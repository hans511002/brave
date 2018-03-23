package engine
{
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class GetSphere extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:MovieClip;
        public var radius:MovieClip;
        public var counter:int = 0;
        public var owner:Object;
        public var ownerType:String;
        public var ownerPoint:Point;
        public var myRadius:Number = 0;
        public var myDamage:Number = 0;
        public var fireCount:int = 0;
        public var iceCount:int = 0;
        public var stoneCount:int = 0;
        public var levinCount:int = 0;
        public var listOfStack:Array;
        public var world:World;
        public var dead:Boolean;
        public var speedFrame:int;
        public var speedX:Number;
        public var speedY:Number;
        public var arrow:Arrow_mc;
        public var towerArrow:Arrow_mc;
        public var type:String;
        public var getAllCount:int = 0;
        public var containerChange:MovieClip;

        public function GetSphere(param1:String = "holder")
        {
            this.listOfStack = [];
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.type = param1;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.world = Main.mainClass.worldClass;
            if (this.type == "holder")
            {
                this.container = new GetSphere_mc();
                this.container.stop();
                this.container.cont.stop();
                this.container.sphere1.stop();
                this.container.sphere2.stop();
                this.container.sphere3.stop();
                this.container.sphere4.stop();
                this.container.sphere1.cont.stop();
                this.container.sphere2.cont.stop();
                this.container.sphere3.cont.stop();
                this.container.sphere4.cont.stop();
                this.container.sphere1.visible = false;
                this.container.sphere2.visible = false;
                this.container.sphere3.visible = false;
                this.container.sphere4.visible = false;
            }
            else if (this.type == "getAll")
            {
                this.container = new GetAll_mc();
                this.container.stop();
                this.container.cross.stop();
                this.container.cross.visible = false;
            }
            this.addChild(this.container);
            this.world.worldInterface.castRegime("on");
            this.arrow = new Arrow_mc();
            this.arrow.stop();
            this.arrow.scaleY = -1;
            this.arrow.y = this.arrow.y - 30;
            this.arrow.visible = false;
            this.addChild(this.arrow);
            if (this.world.towerMenu)
            {
                if (this.world.towerMenu.container.btnUpgradeMenu)
                {
                    if (this.world.towerMenu.container.btnUpgradeMenu.btnUpgradeMenuCase)
                    {
                        if (this.world.towerMenu.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode)
                        {
                            this.world.towerMenu.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode = false;
                        }
                    }
                }
                else
                {
                    if (this.world.towerMenu.container.btnTowerUpgr1)
                    {
                        this.world.towerMenu.container.btnTowerUpgr1.btnTowerUpgrCase.buttonMode = false;
                    }
                    if (this.world.towerMenu.container.btnTowerUpgr2)
                    {
                        this.world.towerMenu.container.btnTowerUpgr2.btnTowerUpgrCase.buttonMode = false;
                    }
                    if (this.world.towerMenu.container.btnTowerUpgr3)
                    {
                        this.world.towerMenu.container.btnTowerUpgr3.btnTowerUpgrCase.buttonMode = false;
                    }
                    if (this.world.towerMenu.container.btnTowerUpgr4)
                    {
                        this.world.towerMenu.container.btnTowerUpgr4.btnTowerUpgrCase.buttonMode = false;
                    }
                }
            }
            else if (this.world.ultraTowerMenu)
            {
                if (this.world.ultraTowerMenu.container.btnUpgradeMenu)
                {
                    if (this.world.ultraTowerMenu.container.btnUpgradeMenu.btnUpgradeMenuCase)
                    {
                        if (this.world.ultraTowerMenu.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode)
                        {
                            this.world.ultraTowerMenu.container.btnUpgradeMenu.btnUpgradeMenuCase.buttonMode = false;
                        }
                    }
                }
            }
            this.x = this.world.mouseX;
            this.y = this.world.mouseY;
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            return;
        }// end function

        public function update() : void
        {
            if (this.type == "holder")
            {
                if (this.container is GetSphere_mc)
                {
                    if (this.container.sphere1.visible)
                    {
                        if (this.container.sphere1.cont.currentFrame < this.container.sphere1.cont.totalFrames)
                        {
                            this.container.sphere1.cont.gotoAndStop((this.container.sphere1.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.container.sphere1.cont.gotoAndStop(1);
                        }
                    }
                    if (this.container.sphere2.visible)
                    {
                        if (this.container.sphere2.cont.currentFrame < this.container.sphere2.cont.totalFrames)
                        {
                            this.container.sphere2.cont.gotoAndStop((this.container.sphere2.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.container.sphere2.cont.gotoAndStop(1);
                        }
                    }
                    if (this.container.sphere3.visible)
                    {
                        if (this.container.sphere3.cont.currentFrame < this.container.sphere3.cont.totalFrames)
                        {
                            this.container.sphere3.cont.gotoAndStop((this.container.sphere3.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.container.sphere3.cont.gotoAndStop(1);
                        }
                    }
                    if (this.container.sphere4.visible)
                    {
                        if (this.container.sphere4.cont.currentFrame < this.container.sphere4.cont.totalFrames)
                        {
                            this.container.sphere4.cont.gotoAndStop((this.container.sphere4.cont.currentFrame + 1));
                        }
                        else
                        {
                            this.container.sphere4.cont.gotoAndStop(1);
                        }
                    }
                }
                else if (this.container.cont.currentFrame < this.container.cont.totalFrames)
                {
                    this.container.cont.gotoAndStop((this.container.cont.currentFrame + 1));
                }
                else
                {
                    this.container.cont.gotoAndStop(1);
                }
            }
            else if (this.type == "getAll")
            {
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                else
                {
                    this.container.gotoAndStop(1);
                }
            }
            if (this.arrow.visible)
            {
                if (this.arrow.currentFrame < this.arrow.totalFrames)
                {
                    this.arrow.gotoAndStop((this.arrow.currentFrame + 1));
                }
                else
                {
                    this.arrow.gotoAndStop(1);
                }
            }
            if (this.towerArrow)
            {
                if (this.towerArrow.currentFrame < this.towerArrow.totalFrames)
                {
                    this.towerArrow.gotoAndStop((this.towerArrow.currentFrame + 1));
                }
                else
                {
                    this.towerArrow.gotoAndStop(1);
                }
            }
            if (this.containerChange)
            {
                if (this.containerChange.alpha > 0)
                {
                    this.containerChange.alpha = this.containerChange.alpha - 0.1;
                    this.container.alpha = this.container.alpha + 0.1;
                }
                else
                {
                    this.removeChild(this.containerChange);
                    this.containerChange = null;
                    this.container.alpha = 1;
                }
            }
            if (this.world.getSphere == this)
            {
                this.world.feature.scanPointersAtCast();
                this.x = this.world.mouseX;
                this.y = this.world.mouseY;
                if (this.radius.visible)
                {
                    if (this.radius.currentFrame == 1)
                    {
                        (this.radius.rotation + 1);
                    }
                    if (this.radius.cont.currentFrame < this.radius.cont.totalFrames)
                    {
                        this.radius.cont.gotoAndStop((this.radius.cont.currentFrame + 1));
                    }
                    else
                    {
                        this.radius.cont.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (param1.target.name == "fireCase")
            {
                if (param1.target.buttonMode && this.world.worldInterface.container.fireBack.currentFrame == 1)
                {
                    if (this.world.worldInterface.container.iceBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.iceBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.stoneBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.stoneBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.levinBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.levinBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.getAll.currentFrame == 2)
                    {
                        this.world.worldInterface.container.getAll.gotoAndStop(1);
                    }
                    this.world.worldInterface.container.fireBack.gotoAndStop(2);
                    this.world.worldInterface.container.fireBack.cont.stop();
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.world.worldInterface.container.fireBack.currentFrame == 2)
            {
                this.world.worldInterface.container.fireBack.gotoAndStop(1);
            }
            if (param1.target.name == "iceCase")
            {
                if (param1.target.buttonMode && this.world.worldInterface.container.iceBack.currentFrame == 1)
                {
                    if (this.world.worldInterface.container.fireBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.fireBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.stoneBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.stoneBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.levinBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.levinBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.getAll.currentFrame == 2)
                    {
                        this.world.worldInterface.container.getAll.gotoAndStop(1);
                    }
                    this.world.worldInterface.container.iceBack.gotoAndStop(2);
                    this.world.worldInterface.container.iceBack.cont.stop();
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.world.worldInterface.container.iceBack.currentFrame == 2)
            {
                this.world.worldInterface.container.iceBack.gotoAndStop(1);
            }
            if (param1.target.name == "stoneCase")
            {
                if (param1.target.buttonMode && this.world.worldInterface.container.stoneBack.currentFrame == 1)
                {
                    if (this.world.worldInterface.container.fireBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.fireBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.iceBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.iceBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.levinBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.levinBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.getAll.currentFrame == 2)
                    {
                        this.world.worldInterface.container.getAll.gotoAndStop(1);
                    }
                    this.world.worldInterface.container.stoneBack.gotoAndStop(2);
                    this.world.worldInterface.container.stoneBack.cont.stop();
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.world.worldInterface.container.stoneBack.currentFrame == 2)
            {
                this.world.worldInterface.container.stoneBack.gotoAndStop(1);
            }
            if (param1.target.name == "levinCase")
            {
                if (param1.target.buttonMode && this.world.worldInterface.container.levinBack.currentFrame == 1)
                {
                    if (this.world.worldInterface.container.fireBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.fireBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.iceBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.iceBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.stoneBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.stoneBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.getAll.currentFrame == 2)
                    {
                        this.world.worldInterface.container.getAll.gotoAndStop(1);
                    }
                    this.world.worldInterface.container.levinBack.gotoAndStop(2);
                    this.world.worldInterface.container.levinBack.cont.stop();
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.world.worldInterface.container.levinBack.currentFrame == 2)
            {
                this.world.worldInterface.container.levinBack.gotoAndStop(1);
            }
            if (param1.target.name == "getAllCase")
            {
                if (param1.target.buttonMode && this.world.worldInterface.container.getAll.currentFrame == 1)
                {
                    if (this.world.worldInterface.container.fireBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.fireBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.iceBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.iceBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.stoneBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.stoneBack.gotoAndStop(1);
                    }
                    if (this.world.worldInterface.container.levinBack.currentFrame == 2)
                    {
                        this.world.worldInterface.container.levinBack.gotoAndStop(1);
                    }
                    this.world.worldInterface.container.getAll.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.world.worldInterface.container.getAll.currentFrame == 2)
            {
                this.world.worldInterface.container.getAll.gotoAndStop(1);
            }
            if (param1.target.name == "fireCase" || param1.target.name == "iceCase" || param1.target.name == "stoneCase" || param1.target.name == "levinCase" || param1.target.name == "getAllCase" || param1.target.name == "archiveCase" || param1.target.name == "interfaceUpCase" || param1.target.name == "sellCase" || param1.target.name == "towerCase")
            {
                if (this.radius.visible)
                {
                    this.radius.visible = false;
                    this.arrow.visible = false;
                }
                if (param1.target.name == "towerCase")
                {
                    if (this.type == "holder")
                    {
                        if (param1.target.buttonMode && param1.target.parent.parent.spheresManage("scan") > 0)
                        {
                            if (!this.towerArrow)
                            {
                                this.towerArrow = new Arrow_mc();
                                this.towerArrow.stop();
                                this.towerArrow.myTower = param1.target.parent.parent;
                                var _loc_2:* = false;
                                this.towerArrow.mouseChildren = false;
                                this.towerArrow.mouseEnabled = _loc_2;
                                this.towerArrow.myTower.addChild(this.towerArrow);
                            }
                            if (this.container.currentFrame == 2)
                            {
                                this.container.gotoAndStop(1);
                            }
                        }
                        else
                        {
                            if (this.towerArrow)
                            {
                                this.towerArrow.myTower.removeChild(this.towerArrow);
                                this.towerArrow = null;
                            }
                            if (this.container.currentFrame == 1)
                            {
                                this.container.gotoAndStop(2);
                            }
                        }
                    }
                    else if (this.type == "getAll")
                    {
                        if (param1.target.buttonMode && param1.target.parent.parent.spheresManage("scan") == 4)
                        {
                            if (!this.towerArrow)
                            {
                                this.towerArrow = new Arrow_mc();
                                this.towerArrow.stop();
                                this.towerArrow.myTower = param1.target.parent.parent;
                                var _loc_2:* = false;
                                this.towerArrow.mouseChildren = false;
                                this.towerArrow.mouseEnabled = _loc_2;
                                this.towerArrow.myTower.addChild(this.towerArrow);
                            }
                            if (this.container.cross.visible)
                            {
                                this.container.cross.visible = false;
                            }
                        }
                        else
                        {
                            if (this.towerArrow)
                            {
                                this.towerArrow.myTower.removeChild(this.towerArrow);
                                this.towerArrow = null;
                            }
                            if (this.container.cross.visible)
                            {
                                this.container.cross.visible = true;
                            }
                        }
                    }
                }
            }
            else
            {
                if (this.towerArrow)
                {
                    this.towerArrow.myTower.removeChild(this.towerArrow);
                    this.towerArrow = null;
                }
                if (this.type == "holder")
                {
                    if (this.container.currentFrame == 2)
                    {
                        this.container.gotoAndStop(1);
                    }
                }
                else if (this.type == "getAll")
                {
                    if (this.container.cross.visible)
                    {
                        this.container.cross.visible = false;
                    }
                }
                if (!this.world.towerMenu && !this.world.ultraTowerMenu)
                {
                    if (!this.radius.visible)
                    {
                        this.radius.visible = true;
                        this.arrow.visible = true;
                    }
                }
                else
                {
                    if (this.world.towerMenu)
                    {
                        this.tempObject = this.world.towerMenu;
                    }
                    else if (this.world.ultraTowerMenu)
                    {
                        this.tempObject = this.world.ultraTowerMenu;
                    }
                    if (!this.radius.visible && Point.distance(this.tempObject.myTower.this_pt, new Point(this.world.mouseX, this.world.mouseY)) > 86)
                    {
                        this.radius.visible = true;
                        this.arrow.visible = true;
                        this.tempObject.closeMenu();
                    }
                }
                if (param1.target.name == "road")
                {
                    if (this.radius.currentFrame == 2)
                    {
                        this.radius.gotoAndStop(1);
                        this.arrow.alpha = 0;
                        this.radius.cont.stop();
                        if (this.radius.cont1)
                        {
                            if (this.type == "holder")
                            {
                                this.radius.cont1.stop();
                                this.radius.cont2.stop();
                                this.radius.cont3.stop();
                                this.radius.cont1.visible = false;
                                this.radius.cont2.visible = false;
                                this.radius.cont3.visible = false;
                            }
                            else
                            {
                                this.radius.cont1.stop();
                                this.radius.cont2.stop();
                                this.radius.cont3.stop();
                                if (this.getAllCount > 0)
                                {
                                    this.radius.cont1.visible = true;
                                }
                                else
                                {
                                    this.radius.cont1.visible = false;
                                }
                                if (this.getAllCount > 1)
                                {
                                    this.radius.cont2.visible = true;
                                }
                                else
                                {
                                    this.radius.cont2.visible = false;
                                }
                                if (this.getAllCount > 2)
                                {
                                    this.radius.cont3.visible = true;
                                }
                                else
                                {
                                    this.radius.cont3.visible = false;
                                }
                            }
                        }
                    }
                }
                else if (this.radius.currentFrame == 1)
                {
                    this.radius.gotoAndStop(2);
                    this.arrow.alpha = 1;
                    this.radius.cont.stop();
                    if (this.radius.cont1)
                    {
                        if (this.type == "holder")
                        {
                            this.radius.cont1.stop();
                            this.radius.cont2.stop();
                            this.radius.cont3.stop();
                            this.radius.cont1.visible = false;
                            this.radius.cont2.visible = false;
                            this.radius.cont3.visible = false;
                        }
                        else
                        {
                            this.radius.cont1.stop();
                            this.radius.cont2.stop();
                            this.radius.cont3.stop();
                            if (this.getAllCount > 0)
                            {
                                this.radius.cont1.visible = true;
                            }
                            else
                            {
                                this.radius.cont1.visible = false;
                            }
                            if (this.getAllCount > 1)
                            {
                                this.radius.cont2.visible = true;
                            }
                            else
                            {
                                this.radius.cont2.visible = false;
                            }
                            if (this.getAllCount > 2)
                            {
                                this.radius.cont3.visible = true;
                            }
                            else
                            {
                                this.radius.cont3.visible = false;
                            }
                        }
                    }
                }
            }
            if (param1.target.name == "sphereSlotCase")
            {
                if (this.world.towerMenu)
                {
                    this.world.towerMenu.mouseMoveHandler(param1);
                }
                else if (this.world.ultraTowerMenu)
                {
                    this.world.ultraTowerMenu.mouseMoveHandler(param1);
                }
            }
            else if (this.world.towerMenu)
            {
                if (this.world.towerMenu.container.sphereSlot1.currentFrame == 2)
                {
                    this.world.towerMenu.container.sphereSlot1.gotoAndStop(1);
                }
                if (this.world.towerMenu.container.sphereSlot2.currentFrame == 2)
                {
                    this.world.towerMenu.container.sphereSlot2.gotoAndStop(1);
                }
                if (this.world.towerMenu.container.sphereSlot3.currentFrame == 2)
                {
                    this.world.towerMenu.container.sphereSlot3.gotoAndStop(1);
                }
                if (this.world.towerMenu.container.sphereSlot4.currentFrame == 2)
                {
                    this.world.towerMenu.container.sphereSlot4.gotoAndStop(1);
                }
            }
            else if (this.world.ultraTowerMenu)
            {
                if (this.world.ultraTowerMenu.container.sphereSlot1.currentFrame == 2)
                {
                    this.world.ultraTowerMenu.container.sphereSlot1.gotoAndStop(1);
                }
                if (this.world.ultraTowerMenu.container.sphereSlot2.currentFrame == 2)
                {
                    this.world.ultraTowerMenu.container.sphereSlot2.gotoAndStop(1);
                }
            }
            if (param1.target.name == "sellCase")
            {
                if (this.world.worldInterface.container.sell.currentFrame == 1)
                {
                    this.world.worldInterface.container.sell.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.world.worldInterface.container.sell.currentFrame == 2)
            {
                this.world.worldInterface.container.sell.gotoAndStop(1);
            }
            return;
        }// end function

        public function mouseDownHandler(param1) : void
        {
            if (param1.target.name == "sellCase")
            {
                this.world.worldInterface.container.sell.gotoAndStop(1);
                while (this.fireCount > 0)
                {
                    
                    (this.fireCount - 1);
                    this.world.worldInterface.sellSphere("fire");
                }
                while (this.iceCount > 0)
                {
                    
                    (this.iceCount - 1);
                    this.world.worldInterface.sellSphere("ice");
                }
                while (this.stoneCount > 0)
                {
                    
                    (this.stoneCount - 1);
                    this.world.worldInterface.sellSphere("stone");
                }
                while (this.levinCount > 0)
                {
                    
                    (this.levinCount - 1);
                    this.world.worldInterface.sellSphere("levin");
                }
                while (this.getAllCount > 0)
                {
                    
                    (this.getAllCount - 1);
                    this.world.worldInterface.sellSphere("getAll");
                }
                this.kill();
                Sounds.instance.playSound("snd_world_sell");
            }
            else if (param1.target.name == "towerCase" && param1.target.buttonMode)
            {
                this.tempObject = param1.target.parent.parent;
                if (this.type == "holder")
                {
                    this.container.sphere1.visible = false;
                    this.container.sphere2.visible = false;
                    this.container.sphere3.visible = false;
                    this.container.sphere4.visible = false;
                    this.i = 0;
                    while (this.i < this.listOfStack.length)
                    {
                        
                        if (this.listOfStack[this.i] == "fire")
                        {
                            this.tempObject1 = this.tempObject.spheresManage("push", "fire", 1);
                            if (this.tempObject1 == 0)
                            {
                                (this.fireCount - 1);
                                this.listOfStack[this.i] = "无";
                            }
                        }
                        else if (this.listOfStack[this.i] == "ice")
                        {
                            this.tempObject1 = this.tempObject.spheresManage("push", "ice", 1);
                            if (this.tempObject1 == 0)
                            {
                                (this.iceCount - 1);
                                this.listOfStack[this.i] = "无";
                            }
                        }
                        else if (this.listOfStack[this.i] == "stone")
                        {
                            this.tempObject1 = this.tempObject.spheresManage("push", "stone", 1);
                            if (this.tempObject1 == 0)
                            {
                                (this.stoneCount - 1);
                                this.listOfStack[this.i] = "无";
                            }
                        }
                        else if (this.listOfStack[this.i] == "levin")
                        {
                            this.tempObject1 = this.tempObject.spheresManage("push", "levin", 1);
                            if (this.tempObject1 == 0)
                            {
                                (this.levinCount - 1);
                                this.listOfStack[this.i] = "无";
                            }
                        }
                        var _loc_2:* = this;
                        var _loc_3:* = this.i + 1;
                        _loc_2.i = _loc_3;
                    }
                    this.i = this.listOfStack.length - 1;
                    while (this.i >= 0)
                    {
                        
                        if (this.listOfStack[this.i] == "无")
                        {
                            this.listOfStack.splice(this.i, 1);
                        }
                        var _loc_2:* = this;
                        var _loc_3:* = this.i - 1;
                        _loc_2.i = _loc_3;
                    }
                    if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount == 0)
                    {
                        this.kill();
                    }
                    else
                    {
                        this.retrieveGetSphere();
                    }
                }
                else if (this.type == "getAll")
                {
                    (this.getAllCount - 1);
                    this.tempObject1 = this.tempObject.spheresManage("push", "getAll", 1);
                    this.getAllCount = this.getAllCount + this.tempObject1;
                    if (this.getAllCount == 0)
                    {
                        this.kill();
                    }
                    else
                    {
                        this.retrieveGetSphere();
                    }
                }
            }
            else if (param1.target.name == "fireCase")
            {
                if (param1.target.buttonMode)
                {
                    if (this.listOfStack.length < 4)
                    {
                        if (this.world.worldInterface.fireCount == 0)
                        {
                            this.world.worldInterface.archiveManage("buy", "fire");
                        }
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                        this.world.worldInterface.archiveManage("get", "fire");
                    }
                }
            }
            else if (param1.target.name == "iceCase")
            {
                if (param1.target.buttonMode)
                {
                    if (this.listOfStack.length < 4)
                    {
                        if (this.world.worldInterface.iceCount == 0)
                        {
                            this.world.worldInterface.archiveManage("buy", "ice");
                        }
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                        this.world.worldInterface.archiveManage("get", "ice");
                    }
                }
            }
            else if (param1.target.name == "stoneCase")
            {
                if (param1.target.buttonMode)
                {
                    if (this.listOfStack.length < 4)
                    {
                        if (this.world.worldInterface.stoneCount == 0)
                        {
                            this.world.worldInterface.archiveManage("buy", "stone");
                        }
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                        this.world.worldInterface.archiveManage("get", "stone");
                    }
                }
            }
            else if (param1.target.name == "levinCase")
            {
                if (param1.target.buttonMode)
                {
                    if (this.listOfStack.length < 4)
                    {
                        if (this.world.worldInterface.levinCount == 0)
                        {
                            this.world.worldInterface.archiveManage("buy", "levin");
                        }
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                        this.world.worldInterface.archiveManage("get", "levin");
                    }
                }
            }
            else if (param1.target.name == "getAllCase")
            {
                if (param1.target.buttonMode)
                {
                    if (this.getAllCount < 3)
                    {
                        if (this.world.worldInterface.getAllCount == 0)
                        {
                            this.world.worldInterface.archiveManage("buy", "getAll");
                        }
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                        this.world.worldInterface.archiveManage("get", "getAll");
                    }
                }
            }
            else if (param1.target.name == "sphereSlotCase")
            {
                if (param1.target.parent.currentFrame == 2)
                {
                    if (this.listOfStack.length < 4)
                    {
                        if (this.world.towerMenu)
                        {
                            this.tempObject = this.world.towerMenu;
                        }
                        else if (this.world.ultraTowerMenu)
                        {
                            this.tempObject = this.world.ultraTowerMenu;
                        }
                        if (param1.target.parent.sphereAnima.visible)
                        {
                            if (param1.target.parent.sphereAnima.visible)
                            {
                                if (param1.target.parent.sphereAnima.currentFrame == 1)
                                {
                                    this.tempObject.myTower.towerGetSphereManage("get", "fire");
                                    if (!this.world.ultraTowerMenu)
                                    {
                                        this.tempObject.spheresMonitor();
                                    }
                                }
                                else if (param1.target.parent.sphereAnima.currentFrame == 2)
                                {
                                    this.tempObject.myTower.towerGetSphereManage("get", "ice");
                                    if (!this.world.ultraTowerMenu)
                                    {
                                        this.tempObject.spheresMonitor();
                                    }
                                }
                                else if (param1.target.parent.sphereAnima.currentFrame == 3)
                                {
                                    this.tempObject.myTower.towerGetSphereManage("get", "stone");
                                    if (!this.world.ultraTowerMenu)
                                    {
                                        this.tempObject.spheresMonitor();
                                    }
                                }
                                else if (param1.target.parent.sphereAnima.currentFrame == 4)
                                {
                                    this.tempObject.myTower.towerGetSphereManage("get", "levin");
                                    if (!this.world.ultraTowerMenu)
                                    {
                                        this.tempObject.spheresMonitor();
                                    }
                                }
                            }
                        }
                        Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
                else if (param1.target.parent.currentFrame == 1)
                {
                    this.getSphereFromArchiveToTower();
                    this.speedFrame = 0;
                }
            }
            else if (param1.target.name != "archiveCase" && param1.target.name != "getAllCase")
            {
                if (this.radius.currentFrame == 1)
                {
                    this.tempObject = new CastSphere();
                    this.world.addChild(this.tempObject);
                    this.kill();
                }
                else if (param1.target is TowerMenu_mc || param1.target.parent is TowerMenu_mc || param1.target.parent.parent is TowerMenu_mc || param1.target is UltraTowerMenu_mc || param1.target.parent is UltraTowerMenu_mc || param1.target.parent.parent is UltraTowerMenu_mc)
                {
                    if (this.world.towerMenu || this.world.ultraTowerMenu)
                    {
                        this.getSphereFromArchiveToTower();
                        this.speedFrame = 0;
                    }
                }
                else
                {
                    this.retrieveGetSphereToArchive();
                }
            }
            return;
        }// end function

        public function mouseUpHandler(param1) : void
        {
            return;
        }// end function

        public function retrieveGetSphereToArchive() : void
        {
            this.ownerType = "archive";
            if (this.fireCount > 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount == 0)
            {
                this.owner = this.world.worldInterface.container.fireSphere;
                this.ownerPoint = this.world.worldInterface.container.fireSphere.myPoint;
            }
            else if (this.fireCount == 0 && this.iceCount > 0 && this.stoneCount == 0 && this.levinCount == 0)
            {
                this.owner = this.world.worldInterface.container.iceSphere;
                this.ownerPoint = this.world.worldInterface.container.iceSphere.myPoint;
            }
            else if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount > 0 && this.levinCount == 0)
            {
                this.owner = this.world.worldInterface.container.stoneSphere;
                this.ownerPoint = this.world.worldInterface.container.stoneSphere.myPoint;
            }
            else if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount > 0)
            {
                this.owner = this.world.worldInterface.container.levinSphere;
                this.ownerPoint = this.world.worldInterface.container.levinSphere.myPoint;
            }
            else
            {
                this.owner = this.world.worldInterface.container.getAll;
                this.ownerPoint = this.world.worldInterface.container.getAll.myPoint;
            }
            this.retrieveGetSphere();
            return;
        }// end function

        public function manage(param1:String, param2:String = "") : void
        {
            if (param1 == "add")
            {
                if (this.type == "holder")
                {
                    if (this.listOfStack.length < 4)
                    {
                        this.listOfStack.push(param2);
                        if (param2 == "fire")
                        {
                            if (this.listOfStack.length == 1)
                            {
                                this.container.sphere1.gotoAndStop(1);
                                this.container.sphere1.cont.stop();
                                this.container.sphere1.visible = true;
                            }
                            else if (this.listOfStack.length == 2)
                            {
                                this.container.sphere2.gotoAndStop(1);
                                this.container.sphere2.cont.stop();
                                this.container.sphere2.visible = true;
                            }
                            else if (this.listOfStack.length == 3)
                            {
                                this.container.sphere3.gotoAndStop(1);
                                this.container.sphere3.cont.stop();
                                this.container.sphere3.visible = true;
                            }
                            else if (this.listOfStack.length == 4)
                            {
                                this.container.sphere4.gotoAndStop(1);
                                this.container.sphere4.cont.stop();
                                this.container.sphere4.visible = true;
                            }
                            (this.fireCount + 1);
                        }
                        else if (param2 == "ice")
                        {
                            if (this.listOfStack.length == 1)
                            {
                                this.container.sphere1.gotoAndStop(2);
                                this.container.sphere1.cont.stop();
                                this.container.sphere1.visible = true;
                            }
                            else if (this.listOfStack.length == 2)
                            {
                                this.container.sphere2.gotoAndStop(2);
                                this.container.sphere2.cont.stop();
                                this.container.sphere2.visible = true;
                            }
                            else if (this.listOfStack.length == 3)
                            {
                                this.container.sphere3.gotoAndStop(2);
                                this.container.sphere3.cont.stop();
                                this.container.sphere3.visible = true;
                            }
                            else if (this.listOfStack.length == 4)
                            {
                                this.container.sphere4.gotoAndStop(2);
                                this.container.sphere4.cont.stop();
                                this.container.sphere4.visible = true;
                            }
                            (this.iceCount + 1);
                        }
                        else if (param2 == "stone")
                        {
                            if (this.listOfStack.length == 1)
                            {
                                this.container.sphere1.gotoAndStop(3);
                                this.container.sphere1.cont.stop();
                                this.container.sphere1.visible = true;
                            }
                            else if (this.listOfStack.length == 2)
                            {
                                this.container.sphere2.gotoAndStop(3);
                                this.container.sphere2.cont.stop();
                                this.container.sphere2.visible = true;
                            }
                            else if (this.listOfStack.length == 3)
                            {
                                this.container.sphere3.gotoAndStop(3);
                                this.container.sphere3.cont.stop();
                                this.container.sphere3.visible = true;
                            }
                            else if (this.listOfStack.length == 4)
                            {
                                this.container.sphere4.gotoAndStop(3);
                                this.container.sphere4.cont.stop();
                                this.container.sphere4.visible = true;
                            }
                            (this.stoneCount + 1);
                        }
                        else if (param2 == "levin")
                        {
                            if (this.listOfStack.length == 1)
                            {
                                this.container.sphere1.gotoAndStop(4);
                                this.container.sphere1.cont.stop();
                                this.container.sphere1.visible = true;
                            }
                            else if (this.listOfStack.length == 2)
                            {
                                this.container.sphere2.gotoAndStop(4);
                                this.container.sphere2.cont.stop();
                                this.container.sphere2.visible = true;
                            }
                            else if (this.listOfStack.length == 3)
                            {
                                this.container.sphere3.gotoAndStop(4);
                                this.container.sphere3.cont.stop();
                                this.container.sphere3.visible = true;
                            }
                            else if (this.listOfStack.length == 4)
                            {
                                this.container.sphere4.gotoAndStop(4);
                                this.container.sphere4.cont.stop();
                                this.container.sphere4.visible = true;
                            }
                            (this.levinCount + 1);
                        }
                        if (this.fireCount == 1 && this.iceCount == 1 && this.stoneCount == 1 && this.levinCount == 1)
                        {
                            this.fireCount = 0;
                            this.iceCount = 0;
                            this.stoneCount = 0;
                            this.levinCount = 0;
                            this.getAllCount = 1;
                            this.type = "getAll";
                            this.containerChange = this.container;
                            this.listOfStack = [];
                            this.container = new GetAll_mc();
                            this.container.stop();
                            this.container.cross.stop();
                            this.container.numTXT.text = this.getAllCount;
                            this.container.cross.visible = false;
                            this.container.alpha = 0;
                            this.addChild(this.container);
                        }
                    }
                }
                else if (this.type == "getAll")
                {
                    if (this.getAllCount < 3)
                    {
                        (this.getAllCount + 1);
                        this.container.numTXT.text = this.getAllCount;
                    }
                }
                if (this.fireCount > 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount == 0)
                {
                    if (this.radius && !(this.radius is RadiusFire_mc))
                    {
                        this.removeChild(this.radius);
                        this.radius = null;
                    }
                    if (!this.radius)
                    {
                        this.radius = new RadiusFire_mc();
                        this.radius.gotoAndStop(2);
                        this.arrow.alpha = 1;
                        this.radius.cont.stop();
                        var _loc_3:* = Main.mainClass.readXMLClass.listOfMoveFireXML[0] * 2;
                        this.radius.height = Main.mainClass.readXMLClass.listOfMoveFireXML[0] * 2;
                        this.radius.width = _loc_3;
                        this.radius.visible = false;
                        this.arrow.visible = false;
                        this.addChildAt(this.radius, 0);
                    }
                    this.myRadius = Main.mainClass.readXMLClass.listOfMoveFireXML[0];
                    this.myDamage = Main.mainClass.readXMLClass.listOfMoveFireXML[this.fireCount];
                }
                else if (this.fireCount == 0 && this.iceCount > 0 && this.stoneCount == 0 && this.levinCount == 0)
                {
                    if (this.radius && !(this.radius is RadiusIce_mc))
                    {
                        this.removeChild(this.radius);
                        this.radius = null;
                    }
                    if (!this.radius)
                    {
                        this.radius = new RadiusIce_mc();
                        this.radius.gotoAndStop(2);
                        this.arrow.alpha = 1;
                        this.radius.cont.stop();
                        var _loc_3:* = Main.mainClass.readXMLClass.listOfMoveIceXML[0] * 2;
                        this.radius.height = Main.mainClass.readXMLClass.listOfMoveIceXML[0] * 2;
                        this.radius.width = _loc_3;
                        this.radius.visible = false;
                        this.arrow.visible = false;
                        this.addChildAt(this.radius, 0);
                    }
                    this.myRadius = Main.mainClass.readXMLClass.listOfMoveIceXML[0];
                    this.myDamage = Main.mainClass.readXMLClass.listOfMoveIceXML[this.iceCount];
                }
                else if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount > 0 && this.levinCount == 0)
                {
                    if (this.radius && !(this.radius is RadiusStone_mc))
                    {
                        this.removeChild(this.radius);
                        this.radius = null;
                    }
                    if (!this.radius)
                    {
                        this.radius = new RadiusStone_mc();
                        this.radius.gotoAndStop(2);
                        this.arrow.alpha = 1;
                        this.radius.cont.stop();
                        var _loc_3:* = Main.mainClass.readXMLClass.listOfMoveStoneXML[0] * 2;
                        this.radius.height = Main.mainClass.readXMLClass.listOfMoveStoneXML[0] * 2;
                        this.radius.width = _loc_3;
                        this.radius.visible = false;
                        this.arrow.visible = false;
                        this.addChildAt(this.radius, 0);
                    }
                    this.myRadius = Main.mainClass.readXMLClass.listOfMoveStoneXML[0];
                    this.myDamage = Main.mainClass.readXMLClass.listOfMoveStoneXML[this.stoneCount];
                }
                else if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount > 0)
                {
                    if (this.radius && !(this.radius is RadiusLevin_mc))
                    {
                        this.removeChild(this.radius);
                        this.radius = null;
                    }
                    if (!this.radius)
                    {
                        this.radius = new RadiusLevin_mc();
                        this.radius.gotoAndStop(2);
                        this.arrow.alpha = 1;
                        this.radius.cont.stop();
                        var _loc_3:* = Main.mainClass.readXMLClass.listOfMoveLevinXML[0] * 2;
                        this.radius.height = Main.mainClass.readXMLClass.listOfMoveLevinXML[0] * 2;
                        this.radius.width = _loc_3;
                        this.radius.visible = false;
                        this.arrow.visible = false;
                        this.addChildAt(this.radius, 0);
                    }
                    this.myRadius = Main.mainClass.readXMLClass.listOfMoveLevinXML[0];
                    this.myDamage = Main.mainClass.readXMLClass.listOfMoveLevinXML[this.levinCount];
                }
                else
                {
                    if (this.radius)
                    {
                        this.removeChild(this.radius);
                        this.radius = null;
                    }
                    if (!this.radius)
                    {
                        this.radius = new RadiusGetAll_mc();
                        this.radius.gotoAndStop(2);
                        this.arrow.alpha = 1;
                        this.radius.cont.stop();
                        if (this.radius.cont1)
                        {
                            if (this.type == "holder")
                            {
                                this.radius.cont1.stop();
                                this.radius.cont2.stop();
                                this.radius.cont3.stop();
                                this.radius.cont1.visible = false;
                                this.radius.cont2.visible = false;
                                this.radius.cont3.visible = false;
                            }
                            else
                            {
                                this.radius.cont1.stop();
                                this.radius.cont2.stop();
                                this.radius.cont3.stop();
                                this.radius.cont1.visible = true;
                                if (this.getAllCount > 1)
                                {
                                    this.radius.cont2.visible = true;
                                }
                                else
                                {
                                    this.radius.cont2.visible = false;
                                }
                                if (this.getAllCount > 2)
                                {
                                    this.radius.cont3.visible = true;
                                }
                                else
                                {
                                    this.radius.cont3.visible = false;
                                }
                            }
                        }
                    }
                    this.myRadius = 0;
                    this.myDamage = 0;
                    if (this.type == "holder")
                    {
                        if (this.fireCount > 0)
                        {
                            if (this.myRadius < Main.mainClass.readXMLClass.listOfMoveFireXML[0])
                            {
                                this.myRadius = Main.mainClass.readXMLClass.listOfMoveFireXML[0];
                            }
                            this.myDamage = this.myDamage + Main.mainClass.readXMLClass.listOfMoveFireXML[this.fireCount];
                        }
                        if (this.iceCount > 0)
                        {
                            if (this.myRadius < Main.mainClass.readXMLClass.listOfMoveIceXML[0])
                            {
                                this.myRadius = Main.mainClass.readXMLClass.listOfMoveIceXML[0];
                            }
                            this.myDamage = this.myDamage + Main.mainClass.readXMLClass.listOfMoveIceXML[this.iceCount];
                        }
                        if (this.stoneCount > 0)
                        {
                            if (this.myRadius < Main.mainClass.readXMLClass.listOfMoveStoneXML[0])
                            {
                                this.myRadius = Main.mainClass.readXMLClass.listOfMoveStoneXML[0];
                            }
                            this.myDamage = this.myDamage + Main.mainClass.readXMLClass.listOfMoveStoneXML[this.stoneCount];
                        }
                        if (this.levinCount > 0)
                        {
                            if (this.myRadius < Main.mainClass.readXMLClass.listOfMoveLevinXML[0])
                            {
                                this.myRadius = Main.mainClass.readXMLClass.listOfMoveLevinXML[0];
                            }
                            this.myDamage = this.myDamage + Main.mainClass.readXMLClass.listOfMoveLevinXML[this.levinCount];
                        }
                    }
                    else if (this.type == "getAll")
                    {
                        if (this.myRadius < Main.mainClass.readXMLClass.listOfMoveFireXML[0])
                        {
                            this.myRadius = Main.mainClass.readXMLClass.listOfMoveFireXML[0];
                        }
                        if (this.myRadius < Main.mainClass.readXMLClass.listOfMoveIceXML[0])
                        {
                            this.myRadius = Main.mainClass.readXMLClass.listOfMoveIceXML[0];
                        }
                        if (this.myRadius < Main.mainClass.readXMLClass.listOfMoveStoneXML[0])
                        {
                            this.myRadius = Main.mainClass.readXMLClass.listOfMoveStoneXML[0];
                        }
                        if (this.myRadius < Main.mainClass.readXMLClass.listOfMoveLevinXML[0])
                        {
                            this.myRadius = Main.mainClass.readXMLClass.listOfMoveLevinXML[0];
                        }
                        if (this.getAllCount == 1)
                        {
                            this.myDamage = Main.mainClass.readXMLClass.getAllMultiply;
                        }
                        else if (this.getAllCount == 2)
                        {
                            this.myDamage = Main.mainClass.readXMLClass.getAllMultiply1;
                        }
                        else if (this.getAllCount == 3)
                        {
                            this.myDamage = Main.mainClass.readXMLClass.getAllMultiply2;
                        }
                    }
                    var _loc_3:* = this.myRadius * 2;
                    this.radius.height = this.myRadius * 2;
                    this.radius.width = _loc_3;
                    this.radius.visible = false;
                    this.arrow.visible = false;
                    this.addChildAt(this.radius, 0);
                }
            }
            return;
        }// end function

        public function retrieveGetSphere() : void
        {
            if (this.world.getSphere == this)
            {
                this.world.worldInterface.castRegime("off");
            }
            if (this.getAllCount == 0)
            {
                if (this.fireCount > 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount == 0)
                {
                    this.removeChild(this.container);
                    this.container = new MoveFire_mc();
                    this.container.stop();
                    this.container.cont.stop();
                    this.container.numTXT.text = this.fireCount;
                    if (this.fireCount == 1)
                    {
                        this.container.numTXT.visible = false;
                    }
                    var _loc_1:* = 0.6;
                    this.container.scaleY = 0.6;
                    this.container.scaleX = _loc_1;
                    this.addChild(this.container);
                }
                else if (this.fireCount == 0 && this.iceCount > 0 && this.stoneCount == 0 && this.levinCount == 0)
                {
                    this.removeChild(this.container);
                    this.container = new MoveIce_mc();
                    this.container.stop();
                    this.container.cont.stop();
                    this.container.numTXT.text = this.iceCount;
                    if (this.iceCount == 1)
                    {
                        this.container.numTXT.visible = false;
                    }
                    var _loc_1:* = 0.6;
                    this.container.scaleY = 0.6;
                    this.container.scaleX = _loc_1;
                    this.addChild(this.container);
                }
                else if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount > 0 && this.levinCount == 0)
                {
                    this.removeChild(this.container);
                    this.container = new MoveStone_mc();
                    this.container.stop();
                    this.container.cont.stop();
                    this.container.numTXT.text = this.stoneCount;
                    if (this.stoneCount == 1)
                    {
                        this.container.numTXT.visible = false;
                    }
                    var _loc_1:* = 0.6;
                    this.container.scaleY = 0.6;
                    this.container.scaleX = _loc_1;
                    this.addChild(this.container);
                }
                else if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount > 0)
                {
                    this.removeChild(this.container);
                    this.container = new MoveLevin_mc();
                    this.container.stop();
                    this.container.cont.stop();
                    this.container.numTXT.text = this.levinCount;
                    if (this.levinCount == 1)
                    {
                        this.container.numTXT.visible = false;
                    }
                    var _loc_1:* = 0.6;
                    this.container.scaleY = 0.6;
                    this.container.scaleX = _loc_1;
                    this.addChild(this.container);
                }
                else if (this.ownerType == "archive")
                {
                    if (this.fireCount > 0)
                    {
                        this.world.feature.getSphereBeat("fire", this.fireCount);
                        this.world.getSphere.x = this.x;
                        this.world.getSphere.y = this.y;
                        this.world.getSphere.retrieveGetSphere();
                        this.fireCount = 0;
                    }
                    if (this.iceCount > 0)
                    {
                        this.world.feature.getSphereBeat("ice", this.iceCount);
                        this.world.getSphere.x = this.x;
                        this.world.getSphere.y = this.y;
                        this.world.getSphere.retrieveGetSphere();
                        this.iceCount = 0;
                    }
                    if (this.stoneCount > 0)
                    {
                        this.world.feature.getSphereBeat("stone", this.stoneCount);
                        this.world.getSphere.x = this.x;
                        this.world.getSphere.y = this.y;
                        this.world.getSphere.retrieveGetSphere();
                        this.stoneCount = 0;
                    }
                    if (this.stoneCount > 0)
                    {
                        this.world.feature.getSphereBeat("stone", this.stoneCount);
                        this.world.getSphere.x = this.x;
                        this.world.getSphere.y = this.y;
                        this.world.getSphere.retrieveGetSphere();
                        this.stoneCount = 0;
                    }
                }
            }
            this.speedFrame = 5;
            this.speedX = (this.ownerPoint.x - this.x) / this.speedFrame;
            this.speedY = (this.ownerPoint.y - this.y) / this.speedFrame;
            this.radius.visible = false;
            this.arrow.visible = false;
            this.world.getSphere = null;
            if (this.towerArrow)
            {
                this.towerArrow.myTower.removeChild(this.towerArrow);
                this.towerArrow = null;
            }
            if (this.ownerType == "archive")
            {
                Sounds.instance.playSoundWithVol("snd_world_sphereGoToArchive", 0.9);
            }
            else
            {
                Sounds.instance.playSound("snd_world_sphereMoveBack");
            }
            if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount == 0 && this.getAllCount == 0)
            {
                this.world.removeChild(this);
            }
            else
            {
                this.world.listOfMoveSpheres.push(this);
            }
            this.world.worldInterface.autoguidersButtons();
            return;
        }// end function

        public function getSphereFromArchiveToTower() : void
        {
            if (this.world.towerMenu)
            {
                this.owner = this.world.towerMenu.myTower;
                this.ownerPoint = new Point(this.world.towerMenu.myTower.x, this.world.towerMenu.myTower.y + this.world.towerMenu.myTower.correctYGrPos);
            }
            else if (this.world.ultraTowerMenu)
            {
                this.owner = this.world.ultraTowerMenu.myTower;
                this.ownerPoint = new Point(this.world.ultraTowerMenu.myTower.x, this.world.ultraTowerMenu.myTower.y + this.world.ultraTowerMenu.myTower.correctYGrPos);
            }
            this.ownerType = "tower";
            if (this.fireCount > 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount == 0)
            {
                this.x = this.world.worldInterface.container.fireSphere.x;
                this.y = this.world.worldInterface.container.fireSphere.y;
            }
            else if (this.fireCount == 0 && this.iceCount > 0 && this.stoneCount == 0 && this.levinCount == 0)
            {
                this.x = this.world.worldInterface.container.iceSphere.x;
                this.y = this.world.worldInterface.container.iceSphere.y;
            }
            else if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount > 0 && this.levinCount == 0)
            {
                this.x = this.world.worldInterface.container.stoneSphere.x;
                this.y = this.world.worldInterface.container.stoneSphere.y;
            }
            else if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount > 0)
            {
                this.x = this.world.worldInterface.container.levinSphere.x;
                this.y = this.world.worldInterface.container.levinSphere.y;
            }
            else
            {
                this.x = this.world.worldInterface.container.getAll.x;
                this.y = this.world.worldInterface.container.getAll.y;
            }
            this.retrieveGetSphere();
            this.world.worldInterface.updateInfo();
            return;
        }// end function

        public function monitor() : void
        {
            if (this.listOfStack.length < 4 && this.getAllCount == 0)
            {
                if (this.world.worldInterface.fireCount > 0 || this.world.money >= int(this.world.worldInterface.container.buyFire.buyTXT.text) && this.world.worldInterface.container.fireSphere.visible)
                {
                    if (!this.world.worldInterface.castMask.fireCase.buttonMode)
                    {
                        this.world.worldInterface.castMask.fireCase.buttonMode = true;
                    }
                }
                else if (this.world.worldInterface.castMask.fireCase.buttonMode)
                {
                    this.world.worldInterface.castMask.fireCase.buttonMode = false;
                }
                if (this.world.worldInterface.iceCount > 0 || this.world.money >= int(this.world.worldInterface.container.buyIce.buyTXT.text) && this.world.worldInterface.container.iceSphere.visible)
                {
                    if (!this.world.worldInterface.castMask.iceCase.buttonMode)
                    {
                        this.world.worldInterface.castMask.iceCase.buttonMode = true;
                    }
                }
                else if (this.world.worldInterface.castMask.iceCase.buttonMode)
                {
                    this.world.worldInterface.castMask.iceCase.buttonMode = false;
                }
                if (this.world.worldInterface.stoneCount > 0 || this.world.money >= int(this.world.worldInterface.container.buyStone.buyTXT.text) && this.world.worldInterface.container.stoneSphere.visible)
                {
                    if (!this.world.worldInterface.castMask.stoneCase.buttonMode)
                    {
                        this.world.worldInterface.castMask.stoneCase.buttonMode = true;
                    }
                }
                else if (this.world.worldInterface.castMask.stoneCase.buttonMode)
                {
                    this.world.worldInterface.castMask.stoneCase.buttonMode = false;
                }
                if (this.world.worldInterface.levinCount > 0 || this.world.money >= int(this.world.worldInterface.container.buyLevin.buyTXT.text) && this.world.worldInterface.container.levinSphere.visible)
                {
                    if (!this.world.worldInterface.castMask.levinCase.buttonMode)
                    {
                        this.world.worldInterface.castMask.levinCase.buttonMode = true;
                    }
                }
                else if (this.world.worldInterface.castMask.levinCase.buttonMode)
                {
                    this.world.worldInterface.castMask.levinCase.buttonMode = false;
                }
            }
            else
            {
                if (this.world.worldInterface.castMask.fireCase.buttonMode)
                {
                    this.world.worldInterface.castMask.fireCase.buttonMode = false;
                }
                if (this.world.worldInterface.castMask.iceCase.buttonMode)
                {
                    this.world.worldInterface.castMask.iceCase.buttonMode = false;
                }
                if (this.world.worldInterface.castMask.stoneCase.buttonMode)
                {
                    this.world.worldInterface.castMask.stoneCase.buttonMode = false;
                }
                if (this.world.worldInterface.castMask.levinCase.buttonMode)
                {
                    this.world.worldInterface.castMask.levinCase.buttonMode = false;
                }
            }
            if (this.listOfStack.length == 0)
            {
                if (this.getAllCount < 3)
                {
                    if (!this.world.worldInterface.castMask.getAllCase.buttonMode)
                    {
                        this.world.worldInterface.castMask.getAllCase.buttonMode = true;
                    }
                }
                else if (this.world.worldInterface.castMask.getAllCase.buttonMode)
                {
                    this.world.worldInterface.castMask.getAllCase.buttonMode = false;
                }
            }
            else if (this.world.worldInterface.castMask.getAllCase.buttonMode)
            {
                this.world.worldInterface.castMask.getAllCase.buttonMode = false;
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.worldInterface.castRegime("off");
                this.world.removeChild(this);
                this.world.getSphere = null;
                if (this.towerArrow)
                {
                    this.towerArrow.myTower.removeChild(this.towerArrow);
                    this.towerArrow = null;
                }
                this.world.worldInterface.castMask.fireCase.buttonMode = false;
                this.world.worldInterface.castMask.iceCase.buttonMode = false;
                this.world.worldInterface.castMask.stoneCase.buttonMode = false;
                this.world.worldInterface.castMask.levinCase.buttonMode = false;
                this.world.worldInterface.castMask.getAllCase.buttonMode = false;
                this.world.worldInterface.updateInfo();
            }
            return;
        }// end function

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            return;
        }// end function

    }
}
