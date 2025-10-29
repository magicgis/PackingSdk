package com.xmplatform.knest;
import com.sun.jna.*;
import com.sun.jna.ptr.PointerByReference;

public interface PackingSdk extends Library {
    static PackingSdk NATIVE = (PackingSdk) Native.loadLibrary("packing", PackingSdk.class);//加载packing.dll

    /**
     * helloWorld
     */
    void helloWorld();

    /**
     * 销毁char, 返回0表示销毁成功
     * @param str 需要销毁的char指针
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int charFree(PointerByReference str);
    /**
     * 设置日志级别
     * @param logLevel 日志级别  Trace = 1,Debug = 2,Info = 3,Warn = 4,Error = 5,Fatal = 6,Off = 7
     */
    void setLogLevel(int logLevel);
    /**
     * 获取加密狗的code
     * @return 加密狗code数据的char指针
     */
    Pointer getDogCode();

    /**
     * 获取加密狗的code
     * @param dogCodePref 读取的加密狗code的指针的指针
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int getDogCode2(PointerByReference dogCodePref);
    /**
     * 根据加密狗的类型来获取加密狗code
     * @param dogType 加密狗的类型 0表示未定义的加密狗 1表示USB加密狗 2表示离线的加密狗
     * @return 加密狗code数据的指针
     */
    Pointer getDogCodeByDogType(int dogType);
    /**
     * 根据加密狗类型获取加密狗的code
     * @param dogType 加密狗类型 0表示未定义的加密狗 1表示USB加密狗 2表示离线的加密狗
     * @param dogCodePref 读取的加密狗code的指针的指针
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int getDogCodeByDogType2(int dogType, PointerByReference dogCodePref);
    /**
     * 加密狗是否可用
     * @return 是否可用
     *
     */
    boolean isDogValid();
    /**
     * 读取加密狗的数据
     * @param offset 读取的地址
     * @param length 读取数据的长度
     * @param data 读取的数据的指针
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int readDog(int offset, int length, Pointer data);
    /**
     * 写入数据到加密狗
     * @param offset 写入的地址
     * @param length 写入数据的长度
     * @param data 写入的数据的指针
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int writeDog(int offset, int length, Pointer data);

    /**
     * 是否支持获取时间，返回 0 表示不支持，1 表示支持
     * @return 是否支持，返回 0（false）表示不支持，1 （true）表示支持
     */
    int supportGetDogTime();

    /**
     * 获取时间（从 1970 年 1 月 1 日开始经过的秒数）
     * @param time c++类型为long long*的时间变量
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int getDogTime(Pointer time);

    /**
     * 获取加密狗类型  0表示未定义 1表示USB加密狗 2表示离线的加密狗
     * @return 加密狗类型，0表示未定义 1表示USB加密狗 2表示离线的加密狗
     */
    int getDogType();

    /**
     * 获取加密狗内的套餐类型
     * @return 当前加密狗的套餐类型 0表示未定义的套餐，1表示标准版本套餐 2表示高级版本套餐
     */
    int getDogSuite();

    /**
     * 注册离线授权
     * @param registerCode 注册码
     * @param registerParams 需要保存到授权内的参数列表（键值对转换为json字符串）
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int registerOfflineLicense(Pointer registerCode, Pointer registerParams);


    /**
     * 取消离线授权
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int cancelOfflineLicense();

    /**
     * 是否强制取消离线授权，返回错误码 0 表示无错误，非0表示有错误。cancelOfflineLicense实际调用的是cancelOfflineLicenseForce(false)
     * @param isForceDelete 强制与否，true表示强制取消
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int cancelOfflineLicenseForce(boolean isForceDelete);

    /**
     * 获取当前离线授权的注册码
     * @return 当前离线授权注册码的char指针
     */
    Pointer getRegisterCode();

    /**
     * 根据key读取离线授权的参数的值
     * @param key 键
     * @param buffer 存储读取数据的缓冲区指针，由调用者分配内存并传入，对应于C++的void* buffer
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int readOfflineDog(Pointer key, Pointer buffer);

    /**
     * 将键值对写入到离线授权中
     * @param key 键值对中的键
     * @param value 键值对中的值
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int writeOfflineDog(Pointer key, Pointer value);

    /**
     * 获取授权剩余天数（离线授权）
     * @param days 值为0表示已经过期，-1表示没有时间限制，其他正数表示剩余的天数，在C++中days的类型为int*
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int getOfflineDogRestDays(Pointer days);

    //**********************************服务端相关接口begin********************************

    /**
     * 将参数提前写入到注册码对应的参数中
     * @param registerCode 注册码
     * @param key 键
     * @param value 值
     * @param isClearBeforeWrite 是否在写入前清空原有的所有数据
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int writeParameterByRegisterCode(Pointer registerCode, Pointer key, Pointer value, boolean isClearBeforeWrite);

    /**
     * 从服务器中读取指定注册码的参数的值
     * @param registerCode 注册码
     * @param key 键
     * @param buffer 存储读取数据的缓冲区指针，由调用者分配内存并传入，对应于C++的void* buffer
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int readParameterByRegisterCode(Pointer registerCode, Pointer key, Pointer buffer);

    /**
     * 向服务器读取指定注册码的状态
     * @param registerCode 注册码
     * @param status 注册码的状态，对应于C++的int*
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int readRegisterCodeStatus(Pointer registerCode, Pointer status);
    /**
     * 重新注册离线授权(重新注册-需附带前一个机器的机器码dogCode)
     * @param registerCode 注册码
     * @param lastDogCode 上一个机器的加密狗Code
     * @param registerParams 注册参数
     * @return 错误码，0表示无错误, 非0表示有错误
     */
    int registerOfflineLicenseWithLastMachineCode(Pointer registerCode, Pointer lastDogCode, Pointer registerParams);

    //**********************************服务端相关接口end********************************

    /**
     * 创建PackingSdk的实例
     * @return 返回一个优化排版实例的指针
     */
    Pointer packingNew();

    /**
     *
     * @param inputJson 输入数据字符串的指针
     * @param isGenerateHtml 是否生成html结果
     * @param callback 回调
     * @return 优化结果json字符串指针
     */
    Pointer doOptimization(Pointer sdk, Pointer inputJson, boolean isGenerateHtml, PackingSdkCallbackImpl callback);

    /**
     * 启动PackingSdk实例的排版计算,可设置回调函数
     * @param sdk 优化实例指针
     * @param inputJson 输入数据字符串的指针
     * @param isGenerateHtml 是否生成html结果
     * @param callback 回调
     */
    void packingStart(Pointer sdk, Pointer inputJson, boolean isGenerateHtml, PackingSdkCallbackVoidImpl callback);

    /**
     * 停止PackingSdk实例的排版计算
     * @param sdk 优化实例指针
     */
    void packingStop(Pointer sdk);

    /**
     * 销毁PackingSdk实例
     * @param sdk 优化实例指针
     */
    void packingFree(Pointer sdk);

    /**
     * 查看优化实例是否计算完成，当返回true表示已停止
     * @param sdk 优化实例指针
     * @return 返回true表示已停止，fasle表示还在运行中
     */
    boolean packingIsRunning(Pointer sdk);
}