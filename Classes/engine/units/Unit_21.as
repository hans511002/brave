package engine.units
{
    import flash.events.*;

    public class Unit_21 extends Unit
    {
        public var newEnemyCounter:int;

        public function Unit_21()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 21;
            this.newEnemyCounter = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            container = new Unit21_mc();
            var _loc_2:* = 0.88;
            container.scaleY = 0.88;
            container.scaleX = _loc_2;
            super.init(event);
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!icemanFlag)
            {
                if (direction != "up")
                {
                    if (container.cont.currentFrame == 2)
                    {
                        container.cont.gotoAndStop(1);
                    }
                }
                else if (container.cont.currentFrame == 1)
                {
                    container.cont.gotoAndStop(2);
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
            }
            super.animationHandler();
            return;
        }// end function

        override public function kill() : void
        {
            if (!dead && health <= 0)
            {
                if (container.cont.currentFrame == 1)
                {
                    tempObject = new Indexes(new Unit21_frontDeath_mc(), 1);
                }
                else if (container.cont.currentFrame == 2)
                {
                    tempObject = new Indexes(new Unit21_backDeath_mc(), 1);
                }
                Sounds.instance.playSound("snd_unit_orderDeath");
                tempObject1 = container.localToGlobal(new Point(container.cont.x, container.cont.y));
                tempObject.x = tempObject1.x;
                tempObject.y = tempObject1.y;
                tempObject1 = 0;
                tempObject2 = 0;
                tempObject3 = 0;
                if (way == 1)
                {
                    tempObject1 = path;
                }
                else if (way == 2)
                {
                    tempObject2 = path;
                }
                else if (way == 2)
                {
                    tempObject3 = path;
                }
                if (tempObject1 == 0)
                {
                    tempObject = 10000;
                    tempObject4 = world.bezierClass.getPathLength(road, 1);
                    i = 0;
                    while (i < tempObject4)
                    {
                        
                        tempObject5 = world.bezierClass.getPathPoint(i, road, 1);
                        tempObject6 = Point.distance(new Point(tempObject5.x, tempObject5.y), this_pt);
                        if (tempObject6 < tempObject)
                        {
                            tempObject = tempObject6;
                        }
                        else if (tempObject6 < 50)
                        {
                            break;
                        }
                        i = i + 5;
                    }
                    tempObject1 = i;
                }
                if (tempObject2 == 0)
                {
                    tempObject = 10000;
                    tempObject4 = world.bezierClass.getPathLength(road, 2);
                    i = 0;
                    while (i < tempObject4)
                    {
                        
                        tempObject5 = world.bezierClass.getPathPoint(i, road, 2);
                        tempObject6 = Point.distance(new Point(tempObject5.x, tempObject5.y), this_pt);
                        if (tempObject6 < tempObject)
                        {
                            tempObject = tempObject6;
                        }
                        else if (tempObject6 < 50)
                        {
                            break;
                        }
                        i = i + 5;
                    }
                    tempObject2 = i;
                }
                if (tempObject3 == 0)
                {
                    tempObject = 10000;
                    tempObject4 = world.bezierClass.getPathLength(road, 3);
                    i = 0;
                    while (i < tempObject4)
                    {
                        
                        tempObject5 = world.bezierClass.getPathPoint(i, road, 3);
                        tempObject6 = Point.distance(new Point(tempObject5.x, tempObject5.y), this_pt);
                        if (tempObject6 < tempObject)
                        {
                            tempObject = tempObject6;
                        }
                        else if (tempObject6 < 50)
                        {
                            break;
                        }
                        i = i + 5;
                    }
                    tempObject3 = i;
                }
                j = 0;
                i = 1;
                while (i <= this.newEnemyCounter)
                {
                    
                    (j + 1);
                    if (j == 1)
                    {
                        tempObject1 = tempObject1 + 15;
                        tempObject = world.addUnit(32, road, 1, tempObject1);
                        tempObject.speedKSave = tempObject.speedKSave - 0.1;
                    }
                    else if (j == 2)
                    {
                        tempObject2 = tempObject2 + 15;
                        tempObject = world.addUnit(32, road, 2, tempObject2);
                        tempObject.speedKSave = tempObject.speedKSave - 0.14;
                    }
                    else if (j == 3)
                    {
                        tempObject3 = tempObject3 + 15;
                        tempObject = world.addUnit(32, road, 3, tempObject3);
                        tempObject.speedKSave = tempObject.speedKSave - 0.17;
                    }
                    else if (j == 4)
                    {
                        j = 0;
                        tempObject3 = tempObject3 + 15;
                        tempObject = world.addUnit(32, road, 1, tempObject1);
                        tempObject.speedKSave = tempObject.speedKSave - 0.2;
                    }
                    tempObject.speedK = tempObject.speedKSave;
                    tempObject.direction = direction;
                    tempObject.readyDamage = false;
                    tempObject.moveFlag = false;
                    tempObject.x = this.x;
                    tempObject.y = this.y;
                    tempObject.alpha = 0;
                    var _loc_2:* = i + 1;
                    i = _loc_2;
                }
            }
            super.kill();
            return;
        }// end function

    }
}
