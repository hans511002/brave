#ifndef BEZIER__H
#define BEZIER__H
#include "BaseHeaders.h"
#include "PathSegment.h"
#include "Path.h"
#include "Pointer.h"
#include "FitLine.h"

namespace bezier
{ 
     class Bezier :public BaseNode
    {
	public:
		Common::Array<Pointer*> _pointers1;//private var _pointers1:Array;
		Common::Array<Pointer*>  _pointers2 ;
		Common::Array<Pointer*>  _pointers3 ;
		Common::Array<Pointer*>  _pointers11 ;
		Common::Array<Pointer*>  _pointers12 ;
		Common::Array<Pointer*>  _pointers13 ;
		Common::Array<Pointer*>  _pointers21 ;
		Common::Array<Pointer*>  _pointers22;
		Common::Array<Pointer*>  _pointers23;
		FitLine* _line1;
		FitLine* _line2;
		FitLine* _line3;
		FitLine* _line11;
		FitLine* _line12;
		FitLine* _line13;
		FitLine* _line21;
		FitLine* _line22;
		FitLine* _line23;

		Common::Array<cocos2d::Point> * path1;// var path1 : Array;
		Common::Array<cocos2d::Point> * path2;// //public var path2:Array;
		Common::Array<cocos2d::Point> * path3;////public var path3:Array;
		Common::Array<cocos2d::Point> *  path11;
		Common::Array<cocos2d::Point> *  path12;
		Common::Array<cocos2d::Point> *  path13;
		Common::Array<cocos2d::Point> *  path21;
		Common::Array<cocos2d::Point> *  path22;
		Common::Array<cocos2d::Point> *  path23;
        //public var tracePoints:MovieClip;
		double _pos;// = 0;
		double _dashStart;// = 0;
		int scanRoad;
		int scanWay;

		CREATE_FUNC(Bezier);
		Bezier() :_pos(0),_dashStart(0), _line1(NULL), _line2(NULL), _line3(NULL),
			_line11(NULL), _line12(NULL), _line13(NULL), _line21(NULL), _line22(NULL), _line23(NULL),
			path1(NULL), path2(NULL), path3(NULL), path11(NULL), path12(NULL), path13(NULL), 
			path21(NULL), path22(NULL), path23(NULL)
        {
            //this->_pointers1 = [];
            //this->_pointers2 = [];
            //this->_pointers3 = [];
            //this->_pointers11 = [];
            //this->_pointers12 = [];
            //this->_pointers13 = [];
            //this->_pointers21 = [];
            //this->_pointers22 = [];
            //this->_pointers23 = [];
            //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            //return;
        }// end function
        ~Bezier();
		bool init();

		void tracePointsArr();

		void updateLine();

		PathPoint getPathPoint(float param1, int param2, int param3);

		float getPathLength(int param1, int param2);

        void mainUpdate()  
        {
			if (Pointer::dragFlag)
			{
				this->updateLine();
			}
        }// end function

        //void reInit(event:Event) : void
        //{
        //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //    if (this->tracePoints)
        //    {
        //        this->tracePoints.removeEventListener(MouseEvent.CLICK, this->tracePointsArr);
        //    }
        //    return;
        //}// end function

	 };
}
#endif
