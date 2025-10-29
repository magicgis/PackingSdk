#pragma once
// 添加导出宏定义
#ifdef KNPACKING_EXPORTS
#define KNPACKING __declspec(dllexport)
#else
#define KNPACKING __declspec(dllimport)
#endif

#include <string>
#include <exception>

namespace knest {

    // 所有错误码
    enum class KNPACKING PackingError {
        // 通用的错误码
        Succeed = 0,                // 没有错误（成功）
        NoDogDetected = 1,          // 没有检测到加密狗
        ParameterError = 2,         // 参数错误，例如数据为空，数据大小为0等不合法的参数
        Undefine = 3,               // 当前加密狗无此函数的实现
        WrongMachineCode = 4,       // 当前离线授权的机器码与授权不匹配
        ExpiredError = 5,           // 授权已过期
        SignError = 6,              // 授权签名错误
        UnknowExceptionError = 7,   // 未知异常错误

        // 读狗相关错误
        ReadError = 20,//读取数据失败
        ExceptionOccurWhenReadError = 50,  // 发生异常导致读取数据失败

        // 写狗相关错误
        CapacityExceeds = 60,       // 写入的数据超出最大容量
        WriteError = 61,            // 写入失败,由于某些错误导致写入失败
        ExceptionOccurWhenWriteError = 62,  // 发生异常导致写入失败

        // 获取狗的时间错误
        TimeInValidError = 70,      // 加密狗不支持获取时间

        // 注册离线授权相关错误
        LicenseInValidError = 80,        // 授权不可用
        CodeIsUsedError = 81,            // 注册码已被使用
        NotMatchMachineCodeError = 82,   // 在重新注册时与上次的机器码不匹配
        GenerateFailedError = 83,        // 生成授权失败
        CodeIsNotExistError = 84,        // 注册码不存在
        ExceptionOccurError = 85,        // 发生异常导致注册失败
        SignDataError = 86,              // 服务端返回的数据的签名不正确，可能数据已被劫持
        OutofServiceError = 87,          // 无法访问注册服务（网络未连接或者后台无服务）
        JsonConvertError = 88,           // 注册参数转换为json时发生错误
		ClientSignDataError = 89,        // 客户端发送的签名数据不匹配
        AlreadyRegistered = 90,          //当前电脑已注册过授权
        UnRegisterFailedWithUnMatch = 91,//授权信息与后台数据不匹配导致取消授权失败
        UnRegisterFailedWithException = 92,//发生异常导致取消授权失败
        LackOfTimestamp = 93,            //缺少时间戳参数
        TimestampIsNotNum = 94,          //时间戳参数为非数字
        TimestampIsTimeout = 95,         //时间戳参数的值已超时
        LackOfSign = 96,                //缺少签名参数sign

        // 取消/删除离线授权相关错误
        UnknowLicenseType = 100,         // 未知的授权类型
        DeleteFailedError = 101,         // 删除失败

        // 根据key读取离线授权加密狗的存储相关错误
        LicenseIsInValid = 110,          // 授权不可用
        DataPointerIsNull = 111,         // 指向的数据指针为空
        DecodeError = 112,               // 字符解密错误(utf8->gbk)

        // 根据key向离线授权写入值错误
        WriteOfflineLicenseFailed = 120,  // 向离线授权写入值时发生错误导致写入失败

        // 向服务器提前写入参数错误
        LackOfParameterError = 130,      // 缺少必要的参数
        ParameterIsNotModifiableError = 131, // 非初始状态，禁止操作参数
        WriteParameterFailed = 132,      // 写入参数过程中发生错误导致写入失败
        ParameterIsNotModifiableWhenReRegisterError = 133,//可重新注册状态，禁止操作参数

        // 从服务器读取提前写入的参数错误
        ValuePointerIsNullError = 140,   // 值的指针为空
        ReadParameterFailed = 141,        // 读取提前参数过程中发生错误导致写入失败


        Unknown = 9999  //未知错误码
    };


    // 数字转换为 PackingError 的函数
    inline PackingError toPackingError(int errorCode) {
        switch (errorCode) {
            // 通用的错误码
        case 0: return PackingError::Succeed;
        case 1: return PackingError::NoDogDetected;
        case 2: return PackingError::ParameterError;
        case 3: return PackingError::Undefine;
        case 4: return PackingError::WrongMachineCode;
        case 5: return PackingError::ExpiredError;
        case 6: return PackingError::SignError;
        case 7: return PackingError::UnknowExceptionError;

            // 读狗相关错误
        case 50: return PackingError::ExceptionOccurWhenReadError;

            // 写狗相关错误
        case 60: return PackingError::CapacityExceeds;
        case 61: return PackingError::WriteError;
        case 62: return PackingError::ExceptionOccurWhenWriteError;

            // 获取狗的时间错误
        case 70: return PackingError::TimeInValidError;

            // 注册离线授权相关错误
        case 80: return PackingError::LicenseInValidError;
        case 81: return PackingError::CodeIsUsedError;
        case 82: return PackingError::NotMatchMachineCodeError;
        case 83: return PackingError::GenerateFailedError;
        case 84: return PackingError::CodeIsNotExistError;
        case 85: return PackingError::ExceptionOccurError;
        case 86: return PackingError::SignDataError;
        case 87: return PackingError::OutofServiceError;
        case 88: return PackingError::JsonConvertError;
		case 89: return PackingError::ClientSignDataError;
        case 90: return PackingError::AlreadyRegistered;
        case 91: return PackingError::UnRegisterFailedWithUnMatch;
        case 92: return PackingError::UnRegisterFailedWithException;
        case 93: return PackingError::LackOfTimestamp;
        case 94: return PackingError::TimestampIsNotNum;
        case 95: return PackingError::TimestampIsTimeout;
        case 96: return PackingError::LackOfSign;

            // 取消/删除离线授权相关错误
        case 100: return PackingError::UnknowLicenseType;
        case 101: return PackingError::DeleteFailedError;

            // 根据key读取离线授权加密狗的存储相关错误
        case 110: return PackingError::LicenseIsInValid;
        case 111: return PackingError::DataPointerIsNull;
        case 112: return PackingError::DecodeError;

            // 根据key向离线授权写入值错误
        case 120: return PackingError::WriteOfflineLicenseFailed;

            // 向服务器提前写入参数错误
        case 130: return PackingError::LackOfParameterError;
        case 131: return PackingError::ParameterIsNotModifiableError;
        case 132: return PackingError::WriteParameterFailed;

            // 从服务器读取提前写入的参数错误
        case 140: return PackingError::ValuePointerIsNullError;
        case 141: return PackingError::ReadParameterFailed;

            // 如果没有匹配的错误码，返回 Unknown
        default: return PackingError::Unknown;
        }
    }
    // PackingError 转换为数字的函数
    inline int fromPackingError(PackingError errorCode) {
        return static_cast<int>(errorCode);
    }
    //从错误码获取对应描述
    inline const char* getPackingErrorDescription(PackingError errorCode) {
        switch (errorCode) {
        case PackingError::Succeed: return "没有错误（成功）";
        case PackingError::NoDogDetected: return "没有检测到加密狗";
        case PackingError::ParameterError: return "参数错误，例如数据为空，数据大小为0等不合法的参数";
        case PackingError::Undefine: return "当前加密狗无此函数的实现";
        case PackingError::WrongMachineCode: return "当前离线授权的机器码与授权不匹配";
        case PackingError::ExpiredError: return "授权已过期";
        case PackingError::SignError: return "授权签名错误";
        case PackingError::UnknowExceptionError: return "未知异常错误";
        case PackingError::ExceptionOccurWhenReadError: return "发生异常导致读取失败";
        case PackingError::CapacityExceeds: return "写入的数据超出最大容量";
        case PackingError::WriteError: return "写入失败,由于某些错误导致写入失败";
        case PackingError::ExceptionOccurWhenWriteError: return "发生异常导致写入失败";
        case PackingError::TimeInValidError: return "加密狗不支持获取时间";
        case PackingError::LicenseInValidError: return "授权不可用";
        case PackingError::CodeIsUsedError: return "注册码已被使用";
        case PackingError::NotMatchMachineCodeError: return "在重新注册时与上次的机器码不匹配";
        case PackingError::GenerateFailedError: return "生成授权失败";
        case PackingError::CodeIsNotExistError: return "注册码不存在";
        case PackingError::ExceptionOccurError: return "发生异常导致注册失败";
        case PackingError::SignDataError: return "服务端返回的数据的签名不正确，可能数据已被劫持";
        case PackingError::OutofServiceError: return "无法访问注册服务（网络未连接或者后台无服务）";
        case PackingError::JsonConvertError: return "注册参数转换为json时发生错误";
		case PackingError::ClientSignDataError: return "客户端发送的签名数据不匹配";
        case PackingError::AlreadyRegistered: return "当前电脑已注册过授权";
        case PackingError::UnRegisterFailedWithUnMatch: return "授权信息与后台数据不匹配导致取消授权失败";
        case PackingError::UnRegisterFailedWithException: return "发生异常导致取消授权失败";
        case PackingError::LackOfTimestamp: return "缺少时间戳参数";
        case PackingError::TimestampIsNotNum: return "时间戳参数为非数字";
        case PackingError::TimestampIsTimeout: return "时间戳参数的值已超时";
        case PackingError::LackOfSign: return "缺少签名参数sign";

        case PackingError::UnknowLicenseType: return "未知的授权类型";
        case PackingError::DeleteFailedError: return "删除失败";
        case PackingError::LicenseIsInValid: return "授权不可用";
        case PackingError::DataPointerIsNull: return "指向的数据指针为空";
        case PackingError::DecodeError: return "字符解密错误(utf8->gbk)";
        case PackingError::WriteOfflineLicenseFailed: return "向离线授权写入值时发生错误导致写入失败";
        case PackingError::LackOfParameterError: return "缺少必要的参数";
        case PackingError::ParameterIsNotModifiableError: return "非初始状态，禁止操作参数";
        case PackingError::WriteParameterFailed: return "写入参数过程中发生错误导致写入失败";
        case PackingError::ValuePointerIsNullError: return "值的指针为空";
        case PackingError::ReadParameterFailed: return "读取提前参数过程中发生错误导致写入失败";
        default: return "未知错误";
        }
    }
    //从错误码数字获取对应描述
    inline const char* getPackingErrorDescriptionFromInt(int errorCode)
    {
        PackingError code = toPackingError(errorCode);
        return getPackingErrorDescription(code);
    }
    // 如果需要抛出异常，可以使用自定义异常类
    class PackingErrorException : public std::runtime_error {
    public:
        PackingErrorException(PackingError code)
            : std::runtime_error(getPackingErrorDescription(code)), errorCode(code) {}
        PackingErrorException(int code)
            : std::runtime_error(getPackingErrorDescriptionFromInt(code)), errorCode(toPackingError(code)) {}

        PackingError getErrorCode() const { return errorCode; }
    private:
        PackingError errorCode;
    };

}