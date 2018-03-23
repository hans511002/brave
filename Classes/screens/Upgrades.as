package screens
{
    import flash.display.*;
    import flash.events.*;

    public class Upgrades extends Sprite
    {
        public var i:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:Upgrades_mc;
        public var frameCounter:int = 0;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var levelsMenu:LevelsMenu;
        public var nowUpgradeButton:MovieClip;
        public var dead:Boolean;
        public var hint:HintUpgrade_mc;
        public var listOfUpgradeAnima:Array;
        public var costGolemUpgrade1:int = 2;
        public var costGolemUpgrade2:int = 2;
        public var costGolemUpgrade3:int = 2;
        public var costGolemUpgrade4:int = 3;
        public var costGolemUpgrade5:int = 4;
        public var costIcemanUpgrade1:int = 1;
        public var costIcemanUpgrade2:int = 2;
        public var costIcemanUpgrade3:int = 2;
        public var costIcemanUpgrade4:int = 3;
        public var costIcemanUpgrade5:int = 4;
        public var costAirUpgrade1:int = 1;
        public var costAirUpgrade2:int = 2;
        public var costAirUpgrade3:int = 2;
        public var costAirUpgrade4:int = 3;
        public var costAirUpgrade5:int = 4;
        public var costFireUpgrade1:int = 1;
        public var costFireUpgrade2:int = 1;
        public var costFireUpgrade3:int = 1;
        public var costFireUpgrade4:int = 1;
        public var costFireUpgrade5:int = 2;
        public var costIceUpgrade1:int = 1;
        public var costIceUpgrade2:int = 1;
        public var costIceUpgrade3:int = 1;
        public var costIceUpgrade4:int = 1;
        public var costIceUpgrade5:int = 2;
        public var costStoneUpgrade1:int = 1;
        public var costStoneUpgrade2:int = 1;
        public var costStoneUpgrade3:int = 1;
        public var costStoneUpgrade4:int = 1;
        public var costStoneUpgrade5:int = 2;
        public var costLevinUpgrade1:int = 1;
        public var costLevinUpgrade2:int = 1;
        public var costLevinUpgrade3:int = 2;
        public var costLevinUpgrade4:int = 2;
        public var costLevinUpgrade5:int = 2;

        public function Upgrades()
        {
            this.listOfUpgradeAnima = [];
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.stage.frameRate = 60;
            this.levelsMenu = Main.mainClass.levelsMenuClass;
            this.levelsMenu.manageListeners("off");
            this.manageListeners("on");
            this.container = new Upgrades_mc();
            this.container.stop();
            this.container.back.stop();
            this.container.back.backCase.stop();
            this.container.back.backCase.buttonMode = true;
            this.container.cont.stop();
            this.container.cont.btnReset.stop();
            this.container.cont.btnAccept.stop();
            this.container.cont.golemArrow1.stop();
            this.container.cont.golemArrow2.stop();
            this.container.cont.golemArrow3.stop();
            this.container.cont.golemArrow4.stop();
            this.container.cont.icemanArrow1.stop();
            this.container.cont.icemanArrow2.stop();
            this.container.cont.icemanArrow3.stop();
            this.container.cont.icemanArrow4.stop();
            this.container.cont.airArrow1.stop();
            this.container.cont.airArrow2.stop();
            this.container.cont.airArrow3.stop();
            this.container.cont.airArrow4.stop();
            this.container.cont.fireArrow1.stop();
            this.container.cont.fireArrow2.stop();
            this.container.cont.fireArrow3.stop();
            this.container.cont.fireArrow4.stop();
            this.container.cont.iceArrow1.stop();
            this.container.cont.iceArrow2.stop();
            this.container.cont.iceArrow3.stop();
            this.container.cont.iceArrow4.stop();
            this.container.cont.stoneArrow1.stop();
            this.container.cont.stoneArrow2.stop();
            this.container.cont.stoneArrow3.stop();
            this.container.cont.stoneArrow4.stop();
            this.container.cont.levinArrow1.stop();
            this.container.cont.levinArrow2.stop();
            this.container.cont.levinArrow3.stop();
            this.container.cont.levinArrow4.stop();
            this.container.cont.btnReset.resetCase.buttonMode = true;
            this.container.cont.btnAccept.acceptCase.buttonMode = true;
            this.container.cont.golemArrow1.visible = false;
            this.container.cont.golemArrow2.visible = false;
            this.container.cont.golemArrow3.visible = false;
            this.container.cont.golemArrow4.visible = false;
            this.container.cont.icemanArrow1.visible = false;
            this.container.cont.icemanArrow2.visible = false;
            this.container.cont.icemanArrow3.visible = false;
            this.container.cont.icemanArrow4.visible = false;
            this.container.cont.airArrow1.visible = false;
            this.container.cont.airArrow2.visible = false;
            this.container.cont.airArrow3.visible = false;
            this.container.cont.airArrow4.visible = false;
            this.container.cont.fireArrow1.visible = false;
            this.container.cont.fireArrow2.visible = false;
            this.container.cont.fireArrow3.visible = false;
            this.container.cont.fireArrow4.visible = false;
            this.container.cont.iceArrow1.visible = false;
            this.container.cont.iceArrow2.visible = false;
            this.container.cont.iceArrow3.visible = false;
            this.container.cont.iceArrow4.visible = false;
            this.container.cont.stoneArrow1.visible = false;
            this.container.cont.stoneArrow2.visible = false;
            this.container.cont.stoneArrow3.visible = false;
            this.container.cont.stoneArrow4.visible = false;
            this.container.cont.levinArrow1.visible = false;
            this.container.cont.levinArrow2.visible = false;
            this.container.cont.levinArrow3.visible = false;
            this.container.cont.levinArrow4.visible = false;
            this.addChild(this.container);
            this.hint = new HintUpgrade_mc();
            this.hint.stop();
            this.hint.myTarget = null;
            var _loc_2:* = false;
            this.hint.mouseChildren = false;
            this.hint.mouseEnabled = _loc_2;
            this.hint.visible = false;
            this.addChild(this.hint);
            this.upgradeUpdate();
            var _loc_2:* = false;
            this.container.cont.mouseChildren = false;
            this.container.cont.mouseEnabled = _loc_2;
            Sounds.instance.playSound("snd_menu_openBoard");
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
                else
                {
                    this.openFlag = false;
                    var _loc_2:* = true;
                    this.container.cont.mouseChildren = true;
                    this.container.cont.mouseEnabled = _loc_2;
                    this.upgradeUpdate();
                    this.stage.frameRate = 30;
                }
            }
            else if (this.closeFlag)
            {
                if (this.container.currentFrame > 1)
                {
                    this.container.gotoAndStop((this.container.currentFrame - 1));
                }
                else
                {
                    this.closeFlag = false;
                    this.kill();
                }
            }
            if (this.listOfUpgradeAnima.length > 0)
            {
                this.i = this.listOfUpgradeAnima.length - 1;
                while (this.i >= 0)
                {
                    
                    if (this.listOfUpgradeAnima[this.i].currentFrame < this.listOfUpgradeAnima[this.i].totalFrames)
                    {
                        this.listOfUpgradeAnima[this.i].gotoAndStop((this.listOfUpgradeAnima[this.i].currentFrame + 1));
                    }
                    else
                    {
                        this.removeChild(this.listOfUpgradeAnima[this.i]);
                        this.listOfUpgradeAnima.splice(this.i, 1);
                    }
                    var _loc_2:* = this;
                    var _loc_3:* = this.i - 1;
                    _loc_2.i = _loc_3;
                }
            }
            if (this.hint.visible)
            {
                this.hint.x = this.mouseX;
                this.hint.y = this.mouseY;
            }
            this.setChildIndex(this.hint, (this.numChildren - 1));
            return;
        }// end function

        public function mouseMoveHandler(event:MouseEvent) : void
        {
            if (event.target.name == "backCase")
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
            if (event.target.name == "resetCase")
            {
                if (this.container.cont.btnReset.currentFrame == 1)
                {
                    this.container.cont.btnReset.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.btnReset.currentFrame == 2)
            {
                this.container.cont.btnReset.gotoAndStop(1);
            }
            if (event.target.name == "acceptCase")
            {
                if (this.container.cont.btnAccept.currentFrame == 1)
                {
                    this.container.cont.btnAccept.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.btnAccept.currentFrame == 2)
            {
                this.container.cont.btnAccept.gotoAndStop(1);
            }
            if (event.target.name == "upgradeCase")
            {
                if (this.nowUpgradeButton)
                {
                    if (this.nowUpgradeButton != event.target.parent)
                    {
                        if (this.nowUpgradeButton.currentFrame == 2)
                        {
                            this.tempObject = this.nowUpgradeButton.starsTXT.text;
                            this.nowUpgradeButton.gotoAndStop(1);
                            this.nowUpgradeButton.starsTXT.text = this.tempObject;
                            this.nowUpgradeButton.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                        }
                    }
                }
                this.nowUpgradeButton = event.target.parent;
                if (this.nowUpgradeButton.currentFrame == 1)
                {
                    this.tempObject = this.nowUpgradeButton.starsTXT.text;
                    this.nowUpgradeButton.gotoAndStop(2);
                    this.nowUpgradeButton.starsTXT.text = this.tempObject;
                    this.nowUpgradeButton.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
                if (!this.hint.visible || this.hint.myTarget != this.nowUpgradeButton)
                {
                    this.hint.visible = true;
                    this.hint.myTarget = this.nowUpgradeButton;
                    if (this.hint.myTarget.name == "golemUpgrade1")
                    {
                        this.hint.gotoAndStop(1);
                    }
                    else if (this.hint.myTarget.name == "golemUpgrade2")
                    {
                        this.hint.gotoAndStop(2);
                    }
                    else if (this.hint.myTarget.name == "golemUpgrade3")
                    {
                        this.hint.gotoAndStop(3);
                    }
                    else if (this.hint.myTarget.name == "golemUpgrade4")
                    {
                        this.hint.gotoAndStop(4);
                    }
                    else if (this.hint.myTarget.name == "golemUpgrade5")
                    {
                        this.hint.gotoAndStop(5);
                    }
                    else if (this.hint.myTarget.name == "icemanUpgrade1")
                    {
                        this.hint.gotoAndStop(6);
                    }
                    else if (this.hint.myTarget.name == "icemanUpgrade2")
                    {
                        this.hint.gotoAndStop(7);
                    }
                    else if (this.hint.myTarget.name == "icemanUpgrade3")
                    {
                        this.hint.gotoAndStop(8);
                    }
                    else if (this.hint.myTarget.name == "icemanUpgrade4")
                    {
                        this.hint.gotoAndStop(9);
                    }
                    else if (this.hint.myTarget.name == "icemanUpgrade5")
                    {
                        this.hint.gotoAndStop(10);
                    }
                    else if (this.hint.myTarget.name == "airUpgrade1")
                    {
                        this.hint.gotoAndStop(11);
                    }
                    else if (this.hint.myTarget.name == "airUpgrade2")
                    {
                        this.hint.gotoAndStop(12);
                    }
                    else if (this.hint.myTarget.name == "airUpgrade3")
                    {
                        this.hint.gotoAndStop(13);
                    }
                    else if (this.hint.myTarget.name == "airUpgrade4")
                    {
                        this.hint.gotoAndStop(14);
                    }
                    else if (this.hint.myTarget.name == "airUpgrade5")
                    {
                        this.hint.gotoAndStop(15);
                    }
                    else if (this.hint.myTarget.name == "fireUpgrade1")
                    {
                        this.hint.gotoAndStop(16);
                    }
                    else if (this.hint.myTarget.name == "fireUpgrade2")
                    {
                        this.hint.gotoAndStop(17);
                    }
                    else if (this.hint.myTarget.name == "fireUpgrade3")
                    {
                        this.hint.gotoAndStop(18);
                    }
                    else if (this.hint.myTarget.name == "fireUpgrade4")
                    {
                        this.hint.gotoAndStop(19);
                    }
                    else if (this.hint.myTarget.name == "fireUpgrade5")
                    {
                        this.hint.gotoAndStop(20);
                    }
                    else if (this.hint.myTarget.name == "iceUpgrade1")
                    {
                        this.hint.gotoAndStop(21);
                    }
                    else if (this.hint.myTarget.name == "iceUpgrade2")
                    {
                        this.hint.gotoAndStop(22);
                    }
                    else if (this.hint.myTarget.name == "iceUpgrade3")
                    {
                        this.hint.gotoAndStop(23);
                    }
                    else if (this.hint.myTarget.name == "iceUpgrade4")
                    {
                        this.hint.gotoAndStop(24);
                    }
                    else if (this.hint.myTarget.name == "iceUpgrade5")
                    {
                        this.hint.gotoAndStop(25);
                    }
                    else if (this.hint.myTarget.name == "stoneUpgrade1")
                    {
                        this.hint.gotoAndStop(26);
                    }
                    else if (this.hint.myTarget.name == "stoneUpgrade2")
                    {
                        this.hint.gotoAndStop(27);
                    }
                    else if (this.hint.myTarget.name == "stoneUpgrade3")
                    {
                        this.hint.gotoAndStop(28);
                    }
                    else if (this.hint.myTarget.name == "stoneUpgrade4")
                    {
                        this.hint.gotoAndStop(29);
                    }
                    else if (this.hint.myTarget.name == "stoneUpgrade5")
                    {
                        this.hint.gotoAndStop(30);
                    }
                    else if (this.hint.myTarget.name == "levinUpgrade1")
                    {
                        this.hint.gotoAndStop(31);
                    }
                    else if (this.hint.myTarget.name == "levinUpgrade2")
                    {
                        this.hint.gotoAndStop(32);
                    }
                    else if (this.hint.myTarget.name == "levinUpgrade3")
                    {
                        this.hint.gotoAndStop(33);
                    }
                    else if (this.hint.myTarget.name == "levinUpgrade4")
                    {
                        this.hint.gotoAndStop(34);
                    }
                    else if (this.hint.myTarget.name == "levinUpgrade5")
                    {
                        this.hint.gotoAndStop(35);
                    }
                    this.hint.x = this.mouseX;
                    this.hint.y = this.mouseY;
                }
            }
            else if (this.nowUpgradeButton)
            {
                if (this.nowUpgradeButton.currentFrame == 2)
                {
                    this.tempObject = this.nowUpgradeButton.starsTXT.text;
                    this.nowUpgradeButton.gotoAndStop(1);
                    this.nowUpgradeButton.starsTXT.text = this.tempObject;
                    this.nowUpgradeButton.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                }
                if (this.hint.visible)
                {
                    this.hint.visible = false;
                }
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (!this.openFlag)
            {
                if (event.target.name == "backCase")
                {
                    if (this.container.back.currentFrame == 2)
                    {
                        this.container.back.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "resetCase")
                {
                    if (this.container.cont.btnReset.currentFrame == 2)
                    {
                        this.container.cont.btnReset.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "acceptCase")
                {
                    if (this.container.cont.btnAccept.currentFrame == 2)
                    {
                        this.container.cont.btnAccept.gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (event.target.name == "shadow")
                {
                    this.close();
                }
                else if (event.target.name == "upgradeCase")
                {
                    if (this.nowUpgradeButton)
                    {
                        if (this.nowUpgradeButton != event.target.parent)
                        {
                            if (this.nowUpgradeButton.currentFrame == 2)
                            {
                                this.nowUpgradeButton.gotoAndStop(1);
                            }
                        }
                        if (this.nowUpgradeButton.currentFrame == 2)
                        {
                            this.nowUpgradeButton.gotoAndStop(3);
                            this.tempObject = this.container.cont.localToGlobal(new Point(this.nowUpgradeButton.x, this.nowUpgradeButton.y));
                            this.tempObject1 = new AnimUpgrade_mc();
                            this.tempObject1.stop();
                            this.tempObject1.x = this.tempObject.x;
                            this.tempObject1.y = this.tempObject.y;
                            var _loc_2:* = false;
                            this.tempObject1.mouseChildren = false;
                            this.tempObject1.mouseEnabled = _loc_2;
                            this.addChild(this.tempObject1);
                            this.listOfUpgradeAnima.push(this.tempObject1);
                            Sounds.instance.playSound("snd_menu_upgrIconMouseDown");
                            if (this.nowUpgradeButton.name == "golemUpgrade1")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem1 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costGolemUpgrade1;
                            }
                            else if (this.nowUpgradeButton.name == "golemUpgrade2")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem2 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costGolemUpgrade2;
                            }
                            else if (this.nowUpgradeButton.name == "golemUpgrade3")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem3 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costGolemUpgrade3;
                            }
                            else if (this.nowUpgradeButton.name == "golemUpgrade4")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem4 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costGolemUpgrade4;
                            }
                            else if (this.nowUpgradeButton.name == "golemUpgrade5")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem5 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costGolemUpgrade5;
                            }
                            if (this.nowUpgradeButton.name == "icemanUpgrade1")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman1 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIcemanUpgrade1;
                            }
                            else if (this.nowUpgradeButton.name == "icemanUpgrade2")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman2 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIcemanUpgrade2;
                            }
                            else if (this.nowUpgradeButton.name == "icemanUpgrade3")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman3 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIcemanUpgrade3;
                            }
                            else if (this.nowUpgradeButton.name == "icemanUpgrade4")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman4 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIcemanUpgrade4;
                            }
                            else if (this.nowUpgradeButton.name == "icemanUpgrade5")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman5 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIcemanUpgrade5;
                            }
                            if (this.nowUpgradeButton.name == "airUpgrade1")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeAir1 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costAirUpgrade1;
                            }
                            else if (this.nowUpgradeButton.name == "airUpgrade2")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeAir2 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costAirUpgrade2;
                            }
                            else if (this.nowUpgradeButton.name == "airUpgrade3")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeAir3 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costAirUpgrade3;
                            }
                            else if (this.nowUpgradeButton.name == "airUpgrade4")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeAir4 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costAirUpgrade4;
                            }
                            else if (this.nowUpgradeButton.name == "airUpgrade5")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeAir5 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costAirUpgrade5;
                            }
                            if (this.nowUpgradeButton.name == "fireUpgrade1")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeFire1 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costFireUpgrade1;
                            }
                            else if (this.nowUpgradeButton.name == "fireUpgrade2")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeFire2 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costFireUpgrade2;
                            }
                            else if (this.nowUpgradeButton.name == "fireUpgrade3")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeFire3 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costFireUpgrade3;
                            }
                            else if (this.nowUpgradeButton.name == "fireUpgrade4")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeFire4 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costFireUpgrade4;
                            }
                            else if (this.nowUpgradeButton.name == "fireUpgrade5")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeFire5 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costFireUpgrade5;
                            }
                            if (this.nowUpgradeButton.name == "iceUpgrade1")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIce1 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIceUpgrade1;
                            }
                            else if (this.nowUpgradeButton.name == "iceUpgrade2")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIce2 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIceUpgrade2;
                            }
                            else if (this.nowUpgradeButton.name == "iceUpgrade3")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIce3 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIceUpgrade3;
                            }
                            else if (this.nowUpgradeButton.name == "iceUpgrade4")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIce4 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIceUpgrade4;
                            }
                            else if (this.nowUpgradeButton.name == "iceUpgrade5")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeIce5 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costIceUpgrade5;
                            }
                            if (this.nowUpgradeButton.name == "stoneUpgrade1")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeStone1 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costStoneUpgrade1;
                            }
                            else if (this.nowUpgradeButton.name == "stoneUpgrade2")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeStone2 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costStoneUpgrade2;
                            }
                            else if (this.nowUpgradeButton.name == "stoneUpgrade3")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeStone3 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costStoneUpgrade3;
                            }
                            else if (this.nowUpgradeButton.name == "stoneUpgrade4")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeStone4 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costStoneUpgrade4;
                            }
                            else if (this.nowUpgradeButton.name == "stoneUpgrade5")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeStone5 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costStoneUpgrade5;
                            }
                            if (this.nowUpgradeButton.name == "levinUpgrade1")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin1 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costLevinUpgrade1;
                            }
                            else if (this.nowUpgradeButton.name == "levinUpgrade2")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin2 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costLevinUpgrade2;
                            }
                            else if (this.nowUpgradeButton.name == "levinUpgrade3")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin3 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costLevinUpgrade3;
                            }
                            else if (this.nowUpgradeButton.name == "levinUpgrade4")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin4 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costLevinUpgrade4;
                            }
                            else if (this.nowUpgradeButton.name == "levinUpgrade5")
                            {
                                Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin5 = true;
                                Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) - this.costLevinUpgrade5;
                            }
                            this.upgradeUpdate();
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
                    this.container.back.gotoAndStop(2);
                    this.close();
                }
            }
            else if (this.container.back.currentFrame == 3)
            {
                this.container.back.gotoAndStop(1);
            }
            if (event.target.name == "resetCase")
            {
                if (this.container.cont.btnReset.currentFrame == 3)
                {
                    this.container.cont.btnReset.gotoAndStop(2);
                    Sounds.instance.playSound("snd_menu_upgrReset");
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem1)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem1 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costGolemUpgrade1;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem2)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem2 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costGolemUpgrade2;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem3)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem3 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costGolemUpgrade3;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem4)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem4 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costGolemUpgrade4;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem5)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem5 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costGolemUpgrade5;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman1)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman1 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIcemanUpgrade1;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman2)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman2 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIcemanUpgrade2;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman3)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman3 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIcemanUpgrade3;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman4)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman4 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIcemanUpgrade4;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman5)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman5 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIcemanUpgrade5;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir1)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeAir1 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costAirUpgrade1;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir2)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeAir2 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costAirUpgrade2;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir3)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeAir3 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costAirUpgrade3;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir4)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeAir4 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costAirUpgrade4;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir5)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeAir5 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costAirUpgrade5;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire1)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeFire1 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costFireUpgrade1;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire2)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeFire2 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costFireUpgrade2;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire3)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeFire3 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costFireUpgrade3;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire4)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeFire4 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costFireUpgrade4;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire5)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeFire5 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costFireUpgrade5;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce1)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIce1 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIceUpgrade1;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce2)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIce2 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIceUpgrade2;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce3)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIce3 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIceUpgrade3;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce4)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIce4 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIceUpgrade4;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce5)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeIce5 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costIceUpgrade5;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone1)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeStone1 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costStoneUpgrade1;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone2)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeStone2 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costStoneUpgrade2;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone3)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeStone3 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costStoneUpgrade3;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone4)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeStone4 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costStoneUpgrade4;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone5)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeStone5 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costStoneUpgrade5;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin1)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin1 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costLevinUpgrade1;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin2)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin2 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costLevinUpgrade2;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin3)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin3 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costLevinUpgrade3;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin4)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin4 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costLevinUpgrade4;
                    }
                    if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin5)
                    {
                        Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin5 = false;
                        Main.mainClass.saveBoxClass.gameSave.data.stars = int(Main.mainClass.saveBoxClass.gameSave.data.stars) + this.costLevinUpgrade5;
                    }
                    this.upgradeUpdate();
                }
            }
            else if (this.container.cont.btnReset.currentFrame == 3)
            {
                this.container.cont.btnReset.gotoAndStop(1);
            }
            if (event.target.name == "acceptCase")
            {
                if (this.container.cont.btnAccept.currentFrame == 3)
                {
                    this.container.cont.btnAccept.gotoAndStop(2);
                    this.close();
                }
            }
            else if (this.container.cont.btnAccept.currentFrame == 3)
            {
                this.container.cont.btnAccept.gotoAndStop(1);
            }
            return;
        }// end function

        public function upgradeUpdate() : void
        {
            if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[3] > 0)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem1)
                {
                    this.container.cont.golemUpgrade1.gotoAndStop(3);
                    this.container.cont.golemUpgrade1.upgradeCase.buttonMode = false;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costGolemUpgrade1)
                {
                    this.container.cont.golemUpgrade1.gotoAndStop(1);
                    this.container.cont.golemUpgrade1.starsTXT.text = this.costGolemUpgrade1;
                    this.container.cont.golemUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade1.upgradeCase.buttonMode = true;
                }
                else
                {
                    this.container.cont.golemUpgrade1.gotoAndStop(4);
                    this.container.cont.golemUpgrade1.starsTXT.text = this.costGolemUpgrade1;
                    this.container.cont.golemUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade1.upgradeCase.buttonMode = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem2)
                {
                    this.container.cont.golemUpgrade2.gotoAndStop(3);
                    this.container.cont.golemUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.golemArrow1.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costGolemUpgrade2 && Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem1)
                {
                    this.container.cont.golemUpgrade2.gotoAndStop(1);
                    this.container.cont.golemUpgrade2.starsTXT.text = this.costGolemUpgrade2;
                    this.container.cont.golemUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade2.upgradeCase.buttonMode = true;
                    this.container.cont.golemArrow1.visible = false;
                }
                else
                {
                    this.container.cont.golemUpgrade2.gotoAndStop(4);
                    this.container.cont.golemUpgrade2.starsTXT.text = this.costGolemUpgrade2;
                    this.container.cont.golemUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.golemArrow1.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem3)
                {
                    this.container.cont.golemUpgrade3.gotoAndStop(3);
                    this.container.cont.golemUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.golemArrow2.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costGolemUpgrade3 && Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem2)
                {
                    this.container.cont.golemUpgrade3.gotoAndStop(1);
                    this.container.cont.golemUpgrade3.starsTXT.text = this.costGolemUpgrade3;
                    this.container.cont.golemUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade3.upgradeCase.buttonMode = true;
                    this.container.cont.golemArrow2.visible = false;
                }
                else
                {
                    this.container.cont.golemUpgrade3.gotoAndStop(4);
                    this.container.cont.golemUpgrade3.starsTXT.text = this.costGolemUpgrade3;
                    this.container.cont.golemUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.golemArrow2.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem4)
                {
                    this.container.cont.golemUpgrade4.gotoAndStop(3);
                    this.container.cont.golemUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.golemArrow3.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costGolemUpgrade4 && Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem3)
                {
                    this.container.cont.golemUpgrade4.gotoAndStop(1);
                    this.container.cont.golemUpgrade4.starsTXT.text = this.costGolemUpgrade4;
                    this.container.cont.golemUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade4.upgradeCase.buttonMode = true;
                    this.container.cont.golemArrow3.visible = false;
                }
                else
                {
                    this.container.cont.golemUpgrade4.gotoAndStop(4);
                    this.container.cont.golemUpgrade4.starsTXT.text = this.costGolemUpgrade4;
                    this.container.cont.golemUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.golemArrow3.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem5)
                {
                    this.container.cont.golemUpgrade5.gotoAndStop(3);
                    this.container.cont.golemUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.golemArrow4.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costGolemUpgrade5 && Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem4)
                {
                    this.container.cont.golemUpgrade5.gotoAndStop(1);
                    this.container.cont.golemUpgrade5.starsTXT.text = this.costGolemUpgrade5;
                    this.container.cont.golemUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade5.upgradeCase.buttonMode = true;
                    this.container.cont.golemArrow4.visible = false;
                }
                else
                {
                    this.container.cont.golemUpgrade5.gotoAndStop(4);
                    this.container.cont.golemUpgrade5.starsTXT.text = this.costGolemUpgrade5;
                    this.container.cont.golemUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.golemUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.golemArrow4.visible = false;
                }
            }
            else
            {
                this.container.cont.golemUpgrade1.gotoAndStop(5);
                this.container.cont.golemUpgrade1.starsTXT.text = this.costGolemUpgrade1;
                this.container.cont.golemUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.golemUpgrade1.upgradeCase.buttonMode = false;
                this.container.cont.golemUpgrade2.gotoAndStop(5);
                this.container.cont.golemUpgrade2.starsTXT.text = this.costGolemUpgrade2;
                this.container.cont.golemUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.golemUpgrade2.upgradeCase.buttonMode = false;
                this.container.cont.golemArrow1.visible = false;
                this.container.cont.golemUpgrade3.gotoAndStop(5);
                this.container.cont.golemUpgrade3.starsTXT.text = this.costGolemUpgrade3;
                this.container.cont.golemUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.golemUpgrade3.upgradeCase.buttonMode = false;
                this.container.cont.golemArrow2.visible = false;
                this.container.cont.golemUpgrade4.gotoAndStop(5);
                this.container.cont.golemUpgrade4.starsTXT.text = this.costGolemUpgrade4;
                this.container.cont.golemUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.golemUpgrade4.upgradeCase.buttonMode = false;
                this.container.cont.golemArrow3.visible = false;
                this.container.cont.golemUpgrade5.gotoAndStop(5);
                this.container.cont.golemUpgrade5.starsTXT.text = this.costGolemUpgrade5;
                this.container.cont.golemUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.golemUpgrade5.upgradeCase.buttonMode = false;
                this.container.cont.golemArrow4.visible = false;
            }
            if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[1] > 0 || Main.mainClass.saveBoxClass.gameSave.data.saveNo > 3)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman1)
                {
                    this.container.cont.icemanUpgrade1.gotoAndStop(3);
                    this.container.cont.icemanUpgrade1.upgradeCase.buttonMode = false;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIcemanUpgrade1)
                {
                    this.container.cont.icemanUpgrade1.gotoAndStop(1);
                    this.container.cont.icemanUpgrade1.starsTXT.text = this.costIcemanUpgrade1;
                    this.container.cont.icemanUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade1.upgradeCase.buttonMode = true;
                }
                else
                {
                    this.container.cont.icemanUpgrade1.gotoAndStop(4);
                    this.container.cont.icemanUpgrade1.starsTXT.text = this.costIcemanUpgrade1;
                    this.container.cont.icemanUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade1.upgradeCase.buttonMode = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman2)
                {
                    this.container.cont.icemanUpgrade2.gotoAndStop(3);
                    this.container.cont.icemanUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.icemanArrow1.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIcemanUpgrade2 && Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman1)
                {
                    this.container.cont.icemanUpgrade2.gotoAndStop(1);
                    this.container.cont.icemanUpgrade2.starsTXT.text = this.costIcemanUpgrade2;
                    this.container.cont.icemanUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade2.upgradeCase.buttonMode = true;
                    this.container.cont.icemanArrow1.visible = false;
                }
                else
                {
                    this.container.cont.icemanUpgrade2.gotoAndStop(4);
                    this.container.cont.icemanUpgrade2.starsTXT.text = this.costIcemanUpgrade2;
                    this.container.cont.icemanUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.icemanArrow1.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman3)
                {
                    this.container.cont.icemanUpgrade3.gotoAndStop(3);
                    this.container.cont.icemanUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.icemanArrow2.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIcemanUpgrade3 && Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman2)
                {
                    this.container.cont.icemanUpgrade3.gotoAndStop(1);
                    this.container.cont.icemanUpgrade3.starsTXT.text = this.costIcemanUpgrade3;
                    this.container.cont.icemanUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade3.upgradeCase.buttonMode = true;
                    this.container.cont.icemanArrow2.visible = false;
                }
                else
                {
                    this.container.cont.icemanUpgrade3.gotoAndStop(4);
                    this.container.cont.icemanUpgrade3.starsTXT.text = this.costIcemanUpgrade3;
                    this.container.cont.icemanUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.icemanArrow2.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman4)
                {
                    this.container.cont.icemanUpgrade4.gotoAndStop(3);
                    this.container.cont.icemanUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.icemanArrow3.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIcemanUpgrade4 && Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman3)
                {
                    this.container.cont.icemanUpgrade4.gotoAndStop(1);
                    this.container.cont.icemanUpgrade4.starsTXT.text = this.costIcemanUpgrade4;
                    this.container.cont.icemanUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade4.upgradeCase.buttonMode = true;
                    this.container.cont.icemanArrow3.visible = false;
                }
                else
                {
                    this.container.cont.icemanUpgrade4.gotoAndStop(4);
                    this.container.cont.icemanUpgrade4.starsTXT.text = this.costIcemanUpgrade4;
                    this.container.cont.icemanUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.icemanArrow3.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman5)
                {
                    this.container.cont.icemanUpgrade5.gotoAndStop(3);
                    this.container.cont.icemanUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.icemanArrow4.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIcemanUpgrade5 && Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman4)
                {
                    this.container.cont.icemanUpgrade5.gotoAndStop(1);
                    this.container.cont.icemanUpgrade5.starsTXT.text = this.costIcemanUpgrade5;
                    this.container.cont.icemanUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade5.upgradeCase.buttonMode = true;
                    this.container.cont.icemanArrow4.visible = false;
                }
                else
                {
                    this.container.cont.icemanUpgrade5.gotoAndStop(4);
                    this.container.cont.icemanUpgrade5.starsTXT.text = this.costIcemanUpgrade5;
                    this.container.cont.icemanUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.icemanUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.icemanArrow4.visible = false;
                }
            }
            else
            {
                this.container.cont.icemanUpgrade1.gotoAndStop(5);
                this.container.cont.icemanUpgrade1.starsTXT.text = this.costIcemanUpgrade1;
                this.container.cont.icemanUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.icemanUpgrade1.upgradeCase.buttonMode = false;
                this.container.cont.icemanUpgrade2.gotoAndStop(5);
                this.container.cont.icemanUpgrade2.starsTXT.text = this.costIcemanUpgrade2;
                this.container.cont.icemanUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.icemanUpgrade2.upgradeCase.buttonMode = false;
                this.container.cont.icemanArrow1.visible = false;
                this.container.cont.icemanUpgrade3.gotoAndStop(5);
                this.container.cont.icemanUpgrade3.starsTXT.text = this.costIcemanUpgrade3;
                this.container.cont.icemanUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.icemanUpgrade3.upgradeCase.buttonMode = false;
                this.container.cont.icemanArrow2.visible = false;
                this.container.cont.icemanUpgrade4.gotoAndStop(5);
                this.container.cont.icemanUpgrade4.starsTXT.text = this.costIcemanUpgrade4;
                this.container.cont.icemanUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.icemanUpgrade4.upgradeCase.buttonMode = false;
                this.container.cont.icemanArrow3.visible = false;
                this.container.cont.icemanUpgrade5.gotoAndStop(5);
                this.container.cont.icemanUpgrade5.starsTXT.text = this.costIcemanUpgrade5;
                this.container.cont.icemanUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.icemanUpgrade5.upgradeCase.buttonMode = false;
                this.container.cont.icemanArrow4.visible = false;
            }
            if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[2] > 0)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir1)
                {
                    this.container.cont.airUpgrade1.gotoAndStop(3);
                    this.container.cont.airUpgrade1.upgradeCase.buttonMode = false;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costAirUpgrade1)
                {
                    this.container.cont.airUpgrade1.gotoAndStop(1);
                    this.container.cont.airUpgrade1.starsTXT.text = this.costAirUpgrade1;
                    this.container.cont.airUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade1.upgradeCase.buttonMode = true;
                }
                else
                {
                    this.container.cont.airUpgrade1.gotoAndStop(4);
                    this.container.cont.airUpgrade1.starsTXT.text = this.costAirUpgrade1;
                    this.container.cont.airUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade1.upgradeCase.buttonMode = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir2)
                {
                    this.container.cont.airUpgrade2.gotoAndStop(3);
                    this.container.cont.airUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.airArrow1.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costAirUpgrade2 && Main.mainClass.saveBoxClass.gameSave.data.upgradeAir1)
                {
                    this.container.cont.airUpgrade2.gotoAndStop(1);
                    this.container.cont.airUpgrade2.starsTXT.text = this.costAirUpgrade2;
                    this.container.cont.airUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade2.upgradeCase.buttonMode = true;
                    this.container.cont.airArrow1.visible = false;
                }
                else
                {
                    this.container.cont.airUpgrade2.gotoAndStop(4);
                    this.container.cont.airUpgrade2.starsTXT.text = this.costAirUpgrade2;
                    this.container.cont.airUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.airArrow1.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir3)
                {
                    this.container.cont.airUpgrade3.gotoAndStop(3);
                    this.container.cont.airUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.airArrow2.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costAirUpgrade3 && Main.mainClass.saveBoxClass.gameSave.data.upgradeAir2)
                {
                    this.container.cont.airUpgrade3.gotoAndStop(1);
                    this.container.cont.airUpgrade3.starsTXT.text = this.costAirUpgrade3;
                    this.container.cont.airUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade3.upgradeCase.buttonMode = true;
                    this.container.cont.airArrow2.visible = false;
                }
                else
                {
                    this.container.cont.airUpgrade3.gotoAndStop(4);
                    this.container.cont.airUpgrade3.starsTXT.text = this.costAirUpgrade3;
                    this.container.cont.airUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.airArrow2.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir4)
                {
                    this.container.cont.airUpgrade4.gotoAndStop(3);
                    this.container.cont.airUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.airArrow3.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costAirUpgrade4 && Main.mainClass.saveBoxClass.gameSave.data.upgradeAir3)
                {
                    this.container.cont.airUpgrade4.gotoAndStop(1);
                    this.container.cont.airUpgrade4.starsTXT.text = this.costAirUpgrade4;
                    this.container.cont.airUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade4.upgradeCase.buttonMode = true;
                    this.container.cont.airArrow3.visible = false;
                }
                else
                {
                    this.container.cont.airUpgrade4.gotoAndStop(4);
                    this.container.cont.airUpgrade4.starsTXT.text = this.costAirUpgrade4;
                    this.container.cont.airUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.airArrow3.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeAir5)
                {
                    this.container.cont.airUpgrade5.gotoAndStop(3);
                    this.container.cont.airUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.airArrow4.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costAirUpgrade5 && Main.mainClass.saveBoxClass.gameSave.data.upgradeAir4)
                {
                    this.container.cont.airUpgrade5.gotoAndStop(1);
                    this.container.cont.airUpgrade5.starsTXT.text = this.costAirUpgrade5;
                    this.container.cont.airUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade5.upgradeCase.buttonMode = true;
                    this.container.cont.airArrow4.visible = false;
                }
                else
                {
                    this.container.cont.airUpgrade5.gotoAndStop(4);
                    this.container.cont.airUpgrade5.starsTXT.text = this.costAirUpgrade5;
                    this.container.cont.airUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.airUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.airArrow4.visible = false;
                }
            }
            else
            {
                this.container.cont.airUpgrade1.gotoAndStop(5);
                this.container.cont.airUpgrade1.starsTXT.text = this.costAirUpgrade1;
                this.container.cont.airUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.airUpgrade1.upgradeCase.buttonMode = false;
                this.container.cont.airUpgrade2.gotoAndStop(5);
                this.container.cont.airUpgrade2.starsTXT.text = this.costAirUpgrade2;
                this.container.cont.airUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.airUpgrade2.upgradeCase.buttonMode = false;
                this.container.cont.airArrow1.visible = false;
                this.container.cont.airUpgrade3.gotoAndStop(5);
                this.container.cont.airUpgrade3.starsTXT.text = this.costAirUpgrade3;
                this.container.cont.airUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.airUpgrade3.upgradeCase.buttonMode = false;
                this.container.cont.airArrow2.visible = false;
                this.container.cont.airUpgrade4.gotoAndStop(5);
                this.container.cont.airUpgrade4.starsTXT.text = this.costAirUpgrade4;
                this.container.cont.airUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.airUpgrade4.upgradeCase.buttonMode = false;
                this.container.cont.airArrow3.visible = false;
                this.container.cont.airUpgrade5.gotoAndStop(5);
                this.container.cont.airUpgrade5.starsTXT.text = this.costAirUpgrade5;
                this.container.cont.airUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.airUpgrade5.upgradeCase.buttonMode = false;
                this.container.cont.airArrow4.visible = false;
            }
            if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[1] > 0 || Main.mainClass.saveBoxClass.gameSave.data.saveNo > 3)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire1)
                {
                    this.container.cont.fireUpgrade1.gotoAndStop(3);
                    this.container.cont.fireUpgrade1.upgradeCase.buttonMode = false;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costFireUpgrade1)
                {
                    this.container.cont.fireUpgrade1.gotoAndStop(1);
                    this.container.cont.fireUpgrade1.starsTXT.text = this.costFireUpgrade1;
                    this.container.cont.fireUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade1.upgradeCase.buttonMode = true;
                }
                else
                {
                    this.container.cont.fireUpgrade1.gotoAndStop(4);
                    this.container.cont.fireUpgrade1.starsTXT.text = this.costFireUpgrade1;
                    this.container.cont.fireUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade1.upgradeCase.buttonMode = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire2)
                {
                    this.container.cont.fireUpgrade2.gotoAndStop(3);
                    this.container.cont.fireUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.fireArrow1.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costFireUpgrade2 && Main.mainClass.saveBoxClass.gameSave.data.upgradeFire1)
                {
                    this.container.cont.fireUpgrade2.gotoAndStop(1);
                    this.container.cont.fireUpgrade2.starsTXT.text = this.costFireUpgrade2;
                    this.container.cont.fireUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade2.upgradeCase.buttonMode = true;
                    this.container.cont.fireArrow1.visible = false;
                }
                else
                {
                    this.container.cont.fireUpgrade2.gotoAndStop(4);
                    this.container.cont.fireUpgrade2.starsTXT.text = this.costFireUpgrade2;
                    this.container.cont.fireUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.fireArrow1.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire3)
                {
                    this.container.cont.fireUpgrade3.gotoAndStop(3);
                    this.container.cont.fireUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.fireArrow2.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costFireUpgrade3 && Main.mainClass.saveBoxClass.gameSave.data.upgradeFire2)
                {
                    this.container.cont.fireUpgrade3.gotoAndStop(1);
                    this.container.cont.fireUpgrade3.starsTXT.text = this.costFireUpgrade3;
                    this.container.cont.fireUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade3.upgradeCase.buttonMode = true;
                    this.container.cont.fireArrow2.visible = false;
                }
                else
                {
                    this.container.cont.fireUpgrade3.gotoAndStop(4);
                    this.container.cont.fireUpgrade3.starsTXT.text = this.costFireUpgrade3;
                    this.container.cont.fireUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.fireArrow2.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire4)
                {
                    this.container.cont.fireUpgrade4.gotoAndStop(3);
                    this.container.cont.fireUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.fireArrow3.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costFireUpgrade4 && Main.mainClass.saveBoxClass.gameSave.data.upgradeFire3)
                {
                    this.container.cont.fireUpgrade4.gotoAndStop(1);
                    this.container.cont.fireUpgrade4.starsTXT.text = this.costFireUpgrade4;
                    this.container.cont.fireUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade4.upgradeCase.buttonMode = true;
                    this.container.cont.fireArrow3.visible = false;
                }
                else
                {
                    this.container.cont.fireUpgrade4.gotoAndStop(4);
                    this.container.cont.fireUpgrade4.starsTXT.text = this.costFireUpgrade4;
                    this.container.cont.fireUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.fireArrow3.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire5)
                {
                    this.container.cont.fireUpgrade5.gotoAndStop(3);
                    this.container.cont.fireUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.fireArrow4.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costFireUpgrade5 && Main.mainClass.saveBoxClass.gameSave.data.upgradeFire4)
                {
                    this.container.cont.fireUpgrade5.gotoAndStop(1);
                    this.container.cont.fireUpgrade5.starsTXT.text = this.costFireUpgrade5;
                    this.container.cont.fireUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade5.upgradeCase.buttonMode = true;
                    this.container.cont.fireArrow4.visible = false;
                }
                else
                {
                    this.container.cont.fireUpgrade5.gotoAndStop(4);
                    this.container.cont.fireUpgrade5.starsTXT.text = this.costFireUpgrade5;
                    this.container.cont.fireUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.fireUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.fireArrow4.visible = false;
                }
            }
            else
            {
                this.container.cont.fireUpgrade1.gotoAndStop(5);
                this.container.cont.fireUpgrade1.starsTXT.text = this.costFireUpgrade1;
                this.container.cont.fireUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.fireUpgrade1.upgradeCase.buttonMode = false;
                this.container.cont.fireUpgrade2.gotoAndStop(5);
                this.container.cont.fireUpgrade2.starsTXT.text = this.costFireUpgrade2;
                this.container.cont.fireUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.fireUpgrade2.upgradeCase.buttonMode = false;
                this.container.cont.fireArrow1.visible = false;
                this.container.cont.fireUpgrade3.gotoAndStop(5);
                this.container.cont.fireUpgrade3.starsTXT.text = this.costFireUpgrade3;
                this.container.cont.fireUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.fireUpgrade3.upgradeCase.buttonMode = false;
                this.container.cont.fireArrow2.visible = false;
                this.container.cont.fireUpgrade4.gotoAndStop(5);
                this.container.cont.fireUpgrade4.starsTXT.text = this.costFireUpgrade4;
                this.container.cont.fireUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.fireUpgrade4.upgradeCase.buttonMode = false;
                this.container.cont.fireArrow3.visible = false;
                this.container.cont.fireUpgrade5.gotoAndStop(5);
                this.container.cont.fireUpgrade5.starsTXT.text = this.costFireUpgrade5;
                this.container.cont.fireUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.fireUpgrade5.upgradeCase.buttonMode = false;
                this.container.cont.fireArrow4.visible = false;
            }
            if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[1] > 0 || Main.mainClass.saveBoxClass.gameSave.data.saveNo > 3)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce1)
                {
                    this.container.cont.iceUpgrade1.gotoAndStop(3);
                    this.container.cont.iceUpgrade1.upgradeCase.buttonMode = false;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIceUpgrade1)
                {
                    this.container.cont.iceUpgrade1.gotoAndStop(1);
                    this.container.cont.iceUpgrade1.starsTXT.text = this.costIceUpgrade1;
                    this.container.cont.iceUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade1.upgradeCase.buttonMode = true;
                }
                else
                {
                    this.container.cont.iceUpgrade1.gotoAndStop(4);
                    this.container.cont.iceUpgrade1.starsTXT.text = this.costIceUpgrade1;
                    this.container.cont.iceUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade1.upgradeCase.buttonMode = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce2)
                {
                    this.container.cont.iceUpgrade2.gotoAndStop(3);
                    this.container.cont.iceUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.iceArrow1.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIceUpgrade2 && Main.mainClass.saveBoxClass.gameSave.data.upgradeIce1)
                {
                    this.container.cont.iceUpgrade2.gotoAndStop(1);
                    this.container.cont.iceUpgrade2.starsTXT.text = this.costIceUpgrade2;
                    this.container.cont.iceUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade2.upgradeCase.buttonMode = true;
                    this.container.cont.iceArrow1.visible = false;
                }
                else
                {
                    this.container.cont.iceUpgrade2.gotoAndStop(4);
                    this.container.cont.iceUpgrade2.starsTXT.text = this.costIceUpgrade2;
                    this.container.cont.iceUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.iceArrow1.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce3)
                {
                    this.container.cont.iceUpgrade3.gotoAndStop(3);
                    this.container.cont.iceUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.iceArrow2.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIceUpgrade3 && Main.mainClass.saveBoxClass.gameSave.data.upgradeIce2)
                {
                    this.container.cont.iceUpgrade3.gotoAndStop(1);
                    this.container.cont.iceUpgrade3.starsTXT.text = this.costIceUpgrade3;
                    this.container.cont.iceUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade3.upgradeCase.buttonMode = true;
                    this.container.cont.iceArrow2.visible = false;
                }
                else
                {
                    this.container.cont.iceUpgrade3.gotoAndStop(4);
                    this.container.cont.iceUpgrade3.starsTXT.text = this.costIceUpgrade3;
                    this.container.cont.iceUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.iceArrow2.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce4)
                {
                    this.container.cont.iceUpgrade4.gotoAndStop(3);
                    this.container.cont.iceUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.iceArrow3.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIceUpgrade4 && Main.mainClass.saveBoxClass.gameSave.data.upgradeIce3)
                {
                    this.container.cont.iceUpgrade4.gotoAndStop(1);
                    this.container.cont.iceUpgrade4.starsTXT.text = this.costIceUpgrade4;
                    this.container.cont.iceUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade4.upgradeCase.buttonMode = true;
                    this.container.cont.iceArrow3.visible = false;
                }
                else
                {
                    this.container.cont.iceUpgrade4.gotoAndStop(4);
                    this.container.cont.iceUpgrade4.starsTXT.text = this.costIceUpgrade4;
                    this.container.cont.iceUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.iceArrow3.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeIce5)
                {
                    this.container.cont.iceUpgrade5.gotoAndStop(3);
                    this.container.cont.iceUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.iceArrow4.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costIceUpgrade5 && Main.mainClass.saveBoxClass.gameSave.data.upgradeIce4)
                {
                    this.container.cont.iceUpgrade5.gotoAndStop(1);
                    this.container.cont.iceUpgrade5.starsTXT.text = this.costIceUpgrade5;
                    this.container.cont.iceUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade5.upgradeCase.buttonMode = true;
                    this.container.cont.iceArrow4.visible = false;
                }
                else
                {
                    this.container.cont.iceUpgrade5.gotoAndStop(4);
                    this.container.cont.iceUpgrade5.starsTXT.text = this.costIceUpgrade5;
                    this.container.cont.iceUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.iceUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.iceArrow4.visible = false;
                }
            }
            else
            {
                this.container.cont.iceUpgrade1.gotoAndStop(5);
                this.container.cont.iceUpgrade1.starsTXT.text = this.costIceUpgrade1;
                this.container.cont.iceUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.iceUpgrade1.upgradeCase.buttonMode = false;
                this.container.cont.iceUpgrade2.gotoAndStop(5);
                this.container.cont.iceUpgrade2.starsTXT.text = this.costIceUpgrade2;
                this.container.cont.iceUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.iceUpgrade2.upgradeCase.buttonMode = false;
                this.container.cont.iceArrow1.visible = false;
                this.container.cont.iceUpgrade3.gotoAndStop(5);
                this.container.cont.iceUpgrade3.starsTXT.text = this.costIceUpgrade3;
                this.container.cont.iceUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.iceUpgrade3.upgradeCase.buttonMode = false;
                this.container.cont.iceArrow2.visible = false;
                this.container.cont.iceUpgrade4.gotoAndStop(5);
                this.container.cont.iceUpgrade4.starsTXT.text = this.costIceUpgrade4;
                this.container.cont.iceUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.iceUpgrade4.upgradeCase.buttonMode = false;
                this.container.cont.iceArrow3.visible = false;
                this.container.cont.iceUpgrade5.gotoAndStop(5);
                this.container.cont.iceUpgrade5.starsTXT.text = this.costIceUpgrade5;
                this.container.cont.iceUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.iceUpgrade5.upgradeCase.buttonMode = false;
                this.container.cont.iceArrow4.visible = false;
            }
            if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[2] > 0)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone1)
                {
                    this.container.cont.stoneUpgrade1.gotoAndStop(3);
                    this.container.cont.stoneUpgrade1.upgradeCase.buttonMode = false;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costStoneUpgrade1)
                {
                    this.container.cont.stoneUpgrade1.gotoAndStop(1);
                    this.container.cont.stoneUpgrade1.starsTXT.text = this.costStoneUpgrade1;
                    this.container.cont.stoneUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade1.upgradeCase.buttonMode = true;
                }
                else
                {
                    this.container.cont.stoneUpgrade1.gotoAndStop(4);
                    this.container.cont.stoneUpgrade1.starsTXT.text = this.costStoneUpgrade1;
                    this.container.cont.stoneUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade1.upgradeCase.buttonMode = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone2)
                {
                    this.container.cont.stoneUpgrade2.gotoAndStop(3);
                    this.container.cont.stoneUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.stoneArrow1.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costStoneUpgrade2 && Main.mainClass.saveBoxClass.gameSave.data.upgradeStone1)
                {
                    this.container.cont.stoneUpgrade2.gotoAndStop(1);
                    this.container.cont.stoneUpgrade2.starsTXT.text = this.costStoneUpgrade2;
                    this.container.cont.stoneUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade2.upgradeCase.buttonMode = true;
                    this.container.cont.stoneArrow1.visible = false;
                }
                else
                {
                    this.container.cont.stoneUpgrade2.gotoAndStop(4);
                    this.container.cont.stoneUpgrade2.starsTXT.text = this.costStoneUpgrade2;
                    this.container.cont.stoneUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.stoneArrow1.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone3)
                {
                    this.container.cont.stoneUpgrade3.gotoAndStop(3);
                    this.container.cont.stoneUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.stoneArrow2.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costStoneUpgrade3 && Main.mainClass.saveBoxClass.gameSave.data.upgradeStone2)
                {
                    this.container.cont.stoneUpgrade3.gotoAndStop(1);
                    this.container.cont.stoneUpgrade3.starsTXT.text = this.costStoneUpgrade3;
                    this.container.cont.stoneUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade3.upgradeCase.buttonMode = true;
                    this.container.cont.stoneArrow2.visible = false;
                }
                else
                {
                    this.container.cont.stoneUpgrade3.gotoAndStop(4);
                    this.container.cont.stoneUpgrade3.starsTXT.text = this.costStoneUpgrade3;
                    this.container.cont.stoneUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.stoneArrow2.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone4)
                {
                    this.container.cont.stoneUpgrade4.gotoAndStop(3);
                    this.container.cont.stoneUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.stoneArrow3.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costStoneUpgrade4 && Main.mainClass.saveBoxClass.gameSave.data.upgradeStone3)
                {
                    this.container.cont.stoneUpgrade4.gotoAndStop(1);
                    this.container.cont.stoneUpgrade4.starsTXT.text = this.costStoneUpgrade4;
                    this.container.cont.stoneUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade4.upgradeCase.buttonMode = true;
                    this.container.cont.stoneArrow3.visible = false;
                }
                else
                {
                    this.container.cont.stoneUpgrade4.gotoAndStop(4);
                    this.container.cont.stoneUpgrade4.starsTXT.text = this.costStoneUpgrade4;
                    this.container.cont.stoneUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.stoneArrow3.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeStone5)
                {
                    this.container.cont.stoneUpgrade5.gotoAndStop(3);
                    this.container.cont.stoneUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.stoneArrow4.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costStoneUpgrade5 && Main.mainClass.saveBoxClass.gameSave.data.upgradeStone4)
                {
                    this.container.cont.stoneUpgrade5.gotoAndStop(1);
                    this.container.cont.stoneUpgrade5.starsTXT.text = this.costStoneUpgrade5;
                    this.container.cont.stoneUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade5.upgradeCase.buttonMode = true;
                    this.container.cont.stoneArrow4.visible = false;
                }
                else
                {
                    this.container.cont.stoneUpgrade5.gotoAndStop(4);
                    this.container.cont.stoneUpgrade5.starsTXT.text = this.costStoneUpgrade5;
                    this.container.cont.stoneUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.stoneUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.stoneArrow4.visible = false;
                }
            }
            else
            {
                this.container.cont.stoneUpgrade1.gotoAndStop(5);
                this.container.cont.stoneUpgrade1.starsTXT.text = this.costStoneUpgrade1;
                this.container.cont.stoneUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.stoneUpgrade1.upgradeCase.buttonMode = false;
                this.container.cont.stoneUpgrade2.gotoAndStop(5);
                this.container.cont.stoneUpgrade2.starsTXT.text = this.costStoneUpgrade2;
                this.container.cont.stoneUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.stoneUpgrade2.upgradeCase.buttonMode = false;
                this.container.cont.stoneArrow1.visible = false;
                this.container.cont.stoneUpgrade3.gotoAndStop(5);
                this.container.cont.stoneUpgrade3.starsTXT.text = this.costStoneUpgrade3;
                this.container.cont.stoneUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.stoneUpgrade3.upgradeCase.buttonMode = false;
                this.container.cont.stoneArrow2.visible = false;
                this.container.cont.stoneUpgrade4.gotoAndStop(5);
                this.container.cont.stoneUpgrade4.starsTXT.text = this.costStoneUpgrade4;
                this.container.cont.stoneUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.stoneUpgrade4.upgradeCase.buttonMode = false;
                this.container.cont.stoneArrow3.visible = false;
                this.container.cont.stoneUpgrade5.gotoAndStop(5);
                this.container.cont.stoneUpgrade5.starsTXT.text = this.costStoneUpgrade5;
                this.container.cont.stoneUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.stoneUpgrade5.upgradeCase.buttonMode = false;
                this.container.cont.stoneArrow4.visible = false;
            }
            if (Main.mainClass.saveBoxClass.gameSave.data.openLevels[3] > 0)
            {
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin1)
                {
                    this.container.cont.levinUpgrade1.gotoAndStop(3);
                    this.container.cont.levinUpgrade1.upgradeCase.buttonMode = false;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costLevinUpgrade1)
                {
                    this.container.cont.levinUpgrade1.gotoAndStop(1);
                    this.container.cont.levinUpgrade1.starsTXT.text = this.costLevinUpgrade1;
                    this.container.cont.levinUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade1.upgradeCase.buttonMode = true;
                }
                else
                {
                    this.container.cont.levinUpgrade1.gotoAndStop(4);
                    this.container.cont.levinUpgrade1.starsTXT.text = this.costLevinUpgrade1;
                    this.container.cont.levinUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade1.upgradeCase.buttonMode = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin2)
                {
                    this.container.cont.levinUpgrade2.gotoAndStop(3);
                    this.container.cont.levinUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.levinArrow1.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costLevinUpgrade2 && Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin1)
                {
                    this.container.cont.levinUpgrade2.gotoAndStop(1);
                    this.container.cont.levinUpgrade2.starsTXT.text = this.costLevinUpgrade2;
                    this.container.cont.levinUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade2.upgradeCase.buttonMode = true;
                    this.container.cont.levinArrow1.visible = false;
                }
                else
                {
                    this.container.cont.levinUpgrade2.gotoAndStop(4);
                    this.container.cont.levinUpgrade2.starsTXT.text = this.costLevinUpgrade2;
                    this.container.cont.levinUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade2.upgradeCase.buttonMode = false;
                    this.container.cont.levinArrow1.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin3)
                {
                    this.container.cont.levinUpgrade3.gotoAndStop(3);
                    this.container.cont.levinUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.levinArrow2.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costLevinUpgrade3 && Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin2)
                {
                    this.container.cont.levinUpgrade3.gotoAndStop(1);
                    this.container.cont.levinUpgrade3.starsTXT.text = this.costLevinUpgrade3;
                    this.container.cont.levinUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade3.upgradeCase.buttonMode = true;
                    this.container.cont.levinArrow2.visible = false;
                }
                else
                {
                    this.container.cont.levinUpgrade3.gotoAndStop(4);
                    this.container.cont.levinUpgrade3.starsTXT.text = this.costLevinUpgrade3;
                    this.container.cont.levinUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade3.upgradeCase.buttonMode = false;
                    this.container.cont.levinArrow2.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin4)
                {
                    this.container.cont.levinUpgrade4.gotoAndStop(3);
                    this.container.cont.levinUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.levinArrow3.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costLevinUpgrade4 && Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin3)
                {
                    this.container.cont.levinUpgrade4.gotoAndStop(1);
                    this.container.cont.levinUpgrade4.starsTXT.text = this.costLevinUpgrade4;
                    this.container.cont.levinUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade4.upgradeCase.buttonMode = true;
                    this.container.cont.levinArrow3.visible = false;
                }
                else
                {
                    this.container.cont.levinUpgrade4.gotoAndStop(4);
                    this.container.cont.levinUpgrade4.starsTXT.text = this.costLevinUpgrade4;
                    this.container.cont.levinUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade4.upgradeCase.buttonMode = false;
                    this.container.cont.levinArrow3.visible = false;
                }
                if (Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin5)
                {
                    this.container.cont.levinUpgrade5.gotoAndStop(3);
                    this.container.cont.levinUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.levinArrow4.visible = true;
                }
                else if (Main.mainClass.saveBoxClass.gameSave.data.stars >= this.costLevinUpgrade5 && Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin4)
                {
                    this.container.cont.levinUpgrade5.gotoAndStop(1);
                    this.container.cont.levinUpgrade5.starsTXT.text = this.costLevinUpgrade5;
                    this.container.cont.levinUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade5.upgradeCase.buttonMode = true;
                    this.container.cont.levinArrow4.visible = false;
                }
                else
                {
                    this.container.cont.levinUpgrade5.gotoAndStop(4);
                    this.container.cont.levinUpgrade5.starsTXT.text = this.costLevinUpgrade5;
                    this.container.cont.levinUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                    this.container.cont.levinUpgrade5.upgradeCase.buttonMode = false;
                    this.container.cont.levinArrow4.visible = false;
                }
            }
            else
            {
                this.container.cont.levinUpgrade1.gotoAndStop(5);
                this.container.cont.levinUpgrade1.starsTXT.text = this.costLevinUpgrade1;
                this.container.cont.levinUpgrade1.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.levinUpgrade1.upgradeCase.buttonMode = false;
                this.container.cont.levinUpgrade2.gotoAndStop(5);
                this.container.cont.levinUpgrade2.starsTXT.text = this.costLevinUpgrade2;
                this.container.cont.levinUpgrade2.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.levinUpgrade2.upgradeCase.buttonMode = false;
                this.container.cont.levinArrow1.visible = false;
                this.container.cont.levinUpgrade3.gotoAndStop(5);
                this.container.cont.levinUpgrade3.starsTXT.text = this.costLevinUpgrade3;
                this.container.cont.levinUpgrade3.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.levinUpgrade3.upgradeCase.buttonMode = false;
                this.container.cont.levinArrow2.visible = false;
                this.container.cont.levinUpgrade4.gotoAndStop(5);
                this.container.cont.levinUpgrade4.starsTXT.text = this.costLevinUpgrade4;
                this.container.cont.levinUpgrade4.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.levinUpgrade4.upgradeCase.buttonMode = false;
                this.container.cont.levinArrow3.visible = false;
                this.container.cont.levinUpgrade5.gotoAndStop(5);
                this.container.cont.levinUpgrade5.starsTXT.text = this.costLevinUpgrade5;
                this.container.cont.levinUpgrade5.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
                this.container.cont.levinUpgrade5.upgradeCase.buttonMode = false;
                this.container.cont.levinArrow4.visible = false;
            }
            if (Main.mainClass.saveBoxClass.gameSave.data.upgradeFire1 || Main.mainClass.saveBoxClass.gameSave.data.upgradeIce1 || Main.mainClass.saveBoxClass.gameSave.data.upgradeStone1 || Main.mainClass.saveBoxClass.gameSave.data.upgradeLevin1 || Main.mainClass.saveBoxClass.gameSave.data.upgradeGolem1 || Main.mainClass.saveBoxClass.gameSave.data.upgradeIceman1 || Main.mainClass.saveBoxClass.gameSave.data.upgradeAir1)
            {
                if (this.container.cont.btnReset.currentFrame == 4)
                {
                    this.container.cont.btnReset.gotoAndStop(1);
                    this.container.cont.btnReset.resetCase.buttonMode = true;
                }
            }
            else if (this.container.cont.btnReset.currentFrame != 4)
            {
                this.container.cont.btnReset.gotoAndStop(4);
                this.container.cont.btnReset.resetCase.buttonMode = false;
            }
            this.container.cont.starsTXT.text = Main.mainClass.saveBoxClass.gameSave.data.stars;
            this.container.cont.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
            Main.mainClass.levelsMenuClass.container.freeStars.cont.starsTXT.text = Main.mainClass.saveBoxClass.gameSave.data.stars;
            Main.mainClass.levelsMenuClass.container.freeStars.cont.starsTXT.setTextFormat(Main.mainClass.boldTextFormat);
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

        public function close() : void
        {
            if (!this.closeFlag)
            {
                this.closeFlag = true;
                var _loc_1:* = false;
                this.container.cont.mouseChildren = false;
                this.container.cont.mouseEnabled = _loc_1;
                Main.mainClass.levelsMenuClass.container.upgrades.gotoAndStop(1);
                this.stage.frameRate = 60;
                if (Main.mainClass.saveBoxClass.gameSave.data.stars == 0)
                {
                    Main.mainClass.levelsMenuClass.container.freeStars.visible = false;
                }
                else
                {
                    Main.mainClass.levelsMenuClass.container.freeStars.gotoAndStop(1);
                    Main.mainClass.levelsMenuClass.container.freeStars.cont.gotoAndStop(1);
                    Main.mainClass.levelsMenuClass.container.freeStars.visible = true;
                }
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.levelsMenu.removeChild(this.levelsMenu.upgradesClass);
                this.levelsMenu.upgradesClass = null;
                this.levelsMenu.manageListeners("on");
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
            this.stage.frameRate = 30;
            Main.mainClass.saveBoxClass.updateSever();
            return;
        }// end function

    }
}
