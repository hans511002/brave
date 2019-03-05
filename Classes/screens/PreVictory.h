#ifndef SCREENS_PREVICTORY_H 
#define SCREENS_PREVICTORY_H
#include "BaseHeaders.h"   
#include "Screen.h"

namespace screens
{ 
    struct PreVictory_mc:public MovieClip
    {
        MovieClipSub * cont;
        MovieClipSub * contBtnOk;
        MCCase * contBtnOkOkCase;
        PreVictory_mc();
    };
    class PreVictory :public Screen
    { 
        PreVictory_mc * container;  

         PreVictory();

        bool init();

        void enterFrameHandler(float dt);

        void mouseMoveHandler(cocos2d::EventMouse * event) ;

        void mouseDownHandler(cocos2d::EventMouse * event);

        void mouseUpHandler(cocos2d::EventMouse * event);

        void stopAll() ;;

        void close() ;

        void kill() ; 

    };
}
#endif
