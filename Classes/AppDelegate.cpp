#include "AppDelegate.h"

#include "MainClass.h"



//#include "./test/HelloWorldScene.h"
//#include "./test/HelloDragonBones.h"
//#include "./test/AnimationBase.h"
//#include "./test/DragonBonesEvent.h"
//#include "./test/AnimationLayer.h"
//#include "./test/BoneOffset.h"
//#include "./test/InverseKinematics.h"
//#include "./test/BoundingBox.h"
//#include "./test/ReplaceSlotDisplay.h" 
//#include "./test/ReplaceSkin.h"
//#include "./test/ReplaceAnimation.h"
//#include "./test/CoreElement.h"
//#include "./test/PerformanceTest.h" 

// #include "DragonBonesTest.h"

USING_NS_CC; 

AppDelegate::AppDelegate() 
{
}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}
//#include "test/DBComTest.h"

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("brave", cocos2d::Rect(0, 0, Main::SCREEN_WIDTH, Main::SCREEN_HEIGHT));
        director->setOpenGLView(glview);
    }

    //director->getOpenGLView()->setDesignResolutionSize(1136, 640, ResolutionPolicy::SHOW_ALL);
    director->getOpenGLView()->setDesignResolutionSize(Main::SCREEN_WIDTH, Main::SCREEN_HEIGHT, ResolutionPolicy::EXACT_FIT);
    director->getOpenGLView()->setFrameSize(Main::SCREEN_WIDTH, Main::SCREEN_HEIGHT);
    director->getOpenGLView()->setViewPortInPoints(0,0, Main::SCREEN_WIDTH, Main::SCREEN_HEIGHT);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(Main::AnimationInterval);
    FileUtils::getInstance()->addSearchPath("test",true);
    FileUtils::getInstance()->addSearchPath("res", true);
	//// create a scene. it's an autorelease object
	//auto scene = HelloWorld::createScene(); 
	//// run
	//director->runWithScene(scene);

	auto scene = Main::createScene();
	//auto scene = DBComTest::createScene();

    // create a scene. it's an autorelease object
    //auto scene = HelloDragonBones::createScene();

    //auto scene1 = AnimationBase::createScene();
    //scene->addChild(scene1);

    // auto scene = DragonBonesEvent::createScene();
    // auto scene = AnimationLayer::createScene();
    // auto scene = BoneOffset::createScene();
    // auto scene = InverseKinematics::createScene();
    // auto scene = BoundingBox::createScene();
    // auto scene = ReplaceSlotDisplay::createScene();
    // auto scene = ReplaceSkin::createScene();
    // auto scene = ReplaceAnimation::createScene();
    // auto scene = CoreElementGame::createScene();
    // auto scene = PerformanceTest::createScene();

    // auto scene = DragonBonesTest::createScene();

    director->runWithScene(scene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
