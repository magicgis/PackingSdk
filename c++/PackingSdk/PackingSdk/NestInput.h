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

#include <string>
#include <vector>
#include <iostream>
#include "json.hpp"

namespace knest {
	//优化的参数(旧版本结构-只支持单种大板类型的优化)
	struct KNPACKING OptParameter {
		std::string material;//基材
		float thickness;//板厚
		float trimL;//左修边
		float trimR;//右修边
		float trimT;//上修边
		float trimB;//下修边
		float spacing;//板件/零件之间的间距
		double binLength;//原材料大板长度
		double binWidth;//原材料大板宽度
		unsigned char baseCorner = 1;//优化的堆积角落，1表示左下角，2表示右下角，3表示右上角，4表示左上角
		unsigned char nestType;//优先级类型 1表示优先级大于0的尽量靠前，2表示优先级大于0的绝对靠前
		bool enablePriority = false;//是否启用板件/零件的排版优先级（优先级的值默认是0）
		unsigned char priorityType;//优先级类型 1表示优先级大于0的尽量靠前，2表示优先级大于0的绝对靠前
		bool higherPriorityPlacedFront = false;//大板中的小板存在优先级定义时，该大板靠前还是靠后, true 则放在前面，false 则放在后面， 默认false
		unsigned long binCount;//原材料大板对应的数量
		int resultTimeOut = -1;//得到优化结果后，等待多长时间内(毫秒)再无优化结果变化，则算法停止运行，当为-1表示不限制，即一直等待
		unsigned short logLevel = 4;//日志级别，默认值是2调试模式  Trace = 1, Debug = 2, Info = 3, Warn = 4, Error = 5, Fatal = 6, Off = 7
		bool jsonResultAsFile = false;//是否将输出结果导出为文件，然后将文件路径放入jsonResult中。默认值为false，false表示jsonResult中放入的是json字符串(NestOutput)，true表示将json字符串保存为文件后，将文件路径值放入jsonResult
		unsigned char binValueType = 1;//大板价值类型：按照面积还是按照价格，当为空或者为1表示按照面积，非空且为2表示按照价格
		double binValue;//大板价格
		bool enableExecCbOnTimer = false;//是否启用了定期执行回调函数，默认为false不启用
		unsigned int execCbOnTimerInterval = 3;//定时执行回调函数的间隔时间，单位（秒），默认值为3秒
		unsigned int calThreads = 2;//算法计算线程数，默认值为2个

		// 手动序列化函数
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				j["material"] = material;
				j["thickness"] = thickness;
				j["trimL"] = trimL;
				j["trimR"] = trimR;
				j["trimT"] = trimT;
				j["trimB"] = trimB;
				j["spacing"] = spacing;
				j["binLength"] = binLength;
				j["binWidth"] = binWidth;
				j["baseCorner"] = static_cast<int>(baseCorner);          // 显式转换
				j["nestType"] = static_cast<int>(nestType);              // 显式转换
				j["enablePriority"] = enablePriority;
				j["priorityType"] = static_cast<int>(priorityType);      // 显式转换
				j["higherPriorityPlacedFront"] = higherPriorityPlacedFront;
				j["binCount"] = binCount;
				j["resultTimeOut"] = resultTimeOut;
				j["logLevel"] = logLevel;
				j["jsonResultAsFile"] = jsonResultAsFile;
				j["binValueType"] = static_cast<int>(binValueType);      // 显式转换
				j["binValue"] = binValue;
				j["enableExecCbOnTimer"] = enableExecCbOnTimer;
				j["execCbOnTimerInterval"] = execCbOnTimerInterval;
				j["calThreads"] = calThreads;
			}
			catch (const std::exception& e) {
				std::cout << "序列化错误: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//顶点
	struct KNPACKING Vertex {
		double x;//x坐标
		double y;//y坐标
		double bulge = 0.0;//凸度值

		// 手动序列化函数
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				j["x"] = x;
				j["y"] = y;
				j["bulge"] = bulge;
			}
			catch (const std::exception& e) {
				std::cout << "序列化错误: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//零件/小板件数据
	struct KNPACKING NestPart {
		unsigned long num;//唯一数字，初始化时指定，后面都不会变（可以理解为顺序号）
		std::string code;//唯一编码（字符类型的唯一编码）
		double length;//板长
		double width;//板宽
		unsigned long quantity;//数量
		bool texture;//是否要求纹理(false无纹理要求-即表示可以任意旋转  true有纹理要求-即表示不可旋转或者只能旋转180度)
		std::vector<Vertex> outer;//外轮廓
		std::vector<std::vector<Vertex>> inners;//内轮廓
		std::vector<Vertex> outerPreserved;//包含预留空间的轮廓，当没有预留空间时，该值为空
		unsigned long priority = 0;//优先级，默认为0

		// 手动序列化函数
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				j["num"] = num;
				j["code"] = code;
				j["length"] = length;
				j["width"] = width;
				j["quantity"] = quantity;
				j["texture"] = texture;
				j["priority"] = priority;

				// 处理外轮廓
				nlohmann::json outerJson = nlohmann::json::array();
				for (const auto& vertex : outer) {
					outerJson.push_back(vertex.toJson());
				}
				j["outer"] = outerJson;

				// 处理内轮廓（二维数组）
				nlohmann::json innersJson = nlohmann::json::array();
				for (const auto& innerContour : inners) {
					nlohmann::json innerJson = nlohmann::json::array();
					for (const auto& vertex : innerContour) {
						innerJson.push_back(vertex.toJson());
					}
					innersJson.push_back(innerJson);
				}
				j["inners"] = innersJson;

				// 处理预留轮廓
				nlohmann::json outerPreservedJson = nlohmann::json::array();
				for (const auto& vertex : outerPreserved) {
					outerPreservedJson.push_back(vertex.toJson());
				}
				j["outerPreserved"] = outerPreservedJson;

			}
			catch (const std::exception& e) {
				std::cout << "NestPart序列化错误: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//算法相关参数
	struct KNPACKING AlgorithmParameter {
		unsigned char nestType = 0;//嵌套计算的类型，0 表示不嵌套，1 表示简单异形嵌套，2 表示复杂异形嵌套
		unsigned char baseCorner = 1;//优化的堆积角落，1表示左下角，2表示右下角，3表示右上角，4表示左上角
		bool enablePriority = false;//是否启用板块的排版优先级（优先级的值默认是0）
		unsigned char priorityType = 1;//优先级类型 1表示优先级大于0的尽量靠前，2表示优先级大于0的绝对靠前
		bool higherPriorityPlacedFront = false;//大板中的小板存在优先级定义时，该大板靠前还是靠后, true 则放在前面，false 则放在后面
		int resultTimeOut = -1;//得到优化结果后，等待多长时间内(毫秒)再无优化结果变化，则算法停止运行，当为-1表示不限制，即一直等待
		bool jsonResultAsFile = false;//是否将输出结果导出为文件。默认值为false，false表示NestOutput的jsonResult属性中放入的是json字符串(NestOutput)，true表示将NestOutput对应的json保存为文件，并且将该json文件路径放入到jsonResult中
		unsigned char binValueType = 1;//大板价值类型：按照面积还是按照价格，当为空或者为1表示按照面积，非空且为2表示按照价格
		bool enableExecCbOnTimer = false;//是否启用了定期执行回调函数，默认为false不启用
		unsigned int execCbOnTimerInterval = 3;//定时执行回调函数的间隔时间，单位（秒），默认值为3秒
		unsigned int calThreads = 2;//算法计算线程数，默认值为2个

		// 手动序列化函数
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				// 注意：nestType 有可能为字符 '0'，但在JSON中我们存储为数值
				// 如果想保持字符特性，可以改为 j["nestType"] = std::string(1, nestType);
				if (nestType == '0') {
					j["nestType"] = 0;
				}
				else if (nestType == '1') {
					j["nestType"] = 1;
				}
				else if (nestType == '2') {
					j["nestType"] = 2;
				}
				else {
					j["nestType"] = static_cast<int>(nestType);  // 其他情况转换为数值
				}
				j["baseCorner"] = static_cast<int>(baseCorner);          // 显式转换
				j["enablePriority"] = enablePriority;
				j["priorityType"] = static_cast<int>(priorityType);        // unsigned char 显式转换
				j["higherPriorityPlacedFront"] = higherPriorityPlacedFront;
				j["resultTimeOut"] = resultTimeOut;
				j["jsonResultAsFile"] = jsonResultAsFile;
				j["binValueType"] = static_cast<int>(binValueType);        // unsigned char 显式转换
				j["enableExecCbOnTimer"] = enableExecCbOnTimer;
				j["execCbOnTimerInterval"] = execCbOnTimerInterval;
				j["calThreads"] = calThreads;
			}
			catch (const std::exception& e) {
				std::cout << "AlgorithmParameter序列化错误: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//大板的属性
	struct KNPACKING BinParameter {
		std::string material;//基材
		float thickness;//板厚
		float trimL;//左修边
		float trimR;//右修边
		float trimT;//上修边
		float trimB;//下修边
		float spacing;//小板件/零件之间的间距
		double binLength;//原材料大板长度
		double binWidth;//原材料大板宽度
		unsigned long binCount;//原材料大板对应的数量
		double binValue;//原材料大板对应的价格

		// 手动序列化函数
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				j["material"] = material;
				j["thickness"] = thickness;
				j["trimL"] = trimL;
				j["trimR"] = trimR;
				j["trimT"] = trimT;
				j["trimB"] = trimB;
				j["spacing"] = spacing;
				j["binLength"] = binLength;
				j["binWidth"] = binWidth;
				j["binCount"] = binCount;
				j["binValue"] = binValue;
			}
			catch (const std::exception& e) {
				std::cout << "BinParameter序列化错误: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//优化算法输入数据
	struct KNPACKING NestInputData {
		OptParameter param;//优化参数
		//std::vector<GroupInfo> groupInfos;//组信息列表
		//std::vector<WsPart> partOfGroups;//组信息列表，该节点下的part，其属性groupCode必须非空

		//上面的属性是原有属性，下面的属性是建议新增属性
		//原有结构保留，以兼容以前的数据。新的输入数据根据版本version的值来区分，例如当版本号为1时，优化相关参数从algorithmParam中获取，大板的相关参数则从bins中获取（从而支持多原片-单次优化时输入数据中有多个不同的大板）
		unsigned short version = 1;//版本
		std::vector<NestPart> parts;//零件/小板件列表
		AlgorithmParameter algorithmParam;//优化参数
		std::vector<BinParameter> bins;//原材料板件/大板列表

		// 手动序列化函数
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				j["param"] = param.toJson();
				j["version"] = version;

				// 序列化 parts 数组
				nlohmann::json partsArray = nlohmann::json::array();
				for (const auto& part : parts) {
					partsArray.push_back(part.toJson());
				}
				j["parts"] = partsArray;

				j["algorithmParam"] = algorithmParam.toJson();

				// 序列化 bins 数组
				nlohmann::json binsArray = nlohmann::json::array();
				for (const auto& bin : bins) {
					binsArray.push_back(bin.toJson());
				}
				j["bins"] = binsArray;
			}
			catch (const std::exception& e) {
				std::cout << "NestInputData 序列化错误: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//优化算法输入(总体结构)
	struct KNPACKING NestInput {
		unsigned short version = 1;//版本
		NestInputData data;//优化所需的所有数据

		// 手动序列化函数
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				j["version"] = version;
				j["data"] = data.toJson();
			}
			catch (const std::exception& e) {
				std::cout << "NestInput序列化错误: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
}