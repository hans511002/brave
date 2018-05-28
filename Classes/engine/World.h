#ifndef WORLD_H
#define WORLD_H

#include "BaseNode.h"
#include "engine/xml/ReadXML.h"
#include "engine/Waves.h"
#include "sys/saveBox.h"
#include "engine/WorldInterface.h"
#include "Feature.h"
#include "engine/level/Level.h"
#include "bezier/Bezier.h"
#include "engine/units/Unit.h"
#include "engine/GetSphere.h"
#include "engine/bullets/Bullet.h"
#include "engine/towers/Tower.h"
#include "engine/towers/BuildTowerMenu.h"
#include "engine/towers/UltraTowerMenu.h"
#include "engine/towers/TowerMenu.h"
#include "engine/towers/TowerMenu_mc.h"
#include "engine/casts/Map.h"

//#include "animation/Hint.h"

namespace engine
{
    namespace  decoration
    {
        class Decoration;
    };
    namespace  casts
    {
        class Cast;
    };
    class WorldInterface;
    class Waves;
    class Feature;
    using namespace towers;
    using namespace units;
    
    class World : public BaseNode //, public  BaseLayer
    {
         
    public:
        int i;
        int j;
        int n;
        int m;
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
        //public var road : MovieClip;
        //public var levelAdditionally : MovieClip;
        //public var levelAdditionally1 : MovieClip;
        //public var levelAdditionally2 : MovieClip;
        //public var levelAdditionally3 : MovieClip;

        WorldInterface* worldInterface;
        Common::Array<Node*> listOfFlags;//public var listOfFlags : Array;
        Common::Array<Node*> listOfPlaces;//public var listOfPlaces : Array;
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
        //public var listOfMoveSpheres : Array;
        //public var listOfClasses : Array;
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
        //public var listOfIndexes0 : Array;
        //public var listOfIndexes1 : Array;
        //public var listOfIndexes2 : Array;
        //public var listOfIndexes3 : Array;
        casts::Cast* cast;
        casts::Map map; //public var map : Map;
        BaseNode * menuObject;//public var menuObject : Object;//՝�� �ˠѧϰ
        //public var sortIndex : Array;

       
        //PointTimer * pointer4;
        //public var pointer1 : MovieClip;
        //public var pointer2 : MovieClip;
        //public var pointer3 : MovieClip;
        BaseNode * selectObject;//public var selectObject : Object;
        bool firstMusicPlay;//: Boolean;
        bool secondMusicPlay;//: Boolean;
        int secondMusicCounter;// : int = 0;
        //public var listOfSoundChannels : Array;
        int winDefCounter;//: int = -1;
        int viewBoss;// : int = 0;
        int viewRockCrash;//: int = 0;
        //public var boss : Unit_34;
        decoration::Decoration* decoration;
        int nowLevel;
        sys::SaveBox * saveBox;
        //public var exchange : Exchange;
        int portalViewCounter;//: int = 30;
        BaseNode * trainingClass;//public var trainingClass : Object;
        //Hint* hint;// : Hint_mc;
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
 
        bool init();

        virtual void onEnter();
        virtual void onExit();
        
        virtual void enterFrameHandler(float dt);//void  enterFrameHandler();  // event : Event
        //void scheduleUpdate(float dt);
        //void MyNode::TickMe(float dt);
        //// wrap this function into a selector via schedule_selector marco.
        //this->schedule(CC_SCHEDULE_SELECTOR(MyNode::TickMe), 0, 0, 0);

        //cocos2d::EventMouse* event
        void mouseMoveHandler(cocos2d::EventMouse* param1);

        void mouseDownHandler(cocos2d::EventMouse* event);

        void mouseUpHandler(cocos2d::EventMouse* event);

        void rightMouseDownHandler(cocos2d::EventMouse* event);

        void rightMouseUpHandler(cocos2d::EventMouse* event);

        Tower * addTower(std::string param1, Sprite*  param2, bool param3 = false);

        units::Unit * addUnit(int param1, int param2, int param3 = 0, float param4 = 0, int param5 = 0, int param6 = 0);



        //Bullet * addBullet(int param1, Point param2, Object param3, Object param4, float param5 = 0, int param6 = 0);

        void manageIndexes();



        void manageMouse(string param1);

        void manageListeners(string param1);

        void deactivateHandler(cocos2d::EventMouse* event);//event:Event

        void achieveManage(string param1);

        void reInit(cocos2d::EventMouse*event);//event:Event 

    };


}
#endif
