#include "Cast_2.h"
#include "engine/World.h"
#include "engine/WorldInterface.h"

namespace engine {
	namespace    casts
	{
		bool Cast_2::init()
		{
			container = new MovieClip("cast/", "MoveIceman_mc", "MoveIceman_mc");
			//container->gotoAndStop(2);
			this->addChild(container, 3);
			Cast::init();
			this->autorelease();
			return true;
		}// end function

		void Cast_2::update(float dt)
		{
			Cast::update();
			return;
		}// end function

		void Cast_2::mouseMoveHandler(cocos2d::EventMouse *e)
		{
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if (!event)
				return;
			string targetName = event->target->getName();
			if (targetName == "castIcemanCase")
			{
				if (container->currentFrame == 1)
				{
					container->gotoAndStop(2);
				}
				if (world->worldInterface->container->butCastIceman->currentFrame != 6)
				{
					world->worldInterface->container->butCastIceman->gotoAndStop(6);
				}
			}
			else
			{
				if (world->worldInterface->container->butCastIceman->currentFrame != 5)
				{
					world->worldInterface->container->butCastIceman->gotoAndStop(5);
				}
				if (scanWay())
				{
					if (container->currentFrame == 2)
					{
						container->gotoAndStop(1);
					}
				}
				else if (container->currentFrame == 1)
				{
					container->gotoAndStop(2);
				}
			}
			return;
		}// end function

		void Cast_2::mouseDownHandler(cocos2d::EventMouse *e)
		{
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if (!event)
				return;
			bool deled = false;
			if (event)
			{
				string targetName = event->target->getName();
				if (targetName != "castIcemanCase" && scanWay())
				{
					this->setMouseChildren(true);
					this->setMouseEnabled(true);
					//event = new MouseEvent(MouseEvent.MOUSE_DOWN);
					world->worldInterface->castIcemanCounter++;
					world->worldInterface->container->butCastIceman->gotoAndStop(4);
					world->worldInterface->container->butCastIcemanCastIcemanCase->setMouseEnabled(false);
					world->worldInterface->container->butCastIcemanContContMask->setScaleY(0);
					this->addIceman();
					kill();
					deled = true;
				}
				else if (targetName == "castGolemCase" || targetName == "castIcemanCase" || targetName == "castAirCase")
				{
					world->worldInterface->container->butCastIceman->gotoAndStop(1);
					kill();
					deled = true;
				}
			}
			if (!deled)
				container->gotoAndStop(3);
			return;
		}// end function

		void Cast_2::mouseUpHandler(cocos2d::EventMouse *e)
		{
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if (!event)
				return;
			return;
		}// end function

		void Cast_2::addIceman()
		{
			tempObject = cocos2d::Point(world->mouseX, world->mouseY);
			//tempObject1 = null;
			float tempObject2 = 0;
			float tempObject3 = 10000;
			n = 1;
			while (n <= Main::mainClass->readXMLClass.strategies)
			{
				if (n == 1)
				{
					map = &world->map->road1;
				}
				else if (n == 2)
				{
					map = &world->map->road2;
				}
				else if (n == 3)
				{
					map = &world->map->road3;
				}
				i = 1;
				Common::Array<cocos2d::Point> &  map = *this->map;
				while (i < map.size())
				{
					if (map[i].x == map[(i - 1)].x)
					{
						if (map[i].y >= map[(i - 1)].y)
						{
							j = map[(i - 1)].y;
							while (j < map[i].y)
							{
								tempObject2 = tempObject.distance(cocos2d::Point(map[i].x, j));
								if (tempObject2 < 30)
								{
									if (tempObject2 < tempObject3)
									{
										tempObject3 = tempObject2;
									}
									else
									{
										Iceman * tempObject1 = new Iceman(cocos2d::Point(map[i].x, j), n, i);
										world->addChild(tempObject1, 4);
										return;
									}
								}
								j = j + 5;
							}
						}
						else
						{
							j = map[(i - 1)].y;
							while (j >= map[i].y)
							{
								tempObject2 = tempObject.distance(cocos2d::Point(map[i].x, j));
								if (tempObject2 < 30)
								{
									if (tempObject2 < tempObject3)
									{
										tempObject3 = tempObject2;
									}
									else
									{
										Iceman * tempObject1 = new Iceman(cocos2d::Point(map[i].x, j), n, i);
										world->addChild(tempObject1, 4);
										return;
									}
								}
								j = j - 5;
							}
						}
					}
					else if (map[i].y == map[(i - 1)].y)
					{
						if (map[i].x >= map[(i - 1)].x)
						{
							j = map[(i - 1)].x;
							while (j < map[i].x)
							{
								tempObject2 = tempObject.distance(cocos2d::Point(j, map[i].y));
								if (tempObject2 < 30)
								{
									if (tempObject2 < tempObject3)
									{
										tempObject3 = tempObject2;
									}
									else
									{
										Iceman * tempObject1 = new Iceman(cocos2d::Point(j, map[i].y), n, i);
										world->addChild(tempObject1, 4);
										return;
									}
								}
								j = j + 5;
							}
						}
						else
						{
							j = map[(i - 1)].x;
							while (j >= map[i].x)
							{
								tempObject2 = tempObject.distance(cocos2d::Point(j, map[i].y));
								if (tempObject2 < 30)
								{
									if (tempObject2 < tempObject3)
									{
										tempObject3 = tempObject2;
									}
									else
									{
										Iceman * tempObject1 = new Iceman(cocos2d::Point(j, map[i].y), n, i);
										world->addChild(tempObject1, 4);
										return;
									}
								}
								j = j - 5;
							}
						}
					}
					i++;
				}
				n++;
			}
			return;
		}// end function


	}
}
