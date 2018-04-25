
#include "LevelsMenu.h"
#include "MainClass.h"

namespace screens
{


    LevelsMenu::LevelsMenu() :frameCounter(0), newLevel(0), newStarsForLevel(0)
    {
        //this->listOfLevels = [];
        //this->listOfAnimation = [];
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool LevelsMenu::init()
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        if (Main::mainClass->saveBoxClass->getIntValue("newLevel") > 0)
        {
            this->newLevel = Main::mainClass->saveBoxClass->getIntValue("newLevel");
            this->roadOff = false;
        }
        if (Main::mainClass->saveBoxClass->getIntValue("newStarsForLevel") > 0)
        {
            this->newStarsForLevel = Main::mainClass->saveBoxClass->getIntValue("newStarsForLevel");
        }
        this->container = new LevelsMenu_mc();
        this->container->stop();
        this->container->back->stop();
        this->container->back->backCase->stop();
        this->container->upgrades->stop();
        this->container->upgrades->upgradesCase1->stop();
        this->container->upgrades->upgradesCase2->stop();
        this->container->book->stop();
        this->container->book->bookCase1->stop();
        this->container->book->bookCase2->stop();
        this->container->achieves->stop();
        this->container->achieves->achievesCase1->stop();
        this->container->achieves->achievesCase2->stop();
        this->container->back->backCase->buttonMode = true;
        this->container->upgrades->upgradesCase1->buttonMode = true;
        this->container->upgrades->upgradesCase2->buttonMode = true;
        this->container->book->bookCase1->buttonMode = true;
        this->container->book->bookCase2->buttonMode = true;
        this->container->achieves->achievesCase1->buttonMode = true;
        this->container->achieves->achievesCase2->buttonMode = true;
        this->container->wavesAnimation->stop();
        this->tempObject1 = this->container->wavesAnimation->numChildren;
        this->i = 0;
        while (this->i < this->tempObject1)
        {
            this->tempObject = this->container->wavesAnimation->getChildAt(this->i);
            this->tempObject->gotoAndStop((std::round(std::random() * (this->tempObject->totalFrames - 1)) + 1));
            this->listOfAnimation->push(this->tempObject);
            i++;
        }
        this->listOfLevels->push(this->container->level1);
        this->listOfLevels->push(this->container->level2);
        this->listOfLevels->push(this->container->level3);
        this->listOfLevels->push(this->container->level4);
        this->listOfLevels->push(this->container->level5);
        this->listOfLevels->push(this->container->level6);
        this->listOfLevels->push(this->container->level7);
        this->listOfLevels->push(this->container->level8);
        this->listOfLevels->push(this->container->level9);
        this->listOfLevels->push(this->container->level10);
        this->listOfLevels->push(this->container->level11);
        this->listOfLevels->push(this->container->level12);
        this->listOfLevels->push(this->container->level13);
        this->listOfLevels->push(this->container->level14);
        this->listOfLevels->push(this->container->level15);
        this->preparationLevels();
        this->container->btnMusic->stop();
        this->container->btnSound->stop();
        this->container->btnMusic->musicCase->buttonMode = true;
        this->container->btnSound->soundCase->buttonMode = true;
        this->container->freeStars->stop();
        this->container->freeStars->cont->stop();
        this->container->freeStars->mouseChildren = false;
        this->container->freeStars->mouseEnabled = false;
        if (Main::mainClass->saveBoxClass->getIntValue("stars") == 0)
        {
            this->container->freeStars->setVisible(false);
        }
        this->addChild(this->container);
        //if (Sounds.instance.musicOn)
        //{
        //    this->container->btnMusic->gotoAndStop(1);
        //}
        //else
        //{
        //    this->container->btnMusic->gotoAndStop(4);
        //}
        //if (Sounds.instance.soundOn)
        //{
        //    this->container->btnSound->gotoAndStop(1);
        //}
        //else
        //{
        //    this->container->btnSound->gotoAndStop(4);
        //}
        if (!Main::mainClass->saveBoxClass->getBoolValue("difficultyLevel"))
        {
            this->container->mouseChildren = false;
            this->container->mouseEnabled = false;
        }
        //if (Main::mainClass->saveBoxClass.gameSave.data.training_9 == 1)
        //{
        //    Main::mainClass->saveBoxClass.gameSave.data.training_9 = 2;
        //    this->training_9 = new Training_9();
        //    this->addChild(this->training_9);
        //}
        //if (Main::mainClass->saveBoxClass.gameSave.data.training_91 > 0)
        //{
        //    training_91 = new Training_91(Main::mainClass->saveBoxClass.gameSave.data.training_91);
        //    this->addChild(training_91);
        //    Main::mainClass->saveBoxClass.gameSave.data.training_91 = -1;
        //}
        return;
    }// end function

    void LevelsMenu::enterFrameHandler(cocos2d::Event * event)
    {
        if (this->frameCounter < 30)
        {
            this->frameCounter++;
        }
        else
        {
            this->frameCounter = 1;
        }
        if (!this->firstMusicPlay)
        {
            if (this->frameCounter == 8)
            {
                if (!Main::mainClass->saveBoxClass->getBoolValue("difficultyLevel"))
                {
                    this->difficultyLevel = new DifficultyLevel();
                    this->addChild(this->difficultyLevel);
                }
                else
                {
                    this->firstMusicPlay = true;
                    //if (Sounds.instance.nowMusic != 0)
                    //{
                    //    Sounds.instance.playMusic(0);
                    //}
                }
            }
        }
        if (this->container->freeStars->isVisible())
        {
            if (this->container->freeStars->currentFrame < this->container->freeStars->totalFrames)
            {
                this->container->freeStars->gotoAndStop((this->container->freeStars->currentFrame + 1));
            }
            else
            {
                this->container->freeStars->gotoAndStop(11);
            }
            if (this->container->freeStars->cont->currentFrame < this->container->freeStars->cont->totalFrames)
            {
                this->container->freeStars->cont->gotoAndStop((this->container->freeStars->cont->currentFrame + 1));
            }
            else
            {
                this->container->freeStars->cont->gotoAndStop(1);
            }
            this->container->freeStars->cont->starsTXT->setText(Main::mainClass->saveBoxClass->getString("stars"));
            //this->container->freeStars->cont->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
        }
        if (this->newLevel > 0 && this->container->mouseEnabled)
        {
            this->openNewLevel();
        }
        if (this->newStarsForLevel > 0)
        {
            this->openNewStarsForLevel();
        }
        if (this->container->upgrades->currentFrame != this->container->upgrades->totalFrames)
        {
            if (this->mouseMoveTarget == this->container->upgrades)
            {
                if (this->container->upgrades->currentFrame < (this->container->upgrades->totalFrames - 1))
                {
                    this->container->upgrades->gotoAndStop((this->container->upgrades->currentFrame + 1));
                }
            }
            else if (this->container->upgrades->currentFrame > 1)
            {
                if (this->container->upgrades->currentFrame > 6)
                {
                    this->container->upgrades->gotoAndStop(6);
                }
                else
                {
                    this->container->upgrades->gotoAndStop((this->container->upgrades->currentFrame - 1));
                }
            }
            if (this->container->upgrades->fireCont)
            {
                if (this->container->upgrades->fireCont->currentFrame < this->container->upgrades->fireCont->totalFrames)
                {
                    this->container->upgrades->fireCont->gotoAndStop((this->container->upgrades->fireCont->currentFrame + 1));
                }
                else
                {
                    this->container->upgrades->fireCont->gotoAndStop(1);
                }
            }
        }
        if (this->container->book->currentFrame != this->container->book->totalFrames)
        {
            if (this->mouseMoveTarget == this->container->book)
            {
                if (this->container->book->currentFrame < (this->container->book->totalFrames - 1))
                {
                    this->container->book->gotoAndStop((this->container->book->currentFrame + 1));
                }
            }
            else if (this->container->book->currentFrame > 1)
            {
                this->container->book->gotoAndStop((this->container->book->currentFrame - 1));
            }
        }
        if (this->container->achieves->currentFrame != this->container->achieves->totalFrames)
        {
            if (this->mouseMoveTarget == this->container->achieves)
            {
                if (this->container->achieves->currentFrame < (this->container->achieves->totalFrames - 1))
                {
                    this->container->achieves->gotoAndStop((this->container->achieves->currentFrame + 1));
                }
            }
            else if (this->container->achieves->currentFrame > 1)
            {
                this->container->achieves->gotoAndStop((this->container->achieves->currentFrame - 1));
            }
        }
        if (this->frameCounter / 2 is int)
        {
            this->i = 0;
            while (this->i < this->listOfAnimation.size())
            {
                if (this->listOfAnimation[this->i]->currentFrame < this->listOfAnimation[this->i]->totalFrames)
                {
                    this->listOfAnimation[this->i]->gotoAndStop((this->listOfAnimation[this->i]->currentFrame + 1));
                }
                else
                {
                    this->listOfAnimation[this->i]->gotoAndStop(1);
                }
                i++;
            }
        }
        return;
    }// end function

    void LevelsMenu::mouseMoveHandler(cocos2d::Event * param1)
    {
        if (this->mouseMoveTarget)
        {
            this->mouseMoveTarget = NULL;
        }
        if (param1.target.name == "musicCase")
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
        if (param1.target.name == "soundCase")
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
        if (param1.target.name == "backCase")
        {
            this->mouseMoveTarget = param1.target.parent;
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
        if (param1.target.name == "upgradesCase1" || param1.target.name == "upgradesCase2")
        {
            this->mouseMoveTarget = param1.target.parent;
            if (!this->container->upgrades->mouseMoveFlag)
            {
                this->container->upgrades->mouseMoveFlag = true;
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->upgrades->mouseMoveFlag)
        {
            this->container->upgrades->mouseMoveFlag = false;
        }
        if (param1.target.name == "bookCase1" || param1.target.name == "bookCase2")
        {
            this->mouseMoveTarget = param1.target.parent;
            if (!this->container->book->mouseMoveFlag)
            {
                this->container->book->mouseMoveFlag = true;
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->book->mouseMoveFlag)
        {
            this->container->book->mouseMoveFlag = false;
        }
        if (param1.target.name == "achievesCase1" || param1.target.name == "achievesCase2")
        {
            this->mouseMoveTarget = param1.target.parent;
            if (!this->container->achieves->mouseMoveFlag)
            {
                this->container->achieves->mouseMoveFlag = true;
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->achieves->mouseMoveFlag)
        {
            this->container->achieves->mouseMoveFlag = false;
        }
        if (param1.target.name == "levelCase")
        {
            if (param1.target.parent->currentFrame == 1 || param1.target.parent->currentFrame == 5 || param1.target.parent->currentFrame == 8)
            {
                param1.target->parent->gotoAndStop((param1.target.parent->currentFrame + 1));
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else
        {
            if (this->container->level1->currentFrame == 2 || this->container->level1->currentFrame == 6 || this->container->level1->currentFrame == 9)
            {
                this->container->level1->gotoAndStop((this->container->level1->currentFrame - 1));
            }
            if (this->container->level2->currentFrame == 2 || this->container->level2->currentFrame == 6 || this->container->level2->currentFrame == 9)
            {
                this->container->level2->gotoAndStop((this->container->level2->currentFrame - 1));
            }
            if (this->container->level3->currentFrame == 2 || this->container->level3->currentFrame == 6 || this->container->level3->currentFrame == 9)
            {
                this->container->level3->gotoAndStop((this->container->level3->currentFrame - 1));
            }
            if (this->container->level4->currentFrame == 2 || this->container->level4->currentFrame == 6 || this->container->level4->currentFrame == 9)
            {
                this->container->level4->gotoAndStop((this->container->level4->currentFrame - 1));
            }
            if (this->container->level5->currentFrame == 2 || this->container->level5->currentFrame == 6 || this->container->level5->currentFrame == 9)
            {
                this->container->level5->gotoAndStop((this->container->level5->currentFrame - 1));
            }
            if (this->container->level6->currentFrame == 2 || this->container->level6->currentFrame == 6 || this->container->level6->currentFrame == 9)
            {
                this->container->level6->gotoAndStop((this->container->level6->currentFrame - 1));
            }
            if (this->container->level7->currentFrame == 2 || this->container->level7->currentFrame == 6 || this->container->level7->currentFrame == 9)
            {
                this->container->level7->gotoAndStop((this->container->level7->currentFrame - 1));
            }
            if (this->container->level8->currentFrame == 2 || this->container->level8->currentFrame == 6 || this->container->level8->currentFrame == 9)
            {
                this->container->level8->gotoAndStop((this->container->level8->currentFrame - 1));
            }
            if (this->container->level9->currentFrame == 2 || this->container->level9->currentFrame == 6 || this->container->level9->currentFrame == 9)
            {
                this->container->level9->gotoAndStop((this->container->level9->currentFrame - 1));
            }
            if (this->container->level10->currentFrame == 2 || this->container->level10->currentFrame == 6 || this->container->level10->currentFrame == 9)
            {
                this->container->level10->gotoAndStop((this->container->level10->currentFrame - 1));
            }
            if (this->container->level11->currentFrame == 2 || this->container->level11->currentFrame == 6 || this->container->level11->currentFrame == 9)
            {
                this->container->level11->gotoAndStop((this->container->level11->currentFrame - 1));
            }
            if (this->container->level12->currentFrame == 2 || this->container->level12->currentFrame == 6 || this->container->level12->currentFrame == 9)
            {
                this->container->level12->gotoAndStop((this->container->level12->currentFrame - 1));
            }
            if (this->container->level13->currentFrame == 2 || this->container->level13->currentFrame == 6 || this->container->level13->currentFrame == 9)
            {
                this->container->level13->gotoAndStop((this->container->level13->currentFrame - 1));
            }
            if (this->container->level14->currentFrame == 2 || this->container->level14->currentFrame == 6 || this->container->level14->currentFrame == 9)
            {
                this->container->level14->gotoAndStop((this->container->level14->currentFrame - 1));
            }
            if (this->container->level15->currentFrame == 2 || this->container->level15->currentFrame == 6 || this->container->level15->currentFrame == 9)
            {
                this->container->level15->gotoAndStop((this->container->level15->currentFrame - 1));
            }
        }
        return;
    }// end function

    void LevelsMenu::mouseDownHandler(cocos2d::Event * event)
    {
        if (this->mouseDownTarget)
        {
            this->mouseDownTarget = null;
        }
        if (event.target.name == "musicCase")
        {
            if (this->container->btnMusic->currentFrame == 2 || this->container->btnMusic->currentFrame == 5)
            {
                this->container->btnMusic->gotoAndStop((this->container->btnMusic->currentFrame + 1));
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event.target.name == "soundCase")
        {
            if (this->container->btnSound->currentFrame == 2 || this->container->btnSound->currentFrame == 5)
            {
                this->container->btnSound->gotoAndStop((this->container->btnSound->currentFrame + 1));
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event.target.name == "backCase")
        {
            this->mouseDownTarget = event.target.parent;
            if (this->container->back->currentFrame == 2)
            {
                this->container->back->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event.target.name == "upgradesCase1" || event.target.name == "upgradesCase2")
        {
            this->mouseDownTarget = event.target.parent;
            if (this->container->upgrades->currentFrame != this->container->upgrades.totalFrames)
            {
                this->container->upgrades->gotoAndStop(this->container->upgrades.totalFrames);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event.target.name == "bookCase1" || event.target.name == "bookCase2")
        {
            this->mouseDownTarget = event.target.parent;
            if (this->container->book->currentFrame != this->container->book.totalFrames)
            {
                this->container->book->gotoAndStop(this->container->book.totalFrames);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event.target.name == "achievesCase1" || event.target.name == "achievesCase2")
        {
            this->mouseDownTarget = event.target.parent;
            if (this->container->achieves->currentFrame != this->container->achieves.totalFrames)
            {
                this->container->achieves->gotoAndStop(this->container->achieves.totalFrames);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event.target.name == "levelCase")
        {
            this->mouseDownTarget = event.target.parent;
            if (event.target.parent->currentFrame == 2 || event.target.parent->currentFrame == 6 || event.target.parent->currentFrame == 9)
            {
                event.target.parent->gotoAndStop((event.target.parent->currentFrame + 1));
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        return;
    }// end function

    void LevelsMenu::mouseUpHandler(cocos2d::Event * event)
    {
        if (this->mouseDownTarget)
        {
            this->mouseDownTarget = null;
        }
        if (event.target.name == "musicCase")
        {
            if (this->container->btnMusic->currentFrame == 3 || this->container->btnMusic->currentFrame == 6)
            {
                if (this->container->btnMusic->currentFrame == 3)
                {
                    this->container->btnMusic->gotoAndStop(5);
                    Sounds.instance.musicManage("off");
                }
                else if (this->container->btnMusic->currentFrame == 6)
                {
                    this->container->btnMusic->gotoAndStop(2);
                    //Sounds.instance.musicManage("on");
                    //Sounds.instance.playMusic(0);
                }
            }
        }
        else if (this->container->btnMusic->currentFrame == 3 || this->container->btnMusic->currentFrame == 6)
        {
            this->container->btnMusic->gotoAndStop(this->container->btnMusic->currentFrame - 2);
        }
        if (event.target.name == "soundCase")
        {
            if (this->container->btnSound->currentFrame == 3 || this->container->btnSound->currentFrame == 6)
            {
                if (this->container->btnSound->currentFrame == 3)
                {
                    this->container->btnSound->gotoAndStop(5);
                    //Sounds.instance.soundManage("off");
                }
                else if (this->container->btnSound->currentFrame == 6)
                {
                    this->container->btnSound->gotoAndStop(2);
                    //Sounds.instance.soundManage("on");
                }
            }
        }
        else if (this->container->btnSound->currentFrame == 3 || this->container->btnSound->currentFrame == 6)
        {
            this->container->btnSound->gotoAndStop(this->container->btnSound->currentFrame - 2);
        }
        if (event.target.name == "backCase")
        {
            if (this->container->back->currentFrame == 3)
            {
                this->container->back->gotoAndStop(2);
                Main::mainClass->addNewScreen("StartMenu");
            }
        }
        else if (this->container->back->currentFrame == 3)
        {
            this->container->back->gotoAndStop(1);
        }
        if (event.target.name == "upgradesCase1" || event.target.name == "upgradesCase2")
        {
            this->mouseMoveTarget = null;
            this->mouseDownTarget = null;
            this->container->upgrades.moveFlag = false;
            this->container->upgrades->gotoAndStop(this->container->upgrades.totalFrames);
            this->upgradesClass = new Upgrades();
            this->addChild(this->upgradesClass);
        }
        else if (this->container->upgrades->currentFrame == this->container->upgrades.totalFrames)
        {
            this->container->upgrades->gotoAndStop((this->container->upgrades.totalFrames - 1));
        }
        if (event.target.name == "bookCase1" || event.target.name == "bookCase2")
        {
            this->mouseMoveTarget = null;
            this->mouseDownTarget = null;
            this->container->book.moveFlag = false;
            this->container->book->gotoAndStop(this->container->book.totalFrames);
            this->encyclopediaClass = new Encyclopedia();
            this->addChild(this->encyclopediaClass);
        }
        else if (this->container->book->currentFrame == this->container->book.totalFrames)
        {
            this->container->book->gotoAndStop((this->container->book.totalFrames - 1));
        }
        if (event.target.name == "achievesCase1" || event.target.name == "achievesCase2")
        {
            this->mouseMoveTarget = null;
            this->mouseDownTarget = null;
            this->container->achieves.moveFlag = false;
            this->container->achieves->gotoAndStop(this->container->achieves.totalFrames);
            this->achievementsClass = new Achievements();
            this->addChild(this->achievementsClass);
        }
        else if (this->container->achieves->currentFrame == this->container->achieves.totalFrames)
        {
            this->container->achieves->gotoAndStop((this->container->achieves.totalFrames - 1));
        }
        if (event.target.name == "levelCase")
        {
            if (event.target.parent->currentFrame == 3 || event.target.parent->currentFrame == 7 || event.target.parent->currentFrame == 10)
            {
                if (event.target.parent.name == "level1")
                {
                    this->openLevel = new OpenLevel(1);
                }
                else if (event.target.parent.name == "level2")
                {
                    this->openLevel = new OpenLevel(2);
                }
                else if (event.target.parent.name == "level3")
                {
                    this->openLevel = new OpenLevel(3);
                }
                else if (event.target.parent.name == "level4")
                {
                    this->openLevel = new OpenLevel(4);
                }
                else if (event.target.parent.name == "level5")
                {
                    this->openLevel = new OpenLevel(5);
                }
                else if (event.target.parent.name == "level6")
                {
                    this->openLevel = new OpenLevel(6);
                }
                else if (event.target.parent.name == "level7")
                {
                    this->openLevel = new OpenLevel(7);
                }
                else if (event.target.parent.name == "level8")
                {
                    this->openLevel = new OpenLevel(8);
                }
                else if (event.target.parent.name == "level9")
                {
                    this->openLevel = new OpenLevel(9);
                }
                else if (event.target.parent.name == "level10")
                {
                    this->openLevel = new OpenLevel(10);
                }
                else if (event.target.parent.name == "level11")
                {
                    this->openLevel = new OpenLevel(11);
                }
                else if (event.target.parent.name == "level12")
                {
                    this->openLevel = new OpenLevel(12);
                }
                else if (event.target.parent.name == "level13")
                {
                    this->openLevel = new OpenLevel(13);
                }
                else if (event.target.parent.name == "level14")
                {
                    this->openLevel = new OpenLevel(14);
                }
                else if (event.target.parent.name == "level15")
                {
                    this->openLevel = new OpenLevel(15);
                }
                this->addChild(this->openLevel);
            }
        }
        if (this->container->level1->currentFrame == 3 || this->container->level1->currentFrame == 7 || this->container->level1->currentFrame == 10)
        {
            this->container->level1->gotoAndStop(this->container->level1->currentFrame - 2);
        }
        if (this->container->level2->currentFrame == 3 || this->container->level2->currentFrame == 7 || this->container->level2->currentFrame == 10)
        {
            this->container->level2->gotoAndStop(this->container->level2->currentFrame - 2);
        }
        if (this->container->level3->currentFrame == 3 || this->container->level3->currentFrame == 7 || this->container->level3->currentFrame == 10)
        {
            this->container->level3->gotoAndStop(this->container->level3->currentFrame - 2);
        }
        if (this->container->level4->currentFrame == 3 || this->container->level4->currentFrame == 7 || this->container->level4->currentFrame == 10)
        {
            this->container->level4->gotoAndStop(this->container->level4->currentFrame - 2);
        }
        if (this->container->level5->currentFrame == 3 || this->container->level5->currentFrame == 7 || this->container->level5->currentFrame == 10)
        {
            this->container->level5->gotoAndStop(this->container->level5->currentFrame - 2);
        }
        if (this->container->level6->currentFrame == 3 || this->container->level6->currentFrame == 7 || this->container->level6->currentFrame == 10)
        {
            this->container->level6->gotoAndStop(this->container->level6->currentFrame - 2);
        }
        if (this->container->level7->currentFrame == 3 || this->container->level7->currentFrame == 7 || this->container->level7->currentFrame == 10)
        {
            this->container->level7->gotoAndStop(this->container->level7->currentFrame - 2);
        }
        if (this->container->level8->currentFrame == 3 || this->container->level8->currentFrame == 7 || this->container->level8->currentFrame == 10)
        {
            this->container->level8->gotoAndStop(this->container->level8->currentFrame - 2);
        }
        if (this->container->level9->currentFrame == 3 || this->container->level9->currentFrame == 7 || this->container->level9->currentFrame == 10)
        {
            this->container->level9->gotoAndStop(this->container->level9->currentFrame - 2);
        }
        if (this->container->level10->currentFrame == 3 || this->container->level10->currentFrame == 7 || this->container->level10->currentFrame == 10)
        {
            this->container->level10->gotoAndStop(this->container->level10->currentFrame - 2);
        }
        if (this->container->level11->currentFrame == 3 || this->container->level11->currentFrame == 7 || this->container->level11->currentFrame == 10)
        {
            this->container->level11->gotoAndStop(this->container->level11->currentFrame - 2);
        }
        if (this->container->level12->currentFrame == 3 || this->container->level12->currentFrame == 7 || this->container->level12->currentFrame == 10)
        {
            this->container->level12->gotoAndStop(this->container->level12->currentFrame - 2);
        }
        if (this->container->level13->currentFrame == 3 || this->container->level13->currentFrame == 7 || this->container->level13->currentFrame == 10)
        {
            this->container->level13->gotoAndStop(this->container->level13->currentFrame - 2);
        }
        if (this->container->level14->currentFrame == 3 || this->container->level14->currentFrame == 7 || this->container->level14->currentFrame == 10)
        {
            this->container->level14->gotoAndStop(this->container->level14->currentFrame - 2);
        }
        if (this->container->level15->currentFrame == 3 || this->container->level15->currentFrame == 7 || this->container->level15->currentFrame == 10)
        {
            this->container->level15->gotoAndStop(this->container->level15->currentFrame - 2);
        }
        return;
    }// end function

    void LevelsMenu::preparationLevels()
    {
        this->container->road->stop();
        if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[14] == 1)
        {
            if (this->newLevel != 15)
            {
                this->container->road->gotoAndStop(179);
            }
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[13] == 1)
        {
            if (this->newLevel != 14)
            {
                this->container->road->gotoAndStop(164);
            }
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[12] == 1)
        {
            if (this->newLevel != 13)
            {
                this->container->road->gotoAndStop(153);
            }
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[11] == 1)
        {
            if (this->newLevel != 12)
            {
                this->container->road->gotoAndStop(144);
            }
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[10] == 1)
        {
            if (this->newLevel != 11)
            {
                this->container->road->gotoAndStop(136);
            }
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[9] == 1)
        {
            if (this->newLevel != 10)
            {
                this->container->road->gotoAndStop(127);
            }
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[8] == 1)
        {
            if (this->newLevel != 9)
            {
                this->container->road->gotoAndStop(115);
            }
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[7] == 1)
        {
            if (this->newLevel != 8)
            {
                this->container->road->gotoAndStop(104);
            }
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[6] == 1)
        {
            if (this->newLevel != 7)
            {
                this->container->road->gotoAndStop(92);
            }
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[5] == 1)
        {
            if (this->newLevel != 6)
            {
                this->container->road->gotoAndStop(80);
            }
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[4] == 1)
        {
            if (this->newLevel != 5)
            {
                this->container->road->gotoAndStop(66);
            }
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[3] == 1)
        {
            if (this->newLevel != 4)
            {
                this->container->road->gotoAndStop(55);
            }
            this->container->level5->setVisible(false);
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[2] == 1)
        {
            if (this->newLevel != 3)
            {
                this->container->road->gotoAndStop(41);
            }
            this->container->level4->setVisible(false);
            this->container->level5->setVisible(false);
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[1] == 1)
        {
            if (this->newLevel != 2)
            {
                this->container->road->gotoAndStop(26);
            }
            this->container->level3->setVisible(false);
            this->container->level4->setVisible(false);
            this->container->level5->setVisible(false);
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        else if (Main::mainClass->saveBoxClass.gameSave.data.openLevels[0] == 1)
        {
            if (this->newLevel != 1)
            {
                this->container->road->gotoAndStop(12);
            }
            this->container->level2->setVisible(false);
            this->container->level3->setVisible(false);
            this->container->level4->setVisible(false);
            this->container->level5->setVisible(false);
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        this->i = 0;
        while (this->i < 15)
        {

            if (this->listOfLevels[this->i].visible && (this->i + 1) != this->newLevel && (this->i + 1) != this->newStarsForLevel)
            {
                if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[this->i] > 0)
                {
                    this->listOfLevels[this->i]->gotoAndStop(5);
                    this->listOfLevels[this->i].wreath->stop();
                    this->listOfLevels[this->i].star1->stop();
                    this->listOfLevels[this->i].star2->stop();
                    this->listOfLevels[this->i].star3->stop();
                    this->listOfLevels[this->i].wreath->setVisible(false);
                    this->listOfLevels[this->i].star1->setVisible(false);
                    this->listOfLevels[this->i].star2->setVisible(false);
                    this->listOfLevels[this->i].star3->setVisible(false);
                    if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[this->i] >= 1)
                    {
                        this->listOfLevels[this->i].star1.visible = true;
                        this->listOfLevels[this->i].star1->gotoAndStop(this->listOfLevels[this->i].star1.totalFrames);
                    }
                    if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[this->i] >= 2)
                    {
                        this->listOfLevels[this->i].star2.visible = true;
                        this->listOfLevels[this->i].star2->gotoAndStop(this->listOfLevels[this->i].star2.totalFrames);
                    }
                    if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[this->i] >= 3)
                    {
                        this->listOfLevels[this->i].star3.visible = true;
                        this->listOfLevels[this->i].star3->gotoAndStop(this->listOfLevels[this->i].star3.totalFrames);
                    }
                    if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[this->i] == 4)
                    {
                        this->listOfLevels[this->i]->gotoAndStop(8);
                        this->listOfLevels[this->i].levelCase->stop();
                        this->listOfLevels[this->i].levelCase.buttonMode = true;
                    }
                }
            }
            else if ((this->i + 1) == this->newLevel)
            {
                if (this->newLevel == 1)
                {
                    this->container->road->gotoAndStop(1);
                }
                else if (this->newLevel == 2)
                {
                    this->container->road->gotoAndStop(12);
                }
                else if (this->newLevel == 3)
                {
                    this->container->road->gotoAndStop(26);
                }
                else if (this->newLevel == 4)
                {
                    this->container->road->gotoAndStop(41);
                }
                else if (this->newLevel == 5)
                {
                    this->container->road->gotoAndStop(55);
                }
                else if (this->newLevel == 6)
                {
                    this->container->road->gotoAndStop(66);
                }
                else if (this->newLevel == 7)
                {
                    this->container->road->gotoAndStop(80);
                }
                else if (this->newLevel == 8)
                {
                    this->container->road->gotoAndStop(92);
                }
                else if (this->newLevel == 9)
                {
                    this->container->road->gotoAndStop(104);
                }
                else if (this->newLevel == 10)
                {
                    this->container->road->gotoAndStop(115);
                }
                else if (this->newLevel == 11)
                {
                    this->container->road->gotoAndStop(127);
                }
                else if (this->newLevel == 12)
                {
                    this->container->road->gotoAndStop(136);
                }
                else if (this->newLevel == 13)
                {
                    this->container->road->gotoAndStop(144);
                }
                else if (this->newLevel == 14)
                {
                    this->container->road->gotoAndStop(153);
                }
                else if (this->newLevel == 15)
                {
                    this->container->road->gotoAndStop(164);
                }
                this->listOfLevels[this->i]->setVisible(false);
            }
            else if ((this->i + 1) == this->newStarsForLevel)
            {
                if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[this->i] < 4)
                {
                    this->listOfLevels[this->i]->gotoAndStop(4);
                    this->listOfLevels[this->i].towerEffect->stop();
                    this->listOfLevels[this->i].star1->stop();
                    this->listOfLevels[this->i].star2->stop();
                    this->listOfLevels[this->i].star3->stop();
                    this->listOfLevels[this->i].star1->setVisible(false);
                    this->listOfLevels[this->i].star2->setVisible(false);
                    this->listOfLevels[this->i].star3->setVisible(false);
                }
                else
                {
                    this->listOfLevels[this->i]->gotoAndStop(5);
                    this->listOfLevels[this->i].wreath->stop();
                    this->listOfLevels[this->i].star1->stop();
                    this->listOfLevels[this->i].star2->stop();
                    this->listOfLevels[this->i].star3->stop();
                    this->listOfLevels[this->i].wreath.visible = true;
                    this->listOfLevels[this->i].star1.visible = true;
                    this->listOfLevels[this->i].star2.visible = true;
                    this->listOfLevels[this->i].star3.visible = true;
                    this->listOfLevels[this->i].wreath->gotoAndStop(1);
                    this->listOfLevels[this->i].star1->gotoAndStop(this->listOfLevels[this->i].star1.totalFrames);
                    this->listOfLevels[this->i].star2->gotoAndStop(this->listOfLevels[this->i].star2.totalFrames);
                    this->listOfLevels[this->i].star3->gotoAndStop(this->listOfLevels[this->i].star3.totalFrames);
                    this->listOfLevels[this->i]->stop();
                    this->listOfLevels[this->i].levelCase->stop();
                    ;
                }
            }
            this->listOfLevels[this->i]->stop();
            if (this->listOfLevels[this->i].levelCase)
            {
                this->listOfLevels[this->i].levelCase->stop();
                this->listOfLevels[this->i].levelCase.buttonMode = true;
            }
            var _loc_1 : *= this;
            var _loc_2 : *= this->i + 1;
            _loc_1.i = _loc_2;
        }
        return;
    }// end function

    void LevelsMenu::openNewLevel()
    {
        if (this->newLevel == 1)
        {
            if (this->container->road->currentFrame < 12)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 2)
        {
            if (this->container->road->currentFrame < 26)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 3)
        {
            if (this->container->road->currentFrame < 41)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 4)
        {
            if (this->container->road->currentFrame < 55)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 5)
        {
            if (this->container->road->currentFrame < 66)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 6)
        {
            if (this->container->road->currentFrame < 80)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 7)
        {
            if (this->container->road->currentFrame < 92)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 8)
        {
            if (this->container->road->currentFrame < 104)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 9)
        {
            if (this->container->road->currentFrame < 115)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 10)
        {
            if (this->container->road->currentFrame < 127)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 11)
        {
            if (this->container->road->currentFrame < 136)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 12)
        {
            if (this->container->road->currentFrame < 144)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 13)
        {
            if (this->container->road->currentFrame < 153)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 14)
        {
            if (this->container->road->currentFrame < 164)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        else if (this->newLevel == 15)
        {
            if (this->container->road->currentFrame < 179)
            {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            }
            else if (!this->roadOff)
            {
                this->roadOff = true;
            }
        }
        if (this->roadOff)
        {
            if (!this->newLevelGr)
            {
                this->newLevelGr = new NewLevel_mc();
                this->newLevelGr->stop();
                this->newLevelGr.x = this->listOfLevels[(this->newLevel - 1)].x + 0.65;
                this->newLevelGr.y = this->listOfLevels[(this->newLevel - 1)].y + 0.65;
                this->addChild(this->newLevelGr);
                this->listOfLevels[(this->newLevel - 1)].visible = true;
                this->listOfLevels[(this->newLevel - 1)].alpha = 0;
            }
            else if (this->newLevelGr->currentFrame < this->newLevelGr.totalFrames)
            {
                this->newLevelGr->gotoAndStop((this->newLevelGr->currentFrame + 1));
                if (this->newLevelGr->currentFrame >= 8)
                {
                    this->newLevelGr.alpha = this->newLevelGr.alpha - 0.2;
                    this->listOfLevels[(this->newLevel - 1)].alpha = this->listOfLevels[(this->newLevel - 1)].alpha + 0.2;
                }
            }
            else
            {
                if (this->newLevel == 1)
                {
                    this->training_1 = new Training_1();
                    this->addChild(this->training_1);
                }
                this->listOfLevels[(this->newLevel - 1)].alpha = 1;
                var _loc_1 : *= 0;
                this->newLevel = 0;
                Main::mainClass->saveBoxClass.gameSave.data.newLevel = _loc_1;
                this->removeChild(this->newLevelGr);
                this->newLevelGr = null;
            }
        }
        return;
    }// end function

    void LevelsMenu::openNewStarsForLevel()
    {
        if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[(this->newStarsForLevel - 1)] < 4)
        {
            if (this->listOfLevels[(this->newStarsForLevel - 1)].towerEffect->currentFrame < this->listOfLevels[(this->newStarsForLevel - 1)].towerEffect.totalFrames)
            {
                this->listOfLevels[(this->newStarsForLevel - 1)].towerEffect->gotoAndStop((this->listOfLevels[(this->newStarsForLevel - 1)].towerEffect->currentFrame + 1));
            }
            else if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[(this->newStarsForLevel - 1)] == 1)
            {
                if (!this->listOfLevels[(this->newStarsForLevel - 1)].star1->isVisible())
                {
                    this->listOfLevels[(this->newStarsForLevel - 1)].star1.visible = true;
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)].star1->currentFrame < this->listOfLevels[(this->newStarsForLevel - 1)].star1.totalFrames)
                {
                    this->listOfLevels[(this->newStarsForLevel - 1)].star1->gotoAndStop((this->listOfLevels[(this->newStarsForLevel - 1)].star1->currentFrame + 1));
                }
                else
                {
                    var _loc_1 : *= 0;
                    this->newStarsForLevel = 0;
                    Main::mainClass->saveBoxClass.gameSave.data.newStarsForLevel = _loc_1;
                    this->preparationLevels();
                }
            }
            else if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[(this->newStarsForLevel - 1)] == 2)
            {
                if (!this->listOfLevels[(this->newStarsForLevel - 1)].star1->isVisible())
                {
                    this->listOfLevels[(this->newStarsForLevel - 1)].star1.visible = true;
                    this->listOfLevels[(this->newStarsForLevel - 1)].star2.visible = true;
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)].star1->currentFrame < this->listOfLevels[(this->newStarsForLevel - 1)].star1.totalFrames)
                {
                    this->listOfLevels[(this->newStarsForLevel - 1)].star1->gotoAndStop((this->listOfLevels[(this->newStarsForLevel - 1)].star1->currentFrame + 1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)].star2->currentFrame < this->listOfLevels[(this->newStarsForLevel - 1)].star2.totalFrames)
                {
                    this->listOfLevels[(this->newStarsForLevel - 1)].star2->gotoAndStop((this->listOfLevels[(this->newStarsForLevel - 1)].star2->currentFrame + 1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)].star1->currentFrame == this->listOfLevels[(this->newStarsForLevel - 1)].star1.totalFrames && this->listOfLevels[(this->newStarsForLevel - 1)].star2->currentFrame == this->listOfLevels[(this->newStarsForLevel - 1)].star2.totalFrames)
                {
                    var _loc_1 : *= 0;
                    this->newStarsForLevel = 0;
                    Main::mainClass->saveBoxClass.gameSave.data.newStarsForLevel = _loc_1;
                    this->preparationLevels();
                }
            }
            else if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[(this->newStarsForLevel - 1)] == 3)
            {
                if (!this->listOfLevels[(this->newStarsForLevel - 1)].star1->isVisible())
                {
                    this->listOfLevels[(this->newStarsForLevel - 1)].star1.visible = true;
                    this->listOfLevels[(this->newStarsForLevel - 1)].star2.visible = true;
                    this->listOfLevels[(this->newStarsForLevel - 1)].star3.visible = true;
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)].star1->currentFrame < this->listOfLevels[(this->newStarsForLevel - 1)].star1.totalFrames)
                {
                    this->listOfLevels[(this->newStarsForLevel - 1)].star1->gotoAndStop((this->listOfLevels[(this->newStarsForLevel - 1)].star1->currentFrame + 1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)].star2->currentFrame < this->listOfLevels[(this->newStarsForLevel - 1)].star2.totalFrames)
                {
                    this->listOfLevels[(this->newStarsForLevel - 1)].star2->gotoAndStop((this->listOfLevels[(this->newStarsForLevel - 1)].star2->currentFrame + 1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)].star3->currentFrame < this->listOfLevels[(this->newStarsForLevel - 1)].star3.totalFrames)
                {
                    this->listOfLevels[(this->newStarsForLevel - 1)].star3->gotoAndStop((this->listOfLevels[(this->newStarsForLevel - 1)].star3->currentFrame + 1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)].star1->currentFrame == this->listOfLevels[(this->newStarsForLevel - 1)].star1.totalFrames && this->listOfLevels[(this->newStarsForLevel - 1)].star2->currentFrame == this->listOfLevels[(this->newStarsForLevel - 1)].star2.totalFrames && this->listOfLevels[(this->newStarsForLevel - 1)].star3->currentFrame == this->listOfLevels[(this->newStarsForLevel - 1)].star3.totalFrames)
                {
                    var _loc_1 : *= 0;
                    this->newStarsForLevel = 0;
                    Main::mainClass->saveBoxClass.gameSave.data.newStarsForLevel = _loc_1;
                    this->preparationLevels();
                }
            }
        }
        else if (this->listOfLevels[(this->newStarsForLevel - 1)].wreath->currentFrame < this->listOfLevels[(this->newStarsForLevel - 1)].wreath.totalFrames)
        {
            this->listOfLevels[(this->newStarsForLevel - 1)].wreath->gotoAndStop((this->listOfLevels[(this->newStarsForLevel - 1)].wreath->currentFrame + 1));
        }
        else
        {
            var _loc_1 : *= 0;
            this->newStarsForLevel = 0;
            Main::mainClass->saveBoxClass.gameSave.data.newStarsForLevel = _loc_1;
            this->preparationLevels();
        }
        return;
    }// end function

    void LevelsMenu::autoguidersButtons()
    {
        this->autoguidesMouse_pt = new Point(this->mouseX, this->mouseY);
        this->autoguidesObject = null;
        this->autoguidesObject_pt = this->container->back.localToGlobal(new Point(this->container->back.backCase.x, this->container->back.backCase.y));
        this->autoguidesObjectWidth = this->container->back.backCase.width / 2;
        this->autoguidesObjectHeight = this->container->back.backCase.height / 2;
        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        {
            this->autoguidesObject = this->container->back.backCase;
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->upgrades.localToGlobal(new Point(this->container->upgrades.upgradesCase1.x, this->container->upgrades.upgradesCase1.y));
            this->autoguidesObjectWidth = this->container->upgrades.upgradesCase1.width / 2;
            this->autoguidesObjectHeight = this->container->upgrades.upgradesCase1.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->upgrades.upgradesCase1;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->upgrades.localToGlobal(new Point(this->container->upgrades.upgradesCase2.x, this->container->upgrades.upgradesCase2.y));
            this->autoguidesObjectWidth = this->container->upgrades.upgradesCase2.width / 2;
            this->autoguidesObjectHeight = this->container->upgrades.upgradesCase2.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->upgrades.upgradesCase2;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->book.localToGlobal(new Point(this->container->book.bookCase1.x, this->container->book.bookCase1.y));
            this->autoguidesObjectWidth = this->container->book.bookCase1.width / 2;
            this->autoguidesObjectHeight = this->container->book.bookCase1.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->book.bookCase1;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->book.localToGlobal(new Point(this->container->book.bookCase2.x, this->container->book.bookCase2.y));
            this->autoguidesObjectWidth = this->container->book.bookCase2.width / 2;
            this->autoguidesObjectHeight = this->container->book.bookCase2.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->book.bookCase2;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->achieves.localToGlobal(new Point(this->container->achieves.achievesCase1.x, this->container->achieves.achievesCase1.y));
            this->autoguidesObjectWidth = this->container->achieves.achievesCase1.width / 2;
            this->autoguidesObjectHeight = this->container->achieves.achievesCase1.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->achieves.achievesCase1;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->achieves.localToGlobal(new Point(this->container->achieves.achievesCase2.x, this->container->achieves.achievesCase2.y));
            this->autoguidesObjectWidth = this->container->achieves.achievesCase2.width / 2;
            this->autoguidesObjectHeight = this->container->achieves.achievesCase2.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->achieves.achievesCase2;
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level1.levelCase)
            {
                this->autoguidesObject_pt = this->container->level1.localToGlobal(new Point(this->container->level1.levelCase.x, this->container->level1.levelCase.y));
                this->autoguidesObjectWidth = this->container->level1.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level1.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level1.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level2.levelCase)
            {
                this->autoguidesObject_pt = this->container->level2.localToGlobal(new Point(this->container->level2.levelCase.x, this->container->level2.levelCase.y));
                this->autoguidesObjectWidth = this->container->level2.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level2.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level2.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level3.levelCase)
            {
                this->autoguidesObject_pt = this->container->level3.localToGlobal(new Point(this->container->level3.levelCase.x, this->container->level3.levelCase.y));
                this->autoguidesObjectWidth = this->container->level3.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level3.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level3.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level4.levelCase)
            {
                this->autoguidesObject_pt = this->container->level4.localToGlobal(new Point(this->container->level4.levelCase.x, this->container->level4.levelCase.y));
                this->autoguidesObjectWidth = this->container->level4.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level4.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level4.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level5.levelCase)
            {
                this->autoguidesObject_pt = this->container->level5.localToGlobal(new Point(this->container->level5.levelCase.x, this->container->level5.levelCase.y));
                this->autoguidesObjectWidth = this->container->level5.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level5.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level5.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level6.levelCase)
            {
                this->autoguidesObject_pt = this->container->level6.localToGlobal(new Point(this->container->level6.levelCase.x, this->container->level6.levelCase.y));
                this->autoguidesObjectWidth = this->container->level6.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level6.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level6.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level7.levelCase)
            {
                this->autoguidesObject_pt = this->container->level7.localToGlobal(new Point(this->container->level7.levelCase.x, this->container->level7.levelCase.y));
                this->autoguidesObjectWidth = this->container->level7.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level7.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level7.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level8.levelCase)
            {
                this->autoguidesObject_pt = this->container->level8.localToGlobal(new Point(this->container->level8.levelCase.x, this->container->level8.levelCase.y));
                this->autoguidesObjectWidth = this->container->level8.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level8.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level8.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level9.levelCase)
            {
                this->autoguidesObject_pt = this->container->level9.localToGlobal(new Point(this->container->level9.levelCase.x, this->container->level9.levelCase.y));
                this->autoguidesObjectWidth = this->container->level9.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level9.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level9.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level10.levelCase)
            {
                this->autoguidesObject_pt = this->container->level10.localToGlobal(new Point(this->container->level10.levelCase.x, this->container->level10.levelCase.y));
                this->autoguidesObjectWidth = this->container->level10.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level10.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level10.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level11.levelCase)
            {
                this->autoguidesObject_pt = this->container->level11.localToGlobal(new Point(this->container->level11.levelCase.x, this->container->level11.levelCase.y));
                this->autoguidesObjectWidth = this->container->level11.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level11.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level11.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level12.levelCase)
            {
                this->autoguidesObject_pt = this->container->level12.localToGlobal(new Point(this->container->level12.levelCase.x, this->container->level12.levelCase.y));
                this->autoguidesObjectWidth = this->container->level12.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level12.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level12.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level13.levelCase)
            {
                this->autoguidesObject_pt = this->container->level13.localToGlobal(new Point(this->container->level13.levelCase.x, this->container->level13.levelCase.y));
                this->autoguidesObjectWidth = this->container->level13.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level13.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level13.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level14.levelCase)
            {
                this->autoguidesObject_pt = this->container->level14.localToGlobal(new Point(this->container->level14.levelCase.x, this->container->level14.levelCase.y));
                this->autoguidesObjectWidth = this->container->level14.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level14.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level14.levelCase;
                }
            }
        }
        if (!this->autoguidesObject)
        {
            if (this->container->level15.levelCase)
            {
                this->autoguidesObject_pt = this->container->level15.localToGlobal(new Point(this->container->level15.levelCase.x, this->container->level15.levelCase.y));
                this->autoguidesObjectWidth = this->container->level15.levelCase.width / 2;
                this->autoguidesObjectHeight = this->container->level15.levelCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->level15.levelCase;
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

    void LevelsMenu::manageListeners(string param1)
    {
        if (param1 == "on")
        {
            this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
            this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
            this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
            this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
            this->autoguidersButtons();
        }
        else if (param1 == "off")
        {
            this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
            this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
            this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
            this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        }
        return;
    }// end function

    //void reInit(event:Event) 
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    return;
    //}// end function

}

