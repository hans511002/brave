#ifndef SCREENS_STARTMENU_H
#define SCREENS_STARTMENU_H
#include "Screen.h"   

namespace engine
{
    class World;
}
using namespace engine;

namespace screens
{  
    struct StartMenu_mc : public MovieClip
    {
        MovieClip * back;
        MovieClip * btnIdnet;
        MovieClip * btnMusic;
        MovieClip * btnSound;
        MovieClip * btnY8;
        MovieClip * credits;
        MovieClip * game1;
        MovieClip * game2;
        MovieClip * game3;
        MovieClip * glitter;
        MovieClip * logOut;
        MovieClip * logo;
        MovieClip * question;
        MovieClip * saveType;
        MovieClip * start;

        StartMenu_mc();
    };

    class StartMenu : public Screen
    {
    public:
        //public var tempObject:Object;
        StartMenu_mc * container;
        bool firstPlay;
        int page ;
        int question ;
        Credits* creditsClass;
        bool loginFlag;
        int loginFlag1 ;
        string welcomeText , nickText ;
        int waitCounter;
        int syncLoginCounter;
        Hint_mc * syncHint; 
        static bool firstMusicPlay;

        StartMenu();
        bool init() ;

        void enterFrameHandler(cocos2d::Event * event);

        void mouseMoveHandler(cocos2d::Event * param1)  ;

        void mouseDownHandler(cocos2d::Event * event) ;

        void mouseUpHandler(cocos2d::Event * event) ;

        void autoguidersButtons() ;

        void manageListeners(param1:String) ;

        //void reInit(event:Event);

    }
}
#endif
