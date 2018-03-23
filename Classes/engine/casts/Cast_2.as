package engine.casts
{
    import flash.events.*;

    public class Cast_2 extends Cast
    {

        public function Cast_2()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            container = new MoveIceman_mc();
            container.gotoAndStop(2);
            this.addChild(container);
            super.init(event);
            return;
        }// end function

        override public function update() : void
        {
            super.update();
            return;
        }// end function

        override public function mouseMoveHandler(param1) : void
        {
            if (param1.target.name == "castIcemanCase")
            {
                if (container.currentFrame == 1)
                {
                    container.gotoAndStop(2);
                }
                if (world.worldInterface.container.butCastIceman.currentFrame != 6)
                {
                    world.worldInterface.container.butCastIceman.gotoAndStop(6);
                }
            }
            else
            {
                if (world.worldInterface.container.butCastIceman.currentFrame != 5)
                {
                    world.worldInterface.container.butCastIceman.gotoAndStop(5);
                }
                if (scanWay())
                {
                    if (container.currentFrame == 2)
                    {
                        container.gotoAndStop(1);
                    }
                }
                else if (container.currentFrame == 1)
                {
                    container.gotoAndStop(2);
                }
            }
            return;
        }// end function

        override public function mouseDownHandler(event:MouseEvent) : void
        {
            if (event)
            {
                if (event.target.name != "castIcemanCase" && scanWay())
                {
                    var _loc_2:* = true;
                    this.mouseChildren = true;
                    this.mouseEnabled = _loc_2;
                    event = new MouseEvent(MouseEvent.MOUSE_DOWN);
                    (world.worldInterface.castIcemanCounter + 1);
                    world.worldInterface.container.butCastIceman.gotoAndStop(4);
                    world.worldInterface.container.butCastIceman.castIcemanCase.buttonMode = false;
                    world.worldInterface.container.butCastIceman.cont.contMask.scaleY = 0;
                    this.addIceman();
                    kill();
                }
                else if (event.target.name == "castGolemCase" || event.target.name == "castIcemanCase" || event.target.name == "castAirCase")
                {
                    world.worldInterface.container.butCastIceman.gotoAndStop(1);
                    kill();
                }
            }
            container.gotoAndStop(3);
            return;
        }// end function

        override public function mouseUpHandler(event:MouseEvent = null) : void
        {
            return;
        }// end function

        public function addIceman() : void
        {
            tempObject = new Point(world.mouseX, world.mouseY);
            tempObject1 = null;
            tempObject2 = null;
            tempObject3 = 10000;
            n = 1;
            while (n <= Main.mainClass.readXMLClass.strategies)
            {
                
                if (n == 1)
                {
                    map = world.map.road1;
                }
                else if (n == 2)
                {
                    map = world.map.road2;
                }
                else if (n == 3)
                {
                    map = world.map.road3;
                }
                i = 1;
                while (i < map.length)
                {
                    
                    if (map[i].x == map[(i - 1)].x)
                    {
                        if (map[i].y >= map[(i - 1)].y)
                        {
                            j = map[(i - 1)].y;
                            while (j < map[i].y)
                            {
                                
                                tempObject2 = Point.distance(tempObject, new Point(map[i].x, j));
                                if (tempObject2 < 30)
                                {
                                    if (tempObject2 < tempObject3)
                                    {
                                        tempObject3 = tempObject2;
                                    }
                                    else
                                    {
                                        tempObject1 = new Iceman(new Point(map[i].x, j), n, i);
                                        world.addChild(tempObject1);
                                        return;
                                    }
                                }
                                j = j + 5;
                            }
                        }
                        else
                        {
                            j = map[(i - 1)].y;
                            while (j >= map[i].y)
                            {
                                
                                tempObject2 = Point.distance(tempObject, new Point(map[i].x, j));
                                if (tempObject2 < 30)
                                {
                                    if (tempObject2 < tempObject3)
                                    {
                                        tempObject3 = tempObject2;
                                    }
                                    else
                                    {
                                        tempObject1 = new Iceman(new Point(map[i].x, j), n, i);
                                        world.addChild(tempObject1);
                                        return;
                                    }
                                }
                                j = j - 5;
                            }
                        }
                    }
                    else if (map[i].y == map[(i - 1)].y)
                    {
                        if (map[i].x >= map[(i - 1)].x)
                        {
                            j = map[(i - 1)].x;
                            while (j < map[i].x)
                            {
                                
                                tempObject2 = Point.distance(tempObject, new Point(j, map[i].y));
                                if (tempObject2 < 30)
                                {
                                    if (tempObject2 < tempObject3)
                                    {
                                        tempObject3 = tempObject2;
                                    }
                                    else
                                    {
                                        tempObject1 = new Iceman(new Point(j, map[i].y), n, i);
                                        world.addChild(tempObject1);
                                        return;
                                    }
                                }
                                j = j + 5;
                            }
                        }
                        else
                        {
                            j = map[(i - 1)].x;
                            while (j >= map[i].x)
                            {
                                
                                tempObject2 = Point.distance(tempObject, new Point(j, map[i].y));
                                if (tempObject2 < 30)
                                {
                                    if (tempObject2 < tempObject3)
                                    {
                                        tempObject3 = tempObject2;
                                    }
                                    else
                                    {
                                        tempObject1 = new Iceman(new Point(j, map[i].y), n, i);
                                        world.addChild(tempObject1);
                                        return;
                                    }
                                }
                                j = j - 5;
                            }
                        }
                    }
                    var _loc_2:* = i + 1;
                    i = _loc_2;
                }
                var _loc_2:* = n + 1;
                n = _loc_2;
            }
            return;
        }// end function

    }
}
