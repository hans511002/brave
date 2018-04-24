#ifndef ENGINE_CASTS_CAST2_H
#define ENGINE_CASTS_CAST2_H
#include "BaseHeaders.h"
#include "Cast.h"

namespace engine{
    class World;
    namespace    casts
    {
        class MoveIceman_mc:public BaseNode
        {

        };
        class Cast_2 :public Cast
        {
		public:

             Cast_2()
            {
				 init();
            }// end function

             bool init();

            void update();

            void mouseMoveHandler(cocos2d::Event *param1);

            void mouseDownHandler(cocos2d::Event *event);

            void mouseUpHandler(cocos2d::Event *event);

            void addIceman();

        };
    }
}
#endif
