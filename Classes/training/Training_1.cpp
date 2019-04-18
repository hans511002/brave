#include "Training_1.h"   
#include "engine/World.h"   
#include "MainClass.h"   
#include "screens/LevelsMenu.h"

using namespace engine; 
namespace training
{
	Training_1::Training_1()
	{
		//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
		return;
	}// end function

	bool Training_1::init()
	{
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
		//this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
		//this->container = new Training_1_mc();
		//this->container.stop();
		//this->container.x = Main.mainClass.levelsMenuClass.container.level1.x + this->container.width / 2 + 10;
		//this->container.y = Main.mainClass.levelsMenuClass.container.level1.y - this->container.height / 2 - 30;
		//this->addChild(this->container);
		//this->mouseChildren = false;
		//this->mouseEnabled = false;
		return;
	}// end function

	void Training_1::enterFrameHandler(float dt)
	{
		//if (this->frameCounter < 30)
		//{
		//    (this->frameCounter + 1);
		//}
		//else
		//{
		//    this->frameCounter = 1;
		//}
		//if (this->openFlag)
		//{
		//    if (this->container.currentFrame < 12)
		//    {
		//        this->container.gotoAndStop((this->container.currentFrame + 1));
		//    }
		//    else
		//    {
		//        this->openFlag = false;
		//    }
		//}
		//else if (this->closeFlag)
		//{
		//    if (this->container.currentFrame < 23)
		//    {
		//        this->container.gotoAndStop(23);
		//    }
		//    if (this->container.currentFrame < this->container.totalFrames)
		//    {
		//        this->container.gotoAndStop((this->container.currentFrame + 1));
		//    }
		//    else
		//    {
		//        this->closeFlag = false;
		//        Main.mainClass.levelsMenuClass.openLevel.visible = true;
		//        this->kill();
		//    }
		//}
		//else
		//{
		//    if (this->container.currentFrame < 23)
		//    {
		//        this->container.gotoAndStop((this->container.currentFrame + 1));
		//    }
		//    else
		//    {
		//        this->container.gotoAndStop(13);
		//    }
		//    if (Main.mainClass.levelsMenuClass.openLevel)
		//    {
		//        this->closeFlag = true;
		//    }
		//}
		return;
	}// end function

	void  Training_1::kill()  
	{	if (!this->dead)
		{
			this->dead = true;
			Main::mainClass->levelsMenuClass->removeChild(this);
			Main::mainClass->levelsMenuClass->training_1 = NULL;
		}
	}// end function

 


}

