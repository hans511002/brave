package engine.units
{
    import flash.events.*;

    public class Unit_6 extends Unit
    {

        public function Unit_6()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 6;
            container = new Unit6_mc();
            var _loc_2:* = 0.85;
            container.scaleY = 0.85;
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
                        if (container.currentFrame > 17)
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
                        else if (container.currentFrame < 17)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container.currentFrame != 18)
                {
                    if (container.currentFrame < 18)
                    {
                        if (container.currentFrame < 17)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(18);
                        }
                    }
                    else if (container.currentFrame < container.totalFrames)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else
                    {
                        container.gotoAndStop(18);
                    }
                }
            }
            super.animationHandler();
            return;
        }// end function

    }
}
