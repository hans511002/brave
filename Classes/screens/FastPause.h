﻿#ifndef SCREENS_FASTPAUSE_H
#define SCREENS_FASTPAUSE_H
#include "BaseHeaders.h" 

using namespace engine;

namespace screens
{
    struct FastPause_mc : public MovieClip
    {
        FastPause_mc();
    };
    
	class FastPause :public Screen
	{
	public:
		FastPause_mc *container;
		World * world;
		float startMusicVolume;

		FastPause();

		virtual bool init();

		virtual void enterFrameHandler(float dt);

		virtual void mouseDownHandler(cocos2d::EventMouse * event);

		virtual void kill();

		//void reInit(event:Event) 
		//{
		//    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
		//    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
		//    this->removeEventListener(MouseEvent.CLICK, this->mouseClickHandler);
		//    if (Sounds.instance.musicChanel)
		//    {
		//        AudioUtil::setMusicVolume(this->startMusicVolume);
		//    }
		//    if (this->world->getSphere || this->world->cast)
		//    {
		//        this->world->manageMouse("hide");
		//    }
		//    return;
		//}// end function

	};
}
#endif
