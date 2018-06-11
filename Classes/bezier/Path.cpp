#include "Path.h"

namespace bezier
{
	Path::Path(Common::Array<cocos2d::Point>  &param1) :points(param1)
	{
		CCLOG("================Path points=======================\n");
		for(size_t i = 0; i < points.size(); i++)
		{
			CCLOG("%f,%f   ", points[i].x, points[i].y);
		}
		CCLOG("================end Path points=======================\n");
		this->update();

		return;
	}// end function

	Path::~Path()
	{
		for(int i = 0; i < this->_segmentsArr.size(); i++)
		{
			delete this->_segmentsArr[i];
		}
		this->_segmentsArr.clear();
	};

	PathPoint Path::getPathPoint(double param1)
	{
		if(this->_segmentsArr.size()< 1)
		{
			return PathPoint(0, 0);
		}
		if(param1 > this->length)
		{
			param1 = this->length;
		}
		else if(param1 < 0)
		{
			param1 = 0;
		}
		double _loc_3 = 0;
		int _loc_4 = 0;

		PathSegment * _loc_2 = NULL;
		while(_loc_3 <= param1 && _loc_4 < this->_segmentsArr.size())
		{
			_loc_2 = this->_segmentsArr[_loc_4++];
			_loc_3 = _loc_3 + _loc_2->length;
		}
		return _loc_2->getPoint(param1 - (_loc_3 - _loc_2->length));
	}// end function
	void   Path::update()
	{
		PathSegment *_loc_1 = NULL;
		for(int i = 0; i < this->_segmentsArr.size(); i++)
		{
			delete this->_segmentsArr[i];
		}
		this->_segmentsArr.clear();
		this->length = 0;
		int _loc_2 = 1;
		while(_loc_2 < (this->points.size() - 1))
		{
			_loc_1 = new PathSegment(this->points[(_loc_2 - 1)], this->points[_loc_2], this->points[(_loc_2 + 1)]);
			this->length = this->length + _loc_1->length;
			this->_segmentsArr.push(_loc_1);
			_loc_2 = _loc_2 + 2;

		}

		return;
	}// end function
}
