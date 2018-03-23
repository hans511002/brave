package engine.towers
{
    import flash.events.*;

    public class Tower4 extends Tower
    {

        public function Tower4()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            towerType = 4;
            correctYGrPos = -15;
            radius = Main.mainClass.readXMLClass.listOfSpheresRadius[3];
            slotsStack = [0, 0, 0, 0];
            container = new Tower4_mc();
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
            else if (spheresStack.length == 3)
            {
                if (container.sphere3_1.currentFrame < container.sphere3_1.totalFrames)
                {
                    container.sphere3_1.gotoAndStop((container.sphere3_1.currentFrame + 1));
                }
                else
                {
                    container.sphere3_1.gotoAndStop(1);
                }
                if (container.sphere3_1.bullet.currentFrame == 1)
                {
                    if (container.sphere3_1.bullet.cont.currentFrame < container.sphere3_1.bullet.cont.totalFrames)
                    {
                        container.sphere3_1.bullet.cont.gotoAndStop((container.sphere3_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere3_1.bullet.currentFrame == 2)
                {
                    if (container.sphere3_1.bullet.cont.currentFrame < container.sphere3_1.bullet.cont.totalFrames)
                    {
                        container.sphere3_1.bullet.cont.gotoAndStop((container.sphere3_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere3_1.bullet.currentFrame == 3)
                {
                    if (container.sphere3_1.bullet.cont.currentFrame < container.sphere3_1.bullet.cont.totalFrames)
                    {
                        container.sphere3_1.bullet.cont.gotoAndStop((container.sphere3_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere3_1.bullet.currentFrame == 4)
                {
                    if (container.sphere3_1.bullet.cont.currentFrame < container.sphere3_1.bullet.cont.totalFrames)
                    {
                        container.sphere3_1.bullet.cont.gotoAndStop((container.sphere3_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_1.bullet.cont.gotoAndStop(1);
                    }
                }
                if (container.sphere3_2.currentFrame < container.sphere3_2.totalFrames)
                {
                    container.sphere3_2.gotoAndStop((container.sphere3_2.currentFrame + 1));
                }
                else
                {
                    container.sphere3_2.gotoAndStop(1);
                }
                if (container.sphere3_2.bullet.currentFrame == 1)
                {
                    if (container.sphere3_2.bullet.cont.currentFrame < container.sphere3_2.bullet.cont.totalFrames)
                    {
                        container.sphere3_2.bullet.cont.gotoAndStop((container.sphere3_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_2.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere3_2.bullet.currentFrame == 2)
                {
                    if (container.sphere3_2.bullet.cont.currentFrame < container.sphere3_2.bullet.cont.totalFrames)
                    {
                        container.sphere3_2.bullet.cont.gotoAndStop((container.sphere3_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_2.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere3_2.bullet.currentFrame == 3)
                {
                    if (container.sphere3_2.bullet.cont.currentFrame < container.sphere3_2.bullet.cont.totalFrames)
                    {
                        container.sphere3_2.bullet.cont.gotoAndStop((container.sphere3_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_2.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere3_2.bullet.currentFrame == 4)
                {
                    if (container.sphere3_2.bullet.cont.currentFrame < container.sphere3_2.bullet.cont.totalFrames)
                    {
                        container.sphere3_2.bullet.cont.gotoAndStop((container.sphere3_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_2.bullet.cont.gotoAndStop(1);
                    }
                }
                if (container.sphere3_3.currentFrame < container.sphere3_3.totalFrames)
                {
                    container.sphere3_3.gotoAndStop((container.sphere3_3.currentFrame + 1));
                }
                else
                {
                    container.sphere3_3.gotoAndStop(1);
                }
                if (container.sphere3_3.bullet.currentFrame == 1)
                {
                    if (container.sphere3_3.bullet.cont.currentFrame < container.sphere3_3.bullet.cont.totalFrames)
                    {
                        container.sphere3_3.bullet.cont.gotoAndStop((container.sphere3_3.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_3.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere3_3.bullet.currentFrame == 2)
                {
                    if (container.sphere3_3.bullet.cont.currentFrame < container.sphere3_3.bullet.cont.totalFrames)
                    {
                        container.sphere3_3.bullet.cont.gotoAndStop((container.sphere3_3.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_3.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere3_3.bullet.currentFrame == 3)
                {
                    if (container.sphere3_3.bullet.cont.currentFrame < container.sphere3_3.bullet.cont.totalFrames)
                    {
                        container.sphere3_3.bullet.cont.gotoAndStop((container.sphere3_3.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_3.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere3_3.bullet.currentFrame == 4)
                {
                    if (container.sphere3_3.bullet.cont.currentFrame < container.sphere3_3.bullet.cont.totalFrames)
                    {
                        container.sphere3_3.bullet.cont.gotoAndStop((container.sphere3_3.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere3_3.bullet.cont.gotoAndStop(1);
                    }
                }
            }
            else if (spheresStack.length == 4)
            {
                if (container.sphere4_1.currentFrame < container.sphere4_1.totalFrames)
                {
                    container.sphere4_1.gotoAndStop((container.sphere4_1.currentFrame + 1));
                }
                else
                {
                    container.sphere4_1.gotoAndStop(1);
                }
                if (container.sphere4_1.bullet.currentFrame == 1)
                {
                    if (container.sphere4_1.bullet.cont.currentFrame < container.sphere4_1.bullet.cont.totalFrames)
                    {
                        container.sphere4_1.bullet.cont.gotoAndStop((container.sphere4_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_1.bullet.currentFrame == 2)
                {
                    if (container.sphere4_1.bullet.cont.currentFrame < container.sphere4_1.bullet.cont.totalFrames)
                    {
                        container.sphere4_1.bullet.cont.gotoAndStop((container.sphere4_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_1.bullet.currentFrame == 3)
                {
                    if (container.sphere4_1.bullet.cont.currentFrame < container.sphere4_1.bullet.cont.totalFrames)
                    {
                        container.sphere4_1.bullet.cont.gotoAndStop((container.sphere4_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_1.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_1.bullet.currentFrame == 4)
                {
                    if (container.sphere4_1.bullet.cont.currentFrame < container.sphere4_1.bullet.cont.totalFrames)
                    {
                        container.sphere4_1.bullet.cont.gotoAndStop((container.sphere4_1.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_1.bullet.cont.gotoAndStop(1);
                    }
                }
                if (container.sphere4_2.currentFrame < container.sphere4_2.totalFrames)
                {
                    container.sphere4_2.gotoAndStop((container.sphere4_2.currentFrame + 1));
                }
                else
                {
                    container.sphere4_2.gotoAndStop(1);
                }
                if (container.sphere4_2.bullet.currentFrame == 1)
                {
                    if (container.sphere4_2.bullet.cont.currentFrame < container.sphere4_2.bullet.cont.totalFrames)
                    {
                        container.sphere4_2.bullet.cont.gotoAndStop((container.sphere4_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_2.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_2.bullet.currentFrame == 2)
                {
                    if (container.sphere4_2.bullet.cont.currentFrame < container.sphere4_2.bullet.cont.totalFrames)
                    {
                        container.sphere4_2.bullet.cont.gotoAndStop((container.sphere4_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_2.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_2.bullet.currentFrame == 3)
                {
                    if (container.sphere4_2.bullet.cont.currentFrame < container.sphere4_2.bullet.cont.totalFrames)
                    {
                        container.sphere4_2.bullet.cont.gotoAndStop((container.sphere4_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_2.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_2.bullet.currentFrame == 4)
                {
                    if (container.sphere4_2.bullet.cont.currentFrame < container.sphere4_2.bullet.cont.totalFrames)
                    {
                        container.sphere4_2.bullet.cont.gotoAndStop((container.sphere4_2.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_2.bullet.cont.gotoAndStop(1);
                    }
                }
                if (container.sphere4_3.currentFrame < container.sphere4_3.totalFrames)
                {
                    container.sphere4_3.gotoAndStop((container.sphere4_3.currentFrame + 1));
                }
                else
                {
                    container.sphere4_3.gotoAndStop(1);
                }
                if (container.sphere4_3.bullet.currentFrame == 1)
                {
                    if (container.sphere4_3.bullet.cont.currentFrame < container.sphere4_3.bullet.cont.totalFrames)
                    {
                        container.sphere4_3.bullet.cont.gotoAndStop((container.sphere4_3.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_3.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_3.bullet.currentFrame == 2)
                {
                    if (container.sphere4_3.bullet.cont.currentFrame < container.sphere4_3.bullet.cont.totalFrames)
                    {
                        container.sphere4_3.bullet.cont.gotoAndStop((container.sphere4_3.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_3.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_3.bullet.currentFrame == 3)
                {
                    if (container.sphere4_3.bullet.cont.currentFrame < container.sphere4_3.bullet.cont.totalFrames)
                    {
                        container.sphere4_3.bullet.cont.gotoAndStop((container.sphere4_3.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_3.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_3.bullet.currentFrame == 4)
                {
                    if (container.sphere4_3.bullet.cont.currentFrame < container.sphere4_3.bullet.cont.totalFrames)
                    {
                        container.sphere4_3.bullet.cont.gotoAndStop((container.sphere4_3.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_3.bullet.cont.gotoAndStop(1);
                    }
                }
                if (container.sphere4_4.currentFrame < container.sphere4_4.totalFrames)
                {
                    container.sphere4_4.gotoAndStop((container.sphere4_4.currentFrame + 1));
                }
                else
                {
                    container.sphere4_4.gotoAndStop(1);
                }
                if (container.sphere4_4.bullet.currentFrame == 1)
                {
                    if (container.sphere4_4.bullet.cont.currentFrame < container.sphere4_4.bullet.cont.totalFrames)
                    {
                        container.sphere4_4.bullet.cont.gotoAndStop((container.sphere4_4.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_4.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_4.bullet.currentFrame == 2)
                {
                    if (container.sphere4_4.bullet.cont.currentFrame < container.sphere4_4.bullet.cont.totalFrames)
                    {
                        container.sphere4_4.bullet.cont.gotoAndStop((container.sphere4_4.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_4.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_4.bullet.currentFrame == 3)
                {
                    if (container.sphere4_4.bullet.cont.currentFrame < container.sphere4_4.bullet.cont.totalFrames)
                    {
                        container.sphere4_4.bullet.cont.gotoAndStop((container.sphere4_4.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_4.bullet.cont.gotoAndStop(1);
                    }
                }
                else if (container.sphere4_4.bullet.currentFrame == 4)
                {
                    if (container.sphere4_4.bullet.cont.currentFrame < container.sphere4_4.bullet.cont.totalFrames)
                    {
                        container.sphere4_4.bullet.cont.gotoAndStop((container.sphere4_4.bullet.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.sphere4_4.bullet.cont.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

    }
}
