#include "Screen.h"   
#include "engine/World.h" 
  
namespace screens
{  
    StartMenu_mc::StartMenu_mc()
    {
        return;
    }// end function

    
    StartMenu::StartMenu():page(1),question(0),loginFlag1(0),waitCounter(0),syncLoginCounter(0)
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool StartMenu::init() 
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        this->container = new StartMenu_mc();
        this->container->stop();
        this->container->logOut->stop();
        this->container->logo->stop();
        this->container->start->stop();
        this->container->credits->stop();
        this->container->btnMusic->stop();
        this->container->btnSound->stop();
        this->container->back->stop();
        this->container->logOut->setMouseEnabled(true);
        this->container->btnMusic->musicCase->setMouseEnabled(true);
        this->container->btnSound->soundCase->setMouseEnabled(true);
        this->container->back->backCase->setMouseEnabled(true);
        this->container->back->setVisible(false);
        this->container->btnY8->stop();
        this->container->btnIdnet->stop();
        this->container->btnY8->y8Case->stop();
        this->container->btnIdnet->idnetCase->stop();
        //if (!Main::mainClass->IDIClass.isSponsor)
        //{
        //    this->container->btnY8->y8Case->setMouseEnabled(true);
        //}
        this->container->btnIdnet->idnetCase->setMouseEnabled(true);
        this->container->logOut->setVisible(false);
        this->addChild(this->container);
        //if (//Sounds.instance.musicOn)
        //{
        //    this->container->btnMusic->gotoAndStop(1);
        //}
        //else
        //{
        //    this->container->btnMusic->gotoAndStop(4);
        //}
        //if (//Sounds.instance.soundOn)
        //{
        //    this->container->btnSound->gotoAndStop(1);
        //}
        //else
        //{
        //    this->container->btnSound->gotoAndStop(4);
        //}
        if (!Main::mainClass->middleScreenClass)
        {
            this->firstPlay = true;
            Main::mainClass->bmp = new Bitmap(Main::mainClass->getBitmapData(this));
            Main::mainClass->bmp.alpha = 0;
            this->addChild(Main::mainClass->bmp);
            this->container->setVisible(false);
            this->manageListeners("on");
        }
        if (!StartMenu::firstMusicPlay)
        {
            StartMenu::firstMusicPlay = true;
            ////Sounds.instance.playMusic(0);
        }
        if (Main::mainClass->lastClass == "LevelsMenu")
        {
            this->container->gotoAndStop(53);
            if (Main::mainClass->saveBoxClass->getStringValue("type") == "site")
            {
                this->page = 4;
                this->waitCounter = 0;
                //Main::mainClass->saveBoxClass->gameSave4.data.haveSave = false;
                //Main::mainClass->saveBoxClass->gameSave5.data.haveSave = false;
                //Main::mainClass->saveBoxClass->gameSave6.data.haveSave = false;
                //Main::mainClass->IDIClass.getData(4);
                //Main::mainClass->IDIClass.getData(5);
                //Main::mainClass->IDIClass.getData(6);
            }
            else
            {
                this->page = 3;
            }
            this->container->back->setVisible(true);
        } 
        this->container->setMouseChildren(false);
        this->container->setMouseEnabled(false);
        return;
    }// end function

    void StartMenu::enterFrameHandler(cocos2d::EventMouse * event)
    {
        if (this->frameCounter < 30)
        {
            this->frameCounter++;
        }
        else
        {
            this->frameCounter = 1;
        }
        if (this->container->glitter)
        {
            if (this->container->glitter->currentFrame < this->container->glitter->totalFrames)
            {
                this->container->glitter->gotoAndStop((this->container->glitter->currentFrame + 1));
            }
            else
            {
                this->container->glitter->gotoAndStop(1);
            }
        }
        if (this->firstPlay)
        {
            if (Main::mainClass->bmp.alpha < 1)
            {
                Main::mainClass->bmp.alpha = Main::mainClass->bmp.alpha + 0.2;
            }
            else
            {
                this->firstPlay = false;
                this->container->setVisible(true);
                this->removeChild(Main::mainClass->bmp);
                Main::mainClass->bmp = NULL;
            }
        }
        else
        {
            if (this->page == 1)
            {
                if (this->container->currentFrame < 28)
                {
                    this->container->gotoAndStop((this->container->currentFrame + 1));
                    if (this->container->currentFrame == 9)
                    {
                        this->container->glitter->stop();
                    }
                    else if (this->container->currentFrame == 28)
                    {
                        this->container->start->startCase->setMouseEnabled(true);
                        this->container->credits->creditsCase->setMouseEnabled(true); 
                        this->container->setMouseChildren(true);
                        this->container->setMouseEnabled(true);
                        this->container->back->setVisible(false);
                        this->autoguidersButtons();
                    }
                }
                else if (this->container->currentFrame > 28)
                {
                    this->container->gotoAndStop((this->container->currentFrame - 1));
                    if (this->container->currentFrame == 33)
                    {
                        this->container->start->stop();
                        this->container->credits->stop();
                    }
                    else if (this->container->currentFrame == 28)
                    {
                        this->container->start->startCase->setMouseEnabled(true);
                        this->container->credits->creditsCase->setMouseEnabled(true); 
                        this->container->setMouseChildren(true);
                        this->container->setMouseEnabled(true);
                        this->container->back->setVisible(false);
                        this->autoguidersButtons();
                    }
                }
            }
            else if (this->page == 2)
            {
                if (this->container->currentFrame < 44)
                {
                    this->container->gotoAndStop((this->container->currentFrame + 1));
                    if (this->container->currentFrame == 35)
                    {
                        this->container->saveType->stop();
                        this->container->saveType->localSave->stop();
                        this->container->saveType->onlineSave->stop();
                        this->container->saveType->localSave->localSaveCase->stop();
                        this->container->saveType->onlineSave->onlineSaveCase->stop();
                        if (Main::mainClass->IDIClass.idnet)
                        {
                            //if (Main::mainClass->IDIClass.idnet.userData)
                            //{
                            //    std::setText(this->container->saveType->onlineSave->welcomeTXT,"Welcome,");
                            //    std::setText(this->container->saveType->onlineSave->nickTXT,Main::mainClass->IDIClass.currentUser + "!");
                            //}
                            //else
                            //{
                            //    std::setText(this->container->saveType->onlineSave->welcomeTXT,"登录使用在线存档");
                            //    std::setText(this->container->saveType->onlineSave->nickTXT,"");
                            //}
                            this->welcomeText = this->container->saveType->onlineSave->welcomeTXT.text;
                            this->nickText = this->container->saveType->onlineSave->nickTXT.text;
                            this->container->saveType->onlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
                        }
                        this->container->saveType->localSave->localSaveCase->setMouseEnabled(true);
                        this->container->saveType->onlineSave->onlineSaveCase->setMouseEnabled(true);
                        this->container->back->setVisible(true);
                    }
                    else if (this->container->currentFrame == 44)
                    { 
                        this->container->setMouseChildren(true);
                        this->container->setMouseEnabled(true);
                        this->autoguidersButtons();
                    }
                }
                else if (this->container->currentFrame > 44)
                {
                    this->container->gotoAndStop((this->container->currentFrame - 1));
                    if (this->container->currentFrame == 53)
                    {
                        this->container->gotoAndStop(34);
                    }
                }
            }
            else if (this->page == 3 || this->page == 4)
            {
                if (this->page == 3 || this->waitCounter == 3)
                {
                    if (this->container->currentFrame < 79)
                    {
                        this->container->gotoAndStop((this->container->currentFrame + 1));
                        if (this->container->currentFrame == 54)
                        {
                            if (this->page == 3)
                            {
                                if (!Main::mainClass->saveBoxClass->gameSave1.data.haveSave)
                                {
                                    this->container->game1->gotoAndStop(4);
                                    this->container->game1->newGame1Case->stop();
                                    this->container->game1->newGame1Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game1->gotoAndStop(1);
                                    this->container->game1->game1Case->stop();
                                    this->container->game1->game1Case->setMouseEnabled(true);
                                    this->container->game1->syncSlot->stop();
                                    this->container->game1->syncSlot->syncSlotCase->stop();
                                    this->container->game1->syncSlot->syncSlotCase->setMouseEnabled(true);
                                    //if (Main::mainClass->IDIClass.idnet)
                                    //{
                                    //    if (!Main::mainClass->IDIClass.idnet.userData)
                                    //    {
                                    //        this->container->game1->syncSlot->gotoAndStop(1);
                                    //    }
                                    //    else
                                    //    {
                                    //        this->container->game1->syncSlot->gotoAndStop(4);
                                    //    }
                                    //}
                                    //else
                                    //{
                                    //    this->container->game1->syncSlot->setVisible(false);
                                    //}
                                    this->container->game1->deleteSlot->stop();
                                    this->container->game1->deleteSlot->deleteSlotCase->stop();
                                    this->container->game1->deleteSlot->deleteSlotCase->setMouseEnabled(true);
                                    int tempObject = 0;
                                    this->i = 0;
                                    while (this->i < Main::mainClass->saveBoxClass->gameSave1.data.starsOfLevels.length)
                                    {
                                        
                                        tempObject = tempObject + Main::mainClass->saveBoxClass->gameSave1.data.starsOfLevels[this->i];
                                        i++;
                                    }
                                    std::setText(this->container->game1->numTXT,tempObject + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    this->container->game1->numTXT.setTextFormat(Main::mainClass->boldTextFormat);
                                }
                                if (!Main::mainClass->saveBoxClass->gameSave2.data.haveSave)
                                {
                                    this->container->game2->gotoAndStop(4);
                                    this->container->game2->newGame2Case->stop();
                                    this->container->game2->newGame2Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game2->gotoAndStop(1);
                                    this->container->game2->game2Case->stop();
                                    this->container->game2->game2Case->setMouseEnabled(true);
                                    this->container->game2->syncSlot->stop();
                                    this->container->game2->syncSlot->syncSlotCase->stop();
                                    this->container->game2->syncSlot->syncSlotCase->setMouseEnabled(true);
                                    if (Main::mainClass->IDIClass.idnet)
                                    {
                                        if (!Main::mainClass->IDIClass.idnet.userData)
                                        {
                                            this->container->game2->syncSlot->gotoAndStop(1);
                                        }
                                        else
                                        {
                                            this->container->game2->syncSlot->gotoAndStop(4);
                                        }
                                    }
                                    else
                                    {
                                        this->container->game2->syncSlot->setVisible(false);
                                    }
                                    this->container->game2->deleteSlot->stop();
                                    this->container->game2->deleteSlot->deleteSlotCase->stop();
                                    this->container->game2->deleteSlot->deleteSlotCase->setMouseEnabled(true);
                                    int tempObject = 0;
                                    this->i = 0;
                                    while (this->i < Main::mainClass->saveBoxClass->gameSave2.data.starsOfLevels.length)
                                    {
                                        
                                        tempObject = tempObject + Main::mainClass->saveBoxClass->gameSave2.data.starsOfLevels[this->i];
                                        i++;
                                    }
                                    std::setText(this->container->game2->numTXT,tempObject + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    this->container->game2->numTXT.setTextFormat(Main::mainClass->boldTextFormat);
                                }
                                if (!Main::mainClass->saveBoxClass->gameSave3.data.haveSave)
                                {
                                    this->container->game3->gotoAndStop(4);
                                    this->container->game3->newGame3Case->stop();
                                    this->container->game3->newGame3Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game3->gotoAndStop(1);
                                    this->container->game3->game3Case->stop();
                                    this->container->game3->game3Case->setMouseEnabled(true);
                                    this->container->game3->syncSlot->stop();
                                    this->container->game3->syncSlot->syncSlotCase->stop();
                                    this->container->game3->syncSlot->syncSlotCase->setMouseEnabled(true);
                                    if (Main::mainClass->IDIClass.idnet)
                                    {
                                        if (!Main::mainClass->IDIClass.idnet.userData)
                                        {
                                            this->container->game3->syncSlot->gotoAndStop(1);
                                        }
                                        else
                                        {
                                            this->container->game3->syncSlot->gotoAndStop(4);
                                        }
                                    }
                                    else
                                    {
                                        this->container->game3->syncSlot->setVisible(false);
                                    }
                                    this->container->game3->deleteSlot->stop();
                                    this->container->game3->deleteSlot->deleteSlotCase->stop();
                                    this->container->game3->deleteSlot->deleteSlotCase->setMouseEnabled(true);
                                    tempObject = 0;
                                    this->i = 0;
                                    while (this->i < Main::mainClass->saveBoxClass->gameSave3.data.starsOfLevels.length)
                                    {
                                        
                                        tempObject = tempObject + Main::mainClass->saveBoxClass->gameSave3.data.starsOfLevels[this->i];
                                        i++;
                                    }
                                    std::setText(this->container->game3->numTXT,tempObject + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    this->container->game3->numTXT.setTextFormat(Main::mainClass->boldTextFormat);
                                }
                            }
                            else if (this->page == 4)
                            {
                                if (!Main::mainClass->saveBoxClass->gameSave4.data.haveSave)
                                {
                                    this->container->game1->gotoAndStop(4);
                                    this->container->game1->newGame1Case->stop();
                                    this->container->game1->newGame1Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game1->gotoAndStop(1);
                                    this->container->game1->game1Case->stop();
                                    this->container->game1->game1Case->setMouseEnabled(true);
                                    this->container->game1->syncSlot->stop();
                                    this->container->game1->syncSlot->syncSlotCase->stop();
                                    this->container->game1->syncSlot->syncSlotCase->setMouseEnabled(true);
                                    this->container->game1->syncSlot->setVisible(false);
                                    this->container->game1->deleteSlot->stop();
                                    this->container->game1->deleteSlot->deleteSlotCase->stop();
                                    this->container->game1->deleteSlot->deleteSlotCase->setMouseEnabled(true);
                                    int tempObject = 0;
                                    this->i = 0;
                                    while (this->i < Main::mainClass->saveBoxClass->gameSave4.data.starsOfLevels.length)
                                    {
                                        
                                        tempObject = tempObject + Main::mainClass->saveBoxClass->gameSave4.data.starsOfLevels[this->i];
                                        i++;
                                    }
                                    tempObject =  tempObject + 3;
                                    std::setText(this->container->game1->numTXT,tempObject + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    this->container->game1->numTXT.setTextFormat(Main::mainClass->boldTextFormat);
                                }
                                if (!Main::mainClass->saveBoxClass->gameSave5.data.haveSave)
                                {
                                    this->container->game2->gotoAndStop(4);
                                    this->container->game2->newGame2Case->stop();
                                    this->container->game2->newGame2Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game2->gotoAndStop(1);
                                    this->container->game2->game2Case->stop();
                                    this->container->game2->game2Case->setMouseEnabled(true);
                                    this->container->game2->syncSlot->stop();
                                    this->container->game2->syncSlot->syncSlotCase->stop();
                                    this->container->game2->syncSlot->syncSlotCase->setMouseEnabled(true);
                                    this->container->game2->syncSlot->setVisible(false);
                                    this->container->game2->deleteSlot->stop();
                                    this->container->game2->deleteSlot->deleteSlotCase->stop();
                                    this->container->game2->deleteSlot->deleteSlotCase->setMouseEnabled(true);
                                    tempObject = 0;
                                    this->i = 0;
                                    while (this->i < Main::mainClass->saveBoxClass->gameSave5.data.starsOfLevels.length)
                                    { 
                                        tempObject = tempObject + Main::mainClass->saveBoxClass->gameSave5.data.starsOfLevels[this->i];
                                        i++;
                                    }
                                    tempObject = tempObject + 3;
                                    std::setText(this->container->game2->numTXT,tempObject + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    this->container->game2->numTXT.setTextFormat(Main::mainClass->boldTextFormat);
                                }
                                if (!Main::mainClass->saveBoxClass->gameSave6.data.haveSave)
                                {
                                    this->container->game3->gotoAndStop(4);
                                    this->container->game3->newGame3Case->stop();
                                    this->container->game3->newGame3Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game3->gotoAndStop(1);
                                    this->container->game3->game3Case->stop();
                                    this->container->game3->game3Case->setMouseEnabled(true);
                                    this->container->game3->syncSlot->stop();
                                    this->container->game3->syncSlot->syncSlotCase->stop();
                                    this->container->game3->syncSlot->syncSlotCase->setMouseEnabled(true);
                                    this->container->game3->syncSlot->setVisible(false);
                                    this->container->game3->deleteSlot->stop();
                                    this->container->game3->deleteSlot->deleteSlotCase->stop();
                                    this->container->game3->deleteSlot->deleteSlotCase->setMouseEnabled(true);
                                    tempObject = 0;
                                    this->i = 0;
                                    while (this->i < Main::mainClass->saveBoxClass->gameSave6.data.starsOfLevels.length)
                                    {
                                        
                                        tempObject = tempObject + Main::mainClass->saveBoxClass->gameSave6.data.starsOfLevels[this->i];
                                        i++;
                                    }
                                    tempObject = tempObject + 3;
                                    std::setText(this->container->game3->numTXT,tempObject + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    this->container->game3->numTXT.setTextFormat(Main::mainClass->boldTextFormat);
                                }
                            }
                            this->container->back->setVisible(true);
                        }
                        else if (this->container->currentFrame == 79)
                        { 
                            this->container->setMouseChildren(true);
                            this->container->setMouseEnabled(true);
                            this->autoguidersButtons();
                        }
                    }
                    if (this->question > 0)
                    {
                        if (this->container->currentFrame < 87)
                        {
                            this->container->gotoAndStop((this->container->currentFrame + 1));
                            if (this->container->currentFrame == 80)
                            {
                                this->container->question->stop();
                                this->container->question->btnYes->stop();
                                this->container->question->btnYes->yesCase->stop();
                                this->container->question->btnNo->stop();
                                this->container->question->btnNo->noCase->stop();
                                this->container->question->btnYes->yesCase->setMouseEnabled(true);
                                this->container->question->btnNo->noCase->setMouseEnabled(true); 
                                this->container->question->setMouseChildren(false);
                                this->container->question->setMouseEnabled(false);
                                if (this->question < 11)
                                {
                                    std::setText(this->container->question->noteTXT,"Delete save slot?");
                                }
                                else
                                {
                                    std::setText(this->container->question->noteTXT,"Are you sure?");
                                }
                            }
                        }
                        else if (this->container->question->currentFrame < this->container->question->totalFrames)
                        {
                            this->container->question->gotoAndStop((this->container->question->currentFrame + 1));
                            if (this->container->question->currentFrame == this->container->question->totalFrames)
                            { 
                                this->container->question->setMouseChildren(true);
                                this->container->question->setMouseEnabled(true);
                            }
                        }
                    }
                    else if (this->question == -1)
                    {
                        tempObject = false;
                        if (this->container->question)
                        {
                            if (this->container->question->currentFrame > 1)
                            {
                                this->container->question->gotoAndStop((this->container->question->currentFrame - 1));
                                tempObject = true;
                            }
                        }
                        if (!tempObject)
                        {
                            if (this->container->currentFrame > 79)
                            {
                                this->container->gotoAndStop((this->container->currentFrame - 1));
                            }
                            else
                            {
                                this->question = 0; 
                                this->container->game1->setMouseChildren(true);
                                this->container->game1->setMouseEnabled(true); 
                                this->container->game2->setMouseChildren(true);
                                this->container->game2->setMouseEnabled(true); 
                                this->container->game3->setMouseChildren(true);
                                this->container->game3->setMouseEnabled(true);
                                this->container->game1->alpha = 1;
                                this->container->game2->alpha = 1;
                                this->container->game3->alpha = 1; 
                                this->container->setMouseChildren(true);
                                this->container->setMouseEnabled(true);
                                this->autoguidersButtons();
                            }
                        }
                    }
                }
            }
            if (this->loginFlag)
            {
                if (Main::mainClass->IDIClass.idnet)
                {
                    if (Main::mainClass->IDIClass.idnet.userData)
                    {
                        this->loginFlag = false;
                        this->page = 4; 
                        this->container->setMouseChildren(false);
                        this->container->setMouseEnabled(false);
                        this->waitCounter = 0;
                        Main::mainClass->saveBoxClass->gameSave4.data.haveSave = false;
                        Main::mainClass->saveBoxClass->gameSave5.data.haveSave = false;
                        Main::mainClass->saveBoxClass->gameSave6.data.haveSave = false;
                        Main::mainClass->IDIClass.getData(4);
                        Main::mainClass->IDIClass.getData(5);
                        Main::mainClass->IDIClass.getData(6);
                    }
                }
            }
            else if (this->loginFlag1 > 0)
            {
                if (this->question > 0 || this->page != 3)
                {
                    this->loginFlag1 = 0;
                }
                else if (Main::mainClass->IDIClass.idnet)
                {
                    if (Main::mainClass->IDIClass.idnet.userData)
                    {
                        this->question = this->loginFlag1;
                        if (this->container->game1->syncSlot)
                        {
                            this->container->game1->syncSlot->gotoAndStop(4);
                        }
                        if (this->container->game2->syncSlot)
                        {
                            this->container->game2->syncSlot->gotoAndStop(4);
                        }
                        if (this->container->game3->syncSlot)
                        {
                            this->container->game3->syncSlot->gotoAndStop(4);
                        } 
                        this->container->game1->setMouseChildren(false);
                        this->container->game1->setMouseEnabled(false); 
                        this->container->game2->setMouseChildren(false);
                        this->container->game2->setMouseEnabled(false); 
                        this->container->game3->setMouseChildren(false);
                        this->container->game3->setMouseEnabled(false);
                        this->container->game1->alpha = 0.5;
                        this->container->game2->alpha = 0.5;
                        this->container->game3->alpha = 0.5;
                        this->loginFlag1 = 0;
                    }
                }
            }
        }
        return;
    }// end function

    void StartMenu::mouseMoveHandler(cocos2d::EventMouse * e)  
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if(!event)
			return;
        string targetName = event->target->getName();
        if (param1->target->name == "backCase")
        {
            if (this->container->back->currentFrame == 1)
            {
                this->container->back->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->back->currentFrame == 2)
        {
            this->container->back->gotoAndStop(1);
        }
        if (param1->target->name == "musicCase")
        {
            if (this->container->btnMusic->currentFrame == 1 || this->container->btnMusic->currentFrame == 4)
            {
                this->container->btnMusic->gotoAndStop((this->container->btnMusic->currentFrame + 1));
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->btnMusic->currentFrame == 2 || this->container->btnMusic->currentFrame == 5)
        {
            this->container->btnMusic->gotoAndStop((this->container->btnMusic->currentFrame - 1));
        }
        if (param1->target->name == "soundCase")
        {
            if (this->container->btnSound->currentFrame == 1 || this->container->btnSound->currentFrame == 4)
            {
                this->container->btnSound->gotoAndStop((this->container->btnSound->currentFrame + 1));
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->btnSound->currentFrame == 2 || this->container->btnSound->currentFrame == 5)
        {
            this->container->btnSound->gotoAndStop((this->container->btnSound->currentFrame - 1));
        }
        if (this->container->btnY8->y8Case->mouseEnabled)
        {
            if (param1->target->name == "y8Case")
            {
                if (this->container->btnY8->currentFrame == 1)
                {
                    this->container->btnY8->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->btnY8->currentFrame == 2)
            {
                this->container->btnY8->gotoAndStop(1);
            }
        }
        if (param1->target->name == "idnetCase")
        {
            if (this->container->btnIdnet->currentFrame == 1)
            {
                this->container->btnIdnet->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->btnIdnet->currentFrame == 2)
        {
            this->container->btnIdnet->gotoAndStop(1);
        }
        if (this->container->start)
        {
            if (this->container->start->startCase->mouseEnabled)
            {
                if (param1->target->name == "startCase")
                {
                    if (this->container->start->currentFrame == 1)
                    {
                        this->container->start->gotoAndStop(2);
                        //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this->container->start->currentFrame == 2)
                {
                    this->container->start->gotoAndStop(1);
                }
                if (param1->target->name == "creditsCase")
                {
                    if (this->container->credits->currentFrame == 1)
                    {
                        this->container->credits->gotoAndStop(2);
                        //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this->container->credits->currentFrame == 2)
                {
                    this->container->credits->gotoAndStop(1);
                }
            }
        }
        else if (this->container->saveType)
        {
            if (param1->target->name == "localSaveCase")
            {
                if (this->container->saveType->localSave->currentFrame == 1)
                {
                    this->container->saveType->localSave->gotoAndStop(2);
                    this->container->saveType->setChildIndex(this->container->saveType->localSave, (this->container->saveType->numChildren - 1));
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->saveType->localSave->currentFrame == 2)
            {
                this->container->saveType->localSave->gotoAndStop(1);
            }
            if (param1->target->name == "onlineSaveCase")
            {
                if (this->container->saveType->onlineSave->currentFrame == 1)
                {
                    this->container->saveType->onlineSave->gotoAndStop(2);
                    if (this->welcomeText)
                    {
                        std::setText(this->container->saveType->onlineSave->welcomeTXT,this->welcomeText);
                        std::setText(this->container->saveType->onlineSave->nickTXT,this->nickText);
                        this->container->saveType->onlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
                    }
                    this->container->saveType->setChildIndex(this->container->saveType->onlineSave, (this->container->saveType->numChildren - 1));
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->saveType->onlineSave->currentFrame == 2)
            {
                this->container->saveType->onlineSave->gotoAndStop(1);
                if (this->welcomeText)
                {
                    std::setText(this->container->saveType->onlineSave->welcomeTXT,this->welcomeText);
                    std::setText(this->container->saveType->onlineSave->nickTXT,this->nickText);
                    this->container->saveType->onlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
                }
            }
        }
        else if (this->container->game1)
        {
            if (param1->target->name == "game1Case")
            {
                if (this->container->game1->currentFrame == 1)
                {
                    this->container->game1->gotoAndStop(2);
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->game1->currentFrame == 2)
            {
                this->container->game1->gotoAndStop(1);
            }
            if (param1->target->name == "game2Case")
            {
                if (this->container->game2->currentFrame == 1)
                {
                    this->container->game2->gotoAndStop(2);
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->game2->currentFrame == 2)
            {
                this->container->game2->gotoAndStop(1);
            }
            if (param1->target->name == "game3Case")
            {
                if (this->container->game3->currentFrame == 1)
                {
                    this->container->game3->gotoAndStop(2);
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->game3->currentFrame == 2)
            {
                this->container->game3->gotoAndStop(1);
            }
            if (param1->target->name == "newGame1Case")
            {
                if (this->container->game1->currentFrame == 4)
                {
                    this->container->game1->gotoAndStop(5);
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->game1->currentFrame == 5)
            {
                this->container->game1->gotoAndStop(4);
            }
            if (param1->target->name == "newGame2Case")
            {
                if (this->container->game2->currentFrame == 4)
                {
                    this->container->game2->gotoAndStop(5);
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->game2->currentFrame == 5)
            {
                this->container->game2->gotoAndStop(4);
            }
            if (param1->target->name == "newGame3Case")
            {
                if (this->container->game3->currentFrame == 4)
                {
                    this->container->game3->gotoAndStop(5);
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->game3->currentFrame == 5)
            {
                this->container->game3->gotoAndStop(4);
            }
            if (param1->target->name == "syncSlotCase")
            {
                if (param1.target.parent->currentFrame < 4)
                {
                    if (!this->syncHint)
                    {
                        this->syncHint = new Hint_mc();
                        this->syncHint->gotoAndStop(16);
                        if (param1.target.parent.parent.name == "game1")
                        {
                            this->syncHint.x = this->container->game1->x + this->container->game1->syncSlot->x + this->container->game1->syncSlot->syncSlotCase.x + 10;
                            this->syncHint.y = this->container->game1->y + this->container->game1->syncSlot->y + this->container->game1->syncSlot->syncSlotCase.y - 5;
                        }
                        else if (param1.target.parent.parent.name == "game2")
                        {
                            this->syncHint.x = this->container->game2->x + this->container->game2->syncSlot->x + this->container->game2->syncSlot->syncSlotCase.x + 10;
                            this->syncHint.y = this->container->game2->y + this->container->game2->syncSlot->y + this->container->game2->syncSlot->syncSlotCase.y - 5;
                        }
                        else if (param1.target.parent.parent.name == "game3")
                        {
                            this->syncHint.x = this->container->game3->x + this->container->game3->syncSlot->x + this->container->game3->syncSlot->syncSlotCase.x + 10;
                            this->syncHint.y = this->container->game3->y + this->container->game3->syncSlot->y + this->container->game3->syncSlot->syncSlotCase.y - 5;
                        }
                        var _loc_2:* = false;
                        this->syncHint.setMouseChildren(false);
                        this->syncHint.mouseEnabled = _loc_2;
                        this->addChild(this->syncHint);
                    }
                }
                if (param1.target.parent.parent.name == "game1")
                {
                    if (this->container->game1->syncSlot->currentFrame == 1 || this->container->game1->syncSlot->currentFrame == 4)
                    {
                        this->container->game1->syncSlot->gotoAndStop((this->container->game1->syncSlot->currentFrame + 1));
                        //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (param1.target.parent.parent.name == "game2")
                {
                    if (this->container->game2->syncSlot->currentFrame == 1 || this->container->game2->syncSlot->currentFrame == 4)
                    {
                        this->container->game2->syncSlot->gotoAndStop((this->container->game2->syncSlot->currentFrame + 1));
                        //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (param1.target.parent.parent.name == "game3")
                {
                    if (this->container->game3->syncSlot->currentFrame == 1 || this->container->game3->syncSlot->currentFrame == 4)
                    {
                        this->container->game3->syncSlot->gotoAndStop((this->container->game3->syncSlot->currentFrame + 1));
                        //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
            }
            else
            {
                if (this->syncHint)
                {
                    this->removeChild(this->syncHint);
                    this->syncHint = NULL;
                }
                if (this->container->game1->currentFrame < 4)
                {
                    if (this->container->game1->syncSlot->currentFrame == 2 || this->container->game1->syncSlot->currentFrame == 5)
                    {
                        this->container->game1->syncSlot->gotoAndStop((this->container->game1->syncSlot->currentFrame - 1));
                    }
                }
                if (this->container->game2->currentFrame < 4)
                {
                    if (this->container->game2->syncSlot->currentFrame == 2 || this->container->game2->syncSlot->currentFrame == 5)
                    {
                        this->container->game2->syncSlot->gotoAndStop((this->container->game2->syncSlot->currentFrame - 1));
                    }
                }
                if (this->container->game3->currentFrame < 4)
                {
                    if (this->container->game3->syncSlot->currentFrame == 2 || this->container->game3->syncSlot->currentFrame == 5)
                    {
                        this->container->game3->syncSlot->gotoAndStop((this->container->game3->syncSlot->currentFrame - 1));
                    }
                }
            }
            if (param1->target->name == "deleteSlotCase" && param1.target.parent.parent.name == "game1")
            {
                if (this->container->game1->deleteSlot->currentFrame == 1)
                {
                    this->container->game1->deleteSlot->gotoAndStop(2);
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->game1->currentFrame < 4)
            {
                if (this->container->game1->deleteSlot->currentFrame == 2)
                {
                    this->container->game1->deleteSlot->gotoAndStop(1);
                }
            }
            if (param1->target->name == "deleteSlotCase" && param1.target.parent.parent.name == "game2")
            {
                if (this->container->game2->deleteSlot->currentFrame == 1)
                {
                    this->container->game2->deleteSlot->gotoAndStop(2);
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->game2->currentFrame < 4)
            {
                if (this->container->game2->deleteSlot->currentFrame == 2)
                {
                    this->container->game2->deleteSlot->gotoAndStop(1);
                }
            }
            if (param1->target->name == "deleteSlotCase" && param1.target.parent.parent.name == "game3")
            {
                if (this->container->game3->deleteSlot->currentFrame == 1)
                {
                    this->container->game3->deleteSlot->gotoAndStop(2);
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->game3->currentFrame < 4)
            {
                if (this->container->game3->deleteSlot->currentFrame == 2)
                {
                    this->container->game3->deleteSlot->gotoAndStop(1);
                }
            }
            if (this->container->question)
            {
                if (param1->target->name == "yesCase")
                {
                    if (param1.target.parent->currentFrame == 1)
                    {
                        param1.target.parent->gotoAndStop(2);
                        //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this->container->question->btnYes->currentFrame == 2)
                {
                    this->container->question->btnYes->gotoAndStop(1);
                }
                if (param1->target->name == "noCase")
                {
                    if (param1.target.parent->currentFrame == 1)
                    {
                        param1.target.parent->gotoAndStop(2);
                        //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this->container->question->btnNo->currentFrame == 2)
                {
                    this->container->question->btnNo->gotoAndStop(1);
                }
            }
        }
        return;
    }// end function

    void StartMenu::mouseDownHandler(cocos2d::EventMouse * e)  
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if(!event)
			return;
        string targetName = event->target->getName();
        if (targetName == "backCase")
        {
            if (this->container->back->currentFrame == 2)
            {
                this->container->back->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (targetName == "musicCase")
        {
            if (this->container->btnMusic->currentFrame == 2 || this->container->btnMusic->currentFrame == 5)
            {
                this->container->btnMusic->gotoAndStop((this->container->btnMusic->currentFrame + 1));
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (targetName == "soundCase")
        {
            if (this->container->btnSound->currentFrame == 2 || this->container->btnSound->currentFrame == 5)
            {
                this->container->btnSound->gotoAndStop((this->container->btnSound->currentFrame + 1));
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (targetName == "y8Case")
        {
            if (this->container->btnY8->currentFrame == 2)
            {
                this->container->btnY8->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (targetName == "idnetCase")
        {
            if (this->container->btnIdnet->currentFrame == 2)
            {
                this->container->btnIdnet->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (targetName == "logOut")
        {
            if (Main::mainClass->IDIClass.idnet)
            {
                Main::mainClass->IDIClass.idnet.logout();
            }
        }
        if (this->container->start)
        {
            if (targetName == "startCase")
            {
                if (this->container->start->currentFrame == 2)
                {
                    this->container->start->gotoAndStop(3);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            else if (targetName == "creditsCase")
            {
                if (this->container->credits->currentFrame == 2)
                {
                    this->container->credits->gotoAndStop(3);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
        }
        else if (this->container->saveType)
        {
            if (targetName == "localSaveCase")
            {
                if (this->container->saveType->localSave->currentFrame == 2)
                {
                    this->container->saveType->localSave->gotoAndStop(3);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            else if (targetName == "onlineSaveCase")
            {
                if (this->container->saveType->onlineSave->currentFrame == 2)
                {
                    this->container->saveType->onlineSave->gotoAndStop(3);
                    if (this->welcomeText)
                    {
                        std::setText(this->container->saveType->onlineSave->welcomeTXT,this->welcomeText);
                        std::setText(this->container->saveType->onlineSave->nickTXT,this->nickText);
                        this->container->saveType->onlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
                    }
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
        }
        else if (this->container->game1)
        {
            if (targetName == "game1Case")
            {
                if (this->container->game1->currentFrame == 2)
                {
                    this->container->game1->gotoAndStop(3);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            else if (targetName == "game2Case")
            {
                if (this->container->game2->currentFrame == 2)
                {
                    this->container->game2->gotoAndStop(3);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            else if (targetName == "game3Case")
            {
                if (this->container->game3->currentFrame == 2)
                {
                    this->container->game3->gotoAndStop(3);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            else if (targetName == "newGame1Case")
            {
                if (this->container->game1->currentFrame == 5)
                {
                    this->container->game1->gotoAndStop(6);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            else if (targetName == "newGame2Case")
            {
                if (this->container->game2->currentFrame == 5)
                {
                    this->container->game2->gotoAndStop(6);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            else if (targetName == "newGame3Case")
            {
                if (this->container->game3->currentFrame == 5)
                {
                    this->container->game3->gotoAndStop(6);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            else if (targetName == "syncSlotCase")
            {
                if (event.target.parent->currentFrame == 2 || event.target.parent->currentFrame == 5)
                {
                    event.target.parent->gotoAndStop((event.target.parent->currentFrame + 1));
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            else if (targetName == "deleteSlotCase")
            {
                if (event.target.parent->currentFrame == 2)
                {
                    event.target.parent->gotoAndStop(3);
                    //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                }
            }
            if (this->container->question)
            {
                if (targetName == "yesCase")
                {
                    if (event.target.parent->currentFrame == 2)
                    {
                        event.target.parent->gotoAndStop(3);
                        //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (targetName == "noCase")
                {
                    if (event.target.parent->currentFrame == 2)
                    {
                        event.target.parent->gotoAndStop(3);
                        //Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
            }
        }
        return;
    }// end function

    void StartMenu::mouseUpHandler(cocos2d::EventMouse * e) 
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
        string targetName = event->target->getName();
        if (targetName == "backCase")
        {
            if (this->container->back->currentFrame == 3)
            {
                this->container->back->gotoAndStop(1);
                if (this->question != 0)
                {
                    this->question = -1;
                }
                else if (this->page == 2)
                {
                    this->page = 1;
                }
                else if (this->page == 3 || this->page == 4)
                {
                    this->page = 2;
                } 
                this->container->setMouseChildren(false);
                this->container->setMouseEnabled(false);
            }
        }
        else if (this->container->back->currentFrame == 3)
        {
            this->container->back->gotoAndStop(1);
        }
        if (targetName == "musicCase")
        {
            if (this->container->btnMusic->currentFrame == 3 || this->container->btnMusic->currentFrame == 6)
            {
                if (this->container->btnMusic->currentFrame == 3)
                {
                    this->container->btnMusic->gotoAndStop(5);
                    ////Sounds.instance.musicManage("off");
                }
                else if (this->container->btnMusic->currentFrame == 6)
                {
                    this->container->btnMusic->gotoAndStop(2);
                    ////Sounds.instance.musicManage("on");
                    ////Sounds.instance.playMusic(0);
                }
            }
        }
        else if (this->container->btnMusic->currentFrame == 3 || this->container->btnMusic->currentFrame == 6)
        {
            this->container->btnMusic->gotoAndStop(this->container->btnMusic->currentFrame - 2);
        }
        if (targetName == "soundCase")
        {
            if (this->container->btnSound->currentFrame == 3 || this->container->btnSound->currentFrame == 6)
            {
                if (this->container->btnSound->currentFrame == 3)
                {
                    this->container->btnSound->gotoAndStop(5);
                    ////Sounds.instance.soundManage("off");
                }
                else if (this->container->btnSound->currentFrame == 6)
                {
                    this->container->btnSound->gotoAndStop(2);
                    ////Sounds.instance.soundManage("on");
                }
            }
        }
        else if (this->container->btnSound->currentFrame == 3 || this->container->btnSound->currentFrame == 6)
        {
            this->container->btnSound->gotoAndStop(this->container->btnSound->currentFrame - 2);
        }
        if (targetName == "y8Case")
        {
            if (this->container->btnY8->currentFrame == 3)
            {
                this->container->btnY8->gotoAndStop(2);
                //navigateToURL(new URLRequest("http://www.y8.com/?utm_source=" + Main::mainClass->domainName + "&utm_medium=g_prelogo&utm_campaign=brave_heads"));
            }
        }
        else if (this->container->btnY8->currentFrame == 3)
        {
            this->container->btnY8->gotoAndStop(1);
        }
        if (targetName == "idnetCase")
        {
            if (this->container->btnIdnet->currentFrame == 3)
            {
                this->container->btnIdnet->gotoAndStop(2);
                navigateToURL(new URLRequest("http://www.id.net"));
            }
        }
        else if (this->container->btnIdnet->currentFrame == 3)
        {
            this->container->btnIdnet->gotoAndStop(1);
        }
        if (this->container->start)
        {
            if (targetName == "startCase")
            {
                if (this->container->start->currentFrame == 3)
                {
                    this->page = 2;
                    var _loc_2:* = false;
                    this->container->setMouseChildren(false);
                    this->container->mouseEnabled = _loc_2;
                }
            }
            else if (this->container->start->currentFrame == 3)
            {
                this->container->start->gotoAndStop(1);
            }
            if (targetName == "creditsCase")
            {
                if (this->container->credits->currentFrame == 3)
                {
                    this->container->credits->gotoAndStop(2);
                    this->creditsClass = new Credits();
                    this->addChild(this->creditsClass);
                }
            }
            else if (this->container->credits->currentFrame == 3)
            {
                this->container->credits->gotoAndStop(1);
            }
        }
        else if (this->container->saveType)
        {
            if (targetName == "localSaveCase")
            {
                if (this->container->saveType->localSave->currentFrame == 3)
                {
                    this->container->saveType->localSave->gotoAndStop(2);
                    this->page = 3;
                    var _loc_2:* = false;
                    this->container->setMouseChildren(false);
                    this->container->mouseEnabled = _loc_2;
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->saveType->localSave->currentFrame == 3)
            {
                this->container->saveType->localSave->gotoAndStop(1);
            }
            if (targetName == "onlineSaveCase")
            {
                if (this->container->saveType->onlineSave->currentFrame == 3)
                {
                    this->container->saveType->onlineSave->gotoAndStop(2);
                    if (this->welcomeText)
                    {
                        std::setText(this->container->saveType->onlineSave->welcomeTXT,this->welcomeText);
                        std::setText(this->container->saveType->onlineSave->nickTXT,this->nickText);
                        this->container->saveType->onlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
                    }
                    if (Main::mainClass->IDIClass.idnet)
                    {
                        if (!Main::mainClass->IDIClass.idnet.userData)
                        {
                            this->loginFlag = true;
                            Main::mainClass->IDIClass.idnet.toggleInterface();
                        }
                        else
                        {
                            this->page = 4;
                            var _loc_2:* = false;
                            this->container->setMouseChildren(false);
                            this->container->mouseEnabled = _loc_2;
                            this->waitCounter = 0;
                            Main::mainClass->saveBoxClass->gameSave4.data.haveSave = false;
                            Main::mainClass->saveBoxClass->gameSave5.data.haveSave = false;
                            Main::mainClass->saveBoxClass->gameSave6.data.haveSave = false;
                            Main::mainClass->IDIClass.getData(4);
                            Main::mainClass->IDIClass.getData(5);
                            Main::mainClass->IDIClass.getData(6);
                        }
                    }
                    //Sounds.instance.playSound("snd_menu_stoneMouseMove");
                }
            }
            else if (this->container->saveType->onlineSave->currentFrame == 3)
            {
                this->container->saveType->onlineSave->gotoAndStop(1);
                if (this->welcomeText)
                {
                    std::setText(this->container->saveType->onlineSave->welcomeTXT,this->welcomeText);
                    std::setText(this->container->saveType->onlineSave->nickTXT,this->nickText);
                    this->container->saveType->onlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
                }
            }
        }
        else if (this->container->game1)
        {
            if (targetName == "game1Case")
            {
                if (this->container->game1->currentFrame == 3)
                {
                    if (this->page == 3)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(1);
                    }
                    else if (this->page == 4)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(4);
                    }
                    Main::mainClass->addNewScreen("LevelsMenu");
                }
            }
            else if (this->container->game1->currentFrame == 3)
            {
                this->container->game1->gotoAndStop(1);
            }
            if (targetName == "game2Case")
            {
                if (this->container->game2->currentFrame == 3)
                {
                    if (this->page == 3)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(2);
                    }
                    else if (this->page == 4)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(5);
                    }
                    Main::mainClass->addNewScreen("LevelsMenu");
                }
            }
            else if (this->container->game2->currentFrame == 3)
            {
                this->container->game2->gotoAndStop(1);
            }
            if (targetName == "game3Case")
            {
                if (this->container->game3->currentFrame == 3)
                {
                    if (this->page == 3)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(3);
                    }
                    else if (this->page == 4)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(6);
                    }
                    Main::mainClass->addNewScreen("LevelsMenu");
                }
            }
            else if (this->container->game3->currentFrame == 3)
            {
                this->container->game3->gotoAndStop(1);
            }
            if (targetName == "newGame1Case")
            {
                if (this->container->game1->currentFrame == 6)
                {
                    if (this->page == 3)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(1);
                    }
                    else if (this->page == 4)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(4);
                    }
                    Main::mainClass->addNewScreen("LevelsMenu");
                }
            }
            else if (this->container->game1->currentFrame == 6)
            {
                this->container->game1->gotoAndStop(4);
            }
            if (targetName == "newGame2Case")
            {
                if (this->container->game2->currentFrame == 6)
                {
                    if (this->page == 3)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(2);
                    }
                    else if (this->page == 4)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(5);
                    }
                    Main::mainClass->addNewScreen("LevelsMenu");
                }
            }
            else if (this->container->game2->currentFrame == 6)
            {
                this->container->game2->gotoAndStop(4);
            }
            if (targetName == "newGame3Case")
            {
                if (this->container->game3->currentFrame == 6)
                {
                    if (this->page == 3)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(3);
                    }
                    else if (this->page == 4)
                    {
                        Main::mainClass->saveBoxClass->checkSaves(6);
                    }
                    Main::mainClass->addNewScreen("LevelsMenu");
                }
            }
            else if (this->container->game3->currentFrame == 6)
            {
                this->container->game3->gotoAndStop(4);
            }
            if (targetName == "syncSlotCase" && event.target.parent.parent.name == "game1")
            {
                if (this->container->game1->syncSlot->currentFrame == 3 || this->container->game1->syncSlot->currentFrame == 6)
                {
                    this->container->game1->syncSlot->gotoAndStop((this->container->game1->syncSlot->currentFrame - 1));
                    if (Main::mainClass->IDIClass.idnet)
                    {
                        if (Main::mainClass->IDIClass.idnet.userData)
                        {
                            this->question = 11; 
                            this->container->game1->setMouseChildren(false);
                            this->container->game1->setMouseEnabled(false); 
                            this->container->game2->setMouseChildren(false);
                            this->container->game2->setMouseEnabled(false); 
                            this->container->game3->setMouseChildren(false);
                            this->container->game3->setMouseEnabled(false);
                            this->container->game1->alpha = 0.5;
                            this->container->game2->alpha = 0.5;
                            this->container->game3->alpha = 0.5;
                        }
                        else
                        {
                            Main::mainClass->IDIClass.idnet.toggleInterface();
                            this->loginFlag1 = 11;
                        }
                        if (this->syncHint)
                        {
                            this->removeChild(this->syncHint);
                            this->syncHint = NULL;
                        }
                    }
                }
            }
            else if (this->container->game1->currentFrame < 4)
            {
                if (this->container->game1->syncSlot->currentFrame == 3 || this->container->game1->syncSlot->currentFrame == 6)
                {
                    this->container->game1->syncSlot->gotoAndStop(this->container->game1->syncSlot->currentFrame - 2);
                }
            }
            if (targetName == "syncSlotCase" && event.target.parent.parent.name == "game2")
            {
                if (this->container->game2->syncSlot->currentFrame == 3 || this->container->game2->syncSlot->currentFrame == 6)
                {
                    this->container->game2->syncSlot->gotoAndStop((this->container->game2->syncSlot->currentFrame - 1));
                    if (Main::mainClass->IDIClass.idnet)
                    {
                        if (Main::mainClass->IDIClass.idnet.userData)
                        {
                            this->question = 12; 
                            this->container->game1->setMouseChildren(false);
                            this->container->game1->setMouseEnabled(false); 
                            this->container->game2->setMouseChildren(false);
                            this->container->game2->setMouseEnabled(false); 
                            this->container->game3->setMouseChildren(false);
                            this->container->game3->setMouseEnabled(false);
                            this->container->game1->alpha = 0.5;
                            this->container->game2->alpha = 0.5;
                            this->container->game3->alpha = 0.5;
                        }
                        else
                        {
                            Main::mainClass->IDIClass.idnet.toggleInterface();
                            this->loginFlag1 = 12;
                        }
                        if (this->syncHint)
                        {
                            this->removeChild(this->syncHint);
                            this->syncHint = NULL;
                        }
                    }
                }
            }
            else if (this->container->game2->currentFrame < 4)
            {
                if (this->container->game2->syncSlot->currentFrame == 3 || this->container->game2->syncSlot->currentFrame == 6)
                {
                    this->container->game2->syncSlot->gotoAndStop(this->container->game2->syncSlot->currentFrame - 2);
                }
            }
            if (targetName == "syncSlotCase" && event.target.parent.parent.name == "game3")
            {
                if (this->container->game3->syncSlot->currentFrame == 3 || this->container->game3->syncSlot->currentFrame == 6)
                {
                    this->container->game3->syncSlot->gotoAndStop((this->container->game3->syncSlot->currentFrame - 1));
                    if (Main::mainClass->IDIClass.idnet)
                    {
                        if (Main::mainClass->IDIClass.idnet.userData)
                        {
                            this->question = 13; 
                            this->container->game1->setMouseChildren(false);
                            this->container->game1->setMouseEnabled(false); 
                            this->container->game2->setMouseChildren(false);
                            this->container->game2->setMouseEnabled(false); 
                            this->container->game3->setMouseChildren(false);
                            this->container->game3->setMouseEnabled(false);
                            this->container->game1->alpha = 0.5;
                            this->container->game2->alpha = 0.5;
                            this->container->game3->alpha = 0.5;
                        }
                        else
                        {
                            Main::mainClass->IDIClass.idnet.toggleInterface();
                            this->loginFlag1 = 13;
                        }
                        if (this->syncHint)
                        {
                            this->removeChild(this->syncHint);
                            this->syncHint = NULL;
                        }
                    }
                }
            }
            else if (this->container->game3->currentFrame < 4)
            {
                if (this->container->game3->syncSlot->currentFrame == 3 || this->container->game3->syncSlot->currentFrame == 6)
                {
                    this->container->game3->syncSlot->gotoAndStop(this->container->game3->syncSlot->currentFrame - 2);
                }
            }
            if (targetName == "deleteSlotCase" && event.target.parent.parent.name == "game1")
            {
                if (this->container->game1->deleteSlot->currentFrame == 3)
                {
                    this->container->game1->deleteSlot->gotoAndStop(2);
                    if (this->page == 3)
                    {
                        this->question = 1;
                    }
                    else if (this->page == 4)
                    {
                        this->question = 4;
                    } 
                    this->container->game1->setMouseChildren(false);
                    this->container->game1->setMouseEnabled(false); 
                    this->container->game2->setMouseChildren(false);
                    this->container->game2->setMouseEnabled(false); 
                    this->container->game3->setMouseChildren(false);
                    this->container->game3->setMouseEnabled(false);
                    this->container->game1->alpha = 0.5;
                    this->container->game2->alpha = 0.5;
                    this->container->game3->alpha = 0.5;
                }
            }
            else if (this->container->game1->currentFrame < 4)
            {
                if (this->container->game1->deleteSlot->currentFrame == 3)
                {
                    this->container->game1->deleteSlot->gotoAndStop(1);
                }
            }
            if (targetName == "deleteSlotCase" && event.target.parent.parent.name == "game2")
            {
                if (this->container->game2->deleteSlot->currentFrame == 3)
                {
                    this->container->game2->deleteSlot->gotoAndStop(2);
                    if (this->page == 3)
                    {
                        this->question = 2;
                    }
                    else if (this->page == 4)
                    {
                        this->question = 5;
                    } 
                    this->container->game1->setMouseChildren(false);
                    this->container->game1->setMouseEnabled(false); 
                    this->container->game2->setMouseChildren(false);
                    this->container->game2->setMouseEnabled(false); 
                    this->container->game3->setMouseChildren(false);
                    this->container->game3->setMouseEnabled(false);
                    this->container->game1->alpha = 0.5;
                    this->container->game2->alpha = 0.5;
                    this->container->game3->alpha = 0.5;
                }
            }
            else if (this->container->game2->currentFrame < 4)
            {
                if (this->container->game2->deleteSlot->currentFrame == 3)
                {
                    this->container->game2->deleteSlot->gotoAndStop(1);
                }
            }
            if (targetName == "deleteSlotCase" && event.target.parent.parent.name == "game3")
            {
                if (this->container->game3->deleteSlot->currentFrame == 3)
                {
                    this->container->game3->deleteSlot->gotoAndStop(2);
                    if (this->page == 3)
                    {
                        this->question = 3;
                    }
                    else if (this->page == 4)
                    {
                        this->question = 6;
                    } 
                    this->container->game1->setMouseChildren(false);
                    this->container->game1->setMouseEnabled(false); 
                    this->container->game2->setMouseChildren(false);
                    this->container->game2->setMouseEnabled(false); 
                    this->container->game3->setMouseChildren(false);
                    this->container->game3->setMouseEnabled(false);
                    this->container->game1->alpha = 0.5;
                    this->container->game2->alpha = 0.5;
                    this->container->game3->alpha = 0.5;
                }
            }
            else if (this->container->game3->currentFrame < 4)
            {
                if (this->container->game3->deleteSlot->currentFrame == 3)
                {
                    this->container->game3->deleteSlot->gotoAndStop(1);
                }
            }
            if (this->container->question)
            {
                if (targetName == "yesCase")
                {
                    if (event.target.parent->currentFrame == 3)
                    {
                        event.target.parent->gotoAndStop(2);
                        if (this->question == 1 || this->question == 4)
                        {
                            this->container->game1->gotoAndStop(4);
                            this->container->game1->newGame1Case->stop();
                            this->container->game1->newGame1Case->setMouseEnabled(true);
                            if (this->question == 1)
                            {
                                Main::mainClass->saveBoxClass->gameSave1.data.haveSave = false;
                            }
                            else if (this->question == 4)
                            {
                                Main::mainClass->saveBoxClass->gameSave4.data.haveSave = false;
                                Main::mainClass->IDIClass.removeData(4);
                            }
                        }
                        else if (this->question == 2 || this->question == 5)
                        {
                            this->container->game2->gotoAndStop(4);
                            this->container->game2->newGame2Case->stop();
                            this->container->game2->newGame2Case->setMouseEnabled(true);
                            if (this->question == 2)
                            {
                                Main::mainClass->saveBoxClass->gameSave2.data.haveSave = false;
                            }
                            else if (this->question == 5)
                            {
                                Main::mainClass->saveBoxClass->gameSave5.data.haveSave = false;
                                Main::mainClass->IDIClass.removeData(5);
                            }
                        }
                        else if (this->question == 3 || this->question == 6)
                        {
                            this->container->game3->gotoAndStop(4);
                            this->container->game3->newGame3Case->stop();
                            this->container->game3->newGame3Case->setMouseEnabled(true);
                            if (this->question == 3)
                            {
                                Main::mainClass->saveBoxClass->gameSave3.data.haveSave = false;
                            }
                            else if (this->question == 6)
                            {
                                Main::mainClass->saveBoxClass->gameSave6.data.haveSave = false;
                                Main::mainClass->IDIClass.removeData(6);
                            }
                        }
                        else if (this->question == 11 || this->question == 12 || this->question == 13)
                        {
                            if (this->question == 11)
                            {
                                Main::mainClass->saveBoxClass->synchronizationLocalToSite(1);
                                this->container->game1->syncSlot->gotoAndStop(7);
                            }
                            else if (this->question == 12)
                            {
                                Main::mainClass->saveBoxClass->synchronizationLocalToSite(2);
                                this->container->game2->syncSlot->gotoAndStop(7);
                            }
                            else if (this->question == 13)
                            {
                                Main::mainClass->saveBoxClass->synchronizationLocalToSite(3);
                                this->container->game3->syncSlot->gotoAndStop(7);
                            }
                        }
                        this->question = -1;
                    }
                }
                else if (this->container->question->btnYes->currentFrame == 3)
                {
                    this->container->question->btnYes->gotoAndStop(2);
                }
                if (targetName == "noCase")
                {
                    if (event.target.parent->currentFrame == 3)
                    {
                        event.target.parent->gotoAndStop(2);
                        this->question = -1;
                    }
                }
                else if (this->container->question->btnNo->currentFrame == 3)
                {
                    this->container->question->btnNo->gotoAndStop(2);
                }
            }
        }
        return;
    }// end function

    void StartMenu::autoguidersButtons()  
    {
        this->autoguidesMouse_pt = cocos2d::Point(this->mouseX, this->mouseY);
        this->autoguidesObject = NULL;
        if (this->page == 1)
        {
            this->autoguidesObject_pt = this->container->start->localToGlobal(this->container->start->startCase->getPosition());
            this->autoguidesObjectWidth = this->container->start->startCase.width / 2;
            this->autoguidesObjectHeight = this->container->start->startCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->start->startCase;
            }
            if (!this->autoguidesObject)
            {
                this->autoguidesObject_pt = this->container->credits->localToGlobal( this->container->credits->creditsCase->getPosition());
                this->autoguidesObjectWidth = this->container->credits->creditsCase.width / 2;
                this->autoguidesObjectHeight = this->container->credits->creditsCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->credits->creditsCase;
                }
            }
        }
        else if (this->page == 2)
        {
            this->autoguidesObject_pt = this->container->saveType->localSave->localToGlobal( this->container->saveType->localSave->localSaveCase->getPosition());
            this->autoguidesObjectWidth = this->container->saveType->localSave->localSaveCase.width / 2;
            this->autoguidesObjectHeight = this->container->saveType->localSave->localSaveCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->saveType->localSave->localSaveCase;
            }
            if (!this->autoguidesObject)
            {
                this->autoguidesObject_pt = this->container->saveType->onlineSave->localToGlobal( this->container->saveType->onlineSave->onlineSaveCase->getPosition());
                this->autoguidesObjectWidth = this->container->saveType->onlineSave->onlineSaveCase.width / 2;
                this->autoguidesObjectHeight = this->container->saveType->onlineSave->onlineSaveCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->saveType->onlineSave->onlineSaveCase;
                }
            }
        }
        else if (this->page == 3)
        {
            if (this->container->game1->currentFrame < 4)
            {
                this->autoguidesObject_pt = this->container->game1->localToGlobal( this->container->game1->game1Case->getPosition());
                this->autoguidesObjectWidth = this->container->game1->game1Case.width / 2;
                this->autoguidesObjectHeight = this->container->game1->game1Case.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->game1->game1Case;
                }
                if (!this->autoguidesObject)
                {
                    this->autoguidesObject_pt = this->container->game1->deleteSlot->localToGlobal( this->container->game1->deleteSlot->deleteSlotCase->getPosition());
                    this->autoguidesObjectWidth = this->container->game1->deleteSlot->deleteSlotCase.width / 2;
                    this->autoguidesObjectHeight = this->container->game1->deleteSlot->deleteSlotCase.height / 2;
                    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                    {
                        this->autoguidesObject = this->container->game1->deleteSlot->deleteSlotCase;
                    }
                }
            }
            else
            {
                this->autoguidesObject_pt = this->container->game1->localToGlobal(this->container->game1->newGame1Case->getPosition());
                this->autoguidesObjectWidth = this->container->game1->newGame1Case.width / 2;
                this->autoguidesObjectHeight = this->container->game1->newGame1Case.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->game1->newGame1Case;
                }
            }
            if (this->container->game2->currentFrame < 4)
            {
                if (!this->autoguidesObject)
                {
                    this->autoguidesObject_pt = this->container->game2->localToGlobal(this->container->game2->game2Case->getPosition());
                    this->autoguidesObjectWidth = this->container->game2->game2Case.width / 2;
                    this->autoguidesObjectHeight = this->container->game2->game2Case.height / 2;
                    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                    {
                        this->autoguidesObject = this->container->game2->game2Case;
                    }
                }
                if (!this->autoguidesObject)
                {
                    this->autoguidesObject_pt = this->container->game2->deleteSlot->localToGlobal(this->container->game2->deleteSlot->deleteSlotCase->getPosition());
                    this->autoguidesObjectWidth = this->container->game2->deleteSlot->deleteSlotCase.width / 2;
                    this->autoguidesObjectHeight = this->container->game2->deleteSlot->deleteSlotCase.height / 2;
                    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                    {
                        this->autoguidesObject = this->container->game2->deleteSlot->deleteSlotCase;
                    }
                }
            }
            else if (!this->autoguidesObject)
            {
                this->autoguidesObject_pt = this->container->game2->localToGlobal(this->container->game2->newGame2Case->getPosition());
                this->autoguidesObjectWidth = this->container->game2->newGame2Case.width / 2;
                this->autoguidesObjectHeight = this->container->game2->newGame2Case.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->game2->newGame2Case;
                }
            }
            if (this->container->game3->currentFrame < 4)
            {
                if (!this->autoguidesObject)
                {
                    this->autoguidesObject_pt = this->container->game3->localToGlobal(this->container->game3->game3Case->getPosition());
                    this->autoguidesObjectWidth = this->container->game3->game3Case.width / 2;
                    this->autoguidesObjectHeight = this->container->game3->game3Case.height / 2;
                    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                    {
                        this->autoguidesObject = this->container->game3->game3Case;
                    }
                }
                if (!this->autoguidesObject)
                {
                    this->autoguidesObject_pt = this->container->game3->deleteSlot->localToGlobal(this->container->game3->deleteSlot->deleteSlotCase->getPosition());
                    this->autoguidesObjectWidth = this->container->game3->deleteSlot->deleteSlotCase.width / 2;
                    this->autoguidesObjectHeight = this->container->game3->deleteSlot->deleteSlotCase.height / 2;
                    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                    {
                        this->autoguidesObject = this->container->game3->deleteSlot->deleteSlotCase;
                    }
                }
            }
            else if (!this->autoguidesObject)
            {
                this->autoguidesObject_pt = this->container->game3->localToGlobal(this->container->game3->newGame3Case->getPosition());
                this->autoguidesObjectWidth = this->container->game3->newGame3Case.width / 2;
                this->autoguidesObjectHeight = this->container->game3->newGame3Case.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->game3->newGame3Case;
                }
            }
            if (this->container->question)
            {
                if (!this->autoguidesObject)
                {
                    this->autoguidesObject_pt = this->container->question->btnYes->localToGlobal(this->container->question->btnYes->yesCase->getPosition());
                    this->autoguidesObjectWidth = this->container->question->btnYes->yesCase.width / 2;
                    this->autoguidesObjectHeight = this->container->question->btnYes->yesCase.height / 2;
                    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                    {
                        this->autoguidesObject = this->container->question->btnYes->yesCase;
                    }
                }
                if (!this->autoguidesObject)
                {
                    this->autoguidesObject_pt = this->container->question->btnNo->localToGlobal(this->container->question->btnNo->noCase->getPosition());
                    this->autoguidesObjectWidth = this->container->question->btnNo->noCase.width / 2;
                    this->autoguidesObjectHeight = this->container->question->btnNo->noCase.height / 2;
                    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                    {
                        this->autoguidesObject = this->container->question->btnNo->noCase;
                    }
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->back->visible)
            {
                this->autoguidesObject_pt = this->container->back->localToGlobal(this->container->back->backCase.x, this->container->back->backCase.y));
                this->autoguidesObjectWidth = this->container->back->backCase.width / 2;
                this->autoguidesObjectHeight = this->container->back->backCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->back->backCase;
                }
            }
        }
        if (this->autoguidesObject)
        {
            tempObject = new Object();
            tempObject.target = this->autoguidesObject;
            this->mouseMoveHandler(tempObject);
        }
        return;
    }// end function

    void StartMenu::manageListeners(param1:String)  
    {
        if (param1 == "on")
        {
            //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
            //this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
            //this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
            //this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        }
        else if (param1 == "off")
        {
            //this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
            //this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
            //this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
            //this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        }
        return;
    }// end function

    //void StartMenu::reInit(event:Event)  
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    return;
    //}// end function

}
 
