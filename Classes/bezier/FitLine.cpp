#include "FitLine.h"
namespace bezier{
	const string FitLine::CUBIC = "cubic";
	const string FitLine::QUADRATIC = "quadratic";

	FitLine::FitLine(Common::Array<cocos2d::Point>& param1, double param2, string param3)
	{
		this->_fitCoeff = param2;
		this->_fitMode = param3;
		this->_srcPoints = param1;
		this->calculateFitArray();
		this->path = new Path(this->_fitPoints);
		//return;
	}// end function

	void FitLine::drawFitLine()// (param1:Graphics) : void
	{ 
		cocos2d::Point _loc_1;
		cocos2d::Point _loc_2;
		cocos2d::Point _loc_3;
		//param1.moveTo(Point(this->_fitPoints[0]).x, Point(this->_fitPoints[0]).y);
		int _loc_4 = 1;
		_loc_1 = this->_fitPoints[0];
		while (_loc_4 < (this->_fitPoints.size() - 1))
		{
			_loc_2 = this->_fitPoints[_loc_4];
			_loc_3 = this->_fitPoints[(_loc_4 + 1)];
//			if (this->_fitMode != CUBIC)
//				DrawPrimitives::drawQuadBezier(_loc_1, _loc_2, _loc_3, 10);
//			else
//				DrawPrimitives::drawCubicBezier(_loc_1, _loc_2, _loc_2, _loc_3, 10);
			_loc_1 = _loc_3;
			//参数依次为起点、控制点、终点、段数  
			//DrawPrimitives::drawQuadBezier(VisibleRect::leftTop(), VisibleRect::center(), 
			//          VisibleRect::rightTop(), 50);
			//参数依次为起点、控制点1、控制点2、终点、段数  
			//DrawPrimitives::drawCubicBezier(VisibleRect::center(), Vec2(VisibleRect::center().x + 30,
			//          VisibleRect::center().y + 50), Vec2(VisibleRect::center().x + 60, 
			//              VisibleRect::center().y - 50), VisibleRect::right(), 100);

			//param1.curveTo(_loc_2.x, _loc_2.y, _loc_3.x, _loc_3.y);
			_loc_4 = _loc_4 + 2;
		}
		return;
	}// end function

	void FitLine::calculateFitArray()
	{
		int _loc_1 = 0;
		double _loc_2  = 0;
		double _loc_3 = 0;
		cocos2d::Point * _loc_4 = NULL;
		Common::Array<cocos2d::Point> _loc_5 ;
		Common::Array<cocos2d::Point>   _loc_6  ;
		this->_fitPoints.clear();
		this->_fitPoints [0]= this->_srcPoints[0] ;
		int srcLen = this->_srcPoints.size();
		if (srcLen< 2)
		{
			this->_fitPoints.clear();
			return;
		}
		if (srcLen == 2)
		{
			this->_fitPoints[1] = midLine(this->_srcPoints[0], this->_srcPoints[1]);
			this->_fitPoints[2] = this->_srcPoints[1];
			return;
		}
		if (_fitMode == QUADRATIC){
			//如果 _fitCoeff=1，则返回 pt1；如果 f=0，则返回 pt2。
			//_loc_4 = Point.interpolate(new cocos2d::Point((3 * this->_srcPoints[1].x - this->_srcPoints[2].x) / 2, (3 * this->_srcPoints[1].y - this->_srcPoints[2].y) / 2),
			//	new cocos2d::Point((this->_srcPoints[0].x + this->_srcPoints[1].x) / 2, (this->_srcPoints[0].y + this->_srcPoints[1].y) / 2), this->_fitCoeff);
			float ins1x = (3 * this->_srcPoints[1].x - this->_srcPoints[2].x) / 2;
			float ins1y=(3 * this->_srcPoints[1].y - this->_srcPoints[2].y) / 2;
			float ins2x = (this->_srcPoints[0].x + this->_srcPoints[1].x) / 2;
			float ins2y = (this->_srcPoints[0].y + this->_srcPoints[1].y) / 2; 
			cocos2d::Point _loc_4 = cocos2d::Point(ins1x*this->_fitCoeff + ins2x*(1 - this->_fitCoeff), ins1y*this->_fitCoeff + ins2y*(1 - this->_fitCoeff));
			_loc_1 = 1;
			while (_loc_1 < (srcLen - 1))
			{
				this->_fitPoints.push(_loc_4);
				this->_fitPoints.push(this->_srcPoints[_loc_1]); 
				_loc_3 = this->_fitCoeff * this->_srcPoints[_loc_1].distance( this->_srcPoints[(_loc_1 + 1)]);//_loc_3 = this->_fitCoeff * cocos2d::Point::distance(this->_srcPoints[_loc_1], this->_srcPoints[(_loc_1 + 1)]);
				_loc_2 = std::atan2(this->_srcPoints[_loc_1].y - _loc_4.y, this->_srcPoints[_loc_1].x - _loc_4.x);
				_loc_4 =   cocos2d::Point(this->_srcPoints[_loc_1].x + _loc_3 * std::cos(_loc_2), this->_srcPoints[_loc_1].y + _loc_3 * std::sin(_loc_2));
				_loc_1++;
			}
			this->_fitPoints.push(_loc_4);
			this->_fitPoints.push(this->_srcPoints[_loc_1]);
		}
		else{
			_loc_5[0] =  this->_srcPoints[0] ; 
			_loc_1 = 1;
			while (_loc_1 < (srcLen - 1))
			{ 
				_loc_2 = std::atan2(this->_srcPoints[(_loc_1 - 1)].y - this->_srcPoints[(_loc_1 + 1)].y, this->_srcPoints[(_loc_1 - 1)].x - this->_srcPoints[(_loc_1 + 1)].x);
				_loc_3 = this->_fitCoeff *this->_srcPoints[(_loc_1 - 1)].distance(this->_srcPoints[_loc_1]);//  Point.distance(this->_srcPoints[(_loc_1 - 1)], this->_srcPoints[_loc_1]);
				_loc_6[_loc_1] =   cocos2d::Point(this->_srcPoints[_loc_1].x + _loc_3 * std::cos(_loc_2), this->_srcPoints[_loc_1].y + _loc_3 * std::sin(_loc_2));
				_loc_3 = this->_fitCoeff * this->_srcPoints[(_loc_1 + 1)].distance(this->_srcPoints[_loc_1]);// Point.distance(this->_srcPoints[(_loc_1 + 1)], this->_srcPoints[_loc_1]);
				//_loc_3 = this->_fitCoeff * this->_srcPoints[(_loc_1 + 1)].distance(this->_srcPoints[_loc_1]);// cocos2d::Point.distance(this->_srcPoints[(_loc_1 + 1)], this->_srcPoints[_loc_1]);
				_loc_2 = _loc_2 + std::PI;
				_loc_5[_loc_1] =   cocos2d::Point(this->_srcPoints[_loc_1].x + _loc_3 * std::cos(_loc_2), this->_srcPoints[_loc_1].y + _loc_3 * std::sin(_loc_2));
				_loc_1++;
			}
			_loc_6.push(this->_srcPoints[(this->_srcPoints.size() - 1)]);
			_loc_1 = 0;
			while (_loc_1 < (srcLen - 1))
			{
				addBezier(this->_fitPoints, this->_srcPoints[_loc_1], _loc_5[_loc_1], _loc_6[(_loc_1 + 1)], this->_srcPoints[(_loc_1 + 1)]);
				_loc_1++;
			}
		} 
	}// end function

	cocos2d::Point FitLine::intersect2Lines(cocos2d::Point param1, cocos2d::Point  param2, cocos2d::Point param3, cocos2d::Point  param4)
	{
		double _loc_5 = param1.x;
		double _loc_6 = param1.y;
		double _loc_7 = param4.x;
		double _loc_8 = param4.y;
		double _loc_9 = param2.x - _loc_5;
		double _loc_10 = param3.x - _loc_7;
		if (!(std::abs(_loc_9)>1e-006f || std::abs(_loc_10)>1e-006f))
		{
			return cocos2d::Point(-1, -1);
		}
		float _loc_11 = (param2.y - _loc_6) / _loc_9;
		float _loc_12 = (param3.y - _loc_8) / _loc_10;
		if(std::abs(_loc_9)<1e-006f)// (!_loc_9)
		{
			return   cocos2d::Point(_loc_5, _loc_12 * (_loc_5 - _loc_7) + _loc_8);
		}
		if(std::abs(_loc_10)<1e-006f)//if (!_loc_10)
		{
			return   cocos2d::Point(_loc_7, _loc_11 * (_loc_7 - _loc_5) + _loc_6);
		}
		float _loc_13 = ((-_loc_12) * _loc_7 + _loc_8 + _loc_11 * _loc_5 - _loc_6) / (_loc_11 - _loc_12);
		float _loc_14 = _loc_11 * (_loc_13 - _loc_5) + _loc_6;
		return  cocos2d::Point(_loc_13, _loc_14);
	}// end function

	Common::Array<cocos2d::Point> FitLine::bezierSplit(cocos2d::Point param1, cocos2d::Point param2, cocos2d::Point param3, cocos2d::Point param4)
	{
		cocos2d::Point _loc_5 = midLine(param1, param2);
		cocos2d::Point _loc_6 = midLine(param2, param3);
		cocos2d::Point _loc_7 = midLine(param3, param4);
		cocos2d::Point _loc_8 = midLine(_loc_5, _loc_6);
		cocos2d::Point _loc_9 = midLine(_loc_6, _loc_7);
		cocos2d::Point _loc_10 = midLine(_loc_8, _loc_9);
		Common::Array<cocos2d::Point> pos;
		pos.push_back(param1);
		pos.push_back(_loc_5);
		pos.push_back(_loc_8);
		pos.push_back(_loc_10);

		pos.push_back(_loc_10);
		pos.push_back(_loc_9);
		pos.push_back(_loc_7);
		pos.push_back(param4);
		return pos;
		//return{ b0:{a:param1, b : _loc_5, c : _loc_8, d : _loc_10}, b1 : {a:_loc_10, b : _loc_9, c : _loc_7, d : param4} };
	}// end function

	  void FitLine::addBezier(Common::Array<cocos2d::Point> &param1, cocos2d::Point  param2, cocos2d::Point  param3, cocos2d::Point param4, cocos2d::Point param5)
	  {
		  float _loc_11  = 0;
		  float _loc_12  = 0;
		  float _loc_9 = 4;
		  cocos2d::Point _loc_10 = intersect2Lines(param2, param3, param4, param5);
		  if (_loc_10.x != -1 && _loc_10.y != -1)
		  {
			  _loc_11 = (param2.x + param5.x + _loc_10.x * 4 - (param3.x + param4.x) * 3) / 8;
			  _loc_12 = (param2.y + param5.y + _loc_10.y * 4 - (param3.y + param4.y) * 3) / 8;
		  }
		  if (_loc_11 * _loc_11 + _loc_12 * _loc_12 > _loc_9)
		  {
			  Common::Array<cocos2d::Point> tmpPos = bezierSplit(param2, param3, param4, param5);
 
			  addBezier(param1, param2, tmpPos[1], tmpPos[2], tmpPos[3]);
			  addBezier(param1, tmpPos[4], tmpPos[5], tmpPos[6], param5);
		  }
		  else if (_loc_10.x != -1 && _loc_10.y != -1)
		  {
			  param1.push(_loc_10);
			  param1.push(param5);
		  }
		  return;
	  }// end function
}