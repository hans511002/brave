#ifndef BEZIER__H
#define BEZIER__H
#include "BaseHeaders.h"
#include "MainClass.h"
 

namespace screens
{ 
    class MiddleScreen : public cocos2d::Node
    {
	public:
		int i;// public var i : int;
        //public var tempObject:Object;
        //public var container:MiddleScreen_mc;
        //public var middleRound:MiddleScreenCentr_mc;
		int frameCounter;// public var frameCounter : int = 0;
		int gogoCounter;// public var gogoCounter : int = 0;
		string openScreenName;// public var openScreenName : String;

         MiddleScreen(string param1)
        {
            //this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this->openScreenName = param1;
        }// end function

        bool init()
        {
            //this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            //this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            //this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            if (Main::mainClass->container)
            {
                //Main.mainClass.container.manageListeners("off");
            }
            //this.stage.frameRate = 60;
            //this.container = new MiddleScreen_mc();
            //this.container.stop();
            //this.container.leftUp.stop();
            //this.container.rightUp.stop();
            //this.container.leftDown.stop();
            //this.container.rightDown.stop();
            //this.addChild(this.container);
            if (this->openScreenName == "World" || Main::mainClass->worldClass)
            {
                //Sounds.instance.stopAll();
            }
            //Sounds.instance.playSoundWithVol("snd_middleScreen", 0.95);
            return true;
        }// end function

        //public function enterFrameHandler(event:Event) : void
        //{
        //    (this.frameCounter + 1);
        //    if (this.frameCounter <= 15)
        //    {
        //        var _loc_2:* = this;
        //        var _loc_3:* = this.gogoCounter + 1;
        //        _loc_2.gogoCounter = _loc_3;
        //        if (this.gogoCounter == 1)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 44;
        //            this.container.leftUp.y = this.container.leftUp.y + 34;
        //            this.container.leftDown.x = this.container.leftDown.x + 44;
        //            this.container.leftDown.y = this.container.leftDown.y - 34;
        //            this.container.rightUp.x = this.container.rightUp.x - 44;
        //            this.container.rightUp.y = this.container.rightUp.y + 34;
        //            this.container.rightDown.x = this.container.rightDown.x - 44;
        //            this.container.rightDown.y = this.container.rightDown.y - 34;
        //        }
        //        else if (this.gogoCounter == 2)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 42;
        //            this.container.leftUp.y = this.container.leftUp.y + 32;
        //            this.container.leftDown.x = this.container.leftDown.x + 42;
        //            this.container.leftDown.y = this.container.leftDown.y - 32;
        //            this.container.rightUp.x = this.container.rightUp.x - 42;
        //            this.container.rightUp.y = this.container.rightUp.y + 32;
        //            this.container.rightDown.x = this.container.rightDown.x - 42;
        //            this.container.rightDown.y = this.container.rightDown.y - 32;
        //        }
        //        else if (this.gogoCounter == 3)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 40;
        //            this.container.leftUp.y = this.container.leftUp.y + 30;
        //            this.container.leftDown.x = this.container.leftDown.x + 40;
        //            this.container.leftDown.y = this.container.leftDown.y - 30;
        //            this.container.rightUp.x = this.container.rightUp.x - 40;
        //            this.container.rightUp.y = this.container.rightUp.y + 30;
        //            this.container.rightDown.x = this.container.rightDown.x - 40;
        //            this.container.rightDown.y = this.container.rightDown.y - 30;
        //        }
        //        else if (this.gogoCounter == 4)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 38;
        //            this.container.leftUp.y = this.container.leftUp.y + 28;
        //            this.container.leftDown.x = this.container.leftDown.x + 38;
        //            this.container.leftDown.y = this.container.leftDown.y - 28;
        //            this.container.rightUp.x = this.container.rightUp.x - 38;
        //            this.container.rightUp.y = this.container.rightUp.y + 28;
        //            this.container.rightDown.x = this.container.rightDown.x - 38;
        //            this.container.rightDown.y = this.container.rightDown.y - 28;
        //        }
        //        else if (this.gogoCounter == 5)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 36;
        //            this.container.leftUp.y = this.container.leftUp.y + 26;
        //            this.container.leftDown.x = this.container.leftDown.x + 36;
        //            this.container.leftDown.y = this.container.leftDown.y - 26;
        //            this.container.rightUp.x = this.container.rightUp.x - 36;
        //            this.container.rightUp.y = this.container.rightUp.y + 26;
        //            this.container.rightDown.x = this.container.rightDown.x - 36;
        //            this.container.rightDown.y = this.container.rightDown.y - 26;
        //        }
        //        else if (this.gogoCounter == 6)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 34;
        //            this.container.leftUp.y = this.container.leftUp.y + 24;
        //            this.container.leftDown.x = this.container.leftDown.x + 34;
        //            this.container.leftDown.y = this.container.leftDown.y - 24;
        //            this.container.rightUp.x = this.container.rightUp.x - 34;
        //            this.container.rightUp.y = this.container.rightUp.y + 24;
        //            this.container.rightDown.x = this.container.rightDown.x - 34;
        //            this.container.rightDown.y = this.container.rightDown.y - 24;
        //        }
        //        else if (this.gogoCounter == 7)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 32;
        //            this.container.leftUp.y = this.container.leftUp.y + 22;
        //            this.container.leftDown.x = this.container.leftDown.x + 32;
        //            this.container.leftDown.y = this.container.leftDown.y - 22;
        //            this.container.rightUp.x = this.container.rightUp.x - 32;
        //            this.container.rightUp.y = this.container.rightUp.y + 22;
        //            this.container.rightDown.x = this.container.rightDown.x - 32;
        //            this.container.rightDown.y = this.container.rightDown.y - 22;
        //        }
        //        else if (this.gogoCounter == 8)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 30;
        //            this.container.leftUp.y = this.container.leftUp.y + 20;
        //            this.container.leftDown.x = this.container.leftDown.x + 30;
        //            this.container.leftDown.y = this.container.leftDown.y - 20;
        //            this.container.rightUp.x = this.container.rightUp.x - 30;
        //            this.container.rightUp.y = this.container.rightUp.y + 20;
        //            this.container.rightDown.x = this.container.rightDown.x - 30;
        //            this.container.rightDown.y = this.container.rightDown.y - 20;
        //        }
        //        else if (this.gogoCounter == 9)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 28;
        //            this.container.leftUp.y = this.container.leftUp.y + 18;
        //            this.container.leftDown.x = this.container.leftDown.x + 28;
        //            this.container.leftDown.y = this.container.leftDown.y - 18;
        //            this.container.rightUp.x = this.container.rightUp.x - 28;
        //            this.container.rightUp.y = this.container.rightUp.y + 18;
        //            this.container.rightDown.x = this.container.rightDown.x - 28;
        //            this.container.rightDown.y = this.container.rightDown.y - 18;
        //        }
        //        else if (this.gogoCounter == 10)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 26;
        //            this.container.leftUp.y = this.container.leftUp.y + 16;
        //            this.container.leftDown.x = this.container.leftDown.x + 26;
        //            this.container.leftDown.y = this.container.leftDown.y - 16;
        //            this.container.rightUp.x = this.container.rightUp.x - 26;
        //            this.container.rightUp.y = this.container.rightUp.y + 16;
        //            this.container.rightDown.x = this.container.rightDown.x - 26;
        //            this.container.rightDown.y = this.container.rightDown.y - 16;
        //        }
        //        else if (this.gogoCounter == 11)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 20;
        //            this.container.leftUp.y = this.container.leftUp.y + 20;
        //            this.container.leftDown.x = this.container.leftDown.x + 20;
        //            this.container.leftDown.y = this.container.leftDown.y - 20;
        //            this.container.rightUp.x = this.container.rightUp.x - 20;
        //            this.container.rightUp.y = this.container.rightUp.y + 20;
        //            this.container.rightDown.x = this.container.rightDown.x - 20;
        //            this.container.rightDown.y = this.container.rightDown.y - 20;
        //        }
        //        else if (this.gogoCounter == 12)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 15;
        //            this.container.leftUp.y = this.container.leftUp.y + 15;
        //            this.container.leftDown.x = this.container.leftDown.x + 15;
        //            this.container.leftDown.y = this.container.leftDown.y - 15;
        //            this.container.rightUp.x = this.container.rightUp.x - 15;
        //            this.container.rightUp.y = this.container.rightUp.y + 15;
        //            this.container.rightDown.x = this.container.rightDown.x - 15;
        //            this.container.rightDown.y = this.container.rightDown.y - 15;
        //        }
        //        else if (this.gogoCounter == 13)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 10;
        //            this.container.leftUp.y = this.container.leftUp.y + 10;
        //            this.container.leftDown.x = this.container.leftDown.x + 10;
        //            this.container.leftDown.y = this.container.leftDown.y - 10;
        //            this.container.rightUp.x = this.container.rightUp.x - 10;
        //            this.container.rightUp.y = this.container.rightUp.y + 10;
        //            this.container.rightDown.x = this.container.rightDown.x - 10;
        //            this.container.rightDown.y = this.container.rightDown.y - 10;
        //        }
        //        else if (this.gogoCounter == 14)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 3;
        //            this.container.leftUp.y = this.container.leftUp.y + 3;
        //            this.container.leftDown.x = this.container.leftDown.x + 3;
        //            this.container.leftDown.y = this.container.leftDown.y - 3;
        //            this.container.rightUp.x = this.container.rightUp.x - 3;
        //            this.container.rightUp.y = this.container.rightUp.y + 3;
        //            this.container.rightDown.x = this.container.rightDown.x - 3;
        //            this.container.rightDown.y = this.container.rightDown.y - 3;
        //        }
        //        else if (this.gogoCounter == 15)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x + 2;
        //            this.container.leftUp.y = this.container.leftUp.y + 2;
        //            this.container.leftDown.x = this.container.leftDown.x + 2;
        //            this.container.leftDown.y = this.container.leftDown.y - 2;
        //            this.container.rightUp.x = this.container.rightUp.x - 2;
        //            this.container.rightUp.y = this.container.rightUp.y + 2;
        //            this.container.rightDown.x = this.container.rightDown.x - 2;
        //            this.container.rightDown.y = this.container.rightDown.y - 2;
        //        }
        //    }
        //    else if (this.frameCounter > 15 && this.frameCounter < 23)
        //    {
        //        if (!this.middleRound)
        //        {
        //            this.middleRound = new MiddleScreenCentr_mc();
        //            this.middleRound.stop();
        //            this.middleRound.x = Main.SCREEN_WIDTH_HALF;
        //            this.middleRound.y = Main.SCREEN_HEIGHT_HALF;
        //            this.addChild(this.middleRound);
        //            Main.mainClass.removeAllScreens();
        //            Main.mainClass.addNewScreen(this.openScreenName);
        //            Main.mainClass.container.manageListeners("off");
        //        }
        //        if (this.middleRound.currentFrame < this.middleRound.totalFrames)
        //        {
        //            this.middleRound.gotoAndStop((this.middleRound.currentFrame + 1));
        //            this.middleRound.rotation = this.middleRound.rotation + 15;
        //        }
        //        else
        //        {
        //            this.container.leftUp.gotoAndStop(2);
        //            this.container.leftDown.gotoAndStop(2);
        //            this.container.rightUp.gotoAndStop(2);
        //            this.container.rightDown.gotoAndStop(2);
        //            this.removeChild(this.middleRound);
        //            this.middleRound = null;
        //            this.gogoCounter = 0;
        //        }
        //    }
        //    else
        //    {
        //        var _loc_2:* = this;
        //        var _loc_3:* = this.gogoCounter + 1;
        //        _loc_2.gogoCounter = _loc_3;
        //        if (this.gogoCounter == 1)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 2;
        //            this.container.leftUp.y = this.container.leftUp.y - 2;
        //            this.container.leftDown.x = this.container.leftDown.x - 2;
        //            this.container.leftDown.y = this.container.leftDown.y + 2;
        //            this.container.rightUp.x = this.container.rightUp.x + 2;
        //            this.container.rightUp.y = this.container.rightUp.y - 2;
        //            this.container.rightDown.x = this.container.rightDown.x + 2;
        //            this.container.rightDown.y = this.container.rightDown.y + 2;
        //        }
        //        else if (this.gogoCounter == 2)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 3;
        //            this.container.leftUp.y = this.container.leftUp.y - 3;
        //            this.container.leftDown.x = this.container.leftDown.x - 3;
        //            this.container.leftDown.y = this.container.leftDown.y + 3;
        //            this.container.rightUp.x = this.container.rightUp.x + 3;
        //            this.container.rightUp.y = this.container.rightUp.y - 3;
        //            this.container.rightDown.x = this.container.rightDown.x + 3;
        //            this.container.rightDown.y = this.container.rightDown.y + 3;
        //        }
        //        else if (this.gogoCounter == 3)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 10;
        //            this.container.leftUp.y = this.container.leftUp.y - 10;
        //            this.container.leftDown.x = this.container.leftDown.x - 10;
        //            this.container.leftDown.y = this.container.leftDown.y + 10;
        //            this.container.rightUp.x = this.container.rightUp.x + 10;
        //            this.container.rightUp.y = this.container.rightUp.y - 10;
        //            this.container.rightDown.x = this.container.rightDown.x + 10;
        //            this.container.rightDown.y = this.container.rightDown.y + 10;
        //        }
        //        else if (this.gogoCounter == 4)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 15;
        //            this.container.leftUp.y = this.container.leftUp.y - 15;
        //            this.container.leftDown.x = this.container.leftDown.x - 15;
        //            this.container.leftDown.y = this.container.leftDown.y + 15;
        //            this.container.rightUp.x = this.container.rightUp.x + 15;
        //            this.container.rightUp.y = this.container.rightUp.y - 15;
        //            this.container.rightDown.x = this.container.rightDown.x + 15;
        //            this.container.rightDown.y = this.container.rightDown.y + 15;
        //        }
        //        else if (this.gogoCounter == 5)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 20;
        //            this.container.leftUp.y = this.container.leftUp.y - 20;
        //            this.container.leftDown.x = this.container.leftDown.x - 20;
        //            this.container.leftDown.y = this.container.leftDown.y + 20;
        //            this.container.rightUp.x = this.container.rightUp.x + 20;
        //            this.container.rightUp.y = this.container.rightUp.y - 20;
        //            this.container.rightDown.x = this.container.rightDown.x + 20;
        //            this.container.rightDown.y = this.container.rightDown.y + 20;
        //        }
        //        else if (this.gogoCounter == 6)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 26;
        //            this.container.leftUp.y = this.container.leftUp.y - 20;
        //            this.container.leftDown.x = this.container.leftDown.x - 26;
        //            this.container.leftDown.y = this.container.leftDown.y + 20;
        //            this.container.rightUp.x = this.container.rightUp.x + 26;
        //            this.container.rightUp.y = this.container.rightUp.y - 20;
        //            this.container.rightDown.x = this.container.rightDown.x + 26;
        //            this.container.rightDown.y = this.container.rightDown.y + 20;
        //        }
        //        else if (this.gogoCounter == 7)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 28;
        //            this.container.leftUp.y = this.container.leftUp.y - 20;
        //            this.container.leftDown.x = this.container.leftDown.x - 28;
        //            this.container.leftDown.y = this.container.leftDown.y + 20;
        //            this.container.rightUp.x = this.container.rightUp.x + 28;
        //            this.container.rightUp.y = this.container.rightUp.y - 20;
        //            this.container.rightDown.x = this.container.rightDown.x + 28;
        //            this.container.rightDown.y = this.container.rightDown.y + 20;
        //        }
        //        else if (this.gogoCounter == 8)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 30;
        //            this.container.leftUp.y = this.container.leftUp.y - 20;
        //            this.container.leftDown.x = this.container.leftDown.x - 30;
        //            this.container.leftDown.y = this.container.leftDown.y + 20;
        //            this.container.rightUp.x = this.container.rightUp.x + 30;
        //            this.container.rightUp.y = this.container.rightUp.y - 20;
        //            this.container.rightDown.x = this.container.rightDown.x + 30;
        //            this.container.rightDown.y = this.container.rightDown.y + 20;
        //        }
        //        else if (this.gogoCounter == 9)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 32;
        //            this.container.leftUp.y = this.container.leftUp.y - 20;
        //            this.container.leftDown.x = this.container.leftDown.x - 32;
        //            this.container.leftDown.y = this.container.leftDown.y + 20;
        //            this.container.rightUp.x = this.container.rightUp.x + 32;
        //            this.container.rightUp.y = this.container.rightUp.y - 20;
        //            this.container.rightDown.x = this.container.rightDown.x + 32;
        //            this.container.rightDown.y = this.container.rightDown.y + 20;
        //        }
        //        else if (this.gogoCounter == 10)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 34;
        //            this.container.leftUp.y = this.container.leftUp.y - 20;
        //            this.container.leftDown.x = this.container.leftDown.x - 34;
        //            this.container.leftDown.y = this.container.leftDown.y + 20;
        //            this.container.rightUp.x = this.container.rightUp.x + 34;
        //            this.container.rightUp.y = this.container.rightUp.y - 20;
        //            this.container.rightDown.x = this.container.rightDown.x + 34;
        //            this.container.rightDown.y = this.container.rightDown.y + 20;
        //        }
        //        else if (this.gogoCounter == 11)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 36;
        //            this.container.leftUp.y = this.container.leftUp.y - 30;
        //            this.container.leftDown.x = this.container.leftDown.x - 36;
        //            this.container.leftDown.y = this.container.leftDown.y + 30;
        //            this.container.rightUp.x = this.container.rightUp.x + 36;
        //            this.container.rightUp.y = this.container.rightUp.y - 30;
        //            this.container.rightDown.x = this.container.rightDown.x + 36;
        //            this.container.rightDown.y = this.container.rightDown.y + 30;
        //        }
        //        else if (this.gogoCounter == 12)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 38;
        //            this.container.leftUp.y = this.container.leftUp.y - 30;
        //            this.container.leftDown.x = this.container.leftDown.x - 38;
        //            this.container.leftDown.y = this.container.leftDown.y + 30;
        //            this.container.rightUp.x = this.container.rightUp.x + 38;
        //            this.container.rightUp.y = this.container.rightUp.y - 30;
        //            this.container.rightDown.x = this.container.rightDown.x + 38;
        //            this.container.rightDown.y = this.container.rightDown.y + 30;
        //        }
        //        else if (this.gogoCounter == 13)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 40;
        //            this.container.leftUp.y = this.container.leftUp.y - 30;
        //            this.container.leftDown.x = this.container.leftDown.x - 40;
        //            this.container.leftDown.y = this.container.leftDown.y + 30;
        //            this.container.rightUp.x = this.container.rightUp.x + 40;
        //            this.container.rightUp.y = this.container.rightUp.y - 30;
        //            this.container.rightDown.x = this.container.rightDown.x + 40;
        //            this.container.rightDown.y = this.container.rightDown.y + 30;
        //        }
        //        else if (this.gogoCounter == 14)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 42;
        //            this.container.leftUp.y = this.container.leftUp.y - 30;
        //            this.container.leftDown.x = this.container.leftDown.x - 42;
        //            this.container.leftDown.y = this.container.leftDown.y + 30;
        //            this.container.rightUp.x = this.container.rightUp.x + 42;
        //            this.container.rightUp.y = this.container.rightUp.y - 30;
        //            this.container.rightDown.x = this.container.rightDown.x + 42;
        //            this.container.rightDown.y = this.container.rightDown.y + 30;
        //        }
        //        else if (this.gogoCounter == 15)
        //        {
        //            this.container.leftUp.x = this.container.leftUp.x - 44;
        //            this.container.leftUp.y = this.container.leftUp.y - 30;
        //            this.container.leftDown.x = this.container.leftDown.x - 44;
        //            this.container.leftDown.y = this.container.leftDown.y + 30;
        //            this.container.rightUp.x = this.container.rightUp.x + 44;
        //            this.container.rightUp.y = this.container.rightUp.y - 30;
        //            this.container.rightDown.x = this.container.rightDown.x + 44;
        //            this.container.rightDown.y = this.container.rightDown.y + 30;
        //        }
        //        if (this.frameCounter == 38)
        //        {
        //            Main.mainClass.removeChild(Main.mainClass.middleScreenClass);
        //            Main.mainClass.middleScreenClass = null;
        //            Main.mainClass.removeChild(Main.mainClass.bmp);
        //            Main.mainClass.bmp = null;
        //            Main.mainClass.container.visible = true;
        //            if (Main.mainClass.container)
        //            {
        //                Main.mainClass.container.manageListeners("on");
        //            }
        //        }
        //    }
        //    return;
        //}// end function

        //public function reInit(event:Event) : void
        //{
        //    this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
        //    this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
        //    if (this.stage.quality != "high")
        //    {
        //        this.stage.quality = "high";
        //    }
        //    if (this.stage.frameRate != 30)
        //    {
        //        this.stage.frameRate = 30;
        //    }
        //    return;
        //}// end function

	};
}
#endif
