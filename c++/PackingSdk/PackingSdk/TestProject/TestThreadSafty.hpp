#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>

#include "PackingSdk.h"

// KNestWrapperDll DLL函数示例
typedef bool (*IsSuperDogValidFunc)();

// DLL句柄
HMODULE hDll = nullptr;
IsSuperDogValidFunc IsSuperDogValid = nullptr;

// 加载DLL函数
bool LoadKNestWrapperSuperDogDll() {
    hDll = LoadLibrary(L"KNestWrapper.dll");
    if (hDll == nullptr) {
        std::cerr << "Failed to load KNestWrapper.dll" << std::endl;
        return false;
    }

    IsSuperDogValid = (IsSuperDogValidFunc)GetProcAddress(hDll, "IsSuperDogValid");
    if (IsSuperDogValid == nullptr) {
        std::cerr << "Failed to get IsSuperDogValid function" << std::endl;
        FreeLibrary(hDll);
        return false;
    }

    return true;
}

// 一些安全的DLL函数示例
bool safeWinApiCall() {
    return IsDebuggerPresent(); // Windows API 函数，天然线程安全
}

bool safeStaticCall() {
    static const bool result = true; // 只读静态变量，线程安全
    return result;
}

bool myIsDogValid()
{
    return true;
}

// 测试参数
const int NUM_THREADS = 10;
const int ITERATIONS_PER_THREAD = 1000;
std::atomic<int> successCount;
std::atomic<int> failureCount;

// 线程测试函数
void testThreadSafety(bool bUsePackingDll, int threadId)
{
    for (int i = 0; i < ITERATIONS_PER_THREAD; i++) {
        try {
            bool result = false;

            if (bUsePackingDll)
            {
                result = isDogValid();
            }
            else
            {
                //result = safeWinApiCall();
                //result = safeStaticCall();

                if (IsSuperDogValid)
                    result = IsSuperDogValid();// KNestWrapperDll 加载的函数
                else
                    result = safeWinApiCall(); // Windows API 函数，天然线程安全

                //result = myIsDogValid();
            }

            successCount++;

            // 随机增加一些延迟来增加线程切换的机会
            if (i % 100 == 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }

            std::cout << "Thread " << threadId << " iteration " << i
                << " result: " << (result ? "true" : "false") << std::endl;
        }
        catch (...) {
            failureCount++;
            std::cerr << "Thread " << threadId << " caught exception in iteration "
                << i << std::endl;
        }
    }
}

int TestThreadSafty(bool bUsePackingDll)
{
    //加载 KNestWrapperDll
    LoadKNestWrapperSuperDogDll();

    std::cout << "=== === === === Thread Safety Test Started === === === === " << std::endl;
    // 创建并启动多个测试线程
    std::vector<std::thread> threads;
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back(&testThreadSafety, bUsePackingDll, i);
    }

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // 输出测试结果
    std::cout << "\nThread Safety Test Results:" << std::endl;
    std::cout << "Total threads: " << NUM_THREADS << std::endl;
    std::cout << "Iterations per thread: " << ITERATIONS_PER_THREAD << std::endl;
    std::cout << "Total iterations: " << NUM_THREADS * ITERATIONS_PER_THREAD << std::endl;
    std::cout << "Successful calls: " << successCount << std::endl;
    std::cout << "Failed calls: " << failureCount << std::endl;
    std::cout << "Total time: " << duration.count() << "ms" << std::endl;

    std::cout << "===================== Thread Safety Test Finished ===================== " << std::endl;
    return 0;
}
