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

        bool init();

        void stopManage();

        void enterFrameHandler(float dt);

        void mouseMoveHandler(cocos2d::Event * param1) ;

        void mouseDownHandler(cocos2d::Event * event) ;
        void mouseUpHandler(cocos2d::Event *event);

        void autoguidersButtons();

        void close();

        void kill();

        //void reInit(event:Event) ;
    }
}
#endif
