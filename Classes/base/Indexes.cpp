 
#include "Indexes.h"
#include "engine/World.h"

namespace engine
{
     
    Indexes::Indexes(MovieClip *param1, int param2, float param3) :speedX(0), speedY(0)
    {
        this->world = Main::mainClass->worldClass;
        this->container = param1;
        //this->container.stop();
        this->addChild(this->container);
        this->indexParam = param2;
        this->alphaParam = param3;
        if(this->indexParam == 0)
        {
            //this->world->listOfIndexes0.push(this);
        }
        else if(this->indexParam == 1)
        {
            //this->world->listOfIndexes1.push(this);
        }
        else if(this->indexParam == 2)
        {
            //this->world->listOfIndexes2.push(this);
        }
        else if(this->indexParam == 3)
        {
            //this->world->listOfIndexes3.push(this);
        }
        this->world->addChild(this);
        this->world->listOfClasses.push(this);
        this->setMouseChildren(false);
        this->setMouseEnabled(false);
        this->world->forseIndexFl = true;
    }// end function

    void Indexes::update(float dt)
    {
        if(this->container->currentFrame < this->container->totalFrames && this->container->getAlpha() > 0)
        {
            this->container->gotoAndStop((this->container->currentFrame + 1));
            this->container->setAlpha(this->container->getAlpha() - this->alphaParam);
            this->setPositionX(this->getPositionX() + this->speedX);
            this->setPositionY(this->getPositionY() + this->speedY); 
        }
        else
        {
            this->world->removeChild(this);
             
            //if(this->indexParam == 0)
            //{
            //    this->i = 0;
            //    while(this->i < this->world->listOfIndexes0.length)
            //    {
            //        if(this->world->listOfIndexes0[this->i] == this)
            //        {
            //            this->world->listOfIndexes0.splice(this->i, 1);
            //            break;
            //        }
            //        i++;
            //    }
            //}
            //else if(this->indexParam == 1)
            //{
            //    this->i = 0;
            //    while(this->i < this->world->listOfIndexes1.length)
            //    {
            //        if(this->world->listOfIndexes1[this->i] == this)
            //        {
            //            this->world->listOfIndexes1.splice(this->i, 1);
            //            break;
            //        }
            //        i++;
            //    }
            //}
            //else if(this->indexParam == 2)
            //{
            //    this->i = 0;
            //    while(this->i < this->world->listOfIndexes2.length)
            //    {
            //        if(this->world->listOfIndexes2[this->i] == this)
            //        {
            //            this->world->listOfIndexes2.splice(this->i, 1);
            //            break;
            //        }
            //        i++;
            //    }
            //}
            //else if(this->indexParam == 3)
            //{
            //    this->i = 0;
            //    while(this->i < this->world->listOfIndexes3.length)
            //    {
            //        if(this->world->listOfIndexes3[this->i] == this)
            //        {
            //            this->world->listOfIndexes3.splice(this->i, 1);
            //            break;
            //        }
            //        i++;
            //    }
            //}
        }
        return;
    }// end function


}
 
