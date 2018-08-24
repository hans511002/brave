#include "BaseHeaders.h"
#include "MiddleScreen.h"
#include "MainClass.h"
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
        //Main::mainClass->stage->frameRate = 30;
        this->world = Main::mainClass->worldClass;
        this->setPosition(Vec2(0,0)); 
		this->world->worldInterface->setPosition(Vec2(0, 0));
        
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
        this->container->scroll->btnMusic->musicCase->setMouseEnabled(true);
        this->container->scroll->btnSound->soundCase->setMouseEnabled(true);
        this->container->scroll->btnLow->lowCase->setMouseEnabled(true);
        this->container->scroll->btnMedium->mediumCase->setMouseEnabled(true);
        this->container->scroll->btnHigh->highCase->setMouseEnabled(true);
        this->container->scroll->btnOn->onCase->setMouseEnabled(true);
        this->container->scroll->btnOff->offCase->setMouseEnabled(true);
        this->container->scroll->btnResume->resumeCase->setMouseEnabled(true);
        this->container->scroll->btnRestart->restartCase->setMouseEnabled(true);
        this->container->scroll->btnExit->exitCase->setMouseEnabled(true); 
        this->container->scroll->setMouseChildren(false);
        this->container->scroll->setMouseEnabled(false);
        this->container->scroll->btnResume->arrow->setVisible(false);
        this->container->scroll->btnRestart->arrow->setVisible(false);
        this->container->scroll->btnExit->arrow->setVisible(false);
        this->container->scroll->btnY8->stop();
        this->container->scroll->btnY8->y8Case->stop();
        if (!Main::mainClass->IDIClass.isSponsor)
        {
            this->container->scroll->btnY8->y8Case->setMouseEnabled(true);
        }
        this->addChild(this->container);
        //if (!AudioUtil::musicOn)
        //{
        //    this->container->scroll->btnMusic->gotoAndStop(4);
        //}
        //if (!AudioUtil::soundOn)
        //{
        //    this->container->scroll->btnSound->gotoAndStop(4);
        //}
        //if (Main::mainClass->saveBoxClass.gameSave.data.quality == "low")
        //{
        //    this->container->scroll->btnLow->gotoAndStop(4);
        //    this->container->scroll->btnLow->lowCase->setMouseEnabled(false);
        //}
        //else if (Main::mainClass->saveBoxClass.gameSave.data.quality == "medium")
        //{
        //    this->container->scroll->btnMedium->gotoAndStop(4);
        //    this->container->scroll->btnMedium->mediumCase->setMouseEnabled(false);
        //}
        //else if (Main::mainClass->saveBoxClass.gameSave.data.quality == "high")
        //{
        //    this->container->scroll->btnHigh->gotoAndStop(4);
        //    this->container->scroll->btnHigh->highCase->setMouseEnabled(false);
        //}
        if (Main::mainClass->saveBoxClass->getBoolValue("autoPause"))
        {
            this->container->scroll->btnOn->gotoAndStop(4);
            this->container->scroll->btnOn->onCase->setMouseEnabled(false);
        }
        else
        {
            this->container->scroll->btnOff->gotoAndStop(4);
            this->container->scroll->btnOff->offCase->setMouseEnabled(false);
        }
        return;
    }// end function

    void PauseMenu::enterFrameHandler(cocos2d::EventMouse * event)
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
            if (AudioUtil::soundOn)
            {
                if (this->startMusicVolume == 0)
                {
                    this->startMusicVolume = AudioUtil::getMusicVolume();
                }
                if (AudioUtil::getMusicVolume() > this->startMusicVolume * 0.35)
                {
                    AudioUtil::setMusicVolume(AudioUtil::getMusicVolume() - this->startMusicVolume * 0.035 );
                }
            }
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
                    this->container->scroll->setMouseChildren(true);
                    this->container->scroll->setMouseEnabled(true);
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
            if (AudioUtil::soundOn)
            { 
                if (AudioUtil::getMusicVolume() < this->startMusicVolume )
                {
                    AudioUtil::setMusicVolume(AudioUtil::getMusicVolume() - this->startMusicVolume * 0.035 );
                }
            }
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
                this->world->menuObject = NULL;
                this->world->removeChild(this);
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
                    this->container->scroll->btnLow->alpha = 1;
                    this->container->scroll->btnMedium->alpha = 1;
                    this->container->scroll->btnHigh->alpha = 1;
                    this->container->scroll->btnOn->alpha = 1;
                    this->container->scroll->btnOff->alpha = 1;
                    this->container->scroll->btnResume->alpha = 1;
                    this->container->scroll->btnRestart->alpha = 1;
                    this->container->scroll->btnExit->alpha = 1;
                    this->container->scroll->qualityTXT->alpha = 1;
                    this->container->scroll->autopauseTXT->alpha = 1; 
                    this->container->scroll->btnMusic->setMouseChildren(true);
                    this->container->scroll->btnMusic->setMouseEnabled(true); 
                    this->container->scroll->btnSound->setMouseChildren(true);
                    this->container->scroll->btnSound->setMouseEnabled(true); 
                    this->container->scroll->btnLow->setMouseChildren(true);
                    this->container->scroll->btnLow->setMouseEnabled(true); 
                    this->container->scroll->btnMedium->setMouseChildren(true);
                    this->container->scroll->btnMedium->setMouseEnabled(true); 
                    this->container->scroll->btnHigh->setMouseChildren(true);
                    this->container->scroll->btnHigh->setMouseEnabled(true); 
                    this->container->scroll->btnOn->setMouseChildren(true);
                    this->container->scroll->btnOn->setMouseEnabled(true); 
                    this->container->scroll->btnOff->setMouseChildren(true);
                    this->container->scroll->btnOff->setMouseEnabled(true); 
                    this->container->scroll->btnResume->setMouseChildren(true);
                    this->container->scroll->btnResume->setMouseEnabled(true); 
                    this->container->scroll->btnRestart->setMouseChildren(true);
                    this->container->scroll->btnRestart->setMouseEnabled(true); 
                    this->container->scroll->btnExit->setMouseChildren(true);
                    this->container->scroll->btnExit->setMouseEnabled(true);
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
                    this->container->scroll->question->btnYes->yesCase->setMouseEnabled(true);
                    this->container->scroll->question->btnNo->noCase->setMouseEnabled(true); 
                    this->container->scroll->question->setMouseChildren(false);
                    this->container->scroll->question->setMouseEnabled(false);
                }
            }
            else if (this->container->scroll->question->currentFrame < this->container->scroll->question->totalFrames)
            {
                this->container->scroll->question->gotoAndStop((this->container->scroll->question->currentFrame + 1));
                if (this->container->scroll->question->currentFrame == this->container->scroll->question->totalFrames)
                { 
                    this->container->scroll->question->setMouseChildren(true);
                    this->container->scroll->question->setMouseEnabled(true);;
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
        this->i = 0;
        while (this->i < this->world->listOfClasses.size())
        { 
            if (this->world->listOfClasses[this->i] is Indexes)
            {
                if (this->world->listOfClasses[this->i]->type == "golemDeath" || this->world->listOfClasses[this->i]->type == "icemanDeath" || this->world->listOfClasses[this->i]->type == "airDeath")
                {
                    this->world->listOfClasses[this->i]->update();
                }
            }
            i++;
        }
        return;
    }// end function

    void PauseMenu::mouseMoveHandler(cocos2d::EventMouse *e)  
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if(!event)
			return;
        string targetName = event->target->getName();
        if (this->questionFlag == 0)
        {
            if (param1->target->name == "musicCase")
            {
                if (this->container->scroll->btnMusic->currentFrame == 1 || this->container->scroll->btnMusic->currentFrame == 4)
                {
                    this->container->scroll->btnMusic->gotoAndStop((this->container->scroll->btnMusic->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
            if (this->container->scroll->btnY8->y8Case->mouseEnabled)
            {
                if (param1->target->name == "y8Case")
                {
                    if (this->container->scroll->btnY8->currentFrame == 1)
                    {
                        this->container->scroll->btnY8->gotoAndStop(2);
                        AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
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

    void PauseMenu::mouseDownHandler(cocos2d::EventMouse *e) 
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if(!event)
			return;
        string targetName = event->target->getName();
        if (this->questionFlag == 0)
        {
            if (event.target.name == "musicCase")
            {
                if (this->container->scroll->btnMusic->currentFrame == 2 || this->container->scroll->btnMusic->currentFrame == 5)
                {
                    this->container->scroll->btnMusic->gotoAndStop((this->container->scroll->btnMusic->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "soundCase")
            {
                if (this->container->scroll->btnSound->currentFrame == 2 || this->container->scroll->btnSound->currentFrame == 5)
                {
                    this->container->scroll->btnSound->gotoAndStop((this->container->scroll->btnSound->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "lowCase")
            {
                if (this->container->scroll->btnLow->currentFrame == 2)
                {
                    this->container->scroll->btnLow->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "mediumCase")
            {
                if (this->container->scroll->btnMedium->currentFrame == 2)
                {
                    this->container->scroll->btnMedium->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "highCase")
            {
                if (this->container->scroll->btnHigh->currentFrame == 2)
                {
                    this->container->scroll->btnHigh->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "onCase")
            {
                if (this->container->scroll->btnOn->currentFrame == 2)
                {
                    this->container->scroll->btnOn->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "offCase")
            {
                if (this->container->scroll->btnOff->currentFrame == 2)
                {
                    this->container->scroll->btnOff->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "resumeCase")
            {
                if (this->container->scroll->btnResume->currentFrame == 2)
                {
                    this->container->scroll->btnResume->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "restartCase")
            {
                if (this->container->scroll->btnRestart->currentFrame == 2)
                {
                    this->container->scroll->btnRestart->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "exitCase")
            {
                if (this->container->scroll->btnExit->currentFrame == 2)
                {
                    this->container->scroll->btnExit->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
            else if (event.target.name == "y8Case")
            {
                if (this->container->scroll->btnY8->currentFrame == 2)
                {
                    this->container->scroll->btnY8->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                }
            }
        }
        else if (event.target.name == "yesCase")
        {
            if (this->container->scroll->question->btnYes->currentFrame == 2)
            {
                this->container->scroll->question->btnYes->gotoAndStop(3);
                AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
            }
        }
        else if (event.target.name == "noCase")
        {
            if (this->container->scroll->question->btnNo->currentFrame == 2)
            {
                this->container->scroll->question->btnNo->gotoAndStop(3);
                AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
            }
        }
        return;
    }// end function

    void PauseMenu::mouseUpHandler(cocos2d::EventMouse * event) 
    {
        if (this->questionFlag == 0)
        {
            if (event.target.name == "musicCase")
            {
                if (this->container->scroll->btnMusic->currentFrame == 3)
                {
                    this->container->scroll->btnMusic->gotoAndStop(5);
                    //AudioUtil::musicPausePosition = AudioUtil::musicChanel.position;
                    AudioUtil::musicManage("off");
                }
                else if (this->container->scroll->btnMusic->currentFrame == 6)
                {
                    this->container->scroll->btnMusic->gotoAndStop(2);
                    AudioUtil::musicManage("on");
                    if (this->world->wavesClass->nowWave == 0)
                    {
                        AudioUtil::playMusic(1);
                    }
                    else
                    {
                        AudioUtil::playMusic(2);
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
                    AudioUtil::soundManage("off");
                }
                else if (this->container->scroll->btnSound->currentFrame == 6)
                {
                    this->container->scroll->btnSound->gotoAndStop(2);
                    AudioUtil::soundManage("on");
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
                    this->container->scroll->btnLow->lowCase->setMouseEnabled(false);
                    if (this->container->scroll->btnMedium->currentFrame != 1)
                    {
                        this->container->scroll->btnMedium->gotoAndStop(1);
                        this->container->scroll->btnMedium->mediumCase->setMouseEnabled(true);
                    }
                    if (this->container->scroll->btnHigh->currentFrame != 1)
                    {
                        this->container->scroll->btnHigh->gotoAndStop(1);
                        this->container->scroll->btnHigh->highCase->setMouseEnabled(true);
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
                    this->container->scroll->btnMedium->mediumCase->setMouseEnabled(false);
                    if (this->container->scroll->btnLow->currentFrame != 1)
                    {
                        this->container->scroll->btnLow->gotoAndStop(1);
                        this->container->scroll->btnLow->lowCase->setMouseEnabled(true);
                    }
                    if (this->container->scroll->btnHigh->currentFrame != 1)
                    {
                        this->container->scroll->btnHigh->gotoAndStop(1);
                        this->container->scroll->btnHigh->highCase->setMouseEnabled(true);
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
                    this->container->scroll->btnHigh->highCase->setMouseEnabled(false);
                    if (this->container->scroll->btnLow->currentFrame != 1)
                    {
                        this->container->scroll->btnLow->gotoAndStop(1);
                        this->container->scroll->btnLow->lowCase->setMouseEnabled(true);
                    }
                    if (this->container->scroll->btnMedium->currentFrame != 1)
                    {
                        this->container->scroll->btnMedium->gotoAndStop(1);
                        this->container->scroll->btnMedium->mediumCase->setMouseEnabled(true);
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
                    this->container->scroll->btnOn->onCase->setMouseEnabled(false);
                    this->container->scroll->btnOff->gotoAndStop(1);
                    this->container->scroll->btnOff->offCase->setMouseEnabled(true);
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
                    this->container->scroll->btnOff->offCase->setMouseEnabled(false);
                    this->container->scroll->btnOn->gotoAndStop(1);
                    this->container->scroll->btnOn->onCase->setMouseEnabled(true);
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
                    this->container->scroll->btnLow->alpha = 0.5;
                    this->container->scroll->btnMedium->alpha = 0.5;
                    this->container->scroll->btnHigh->alpha = 0.5;
                    this->container->scroll->btnOn->alpha = 0.5;
                    this->container->scroll->btnOff->alpha = 0.5;
                    this->container->scroll->btnResume->alpha = 0.5;
                    this->container->scroll->btnRestart->alpha = 0.5;
                    this->container->scroll->btnExit->alpha = 0.5;
                    this->container->scroll->qualityTXT->alpha = 0.5;
                    this->container->scroll->autopauseTXT->alpha = 0.5; 
                    this->container->scroll->btnMusic->setMouseChildren(false);
                    this->container->scroll->btnMusic->setMouseEnabled(false); 
                    this->container->scroll->btnSound->setMouseChildren(false);
                    this->container->scroll->btnSound->setMouseEnabled(false); 
                    this->container->scroll->btnLow->setMouseChildren(false);
                    this->container->scroll->btnLow->setMouseEnabled(false); 
                    this->container->scroll->btnMedium->setMouseChildren(false);
                    this->container->scroll->btnMedium->setMouseEnabled(false); 
                    this->container->scroll->btnHigh->setMouseChildren(false);
                    this->container->scroll->btnHigh->setMouseEnabled(false); 
                    this->container->scroll->btnOn->setMouseChildren(false);
                    this->container->scroll->btnOn->setMouseEnabled(false); 
                    this->container->scroll->btnOff->setMouseChildren(false);
                    this->container->scroll->btnOff->setMouseEnabled(false); 
                    this->container->scroll->btnResume->setMouseChildren(false);
                    this->container->scroll->btnResume->setMouseEnabled(false); 
                    this->container->scroll->btnRestart->setMouseChildren(false);
                    this->container->scroll->btnRestart->setMouseEnabled(false); 
                    this->container->scroll->btnExit->setMouseChildren(false);
                    this->container->scroll->btnExit->setMouseEnabled(false);
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
                    this->container->scroll->btnLow->alpha = 0.5;
                    this->container->scroll->btnMedium->alpha = 0.5;
                    this->container->scroll->btnHigh->alpha = 0.5;
                    this->container->scroll->btnOn->alpha = 0.5;
                    this->container->scroll->btnOff->alpha = 0.5;
                    this->container->scroll->btnResume->alpha = 0.5;
                    this->container->scroll->btnRestart->alpha = 0.5;
                    this->container->scroll->btnExit->alpha = 0.5;
                    this->container->scroll->qualityTXT->alpha = 0.5;
                    this->container->scroll->autopauseTXT->alpha = 0.5; 
                    this->container->scroll->btnMusic->setMouseChildren(false);
                    this->container->scroll->btnMusic->setMouseEnabled(false); 
                    this->container->scroll->btnSound->setMouseChildren(false);
                    this->container->scroll->btnSound->setMouseEnabled(false); 
                    this->container->scroll->btnLow->setMouseChildren(false);
                    this->container->scroll->btnLow->setMouseEnabled(false); 
                    this->container->scroll->btnMedium->setMouseChildren(false);
                    this->container->scroll->btnMedium->setMouseEnabled(false); 
                    this->container->scroll->btnHigh->setMouseChildren(false);
                    this->container->scroll->btnHigh->setMouseEnabled(false); 
                    this->container->scroll->btnOn->setMouseChildren(false);
                    this->container->scroll->btnOn->setMouseEnabled(false); 
                    this->container->scroll->btnOff->setMouseChildren(false);
                    this->container->scroll->btnOff->setMouseEnabled(false); 
                    this->container->scroll->btnResume->setMouseChildren(false);
                    this->container->scroll->btnResume->setMouseEnabled(false); 
                    this->container->scroll->btnRestart->setMouseChildren(false);
                    this->container->scroll->btnRestart->setMouseEnabled(false); 
                    this->container->scroll->btnExit->setMouseChildren(false);
                    this->container->scroll->btnExit->setMouseEnabled(false);
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
            this->container->setMouseChildren(false);
            this->container->setMouseEnabled(false);
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
    //    if (AudioUtil::musicPausePosition != 0)
    //    {
    //        AudioUtil::musicPausePosition = 0;
    //    }
    //    if (AudioUtil::musicChanel)
    //    {
    //        if (this->startMusicVolume > 0)
    //        {
    //            AudioUtil::musicChanel.soundTransform = new SoundTransform(this->startMusicVolume, 0);
    //        }
    //    }
    //   if (AudioUtil::soundOn)
    //   { 
    //       if ( this->startMusicVolume > 0)
    //       {
    //           AudioUtil::setMusicVolume(startMusicVolume);
    //       }
    //   }
    //    if (this->world->getSphere || this->world->cast)
    //    {
    //        this->world->manageMouse("hide");
    //    }
    //    return;
    //}// end function

} 
