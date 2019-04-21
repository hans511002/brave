#ifndef TRAINING_TRAINING_4_H
#define TRAINING_TRAINING_4_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_4_mc : public MovieClip {
		Training_4_mc();
	};

	class Training_4 :public Training
	{
	public:
		Training_4_mc * container;

		Training_4();

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
