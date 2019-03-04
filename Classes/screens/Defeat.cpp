#include "Defeat.h"   
#include "engine/World.h"   

using namespace engine;

namespace screens
{
	DefMenu_mc::DefMenu_mc() :MovieClip("screen", "DefMenu_mc", "DefMenu_mc")
	{
		first = this->createMovieClipSub("first");
		firstScroll = this->first->createMovieClipSub("scroll");
		firstFire = this->first->createMovieClipSub("fire");
		firstScrollBtnContinue = this->first->createMovieClipSub("btnContinue");
		firstScrollBtnRestart = this->first->createMovieClipSub("btnRestart");
		firstScrollBtnContinueContinueCase = this->firstScrollBtnContinue->createCase("continueCase");
		firstScrollBtnRestartRestartCase = this->firstScrollBtnRestart->createCase("restartCase");
		firstScrollBtnRestartArrow = this->firstScrollBtnRestart->createMovieClipSub("arrow");
		firstScrollBtnContinueArrow = this->firstScrollBtnContinue->createMovieClipSub("arrow");
	};

	Defeat::Defeat() : world(0), firstSoundPlay(false)
	{
		init();
		//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
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
		this->world->worldInterface->breaking();
		int addit_levelsDefeatCounter = Main::mainClass->saveBoxClass->getIntValue("addit_levelsDefeatCounter", this->world->nowLevel - 1) + 1;
		Main::mainClass->saveBoxClass->setValue("addit_levelsDefeatCounter", addit_levelsDefeatCounter);
		//(Main::mainClass->saveBoxClass.gameSave.data.addit_levelsDefeatCounter[(this->world->nowLevel - 1)] + 1);
		this->container = new DefMenu_mc();
		cocos2d::Size size = this->container->getSprite("shadow")->getContentSize();
		float sy = Main::SCREEN_HEIGHT / size.height;
		float sx = (size.width - Main::SCREEN_WIDTH) / 2;
		this->container->setPosition(0, 100);//600
		this->container->setScaleY(sy);
		this->container->stop();
		this->container->first->stop();
		this->container->firstFire->stop();
		this->container->firstScroll->stop();
		this->container->firstScrollBtnContinue->stop();
		this->container->firstScrollBtnContinueArrow->stop();
		this->container->firstScrollBtnRestart->stop();
		this->container->firstScrollBtnRestartArrow->stop();
		this->container->firstScrollBtnContinueContinueCase->setMouseEnabled(true);
		this->container->firstScrollBtnRestartRestartCase->setMouseEnabled(true);
		this->container->first->setMouseChildren(false);
		this->container->first->setMouseEnabled(false);
		this->container->firstScrollBtnContinueArrow->setVisible(false);
		this->container->firstScrollBtnRestartArrow->setVisible(false);
		this->addChild(this->container);
		if (this->world->nowLevel <= 5)
		{
			//Main::mainClass->tracker.trackPageview("defeatLevel_" + this->world->nowLevel);
		}
		this->manageListeners("on");
		return true;
	}// end function

	void Defeat::enterFrameHandler(float dt)
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
						AudioUtil::setMusicVolume(AudioUtil::getMusicVolume() - 0.1);
					}
					else if (AudioUtil::getMusicVolume() != 0)
					{
						AudioUtil::setMusicVolume(0);
					}
				}
			}
			else
			{
				this->firstSoundPlay = true;
				AudioUtil::stopAll();
				AudioUtil::playSound("Snd_menu_defeat.mp3");
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
				this->container->first->setMouseEnabled(true);
				cocos2d::Point tempObject(Main::mouseX, Main::mouseY);
				if (this->container->firstScrollBtnContinueContinueCase->hitTest(tempObject)) {
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
		if (this->container->firstFire->currentFrame < this->container->firstFire->totalFrames)
		{
			this->container->firstFire->gotoAndStop((this->container->firstFire->currentFrame + 1));
		}
		else
		{
			this->container->firstFire->gotoAndStop(1);
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
		return;
	}// end function

	void Defeat::mouseMoveHandler(cocos2d::EventMouse * e)
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
		}
	}// end function

	void Defeat::mouseDownHandler(cocos2d::EventMouse * e)
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
		}
	}// end function

	void Defeat::mouseUpHandler(cocos2d::EventMouse * e)
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
					Main::mainClass->addNewScreen("LevelsMenu");
					//Main::mainClass->testingClass = NULL;
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
					Main::mainClass->addNewScreen("World");
					//Main::mainClass->testingClass = NULL;
				}
			}
			else if (this->container->firstScrollBtnRestart->currentFrame == 3)
			{
				this->container->firstScrollBtnRestart->gotoAndStop(1);
			}
		}
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
