 
#include "PauseMenu.h"

namespace screens
{
    PauseMenu::PauseMenu():frameCounter(0),openFlag(true),questionFlag(0),startMusicVolume(0)
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool PauseMenu::init()
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        Main::mainClass->stage.frameRate = 30;
        this->world = Main::mainClass->worldClass;
        this->setPosition(Vec2(0,0)); 
        this->worldInterface->setPosition(Vec2(0,0)); 
        
        if (this->world->towerMenu)
        {
            this->world->towerMenu->closeMenu(true);
        }
        else if (this->world->ultraTowerMenu)
        {
            this->world->ultraTowerMenu->closeMenu(true);
        }
        this->world->manageListeners("off");
        if (this->world->exchange)
        {
            this->world->worldInterface->breaking();
        }
        else if (this->world->getSphere || this->world->cast)
        {
            this->world->manageMouse("show");
        }
        this->container = new PauseMenu_mc();
        this->container->stop();
        this->container->scroll->stop();
        this->container->scroll->btnMusic->stop();
        this->container->scroll->btnMusic->musicCase->stop();
        this->container->scroll->btnSound->stop();
        this->container->scroll->btnSound->soundCase->stop();
        this->container->scroll->btnLow->stop();
        this->container->scroll->btnLow->lowCase->stop();
        this->container->scroll->btnMedium->stop();
        this->container->scroll->btnMedium->mediumCase->stop();
        this->container->scroll->btnHigh->stop();
        this->container->scroll->btnHigh->highCase->stop();
        this->container->scroll->btnOn->stop();
        this->container->scroll->btnOn->onCase->stop();
        this->container->scroll->btnOff->stop();
        this->container->scroll->btnOff->offCase->stop();
        this->container->scroll->btnResume->stop();
        this->container->scroll->btnResume->arrow->stop();
        this->container->scroll->btnResume->resumeCase->stop();
        this->container->scroll->btnRestart->stop();
        this->container->scroll->btnRestart->arrow->stop();
        this->container->scroll->btnRestart->restartCase->stop();
        this->container->scroll->btnExit->stop();
        this->container->scroll->btnExit->arrow->stop();
        this->container->scroll->btnExit->exitCase->stop();
        this->container->scroll->btnMusic->musicCase->buttonMode = true;
        this->container->scroll->btnSound->soundCase->buttonMode = true;
        this->container->scroll->btnLow->lowCase->buttonMode = true;
        this->container->scroll->btnMedium->mediumCase->buttonMode = true;
        this->container->scroll->btnHigh->highCase->buttonMode = true;
        this->container->scroll->btnOn->onCase->buttonMode = true;
        this->container->scroll->btnOff->offCase->buttonMode = true;
        this->container->scroll->btnResume->resumeCase->buttonMode = true;
        this->container->scroll->btnRestart->restartCase->buttonMode = true;
        this->container->scroll->btnExit->exitCase->buttonMode = true; 
        this->container->scroll->mouseChildren = false;
        this->container->scroll->mouseEnabled = false;
        this->container->scroll->btnResume->arrow->setVisible(false);
        this->container->scroll->btnRestart->arrow->setVisible(false);
        this->container->scroll->btnExit->arrow->setVisible(false);
        this->container->scroll->btnY8->stop();
        this->container->scroll->btnY8->y8Case->stop();
        if (!Main::mainClass->IDIClass.isSponsor)
        {
            this->container->scroll->btnY8->y8Case->buttonMode = true;
        }
        this->addChild(this->container);
        //if (!//Sounds.instance.musicOn)
        //{
        //    this->container->scroll->btnMusic->gotoAndStop(4);
        //}
        //if (!//Sounds.instance.soundOn)
        //{
        //    this->container->scroll->btnSound->gotoAndStop(4);
        //}
        //if (Main::mainClass->saveBoxClass.gameSave.data.quality == "low")
        //{
        //    this->container->scroll->btnLow->gotoAndStop(4);
        //    this->container->scroll->btnLow->lowCase->buttonMode = false;
        //}
        //else if (Main::mainClass->saveBoxClass.gameSave.data.quality == "medium")
        //{
        //    this->container->scroll->btnMedium->gotoAndStop(4);
        //    this->container->scroll->btnMedium->mediumCase->buttonMode = false;
        //}
        //else if (Main::mainClass->saveBoxClass.gameSave.data.quality == "high")
        //{
        //    this->container->scroll->btnHigh->gotoAndStop(4);
        //    this->container->scroll->btnHigh->highCase->buttonMode = false;
        //}
        if (Main::mainClass->saveBoxClass->getBoolValue("autoPause"))
        {
            this->container->scroll->btnOn->gotoAndStop(4);
            this->container->scroll->btnOn->onCase->buttonMode = false;
        }
        else
        {
            this->container->scroll->btnOff->gotoAndStop(4);
            this->container->scroll->btnOff->offCase->buttonMode = false;
        }
        return;
    }// end function

    void PauseMenu::enterFrameHandler(cocos2d::Event * event)
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
            //if (//Sounds.instance.musicChanel)
            //{
            //    if (this->startMusicVolume == 0)
            //    {
            //        this->startMusicVolume = //Sounds.instance.musicChanel.soundTransform.volume;
            //    }
            //    if (//Sounds.instance.musicChanel.soundTransform.volume > this->startMusicVolume * 0.35)
            //    {
            //        //Sounds.instance.musicChanel.soundTransform = new SoundTransform(//Sounds.instance.musicChanel.soundTransform.volume - this->startMusicVolume * 0.035, 0);
            //    }
            //}
            if (this->container->currentFrame < this->container->totalFrames)
            {
                this->container->gotoAndStop((this->container->currentFrame + 1));
            }
            if (this->container->scroll->currentFrame < 24)
            {
                this->container->scroll->gotoAndStop((this->container->scroll->currentFrame + 1));
            }
            if (this->container->currentFrame == this->container->totalFrames)
            {
                if (this->container->scroll->currentFrame == 18)
                { 
                    this->container->scroll->mouseChildren = true;
                    this->container->scroll->mouseEnabled = true;
                    this->autoguidersButtons();
                }
                else if (this->container->scroll->currentFrame == 24)
                {
                    this->openFlag = false;
                    this->autoguidersButtons();
                }
            }
        }
        else if (this->closeFlag)
        {
            //if (//Sounds.instance.musicChanel)
            //{
            //    if (//Sounds.instance.musicChanel.soundTransform.volume < this->startMusicVolume)
            //    {
            //        //Sounds.instance.musicChanel.soundTransform = new SoundTransform(//Sounds.instance.musicChanel.soundTransform.volume + this->startMusicVolume * 0.035, 0);
            //    }
            //}
            if (this->container->scroll->currentFrame > 1)
            {
                this->container->scroll->gotoAndStop((this->container->scroll->currentFrame - 1));
            }
            if (this->container->scroll->currentFrame < 9)
            {
                this->container->gotoAndStop((this->container->currentFrame - 1));
            }
            if (this->container->currentFrame == 1 && this->container->scroll->currentFrame == 1)
            {
                this->closeFlag = false;
                this->world->manageListeners("on");
                this->world->removeChild(this);
                this->world->menuObject = NULL;
            }
        }
        if (this->questionFlag == 0)
        {
            if (this->container->scroll->currentFrame > 24)
            {
                this->container->scroll->gotoAndStop((this->container->scroll->currentFrame - 1));
                if (this->container->scroll->currentFrame == 25)
                {
                    this->container->scroll->btnMusic->alpha = 1;
                    this->container->scroll->btnSound->alpha = 1;
                    this->container->scroll->btnLow.alpha = 1;
                    this->container->scroll->btnMedium->alpha = 1;
                    this->container->scroll->btnHigh->alpha = 1;
                    this->container->scroll->btnOn->alpha = 1;
                    this->container->scroll->btnOff->alpha = 1;
                    this->container->scroll->btnResume->alpha = 1;
                    this->container->scroll->btnRestart->alpha = 1;
                    this->container->scroll->btnExit->alpha = 1;
                    this->container->scroll->qualityTXT.alpha = 1;
                    this->container->scroll->autopauseTXT.alpha = 1; 
                    this->container->scroll->btnMusic->mouseChildren = true;
                    this->container->scroll->btnMusic->mouseEnabled = true; 
                    this->container->scroll->btnSound->mouseChildren = true;
                    this->container->scroll->btnSound->mouseEnabled = true; 
                    this->container->scroll->btnLow->mouseChildren = true;
                    this->container->scroll->btnLow->mouseEnabled = true; 
                    this->container->scroll->btnMedium->mouseChildren = true;
                    this->container->scroll->btnMedium->mouseEnabled = true; 
                    this->container->scroll->btnHigh->mouseChildren = true;
                    this->container->scroll->btnHigh->mouseEnabled = true; 
                    this->container->scroll->btnOn->mouseChildren = true;
                    this->container->scroll->btnOn->mouseEnabled = true; 
                    this->container->scroll->btnOff->mouseChildren = true;
                    this->container->scroll->btnOff->mouseEnabled = true; 
                    this->container->scroll->btnResume->mouseChildren = true;
                    this->container->scroll->btnResume->mouseEnabled = true; 
                    this->container->scroll->btnRestart->mouseChildren = true;
                    this->container->scroll->btnRestart->mouseEnabled = true; 
                    this->container->scroll->btnExit->mouseChildren = true;
                    this->container->scroll->btnExit->mouseEnabled = true;
                    this->autoguidersButtons();
                }
            }
        }
        else if (this->questionFlag > 0)
        {
            if (this->container->scroll->currentFrame < this->container->scroll->totalFrames)
            {
                this->container->scroll->gotoAndStop((this->container->scroll->currentFrame + 1));
                if (this->container->scroll->currentFrame == 25)
                {
                    this->container->scroll->question->stop();
                    this->container->scroll->question->btnYes->stop();
                    this->container->scroll->question->btnNo->stop();
                    this->container->scroll->question->btnYes->yesCase->buttonMode = true;
                    this->container->scroll->question->btnNo->noCase->buttonMode = true; 
                    this->container->scroll->question->mouseChildren = false;
                    this->container->scroll->question->mouseEnabled = false;
                }
            }
            else if (this->container->scroll->question->currentFrame < this->container->scroll->question->totalFrames)
            {
                this->container->scroll->question->gotoAndStop((this->container->scroll->question->currentFrame + 1));
                if (this->container->scroll->question->currentFrame == this->container->scroll->question->totalFrames)
                { 
                    this->container->scroll->question->mouseChildren = true;
                    this->container->scroll->question->mouseEnabled = true;;
                    this->autoguidersButtons();
                }
            }
        }
        if (this->container->scroll->btnResume->arrow->isVisible())
        {
            if (this->container->scroll->btnResume->currentFrame > 1)
            {
                if (this->container->scroll->btnResume->arrow->currentFrame < this->container->scroll->btnResume->arrow->totalFrames)
                {
                    this->container->scroll->btnResume->arrow->gotoAndStop((this->container->scroll->btnResume->arrow->currentFrame + 1));
                }
            }
            else if (this->container->scroll->btnResume->arrow->currentFrame > 1)
            {
                if (this->container->scroll->btnResume->mouseEnabled)
                {
                    this->container->scroll->btnResume->arrow->gotoAndStop((this->container->scroll->btnResume->arrow->currentFrame - 1));
                }
                else if (this->container->scroll->btnResume->arrow->currentFrame != this->container->scroll->btnResume->arrow->totalFrames)
                {
                    this->container->scroll->btnResume->arrow->gotoAndStop(this->container->scroll->btnResume->arrow->totalFrames);
                }
            }
            else
            {
                this->container->scroll->btnResume->arrow->setVisible(false);
            }
        }
        if (this->container->scroll->btnRestart->arrow->isVisible())
        {
            if (this->container->scroll->btnRestart->currentFrame > 1)
            {
                if (this->container->scroll->btnRestart->arrow->currentFrame < this->container->scroll->btnRestart->arrow->totalFrames)
                {
                    this->container->scroll->btnRestart->arrow->gotoAndStop((this->container->scroll->btnRestart->arrow->currentFrame + 1));
                }
            }
            else if (this->container->scroll->btnRestart->arrow->currentFrame > 1)
            {
                if (this->container->scroll->btnRestart->mouseEnabled)
                {
                    this->container->scroll->btnRestart->arrow->gotoAndStop((this->container->scroll->btnRestart->arrow->currentFrame - 1));
                }
                else if (this->container->scroll->btnRestart->arrow->currentFrame != this->container->scroll->btnRestart->arrow->totalFrames)
                {
                    this->container->scroll->btnRestart->arrow->gotoAndStop(this->container->scroll->btnRestart->arrow->totalFrames);
                }
            }
            else
            {
                this->container->scroll->btnRestart->arrow->setVisible(false);
            }
        }
        if (this->container->scroll->btnExit->arrow->isVisible())
        {
            if (this->container->scroll->btnExit->currentFrame > 1)
            {
                if (this->container->scroll->btnExit->arrow->currentFrame < this->container->scroll->btnExit->arrow->totalFrames)
                {
                    this->container->scroll->btnExit->arrow->gotoAndStop((this->container->scroll->btnExit->arrow->currentFrame + 1));
                }
            }
            else if (this->container->scroll->btnExit->arrow->currentFrame > 1)
            {
                if (this->container->scroll->btnExit->mouseEnabled)
                {
                    this->container->scroll->btnExit->arrow->gotoAndStop((this->container->scroll->btnExit->arrow->currentFrame - 1));
                }
                else if (this->container->scroll->btnExit->arrow->currentFrame != this->container->scroll->btnExit->arrow->totalFrames)
                {
                    this->container->scroll->btnExit->arrow->gotoAndStop(this->container->scroll->btnExit->arrow->totalFrames);
                }
            }
            else
            {
                this->container->scroll->btnExit->arrow->setVisible(false);
            }
        }
        //this->i = 0;
        //while (this->i < this->world->listOfClasses.size())
        //{ 
        //    if (this->world->listOfClasses[this->i] is Indexes)
        //    {
        //        if (this->world->listOfClasses[this->i]->type == "golemDeath" || this->world->listOfClasses[this->i]->type == "icemanDeath" || this->world->listOfClasses[this->i]->type == "airDeath")
        //        {
        //            this->world->listOfClasses[this->i]->update();
        //        }
        //    }
        //    i++;
        //}
        return;
    }// end function

    void PauseMenu::mouseMoveHandler(cocos2d::Event *param1)  
    {
        if (this->questionFlag == 0)
        {
            if (param1->target->name == "musicCase")
            {
                if (this->container->scroll->btnMusic->currentFrame == 1 || this->container->scroll->btnMusic->currentFrame == 4)
                {
                    this->container->scroll->btnMusic->gotoAndStop((this->container->scroll->btnMusic->currentFrame + 1));
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->scroll->btnMusic->currentFrame == 2 || this->container->scroll->btnMusic->currentFrame == 5)
            {
                this->container->scroll->btnMusic->gotoAndStop((this->container->scroll->btnMusic->currentFrame - 1));
            }
            if (param1->target->name == "soundCase")
            {
                if (this->container->scroll->btnSound->currentFrame == 1 || this->container->scroll->btnSound->currentFrame == 4)
                {
                    this->container->scroll->btnSound->gotoAndStop((this->container->scroll->btnSound->currentFrame + 1));
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->scroll->btnSound->currentFrame == 2 || this->container->scroll->btnSound->currentFrame == 5)
            {
                this->container->scroll->btnSound->gotoAndStop((this->container->scroll->btnSound->currentFrame - 1));
            }
            if (param1->target->name == "lowCase")
            {
                if (this->container->scroll->btnLow->currentFrame == 1)
                {
                    this->container->scroll->btnLow->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->scroll->btnLow->currentFrame == 2)
            {
                if (Main::mainClass->saveBoxClass->getString("quality") != "low")
                {
                    this->container->scroll->btnLow->gotoAndStop(1);
                }
                else
                {
                    this->container->scroll->btnLow->gotoAndStop(4);
                }
            }
            if (param1->target->name == "mediumCase")
            {
                if (this->container->scroll->btnMedium->currentFrame == 1)
                {
                    this->container->scroll->btnMedium->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->scroll->btnMedium->currentFrame == 2)
            {
                if (Main::mainClass->saveBoxClass->getString("quality") != "medium")
                {
                    this->container->scroll->btnMedium->gotoAndStop(1);
                }
                else
                {
                    this->container->scroll->btnMedium->gotoAndStop(4);
                }
            }
            if (param1->target->name == "highCase")
            {
                if (this->container->scroll->btnHigh->currentFrame == 1)
                {
                    this->container->scroll->btnHigh->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->scroll->btnHigh->currentFrame == 2)
            {
                if (Main::mainClass->saveBoxClass->getString("quality") != "high")
                {
                    this->container->scroll->btnHigh->gotoAndStop(1);
                }
                else
                {
                    this->container->scroll->btnHigh->gotoAndStop(4);
                }
            }
            if (param1->target->name == "onCase")
            {
                if (this->container->scroll->btnOn->currentFrame == 1)
                {
                    this->container->scroll->btnOn->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->scroll->btnOn->currentFrame == 2)
            {
                this->container->scroll->btnOn->gotoAndStop(1);
            }
            if (param1->target->name == "offCase")
            {
                if (this->container->scroll->btnOff->currentFrame == 1)
                {
                    this->container->scroll->btnOff->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->scroll->btnOff->currentFrame == 2)
            {
                this->container->scroll->btnOff->gotoAndStop(1);
            }
            if (param1->target->name == "resumeCase")
            {
                if (this->container->scroll->btnResume->currentFrame == 1)
                {
                    this->container->scroll->btnResume->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    if (!this->container->scroll->btnResume->arrow->isVisible())
                    {
                        this->container->scroll->btnResume->arrow->visible(true);
                    }
                }
            }
            else if (this->container->scroll->btnResume->currentFrame == 2)
            {
                this->container->scroll->btnResume->gotoAndStop(1);
            }
            if (param1->target->name == "restartCase")
            {
                if (this->container->scroll->btnRestart->currentFrame == 1)
                {
                    this->container->scroll->btnRestart->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    if (!this->container->scroll->btnRestart->arrow->isVisible())
                    {
                        this->container->scroll->btnRestart->arrow->visible(true);
                    }
                }
            }
            else if (this->container->scroll->btnRestart->currentFrame == 2)
            {
                this->container->scroll->btnRestart->gotoAndStop(1);
            }
            if (param1->target->name == "exitCase")
            {
                if (this->container->scroll->btnExit->currentFrame == 1)
                {
                    this->container->scroll->btnExit->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    if (!this->container->scroll->btnExit->arrow->isVisible())
                    {
                        this->container->scroll->btnExit->arrow->visible(true);
                    }
                }
            }
            else if (this->container->scroll->btnExit->currentFrame == 2)
            {
                this->container->scroll->btnExit->gotoAndStop(1);
            }
            if (this->container->scroll->btnY8->y8Case->buttonMode)
            {
                if (param1->target->name == "y8Case")
                {
                    if (this->container->scroll->btnY8->currentFrame == 1)
                    {
                        this->container->scroll->btnY8->gotoAndStop(2);
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this->container->scroll->btnY8->currentFrame == 2)
                {
                    this->container->scroll->btnY8->gotoAndStop(1);
                }
            }
        }
        else
        {
            if (param1->target->name == "yesCase")
            {
                if (this->container->scroll->question->btnYes->currentFrame == 1)
                {
                    this->container->scroll->question->btnYes->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->scroll->question)
            {
                if (this->container->scroll->question->btnYes->currentFrame == 2)
                {
                    this->container->scroll->question->btnYes->gotoAndStop(1);
                }
            }
            if (param1->target->name == "noCase")
            {
                if (this->container->scroll->question->btnNo->currentFrame == 1)
                {
                    this->container->scroll->question->btnNo->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->scroll->question)
            {
                if (this->container->scroll->question->btnNo->currentFrame == 2)
                {
                    this->container->scroll->question->btnNo->gotoAndStop(1);
                }
            }
        }
        return;
    }// end function

    void PauseMenu::mouseDownHandler(cocos2d::Event *event) 
    {
        if (this->questionFlag == 0)
        {
            if (event.target.name == "musicCase")
            {
                if (this->container->scroll->btnMusic->currentFrame == 2 || this->container->scroll->btnMusic->currentFrame == 5)
                {
                    this->container->scroll->btnMusic->gotoAndStop((this->container->scroll->btnMusic->currentFrame + 1));
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "soundCase")
            {
                if (this->container->scroll->btnSound->currentFrame == 2 || this->container->scroll->btnSound->currentFrame == 5)
                {
                    this->container->scroll->btnSound->gotoAndStop((this->container->scroll->btnSound->currentFrame + 1));
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "lowCase")
            {
                if (this->container->scroll->btnLow->currentFrame == 2)
                {
                    this->container->scroll->btnLow->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "mediumCase")
            {
                if (this->container->scroll->btnMedium->currentFrame == 2)
                {
                    this->container->scroll->btnMedium->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "highCase")
            {
                if (this->container->scroll->btnHigh->currentFrame == 2)
                {
                    this->container->scroll->btnHigh->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "onCase")
            {
                if (this->container->scroll->btnOn->currentFrame == 2)
                {
                    this->container->scroll->btnOn->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "offCase")
            {
                if (this->container->scroll->btnOff->currentFrame == 2)
                {
                    this->container->scroll->btnOff->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "resumeCase")
            {
                if (this->container->scroll->btnResume->currentFrame == 2)
                {
                    this->container->scroll->btnResume->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "restartCase")
            {
                if (this->container->scroll->btnRestart->currentFrame == 2)
                {
                    this->container->scroll->btnRestart->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "exitCase")
            {
                if (this->container->scroll->btnExit->currentFrame == 2)
                {
                    this->container->scroll->btnExit->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "y8Case")
            {
                if (this->container->scroll->btnY8->currentFrame == 2)
                {
                    this->container->scroll->btnY8->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
        }
        else if (event.target.name == "yesCase")
        {
            if (this->container->scroll->question->btnYes->currentFrame == 2)
            {
                this->container->scroll->question->btnYes->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event.target.name == "noCase")
        {
            if (this->container->scroll->question->btnNo->currentFrame == 2)
            {
                this->container->scroll->question->btnNo->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        return;
    }// end function

    void PauseMenu::mouseUpHandler(cocos2d::Event * event) 
    {
        if (this->questionFlag == 0)
        {
            if (event.target.name == "musicCase")
            {
                if (this->container->scroll->btnMusic->currentFrame == 3)
                {
                    this->container->scroll->btnMusic->gotoAndStop(5);
                    //Sounds.instance.musicPausePosition = //Sounds.instance.musicChanel.position;
                    //Sounds.instance.musicManage("off");
                }
                else if (this->container->scroll->btnMusic->currentFrame == 6)
                {
                    this->container->scroll->btnMusic->gotoAndStop(2);
                    //Sounds.instance.musicManage("on");
                    if (this->world->wavesClass.nowWave == 0)
                    {
                        //Sounds.instance.playMusic(1);
                    }
                    else
                    {
                        //Sounds.instance.playMusic(2);
                    }
                }
            }
            else if (this->container->scroll->btnMusic->currentFrame == 3 || this->container->scroll->btnMusic->currentFrame == 6)
            {
                this->container->scroll->btnMusic->gotoAndStop(this->container->scroll->btnMusic->currentFrame - 2);
            }
            if (event.target.name == "soundCase")
            {
                if (this->container->scroll->btnSound->currentFrame == 3)
                {
                    this->container->scroll->btnSound->gotoAndStop(5);
                    //Sounds.instance.soundManage("off");
                }
                else if (this->container->scroll->btnSound->currentFrame == 6)
                {
                    this->container->scroll->btnSound->gotoAndStop(2);
                    //Sounds.instance.soundManage("on");
                }
            }
            else if (this->container->scroll->btnSound->currentFrame == 3 || this->container->scroll->btnSound->currentFrame == 6)
            {
                this->container->scroll->btnSound->gotoAndStop(this->container->scroll->btnSound->currentFrame - 2);
            }
            if (event.target.name == "lowCase")
            {
                if (this->container->scroll->btnLow->currentFrame == 3)
                { 
                    this->world->stage.quality = "low";
                    Main::mainClass->saveBoxClass->setValue(quality , "low");
                    this->container->scroll->btnLow->gotoAndStop(4);
                    this->container->scroll->btnLow->lowCase->buttonMode = false;
                    if (this->container->scroll->btnMedium->currentFrame != 1)
                    {
                        this->container->scroll->btnMedium->gotoAndStop(1);
                        this->container->scroll->btnMedium->mediumCase->buttonMode = true;
                    }
                    if (this->container->scroll->btnHigh->currentFrame != 1)
                    {
                        this->container->scroll->btnHigh->gotoAndStop(1);
                        this->container->scroll->btnHigh->highCase->buttonMode = true;
                    }
                }
            }
            else if (this->container->scroll->btnLow->currentFrame == 3)
            {
                this->container->scroll->btnLow->gotoAndStop(1);
            }
            if (event.target.name == "mediumCase")
            {
                if (this->container->scroll->btnMedium->currentFrame == 3)
                { 
                    this->world->stage.quality = "medium";
                    Main::mainClass->saveBoxClass->setValue(quality , "medium"); 
                    this->container->scroll->btnMedium->gotoAndStop(4);
                    this->container->scroll->btnMedium->mediumCase->buttonMode = false;
                    if (this->container->scroll->btnLow->currentFrame != 1)
                    {
                        this->container->scroll->btnLow->gotoAndStop(1);
                        this->container->scroll->btnLow->lowCase->buttonMode = true;
                    }
                    if (this->container->scroll->btnHigh->currentFrame != 1)
                    {
                        this->container->scroll->btnHigh->gotoAndStop(1);
                        this->container->scroll->btnHigh->highCase->buttonMode = true;
                    }
                }
            }
            else if (this->container->scroll->btnMedium->currentFrame == 3)
            {
                this->container->scroll->btnMedium->gotoAndStop(1);
            }
            if (event.target.name == "highCase")
            {
                if (this->container->scroll->btnHigh->currentFrame == 3)
                { 
                    this->world->stage.quality = "high";
                    Main::mainClass->saveBoxClass->setValue(quality , "high"); ;
                    this->container->scroll->btnHigh->gotoAndStop(4);
                    this->container->scroll->btnHigh->highCase->buttonMode = false;
                    if (this->container->scroll->btnLow->currentFrame != 1)
                    {
                        this->container->scroll->btnLow->gotoAndStop(1);
                        this->container->scroll->btnLow->lowCase->buttonMode = true;
                    }
                    if (this->container->scroll->btnMedium->currentFrame != 1)
                    {
                        this->container->scroll->btnMedium->gotoAndStop(1);
                        this->container->scroll->btnMedium->mediumCase->buttonMode = true;
                    }
                }
            }
            else if (this->container->scroll->btnHigh->currentFrame == 3)
            {
                this->container->scroll->btnHigh->gotoAndStop(1);
            }
            if (event.target.name == "onCase")
            {
                if (this->container->scroll->btnOn->currentFrame == 3)
                {
                    this->container->scroll->btnOn->gotoAndStop(4);
                    this->container->scroll->btnOn->onCase->buttonMode = false;
                    this->container->scroll->btnOff->gotoAndStop(1);
                    this->container->scroll->btnOff->offCase->buttonMode = true;
                    Main::mainClass->saveBoxClass->setValue("autoPause",true);
                }
            }
            else if (this->container->scroll->btnOn->currentFrame == 3)
            {
                this->container->scroll->btnOn->gotoAndStop(1);
            }
            if (event.target.name == "offCase")
            {
                if (this->container->scroll->btnOff->currentFrame == 3)
                {
                    this->container->scroll->btnOff->gotoAndStop(4);
                    this->container->scroll->btnOff->offCase->buttonMode = false;
                    this->container->scroll->btnOn->gotoAndStop(1);
                    this->container->scroll->btnOn->onCase->buttonMode = true;
                    Main::mainClass->saveBoxClass->setValue("autoPause",false);
                }
            }
            else if (this->container->scroll->btnOff->currentFrame == 3)
            {
                this->container->scroll->btnOff->gotoAndStop(1);
            }
            if (event.target.name == "resumeCase")
            {
                if (this->container->scroll->btnResume->currentFrame == 3)
                {
                    this->close();
                }
            }
            else if (this->container->scroll->btnResume->currentFrame == 3)
            {
                this->container->scroll->btnResume->gotoAndStop(1);
            }
            if (event.target.name == "restartCase")
            {
                if (this->container->scroll->btnRestart->currentFrame == 3)
                {
                    this->container->scroll->btnRestart->gotoAndStop(1);
                    this->questionFlag = 1;
                    this->container->scroll->btnMusic->alpha = 0.5;
                    this->container->scroll->btnSound->alpha = 0.5;
                    this->container->scroll->btnLow.alpha = 0.5;
                    this->container->scroll->btnMedium->alpha = 0.5;
                    this->container->scroll->btnHigh->alpha = 0.5;
                    this->container->scroll->btnOn->alpha = 0.5;
                    this->container->scroll->btnOff->alpha = 0.5;
                    this->container->scroll->btnResume->alpha = 0.5;
                    this->container->scroll->btnRestart->alpha = 0.5;
                    this->container->scroll->btnExit->alpha = 0.5;
                    this->container->scroll->qualityTXT.alpha = 0.5;
                    this->container->scroll->autopauseTXT.alpha = 0.5; 
                    this->container->scroll->btnMusic->mouseChildren = false;
                    this->container->scroll->btnMusic->mouseEnabled = false; 
                    this->container->scroll->btnSound->mouseChildren = false;
                    this->container->scroll->btnSound->mouseEnabled = false; 
                    this->container->scroll->btnLow->mouseChildren = false;
                    this->container->scroll->btnLow->mouseEnabled = false; 
                    this->container->scroll->btnMedium->mouseChildren = false;
                    this->container->scroll->btnMedium->mouseEnabled = false; 
                    this->container->scroll->btnHigh->mouseChildren = false;
                    this->container->scroll->btnHigh->mouseEnabled = false; 
                    this->container->scroll->btnOn->mouseChildren = false;
                    this->container->scroll->btnOn->mouseEnabled = false; 
                    this->container->scroll->btnOff->mouseChildren = false;
                    this->container->scroll->btnOff->mouseEnabled = false; 
                    this->container->scroll->btnResume->mouseChildren = false;
                    this->container->scroll->btnResume->mouseEnabled = false; 
                    this->container->scroll->btnRestart->mouseChildren = false;
                    this->container->scroll->btnRestart->mouseEnabled = false; 
                    this->container->scroll->btnExit->mouseChildren = false;
                    this->container->scroll->btnExit->mouseEnabled = false;
                }
            }
            else if (this->container->scroll->btnRestart->currentFrame == 3)
            {
                this->container->scroll->btnRestart->gotoAndStop(1);
            }
            if (event.target.name == "exitCase")
            {
                if (this->container->scroll->btnExit->currentFrame == 3)
                {
                    this->container->scroll->btnExit->gotoAndStop(1);
                    this->questionFlag = 2;
                    this->container->scroll->btnMusic->alpha = 0.5;
                    this->container->scroll->btnSound->alpha = 0.5;
                    this->container->scroll->btnLow.alpha = 0.5;
                    this->container->scroll->btnMedium->alpha = 0.5;
                    this->container->scroll->btnHigh->alpha = 0.5;
                    this->container->scroll->btnOn->alpha = 0.5;
                    this->container->scroll->btnOff->alpha = 0.5;
                    this->container->scroll->btnResume->alpha = 0.5;
                    this->container->scroll->btnRestart->alpha = 0.5;
                    this->container->scroll->btnExit->alpha = 0.5;
                    this->container->scroll->qualityTXT.alpha = 0.5;
                    this->container->scroll->autopauseTXT.alpha = 0.5; 
                    this->container->scroll->btnMusic->mouseChildren = false;
                    this->container->scroll->btnMusic->mouseEnabled = false; 
                    this->container->scroll->btnSound->mouseChildren = false;
                    this->container->scroll->btnSound->mouseEnabled = false; 
                    this->container->scroll->btnLow->mouseChildren = false;
                    this->container->scroll->btnLow->mouseEnabled = false; 
                    this->container->scroll->btnMedium->mouseChildren = false;
                    this->container->scroll->btnMedium->mouseEnabled = false; 
                    this->container->scroll->btnHigh->mouseChildren = false;
                    this->container->scroll->btnHigh->mouseEnabled = false; 
                    this->container->scroll->btnOn->mouseChildren = false;
                    this->container->scroll->btnOn->mouseEnabled = false; 
                    this->container->scroll->btnOff->mouseChildren = false;
                    this->container->scroll->btnOff->mouseEnabled = false; 
                    this->container->scroll->btnResume->mouseChildren = false;
                    this->container->scroll->btnResume->mouseEnabled = false; 
                    this->container->scroll->btnRestart->mouseChildren = false;
                    this->container->scroll->btnRestart->mouseEnabled = false; 
                    this->container->scroll->btnExit->mouseChildren = false;
                    this->container->scroll->btnExit->mouseEnabled = false;
                }
            }
            else if (this->container->scroll->btnExit->currentFrame == 3)
            {
                this->container->scroll->btnExit->gotoAndStop(1);
            }
            if (event.target.name == "y8Case")
            {
                if (this->container->scroll->btnY8->currentFrame == 3)
                {
                    this->container->scroll->btnY8->gotoAndStop(2);
                    //navigateToURL(new URLRequest("http://www.y8.com/?utm_source=" + Main::mainClass->domainName + "&utm_medium=g_prelogo&utm_campaign=brave_heads"));
                }
            }
            else if (this->container->scroll->btnY8->currentFrame == 3)
            {
                this->container->scroll->btnY8->gotoAndStop(1);
            }
        }
        else if (this->container->scroll->question)
        {
            if (event.target.name == "yesCase")
            {
                if (this->container->scroll->question->btnYes->currentFrame == 3)
                {
                    this->container->scroll->question->btnYes->gotoAndStop(2);
                    if (this->questionFlag == 1)
                    {
                        Main::mainClass->addNewScreen("World");
                    }
                    else if (this->questionFlag == 2)
                    {
                        Main::mainClass->addNewScreen("LevelsMenu");
                    }
                    Main::mainClass->testingClass = NULL;
                }
            }
            else if (this->container->scroll->question->btnYes->currentFrame == 3)
            {
                this->container->scroll->question->btnYes->gotoAndStop(1);
            }
            if (event.target.name == "noCase")
            {
                if (this->container->scroll->question->btnNo->currentFrame == 3)
                {
                    this->container->scroll->question->btnNo->gotoAndStop(2);
                    this->questionFlag = 0;
                }
            }
            else if (this->container->scroll->question->btnNo->currentFrame == 3)
            {
                this->container->scroll->question->btnNo->gotoAndStop(1);
            }
        }
        return;
    }// end function

    void PauseMenu::autoguidersButtons() 
    {
        this->autoguidesMouse_pt = new Point(this->mouseX, this->mouseY);
        this->autoguidesObject = null;
        this->autoguidesObject_pt = this->container->scroll->btnMusic->localToGlobal(this->container->scroll->btnMusic->musicCase->getPosition());
        this->autoguidesObjectWidth = this->container->scroll->btnMusic->musicCase.width / 2;
        this->autoguidesObjectHeight = this->container->scroll->btnMusic->musicCase.height / 2;
        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        {
            this->autoguidesObject = this->container->scroll->btnMusic->musicCase;
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->scroll->btnSound->localToGlobal( this->container->scroll->btnSound->soundCase->getPosition());
            this->autoguidesObjectWidth = this->container->scroll->btnSound->soundCase.width / 2;
            this->autoguidesObjectHeight = this->container->scroll->btnSound->soundCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->scroll->btnSound->soundCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->scroll->btnLow->localToGlobal(this->container->scroll->btnLow->lowCase->getPosition());
            this->autoguidesObjectWidth = this->container->scroll->btnLow->lowCase.width / 2;
            this->autoguidesObjectHeight = this->container->scroll->btnLow->lowCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->scroll->btnLow->lowCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->scroll->btnMedium->localToGlobal(this->container->scroll->btnMedium->mediumCase->getPosition());
            this->autoguidesObjectWidth = this->container->scroll->btnMedium->mediumCase.width / 2;
            this->autoguidesObjectHeight = this->container->scroll->btnMedium->mediumCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->scroll->btnMedium->mediumCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->scroll->btnHigh->localToGlobal( this->container->scroll->btnHigh->highCase->getPosition());
            this->autoguidesObjectWidth = this->container->scroll->btnHigh->highCase.width / 2;
            this->autoguidesObjectHeight = this->container->scroll->btnHigh->highCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->scroll->btnHigh->highCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->scroll->btnOn->localToGlobal(this->container->scroll->btnOn->onCase->getPosition());
            this->autoguidesObjectWidth = this->container->scroll->btnOn->onCase.width / 2;
            this->autoguidesObjectHeight = this->container->scroll->btnOn->onCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->scroll->btnOn->onCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->scroll->btnOff->localToGlobal(this->container->scroll->btnOff->offCase->getPosition());
            this->autoguidesObjectWidth = this->container->scroll->btnOff->offCase.width / 2;
            this->autoguidesObjectHeight = this->container->scroll->btnOff->offCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->scroll->btnOff->offCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->scroll->btnResume->localToGlobal(this->container->scroll->btnResume->resumeCase->getPosition());
            this->autoguidesObjectWidth = this->container->scroll->btnResume->resumeCase.width / 2;
            this->autoguidesObjectHeight = this->container->scroll->btnResume->resumeCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->scroll->btnResume->resumeCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->scroll->btnRestart->localToGlobal(this->container->scroll->btnRestart->restartCase->getPosition());
            this->autoguidesObjectWidth = this->container->scroll->btnRestart->restartCase.width / 2;
            this->autoguidesObjectHeight = this->container->scroll->btnRestart->restartCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->scroll->btnRestart->restartCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->scroll->btnExit->localToGlobal(this->container->scroll->btnExit->exitCase->getPosition());
            this->autoguidesObjectWidth = this->container->scroll->btnExit->exitCase.width / 2;
            this->autoguidesObjectHeight = this->container->scroll->btnExit->exitCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->scroll->btnExit->exitCase;
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->scroll->question)
            {
                this->autoguidesObject_pt = this->container->scroll->question->btnYes->localToGlobal(this->container->scroll->question->btnYes->yesCase->getPosition());
                this->autoguidesObjectWidth = this->container->scroll->question->btnYes->yesCase.width / 2;
                this->autoguidesObjectHeight = this->container->scroll->question->btnYes->yesCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->scroll->question->btnYes->yesCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->scroll->question)
            {
                this->autoguidesObject_pt = this->container->scroll->question->btnNo->localToGlobal(this->container->scroll->question->btnNo->noCase->getPosition());
                this->autoguidesObjectWidth = this->container->scroll->question->btnNo->noCase.width / 2;
                this->autoguidesObjectHeight = this->container->scroll->question->btnNo->noCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->scroll->question->btnNo->noCase;
                }
            }
        }
        if (this->autoguidesObject)
        {
            this->tempObject = new Object();
            this->tempObject.target = this->autoguidesObject;
            this->mouseMoveHandler(this->tempObject);
        }
        return;
    }// end function

    void PauseMenu::close()
    {
        if (!this->closeFlag)
        {
            this->closeFlag = true;
            this->container->scroll->btnResume->gotoAndStop(2); 
            this->container->mouseChildren = false;
            this->container->mouseEnabled = false;
        }
        return;
    }// end function

    //void PauseMenu::reInit()
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    if (//Sounds.instance.musicPausePosition != 0)
    //    {
    //        //Sounds.instance.musicPausePosition = 0;
    //    }
    //    if (//Sounds.instance.musicChanel)
    //    {
    //        if (this->startMusicVolume > 0)
    //        {
    //            //Sounds.instance.musicChanel.soundTransform = new SoundTransform(this->startMusicVolume, 0);
    //        }
    //    }
    //    if (this->world->getSphere || this->world->cast)
    //    {
    //        this->world->manageMouse("hide");
    //    }
    //    return;
    //}// end function

} 
