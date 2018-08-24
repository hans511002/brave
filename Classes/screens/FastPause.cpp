 
#include "FastPause.h" 
#include "engine/World.h" 
#include "MainClass.h" 
#include "engine/WorldInterface.h"

namespace screens
{
    FastPause_mc::FastPause_mc():MovieClip("screen/","FastPause_mc","FastPause_mc")
    {
		SET_NODETYPENAME();

    };
     
    FastPause::FastPause():openFlag(true),closeFlag(false),startMusicVolume(0),frameCounter(0)
	{
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool FastPause::init()
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //this->addEventListener(MouseEvent.CLICK, this->mouseClickHandler);
        //Main::mainClass->stage.frameRate = 30;
        BaseNode::init();
        this->world = Main::mainClass->worldClass;
        this->world->manageListeners("off");
        if (this->world->exchange)
        {
            this->world->worldInterface->breaking();
        }
        else if (this->world->getSphere || this->world->cast)
        {
            this->world->manageMouse("show");
        }
        this->container = new FastPause_mc();
        this->container->stop();
        this->addChild(this->container);
        return true;
    }// end function

    void FastPause::enterFrameHandler(float dt) 
    {
        if (this->frameCounter < 30)
        {
            this->frameCounter++;
        }
        else
        {
            this->frameCounter = 1;
        }
        if (this->openFlag)
        {
            //if (Sounds.instance.musicChanel)
            //{
            //    if (this->startMusicVolume == 0)
            //    {
            //        this->startMusicVolume = AudioUtil::getMusicVolume();
            //    }
            //    if (AudioUtil::getMusicVolume() > this->startMusicVolume * 0.35)
            //    {
            //       AudioUtil::setMusicVolume(AudioUtil::getMusicVolume()- this->startMusicVolume * 0.035);
            //    }
            //}
            if (this->container->currentFrame < this->container->totalFrames)
            {
                this->container->gotoAndStop((this->container->currentFrame + 1));
            }
            else
            {
                this->openFlag = false;
            }
        }
        else if (this->closeFlag)
        {
            //if (Sounds.instance.musicChanel)
            //{
            //    if (AudioUtil::getMusicVolume() < this->startMusicVolume)
            //    {
            //        AudioUtil::setMusicVolume(AudioUtil::getMusicVolume() + this->startMusicVolume * 0.035);
            //    }
            //}
            if (this->container->currentFrame > 1)
            {
                this->container->gotoAndStop((this->container->currentFrame - 1));
            }
            else
            {
                this->closeFlag = false;
                this->kill();
            }
        }
        int i = 0;
        while (i < this->world->listOfClasses.size())
        {
			if (ISTYPE(Indexes,this->world->listOfClasses[i] ))
            {
				Indexes * idx=ISTYPE(Indexes, this->world->listOfClasses[i]);
				if (idx->type == "golemDeath" || idx->type == "icemanDeath" || idx->type == "airDeath")
                {
					idx->update();
                }
            }
            i++;
        }
        return;
    }// end function

    void FastPause::mouseClickHandler(cocos2d::EventMouse * event)
    {
        if (!this->closeFlag)
        {
            this->closeFlag = true;
        }
        return;
    }// end function

    void FastPause::kill()
    {
        if (!this->dead)
        {
            this->dead = true;
            this->world->manageListeners("on");
            this->world->menuObject = NULL;
            this->world->removeChild(this);
        }
        return;
    }// end function

    //void reInit(event:Event) 
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.CLICK, this->mouseClickHandler);
    //    if (Sounds.instance.musicChanel)
    //    {
    //        AudioUtil::setMusicVolume(this->startMusicVolume);
    //    }
    //    if (this->world->getSphere || this->world->cast)
    //    {
    //        this->world->manageMouse("hide");
    //    }
    //    return;
    //}// end function

}
