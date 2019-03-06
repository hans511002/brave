#ifndef SCREENS_SCREEN_H
#define SCREENS_SCREEN_H
#include "BaseHeaders.h"   

namespace screens
{   
    class Screen : public BaseNode
    {
    public:
        int i,j;
        int frameCounter;
        bool openFlag;
        bool closeFlag;
        bool dead;
        
        cocos2d::Point autoguidesMouse_pt;
        BaseNode * autoguidesObject;
        cocos2d::Point autoguidesObject_pt;
        float autoguidesObjectWidth;
        float autoguidesObjectHeight;
		virtual void manageListeners(string param1);
		cocos2d::EventListenerFocus * focusListener;

		//void focusChanged(cocos2d::EventFocus * e);
		//void enableFocusEvent();
        Screen();
        virtual void enterFrameHandler(float dt){};
		
		virtual bool preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType);
		virtual void mouseMoveHandler(cocos2d::EventMouse * event){};
		virtual void mouseDownHandler(cocos2d::EventMouse * event){};
		virtual void mouseUpHandler(cocos2d::EventMouse * event){};
    };
	struct Back_mc : public MovieClip
	{
		MCCase * backCase;
		Back_mc();
	};
}
#endif
