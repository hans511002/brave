package engine
{
    import flash.display.*;
    import flash.events.*;

    public class BonusMoney extends Sprite
    {
        public var i:int;
        public var dead:Boolean;
        public var world:World;
        public var container:BonusMoney_mc;
        public var counter:int = 0;

        public function BonusMoney()
        {
            this.world = Main.mainClass.worldClass;
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.container = new BonusMoney_mc();
            this.container.stop();
            this.container.cont.stop();
            this.container.cont.noteTXT.text = "+" + this.world.bonusMoney;
            this.container.x = Main.SCREEN_WIDTH_HALF;
            this.container.y = Main.SCREEN_HEIGHT_HALF;
            this.addChild(this.container);
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            this.world.listOfIndexes3.push(this);
            this.world.listOfClasses.push(this);
            return;
        }// end function

        public function update() : void
        {
            if (this.container.currentFrame < this.container.totalFrames)
            {
                this.container.gotoAndStop((this.container.currentFrame + 1));
                if (this.container.currentFrame == this.container.totalFrames)
                {
                    this.world.money = this.world.money + this.world.bonusMoney;
                    this.world.worldInterface.updateInfo();
                }
            }
            else if (this.counter < 30)
            {
                (this.counter + 1);
            }
            else if (this.container.alpha > 0)
            {
                this.container.alpha = this.container.alpha - 0.2;
            }
            else
            {
                this.kill();
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
            }
            return;
        }// end function

    }
}
