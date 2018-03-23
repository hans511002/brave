package engine.units
{
    import flash.events.*;

    public class Unit_14 extends Unit
    {

        public function Unit_14()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 14;
            moveFlag = false;
            container = new Unit14_mc();
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
                if (!airFlag && !airShockFlag)
                {
                    if (direction == "left" || direction == "right")
                    {
                        if (container.cont.currentFrame == 2)
                        {
                            container.cont.gotoAndStop(1);
                        }
                        if (container.currentFrame > 18)
                        {
                            container.gotoAndStop(container.currentFrame - 18);
                        }
                        else if (container.currentFrame < 18)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(1);
                        }
                        if (container.currentFrame < 9)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (!moveFlag)
                        {
                            moveFlag = true;
                        }
                    }
                    else if (direction == "up")
                    {
                        if (container.cont.currentFrame == 1)
                        {
                            container.cont.gotoAndStop(2);
                        }
                        if (container.currentFrame < 19)
                        {
                            container.gotoAndStop(container.currentFrame + 18);
                        }
                        else if (container.currentFrame < container.totalFrames)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(19);
                        }
                        if (container.currentFrame < 27)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (!moveFlag)
                        {
                            moveFlag = true;
                        }
                    }
                    else if (direction == "down")
                    {
                        if (container.cont.currentFrame == 2)
                        {
                            container.cont.gotoAndStop(1);
                        }
                        if (container.currentFrame < 19)
                        {
                            container.gotoAndStop(container.currentFrame + 18);
                        }
                        else if (container.currentFrame < container.totalFrames)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(19);
                        }
                        if (container.currentFrame < 27)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (!moveFlag)
                        {
                            moveFlag = true;
                        }
                    }
                }
                else if (direction == "left" || direction == "right")
                {
                    if (container.cont.currentFrame == 2)
                    {
                        container.cont.gotoAndStop(1);
                    }
                    if (container.currentFrame > 18)
                    {
                        container.gotoAndStop(container.currentFrame - 18);
                    }
                    else if (container.currentFrame != 1 && container.currentFrame < 18)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else if (container.currentFrame != 1)
                    {
                        container.gotoAndStop(1);
                    }
                    if (container.currentFrame < 9)
                    {
                        if (moveFlag)
                        {
                            moveFlag = false;
                        }
                    }
                    else if (!moveFlag)
                    {
                        moveFlag = true;
                    }
                }
                else if (direction == "up")
                {
                    if (container.cont.currentFrame == 1)
                    {
                        container.cont.gotoAndStop(2);
                    }
                    if (container.currentFrame < 19)
                    {
                        container.gotoAndStop(container.currentFrame + 18);
                    }
                    else if (container.currentFrame != 19 && container.currentFrame < container.totalFrames)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else if (container.currentFrame != 19)
                    {
                        container.gotoAndStop(19);
                    }
                    if (container.currentFrame < 27)
                    {
                        if (moveFlag)
                        {
                            moveFlag = false;
                        }
                    }
                    else if (!moveFlag)
                    {
                        moveFlag = true;
                    }
                }
                else if (direction == "down")
                {
                    if (container.cont.currentFrame == 2)
                    {
                        container.cont.gotoAndStop(1);
                    }
                    if (container.currentFrame < 19)
                    {
                        container.gotoAndStop(container.currentFrame + 18);
                    }
                    else if (container.currentFrame != 19 && container.currentFrame < container.totalFrames)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else if (container.currentFrame != 19)
                    {
                        container.gotoAndStop(19);
                    }
                    if (container.currentFrame < 27)
                    {
                        if (moveFlag)
                        {
                            moveFlag = false;
                        }
                    }
                    else if (!moveFlag)
                    {
                        moveFlag = true;
                    }
                }
            }
            super.animationHandler();
            return;
        }// end function

    }
}
