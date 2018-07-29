#ifndef SAVEBOX_H
#define SAVEBOX_H
//#include "BaseHeaders.h"
#include "JsonUtil.h"

//#include "engine/xml/XmlConfigParser.h"
#include "bezierBox.h"

namespace sys
{
	/**
	保存数据到本地或服务器，暂时不实现
	*/
	class SaveBox
	{
	public:
		int i;
		int j;
		BezierBox bezierBoxClass;
		rapidjson::Document * gameSave;
		rapidjson::Document *  gameSave1;
		rapidjson::Document *  gameSave2;
		rapidjson::Document * gameSave3;
		rapidjson::Document * gameSave4;
		rapidjson::Document * gameSave5;
		rapidjson::Document *  gameSave6;
		int maxStars;
		int playLevel;

		SaveBox();
		~SaveBox();

		template <class T = int> void setValue(string namePath,T val){
			JsonUtil::setValue<T>(*gameSave, namePath, val);
		};
		template <class T = int> void setValue(string namePath, int idx, T val){
			JsonUtil::setValue<T>(*gameSave, namePath, idx, val);
		};

		bool eraseValue(  string namePath){
			return JsonUtil::eraseValue(*gameSave, namePath);
		};
		bool eraseValue(string namePath, int idx){
			return JsonUtil::eraseValue(*gameSave, namePath, idx);
		};


		inline rapidjson::Value * getValue(string namePath){
			if (!gameSave)return NULL;
			return rapidjson::getValue(gameSave, namePath);
		}
		//gameSave.data.upgradeGolem5
		inline bool HasMember(string namePath){
		    return getValue(namePath)!=NULL;
		}
		bool getBoolValue(string namePath){
			return JsonUtil::getBoolValue(gameSave, namePath);
		};
		int getIntValue(string namePath){
			return JsonUtil::getIntValue(gameSave, namePath);
		};
		long long getLLongValue(string namePath){
			return JsonUtil::getLLongValue(gameSave, namePath);
		};
		double getDoubleValue(string namePath){
			return JsonUtil::getDoubleValue(gameSave, namePath);
		};
		const char* getCharsValue(string namePath){
			return JsonUtil::getCharsValue(gameSave, namePath);
		};
		string getStringValue(string namePath){
			return JsonUtil::getStringValue(gameSave, namePath);
		};
		//数组
		bool getBoolValue(string namePath, int idx){
			return JsonUtil::getBoolValue(gameSave, namePath, idx);
		};
		int getIntValue(string namePath, int idx){
			return JsonUtil::getIntValue(gameSave, namePath, idx);
		};
		long long getLLongValue(string namePath, int idx){
			return JsonUtil::getLLongValue(gameSave, namePath, idx);
		};
		double getDoubleValue(string namePath, int idx){
			return JsonUtil::getDoubleValue(gameSave, namePath,idx);
		};
		string getStringValue(string namePath, int idx){
			return JsonUtil::getStringValue(gameSave, namePath, idx);
		};
		const char* getCharsValue(string namePath, int idx){
			return JsonUtil::getCharsValue(gameSave, namePath, idx);
		};

		
		
		void  checkSaves(int param1) ;

		void updateSever() ;

		void siteSaveConvertionToLocal(int param1);

		void siteSaveConvertionToServer(int param1)  ;

		void synchronizationLocalToSite(int param1) ;// end function

	};


}
#endif
