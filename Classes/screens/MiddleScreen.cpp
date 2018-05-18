﻿#include "BaseNode.h"

#include "MiddleScreen.h"

#include "MainClass.h"

namespace screens
{
    
    Screen:Screen():frameCounter(0),openFlag(true) ,fireFrame(0),closeFlag(false),dead(false) 
    {
        
    };
    
    MiddleScreen_mc::MiddleScreen_mc()
    {
        init();
    }// end function
    bool  MiddleScreen_mc::init()
    {
        BaseNode::init();
        leftUp = new ImageMovieClip("screen/MiddleScreen_mc/", "leftUp", 2);
        leftDown = new ImageMovieClip("screen/MiddleScreen_mc/", "leftDown", 2);
        rightUp = new ImageMovieClip("screen/MiddleScreen_mc/", "rightUp", 2);
        rightDown = new ImageMovieClip("screen/MiddleScreen_mc/", "rightDown", 2);

        leftUp->setPosition(cocos2d::Point(-410, Main::SCREEN_HEIGHT + 310));
        leftDown->setPosition(cocos2d::Point(-410, -310));
        rightUp->setPosition(cocos2d::Point(Main::SCREEN_WIDTH + 410, Main::SCREEN_HEIGHT + 310));
        rightDown->setPosition(cocos2d::Point(Main::SCREEN_WIDTH + 410, -310));
        this->autorelease();
    };

    void MiddleScreen_mc::stop(){
        leftDown->stop();
        leftUp->stop();
        rightDown->stop();
        rightUp->stop();
    };
	MiddleScreen::MiddleScreen(string param1) :frameCounter(0), gogoCounter(0), middleRound(NULL), container(NULL)
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        this->openScreenName = param1;
		init();
    }// end function

    bool MiddleScreen::init()
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        if (Main::mainClass->container)
        {
            //Main::mainClass->container.manageListeners("off");
        }
        //this->stage.frameRate = 60;
        this->container = new MiddleScreen_mc();
        this->container->stop();
        this->container->leftUp->stop();
        this->container->rightUp->stop();
        this->container->leftDown->stop();
        this->container->rightDown->stop();
        this->addChild(this->container);
        if (this->openScreenName == "World" || Main::mainClass->worldClass)
        {
            //Sounds.instance.stopAll();
        }
        //Sounds.instance.playSoundWithVol("snd_middleScreen", 0.95);
        return true;
    }// end function

	void MiddleScreen::onEnter()
	{
		this->schedule(schedule_selector(MiddleScreen::enterFrameHandler), 0.0f);
	}
	void MiddleScreen::enterFrameHandler(float dt)
	{
        this->frameCounter++;
        if (this->frameCounter <= 15)
        {
			int offsetX = 44 - 2 * this->gogoCounter;
			int offsetY = 34 - 2 * this->gogoCounter;
			this->gogoCounter++; 
			if (this->gogoCounter == 11)
            {
				offsetX = 20;
				offsetY = 20;
			}
			else if(this->gogoCounter == 12)
			{
				offsetX = 15;
				offsetY = 15;
			}
			else if(this->gogoCounter == 13)
			{
				offsetX = 10;
				offsetY = 10;
			}
			else if(this->gogoCounter == 14)
			{
				offsetX = 3;
				offsetY = 3;
			}
			else if(this->gogoCounter == 14)
			{
				offsetX = 2;
				offsetY = 2;
			}
			this->container->leftUp->setPositionX(this->container->leftUp->getPositionX() + offsetX);
			this->container->leftUp->setPositionY(this->container->leftUp->getPositionY() + offsetY);
			this->container->leftDown->setPositionX(this->container->leftDown->getPositionX() + offsetX);
			this->container->leftDown->setPositionY(this->container->leftDown->getPositionY() - offsetY);
			this->container->rightUp->setPositionX(this->container->rightUp->getPositionX() - offsetX);
			this->container->rightUp->setPositionY(this->container->rightUp->getPositionY() + offsetY);
			this->container->rightDown->setPositionX(this->container->rightDown->getPositionX() - offsetX);
			this->container->rightDown->setPositionY(this->container->rightDown->getPositionY() - offsetY);
        }
        else if (this->frameCounter > 15 && this->frameCounter < 23)
        {
            if (!this->middleRound)
            {
                this->middleRound = new MovieClip("screen/","MiddleScreenCentr_mc");
                this->middleRound->stop();
				this->middleRound->setPositionX(Main::SCREEN_WIDTH_HALF);
				this->middleRound->setPositionY(Main::SCREEN_HEIGHT_HALF); 
                this->addChild(this->middleRound);
                Main::mainClass->removeAllScreens();
                Main::mainClass->addNewScreen(this->openScreenName);
                //Main::mainClass->container->manageListeners("off");
            }
			if(this->middleRound->currentFrame < this->middleRound->totalFrames)
            {
				this->middleRound->gotoAndStop((this->middleRound->currentFrame + 1));
				this->middleRound->setRotation(this->middleRound->getRotation() + 15);
            }
            else
            {
                this->container->leftUp->gotoAndStop(2);
				this->container->leftDown->gotoAndStop(2);
				this->container->rightUp->gotoAndStop(2);
				this->container->rightDown->gotoAndStop(2);
                this->removeChild(this->middleRound);
                this->middleRound = NULL;
                this->gogoCounter = 0;
            }
        }
        else
        {
             this->gogoCounter ++;
			 int offsetX = 0;
			 int offsetY = 0;
			 if(this->gogoCounter == 1)
			 {
				 offsetX = offsetY = 2;
			 }
			 else  if(this->gogoCounter == 2)
			 {
				 offsetX = offsetY = 3;
			 }
			 else  if(this->gogoCounter == 3)
			 {
				 offsetX = offsetY = 10;
			 }
			 else  if(this->gogoCounter == 4)
			 {
				 offsetX = offsetY = 15;
			 }
			 else  if(this->gogoCounter == 5)
			 {
				 offsetX = offsetY = 20;
			 }
			 else  if(this->gogoCounter == 6)
			 {
				 offsetX = 26;
					 offsetY = 20;
			 }
			 else  if(this->gogoCounter == 7)
			 {
				 offsetX = 28;
				 offsetY = 20;
			 }
			 else  if(this->gogoCounter == 8)
			 {
				 offsetX = 30;
				 offsetY = 20;
			 }
			 else  if(this->gogoCounter == 9)
			 {
				 offsetX = 32;
				 offsetY = 20;
			 }
			 else  if(this->gogoCounter == 10)
			 {
				 offsetX = 34;
				 offsetY = 20;
			 }
			 else  if(this->gogoCounter == 11)
			 {
				 offsetX = 36;
				 offsetY = 20;
			 }
			 else  if(this->gogoCounter == 12)
			 {
				 offsetX = 38;
				 offsetY = 20;
			 }
			 else  if(this->gogoCounter == 13)
			 {
				 offsetX = 40;
				 offsetY = 30;
			 }
			 else  if(this->gogoCounter == 14)
			 {
				 offsetX = 42;
				 offsetY = 30;
			 }
			 else  if(this->gogoCounter == 15)
			 {
				 offsetX = 44;
				 offsetY = 30;
			 }
			 this->container->leftUp->setPositionX(this->container->leftUp->getPositionX() - offsetX);
			 this->container->leftUp->setPositionY(this->container->leftUp->getPositionY() - offsetY);
			 this->container->leftDown->setPositionX(this->container->leftDown->getPositionX() - offsetX);
			 this->container->leftDown->setPositionY(this->container->leftDown->getPositionY() + offsetY);
			 this->container->rightUp->setPositionX(this->container->rightUp->getPositionX() + offsetX);
			 this->container->rightUp->setPositionY(this->container->rightUp->getPositionY() - offsetY);
			 this->container->rightDown->setPositionX(this->container->rightDown->getPositionX() + offsetX);
			 this->container->rightDown->setPositionY(this->container->rightDown->getPositionY() + offsetY);
			        
            if (this->frameCounter == 38)
            {
				this->unschedule(schedule_selector(MiddleScreen::enterFrameHandler));
                Main::mainClass->removeChild(Main::mainClass->middleScreenClass);
                Main::mainClass->middleScreenClass = NULL;
                //Main::mainClass->removeChild(Main::mainClass->bmp);
                //Main::mainClass->bmp = NULL;
                if (Main::mainClass->container)
                {
					Main::mainClass->container->setVisible( true);
                    //Main::mainClass->container->manageListeners("on");
                }
            }
        }
        return;
    }// end function

    //public function reInit(event:Event) : void
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    if (this->stage.quality != "high")
    //    {
    //        this->stage.quality = "high";
    //    }
    //    if (this->stage.frameRate != 30)
    //    {
    //        this->stage.frameRate = 30;
    //    }
    //    return;
    //}// end function
}
