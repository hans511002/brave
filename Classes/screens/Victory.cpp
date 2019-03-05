#include "Victory.h"   
#include "engine/world.h"   

using namespace engine;

namespace screens
{

	WinMenuBase::WinMenuBase(const string & name) :MovieClip("screen", name, "WinMenu_mc")
	{
		this->first = this->createMovieClipSub("first");
		this->firstStars = this->first->createMovieClipSub("stars");
		this->firstScroll = this->first->createMovieClipSub("scroll");
		this->firstScrollLogo = this->firstScroll->createMovieClipSub("logo");
		this->firstScrollLogoLogoCase = this->firstScrollLogo->createCase("logoCase");

		this->firstScrollBtnContinue = this->firstScroll->createMovieClipSub("btnContinue");
		this->firstScrollBtnContinueArrow = this->firstScrollBtnContinue->createMovieClipSub("aArrow");
		this->firstScrollBtnContinueContinueCase = this->firstScrollBtnContinue->createCase("case");
		this->firstScrollBtnRestart = this->firstScroll->createMovieClipSub("btnRestart", true);
		this->firstScrollBtnRestartArrow = this->firstScrollBtnRestart->createMovieClipSub("aArrow");
		this->firstScrollBtnRestartRestartCase = this->firstScrollBtnRestart->createCase("case");

		this->firstSponsor = NULL;
		this->firstSponsorLink1 = NULL;
		this->firstSponsorLink2 = NULL;
		this->firstSponsorLink3 = NULL;
		this->firstSponsorLink1Link1Case = NULL;
		this->firstSponsorLink2Link2Case = NULL;
		this->firstSponsorLink3Link3Case = NULL;
	}
	WinMenu_mc::WinMenu_mc() :WinMenuBase("WinMenu_mc")
	{
	}
	WinMenuFinish_mc::WinMenuFinish_mc() : WinMenuBase("WinMenuFinish_mc")
	{
		this->firstSponsor = this->first->createMovieClipSub("sponsor");
		this->firstSponsorLink1 = this->firstSponsor->createMovieClipSub("link1");
		this->firstSponsorLink2 = this->firstSponsor->createMovieClipSub("link2");
		this->firstSponsorLink3 = this->firstSponsor->createMovieClipSub("link3");
		this->firstSponsorLink1Link1Case = this->firstSponsorLink1->createCase("link1Case");
		this->firstSponsorLink2Link2Case = this->firstSponsorLink2->createCase("link2Case");
		this->firstSponsorLink3Link3Case = this->firstSponsorLink3->createCase("link3Case");
	}
	WinSurvMenu_mc::WinSurvMenu_mc() :WinMenuBase("WinSurvMenu_mc")
	{
	}
	Victory::Victory()
	{
		//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
		init();
		return;
	}// end function

	bool Victory::init()
	{
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
		//this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
		//this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
		//this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
		//Main.mainClass.stage.frameRate = 30;
		this->world = Main::mainClass->worldClass;
		this->world->manageListeners("off");
		this->world->worldInterface->breaking();
		if (this->world->saveBox->getIntValue("complexityLevel") < 4)
		{
			if (this->world->nowLevel < 15)
			{
				this->container = new WinMenu_mc();
			}
			else
			{
				this->container = new WinMenuFinish_mc();
				this->container->firstSponsor->stop();
				this->container->firstSponsor->setMouseEnabled(false);
				this->container->firstSponsor->setMouseChildren(false);
			}
		}
		else
		{
			this->container = new WinSurvMenu_mc();
		}
		this->container->stop();
		this->container->first->stop();
		this->container->firstStars->stop();
		this->container->firstScroll->stop();
		this->container->firstScrollBtnContinue->stop();
		this->container->firstScrollBtnContinueArrow->stop();
		this->container->firstScrollBtnRestart->stop();
		this->container->firstScrollBtnRestartArrow->stop();
		this->container->firstScrollBtnContinueContinueCase->setMouseEnabled(true);
		this->container->firstScrollBtnRestartRestartCase->setMouseEnabled(true);
		this->container->first->setMouseChildren(false);
		this->container->first->mouseEnabled = false;
		this->container->firstScrollBtnContinueArrow->setVisible(false);
		this->container->firstScrollBtnRestartArrow->setVisible(false);

		this->addChild(this->container);
		if (this->world->saveBox->getIntValue("complexityLevel") < 4)
		{
			if (this->world->live >= 18)
			{
				this->starsFlag = 3;
				if (Main::mainClass->saveBoxClass->getIntValue("training_91") == 0)
				{
					Main::mainClass->saveBoxClass->setValue("training_91", Main::mainClass->saveBoxClass->playLevel);
				}
			}
			else if (this->world->live >= 8)
			{
				this->starsFlag = 2;
			}
			else
			{
				this->starsFlag = 1;
			}
			if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", Main::mainClass->saveBoxClass->playLevel - 1) < this->starsFlag)
			{
				Main::mainClass->saveBoxClass->setValue("stars", Main::mainClass->saveBoxClass->getIntValue("stars")
					+ (this->starsFlag - Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", Main::mainClass->saveBoxClass->playLevel - 1)));
				Main::mainClass->saveBoxClass->setValue("newStarsForLevel", Main::mainClass->saveBoxClass->playLevel);
				Main::mainClass->saveBoxClass->setValue("starsOfLevels", Main::mainClass->saveBoxClass->playLevel - 1, this->starsFlag);
			}
		}
		else if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", Main::mainClass->saveBoxClass->playLevel - 1) < 4)
		{
			this->starsFlag = 1;
			if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", Main::mainClass->saveBoxClass->playLevel - 1) == 3)
			{
				Main::mainClass->saveBoxClass->setValue("stars", Main::mainClass->saveBoxClass->getIntValue("stars") + 1);
				Main::mainClass->saveBoxClass->setValue("newStarsForLevel", Main::mainClass->saveBoxClass->playLevel);
				int stars = Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", Main::mainClass->saveBoxClass->playLevel - 1);
				Main::mainClass->saveBoxClass->setValue("starsOfLevels", Main::mainClass->saveBoxClass->playLevel - 1, stars + 1);
			}
		}
		if (Main::mainClass->saveBoxClass->playLevel < 15)
		{
			if (Main::mainClass->saveBoxClass->getIntValue("openLevels", Main::mainClass->saveBoxClass->playLevel) == 0)
			{
				Main::mainClass->saveBoxClass->setValue("newLevel", Main::mainClass->saveBoxClass->playLevel + 1);
				Main::mainClass->saveBoxClass->setValue("openLevels", Main::mainClass->saveBoxClass->playLevel, 1);
				if (Main::mainClass->saveBoxClass->playLevel == 1)
				{
					if (this->world->saveBox->getIntValue("complexityLevel") < 4)
					{
						if (Main::mainClass->saveBoxClass->getIntValue("training_9") == 0)
							Main::mainClass->saveBoxClass->setValue("training_9", 1);
					}
				}
			}
		}
		if (Main::mainClass->saveBoxClass->getIntValue("levelsFinish", Main::mainClass->saveBoxClass->playLevel - 1)
			< this->world->saveBox->getIntValue("complexityLevel") && this->world->saveBox->getIntValue("complexityLevel") < 4)
		{
			Main::mainClass->saveBoxClass->setValue("levelsFinish", Main::mainClass->saveBoxClass->playLevel - 1, this->world->saveBox->getIntValue("complexityLevel"));
		}
		if (this->world->castFireCounter == 0 && this->world->castIceCounter == 0 && this->world->castStoneCounter == 0 && this->world->castLevinCounter == 0 && this->world->castGetAllCounter == 0)
		{
			this->world->achieveManage("notCast");
		}
		int complexityLevel = this->world->saveBox->getIntValue("complexityLevel");
		if (complexityLevel == 1 || complexityLevel == 2 || complexityLevel == 3 || complexityLevel == 4)
		{
			this->world->saveBox->setValue("complexityLevel", complexityLevel + 1);
		}
		if (this->world->live == this->world->liveMax)
		{
			int addit_completeLevelsWithAllLivesCounter = this->world->saveBox->getIntValue("addit_completeLevelsWithAllLivesCounter");
			this->world->saveBox->setValue("addit_completeLevelsWithAllLivesCounter", addit_completeLevelsWithAllLivesCounter + 1);
		}
		if (this->world->saveBox->getIntValue("addit_completeHardLevelsCounter") == 10)
		{
			this->world->achieveManage("complete_10_hardLevels");
		}
		if (this->world->saveBox->getIntValue("addit_completeSurvivalLevelsCounter") == 10)
		{
			this->world->achieveManage("complete_10_survivalLevels");
		}
		if (this->world->saveBox->getIntValue("addit_completeLevelsWithAllLivesCounter") == 10)
		{
			this->world->achieveManage("complete_10_withAllLives");
		}
		this->manageListeners("on");
		return true;
	}// end function

	void Victory::enterFrameHandler(float dt)
	{
		if (this->frameCounter < 30)
			this->frameCounter++;
		else
			this->frameCounter = 1;
		if (!this->firstSoundPlay)
		{
			if (this->frameCounter < 10)
			{
				if (AudioUtil::musicOn)
				{
					if (AudioUtil::getMusicVolume() > 0)
					{
						AudioUtil::setMusicVolume(AudioUtil::getMusicVolume() - 0.1f);
					}
					else if (AudioUtil::getMusicVolume() != 0)
					{
						AudioUtil::setMusicVolume(0.0f);
					}
				}
			}
			else
			{
				this->firstSoundPlay = true;
				AudioUtil::stopAll();
				AudioUtil::playSound("Snd_menu_victory.mp3");
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
				this->container->first->setMouseChildren(true);
				this->container->first->mouseEnabled = true;
				cocos2d::Point tempObject(Main::mouseX, Main::mouseY);
				if (this->container->firstScrollBtnContinueContinueCase->hitTest(tempObject))
				{
					this->container->firstScrollBtnContinue->gotoAndStop(2);
				}
				if (this->container->firstScrollBtnRestartRestartCase->hitTest(tempObject)) {
					this->container->firstScrollBtnRestart->gotoAndStop(2);
				}
			}
			if (this->container->currentFrame > 8)
			{
				if (this->container->firstScroll->currentFrame < this->container->firstScroll->totalFrames)
				{
					this->container->firstScroll->gotoAndStop((this->container->firstScroll->currentFrame + 1));
					this->container->firstScrollBtnContinue->stop();
					this->container->firstScrollBtnContinueArrow->stop();
					this->container->firstScrollBtnRestart->stop();
					this->container->firstScrollBtnRestartArrow->stop();
					this->container->firstScrollBtnContinueContinueCase->setMouseEnabled(true);
					this->container->firstScrollBtnRestartRestartCase->setMouseEnabled(true);
					this->container->firstScrollBtnContinueArrow->setVisible(false);
					this->container->firstScrollBtnRestartArrow->setVisible(false);
				}
			}
		}
		else if (this->starsFlag > 0)
		{
			if (this->starsFlag == 1)
			{
				if (this->container->firstStars->currentFrame < 17)
				{
					this->container->firstStars->gotoAndStop((this->container->firstStars->currentFrame + 1));
				}
				else
				{
					this->starsFlag = 0;
					if (this->container->firstSponsor)
					{
						this->container->firstSponsor->gotoAndStop(2);
					}
				}
			}
			else if (this->starsFlag == 2)
			{
				if (this->container->firstStars->currentFrame < 29)
				{
					this->container->firstStars->gotoAndStop((this->container->firstStars->currentFrame + 1));
				}
				else
				{
					this->starsFlag = 0;
					if (this->container->firstSponsor)
					{
						this->container->firstSponsor->gotoAndStop(2);
					}
				}
			}
			else if (this->starsFlag == 3)
			{
				if (this->container->firstStars->currentFrame < this->container->firstStars->totalFrames)
				{
					this->container->firstStars->gotoAndStop((this->container->firstStars->currentFrame + 1));
				}
				else
				{
					this->starsFlag = 0;
					if (this->container->firstSponsor)
					{
						this->container->firstSponsor->gotoAndStop(2);
					}
				}
			}
			if (this->container->firstStars->currentFrame == 10 || this->container->firstStars->currentFrame == 19 || this->container->firstStars->currentFrame == 31)
			{
				AudioUtil::playSound("Snd_menu_victoryStar.mp3");
			}
		}
		if (this->container->firstScrollBtnContinue->currentFrame > 1)
		{
			if (!this->container->firstScrollBtnContinueArrow->isVisible())
			{
				this->container->firstScrollBtnContinueArrow->setVisible(true);
			}
			else if (this->container->firstScrollBtnContinueArrow->currentFrame < this->container->firstScrollBtnContinueArrow->totalFrames)
			{
				this->container->firstScrollBtnContinueArrow->gotoAndStop((this->container->firstScrollBtnContinueArrow->currentFrame + 1));
			}
		}
		else if (this->container->firstScrollBtnContinueArrow->currentFrame > 1)
		{
			this->container->firstScrollBtnContinueArrow->gotoAndStop((this->container->firstScrollBtnContinueArrow->currentFrame - 1));
		}
		else if (this->container->firstScrollBtnContinueArrow->isVisible())
		{
			this->container->firstScrollBtnContinueArrow->setVisible(false);
		}
		if (this->container->firstScrollBtnRestart->currentFrame > 1)
		{
			if (!this->container->firstScrollBtnRestartArrow->isVisible())
			{
				this->container->firstScrollBtnRestartArrow->setVisible(true);
			}
			else if (this->container->firstScrollBtnRestartArrow->currentFrame < this->container->firstScrollBtnRestartArrow->totalFrames)
			{
				this->container->firstScrollBtnRestartArrow->gotoAndStop((this->container->firstScrollBtnRestartArrow->currentFrame + 1));
			}
		}
		else if (this->container->firstScrollBtnRestartArrow->currentFrame > 1)
		{
			this->container->firstScrollBtnRestartArrow->gotoAndStop((this->container->firstScrollBtnRestartArrow->currentFrame - 1));
		}
		else if (this->container->firstScrollBtnRestartArrow->isVisible())
		{
			this->container->firstScrollBtnRestartArrow->setVisible(false);
		}
		if (this->container->firstSponsor)
		{
			if (this->container->firstSponsor->currentFrame > 1)
			{
				if (this->container->firstSponsor->currentFrame < this->container->firstSponsor->totalFrames)
				{
					this->container->firstSponsor->gotoAndStop((this->container->firstSponsor->currentFrame + 1));
					if (this->container->firstSponsorLink1)
					{
						if (!this->container->firstSponsorLink1Link1Case->mouseEnabled)
						{
							this->container->firstSponsorLink1->stop();
							this->container->firstSponsorLink1Link1Case->setMouseEnabled(true);
							//(this->container->firstSponsorLink1Cont->aa_video as FLVPlayback).addEventListener(VideoEvent.COMPLETE, this->link1Play);
						}
					}
					if (this->container->firstSponsorLink2)
					{
						if (!this->container->firstSponsorLink2Link2Case->mouseEnabled)
						{
							this->container->firstSponsorLink2->stop();
							//this->container->firstSponsorLink2Cont->stop();
							this->container->firstSponsorLink2Link2Case->stop();
							this->container->firstSponsorLink2Link2Case->setMouseEnabled(true);
							// (this->container->firstSponsorLink2Cont->wh_video as FLVPlayback).addEventListener(VideoEvent.COMPLETE, this->link2Play);
						}
					}
					if (this->container->firstSponsorLink3)
					{
						if (!this->container->firstSponsorLink3Link3Case->mouseEnabled)
						{
							this->container->firstSponsorLink3->stop();
							//this->container->firstSponsorLink3Cont->stop();
							this->container->firstSponsorLink3Link3Case->stop();
							this->container->firstSponsorLink3Link3Case->setMouseEnabled(true);
							//(this->container->firstSponsorLink3Cont->mk_video as FLVPlayback).addEventListener(VideoEvent.COMPLETE, this->link3Play);
						}
					}
					if (this->container->firstSponsor->currentFrame == this->container->firstSponsor->totalFrames)
					{
						this->container->firstSponsor->setMouseEnabled(true);
						this->container->firstSponsor->setMouseChildren(true);
					}
				}
			}
		}
		return;
	}// end function

	void Victory::mouseMoveHandler(cocos2d::EventMouse * e)
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
			if (targetName == "continueCase")
			{
				if (this->container->firstScrollBtnContinue->currentFrame == 1)
				{
					this->container->firstScrollBtnContinue->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->firstScrollBtnContinue->currentFrame == 2)
			{
				this->container->firstScrollBtnContinue->gotoAndStop(1);
			}
			if (targetName == "restartCase")
			{
				if (this->container->firstScrollBtnRestart->currentFrame == 1)
				{
					this->container->firstScrollBtnRestart->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->firstScrollBtnRestart->currentFrame == 2)
			{
				this->container->firstScrollBtnRestart->gotoAndStop(1);
			}
			if (this->container->firstSponsor)
			{
				if (this->container->firstSponsorLink1)
				{
					if (targetName == "link1Case")
					{
						if (this->container->firstSponsorLink1->currentFrame == 1)
						{
							this->container->firstSponsorLink1->gotoAndStop(2);
							AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
						}
					}
					else if (this->container->firstSponsorLink1->currentFrame == 2)
					{
						this->container->firstSponsorLink1->gotoAndStop(1);
					}
				}
				if (this->container->firstSponsorLink2)
				{
					if (targetName == "link2Case")
					{
						if (this->container->firstSponsorLink2->currentFrame == 1)
						{
							this->container->firstSponsorLink2->gotoAndStop(2);
							AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
						}
					}
					else if (this->container->firstSponsorLink2->currentFrame == 2)
					{
						this->container->firstSponsorLink2->gotoAndStop(1);
					}
				}
				if (this->container->firstSponsorLink3)
				{
					if (targetName == "link3Case")
					{
						if (this->container->firstSponsorLink3->currentFrame == 1)
						{
							this->container->firstSponsorLink3->gotoAndStop(2);
							AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
						}
					}
					else if (this->container->firstSponsorLink3->currentFrame == 2)
					{
						this->container->firstSponsorLink3->gotoAndStop(1);
					}
				}
			}
		}
	}// end function

	void Victory::mouseDownHandler(cocos2d::EventMouse * e)
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
			if (targetName == "continueCase")
			{
				if (this->container->firstScrollBtnContinue->currentFrame == 2)
				{
					this->container->firstScrollBtnContinue->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "restartCase")
			{
				if (this->container->firstScrollBtnRestart->currentFrame == 2)
				{
					this->container->firstScrollBtnRestart->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			if (this->container->firstSponsor)
			{
				if (this->container->firstSponsorLink1)
				{
					if (targetName == "link1Case")
					{
						if (this->container->firstSponsorLink1->currentFrame == 2)
						{
							this->container->firstSponsorLink1->gotoAndStop(3);
							AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
						}
					}
				}
				if (this->container->firstSponsorLink2)
				{
					if (targetName == "link2Case")
					{
						if (this->container->firstSponsorLink2->currentFrame == 2)
						{
							this->container->firstSponsorLink2->gotoAndStop(3);
							AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
						}
					}
				}
				if (this->container->firstSponsorLink3)
				{
					if (targetName == "link3Case")
					{
						if (this->container->firstSponsorLink3->currentFrame == 2)
						{
							this->container->firstSponsorLink3->gotoAndStop(3);
							AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
						}
					}
				}
			}
		}
	}// end function

	void Victory::mouseUpHandler(cocos2d::EventMouse * e)
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
			if (targetName == "continueCase")
			{
				if (this->container->firstScrollBtnContinue->currentFrame == 3)
				{
					this->container->firstScrollBtnContinue->gotoAndStop(2);
					if (this->container->firstSponsor)
					{

					}
					Main::mainClass->addNewScreen("LevelsMenu");
					//Main.mainClass.testingClass = NULL;
				}
			}
			else if (this->container->firstScrollBtnContinue->currentFrame == 3)
			{
				this->container->firstScrollBtnContinue->gotoAndStop(1);
			}
			if (targetName == "restartCase")
			{
				if (this->container->firstScrollBtnRestart->currentFrame == 3)
				{
					this->container->firstScrollBtnRestart->gotoAndStop(2);
					if (this->container->firstSponsor)
					{
					}
					Main::mainClass->addNewScreen("World");
					//Main::mainClass->testingClass = NULL;
				}
			}
			else if (this->container->firstScrollBtnRestart->currentFrame == 3)
			{
				this->container->firstScrollBtnRestart->gotoAndStop(1);
			}
			if (this->container->firstSponsor)
			{
				if (this->container->firstSponsorLink1)
				{
					if (targetName == "link1Case")
					{
						if (this->container->firstSponsorLink1->currentFrame == 3)
						{
							this->container->firstSponsorLink1->gotoAndStop(2);
							//navigateToURL(new URLRequest("http://ru.y8.com/games/asgard_attack"));
						}
					}
					else if (this->container->firstSponsorLink1->currentFrame == 3)
					{
						this->container->firstSponsorLink1->gotoAndStop(1);
					}
				}
				if (this->container->firstSponsorLink2)
				{
					if (targetName == "link2Case")
					{
						if (this->container->firstSponsorLink2->currentFrame == 3)
						{
							this->container->firstSponsorLink2->gotoAndStop(2);
							//navigateToURL(new URLRequest("http://ru.y8.com/games/war_heroes"));
						}
					}
					else if (this->container->firstSponsorLink2->currentFrame == 3)
					{
						this->container->firstSponsorLink2->gotoAndStop(1);
					}
				}
				if (this->container->firstSponsorLink3)
				{
					if (targetName == "link3Case")
					{
						if (this->container->firstSponsorLink3->currentFrame == 3)
						{
							this->container->firstSponsorLink3->gotoAndStop(2);
							//navigateToURL(new URLRequest("http://ru.y8.com/games/mighty_knight_2"));
						}
					}
					else if (this->container->firstSponsorLink3->currentFrame == 3)
					{
						this->container->firstSponsorLink3->gotoAndStop(1);
					}
				}
			}
		}
	}// end function

	void Victory::link1Play(cocos2d::Event *e)
	{
		if (this->container->firstSponsor)
		{
			//(this->container->firstSponsorLink1Cont->aa_video as FLVPlayback).play();
		}
		return;
	}// end function

	void Victory::link2Play(cocos2d::Event *e)
	{
		if (this->container->firstSponsor)
		{
			//(this->container->firstSponsorLink2Cont->wh_video as FLVPlayback).play();
		}
		return;
	}// end function

	void Victory::link3Play(cocos2d::Event *e)
	{
		if (this->container->firstSponsor)
		{
			//(this->container->firstSponsorLink3Cont->mk_video as FLVPlayback).play();
		}
		return;
	}// end function

	void Victory::removeLinksListeners()
	{
		if (this->container->firstSponsor)
		{
			if (this->container->firstSponsorLink1)
			{
				//(this->container->firstSponsorLink1Cont->aa_video as FLVPlayback).removeEventListener(VideoEvent.COMPLETE, this->link1Play);
			}
			if (this->container->firstSponsorLink2)
			{
				//(this->container->firstSponsorLink2Cont->wh_video as FLVPlayback).removeEventListener(VideoEvent.COMPLETE, this->link2Play);
			}
			if (this->container->firstSponsorLink3)
			{
				//(this->container->firstSponsorLink3Cont->mk_video as FLVPlayback).removeEventListener(VideoEvent.COMPLETE, this->link3Play);
			}
		}
		return;
	}// end function

}
