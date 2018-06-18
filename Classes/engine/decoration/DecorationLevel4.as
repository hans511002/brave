package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel4 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var decorationFlag:int = 0;
        public var mouseDownCounter:int = 0;

        public function DecorationLevel4()
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
                    if (container.currentFrame < 299)
                    {
                        if (container.currentFrame != 253)
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
                        container.gotoAndStop(1);
                    }
                }
                else if (this.decorationFlag == 2)
                {
                    if (container.currentFrame < 351)
                    {
                        if (container.currentFrame != 333 && container.currentFrame != 347)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else if (container.currentFrame == 333)
                        {
                            if (counter < 30)
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
                        else if (container.currentFrame == 347)
                        {
                            if (counter < 60)
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
                    }
                    else
                    {
                        this.decorationFlag = 0;
                        container.gotoAndStop(1);
                    }
                }
                else if (this.decorationFlag == 3)
                {
                    if (container.currentFrame < container.totalFrames)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                        if (container.currentFrame == 383)
                        {
                            world.achieveManage("achieve_dude_04");
                        }
                    }
                    else
                    {
                        this.decorationFlag = 0;
                        container.gotoAndStop(1);
                        this.decorationCase.visible = true;
                    }
                }
            }
            else if (container.currentFrame < 98)
            {
                container.gotoAndStop((container.currentFrame + 1));
            }
            else
            {
                container.gotoAndStop(1);
            }
            super.update();
            return;
        }// end function

        override public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "decorationCase")
            {
                (this.mouseDownCounter + 1);
                if (this.mouseDownCounter == 1)
                {
                    this.decorationFlag = 1;
                    container.gotoAndStop(226);
                }
                else if (this.mouseDownCounter == 2)
                {
                    this.decorationFlag = 2;
                    container.gotoAndStop(300);
                }
                else if (this.mouseDownCounter == 3)
                {
                    this.mouseDownCounter = 0;
                    this.decorationFlag = 3;
                    container.gotoAndStop(352);
                    this.decorationCase.visible = false;
                }
            }
            return;
        }// end function

    }
}
