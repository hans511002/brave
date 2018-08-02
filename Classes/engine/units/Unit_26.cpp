
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine 
{
	namespace units
	{
		Unit_26::Unit_26()
		{
			return;
		}// end function

		bool Unit_26::init()
		{
            typeUnit = 26;
            container = new Unit_mc(this, "unit26", typeUnit);  
			container->setScale(0.81);
			container->init();
			Unit::init();
			this->autorelease();
			portalAnima = NULL;
			myPortal = NULL;
            if (world->listOfLevinPortals.size() > 0)
            {
                if ((gate - 1) >= 0 && (gate - 1) < world->listOfLevinPortals.size())
                {
                    this->myPortal = world->listOfLevinPortals[(gate - 1)];
                }
                else
                {
                    tempObject = std::random();
                    i = world->listOfLevinPortals.size() - 1;
                    while (i >= 0)
                    {
                        if (tempObject > i / world->listOfLevinPortals.size())
                        {
                            this->myPortal = world->listOfLevinPortals[i];
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
				//container->setVisible(false);
				container->setAlpha(0);
				this->setMouseChildren(false);
				this->setMouseEnabled(false);
				this->portalAnima = new MovieClip("unit/", "RoadUnitLevin_mc");// RoadUnitLevin_mc();
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

        void Unit_26::animationHandler()
        {
            if (this->portalAnima)
            {
                if (this->myPortal->myStack[0] == this)
                {
                    if (!this->myPortal->repeatFlag)
                    {
                        if (this->myPortal->repeatCounter < 30)
                        {
                            this->myPortal->repeatCounter ++;
                        }
                        else if (this->myPortal->currentFrame < this->myPortal->totalFrames)
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
                    else if (this->myPortal->currentFrame < this->myPortal->totalFrames)
                    {
                        this->myPortal->gotoAndStop((this->myPortal->currentFrame + 1));
                        if (this->myPortal->currentFrame == 26)
                        {
                            this->portalAnima->setVisible(true); //visible = true;
                        }
                        else if (this->myPortal->currentFrame > 26)
                        {
                            if (this->portalAnima->currentFrame < this->portalAnima->totalFrames)
                            {
                                this->portalAnima->gotoAndStop((this->portalAnima->currentFrame + 1));
                                if (this->portalAnima->currentFrame > 6)
                                {
                                    if (container->getAlpha() < 1)
                                    {
                                        container->setAlpha(container->getAlpha() * 1.2);
                                    }
                                }
                            }
                            else if (this->portalAnima->isVisible())
                            {
                                this->portalAnima->setVisible(false); //visible = false;
                            }
                        }
                    }
                    else
                    {
                        this->myPortal->repeatFlag = false;
                        this->myPortal->gotoAndStop(1);
                        this->myPortal->myStack.splice(0, 1);
                        this->removeChild(this->portalAnima);
                        this->portalAnima = NULL;
                        container->setAlpha(1); 
                        this->setMouseChildren(true);
                        this->setMouseEnabled(true);
                        readyDamage = true;
                        moveFlag = true;
                    }
                }
            }
            if (!dead && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container->contMcs->currentFrame < 61)
                    {
                        if (container->contMcs->currentFrame < 60)
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
                        container->contMcs->gotoAndStop(container->contMcs->currentFrame - 60);
                    }
                }
                else if (container->contMcs->currentFrame > 60)
                {
                    if (container->contMcs->currentFrame < container->contMcs->totalFrames)
                    {
                        container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                    }
                    else
                    {
                        container->contMcs->gotoAndStop(61);
                    }
                }
                else
                {
                    container->contMcs->gotoAndStop(container->contMcs->currentFrame + 60);
                }
                if (listOfTornado.size() > 0)
                {
                    if (world->frameCounter == 10 || world->frameCounter == 20 || world->frameCounter == 30)
                    {
                        float tempObject1 = std::round(std::random() * (3 - 1)) + 1;// Math.round(Math.random() * (3 - 1)) + 1;
                        float tempObject2 = world->bezierClass->getPathLength(road, tempObject1);
                        float tempObject6 = 10000;
                        j = 0;
                        while (j < tempObject2)
                        {
                            cocos2d::Point tempObject3 = world->bezierClass->getPathPoint(j, road, tempObject1);
                            //tempObject3 = new Point(tempObject3.x, tempObject3.y);
                            float tempObject4 = this_pt.distance(tempObject3);
                            if (tempObject4 < 30)
                            {
                                if (tempObject4 < tempObject6)
                                {
                                    tempObject6 = tempObject4;
                                }
                                else
                                {
                                    Unit * tempObject = world->addUnit(33, road, tempObject1, j + std::random() * 20);
                                    tempObject->direction = direction;
                                    tempObject->readyDamage = false;
                                    tempObject->moveFlag = false;
                                    tempObject->setPosition(this->getPosition());
                                    tempObject->setAlpha(0);
                                    listOfTornado.splice(0, 1);
                                    break;
                                }
                            }
                            j = j + 10;
                        }
                    }
                }
            }
            Unit::animationHandler();
            return;
        }// end function

        void Unit_26::kill()
        {
            if (!dead && health <= 0)
            {
                MovieClip * tempObject = NULL;
				if(direction != "up")
				{
					tempObject = new MovieClip(world, "unit/", "Unit26HorisontDeath_mc", "Unit26HorisontDeath_mc");// new Indexes(new Unit26HorisontDeath_mc(), 1);
				}
				else
				{
					tempObject = new MovieClip(world, "unit/", "Unit26VerticalDeath_mc", "Unit26VerticalDeath_mc");//Indexes(new Unit26VerticalDeath_mc(), 1);
				}
				tempObject->container->setScaleX(container->getScaleX());//X = container.scaleX;
				tempObject->container->setScaleY(container->getScaleY());//Y = container.scaleY;
				tempObject->setPosition(shoot_pt);				 
            }
            Unit::kill();
            return;
        }// end function

    }
}
