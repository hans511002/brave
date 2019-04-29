
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine 
{
	namespace units
	{ 

		bool Unit_26::init()
		{
            typeUnit = 26;
            container = new Unit_mc(this, "Unit26_mc", typeUnit);  
			container->setScale(0.81f);
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
                    float path = std::random();
                    i = world->listOfLevinPortals.size() - 1;
                    while (i >= 0)
                    {
                        if (path > i / world->listOfLevinPortals.size())
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
				this->portalAnima = new MovieClip("unit/", "RoadUnitLevin_mc", "RoadUnitLevin_mc");// RoadUnitLevin_mc();
				this->portalAnima->stop();
				this->portalAnima->setVisible(false);
				this->addChild(this->portalAnima);
            }
            this->setPosition(world->bezierClass->getPathPoint(path + speedK, road, way));
			//path = world->bezierClass->getPathPoint(path + speedK, road, way);
			//this->x = path.x;
			//this->y = path.y;
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
                        if (this->myPortal->currentFrame == 26)
                        {
                            this->portalAnima->setVisible(true); //visible = true;
                        }
                        else if (this->myPortal->currentFrame > 26)
                        {
                            if (this->portalAnima->currentFrame < this->portalAnima->totalFrames)
                            {
                                this->portalAnima->tryPlay();
				                //this->portalAnima->gotoAndStop((this->portalAnima->currentFrame + 1));
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
                if (listOfTornado.size() > 0)
                {
                    if (world->frameCounter == 10 || world->frameCounter == 20 || world->frameCounter == 30)
                    {
                        float path1 = ::round(std::random() * (3 - 1)) + 1;// Math.round(Math.random() * (3 - 1)) + 1;
                        float path2 = world->bezierClass->getPathLength(road, path1);
                        float path6 = 10000;
                        j = 0;
                        while (j < path2)
                        {
                            cocos2d::Point path3 = world->bezierClass->getPathPoint(j, road, path1);
                            //path3 = new Point(path3.x, path3.y);
                            float path4 = this_pt.distance(path3);
                            if (path4 < 30)
                            {
                                if (path4 < path6)
                                {
                                    path6 = path4;
                                }
                                else
                                {
                                    Unit * unit = world->addUnit(33, road, path1, j + std::random() * 20);
                                    unit->direction = direction;
                                    unit->readyDamage = false;
                                    unit->moveFlag = false;
                                    unit->setPosition(this->getPosition());
                                    unit->setAlpha(0);
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
                MovieClip * deadMc = NULL;
				if(direction != "up")
				{
					deadMc = new MovieClip(world, "unit/", "Unit26HorisontDeath_mc", "Unit26HorisontDeath_mc");// new Indexes(new Unit26HorisontDeath_mc(), 1);
				}
				else
				{
					deadMc = new MovieClip(world, "unit/", "Unit26VerticalDeath_mc", "Unit26VerticalDeath_mc");//Indexes(new Unit26VerticalDeath_mc(), 1);
				}
				deadMc->container->setScaleX(container->getScaleX());//X = container.scaleX;
				deadMc->container->setScaleY(container->getScaleY());//Y = container.scaleY;
				deadMc->setPosition(shoot_pt);				 
            }
            Unit::kill();
            return;
        }// end function

    }
}
