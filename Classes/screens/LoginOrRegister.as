package screens
{
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class LoginOrRegister extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var container:LoginOrRegister_mc;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var dead:Boolean;
        public var loginFlag:Boolean;
        public var transformationFlag:int = 0;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;

        public function LoginOrRegister()
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
            Main.mainClass.levelsMenuClass.openLevel.manageListeners("off");
            this.container = new LoginOrRegister_mc();
            if (Main.mainClass.IDIClass.idnet)
            {
                if (Main.mainClass.IDIClass.idnet.userData)
                {
                    this.transformationFlag = 3;
                }
            }
            this.stopAll();
            this.container.x = Main.SCREEN_WIDTH_HALF;
            this.container.y = Main.SCREEN_HEIGHT_HALF;
            var _loc_2:* = false;
            this.container.cont.setMouseChildren(false);
            this.container.cont.mouseEnabled = _loc_2;
            this.addChild(this.container);
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
                    this.container.cont.setMouseChildren(true);
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
                    Main.mainClass.levelsMenuClass.openLevel.autoguidersButtons();
                }
            }
            else if (this.loginFlag)
            {
                if (Main.mainClass.IDIClass.idnet)
                {
                    if (Main.mainClass.IDIClass.idnet.userData)
                    {
                        this.loginFlag = false;
                        this.transformationFlag = 1;
                        var _loc_2:* = false;
                        this.container.cont.setMouseChildren(false);
                        this.container.cont.mouseEnabled = _loc_2;
                    }
                }
            }
            else if (this.transformationFlag == 1)
            {
                if (this.container.cont.cont1.alpha > 0)
                {
                    this.container.cont.cont1.alpha = this.container.cont.cont1.alpha - 0.2;
                }
                else
                {
                    this.transformationFlag = 2;
                    this.container.cont.cont1.gotoAndStop(2);
                    this.stopAll();
                }
            }
            else if (this.transformationFlag == 2)
            {
                if (this.container.cont.cont1.alpha < 1)
                {
                    this.container.cont.cont1.alpha = this.container.cont.cont1.alpha + 0.2;
                }
                else
                {
                    this.transformationFlag = 3;
                    this.container.cont.cont1.alpha = 1;
                    var _loc_2:* = true;
                    this.container.cont.setMouseChildren(true);
                    this.container.cont.mouseEnabled = _loc_2;
                }
            }
            else if (this.transformationFlag == 3)
            {
            }
            else if (this.transformationFlag == 4)
            {
                if (this.container.cont.cont1.alpha > 0)
                {
                    this.container.cont.cont1.alpha = this.container.cont.cont1.alpha - 0.2;
                }
                else
                {
                    this.transformationFlag = 5;
                    this.container.cont.cont1.gotoAndStop(3);
                    this.stopAll();
                }
            }
            else if (this.transformationFlag == 5)
            {
                if (this.container.cont.cont1.alpha < 1)
                {
                    this.container.cont.cont1.alpha = this.container.cont.cont1.alpha + 0.2;
                }
                else
                {
                    this.transformationFlag = 6;
                    this.container.cont.cont1.alpha = 1;
                    var _loc_2:* = true;
                    this.container.cont.setMouseChildren(true);
                    this.container.cont.mouseEnabled = _loc_2;
                    if (Main.mainClass.saveBoxClass.gameSave.data.saveNo == 1)
                    {
                        Main.mainClass.saveBoxClass.synchronizationLocalToSite(1);
                        Main.mainClass.saveBoxClass.checkSaves(4);
                    }
                    else if (Main.mainClass.saveBoxClass.gameSave.data.saveNo == 2)
                    {
                        Main.mainClass.saveBoxClass.synchronizationLocalToSite(2);
                        Main.mainClass.saveBoxClass.checkSaves(5);
                    }
                    else if (Main.mainClass.saveBoxClass.gameSave.data.saveNo == 3)
                    {
                        Main.mainClass.saveBoxClass.synchronizationLocalToSite(3);
                        Main.mainClass.saveBoxClass.checkSaves(6);
                    }
                    Main.mainClass.levelsMenuClass.openLevel.complexityManage(4);
                    Main.mainClass.levelsMenuClass.container.freeStars.visible = true;
                    Main.mainClass.levelsMenuClass.container.freeStars.cont.starsTXT.text = Main.mainClass.saveBoxClass.gameSave.data.stars;
                    Main.mainClass.levelsMenuClass.container.freeStars.cont.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (param1.target.name == "loginCase")
            {
                if (this.container.cont.cont1.login.currentFrame == 1)
                {
                    this.container.cont.cont1.login.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.cont1.login)
            {
                if (this.container.cont.cont1.login.currentFrame == 2)
                {
                    this.container.cont.cont1.login.gotoAndStop(1);
                }
            }
            if (param1.target.name == "registerCase")
            {
                if (this.container.cont.cont1.register.currentFrame == 1)
                {
                    this.container.cont.cont1.register.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.cont1.register)
            {
                if (this.container.cont.cont1.register.currentFrame == 2)
                {
                    this.container.cont.cont1.register.gotoAndStop(1);
                }
            }
            if (param1.target.name == "yesCase")
            {
                if (this.container.cont.cont1.yes.currentFrame == 1)
                {
                    this.container.cont.cont1.yes.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.cont1.yes)
            {
                if (this.container.cont.cont1.yes.currentFrame == 2)
                {
                    this.container.cont.cont1.yes.gotoAndStop(1);
                }
            }
            if (param1.target.name == "noCase")
            {
                if (this.container.cont.cont1.no.currentFrame == 1)
                {
                    this.container.cont.cont1.no.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.cont1.no)
            {
                if (this.container.cont.cont1.no.currentFrame == 2)
                {
                    this.container.cont.cont1.no.gotoAndStop(1);
                }
            }
            if (param1.target.name == "okCase")
            {
                if (this.container.cont.cont1.ok.currentFrame == 1)
                {
                    this.container.cont.cont1.ok.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.cont1.ok)
            {
                if (this.container.cont.cont1.ok.currentFrame == 2)
                {
                    this.container.cont.cont1.ok.gotoAndStop(1);
                }
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (!this.openFlag && !this.closeFlag)
            {
                if (event.target.name == "loginCase")
                {
                    if (this.container.cont.cont1.login.currentFrame == 2)
                    {
                        this.container.cont.cont1.login.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "registerCase")
                {
                    if (this.container.cont.cont1.register.currentFrame == 2)
                    {
                        this.container.cont.cont1.register.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "yesCase")
                {
                    if (this.container.cont.cont1.yes.currentFrame == 2)
                    {
                        this.container.cont.cont1.yes.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "noCase")
                {
                    if (this.container.cont.cont1.no.currentFrame == 2)
                    {
                        this.container.cont.cont1.no.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "okCase")
                {
                    if (this.container.cont.cont1.ok.currentFrame == 2)
                    {
                        this.container.cont.cont1.ok.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "shadow")
                {
                    this.close();
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (event.target.name == "loginCase")
            {
                if (this.container.cont.cont1.login.currentFrame == 3)
                {
                    this.container.cont.cont1.login.gotoAndStop(2);
                    this.loginFlag = true;
                    if (Main.mainClass.IDIClass.idnet)
                    {
                        Main.mainClass.IDIClass.idnet.toggleInterface();
                    }
                }
            }
            else if (this.container.cont.cont1.login)
            {
                if (this.container.cont.cont1.login.currentFrame == 3)
                {
                    this.container.cont.cont1.login.gotoAndStop(1);
                }
            }
            if (event.target.name == "registerCase")
            {
                if (this.container.cont.cont1.register.currentFrame == 3)
                {
                    this.container.cont.cont1.register.gotoAndStop(2);
                    this.loginFlag = true;
                    if (Main.mainClass.IDIClass.idnet)
                    {
                        Main.mainClass.IDIClass.idnet.toggleInterface("registration");
                    }
                }
            }
            else if (this.container.cont.cont1.register)
            {
                if (this.container.cont.cont1.register.currentFrame == 3)
                {
                    this.container.cont.cont1.register.gotoAndStop(1);
                }
            }
            if (event.target.name == "yesCase")
            {
                if (this.container.cont.cont1.yes.currentFrame == 3)
                {
                    this.container.cont.cont1.yes.gotoAndStop(2);
                    this.transformationFlag = 4;
                    var _loc_2:* = false;
                    this.container.cont.setMouseChildren(false);
                    this.container.cont.mouseEnabled = _loc_2;
                }
            }
            else if (this.container.cont.cont1.yes)
            {
                if (this.container.cont.cont1.yes.currentFrame == 3)
                {
                    this.container.cont.cont1.yes.gotoAndStop(1);
                }
            }
            if (event.target.name == "noCase")
            {
                if (this.container.cont.cont1.no.currentFrame == 3)
                {
                    this.container.cont.cont1.no.gotoAndStop(2);
                    this.close();
                }
            }
            else if (this.container.cont.cont1.no)
            {
                if (this.container.cont.cont1.no.currentFrame == 3)
                {
                    this.container.cont.cont1.no.gotoAndStop(1);
                }
            }
            if (event.target.name == "okCase")
            {
                if (this.container.cont.cont1.ok.currentFrame == 3)
                {
                    this.container.cont.cont1.ok.gotoAndStop(2);
                    this.close();
                }
            }
            else if (this.container.cont.cont1.ok)
            {
                if (this.container.cont.cont1.ok.currentFrame == 3)
                {
                    this.container.cont.cont1.ok.gotoAndStop(1);
                }
            }
            return;
        }// end function

        public function stopAll() : void
        {
            this.container.stop();
            this.container.cont.stop();
            if (this.transformationFlag == 0)
            {
                this.container.cont.cont1.gotoAndStop(1);
            }
            else if (this.transformationFlag <= 3)
            {
                this.container.cont.cont1.gotoAndStop(2);
            }
            else
            {
                this.container.cont.cont1.gotoAndStop(3);
            }
            if (this.container.cont.cont1.login)
            {
                this.container.cont.cont1.login.stop();
                this.container.cont.cont1.login.loginCase.stop();
                this.container.cont.cont1.login.loginCase.setMouseEnabled(true);
            }
            if (this.container.cont.cont1.register)
            {
                this.container.cont.cont1.register.stop();
                this.container.cont.cont1.register.registerCase.stop();
                this.container.cont.cont1.register.registerCase.setMouseEnabled(true);
            }
            if (this.container.cont.cont1.yes)
            {
                this.container.cont.cont1.yes.stop();
                this.container.cont.cont1.yes.yesCase.stop();
                this.container.cont.cont1.yes.yesCase.setMouseEnabled(true);
            }
            if (this.container.cont.cont1.no)
            {
                this.container.cont.cont1.no.stop();
                this.container.cont.cont1.no.noCase.stop();
                this.container.cont.cont1.no.noCase.setMouseEnabled(true);
            }
            if (this.container.cont.cont1.ok)
            {
                this.container.cont.cont1.ok.stop();
                this.container.cont.cont1.ok.okCase.stop();
                this.container.cont.cont1.ok.okCase.setMouseEnabled(true);
            }
            return;
        }// end function

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(this.mouseX, this.mouseY);
            this.autoguidesObject = null;
            if (!this.autoguidesObject && this.container.cont.cont1.login)
            {
                this.autoguidesObject_pt = this.container.cont.cont1.login.localToGlobal(new Point(this.container.cont.cont1.login.loginCase.x, this.container.cont.cont1.login.loginCase.y));
                this.autoguidesObjectWidth = this.container.cont.cont1.login.loginCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.cont1.login.loginCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.cont1.login.loginCase;
                }
            }
            if (!this.autoguidesObject && this.container.cont.cont1.register)
            {
                this.autoguidesObject_pt = this.container.cont.cont1.register.localToGlobal(new Point(this.container.cont.cont1.register.registerCase.x, this.container.cont.cont1.register.registerCase.y));
                this.autoguidesObjectWidth = this.container.cont.cont1.register.registerCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.cont1.register.registerCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.cont1.register.registerCase;
                }
            }
            if (!this.autoguidesObject && this.container.cont.cont1.yes)
            {
                this.autoguidesObject_pt = this.container.cont.cont1.yes.localToGlobal(new Point(this.container.cont.cont1.yes.yesCase.x, this.container.cont.cont1.yes.yesCase.y));
                this.autoguidesObjectWidth = this.container.cont.cont1.yes.yesCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.cont1.yes.yesCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.cont1.yes.yesCase;
                }
            }
            if (!this.autoguidesObject && this.container.cont.cont1.no)
            {
                this.autoguidesObject_pt = this.container.cont.cont1.no.localToGlobal(new Point(this.container.cont.cont1.no.noCase.x, this.container.cont.cont1.no.noCase.y));
                this.autoguidesObjectWidth = this.container.cont.cont1.no.noCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.cont1.no.noCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.cont1.no.noCase;
                }
            }
            if (!this.autoguidesObject && this.container.cont.cont1.ok)
            {
                this.autoguidesObject_pt = this.container.cont.cont1.ok.localToGlobal(new Point(this.container.cont.cont1.ok.okCase.x, this.container.cont.cont1.ok.okCase.y));
                this.autoguidesObjectWidth = this.container.cont.cont1.ok.okCase.width / 2;
                this.autoguidesObjectHeight = this.container.cont.cont1.ok.okCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.cont.cont1.ok.okCase;
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
                this.container.cont.setMouseChildren(false);
                this.container.cont.mouseEnabled = _loc_1;
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                Main.mainClass.levelsMenuClass.openLevel.removeChild(this);
                Main.mainClass.levelsMenuClass.openLevel.loginOrRegisterClass = null;
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
            Main.mainClass.levelsMenuClass.openLevel.manageListeners("on");
            return;
        }// end function

    }
}
