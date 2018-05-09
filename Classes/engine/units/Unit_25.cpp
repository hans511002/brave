﻿
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		Unit_25::Unit_25()
		{
			return;
		}// end function

		bool Unit_25::init()
		{
            typeUnit = 25;
            container = new Unit_mc(this, "unit25", typeUnit);  
			container->setScale(0.81);
			container->init();
			Unit::init();
			this->autorelease();
			portalAnima = NULL;
			myPortal = NULL;
            container->maskCont->stop();
            container->myFirstPoint =container->getPosition();// new Point(container->cont->x, container->cont->y);
            if (world->listOfStonePortals.size() > 0)
            {
                //container->cont->mask = container->maskCont;
                container->cont->getArmature()->getSlot("shadow")->setDisplayIndex(-1);// setVisible(false);//container->shadow.visible = false;
                if ((gate - 1) >= 0 && (gate - 1) < world->listOfStonePortals.size())
                {
                    this->myPortal = world->listOfStonePortals[(gate - 1)];
                }
                else
                {
                    tempObject = std::random();
                    i = world->listOfStonePortals.size() - 1;
                    while (i >= 0)
                    { 
                        if (tempObject > i / world->listOfStonePortals.size())
                        {
                            this->myPortal = world->listOfStonePortals[i];
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
				this->portalAnima = new MovieClip("unit/", "RoadUnitStone_mc");// RoadUnitStone_mc();
				this->portalAnima->stop();
				this->portalAnima->setVisible(false);
				this->addChild(this->portalAnima); 
            }
            else
            {
                container->setPositionY(0);
                container->maskCont->setVisible(false);
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

        void Unit_25::update(float dt)
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
                        if (this->myPortal->currentFrame == 23)
                        {
                            this->portalAnima->setVisible(true);
                        }
                        else if (this->myPortal->currentFrame > 23)
                        {
                            if (this->portalAnima->currentFrame < this->portalAnima->totalFrames)
                            {
                                this->portalAnima->gotoAndStop((this->portalAnima->currentFrame + 1));
                                if (container->getPositionY() > 0)
                                {
                                    container->setPositionY(container->getPositionY() - container->myFirstPoint.y / this->portalAnima->totalFrames);
                                }
                                //if (container->cont->y > 0) 
                                //    container->cont->y = container->cont->y - container->cont->myFirstPoint.y / this->portalAnima->totalFrames;
                            }
                            else if (this->portalAnima->isVisible())
                            {
                                this->portalAnima->setVisible(false); //visible = false;
                                container->setPositionY(0);//cont->y = 0;
                                container->cont->getArmature()->getSlot("shadow")->setDisplayIndex(-1); //setVisible(false);//container->shadow->setVisible(true); //visible = true;
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
						container->maskCont->setVisible(false); //visible = false;
                        //container->cont->mask = NULL; 
                        this->mouseChildren = true;
                        this->mouseEnabled = true;
                        readyDamage = true;
                        moveFlag = true;
                    }
                }
            }
            //else
            {
                Unit::update(dt);
            }
            return;
        }// end function

        void Unit_25::animationHandler() 
        {
            if (!dead && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container->contMcs->currentFrame < 41)
                    {
                        if (container->contMcs->currentFrame < 40)
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
                        container->contMcs->gotoAndStop(container->contMcs->currentFrame - 40);
                    }
                }
                else if (container->contMcs->currentFrame > 40)
                {
                    if (container->contMcs->currentFrame < container->contMcs->totalFrames)
                    {
                        container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                    }
                    else
                    {
                        container->contMcs->gotoAndStop(41);
                    }
                }
                else
                {
                    container->contMcs->gotoAndStop(container->contMcs->currentFrame + 40);
                }
            }
            Unit::animationHandler();
            return;
        }// end function

        void Unit_25::kill()
        {
            if (!dead && health <= 0)
            {
                OnceMovieClip * tempObject = NULL;
				if(direction != "up")
				{
					tempObject = new OnceMovieClip(world, "unit/", "Unit25HorisontDeath_mc", "Unit25HorisontDeath_mc");// new Indexes(new Unit25HorisontDeath_mc(), 1);
				}
				else
				{
					tempObject = new OnceMovieClip(world, "unit/", "Unit25VerticalDeath_mc", "Unit25VerticalDeath_mc");//Indexes(new Unit25VerticalDeath_mc(), 1);
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
