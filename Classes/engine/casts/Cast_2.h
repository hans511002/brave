#ifndef ENGINE_CASTS_CAST2_H
#define ENGINE_CASTS_CAST2_H
#include "BaseHeaders.h"
#include "Cast.h"

namespace engine{

	namespace    casts
	{
		class Cast_2 :public Cast
		{
		public:

			Cast_2()
			{
				init();
			}// end function

			virtual bool init();

			virtual void update(float dt = 0);

			virtual void mouseMoveHandler(cocos2d::EventMouse *param1);

			virtual void mouseDownHandler(cocos2d::EventMouse *event);

			virtual void mouseUpHandler(cocos2d::EventMouse *event);

			virtual void addIceman();

		};
	}
}
#endif
