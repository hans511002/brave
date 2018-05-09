#ifndef UNITS_UNIT_MC_H
#define UNITS_UNIT_MC_H
#include "BaseHeaders.h"
#include "HealthBar.h"

namespace engine
{
	class World;
	namespace units
	{
		class Unit;
		class Unit_mc:public BaseNode {
		public:
			Common::HashTable2<string, int> attrFlag;
			Unit * unit;
			int typeUnit;
			string contName;
			//////////////////////////////////////////////////////////////////////////
			//airshock生效效果 重复播
			MovieClip * airShock;// airshock;//public var airShock : MovieClip;

			//加血buff生效效果 共25帧
			MovieClip * buffHP;// buffhp;//public var buffHP : MovieClip;
			//加速buff生效效果 重复播
			MovieClip * buffSpeed;// buffspeed;//public var buffSpeed : MovieClip;
			//普通火击中效果 只播一次
			MovieClip * fireAttack;// fireattack; public var fireAttack : MovieClip;
			//特殊火攻击效果 两个动作：攻击开始:begin(只播一次)  攻击持续:continue(重复） 开始播完再重复播持续（开始对应前19帧）
			MovieClip  * fireEffect;// fireeffect; //public var fireEffect : MovieClip;
			//特殊冰攻击效果 两个动作：攻击开始:begin(只播一次)  攻击持续:continue(重复） 开始播完再重复播持续（开始对应前15帧）
			MovieClip * iceEffect;// iceeffect;//public var iceEffect : MovieClip;
			//冰击中效果
			MovieClip *iceAttack;// iceattack; // public var iceAttack : MovieClip;
			//闪电击中死亡效果 关键第6帧标记：aa
			MovieClip * levinDeath;// levindeath; public var levinDeath : MovieClip;
			//石头击中死亡效果 关键第3帧标记：aa
			MovieClip * stoneDeath;// stonedeath;//public var stoneDeath : MovieClip;
			//冰击中死亡效果 关键第9帧标记：aa
			MovieClip * iceDeath;// icedeath; public var iceDeath : MovieClip;
			int iceDeathFlag;
			int stoneDeathFlag;
			int levinDeathFlag;
			//重复播
			MovieClip * dust1;
			MovieClip * dust2;
			MovieClip * dust3;
			MovieClip * dust4;
			//闪电击中效果
			MovieClip * levinAttack;// levinattack;//public var levinAttack : MovieClip;
			//被技能冰人攻击效果  两个动作：iceman活着:icemanlive  iceman死亡:icemandead  （活着对应前45帧）
			MovieClip * iceFreez;// icefreeze; public var iceFreez : MovieClip;

			//血条 背景：healthbar_cont 当前进度：healthbar_getdamage
			HealthBar * healthBar;// healthbar; // public var healthBar : MovieClip;
			 
			cocos2d::Sprite * selectUnit;// selectunit; //public var selectUnit : MovieClip;

			MovieClip *cont;// public var cont : MovieClip;


			MovieClip * unitCase;// public var unitCase : MovieClip;
			//MovieClip * shadow;//public var shadow : MovieClip; 合并到cont中了
			MovieClip * armor;//public var armor : MovieClip;
			// 18 19
			MovieClip * signal;
			
			//28
			MovieClip * giveHealth1;
			MovieClip * giveHealth2;
			MovieClip * giveHealth3;
			
			//29 30
			MovieClip * dustAnima;
			
			//25
			MovieClip * maskCont;

			cocos2d::Point myFirstPoint;
            void onExit();
            MovieClipSub * contMcs;
            
			Unit_mc(Unit* unit,string contName, int typeUnit);
			void mcHandler(cocos2d::EventCustom *event);
			bool init();
			void stop();
 		};

	}
}
#endif
