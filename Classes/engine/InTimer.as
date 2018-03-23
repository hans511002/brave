package engine
{

    public class InTimer extends Object
    {
        public var i:int;
        public var tempObject:Object;
        public var counter:int = 0;
        public var type:String;
        public var dead:Boolean;
        public var world:World;

        public function InTimer(param1:String)
        {
            this.world = Main.mainClass.worldClass;
            this.type = param1;
            this.world.listOfClasses.push(this);
            return;
        }// end function

        public function update() : void
        {
            if (this.type == "bossDeath")
            {
                if (this.counter < 183)
                {
                    (this.counter + 1);
                }
                else
                {
                    Sounds.instance.playSound("snd_boss_death");
                    this.kill();
                }
            }
            else if (this.type == "bossSpeakInDeath")
            {
                if (this.counter < 44)
                {
                    (this.counter + 1);
                }
                else
                {
                    Sounds.instance.playSound("snd_boss_speak");
                    this.kill();
                }
            }
            else if (this.type == "openIce")
            {
                if (this.counter < 30)
                {
                    (this.counter + 1);
                }
                else
                {
                    this.world.worldInterface.container.iceSphere.visible = true;
                    var _loc_1:* = 0;
                    this.world.worldInterface.container.iceSphere.scaleY = 0;
                    this.world.worldInterface.container.iceSphere.scaleX = _loc_1;
                    this.tempObject = new AnimUpgrade_mc();
                    this.tempObject.stop();
                    this.tempObject.x = this.world.worldInterface.container.iceSphere.x;
                    this.tempObject.y = this.world.worldInterface.container.iceSphere.y;
                    var _loc_1:* = false;
                    this.tempObject.mouseChildren = false;
                    this.tempObject.mouseEnabled = _loc_1;
                    this.world.worldInterface.addChild(this.tempObject);
                    this.world.worldInterface.listOfAnimation.push(this.tempObject);
                    Sounds.instance.playSound("snd_menu_upgrIconMouseDown");
                    this.kill();
                }
            }
            else if (this.type == "openLevin")
            {
                if (this.counter < 30)
                {
                    (this.counter + 1);
                }
                else
                {
                    this.world.worldInterface.container.levinSphere.visible = true;
                    var _loc_1:* = 0;
                    this.world.worldInterface.container.levinSphere.scaleY = 0;
                    this.world.worldInterface.container.levinSphere.scaleX = _loc_1;
                    this.tempObject = new AnimUpgrade_mc();
                    this.tempObject.stop();
                    this.tempObject.x = this.world.worldInterface.container.levinSphere.x;
                    this.tempObject.y = this.world.worldInterface.container.levinSphere.y;
                    var _loc_1:* = false;
                    this.tempObject.mouseChildren = false;
                    this.tempObject.mouseEnabled = _loc_1;
                    this.world.worldInterface.addChild(this.tempObject);
                    this.world.worldInterface.listOfAnimation.push(this.tempObject);
                    Sounds.instance.playSound("snd_menu_upgrIconMouseDown");
                    if (Main.mainClass.saveBoxClass.gameSave.data.saveNo > 3)
                    {
                        this.world.worldInterface.spheresBlockManage("unblockGetAll");
                        new CallDelay("newElement", 8);
                    }
                    this.kill();
                }
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
