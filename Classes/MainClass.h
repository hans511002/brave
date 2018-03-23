#ifndef BRAVE_MAIN_H
#define BRAVE_MAIN_H
#include "BaseHeaders.h" 
#include "sys/saveBox.h"
//#include "engine/World.h"
#include "engine/xml/ReadXML.h"
//#include "screens/*.h"
namespace engine{
	class World;
}
using namespace engine;
//using namespace screens;
using namespace sys;

class Main //: public  cocos2d::Node //cocos2d::LayerColor //
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
	//MiddleScreen * middleScreenClass;//public var middleScreenClass:MiddleScreen;
	//LevelsMenu * levelsMenuClass;//public var levelsMenuClass:LevelsMenu;
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

	cocos2d::Image getBitmapData(cocos2d::Node* param1) //: BitmapData
	{
		/*  this.bd = new BitmapData(param1.width, param1.height);
		  this.bd.draw(param1);
		  return this.bd;*/
	}// end function

	void keyDownHandler(cocos2d::EventKeyboard event)
	{
		/*           if (event.charCode == 49)
				   {
				   if (this.worldClass)
				   {
				   if (!this.worldClass.menuObject && this.worldClass.firstMusicPlay)
				   {
				   if (this.worldClass.cast)
				   {
				   if (!(this.worldClass.cast is Cast_1))
				   {
				   this.worldClass.worldInterface.breaking();
				   }
				   else
				   {
				   this.worldClass.worldInterface.breaking();
				   return;
				   }
				   }
				   if (this.worldClass.worldInterface.container.butCastGolem.visible && this.worldClass.worldInterface.container.butCastGolem.currentFrame < 4)
				   {
				   if (this.worldClass.worldInterface.container.mouseEnabled)
				   {
				   this.worldClass.worldInterface.castGolem();
				   this.worldClass.worldInterface.container.butCastGolem.gotoAndStop(5);
				   }
				   }
				   }
				   }
				   }
				   else if (event.charCode == 50)
				   {
				   if (this.worldClass)
				   {
				   if (!this.worldClass.menuObject && this.worldClass.firstMusicPlay)
				   {
				   if (this.worldClass.cast)
				   {
				   if (!(this.worldClass.cast is Cast_2))
				   {
				   this.worldClass.worldInterface.breaking();
				   }
				   else
				   {
				   this.worldClass.worldInterface.breaking();
				   return;
				   }
				   }
				   if (this.worldClass.worldInterface.container.butCastIceman.visible && this.worldClass.worldInterface.container.butCastIceman.currentFrame < 4)
				   {
				   if (this.worldClass.worldInterface.container.mouseEnabled)
				   {
				   this.worldClass.worldInterface.castIceman();
				   this.worldClass.worldInterface.container.butCastIceman.gotoAndStop(5);
				   }
				   }
				   }
				   }
				   }
				   else if (event.charCode == 51)
				   {
				   if (this.worldClass)
				   {
				   if (!this.worldClass.menuObject && this.worldClass.firstMusicPlay)
				   {
				   if (this.worldClass.cast)
				   {
				   if (!(this.worldClass.cast is Cast_3))
				   {
				   this.worldClass.worldInterface.breaking();
				   }
				   else
				   {
				   this.worldClass.worldInterface.breaking();
				   return;
				   }
				   }
				   if (this.worldClass.worldInterface.container.butCastAir.visible && this.worldClass.worldInterface.container.butCastAir.currentFrame < 4)
				   {
				   if (this.worldClass.worldInterface.container.mouseEnabled)
				   {
				   this.worldClass.worldInterface.castAir();
				   this.worldClass.worldInterface.container.butCastAir.gotoAndStop(5);
				   }
				   }
				   }
				   }
				   }
				   else if (event.charCode == 109 || event.charCode == 77)
				   {
				   if (this.worldClass)
				   {
				   if (Sounds.instance.musicOn)
				   {
				   Sounds.instance.musicManage("off");
				   }
				   else
				   {
				   Sounds.instance.musicManage("on");
				   }
				   }
				   }
				   else if (event.charCode == 115 || event.charCode == 83)
				   {
				   if (this.worldClass)
				   {
				   if (Sounds.instance.soundOn)
				   {
				   Sounds.instance.soundManage("off");
				   }
				   else
				   {
				   Sounds.instance.soundManage("on");
				   }
				   }
				   }
				   return;*/
	}// end function

	void addStartLogo()
	{
		/*var _loc_1:* = new StartMenu();
		this.container = new StartMenu();
		this.startMenuClass = _loc_1;
		this.addChild(this.startMenuClass);
		return;*/
	}// end function


};

#endif
