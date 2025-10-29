#pragma once
#ifdef KNPACKING_EXPORTS
#define KNPACKING __declspec(dllexport)
#else
#define KNPACKING __declspec(dllimport)
#endif

#ifdef __cplusplus  
#ifdef _WIN32
// ���� STL ������ DLL �߽�ľ���
#pragma warning(push)
#pragma warning(disable: 4251)
#pragma warning(disable: 4275)
#endif
#include <string>
namespace knest {

    //�Ż�״̬
    enum KNPACKING SolverState {
        Ready = 0,//0��׼����
        Running = 1,//1������
        RunningForBetter = 2,//2�����У������н�������ڼ�����Ž��
        Ended = 3,//3����
    };
    //�Ż�����ԭ��
    enum KNPACKING SolverEndedReason {
        None = 0,//0��
        Normal = 1,//1��������
        WrongParam = 2,//2�������ݻ�������������Ϸ�����ֹ
        DogError = 3,//3û���ҵ�Ӳ��������������Ӳ��������
        ReachCondition = 4,//4�ﵽ������������������������ȶ���ֹ
        TimeOut = 5,//5�ﵽ�û����õ����ȴ�ʱ��(�õ��Ż�����󣬵ȴ��೤ʱ���������Ż���������㷨ֹͣ����)����ֹ
        UserCancel = 6,//6�û��ж�
        CallBackToStop = 7,//7�ص���������true�Ӷ���ֹ
        ExceptionExit = 8,//8�쳣����
    };

    //�Ż��ص�����ṹ��--�ص��������ص��ַ�����Ӧ�Ľṹ��
    struct KNPACKING SolverOutput {
        SolverState solverState;//�㷨��ǰ״̬
        SolverEndedReason solverEndedReason;//�㷨����ԭ��
        std::string solverEndedMsg;//�㷨����ԭ�������Ϣ
        unsigned long currentPriority;//���ּ�������ȼ�
        unsigned long numOfIteration;//�����ܴ���
        unsigned long long elapsedTime;//�㷨���ĵ���ʱ��(��λ����)

        std::string firstMaterial;  //��һ��BinParameter�� [����] (���ڽ�����ʾ)
        double firstLength;  //��һ��BinParameter�� [����] (���ڽ�����ʾ)
        double firstWidth;  //��һ��BinParameter�� [���] (���ڽ�����ʾ)
        double firstThickness;  //��һ��BinParameter�� [���] (���ڽ�����ʾ)

        double calUsage;//���ּ�����������ʣ�����0.95��ʾ95%��������
        double calProgress;//���ּ���Ľ��ȣ�����95��ʾ95%�Ľ���
        unsigned int calTargetSheetCount;//���ּ���ĵ�Ŀ�����������統ǰ���Ž���Ĵ������8����ͨ�����ּ����Ŀ��������8-1=7
        unsigned long optimumIndex;//��ֵ���ڱ�ǵڼ����Ż�����б�ÿ���Ż�����б�ĸ�ֵ�����ϴβ�ͬ��
        unsigned long long bestFitness;//Ŀǰ��õ���Ӧ��ֵ
        long long resultTimeOut = -1;//��ʱʱ�䣨�������� -���ڶ�������ϴ��Ż������ʱ��������Ϊ-1ʱ��ʾ����ʱ�����Ż����û�仯���ҳ�����ʱ����ʱ���Ż��Զ�ֹͣ
        unsigned long long startTimeForTimeOut;//��ʱ��ʼʱ�䣨��������
        unsigned long long timeElapsedSinceLastResult; //��¼�� startTimeForTimeOut ��ʼ�Ѿ�������ʱ�䣬�����ʱ�䳬�� resultTimeOut ʱ���Զ�ֹͣ�㷨
        unsigned int bestResultSheetCount;//��ǰ�Ѽ�����ɵ��Ű淽���н�����ŵĴ����

        unsigned int partCountInBestResult; //��ǰ�Ѽ�����ɵ��Ű淽�������Ž���е�С������

        double bestResultUsage;//��ǰ�Ѽ�����ɵ��Ű淽���н�����ŵ�������
        std::string jsonResult;//�Ż����json�ַ�������json�ļ�·����ֻ�м������ս�����SolverStateΪ3����ʱ����ֶβŻ���ֵ
        bool isMultiPriorityMode = false;//true��ʾ��ǰ�����ڶ����ȼ���ģʽ�£�false��ʾ�Ƕ����ȼ�ģʽ
        long long resultNumOfIteration = -1;//�������Ƶ����� -���ڶ�������ϴ��Ż�����ĵ�����������Ϊ-1ʱ��ʾ�����������Ż����û�仯���Ҿ����ϴε���������������ֵʱ���Ż��Զ�ֹͣ
        unsigned long long numOfIterationSinceLastResult; //��¼�ϴ��б仯���Ż�����ĵ����ܴ�������numOfIteration��ȥ���ֵ���� resultNumOfIteration ʱ���Զ�ֹͣ�㷨
    };
}

extern "C" {
#endif
    //helloWorld
    KNPACKING void helloWorld();
    //����char������0��ʾ���ٳɹ�
    KNPACKING int charFree(char* input);
    KNPACKING void setLogLevel(int level);//����������־���� Trace = 1,Debug = 2,Info = 3,Warn = 4,Error = 5,Fatal = 6,Off = 7
    //��ȡ���ܹ�code�����۵�ǰ�õ���ʲô���ܹ��������Ҳ������ܹ�ʱ���ؿ��ַ�����
    KNPACKING char* getDogCode();
    //��ȡ���ܹ�code�����۵�ǰ�õ���ʲô���ܹ��������ش����� 0 ��ʾ�޴��󣬷�0��ʾ�д���
    KNPACKING int getDogCode2(char** dogCode);
    //���ݼ��ܹ����ͻ�ȡ���ܹ�code�����Ҳ������ܹ�ʱ���ؿ��ַ��������߼��ܹ��᷵��dogCode,��ʹ��ǰδע�ᡣ0��ʾδ����ļ��ܹ� 1��ʾUSB���ܹ� 2��ʾ���ߵļ��ܹ�
    KNPACKING char* getDogCodeByDogType(int dogType);
    //���ݼ��ܹ����ͻ�ȡ���ܹ�code�����ش����� 0 ��ʾ�޴��󣬷�0��ʾ�д���dogType��0δ����ļ��ܹ� 1USB���ܹ� 2���ߵļ��ܹ�
    KNPACKING int getDogCodeByDogType2(int dogType, char** dogCode);
    //���ܹ��Ƿ����
    KNPACKING bool isDogValid();
    //��ȡ���ܹ����� ���ش����� 0 ��ʾ�޴��󣬷�0��ʾ�д���
    KNPACKING int readDog(unsigned int offset, unsigned int length, void* buffer);
    //д����ܹ����� ���ش����� 0 ��ʾ�޴��󣬷�0��ʾ�д���
    KNPACKING int writeDog(unsigned int offset, unsigned int length, const void* buffer);
    //�Ƿ�֧�ֻ�ȡʱ�䣬���� 0��false����ʾ��֧�֣�1 ��true����ʾ֧��
    KNPACKING int supportGetDogTime();
    //��ȡʱ�䣨�� 1970 �� 1 �� 1 �տ�ʼ������������,���ش����� 0 ��ʾ�޴��󣬷�0��ʾ�д���
    KNPACKING int getDogTime(long long* time);
    //��ȡ���ܹ�����  0��ʾδ���� 1��ʾUSB���ܹ� 2��ʾ���ߵļ��ܹ�
    KNPACKING int getDogType();
    //��ȡ���ܹ��ڵ��ײ����� 0��ʾδ������ײͣ�1��ʾ��׼�汾�ײ� 2��ʾ�߼��汾�ײ�
    KNPACKING int getDogSuite();
    //ע��������Ȩ�����ش����� 0 ��ʾ�޴��󣬷�0��ʾ�д�������registerCodeΪע���룬registerParamsΪ��Ҫ���浽��Ȩ�ڵĲ����б���ֵ��ת��Ϊjson�ַ�����
    KNPACKING int registerOfflineLicense(const char* registerCode, const char* registerParams);
    //ȡ��������Ȩ�����ش����� 0 ��ʾ�޴��󣬷�0��ʾ�д���
    KNPACKING int cancelOfflineLicense();
    //�Ƿ�ǿ��ȡ��������Ȩ�����ش����� 0 ��ʾ�޴��󣬷�0��ʾ�д���cancelOfflineLicenseʵ�ʵ��õ���cancelOfflineLicenseForce(false)
    KNPACKING int cancelOfflineLicenseForce(bool isForceDelete);
    //��ȡ��ǰ������Ȩ��ע����
    KNPACKING char* getRegisterCode();
    //����key��ȡ���߼��ܹ��Ĳ�����ֵ�����ش�����0��ʾ�޴��󣬷�0��ʾ�д���
    KNPACKING int readOfflineDog(const char* key, void* buffer);
    //����ֵ��д�뵽���߼��ܹ���
    KNPACKING int writeOfflineDog(const char* key, const char* value);
    //��ȡ��Ȩʣ�����������߼��ܹ���days��ֵΪ0��ʾ�Ѿ����ڣ�-1��ʾû��ʱ�����ƣ�����������ʾʣ�������,���ش����룬0��ʾ�޴���, ��0��ʾ�д���
    KNPACKING int getOfflineDogRestDays(int* days);

    //�������صĽӿ�
    //�ڷ������˽�������ǰд�뵽ע�����Ӧ�Ĳ����У����ش�����0��ʾ�޴���(д��ɹ�)����0��ʾ�д���(д��ʧ��)��isClearBeforeWrite���Ƿ���д��ǰ���ԭ�е���������
    KNPACKING int writeParameterByRegisterCode(const char* registerCode, const char* key, const char* value, bool isClearBeforeWrite = false);
    //�ӷ������ж�ȡָ��ע����Ĳ�����ֵ�����ش�����0��ʾ�޴��󣬷�0��ʾ�д���
    KNPACKING int readParameterByRegisterCode(const char* registerCode, const char* key, void* buffer);
    //���������ȡָ��ע�����״̬  ���ش�����0��ʾ�޴��󣬷�0��ʾ�д���  status:0 = [δ����] 1 = [������] 2 = [δʹ��] 3 = [��ʹ��] 4=[������ע��]
    KNPACKING int readRegisterCodeStatus(const char* registerCode, int* status);
    //����ע��������Ȩ(����ע��-�踽��ǰһ�������Ļ�����dogCode)�����ش����� 0��ʾ�޴��󣬷�0��ʾ�д�������registerCodeΪע���룬lastDogCodeΪ�ϴ�ע������ļ��ܹ������룬registerParamsΪ��Ҫ���浽��Ȩ�ڵĲ����б���ֵ��ת��Ϊjson�ַ�����
    KNPACKING int registerOfflineLicenseWithLastMachineCode(const char* registerCode, const char* lastDogCode, const char* registerParams);
    
    //PackingSdk�ṹ��
    typedef struct {
    } PackingSdk;
    //����PackingSdk��ʵ��
    KNPACKING PackingSdk* packingNew();
    //�������ݣ�����PackingSdkʵ�����Ű����,�����ûص�������ͬ����
    //inputJson ��������
    //isGenerateHtml�Ƿ�����html���,����0��ʾ��Ҫ����html���
    //callback �ص�����������֪ͨ���ȣ�����trueʱ��ʾֹͣ�Ż���Ĭ���Ƿ���false
    KNPACKING char* doOptimization(PackingSdk* sdk, const char* inputJson, bool isGenerateHtml = false, bool(*callback)(PackingSdk* sdk, const char* data) = nullptr);

    //�������ݣ�����PackingSdkʵ�����Ű����,�����ûص��������첽��
    //inputJson:��������
    //isGenerateHtml�Ƿ�����html���,����0��ʾ��Ҫ����html���
    //callback�ص�����
    KNPACKING void packingStart(PackingSdk* sdk, const char* inputJson, bool isGenerateHtml = false, void(*callback)(PackingSdk* sdk, const char* data) = nullptr);
    //ֹͣPackingSdkʵ�����Ű��Ż�����
    KNPACKING void packingStop(PackingSdk* sdk);
    //����PackingSdkʵ��
    KNPACKING void packingFree(PackingSdk* sdk);
    //�鿴PackingSdkʵ�����Ű�����Ƿ���ִ����
    KNPACKING bool packingIsRunning(PackingSdk* sdk);

#ifdef __cplusplus
}
#endif
