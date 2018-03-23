#include "MainCLass.h"
#include "engine/World.h"
Main * Main::mainClass;
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
	//this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
	//this.stage.addEventListener(KeyboardEvent.KEY_DOWN, this.keyDownHandler);
	
	//this.stage.scaleMode = StageScaleMode.SHOW_ALL;
	//this.stage.align = StageAlign.TOP_LEFT;
	//this.boldTextFormat = new TextFormat();
	//this.boldTextFormat.bold = true;
	double aniInterval = Director::getInstance()->getAnimationInterval()-0.00000001;
	aniInterval = 1 / aniInterval;
	Main::fps = aniInterval;
	float psf= Director::getInstance()->getSecondsPerFrame();
	CCLOG("fps=%i", Main::fps);

	this->saveBoxClass = new SaveBox();
	//this->readXMLClass = new ReadXML();
	//Sounds.instance.stopAll();
	//this.tracker = new GATracker(this, "UA-63231445-3", "AS3", false);
	//this.tracker.trackPageview("openGame");
	Main::mainClass->worldClass = World::create();// new World();
	return true;
}// end function

void Main::addNewScreen(string param1)
{
	//if (this.middleScreenClass)
	//{
	//	if (param1 == "StartMenu")
	//	{
	//		var _loc_2 : *= new StartMenu();
	//		this.container = new StartMenu();
	//		this.startMenuClass = _loc_2;
	//		this.addChild(this.startMenuClass);
	//	}
	//	else if (param1 == "LevelsMenu")
	//	{
	//		var _loc_2 : *= new LevelsMenu();
	//		this.container = new LevelsMenu();
	//		this.levelsMenuClass = _loc_2;
	//		this.addChild(this.levelsMenuClass);
	//	}
	//	else if (param1 == "World")
	//	{
	//		var _loc_2 : *= new World();
	//		this.container = new World();
	//		this.worldClass = _loc_2;
	//		this.addChild(this.worldClass);
	//	}
	//	this.bmp = new Bitmap(this.getBitmapData(this.container));
	//	this.addChild(Main.mainClass.bmp);
	//	this.container.visible = false;
	//	this.setChildIndex(this.middleScreenClass, (this.numChildren - 1));
	//	this.setChildIndex(this.IDIClass, (this.numChildren - 1));
	//}
	//else
	//{
	//	if (this.container)
	//	{
	//		this.bmp = new Bitmap(this.getBitmapData(this.container));
	//		this.addChild(Main.mainClass.bmp);
	//		this.container.visible = false;
	//	}
	//	this.middleScreenClass = new MiddleScreen(param1);
	//	this.addChild(this.middleScreenClass);
	//}
	//return;
}// end function
void Main::removeAllScreens()
{
	//if (this.bmp)
	//{
	//	this.removeChild(this.bmp);
	//	this.bmp = null;
	//}
	//if (this.startMenuClass)
	//{
	//	this.lastClass = "StartMenu";
	//	this.removeChild(this.startMenuClass);
	//	this.startMenuClass = null;
	//}
	//if (this.levelsMenuClass)
	//{
	//	this.lastClass = "LevelsMenu";
	//	this.removeChild(this.levelsMenuClass);
	//	this.levelsMenuClass = null;
	//}
	//if (this.worldClass)
	//{
	//	this.lastClass = "World";
	//	this.removeChild(this.worldClass);
	//	this.worldClass = null;
	//}
	//this.container = null;
	//this.saveBoxClass.updateSever();
	//return;
}// end function