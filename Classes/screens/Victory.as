package screens
{
    import engine.*;
    import fl.video.*;
    import flash.display.*;
    import flash.events.*;

    public class Victory extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:MovieClip;
        public var frameCounter:int = 0;
        public var openFlag:Boolean = true;
        public var starsFlag:int;
        public var world:World;
        public var firstSoundPlay:Boolean;

        public function Victory()
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
            if (this.world.saveBox.gameSave.data.complexityLevel < 4)
            {
                if (this.world.nowLevel < 15)
                {
                    this.container = new WinMenu_mc();
                }
                else
                {
                    this.container = new WinMenuFinish_mc();
                    this.container.first.sponsor.stop();
                    this.container.first.sponsor.setMouseEnabled(false);
                    this.container.first.sponsor.setMouseChildren(false);
                }
            }
            else
            {
                this.container = new WinSurvMenu_mc();
            }
            this.container.stop();
            this.container.first.stop();
            this.container.first.stars.stop();
            this.container.first.scroll.stop();
            this.container.first.scroll.btnContinue.stop();
            this.container.first.scroll.btnContinue.arrow.stop();
            this.container.first.scroll.btnRestart.stop();
            this.container.first.scroll.btnRestart.arrow.stop();
            this.container.first.scroll.btnContinue.continueCase.setMouseEnabled(true);
            this.container.first.scroll.btnRestart.restartCase.setMouseEnabled(true);
            var _loc_2:* = false;
            this.container.first.setMouseChildren(false);
            this.container.first.mouseEnabled = _loc_2;
            this.container.first.scroll.btnContinue.arrow.visible = false;
            this.container.first.scroll.btnRestart.arrow.visible = false;
            this.container.first.scroll.btnY8.stop();
            this.container.first.scroll.btnY8.y8Case.stop();
            if (!Main.mainClass.IDIClass.isSponsor)
            {
                this.container.first.scroll.btnY8.y8Case.setMouseEnabled(true);
            }
            this.addChild(this.container);
            if (this.world.saveBox.gameSave.data.complexityLevel < 4)
            {
                if (this.world.live >= 18)
                {
                    this.starsFlag = 3;
                    if (Main.mainClass.saveBoxClass.gameSave.data.training_91 == 0)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.training_91 = Main.mainClass.saveBoxClass.playLevel;
                    }
                }
                else if (this.world.live >= 8)
                {
                    this.starsFlag = 2;
                }
                else
                {
                    this.starsFlag = 1;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.starsOfLevels[(Main.mainClass.saveBoxClass.playLevel - 1)] < this.starsFlag)
                {
                    Main.mainClass.saveBoxClass.gameSave.data.stars = Main.mainClass.saveBoxClass.gameSave.data.stars + (this.starsFlag - Main.mainClass.saveBoxClass.gameSave.data.starsOfLevels[(Main.mainClass.saveBoxClass.playLevel - 1)]);
                    Main.mainClass.saveBoxClass.gameSave.data.newStarsForLevel = Main.mainClass.saveBoxClass.playLevel;
                    Main.mainClass.saveBoxClass.gameSave.data.starsOfLevels[(Main.mainClass.saveBoxClass.playLevel - 1)] = this.starsFlag;
                }
            }
            else if (Main.mainClass.saveBoxClass.gameSave.data.starsOfLevels[(Main.mainClass.saveBoxClass.playLevel - 1)] < 4)
            {
                this.starsFlag = 1;
                if (Main.mainClass.saveBoxClass.gameSave.data.starsOfLevels[(Main.mainClass.saveBoxClass.playLevel - 1)] == 3)
                {
                    Main.mainClass.saveBoxClass.gameSave.data.stars++;
                    Main.mainClass.saveBoxClass.gameSave.data.newStarsForLevel = Main.mainClass.saveBoxClass.playLevel;
                    Main.mainClass.saveBoxClass.gameSave.data.starsOfLevels[(Main.mainClass.saveBoxClass.playLevel - 1)]++;
                }
            }
            if (Main.mainClass.saveBoxClass.playLevel < 15)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[Main.mainClass.saveBoxClass.playLevel] == 0)
                {
                    Main.mainClass.saveBoxClass.gameSave.data.newLevel = Main.mainClass.saveBoxClass.playLevel + 1;
                    Main.mainClass.saveBoxClass.gameSave.data.openLevels[Main.mainClass.saveBoxClass.playLevel] = 1;
                    if (Main.mainClass.saveBoxClass.playLevel == 1)
                    {
                        if (this.world.saveBox.gameSave.data.complexityLevel < 4)
                        {
                            if (Main.mainClass.saveBoxClass.gameSave.data.training_9 == 0)
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.training_9 = 1;
                            }
                        }
                    }
                }
            }
            if (Main.mainClass.saveBoxClass.gameSave.data.levelsFinish[(Main.mainClass.saveBoxClass.playLevel - 1)] < this.world.saveBox.gameSave.data.complexityLevel && this.world.saveBox.gameSave.data.complexityLevel < 4)
            {
                Main.mainClass.saveBoxClass.gameSave.data.levelsFinish[(Main.mainClass.saveBoxClass.playLevel - 1)] = this.world.saveBox.gameSave.data.complexityLevel;
            }
            if (this.world.castFireCounter == 0 && this.world.castIceCounter == 0 && this.world.castStoneCounter == 0 && this.world.castLevinCounter == 0 && this.world.castGetAllCounter == 0)
            {
                this.world.achieveManage("notCast");
            }
            if (this.world.saveBox.gameSave.data.complexityLevel == 1)
            {
                this.world.saveBox.gameSave.data.addit_completeEasyLevelsCounter++;
            }
            if (this.world.saveBox.gameSave.data.complexityLevel == 2)
            {
                this.world.saveBox.gameSave.data.addit_completeNormalLevelsCounter++;
            }
            if (this.world.saveBox.gameSave.data.complexityLevel == 3)
            {
                this.world.saveBox.gameSave.data.addit_completeHardLevelsCounter++;
            }
            if (this.world.saveBox.gameSave.data.complexityLevel == 4)
            {
                this.world.saveBox.gameSave.data.addit_completeSurvivalLevelsCounter++;
            }
            if (this.world.live == this.world.liveMax)
            {
                this.world.saveBox.gameSave.data.addit_completeLevelsWithAllLivesCounter++;
            }
            if (this.world.saveBox.gameSave.data.addit_completeHardLevelsCounter == 10)
            {
                this.world.achieveManage("complete_10_hardLevels");
            }
            if (this.world.saveBox.gameSave.data.addit_completeSurvivalLevelsCounter == 10)
            {
                this.world.achieveManage("complete_10_survivalLevels");
            }
            if (this.world.saveBox.gameSave.data.addit_completeLevelsWithAllLivesCounter == 10)
            {
                this.world.achieveManage("complete_10_withAllLives");
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
                    Sounds.instance.playSound("snd_menu_victory");
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
                    this.container.first.setMouseChildren(true);
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
                        this.container.first.scroll.btnContinue.continueCase.setMouseEnabled(true);
                        this.container.first.scroll.btnRestart.restartCase.setMouseEnabled(true);
                        this.container.first.scroll.btnContinue.arrow.visible = false;
                        this.container.first.scroll.btnRestart.arrow.visible = false;
                    }
                }
            }
            else if (this.starsFlag > 0)
            {
                if (this.starsFlag == 1)
                {
                    if (this.container.first.stars.currentFrame < 17)
                    {
                        this.container.first.stars.gotoAndStop((this.container.first.stars.currentFrame + 1));
                    }
                    else
                    {
                        this.starsFlag = 0;
                        if (this.container.first.sponsor)
                        {
                            this.container.first.sponsor.gotoAndStop(2);
                        }
                    }
                }
                else if (this.starsFlag == 2)
                {
                    if (this.container.first.stars.currentFrame < 29)
                    {
                        this.container.first.stars.gotoAndStop((this.container.first.stars.currentFrame + 1));
                    }
                    else
                    {
                        this.starsFlag = 0;
                        if (this.container.first.sponsor)
                        {
                            this.container.first.sponsor.gotoAndStop(2);
                        }
                    }
                }
                else if (this.starsFlag == 3)
                {
                    if (this.container.first.stars.currentFrame < this.container.first.stars.totalFrames)
                    {
                        this.container.first.stars.gotoAndStop((this.container.first.stars.currentFrame + 1));
                    }
                    else
                    {
                        this.starsFlag = 0;
                        if (this.container.first.sponsor)
                        {
                            this.container.first.sponsor.gotoAndStop(2);
                        }
                    }
                }
                if (this.container.first.stars.currentFrame == 10 || this.container.first.stars.currentFrame == 19 || this.container.first.stars.currentFrame == 31)
                {
                    Sounds.instance.playSound("snd_menu_victoryStar");
                }
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
            if (this.container.first.sponsor)
            {
                if (this.container.first.sponsor.currentFrame > 1)
                {
                    if (this.container.first.sponsor.currentFrame < this.container.first.sponsor.totalFrames)
                    {
                        this.container.first.sponsor.gotoAndStop((this.container.first.sponsor.currentFrame + 1));
                        if (this.container.first.sponsor.link1)
                        {
                            if (!this.container.first.sponsor.link1.link1Case.mouseEnabled)
                            {
                                this.container.first.sponsor.link1.stop();
                                this.container.first.sponsor.link1.cont.stop();
                                this.container.first.sponsor.link1.link1Case.stop();
                                this.container.first.sponsor.link1.link1Case.setMouseEnabled(true);
                                (this.container.first.sponsor.link1.cont.aa_video as FLVPlayback).addEventListener(VideoEvent.COMPLETE, this.link1Play);
                            }
                        }
                        if (this.container.first.sponsor.link2)
                        {
                            if (!this.container.first.sponsor.link2.link2Case.mouseEnabled)
                            {
                                this.container.first.sponsor.link2.stop();
                                this.container.first.sponsor.link2.cont.stop();
                                this.container.first.sponsor.link2.link2Case.stop();
                                this.container.first.sponsor.link2.link2Case.setMouseEnabled(true);
                                (this.container.first.sponsor.link2.cont.wh_video as FLVPlayback).addEventListener(VideoEvent.COMPLETE, this.link2Play);
                            }
                        }
                        if (this.container.first.sponsor.link3)
                        {
                            if (!this.container.first.sponsor.link3.link3Case.mouseEnabled)
                            {
                                this.container.first.sponsor.link3.stop();
                                this.container.first.sponsor.link3.cont.stop();
                                this.container.first.sponsor.link3.link3Case.stop();
                                this.container.first.sponsor.link3.link3Case.setMouseEnabled(true);
                                (this.container.first.sponsor.link3.cont.mk_video as FLVPlayback).addEventListener(VideoEvent.COMPLETE, this.link3Play);
                            }
                        }
                        if (this.container.first.sponsor.currentFrame == this.container.first.sponsor.totalFrames)
                        {
                            this.container.first.sponsor.setMouseEnabled(true);
                            this.container.first.sponsor.setMouseChildren(true);
                        }
                    }
                }
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
            if (this.container.first.scroll.btnY8.y8Case.mouseEnabled)
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
            if (this.container.first.sponsor)
            {
                if (this.container.first.sponsor.link1)
                {
                    if (event.target.name == "link1Case")
                    {
                        if (this.container.first.sponsor.link1.currentFrame == 1)
                        {
                            this.container.first.sponsor.link1.gotoAndStop(2);
                            Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                        }
                    }
                    else if (this.container.first.sponsor.link1.currentFrame == 2)
                    {
                        this.container.first.sponsor.link1.gotoAndStop(1);
                    }
                }
                if (this.container.first.sponsor.link2)
                {
                    if (event.target.name == "link2Case")
                    {
                        if (this.container.first.sponsor.link2.currentFrame == 1)
                        {
                            this.container.first.sponsor.link2.gotoAndStop(2);
                            Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                        }
                    }
                    else if (this.container.first.sponsor.link2.currentFrame == 2)
                    {
                        this.container.first.sponsor.link2.gotoAndStop(1);
                    }
                }
                if (this.container.first.sponsor.link3)
                {
                    if (event.target.name == "link3Case")
                    {
                        if (this.container.first.sponsor.link3.currentFrame == 1)
                        {
                            this.container.first.sponsor.link3.gotoAndStop(2);
                            Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                        }
                    }
                    else if (this.container.first.sponsor.link3.currentFrame == 2)
                    {
                        this.container.first.sponsor.link3.gotoAndStop(1);
                    }
                }
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
            if (this.container.first.sponsor)
            {
                if (this.container.first.sponsor.link1)
                {
                    if (event.target.name == "link1Case")
                    {
                        if (this.container.first.sponsor.link1.currentFrame == 2)
                        {
                            this.container.first.sponsor.link1.gotoAndStop(3);
                            Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                        }
                    }
                }
                if (this.container.first.sponsor.link2)
                {
                    if (event.target.name == "link2Case")
                    {
                        if (this.container.first.sponsor.link2.currentFrame == 2)
                        {
                            this.container.first.sponsor.link2.gotoAndStop(3);
                            Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                        }
                    }
                }
                if (this.container.first.sponsor.link3)
                {
                    if (event.target.name == "link3Case")
                    {
                        if (this.container.first.sponsor.link3.currentFrame == 2)
                        {
                            this.container.first.sponsor.link3.gotoAndStop(3);
                            Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                        }
                    }
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
                    if (this.container.first.sponsor)
                    {
                        if (this.container.first.sponsor.link1)
                        {
                            this.removeLinksListeners();
                            this.container.first.sponsor.removeChild(this.container.first.sponsor.link1);
                            this.container.first.sponsor.link1 = null;
                        }
                        if (this.container.first.sponsor.link2)
                        {
                            this.container.first.sponsor.removeChild(this.container.first.sponsor.link2);
                            this.container.first.sponsor.link2 = null;
                        }
                        if (this.container.first.sponsor.link3)
                        {
                            this.container.first.sponsor.removeChild(this.container.first.sponsor.link3);
                            this.container.first.sponsor.link3 = null;
                        }
                    }
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
                    if (this.container.first.sponsor)
                    {
                        if (this.container.first.sponsor.link1)
                        {
                            this.removeLinksListeners();
                            this.container.first.sponsor.removeChild(this.container.first.sponsor.link1);
                            this.container.first.sponsor.link1 = null;
                        }
                        if (this.container.first.sponsor.link2)
                        {
                            this.container.first.sponsor.removeChild(this.container.first.sponsor.link2);
                            this.container.first.sponsor.link2 = null;
                        }
                        if (this.container.first.sponsor.link3)
                        {
                            this.container.first.sponsor.removeChild(this.container.first.sponsor.link3);
                            this.container.first.sponsor.link3 = null;
                        }
                    }
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
            if (this.container.first.sponsor)
            {
                if (this.container.first.sponsor.link1)
                {
                    if (event.target.name == "link1Case")
                    {
                        if (this.container.first.sponsor.link1.currentFrame == 3)
                        {
                            this.container.first.sponsor.link1.gotoAndStop(2);
                            navigateToURL(new URLRequest("http://ru.y8.com/games/asgard_attack"));
                        }
                    }
                    else if (this.container.first.sponsor.link1.currentFrame == 3)
                    {
                        this.container.first.sponsor.link1.gotoAndStop(1);
                    }
                }
                if (this.container.first.sponsor.link2)
                {
                    if (event.target.name == "link2Case")
                    {
                        if (this.container.first.sponsor.link2.currentFrame == 3)
                        {
                            this.container.first.sponsor.link2.gotoAndStop(2);
                            navigateToURL(new URLRequest("http://ru.y8.com/games/war_heroes"));
                        }
                    }
                    else if (this.container.first.sponsor.link2.currentFrame == 3)
                    {
                        this.container.first.sponsor.link2.gotoAndStop(1);
                    }
                }
                if (this.container.first.sponsor.link3)
                {
                    if (event.target.name == "link3Case")
                    {
                        if (this.container.first.sponsor.link3.currentFrame == 3)
                        {
                            this.container.first.sponsor.link3.gotoAndStop(2);
                            navigateToURL(new URLRequest("http://ru.y8.com/games/mighty_knight_2"));
                        }
                    }
                    else if (this.container.first.sponsor.link3.currentFrame == 3)
                    {
                        this.container.first.sponsor.link3.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

        public function link1Play(event:VideoEvent) : void
        {
            if (this.container.first.sponsor)
            {
                (this.container.first.sponsor.link1.cont.aa_video as FLVPlayback).play();
            }
            return;
        }// end function

        public function link2Play(event:VideoEvent) : void
        {
            if (this.container.first.sponsor)
            {
                (this.container.first.sponsor.link2.cont.wh_video as FLVPlayback).play();
            }
            return;
        }// end function

        public function link3Play(event:VideoEvent) : void
        {
            if (this.container.first.sponsor)
            {
                (this.container.first.sponsor.link3.cont.mk_video as FLVPlayback).play();
            }
            return;
        }// end function

        public function removeLinksListeners() : void
        {
            if (this.container.first.sponsor)
            {
                if (this.container.first.sponsor.link1)
                {
                    (this.container.first.sponsor.link1.cont.aa_video as FLVPlayback).removeEventListener(VideoEvent.COMPLETE, this.link1Play);
                }
                if (this.container.first.sponsor.link2)
                {
                    (this.container.first.sponsor.link2.cont.wh_video as FLVPlayback).removeEventListener(VideoEvent.COMPLETE, this.link2Play);
                }
                if (this.container.first.sponsor.link3)
                {
                    (this.container.first.sponsor.link3.cont.mk_video as FLVPlayback).removeEventListener(VideoEvent.COMPLETE, this.link3Play);
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
            this.removeLinksListeners();
            return;
        }// end function

    }
}
