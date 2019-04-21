#ifndef TRAINING_TRAINING_8_H
#define TRAINING_TRAINING_8_H
#include "BaseHeaders.h" 
#include "Training.h"
#include "base/mc.h"
using namespace engine;


namespace training
{
	struct Training_8_mc : public MovieClip {
		Training_8_mc();
		MovieClipSub * cont;
		MovieClipSub * contCont1;
		MovieClipSub * contCont1BtnLeft;
		MCCase * contCont1BtnLeftArrowCase;
		MovieClipSub * contCont1BtnRight;
		MCCase * contCont1BtnRightArrowCase;
		MovieClipSub * contCont1BtnOk;
		MCCase * contCont1BtnOkOkCase;
	};

	class Training_8 :public Training
	{
	public:
		Training_8_mc * container;
		int type;
		int page;
		int viewCounter;

		Training_8(int param1);

		virtual bool init();

		virtual void enterFrameHandler(float dt);

		virtual void mouseMoveHandler(cocos2d::EventMouse * e);

		virtual void mouseDownHandler(cocos2d::EventMouse * e);

		virtual void mouseUpHandler(cocos2d::EventMouse * e);

		virtual void contStops();

		virtual void close();

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

