
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		Unit_28::Unit_28():giveHealthRadius(0),giveHeathCounter(0),giveHeathTimer(0),giveHeath(0)
		{
			return;
		}// end function

		bool Unit_28::init()
		{
            typeUnit = 28;
            this->giveHealthRadius = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            this->giveHeathTimer = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            this->giveHeathCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            this->giveHeath = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][32];
            container = new Unit_mc(this, "unit28", typeUnit);  
			container->setScale(0.8);
			container->init();
			Unit::init();
			this->autorelease(); 
            return true;
        }// end function

        void Unit_28::animationHandler()
        {
            if (!dead && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container->contMcs->currentFrame < 12)
                    {
                        if (container->contMcs->currentFrame < 11)
                        {
                            container->contMcs->tryPlay();
				            //container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                        }
                        else
                        {
                            container->contMcs->gotoAndStop(1);
                        }
                    }
                    else
                    {
                        container->contMcs->gotoAndStop(1);
                    }
                }
                else if (container->contMcs->currentFrame != 12)
                {
                    container->contMcs->gotoAndStop(12);
                }
                if (!airFlag && !airShockFlag || container->cont->currentFrame != 1)
                {
                    if (container->cont->currentFrame < container->cont->totalFrames)
                    {
                        container->cont->tryPlay();
				        //container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else
                    {
                        container->cont->gotoAndStop(1);
                    }
                }
                if (this->giveHeathCounter > 0)
                {
                    this->giveHeathCounter --;
                }
                else if (world->frameCounter == 30)
                {
                    i = 0;
                    while (i < world->listOfUnits.size())
                    {
                        if (world->listOfUnits[i]->typeUnit != 28 && world->listOfUnits[i]->typeUnit != 34 && world->listOfUnits[i]->atStaged && world->listOfUnits[i]->health < world->listOfUnits[i]->healthMax)
                        {
                            if (this_pt.distance(world->listOfUnits[i]->this_pt) < this->giveHealthRadius)
                            {
                                if (this->giveHeathCounter == 0)
                                {
                                    this->giveHeathCounter = this->giveHeathTimer;
                                    container->giveHealth1->setVisible(true);
                                    container->giveHealth2->setVisible(true);
                                    container->giveHealth3->setVisible(true);
                                }
                                world->listOfUnits[i]->healthPlusFlag = true;
                                world->listOfUnits[i]->healthPlusValue = world->listOfUnits[i]->healthMax * this->giveHeath;
                                world->listOfUnits[i]->healthPlusValue = world->listOfUnits[i]->healthPlusValue / world->listOfUnits[i]->container->buffHP->totalFrames;
                                world->listOfUnits[i]->container->buffHP->gotoAndStop(1);
                            }
                        }
                        i++;
                    }
                }
            }
            if (container->giveHealth1->visible)
            {
                if (container->giveHealth1->currentFrame < container->giveHealth1->totalFrames)
                {
                    container->giveHealth1->tryPlay();
				    //container->giveHealth1->gotoAndStop((container->giveHealth1->currentFrame + 1));
                    container->giveHealth2->tryPlay();
				    //container->giveHealth2->gotoAndStop((container->giveHealth2->currentFrame + 1));
                    container->giveHealth3->tryPlay();
				    //container->giveHealth3->gotoAndStop((container->giveHealth3->currentFrame + 1));
                }
                else
                {
                    container->giveHealth1->gotoAndStop(1);
                    container->giveHealth2->gotoAndStop(1);
                    container->giveHealth3->gotoAndStop(1);
                    container->giveHealth1->setVisible(false);
                    container->giveHealth2->setVisible(false);
                    container->giveHealth3->setVisible(false);
                }
            }
            Unit::animationHandler();
            return;
        }// end function

    }
}
