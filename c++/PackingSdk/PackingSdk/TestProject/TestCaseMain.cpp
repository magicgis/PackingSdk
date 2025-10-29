#include <gtest/gtest.h>
#include "PackingSdkAll.h"
#include <windows.h>

namespace knest {
    //���Ȼص�����
    bool testCallBack(PackingSdk* sdk, const char* data)
    {
        SolverOutput output = JsonUtils::charToSolverOutput(data);
        //��ӡ�鿴
        std::cout << "========testCallBack==========" << "\n";
        //std::cout << "output.jsonResult:" << output.jsonResult << "\n";
        std::cout << "output.calUsage:" << output.calUsage << "\n";
        std::cout << "output.bestResultUsage:" << output.bestResultUsage << "\n";
        //std::cout << "output.partCountInBestResult:" << output.partCountInBestResult << "\n";
        //std::cout << "output.timeElapsedSinceLastResult:" << output.timeElapsedSinceLastResult << "\n";
        std::cout << "output.isMultiPriorityMode:" << output.isMultiPriorityMode << "\n";
        //����false��ʾ��Ҫֹͣ�Ż�����
        return false;
    }
    //���Ȼص�����
    void testCallBackVoid(PackingSdk* sdk, const char* data)
    {
        testCallBack(sdk, data);
    }
    //ʹ��doOptimization�����Ż�
    TEST(Main, doOptimization) {
        //������־����
        setLogLevel(2);//5��ֻ��ӡ������־�����Ҫ�鿴����ĵ�����Ϣ��־��������Ϊ2
        //��������
        NestInputData inputData;//��������
        AlgorithmParameter algorithmParam;//�㷨����
        algorithmParam.resultTimeOut = 10000;//�����Ż�����󣬵ȴ�10��������Ż�����仯�����㷨ֹͣ����
        algorithmParam.jsonResultAsFile = false;//�Ƿ��Ż�������Ϊ�ļ�
        inputData.algorithmParam = algorithmParam;
        BinParameter bin;//ԭ���ϴ�����
        bin.material = JsonUtils::gbkToUtf8("���ܶ���������ƴ");//������gbk����ת��Ϊutf-8������ʹ��utf-8���룩
        bin.thickness = 9;
        bin.trimL = 4.0;
        bin.trimR = 4.0;
        bin.trimT = 4.0;
        bin.trimB = 4.0;
        bin.spacing = 8;
        bin.binLength = 2440.0;
        bin.binWidth = 1220.0;
        bin.binCount = 10000;
        bin.binValue = 0;
        inputData.bins.push_back(bin);
        NestPart part1;
        part1.num = 1;
        part1.code = "C1";
        part1.length = 308.4;
        part1.width = 138.4;
        part1.quantity = 120;
        part1.texture = true;//������Ҫ�󣬼�������ת
        inputData.parts.push_back(part1);
        NestPart part2;
        part2.num = 2;
        part2.code = "C2";
        part2.length = 308.4;
        part2.width = 138.4;
        part2.quantity = 1;
        part2.texture = true;
        inputData.parts.push_back(part2);
        NestPart part3;
        part3.num = 3;
        part3.code = "C3";
        part3.length = 322.4;
        part3.width = 138.4;
        part3.quantity = 1;
        part3.texture = true;
        inputData.parts.push_back(part3);
        NestPart part4;
        part4.num = 4;
        part4.code = "C4";
        part4.length = 322.4;
        part4.width = 138.4;
        part4.quantity = 1;
        part4.texture = true;
        inputData.parts.push_back(part4);
        //�������ݵ��ܽṹ
        NestInput nestInput;
        nestInput.data = inputData;
        nestInput.version = 1;
        std::string dataString = nestInput.toJsonString();//����������ת��Ϊjson�ַ���
        const char* data = dataString.c_str();;
        //����PackingSdk����
        PackingSdk* sdk = packingNew();
        //ʹ��doOptimization�����Ű��Ż�(ͬ��)
        char* result = doOptimization(sdk, data, true, &testCallBack);//�������ݲ��Ż�(���html���)
        SolverOutput output = JsonUtils::charToSolverOutput(result);//���Ż����ת��ΪSolverOutput��������������
        //������ǽ��Ż��������Ϊ�ļ������Ż�����Ǵ����output.jsonResult��
        if (algorithmParam.jsonResultAsFile == false && output.bestResultSheetCount > 0)
        {
            std::string resultString = JsonUtils::gbkToUtf8(output.jsonResult.c_str());//Ϊ��JsonUtils��������ת������Ҫ��gbk����תΪutf-8
            NestOutput nestOutput = JsonUtils::jsonResultToNestOutput(resultString);//�Ű�������
            std::cout << "pattern count:" << nestOutput.data.patterns.size() << "\n";//��ӡ
        }
        else {
            //algorithmParam.jsonResultAsFileΪtrue�����Ű��������Ǳ�����json�ļ��У���ʱ���ļ�·�������output.jsonResult��
            //�����ж�ȡ��json�ļ�����ȡ���ݺ���JsonUtils::jsonResultToNestOutputת��Ϊ�Ż��������ṹ��NestOutput
        }
        std::string resultString = JsonUtils::utf8ToGbk(result);//Ϊ��������ʾ��ӡ����utf-8����ת��Ϊgbk
        std::cout << "doOptimization:" << resultString << "\n";//��ӡ
        charFree(result);//����char*
        packingFree(sdk);//����PackingSdk����
        EXPECT_EQ(output.bestResultSheetCount, 3);
    }
    //ʹ��packingStart�����Ż�
    TEST(Main, packingStart) {
        //������־����
        setLogLevel(2);//5��ֻ��ӡ������־�����Ҫ�鿴����ĵ�����Ϣ��־��������Ϊ2
        //��������
        NestInputData inputData;//��������
        AlgorithmParameter algorithmParam;//�㷨����
        algorithmParam.resultTimeOut = 10000;//�����Ż�����󣬵ȴ�10��������Ż�����仯�����㷨ֹͣ����
        algorithmParam.jsonResultAsFile = false;//�Ƿ��Ż�������Ϊ�ļ�
        inputData.algorithmParam = algorithmParam;
        BinParameter bin;//ԭ���ϴ�����
        bin.material = JsonUtils::gbkToUtf8("���ܶ���������ƴ");//������gbk����ת��Ϊutf-8������ʹ��utf-8���룩
        bin.thickness = 9;
        bin.trimL = 4.0;
        bin.trimR = 4.0;
        bin.trimT = 4.0;
        bin.trimB = 4.0;
        bin.spacing = 8;
        bin.binLength = 2440.0;
        bin.binWidth = 1220.0;
        bin.binCount = 10000;
        bin.binValue = 0;
        inputData.bins.push_back(bin);
        NestPart part1;
        part1.num = 1;
        part1.code = "C1";
        part1.length = 308.4;
        part1.width = 138.4;
        part1.quantity = 120;
        part1.texture = true;//������Ҫ�󣬼�������ת
        inputData.parts.push_back(part1);
        NestPart part2;
        part2.num = 2;
        part2.code = "C2";
        part2.length = 308.4;
        part2.width = 138.4;
        part2.quantity = 1;
        part2.texture = true;
        inputData.parts.push_back(part2);
        NestPart part3;
        part3.num = 3;
        part3.code = "C3";
        part3.length = 322.4;
        part3.width = 138.4;
        part3.quantity = 1;
        part3.texture = true;
        inputData.parts.push_back(part3);
        NestPart part4;
        part4.num = 4;
        part4.code = "C4";
        part4.length = 322.4;
        part4.width = 138.4;
        part4.quantity = 1;
        part4.texture = true;
        inputData.parts.push_back(part4);
        //�������ݵ��ܽṹ
        NestInput nestInput;
        nestInput.data = inputData;
        nestInput.version = 1;
        std::string dataString = nestInput.toJsonString();//����������ת��Ϊjson�ַ���
        const char* data = dataString.c_str();;
        //����PackingSdk����
        PackingSdk* sdk = packingNew();
        //�����Ż�(�첽)
        packingStart(sdk, data, true, &testCallBackVoid);//�����Ż��������ûص�
        //ģ��ȴ�����
        while (packingIsRunning(sdk) == true)
        {
            printf("..........");
            Sleep(1000);
        }
        //��ʱ�Ż��ѽ���
        EXPECT_EQ(packingIsRunning(sdk), false);
        //�����Ż�����
        packingFree(sdk);//����PackingSdk����
    }
    //ʹ���������ݽ����Ż�-ͬ���ķ�ʽ
    TEST(Main, doOptimizationByString) {
        //dataΪ��������
        std::string json_str = R"({"version":"1","data":{"param":{"material":"���ܶ���������ƴ","thickness":9.0,"trimL":4.0,"trimR":4.0,"trimT":4.0,"trimB":4.0,"spacing":8.0,"binLength":2440.0,"binWidth":1220.0,"binCount":1000000,"loopCount":2,"baseCorner":1,"nestType":1,"enablePriority":false,"higherPriorityPlacedFront":true,"resultTimeOut":6000},"parts":[{"code":"1189598","length":308.4,"width":138.39999999999999,"quantity":120,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":308.4,"y":0.0},{"x":308.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189599","length":308.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":308.4,"y":0.0},{"x":308.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189600","length":322.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":322.4,"y":0.0},{"x":322.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189602","length":322.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":322.4,"y":0.0},{"x":322.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//����PackingSdk����
            //ִ���Ż�(ͬ��)
            char* result = doOptimization(sdk, data, true, nullptr);//�������ݲ��Ż�
            SolverOutput output = JsonUtils::charToSolverOutput(result);
            std::string resultString = JsonUtils::utf8ToGbk(result);//Ϊ��������ʾ��ӡ����utf-8����תΪgbk
            std::cout << "do_optimization:" << resultString << "\n";//��ӡ
            charFree(result);//����char*
            //Ԥ���Ż���Ĵ������3
            EXPECT_EQ(output.bestResultSheetCount, 3);
        }
    }
    //ʹ���������ݽ����Ż�-�첽�ķ�ʽ
    TEST(Main, packingStartByString) {
        //dataΪ�������ݣ��Ż��ĵ��÷�Ϊ���ַ�ʽ���ֱ�Ϊ��ʽһ�ͷ�ʽ����������ʾ��
        std::string json_str = R"({"version":"1","data":{"param":{"material":"���ܶ���������ƴ","thickness":9.0,"trimL":4.0,"trimR":4.0,"trimT":4.0,"trimB":4.0,"spacing":8.0,"binLength":2440.0,"binWidth":1220.0,"binCount":1000000,"loopCount":2,"baseCorner":1,"nestType":1,"enablePriority":false,"higherPriorityPlacedFront":true,"resultTimeOut":6000},"parts":[{"code":"1189598","length":308.4,"width":138.39999999999999,"quantity":120,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":308.4,"y":0.0},{"x":308.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189599","length":308.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":308.4,"y":0.0},{"x":308.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189600","length":322.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":322.4,"y":0.0},{"x":322.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189602","length":322.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":322.4,"y":0.0},{"x":322.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//����PackingSdk����
            //�����Ż�(�첽)
            packingStart(sdk, data, true, &testCallBackVoid);//�����Ż��������ûص�
            //ģ��ȴ�����
            while (packingIsRunning(sdk) == true)
            {
                printf("..........");
                Sleep(1000);
            }
            //��ʱ�Ż��ѽ���
            EXPECT_EQ(packingIsRunning(sdk), false);
            //�����Ż�����
            packingFree(sdk);//����PackingSdk����
        }
    }
    //ʹ���������ݽ����Ż�-�������ݵİ汾��Ϊ����
    TEST(Main, packingStartVersionIsNum) {
        //�汾��Ϊ���֣����ڲ�Ϊ�ַ������Ӷ�������������
        std::string json_str = R"({"version":2,"data":{"algorithmParam":{"nestType":1,"baseCorner":1,"enablePriority":false,"priorityType":1,"higherPriorityPlacedFront":true,"resultTimeOut":6000,"jsonResultAsFile":false,"binValueType":1},"bins":[{"code":"default","material":"default","thickness":18.0,"trimL":2.0,"trimR":2.0,"trimT":2.0,"trimB":2.0,"spacing":12.2,"binLength":2800.0,"binWidth":2070.0,"binCount":1000000,"binValue":0.0}],"parts":[{"code":"1734074757","length":600.0,"width":500.0,"quantity":30,"texture":false,"priority":100,"outer":[{"x":0.0,"y":0.0},{"x":600.0,"y":0.0},{"x":600.0,"y":500.0},{"x":0.0,"y":500.0},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//����PackingSdk����
            std::cout << "packingNew:" << sdk;
            //��ʽ��(�첽)
            //�����Ż�
            packingStart(sdk, data, true, &testCallBackVoid);//�����Ż��������ûص�
            //ģ��ȴ�����
            while (packingIsRunning(sdk) == true)
            {
                printf("..........");
                Sleep(1000);
            }
            //��ʱ�Ż��ѽ���
            EXPECT_EQ(packingIsRunning(sdk), false);
            //�����Ż�����
            packingFree(sdk);//����PackingSdk����
        }
    }
    //ʹ���������ݽ����Ż�-�������ݵ�binValueType��Ϊ��
    TEST(Main, packingStartBinValueTypeIsNull) {
        //��json��Ӧ�������binValueType��priorityTypeΪnull��Ӧ����ҪΪĬ��ֵ
        std::string json_str = R"({"version":"1","data":{"param":{"material":"default","thickness":18.0,"trimL":2.0,"trimR":2.0,"trimT":2.0,"trimB":2.0,"spacing":12.2,"binLength":2800.0,"binWidth":2070.0,"binCount":1000000,"loopCount":2,"baseCorner":1,"nestType":1,"enablePriority":false,"higherPriorityPlacedFront":true,"useNest2ToInitResult":false,"resultTimeOut":6000,"littleBoardLength":230.0,"littleBoardArea":90000.0},"parts":[{"code":"1734077140","length":600.0,"width":500.0,"quantity":30,"texture":false,"priority":100,"outer":[{"x":0.0,"y":0.0},{"x":600.0,"y":0.0},{"x":600.0,"y":500.0},{"x":0.0,"y":500.0},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//����PackingSdk����
            std::cout << "packingNew:" << sdk;
            //��ʽ��(�첽)
            //�����Ż�
            packingStart(sdk, data, true, &testCallBackVoid);//�����Ż��������ûص�
            //ģ��ȴ�����
            while (packingIsRunning(sdk) == true)
            {
                printf("..........");
                Sleep(1000);
            }
            //��ʱ�Ż��ѽ���
            EXPECT_EQ(packingIsRunning(sdk), false);
            //�����Ż�����
            packingFree(sdk);//����PackingSdk����
        }
    }
    //ʹ���������ݽ����Ż�-���ľ�������
    TEST(Main, packingStartBoardGapProblem) {
        //���ľ���������������
        std::string json_str = R"({"version":1,"data":{"param":{"material":"default","thickness":18.0,"trimL":20.0,"trimR":20.0,"trimT":20.0,"trimB":20.0,"spacing":10.0,"binLength":2800.0,"binWidth":2070.0,"binCount":1000000,"loopCount":2,"baseCorner":4,"nestType":3,"enablePriority":false,"higherPriorityPlacedFront":true,"useNest2ToInitResult":false,"resultTimeOut":6000,"littleBoardLength":200.0,"littleBoardArea":70000.0,"enableExecCbOnTimer":true,"execCbOnTimerInterval":1},"parts":[{"code":"1734342173","length":600.0,"width":500.0,"quantity":30,"texture":false,"priority":0,"outer":[{"x":0.0,"y":0.0},{"x":600.0,"y":0.0},{"x":600.0,"y":500.0},{"x":0.0,"y":500.0},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//����PackingSdk����
            std::cout << "packingNew:" << sdk;
            //��ʽ��(�첽)
            //�����Ż�
            packingStart(sdk, data, true, &testCallBackVoid);//�����Ż��������ûص�
            //ģ��ȴ�����
            while (packingIsRunning(sdk) == true)
            {
                printf("..........");
                Sleep(1000);
            }
            //��ʱ�Ż��ѽ���
            EXPECT_EQ(packingIsRunning(sdk), false);
            //�����Ż�����
            packingFree(sdk);//����PackingSdk����
        }
    }
}