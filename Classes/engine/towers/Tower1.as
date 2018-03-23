package engine.towers
{
    import flash.events.*;

    public class Tower1 extends Tower
    {
        public var firstTowerMenuCounter:int = 8;

        public function Tower1()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            towerType = 1;
            correctYGrPos = -15;
            radius = Main.mainClass.readXMLClass.listOfSpheresRadius[0];
            slotsStack = [0, 1, 1, 1];
            container = new Tower1_mc();
            container.stop();
            container.towerCase.stop();
            container.blockTower.stop();
            container.boneBlock.stop();
            container.selectTower.stop();
            container.towerCase.buttonMode = true;
            container.blockTower.visible = false;
            container.boneBlock.visible = false;
            container.selectTower.visible = false;
            this.addChild(container);
            super.init(event);
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            if (!autoBuild)
            {
                Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
            }
            return;
        }// end function

        override public function update() : void
        {
            super.update();
            if (this.firstTowerMenuCounter > -1)
            {
                if (this.firstTowerMenuCounter > 0)
                {
                    var _loc_1:* = this;
                    var _loc_2:* = this.firstTowerMenuCounter - 1;
                    _loc_1.firstTowerMenuCounter = _loc_2;
                }
                else
                {
                    this.firstTowerMenuCounter = -1;
                    if (world.towerMenu)
                    {
                        world.towerMenu.closeMenu();
                    }
                    else if (world.ultraTowerMenu)
                    {
                        world.ultraTowerMenu.closeMenu();
                    }
                    world.towerMenu = new TowerMenu(this);
                    world.addChild(world.towerMenu);
                    world.towerMenu.monitor();
                    var _loc_1:* = true;
                    this.mouseChildren = true;
                    this.mouseEnabled = _loc_1;
                }
            }
            if (world.frameCounter % 2)
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
            if (spheresStack.length == 1)
            {
                if (container.sphere1.currentFrame < container.sphere1.totalFrames)
                {
                    container.sphere1.gotoAndStop((container.sphere1.currentFrame + 1));
                }
                else
                {
                    container.sphere1.gotoAndStop(1);
                }
                if (container.sphere1.bullet.currentFrame == 1)
                {
                    if (container.sphere1.bullet.cont.currentFrame < container.sphere1.bullet.cont.totalFrames)
                    {
                        container.sphere1.bullet.cont.gotoAndStop((container.sphere1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere1.bullet.currentFrame == 2)
                {
                    if (container.sphere1.bullet.cont.currentFrame < container.sphere1.bullet.cont.totalFrames)
                    {
                        container.sphere1.bullet.cont.gotoAndStop((container.sphere1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere1.bullet.currentFrame == 3)
                {
                    if (container.sphere1.bullet.cont.currentFrame < container.sphere1.bullet.cont.totalFrames)
                    {
                        container.sphere1.bullet.cont.gotoAndStop((container.sphere1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere1.bullet.currentFrame == 4)
                {
                    if (container.sphere1.bullet.cont.currentFrame < container.sphere1.bullet.cont.totalFrames)
                    {
                        container.sphere1.bullet.cont.gotoAndStop((container.sphere1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere1.bullet.cont.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

    }
}
