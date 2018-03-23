package engine.towers
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class UltraTowerMenu extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:UltraTowerMenu_mc;
        public var myTower:Tower;
        public var dead:Boolean;
        public var world:World;
        public var closeFlag:Boolean;
        public var openFlag:Boolean = true;
        public var towerRadius:MovieClip;
        public var lastE:MouseEvent;
        public var sellTax:Number = 0.4;
        public var fastBuyUltraFlag:String;
        public var openFastBuyUltraFlag:Boolean;
        public var closeFastBuyUltraFlag:Boolean;
        public var readyFastBuyUltraFlag:Boolean;
        public var fastBuyPrice:int = 0;
        public var fastBuyBlockCost:Boolean;
        public var hint:UltraTowerMenuHint_mc;
        public var autoguidesMouse_pt:Point;
        public var autoguidesObject:Object;
        public var autoguidesObject_pt:Point;
        public var autoguidesObjectWidth:Number;
        public var autoguidesObjectHeight:Number;

        public function UltraTowerMenu(param1:Tower)
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
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            this.x = this.myTower.this_pt.x;
            this.y = this.myTower.this_pt.y;
            this.towerRadius = new TowerRadius_mc();
            this.towerRadius.stop();
            this.towerRadius.width = this.myTower.radius * 2;
            this.towerRadius.height = this.myTower.radius * 2 * this.world.scaleRadius;
            var _loc_2:* = false;
            this.towerRadius.mouseChildren = false;
            this.towerRadius.mouseEnabled = _loc_2;
            this.addChild(this.towerRadius);
            this.container = new UltraTowerMenu_mc();
            this.container.stop();
            this.container.btnUpgradeMenu.stop();
            this.container.sphereSlot1.stop();
            this.container.sphereSlot2.stop();
            this.container.sphereSlot1.sphereAnima.stop();
            this.container.sphereSlot2.sphereAnima.stop();
            this.container.sphereSlot1.sphereAnima.fire.stop();
            this.container.sphereSlot2.sphereAnima.fire.stop();
            this.container.sellUltraTower.stop();
            this.container.sellUltraTower.sellUltraTowerCase.stop();
            this.container.sellUltraTower.sellUltraTowerCase.buttonMode = true;
            this.addChild(this.container);
            this.world.listOfClasses.push(this);
            if (this.myTower.upgradeTypeAdd == 1)
            {
                this.container.sphereSlot1.visible = false;
                this.container.sphereSlot2.visible = false;
            }
            this.fastBuyUltraManage();
            var _loc_2:* = false;
            this.myTower.mouseChildren = false;
            this.myTower.mouseEnabled = _loc_2;
            this.world.worldInterface.barInfoManage(this);
            if (!this.hint)
            {
                this.hint = new UltraTowerMenuHint_mc();
                this.hint.stop();
                var _loc_2:* = false;
                this.hint.mouseChildren = false;
                this.hint.mouseEnabled = _loc_2;
                this.hint.visible = false;
                this.world.addChild(this.hint);
            }
            this.world.worldInterface.updateInfo();
            return;
        }// end function

        public function update() : void
        {
            if (this.closeFlag)
            {
                this.kill();
            }
            else if (this.openFlag)
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
                }
            }
            else
            {
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
                if (Point.distance(this.myTower.this_pt, new Point(this.world.mouseX, this.world.mouseY)) > 75)
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
                else if (this.fastBuyUltraFlag == "upgrade")
                {
                    Sounds.instance.playSoundWithVol("snd_tower_build1", 0.9);
                    this.container.btnUpgradeMenu.costTXT.visible = false;
                    (this.myTower.upgradeTypeAdd + 1);
                    if (!this.myTower.enemyTarget)
                    {
                        this.myTower.addBuildAnima();
                    }
                    this.closeMenu();
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (param1.target.name == "btnUpgradeMenuCase")
            {
                if (this.container.btnUpgradeMenu.currentFrame == 1)
                {
                    this.container.btnUpgradeMenu.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
                if (!this.hint.visible && !this.openFlag && !this.closeFlag)
                {
                    this.hint.visible = true;
                    if (this.myTower.towerType == 5)
                    {
                        this.hintPosition(1);
                    }
                    else if (this.myTower.towerType == 6)
                    {
                        this.hintPosition(5);
                    }
                    else if (this.myTower.towerType == 7)
                    {
                        this.hintPosition(9);
                    }
                    else if (this.myTower.towerType == 8)
                    {
                        this.hintPosition(13);
                    }
                }
            }
            else
            {
                if (this.container.btnUpgradeMenu.currentFrame == 2)
                {
                    this.container.btnUpgradeMenu.gotoAndStop(1);
                }
                if (param1.target.name == "btnUpgradeMenuBLOCKCase")
                {
                    if (!this.hint.visible && !this.openFlag && !this.closeFlag)
                    {
                        this.hint.visible = true;
                        if (this.myTower.towerType == 5)
                        {
                            this.hintPosition(1);
                        }
                        else if (this.myTower.towerType == 6)
                        {
                            this.hintPosition(5);
                        }
                        else if (this.myTower.towerType == 7)
                        {
                            this.hintPosition(9);
                        }
                        else if (this.myTower.towerType == 8)
                        {
                            this.hintPosition(13);
                        }
                    }
                }
                else if (param1.target.name == "btnUpgradeMenuLOCKCase")
                {
                    if (!this.hint.visible && !this.openFlag && !this.closeFlag)
                    {
                        this.hint.visible = true;
                        this.hintPosition(21);
                    }
                }
                else if (this.hint.visible)
                {
                    this.hint.visible = false;
                }
            }
            if (param1.target.name == "btnUpgradeMenuCase" || param1.target.name == "btnUpgradeMenuBLOCKCase" || param1.target.name == "fastBuyUltraCase")
            {
                if (this.myTower.towerType == 5)
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
                }
                else if (this.myTower.towerType == 6)
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
                }
                else if (this.myTower.towerType == 7)
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
                }
                else if (this.myTower.towerType == 8)
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
                }
            }
            else if (param1.target.name != "sphereSlotCase")
            {
                if (this.world.worldInterface.container.fireBacklight.visible || this.world.worldInterface.container.iceBacklight.visible || this.world.worldInterface.container.stoneBacklight.visible || this.world.worldInterface.container.levinBacklight.visible)
                {
                    this.world.worldInterface.archiveSphereBacklightManage("");
                }
            }
            if (param1.target.name == "sphereSlotCase")
            {
                this.tempObject = param1.target.parent;
                if (this.tempObject.sphereAnima.visible)
                {
                    if (param1.target.parent.name == "sphereSlot1")
                    {
                        if (this.container.sphereSlot2.currentFrame == 2)
                        {
                            this.container.sphereSlot2.gotoAndStop(1);
                        }
                    }
                    else if (param1.target.parent.name == "sphereSlot2")
                    {
                        if (this.container.sphereSlot1.currentFrame == 2)
                        {
                            this.container.sphereSlot1.gotoAndStop(1);
                        }
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
            }
            if (param1.target.name == "sellUltraTowerCase")
            {
                if (this.container.sellUltraTower.currentFrame == 1)
                {
                    this.container.sellUltraTower.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.sellUltraTower.currentFrame == 2)
            {
                this.container.sellUltraTower.gotoAndStop(1);
            }
            if (!this.openFastBuyUltraFlag && !this.closeFastBuyUltraFlag)
            {
                if (param1.target.name == "fastBuyUltraCase" && this.container.fastBuyUltraCont.btnFastBuyUltra.fastBuyUltraCase.buttonMode)
                {
                    if (this.container.fastBuyUltraCont.btnFastBuyUltra.currentFrame == 1)
                    {
                        this.container.fastBuyUltraCont.btnFastBuyUltra.gotoAndStop(2);
                        this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyPrice;
                        if (this.fastBuyUltraFlag == "upgrade")
                        {
                            if (this.myTower.towerType == 5)
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
                            }
                            else if (this.myTower.towerType == 6)
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
                            }
                            else if (this.myTower.towerType == 7)
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
                            }
                            else if (this.myTower.towerType == 8)
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
                            }
                        }
                        Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this.container.fastBuyUltraCont.btnFastBuyUltra.currentFrame == 2)
                {
                    this.container.fastBuyUltraCont.btnFastBuyUltra.gotoAndStop(1);
                    this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyPrice;
                    if (this.world.worldInterface.container.fireBacklight.visible || this.world.worldInterface.container.iceBacklight.visible || this.world.worldInterface.container.stoneBacklight.visible || this.world.worldInterface.container.levinBacklight.visible)
                    {
                        this.world.worldInterface.archiveSphereBacklightManage("");
                    }
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
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "sphereSlotCase")
            {
                this.tempObject = event.target.parent;
                if (this.tempObject.currentFrame < 4)
                {
                    if (this.tempObject.sphereAnima.currentFrame == 1)
                    {
                        this.myTower.towerGetSphereManage("get", "fire");
                    }
                    else if (this.tempObject.sphereAnima.currentFrame == 2)
                    {
                        this.myTower.towerGetSphereManage("get", "ice");
                    }
                    else if (this.tempObject.sphereAnima.currentFrame == 3)
                    {
                        this.myTower.towerGetSphereManage("get", "stone");
                    }
                    else if (this.tempObject.sphereAnima.currentFrame == 4)
                    {
                        this.myTower.towerGetSphereManage("get", "levin");
                    }
                    if (!this.world.getSphere)
                    {
                        if (this.tempObject.name == "sphereSlot1")
                        {
                            if (this.myTower.towerType == 5)
                            {
                                if (this.world.worldInterface.container.fireSphere.alpha == 1 && this.world.worldInterface.container.fireSphere.visible)
                                {
                                    this.world.worldInterface.container.fireBacklight.turnFlag = false;
                                    this.world.worldInterface.container.fireBacklight.gotoAndStop(2);
                                    this.world.worldInterface.container.fireBacklight.visible = true;
                                }
                            }
                            else if (this.myTower.towerType == 6)
                            {
                                if (this.world.worldInterface.container.iceSphere.alpha == 1 && this.world.worldInterface.container.iceSphere.visible)
                                {
                                    this.world.worldInterface.container.iceBacklight.turnFlag = false;
                                    this.world.worldInterface.container.iceBacklight.gotoAndStop(2);
                                    this.world.worldInterface.container.iceBacklight.visible = true;
                                }
                            }
                            else if (this.myTower.towerType == 7)
                            {
                                if (this.world.worldInterface.container.iceSphere.alpha == 1 && this.world.worldInterface.container.iceSphere.visible)
                                {
                                    this.world.worldInterface.container.iceBacklight.turnFlag = false;
                                    this.world.worldInterface.container.iceBacklight.gotoAndStop(2);
                                    this.world.worldInterface.container.iceBacklight.visible = true;
                                }
                            }
                            else if (this.myTower.towerType == 8)
                            {
                                if (this.world.worldInterface.container.fireSphere.alpha == 1 && this.world.worldInterface.container.fireSphere.visible)
                                {
                                    this.world.worldInterface.container.fireBacklight.turnFlag = false;
                                    this.world.worldInterface.container.fireBacklight.gotoAndStop(2);
                                    this.world.worldInterface.container.fireBacklight.visible = true;
                                }
                            }
                        }
                        else if (this.tempObject.name == "sphereSlot2")
                        {
                            if (this.myTower.towerType == 5)
                            {
                                if (this.world.worldInterface.container.stoneSphere.alpha == 1 && this.world.worldInterface.container.stoneSphere.visible)
                                {
                                    this.world.worldInterface.container.stoneBacklight.turnFlag = false;
                                    this.world.worldInterface.container.stoneBacklight.gotoAndStop(2);
                                    this.world.worldInterface.container.stoneBacklight.visible = true;
                                }
                            }
                            else if (this.myTower.towerType == 6)
                            {
                                if (this.world.worldInterface.container.levinSphere.alpha == 1 && this.world.worldInterface.container.levinSphere.visible)
                                {
                                    this.world.worldInterface.container.levinBacklight.turnFlag = false;
                                    this.world.worldInterface.container.levinBacklight.gotoAndStop(2);
                                    this.world.worldInterface.container.levinBacklight.visible = true;
                                }
                            }
                            else if (this.myTower.towerType == 7)
                            {
                                if (this.world.worldInterface.container.stoneSphere.alpha == 1 && this.world.worldInterface.container.stoneSphere.visible)
                                {
                                    this.world.worldInterface.container.stoneBacklight.turnFlag = false;
                                    this.world.worldInterface.container.stoneBacklight.gotoAndStop(2);
                                    this.world.worldInterface.container.stoneBacklight.visible = true;
                                }
                            }
                            else if (this.myTower.towerType == 8)
                            {
                                if (this.world.worldInterface.container.levinSphere.alpha == 1 && this.world.worldInterface.container.levinSphere.visible)
                                {
                                    this.world.worldInterface.container.levinBacklight.turnFlag = false;
                                    this.world.worldInterface.container.levinBacklight.gotoAndStop(2);
                                    this.world.worldInterface.container.levinBacklight.visible = true;
                                }
                            }
                        }
                    }
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event.target.name == "sellUltraTowerCase")
            {
                if (this.container.sellUltraTower.currentFrame == 2)
                {
                    this.container.sellUltraTower.gotoAndStop(3);
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
                        var _loc_2:* = false;
                        this.myTower.mouseChildren = false;
                        this.myTower.mouseEnabled = _loc_2;
                        this.readyFastBuyUltraFlag = true;
                        if (this.myTower.towerType == 5)
                        {
                            this.world.money = this.world.money - Main.mainClass.readXMLClass.costUltraAddFireStone;
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
                        else if (this.myTower.towerType == 6)
                        {
                            this.world.money = this.world.money - Main.mainClass.readXMLClass.costUltraAddIceLevin;
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
                        else if (this.myTower.towerType == 7)
                        {
                            this.world.money = this.world.money - Main.mainClass.readXMLClass.costUltraAddIceStone;
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
                        else if (this.myTower.towerType == 8)
                        {
                            this.world.money = this.world.money - Main.mainClass.readXMLClass.costUltraAddFireLevin;
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
                        this.world.worldInterface.updateInfo();
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            else if (event.target.name != "buySphereCase" && event.target.name != "sphereCase" && event.target.name != "btnUpgradeMenuBLOCKCase" && event.target.parent != this.container && event.target.parent.parent != this.container)
            {
                this.lastE = event;
                this.closeMenu();
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (event.target.name == "btnUpgradeMenuCase")
            {
                if (this.container.btnUpgradeMenu.currentFrame == 3)
                {
                    this.container.btnUpgradeMenu.gotoAndStop(4);
                    if (this.myTower.towerType == 5)
                    {
                        this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costUltraAddFireStone;
                    }
                    else if (this.myTower.towerType == 6)
                    {
                        this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costUltraAddIceLevin;
                    }
                    else if (this.myTower.towerType == 7)
                    {
                        this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costUltraAddIceStone;
                    }
                    else if (this.myTower.towerType == 8)
                    {
                        this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costUltraAddFireLevin;
                    }
                    if (!this.fastBuyUltraFlag)
                    {
                        this.fastBuyUltraFlag = "upgrade";
                        this.openFastBuyUltraFlag = true;
                        this.fastBuyUltraManage();
                    }
                    else if (event.target.parent.name == this.fastBuyUltraFlag)
                    {
                        this.fastBuyUltraFlag = null;
                        this.closeFastBuyUltraFlag = true;
                        this.mouseMoveHandler(event);
                    }
                }
            }
            else if (this.container.btnUpgradeMenu.currentFrame == 3)
            {
                this.container.btnUpgradeMenu.gotoAndStop(1);
            }
            if (event.target.name == "sellUltraTowerCase")
            {
                if (this.container.sellUltraTower.currentFrame == 3)
                {
                    this.container.sellUltraTower.gotoAndStop(2);
                    if (this.myTower.towerType == 5)
                    {
                        this.tempObject = Math.round(Main.mainClass.readXMLClass.costUltraFireStone - Main.mainClass.readXMLClass.costUltraFireStone * this.sellTax);
                        if (this.myTower.upgradeTypeAdd == 0)
                        {
                            if (this.myTower.shootingTurnStack[0])
                            {
                                this.world.getSphere = new GetSphere();
                                this.world.getSphere.owner = this.world.worldInterface.container.fireSphere;
                                this.world.getSphere.ownerType = "archive";
                                this.world.getSphere.ownerPoint = this.world.worldInterface.container.fireSphere.myPoint;
                                this.world.addChild(this.world.getSphere);
                                this.myTower.spheresManage("get", "fire", 1);
                                this.world.getSphere.manage("add", "fire");
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
                                this.myTower.spheresManage("get", "stone", 1);
                                this.world.getSphere.manage("add", "stone");
                                this.world.getSphere.x = this.myTower.this_pt.x;
                                this.world.getSphere.y = this.myTower.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                        }
                        else if (this.myTower.upgradeTypeAdd == 1)
                        {
                            this.tempObject = this.tempObject + Math.round(Main.mainClass.readXMLClass.costUltraAddFireStone - Main.mainClass.readXMLClass.costUltraAddFireStone * this.sellTax);
                            this.world.worldInterface.sellSphere("fire");
                            this.world.worldInterface.sellSphere("stone");
                        }
                    }
                    else if (this.myTower.towerType == 6)
                    {
                        this.tempObject = Math.round(Main.mainClass.readXMLClass.costUltraIceLevin - Main.mainClass.readXMLClass.costUltraIceLevin * this.sellTax);
                        if (this.myTower.upgradeTypeAdd == 0)
                        {
                            if (this.myTower.shootingTurnStack[1])
                            {
                                this.world.getSphere = new GetSphere();
                                this.world.getSphere.owner = this.world.worldInterface.container.iceSphere;
                                this.world.getSphere.ownerType = "archive";
                                this.world.getSphere.ownerPoint = this.world.worldInterface.container.iceSphere.myPoint;
                                this.world.addChild(this.world.getSphere);
                                this.myTower.spheresManage("get", "ice", 1);
                                this.world.getSphere.manage("add", "ice");
                                this.world.getSphere.x = this.myTower.this_pt.x;
                                this.world.getSphere.y = this.myTower.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            if (this.myTower.shootingTurnStack[3])
                            {
                                this.world.getSphere = new GetSphere();
                                this.world.getSphere.owner = this.world.worldInterface.container.levinSphere;
                                this.world.getSphere.ownerType = "archive";
                                this.world.getSphere.ownerPoint = this.world.worldInterface.container.levinSphere.myPoint;
                                this.world.addChild(this.world.getSphere);
                                this.myTower.spheresManage("get", "levin", 1);
                                this.world.getSphere.manage("add", "levin");
                                this.world.getSphere.x = this.myTower.this_pt.x;
                                this.world.getSphere.y = this.myTower.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                        }
                        else if (this.myTower.upgradeTypeAdd == 1)
                        {
                            this.tempObject = this.tempObject + Math.round(Main.mainClass.readXMLClass.costUltraAddIceLevin - Main.mainClass.readXMLClass.costUltraAddIceLevin * this.sellTax);
                            this.world.worldInterface.sellSphere("ice");
                            this.world.worldInterface.sellSphere("levin");
                        }
                    }
                    else if (this.myTower.towerType == 7)
                    {
                        this.tempObject = Math.round(Main.mainClass.readXMLClass.costUltraIceStone - Main.mainClass.readXMLClass.costUltraIceStone * this.sellTax);
                        if (this.myTower.upgradeTypeAdd == 0)
                        {
                            if (this.myTower.shootingTurnStack[1])
                            {
                                this.world.getSphere = new GetSphere();
                                this.world.getSphere.owner = this.world.worldInterface.container.iceSphere;
                                this.world.getSphere.ownerType = "archive";
                                this.world.getSphere.ownerPoint = this.world.worldInterface.container.iceSphere.myPoint;
                                this.world.addChild(this.world.getSphere);
                                this.myTower.spheresManage("get", "ice", 1);
                                this.world.getSphere.manage("add", "ice");
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
                                this.myTower.spheresManage("get", "stone", 1);
                                this.world.getSphere.manage("add", "stone");
                                this.world.getSphere.x = this.myTower.this_pt.x;
                                this.world.getSphere.y = this.myTower.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                        }
                        else if (this.myTower.upgradeTypeAdd == 1)
                        {
                            this.tempObject = this.tempObject + Math.round(Main.mainClass.readXMLClass.costUltraAddIceStone - Main.mainClass.readXMLClass.costUltraAddIceStone * this.sellTax);
                            this.world.worldInterface.sellSphere("ice");
                            this.world.worldInterface.sellSphere("stone");
                        }
                    }
                    else if (this.myTower.towerType == 8)
                    {
                        this.tempObject = Math.round(Main.mainClass.readXMLClass.costUltraFireLevin - Main.mainClass.readXMLClass.costUltraFireLevin * this.sellTax);
                        if (this.myTower.upgradeTypeAdd == 0)
                        {
                            if (this.myTower.shootingTurnStack[0])
                            {
                                this.world.getSphere = new GetSphere();
                                this.world.getSphere.owner = this.world.worldInterface.container.fireSphere;
                                this.world.getSphere.ownerType = "archive";
                                this.world.getSphere.ownerPoint = this.world.worldInterface.container.fireSphere.myPoint;
                                this.world.addChild(this.world.getSphere);
                                this.myTower.spheresManage("get", "fire", 1);
                                this.world.getSphere.manage("add", "fire");
                                this.world.getSphere.x = this.myTower.this_pt.x;
                                this.world.getSphere.y = this.myTower.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            if (this.myTower.shootingTurnStack[3])
                            {
                                this.world.getSphere = new GetSphere();
                                this.world.getSphere.owner = this.world.worldInterface.container.levinSphere;
                                this.world.getSphere.ownerType = "archive";
                                this.world.getSphere.ownerPoint = this.world.worldInterface.container.levinSphere.myPoint;
                                this.world.addChild(this.world.getSphere);
                                this.myTower.spheresManage("get", "levin", 1);
                                this.world.getSphere.manage("add", "levin");
                                this.world.getSphere.x = this.myTower.this_pt.x;
                                this.world.getSphere.y = this.myTower.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                        }
                        else if (this.myTower.upgradeTypeAdd == 1)
                        {
                            this.tempObject = this.tempObject + Math.round(Main.mainClass.readXMLClass.costUltraAddFireLevin - Main.mainClass.readXMLClass.costUltraAddFireLevin * this.sellTax);
                            this.world.worldInterface.sellSphere("fire");
                            this.world.worldInterface.sellSphere("levin");
                        }
                    }
                    this.world.money = this.world.money + this.tempObject;
                    this.world.worldInterface.updateInfo();
                    this.closeMenu();
                    this.myTower.myPlace.gotoAndStop(1);
                    this.myTower.myPlace.buildPoint.stop();
                    this.myTower.myPlace.placeForBuildCase.buttonMode = true;
                    this.myTower.kill();
                    Sounds.instance.playSound("snd_tower_sell");
                }
            }
            else if (this.container.sellUltraTower.currentFrame == 3)
            {
                this.container.sellUltraTower.gotoAndStop(1);
            }
            return;
        }// end function

        public function monitor() : void
        {
            if (this.myTower.towerType == 5)
            {
                if (Main.mainClass.readXMLClass.ultraTower1UpgrBlock == 0)
                {
                    this.container.sphereSlot1.gotoAndStop(1);
                    this.container.sphereSlot2.gotoAndStop(1);
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(1);
                    this.container.sphereSlot1.sphereAnima.fire.stop();
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(3);
                    this.container.sphereSlot2.sphereAnima.stone.stop();
                    if (!this.myTower.shootingTurnStack[0])
                    {
                        this.container.sphereSlot1.sphereAnima.visible = false;
                        this.container.sphereSlot1.sphereSlotCase.buttonMode = false;
                    }
                    else
                    {
                        this.container.sphereSlot1.sphereAnima.visible = true;
                        this.container.sphereSlot1.sphereSlotCase.buttonMode = true;
                    }
                    if (!this.myTower.shootingTurnStack[2])
                    {
                        this.container.sphereSlot2.sphereAnima.visible = false;
                        this.container.sphereSlot2.sphereSlotCase.buttonMode = false;
                    }
                    else
                    {
                        this.container.sphereSlot2.sphereAnima.visible = true;
                        this.container.sphereSlot2.sphereSlotCase.buttonMode = true;
                    }
                    if (this.myTower.upgradeTypeAdd == 1)
                    {
                        this.container.btnUpgradeMenu.visible = false;
                    }
                    else if (this.world.money >= Main.mainClass.readXMLClass.costUltraAddFireStone && !this.fastBuyUltraFlag)
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(1);
                        this.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode = true;
                    }
                    else
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(4);
                    }
                    if (!this.fastBuyUltraFlag)
                    {
                        this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costUltraAddFireStone;
                    }
                }
                else
                {
                    this.container.btnUpgradeMenu.gotoAndStop(5);
                    this.container.sphereSlot1.gotoAndStop(4);
                    this.container.sphereSlot2.gotoAndStop(4);
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(1);
                    this.container.sphereSlot1.sphereAnima.fire.stop();
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(3);
                    this.container.sphereSlot2.sphereAnima.stone.stop();
                    this.container.sphereSlot1.sphereAnima.visible = false;
                    this.container.sphereSlot1.sphereSlotCase.buttonMode = false;
                    this.container.sphereSlot2.sphereAnima.visible = false;
                    this.container.sphereSlot2.sphereSlotCase.buttonMode = false;
                }
            }
            else if (this.myTower.towerType == 6)
            {
                if (Main.mainClass.readXMLClass.ultraTower2UpgrBlock == 0)
                {
                    this.container.sphereSlot1.gotoAndStop(1);
                    this.container.sphereSlot2.gotoAndStop(1);
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(2);
                    this.container.sphereSlot1.sphereAnima.ice.stop();
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(4);
                    this.container.sphereSlot2.sphereAnima.levin.stop();
                    if (!this.myTower.shootingTurnStack[1])
                    {
                        this.container.sphereSlot1.sphereAnima.visible = false;
                        this.container.sphereSlot1.sphereSlotCase.buttonMode = false;
                    }
                    else
                    {
                        this.container.sphereSlot1.sphereAnima.visible = true;
                        this.container.sphereSlot1.sphereSlotCase.buttonMode = true;
                    }
                    if (!this.myTower.shootingTurnStack[3])
                    {
                        this.container.sphereSlot2.sphereAnima.visible = false;
                        this.container.sphereSlot2.sphereSlotCase.buttonMode = false;
                    }
                    else
                    {
                        this.container.sphereSlot2.sphereAnima.visible = true;
                        this.container.sphereSlot2.sphereSlotCase.buttonMode = true;
                    }
                    if (this.myTower.upgradeTypeAdd == 1)
                    {
                        this.container.btnUpgradeMenu.visible = false;
                    }
                    else if (this.world.money >= Main.mainClass.readXMLClass.costUltraAddIceLevin && !this.fastBuyUltraFlag)
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(1);
                        this.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode = true;
                    }
                    else
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(4);
                    }
                    if (!this.fastBuyUltraFlag)
                    {
                        this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costUltraAddIceLevin;
                    }
                }
                else
                {
                    this.container.btnUpgradeMenu.gotoAndStop(5);
                    this.container.sphereSlot1.gotoAndStop(4);
                    this.container.sphereSlot2.gotoAndStop(4);
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(2);
                    this.container.sphereSlot1.sphereAnima.ice.stop();
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(4);
                    this.container.sphereSlot2.sphereAnima.levin.stop();
                    this.container.sphereSlot1.sphereAnima.visible = false;
                    this.container.sphereSlot1.sphereSlotCase.buttonMode = false;
                    this.container.sphereSlot2.sphereAnima.visible = false;
                    this.container.sphereSlot2.sphereSlotCase.buttonMode = false;
                }
            }
            else if (this.myTower.towerType == 7)
            {
                if (Main.mainClass.readXMLClass.ultraTower3UpgrBlock == 0)
                {
                    this.container.sphereSlot1.gotoAndStop(1);
                    this.container.sphereSlot2.gotoAndStop(1);
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(2);
                    this.container.sphereSlot1.sphereAnima.ice.stop();
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(3);
                    this.container.sphereSlot2.sphereAnima.stone.stop();
                    if (!this.myTower.shootingTurnStack[1])
                    {
                        this.container.sphereSlot1.sphereAnima.visible = false;
                        this.container.sphereSlot1.sphereSlotCase.buttonMode = false;
                    }
                    else
                    {
                        this.container.sphereSlot1.sphereAnima.visible = true;
                        this.container.sphereSlot1.sphereSlotCase.buttonMode = true;
                    }
                    if (!this.myTower.shootingTurnStack[2])
                    {
                        this.container.sphereSlot2.sphereAnima.visible = false;
                        this.container.sphereSlot2.sphereSlotCase.buttonMode = false;
                    }
                    else
                    {
                        this.container.sphereSlot2.sphereAnima.visible = true;
                        this.container.sphereSlot2.sphereSlotCase.buttonMode = true;
                    }
                    if (this.myTower.upgradeTypeAdd == 1)
                    {
                        this.container.btnUpgradeMenu.visible = false;
                    }
                    else if (this.world.money >= Main.mainClass.readXMLClass.costUltraAddIceStone && !this.fastBuyUltraFlag)
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(1);
                        this.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode = true;
                    }
                    else
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(4);
                    }
                    if (!this.fastBuyUltraFlag)
                    {
                        this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costUltraAddIceStone;
                    }
                }
                else
                {
                    this.container.btnUpgradeMenu.gotoAndStop(5);
                    this.container.sphereSlot1.gotoAndStop(4);
                    this.container.sphereSlot2.gotoAndStop(4);
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(2);
                    this.container.sphereSlot1.sphereAnima.ice.stop();
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(3);
                    this.container.sphereSlot2.sphereAnima.stone.stop();
                    this.container.sphereSlot1.sphereAnima.visible = false;
                    this.container.sphereSlot1.sphereSlotCase.buttonMode = false;
                    this.container.sphereSlot2.sphereAnima.visible = false;
                    this.container.sphereSlot2.sphereSlotCase.buttonMode = false;
                }
            }
            else if (this.myTower.towerType == 8)
            {
                if (Main.mainClass.readXMLClass.ultraTower4UpgrBlock == 0)
                {
                    this.container.sphereSlot1.gotoAndStop(1);
                    this.container.sphereSlot2.gotoAndStop(1);
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(1);
                    this.container.sphereSlot1.sphereAnima.fire.stop();
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(4);
                    this.container.sphereSlot2.sphereAnima.levin.stop();
                    if (!this.myTower.shootingTurnStack[0])
                    {
                        this.container.sphereSlot1.sphereAnima.visible = false;
                        this.container.sphereSlot1.sphereSlotCase.buttonMode = false;
                    }
                    else
                    {
                        this.container.sphereSlot1.sphereAnima.visible = true;
                        this.container.sphereSlot1.sphereSlotCase.buttonMode = true;
                    }
                    if (!this.myTower.shootingTurnStack[3])
                    {
                        this.container.sphereSlot2.sphereAnima.visible = false;
                        this.container.sphereSlot2.sphereSlotCase.buttonMode = false;
                    }
                    else
                    {
                        this.container.sphereSlot2.sphereAnima.visible = true;
                        this.container.sphereSlot2.sphereSlotCase.buttonMode = true;
                    }
                    if (this.myTower.upgradeTypeAdd == 1)
                    {
                        this.container.btnUpgradeMenu.visible = false;
                    }
                    else if (this.world.money >= Main.mainClass.readXMLClass.costUltraAddFireLevin && !this.fastBuyUltraFlag)
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(1);
                        this.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode = true;
                    }
                    else
                    {
                        this.container.btnUpgradeMenu.gotoAndStop(4);
                    }
                    if (!this.fastBuyUltraFlag)
                    {
                        this.container.btnUpgradeMenu.costTXT.text = Main.mainClass.readXMLClass.costUltraAddFireLevin;
                    }
                }
                else
                {
                    this.container.btnUpgradeMenu.gotoAndStop(5);
                    this.container.sphereSlot1.gotoAndStop(4);
                    this.container.sphereSlot2.gotoAndStop(4);
                    this.container.sphereSlot1.sphereAnima.gotoAndStop(1);
                    this.container.sphereSlot1.sphereAnima.fire.stop();
                    this.container.sphereSlot2.sphereAnima.gotoAndStop(4);
                    this.container.sphereSlot2.sphereAnima.levin.stop();
                    this.container.sphereSlot1.sphereAnima.visible = false;
                    this.container.sphereSlot1.sphereSlotCase.buttonMode = false;
                    this.container.sphereSlot2.sphereAnima.visible = false;
                    this.container.sphereSlot2.sphereSlotCase.buttonMode = false;
                }
            }
            if (this.fastBuyUltraFlag)
            {
                this.fastBuyUltraManage();
            }
            if (!this.openFlag)
            {
                this.world.worldInterface.archiveSphereBacklightManage("");
                this.autoguidersButtons();
            }
            return;
        }// end function

        public function autoguidersButtons() : void
        {
            this.autoguidesMouse_pt = new Point(Main.mainClass.worldClass.mouseX, Main.mainClass.worldClass.mouseY);
            this.autoguidesObject = null;
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
            if (!this.autoguidesObject && this.container.btnUpgradeMenu.visible && this.container.btnUpgradeMenu.btnUpgradeMenuCase)
            {
                this.autoguidesObject_pt = this.container.btnUpgradeMenu.localToGlobal(new Point(this.container.btnUpgradeMenu.btnUpgradeMenuCase.x, this.container.btnUpgradeMenu.btnUpgradeMenuCase.y));
                this.autoguidesObjectWidth = this.container.btnUpgradeMenu.btnUpgradeMenuCase.width / 2;
                this.autoguidesObjectHeight = this.container.btnUpgradeMenu.btnUpgradeMenuCase.height / 2;
                if (this.autoguidesMouse_pt.x >= this.autoguidesObject_pt.x - this.autoguidesObjectWidth && this.autoguidesMouse_pt.x <= this.autoguidesObject_pt.x + this.autoguidesObjectWidth && this.autoguidesMouse_pt.y >= this.autoguidesObject_pt.y - this.autoguidesObjectHeight && this.autoguidesMouse_pt.y <= this.autoguidesObject_pt.y + this.autoguidesObjectHeight)
                {
                    this.autoguidesObject = this.container.btnUpgradeMenu.btnUpgradeMenuCase;
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
            if (this.autoguidesObject)
            {
                this.tempObject = new Object();
                this.tempObject.target = this.autoguidesObject;
                this.mouseMoveHandler(this.tempObject);
            }
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
                this.container.fastBuyUltraCont.indicator2.visible = false;
                this.container.fastBuyUltraCont.indicator3.visible = false;
                if (!this.fastBuyUltraFlag && !this.openFastBuyUltraFlag && !this.closeFastBuyUltraFlag)
                {
                    this.container.fastBuyUltraCont.visible = false;
                }
                if (this.fastBuyUltraFlag)
                {
                    this.container.fastBuyUltraCont.btnFastBuyUltra.gotoAndStop(1);
                    this.container.fastBuyUltraCont.indicator1.gotoAndStop(2);
                    this.container.fastBuyUltraCont.indicator4.gotoAndStop(2);
                    this.container.fastBuyUltraCont.indicator1.visible = true;
                    this.container.fastBuyUltraCont.indicator4.visible = true;
                    if (!this.fastBuyBlockCost)
                    {
                        this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyUltraScan();
                    }
                    else
                    {
                        this.container.fastBuyUltraCont.btnFastBuyUltra.costTXT.text = this.fastBuyPrice;
                    }
                    if (this.myTower.towerType == 5)
                    {
                        if (this.myTower.shootingTurnStack[0])
                        {
                            this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                        }
                        if (this.myTower.shootingTurnStack[2])
                        {
                            this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                        }
                    }
                    else if (this.myTower.towerType == 6)
                    {
                        if (this.myTower.shootingTurnStack[1])
                        {
                            this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                        }
                        if (this.myTower.shootingTurnStack[3])
                        {
                            this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                        }
                    }
                    else if (this.myTower.towerType == 7)
                    {
                        if (this.myTower.shootingTurnStack[1])
                        {
                            this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                        }
                        if (this.myTower.shootingTurnStack[2])
                        {
                            this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
                        }
                    }
                    else if (this.myTower.towerType == 8)
                    {
                        if (this.myTower.shootingTurnStack[0])
                        {
                            this.container.fastBuyUltraCont.indicator1.gotoAndStop(1);
                        }
                        if (this.myTower.shootingTurnStack[3])
                        {
                            this.container.fastBuyUltraCont.indicator4.gotoAndStop(1);
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

        public function fastBuyUltraScan() : int
        {
            if (this.myTower.towerType == 5)
            {
                this.tempObject1 = Main.mainClass.readXMLClass.costUltraAddFireStone;
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
            else if (this.myTower.towerType == 6)
            {
                this.tempObject1 = Main.mainClass.readXMLClass.costUltraAddIceLevin;
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
            else if (this.myTower.towerType == 7)
            {
                this.tempObject1 = Main.mainClass.readXMLClass.costUltraAddIceStone;
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
            else if (this.myTower.towerType == 8)
            {
                this.tempObject1 = Main.mainClass.readXMLClass.costUltraAddFireLevin;
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

        public function hintPosition(param1:int = 1) : void
        {
            this.tempObject = this.container.localToGlobal(new Point(this.container.btnUpgradeMenu.x, this.container.btnUpgradeMenu.y));
            param1 = param1 - 1;
            if (this.tempObject.x < 120)
            {
                if (this.tempObject.y < 120)
                {
                    this.hint.gotoAndStop(param1 + 4);
                    this.hint.y = this.tempObject.y + 12;
                }
                else if (this.tempObject.y > Main.SCREEN_HEIGHT - 120)
                {
                    this.hint.gotoAndStop(param1 + 2);
                    this.hint.y = this.tempObject.y - 12;
                }
                else
                {
                    this.hint.gotoAndStop(param1 + 2);
                    this.hint.y = this.tempObject.y - 12;
                }
                this.hint.x = this.tempObject.x + 12;
            }
            else if (this.tempObject.x > Main.SCREEN_WIDTH - 120)
            {
                if (this.tempObject.y < 120)
                {
                    this.hint.gotoAndStop(param1 + 3);
                    this.hint.y = this.tempObject.y + 12;
                }
                else if (this.tempObject.y > Main.SCREEN_HEIGHT - 120)
                {
                    this.hint.gotoAndStop((param1 + 1));
                    this.hint.y = this.tempObject.y - 12;
                }
                else
                {
                    this.hint.gotoAndStop((param1 + 1));
                    this.hint.y = this.tempObject.y + 12;
                }
                this.hint.x = this.tempObject.x - 12;
            }
            else if (this.tempObject.y < 120)
            {
                if (this.tempObject.x < 120)
                {
                    this.hint.gotoAndStop(param1 + 4);
                    this.hint.x = this.tempObject.x + 12;
                    this.hint.y = this.tempObject.y + 12;
                }
                else if (this.tempObject.x > Main.SCREEN_WIDTH - 120)
                {
                    this.hint.gotoAndStop(param1 + 3);
                    this.hint.x = this.tempObject.x - 12;
                    this.hint.y = this.tempObject.y + 12;
                }
                else
                {
                    this.hint.gotoAndStop(param1 + 4);
                    this.hint.x = this.tempObject.x;
                    this.hint.y = this.tempObject.y + 12;
                }
            }
            else if (this.tempObject.y > Main.SCREEN_HEIGHT - 120)
            {
                if (this.tempObject.x < 120)
                {
                    this.hint.gotoAndStop(param1 + 2);
                    this.hint.x = this.tempObject.x + 12;
                    this.hint.y = this.tempObject.y - 12;
                }
                else if (this.tempObject.x > Main.SCREEN_WIDTH - 120)
                {
                    this.hint.gotoAndStop((param1 + 1));
                    this.hint.x = this.tempObject.x - 12;
                    this.hint.y = this.tempObject.y - 12;
                }
                else
                {
                    this.hint.gotoAndStop(param1 + 2);
                    this.hint.x = this.tempObject.x;
                    this.hint.y = this.tempObject.y - 12;
                }
            }
            else
            {
                this.hint.gotoAndStop(param1 + 2);
                this.hint.x = this.tempObject.x;
                this.hint.y = this.tempObject.y - 12;
            }
            this.tempObject = null;
            return;
        }// end function

        public function closeMenu(param1:Boolean = false) : void
        {
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            this.closeFlag = true;
            this.towerRadius.visible = false;
            this.world.ultraTowerMenu = null;
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
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.worldInterface.updateInfo();
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
