#ifndef TRAINING_TRAINING_3_H
#define TRAINING_TRAINING_3_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
    struct Training_3_mc : public MovieClip {
        Training_3_mc() ;
    };

    class Training_3 :public Training
    {
    public: 
        Training_3_mc* container;
        int phase;

        Training_3();

        bool init();

        void enterFrameHandler(float dt);

        void mouseMoveHandler(cocos2d::EventMouse * e);

        void mouseDownHandler(cocos2d::EventMouse * e) ;

        void mouseUpHandler(cocos2d::EventMouse * e) ;

        void close() 
        {
            return;
        }// end function

        void kill()  ;

        //void reInit(event:Event) : void
        //{
        //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //    this->world.removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //    this->world.removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //    this->world.removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        //    return;
        //}// end function

    };
}
#endif
