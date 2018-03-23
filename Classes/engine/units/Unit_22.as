package engine.units
{
    import flash.display.*;
    import flash.events.*;

    public class Unit_22 extends Unit
    {
        public var blockTowerRadius:int;
        public var blockRadiusGr:MovieClip;
        public var greenFlag:Boolean;
        public var testTarget:Object;

        public function Unit_22()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 22;
            this.blockTowerRadius = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            container = new Unit22_mc();
            var _loc_2:* = 0.85;
            container.scaleY = 0.85;
            container.scaleX = _loc_2;
            super.init(event);
            this.blockRadiusGr = new BlockRadius_mc();
            this.blockRadiusGr.stop();
            this.blockRadiusGr.x = this.x;
            this.blockRadiusGr.y = this.y;
            this.blockRadiusGr.width = this.blockTowerRadius * 2;
            this.blockRadiusGr.scaleY = this.blockRadiusGr.scaleX;
            var _loc_2:* = false;
            this.blockRadiusGr.mouseChildren = false;
            this.blockRadiusGr.mouseEnabled = _loc_2;
            this.blockRadiusGr.visible = false;
            world.addChild(this.blockRadiusGr);
            world.listOfIndexes0.push(this.blockRadiusGr);
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!dead)
            {
                if (atStage && !icemanFlag && !teleportFlag)
                {
                    if (world.frameCounter == 10 || world.frameCounter == 20 || world.frameCounter == 30)
                    {
                        i = 0;
                        while (i < world.listOfTowers.length)
                        {
                            
                            if (!world.listOfTowers[i].container.blockTower.visible && !world.listOfTowers[i].container.boneBlock.visible)
                            {
                                this.testTarget = world.listOfTowers[i].this_pt;
                                this.scanAtRadius();
                                if (this.greenFlag)
                                {
                                    world.listOfTowers[i].container.blockTower.visible = true;
                                    world.listOfTowers[i].blockTowerFlag = true;
                                    if (world.exchange)
                                    {
                                        if (world.exchange.myTower == world.listOfTowers[i])
                                        {
                                            world.exchange.kill();
                                        }
                                    }
                                    var _loc_1:* = false;
                                    world.listOfTowers[i].mouseChildren = false;
                                    world.listOfTowers[i].mouseEnabled = _loc_1;
                                    if (world.towerMenu)
                                    {
                                        if (world.towerMenu.myTower == world.listOfTowers[i])
                                        {
                                            world.towerMenu.closeMenu();
                                        }
                                    }
                                    else if (world.ultraTowerMenu)
                                    {
                                        if (world.ultraTowerMenu.myTower == world.listOfTowers[i])
                                        {
                                            world.ultraTowerMenu.closeMenu();
                                        }
                                    }
                                }
                            }
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                    }
                    if (direction != "up")
                    {
                        if (container.cont.currentFrame < 21)
                        {
                            if (container.cont.currentFrame < 20)
                            {
                                container.cont.gotoAndStop((container.cont.currentFrame + 1));
                            }
                            else
                            {
                                container.cont.gotoAndStop(1);
                            }
                        }
                        else
                        {
                            container.cont.gotoAndStop(container.cont.currentFrame - 20);
                        }
                    }
                    else if (container.cont.currentFrame > 20)
                    {
                        if (container.cont.currentFrame < container.cont.totalFrames)
                        {
                            container.cont.gotoAndStop((container.cont.currentFrame + 1));
                        }
                        else
                        {
                            container.cont.gotoAndStop(21);
                        }
                    }
                    else
                    {
                        container.cont.gotoAndStop(container.cont.currentFrame + 20);
                    }
                    if (direction == "left" || direction == "right")
                    {
                        if (!airFlag && !airShockFlag || container.currentFrame != 1)
                        {
                            if (container.currentFrame > 20)
                            {
                                if (container.currentFrame < container.totalFrames)
                                {
                                    container.gotoAndStop((container.currentFrame + 1));
                                }
                                else
                                {
                                    container.gotoAndStop(1);
                                }
                            }
                            else if (container.currentFrame < 20)
                            {
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                            else
                            {
                                container.gotoAndStop(1);
                            }
                        }
                    }
                    else if (!airFlag && !airShockFlag || container.currentFrame != 21)
                    {
                        if (container.currentFrame > 20)
                        {
                            if (container.currentFrame < container.totalFrames)
                            {
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                            else
                            {
                                container.gotoAndStop(21);
                            }
                        }
                        else if (container.currentFrame < 20)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(21);
                        }
                    }
                }
                if (atStage && !icemanFlag && !teleportFlag)
                {
                    if (!this.blockRadiusGr.visible)
                    {
                        this.blockRadiusGr.visible = true;
                    }
                    else if (this.blockRadiusGr.currentFrame < this.blockRadiusGr.totalFrames)
                    {
                        this.blockRadiusGr.gotoAndStop((this.blockRadiusGr.currentFrame + 1));
                    }
                    else
                    {
                        this.blockRadiusGr.gotoAndStop(1);
                    }
                }
                else if (this.blockRadiusGr.visible)
                {
                    this.blockRadiusGr.visible = false;
                }
                this.blockRadiusGr.x = this.x;
                this.blockRadiusGr.y = this.y;
            }
            super.animationHandler();
            return;
        }// end function

        public function scanAtRadius() : void
        {
            this.greenFlag = false;
            tempObject = this.blockTowerRadius - this.blockTowerRadius * (1 - world.scaleRadius);
            if ((this.testTarget.x - this.x) * (this.testTarget.x - this.x) / (this.blockTowerRadius * this.blockTowerRadius) + (this.testTarget.y - this.y) * (this.testTarget.y - this.y) / (tempObject * tempObject) <= 1)
            {
                this.greenFlag = true;
            }
            return;
        }// end function

        override public function kill() : void
        {
            if (!dead)
            {
                i = 0;
                while (i < world.listOfIndexes0.length)
                {
                    
                    if (world.listOfIndexes0[i] == this.blockRadiusGr)
                    {
                        world.removeChild(this.blockRadiusGr);
                        world.listOfIndexes0.splice(i, 1);
                        break;
                    }
                    var _loc_2:* = i + 1;
                    i = _loc_2;
                }
            }
            super.kill();
            return;
        }// end function

    }
}
