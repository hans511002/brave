#ifndef SCREENS_DEFEAT_H
#define SCREENS_DEFEAT_H
#include "BaseHeaders.h"   

namespace engine
{
    class World;
}
using namespace engine;

namespace screens
{  
    struct DefMenu_mc : public MovieClip
    {
        MovieClip * first;
        MovieClip * shadow;
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

        void mouseMoveHandler(cocos2d::Event * event) ;

        void mouseDownHandler(cocos2d::Event * event);

        void mouseUpHandler(cocos2d::Event * event);

        //void reInit() 
        //{
        //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        //    return;
        //}// end function

    }
}
#endif
