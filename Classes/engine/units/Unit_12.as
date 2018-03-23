package engine.units
{
    import flash.events.*;

    public class Unit_12 extends Unit
    {

        public function Unit_12()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 12;
            container = new Unit12_mc();
            var _loc_2:* = 0.8;
            container.scaleY = 0.8;
            container.scaleX = _loc_2;
            super.init(event);
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!dead && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container.cont.currentFrame == 2)
                    {
                        container.cont.gotoAndStop(1);
                    }
                }
                else if (container.cont.currentFrame == 1)
                {
                    container.cont.gotoAndStop(2);
                }
                if (direction == "left" || direction == "right")
                {
                    if (!airFlag && !airShockFlag || container.currentFrame != 1)
                    {
                        if (container.currentFrame > 26)
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
                        else if (container.currentFrame < 26)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container.currentFrame != 27)
                {
                    if (container.currentFrame < 27)
                    {
                        if (container.currentFrame < 26)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(27);
                        }
                    }
                    else if (container.currentFrame < container.totalFrames)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else
                    {
                        container.gotoAndStop(27);
                    }
                }
            }
            super.animationHandler();
            return;
        }// end function

    }
}
