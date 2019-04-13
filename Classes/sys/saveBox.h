#ifndef SAVEBOX_H
#define SAVEBOX_H
//#include "BaseHeaders.h"
#include "JsonUtil.h"

//#include "engine/xml/XmlConfigParser.h"
#include "bezierBox.h"

namespace sys
{
	struct Config {
		rapidjson::Document systemConfig;
		Config();
		Config(string file, bool savet = false);
		void save();
		bool savett;
		string file;
		void setSave(string file, bool savet=false);
		void init();

		template <class T = int> void setValue(string namePath, T val) {
			JsonUtil::setValue<T>(systemConfig, namePath, val);
			if(savett)
                save();
		};
		template <class T = int> void setValue(string namePath, int idx, T val) {
			JsonUtil::setValue<T>(systemConfig, namePath, idx, val);
			if (savett)save();
		};
		inline rapidjson::Value * getValue(string namePath) {
 			return rapidjson::getValue(&systemConfig, namePath);
		}
		inline bool HasMember(string namePath) {
			return getValue(namePath) != NULL;
		}
		bool getBoolValue(string namePath) {
			return JsonUtil::getBoolValue(&systemConfig, namePath);
		};
		int getIntValue(string namePath ) {
			return JsonUtil::getIntValue(&systemConfig, namePath);
		};
		long long getLLongValue(string namePath ) {
			return JsonUtil::getLLongValue(&systemConfig, namePath);
		};
		double getDoubleValue(string namePath ) {
			return JsonUtil::getDoubleValue(&systemConfig, namePath);
		};
		const char* getCharsValue(string namePath ) {
			return JsonUtil::getCharsValue(&systemConfig, namePath);
		};
		string getStringValue(string namePath ) {
			return JsonUtil::getStringValue(&systemConfig, namePath);
		};
	};
	extern Config sysConf;

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
			JsonUtil::setValue<T>(*getDoc(0), namePath, val);
		};
		template <class T = int> void setValue(string namePath, int idx, T val){
			JsonUtil::setValue<T>(*getDoc(0), namePath, idx, val);
		};
		template <class T = int> void setValue(int save,string namePath, T val) {
			JsonUtil::setValue<T>(*getDoc(save), namePath, val);
		};
		template <class T = int> void setValue(int save, string namePath, int idx, T val) {
			JsonUtil::setValue<T>(*getDoc(save), namePath, idx, val);
		};

		bool eraseValue(  string namePath){
			return JsonUtil::eraseValue(*gameSave, namePath);
		};
		bool eraseValue(string namePath, int idx){
			return JsonUtil::eraseValue(*gameSave, namePath, idx);
		};
		inline rapidjson::Document * getDoc(int save) {
			if (save == 1)return gameSave1;
			else if (save == 2)return gameSave2;
			else if (save == 3)return gameSave3;
			else if (save == 4)return gameSave4;
			else if (save == 5)return gameSave5;
			else if (save == 6)return gameSave6;
			else return gameSave;
		};
		inline rapidjson::Document * getDoc(rapidjson::Document * save) {
			if (save)return save;
			else return gameSave;
		}
		inline rapidjson::Value * getValue(string namePath, rapidjson::Document * save = NULL){
			if (!getDoc(save))return NULL;
			return rapidjson::getValue(getDoc(save), namePath);
		}
		//gameSave.data.upgradeGolem5
		inline bool HasMember(string namePath, rapidjson::Document * save = NULL){
		    return getValue(namePath, save)!=NULL;
		}
		bool getBoolValue(string namePath, rapidjson::Document * save = NULL){
			return JsonUtil::getBoolValue(getDoc(save), namePath);
		};
		int getIntValue(string namePath, rapidjson::Document * save = NULL){
			return JsonUtil::getIntValue(getDoc(save), namePath);
		};
		long long getLLongValue(string namePath, rapidjson::Document * save = NULL){
			return JsonUtil::getLLongValue(getDoc(save), namePath);
		};
		double getDoubleValue(string namePath, rapidjson::Document * save = NULL){
			return JsonUtil::getDoubleValue(getDoc(save), namePath);
		};
		const char* getCharsValue(string namePath, rapidjson::Document * save = NULL){
			return JsonUtil::getCharsValue(getDoc(save), namePath);
		};
		string getStringValue(string namePath, rapidjson::Document * save = NULL){
			return JsonUtil::getStringValue(getDoc(save), namePath);
		};
		//数组
		int getLength(string namePath, int save = 0) {
			rapidjson::Value * a = JsonUtil::getValue(getDoc(save), namePath);
			if (!a)return 0;
			if (a->IsArray()) {
				rapidjson::Value::Array arr = a->GetArray();
				return arr.Size();
			}
			return 0; 
		};
	 
		bool getBoolValue(string namePath, int idx, int save = 0){
			return JsonUtil::getBoolValue(getDoc(save), namePath, idx);
		};
		int getIntValue(string namePath, int idx, int save = 0){
			return JsonUtil::getIntValue(getDoc(save), namePath, idx);
		};
		long long getLLongValue(string namePath, int idx, int save = 0){
			return JsonUtil::getLLongValue(getDoc(save), namePath, idx);
		};
		double getDoubleValue(string namePath, int idx, int save = 0){
			return JsonUtil::getDoubleValue(getDoc(save), namePath,idx);
		};
		string getStringValue(string namePath, int idx, int save = 0){
			return JsonUtil::getStringValue(getDoc(save), namePath, idx);
		};
		const char* getCharsValue(string namePath, int idx, int save = 0){
			return JsonUtil::getCharsValue(getDoc(save), namePath, idx);
		};

		
		
		void  checkSaves(int param1) ;

		void updateSever() ;

		void siteSaveConvertionToLocal(int param1);

		void siteSaveConvertionToServer(int param1)  ;

		void synchronizationLocalToSite(int param1) ;// end function

	};


}
#endif
