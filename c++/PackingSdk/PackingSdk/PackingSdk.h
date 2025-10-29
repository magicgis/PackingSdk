#pragma once
#ifdef KNPACKING_EXPORTS
#define KNPACKING __declspec(dllexport)
#else
#define KNPACKING __declspec(dllimport)
#endif

#ifdef __cplusplus  
#ifdef _WIN32
// 禁用 STL 容器在 DLL 边界的警告
#pragma warning(push)
#pragma warning(disable: 4251)
#pragma warning(disable: 4275)
#endif
#include <string>
namespace knest {

    //优化状态
    enum KNPACKING SolverState {
        Ready = 0,//0已准备好
        Running = 1,//1运行中
        RunningForBetter = 2,//2运行中，并且有结果，还在计算更优结果
        Ended = 3,//3结束
    };
    //优化结束原因
    enum KNPACKING SolverEndedReason {
        None = 0,//0无
        Normal = 1,//1正常结束
        WrongParam = 2,//2输入数据或者输入参数不合法而终止
        DogError = 3,//3没有找到硬件狗，或者其他硬件狗错误
        ReachCondition = 4,//4达到最大迭代次数、最大收敛条件等而终止
        TimeOut = 5,//5达到用户设置的最大等待时间(得到优化结果后，等待多长时间内再无优化结果，则算法停止运行)而终止
        UserCancel = 6,//6用户中断
        CallBackToStop = 7,//7回调函数返回true从而终止
        ExceptionExit = 8,//8异常结束
    };

    //优化回调输出结构体--回调函数返回的字符串对应的结构体
    struct KNPACKING SolverOutput {
        SolverState solverState;//算法当前状态
        SolverEndedReason solverEndedReason;//算法结束原因
        std::string solverEndedMsg;//算法结束原因相关信息
        unsigned long currentPriority;//当轮计算的优先级
        unsigned long numOfIteration;//迭代总次数
        unsigned long long elapsedTime;//算法消耗的总时间(单位毫秒)

        std::string firstMaterial;  //第一个BinParameter的 [材质] (用于界面显示)
        double firstLength;  //第一个BinParameter的 [长度] (用于界面显示)
        double firstWidth;  //第一个BinParameter的 [宽度] (用于界面显示)
        double firstThickness;  //第一个BinParameter的 [厚度] (用于界面显示)

        double calUsage;//本轮计算的总利用率，例如0.95表示95%的利用率
        double calProgress;//本轮计算的进度，例如95表示95%的进度
        unsigned int calTargetSheetCount;//本轮计算的的目标大板数，例如当前最优结果的大板数是8，则通常本轮计算的目标大板数是8-1=7
        unsigned long optimumIndex;//该值用于标记第几次优化结果列表（每次优化结果列表的该值都与上次不同）
        unsigned long long bestFitness;//目前最好的适应度值
        long long resultTimeOut = -1;//超时时间（毫秒数） -用于定义距离上次优化结果的时间间隔，当为-1时表示不超时，当优化结果没变化并且超过该时间间隔时，优化自动停止
        unsigned long long startTimeForTimeOut;//超时开始时间（毫秒数）
        unsigned long long timeElapsedSinceLastResult; //记录从 startTimeForTimeOut 开始已经经过的时间，当这个时间超过 resultTimeOut 时则自动停止算法
        unsigned int bestResultSheetCount;//当前已计算完成的排版方案中结果最优的大板数

        unsigned int partCountInBestResult; //当前已计算完成的排版方案中最优结果中的小板数量

        double bestResultUsage;//当前已计算完成的排版方案中结果最优的利用率
        std::string jsonResult;//优化结果json字符串或者json文件路径，只有计算最终结束（SolverState为3）的时候该字段才会有值
        bool isMultiPriorityMode = false;//true表示当前正处在多优先级的模式下，false表示非多优先级模式
        long long resultNumOfIteration = -1;//超量限制迭代数 -用于定义距离上次优化结果的迭代次数，当为-1时表示不限量，当优化结果没变化并且距离上次迭代次数超过该数值时，优化自动停止
        unsigned long long numOfIterationSinceLastResult; //记录上次有变化的优化结果的迭代总次数，当numOfIteration减去这个值超过 resultNumOfIteration 时则自动停止算法
    };
}

extern "C" {
#endif
    //helloWorld
    KNPACKING void helloWorld();
    //销毁char，返回0表示销毁成功
    KNPACKING int charFree(char* input);
    KNPACKING void setLogLevel(int level);//用于设置日志级别 Trace = 1,Debug = 2,Info = 3,Warn = 4,Error = 5,Fatal = 6,Off = 7
    //获取加密狗code（无论当前用的是什么加密狗），当找不到加密狗时返回空字符串。
    KNPACKING char* getDogCode();
    //获取加密狗code（无论当前用的是什么加密狗），返回错误码 0 表示无错误，非0表示有错误
    KNPACKING int getDogCode2(char** dogCode);
    //根据加密狗类型获取加密狗code，当找不到加密狗时返回空字符串，离线加密狗会返回dogCode,即使当前未注册。0表示未定义的加密狗 1表示USB加密狗 2表示离线的加密狗
    KNPACKING char* getDogCodeByDogType(int dogType);
    //根据加密狗类型获取加密狗code，返回错误码 0 表示无错误，非0表示有错误。dogType：0未定义的加密狗 1USB加密狗 2离线的加密狗
    KNPACKING int getDogCodeByDogType2(int dogType, char** dogCode);
    //加密狗是否可用
    KNPACKING bool isDogValid();
    //读取加密狗数据 返回错误码 0 表示无错误，非0表示有错误
    KNPACKING int readDog(unsigned int offset, unsigned int length, void* buffer);
    //写入加密狗数据 返回错误码 0 表示无错误，非0表示有错误
    KNPACKING int writeDog(unsigned int offset, unsigned int length, const void* buffer);
    //是否支持获取时间，返回 0（false）表示不支持，1 （true）表示支持
    KNPACKING int supportGetDogTime();
    //获取时间（从 1970 年 1 月 1 日开始经过的秒数）,返回错误码 0 表示无错误，非0表示有错误
    KNPACKING int getDogTime(long long* time);
    //获取加密狗类型  0表示未定义 1表示USB加密狗 2表示离线的加密狗
    KNPACKING int getDogType();
    //获取加密狗内的套餐类型 0表示未定义的套餐，1表示标准版本套餐 2表示高级版本套餐
    KNPACKING int getDogSuite();
    //注册离线授权，返回错误码 0 表示无错误，非0表示有错误。其中registerCode为注册码，registerParams为需要保存到授权内的参数列表（键值对转换为json字符串）
    KNPACKING int registerOfflineLicense(const char* registerCode, const char* registerParams);
    //取消离线授权，返回错误码 0 表示无错误，非0表示有错误
    KNPACKING int cancelOfflineLicense();
    //是否强制取消离线授权，返回错误码 0 表示无错误，非0表示有错误。cancelOfflineLicense实际调用的是cancelOfflineLicenseForce(false)
    KNPACKING int cancelOfflineLicenseForce(bool isForceDelete);
    //获取当前离线授权的注册码
    KNPACKING char* getRegisterCode();
    //根据key读取离线加密狗的参数的值，返回错误码0表示无错误，非0表示有错误。
    KNPACKING int readOfflineDog(const char* key, void* buffer);
    //将键值对写入到离线加密狗中
    KNPACKING int writeOfflineDog(const char* key, const char* value);
    //获取授权剩余天数（离线加密狗）days的值为0表示已经过期，-1表示没有时间限制，其他正数表示剩余的天数,返回错误码，0表示无错误, 非0表示有错误
    KNPACKING int getOfflineDogRestDays(int* days);

    //服务端相关的接口
    //在服务器端将参数提前写入到注册码对应的参数中，返回错误码0表示无错误(写入成功)，非0表示有错误(写入失败)。isClearBeforeWrite：是否在写入前清空原有的所有数据
    KNPACKING int writeParameterByRegisterCode(const char* registerCode, const char* key, const char* value, bool isClearBeforeWrite = false);
    //从服务器中读取指定注册码的参数的值，返回错误码0表示无错误，非0表示有错误
    KNPACKING int readParameterByRegisterCode(const char* registerCode, const char* key, void* buffer);
    //向服务器读取指定注册码的状态  返回错误码0表示无错误，非0表示有错误  status:0 = [未定义] 1 = [不存在] 2 = [未使用] 3 = [已使用] 4=[可重新注册]
    KNPACKING int readRegisterCodeStatus(const char* registerCode, int* status);
    //重新注册离线授权(重新注册-需附带前一个机器的机器码dogCode)，返回错误码 0表示无错误，非0表示有错误。其中registerCode为注册码，lastDogCode为上次注册机器的加密狗机器码，registerParams为需要保存到授权内的参数列表（键值对转换为json字符串）
    KNPACKING int registerOfflineLicenseWithLastMachineCode(const char* registerCode, const char* lastDogCode, const char* registerParams);
    
    //PackingSdk结构体
    typedef struct {
    } PackingSdk;
    //创建PackingSdk的实例
    KNPACKING PackingSdk* packingNew();
    //传入数据，启动PackingSdk实例的排版计算,可设置回调函数（同步）
    //inputJson 输入数据
    //isGenerateHtml是否生成html结果,大于0表示需要生成html结果
    //callback 回调函数，用于通知进度，返回true时表示停止优化，默认是返回false
    KNPACKING char* doOptimization(PackingSdk* sdk, const char* inputJson, bool isGenerateHtml = false, bool(*callback)(PackingSdk* sdk, const char* data) = nullptr);

    //传入数据，启动PackingSdk实例的排版计算,可设置回调函数（异步）
    //inputJson:输入数据
    //isGenerateHtml是否生成html结果,大于0表示需要生成html结果
    //callback回调方法
    KNPACKING void packingStart(PackingSdk* sdk, const char* inputJson, bool isGenerateHtml = false, void(*callback)(PackingSdk* sdk, const char* data) = nullptr);
    //停止PackingSdk实例的排版优化计算
    KNPACKING void packingStop(PackingSdk* sdk);
    //销毁PackingSdk实例
    KNPACKING void packingFree(PackingSdk* sdk);
    //查看PackingSdk实例的排版计算是否在执行中
    KNPACKING bool packingIsRunning(PackingSdk* sdk);

#ifdef __cplusplus
}
#endif
