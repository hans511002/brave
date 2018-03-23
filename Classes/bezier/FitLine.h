#ifndef BEZIER_FITLINE_H
#define BEZIER_FITLINE_H
#include "BaseHeaders.h"
#include "PathSegment.h"
#include "Path.h"
#include "Pointer.h"

namespace bezier
{

	class FitLine
	{
		Common::Array<cocos2d::Point> _fitPoints; //private var _fitPoints:Array;
		Common::Array<cocos2d::Point>_srcPoints; //private var _srcPoints:Array;
	public:
		Path * path;//private var _path : Path;
		string _fitMode;// : String = "cubic";

		float _fitCoeff;// private var _fitCoeff : Number = 0.38;
		const  static  string CUBIC;
		const  static  string QUADRATIC;

		FitLine(Common::Array<cocos2d::Point>& param1, double param2 = 0.38, string param3 = "cubic");
        ~FitLine(){
			if (path){
				delete path;
            }
			path = NULL;
        }
		void drawFitLine();

		void update()
		{
			this->calculateFitArray();
			this->path->setPoints( this->_fitPoints);
			//return;
		}// end function

		void calculateFitArray();

		float getFitCoeff()
		{
			return this->_fitCoeff;
		}// end function

		void setFitCoeff(float param1)
		{
			if (param1 < 0.05)
			{
				param1 = 0.05f;
			}
			if (param1 > 0.95)
			{
				param1 = 0.95f;
			}
			this->_fitCoeff = param1;
			this->update();
			return;
		}// end function

		string getFitMode()
		{
			return this->_fitMode;
		}// end function

		void setFitMode(string param1)
		{
			if (this->_fitMode == param1)
			{
				return;
			}
			if (param1 != QUADRATIC && param1 != CUBIC)
			{
				return;
				//throw Error("unsupported mode: " + param1);
			}
			this->_fitMode = param1;
			this->update();
			return;
		}// end function

		Common::Array<cocos2d::Point>& getFitPoints()
		{
			return this->_fitPoints;
		}// end function

		void setSrcPoints(Common::Array<cocos2d::Point>& param1) 
		{
		    this->_srcPoints = param1;
		    this->update(); 
		}// end function

		Path& getPath()
		{
			return *this->path;
		}// end function

		static cocos2d::Point intersect2Lines(cocos2d::Point param1, cocos2d::Point  param2, cocos2d::Point param3, cocos2d::Point  param4);

		static cocos2d::Point midLine(cocos2d::Point param1, cocos2d::Point param2)
		{
			return cocos2d::Point((param1.x + param2.x) / 2, (param1.y + param2.y) / 2);
		}// end function

		static Common::Array<cocos2d::Point> bezierSplit(cocos2d::Point param1, cocos2d::Point param2, cocos2d::Point param3, cocos2d::Point param4);
			

		static void addBezier(Common::Array<cocos2d::Point> &param1, cocos2d::Point  param2, cocos2d::Point  param3, cocos2d::Point param4, cocos2d::Point param5);

	};
}
#endif
