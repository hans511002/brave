#include "Training_91.h"   
#include "engine/World.h"   
#include "screens/LevelsMenu.h"   

using namespace engine;

namespace training
{
	Training_91_mc::Training_91_mc() :MovieClip("training", "Training_91_mc", "Training_91_mc")
	{
	};

	Training_91::Training_91(int param1)
	{
		//this->addEventListener(Event->ADDED_TO_STAGE, this->init);
		this->myLevel = param1;
		this->init();
		return;
	}// end function

	bool Training_91::init()
	{
		//this->removeEventListener(Event->ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event->REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event->ENTER_FRAME, this->enterFrameHandler);
		this->enableFrameHandler();
		this->container = new Training_91_mc();
		this->container->stop();
		Vec2 pos;
		if (this->myLevel >= 1 && this->myLevel<=15)
			pos = Main::mainClass->levelsMenuClass->listOfLevels[this->myLevel-1]->convertToWorldSpace(Vec2(0,0))  ;
		pos = Main::mainClass->levelsMenuClass->convertToNodeSpaceAR(pos+Vec2(-7,15)); 
		this->addChild(this->container);
		this->mouseChildren = false;
		this->mouseEnabled = false;
		return true;
	}// end function

	void Training_91::enterFrameHandler(float dt)
	{
		if (this->frameCounter < 30)
		{
			(this->frameCounter + 1);
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
				Main::mainClass->levelsMenuClass->openLevel->setVisible(true);
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
			if (Main::mainClass->levelsMenuClass->openLevel)
			{
				this->closeFlag = true;
			}
		}
		return;
	}// end function

	void Training_91::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			Main::mainClass->levelsMenuClass->removeChild(this);
			Main::mainClass->levelsMenuClass->training_9 = NULL;
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
