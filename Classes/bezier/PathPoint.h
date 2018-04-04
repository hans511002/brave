#ifndef BEZIER_PATHPOINT_H
#define BEZIER_PATHPOINT_H
#include "BaseHeaders.h"

namespace bezier
{
    class PathPoint : public cocos2d::Point
    {
	public:
		//float x;// : Number;
		//float   y;// : Number;
		float rotation;// :Number;

		PathPoint(float param1, float param2, float param3 = 0)
        {
            this->rotation = param3;
            this->x = param1;
            this->y = param2; 
        }// end function
		inline  operator Vec2()
		{
			return Vec2(x,y);
		};
	};
}
#endif
