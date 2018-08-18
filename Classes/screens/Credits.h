#ifndef SCREENS_CREDITS_H
#define SCREENS_CREDITS_H
#include "Screen.h"   

 
namespace screens
{   
    struct Credits_mc : public MovieClip
    {
        MovieClip * cont;
        MovieClip * shadow;

        Credits_mc();
    };
    
    class Credits : public Screen
    {
    public:
         //public var tempObject:Object;
        Credits_mc * container; 

        Credits()
        {
            //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            return;
        }// end function

		virtual bool init();

		virtual void stopManage();

		virtual void enterFrameHandler(float dt);

		virtual void mouseMoveHandler(cocos2d::EventMouse * param1) ;

		virtual void mouseDownHandler(cocos2d::EventMouse * event) ;
		virtual void mouseUpHandler(cocos2d::EventMouse *event);

		virtual void autoguidersButtons();

		virtual void close();

		virtual void kill();

        //void reInit(event:Event) ;
    }
}
#endif
