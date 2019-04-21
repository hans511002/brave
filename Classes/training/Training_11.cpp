#include "Training_11.h"   
#include "engine/world.h"   

using namespace engine;

namespace training
{
	Training_11_mc::Training_11_mc() :MovieClip("training", "Training_11_mc", "Training_11_mc")
	{

	};
	Training_11_01_mc::Training_11_01_mc() :MovieClip("training", "Training_11_01_mc", "Training_11_01_mc")
	{

	};

	Training_11::Training_11(int param1)
	{
		this->world = Main::mainClass->worldClass;
		//this->addEventListener(Event->ADDED_TO_STAGE, this->init);
		this->type = param1;
		this->init();
		return;
	}// end function

	bool Training_11::init()
	{
		//this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		this->enableFrameHandler();
		//this->world->worldInterface->addEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
		if (this->type < 5)
		{
			this->container = new Training_11_mc();
		}
		else
		{
			this->container = new Training_11_01_mc();
		}
		this->container->stop();
		this->addChild(this->container);
		Vec2 pos;
		if (this->type == 1)
		{
			pos = this->world->worldInterface->container->fireSphereSphereCase->convertToWorldSpace(Vec2(0, 0));
			pos = this->world->worldInterface->convertToNodeSpaceAR(pos + Vec2(20, 10));
		}
		else if (this->type == 2)
		{
			pos = this->world->worldInterface->container->iceSphereSphereCase->convertToWorldSpace(Vec2(0, 0));
			pos = this->world->worldInterface->convertToNodeSpaceAR(pos + Vec2(20, 10));
		}
		else if (this->type == 3)
		{
			pos = this->world->worldInterface->container->stoneSphereSphereCase->convertToWorldSpace(Vec2(0, 0));
			pos = this->world->worldInterface->convertToNodeSpaceAR(pos + Vec2(20, 10));
		}
		else if (this->type == 4)
		{
			pos = this->world->worldInterface->container->levinSphereSphereCase->convertToWorldSpace(Vec2(0, 0));
			pos = this->world->worldInterface->convertToNodeSpaceAR(pos + Vec2(20, 10));
		}
		else if (this->type == 5)
		{
			pos = this->world->worldInterface->container->getAllSphereCase->convertToWorldSpace(Vec2(0, 0));
			pos = this->world->worldInterface->convertToNodeSpaceAR(pos + Vec2(20, 10));
		}
		this->container->setPosition(pos);
		this->mouseChildren = false;
		this->mouseEnabled = false;
		return true;
	}// end function

	void Training_11::enterFrameHandler(float dt)
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
		else if (this->container->currentFrame < 23)
		{
			this->container->gotoAndStop((this->container->currentFrame + 1));
		}
		else
		{
			this->container->gotoAndStop(13);
		}
		return;
	}// end function

	void Training_11::mouseDownHandler(cocos2d::EventMouse * e)
	{
		string parName = e->getCurrentTarget()->getParent()->getParent()->getName();
		if (this->type == 1)
		{
			if (parName == "fireSphere")
			{
				this->closeFlag = true;
			}
		}
		else if (this->type == 2)
		{
			if (parName == "iceSphere")
			{
				this->closeFlag = true;
			}
		}
		else if (this->type == 3)
		{
			if (parName == "stoneSphere")
			{
				this->closeFlag = true;
			}
		}
		else if (this->type == 4)
		{
			if (parName == "levinSphere")
			{
				this->closeFlag = true;
			}
		}
		else if (this->type == 5)
		{
			if (parName == "getAll")
			{
				this->closeFlag = true;
			}
		}
		return;
	}// end function

	void Training_11::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			int i = this->world->trainings.size()-1;
			while (i >= 0) {
				if (this->world->trainings[i] == this) {
					this->world->trainings.remove(i);
					break;
				}
				i--;
			}
			this->world->worldInterface->removeChild(this);
		}
		return;
	}// end function

	//public function reInit(event:Event) : void
	//{
	//    this->removeEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
	//    this->removeEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
	//    this->world->worldInterface->removeEventListener(MouseEvent->MOUSE_DOWN, this->mouseDownHandler);
	//    return;
	//}// end function

}

