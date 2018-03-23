package engine.units
{
    import flash.events.*;

    public class Unit_28 extends Unit
    {
        public var giveHealthRadius:Number;
        public var giveHeathCounter:int;
        public var giveHeathTimer:int;
        public var giveHeath:Number;

        public function Unit_28()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 28;
            this.giveHealthRadius = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            var _loc_2:* = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            this.giveHeathTimer = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            this.giveHeathCounter = _loc_2;
            this.giveHeath = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][32];
            container = new Unit28_mc();
            var _loc_2:* = 0.8;
            container.scaleY = 0.8;
            container.scaleX = _loc_2;
            super.init(event);
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!dead && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container.cont.currentFrame < 12)
                    {
                        if (container.cont.currentFrame < 11)
                        {
                            container.cont.gotoAndStop((container.cont.currentFrame + 1));
                        }
                        else
                        {
                            container.cont.gotoAndStop(1);
                        }
                    }
                    else
                    {
                        container.cont.gotoAndStop(1);
                    }
                }
                else if (container.cont.currentFrame != 12)
                {
                    container.cont.gotoAndStop(12);
                }
                if (!airFlag && !airShockFlag || container.currentFrame != 1)
                {
                    if (container.currentFrame < container.totalFrames)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else
                    {
                        container.gotoAndStop(1);
                    }
                }
                if (this.giveHeathCounter > 0)
                {
                    (this.giveHeathCounter - 1);
                }
                else if (world.frameCounter == 30)
                {
                    i = 0;
                    while (i < world.listOfUnits.length)
                    {
                        
                        if (world.listOfUnits[i].typeUnit != 28 && world.listOfUnits[i].typeUnit != 34 && world.listOfUnits[i].atStage && world.listOfUnits[i].health < world.listOfUnits[i].healthMax)
                        {
                            if (Point.distance(world.listOfUnits[i].this_pt, this_pt) < this.giveHealthRadius)
                            {
                                if (this.giveHeathCounter == 0)
                                {
                                    this.giveHeathCounter = this.giveHeathTimer;
                                    container.giveHealth1.visible = true;
                                    container.giveHealth2.visible = true;
                                    container.giveHealth3.visible = true;
                                }
                                world.listOfUnits[i].healthPlusFlag = true;
                                world.listOfUnits[i].healthPlusValue = world.listOfUnits[i].healthMax * this.giveHeath;
                                world.listOfUnits[i].healthPlusValue = world.listOfUnits[i].healthPlusValue / world.listOfUnits[i].container.buffHP.totalFrames;
                                world.listOfUnits[i].container.buffHP.gotoAndStop(1);
                            }
                        }
                        var _loc_2:* = i + 1;
                        i = _loc_2;
                    }
                }
            }
            if (container.giveHealth1.visible)
            {
                if (container.giveHealth1.currentFrame < container.giveHealth1.totalFrames)
                {
                    container.giveHealth1.gotoAndStop((container.giveHealth1.currentFrame + 1));
                    container.giveHealth2.gotoAndStop((container.giveHealth2.currentFrame + 1));
                    container.giveHealth3.gotoAndStop((container.giveHealth3.currentFrame + 1));
                }
                else
                {
                    container.giveHealth1.gotoAndStop(1);
                    container.giveHealth2.gotoAndStop(1);
                    container.giveHealth3.gotoAndStop(1);
                    container.giveHealth1.visible = false;
                    container.giveHealth2.visible = false;
                    container.giveHealth3.visible = false;
                }
            }
            super.animationHandler();
            return;
        }// end function

    }
}
