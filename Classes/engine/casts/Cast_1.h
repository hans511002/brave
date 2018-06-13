#ifndef ENGINE_CASTS_CAST1_H
#define ENGINE_CASTS_CAST1_H
#include "BaseHeaders.h"
#include "Cast.h"

namespace engine{
 
	namespace    casts
	{
		class Golem;

		class Cast_1 :public Cast
		{
		public:
			Cast_1()
			{
				setNodeType("Cast_1");
				init();
			}// end function

			bool init();

			virtual void update(float dt = 0);

			virtual  void   mouseMoveHandler(cocos2d::EventMouse * param1);

			virtual  void   mouseDownHandler(cocos2d::EventMouse *event);

			virtual void   mouseUpHandler(cocos2d::EventMouse  event);

			void addGolem();

		};
	}
}
#endif
