package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel12 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var phase:int = 0;
        public var returnFlag:Boolean;

        public function DecorationLevel12()
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
            if (this.phase < 4)
            {
                if (container.currentFrame < 30)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(1);
                }
            }
            else if (this.phase == 4)
            {
                if (container.currentFrame < 100)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                    if (!this.returnFlag)
                    {
                        if (container.currentFrame == 99)
                        {
                            container.gotoAndStop(57);
                            this.returnFlag = true;
                        }
                    }
                    else if (container.currentFrame == 89)
                    {
                        if (!world.saveBox.gameSave.data.achieve_dude_12)
                        {
                            world.achieveManage("achieve_dude_12");
                        }
                    }
                }
                else if (counter < 90)
                {
                    counter++;
                }
                else
                {
                    counter = 0;
                    this.phase = 5;
                }
            }
            else if (this.phase == 5)
            {
                if (container.currentFrame < 130)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    this.phase = 6;
                }
            }
            super.update();
            return;
        }// end function

        override public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "decorationCase")
            {
                if (this.phase == 0)
                {
                    this.phase = 1;
                }
                else if (this.phase == 1)
                {
                    this.phase = 2;
                }
                else if (this.phase == 2)
                {
                    this.phase = 3;
                }
                else if (this.phase == 3)
                {
                    this.phase = 4;
                    this.decorationCase.visible = false;
                }
            }
            return;
        }// end function

    }
}
