#ifndef SCREENS_ACHIEVEMENTS_H
#define SCREENS_ACHIEVEMENTS_H
#include "Screen.h"   

namespace screens
{   
    struct Achievements_mc : public MovieClip
    {
        MovieClip *  back ;
        MovieClip *  cont ;
        MovieClip *  shadow;

        Achievements_mc();
    };
    class Achievements : public Screen
    {
    public:
        //public var tempObject:Object;
        Achievements_mc * container;
         
        int  page;
        int fireFrame ;  

        Achievements();

        bool init(float dt);
        void enterFrameHandler(float dt);

        void mouseMoveHandler(cocos2d::EventMouse * event);

        void mouseDownHandler(cocos2d::EventMouse * event);

        void mouseUpHandler(cocos2d::EventMouse * event);

        void pageManage(int param1)  ;

        void autoguidersButtons()  ;

        void close()  ;

        void kill()  ;

		void  manageListeners(string param1);


	};
}
#endif
