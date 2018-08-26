#include "FileUtil.h"
#include "JsonUtil.h"

namespace rapidjson {

	int readFile(rapidjson::Document * doc, string jsonFile)
	{
		rapidjson::Document &newDoc = *doc;
		//auto File = cocos2d::FileUtils::getInstance();
		//string sFullPath = File->fullPathForFilename(jsonFile);
		//string beffer = File->getStringFromFile(sFullPath);
		//newDoc.Parse(beffer.c_str());
		//if (!newDoc.HasParseError())return 0;
		const auto &data = cocos2d::FileUtils::getInstance()->getDataFromFile(jsonFile);
		//		FILE* myFile = fopen(jsonFile.c_str(), "r");
		if (data.getSize()) {
			//char buf[6556];
			//rapidjson::FileReadStream inputStream(myFile,buf, sizeof(buf));  //创建一个输入流
			newDoc.Parse<kParseStopWhenDoneFlag>(reinterpret_cast<char*>(data.getBytes()));//.ParseStream(inputStream); //将读取的内容转换为dom元素
            //fclose(myFile); //关闭文件，很重要
		}
		if (newDoc.HasParseError()) {
			ifstream ifs(jsonFile);
			IStreamWrapper isw(ifs);
			doc->ParseStream<kParseStopWhenDoneFlag>(isw);
			//log("Json Parse error:%d", newDoc.GetParseError()); //打印错误编号
			if (newDoc.HasParseError())
				return newDoc.GetParseError();
		}
		return 0;
	}
	int writeFile(rapidjson::Document * doc, string jsonFile)
	{
		FILE *fp = fopen( jsonFile.c_str(), "wb");
		char writeBuffer[512];
		rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
		rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
		auto e = doc->Accept(writer);
		fclose(fp);
		return 0;
	}
	inline static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}
	Value * getValue(Value *node, string namePath){
		if (!node)return NULL;
		namePath = Common::String::Trim(namePath, '.');
		std::vector<std::string> elems;
		split(namePath, '.', elems);
		int n = elems.size();
		Value *parVal = node;
		int i = 0;
		while (i < n && parVal){
			const char* name = elems[i].c_str();
			if (parVal->HasMember(name))
			{
				Value & a = parVal->operator[](name);
				if (i == n - 1) {
					return &a;
				}
				if (!a.IsObject()){
					return NULL;
				}
				parVal = &a;
			}
			else{
				return NULL;
			}
		}
		return NULL;
	}
	string toString(Value &node){
		rapidjson::StringBuffer sbBuf;
		rapidjson::Writer<rapidjson::StringBuffer> jWriter(sbBuf);
		node.Accept(jWriter);
		return sbBuf.GetString();
	};


	bool getBoolValue(Value *node, string namePath){
		rapidjson::Value * a = getValue(node,namePath);
		return getBool(a);
	};
	int getIntValue(Value *node, string namePath){
		rapidjson::Value * a = getValue(node, namePath);
		return getInt(a);
	};
	long long getLLongValue(Value *node, string namePath){
		rapidjson::Value * a = getValue(node, namePath);
		return getLLong(a);
	};
	double getDoubleValue(Value *node, string namePath){
		rapidjson::Value * a = getValue(node, namePath);
		return getDouble(a);
	};
	string getStringValue(Value *node, string namePath){
		rapidjson::Value * a = getValue(node, namePath);
		return getString(a);
	}
	const char* getCharsValue(Value *node, string namePath){
		rapidjson::Value * a = getValue(node, namePath);
		return getChars(a);
	};
	 
	bool getBool(Value *a){ 
		if (!a)return false;
		if (a->IsBool()){
			return a->GetBool();
		}
		else if (a->IsString()){
			return Common::String::strcmp(a->GetString(), "true", true);
		}
		else if (a->IsNumber()) {
			return a->GetInt();
		}
		else if (a->IsArray()) {
			return !a->GetArray().Empty();
		}
		return false;
	};
	int getInt(Value *a){
		if (!a)return 0;
		if (a->IsInt()){
			return a->GetInt();
		}
		else if (a->IsString()){
			return atoi(a->GetString());
		}
		else{
			return 0;
		}
	};
	long long getLLong(Value *a){ 
		if (!a)return 0;
		if (a->IsInt64()){
			return a->GetInt64();
		}
		else if (a->IsString()){
			return atoll(a->GetString());
		}
		else{
			return 0;
		}
	};
	double getDouble(Value *a){
		if (!a)return 0;
		if (a->IsDouble()){
			return a->GetDouble();
		}
		else if (a->IsString()){
			return atof(a->GetString());
		}
		else{
			return 0;
		}
	};
	string getString(Value *a){
		if (!a)return "";
		if (a->IsString()){
			return a->GetString();
		}
		else {
			return JsonUtil::toString(*a);
		}
	}
	const char* getChars(Value *a){
		if (!a)return NULL;
		if (a->IsString()){
			return a->GetString();
		}
		else{
			return NULL;
		}
	};


	//˽ة
	bool getBoolValue(Value *node, string namePath, int idx){
		rapidjson::Value * a = getValue(node, namePath);
		if (!a)return false;
		if (a->IsArray()){
			Value::Array arr = a->GetArray();
			if (arr.Size() > idx){
				return getBool(&arr[idx]);
			}
		}
		return false;
	};


	int getIntValue(Value *node, string namePath, int idx){
		rapidjson::Value * a = getValue(node, namePath);
		if (!a)return 0;
		if (a->IsArray()){
			Value::Array arr = a->GetArray();
			if (arr.Size() > idx){
				return getInt(&arr[idx]);
			}
		}
		return 0;
	};
	long long getLLongValue(Value *node, string namePath, int idx){
		rapidjson::Value * a = getValue(node, namePath);
		if (!a)return 0;
		if (a->IsArray()){
			Value::Array arr = a->GetArray();
			if (arr.Size() > idx){
				return getLLong(&arr[idx]);
			}
		}
		return 0;
	};
	double getDoubleValue(Value *node, string namePath, int idx){
		rapidjson::Value * a = getValue(node, namePath);
		if (!a)return 0;
		if (a->IsArray()){
			Value::Array arr = a->GetArray();
			if (arr.Size() > idx){
				return getDouble(&arr[idx]);
			}
		}
		return 0;
	};
	string getStringValue(Value *node, string namePath, int idx){
		rapidjson::Value * a = getValue(node, namePath);
		if (!a)return 0;
		if (a->IsArray()){
			Value::Array arr = a->GetArray();
			if (arr.Size() > idx){
				return getString(&arr[idx]);
			}
		}
		return 0;
	};
	const char * getCharsValue(Value *node, string namePath, int idx){
		rapidjson::Value * a = getValue(node, namePath);
		if (!a)return 0;
		if (a->IsArray()){
			Value::Array arr = a->GetArray();
			if (arr.Size() > idx){
				return getChars(&arr[idx]);
			}
		}
		return 0;
	};

}

 
