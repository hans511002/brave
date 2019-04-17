package training
{
    import engine.*;
    import engine.towers.*;
    import flash.display.*;
    import flash.events.*;

    public class Training_12 extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var container:MovieClip;
        public var frameCounter:int = 0;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var dead:Boolean;
        public var world:World;
        public var myTowerMenu:TowerMenu;

        public function Training_12()
        {
            this.world = Main.mainClass.worldClass;
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.world.addEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            this.container = new Training_12_mc();
            this.container.stop();
            this.addChild(this.container);
            this.myTowerMenu = this.world.towerMenu;
            this.x = 5;
            this.y = -5;
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
                if (!this.world.towerMenu)
                {
                    this.closeFlag = true;
                }
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "btnGetAllCase")
            {
                Main.mainClass.saveBoxClass.gameSave.data.firstClickKeepAll = true;
                this.closeFlag = true;
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.myTowerMenu.removeChild(this);
                this.myTowerMenu.training_12 = null;
            }
            return;
        }// end function

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.world.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            return;
        }// end function

    }
}
