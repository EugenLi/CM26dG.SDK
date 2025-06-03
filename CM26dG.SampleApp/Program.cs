using System;
using System.Threading.Tasks;
using CM26dG.SDK.Services;
using CM26dG.SDK.Models;

namespace CM26dG.SampleApp
{
    internal class Program
    {
      
        static async Task Main(string[] args)
        {
            Console.WriteLine("Starte CM26dG Test...");

            var sdk = new ColorMeterService();

            try
            {
                var devices = await sdk.FindDevicesAsync();
                if (devices.Count == 0)
                {
                    Console.WriteLine("Kein Gerät gefunden.");
                    return;
                }

                Console.WriteLine("Gefundene Geräte:");
                foreach (var dev in devices)
                    Console.WriteLine($"COM{dev.ComPort}: {dev.Label}");

                var selected = devices[0];

                if (!await sdk.ConnectAsync(selected.ComPort))
                {
                    Console.WriteLine($"Verbindung zu COM{selected.ComPort} fehlgeschlagen.");
                    return;
                }

                Console.WriteLine("Verbindung erfolgreich.");
               
                   await sdk.ConfigureMeasurementAsync();

                var result = await sdk.MeasureAsync();

                Console.WriteLine($"Glanz: {result.Gloss}");
                Console.WriteLine($"L*a*b* SCI: L={result.LabSCI.L:F2}, a={result.LabSCI.A:F2}, b={result.LabSCI.B:F2}");
                Console.WriteLine($"L*a*b* SCE: L={result.LabSCE.L:F2}, a={result.LabSCE.A:F2}, b={result.LabSCE.B:F2}");

                Console.WriteLine("Spektraldaten SCI (in %):");
                for (int i = 0; i < result.SpectrumSCI.Length; i++)
                {
                    Console.WriteLine($"{360 + i * 10} nm: {result.SpectrumSCI[i] * 100:F2}%");
                }

                Console.WriteLine("Spektraldaten SCE (in %):");
                for (int i = 0; i < result.SpectrumSCE.Length; i++)
                {
                    Console.WriteLine($"{360 + i * 10} nm: {result.SpectrumSCE[i] * 100:F2}%");
                }



                await sdk.DisconnectAsync();
                Console.WriteLine("Verbindung getrennt.");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Fehler: " + ex.Message);
            }
        }
    }
}
