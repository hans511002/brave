#ifndef SCREENS_PREVICTORY_H 
#define SCREENS_PREVICTORY_H
#include "BaseHeaders.h"   
#include "Screen.h"

namespace screens
{
	struct PreVictory_mc :public MovieClip
	{
		MovieClipSub * cont;
		MovieClipSub * contBtnOk;
		MCCase * contBtnOkOkCase;
		PreVictory_mc();
	};
	class PreVictory :public Screen
	{
	public:
		PreVictory_mc * container;

		PreVictory();

		virtual bool init();

		virtual void enterFrameHandler(float dt);

		virtual void mouseMoveHandler(cocos2d::EventMouse * e);

		virtual void mouseDownHandler(cocos2d::EventMouse * e);

		virtual void mouseUpHandler(cocos2d::EventMouse * e);

		virtual void stopAll();;

		virtual void close();

		virtual void kill();

	};
}
#endif
