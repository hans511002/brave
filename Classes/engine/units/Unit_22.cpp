
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{  
        Unit_22::Unit_22()
        {
            return;
        }// end function

        bool Unit_22::init()
        { 
            typeUnit = 22;
            this->blockTowerRadius = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            container = new Unit_mc(this,"unit22", typeUnit); //new Unit22_mc(); 
            container->setScale(0.85);
            container->init();
            Unit::init();
            this->autorelease();   
             
            this->blockRadiusGr = new MovieClip("unit/", "BlockRadius_mc");//new BlockRadius_mc();
            this->blockRadiusGr->stop();
            
            this->blockRadiusGr->setPosition(this->getPosition());//.x = this->x;
            //this->blockRadiusGr.y = this->y;
			float wid=this->blockRadiusGr->getContentSize().width;
			float scale = this->blockTowerRadius * 2 / wid;
			this->blockRadiusGr->setScale(scale);
            //this->blockRadiusGr.width = this->blockTowerRadius * 2;
            //this->blockRadiusGr.scaleY = this->blockRadiusGr.scaleX;
            this->blockRadiusGr->setMouseChildren(false);
            this->blockRadiusGr->setMouseEnabled(false);
            this->blockRadiusGr->setVisible(false);
            world->addChild(this->blockRadiusGr);
            //world->listOfIndexes0.push(this->blockRadiusGr);
            return true;
        }// end function

		void Unit_22::animationHandler()
        {
            if (!dead)
            {
                if (atStage && !icemanFlag && !teleportFlag)
                {
                    if (world->frameCounter == 10 || world->frameCounter == 20 || world->frameCounter == 30)
                    {
                        i = 0;
                        while (i < world->listOfTowers.size())
                        {
                            if (!world->listOfTowers[i]->container->blockTower->isVisible() && !world->listOfTowers[i]->container->boneBlock->isVisible())
                            {
                                this->testTarget = world->listOfTowers[i]->this_pt;
                                this->scanAtRadius();
                                if (this->greenFlag)
                                {
                                    world->listOfTowers[i]->container->blockTower->setVisible(true);
                                    world->listOfTowers[i]->blockTowerFlag = true;
                                    if (world->exchange)
                                    {
                                        if (world->exchange->myTower == world->listOfTowers[i])
                                        {
                                            world->exchange->kill();
                                        }
                                    } 
                                    world->listOfTowers[i]->setMouseChildren(false);
                                    world->listOfTowers[i]->setMouseEnabled(false);
                                    if (world->towerMenu)
                                    {
                                        if (world->towerMenu->myTower == world->listOfTowers[i])
                                        {
                                            world->towerMenu->closeMenu();
                                        }
                                    }
                                    else if (world->ultraTowerMenu)
                                    {
                                        if (world->ultraTowerMenu->myTower == world->listOfTowers[i])
                                        {
                                            world->ultraTowerMenu->closeMenu();
                                        }
                                    }
                                }
                            }
                            i++;
                        }
                    }
                    if (direction != "up")
                    {
                        if (container->contMcs->currentFrame < 21)
                        {
                            if (container->contMcs->currentFrame < 20)
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
                            container->contMcs->gotoAndStop(container->contMcs->currentFrame - 20);
                        }
                    }
                    else if (container->contMcs->currentFrame > 20)
                    {
                        if (container->contMcs->currentFrame < container->contMcs->totalFrames)
                        {
                            container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                        }
                        else
                        {
                            container->contMcs->gotoAndStop(21);
                        }
                    }
                    else
                    {
                        container->contMcs->gotoAndStop(container->contMcs->currentFrame + 20);
                    }
                    if (direction == "left" || direction == "right")
                    {
                        if (!airFlag && !airShockFlag || container->cont->currentFrame != 1)
                        {
                            if (container->cont->currentFrame > 20)
                            {
                                if (container->cont->currentFrame < container->cont->totalFrames)
                                {
                                    container->cont->gotoAndStop((container->cont->currentFrame + 1));
                                }
                                else
                                {
                                    container->cont->gotoAndStop(1);
                                }
                            }
                            else if (container->cont->currentFrame < 20)
                            {
                                container->cont->gotoAndStop((container->cont->currentFrame + 1));
                            }
                            else
                            {
                                container->cont->gotoAndStop(1);
                            }
                        }
                    }
                    else if (!airFlag && !airShockFlag || container->cont->currentFrame != 21)
                    {
                        if (container->cont->currentFrame > 20)
                        {
                            if (container->cont->currentFrame < container->cont->totalFrames)
                            {
                                container->cont->gotoAndStop((container->cont->currentFrame + 1));
                            }
                            else
                            {
                                container->cont->gotoAndStop(21);
                            }
                        }
                        else if (container->cont->currentFrame < 20)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(21);
                        }
                    }
                }
                if (atStage && !icemanFlag && !teleportFlag)
                {
                    if (!this->blockRadiusGr->isVisible())
                    {
                        this->blockRadiusGr->setVisible(true);
                    }
                    else if (this->blockRadiusGr->currentFrame < this->blockRadiusGr->totalFrames)
                    {
                        this->blockRadiusGr->gotoAndStop((this->blockRadiusGr->currentFrame + 1));
                    }
                    else
                    {
                        this->blockRadiusGr->gotoAndStop(1);
                    }
                }
                else if (this->blockRadiusGr->isVisible())
                {
                    this->blockRadiusGr->setVisible(false);
                }
                this->blockRadiusGr->setPosition(this->getPosition());
                //this->blockRadiusGr.x = this->x;
                //this->blockRadiusGr.y = this->y;
            }
            Unit::animationHandler();
            return;
        }// end function

		void Unit_22::scanAtRadius()
        {
            this->greenFlag = false;
            float tempObject = this->blockTowerRadius - this->blockTowerRadius * (1 - world->scaleRadius);
			cocos2d::Point thpos = this->getPosition();
			if((this->testTarget.x - thpos.x) * (this->testTarget.x - thpos.x) / (this->blockTowerRadius * this->blockTowerRadius)
			   + (this->testTarget.y - thpos.y) * (this->testTarget.y - thpos.y) / (tempObject * tempObject) <= 1)
            {
                this->greenFlag = true;
            }
            return;
        }// end function

		void Unit_22::kill()
        {
            if (!dead)
            {
                if(this->blockRadiusGr){
                    world->removeChild(this->blockRadiusGr);
                    this->blockRadiusGr=NULL;
                }
                //i = 0;
                //while (i < world->listOfIndexes0.length)
                //{
                //    if (world->listOfIndexes0[i] == this->blockRadiusGr)
                //    {
                //        world->removeChild(this->blockRadiusGr);
                //        world->listOfIndexes0.splice(i, 1);
                //        break;
                //    }
                //    i++;
                //}
            }
            Unit::kill();
            return;
        }// end function

    }
}
