package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel10 extends Decoration
    {
        public var decorationCase:MovieClip;
        public var phase:int = 0;

        public function DecorationLevel10()
        {
            container = world.level.decoration;
            this.decorationCase = world.level.decorationCase;
            container.stop();
            this.decorationCase.stop();
            this.decorationCase.buttonMode = true;
            this.decorationCase.visible = false;
            return;
        }// end function

        override public function update() : void
        {
            if (this.phase == 0)
            {
                if (container.currentFrame < 599)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                    if (container.currentFrame == 319)
                    {
                        container.gotoAndStop(401);
                    }
                }
                else
                {
                    container.gotoAndStop(494);
                    if (!this.decorationCase.visible)
                    {
                        this.decorationCase.visible = true;
                    }
                }
            }
            else if (this.phase == 1)
            {
                if (container.currentFrame < 820)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(744);
                }
            }
            else if (this.phase == 2)
            {
                if (container.currentFrame < 1109)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                    if (container.currentFrame == 1007)
                    {
                        if (!world.saveBox.gameSave.data.achieve_dude_10)
                        {
                            world.achieveManage("achieve_dude_10");
                        }
                    }
                }
                else
                {
                    container.gotoAndStop(1060);
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
                    container.gotoAndStop(600);
                }
                else if (this.phase == 1)
                {
                    this.phase = 2;
                    container.gotoAndStop(821);
                    this.decorationCase.visible = false;
                }
            }
            return;
        }// end function

    }
}
