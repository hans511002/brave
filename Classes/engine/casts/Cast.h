package engine.casts
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;

    public class Cast extends Sprite
    {
        public var i:int;
        public var j:int;
        public var n:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var tempObject2:Object;
        public var tempObject3:Object;
        public var container:MovieClip;
        public var world:World;
        public var dead:Boolean;
        public var map:Array;
        public var canselCounter:int = 0;
        public var canselTimer:int;

        public function Cast()
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.canselTimer = 5;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.world = Main.mainClass.worldClass;
            this.x = this.world.mouseX;
            this.y = this.world.mouseY;
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            this.world.hint.visible = false;
            this.world.worldInterface.barInfoManage(this);
            return;
        }// end function

        public function update() : void
        {
            this.world.feature.scanPointersAtCast();
            this.x = this.world.mouseX;
            this.y = this.world.mouseY;
            if (this.container.currentFrame == 3)
            {
                if (this.canselCounter < this.canselTimer)
                {
                    (this.canselCounter + 1);
                }
                else
                {
                    this.canselCounter = 0;
                    this.container.gotoAndStop(2);
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent = null) : void
        {
            return;
        }// end function

        public function scanWay() : Boolean
        {
            this.tempObject = new Point(this.world.mouseX, this.world.mouseY);
            if (this.world.nowLevel == 6)
            {
                if (this.tempObject.x > 650 && this.tempObject.y < 320)
                {
                    return false;
                }
            }
            else if (this.world.nowLevel == 11)
            {
                if (this.tempObject.x > 390 && this.tempObject.x < 656 && this.tempObject.y < 190)
                {
                    return false;
                }
            }
            else if (this.world.nowLevel == 13)
            {
                if (this.tempObject.x > 480 && this.tempObject.x < 550 && this.tempObject.y > 277)
                {
                    return false;
                }
            }
            else if (this.world.nowLevel == 14)
            {
                if (this.tempObject.x > 645 && this.tempObject.y > 440)
                {
                    return false;
                }
            }
            else if (this.world.nowLevel == 15)
            {
                if (this.tempObject.x >= 366 && this.tempObject.x <= 447 && this.tempObject.y < 296)
                {
                    return false;
                }
            }
            if (this is Cast_3)
            {
                if (this.world.nowLevel == 9)
                {
                    if (this.tempObject.x >= 370 && this.tempObject.x <= 470 && this.tempObject.y >= 240 && this.tempObject.y <= 390)
                    {
                        return true;
                    }
                }
                if (this.world.nowLevel == 15)
                {
                }
            }
            this.n = 1;
            while (this.n <= Main.mainClass.readXMLClass.strategies)
            {
                
                if (this.n == 1)
                {
                    this.map = this.world.map.road1;
                }
                else if (this.n == 2)
                {
                    this.map = this.world.map.road2;
                }
                else if (this.n == 3)
                {
                    this.map = this.world.map.road3;
                }
                this.i = 1;
                while (this.i < this.map.length)
                {
                    
                    if (this.map[this.i].x == this.map[(this.i - 1)].x)
                    {
                        if (this.map[this.i].y >= this.map[(this.i - 1)].y)
                        {
                            this.j = this.map[(this.i - 1)].y;
                            while (this.j < this.map[this.i].y)
                            {
                                
                                if (Point.distance(this.tempObject, new Point(this.map[this.i].x, this.j)) < 30)
                                {
                                    return true;
                                }
                                this.j = this.j + 10;
                            }
                        }
                        else
                        {
                            this.j = this.map[(this.i - 1)].y;
                            while (this.j >= this.map[this.i].y)
                            {
                                
                                if (Point.distance(this.tempObject, new Point(this.map[this.i].x, this.j)) < 30)
                                {
                                    return true;
                                }
                                this.j = this.j - 10;
                            }
                        }
                    }
                    else if (this.map[this.i].y == this.map[(this.i - 1)].y)
                    {
                        if (this.map[this.i].x >= this.map[(this.i - 1)].x)
                        {
                            this.j = this.map[(this.i - 1)].x;
                            while (this.j < this.map[this.i].x)
                            {
                                
                                if (Point.distance(this.tempObject, new Point(this.j, this.map[this.i].y)) < 30)
                                {
                                    return true;
                                }
                                this.j = this.j + 10;
                            }
                        }
                        else
                        {
                            this.j = this.map[(this.i - 1)].x;
                            while (this.j >= this.map[this.i].x)
                            {
                                
                                if (Point.distance(this.tempObject, new Point(this.j, this.map[this.i].y)) < 30)
                                {
                                    return true;
                                }
                                this.j = this.j - 10;
                            }
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
                var _loc_1:* = this;
                var _loc_2:* = this.n + 1;
                _loc_1.n = _loc_2;
            }
            return false;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.worldInterface.castRegime("off");
                this.i = 0;
                while (this.i < this.world.listOfClasses.length)
                {
                    
                    if (this.world.listOfClasses[this.i] == this)
                    {
                        this.world.listOfClasses.splice(this.i, 1);
                        break;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
                this.world.removeChild(this.world.cast);
                this.world.cast = null;
                this.world.worldInterface.autoguidersButtons();
            }
            return;
        }// end function

    }
}
