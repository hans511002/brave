package training
{
    import flash.display.*;
    import flash.events.*;

    public class Training_91 extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var container:Training_91_mc;
        public var frameCounter:int = 0;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var dead:Boolean;
        public var myLevel:int;

        public function Training_91(param1:int)
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.myLevel = param1;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.container = new Training_91_mc();
            this.container.stop();
            if (this.myLevel == 1)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level1;
            }
            else if (this.myLevel == 2)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level2;
            }
            else if (this.myLevel == 3)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level3;
            }
            else if (this.myLevel == 4)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level4;
            }
            else if (this.myLevel == 5)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level5;
            }
            else if (this.myLevel == 6)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level6;
            }
            else if (this.myLevel == 7)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level7;
            }
            else if (this.myLevel == 8)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level8;
            }
            else if (this.myLevel == 9)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level9;
            }
            else if (this.myLevel == 10)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level10;
            }
            else if (this.myLevel == 11)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level11;
            }
            else if (this.myLevel == 12)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level12;
            }
            else if (this.myLevel == 13)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level13;
            }
            else if (this.myLevel == 14)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level14;
            }
            else if (this.myLevel == 15)
            {
                this.tempObject = Main.mainClass.levelsMenuClass.container.level15;
            }
            this.container.x = this.tempObject.x + this.container.width / 2 - 7;
            this.container.y = this.tempObject.y - this.container.height / 2 - 15;
            this.addChild(this.container);
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            return;
        }// end function

        public function enterFrameHandler(event:Event) : void
        {
            if (this.frameCounter < 30)
            {
                (this.frameCounter + 1);
            }
            else
            {
                this.frameCounter = 1;
            }
            if (this.openFlag)
            {
                if (this.container.currentFrame < 12)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                else
                {
                    this.openFlag = false;
                }
            }
            else if (this.closeFlag)
            {
                if (this.container.currentFrame < 23)
                {
                    this.container.gotoAndStop(23);
                }
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                else
                {
                    this.closeFlag = false;
                    Main.mainClass.levelsMenuClass.openLevel.visible = true;
                    this.kill();
                }
            }
            else
            {
                if (this.container.currentFrame < 23)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                else
                {
                    this.container.gotoAndStop(13);
                }
                if (Main.mainClass.levelsMenuClass.openLevel)
                {
                    this.closeFlag = true;
                }
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                Main.mainClass.levelsMenuClass.removeChild(this);
                Main.mainClass.levelsMenuClass.training_1 = null;
            }
            return;
        }// end function

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            return;
        }// end function

    }
}
