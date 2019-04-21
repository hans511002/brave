#ifndef TRAINING_TRAINING_H
#define TRAINING_TRAINING_H
#include "BaseHeaders.h"   

namespace training
{
	class Training : public BaseNode
	{
	public:
		int i, j;
		int frameCounter;
		bool openFlag;
		bool closeFlag;
		bool dead;
		World* world;

		Training() :openFlag(true), closeFlag(false), dead(false), frameCounter(0), world(NULL) {};
		virtual void enterFrameHandler(float dt) {};

		virtual void manageListeners(string param1);
		virtual bool preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType);
		virtual void mouseMoveHandler(cocos2d::EventMouse * event) {};
		virtual void mouseDownHandler(cocos2d::EventMouse * event) {};
		virtual void mouseUpHandler(cocos2d::EventMouse * event) {};
	};

}
#endif

