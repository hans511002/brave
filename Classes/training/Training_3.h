#ifndef TRAINING_TRAINING_3_H
#define TRAINING_TRAINING_3_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_3_mc : public MovieClip {
		Sprite * bg;
		Slot * bgSlot;
		Training_3_mc();
		virtual void gotoAndStop(int cf, const string &  aniName = "");
	};

	class Training_3 :public Training
	{
	public:
		Training_3_mc* container;
		int phase;

		Training_3();

		virtual bool init();

		virtual void enterFrameHandler(float dt);
		virtual bool preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType
			_mouseEventType);
		virtual  void mouseMoveHandler(cocos2d::EventMouse * e);

		virtual  void mouseDownHandler(cocos2d::EventMouse * e);

		virtual void mouseUpHandler(cocos2d::EventMouse * e);

		virtual void close();

		virtual void kill();

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
