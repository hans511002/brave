#include "CallDelay.h" 
#include "MainClass.h"
#include "engine/World.h"
 
namespace engine
{
     
     CallDelay::CallDelay(string param1,int param2):dead(0),counter(0)
    {
        this->world = Main::mainClass->worldClass;
        this->type = param1;
        this->type1 = param2;
        if (this->type == "newElement")
            this->counter = 60;
		BaseNode::init();
		this->world->addChild(this,2);
        this->world->addClasses(this);
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
				NewElement_mc * tempObject = new NewElement_mc();
                tempObject->stop();
                tempObject->newElementCase->stop();
                tempObject->type = this->type1;
                //tempObject->soundFlag = true;
                tempObject->newElementCase->setMouseEnabled(true);
                this->world->worldInterface->addChild(tempObject);
                this->world->worldInterface->listOfNewEnemies.push(tempObject);
                this->world->worldInterface->newEnemyUpdate();
                AudioUtil::playSoundWithVol("snd_world_newEnemy.mp3", 0.9f);
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
			this->world->removeChild(this);//this->world->removeClasses(this);
             
        }
        return;
    }// end function

}
