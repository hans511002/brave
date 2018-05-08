
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		Unit_30::Unit_30():returnHealth(0),stealthCounter(0),stealthTimer(0),phase(1)
		{
			return;
		}// end function
    
        bool Unit_30::init()
        {
            typeUnit = 30;
            readyDamage = false;
            moveFlag = false;
            this->returnHealth = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][33];
            this->stealthTimer = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
            this->stealthCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
            container = new Unit_mc(this, "unit30", typeUnit);  
			container->setScale(0.85);
			container->init();
			Unit::init();
			this->autorelease();  
            container->contMcs->gotoAndStop(68);
            this->alpha = 0; 
            this->mouseChildren = false;
            this->mouseEnabled = false;
            i = 0;
            while (i < world->listOfUnits.size())
            { 
                if (world->listOfUnits[i] == this)
                {
                    world->listOfUnits.splice(i, 1);
                    break;
                }
                i++;
            }
            //world->listOfClasses.push(this);
            //world->listOfIndexes0.push(this);
            return true;
        }// end function

        void Unit_30::animationHandler() 
        {
            if (!dead)
            {
                if (readyDamage)
                {
                    if (!icemanFlag && !airFlag && !airShockFlag)
                    {
                        if (direction != "up")
                        {
                            if (container->contMcs->currentFrame == 101)
                            {
                                container->contMcs->gotoAndStop(33);
                            }
                            else if (container->contMcs->currentFrame == 102)
                            {
                                container->contMcs->gotoAndStop(34);
                            }
                        }
                        else if (container->contMcs->currentFrame == 33)
                        {
                            container->contMcs->gotoAndStop(101);
                        }
                        else if (container->contMcs->currentFrame == 34)
                        {
                            container->contMcs->gotoAndStop(102);
                        }
                        if (direction == "left" || direction == "right")
                        {
                            if (container->cont->currentFrame > 24)
                            {
                                container->cont->gotoAndStop((container->cont->currentFrame + 1));
                                if (container->cont->x >= -1 && container->cont->x <= 1 && container->cont->y >= -1 && container->cont->y <= 1)
                                {
                                    container->cont->gotoAndStop(1);
                                }
                                if (container->cont->currentFrame < 33)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < 37)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container->cont->currentFrame < 44)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < container->cont->totalFrames)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                            else
                            {
                                if (container->cont->currentFrame < 24)
                                {
                                    container->cont->gotoAndStop((container->cont->currentFrame + 1));
                                }
                                else
                                {
                                    container->cont->gotoAndStop(1);
                                }
                                if (container->cont->currentFrame < 9)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < 13)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container->cont->currentFrame < 20)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < 24)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                        }
                        else if (direction == "up")
                        {
                            if (container->contMcs->currentFrame < 10)
                            {
                                container->contMcs->gotoAndStop(10);
                            }
                            if (container->cont->currentFrame < 25)
                            {
                                container->cont->gotoAndStop((container->cont->currentFrame + 1));
                                if (container->cont->x >= -1 && container->cont->x <= 1 && container->cont->y >= -1 && container->cont->y <= 1)
                                {
                                    container->cont->gotoAndStop(25);
                                }
                                if (container->cont->currentFrame < 9)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < 13)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container->cont->currentFrame < 20)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < 24)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                            else
                            {
                                if (container->cont->currentFrame < container->cont->totalFrames)
                                {
                                    container->cont->gotoAndStop((container->cont->currentFrame + 1));
                                }
                                else
                                {
                                    container->cont->gotoAndStop(25);
                                }
                                if (container->cont->currentFrame < 33)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < 37)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container->cont->currentFrame < 44)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < container->cont->totalFrames)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                        }
                        else if (direction == "down")
                        {
                            if (container->cont->currentFrame < 25)
                            {
                                container->cont->gotoAndStop((container->cont->currentFrame + 1));
                                if (container->cont->x >= -1 && container->cont->x <= 1 && container->cont->y >= -1 && container->cont->y <= 1)
                                {
                                    container->cont->gotoAndStop(25);
                                }
                                if (container->cont->currentFrame < 9)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < 13)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container->cont->currentFrame < 20)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < 24)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                            else
                            {
                                if (container->cont->currentFrame < container->cont->totalFrames)
                                {
                                    container->cont->gotoAndStop((container->cont->currentFrame + 1));
                                }
                                else
                                {
                                    container->cont->gotoAndStop(25);
                                }
                                if (container->cont->currentFrame < 33)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < 37)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container->cont->currentFrame < 44)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container->cont->currentFrame < container->cont->totalFrames)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                        }
                    }
                }
                else if (!teleportFlag)
                {
                    if (this->phase == 1)
                    {
                        if (container->contMcs->currentFrame >= 34 && container->contMcs->currentFrame <= 68)
                        {
                            if (this->alpha < 1)
                            {
                                this->alpha = this->alpha + 0.1;
                            }
                            else if (this->alpha != 1)
                            {
                                this->alpha = 1;
                            }
                            if (this->stealthCounter > 0)
                            {
                                this->stealthCounter --;
                                if (this->stealthCounter <= 5)
                                {
                                    if (container->dustAnima->alpha > 0)
                                    {
                                        container->dustAnima->alpha = container->dustAnima->alpha - 0.2;
                                    }
                                }
                            }
                            else
                            {
                                if (container->dustAnima->isVisible())
                                {
                                    container->dustAnima->setVisible(false);
                                    container->dustAnima->alpha = 0;
                                    i = 0;
                                    while (i < world->listOfIndexes0.size())
                                    { 
                                        if (world->listOfIndexes0[i] == this)
                                        {
                                            world->listOfIndexes0.splice(i, 1);
                                            break;
                                        }
                                        i++;
                                    }
                                    world->listOfIndexes1.push(this);
                                }
                                if (container->contMcs->currentFrame > 34)
                                {
                                    container->contMcs->gotoAndStop((container->contMcs->currentFrame - 1));
                                }
                                else
                                {
                                    i = 0;
                                    while (i < world->listOfClasses.size())
                                    { 
                                        if (world->listOfClasses[i] == this)
                                        {
                                            world->listOfClasses.splice(i, 1);
                                            break;
                                        }
                                        i++;
                                    }
                                    i = 0;
                                    while (i < world->listOfIndexes1.size())
                                    { 
                                        if (world->listOfIndexes1[i] == this)
                                        {
                                            world->listOfIndexes1.splice(i, 1);
                                            break;
                                        }
                                        i++;
                                    }
                                    world->listOfUnits.push(this);
                                    readyDamage = true;
                                    moveFlag = true; 
                                    this->mouseChildren = true;
                                    this->mouseEnabled = true;
                                    this->stealthCounter = this->stealthTimer;
                                    this->phase = 2;
                                }
                            }
                        }
                    }
                    else if (this->phase == 2)
                    {
                        if (container->contMcs->currentFrame >= 34 && container->contMcs->currentFrame <= 68)
                        {
                            if (container->contMcs->currentFrame < 68)
                            {
                                container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                            }
                            else if (!container->dustAnima->isVisible())
                            {
                                container->dustAnima->visible = true;
                                container->contMcs->gotoAndStop(1);
                            }
                        }
                        else if (container->contMcs->currentFrame >= 102 && container->contMcs->currentFrame <= 136)
                        {
                            if (container->contMcs->currentFrame < 136)
                            {
                                container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                            }
                            else if (!container->dustAnima->isVisible())
                            {
                                container->dustAnima->visible = true;
                                container->contMcs->gotoAndStop(69);
                            }
                        }
                        if (container->contMcs->currentFrame == 1 || container->contMcs->currentFrame == 69)
                        {
                            container->dustAnima->alpha = container->dustAnima->alpha + 0.2;
                            if (container->dustAnima->alpha > 1)
                            {
                                container->dustAnima->alpha = 1;
                                i = 0;
                                while (i < world->listOfIndexes0.size())
                                { 
                                    if (world->listOfIndexes0[i] == this)
                                    {
                                        world->listOfIndexes0.splice(i, 1);
                                        break;
                                    }
                                    i++;
                                }
                                i = 0;
                                while (i < world->listOfIndexes1.size())
                                { 
                                    if (world->listOfIndexes1[i] == this)
                                    {
                                        world->listOfIndexes1.splice(i, 1);
                                        break;
                                    }
                                    i++;
                                }
                                world->listOfIndexes0.push(this);
                                this->phase = 3;
                            }
                        }
                    }
                    else if (this->phase == 3)
                    {
                        if (container->contMcs->currentFrame == 1 || container->contMcs->currentFrame == 69)
                        {
                            if (this->stealthCounter > 0)
                            {
                                this->stealthCounter--;
                                if (this->stealthCounter <= 5)
                                {
                                    if (container->dustAnima->alpha > 0)
                                    {
                                        container->dustAnima->alpha = container->dustAnima->alpha - 0.2;
                                    }
                                }
                            }
                            else if (container->dustAnima->isVisible())
                            {
                                container->dustAnima->setVisible(false);
                                container->dustAnima->alpha = 0;
                                i = 0;
                                while (i < world->listOfIndexes0.size())
                                { 
                                    if (world->listOfIndexes0[i] == this)
                                    {
                                        world->listOfIndexes0.splice(i, 1);
                                        break;
                                    }
                                    i++;
                                }
                                world->listOfIndexes1.push(this);
                                this->phase = 4;
                            }
                        }
                    }
                    else if (this->phase == 4)
                    {
                        if (container->contMcs->currentFrame >= 1 && container->contMcs->currentFrame <= 33)
                        {
                            if (container->contMcs->currentFrame < 33)
                            {
                                container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                            }
                        }
                        else if (container->contMcs->currentFrame >= 69 && container->contMcs->currentFrame <= 101)
                        {
                            if (container->contMcs->currentFrame < 101)
                            {
                                container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                            }
                        }
                        if (container->contMcs->currentFrame == 33 || container->contMcs->currentFrame == 101)
                        {
                            i = 0;
                            while (i < world->listOfClasses.size())
                            { 
                                if (world->listOfClasses[i] == this)
                                {
                                    world->listOfClasses.splice(i, 1);
                                    break;
                                }
                                i++;
                            }
                            i = 0;
                            while (i < world->listOfIndexes1.size())
                            { 
                                if (world->listOfIndexes1[i] == this)
                                {
                                    world->listOfIndexes1.splice(i, 1);
                                    break;
                                }
                                i++;
                            }
                            world->listOfUnits.push(this);
                            container->healthBar->setVisible(true);
                            health = healthMax * this->returnHealth;
                            container->healthBar->cont->setScaleX((double)health / healthMax);
                            readyDamage = true;
                            moveFlag = true; 
                            this->mouseChildren = true;
                            this->mouseEnabled = true;
                            this->phase = 5;
                        }
                    }
                    if (container->dustAnima->isVisible())
                    {
                        if (container->dustAnima->currentFrame < container->dustAnima->totalFrames)
                        {
                            container->dustAnima->gotoAndStop((container->dustAnima->currentFrame + 1));
                        }
                        else
                        {
                            container->dustAnima->gotoAndStop(1);
                        }
                    }
                }
            }
            Unit::animationHandler();
            return;
        }// end function

        void Unit_30::kill()
        {
            if (this->phase < 5 && health <= 0)
            {
                if (readyDamage)
                {
                    //i = 0;
                    //while (i < world->listOfUnits.size())
                    //{ 
                    //    if (world->listOfUnits[i] == this)
                    //    {
                    //        world->listOfUnits.splice(i, 1);
                    //        break;
                    //    }
                    //    i++;
                    //}
                    //i = 0;
                    //while (i < world->listOfClasses.size())
                    //{ 
                    //    if (world->listOfClasses[i] == this)
                    //    {
                    //        world->listOfClasses.splice(i, 1);
                    //        break;
                    //    }
                    //    i++;
                    //}
                    //i = 0;
                    //while (i < world->listOfIndexes0.size())
                    //{ 
                    //    if (world->listOfIndexes0[i] == this)
                    //    {
                    //        world->listOfIndexes0.splice(i, 1);
                    //        break;
                    //    }
                    //    i++;
                    //}
                    //i = 0;
                    //while (i < world->listOfIndexes1.size())
                    //{ 
                    //    if (world->listOfIndexes1[i] == this)
                    //    {
                    //        world->listOfIndexes1.splice(i, 1);
                    //        break;
                    //    }
                    //    i++;
                    //}
                    stopAllEffects();
                    health = 0;
                    readyDamage = false;
                    moveFlag = false; 
                    this->mouseChildren = false;
                    this->mouseEnabled = false;
                    //world->listOfClasses.push(this);
                    //if (lastAttackType == "golem")
                    //{
                    //    world->listOfIndexes0.push(this);
                    //}
                    //else
                    //{
                    //    world->listOfIndexes1.push(this);
                    //}
                }
            }
            else
            {
                if (!dead)
                {
                    //i = 0;
                    //while (i < world->listOfClasses.size())
                    //{ 
                    //    if (world->listOfClasses[i] == this)
                    //    {
                    //        world->listOfClasses.splice(i, 1);
                    //        break;
                    //    }
                    //    i++;
                    //}
                    //i = 0;
                    //while (i < world->listOfIndexes0.size())
                    //{
                    //    
                    //    if (world->listOfIndexes0[i] == this)
                    //    {
                    //        world->listOfIndexes0.splice(i, 1);
                    //        break;
                    //    }
                    //    i++;
                    //}
                    //i = 0;
                    //while (i < world->listOfIndexes1.size())
                    //{
                    //    
                    //    if (world->listOfIndexes1[i] == this)
                    //    {
                    //        world->listOfIndexes1.splice(i, 1);
                    //        break;
                    //    }
                    //    i++;
                    //}
                }
                Unit::kill();
            }
            return;
        }// end function

    }
}
