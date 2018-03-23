#ifndef BEZIER_PATH_H
#define BEZIER_PATH_H
#include "BaseHeaders.h"
#include "PathSegment.h"

namespace bezier
{

	class Path
	{
		Common::Array<PathSegment *>   _segmentsArr;
		//private var points : Array;
		Common::Array<cocos2d::Point>  &points;
	public:
		double length;// : Number = 0;
		Path(Common::Array<cocos2d::Point>  &param1);
		~Path();

		PathPoint getPathPoint(double param1);

		void   update();

		void setPoints(Common::Array<cocos2d::Point>  &param1)
		{
			this->points = param1;
			this->update();
		}// end function

	};
}
#endif

