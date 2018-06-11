#ifndef ENGINE_WORLDINTERFACE_H
#define ENGINE_WORLDINTERFACE_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"
//#include "MainClass.h"
//#include "World.h"
#include "JsonUtil.h"
#include "Feature.h"
#include "WorldInterface_mc.h"
#include "engine/units/Unit.h" 
#include "engine/casts/Cast.h"
 
namespace engine
{ 
 
	class  WorldInterface :public BaseNode
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
		Common::Array<NewEnemy_mc *> listOfNewEnemies;//public var listOfNewEnemies:Array;
		MCText * lastTime;//public var lastTime:TextField;
        Common::Array<GetAchieve_mc *> listOfGetAhieve ;//public var listOfGetAhieve:Array;
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
		cocos2d::Point autoguidesMouse_pt;//public var autoguidesMouse_pt:Point;
		BaseNode * autoguidesObject;//public var autoguidesObject:Object;
		cocos2d::Point autoguidesObject_pt;//public var autoguidesObject_pt:Point;
        float autoguidesObjectWidth;////public var autoguidesObjectWidth:Number;
        float autoguidesObjectHeight;////public var autoguidesObjectHeight:Number;

		WorldInterface();
		CREATE_FUNC(WorldInterface);
		bool init();// (event:Event) : void
		void update(float dt=0);
        //void clickHandler(Ref* ref);
        
        void mouseMoveHandler(cocos2d::EventMouse* param1);
        void mouseDownHandler(cocos2d::EventMouse *event);
        void mouseUpHandler(cocos2d::EventMouse* event);
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

		void addCast(string param1);

		void updateInfo();

        void archiveManage(string param1, string param2) ;

        void castGolem();

        void castIceman() ;

        void castAir() ;

        void addPause() ;

        void addFastPause();

        void addEncyclopedia() ;

        void downloadCast() ;

        void castRegime(string param1) ;

        void fastPlayControl(int param1= 0);

		 void  barInfoView();

		void barInfoManage(BaseNode * param1= NULL) ;

		void breaking()  ;

		void hintUpdate();

		void autoguidersButtons();
        void spheresBlockManage(string param1 = "");

		void archiveSphereBacklightManage(string param1);

		void fasterManage(bool param1);

		void sellSphere(string param1);

		void addGetAchieve(string param1);

		void newEnemyUpdate();

	};

}
#endif
