#include "Bezier.h"
#include "MainClass.h"
#include "engine/World.h"

namespace bezier
{
    Bezier::~Bezier()
    {
    };
	bool Bezier::init()
	{
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
		this->scanRoad = Main::mainClass->readXMLClass.bezierRoadXML;
		this->scanWay = Main::mainClass->readXMLClass.bezierWayXML;
		if (!Main::mainClass->readXMLClass.bezierBuildXML)
		{
			if (this->scanRoad == 0 && this->scanWay == 0)
			{
				//this->setVisible(false);
			}
		}
		int playLevel=Main::mainClass->saveBoxClass->playLevel;
		if (playLevel == 1)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level1_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level1_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level1_path3;
		}
		else if (playLevel == 2)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level2_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level2_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level2_path3;
		}
		else if (playLevel == 3)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level3_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level3_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level3_path3;
			this->path11 = &Main::mainClass->saveBoxClass->bezierBoxClass.level3_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level3_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level3_path13;
		}
		else if (playLevel == 4)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level4_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level4_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level4_path3;
			this->path11 =& Main::mainClass->saveBoxClass->bezierBoxClass.level4_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level4_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level4_path13;
		}
		else if (playLevel == 5)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level5_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level5_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level5_path3;
			this->path11 =& Main::mainClass->saveBoxClass->bezierBoxClass.level5_path11;
			this->path12 =& Main::mainClass->saveBoxClass->bezierBoxClass.level5_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level5_path13;
		}
		else if (playLevel == 6)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level6_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level6_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level6_path3;
			this->path11 =& Main::mainClass->saveBoxClass->bezierBoxClass.level6_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level6_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level6_path13;
		}
		else if (playLevel == 7)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level7_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level7_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level7_path3;
		}
		else if (playLevel == 8)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level8_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level8_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level8_path3;
			this->path11 = &Main::mainClass->saveBoxClass->bezierBoxClass.level8_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level8_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level8_path13;
		}
		else if (playLevel == 9)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level9_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level9_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level9_path3;
			this->path11 = &Main::mainClass->saveBoxClass->bezierBoxClass.level9_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level9_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level9_path13;
		}
		else if (playLevel == 10)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level10_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level10_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level10_path3;
			this->path11 = &Main::mainClass->saveBoxClass->bezierBoxClass.level10_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level10_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level10_path13;
		}
		else if (playLevel == 11)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level11_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level11_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level11_path3;
			this->path11 = &Main::mainClass->saveBoxClass->bezierBoxClass.level11_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level11_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level11_path13;
		}
		else if (playLevel == 12)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level12_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level12_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level12_path3;
			this->path11 = &Main::mainClass->saveBoxClass->bezierBoxClass.level12_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level12_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level12_path13;
		}
		else if (playLevel == 13)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level13_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level13_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level13_path3;
			this->path11 = &Main::mainClass->saveBoxClass->bezierBoxClass.level13_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level13_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level13_path13;
		}
		else if (playLevel == 14)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level14_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level14_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level14_path3;
			this->path11 = &Main::mainClass->saveBoxClass->bezierBoxClass.level14_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level14_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level14_path13;
		}
		else if (playLevel == 15)
		{
			this->path1 = &Main::mainClass->saveBoxClass->bezierBoxClass.level15_path1;
			this->path2 = &Main::mainClass->saveBoxClass->bezierBoxClass.level15_path2;
			this->path3 = &Main::mainClass->saveBoxClass->bezierBoxClass.level15_path3;
			this->path11 = &Main::mainClass->saveBoxClass->bezierBoxClass.level15_path11;
			this->path12 = &Main::mainClass->saveBoxClass->bezierBoxClass.level15_path12;
			this->path13 = &Main::mainClass->saveBoxClass->bezierBoxClass.level15_path13;
			this->path21 = &Main::mainClass->saveBoxClass->bezierBoxClass.level15_path21;
			this->path22 = &Main::mainClass->saveBoxClass->bezierBoxClass.level15_path22;
			this->path23 = &Main::mainClass->saveBoxClass->bezierBoxClass.level15_path23;
		}
		if (this->path21)
		{
			Main::mainClass->worldClass->numRoads = 3;
		}
		else if (this->path11)
		{
			Main::mainClass->worldClass->numRoads = 2;
		}
		else if (this->path1)
		{
			Main::mainClass->worldClass->numRoads = 1;
		}
		if (Main::mainClass->readXMLClass.bezierRoadXML == 1)
		{
			this->path11 = NULL;
			this->path12 = NULL;
			this->path13 = NULL;
			this->path21 = NULL;
			this->path22 = NULL;
			this->path23 = NULL;
			if (Main::mainClass->readXMLClass.bezierWayXML == 1)
			{
				this->path2 = NULL;
				this->path3 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 2)
			{
				this->path1 = NULL;
				this->path3 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 3)
			{
				this->path1 = NULL;
				this->path2 = NULL;
			}
		}
		else if (Main::mainClass->readXMLClass.bezierRoadXML == 2)
		{
			this->path1 = NULL;
			this->path2 = NULL;
			this->path3 = NULL;
			this->path21 = NULL;
			this->path22 = NULL;
			this->path23 = NULL;
			if (Main::mainClass->readXMLClass.bezierWayXML == 1)
			{
				this->path12 = NULL;
				this->path13 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 2)
			{
				this->path11 = NULL;
				this->path13 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 3)
			{
				this->path11 = NULL;
				this->path12 = NULL;
			}
		}
		else if (Main::mainClass->readXMLClass.bezierRoadXML == 3)
		{
			this->path1 = NULL;
			this->path2 = NULL;
			this->path3 = NULL;
			this->path11 = NULL;
			this->path12 = NULL;
			this->path13 = NULL;
			if (Main::mainClass->readXMLClass.bezierWayXML == 1)
			{
				this->path22 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 2)
			{
				this->path21 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 3)
			{
				this->path21 = NULL;
				this->path22 = NULL;
			}
		}
		else if (Main::mainClass->readXMLClass.bezierWayXML > 0)
		{
			if (Main::mainClass->readXMLClass.bezierWayXML == 1)
			{
				this->path2 = NULL;
				this->path3 = NULL;
				this->path11 = NULL;
				this->path12 = NULL;
				this->path13 = NULL;
				this->path21 = NULL;
				this->path22 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 2)
			{
				this->path1 = NULL;
				this->path3 = NULL;
				this->path11 = NULL;
				this->path12 = NULL;
				this->path13 = NULL;
				this->path21 = NULL;
				this->path22 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 3)
			{
				this->path1 = NULL;
				this->path2 = NULL;
				this->path11 = NULL;
				this->path12 = NULL;
				this->path13 = NULL;
				this->path21 = NULL;
				this->path22 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 11)
			{
				this->path1 = NULL;
				this->path2 = NULL;
				this->path3 = NULL;
				this->path12 = NULL;
				this->path13 = NULL;
				this->path21 = NULL;
				this->path22 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 12)
			{
				this->path1 = NULL;
				this->path2 = NULL;
				this->path3 = NULL;
				this->path11 = NULL;
				this->path13 = NULL;
				this->path21 = NULL;
				this->path22 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 13)
			{
				this->path1 = NULL;
				this->path2 = NULL;
				this->path3 = NULL;
				this->path11 = NULL;
				this->path12 = NULL;
				this->path21 = NULL;
				this->path22 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 21)
			{
				this->path1 = NULL;
				this->path2 = NULL;
				this->path3 = NULL;
				this->path11 = NULL;
				this->path12 = NULL;
				this->path13 = NULL;
				this->path22 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 22)
			{
				this->path1 = NULL;
				this->path2 = NULL;
				this->path3 = NULL;
				this->path11 = NULL;
				this->path12 = NULL;
				this->path13 = NULL;
				this->path21 = NULL;
				this->path23 = NULL;
			}
			else if (Main::mainClass->readXMLClass.bezierWayXML == 23)
			{
				this->path1 = NULL;
				this->path2 = NULL;
				this->path3 = NULL;
				this->path11 = NULL;
				this->path12 = NULL;
				this->path13 = NULL;
				this->path21 = NULL;
				this->path22 = NULL;
			}
		}
		Common::Array<cocos2d::Point> _loc_4;
		////var _loc_4 : *= [];
		if (this->path1)
		{
			Common::Array<cocos2d::Point> & path=*path1;
			if (!Main::mainClass->readXMLClass.bezierBuildXML)
			{
				_loc_4 = path;
				//int _loc_2 = 0;
				//while (_loc_2 < path.size())//this->path1.length)
				//{
				//	_loc_4.push(path[_loc_2]);
				//	//_loc_4.push(  cocos2d::Point(this->path1[_loc_2][0], this->path1[_loc_2][1]));
				//	_loc_2++;
				//}
			}
			else
			{
				int _loc_2 = 0;
				while (_loc_2 < path.size())//this->path1.length)
				{
					Pointer * _loc_3 = Pointer::create();
					_loc_3->setPosition(path[_loc_2]);
					this->addChild(_loc_3); 
					this->_pointers1.push(_loc_3);
					_loc_4.push(path[_loc_2]);//_loc_4.push(cocos2d::Point(this->_pointers1[_loc_2].x, this->_pointers1[_loc_2].y));
					_loc_2++;
				}
			}
			this->_line1 = new FitLine(_loc_4);
			this->updateLine();
			_loc_4.clear();
		}
		if (this->path2)
		{
			Common::Array<cocos2d::Point> & path = *path2;
			if (!Main::mainClass->readXMLClass.bezierBuildXML)
			{
				_loc_4 = path;
				//_loc_2 = 0;
				//while (_loc_2 < this->path2.length)
				//{
				//	_loc_4.push(new Point(this->path2[_loc_2][0], this->path2[_loc_2][1]));
				//	_loc_2++;
				//}
			}
			else
			{
				int _loc_2 = 0;
				while (_loc_2 < path.size())
				{
					Pointer * _loc_3 = Pointer::create();
					_loc_3->setPosition(path[_loc_2]);
					this->addChild(_loc_3);
					this->_pointers2.push(_loc_3);
					_loc_4.push(path[_loc_2]);// (new Point(this->_pointers2[_loc_2].x, this->_pointers2[_loc_2].y));
					_loc_2++;
				}
			}
			this->_line2 = new FitLine(_loc_4);
			this->updateLine();
			_loc_4.clear();
		}
		if (this->path3)
		{
			Common::Array<cocos2d::Point> & path = *path3;
			if (!Main::mainClass->readXMLClass.bezierBuildXML)
			{
				_loc_4 = path;
				//_loc_2 = 0;
				//while (_loc_2 < this->path3.length)
				//{
				//	_loc_4.push(new Point(this->path3[_loc_2][0], this->path3[_loc_2][1]));
				//	_loc_2++;
				//}
			}
			else
			{
				int _loc_2 = 0;
				while (_loc_2 < path.size())
				{
					Pointer * _loc_3 = Pointer::create();
					_loc_3->setPosition(path[_loc_2]);
					this->addChild(_loc_3);
					this->_pointers3.push(_loc_3);
					_loc_4.push(path[_loc_2]);// (new Point(this->_pointers3[_loc_2].x, this->_pointers3[_loc_2].y));
					_loc_2++;
				}
			}
			this->_line3 = new FitLine(_loc_4);
			this->updateLine();
			_loc_4.clear();
		}
		if (this->path11)
		{
			Common::Array<cocos2d::Point> & path = *path11;
			if (!Main::mainClass->readXMLClass.bezierBuildXML)
			{
				_loc_4 = path;
				//_loc_2 = 0;
				//while (_loc_2 < this->path11.length)
				//{
				//	_loc_4.push(new Point(this->path11[_loc_2][0], this->path11[_loc_2][1]));
				//	_loc_2++;
				//}
			}
			else
			{
				int _loc_2 = 0;
				while (_loc_2 < path.size())
				{
					Pointer * _loc_3 = Pointer::create();
					_loc_3->setPosition(path[_loc_2]);
					this->addChild(_loc_3);
					this->_pointers11.push(_loc_3);
					_loc_4.push(path[_loc_2]);// (new Point(this->_pointers11[_loc_2].x, this->_pointers11[_loc_2].y));
					_loc_2++;
				}
			}
			this->_line11 = new FitLine(_loc_4);
			this->updateLine();
			_loc_4.clear();
		}
		if (this->path12)
		{
			Common::Array<cocos2d::Point> & path = *path12;
			if (!Main::mainClass->readXMLClass.bezierBuildXML)
			{
				_loc_4 = path;
				//int _loc_2 = 0;
				//while (_loc_2 < this->path12.length)
				//{
				//	_loc_4.push(new Point(this->path12[_loc_2][0], this->path12[_loc_2][1]));
				//	_loc_2++;
				//}
			}
			else
			{
				int _loc_2 = 0;
				while (_loc_2 < path.size())
				{
					Pointer * _loc_3 = Pointer::create();
					_loc_3->setPosition(path[_loc_2]);
					this->addChild(_loc_3);
					this->_pointers12.push(_loc_3);
					_loc_4.push(path[_loc_2]);//(new Point(this->_pointers12[_loc_2].x, this->_pointers12[_loc_2].y));
					_loc_2++;
				}
			}
			this->_line12 = new FitLine(_loc_4);
			this->updateLine();
			_loc_4.clear();
		}
		if (this->path13)
		{
			Common::Array<cocos2d::Point> & path = *path13;
			if (!Main::mainClass->readXMLClass.bezierBuildXML)
			{
				_loc_4 = path;
				//int _loc_2 = 0;
				//while (_loc_2 < this->path13.length)
				//{
				//	_loc_4.push(new Point(this->path13[_loc_2][0], this->path13[_loc_2][1]));
				//	_loc_2++;
				//}
			}
			else
			{
				int _loc_2 = 0;
				while (_loc_2 < path.size())
				{
					Pointer * _loc_3 = Pointer::create();
					_loc_3->setPosition(path[_loc_2]);
					this->addChild(_loc_3);
					this->_pointers13.push(_loc_3);
					_loc_4.push(path[_loc_2]);//(new Point(this->_pointers13[_loc_2].x, this->_pointers13[_loc_2].y));
					_loc_2++;
				}
			}
			this->_line13 = new FitLine(_loc_4);
			this->updateLine();
			_loc_4.clear();
		}
		if (this->path21)
		{
		Common::Array<cocos2d::Point> & path = *path11;
			if (!Main::mainClass->readXMLClass.bezierBuildXML)
			{
				_loc_4 = path;
				//int _loc_2 = 0;
				//while (_loc_2 < this->path21.length)
				//{
				//	_loc_4.push(new Point(this->path21[_loc_2][0], this->path21[_loc_2][1]));
				//	_loc_2++;
				//}
			}
			else
			{
				int _loc_2 = 0;
				while (_loc_2 < path.size())
				{
					Pointer * _loc_3 = Pointer::create();
					_loc_3->setPosition(path[_loc_2]);
					this->addChild(_loc_3);
					this->_pointers21.push(_loc_3);
					_loc_4.push(path[_loc_2]);//(new Point(this->_pointers21[_loc_2].x, this->_pointers21[_loc_2].y));
					_loc_2++;
				}
			}
			this->_line21 = new FitLine(_loc_4);
			this->updateLine();
			_loc_4.clear();
		}
		if (this->path22)
		{
		Common::Array<cocos2d::Point> & path = *path11;
			if (!Main::mainClass->readXMLClass.bezierBuildXML)
			{
				_loc_4 = path;
				//int _loc_2 = 0;
				//while (_loc_2 < this->path22.length)
				//{
				//	_loc_4.push(new Point(this->path22[_loc_2][0], this->path22[_loc_2][1]));
				//	_loc_2++;
				//}
			}
			else
			{
				int _loc_2 = 0;
				while (_loc_2 <  path.size())
				{
					Pointer * _loc_3 = Pointer::create();
					_loc_3->setPosition(path[_loc_2]);
					this->addChild(_loc_3);
					this->_pointers22.push(_loc_3);
					_loc_4.push(path[_loc_2]);//(new Point(this->_pointers22[_loc_2].x, this->_pointers22[_loc_2].y));
					_loc_2++;
				}
			}
			this->_line22 = new FitLine(_loc_4);
			this->updateLine();
			_loc_4.clear();
		}
		if (this->path23)
		{
		Common::Array<cocos2d::Point> & path = *path11;
			if (!Main::mainClass->readXMLClass.bezierBuildXML)
			{
				_loc_4 = path;
				//int _loc_2 = 0;
				//while (_loc_2 < this->path23.length)
				//{
				//	_loc_4.push(new Point(this->path23[_loc_2][0], this->path23[_loc_2][1]));
				//	_loc_2++;
				//}
			}
			else
			{
				int _loc_2 = 0;
				while (_loc_2 <  path.size())
				{
					Pointer * _loc_3 = Pointer::create();
					_loc_3->setPosition(path[_loc_2]);
					this->addChild(_loc_3);
					this->_pointers23.push(_loc_3);
					_loc_4.push(path[_loc_2]);//(new Point(this->_pointers23[_loc_2].x, this->_pointers23[_loc_2].y));
					_loc_2++;
				}
			}
			this->_line23 = new FitLine(_loc_4);
			this->updateLine();
			_loc_4.clear();
		}
		return true;
	}// end function

	void Bezier::tracePointsArr()
	{
		//if (this->_pointers1.size() > 0)
		//{
		//	i = 0;
		//	while (i < this->_pointers1.size())
		//	{
		//		var _loc_3 : *= i + 1;
		//		i = _loc_3;
		//	}
		//}
		//if (this->_pointers2.length > 0)
		//{
		//	i = 0;
		//	while (i < this->_pointers2.size())
		//	{ 
		//		var _loc_3 : *= i + 1;
		//		i = _loc_3;
		//	}
		//}
		//if (this->_pointers3.length > 0)
		//{
		//	i = 0;
		//	while (i < this->_pointers3.size())
		//	{ 
		//		var _loc_3 : *= i + 1;
		//		i = _loc_3;
		//	}
		//}
		//if (this->_pointers11.length > 0)
		//{
		//	i = 0;
		//	while (i < this->_pointers11.size())
		//	{ 
		//		var _loc_3 : *= i + 1;
		//		i = _loc_3;
		//	}
		//}
		//if (this->_pointers12.length > 0)
		//{
		//	i = 0;
		//	while (i < this->_pointers12.size())
		//	{ 
		//		var _loc_3 : *= i + 1;
		//		i = _loc_3;
		//	}
		//}
		//if (this->_pointers13.length > 0)
		//{
		//	i = 0;
		//	while (i < this->_pointers13.size())
		//	{ 
		//		var _loc_3 : *= i + 1;
		//		i = _loc_3;
		//	}
		//}
		//if (this->_pointers21.length > 0)
		//{
		//	i = 0;
		//	while (i < this->_pointers21.size())
		//	{ 
		//		var _loc_3 : *= i + 1;
		//		i = _loc_3;
		//	}
		//}
		//if (this->_pointers22.length > 0)
		//{
		//	i = 0;
		//	while (i < this->_pointers22.size())
		//	{ 
		//		var _loc_3 : *= i + 1;
		//		i = _loc_3;
		//	}
		//}
		//if (this->_pointers23.length > 0)
		//{
		//	i = 0;
		//	while (i < this->_pointers23.size())
		//	{ 
		//		var _loc_3 : *= i + 1;
		//		i = _loc_3;
		//	}
		//}
		//return;
	}// end function

	void Bezier::updateLine()
	{
		Common::Array<cocos2d::Point> _loc_1  ;
		int _loc_2 = 0;
		if (Main::mainClass->readXMLClass.bezierBuildXML)
		{ 
			if (this->_pointers1.size() > 0)
			{
				_loc_2 = 0;
				while (_loc_2 < this->_pointers1.size())
				{
				    _loc_1.push(this->_pointers1[_loc_2]->getPosition());
					//_loc_1.push(new Point(this->_pointers1[_loc_2].x, this->_pointers1[_loc_2].y));
					_loc_2++;
				}
				this->_line1->setSrcPoints(_loc_1);
				_loc_1.clear();
			}
			if (this->_pointers2.size() > 0)
			{
				_loc_2 = 0;
				while(_loc_2 < this->_pointers2.size())
				{
                    _loc_1.push(this->_pointers2[_loc_2]->getPosition());
					//_loc_1.push(new Point(this->_pointers2[_loc_2].x, this->_pointers2[_loc_2].y));
					_loc_2++;
				}
				this->_line2->setSrcPoints(_loc_1);
				_loc_1 .clear();
			}
			if(this->_pointers3.size() > 0)
			{
				_loc_2 = 0;
				while(_loc_2 < this->_pointers3.size())
				{
                    _loc_1.push(this->_pointers3[_loc_2]->getPosition());
					//_loc_1.push(new Point(this->_pointers3[_loc_2].x, this->_pointers3[_loc_2].y));
					_loc_2++;
				}
				this->_line3->setSrcPoints(_loc_1);
				_loc_1 .clear();
			}
			if(this->_pointers11.size() > 0)
			{
				_loc_2 = 0;
				while(_loc_2 < this->_pointers11.size())
				{ 
					_loc_1.push(this->_pointers11[_loc_2]->getPosition());
					//_loc_1.push(new Point(this->_pointers11[_loc_2].x, this->_pointers11[_loc_2].y));
					_loc_2++;
				}
				this->_line11->setSrcPoints(_loc_1);
				_loc_1 .clear();
			}
			if(this->_pointers12.size() > 0)
			{
				_loc_2 = 0;
				while(_loc_2 < this->_pointers12.size())
				{ 
					_loc_1.push(this->_pointers12[_loc_2]->getPosition());
					//_loc_1.push(new Point(this->_pointers12[_loc_2].x, this->_pointers12[_loc_2].y));
					_loc_2++;
				}
				this->_line12->setSrcPoints(_loc_1);
				_loc_1.clear();
			}
			if(this->_pointers13.size() > 0)
			{
				_loc_2 = 0;
				while(_loc_2 < this->_pointers13.size())
				{ 
					_loc_1.push(this->_pointers13[_loc_2]->getPosition());
					//_loc_1.push(new Point(this->_pointers13[_loc_2].x, this->_pointers13[_loc_2].y));
					_loc_2++;
				}
				this->_line13->setSrcPoints(_loc_1);
				_loc_1.clear();
			}
			if(this->_pointers21.size() > 0)
			{
				_loc_2 = 0;
				while(_loc_2 < this->_pointers21.size())
				{ 
					_loc_1.push(this->_pointers21[_loc_2]->getPosition());
					//_loc_1.push(new Point(this->_pointers21[_loc_2].x, this->_pointers21[_loc_2].y));
					_loc_2++;
				}
				this->_line21->setSrcPoints(_loc_1);
				_loc_1.clear();
			}
			if(this->_pointers22.size() > 0)
			{
				_loc_2 = 0;
				while(_loc_2 < this->_pointers22.size())
				{ 
					_loc_1.push(this->_pointers22[_loc_2]->getPosition());
					//_loc_1.push(new Point(this->_pointers22[_loc_2].x, this->_pointers22[_loc_2].y));
					_loc_2++;
				}
				this->_line22->setSrcPoints(_loc_1);
				_loc_1.clear();
			}
			if(this->_pointers23.size() > 0)
			{
				_loc_2 = 0;
				while(_loc_2 < this->_pointers23.size())
				{ 
					_loc_1.push(this->_pointers23[_loc_2]->getPosition());
					//_loc_1.push(new Point(this->_pointers23[_loc_2].x, this->_pointers23[_loc_2].y));
					_loc_2++;
				}
				this->_line23->setSrcPoints(_loc_1);
				_loc_1.clear();
			}
		}
		if (this->isVisible())
		{
		//	graphics.clear();
		//	graphics.lineStyle(2, 48944);
			if (this->_line1)
			{
				this->_line1->drawFitLine();
			}
			if (this->_line2)
			{
				this->_line2->drawFitLine();
			}
			if (this->_line3)
			{
				this->_line3->drawFitLine();
			}
			if (this->_line11)
			{
				this->_line11->drawFitLine();
			}
			if (this->_line12)
			{
				this->_line12->drawFitLine();
			}
			if (this->_line13)
			{
				this->_line13->drawFitLine();
			}
			if (this->_line21)
			{
				this->_line21->drawFitLine();
			}
			if (this->_line22)
			{
				this->_line22->drawFitLine();
			}
			if (this->_line23)
			{
				this->_line23->drawFitLine();
			}
		}
		//return;
	}// end function
	PathPoint Bezier::getPathPoint(float param1, int param2, int param3)
	{
		if (param2 == 1)
		{
			if (param3 == 1)
			{
				if (this->_line1)
				{
					return this->_line1->path->getPathPoint(param1);
				}
			}
			else if (param3 == 2)
			{
				if (this->_line2)
				{
					return this->_line2->path->getPathPoint(param1);
				}
			}
			else if (param3 == 3)
			{
				if (this->_line3)
				{
					return this->_line3->path->getPathPoint(param1);
				}
			}
		}
		else if (param2 == 2)
		{
			if (param3 == 1)
			{
				if (this->_line11)
				{
					return this->_line11->path->getPathPoint(param1);
				}
			}
			else if (param3 == 2)
			{
				if (this->_line12)
				{
					return this->_line12->path->getPathPoint(param1);
				}
			}
			else if (param3 == 3)
			{
				if (this->_line13)
				{
					return this->_line13->path->getPathPoint(param1);
				}
			}
		}
		else if (param2 == 3)
		{
			if (param3 == 1)
			{
				if (this->_line21)
				{
					return this->_line21->path->getPathPoint(param1);
				}
			}
			else if (param3 == 2)
			{
				if (this->_line22)
				{
					return this->_line22->path->getPathPoint(param1);
				}
			}
			else if (param3 == 3)
			{
				if (this->_line23)
				{
					return this->_line23->path->getPathPoint(param1);
				}
			}
		}
		else if (param3 == 1)
		{
			if (this->_line1)
			{
				return this->_line1->path->getPathPoint(param1);
			}
		}
		else if (param3 == 2)
		{
			if (this->_line2)
			{
				return this->_line2->path->getPathPoint(param1);
			}
		}
		else if (param3 == 3)
		{
			if (this->_line3)
			{
				return this->_line3->path->getPathPoint(param1);
			}
		}
		else if (param3 == 11)
		{
			if (this->_line11)
			{
				return this->_line11->path->getPathPoint(param1);
			}
		}
		else if (param3 == 12)
		{
			if (this->_line12)
			{
				return this->_line12->path->getPathPoint(param1);
			}
		}
		else if (param3 == 13)
		{
			if (this->_line13)
			{
				return this->_line13->path->getPathPoint(param1);
			}
		}
		else if (param3 == 21)
		{
			if (this->_line21)
			{
				return this->_line21->path->getPathPoint(param1);
			}
		}
		else if (param3 == 22)
		{
			if (this->_line22)
			{
				return this->_line22->path->getPathPoint(param1);
			}
		}
		else if (param3 == 23)
		{
			if (this->_line23)
			{
				return this->_line23->path->getPathPoint(param1);
			}
		}
		return PathPoint(0, 0, 0);
	}// end function

	float Bezier::getPathLength(int param1, int param2)
	{
		if (param1 == 1)
		{
			if (param2 == 1)
			{
				return this->_line1->path->length;
			}
			if (param2 == 2)
			{
				return this->_line2->path->length;
			}
			if (param2 == 3)
			{
				return this->_line3->path->length;
			}
		}
		else if (param1 == 2)
		{
			if (param2 == 1)
			{
				return this->_line11->path->length;
			}
			if (param2 == 2)
			{
				return this->_line12->path->length;
			}
			if (param2 == 3)
			{
				return this->_line13->path->length;
			}
		}
		else if (param1 == 3)
		{
			if (param2 == 1)
			{
				return this->_line21->path->length;
			}
			if (param2 == 2)
			{
				return this->_line22->path->length;
			}
			if (param2 == 3)
			{
				return this->_line23->path->length;
			}
		}
		else
		{
			if (param2 == 1)
			{
				return this->_line1->path->length;
			}
			if (param2 == 2)
			{
				return this->_line2->path->length;
			}
			if (param2 == 3)
			{
				return this->_line3->path->length;
			}
			if (param2 == 11)
			{
				return this->_line11->path->length;
			}
			if (param2 == 12)
			{
				return this->_line12->path->length;
			}
			if (param2 == 13)
			{
				return this->_line13->path->length;
			}
			if (param2 == 21)
			{
				return this->_line21->path->length;
			}
			if (param2 == 22)
			{
				return this->_line22->path->length;
			}
			if (param2 == 23)
			{
				return this->_line23->path->length;
			}
		}
		return 0;
	}// end function

}
