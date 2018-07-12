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

class Main : public  BaseLayer //cocos2d::LayerColor //
{
public:
	int frameCounter;
	int i;
	int j;
	//void * tempObject;
	ListenInterface * container;
	SaveBox * saveBoxClass;
	//加载配置数据 
	ReadXML readXMLClass;
	//public var startLogoClass:StartLogo;
	//public var startMenuClass:StartMenu;
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
	

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	static const int SCREEN_WIDTH_HALF = 400;
	static const int SCREEN_HEIGHT_HALF = 300;

	static const int SCREEN_WIDTH_OUT_LEFT = 0;
	static const int SCREEN_HEIGHT_OUT_TOP = 0;
	static const int SCREEN_HEIGHT_OUT_DOWN = 0;
	
    static const int FrameRate=30;
    static const double AnimationInterval ;

	static Main *mainClass;

	Main();
	//CREATE_FUNC(Main);
	virtual bool init();
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

#endif
