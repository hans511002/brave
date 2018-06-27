package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel7 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var decorationFlag:int = 0;
        public var mouseDownCounter:int = 0;
        public var counter1:int = 0;

        public function DecorationLevel7()
        {
            container = world.level.decoration;
            this.decorationCase = world.level.decorationCase;
            container.stop();
            this.decorationCase.stop();
            this.decorationCase.setMouseEnabled(true);
            return;
        }// end function

        override public function update() : void
        {
            if (this.decorationFlag == 1)
            {
                if (container.currentFrame < 63)
                {
                    if (container.currentFrame != 57)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else if (this.counter1 < 60)
                    {
                        var _loc_1:* = this;
                        var _loc_2:* = this.counter1 + 1;
                        _loc_1.counter1 = _loc_2;
                    }
                    else
                    {
                        this.counter1 = 0;
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                }
                else
                {
                    this.decorationFlag = 0;
                    container.gotoAndStop(12);
                }
            }
            else if (this.decorationFlag == 2)
            {
                if (container.currentFrame < 64)
                {
                    container.gotoAndStop(64);
                }
                if (container.currentFrame < 116)
                {
                    if (container.currentFrame != 107)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else if (this.counter1 < 60)
                    {
                        var _loc_1:* = this;
                        var _loc_2:* = this.counter1 + 1;
                        _loc_1.counter1 = _loc_2;
                    }
                    else
                    {
                        this.counter1 = 0;
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                }
                else
                {
                    container.gotoAndStop(1);
                    this.decorationFlag = 0;
                }
            }
            else if (this.decorationFlag == 3)
            {
                if (container.currentFrame < 117)
                {
                    container.gotoAndStop(117);
                }
                if (container.currentFrame < container.totalFrames)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                    if (container.currentFrame == 174)
                    {
                        world.achieveManage("achieve_dude_07");
                    }
                }
            }
            else if (this.decorationFlag < 3)
            {
                if (container.currentFrame < 24)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else if (this.counter1 < 60)
                {
                    this.counter1++;
                }
                else
                {
                    this.counter1 = 1;
                    container.gotoAndStop(1);
                }
            }
            super.update();
            return;
        }// end function

        override public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "decorationCase")
            {
                this.mouseDownCounter++;
                if (this.mouseDownCounter == 1)
                {
                    this.decorationFlag = 1;
                    container.gotoAndStop(25);
                }
                else if (this.mouseDownCounter == 2)
                {
                    this.decorationFlag = 2;
                    container.gotoAndStop(86);
                }
                else if (this.mouseDownCounter == 3)
                {
                    this.mouseDownCounter = 0;
                    this.decorationFlag = 3;
                    container.gotoAndStop(138);
                    this.decorationCase.visible = false;
                }
            }
            return;
        }// end function

    }
}
