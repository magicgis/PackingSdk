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

#include <string>
#include <vector>
#include <iostream>
#include "json.hpp"

namespace knest {
	//�Ż��Ĳ���(�ɰ汾�ṹ-ֻ֧�ֵ��ִ�����͵��Ż�)
	struct KNPACKING OptParameter {
		std::string material;//����
		float thickness;//���
		float trimL;//���ޱ�
		float trimR;//���ޱ�
		float trimT;//���ޱ�
		float trimB;//���ޱ�
		float spacing;//���/���֮��ļ��
		double binLength;//ԭ���ϴ�峤��
		double binWidth;//ԭ���ϴ����
		unsigned char baseCorner = 1;//�Ż��Ķѻ����䣬1��ʾ���½ǣ�2��ʾ���½ǣ�3��ʾ���Ͻǣ�4��ʾ���Ͻ�
		unsigned char nestType;//���ȼ����� 1��ʾ���ȼ�����0�ľ�����ǰ��2��ʾ���ȼ�����0�ľ��Կ�ǰ
		bool enablePriority = false;//�Ƿ����ð��/������Ű����ȼ������ȼ���ֵĬ����0��
		unsigned char priorityType;//���ȼ����� 1��ʾ���ȼ�����0�ľ�����ǰ��2��ʾ���ȼ�����0�ľ��Կ�ǰ
		bool higherPriorityPlacedFront = false;//����е�С��������ȼ�����ʱ���ô�忿ǰ���ǿ���, true �����ǰ�棬false ����ں��棬 Ĭ��false
		unsigned long binCount;//ԭ���ϴ���Ӧ������
		int resultTimeOut = -1;//�õ��Ż�����󣬵ȴ��೤ʱ����(����)�����Ż�����仯�����㷨ֹͣ���У���Ϊ-1��ʾ�����ƣ���һֱ�ȴ�
		unsigned short logLevel = 4;//��־����Ĭ��ֵ��2����ģʽ  Trace = 1, Debug = 2, Info = 3, Warn = 4, Error = 5, Fatal = 6, Off = 7
		bool jsonResultAsFile = false;//�Ƿ�����������Ϊ�ļ���Ȼ���ļ�·������jsonResult�С�Ĭ��ֵΪfalse��false��ʾjsonResult�з������json�ַ���(NestOutput)��true��ʾ��json�ַ�������Ϊ�ļ��󣬽��ļ�·��ֵ����jsonResult
		unsigned char binValueType = 1;//����ֵ���ͣ�����������ǰ��ռ۸񣬵�Ϊ�ջ���Ϊ1��ʾ����������ǿ���Ϊ2��ʾ���ռ۸�
		double binValue;//���۸�
		bool enableExecCbOnTimer = false;//�Ƿ������˶���ִ�лص�������Ĭ��Ϊfalse������
		unsigned int execCbOnTimerInterval = 3;//��ʱִ�лص������ļ��ʱ�䣬��λ���룩��Ĭ��ֵΪ3��
		unsigned int calThreads = 2;//�㷨�����߳�����Ĭ��ֵΪ2��

		// �ֶ����л�����
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
				j["baseCorner"] = static_cast<int>(baseCorner);          // ��ʽת��
				j["nestType"] = static_cast<int>(nestType);              // ��ʽת��
				j["enablePriority"] = enablePriority;
				j["priorityType"] = static_cast<int>(priorityType);      // ��ʽת��
				j["higherPriorityPlacedFront"] = higherPriorityPlacedFront;
				j["binCount"] = binCount;
				j["resultTimeOut"] = resultTimeOut;
				j["logLevel"] = logLevel;
				j["jsonResultAsFile"] = jsonResultAsFile;
				j["binValueType"] = static_cast<int>(binValueType);      // ��ʽת��
				j["binValue"] = binValue;
				j["enableExecCbOnTimer"] = enableExecCbOnTimer;
				j["execCbOnTimerInterval"] = execCbOnTimerInterval;
				j["calThreads"] = calThreads;
			}
			catch (const std::exception& e) {
				std::cout << "���л�����: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//����
	struct KNPACKING Vertex {
		double x;//x����
		double y;//y����
		double bulge = 0.0;//͹��ֵ

		// �ֶ����л�����
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				j["x"] = x;
				j["y"] = y;
				j["bulge"] = bulge;
			}
			catch (const std::exception& e) {
				std::cout << "���л�����: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//���/С�������
	struct KNPACKING NestPart {
		unsigned long num;//Ψһ���֣���ʼ��ʱָ�������涼����䣨�������Ϊ˳��ţ�
		std::string code;//Ψһ���루�ַ����͵�Ψһ���룩
		double length;//�峤
		double width;//���
		unsigned long quantity;//����
		bool texture;//�Ƿ�Ҫ������(false������Ҫ��-����ʾ����������ת  true������Ҫ��-����ʾ������ת����ֻ����ת180��)
		std::vector<Vertex> outer;//������
		std::vector<std::vector<Vertex>> inners;//������
		std::vector<Vertex> outerPreserved;//����Ԥ���ռ����������û��Ԥ���ռ�ʱ����ֵΪ��
		unsigned long priority = 0;//���ȼ���Ĭ��Ϊ0

		// �ֶ����л�����
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

				// ����������
				nlohmann::json outerJson = nlohmann::json::array();
				for (const auto& vertex : outer) {
					outerJson.push_back(vertex.toJson());
				}
				j["outer"] = outerJson;

				// ��������������ά���飩
				nlohmann::json innersJson = nlohmann::json::array();
				for (const auto& innerContour : inners) {
					nlohmann::json innerJson = nlohmann::json::array();
					for (const auto& vertex : innerContour) {
						innerJson.push_back(vertex.toJson());
					}
					innersJson.push_back(innerJson);
				}
				j["inners"] = innersJson;

				// ����Ԥ������
				nlohmann::json outerPreservedJson = nlohmann::json::array();
				for (const auto& vertex : outerPreserved) {
					outerPreservedJson.push_back(vertex.toJson());
				}
				j["outerPreserved"] = outerPreservedJson;

			}
			catch (const std::exception& e) {
				std::cout << "NestPart���л�����: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//�㷨��ز���
	struct KNPACKING AlgorithmParameter {
		unsigned char nestType = 0;//Ƕ�׼�������ͣ�0 ��ʾ��Ƕ�ף�1 ��ʾ������Ƕ�ף�2 ��ʾ��������Ƕ��
		unsigned char baseCorner = 1;//�Ż��Ķѻ����䣬1��ʾ���½ǣ�2��ʾ���½ǣ�3��ʾ���Ͻǣ�4��ʾ���Ͻ�
		bool enablePriority = false;//�Ƿ����ð����Ű����ȼ������ȼ���ֵĬ����0��
		unsigned char priorityType = 1;//���ȼ����� 1��ʾ���ȼ�����0�ľ�����ǰ��2��ʾ���ȼ�����0�ľ��Կ�ǰ
		bool higherPriorityPlacedFront = false;//����е�С��������ȼ�����ʱ���ô�忿ǰ���ǿ���, true �����ǰ�棬false ����ں���
		int resultTimeOut = -1;//�õ��Ż�����󣬵ȴ��೤ʱ����(����)�����Ż�����仯�����㷨ֹͣ���У���Ϊ-1��ʾ�����ƣ���һֱ�ȴ�
		bool jsonResultAsFile = false;//�Ƿ�����������Ϊ�ļ���Ĭ��ֵΪfalse��false��ʾNestOutput��jsonResult�����з������json�ַ���(NestOutput)��true��ʾ��NestOutput��Ӧ��json����Ϊ�ļ������ҽ���json�ļ�·�����뵽jsonResult��
		unsigned char binValueType = 1;//����ֵ���ͣ�����������ǰ��ռ۸񣬵�Ϊ�ջ���Ϊ1��ʾ����������ǿ���Ϊ2��ʾ���ռ۸�
		bool enableExecCbOnTimer = false;//�Ƿ������˶���ִ�лص�������Ĭ��Ϊfalse������
		unsigned int execCbOnTimerInterval = 3;//��ʱִ�лص������ļ��ʱ�䣬��λ���룩��Ĭ��ֵΪ3��
		unsigned int calThreads = 2;//�㷨�����߳�����Ĭ��ֵΪ2��

		// �ֶ����л�����
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				// ע�⣺nestType �п���Ϊ�ַ� '0'������JSON�����Ǵ洢Ϊ��ֵ
				// ����뱣���ַ����ԣ����Ը�Ϊ j["nestType"] = std::string(1, nestType);
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
					j["nestType"] = static_cast<int>(nestType);  // �������ת��Ϊ��ֵ
				}
				j["baseCorner"] = static_cast<int>(baseCorner);          // ��ʽת��
				j["enablePriority"] = enablePriority;
				j["priorityType"] = static_cast<int>(priorityType);        // unsigned char ��ʽת��
				j["higherPriorityPlacedFront"] = higherPriorityPlacedFront;
				j["resultTimeOut"] = resultTimeOut;
				j["jsonResultAsFile"] = jsonResultAsFile;
				j["binValueType"] = static_cast<int>(binValueType);        // unsigned char ��ʽת��
				j["enableExecCbOnTimer"] = enableExecCbOnTimer;
				j["execCbOnTimerInterval"] = execCbOnTimerInterval;
				j["calThreads"] = calThreads;
			}
			catch (const std::exception& e) {
				std::cout << "AlgorithmParameter���л�����: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//��������
	struct KNPACKING BinParameter {
		std::string material;//����
		float thickness;//���
		float trimL;//���ޱ�
		float trimR;//���ޱ�
		float trimT;//���ޱ�
		float trimB;//���ޱ�
		float spacing;//С���/���֮��ļ��
		double binLength;//ԭ���ϴ�峤��
		double binWidth;//ԭ���ϴ����
		unsigned long binCount;//ԭ���ϴ���Ӧ������
		double binValue;//ԭ���ϴ���Ӧ�ļ۸�

		// �ֶ����л�����
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
				std::cout << "BinParameter���л�����: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//�Ż��㷨��������
	struct KNPACKING NestInputData {
		OptParameter param;//�Ż�����
		//std::vector<GroupInfo> groupInfos;//����Ϣ�б�
		//std::vector<WsPart> partOfGroups;//����Ϣ�б��ýڵ��µ�part��������groupCode����ǿ�

		//�����������ԭ�����ԣ�����������ǽ�����������
		//ԭ�нṹ�������Լ�����ǰ�����ݡ��µ��������ݸ��ݰ汾version��ֵ�����֣����統�汾��Ϊ1ʱ���Ż���ز�����algorithmParam�л�ȡ��������ز������bins�л�ȡ���Ӷ�֧�ֶ�ԭƬ-�����Ż�ʱ�����������ж����ͬ�Ĵ�壩
		unsigned short version = 1;//�汾
		std::vector<NestPart> parts;//���/С����б�
		AlgorithmParameter algorithmParam;//�Ż�����
		std::vector<BinParameter> bins;//ԭ���ϰ��/����б�

		// �ֶ����л�����
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				j["param"] = param.toJson();
				j["version"] = version;

				// ���л� parts ����
				nlohmann::json partsArray = nlohmann::json::array();
				for (const auto& part : parts) {
					partsArray.push_back(part.toJson());
				}
				j["parts"] = partsArray;

				j["algorithmParam"] = algorithmParam.toJson();

				// ���л� bins ����
				nlohmann::json binsArray = nlohmann::json::array();
				for (const auto& bin : bins) {
					binsArray.push_back(bin.toJson());
				}
				j["bins"] = binsArray;
			}
			catch (const std::exception& e) {
				std::cout << "NestInputData ���л�����: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
	//�Ż��㷨����(����ṹ)
	struct KNPACKING NestInput {
		unsigned short version = 1;//�汾
		NestInputData data;//�Ż��������������

		// �ֶ����л�����
		nlohmann::json toJson() const {
			nlohmann::json j;
			try {
				j["version"] = version;
				j["data"] = data.toJson();
			}
			catch (const std::exception& e) {
				std::cout << "NestInput���л�����: " << e.what() << std::endl;
			}
			return j;
		}

		std::string toJsonString() const {
			return toJson().dump();
		}
	};
}