package engine.units
{
    import flash.display.*;
    import flash.events.*;

    public class Unit_24 extends Unit
    {
        public var myPortal:MovieClip;
        public var portalAnima:MovieClip;

        public function Unit_24()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 24;
            container = new Unit24_mc();
            var _loc_2:* = 0.81;
            container.scaleY = 0.81;
            container.scaleX = _loc_2;
            speedKRun = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            speedRunTimerIce1 = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            speedRunTimerIce2 = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][32];
            speedRunTimerIce3 = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][33];
            speedRunTimerIce4 = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
            super.init(event);
            if (world.listOfIcePortals.length > 0)
            {
                if ((gate - 1) >= 0 && (gate - 1) < world.listOfIcePortals.length)
                {
                    this.myPortal = world.listOfIcePortals[(gate - 1)];
                }
                else
                {
                    tempObject = Math.random();
                    i = world.listOfIcePortals.length - 1;
                    while (i >= 0)
                    {
                        
                        if (tempObject > i / world.listOfIcePortals.length)
                        {
                            this.myPortal = world.listOfIcePortals[i];
                            break;
                        }
                        var _loc_3:* = i - 1;
                        i = _loc_3;
                    }
                }
                this.myPortal.myStack.push(this);
                readyDamage = false;
                moveFlag = false;
                path = this.myPortal.myPath;
                road = this.myPortal.myRoad;
                way = this.myPortal.myWay;
                finishPath = world.bezierClass.getPathLength(road, way);
                this.x = this.myPortal.myPoint.x;
                this.y = this.myPortal.myPoint.y;
                this_pt = this.myPortal.myPoint;
                container.alpha = 0;
                var _loc_2:* = false;
                this.mouseChildren = false;
                this.mouseEnabled = _loc_2;
                this.portalAnima = new RoadUnitIce_mc();
                this.portalAnima.stop();
                this.portalAnima.visible = false;
                this.addChild(this.portalAnima);
            }
            tempObject = world.bezierClass.getPathPoint(path + speedK, road, way);
            this.x = tempObject.x;
            this.y = tempObject.y;
            directionFlag = true;
            directionManage();
            this.x = this_pt.x;
            this.y = this_pt.y;
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (this.portalAnima)
            {
                if (this.myPortal.myStack[0] == this)
                {
                    if (!this.myPortal.repeatFlag)
                    {
                        if (this.myPortal.repeatCounter < 30)
                        {
                            (this.myPortal.repeatCounter + 1);
                        }
                        else if (this.myPortal.currentFrame < this.myPortal.totalFrames)
                        {
                            this.myPortal.gotoAndStop((this.myPortal.currentFrame + 1));
                        }
                        else
                        {
                            this.myPortal.repeatFlag = true;
                            this.myPortal.repeatCounter = 0;
                            this.myPortal.gotoAndStop(1);
                        }
                    }
                    else if (this.myPortal.currentFrame < this.myPortal.totalFrames)
                    {
                        this.myPortal.gotoAndStop((this.myPortal.currentFrame + 1));
                        if (this.myPortal.currentFrame == 14)
                        {
                            this.portalAnima.visible = true;
                        }
                        else if (this.myPortal.currentFrame > 14)
                        {
                            if (this.portalAnima.currentFrame < this.portalAnima.totalFrames)
                            {
                                this.portalAnima.gotoAndStop((this.portalAnima.currentFrame + 1));
                                if (this.portalAnima.currentFrame > 8)
                                {
                                    if (container.alpha < 1)
                                    {
                                        container.alpha = container.alpha + 0.1;
                                    }
                                }
                            }
                            else if (this.portalAnima.visible)
                            {
                                this.portalAnima.visible = false;
                            }
                        }
                    }
                    else
                    {
                        this.myPortal.repeatFlag = false;
                        this.myPortal.gotoAndStop(1);
                        this.myPortal.myStack.splice(0, 1);
                        this.removeChild(this.portalAnima);
                        this.portalAnima = null;
                        container.alpha = 1;
                        var _loc_1:* = true;
                        this.mouseChildren = true;
                        this.mouseEnabled = _loc_1;
                        readyDamage = true;
                        moveFlag = true;
                    }
                }
            }
            if (!dead && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container.cont.currentFrame < 61)
                    {
                        if (container.cont.currentFrame < 60)
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
                        container.cont.gotoAndStop(container.cont.currentFrame - 60);
                    }
                }
                else if (container.cont.currentFrame > 60)
                {
                    if (container.cont.currentFrame < container.cont.totalFrames)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.cont.gotoAndStop(61);
                    }
                }
                else
                {
                    container.cont.gotoAndStop(container.cont.currentFrame + 60);
                }
            }
            super.animationHandler();
            return;
        }// end function

        override public function kill() : void
        {
            if (!dead && health <= 0)
            {
                if (direction != "up")
                {
                    tempObject = new Indexes(new Unit24HorisontDeath_mc(), 1);
                }
                else
                {
                    tempObject = new Indexes(new Unit24VerticalDeath_mc(), 1);
                }
                tempObject.container.scaleX = container.scaleX;
                tempObject.container.scaleY = container.scaleY;
                tempObject.x = shoot_pt.x;
                tempObject.y = shoot_pt.y;
            }
            super.kill();
            return;
        }// end function

    }
}
