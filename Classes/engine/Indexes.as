package engine
{
    import flash.display.*;

    public class Indexes extends Sprite
    {
        public var i:int;
        public var tempObject:Object;
        public var world:World;
        public var container:MovieClip;
        public var indexParam:int;
        public var alphaParam:Number;
        public var type:String = "default";
        public var speedX:Number = 0;
        public var speedY:Number = 0;

        public function Indexes(param1:MovieClip, param2:int, param3:Number = 0)
        {
            this.world = Main.mainClass.worldClass;
            this.container = param1;
            this.container.stop();
            this.addChild(this.container);
            this.indexParam = param2;
            this.alphaParam = param3;
            if (this.indexParam == 0)
            {
                this.world.listOfIndexes0.push(this);
            }
            else if (this.indexParam == 1)
            {
                this.world.listOfIndexes1.push(this);
            }
            else if (this.indexParam == 2)
            {
                this.world.listOfIndexes2.push(this);
            }
            else if (this.indexParam == 3)
            {
                this.world.listOfIndexes3.push(this);
            }
            this.world.addChild(this);
            this.world.listOfClasses.push(this);
            var _loc_4:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_4;
            this.world.forseIndexFl = true;
            return;
        }// end function

        public function update() : void
        {
            if (this.container.currentFrame < this.container.totalFrames && this.container.alpha > 0)
            {
                this.container.gotoAndStop((this.container.currentFrame + 1));
                this.container.alpha = this.container.alpha - this.alphaParam;
                this.x = this.x + this.speedX;
                this.y = this.y + this.speedY;
            }
            else
            {
                this.world.removeChild(this);
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
                if (this.indexParam == 0)
                {
                    this.i = 0;
                    while (this.i < this.world.listOfIndexes0.length)
                    {
                        
                        if (this.world.listOfIndexes0[this.i] == this)
                        {
                            this.world.listOfIndexes0.splice(this.i, 1);
                            break;
                        }
                        var _loc_1:* = this;
                        var _loc_2:* = this.i + 1;
                        _loc_1.i = _loc_2;
                    }
                }
                else if (this.indexParam == 1)
                {
                    this.i = 0;
                    while (this.i < this.world.listOfIndexes1.length)
                    {
                        
                        if (this.world.listOfIndexes1[this.i] == this)
                        {
                            this.world.listOfIndexes1.splice(this.i, 1);
                            break;
                        }
                        var _loc_1:* = this;
                        var _loc_2:* = this.i + 1;
                        _loc_1.i = _loc_2;
                    }
                }
                else if (this.indexParam == 2)
                {
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
                }
                else if (this.indexParam == 3)
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
                }
            }
            return;
        }// end function

    }
}
