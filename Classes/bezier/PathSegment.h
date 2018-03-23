#ifndef BEZIER_PATHSEGMENT_H
#define BEZIER_PATHSEGMENT_H
#include "BaseHeaders.h"
#include "PathPoint.h"

namespace bezier
{
	class PathSegment
	{
		cocos2d::Point _p0;
		cocos2d::Point _p1;
		cocos2d::Point _p2;
		double _a;// : Number;
		double _b;// : Number;
		double _c;//: Number;
		double _sqrt_a;// : Number;
		double _sqrt_c;// : Number;
	public:
		double length;// :Number;
		PathSegment(cocos2d::Point param1, cocos2d::Point  param2, cocos2d::Point  param3);
		PathPoint getPoint(double param1);
        
	 

	};
}
#endif
