using System;
using System.Runtime.InteropServices;
using System.Threading;

namespace knest
{
    // 定义一个公共委托类型(回调函数)
    [UnmanagedFunctionPointer(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate bool PackingSdkCallback(IntPtr sdk, [MarshalAs(UnmanagedType.LPUTF8Str)] string data);
    // 定义一个公共委托类型(回调函数)
    [UnmanagedFunctionPointer(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    public delegate void PackingSdkCallbackVoid(IntPtr sdk, [MarshalAs(UnmanagedType.LPUTF8Str)] string data);

    // 优化状态
    public enum SolverState
    {
        Ready = 0,       // 0已准备好
        Running = 1,     // 1运行中
        RunningForBetter = 2, // 2运行中，并且有结果，还在计算更优结果
        Ended = 3        // 3结束
    }

    // 优化结束原因
    public enum SolverEndedReason
    {
        None = 0,       // 0无
        Normal = 1,      // 1正常结束
        WrongParam = 2,   // 2输入数据或者输入参数不合法而终止
        DogError = 3,     // 3没有找到硬件狗，或者其他硬件狗错误
        ReachCondition = 4, // 4达到最大迭代次数、最大收敛条件等而终止
        TimeOut = 5,      // 5达到用户设置的最大等待时间而终止
        UserCancel = 6,   // 6用户中断
        CallBackToStop = 7, // 7回调函数返回true从而终止
        ExceptionExit = 8  // 8异常结束
    }

    // 优化回调输出结构体--回调函数返回的字符串对应的结构体
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct SolverOutput
    {
        public SolverState solverState;          // 算法当前状态
        public SolverEndedReason solverEndedReason; // 算法结束原因
        [MarshalAs(UnmanagedType.LPStr)]
        public string solverEndedMsg;            // 算法结束原因相关信息
        public uint currentPriority;             // 当轮计算的优先级
        public uint numOfIteration;              // 迭代总次数
        public ulong elapsedTime;                // 算法消耗的总时间(单位毫秒)

        [MarshalAs(UnmanagedType.LPStr)]
        public string firstMaterial;             // 第一个BinParameter的 [材质] (用于界面显示)
        public double firstLength;               // 第一个BinParameter的 [长度] (用于界面显示)
        public double firstWidth;                // 第一个BinParameter的 [宽度] (用于界面显示)
        public double firstThickness;            // 第一个BinParameter的 [厚度] (用于界面显示)

        public double calUsage;                  // 本轮计算的总利用率，例如0.97表示95%的利用率
        public double calProgress;               // 本轮计算的进度，例如95表示95%的进度
        public uint calTargetSheetCount;         // 本轮计算的的目标大板数，例如当前最优结果的大板数是8，则通常本轮计算的目标大板数是8-1=7
        public ulong optimumIndex;               // 每次优化结果列表都与上次不同，该值用于标记第几次优化结果列表
        public ulong bestFitness;                // 目前最好的适应度值
        public long resultTimeOut;               // 超时时间（毫秒数）-用于定义距离上次优化结果的时间间隔，当为-1时表示不超时
        public ulong startTimeForTimeOut;        // 超时开始时间（毫秒数）
        public ulong timeElapsedSinceLastResult; // 记录从startTimeForTimeOut开始已经经过的时间
        public uint bestResultSheetCount;        // 当前已计算完成的排版方案中结果最优的大板数
        public uint partCountInBestResult;       // 当前已计算完成的排版方案中最优结果中的小板数量
        public double bestResultUsage;           // 当前已计算完成的排版方案中结果最优的利用率

        public object jsonResult;                // 优化结果json字符串或者json文件路径，只有计算最终结束（SolverState为3）的时候该字段才会有值

        [MarshalAs(UnmanagedType.I1)]
        public bool isMultiPriorityMode;          // true表示当前正处在多优先级的模式下，false表示非多优先级模式
        public long resultNumOfIteration;         // 超量限制迭代数-用于定义距离上次优化结果的迭代次数，当为-1时表示不限量
        public ulong numOfIterationSinceLastResult; // 记录上次有变化的优化结果的迭代总次数
    }
    //PackingSdk
    public class PackingSdk : SafeHandle
    {
        //dll接口
        public class NATIVE
        {
            private const string DllName = "packing.dll";

            //helloWorld
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern void helloWorld();

            //销毁char，返回0表示销毁成功
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int charFree(IntPtr input);

            //用于设置日志级别 Trace = 1,Debug = 2,Info = 3,Warn = 4,Error = 5,Fatal = 6,Off = 7
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern void setLogLevel(int level);

            //获取加密狗code（无论当前用的是什么加密狗），当找不到加密狗时返回空字符串
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr getDogCode();

            //获取加密狗code（无论当前用的是什么加密狗），返回错误码 0 表示无错误，非0表示有错误
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int getDogCode2(out IntPtr dogCode);

            //根据加密狗类型获取加密狗code，当找不到加密狗时返回空字符串，离线加密狗会返回dogCode,即使当前未注册。0表示未定义的加密狗 1表示USB加密狗 2表示离线的加密狗
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr getDogCodeByDogType(int dogType);

            //根据加密狗类型获取加密狗code，返回错误码 0 表示无错误，非0表示有错误。dogType：0未定义的加密狗 1USB加密狗 2离线的加密狗
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int getDogCodeByDogType2(int dogType, out IntPtr dogCode);

            //加密狗是否可用
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            [return: MarshalAs(UnmanagedType.I1)]
            public static extern bool isDogValid();

            //读取加密狗数据 返回错误码 0 表示无错误，非0表示有错误
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int readDog(uint offset, uint length, IntPtr buffer);

            //写入加密狗数据 返回错误码 0 表示无错误，非0表示有错误
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int writeDog(uint offset, uint length, IntPtr buffer);

            //是否支持获取时间
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int supportGetDogTime();

            //获取时间（从 1970 年 1 月 1 日开始经过的秒数）,返回错误码 0 表示无错误，非0表示有错误
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int getDogTime(out long time);

            //获取加密狗类型  0表示未定义 1表示USB加密狗 2表示离线的加密狗
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int getDogType();

            //获取加密狗内的套餐类型 0表示未定义的套餐，1表示标准版本套餐 2表示高级版本套餐
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int getDogSuite();

            //注册离线授权，返回错误码 0 表示无错误，非0表示有错误。其中registerCode为注册码，registerParams为需要保存到授权内的参数列表（键值对转换为json字符串）
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
            public static extern int registerOfflineLicense(string registerCode, string registerParams);

            //取消离线授权，返回错误码 0 表示无错误，非0表示有错误
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int cancelOfflineLicense();

            //是否强制取消离线授权，返回错误码 0 表示无错误，非0表示有错误。cancelOfflineLicense实际调用的是cancelOfflineLicenseForce(false)
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int cancelOfflineLicenseForce([MarshalAs(UnmanagedType.I1)] bool isForceDelete);

            //获取当前离线授权的注册码
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr getRegisterCode();

            //根据key读取离线授权的参数的值
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
            public static extern int readOfflineDog(string key, IntPtr buffer);

            //将键值对写入到离线授权中
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
            public static extern int writeOfflineDog(string key, string value);

            //获取授权剩余天数（离线授权）days的值为0表示已经过期，-1表示没有时间限制，其他正数表示剩余的天数,返回错误码，0表示无错误, 非0表示有错误
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern int getOfflineDogRestDays(out int days);

            //服务端相关的接口
            //将参数提前写入到注册码对应的参数中，返回1表示写入成功，0表示写入失败。isClearBeforeWrite：是否在写入前清空原有的所有数据
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
            public static extern int writeParameterByRegisterCode(string registerCode, string key, string value, [MarshalAs(UnmanagedType.I1)] bool isClearBeforeWrite);

            //从服务器中读取指定注册码的参数的值，返回1表示读取成功，0表示读取失败
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
            public static extern int readParameterByRegisterCode(string registerCode, string key, IntPtr buffer);

            //向服务器读取指定注册码的状态  返回错误码 0表示无错误，非0表示有错误  status:0 = [未定义] 1 = [不存在] 2 = [未使用] 3 = [已使用] 4=[可重新注册]
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
            public static extern int readRegisterCodeStatus(string registerCode, out int status);

            //重新注册离线授权(重新注册-需附带前一个机器的机器码dogCode)，返回错误码 0表示无错误，非0表示有错误。其中registerCode为注册码，lastDogCode为上次注册机器的加密狗机器码，registerParams为需要保存到授权内的参数列表（键值对转换为json字符串）
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
            public static extern int registerOfflineLicenseWithLastMachineCode(string registerCode, string lastDogCode, string registerParams);

            //PackingSdk结构体
            //创建PackingSdk的实例
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr packingNew();

            //传递数据，执行优化
            //inputJson 输入数据
            //isGenerateHtml是否生成html结果,大于0表示需要生成html结果
            //callback 回调函数，用于通知进度，返回true时表示停止优化，默认是返回false

            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
            public static extern IntPtr doOptimization(IntPtr sdk, string inputJson, [MarshalAs(UnmanagedType.I1)] bool isGenerateHtml = false, PackingSdkCallback callback = null);

            //启动PackingSdk实例的排版计算,可设置回调函数
            //inputJson:输入数据
            //isGenerateHtml是否生成html结果,大于0表示需要生成html结果
            //callback回调方法

            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
            public static extern void packingStart(IntPtr sdk, string inputJson, [MarshalAs(UnmanagedType.I1)] bool isGenerateHtml = false, PackingSdkCallbackVoid callback = null);

            //停止PackingSdk实例的排版计算
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern void packingStop(IntPtr sdk);

            //销毁PackingSdk实例
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            public static extern void packingFree(IntPtr sdk);

            //查看PackingSdk实例的排版计算是否在执行中
            [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
            [return: MarshalAs(UnmanagedType.I1)]
            public static extern bool packingIsRunning(IntPtr sdk);
        }
        // 接受句柄的构造函数
        internal PackingSdk(IntPtr handle) : base(IntPtr.Zero, true)
        {
            SetHandle(handle);
        }
        //public PackingSdk() : base(IntPtr.Zero, true) { }
        public static PackingSdk Create()
        {
            IntPtr handle = NATIVE.packingNew();
            return new PackingSdk(handle);
        }

        public override bool IsInvalid
        {
            get { return this.handle == IntPtr.Zero; }
        }
        //重写句柄销毁，从而在PackingSdk类销毁的时候自动销毁dll接口的句柄，从而无需手工调用
        protected override bool ReleaseHandle()
        {
            if (!this.IsInvalid)
            {
                NATIVE.packingFree(handle);
            }
            return true;
        }
    }
}
