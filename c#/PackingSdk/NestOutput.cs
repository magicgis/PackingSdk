using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace knest
{
    using System.Collections.Generic;
    // 零件/小板件的摆放信息
    public struct NestPlacement
    {
        public string code; // 唯一编码
        public bool texture; // 是否有纹理要求
        public double angle; // 旋转角度
        public double baseX; // 坐标x
        public double baseY; // 坐标y

        // 静态工厂方法，用于创建带默认值的实例
        public static NestPlacement CreateDefault()
        {
            return new NestPlacement
            {
                code = string.Empty
            };
        }
    }

    // 排版图案
    public struct NestPattern
    {
        public ulong id; // 原材料板件/大板id
        public string code; // 原材料板件/大板唯一编码
        public string material; // 材质
        public double length; // 排版图案长
        public double width; // 排版图案宽
        public double thickness; // 排版图案厚

        private List<NestPlacement> _wsPlacements;
        public List<NestPlacement> wsPlacements
        {
            get => _wsPlacements ?? (_wsPlacements = new List<NestPlacement>());
            set => _wsPlacements = value;
        } // 零件/小板件排版位置

        public double area; // 面积
        public double fillRate; // 填充率

        // 静态工厂方法，用于创建带默认值的实例
        public static NestPattern CreateDefault()
        {
            return new NestPattern
            {
                code = string.Empty,
                material = string.Empty,
                wsPlacements = new List<NestPlacement>()
            };
        }
    }

    // 已使用零件/小板件信息
    public struct NestPartUsedInfo
    {
        public string code; // 唯一编码
        public double length; // 零件/小板件长
        public double width; // 零件/小板件宽
        public ulong startQuantity; // 初始数量(零件/小板件的数量)
        public ulong usedQuantity; // 已使用数量
        public ulong restQuantity; // 剩余数量

        // 静态工厂方法，用于创建带默认值的实例
        public static NestPartUsedInfo CreateDefault()
        {
            return new NestPartUsedInfo
            {
                code = string.Empty
            };
        }
    }

    // 大板使用信息
    public struct BinUsedInfo
    {
        public string code; // 大板唯一编码
        public double length; // 长
        public double width; // 宽
        public ulong startQuantity; // 初始数量(原材料板件/大板的数量)
        public ulong usedQuantity; // 已使用数量
        public ulong restQuantity; // 剩余数量

        // 静态工厂方法，用于创建带默认值的实例
        public static BinUsedInfo CreateDefault()
        {
            return new BinUsedInfo
            {
                code = string.Empty
            };
        }
    }

    // 优化输出数据结构体
    public struct NestOutputData
    {
        public ushort status; // 状态

        private List<NestPart> _parts;
        private List<BinParameter> _bins;
        private List<NestPattern> _patterns;
        private List<NestPartUsedInfo> _partUsedInfos;
        private List<BinUsedInfo> _binUsedInfos;

        public List<NestPart> parts
        {
            get => _parts ?? (_parts = new List<NestPart>());
            set => _parts = value;
        } // 零件/小板件列表

        public AlgorithmParameter algorithmParam; // 优化参数

        public List<BinParameter> bins
        {
            get => _bins ?? (_bins = new List<BinParameter>());
            set => _bins = value;
        } // 原材料板件/大板列表

        public List<NestPattern> patterns
        {
            get => _patterns ?? (_patterns = new List<NestPattern>());
            set => _patterns = value;
        } // 排版图案

        public List<NestPartUsedInfo> partUsedInfos
        {
            get => _partUsedInfos ?? (_partUsedInfos = new List<NestPartUsedInfo>());
            set => _partUsedInfos = value;
        } // 被使用的零件/小板件信息

        public List<BinUsedInfo> binUsedInfos
        {
            get => _binUsedInfos ?? (_binUsedInfos = new List<BinUsedInfo>());
            set => _binUsedInfos = value;
        } // 被使用的原材料板件/大板信息

        public double totalFillRate; // 填充率
        public ulong totalPartCount; // 零件/小板件总数

        // 静态工厂方法，用于创建带默认值的实例
        public static NestOutputData CreateDefault()
        {
            return new NestOutputData
            {
                parts = new List<NestPart>(),
                algorithmParam = AlgorithmParameter.CreateDefault(),
                bins = new List<BinParameter>(),
                patterns = new List<NestPattern>(),
                partUsedInfos = new List<NestPartUsedInfo>(),
                binUsedInfos = new List<BinUsedInfo>()
            };
        }
    }

    // 优化输出结果结构体
    public struct NestOutput
    {
        public ushort status; // 状态
        public NestOutputData data; // 输出数据

        // 静态工厂方法，用于创建带默认值的实例
        public static NestOutput CreateDefault()
        {
            return new NestOutput
            {
                data = NestOutputData.CreateDefault()
            };
        }
    }
}
