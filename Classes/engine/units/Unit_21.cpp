
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h" 

namespace engine
{
	namespace units
	{ 

		bool Unit_21::init()
		{
			typeUnit = 21;
			this->newEnemyCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
			container = new Unit_mc(this, "Unit21_mc", typeUnit); //new Unit21_mc(); 
			container->setScale(0.88f);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_21::animationHandler()
		{
			if(!icemanFlag)
			{
				if(direction != "up")
				{
					if(container->cont->currentFrame != 1)
					{
						container->cont->gotoAndStop(1);
					}
				}
				else if(container->cont->currentFrame != 2)
				{
					container->cont->gotoAndStop(2);
				}
				if(!airFlag && !airShockFlag || container->currentFrame != 1)
				{
					if(container->currentFrame < container->totalFrames)
					{
						container->gotoAndStop((container->currentFrame + 1));
					}
					else
					{
						container->gotoAndStop(1);
					}
				}
			}
			Unit::animationHandler();
			return;
		}// end function

		void Unit_21::kill()
		{
			if(!dead && health <= 0)
			{
				if(container->cont->currentFrame == 1)
				{
					MovieClip * tempObject = new MovieClip(world, "unit/", "Unit21_frontDeath_mc", "Unit21_frontDeath_mc");//Indexes(new Unit20_frontDeath_mc(), 1);
					cocos2d::Point pos = container->getPosition();
					pos = CONVERT_TO_WORLD_POS(container->localToGlobal(pos));
					tempObject->setPosition(pos);
					//tempObject = new Indexes(new Unit21_frontDeath_mc(), 1);
				}
				else if(container->cont->currentFrame == 2)
				{
					MovieClip * tempObject = new MovieClip(world, "unit/", "Unit21_backDeath_mc", "Unit21_backDeath_mc");//Indexes(new Unit20_frontDeath_mc(), 1);
					cocos2d::Point pos = container->getPosition();
					pos = CONVERT_TO_WORLD_POS(container->localToGlobal(pos));
					tempObject->setPosition(pos);
					//tempObject = new Indexes(new Unit21_backDeath_mc(), 1);
				}
				AudioUtil::playSound("Snd_unit_orderDeath.mp3");
				//path1 = container->localToGlobal(new Point(container->x, container->y));
				//tempObject.x = path1.x;
				//tempObject.y = path1.y;
				float path1 = 0;
				float path2 = 0;
				float path3 = 0;
				if(way == 1)
				{
					path1 = path;
				}
				else if(way == 2)
				{
					path2 = path;
				}
				else if(way == 2)
				{
					path3 = path;
				}
				if(path1 == 0)
				{
					float tempObject = 10000;
					float tempObject4 = world->bezierClass->getPathLength(road, 1);
					i = 0;
					while(i < tempObject4)
					{
						cocos2d::Point tempObject5 = world->bezierClass->getPathPoint(i, road, 1);
						float tempObject6 = tempObject5.distance(this_pt);
						//tempObject6 = Point.distance(new Point(tempObject5.x, tempObject5.y), this_pt);
						if(tempObject6 < tempObject)
						{
							tempObject = tempObject6;
						}
						else if(tempObject6 < 50)
						{
							break;
						}
						i = i + 5;
					}
					path1 = i;
				}
				if(path2 == 0)
				{
					float tempObject = 10000;
					float tempObject4 = world->bezierClass->getPathLength(road, 2);
					i = 0;
					while(i < tempObject4)
					{
						cocos2d::Point tempObject5 = world->bezierClass->getPathPoint(i, road, 2);
						float tempObject6 = tempObject5.distance(this_pt);
						//tempObject6 = Point.distance(new Point(tempObject5.x, tempObject5.y), this_pt);
						if(tempObject6 < tempObject)
						{
							tempObject = tempObject6;
						}
						else if(tempObject6 < 50)
						{
							break;
						}
						i = i + 5;
					}
					path2 = i;
				}
				if(path3 == 0)
				{
					float tempObject = 10000;
					float tempObject4 = world->bezierClass->getPathLength(road, 3);
					i = 0;
					while(i < tempObject4)
					{
						cocos2d::Point tempObject5 = world->bezierClass->getPathPoint(i, road, 3);
						float tempObject6 = tempObject5.distance(this_pt);
						//tempObject6 = Point.distance(new Point(tempObject5.x, tempObject5.y), this_pt);
						if(tempObject6 < tempObject)
						{
							tempObject = tempObject6;
						}
						else if(tempObject6 < 50)
						{
							break;
						}
						i = i + 5;
					}
					path3 = i;
				}
				j = 0;
				i = 1;
				while(i <= this->newEnemyCounter)
				{
					Unit * tempObject = NULL;
					j++;
					if(j == 1)
					{
						path1 = path1 + 15;
						tempObject = world->addUnit(32, road, 1, path1);
						tempObject->speedKSave = tempObject->speedKSave - 0.1;
					}
					else if(j == 2)
					{
						path2 = path2 + 15;
						tempObject = world->addUnit(32, road, 2, path2);
						tempObject->speedKSave = tempObject->speedKSave - 0.14;
					}
					else if(j == 3)
					{
						path3 = path3 + 15;
						tempObject = world->addUnit(32, road, 3, path3);
						tempObject->speedKSave = tempObject->speedKSave - 0.17;
					}
					else if(j == 4)
					{
						j = 0;
						path3 = path3 + 15;
						tempObject = world->addUnit(32, road, 1, path1);
						tempObject->speedKSave = tempObject->speedKSave - 0.2;
					}
					tempObject->speedK = tempObject->speedKSave;
					tempObject->direction = direction;
					tempObject->readyDamage = false;
					tempObject->moveFlag = false;
					tempObject->setPosition(this->getPosition());
					//tempObject->x = this->x;
					//tempObject->y = this->y;
					tempObject->setPosition(0);// alpha = 0;
					i++;
				}
			}
			Unit::kill();
			return;
		}// end function

	}
}
