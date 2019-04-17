package training
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;

    public class Training_11 extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var container:MovieClip;
        public var frameCounter:int = 0;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var dead:Boolean;
        public var type:int;
        public var world:World;

        public function Training_11(param1:int)
        {
            this.world = Main.mainClass.worldClass;
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.type = param1;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.world.worldInterface.addEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            if (this.type < 5)
            {
                this.container = new Training_11_mc();
            }
            else
            {
                this.container = new Training_11_01_mc();
            }
            this.container.stop();
            this.addChild(this.container);
            if (this.type == 1)
            {
                this.container.x = this.world.worldInterface.container.fireSphere.x + 10;
                this.container.y = this.world.worldInterface.container.fireSphere.y + 20;
            }
            else if (this.type == 2)
            {
                this.container.x = this.world.worldInterface.container.iceSphere.x + 10;
                this.container.y = this.world.worldInterface.container.iceSphere.y + 20;
            }
            else if (this.type == 3)
            {
                this.container.x = this.world.worldInterface.container.stoneSphere.x + 10;
                this.container.y = this.world.worldInterface.container.stoneSphere.y + 20;
            }
            else if (this.type == 4)
            {
                this.container.x = this.world.worldInterface.container.levinSphere.x + 10;
                this.container.y = this.world.worldInterface.container.levinSphere.y + 20;
            }
            else if (this.type == 5)
            {
                this.container.x = this.world.worldInterface.container.getAll.x + 10;
                this.container.y = this.world.worldInterface.container.getAll.y + 20;
            }
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
            else if (this.container.currentFrame < 23)
            {
                this.container.gotoAndStop((this.container.currentFrame + 1));
            }
            else
            {
                this.container.gotoAndStop(13);
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (this.type == 1)
            {
                if (event.target.parent.name == "fireSphere")
                {
                    if (event.target.parent.alpha == 1)
                    {
                        this.closeFlag = true;
                    }
                }
            }
            else if (this.type == 2)
            {
                if (event.target.parent.name == "iceSphere")
                {
                    if (event.target.parent.alpha == 1)
                    {
                        this.closeFlag = true;
                    }
                }
            }
            else if (this.type == 3)
            {
                if (event.target.parent.name == "stoneSphere")
                {
                    if (event.target.parent.alpha == 1)
                    {
                        this.closeFlag = true;
                    }
                }
            }
            else if (this.type == 4)
            {
                if (event.target.parent.name == "levinSphere")
                {
                    if (event.target.parent.alpha == 1)
                    {
                        this.closeFlag = true;
                    }
                }
            }
            else if (this.type == 5)
            {
                if (event.target.parent.name == "getAll")
                {
                    if (event.target.parent.alpha == 1)
                    {
                        this.closeFlag = true;
                    }
                }
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.worldInterface.removeChild(this);
            }
            return;
        }// end function

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.world.worldInterface.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            return;
        }// end function

    }
}
