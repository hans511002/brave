package engine.towers
{
    import flash.events.*;

    public class Tower2 extends Tower
    {

        public function Tower2()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            towerType = 2;
            correctYGrPos = -15;
            radius = Main.mainClass.readXMLClass.listOfSpheresRadius[1];
            slotsStack = [0, 0, 1, 1];
            container = new Tower2_mc();
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
            if (!autoBuild)
            {
                Sounds.instance.playSoundWithVol("snd_tower_build1", 0.9);
            }
            return;
        }// end function

        override public function update() : void
        {
            super.update();
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
            else if (spheresStack.length == 2)
            {
                if (container.sphere2_1.currentFrame < container.sphere2_1.totalFrames)
                {
                    container.sphere2_1.gotoAndStop((container.sphere2_1.currentFrame + 1));
                }
                else
                {
                    container.sphere2_1.gotoAndStop(1);
                }
                if (container.sphere2_1.bullet.currentFrame == 1)
                {
                    if (container.sphere2_1.bullet.cont.currentFrame < container.sphere2_1.bullet.cont.totalFrames)
                    {
                        container.sphere2_1.bullet.cont.gotoAndStop((container.sphere2_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere2_1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere2_1.bullet.currentFrame == 2)
                {
                    if (container.sphere2_1.bullet.cont.currentFrame < container.sphere2_1.bullet.cont.totalFrames)
                    {
                        container.sphere2_1.bullet.cont.gotoAndStop((container.sphere2_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere2_1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere2_1.bullet.currentFrame == 3)
                {
                    if (container.sphere2_1.bullet.cont.currentFrame < container.sphere2_1.bullet.cont.totalFrames)
                    {
                        container.sphere2_1.bullet.cont.gotoAndStop((container.sphere2_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere2_1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere2_1.bullet.currentFrame == 4)
                {
                    if (container.sphere2_1.bullet.cont.currentFrame < container.sphere2_1.bullet.cont.totalFrames)
                    {
                        container.sphere2_1.bullet.cont.gotoAndStop((container.sphere2_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere2_1.bullet.cont.gotoAndStop(1);
                    }
                }
                if (container.sphere2_2.currentFrame < container.sphere2_2.totalFrames)
                {
                    container.sphere2_2.gotoAndStop((container.sphere2_2.currentFrame + 1));
                }
                else
                {
                    container.sphere2_2.gotoAndStop(1);
                }
                if (container.sphere2_2.bullet.currentFrame == 1)
                {
                    if (container.sphere2_2.bullet.cont.currentFrame < container.sphere2_2.bullet.cont.totalFrames)
                    {
                        container.sphere2_2.bullet.cont.gotoAndStop((container.sphere2_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere2_2.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere2_2.bullet.currentFrame == 2)
                {
                    if (container.sphere2_2.bullet.cont.currentFrame < container.sphere2_2.bullet.cont.totalFrames)
                    {
                        container.sphere2_2.bullet.cont.gotoAndStop((container.sphere2_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere2_2.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere2_2.bullet.currentFrame == 3)
                {
                    if (container.sphere2_2.bullet.cont.currentFrame < container.sphere2_2.bullet.cont.totalFrames)
                    {
                        container.sphere2_2.bullet.cont.gotoAndStop((container.sphere2_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere2_2.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere2_2.bullet.currentFrame == 4)
                {
                    if (container.sphere2_2.bullet.cont.currentFrame < container.sphere2_2.bullet.cont.totalFrames)
                    {
                        container.sphere2_2.bullet.cont.gotoAndStop((container.sphere2_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere2_2.bullet.cont.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

    }
}
