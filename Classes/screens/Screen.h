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
		virtual bool  preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType) { return false; };

		//void focusChanged(cocos2d::EventFocus * e);
		//void enableFocusEvent();
        Screen();
    };
	struct Back_mc : public MovieClip
	{
		MCCase * backCase;
		Back_mc();
	};
}
#endif
