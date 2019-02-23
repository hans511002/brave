#include "BaseNode.h"

#include "sys/saveBox.h"
#include "engine/World.h"
#include "screens/MiddleScreen.h"
#include "screens/LevelsMenu.h"
#include "engine/casts/Cast.h"
#include "engine/WorldInterface.h"
#include "MainCLass.h"
#include "sys/preloadSound.h"

Main * Main::mainClass;
const double Main::AnimationInterval = 1.0f / (double)Main::FrameRate;
bool Main::moneyDebug=true;
namespace std {
	sys::I18n i18n;

}

  float Main::mouseX=0;
  float Main::mouseY=0;

Main::Main() :worldClass(NULL), frameCounter(0), container(NULL), middleScreenClass(NULL), levelsMenuClass(NULL), preload(false)
{
	i18n.init();
    Main::mainClass = this;
};
Scene* Main::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    Main *main = new Main();// Main::create();
    main->init();
    // add layer as a child to scene
    scene->addChild(main);
    // return the scene
    return scene;
}
int Main::fps;
void Main::_onStart(){

};

bool Main::init()
{
	BaseLayer::init();
	//BaseNode::init();
	this->setName("Main");
    //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
    //this->stage.addEventListener(KeyboardEvent.KEY_DOWN, this->keyDownHandler);

    //this->stage.scaleMode = StageScaleMode.SHOW_ALL;
    //this->stage.align = StageAlign.TOP_LEFT;
    //this->boldTextFormat = new TextFormat();
    //this->boldTextFormat.bold = true;
    double aniInterval = Director::getInstance()->getAnimationInterval() - 0.0000001;
    aniInterval = 1 / aniInterval;
    Main::fps = aniInterval;
    float psf = Director::getInstance()->getSecondsPerFrame();
    CCLOG("fps=%i", Main::fps);

    this->saveBoxClass = new SaveBox();
	this->saveBoxClass->playLevel = 1;
    //this->readXMLClass = new ReadXML();//不使用指针,使用对象
    //this->tracker = new GATracker(this, "UA-63231445-3", "AS3", false);
    //this->tracker.trackPageview("openGame");
	this->enableKeyHandler();
    //this->enableMouseHandler();//world及screen中监听
    //addPreloadDB();
    //
    AudioUtil::setAudioDir("sound");
    //    AudioUtil::stopAll();
//    AudioUtil::musicManage("off");
//    AudioUtil::soundManage("off");
    preloadSound();
    return true;
}// end function

void Main::addNewScreen(const string & param1)
{
    if (this->middleScreenClass)
    {
        if (param1 == "StartMenu")
        {
            //this->container = new StartMenu();
            //         this->startMenuClass = new StartMenu();;
            //this->startMenuClass->init();
            //this->addChild(this->startMenuClass);
        }
        else if (param1 == "LevelsMenu")
        {
            this->levelsMenuClass = new LevelsMenu();
            this->container = this->levelsMenuClass;
            this->levelsMenuClass->init();
            this->addChild(this->levelsMenuClass);
			this->printNodePos(this->levelsMenuClass);
        }
        else if (param1 == "World")
        {
			this->worldClass = new World();
			this->container = this->worldClass;
            this->worldClass->init();
            this->addChild(this->worldClass);
        }
        //this->bmp = new Bitmap(this->getBitmapData(this->container));
        //this->addChild(Main.mainClass.bmp);
        if (this->container)
			this->container->setVisible(false);
        this->middleScreenClass->setLocalZOrder(99);
        //this->setChildIndex(this->middleScreenClass, (this->numChildren - 1));
        //this->setChildIndex(this->IDIClass, (this->numChildren - 1));
    }
    else
    {
//        if (this->container)
//        {
//            //this->bmp = new Bitmap(this->getBitmapData(this->container));
//            //this->addChild(Main.mainClass.bmp);
//            this->container->setVisible(false);
//        }
        this->middleScreenClass = new MiddleScreen(param1);
        this->addChild(this->middleScreenClass);
//		preload.start();
    }
    return;
}// end function
void Main::removeAllScreens()
{
    //if (this->bmp)
    //{
    //	this->removeChild(this->bmp);
    //	this->bmp = null;
    //}
    //if (this->startMenuClass)
    //{
    //	this->lastClass = "StartMenu";
    //	this->removeChild(this->startMenuClass);
    //	this->startMenuClass = null;
    //}
    if (this->levelsMenuClass)
    {
        this->lastClass = "LevelsMenu";
        this->removeChild(this->levelsMenuClass);
        this->levelsMenuClass = NULL;
    }
    if (this->worldClass)
    {
        this->lastClass = "World";
        this->removeChild(this->worldClass);
        this->worldClass = NULL;
    }
    this->container = NULL;
    this->saveBoxClass->updateSever();
    //return;
}// end function
void Main::onEnter()
{
	BaseLayer::onEnter();
	//BaseNode::onEnter();
   addStartLogo();
};

cocos2d::Image * Main::getBitmapData(cocos2d::Node* param1) //: BitmapData
{
    //  this->bd = new BitmapData(param1.width, param1.height);
    //this->bd.draw(param1);
    //return this->bd;
    return (cocos2d::Image *)NULL;
}// end function
void Main::addStartLogo()
{
    addNewScreen("LevelsMenu");
    //this->container = new StartMenu();
	//this->startMenuClass = new StartMenu();
	//this->addChild(this->startMenuClass);
	return;
}// end function
void Main::keyBoardPressedHandler(EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
    if ((int)keycode == 49)
    {
        if (this->worldClass)
        {
            if (!this->worldClass->menuObject && this->worldClass->firstMusicPlay)
            {
                if (this->worldClass->cast)
                {
                    if (!(dynamic_cast<casts::Cast_1*>(this->worldClass->cast)))
                    {
                        this->worldClass->worldInterface->breaking();
                    }
                    else
                    {
                        this->worldClass->worldInterface->breaking();
                        return;
                    }
                }
                if (this->worldClass->worldInterface->container->butCastGolem->isVisible() && (int)this->worldClass->worldInterface->container->butCastGolem->getUserData() != 5)
                {
                    if (this->worldClass->worldInterface->container->mouseEnabled)
                    {
                        this->worldClass->worldInterface->castGolem();
                        this->worldClass->worldInterface->container->butCastGolem->setUserData((void*)5);// gotoAndStop(5);
                    }
                }
            }
        }
    }
    else if ((int)keycode == 50)
    {
        if (this->worldClass)
        {
            if (!this->worldClass->menuObject && this->worldClass->firstMusicPlay)
            {
                if (this->worldClass->cast)
                {
                    if (!(dynamic_cast<casts::Cast_2*>(this->worldClass->cast)))
                    {
                        this->worldClass->worldInterface->breaking();
                    }
                    else
                    {
                        this->worldClass->worldInterface->breaking();
                        return;
                    }
                }
                if (this->worldClass->worldInterface->container->butCastIceman->isVisible() && (int)this->worldClass->worldInterface->container->butCastIceman->getUserData() != 5)
                {
                    if (this->worldClass->worldInterface->container->mouseEnabled)
                    {
                        this->worldClass->worldInterface->castIceman();
                        this->worldClass->worldInterface->container->butCastIceman->setUserData((void*)5);//gotoAndStop(5);
                    }
                }
            }
        }
    }
    else if ((int)keycode == 51)
    {
        if (this->worldClass)
        {
            if (!this->worldClass->menuObject && this->worldClass->firstMusicPlay)
            {
                if (this->worldClass->cast)
                {
                    if (!(dynamic_cast<casts::Cast_3*>(this->worldClass->cast)))
                    {
                        this->worldClass->worldInterface->breaking();
                    }
                    else
                    {
                        this->worldClass->worldInterface->breaking();
                        return;
                    }
                }
                if (this->worldClass->worldInterface->container->butCastAir->isVisible() && (int)this->worldClass->worldInterface->container->butCastAir->getUserData() != 5)
                {
                    if (this->worldClass->worldInterface->container->mouseEnabled)
                    {
                        this->worldClass->worldInterface->castAir();
                        this->worldClass->worldInterface->container->butCastAir->setUserData((void*)5);//.gotoAndStop(5);
                    }
                }
            }
        }
    }
    else if ((int)keycode == 109 || (int)keycode == 77)
    {
        if (this->worldClass)
        {
            if (AudioUtil::musicOn) 
                AudioUtil::musicManage("off"); 
            else 
                AudioUtil::musicManage("on"); 
        }
    }
    else if ((int)keycode == 115 || (int)keycode == 83)
    {
        if (this->worldClass)
        {
            if (AudioUtil::soundOn) 
                AudioUtil::soundManage("off"); 
            else 
                AudioUtil::soundManage("on"); 
        }
    }
    return;
}// end function
void Main::keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event){
	EventNode::keyBoardPressedHandler(keyCode, event);
};
void Main::mouseDownHandler(cocos2d::EventMouse* event){
	EventNode::mouseDownHandler(event);
	cocos2d::EventMouse::MouseButton mouseButton = event->getMouseButton();
	if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
	std::MouseEvent me= std::buildMouseEvent(event);
	if (this->worldClass)
		this->worldClass->mouseDownHandler(&me);
	if (this->levelsMenuClass)
		this->levelsMenuClass->mouseDownHandler(&me);
	//if (this->startMenuClass)
	//	this->startMenuClass->mouseDownHandler(me);
};
void Main::mouseUpHandler(cocos2d::EventMouse* event){
	EventNode::mouseUpHandler(event);
	cocos2d::EventMouse::MouseButton  mouseButton = event->getMouseButton();
	if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
	std::MouseEvent  me = std::buildMouseEvent(event);
	if (this->worldClass)
		this->worldClass->mouseUpHandler(&me);
	if (this->levelsMenuClass)
		this->levelsMenuClass->mouseUpHandler(&me);
	//if (this->startMenuClass)
	//	this->startMenuClass->mouseUpHandler(me);
};
void Main::mouseMoveHandler(cocos2d::EventMouse* event){
	EventNode::mouseMoveHandler(event);
	std::MouseEvent  me = std::buildMouseEvent(event);
	if (this->worldClass)
		this->worldClass->mouseMoveHandler(&me);
	if (this->levelsMenuClass)
		this->levelsMenuClass->mouseMoveHandler(&me);
	//if (this->startMenuClass)
	//	this->startMenuClass->mouseMoveHandler(me);
};
void Main::mouseScrollHandler(cocos2d::EventMouse* event){
	EventNode::mouseScrollHandler(event);
};
void Main::rightMouseDownHandler(cocos2d::EventMouse* event){
	EventNode::rightMouseDownHandler(event);
	std::MouseEvent  me = std::buildMouseEvent(event);
	if (this->worldClass)
		this->worldClass->rightMouseDownHandler(&me);
	if (this->levelsMenuClass)
		this->levelsMenuClass->rightMouseDownHandler(&me);
	//if (this->startMenuClass)
	//	this->startMenuClass->rightMouseDownHandler(me);
};
void Main::rightMouseUpHandler(cocos2d::EventMouse* event)
{
	EventNode::rightMouseUpHandler(event);
	//if (this->worldClass)
	//	this->worldClass->rightMouseUpHandler(me);
	//if (this->levelsMenuClass)
	//	this->levelsMenuClass->rightMouseUpHandler(me);
	//if (this->startMenuClass)
	//	this->startMenuClass->rightMouseUpHandler(me);
};
void Main::touchActionHandler(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type){
	EventNode::touchActionHandler(pSender,type);
};

void Main::addPreloadDB(){
//    preload.addPreLoadDir("cast");
//    preload.addPreLoadDir("worldinterface");
//    preload.addPreLoadDir("unit");
//    preload.addPreLoadDir("sphere");
//    preload.addPreLoadDir("tower");
//    preload.addPreLoadDir("screen");
    string fileType="json";
    preload.addPreLoadArm("cast/Air_mc","Air_mc", fileType);
    preload.addPreLoadArm("cast/BlowIce_mc","BlowIce_mc", fileType);
    preload.addPreLoadArm("cast/DeathAit_mc","DeathAit_mc", fileType);
    preload.addPreLoadArm("cast/Golem1HorisontDeath_mc","Golem1HorisontDeath_mc", fileType);
    preload.addPreLoadArm("cast/Golem1VerticalDeath_mc","Golem1VerticalDeath_mc", fileType);
    preload.addPreLoadArm("cast/Golem2HorisontDeath_mc","Golem2HorisontDeath_mc", fileType);
    preload.addPreLoadArm("cast/Golem2VerticalDeath_mc","Golem2VerticalDeath_mc", fileType);
    preload.addPreLoadArm("cast/Golem3HorisontDeath_mc","Golem3HorisontDeath_mc", fileType);
    preload.addPreLoadArm("cast/Golem3VerticalDeath_mc","Golem3VerticalDeath_mc", fileType);
    preload.addPreLoadArm("cast/Golem_mc","Golem_mc", fileType);
    preload.addPreLoadArm("cast/IcemanHorisontDeath_mc","IcemanHorisontDeath_mc", fileType);
    preload.addPreLoadArm("cast/IcemanVerticalDeath_mc","IcemanVerticalDeath_mc", fileType);
    preload.addPreLoadArm("cast/Iceman_mc","Iceman_mc", fileType);
    preload.addPreLoadArm("cast/IceRoad_mc","IceRoad_mc", fileType);
    preload.addPreLoadArm("cast/MoveAir_mc","MoveAir_mc", fileType);
    preload.addPreLoadArm("cast/MoveGolem_mc","MoveGolem_mc", fileType);
    preload.addPreLoadArm("cast/MoveIceman_mc","MoveIceman_mc", fileType);
    preload.addPreLoadArm("sphere/BulletSphereTower_mc","BulletSphereTower_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower51_1_mc","BulletTower51_1_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower51_2_mc","BulletTower51_2_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower5_1Bang_mc","BulletTower5_1Bang_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower5_1Smoke1_mc","BulletTower5_1Smoke1_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower5_1_mc","BulletTower5_1_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower61_mc","BulletTower61_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower6_1_mc","BulletTower6_1_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower6_2_mc","BulletTower6_2_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower71_mc","BulletTower71_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower7_mc","BulletTower7_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower7_smoke_mc","BulletTower7_smoke_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower81_mc","BulletTower81_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower8_1_mc","BulletTower8_1_mc", fileType);
    preload.addPreLoadArm("sphere/BulletTower8_2_mc","BulletTower8_2_mc", fileType);
    preload.addPreLoadArm("tower/AnimUpgrade_mc","AnimUpgrade_mc", fileType);
    preload.addPreLoadArm("tower/BuildTowerMenu_mc","BuildTowerMenu_mc", fileType);
    preload.addPreLoadArm("tower/BuildTowerSmoke_mc","BuildTowerSmoke_mc", fileType);
    preload.addPreLoadArm("tower/Exchange1_mc","Exchange1_mc", fileType);
    preload.addPreLoadArm("tower/Exchange_mc","Exchange_mc", fileType);
    preload.addPreLoadArm("tower/ShotTower51_2_mc","ShotTower51_2_mc", fileType);
    preload.addPreLoadArm("tower/Tower1_mc","Tower1_mc", fileType);
    preload.addPreLoadArm("tower/Tower2_mc","Tower2_mc", fileType);
    preload.addPreLoadArm("tower/Tower3_mc","Tower3_mc", fileType);
    preload.addPreLoadArm("tower/Tower4_mc","Tower4_mc", fileType);
    preload.addPreLoadArm("tower/Tower5_mc","Tower5_mc", fileType);
    preload.addPreLoadArm("tower/Tower6_mc","Tower6_mc", fileType);
    preload.addPreLoadArm("tower/Tower7_mc","Tower7_mc", fileType);
    preload.addPreLoadArm("tower/Tower8_mc","Tower8_mc", fileType);
    preload.addPreLoadArm("tower/TowerBlockBone","TowerBlockBone", fileType);
    preload.addPreLoadArm("tower/TowerMenuHint_mc","TowerMenuHint_mc", fileType);
    preload.addPreLoadArm("tower/TowerMenuSphere_mc","TowerMenuSphere_mc", fileType);
    preload.addPreLoadArm("tower/TowerMenu_mc","TowerMenu_mc", fileType);
    preload.addPreLoadArm("tower/UltraTowerMenu_mc","UltraTowerMenu_mc", fileType);
    preload.addPreLoadArm("unit/NewElement_mc","NewElement_mc", fileType);
    preload.addPreLoadArm("unit/NewEnemy_mc","NewEnemy_mc", fileType);
    preload.addPreLoadArm("unit/Unit10_mc","Unit10_mc", fileType);
    preload.addPreLoadArm("unit/Unit11_mc","Unit11_mc", fileType);
    preload.addPreLoadArm("unit/Unit12_mc","Unit12_mc", fileType);
    preload.addPreLoadArm("unit/Unit13_mc","Unit13_mc", fileType);
    preload.addPreLoadArm("unit/Unit14_mc","Unit14_mc", fileType);
    preload.addPreLoadArm("unit/Unit15_mc","Unit15_mc", fileType);
    preload.addPreLoadArm("unit/Unit16_mc","Unit16_mc", fileType);
    preload.addPreLoadArm("unit/Unit17_mc","Unit17_mc", fileType);
    preload.addPreLoadArm("unit/Unit18_mc","Unit18_mc", fileType);
    preload.addPreLoadArm("unit/Unit19_mc","Unit19_mc", fileType);
    preload.addPreLoadArm("unit/Unit1_1_mc","Unit1_1_mc", fileType);
    preload.addPreLoadArm("unit/Unit1_2_mc","Unit1_2_mc", fileType);
    preload.addPreLoadArm("unit/Unit1_3_mc","Unit1_3_mc", fileType);
    preload.addPreLoadArm("unit/Unit20_backDeath_mc","Unit20_backDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit20_frontDeath_mc","Unit20_frontDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit20_mc","Unit20_mc", fileType);
    preload.addPreLoadArm("unit/Unit21_backDeath_mc","Unit21_backDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit21_frontDeath_mc","Unit21_frontDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit21_mc","Unit21_mc", fileType);
    preload.addPreLoadArm("unit/Unit22_mc","Unit22_mc", fileType);
    preload.addPreLoadArm("unit/Unit23HorisontDeath_mc","Unit23HorisontDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit23VerticalDeath_mc","Unit23VerticalDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit23_mc","Unit23_mc", fileType);
    preload.addPreLoadArm("unit/Unit24HorisontDeath_mc","Unit24HorisontDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit24VerticalDeath_mc","Unit24VerticalDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit24_mc","Unit24_mc", fileType);
    preload.addPreLoadArm("unit/Unit25HorisontDeath_mc","Unit25HorisontDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit25VerticalDeath_mc","Unit25VerticalDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit25_mc","Unit25_mc", fileType);
    preload.addPreLoadArm("unit/Unit26HorisontDeath_mc","Unit26HorisontDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit26VerticalDeath_mc","Unit26VerticalDeath_mc", fileType);
    preload.addPreLoadArm("unit/Unit26_mc","Unit26_mc", fileType);
    preload.addPreLoadArm("unit/Unit27_mc","Unit27_mc", fileType);
    preload.addPreLoadArm("unit/Unit28_mc","Unit28_mc", fileType);
    preload.addPreLoadArm("unit/Unit29_mc","Unit29_mc", fileType);
    preload.addPreLoadArm("unit/Unit2_mc","Unit2_mc", fileType);
    preload.addPreLoadArm("unit/Unit30_mc","Unit30_mc", fileType);
    preload.addPreLoadArm("unit/Unit31_mc","Unit31_mc", fileType);
    preload.addPreLoadArm("unit/Unit32_mc","Unit32_mc", fileType);
    preload.addPreLoadArm("unit/Unit33_mc","Unit33_mc", fileType);
    preload.addPreLoadArm("unit/Unit3_mc","Unit3_mc", fileType);
    preload.addPreLoadArm("unit/Unit4_mc","Unit4_mc", fileType);
    preload.addPreLoadArm("unit/Unit5_mc","Unit5_mc", fileType);
    preload.addPreLoadArm("unit/Unit6_mc","Unit6_mc", fileType);
    preload.addPreLoadArm("unit/Unit7_mc","Unit7_mc", fileType);
    preload.addPreLoadArm("unit/Unit8_mc","Unit8_mc", fileType);
    preload.addPreLoadArm("unit/Unit9_mc","Unit9_mc", fileType);
    preload.addPreLoadArm("unit/UnitBase_mc","UnitBase_mc", fileType);
    preload.addPreLoadArm("worldinterface/Arrow_mc","Arrow_mc", fileType);
    preload.addPreLoadArm("worldinterface/BonusMoney_mc","BonusMoney_mc", fileType);
    preload.addPreLoadArm("worldinterface/buySphere","buySphere", fileType);
    preload.addPreLoadArm("worldinterface/CastFireIce_mc","CastFireIce_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastFireLevin_mc","CastFireLevin_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastFireStone_mc","CastFireStone_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastFire_mc","CastFire_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastGetAllLittle_mc","CastGetAllLittle_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastGetAllSwamp_mc","CastGetAllSwamp_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastGetAll_mc","CastGetAll_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastIceLevin_mc","CastIceLevin_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastIceStone_mc","CastIceStone_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastIce_mc","CastIce_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastLevin_mc","CastLevin_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastMask_mc","CastMask_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastStoneLevin_mc","CastStoneLevin_mc", fileType);
    preload.addPreLoadArm("worldinterface/CastStone_mc","CastStone_mc", fileType);
    preload.addPreLoadArm("worldinterface/GetAchieve_mc","GetAchieve_mc", fileType);
    preload.addPreLoadArm("worldinterface/GetAll_mc","GetAll_mc", fileType);
    preload.addPreLoadArm("worldinterface/GetSphere_mc","GetSphere_mc", fileType);
    preload.addPreLoadArm("worldinterface/Hint_mc","Hint_mc", fileType);
    preload.addPreLoadArm("worldinterface/Level1_mc","Level1_mc", fileType);
    preload.addPreLoadArm("worldinterface/Level2_mc","Level2_mc", fileType);
    preload.addPreLoadArm("worldinterface/Level3_mc","Level3_mc", fileType);
    preload.addPreLoadArm("worldinterface/Level4_mc","Level4_mc", fileType);
    preload.addPreLoadArm("worldinterface/Level5_mc","Level5_mc", fileType);
    preload.addPreLoadArm("worldinterface/Level6_mc","Level6_mc", fileType);
    preload.addPreLoadArm("worldinterface/LevelBase","LevelBase", fileType);
    preload.addPreLoadArm("worldinterface/MoneyAdd_mc","MoneyAdd_mc", fileType);
    preload.addPreLoadArm("worldinterface/MoveSphere_mc","MoveSphere_mc", fileType);
    preload.addPreLoadArm("worldinterface/RadiusSphere_mc","RadiusSphere_mc", fileType);
    preload.addPreLoadArm("worldinterface/RoadsignFire_mc","RoadsignFire_mc", fileType);
    preload.addPreLoadArm("worldinterface/RoadsignIce_mc","RoadsignIce_mc", fileType);
    preload.addPreLoadArm("worldinterface/RoadsignLevin_mc","RoadsignLevin_mc", fileType);
    preload.addPreLoadArm("worldinterface/RoadsignSphere_mc","RoadsignSphere_mc", fileType);
    preload.addPreLoadArm("worldinterface/RoadsignStone_mc","RoadsignStone_mc", fileType);
    preload.addPreLoadArm("worldinterface/SavedCastTime_mc","SavedCastTime_mc", fileType);
    preload.addPreLoadArm("worldinterface/worldBook_mc","worldBook_mc", fileType);
    preload.addPreLoadArm("worldinterface/worldCast_mc","worldCast_mc", fileType);
//    preload.addPreLoadArm("worldinterface/WorldInterface_mc","WorldInterface_mc", fileType);
    preload.addPreLoadArm("worldinterface/worldLive_mc","worldLive_mc", fileType);
    preload.addPreLoadArm("worldinterface/worldSphere_mc","worldSphere_mc", fileType);
    preload.addPreLoadArm("worldinterface/worldStart_mc","worldStart_mc", fileType);
	preload.addPreLoadArm("screen/MiddleScreenCentr_mc", "MiddleScreenCentr_mc", fileType);
	preload.addPreLoadArm("screen/MiddleScreen_mc", "MiddleScreen_mc", fileType);

}

