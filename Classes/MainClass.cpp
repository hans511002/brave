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
    AudioUtil::setAudioDir("sound");
    AudioUtil::stopAll();
    preloadSound();

    //this->tracker = new GATracker(this, "UA-63231445-3", "AS3", false);
    //this->tracker.trackPageview("openGame");
	this->enableKeyHandler();
    //this->enableMouseHandler();//world及screen中监听
	preload.addPreLoadDir("cast");
	preload.addPreLoadDir("worldinterface");
	preload.addPreLoadDir("unit");
	preload.addPreLoadDir("sphere"); 
	preload.addPreLoadDir("tower"); 
	preload.addPreLoadDir("screen"); 
    preload.start();
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
            ////this->container = new LevelsMenu();
            //this->levelsMenuClass = new LevelsMenu();
            //this->levelsMenuClass->init();
            //this->addChild(this->levelsMenuClass);
        }
        else if (param1 == "World")
        {
            this->container = this->worldClass = new World();
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
        if (this->container)
        {
            //this->bmp = new Bitmap(this->getBitmapData(this->container));
            //this->addChild(Main.mainClass.bmp);
            this->container->setVisible(false);
        }
        this->middleScreenClass = new MiddleScreen(param1);
        this->addChild(this->middleScreenClass);
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


    addNewScreen("World");
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

