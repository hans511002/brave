package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel2 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var decorationFlag:int = 0;
        public var mouseDownCounter:int = 0;

        public function DecorationLevel2()
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
            if (this.decorationFlag > 0)
            {
                if (this.decorationFlag == 1)
                {
                    if (container.currentFrame < 23)
                    {
                        if (container.currentFrame != 17)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else if (counter < 60)
                        {
                            var _loc_2:* = counter + 1;
                            counter = _loc_2;
                        }
                        else
                        {
                            counter = 0;
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                    }
                    else
                    {
                        this.decorationFlag = 0;
                    }
                }
                else if (this.decorationFlag == 2)
                {
                    if (container.currentFrame < 24)
                    {
                        container.gotoAndStop(24);
                    }
                    if (container.currentFrame < 66)
                    {
                        if (container.currentFrame != 47)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else if (counter < 60)
                        {
                            var _loc_2:* = counter + 1;
                            counter = _loc_2;
                        }
                        else
                        {
                            counter = 0;
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                    }
                    else
                    {
                        this.decorationFlag = 0;
                    }
                }
                else if (this.decorationFlag == 3)
                {
                    if (container.currentFrame < 67)
                    {
                        container.gotoAndStop(67);
                    }
                    if (container.currentFrame < container.totalFrames)
                    {
                        if (container.currentFrame != 254)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                            if (container.currentFrame == 270)
                            {
                                world.achieveManage("achieve_dude_02");
                            }
                        }
                        else if (counter < 15)
                        {
                            var _loc_2:* = counter + 1;
                            counter = _loc_2;
                        }
                        else
                        {
                            counter = 0;
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                    }
                    else
                    {
                        this.decorationFlag = 0;
                    }
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
                }
                else if (this.mouseDownCounter == 2)
                {
                    this.decorationFlag = 2;
                }
                else if (this.mouseDownCounter == 3)
                {
                    this.decorationFlag = 3;
                    this.decorationCase.visible = false;
                }
            }
            return;
        }// end function

    }
}
