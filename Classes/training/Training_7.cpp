#include "engine/World.h"
#include "Training_7.h"   
using namespace engine;

namespace training
{
	Training_7_mc::Training_7_mc() :MovieClip("training", "Training_7_mc", "Training_7_mc")
	{
	};

	Training_7::Training_7(const string & param1)
	{
		//this->addEventListener(Event->ADDED_TO_STAGE, this->init);
		this->type = param1;
		this->init();
	}// end function

	bool Training_7::init()
	{
		//this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		this->enableFrameHandler();
		this->world = Main::mainClass->worldClass;
		this->container = new Training_7_mc();
		this->container->stop();
		Vec2 pos;
		if (this->type == "golem")
		{
			pos = this->world->worldInterface->container->butCastGolemCastGolemCase->convertToWorldSpace(Vec2(0, 0));
			pos = this->world->worldInterface->convertToNodeSpaceAR(pos);
		}
		else if (this->type == "iceman")
		{
			pos = this->world->worldInterface->container->butCastIcemanCastIcemanCase->convertToWorldSpace(Vec2(0, 0));
			pos = this->world->worldInterface->convertToNodeSpaceAR(pos);
		}
		else if (this->type == "air")
		{
			pos = this->world->worldInterface->container->butCastAirCastAirCase->convertToWorldSpace(Vec2(0, 0));
			pos = this->world->worldInterface->convertToNodeSpaceAR(pos);
		}
		this->addChild(this->container);
		this->setPosition(pos + Vec2(80, 80));
		this->mouseChildren = false;
		this->mouseEnabled = false;
		return true;
	}// end function

	void Training_7::enterFrameHandler(float dt)
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
			if (this->world->cast)
			{
				this->closeFlag = true;
			}
		}
		return;
	}// end function

	void Training_7::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			this->world->worldInterface->removeChild(this);
			this->world->trainingClass = NULL;
		}
		return;
	}// end function

	//public function reInit(event:Event) : void
	//{
	//    this->removeEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
	//    this->removeEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
	//    return;
	//}// end function
}

