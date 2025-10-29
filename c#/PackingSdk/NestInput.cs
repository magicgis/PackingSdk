using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace knest
{
    using System.Collections.Generic;
    // 优化的参数(旧版本结构-只支持单种大板类型的优化)
    public struct OptParameter
    {
        public string material; // 基材
        public float thickness; // 板厚
        public float trimL; // 左修边
        public float trimR; // 右修边
        public float trimT; // 上修边
        public float trimB; // 下修边
        public float spacing; // 板件/零件之间的间距
        public double binLength; // 原材料大板长度
        public double binWidth; // 原材料大板宽度
        public byte baseCorner; // 优化的堆积角落，1表示左下角，2表示右下角，3表示右上角，4表示左上角
        public byte nestType; // 优先级类型 1表示优先级大于0的尽量靠前，2表示优先级大于0的绝对靠前
        public bool enablePriority; // 是否启用板件/零件的排版优先级（优先级的值默认是0）
        public byte priorityType; // 优先级类型 1表示优先级大于0的尽量靠前，2表示优先级大于0的绝对靠前
        public bool higherPriorityPlacedFront; // 大板中的小板存在优先级定义时，该大板靠前还是靠后, true 则放在前面，false 则放在后面， 默认false
        public ulong binCount; // 原材料大板对应的数量
        public int resultTimeOut; // 得到优化结果后，等待多长时间内(毫秒)再无优化结果变化，则算法停止运行，当为-1表示不限制，即一直等待
        public ushort logLevel; // 日志级别，默认值是2调试模式  Trace = 1, Debug = 2, Info = 3, Warn = 4, Error = 5, Fatal = 6, Off = 7
        public bool jsonResultAsFile; // 是否将输出结果导出为文件，然后将文件路径放入jsonResult中。默认值为false，false表示jsonResult中放入的是json字符串(NestOutput)，true表示将json字符串保存为文件后，将文件路径值放入jsonResult
        public byte binValueType; // 大板价值类型：按照面积还是按照价格，当为空或者为1表示按照面积，非空且为2表示按照价格
        public double binValue; // 大板价格
        public bool enableExecCbOnTimer; // 是否启用了定期执行回调函数，默认为false不启用
        public uint execCbOnTimerInterval; // 定时执行回调函数的间隔时间，单位（秒），默认值为3秒
        public uint calThreads; // 算法计算线程数，默认值为2个

        // 静态工厂方法，用于创建带默认值的实例
        public static OptParameter CreateDefault()
        {
            return new OptParameter
            {
                material = string.Empty,
                baseCorner = 1,
                resultTimeOut = -1,
                logLevel = 4,
                binValueType = 1,
                execCbOnTimerInterval = 3,
                calThreads = 2
            };
        }
    }

    // 顶点
    public struct Vertex
    {
        public double x; // x坐标
        public double y; // y坐标
        public double bulge; // 凸度值

        public Vertex(double x, double y, double bulge = 0.0)
        {
            this.x = x;
            this.y = y;
            this.bulge = bulge;
        }
    }

    // 小板件数据
    public struct NestPart
    {
        public ulong num; // 唯一数字，初始化时指定，后面都不会变（可以理解为顺序号）
        public string code; // 唯一编码（字符类型的唯一编码）
        public double length; // 板长
        public double width; // 板宽
        public ulong quantity; // 数量
        public bool texture; // 是否要求纹理(false无纹理要求-即表示可以任意旋转  true有纹理要求-即表示不可旋转或者只能旋转180度)

        private List<Vertex> _outer;
        private List<List<Vertex>> _inners;
        private List<Vertex> _outerPreserved;

        public List<Vertex> outer
        {
            get => _outer ?? (_outer = new List<Vertex>());
            set => _outer = value;
        } // 外轮廓

        public List<List<Vertex>> inners
        {
            get => _inners ?? (_inners = new List<List<Vertex>>());
            set => _inners = value;
        } // 内轮廓

        public List<Vertex> outerPreserved
        {
            get => _outerPreserved ?? (_outerPreserved = new List<Vertex>());
            set => _outerPreserved = value;
        } // 包含预留空间的轮廓，当没有预留空间时，该值为空

        public ulong priority; // 优先级，默认为0

        // 静态工厂方法，用于创建带默认值的实例
        public static NestPart CreateDefault()
        {
            return new NestPart
            {
                code = string.Empty,
                outer = new List<Vertex>(),
                inners = new List<List<Vertex>>(),
                outerPreserved = new List<Vertex>()
            };
        }
    }

    // 算法相关参数
    public struct AlgorithmParameter
    {
        public byte nestType; // 嵌套计算的类型，0 表示不嵌套，1 表示简单异形嵌套，2 表示复杂异形嵌套
        public byte baseCorner; // 优化的堆积角落，1表示左下角，2表示右下角，3表示右上角，4表示左上角
        public bool enablePriority; // 是否启用板块的排版优先级（优先级的值默认是0）
        public byte priorityType; // 优先级类型 1表示优先级大于0的尽量靠前，2表示优先级大于0的绝对靠前
        public bool higherPriorityPlacedFront; // 大板中的小板存在优先级定义时，该大板靠前还是靠后, true 则放在前面，false 则放在后面
        public int resultTimeOut; // 得到优化结果后，等待多长时间内(毫秒)再无优化结果变化，则算法停止运行，当为-1表示不限制，即一直等待
        public bool jsonResultAsFile; // 是否将输出结果导出为文件，然后将文件路径放入json_result中。默认值为false，false表示json_result中放入的是json字符串(NestOutput)，true表示将json字符串保存为文件后，将文件路径值放入json_result
        public byte binValueType; // 大板价值类型：按照面积还是按照价格，当为空或者为1表示按照面积，非空且为2表示按照价格
        public bool enableExecCbOnTimer; // 是否启用了定期执行回调函数，默认为false不启用
        public uint execCbOnTimerInterval; // 定时执行回调函数的间隔时间，单位（秒），默认值为3秒
        public uint calThreads; // 算法计算线程数，默认值为2个

        // 静态工厂方法，用于创建带默认值的实例
        public static AlgorithmParameter CreateDefault()
        {
            return new AlgorithmParameter
            {
                baseCorner = 1,
                priorityType = 1,
                resultTimeOut = -1,
                binValueType = 1,
                execCbOnTimerInterval = 3,
                calThreads = 2
            };
        }
    }

    // 大板的属性
    public struct BinParameter
    {
        public string material; // 基材
        public float thickness; // 板厚
        public float trimL; // 左修边
        public float trimR; // 右修边
        public float trimT; // 上修边
        public float trimB; // 下修边
        public float spacing; // 小板件/零件之间的间距
        public double binLength; // 原材料大板长度
        public double binWidth; // 原材料大板宽度
        public ulong binCount; // 原材料大板对应的数量
        public double binValue; // 原材料大板对应的价格

        // 静态工厂方法，用于创建带默认值的实例
        public static BinParameter CreateDefault()
        {
            return new BinParameter
            {
                material = string.Empty
            };
        }
    }

    // 优化算法输入数据
    public struct NestInputData
    {
        public OptParameter param; // 优化参数
                                   // std::vector<GroupInfo> groupInfos; // 组信息列表
                                   // std::vector<WsPart> partOfGroups; // 组信息列表，该节点下的part，其属性groupCode必须非空
                                   // 上面的属性是原有属性，下面的属性是建议新增属性
                                   // 原有结构保留，以兼容以前的数据。新的输入数据根据版本version的值来区分，例如当版本号为1时，优化相关参数从algorithmParam中获取，大板的相关参数则从bins中获取（从而支持多原片-单次优化时输入数据中有多个不同的大板）
        public ushort version; // 版本

        private List<NestPart> _parts;
        private List<BinParameter> _bins;

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

        // 静态工厂方法，用于创建带默认值的实例
        public static NestInputData CreateDefault()
        {
            return new NestInputData
            {
                param = OptParameter.CreateDefault(),
                version = 1,
                parts = new List<NestPart>(),
                algorithmParam = AlgorithmParameter.CreateDefault(),
                bins = new List<BinParameter>()
            };
        }
    }

    // 优化算法输入(总体结构)
    public struct NestInput
    {
        public ushort version; // 版本
        public NestInputData data; // 优化所需的所有数据

        // 静态工厂方法，用于创建带默认值的实例
        public static NestInput CreateDefault()
        {
            return new NestInput
            {
                version = 1,
                data = NestInputData.CreateDefault()
            };
        }
    }
}
