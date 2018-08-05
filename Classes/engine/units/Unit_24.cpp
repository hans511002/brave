
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{ 
	namespace units
	{ 

		bool Unit_24::init()
        { 
            typeUnit = 24; 
            speedKRun = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            speedRunTimerIce1 = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            speedRunTimerIce2 = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][32];
            speedRunTimerIce3 = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][33];
            speedRunTimerIce4 = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
            container = new Unit_mc(this, "unit24", typeUnit); //new Unit24_mc(); 
			container->setScale(0.81);
			container->init();
			Unit::init();
			this->autorelease();
			portalAnima = NULL;
			myPortal = NULL;
            if (world->listOfIcePortals.size() > 0)
            {
                if ((gate - 1) >= 0 && (gate - 1) < world->listOfIcePortals.size())
                {
                    this->myPortal = world->listOfIcePortals[(gate - 1)];
                }
                else
                {
                    float tempObject =std::random();// Math.random();
                    i = world->listOfIcePortals.size() - 1;
                    while (i >= 0)
                    { 
                        if (tempObject > (double)i / world->listOfIcePortals.size())
                        {
                            this->myPortal = world->listOfIcePortals[i];
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
                this_pt = this->myPortal->myPoint;
				this->setPosition(this_pt);
				//container->setVisible(false);
				container->setAlpha(0);//container->alpha = 0;

                this->setMouseChildren(false);
                this->setMouseEnabled(false);
                this->portalAnima = new MovieClip("unit/", "RoadUnitIce_mc");// RoadUnitIce_mc();
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

        void Unit_24::animationHandler()
        {
            if (this->portalAnima)
            {
                if (this->myPortal->myStack[0] == this)
                {
                    if (!this->myPortal->repeatFlag)
                    {
                        if (this->myPortal->repeatCounter < 30)
                        {
                            this->myPortal->repeatCounter++;
                        }
                        else if (this->myPortal->currentFrame < this->myPortal->totalFrames)
                        {
                            this->myPortal->tryPlay();
				            //this->myPortal->gotoAndStop((this->myPortal->currentFrame + 1));
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
                        this->myPortal->tryPlay();
				        //this->myPortal->gotoAndStop((this->myPortal->currentFrame + 1));
                        if (this->myPortal->currentFrame == 14)
                        {
                            this->portalAnima->setVisible(true);
                        }
                        else if (this->myPortal->currentFrame > 14)
                        {
                            if (this->portalAnima->currentFrame < this->portalAnima->totalFrames)
                            {
                                this->portalAnima->tryPlay();
				                //this->portalAnima->gotoAndStop((this->portalAnima->currentFrame + 1));
                                if (this->portalAnima->currentFrame > 8)
                                {
                                    if (container->getAlpha() < 1)
                                    {
                                        container->setAlpha(container->getAlpha()* 1.1);
                                    }
                                }
                            }
                            else if (this->portalAnima->isVisible())
                            {
                                this->portalAnima->setVisible(false);
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
                    if (container->cont->currentFrame < 61)
                    {
                        if (container->cont->currentFrame < 60)
                        {
                            container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(1);
                        }
                    }
                    else
                    {
                        container->cont->gotoAndStop(container->cont->currentFrame - 60);
                    }
                }
                else if (container->cont->currentFrame > 60)
                {
                    if (container->cont->currentFrame < container->cont->totalFrames)
                    {
                        container->cont->tryPlay();
				        //container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else
                    {
                        container->cont->gotoAndStop(61);
                    }
                }
                else
                {
                    container->cont->gotoAndStop(container->cont->currentFrame + 60);
                }
            }
            Unit::animationHandler();
            return;
        }// end function

        void Unit_24::kill()
        {
            if (!dead && health <= 0)
            {
                MovieClip * tempObject = NULL;
				if(direction != "up")
				{
					tempObject = new MovieClip(this->world, "unit/", "Unit24HorisontDeath_mc", "Unit24HorisontDeath_mc");// new Indexes(new Unit24HorisontDeath_mc(), 1);
				}
				else
				{
					tempObject = new MovieClip(world, "unit/", "Unit24VerticalDeath_mc", "Unit24VerticalDeath_mc");//Indexes(new Unit24VerticalDeath_mc(), 1);
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
