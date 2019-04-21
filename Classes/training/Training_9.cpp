#include "Training_9.h"   
#include "engine/world.h"   
//#include "MainClass.h"   
//#include "engine/level/Level.h"   
#include "screens/LevelsMenu.h"   

using namespace engine;

namespace training
{
	Training_9_mc::Training_9_mc() :MovieClip("training", "Training_9_mc", "Training_9_mc")
	{
	};
	Training_9::Training_9()
	{
		//this->addEventListener(Event->ADDED_TO_STAGE, this->init);
		this->init();
		return;
	}// end function

	bool Training_9::init()
	{
		//this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		this->enableFrameHandler();
		this->container = new Training_9_mc();
		this->container->stop();
		Vec2 pos=Main::mainClass->levelsMenuClass->container->upgrades->convertToWorldSpace(Vec2(0,0));
		pos = Main::mainClass->levelsMenuClass->convertToNodeSpaceAR(pos);
		this->container->setPosition(pos+Vec2(30,40));
		this->addChild(this->container);
		this->mouseChildren = false;
		this->mouseEnabled = false;
		return true;
	}// end function

	void Training_9::enterFrameHandler(float dt)
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
			if (Main::mainClass->levelsMenuClass->upgradesClass)
			{
				this->closeFlag = true;
			}
		}
		return;
	}// end function

	void Training_9::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			Main::mainClass->levelsMenuClass->removeChild(this);
			Main::mainClass->levelsMenuClass->training_1 = NULL;
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
