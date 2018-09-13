#ifndef ENGINE_WORLDINTERFACE_H
#define ENGINE_WORLDINTERFACE_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"
//#include "MainClass.h"
//#include "World.h"
#include "JsonUtil.h"
#include "Feature.h"
#include "WorldInterface_mc.h"
#include "screens/Screen.h"
 
namespace engine
{ 
 
	class  WorldInterface :public screens::Screen
	{
	public:
		int i;
		//public var tempObject:Object;
		//public var tempObject1:Object;
		//public var tempObject2:Object;
		WorldInterface_mc *container; //public var container:WorldInterface_mc;
		int fasterFlag;//int fasterFlag;////public var fasterFlag:int = 0;
		World * world;//public var world:World;
		CastMask_mc* castMask;
		Common::Array<int>   sphereCostHistory[4];//Common::Array<Common::Array<int> >  sphereCostHistory;//public var sphereCostHistory:Array;
		Common::Array<MouseStatusMC *> listOfNewEnemies;//public var listOfNewEnemies:Array;
		MCText * lastTime;//public var lastTime:TextField;
		Common::Array<GetAchieve_mc *> listOfGetAhieve;//public var listOfGetAhieve:Array;
		Common::Array<MovieClip *> listOfAnimation;//public var listOfAnimation:Array;
		Hint_mc * sellHint;
		Hint_mc * getAllHint;
		int fireCount;////public var fireCount:int = 0;
		int iceCount;////public var iceCount:int = 0;
		int stoneCount;////public var stoneCount:int = 0;
		int levinCount;////public var levinCount:int = 0;
		int getAllCount;////public var getAllCount:int = 0;
		int fireBuyHistory;////public var fireBuyHistory:int = 0;
		int iceBuyHistory;////public var iceBuyHistory:int = 0;
		int stoneBuyHistory;////public var stoneBuyHistory:int = 0;
		int levinBuyHistory;////public var levinBuyHistory:int = 0;
		bool blockCastGolem;////public var blockCastGolem:Boolean;
		bool blockCastIceman;////public var blockCastIceman:Boolean;
		bool blockCastAir;////public var blockCastAir:Boolean;
		int castGolemCounter;////public var castGolemCounter:int = 0;
		int castIcemanCounter;////public var castIcemanCounter:int = 0;
		int castAirCounter;////public var castAirCounter:int = 0;
		int castGolemTimer;////public var castGolemTimer:int;
		int castIcemanTimer;////public var castIcemanTimer:int;
		int castAirTimer;////public var castAirTimer:int;
		
		Vec2 savePos;

		WorldInterface();
		CREATE_FUNC(WorldInterface);
		virtual bool init();// (event:Event) : void
		virtual void update(float dt = 0);
		virtual void onEnter();
		//void clickHandler(Ref* ref);

		virtual void mouseMoveHandler(cocos2d::EventMouse* param1);
		virtual void mouseDownHandler(cocos2d::EventMouse *event);
		virtual void mouseUpHandler(cocos2d::EventMouse* event);
		//bool onTouchBegan(Touch *touch, Event *unused_event);
		//void onTouchEnded(Touch *touch, Event *unused_event);
		//void onTouchCancelled(Touch *touch, Event *unused_event);
		//void onTouchMoved(Touch *touch, Event *unused_event);
		//
		//void onMouseMove(Event *unused_event);
		//void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
		//void onTouchesMoved(const std::vector<Touch*>& touches, Event *pEvent);
		//void onTouchesEnded(const std::vector<Touch*>& touches, Event *pEvent);
		//void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

		virtual void addCast(string param1);

		virtual void updateInfo();

		virtual void archiveManage(string param1, string param2);

		virtual void castGolem();

		virtual void castIceman();

		virtual void castAir();

		virtual void addPause();

		virtual void addFastPause();

		virtual void addEncyclopedia();

		virtual void downloadCast();

		virtual void castRegime(string param1);

		virtual void fastPlayControl(int param1 = 0);

		virtual void  barInfoView();

		virtual void barInfoManage(BaseNode * param1 = NULL);

		virtual void breaking();

		virtual void hintUpdate();

		virtual void autoguidersButtons();
		virtual void spheresBlockManage(string param1 = "");

		virtual void archiveSphereBacklightManage(string param1);

		virtual void fasterManage(bool param1);

		virtual void sellSphere(string param1);

		virtual void addGetAchieve(string param1);

		virtual void newEnemyUpdate();

	};

}
#endif
