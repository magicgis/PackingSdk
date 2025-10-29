using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace knest
{
    public class PackingSdkWrapper : IDisposable
    {
        private PackingSdk sdk;
        private PackingSdkCallbackVoid _callback; // 保存委托实例
        //构造函数
        public PackingSdkWrapper()
        {
            sdk = PackingSdk.Create();
        }
        // 实现一个回调函数
        private void DefaultCallback(IntPtr sdk, string data)
        {
            Console.WriteLine("回调收到数据: " + data);
        }
        public void Start(string inputJson, bool isGenerateHtml = false, PackingSdkCallbackVoid callback = null)
        {
            // 如果没有提供回调，使用默认回调
            _callback = callback ?? DefaultCallback;
            PackingSdk.NATIVE.packingStart(sdk.DangerousGetHandle(), inputJson, isGenerateHtml, callback);
        }

        public void Stop()
        {
            PackingSdk.NATIVE.packingStop(sdk.DangerousGetHandle());
        }
        public bool IsRunning()
        {
            return PackingSdk.NATIVE.packingIsRunning(sdk.DangerousGetHandle());
        }
        public void Dispose()
        {
            sdk.Dispose();
        }
    }
}
