#ifndef UNITS_UNIT_H
#define UNITS_UNIT_H
#include "BaseHeaders.h"
#include "Unit_mc.h"
#include "engine/Waves.h"
#include "engine/World.h" 
#include "engine/bullets/Bullet.h" 

namespace engine
{
 
	//class WaveData;
	struct MouseStatusMC :public MovieClip
	{
		int mouseStatus;
		inline MouseStatusMC(string rootPath, string armName, string dbName, string defAniName = "") :mouseStatus(0), MovieClip(rootPath, armName, dbName, defAniName){
		};
		
	};
	struct NewEnemy_mc :public MouseStatusMC
		{
			MCCase* newEnemyCase;
			int typeUnit;
			NewEnemy_mc();
		};
	struct NewElement_mc :public MouseStatusMC
		{
			MCCase *newElementCase;
			int type;
			NewElement_mc();
		};
	namespace units
	{
		class Unit;
		struct Roadsign_mc : public MovieClip
		{
			float myPath;
			int myRoad, myWay;
			Common::Array<Unit *> myStack;
			cocos2d::Point myPoint;
			bool repeatFlag;
			int repeatCounter;
			inline Roadsign_mc(string path, string arm, string dbName) :MovieClip(path, arm, dbName){};
		};
		struct RoadsignFire_mc : public Roadsign_mc
		{
			inline RoadsignFire_mc() :Roadsign_mc("worldinterface/", "RoadsignFire_mc", "RoadsignFire_mc"){
				SET_NODETYPENAME();
			};
		};
		struct RoadsignIce_mc : public Roadsign_mc
		{
			inline RoadsignIce_mc() :Roadsign_mc("worldinterface/", "RoadsignIce_mc", "RoadsignIce_mc"){
				SET_NODETYPENAME();
			};
		};
		struct RoadsignStone_mc : public Roadsign_mc
		{
			inline RoadsignStone_mc() :Roadsign_mc("worldinterface/", "RoadsignStone_mc", "RoadsignStone_mc"){
				SET_NODETYPENAME();
			};
		};
		struct RoadsignLevin_mc : public Roadsign_mc
		{
			inline RoadsignLevin_mc() :Roadsign_mc("worldinterface/", "RoadsignLevin_mc", "RoadsignLevin_mc"){
				SET_NODETYPENAME();
			};
		};
		class Unit :public ShootBase
		{
		public:
			int i, j, n;
			float resLen;// tempObject:Object;
			bool resFlag;//public var tempObject1:Object;
			BulletTower71_mc * bulltTower71Mc;
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
			//cocos2d::Vec2 this_pt; //public var this_pt:Point;
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
			//bool atStage;//public var atStage:Boolean;
			bool readyDamage;//public var readyDamage:Boolean = true;
			bool bulletTower6Effect;//public var bulletTower6Effect:Boolean;
			bool airFlag;//public var airFlag:Boolean;
			bool fireLevinKillFlag;//public var fireLevinKillFlag:Boolean;
			string direction;//:String = "none";
			bool moveFlag;//public var moveFlag:Boolean = true;
			cocos2d::Vec2 shoot_pt;// : Point;
			int gate;//public var gate:int = 0;
			bool nextTurnFlag;//public var nextTurnFlag:Boolean;
			cocos2d::Vec2 nextTurnPoint;// : Point;
			float nextTurnPath;//public var nextTurnPath:Number;
			float nextTurnMidPath;//public var nextTurnMidPath:Number;
			Common::Array<int>listOfTornado; //public var listOfTornado:Array;
			MovieClip * teleportAnima;
			bool teleportFlag;//public var teleportFlag:Object;
			Unit* teleportFlagObj;//public var teleportFlag:Object;
			bool directionFlag;//public var directionFlag:Boolean;
			bool replaced;//public var replaced:Boolean;
			float speedKRun;//public var speedKRun:Number;
			int speedRunTimerIce1;//public var speedRunTimerIce1:int;
			int speedRunTimerIce2;//public var speedRunTimerIce2:int;
			int speedRunTimerIce3;//public var speedRunTimerIce3:int;
			int speedRunTimerIce4;//public var speedRunTimerIce4:int;
			Unit * myParent;//public var myParent:Object;
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

			// 18 19
			bool hiddenFlag;
			int invisibleCounter, invisibleTimer, visibleCounter, visibleTimer;
			int newEnemyCounter;//20
			bool atStaged;

			int blockTowerRadius;//22

			bool removed;

			inline Unit() :direction("none"), world(NULL), road(0), way(0), path(0), finishPath(0), stopAnima(false), typeUnit(0), health(0), healthMax(0), speedK(0), speedKSave(0),
				gold(0), fireDamageK(0), iceDamageK(0), stoneDamageK(0), levinDamageK(0), penalty(0), dead(false), readyDamage(true),
				bulletTower6Effect(false), airFlag(false), fireLevinKillFlag(false), moveFlag(true), gate(0), nextTurnFlag(false), nextTurnPath(0), nextTurnMidPath(0),
				teleportFlag(false), directionFlag(false), replaced(false), speedKRun(0), speedRunTimerIce1(0), speedRunTimerIce2(0), speedRunTimerIce3(0),
				speedRunTimerIce4(0), healthPlusFlag(false), healthPlusValue(0), armorFlag(false), armorPower(0), armorCounter(0), airShockFlag(false), airShockCounter(0),
				speedPlusFlag(false), speedPlusCounter(0), speedPlusValue(0), airGo(0), airWaitTimer(0), airSpacing(0), airPower(0), airResist(0), dampingAir(0), traversedPath(0),
				icemanFlag(false), icemanCounter(0), icemanResist(0), fireEffectFlag(false), fireEffectCounter(0), fireEffectDamage(0), iceEffectFlag(false), iceEffectCounter(0),
				iceEffectSlowdown(0), replacementFlag(0), replacementCount(0), mainMoveFlag(true), stealthCounter(0), hiddenFlag(false),
				invisibleCounter(0), invisibleTimer(0), visibleCounter(0), visibleTimer(0), newEnemyCounter(0), atStaged(false), teleportAnima(NULL), blockTowerRadius(0), teleportFlagObj(0), bulltTower71Mc(NULL)
			{

			}// end function

			virtual bool init();

			virtual void update(float dt=0);

			virtual void moveHandler();

			virtual void directionManage();

			virtual void scanNextTurn();

			virtual void setVerticalTurn();

			virtual void setTurn(string param1);

			virtual void atStageManage();

			virtual void animationHandler();

			////public function getHit(param1:Number, param2:String = "无", param3:int = 0, param4:Boolean = false, param5:int = 0, param6:Object = null) : void
			virtual bool getHit(float param1, string param2 = "none", int  param3 = 0, bool param4 = false, int param5 = 0, ShootBase * param6 = NULL);

			virtual void setAirSettings(string param1);

			virtual void stopAllEffects(string param1 = "");

			virtual void removeUnitAfterDeathAnima();

			virtual void kill();
			virtual void remove();

			//virtual void onExit();
		};

#define UNIT_CLASS_DEFINE(unitName,MEMBER_DEFINE) struct unitName :public Unit{ \
public:\
	inline unitName() { SET_NODETYPENAME();	}; \
	virtual bool init(); \
	virtual void animationHandler(); \
	MEMBER_DEFINE \
		};

		UNIT_CLASS_DEFINE(Unit_1,);
		UNIT_CLASS_DEFINE(Unit_2,);
		UNIT_CLASS_DEFINE(Unit_3,);
		UNIT_CLASS_DEFINE(Unit_4,);
		UNIT_CLASS_DEFINE(Unit_5,);
		UNIT_CLASS_DEFINE(Unit_6,);
		UNIT_CLASS_DEFINE(Unit_7,);
		UNIT_CLASS_DEFINE(Unit_8,);
		UNIT_CLASS_DEFINE(Unit_9, );
		UNIT_CLASS_DEFINE(Unit_10,);
		UNIT_CLASS_DEFINE(Unit_11,);
		UNIT_CLASS_DEFINE(Unit_12,);
		UNIT_CLASS_DEFINE(Unit_13,);
		UNIT_CLASS_DEFINE(Unit_14,);
		UNIT_CLASS_DEFINE(Unit_15,);
		UNIT_CLASS_DEFINE(Unit_16,);
		UNIT_CLASS_DEFINE(Unit_17, );
		UNIT_CLASS_DEFINE(Unit_18,);
		UNIT_CLASS_DEFINE(Unit_19, );
		UNIT_CLASS_DEFINE(Unit_20, virtual void kill(););
		UNIT_CLASS_DEFINE(Unit_21, virtual void kill(););
		UNIT_CLASS_DEFINE(Unit_22, int blockTowerRadius; MovieClip * blockRadiusGr; bool greenFlag; cocos2d::Point testTarget; virtual void scanAtRadius(); virtual void remove(););

		UNIT_CLASS_DEFINE(Unit_23, RoadsignFire_mc * myPortal; MovieClip * portalAnima; virtual void kill(););
		UNIT_CLASS_DEFINE(Unit_24, RoadsignIce_mc * myPortal; MovieClip * portalAnima; virtual void kill(););
		UNIT_CLASS_DEFINE(Unit_25, RoadsignStone_mc * myPortal; MovieClip * portalAnima; virtual void kill(); virtual void update(float dt=0););
		UNIT_CLASS_DEFINE(Unit_26, RoadsignLevin_mc * myPortal; MovieClip * portalAnima; virtual void kill(););
		UNIT_CLASS_DEFINE(Unit_27, int teleportPhase; int teleportTimer; int teleportCounter; int teleportStealthTimer; int teleportStealthCounter; float teleportDistance; float teleportRadius; Common::Array<Unit*> listOfTeleportUnits; int soundCounter; int soundTimer; int soundTimer1; int teleportUnitsMax; int teleportUnitsCounter; virtual void kill(););
		UNIT_CLASS_DEFINE(Unit_28, float giveHealthRadius; int giveHeathCounter; int giveHeathTimer; float giveHeath;);
		UNIT_CLASS_DEFINE(Unit_29, float returnHealth; int stealthCounter; int stealthTimer; int phase; virtual void remove(););
		UNIT_CLASS_DEFINE(Unit_30, float returnHealth; int stealthCounter; int stealthTimer; int phase; virtual void kill(););
		UNIT_CLASS_DEFINE(Unit_31, float distanceX; float distanceY; int counter; bool firstView; virtual void moveHandler(););
		UNIT_CLASS_DEFINE(Unit_32, float distanceX; float distanceY; int counter; bool firstView; virtual void moveHandler(););
		UNIT_CLASS_DEFINE(Unit_33, float distanceX; float distanceY; int counter; bool firstView; virtual void moveHandler(););
		UNIT_CLASS_DEFINE(Unit_34, int phase; int teleportStatus; bool eyesFlag; int eyesCounter; int eyesCounter1; int eyesCounter2; ReadXML * readXML; int phaseRoad1; int phaseRoad2; bool giveArmorFlag; bool takeAwayCastsFlag; string changeRoad; bool speakFlag; int notAtRoad; int musicVolumeManageCounter; bool greenFlag;  Common::Array<engine::WaveData<int> > arrayTurn; int callUnitsCounter; bool roadFlag; virtual void kill(););
	}
}
#endif
