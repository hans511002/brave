package engine.decoration
{
    import flash.display.*;
    import flash.events.*;

    public class DecorationLevel8 extends Decoration
    {
        public var decorationFlag:int = 0;
        public var decoration1Flag:int = 0;
        public var decoration2Flag:int = 0;
        public var decoration3Flag:int = 0;
        public var container1:MovieClip;
        public var container2:MovieClip;
        public var container3:MovieClip;
        public var decorationCase:MovieClip;
        public var decoration1Case:MovieClip;
        public var decoration2Case:MovieClip;
        public var decoration3Case:MovieClip;
        public var decoration4Case:MovieClip;
        public var finish_01:Boolean;
        public var finish_02:Boolean;
        public var finish_03:Boolean;
        public var finish_04:Boolean;

        public function DecorationLevel8()
        {
            container = world.level.decoration;
            this.container1 = world.level.decoration1;
            this.container2 = world.level.decoration2;
            this.container3 = world.level.decoration3;
            this.decorationCase = world.level.decorationCase;
            this.decoration1Case = world.level.decoration1Case;
            this.decoration2Case = world.level.decoration2Case;
            this.decoration3Case = world.level.decoration3Case;
            this.decoration4Case = world.level.decoration4Case;
            container.stop();
            this.container1.gotoAndStop(346);
            this.container2.gotoAndStop(565);
            this.container3.gotoAndStop(565);
            this.decorationCase.stop();
            this.decoration1Case.stop();
            this.decoration2Case.stop();
            this.decoration3Case.stop();
            this.decoration4Case.stop();
            this.decorationCase.setMouseEnabled(true);
            this.decoration1Case.setMouseEnabled(true);
            this.decoration2Case.setMouseEnabled(true);
            this.decoration3Case.setMouseEnabled(true);
            this.decoration4Case.setMouseEnabled(true);
            this.decoration1Case.visible = false;
            return;
        }// end function

        override public function update() : void
        {
            if (this.decorationFlag == 0)
            {
                if (container.currentFrame < 210)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(1);
                }
            }
            else if (this.decorationFlag == 1)
            {
                if (container.currentFrame < 211)
                {
                    container.gotoAndStop(211);
                }
                if (container.currentFrame < 345)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    this.decorationFlag = 2;
                    this.decoration1Case.visible = true;
                }
            }
            else if (this.decorationFlag == 2)
            {
                if (container.currentFrame < 405)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(346);
                }
            }
            else if (this.decorationFlag == 3)
            {
                if (container.currentFrame < 439)
                {
                    container.gotoAndStop(439);
                }
                if (container.currentFrame < 564)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    this.decorationFlag = 4;
                    this.decoration1Case.visible = true;
                }
            }
            else if (this.decorationFlag == 4)
            {
                if (container.currentFrame < 795)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(565);
                }
            }
            else if (this.decorationFlag == 5)
            {
                if (container.currentFrame < 796)
                {
                    container.gotoAndStop(796);
                }
                if (container.currentFrame < container.totalFrames)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
                else
                {
                    container.gotoAndStop(465);
                    this.decorationFlag = 2;
                    this.decoration1Case.visible = true;
                }
            }
            if (this.decoration1Flag == 0)
            {
                if (this.container1.currentFrame < 405)
                {
                    this.container1.gotoAndStop((this.container1.currentFrame + 1));
                }
                else
                {
                    this.container1.gotoAndStop(346);
                }
            }
            else if (this.decoration1Flag == 1)
            {
                if (this.container1.currentFrame < 439)
                {
                    this.container1.gotoAndStop(439);
                }
                if (this.container1.currentFrame < 564)
                {
                    this.container1.gotoAndStop((this.container1.currentFrame + 1));
                }
                else
                {
                    this.decoration1Flag = 2;
                    this.decoration2Case.visible = true;
                }
            }
            else if (this.decoration1Flag == 2)
            {
                if (this.container1.currentFrame < 795)
                {
                    this.container1.gotoAndStop((this.container1.currentFrame + 1));
                }
                else
                {
                    this.container1.gotoAndStop(565);
                }
            }
            else if (this.decoration1Flag == 3)
            {
                if (this.container1.currentFrame < 796)
                {
                    this.container1.gotoAndStop(796);
                }
                if (this.container1.currentFrame < this.container1.totalFrames)
                {
                    this.container1.gotoAndStop((this.container1.currentFrame + 1));
                }
                else
                {
                    this.container1.gotoAndStop(455);
                    this.decoration1Flag = 0;
                    this.decoration2Case.visible = true;
                }
            }
            if (this.decoration2Flag == 0)
            {
                if (this.container2.currentFrame < 795)
                {
                    this.container2.gotoAndStop((this.container2.currentFrame + 1));
                }
                else
                {
                    this.container2.gotoAndStop(565);
                }
            }
            else if (this.decoration2Flag == 1)
            {
                if (this.container2.currentFrame < 796)
                {
                    this.container2.gotoAndStop(796);
                }
                if (this.container2.currentFrame < this.container2.totalFrames)
                {
                    this.container2.gotoAndStop((this.container2.currentFrame + 1));
                }
                else
                {
                    this.decoration2Flag = 2;
                    this.container2.gotoAndStop(455);
                    this.decoration3Case.visible = true;
                }
            }
            else if (this.decoration2Flag == 2)
            {
                if (this.container2.currentFrame < 405)
                {
                    this.container2.gotoAndStop((this.container2.currentFrame + 1));
                }
                else
                {
                    this.container2.gotoAndStop(346);
                }
            }
            else if (this.decoration2Flag == 3)
            {
                if (this.container2.currentFrame < 439)
                {
                    this.container2.gotoAndStop(439);
                }
                if (this.container2.currentFrame < 564)
                {
                    this.container2.gotoAndStop((this.container2.currentFrame + 1));
                }
                else
                {
                    this.decoration2Flag = 0;
                    this.decoration3Case.visible = true;
                }
            }
            if (this.decoration3Flag == 0)
            {
                if (this.container3.currentFrame < 795)
                {
                    this.container3.gotoAndStop((this.container3.currentFrame + 1));
                }
                else
                {
                    this.container3.gotoAndStop(565);
                }
            }
            else if (this.decoration3Flag == 1)
            {
                if (this.container3.currentFrame < 796)
                {
                    this.container3.gotoAndStop(796);
                }
                if (this.container3.currentFrame < this.container3.totalFrames)
                {
                    this.container3.gotoAndStop((this.container3.currentFrame + 1));
                }
                else
                {
                    this.decoration3Flag = 2;
                    this.container3.gotoAndStop(455);
                    this.decoration4Case.visible = true;
                }
            }
            else if (this.decoration3Flag == 2)
            {
                if (this.container3.currentFrame < 405)
                {
                    this.container3.gotoAndStop((this.container3.currentFrame + 1));
                }
                else
                {
                    this.container3.gotoAndStop(346);
                }
            }
            else if (this.decoration3Flag == 3)
            {
                if (this.container3.currentFrame < 439)
                {
                    this.container3.gotoAndStop(439);
                }
                if (this.container3.currentFrame < 564)
                {
                    this.container3.gotoAndStop((this.container3.currentFrame + 1));
                }
                else
                {
                    this.decoration3Flag = 0;
                    this.decoration4Case.visible = true;
                }
            }
            super.update();
            return;
        }// end function

        override public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event.target.name == "decorationCase")
            {
                if (this.decorationFlag == 0)
                {
                    this.decorationFlag = 1;
                    this.decorationCase.visible = false;
                }
            }
            else if (event.target.name == "decoration1Case")
            {
                if (this.decorationFlag == 2)
                {
                    this.decorationFlag = 3;
                    this.decoration1Case.visible = false;
                    if (!this.finish_01)
                    {
                        this.finish_01 = true;
                        if (this.finish_01 && this.finish_02 && this.finish_03 && this.finish_04)
                        {
                            world.achieveManage("achieve_dude_08");
                        }
                    }
                }
                else if (this.decorationFlag == 4)
                {
                    this.decorationFlag = 5;
                    this.decoration1Case.visible = false;
                }
            }
            else if (event.target.name == "decoration2Case")
            {
                if (this.decoration1Flag == 0)
                {
                    this.decoration1Flag = 1;
                    this.decoration2Case.visible = false;
                    if (!this.finish_02)
                    {
                        this.finish_02 = true;
                        if (this.finish_01 && this.finish_02 && this.finish_03 && this.finish_04)
                        {
                            world.achieveManage("achieve_dude_08");
                        }
                    }
                }
                else if (this.decoration1Flag == 2)
                {
                    this.decoration1Flag = 3;
                    this.decoration2Case.visible = false;
                }
            }
            else if (event.target.name == "decoration3Case")
            {
                if (this.decoration2Flag == 0)
                {
                    this.decoration2Flag = 1;
                    this.decoration3Case.visible = false;
                    if (!this.finish_03)
                    {
                        this.finish_03 = true;
                        if (this.finish_01 && this.finish_02 && this.finish_03 && this.finish_04)
                        {
                            world.achieveManage("achieve_dude_08");
                        }
                    }
                }
                else if (this.decoration2Flag == 1)
                {
                    this.decoration2Flag = 2;
                    this.decoration3Case.visible = false;
                }
                else if (this.decoration2Flag == 2)
                {
                    this.decoration2Flag = 3;
                    this.decoration3Case.visible = false;
                }
            }
            else if (event.target.name == "decoration4Case")
            {
                if (this.decoration3Flag == 0)
                {
                    this.decoration3Flag = 1;
                    this.decoration4Case.visible = false;
                    if (!this.finish_04)
                    {
                        this.finish_04 = true;
                        if (this.finish_01 && this.finish_02 && this.finish_03 && this.finish_04)
                        {
                            world.achieveManage("achieve_dude_08");
                        }
                    }
                }
                else if (this.decoration3Flag == 1)
                {
                    this.decoration3Flag = 2;
                    this.decoration4Case.visible = false;
                }
                else if (this.decoration3Flag == 2)
                {
                    this.decoration3Flag = 3;
                    this.decoration4Case.visible = false;
                }
            }
            return;
        }// end function

    }
}
