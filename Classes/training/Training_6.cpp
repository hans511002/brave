#include "Training_6.h"   
#include "engine/World.h"   
#include "engine/level/Level.h"   

using namespace engine;

namespace training
{
	Training_6_mc::Training_6_mc() :MovieClip("training", "Training_6_mc", "Training_6_mc")
	{

	};
	Training_6::Training_6()
	{
		//this->addEventListener(Event->ADDED_TO_STAGE, this->init);
		this->init();
		return;
	}// end function 


	bool Training_6::init()
	{
		//this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		this->world = Main::mainClass->worldClass;
		this->enableFrameHandler();
		this->container = new Training_6_mc();
		this->container->stop();
		this->container->setPosition(Vec2( this->world->pointer1->getPosition()+Vec2(5,10)));
		this->addChild(this->container);
		this->mouseChildren = false;
		this->mouseEnabled = false;
		return true;
	}// end function

	void Training_6::enterFrameHandler(float dt)
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
			if (this->world->wavesClass->nowWave > 1)
			{
				this->closeFlag = true;
			}
		}
		return;
	}// end function

	void Training_6::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			this->world->removeChild(this);
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

