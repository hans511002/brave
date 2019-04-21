#ifndef TRAINING_TRAINING_11_H
#define TRAINING_TRAINING_11_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_11_mc : public MovieClip {

		Training_11_mc();
	};
	struct Training_11_01_mc : public MovieClip {
		Training_11_01_mc();
	};
	class Training_11 : public Training
	{
	public:
		MovieClip * container;
		int type;

		Training_11(int param1);

		virtual bool init();

		virtual void enterFrameHandler(float dt);

		virtual void mouseDownHandler(cocos2d::EventMouse * e);

		virtual void kill();

		//public function reInit(event:Event) : void
		//{
		//    this->removeEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//    this->removeEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		//    this->world->worldInterface->removeEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
		//    return;
		//}// end function

	};
}
#endif
