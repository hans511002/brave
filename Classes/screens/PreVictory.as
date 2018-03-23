package screens
{
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class PreVictory extends Sprite
    {
        public var i:int;
        public var tempObject:Object;
        public var container:PreVictory_mc;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var dead:Boolean;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;

        public function PreVictory()
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.addEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
            this.addEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            this.addEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            Main.mainClass.worldClass.manageListeners("off");
            Main.mainClass.worldClass.worldInterface.breaking();
            this.container = new PreVictory_mc();
            this.stopAll();
            this.container.x = Main.SCREEN_WIDTH_HALF;
            this.container.y = Main.SCREEN_HEIGHT_HALF;
            this.addChild(this.container);
            var _loc_2:* = false;
            this.container.cont.mouseChildren = false;
            this.container.cont.mouseEnabled = _loc_2;
            return;
        }// end function

        public function enterFrameHandler(event:Event) : void
        {
            if (this.openFlag)
            {
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                if (this.container.cont.currentFrame < this.container.cont.totalFrames)
                {
                    this.container.cont.gotoAndStop((this.container.cont.currentFrame + 1));
                }
                this.stopAll();
                if (this.container.currentFrame == this.container.totalFrames && this.container.cont.currentFrame == this.container.cont.totalFrames)
                {
                    this.openFlag = false;
                    var _loc_2:* = true;
                    this.container.cont.mouseChildren = true;
                    this.container.cont.mouseEnabled = _loc_2;
                    this.autoguidersButtons();
                }
            }
            else if (this.closeFlag)
            {
                if (this.container.currentFrame > 1)
                {
                    this.container.gotoAndStop((this.container.currentFrame - 1));
                }
                if (this.container.cont.currentFrame > 1)
                {
                    this.container.cont.gotoAndStop((this.container.cont.currentFrame - 1));
                }
                this.stopAll();
                if (this.container.currentFrame == 1 && this.container.cont.currentFrame == 1)
                {
                    this.closeFlag = false;
                    this.kill();
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (param1.target.name == "okCase")
            {
                if (this.container.cont.btnOk.currentFrame == 1)
                {
                    this.container.cont.btnOk.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.btnOk.currentFrame == 2)
            {
                this.container.cont.btnOk.gotoAndStop(1);
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (!this.openFlag && !this.closeFlag)
            {
                if (event.target.name == "okCase")
                {
                    if (this.container.cont.btnOk.currentFrame == 2)
                    {
                        this.container.cont.btnOk.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (event.target.name == "okCase")
            {
                if (this.container.cont.btnOk.currentFrame == 3)
                {
                    this.container.cont.btnOk.gotoAndStop(2);
                    this.close();
                }
            }
            else if (this.container.cont.btnOk.currentFrame == 3)
            {
                this.container.cont.btnOk.gotoAndStop(1);
            }
            return;
        }// end function

        public function stopAll() : void
        {
            this.container.stop();
            this.container.cont.stop();
            this.container.cont.btnOk.stop();
            this.container.cont.btnOk.okCase.stop();
            this.container.cont.btnOk.okCase.buttonMode = true;
            return;
        }// end function

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(this.mouseX, this.mouseY);
            this.autoguidesObject = null;
            this.autoguidesObject_pt = this.container.cont.btnOk.localToGlobal(new Point(this.container.cont.btnOk.okCase.x, this.container.cont.btnOk.okCase.y));
            this.autoguidesObjectWidth = this.container.cont.btnOk.okCase.width / 2;
            this.autoguidesObjectHeight = this.container.cont.btnOk.okCase.height / 2;
            if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
            {
                this.autoguidesObject = this.container.cont.btnOk.okCase;
            }
            if (this.autoguidesObject)
            {
                this.tempObject = new Object();
                this.tempObject.target = this.autoguidesObject;
                this.mouseMoveHandler(this.tempObject);
            }
            return;
        }// end function

        public function close() : void
        {
            if (!this.closeFlag)
            {
                this.closeFlag = true;
                var _loc_1:* = false;
                this.container.cont.mouseChildren = false;
                this.container.cont.mouseEnabled = _loc_1;
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                Main.mainClass.worldClass.removeChild(this);
                Main.mainClass.worldClass.menuObject = null;
                Main.mainClass.worldClass.menuObject = new Victory();
                Main.mainClass.worldClass.addChild(Main.mainClass.worldClass.menuObject);
            }
            return;
        }// end function

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.removeEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
            this.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            this.removeEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            return;
        }// end function

    }
}
