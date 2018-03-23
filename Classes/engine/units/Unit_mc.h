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
			dragonBones::DBCCArmatureNode * airShock;// airshock;//public var airShock : MovieClip;

			//加血buff生效效果 共25帧
			dragonBones::DBCCArmatureNode * buffHP;// buffhp;//public var buffHP : MovieClip;
			//加速buff生效效果 重复播
			dragonBones::DBCCArmatureNode * buffSpeed;// buffspeed;//public var buffSpeed : MovieClip;
			//普通火击中效果 只播一次
			dragonBones::DBCCArmatureNode * fireAttack;// fireattack; public var fireAttack : MovieClip;
			//特殊火攻击效果 两个动作：攻击开始:begin(只播一次)  攻击持续:continue(重复） 开始播完再重复播持续（开始对应前19帧）
			dragonBones::DBCCArmatureNode * fireEffect;// fireeffect; //public var fireEffect : MovieClip;
			//特殊冰攻击效果 两个动作：攻击开始:begin(只播一次)  攻击持续:continue(重复） 开始播完再重复播持续（开始对应前15帧）
			dragonBones::DBCCArmatureNode * iceEffect;// iceeffect;//public var iceEffect : MovieClip;
			//冰击中效果
			dragonBones::DBCCArmatureNode *iceAttack;// iceattack; // public var iceAttack : MovieClip;
			//闪电击中死亡效果 关键第6帧标记：aa
			dragonBones::DBCCArmatureNode * levinDeath;// levindeath; public var levinDeath : MovieClip;
			//石头击中死亡效果 关键第3帧标记：aa
			dragonBones::DBCCArmatureNode * stoneDeath;// stonedeath;//public var stoneDeath : MovieClip;
			//冰击中死亡效果 关键第9帧标记：aa
			dragonBones::DBCCArmatureNode * iceDeath;// icedeath; public var iceDeath : MovieClip;
			int iceDeathFlag;
			int stoneDeathFlag;
			int levinDeathFlag;
			//重复播
			dragonBones::DBCCArmatureNode * dust1;
			dragonBones::DBCCArmatureNode * dust2;
			dragonBones::DBCCArmatureNode * dust3;
			dragonBones::DBCCArmatureNode * dust4;
			//闪电击中效果
			dragonBones::DBCCArmatureNode * levinAttack;// levinattack;//public var levinAttack : MovieClip;
			//被技能冰人攻击效果  两个动作：iceman活着:icemanlive  iceman死亡:icemandead  （活着对应前45帧）
			dragonBones::DBCCArmatureNode * iceFreez;// icefreeze; public var iceFreez : MovieClip;

			//血条 背景：healthbar_cont 当前进度：healthbar_getdamage
			HealthBar * healthBar;// healthbar; // public var healthBar : MovieClip;
			 
			cocos2d::Sprite * selectUnit;// selectunit; //public var selectUnit : MovieClip;

			dragonBones::DBCCArmatureNode *cont;// public var cont : MovieClip;


			dragonBones::DBCCArmatureNode * unitCase;// public var unitCase : MovieClip;
			dragonBones::DBCCArmatureNode * shadow;//public var shadow : MovieClip;
			dragonBones::DBCCArmatureNode * armor;//public var armor : MovieClip;
			dragonBones::DBCCArmatureNode * signal;
			dragonBones::DBCCArmatureNode * giveHealth1;
			dragonBones::DBCCArmatureNode * giveHealth2;
			dragonBones::DBCCArmatureNode * giveHealth3;
			dragonBones::DBCCArmatureNode * dustAnima;
			
			

			Unit_mc(Unit* unit,string contName, int typeUnit);
			void mcHandler(cocos2d::EventCustom *event);
			bool init();
			void stop();
		};

	}
}
#endif
