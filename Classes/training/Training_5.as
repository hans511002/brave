package training
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class Training_5 extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var container:Training_5_mc;
        public var frameCounter:int = 0;
        public var dead:Boolean;
        public var world:World;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var type:int;
        public var page:int;
        public var viewCounter:int = 15;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;

        public function Training_5(param1:int)
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            var _loc_2:* = param1;
            this.page = param1;
            this.type = _loc_2;
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
            this.world = Main.mainClass.worldClass;
            this.container = new Training_5_mc();
            this.container.x = Main.SCREEN_WIDTH_HALF;
            this.container.y = Main.SCREEN_HEIGHT_HALF;
            this.contStops();
            var _loc_2:* = false;
            this.container.cont.mouseChildren = false;
            this.container.cont.mouseEnabled = _loc_2;
            this.container.cont.visible = false;
            this.addChild(this.container);
            Sounds.instance.playSound("snd_menu_pageScrolling");
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
            if (this.viewCounter > 0)
            {
                (this.viewCounter - 1);
                if (this.viewCounter == 0)
                {
                    this.world.manageListeners("off");
                    if (this.world.exchange)
                    {
                        this.world.worldInterface.breaking();
                    }
                    else if (this.world.getSphere || this.world.cast)
                    {
                        this.world.manageMouse("show");
                    }
                    this.container.cont.visible = true;
                }
                else
                {
                    return;
                }
            }
            if (this.openFlag)
            {
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                if (this.container.cont.currentFrame < this.container.cont.totalFrames)
                {
                    this.container.cont.gotoAndStop((this.container.cont.currentFrame + 1));
                    this.contStops();
                    var _loc_2:* = false;
                    this.container.cont.mouseChildren = false;
                    this.container.cont.mouseEnabled = _loc_2;
                }
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
                    this.contStops();
                    var _loc_2:* = false;
                    this.container.cont.mouseChildren = false;
                    this.container.cont.mouseEnabled = _loc_2;
                }
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
                if (this.container.cont.cont1.btnOk.currentFrame == 1)
                {
                    this.container.cont.cont1.btnOk.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.cont1.btnOk.currentFrame == 2)
            {
                this.container.cont.cont1.btnOk.gotoAndStop(1);
            }
            if (param1.target.name == "arrowCase")
            {
                if (param1.target.parent.currentFrame == 1)
                {
                    param1.target.parent.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else
            {
                if (this.container.cont.cont1.btnLeft.currentFrame == 2)
                {
                    this.container.cont.cont1.btnLeft.gotoAndStop(1);
                }
                if (this.container.cont.cont1.btnRight.currentFrame == 2)
                {
                    this.container.cont.cont1.btnRight.gotoAndStop(1);
                }
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "okCase")
            {
                if (this.container.cont.cont1.btnOk.currentFrame == 2)
                {
                    this.container.cont.cont1.btnOk.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "arrowCase")
            {
                if (event.target.parent.currentFrame == 2)
                {
                    event.target.parent.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (event.target.name == "okCase")
            {
                if (this.container.cont.cont1.btnOk.currentFrame == 3)
                {
                    this.container.cont.cont1.btnOk.gotoAndStop(1);
                    this.close();
                }
            }
            else if (this.container.cont.cont1.btnOk.currentFrame == 3)
            {
                this.container.cont.cont1.btnOk.gotoAndStop(1);
            }
            if (event.target.name == "arrowCase")
            {
                if (event.target.parent.currentFrame == 3)
                {
                    if (event.target.parent.name == "btnLeft")
                    {
                        this.container.cont.cont1.btnLeft.gotoAndStop(2);
                        if (this.page > 1)
                        {
                            (this.page - 1);
                        }
                        else
                        {
                            this.page = 7;
                        }
                        this.contStops();
                    }
                    else if (event.target.parent.name == "btnRight")
                    {
                        this.container.cont.cont1.btnRight.gotoAndStop(2);
                        if (this.page < 7)
                        {
                            (this.page + 1);
                        }
                        else
                        {
                            this.page = 1;
                        }
                        this.contStops();
                    }
                }
            }
            else
            {
                if (this.container.cont.cont1.btnLeft.currentFrame == 3)
                {
                    this.container.cont.cont1.btnLeft.gotoAndStop(1);
                }
                if (this.container.cont.cont1.btnRight.currentFrame == 3)
                {
                    this.container.cont.cont1.btnRight.gotoAndStop(1);
                }
            }
            return;
        }// end function

        public function contStops() : void
        {
            this.container.stop();
            this.container.cont.stop();
            this.container.cont.cont1.gotoAndStop(this.page);
            this.container.cont.cont1.btnOk.stop();
            this.container.cont.cont1.btnLeft.stop();
            this.container.cont.cont1.btnRight.stop();
            this.container.cont.cont1.btnOk.okCase.stop();
            this.container.cont.cont1.btnOk.okCase.buttonMode = true;
            this.container.cont.cont1.btnLeft.arrowCase.stop();
            this.container.cont.cont1.btnLeft.arrowCase.buttonMode = true;
            this.container.cont.cont1.btnRight.arrowCase.stop();
            this.container.cont.cont1.btnRight.arrowCase.buttonMode = true;
            this.container.cont.cont1.btnLeft.visible = false;
            this.container.cont.cont1.btnRight.visible = false;
            return;
        }// end function

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(this.mouseX, this.mouseY);
            this.autoguidesObject = null;
            this.autoguidesObject_pt = this.container.cont.cont1.btnOk.localToGlobal(new Point(this.container.cont.cont1.btnOk.okCase.x, this.container.cont.cont1.btnOk.okCase.y));
            this.autoguidesObjectWidth = this.container.cont.cont1.btnOk.okCase.width / 2;
            this.autoguidesObjectHeight = this.container.cont.cont1.btnOk.okCase.height / 2;
            if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
            {
                this.autoguidesObject = this.container.cont.cont1.btnOk.okCase;
            }
            if (!this.autoguidesObject)
            {
                this.autoguidesObject_pt = this.container.cont.cont1.btnLeft.localToGlobal(new Point(this.container.cont.cont1.btnLeft.arrowCase.x, this.container.cont.cont1.btnLeft.arrowCase.y));
                this.autoguidesObjectWidth = this.container.cont.cont1.btnLeft.arrowCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.cont1.btnLeft.arrowCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.cont1.btnLeft.arrowCase;
                }
            }
            if (!this.autoguidesObject)
            {
                this.autoguidesObject_pt = this.container.cont.cont1.btnRight.localToGlobal(new Point(this.container.cont.cont1.btnRight.arrowCase.x, this.container.cont.cont1.btnRight.arrowCase.y));
                this.autoguidesObjectWidth = this.container.cont.cont1.btnRight.arrowCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.cont1.btnRight.arrowCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.cont1.btnRight.arrowCase;
                }
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
                Sounds.instance.playSound("snd_menu_pageScrolling");
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.manageListeners("on");
                if (this.world.getSphere || this.world.cast)
                {
                    this.world.manageMouse("hide");
                }
                this.world.removeChild(this);
                this.world.menuObject = null;
                if (this.type == 5)
                {
                    if (!this.world.trainingClass)
                    {
                        this.world.trainingClass = new Training_7("golem");
                        this.world.addChild(this.world.trainingClass);
                    }
                }
                else if (this.type == 6)
                {
                    if (!this.world.trainingClass)
                    {
                        this.world.trainingClass = new Training_7("iceman");
                        this.world.addChild(this.world.trainingClass);
                    }
                }
                else if (this.type == 7)
                {
                    if (!this.world.trainingClass)
                    {
                        this.world.trainingClass = new Training_7("air");
                        this.world.addChild(this.world.trainingClass);
                    }
                }
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
