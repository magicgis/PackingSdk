#include "JsonUtils.h"
#include <fstream>
#include <direct.h>
#include <iostream>
#include <windows.h>

namespace knest {
	json JsonUtils::getJson(const json& jsonNode, const std::string& name)
	{
		json value;
		if (jsonNode.contains(name))
		{
			try
			{
				value = jsonNode.at(name);
			}
			catch (json::type_error& e)
			{
				std::cerr << "getJson error: " << e.what() << std::endl;
			}
		}
		return value;
	}

	std::string JsonUtils::getString(const json& jsonNode, const std::string& name)
	{
		std::string value;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error&)
			{
				value = jsonNode.at(name).dump();
				//std::cerr << "getString(name:" << name << ") warnning: " << e.what() << std::endl;
			}
		}
		return value;
	}
	double JsonUtils::getDouble(const json& jsonNode, const std::string& name)
	{
		double value = 0.0;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				value = std::stod(nodeVal);
				std::cerr << "getDouble error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	float JsonUtils::getFloat(const json& jsonNode, const std::string& name)
	{
		float value = 0.0;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				value = std::stof(nodeVal);
				std::cerr << "getFloat error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	int JsonUtils::getInt(const json& jsonNode, const std::string& name)
	{
		int value = 0;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				nodeVal.erase(remove(nodeVal.begin(), nodeVal.end(), '\"'), nodeVal.end());
				value = std::stoi(nodeVal);
				std::cerr << "getInt error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	unsigned int JsonUtils::getUInt(const json& jsonNode, const std::string& name)
	{
		unsigned int value = 0;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				nodeVal.erase(remove(nodeVal.begin(), nodeVal.end(), '\"'), nodeVal.end());
				value = std::stoi(nodeVal);
				std::cerr << "getUInt error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	unsigned short JsonUtils::getUShort(const json& jsonNode, const std::string& name) {
		unsigned short value = 0;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				nodeVal.erase(remove(nodeVal.begin(), nodeVal.end(), '\"'), nodeVal.end());
				value = std::stoi(nodeVal);
				std::cerr << "getUShort error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	unsigned char JsonUtils::getUChar(const json& jsonNode, const std::string& name) {
		unsigned char value = '0';
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				nodeVal.erase(remove(nodeVal.begin(), nodeVal.end(), '\"'), nodeVal.end());
				int val = std::stoi(nodeVal);
				if (val < 0 || val > UCHAR_MAX) {
					throw std::out_of_range("Value out of range for unsigned char");
				}
				value = static_cast<unsigned char>(val);
				std::cerr << "getUChar error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	long JsonUtils::getLong(const json& jsonNode, const std::string& name)
	{
		long value = 0;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				value = std::stol(nodeVal);
				std::cerr << "getLong error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	unsigned long JsonUtils::getULong(const json& jsonNode, const std::string& name)
	{
		unsigned long value = 0;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				value = std::stoul(nodeVal);
				std::cerr << "getULong error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	unsigned long long JsonUtils::getULLong(const json& jsonNode, const std::string& name)
	{
		unsigned long long value = 0;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				value = std::stoull(nodeVal); // 使用 stoull 而不是 stoul
				std::cerr << "getULLong error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	bool JsonUtils::getBool(const json& jsonNode, const std::string& name)
	{
		bool value = false;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				std::string nodeVal = jsonNode.at(name).dump();
				value = (std::stoi(nodeVal) > 0 ? true : false);
				std::cerr << "getBool error: " << e.what() << std::endl;
			}
		}
		return value;
	}
	char JsonUtils::getChar(const json& jsonNode, const std::string& name)
	{
		std::string value;
		if (jsonNode.contains(name))
		{
			try
			{
				jsonNode.at(name).get_to(value);
			}
			catch (json::type_error& e)
			{
				value = jsonNode.at(name).dump();
				std::cerr << "getChar error: " << e.what() << std::endl;
			}
		}
		return *value.c_str();
	}
#define GetCurrentDir _getcwd
	// 读取整个JSON文件为字符串
	const char* JsonUtils::readJsonFile(const std::string& fileName) {
		try {
			char filePath[FILENAME_MAX];
			if (!GetCurrentDir(filePath, FILENAME_MAX)) {
				throw std::runtime_error("无法获取当前路径");
			}
			std::string finalPath = std::string(filePath) + "\\jsons\\" + fileName;
			// 以二进制模式打开文件，支持 UTF-8 BOM
			std::ifstream file(finalPath, std::ios::binary);
			// 检查并跳过 UTF-8 BOM
			char bom[3];
			file.read(bom, 3);
			if (!(bom[0] == (char)0xEF && bom[1] == (char)0xBB && bom[2] == (char)0xBF)) {
				// 如果不是 BOM，回到文件开头
				file.seekg(0);
			}
			// 读取文件内容
			std::string fileContent((std::istreambuf_iterator<char>(file)),
				std::istreambuf_iterator<char>());

			// UTF-8 编码验证
			auto validateUtf8 = [](const std::string& str) -> bool {
				int byteCount = 0;
				for (unsigned char c : str) {
					if (byteCount == 0) {
						if ((c >> 5) == 0b110) byteCount = 1;       // 2字节字符
						else if ((c >> 4) == 0b1110) byteCount = 2; // 3字节字符
						else if ((c >> 3) == 0b11110) byteCount = 3;// 4字节字符
						else if (c >> 7) return false;  // 单字节字符不应以1开头
					}
					else {
						// 检查后续字节
						if ((c >> 6) != 0b10) return false;
						byteCount--;
					}
				}
				return byteCount == 0;
				};

			if (!validateUtf8(fileContent)) {
				throw std::runtime_error("文件包含无效的 UTF-8 编码");
			}

			// 解析 JSON
			nlohmann::json jsonData = nlohmann::json::parse(fileContent);

			// 将 JSON 转换为格式化字符串
			std::string jsonString = jsonData.dump(4);  // 4空格缩进

			// 使用 unique_ptr 管理内存
			auto jsonContent = std::make_unique<char[]>(jsonString.length() + 1);

			// 安全拷贝
#ifdef _MSC_VER
			strcpy_s(jsonContent.get(), jsonString.length() + 1, jsonString.c_str());
#else
			strncpy(jsonContent.get(), jsonString.c_str(), jsonString.length() + 1);
			jsonContent[jsonString.length()] = '\0';
#endif

			return jsonContent.get();
		}
		catch (const std::exception& e) {
			// 错误处理
			std::cerr << "Error reading JSON: " << e.what() << std::endl;
			return nullptr;
		}
	}

	//将字符从utf-8转换为gbk
	std::string JsonUtils::utf8ToGbk(const char* src_str)
	{
		int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
		wchar_t* wszGBK = new wchar_t[len + 1];
		memset(wszGBK, 0, len * 2 + 2);
		MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
		len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
		char* szGBK = new char[len + 1];
		memset(szGBK, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
		std::string strTemp(szGBK);
		if (wszGBK) delete[] wszGBK;
		if (szGBK) delete[] szGBK;
		return strTemp;
	}

	std::string JsonUtils::gbkToUtf8(const char* src_str)
	{
		// 第一步：将GBK转换为宽字符（UTF-16）
		int len = MultiByteToWideChar(936, 0, src_str, -1, nullptr, 0);
		if (len <= 0) return std::string();

		wchar_t* wstr = new wchar_t[len];
		memset(wstr, 0, len * sizeof(wchar_t));
		MultiByteToWideChar(936, 0, src_str, -1, wstr, len);

		// 第二步：将宽字符（UTF-16）转换为UTF-8
		len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
		if (len <= 0)
		{
			delete[] wstr;
			return std::string();
		}

		char* utf8_str = new char[len];
		memset(utf8_str, 0, len);
		WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8_str, len, nullptr, nullptr);

		std::string result(utf8_str);

		// 清理内存
		delete[] wstr;
		delete[] utf8_str;

		return result;
	}

	SolverOutput JsonUtils::charToSolverOutput(const char* data) {
		//将字符串转换为json对象
		nlohmann::json outputJson;
		try
		{
			outputJson = nlohmann::json::parse(data);
		}
		catch (nlohmann::detail::exception& e)
		{
			printf(e.what());
		}
		//将json对象转换为SolverOutput结构体
		SolverOutput output;
		output.solverState = SolverState(JsonUtils::getInt(outputJson, "solverState"));
		output.solverEndedReason = SolverEndedReason(JsonUtils::getInt(outputJson, "solverEndedReason"));
		output.solverEndedMsg = JsonUtils::getString(outputJson, "solverEndedMsg");
		output.currentPriority = JsonUtils::getULong(outputJson, "currentPriority");
		output.numOfIteration = JsonUtils::getULong(outputJson, "numOfIteration");
		output.elapsedTime = JsonUtils::getULong(outputJson, "elapsedTime");
		output.calUsage = JsonUtils::getDouble(outputJson, "calUsage");
		output.calProgress = JsonUtils::getDouble(outputJson, "calProgress");
		output.calTargetSheetCount = JsonUtils::getUInt(outputJson, "calTargetSheetCount");
		output.optimumIndex = JsonUtils::getULong(outputJson, "optimumIndex");
		output.bestFitness = JsonUtils::getULong(outputJson, "bestFitness");
		output.resultTimeOut = JsonUtils::getLong(outputJson, "resultTimeOut");
		output.startTimeForTimeOut = JsonUtils::getULong(outputJson, "startTimeForTimeOut");
		output.timeElapsedSinceLastResult = JsonUtils::getULong(outputJson, "timeElapsedSinceLastResult");
		output.bestResultSheetCount = JsonUtils::getUInt(outputJson, "bestResultSheetCount");
		output.partCountInBestResult = JsonUtils::getUInt(outputJson, "partCountInBestResult");
		output.bestResultUsage = JsonUtils::getDouble(outputJson, "bestResultUsage");
		//jsonResult中存放的是wsNestOutput的json字符串或者文件路径，可能存在中文，故需要utf-8编码转换为gbk编码
		output.jsonResult = JsonUtils::utf8ToGbk(JsonUtils::getString(outputJson, "jsonResult").c_str());
		output.isMultiPriorityMode = JsonUtils::getBool(outputJson, "isMultiPriorityMode");
		output.resultNumOfIteration = JsonUtils::getLong(outputJson, "resultNumOfIteration");
		output.numOfIterationSinceLastResult = JsonUtils::getULong(outputJson, "numOfIterationSinceLastResult");
		return output;
	}

	NestOutput JsonUtils::jsonResultToNestOutput(const std::string& data) {
		//将字符串转换为json对象
		nlohmann::json outputJson;//json对象
		NestOutput output;//输出对象
		try
		{
			outputJson = nlohmann::json::parse(data);
		}
		catch (nlohmann::detail::exception& e)
		{
			std::cout << "JSON转换失败" << std::endl;
			std::cout << "转换错误为: " << e.what() << std::endl;
			output.status = 1;//1为json转换失败错误
			return output;
		}
		//将json对象转换为SolverOutput结构体
		output.status = JsonUtils::getUShort(outputJson, "status");
		nlohmann::json dataJson = JsonUtils::getJson(outputJson, "data");
		NestOutputData outputData;
		outputData.status = JsonUtils::getUShort(dataJson, "status");
		std::vector<NestPart> parts;//小板件
		if (dataJson.contains("parts") && dataJson["parts"].is_array()) {
			// parts 是数组，可以进行遍历
			json& partsArray = dataJson["parts"];
			// 遍历
			for (auto& part : partsArray) {
				NestPart nestPart;
				nestPart.num = JsonUtils::getULong(part, "num");
				nestPart.code = JsonUtils::getString(part, "code");
				nestPart.length = JsonUtils::getDouble(part, "length");
				nestPart.width = JsonUtils::getDouble(part, "width");
				nestPart.quantity = JsonUtils::getULong(part, "quantity");
				nestPart.texture = JsonUtils::getBool(part, "texture");
				std::vector<Vertex> outer;//外轮廓
				if (part.contains("outer") && part["outer"].is_array()) {
					json& outerArray = part["outer"];
					for (auto& outerOne : outerArray) {
						Vertex vertex;
						vertex.x = JsonUtils::getDouble(outerOne, "x");
						vertex.y = JsonUtils::getDouble(outerOne, "y");
						vertex.bulge = JsonUtils::getDouble(outerOne, "bulge");
						outer.push_back(vertex);
					}
				}
				nestPart.outer = outer;
				parts.push_back(nestPart);
			}//end for
		}
		outputData.parts = parts;
		if (dataJson.contains("algorithmParam")) {
			json& algorithmParamJson = dataJson["algorithmParam"];
			AlgorithmParameter algorithmParam;
			algorithmParam.nestType = JsonUtils::getUChar(algorithmParamJson, "nestType");
			algorithmParam.baseCorner = JsonUtils::getUChar(algorithmParamJson, "baseCorner");
			algorithmParam.enablePriority = JsonUtils::getBool(algorithmParamJson, "enablePriority");
			algorithmParam.priorityType = JsonUtils::getUChar(algorithmParamJson, "priorityType");
			algorithmParam.higherPriorityPlacedFront = JsonUtils::getBool(algorithmParamJson, "higherPriorityPlacedFront");
			algorithmParam.resultTimeOut = JsonUtils::getInt(algorithmParamJson, "resultTimeOut");
			algorithmParam.jsonResultAsFile = JsonUtils::getBool(algorithmParamJson, "jsonResultAsFile");
			algorithmParam.binValueType = JsonUtils::getUChar(algorithmParamJson, "binValueType");
			algorithmParam.enableExecCbOnTimer = JsonUtils::getBool(algorithmParamJson, "enableExecCbOnTimer");
			algorithmParam.execCbOnTimerInterval = JsonUtils::getUInt(algorithmParamJson, "execCbOnTimerInterval");
			algorithmParam.calThreads = JsonUtils::getUInt(algorithmParamJson, "calThreads");
			outputData.algorithmParam = algorithmParam;
		}
		std::vector<BinParameter> bins;//大板件
		if (dataJson.contains("bins") && dataJson["bins"].is_array()) {
			// bins 是数组，可以进行遍历
			json& binsArray = dataJson["bins"];
			// 遍历
			for (auto& bin : binsArray) {
				BinParameter binParameter;
				binParameter.material = JsonUtils::getString(bin, "material");
				binParameter.thickness = JsonUtils::getFloat(bin, "thickness");
				binParameter.trimL = JsonUtils::getFloat(bin, "trimL");
				binParameter.trimR = JsonUtils::getFloat(bin, "trimR");
				binParameter.trimT = JsonUtils::getFloat(bin, "trimT");
				binParameter.trimB = JsonUtils::getFloat(bin, "trimB");
				binParameter.spacing = JsonUtils::getFloat(bin, "spacing");
				binParameter.binLength = JsonUtils::getDouble(bin, "binLength");
				binParameter.binWidth = JsonUtils::getDouble(bin, "binWidth");
				binParameter.binCount = JsonUtils::getULong(bin, "binCount");
				binParameter.binValue = JsonUtils::getDouble(bin, "binValue");
				bins.push_back(binParameter);
			}//end for
		}
		outputData.bins = bins;
		std::vector<NestPattern> patterns;//排版图案
		if (dataJson.contains("patterns") && dataJson["patterns"].is_array()) {
			// patterns 是数组，可以进行遍历
			json& patternsArray = dataJson["patterns"];
			//遍历
			for (auto& pattern : patternsArray) {
				NestPattern nestPattern;
				nestPattern.id = JsonUtils::getULLong(pattern, "id");
				nestPattern.code = JsonUtils::getString(pattern, "code");
				nestPattern.material = JsonUtils::getString(pattern, "material");
				nestPattern.length = JsonUtils::getDouble(pattern, "length");
				nestPattern.width = JsonUtils::getDouble(pattern, "width");
				nestPattern.thickness = JsonUtils::getDouble(pattern, "thickness");
				std::vector<NestPlacement> placements;//零件/小板件排版位置
				if (pattern.contains("wsPlacements") && pattern["wsPlacements"].is_array()) {
					json& placementArray = pattern["wsPlacements"];
					for (auto& placement : placementArray) {
						NestPlacement nestPlacement;
						nestPlacement.code = JsonUtils::getString(placement, "code");
						nestPlacement.texture = JsonUtils::getBool(placement, "texture");
						nestPlacement.angle = JsonUtils::getDouble(placement, "angle");
						nestPlacement.baseX = JsonUtils::getDouble(placement, "baseX");
						nestPlacement.baseY = JsonUtils::getDouble(placement, "baseY");
						placements.push_back(nestPlacement);
					}
				}
				nestPattern.wsPlacements = placements;
				nestPattern.area = JsonUtils::getDouble(pattern, "area");
				nestPattern.fillRate = JsonUtils::getDouble(pattern, "fillRate");
				patterns.push_back(nestPattern);
			}//end for
		}
		outputData.patterns = patterns;
		std::vector<NestPartUsedInfo> partUsedInfos;//被使用的零件/小板件信息
		if (dataJson.contains("partUsedInfos") && dataJson["partUsedInfos"].is_array()) {
			json& partUsedInfosArray = dataJson["partUsedInfos"];
			//遍历
			for (auto& partUsedInfosJson : partUsedInfosArray) {
				NestPartUsedInfo partUsedInfo;//被使用的零件/小板件信息
				partUsedInfo.code = JsonUtils::getString(partUsedInfosJson, "code");
				partUsedInfo.length = JsonUtils::getDouble(partUsedInfosJson, "length");
				partUsedInfo.width = JsonUtils::getDouble(partUsedInfosJson, "width");
				partUsedInfo.startQuantity = JsonUtils::getULLong(partUsedInfosJson, "startQuantity");
				partUsedInfo.usedQuantity = JsonUtils::getULLong(partUsedInfosJson, "usedQuantity");
				partUsedInfo.restQuantity = JsonUtils::getInt(partUsedInfosJson, "restQuantity");
				partUsedInfos.push_back(partUsedInfo);
			}//end for
		}
		outputData.partUsedInfos = partUsedInfos;
		std::vector<BinUsedInfo> binUsedInfos;//被使用的原材料板件/大板信息
		if (dataJson.contains("binUsedInfos") && dataJson["binUsedInfos"].is_array()) {
			json& binUsedInfosArray = dataJson["binUsedInfos"];
			//遍历
			for (auto& binUsedInfosJson : binUsedInfosArray) {
				BinUsedInfo binUsedInfo;//被使用的原材料板件/大板信息
				binUsedInfo.code = JsonUtils::getString(binUsedInfosJson, "code");
				binUsedInfo.length = JsonUtils::getDouble(binUsedInfosJson, "length");
				binUsedInfo.width = JsonUtils::getDouble(binUsedInfosJson, "width");
				binUsedInfo.startQuantity = JsonUtils::getULLong(binUsedInfosJson, "startQuantity");
				binUsedInfo.usedQuantity = JsonUtils::getULLong(binUsedInfosJson, "usedQuantity");
				binUsedInfo.restQuantity = JsonUtils::getInt(binUsedInfosJson, "restQuantity");
				binUsedInfos.push_back(binUsedInfo);
			}
		}
		outputData.binUsedInfos = binUsedInfos;
		outputData.totalFillRate = JsonUtils::getDouble(dataJson, "totalFillRate");
		outputData.totalPartCount = JsonUtils::getULLong(dataJson, "totalPartCount");
		output.data = outputData;
		return output;
	}
}
