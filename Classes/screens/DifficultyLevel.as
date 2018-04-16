package screens
{
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class DifficultyLevel extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var frameCounter:int = 0;
        public var container:DeifficultyLevel_mc;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;

        public function DifficultyLevel()
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
            this.addEventListener(MouseEvent.MOUSE_DOWN, this.mouseDwonHandler);
            this.addEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            Main.mainClass.levelsMenuClass.manageListeners("off");
            this.container = new DeifficultyLevel_mc();
            this.container.stop();
            this.container.first.stop();
            this.container.first.easy.stop();
            this.container.first.normal.stop();
            this.container.first.hard.stop();
            this.container.first.easy.complexityCase.stop();
            this.container.first.normal.complexityCase.stop();
            this.container.first.hard.complexityCase.stop();
            this.container.first.easy.complexityCase.buttonMode = false;
            this.container.first.normal.complexityCase.buttonMode = false;
            this.container.first.hard.complexityCase.buttonMode = false;
            this.addChild(this.container);
            this.x = Main.SCREEN_WIDTH_HALF;
            this.y = Main.SCREEN_HEIGHT_HALF;
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
            if (this.openFlag)
            {
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                if (this.container.first.currentFrame < this.container.first.totalFrames)
                {
                    this.container.first.gotoAndStop((this.container.first.currentFrame + 1));
                    this.container.first.easy.gotoAndStop(1);
                    this.container.first.normal.gotoAndStop(1);
                    this.container.first.hard.gotoAndStop(1);
                    this.container.first.easy.complexityCase.stop();
                    this.container.first.normal.complexityCase.stop();
                    this.container.first.hard.complexityCase.stop();
                    this.container.first.easy.complexityCase.buttonMode = false;
                    this.container.first.normal.complexityCase.buttonMode = false;
                    this.container.first.hard.complexityCase.buttonMode = false;
                }
                if (this.container.currentFrame == this.container.totalFrames && this.container.first.currentFrame == this.container.first.totalFrames)
                {
                    this.openFlag = false;
                    this.container.first.easy.complexityCase.buttonMode = true;
                    this.container.first.normal.complexityCase.buttonMode = true;
                    this.container.first.hard.complexityCase.buttonMode = true;
                }
            }
            else if (this.closeFlag)
            {
                if (this.container.currentFrame > 1)
                {
                    this.container.gotoAndStop((this.container.currentFrame - 1));
                }
                if (this.container.first.currentFrame > 1)
                {
                    this.container.first.gotoAndStop((this.container.first.currentFrame - 1));
                    this.container.first.easy.gotoAndStop(1);
                    this.container.first.normal.gotoAndStop(1);
                    this.container.first.hard.gotoAndStop(1);
                    this.container.first.easy.complexityCase.stop();
                    this.container.first.normal.complexityCase.stop();
                    this.container.first.hard.complexityCase.stop();
                    this.container.first.easy.complexityCase.buttonMode = false;
                    this.container.first.normal.complexityCase.buttonMode = false;
                    this.container.first.hard.complexityCase.buttonMode = false;
                }
                if (this.container.currentFrame == 1 && this.container.first.currentFrame == 1)
                {
                    Main.mainClass.levelsMenuClass.removeChild(this);
                    Main.mainClass.levelsMenuClass.difficultyLevel = null;
                    Main.mainClass.levelsMenuClass.manageListeners("on"); 
                    Main.mainClass.levelsMenuClass.container.mouseChildren = true;
                    Main.mainClass.levelsMenuClass.container.mouseEnabled = true;
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (param1.target.parent.name == "easy")
            {
                if (param1.target.buttonMode)
                {
                    if (this.container.first.easy.currentFrame == 1)
                    {
                        this.container.first.easy.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
            }
            else if (this.container.first.easy.currentFrame == 2)
            {
                this.container.first.easy.gotoAndStop(1);
            }
            if (param1.target.parent.name == "normal")
            {
                if (param1.target.buttonMode)
                {
                    if (this.container.first.normal.currentFrame == 1)
                    {
                        this.container.first.normal.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
            }
            else if (this.container.first.normal.currentFrame == 2)
            {
                this.container.first.normal.gotoAndStop(1);
            }
            if (param1.target.parent.name == "hard")
            {
                if (param1.target.buttonMode)
                {
                    if (this.container.first.hard.currentFrame == 1)
                    {
                        this.container.first.hard.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
            }
            else if (this.container.first.hard.currentFrame == 2)
            {
                this.container.first.hard.gotoAndStop(1);
            }
            return;
        }// end function

        public function mouseDwonHandler(event:MouseEvent) : void
        {
            if (event.target.parent.name == "easy")
            {
                if (event.target.buttonMode)
                {
                    if (this.container.first.easy.currentFrame == 2)
                    {
                        this.container.first.easy.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            else if (event.target.parent.name == "normal")
            {
                if (event.target.buttonMode)
                {
                    if (this.container.first.normal.currentFrame == 2)
                    {
                        this.container.first.normal.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            else if (event.target.parent.name == "hard")
            {
                if (event.target.buttonMode)
                {
                    if (this.container.first.hard.currentFrame == 2)
                    {
                        this.container.first.hard.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (event.target.parent.name == "easy")
            {
                if (event.target.buttonMode)
                {
                    if (this.container.first.easy.currentFrame == 3)
                    {
                        this.container.first.easy.gotoAndStop(2);
                        this.closeFlag = true;
                        Main.mainClass.saveBoxClass.gameSave.data.difficultyLevel = true;
                        Main.mainClass.saveBoxClass.gameSave.data.complexityLevel = 1;
                        Sounds.instance.playSound("snd_menu_pageScrolling");
                    }
                }
            }
            else if (this.container.first.easy.currentFrame == 3)
            {
                this.container.first.easy.gotoAndStop(1);
            }
            if (event.target.parent.name == "normal")
            {
                if (event.target.buttonMode)
                {
                    if (this.container.first.normal.currentFrame == 3)
                    {
                        this.container.first.normal.gotoAndStop(2);
                        this.closeFlag = true;
                        Main.mainClass.saveBoxClass.gameSave.data.difficultyLevel = true;
                        Main.mainClass.saveBoxClass.gameSave.data.complexityLevel = 2;
                        Sounds.instance.playSound("snd_menu_pageScrolling");
                    }
                }
            }
            else if (this.container.first.normal.currentFrame == 3)
            {
                this.container.first.normal.gotoAndStop(1);
            }
            if (event.target.parent.name == "hard")
            {
                if (event.target.buttonMode)
                {
                    if (this.container.first.hard.currentFrame == 3)
                    {
                        this.container.first.hard.gotoAndStop(2);
                        this.closeFlag = true;
                        Main.mainClass.saveBoxClass.gameSave.data.difficultyLevel = true;
                        Main.mainClass.saveBoxClass.gameSave.data.complexityLevel = 3;
                        Sounds.instance.playSound("snd_menu_pageScrolling");
                    }
                }
            }
            else if (this.container.first.hard.currentFrame == 3)
            {
                this.container.first.hard.gotoAndStop(1);
            }
            return;
        }// end function

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(Main.mainClass.worldClass.mouseX, Main.mainClass.worldClass.mouseY);
            this.autoguidesObject = null;
            this.autoguidesObject_pt = this.container.first.easy.localToGlobal(new Point(this.container.first.easy.complexityCase.x, this.container.first.easy.complexityCase.y));
            this.autoguidesObjectWidth = this.container.first.easy.complexityCase.width / 2;
            this.autoguidesObjectHeight = this.container.first.easy.complexityCase.height / 2;
            if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
            {
                this.autoguidesObject = this.container.first.easy.complexityCase;
            }
            if (!this.autoguidesObject)
            {
                this.autoguidesObject_pt = this.container.first.easy.localToGlobal(new Point(this.container.first.normal.complexityCase.x, this.container.first.normal.complexityCase.y));
                this.autoguidesObjectWidth = this.container.first.normal.complexityCase.width / 2;
                this.autoguidesObjectHeight = this.container.first.normal.complexityCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.first.normal.complexityCase;
                }
            }
            if (!this.autoguidesObject)
            {
                this.autoguidesObject_pt = this.container.first.easy.localToGlobal(new Point(this.container.first.hard.complexityCase.x, this.container.first.hard.complexityCase.y));
                this.autoguidesObjectWidth = this.container.first.hard.complexityCase.width / 2;
                this.autoguidesObjectHeight = this.container.first.hard.complexityCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.first.hard.complexityCase;
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

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.removeEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
            this.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDwonHandler);
            this.removeEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            return;
        }// end function

    }
}
