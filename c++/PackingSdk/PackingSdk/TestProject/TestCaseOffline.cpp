#include <gtest/gtest.h>
#include "PackingSdkAll.h"
//离线加密狗相关测试样例
namespace knest {
    const char* REG_CODE = "BAS-BA2I-OPKQ-76PO-13TH";//注册码
    //强制取消/删除本机离线授权
    TEST(Offline, cancelOfflineLicenseForce) {
        int cancelResult = cancelOfflineLicenseForce(true);//返回0表示成功
        std::cout << "==cancelOfflineLicenseForce:" << cancelResult << "\n";//打印返回结果
        EXPECT_EQ(cancelResult, 0);
    }
    //注册离线授权
    TEST(Offline, registerOfflineLicense) {
        //注册离线授权
        const char* registerParams = "{\"a\":\"1\", \"b\": \"2\", \"d\":\"test\"}";//注册的时候要写入授权的参数（json字符串）
        int rtn = registerOfflineLicense(REG_CODE, registerParams);
        std::cout << "==registerOfflineLicense rtn:" << rtn << (rtn == 0 ? "注册成功" : "注册失败") << "\n";//打印返回结果
        EXPECT_EQ(rtn, 0);
    }
    //取消/删除本机离线授权
    TEST(Offline, cancelOfflineLicense) {
        int cancelResult = cancelOfflineLicense();//返回0表示成功
        std::cout << "==cancelOfflineLicense:" << cancelResult << "\n";//打印返回结果
        EXPECT_EQ(cancelResult, 0);
    }
    //重新注册离线授权
    TEST(Offline, registerOfflineLicenseWithLastMachineCode) {
        //注册离线授权
        const char* dogCode = "";//本机重新注册时dogCode为空，当非本机重新注册时，dogCode放入原已注册电脑的dogCode(通过getDogCode获取)
        const char* registerParams = "{\"a\":\"1\", \"b\": \"2\", \"d\":\"test\"}";//注册的时候要写入授权的参数（json字符串）
        int rtn = registerOfflineLicenseWithLastMachineCode(REG_CODE, dogCode, registerParams);
        std::cout << "==registerOfflineLicenseWithLastMachineCode rtn:" << rtn << (rtn == 0 ? "注册成功" : "注册失败") << "\n";//打印返回结果
        EXPECT_EQ(rtn, 0);
    }
    //获取当前离线授权剩余天数
    TEST(Offline, getOfflineDogRestDays) {
        //获取当前授权剩余天数
        int rest_days = 0;
        int rtn = getOfflineDogRestDays(&rest_days);
        std::cout << "==getOfflineDogRestDays rnt:" << rtn << "\n";//打印返回结果
        std::cout << "==getOfflineDogRestDays:" << rest_days << "\n";//打印返回结果
        EXPECT_EQ(rtn, 0);
        EXPECT_NE(rest_days, 0);//0表示已经过期，-1表示没有时间限制，其他正数表示剩余的天数
    }
    //获取当前授权的注册码
    TEST(Offline, getRegisterCode11) {
        //获取加密狗的注册码（离线授权）
        char* currentRegisterCode = getRegisterCode();//获取离线授权的注册码
        std::cout << "==registerCode:" << currentRegisterCode << "\n";
        EXPECT_EQ(strcmp(currentRegisterCode, REG_CODE), 0);
        charFree(currentRegisterCode);
    }
    //根据key读取离线授权的参数的值
    TEST(Offline, readOfflineDog11) {
        //根据key读取加密狗的数据（离线授权）
        char buffer[1024] = { 0 }; // 读取的数据，假设最大长度为1024
        int rtn = readOfflineDog("a", buffer);//读取加密狗的数据
        std::string bufferString = std::string(JsonUtils::utf8ToGbk(buffer));//将char进行转码后转为string
        std::cout << "==readOfflineDog rtn:" << rtn << "\n";//打印返回结果
        std::cout << "==readOfflineDog result:" << bufferString << "\n";//打印返回结果
        EXPECT_EQ(rtn, 0);
    }
    //从服务器中读取指定注册码的参数的值
    TEST(Offline, readParameterByRegisterCode) {
        // 示例1：读取整型数据
        const char* regCode = "TRI-ZB3W-6UNO-B4I5-41YO";
        const char* key = "key1";
        int intValue;
        int errorCode = readParameterByRegisterCode(regCode, key, &intValue);
        if (errorCode == 0) {
            std::cout << "读取到的整数值: " << intValue << std::endl;
        }

        // 示例2：读取浮点数据
        float floatValue;
        errorCode = readParameterByRegisterCode(regCode, key, &floatValue);
        if (errorCode == 0) {
            std::cout << "读取到的浮点值: " << floatValue << std::endl;
        }

        // 示例3：读取字符串数据
        char stringBuffer[256] = { 0 };
        errorCode = readParameterByRegisterCode(regCode, key, stringBuffer);
        if (errorCode == 0) {
            std::cout << "读取到的字符串: " << stringBuffer << std::endl;
        }
        EXPECT_EQ(errorCode, 0);
    }
    //向服务器读取指定注册码的状态
    TEST(Offline, readRegisterCodeStatus) {
        const char* regCode = "TRI-ZB3W-6UNO-B4I5-41YO";
        int statusValaue;
        int errorCode = readRegisterCodeStatus(regCode, &statusValaue);
        if (errorCode == 0) {
            std::cout << "注册码的状态为: " << statusValaue << std::endl;
        }
        EXPECT_EQ(errorCode, 0);
    }
}