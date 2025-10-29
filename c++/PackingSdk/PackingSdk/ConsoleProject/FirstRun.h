#pragma once
#include "PackingSdkAll.h"
#include <windows.h>

namespace knest {
    //�ص�����
    bool callBack(PackingSdk* sdk, const char* data)
    {
        SolverOutput output = JsonUtils::charToSolverOutput(data);
        //��ӡ�鿴
        std::cout << "========callBack==========" << "\n";
        //std::cout << "output.jsonResult:" << output.jsonResult << "\n";
        std::cout << "output.calUsage:" << output.calUsage << "\n";
        std::cout << "output.bestResultUsage:" << output.bestResultUsage << "\n";
        //std::cout << "output.partCountInBestResult:" << output.partCountInBestResult << "\n";
        //std::cout << "output.timeElapsedSinceLastResult:" << output.timeElapsedSinceLastResult << "\n";
        std::cout << "output.isMultiPriorityMode:" << output.isMultiPriorityMode << "\n";
        //����false��ʾ��Ҫֹͣ�Ż�����
        return false;
    }
    //�ص�����
    void callBackVoid(PackingSdk* sdk, const char* data)
    {
        knest::callBack(sdk, data);
    }

    //��һ����������
    int firstRun() {
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
        char* result = doOptimization(sdk, data, true, nullptr);//�������ݲ��Ż�(���html���)
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
        return 0;
    }

    //�ڶ����������ӣ��лص���
    int secondRun() {
        //������־����
        setLogLevel(5);//5��ֻ��ӡ������־�����Ҫ�鿴����ĵ�����Ϣ��־��������Ϊ2
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
        char* result = doOptimization(sdk, data, true, &callBack);//�������ݲ��Ż�(���html���)
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
        return 0;
    }

    //�������������ӣ����ص����������ӣ�ʹ��PackingSdk-packingStart�����Ż���
    int thirdRun() {
        //������־����
        setLogLevel(5);//5��ֻ��ӡ������־�����Ҫ�鿴����ĵ�����Ϣ��־��������Ϊ2
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
        //ʹ��packingStart�����Ű��Ż�(�첽)
        packingStart(sdk, data, true, &callBackVoid);//�������ݲ��Ż�(���html���)
        //ģ��ȴ�����
        while (packingIsRunning(sdk) == true)
        {
            printf("..........");
            Sleep(1000);
        }
        //�����Ż�����
        packingFree(sdk);//����PackingSdk����
        return 0;
    }

    //���ĸ��������ӣ����ص����������ӣ�ʹ��PackingSdk-doOptimization�����Ż���
    int fourthRun() {
        //������־����
        setLogLevel(5);//5��ֻ��ӡ������־�����Ҫ�鿴����ĵ�����Ϣ��־��������Ϊ2
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
        char* result = doOptimization(sdk, data, true, &callBack);//�������ݲ��Ż�(���html���)
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
        return 0;
    }

}