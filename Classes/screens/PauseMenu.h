#ifndef SCREENS_PAUSEMENU_H
#define SCREENS_PAUSEMENU_H
#include "BaseHeaders.h" 
#include "sys/saveBox.h"
//#include "engine/World.h"
#include "engine/xml/ReadXML.h"
 
 

namespace screens
{
 
    struct PauseMenu_mc : public MovieClip
    {
        MovieClip * scroll;
        MovieClip * shadow;        
    };
    class PauseMenu : public BaseNode
    {
    public:
        int i;
        //public var tempObject:Object;
        //public var tempObject1:Object;
        //public var tempObject2:Object;
        PauseMenu_mc * container;
        int frameCounter;
        bool openFlag;
        bool closeFlag;
        World * world;
        int questionFlag;
        float startMusicVolume;
        cocos2d::Point autoguidesMouse_pt;
        //public var autoguidesObject:Object;
        cocos2d::Point autoguidesObject_pt;
        float autoguidesObjectWidth;
        float autoguidesObjectHeight;

        PauseMenu();

		virtual bool init();

		virtual void enterFrameHandler(cocos2d::EventMouse * event);

		virtual void mouseMoveHandler(cocos2d::EventMouse *param1);

		virtual void mouseDownHandler(cocos2d::EventMouse *event);

		virtual void mouseUpHandler(cocos2d::EventMouse * event);

		virtual void autoguidersButtons();

		virtual void close();

        //void reInit(event:Event);

    };
}
#endif
