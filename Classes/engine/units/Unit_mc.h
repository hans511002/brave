#ifndef UNITS_UNIT_MC_H
#define UNITS_UNIT_MC_H
#include "BaseHeaders.h"

namespace engine
{
	class World;
	class ShootBase :public BaseNode
	{
	public:
		int  fireBulletCounter; //public var fireBulletCounter:int = 0;
		int  iceBulletCounter; //public var iceBulletCounter:int = 0;
		int  levinBulletCounter; //public var levinBulletCounter:int = 0;
		float radius; //public var radius:Number;

	};

	namespace units
	{
		class Unit;
		class Unit_mc :public MovieClip
		{
		public:
			Common::HashTable2<string, int> attrFlag;
			Unit * unit;
			int typeUnit;
			string contName;
			MovieClip * levinDeath;//闪电击中死亡效果
			MovieClip * stoneDeath;//石头击中死亡效果
			MovieClip * iceDeath;//冰击中死亡效果
			MovieClip * buffHP;//加血buff生效效果
			MovieClip * airShock;//airshock生效效果 
			MovieClip * buffSpeed;//加速buff生效效果
			MovieClip * dust1;
			MovieClip * dust2;
			MovieClip * dust3;
			MovieClip * fireAttack;//普通火击中效果
			MovieClip * iceAttack; //冰击中效果
			MovieClip * levinAttack;//闪电击中效果
			MovieClip * iceFreez;//被技能冰人攻击效果  两个动作：iceman活着:icemanlive  iceman死亡:icemandead  （活着对应前45帧）
			MovieClip * fireEffect;//特殊火攻击效果 两个动作：攻击开始:begin(只播一次)  攻击持续:continue(重复） 开始播完再重复播持续（开始对应前19帧）
			MovieClip * iceEffect;//特殊冰攻击效果 两个动作：攻击开始:begin(只播一次)  攻击持续:continue(重复） 开始播完再重复播持续（开始对应前15帧）
			MovieClip * armor;
			MovieClip * healthBar;//血条
			MovieClip * shadow;
			MovieClip * selectUnit;
			MovieClip * dust4;
			MovieClipSub * cont;
			MCCase * unitCase;

			Sprite * healthBarGetDamage;
			Sprite * healthBarCont;
			int healthBarCounter;

			int iceDeathFlag;
			int stoneDeathFlag;
			int levinDeathFlag;

			// 18 19
			MovieClipSub * signal;

			//28
			MovieClipSub * giveHealth1;
			MovieClipSub * giveHealth2;
			MovieClipSub * giveHealth3;

			//29 30
			MovieClipSub * dustAnima;

			//25
			MovieClipSub * maskCont;

			cocos2d::Point myFirstPoint, coordOrigin;


			Unit_mc(Unit* unit, string contName, int typeUnit);
			void mcHandler(cocos2d::EventCustom *event);
			bool init();
			void stop();
		};

	}
}
#endif
