 
#include "Achievements.h"   
#include "engine/World.h"   
#include "MainClass.h"
#include "LevelsMenu.h"
 
namespace screens
{   
    Achievements_mc::Achievements_mc()
    {
        return;
    }// end function
     

    Achievements::Achievements():fireFrame(0),container(0)
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool Achievements::init(float dt)
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        //this->stage.frameRate = 60;
        Main::mainClass->levelsMenuClass->manageListeners("off");
        this->container = new Achievements_mc();
        this->container->stop();
        this->container->back->stop();
        this->container->back->backCase->stop();
        this->container->back->backCase->setMouseEnabled(true);
        this->container->cont->stop();
        this->container->cont->achieve1->stop();
        this->container->cont->achieve2->stop();
        this->container->cont->achieve3->stop();
        this->container->cont->achieve4->stop();
        this->container->cont->achieve5->stop();
        this->container->cont->achieve6->stop();
        this->container->cont->achieve7->stop();
        this->container->cont->achieve8->stop();
        this->container->cont->achieve9->stop();
        this->container->cont->achieve10->stop();
        this->container->cont->btnBack->stop();
        this->container->cont->btnBack->arrowCase->stop();
        this->container->cont->btnForward->stop();
        this->container->cont->btnForward->arrowCase->stop();
        this->container->cont->btnClose->stop();
        this->container->cont->btnClose->closeCase->stop();
        this->container->cont->fire1->stop();
        this->container->cont->fire2->stop();
        this->container->cont->fire3->stop();
        this->container->cont->fire4->stop();
        this->container->cont->fire5->stop();
        this->container->cont->fire1Case->stop();
        this->container->cont->fire2Case->stop();
        this->container->cont->fire3Case->stop();
        this->container->cont->fire4Case->stop();
        this->container->cont->fire5Case->stop();
        this->container->cont->btnBack->arrowCase->setMouseEnabled(true);
        this->container->cont->btnForward->arrowCase->setMouseEnabled(true);
        this->container->cont->btnClose->closeCase->setMouseEnabled(true);
        this->pageManage(1); 
        this->container->cont->setMouseChildren(false);
        this->container->cont->setMouseEnabled(false);
        this->addChild(this->container);
        AudioUtil::playSound("Snd_menu_openBoard.mp3");
        return true;
    }// end function

    void Achievements::enterFrameHandler(float dt)
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
            if (this->container->currentFrame < this->container->totalFrames)
            {
                this->container->gotoAndStop((this->container->currentFrame + 1));
            }
            else
            {
                this->openFlag = false; 
                this->container->cont->setMouseChildren(true);
                this->container->cont->setMouseEnabled(true);
                this->autoguidersButtons();
                //this->stage.frameRate = 30;
            }
        }
        else if (this->closeFlag)
        {
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
        if (this->container->cont->fire1->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire1->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire1->gotoAndStop(this->fireFrame);
        }
        else if (this->container->cont->fire2->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire2->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire2->gotoAndStop(this->fireFrame);
        }
        else if (this->container->cont->fire3->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire3->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire3->gotoAndStop(this->fireFrame);
        }
        else if (this->container->cont->fire4->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire4->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire4->gotoAndStop(this->fireFrame);
        }
        else if (this->container->cont->fire5->isVisible())
        {
            if (this->fireFrame < this->container->cont->fire5->totalFrames)
            {
                this->fireFrame++;
            }
            else
            {
                this->fireFrame = 1;
            }
            this->container->cont->fire5->gotoAndStop(this->fireFrame);
        }
        return;
    }// end function

    void Achievements::mouseMoveHandler(cocos2d::EventMouse *e)
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
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->back->currentFrame == 2)
        {
            this->container->back->gotoAndStop(1);
        }
        if (param1->target->name == "closeCase")
        {
            if (this->container->cont->btnClose->currentFrame == 1)
            {
                this->container->cont->btnClose->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->btnClose->currentFrame == 2)
        {
            this->container->cont->btnClose->gotoAndStop(1);
        }
        if (param1->target->parent.name == "btnBack")
        {
            if (this->container->cont->btnBack->currentFrame == 1)
            {
                this->container->cont->btnBack->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->btnBack->currentFrame == 2)
        {
            this->container->cont->btnBack->gotoAndStop(1);
        }
        if (param1->target->parent.name == "btnForward")
        {
            if (this->container->cont->btnForward->currentFrame == 1)
            {
                this->container->cont->btnForward->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->btnForward->currentFrame == 2)
        {
            this->container->cont->btnForward->gotoAndStop(1);
        }
        if (param1->target->name == "fire1Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->fire1Case->mouseMoveFlag)
        {
            this->container->cont->fire1Case->mouseMoveFlag = false;
        }
        if (param1->target->name == "fire2Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->fire2Case->mouseMoveFlag)
        {
            this->container->cont->fire2Case->mouseMoveFlag = false;
        }
        if (param1->target->name == "fire3Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->fire3Case->mouseMoveFlag)
        {
            this->container->cont->fire3Case->mouseMoveFlag = false;
        }
        if (param1->target->name == "fire4Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->fire4Case->mouseMoveFlag)
        {
            this->container->cont->fire4Case->mouseMoveFlag = false;
        }
        if (param1->target->name == "fire5Case")
        {
            if (!param1->target->mouseMoveFlag)
            {
                param1->target->mouseMoveFlag = true;
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->cont->fire5Case->mouseMoveFlag)
        {
            this->container->cont->fire5Case->mouseMoveFlag = false;
        }
        return;
    }// end function

    void Achievements::mouseDownHandler(cocos2d::EventMouse * e)
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if(!event)
			return;
        string targetName = event->target->getName();
        if (!this->openFlag)
        {
            if (targetName == "backCase")
            {
                if (this->container->back->currentFrame == 2)
                {
                    this->container->back->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "closeCase")
            {
                if (this->container->cont->btnClose->currentFrame == 2)
                {
                    this->container->cont->btnClose->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (event.target.parent.name == "btnBack")
            {
                if (this->container->cont->btnBack->currentFrame == 2)
                {
                    this->container->cont->btnBack->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (event.target.parent.name == "btnForward")
            {
                if (this->container->cont->btnForward->currentFrame == 2)
                {
                    this->container->cont->btnForward->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "fire1Case")
            {
                if (this->container->cont->fire1Case->mouseEnabled)
                {
                    this->pageManage(1);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "fire2Case")
            {
                if (this->container->cont->fire2Case->mouseEnabled)
                {
                    this->pageManage(2);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "fire3Case")
            {
                if (this->container->cont->fire3Case->mouseEnabled)
                {
                    this->pageManage(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "fire4Case")
            {
                if (this->container->cont->fire4Case->mouseEnabled)
                {
                    this->pageManage(4);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "fire5Case")
            {
                if (this->container->cont->fire5Case->mouseEnabled)
                {
                    this->pageManage(5);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "shadow")
            {
                this->close();
            }
        }
        return;
    }// end function

    void Achievements::mouseUpHandler(cocos2d::EventMouse * event) 
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
        string targetName = event->target->getName();
        if (targetName == "backCase")
        {
            if (this->container->back->currentFrame == 3)
            {
                this->container->back->gotoAndStop(2);
                this->close();
            }
        }
        else if (this->container->back->currentFrame == 3)
        {
            this->container->back->gotoAndStop(1);
        }
        if (targetName == "closeCase")
        {
            if (this->container->cont->btnClose->currentFrame == 3)
            {
                this->container->cont->btnClose->gotoAndStop(2);
                this->close();
            }
        }
        else if (this->container->cont->btnClose->currentFrame == 3)
        {
            this->container->cont->btnClose->gotoAndStop(1);
        }
        if (event.target.parent.name == "btnBack")
        {
            if (this->container->cont->btnBack->currentFrame == 3)
            {
                this->container->cont->btnBack->gotoAndStop(2);
                this->pageManage((this->page - 1));
            }
        }
        else if (this->container->cont->btnBack->currentFrame == 3)
        {
            this->container->cont->btnBack->gotoAndStop(1);
        }
        if (event.target.parent.name == "btnForward")
        {
            if (this->container->cont->btnForward->currentFrame == 3)
            {
                this->container->cont->btnForward->gotoAndStop(2);
                this->pageManage((this->page + 1));
            }
        }
        else if (this->container->cont->btnForward->currentFrame == 3)
        {
            this->container->cont->btnForward->gotoAndStop(1);
        }
        return;
    }// end function

    void Achievements::pageManage(int param1)  
    {
        if (param1 < 1)
        {
            param1 = 5;
        }
        else if (param1 > 5)
        {
            param1 = 1;
        }
        this->page = param1;
        if (!this->container->cont->achieve1->isVisible())
        {
            this->container->cont->achieve1->setVisible(true);
        }
        if (!this->container->cont->achieve2->isVisible())
        {
            this->container->cont->achieve2->setVisible(true);
        }
        if (!this->container->cont->achieve3->isVisible())
        {
            this->container->cont->achieve3->setVisible(true);
        }
        if (!this->container->cont->achieve4->isVisible())
        {
            this->container->cont->achieve4->setVisible(true);
        }
        if (!this->container->cont->achieve5->isVisible())
        {
            this->container->cont->achieve5->setVisible(true);
        }
        if (!this->container->cont->achieve6->isVisible())
        {
            this->container->cont->achieve6->setVisible(true);
        }
        if (!this->container->cont->achieve7->isVisible())
        {
            this->container->cont->achieve7->setVisible(true);
        }
        if (!this->container->cont->achieve8->isVisible())
        {
            this->container->cont->achieve8->setVisible(true);
        }
        if (!this->container->cont->achieve9->isVisible())
        {
            this->container->cont->achieve9->setVisible(true);
        }
        if (!this->container->cont->achieve10->isVisible())
        {
            this->container->cont->achieve10->setVisible(true);
        }
        if (this->container->cont->fire1->isVisible())
        {
            this->container->cont->fire1->setVisible(false);
        }
        if (this->container->cont->fire2->isVisible())
        {
            this->container->cont->fire2->setVisible(false);
        }
        if (this->container->cont->fire3->isVisible())
        {
            this->container->cont->fire3->setVisible(false);
        }
        if (this->container->cont->fire4->isVisible())
        {
            this->container->cont->fire4->setVisible(false);
        }
        if (this->container->cont->fire5->isVisible())
        {
            this->container->cont->fire5->setVisible(false);
        }
        if (!this->container->cont->fire1Case->mouseEnabled)
        {
            this->container->cont->fire1Case->setMouseEnabled(true);
        }
        if (!this->container->cont->fire2Case->mouseEnabled)
        {
            this->container->cont->fire2Case->setMouseEnabled(true);
        }
        if (!this->container->cont->fire3Case->mouseEnabled)
        {
            this->container->cont->fire3Case->setMouseEnabled(true);
        }
        if (!this->container->cont->fire4Case->mouseEnabled)
        {
            this->container->cont->fire4Case->setMouseEnabled(true);
        }
        if (!this->container->cont->fire5Case->mouseEnabled)
        {
            this->container->cont->fire5Case->setMouseEnabled(true);
        }
        if (param1 == 1)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_firstKill"))
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(1);
            std::setText(this->container->cont->achieve1->nameTxt,I18N_VALUE(I18N_CODE::U025)));
            std::setText(this->container->cont->achieve1->noteTxt,I18N_VALUE(I18N_CODE::U072));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_kill_100_enemies")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(2);
            std::setText(this->container->cont->achieve2->nameTxt,I18N_VALUE(I18N_CODE::U026));
            std::setText(this->container->cont->achieve2->noteTxt,I18N_VALUE(I18N_CODE::U073));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_kill_2500_enemies")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(3);
            std::setText(this->container->cont->achieve3->nameTxt,I18N_VALUE(I18N_CODE::U027));
            std::setText(this->container->cont->achieve3->noteTxt,I18N_VALUE(I18N_CODE::U074));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_call_100_earlyWaves")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(4);
            std::setText(this->container->cont->achieve4->nameTxt,I18N_VALUE(I18N_CODE::U028));
            std::setText(this->container->cont->achieve4->noteTxt,I18N_VALUE(I18N_CODE::U075));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_build_100_towers")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(5);
            std::setText(this->container->cont->achieve5->nameTxt,I18N_VALUE(I18N_CODE::U029));
            std::setText(this->container->cont->achieve5->noteTxt,I18N_VALUE(I18N_CODE::U076));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_createGolem_5_times")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(6);
            std::setText(this->container->cont->achieve6->nameTxt,I18N_VALUE(I18N_CODE::U030));
            std::setText(this->container->cont->achieve6->noteTxt,I18N_VALUE(I18N_CODE::U077));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_createIceman_15_times")
            {
                this->container->cont->achieve7->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve7->gotoAndStop(2);
            }
            this->container->cont->achieve7->icon->gotoAndStop(7);
            std::setText(this->container->cont->achieve7->nameTxt,I18N_VALUE(I18N_CODE::U031));
            std::setText(this->container->cont->achieve7->noteTxt,I18N_VALUE(I18N_CODE::U078));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_createAir_7_times")
            {
                this->container->cont->achieve8->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve8->gotoAndStop(2);
            }
            this->container->cont->achieve8->icon->gotoAndStop(8);
            std::setText(this->container->cont->achieve8->nameTxt,I18N_VALUE(I18N_CODE::U032));
            std::setText(this->container->cont->achieve8->noteTxt,I18N_VALUE(I18N_CODE::U079));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_callAllWavesInLevel")
            {
                this->container->cont->achieve9->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve9->gotoAndStop(2);
            }
            this->container->cont->achieve9->icon->gotoAndStop(9);
            std::setText(this->container->cont->achieve9->nameTxt,I18N_VALUE(I18N_CODE::U033));
            std::setText(this->container->cont->achieve9->noteTxt,I18N_VALUE(I18N_CODE::U080));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellFireIceStoneLevin")
            {
                this->container->cont->achieve10->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve10->gotoAndStop(2);
            }
            this->container->cont->achieve10->icon->gotoAndStop(10);
            std::setText(this->container->cont->achieve10->nameTxt,I18N_VALUE(I18N_CODE::U034));
            std::setText(this->container->cont->achieve10->noteTxt,I18N_VALUE(I18N_CODE::U081));
            this->container->cont->fire1->setVisible(true);
            this->container->cont->fire1Case->setMouseEnabled(false);
        }
        else if (param1 == 2)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellFire_10_times")
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(11);
            std::setText(this->container->cont->achieve1->nameTxt,I18N_VALUE(I18N_CODE::U035));
            std::setText(this->container->cont->achieve1->noteTxt,I18N_VALUE(I18N_CODE::U082));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellIce_10_times")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(12);
            std::setText(this->container->cont->achieve2->nameTxt,I18N_VALUE(I18N_CODE::U036));
            std::setText(this->container->cont->achieve2->noteTxt,I18N_VALUE(I18N_CODE::U083));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellStone_10_times")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(13);
            std::setText(this->container->cont->achieve3->nameTxt,I18N_VALUE(I18N_CODE::U037));
            std::setText(this->container->cont->achieve3->noteTxt,I18N_VALUE(I18N_CODE::U084));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellLevin_10_times")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(14);
            std::setText(this->container->cont->achieve4->nameTxt,I18N_VALUE(I18N_CODE::U038));
            std::setText(this->container->cont->achieve4->noteTxt,I18N_VALUE(I18N_CODE::U085));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_golemKill_250_enemies")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(15);
            std::setText(this->container->cont->achieve5->nameTxt,I18N_VALUE(I18N_CODE::U039));
            std::setText(this->container->cont->achieve5->noteTxt,I18N_VALUE(I18N_CODE::U086));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_icemanSlowdown_75_enemies")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(16);
            std::setText(this->container->cont->achieve6->nameTxt,I18N_VALUE(I18N_CODE::U040));
            std::setText(this->container->cont->achieve6->noteTxt,I18N_VALUE(I18N_CODE::U087));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_icemanSlowdown_500_enemies")
            {
                this->container->cont->achieve7->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve7->gotoAndStop(2);
            }
            this->container->cont->achieve7->icon->gotoAndStop(17);
            std::setText(this->container->cont->achieve7->nameTxt,I18N_VALUE(I18N_CODE::U041));
            std::setText(this->container->cont->achieve7->noteTxt,I18N_VALUE(I18N_CODE::U088));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_buildUltraTower")
            {
                this->container->cont->achieve8->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve8->gotoAndStop(2);
            }
            this->container->cont->achieve8->icon->gotoAndStop(18);
            std::setText(this->container->cont->achieve8->nameTxt,I18N_VALUE(I18N_CODE::U042));
            std::setText(this->container->cont->achieve8->noteTxt,I18N_VALUE(I18N_CODE::U089));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_buildUltraTower_50_times")
            {
                this->container->cont->achieve9->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve9->gotoAndStop(2);
            }
            this->container->cont->achieve9->icon->gotoAndStop(19);
            std::setText(this->container->cont->achieve9->nameTxt,I18N_VALUE(I18N_CODE::U043));
            std::setText(this->container->cont->achieve9->noteTxt,I18N_VALUE(I18N_CODE::U090));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_buildAllUltraTowers")
            {
                this->container->cont->achieve10->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve10->gotoAndStop(2);
            }
            this->container->cont->achieve10->icon->gotoAndStop(20);
            std::setText(this->container->cont->achieve10->nameTxt,I18N_VALUE(I18N_CODE::U044));
            std::setText(this->container->cont->achieve10->noteTxt,I18N_VALUE(I18N_CODE::U091));
            this->container->cont->fire2->setVisible(true);
            this->container->cont->fire2Case->setMouseEnabled(false);
        }
        else if (param1 == 3)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_notCast")
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(21);
            std::setText(this->container->cont->achieve1->nameTxt,I18N_VALUE(I18N_CODE::U045));
            std::setText(this->container->cont->achieve1->noteTxt,I18N_VALUE(I18N_CODE::U092));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castFire_150_times")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(22);
            std::setText(this->container->cont->achieve2->nameTxt,I18N_VALUE(I18N_CODE::U046));
            std::setText(this->container->cont->achieve2->noteTxt,I18N_VALUE(I18N_CODE::U093));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castIce_150_times")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(23);
            std::setText(this->container->cont->achieve3->nameTxt,I18N_VALUE(I18N_CODE::U047));
            std::setText(this->container->cont->achieve3->noteTxt,I18N_VALUE(I18N_CODE::U094));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castStone_150_times")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(24);
            std::setText(this->container->cont->achieve4->nameTxt,I18N_VALUE(I18N_CODE::U048));
            std::setText(this->container->cont->achieve4->noteTxt,I18N_VALUE(I18N_CODE::U095));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castLevin_150_times")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(25);
            std::setText(this->container->cont->achieve5->nameTxt,I18N_VALUE(I18N_CODE::U049));
            std::setText(this->container->cont->achieve5->noteTxt,I18N_VALUE(I18N_CODE::U096));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castGetAll_10_times")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(26);
            std::setText(this->container->cont->achieve6->nameTxt,I18N_VALUE(I18N_CODE::U050));
            std::setText(this->container->cont->achieve6->noteTxt,I18N_VALUE(I18N_CODE::U097));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castGetAll_100_times")
            {
                this->container->cont->achieve7->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve7->gotoAndStop(2);
            }
            this->container->cont->achieve7->icon->gotoAndStop(27);
            std::setText(this->container->cont->achieve7->nameTxt,I18N_VALUE(I18N_CODE::U051));
            std::setText(this->container->cont->achieve7->noteTxt,I18N_VALUE(I18N_CODE::U098));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castKill_1_enemy")
            {
                this->container->cont->achieve8->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve8->gotoAndStop(2);
            }
            this->container->cont->achieve8->icon->gotoAndStop(28);
            std::setText(this->container->cont->achieve8->nameTxt,I18N_VALUE(I18N_CODE::U052));
            std::setText(this->container->cont->achieve8->noteTxt,I18N_VALUE(I18N_CODE::U099));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castKill_100_enemy")
            {
                this->container->cont->achieve9->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve9->gotoAndStop(2);
            }
            this->container->cont->achieve9->icon->gotoAndStop(29);
            std::setText(this->container->cont->achieve9->nameTxt,I18N_VALUE(I18N_CODE::U053));
            std::setText(this->container->cont->achieve9->noteTxt,I18N_VALUE(I18N_CODE::U100));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_complete_10_hardLevels")
            {
                this->container->cont->achieve10->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve10->gotoAndStop(2);
            }
            this->container->cont->achieve10->icon->gotoAndStop(30);
            std::setText(this->container->cont->achieve10->nameTxt,I18N_VALUE(I18N_CODE::U054));
            std::setText(this->container->cont->achieve10->noteTxt,I18N_VALUE(I18N_CODE::U101));
            this->container->cont->fire3->setVisible(true);
            this->container->cont->fire3Case->setMouseEnabled(false);
        }
        else if (param1 == 4)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_complete_10_survivalLevels")
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(31);
            std::setText(this->container->cont->achieve1->nameTxt,I18N_VALUE(I18N_CODE::U055));
            std::setText(this->container->cont->achieve1->noteTxt,I18N_VALUE(I18N_CODE::U102));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_complete_10_withAllLives")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(32);
            std::setText(this->container->cont->achieve2->nameTxt,I18N_VALUE(I18N_CODE::U056));
            std::setText(this->container->cont->achieve2->noteTxt,I18N_VALUE(I18N_CODE::U103));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_01")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(33);
            std::setText(this->container->cont->achieve3->nameTxt,I18N_VALUE(I18N_CODE::U057));
            std::setText(this->container->cont->achieve3->noteTxt,I18N_VALUE(I18N_CODE::U104));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_02")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(34);
            std::setText(this->container->cont->achieve4->nameTxt,I18N_VALUE(I18N_CODE::U058));
            std::setText(this->container->cont->achieve4->noteTxt,I18N_VALUE(I18N_CODE::U105));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_03")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(35);
            std::setText(this->container->cont->achieve5->nameTxt,I18N_VALUE(I18N_CODE::U059));
            std::setText(this->container->cont->achieve5->noteTxt,I18N_VALUE(I18N_CODE::U106));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_04")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(36);
            std::setText(this->container->cont->achieve6->nameTxt,I18N_VALUE(I18N_CODE::U060));
            std::setText(this->container->cont->achieve6->noteTxt,I18N_VALUE(I18N_CODE::U107));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_05")
            {
                this->container->cont->achieve7->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve7->gotoAndStop(2);
            }
            this->container->cont->achieve7->icon->gotoAndStop(37);
            std::setText(this->container->cont->achieve7->nameTxt,I18N_VALUE(I18N_CODE::U061));
            std::setText(this->container->cont->achieve7->noteTxt,I18N_VALUE(I18N_CODE::U108));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_06")
            {
                this->container->cont->achieve8->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve8->gotoAndStop(2);
            }
            this->container->cont->achieve8->icon->gotoAndStop(38);
            std::setText(this->container->cont->achieve8->nameTxt,I18N_VALUE(I18N_CODE::U062));
            std::setText(this->container->cont->achieve8->noteTxt,I18N_VALUE(I18N_CODE::U109));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_07")
            {
                this->container->cont->achieve9->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve9->gotoAndStop(2);
            }
            this->container->cont->achieve9->icon->gotoAndStop(39);
            std::setText(this->container->cont->achieve9->nameTxt,I18N_VALUE(I18N_CODE::U063));
            std::setText(this->container->cont->achieve9->noteTxt,I18N_VALUE(I18N_CODE::U110));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_08")
            {
                this->container->cont->achieve10->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve10->gotoAndStop(2);
            }
            this->container->cont->achieve10->icon->gotoAndStop(40);
            std::setText(this->container->cont->achieve10->nameTxt,I18N_VALUE(I18N_CODE::U064));
            std::setText(this->container->cont->achieve10->noteTxt,I18N_VALUE(I18N_CODE::U111));
            this->container->cont->fire4->setVisible(true);
            this->container->cont->fire4Case->setMouseEnabled(false);
        }
        else if (param1 == 5)
        {
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_09")
            {
                this->container->cont->achieve1->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve1->gotoAndStop(2);
            }
            this->container->cont->achieve1->icon->gotoAndStop(41);
            std::setText(this->container->cont->achieve1->nameTxt,I18N_VALUE(I18N_CODE::U065));
            std::setText(this->container->cont->achieve1->noteTxt,I18N_VALUE(I18N_CODE::U112));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_10")
            {
                this->container->cont->achieve2->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve2->gotoAndStop(2);
            }
            this->container->cont->achieve2->icon->gotoAndStop(42);
            std::setText(this->container->cont->achieve2->nameTxt,I18N_VALUE(I18N_CODE::U066));
            std::setText(this->container->cont->achieve2->noteTxt,I18N_VALUE(I18N_CODE::U113));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_11")
            {
                this->container->cont->achieve3->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve3->gotoAndStop(2);
            }
            this->container->cont->achieve3->icon->gotoAndStop(43);
            std::setText(this->container->cont->achieve3->nameTxt,I18N_VALUE(I18N_CODE::U067));
            std::setText(this->container->cont->achieve3->noteTxt,I18N_VALUE(I18N_CODE::U114));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_12")
            {
                this->container->cont->achieve4->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve4->gotoAndStop(2);
            }
            this->container->cont->achieve4->icon->gotoAndStop(44);
            std::setText(this->container->cont->achieve4->nameTxt,I18N_VALUE(I18N_CODE::U068));
            std::setText(this->container->cont->achieve4->noteTxt,I18N_VALUE(I18N_CODE::U115));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_13")
            {
                this->container->cont->achieve5->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve5->gotoAndStop(2);
            }
            this->container->cont->achieve5->icon->gotoAndStop(45);
            std::setText(this->container->cont->achieve5->nameTxt,I18N_VALUE(I18N_CODE::U069));
            std::setText(this->container->cont->achieve5->noteTxt,I18N_VALUE(I18N_CODE::U116));
            if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_14")
            {
                this->container->cont->achieve6->gotoAndStop(1);
            }
            else
            {
                this->container->cont->achieve6->gotoAndStop(2);
            }
            this->container->cont->achieve6->icon->gotoAndStop(46);
            std::setText(this->container->cont->achieve6->nameTxt,I18N_VALUE(I18N_CODE::U070));
            std::setText(this->container->cont->achieve6->noteTxt,I18N_VALUE(I18N_CODE::U117));
            this->container->cont->achieve7->setVisible(false);
            this->container->cont->achieve8->setVisible(false);
            this->container->cont->achieve9->setVisible(false);
            this->container->cont->achieve10->setVisible(false);
            this->container->cont->fire5->setVisible(true);
            this->container->cont->fire5Case->setMouseEnabled(false);
        }
        return;
    }// end function

    void Achievements::autoguidersButtons()  
    {
        this->autoguidesMouse_pt = CONVERT_TO_WORLD_POS(cocos2d::Point(this->mouseX, this->mouseY));
        this->autoguidesObject = NULL;
        this->autoguidesObject_pt = CONVERT_TO_WORLD_POS(this->container->cont->btnClose->localToGlobal(this->container->cont->btnClose->closeCase->getPosition()));
        this->autoguidesObjectWidth = this->container->cont->btnClose->closeCase.width / 2;
        this->autoguidesObjectHeight = this->container->cont->btnClose->closeCase.height / 2;
        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        {
            this->autoguidesObject = this->container->cont->btnClose->closeCase;
        }
        if (this->autoguidesObject)
        {
            this->tempObject = new Object();
            this->tempObject.target = this->autoguidesObject;
            this->mouseMoveHandler(this->tempObject);
        }
        return;
    }// end function

    void Achievements::close()  
    {
        if (!this->closeFlag)
        {
            this->closeFlag = true; 
            this->container->cont->setMouseChildren(false);
            this->container->cont->setMouseEnabled(false);
            Main::mainClass->levelsMenuClass->container->achieves->gotoAndStop(1);
            //this->stage.frameRate = 60;
        }
        return;
    }// end function

    void Achievements::kill()  
    {
        if (!this->dead)
        {
            this->dead = true;
            Main::mainClass->levelsMenuClass->removeChild(Main::mainClass->levelsMenuClass->achievementsClass);
            Main::mainClass->levelsMenuClass->achievementsClass = NULL;
            Main::mainClass->levelsMenuClass->manageListeners("on");
        }
        return;
    }// end function

	void Achievements::manageListeners(string param1)
	{
		if (param1 == "on")
		{
			if (useNodeEvent)
				std::globalNode = this;
			this->enableMouseHandler(true);
			this->enableFrameHandler(true);
		}
		else if (param1 == "off")
		{
			this->disableMouseHandler();
			this->disableFrameHandler();
		}
		return;
	}// end function
 
}
