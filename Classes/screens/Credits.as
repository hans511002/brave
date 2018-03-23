package screens
{
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class Credits extends Sprite
    {
        public var i:int;
        public var tempObject:Object;
        public var container:Credits_mc;
        public var frameCounter:int = 0;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var dead:Boolean;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;

        public function Credits()
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
            this.container = new Credits_mc();
            this.stopManage();
            var _loc_2:* = false;
            this.container.cont.mouseChildren = false;
            this.container.cont.mouseEnabled = _loc_2;
            this.addChild(this.container);
            return;
        }// end function

        public function stopManage() : void
        {
            this.container.stop();
            this.container.cont.stop();
            this.container.cont.logoCont.stop();
            this.container.cont.noteCont.stop();
            this.container.cont.noteCont.stop();
            this.container.cont.facebook.stop();
            this.container.cont.twitter.stop();
            this.container.cont.btnOk.stop();
            this.container.cont.logoCont.logoContCase.stop();
            this.container.cont.noteCont.noteContCase.stop();
            this.container.cont.facebook.facebookCase.stop();
            this.container.cont.twitter.twitterCase.stop();
            this.container.cont.btnOk.okCase.stop();
            this.container.cont.logoCont.logoContCase.buttonMode = true;
            this.container.cont.noteCont.noteContCase.buttonMode = true;
            this.container.cont.facebook.facebookCase.buttonMode = true;
            this.container.cont.twitter.twitterCase.buttonMode = true;
            this.container.cont.btnOk.okCase.buttonMode = true;
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
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                if (this.container.cont.currentFrame < this.container.cont.totalFrames)
                {
                    this.container.cont.gotoAndStop((this.container.cont.currentFrame + 1));
                }
                this.stopManage();
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
                this.stopManage();
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
            if (param1.target.name == "logoContCase")
            {
                if (this.container.cont.logoCont.currentFrame == 1)
                {
                    this.container.cont.logoCont.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.logoCont.currentFrame == 2)
            {
                this.container.cont.logoCont.gotoAndStop(1);
            }
            if (param1.target.name == "noteContCase")
            {
                if (this.container.cont.noteCont.currentFrame == 1)
                {
                    this.container.cont.noteCont.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.noteCont.currentFrame == 2)
            {
                this.container.cont.noteCont.gotoAndStop(1);
            }
            if (param1.target.name == "facebookCase")
            {
                if (this.container.cont.facebook.currentFrame == 1)
                {
                    this.container.cont.facebook.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.facebook.currentFrame == 2)
            {
                this.container.cont.facebook.gotoAndStop(1);
            }
            if (param1.target.name == "twitterCase")
            {
                if (this.container.cont.twitter.currentFrame == 1)
                {
                    this.container.cont.twitter.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.twitter.currentFrame == 2)
            {
                this.container.cont.twitter.gotoAndStop(1);
            }
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
            if (event.target.name == "logoContCase")
            {
                if (this.container.cont.logoCont.currentFrame == 2)
                {
                    this.container.cont.logoCont.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "noteContCase")
            {
                if (this.container.cont.noteCont.currentFrame == 2)
                {
                    this.container.cont.noteCont.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "facebookCase")
            {
                if (this.container.cont.facebook.currentFrame == 2)
                {
                    this.container.cont.facebook.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "twitterCase")
            {
                if (this.container.cont.twitter.currentFrame == 2)
                {
                    this.container.cont.twitter.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "okCase")
            {
                if (this.container.cont.btnOk.currentFrame == 2)
                {
                    this.container.cont.btnOk.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "shadow")
            {
                if (!this.openFlag && !this.closeFlag)
                {
                    this.close();
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (event.target.name == "logoContCase")
            {
                if (this.container.cont.logoCont.currentFrame == 3)
                {
                    this.container.cont.logoCont.gotoAndStop(2);
                    navigateToURL(new URLRequest("http://www.hammersongames.com"));
                }
            }
            else if (this.container.cont.logoCont.currentFrame == 3)
            {
                this.container.cont.logoCont.gotoAndStop(1);
            }
            if (event.target.name == "noteContCase")
            {
                if (this.container.cont.noteCont.currentFrame == 3)
                {
                    this.container.cont.noteCont.gotoAndStop(2);
                    navigateToURL(new URLRequest("http://www.hammersongames.com"));
                }
            }
            else if (this.container.cont.noteCont.currentFrame == 3)
            {
                this.container.cont.noteCont.gotoAndStop(1);
            }
            if (event.target.name == "facebookCase")
            {
                if (this.container.cont.facebook.currentFrame == 3)
                {
                    this.container.cont.facebook.gotoAndStop(2);
                    navigateToURL(new URLRequest("http://www.facebook.com/HammersonGames"));
                }
            }
            else if (this.container.cont.facebook.currentFrame == 3)
            {
                this.container.cont.facebook.gotoAndStop(1);
            }
            if (event.target.name == "twitterCase")
            {
                if (this.container.cont.twitter.currentFrame == 3)
                {
                    this.container.cont.twitter.gotoAndStop(2);
                    navigateToURL(new URLRequest("http://twitter.com/hammersongames"));
                }
            }
            else if (this.container.cont.twitter.currentFrame == 3)
            {
                this.container.cont.twitter.gotoAndStop(1);
            }
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

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(this.mouseX, this.mouseY);
            this.autoguidesObject = null;
            this.autoguidesObject_pt = this.container.cont.logoCont.localToGlobal(new Point(this.container.cont.logoCont.logoContCase.x, this.container.cont.logoCont.logoContCase.y));
            this.autoguidesObjectWidth = this.container.cont.logoCont.logoContCase.width / 2;
            this.autoguidesObjectHeight = this.container.cont.logoCont.logoContCase.height / 2;
            if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
            {
                this.autoguidesObject = this.container.cont.logoCont.logoContCase;
            }
            if (!this.autoguidesObject)
            {
                this.autoguidesObject_pt = this.container.cont.noteCont.localToGlobal(new Point(this.container.cont.noteCont.noteContCase.x, this.container.cont.noteCont.noteContCase.y));
                this.autoguidesObjectWidth = this.container.cont.noteCont.noteContCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.noteCont.noteContCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.noteCont.noteContCase;
                }
            }
            if (!this.autoguidesObject)
            {
                this.autoguidesObject_pt = this.container.cont.facebook.localToGlobal(new Point(this.container.cont.facebook.facebookCase.x, this.container.cont.facebook.facebookCase.y));
                this.autoguidesObjectWidth = this.container.cont.facebook.facebookCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.facebook.facebookCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.facebook.facebookCase;
                }
            }
            if (!this.autoguidesObject)
            {
                this.autoguidesObject_pt = this.container.cont.twitter.localToGlobal(new Point(this.container.cont.twitter.twitterCase.x, this.container.cont.twitter.twitterCase.y));
                this.autoguidesObjectWidth = this.container.cont.twitter.twitterCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.twitter.twitterCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.twitter.twitterCase;
                }
            }
            if (!this.autoguidesObject)
            {
                this.autoguidesObject_pt = this.container.cont.btnOk.localToGlobal(new Point(this.container.cont.btnOk.okCase.x, this.container.cont.btnOk.okCase.y));
                this.autoguidesObjectWidth = this.container.cont.btnOk.okCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.btnOk.okCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.btnOk.okCase;
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
            this.closeFlag = true;
            var _loc_1:* = false;
            this.container.cont.mouseChildren = false;
            this.container.cont.mouseEnabled = _loc_1;
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                Main.mainClass.startMenuClass.removeChild(this);
                Main.mainClass.startMenuClass.creditsClass = null;
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
