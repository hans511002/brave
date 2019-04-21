#include "Training_4.h"   
#include "engine/World.h"   

using namespace engine;

namespace training
{
	Training_4_mc::Training_4_mc() :MovieClip("training", "Training_4_mc", "Training_4_mc")
	{

	}
	Training_4::Training_4()
	{
		this->init();
		//this->addEventListener(Event->ADDED_TO_STAGE, this->init);
		return;
	}// end function 

	bool Training_4::init()
	{
		//this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		this->enableFrameHandler();
		this->world = Main::mainClass->worldClass;
		this->container = new Training_4_mc();
		this->container->stop();
		this->container->setPosition(Vec2(691, 160));
		this->addChild(this->container);
		this->mouseChildren = false;
		this->mouseEnabled = false;
		return true;
	}

	void Training_4::enterFrameHandler(float dt)
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
			if (this->world->wavesClass->nowWave > 0)
			{
				this->closeFlag = true;
			}
		}
		return;
	}// end function

	void Training_4::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			this->world->removeChild(this);
			this->world->trainingClass = NULL;
		}
		return;
	}// end function
}
