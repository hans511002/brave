#ifndef SCREENS_DEFEAT_H
#define SCREENS_DEFEAT_H
#include "BaseHeaders.h"   
#include "Screen.h"

 
namespace screens
{  
    struct DefMenu_mc : public MovieClip
    {
		MovieClipSub * first;
		MovieClipSub * firstScroll;
		MovieClipSub * firstFire;
		MovieClipSub * firstScrollBtnContinue;
		MCCase * firstScrollBtnContinueContinueCase;
		MovieClipSub * firstScrollBtnContinueArrow;

		MovieClipSub * firstScrollBtnRestart;
		MCCase * firstScrollBtnRestartRestartCase;
		MovieClipSub * firstScrollBtnRestartArrow;
		
		cocos2d::Sprite * logo;

        DefMenu_mc() ;
    };


    class Defeat : public Screen
    {
    public:
        int i,j;
        //tempObject:Object;
        //tempObject1:Object;
        DefMenu_mc * container; 
        World * world;
        bool firstSoundPlay;

        Defeat();

        bool init() ;

        void enterFrameHandler(float dt);

        void mouseMoveHandler(cocos2d::EventMouse * event) ;

        void mouseDownHandler(cocos2d::EventMouse * event);

        void mouseUpHandler(cocos2d::EventMouse * event);
		 
	};
}
#endif
