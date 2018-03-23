package engine.units
{
    import flash.events.*;

    public class Unit_7 extends Unit
    {

        public function Unit_7()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 7;
            container = new Unit7_mc();
            var _loc_2:* = 0.9;
            container.scaleY = 0.9;
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
                    if (container.cont.currentFrame < 31)
                    {
                        if (container.cont.currentFrame < 30)
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
                        container.cont.gotoAndStop(container.cont.currentFrame - 30);
                    }
                }
                else if (container.cont.currentFrame > 30)
                {
                    if (container.cont.currentFrame < container.cont.totalFrames)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.cont.gotoAndStop(31);
                    }
                }
                else
                {
                    container.cont.gotoAndStop(container.cont.currentFrame + 30);
                }
                if (direction == "left" || direction == "right")
                {
                    if (!airFlag && !airShockFlag || container.currentFrame != 1)
                    {
                        if (container.currentFrame > 19)
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
                        else if (container.currentFrame < 19)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container.currentFrame != 20)
                {
                    if (container.currentFrame < 20)
                    {
                        if (container.currentFrame < 19)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(20);
                        }
                    }
                    else if (container.currentFrame < container.totalFrames)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else
                    {
                        container.gotoAndStop(20);
                    }
                }
            }
            super.animationHandler();
            return;
        }// end function

    }
}
