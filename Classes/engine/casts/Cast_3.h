package engine.casts
{
    import flash.events.*;
    import flash.geom.*;

    public class Cast_3 extends Cast
    {
        public var direction:String;
        public var this_pt:Point;

        public function Cast_3()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            container = new MoveAir_mc();
            container.gotoAndStop(2);
            this.addChild(container);
            super.init(event);
            this.this_pt = new Point(world.mouseX, world.mouseY);
            return;
        }// end function

        override public function update() : void
        {
            this.directionManage();
            super.update();
            return;
        }// end function

        override public function mouseMoveHandler(param1) : void
        {
            if (param1.target.name == "castAirCase")
            {
                if (container.currentFrame == 1)
                {
                    container.gotoAndStop(2);
                }
                if (world.worldInterface.container.butCastAir.currentFrame != 6)
                {
                    world.worldInterface.container.butCastAir.gotoAndStop(6);
                }
            }
            else
            {
                if (world.worldInterface.container.butCastAir.currentFrame != 5)
                {
                    world.worldInterface.container.butCastAir.gotoAndStop(5);
                }
                if (scanWay())
                {
                    if (container.currentFrame == 2)
                    {
                        container.gotoAndStop(1);
                        container.left.stop();
                        container.right.stop();
                        container.up.stop();
                        container.down.stop();
                        container.left.visible = false;
                        container.right.visible = false;
                        container.up.visible = false;
                        container.down.visible = false;
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
                if (event.target.name != "castAirCase" && scanWay())
                {
                    var _loc_2:* = true;
                    this.mouseChildren = true;
                    this.mouseEnabled = _loc_2;
                    event = new MouseEvent(MouseEvent.MOUSE_DOWN);
                    (world.worldInterface.castAirCounter + 1);
                    world.worldInterface.container.butCastAir.gotoAndStop(4);
                    world.worldInterface.container.butCastAir.castAirCase.buttonMode = false;
                    world.worldInterface.container.butCastAir.cont.contMask.scaleY = 0;
                    this.addAir();
                    kill();
                }
                else if (event.target.name == "castGolemCase" || event.target.name == "castIcemanCase" || event.target.name == "castAirCase")
                {
                    world.worldInterface.container.butCastAir.gotoAndStop(1);
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

        public function directionManage() : void
        {
            if (container.currentFrame == 1)
            {
                if (this.this_pt.x != world.mouseX || this.this_pt.y != world.mouseY)
                {
                    this.this_pt = new Point(world.mouseX, world.mouseY);
                    tempObject1 = 10000;
                    tempObject3 = null;
                    container.left.visible = false;
                    container.right.visible = false;
                    container.up.visible = false;
                    container.down.visible = false;
                    if (world.nowLevel == 9)
                    {
                        if (tempObject.x >= 370 && tempObject.x <= 470 && tempObject.y >= 240 && tempObject.y <= 390)
                        {
                            this.direction = "left";
                            container.left.visible = true;
                        }
                    }
                    if (!container.left.visible)
                    {
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
                            i = map.length - 1;
                            while (i > 0)
                            {
                                
                                if (map[i].x == map[(i - 1)].x)
                                {
                                    if (map[i].y >= map[(i - 1)].y)
                                    {
                                        j = map[(i - 1)].y;
                                        while (j < map[i].y)
                                        {
                                            
                                            tempObject2 = Point.distance(this.this_pt, new Point(map[i].x, j));
                                            if (tempObject2 < 30)
                                            {
                                                if (tempObject2 < tempObject1)
                                                {
                                                    tempObject1 = tempObject2;
                                                    tempObject3 = new Point(map[i].x, j);
                                                    this.direction = "down";
                                                    container.down.visible = true;
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
                                            
                                            tempObject2 = Point.distance(this.this_pt, new Point(map[i].x, j));
                                            if (tempObject2 < 30)
                                            {
                                                if (tempObject2 < tempObject1)
                                                {
                                                    tempObject1 = tempObject2;
                                                    tempObject3 = new Point(map[i].x, j);
                                                    this.direction = "up";
                                                    container.up.visible = true;
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
                                            
                                            tempObject2 = Point.distance(this.this_pt, new Point(j, map[i].y));
                                            if (tempObject2 < 30)
                                            {
                                                if (tempObject2 < tempObject1)
                                                {
                                                    tempObject1 = tempObject2;
                                                    tempObject3 = new Point(j, map[i].y);
                                                    this.direction = "right";
                                                    container.right.visible = true;
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
                                            
                                            tempObject2 = Point.distance(this.this_pt, new Point(j, map[i].y));
                                            if (tempObject2 < 30)
                                            {
                                                if (tempObject2 < tempObject1)
                                                {
                                                    tempObject1 = tempObject2;
                                                    tempObject3 = new Point(j, map[i].y);
                                                    this.direction = "left";
                                                    container.left.visible = true;
                                                }
                                            }
                                            j = j - 5;
                                        }
                                    }
                                }
                                if (tempObject1 < tempObject2)
                                {
                                    break;
                                }
                                var _loc_2:* = i - 1;
                                i = _loc_2;
                            }
                            if (tempObject1 < tempObject2)
                            {
                                break;
                            }
                            var _loc_2:* = n + 1;
                            n = _loc_2;
                        }
                    }
                }
                if (container.left.visible)
                {
                    if (container.left.currentFrame < container.left.totalFrames)
                    {
                        container.left.gotoAndStop((container.left.currentFrame + 1));
                    }
                    else
                    {
                        container.left.gotoAndStop(1);
                    }
                }
                else if (container.right.visible)
                {
                    if (container.right.currentFrame < container.right.totalFrames)
                    {
                        container.right.gotoAndStop((container.right.currentFrame + 1));
                    }
                    else
                    {
                        container.right.gotoAndStop(1);
                    }
                }
                else if (container.up.visible)
                {
                    if (container.up.currentFrame < container.up.totalFrames)
                    {
                        container.up.gotoAndStop((container.up.currentFrame + 1));
                    }
                    else
                    {
                        container.up.gotoAndStop(1);
                    }
                }
                else if (container.down.visible)
                {
                    if (container.down.currentFrame < container.down.totalFrames)
                    {
                        container.down.gotoAndStop((container.down.currentFrame + 1));
                    }
                    else
                    {
                        container.down.gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

        public function addAir() : void
        {
            this.directionManage();
            if (tempObject3)
            {
                tempObject = new Air(tempObject3, this.direction);
            }
            else
            {
                tempObject = new Air(this.this_pt, this.direction);
            }
            world.addChild(tempObject);
            return;
        }// end function

    }
}
