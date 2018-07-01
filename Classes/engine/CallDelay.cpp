#include "CallDeplay.h" 
#include "MainClass.h"
#include "engine/World.h"
#include "engine/mc/mc.h"

namespace engine
{
     
     CallDelay::CallDelay(string param1,int param2)��dead(0),counter(0)
    {
        this->world = Main::mainClass->worldClass;
        this->type = param1;
        this->type1 = param2;
        if (this->type == "newElement")
        {
            this->counter = 60;
        }
        this->world.listOfClasses.push(this);
        return;
    }// end function

    void CallDelay::update(float dt)
    {
        if (this->counter > 0)
        {
            this->counter--;
        }
        else
        {
            if (this->type == "newElement")
            {
                if (this->type1 > 1 && this->type1 < 5)
                {
                    //this->tempObject = new Training_11(this->type1);
                    //this->world->worldInterface->addChild(this->tempObject);
                }
                this->tempObject = new NewElement_mc();
                this->tempObject->stop();
                this->tempObject->newElementCase->stop();
                this->tempObject->type = this->type1;
                //this->tempObject->soundFlag = true;
                this->tempObject->newElementCase->setMouseEnabled(true);
                this->world->worldInterface->addChild(this->tempObject);
                this->world->worldInterface->listOfNewEnemies->push(this->tempObject);
                this->world->worldInterface->newEnemyUpdate();
                //Sounds.instance.playSoundWithVol("snd_world_newEnemy", 0.9);
            }
            this->kill();
        }
        return;
    }// end function

    void CallDelay::kill()
    {
        if (!this->dead)
        {
            this->dead = true;
            this->i = 0;
            while (this->i < this->world.listOfClasses.length)
            {
                if (this->world.listOfClasses[this->i] == this)
                {
                    this->world.listOfClasses.splice(this->i, 1);
                    break;
                }
                i++;
            }
        }
        return;
    }// end function

}
