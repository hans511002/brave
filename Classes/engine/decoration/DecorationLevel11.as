package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel11 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var phase:int = 0;

        public function DecorationLevel11()
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
            if (this.phase == 1)
            {
                if (container.currentFrame < 267)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    this.phase = 2;
                    this.decorationCase.visible = true;
                }
            }
            else if (this.phase == 3)
            {
                if (container.currentFrame < 400)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    this.phase = 4;
                }
            }
            else if (this.phase == 4)
            {
                if (counter < 90)
                {
                    (counter + 1);
                }
                else if (container.currentFrame < 456)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(403);
                    counter = 0;
                }
            }
            else if (this.phase == 5)
            {
                if (container.currentFrame < 400)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    this.phase = 6;
                }
            }
            else if (this.phase == 6)
            {
                if (counter < 90)
                {
                    (counter + 1);
                }
                else if (container.currentFrame < 456)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(403);
                    counter = 0;
                }
            }
            else if (this.phase == 7)
            {
                if (container.currentFrame < 580)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                    if (container.currentFrame == 481)
                    {
                        if (!world.saveBox.gameSave.data.achieve_dude_11)
                        {
                            world.achieveManage("achieve_dude_11");
                        }
                    }
                }
                else
                {
                    this.phase = 8;
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
                    this.decorationCase.visible = false;
                }
                else if (this.phase == 2)
                {
                    this.phase = 3;
                    counter = 0;
                }
                else if (this.phase == 3 || this.phase == 4)
                {
                    this.phase = 5;
                    container.gotoAndStop(341);
                    counter = 0;
                }
                else if (this.phase == 5 || this.phase == 6)
                {
                    this.phase = 7;
                    container.gotoAndStop(457);
                    counter = 0;
                    this.decorationCase.visible = false;
                }
            }
            return;
        }// end function

    }
}
