#include <gtest/gtest.h>
#include "PackingSdkAll.h"
// (���߼��ܹ�)���õĲ�������
namespace knest {
    const int DOG_TYPE = 2;//������Ϊ���߼��ܹ�
    //������־����
    TEST(CommonOffline, setLogLevel) {
        //������־����
        setLogLevel(2);
        helloWorld();
    }
    //��ȡ���ܹ�code
    TEST(CommonOffline, getDogCode) {
        //��ȡ���ܹ���code
        char* dogCode = getDogCode();
        std::cout << "dogCode:" << dogCode << "\n";//��ӡ���ؽ��
        //�ж�code�ǿղ��ҷǿ��ַ���
        EXPECT_NE(dogCode, nullptr);
        EXPECT_NE(dogCode[0], '\0');
        charFree(dogCode);
    }
    //��ȡ���ܹ�code2
    TEST(CommonOffline, getDogCode2) {
        //��ȡ���ܹ���code
        char* dogCode = nullptr;
        int rtn = getDogCode2(&dogCode);
        EXPECT_EQ(rtn, 0);
        //�ж�code�ǿղ��ҷǿ��ַ���
        EXPECT_NE(dogCode, nullptr);
        EXPECT_NE(dogCode[0], '\0');
        charFree(dogCode);
    }
    //���ݼ��ܹ����ͻ�ȡ���ܹ�code
    TEST(CommonOffline, getDogCodeByDogType) {
        //��ȡ���߼��ܹ���code
        char* dogCode = getDogCodeByDogType(DOG_TYPE);
        //�ж�code�ǿղ��ҷǿ��ַ���
        EXPECT_NE(dogCode, nullptr);
        EXPECT_NE(dogCode[0], '\0');
        charFree(dogCode);
    }
    //���ݼ��ܹ����ͻ�ȡ���ܹ�code2
    TEST(CommonOffline, getDogCodeByDogType2) {
        //��ȡ���߼��ܹ���code
        char* dogCode = nullptr;
        int rtn = getDogCodeByDogType2(DOG_TYPE, &dogCode);
        EXPECT_EQ(rtn, 0);
        //�ж�code�ǿղ��ҷǿ��ַ���
        EXPECT_NE(dogCode, nullptr);
        EXPECT_NE(dogCode[0], '\0');
        charFree(dogCode);
    }
    //���ܹ��Ƿ����
    TEST(CommonOffline, isDogValid) {
        //��ȡ���ܹ��Ƿ����
        bool isValid = isDogValid();
        //���ܹ�����
        EXPECT_EQ(isValid, true);
    }
    //�����ܹ���д������-����5
    TEST(CommonOffline, writeDog) {
        int startOffset = 1;//д�����ݵĿ�ʼ��ַ��ƫ��ֵ������ַ��Χֵ��0-494��
        int dataSize = 1;//д�����ݵĴ�С
        int val = 5;//Ҫд���ֵ
        const void* voidPtr = &val;//ֵ���ڴ��ַ
        int rtn = writeDog(startOffset, dataSize, voidPtr);//��ֵд����ܹ�
        std::cout << "write rtn:" << rtn << "\n";//��ӡ���ؽ��
        std::cout << "write rtn error msg:" << getPackingErrorDescriptionFromInt(rtn) << "\n";//��ӡ���ؽ��
        EXPECT_EQ(rtn, 0);
    }
    //��ȡ���ܹ�����-����5
    TEST(CommonOffline, readDog) {
        int startOffset = 1;//��ȡ���ݵĿ�ʼ��ַ��ƫ��ֵ������ַ��Χֵ��0-494��
        int dataSize = 1;//��ȡ���ݵĴ�С
        //��ȡ���ܹ�������
        unsigned char* ptr = new unsigned char[dataSize];//��ȡ������
        int rtn = readDog(startOffset, dataSize, ptr);//��ȡ���ܹ�������
        std::cout << "read rtn:" << rtn << "\n";//��ӡ���ؽ��
        std::cout << "read result:" << "\n";//��ӡ���ؽ��
        //����ֽڴ�ӡ
        for (int i = 0; i < dataSize; i++) {
            printf("char:%01X\n", ptr[i]);
        }
        EXPECT_EQ(rtn, 0);
        EXPECT_EQ(static_cast<char>(ptr[0]), 0x05);
    }
    //�����ܹ���д������-char����
    TEST(CommonOffline, writeDogWithChar) {
        int startOffset = 300;//д�����ݵĿ�ʼ��ַ��ƫ��ֵ������ַ��Χֵ��0-494��
        int dataSize = 16;//д�����ݵĴ�С
        unsigned char dataTest[17] = { 'x' };//����д�������
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
        int rtn = writeDog(startOffset, dataSize, dataTest);//��ֵд����ܹ�
        std::cout << "write rtn:" << rtn << "\n";//��ӡ���ؽ��
        std::cout << "write rtn error msg:" << getPackingErrorDescriptionFromInt(rtn) << "\n";//��ӡ���ؽ��
        EXPECT_EQ(rtn, 0);
    }
    //��ȡ���ܹ�����-char����
    TEST(CommonOffline, readDogWithChar) {
        int startOffset = 300;//��ȡ���ݵĿ�ʼ��ַ��ƫ��ֵ������ַ��Χֵ��0-494��
        int dataSize = 16;//��ȡ���ݵĴ�С
        //��ȡ���ܹ�������
        unsigned char* ptr = new unsigned char[dataSize];//��ȡ������
        int rtn = readDog(startOffset, dataSize, ptr);//��ȡ���ܹ�������
        std::cout << "read rtn:" << rtn << "\n";//��ӡ���ؽ��
        std::cout << "read result:" << "\n";//��ӡ���ؽ��
        printf("char :");
        //����ֽڴ�ӡ
        for (int i = 0; i < dataSize; i++) {
            printf("%02X ", ptr[i]);
        }
        printf("\n");
        EXPECT_EQ(rtn, 0);
        EXPECT_EQ(static_cast<char>(ptr[15]), 0x43);
    }
    //�Ƿ�֧�ֻ�ȡʱ��
    TEST(CommonOffline, supportGetDogTime) {
        //���ܹ��Ƿ�֧�ֶ�ȡʱ��
        int isSupport = supportGetDogTime();
        std::cout << "supportGetDogTime:" << (isSupport == 1 ? "֧��" : "��֧��") << "\n";//��ӡ���ؽ��
        //���߼��ܹ�֧�ֻ�ȡʱ��
        EXPECT_EQ(isSupport, 1);
    }
    //��ȡʱ�䣨�� 1970 �� 1 �� 1 �տ�ʼ������������
    TEST(CommonOffline, getDogTime) {
        //��ȡʱ�䣨�� 1970 �� 1 �� 1 �տ�ʼ������������
        long long time;//�� 1970 �� 1 �� 1 �տ�ʼ����������
        int rtn = getDogTime(&time);
        std::cout << "getDogTime rtn:" << rtn << "\n";//��ӡ���ؽ��
        std::cout << "getDogTime result:" << time << "\n";//��ӡ���ؽ��
        //EXPECT_EQ(rtn, 3);//3��ʾ����ǰ���ܹ��޴˺�����ʵ�֡�
        EXPECT_NE(time, 0);
    }
    //��ȡ���ܹ�����
    TEST(CommonOffline, getDogType) {
        //��ȡ���ܹ�����
        int dogType = getDogType();
        std::cout << "getDogType:" << dogType << "\n";//��ӡ���ؽ��
        EXPECT_NE(dogType, 0);//0��ʾδ���� 1��ʾUSB���ܹ� 2��ʾ���ߵļ��ܹ� 3��ʾ���ߵļ��ܹ�
    }
    //��ȡ���ܹ����ײ�����
    TEST(CommonOffline, getDogSuite) {
        //��ȡ���ܹ��İ汾�ײ�
        int dogSuite = getDogSuite();
        std::cout << "getDogSuite:" << dogSuite << "\n";//��ӡ���ؽ��
        EXPECT_NE(dogSuite, 0);//0��ʾδ������ײͣ�1��ʾ��׼�汾�ײ� 2��ʾ�߼��汾�ײ�
    }
}