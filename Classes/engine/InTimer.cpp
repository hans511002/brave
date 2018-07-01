#ifndef ENGINE_INTIMER_H
#define ENGINE_INTIMER_H
#include "InTimer.h" 
#include "engine/World.h"

namespace engine
{ 
    InTimer::InTimer(string param1):dead(false),counter(0)
    {
        this->world = Main::mainClass->worldClass;
        this->type = param1;
        this->world->listOfClasses.push(this);
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
                this->world->worldInterface->container->iceSphere->setScale(0);
                this->tempObject = new AnimUpgrade_mc();
                this->tempObject->stop();
                this->tempObject->setPosition(this->world->worldInterface->container->iceSphere->getPosition()); 
                this->tempObject->setMouseChildren(false);
                this->tempObject->setMouseEnabled(false);
                this->world->worldInterface->addChild(this->tempObject);
                this->world->worldInterface->listOfAnimation->push(this->tempObject);
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
                this->world->worldInterface->container->levinSphere->setScale(0);
                this->tempObject = new AnimUpgrade_mc();
                this->tempObject->stop();
                this->tempObject->setPosition(this->world->worldInterface->container->levinSphere->getPosition());
                this->tempObject->setMouseChildren(false);
                this->tempObject->setMouseEnabled(false);
                this->world->worldInterface->addChild(this->tempObject);
                this->world->worldInterface->listOfAnimation->push(this->tempObject);
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
            this->i = 0;
            while (this->i < this->world->listOfClasses.length)
            { 
                if (this->world->listOfClasses[this->i] == this)
                {
                    this->world->listOfClasses.splice(this->i, 1);
                    break;
                }
                i++;
            }
        }
        return;
    }// end function

}
#endif
