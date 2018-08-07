#include "Cast_3.h"
#include "engine/world.h"
#include "Air.h"
#include "engine/WorldInterface.h"

namespace engine {
	namespace    casts
	{
		bool Cast_3::init()
		{
			container = new MoveAir_mc();//("cast/", "MoveAir_mc","MoveAir_mc");
			//container->gotoAndStop(2);
			this->addChild(container);
			Cast::init();
			this->this_pt = cocos2d::Point(world->mouseX, world->mouseY);
			this->autorelease();
			return true;
		}// end function

		void Cast_3::update(float dt)
		{
			this->directionManage();
			Cast::update();
			return;
		}// end function

		void Cast_3::mouseMoveHandler(cocos2d::EventMouse *e)
		{
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if (!event)
				return;
			string targetName = event->target->getName();
			if (targetName == "castAirCase")
			{
				if (container->currentFrame == 1)
				{
					container->gotoAndStop(2);
				}
				if (world->worldInterface->container->butCastAir->currentFrame != 6)
				{
					world->worldInterface->container->butCastAir->gotoAndStop(6);
				}
			}
			else
			{
				if (world->worldInterface->container->butCastAir->currentFrame != 5)
				{
					world->worldInterface->container->butCastAir->gotoAndStop(5);
				}
				if (scanWay())
				{
					if (container->currentFrame == 2)
					{
						MoveAir_mc * container = ISTYPE(MoveAir_mc, this->container);
						container->gotoAndStop(1);
						container->left->stop();
						container->right->stop();
						container->up->stop();
						container->down->stop();
						container->left->setVisible(false);
						container->right->setVisible(false);
						container->up->setVisible(false);
						container->down->setVisible(false);
					}
				}
				else if (container->currentFrame == 1)
				{
					container->gotoAndStop(2);
				}
			}
			return;
		}// end function

		void  Cast_3::mouseDownHandler(cocos2d::EventMouse *e)
		{
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if (!event)
				return;
			bool deled = false;
			if (event)
			{
				string targetName = event->target->getName();
				if (targetName != "castAirCase" && scanWay())
				{
					this->setMouseChildren(true);
					this->setMouseEnabled(true);
					//event = new MouseEvent(MouseEvent.MOUSE_DOWN);
					world->worldInterface->castAirCounter++;
					world->worldInterface->container->butCastAir->gotoAndStop(4);
					world->worldInterface->container->butCastAirCastAirCase->setMouseEnabled(false);
					world->worldInterface->container->butCastAirContContMask->setScaleY(0);
					this->addAir();
					kill();
					deled = true;
				}
				else if (targetName == "castGolemCase" || targetName == "castIcemanCase" || targetName == "castAirCase")
				{
					world->worldInterface->container->butCastAir->gotoAndStop(1);
					kill();
					deled = true;
				}
			}
			if(!deled)
				container->gotoAndStop(3);
			return;
		}// end function

		void  Cast_3::mouseUpHandler(cocos2d::EventMouse *event)
		{
			return;
		}// end function

		void Cast_3::directionManage()
		{
			MoveAir_mc * container = ISTYPE(MoveAir_mc, this->container);
			if (container->currentFrame == 1)
			{
				if (this->this_pt.x != world->mouseX || this->this_pt.y != world->mouseY)
				{
					this->this_pt = cocos2d::Point(world->mouseX, world->mouseY);
					float tempObject1 = 10000;
					container->left->setVisible(false);
					container->right->setVisible(false);
					container->up->setVisible(false);
					container->down->setVisible(false);
					if (world->nowLevel == 9)
					{
						if (tempObject.x >= 370 && tempObject.x <= 470 && tempObject.y >= 240 && tempObject.y <= 390)
						{
							this->direction = "left";
							container->left->setVisible(true);
						}
					}
					if (!container->left->isVisible())
					{
						n = 1;
						while (n <= Main::mainClass->readXMLClass.strategies)
						{
							if (n == 1)
							{
								map = &world->map.road1;
							}
							else if (n == 2)
							{
								map = &world->map.road2;
							}
							else if (n == 3)
							{
								map = &world->map.road3;
							}
							Common::Array<cocos2d::Point> &map = *this->map;
							i = map.size() - 1;
							float tempObject2 = 0;
							while (i > 0)
							{
								if (map[i].x == map[(i - 1)].x)
								{
									if (map[i].y >= map[(i - 1)].y)
									{
										j = map[(i - 1)].y;
										while (j < map[i].y)
										{
											tempObject2 = this->this_pt.distance(cocos2d::Point(map[i].x, j));
											if (tempObject2 < 30)
											{
												if (tempObject2 < tempObject1)
												{
													tempObject1 = tempObject2;
													tempObject3 = cocos2d::Point(map[i].x, j);
													this->direction = "up";
													container->up->setVisible(true);
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
											float tempObject2 = this->this_pt.distance(cocos2d::Point(map[i].x, j));
											if (tempObject2 < 30)
											{
												if (tempObject2 < tempObject1)
												{
													tempObject1 = tempObject2;
													tempObject3 = cocos2d::Point(map[i].x, j);
													this->direction = "down";
													container->down->setVisible(true);
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
											tempObject2 = this->this_pt.distance(cocos2d::Point(j, map[i].y));
											if (tempObject2 < 30)
											{
												if (tempObject2 < tempObject1)
												{
													tempObject1 = tempObject2;
													tempObject3 = cocos2d::Point(j, map[i].y);
													this->direction = "right";
													container->right->setVisible(true);
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
											float tempObject2 = this->this_pt.distance(cocos2d::Point(j, map[i].y));
											if (tempObject2 < 30)
											{
												if (tempObject2 < tempObject1)
												{
													tempObject1 = tempObject2;
													tempObject3 = cocos2d::Point(j, map[i].y);
													this->direction = "left";
													container->left->setVisible(true);
												}
											}
											j = j - 5;
										}
									}
								}
								if (tempObject1 < tempObject2)
								{
									break;
								}
								i--;
							}
							if (tempObject1 < tempObject2)
							{
								break;
							}
							n++;
						}
					}
				}
				if (container->left->isVisible())
				{
					if (container->left->currentFrame < container->left->totalFrames)
					{
						container->left->tryPlay();
						//container->left->gotoAndStop((container->left->currentFrame + 1));
					}
					else
					{
						container->left->gotoAndStop(1);
					}
				}
				else if (container->right->isVisible())
				{
					if (container->right->currentFrame < container->right->totalFrames)
					{
						container->right->tryPlay();
						//container->right->gotoAndStop((container->right->currentFrame + 1));
					}
					else
					{
						container->right->gotoAndStop(1);
					}
				}
				else if (container->up->isVisible())
				{
					if (container->up->currentFrame < container->up->totalFrames)
					{
						container->up->tryPlay();
						//container->up->gotoAndStop((container->up->currentFrame + 1));
					}
					else
					{
						container->up->gotoAndStop(1);
					}
				}
				else if (container->down->isVisible())
				{
					if (container->down->currentFrame < container->down->totalFrames)
					{
						container->down->tryPlay();
						//container->down->gotoAndStop((container->down->currentFrame + 1));
					}
					else
					{
						container->down->gotoAndStop(1);
					}
				}
			}
			return;
		}// end function

		void  Cast_3::addAir()
		{
			this->directionManage();
			Air * air = NULL;
			if (tempObject3.x >= 0)
			{
				air = new Air(tempObject3, this->direction);
			}
			else
			{
				air = new Air(this->this_pt, this->direction);
			}
			world->addChild(air, 4);
			tempObject = air->getPosition();
			return;
		}// end function

	}
}
