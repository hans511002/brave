#ifndef WORLD_H
#define WORLD_H

#include "BaseHeaders.h" 
#include "screens/Screen.h" 
#include "bezier/Bezier.h"
#include "engine/casts/Map.h"
#include "base/Indexes.h"
#include "WorldInterface.h"

//#include "animation/Hint.h"

namespace engine
{

	class World : public ListenInterface //, public  BaseLayer
    {
         
    public:
        //int i;
        //int j;
        //int n;
        //int m;
        //public var tempObject : Object;
        //public var tempObject1 : Object;
        //public var tempObject2 : Object;
        //public var tempObject3 : Object;
        //public var tempObject4 : Object;
        //public var tempObject5 : Object;
        //public var indexesTemp1 : Object;
        //public var indexesTemp2 : Object;
        //public var indexesTemp3 : Object;
        //public var indexesTemp4 : Object;
        int frameCounter;//: int = 0;
        Feature *feature;
        bezier::Bezier * bezierClass;//public var bezierClass : Bezier;
        Waves *wavesClass;
        int numRoads;//public var numRoads : int;
        Level * level;		//public var level : MovieClip;
		RoadLevels_mc *road;//public var road : MovieClip;
		MovieClipSub *levelAdditionally;  //public var levelAdditionally : MovieClip;
		MovieClipSub *levelAdditionally1;//public var levelAdditionally1 : MovieClip;
		MovieClipSub *levelAdditionally2;//public var levelAdditionally2 : MovieClip;
		MovieClipSub *levelAdditionally3;//public var levelAdditionally3 : MovieClip;

        WorldInterface* worldInterface;
		Common::Array<MovieClip *> listOfFlags;//public var listOfFlags : Array;
		Common::Array<BuildTowerPlace *> listOfPlaces;//public var listOfPlaces : Array;
        Common::Array<RoadsignFire_mc *> listOfFirePortals;//public var listOfFirePortals : Array;
        Common::Array<RoadsignIce_mc *> listOfIcePortals;//public var listOfIcePortals : Array;
        Common::Array<RoadsignStone_mc *> listOfStonePortals;//public var listOfStonePortals : Array;
        Common::Array<RoadsignLevin_mc *> listOfLevinPortals;//public var listOfLevinPortals : Array;
        int money;
        int bonusMoney;
        int liveMax;//: int = 20;
        int live;
        bool forseIndexFl;// : Boolean;
        GetSphere *getSphere; //public var getSphere : GetSphere;
		Common::Array<GetSphere *>listOfMoveSpheres;//public var listOfMoveSpheres : Array;
		
		Common::Array<BaseNode *>listOfClasses;//public var listOfClasses : Array;

        Common::Array<towers::Tower *>listOfTowers;//public var listOfTowers : Array;
        Common::Array<engine::units::Unit *> listOfUnits;//public var listOfUnits : Array;
        Common::Array<engine::bullets::Bullet *> listOfBullets;//public var listOfBullets : Array;
        towers::BuildTowerMenu * buildTowerMenu;//public var buildTowerMenu : BuildTowerMenu;
        towers::TowerMenu *towerMenu;//public var towerMenu : TowerMenu;
        UltraTowerMenu * ultraTowerMenu;//public var ultraTowerMenu : UltraTowerMenu;
        float scaleRadius;//public var scaleRadius : Number = 0.85;
        towers::TowerRadius_mc* towerRadius;// : MovieClip;
        Common::Array<int> unitInputBezieArr; //public var unitInputBezieArr : Array;
        int unitInputBezieCounter;// : int = 0;
		Common::Array<BaseNode *> listOfIndexes0 ;
		Common::Array<BaseNode *> listOfIndexes1 ;
		Common::Array<BaseNode *> listOfIndexes2 ;
		Common::Array<BaseNode *> listOfIndexes3 ;
        casts::Cast* cast;
        casts::Map map; //public var map : Map;
        BaseNode * menuObject;//public var menuObject : Object;//՝�� �ˠѧϰ
        //public var sortIndex : Array;

       
        //PointTimer * pointer4;
		LevelPointer * pointer1;
		LevelPointer * pointer2;
		LevelPointer * pointer3;
        BaseNode * selectObject;//public var selectObject : Object;
        bool firstMusicPlay;//: Boolean;
        bool secondMusicPlay;//: Boolean;
        int secondMusicCounter;// : int = 0;
        //public var listOfSoundChannels : Array;
        int winDefCounter;//: int = -1;
        int viewBoss;// : int = 0;
        int viewRockCrash;//: int = 0;
		Unit_34 * boss ;
        decoration::Decoration* decoration;
        int nowLevel;
        sys::SaveBox * saveBox;
		towers::Exchange * exchange;//public var exchange : Exchange;
        int portalViewCounter;//: int = 30;
        BaseNode * trainingClass;//public var trainingClass : Object;
		Hint_mc* hint;// : Hint_mc;
        float startMusicVolume;//: Number = 0;
        bool bonusMoneyFlag;//: Boolean = true;
        bool eduOpenUpgrArrowFlag;// : Boolean = true;
        int killEnemiesCounter;//: int = 0;
        int createGolemCounter;//: int = 0;
        int createIcemanCounter;//: int = 0;
        int createAirCounter;//: int = 0;
        int earlyWaveCounter;//: int = 0;
        int sellFireCounter;//: int = 0;
        int sellIceCounter;//: int = 0;
        int sellStoneCounter;//: int = 0;
        int sellLevinCounter;//: int = 0;
        int sellGetAllCounter;//: int = 0;
        int icemanSlowdownEnemiesCounter;//: int = 0;
        int castFireCounter;//: int = 0;
        int castIceCounter;//: int = 0;
        int castStoneCounter;//: int = 0;
        int castLevinCounter;//: int = 0;
        int castGetAllCounter;//: int = 0;
        int golemVoiceTurn;//: int = 1;
        int icemanVoiceTurn;//: int = 1;
        int airVoiceTurn;//: int = 1;
        std::string levelType;

        float mouseX;
        float mouseY;

        World();
        //CREATE_FUNC(World);
 
		virtual bool init();

        virtual void onEnter();
        virtual void onExit();
        
        virtual void enterFrameHandler(float dt);//void  enterFrameHandler();  // event : Event
    
		virtual void removeEventTarget(std::MouseEvent * event, BaseNode* node, string caseName);
		virtual void removeEventTarget(std::MouseEvent * event, string case1, string caseName);
        virtual bool preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType);
		virtual   void mouseDownHandler(cocos2d::EventMouse* event);
		virtual   void mouseUpHandler(cocos2d::EventMouse* event);
		virtual   void mouseMoveHandler(cocos2d::EventMouse* event);
		//virtual   void mouseScrollHandler(cocos2d::EventMouse* event);
		virtual   void rightMouseDownHandler(cocos2d::EventMouse* event);
		virtual   void rightMouseUpHandler(cocos2d::EventMouse* event);
		 
		Tower * addTower(std::string param1, BuildTowerPlace*  param2, bool param3 = false);

        units::Unit * addUnit(int param1, int param2, int param3 = 0, float param4 = 0, int param5 = 0, int param6 = 0); 

		Bullet * addBullet(int param1, cocos2d::Point param2, ShootBase *  param3, units::Unit*  param4, float param5 = 0, int param6 = 0);

		virtual void manageIndexes();
		 
		virtual void manageMouse(string param1);

		virtual void manageListeners(string param1);

		virtual void deactivateHandler(cocos2d::EventMouse* event);//event:Event

		virtual void achieveManage(string param1);

		virtual void removeChild(Node* child, bool cleanup  = true );

		virtual void removeIndexes(BaseNode * node);
		virtual void removeClasses(BaseNode * node);
		virtual void reInit(cocos2d::EventMouse*event);//event:Event 

    };


}
#endif
