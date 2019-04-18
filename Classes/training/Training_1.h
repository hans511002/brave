#ifndef TRAINING_TRAINING_1_H
#define TRAINING_TRAINING_1_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_1_mc : public MovieClip {
		Training_1_mc() :MovieClip("training", "Training_1_mc", "Training_1_mc") {};
	};
	class Training_1 : public Training
	{
	public:

		//public var tempObject:Object;
		Training_1_mc * container;

		Training_1();

		bool init();

		void enterFrameHandler(float dt);

		void kill();

		//public function reInit(event:Event) : void
		//{
		//    this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
		//    this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
		//    return;
		//}// end function

	};

}
#endif
