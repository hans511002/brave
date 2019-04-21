#ifndef TRAINING_TRAINING_6_H
#define TRAINING_TRAINING_6_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_6_mc : public MovieClip {
		Training_6_mc();
	};

	class Training_6 :public Training
	{
	public:

		Training_6_mc* container;

		Training_6();

		virtual bool init();

		virtual void enterFrameHandler(float dt);

		virtual void kill();

		//public function reInit(event:Event) : void
		//{
		//    this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
		//    this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
		//    return;
		//}// end function

	};
}
#endif

