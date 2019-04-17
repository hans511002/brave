package training
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class Training_10 extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var container:Training_10_mc;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var dead:Boolean;
        public var frameCounter:int = 0;
        public var tower1:Tower1_mc;
        public var tower2:Tower1_mc;
        public var viewCounter:int = 15;
        public var world:World;
        public var phase:int = 0;
        public var exchange:Exchange_mc;
        public var exchange1:Exchange1_mc;
        public var listOfMoveSpheres:Array;
        public var oldMouseMove:Object;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;

        public function Training_10()
        {
            this.world = Main.mainClass.worldClass;
            this.listOfMoveSpheres = [];
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
            this.addEventListener(MouseEvent.RIGHT_MOUSE_DOWN, this.mouseRightDownHandler);
            this.addEventListener(MouseEvent.RIGHT_MOUSE_UP, this.mouseRightUpHandler);
            this.container = new Training_10_mc();
            this.contStops();
            this.container.x = Main.SCREEN_WIDTH_HALF;
            this.container.y = Main.SCREEN_HEIGHT_HALF;
            var _loc_2:* = false;
            this.container.cont.mouseChildren = false;
            this.container.cont.mouseEnabled = _loc_2;
            this.container.cont.visible = false;
            this.addChild(this.container);
            this.oldMouseMove = this;
            Sounds.instance.playSound("snd_menu_pageScrolling");
            return;
        }// end function

        public function enterFrameHandler(event:Event) : void
        {
            if (this.frameCounter < 30)
            {
                var _loc_2:* = this;
                var _loc_3:* = this.frameCounter + 1;
                _loc_2.frameCounter = _loc_3;
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
                this.contStops();
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
                    var _loc_2:* = false;
                    this.container.cont.mouseChildren = false;
                    this.container.cont.mouseEnabled = _loc_2;
                }
                if (this.container.currentFrame == 1 && this.container.cont.currentFrame == 1)
                {
                    this.closeFlag = false;
                    this.kill();
                }
                this.contStops();
            }
            else
            {
                if (this.container.cont.cont1.hint1.visible)
                {
                    if (!this.exchange1)
                    {
                        if (this.container.cont.cont1.hint1.currentFrame < 23)
                        {
                            this.container.cont.cont1.hint1.gotoAndStop((this.container.cont.cont1.hint1.currentFrame + 1));
                        }
                        else
                        {
                            this.container.cont.cont1.hint1.gotoAndStop(13);
                        }
                    }
                    else
                    {
                        if (this.container.cont.cont1.hint1.currentFrame < 23)
                        {
                            this.container.cont.cont1.hint1.gotoAndStop(23);
                        }
                        if (this.container.cont.cont1.hint1.currentFrame < this.container.cont.cont1.hint1.totalFrames)
                        {
                            this.container.cont.cont1.hint1.gotoAndStop((this.container.cont.cont1.hint1.currentFrame + 1));
                        }
                        else
                        {
                            this.container.cont.cont1.hint1.visible = false;
                        }
                    }
                }
                if (this.container.cont.cont1.hint2.visible)
                {
                    if (this.exchange1)
                    {
                        if (this.container.cont.cont1.hint2.currentFrame < 23)
                        {
                            this.container.cont.cont1.hint2.gotoAndStop((this.container.cont.cont1.hint2.currentFrame + 1));
                        }
                        else
                        {
                            this.container.cont.cont1.hint2.gotoAndStop(13);
                        }
                    }
                    else
                    {
                        if (this.container.cont.cont1.hint2.currentFrame < 23)
                        {
                            this.container.cont.cont1.hint2.gotoAndStop(23);
                        }
                        if (this.container.cont.cont1.hint2.currentFrame < this.container.cont.cont1.hint2.totalFrames)
                        {
                            this.container.cont.cont1.hint2.gotoAndStop((this.container.cont.cont1.hint2.currentFrame + 1));
                        }
                        else
                        {
                            this.container.cont.cont1.hint2.visible = false;
                        }
                    }
                }
                if (this.oldMouseMove.parent != this.tower1)
                {
                    if (this.tower1.towerCase.buttonMode)
                    {
                        (this.tower1.selectTower.counter + 1);
                        if (this.tower1.selectTower.counter <= 5)
                        {
                            this.tower1.selectTower.alpha = this.tower1.selectTower.alpha + 0.2;
                            if (this.tower1.selectTower.counter == 5)
                            {
                                this.tower1.selectTower.alpha = 1;
                            }
                        }
                        else if (this.tower1.selectTower.counter > 10)
                        {
                            if (this.tower1.selectTower.alpha > 0)
                            {
                                this.tower1.selectTower.alpha = this.tower1.selectTower.alpha - 0.0666667;
                            }
                            else
                            {
                                this.tower1.selectTower.counter = 0;
                            }
                        }
                    }
                }
                if (this.oldMouseMove.parent != this.tower2)
                {
                    if (this.exchange1)
                    {
                        (this.tower2.selectTower.counter + 1);
                        if (this.tower2.selectTower.counter <= 5)
                        {
                            this.tower2.selectTower.alpha = this.tower2.selectTower.alpha + 0.2;
                            if (this.tower2.selectTower.counter == 5)
                            {
                                this.tower2.selectTower.alpha = 1;
                            }
                        }
                        else if (this.tower2.selectTower.counter > 10)
                        {
                            if (this.tower2.selectTower.alpha > 0)
                            {
                                this.tower2.selectTower.alpha = this.tower2.selectTower.alpha - 0.0666667;
                            }
                            else
                            {
                                this.tower2.selectTower.counter = 0;
                            }
                        }
                    }
                }
            }
            if (this.tower1)
            {
                if (this.frameCounter % 2)
                {
                    if (this.tower1.currentFrame < this.tower1.totalFrames)
                    {
                        this.tower1.gotoAndStop((this.tower1.currentFrame + 1));
                    }
                    else
                    {
                        this.tower1.gotoAndStop(1);
                    }
                }
                if (this.tower1.sphere1.visible)
                {
                    if (this.tower1.sphere1.currentFrame < this.tower1.sphere1.totalFrames)
                    {
                        this.tower1.sphere1.gotoAndStop((this.tower1.sphere1.currentFrame + 1));
                    }
                    else
                    {
                        this.tower1.sphere1.gotoAndStop(1);
                    }
                    if (this.tower1.sphere1.bullet.cont.currentFrame < this.tower1.sphere1.bullet.cont.totalFrames)
                    {
                        this.tower1.sphere1.bullet.cont.gotoAndStop((this.tower1.sphere1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        this.tower1.sphere1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (!this.exchange1)
                {
                    if (this.tower1.counter < 10)
                    {
                        (this.tower1.counter + 1);
                    }
                    else
                    {
                        this.tower1.sphere1.visible = true;
                    }
                }
            }
            if (this.tower2)
            {
                if (this.frameCounter % 2)
                {
                    if (this.tower2.currentFrame < this.tower2.totalFrames)
                    {
                        this.tower2.gotoAndStop((this.tower2.currentFrame + 1));
                    }
                    else
                    {
                        this.tower2.gotoAndStop(1);
                    }
                }
                if (this.tower2.sphere1.visible)
                {
                    if (this.tower2.sphere1.currentFrame < this.tower2.sphere1.totalFrames)
                    {
                        this.tower2.sphere1.gotoAndStop((this.tower2.sphere1.currentFrame + 1));
                    }
                    else
                    {
                        this.tower2.sphere1.gotoAndStop(1);
                    }
                    if (this.tower2.sphere1.bullet.cont.currentFrame < this.tower2.sphere1.bullet.cont.totalFrames)
                    {
                        this.tower2.sphere1.bullet.cont.gotoAndStop((this.tower2.sphere1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        this.tower2.sphere1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (!this.exchange1)
                {
                    if (this.tower2.counter < 10)
                    {
                        (this.tower2.counter + 1);
                    }
                    else
                    {
                        this.tower2.sphere1.visible = true;
                    }
                }
            }
            this.i = this.listOfMoveSpheres.length - 1;
            while (this.i >= 0)
            {
                
                if (this.listOfMoveSpheres[this.i].counter > 0)
                {
                    (this.listOfMoveSpheres[this.i].counter - 1);
                    if (this.listOfMoveSpheres[this.i].counter < 4)
                    {
                        this.listOfMoveSpheres[this.i].alpha = this.listOfMoveSpheres[this.i].alpha - 0.25;
                    }
                    if (this.listOfMoveSpheres[this.i] is MoveFire_mc)
                    {
                        this.listOfMoveSpheres[this.i].x = this.listOfMoveSpheres[this.i].x + (this.tower2.x + this.tower2.towerCase.x - this.listOfMoveSpheres[this.i].x) / this.listOfMoveSpheres[this.i].counter;
                        this.listOfMoveSpheres[this.i].y = this.listOfMoveSpheres[this.i].y + (this.tower2.y + this.tower2.towerCase.y - this.listOfMoveSpheres[this.i].y) / this.listOfMoveSpheres[this.i].counter;
                    }
                    else if (this.listOfMoveSpheres[this.i] is MoveIce_mc)
                    {
                        this.listOfMoveSpheres[this.i].x = this.listOfMoveSpheres[this.i].x + (this.tower1.x + this.tower1.towerCase.x - this.listOfMoveSpheres[this.i].x) / this.listOfMoveSpheres[this.i].counter;
                        this.listOfMoveSpheres[this.i].y = this.listOfMoveSpheres[this.i].y + (this.tower1.y + this.tower1.towerCase.y - this.listOfMoveSpheres[this.i].y) / this.listOfMoveSpheres[this.i].counter;
                    }
                }
                else
                {
                    if (this.listOfMoveSpheres[this.i] is MoveFire_mc)
                    {
                        this.tower2.sphere1.bullet.gotoAndStop(1);
                        this.tower2.sphere1.bullet.cont.stop();
                    }
                    else if (this.listOfMoveSpheres[this.i] is MoveIce_mc)
                    {
                        this.tower1.sphere1.bullet.gotoAndStop(2);
                        this.tower1.sphere1.bullet.cont.stop();
                    }
                    this.container.cont.cont1.removeChild(this.listOfMoveSpheres[this.i]);
                    this.listOfMoveSpheres.splice(this.i, 1);
                }
                var _loc_2:* = this;
                var _loc_3:* = this.i - 1;
                _loc_2.i = _loc_3;
            }
            if (this.exchange1)
            {
                this.exchange1.x = this.mouseX;
                this.exchange1.y = this.mouseY;
                if (!this.exchange1.cross.visible)
                {
                    if (this.exchange1.currentFrame < this.exchange1.totalFrames)
                    {
                        this.exchange1.gotoAndStop((this.exchange1.currentFrame + 1));
                    }
                    else
                    {
                        this.exchange1.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            this.oldMouseMove = param1.target;
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
            if (param1.target.name == "towerCase")
            {
                if (param1.target.buttonMode && param1.target.parent == this.tower1)
                {
                    if (!this.tower1.selectTower.visible || this.tower1.selectTower.alpha != 1)
                    {
                        this.tower1.selectTower.counter = 5;
                        this.tower1.selectTower.alpha = 1;
                        this.tower1.selectTower.visible = true;
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
            }
            if (param1.target.name == "towerCase")
            {
                if (this.exchange1 && param1.target.parent == this.tower2)
                {
                    if (!this.tower2.selectTower.visible || this.tower2.selectTower.alpha != 1)
                    {
                        this.tower2.selectTower.counter = 5;
                        this.tower2.selectTower.alpha = 1;
                        this.tower2.selectTower.visible = true;
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
            }
            if (this.exchange1)
            {
                if (param1.target.name == "towerCase")
                {
                    if (param1.target.parent == this.tower2)
                    {
                        this.exchange1.cross.visible = false;
                    }
                    else
                    {
                        this.exchange1.cross.visible = true;
                    }
                }
                else
                {
                    this.exchange1.cross.visible = true;
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
            return;
        }// end function

        public function mouseRightDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "towerCase")
            {
                if (event.target.parent == this.tower1)
                {
                    if (event.target.buttonMode)
                    {
                        event.target.buttonMode = false;
                        this.tower1.selectTower.visible = false;
                        this.exchange = new Exchange_mc();
                        this.exchange.stop();
                        this.exchange.x = this.tower1.towerCase.x;
                        this.exchange.y = this.tower1.towerCase.y;
                        var _loc_2:* = false;
                        this.exchange.mouseChildren = false;
                        this.exchange.mouseEnabled = _loc_2;
                        this.exchange.visible = false;
                        this.tower1.addChild(this.exchange);
                        this.exchange1 = new Exchange1_mc();
                        this.exchange1.stop();
                        this.exchange1.cross.stop();
                        this.exchange1.x = this.mouseX;
                        this.exchange1.y = this.mouseY;
                        var _loc_2:* = false;
                        this.exchange1.mouseChildren = false;
                        this.exchange1.mouseEnabled = _loc_2;
                        this.addChild(this.exchange1);
                        this.container.cont.cont1.hint2.visible = true;
                        this.world.manageMouse("hide");
                    }
                }
                else if (event.target.parent == this.tower2)
                {
                    if (this.exchange)
                    {
                        this.tower1.removeChild(this.exchange);
                        this.exchange = null;
                        this.removeChild(this.exchange1);
                        this.exchange1 = null;
                        this.tower2.selectTower.visible = false;
                        this.tower1.sphere1.visible = false;
                        this.tempObject = new MoveFire_mc();
                        this.tempObject.stop();
                        this.tempObject.counter = 8;
                        this.tempObject.x = this.tower1.x + this.tower1.towerCase.x;
                        this.tempObject.y = this.tower1.y + this.tower1.towerCase.y;
                        var _loc_2:* = 0.6;
                        this.tempObject.scaleY = 0.6;
                        this.tempObject.scaleX = _loc_2;
                        this.tempObject.numTXT.visible = false;
                        this.container.cont.cont1.addChild(this.tempObject);
                        this.listOfMoveSpheres.push(this.tempObject);
                        this.tower2.sphere1.visible = false;
                        this.tempObject = new MoveIce_mc();
                        this.tempObject.stop();
                        this.tempObject.counter = 8;
                        this.tempObject.x = this.tower2.x + this.tower2.towerCase.x;
                        this.tempObject.y = this.tower2.y + this.tower2.towerCase.y;
                        var _loc_2:* = 0.6;
                        this.tempObject.scaleY = 0.6;
                        this.tempObject.scaleX = _loc_2;
                        this.tempObject.numTXT.visible = false;
                        this.container.cont.cont1.addChild(this.tempObject);
                        this.listOfMoveSpheres.push(this.tempObject);
                        this.container.cont.cont1.btnOk.visible = true;
                        this.world.manageMouse("show");
                    }
                }
            }
            return;
        }// end function

        public function mouseRightUpHandler(event:MouseEvent) : void
        {
            return;
        }// end function

        public function contStops() : void
        {
            this.container.stop();
            this.container.cont.cont1.stop();
            this.container.cont.cont1.btnOk.stop();
            this.container.cont.cont1.btnOk.okCase.stop();
            this.container.cont.cont1.hint1.stop();
            this.container.cont.cont1.hint2.stop();
            if (this.openFlag)
            {
                this.container.cont.cont1.hint1.visible = true;
                this.container.cont.cont1.hint2.visible = false;
                this.container.cont.cont1.btnOk.visible = false;
            }
            else if (this.closeFlag)
            {
                this.container.cont.cont1.hint1.visible = false;
                this.container.cont.cont1.hint2.visible = false;
                this.container.cont.cont1.btnOk.visible = true;
            }
            this.container.cont.cont1.btnOk.okCase.buttonMode = true;
            this.tempObject = false;
            if (!this.tower1)
            {
                this.tempObject = true;
            }
            else if (this.tower1.parent != this.container.cont.cont1)
            {
                this.tempObject = true;
            }
            if (this.tempObject)
            {
                this.tower1 = new Tower1_mc();
                this.tower1.stop();
                this.tower1.towerCase.stop();
                this.tower1.blockTower.stop();
                this.tower1.boneBlock.stop();
                this.tower1.sphere1.stop();
                this.tower1.sphere1.bullet.gotoAndStop(1);
                this.tower1.sphere1.bullet.cont.stop();
                this.tower1.selectTower.stop();
                this.tower1.x = -52;
                this.tower1.y = -10;
                this.tower1.counter = 0;
                this.tower1.selectTower.counter = 0;
                this.tower1.selectTower.alpha = 0;
                this.tower1.blockTower.visible = false;
                this.tower1.boneBlock.visible = false;
                this.tower1.towerCase.buttonMode = true;
                this.container.cont.cont1.addChild(this.tower1);
            }
            this.tempObject = false;
            if (!this.tower2)
            {
                this.tempObject = true;
            }
            else if (this.tower2.parent != this.container.cont.cont1)
            {
                this.tempObject = true;
            }
            if (this.tempObject)
            {
                this.tower2 = new Tower1_mc();
                this.tower2.stop();
                this.tower2.towerCase.stop();
                this.tower2.blockTower.stop();
                this.tower2.boneBlock.stop();
                this.tower2.sphere1.stop();
                this.tower2.sphere1.bullet.gotoAndStop(2);
                this.tower2.sphere1.bullet.cont.stop();
                this.tower2.selectTower.stop();
                this.tower2.x = 59;
                this.tower2.y = 63;
                this.tower2.counter = 0;
                this.tower2.selectTower.counter = 0;
                this.tower2.selectTower.alpha = 0;
                this.tower2.blockTower.visible = false;
                this.tower2.boneBlock.visible = false;
                this.container.cont.cont1.addChild(this.tower2);
            }
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
            }
            return;
        }// end function

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.removeEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
            this.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            this.removeEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            this.removeEventListener(MouseEvent.RIGHT_MOUSE_DOWN, this.mouseRightDownHandler);
            this.removeEventListener(MouseEvent.RIGHT_MOUSE_UP, this.mouseRightUpHandler);
            return;
        }// end function

    }
}
