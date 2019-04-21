#include "Training_8.h"   
#include "engine/World.h"   

using namespace engine;

namespace training
{
	Training_8_mc::Training_8_mc() :MovieClip("training", "Training_8_mc", "Training_8_mc")
	{
		this->cont = this->createMovieClipSub("cont");
		this->contCont1 = this->cont->createMovieClipSub("cont1");
		this->contCont1BtnLeft = this->contCont1->createMovieClipSub("btnLeft");
		this->contCont1BtnRight = this->contCont1->createMovieClipSub("btnRight");
		this->contCont1BtnOk = this->contCont1->createMovieClipSub("btnOk");
		this->contCont1BtnLeftArrowCase = this->contCont1BtnLeft->createCase("arrowCase");
		this->contCont1BtnRightArrowCase = this->contCont1BtnRight->createCase("arrowCase");
		this->contCont1BtnOkOkCase = this->contCont1BtnOk->createCase("okCase");

	};

	Training_8::Training_8(int param1) :viewCounter(15)
	{
		//this->addEventListener(Event->ADDED_TO_STAGE, this->init);
		this->page = param1;
		this->type = param1;
		this->init();
		return;
	}// end function

	bool Training_8::init()
	{
		//this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		//this->addEventListener(MouseEvent->MOUSE_MOVE, this->mouseMoveHandler);
		//this->addEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
		//this->addEventListener(MouseEvent->MOUSE_UP, this->mouseUpHandler);
		this->world = Main::mainClass->worldClass;
		this->manageListeners("on");
		this->container = new Training_8_mc();
		this->container->setPosition(Main::SCREEN_WIDTH_HALF, Main::LEVEL_MAP_HEIGHT/2+20);
		this->contStops();
		this->container->cont->mouseChildren = false;
		this->container->cont->mouseEnabled = false;
		this->container->cont->setVisible(false);
		this->addChild(this->container);
		AudioUtil::playSound("snd_menu_pageScrolling");
		return true;
	}// end function

	void Training_8::enterFrameHandler(float dt)
	{
		if (this->frameCounter < 30)
		{
			this->frameCounter++;
		}
		else
		{
			this->frameCounter = 1;
		}
		if (this->viewCounter > 0)
		{
			this->viewCounter--;
			if (this->viewCounter == 0)
			{
				this->world->manageListeners("off");
				if (this->world->exchange)
				{
					this->world->worldInterface->breaking();
				}
				else if (this->world->getSphere || this->world->cast)
				{
					this->world->manageMouse("show");
				}
				this->container->cont->setVisible(true);
			}
			else
			{
				return;
			}
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
				this->container->cont->mouseChildren = false;
				this->container->cont->mouseEnabled = false;
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
				this->container->cont->mouseChildren = false;
				this->container->cont->mouseEnabled = false;
			}
			if (this->container->currentFrame == 1 && this->container->cont->currentFrame == 1)
			{
				this->closeFlag = false;
				this->kill();
			}
		}
		return;
	}// end function

	void Training_8::mouseMoveHandler(cocos2d::EventMouse * e)
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
				if (this->container->contCont1BtnOk->currentFrame == 1)
				{
					this->container->contCont1BtnOk->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->contCont1BtnOk->currentFrame == 2)
			{
				this->container->contCont1BtnOk->gotoAndStop(1);
			}
			if (targetName == "arrowCase")
			{
				string parName = event->target->getParent()->getParent()->getName();
				MC * parent = this->container->getMemSubMC(parName);
				if (parent->currentFrame == 1)
				{
					parent->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else
			{
				if (this->container->contCont1BtnLeft->currentFrame == 2)
				{
					this->container->contCont1BtnLeft->gotoAndStop(1);
				}
				if (this->container->contCont1BtnRight->currentFrame == 2)
				{
					this->container->contCont1BtnRight->gotoAndStop(1);
				}
			}
		}
	}// end function

	void Training_8::mouseDownHandler(cocos2d::EventMouse * e)
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
				if (this->container->contCont1BtnOk->currentFrame == 2)
				{
					this->container->contCont1BtnOk->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "arrowCase")
			{
				string parName = event->target->getParent()->getParent()->getName();
				MC * parent = this->container->getMemSubMC(parName);
				if (parent->currentFrame == 2)
				{
					parent->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
		}
	}// end function

	void Training_8::mouseUpHandler(cocos2d::EventMouse * e)
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
				if (this->container->contCont1BtnOk->currentFrame == 3)
				{
					this->container->contCont1BtnOk->gotoAndStop(1);
					this->close();
				}
			}
			else if (this->container->contCont1BtnOk->currentFrame == 3)
			{
				this->container->contCont1BtnOk->gotoAndStop(1);
			}
			if (targetName == "arrowCase")
			{
				string parName = event->target->getParent()->getParent()->getName();
				MC * parent = this->container->getMemSubMC(parName);
				if (parent->currentFrame == 3)
				{
					if (parName == "btnLeft")
					{
						this->container->contCont1BtnLeft->gotoAndStop(2);
						if (this->page == 1)
						{
							this->page = 2;
						}
						else
						{
							this->page = 1;
						}
						this->contStops();
					}
					else if (parName == "btnRight")
					{
						this->container->contCont1BtnRight->gotoAndStop(2);
						if (this->page == 1)
						{
							this->page = 2;
						}
						else
						{
							this->page = 1;
						}
						this->contStops();
					}
				}
			}
			else
			{
				if (this->container->contCont1BtnLeft->currentFrame == 3)
				{
					this->container->contCont1BtnLeft->gotoAndStop(1);
				}
				if (this->container->contCont1BtnRight->currentFrame == 3)
				{
					this->container->contCont1BtnRight->gotoAndStop(1);
				}
			}
		}
	}// end function

	void Training_8::contStops()
	{
		this->container->stop();
		this->container->cont->stop();
		this->container->contCont1->gotoAndStop(this->page);
		this->container->contCont1BtnOk->stop();
		this->container->contCont1BtnLeft->stop();
		this->container->contCont1BtnRight->stop();
		this->container->contCont1BtnOkOkCase->mouseEnabled = true;
		this->container->contCont1BtnLeftArrowCase->mouseEnabled = true;
		this->container->contCont1BtnRightArrowCase->mouseEnabled = true;
		if (this->page == 1)
		{
			this->container->contCont1BtnOk->setVisible(false);
			this->container->contCont1BtnLeft->setVisible(false);
			this->container->contCont1BtnRight->setVisible(true);
		}
		else
		{
			this->container->contCont1BtnOk->setVisible(true);
			this->container->contCont1BtnLeft->setVisible(true);
			this->container->contCont1BtnRight->setVisible(false);
		}
		return;
	}// end function


	void Training_8::close()
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

	void Training_8::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			this->world->manageListeners("on");
			if (this->world->getSphere || this->world->cast)
			{
				this->world->manageMouse("hide");
			}
			this->world->removeChild(this);
			this->world->menuObject = NULL;
		}
		return;
	}// end function

	//public function reInit(event:Event) : void
	//{
	//    this->removeEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
	//    this->removeEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
	//    this->removeEventListener(MouseEvent->MOUSE_MOVE, this->mouseMoveHandler);
	//    this->removeEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
	//    this->removeEventListener(MouseEvent->MOUSE_UP, this->mouseUpHandler);
	//    return;
	//}// end function

}

