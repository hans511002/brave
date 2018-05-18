#ifndef SCREENS_DEFEAT_H
#define SCREENS_DEFEAT_H
#include "Defeat.h"   
#include "engine/World.h"   

using namespace engine;

namespace screens
{   
    DefMenu_mc::DefMenu_mc()
    {
    
    } ;
 

    Defeat::Defeat():frameCounter(0),openFlag(true),world(0),firstSoundPlay(false)
    {
        this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool Defeat::init() 
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        //Main::mainClass->stage.frameRate = 30;
        this->world = Main::mainClass->worldClass;
        this->world->manageListeners("off");
        this->world->worldInterface.breaking();
        int addit_levelsDefeatCounter=Main::mainClass->saveBoxClass->getIntValue("addit_levelsDefeatCounter",this->world->nowLevel - 1)+1;
        Main::mainClass->saveBoxClass->setValue("addit_levelsDefeatCounter",addit_levelsDefeatCounter);
        //(Main::mainClass->saveBoxClass.gameSave.data.addit_levelsDefeatCounter[(this->world->nowLevel - 1)] + 1);
        this->container = new DefMenu_mc();
        this->container->stop();
        this->container->first->stop();
        this->container->first->fire->stop();
        this->container->first->scroll->stop();
        this->container->first->scroll->btnContinue->stop();
        this->container->first->scroll->btnContinue->arrow->stop();
        this->container->first->scroll->btnRestart->stop();
        this->container->first->scroll->btnRestart->arrow->stop();
        this->container->first->scroll->btnContinue->continueCase->buttonMode = true;
        this->container->first->scroll->btnRestart->restartCase->buttonMode = true;
        this->container->first->mouseChildren = false;
        this->container->first->mouseEnabled = false;
        this->container->first->scroll->btnContinue->arrow->setVisible(false);
        this->container->first->scroll->btnRestart->arrow->setVisible(false);
        //this->container->first->scroll->btnY8->stop();
        //this->container->first->scroll->btnY8->y8Case->stop();
        //if (!Main::mainClass->IDIClass.isSponsor)
        //{
        //    this->container->first->scroll->btnY8->y8Case->buttonMode = true;
        //}
        this->container->first->forum->stop();
        this->container->first->forum.forumCase->stop();
        this->container->first->forum.forumCase->buttonMode = true;
        
        if (addit_levelsDefeatCounter >= 3)
        {
            this->container->first->forum->setVisible(true);
        }
        else
        {
            this->container->first->forum->setVisible(false);
        }
        this->addChild(this->container);
        if (this->world->nowLevel <= 5)
        {
            //Main::mainClass->tracker.trackPageview("defeatLevel_" + this->world->nowLevel);
        }
        return;
    }// end function

    void Defeat::enterFrameHandler(float dt)
    {
        if (this->frameCounter < 30)
        {
            this->frameCounter++;
        }
        else
        {
            this->frameCounter = 1;
        }
        if (!this->firstSoundPlay)
        {
            if (this->frameCounter < 10)
            {
                //if (Sounds.instance.musicChanel)
                //{
                //    if (Sounds.instance.musicChanel.soundTransform.volume > 0)
                //    {
                //        Sounds.instance.musicChanel.soundTransform = new SoundTransform(Sounds.instance.musicChanel.soundTransform.volume - 0.1, 0);
                //    }
                //    else if (Sounds.instance.musicChanel.soundTransform.volume != 0)
                //    {
                //        Sounds.instance.musicChanel.soundTransform = new SoundTransform(0, 0);
                //    }
                //}
            }
            else
            {
                this->firstSoundPlay = true;
                //Sounds.instance.stopAll();
                //Sounds.instance.playSound("snd_menu_defeat");
            }
        }
        if (this->openFlag)
        {
            if (this->container->currentFrame < this->container->totalFrames)
            {
                this->container->gotoAndStop((this->container->currentFrame + 1));
                this->container->first->gotoAndStop((this->container->first->currentFrame + 1));
            }
            else
            {
                this->openFlag = false; 
                this->container->first->mouseChildren = true;
                this->container->first->mouseEnabled = true;
                cocos2d::Point tempObject(this->mouseX, this->mouseY);
                tempObject1 = this->container->first->scroll->btnContinue->localToGlobal(this->container->first->scroll->btnContinue->continueCase->getPosition());
                if (tempObject.x > tempObject1.x - this->container->first->scroll->btnContinue->continueCase.width / 2 
                   && tempObject.x < tempObject1.x + this->container->first->scroll->btnContinue->continueCase.width / 2 
                   && tempObject.y > tempObject1.y - this->container->first->scroll->btnContinue->continueCase.height / 2 
                   && tempObject.y < tempObject1.y + this->container->first->scroll->btnContinue->continueCase.height / 2)
                {
                    this->container->first->scroll->btnContinue->gotoAndStop(2);
                }
                tempObject1 = this->container->first->scroll->btnRestart->localToGlobal(this->container->first->scroll->btnRestart->restartCase->getPosition());
                if (tempObject.x > tempObject1.x - this->container->first->scroll->btnRestart->restartCase.width / 2 
                   && tempObject.x < tempObject1.x + this->container->first->scroll->btnRestart->restartCase.width / 2 
                   && tempObject.y > tempObject1.y - this->container->first->scroll->btnRestart->restartCase.height / 2 
                   && tempObject.y < tempObject1.y + this->container->first->scroll->btnRestart->restartCase.height / 2)
                {
                    this->container->first->scroll->btnRestart->gotoAndStop(2);
                }
            }
            if (this->container->currentFrame > 8)
            {
                if (this->container->first->scroll->currentFrame < this->container->first->scroll->totalFrames)
                {
                    this->container->first->scroll->gotoAndStop((this->container->first->scroll->currentFrame + 1));
                    this->container->first->scroll->btnContinue->stop();
                    this->container->first->scroll->btnContinue->arrow->stop();
                    this->container->first->scroll->btnRestart->stop();
                    this->container->first->scroll->btnRestart->arrow->stop();
                    this->container->first->scroll->btnContinue->continueCase->buttonMode = true;
                    this->container->first->scroll->btnRestart->restartCase->buttonMode = true;
                    this->container->first->scroll->btnContinue->arrow->setVisible(false);
                    this->container->first->scroll->btnRestart->arrow->setVisible(false);
                }
            }
        }
        if (this->container->first->fire->currentFrame < this->container->first->fire->totalFrames)
        {
            this->container->first->fire->gotoAndStop((this->container->first->fire->currentFrame + 1));
        }
        else
        {
            this->container->first->fire->gotoAndStop(1);
        }
        if (this->container->first->scroll->btnContinue->currentFrame > 1)
        {
            if (!this->container->first->scroll->btnContinue->arrow->isVisible())
            {
                this->container->first->scroll->btnContinue->arrow->setVisible(true);
            }
            else if (this->container->first->scroll->btnContinue->arrow->currentFrame < this->container->first->scroll->btnContinue->arrow->totalFrames)
            {
                this->container->first->scroll->btnContinue->arrow->gotoAndStop((this->container->first->scroll->btnContinue->arrow->currentFrame + 1));
            }
        }
        else if (this->container->first->scroll->btnContinue->arrow->currentFrame > 1)
        {
            this->container->first->scroll->btnContinue->arrow->gotoAndStop((this->container->first->scroll->btnContinue->arrow->currentFrame - 1));
        }
        else if (this->container->first->scroll->btnContinue->arrow->isVisible())
        {
            this->container->first->scroll->btnContinue->arrow->setVisible(false);
        }
        if (this->container->first->scroll->btnRestart->currentFrame > 1)
        {
            if (!this->container->first->scroll->btnRestart->arrow->isVisible())
            {
                this->container->first->scroll->btnRestart->arrow->setVisible(true);
            }
            else if (this->container->first->scroll->btnRestart->arrow->currentFrame < this->container->first->scroll->btnRestart->arrow->totalFrames)
            {
                this->container->first->scroll->btnRestart->arrow->gotoAndStop((this->container->first->scroll->btnRestart->arrow->currentFrame + 1));
            }
        }
        else if (this->container->first->scroll->btnRestart->arrow->currentFrame > 1)
        {
            this->container->first->scroll->btnRestart->arrow->gotoAndStop((this->container->first->scroll->btnRestart->arrow->currentFrame - 1));
        }
        else if (this->container->first->scroll->btnRestart->arrow->isVisible())
        {
            this->container->first->scroll->btnRestart->arrow->setVisible(false);
        }
        return;
    }// end function

    void Defeat::mouseMoveHandler(cocos2d::Event * event) 
    {
        if (event->target->name == "continueCase")
        {
            if (this->container->first->scroll->btnContinue->currentFrame == 1)
            {
                this->container->first->scroll->btnContinue->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->first->scroll->btnContinue->currentFrame == 2)
        {
            this->container->first->scroll->btnContinue->gotoAndStop(1);
        }
        if (event->target->name == "restartCase")
        {
            if (this->container->first->scroll->btnRestart->currentFrame == 1)
            {
                this->container->first->scroll->btnRestart->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->first->scroll->btnRestart->currentFrame == 2)
        {
            this->container->first->scroll->btnRestart->gotoAndStop(1);
        }
        if (this->container->first->scroll->btnY8->y8Case->buttonMode)
        {
            if (event->target->name == "y8Case")
            {
                if (this->container->first->scroll->btnY8->currentFrame == 1)
                {
                    this->container->first->scroll->btnY8->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->first->scroll->btnY8->currentFrame == 2)
            {
                this->container->first->scroll->btnY8->gotoAndStop(1);
            }
        }
        if (event->target->name == "forumCase")
        {
            if (this->container->first->forum->currentFrame == 1)
            {
                this->container->first->forum->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->first->forum->currentFrame == 2)
        {
            this->container->first->forum->gotoAndStop(1);
        }
        return;
    }// end function

    void Defeat::mouseDownHandler(cocos2d::Event * event)
    {
        if (event->target->name == "continueCase")
        {
            if (this->container->first->scroll->btnContinue->currentFrame == 2)
            {
                this->container->first->scroll->btnContinue->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event->target->name == "restartCase")
        {
            if (this->container->first->scroll->btnRestart->currentFrame == 2)
            {
                this->container->first->scroll->btnRestart->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event->target->name == "y8Case")
        {
            if (this->container->first->scroll->btnY8->currentFrame == 2)
            {
                this->container->first->scroll->btnY8->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event->target->name == "forumCase")
        {
            if (this->container->first->forum->currentFrame == 2)
            {
                this->container->first->forum->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        return;
    }// end function

    void Defeat::mouseUpHandler(cocos2d::Event * event)
    {
        if (event->target->name == "continueCase")
        {
            if (this->container->first->scroll->btnContinue->currentFrame == 3)
            {
                this->container->first->scroll->btnContinue->gotoAndStop(2);
                Main::mainClass->addNewScreen("LevelsMenu");
                Main::mainClass->testingClass = NULL;
            }
        }
        else if (this->container->first->scroll->btnContinue->currentFrame == 3)
        {
            this->container->first->scroll->btnContinue->gotoAndStop(1);
        }
        if (event->target->name == "restartCase")
        {
            if (this->container->first->scroll->btnRestart->currentFrame == 3)
            {
                this->container->first->scroll->btnRestart->gotoAndStop(2);
                Main::mainClass->addNewScreen("World");
                Main::mainClass->testingClass = NULL;
            }
        }
        else if (this->container->first->scroll->btnRestart->currentFrame == 3)
        {
            this->container->first->scroll->btnRestart->gotoAndStop(1);
        }
        //if (event->target->name == "y8Case")
        //{
        //    if (this->container->first->scroll->btnY8->currentFrame == 3)
        //    {
        //        this->container->first->scroll->btnY8->gotoAndStop(2);
        //        navigateToURL(new URLRequest("http://www.y8.com/?utm_source=" + Main::mainClass->domainName + "&utm_medium=g_prelogo&utm_campaign=brave_heads"));
        //    }
        //}
        //else if (this->container->first->scroll->btnY8->currentFrame == 3)
        //{
        //    this->container->first->scroll->btnY8->gotoAndStop(1);
        //}
        if (event->target->name == "forumCase")
        {
            if (this->container->first->forum->currentFrame == 3)
            {
                this->container->first->forum->gotoAndStop(2);
                //navigateToURL(new URLRequest("https://forum.id.net/t/brave-heads-tower-defense/1372"));
            }
        }
        else if (this->container->first->forum->currentFrame == 3)
        {
            this->container->first->forum->gotoAndStop(1);
        }
        return;
    }// end function

    //void reInit() 
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    return;
    //}// end function
 
}
