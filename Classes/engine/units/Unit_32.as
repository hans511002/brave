package engine.units
{
    import flash.events.*;

    public class Unit_32 extends Unit
    {
        public var distanceX:Number;
        public var distanceY:Number;
        public var counter:int = -1;
        public var firstView:Boolean;

        public function Unit_32()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 32;
            container = new Unit32_mc();
            var _loc_2:* = 0.81;
            container.scaleY = 0.81;
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
                        this.counter = 3;
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
                    if (!airFlag && !airShockFlag || container.currentFrame != 1)
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
            }
            super.animationHandler();
            return;
        }// end function

    }
}
