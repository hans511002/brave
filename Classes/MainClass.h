#ifndef BRAVE_MAIN_H
#define BRAVE_MAIN_H
#include "BaseHeaders.h" 
#include "sys/saveBox.h"
//#include "engine/World.h"
#include "engine/xml/ReadXML.h"
#include "screens/MiddleScreen.h"
#include "screens/LevelsMenu.h"
namespace engine{
	class World;
}
using namespace engine;
using namespace screens;
using namespace sys;

class Main : public  cocos2d::Node //cocos2d::LayerColor //
{
public:
	int frameCounter;
	int i;
	int j;
	void * tempObject;
	Node * container;
	SaveBox * saveBoxClass;
	//º”‘ÿ≈‰÷√ ˝æ› 
	ReadXML readXMLClass;
	//public var startLogoClass:StartLogo;
	//public var startMenuClass:StartMenu;
	MiddleScreen * middleScreenClass;//public var middleScreenClass:MiddleScreen;
	LevelsMenu * levelsMenuClass;//public var levelsMenuClass:LevelsMenu;
	World * worldClass;
	//public var testingClass:Testing;
	string lastClass;
	//public var tracker:AnalyticsTracker;
	//public var IDIClass:Object;
	bool ourNet;
	string domainName;

	static int fps;
	

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	static const int SCREEN_WIDTH_HALF = 400;
	static const int SCREEN_HEIGHT_HALF = 300;

	static const int SCREEN_WIDTH_OUT_LEFT = 0;
	static const int SCREEN_HEIGHT_OUT_TOP = 0;
	static const int SCREEN_HEIGHT_OUT_DOWN = 0;

	static Main *mainClass;


	Main();
	//CREATE_FUNC(Main);
	virtual bool init();
	static Scene* createScene();

	void addNewScreen(string param1);

	void removeAllScreens();

    cocos2d::Image getBitmapData(cocos2d::Node* param1);

    void keyDownHandler(EventKeyboard::KeyCode keycode, cocos2d::Event *event);

    void addStartLogo();


};

#endif
