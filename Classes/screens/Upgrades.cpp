#include "MainClass.h"
#include "LevelsMenu.h"
#include "Upgrades.h"   
namespace screens
{
	UpgradeButton::UpgradeButton(MC *mc, const std::string &  slot, const string &  defAniName) :MovieClipSub(mc, slot, defAniName)
	{
		this->upgradeCase = this->createCase("upgradeCase");
		this->starsTXT = this->createText("starsTXT",true);
		this->starsTXT->setPosition(this->starsTXT->getPosition()+Vec2(0,10));
	};

	Upgrades_mc::Upgrades_mc() :MovieClip("screen/", "Upgrades_mc", "Upgrades_mc")
	{
		this->cont = this->createMovieClipSub("cont");
		this->shadow = this->createCase("shadow");
		this->stars=new MovieClip("screen/", "star", "star");
		this->starsTXT = this->stars->createText("starsTXT");
		std::setText(this->starsTXT, "TEST");
		std::drawRange(this->starsTXT, Color4F::RED);
		this->contBtnReset = this->cont->createMovieClipSub("btnReset");
		this->contBtnResetResetCase = this->contBtnReset->createCase("resetCase");
		this->contBtnAccept = this->cont->createMovieClipSub("btnAccept");
		this->contBtnAcceptAcceptCase = this->contBtnAccept->createCase("acceptCase");
		this->levinUpgrade1 = this->cont->createMovieClipSub<UpgradeButton>("levinUpgrade1");
		this->levinUpgrade2 = this->cont->createMovieClipSub<UpgradeButton>("levinUpgrade2");
		this->levinUpgrade3 = this->cont->createMovieClipSub<UpgradeButton>("levinUpgrade3");
		this->levinUpgrade4 = this->cont->createMovieClipSub<UpgradeButton>("levinUpgrade4");
		this->levinUpgrade5 = this->cont->createMovieClipSub<UpgradeButton>("levinUpgrade5");
		this->stoneUpgrade1 = this->cont->createMovieClipSub<UpgradeButton>("stoneUpgrade1");
		this->stoneUpgrade2 = this->cont->createMovieClipSub<UpgradeButton>("stoneUpgrade2");
		this->stoneUpgrade3 = this->cont->createMovieClipSub<UpgradeButton>("stoneUpgrade3");
		this->stoneUpgrade4 = this->cont->createMovieClipSub<UpgradeButton>("stoneUpgrade4");
		this->stoneUpgrade5 = this->cont->createMovieClipSub<UpgradeButton>("stoneUpgrade5");
		this->iceUpgrade1 = this->cont->createMovieClipSub<UpgradeButton>("iceUpgrade1");
		this->iceUpgrade2 = this->cont->createMovieClipSub<UpgradeButton>("iceUpgrade2");
		this->iceUpgrade3 = this->cont->createMovieClipSub<UpgradeButton>("iceUpgrade3");
		this->iceUpgrade4 = this->cont->createMovieClipSub<UpgradeButton>("iceUpgrade4");
		this->iceUpgrade5 = this->cont->createMovieClipSub<UpgradeButton>("iceUpgrade5");
		this->fireUpgrade1 = this->cont->createMovieClipSub<UpgradeButton>("fireUpgrade1");
		this->fireUpgrade2 = this->cont->createMovieClipSub<UpgradeButton>("fireUpgrade2");
		this->fireUpgrade3 = this->cont->createMovieClipSub<UpgradeButton>("fireUpgrade3");
		this->fireUpgrade4 = this->cont->createMovieClipSub<UpgradeButton>("fireUpgrade4");
		this->fireUpgrade5 = this->cont->createMovieClipSub<UpgradeButton>("fireUpgrade5");
		this->airUpgrade1 = this->cont->createMovieClipSub<UpgradeButton>("airUpgrade1");
		this->airUpgrade2 = this->cont->createMovieClipSub<UpgradeButton>("airUpgrade2");
		this->airUpgrade3 = this->cont->createMovieClipSub<UpgradeButton>("airUpgrade3");
		this->airUpgrade4 = this->cont->createMovieClipSub<UpgradeButton>("airUpgrade4");
		this->airUpgrade5 = this->cont->createMovieClipSub<UpgradeButton>("airUpgrade5");
		this->icemanUpgrade1 = this->cont->createMovieClipSub<UpgradeButton>("icemanUpgrade1");
		this->icemanUpgrade2 = this->cont->createMovieClipSub<UpgradeButton>("icemanUpgrade2");
		this->icemanUpgrade3 = this->cont->createMovieClipSub<UpgradeButton>("icemanUpgrade3");
		this->icemanUpgrade4 = this->cont->createMovieClipSub<UpgradeButton>("icemanUpgrade4");
		this->icemanUpgrade5 = this->cont->createMovieClipSub<UpgradeButton>("icemanUpgrade5");
		this->golemUpgrade1 = this->cont->createMovieClipSub<UpgradeButton>("golemUpgrade1");
		this->golemUpgrade2 = this->cont->createMovieClipSub<UpgradeButton>("golemUpgrade2");
		this->golemUpgrade3 = this->cont->createMovieClipSub<UpgradeButton>("golemUpgrade3");
		this->golemUpgrade4 = this->cont->createMovieClipSub<UpgradeButton>("golemUpgrade4");
		this->golemUpgrade5 = this->cont->createMovieClipSub<UpgradeButton>("golemUpgrade5");
		this->levinArrow1 = this->cont->getSprite("levinArrow1");
		this->levinArrow2 = this->cont->getSprite("levinArrow2");
		this->levinArrow3 = this->cont->getSprite("levinArrow3");
		this->levinArrow4 = this->cont->getSprite("levinArrow4");
		this->stoneArrow1 = this->cont->getSprite("stoneArrow1");
		this->stoneArrow2 = this->cont->getSprite("stoneArrow2");
		this->stoneArrow3 = this->cont->getSprite("stoneArrow3");
		this->stoneArrow4 = this->cont->getSprite("stoneArrow4");
		this->iceArrow1 = this->cont->getSprite("iceArrow1");
		this->iceArrow2 = this->cont->getSprite("iceArrow2");
		this->iceArrow3 = this->cont->getSprite("iceArrow3");
		this->iceArrow4 = this->cont->getSprite("iceArrow4");
		this->fireArrow1 = this->cont->getSprite("fireArrow1");
		this->fireArrow2 = this->cont->getSprite("fireArrow2");
		this->fireArrow3 = this->cont->getSprite("fireArrow3");
		this->fireArrow4 = this->cont->getSprite("fireArrow4");
		this->airArrow1 = this->cont->getSprite("airArrow1");
		this->airArrow2 = this->cont->getSprite("airArrow2");
		this->airArrow3 = this->cont->getSprite("airArrow3");
		this->airArrow4 = this->cont->getSprite("airArrow4");
		this->icemanArrow1 = this->cont->getSprite("icemanArrow1");
		this->icemanArrow2 = this->cont->getSprite("icemanArrow2");
		this->icemanArrow3 = this->cont->getSprite("icemanArrow3");
		this->icemanArrow4 = this->cont->getSprite("icemanArrow4");
		this->golemArrow1 = this->cont->getSprite("golemArrow1");
		this->golemArrow2 = this->cont->getSprite("golemArrow2");
		this->golemArrow3 = this->cont->getSprite("golemArrow3");
		this->golemArrow4 = this->cont->getSprite("golemArrow4");

		return;
	};// end function
	HintUpgrade_mc::HintUpgrade_mc() :MovieClip("screen/", "HintUpgrade_mc", "HintUpgrade_mc")
	{
		myTarget = NULL;
	};

	Upgrades::Upgrades() : costGolemUpgrade1(2), costGolemUpgrade2(2), costGolemUpgrade3(2)
		, costGolemUpgrade4(3), costGolemUpgrade5(4), costIcemanUpgrade1(1), costIcemanUpgrade2(2), costIcemanUpgrade3(2), costIcemanUpgrade4(3),
		costIcemanUpgrade5(4), costAirUpgrade1(1), costAirUpgrade2(2), costAirUpgrade3(2), costAirUpgrade4(3), costAirUpgrade5(4), costFireUpgrade1(1),
		costFireUpgrade2(1), costFireUpgrade3(1), costFireUpgrade4(1), costFireUpgrade5(2), costIceUpgrade1(1), costIceUpgrade2(1), costIceUpgrade3(1),
		costIceUpgrade4(1), costIceUpgrade5(2), costStoneUpgrade1(1), costStoneUpgrade2(1), costStoneUpgrade3(1), costStoneUpgrade4(1), costStoneUpgrade5(2),
		costLevinUpgrade1(1), costLevinUpgrade2(1), costLevinUpgrade3(2), costLevinUpgrade4(2), costLevinUpgrade5(2), container(NULL), levelsMenu(NULL), nowUpgradeButton(NULL), hint(NULL)
	{
		//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
 		init();
		return;
	}// end function

	bool Upgrades::init()
	{
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
		//this->stage.frameRate = 60;
		this->levelsMenu = Main::mainClass->levelsMenuClass;
		this->levelsMenu->manageListeners("off");
		this->container = new Upgrades_mc(); 
		this->addChild(this->container);
		this->container->setPosition(0, 800);
		this->container->back = new Back_mc();
		//this->container->setScaleY(0.8);
		this->container->back->setPosition(26, Main::SCREEN_HEIGHT - 15);
		this->addChild(this->container->back);
		this->addChild(this->container->stars);
		this->printNodePos(this->container->stars);
		this->container->stars->setPosition(0, Main::SCREEN_HEIGHT - 10);
		this->container->stop();
		this->container->back->stop();
		this->container->back->backCase->stop();
		this->container->back->backCase->setMouseEnabled(true);
		this->container->cont->stop();
		this->container->contBtnReset->stop();
		this->container->contBtnAccept->stop(); 
		this->container->contBtnResetResetCase->setMouseEnabled(true);
		this->container->contBtnAcceptAcceptCase->setMouseEnabled(true);
		this->container->golemArrow1->setVisible(false);
		this->container->golemArrow2->setVisible(false);
		this->container->golemArrow3->setVisible(false);
		this->container->golemArrow4->setVisible(false);
		this->container->icemanArrow1->setVisible(false);
		this->container->icemanArrow2->setVisible(false);
		this->container->icemanArrow3->setVisible(false);
		this->container->icemanArrow4->setVisible(false);
		this->container->airArrow1->setVisible(false);
		this->container->airArrow2->setVisible(false);
		this->container->airArrow3->setVisible(false);
		this->container->airArrow4->setVisible(false);
		this->container->fireArrow1->setVisible(false);
		this->container->fireArrow2->setVisible(false);
		this->container->fireArrow3->setVisible(false);
		this->container->fireArrow4->setVisible(false);
		this->container->iceArrow1->setVisible(false);
		this->container->iceArrow2->setVisible(false);
		this->container->iceArrow3->setVisible(false);
		this->container->iceArrow4->setVisible(false);
		this->container->stoneArrow1->setVisible(false);
		this->container->stoneArrow2->setVisible(false);
		this->container->stoneArrow3->setVisible(false);
		this->container->stoneArrow4->setVisible(false);
		this->container->levinArrow1->setVisible(false);
		this->container->levinArrow2->setVisible(false);
		this->container->levinArrow3->setVisible(false);
		this->container->levinArrow4->setVisible(false);
		this->hint = new HintUpgrade_mc();
		this->hint->stop();
		this->hint->myTarget = NULL;
		this->hint->setMouseChildren(false);
		this->hint->setMouseEnabled(false);
		this->hint->setVisible(false);
		this->addChild(this->hint);
		//this->upgradeUpdate();
		this->container->cont->setMouseChildren(false);
		this->container->cont->setMouseEnabled(false);
		AudioUtil::playSound("Snd_menu_openBoard.mp3");
		this->manageListeners("on");
		//this->container->play(1);
		return true;
	}// end function

	void Upgrades::enterFrameHandler(float dt)
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
				if (this->openFlag && dt > 0)this->enableFrameHandler(0);
			}
			else
			{
				this->openFlag = false;
				this->container->cont->setMouseChildren(true);
				this->container->cont->setMouseEnabled(true);
				this->upgradeUpdate();
				//this->stage.frameRate = 30;
			}
		}
		else if (this->closeFlag)
		{
			if (this->container->currentFrame > 1)
			{
				this->container->gotoAndStop((this->container->currentFrame - 1));
				if (this->closeFlag && dt > 0)this->enableFrameHandler(0);
			}
			else
			{
				this->closeFlag = false;
				this->kill();
			}
		}
		if (this->listOfUpgradeAnima.size() > 0)
		{
			this->i = this->listOfUpgradeAnima.size() - 1;
			while (this->i >= 0)
			{
				if (this->listOfUpgradeAnima[this->i]->currentFrame < this->listOfUpgradeAnima[this->i]->totalFrames)
				{
					this->listOfUpgradeAnima[this->i]->gotoAndStop((this->listOfUpgradeAnima[this->i]->currentFrame + 1));
				}
				else
				{
					this->removeChild(this->listOfUpgradeAnima[this->i]);
					this->listOfUpgradeAnima.splice(this->i, 1);
				}
				i--;
			}
		}
		if (this->hint->isVisible())
		{
			this->hint->setPosition(Main::mouseX, Main::mouseY);
		}
		this->hint->setLocalZOrder(999);
		return;
	}// end function
	bool Upgrades::preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType)
	{
		removeEventTarget(event, this);
		Vec2 pos = event->getLocationInView();
		switch (_mouseEventType)
		{
		case cocos2d::EventMouse::MouseEventType::MOUSE_NONE:
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_DOWN:
			if (event->currentTargets.size() > 1) {
				removeEventTarget(event, "shadow");
				//removeEventTarget(event, "sphereCase", "fireCase");
			}
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_UP:
			if (event->currentTargets.size() > 1) {
				removeEventTarget(event, "shadow");
			}
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_MOVE:
			removeEventTarget(event, "shadow");
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_SCROLL:
			break;
		default:
			break;
		}
		event->reset();
		return false;
	};
	void Upgrades::mouseMoveHandler(cocos2d::EventMouse * e)
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
			EventNode::beginTouchNode = event->target;// event->currentTargets.at(0);

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
			if (targetName == "resetCase")
			{
				if (this->container->contBtnReset->currentFrame == 1)
				{
					this->container->contBtnReset->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->contBtnReset->currentFrame == 2)
			{
				this->container->contBtnReset->gotoAndStop(1);
			}
			if (targetName == "acceptCase")
			{
				if (this->container->contBtnAccept->currentFrame == 1)
				{
					this->container->contBtnAccept->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->contBtnAccept->currentFrame == 2)
			{
				this->container->contBtnAccept->gotoAndStop(1);
			}
			if (targetName == "upgradeCase")
			{
				string slotName = event->target->getParent()->getParent()->getName();
				UpgradeButton *curButton = (UpgradeButton*)this->container->getMemSubMC(slotName);
				if (this->nowUpgradeButton)
				{
					if (this->nowUpgradeButton != curButton)
					{
						if (this->nowUpgradeButton->currentFrame == 2)
						{
							string startsTxt = this->nowUpgradeButton->starsTXT->getString();
							this->nowUpgradeButton->gotoAndStop(1);
							std::setText(this->nowUpgradeButton->starsTXT, startsTxt);
							// �Ӵ� ��ɫ
							//this->nowUpgradeButton->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
						}
					}
				}
				this->nowUpgradeButton = curButton;
				if (this->nowUpgradeButton->currentFrame == 1)
				{
					string startsTxt = this->nowUpgradeButton->starsTXT->getString();
					this->nowUpgradeButton->gotoAndStop(2);
					std::setText(this->nowUpgradeButton->starsTXT, startsTxt);
					//this->nowUpgradeButton->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
				if (!this->hint->isVisible() || this->hint->myTarget != this->nowUpgradeButton)
				{
					this->hint->setVisible(true);
					this->hint->myTarget = this->nowUpgradeButton;
					if (this->hint->myTarget->getName() == "golemUpgrade1")
					{
						this->hint->gotoAndStop(1);
					}
					else if (this->hint->myTarget->getName() == "golemUpgrade2")
					{
						this->hint->gotoAndStop(2);
					}
					else if (this->hint->myTarget->getName() == "golemUpgrade3")
					{
						this->hint->gotoAndStop(3);
					}
					else if (this->hint->myTarget->getName() == "golemUpgrade4")
					{
						this->hint->gotoAndStop(4);
					}
					else if (this->hint->myTarget->getName() == "golemUpgrade5")
					{
						this->hint->gotoAndStop(5);
					}
					else if (this->hint->myTarget->getName() == "icemanUpgrade1")
					{
						this->hint->gotoAndStop(6);
					}
					else if (this->hint->myTarget->getName() == "icemanUpgrade2")
					{
						this->hint->gotoAndStop(7);
					}
					else if (this->hint->myTarget->getName() == "icemanUpgrade3")
					{
						this->hint->gotoAndStop(8);
					}
					else if (this->hint->myTarget->getName() == "icemanUpgrade4")
					{
						this->hint->gotoAndStop(9);
					}
					else if (this->hint->myTarget->getName() == "icemanUpgrade5")
					{
						this->hint->gotoAndStop(10);
					}
					else if (this->hint->myTarget->getName() == "airUpgrade1")
					{
						this->hint->gotoAndStop(11);
					}
					else if (this->hint->myTarget->getName() == "airUpgrade2")
					{
						this->hint->gotoAndStop(12);
					}
					else if (this->hint->myTarget->getName() == "airUpgrade3")
					{
						this->hint->gotoAndStop(13);
					}
					else if (this->hint->myTarget->getName() == "airUpgrade4")
					{
						this->hint->gotoAndStop(14);
					}
					else if (this->hint->myTarget->getName() == "airUpgrade5")
					{
						this->hint->gotoAndStop(15);
					}
					else if (this->hint->myTarget->getName() == "fireUpgrade1")
					{
						this->hint->gotoAndStop(16);
					}
					else if (this->hint->myTarget->getName() == "fireUpgrade2")
					{
						this->hint->gotoAndStop(17);
					}
					else if (this->hint->myTarget->getName() == "fireUpgrade3")
					{
						this->hint->gotoAndStop(18);
					}
					else if (this->hint->myTarget->getName() == "fireUpgrade4")
					{
						this->hint->gotoAndStop(19);
					}
					else if (this->hint->myTarget->getName() == "fireUpgrade5")
					{
						this->hint->gotoAndStop(20);
					}
					else if (this->hint->myTarget->getName() == "iceUpgrade1")
					{
						this->hint->gotoAndStop(21);
					}
					else if (this->hint->myTarget->getName() == "iceUpgrade2")
					{
						this->hint->gotoAndStop(22);
					}
					else if (this->hint->myTarget->getName() == "iceUpgrade3")
					{
						this->hint->gotoAndStop(23);
					}
					else if (this->hint->myTarget->getName() == "iceUpgrade4")
					{
						this->hint->gotoAndStop(24);
					}
					else if (this->hint->myTarget->getName() == "iceUpgrade5")
					{
						this->hint->gotoAndStop(25);
					}
					else if (this->hint->myTarget->getName() == "stoneUpgrade1")
					{
						this->hint->gotoAndStop(26);
					}
					else if (this->hint->myTarget->getName() == "stoneUpgrade2")
					{
						this->hint->gotoAndStop(27);
					}
					else if (this->hint->myTarget->getName() == "stoneUpgrade3")
					{
						this->hint->gotoAndStop(28);
					}
					else if (this->hint->myTarget->getName() == "stoneUpgrade4")
					{
						this->hint->gotoAndStop(29);
					}
					else if (this->hint->myTarget->getName() == "stoneUpgrade5")
					{
						this->hint->gotoAndStop(30);
					}
					else if (this->hint->myTarget->getName() == "levinUpgrade1")
					{
						this->hint->gotoAndStop(31);
					}
					else if (this->hint->myTarget->getName() == "levinUpgrade2")
					{
						this->hint->gotoAndStop(32);
					}
					else if (this->hint->myTarget->getName() == "levinUpgrade3")
					{
						this->hint->gotoAndStop(33);
					}
					else if (this->hint->myTarget->getName() == "levinUpgrade4")
					{
						this->hint->gotoAndStop(34);
					}
					else if (this->hint->myTarget->getName() == "levinUpgrade5")
					{
						this->hint->gotoAndStop(35);
					}
					this->hint->setPosition(Main::mouseX, Main::mouseY);
				}
			}
			else if (this->nowUpgradeButton)
			{
				if (this->nowUpgradeButton->currentFrame == 2)
				{
					string starsTxt = this->nowUpgradeButton->starsTXT->getString();
					this->nowUpgradeButton->gotoAndStop(1);
					std::setText(this->nowUpgradeButton->starsTXT, starsTxt);
					//this->nowUpgradeButton->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				}
				if (this->hint->isVisible())
				{
					this->hint->setVisible(false);
				}
			}
		}
	}// end function

	void Upgrades::mouseDownHandler(cocos2d::EventMouse * e)
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
			EventNode::beginTouchNode = event->target;// event->currentTargets.at(0);

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
				else if (targetName == "resetCase")
				{
					if (this->container->contBtnReset->currentFrame == 2)
					{
						this->container->contBtnReset->gotoAndStop(3);
						AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
					}
				}
				else if (targetName == "acceptCase")
				{
					if (this->container->contBtnAccept->currentFrame == 2)
					{
						this->container->contBtnAccept->gotoAndStop(3);
						AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
					}
				}
				else if (targetName == "shadow")
				{
					Sprite * bg = this->container->cont->getSprite("bg");
					if (!bg || !std::hitTest(bg, EventNode::beginTouchPos))
						this->close();
				}
				else if (targetName == "upgradeCase")
				{
					string slotName = event->target->getParent()->getParent()->getName();
					UpgradeButton *curButton = (UpgradeButton*)this->container->getMemSubMC(slotName);
					if (this->nowUpgradeButton)
					{
						if (this->nowUpgradeButton != curButton)
						{
							if (this->nowUpgradeButton->currentFrame == 2)
							{
								this->nowUpgradeButton->gotoAndStop(1);
							}
						}
						if (this->nowUpgradeButton->currentFrame == 2)
						{
							this->nowUpgradeButton->gotoAndStop(3);
							cocos2d::Point tempObject = this->container->cont->localToGlobal(this->nowUpgradeButton->getPosition());
							AnimUpgrade_mc * tempObject1 = new AnimUpgrade_mc();
							tempObject1->stop();
							tempObject1->setPosition(tempObject);
							tempObject1->setMouseChildren(false);
							tempObject1->setMouseEnabled(false);
							this->addChild(tempObject1);
							this->listOfUpgradeAnima.push(tempObject1);
							AudioUtil::playSound("Snd_menu_upgrIconMouseDown.mp3");
							int stars = Main::mainClass->saveBoxClass->getIntValue("stars");
							if (this->nowUpgradeButton->name == "golemUpgrade1")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeGolem1", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costGolemUpgrade1);
							}
							else if (this->nowUpgradeButton->name == "golemUpgrade2")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeGolem2", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costGolemUpgrade2);
							}
							else if (this->nowUpgradeButton->name == "golemUpgrade3")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeGolem3", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costGolemUpgrade3);
							}
							else if (this->nowUpgradeButton->name == "golemUpgrade4")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeGolem4", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costGolemUpgrade4);
							}
							else if (this->nowUpgradeButton->name == "golemUpgrade5")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeGolem5", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costGolemUpgrade5);
							}
							if (this->nowUpgradeButton->name == "icemanUpgrade1")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIceman1", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIcemanUpgrade1);
							}
							else if (this->nowUpgradeButton->name == "icemanUpgrade2")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIceman2", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIcemanUpgrade2);
							}
							else if (this->nowUpgradeButton->name == "icemanUpgrade3")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIceman3", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIcemanUpgrade3);
							}
							else if (this->nowUpgradeButton->name == "icemanUpgrade4")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIceman4", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIcemanUpgrade4);
							}
							else if (this->nowUpgradeButton->name == "icemanUpgrade5")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIceman5", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIcemanUpgrade5);
							}
							if (this->nowUpgradeButton->name == "airUpgrade1")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeAir1", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costAirUpgrade1);
							}
							else if (this->nowUpgradeButton->name == "airUpgrade2")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeAir2", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costAirUpgrade2);
							}
							else if (this->nowUpgradeButton->name == "airUpgrade3")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeAir3", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costAirUpgrade3);
							}
							else if (this->nowUpgradeButton->name == "airUpgrade4")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeAir4", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costAirUpgrade4);
							}
							else if (this->nowUpgradeButton->name == "airUpgrade5")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeAir5", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costAirUpgrade5);
							}
							if (this->nowUpgradeButton->name == "fireUpgrade1")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeFire1", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costFireUpgrade1);
							}
							else if (this->nowUpgradeButton->name == "fireUpgrade2")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeFire2", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costFireUpgrade2);
							}
							else if (this->nowUpgradeButton->name == "fireUpgrade3")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeFire3", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costFireUpgrade3);
							}
							else if (this->nowUpgradeButton->name == "fireUpgrade4")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeFire4", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costFireUpgrade4);
							}
							else if (this->nowUpgradeButton->name == "fireUpgrade5")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeFire5", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costFireUpgrade5);
							}
							if (this->nowUpgradeButton->name == "iceUpgrade1")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIce1", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIceUpgrade1);
							}
							else if (this->nowUpgradeButton->name == "iceUpgrade2")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIce2", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIceUpgrade2);
							}
							else if (this->nowUpgradeButton->name == "iceUpgrade3")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIce3", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIceUpgrade3);
							}
							else if (this->nowUpgradeButton->name == "iceUpgrade4")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIce4", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIceUpgrade4);
							}
							else if (this->nowUpgradeButton->name == "iceUpgrade5")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeIce5", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costIceUpgrade5);
							}
							if (this->nowUpgradeButton->name == "stoneUpgrade1")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeStone1", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costStoneUpgrade1);
							}
							else if (this->nowUpgradeButton->name == "stoneUpgrade2")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeStone2", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costStoneUpgrade2);
							}
							else if (this->nowUpgradeButton->name == "stoneUpgrade3")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeStone3", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costStoneUpgrade3);
							}
							else if (this->nowUpgradeButton->name == "stoneUpgrade4")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeStone4", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costStoneUpgrade4);
							}
							else if (this->nowUpgradeButton->name == "stoneUpgrade5")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeStone5", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costStoneUpgrade5);
							}
							if (this->nowUpgradeButton->name == "levinUpgrade1")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeLevin1", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costLevinUpgrade1);
							}
							else if (this->nowUpgradeButton->name == "levinUpgrade2")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeLevin2", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costLevinUpgrade2);
							}
							else if (this->nowUpgradeButton->name == "levinUpgrade3")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeLevin3", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costLevinUpgrade3);
							}
							else if (this->nowUpgradeButton->name == "levinUpgrade4")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeLevin4", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costLevinUpgrade4);
							}
							else if (this->nowUpgradeButton->name == "levinUpgrade5")
							{
								Main::mainClass->saveBoxClass->setValue("upgradeLevin5", true);
								Main::mainClass->saveBoxClass->setValue("stars", stars - this->costLevinUpgrade5);
							}
							this->upgradeUpdate();
						}
					}
				}
			}
		}
	}// end function

	void Upgrades::mouseUpHandler(cocos2d::EventMouse * e)
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
			if (targetName == "resetCase")
			{
				if (this->container->contBtnReset->currentFrame == 3)
				{
					this->container->contBtnReset->gotoAndStop(2);
					AudioUtil::playSound("Snd_menu_upgrReset.mp3");
					int stars = Main::mainClass->saveBoxClass->getIntValue("stars");
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem1"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeGolem1", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costGolemUpgrade1);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem2"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeGolem2", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costGolemUpgrade2);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem3"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeGolem3", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costGolemUpgrade3);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem4"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeGolem4", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costGolemUpgrade4);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem5"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeGolem5", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costGolemUpgrade5);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman1"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIceman1", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIcemanUpgrade1);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman2"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIceman2", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIcemanUpgrade2);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman3"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIceman3", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIcemanUpgrade3);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman4"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIceman4", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIcemanUpgrade4);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman5"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIceman5", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIcemanUpgrade5);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir1"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeAir1", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costAirUpgrade1);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir2"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeAir2", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costAirUpgrade2);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir3"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeAir3", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costAirUpgrade3);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir4"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeAir4", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costAirUpgrade4);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir5"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeAir5", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costAirUpgrade5);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire1"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeFire1", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costFireUpgrade1);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire2"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeFire2", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costFireUpgrade2);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire3"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeFire3", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costFireUpgrade3);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire4"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeFire4", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costFireUpgrade4);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire5"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeFire5", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costFireUpgrade5);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce1"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIce1", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIceUpgrade1);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce2"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIce2", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIceUpgrade2);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce3"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIce3", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIceUpgrade3);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce4"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIce4", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIceUpgrade4);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce5"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeIce5", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costIceUpgrade5);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone1"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeStone1", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costStoneUpgrade1);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone2"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeStone2", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costStoneUpgrade2);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone3"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeStone3", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costStoneUpgrade3);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone4"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeStone4", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costStoneUpgrade4);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone5"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeStone5", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costStoneUpgrade5);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin1"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeLevin1", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costLevinUpgrade1);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin2"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeLevin2", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costLevinUpgrade2);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin3"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeLevin3", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costLevinUpgrade3);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin4"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeLevin4", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costLevinUpgrade4);
					}
					if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin5"))
					{
						Main::mainClass->saveBoxClass->setValue("upgradeLevin5", false);
						Main::mainClass->saveBoxClass->setValue("stars", stars + this->costLevinUpgrade5);
					}
					this->upgradeUpdate();
				}
			}
			else if (this->container->contBtnReset->currentFrame == 3)
			{
				this->container->contBtnReset->gotoAndStop(1);
			}
			if (targetName == "acceptCase")
			{
				if (this->container->contBtnAccept->currentFrame == 3)
				{
					this->container->contBtnAccept->gotoAndStop(2);
					this->close();
				}
			}
			else if (this->container->contBtnAccept->currentFrame == 3)
			{
				this->container->contBtnAccept->gotoAndStop(1);
			}
		}
	}// end function

	void Upgrades::upgradeUpdate()
	{
		if (Main::mainClass->saveBoxClass->getIntValue("openLevels",3) > 0)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem1"))
			{
				this->container->golemUpgrade1->gotoAndStop(3);
				this->container->golemUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade1)
			{
				this->container->golemUpgrade1->gotoAndStop(1);
				std::setText(this->container->golemUpgrade1->starsTXT, this->costGolemUpgrade1);
				//this->container->golemUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade1->upgradeCase->setMouseEnabled(true);
			}
			else
			{
				this->container->golemUpgrade1->gotoAndStop(4);
				std::setText(this->container->golemUpgrade1->starsTXT, this->costGolemUpgrade1);
				//this->container->golemUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem2"))
			{
				this->container->golemUpgrade2->gotoAndStop(3);
				this->container->golemUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->golemArrow1->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade2 && Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem1"))
			{
				this->container->golemUpgrade2->gotoAndStop(1);
				std::setText(this->container->golemUpgrade2->starsTXT, this->costGolemUpgrade2);
				//this->container->golemUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade2->upgradeCase->setMouseEnabled(true);
				this->container->golemArrow1->setVisible(false);
			}
			else
			{
				this->container->golemUpgrade2->gotoAndStop(4);
				std::setText(this->container->golemUpgrade2->starsTXT, this->costGolemUpgrade2);
				//this->container->golemUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->golemArrow1->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem3"))
			{
				this->container->golemUpgrade3->gotoAndStop(3);
				this->container->golemUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->golemArrow2->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade3 && Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem2"))
			{
				this->container->golemUpgrade3->gotoAndStop(1);
				std::setText(this->container->golemUpgrade3->starsTXT, this->costGolemUpgrade3);
				//this->container->golemUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade3->upgradeCase->setMouseEnabled(true);
				this->container->golemArrow2->setVisible(false);
			}
			else
			{
				this->container->golemUpgrade3->gotoAndStop(4);
				std::setText(this->container->golemUpgrade3->starsTXT, this->costGolemUpgrade3);
				//this->container->golemUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->golemArrow2->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem4"))
			{
				this->container->golemUpgrade4->gotoAndStop(3);
				this->container->golemUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->golemArrow3->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade4 && Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem3"))
			{
				this->container->golemUpgrade4->gotoAndStop(1);
				std::setText(this->container->golemUpgrade4->starsTXT, this->costGolemUpgrade4);
				//this->container->golemUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade4->upgradeCase->setMouseEnabled(true);
				this->container->golemArrow3->setVisible(false);
			}
			else
			{
				this->container->golemUpgrade4->gotoAndStop(4);
				std::setText(this->container->golemUpgrade4->starsTXT, this->costGolemUpgrade4);
				//this->container->golemUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->golemArrow3->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem5"))
			{
				this->container->golemUpgrade5->gotoAndStop(3);
				this->container->golemUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->golemArrow4->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costGolemUpgrade5 && Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem4"))
			{
				this->container->golemUpgrade5->gotoAndStop(1);
				std::setText(this->container->golemUpgrade5->starsTXT, this->costGolemUpgrade5);
				//this->container->golemUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade5->upgradeCase->setMouseEnabled(true);
				this->container->golemArrow4->setVisible(false);
			}
			else
			{
				this->container->golemUpgrade5->gotoAndStop(4);
				std::setText(this->container->golemUpgrade5->starsTXT, this->costGolemUpgrade5);
				//this->container->golemUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->golemUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->golemArrow4->setVisible(false);
			}
		}
		else
		{
			this->container->golemUpgrade1->gotoAndStop(5);
			std::setText(this->container->golemUpgrade1->starsTXT, this->costGolemUpgrade1);
			//this->container->golemUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->golemUpgrade1->upgradeCase->setMouseEnabled(false);
			this->container->golemUpgrade2->gotoAndStop(5);
			std::setText(this->container->golemUpgrade2->starsTXT, this->costGolemUpgrade2);
			//this->container->golemUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->golemUpgrade2->upgradeCase->setMouseEnabled(false);
			this->container->golemArrow1->setVisible(false);
			this->container->golemUpgrade3->gotoAndStop(5);
			std::setText(this->container->golemUpgrade3->starsTXT, this->costGolemUpgrade3);
			//this->container->golemUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->golemUpgrade3->upgradeCase->setMouseEnabled(false);
			this->container->golemArrow2->setVisible(false);
			this->container->golemUpgrade4->gotoAndStop(5);
			std::setText(this->container->golemUpgrade4->starsTXT, this->costGolemUpgrade4);
			//this->container->golemUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->golemUpgrade4->upgradeCase->setMouseEnabled(false);
			this->container->golemArrow3->setVisible(false);
			this->container->golemUpgrade5->gotoAndStop(5);
			std::setText(this->container->golemUpgrade5->starsTXT, this->costGolemUpgrade5);
			//this->container->golemUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->golemUpgrade5->upgradeCase->setMouseEnabled(false);
			this->container->golemArrow4->setVisible(false);
		}
		if (Main::mainClass->saveBoxClass->getIntValue("openLevels",1) > 0 || Main::mainClass->saveBoxClass->getIntValue("saveNo") > 3)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman1"))
			{
				this->container->icemanUpgrade1->gotoAndStop(3);
				this->container->icemanUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade1)
			{
				this->container->icemanUpgrade1->gotoAndStop(1);
				std::setText(this->container->icemanUpgrade1->starsTXT, this->costIcemanUpgrade1);
				//this->container->icemanUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade1->upgradeCase->setMouseEnabled(true);
			}
			else
			{
				this->container->icemanUpgrade1->gotoAndStop(4);
				std::setText(this->container->icemanUpgrade1->starsTXT, this->costIcemanUpgrade1);
				//this->container->icemanUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman2"))
			{
				this->container->icemanUpgrade2->gotoAndStop(3);
				this->container->icemanUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->icemanArrow1->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade2 && Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman1"))
			{
				this->container->icemanUpgrade2->gotoAndStop(1);
				std::setText(this->container->icemanUpgrade2->starsTXT, this->costIcemanUpgrade2);
				//this->container->icemanUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade2->upgradeCase->setMouseEnabled(true);
				this->container->icemanArrow1->setVisible(false);
			}
			else
			{
				this->container->icemanUpgrade2->gotoAndStop(4);
				std::setText(this->container->icemanUpgrade2->starsTXT, this->costIcemanUpgrade2);
				//this->container->icemanUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->icemanArrow1->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman3"))
			{
				this->container->icemanUpgrade3->gotoAndStop(3);
				this->container->icemanUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->icemanArrow2->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade3 && Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman2"))
			{
				this->container->icemanUpgrade3->gotoAndStop(1);
				std::setText(this->container->icemanUpgrade3->starsTXT, this->costIcemanUpgrade3);
				//this->container->icemanUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade3->upgradeCase->setMouseEnabled(true);
				this->container->icemanArrow2->setVisible(false);
			}
			else
			{
				this->container->icemanUpgrade3->gotoAndStop(4);
				std::setText(this->container->icemanUpgrade3->starsTXT, this->costIcemanUpgrade3);
				//this->container->icemanUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->icemanArrow2->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman4"))
			{
				this->container->icemanUpgrade4->gotoAndStop(3);
				this->container->icemanUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->icemanArrow3->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade4 && Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman3"))
			{
				this->container->icemanUpgrade4->gotoAndStop(1);
				std::setText(this->container->icemanUpgrade4->starsTXT, this->costIcemanUpgrade4);
				//this->container->icemanUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade4->upgradeCase->setMouseEnabled(true);
				this->container->icemanArrow3->setVisible(false);
			}
			else
			{
				this->container->icemanUpgrade4->gotoAndStop(4);
				std::setText(this->container->icemanUpgrade4->starsTXT, this->costIcemanUpgrade4);
				//this->container->icemanUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->icemanArrow3->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman5"))
			{
				this->container->icemanUpgrade5->gotoAndStop(3);
				this->container->icemanUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->icemanArrow4->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIcemanUpgrade5 && Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman4"))
			{
				this->container->icemanUpgrade5->gotoAndStop(1);
				std::setText(this->container->icemanUpgrade5->starsTXT, this->costIcemanUpgrade5);
				//this->container->icemanUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade5->upgradeCase->setMouseEnabled(true);
				this->container->icemanArrow4->setVisible(false);
			}
			else
			{
				this->container->icemanUpgrade5->gotoAndStop(4);
				std::setText(this->container->icemanUpgrade5->starsTXT, this->costIcemanUpgrade5);
				//this->container->icemanUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->icemanUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->icemanArrow4->setVisible(false);
			}
		}
		else
		{
			this->container->icemanUpgrade1->gotoAndStop(5);
			std::setText(this->container->icemanUpgrade1->starsTXT, this->costIcemanUpgrade1);
			//this->container->icemanUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->icemanUpgrade1->upgradeCase->setMouseEnabled(false);
			this->container->icemanUpgrade2->gotoAndStop(5);
			std::setText(this->container->icemanUpgrade2->starsTXT, this->costIcemanUpgrade2);
			//this->container->icemanUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->icemanUpgrade2->upgradeCase->setMouseEnabled(false);
			this->container->icemanArrow1->setVisible(false);
			this->container->icemanUpgrade3->gotoAndStop(5);
			std::setText(this->container->icemanUpgrade3->starsTXT, this->costIcemanUpgrade3);
			//this->container->icemanUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->icemanUpgrade3->upgradeCase->setMouseEnabled(false);
			this->container->icemanArrow2->setVisible(false);
			this->container->icemanUpgrade4->gotoAndStop(5);
			std::setText(this->container->icemanUpgrade4->starsTXT, this->costIcemanUpgrade4);
			//this->container->icemanUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->icemanUpgrade4->upgradeCase->setMouseEnabled(false);
			this->container->icemanArrow3->setVisible(false);
			this->container->icemanUpgrade5->gotoAndStop(5);
			std::setText(this->container->icemanUpgrade5->starsTXT, this->costIcemanUpgrade5);
			//this->container->icemanUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->icemanUpgrade5->upgradeCase->setMouseEnabled(false);
			this->container->icemanArrow4->setVisible(false);
		}
		if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 2)  > 0)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir1"))
			{
				this->container->airUpgrade1->gotoAndStop(3);
				this->container->airUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade1)
			{
				this->container->airUpgrade1->gotoAndStop(1);
				std::setText(this->container->airUpgrade1->starsTXT, this->costAirUpgrade1);
				//this->container->airUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade1->upgradeCase->setMouseEnabled(true);
			}
			else
			{
				this->container->airUpgrade1->gotoAndStop(4);
				std::setText(this->container->airUpgrade1->starsTXT, this->costAirUpgrade1);
				//this->container->airUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir2"))
			{
				this->container->airUpgrade2->gotoAndStop(3);
				this->container->airUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->airArrow1->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade2 && Main::mainClass->saveBoxClass->getBoolValue("upgradeAir1"))
			{
				this->container->airUpgrade2->gotoAndStop(1);
				std::setText(this->container->airUpgrade2->starsTXT, this->costAirUpgrade2);
				//this->container->airUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade2->upgradeCase->setMouseEnabled(true);
				this->container->airArrow1->setVisible(false);
			}
			else
			{
				this->container->airUpgrade2->gotoAndStop(4);
				std::setText(this->container->airUpgrade2->starsTXT, this->costAirUpgrade2);
				//this->container->airUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->airArrow1->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir3"))
			{
				this->container->airUpgrade3->gotoAndStop(3);
				this->container->airUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->airArrow2->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade3 && Main::mainClass->saveBoxClass->getBoolValue("upgradeAir2"))
			{
				this->container->airUpgrade3->gotoAndStop(1);
				std::setText(this->container->airUpgrade3->starsTXT, this->costAirUpgrade3);
				//this->container->airUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade3->upgradeCase->setMouseEnabled(true);
				this->container->airArrow2->setVisible(false);
			}
			else
			{
				this->container->airUpgrade3->gotoAndStop(4);
				std::setText(this->container->airUpgrade3->starsTXT, this->costAirUpgrade3);
				//this->container->airUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->airArrow2->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir4"))
			{
				this->container->airUpgrade4->gotoAndStop(3);
				this->container->airUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->airArrow3->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade4 && Main::mainClass->saveBoxClass->getBoolValue("upgradeAir3"))
			{
				this->container->airUpgrade4->gotoAndStop(1);
				std::setText(this->container->airUpgrade4->starsTXT, this->costAirUpgrade4);
				//this->container->airUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade4->upgradeCase->setMouseEnabled(true);
				this->container->airArrow3->setVisible(false);
			}
			else
			{
				this->container->airUpgrade4->gotoAndStop(4);
				std::setText(this->container->airUpgrade4->starsTXT, this->costAirUpgrade4);
				//this->container->airUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->airArrow3->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeAir5"))
			{
				this->container->airUpgrade5->gotoAndStop(3);
				this->container->airUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->airArrow4->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costAirUpgrade5 && Main::mainClass->saveBoxClass->getBoolValue("upgradeAir4"))
			{
				this->container->airUpgrade5->gotoAndStop(1);
				std::setText(this->container->airUpgrade5->starsTXT, this->costAirUpgrade5);
				//this->container->airUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade5->upgradeCase->setMouseEnabled(true);
				this->container->airArrow4->setVisible(false);
			}
			else
			{
				this->container->airUpgrade5->gotoAndStop(4);
				std::setText(this->container->airUpgrade5->starsTXT, this->costAirUpgrade5);
				//this->container->airUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->airUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->airArrow4->setVisible(false);
			}
		}
		else
		{
			this->container->airUpgrade1->gotoAndStop(5);
			std::setText(this->container->airUpgrade1->starsTXT, this->costAirUpgrade1);
			//this->container->airUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->airUpgrade1->upgradeCase->setMouseEnabled(false);
			this->container->airUpgrade2->gotoAndStop(5);
			std::setText(this->container->airUpgrade2->starsTXT, this->costAirUpgrade2);
			//this->container->airUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->airUpgrade2->upgradeCase->setMouseEnabled(false);
			this->container->airArrow1->setVisible(false);
			this->container->airUpgrade3->gotoAndStop(5);
			std::setText(this->container->airUpgrade3->starsTXT, this->costAirUpgrade3);
			//this->container->airUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->airUpgrade3->upgradeCase->setMouseEnabled(false);
			this->container->airArrow2->setVisible(false);
			this->container->airUpgrade4->gotoAndStop(5);
			std::setText(this->container->airUpgrade4->starsTXT, this->costAirUpgrade4);
			//this->container->airUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->airUpgrade4->upgradeCase->setMouseEnabled(false);
			this->container->airArrow3->setVisible(false);
			this->container->airUpgrade5->gotoAndStop(5);
			std::setText(this->container->airUpgrade5->starsTXT, this->costAirUpgrade5);
			//this->container->airUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->airUpgrade5->upgradeCase->setMouseEnabled(false);
			this->container->airArrow4->setVisible(false);
		}
		if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 1) > 0 || Main::mainClass->saveBoxClass->getIntValue("saveNo") > 3)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire1"))
			{
				this->container->fireUpgrade1->gotoAndStop(3);
				this->container->fireUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade1)
			{
				this->container->fireUpgrade1->gotoAndStop(1);
				std::setText(this->container->fireUpgrade1->starsTXT, this->costFireUpgrade1);
				//this->container->fireUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade1->upgradeCase->setMouseEnabled(true);
			}
			else
			{
				this->container->fireUpgrade1->gotoAndStop(4);
				std::setText(this->container->fireUpgrade1->starsTXT, this->costFireUpgrade1);
				//this->container->fireUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire2"))
			{
				this->container->fireUpgrade2->gotoAndStop(3);
				this->container->fireUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->fireArrow1->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade2 && Main::mainClass->saveBoxClass->getBoolValue("upgradeFire1"))
			{
				this->container->fireUpgrade2->gotoAndStop(1);
				std::setText(this->container->fireUpgrade2->starsTXT, this->costFireUpgrade2);
				//this->container->fireUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade2->upgradeCase->setMouseEnabled(true);
				this->container->fireArrow1->setVisible(false);
			}
			else
			{
				this->container->fireUpgrade2->gotoAndStop(4);
				std::setText(this->container->fireUpgrade2->starsTXT, this->costFireUpgrade2);
				//this->container->fireUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->fireArrow1->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire3"))
			{
				this->container->fireUpgrade3->gotoAndStop(3);
				this->container->fireUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->fireArrow2->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade3 && Main::mainClass->saveBoxClass->getBoolValue("upgradeFire2"))
			{
				this->container->fireUpgrade3->gotoAndStop(1);
				std::setText(this->container->fireUpgrade3->starsTXT, this->costFireUpgrade3);
				//this->container->fireUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade3->upgradeCase->setMouseEnabled(true);
				this->container->fireArrow2->setVisible(false);
			}
			else
			{
				this->container->fireUpgrade3->gotoAndStop(4);
				std::setText(this->container->fireUpgrade3->starsTXT, this->costFireUpgrade3);
				//this->container->fireUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->fireArrow2->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire4"))
			{
				this->container->fireUpgrade4->gotoAndStop(3);
				this->container->fireUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->fireArrow3->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade4 && Main::mainClass->saveBoxClass->getBoolValue("upgradeFire3"))
			{
				this->container->fireUpgrade4->gotoAndStop(1);
				std::setText(this->container->fireUpgrade4->starsTXT, this->costFireUpgrade4);
				//this->container->fireUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade4->upgradeCase->setMouseEnabled(true);
				this->container->fireArrow3->setVisible(false);
			}
			else
			{
				this->container->fireUpgrade4->gotoAndStop(4);
				std::setText(this->container->fireUpgrade4->starsTXT, this->costFireUpgrade4);
				//this->container->fireUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->fireArrow3->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire5"))
			{
				this->container->fireUpgrade5->gotoAndStop(3);
				this->container->fireUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->fireArrow4->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costFireUpgrade5 && Main::mainClass->saveBoxClass->getBoolValue("upgradeFire4"))
			{
				this->container->fireUpgrade5->gotoAndStop(1);
				std::setText(this->container->fireUpgrade5->starsTXT, this->costFireUpgrade5);
				//this->container->fireUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade5->upgradeCase->setMouseEnabled(true);
				this->container->fireArrow4->setVisible(false);
			}
			else
			{
				this->container->fireUpgrade5->gotoAndStop(4);
				std::setText(this->container->fireUpgrade5->starsTXT, this->costFireUpgrade5);
				//this->container->fireUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->fireUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->fireArrow4->setVisible(false);
			}
		}
		else
		{
			this->container->fireUpgrade1->gotoAndStop(5);
			std::setText(this->container->fireUpgrade1->starsTXT, this->costFireUpgrade1);
			//this->container->fireUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->fireUpgrade1->upgradeCase->setMouseEnabled(false);
			this->container->fireUpgrade2->gotoAndStop(5);
			std::setText(this->container->fireUpgrade2->starsTXT, this->costFireUpgrade2);
			//this->container->fireUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->fireUpgrade2->upgradeCase->setMouseEnabled(false);
			this->container->fireArrow1->setVisible(false);
			this->container->fireUpgrade3->gotoAndStop(5);
			std::setText(this->container->fireUpgrade3->starsTXT, this->costFireUpgrade3);
			//this->container->fireUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->fireUpgrade3->upgradeCase->setMouseEnabled(false);
			this->container->fireArrow2->setVisible(false);
			this->container->fireUpgrade4->gotoAndStop(5);
			std::setText(this->container->fireUpgrade4->starsTXT, this->costFireUpgrade4);
			//this->container->fireUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->fireUpgrade4->upgradeCase->setMouseEnabled(false);
			this->container->fireArrow3->setVisible(false);
			this->container->fireUpgrade5->gotoAndStop(5);
			std::setText(this->container->fireUpgrade5->starsTXT, this->costFireUpgrade5);
			//this->container->fireUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->fireUpgrade5->upgradeCase->setMouseEnabled(false);
			this->container->fireArrow4->setVisible(false);
		}
		if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 1) > 0 || Main::mainClass->saveBoxClass->getIntValue("saveNo") > 3)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce1"))
			{
				this->container->iceUpgrade1->gotoAndStop(3);
				this->container->iceUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIceUpgrade1)
			{
				this->container->iceUpgrade1->gotoAndStop(1);
				std::setText(this->container->iceUpgrade1->starsTXT, this->costIceUpgrade1);
				//this->container->iceUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade1->upgradeCase->setMouseEnabled(true);
			}
			else
			{
				this->container->iceUpgrade1->gotoAndStop(4);
				std::setText(this->container->iceUpgrade1->starsTXT, this->costIceUpgrade1);
				//this->container->iceUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce2"))
			{
				this->container->iceUpgrade2->gotoAndStop(3);
				this->container->iceUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->iceArrow1->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIceUpgrade2 && Main::mainClass->saveBoxClass->getBoolValue("upgradeIce1"))
			{
				this->container->iceUpgrade2->gotoAndStop(1);
				std::setText(this->container->iceUpgrade2->starsTXT, this->costIceUpgrade2);
				//this->container->iceUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade2->upgradeCase->setMouseEnabled(true);
				this->container->iceArrow1->setVisible(false);
			}
			else
			{
				this->container->iceUpgrade2->gotoAndStop(4);
				std::setText(this->container->iceUpgrade2->starsTXT, this->costIceUpgrade2);
				//this->container->iceUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->iceArrow1->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce3"))
			{
				this->container->iceUpgrade3->gotoAndStop(3);
				this->container->iceUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->iceArrow2->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIceUpgrade3 && Main::mainClass->saveBoxClass->getBoolValue("upgradeIce2"))
			{
				this->container->iceUpgrade3->gotoAndStop(1);
				std::setText(this->container->iceUpgrade3->starsTXT, this->costIceUpgrade3);
				//this->container->iceUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade3->upgradeCase->setMouseEnabled(true);
				this->container->iceArrow2->setVisible(false);
			}
			else
			{
				this->container->iceUpgrade3->gotoAndStop(4);
				std::setText(this->container->iceUpgrade3->starsTXT, this->costIceUpgrade3);
				//this->container->iceUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->iceArrow2->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce4"))
			{
				this->container->iceUpgrade4->gotoAndStop(3);
				this->container->iceUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->iceArrow3->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIceUpgrade4 && Main::mainClass->saveBoxClass->getBoolValue("upgradeIce3"))
			{
				this->container->iceUpgrade4->gotoAndStop(1);
				std::setText(this->container->iceUpgrade4->starsTXT, this->costIceUpgrade4);
				//this->container->iceUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade4->upgradeCase->setMouseEnabled(true);
				this->container->iceArrow3->setVisible(false);
			}
			else
			{
				this->container->iceUpgrade4->gotoAndStop(4);
				std::setText(this->container->iceUpgrade4->starsTXT, this->costIceUpgrade4);
				//this->container->iceUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->iceArrow3->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeIce5"))
			{
				this->container->iceUpgrade5->gotoAndStop(3);
				this->container->iceUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->iceArrow4->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costIceUpgrade5 && Main::mainClass->saveBoxClass->getBoolValue("upgradeIce4"))
			{
				this->container->iceUpgrade5->gotoAndStop(1);
				std::setText(this->container->iceUpgrade5->starsTXT, this->costIceUpgrade5);
				//this->container->iceUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade5->upgradeCase->setMouseEnabled(true);
				this->container->iceArrow4->setVisible(false);
			}
			else
			{
				this->container->iceUpgrade5->gotoAndStop(4);
				std::setText(this->container->iceUpgrade5->starsTXT, this->costIceUpgrade5);
				//this->container->iceUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->iceUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->iceArrow4->setVisible(false);
			}
		}
		else
		{
			this->container->iceUpgrade1->gotoAndStop(5);
			std::setText(this->container->iceUpgrade1->starsTXT, this->costIceUpgrade1);
			//this->container->iceUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->iceUpgrade1->upgradeCase->setMouseEnabled(false);
			this->container->iceUpgrade2->gotoAndStop(5);
			std::setText(this->container->iceUpgrade2->starsTXT, this->costIceUpgrade2);
			//this->container->iceUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->iceUpgrade2->upgradeCase->setMouseEnabled(false);
			this->container->iceArrow1->setVisible(false);
			this->container->iceUpgrade3->gotoAndStop(5);
			std::setText(this->container->iceUpgrade3->starsTXT, this->costIceUpgrade3);
			//this->container->iceUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->iceUpgrade3->upgradeCase->setMouseEnabled(false);
			this->container->iceArrow2->setVisible(false);
			this->container->iceUpgrade4->gotoAndStop(5);
			std::setText(this->container->iceUpgrade4->starsTXT, this->costIceUpgrade4);
			//this->container->iceUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->iceUpgrade4->upgradeCase->setMouseEnabled(false);
			this->container->iceArrow3->setVisible(false);
			this->container->iceUpgrade5->gotoAndStop(5);
			std::setText(this->container->iceUpgrade5->starsTXT, this->costIceUpgrade5);
			//this->container->iceUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->iceUpgrade5->upgradeCase->setMouseEnabled(false);
			this->container->iceArrow4->setVisible(false);
		}
		if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 2)  > 0)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone1"))
			{
				this->container->stoneUpgrade1->gotoAndStop(3);
				this->container->stoneUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade1)
			{
				this->container->stoneUpgrade1->gotoAndStop(1);
				std::setText(this->container->stoneUpgrade1->starsTXT, this->costStoneUpgrade1);
				//this->container->stoneUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade1->upgradeCase->setMouseEnabled(true);
			}
			else
			{
				this->container->stoneUpgrade1->gotoAndStop(4);
				std::setText(this->container->stoneUpgrade1->starsTXT, this->costStoneUpgrade1);
				//this->container->stoneUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone2"))
			{
				this->container->stoneUpgrade2->gotoAndStop(3);
				this->container->stoneUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->stoneArrow1->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade2 && Main::mainClass->saveBoxClass->getBoolValue("upgradeStone1"))
			{
				this->container->stoneUpgrade2->gotoAndStop(1);
				std::setText(this->container->stoneUpgrade2->starsTXT, this->costStoneUpgrade2);
				//this->container->stoneUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade2->upgradeCase->setMouseEnabled(true);
				this->container->stoneArrow1->setVisible(false);
			}
			else
			{
				this->container->stoneUpgrade2->gotoAndStop(4);
				std::setText(this->container->stoneUpgrade2->starsTXT, this->costStoneUpgrade2);
				//this->container->stoneUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->stoneArrow1->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone3"))
			{
				this->container->stoneUpgrade3->gotoAndStop(3);
				this->container->stoneUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->stoneArrow2->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade3 && Main::mainClass->saveBoxClass->getBoolValue("upgradeStone2"))
			{
				this->container->stoneUpgrade3->gotoAndStop(1);
				std::setText(this->container->stoneUpgrade3->starsTXT, this->costStoneUpgrade3);
				//this->container->stoneUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade3->upgradeCase->setMouseEnabled(true);
				this->container->stoneArrow2->setVisible(false);
			}
			else
			{
				this->container->stoneUpgrade3->gotoAndStop(4);
				std::setText(this->container->stoneUpgrade3->starsTXT, this->costStoneUpgrade3);
				//this->container->stoneUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->stoneArrow2->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone4"))
			{
				this->container->stoneUpgrade4->gotoAndStop(3);
				this->container->stoneUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->stoneArrow3->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade4 && Main::mainClass->saveBoxClass->getBoolValue("upgradeStone3"))
			{
				this->container->stoneUpgrade4->gotoAndStop(1);
				std::setText(this->container->stoneUpgrade4->starsTXT, this->costStoneUpgrade4);
				//this->container->stoneUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade4->upgradeCase->setMouseEnabled(true);
				this->container->stoneArrow3->setVisible(false);
			}
			else
			{
				this->container->stoneUpgrade4->gotoAndStop(4);
				std::setText(this->container->stoneUpgrade4->starsTXT, this->costStoneUpgrade4);
				//this->container->stoneUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->stoneArrow3->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeStone5"))
			{
				this->container->stoneUpgrade5->gotoAndStop(3);
				this->container->stoneUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->stoneArrow4->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costStoneUpgrade5 && Main::mainClass->saveBoxClass->getBoolValue("upgradeStone4"))
			{
				this->container->stoneUpgrade5->gotoAndStop(1);
				std::setText(this->container->stoneUpgrade5->starsTXT, this->costStoneUpgrade5);
				//this->container->stoneUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade5->upgradeCase->setMouseEnabled(true);
				this->container->stoneArrow4->setVisible(false);
			}
			else
			{
				this->container->stoneUpgrade5->gotoAndStop(4);
				std::setText(this->container->stoneUpgrade5->starsTXT, this->costStoneUpgrade5);
				//this->container->stoneUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->stoneUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->stoneArrow4->setVisible(false);
			}
		}
		else
		{
			this->container->stoneUpgrade1->gotoAndStop(5);
			std::setText(this->container->stoneUpgrade1->starsTXT, this->costStoneUpgrade1);
			//this->container->stoneUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->stoneUpgrade1->upgradeCase->setMouseEnabled(false);
			this->container->stoneUpgrade2->gotoAndStop(5);
			std::setText(this->container->stoneUpgrade2->starsTXT, this->costStoneUpgrade2);
			//this->container->stoneUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->stoneUpgrade2->upgradeCase->setMouseEnabled(false);
			this->container->stoneArrow1->setVisible(false);
			this->container->stoneUpgrade3->gotoAndStop(5);
			std::setText(this->container->stoneUpgrade3->starsTXT, this->costStoneUpgrade3);
			//this->container->stoneUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->stoneUpgrade3->upgradeCase->setMouseEnabled(false);
			this->container->stoneArrow2->setVisible(false);
			this->container->stoneUpgrade4->gotoAndStop(5);
			std::setText(this->container->stoneUpgrade4->starsTXT, this->costStoneUpgrade4);
			//this->container->stoneUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->stoneUpgrade4->upgradeCase->setMouseEnabled(false);
			this->container->stoneArrow3->setVisible(false);
			this->container->stoneUpgrade5->gotoAndStop(5);
			std::setText(this->container->stoneUpgrade5->starsTXT, this->costStoneUpgrade5);
			//this->container->stoneUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->stoneUpgrade5->upgradeCase->setMouseEnabled(false);
			this->container->stoneArrow4->setVisible(false);
		}
		if (Main::mainClass->saveBoxClass->getIntValue("openLevels",3) > 0)
		{
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin1"))
			{
				this->container->levinUpgrade1->gotoAndStop(3);
				this->container->levinUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade1)
			{
				this->container->levinUpgrade1->gotoAndStop(1);
				std::setText(this->container->levinUpgrade1->starsTXT, this->costLevinUpgrade1);
				//this->container->levinUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade1->upgradeCase->setMouseEnabled(true);
			}
			else
			{
				this->container->levinUpgrade1->gotoAndStop(4);
				std::setText(this->container->levinUpgrade1->starsTXT, this->costLevinUpgrade1);
				//this->container->levinUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade1->upgradeCase->setMouseEnabled(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin2"))
			{
				this->container->levinUpgrade2->gotoAndStop(3);
				this->container->levinUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->levinArrow1->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade2 && Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin1"))
			{
				this->container->levinUpgrade2->gotoAndStop(1);
				std::setText(this->container->levinUpgrade2->starsTXT, this->costLevinUpgrade2);
				//this->container->levinUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade2->upgradeCase->setMouseEnabled(true);
				this->container->levinArrow1->setVisible(false);
			}
			else
			{
				this->container->levinUpgrade2->gotoAndStop(4);
				std::setText(this->container->levinUpgrade2->starsTXT, this->costLevinUpgrade2);
				//this->container->levinUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade2->upgradeCase->setMouseEnabled(false);
				this->container->levinArrow1->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin3"))
			{
				this->container->levinUpgrade3->gotoAndStop(3);
				this->container->levinUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->levinArrow2->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade3 && Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin2"))
			{
				this->container->levinUpgrade3->gotoAndStop(1);
				std::setText(this->container->levinUpgrade3->starsTXT, this->costLevinUpgrade3);
				//this->container->levinUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade3->upgradeCase->setMouseEnabled(true);
				this->container->levinArrow2->setVisible(false);
			}
			else
			{
				this->container->levinUpgrade3->gotoAndStop(4);
				std::setText(this->container->levinUpgrade3->starsTXT, this->costLevinUpgrade3);
				//this->container->levinUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade3->upgradeCase->setMouseEnabled(false);
				this->container->levinArrow2->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin4"))
			{
				this->container->levinUpgrade4->gotoAndStop(3);
				this->container->levinUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->levinArrow3->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade4 && Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin3"))
			{
				this->container->levinUpgrade4->gotoAndStop(1);
				std::setText(this->container->levinUpgrade4->starsTXT, this->costLevinUpgrade4);
				//this->container->levinUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade4->upgradeCase->setMouseEnabled(true);
				this->container->levinArrow3->setVisible(false);
			}
			else
			{
				this->container->levinUpgrade4->gotoAndStop(4);
				std::setText(this->container->levinUpgrade4->starsTXT, this->costLevinUpgrade4);
				//this->container->levinUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade4->upgradeCase->setMouseEnabled(false);
				this->container->levinArrow3->setVisible(false);
			}
			if (Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin5"))
			{
				this->container->levinUpgrade5->gotoAndStop(3);
				this->container->levinUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->levinArrow4->setVisible(true);
			}
			else if (Main::mainClass->saveBoxClass->getIntValue("stars") >= this->costLevinUpgrade5 && Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin4"))
			{
				this->container->levinUpgrade5->gotoAndStop(1);
				std::setText(this->container->levinUpgrade5->starsTXT, this->costLevinUpgrade5);
				//this->container->levinUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade5->upgradeCase->setMouseEnabled(true);
				this->container->levinArrow4->setVisible(false);
			}
			else
			{
				this->container->levinUpgrade5->gotoAndStop(4);
				std::setText(this->container->levinUpgrade5->starsTXT, this->costLevinUpgrade5);
				//this->container->levinUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
				this->container->levinUpgrade5->upgradeCase->setMouseEnabled(false);
				this->container->levinArrow4->setVisible(false);
			}
		}
		else
		{
			this->container->levinUpgrade1->gotoAndStop(5);
			std::setText(this->container->levinUpgrade1->starsTXT, this->costLevinUpgrade1);
			//this->container->levinUpgrade1->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->levinUpgrade1->upgradeCase->setMouseEnabled(false);
			this->container->levinUpgrade2->gotoAndStop(5);
			std::setText(this->container->levinUpgrade2->starsTXT, this->costLevinUpgrade2);
			//this->container->levinUpgrade2->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->levinUpgrade2->upgradeCase->setMouseEnabled(false);
			this->container->levinArrow1->setVisible(false);
			this->container->levinUpgrade3->gotoAndStop(5);
			std::setText(this->container->levinUpgrade3->starsTXT, this->costLevinUpgrade3);
			//this->container->levinUpgrade3->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->levinUpgrade3->upgradeCase->setMouseEnabled(false);
			this->container->levinArrow2->setVisible(false);
			this->container->levinUpgrade4->gotoAndStop(5);
			std::setText(this->container->levinUpgrade4->starsTXT, this->costLevinUpgrade4);
			//this->container->levinUpgrade4->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->levinUpgrade4->upgradeCase->setMouseEnabled(false);
			this->container->levinArrow3->setVisible(false);
			this->container->levinUpgrade5->gotoAndStop(5);
			std::setText(this->container->levinUpgrade5->starsTXT, this->costLevinUpgrade5);
			//this->container->levinUpgrade5->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
			this->container->levinUpgrade5->upgradeCase->setMouseEnabled(false);
			this->container->levinArrow4->setVisible(false);
		}
		if (Main::mainClass->saveBoxClass->getBoolValue("upgradeFire1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeIce1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeStone1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeLevin1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeIceman1") || Main::mainClass->saveBoxClass->getBoolValue("upgradeAir1"))
		{
			if (this->container->contBtnReset->currentFrame == 4)
			{
				this->container->contBtnReset->gotoAndStop(1);
				this->container->contBtnResetResetCase->setMouseEnabled(true);
			}
		}
		else if (this->container->contBtnReset->currentFrame != 4)
		{
			this->container->contBtnReset->gotoAndStop(4);
			this->container->contBtnResetResetCase->setMouseEnabled(false);
		}
		std::setText(this->container->starsTXT, Main::mainClass->saveBoxClass->getIntValue("stars"));
		//this->container->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
		std::setText(Main::mainClass->levelsMenuClass->container->freeStarsContStarsTXT, Main::mainClass->saveBoxClass->getIntValue("stars"));
		//Main::mainClass->levelsMenuClass->container->freeStarsContStarsTXT.setTextFormat(Main::mainClass->boldTextFormat);
		return;
	}// end function

	void Upgrades::close()
	{
		if (!this->closeFlag)
		{
			this->closeFlag = true;
			this->container->cont->setMouseChildren(false);
			this->container->cont->setMouseEnabled(false);
			Main::mainClass->levelsMenuClass->container->upgrades->gotoAndStop(1);
			//this->stage.frameRate = 60;
			if (Main::mainClass->saveBoxClass->getIntValue("stars") == 0)
			{
				Main::mainClass->levelsMenuClass->container->freeStars->setVisible(false);
			}
			else
			{
				Main::mainClass->levelsMenuClass->container->freeStars->gotoAndStop(1);
				Main::mainClass->levelsMenuClass->container->freeStarsCont->gotoAndStop(1);
				Main::mainClass->levelsMenuClass->container->freeStars->setVisible(true);
			}
		}
		return;
	}// end function

	void Upgrades::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			this->levelsMenu->removeChild(this->levelsMenu->upgradesClass);
			this->levelsMenu->upgradesClass = NULL;
			this->levelsMenu->manageListeners("on");
		}
		return;
	}// end function

	//void Upgrades::reInit(event:Event)
	//{
	//    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
	//    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
	//    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
	//    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
	//    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
	//    this->stage.frameRate = 30;
	//    Main::mainClass->saveBoxClass.updateSever();
	//    return;
	//}// end function

}

