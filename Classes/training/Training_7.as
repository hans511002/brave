package training
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;

    public class Training_7 extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var container:Training_7_mc;
        public var frameCounter:int = 0;
        public var dead:Boolean;
        public var world:World;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var type:String;

        public function Training_7(param1:String)
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.type = param1;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.world = Main.mainClass.worldClass;
            this.container = new Training_7_mc();
            this.container.stop();
            if (this.type == "golem")
            {
                this.container.x = this.world.worldInterface.container.butCastGolem.x + this.world.worldInterface.container.butCastGolem.width / 2 + this.container.width / 2;
                this.container.y = this.world.worldInterface.container.butCastGolem.y - this.world.worldInterface.container.butCastGolem.height / 2 - this.container.height / 2;
            }
            else if (this.type == "iceman")
            {
                this.container.x = this.world.worldInterface.container.butCastIceman.x + this.world.worldInterface.container.butCastIceman.width / 2 + this.container.width / 2;
                this.container.y = this.world.worldInterface.container.butCastIceman.y - this.world.worldInterface.container.butCastIceman.height / 2 - this.container.height / 2;
            }
            else if (this.type == "air")
            {
                this.container.x = this.world.worldInterface.container.butCastAir.x + this.world.worldInterface.container.butCastAir.width / 2 + this.container.width / 2;
                this.container.y = this.world.worldInterface.container.butCastAir.y - this.world.worldInterface.container.butCastAir.height / 2 - this.container.height / 2;
            }
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
                if (this.world.cast)
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
                this.world.removeChild(this);
                this.world.trainingClass = null;
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
