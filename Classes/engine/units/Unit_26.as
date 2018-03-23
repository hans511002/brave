package engine.units
{
    import flash.display.*;
    import flash.events.*;

    public class Unit_26 extends Unit
    {
        public var myPortal:MovieClip;
        public var portalAnima:MovieClip;

        public function Unit_26()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 26;
            container = new Unit26_mc();
            var _loc_2:* = 0.81;
            container.scaleY = 0.81;
            container.scaleX = _loc_2;
            super.init(event);
            if (world.listOfLevinPortals.length > 0)
            {
                if ((gate - 1) >= 0 && (gate - 1) < world.listOfLevinPortals.length)
                {
                    this.myPortal = world.listOfLevinPortals[(gate - 1)];
                }
                else
                {
                    tempObject = Math.random();
                    i = world.listOfLevinPortals.length - 1;
                    while (i >= 0)
                    {
                        
                        if (tempObject > i / world.listOfLevinPortals.length)
                        {
                            this.myPortal = world.listOfLevinPortals[i];
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
                this.portalAnima = new RoadUnitLevin_mc();
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
                        if (this.myPortal.currentFrame == 26)
                        {
                            this.portalAnima.visible = true;
                        }
                        else if (this.myPortal.currentFrame > 26)
                        {
                            if (this.portalAnima.currentFrame < this.portalAnima.totalFrames)
                            {
                                this.portalAnima.gotoAndStop((this.portalAnima.currentFrame + 1));
                                if (this.portalAnima.currentFrame > 6)
                                {
                                    if (container.alpha < 1)
                                    {
                                        container.alpha = container.alpha + 0.2;
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
                if (listOfTornado.length > 0)
                {
                    if (world.frameCounter == 10 || world.frameCounter == 20 || world.frameCounter == 30)
                    {
                        tempObject1 = Math.round(Math.random() * (3 - 1)) + 1;
                        tempObject2 = world.bezierClass.getPathLength(road, tempObject1);
                        tempObject6 = 10000;
                        j = 0;
                        while (j < tempObject2)
                        {
                            
                            tempObject3 = world.bezierClass.getPathPoint(j, road, tempObject1);
                            tempObject3 = new Point(tempObject3.x, tempObject3.y);
                            tempObject4 = Point.distance(this_pt, tempObject3);
                            if (tempObject4 < 30)
                            {
                                if (tempObject4 < tempObject6)
                                {
                                    tempObject6 = tempObject4;
                                }
                                else
                                {
                                    tempObject1 = world.addUnit(33, road, tempObject1, j + Math.random() * 20);
                                    tempObject1.direction = direction;
                                    tempObject1.readyDamage = false;
                                    tempObject1.moveFlag = false;
                                    tempObject1.x = this.x;
                                    tempObject1.y = this.y;
                                    tempObject1.alpha = 0;
                                    listOfTornado.splice(0, 1);
                                    break;
                                }
                            }
                            j = j + 10;
                        }
                    }
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
                    tempObject = new Indexes(new Unit26HorisontDeath_mc(), 1);
                }
                else
                {
                    tempObject = new Indexes(new Unit26VerticalDeath_mc(), 1);
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
