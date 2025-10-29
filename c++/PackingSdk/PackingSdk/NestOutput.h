#pragma once
// ��ӵ����궨��
#ifdef KNPACKING_EXPORTS
#define KNPACKING __declspec(dllexport)
#else
#define KNPACKING __declspec(dllimport)
#endif
#ifdef _WIN32
// ���� STL ������ DLL �߽�ľ���
#pragma warning(push)
#pragma warning(disable: 4251)
#pragma warning(disable: 4275)
#endif

#include "NestInput.h"

namespace knest {
    //���/С����İڷ���Ϣ
    struct KNPACKING NestPlacement{
        std::string code; //Ψһ����
        bool texture; //�Ƿ�������Ҫ��
        double angle; //��ת�Ƕ�
        double baseX; //����x
        double baseY; //����y
    };
    //�Ű�ͼ��
    struct KNPACKING NestPattern{
        uint64_t id; //ԭ���ϰ��/���id
        std::string code; //ԭ���ϰ��/���Ψһ����
        std::string material; //����
        double length; //�Ű�ͼ����
        double width; //�Ű�ͼ����
        double thickness; //�Ű�ͼ����
        std::vector<NestPlacement> wsPlacements; //���/С����Ű�λ��
        double area; // ���
        double fillRate; // �����
    };
    //��ʹ�����/С�����Ϣ
    struct KNPACKING NestPartUsedInfo {
        std::string code; //Ψһ����
        double length; //���/С�����
        double width; //���/С�����
        uint64_t startQuantity; //��ʼ����(���/С���������)
        uint64_t usedQuantity; //��ʹ������
        uint64_t restQuantity; //ʣ������
    };
    //
    struct KNPACKING BinUsedInfo{
        std::string code; //���Ψһ����
        double length; //��
        double width; //��
        uint64_t startQuantity; //��ʼ����(ԭ���ϰ��/��������)
        uint64_t usedQuantity; //��ʹ������
        uint64_t restQuantity; //ʣ������
    };
    //�Ż�������ݽṹ��
    struct KNPACKING NestOutputData{
        unsigned short status;//״̬
        std::vector<NestPart> parts;//���/С����б�
        AlgorithmParameter algorithmParam;//�Ż�����
        std::vector<BinParameter> bins;//ԭ���ϰ��/����б�
        std::vector<NestPattern> patterns;//�Ű�ͼ��
        std::vector<NestPartUsedInfo> partUsedInfos;//��ʹ�õ����/С�����Ϣ
        std::vector<BinUsedInfo> binUsedInfos;//��ʹ�õ�ԭ���ϰ��/�����Ϣ
        double totalFillRate;//�����
        uint64_t totalPartCount;//���/С�������
    };

    //�Ż��������ṹ��
    struct KNPACKING NestOutput{
        unsigned short status;//״̬
        NestOutputData data;//�������
    };
}