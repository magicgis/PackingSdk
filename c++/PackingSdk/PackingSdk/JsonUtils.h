#pragma once
// ��ӵ����궨��
#ifdef KNPACKING_EXPORTS
#define KNPACKING __declspec(dllexport)
#else
#define KNPACKING __declspec(dllimport)
#endif
#include "json.hpp"
#include "PackingSdk.h"
#include "NestOutput.h"
/**
* @brief json��صĹ����ࣨ������ȡjson��ֵ�ȣ�
* 
* ���磺std::string val = JsonUtils::getString(jsonNode, "name");
*/
namespace knest {
	using json = nlohmann::json;
	class KNPACKING JsonUtils
	{
	public:
		//��json�ж�ȡĳ���ڵ㷵�أ����ص�Ҳ��json��
		static json getJson(const json& jsonNode, const std::string& name);
		//��json�л�ȡstd::string
		static std::string getString(const json& jsonNode, const std::string& name);
		//��ȡdouble
		static double getDouble(const json& jsonNode, const std::string& name);
		//��ȡfloat
		static float getFloat(const json& jsonNode, const std::string& name);
		//��ȡint
		static int getInt(const json& jsonNode, const std::string& name);
		//��ȡuint
		static unsigned int getUInt(const json& jsonNode, const std::string& name);
		//��ȡushort
		static unsigned short getUShort(const json& jsonNode, const std::string& name);
		//��ȡuchar
		static unsigned char getUChar(const json& jsonNode, const std::string& name);
		//��ȡlong
		static long getLong(const json& jsonNode, const std::string& name);
		//��ȡulong
		static unsigned long getULong(const json& jsonNode, const std::string& name);
		//��ȡulong long
		static unsigned long long getULLong(const json& jsonNode, const std::string& name);
		//��ȡbool
		static bool getBool(const json& jsonNode, const std::string& name);
		//��ȡchar
		static char getChar(const json& jsonNode, const std::string& name);
		// ��ȡ����JSON�ļ�Ϊ�ַ���
		static const char* readJsonFile(const std::string& fileName);
		//���ַ���utf-8ת��Ϊgbk
		static std::string utf8ToGbk(const char* src_str);
		//���ַ���gbkת��Ϊutf-8
		static std::string gbkToUtf8(const char* src_str);
		//���ַ�������ת��ΪSolverOutput
		static SolverOutput charToSolverOutput(const char* data);
		//��jsonResult�ַ���ת��ΪNestOutput
		static NestOutput jsonResultToNestOutput(const std::string& data);
	};
}
