#pragma once
#include "PackingSdkAll.h"
#include <windows.h>

namespace knest {
    //回调函数
    bool callBack(PackingSdk* sdk, const char* data)
    {
        SolverOutput output = JsonUtils::charToSolverOutput(data);
        //打印查看
        std::cout << "========callBack==========" << "\n";
        //std::cout << "output.jsonResult:" << output.jsonResult << "\n";
        std::cout << "output.calUsage:" << output.calUsage << "\n";
        std::cout << "output.bestResultUsage:" << output.bestResultUsage << "\n";
        //std::cout << "output.partCountInBestResult:" << output.partCountInBestResult << "\n";
        //std::cout << "output.timeElapsedSinceLastResult:" << output.timeElapsedSinceLastResult << "\n";
        std::cout << "output.isMultiPriorityMode:" << output.isMultiPriorityMode << "\n";
        //返回false表示不要停止优化计算
        return false;
    }
    //回调函数
    void callBackVoid(PackingSdk* sdk, const char* data)
    {
        knest::callBack(sdk, data);
    }

    //第一个运行例子
    int firstRun() {
        //设置日志级别
        setLogLevel(2);//5是只打印错误日志，如果要查看更多的调试信息日志，可设置为2
        //输入数据
        NestInputData inputData;//输入数据
        AlgorithmParameter algorithmParam;//算法参数
        algorithmParam.resultTimeOut = 10000;//当有优化结果后，等待10秒后再无优化结果变化，则算法停止运行
        algorithmParam.jsonResultAsFile = false;//是否将优化结果输出为文件
        inputData.algorithmParam = algorithmParam;
        BinParameter bin;//原材料大板参数
        bin.material = JsonUtils::gbkToUtf8("加密多层贴白橡混拼");//将中文gbk编码转换为utf-8（必须使用utf-8编码）
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
        part1.texture = true;//有纹理要求，即不能旋转
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
        //输入数据的总结构
        NestInput nestInput;
        nestInput.data = inputData;
        nestInput.version = 1;
        std::string dataString = nestInput.toJsonString();//将输入数据转换为json字符串
        const char* data = dataString.c_str();;
        //创建PackingSdk对象
        PackingSdk* sdk = packingNew();
        //使用doOptimization进行排版优化(同步)
        char* result = doOptimization(sdk, data, true, nullptr);//送入数据并优化(输出html结果)
        SolverOutput output = JsonUtils::charToSolverOutput(result);//将优化结果转换为SolverOutput（方案输出结果）
        //如果不是将优化结果保存为文件，则优化结果是存放于output.jsonResult的
        if (algorithmParam.jsonResultAsFile == false && output.bestResultSheetCount > 0)
        {
            std::string resultString = JsonUtils::gbkToUtf8(output.jsonResult.c_str());//为了JsonUtils可以正常转换，需要将gbk编码转为utf-8
            NestOutput nestOutput = JsonUtils::jsonResultToNestOutput(resultString);//排版输出结果
            std::cout << "pattern count:" << nestOutput.data.patterns.size() << "\n";//打印
        }
        else {
            //algorithmParam.jsonResultAsFile为true，则排版输出结果是保存在json文件中，此时其文件路径存放于output.jsonResult中
            //可自行读取该json文件，读取内容后用JsonUtils::jsonResultToNestOutput转换为优化输出结果结构体NestOutput
        }
        std::string resultString = JsonUtils::utf8ToGbk(result);//为了正常显示打印，将utf-8编码转换为gbk
        std::cout << "doOptimization:" << resultString << "\n";//打印
        charFree(result);//销毁char*
        packingFree(sdk);//销毁PackingSdk对象
        return 0;
    }

    //第二个运行例子（有回调）
    int secondRun() {
        //设置日志级别
        setLogLevel(5);//5是只打印错误日志，如果要查看更多的调试信息日志，可设置为2
        //输入数据
        NestInputData inputData;//输入数据
        AlgorithmParameter algorithmParam;//算法参数
        algorithmParam.resultTimeOut = 10000;//当有优化结果后，等待10秒后再无优化结果变化，则算法停止运行
        algorithmParam.jsonResultAsFile = false;//是否将优化结果输出为文件
        inputData.algorithmParam = algorithmParam;
        BinParameter bin;//原材料大板参数
        bin.material = JsonUtils::gbkToUtf8("加密多层贴白橡混拼");//将中文gbk编码转换为utf-8（必须使用utf-8编码）
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
        part1.texture = true;//有纹理要求，即不能旋转
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
        //输入数据的总结构
        NestInput nestInput;
        nestInput.data = inputData;
        nestInput.version = 1;
        std::string dataString = nestInput.toJsonString();//将输入数据转换为json字符串
        const char* data = dataString.c_str();;
        //创建PackingSdk对象
        PackingSdk* sdk = packingNew();
        //使用doOptimization进行排版优化(同步)
        char* result = doOptimization(sdk, data, true, &callBack);//送入数据并优化(输出html结果)
        SolverOutput output = JsonUtils::charToSolverOutput(result);//将优化结果转换为SolverOutput（方案输出结果）
        //如果不是将优化结果保存为文件，则优化结果是存放于output.jsonResult的
        if (algorithmParam.jsonResultAsFile == false && output.bestResultSheetCount > 0)
        {
            std::string resultString = JsonUtils::gbkToUtf8(output.jsonResult.c_str());//为了JsonUtils可以正常转换，需要将gbk编码转为utf-8
            NestOutput nestOutput = JsonUtils::jsonResultToNestOutput(resultString);//排版输出结果
            std::cout << "pattern count:" << nestOutput.data.patterns.size() << "\n";//打印
        }
        else {
            //algorithmParam.jsonResultAsFile为true，则排版输出结果是保存在json文件中，此时其文件路径存放于output.jsonResult中
            //可自行读取该json文件，读取内容后用JsonUtils::jsonResultToNestOutput转换为优化输出结果结构体NestOutput
        }
        std::string resultString = JsonUtils::utf8ToGbk(result);//为了正常显示打印，将utf-8编码转换为gbk
        std::cout << "doOptimization:" << resultString << "\n";//打印
        charFree(result);//销毁char*
        packingFree(sdk);//销毁PackingSdk对象
        return 0;
    }

    //第三个运行例子，带回调的运行例子（使用PackingSdk-packingStart进行优化）
    int thirdRun() {
        //设置日志级别
        setLogLevel(5);//5是只打印错误日志，如果要查看更多的调试信息日志，可设置为2
        //输入数据
        NestInputData inputData;//输入数据
        AlgorithmParameter algorithmParam;//算法参数
        algorithmParam.resultTimeOut = 10000;//当有优化结果后，等待10秒后再无优化结果变化，则算法停止运行
        algorithmParam.jsonResultAsFile = false;//是否将优化结果输出为文件
        inputData.algorithmParam = algorithmParam;
        BinParameter bin;//原材料大板参数
        bin.material = JsonUtils::gbkToUtf8("加密多层贴白橡混拼");//将中文gbk编码转换为utf-8（必须使用utf-8编码）
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
        part1.texture = true;//有纹理要求，即不能旋转
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
        //输入数据的总结构
        NestInput nestInput;
        nestInput.data = inputData;
        nestInput.version = 1;
        std::string dataString = nestInput.toJsonString();//将输入数据转换为json字符串
        const char* data = dataString.c_str();;
        //创建PackingSdk对象
        PackingSdk* sdk = packingNew();
        //使用packingStart进行排版优化(异步)
        packingStart(sdk, data, true, &callBackVoid);//送入数据并优化(输出html结果)
        //模拟等待结束
        while (packingIsRunning(sdk) == true)
        {
            printf("..........");
            Sleep(1000);
        }
        //销毁优化对象
        packingFree(sdk);//销毁PackingSdk对象
        return 0;
    }

    //第四个运行例子，带回调的运行例子（使用PackingSdk-doOptimization进行优化）
    int fourthRun() {
        //设置日志级别
        setLogLevel(5);//5是只打印错误日志，如果要查看更多的调试信息日志，可设置为2
        //输入数据
        NestInputData inputData;//输入数据
        AlgorithmParameter algorithmParam;//算法参数
        algorithmParam.resultTimeOut = 10000;//当有优化结果后，等待10秒后再无优化结果变化，则算法停止运行
        algorithmParam.jsonResultAsFile = false;//是否将优化结果输出为文件
        inputData.algorithmParam = algorithmParam;
        BinParameter bin;//原材料大板参数
        bin.material = JsonUtils::gbkToUtf8("加密多层贴白橡混拼");//将中文gbk编码转换为utf-8（必须使用utf-8编码）
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
        part1.texture = true;//有纹理要求，即不能旋转
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
        //输入数据的总结构
        NestInput nestInput;
        nestInput.data = inputData;
        nestInput.version = 1;
        std::string dataString = nestInput.toJsonString();//将输入数据转换为json字符串
        const char* data = dataString.c_str();;
        //创建PackingSdk对象
        PackingSdk* sdk = packingNew();
        //使用doOptimization进行排版优化(同步)
        char* result = doOptimization(sdk, data, true, &callBack);//送入数据并优化(输出html结果)
        SolverOutput output = JsonUtils::charToSolverOutput(result);//将优化结果转换为SolverOutput（方案输出结果）
        //如果不是将优化结果保存为文件，则优化结果是存放于output.jsonResult的
        if (algorithmParam.jsonResultAsFile == false && output.bestResultSheetCount > 0)
        {
            std::string resultString = JsonUtils::gbkToUtf8(output.jsonResult.c_str());//为了JsonUtils可以正常转换，需要将gbk编码转为utf-8
            NestOutput nestOutput = JsonUtils::jsonResultToNestOutput(resultString);//排版输出结果
            std::cout << "pattern count:" << nestOutput.data.patterns.size() << "\n";//打印
        }
        else {
            //algorithmParam.jsonResultAsFile为true，则排版输出结果是保存在json文件中，此时其文件路径存放于output.jsonResult中
            //可自行读取该json文件，读取内容后用JsonUtils::jsonResultToNestOutput转换为优化输出结果结构体NestOutput
        }
        std::string resultString = JsonUtils::utf8ToGbk(result);//为了正常显示打印，将utf-8编码转换为gbk
        std::cout << "doOptimization:" << resultString << "\n";//打印
        charFree(result);//销毁char*
        packingFree(sdk);//销毁PackingSdk对象
        return 0;
    }

}