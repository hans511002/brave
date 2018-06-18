
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		Unit_27::Unit_27():teleportPhase(0),teleportTimer(0),teleportCounter(0),teleportStealthTimer(0),teleportStealthCounter(0),teleportDistance(0)
		    ,teleportRadius(0),soundCounter(0),soundTimer(5),soundTimer1(4),teleportUnitsMax(5),teleportUnitsCounter(0)
		{
			return;
		}// end function

		bool Unit_27::init()
		{
            typeUnit = 27;
            this->teleportCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            this->teleportTimer = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            this->teleportStealthCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            this->teleportStealthTimer = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            this->teleportDistance = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][32];
            this->teleportRadius = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][33];
            this->teleportUnitsMax = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
            container = new Unit_mc(this, "unit27", typeUnit);  
			container->setScale(0.9);
			container->init();
			Unit::init();
			this->autorelease(); 
            return true;
        }// end function

        void Unit_27::animationHandler()
        {
            if (!dead && !icemanFlag && !airFlag && !airShockFlag)
            {
                if (!teleportFlag)
                {
                    if (this->teleportCounter > 0)
                    {
                        this->teleportCounter--;
                    }
                    else if (this->soundCounter < this->soundTimer)
                    {
                        this->soundCounter++;
                        if (this->soundCounter == 1)
                        {
                            //Sounds.instance.playSoundWithVol("snd_unit_teleport", 0.85);
                        }
                    }
                    else
                    {
                        this->soundCounter = 0;
                        teleportFlag = true;
                        readyDamage = false;
                        mainMoveFlag = false;
                        this->teleportCounter = this->teleportTimer;
                        i = 0;
                        while (i < world->listOfUnits.size())
                        {
                            if (world->listOfUnits[i]->road == road)
                            {
                                if (!world->listOfUnits[i]->dead && world->listOfUnits[i]->readyDamage && world->listOfUnits[i]->atStage && !world->listOfUnits[i]->teleportAnima)
                                {
                                    if (world->listOfUnits[i]->typeUnit != 27 && world->listOfUnits[i]->typeUnit != 34)
                                    {
                                        if (this_pt.distance(world->listOfUnits[i]->this_pt) < this->teleportRadius)
                                        {
                                            if (this->teleportUnitsCounter < this->teleportUnitsMax)
                                            {
                                                this->teleportUnitsCounter ++;
                                                world->listOfUnits[i]->teleportFlag = this;
                                                world->listOfUnits[i]->readyDamage = false;
                                                world->listOfUnits[i]->mainMoveFlag = false;
                                                this->listOfTeleportUnits.push(world->listOfUnits[i]);
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            i++;
                        }
                        if (this->teleportUnitsCounter < this->teleportUnitsMax)
                        {
                            i = 0;
                            while (i < world->listOfUnits.size())
                            {
                                if (world->listOfUnits[i]->road != road)
                                {
                                    if (!world->listOfUnits[i]->dead && world->listOfUnits[i]->readyDamage && world->listOfUnits[i]->atStage && !world->listOfUnits[i]->teleportAnima)
                                    {
                                        if (world->listOfUnits[i]->typeUnit != 27 && world->listOfUnits[i]->typeUnit != 34)
                                        {
                                            if (Point.distance(this_pt, world->listOfUnits[i]->this_pt) < this->teleportRadius)
                                            {
                                                if (this->teleportUnitsCounter < this->teleportUnitsMax)
                                                {
                                                    this->teleportUnitsCounter ++;
                                                    world->listOfUnits[i]->teleportFlag = this;
                                                    world->listOfUnits[i]->readyDamage = false;
                                                    world->listOfUnits[i]->mainMoveFlag = false;
                                                    this->listOfTeleportUnits.push(world->listOfUnits[i]);
                                                }
                                                else
                                                {
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                                i++;
                            }
                        }
                        this->teleportUnitsCounter = 0;
                    }
                }
                else if (this->teleportPhase == 0)
                {
                    if (!teleportAnima)
                    {
                        teleportAnima = new MovieClip("unit/","UnitTeleportOut_mc");
                        teleportAnima->stop();
                        teleportAnima->setPosition(container->unitCase->getPosition());
                        //teleportAnima->x = container->unitCase.x;
                        //teleportAnima->y = container->unitCase.y;
                        teleportAnima->setMouseChildren(false);
                        teleportAnima->setMouseEnabled(false);
                        this->addChild(teleportAnima);
                        i = 0;
                        while (i < this->listOfTeleportUnits.size())
                        {
                            this->listOfTeleportUnits[i]->teleportAnima = new MovieClip("unit/","UnitTeleportOut_mc");
                            this->listOfTeleportUnits[i]->teleportAnima->stop();
                            this->listOfTeleportUnits[i]->teleportAnima->setPosition(this->listOfTeleportUnits[i]->container->unitCase->getPosition());
                            //this->listOfTeleportUnits[i]->teleportAnima->x = this->listOfTeleportUnits[i]->container->unitCase.x;
                            //this->listOfTeleportUnits[i]->teleportAnima->y = this->listOfTeleportUnits[i]->container->unitCase.y;
                            this->listOfTeleportUnits[i]->teleportAnima->setMouseChildren(false);
                            this->listOfTeleportUnits[i]->teleportAnima->setMouseEnabled(false);
                            this->listOfTeleportUnits[i]->addChild(this->listOfTeleportUnits[i]->teleportAnima);
                            i++;
                        }
                    }
                    else if (teleportAnima->currentFrame < teleportAnima->totalFrames)
                    {
                        teleportAnima->gotoAndStop((teleportAnima->currentFrame + 1));
                        container->alpha = container->alpha - 0.1;
                        i = 0;
                        while (i < this->listOfTeleportUnits.size())
                        {
                            this->listOfTeleportUnits[i]->teleportAnima->gotoAndStop((this->listOfTeleportUnits[i]->teleportAnima->currentFrame + 1));
                            this->listOfTeleportUnits[i]->container->alpha = this->listOfTeleportUnits[i]->container->alpha - 0.1;
                            i++;
                        }
                    }
                    else
                    {
                        this->teleportPhase = 1;
                        container->alpha = 0;
                        container->setVisible(false);
                        this->removeChild(teleportAnima);
                        teleportAnima = NULL;
                        i = 0;
                        while (i < this->listOfTeleportUnits.length)
                        {
                            if (this->listOfTeleportUnits[i]->teleportAnima)
                            {
                                this->listOfTeleportUnits[i]->container->alpha = 0;
                                this->listOfTeleportUnits[i]->setVisible(false);
                                this->listOfTeleportUnits[i]->removeChild(this->listOfTeleportUnits[i]->teleportAnima);
                                this->listOfTeleportUnits[i]->teleportAnima = NULL;
                            }
                            i++;
                        }
                        j = 0;
                        i = 0;
                        while (i < this->listOfTeleportUnits.size())
                        {
                            if (this->listOfTeleportUnits[i]->road != road)
                            {
                                j = j + 5;
                                this->listOfTeleportUnits[i]->road = road;
                                this->listOfTeleportUnits[i]->path = path + j;
                                this->listOfTeleportUnits[i]->finishPath = finishPath;
                            }
                            i++;
                        }
                    }
                }
                else if (this->teleportPhase == 1)
                {
                    if (this->teleportStealthCounter > 0)
                    {
                        this->teleportStealthCounter --;
                    }
                    else if (this->soundCounter < this->soundTimer1)
                    {
                        this->soundCounter ++;
                        if (this->soundCounter == 1)
                        {
                            //Sounds.instance.playSoundWithVol("snd_unit_teleport", 0.85);
                        }
                    }
                    else
                    {
                        this->soundCounter = 0;
                        this->teleportPhase = 2;
                        container->setVisible(true);
                        path = path + this->teleportDistance;
                        this->teleportStealthCounter = this->teleportStealthTimer;
                        this_pt = world->bezierClass->getPathPoint(path, road, way);
                        this->setPosition(this_pt); 
                        shoot_pt = container->localToGlobal(container->getPosition());
                        //shoot_pt = container->localToGlobal(new Point(container->cont->x, container->cont->y));
                        teleportAnima = new MovieClip("unit/","UnitTeleportIn_mc");//new UnitTeleportIn_mc();
                        teleportAnima->stop();
                        teleportAnima->setPosition(container->unitCase->getPosition());
                        //teleportAnima->x = container->unitCase.x;
                        //teleportAnima->y = container->unitCase.y; 
                        teleportAnima->setMouseChildren(false);
                        teleportAnima->setMouseEnabled(false);
                        this->addChild(teleportAnima);
                        i = 0;
                        while (i < this->listOfTeleportUnits.size())
                        { 
                            this->listOfTeleportUnits[i]->setVisible(true);
                            this->listOfTeleportUnits[i]->path = this->listOfTeleportUnits[i]->path + this->teleportDistance;
                            cocos2d::Point tempObject = world->bezierClass->getPathPoint(this->listOfTeleportUnits[i]->path, this->listOfTeleportUnits[i]->road, this->listOfTeleportUnits[i]->way);
                            this->listOfTeleportUnits[i]->setPosition(tempObject);
                            this->listOfTeleportUnits[i]->this_pt = tempObject;//new Point(this->listOfTeleportUnits[i]->x, this->listOfTeleportUnits[i]->y);
                            this->listOfTeleportUnits[i]->shoot_pt = tempObject;//this->listOfTeleportUnits[i]->container->localToGlobal(new Point(this->listOfTeleportUnits[i]->container->cont->x, this->listOfTeleportUnits[i]->container->cont->y));
                            this->listOfTeleportUnits[i]->teleportAnima = new MovieClip("unit/","UnitTeleportIn_mc");//new UnitTeleportIn_mc();
                            this->listOfTeleportUnits[i]->teleportAnima->stop();
                            this->listOfTeleportUnits[i]->teleportAnima->setPosition(this->listOfTeleportUnits[i]->container->unitCase->getPosition());
                            //this->listOfTeleportUnits[i]->teleportAnima->x = this->listOfTeleportUnits[i]->container->unitCase.x;
                            //this->listOfTeleportUnits[i]->teleportAnima->y = this->listOfTeleportUnits[i]->container->unitCase.y; 
                            this->listOfTeleportUnits[i]->teleportAnima->setMouseChildren(false);
                            this->listOfTeleportUnits[i]->teleportAnima->setMouseEnabled(false);
                            this->listOfTeleportUnits[i]->addChild(this->listOfTeleportUnits[i]->teleportAnima);
                            i++;
                        }
                    }
                }
                else if (this->teleportPhase == 2)
                {
                    if (teleportAnima->currentFrame < teleportAnima->totalFrames)
                    {
                        teleportAnima->gotoAndStop((teleportAnima->currentFrame + 1));
                        container->alpha = container->alpha + 0.1;
                        i = 0;
                        while (i < this->listOfTeleportUnits.size())
                        {
                            this->listOfTeleportUnits[i]->teleportAnima->gotoAndStop((this->listOfTeleportUnits[i]->teleportAnima->currentFrame + 1));
                            this->listOfTeleportUnits[i]->container->alpha = this->listOfTeleportUnits[i]->container->alpha + 0.1;
                            i++;
                        }
                    }
                    else
                    {
                        this->teleportPhase = 0;
                        container->alpha = 1;
                        teleportFlag = false;
                        readyDamage = true;
                        mainMoveFlag = true;
                        this->removeChild(teleportAnima);
                        teleportAnima = NULL;
                        directionFlag = true;
                        moveHandler();
                        i = 0;
                        while (i < this->listOfTeleportUnits.size())
                        {
                            if (this->listOfTeleportUnits[i]->teleportFlag == this)
                            {
                                this->listOfTeleportUnits[i]->container->alpha = 1;
                                this->listOfTeleportUnits[i]->teleportFlag = false;
                                this->listOfTeleportUnits[i]->readyDamage = true;
                                this->listOfTeleportUnits[i]->mainMoveFlag = true;
                                this->listOfTeleportUnits[i]->removeChild(this->listOfTeleportUnits[i]->teleportAnima);
                                this->listOfTeleportUnits[i]->teleportAnima = NULL;
                                this->listOfTeleportUnits[i]->directionFlag = true;
                                this->listOfTeleportUnits[i]->moveHandler();
                            }
                            i++;
                        }
                        this->listOfTeleportUnits.clear();
                        //this->listOfTeleportUnits.length = [];
                    }
                }
                if (direction != "up")
                {
                    if (container->contMcs->currentFrame < 9)
                    {
                        if (container->contMcs->currentFrame < 8)
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
                        container->contMcs->gotoAndStop(container->contMcs->currentFrame - 8);
                    }
                }
                else if (container->contMcs->currentFrame > 8)
                {
                    if (container->contMcs->currentFrame < container->contMcs->totalFrames)
                    {
                        container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                    }
                    else
                    {
                        container->contMcs->gotoAndStop(9);
                    }
                }
                else
                {
                    container->contMcs->gotoAndStop(container->contMcs->currentFrame + 8);
                }
                if (direction == "left" || direction == "right")
                {
                    if (!airFlag && !airShockFlag || container->cont->currentFrame != 1)
                    {
                        if (container->cont->currentFrame > 16)
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
                        else if (container->cont->currentFrame < 16)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container->cont->currentFrame != 17)
                {
                    if (container->cont->currentFrame > 16)
                    {
                        if (container->cont->currentFrame < container->cont->totalFrames)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(17);
                        }
                    }
                    else if (container->cont->currentFrame < 16)
                    {
                        container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else
                    {
                        container->cont->gotoAndStop(17);
                    }
                }
            }
            Unit::animationHandler();
            return;
        }// end function

        void Unit_27::kill()
        {
            if (teleportFlag)
            {
                while (teleportFlag)
                {
                    this->animationHandler();
                }
            }
            Unit::kill();
            return;
        }// end function

    }
}
