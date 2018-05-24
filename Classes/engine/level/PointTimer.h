#ifndef ENGINE_LVEL_POINITTIMER_H
#define ENGINE_LVEL_POINITTIMER_H
#include "BaseHeaders.h"

namespace engine{

	class PointTimer:public BaseNode
	{
	public:
		int timer;
		int counter;
		int currentFrame;
		Sprite *point ;

		PointTimer();
		~PointTimer();
		CREATE_FUNC(PointTimer);

        void mouseDownHandler(cocos2d::Event *event);
            void scheduleUpdate(float dt);
		bool init();
	private:

	};
		  
}
#endif
 