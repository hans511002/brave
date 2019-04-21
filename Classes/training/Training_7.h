#ifndef TRAINING_TRAINING_7_H
#define TRAINING_TRAINING_7_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_7_mc : public MovieClip {
		Training_7_mc();
	};

	class Training_7 :public Training
	{
	public:
		Training_7_mc* container;
		string type;

		Training_7(const string & param1);

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
