package engine.casts
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class Air extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:Air_mc;
        public var this_pt:Point;
        public var enemy_pt:Point;
        public var world:World;
        public var direction:String = "无";
        public var radius:Number;
        public var dead:Boolean;
        public var openFlag:Boolean = true;
        public var openCounter:int = 0;
        public var workFlag:Boolean;
        public var liveCounter:int;
        public var voiceCounter:int = 10;
        public var shoot_pt:Point;
        public var cameraJitterTimer:int = 5;
        public var cameraJitterCounter:int;
        public var cameraXOffset:Number;
        public var cameraYOffset:Number;

        public function Air(param1:Point, param2:String = "无")
        {
            this.cameraJitterCounter = this.cameraJitterTimer;
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.this_pt = param1;
            this.direction = param2;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.world = Main.mainClass.worldClass;
            this.container = new Air_mc();
            if (this.direction == "left")
            {
                this.container.gotoAndStop(1);
            }
            else if (this.direction == "right")
            {
                this.container.gotoAndStop(2);
            }
            else if (this.direction == "up")
            {
                this.container.gotoAndStop(3);
            }
            else if (this.direction == "down")
            {
                this.container.gotoAndStop(4);
            }
            this.container.cont.gotoAndStop(48);
            this.container.dust1.stop();
            this.container.dust2.stop();
            this.container.dust1.visible = false;
            this.container.dust2.visible = false;
            this.addChild(this.container);
            this.radius = 125;
            this.liveCounter = Main.mainClass.readXMLClass.airLifeSecXML;
            this.x = this.this_pt.x;
            this.y = this.this_pt.y;
            this.container.alpha = 0.1;
            this.y = this.y - 200;
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            this.world.listOfClasses.push(this);
            this.world.listOfIndexes1.push(this);
            this.world.worldInterface.barInfoManage(this);
            (this.world.createAirCounter + 1);
            if (this.world.createAirCounter == 7)
            {
                this.world.achieveManage("createAir_7_times");
            }
            return;
        }// end function

        public function update() : void
        {
            if (!this.openFlag)
            {
                if (this.voiceCounter > 0)
                {
                    (this.voiceCounter - 1);
                    if (this.voiceCounter == 0)
                    {
                        if (this.world.airVoiceTurn == 1)
                        {
                            this.world.airVoiceTurn = 2;
                            Sounds.instance.playSoundWithVol("snd_air_voice1", 0.9);
                        }
                        else if (this.world.airVoiceTurn == 2)
                        {
                            this.world.airVoiceTurn = 3;
                            Sounds.instance.playSoundWithVol("snd_air_voice2", 0.9);
                        }
                        else if (this.world.airVoiceTurn == 3)
                        {
                            this.world.airVoiceTurn = 4;
                            Sounds.instance.playSoundWithVol("snd_air_voice4", 0.9);
                        }
                        else if (this.world.airVoiceTurn == 4)
                        {
                            this.world.airVoiceTurn = 1;
                            Sounds.instance.playSoundWithVol("snd_air_voice5", 0.9);
                        }
                    }
                }
                if (this.liveCounter > 0)
                {
                    (this.liveCounter - 1);
                }
                if (this.liveCounter == 0 && !this.workFlag)
                {
                    this.kill();
                    if (this.direction == "left")
                    {
                        this.tempObject = new Indexes(new DeathAit1_mc(), 1);
                    }
                    else if (this.direction == "right")
                    {
                        this.tempObject = new Indexes(new DeathAit1_mc(), 1);
                    }
                    else if (this.direction == "up")
                    {
                        this.tempObject = new Indexes(new DeathAit2_mc(), 1);
                    }
                    else if (this.direction == "down")
                    {
                        this.tempObject = new Indexes(new DeathAit3_mc(), 1);
                    }
                    this.tempObject.container.scaleX = this.container.scaleX;
                    this.tempObject.type = "airDeath";
                    this.tempObject.x = this.this_pt.x;
                    this.tempObject.y = this.this_pt.y;
                    Sounds.instance.playSound("snd_air_goodBye");
                }
                else if (!this.workFlag)
                {
                    this.scan();
                }
                else
                {
                    this.attack();
                }
            }
            else
            {
                (this.openCounter + 1);
                if (this.openCounter == 5)
                {
                    Sounds.instance.playSound("snd_air_addToWorld");
                }
                if (this.container.alpha < 1)
                {
                    this.container.alpha = this.container.alpha + 0.2;
                    this.y = this.y + 40;
                }
                else
                {
                    if (!this.container.dust1.visible && !this.container.dust2.visible)
                    {
                        this.container.dust1.visible = true;
                        this.container.dust2.visible = true;
                        this.y = this.this_pt.y;
                        this.container.alpha = 1;
                    }
                    if (this.cameraJitterCounter <= 0)
                    {
                        if (this.cameraJitterCounter == 0)
                        {
                            this.cameraJitterCounter = -1;
                            var _loc_1:* = 0;
                            this.world.y = 0;
                            this.world.x = _loc_1;
                            var _loc_1:* = 0;
                            this.world.worldInterface.y = 0;
                            this.world.worldInterface.x = _loc_1;
                            this.openFlag = false;
                            this.world.decoration.earthquakeFlag = true;
                            this.shoot_pt = this.container.localToGlobal(new Point(this.container.cont.x, this.container.cont.y));
                        }
                    }
                    else
                    {
                        (this.cameraJitterCounter - 1);
                        this.cameraXOffset = Math.random() * 2;
                        if (Math.random() < 0.5)
                        {
                            this.cameraXOffset = -this.cameraXOffset;
                        }
                        this.cameraYOffset = Math.random() * 2;
                        if (Math.random() < 0.5)
                        {
                            this.cameraYOffset = -this.cameraYOffset;
                        }
                        this.world.x = this.world.x + this.cameraXOffset;
                        this.world.y = this.world.y + this.cameraYOffset;
                        this.tempObject = Main.mainClass.worldClass.globalToLocal(new Point(0, 0));
                        this.world.worldInterface.x = this.tempObject.x;
                        this.world.worldInterface.y = this.tempObject.y;
                        this.world.hint.x = this.world.hint.x + this.tempObject.x;
                        this.world.hint.y = this.world.hint.y + this.tempObject.y;
                    }
                    if (this.container.cont.currentFrame == 48)
                    {
                        this.container.cont.gotoAndStop(49);
                    }
                    else if (this.container.cont.currentFrame == 49)
                    {
                        this.container.cont.gotoAndStop(1);
                        this.container.cont.blowing.stop();
                        this.container.cont.blowing.visible = false;
                    }
                }
            }
            if (this.container.dust1.visible)
            {
                if (this.container.dust1.currentFrame < 47)
                {
                    this.container.dust1.gotoAndStop((this.container.dust1.currentFrame + 1));
                }
                else
                {
                    this.container.dust1.gotoAndStop(1);
                    this.container.dust1.visible = false;
                }
            }
            if (this.container.dust2.visible)
            {
                if (this.container.dust2.currentFrame < 47)
                {
                    this.container.dust2.gotoAndStop((this.container.dust2.currentFrame + 1));
                }
                else
                {
                    this.container.dust2.gotoAndStop(1);
                    this.container.dust2.visible = false;
                }
            }
            return;
        }// end function

        public function scan() : void
        {
            this.i = 0;
            while (this.i < this.world.listOfUnits.length)
            {
                
                if (this.world.listOfUnits[this.i].readyDamage && this.world.listOfUnits[this.i].atStage && !this.world.listOfUnits[this.i].airFlag)
                {
                    this.tempObject = Point.distance(this.world.listOfUnits[this.i].shoot_pt, this.shoot_pt);
                    if (this.tempObject < this.radius)
                    {
                        if (this.direction == "left" || this.direction == "right")
                        {
                            if (this.world.listOfUnits[this.i].shoot_pt.y > this.shoot_pt.y - 30 && this.world.listOfUnits[this.i].shoot_pt.y < this.shoot_pt.y + 30)
                            {
                                if (this.direction == "left")
                                {
                                    if (this.world.listOfUnits[this.i].shoot_pt.x < this.shoot_pt.x)
                                    {
                                        this.workFlag = true;
                                        break;
                                    }
                                }
                                else if (this.direction == "right")
                                {
                                    if (this.world.listOfUnits[this.i].shoot_pt.x > this.shoot_pt.x)
                                    {
                                        this.workFlag = true;
                                        break;
                                    }
                                }
                            }
                        }
                        else if (this.direction == "up" || this.direction == "down")
                        {
                            if (this.world.listOfUnits[this.i].shoot_pt.x > this.shoot_pt.x - 30 && this.world.listOfUnits[this.i].shoot_pt.x < this.shoot_pt.x + 30)
                            {
                                if (this.direction == "up")
                                {
                                    if (this.world.listOfUnits[this.i].shoot_pt.y < this.shoot_pt.y)
                                    {
                                        this.workFlag = true;
                                        break;
                                    }
                                }
                                else if (this.direction == "down")
                                {
                                    if (this.world.listOfUnits[this.i].shoot_pt.y > this.shoot_pt.y)
                                    {
                                        this.workFlag = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                var _loc_1:* = this;
                var _loc_2:* = this.i + 1;
                _loc_1.i = _loc_2;
            }
            return;
        }// end function

        public function attack() : void
        {
            if (!this.container.cont.blowing.visible)
            {
                this.container.cont.blowing.visible = true;
            }
            else if (this.container.cont.currentFrame < 47)
            {
                this.container.cont.gotoAndStop((this.container.cont.currentFrame + 1));
                this.container.cont.blowing.gotoAndStop((this.container.cont.blowing.currentFrame + 1));
                if (this.container.cont.currentFrame == 2)
                {
                    Sounds.instance.playSoundWithVol("snd_air_blow", 0.65);
                }
                else if (this.container.cont.currentFrame > 20)
                {
                    this.i = 0;
                    while (this.i < this.world.listOfUnits.length)
                    {
                        
                        if (this.world.listOfUnits[this.i].atStage && this.world.listOfUnits[this.i].readyDamage && !this.world.listOfUnits[this.i].airFlag && !this.world.listOfUnits[this.i].teleportFlag)
                        {
                            this.tempObject = Point.distance(this.world.listOfUnits[this.i].shoot_pt, this.shoot_pt);
                            if (this.tempObject < this.radius)
                            {
                                if (this.direction == "left" || this.direction == "right")
                                {
                                    if (this.world.listOfUnits[this.i].shoot_pt.y > this.shoot_pt.y - 30 && this.world.listOfUnits[this.i].shoot_pt.y < this.shoot_pt.y + 30)
                                    {
                                        if (this.direction == "left")
                                        {
                                            if (this.world.listOfUnits[this.i].shoot_pt.x < this.shoot_pt.x)
                                            {
                                                this.world.listOfUnits[this.i].setAirSettings("air");
                                            }
                                        }
                                        else if (this.direction == "right")
                                        {
                                            if (this.world.listOfUnits[this.i].shoot_pt.x > this.shoot_pt.x)
                                            {
                                                this.world.listOfUnits[this.i].setAirSettings("air");
                                            }
                                        }
                                    }
                                }
                                else if (this.direction == "up" || this.direction == "down")
                                {
                                    if (this.world.listOfUnits[this.i].shoot_pt.x > this.shoot_pt.x - 30 && this.world.listOfUnits[this.i].shoot_pt.x < this.shoot_pt.x + 30)
                                    {
                                        if (this.direction == "up")
                                        {
                                            if (this.world.listOfUnits[this.i].shoot_pt.y < this.shoot_pt.y)
                                            {
                                                this.world.listOfUnits[this.i].setAirSettings("air");
                                            }
                                        }
                                        else if (this.direction == "down")
                                        {
                                            if (this.world.listOfUnits[this.i].shoot_pt.y > this.shoot_pt.y)
                                            {
                                                this.world.listOfUnits[this.i].setAirSettings("air");
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        var _loc_1:* = this;
                        var _loc_2:* = this.i + 1;
                        _loc_1.i = _loc_2;
                    }
                }
            }
            else
            {
                this.container.cont.gotoAndStop(1);
                this.container.cont.blowing.gotoAndStop(1);
                this.container.cont.blowing.visible = false;
                this.workFlag = false;
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
                var _loc_1:* = 0;
                this.world.y = 0;
                this.world.x = _loc_1;
                var _loc_1:* = 0;
                this.world.worldInterface.y = 0;
                this.world.worldInterface.x = _loc_1;
                if (this.world.selectObject == this)
                {
                    this.world.worldInterface.barInfoManage();
                }
            }
            return;
        }// end function

    }
}
