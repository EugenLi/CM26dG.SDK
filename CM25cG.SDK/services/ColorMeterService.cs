using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using CM25cG.SDK.models;
using CM26dG.SDK.Interfaces;
using CM26dG.SDK.Models;
using Konicaminolta;

namespace CM26dG.SDK.Services
{
    public class ColorMeterService : IColorMeter
    {
        private int comPort = 0;
        private ColorManagementMISDK _sdk;

        public async Task<List<DeviceInfo>> FindDevicesAsync()
        {
            var localSdk = ColorManagementMISDK.GetInstance();
            var ret = localSdk.GetDeviceList(out var deviceList, false);
            CheckReturn(ret, "Geräteliste abrufen");

            return deviceList?
                .Select(kvp => new DeviceInfo
                {
                    ComPort = kvp.Key,
                    Label = kvp.Value
                })
                .ToList() ?? new List<DeviceInfo>();
        }


        public async Task<bool> ConnectAsync(int? port = null)
        {
            return await Task.Run(() =>
            {
                comPort = port ?? 0;

                if (_sdk != null)
                    return true;

                try
                {
                    _sdk = ColorManagementMISDK.GetInstance();
                    var ret = _sdk.Connect(comPort);
                    if (ret.errorCode != ErrorDefine.KmSuccess)
                    {
                        _sdk = null;
                        return false;
                    }

                    return true;
                }
                catch
                {
                    _sdk = null;
                    return false;
                }
            });
        }

        public async Task<bool> ConfigureMeasurementAsync()
        {
            return await Task.Run(() =>
            {
                EnsureConnected();

                CheckReturn(_sdk.SetMeasurementMode(MeasCondMode.MeasModeColorAndGloss, comPort), "Messmodus setzen");
                CheckReturn(_sdk.SetAutoAverageTimes(1, comPort), "Mittelungsanzahl setzen");
                CheckReturn(_sdk.SetUv(MeasCondUv.UV_100, comPort), "UV-Filter setzen");
                CheckReturn(_sdk.SetSpecularComponent(MeasCondScie.SC_SCIE, comPort), "Specular Component setzen");

                // Trigger-Modus aktivieren
                CheckReturn(_sdk.SetTriggerMode(OnOff.ON, comPort), "Trigger-Modus aktivieren");

                // Schwarz-Kalibrierung vorbereiten
                Console.WriteLine("Bitte das Gerät auf die SCHWARZ-Kalibrierfläche stellen.");
                Console.WriteLine("Bestätigen Sie mit [Enter]...");
                Console.ReadLine();
                CheckReturn(_sdk.PerformZeroCalibration(comPort), "Schwarzkalibrierung");

                // Weiß-Kalibrierung vorbereiten
                Console.WriteLine("Bitte das Gerät auf die WEISS-Kalibrierfläche stellen.");
                Console.WriteLine("Bestätigen Sie mit [Enter]...");
                Console.ReadLine();
                CheckReturn(_sdk.PerformWhiteCalibration(comPort), "Weißkalibrierung");



                // Glanz-Kalibrierung vorbereiten
                Console.WriteLine("Bitte das Gerät auf den GLANZ-Standard stellen.");
                Console.WriteLine("Bestätigen Sie mit [Enter]...");
                Console.ReadLine();
                CheckReturn(_sdk.PerformGlossCalibration(comPort), "Glanzkalibrierung");

                CheckReturn(_sdk.SetObserverAndIlluminant(0, Observer.Deg10, Illuminant.ILL_D65, comPort), "Beobachter & Lichtart setzen");

                return true;
            });
        }



        public async Task<MeasurementResult> MeasureAsync()
        {
            EnsureConnected();

            var combined = await PerformMeasurementAsync(MeasCondScie.SC_SCIE);


            return new MeasurementResult
            {
                SpectrumSCI = combined.SCI_Spec.Spec.Select(v => v * 0.01f).ToArray(),
                SpectrumSCE = combined.SCE_Spec.Spec.Select(v => v * 0.01f).ToArray(),
                Gloss = combined.SCI_Spec.Gloss,
                LabSCI = combined.LabSCI,
                LabSCE = combined.LabSCE
            };
        }






        private async Task<DualSpecData> PerformMeasurementAsync(MeasCondScie mode)
        {
            return await Task.Run(() =>
            {
                CheckReturn(_sdk.SetSpecularComponent(mode, comPort), $"Specular Mode '{mode}' setzen");

                var ret = _sdk.PerformMeasurement(comPort);
                CheckReturn(ret, $"Messung starten ({mode})");

                MeasStatus status;
                do
                {
                    Thread.Sleep(200);
                    ret = _sdk.PollingMeasurement(out status, comPort);
                    CheckReturn(ret, "Messstatus prüfen");
                } while (status != MeasStatus.Idling);

                // SCI Spektrum
                var specSCI = new SpecData();
                var formSCI = new DataForm { DataType = DataType.SC_SCI_UVFULL };
                ret = _sdk.ReadLatestData(formSCI, specSCI, comPort);
                CheckReturn(ret, "SCI-Spektrum lesen");

                // SCE Spektrum
                var specSCE = new SpecData();
                var formSCE = new DataForm { DataType = DataType.SC_SCE_UVFULL };
                ret = _sdk.ReadLatestData(formSCE, specSCE, comPort);
                CheckReturn(ret, "SCE-Spektrum lesen");

                // SCI Lab
                var labSCI = new ColorValue
                {
                    ColorModeId = ColorSpace.COLOR_LAB
                };

                var labFormSCI = new DataForm { DataType = DataType.SC_SCI_UVFULL };
                ret = _sdk.ReadLatestData(labFormSCI, labSCI, comPort);
                CheckReturn(ret, "SCI-Lab lesen");

                // SCE Lab
                var labSCE = new ColorValue
                {
                    ColorModeId = ColorSpace.COLOR_LAB
                };

                var labFormSCE = new DataForm { DataType = DataType.SC_SCE_UVFULL };
                ret = _sdk.ReadLatestData(labFormSCE, labSCE, comPort);
                CheckReturn(ret, "SCE-Lab lesen");

                return new DualSpecData
                {
                    SCI_Spec = specSCI,
                    SCE_Spec = specSCE,
                    LabSCI = (
                        labSCI.Value.TryGetValue("L", out var l1) ? l1 : 0.0,
                        labSCI.Value.TryGetValue("a", out var a1) ? a1 : 0.0,
                        labSCI.Value.TryGetValue("b", out var b1) ? b1 : 0.0
                    ),
                    LabSCE = (
                        labSCE.Value.TryGetValue("L", out var l2) ? l2 : 0.0,
                        labSCE.Value.TryGetValue("a", out var a2) ? a2 : 0.0,
                        labSCE.Value.TryGetValue("b", out var b2) ? b2 : 0.0
                    )
                };
            });
        }





        public async Task DisconnectAsync()
        {
            if (_sdk != null)
            {
                await Task.Run(() =>
                {
                    var ret = _sdk.DisConnect(comPort);
                    CheckReturn(ret, "Verbindung trennen");
                    _sdk = null;
                });
            }
        }

        private void EnsureConnected()
        {
            if (_sdk == null)
                throw new InvalidOperationException("Gerät ist nicht verbunden. Bitte zuerst ConnectAsync() aufrufen.");
        }

        private void CheckReturn(ReturnMessage ret, string operation)
        {
            if (ret.errorCode != ErrorDefine.KmSuccess)
            {
                var message = string.Join("; ", ret.errorMessage ?? new List<string>());
                throw new InvalidOperationException($"Fehler bei '{operation}': Code={ret.errorCode}, Nachricht(en)={message}");
            }
        }
    }
}