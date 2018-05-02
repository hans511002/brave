#include "MainCLass.h"
#include "engine/World.h"


Main * Main::mainClass;
const double Main::AnimationInterval = 1.0f / (double)Main::FrameRate;

Main::Main() :worldClass(NULL){
    Main::mainClass = this;
};
Scene* Main::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    Main *main = new Main();// Main::create();
    main->init();
    // add layer as a child to scene
    scene->addChild(main->worldClass);
    // return the scene
    return scene;
}
int Main::fps;
bool Main::init()
{
    //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
    //this->stage.addEventListener(KeyboardEvent.KEY_DOWN, this->keyDownHandler);

    //this->stage.scaleMode = StageScaleMode.SHOW_ALL;
    //this->stage.align = StageAlign.TOP_LEFT;
    //this->boldTextFormat = new TextFormat();
    //this->boldTextFormat.bold = true;
    double aniInterval = Director::getInstance()->getAnimationInterval() - 0.00000001;
    aniInterval = 1 / aniInterval;
    Main::fps = aniInterval;
    float psf = Director::getInstance()->getSecondsPerFrame();
    CCLOG("fps=%i", Main::fps);

    this->saveBoxClass = new SaveBox();
    //this->readXMLClass = new ReadXML();//使用对象
    //Sounds.instance.stopAll();
    //this->tracker = new GATracker(this, "UA-63231445-3", "AS3", false);
    //this->tracker.trackPageview("openGame");
    addNewScreen("World");
    //Main::mainClass->worldClass = World::create();// new World();
    auto myKeyListener = EventListenerKeyboard::create(); //创建事件监听器监听键盘事件
    ////键盘按键按下时的响应
    //myKeyListener->onKeyPressed = [](EventKeyboard::KeyCode keycode, cocos2d::Event *event)
    //{
    //    CCLOG("key is pressed, keycode is %d", keycode);
    //};

    myKeyListener->onKeyPressed = CC_CALLBACK_2(Main::keyDownHandler, this);
    ////键盘按键弹回时的响应
    //myKeyListener->onKeyReleased = [](EventKeyboard::KeyCode keycode, cocos2d::Event *event)
    //{
    //    CCLOG("key is released, keycode is %d", keycode);
    //};
    return true;
}// end function

void Main::addNewScreen(string param1)
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
            //this->container = new LevelsMenu();
            this->levelsMenuClass = new LevelsMenu();
            this->levelsMenuClass->init();
            this->addChild(this->levelsMenuClass);
        }
        else if (param1 == "World")
        {
            //this->container = new World();
            this->worldClass = new World();
            this->worldClass->init();
            this->addChild(this->worldClass);
        }
        //this->bmp = new Bitmap(this->getBitmapData(this->container));
        //this->addChild(Main.mainClass.bmp);
        if (this->container)this->container->setVisible(false);
        this->middleScreenClass->setZOrder(99);
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


cocos2d::Image * Main::getBitmapData(cocos2d::Node* param1) //: BitmapData
{
    //  this->bd = new BitmapData(param1.width, param1.height);
    //this->bd.draw(param1);
    //return this->bd;
    return (cocos2d::Image *)NULL;
}// end function

void Main::keyDownHandler(EventKeyboard::KeyCode keycode, cocos2d::Event *event)
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
            //if (Sounds.instance.musicOn)
            //{
            //    Sounds.instance.musicManage("off");
            //}
            //else
            //{
            //    Sounds.instance.musicManage("on");
            //}
        }
    }
    else if ((int)keycode == 115 || (int)keycode == 83)
    {
        if (this->worldClass)
        {
            //if (Sounds.instance.soundOn)
            //{
            //    Sounds.instance.soundManage("off");
            //}
            //else
            //{
            //    Sounds.instance.soundManage("on");
            //}
        }
    }
    return;
}// end function

void Main::addStartLogo()
{
    //this->container = new StartMenu();
    //this->startMenuClass = new StartMenu();
    //this->addChild(this->startMenuClass);
    return;
}// end function


