#ifndef BRAVE_MAIN_H
#define BRAVE_MAIN_H
#include "BaseNode.h"

//#include "BaseHeaders.h"
//#include "engine/World.h"
#include "engine/xml/ReadXML.h"
//#include "screens/MiddleScreen.h"
//#include "screens/LevelsMenu.h"
#include "DbPreload.h"

#include "DefineClasses.h"
#include "screens/Screen.h"   

class Main : public  BaseLayer //cocos2d::LayerColor //
{
public:
	string currentUser;

	int frameCounter;
	int i;
	int j;
	//void * tempObject;
	//加载配置数据
	ReadXML readXMLClass;
	screens::Screen * container;
	SaveBox * saveBoxClass;
	StartLogo * startLogoClass;
	StartMenu * startMenuClass;
	MiddleScreen * middleScreenClass;//public var middleScreenClass:MiddleScreen;
	LevelsMenu * levelsMenuClass;//public var levelsMenuClass:LevelsMenu;
	engine::World * worldClass;
	//public var testingClass:Testing;
	string lastClass;
	//public var tracker:AnalyticsTracker;
	//public var IDIClass:Object;
	bool ourNet;
	string domainName;
	DbPreload preload;
	static int fps;

	static float mouseX;
	static float mouseY;

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 450;
	static const int SCREEN_WIDTH_HALF = SCREEN_WIDTH/2;
	static const int SCREEN_HEIGHT_HALF = SCREEN_HEIGHT/2;

	static const int LEVEL_MAP_WIDTH = 800;
	static const int LEVEL_MAP_HEIGHT = 600;

	static const int SCREEN_WIDTH_OUT_LEFT = (SCREEN_WIDTH - LEVEL_MAP_WIDTH) / 2;
	static const int SCREEN_HEIGHT_OUT_TOP = (LEVEL_MAP_HEIGHT - SCREEN_HEIGHT)/2;
	static const int SCREEN_HEIGHT_OUT_DOWN = (LEVEL_MAP_HEIGHT - SCREEN_HEIGHT)/2;

    static const int FrameRate=30;
    static const double AnimationInterval ;

	static Main *mainClass;
	static bool moneyDebug;
	static bool releaseTest;

	Main();
	//CREATE_FUNC(Main);
	virtual bool init();
	void addPreloadDB();
	static Scene* createScene();
    virtual void onEnter();
	virtual void _onStart();

    void addNewScreen(const string &  param1);

	void removeAllScreens();

    cocos2d::Image * getBitmapData(cocos2d::Node* param1);

    void addStartLogo();

	virtual   void keyBoardPressedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual   void keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual   void mouseDownHandler(cocos2d::EventMouse* event);
	virtual   void mouseUpHandler(cocos2d::EventMouse* event);
	virtual   void mouseMoveHandler(cocos2d::EventMouse* event);
	virtual   void mouseScrollHandler(cocos2d::EventMouse* event);
	virtual   void rightMouseDownHandler(cocos2d::EventMouse* event);
	virtual   void rightMouseUpHandler(cocos2d::EventMouse* event);
	virtual void touchActionHandler(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);

};

#define CONVERT_TO_WORLD_POS(pos) Main::mainClass->worldClass->convertToNodeSpace(pos)

#endif
