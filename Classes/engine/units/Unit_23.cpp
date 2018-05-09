
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		Unit_23::Unit_23()
		{
			return;
		}// end function

		bool Unit_23::init()
		{
			typeUnit = 23;
			container = new Unit_mc(this, "unit23", typeUnit); //new Unit23_mc(); 
			container->setScale(0.81);
			container->init();
			Unit::init();
			this->autorelease();
			portalAnima = NULL;
			myPortal = NULL;
			if(world->listOfFirePortals.size() > 0)
			{
				if((gate - 1) >= 0 && (gate - 1) < world->listOfFirePortals.size())
				{
					this->myPortal = world->listOfFirePortals[(gate - 1)];
				}
				else
				{
					float tempObject = std::random();
					i = world->listOfFirePortals.size() - 1;
					while(i >= 0)
					{
						if(tempObject > (double)i / world->listOfFirePortals.size())
						{
							this->myPortal = world->listOfFirePortals[i];
							break;
						}
						i--;
					}
				}
				this->myPortal->myStack.push(this);
				readyDamage = false;
				moveFlag = false;
				path = this->myPortal->myPath;
				road = this->myPortal->myRoad;
				way = this->myPortal->myWay;
				finishPath = world->bezierClass->getPathLength(road, way);
				//this->x = this->myPortal->myPoint.x;
				//this->y = this->myPortal->myPoint.y;
				this_pt = this->myPortal->myPoint;
				this->setPosition(this_pt);
				container->setVisible(false);
				this->mouseChildren = false;
				this->mouseEnabled = false;
				this->portalAnima = new MovieClip("unit/", "RoadUnitFire_mc");// RoadUnitFire_mc();
				this->portalAnima->stop();
				this->portalAnima->setVisible(false);
				this->addChild(this->portalAnima);
			}
			this->setPosition(world->bezierClass->getPathPoint(path + speedK, road, way));
			//tempObject = world->bezierClass->getPathPoint(path + speedK, road, way);
			//this->x = tempObject.x;
			//this->y = tempObject.y;
			directionFlag = true;
			directionManage();
			//this->x = this_pt.x;
			//this->y = this_pt.y;
			this->setPosition(this_pt);
			return true;
		}// end function

		void Unit_23::animationHandler()
		{
			if(this->portalAnima)
			{
				if(this->myPortal->myStack[0] == this)
				{
					if(!this->myPortal->repeatFlag)
					{
						if(this->myPortal->repeatCounter < 30)
						{
							this->myPortal->repeatCounter++;
						}
						else if(this->myPortal->currentFrame < this->myPortal->totalFrames)
						{
							this->myPortal->gotoAndStop((this->myPortal->currentFrame + 1));
						}
						else
						{
							this->myPortal->repeatFlag = true;
							this->myPortal->repeatCounter = 0;
							this->myPortal->gotoAndStop(1);
						}
					}
					else if(this->myPortal->currentFrame < this->myPortal->totalFrames)
					{
						this->myPortal->gotoAndStop((this->myPortal->currentFrame + 1));
						if(this->myPortal->currentFrame == 23)
						{
							this->portalAnima->setVisible(true);
						}
						else if(this->myPortal->currentFrame > 23)
						{
							if(this->portalAnima->currentFrame < this->portalAnima->totalFrames)
							{
								this->portalAnima->gotoAndStop((this->portalAnima->currentFrame + 1));
								if(this->portalAnima->currentFrame == 7)
								{
									container->setVisible(true);
								}
							}
							else if(this->portalAnima->isVisible())
							{
								this->portalAnima->setVisible(false);
							}
						}
					}
					else
					{
						this->myPortal->repeatFlag = false;
						this->myPortal->gotoAndStop(1);
						//this->myPortal->myStack.splice(0, 1);
						this->myPortal->myStack.remove(0);
						this->removeChild(this->portalAnima);
						this->portalAnima = NULL;
						this->mouseChildren = true;
						this->mouseEnabled = true;
						readyDamage = true;
						moveFlag = true;
					}
				}
			}
			if(!dead && !icemanFlag)
			{
				if(direction != "up")
				{
					if(container->contMcs->currentFrame < 31)
					{
						if(container->contMcs->currentFrame < 30)
						{
							container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
						}
						else
						{
							container->contMcs->gotoAndStop(1);
						}
					}
					else
					{
						container->contMcs->gotoAndStop(container->contMcs->currentFrame - 30);
					}
				}
				else if(container->contMcs->currentFrame > 30)
				{
					if(container->contMcs->currentFrame < container->contMcs->totalFrames)
					{
						container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
					}
					else
					{
						container->contMcs->gotoAndStop(31);
					}
				}
				else
				{
					container->contMcs->gotoAndStop(container->contMcs->currentFrame + 30);
				}
			}
			Unit::animationHandler();
			return;
		}// end function

		void Unit_23::kill()
		{
			if(!dead && health <= 0)
			{
				OnceMovieClip * tempObject = NULL;
				if(direction != "up")
				{
					tempObject = new OnceMovieClip(this->world, "unit/", "Unit23HorisontDeath_mc", "Unit23HorisontDeath_mc");// new Indexes(new Unit23HorisontDeath_mc(), 1);
				}
				else
				{
					tempObject = new OnceMovieClip(world, "unit/", "Unit23VerticalDeath_mc", "Unit23VerticalDeath_mc");//Indexes(new Unit23VerticalDeath_mc(), 1);
				}
				tempObject->container->setScaleX(container->getScaleX());//X = container.scaleX;
				tempObject->container->setScaleY(container->getScaleY());//Y = container.scaleY;
				tempObject->setPosition(shoot_pt);
				//tempObject.x = shoot_pt.x;
				//tempObject.y = shoot_pt.y;
			}
			Unit::kill();
			return;
		}// end function

	}
}
