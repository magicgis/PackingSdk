#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>

#include "PackingSdk.h"

// KNestWrapperDll DLL����ʾ��
typedef bool (*IsSuperDogValidFunc)();

// DLL���
HMODULE hDll = nullptr;
IsSuperDogValidFunc IsSuperDogValid = nullptr;

// ����DLL����
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

// һЩ��ȫ��DLL����ʾ��
bool safeWinApiCall() {
    return IsDebuggerPresent(); // Windows API ��������Ȼ�̰߳�ȫ
}

bool safeStaticCall() {
    static const bool result = true; // ֻ����̬�������̰߳�ȫ
    return result;
}

bool myIsDogValid()
{
    return true;
}

// ���Բ���
const int NUM_THREADS = 10;
const int ITERATIONS_PER_THREAD = 1000;
std::atomic<int> successCount;
std::atomic<int> failureCount;

// �̲߳��Ժ���
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
                    result = IsSuperDogValid();// KNestWrapperDll ���صĺ���
                else
                    result = safeWinApiCall(); // Windows API ��������Ȼ�̰߳�ȫ

                //result = myIsDogValid();
            }

            successCount++;

            // �������һЩ�ӳ��������߳��л��Ļ���
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
    //���� KNestWrapperDll
    LoadKNestWrapperSuperDogDll();

    std::cout << "=== === === === Thread Safety Test Started === === === === " << std::endl;
    // ������������������߳�
    std::vector<std::thread> threads;
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back(&testThreadSafety, bUsePackingDll, i);
    }

    // �ȴ������߳����
    for (auto& thread : threads) {
        thread.join();
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // ������Խ��
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
