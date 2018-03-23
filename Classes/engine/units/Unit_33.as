package engine.units
{
    import flash.events.*;

    public class Unit_33 extends Unit
    {
        public var distanceX:Number;
        public var distanceY:Number;
        public var counter:int = -1;
        public var firstView:Boolean;

        public function Unit_33()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 33;
            container = new Unit33_mc();
            var _loc_2:* = 0.9;
            container.scaleY = 0.9;
            container.scaleX = _loc_2;
            super.init(event);
            return;
        }// end function

        override public function moveHandler() : void
        {
            if (readyDamage)
            {
                super.moveHandler();
            }
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!dead)
            {
                if (!readyDamage && !this.firstView)
                {
                    if (this.counter == -1)
                    {
                        this.counter = 5;
                        this.distanceX = (this_pt.x - this.x) / this.counter;
                        this.distanceY = (this_pt.y - this.y) / this.counter;
                    }
                    else if (this.counter > 0)
                    {
                        (this.counter - 1);
                        this.x = this.x + this.distanceX;
                        this.y = this.y + this.distanceY;
                        if (this.alpha < 1)
                        {
                            this.alpha = this.alpha + 0.3;
                        }
                    }
                    else
                    {
                        this.firstView = true;
                        this.x = this_pt.x;
                        this.y = this_pt.y;
                        this.alpha = 1;
                        readyDamage = true;
                        moveFlag = true;
                        this.moveHandler();
                    }
                }
                else if (!icemanFlag)
                {
                    if (container.cont.currentFrame < container.cont.totalFrames)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.cont.gotoAndStop(1);
                    }
                }
            }
            super.animationHandler();
            return;
        }// end function

    }
}
