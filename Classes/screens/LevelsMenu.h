#ifndef SCREENS_LEVELSMENU_H
#define SCREENS_LEVELSMENU_H
#include "BaseHeaders.h" 
#include "sys/saveBox.h"
//#include "engine/World.h"
#include "engine/xml/ReadXML.h"
#include "OpenLevel.h"
#include "engine/level/Level.h"
#include "Screen.h"
using namespace engine;

namespace screens
{
    struct NewLevel_mc:public MovieClip
    {
        
    };
	struct Level_mc:public MovieClip
	{
		MCCase * levelCase;
		MovieClipSub * star1;
		MovieClipSub * star2;
		MovieClipSub * star3;
		MovieClipSub *towerEffect;
		MovieClipSub *wreath;
		Level_mc();
	};
    struct LevelsMenu_mc :public MovieClip
    {
        MovieClipSub * achieves;
		MCCase * achievesAchievesCase1;
		MCCase * achievesAchievesCase2;
        MovieClipSub * back;
		MCCase * backBackCase;
		MovieClipSub * book;
		MCCase * bookBookCase1;
		MCCase * bookBookCase2;
        MovieClipSub * btnMusic;
		MCCase * btnMusicMusicCase;
        MovieClipSub * btnSound;
		MCCase * btnSoundSoundCase;
		MovieClipSub * freeStars;
		MovieClipSub * freeStarsCont;
		MCText * freeStarsContStarsTXT;
		Level_mc * level1;
		Level_mc * level2;
		Level_mc * level3;
		Level_mc * level4;
		Level_mc * level5;
		Level_mc * level6;
		Level_mc * level7;
		Level_mc * level8;
		Level_mc * level9;
		Level_mc * level10;
		Level_mc * level11;
		Level_mc * level12;
		Level_mc * level13;
		Level_mc * level14;
		Level_mc * level15;
		MovieClipSub * road;
        MovieClipSub * upgrades;
		MCCase * upgradesUpgradesCase1;
		MCCase * upgradesUpgradesCase2;
		MovieClipSub * upgradesFireCont;

        MovieClipSub * wavesAnimation;
		Map<std::string, MovieClipSub *> waves;

		LevelsMenu_mc();

    };
    
    class LevelsMenu :public Screen
    {
    public:
         //public var tempObject:Object;
        //public var tempObject1:Object;
        LevelsMenu_mc * container;
        int frameCounter;//public var frameCounter:int = 0;
        Common::Array<Level_mc *> listOfLevels;//public var listOfLevels:Array;
        int newLevel;//public var newLevel:int = 0;
        dragonBones::CCArmatureDisplay * newLevelGr;// public var newLevelGr:NewLevel_mc;
        bool roadOff;//public var roadOff:Boolean;
        int newStarsForLevel;//public var newStarsForLevel:int = 0;
        Node * mouseMoveTarget;
        Node * mouseDownTarget;
        Common::Array<MovieClipSub * > listOfAnimation;
        OpenLevel * openLevel;
        //Upgrades * upgradesClass;
        //Encyclopedia * encyclopediaClass;
        //Achievements * achievementsClass;
        bool firstMusicPlay;
        //DifficultyLevel * difficultyLevel;
        //public var training_1:Training_1;
        //public var training_9:Training_9;
 

        LevelsMenu();

		virtual bool init();

		virtual void enterFrameHandler(cocos2d::EventMouse * event);

		virtual void mouseMoveHandler(cocos2d::EventMouse * param1);

		virtual  void mouseDownHandler(cocos2d::EventMouse * event);

		virtual void mouseUpHandler(cocos2d::EventMouse * event);

		virtual  void preparationLevels();

		virtual void openNewLevel();

		virtual void openNewStarsForLevel();

		virtual void autoguidersButtons();

		virtual void manageListeners(string param1);

        //void reInit(event:Event) 
        //{
        //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        //    return;
        //}// end function
    };
}
#endif
