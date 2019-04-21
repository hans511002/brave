#ifndef TRAINING_TRAINING_2_H
#define TRAINING_TRAINING_2_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_2_mc : public MovieClip {
		MovieClipSub * cont;
		MovieClipSub * contBtnOk;
		MCCase * contBtnOkOkCase; 
		Training_2_mc();
	};
	class Training_2 : public Training
	{
	public:
		Training_2_mc * container;
		Training_2();

		virtual  bool init();

		virtual  void enterFrameHandler(float dt);

		virtual void mouseMoveHandler(cocos2d::EventMouse * e);

		virtual void mouseDownHandler(cocos2d::EventMouse * e);

		virtual void mouseUpHandler(cocos2d::EventMouse * e);

		virtual void contStops();


		virtual void close();

		virtual void kill();

		//void reInit(event:Event) : void
		//{
		//    this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
		//    this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
		//    this.removeEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
		//    this.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
		//    this.removeEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
		//    return;
		//}// end function

	};
}
#endif
