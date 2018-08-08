 
#include "InTimer.h" 
#include "World.h"

namespace engine
{ 
    InTimer::InTimer(string param1):dead(false),counter(0)
    {
        this->world = Main::mainClass->worldClass;
        this->type = param1;
        this->world->addClasses(this);
		this->world->addChild(this);
		BaseNode::init();
        return;
    }// end function

    void InTimer::update(float dt)
    {
        if (this->type == "bossDeath")
        {
            if (this->counter < 183)
            {
                this->counter++;
            }
            else
            {
                //Sounds.instance.playSound("snd_boss_death");
                this->kill();
            }
        }
        else if (this->type == "bossSpeakInDeath")
        {
            if (this->counter < 44)
            {
                this->counter++;
            }
            else
            {
                //Sounds.instance.playSound("snd_boss_speak");
                this->kill();
            }
        }
        else if (this->type == "openIce")
        {
            if (this->counter < 30)
            {
                this->counter++;
            }
            else
            {
                this->world->worldInterface->container->iceSphere->setVisible(true); 
                //this->world->worldInterface->container->iceSphere->setScale(0);
				AnimUpgrade_mc * tempObject = new AnimUpgrade_mc();
                tempObject->stop();
                tempObject->setPosition(this->world->worldInterface->container->iceSphere->getPosition()); 
                tempObject->setMouseChildren(false);
                tempObject->setMouseEnabled(false);
				tempObject->setOnceMove(this->world);//一次性动画
                //this->world->worldInterface->addChild(tempObject);
                //this->world->worldInterface->listOfAnimation.push(tempObject);
                //Sounds.instance.playSound("snd_menu_upgrIconMouseDown");
                this->kill();
            }
        }
        else if (this->type == "openLevin")
        {
            if (this->counter < 30)
            {
                this->counter++;
            }
            else
            {
                this->world->worldInterface->container->levinSphere->setVisible(true); 
                //this->world->worldInterface->container->levinSphere->setScale(0);
				AnimUpgrade_mc * tempObject = new AnimUpgrade_mc();
                tempObject->stop();
                tempObject->setPosition(this->world->worldInterface->container->levinSphere->getPosition());
                tempObject->setMouseChildren(false);
                tempObject->setMouseEnabled(false);
				tempObject->setOnceMove(this->world);//一次性动画
				//this->world->worldInterface->addChild(tempObject);
    //            this->world->worldInterface->listOfAnimation.push(tempObject);
                //Sounds.instance.playSound("snd_menu_upgrIconMouseDown");
                if (Main::mainClass->saveBoxClass->getIntValue("saveNo") > 3)
                {
                    this->world->worldInterface->spheresBlockManage("unblockGetAll");
                    new CallDelay("newElement", 8);
                }
                this->kill();
            }
        }
        return;
    }// end function

    void InTimer::kill()
    {
        if (!this->dead)
        {
            this->dead = true;
			this->world->removeChild(this);
			//this->world->removeClasses(this);
            //this->i = 0;
            //while (this->i < this->world->listOfClasses.size())
            //{ 
            //    if (this->world->listOfClasses[this->i] == this)
            //    {
            //        this->world->listOfClasses.splice(this->i, 1);
            //        break;
            //    }
            //    i++;
            //}
        }
        return;
    }// end function

} 
