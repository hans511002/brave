#include "Training_12.h"   
#include "engine/world.h"   
#include "engine/towers/TowerMenu.h"   

using namespace engine;

namespace training
{
	Training_12_mc::Training_12_mc() :MovieClip("training", "Training_12_mc", "Training_12_mc")
	{

	};
	Training_12::Training_12()
	{
		this->world = Main::mainClass->worldClass;
		//this->addEventListener(Event->ADDED_TO_STAGE, this->init);
		this->init();
		return;
	}// end function

	bool Training_12::init()
	{
		//this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		//this->world->addEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
		this->enableFrameHandler();
		this->container = new Training_12_mc();
		this->container->stop();
		this->addChild(this->container);
		this->myTowerMenu = this->world->towerMenu;
		this->setPosition(50,50);
		this->mouseChildren = false;
		this->mouseEnabled = false;
		return true;
	}// end function

	void Training_12::enterFrameHandler(float dt)
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
			if (this->container->currentFrame < 12)
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
			if (this->container->currentFrame < 23)
			{
				this->container->gotoAndStop(23);
			}
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
		else
		{
			if (this->container->currentFrame < 23)
			{
				this->container->gotoAndStop((this->container->currentFrame + 1));
			}
			else
			{
				this->container->gotoAndStop(13);
			}
			if (!this->world->towerMenu)
			{
				Main::mainClass->saveBoxClass->setValue("firstClickKeepAll", true);
				this->closeFlag = true;
			}
		}
		return;
	}// end function

	void Training_12::mouseDownHandler(cocos2d::EventMouse * e)
	{
		if (e->getCurrentTarget()->getName() == "btnGetAllCase")
		{
			Main::mainClass->saveBoxClass->setValue("firstClickKeepAll", true);
			this->closeFlag = true;
		}
		return;
	}// end function

	void Training_12::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			this->myTowerMenu->removeChild(this);
			this->myTowerMenu->training_12 = NULL;
		}
		return;
	}// end function

	//public function reInit(event:Event) : void
	//{
	//    this->removeEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
	//    this->removeEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
	//    this->world->removeEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
	//    return;
	//}// end function

}


