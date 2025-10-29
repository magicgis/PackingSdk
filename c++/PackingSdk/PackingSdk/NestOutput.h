#pragma once
// 添加导出宏定义
#ifdef KNPACKING_EXPORTS
#define KNPACKING __declspec(dllexport)
#else
#define KNPACKING __declspec(dllimport)
#endif
#ifdef _WIN32
// 禁用 STL 容器在 DLL 边界的警告
#pragma warning(push)
#pragma warning(disable: 4251)
#pragma warning(disable: 4275)
#endif

#include "NestInput.h"

namespace knest {
    //零件/小板件的摆放信息
    struct KNPACKING NestPlacement{
        std::string code; //唯一编码
        bool texture; //是否有纹理要求
        double angle; //旋转角度
        double baseX; //坐标x
        double baseY; //坐标y
    };
    //排版图案
    struct KNPACKING NestPattern{
        uint64_t id; //原材料板件/大板id
        std::string code; //原材料板件/大板唯一编码
        std::string material; //材质
        double length; //排版图案长
        double width; //排版图案宽
        double thickness; //排版图案厚
        std::vector<NestPlacement> wsPlacements; //零件/小板件排版位置
        double area; // 面积
        double fillRate; // 填充率
    };
    //已使用零件/小板件信息
    struct KNPACKING NestPartUsedInfo {
        std::string code; //唯一编码
        double length; //零件/小板件长
        double width; //零件/小板件宽
        uint64_t startQuantity; //初始数量(零件/小板件的数量)
        uint64_t usedQuantity; //已使用数量
        uint64_t restQuantity; //剩余数量
    };
    //
    struct KNPACKING BinUsedInfo{
        std::string code; //大板唯一编码
        double length; //长
        double width; //宽
        uint64_t startQuantity; //初始数量(原材料板件/大板的数量)
        uint64_t usedQuantity; //已使用数量
        uint64_t restQuantity; //剩余数量
    };
    //优化输出数据结构体
    struct KNPACKING NestOutputData{
        unsigned short status;//状态
        std::vector<NestPart> parts;//零件/小板件列表
        AlgorithmParameter algorithmParam;//优化参数
        std::vector<BinParameter> bins;//原材料板件/大板列表
        std::vector<NestPattern> patterns;//排版图案
        std::vector<NestPartUsedInfo> partUsedInfos;//被使用的零件/小板件信息
        std::vector<BinUsedInfo> binUsedInfos;//被使用的原材料板件/大板信息
        double totalFillRate;//填充率
        uint64_t totalPartCount;//零件/小板件总数
    };

    //优化输出结果结构体
    struct KNPACKING NestOutput{
        unsigned short status;//状态
        NestOutputData data;//输出数据
    };
}