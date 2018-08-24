 
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
                AudioUtil::playSound("Snd_boss_death.mp3");
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
                AudioUtil::playSound("Snd_boss_speak.mp3");
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
				tempObject->setOnceMove(this->world);//
                //this->world->worldInterface->addChild(tempObject);
                //this->world->worldInterface->listOfAnimation.push(tempObject);
                AudioUtil::playSound("Snd_menu_upgrIconMouseDown.mp3");
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
				tempObject->setOnceMove(this->world);//һ�ϐԶ���
				//this->world->worldInterface->addChild(tempObject);
    //            this->world->worldInterface->listOfAnimation.push(tempObject);
                AudioUtil::playSound("Snd_menu_upgrIconMouseDown.mp3");
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
        }
        return;
    }// end function

} 
