#ifndef UNITS_UNIT_H
#define UNITS_UNIT_H
#include "BaseHeaders.h"
#include "Unit_mc.h"

namespace engine
{
	class World;
	namespace units
	{
		class Unit :public BaseNode
		{
		public:
			int i, j, n;
			float tempObject;// :Object;
			Bullet * tempObject1;//public var tempObject1:Object;
			//public var tempObject2:Object;
			//public var tempObject3:Object;
			//public var tempObject4:Object;
			//public var tempObject5:Object;
			//public var tempObject6:Object;
			World * world;
			Unit_mc * container;//public var container:MovieClip;
			int road;
			int way;//public var way:int;
			float path;//public var path:Number = 0;
			float finishPath;//public var finishPath:Number;
			cocos2d::Vec2 this_pt; //public var this_pt:Point;
			cocos2d::Vec2 enemy_pt;//public var enemy_pt:Point;
			bool stopAnima;//public var stopAnima:Boolean;
			int typeUnit;//public var typeUnit:int;
			float health;//public var health:Number;
			float healthMax;//public var healthMax:Number;
			float speedK;//public var speedK:Number;
			float speedKSave;//public var speedKSave:Number;
			int gold;//public var gold:int;
			float fireDamageK;//public var fireDamageK:Number;
			float iceDamageK;//public var iceDamageK:Number;
			float stoneDamageK;//public var stoneDamageK:Number;
			float levinDamageK;//public var levinDamageK:Number;
			int penalty;//public var penalty:int;
			bool dead;//public var dead:Boolean;
			string lastAttackType;//public var lastAttackType:String;
			bool atStage;//public var atStage:Boolean;
			bool readyDamage;//public var readyDamage:Boolean = true;
			bool bulletTower6Effect;//public var bulletTower6Effect:Boolean;
			bool airFlag;//public var airFlag:Boolean;
			bool fireLevinKillFlag;//public var fireLevinKillFlag:Boolean;
			string direction;//:String = "无";
			bool moveFlag;//public var moveFlag:Boolean = true;
			cocos2d::Vec2 shoot_pt;// : Point;
			int gate;//public var gate:int = 0;
			bool nextTurnFlag;//public var nextTurnFlag:Boolean;
			cocos2d::Vec2 nextTurnPoint;// : Point;
			float nextTurnPath;//public var nextTurnPath:Number;
			float nextTurnMidPath;//public var nextTurnMidPath:Number;
			Common::Array<int>listOfTornado; //public var listOfTornado:Array;
			//public var teleportAnima:MovieClip;
			bool teleportFlag;//public var teleportFlag:Object;
			bool directionFlag;//public var directionFlag:Boolean;
			bool replaced;//public var replaced:Boolean;
			float speedKRun;//public var speedKRun:Number;
			int speedRunTimerIce1;//public var speedRunTimerIce1:int;
			int speedRunTimerIce2;//public var speedRunTimerIce2:int;
			int speedRunTimerIce3;//public var speedRunTimerIce3:int;
			int speedRunTimerIce4;//public var speedRunTimerIce4:int;
			//public var myParent:Object;
			bool healthPlusFlag;//public var healthPlusFlag:Boolean;
			float healthPlusValue;//public var healthPlusValue:Number = 0;
			bool armorFlag;//public var armorFlag:Boolean;
			float armorPower;//public var armorPower:Number = 0;
			int armorCounter;//public var armorCounter:int = 0;
			bool airShockFlag;//public var airShockFlag:Boolean;
			int airShockCounter;//public var airShockCounter:int = 0;
			bool speedPlusFlag;//public var speedPlusFlag:Boolean;
			int speedPlusCounter;//public var speedPlusCounter:int = 0;
			float speedPlusValue;//public var speedPlusValue:Number = 0;
			int airGo;//public var airGo:int = 0;
			int airWaitTimer;
			float airSpacing;//public var airSpacing:Number;
			float airPower;//public var airPower:Number;
			float airResist;//public var airResist:Number;
			float dampingAir;//public var dampingAir:Number;
			float traversedPath;//public var traversedPath:Number;
			bool icemanFlag;//public var icemanFlag:Boolean;
			int icemanCounter;//public var icemanCounter:int = 0;
			float icemanResist;//public var icemanResist:Number;
			bool fireEffectFlag;//public var fireEffectFlag:Boolean;
			int fireEffectCounter;//public var fireEffectCounter:int = 0;
			float fireEffectDamage;//public var fireEffectDamage:Number = 0;
			bool iceEffectFlag;//public var iceEffectFlag:Boolean;
			int iceEffectCounter;//public var iceEffectCounter:int = 0;
			float iceEffectSlowdown;//public var iceEffectSlowdown:Number = 0;
			int replacementFlag;//public var replacementFlag:int;
			int replacementCount;//public var replacementCount:int;
			bool mainMoveFlag;//public var mainMoveFlag:Boolean = true;

			int stealthCounter;
			 


			Unit() :direction("none"), world(NULL), road(0), way(0), path(0), finishPath(0), stopAnima(false), typeUnit(0), health(0), healthMax(0), speedK(0), speedKSave(0),
				gold(0), fireDamageK(0), iceDamageK(0), stoneDamageK(0), levinDamageK(0), penalty(0), dead(false), atStage(false), readyDamage(true), 
				bulletTower6Effect(false), airFlag(false), fireLevinKillFlag(false), moveFlag(true),gate(0), nextTurnFlag(false), nextTurnPath(0), nextTurnMidPath(0),
				teleportFlag(false), directionFlag(false), replaced(false), speedKRun(0),speedRunTimerIce1(0), speedRunTimerIce2(0), speedRunTimerIce3(0),
				speedRunTimerIce4(0),healthPlusFlag(false),healthPlusValue(0),armorFlag(false),armorPower(0),armorCounter(0),airShockFlag(false),airShockCounter(0),
				speedPlusFlag(false),speedPlusCounter(0),speedPlusValue(0),airGo(0),airWaitTimer(0),airSpacing(0),airPower(0),airResist(0),dampingAir(0),traversedPath(0),
				icemanFlag(false),icemanCounter(0),icemanResist(0),fireEffectFlag(false),fireEffectCounter(0),fireEffectDamage(0),iceEffectFlag(false),iceEffectCounter(0),
				iceEffectSlowdown(0),replacementFlag(0),replacementCount(0),mainMoveFlag(true),stealthCounter(0)

			{
				 
			}// end function

			bool init();
			 
			void update(float dt);

			void moveHandler();

			void directionManage();

			void scanNextTurn();

			void setVerticalTurn();

			void setTurn(string param1);

			void atStageManage();

			void animationHandler();

			////public function getHit(param1:Number, param2:String = "无", param3:int = 0, param4:Boolean = false, param5:int = 0, param6:Object = null) : void
			void getHit(float param1, string param2 = "none", int  param3 = 0, bool param4 = false, int param5 = 0, void * param6 = NULL);

			void setAirSettings(string param1);

			void stopAllEffects(string param1 = "");

			void removeUnitAfterDeathAnima();

			void kill();

		};
	}
}
#endif
