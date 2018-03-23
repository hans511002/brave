package engine
{

    public class CallDelay extends Object
    {
        public var i:int;
        public var tempObject:Object;
        public var type:String;
        public var type1:int;
        public var counter:int;
        public var dead:Boolean;
        public var world:World;

        public function CallDelay(param1:String, param2:int)
        {
            this.world = Main.mainClass.worldClass;
            this.type = param1;
            this.type1 = param2;
            if (this.type == "newElement")
            {
                this.counter = 60;
            }
            this.world.listOfClasses.push(this);
            return;
        }// end function

        public function update() : void
        {
            if (this.counter > 0)
            {
                (this.counter - 1);
            }
            else
            {
                if (this.type == "newElement")
                {
                    if (this.type1 > 1 && this.type1 < 5)
                    {
                        this.tempObject = new Training_11(this.type1);
                        this.world.worldInterface.addChild(this.tempObject);
                    }
                    this.tempObject = new NewElement_mc();
                    this.tempObject.stop();
                    this.tempObject.newElementCase.stop();
                    this.tempObject.type = this.type1;
                    this.tempObject.soundFlag = true;
                    this.tempObject.newElementCase.buttonMode = true;
                    this.world.worldInterface.addChild(this.tempObject);
                    this.world.worldInterface.listOfNewEnemies.push(this.tempObject);
                    this.world.worldInterface.newEnemyUpdate();
                    Sounds.instance.playSoundWithVol("snd_world_newEnemy", 0.9);
                }
                this.kill();
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
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
