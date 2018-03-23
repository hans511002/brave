package engine.units
{
    import flash.events.*;

    public class Unit_18 extends Unit
    {
        public var hiddenFlag:Boolean;
        public var invisibleCounter:int = 0;
        public var invisibleTimer:int;
        public var visibleCounter:int = 0;
        public var visibleTimer:int;

        public function Unit_18()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 18;
            this.hiddenFlag = true;
            this.alpha = 0.5;
            readyDamage = false;
            this.invisibleTimer = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            this.visibleTimer = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            container = new Unit18_mc();
            var _loc_2:* = 0.84;
            container.scaleY = 0.84;
            container.scaleX = _loc_2;
            super.init(event);
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!dead && !icemanFlag)
            {
                if (!airFlag && !airShockFlag)
                {
                    if (this.hiddenFlag)
                    {
                        if (this.invisibleCounter < this.invisibleTimer)
                        {
                            (this.invisibleCounter + 1);
                        }
                    }
                    else if (this.visibleCounter < this.visibleTimer)
                    {
                        (this.visibleCounter + 1);
                    }
                    if (direction == "left" || direction == "right")
                    {
                        if (this.hiddenFlag)
                        {
                            if (container.cont.currentFrame > 9)
                            {
                                container.cont.gotoAndStop(1);
                            }
                            else if (container.cont.currentFrame > 1)
                            {
                                container.cont.gotoAndStop((container.cont.currentFrame - 1));
                            }
                        }
                        else if (container.cont.currentFrame > 9)
                        {
                            container.cont.gotoAndStop(9);
                        }
                        else if (container.cont.currentFrame < 9)
                        {
                            container.cont.gotoAndStop((container.cont.currentFrame + 1));
                        }
                        if (container.currentFrame > 24)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                            if (container.cont.x >= -1 && container.cont.x <= 1 && container.cont.y >= -1 && container.cont.y <= 1)
                            {
                                container.gotoAndStop(1);
                            }
                            if (container.currentFrame < 33)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < 37)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                            else if (container.currentFrame < 44)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < container.totalFrames)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                        }
                        else
                        {
                            if (container.currentFrame < 24)
                            {
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                            else
                            {
                                container.gotoAndStop(1);
                            }
                            if (container.currentFrame < 9)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < 13)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                            else if (container.currentFrame < 20)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < 24)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                        }
                    }
                    else if (direction == "up")
                    {
                        if (container.cont.currentFrame < 10)
                        {
                            container.cont.gotoAndStop(10);
                        }
                        if (container.currentFrame < 25)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                            if (container.cont.x >= -1 && container.cont.x <= 1 && container.cont.y >= -1 && container.cont.y <= 1)
                            {
                                container.gotoAndStop(25);
                            }
                            if (container.currentFrame < 9)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < 13)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                            else if (container.currentFrame < 20)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < 24)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                        }
                        else
                        {
                            if (container.currentFrame < container.totalFrames)
                            {
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                            else
                            {
                                container.gotoAndStop(25);
                            }
                            if (container.currentFrame < 33)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < 37)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                            else if (container.currentFrame < 44)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < container.totalFrames)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                        }
                    }
                    else if (direction == "down")
                    {
                        if (this.hiddenFlag)
                        {
                            if (container.cont.currentFrame > 9)
                            {
                                container.cont.gotoAndStop(1);
                            }
                            else if (container.cont.currentFrame > 1)
                            {
                                container.cont.gotoAndStop((container.cont.currentFrame - 1));
                            }
                        }
                        else if (container.cont.currentFrame > 9)
                        {
                            container.cont.gotoAndStop(9);
                        }
                        else if (container.cont.currentFrame < 9)
                        {
                            container.cont.gotoAndStop((container.cont.currentFrame + 1));
                        }
                        if (container.currentFrame < 25)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                            if (container.cont.x >= -1 && container.cont.x <= 1 && container.cont.y >= -1 && container.cont.y <= 1)
                            {
                                container.gotoAndStop(25);
                            }
                            if (container.currentFrame < 9)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < 13)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                            else if (container.currentFrame < 20)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < 24)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                        }
                        else
                        {
                            if (container.currentFrame < container.totalFrames)
                            {
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                            else
                            {
                                container.gotoAndStop(25);
                            }
                            if (container.currentFrame < 33)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < 37)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                            else if (container.currentFrame < 44)
                            {
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container.currentFrame < container.totalFrames)
                            {
                                if (moveFlag)
                                {
                                    moveFlag = false;
                                }
                            }
                        }
                    }
                }
                else if (direction == "left" || direction == "right")
                {
                    if (this.hiddenFlag)
                    {
                        if (container.cont.currentFrame > 9)
                        {
                            container.cont.gotoAndStop(1);
                        }
                        else if (container.cont.currentFrame > 1)
                        {
                            container.cont.gotoAndStop((container.cont.currentFrame - 1));
                        }
                    }
                    else if (container.cont.currentFrame > 9)
                    {
                        container.cont.gotoAndStop(9);
                    }
                    else if (container.cont.currentFrame < 9)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                    }
                    if (container.currentFrame > 24)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                        if (container.cont.x >= -1 && container.cont.x <= 1 && container.cont.y >= -1 && container.cont.y <= 1)
                        {
                            container.gotoAndStop(1);
                        }
                        if (container.currentFrame < 33)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < 37)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (container.currentFrame < 44)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < container.totalFrames)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                    }
                    else
                    {
                        if (container.currentFrame != 1 && container.currentFrame < 24)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else if (container.currentFrame != 1)
                        {
                            container.gotoAndStop(1);
                        }
                        if (container.currentFrame < 9)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < 13)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (container.currentFrame < 20)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < 24)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                    }
                }
                else if (direction == "up")
                {
                    if (container.cont.currentFrame < 10)
                    {
                        container.cont.gotoAndStop(10);
                    }
                    if (container.currentFrame < 25)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                        if (container.cont.x >= -1 && container.cont.x <= 1 && container.cont.y >= -1 && container.cont.y <= 1)
                        {
                            container.gotoAndStop(25);
                        }
                        if (container.currentFrame < 9)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < 13)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (container.currentFrame < 20)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < 24)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                    }
                    else
                    {
                        if (container.currentFrame != 25 && container.currentFrame < container.totalFrames)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else if (container.currentFrame != 25)
                        {
                            container.gotoAndStop(25);
                        }
                        if (container.currentFrame < 33)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < 37)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (container.currentFrame < 44)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < container.totalFrames)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                    }
                }
                else if (direction == "down")
                {
                    if (this.hiddenFlag)
                    {
                        if (container.cont.currentFrame > 9)
                        {
                            container.cont.gotoAndStop(1);
                        }
                        else if (container.cont.currentFrame > 1)
                        {
                            container.cont.gotoAndStop((container.cont.currentFrame - 1));
                        }
                    }
                    else if (container.cont.currentFrame > 9)
                    {
                        container.cont.gotoAndStop(9);
                    }
                    else if (container.cont.currentFrame < 9)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                    }
                    if (container.currentFrame < 25)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                        if (container.cont.x >= -1 && container.cont.x <= 1 && container.cont.y >= -1 && container.cont.y <= 1)
                        {
                            container.gotoAndStop(25);
                        }
                        if (container.currentFrame < 9)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < 13)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (container.currentFrame < 20)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < 24)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                    }
                    else
                    {
                        if (container.currentFrame != 25 && container.currentFrame < container.totalFrames)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else if (container.currentFrame != 25)
                        {
                            container.gotoAndStop(25);
                        }
                        if (container.currentFrame < 33)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < 37)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (container.currentFrame < 44)
                        {
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container.currentFrame < container.totalFrames)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                    }
                }
            }
            if (this.invisibleCounter == this.invisibleTimer)
            {
                if (!container.signal.visible)
                {
                    container.signal.visible = true;
                }
                else if (container.signal.currentFrame < container.signal.totalFrames)
                {
                    container.signal.gotoAndStop((container.signal.currentFrame + 1));
                }
                else
                {
                    container.signal.gotoAndStop(1);
                    container.signal.visible = false;
                    this.invisibleCounter = 0;
                    this.hiddenFlag = false;
                    this.alpha = 1;
                    readyDamage = true;
                }
            }
            else if (this.visibleCounter == this.visibleTimer)
            {
                if (!container.signal.visible)
                {
                    container.signal.visible = true;
                    readyDamage = false;
                }
                else if (container.signal.currentFrame < container.signal.totalFrames)
                {
                    container.signal.gotoAndStop((container.signal.currentFrame + 1));
                }
                else
                {
                    container.signal.gotoAndStop(1);
                    container.signal.visible = false;
                    this.visibleCounter = 0;
                    this.hiddenFlag = true;
                    this.alpha = 0.5;
                }
            }
            super.animationHandler();
            return;
        }// end function

    }
}
