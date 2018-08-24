package engine
{
    import flash.display.*;
    import flash.events.*;

    public class Education extends Sprite
    {
        public var i:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:MovieClip;
        public var frameCounter:int = 0;
        public var type:String;
        public var additSetting:int = 0;
        public var openFlag:Boolean;
        public var closeFlag:Boolean;
        public var world:World;
        public var counter:int = 0;

        public function Education(param1:String, param2:int = 0)
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.type = param1;
            this.additSetting = param2;
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
            if (this.type == "newEnemy")
            {
                this.openFlag = true;
                this.container = new NewEnemyInfo_mc();
                this.container.stop();
                this.container.first.stop();
                this.container.first.card.stop();
                this.container.first.card.note.stop();
                this.container.first.card.icon.stop();
                this.container.first.card.btnOk.stop();
                this.container.first.card.btnOk.okCase.setMouseEnabled(true);
                var _loc_2:* = false;
                this.container.first.setMouseChildren(false);
                this.container.first.mouseEnabled = _loc_2;
                this.addChild(this.container);
                this.prepareEnemyInfo();
            }
            AudioUtil::playSound("Snd_menu_pageScrolling.mp3");
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
            if (this.type == "newEnemy")
            {
                if (this.openFlag)
                {
                    if (this.container.first.currentFrame < this.container.first.totalFrames)
                    {
                        this.container.first.gotoAndStop((this.container.first.currentFrame + 1));
                    }
                    if (this.container.first.card.currentFrame < this.container.first.card.totalFrames)
                    {
                        this.container.first.card.gotoAndStop((this.container.first.card.currentFrame + 1));
                        this.container.first.card.icon.stop();
                        this.container.first.card.btnOk.stop();
                        this.container.first.card.btnOk.okCase.setMouseEnabled(true);
                        var _loc_2:* = false;
                        this.container.first.setMouseChildren(false);
                        this.container.first.mouseEnabled = _loc_2;
                        this.prepareEnemyInfo();
                    }
                    if (this.container.first.currentFrame == this.container.first.totalFrames && this.container.first.card.currentFrame == this.container.first.card.totalFrames)
                    {
                        this.openFlag = false;
                        var _loc_2:* = true;
                        this.container.first.setMouseChildren(true);
                        this.container.first.mouseEnabled = _loc_2;
                        this.tempObject = new Point(this.mouseX, this.mouseY);
                        this.tempObject1 = this.container.first.card.btnOk.localToGlobal(new Point(this.container.first.card.btnOk.okCase.x, this.container.first.card.btnOk.okCase.y));
                        if (this.tempObject.x > this.tempObject1.x - this.container.first.card.btnOk.okCase.width / 2 && this.tempObject.x < this.tempObject1.x + this.container.first.card.btnOk.okCase.width / 2 && this.tempObject.y > this.tempObject1.y - this.container.first.card.btnOk.okCase.height / 2 && this.tempObject.y < this.tempObject1.y + this.container.first.card.btnOk.okCase.height / 2)
                        {
                            this.container.first.card.btnOk.gotoAndStop(2);
                        }
                    }
                }
                else if (this.closeFlag)
                {
                    if (this.container.first.currentFrame > 1)
                    {
                        this.container.first.gotoAndStop((this.container.first.currentFrame - 1));
                    }
                    if (this.container.first.card.currentFrame > 1)
                    {
                        this.container.first.card.gotoAndStop((this.container.first.card.currentFrame - 1));
                        this.container.first.card.icon.stop();
                        this.container.first.card.btnOk.stop();
                        this.container.first.card.btnOk.okCase.setMouseEnabled(true);
                        var _loc_2:* = false;
                        this.container.first.setMouseChildren(false);
                        this.container.first.mouseEnabled = _loc_2;
                        this.prepareEnemyInfo();
                    }
                    if (this.container.first.currentFrame == 1 && this.container.first.card.currentFrame == 1)
                    {
                        this.closeFlag = false;
                        this.world.manageListeners("on");
                        this.world.removeChild(this);
                        this.world.menuObject = null;
                    }
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(event:MouseEvent) : void
        {
            if (this.type == "newEnemy")
            {
                if (event.target.name == "okCase")
                {
                    if (this.container.first.card.btnOk.currentFrame == 1)
                    {
                        this.container.first.card.btnOk.gotoAndStop(2);
                        AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
                    }
                }
                else if (this.container.first.card.btnOk.currentFrame == 2)
                {
                    this.container.first.card.btnOk.gotoAndStop(1);
                }
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (this.type == "newEnemy")
            {
                if (event.target.name == "okCase")
                {
                    if (this.container.first.card.btnOk.currentFrame == 2)
                    {
                        this.container.first.card.btnOk.gotoAndStop(3);
                        AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                    }
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (this.type == "newEnemy")
            {
                if (event.target.name == "okCase")
                {
                    if (this.container.first.card.btnOk.currentFrame == 3)
                    {
                        this.container.first.card.btnOk.gotoAndStop(2);
                        this.closeFlag = true;
                        var _loc_2:* = false;
                        this.container.first.setMouseChildren(false);
                        this.container.first.mouseEnabled = _loc_2;
                        AudioUtil::playSound("Snd_menu_pageScrolling.mp3");
                    }
                }
                else if (this.container.first.card.btnOk.currentFrame == 3)
                {
                    this.container.first.card.btnOk.gotoAndStop(1);
                }
            }
            return;
        }// end function

        public function prepareEnemyInfo() : void
        {
            this.container.first.card.icon.gotoAndStop(this.additSetting);
            this.tempObject = Encyclopedia.enemyInfo(this.additSetting);
            this.container.first.card.note.gotoAndStop(this.additSetting);
            this.container.first.card.nameTXT.text = this.tempObject[0];
            this.container.first.card.healthTXT.text = this.tempObject[1];
            this.container.first.card.speedTXT.text = this.tempObject[2];
            this.container.first.card.penaltyTXT.text = this.tempObject[3];
            this.container.first.card.fireResistTXT.text = this.tempObject[4];
            this.container.first.card.iceResistTXT.text = this.tempObject[5];
            this.container.first.card.stoneResistTXT.text = this.tempObject[6];
            this.container.first.card.levinResistTXT.text = this.tempObject[7];
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
