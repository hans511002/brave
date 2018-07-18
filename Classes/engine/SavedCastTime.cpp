#include "SavedCastTime.h"
#include "engine/World.h" 
#include "engine/WorldInterface.h"



namespace engine
{

    SavedCastTime_mc::SavedCastTime_mc() :MovieClip("worldinterface/", "SavedCastTime_mc", "SavedCastTime_mc")
    {
		SET_NODETYPENAME();
		cont = this->createMovieClipSub("cont");
        contNoteTXT = cont->createText("noteTXT");
    }

    SavedCastTime::SavedCastTime(string param1, int param2)
    {
        //this->addEventListener(Event.ADDED_TO_STAGE,this->init);
        this->type = param1;
        this->savedFrames = param2;
    }// end function 

    bool SavedCastTime::init()
    {
		BaseNode::init();
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        this->world = Main::mainClass->worldClass;
        this->container = new SavedCastTime_mc();
        this->container->stop();
        float tempObject = std::round(this->savedFrames / 30);
        if (tempObject >= 10)
        {
            this->container->cont->gotoAndStop(1);
        }
        else
        {
            this->container->cont->gotoAndStop(2);
        }

       std::setText( this->container->contNoteTXT, Common::String("-" )+ tempObject);
        this->addChild(this->container);
        //this->world->listOfClasses.push(this);
        if (this->type == "golem")
        {
            this->setPositionX(this->world->worldInterface->container->butCastGolem->getPositionX());
            this->setPositionY(this->world->worldInterface->container->butCastGolem->getPositionY());
        }
        else if (this->type == "iceman")
        {
            this->setPositionX(this->world->worldInterface->container->butCastIceman->getPositionX());
            this->setPositionY(this->world->worldInterface->container->butCastIceman->getPositionY());
        }
        else if (this->type == "air")
        {
            this->setPositionX(this->world->worldInterface->container->butCastAir->getPositionX());
            this->setPositionY(this->world->worldInterface->container->butCastAir->getPositionY());
        }
        this->setPositionX(this->getPositionX() + 8);
        this->setMouseChildren(false);
        this->setMouseEnabled(false);
        return true;
    }// end function

    void SavedCastTime::update(float dt)
    {
        if (this->container->currentFrame < this->container->totalFrames)
        {
            this->container->gotoAndStop((this->container->currentFrame + 1));
        }
        else
        {
            this->kill();
        }
    }// end function
    void SavedCastTime::kill()
    {
        if (!this->dead)
        {
            this->dead = true;
            this->world->worldInterface->removeChild(this);
			this->world->removeClasses(this);
            //this->i = 0;
            //while (this->i <this->world->listOfClasses.size())
            //{
            //	if (this->world->listOfClasses[this->i] == this)
            //	{
            //		this->world->listOfClasses.splice(this->i, 1);
            //		break;
            //	}
            //	i++;
            //}
        }
    }// end function
}
