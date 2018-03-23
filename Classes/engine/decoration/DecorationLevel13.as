package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel13 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var phase:int = 0;

        public function DecorationLevel13()
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
            if (this.phase == 0)
            {
                if (container.currentFrame < 25)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(1);
                }
            }
            else if (this.phase == 1)
            {
                if (container.currentFrame < 66)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
            }
            else if (this.phase == 2)
            {
                if (container.currentFrame < 109)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
            }
            else if (this.phase == 3)
            {
                if (container.currentFrame < 150)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
            }
            else if (this.phase == 4)
            {
                if (container.currentFrame < 260)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                    if (container.currentFrame == 195)
                    {
                        if (!world.saveBox.gameSave.data.achieve_dude_13)
                        {
                            world.achieveManage("achieve_dude_13");
                        }
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
                if (this.phase == 0)
                {
                    this.phase = 1;
                    container.gotoAndStop(26);
                }
                else if (this.phase == 1)
                {
                    this.phase = 2;
                    container.gotoAndStop(67);
                }
                else if (this.phase == 2)
                {
                    this.phase = 3;
                    container.gotoAndStop(110);
                }
                else
                {
                    this.phase = 4;
                    container.gotoAndStop(151);
                }
            }
            return;
        }// end function

    }
}
