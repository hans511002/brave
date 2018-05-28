 
#include "FastPause.h" 
 
namespace screens
{
    FastPause_mc::FastPause_mc():MovieClip("screen/","FastPause_mc","FastPause_mc")
    {
    
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
            //        this->startMusicVolume = Sounds.instance.musicChanel.soundTransform.volume;
            //    }
            //    if (Sounds.instance.musicChanel.soundTransform.volume > this->startMusicVolume * 0.35)
            //    {
            //        Sounds.instance.musicChanel.soundTransform = new SoundTransform(Sounds.instance.musicChanel.soundTransform.volume - this->startMusicVolume * 0.035, 0);
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
            //    if (Sounds.instance.musicChanel.soundTransform.volume < this->startMusicVolume)
            //    {
            //        Sounds.instance.musicChanel.soundTransform = new SoundTransform(Sounds.instance.musicChanel.soundTransform.volume + this->startMusicVolume * 0.035, 0);
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
        //i = 0;
        //while (i < this->world->listOfClasses.size())
        //{
        //    
        //    if (this->world->listOfClasses[i] is Indexes)
        //    {
        //        if (this->world->listOfClasses[i].type == "golemDeath" || this->world->listOfClasses[i].type == "icemanDeath" || this->world->listOfClasses[i].type == "airDeath")
        //        {
        //            this->world->listOfClasses[i].update();
        //        }
        //    }
        //    i++;
        //}
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
            this->world->removeChild(this);
            this->world->menuObject = NULL;
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
    //        Sounds.instance.musicChanel.soundTransform = new SoundTransform(this->startMusicVolume, 0);
    //    }
    //    if (this->world->getSphere || this->world->cast)
    //    {
    //        this->world->manageMouse("hide");
    //    }
    //    return;
    //}// end function

}
