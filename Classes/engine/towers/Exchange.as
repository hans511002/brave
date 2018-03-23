package engine.towers
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;

    public class Exchange extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:MovieClip;
        public var graphicAtMyTower:MovieClip;
        public var dead:Boolean;
        public var world:World;
        public var myTower:Tower;
        public var atTower:Boolean;

        public function Exchange(param1:Tower)
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.myTower = param1;
            var _loc_2:* = false;
            this.myTower.mouseChildren = false;
            this.myTower.mouseEnabled = _loc_2;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.world = Main.mainClass.worldClass;
            this.graphicAtMyTower = new Exchange_mc();
            this.graphicAtMyTower.stop();
            this.graphicAtMyTower.x = this.myTower.x;
            this.graphicAtMyTower.y = this.myTower.y;
            var _loc_2:* = false;
            this.graphicAtMyTower.mouseChildren = false;
            this.graphicAtMyTower.mouseEnabled = _loc_2;
            this.world.addChild(this.graphicAtMyTower);
            this.container = new Exchange1_mc();
            this.container.stop();
            this.container.cross.stop();
            this.addChild(this.container);
            this.x = this.world.mouseX;
            this.y = this.world.mouseY;
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            if (this.world.towerMenu)
            {
                this.world.towerMenu.closeMenu();
            }
            else if (this.world.ultraTowerMenu)
            {
                this.world.ultraTowerMenu.closeMenu();
            }
            this.i = 0;
            while (this.i < this.world.listOfTowers.length)
            {
                
                if (this.world.listOfTowers[this.i].towerType < 5)
                {
                    if (this.world.listOfTowers[this.i] != this.myTower && !this.world.listOfTowers[this.i].blockTowerFlag)
                    {
                        if (this.myTower.spheresStack.length > 0 || this.world.listOfTowers[this.i].spheresStack.length > 0)
                        {
                            this.world.listOfTowers[this.i].exchangeFlag = true;
                            this.world.listOfTowers[this.i].container.selectTower.visible = true;
                        }
                    }
                    else
                    {
                        this.myTower.container.selectTower.visible = false;
                    }
                }
                var _loc_2:* = this;
                var _loc_3:* = this.i + 1;
                _loc_2.i = _loc_3;
            }
            this.world.manageMouse("hide");
            return;
        }// end function

        public function update() : void
        {
            this.x = this.world.mouseX;
            this.y = this.world.mouseY;
            if (this.atTower)
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
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (param1.target.name == "towerCase" && param1.target.buttonMode)
            {
                this.tempObject = param1.target.parent.parent;
                if (this.tempObject.towerType < 5)
                {
                    if (this.tempObject.container.selectTower.visible)
                    {
                        if (!this.atTower)
                        {
                            this.atTower = true;
                            this.container.cross.visible = false;
                        }
                    }
                    else if (this.atTower)
                    {
                        this.atTower = false;
                        this.container.cross.visible = true;
                    }
                }
                else if (this.atTower)
                {
                    this.atTower = false;
                    this.container.cross.visible = true;
                }
            }
            else if (this.atTower)
            {
                this.atTower = false;
                this.container.cross.visible = true;
            }
            return;
        }// end function

        public function mouseDownHandler(param1) : void
        {
            this.kill();
            return;
        }// end function

        public function mouseUpHandler(param1) : void
        {
            return;
        }// end function

        public function rightMouseDownHandler(param1) : void
        {
            if (param1.target.name == "towerCase" && param1.target.buttonMode)
            {
                this.tempObject = param1.target.parent.parent;
                if (this.tempObject.towerType < 5)
                {
                    this.i = 0;
                    while (this.i < this.world.listOfMoveSpheres.length)
                    {
                        
                        if (this.world.listOfMoveSpheres[this.i].speedFrame >= 0)
                        {
                            this.world.listOfMoveSpheres[this.i].speedFrame = 0;
                        }
                        var _loc_2:* = this;
                        var _loc_3:* = this.i + 1;
                        _loc_2.i = _loc_3;
                    }
                    this.world.feature.listOfMoveSpheres();
                    if (this.myTower.spheresStack.length > 0)
                    {
                        while (this.myTower.spheresStack.length > 0)
                        {
                            
                            if (this.myTower.spheresStack[0] == "fire")
                            {
                                this.myTower.towerGetSphereManage("get", "fire");
                                continue;
                            }
                            if (this.myTower.spheresStack[0] == "ice")
                            {
                                this.myTower.towerGetSphereManage("get", "ice");
                                continue;
                            }
                            if (this.myTower.spheresStack[0] == "stone")
                            {
                                this.myTower.towerGetSphereManage("get", "stone");
                                continue;
                            }
                            if (this.myTower.spheresStack[0] == "levin")
                            {
                                this.myTower.towerGetSphereManage("get", "levin");
                            }
                        }
                        this.world.getSphere.x = this.myTower.this_pt.x;
                        this.world.getSphere.y = this.myTower.this_pt.y;
                        this.world.getSphere.owner = this.tempObject;
                        this.world.getSphere.ownerType = "tower";
                        this.world.getSphere.ownerPoint = this.tempObject.this_pt;
                        this.world.getSphere.retrieveGetSphere();
                    }
                    if (this.tempObject.spheresStack.length > 0)
                    {
                        while (this.tempObject.spheresStack.length > 0)
                        {
                            
                            if (this.tempObject.spheresStack[0] == "fire")
                            {
                                this.tempObject.towerGetSphereManage("get", "fire");
                                continue;
                            }
                            if (this.tempObject.spheresStack[0] == "ice")
                            {
                                this.tempObject.towerGetSphereManage("get", "ice");
                                continue;
                            }
                            if (this.tempObject.spheresStack[0] == "stone")
                            {
                                this.tempObject.towerGetSphereManage("get", "stone");
                                continue;
                            }
                            if (this.tempObject.spheresStack[0] == "levin")
                            {
                                this.tempObject.towerGetSphereManage("get", "levin");
                            }
                        }
                        this.world.getSphere.x = this.tempObject.this_pt.x;
                        this.world.getSphere.y = this.tempObject.this_pt.y;
                        this.world.getSphere.owner = this.myTower;
                        this.world.getSphere.ownerType = "tower";
                        this.world.getSphere.ownerPoint = this.myTower.this_pt;
                        this.world.getSphere.retrieveGetSphere();
                    }
                }
            }
            this.kill();
            this.world.mouseMoveHandler(param1);
            return;
        }// end function

        public function rightMouseUpHandler(param1) : void
        {
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                var _loc_1:* = true;
                this.myTower.mouseChildren = true;
                this.myTower.mouseEnabled = _loc_1;
                this.i = 0;
                while (this.i < this.world.listOfTowers.length)
                {
                    
                    if (this.world.listOfTowers[this.i].towerType < 5)
                    {
                        if (this.world.listOfTowers[this.i] != this.myTower)
                        {
                            this.world.listOfTowers[this.i].exchangeFlag = false;
                            this.world.listOfTowers[this.i].container.selectTower.visible = false;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
                this.world.removeChild(this.graphicAtMyTower);
                this.graphicAtMyTower = null;
                this.world.removeChild(this.world.exchange);
                this.world.exchange = null;
                this.world.manageMouse("show");
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
