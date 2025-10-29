#include <gtest/gtest.h>
#include "PackingSdkAll.h"
//���߼��ܹ���ز�������
namespace knest {
    const char* REG_CODE = "BAS-BA2I-OPKQ-76PO-13TH";//ע����
    //ǿ��ȡ��/ɾ������������Ȩ
    TEST(Offline, cancelOfflineLicenseForce) {
        int cancelResult = cancelOfflineLicenseForce(true);//����0��ʾ�ɹ�
        std::cout << "==cancelOfflineLicenseForce:" << cancelResult << "\n";//��ӡ���ؽ��
        EXPECT_EQ(cancelResult, 0);
    }
    //ע��������Ȩ
    TEST(Offline, registerOfflineLicense) {
        //ע��������Ȩ
        const char* registerParams = "{\"a\":\"1\", \"b\": \"2\", \"d\":\"test\"}";//ע���ʱ��Ҫд����Ȩ�Ĳ�����json�ַ�����
        int rtn = registerOfflineLicense(REG_CODE, registerParams);
        std::cout << "==registerOfflineLicense rtn:" << rtn << (rtn == 0 ? "ע��ɹ�" : "ע��ʧ��") << "\n";//��ӡ���ؽ��
        EXPECT_EQ(rtn, 0);
    }
    //ȡ��/ɾ������������Ȩ
    TEST(Offline, cancelOfflineLicense) {
        int cancelResult = cancelOfflineLicense();//����0��ʾ�ɹ�
        std::cout << "==cancelOfflineLicense:" << cancelResult << "\n";//��ӡ���ؽ��
        EXPECT_EQ(cancelResult, 0);
    }
    //����ע��������Ȩ
    TEST(Offline, registerOfflineLicenseWithLastMachineCode) {
        //ע��������Ȩ
        const char* dogCode = "";//��������ע��ʱdogCodeΪ�գ����Ǳ�������ע��ʱ��dogCode����ԭ��ע����Ե�dogCode(ͨ��getDogCode��ȡ)
        const char* registerParams = "{\"a\":\"1\", \"b\": \"2\", \"d\":\"test\"}";//ע���ʱ��Ҫд����Ȩ�Ĳ�����json�ַ�����
        int rtn = registerOfflineLicenseWithLastMachineCode(REG_CODE, dogCode, registerParams);
        std::cout << "==registerOfflineLicenseWithLastMachineCode rtn:" << rtn << (rtn == 0 ? "ע��ɹ�" : "ע��ʧ��") << "\n";//��ӡ���ؽ��
        EXPECT_EQ(rtn, 0);
    }
    //��ȡ��ǰ������Ȩʣ������
    TEST(Offline, getOfflineDogRestDays) {
        //��ȡ��ǰ��Ȩʣ������
        int rest_days = 0;
        int rtn = getOfflineDogRestDays(&rest_days);
        std::cout << "==getOfflineDogRestDays rnt:" << rtn << "\n";//��ӡ���ؽ��
        std::cout << "==getOfflineDogRestDays:" << rest_days << "\n";//��ӡ���ؽ��
        EXPECT_EQ(rtn, 0);
        EXPECT_NE(rest_days, 0);//0��ʾ�Ѿ����ڣ�-1��ʾû��ʱ�����ƣ�����������ʾʣ�������
    }
    //��ȡ��ǰ��Ȩ��ע����
    TEST(Offline, getRegisterCode11) {
        //��ȡ���ܹ���ע���루������Ȩ��
        char* currentRegisterCode = getRegisterCode();//��ȡ������Ȩ��ע����
        std::cout << "==registerCode:" << currentRegisterCode << "\n";
        EXPECT_EQ(strcmp(currentRegisterCode, REG_CODE), 0);
        charFree(currentRegisterCode);
    }
    //����key��ȡ������Ȩ�Ĳ�����ֵ
    TEST(Offline, readOfflineDog11) {
        //����key��ȡ���ܹ������ݣ�������Ȩ��
        char buffer[1024] = { 0 }; // ��ȡ�����ݣ�������󳤶�Ϊ1024
        int rtn = readOfflineDog("a", buffer);//��ȡ���ܹ�������
        std::string bufferString = std::string(JsonUtils::utf8ToGbk(buffer));//��char����ת���תΪstring
        std::cout << "==readOfflineDog rtn:" << rtn << "\n";//��ӡ���ؽ��
        std::cout << "==readOfflineDog result:" << bufferString << "\n";//��ӡ���ؽ��
        EXPECT_EQ(rtn, 0);
    }
    //�ӷ������ж�ȡָ��ע����Ĳ�����ֵ
    TEST(Offline, readParameterByRegisterCode) {
        // ʾ��1����ȡ��������
        const char* regCode = "TRI-ZB3W-6UNO-B4I5-41YO";
        const char* key = "key1";
        int intValue;
        int errorCode = readParameterByRegisterCode(regCode, key, &intValue);
        if (errorCode == 0) {
            std::cout << "��ȡ��������ֵ: " << intValue << std::endl;
        }

        // ʾ��2����ȡ��������
        float floatValue;
        errorCode = readParameterByRegisterCode(regCode, key, &floatValue);
        if (errorCode == 0) {
            std::cout << "��ȡ���ĸ���ֵ: " << floatValue << std::endl;
        }

        // ʾ��3����ȡ�ַ�������
        char stringBuffer[256] = { 0 };
        errorCode = readParameterByRegisterCode(regCode, key, stringBuffer);
        if (errorCode == 0) {
            std::cout << "��ȡ�����ַ���: " << stringBuffer << std::endl;
        }
        EXPECT_EQ(errorCode, 0);
    }
    //���������ȡָ��ע�����״̬
    TEST(Offline, readRegisterCodeStatus) {
        const char* regCode = "TRI-ZB3W-6UNO-B4I5-41YO";
        int statusValaue;
        int errorCode = readRegisterCodeStatus(regCode, &statusValaue);
        if (errorCode == 0) {
            std::cout << "ע�����״̬Ϊ: " << statusValaue << std::endl;
        }
        EXPECT_EQ(errorCode, 0);
    }
}