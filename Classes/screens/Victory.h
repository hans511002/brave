#ifndef SCREENS_VICTORY_H 
#define SCREENS_VICTORY_H
#include "BaseHeaders.h"   
#include "Screen.h"

namespace screens
{
	class Victory :public Screen
	{
	public:
		MovieClip container;
		int starsFlag;
		World * world;
		bool firstSoundPlay;

		Victory();
		virtual bool init();
		virtual void enterFrameHandler(float dt);

		virtual void mouseMoveHandler(cocos2d::EventMouse * event);

		virtual void mouseDownHandler(cocos2d::EventMouse * event);

		virtual void mouseUpHandler(cocos2d::EventMouse * event);

		//virtual void link1Play(event:VideoEvent);

		//virtual void link2Play(event:VideoEvent);

		//virtual void link3Play(event:VideoEvent);

		virtual void removeLinksListeners();


	};
}
#endif
