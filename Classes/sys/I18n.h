#ifndef I18N_H
#define I18N_H
//#include "BaseHeaders.h"
#include "JsonUtil.h"

namespace sys
{
	class I18n
	{
	public: 
 		rapidjson::Document * doc; 

		I18n();
		~I18n();

		template <class T = int> void setValue(string namePath,T val){
			JsonUtil::setValue<T>(*doc, namePath, val);
		};
		template <class T = int> void setValue(string namePath, int idx, T val){
			JsonUtil::setValue<T>(*doc, namePath, idx, val);
		};

		bool eraseValue(  string namePath){
			return JsonUtil::eraseValue(*doc, namePath);
		};
		bool eraseValue(string namePath, int idx){
			return JsonUtil::eraseValue(*doc, namePath, idx);
		};


		inline rapidjson::Value * getValue(string namePath){
			if (!doc)return NULL;
			return rapidjson::getValue(doc, namePath);
		}
		//doc.data.upgradeGolem5
		inline bool HasMember(string namePath){
		    return getValue(namePath)!=NULL;
		}
		bool getBoolValue(string namePath){
			return JsonUtil::getBoolValue(doc, namePath);
		};
		int getIntValue(string namePath){
			return JsonUtil::getIntValue(doc, namePath);
		};
		long long getLLongValue(string namePath){
			return JsonUtil::getLLongValue(doc, namePath);
		};
		double getDoubleValue(string namePath){
			return JsonUtil::getDoubleValue(doc, namePath);
		};
		const char* getCharsValue(string namePath){
			return JsonUtil::getCharsValue(doc, namePath);
		};
		string getStringValue(string namePath){
			return JsonUtil::getStringValue(doc, namePath);
		};
		string getString(string namePath){
			return JsonUtil::getStringValue(doc, namePath);
		};
		inline const char* operator[](string namePath){
			return JsonUtil::getCharsValue(doc, namePath);
		};
		
		//数组
		bool getBoolValue(string namePath, int idx){
			return JsonUtil::getBoolValue(doc, namePath, idx);
		};
		int getIntValue(string namePath, int idx){
			return JsonUtil::getIntValue(doc, namePath, idx);
		};
		long long getLLongValue(string namePath, int idx){
			return JsonUtil::getLLongValue(doc, namePath, idx);
		};
		double getDoubleValue(string namePath, int idx){
			return JsonUtil::getDoubleValue(doc, namePath,idx);
		};
		string getStringValue(string namePath, int idx){
			return JsonUtil::getStringValue(doc, namePath, idx);
		};
		const char* getCharsValue(string namePath, int idx){
			return JsonUtil::getCharsValue(doc, namePath, idx);
		};
	};

	namespace I18N_CODE
    {
    static const string U001="U001";//:  "击碎者就绪!"
    static const string U002="U002";//:  "一路碾压所有敌人"
    static const string U003="U003";//:  "击碎者重置"
    static const string U004="U004";//:  "冰冻者就绪!"
    static const string U005="U005";//:  "冰冻者重置"
    static const string U006="U006";//:  "一路冻结所有敌人"
    static const string U007="U007";//:  "复活岛巨像就绪!"
    static const string U008="U008";//:  "复活岛巨像重置"
    static const string U009="U009";//:  "将敌人吹飞到后面"
    static const string U010="U010";//:  "范围: "
    static const string U011="U011";//:  " ; 火焰伤害: "
    static const string U012="U012";//:  " ; 寒冰伤害: "
    static const string U013="U013";//:  " ; 岩石伤害: "
    static const string U014="U014";//:  " ; 闪电伤害: "
    static const string U015="U015";//:  " ; 伤害: "
    static const string U016="U016";//:  " 秒"
    static const string U017="U017";//:  "火焰: "
    static const string U018="U018";//:  " ; "
    static const string U019="U019";//:  "寒冰: "
    static const string U020="U020";//:  "岩石: "
    static const string U021="U021";//:  "闪电: "
    static const string U022="U022";//:  "无元素"
    static const string U023="U023";//:  "伤害: "
    static const string U024="U024";//:  " ; 额外伤害: "
    static const string U025="U025";//:  "第一滴血"
    static const string U026="U026";//:  "热烈无比"
    static const string U027="U027";//:  "杀手"
    static const string U028="U028";//:  "毫无畏惧"
    static const string U029="U029";//:  "建造者"
    static const string U030="U030";//:  "巨型支援"
    static const string U031="U031";//:  "缓和"
    static const string U032="U032";//:  "远古支援"
    static const string U033="U033";//:  "大胆"
    static const string U034="U034";//:  "破坏者"
    static const string U035="U035";//:  "火焰破坏者"
    static const string U036="U036";//:  "寒冰破坏者"
    static const string U037="U037";//:  "巨石破坏者"
    static const string U038="U038";//:  "闪电破坏者"
    static const string U039="U039";//:  "粉碎者"
    static const string U040="U040";//:  "有点冷"
    static const string U041="U041";//:  "霜冻力量"
    static const string U042="U042";//:  "进阶建造者"
    static const string U043="U043";//:  "专家建造者"
    static const string U044="U044";//:  "策略建造者"
    static const string U045="U045";//:  "上手"
    static const string U046="U046";//:  "火焰大师"
    static const string U047="U047";//:  "寒冰大师"
    static const string U048="U048";//:  "岩石大师"
    static const string U049="U049";//:  "闪电大师"
    static const string U050="U050";//:  "策略爆破者"
    static const string U051="U051";//:  "爆破者"
    static const string U052="U052";//:  "施法者"
    static const string U053="U053";//:  "法术杀手"
    static const string U054="U054";//:  "勇猛战士"
    static const string U055="U055";//:  "幸存者"
    static const string U056="U056";//:  "活力四射"
    static const string U057="U057";//:  "伐木工"
    static const string U058="U058";//:  "忙忙碌碌"
    static const string U059="U059";//:  "南瓜节"
    static const string U060="U060";//:  "修理工"
    static const string U061="U061";//:  "勇士"
    static const string U062="U062";//:  "睡眼阑珊"
    static const string U063="U063";//:  "超级女声"
    static const string U064="U064";//:  "老烟枪"
    static const string U065="U065";//:  "渔夫"
    static const string U066="U066";//:  "决斗"
    static const string U067="U067";//:  "萨满"
    static const string U068="U068";//:  "疯狂射手"
    static const string U069="U069";//:  "勇猛大头"
    static const string U070="U070";//:  "寻路无门"
    static const string U071="U071";//:  "波次:"
    static const string U072="U072";//:  "杀死 1 名敌人【U77总有好游戏】"
    static const string U073="U073";//:  "在一场游戏中杀死 100 名敌人"
    static const string U074="U074";//:  "杀死 2500 名敌人"
    static const string U075="U075";//:  "提前召唤 100 波次"
    static const string U076="U076";//:  "建造 100 座塔楼"
    static const string U077="U077";//:  "一场任务中召唤 5 次击碎者"
    static const string U078="U078";//:  "一场任务中召唤 15 次冰冻者"
    static const string U079="U079";//:  "一场任务中召唤 7 次复活岛巨像"
    static const string U080="U080";//:  "一场任务中提前召唤所有波次"
    static const string U081="U081";//:  "一场任务中出售所有类型元素"
    static const string U082="U082";//:  "出售 10 次火焰元素【U 7 7 汉化】"
    static const string U083="U083";//:  "出售 10 次寒冰元素"
    static const string U084="U084";//:  "出售 10 次岩石元素"
    static const string U085="U085";//:  "出售 10 次闪电元素"
    static const string U086="U086";//:  "击碎者碾碎 250 个大头"
    static const string U087="U087";//:  "一场任务中冰冻 75 个单位"
    static const string U088="U088";//:  "冰冻者冰冻 500 个大头"
    static const string U089="U089";//:  "建造 1 座超级塔楼"
    static const string U090="U090";//:  "建造 50 座超级塔楼"
    static const string U091="U091";//:  "一场游戏中每种类型建造一座超级塔楼总计 4 座"
    static const string U092="U092";//:  "一场游戏中不召唤任何元素法术【U77总有好游戏】"
    static const string U093="U093";//:  "召唤 150 次火焰元素"
    static const string U094="U094";//:  "召唤 150 次寒冰元素"
    static const string U095="U095";//:  "召唤 150 次岩石元素"
    static const string U096="U096";//:  "召唤 150 次闪电元素"
    static const string U097="U097";//:  "一场游戏中召唤 10 次超级噼里啪啦"
    static const string U098="U098";//:  "召唤 100 次超级噼里啪啦"
    static const string U099="U099";//:  "召唤任意元素杀死 1 名敌人"
    static const string U100="U100";//:  "召唤任意元素杀死 150 名敌人"
    static const string U101="U101";//:  "困难难度下通过 10 关"
    static const string U102="U102";//:  "生存关卡通过 10 关【U 7 7 汉化】"
    static const string U103="U103";//:  "不损失生命值通过 10 关"
    static const string U104="U104";//:  "伙计去伐木"
    static const string U105="U105";//:  "伙计走开"
    static const string U106="U106";//:  "失掉 3 个南瓜"
    static const string U107="U107";//:  "打到伙计的手指"
    static const string U108="U108";//:  "伙计跑到森林里"
    static const string U109="U109";//:  "伙计要起床"
    static const string U110="U110";//:  "一跃入井"
    static const string U111="U111";//:  "牛仔和仙人掌"
    static const string U112="U112";//:  "小鱼钓渔夫【U77总有好游戏】"
    static const string U113="U113";//:  "Injun 杀了牛仔"
    static const string U114="U114";//:  "伙计要召唤闪电"
    static const string U115="U115";//:  "牛仔开始射击"
    static const string U116="U116";//:  "扒光羽毛"
    static const string U117="U117";//:  "伙计应该要坠落深渊"
    static const string U118="U118";//:  "登录使用在线存档"
    static const string U119="U119";//:  "Welcome,"
    static const string U120="U120";//:  "!"
    static const string U121="U121";//:  "Delete save slot?"
    static const string U122="U122";//:  "Are you sure?"
    };
}
#endif
