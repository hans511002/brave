package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel9 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var phase:int = 0;

        public function DecorationLevel9()
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
            if (this.phase == 0)
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
            else if (this.phase == 1)
            {
                if (container.currentFrame < 152)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(88);
                }
                if (counter < 90)
                {
                    counter ++;
                }
                else
                {
                    counter = 0;
                    this.phase = 2;
                    container.gotoAndStop(1);
                }
            }
            else if (this.phase == 2)
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
            else if (this.phase == 3)
            {
                if (container.currentFrame < 268)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(187);
                }
                if (counter < 90)
                {
                    counter++;
                }
                else
                {
                    counter = 0;
                    this.phase = 4;
                    container.gotoAndStop(1);
                }
            }
            else if (this.phase == 4)
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
            else if (this.phase == 5)
            {
                if (container.currentFrame < 554)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                    if (container.currentFrame == 417)
                    {
                        if (!world.saveBox.gameSave.data.achieve_dude_09)
                        {
                            world.achieveManage("achieve_dude_09");
                        }
                    }
                }
                else
                {
                    container.gotoAndStop(508);
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
                    container.gotoAndStop(31);
                    counter = 0;
                }
                else if (this.phase == 1 || this.phase == 2)
                {
                    this.phase = 3;
                    container.gotoAndStop(159);
                    counter = 0;
                }
                else if (this.phase == 3 || this.phase == 4)
                {
                    this.phase = 5;
                    container.gotoAndStop(281);
                    this.decorationCase.visible = false;
                    counter = 0;
                }
            }
            return;
        }// end function

    }
}
