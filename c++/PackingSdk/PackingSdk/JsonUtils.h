#pragma once
// 添加导出宏定义
#ifdef KNPACKING_EXPORTS
#define KNPACKING __declspec(dllexport)
#else
#define KNPACKING __declspec(dllimport)
#endif
#include "json.hpp"
#include "PackingSdk.h"
#include "NestOutput.h"
/**
* @brief json相关的工具类（包括读取json的值等）
* 
* 例如：std::string val = JsonUtils::getString(jsonNode, "name");
*/
namespace knest {
	using json = nlohmann::json;
	class KNPACKING JsonUtils
	{
	public:
		//从json中读取某个节点返回（返回的也是json）
		static json getJson(const json& jsonNode, const std::string& name);
		//从json中获取std::string
		static std::string getString(const json& jsonNode, const std::string& name);
		//获取double
		static double getDouble(const json& jsonNode, const std::string& name);
		//获取float
		static float getFloat(const json& jsonNode, const std::string& name);
		//获取int
		static int getInt(const json& jsonNode, const std::string& name);
		//获取uint
		static unsigned int getUInt(const json& jsonNode, const std::string& name);
		//获取ushort
		static unsigned short getUShort(const json& jsonNode, const std::string& name);
		//获取uchar
		static unsigned char getUChar(const json& jsonNode, const std::string& name);
		//获取long
		static long getLong(const json& jsonNode, const std::string& name);
		//获取ulong
		static unsigned long getULong(const json& jsonNode, const std::string& name);
		//获取ulong long
		static unsigned long long getULLong(const json& jsonNode, const std::string& name);
		//获取bool
		static bool getBool(const json& jsonNode, const std::string& name);
		//获取char
		static char getChar(const json& jsonNode, const std::string& name);
		// 读取整个JSON文件为字符串
		static const char* readJsonFile(const std::string& fileName);
		//将字符从utf-8转换为gbk
		static std::string utf8ToGbk(const char* src_str);
		//将字符从gbk转换为utf-8
		static std::string gbkToUtf8(const char* src_str);
		//将字符串数据转换为SolverOutput
		static SolverOutput charToSolverOutput(const char* data);
		//将jsonResult字符串转换为NestOutput
		static NestOutput jsonResultToNestOutput(const std::string& data);
	};
}
