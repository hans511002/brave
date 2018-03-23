package engine.units
{
    import flash.events.*;

    public class Unit_8 extends Unit
    {

        public function Unit_8()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 8;
            container = new Unit8_mc();
            var _loc_2:* = 0.87;
            container.scaleY = 0.87;
            container.scaleX = _loc_2;
            super.init(event);
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!container.stoneDeath.visible && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container.cont.currentFrame < 11)
                    {
                        if (container.cont.currentFrame < 10)
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
                        container.cont.gotoAndStop(container.cont.currentFrame - 10);
                    }
                }
                else if (container.cont.currentFrame > 10)
                {
                    if (container.cont.currentFrame < container.cont.totalFrames)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.cont.gotoAndStop(11);
                    }
                }
                else
                {
                    container.cont.gotoAndStop(container.cont.currentFrame + 10);
                }
                if (moveFlag && !airFlag && !airShockFlag || container.currentFrame != 1)
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
            }
            super.animationHandler();
            return;
        }// end function

    }
}
