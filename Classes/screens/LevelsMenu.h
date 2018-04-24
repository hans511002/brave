#ifndef SCREENS_LEVELSMENU_H
#define SCREENS_LEVELSMENU_H
#include "BaseHeaders.h" 
#include "sys/saveBox.h"
//#include "engine/World.h"
#include "engine/xml/ReadXML.h"
#include "OpenLevel.h"
#include "engine/level/Level.h"
using namespace engine;

namespace screens
{
    struct NewLevel_mc:public MovieClip
    {
        
    };
    struct LevelsMenu_mc :public MovieClip
    {
        MovieClip * achieves;
        MovieClip * back;
        MovieClip * book;
        MovieClip * btnMusic;
        MovieClip * btnSound;
        MovieClip * freeStars;
        MovieClip * level1;
        MovieClip * level10;
        MovieClip * level11;
        MovieClip * level12;
        MovieClip * level13;
        MovieClip * level14;
        MovieClip * level15;
        MovieClip * level2;
        MovieClip * level3;
        MovieClip * level4;
        MovieClip * level5;
        MovieClip * level6;
        MovieClip * level7;
        MovieClip * level8;
        MovieClip * level9;
        MovieClip * road;
        MovieClip * upgrades;
        MovieClip * wavesAnimation;

        LevelsMenu_mc()
        {
            return;
        }// end function

    };
    
    class LevelsMenu :public BaseNode
    {
    public:
        int i;//public var i:int;
        //public var tempObject:Object;
        //public var tempObject1:Object;
        //public var container:LevelsMenu_mc;
        int frameCounter;//public var frameCounter:int = 0;
        Common::Array<engine::Level *> listOfLevels;//public var listOfLevels:Array;
        int newLevel;//public var newLevel:int = 0;
        dragonBones::CCArmatureDisplay * newLevelGr;// public var newLevelGr:NewLevel_mc;
        bool roadOff;//public var roadOff:Boolean;
        int newStarsForLevel;//public var newStarsForLevel:int = 0;
        Node * mouseMoveTarget;
        Node * mouseDownTarget;
        Common::Array<dragonBones::CCArmatureDisplay * > listOfAnimation;
        OpenLevel * openLevel;
        //Upgrades * upgradesClass;
        //Encyclopedia * encyclopediaClass;
        //Achievements * achievementsClass;
        bool firstMusicPlay;
        //DifficultyLevel * difficultyLevel;
        //public var training_1:Training_1;
        //public var training_9:Training_9;
        cocos2d::Point autoguidesMouse_pt;//public var autoguidesMouse_pt:Point;
        Node * autoguidesObject;//public var autoguidesObject:Object;
        cocos2d::Point autoguidesObject_pt;//public var autoguidesObject_pt:Point;
        float autoguidesObjectWidth;
        float autoguidesObjectHeight;

        LevelsMenu();

        bool init();

        void enterFrameHandler(cocos2d::Event * event);

        void mouseMoveHandler(cocos2d::Event * param1);

        void mouseDownHandler(cocos2d::Event * event);

        void mouseUpHandler(cocos2d::Event * event);

        void preparationLevels();

        void openNewLevel();

        void openNewStarsForLevel();

        void autoguidersButtons();

        void manageListeners(string param1);

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
