
#include "engine/World.h"   
#include "MainClass.h"
#include "Achievements.h"   
#include "LevelsMenu.h"

namespace screens
{
	ContAchieve::ContAchieve(MC *mc, const std::string &  slot, const string &  defAniName) :MovieClipSub(mc, slot, defAniName)
	{
		this->nameTXT = this->createText("nameTXT");
		this->noteTXT = this->createText("noteTXT");
		icon = this->createMovieClipSub("icon");
	};

	Achievements_mc::Achievements_mc() :MovieClip("screen/", "Achievements_mc", "Achievements_mc")
	{
		shadow = this->createCase("shadow");
		this->cont = this->createMovieClipSub("cont");
		this->contAchieve1 = this->cont->createMovieClipSub<ContAchieve>("achieve1");
		this->contAchieve2 = this->cont->createMovieClipSub<ContAchieve>("achieve2");
		this->contAchieve3 = this->cont->createMovieClipSub<ContAchieve>("achieve3");
		this->contAchieve4 = this->cont->createMovieClipSub<ContAchieve>("achieve4");
		this->contAchieve5 = this->cont->createMovieClipSub<ContAchieve>("achieve5");
		this->contAchieve6 = this->cont->createMovieClipSub<ContAchieve>("achieve6");
		this->contAchieve7 = this->cont->createMovieClipSub<ContAchieve>("achieve7");
		this->contAchieve8 = this->cont->createMovieClipSub<ContAchieve>("achieve8");
		this->contAchieve9 = this->cont->createMovieClipSub<ContAchieve>("achieve9");
		this->contAchieve10 = this->cont->createMovieClipSub<ContAchieve>("achieve10");

		this->contFire1Case = this->cont->createCase("fire1Case");
		this->contFire2Case = this->cont->createCase("fire2Case");
		this->contFire3Case = this->cont->createCase("fire3Case");
		this->contFire4Case = this->cont->createCase("fire4Case");
		this->contFire5Case = this->cont->createCase("fire5Case");

		this->contFire1 = this->cont->createMovieClipSub("fire1");
		this->contFire2 = this->cont->createMovieClipSub("fire2");
		this->contFire3 = this->cont->createMovieClipSub("fire3");
		this->contFire4 = this->cont->createMovieClipSub("fire4");
		this->contFire5 = this->cont->createMovieClipSub("fire5");

		contBtnClose = this->cont->createMovieClipSub("btnClose");
		contBtnBack = this->cont->createMovieClipSub("btnBack");
		contBtnForward = this->cont->createMovieClipSub("btnForward");
		contBtnCloseCloseCase = this->contBtnClose->createCase("closeCase");
		contBtnBackArrowCase = this->contBtnBack->createCase("arrowCase");
		contBtnForwardArrowCase = this->contBtnForward->createCase("arrowCase");

	};


	Achievements::Achievements() :fireFrame(0), container(0)
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
		this->manageListeners("on");
		this->container = new Achievements_mc();
		this->container->back = new Back_mc();
		this->addChild(this->container->back);
		this->container->back->setPosition(0, Main::SCREEN_HEIGHT - 100);
		this->container->stop();
		this->container->back->stop();
		this->container->back->backCase->setMouseEnabled(true);
		this->container->cont->stop();
		this->container->contAchieve1->stop();
		this->container->contAchieve2->stop();
		this->container->contAchieve3->stop();
		this->container->contAchieve4->stop();
		this->container->contAchieve5->stop();
		this->container->contAchieve6->stop();
		this->container->contAchieve7->stop();
		this->container->contAchieve8->stop();
		this->container->contAchieve9->stop();
		this->container->contAchieve10->stop();
		this->container->contBtnBack->stop();
		this->container->contBtnBackArrowCase->stop();
		this->container->contBtnForward->stop();
		this->container->contBtnForwardArrowCase->stop();
		this->container->contBtnClose->stop();
		this->container->contBtnCloseCloseCase->stop();
		this->container->contFire1->stop();
		this->container->contFire2->stop();
		this->container->contFire3->stop();
		this->container->contFire4->stop();
		this->container->contFire5->stop();
		this->container->contFire1Case->stop();
		this->container->contFire2Case->stop();
		this->container->contFire3Case->stop();
		this->container->contFire4Case->stop();
		this->container->contFire5Case->stop();
		this->container->contBtnBackArrowCase->setMouseEnabled(true);
		this->container->contBtnForwardArrowCase->setMouseEnabled(true);
		this->container->contBtnCloseCloseCase->setMouseEnabled(true);
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
		if (this->container->contFire1->isVisible())
		{
			if (this->fireFrame < this->container->contFire1->totalFrames)
			{
				this->fireFrame++;
			}
			else
			{
				this->fireFrame = 1;
			}
			this->container->contFire1->gotoAndStop(this->fireFrame);
		}
		else if (this->container->contFire2->isVisible())
		{
			if (this->fireFrame < this->container->contFire2->totalFrames)
			{
				this->fireFrame++;
			}
			else
			{
				this->fireFrame = 1;
			}
			this->container->contFire2->gotoAndStop(this->fireFrame);
		}
		else if (this->container->contFire3->isVisible())
		{
			if (this->fireFrame < this->container->contFire3->totalFrames)
			{
				this->fireFrame++;
			}
			else
			{
				this->fireFrame = 1;
			}
			this->container->contFire3->gotoAndStop(this->fireFrame);
		}
		else if (this->container->contFire4->isVisible())
		{
			if (this->fireFrame < this->container->contFire4->totalFrames)
			{
				this->fireFrame++;
			}
			else
			{
				this->fireFrame = 1;
			}
			this->container->contFire4->gotoAndStop(this->fireFrame);
		}
		else if (this->container->contFire5->isVisible())
		{
			if (this->fireFrame < this->container->contFire5->totalFrames)
			{
				this->fireFrame++;
			}
			else
			{
				this->fireFrame = 1;
			}
			this->container->contFire5->gotoAndStop(this->fireFrame);
		}
		return;
	}// end function

	void Achievements::mouseMoveHandler(cocos2d::EventMouse *e)
	{
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
		string targetName = event->target->getName();
		string parentName = event->target->getParent()->getParent()->getName();
		if (targetName == "backCase")
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
		if (targetName == "closeCase")
		{
			if (this->container->contBtnClose->currentFrame == 1)
			{
				this->container->contBtnClose->gotoAndStop(2);
				AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
			}
		}
		else if (this->container->contBtnClose->currentFrame == 2)
		{
			this->container->contBtnClose->gotoAndStop(1);
		}
		if (parentName == "btnBack")
		{
			if (this->container->contBtnBack->currentFrame == 1)
			{
				this->container->contBtnBack->gotoAndStop(2);
				AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
			}
		}
		else if (this->container->contBtnBack->currentFrame == 2)
		{
			this->container->contBtnBack->gotoAndStop(1);
		}
		if (parentName == "btnForward")
		{
			if (this->container->contBtnForward->currentFrame == 1)
			{
				this->container->contBtnForward->gotoAndStop(2);
				AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
			}
		}
		else if (this->container->contBtnForward->currentFrame == 2)
		{
			this->container->contBtnForward->gotoAndStop(1);
		}
		if (targetName == "fire1Case")
		{
			AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);

		}
		else if (this->container->contFire1Case->mouseMoveFlag)
		{
			this->container->contFire1Case->mouseMoveFlag = false;
		}
		if (targetName == "fire2Case")
		{
			AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
		}
		else if (this->container->contFire2Case->mouseMoveFlag)
		{
			this->container->contFire2Case->mouseMoveFlag = false;
		}
		if (targetName == "fire3Case")
		{
			AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
		}
		else if (this->container->contFire3Case->mouseMoveFlag)
		{
			this->container->contFire3Case->mouseMoveFlag = false;
		}
		if (targetName == "fire4Case")
		{
			AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
		}
		else if (this->container->contFire4Case->mouseMoveFlag)
		{
			this->container->contFire4Case->mouseMoveFlag = false;
		}
		if (targetName == "fire5Case")
		{
			AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
		}
		else if (this->container->contFire5Case->mouseMoveFlag)
		{
			this->container->contFire5Case->mouseMoveFlag = false;
		}
		return;
	}// end function

	void Achievements::mouseDownHandler(cocos2d::EventMouse * e)
	{
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
		string targetName = event->target->getName();
		string parentName = event->target->getParent()->getParent()->getName();
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
				if (this->container->contBtnClose->currentFrame == 2)
				{
					this->container->contBtnClose->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (parentName == "btnBack")
			{
				if (this->container->contBtnBack->currentFrame == 2)
				{
					this->container->contBtnBack->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (parentName == "btnForward")
			{
				if (this->container->contBtnForward->currentFrame == 2)
				{
					this->container->contBtnForward->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "fire1Case")
			{
				if (this->container->contFire1Case->mouseEnabled)
				{
					this->pageManage(1);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "fire2Case")
			{
				if (this->container->contFire2Case->mouseEnabled)
				{
					this->pageManage(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "fire3Case")
			{
				if (this->container->contFire3Case->mouseEnabled)
				{
					this->pageManage(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "fire4Case")
			{
				if (this->container->contFire4Case->mouseEnabled)
				{
					this->pageManage(4);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "fire5Case")
			{
				if (this->container->contFire5Case->mouseEnabled)
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

	void Achievements::mouseUpHandler(cocos2d::EventMouse * e)
	{
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
		string targetName = event->target->getName();
		string parentName = event->target->getParent()->getParent()->getName();
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
			if (this->container->contBtnClose->currentFrame == 3)
			{
				this->container->contBtnClose->gotoAndStop(2);
				this->close();
			}
		}
		else if (this->container->contBtnClose->currentFrame == 3)
		{
			this->container->contBtnClose->gotoAndStop(1);
		}
		if (parentName == "btnBack")
		{
			if (this->container->contBtnBack->currentFrame == 3)
			{
				this->container->contBtnBack->gotoAndStop(2);
				this->pageManage((this->page - 1));
			}
		}
		else if (this->container->contBtnBack->currentFrame == 3)
		{
			this->container->contBtnBack->gotoAndStop(1);
		}
		if (parentName == "btnForward")
		{
			if (this->container->contBtnForward->currentFrame == 3)
			{
				this->container->contBtnForward->gotoAndStop(2);
				this->pageManage((this->page + 1));
			}
		}
		else if (this->container->contBtnForward->currentFrame == 3)
		{
			this->container->contBtnForward->gotoAndStop(1);
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
		if (!this->container->contAchieve1->isVisible())
		{
			this->container->contAchieve1->setVisible(true);
		}
		if (!this->container->contAchieve2->isVisible())
		{
			this->container->contAchieve2->setVisible(true);
		}
		if (!this->container->contAchieve3->isVisible())
		{
			this->container->contAchieve3->setVisible(true);
		}
		if (!this->container->contAchieve4->isVisible())
		{
			this->container->contAchieve4->setVisible(true);
		}
		if (!this->container->contAchieve5->isVisible())
		{
			this->container->contAchieve5->setVisible(true);
		}
		if (!this->container->contAchieve6->isVisible())
		{
			this->container->contAchieve6->setVisible(true);
		}
		if (!this->container->contAchieve7->isVisible())
		{
			this->container->contAchieve7->setVisible(true);
		}
		if (!this->container->contAchieve8->isVisible())
		{
			this->container->contAchieve8->setVisible(true);
		}
		if (!this->container->contAchieve9->isVisible())
		{
			this->container->contAchieve9->setVisible(true);
		}
		if (!this->container->contAchieve10->isVisible())
		{
			this->container->contAchieve10->setVisible(true);
		}
		if (this->container->contFire1->isVisible())
		{
			this->container->contFire1->setVisible(false);
		}
		if (this->container->contFire2->isVisible())
		{
			this->container->contFire2->setVisible(false);
		}
		if (this->container->contFire3->isVisible())
		{
			this->container->contFire3->setVisible(false);
		}
		if (this->container->contFire4->isVisible())
		{
			this->container->contFire4->setVisible(false);
		}
		if (this->container->contFire5->isVisible())
		{
			this->container->contFire5->setVisible(false);
		}
		if (!this->container->contFire1Case->mouseEnabled)
		{
			this->container->contFire1Case->setMouseEnabled(true);
		}
		if (!this->container->contFire2Case->mouseEnabled)
		{
			this->container->contFire2Case->setMouseEnabled(true);
		}
		if (!this->container->contFire3Case->mouseEnabled)
		{
			this->container->contFire3Case->setMouseEnabled(true);
		}
		if (!this->container->contFire4Case->mouseEnabled)
		{
			this->container->contFire4Case->setMouseEnabled(true);
		}
		if (!this->container->contFire5Case->mouseEnabled)
		{
			this->container->contFire5Case->setMouseEnabled(true);
		}
		if (param1 == 1)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("achieve_firstKill"))
			{
				this->container->contAchieve1->gotoAndStop(1);
			}
			else
			{
				this->container->contAchieve1->gotoAndStop(2);
			}
			this->container->contAchieve1->icon->gotoAndStop(1);
			std::setText(this->container->contAchieve1->nameTXT, I18N_VALUE(I18N_CODE::U025));
			std::setText(this->container->contAchieve1->noteTXT, I18N_VALUE(I18N_CODE::U072));
			if (Main::mainClass->saveBoxClass->getBoolValue("achieve_kill_100_enemies"))
			{
				this->container->contAchieve2->gotoAndStop(1);
			}
			else
			{
				this->container->contAchieve2->gotoAndStop(2);
			}
			this->container->contAchieve2->icon->gotoAndStop(2);
				std::setText(this->container->contAchieve2->nameTXT, I18N_VALUE(I18N_CODE::U026));
				std::setText(this->container->contAchieve2->noteTXT, I18N_VALUE(I18N_CODE::U073));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_kill_2500_enemies"))
				{
					this->container->contAchieve3->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve3->gotoAndStop(2);
				}
			this->container->contAchieve3->icon->gotoAndStop(3);
				std::setText(this->container->contAchieve3->nameTXT, I18N_VALUE(I18N_CODE::U027));
				std::setText(this->container->contAchieve3->noteTXT, I18N_VALUE(I18N_CODE::U074));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_call_100_earlyWaves"))
				{
					this->container->contAchieve4->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve4->gotoAndStop(2);
				}
			this->container->contAchieve4->icon->gotoAndStop(4);
				std::setText(this->container->contAchieve4->nameTXT, I18N_VALUE(I18N_CODE::U028));
				std::setText(this->container->contAchieve4->noteTXT, I18N_VALUE(I18N_CODE::U075));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_build_100_towers"))
				{
					this->container->contAchieve5->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve5->gotoAndStop(2);
				}
			this->container->contAchieve5->icon->gotoAndStop(5);
				std::setText(this->container->contAchieve5->nameTXT, I18N_VALUE(I18N_CODE::U029));
				std::setText(this->container->contAchieve5->noteTXT, I18N_VALUE(I18N_CODE::U076));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_createGolem_5_times"))
				{
					this->container->contAchieve6->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve6->gotoAndStop(2);
				}
			this->container->contAchieve6->icon->gotoAndStop(6);
				std::setText(this->container->contAchieve6->nameTXT, I18N_VALUE(I18N_CODE::U030));
				std::setText(this->container->contAchieve6->noteTXT, I18N_VALUE(I18N_CODE::U077));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_createIceman_15_times"))
				{
					this->container->contAchieve7->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve7->gotoAndStop(2);
				}
			this->container->contAchieve7->icon->gotoAndStop(7);
				std::setText(this->container->contAchieve7->nameTXT, I18N_VALUE(I18N_CODE::U031));
				std::setText(this->container->contAchieve7->noteTXT, I18N_VALUE(I18N_CODE::U078));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_createAir_7_times"))
				{
					this->container->contAchieve8->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve8->gotoAndStop(2);
				}
			this->container->contAchieve8->icon->gotoAndStop(8);
				std::setText(this->container->contAchieve8->nameTXT, I18N_VALUE(I18N_CODE::U032));
				std::setText(this->container->contAchieve8->noteTXT, I18N_VALUE(I18N_CODE::U079));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_callAllWavesInLevel"))
				{
					this->container->contAchieve9->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve9->gotoAndStop(2);
				}
			this->container->contAchieve9->icon->gotoAndStop(9);
				std::setText(this->container->contAchieve9->nameTXT, I18N_VALUE(I18N_CODE::U033));
				std::setText(this->container->contAchieve9->noteTXT, I18N_VALUE(I18N_CODE::U080));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellFireIceStoneLevin"))
				{
					this->container->contAchieve10->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve10->gotoAndStop(2);
				}
			this->container->contAchieve10->icon->gotoAndStop(10);
				std::setText(this->container->contAchieve10->nameTXT, I18N_VALUE(I18N_CODE::U034));
				std::setText(this->container->contAchieve10->noteTXT, I18N_VALUE(I18N_CODE::U081));
				this->container->contFire1->setVisible(true);
			this->container->contFire1Case->setMouseEnabled(false);
		}
		else if (param1 == 2)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellFire_10_times"))
			{
				this->container->contAchieve1->gotoAndStop(1);
			}
			else
			{
				this->container->contAchieve1->gotoAndStop(2);
			}
			this->container->contAchieve1->icon->gotoAndStop(11);
				std::setText(this->container->contAchieve1->nameTXT, I18N_VALUE(I18N_CODE::U035));
				std::setText(this->container->contAchieve1->noteTXT, I18N_VALUE(I18N_CODE::U082));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellIce_10_times"))
				{
					this->container->contAchieve2->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve2->gotoAndStop(2);
				}
			this->container->contAchieve2->icon->gotoAndStop(12);
				std::setText(this->container->contAchieve2->nameTXT, I18N_VALUE(I18N_CODE::U036));
				std::setText(this->container->contAchieve2->noteTXT, I18N_VALUE(I18N_CODE::U083));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellStone_10_times"))
				{
					this->container->contAchieve3->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve3->gotoAndStop(2);
				}
			this->container->contAchieve3->icon->gotoAndStop(13);
				std::setText(this->container->contAchieve3->nameTXT, I18N_VALUE(I18N_CODE::U037));
				std::setText(this->container->contAchieve3->noteTXT, I18N_VALUE(I18N_CODE::U084));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_sellLevin_10_times"))
				{
					this->container->contAchieve4->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve4->gotoAndStop(2);
				}
			this->container->contAchieve4->icon->gotoAndStop(14);
				std::setText(this->container->contAchieve4->nameTXT, I18N_VALUE(I18N_CODE::U038));
				std::setText(this->container->contAchieve4->noteTXT, I18N_VALUE(I18N_CODE::U085));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_golemKill_250_enemies"))
				{
					this->container->contAchieve5->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve5->gotoAndStop(2);
				}
			this->container->contAchieve5->icon->gotoAndStop(15);
				std::setText(this->container->contAchieve5->nameTXT, I18N_VALUE(I18N_CODE::U039));
				std::setText(this->container->contAchieve5->noteTXT, I18N_VALUE(I18N_CODE::U086));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_icemanSlowdown_75_enemies"))
				{
					this->container->contAchieve6->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve6->gotoAndStop(2);
				}
			this->container->contAchieve6->icon->gotoAndStop(16);
				std::setText(this->container->contAchieve6->nameTXT, I18N_VALUE(I18N_CODE::U040));
				std::setText(this->container->contAchieve6->noteTXT, I18N_VALUE(I18N_CODE::U087));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_icemanSlowdown_500_enemies"))
				{
					this->container->contAchieve7->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve7->gotoAndStop(2);
				}
			this->container->contAchieve7->icon->gotoAndStop(17);
				std::setText(this->container->contAchieve7->nameTXT, I18N_VALUE(I18N_CODE::U041));
				std::setText(this->container->contAchieve7->noteTXT, I18N_VALUE(I18N_CODE::U088));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_buildUltraTower"))
				{
					this->container->contAchieve8->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve8->gotoAndStop(2);
				}
			this->container->contAchieve8->icon->gotoAndStop(18);
				std::setText(this->container->contAchieve8->nameTXT, I18N_VALUE(I18N_CODE::U042));
				std::setText(this->container->contAchieve8->noteTXT, I18N_VALUE(I18N_CODE::U089));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_buildUltraTower_50_times"))
				{
					this->container->contAchieve9->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve9->gotoAndStop(2);
				}
			this->container->contAchieve9->icon->gotoAndStop(19);
				std::setText(this->container->contAchieve9->nameTXT, I18N_VALUE(I18N_CODE::U043));
				std::setText(this->container->contAchieve9->noteTXT, I18N_VALUE(I18N_CODE::U090));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_buildAllUltraTowers"))
				{
					this->container->contAchieve10->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve10->gotoAndStop(2);
				}
			this->container->contAchieve10->icon->gotoAndStop(20);
				std::setText(this->container->contAchieve10->nameTXT, I18N_VALUE(I18N_CODE::U044));
				std::setText(this->container->contAchieve10->noteTXT, I18N_VALUE(I18N_CODE::U091));
				this->container->contFire2->setVisible(true);
			this->container->contFire2Case->setMouseEnabled(false);
		}
		else if (param1 == 3)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("achieve_notCast"))
			{
				this->container->contAchieve1->gotoAndStop(1);
			}
			else
			{
				this->container->contAchieve1->gotoAndStop(2);
			}
			this->container->contAchieve1->icon->gotoAndStop(21);
				std::setText(this->container->contAchieve1->nameTXT, I18N_VALUE(I18N_CODE::U045));
				std::setText(this->container->contAchieve1->noteTXT, I18N_VALUE(I18N_CODE::U092));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castFire_150_times"))
				{
					this->container->contAchieve2->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve2->gotoAndStop(2);
				}
			this->container->contAchieve2->icon->gotoAndStop(22);
				std::setText(this->container->contAchieve2->nameTXT, I18N_VALUE(I18N_CODE::U046));
				std::setText(this->container->contAchieve2->noteTXT, I18N_VALUE(I18N_CODE::U093));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castIce_150_times"))
				{
					this->container->contAchieve3->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve3->gotoAndStop(2);
				}
			this->container->contAchieve3->icon->gotoAndStop(23);
				std::setText(this->container->contAchieve3->nameTXT, I18N_VALUE(I18N_CODE::U047));
				std::setText(this->container->contAchieve3->noteTXT, I18N_VALUE(I18N_CODE::U094));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castStone_150_times"))
				{
					this->container->contAchieve4->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve4->gotoAndStop(2);
				}
			this->container->contAchieve4->icon->gotoAndStop(24);
				std::setText(this->container->contAchieve4->nameTXT, I18N_VALUE(I18N_CODE::U048));
				std::setText(this->container->contAchieve4->noteTXT, I18N_VALUE(I18N_CODE::U095));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castLevin_150_times"))
				{
					this->container->contAchieve5->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve5->gotoAndStop(2);
				}
			this->container->contAchieve5->icon->gotoAndStop(25);
				std::setText(this->container->contAchieve5->nameTXT, I18N_VALUE(I18N_CODE::U049));
				std::setText(this->container->contAchieve5->noteTXT, I18N_VALUE(I18N_CODE::U096));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castGetAll_10_times"))
				{
					this->container->contAchieve6->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve6->gotoAndStop(2);
				}
			this->container->contAchieve6->icon->gotoAndStop(26);
				std::setText(this->container->contAchieve6->nameTXT, I18N_VALUE(I18N_CODE::U050));
				std::setText(this->container->contAchieve6->noteTXT, I18N_VALUE(I18N_CODE::U097));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castGetAll_100_times"))
				{
					this->container->contAchieve7->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve7->gotoAndStop(2);
				}
			this->container->contAchieve7->icon->gotoAndStop(27);
				std::setText(this->container->contAchieve7->nameTXT, I18N_VALUE(I18N_CODE::U051));
				std::setText(this->container->contAchieve7->noteTXT, I18N_VALUE(I18N_CODE::U098));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castKill_1_enemy"))
				{
					this->container->contAchieve8->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve8->gotoAndStop(2);
				}
			this->container->contAchieve8->icon->gotoAndStop(28);
				std::setText(this->container->contAchieve8->nameTXT, I18N_VALUE(I18N_CODE::U052));
				std::setText(this->container->contAchieve8->noteTXT, I18N_VALUE(I18N_CODE::U099));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_castKill_100_enemy"))
				{
					this->container->contAchieve9->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve9->gotoAndStop(2);
				}
			this->container->contAchieve9->icon->gotoAndStop(29);
				std::setText(this->container->contAchieve9->nameTXT, I18N_VALUE(I18N_CODE::U053));
				std::setText(this->container->contAchieve9->noteTXT, I18N_VALUE(I18N_CODE::U100));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_complete_10_hardLevels"))
				{
					this->container->contAchieve10->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve10->gotoAndStop(2);
				}
			this->container->contAchieve10->icon->gotoAndStop(30);
				std::setText(this->container->contAchieve10->nameTXT, I18N_VALUE(I18N_CODE::U054));
				std::setText(this->container->contAchieve10->noteTXT, I18N_VALUE(I18N_CODE::U101));
				this->container->contFire3->setVisible(true);
			this->container->contFire3Case->setMouseEnabled(false);
		}
		else if (param1 == 4)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("achieve_complete_10_survivalLevels"))
			{
				this->container->contAchieve1->gotoAndStop(1);
			}
			else
			{
				this->container->contAchieve1->gotoAndStop(2);
			}
			this->container->contAchieve1->icon->gotoAndStop(31);
				std::setText(this->container->contAchieve1->nameTXT, I18N_VALUE(I18N_CODE::U055));
				std::setText(this->container->contAchieve1->noteTXT, I18N_VALUE(I18N_CODE::U102));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_complete_10_withAllLives"))
				{
					this->container->contAchieve2->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve2->gotoAndStop(2);
				}
			this->container->contAchieve2->icon->gotoAndStop(32);
				std::setText(this->container->contAchieve2->nameTXT, I18N_VALUE(I18N_CODE::U056));
				std::setText(this->container->contAchieve2->noteTXT, I18N_VALUE(I18N_CODE::U103));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_01"))
				{
					this->container->contAchieve3->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve3->gotoAndStop(2);
				}
			this->container->contAchieve3->icon->gotoAndStop(33);
				std::setText(this->container->contAchieve3->nameTXT, I18N_VALUE(I18N_CODE::U057));
				std::setText(this->container->contAchieve3->noteTXT, I18N_VALUE(I18N_CODE::U104));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_02"))
				{
					this->container->contAchieve4->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve4->gotoAndStop(2);
				}
			this->container->contAchieve4->icon->gotoAndStop(34);
				std::setText(this->container->contAchieve4->nameTXT, I18N_VALUE(I18N_CODE::U058));
				std::setText(this->container->contAchieve4->noteTXT, I18N_VALUE(I18N_CODE::U105));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_03"))
				{
					this->container->contAchieve5->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve5->gotoAndStop(2);
				}
			this->container->contAchieve5->icon->gotoAndStop(35);
				std::setText(this->container->contAchieve5->nameTXT, I18N_VALUE(I18N_CODE::U059));
				std::setText(this->container->contAchieve5->noteTXT, I18N_VALUE(I18N_CODE::U106));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_04"))
				{
					this->container->contAchieve6->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve6->gotoAndStop(2);
				}
			this->container->contAchieve6->icon->gotoAndStop(36);
				std::setText(this->container->contAchieve6->nameTXT, I18N_VALUE(I18N_CODE::U060));
				std::setText(this->container->contAchieve6->noteTXT, I18N_VALUE(I18N_CODE::U107));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_05"))
				{
					this->container->contAchieve7->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve7->gotoAndStop(2);
				}
			this->container->contAchieve7->icon->gotoAndStop(37);
				std::setText(this->container->contAchieve7->nameTXT, I18N_VALUE(I18N_CODE::U061));
				std::setText(this->container->contAchieve7->noteTXT, I18N_VALUE(I18N_CODE::U108));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_06"))
				{
					this->container->contAchieve8->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve8->gotoAndStop(2);
				}
			this->container->contAchieve8->icon->gotoAndStop(38);
				std::setText(this->container->contAchieve8->nameTXT, I18N_VALUE(I18N_CODE::U062));
				std::setText(this->container->contAchieve8->noteTXT, I18N_VALUE(I18N_CODE::U109));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_07"))
				{
					this->container->contAchieve9->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve9->gotoAndStop(2);
				}
			this->container->contAchieve9->icon->gotoAndStop(39);
				std::setText(this->container->contAchieve9->nameTXT, I18N_VALUE(I18N_CODE::U063));
				std::setText(this->container->contAchieve9->noteTXT, I18N_VALUE(I18N_CODE::U110));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_08"))
				{
					this->container->contAchieve10->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve10->gotoAndStop(2);
				}
			this->container->contAchieve10->icon->gotoAndStop(40);
				std::setText(this->container->contAchieve10->nameTXT, I18N_VALUE(I18N_CODE::U064));
				std::setText(this->container->contAchieve10->noteTXT, I18N_VALUE(I18N_CODE::U111));
				this->container->contFire4->setVisible(true);
			this->container->contFire4Case->setMouseEnabled(false);
		}
		else if (param1 == 5)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_09"))
			{
				this->container->contAchieve1->gotoAndStop(1);
			}
			else
			{
				this->container->contAchieve1->gotoAndStop(2);
			}
			this->container->contAchieve1->icon->gotoAndStop(41);
				std::setText(this->container->contAchieve1->nameTXT, I18N_VALUE(I18N_CODE::U065));
				std::setText(this->container->contAchieve1->noteTXT, I18N_VALUE(I18N_CODE::U112));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_10"))
				{
					this->container->contAchieve2->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve2->gotoAndStop(2);
				}
			this->container->contAchieve2->icon->gotoAndStop(42);
				std::setText(this->container->contAchieve2->nameTXT, I18N_VALUE(I18N_CODE::U066));
				std::setText(this->container->contAchieve2->noteTXT, I18N_VALUE(I18N_CODE::U113));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_11"))
				{
					this->container->contAchieve3->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve3->gotoAndStop(2);
				}
			this->container->contAchieve3->icon->gotoAndStop(43);
				std::setText(this->container->contAchieve3->nameTXT, I18N_VALUE(I18N_CODE::U067));
				std::setText(this->container->contAchieve3->noteTXT, I18N_VALUE(I18N_CODE::U114));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_12"))
				{
					this->container->contAchieve4->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve4->gotoAndStop(2);
				}
			this->container->contAchieve4->icon->gotoAndStop(44);
				std::setText(this->container->contAchieve4->nameTXT, I18N_VALUE(I18N_CODE::U068));
				std::setText(this->container->contAchieve4->noteTXT, I18N_VALUE(I18N_CODE::U115));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_13"))
				{
					this->container->contAchieve5->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve5->gotoAndStop(2);
				}
			this->container->contAchieve5->icon->gotoAndStop(45);
				std::setText(this->container->contAchieve5->nameTXT, I18N_VALUE(I18N_CODE::U069));
				std::setText(this->container->contAchieve5->noteTXT, I18N_VALUE(I18N_CODE::U116));
				if (Main::mainClass->saveBoxClass->getBoolValue("achieve_dude_14"))
				{
					this->container->contAchieve6->gotoAndStop(1);
				}
				else
				{
					this->container->contAchieve6->gotoAndStop(2);
				}
			this->container->contAchieve6->icon->gotoAndStop(46);
				std::setText(this->container->contAchieve6->nameTXT, I18N_VALUE(I18N_CODE::U070));
				std::setText(this->container->contAchieve6->noteTXT, I18N_VALUE(I18N_CODE::U117));
				this->container->contAchieve7->setVisible(false);
			this->container->contAchieve8->setVisible(false);
			this->container->contAchieve9->setVisible(false);
			this->container->contAchieve10->setVisible(false);
			this->container->contFire5->setVisible(true);
			this->container->contFire5Case->setMouseEnabled(false);
		}
		return;
	}// end function

	void Achievements::autoguidersButtons()
	{
		this->autoguidesMouse_pt = CONVERT_TO_WORLD_POS(cocos2d::Point(Main::mouseX, Main::mouseY));
		this->autoguidesObject = NULL;
		//this->autoguidesObject_pt = CONVERT_TO_WORLD_POS(this->container->contBtnClose->localToGlobal(this->container->contBtnCloseCloseCase->getPosition()));
		//this->autoguidesObjectWidth = this->container->contBtnCloseCloseCase.width / 2;
		//this->autoguidesObjectHeight = this->container->contBtnCloseCloseCase.height / 2;
		//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
		//	&& this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
		//	&& this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
		//	&& this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
		//{
		//	this->autoguidesObject = this->container->contBtnCloseCloseCase;
		//}
		//if (this->autoguidesObject)
		//{
		//	this->tempObject = new Object();
		//	this->tempObject.target = this->autoguidesObject;
		//	this->mouseMoveHandler(this->tempObject);
		//}
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
