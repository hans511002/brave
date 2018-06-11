#ifndef ENGINE_CASTS_CAST3_H
#define ENGINE_CASTS_CAST3_H
#include "BaseHeaders.h"
#include "Cast.h"


namespace engine{
 
    namespace    casts
    { 
        class Cast_3 :public Cast
        {
        public:
            string direction;
            cocos2d::Point this_pt;// :Point;
            

            Cast_3()
            {
				init();
            }// end function

             bool init();

virtual              void update(float dt=0);

             void mouseMoveHandler(cocos2d::EventMouse *param1);

             void mouseDownHandler(cocos2d::EventMouse *event);

             void mouseUpHandler(cocos2d::EventMouse *event);

             void directionManage();

             void  addAir();

        };
    }
}
#endif
