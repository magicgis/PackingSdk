#include <gtest/gtest.h>
#include "PackingSdkAll.h"
// (离线加密狗)适用的测试用例
namespace knest {
    const int DOG_TYPE = 2;//狗类型为离线加密狗
    //设置日志级别
    TEST(CommonOffline, setLogLevel) {
        //设置日志级别
        setLogLevel(2);
        helloWorld();
    }
    //获取加密狗code
    TEST(CommonOffline, getDogCode) {
        //获取加密狗的code
        char* dogCode = getDogCode();
        std::cout << "dogCode:" << dogCode << "\n";//打印返回结果
        //判断code非空并且非空字符串
        EXPECT_NE(dogCode, nullptr);
        EXPECT_NE(dogCode[0], '\0');
        charFree(dogCode);
    }
    //获取加密狗code2
    TEST(CommonOffline, getDogCode2) {
        //获取加密狗的code
        char* dogCode = nullptr;
        int rtn = getDogCode2(&dogCode);
        EXPECT_EQ(rtn, 0);
        //判断code非空并且非空字符串
        EXPECT_NE(dogCode, nullptr);
        EXPECT_NE(dogCode[0], '\0');
        charFree(dogCode);
    }
    //根据加密狗类型获取加密狗code
    TEST(CommonOffline, getDogCodeByDogType) {
        //获取离线加密狗的code
        char* dogCode = getDogCodeByDogType(DOG_TYPE);
        //判断code非空并且非空字符串
        EXPECT_NE(dogCode, nullptr);
        EXPECT_NE(dogCode[0], '\0');
        charFree(dogCode);
    }
    //根据加密狗类型获取加密狗code2
    TEST(CommonOffline, getDogCodeByDogType2) {
        //获取离线加密狗的code
        char* dogCode = nullptr;
        int rtn = getDogCodeByDogType2(DOG_TYPE, &dogCode);
        EXPECT_EQ(rtn, 0);
        //判断code非空并且非空字符串
        EXPECT_NE(dogCode, nullptr);
        EXPECT_NE(dogCode[0], '\0');
        charFree(dogCode);
    }
    //加密狗是否可用
    TEST(CommonOffline, isDogValid) {
        //获取加密狗是否可用
        bool isValid = isDogValid();
        //加密狗可用
        EXPECT_EQ(isValid, true);
    }
    //往加密狗中写入数据-数字5
    TEST(CommonOffline, writeDog) {
        int startOffset = 1;//写入数据的开始地址（偏移值），地址范围值（0-494）
        int dataSize = 1;//写入数据的大小
        int val = 5;//要写入的值
        const void* voidPtr = &val;//值的内存地址
        int rtn = writeDog(startOffset, dataSize, voidPtr);//将值写入加密狗
        std::cout << "write rtn:" << rtn << "\n";//打印返回结果
        std::cout << "write rtn error msg:" << getPackingErrorDescriptionFromInt(rtn) << "\n";//打印返回结果
        EXPECT_EQ(rtn, 0);
    }
    //读取加密狗数据-数字5
    TEST(CommonOffline, readDog) {
        int startOffset = 1;//读取数据的开始地址（偏移值），地址范围值（0-494）
        int dataSize = 1;//读取数据的大小
        //读取加密狗的数据
        unsigned char* ptr = new unsigned char[dataSize];//读取的数据
        int rtn = readDog(startOffset, dataSize, ptr);//读取加密狗的数据
        std::cout << "read rtn:" << rtn << "\n";//打印返回结果
        std::cout << "read result:" << "\n";//打印返回结果
        //逐个字节打印
        for (int i = 0; i < dataSize; i++) {
            printf("char:%01X\n", ptr[i]);
        }
        EXPECT_EQ(rtn, 0);
        EXPECT_EQ(static_cast<char>(ptr[0]), 0x05);
    }
    //往加密狗中写入数据-char数组
    TEST(CommonOffline, writeDogWithChar) {
        int startOffset = 300;//写入数据的开始地址（偏移值），地址范围值（0-494）
        int dataSize = 16;//写入数据的大小
        unsigned char dataTest[17] = { 'x' };//测试写入的数据
        {
            dataTest[0] = 0xb0;
            dataTest[1] = 0x02;
            dataTest[2] = 0x00;
            dataTest[3] = 0x69;
            dataTest[4] = 0x59;
            dataTest[5] = 0x23;
            dataTest[6] = 0x05;
            dataTest[7] = 0xc4;
            dataTest[8] = 0x66;
            dataTest[9] = 0x77;
            dataTest[10] = 0x43;
            dataTest[11] = 0x65;
            dataTest[12] = 0x77;
            dataTest[13] = 0x75;
            dataTest[14] = 0x54;
            dataTest[15] = 0x43;
            dataTest[16] = 0x00;
        }
        printf("write:");
        for (int i = 0; i < dataSize; i++) {
            printf("%02X ", dataTest[i]);
        }
        printf("\n");
        printf("write:");
        for (int i = 0; i < dataSize; i++) {
            printf("%02X ", (char)dataTest[i]);
        }
        printf("\n");
        int rtn = writeDog(startOffset, dataSize, dataTest);//将值写入加密狗
        std::cout << "write rtn:" << rtn << "\n";//打印返回结果
        std::cout << "write rtn error msg:" << getPackingErrorDescriptionFromInt(rtn) << "\n";//打印返回结果
        EXPECT_EQ(rtn, 0);
    }
    //读取加密狗数据-char数组
    TEST(CommonOffline, readDogWithChar) {
        int startOffset = 300;//读取数据的开始地址（偏移值），地址范围值（0-494）
        int dataSize = 16;//读取数据的大小
        //读取加密狗的数据
        unsigned char* ptr = new unsigned char[dataSize];//读取的数据
        int rtn = readDog(startOffset, dataSize, ptr);//读取加密狗的数据
        std::cout << "read rtn:" << rtn << "\n";//打印返回结果
        std::cout << "read result:" << "\n";//打印返回结果
        printf("char :");
        //逐个字节打印
        for (int i = 0; i < dataSize; i++) {
            printf("%02X ", ptr[i]);
        }
        printf("\n");
        EXPECT_EQ(rtn, 0);
        EXPECT_EQ(static_cast<char>(ptr[15]), 0x43);
    }
    //是否支持获取时间
    TEST(CommonOffline, supportGetDogTime) {
        //加密狗是否支持读取时间
        int isSupport = supportGetDogTime();
        std::cout << "supportGetDogTime:" << (isSupport == 1 ? "支持" : "不支持") << "\n";//打印返回结果
        //离线加密狗支持获取时间
        EXPECT_EQ(isSupport, 1);
    }
    //获取时间（从 1970 年 1 月 1 日开始经过的秒数）
    TEST(CommonOffline, getDogTime) {
        //获取时间（从 1970 年 1 月 1 日开始经过的秒数）
        long long time;//从 1970 年 1 月 1 日开始经过的秒数
        int rtn = getDogTime(&time);
        std::cout << "getDogTime rtn:" << rtn << "\n";//打印返回结果
        std::cout << "getDogTime result:" << time << "\n";//打印返回结果
        //EXPECT_EQ(rtn, 3);//3表示“当前加密狗无此函数的实现”
        EXPECT_NE(time, 0);
    }
    //获取加密狗类型
    TEST(CommonOffline, getDogType) {
        //获取加密狗类型
        int dogType = getDogType();
        std::cout << "getDogType:" << dogType << "\n";//打印返回结果
        EXPECT_NE(dogType, 0);//0表示未定义 1表示USB加密狗 2表示离线的加密狗 3表示在线的加密狗
    }
    //获取加密狗的套餐类型
    TEST(CommonOffline, getDogSuite) {
        //获取加密狗的版本套餐
        int dogSuite = getDogSuite();
        std::cout << "getDogSuite:" << dogSuite << "\n";//打印返回结果
        EXPECT_NE(dogSuite, 0);//0表示未定义的套餐，1表示标准版本套餐 2表示高级版本套餐
    }
}