package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel14 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var phase:int = 0;

        public function DecorationLevel14()
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
                if (container.currentFrame < 130)
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
                if (container.currentFrame < 187)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    this.phase = 2;
                }
            }
            else if (this.phase == 2)
            {
                if (container.currentFrame < 130)
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
                if (container.currentFrame < 245)
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
                if (container.currentFrame < 130)
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
                if (container.currentFrame < 400)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                    if (container.currentFrame == 381)
                    {
                        if (!world.saveBox.gameSave.data.achieve_dude_14)
                        {
                            world.achieveManage("achieve_dude_14");
                        }
                    }
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
                    container.gotoAndStop(131);
                }
                else if (this.phase == 1 || this.phase == 2)
                {
                    this.phase = 3;
                    container.gotoAndStop(188);
                }
                else if (this.phase == 3 || this.phase == 4)
                {
                    this.phase = 5;
                    container.gotoAndStop(303);
                    this.decorationCase.visible = false;
                }
            }
            return;
        }// end function

    }
}
