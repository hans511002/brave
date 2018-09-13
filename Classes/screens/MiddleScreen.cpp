#include "BaseHeaders.h"

#include "MiddleScreen.h"

#include "MainClass.h"
#include "engine/World.h"
#include "engine/WorldInterface.h"

namespace screens
{
    
    Screen::Screen() :frameCounter(0), openFlag(true), closeFlag(false), dead(false), autoguidesObject(NULL)
    {
        
    };
    
    MiddleScreen_mc::MiddleScreen_mc():MovieClip("screen/","MiddleScreen_mc","MiddleScreen_mc")
    {
		SET_NODETYPENAME();
		leftDown = this->createMovieClipSub("leftDown");
        leftUp= this->createMovieClipSub("leftUp");
        rightDown= this->createMovieClipSub("rightDown");
        rightUp= this->createMovieClipSub("rightUp");
		this->setAutoRemoveData(true);
    }// end function
    
    MiddleScreenCentr_mc::MiddleScreenCentr_mc():MovieClip("screen/","MiddleScreenCentr_mc","MiddleScreenCentr_mc")
    {
		SET_NODETYPENAME();
	}
    
    void MiddleScreen_mc::stop()
	{
		MovieClip::stop();
        leftDown->stop();
        leftUp->stop();
        rightDown->stop();
        rightUp->stop();
    };
    MiddleScreen::MiddleScreen(const string &  param1) :frameCounter(0), gogoCounter(0), middleRound(NULL), container(NULL)
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        this->openScreenName = param1;
		init();
    }// end function

    bool MiddleScreen::init()
    {
        BaseNode::init();
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        if (Main::mainClass->container)
        {
            //Main::mainClass->container.manageListeners("off");
        }
        //this->stage.frameRate = 60;
        this->container = new MiddleScreen_mc();
        this->addChild(this->container);
		this->container->setPosition(Vec2(-Main::SCREEN_WIDTH_OUT_LEFT, -Main::SCREEN_HEIGHT_OUT_DOWN));

		this->container->stop();
        this->container->leftUp->stop();
        this->container->rightUp->stop();
        this->container->leftDown->stop();
        this->container->rightDown->stop();
        Vec2 lupos=this->container->leftUp->convertToWorldSpace(this->container->leftUp->getPosition());
        lupos=this->container->convertToNodeSpaceAR(lupos);
		this->container->leftUp->setPosition(lupos);
		this->container->leftDown->setPosition(this->container->convertToNodeSpaceAR(this->container->leftDown->convertToWorldSpace(this->container->leftDown->getPosition())));
		this->container->rightUp->setPosition(this->container->convertToNodeSpaceAR(this->container->rightUp->convertToWorldSpace(this->container->rightUp->getPosition())));
		this->container->rightDown->setPosition(this->container->convertToNodeSpaceAR(this->container->rightDown->convertToWorldSpace(this->container->rightDown->getPosition())));

		//this->container->leftUp->setPosition(0, Main::SCREEN_HEIGHT);
		//this->container->leftDown->setPosition(0, 0);
		//this->container->rightUp->setPosition(Main::LEVEL_MAP_WIDTH, Main::LEVEL_MAP_HEIGHT);
		//this->container->rightDown->setPosition(Main::SCREEN_WIDTH, 0);
        this->container->setScale(1.0f);
		//this->container->setPosition(400, 300);
        if (this->openScreenName == "World" || Main::mainClass->worldClass)
        {
            //AudioUtil::stopAll();
        }
        AudioUtil::playSoundWithVol("Snd_middleScreen.mp3", 0.95f);
        return true;
    }// end function

	void MiddleScreen::onEnter()
	{
        BaseNode::onEnter();
        enableFrameHandler(true);
        //this->schedule(static_cast<cocos2d::SEL_SCHEDULE>(&MiddleScreen::enterFrameHandler));
		//this->schedule(schedule_selector(MiddleScreen::enterFrameHandler), 1.0f);
	}
	void MiddleScreen::onExit() {
		
		BaseNode::onExit();
	};

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
			float x = this->container->leftUp->getPositionX() + offsetX;
			float y = this->container->leftUp->getPositionY() - offsetY;
			if (x > Main::SCREEN_WIDTH_HALF + Main::SCREEN_WIDTH_OUT_LEFT)x = Main::SCREEN_WIDTH_HALF + Main::SCREEN_WIDTH_OUT_LEFT;
			if (y < Main::SCREEN_HEIGHT_HALF + Main::SCREEN_HEIGHT_OUT_TOP)y = Main::SCREEN_HEIGHT_HALF + Main::SCREEN_HEIGHT_OUT_TOP;
			this->container->leftUp->setPosition(x, y);

			x = this->container->leftDown->getPositionX() + offsetX;
			y = this->container->leftDown->getPositionY() + offsetY;
			if (x > Main::SCREEN_WIDTH_HALF + Main::SCREEN_WIDTH_OUT_LEFT)x = Main::SCREEN_WIDTH_HALF + Main::SCREEN_WIDTH_OUT_LEFT;
			if (y > Main::SCREEN_HEIGHT_HALF + Main::SCREEN_HEIGHT_OUT_DOWN)y = Main::SCREEN_HEIGHT_HALF + Main::SCREEN_HEIGHT_OUT_DOWN;
			this->container->leftDown->setPosition(x, y);
			 
			x = this->container->rightUp->getPositionX() - offsetX;
			y = this->container->rightUp->getPositionY() - offsetY;
			if (x < Main::SCREEN_WIDTH_HALF + Main::SCREEN_WIDTH_OUT_LEFT)x = Main::SCREEN_WIDTH_HALF + Main::SCREEN_WIDTH_OUT_LEFT;
			if (y < Main::SCREEN_HEIGHT_HALF + Main::SCREEN_HEIGHT_OUT_TOP)y = Main::SCREEN_HEIGHT_HALF + Main::SCREEN_HEIGHT_OUT_TOP;
			this->container->rightUp->setPosition(x, y);
			 
			x = this->container->rightDown->getPositionX() - offsetX;
			y = this->container->rightDown->getPositionY() + offsetY;
			if (x < Main::SCREEN_WIDTH_HALF+Main::SCREEN_WIDTH_OUT_LEFT)x = Main::SCREEN_WIDTH_HALF+ Main::SCREEN_WIDTH_OUT_LEFT;
			if (y > Main::SCREEN_HEIGHT_HALF+ Main::SCREEN_HEIGHT_OUT_DOWN)y = Main::SCREEN_HEIGHT_HALF+ Main::SCREEN_HEIGHT_OUT_DOWN;
			this->container->rightDown->setPosition(x, y);
        }
        else if (this->frameCounter > 15 && this->frameCounter < 23)
        {
            if (!this->middleRound)
            {
				//Main::mainClass->preload.join();
				this->middleRound = new  MiddleScreenCentr_mc();
				this->middleRound->stop();
				this->middleRound->setPositionX(Main::SCREEN_WIDTH_HALF);
				this->middleRound->setPositionY(Main::SCREEN_HEIGHT_HALF); 
				this->addChild(this->middleRound);
                Main::mainClass->removeAllScreens();
                Main::mainClass->addNewScreen(this->openScreenName);
                Main::mainClass->container->manageListeners("off");
            }
            //this->middleRound->tryPlay();
			if (this->frameCounter == 16 && Main::mainClass->preload.getProgress() < 1) {
				this->frameCounter--; 
				if (!Main::mainClass->preload.isStartSch())
					Main::mainClass->preload.startSch();
				return;
			}
			else if(Main::mainClass->preload.isRunning()){
				Main::mainClass->preload.join();
			}
			if(this->middleRound->currentFrame < this->middleRound->totalFrames)
            {
				this->middleRound->gotoAndStop((this->middleRound->currentFrame + 1));
				this->middleRound->setRotation(this->middleRound->getRotation() + 15);
            }
            if(this->frameCounter == 22)
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
			 this->container->leftUp->setPositionY(this->container->leftUp->getPositionY() + offsetY);
			 this->container->leftDown->setPositionX(this->container->leftDown->getPositionX() - offsetX);
			 this->container->leftDown->setPositionY(this->container->leftDown->getPositionY() - offsetY);
			 this->container->rightUp->setPositionX(this->container->rightUp->getPositionX() + offsetX);
			 this->container->rightUp->setPositionY(this->container->rightUp->getPositionY() + offsetY);
			 this->container->rightDown->setPositionX(this->container->rightDown->getPositionX() + offsetX);
			 this->container->rightDown->setPositionY(this->container->rightDown->getPositionY() - offsetY);
			 //this->container->leftUp->setPositionX(this->container->leftUp->getPositionX() - offsetX);
			 //this->container->leftUp->setPositionY(this->container->leftUp->getPositionY() - offsetY);
			 //this->container->leftDown->setPositionX(this->container->leftDown->getPositionX() - offsetX);
			 //this->container->leftDown->setPositionY(this->container->leftDown->getPositionY() + offsetY);
			 //this->container->rightUp->setPositionX(this->container->rightUp->getPositionX() + offsetX);
			 //this->container->rightUp->setPositionY(this->container->rightUp->getPositionY() - offsetY);
			 //this->container->rightDown->setPositionX(this->container->rightDown->getPositionX() + offsetX);
			 //this->container->rightDown->setPositionY(this->container->rightDown->getPositionY() + offsetY);
			        
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
                    Main::mainClass->container->manageListeners("on");
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
