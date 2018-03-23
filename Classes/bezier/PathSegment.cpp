#include "PathSegment.h"
#include "MainClass.h"


namespace bezier
{
	PathSegment::PathSegment(cocos2d::Point param1, cocos2d::Point  param2, cocos2d::Point  param3)
	{
		this->_p0 = param1;
		this->_p1 = param2;
		this->_p2 = param3;
		double _loc_4 = this->_p0.x - 2 * this->_p1.x + this->_p2.x;
		if (std::abs(_loc_4)<1e-006f) //(!(_loc_4))
		{
			_loc_4 = 1e-006f;
		}
		double _loc_5 = this->_p0.y - 2 * this->_p1.y + this->_p2.y;
		if (std::abs(_loc_5)<1e-006f) //(!(_loc_5))
		{
			_loc_5 = 1e-006f;
		}
		double _loc_6 = this->_p0.x - this->_p1.x;
		double _loc_7 = this->_p0.y - this->_p1.y;
		this->_a = 4 * (_loc_4 * _loc_4 + _loc_5 * _loc_5);
		this->_b = -8 * (_loc_4 * _loc_6 + _loc_5 * _loc_7);
		this->_c = 4 * (_loc_6 * _loc_6 + _loc_7 * _loc_7);
		this->_sqrt_c = std::sqrt(this->_c);
		this->_sqrt_a = std::sqrt(this->_a);
		double _loc_8  = std::sqrt(this->_c + this->_b + this->_a);
		double _loc_9 = this->_a * 2;
		this->length = (2 * this->_sqrt_a * (_loc_8 * (this->_b + _loc_9) - this->_sqrt_c * this->_b) +
			(this->_b * this->_b - 4 * this->_a * this->_c) * (std::log(2 * this->_sqrt_c + this->_b / this->_sqrt_a) - std::log(2 * _loc_8 + (this->_b + _loc_9) / this->_sqrt_a))) / (8 * std::pow(this->_a, (double)3 / 2));
		//this._length = (2 * this._sqrt_a * (_loc_8 * (this._b + _loc_9) - this._sqrt_c * this._b) + 
		//(this._b * this._b - 4 * this._a * this._c) * (Math.log(2 * this._sqrt_c + this._b / this._sqrt_a) - Math.log(2 * _loc_8 + (this._b + _loc_9) / this._sqrt_a))) / (8 * Math.pow(this._a, 3 / 2));
		return;
	}// end function

	PathPoint PathSegment::getPoint(double param1)
	{
		double _loc_2  = 0;
		double _loc_3  = 0;
		double _loc_4 = 1;
		double _loc_5 = 1;
		double _loc_6  = this->length;
		double _loc_7 = 100;
		while (std::abs(_loc_6 - param1) > 1e-006 && _loc_7-- > 0)
		{ 
			_loc_2 = std::sqrt(this->_c + _loc_5 * (this->_b + this->_a * _loc_5));
			_loc_3 = this->_a * 2 * _loc_5;
			_loc_6 = (2 * this->_sqrt_a * (_loc_2 * (this->_b + _loc_3) - this->_sqrt_c * this->_b) + (this->_b * this->_b - 4 * this->_a * this->_c) * (std::log(2 * this->_sqrt_c + this->_b / this->_sqrt_a) - std::log(2 * _loc_2 + (this->_b + _loc_3) / this->_sqrt_a))) / (8 * std::pow(this->_a, 3.0f / 2));
			_loc_4 = _loc_4 / 2;
			_loc_5 = _loc_5 + (_loc_6 < param1 ? (_loc_4) : (_loc_6 > param1 ? (-_loc_4) : (0)));
		}
		double _loc_8  = 1 - _loc_5;
		double _loc_9  = (1 - _loc_5) * (1 - _loc_5);
		double _loc_10 = 2 * _loc_5 * _loc_8;
		double _loc_11 =_loc_5 * _loc_5;
		double _loc_12 = this->_p2.x * _loc_11 + this->_p1.x * _loc_10 + this->_p0.x * _loc_9;
		double _loc_13 = this->_p2.y * _loc_11 + this->_p1.y * _loc_10 + this->_p0.y * _loc_9;
		double _loc_14 = std::atan2(this->_p0.y - this->_p1.y + (2 * this->_p1.y - this->_p0.y - this->_p2.y) * _loc_5, this->_p0.x - this->_p1.x + (2 * this->_p1.x - this->_p0.x - this->_p2.x) * _loc_5) / (std::PI / 180);
		//_loc_13 = Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - _loc_13;

		return  PathPoint(_loc_12, _loc_13, _loc_14);
	}// end function
}

