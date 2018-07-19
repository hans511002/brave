#include "FileUtil.h"
#include "I18n.h"
#include "I18n.h"


namespace sys
{
	I18n::I18n()
	{
		doc = new rapidjson::Document();
		doc->SetObject();
		int res=JsonUtil::readFile(doc, std::FileUtil::getFilePath("res/i18n/cn.json"));
		if (res != 0) {
			exit(res);
		}
		//SetValueByPointer(d, "/project", "RapidJSON");
		//SetValueByPointer(d, "/stars", 10);
		//if (Value* stars = GetValueByPointer(d, "/stars"))
		//	stars->SetInt(stars->GetInt() + 1);
		//CreateValueByPointer(d, "/a/b/0");
		//Value& hello = GetValueByPointerWithDefault(d, "/hello", "world");
		//Value x("C++");
		//SwapValueByPointer(d, "/hello", x);
		//bool success = EraseValueByPointer(d, "/a");
		//assert(success);
	};
	I18n::~I18n() {
		delete doc;
		doc = NULL;
	}
}