package engine.units
{
    import flash.events.*;

    public class Unit_4 extends Unit
    {

        public function Unit_4()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 4;
            container = new Unit4_mc();
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
                    if (container.cont.currentFrame == 2)
                    {
                        container.cont.gotoAndStop(1);
                    }
                }
                else if (container.cont.currentFrame == 1)
                {
                    container.cont.gotoAndStop(2);
                }
                if (!airFlag && !airShockFlag)
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
