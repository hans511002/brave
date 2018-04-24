#ifndef ENGINE_CASTS_CAST3_H
#define ENGINE_CASTS_CAST3_H
#include "BaseHeaders.h"
#include "Cast.h"


namespace engine{
    class World;
    namespace    casts
    {
        struct MoveAir_mc :public MovieClip
        {

        };
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

             void update();

             void mouseMoveHandler(cocos2d::Event *param1);

             void mouseDownHandler(cocos2d::Event *event);

             void mouseUpHandler(cocos2d::Event *event);

             void directionManage();

             void  addAir();

        };
    }
}
#endif
