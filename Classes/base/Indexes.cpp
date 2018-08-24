 
#include "Indexes.h"
#include "engine/World.h"

namespace engine
{
     
    Indexes::Indexes(MovieClip *param1, int param2, float param3) :speedX(0), speedY(0)
    {
        this->world = Main::mainClass->worldClass;
        this->container = param1;
        this->addChild(this->container);
        this->indexParam = param2;
        this->alphaParam = param3;
        this->world->addIndexes(this,indexParam); 
        this->world->addChild(this);
        this->world->addClasses(this);
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
             this->world->removeIndexes(this,indexParam); 
        }
        return;
    }// end function


}
 
