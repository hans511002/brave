package engine.towers
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;
    import training.*;

    public class TowerMenu extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var tempObject2:Object;
        public var tempObject3:Object;
        public var tempObject4:Object;
        public var container:TowerMenu_mc;
        public var myTower:Tower;
        public var world:World;
        public var dead:Boolean;
        public var closeFlag:Boolean;
        public var openFlag:Boolean = true;
        public var towerRadius:MovieClip;
        public var towerRadius1:MovieClip;
        public var exampleUltraTower:MovieClip;
        public var openUltraSection:Boolean;
        public var hint:TowerMenuHint_mc;
        public var hint1:TowerMenuHint_mc;
        public var lastE:MouseEvent;
        public var fastBuyUltraFlag:String;
        public var openFastBuyUltraFlag:Boolean;
        public var closeFastBuyUltraFlag:Boolean;
        public var readyFastBuyUltraFlag:Boolean;
        public var fastBuyPrice:int = 0;
        public var fastBuyBlockCost:Boolean;
        public var training_12:Training_12;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;
        public var container1:TowerMenu_mc;
        public var starsAnima:AnimUpgrade_mc;

        public function TowerMenu(param1:Tower)
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.myTower = param1;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.world = Main.mainClass.worldClass;
            if (this.world.towerRadius.visible)
            {
                this.world.towerRadius.visible = false;
            }
            if (this.myTower.towerType < 5)
            {
                this.myTower.container.selectTower.visible = false;
            }
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            this.x = this.myTower.this_pt.x;
            this.y = this.myTower.this_pt.y;
            this.towerRadius = new TowerRadius_mc();
            this.towerRadius.stop();
            this.towerRadius.width = this.myTower.radius * 2;
            this.towerRadius.height = this.myTower.radius * 2 * this.world.scaleRadius;
            this.towerRadius.x = this.x;
            this.towerRadius.y = this.y;
            var _loc_2:* = false;
            this.towerRadius.mouseChildren = false;
            this.towerRadius.mouseEnabled = _loc_2;
            this.world.addChild(this.towerRadius);
            this.towerRadius1 = new TowerRadius_mc();
            this.towerRadius1.stop();
            this.towerRadius1.width = this.myTower.radius * 2;
            this.towerRadius1.height = this.myTower.radius * 2 * this.world.scaleRadius;
            this.towerRadius1.x = this.x;
            this.towerRadius1.y = this.y;
            var _loc_2:* = false;
            this.towerRadius1.mouseChildren = false;
            this.towerRadius1.mouseEnabled = _loc_2;
            this.towerRadius1.visible = false;
            this.world.addChild(this.towerRadius1);
            this.container = new TowerMenu_mc();
            this.container.stop();
            this.container.btnUpgradeMenu.stop();
            this.container.btnGetAll.stop();
            this.container.sphereSlot1.stop();
            this.container.sphereSlot2.stop();
            this.container.sphereSlot3.stop();
            this.container.sphereSlot4.stop();
            this.container.sphereSlot1.sphereAnima.stop();
            this.container.sphereSlot2.sphereAnima.stop();
            this.container.sphereSlot3.sphereAnima.stop();
            this.container.sphereSlot4.sphereAnima.stop();
            this.container.sphereSlot1.sphereAnima.fire.stop();
            this.container.sphereSlot2.sphereAnima.fire.stop();
            this.container.sphereSlot3.sphereAnima.fire.stop();
            this.container.sphereSlot4.sphereAnima.fire.stop();
            this.container.cont1.stop();
            this.container.cont2.stop();
            this.addChild(this.container);
            this.world.listOfClasses.push(this);
            if (this.myTower.spheresStack.length > 0)
            {
                this.container.btnGetAll.btnGetAllCase.buttonMode = true;
            }
            if (this.myTower.towerType == 4)
            {
                this.container.gotoAndStop(this.container.totalFrames);
            }
            var _loc_2:* = false;
            this.myTower.mouseChildren = false;
            this.myTower.mouseEnabled = _loc_2;
            this.world.worldInterface.barInfoManage(this);
            if (!this.hint)
            {
                this.hint = new TowerMenuHint_mc();
                this.hint.stop();
                this.hint.cont.stop();
                this.hint.cont.cont1.stop();
                this.hint.cont.cont1.sphere1.stop();
                this.hint.cont.cont1.sphere2.stop();
                var _loc_2:* = false;
                this.hint.mouseChildren = false;
                this.hint.mouseEnabled = _loc_2;
                this.hint.visible = false;
                this.world.addChild(this.hint);
            }
            if (this.world.eduOpenUpgrArrowFlag)
            {
                if (this.world.nowLevel == 2 && this.world.saveBox.gameSave.data.complexityLevel < 4)
                {
                    this.container.visible = false;
                    this.container1 = new TowerMenu_mc();
                    this.container1.stop();
                    this.container1.btnUpgradeMenu.gotoAndStop(5);
                    this.container1.btnGetAll.stop();
                    this.container1.sphereSlot1.gotoAndStop(1);
                    this.container1.sphereSlot2.gotoAndStop(4);
                    this.container1.sphereSlot3.gotoAndStop(4);
                    this.container1.sphereSlot4.gotoAndStop(4);
                    this.container1.sphereSlot1.sphereAnima.stop();
                    this.container1.sphereSlot2.sphereAnima.stop();
                    this.container1.sphereSlot3.sphereAnima.stop();
                    this.container1.sphereSlot4.sphereAnima.stop();
                    this.container1.sphereSlot1.sphereAnima.fire.stop();
                    this.container1.sphereSlot2.sphereAnima.fire.stop();
                    this.container1.sphereSlot3.sphereAnima.fire.stop();
                    this.container1.sphereSlot4.sphereAnima.fire.stop();
                    this.container1.cont1.stop();
                    this.container1.cont2.stop();
                    this.container1.sphereSlot1.sphereAnima.visible = false;
                    this.container1.sphereSlot2.sphereAnima.visible = false;
                    this.container1.sphereSlot3.sphereAnima.visible = false;
                    this.container1.sphereSlot4.sphereAnima.visible = false;
                    var _loc_2:* = false;
                    this.container1.mouseChildren = false;
                    this.container1.mouseEnabled = _loc_2;
                    this.addChild(this.container1);
                    this.starsAnima = new AnimUpgrade_mc();
                    this.starsAnima.stop();
                    this.starsAnima.x = this.container.btnUpgradeMenu.x;
                    this.starsAnima.y = this.container.btnUpgradeMenu.y;
                    var _loc_2:* = false;
                    this.starsAnima.mouseChildren = false;
                    this.starsAnima.mouseEnabled = _loc_2;
                    this.addChild(this.starsAnima);
                    Sounds.instance.playSound("snd_menu_upgrIconMouseDown");
                }
                else
                {
                    this.world.eduOpenUpgrArrowFlag = false;
                }
            }
            this.upgradeManage();
            this.spheresMonitor();
            this.world.worldInterface.updateInfo();
            return;
        }// end function

        public function update() : void
        {
            if (!this.closeFlag)
            {
                if (this.openFlag)
                {
                    if (this.container.scaleX < 1)
                    {
                        this.container.scaleX = this.container.scaleX + 0.2;
                        this.container.scaleY = this.container.scaleY + 0.2;
                    }
                    else
                    {
                        this.openFlag = false;
                        var _loc_1:* = 1;
                        this.container.scaleY = 1;
                        this.container.scaleX = _loc_1;
                        var _loc_1:* = true;
                        this.mouseChildren = true;
                        this.mouseEnabled = _loc_1;
                        this.autoguidersButtons();
                        if (!this.training_12 && this.world.nowLevel > 1 && this.world.nowLevel < 5)
                        {
                            if (!Main.mainClass.saveBoxClass.gameSave.data.firstClickKeepAll)
                            {
                                if (this.myTower.spheresStack.length > 0)
                                {
                                    this.training_12 = new Training_12();
                                    this.addChild(this.training_12);
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (this.world.eduOpenUpgrArrowFlag)
                    {
                        if (this.container1.btnGetAll.currentFrame < this.container1.btnGetAll.totalFrames)
                        {
                            this.container1.btnGetAll.gotoAndStop((this.container1.btnGetAll.currentFrame + 1));
                        }
                        else
                        {
                            this.container1.btnGetAll.gotoAndStop(1);
                        }
                        if (this.container1.cont1.currentFrame < this.container1.cont1.totalFrames)
                        {
                            this.container1.cont1.gotoAndStop((this.container1.cont1.currentFrame + 1));
                        }
                        else
                        {
                            this.container1.cont1.gotoAndStop(1);
                        }
                        if (this.container1.cont2.currentFrame < this.container1.cont2.totalFrames)
                        {
                            this.container1.cont2.gotoAndStop((this.container1.cont2.currentFrame + 1));
                        }
                        else
                        {
                            this.container1.cont2.gotoAndStop(1);
                        }
                        if (this.starsAnima.currentFrame < this.starsAnima.totalFrames)
                        {
                            this.starsAnima.gotoAndStop((this.starsAnima.currentFrame + 1));
                            if (this.starsAnima.currentFrame == 12)
                            {
                                this.container1.btnUpgradeMenu.gotoAndStop(1);
                                this.container1.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costSlot2XML;
                                this.container1.sphereSlot2.gotoAndStop(3);
                            }
                        }
                        else
                        {
                            this.container.visible = true;
                            this.removeChild(this.starsAnima);
                            this.starsAnima = null;
                            this.removeChild(this.container1);
                            this.container1 = null;
                            this.world.eduOpenUpgrArrowFlag = false;
                        }
                    }
                    if (this.container.btnGetAll.currentFrame < this.container.btnGetAll.totalFrames)
                    {
                        this.container.btnGetAll.gotoAndStop((this.container.btnGetAll.currentFrame + 1));
                    }
                    else
                    {
                        this.container.btnGetAll.gotoAndStop(1);
                    }
                    if (this.container.cont1.currentFrame < this.container.cont1.totalFrames)
                    {
                        this.container.cont1.gotoAndStop((this.container.cont1.currentFrame + 1));
                    }
                    else
                    {
                        this.container.cont1.gotoAndStop(1);
                    }
                    if (this.container.cont2.currentFrame < this.container.cont2.totalFrames)
                    {
                        this.container.cont2.gotoAndStop((this.container.cont2.currentFrame + 1));
                    }
                    else
                    {
                        this.container.cont2.gotoAndStop(1);
                    }
                    if (this.openUltraSection)
                    {
                        if (this.container.currentFrame < this.container.totalFrames)
                        {
                            this.container.gotoAndStop((this.container.currentFrame + 1));
                            if (this.container.currentFrame == 4 || this.container.currentFrame == 6 || this.container.currentFrame == 9 || this.container.currentFrame == 11)
                            {
                                this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costSlot4XML;
                            }
                            else if (this.container.currentFrame == 13 || this.container.currentFrame == 15 || this.container.currentFrame == 17 || this.container.currentFrame == 19 || this.container.currentFrame == 21 || this.container.currentFrame == 23 || this.container.currentFrame == 25)
                            {
                                this.upgradeManage();
                            }
                        }
                        else
                        {
                            this.openUltraSection = false;
                            var _loc_1:* = true;
                            this.mouseChildren = true;
                            this.mouseEnabled = _loc_1;
                            this.upgradeManage();
                            this.autoguidersButtons();
                        }
                    }
                    if (this.hint)
                    {
                        if (this.hint.visible)
                        {
                            if (this.hint.currentFrame < 5)
                            {
                                if (this.hint.cont.cont1.sphere1.currentFrame < this.hint.cont.cont1.sphere1.totalFrames)
                                {
                                    this.hint.cont.cont1.sphere1.gotoAndStop((this.hint.cont.cont1.sphere1.currentFrame + 1));
                                }
                                else
                                {
                                    this.hint.cont.cont1.sphere1.gotoAndStop(1);
                                }
                                if (this.hint.cont.cont1.sphere2.currentFrame < this.hint.cont.cont1.sphere2.totalFrames)
                                {
                                    this.hint.cont.cont1.sphere2.gotoAndStop((this.hint.cont.cont1.sphere2.currentFrame + 1));
                                }
                                else
                                {
                                    this.hint.cont.cont1.sphere2.gotoAndStop(1);
                                }
                            }
                        }
                    }
                    if (this.exampleUltraTower)
                    {
                        if (this.exampleUltraTower is Tower5_mc)
                        {
                            if (this.world.frameCounter % 2)
                            {
                                if (this.exampleUltraTower.currentFrame < this.exampleUltraTower.totalFrames)
                                {
                                    this.exampleUltraTower.gotoAndStop((this.exampleUltraTower.currentFrame + 1));
                                }
                                else
                                {
                                    this.exampleUltraTower.gotoAndStop(1);
                                }
                            }
                        }
                        else if (this.exampleUltraTower is Tower6_mc)
                        {
                            if (this.world.frameCounter % 2)
                            {
                                if (this.exampleUltraTower.currentFrame < this.exampleUltraTower.totalFrames)
                                {
                                    this.exampleUltraTower.gotoAndStop((this.exampleUltraTower.currentFrame + 1));
                                }
                                else
                                {
                                    this.exampleUltraTower.gotoAndStop(1);
                                }
                            }
                        }
                        else if (this.exampleUltraTower is Tower7_mc)
                        {
                            if (this.exampleUltraTower.cont1.currentFrame < this.exampleUltraTower.cont1.totalFrames)
                            {
                                this.exampleUltraTower.cont1.gotoAndStop((this.exampleUltraTower.cont1.currentFrame + 1));
                            }
                            else
                            {
                                this.exampleUltraTower.cont1.gotoAndStop(1);
                            }
                            if (this.exampleUltraTower.cont2.currentFrame < this.exampleUltraTower.cont2.totalFrames)
                            {
                                this.exampleUltraTower.cont2.gotoAndStop((this.exampleUltraTower.cont2.currentFrame + 1));
                            }
                            else
                            {
                                this.exampleUltraTower.cont2.gotoAndStop(1);
                            }
                            if (this.exampleUltraTower.cont3.currentFrame < this.exampleUltraTower.cont3.totalFrames)
                            {
                                this.exampleUltraTower.cont3.gotoAndStop((this.exampleUltraTower.cont3.currentFrame + 1));
                            }
                            else
                            {
                                this.exampleUltraTower.cont3.gotoAndStop(1);
                            }
                        }
                        else if (this.exampleUltraTower is Tower8_mc)
                        {
                            if (this.world.frameCounter % 2)
                            {
                                if (this.exampleUltraTower.cont1.currentFrame < this.exampleUltraTower.cont1.totalFrames)
                                {
                                    this.exampleUltraTower.cont1.gotoAndStop((this.exampleUltraTower.cont1.currentFrame + 1));
                                }
                                else
                                {
                                    this.exampleUltraTower.cont1.gotoAndStop(1);
                                }
                                if (this.exampleUltraTower.cont2.currentFrame < this.exampleUltraTower.cont2.totalFrames)
                                {
                                    this.exampleUltraTower.cont2.gotoAndStop((this.exampleUltraTower.cont2.currentFrame + 1));
                                }
                                else
                                {
                                    this.exampleUltraTower.cont2.gotoAndStop(1);
                                }
                                if (this.exampleUltraTower.cont3.currentFrame < this.exampleUltraTower.cont3.totalFrames)
                                {
                                    this.exampleUltraTower.cont3.gotoAndStop((this.exampleUltraTower.cont3.currentFrame + 1));
                                }
                                else
                                {
                                    this.exampleUltraTower.cont3.gotoAndStop(1);
                                }
                            }
                            this.exampleUltraTower.cont2.rotation = this.exampleUltraTower.cont2.rotation + 3;
                        }
                    }
                    if (this.container.sphereSlot1.sphereAnima.visible)
                    {
                        if (this.container.sphereSlot1.sphereAnima.currentFrame == 1)
                        {
                            if (this.container.sphereSlot1.sphereAnima.fire.currentFrame < this.container.sphereSlot1.sphereAnima.fire.totalFrames)
                            {
                                this.container.sphereSlot1.sphereAnima.fire.gotoAndStop((this.container.sphereSlot1.sphereAnima.fire.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot1.sphereAnima.fire.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot1.sphereAnima.currentFrame == 2)
                        {
                            if (this.container.sphereSlot1.sphereAnima.ice.currentFrame < this.container.sphereSlot1.sphereAnima.ice.totalFrames)
                            {
                                this.container.sphereSlot1.sphereAnima.ice.gotoAndStop((this.container.sphereSlot1.sphereAnima.ice.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot1.sphereAnima.ice.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot1.sphereAnima.currentFrame == 3)
                        {
                            if (this.container.sphereSlot1.sphereAnima.stone.currentFrame < this.container.sphereSlot1.sphereAnima.stone.totalFrames)
                            {
                                this.container.sphereSlot1.sphereAnima.stone.gotoAndStop((this.container.sphereSlot1.sphereAnima.stone.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot1.sphereAnima.stone.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot1.sphereAnima.currentFrame == 4)
                        {
                            if (this.container.sphereSlot1.sphereAnima.levin.currentFrame < this.container.sphereSlot1.sphereAnima.levin.totalFrames)
                            {
                                this.container.sphereSlot1.sphereAnima.levin.gotoAndStop((this.container.sphereSlot1.sphereAnima.levin.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot1.sphereAnima.levin.gotoAndStop(1);
                            }
                        }
                    }
                    if (this.container.sphereSlot2.sphereAnima.visible)
                    {
                        if (this.container.sphereSlot2.sphereAnima.currentFrame == 1)
                        {
                            if (this.container.sphereSlot2.sphereAnima.fire.currentFrame < this.container.sphereSlot2.sphereAnima.fire.totalFrames)
                            {
                                this.container.sphereSlot2.sphereAnima.fire.gotoAndStop((this.container.sphereSlot2.sphereAnima.fire.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot2.sphereAnima.fire.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot2.sphereAnima.currentFrame == 2)
                        {
                            if (this.container.sphereSlot2.sphereAnima.ice.currentFrame < this.container.sphereSlot2.sphereAnima.ice.totalFrames)
                            {
                                this.container.sphereSlot2.sphereAnima.ice.gotoAndStop((this.container.sphereSlot2.sphereAnima.ice.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot2.sphereAnima.ice.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot2.sphereAnima.currentFrame == 3)
                        {
                            if (this.container.sphereSlot2.sphereAnima.stone.currentFrame < this.container.sphereSlot2.sphereAnima.stone.totalFrames)
                            {
                                this.container.sphereSlot2.sphereAnima.stone.gotoAndStop((this.container.sphereSlot2.sphereAnima.stone.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot2.sphereAnima.stone.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot2.sphereAnima.currentFrame == 4)
                        {
                            if (this.container.sphereSlot2.sphereAnima.levin.currentFrame < this.container.sphereSlot2.sphereAnima.levin.totalFrames)
                            {
                                this.container.sphereSlot2.sphereAnima.levin.gotoAndStop((this.container.sphereSlot2.sphereAnima.levin.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot2.sphereAnima.levin.gotoAndStop(1);
                            }
                        }
                    }
                    if (this.container.sphereSlot3.sphereAnima.visible)
                    {
                        if (this.container.sphereSlot3.sphereAnima.currentFrame == 1)
                        {
                            if (this.container.sphereSlot3.sphereAnima.fire.currentFrame < this.container.sphereSlot3.sphereAnima.fire.totalFrames)
                            {
                                this.container.sphereSlot3.sphereAnima.fire.gotoAndStop((this.container.sphereSlot3.sphereAnima.fire.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot3.sphereAnima.fire.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot3.sphereAnima.currentFrame == 2)
                        {
                            if (this.container.sphereSlot3.sphereAnima.ice.currentFrame < this.container.sphereSlot3.sphereAnima.ice.totalFrames)
                            {
                                this.container.sphereSlot3.sphereAnima.ice.gotoAndStop((this.container.sphereSlot3.sphereAnima.ice.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot3.sphereAnima.ice.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot3.sphereAnima.currentFrame == 3)
                        {
                            if (this.container.sphereSlot3.sphereAnima.stone.currentFrame < this.container.sphereSlot3.sphereAnima.stone.totalFrames)
                            {
                                this.container.sphereSlot3.sphereAnima.stone.gotoAndStop((this.container.sphereSlot3.sphereAnima.stone.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot3.sphereAnima.stone.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot3.sphereAnima.currentFrame == 4)
                        {
                            if (this.container.sphereSlot3.sphereAnima.levin.currentFrame < this.container.sphereSlot3.sphereAnima.levin.totalFrames)
                            {
                                this.container.sphereSlot3.sphereAnima.levin.gotoAndStop((this.container.sphereSlot3.sphereAnima.levin.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot3.sphereAnima.levin.gotoAndStop(1);
                            }
                        }
                    }
                    if (this.container.sphereSlot4.sphereAnima.visible)
                    {
                        if (this.container.sphereSlot4.sphereAnima.currentFrame == 1)
                        {
                            if (this.container.sphereSlot4.sphereAnima.fire.currentFrame < this.container.sphereSlot4.sphereAnima.fire.totalFrames)
                            {
                                this.container.sphereSlot4.sphereAnima.fire.gotoAndStop((this.container.sphereSlot4.sphereAnima.fire.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot4.sphereAnima.fire.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot4.sphereAnima.currentFrame == 2)
                        {
                            if (this.container.sphereSlot4.sphereAnima.ice.currentFrame < this.container.sphereSlot4.sphereAnima.ice.totalFrames)
                            {
                                this.container.sphereSlot4.sphereAnima.ice.gotoAndStop((this.container.sphereSlot4.sphereAnima.ice.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot4.sphereAnima.ice.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot4.sphereAnima.currentFrame == 3)
                        {
                            if (this.container.sphereSlot4.sphereAnima.stone.currentFrame < this.container.sphereSlot4.sphereAnima.stone.totalFrames)
                            {
                                this.container.sphereSlot4.sphereAnima.stone.gotoAndStop((this.container.sphereSlot4.sphereAnima.stone.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot4.sphereAnima.stone.gotoAndStop(1);
                            }
                        }
                        else if (this.container.sphereSlot4.sphereAnima.currentFrame == 4)
                        {
                            if (this.container.sphereSlot4.sphereAnima.levin.currentFrame < this.container.sphereSlot4.sphereAnima.levin.totalFrames)
                            {
                                this.container.sphereSlot4.sphereAnima.levin.gotoAndStop((this.container.sphereSlot4.sphereAnima.levin.currentFrame + 1));
                            }
                            else
                            {
                                this.container.sphereSlot4.sphereAnima.levin.gotoAndStop(1);
                            }
                        }
                    }
                    if (this.closeFastBuyUltraFlag)
                    {
                        if (this.container.fastBuyUltraCont.currentFrame > 1)
                        {
                            this.container.fastBuyUltraCont.gotoAndStop((this.container.fastBuyUltraCont.currentFrame - 1));
                        }
                        else
                        {
                            this.closeFastBuyUltraFlag = false;
                            this.openFastBuyUltraFlag = false;
                            this.container.fastBuyUltraCont.visible = false;
                        }
                    }
                    else if (this.openFastBuyUltraFlag)
                    {
                        if (!this.container.fastBuyUltraCont.visible)
                        {
                            this.container.fastBuyUltraCont.visible = true;
                        }
                        else if (this.container.fastBuyUltraCont.currentFrame < this.container.fastBuyUltraCont.totalFrames)
                        {
                            this.container.fastBuyUltraCont.gotoAndStop((this.container.fastBuyUltraCont.currentFrame + 1));
                        }
                        else
                        {
                            this.openFastBuyUltraFlag = false;
                            this.closeFastBuyUltraFlag = false;
                            this.fastBuyUltraManage();
                        }
                    }
                    if (!this.readyFastBuyUltraFlag)
                    {
                        if (Point.distance(this.myTower.this_pt, new Point(this.world.mouseX, this.world.mouseY)) > 86)
                        {
                            if (this.mouseEnabled)
                            {
                                var _loc_1:* = false;
                                this.mouseChildren = false;
                                this.mouseEnabled = _loc_1;
                            }
                        }
                        else if (!this.mouseEnabled)
                        {
                            var _loc_1:* = true;
                            this.mouseChildren = true;
                            this.mouseEnabled = _loc_1;
                        }
                    }
                    else if (this.fastBuyUltraFlag == "btnTowerUpgr1")
                    {
                        if (this.myTower.shootingTurnStack[0] && this.myTower.shootingTurnStack[2])
                        {
                            this.readyFastBuyUltraFlag = false;
                            this.ultraUpgradeTower(this.fastBuyUltraFlag);
                        }
                    }
                    else if (this.fastBuyUltraFlag == "btnTowerUpgr2")
                    {
                        if (this.myTower.shootingTurnStack[1] && this.myTower.shootingTurnStack[3])
                        {
                            this.readyFastBuyUltraFlag = false;
                            this.ultraUpgradeTower(this.fastBuyUltraFlag);
                        }
                    }
                    else if (this.fastBuyUltraFlag == "btnTowerUpgr3")
                    {
                        if (this.myTower.shootingTurnStack[1] && this.myTower.shootingTurnStack[2])
                        {
                            this.readyFastBuyUltraFlag = false;
                            this.ultraUpgradeTower(this.fastBuyUltraFlag);
                        }
                    }
                    else if (this.fastBuyUltraFlag == "btnTowerUpgr4")
                    {
                        if (this.myTower.shootingTurnStack[0] && this.myTower.shootingTurnStack[3])
                        {
                            this.readyFastBuyUltraFlag = false;
                            this.ultraUpgradeTower(this.fastBuyUltraFlag);
                        }
                    }
                }
            }
            else
            {
                this.kill();
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (this.container.currentFrame == 1)
            {
                if (param1.target.name == "btnUpgradeMenuCase")
                {
                    if (this.container.btnUpgradeMenu.currentFrame == 1)
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(2);
                        this.towerRadius1.visible = true;
                        if (this.myTower.towerType == 1)
                        {
                            this.towerRadius1.width = Main.mainClass.readXMLClass.listOfSpheresRadius[1] * 2;
                            this.towerRadius1.height = Main.mainClass.readXMLClass.listOfSpheresRadius[1] * 2 * this.world.scaleRadius;
                        }
                        else if (this.myTower.towerType == 2)
                        {
                            this.towerRadius1.width = Main.mainClass.readXMLClass.listOfSpheresRadius[2] * 2;
                            this.towerRadius1.height = Main.mainClass.readXMLClass.listOfSpheresRadius[2] * 2 * this.world.scaleRadius;
                        }
                        else if (this.myTower.towerType == 3)
                        {
                            this.towerRadius1.width = Main.mainClass.readXMLClass.listOfSpheresRadius[3] * 2;
                            this.towerRadius1.height = Main.mainClass.readXMLClass.listOfSpheresRadius[3] * 2 * this.world.scaleRadius;
                        }
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                    if (this.myTower.towerType < 5)
                    {
                        if (!this.hint.visible && !this.openFlag && !this.closeFlag)
                        {
                            this.hint.visible = true;
                            this.hintPosition(5);
                        }
                    }
                    else if (this.hint.visible)
                    {
                        this.hint.visible = false;
                    }
                }
                else
                {
                    if (this.container.btnUpgradeMenu.currentFrame == 2)
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(1);
                        this.towerRadius1.visible = false;
                    }
                    if (this.myTower.towerType < 5)
                    {
                        if (param1.target.name == "btnUpgradeMenuBLOCKCase")
                        {
                            if (!this.hint.visible && !this.openFlag && !this.closeFlag)
                            {
                                this.hint.visible = true;
                                this.hintPosition(5);
                            }
                        }
                        else if (param1.target.name == "btnUpgradeMenuLOCKCase")
                        {
                            if (!this.hint.visible && !this.openFlag && !this.closeFlag)
                            {
                                this.hint.visible = true;
                                this.hintPosition(9);
                            }
                        }
                        else if (this.hint.visible)
                        {
                            this.hint.visible = false;
                        }
                    }
                    else if (this.hint.visible)
                    {
                        this.hint.visible = false;
                    }
                }
            }
            else if (this.container.currentFrame == this.container.totalFrames)
            {
                if (param1.target.name == "btnTowerUpgrCase")
                {
                    if (param1.target.parent != this.container.btnTowerUpgr1)
                    {
                        if (this.container.btnTowerUpgr1.currentFrame == 2)
                        {
                            if (this.fastBuyUltraFlag != "btnTowerUpgr1")
                            {
                                this.tempObject = this.container.btnTowerUpgr1.costTXT.text;
                                this.container.btnTowerUpgr1.gotoAndStop(1);
                                this.container.btnTowerUpgr1.costTXT.text = this.tempObject;
                            }
                        }
                    }
                    if (param1.target.parent != this.container.btnTowerUpgr2)
                    {
                        if (this.container.btnTowerUpgr2.currentFrame == 2)
                        {
                            if (this.fastBuyUltraFlag != "btnTowerUpgr2")
                            {
                                this.tempObject = this.container.btnTowerUpgr2.costTXT.text;
                                this.container.btnTowerUpgr2.gotoAndStop(1);
                                this.container.btnTowerUpgr2.costTXT.text = this.tempObject;
                            }
                        }
                    }
                    if (param1.target.parent != this.container.btnTowerUpgr3)
                    {
                        if (this.container.btnTowerUpgr3.currentFrame == 2)
                        {
                            if (this.fastBuyUltraFlag != "btnTowerUpgr3")
                            {
                                this.tempObject = this.container.btnTowerUpgr3.costTXT.text;
                                this.container.btnTowerUpgr3.gotoAndStop(1);
                                this.container.btnTowerUpgr3.costTXT.text = this.tempObject;
                            }
                        }
                    }
                    if (param1.target.parent != this.container.btnTowerUpgr4)
                    {
                        if (this.container.btnTowerUpgr4.currentFrame == 2)
                        {
                            if (this.fastBuyUltraFlag != "btnTowerUpgr4")
                            {
                                this.tempObject = this.container.btnTowerUpgr4.costTXT.text;
                                this.container.btnTowerUpgr4.gotoAndStop(1);
                                this.container.btnTowerUpgr4.costTXT.text = this.tempObject;
                            }
                        }
                    }
                    if (param1.target.parent.currentFrame == 1)
                    {
                        if (param1.target.buttonMode)
                        {
                            this.tempObject = param1.target.parent.costTXT.text;
                            param1.target.parent.gotoAndStop(2);
                            param1.target.parent.costTXT.text = this.tempObject;
                            Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                        }
                        else
                        {
                            if (this.container.btnTowerUpgr1.currentFrame == 2)
                            {
                                this.tempObject = this.container.btnTowerUpgr1.costTXT.text;
                                this.container.btnTowerUpgr1.gotoAndStop(1);
                                this.container.btnTowerUpgr1.costTXT.text = this.tempObject;
                            }
                            if (this.container.btnTowerUpgr2.currentFrame == 2)
                            {
                                this.tempObject = this.container.btnTowerUpgr2.costTXT.text;
                                this.container.btnTowerUpgr2.gotoAndStop(1);
                                this.container.btnTowerUpgr2.costTXT.text = this.tempObject;
                            }
                            if (this.container.btnTowerUpgr3.currentFrame == 2)
                            {
                                this.tempObject = this.container.btnTowerUpgr3.costTXT.text;
                                this.container.btnTowerUpgr3.gotoAndStop(1);
                                this.container.btnTowerUpgr3.costTXT.text = this.tempObject;
                            }
                            if (this.container.btnTowerUpgr4.currentFrame == 2)
                            {
                                this.tempObject = this.container.btnTowerUpgr4.costTXT.text;
                                this.container.btnTowerUpgr4.gotoAndStop(1);
                                this.container.btnTowerUpgr4.costTXT.text = this.tempObject;
                            }
                        }
                    }
                    if (param1.target.parent.currentFrame < 5)
                    {
                        this.towerRadius1.visible = true;
                        if (param1.target.parent.name == "btnTowerUpgr1")
                        {
                            this.towerRadius1.width = Main.mainClass.readXMLClass.ultraFireStoneRadiusXML * 2;
                            this.towerRadius1.height = Main.mainClass.readXMLClass.ultraFireStoneRadiusXML * 2 * this.world.scaleRadius;
                        }
                        else if (param1.target.parent.name == "btnTowerUpgr2")
                        {
                            this.towerRadius1.width = Main.mainClass.readXMLClass.ultraIceLevinRadiusXML * 2;
                            this.towerRadius1.height = Main.mainClass.readXMLClass.ultraIceLevinRadiusXML * 2 * this.world.scaleRadius;
                        }
                        else if (param1.target.parent.name == "btnTowerUpgr3")
                        {
                            this.towerRadius1.width = Main.mainClass.readXMLClass.ultraIceStoneRadiusXML * 2;
                            this.towerRadius1.height = Main.mainClass.readXMLClass.ultraIceStoneRadiusXML * 2 * this.world.scaleRadius;
                        }
                        else if (param1.target.parent.name == "btnTowerUpgr4")
                        {
                            this.towerRadius1.width = Main.mainClass.readXMLClass.ultraFireLevinRadiusXML * 2;
                            this.towerRadius1.height = Main.mainClass.readXMLClass.ultraFireLevinRadiusXML * 2 * this.world.scaleRadius;
                        }
                        if (this.hint.currentFrame > 4)
                        {
                            this.hintManage("ultraButtons", 1);
                        }
                        if (param1.target.parent.name == "btnTowerUpgr1")
                        {
                            if (this.world.worldInterface.container.iceBacklight.visible || this.world.worldInterface.container.levinBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("");
                            }
                            if (!this.world.worldInterface.container.fireBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("fire");
                            }
                            if (!this.world.worldInterface.container.stoneBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("stone");
                            }
                            this.hintManage("ultraButtons", 1);
                        }
                        else if (param1.target.parent.name == "btnTowerUpgr2")
                        {
                            if (this.world.worldInterface.container.fireBacklight.visible || this.world.worldInterface.container.stoneBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("");
                            }
                            if (!this.world.worldInterface.container.iceBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("ice");
                            }
                            if (!this.world.worldInterface.container.levinBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("levin");
                            }
                            this.hintManage("ultraButtons", 2);
                        }
                        else if (param1.target.parent.name == "btnTowerUpgr3")
                        {
                            if (this.world.worldInterface.container.fireBacklight.visible || this.world.worldInterface.container.levinBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("");
                            }
                            if (!this.world.worldInterface.container.iceBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("ice");
                            }
                            if (!this.world.worldInterface.container.stoneBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("stone");
                            }
                            this.hintManage("ultraButtons", 3);
                        }
                        else if (param1.target.parent.name == "btnTowerUpgr4")
                        {
                            if (this.world.worldInterface.container.iceBacklight.visible || this.world.worldInterface.container.stoneBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("");
                            }
                            if (!this.world.worldInterface.container.fireBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("fire");
                            }
                            if (!this.world.worldInterface.container.levinBacklight.visible)
                            {
                                this.world.worldInterface.archiveSphereBacklightManage("levin");
                            }
                            this.hintManage("ultraButtons", 4);
                        }
                    }
                    else
                    {
                        if (this.world.worldInterface.container.fireBacklight.visible || this.world.worldInterface.container.iceBacklight.visible || this.world.worldInterface.container.stoneBacklight.visible || this.world.worldInterface.container.levinBacklight.visible)
                        {
                            this.world.worldInterface.archiveSphereBacklightManage("");
                        }
                        if (this.hint.currentFrame != 9 || !this.hint.visible)
                        {
                            this.hintManage("ultraButtons", 9, param1.target.parent);
                            if (this.exampleUltraTower)
                            {
                                this.exampleUltraManage("remove");
                            }
                        }
                    }
                }
                else
                {
                    if (this.container.btnTowerUpgr1.currentFrame == 2)
                    {
                        if (this.fastBuyUltraFlag != "btnTowerUpgr1")
                        {
                            this.tempObject = this.container.btnTowerUpgr1.costTXT.text;
                            this.container.btnTowerUpgr1.gotoAndStop(1);
                            this.container.btnTowerUpgr1.costTXT.text = this.tempObject;
                        }
                    }
                    if (this.container.btnTowerUpgr2.currentFrame == 2)
                    {
                        if (this.fastBuyUltraFlag != "btnTowerUpgr2")
                        {
                            this.tempObject = this.container.btnTowerUpgr2.costTXT.text;
                            this.container.btnTowerUpgr2.gotoAndStop(1);
                            this.container.btnTowerUpgr2.costTXT.text = this.tempObject;
                        }
                    }
                    if (this.container.btnTowerUpgr3.currentFrame == 2)
                    {
                        if (this.fastBuyUltraFlag != "btnTowerUpgr3")
                        {
                            this.tempObject = this.container.btnTowerUpgr3.costTXT.text;
                            this.container.btnTowerUpgr3.gotoAndStop(1);
                            this.container.btnTowerUpgr3.costTXT.text = this.tempObject;
                        }
                    }
                    if (this.container.btnTowerUpgr4.currentFrame == 2)
                    {
                        if (this.fastBuyUltraFlag != "btnTowerUpgr4")
                        {
                            this.tempObject = this.container.btnTowerUpgr4.costTXT.text;
                            this.container.btnTowerUpgr4.gotoAndStop(1);
                            this.container.btnTowerUpgr4.costTXT.text = this.tempObject;
                        }
                    }
                    if (this.towerRadius1.visible)
                    {
                        this.towerRadius1.visible = false;
                    }
                    if (param1.target.name != "fastBuyUltraCase" || !this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.buttonMode)
                    {
                        if (this.world.worldInterface.container.fireBacklight.visible || this.world.worldInterface.container.iceBacklight.visible || this.world.worldInterface.container.stoneBacklight.visible || this.world.worldInterface.container.levinBacklight.visible)
                        {
                            this.world.worldInterface.archiveSphereBacklightManage("");
                        }
                        if (param1.target.name != "fastBuyUltraCase")
                        {
                            if (this.hint.visible)
                            {
                                this.hint.visible = false;
                            }
                            if (this.exampleUltraTower)
                            {
                                this.exampleUltraManage("remove");
                            }
                        }
                    }
                }
                if (!this.openFastBuyUltraFlag && !this.closeFastBuyUltraFlag)
                {
                    if (param1.target.name == "fastBuyUltraCase" && this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.buttonMode)
                    {
                        if (this.container.fastBuyUltraCont.btnFastBuyUltra.currentFrame == 1)
                        {
                            this.container.fastBuyUltraCont.btnFastBuyUltra.gotoAndStop(2);
                            this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyPrice;
                            if (this.hint.currentFrame > 4)
                            {
                                this.hintManage("ultraButtons", 1);
                            }
                            if (this.fastBuyUltraFlag == "btnTowerUpgr1")
                            {
                                if (this.world.worldInterface.container.iceBacklight.visible || this.world.worldInterface.container.levinBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("");
                                }
                                if (!this.world.worldInterface.container.fireBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("fire");
                                }
                                if (!this.world.worldInterface.container.stoneBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("stone");
                                }
                                if (this.hint.cont.currentFrame != 1 || !this.hint.visible)
                                {
                                    this.hintManage("ultraButtons", 1);
                                }
                            }
                            else if (this.fastBuyUltraFlag == "btnTowerUpgr2")
                            {
                                if (this.world.worldInterface.container.fireBacklight.visible || this.world.worldInterface.container.stoneBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("");
                                }
                                if (!this.world.worldInterface.container.iceBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("ice");
                                }
                                if (!this.world.worldInterface.container.levinBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("levin");
                                }
                                if (this.hint.cont.currentFrame != 2 || !this.hint.visible)
                                {
                                    this.hintManage("ultraButtons", 2);
                                }
                            }
                            else if (this.fastBuyUltraFlag == "btnTowerUpgr3")
                            {
                                if (this.world.worldInterface.container.fireBacklight.visible || this.world.worldInterface.container.levinBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("");
                                }
                                if (!this.world.worldInterface.container.iceBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("ice");
                                }
                                if (!this.world.worldInterface.container.stoneBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("stone");
                                }
                                if (this.hint.cont.currentFrame != 3 || !this.hint.visible)
                                {
                                    this.hintManage("ultraButtons", 3);
                                }
                            }
                            else if (this.fastBuyUltraFlag == "btnTowerUpgr4")
                            {
                                if (this.world.worldInterface.container.iceBacklight.visible || this.world.worldInterface.container.stoneBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("");
                                }
                                if (!this.world.worldInterface.container.fireBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("fire");
                                }
                                if (!this.world.worldInterface.container.levinBacklight.visible)
                                {
                                    this.world.worldInterface.archiveSphereBacklightManage("levin");
                                }
                                if (this.hint.cont.currentFrame != 4 || !this.hint.visible)
                                {
                                    this.hintManage("ultraButtons", 4);
                                }
                            }
                            this.hint.x = this.x + this.container.x + this.container.fastBuyUltraCont.x + this.container.fastBuyUltraCont.btnFastBuyUltra.x;
                            this.hint.y = this.y + this.container.y + this.container.fastBuyUltraCont.y + this.container.fastBuyUltraCont.btnFastBuyUltra.y - 15;
                            Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                        }
                    }
                    else if (this.container.fastBuyUltraCont.btnFastBuyUltra.currentFrame == 2)
                    {
                        this.container.fastBuyUltraCont.btnFastBuyUltra.gotoAndStop(1);
                        this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyPrice;
                    }
                }
            }
            if (param1.target.name == "sphereSlotCase")
            {
                this.tempObject = param1.target.parent;
                if (this.tempObject.sphereAnima.visible)
                {
                    if (this.tempObject != this.container.sphereSlot1 && this.container.sphereSlot1.currentFrame == 2)
                    {
                        this.container.sphereSlot1.gotoAndStop(1);
                    }
                    if (this.tempObject != this.container.sphereSlot2 && this.container.sphereSlot2.currentFrame == 2)
                    {
                        this.container.sphereSlot2.gotoAndStop(1);
                    }
                    if (this.tempObject != this.container.sphereSlot3 && this.container.sphereSlot3.currentFrame == 2)
                    {
                        this.container.sphereSlot3.gotoAndStop(1);
                    }
                    if (this.tempObject != this.container.sphereSlot4 && this.container.sphereSlot4.currentFrame == 2)
                    {
                        this.container.sphereSlot4.gotoAndStop(1);
                    }
                    if (this.tempObject.currentFrame == 1)
                    {
                        this.tempObject.gotoAndStop(2);
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.tempObject.currentFrame == 2)
                {
                    this.tempObject.gotoAndStop(1);
                }
            }
            else
            {
                if (this.container.sphereSlot1.currentFrame == 2)
                {
                    this.container.sphereSlot1.gotoAndStop(1);
                }
                if (this.container.sphereSlot2.currentFrame == 2)
                {
                    this.container.sphereSlot2.gotoAndStop(1);
                }
                if (this.container.sphereSlot3.currentFrame == 2)
                {
                    this.container.sphereSlot3.gotoAndStop(1);
                }
                if (this.container.sphereSlot4.currentFrame == 2)
                {
                    this.container.sphereSlot4.gotoAndStop(1);
                }
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "btnUpgradeMenuCase")
            {
                if (this.container.btnUpgradeMenu.currentFrame == 2)
                {
                    this.container.btnUpgradeMenu.gotoAndStop(3);
                }
            }
            else if (event.target.name == "btnTowerUpgrCase")
            {
                if (event.target.parent.currentFrame == 2)
                {
                    this.tempObject = event.target.parent.costTXT.text;
                    event.target.parent.gotoAndStop(3);
                    event.target.parent.costTXT.text = this.tempObject;
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
                if (this.world.worldInterface.container.fireBacklight.visible)
                {
                    if (this.world.worldInterface.container.fireBacklight.currentFrame == this.world.worldInterface.container.fireBacklight.totalFrames)
                    {
                        this.world.worldInterface.container.fireBacklight.gotoAndStop(2);
                        this.world.worldInterface.container.fireBacklight.turnFlag = false;
                    }
                }
                if (this.world.worldInterface.container.iceBacklight.visible)
                {
                    if (this.world.worldInterface.container.iceBacklight.currentFrame == this.world.worldInterface.container.iceBacklight.totalFrames)
                    {
                        this.world.worldInterface.container.iceBacklight.gotoAndStop(2);
                        this.world.worldInterface.container.iceBacklight.turnFlag = false;
                    }
                }
                if (this.world.worldInterface.container.stoneBacklight.visible)
                {
                    if (this.world.worldInterface.container.stoneBacklight.currentFrame == this.world.worldInterface.container.stoneBacklight.totalFrames)
                    {
                        this.world.worldInterface.container.stoneBacklight.gotoAndStop(2);
                        this.world.worldInterface.container.stoneBacklight.turnFlag = false;
                    }
                }
                if (this.world.worldInterface.container.levinBacklight.visible)
                {
                    if (this.world.worldInterface.container.levinBacklight.currentFrame == this.world.worldInterface.container.levinBacklight.totalFrames)
                    {
                        this.world.worldInterface.container.levinBacklight.gotoAndStop(2);
                        this.world.worldInterface.container.levinBacklight.turnFlag = false;
                    }
                }
            }
            else if (event.target.name == "sphereSlotCase")
            {
                if (event.target.parent.sphereAnima.visible)
                {
                    this.tempObject = event.target.parent;
                    if (this.tempObject.sphereAnima.currentFrame == 1)
                    {
                        this.myTower.towerGetSphereManage("get", "fire");
                        this.spheresMonitor();
                    }
                    else if (this.tempObject.sphereAnima.currentFrame == 2)
                    {
                        this.myTower.towerGetSphereManage("get", "ice");
                        this.spheresMonitor();
                    }
                    else if (this.tempObject.sphereAnima.currentFrame == 3)
                    {
                        this.myTower.towerGetSphereManage("get", "stone");
                        this.spheresMonitor();
                    }
                    else if (this.tempObject.sphereAnima.currentFrame == 4)
                    {
                        this.myTower.towerGetSphereManage("get", "levin");
                        this.spheresMonitor();
                    }
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
                else
                {
                    if (this.world.worldInterface.container.fireSphere.alpha == 1 && this.world.worldInterface.container.fireSphere.visible)
                    {
                        this.world.worldInterface.container.fireBacklight.turnFlag = false;
                        this.world.worldInterface.container.fireBacklight.gotoAndStop(2);
                        this.world.worldInterface.container.fireBacklight.visible = true;
                    }
                    if (this.world.worldInterface.container.iceSphere.alpha == 1 && this.world.worldInterface.container.iceSphere.visible)
                    {
                        this.world.worldInterface.container.iceBacklight.turnFlag = false;
                        this.world.worldInterface.container.iceBacklight.gotoAndStop(2);
                        this.world.worldInterface.container.iceBacklight.visible = true;
                    }
                    if (this.world.worldInterface.container.stoneSphere.alpha == 1 && this.world.worldInterface.container.stoneSphere.visible)
                    {
                        this.world.worldInterface.container.stoneBacklight.turnFlag = false;
                        this.world.worldInterface.container.stoneBacklight.gotoAndStop(2);
                        this.world.worldInterface.container.stoneBacklight.visible = true;
                    }
                    if (this.world.worldInterface.container.levinSphere.alpha == 1 && this.world.worldInterface.container.levinSphere.visible)
                    {
                        this.world.worldInterface.container.levinBacklight.turnFlag = false;
                        this.world.worldInterface.container.levinBacklight.gotoAndStop(2);
                        this.world.worldInterface.container.levinBacklight.visible = true;
                    }
                }
            }
            else if (event.target.name == "btnGetAllCase")
            {
                if (event.target.parent.btnGetAllCase.buttonMode)
                {
                    this.i = 0;
                    while (this.i < this.world.listOfMoveSpheres.length)
                    {
                        
                        if (this.world.listOfMoveSpheres[this.i].owner == this.myTower)
                        {
                            if (this.world.listOfMoveSpheres[this.i].speedFrame >= 0)
                            {
                                this.world.listOfMoveSpheres[this.i].speedFrame = 0;
                            }
                        }
                        var _loc_2:* = this;
                        var _loc_3:* = this.i + 1;
                        _loc_2.i = _loc_3;
                    }
                    this.world.feature.listOfMoveSpheres();
                    this.i = 0;
                    while (this.i < 4)
                    {
                        
                        this.myTower.towerGetSphereManage("get", "fire");
                        this.spheresMonitor();
                        var _loc_2:* = this;
                        var _loc_3:* = this.i + 1;
                        _loc_2.i = _loc_3;
                    }
                    this.i = 0;
                    while (this.i < 4)
                    {
                        
                        this.myTower.towerGetSphereManage("get", "ice");
                        this.spheresMonitor();
                        var _loc_2:* = this;
                        var _loc_3:* = this.i + 1;
                        _loc_2.i = _loc_3;
                    }
                    this.i = 0;
                    while (this.i < 4)
                    {
                        
                        this.myTower.towerGetSphereManage("get", "stone");
                        this.spheresMonitor();
                        var _loc_2:* = this;
                        var _loc_3:* = this.i + 1;
                        _loc_2.i = _loc_3;
                    }
                    this.i = 0;
                    while (this.i < 4)
                    {
                        
                        this.myTower.towerGetSphereManage("get", "levin");
                        this.spheresMonitor();
                        var _loc_2:* = this;
                        var _loc_3:* = this.i + 1;
                        _loc_2.i = _loc_3;
                    }
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "fastBuyUltraCase")
            {
                if (!this.openFastBuyUltraFlag && !this.closeFastBuyUltraFlag)
                {
                    if (this.container.fastBuyUltraCont.btnFastBuyUltra.currentFrame == 2 && this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.buttonMode)
                    {
                        this.container.fastBuyUltraCont.btnFastBuyUltra.gotoAndStop(1);
                        this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyPrice;
                        this.fastBuyBlockCost = true;
                        this.fastBuyUltraManage();
                        this.ultraUpgradeTower(this.fastBuyUltraFlag, true);
                        var _loc_2:* = false;
                        this.myTower.mouseChildren = false;
                        this.myTower.mouseEnabled = _loc_2;
                        this.readyFastBuyUltraFlag = true;
                        if (this.fastBuyUltraFlag == "btnTowerUpgr1")
                        {
                            if (!this.myTower.shootingTurnStack[0])
                            {
                                if (this.world.worldInterface.fireCount == 0)
                                {
                                    this.world.worldInterface.archiveManage("buy", "fire");
                                }
                                if (this.world.worldInterface.fireCount > 0)
                                {
                                    this.world.worldInterface.archiveManage("get", "fire");
                                    this.world.getSphere.getSphereFromArchiveToTower();
                                }
                            }
                            if (!this.myTower.shootingTurnStack[2])
                            {
                                if (this.world.worldInterface.stoneCount == 0)
                                {
                                    this.world.worldInterface.archiveManage("buy", "stone");
                                }
                                if (this.world.worldInterface.stoneCount > 0)
                                {
                                    this.world.worldInterface.archiveManage("get", "stone");
                                    this.world.getSphere.getSphereFromArchiveToTower();
                                }
                            }
                        }
                        else if (this.fastBuyUltraFlag == "btnTowerUpgr2")
                        {
                            if (!this.myTower.shootingTurnStack[1])
                            {
                                if (this.world.worldInterface.iceCount == 0)
                                {
                                    this.world.worldInterface.archiveManage("buy", "ice");
                                }
                                if (this.world.worldInterface.iceCount > 0)
                                {
                                    this.world.worldInterface.archiveManage("get", "ice");
                                    this.world.getSphere.getSphereFromArchiveToTower();
                                }
                            }
                            if (!this.myTower.shootingTurnStack[3])
                            {
                                if (this.world.worldInterface.levinCount == 0)
                                {
                                    this.world.worldInterface.archiveManage("buy", "levin");
                                }
                                if (this.world.worldInterface.levinCount > 0)
                                {
                                    this.world.worldInterface.archiveManage("get", "levin");
                                    this.world.getSphere.getSphereFromArchiveToTower();
                                }
                            }
                        }
                        else if (this.fastBuyUltraFlag == "btnTowerUpgr3")
                        {
                            if (!this.myTower.shootingTurnStack[1])
                            {
                                if (this.world.worldInterface.iceCount == 0)
                                {
                                    this.world.worldInterface.archiveManage("buy", "ice");
                                }
                                if (this.world.worldInterface.iceCount > 0)
                                {
                                    this.world.worldInterface.archiveManage("get", "ice");
                                    this.world.getSphere.getSphereFromArchiveToTower();
                                }
                            }
                            if (!this.myTower.shootingTurnStack[2])
                            {
                                if (this.world.worldInterface.stoneCount == 0)
                                {
                                    this.world.worldInterface.archiveManage("buy", "stone");
                                }
                                if (this.world.worldInterface.stoneCount > 0)
                                {
                                    this.world.worldInterface.archiveManage("get", "stone");
                                    this.world.getSphere.getSphereFromArchiveToTower();
                                }
                            }
                        }
                        else if (this.fastBuyUltraFlag == "btnTowerUpgr4")
                        {
                            if (!this.myTower.shootingTurnStack[0])
                            {
                                if (this.world.worldInterface.fireCount == 0)
                                {
                                    this.world.worldInterface.archiveManage("buy", "fire");
                                }
                                if (this.world.worldInterface.fireCount > 0)
                                {
                                    this.world.worldInterface.archiveManage("get", "fire");
                                    this.world.getSphere.getSphereFromArchiveToTower();
                                }
                            }
                            if (!this.myTower.shootingTurnStack[3])
                            {
                                if (this.world.worldInterface.levinCount == 0)
                                {
                                    this.world.worldInterface.archiveManage("buy", "levin");
                                }
                                if (this.world.worldInterface.levinCount > 0)
                                {
                                    this.world.worldInterface.archiveManage("get", "levin");
                                    this.world.getSphere.getSphereFromArchiveToTower();
                                }
                            }
                        }
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            else if (event.target.name != "buySphereCase" && event.target.name != "sphereCase" && event.target.name != "btnUpgradeMenuBLOCKCase" && event.target.name != "fastBuyUltraCase" && event.target.parent != this.container && event.target.parent.parent != this.container)
            {
                this.lastE = event;
                this.closeMenu();
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (this.container.currentFrame == 1)
            {
                if (event.target.name == "btnUpgradeMenuCase")
                {
                    if (this.container.btnUpgradeMenu.currentFrame == 3)
                    {
                        if (this.myTower.towerType == 1)
                        {
                            this.tempObject = this.myTower.myPlace;
                            this.tempObject1 = [];
                            this.tempObject3 = [];
                            this.tempObject1 = this.tempObject1.concat(this.myTower.spheresStack);
                            this.tempObject2 = this.myTower.container.sphere1.currentFrame;
                            this.tempObject3 = this.tempObject3.concat(this.myTower.shootingTurnStack);
                            this.myTower.kill();
                            this.myTower = this.world.addTower("tower2", this.tempObject);
                            this.myTower.spheresStack = this.myTower.spheresStack.concat(this.tempObject1);
                            this.myTower.shootingTurnStack = [];
                            this.myTower.shootingTurnStack = this.myTower.shootingTurnStack.concat(this.tempObject3);
                            this.myTower.prepareSpheresGraphic();
                            if (this.myTower.container.sphere2_1.currentFrame + this.tempObject2 > this.myTower.container.sphere2_1.totalFrames)
                            {
                                this.tempObject = this.tempObject2 + this.myTower.container.sphere2_1.currentFrame - this.myTower.container.sphere2_1.totalFrames;
                                this.myTower.container.sphere2_1.gotoAndStop(this.tempObject);
                            }
                            else
                            {
                                this.myTower.container.sphere2_1.gotoAndStop(this.myTower.container.sphere2_1.currentFrame + this.tempObject2);
                            }
                            if (this.myTower.container.sphere2_2.currentFrame + this.tempObject2 > this.myTower.container.sphere2_2.totalFrames)
                            {
                                this.tempObject = this.tempObject2 + this.myTower.container.sphere2_2.currentFrame - this.myTower.container.sphere2_2.totalFrames;
                                this.myTower.container.sphere2_2.gotoAndStop(this.tempObject);
                            }
                            else
                            {
                                this.myTower.container.sphere2_2.gotoAndStop(this.myTower.container.sphere2_2.currentFrame + this.tempObject2);
                            }
                            this.world.setChildIndex(this.myTower, (this.world.getChildIndex(this) - 1));
                            this.container.btnUpgradeMenu.gotoAndStop(1);
                            this.world.money = this.world.money - Main.mainClass.readXMLClass.costSlot2XML;
                        }
                        else if (this.myTower.towerType == 2)
                        {
                            this.tempObject = this.myTower.myPlace;
                            this.tempObject1 = [];
                            this.tempObject3 = [];
                            this.tempObject1 = this.tempObject1.concat(this.myTower.spheresStack);
                            this.tempObject2 = this.myTower.container.sphere2_1.currentFrame;
                            this.tempObject3 = this.tempObject3.concat(this.myTower.shootingTurnStack);
                            this.myTower.kill();
                            this.myTower = this.world.addTower("tower3", this.tempObject);
                            this.myTower.spheresStack = this.myTower.spheresStack.concat(this.tempObject1);
                            this.myTower.shootingTurnStack = [];
                            this.myTower.shootingTurnStack = this.myTower.shootingTurnStack.concat(this.tempObject3);
                            this.myTower.prepareSpheresGraphic();
                            if (this.myTower.container.sphere3_1.currentFrame + this.tempObject2 > this.myTower.container.sphere3_1.totalFrames)
                            {
                                this.tempObject = this.tempObject2 + this.myTower.container.sphere3_1.currentFrame - this.myTower.container.sphere3_1.totalFrames;
                                this.myTower.container.sphere3_1.gotoAndStop(this.tempObject);
                            }
                            else
                            {
                                this.myTower.container.sphere3_1.gotoAndStop(this.myTower.container.sphere3_1.currentFrame + this.tempObject2);
                            }
                            if (this.myTower.container.sphere3_2.currentFrame + this.tempObject2 > this.myTower.container.sphere3_2.totalFrames)
                            {
                                this.tempObject = this.tempObject2 + this.myTower.container.sphere3_2.currentFrame - this.myTower.container.sphere3_2.totalFrames;
                                this.myTower.container.sphere3_2.gotoAndStop(this.tempObject);
                            }
                            else
                            {
                                this.myTower.container.sphere3_2.gotoAndStop(this.myTower.container.sphere3_2.currentFrame + this.tempObject2);
                            }
                            if (this.myTower.container.sphere3_3.currentFrame + this.tempObject2 > this.myTower.container.sphere3_3.totalFrames)
                            {
                                this.tempObject = this.tempObject2 + this.myTower.container.sphere3_3.currentFrame - this.myTower.container.sphere3_3.totalFrames;
                                this.myTower.container.sphere3_3.gotoAndStop(this.tempObject);
                            }
                            else
                            {
                                this.myTower.container.sphere3_3.gotoAndStop(this.myTower.container.sphere3_3.currentFrame + this.tempObject2);
                            }
                            this.world.setChildIndex(this.myTower, (this.world.getChildIndex(this) - 1));
                            this.container.btnUpgradeMenu.gotoAndStop(1);
                            this.world.money = this.world.money - Main.mainClass.readXMLClass.costSlot3XML;
                        }
                        else if (this.myTower.towerType == 3)
                        {
                            this.tempObject = this.myTower.myPlace;
                            this.tempObject1 = [];
                            this.tempObject3 = [];
                            this.tempObject1 = this.tempObject1.concat(this.myTower.spheresStack);
                            this.tempObject2 = this.myTower.container.sphere3_1.currentFrame;
                            this.tempObject3 = this.tempObject3.concat(this.myTower.shootingTurnStack);
                            this.myTower.kill();
                            this.myTower = this.world.addTower("tower4", this.tempObject);
                            this.myTower.spheresStack = this.myTower.spheresStack.concat(this.tempObject1);
                            this.myTower.shootingTurnStack = [];
                            this.myTower.shootingTurnStack = this.myTower.shootingTurnStack.concat(this.tempObject3);
                            this.myTower.prepareSpheresGraphic();
                            if (this.myTower.container.sphere4_1.currentFrame + this.tempObject2 > this.myTower.container.sphere4_1.totalFrames)
                            {
                                this.tempObject = this.tempObject2 + this.myTower.container.sphere4_1.currentFrame - this.myTower.container.sphere4_1.totalFrames;
                                this.myTower.container.sphere4_1.gotoAndStop(this.tempObject);
                            }
                            else
                            {
                                this.myTower.container.sphere4_1.gotoAndStop(this.myTower.container.sphere4_1.currentFrame + this.tempObject2);
                            }
                            if (this.myTower.container.sphere4_2.currentFrame + this.tempObject2 > this.myTower.container.sphere4_2.totalFrames)
                            {
                                this.tempObject = this.tempObject2 + this.myTower.container.sphere4_2.currentFrame - this.myTower.container.sphere4_2.totalFrames;
                                this.myTower.container.sphere4_2.gotoAndStop(this.tempObject);
                            }
                            else
                            {
                                this.myTower.container.sphere4_2.gotoAndStop(this.myTower.container.sphere4_2.currentFrame + this.tempObject2);
                            }
                            if (this.myTower.container.sphere4_3.currentFrame + this.tempObject2 > this.myTower.container.sphere4_3.totalFrames)
                            {
                                this.tempObject = this.tempObject2 + this.myTower.container.sphere4_3.currentFrame - this.myTower.container.sphere4_3.totalFrames;
                                this.myTower.container.sphere4_3.gotoAndStop(this.tempObject);
                            }
                            else
                            {
                                this.myTower.container.sphere4_3.gotoAndStop(this.myTower.container.sphere4_3.currentFrame + this.tempObject2);
                            }
                            if (this.myTower.container.sphere4_4.currentFrame + this.tempObject2 > this.myTower.container.sphere4_4.totalFrames)
                            {
                                this.tempObject = this.tempObject2 + this.myTower.container.sphere4_4.currentFrame - this.myTower.container.sphere4_4.totalFrames;
                                this.myTower.container.sphere4_4.gotoAndStop(this.tempObject);
                            }
                            else
                            {
                                this.myTower.container.sphere4_4.gotoAndStop(this.myTower.container.sphere4_4.currentFrame + this.tempObject2);
                            }
                            this.world.setChildIndex(this.myTower, (this.world.getChildIndex(this) - 1));
                            this.container.btnUpgradeMenu.gotoAndStop(1);
                            this.world.money = this.world.money - Main.mainClass.readXMLClass.costSlot4XML;
                        }
                        else if (this.myTower.towerType == 4)
                        {
                            this.upgradeManage();
                        }
                        this.towerRadius.width = this.myTower.radius * 2;
                        this.towerRadius.height = this.myTower.radius * 2 * this.world.scaleRadius;
                        this.world.worldInterface.updateInfo();
                        this.tempObject = new Object();
                        this.tempObject.target = new Object();
                        this.tempObject.target.name = "btnUpgradeMenuCase";
                        this.mouseMoveHandler(this.tempObject);
                        if (this.myTower.towerType == 4)
                        {
                            this.towerRadius1.visible = false;
                            this.hint.gotoAndStop(1);
                            this.hint.cont.stop();
                            this.hint.cont.cont1.stop();
                            this.hint.cont.cont1.sphere1.stop();
                            this.hint.cont.cont1.sphere2.stop();
                            this.hint.visible = false;
                        }
                    }
                }
                else if (this.container.btnUpgradeMenu.currentFrame == 3)
                {
                    this.container.btnUpgradeMenu.gotoAndStop(1);
                }
            }
            else if (this.container.currentFrame == this.container.totalFrames)
            {
                if (event.target.name == "btnTowerUpgrCase")
                {
                    if (event.target.parent != this.container.btnTowerUpgr1)
                    {
                        if (this.container.btnTowerUpgr1.currentFrame == 3)
                        {
                            this.tempObject = this.container.btnTowerUpgr1.costTXT.text;
                            this.container.btnTowerUpgr1.gotoAndStop(1);
                            this.container.btnTowerUpgr1.costTXT.text = this.tempObject;
                        }
                    }
                    if (event.target.parent != this.container.btnTowerUpgr2)
                    {
                        if (this.container.btnTowerUpgr2.currentFrame == 3)
                        {
                            this.tempObject = this.container.btnTowerUpgr2.costTXT.text;
                            this.container.btnTowerUpgr2.gotoAndStop(1);
                            this.container.btnTowerUpgr2.costTXT.text = this.tempObject;
                        }
                    }
                    if (event.target.parent != this.container.btnTowerUpgr3)
                    {
                        if (this.container.btnTowerUpgr3.currentFrame == 3)
                        {
                            this.tempObject = this.container.btnTowerUpgr3.costTXT.text;
                            this.container.btnTowerUpgr3.gotoAndStop(1);
                            this.container.btnTowerUpgr3.costTXT.text = this.tempObject;
                        }
                    }
                    if (event.target.parent != this.container.btnTowerUpgr4)
                    {
                        if (this.container.btnTowerUpgr4.currentFrame == 3)
                        {
                            this.tempObject = this.container.btnTowerUpgr4.costTXT.text;
                            this.container.btnTowerUpgr4.gotoAndStop(1);
                            this.container.btnTowerUpgr4.costTXT.text = this.tempObject;
                        }
                    }
                    if (event.target.parent.currentFrame == 3)
                    {
                        this.tempObject = event.target.parent;
                        this.tempObject1 = this.tempObject.costTXT.text;
                        this.tempObject.gotoAndStop(2);
                        this.tempObject.costTXT.text = this.tempObject1;
                        if (!this.fastBuyUltraFlag)
                        {
                            this.fastBuyUltraFlag = event.target.parent.name;
                            this.openFastBuyUltraFlag = true;
                            this.fastBuyUltraManage();
                        }
                        else if (event.target.parent.name == this.fastBuyUltraFlag)
                        {
                            this.fastBuyUltraFlag = null;
                            this.closeFastBuyUltraFlag = true;
                            this.mouseMoveHandler(event);
                        }
                        else
                        {
                            this.fastBuyUltraFlag = null;
                            if (this.exampleUltraTower)
                            {
                                this.exampleUltraManage("remove");
                            }
                            this.closeFastBuyUltraFlag = true;
                            this.mouseMoveHandler(event);
                            this.fastBuyUltraFlag = event.target.parent.name;
                            this.openFastBuyUltraFlag = true;
                            this.closeFastBuyUltraFlag = false;
                            this.fastBuyUltraManage();
                            this.exampleUltraManage(event.target.parent.name);
                        }
                    }
                }
                else
                {
                    if (this.container.btnTowerUpgr1.currentFrame == 3)
                    {
                        this.tempObject = this.container.btnTowerUpgr1.costTXT.text;
                        this.container.btnTowerUpgr1.gotoAndStop(1);
                        this.container.btnTowerUpgr1.costTXT.text = this.tempObject;
                    }
                    if (this.container.btnTowerUpgr2.currentFrame == 3)
                    {
                        this.tempObject = this.container.btnTowerUpgr2.costTXT.text;
                        this.container.btnTowerUpgr2.gotoAndStop(1);
                        this.container.btnTowerUpgr2.costTXT.text = this.tempObject;
                    }
                    if (this.container.btnTowerUpgr3.currentFrame == 3)
                    {
                        this.tempObject = this.container.btnTowerUpgr3.costTXT.text;
                        this.container.btnTowerUpgr3.gotoAndStop(1);
                        this.container.btnTowerUpgr3.costTXT.text = this.tempObject;
                    }
                    if (this.container.btnTowerUpgr4.currentFrame == 3)
                    {
                        this.tempObject = this.container.btnTowerUpgr4.costTXT.text;
                        this.container.btnTowerUpgr4.gotoAndStop(1);
                        this.container.btnTowerUpgr4.costTXT.text = this.tempObject;
                    }
                }
            }
            return;
        }// end function

        public function upgradeManage() : void
        {
            if (this.myTower.towerType == 4)
            {
                if (this.container.currentFrame == 1)
                {
                    this.openUltraSection = true;
                    var _loc_1:* = false;
                    this.mouseChildren = false;
                    this.mouseEnabled = _loc_1;
                }
                else
                {
                    this.fastBuyUltraManage();
                    if (this.container.btnTowerUpgr1)
                    {
                        if (Main.mainClass.readXMLClass.ultraTower1Block == 0)
                        {
                            if (this.world.money >= Main.mainClass.readXMLClass.costUltraFireStone && this.world.worldInterface.container.fireSphere.visible && this.world.worldInterface.container.stoneSphere.visible)
                            {
                                if (this.container.btnTowerUpgr1.currentFrame > 3)
                                {
                                    this.container.btnTowerUpgr1.gotoAndStop(1);
                                }
                                else
                                {
                                    this.container.btnTowerUpgr1.stop();
                                }
                                this.container.btnTowerUpgr1.btnTowerUpgrCase.buttonMode = true;
                            }
                            else
                            {
                                this.container.btnTowerUpgr1.gotoAndStop(4);
                                this.container.btnTowerUpgr1.btnTowerUpgrCase.buttonMode = false;
                            }
                            this.container.btnTowerUpgr1.costTXT.text = Main.mainClass.readXMLClass.costUltraFireStone;
                        }
                        else
                        {
                            this.container.btnTowerUpgr1.gotoAndStop(5);
                        }
                    }
                    if (this.container.btnTowerUpgr2)
                    {
                        if (Main.mainClass.readXMLClass.ultraTower2Block == 0)
                        {
                            if (this.world.money >= Main.mainClass.readXMLClass.costUltraIceLevin && this.world.worldInterface.container.iceSphere.visible && this.world.worldInterface.container.levinSphere.visible)
                            {
                                if (this.container.btnTowerUpgr2.currentFrame > 3)
                                {
                                    this.container.btnTowerUpgr2.gotoAndStop(1);
                                }
                                else
                                {
                                    this.container.btnTowerUpgr2.stop();
                                }
                                this.container.btnTowerUpgr2.btnTowerUpgrCase.buttonMode = true;
                            }
                            else
                            {
                                this.container.btnTowerUpgr2.gotoAndStop(4);
                                this.container.btnTowerUpgr2.btnTowerUpgrCase.buttonMode = false;
                            }
                            this.container.btnTowerUpgr2.costTXT.text = Main.mainClass.readXMLClass.costUltraIceLevin;
                        }
                        else
                        {
                            this.container.btnTowerUpgr2.gotoAndStop(5);
                        }
                    }
                    if (this.container.btnTowerUpgr3)
                    {
                        if (Main.mainClass.readXMLClass.ultraTower3Block == 0)
                        {
                            if (this.world.money >= Main.mainClass.readXMLClass.costUltraIceStone && this.world.worldInterface.container.iceSphere.visible && this.world.worldInterface.container.stoneSphere.visible)
                            {
                                if (this.container.btnTowerUpgr3.currentFrame > 3)
                                {
                                    this.container.btnTowerUpgr3.gotoAndStop(1);
                                }
                                else
                                {
                                    this.container.btnTowerUpgr3.stop();
                                }
                                this.container.btnTowerUpgr3.btnTowerUpgrCase.buttonMode = true;
                            }
                            else
                            {
                                this.container.btnTowerUpgr3.gotoAndStop(4);
                                this.container.btnTowerUpgr3.btnTowerUpgrCase.buttonMode = false;
                            }
                            this.container.btnTowerUpgr3.costTXT.text = Main.mainClass.readXMLClass.costUltraIceStone;
                        }
                        else
                        {
                            this.container.btnTowerUpgr3.gotoAndStop(5);
                        }
                    }
                    if (this.container.btnTowerUpgr4)
                    {
                        if (Main.mainClass.readXMLClass.ultraTower4Block == 0)
                        {
                            if (this.world.money >= Main.mainClass.readXMLClass.costUltraFireLevin && this.world.worldInterface.container.fireSphere.visible && this.world.worldInterface.container.levinSphere.visible)
                            {
                                if (this.container.btnTowerUpgr4.currentFrame > 3)
                                {
                                    this.container.btnTowerUpgr4.gotoAndStop(1);
                                }
                                else
                                {
                                    this.container.btnTowerUpgr4.stop();
                                }
                                this.container.btnTowerUpgr4.btnTowerUpgrCase.buttonMode = true;
                            }
                            else
                            {
                                this.container.btnTowerUpgr4.gotoAndStop(4);
                                this.container.btnTowerUpgr4.btnTowerUpgrCase.buttonMode = false;
                            }
                            this.container.btnTowerUpgr4.costTXT.text = Main.mainClass.readXMLClass.costUltraFireLevin;
                        }
                        else
                        {
                            this.container.btnTowerUpgr4.gotoAndStop(5);
                        }
                    }
                    this.fastBuyUltraManage();
                }
            }
            return;
        }// end function

        public function monitor() : void
        {
            if (this.myTower.towerType == 1)
            {
                this.container.sphereSlot1.gotoAndStop(1);
                if (Main.mainClass.readXMLClass.towerSlotBlock < 3)
                {
                    if (this.world.money >= Main.mainClass.readXMLClass.costSlot2XML)
                    {
                        this.container.sphereSlot2.gotoAndStop(3);
                        if (this.container.btnUpgradeMenu.currentFrame > 2)
                        {
                            this.container.btnUpgradeMenu.gotoAndStop(1);
                        }
                        this.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode = true;
                    }
                    else
                    {
                        this.container.sphereSlot2.gotoAndStop(4);
                        this.container.btnUpgradeMenu.gotoAndStop(4);
                    }
                    this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costSlot2XML;
                }
                else
                {
                    this.container.sphereSlot2.gotoAndStop(4);
                    if (this.container.btnUpgradeMenu.currentFrame != 5)
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(5);
                        if (!this.openFlag && !this.closeFlag)
                        {
                            this.hint.visible = true;
                            this.hintPosition(9);
                        }
                    }
                }
                this.container.sphereSlot3.gotoAndStop(4);
                this.container.sphereSlot4.gotoAndStop(4);
            }
            else if (this.myTower.towerType == 2)
            {
                this.container.sphereSlot1.gotoAndStop(1);
                this.container.sphereSlot2.gotoAndStop(1);
                if (Main.mainClass.readXMLClass.towerSlotBlock < 2)
                {
                    if (this.world.money >= Main.mainClass.readXMLClass.costSlot3XML)
                    {
                        this.container.sphereSlot3.gotoAndStop(3);
                        if (this.container.btnUpgradeMenu.currentFrame > 2)
                        {
                            this.container.btnUpgradeMenu.gotoAndStop(1);
                        }
                        this.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode = true;
                    }
                    else
                    {
                        this.container.sphereSlot3.gotoAndStop(4);
                        this.container.btnUpgradeMenu.gotoAndStop(4);
                    }
                    this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costSlot3XML;
                }
                else
                {
                    this.container.sphereSlot3.gotoAndStop(4);
                    if (this.container.btnUpgradeMenu.currentFrame != 5)
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(5);
                        if (!this.openFlag && !this.closeFlag)
                        {
                            this.hint.visible = true;
                            this.hintPosition(9);
                        }
                    }
                }
                this.container.sphereSlot4.gotoAndStop(4);
            }
            else if (this.myTower.towerType == 3)
            {
                this.container.sphereSlot1.gotoAndStop(1);
                this.container.sphereSlot2.gotoAndStop(1);
                this.container.sphereSlot3.gotoAndStop(1);
                if (Main.mainClass.readXMLClass.towerSlotBlock < 1)
                {
                    if (this.world.money >= Main.mainClass.readXMLClass.costSlot4XML)
                    {
                        this.container.sphereSlot4.gotoAndStop(3);
                        if (this.container.btnUpgradeMenu.currentFrame > 2)
                        {
                            this.container.btnUpgradeMenu.gotoAndStop(1);
                        }
                        this.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode = true;
                    }
                    else
                    {
                        this.container.sphereSlot4.gotoAndStop(4);
                        this.container.btnUpgradeMenu.gotoAndStop(4);
                    }
                    this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costSlot4XML;
                }
                else
                {
                    this.container.sphereSlot4.gotoAndStop(4);
                    if (this.container.btnUpgradeMenu.currentFrame != 5)
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(5);
                        if (!this.openFlag && !this.closeFlag)
                        {
                            this.hint.visible = true;
                            this.hintPosition(9);
                        }
                    }
                }
            }
            else if (this.myTower.towerType == 4)
            {
                this.container.sphereSlot1.gotoAndStop(1);
                this.container.sphereSlot2.gotoAndStop(1);
                this.container.sphereSlot3.gotoAndStop(1);
                this.container.sphereSlot4.gotoAndStop(1);
                this.upgradeManage();
            }
            if (!this.openFlag)
            {
                this.world.worldInterface.archiveSphereBacklightManage("");
                this.autoguidersButtons();
            }
            return;
        }// end function

        public function spheresMonitor() : void
        {
            this.container.sphereSlot1.sphereSlotCase.buttonMode = false;
            this.container.sphereSlot2.sphereSlotCase.buttonMode = false;
            this.container.sphereSlot3.sphereSlotCase.buttonMode = false;
            this.container.sphereSlot4.sphereSlotCase.buttonMode = false;
            this.container.btnGetAll.btnGetAllCase.buttonMode = false;
            this.container.sphereSlot1.sphereAnima.visible = false;
            this.container.sphereSlot2.sphereAnima.visible = false;
            this.container.sphereSlot3.sphereAnima.visible = false;
            this.container.sphereSlot4.sphereAnima.visible = false;
            if (this.myTower.spheresStack.length == 0)
            {
                if (this.container.sphereSlot1.currentFrame == 2)
                {
                    this.container.sphereSlot1.gotoAndStop(1);
                }
            }
            else if (this.myTower.spheresStack.length == 1)
            {
                if (this.container.sphereSlot2.currentFrame == 2)
                {
                    this.container.sphereSlot2.gotoAndStop(1);
                }
            }
            else if (this.myTower.spheresStack.length == 2)
            {
                if (this.container.sphereSlot3.currentFrame == 2)
                {
                    this.container.sphereSlot3.gotoAndStop(1);
                }
            }
            else if (this.myTower.spheresStack.length == 3)
            {
                if (this.container.sphereSlot4.currentFrame == 2)
                {
                    this.container.sphereSlot4.gotoAndStop(1);
                }
            }
            else if (this.myTower.spheresStack.length == 4)
            {
            }
            if (this.myTower.spheresStack.length >= 1)
            {
                this.container.btnGetAll.btnGetAllCase.buttonMode = true;
                if (this.container.sphereSlot1.currentFrame == 5)
                {
                    this.container.sphereSlot1.gotoAndStop(1);
                }
                this.container.sphereSlot1.sphereSlotCase.buttonMode = true;
                this.container.sphereSlot1.sphereAnima.visible = true;
                if (this.myTower.spheresStack[0] == "fire")
                {
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(1);
                    if (this.container.sphereSlot1.sphereAnima.fire.currentFrame == 1)
                    {
                        this.container.sphereSlot1.sphereAnima.fire.stop();
                    }
                }
                else if (this.myTower.spheresStack[0] == "ice")
                {
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(2);
                    if (this.container.sphereSlot1.sphereAnima.ice.currentFrame == 1)
                    {
                        this.container.sphereSlot1.sphereAnima.ice.stop();
                    }
                }
                else if (this.myTower.spheresStack[0] == "stone")
                {
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(3);
                    if (this.container.sphereSlot1.sphereAnima.stone.currentFrame == 1)
                    {
                        this.container.sphereSlot1.sphereAnima.stone.stop();
                    }
                }
                else if (this.myTower.spheresStack[0] == "levin")
                {
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(4);
                    if (this.container.sphereSlot1.sphereAnima.levin.currentFrame == 1)
                    {
                        this.container.sphereSlot1.sphereAnima.levin.stop();
                    }
                }
            }
            if (this.myTower.spheresStack.length >= 2)
            {
                if (this.container.sphereSlot2.currentFrame == 5)
                {
                    this.container.sphereSlot2.gotoAndStop(1);
                }
                this.container.sphereSlot2.sphereSlotCase.buttonMode = true;
                this.container.sphereSlot2.sphereAnima.visible = true;
                if (this.myTower.spheresStack[1] == "fire")
                {
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(1);
                    if (this.container.sphereSlot2.sphereAnima.fire.currentFrame == 1)
                    {
                        this.container.sphereSlot2.sphereAnima.fire.stop();
                    }
                }
                else if (this.myTower.spheresStack[1] == "ice")
                {
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(2);
                    if (this.container.sphereSlot2.sphereAnima.ice.currentFrame == 1)
                    {
                        this.container.sphereSlot2.sphereAnima.ice.stop();
                    }
                }
                else if (this.myTower.spheresStack[1] == "stone")
                {
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(3);
                    if (this.container.sphereSlot2.sphereAnima.stone.currentFrame == 1)
                    {
                        this.container.sphereSlot2.sphereAnima.stone.stop();
                    }
                }
                else if (this.myTower.spheresStack[1] == "levin")
                {
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(4);
                    if (this.container.sphereSlot2.sphereAnima.levin.currentFrame == 1)
                    {
                        this.container.sphereSlot2.sphereAnima.levin.stop();
                    }
                }
            }
            if (this.myTower.spheresStack.length >= 3)
            {
                if (this.container.sphereSlot3.currentFrame == 5)
                {
                    this.container.sphereSlot3.gotoAndStop(1);
                }
                this.container.sphereSlot3.sphereSlotCase.buttonMode = true;
                this.container.sphereSlot3.sphereAnima.visible = true;
                if (this.myTower.spheresStack[2] == "fire")
                {
                    this.container.sphereSlot3.sphereAnima.gotoAndStop(1);
                    if (this.container.sphereSlot3.sphereAnima.fire.currentFrame == 1)
                    {
                        this.container.sphereSlot3.sphereAnima.fire.stop();
                    }
                }
                else if (this.myTower.spheresStack[2] == "ice")
                {
                    this.container.sphereSlot3.sphereAnima.gotoAndStop(2);
                    if (this.container.sphereSlot3.sphereAnima.ice.currentFrame == 1)
                    {
                        this.container.sphereSlot3.sphereAnima.ice.stop();
                    }
                }
                else if (this.myTower.spheresStack[2] == "stone")
                {
                    this.container.sphereSlot3.sphereAnima.gotoAndStop(3);
                    if (this.container.sphereSlot3.sphereAnima.stone.currentFrame == 1)
                    {
                        this.container.sphereSlot3.sphereAnima.stone.stop();
                    }
                }
                else if (this.myTower.spheresStack[2] == "levin")
                {
                    this.container.sphereSlot3.sphereAnima.gotoAndStop(4);
                    if (this.container.sphereSlot3.sphereAnima.levin.currentFrame == 1)
                    {
                        this.container.sphereSlot3.sphereAnima.levin.stop();
                    }
                }
            }
            if (this.myTower.spheresStack.length >= 4)
            {
                if (this.container.sphereSlot4.currentFrame == 5)
                {
                    this.container.sphereSlot4.gotoAndStop(1);
                }
                this.container.sphereSlot4.sphereSlotCase.buttonMode = true;
                this.container.sphereSlot4.sphereAnima.visible = true;
                if (this.myTower.spheresStack[3] == "fire")
                {
                    this.container.sphereSlot4.sphereAnima.gotoAndStop(1);
                    if (this.container.sphereSlot4.sphereAnima.fire.currentFrame == 1)
                    {
                        this.container.sphereSlot4.sphereAnima.fire.stop();
                    }
                }
                else if (this.myTower.spheresStack[3] == "ice")
                {
                    this.container.sphereSlot4.sphereAnima.gotoAndStop(2);
                    if (this.container.sphereSlot4.sphereAnima.ice.currentFrame == 1)
                    {
                        this.container.sphereSlot4.sphereAnima.ice.stop();
                    }
                }
                else if (this.myTower.spheresStack[3] == "stone")
                {
                    this.container.sphereSlot4.sphereAnima.gotoAndStop(3);
                    if (this.container.sphereSlot4.sphereAnima.stone.currentFrame == 1)
                    {
                        this.container.sphereSlot4.sphereAnima.stone.stop();
                    }
                }
                else if (this.myTower.spheresStack[3] == "levin")
                {
                    this.container.sphereSlot4.sphereAnima.gotoAndStop(4);
                    if (this.container.sphereSlot4.sphereAnima.levin.currentFrame == 1)
                    {
                        this.container.sphereSlot4.sphereAnima.levin.stop();
                    }
                }
            }
            return;
        }// end function

        public function exampleUltraManage(param1:String) : void
        {
            if (param1 == "btnTowerUpgr1" || param1 == "btnTowerUpgr2" || param1 == "btnTowerUpgr3" || param1 == "btnTowerUpgr4")
            {
                if (param1 == "btnTowerUpgr1")
                {
                    if (this.exampleUltraTower)
                    {
                        this.myTower.removeChild(this.exampleUltraTower);
                    }
                    this.exampleUltraTower = new Tower5_mc();
                    this.exampleUltraTower.myParent = this.myTower;
                    this.exampleUltraTower.stop();
                    this.exampleUltraTower.upgr1.stop();
                    this.exampleUltraTower.blockTower.stop();
                    this.exampleUltraTower.boneBlock.stop();
                    this.exampleUltraTower.bot.stop();
                    this.exampleUltraTower.x = this.myTower.container.x;
                    this.exampleUltraTower.y = this.myTower.container.y;
                    this.exampleUltraTower.upgr1.visible = false;
                    this.exampleUltraTower.blockTower.visible = false;
                    this.exampleUltraTower.boneBlock.visible = false;
                    this.myTower.addChild(this.exampleUltraTower);
                }
                else if (param1 == "btnTowerUpgr2")
                {
                    if (this.exampleUltraTower)
                    {
                        this.myTower.removeChild(this.exampleUltraTower);
                    }
                    this.exampleUltraTower = new Tower6_mc();
                    this.exampleUltraTower.myParent = this.myTower;
                    this.exampleUltraTower.stop();
                    this.exampleUltraTower.shotAnima.stop();
                    this.exampleUltraTower.blockTower.stop();
                    this.exampleUltraTower.boneBlock.stop();
                    this.exampleUltraTower.x = this.myTower.container.x;
                    this.exampleUltraTower.y = this.myTower.container.y;
                    this.exampleUltraTower.shotAnima.visible = false;
                    this.exampleUltraTower.blockTower.visible = false;
                    this.exampleUltraTower.boneBlock.visible = false;
                    this.myTower.addChild(this.exampleUltraTower);
                }
                else if (param1 == "btnTowerUpgr3")
                {
                    if (this.exampleUltraTower)
                    {
                        this.myTower.removeChild(this.exampleUltraTower);
                    }
                    this.exampleUltraTower = new Tower7_mc();
                    this.exampleUltraTower.myParent = this.myTower;
                    this.exampleUltraTower.stop();
                    this.exampleUltraTower.cont1.stop();
                    this.exampleUltraTower.cont2.stop();
                    this.exampleUltraTower.cont3.stop();
                    this.exampleUltraTower.upgr1_1.stop();
                    this.exampleUltraTower.upgr1_2.stop();
                    this.exampleUltraTower.upgr1_3.stop();
                    this.exampleUltraTower.upgr1_4.stop();
                    this.exampleUltraTower.upgr1_5.stop();
                    this.exampleUltraTower.upgr1_6.stop();
                    this.exampleUltraTower.upgr1_7.stop();
                    this.exampleUltraTower.upgr1_8.stop();
                    this.exampleUltraTower.round1.stop();
                    this.exampleUltraTower.round2.stop();
                    this.exampleUltraTower.round3.stop();
                    this.exampleUltraTower.round4.stop();
                    this.exampleUltraTower.blockTower.stop();
                    this.exampleUltraTower.boneBlock.stop();
                    this.exampleUltraTower.x = this.myTower.container.x;
                    this.exampleUltraTower.y = this.myTower.container.y;
                    this.exampleUltraTower.upgr1_1.visible = false;
                    this.exampleUltraTower.upgr1_2.visible = false;
                    this.exampleUltraTower.upgr1_3.visible = false;
                    this.exampleUltraTower.upgr1_4.visible = false;
                    this.exampleUltraTower.upgr1_5.visible = false;
                    this.exampleUltraTower.upgr1_6.visible = false;
                    this.exampleUltraTower.upgr1_7.visible = false;
                    this.exampleUltraTower.upgr1_8.visible = false;
                    this.exampleUltraTower.round1.visible = false;
                    this.exampleUltraTower.round2.visible = false;
                    this.exampleUltraTower.round3.visible = false;
                    this.exampleUltraTower.round4.visible = false;
                    this.exampleUltraTower.blockTower.visible = false;
                    this.exampleUltraTower.boneBlock.visible = false;
                    this.myTower.addChild(this.exampleUltraTower);
                }
                else if (param1 == "btnTowerUpgr4")
                {
                    if (this.exampleUltraTower)
                    {
                        this.myTower.removeChild(this.exampleUltraTower);
                    }
                    this.exampleUltraTower = new Tower8_mc();
                    this.exampleUltraTower.myParent = this.myTower;
                    this.exampleUltraTower.stop();
                    this.exampleUltraTower.cont1.stop();
                    this.exampleUltraTower.cont2.stop();
                    this.exampleUltraTower.cont3.stop();
                    this.exampleUltraTower.cont4.stop();
                    this.exampleUltraTower.cont5.stop();
                    this.exampleUltraTower.cont6.stop();
                    this.exampleUltraTower.fireLight1.stop();
                    this.exampleUltraTower.blockTower.stop();
                    this.exampleUltraTower.boneBlock.stop();
                    this.exampleUltraTower.x = this.myTower.container.x;
                    this.exampleUltraTower.y = this.myTower.container.y;
                    this.exampleUltraTower.cont4.visible = false;
                    this.exampleUltraTower.cont5.visible = false;
                    this.exampleUltraTower.cont6.visible = false;
                    this.exampleUltraTower.fireLight1.visible = false;
                    this.exampleUltraTower.blockTower.visible = false;
                    this.exampleUltraTower.boneBlock.visible = false;
                    this.myTower.addChild(this.exampleUltraTower);
                }
                this.container.btnGetAll.visible = false;
                this.container.cont2.visible = false;
                this.myTower.container.visible = false;
            }
            else if (param1 == "remove")
            {
                this.container.btnGetAll.visible = true;
                this.container.cont2.visible = true;
                this.exampleUltraTower.myParent.container.visible = true;
                this.exampleUltraTower.myParent.removeChild(this.exampleUltraTower);
                this.exampleUltraTower = null;
            }
            return;
        }// end function

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(Main.mainClass.worldClass.mouseX, Main.mainClass.worldClass.mouseY);
            this.autoguidesObject = null;
            if (this.container.currentFrame == 1)
            {
                if (this.container.btnUpgradeMenu.btnUpgradeMenuCase)
                {
                    this.autoguidesObject_pt = this.container.btnUpgradeMenu.localToGlobal(new Point(this.container.btnUpgradeMenu.btnUpgradeMenuCase.x, this.container.btnUpgradeMenu.btnUpgradeMenuCase.y));
                    this.autoguidesObjectWidth = this.container.btnUpgradeMenu.btnUpgradeMenuCase.width / 2;
                    this.autoguidesObjectHeight = this.container.btnUpgradeMenu.btnUpgradeMenuCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.btnUpgradeMenu.btnUpgradeMenuCase;
                    }
                }
            }
            else if (this.container.currentFrame == this.container.totalFrames)
            {
                this.autoguidesObject_pt = this.container.btnTowerUpgr1.localToGlobal(new Point(this.container.btnTowerUpgr1.btnTowerUpgrCase.x, this.container.btnTowerUpgr1.btnTowerUpgrCase.y));
                this.autoguidesObjectWidth = this.container.btnTowerUpgr1.btnTowerUpgrCase.width / 2;
                this.autoguidesObjectHeight = this.container.btnTowerUpgr1.btnTowerUpgrCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.btnTowerUpgr1.btnTowerUpgrCase;
                }
                if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.btnTowerUpgr2.localToGlobal(new Point(this.container.btnTowerUpgr2.btnTowerUpgrCase.x, this.container.btnTowerUpgr2.btnTowerUpgrCase.y));
                    this.autoguidesObjectWidth = this.container.btnTowerUpgr2.btnTowerUpgrCase.width / 2;
                    this.autoguidesObjectHeight = this.container.btnTowerUpgr2.btnTowerUpgrCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.btnTowerUpgr2.btnTowerUpgrCase;
                    }
                }
                if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.btnTowerUpgr3.localToGlobal(new Point(this.container.btnTowerUpgr3.btnTowerUpgrCase.x, this.container.btnTowerUpgr3.btnTowerUpgrCase.y));
                    this.autoguidesObjectWidth = this.container.btnTowerUpgr3.btnTowerUpgrCase.width / 2;
                    this.autoguidesObjectHeight = this.container.btnTowerUpgr3.btnTowerUpgrCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.btnTowerUpgr3.btnTowerUpgrCase;
                    }
                }
                if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.btnTowerUpgr4.localToGlobal(new Point(this.container.btnTowerUpgr4.btnTowerUpgrCase.x, this.container.btnTowerUpgr4.btnTowerUpgrCase.y));
                    this.autoguidesObjectWidth = this.container.btnTowerUpgr4.btnTowerUpgrCase.width / 2;
                    this.autoguidesObjectHeight = this.container.btnTowerUpgr4.btnTowerUpgrCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.btnTowerUpgr4.btnTowerUpgrCase;
                    }
                }
                if (!this.autoguidesObject && this.fastBuyUltraFlag)
                {
                    this.autoguidesObject_pt = this.container.fastBuyUltraCont.btnFastBuyUltra.localToGlobal(new Point(this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.x, this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.y));
                    this.autoguidesObjectWidth = this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.width / 2;
                    this.autoguidesObjectHeight = this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase;
                    }
                }
            }
            if (!this.autoguidesObject)
            {
                this.autoguidesObject_pt = this.container.sphereSlot1.localToGlobal(new Point(this.container.sphereSlot1.sphereSlotCase.x, this.container.sphereSlot1.sphereSlotCase.y));
                this.autoguidesObjectWidth = this.container.sphereSlot1.sphereSlotCase.width / 2;
                this.autoguidesObjectHeight = this.container.sphereSlot1.sphereSlotCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.sphereSlot1.sphereSlotCase;
                }
                if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.sphereSlot2.localToGlobal(new Point(this.container.sphereSlot2.sphereSlotCase.x, this.container.sphereSlot2.sphereSlotCase.y));
                    this.autoguidesObjectWidth = this.container.sphereSlot2.sphereSlotCase.width / 2;
                    this.autoguidesObjectHeight = this.container.sphereSlot2.sphereSlotCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.sphereSlot2.sphereSlotCase;
                    }
                }
                if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.sphereSlot3.localToGlobal(new Point(this.container.sphereSlot3.sphereSlotCase.x, this.container.sphereSlot3.sphereSlotCase.y));
                    this.autoguidesObjectWidth = this.container.sphereSlot3.sphereSlotCase.width / 2;
                    this.autoguidesObjectHeight = this.container.sphereSlot3.sphereSlotCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.sphereSlot3.sphereSlotCase;
                    }
                }
                if (!this.autoguidesObject)
                {
                    this.autoguidesObject_pt = this.container.sphereSlot4.localToGlobal(new Point(this.container.sphereSlot4.sphereSlotCase.x, this.container.sphereSlot4.sphereSlotCase.y));
                    this.autoguidesObjectWidth = this.container.sphereSlot4.sphereSlotCase.width / 2;
                    this.autoguidesObjectHeight = this.container.sphereSlot4.sphereSlotCase.height / 2;
                    if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                    {
                        this.autoguidesObject = this.container.sphereSlot4.sphereSlotCase;
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

        public function hintManage(param1:String, param2:int = 1, param3:Object = null) : void
        {
            if (param1 == "ultraButtons")
            {
                if (!param3)
                {
                    if (!this.exampleUltraTower)
                    {
                        if (param2 == 1)
                        {
                            this.exampleUltraManage("btnTowerUpgr1");
                        }
                        else if (param2 == 2)
                        {
                            this.exampleUltraManage("btnTowerUpgr2");
                        }
                        else if (param2 == 3)
                        {
                            this.exampleUltraManage("btnTowerUpgr3");
                        }
                        else if (param2 == 4)
                        {
                            this.exampleUltraManage("btnTowerUpgr4");
                        }
                    }
                    else if (param2 == 1)
                    {
                        if (!(this.exampleUltraTower is Tower5_mc))
                        {
                            this.exampleUltraManage("remove");
                            this.exampleUltraManage("btnTowerUpgr1");
                        }
                    }
                    else if (param2 == 2)
                    {
                        if (!(this.exampleUltraTower is Tower6_mc))
                        {
                            this.exampleUltraManage("remove");
                            this.exampleUltraManage("btnTowerUpgr2");
                        }
                    }
                    else if (param2 == 3)
                    {
                        if (!(this.exampleUltraTower is Tower7_mc))
                        {
                            this.exampleUltraManage("remove");
                            this.exampleUltraManage("btnTowerUpgr3");
                        }
                    }
                    else if (param2 == 4)
                    {
                        if (!(this.exampleUltraTower is Tower8_mc))
                        {
                            this.exampleUltraManage("remove");
                            this.exampleUltraManage("btnTowerUpgr4");
                        }
                    }
                    this.hintPosition(param2, param3);
                    this.hint.cont.gotoAndStop(param2);
                    this.hint.cont.cont1.sphere1.stop();
                    this.hint.cont.cont1.sphere2.stop();
                    this.hint.visible = true;
                }
                else
                {
                    this.hintPosition(param2, param3);
                    this.hint.visible = true;
                }
            }
            return;
        }// end function

        public function hintPosition(param1:int = 1, param2:Object = null) : void
        {
            if (param1 == 1)
            {
                this.tempObject = this.container.btnTowerUpgr1.localToGlobal(new Point(this.container.btnTowerUpgr1.btnTowerUpgrCase.x, this.container.btnTowerUpgr1.btnTowerUpgrCase.y));
            }
            else if (param1 == 2)
            {
                this.tempObject = this.container.btnTowerUpgr2.localToGlobal(new Point(this.container.btnTowerUpgr2.btnTowerUpgrCase.x, this.container.btnTowerUpgr2.btnTowerUpgrCase.y));
            }
            else if (param1 == 3)
            {
                this.tempObject = this.container.btnTowerUpgr3.localToGlobal(new Point(this.container.btnTowerUpgr3.btnTowerUpgrCase.x, this.container.btnTowerUpgr3.btnTowerUpgrCase.y));
            }
            else if (param1 == 4)
            {
                this.tempObject = this.container.btnTowerUpgr4.localToGlobal(new Point(this.container.btnTowerUpgr4.btnTowerUpgrCase.x, this.container.btnTowerUpgr4.btnTowerUpgrCase.y));
            }
            else if (param1 == 5)
            {
                this.tempObject = this.container.localToGlobal(new Point(this.container.btnUpgradeMenu.x, this.container.btnUpgradeMenu.y));
                this.hint.gotoAndStop((param1 - 1));
            }
            else if (param1 == 9)
            {
                if (!param2)
                {
                    this.tempObject = this.container.localToGlobal(new Point(this.container.btnUpgradeMenu.x, this.container.btnUpgradeMenu.y));
                }
                else
                {
                    this.tempObject = param2.parent.localToGlobal(new Point(param2.x, param2.y));
                }
                this.hint.gotoAndStop((param1 - 1));
            }
            if (param1 < 5)
            {
                if (this.tempObject.x < 120)
                {
                    if (this.tempObject.y < 120)
                    {
                        this.hint.gotoAndStop(4);
                        this.hint.y = this.tempObject.y + 12;
                    }
                    else if (this.tempObject.y > Main.SCREEN_HEIGHT - 120)
                    {
                        this.hint.gotoAndStop(2);
                        this.hint.y = this.tempObject.y - 12;
                    }
                    else
                    {
                        this.hint.gotoAndStop(2);
                        this.hint.y = this.tempObject.y - 12;
                    }
                    this.hint.x = this.tempObject.x + 12;
                }
                else if (this.tempObject.x > Main.SCREEN_WIDTH - 120)
                {
                    if (this.tempObject.y < 120)
                    {
                        this.hint.gotoAndStop(3);
                        this.hint.y = this.tempObject.y + 12;
                    }
                    else if (this.tempObject.y > Main.SCREEN_HEIGHT - 120)
                    {
                        this.hint.gotoAndStop(1);
                        this.hint.y = this.tempObject.y - 12;
                    }
                    else
                    {
                        this.hint.gotoAndStop(1);
                        this.hint.y = this.tempObject.y + 12;
                    }
                    this.hint.x = this.tempObject.x - 12;
                }
                else if (this.tempObject.y < 120)
                {
                    if (this.tempObject.x < 120)
                    {
                        this.hint.gotoAndStop(4);
                        this.hint.x = this.tempObject.x + 12;
                        this.hint.y = this.tempObject.y + 12;
                    }
                    else if (this.tempObject.x > Main.SCREEN_WIDTH - 120)
                    {
                        this.hint.gotoAndStop(3);
                        this.hint.x = this.tempObject.x - 12;
                        this.hint.y = this.tempObject.y + 12;
                    }
                    else
                    {
                        this.hint.gotoAndStop(4);
                        this.hint.x = this.tempObject.x;
                        this.hint.y = this.tempObject.y + 12;
                    }
                }
                else if (this.tempObject.y > Main.SCREEN_HEIGHT - 120)
                {
                    if (this.tempObject.x < 120)
                    {
                        this.hint.gotoAndStop(2);
                        this.hint.x = this.tempObject.x + 12;
                        this.hint.y = this.tempObject.y - 12;
                    }
                    else if (this.tempObject.x > Main.SCREEN_WIDTH - 120)
                    {
                        this.hint.gotoAndStop(1);
                        this.hint.x = this.tempObject.x - 12;
                        this.hint.y = this.tempObject.y - 12;
                    }
                    else
                    {
                        this.hint.gotoAndStop(2);
                        this.hint.x = this.tempObject.x;
                        this.hint.y = this.tempObject.y - 12;
                    }
                }
                else
                {
                    this.hint.gotoAndStop(2);
                    this.hint.x = this.tempObject.x;
                    this.hint.y = this.tempObject.y - 12;
                }
            }
            else if (this.tempObject.x < 120)
            {
                if (this.tempObject.y < 120)
                {
                    this.hint.gotoAndStop(this.hint.currentFrame + 4);
                    this.hint.y = this.tempObject.y + 12;
                }
                else if (this.tempObject.y > Main.SCREEN_HEIGHT - 120)
                {
                    this.hint.gotoAndStop(this.hint.currentFrame + 2);
                    this.hint.y = this.tempObject.y - 12;
                }
                else
                {
                    this.hint.gotoAndStop(this.hint.currentFrame + 2);
                    this.hint.y = this.tempObject.y - 12;
                }
                this.hint.x = this.tempObject.x + 12;
            }
            else if (this.tempObject.x > Main.SCREEN_WIDTH - 120)
            {
                if (this.tempObject.y < 120)
                {
                    this.hint.gotoAndStop(this.hint.currentFrame + 3);
                    this.hint.y = this.tempObject.y + 12;
                }
                else if (this.tempObject.y > Main.SCREEN_HEIGHT - 120)
                {
                    this.hint.gotoAndStop((this.hint.currentFrame + 1));
                    this.hint.y = this.tempObject.y - 12;
                }
                else
                {
                    this.hint.gotoAndStop((this.hint.currentFrame + 1));
                    this.hint.y = this.tempObject.y + 12;
                }
                this.hint.x = this.tempObject.x - 12;
            }
            else if (this.tempObject.y < 120)
            {
                if (this.tempObject.x < 120)
                {
                    this.hint.gotoAndStop(this.hint.currentFrame + 4);
                    this.hint.x = this.tempObject.x + 12;
                    this.hint.y = this.tempObject.y + 12;
                }
                else if (this.tempObject.x > Main.SCREEN_WIDTH - 120)
                {
                    this.hint.gotoAndStop(this.hint.currentFrame + 3);
                    this.hint.x = this.tempObject.x - 12;
                    this.hint.y = this.tempObject.y + 12;
                }
                else
                {
                    this.hint.gotoAndStop(this.hint.currentFrame + 4);
                    this.hint.x = this.tempObject.x;
                    this.hint.y = this.tempObject.y + 12;
                }
            }
            else if (this.tempObject.y > Main.SCREEN_HEIGHT - 120)
            {
                if (this.tempObject.x < 120)
                {
                    this.hint.gotoAndStop(this.hint.currentFrame + 2);
                    this.hint.x = this.tempObject.x + 12;
                    this.hint.y = this.tempObject.y - 12;
                }
                else if (this.tempObject.x > Main.SCREEN_WIDTH - 120)
                {
                    this.hint.gotoAndStop((this.hint.currentFrame + 1));
                    this.hint.x = this.tempObject.x - 12;
                    this.hint.y = this.tempObject.y - 12;
                }
                else
                {
                    this.hint.gotoAndStop(this.hint.currentFrame + 2);
                    this.hint.x = this.tempObject.x;
                    this.hint.y = this.tempObject.y - 12;
                }
            }
            else
            {
                this.hint.gotoAndStop(this.hint.currentFrame + 2);
                this.hint.x = this.tempObject.x;
                this.hint.y = this.tempObject.y - 12;
            }
            this.tempObject = null;
            return;
        }// end function

        public function ultraUpgradeTower(param1:String, param2:Boolean = false) : void
        {
            if (param1 == "btnTowerUpgr1")
            {
                if (this.myTower.shootingTurnStack[0])
                {
                    if (this.myTower.shootingTurnStack[0][3] > 1)
                    {
                        this.world.getSphere = new GetSphere();
                        this.world.getSphere.owner = this.world.worldInterface.container.fireSphere;
                        this.world.getSphere.ownerType = "archive";
                        this.world.getSphere.ownerPoint = this.world.worldInterface.container.fireSphere.myPoint;
                        this.world.addChild(this.world.getSphere);
                        this.i = 0;
                        while (this.i < (this.myTower.shootingTurnStack[0][3] - 1))
                        {
                            
                            (this.i + 1);
                            this.world.getSphere.manage("add", "fire");
                        }
                        this.myTower.spheresManage("get", "fire", (this.myTower.shootingTurnStack[0][3] - 1));
                        this.world.getSphere.x = this.myTower.this_pt.x;
                        this.world.getSphere.y = this.myTower.this_pt.y;
                        this.world.getSphere.retrieveGetSphere();
                    }
                }
                if (this.myTower.shootingTurnStack[1])
                {
                    this.world.getSphere = new GetSphere();
                    this.world.getSphere.owner = this.world.worldInterface.container.iceSphere;
                    this.world.getSphere.ownerType = "archive";
                    this.world.getSphere.ownerPoint = this.world.worldInterface.container.iceSphere.myPoint;
                    this.world.addChild(this.world.getSphere);
                    this.i = 0;
                    while (this.i < this.myTower.shootingTurnStack[1][3])
                    {
                        
                        (this.i + 1);
                        this.world.getSphere.manage("add", "ice");
                    }
                    this.myTower.spheresManage("get", "ice", this.myTower.shootingTurnStack[1][3]);
                    this.world.getSphere.x = this.myTower.this_pt.x;
                    this.world.getSphere.y = this.myTower.this_pt.y;
                    this.world.getSphere.retrieveGetSphere();
                }
                if (this.myTower.shootingTurnStack[2])
                {
                    if (this.myTower.shootingTurnStack[2][3] > 1)
                    {
                        this.world.getSphere = new GetSphere();
                        this.world.getSphere.owner = this.world.worldInterface.container.stoneSphere;
                        this.world.getSphere.ownerType = "archive";
                        this.world.getSphere.ownerPoint = this.world.worldInterface.container.stoneSphere.myPoint;
                        this.world.addChild(this.world.getSphere);
                        this.i = 0;
                        while (this.i < (this.myTower.shootingTurnStack[2][3] - 1))
                        {
                            
                            (this.i + 1);
                            this.world.getSphere.manage("add", "stone");
                        }
                        this.myTower.spheresManage("get", "stone", (this.myTower.shootingTurnStack[2][3] - 1));
                        this.world.getSphere.x = this.myTower.this_pt.x;
                        this.world.getSphere.y = this.myTower.this_pt.y;
                        this.world.getSphere.retrieveGetSphere();
                    }
                }
                if (this.myTower.shootingTurnStack[3])
                {
                    this.world.getSphere = new GetSphere();
                    this.world.getSphere.owner = this.world.worldInterface.container.levinSphere;
                    this.world.getSphere.ownerType = "archive";
                    this.world.getSphere.ownerPoint = this.world.worldInterface.container.levinSphere.myPoint;
                    this.world.addChild(this.world.getSphere);
                    this.i = 0;
                    while (this.i < this.myTower.shootingTurnStack[3][3])
                    {
                        
                        (this.i + 1);
                        this.world.getSphere.manage("add", "levin");
                    }
                    this.myTower.spheresManage("get", "levin", this.myTower.shootingTurnStack[3][3]);
                    this.world.getSphere.x = this.myTower.this_pt.x;
                    this.world.getSphere.y = this.myTower.this_pt.y;
                    this.world.getSphere.retrieveGetSphere();
                }
                if (!param2)
                {
                    this.tempObject = this.myTower.myPlace;
                    this.myTower.kill();
                    this.myTower = this.world.addTower("tower5", this.tempObject);
                    this.world.setChildIndex(this.myTower, (this.world.getChildIndex(this) - 1));
                    this.world.money = this.world.money - Main.mainClass.readXMLClass.costUltraFireStone;
                    this.closeMenu();
                }
            }
            else if (param1 == "btnTowerUpgr2")
            {
                if (this.myTower.shootingTurnStack[0])
                {
                    this.world.getSphere = new GetSphere();
                    this.world.getSphere.owner = this.world.worldInterface.container.fireSphere;
                    this.world.getSphere.ownerType = "archive";
                    this.world.getSphere.ownerPoint = this.world.worldInterface.container.fireSphere.myPoint;
                    this.world.addChild(this.world.getSphere);
                    this.i = 0;
                    while (this.i < this.myTower.shootingTurnStack[0][3])
                    {
                        
                        (this.i + 1);
                        this.world.getSphere.manage("add", "fire");
                    }
                    this.myTower.spheresManage("get", "fire", this.myTower.shootingTurnStack[0][3]);
                    this.world.getSphere.x = this.myTower.this_pt.x;
                    this.world.getSphere.y = this.myTower.this_pt.y;
                    this.world.getSphere.retrieveGetSphere();
                }
                if (this.myTower.shootingTurnStack[1])
                {
                    if (this.myTower.shootingTurnStack[1][3] > 1)
                    {
                        this.world.getSphere = new GetSphere();
                        this.world.getSphere.owner = this.world.worldInterface.container.iceSphere;
                        this.world.getSphere.ownerType = "archive";
                        this.world.getSphere.ownerPoint = this.world.worldInterface.container.iceSphere.myPoint;
                        this.world.addChild(this.world.getSphere);
                        this.i = 0;
                        while (this.i < (this.myTower.shootingTurnStack[1][3] - 1))
                        {
                            
                            (this.i + 1);
                            this.world.getSphere.manage("add", "ice");
                        }
                        this.myTower.spheresManage("get", "ice", (this.myTower.shootingTurnStack[1][3] - 1));
                        this.world.getSphere.x = this.myTower.this_pt.x;
                        this.world.getSphere.y = this.myTower.this_pt.y;
                        this.world.getSphere.retrieveGetSphere();
                    }
                }
                if (this.myTower.shootingTurnStack[2])
                {
                    this.world.getSphere = new GetSphere();
                    this.world.getSphere.owner = this.world.worldInterface.container.stoneSphere;
                    this.world.getSphere.ownerType = "archive";
                    this.world.getSphere.ownerPoint = this.world.worldInterface.container.stoneSphere.myPoint;
                    this.world.addChild(this.world.getSphere);
                    this.i = 0;
                    while (this.i < this.myTower.shootingTurnStack[2][3])
                    {
                        
                        (this.i + 1);
                        this.world.getSphere.manage("add", "stone");
                    }
                    this.myTower.spheresManage("get", "stone", this.myTower.shootingTurnStack[2][3]);
                    this.world.getSphere.x = this.myTower.this_pt.x;
                    this.world.getSphere.y = this.myTower.this_pt.y;
                    this.world.getSphere.retrieveGetSphere();
                }
                if (this.myTower.shootingTurnStack[3])
                {
                    if (this.myTower.shootingTurnStack[3][3] > 1)
                    {
                        this.world.getSphere = new GetSphere();
                        this.world.getSphere.owner = this.world.worldInterface.container.levinSphere;
                        this.world.getSphere.ownerType = "archive";
                        this.world.getSphere.ownerPoint = this.world.worldInterface.container.levinSphere.myPoint;
                        this.world.addChild(this.world.getSphere);
                        this.i = 0;
                        while (this.i < (this.myTower.shootingTurnStack[3][3] - 1))
                        {
                            
                            (this.i + 1);
                            this.world.getSphere.manage("add", "levin");
                        }
                        this.myTower.spheresManage("get", "levin", (this.myTower.shootingTurnStack[3][3] - 1));
                        this.world.getSphere.x = this.myTower.this_pt.x;
                        this.world.getSphere.y = this.myTower.this_pt.y;
                        this.world.getSphere.retrieveGetSphere();
                    }
                }
                if (!param2)
                {
                    this.tempObject = this.myTower.myPlace;
                    this.myTower.kill();
                    this.myTower = this.world.addTower("tower6", this.tempObject);
                    this.world.setChildIndex(this.myTower, (this.world.getChildIndex(this) - 1));
                    this.world.money = this.world.money - Main.mainClass.readXMLClass.costUltraIceLevin;
                    this.closeMenu();
                }
            }
            else if (param1 == "btnTowerUpgr3")
            {
                if (this.myTower.shootingTurnStack[0])
                {
                    this.world.getSphere = new GetSphere();
                    this.world.getSphere.owner = this.world.worldInterface.container.fireSphere;
                    this.world.getSphere.ownerType = "archive";
                    this.world.getSphere.ownerPoint = this.world.worldInterface.container.fireSphere.myPoint;
                    this.world.addChild(this.world.getSphere);
                    this.i = 0;
                    while (this.i < this.myTower.shootingTurnStack[0][3])
                    {
                        
                        (this.i + 1);
                        this.world.getSphere.manage("add", "fire");
                    }
                    this.myTower.spheresManage("get", "fire", this.myTower.shootingTurnStack[0][3]);
                    this.world.getSphere.x = this.myTower.this_pt.x;
                    this.world.getSphere.y = this.myTower.this_pt.y;
                    this.world.getSphere.retrieveGetSphere();
                }
                if (this.myTower.shootingTurnStack[1])
                {
                    if (this.myTower.shootingTurnStack[1][3] > 1)
                    {
                        this.world.getSphere = new GetSphere();
                        this.world.getSphere.owner = this.world.worldInterface.container.iceSphere;
                        this.world.getSphere.ownerType = "archive";
                        this.world.getSphere.ownerPoint = this.world.worldInterface.container.iceSphere.myPoint;
                        this.world.addChild(this.world.getSphere);
                        this.i = 0;
                        while (this.i < (this.myTower.shootingTurnStack[1][3] - 1))
                        {
                            
                            (this.i + 1);
                            this.world.getSphere.manage("add", "ice");
                        }
                        this.myTower.spheresManage("get", "ice", (this.myTower.shootingTurnStack[1][3] - 1));
                        this.world.getSphere.x = this.myTower.this_pt.x;
                        this.world.getSphere.y = this.myTower.this_pt.y;
                        this.world.getSphere.retrieveGetSphere();
                    }
                }
                if (this.myTower.shootingTurnStack[2])
                {
                    if (this.myTower.shootingTurnStack[2][3] > 1)
                    {
                        this.world.getSphere = new GetSphere();
                        this.world.getSphere.owner = this.world.worldInterface.container.stoneSphere;
                        this.world.getSphere.ownerType = "archive";
                        this.world.getSphere.ownerPoint = this.world.worldInterface.container.stoneSphere.myPoint;
                        this.world.addChild(this.world.getSphere);
                        this.i = 0;
                        while (this.i < (this.myTower.shootingTurnStack[2][3] - 1))
                        {
                            
                            (this.i + 1);
                            this.world.getSphere.manage("add", "stone");
                        }
                        this.myTower.spheresManage("get", "stone", (this.myTower.shootingTurnStack[2][3] - 1));
                        this.world.getSphere.x = this.myTower.this_pt.x;
                        this.world.getSphere.y = this.myTower.this_pt.y;
                        this.world.getSphere.retrieveGetSphere();
                    }
                }
                if (this.myTower.shootingTurnStack[3])
                {
                    this.world.getSphere = new GetSphere();
                    this.world.getSphere.owner = this.world.worldInterface.container.levinSphere;
                    this.world.getSphere.ownerType = "archive";
                    this.world.getSphere.ownerPoint = this.world.worldInterface.container.levinSphere.myPoint;
                    this.world.addChild(this.world.getSphere);
                    this.i = 0;
                    while (this.i < this.myTower.shootingTurnStack[3][3])
                    {
                        
                        (this.i + 1);
                        this.world.getSphere.manage("add", "levin");
                    }
                    this.myTower.spheresManage("get", "levin", this.myTower.shootingTurnStack[3][3]);
                    this.world.getSphere.x = this.myTower.this_pt.x;
                    this.world.getSphere.y = this.myTower.this_pt.y;
                    this.world.getSphere.retrieveGetSphere();
                }
                if (!param2)
                {
                    this.tempObject = this.myTower.myPlace;
                    this.myTower.kill();
                    this.myTower = this.world.addTower("tower7", this.tempObject);
                    this.world.setChildIndex(this.myTower, (this.world.getChildIndex(this) - 1));
                    this.world.money = this.world.money - Main.mainClass.readXMLClass.costUltraIceStone;
                    this.closeMenu();
                }
            }
            else if (param1 == "btnTowerUpgr4")
            {
                if (this.myTower.shootingTurnStack[0])
                {
                    if (this.myTower.shootingTurnStack[0][3] > 1)
                    {
                        this.world.getSphere = new GetSphere();
                        this.world.getSphere.owner = this.world.worldInterface.container.fireSphere;
                        this.world.getSphere.ownerType = "archive";
                        this.world.getSphere.ownerPoint = this.world.worldInterface.container.fireSphere.myPoint;
                        this.world.addChild(this.world.getSphere);
                        this.i = 0;
                        while (this.i < (this.myTower.shootingTurnStack[0][3] - 1))
                        {
                            
                            (this.i + 1);
                            this.world.getSphere.manage("add", "fire");
                        }
                        this.myTower.spheresManage("get", "fire", (this.myTower.shootingTurnStack[0][3] - 1));
                        this.world.getSphere.x = this.myTower.this_pt.x;
                        this.world.getSphere.y = this.myTower.this_pt.y;
                        this.world.getSphere.retrieveGetSphere();
                    }
                }
                if (this.myTower.shootingTurnStack[1])
                {
                    this.world.getSphere = new GetSphere();
                    this.world.getSphere.owner = this.world.worldInterface.container.iceSphere;
                    this.world.getSphere.ownerType = "archive";
                    this.world.getSphere.ownerPoint = this.world.worldInterface.container.iceSphere.myPoint;
                    this.world.addChild(this.world.getSphere);
                    this.i = 0;
                    while (this.i < this.myTower.shootingTurnStack[1][3])
                    {
                        
                        (this.i + 1);
                        this.world.getSphere.manage("add", "ice");
                    }
                    this.myTower.spheresManage("get", "ice", this.myTower.shootingTurnStack[1][3]);
                    this.world.getSphere.x = this.myTower.this_pt.x;
                    this.world.getSphere.y = this.myTower.this_pt.y;
                    this.world.getSphere.retrieveGetSphere();
                }
                if (this.myTower.shootingTurnStack[2])
                {
                    this.world.getSphere = new GetSphere();
                    this.world.getSphere.owner = this.world.worldInterface.container.stoneSphere;
                    this.world.getSphere.ownerType = "archive";
                    this.world.getSphere.ownerPoint = this.world.worldInterface.container.stoneSphere.myPoint;
                    this.world.addChild(this.world.getSphere);
                    this.i = 0;
                    while (this.i < this.myTower.shootingTurnStack[2][3])
                    {
                        
                        (this.i + 1);
                        this.world.getSphere.manage("add", "stone");
                    }
                    this.myTower.spheresManage("get", "stone", this.myTower.shootingTurnStack[2][3]);
                    this.world.getSphere.x = this.myTower.this_pt.x;
                    this.world.getSphere.y = this.myTower.this_pt.y;
                    this.world.getSphere.retrieveGetSphere();
                }
                if (this.myTower.shootingTurnStack[3])
                {
                    if (this.myTower.shootingTurnStack[3][3] > 1)
                    {
                        this.world.getSphere = new GetSphere();
                        this.world.getSphere.owner = this.world.worldInterface.container.levinSphere;
                        this.world.getSphere.ownerType = "archive";
                        this.world.getSphere.ownerPoint = this.world.worldInterface.container.levinSphere.myPoint;
                        this.world.addChild(this.world.getSphere);
                        this.i = 0;
                        while (this.i < (this.myTower.shootingTurnStack[3][3] - 1))
                        {
                            
                            (this.i + 1);
                            this.world.getSphere.manage("add", "levin");
                        }
                        this.myTower.spheresManage("get", "levin", (this.myTower.shootingTurnStack[3][3] - 1));
                        this.world.getSphere.x = this.myTower.this_pt.x;
                        this.world.getSphere.y = this.myTower.this_pt.y;
                        this.world.getSphere.retrieveGetSphere();
                    }
                }
                if (!param2)
                {
                    this.tempObject = this.myTower.myPlace;
                    this.myTower.kill();
                    this.myTower = this.world.addTower("tower8", this.tempObject);
                    this.world.setChildIndex(this.myTower, (this.world.getChildIndex(this) - 1));
                    this.world.money = this.world.money - Main.mainClass.readXMLClass.costUltraFireLevin;
                    this.closeMenu();
                }
            }
            this.world.worldInterface.updateInfo();
            return;
        }// end function

        public function fastBuyUltraManage() : void
        {
            if (this.container.fastBuyUltraCont)
            {
                this.container.fastBuyUltraCont.stop();
                this.container.fastBuyUltraCont.btnFastBuyUltra.stop();
                this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.stop();
                this.container.fastBuyUltraCont.indicator1.stop();
                this.container.fastBuyUltraCont.indicator2.stop();
                this.container.fastBuyUltraCont.indicator3.stop();
                this.container.fastBuyUltraCont.indicator4.stop();
                if (!this.fastBuyUltraFlag && !this.openFastBuyUltraFlag && !this.closeFastBuyUltraFlag)
                {
                    this.container.fastBuyUltraCont.visible = false;
                }
                if (this.fastBuyUltraFlag)
                {
                    this.container.fastBuyUltraCont.btnFastBuyUltra.gotoAndStop(1);
                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(2);
                    this.container.fastBuyUltraCont.indicator2.gotoAndStop(2);
                    this.container.fastBuyUltraCont.indicator3.gotoAndStop(2);
                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(2);
                    this.container.fastBuyUltraCont.indicator1.visible = true;
                    this.container.fastBuyUltraCont.indicator2.visible = true;
                    this.container.fastBuyUltraCont.indicator3.visible = true;
                    this.container.fastBuyUltraCont.indicator4.visible = true;
                    if (!this.fastBuyBlockCost)
                    {
                        this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyUltraScan(this.fastBuyUltraFlag);
                    }
                    else
                    {
                        this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyPrice;
                    }
                    if (this.fastBuyUltraFlag == "btnTowerUpgr1")
                    {
                        this.j = 0;
                        this.i = 0;
                        while (this.i < this.myTower.spheresStack.length)
                        {
                            
                            if (this.myTower.spheresStack[this.i] == "fire")
                            {
                                if (this.i == 0)
                                {
                                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                                }
                                else if (this.i == 1)
                                {
                                    this.container.fastBuyUltraCont.indicator2.gotoAndStop(1);
                                }
                                else if (this.i == 2)
                                {
                                    this.container.fastBuyUltraCont.indicator3.gotoAndStop(1);
                                }
                                else if (this.i == 3)
                                {
                                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                                }
                                (this.j + 1);
                                break;
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                        this.i = 0;
                        while (this.i < this.myTower.spheresStack.length)
                        {
                            
                            if (this.myTower.spheresStack[this.i] == "stone")
                            {
                                if (this.i == 0)
                                {
                                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                                }
                                else if (this.i == 1)
                                {
                                    this.container.fastBuyUltraCont.indicator2.gotoAndStop(1);
                                }
                                else if (this.i == 2)
                                {
                                    this.container.fastBuyUltraCont.indicator3.gotoAndStop(1);
                                }
                                else if (this.i == 3)
                                {
                                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                                }
                                (this.j + 1);
                                break;
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                        if (this.j < 2 && this.world.money >= int(this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text))
                        {
                            this.i = 0;
                            while (this.i < this.myTower.spheresStack.length)
                            {
                                
                                if (this.myTower.spheresStack[this.i] != "fire" && this.myTower.spheresStack[this.i] != "stone")
                                {
                                    (this.j - 1);
                                    if (this.i == 0)
                                    {
                                        this.container.fastBuyUltraCont.indicator1.gotoAndStop(3);
                                    }
                                    else if (this.i == 1)
                                    {
                                        this.container.fastBuyUltraCont.indicator2.gotoAndStop(3);
                                    }
                                    else if (this.i == 2)
                                    {
                                        this.container.fastBuyUltraCont.indicator3.gotoAndStop(3);
                                    }
                                    else if (this.i == 3)
                                    {
                                        this.container.fastBuyUltraCont.indicator4.gotoAndStop(3);
                                    }
                                    if (this.j == 0)
                                    {
                                        break;
                                    }
                                }
                                var _loc_1:* = this;
                                var _loc_2:* = this.i + 1;
                                _loc_1.i = _loc_2;
                            }
                        }
                    }
                    else if (this.fastBuyUltraFlag == "btnTowerUpgr2")
                    {
                        this.j = 0;
                        this.i = 0;
                        while (this.i < this.myTower.spheresStack.length)
                        {
                            
                            if (this.myTower.spheresStack[this.i] == "ice")
                            {
                                if (this.i == 0)
                                {
                                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                                }
                                else if (this.i == 1)
                                {
                                    this.container.fastBuyUltraCont.indicator2.gotoAndStop(1);
                                }
                                else if (this.i == 2)
                                {
                                    this.container.fastBuyUltraCont.indicator3.gotoAndStop(1);
                                }
                                else if (this.i == 3)
                                {
                                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                                }
                                (this.j + 1);
                                break;
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                        this.i = 0;
                        while (this.i < this.myTower.spheresStack.length)
                        {
                            
                            if (this.myTower.spheresStack[this.i] == "levin")
                            {
                                if (this.i == 0)
                                {
                                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                                }
                                else if (this.i == 1)
                                {
                                    this.container.fastBuyUltraCont.indicator2.gotoAndStop(1);
                                }
                                else if (this.i == 2)
                                {
                                    this.container.fastBuyUltraCont.indicator3.gotoAndStop(1);
                                }
                                else if (this.i == 3)
                                {
                                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                                }
                                (this.j + 1);
                                break;
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                        if (this.j < 2 && this.world.money >= int(this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text))
                        {
                            this.i = 0;
                            while (this.i < this.myTower.spheresStack.length)
                            {
                                
                                if (this.myTower.spheresStack[this.i] != "ice" && this.myTower.spheresStack[this.i] != "levin")
                                {
                                    (this.j - 1);
                                    if (this.i == 0)
                                    {
                                        this.container.fastBuyUltraCont.indicator1.gotoAndStop(3);
                                    }
                                    else if (this.i == 1)
                                    {
                                        this.container.fastBuyUltraCont.indicator2.gotoAndStop(3);
                                    }
                                    else if (this.i == 2)
                                    {
                                        this.container.fastBuyUltraCont.indicator3.gotoAndStop(3);
                                    }
                                    else if (this.i == 3)
                                    {
                                        this.container.fastBuyUltraCont.indicator4.gotoAndStop(3);
                                    }
                                    if (this.j == 0)
                                    {
                                        break;
                                    }
                                }
                                var _loc_1:* = this;
                                var _loc_2:* = this.i + 1;
                                _loc_1.i = _loc_2;
                            }
                        }
                    }
                    else if (this.fastBuyUltraFlag == "btnTowerUpgr3")
                    {
                        this.j = 0;
                        this.i = 0;
                        while (this.i < this.myTower.spheresStack.length)
                        {
                            
                            if (this.myTower.spheresStack[this.i] == "ice")
                            {
                                if (this.i == 0)
                                {
                                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                                }
                                else if (this.i == 1)
                                {
                                    this.container.fastBuyUltraCont.indicator2.gotoAndStop(1);
                                }
                                else if (this.i == 2)
                                {
                                    this.container.fastBuyUltraCont.indicator3.gotoAndStop(1);
                                }
                                else if (this.i == 3)
                                {
                                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                                }
                                (this.j + 1);
                                break;
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                        this.i = 0;
                        while (this.i < this.myTower.spheresStack.length)
                        {
                            
                            if (this.myTower.spheresStack[this.i] == "stone")
                            {
                                if (this.i == 0)
                                {
                                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                                }
                                else if (this.i == 1)
                                {
                                    this.container.fastBuyUltraCont.indicator2.gotoAndStop(1);
                                }
                                else if (this.i == 2)
                                {
                                    this.container.fastBuyUltraCont.indicator3.gotoAndStop(1);
                                }
                                else if (this.i == 3)
                                {
                                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                                }
                                (this.j + 1);
                                break;
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                        if (this.j < 2 && this.world.money >= int(this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text))
                        {
                            this.i = 0;
                            while (this.i < this.myTower.spheresStack.length)
                            {
                                
                                if (this.myTower.spheresStack[this.i] != "ice" && this.myTower.spheresStack[this.i] != "stone")
                                {
                                    (this.j - 1);
                                    if (this.i == 0)
                                    {
                                        this.container.fastBuyUltraCont.indicator1.gotoAndStop(3);
                                    }
                                    else if (this.i == 1)
                                    {
                                        this.container.fastBuyUltraCont.indicator2.gotoAndStop(3);
                                    }
                                    else if (this.i == 2)
                                    {
                                        this.container.fastBuyUltraCont.indicator3.gotoAndStop(3);
                                    }
                                    else if (this.i == 3)
                                    {
                                        this.container.fastBuyUltraCont.indicator4.gotoAndStop(3);
                                    }
                                    if (this.j == 0)
                                    {
                                        break;
                                    }
                                }
                                var _loc_1:* = this;
                                var _loc_2:* = this.i + 1;
                                _loc_1.i = _loc_2;
                            }
                        }
                    }
                    else if (this.fastBuyUltraFlag == "btnTowerUpgr4")
                    {
                        this.j = 0;
                        this.i = 0;
                        while (this.i < this.myTower.spheresStack.length)
                        {
                            
                            if (this.myTower.spheresStack[this.i] == "fire")
                            {
                                if (this.i == 0)
                                {
                                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                                }
                                else if (this.i == 1)
                                {
                                    this.container.fastBuyUltraCont.indicator2.gotoAndStop(1);
                                }
                                else if (this.i == 2)
                                {
                                    this.container.fastBuyUltraCont.indicator3.gotoAndStop(1);
                                }
                                else if (this.i == 3)
                                {
                                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                                }
                                (this.j + 1);
                                break;
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                        this.i = 0;
                        while (this.i < this.myTower.spheresStack.length)
                        {
                            
                            if (this.myTower.spheresStack[this.i] == "levin")
                            {
                                if (this.i == 0)
                                {
                                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                                }
                                else if (this.i == 1)
                                {
                                    this.container.fastBuyUltraCont.indicator2.gotoAndStop(1);
                                }
                                else if (this.i == 2)
                                {
                                    this.container.fastBuyUltraCont.indicator3.gotoAndStop(1);
                                }
                                else if (this.i == 3)
                                {
                                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                                }
                                (this.j + 1);
                                break;
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                        if (this.j < 2 && this.world.money >= int(this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text))
                        {
                            this.i = 0;
                            while (this.i < this.myTower.spheresStack.length)
                            {
                                
                                if (this.myTower.spheresStack[this.i] != "fire" && this.myTower.spheresStack[this.i] != "levin")
                                {
                                    (this.j - 1);
                                    if (this.i == 0)
                                    {
                                        this.container.fastBuyUltraCont.indicator1.gotoAndStop(3);
                                    }
                                    else if (this.i == 1)
                                    {
                                        this.container.fastBuyUltraCont.indicator2.gotoAndStop(3);
                                    }
                                    else if (this.i == 2)
                                    {
                                        this.container.fastBuyUltraCont.indicator3.gotoAndStop(3);
                                    }
                                    else if (this.i == 3)
                                    {
                                        this.container.fastBuyUltraCont.indicator4.gotoAndStop(3);
                                    }
                                    if (this.j == 0)
                                    {
                                        break;
                                    }
                                }
                                var _loc_1:* = this;
                                var _loc_2:* = this.i + 1;
                                _loc_1.i = _loc_2;
                            }
                        }
                    }
                    this.fastBuyPrice = int(this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text);
                    if (this.world.money >= int(this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text))
                    {
                        this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.buttonMode = true;
                    }
                    else
                    {
                        this.container.fastBuyUltraCont.btnFastBuyUltra.gotoAndStop(4);
                        this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyPrice;
                        this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.buttonMode = false;
                    }
                }
            }
            return;
        }// end function

        public function fastBuyUltraScan(param1:String) : int
        {
            if (param1 == "btnTowerUpgr1")
            {
                this.tempObject1 = Main.mainClass.readXMLClass.costUltraFireStone;
                if (!this.myTower.shootingTurnStack[0])
                {
                    if (this.world.worldInterface.fireCount == 0)
                    {
                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfFirePriceXML[this.world.worldInterface.fireBuyHistory];
                    }
                }
                if (!this.myTower.shootingTurnStack[2])
                {
                    if (this.world.worldInterface.stoneCount == 0)
                    {
                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfStonePriceXML[this.world.worldInterface.stoneBuyHistory];
                    }
                }
            }
            else if (param1 == "btnTowerUpgr2")
            {
                this.tempObject1 = Main.mainClass.readXMLClass.costUltraIceLevin;
                if (!this.myTower.shootingTurnStack[1])
                {
                    if (this.world.worldInterface.iceCount == 0)
                    {
                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfIcePriceXML[this.world.worldInterface.iceBuyHistory];
                    }
                }
                if (!this.myTower.shootingTurnStack[3])
                {
                    if (this.world.worldInterface.levinCount == 0)
                    {
                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfLevinPriceXML[this.world.worldInterface.levinBuyHistory];
                    }
                }
            }
            else if (param1 == "btnTowerUpgr3")
            {
                this.tempObject1 = Main.mainClass.readXMLClass.costUltraIceStone;
                if (!this.myTower.shootingTurnStack[1])
                {
                    if (this.world.worldInterface.iceCount == 0)
                    {
                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfIcePriceXML[this.world.worldInterface.iceBuyHistory];
                    }
                }
                if (!this.myTower.shootingTurnStack[2])
                {
                    if (this.world.worldInterface.stoneCount == 0)
                    {
                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfStonePriceXML[this.world.worldInterface.stoneBuyHistory];
                    }
                }
            }
            else if (param1 == "btnTowerUpgr4")
            {
                this.tempObject1 = Main.mainClass.readXMLClass.costUltraFireLevin;
                if (!this.myTower.shootingTurnStack[0])
                {
                    if (this.world.worldInterface.fireCount == 0)
                    {
                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfFirePriceXML[this.world.worldInterface.fireBuyHistory];
                    }
                }
                if (!this.myTower.shootingTurnStack[3])
                {
                    if (this.world.worldInterface.levinCount == 0)
                    {
                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfLevinPriceXML[this.world.worldInterface.levinBuyHistory];
                    }
                }
            }
            return this.tempObject1;
        }// end function

        public function closeMenu(param1:Boolean = false) : void
        {
            if (!this.readyFastBuyUltraFlag)
            {
                if (this.exampleUltraTower)
                {
                    this.exampleUltraManage("remove");
                }
                var _loc_2:* = false;
                this.mouseChildren = false;
                this.mouseEnabled = _loc_2;
                this.closeFlag = true;
                this.towerRadius.visible = false;
                if (this.myTower.towerType < 5)
                {
                    this.myTower.container.selectTower.visible = false;
                }
                this.world.towerMenu = null;
                if (!this.myTower.blockTowerFlag)
                {
                    var _loc_2:* = true;
                    this.myTower.mouseChildren = true;
                    this.myTower.mouseEnabled = _loc_2;
                }
                this.world.worldInterface.archiveSphereBacklightManage("");
                if (this.hint)
                {
                    this.world.removeChild(this.hint);
                }
                this.world.worldInterface.updateInfo();
                if (!this.world.getSphere && !this.world.cast)
                {
                    this.world.worldInterface.barInfoManage();
                }
                if (!param1)
                {
                    this.world.listOfIndexes3.push(this);
                }
                else
                {
                    this.kill();
                }
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.worldInterface.updateInfo();
                this.world.removeChild(this.towerRadius);
                this.towerRadius = null;
                this.world.removeChild(this.towerRadius1);
                this.towerRadius1 = null;
                this.world.removeChild(this);
                this.i = 0;
                while (this.i < this.world.listOfClasses.length)
                {
                    
                    if (this.world.listOfClasses[this.i] == this)
                    {
                        this.world.listOfClasses.splice(this.i, 1);
                        break;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
                this.i = 0;
                while (this.i < this.world.listOfIndexes3.length)
                {
                    
                    if (this.world.listOfIndexes3[this.i] == this)
                    {
                        this.world.listOfIndexes3.splice(this.i, 1);
                        break;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
                if (this.lastE)
                {
                    this.world.mouseMoveHandler(this.lastE);
                }
            }
            return;
        }// end function

    }
}
