#ifndef TRAINING_TRAINING_2_H
#define TRAINING_TRAINING_2_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
    struct Training_2_mc : public MovieClip {
        Training_2_mc() ;
    };
    class Training_1 : public Training
    {
    public: 
        Training_2_mc * container;  
        Training_2();

        bool init();

        void enterFrameHandler(float dt)  ;

        void mouseMoveHandler(cocos2d::EventMouse * e)  ;

        void mouseDownHandler(cocos2d::EventMouse * e) ;

        void mouseUpHandler(cocos2d::EventMouse * e);

        void contStops() ;
 

        void close() ;

        void kill() ;

        //void reInit(event:Event) : void
        //{
        //    this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
        //    this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
        //    this.removeEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
        //    this.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
        //    this.removeEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
        //    return;
        //}// end function

    };
}
#endif
