package engine.bullets
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class Bullet extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var tempObject2:Object;
        public var dead:Boolean;
        public var world:World;
        public var container:MovieClip;
        public var enemyTarget:Object;
        public var damage:Number;
        public var bulletType:int;
        public var whoShoot:Object;
        public var liveCounter:int;
        public var liveTimer:int;
        public var distanceX:Number;
        public var distanceY:Number;
        public var this_pt:Point;
        public var enemy_pt:Point;
        public var spherePower:int;
        public var mainCounter:int = 0;
        public var changeIndex:int;
        public var radius:Number;
        public var testTarget:Object;
        public var testTower:Object;
        public var greenFlag:Boolean;

        public function Bullet()
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            this.world = Main.mainClass.worldClass;
            this.world.listOfBullets.push(this);
            this.world.listOfIndexes3.push(this);
            this.changeIndex = 10;
            return;
        }// end function

        public function update() : void
        {
            var _loc_1:* = this;
            var _loc_2:* = this.mainCounter + 1;
            _loc_1.mainCounter = _loc_2;
            if (this.mainCounter == this.changeIndex)
            {
                if (this.bulletType == 3 || this.bulletType == 5 || this.bulletType == 7)
                {
                    if (this.this_pt.y < this.whoShoot.y)
                    {
                        if (this.enemyTarget.y < this.whoShoot.y)
                        {
                            this.defaultIndex();
                        }
                        else
                        {
                            var _loc_1:* = this;
                            var _loc_2:* = this.changeIndex + 1;
                            _loc_1.changeIndex = _loc_2;
                        }
                    }
                    else
                    {
                        this.defaultIndex();
                    }
                }
                else
                {
                    this.defaultIndex();
                }
            }
            return;
        }// end function

        public function defaultIndex() : void
        {
            this.i = 0;
            while (this.i < this.world.listOfIndexes3.length)
            {
                
                if (this.world.listOfIndexes3[this.i] == this)
                {
                    this.world.listOfIndexes3.splice(this.i, 1);
                    break;
                }
                var _loc_1:* = this;
                var _loc_2:* = this.i + 1;
                _loc_1.i = _loc_2;
            }
            this.world.listOfIndexes2.push(this);
            return;
        }// end function

        public function scanAtRadius() : void
        {
            this.greenFlag = false;
            this.tempObject = this.radius - this.radius * (1 - this.world.scaleRadius);
            if ((this.testTarget.x - this.this_pt.x) * (this.testTarget.x - this.this_pt.x) / (this.radius * this.radius) + (this.testTarget.y - this.this_pt.y) * (this.testTarget.y - this.this_pt.y) / (this.tempObject * this.tempObject) <= 1)
            {
                this.greenFlag = true;
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.removeChild(this);
                this.i = 0;
                while (this.i < this.world.listOfBullets.length)
                {
                    
                    if (this.world.listOfBullets[this.i] == this)
                    {
                        this.world.listOfBullets.splice(this.i, 1);
                        break;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
                this.i = 0;
                while (this.i < this.world.listOfIndexes2.length)
                {
                    
                    if (this.world.listOfIndexes2[this.i] == this)
                    {
                        this.world.listOfIndexes2.splice(this.i, 1);
                        break;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
                this.i = 0;
                while (this.i < this.world.listOfIndexes3.length)
                {
                    
                    if (this.world.listOfIndexes3[this.i] == this)
                    {
                        this.world.listOfIndexes3.splice(this.i, 1);
                        break;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            return;
        }// end function

    }
}
