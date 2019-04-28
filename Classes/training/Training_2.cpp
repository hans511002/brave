#include "Training_2.h"   
#include "Training_3.h"   
#include "engine/world.h"   

using namespace engine;

namespace training
{
	Training_2_mc::Training_2_mc() :MovieClip("training", "Training_2_mc", "Training_2_mc")
	{
		this->cont = this->createMovieClipSub("cont");
		this->contBtnOk = this->cont->createMovieClipSub("btnOk");
		this->contBtnOkOkCase = this->contBtnOk->createCase("okCase");
	};
	Training_2::Training_2()
	{
		init();
		return;
	}// end function

	bool Training_2::init()
	{
		/*this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		this->addEventListener(MouseEvent->MOUSE_MOVE, this->mouseMoveHandler);
		this->addEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
		this->addEventListener(MouseEvent->MOUSE_UP, this->mouseUpHandler);*/
		//this->enableFrameHandler();
		//this->enableMouseHandler();
		
		this->world = Main::mainClass->worldClass;
		this->manageListeners("on");
		this->world->manageListeners("off");
		this->container = new Training_2_mc();
		this->container->setPosition(Vec2(Main::SCREEN_WIDTH_HALF, Main::LEVEL_MAP_HEIGHT/2-50)-this->world->getPosition());
		this->contStops();
		this->addChild(this->container);
		AudioUtil::playSound("Snd_menu_pageScrolling.mp3");
		this->setZOrder(10);
		return true;
	}// end function

	void Training_2::enterFrameHandler(float dt)
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
			if (this->container->cont->currentFrame < this->container->cont->totalFrames)
			{
				this->container->cont->gotoAndStop((this->container->cont->currentFrame + 1));
				this->contStops();
			}
			if (this->container->currentFrame == this->container->totalFrames && this->container->cont->currentFrame == this->container->cont->totalFrames)
			{
				this->openFlag = false;
				this->container->cont->mouseChildren = true;
				this->container->cont->mouseEnabled = true;
			}
		}
		else if (this->closeFlag)
		{
			if (this->container->currentFrame > 1)
			{
				this->container->gotoAndStop((this->container->currentFrame - 1));
			}
			if (this->container->cont->currentFrame > 1)
			{
				this->container->cont->gotoAndStop((this->container->cont->currentFrame - 1));
				this->contStops();
			}
			if (this->container->currentFrame == 1 && this->container->cont->currentFrame == 1)
			{
				this->closeFlag = false;
				this->kill();
			}
		}
		return;
	}// end function

	void Training_2::mouseMoveHandler(cocos2d::EventMouse * e)
	{
		if (Main::mouseX == e->getCursorX() && Main::mouseY == e->getCursorY())
			return;
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		if (!globalNode)EventNode::mouseMoveHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		else if (globalNode && globalNode == this) {
			//if (!std::hitTest(this, e))return;
		}
		std::MouseEvent *event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_MOVE))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		//return;
		while (event->hasNext()) {
			string targetName = event->target->getName();
			if (targetName == "okCase")
			{
				if (this->container->contBtnOk->currentFrame == 1)
				{
					this->container->contBtnOk->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->contBtnOk->currentFrame == 2)
			{
				this->container->contBtnOk->gotoAndStop(1);
			}
		}
	}// end function

	void Training_2::mouseDownHandler(cocos2d::EventMouse * e)
	{
		if (!globalNode)EventNode::mouseDownHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		else if (globalNode && globalNode == this) {
			//if (!std::hitTest(e->getCurrentTarget(), e, true, true))return;
			e->stopPropagation();
		}
		std::MouseEvent *event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_DOWN))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
		while (event->hasNext()) {
			string targetName = event->target->getName();
			if (targetName == "okCase")
			{
				if (this->container->contBtnOk->currentFrame == 2)
				{
					this->container->contBtnOk->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
		}
		return;
	}// end function

	void Training_2::mouseUpHandler(cocos2d::EventMouse * e)
	{
		if (!globalNode)EventNode::mouseUpHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		else if (globalNode && globalNode == this) {
			//if (!std::hitTest(this, e))return;
		}
		std::MouseEvent *event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_UP))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
		while (event->hasNext()) {
			string targetName = event->target->getName();
			if (targetName == "okCase")
			{
				if (this->container->contBtnOk->currentFrame == 3)
				{
					this->container->contBtnOk->gotoAndStop(1);
					this->close();
				}
			}
			else if (this->container->contBtnOk->currentFrame == 3)
			{
				this->container->contBtnOk->gotoAndStop(1);
			}
		}
	}// end function

	void Training_2::contStops()
	{
		this->container->stop();
		this->container->cont->stop();
		this->container->contBtnOk->stop();
		this->container->contBtnOkOkCase->mouseEnabled = true;
		this->container->cont->mouseChildren = false;
		this->container->cont->mouseEnabled = false;
		return;
	}// end function


	void Training_2::close()
	{
		if (!this->closeFlag)
		{
			this->closeFlag = true;
			this->container->cont->mouseChildren = false;
			this->container->cont->mouseEnabled = false;
			AudioUtil::playSound("Snd_menu_pageScrolling.mp3");
		}
		return;
	}// end function

	void Training_2::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			this->world->removeChild(this);
			this->world->menuObject = NULL;
			this->world->menuObject = new Training_3();
			this->world->addChild(this->world->menuObject,99);
			this->world->manageListeners("on");
		}
		return;
	}// end function

}
