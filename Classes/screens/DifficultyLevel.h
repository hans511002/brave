#ifndef SCREENS_DIFFICULTYLEVEL_H
#define SCREENS_DIFFICULTYLEVEL_H
#include "Screen.h"   
 
namespace screens
{   
    struct DeifficultyLevel_mc  : public MovieClip
    {
        MovieClipSub* first;
        MovieClipSub* firstEasy;
        MovieClipSub* firstNormal;
        MovieClipSub* firstHard;
        MCCase *  firstEasyComplexityCase;
        MCCase *  firstNormalComplexityCase;
        MCCase *  firstHardComplexityCase;
        //MovieClipSub* shadow;
        DeifficultyLevel_mc();

    };
     class DifficultyLevel :public Screen
    {
    public: 
        //public var tempObject:Object;
        DeifficultyLevel_mc * container;
        bool openFlag ;
        bool closeFlag;
 

        DifficultyLevel();

        bool init();

        void enterFrameHandler(float dt=0);

        void mouseMoveHandler(cocos2d::EventMouse * e);

        void mouseDwonHandler(cocos2d::EventMouse *e) ;

        void mouseUpHandler(cocos2d::EventMouse * e);

        void autoguidersButtons();

        //void reInit(event:Event);

	 };
}
#endif
