#ifndef TRAINING_TRAINING_9_H
#define TRAINING_TRAINING_9_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_9_mc : public MovieClip {
		Training_9_mc();
	};

	class Training_9 :public Training
	{
	public:
		Training_9_mc * container;

		Training_9();

		virtual bool init();

		virtual void enterFrameHandler(float dt);

		virtual void kill();

		//public function reInit(event:Event) : void
		//{
		//    this->removeEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//    this->removeEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		//    return;
		//}// end function

	};
}
#endif

