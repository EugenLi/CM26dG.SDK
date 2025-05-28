using CM26dG.SDK.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace CM26dG.SDK.Interfaces
{
    public interface IColorMeter
    {
        Task<List<DeviceInfo>> FindDevicesAsync();
        Task<bool> ConnectAsync(int? comPort = null);
        Task<bool> ConfigureMeasurementAsync();
        Task<MeasurementResult> MeasureAsync();
        Task DisconnectAsync();
    }
}
