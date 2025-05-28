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
               
                    //await sdk.ConfigureMeasurementAsync();

                var result = await sdk.MeasureAsync();

                Console.WriteLine($"Glanz: {result.Gloss}");
                Console.WriteLine($"SCI[0]: {result.SpectrumSCI[0]}");
                Console.WriteLine($"SCE[0]: {result.SpectrumSCE[0]}");
           
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
