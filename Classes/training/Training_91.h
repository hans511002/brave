#ifndef TRAINING_TRAINING_91_H
#define TRAINING_TRAINING_91_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;


namespace training
{
	struct Training_91_mc : public MovieClip {
		Training_91_mc();
	};

	class Training_91 :public Training
	{
	public:
		Training_91_mc * container;
		int myLevel;

		Training_91(int param1);

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
