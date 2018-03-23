package screens
{
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class StartMenu extends Sprite
    {
        public var i:int;
        public var tempObject:Object;
        public var frameCounter:int = 0;
        public var container:StartMenu_mc;
        public var firstPlay:Boolean;
        public var page:int = 1;
        public var question:int = 0;
        public var creditsClass:Credits;
        public var loginFlag:Boolean;
        public var loginFlag1:int = 0;
        public var welcomeText:String = "";
        public var nickText:String = "";
        public var waitCounter:int = 0;
        public var syncLoginCounter:int = 0;
        public var syncHint:Hint_mc;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;
        public static var firstMusicPlay:Boolean;

        public function StartMenu()
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.container = new StartMenu_mc();
            this.container.stop();
            this.container.logOut.stop();
            this.container.logo.stop();
            this.container.start.stop();
            this.container.credits.stop();
            this.container.btnMusic.stop();
            this.container.btnSound.stop();
            this.container.back.stop();
            this.container.logOut.buttonMode = true;
            this.container.btnMusic.musicCase.buttonMode = true;
            this.container.btnSound.soundCase.buttonMode = true;
            this.container.back.backCase.buttonMode = true;
            this.container.back.visible = false;
            this.container.btnY8.stop();
            this.container.btnIdnet.stop();
            this.container.btnY8.y8Case.stop();
            this.container.btnIdnet.idnetCase.stop();
            if (!Main.mainClass.IDIClass.isSponsor)
            {
                this.container.btnY8.y8Case.buttonMode = true;
            }
            this.container.btnIdnet.idnetCase.buttonMode = true;
            this.container.logOut.visible = false;
            this.addChild(this.container);
            if (Sounds.instance.musicOn)
            {
                this.container.btnMusic.gotoAndStop(1);
            }
            else
            {
                this.container.btnMusic.gotoAndStop(4);
            }
            if (Sounds.instance.soundOn)
            {
                this.container.btnSound.gotoAndStop(1);
            }
            else
            {
                this.container.btnSound.gotoAndStop(4);
            }
            if (!Main.mainClass.middleScreenClass)
            {
                this.firstPlay = true;
                Main.mainClass.bmp = new Bitmap(Main.mainClass.getBitmapData(this));
                Main.mainClass.bmp.alpha = 0;
                this.addChild(Main.mainClass.bmp);
                this.container.visible = false;
                this.manageListeners("on");
            }
            if (!StartMenu.firstMusicPlay)
            {
                StartMenu.firstMusicPlay = true;
                Sounds.instance.playMusic(0);
            }
            if (Main.mainClass.lastClass == "LevelsMenu")
            {
                this.container.gotoAndStop(53);
                if (Main.mainClass.saveBoxClass.gameSave.data.type == "site")
                {
                    this.page = 4;
                    this.waitCounter = 0;
                    Main.mainClass.saveBoxClass.gameSave4.data.haveSave = false;
                    Main.mainClass.saveBoxClass.gameSave5.data.haveSave = false;
                    Main.mainClass.saveBoxClass.gameSave6.data.haveSave = false;
                    Main.mainClass.IDIClass.getData(4);
                    Main.mainClass.IDIClass.getData(5);
                    Main.mainClass.IDIClass.getData(6);
                }
                else
                {
                    this.page = 3;
                }
                this.container.back.visible = true;
            }
            var _loc_2:* = false;
            this.container.mouseChildren = false;
            this.container.mouseEnabled = _loc_2;
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
            if (this.container.glitter)
            {
                if (this.container.glitter.currentFrame < this.container.glitter.totalFrames)
                {
                    this.container.glitter.gotoAndStop((this.container.glitter.currentFrame + 1));
                }
                else
                {
                    this.container.glitter.gotoAndStop(1);
                }
            }
            if (this.firstPlay)
            {
                if (Main.mainClass.bmp.alpha < 1)
                {
                    Main.mainClass.bmp.alpha = Main.mainClass.bmp.alpha + 0.2;
                }
                else
                {
                    this.firstPlay = false;
                    this.container.visible = true;
                    this.removeChild(Main.mainClass.bmp);
                    Main.mainClass.bmp = null;
                }
            }
            else
            {
                if (this.page == 1)
                {
                    if (this.container.currentFrame < 28)
                    {
                        this.container.gotoAndStop((this.container.currentFrame + 1));
                        if (this.container.currentFrame == 9)
                        {
                            this.container.glitter.stop();
                        }
                        else if (this.container.currentFrame == 28)
                        {
                            this.container.start.startCase.buttonMode = true;
                            this.container.credits.creditsCase.buttonMode = true;
                            var _loc_2:* = true;
                            this.container.mouseChildren = true;
                            this.container.mouseEnabled = _loc_2;
                            this.container.back.visible = false;
                            this.autoguidersButtons();
                        }
                    }
                    else if (this.container.currentFrame > 28)
                    {
                        this.container.gotoAndStop((this.container.currentFrame - 1));
                        if (this.container.currentFrame == 33)
                        {
                            this.container.start.stop();
                            this.container.credits.stop();
                        }
                        else if (this.container.currentFrame == 28)
                        {
                            this.container.start.startCase.buttonMode = true;
                            this.container.credits.creditsCase.buttonMode = true;
                            var _loc_2:* = true;
                            this.container.mouseChildren = true;
                            this.container.mouseEnabled = _loc_2;
                            this.container.back.visible = false;
                            this.autoguidersButtons();
                        }
                    }
                }
                else if (this.page == 2)
                {
                    if (this.container.currentFrame < 44)
                    {
                        this.container.gotoAndStop((this.container.currentFrame + 1));
                        if (this.container.currentFrame == 35)
                        {
                            this.container.saveType.stop();
                            this.container.saveType.localSave.stop();
                            this.container.saveType.onlineSave.stop();
                            this.container.saveType.localSave.localSaveCase.stop();
                            this.container.saveType.onlineSave.onlineSaveCase.stop();
                            if (Main.mainClass.IDIClass.idnet)
                            {
                                if (Main.mainClass.IDIClass.idnet.userData)
                                {
                                    this.container.saveType.onlineSave.welcomeTXT.text = "Welcome,";
                                    this.container.saveType.onlineSave.nickTXT.text = Main.mainClass.IDIClass.currentUser + "!";
                                }
                                else
                                {
                                    this.container.saveType.onlineSave.welcomeTXT.text = "登录使用在线存档";
                                    this.container.saveType.onlineSave.nickTXT.text = "";
                                }
                                this.welcomeText = this.container.saveType.onlineSave.welcomeTXT.text;
                                this.nickText = this.container.saveType.onlineSave.nickTXT.text;
                                this.container.saveType.onlineSave.nickTXT.setTextFormat(Main.mainClass.boldTextFormat);
                            }
                            this.container.saveType.localSave.localSaveCase.buttonMode = true;
                            this.container.saveType.onlineSave.onlineSaveCase.buttonMode = true;
                            this.container.back.visible = true;
                        }
                        else if (this.container.currentFrame == 44)
                        {
                            var _loc_2:* = true;
                            this.container.mouseChildren = true;
                            this.container.mouseEnabled = _loc_2;
                            this.autoguidersButtons();
                        }
                    }
                    else if (this.container.currentFrame > 44)
                    {
                        this.container.gotoAndStop((this.container.currentFrame - 1));
                        if (this.container.currentFrame == 53)
                        {
                            this.container.gotoAndStop(34);
                        }
                    }
                }
                else if (this.page == 3 || this.page == 4)
                {
                    if (this.page == 3 || this.waitCounter == 3)
                    {
                        if (this.container.currentFrame < 79)
                        {
                            this.container.gotoAndStop((this.container.currentFrame + 1));
                            if (this.container.currentFrame == 54)
                            {
                                if (this.page == 3)
                                {
                                    if (!Main.mainClass.saveBoxClass.gameSave1.data.haveSave)
                                    {
                                        this.container.game1.gotoAndStop(4);
                                        this.container.game1.newGame1Case.stop();
                                        this.container.game1.newGame1Case.buttonMode = true;
                                    }
                                    else
                                    {
                                        this.container.game1.gotoAndStop(1);
                                        this.container.game1.game1Case.stop();
                                        this.container.game1.game1Case.buttonMode = true;
                                        this.container.game1.syncSlot.stop();
                                        this.container.game1.syncSlot.syncSlotCase.stop();
                                        this.container.game1.syncSlot.syncSlotCase.buttonMode = true;
                                        if (Main.mainClass.IDIClass.idnet)
                                        {
                                            if (!Main.mainClass.IDIClass.idnet.userData)
                                            {
                                                this.container.game1.syncSlot.gotoAndStop(1);
                                            }
                                            else
                                            {
                                                this.container.game1.syncSlot.gotoAndStop(4);
                                            }
                                        }
                                        else
                                        {
                                            this.container.game1.syncSlot.visible = false;
                                        }
                                        this.container.game1.deleteSlot.stop();
                                        this.container.game1.deleteSlot.deleteSlotCase.stop();
                                        this.container.game1.deleteSlot.deleteSlotCase.buttonMode = true;
                                        this.tempObject = 0;
                                        this.i = 0;
                                        while (this.i < Main.mainClass.saveBoxClass.gameSave1.data.starsOfLevels.length)
                                        {
                                            
                                            this.tempObject = this.tempObject + Main.mainClass.saveBoxClass.gameSave1.data.starsOfLevels[this.i];
                                            var _loc_2:* = this;
                                            var _loc_3:* = this.i + 1;
                                            _loc_2.i = _loc_3;
                                        }
                                        this.container.game1.numTXT.text = this.tempObject + "/" + Main.mainClass.saveBoxClass.maxStars;
                                        this.container.game1.numTXT.setTextFormat(Main.mainClass.boldTextFormat);
                                    }
                                    if (!Main.mainClass.saveBoxClass.gameSave2.data.haveSave)
                                    {
                                        this.container.game2.gotoAndStop(4);
                                        this.container.game2.newGame2Case.stop();
                                        this.container.game2.newGame2Case.buttonMode = true;
                                    }
                                    else
                                    {
                                        this.container.game2.gotoAndStop(1);
                                        this.container.game2.game2Case.stop();
                                        this.container.game2.game2Case.buttonMode = true;
                                        this.container.game2.syncSlot.stop();
                                        this.container.game2.syncSlot.syncSlotCase.stop();
                                        this.container.game2.syncSlot.syncSlotCase.buttonMode = true;
                                        if (Main.mainClass.IDIClass.idnet)
                                        {
                                            if (!Main.mainClass.IDIClass.idnet.userData)
                                            {
                                                this.container.game2.syncSlot.gotoAndStop(1);
                                            }
                                            else
                                            {
                                                this.container.game2.syncSlot.gotoAndStop(4);
                                            }
                                        }
                                        else
                                        {
                                            this.container.game2.syncSlot.visible = false;
                                        }
                                        this.container.game2.deleteSlot.stop();
                                        this.container.game2.deleteSlot.deleteSlotCase.stop();
                                        this.container.game2.deleteSlot.deleteSlotCase.buttonMode = true;
                                        this.tempObject = 0;
                                        this.i = 0;
                                        while (this.i < Main.mainClass.saveBoxClass.gameSave2.data.starsOfLevels.length)
                                        {
                                            
                                            this.tempObject = this.tempObject + Main.mainClass.saveBoxClass.gameSave2.data.starsOfLevels[this.i];
                                            var _loc_2:* = this;
                                            var _loc_3:* = this.i + 1;
                                            _loc_2.i = _loc_3;
                                        }
                                        this.container.game2.numTXT.text = this.tempObject + "/" + Main.mainClass.saveBoxClass.maxStars;
                                        this.container.game2.numTXT.setTextFormat(Main.mainClass.boldTextFormat);
                                    }
                                    if (!Main.mainClass.saveBoxClass.gameSave3.data.haveSave)
                                    {
                                        this.container.game3.gotoAndStop(4);
                                        this.container.game3.newGame3Case.stop();
                                        this.container.game3.newGame3Case.buttonMode = true;
                                    }
                                    else
                                    {
                                        this.container.game3.gotoAndStop(1);
                                        this.container.game3.game3Case.stop();
                                        this.container.game3.game3Case.buttonMode = true;
                                        this.container.game3.syncSlot.stop();
                                        this.container.game3.syncSlot.syncSlotCase.stop();
                                        this.container.game3.syncSlot.syncSlotCase.buttonMode = true;
                                        if (Main.mainClass.IDIClass.idnet)
                                        {
                                            if (!Main.mainClass.IDIClass.idnet.userData)
                                            {
                                                this.container.game3.syncSlot.gotoAndStop(1);
                                            }
                                            else
                                            {
                                                this.container.game3.syncSlot.gotoAndStop(4);
                                            }
                                        }
                                        else
                                        {
                                            this.container.game3.syncSlot.visible = false;
                                        }
                                        this.container.game3.deleteSlot.stop();
                                        this.container.game3.deleteSlot.deleteSlotCase.stop();
                                        this.container.game3.deleteSlot.deleteSlotCase.buttonMode = true;
                                        this.tempObject = 0;
                                        this.i = 0;
                                        while (this.i < Main.mainClass.saveBoxClass.gameSave3.data.starsOfLevels.length)
                                        {
                                            
                                            this.tempObject = this.tempObject + Main.mainClass.saveBoxClass.gameSave3.data.starsOfLevels[this.i];
                                            var _loc_2:* = this;
                                            var _loc_3:* = this.i + 1;
                                            _loc_2.i = _loc_3;
                                        }
                                        this.container.game3.numTXT.text = this.tempObject + "/" + Main.mainClass.saveBoxClass.maxStars;
                                        this.container.game3.numTXT.setTextFormat(Main.mainClass.boldTextFormat);
                                    }
                                }
                                else if (this.page == 4)
                                {
                                    if (!Main.mainClass.saveBoxClass.gameSave4.data.haveSave)
                                    {
                                        this.container.game1.gotoAndStop(4);
                                        this.container.game1.newGame1Case.stop();
                                        this.container.game1.newGame1Case.buttonMode = true;
                                    }
                                    else
                                    {
                                        this.container.game1.gotoAndStop(1);
                                        this.container.game1.game1Case.stop();
                                        this.container.game1.game1Case.buttonMode = true;
                                        this.container.game1.syncSlot.stop();
                                        this.container.game1.syncSlot.syncSlotCase.stop();
                                        this.container.game1.syncSlot.syncSlotCase.buttonMode = true;
                                        this.container.game1.syncSlot.visible = false;
                                        this.container.game1.deleteSlot.stop();
                                        this.container.game1.deleteSlot.deleteSlotCase.stop();
                                        this.container.game1.deleteSlot.deleteSlotCase.buttonMode = true;
                                        this.tempObject = 0;
                                        this.i = 0;
                                        while (this.i < Main.mainClass.saveBoxClass.gameSave4.data.starsOfLevels.length)
                                        {
                                            
                                            this.tempObject = this.tempObject + Main.mainClass.saveBoxClass.gameSave4.data.starsOfLevels[this.i];
                                            var _loc_2:* = this;
                                            var _loc_3:* = this.i + 1;
                                            _loc_2.i = _loc_3;
                                        }
                                        this.tempObject = this.tempObject + 3;
                                        this.container.game1.numTXT.text = this.tempObject + "/" + Main.mainClass.saveBoxClass.maxStars;
                                        this.container.game1.numTXT.setTextFormat(Main.mainClass.boldTextFormat);
                                    }
                                    if (!Main.mainClass.saveBoxClass.gameSave5.data.haveSave)
                                    {
                                        this.container.game2.gotoAndStop(4);
                                        this.container.game2.newGame2Case.stop();
                                        this.container.game2.newGame2Case.buttonMode = true;
                                    }
                                    else
                                    {
                                        this.container.game2.gotoAndStop(1);
                                        this.container.game2.game2Case.stop();
                                        this.container.game2.game2Case.buttonMode = true;
                                        this.container.game2.syncSlot.stop();
                                        this.container.game2.syncSlot.syncSlotCase.stop();
                                        this.container.game2.syncSlot.syncSlotCase.buttonMode = true;
                                        this.container.game2.syncSlot.visible = false;
                                        this.container.game2.deleteSlot.stop();
                                        this.container.game2.deleteSlot.deleteSlotCase.stop();
                                        this.container.game2.deleteSlot.deleteSlotCase.buttonMode = true;
                                        this.tempObject = 0;
                                        this.i = 0;
                                        while (this.i < Main.mainClass.saveBoxClass.gameSave5.data.starsOfLevels.length)
                                        {
                                            
                                            this.tempObject = this.tempObject + Main.mainClass.saveBoxClass.gameSave5.data.starsOfLevels[this.i];
                                            var _loc_2:* = this;
                                            var _loc_3:* = this.i + 1;
                                            _loc_2.i = _loc_3;
                                        }
                                        this.tempObject = this.tempObject + 3;
                                        this.container.game2.numTXT.text = this.tempObject + "/" + Main.mainClass.saveBoxClass.maxStars;
                                        this.container.game2.numTXT.setTextFormat(Main.mainClass.boldTextFormat);
                                    }
                                    if (!Main.mainClass.saveBoxClass.gameSave6.data.haveSave)
                                    {
                                        this.container.game3.gotoAndStop(4);
                                        this.container.game3.newGame3Case.stop();
                                        this.container.game3.newGame3Case.buttonMode = true;
                                    }
                                    else
                                    {
                                        this.container.game3.gotoAndStop(1);
                                        this.container.game3.game3Case.stop();
                                        this.container.game3.game3Case.buttonMode = true;
                                        this.container.game3.syncSlot.stop();
                                        this.container.game3.syncSlot.syncSlotCase.stop();
                                        this.container.game3.syncSlot.syncSlotCase.buttonMode = true;
                                        this.container.game3.syncSlot.visible = false;
                                        this.container.game3.deleteSlot.stop();
                                        this.container.game3.deleteSlot.deleteSlotCase.stop();
                                        this.container.game3.deleteSlot.deleteSlotCase.buttonMode = true;
                                        this.tempObject = 0;
                                        this.i = 0;
                                        while (this.i < Main.mainClass.saveBoxClass.gameSave6.data.starsOfLevels.length)
                                        {
                                            
                                            this.tempObject = this.tempObject + Main.mainClass.saveBoxClass.gameSave6.data.starsOfLevels[this.i];
                                            var _loc_2:* = this;
                                            var _loc_3:* = this.i + 1;
                                            _loc_2.i = _loc_3;
                                        }
                                        this.tempObject = this.tempObject + 3;
                                        this.container.game3.numTXT.text = this.tempObject + "/" + Main.mainClass.saveBoxClass.maxStars;
                                        this.container.game3.numTXT.setTextFormat(Main.mainClass.boldTextFormat);
                                    }
                                }
                                this.container.back.visible = true;
                            }
                            else if (this.container.currentFrame == 79)
                            {
                                var _loc_2:* = true;
                                this.container.mouseChildren = true;
                                this.container.mouseEnabled = _loc_2;
                                this.autoguidersButtons();
                            }
                        }
                        if (this.question > 0)
                        {
                            if (this.container.currentFrame < 87)
                            {
                                this.container.gotoAndStop((this.container.currentFrame + 1));
                                if (this.container.currentFrame == 80)
                                {
                                    this.container.question.stop();
                                    this.container.question.btnYes.stop();
                                    this.container.question.btnYes.yesCase.stop();
                                    this.container.question.btnNo.stop();
                                    this.container.question.btnNo.noCase.stop();
                                    this.container.question.btnYes.yesCase.buttonMode = true;
                                    this.container.question.btnNo.noCase.buttonMode = true;
                                    var _loc_2:* = false;
                                    this.container.question.mouseChildren = false;
                                    this.container.question.mouseEnabled = _loc_2;
                                    if (this.question < 11)
                                    {
                                        this.container.question.noteTXT.text = "Delete save slot?";
                                    }
                                    else
                                    {
                                        this.container.question.noteTXT.text = "Are you sure?";
                                    }
                                }
                            }
                            else if (this.container.question.currentFrame < this.container.question.totalFrames)
                            {
                                this.container.question.gotoAndStop((this.container.question.currentFrame + 1));
                                if (this.container.question.currentFrame == this.container.question.totalFrames)
                                {
                                    var _loc_2:* = true;
                                    this.container.question.mouseChildren = true;
                                    this.container.question.mouseEnabled = _loc_2;
                                }
                            }
                        }
                        else if (this.question == -1)
                        {
                            this.tempObject = false;
                            if (this.container.question)
                            {
                                if (this.container.question.currentFrame > 1)
                                {
                                    this.container.question.gotoAndStop((this.container.question.currentFrame - 1));
                                    this.tempObject = true;
                                }
                            }
                            if (!this.tempObject)
                            {
                                if (this.container.currentFrame > 79)
                                {
                                    this.container.gotoAndStop((this.container.currentFrame - 1));
                                }
                                else
                                {
                                    this.question = 0;
                                    var _loc_2:* = true;
                                    this.container.game1.mouseChildren = true;
                                    this.container.game1.mouseEnabled = _loc_2;
                                    var _loc_2:* = true;
                                    this.container.game2.mouseChildren = true;
                                    this.container.game2.mouseEnabled = _loc_2;
                                    var _loc_2:* = true;
                                    this.container.game3.mouseChildren = true;
                                    this.container.game3.mouseEnabled = _loc_2;
                                    this.container.game1.alpha = 1;
                                    this.container.game2.alpha = 1;
                                    this.container.game3.alpha = 1;
                                    var _loc_2:* = true;
                                    this.container.mouseChildren = true;
                                    this.container.mouseEnabled = _loc_2;
                                    this.autoguidersButtons();
                                }
                            }
                        }
                    }
                }
                if (this.loginFlag)
                {
                    if (Main.mainClass.IDIClass.idnet)
                    {
                        if (Main.mainClass.IDIClass.idnet.userData)
                        {
                            this.loginFlag = false;
                            this.page = 4;
                            var _loc_2:* = false;
                            this.container.mouseChildren = false;
                            this.container.mouseEnabled = _loc_2;
                            this.waitCounter = 0;
                            Main.mainClass.saveBoxClass.gameSave4.data.haveSave = false;
                            Main.mainClass.saveBoxClass.gameSave5.data.haveSave = false;
                            Main.mainClass.saveBoxClass.gameSave6.data.haveSave = false;
                            Main.mainClass.IDIClass.getData(4);
                            Main.mainClass.IDIClass.getData(5);
                            Main.mainClass.IDIClass.getData(6);
                        }
                    }
                }
                else if (this.loginFlag1 > 0)
                {
                    if (this.question > 0 || this.page != 3)
                    {
                        this.loginFlag1 = 0;
                    }
                    else if (Main.mainClass.IDIClass.idnet)
                    {
                        if (Main.mainClass.IDIClass.idnet.userData)
                        {
                            this.question = this.loginFlag1;
                            if (this.container.game1.syncSlot)
                            {
                                this.container.game1.syncSlot.gotoAndStop(4);
                            }
                            if (this.container.game2.syncSlot)
                            {
                                this.container.game2.syncSlot.gotoAndStop(4);
                            }
                            if (this.container.game3.syncSlot)
                            {
                                this.container.game3.syncSlot.gotoAndStop(4);
                            }
                            var _loc_2:* = false;
                            this.container.game1.mouseChildren = false;
                            this.container.game1.mouseEnabled = _loc_2;
                            var _loc_2:* = false;
                            this.container.game2.mouseChildren = false;
                            this.container.game2.mouseEnabled = _loc_2;
                            var _loc_2:* = false;
                            this.container.game3.mouseChildren = false;
                            this.container.game3.mouseEnabled = _loc_2;
                            this.container.game1.alpha = 0.5;
                            this.container.game2.alpha = 0.5;
                            this.container.game3.alpha = 0.5;
                            this.loginFlag1 = 0;
                        }
                    }
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (param1.target.name == "backCase")
            {
                if (this.container.back.currentFrame == 1)
                {
                    this.container.back.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.back.currentFrame == 2)
            {
                this.container.back.gotoAndStop(1);
            }
            if (param1.target.name == "musicCase")
            {
                if (this.container.btnMusic.currentFrame == 1 || this.container.btnMusic.currentFrame == 4)
                {
                    this.container.btnMusic.gotoAndStop((this.container.btnMusic.currentFrame + 1));
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.btnMusic.currentFrame == 2 || this.container.btnMusic.currentFrame == 5)
            {
                this.container.btnMusic.gotoAndStop((this.container.btnMusic.currentFrame - 1));
            }
            if (param1.target.name == "soundCase")
            {
                if (this.container.btnSound.currentFrame == 1 || this.container.btnSound.currentFrame == 4)
                {
                    this.container.btnSound.gotoAndStop((this.container.btnSound.currentFrame + 1));
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.btnSound.currentFrame == 2 || this.container.btnSound.currentFrame == 5)
            {
                this.container.btnSound.gotoAndStop((this.container.btnSound.currentFrame - 1));
            }
            if (this.container.btnY8.y8Case.buttonMode)
            {
                if (param1.target.name == "y8Case")
                {
                    if (this.container.btnY8.currentFrame == 1)
                    {
                        this.container.btnY8.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.container.btnY8.currentFrame == 2)
                {
                    this.container.btnY8.gotoAndStop(1);
                }
            }
            if (param1.target.name == "idnetCase")
            {
                if (this.container.btnIdnet.currentFrame == 1)
                {
                    this.container.btnIdnet.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.btnIdnet.currentFrame == 2)
            {
                this.container.btnIdnet.gotoAndStop(1);
            }
            if (this.container.start)
            {
                if (this.container.start.startCase.buttonMode)
                {
                    if (param1.target.name == "startCase")
                    {
                        if (this.container.start.currentFrame == 1)
                        {
                            this.container.start.gotoAndStop(2);
                            Sounds.instance.playSound("snd_menu_stoneMouseMove");
                        }
                    }
                    else if (this.container.start.currentFrame == 2)
                    {
                        this.container.start.gotoAndStop(1);
                    }
                    if (param1.target.name == "creditsCase")
                    {
                        if (this.container.credits.currentFrame == 1)
                        {
                            this.container.credits.gotoAndStop(2);
                            Sounds.instance.playSound("snd_menu_stoneMouseMove");
                        }
                    }
                    else if (this.container.credits.currentFrame == 2)
                    {
                        this.container.credits.gotoAndStop(1);
                    }
                }
            }
            else if (this.container.saveType)
            {
                if (param1.target.name == "localSaveCase")
                {
                    if (this.container.saveType.localSave.currentFrame == 1)
                    {
                        this.container.saveType.localSave.gotoAndStop(2);
                        this.container.saveType.setChildIndex(this.container.saveType.localSave, (this.container.saveType.numChildren - 1));
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.saveType.localSave.currentFrame == 2)
                {
                    this.container.saveType.localSave.gotoAndStop(1);
                }
                if (param1.target.name == "onlineSaveCase")
                {
                    if (this.container.saveType.onlineSave.currentFrame == 1)
                    {
                        this.container.saveType.onlineSave.gotoAndStop(2);
                        if (this.welcomeText)
                        {
                            this.container.saveType.onlineSave.welcomeTXT.text = this.welcomeText;
                            this.container.saveType.onlineSave.nickTXT.text = this.nickText;
                            this.container.saveType.onlineSave.nickTXT.setTextFormat(Main.mainClass.boldTextFormat);
                        }
                        this.container.saveType.setChildIndex(this.container.saveType.onlineSave, (this.container.saveType.numChildren - 1));
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.saveType.onlineSave.currentFrame == 2)
                {
                    this.container.saveType.onlineSave.gotoAndStop(1);
                    if (this.welcomeText)
                    {
                        this.container.saveType.onlineSave.welcomeTXT.text = this.welcomeText;
                        this.container.saveType.onlineSave.nickTXT.text = this.nickText;
                        this.container.saveType.onlineSave.nickTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    }
                }
            }
            else if (this.container.game1)
            {
                if (param1.target.name == "game1Case")
                {
                    if (this.container.game1.currentFrame == 1)
                    {
                        this.container.game1.gotoAndStop(2);
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.game1.currentFrame == 2)
                {
                    this.container.game1.gotoAndStop(1);
                }
                if (param1.target.name == "game2Case")
                {
                    if (this.container.game2.currentFrame == 1)
                    {
                        this.container.game2.gotoAndStop(2);
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.game2.currentFrame == 2)
                {
                    this.container.game2.gotoAndStop(1);
                }
                if (param1.target.name == "game3Case")
                {
                    if (this.container.game3.currentFrame == 1)
                    {
                        this.container.game3.gotoAndStop(2);
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.game3.currentFrame == 2)
                {
                    this.container.game3.gotoAndStop(1);
                }
                if (param1.target.name == "newGame1Case")
                {
                    if (this.container.game1.currentFrame == 4)
                    {
                        this.container.game1.gotoAndStop(5);
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.game1.currentFrame == 5)
                {
                    this.container.game1.gotoAndStop(4);
                }
                if (param1.target.name == "newGame2Case")
                {
                    if (this.container.game2.currentFrame == 4)
                    {
                        this.container.game2.gotoAndStop(5);
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.game2.currentFrame == 5)
                {
                    this.container.game2.gotoAndStop(4);
                }
                if (param1.target.name == "newGame3Case")
                {
                    if (this.container.game3.currentFrame == 4)
                    {
                        this.container.game3.gotoAndStop(5);
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.game3.currentFrame == 5)
                {
                    this.container.game3.gotoAndStop(4);
                }
                if (param1.target.name == "syncSlotCase")
                {
                    if (param1.target.parent.currentFrame < 4)
                    {
                        if (!this.syncHint)
                        {
                            this.syncHint = new Hint_mc();
                            this.syncHint.gotoAndStop(16);
                            if (param1.target.parent.parent.name == "game1")
                            {
                                this.syncHint.x = this.container.game1.x + this.container.game1.syncSlot.x + this.container.game1.syncSlot.syncSlotCase.x + 10;
                                this.syncHint.y = this.container.game1.y + this.container.game1.syncSlot.y + this.container.game1.syncSlot.syncSlotCase.y - 5;
                            }
                            else if (param1.target.parent.parent.name == "game2")
                            {
                                this.syncHint.x = this.container.game2.x + this.container.game2.syncSlot.x + this.container.game2.syncSlot.syncSlotCase.x + 10;
                                this.syncHint.y = this.container.game2.y + this.container.game2.syncSlot.y + this.container.game2.syncSlot.syncSlotCase.y - 5;
                            }
                            else if (param1.target.parent.parent.name == "game3")
                            {
                                this.syncHint.x = this.container.game3.x + this.container.game3.syncSlot.x + this.container.game3.syncSlot.syncSlotCase.x + 10;
                                this.syncHint.y = this.container.game3.y + this.container.game3.syncSlot.y + this.container.game3.syncSlot.syncSlotCase.y - 5;
                            }
                            var _loc_2:* = false;
                            this.syncHint.mouseChildren = false;
                            this.syncHint.mouseEnabled = _loc_2;
                            this.addChild(this.syncHint);
                        }
                    }
                    if (param1.target.parent.parent.name == "game1")
                    {
                        if (this.container.game1.syncSlot.currentFrame == 1 || this.container.game1.syncSlot.currentFrame == 4)
                        {
                            this.container.game1.syncSlot.gotoAndStop((this.container.game1.syncSlot.currentFrame + 1));
                            Sounds.instance.playSound("snd_menu_stoneMouseMove");
                        }
                    }
                    else if (param1.target.parent.parent.name == "game2")
                    {
                        if (this.container.game2.syncSlot.currentFrame == 1 || this.container.game2.syncSlot.currentFrame == 4)
                        {
                            this.container.game2.syncSlot.gotoAndStop((this.container.game2.syncSlot.currentFrame + 1));
                            Sounds.instance.playSound("snd_menu_stoneMouseMove");
                        }
                    }
                    else if (param1.target.parent.parent.name == "game3")
                    {
                        if (this.container.game3.syncSlot.currentFrame == 1 || this.container.game3.syncSlot.currentFrame == 4)
                        {
                            this.container.game3.syncSlot.gotoAndStop((this.container.game3.syncSlot.currentFrame + 1));
                            Sounds.instance.playSound("snd_menu_stoneMouseMove");
                        }
                    }
                }
                else
                {
                    if (this.syncHint)
                    {
                        this.removeChild(this.syncHint);
                        this.syncHint = null;
                    }
                    if (this.container.game1.currentFrame < 4)
                    {
                        if (this.container.game1.syncSlot.currentFrame == 2 || this.container.game1.syncSlot.currentFrame == 5)
                        {
                            this.container.game1.syncSlot.gotoAndStop((this.container.game1.syncSlot.currentFrame - 1));
                        }
                    }
                    if (this.container.game2.currentFrame < 4)
                    {
                        if (this.container.game2.syncSlot.currentFrame == 2 || this.container.game2.syncSlot.currentFrame == 5)
                        {
                            this.container.game2.syncSlot.gotoAndStop((this.container.game2.syncSlot.currentFrame - 1));
                        }
                    }
                    if (this.container.game3.currentFrame < 4)
                    {
                        if (this.container.game3.syncSlot.currentFrame == 2 || this.container.game3.syncSlot.currentFrame == 5)
                        {
                            this.container.game3.syncSlot.gotoAndStop((this.container.game3.syncSlot.currentFrame - 1));
                        }
                    }
                }
                if (param1.target.name == "deleteSlotCase" && param1.target.parent.parent.name == "game1")
                {
                    if (this.container.game1.deleteSlot.currentFrame == 1)
                    {
                        this.container.game1.deleteSlot.gotoAndStop(2);
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.game1.currentFrame < 4)
                {
                    if (this.container.game1.deleteSlot.currentFrame == 2)
                    {
                        this.container.game1.deleteSlot.gotoAndStop(1);
                    }
                }
                if (param1.target.name == "deleteSlotCase" && param1.target.parent.parent.name == "game2")
                {
                    if (this.container.game2.deleteSlot.currentFrame == 1)
                    {
                        this.container.game2.deleteSlot.gotoAndStop(2);
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.game2.currentFrame < 4)
                {
                    if (this.container.game2.deleteSlot.currentFrame == 2)
                    {
                        this.container.game2.deleteSlot.gotoAndStop(1);
                    }
                }
                if (param1.target.name == "deleteSlotCase" && param1.target.parent.parent.name == "game3")
                {
                    if (this.container.game3.deleteSlot.currentFrame == 1)
                    {
                        this.container.game3.deleteSlot.gotoAndStop(2);
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.game3.currentFrame < 4)
                {
                    if (this.container.game3.deleteSlot.currentFrame == 2)
                    {
                        this.container.game3.deleteSlot.gotoAndStop(1);
                    }
                }
                if (this.container.question)
                {
                    if (param1.target.name == "yesCase")
                    {
                        if (param1.target.parent.currentFrame == 1)
                        {
                            param1.target.parent.gotoAndStop(2);
                            Sounds.instance.playSound("snd_menu_stoneMouseMove");
                        }
                    }
                    else if (this.container.question.btnYes.currentFrame == 2)
                    {
                        this.container.question.btnYes.gotoAndStop(1);
                    }
                    if (param1.target.name == "noCase")
                    {
                        if (param1.target.parent.currentFrame == 1)
                        {
                            param1.target.parent.gotoAndStop(2);
                            Sounds.instance.playSound("snd_menu_stoneMouseMove");
                        }
                    }
                    else if (this.container.question.btnNo.currentFrame == 2)
                    {
                        this.container.question.btnNo.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "backCase")
            {
                if (this.container.back.currentFrame == 2)
                {
                    this.container.back.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "musicCase")
            {
                if (this.container.btnMusic.currentFrame == 2 || this.container.btnMusic.currentFrame == 5)
                {
                    this.container.btnMusic.gotoAndStop((this.container.btnMusic.currentFrame + 1));
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "soundCase")
            {
                if (this.container.btnSound.currentFrame == 2 || this.container.btnSound.currentFrame == 5)
                {
                    this.container.btnSound.gotoAndStop((this.container.btnSound.currentFrame + 1));
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "y8Case")
            {
                if (this.container.btnY8.currentFrame == 2)
                {
                    this.container.btnY8.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "idnetCase")
            {
                if (this.container.btnIdnet.currentFrame == 2)
                {
                    this.container.btnIdnet.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "logOut")
            {
                if (Main.mainClass.IDIClass.idnet)
                {
                    Main.mainClass.IDIClass.idnet.logout();
                }
            }
            if (this.container.start)
            {
                if (event.target.name == "startCase")
                {
                    if (this.container.start.currentFrame == 2)
                    {
                        this.container.start.gotoAndStop(3);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (event.target.name == "creditsCase")
                {
                    if (this.container.credits.currentFrame == 2)
                    {
                        this.container.credits.gotoAndStop(3);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
            }
            else if (this.container.saveType)
            {
                if (event.target.name == "localSaveCase")
                {
                    if (this.container.saveType.localSave.currentFrame == 2)
                    {
                        this.container.saveType.localSave.gotoAndStop(3);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (event.target.name == "onlineSaveCase")
                {
                    if (this.container.saveType.onlineSave.currentFrame == 2)
                    {
                        this.container.saveType.onlineSave.gotoAndStop(3);
                        if (this.welcomeText)
                        {
                            this.container.saveType.onlineSave.welcomeTXT.text = this.welcomeText;
                            this.container.saveType.onlineSave.nickTXT.text = this.nickText;
                            this.container.saveType.onlineSave.nickTXT.setTextFormat(Main.mainClass.boldTextFormat);
                        }
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
            }
            else if (this.container.game1)
            {
                if (event.target.name == "game1Case")
                {
                    if (this.container.game1.currentFrame == 2)
                    {
                        this.container.game1.gotoAndStop(3);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (event.target.name == "game2Case")
                {
                    if (this.container.game2.currentFrame == 2)
                    {
                        this.container.game2.gotoAndStop(3);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (event.target.name == "game3Case")
                {
                    if (this.container.game3.currentFrame == 2)
                    {
                        this.container.game3.gotoAndStop(3);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (event.target.name == "newGame1Case")
                {
                    if (this.container.game1.currentFrame == 5)
                    {
                        this.container.game1.gotoAndStop(6);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (event.target.name == "newGame2Case")
                {
                    if (this.container.game2.currentFrame == 5)
                    {
                        this.container.game2.gotoAndStop(6);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (event.target.name == "newGame3Case")
                {
                    if (this.container.game3.currentFrame == 5)
                    {
                        this.container.game3.gotoAndStop(6);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (event.target.name == "syncSlotCase")
                {
                    if (event.target.parent.currentFrame == 2 || event.target.parent.currentFrame == 5)
                    {
                        event.target.parent.gotoAndStop((event.target.parent.currentFrame + 1));
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                else if (event.target.name == "deleteSlotCase")
                {
                    if (event.target.parent.currentFrame == 2)
                    {
                        event.target.parent.gotoAndStop(3);
                        Sounds.instance.playSound("snd_menu_stoneMouseDown");
                    }
                }
                if (this.container.question)
                {
                    if (event.target.name == "yesCase")
                    {
                        if (event.target.parent.currentFrame == 2)
                        {
                            event.target.parent.gotoAndStop(3);
                            Sounds.instance.playSound("snd_menu_stoneMouseDown");
                        }
                    }
                    else if (event.target.name == "noCase")
                    {
                        if (event.target.parent.currentFrame == 2)
                        {
                            event.target.parent.gotoAndStop(3);
                            Sounds.instance.playSound("snd_menu_stoneMouseDown");
                        }
                    }
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (event.target.name == "backCase")
            {
                if (this.container.back.currentFrame == 3)
                {
                    this.container.back.gotoAndStop(1);
                    if (this.question != 0)
                    {
                        this.question = -1;
                    }
                    else if (this.page == 2)
                    {
                        this.page = 1;
                    }
                    else if (this.page == 3 || this.page == 4)
                    {
                        this.page = 2;
                    }
                    var _loc_2:* = false;
                    this.container.mouseChildren = false;
                    this.container.mouseEnabled = _loc_2;
                }
            }
            else if (this.container.back.currentFrame == 3)
            {
                this.container.back.gotoAndStop(1);
            }
            if (event.target.name == "musicCase")
            {
                if (this.container.btnMusic.currentFrame == 3 || this.container.btnMusic.currentFrame == 6)
                {
                    if (this.container.btnMusic.currentFrame == 3)
                    {
                        this.container.btnMusic.gotoAndStop(5);
                        Sounds.instance.musicManage("off");
                    }
                    else if (this.container.btnMusic.currentFrame == 6)
                    {
                        this.container.btnMusic.gotoAndStop(2);
                        Sounds.instance.musicManage("on");
                        Sounds.instance.playMusic(0);
                    }
                }
            }
            else if (this.container.btnMusic.currentFrame == 3 || this.container.btnMusic.currentFrame == 6)
            {
                this.container.btnMusic.gotoAndStop(this.container.btnMusic.currentFrame - 2);
            }
            if (event.target.name == "soundCase")
            {
                if (this.container.btnSound.currentFrame == 3 || this.container.btnSound.currentFrame == 6)
                {
                    if (this.container.btnSound.currentFrame == 3)
                    {
                        this.container.btnSound.gotoAndStop(5);
                        Sounds.instance.soundManage("off");
                    }
                    else if (this.container.btnSound.currentFrame == 6)
                    {
                        this.container.btnSound.gotoAndStop(2);
                        Sounds.instance.soundManage("on");
                    }
                }
            }
            else if (this.container.btnSound.currentFrame == 3 || this.container.btnSound.currentFrame == 6)
            {
                this.container.btnSound.gotoAndStop(this.container.btnSound.currentFrame - 2);
            }
            if (event.target.name == "y8Case")
            {
                if (this.container.btnY8.currentFrame == 3)
                {
                    this.container.btnY8.gotoAndStop(2);
                    navigateToURL(new URLRequest("http://www.y8.com/?utm_source=" + Main.mainClass.domainName + "&utm_medium=g_prelogo&utm_campaign=brave_heads"));
                }
            }
            else if (this.container.btnY8.currentFrame == 3)
            {
                this.container.btnY8.gotoAndStop(1);
            }
            if (event.target.name == "idnetCase")
            {
                if (this.container.btnIdnet.currentFrame == 3)
                {
                    this.container.btnIdnet.gotoAndStop(2);
                    navigateToURL(new URLRequest("http://www.id.net"));
                }
            }
            else if (this.container.btnIdnet.currentFrame == 3)
            {
                this.container.btnIdnet.gotoAndStop(1);
            }
            if (this.container.start)
            {
                if (event.target.name == "startCase")
                {
                    if (this.container.start.currentFrame == 3)
                    {
                        this.page = 2;
                        var _loc_2:* = false;
                        this.container.mouseChildren = false;
                        this.container.mouseEnabled = _loc_2;
                    }
                }
                else if (this.container.start.currentFrame == 3)
                {
                    this.container.start.gotoAndStop(1);
                }
                if (event.target.name == "creditsCase")
                {
                    if (this.container.credits.currentFrame == 3)
                    {
                        this.container.credits.gotoAndStop(2);
                        this.creditsClass = new Credits();
                        this.addChild(this.creditsClass);
                    }
                }
                else if (this.container.credits.currentFrame == 3)
                {
                    this.container.credits.gotoAndStop(1);
                }
            }
            else if (this.container.saveType)
            {
                if (event.target.name == "localSaveCase")
                {
                    if (this.container.saveType.localSave.currentFrame == 3)
                    {
                        this.container.saveType.localSave.gotoAndStop(2);
                        this.page = 3;
                        var _loc_2:* = false;
                        this.container.mouseChildren = false;
                        this.container.mouseEnabled = _loc_2;
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.saveType.localSave.currentFrame == 3)
                {
                    this.container.saveType.localSave.gotoAndStop(1);
                }
                if (event.target.name == "onlineSaveCase")
                {
                    if (this.container.saveType.onlineSave.currentFrame == 3)
                    {
                        this.container.saveType.onlineSave.gotoAndStop(2);
                        if (this.welcomeText)
                        {
                            this.container.saveType.onlineSave.welcomeTXT.text = this.welcomeText;
                            this.container.saveType.onlineSave.nickTXT.text = this.nickText;
                            this.container.saveType.onlineSave.nickTXT.setTextFormat(Main.mainClass.boldTextFormat);
                        }
                        if (Main.mainClass.IDIClass.idnet)
                        {
                            if (!Main.mainClass.IDIClass.idnet.userData)
                            {
                                this.loginFlag = true;
                                Main.mainClass.IDIClass.idnet.toggleInterface();
                            }
                            else
                            {
                                this.page = 4;
                                var _loc_2:* = false;
                                this.container.mouseChildren = false;
                                this.container.mouseEnabled = _loc_2;
                                this.waitCounter = 0;
                                Main.mainClass.saveBoxClass.gameSave4.data.haveSave = false;
                                Main.mainClass.saveBoxClass.gameSave5.data.haveSave = false;
                                Main.mainClass.saveBoxClass.gameSave6.data.haveSave = false;
                                Main.mainClass.IDIClass.getData(4);
                                Main.mainClass.IDIClass.getData(5);
                                Main.mainClass.IDIClass.getData(6);
                            }
                        }
                        Sounds.instance.playSound("snd_menu_stoneMouseMove");
                    }
                }
                else if (this.container.saveType.onlineSave.currentFrame == 3)
                {
                    this.container.saveType.onlineSave.gotoAndStop(1);
                    if (this.welcomeText)
                    {
                        this.container.saveType.onlineSave.welcomeTXT.text = this.welcomeText;
                        this.container.saveType.onlineSave.nickTXT.text = this.nickText;
                        this.container.saveType.onlineSave.nickTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    }
                }
            }
            else if (this.container.game1)
            {
                if (event.target.name == "game1Case")
                {
                    if (this.container.game1.currentFrame == 3)
                    {
                        if (this.page == 3)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(1);
                        }
                        else if (this.page == 4)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(4);
                        }
                        Main.mainClass.addNewScreen("LevelsMenu");
                    }
                }
                else if (this.container.game1.currentFrame == 3)
                {
                    this.container.game1.gotoAndStop(1);
                }
                if (event.target.name == "game2Case")
                {
                    if (this.container.game2.currentFrame == 3)
                    {
                        if (this.page == 3)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(2);
                        }
                        else if (this.page == 4)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(5);
                        }
                        Main.mainClass.addNewScreen("LevelsMenu");
                    }
                }
                else if (this.container.game2.currentFrame == 3)
                {
                    this.container.game2.gotoAndStop(1);
                }
                if (event.target.name == "game3Case")
                {
                    if (this.container.game3.currentFrame == 3)
                    {
                        if (this.page == 3)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(3);
                        }
                        else if (this.page == 4)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(6);
                        }
                        Main.mainClass.addNewScreen("LevelsMenu");
                    }
                }
                else if (this.container.game3.currentFrame == 3)
                {
                    this.container.game3.gotoAndStop(1);
                }
                if (event.target.name == "newGame1Case")
                {
                    if (this.container.game1.currentFrame == 6)
                    {
                        if (this.page == 3)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(1);
                        }
                        else if (this.page == 4)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(4);
                        }
                        Main.mainClass.addNewScreen("LevelsMenu");
                    }
                }
                else if (this.container.game1.currentFrame == 6)
                {
                    this.container.game1.gotoAndStop(4);
                }
                if (event.target.name == "newGame2Case")
                {
                    if (this.container.game2.currentFrame == 6)
                    {
                        if (this.page == 3)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(2);
                        }
                        else if (this.page == 4)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(5);
                        }
                        Main.mainClass.addNewScreen("LevelsMenu");
                    }
                }
                else if (this.container.game2.currentFrame == 6)
                {
                    this.container.game2.gotoAndStop(4);
                }
                if (event.target.name == "newGame3Case")
                {
                    if (this.container.game3.currentFrame == 6)
                    {
                        if (this.page == 3)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(3);
                        }
                        else if (this.page == 4)
                        {
                            Main.mainClass.saveBoxClass.checkSaves(6);
                        }
                        Main.mainClass.addNewScreen("LevelsMenu");
                    }
                }
                else if (this.container.game3.currentFrame == 6)
                {
                    this.container.game3.gotoAndStop(4);
                }
                if (event.target.name == "syncSlotCase" && event.target.parent.parent.name == "game1")
                {
                    if (this.container.game1.syncSlot.currentFrame == 3 || this.container.game1.syncSlot.currentFrame == 6)
                    {
                        this.container.game1.syncSlot.gotoAndStop((this.container.game1.syncSlot.currentFrame - 1));
                        if (Main.mainClass.IDIClass.idnet)
                        {
                            if (Main.mainClass.IDIClass.idnet.userData)
                            {
                                this.question = 11;
                                var _loc_2:* = false;
                                this.container.game1.mouseChildren = false;
                                this.container.game1.mouseEnabled = _loc_2;
                                var _loc_2:* = false;
                                this.container.game2.mouseChildren = false;
                                this.container.game2.mouseEnabled = _loc_2;
                                var _loc_2:* = false;
                                this.container.game3.mouseChildren = false;
                                this.container.game3.mouseEnabled = _loc_2;
                                this.container.game1.alpha = 0.5;
                                this.container.game2.alpha = 0.5;
                                this.container.game3.alpha = 0.5;
                            }
                            else
                            {
                                Main.mainClass.IDIClass.idnet.toggleInterface();
                                this.loginFlag1 = 11;
                            }
                            if (this.syncHint)
                            {
                                this.removeChild(this.syncHint);
                                this.syncHint = null;
                            }
                        }
                    }
                }
                else if (this.container.game1.currentFrame < 4)
                {
                    if (this.container.game1.syncSlot.currentFrame == 3 || this.container.game1.syncSlot.currentFrame == 6)
                    {
                        this.container.game1.syncSlot.gotoAndStop(this.container.game1.syncSlot.currentFrame - 2);
                    }
                }
                if (event.target.name == "syncSlotCase" && event.target.parent.parent.name == "game2")
                {
                    if (this.container.game2.syncSlot.currentFrame == 3 || this.container.game2.syncSlot.currentFrame == 6)
                    {
                        this.container.game2.syncSlot.gotoAndStop((this.container.game2.syncSlot.currentFrame - 1));
                        if (Main.mainClass.IDIClass.idnet)
                        {
                            if (Main.mainClass.IDIClass.idnet.userData)
                            {
                                this.question = 12;
                                var _loc_2:* = false;
                                this.container.game1.mouseChildren = false;
                                this.container.game1.mouseEnabled = _loc_2;
                                var _loc_2:* = false;
                                this.container.game2.mouseChildren = false;
                                this.container.game2.mouseEnabled = _loc_2;
                                var _loc_2:* = false;
                                this.container.game3.mouseChildren = false;
                                this.container.game3.mouseEnabled = _loc_2;
                                this.container.game1.alpha = 0.5;
                                this.container.game2.alpha = 0.5;
                                this.container.game3.alpha = 0.5;
                            }
                            else
                            {
                                Main.mainClass.IDIClass.idnet.toggleInterface();
                                this.loginFlag1 = 12;
                            }
                            if (this.syncHint)
                            {
                                this.removeChild(this.syncHint);
                                this.syncHint = null;
                            }
                        }
                    }
                }
                else if (this.container.game2.currentFrame < 4)
                {
                    if (this.container.game2.syncSlot.currentFrame == 3 || this.container.game2.syncSlot.currentFrame == 6)
                    {
                        this.container.game2.syncSlot.gotoAndStop(this.container.game2.syncSlot.currentFrame - 2);
                    }
                }
                if (event.target.name == "syncSlotCase" && event.target.parent.parent.name == "game3")
                {
                    if (this.container.game3.syncSlot.currentFrame == 3 || this.container.game3.syncSlot.currentFrame == 6)
                    {
                        this.container.game3.syncSlot.gotoAndStop((this.container.game3.syncSlot.currentFrame - 1));
                        if (Main.mainClass.IDIClass.idnet)
                        {
                            if (Main.mainClass.IDIClass.idnet.userData)
                            {
                                this.question = 13;
                                var _loc_2:* = false;
                                this.container.game1.mouseChildren = false;
                                this.container.game1.mouseEnabled = _loc_2;
                                var _loc_2:* = false;
                                this.container.game2.mouseChildren = false;
                                this.container.game2.mouseEnabled = _loc_2;
                                var _loc_2:* = false;
                                this.container.game3.mouseChildren = false;
                                this.container.game3.mouseEnabled = _loc_2;
                                this.container.game1.alpha = 0.5;
                                this.container.game2.alpha = 0.5;
                                this.container.game3.alpha = 0.5;
                            }
                            else
                            {
                                Main.mainClass.IDIClass.idnet.toggleInterface();
                                this.loginFlag1 = 13;
                            }
                            if (this.syncHint)
                            {
                                this.removeChild(this.syncHint);
                                this.syncHint = null;
                            }
                        }
                    }
                }
                else if (this.container.game3.currentFrame < 4)
                {
                    if (this.container.game3.syncSlot.currentFrame == 3 || this.container.game3.syncSlot.currentFrame == 6)
                    {
                        this.container.game3.syncSlot.gotoAndStop(this.container.game3.syncSlot.currentFrame - 2);
                    }
                }
                if (event.target.name == "deleteSlotCase" && event.target.parent.parent.name == "game1")
                {
                    if (this.container.game1.deleteSlot.currentFrame == 3)
                    {
                        this.container.game1.deleteSlot.gotoAndStop(2);
                        if (this.page == 3)
                        {
                            this.question = 1;
                        }
                        else if (this.page == 4)
                        {
                            this.question = 4;
                        }
                        var _loc_2:* = false;
                        this.container.game1.mouseChildren = false;
                        this.container.game1.mouseEnabled = _loc_2;
                        var _loc_2:* = false;
                        this.container.game2.mouseChildren = false;
                        this.container.game2.mouseEnabled = _loc_2;
                        var _loc_2:* = false;
                        this.container.game3.mouseChildren = false;
                        this.container.game3.mouseEnabled = _loc_2;
                        this.container.game1.alpha = 0.5;
                        this.container.game2.alpha = 0.5;
                        this.container.game3.alpha = 0.5;
                    }
                }
                else if (this.container.game1.currentFrame < 4)
                {
                    if (this.container.game1.deleteSlot.currentFrame == 3)
                    {
                        this.container.game1.deleteSlot.gotoAndStop(1);
                    }
                }
                if (event.target.name == "deleteSlotCase" && event.target.parent.parent.name == "game2")
                {
                    if (this.container.game2.deleteSlot.currentFrame == 3)
                    {
                        this.container.game2.deleteSlot.gotoAndStop(2);
                        if (this.page == 3)
                        {
                            this.question = 2;
                        }
                        else if (this.page == 4)
                        {
                            this.question = 5;
                        }
                        var _loc_2:* = false;
                        this.container.game1.mouseChildren = false;
                        this.container.game1.mouseEnabled = _loc_2;
                        var _loc_2:* = false;
                        this.container.game2.mouseChildren = false;
                        this.container.game2.mouseEnabled = _loc_2;
                        var _loc_2:* = false;
                        this.container.game3.mouseChildren = false;
                        this.container.game3.mouseEnabled = _loc_2;
                        this.container.game1.alpha = 0.5;
                        this.container.game2.alpha = 0.5;
                        this.container.game3.alpha = 0.5;
                    }
                }
                else if (this.container.game2.currentFrame < 4)
                {
                    if (this.container.game2.deleteSlot.currentFrame == 3)
                    {
                        this.container.game2.deleteSlot.gotoAndStop(1);
                    }
                }
                if (event.target.name == "deleteSlotCase" && event.target.parent.parent.name == "game3")
                {
                    if (this.container.game3.deleteSlot.currentFrame == 3)
                    {
                        this.container.game3.deleteSlot.gotoAndStop(2);
                        if (this.page == 3)
                        {
                            this.question = 3;
                        }
                        else if (this.page == 4)
                        {
                            this.question = 6;
                        }
                        var _loc_2:* = false;
                        this.container.game1.mouseChildren = false;
                        this.container.game1.mouseEnabled = _loc_2;
                        var _loc_2:* = false;
                        this.container.game2.mouseChildren = false;
                        this.container.game2.mouseEnabled = _loc_2;
                        var _loc_2:* = false;
                        this.container.game3.mouseChildren = false;
                        this.container.game3.mouseEnabled = _loc_2;
                        this.container.game1.alpha = 0.5;
                        this.container.game2.alpha = 0.5;
                        this.container.game3.alpha = 0.5;
                    }
                }
                else if (this.container.game3.currentFrame < 4)
                {
                    if (this.container.game3.deleteSlot.currentFrame == 3)
                    {
                        this.container.game3.deleteSlot.gotoAndStop(1);
                    }
                }
                if (this.container.question)
                {
                    if (event.target.name == "yesCase")
                    {
                        if (event.target.parent.currentFrame == 3)
                        {
                            event.target.parent.gotoAndStop(2);
                            if (this.question == 1 || this.question == 4)
                            {
                                this.container.game1.gotoAndStop(4);
                                this.container.game1.newGame1Case.stop();
                                this.container.game1.newGame1Case.buttonMode = true;
                                if (this.question == 1)
                                {
                                    Main.mainClass.saveBoxClass.gameSave1.data.haveSave = false;
                                }
                                else if (this.question == 4)
                                {
                                    Main.mainClass.saveBoxClass.gameSave4.data.haveSave = false;
                                    Main.mainClass.IDIClass.removeData(4);
                                }
                            }
                            else if (this.question == 2 || this.question == 5)
                            {
                                this.container.game2.gotoAndStop(4);
                                this.container.game2.newGame2Case.stop();
                                this.container.game2.newGame2Case.buttonMode = true;
                                if (this.question == 2)
                                {
                                    Main.mainClass.saveBoxClass.gameSave2.data.haveSave = false;
                                }
                                else if (this.question == 5)
                                {
                                    Main.mainClass.saveBoxClass.gameSave5.data.haveSave = false;
                                    Main.mainClass.IDIClass.removeData(5);
                                }
                            }
                            else if (this.question == 3 || this.question == 6)
                            {
                                this.container.game3.gotoAndStop(4);
                                this.container.game3.newGame3Case.stop();
                                this.container.game3.newGame3Case.buttonMode = true;
                                if (this.question == 3)
                                {
                                    Main.mainClass.saveBoxClass.gameSave3.data.haveSave = false;
                                }
                                else if (this.question == 6)
                                {
                                    Main.mainClass.saveBoxClass.gameSave6.data.haveSave = false;
                                    Main.mainClass.IDIClass.removeData(6);
                                }
                            }
                            else if (this.question == 11 || this.question == 12 || this.question == 13)
                            {
                                if (this.question == 11)
                                {
                                    Main.mainClass.saveBoxClass.synchronizationLocalToSite(1);
                                    this.container.game1.syncSlot.gotoAndStop(7);
                                }
                                else if (this.question == 12)
                                {
                                    Main.mainClass.saveBoxClass.synchronizationLocalToSite(2);
                                    this.container.game2.syncSlot.gotoAndStop(7);
                                }
                                else if (this.question == 13)
                                {
                                    Main.mainClass.saveBoxClass.synchronizationLocalToSite(3);
                                    this.container.game3.syncSlot.gotoAndStop(7);
                                }
                            }
                            this.question = -1;
                        }
                    }
                    else if (this.container.question.btnYes.currentFrame == 3)
                    {
                        this.container.question.btnYes.gotoAndStop(2);
                    }
                    if (event.target.name == "noCase")
                    {
                        if (event.target.parent.currentFrame == 3)
                        {
                            event.target.parent.gotoAndStop(2);
                            this.question = -1;
                        }
                    }
                    else if (this.container.question.btnNo.currentFrame == 3)
                    {
                        this.container.question.btnNo.gotoAndStop(2);
                    }
                }
            }
            return;
        }// end function

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(this.mouseX, this.mouseY);
            this.autoguidesObject = null;
            if (this.page == 1)
            {
                this.autoguidesObject_pt = this.container.start.localToGlobal(new Point(this.container.start.startCase.x, this.container.start.startCase.y));
                this.autoguidesObjectWidth = this.container.start.startCase.width / 2;
                this.autoguidesObjectHeight = this.container.start.startCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.start.startCase;
                }
                if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.credits.localToGlobal(new Point(this.container.credits.creditsCase.x, this.container.credits.creditsCase.y));
                    this.autoguidesObjectWidth = this.container.credits.creditsCase.width / 2;
                    this.autoguidesObjectHeight = this.container.credits.creditsCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.credits.creditsCase;
                    }
                }
            }
            else if (this.page == 2)
            {
                this.autoguidesObject_pt = this.container.saveType.localSave.localToGlobal(new Point(this.container.saveType.localSave.localSaveCase.x, this.container.saveType.localSave.localSaveCase.y));
                this.autoguidesObjectWidth = this.container.saveType.localSave.localSaveCase.width / 2;
                this.autoguidesObjectHeight = this.container.saveType.localSave.localSaveCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.saveType.localSave.localSaveCase;
                }
                if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.saveType.onlineSave.localToGlobal(new Point(this.container.saveType.onlineSave.onlineSaveCase.x, this.container.saveType.onlineSave.onlineSaveCase.y));
                    this.autoguidesObjectWidth = this.container.saveType.onlineSave.onlineSaveCase.width / 2;
                    this.autoguidesObjectHeight = this.container.saveType.onlineSave.onlineSaveCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.saveType.onlineSave.onlineSaveCase;
                    }
                }
            }
            else if (this.page == 3)
            {
                if (this.container.game1.currentFrame < 4)
                {
                    this.autoguidesObject_pt = this.container.game1.localToGlobal(new Point(this.container.game1.game1Case.x, this.container.game1.game1Case.y));
                    this.autoguidesObjectWidth = this.container.game1.game1Case.width / 2;
                    this.autoguidesObjectHeight = this.container.game1.game1Case.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.game1.game1Case;
                    }
                    if (!this.autoguidesObject)
                    {
                        this.autoguidesObject_pt = this.container.game1.deleteSlot.localToGlobal(new Point(this.container.game1.deleteSlot.deleteSlotCase.x, this.container.game1.deleteSlot.deleteSlotCase.y));
                        this.autoguidesObjectWidth = this.container.game1.deleteSlot.deleteSlotCase.width / 2;
                        this.autoguidesObjectHeight = this.container.game1.deleteSlot.deleteSlotCase.height / 2;
                        if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                        {
                            this.autoguidesObject = this.container.game1.deleteSlot.deleteSlotCase;
                        }
                    }
                }
                else
                {
                    this.autoguidesObject_pt = this.container.game1.localToGlobal(new Point(this.container.game1.newGame1Case.x, this.container.game1.newGame1Case.y));
                    this.autoguidesObjectWidth = this.container.game1.newGame1Case.width / 2;
                    this.autoguidesObjectHeight = this.container.game1.newGame1Case.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.game1.newGame1Case;
                    }
                }
                if (this.container.game2.currentFrame < 4)
                {
                    if (!this.autoguidesObject)
                    {
                        this.autoguidesObject_pt = this.container.game2.localToGlobal(new Point(this.container.game2.game2Case.x, this.container.game2.game2Case.y));
                        this.autoguidesObjectWidth = this.container.game2.game2Case.width / 2;
                        this.autoguidesObjectHeight = this.container.game2.game2Case.height / 2;
                        if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                        {
                            this.autoguidesObject = this.container.game2.game2Case;
                        }
                    }
                    if (!this.autoguidesObject)
                    {
                        this.autoguidesObject_pt = this.container.game2.deleteSlot.localToGlobal(new Point(this.container.game2.deleteSlot.deleteSlotCase.x, this.container.game2.deleteSlot.deleteSlotCase.y));
                        this.autoguidesObjectWidth = this.container.game2.deleteSlot.deleteSlotCase.width / 2;
                        this.autoguidesObjectHeight = this.container.game2.deleteSlot.deleteSlotCase.height / 2;
                        if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                        {
                            this.autoguidesObject = this.container.game2.deleteSlot.deleteSlotCase;
                        }
                    }
                }
                else if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.game2.localToGlobal(new Point(this.container.game2.newGame2Case.x, this.container.game2.newGame2Case.y));
                    this.autoguidesObjectWidth = this.container.game2.newGame2Case.width / 2;
                    this.autoguidesObjectHeight = this.container.game2.newGame2Case.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.game2.newGame2Case;
                    }
                }
                if (this.container.game3.currentFrame < 4)
                {
                    if (!this.autoguidesObject)
                    {
                        this.autoguidesObject_pt = this.container.game3.localToGlobal(new Point(this.container.game3.game3Case.x, this.container.game3.game3Case.y));
                        this.autoguidesObjectWidth = this.container.game3.game3Case.width / 2;
                        this.autoguidesObjectHeight = this.container.game3.game3Case.height / 2;
                        if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                        {
                            this.autoguidesObject = this.container.game3.game3Case;
                        }
                    }
                    if (!this.autoguidesObject)
                    {
                        this.autoguidesObject_pt = this.container.game3.deleteSlot.localToGlobal(new Point(this.container.game3.deleteSlot.deleteSlotCase.x, this.container.game3.deleteSlot.deleteSlotCase.y));
                        this.autoguidesObjectWidth = this.container.game3.deleteSlot.deleteSlotCase.width / 2;
                        this.autoguidesObjectHeight = this.container.game3.deleteSlot.deleteSlotCase.height / 2;
                        if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                        {
                            this.autoguidesObject = this.container.game3.deleteSlot.deleteSlotCase;
                        }
                    }
                }
                else if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.game3.localToGlobal(new Point(this.container.game3.newGame3Case.x, this.container.game3.newGame3Case.y));
                    this.autoguidesObjectWidth = this.container.game3.newGame3Case.width / 2;
                    this.autoguidesObjectHeight = this.container.game3.newGame3Case.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.game3.newGame3Case;
                    }
                }
                if (this.container.question)
                {
                    if (!this.autoguidesObject)
                    {
                        this.autoguidesObject_pt = this.container.question.btnYes.localToGlobal(new Point(this.container.question.btnYes.yesCase.x, this.container.question.btnYes.yesCase.y));
                        this.autoguidesObjectWidth = this.container.question.btnYes.yesCase.width / 2;
                        this.autoguidesObjectHeight = this.container.question.btnYes.yesCase.height / 2;
                        if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                        {
                            this.autoguidesObject = this.container.question.btnYes.yesCase;
                        }
                    }
                    if (!this.autoguidesObject)
                    {
                        this.autoguidesObject_pt = this.container.question.btnNo.localToGlobal(new Point(this.container.question.btnNo.noCase.x, this.container.question.btnNo.noCase.y));
                        this.autoguidesObjectWidth = this.container.question.btnNo.noCase.width / 2;
                        this.autoguidesObjectHeight = this.container.question.btnNo.noCase.height / 2;
                        if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                        {
                            this.autoguidesObject = this.container.question.btnNo.noCase;
                        }
                    }
                }
            }
            if (!this.autoguidesObject)
            {
                if (this.container.back.visible)
                {
                    this.autoguidesObject_pt = this.container.back.localToGlobal(new Point(this.container.back.backCase.x, this.container.back.backCase.y));
                    this.autoguidesObjectWidth = this.container.back.backCase.width / 2;
                    this.autoguidesObjectHeight = this.container.back.backCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.back.backCase;
                    }
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

        public function manageListeners(param1:String) : void
        {
            if (param1 == "on")
            {
                this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
                this.addEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
                this.addEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
                this.addEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            }
            else if (param1 == "off")
            {
                this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
                this.removeEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
                this.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
                this.removeEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
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
