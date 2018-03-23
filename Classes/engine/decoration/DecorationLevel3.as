package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel3 extends Decoration
    {
        public var pumpkin1Case:MovieClip;
        public var pumpkin2Case:MovieClip;
        public var pumpkin3Case:MovieClip;
        public var mouseFrameCounter:int = 0;
        public var phase:int = 0;

        public function DecorationLevel3()
        {
            container = world.level.decoration;
            this.pumpkin1Case = world.level.pumpkin1Case;
            this.pumpkin2Case = world.level.pumpkin2Case;
            this.pumpkin3Case = world.level.pumpkin3Case;
            container.stop();
            container.pumpkin1.stop();
            container.pumpkin2.stop();
            container.pumpkin3.stop();
            this.pumpkin1Case.stop();
            this.pumpkin2Case.stop();
            this.pumpkin3Case.stop();
            this.pumpkin1Case.buttonMode = true;
            this.pumpkin2Case.buttonMode = true;
            this.pumpkin3Case.buttonMode = true;
            return;
        }// end function

        override public function update() : void
        {
            if (this.phase == 0)
            {
                if (!this.pumpkin1Case.buttonMode)
                {
                    if (container.pumpkin1.currentFrame < (container.pumpkin1.totalFrames - 1))
                    {
                        container.pumpkin1.gotoAndStop((container.pumpkin1.currentFrame + 1));
                    }
                }
                if (!this.pumpkin2Case.buttonMode)
                {
                    if (container.pumpkin2.currentFrame < (container.pumpkin2.totalFrames - 1))
                    {
                        container.pumpkin2.gotoAndStop((container.pumpkin2.currentFrame + 1));
                    }
                }
                if (!this.pumpkin3Case.buttonMode)
                {
                    if (container.pumpkin3.currentFrame < (container.pumpkin3.totalFrames - 1))
                    {
                        container.pumpkin3.gotoAndStop((container.pumpkin3.currentFrame + 1));
                    }
                }
                if (container.pumpkin1.currentFrame == (container.pumpkin1.totalFrames - 1))
                {
                    if (container.pumpkin2.currentFrame == (container.pumpkin2.totalFrames - 1))
                    {
                        if (container.pumpkin3.currentFrame == (container.pumpkin3.totalFrames - 1))
                        {
                            this.phase = 1;
                            world.achieveManage("achieve_dude_03");
                        }
                    }
                }
            }
            else if (this.phase == 1)
            {
                if (container.currentFrame < container.totalFrames)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    this.phase = 0;
                    container.gotoAndStop(1);
                    container.pumpkin1.stop();
                    container.pumpkin2.stop();
                    container.pumpkin3.stop();
                    this.pumpkin1Case.buttonMode = true;
                    this.pumpkin2Case.buttonMode = true;
                    this.pumpkin3Case.buttonMode = true;
                }
            }
            super.update();
            return;
        }// end function

        override public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "pumpkin1Case")
            {
                if (this.pumpkin1Case.buttonMode)
                {
                    this.pumpkin1Case.buttonMode = false;
                }
            }
            else if (event.target.name == "pumpkin2Case")
            {
                if (this.pumpkin2Case.buttonMode)
                {
                    this.pumpkin2Case.buttonMode = false;
                }
            }
            else if (event.target.name == "pumpkin3Case")
            {
                if (this.pumpkin3Case.buttonMode)
                {
                    this.pumpkin3Case.buttonMode = false;
                }
            }
            return;
        }// end function

    }
}
