
#include "BonusMoney.h"
#include "engine/World.h"
#include "MainClass.h"

namespace engine
{
    BonusMoney_mc::BonusMoney_mc() :MovieClip("worldinterface/", "BonusMoney_mc", "BonusMoney_mc")
    {
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
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        this->container = new BonusMoney_mc();
        this->container->stop();
        this->container->cont->stop();
        this->container->contNoteTXT->setText(Common::String("+") + this->world->bonusMoney);
        this->container->setPosition(Main::SCREEN_WIDTH_HALF,Main::SCREEN_HEIGHT_HALF);
        this->addChild(this->container);
        this->mouseChildren = false;
        this->mouseEnabled = false;
        //this->world->listOfIndexes3.push(this);
        //this->world->listOfClasses.push(this);
        return true;
    }// end function

    void BonusMoney::update(float dt)
    {
        if (this->container->currentFrame < this->container->totalFrames)
        {
            this->container->gotoAndStop((this->container->currentFrame + 1));
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
            //this->i = 0;
            //while (this->i < this->world->listOfIndexes3.length)
            //{ 
            //    if (this->world->listOfIndexes3[this->i] == this)
            //    {
            //        this->world->listOfIndexes3.splice(this->i, 1);
            //        break;
            //    }
            //    i++;
            //}
            //this->i = 0;
            //while (this->i < this->world->listOfClasses.length)
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
