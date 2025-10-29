#include <gtest/gtest.h>
#include "PackingSdkAll.h"
#include <windows.h>

namespace knest {
    //进度回调函数
    bool testCallBack(PackingSdk* sdk, const char* data)
    {
        SolverOutput output = JsonUtils::charToSolverOutput(data);
        //打印查看
        std::cout << "========testCallBack==========" << "\n";
        //std::cout << "output.jsonResult:" << output.jsonResult << "\n";
        std::cout << "output.calUsage:" << output.calUsage << "\n";
        std::cout << "output.bestResultUsage:" << output.bestResultUsage << "\n";
        //std::cout << "output.partCountInBestResult:" << output.partCountInBestResult << "\n";
        //std::cout << "output.timeElapsedSinceLastResult:" << output.timeElapsedSinceLastResult << "\n";
        std::cout << "output.isMultiPriorityMode:" << output.isMultiPriorityMode << "\n";
        //返回false表示不要停止优化计算
        return false;
    }
    //进度回调函数
    void testCallBackVoid(PackingSdk* sdk, const char* data)
    {
        testCallBack(sdk, data);
    }
    //使用doOptimization进行优化
    TEST(Main, doOptimization) {
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
        char* result = doOptimization(sdk, data, true, &testCallBack);//送入数据并优化(输出html结果)
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
        EXPECT_EQ(output.bestResultSheetCount, 3);
    }
    //使用packingStart进行优化
    TEST(Main, packingStart) {
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
        //启动优化(异步)
        packingStart(sdk, data, true, &testCallBackVoid);//启动优化，并设置回调
        //模拟等待结束
        while (packingIsRunning(sdk) == true)
        {
            printf("..........");
            Sleep(1000);
        }
        //此时优化已结束
        EXPECT_EQ(packingIsRunning(sdk), false);
        //销毁优化对象
        packingFree(sdk);//销毁PackingSdk对象
    }
    //使用样例数据进行优化-同步的方式
    TEST(Main, doOptimizationByString) {
        //data为输入数据
        std::string json_str = R"({"version":"1","data":{"param":{"material":"加密多层贴白橡混拼","thickness":9.0,"trimL":4.0,"trimR":4.0,"trimT":4.0,"trimB":4.0,"spacing":8.0,"binLength":2440.0,"binWidth":1220.0,"binCount":1000000,"loopCount":2,"baseCorner":1,"nestType":1,"enablePriority":false,"higherPriorityPlacedFront":true,"resultTimeOut":6000},"parts":[{"code":"1189598","length":308.4,"width":138.39999999999999,"quantity":120,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":308.4,"y":0.0},{"x":308.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189599","length":308.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":308.4,"y":0.0},{"x":308.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189600","length":322.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":322.4,"y":0.0},{"x":322.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189602","length":322.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":322.4,"y":0.0},{"x":322.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//创建PackingSdk对象
            //执行优化(同步)
            char* result = doOptimization(sdk, data, true, nullptr);//送入数据并优化
            SolverOutput output = JsonUtils::charToSolverOutput(result);
            std::string resultString = JsonUtils::utf8ToGbk(result);//为了正常显示打印，将utf-8编码转为gbk
            std::cout << "do_optimization:" << resultString << "\n";//打印
            charFree(result);//销毁char*
            //预期优化后的大板数是3
            EXPECT_EQ(output.bestResultSheetCount, 3);
        }
    }
    //使用样例数据进行优化-异步的方式
    TEST(Main, packingStartByString) {
        //data为输入数据，优化的调用分为两种方式，分别为方式一和方式二，如下所示：
        std::string json_str = R"({"version":"1","data":{"param":{"material":"加密多层贴白橡混拼","thickness":9.0,"trimL":4.0,"trimR":4.0,"trimT":4.0,"trimB":4.0,"spacing":8.0,"binLength":2440.0,"binWidth":1220.0,"binCount":1000000,"loopCount":2,"baseCorner":1,"nestType":1,"enablePriority":false,"higherPriorityPlacedFront":true,"resultTimeOut":6000},"parts":[{"code":"1189598","length":308.4,"width":138.39999999999999,"quantity":120,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":308.4,"y":0.0},{"x":308.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189599","length":308.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":308.4,"y":0.0},{"x":308.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189600","length":322.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":322.4,"y":0.0},{"x":322.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]},{"code":"1189602","length":322.4,"width":138.39999999999999,"quantity":1,"texture":true,"outer":[{"x":0.0,"y":0.0},{"x":322.4,"y":0.0},{"x":322.4,"y":138.39999999999999},{"x":0.0,"y":138.39999999999999},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//创建PackingSdk对象
            //启动优化(异步)
            packingStart(sdk, data, true, &testCallBackVoid);//启动优化，并设置回调
            //模拟等待结束
            while (packingIsRunning(sdk) == true)
            {
                printf("..........");
                Sleep(1000);
            }
            //此时优化已结束
            EXPECT_EQ(packingIsRunning(sdk), false);
            //销毁优化对象
            packingFree(sdk);//销毁PackingSdk对象
        }
    }
    //使用样例数据进行优化-测试数据的版本号为数字
    TEST(Main, packingStartVersionIsNum) {
        //版本号为数字，而内部为字符串，从而解析错误的情况
        std::string json_str = R"({"version":2,"data":{"algorithmParam":{"nestType":1,"baseCorner":1,"enablePriority":false,"priorityType":1,"higherPriorityPlacedFront":true,"resultTimeOut":6000,"jsonResultAsFile":false,"binValueType":1},"bins":[{"code":"default","material":"default","thickness":18.0,"trimL":2.0,"trimR":2.0,"trimT":2.0,"trimB":2.0,"spacing":12.2,"binLength":2800.0,"binWidth":2070.0,"binCount":1000000,"binValue":0.0}],"parts":[{"code":"1734074757","length":600.0,"width":500.0,"quantity":30,"texture":false,"priority":100,"outer":[{"x":0.0,"y":0.0},{"x":600.0,"y":0.0},{"x":600.0,"y":500.0},{"x":0.0,"y":500.0},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//创建PackingSdk对象
            std::cout << "packingNew:" << sdk;
            //方式二(异步)
            //启动优化
            packingStart(sdk, data, true, &testCallBackVoid);//启动优化，并设置回调
            //模拟等待结束
            while (packingIsRunning(sdk) == true)
            {
                printf("..........");
                Sleep(1000);
            }
            //此时优化已结束
            EXPECT_EQ(packingIsRunning(sdk), false);
            //销毁优化对象
            packingFree(sdk);//销毁PackingSdk对象
        }
    }
    //使用样例数据进行优化-测试数据的binValueType等为空
    TEST(Main, packingStartBinValueTypeIsNull) {
        //该json对应的输出中binValueType、priorityType为null，应该需要为默认值
        std::string json_str = R"({"version":"1","data":{"param":{"material":"default","thickness":18.0,"trimL":2.0,"trimR":2.0,"trimT":2.0,"trimB":2.0,"spacing":12.2,"binLength":2800.0,"binWidth":2070.0,"binCount":1000000,"loopCount":2,"baseCorner":1,"nestType":1,"enablePriority":false,"higherPriorityPlacedFront":true,"useNest2ToInitResult":false,"resultTimeOut":6000,"littleBoardLength":230.0,"littleBoardArea":90000.0},"parts":[{"code":"1734077140","length":600.0,"width":500.0,"quantity":30,"texture":false,"priority":100,"outer":[{"x":0.0,"y":0.0},{"x":600.0,"y":0.0},{"x":600.0,"y":500.0},{"x":0.0,"y":500.0},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//创建PackingSdk对象
            std::cout << "packingNew:" << sdk;
            //方式二(异步)
            //启动优化
            packingStart(sdk, data, true, &testCallBackVoid);//启动优化，并设置回调
            //模拟等待结束
            while (packingIsRunning(sdk) == true)
            {
                printf("..........");
                Sleep(1000);
            }
            //此时优化已结束
            EXPECT_EQ(packingIsRunning(sdk), false);
            //销毁优化对象
            packingFree(sdk);//销毁PackingSdk对象
        }
    }
    //使用样例数据进行优化-板间的距离问题
    TEST(Main, packingStartBoardGapProblem) {
        //板间的距离问题样例数据
        std::string json_str = R"({"version":1,"data":{"param":{"material":"default","thickness":18.0,"trimL":20.0,"trimR":20.0,"trimT":20.0,"trimB":20.0,"spacing":10.0,"binLength":2800.0,"binWidth":2070.0,"binCount":1000000,"loopCount":2,"baseCorner":4,"nestType":3,"enablePriority":false,"higherPriorityPlacedFront":true,"useNest2ToInitResult":false,"resultTimeOut":6000,"littleBoardLength":200.0,"littleBoardArea":70000.0,"enableExecCbOnTimer":true,"execCbOnTimerInterval":1},"parts":[{"code":"1734342173","length":600.0,"width":500.0,"quantity":30,"texture":false,"priority":0,"outer":[{"x":0.0,"y":0.0},{"x":600.0,"y":0.0},{"x":600.0,"y":500.0},{"x":0.0,"y":500.0},{"x":0.0,"y":0.0}]}]}})";
        const char* data = json_str.c_str();
        if (data) {
            PackingSdk* sdk = packingNew();//创建PackingSdk对象
            std::cout << "packingNew:" << sdk;
            //方式二(异步)
            //启动优化
            packingStart(sdk, data, true, &testCallBackVoid);//启动优化，并设置回调
            //模拟等待结束
            while (packingIsRunning(sdk) == true)
            {
                printf("..........");
                Sleep(1000);
            }
            //此时优化已结束
            EXPECT_EQ(packingIsRunning(sdk), false);
            //销毁优化对象
            packingFree(sdk);//销毁PackingSdk对象
        }
    }
}