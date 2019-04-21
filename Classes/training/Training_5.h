#ifndef TRAINING_TRAINING_5_H
#define TRAINING_TRAINING_5_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;

namespace training
{
	struct Training_5_mc : public MovieClip {
		Training_5_mc();
		MovieClipSub * cont;
		MovieClipSub * contCont1;
		MovieClipSub * contCont1BtnLeft;
		MCCase * contCont1BtnLeftArrowCase;
		MovieClipSub * contCont1BtnRight;
		MCCase * contCont1BtnRightArrowCase;
		MovieClipSub * contCont1BtnOk;
		MCCase * contCont1BtnOkOkCase;
	};

	class Training_5 :public Training
	{
	public:
		Training_5_mc * container;
		int type;
		int page;
		int viewCounter;

		Training_5(int param1);

		virtual bool init();

		virtual void enterFrameHandler(float dt);

		virtual void mouseMoveHandler(cocos2d::EventMouse * e);

		virtual void mouseDownHandler(cocos2d::EventMouse * e);

		virtual void mouseUpHandler(cocos2d::EventMouse * e);

		virtual void contStops();


		virtual  void close();

		virtual void kill();

		//public function reInit(event:Event) : void
		//{
		//    this->removeEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//    this->removeEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		//    this->removeEventListener(MouseEvent->MOUSE_MOVE, this->mouseMoveHandler);
		//    this->removeEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
		//    this->removeEventListener(MouseEvent->MOUSE_UP, this->mouseUpHandler);
		//    return;
		//}// end function

	};
}
#endif
