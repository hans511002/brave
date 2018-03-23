package screens
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;

    public class Defeat extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:DefMenu_mc;
        public var frameCounter:int = 0;
        public var openFlag:Boolean = true;
        public var world:World;
        public var firstSoundPlay:Boolean;

        public function Defeat()
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
            Main.mainClass.stage.frameRate = 30;
            this.world = Main.mainClass.worldClass;
            this.world.manageListeners("off");
            this.world.worldInterface.breaking();
            (Main.mainClass.saveBoxClass.gameSave.data.addit_levelsDefeatCounter[(this.world.nowLevel - 1)] + 1);
            this.container = new DefMenu_mc();
            this.container.stop();
            this.container.first.stop();
            this.container.first.fire.stop();
            this.container.first.scroll.stop();
            this.container.first.scroll.btnContinue.stop();
            this.container.first.scroll.btnContinue.arrow.stop();
            this.container.first.scroll.btnRestart.stop();
            this.container.first.scroll.btnRestart.arrow.stop();
            this.container.first.scroll.btnContinue.continueCase.buttonMode = true;
            this.container.first.scroll.btnRestart.restartCase.buttonMode = true;
            var _loc_2:* = false;
            this.container.first.mouseChildren = false;
            this.container.first.mouseEnabled = _loc_2;
            this.container.first.scroll.btnContinue.arrow.visible = false;
            this.container.first.scroll.btnRestart.arrow.visible = false;
            this.container.first.scroll.btnY8.stop();
            this.container.first.scroll.btnY8.y8Case.stop();
            if (!Main.mainClass.IDIClass.isSponsor)
            {
                this.container.first.scroll.btnY8.y8Case.buttonMode = true;
            }
            this.container.first.forum.stop();
            this.container.first.forum.forumCase.stop();
            this.container.first.forum.forumCase.buttonMode = true;
            if (Main.mainClass.saveBoxClass.gameSave.data.addit_levelsDefeatCounter[(this.world.nowLevel - 1)] >= 3)
            {
                this.container.first.forum.visible = true;
            }
            else
            {
                this.container.first.forum.visible = false;
            }
            this.addChild(this.container);
            if (this.world.nowLevel <= 5)
            {
                Main.mainClass.tracker.trackPageview("defeatLevel_" + this.world.nowLevel);
            }
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
            if (!this.firstSoundPlay)
            {
                if (this.frameCounter < 10)
                {
                    if (Sounds.instance.musicChanel)
                    {
                        if (Sounds.instance.musicChanel.soundTransform.volume > 0)
                        {
                            Sounds.instance.musicChanel.soundTransform = new SoundTransform(Sounds.instance.musicChanel.soundTransform.volume - 0.1, 0);
                        }
                        else if (Sounds.instance.musicChanel.soundTransform.volume != 0)
                        {
                            Sounds.instance.musicChanel.soundTransform = new SoundTransform(0, 0);
                        }
                    }
                }
                else
                {
                    this.firstSoundPlay = true;
                    Sounds.instance.stopAll();
                    Sounds.instance.playSound("snd_menu_defeat");
                }
            }
            if (this.openFlag)
            {
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    this.container.first.gotoAndStop((this.container.first.currentFrame + 1));
                }
                else
                {
                    this.openFlag = false;
                    var _loc_2:* = true;
                    this.container.first.mouseChildren = true;
                    this.container.first.mouseEnabled = _loc_2;
                    this.tempObject = new Point(this.mouseX, this.mouseY);
                    this.tempObject1 = this.container.first.scroll.btnContinue.localToGlobal(new Point(this.container.first.scroll.btnContinue.continueCase.x, this.container.first.scroll.btnContinue.continueCase.y));
                    if (this.tempObject.x > this.tempObject1.x - this.container.first.scroll.btnContinue.continueCase.width / 2 && this.tempObject.x < this.tempObject1.x + this.container.first.scroll.btnContinue.continueCase.width / 2 && this.tempObject.y > this.tempObject1.y - this.container.first.scroll.btnContinue.continueCase.height / 2 && this.tempObject.y < this.tempObject1.y + this.container.first.scroll.btnContinue.continueCase.height / 2)
                    {
                        this.container.first.scroll.btnContinue.gotoAndStop(2);
                    }
                    this.tempObject1 = this.container.first.scroll.btnRestart.localToGlobal(new Point(this.container.first.scroll.btnRestart.restartCase.x, this.container.first.scroll.btnRestart.restartCase.y));
                    if (this.tempObject.x > this.tempObject1.x - this.container.first.scroll.btnRestart.restartCase.width / 2 && this.tempObject.x < this.tempObject1.x + this.container.first.scroll.btnRestart.restartCase.width / 2 && this.tempObject.y > this.tempObject1.y - this.container.first.scroll.btnRestart.restartCase.height / 2 && this.tempObject.y < this.tempObject1.y + this.container.first.scroll.btnRestart.restartCase.height / 2)
                    {
                        this.container.first.scroll.btnRestart.gotoAndStop(2);
                    }
                }
                if (this.container.currentFrame > 8)
                {
                    if (this.container.first.scroll.currentFrame < this.container.first.scroll.totalFrames)
                    {
                        this.container.first.scroll.gotoAndStop((this.container.first.scroll.currentFrame + 1));
                        this.container.first.scroll.btnContinue.stop();
                        this.container.first.scroll.btnContinue.arrow.stop();
                        this.container.first.scroll.btnRestart.stop();
                        this.container.first.scroll.btnRestart.arrow.stop();
                        this.container.first.scroll.btnContinue.continueCase.buttonMode = true;
                        this.container.first.scroll.btnRestart.restartCase.buttonMode = true;
                        this.container.first.scroll.btnContinue.arrow.visible = false;
                        this.container.first.scroll.btnRestart.arrow.visible = false;
                    }
                }
            }
            if (this.container.first.fire.currentFrame < this.container.first.fire.totalFrames)
            {
                this.container.first.fire.gotoAndStop((this.container.first.fire.currentFrame + 1));
            }
            else
            {
                this.container.first.fire.gotoAndStop(1);
            }
            if (this.container.first.scroll.btnContinue.currentFrame > 1)
            {
                if (!this.container.first.scroll.btnContinue.arrow.visible)
                {
                    this.container.first.scroll.btnContinue.arrow.visible = true;
                }
                else if (this.container.first.scroll.btnContinue.arrow.currentFrame < this.container.first.scroll.btnContinue.arrow.totalFrames)
                {
                    this.container.first.scroll.btnContinue.arrow.gotoAndStop((this.container.first.scroll.btnContinue.arrow.currentFrame + 1));
                }
            }
            else if (this.container.first.scroll.btnContinue.arrow.currentFrame > 1)
            {
                this.container.first.scroll.btnContinue.arrow.gotoAndStop((this.container.first.scroll.btnContinue.arrow.currentFrame - 1));
            }
            else if (this.container.first.scroll.btnContinue.arrow.visible)
            {
                this.container.first.scroll.btnContinue.arrow.visible = false;
            }
            if (this.container.first.scroll.btnRestart.currentFrame > 1)
            {
                if (!this.container.first.scroll.btnRestart.arrow.visible)
                {
                    this.container.first.scroll.btnRestart.arrow.visible = true;
                }
                else if (this.container.first.scroll.btnRestart.arrow.currentFrame < this.container.first.scroll.btnRestart.arrow.totalFrames)
                {
                    this.container.first.scroll.btnRestart.arrow.gotoAndStop((this.container.first.scroll.btnRestart.arrow.currentFrame + 1));
                }
            }
            else if (this.container.first.scroll.btnRestart.arrow.currentFrame > 1)
            {
                this.container.first.scroll.btnRestart.arrow.gotoAndStop((this.container.first.scroll.btnRestart.arrow.currentFrame - 1));
            }
            else if (this.container.first.scroll.btnRestart.arrow.visible)
            {
                this.container.first.scroll.btnRestart.arrow.visible = false;
            }
            return;
        }// end function

        public function mouseMoveHandler(event:MouseEvent) : void
        {
            if (event.target.name == "continueCase")
            {
                if (this.container.first.scroll.btnContinue.currentFrame == 1)
                {
                    this.container.first.scroll.btnContinue.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.first.scroll.btnContinue.currentFrame == 2)
            {
                this.container.first.scroll.btnContinue.gotoAndStop(1);
            }
            if (event.target.name == "restartCase")
            {
                if (this.container.first.scroll.btnRestart.currentFrame == 1)
                {
                    this.container.first.scroll.btnRestart.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.first.scroll.btnRestart.currentFrame == 2)
            {
                this.container.first.scroll.btnRestart.gotoAndStop(1);
            }
            if (this.container.first.scroll.btnY8.y8Case.buttonMode)
            {
                if (event.target.name == "y8Case")
                {
                    if (this.container.first.scroll.btnY8.currentFrame == 1)
                    {
                        this.container.first.scroll.btnY8.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.container.first.scroll.btnY8.currentFrame == 2)
                {
                    this.container.first.scroll.btnY8.gotoAndStop(1);
                }
            }
            if (event.target.name == "forumCase")
            {
                if (this.container.first.forum.currentFrame == 1)
                {
                    this.container.first.forum.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.first.forum.currentFrame == 2)
            {
                this.container.first.forum.gotoAndStop(1);
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "continueCase")
            {
                if (this.container.first.scroll.btnContinue.currentFrame == 2)
                {
                    this.container.first.scroll.btnContinue.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "restartCase")
            {
                if (this.container.first.scroll.btnRestart.currentFrame == 2)
                {
                    this.container.first.scroll.btnRestart.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "y8Case")
            {
                if (this.container.first.scroll.btnY8.currentFrame == 2)
                {
                    this.container.first.scroll.btnY8.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "forumCase")
            {
                if (this.container.first.forum.currentFrame == 2)
                {
                    this.container.first.forum.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (event.target.name == "continueCase")
            {
                if (this.container.first.scroll.btnContinue.currentFrame == 3)
                {
                    this.container.first.scroll.btnContinue.gotoAndStop(2);
                    Main.mainClass.addNewScreen("LevelsMenu");
                    Main.mainClass.testingClass = null;
                }
            }
            else if (this.container.first.scroll.btnContinue.currentFrame == 3)
            {
                this.container.first.scroll.btnContinue.gotoAndStop(1);
            }
            if (event.target.name == "restartCase")
            {
                if (this.container.first.scroll.btnRestart.currentFrame == 3)
                {
                    this.container.first.scroll.btnRestart.gotoAndStop(2);
                    Main.mainClass.addNewScreen("World");
                    Main.mainClass.testingClass = null;
                }
            }
            else if (this.container.first.scroll.btnRestart.currentFrame == 3)
            {
                this.container.first.scroll.btnRestart.gotoAndStop(1);
            }
            if (event.target.name == "y8Case")
            {
                if (this.container.first.scroll.btnY8.currentFrame == 3)
                {
                    this.container.first.scroll.btnY8.gotoAndStop(2);
                    navigateToURL(new URLRequest("http://www.y8.com/?utm_source=" + Main.mainClass.domainName + "&utm_medium=g_prelogo&utm_campaign=brave_heads"));
                }
            }
            else if (this.container.first.scroll.btnY8.currentFrame == 3)
            {
                this.container.first.scroll.btnY8.gotoAndStop(1);
            }
            if (event.target.name == "forumCase")
            {
                if (this.container.first.forum.currentFrame == 3)
                {
                    this.container.first.forum.gotoAndStop(2);
                    navigateToURL(new URLRequest("https://forum.id.net/t/brave-heads-tower-defense/1372"));
                }
            }
            else if (this.container.first.forum.currentFrame == 3)
            {
                this.container.first.forum.gotoAndStop(1);
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
