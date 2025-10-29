#pragma once
// ��ӵ����궨��
#ifdef KNPACKING_EXPORTS
#define KNPACKING __declspec(dllexport)
#else
#define KNPACKING __declspec(dllimport)
#endif

#include <string>
#include <exception>

namespace knest {

    // ���д�����
    enum class KNPACKING PackingError {
        // ͨ�õĴ�����
        Succeed = 0,                // û�д��󣨳ɹ���
        NoDogDetected = 1,          // û�м�⵽���ܹ�
        ParameterError = 2,         // ����������������Ϊ�գ����ݴ�СΪ0�Ȳ��Ϸ��Ĳ���
        Undefine = 3,               // ��ǰ���ܹ��޴˺�����ʵ��
        WrongMachineCode = 4,       // ��ǰ������Ȩ�Ļ���������Ȩ��ƥ��
        ExpiredError = 5,           // ��Ȩ�ѹ���
        SignError = 6,              // ��Ȩǩ������
        UnknowExceptionError = 7,   // δ֪�쳣����

        // ������ش���
        ReadError = 20,//��ȡ����ʧ��
        ExceptionOccurWhenReadError = 50,  // �����쳣���¶�ȡ����ʧ��

        // д����ش���
        CapacityExceeds = 60,       // д������ݳ����������
        WriteError = 61,            // д��ʧ��,����ĳЩ������д��ʧ��
        ExceptionOccurWhenWriteError = 62,  // �����쳣����д��ʧ��

        // ��ȡ����ʱ�����
        TimeInValidError = 70,      // ���ܹ���֧�ֻ�ȡʱ��

        // ע��������Ȩ��ش���
        LicenseInValidError = 80,        // ��Ȩ������
        CodeIsUsedError = 81,            // ע�����ѱ�ʹ��
        NotMatchMachineCodeError = 82,   // ������ע��ʱ���ϴεĻ����벻ƥ��
        GenerateFailedError = 83,        // ������Ȩʧ��
        CodeIsNotExistError = 84,        // ע���벻����
        ExceptionOccurError = 85,        // �����쳣����ע��ʧ��
        SignDataError = 86,              // ����˷��ص����ݵ�ǩ������ȷ�����������ѱ��ٳ�
        OutofServiceError = 87,          // �޷�����ע���������δ���ӻ��ߺ�̨�޷���
        JsonConvertError = 88,           // ע�����ת��Ϊjsonʱ��������
		ClientSignDataError = 89,        // �ͻ��˷��͵�ǩ�����ݲ�ƥ��
        AlreadyRegistered = 90,          //��ǰ������ע�����Ȩ
        UnRegisterFailedWithUnMatch = 91,//��Ȩ��Ϣ���̨���ݲ�ƥ�䵼��ȡ����Ȩʧ��
        UnRegisterFailedWithException = 92,//�����쳣����ȡ����Ȩʧ��
        LackOfTimestamp = 93,            //ȱ��ʱ�������
        TimestampIsNotNum = 94,          //ʱ�������Ϊ������
        TimestampIsTimeout = 95,         //ʱ���������ֵ�ѳ�ʱ
        LackOfSign = 96,                //ȱ��ǩ������sign

        // ȡ��/ɾ��������Ȩ��ش���
        UnknowLicenseType = 100,         // δ֪����Ȩ����
        DeleteFailedError = 101,         // ɾ��ʧ��

        // ����key��ȡ������Ȩ���ܹ��Ĵ洢��ش���
        LicenseIsInValid = 110,          // ��Ȩ������
        DataPointerIsNull = 111,         // ָ�������ָ��Ϊ��
        DecodeError = 112,               // �ַ����ܴ���(utf8->gbk)

        // ����key��������Ȩд��ֵ����
        WriteOfflineLicenseFailed = 120,  // ��������Ȩд��ֵʱ����������д��ʧ��

        // ���������ǰд���������
        LackOfParameterError = 130,      // ȱ�ٱ�Ҫ�Ĳ���
        ParameterIsNotModifiableError = 131, // �ǳ�ʼ״̬����ֹ��������
        WriteParameterFailed = 132,      // д����������з���������д��ʧ��
        ParameterIsNotModifiableWhenReRegisterError = 133,//������ע��״̬����ֹ��������

        // �ӷ�������ȡ��ǰд��Ĳ�������
        ValuePointerIsNullError = 140,   // ֵ��ָ��Ϊ��
        ReadParameterFailed = 141,        // ��ȡ��ǰ���������з���������д��ʧ��


        Unknown = 9999  //δ֪������
    };


    // ����ת��Ϊ PackingError �ĺ���
    inline PackingError toPackingError(int errorCode) {
        switch (errorCode) {
            // ͨ�õĴ�����
        case 0: return PackingError::Succeed;
        case 1: return PackingError::NoDogDetected;
        case 2: return PackingError::ParameterError;
        case 3: return PackingError::Undefine;
        case 4: return PackingError::WrongMachineCode;
        case 5: return PackingError::ExpiredError;
        case 6: return PackingError::SignError;
        case 7: return PackingError::UnknowExceptionError;

            // ������ش���
        case 50: return PackingError::ExceptionOccurWhenReadError;

            // д����ش���
        case 60: return PackingError::CapacityExceeds;
        case 61: return PackingError::WriteError;
        case 62: return PackingError::ExceptionOccurWhenWriteError;

            // ��ȡ����ʱ�����
        case 70: return PackingError::TimeInValidError;

            // ע��������Ȩ��ش���
        case 80: return PackingError::LicenseInValidError;
        case 81: return PackingError::CodeIsUsedError;
        case 82: return PackingError::NotMatchMachineCodeError;
        case 83: return PackingError::GenerateFailedError;
        case 84: return PackingError::CodeIsNotExistError;
        case 85: return PackingError::ExceptionOccurError;
        case 86: return PackingError::SignDataError;
        case 87: return PackingError::OutofServiceError;
        case 88: return PackingError::JsonConvertError;
		case 89: return PackingError::ClientSignDataError;
        case 90: return PackingError::AlreadyRegistered;
        case 91: return PackingError::UnRegisterFailedWithUnMatch;
        case 92: return PackingError::UnRegisterFailedWithException;
        case 93: return PackingError::LackOfTimestamp;
        case 94: return PackingError::TimestampIsNotNum;
        case 95: return PackingError::TimestampIsTimeout;
        case 96: return PackingError::LackOfSign;

            // ȡ��/ɾ��������Ȩ��ش���
        case 100: return PackingError::UnknowLicenseType;
        case 101: return PackingError::DeleteFailedError;

            // ����key��ȡ������Ȩ���ܹ��Ĵ洢��ش���
        case 110: return PackingError::LicenseIsInValid;
        case 111: return PackingError::DataPointerIsNull;
        case 112: return PackingError::DecodeError;

            // ����key��������Ȩд��ֵ����
        case 120: return PackingError::WriteOfflineLicenseFailed;

            // ���������ǰд���������
        case 130: return PackingError::LackOfParameterError;
        case 131: return PackingError::ParameterIsNotModifiableError;
        case 132: return PackingError::WriteParameterFailed;

            // �ӷ�������ȡ��ǰд��Ĳ�������
        case 140: return PackingError::ValuePointerIsNullError;
        case 141: return PackingError::ReadParameterFailed;

            // ���û��ƥ��Ĵ����룬���� Unknown
        default: return PackingError::Unknown;
        }
    }
    // PackingError ת��Ϊ���ֵĺ���
    inline int fromPackingError(PackingError errorCode) {
        return static_cast<int>(errorCode);
    }
    //�Ӵ������ȡ��Ӧ����
    inline const char* getPackingErrorDescription(PackingError errorCode) {
        switch (errorCode) {
        case PackingError::Succeed: return "û�д��󣨳ɹ���";
        case PackingError::NoDogDetected: return "û�м�⵽���ܹ�";
        case PackingError::ParameterError: return "����������������Ϊ�գ����ݴ�СΪ0�Ȳ��Ϸ��Ĳ���";
        case PackingError::Undefine: return "��ǰ���ܹ��޴˺�����ʵ��";
        case PackingError::WrongMachineCode: return "��ǰ������Ȩ�Ļ���������Ȩ��ƥ��";
        case PackingError::ExpiredError: return "��Ȩ�ѹ���";
        case PackingError::SignError: return "��Ȩǩ������";
        case PackingError::UnknowExceptionError: return "δ֪�쳣����";
        case PackingError::ExceptionOccurWhenReadError: return "�����쳣���¶�ȡʧ��";
        case PackingError::CapacityExceeds: return "д������ݳ����������";
        case PackingError::WriteError: return "д��ʧ��,����ĳЩ������д��ʧ��";
        case PackingError::ExceptionOccurWhenWriteError: return "�����쳣����д��ʧ��";
        case PackingError::TimeInValidError: return "���ܹ���֧�ֻ�ȡʱ��";
        case PackingError::LicenseInValidError: return "��Ȩ������";
        case PackingError::CodeIsUsedError: return "ע�����ѱ�ʹ��";
        case PackingError::NotMatchMachineCodeError: return "������ע��ʱ���ϴεĻ����벻ƥ��";
        case PackingError::GenerateFailedError: return "������Ȩʧ��";
        case PackingError::CodeIsNotExistError: return "ע���벻����";
        case PackingError::ExceptionOccurError: return "�����쳣����ע��ʧ��";
        case PackingError::SignDataError: return "����˷��ص����ݵ�ǩ������ȷ�����������ѱ��ٳ�";
        case PackingError::OutofServiceError: return "�޷�����ע���������δ���ӻ��ߺ�̨�޷���";
        case PackingError::JsonConvertError: return "ע�����ת��Ϊjsonʱ��������";
		case PackingError::ClientSignDataError: return "�ͻ��˷��͵�ǩ�����ݲ�ƥ��";
        case PackingError::AlreadyRegistered: return "��ǰ������ע�����Ȩ";
        case PackingError::UnRegisterFailedWithUnMatch: return "��Ȩ��Ϣ���̨���ݲ�ƥ�䵼��ȡ����Ȩʧ��";
        case PackingError::UnRegisterFailedWithException: return "�����쳣����ȡ����Ȩʧ��";
        case PackingError::LackOfTimestamp: return "ȱ��ʱ�������";
        case PackingError::TimestampIsNotNum: return "ʱ�������Ϊ������";
        case PackingError::TimestampIsTimeout: return "ʱ���������ֵ�ѳ�ʱ";
        case PackingError::LackOfSign: return "ȱ��ǩ������sign";

        case PackingError::UnknowLicenseType: return "δ֪����Ȩ����";
        case PackingError::DeleteFailedError: return "ɾ��ʧ��";
        case PackingError::LicenseIsInValid: return "��Ȩ������";
        case PackingError::DataPointerIsNull: return "ָ�������ָ��Ϊ��";
        case PackingError::DecodeError: return "�ַ����ܴ���(utf8->gbk)";
        case PackingError::WriteOfflineLicenseFailed: return "��������Ȩд��ֵʱ����������д��ʧ��";
        case PackingError::LackOfParameterError: return "ȱ�ٱ�Ҫ�Ĳ���";
        case PackingError::ParameterIsNotModifiableError: return "�ǳ�ʼ״̬����ֹ��������";
        case PackingError::WriteParameterFailed: return "д����������з���������д��ʧ��";
        case PackingError::ValuePointerIsNullError: return "ֵ��ָ��Ϊ��";
        case PackingError::ReadParameterFailed: return "��ȡ��ǰ���������з���������д��ʧ��";
        default: return "δ֪����";
        }
    }
    //�Ӵ��������ֻ�ȡ��Ӧ����
    inline const char* getPackingErrorDescriptionFromInt(int errorCode)
    {
        PackingError code = toPackingError(errorCode);
        return getPackingErrorDescription(code);
    }
    // �����Ҫ�׳��쳣������ʹ���Զ����쳣��
    class PackingErrorException : public std::runtime_error {
    public:
        PackingErrorException(PackingError code)
            : std::runtime_error(getPackingErrorDescription(code)), errorCode(code) {}
        PackingErrorException(int code)
            : std::runtime_error(getPackingErrorDescriptionFromInt(code)), errorCode(toPackingError(code)) {}

        PackingError getErrorCode() const { return errorCode; }
    private:
        PackingError errorCode;
    };

}