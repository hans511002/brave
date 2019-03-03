#include "BaseHeaders.h"
#include "MiddleScreen.h"
#include "MainClass.h"
#include "PauseMenu.h"
#include "engine/World.h" 
#include "engine/towers/Tower.h"
#include "engine/towers/BuildTowerMenu.h"
#include "engine/towers/UltraTowerMenu.h"
#include "engine/towers/TowerMenu.h"

namespace screens
{
	PauseMenu_mc::PauseMenu_mc():MovieClip("screen","PauseMenu_mc","PauseMenu_mc")
	{
		this-> shadow=this->createCase("shadow");
		scroll = this->createMovieClipSub("scroll");
		scrollBtnSound =this->scroll->createMovieClipSub("btnSound");
		scrollBtnSoundSoundCase=this->scrollBtnSound->createCase("soundCase");
 		scrollBtnMusic = this->scroll->createMovieClipSub("btnMusic");
		scrollBtnMusicMusicCase = this->scrollBtnMusic->createCase("musicCase");
		scrollBtnRestart = this->scroll->createMovieClipSub("btnRestart");
		scrollBtnRestartArrow= this->scrollBtnRestart->createMovieClipSub("arrow");
		scrollBtnRestartRestartCase = this->scrollBtnRestart->createCase("restartCase");
		scrollBtnResume = this->scroll->createMovieClipSub("btnResume");
		scrollBtnResumeArrow = this->scrollBtnResume->createMovieClipSub("arrow");
		scrollBtnResumeResumeCase = this->scrollBtnResume->createCase("resumeCase");
		scrollBtnExit = this->scroll->createMovieClipSub("btnExit");
		scrollBtnExitArrow = this->scrollBtnExit->createMovieClipSub("arrow");
		this->scrollBtnExitExitCase= this->scrollBtnExit->createCase("exitCase");
	};
    PauseMenu::PauseMenu(): questionFlag(0),startMusicVolume(0)
    {
		init();
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
		cocos2d::Size size = this->container->getSprite("shadow")->getContentSize();
		float sy = Main::SCREEN_HEIGHT / size.height;
		float sx = (size.width - Main::SCREEN_WIDTH) / 2;
		//this->container->setPosition(0, Main::SCREEN_WIDTH);//600
		this->container->setScaleY(sy);
        this->container->stop();
        this->container->scroll->stop();
        this->container->scrollBtnMusic->stop();
        this->container->scrollBtnMusicMusicCase->stop();
        this->container->scrollBtnSound->stop();
        this->container->scrollBtnSoundSoundCase->stop(); 
        this->container->scrollBtnResume->stop();
        this->container->scrollBtnResumeArrow->stop();
        this->container->scrollBtnResumeResumeCase->stop();
        this->container->scrollBtnRestart->stop();
        this->container->scrollBtnRestartArrow->stop();
        this->container->scrollBtnRestartRestartCase->stop();
        this->container->scrollBtnExit->stop();
        this->container->scrollBtnExitArrow->stop();
        this->container->scrollBtnExitExitCase->stop();
        this->container->scrollBtnMusicMusicCase->setMouseEnabled(true);
        this->container->scrollBtnSoundSoundCase->setMouseEnabled(true); 
        this->container->scrollBtnResumeResumeCase->setMouseEnabled(true);
        this->container->scrollBtnRestartRestartCase->setMouseEnabled(true);
        this->container->scrollBtnExitExitCase->setMouseEnabled(true); 
        this->container->scroll->setMouseChildren(false);
        this->container->scroll->setMouseEnabled(false);
        this->container->scrollBtnResumeArrow->setVisible(false);
        this->container->scrollBtnRestartArrow->setVisible(false);
        this->container->scrollBtnExitArrow->setVisible(false);
        
        this->addChild(this->container);
        if (!AudioUtil::musicOn)
            this->container->scrollBtnMusic->gotoAndStop(4);
        if (!AudioUtil::soundOn)
            this->container->scrollBtnSound->gotoAndStop(4);
		this->manageListeners("on");
        return true;
    }// end function

    void PauseMenu::enterFrameHandler(float dt)
    {
        if (this->frameCounter < 30)
            this->frameCounter++;
        else
            this->frameCounter = 1;
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
                }
                else if (this->container->scroll->currentFrame == 24)
                {
                    this->openFlag = false;
                }
            }
        }
        else if (this->closeFlag)
        {
            if (AudioUtil::musicOn)
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
                    this->container->scrollBtnMusic->setAlpha(1);
                    this->container->scrollBtnSound->setAlpha(1); 
                    this->container->scrollBtnResume->setAlpha(1); 
                    this->container->scrollBtnRestart->setAlpha(1); 
                    this->container->scrollBtnExit->setAlpha(1);   
                    this->container->scrollBtnMusic->setMouseChildren(true);
                    this->container->scrollBtnMusic->setMouseEnabled(true); 
                    this->container->scrollBtnSound->setMouseChildren(true);
                    this->container->scrollBtnSound->setMouseEnabled(true); 
                    this->container->scrollBtnResume->setMouseChildren(true);
                    this->container->scrollBtnResume->setMouseEnabled(true); 
                    this->container->scrollBtnRestart->setMouseChildren(true);
                    this->container->scrollBtnRestart->setMouseEnabled(true); 
                    this->container->scrollBtnExit->setMouseChildren(true);
                    this->container->scrollBtnExit->setMouseEnabled(true);
                 }
            }
        }
        else if (this->questionFlag > 0)
        {
            
        }
        if (this->container->scrollBtnResumeArrow->isVisible())
        {
            if (this->container->scrollBtnResume->currentFrame > 1)
            {
                if (this->container->scrollBtnResumeArrow->currentFrame < this->container->scrollBtnResumeArrow->totalFrames)
                {
                    this->container->scrollBtnResumeArrow->gotoAndStop((this->container->scrollBtnResumeArrow->currentFrame + 1));
                }
            }
            else if (this->container->scrollBtnResumeArrow->currentFrame > 1)
            {
                if (this->container->scrollBtnResume->mouseEnabled)
                {
                    this->container->scrollBtnResumeArrow->gotoAndStop((this->container->scrollBtnResumeArrow->currentFrame - 1));
                }
                else if (this->container->scrollBtnResumeArrow->currentFrame != this->container->scrollBtnResumeArrow->totalFrames)
                {
                    this->container->scrollBtnResumeArrow->gotoAndStop(this->container->scrollBtnResumeArrow->totalFrames);
                }
            }
            else
            {
                this->container->scrollBtnResumeArrow->setVisible(false);
            }
        }
        if (this->container->scrollBtnRestartArrow->isVisible())
        {
            if (this->container->scrollBtnRestart->currentFrame > 1)
            {
                if (this->container->scrollBtnRestartArrow->currentFrame < this->container->scrollBtnRestartArrow->totalFrames)
                {
                    this->container->scrollBtnRestartArrow->gotoAndStop((this->container->scrollBtnRestartArrow->currentFrame + 1));
                }
            }
            else if (this->container->scrollBtnRestartArrow->currentFrame > 1)
            {
                if (this->container->scrollBtnRestart->mouseEnabled)
                {
                    this->container->scrollBtnRestartArrow->gotoAndStop((this->container->scrollBtnRestartArrow->currentFrame - 1));
                }
                else if (this->container->scrollBtnRestartArrow->currentFrame != this->container->scrollBtnRestartArrow->totalFrames)
                {
                    this->container->scrollBtnRestartArrow->gotoAndStop(this->container->scrollBtnRestartArrow->totalFrames);
                }
            }
            else
            {
                this->container->scrollBtnRestartArrow->setVisible(false);
            }
        }
        if (this->container->scrollBtnExitArrow->isVisible())
        {
            if (this->container->scrollBtnExit->currentFrame > 1)
            {
                if (this->container->scrollBtnExitArrow->currentFrame < this->container->scrollBtnExitArrow->totalFrames)
                {
                    this->container->scrollBtnExitArrow->gotoAndStop((this->container->scrollBtnExitArrow->currentFrame + 1));
                }
            }
            else if (this->container->scrollBtnExitArrow->currentFrame > 1)
            {
                if (this->container->scrollBtnExit->mouseEnabled)
                {
                    this->container->scrollBtnExitArrow->gotoAndStop((this->container->scrollBtnExitArrow->currentFrame - 1));
                }
                else if (this->container->scrollBtnExitArrow->currentFrame != this->container->scrollBtnExitArrow->totalFrames)
                {
                    this->container->scrollBtnExitArrow->gotoAndStop(this->container->scrollBtnExitArrow->totalFrames);
                }
            }
            else
            {
                this->container->scrollBtnExitArrow->setVisible(false);
            }
        }
        return;
    }// end function
	bool PauseMenu::preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType)
	{
		removeEventTarget(event, this);
		Vec2 pos = event->getLocationInView();
		switch (_mouseEventType)
		{
		case cocos2d::EventMouse::MouseEventType::MOUSE_NONE:
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_DOWN:
			if (event->currentTargets.size() > 1) {
				//removeEventTarget(event, "shadow");
				//removeEventTarget(event, "sphereCase", "fireCase");
			}
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_UP:
			if (event->currentTargets.size() > 1) {
			}
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_MOVE:
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_SCROLL:
			break;
		default:
			break;
		}
		event->reset();
		return false;
	};
    void PauseMenu::mouseMoveHandler(cocos2d::EventMouse *e)  
    {
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		if (!globalNode)EventNode::mouseMoveHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_MOVE))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		//return;
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			EventNode::beginTouchNode = event->target;
			if (targetName == "musicCase")
			{
				if (this->container->scrollBtnMusic->currentFrame == 1 || this->container->scrollBtnMusic->currentFrame == 4)
				{
					this->container->scrollBtnMusic->gotoAndStop((this->container->scrollBtnMusic->currentFrame + 1));
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->scrollBtnMusic->currentFrame == 2 || this->container->scrollBtnMusic->currentFrame == 5)
			{
				this->container->scrollBtnMusic->gotoAndStop((this->container->scrollBtnMusic->currentFrame - 1));
			}
			if (targetName == "soundCase")
			{
				if (this->container->scrollBtnSound->currentFrame == 1 || this->container->scrollBtnSound->currentFrame == 4)
				{
					this->container->scrollBtnSound->gotoAndStop((this->container->scrollBtnSound->currentFrame + 1));
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->scrollBtnSound->currentFrame == 2 || this->container->scrollBtnSound->currentFrame == 5)
			{
				this->container->scrollBtnSound->gotoAndStop((this->container->scrollBtnSound->currentFrame - 1));
			}
			if (targetName == "resumeCase")
			{
				if (this->container->scrollBtnResume->currentFrame == 1)
				{
					this->container->scrollBtnResume->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					if (!this->container->scrollBtnResumeArrow->isVisible())
						this->container->scrollBtnResumeArrow->setVisible(true);
				}
			}
			else if (this->container->scrollBtnResume->currentFrame == 2)
			{
				this->container->scrollBtnResume->gotoAndStop(1);
			}
			if (targetName == "restartCase")
			{
				if (this->container->scrollBtnRestart->currentFrame == 1)
				{
					this->container->scrollBtnRestart->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					if (!this->container->scrollBtnRestartArrow->isVisible())
						this->container->scrollBtnRestartArrow->setVisible(true);
				}
			}
			else if (this->container->scrollBtnRestart->currentFrame == 2)
			{
				this->container->scrollBtnRestart->gotoAndStop(1);
			}
			if (targetName == "exitCase")
			{
				if (this->container->scrollBtnExit->currentFrame == 1)
				{
					this->container->scrollBtnExit->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					if (!this->container->scrollBtnExitArrow->isVisible())
						this->container->scrollBtnExitArrow->setVisible(true);
				}
			}
			else if (this->container->scrollBtnExit->currentFrame == 2)
			{
				this->container->scrollBtnExit->gotoAndStop(1);
			}
		}
    }// end function

    void PauseMenu::mouseDownHandler(cocos2d::EventMouse *e) 
    {
		if (!globalNode)EventNode::mouseDownHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_DOWN))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		//Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			EventNode::beginTouchNode = event->target;

			if (targetName == "musicCase")
			{
				if (this->container->scrollBtnMusic->currentFrame == 2 || this->container->scrollBtnMusic->currentFrame == 5)
				{
					this->container->scrollBtnMusic->gotoAndStop((this->container->scrollBtnMusic->currentFrame + 1));
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "soundCase")
			{
				if (this->container->scrollBtnSound->currentFrame == 2 || this->container->scrollBtnSound->currentFrame == 5)
				{
					this->container->scrollBtnSound->gotoAndStop((this->container->scrollBtnSound->currentFrame + 1));
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "resumeCase")
			{
				if (this->container->scrollBtnResume->currentFrame == 2)
				{
					this->container->scrollBtnResume->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "restartCase")
			{
				if (this->container->scrollBtnRestart->currentFrame == 2)
				{
					this->container->scrollBtnRestart->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "exitCase")
			{
				if (this->container->scrollBtnExit->currentFrame == 2)
				{
					this->container->scrollBtnExit->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
		}
    }// end function

	void PauseMenu::mouseUpHandler(cocos2d::EventMouse * e)
	{
		if (!globalNode)EventNode::mouseUpHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_UP))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			if (targetName == "musicCase")
			{
				if (this->container->scrollBtnMusic->currentFrame == 3)
				{
					this->container->scrollBtnMusic->gotoAndStop(5);
					//AudioUtil::musicPausePosition = AudioUtil::musicChanel.position;
					AudioUtil::musicManage("off");
				}
				else if (this->container->scrollBtnMusic->currentFrame == 6)
				{
					this->container->scrollBtnMusic->gotoAndStop(2);
					AudioUtil::musicManage("on");
					if (this->world->wavesClass->nowWave == 0)
						AudioUtil::playMusic("Music_world_beforeBattle.mp3");// (1f);
					else
						AudioUtil::playMusic("Music_world_battle.mp3");//2f
				}
			}
			else if (this->container->scrollBtnMusic->currentFrame == 3 || this->container->scrollBtnMusic->currentFrame == 6)
			{
				this->container->scrollBtnMusic->gotoAndStop(this->container->scrollBtnMusic->currentFrame - 2);
			}
			if (targetName == "soundCase")
			{
				if (this->container->scrollBtnSound->currentFrame == 3)
				{
					this->container->scrollBtnSound->gotoAndStop(5);
					AudioUtil::soundManage("off");
				}
				else if (this->container->scrollBtnSound->currentFrame == 6)
				{
					this->container->scrollBtnSound->gotoAndStop(2);
					AudioUtil::soundManage("on");
				}
			}
			else if (this->container->scrollBtnSound->currentFrame == 3 || this->container->scrollBtnSound->currentFrame == 6)
			{
				this->container->scrollBtnSound->gotoAndStop(this->container->scrollBtnSound->currentFrame - 2);
			}
			if (targetName == "resumeCase")
			{
				if (this->container->scrollBtnResume->currentFrame == 3)
				{
					this->close();
				}
			}
			else if (this->container->scrollBtnResume->currentFrame == 3)
			{
				this->container->scrollBtnResume->gotoAndStop(1);
			}
			if (targetName == "restartCase")
			{
				if (this->container->scrollBtnRestart->currentFrame == 3)
				{
					Main::mainClass->addNewScreen("World");
				}
			}
			else if (this->container->scrollBtnRestart->currentFrame == 3)
			{
				this->container->scrollBtnRestart->gotoAndStop(1);
			}
			if (targetName == "exitCase")
			{
				if (this->container->scrollBtnExit->currentFrame == 3)
				{
					Main::mainClass->addNewScreen("LevelsMenu");
				}
			}
			else if (this->container->scrollBtnExit->currentFrame == 3)
			{
				this->container->scrollBtnExit->gotoAndStop(1);
			}
		}
	}// end function
 
    void PauseMenu::close()
    {
        if (!this->closeFlag)
        {
            this->closeFlag = true;
            this->container->scrollBtnResume->gotoAndStop(2); 
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
    //            AudioUtil::musicChanel.soundTransform = new SoundTransform(this->startMusicVolume, 0f);
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
