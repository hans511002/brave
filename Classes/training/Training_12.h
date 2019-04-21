#ifndef TRAINING_TRAINING_12_H
#define TRAINING_TRAINING_12_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_12_mc : public MovieClip {

		Training_12_mc();
	};
	class Training_12 : public Training
	{
	public:
		MovieClip* container;
		TowerMenu* myTowerMenu;

		Training_12();

		virtual bool init();

		virtual void enterFrameHandler(float dt);

		virtual void mouseDownHandler(cocos2d::EventMouse * e);

		virtual void kill();

		//public function reInit(event:Event) : void
		//{
		//    this->removeEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//    this->removeEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		//    this->world->removeEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
		//    return;
		//}// end function

	};
}
#endif

