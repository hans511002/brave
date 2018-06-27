package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel6 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var decorationFlag:int = 0;
        public var mouseDownCounter:int = 0;

        public function DecorationLevel6()
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
                    if (container.currentFrame < 75)
                    {
                        if (container.currentFrame == 68)
                        {
                            if (counter < 60)
                            {
                                counter++;
                            }
                            else
                            {
                                counter = 0;
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                        }
                        else
                        {
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
                    if (container.currentFrame < 76)
                    {
                        container.gotoAndStop(76);
                    }
                    if (container.currentFrame < 100)
                    {
                        if (container.currentFrame == 94)
                        {
                            if (counter < 60)
                            {
                                counter++;
                            }
                            else
                            {
                                counter = 0;
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                        }
                        else
                        {
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
                    if (container.currentFrame < 101)
                    {
                        container.gotoAndStop(101);
                    }
                    if (container.currentFrame < container.totalFrames)
                    {
                        if (container.currentFrame == 206)
                        {
                            container.gotoAndStop(280);
                        }
                        if (container.currentFrame == 295)
                        {
                            if (counter < 60)
                            {
                                counter++;
                            }
                            else
                            {
                                counter = 0;
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                        }
                        else if (container.currentFrame == 310)
                        {
                            if (counter < 60)
                            {
                                counter++;
                            }
                            else
                            {
                                counter = 0;
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                        }
                        else
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                            if (container.currentFrame == 310)
                            {
                                world.achieveManage("achieve_dude_06");
                            }
                        }
                    }
                    else if (counter < 60)
                    {
                        counter++;
                    }
                    else
                    {
                        counter = 0;
                        this.decorationFlag = 0;
                        this.decorationCase.visible = true;
                    }
                }
            }
            else if (container.currentFrame < 40)
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
                this.mouseDownCounter++;
                if (this.mouseDownCounter == 1)
                {
                    this.decorationFlag = 1;
                    container.gotoAndStop(41);
                }
                else if (this.mouseDownCounter == 2)
                {
                    this.decorationFlag = 2;
                    container.gotoAndStop(76);
                }
                else if (this.mouseDownCounter == 3)
                {
                    this.mouseDownCounter = 0;
                    this.decorationFlag = 3;
                    container.gotoAndStop(101);
                    this.decorationCase.visible = false;
                }
            }
            return;
        }// end function

    }
}
