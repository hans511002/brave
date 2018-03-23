package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel5 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var decorationFlag:int = 0;
        public var mouseDownCounter:int = 0;

        public function DecorationLevel5()
        {
            container = world.level.decoration;
            this.decorationCase = world.level.decorationCase;
            container.stop();
            this.decorationCase.stop();
            this.decorationCase.buttonMode = true;
            return;
        }// end function

        override public function update() : void
        {
            if (this.decorationFlag > 0)
            {
                if (this.decorationFlag == 1)
                {
                    if (container.currentFrame < 31)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else
                    {
                        this.decorationFlag = 0;
                        this.decorationCase.visible = true;
                    }
                }
                else if (this.decorationFlag == 2)
                {
                    if (container.currentFrame < 32)
                    {
                        container.gotoAndStop(32);
                    }
                    if (container.currentFrame < 350)
                    {
                        if (container.currentFrame != 340)
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
                        container.gotoAndStop(32);
                    }
                }
                else if (this.decorationFlag == 3)
                {
                    if (container.currentFrame < 351)
                    {
                        container.gotoAndStop(351);
                    }
                    if (container.currentFrame < 409)
                    {
                        if (container.currentFrame != 402)
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
                        container.gotoAndStop(32);
                    }
                }
                else if (this.decorationFlag == 4)
                {
                    if (container.currentFrame < 410)
                    {
                        container.gotoAndStop(410);
                    }
                    if (container.currentFrame < container.totalFrames)
                    {
                        if (container.currentFrame != 490 && container.currentFrame != 497)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                            if (container.currentFrame == 513)
                            {
                                world.achieveManage("achieve_dude_05");
                            }
                        }
                        else if (container.currentFrame == 490 || container.currentFrame == 497)
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
                    }
                    else
                    {
                        this.decorationFlag = 0;
                    }
                }
            }
            else if (this.mouseDownCounter > 0)
            {
                if (container.currentFrame < 313)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(32);
                }
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
                    this.decorationCase.visible = false;
                }
                else if (this.mouseDownCounter == 2)
                {
                    this.decorationFlag = 2;
                    container.gotoAndStop(314);
                }
                else if (this.mouseDownCounter == 3)
                {
                    this.decorationFlag = 3;
                    container.gotoAndStop(383);
                }
                else if (this.mouseDownCounter == 4)
                {
                    this.mouseDownCounter = 0;
                    this.decorationFlag = 4;
                    container.gotoAndStop(469);
                    this.decorationCase.visible = false;
                }
            }
            return;
        }// end function

    }
}
