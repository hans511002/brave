
#include "BonusMoney.h"
#include "engine/World.h"
#include "MainClass.h"
#include "engine/WorldInterface.h"

namespace engine
{
    BonusMoney_mc::BonusMoney_mc() :MovieClip("worldinterface/", "BonusMoney_mc", "BonusMoney_mc")
    {
		SET_NODETYPENAME();
		cont = this->createMovieClipSub("cont");
        contNoteTXT = cont->createText("noteTXT");
    };
 

    BonusMoney::BonusMoney():counter(0)
    {
        this->world = Main::mainClass->worldClass;
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool BonusMoney::init()
    {
		BaseNode::init();
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        this->container = new BonusMoney_mc();
        this->container->stop();
        this->container->cont->stop();
        this->container->contNoteTXT->setString(Common::String("+") + this->world->bonusMoney);
        this->container->setPosition(Main::LEVEL_MAP_WIDTH/2,Main::LEVEL_MAP_HEIGHT/2);
        this->addChild(this->container);
        this->setMouseChildren(false);
        this->setMouseEnabled(false);
        this->world->addIndexes(this,3);
        this->world->addClasses(this);
        return true;
    }// end function

    void BonusMoney::update(float dt)
    {
        if (this->container->currentFrame < this->container->totalFrames)
        {
            //this->container->gotoAndStop((this->container->currentFrame + 1));
            this->container->tryPlay();
            if (this->container->currentFrame == this->container->totalFrames)
            {
                this->world->money = this->world->money + this->world->bonusMoney;
                this->world->worldInterface->updateInfo();
            }
        }
        else if (this->counter < 30)
        {
            this->counter++;
        }
        else if (this->container->getAlpha() > 0)
        {
            this->container->setAlpha( this->container->getAlpha() - 0.2);
        }
        else
        {
            this->kill();
        }
        return;
    }// end function

    void BonusMoney::kill()
    {
        if (!this->dead)
        {
            this->dead = true;
            this->world->removeChild(this);
            this->world->removeIndexes(this,3); 
        }
        return;
    }// end function

}
