#include "Training_3.h"   
#include "Training_4.h"   
#include "engine/World.h"   
#include "engine/level/Level.h"   
#include "engine/towers/BuildTowerMenu.h"   

using namespace engine;

namespace training
{
	Training_3_mc::Training_3_mc() :MovieClip("training", "Training_3_mc", "Training_3_mc")
	{
		bg = NULL;
		bgSlot = this->getArmature()->getSlot("bg");
	};
	void Training_3_mc::gotoAndStop(int cf, const string &  aniName) {
		bgSlot->offset.y = Main::LEVEL_MAP_HEIGHT;
		if (cf >  43) {
			this->setPosition(0, Main::SCREEN_HEIGHT+Main::SCREEN_HEIGHT_OUT_TOP);
		}
		else {
			this->setPosition(0, Main::LEVEL_MAP_HEIGHT);
		}
		Sprite *s = (Sprite *)bgSlot->getDisplay();
		this->printNodePos(s);
		MovieClip::gotoAndStop(cf, aniName);
		s = (Sprite *)bgSlot->getDisplay();
		this->printNodePos(s);
		if (this->currentFrame) {
			char file[256];
			sprintf(file, "training/Training_3_mc/%i.png", this->currentFrame - 1);
			std::string fullpath = FileUtils::getInstance()->fullPathForFilename(file);
			if (fullpath.size() == 0)
				return;
			Texture2D *texture = _director->getTextureCache()->addImage(file);
			if (texture != NULL) {
				bg = Sprite::createWithTexture(texture);
				bgSlot->setDisplay(bg, dragonBones::DisplayType::Image);
			}
		}
	}

	Training_3::Training_3() :phase(0)
	{
		this->init();
		//this->addEventListener(Event->ADDED_TO_STAGE, this->init);
		return;
	}// end function 

	bool Training_3::init()
	{
		//this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		//Main::mainClass->worldClass->addEventListener(MouseEvent->MOUSE_MOVE, this->mouseMoveHandler);
		//Main::mainClass->worldClass->addEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
		//Main::mainClass->worldClass->addEventListener(MouseEvent->MOUSE_UP, this->mouseUpHandler);

		this->world = Main::mainClass->worldClass;
		this->manageListeners("on");
		//this->world->removeEventListener(MouseEvent->MOUSE_MOVE, this->world->mouseMoveHandler);
		//this->world->removeEventListener(MouseEvent->MOUSE_DOWN, this->world->mouseDownHandler);
		//this->world->removeEventListener(MouseEvent->MOUSE_UP, this->world->mouseUpHandler);
		this->i = 0;
		while (this->i < this->world->listOfPlaces.size())
		{
			if (this->world->listOfPlaces[this->i]->getName() != "place2")
			{
				this->world->listOfPlaces[this->i]->mouseChildren = false;
				this->world->listOfPlaces[this->i]->mouseEnabled = false;
			}
			this->i++;
		}
		this->world->worldInterface->container->fireSphere->mouseChildren = false;
		this->world->worldInterface->container->fireSphere->mouseEnabled = false;
		this->world->worldInterface->container->bookBookCase->mouseEnabled = false;
		this->world->worldInterface->container->pausePauseCase->mouseEnabled = false;
		this->world->worldInterface->container->startWavesStartWavesCase->mouseEnabled = false;
		this->world->pointer1->pointerCase->mouseEnabled = false;
		this->container = new Training_3_mc();
		this->container->stop();
		this->addChild(this->container);
		this->mouseChildren = false;
		this->mouseEnabled = false;
		return true;
	}// end function

	void Training_3::enterFrameHandler(float dt)
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
			if (this->container->currentFrame < 23)
			{
				this->container->gotoAndStop((this->container->currentFrame + 1));
			}
			else
			{
				this->openFlag = false;
			}
		}
		else if (this->closeFlag)
		{
			if (this->container->currentFrame < this->container->totalFrames)
			{
				this->container->gotoAndStop((this->container->currentFrame + 1));
			}
			else
			{
				this->closeFlag = false;
				this->kill();
			}
		}
		else if (this->phase == 0)
		{
			if (this->container->currentFrame < 43)
			{
				this->container->gotoAndStop((this->container->currentFrame + 1));
			}
			else
			{
				this->container->gotoAndStop(24);
			}
			if (this->world->towerMenu)
			{
				this->phase = 1;
				this->container->gotoAndStop(44);
			}
		}
		else if (this->phase == 1)
		{
			if (this->container->currentFrame < 94)
			{
				this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 56)
				{
					this->world->worldInterface->container->fireSphere->mouseChildren = true;
					this->world->worldInterface->container->fireSphere->mouseEnabled = true;
					this->world->worldInterface->autoguidersButtons();
				}
			}
			else
			{
				this->container->gotoAndStop(75);
			}
			if (this->world->listOfMoveSpheres.size() > 0)
			{
				this->closeFlag = true;
				this->container->gotoAndStop(95);
			}
		}
		return;
	}// end function
	bool Training_3::preCheckEventTarget(std::MouseEvent * e, EventMouse::MouseEventType _mouseEventType) {
		if (std::hitTest(this->world->listOfPlaces[1]->placeForBuildCase, e, true, false)) {
			//e->setCurrentTarget(this->world->listOfPlaces[1]->placeForBuildCase);
			e->hitTest(this->world->listOfPlaces[1]->placeForBuildCase);
			return false;
		}
		else if (!this->world->listOfTowers.empty()) {
			if (this->world->listOfTowers[0]->container->towerCase->hitTest(e)) {
				e->hitTest(this->world->listOfTowers[0]->container->towerCase);
				return false;
			}
			else if (this->world->worldInterface->container->fireSphereSphereCase->hitTest(e)) {
				e->hitTest(this->world->worldInterface->container->fireSphereSphereCase);
				return false;
			}
		}
		e->hitTest(this->world, true);
		return false;
	};
	void Training_3::mouseMoveHandler(cocos2d::EventMouse * e)
	{
		if (Main::mouseX == e->getCursorX() && Main::mouseY == e->getCursorY())
			return;
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
			if (this->world->buildTowerMenu)
			{
				this->world->buildTowerMenu->mouseMoveHandler(event);
			}
			else if (targetName == "placeForBuildCase")
			{
				this->world->mouseMoveHandler(event);
			}
			else if (targetName == "towerCase")
			{
				this->world->mouseMoveHandler(event);
			}
			else if (targetName == "sphereCase" && this->world->towerMenu)
			{
				this->world->mouseMoveHandler(event);
			}
			else
			{
				//this->tempObject = new Object();
				//this->tempObject->target = new Object();
				//this->tempObject->target.name = "无";
				//this->world->mouseMoveHandler(this->tempObject);
			}
		}
		return;
	}// end function

	void Training_3::mouseDownHandler(cocos2d::EventMouse * e)
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
			if (this->world->buildTowerMenu)
			{
				this->world->buildTowerMenu->mouseDownHandler(event);
			}
			else if (targetName == "placeCase")
			{
				this->world->mouseDownHandler(event);
			}
			else if (targetName == "towerCase")
			{
				this->world->mouseDownHandler(event);
			}
			else if (targetName == "sphereCase" && this->world->towerMenu)
			{
				this->world->mouseDownHandler(event);
			}
		}
	}// end function

	void Training_3::mouseUpHandler(cocos2d::EventMouse * e)
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
			if (this->world->buildTowerMenu)
			{
				this->world->buildTowerMenu->mouseUpHandler(event);
			}
			else if (targetName == "placeCase")
			{
				this->world->mouseUpHandler(event);
			}
			else if (targetName == "towerCase")
			{
				this->world->mouseUpHandler(event);
			}
			else if (targetName == "sphereCase" && this->world->towerMenu)
			{
				this->world->mouseUpHandler(event);
			}
		}
	}// end function

	void Training_3::close()
	{
		return;
	}// end function

	void Training_3::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			//this->world->addEventListener(MouseEvent->MOUSE_MOVE, this->world->mouseMoveHandler);
			//this->world->addEventListener(MouseEvent->MOUSE_DOWN, this->world->mouseDownHandler);
			//this->world->addEventListener(MouseEvent->MOUSE_UP, this->world->mouseUpHandler);
			this->world->manageListeners("on");
			this->i = 0;
			while (this->i < this->world->listOfPlaces.size())
			{
				this->world->listOfPlaces[this->i]->mouseChildren = true;
				this->world->listOfPlaces[this->i]->mouseEnabled = true;
				this->i++;
			}
			this->world->worldInterface->container->bookBookCase->mouseEnabled = true;
			this->world->worldInterface->container->pausePauseCase->mouseEnabled = true;
			this->world->worldInterface->container->startWavesStartWavesCase->mouseEnabled = true;
			this->world->pointer1->pointerCase->mouseEnabled = true;
			this->world->removeChild(this);
			this->world->menuObject = NULL;
			this->world->trainingClass = new Training_4();
			this->world->addChild(this->world->trainingClass,99);
		}
		return;
	}// end function

	//void reInit(event:Event) : void
	//{
	//    this->removeEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
	//    this->removeEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
	//    this->world->removeEventListener(MouseEvent->MOUSE_MOVE, this->mouseMoveHandler);
	//    this->world->removeEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
	//    this->world->removeEventListener(MouseEvent->MOUSE_UP, this->mouseUpHandler);
	//    return;
	//}// end function

}
