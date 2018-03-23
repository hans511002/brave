package engine.casts
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;
    import flash.media.*;
    import flash.utils.*;

    public class Iceman extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:MovieClip;
        public var this_pt:Point;
        public var enemy_pt:Point;
        public var world:World;
        public var direction:String = "无";
        public var movePhase:int = 1;
        public var speedK:Number;
        public var speedKSave:Number;
        public var radius:Number;
        public var road:int;
        public var roadMap:Array;
        public var dead:Boolean;
        public var openFlag:Boolean;
        public var blow:MovieClip;
        public var liveCounter:int;
        public var soundTimerMove:Timer;
        public var soundChannelMove:SoundChannel;
        public var voiceCounter:int = 10;
        public var rotationTimer:int = 4;
        public var rotateFlag:String;
        public var brother:Iceman;
        public var roadAnimaTimer:int = 7;
        public var roadAnimaCounter:int = 0;

        public function Iceman(param1:Point, param2:int, param3:int, param4:Boolean = true)
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.this_pt = param1;
            this.road = param2;
            this.movePhase = param3;
            this.openFlag = param4;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.world = Main.mainClass.worldClass;
            this.container = new Iceman_mc();
            this.container.stop();
            this.addChild(this.container);
            var _loc_2:* = Main.mainClass.readXMLClass.castIcemanSpeedXML;
            this.speedKSave = Main.mainClass.readXMLClass.castIcemanSpeedXML;
            this.speedK = _loc_2;
            this.radius = 30;
            this.liveCounter = Main.mainClass.readXMLClass.castIcemanLifeTimerXML;
            if (this.road == 1)
            {
                this.roadMap = this.world.map.road1;
            }
            else if (this.road == 2)
            {
                this.roadMap = this.world.map.road2;
            }
            else if (this.road == 3)
            {
                this.roadMap = this.world.map.road3;
            }
            if (this.roadMap[this.movePhase].x != this.roadMap[(this.movePhase - 1)].x)
            {
                if (this.roadMap[this.movePhase].x < this.roadMap[(this.movePhase - 1)].x)
                {
                    this.container.scaleX = this.container.scaleX * -1;
                }
            }
            else
            {
                this.scanNextTurn();
            }
            this.x = this.this_pt.x;
            this.y = this.this_pt.y;
            if (this.openFlag)
            {
                this.container.alpha = 0;
                this.blow = new BlowIce_mc();
                this.blow.stop();
                this.addChild(this.blow);
                this.x = this.x + 84;
                this.y = this.y - 238;
            }
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            this.world.listOfClasses.push(this);
            this.world.listOfIndexes1.push(this);
            if (!this.world.selectObject)
            {
                this.world.worldInterface.barInfoManage(this);
            }
            if (!this.brother)
            {
                (this.world.createIcemanCounter + 1);
                if (this.world.createIcemanCounter == 15)
                {
                    this.world.achieveManage("createIceman_15_times");
                }
            }
            return;
        }// end function

        public function update() : void
        {
            if (!this.openFlag)
            {
                this.soundTimerManageMove(true);
                if (this.liveCounter > 0)
                {
                    (this.liveCounter - 1);
                }
                if (this.liveCounter == 0)
                {
                    this.kill();
                    if (this.direction == "left")
                    {
                        this.tempObject = new Indexes(new IcemanHorisontDeath_mc(), 2);
                        this.tempObject.speedX = this.speedK * -1;
                    }
                    else if (this.direction == "right")
                    {
                        this.tempObject = new Indexes(new IcemanHorisontDeath_mc(), 2);
                        this.tempObject.speedX = this.speedK;
                    }
                    else if (this.direction == "up")
                    {
                        this.tempObject = new Indexes(new IcemanVerticalDeath_mc(), 2);
                        this.tempObject.speedY = this.speedK * -1;
                    }
                    else if (this.direction == "down")
                    {
                        this.tempObject = new Indexes(new IcemanHorisontDeath_mc(), 2);
                        this.tempObject.speedY = this.speedK;
                    }
                    else
                    {
                        this.tempObject = new Indexes(new IcemanHorisontDeath_mc(), 2);
                    }
                    this.tempObject.type = "icemanDeath";
                    this.tempObject.container.scaleX = this.container.scaleX;
                    this.tempObject.container.x = this.container.x;
                    this.tempObject.x = this.this_pt.x;
                    this.tempObject.y = this.this_pt.y;
                }
                else
                {
                    if (this.voiceCounter > 0)
                    {
                        (this.voiceCounter - 1);
                        if (this.voiceCounter == 0)
                        {
                            if (this.world.icemanVoiceTurn == 1)
                            {
                                this.world.icemanVoiceTurn = 2;
                                Sounds.instance.playSoundWithVol("snd_iceman_voice2", 0.5);
                            }
                            else if (this.world.icemanVoiceTurn == 2)
                            {
                                this.world.icemanVoiceTurn = 3;
                                Sounds.instance.playSoundWithVol("snd_iceman_voice3", 0.5);
                            }
                            else if (this.world.icemanVoiceTurn == 3)
                            {
                                this.world.icemanVoiceTurn = 4;
                                Sounds.instance.playSoundWithVol("snd_iceman_voice4", 0.5);
                            }
                            else if (this.world.icemanVoiceTurn == 4)
                            {
                                this.world.icemanVoiceTurn = 1;
                                Sounds.instance.playSoundWithVol("snd_iceman_voice5", 0.5);
                            }
                        }
                    }
                    if (this.roadAnimaCounter < this.roadAnimaTimer)
                    {
                        (this.roadAnimaCounter + 1);
                    }
                    else
                    {
                        this.roadAnimaCounter = 0;
                        this.tempObject = new Indexes(new IceRoad_mc(), 1);
                        this.tempObject.x = this.this_pt.x;
                        this.tempObject.y = this.this_pt.y;
                        this.world.setChildIndex(this.tempObject, (this.world.getChildIndex(this) - 1));
                        if (this.direction == "left")
                        {
                        }
                        else if (this.direction == "right")
                        {
                            this.tempObject.container.scaleX = this.tempObject.container.scaleX * -1;
                        }
                        else if (this.direction == "up")
                        {
                            this.tempObject.container.rotation = this.tempObject.container.rotation + 90;
                        }
                        else if (this.direction == "down")
                        {
                            this.tempObject.container.rotation = this.tempObject.container.rotation + 270;
                            this.tempObject.y = this.tempObject.y - 10;
                        }
                    }
                    this.moveHandler();
                    this.attack();
                    if (this.direction == "left" || this.direction == "right")
                    {
                        if (this.container.currentFrame < 50)
                        {
                            this.container.gotoAndStop((this.container.currentFrame + 1));
                        }
                        else
                        {
                            this.container.gotoAndStop(1);
                        }
                    }
                    else if (this.direction == "up")
                    {
                        if (this.container.currentFrame < this.container.totalFrames)
                        {
                            this.container.gotoAndStop((this.container.currentFrame + 1));
                        }
                        else
                        {
                            this.container.gotoAndStop(101);
                        }
                    }
                    else if (this.direction == "down")
                    {
                        if (this.container.currentFrame < 100)
                        {
                            this.container.gotoAndStop((this.container.currentFrame + 1));
                        }
                        else
                        {
                            this.container.gotoAndStop(51);
                        }
                    }
                }
                if (this.blow)
                {
                    if (this.blow.currentFrame < this.blow.totalFrames)
                    {
                        this.blow.gotoAndStop((this.blow.currentFrame + 1));
                        this.container.alpha = this.container.alpha + 1 / this.blow.totalFrames;
                    }
                    else
                    {
                        this.container.alpha = 1;
                        this.removeChild(this.blow);
                        this.blow = null;
                    }
                }
            }
            else if (Math.abs(this.x - this.this_pt.x) > 1 || Math.abs(this.y - this.this_pt.y) > 1)
            {
                this.x = this.x - 8.4;
                this.y = this.y + 23.8;
            }
            else
            {
                this.openFlag = false;
                if (this.x != this.this_pt.x)
                {
                    this.x = this.this_pt.x;
                }
                if (this.y != this.this_pt.y)
                {
                    this.y = this.this_pt.y;
                }
                this.moveHandler();
            }
            return;
        }// end function

        public function moveHandler() : void
        {
            if (this.this_pt.x == this.roadMap[this.movePhase].x)
            {
                if (this.this_pt.y >= this.roadMap[this.movePhase].y)
                {
                    this.y = this.y - this.speedK;
                    if (this.y <= this.roadMap[this.movePhase].y)
                    {
                        this.tempObject = this.y;
                        this.y = this.roadMap[this.movePhase].y;
                        this.bifurcation();
                        var _loc_1:* = this;
                        var _loc_2:* = this.movePhase + 1;
                        _loc_1.movePhase = _loc_2;
                        if (this.movePhase < this.roadMap.length)
                        {
                            if (this.tempObject < this.roadMap[this.movePhase].y)
                            {
                                this.speedK = this.roadMap[this.movePhase].y - this.tempObject;
                                this.moveHandler();
                            }
                        }
                        else
                        {
                            this.kill();
                        }
                    }
                    else if (this.speedK != this.speedKSave)
                    {
                        this.speedK = this.speedKSave;
                    }
                }
                else
                {
                    this.y = this.y + this.speedK;
                    if (this.y >= this.roadMap[this.movePhase].y)
                    {
                        this.tempObject = this.y;
                        this.y = this.roadMap[this.movePhase].y;
                        this.bifurcation();
                        var _loc_1:* = this;
                        var _loc_2:* = this.movePhase + 1;
                        _loc_1.movePhase = _loc_2;
                        if (this.movePhase < this.roadMap.length)
                        {
                            if (this.tempObject > this.roadMap[this.movePhase].y)
                            {
                                this.speedK = this.tempObject - this.roadMap[this.movePhase].y;
                                this.moveHandler();
                            }
                        }
                        else
                        {
                            this.kill();
                        }
                    }
                    else if (this.speedK != this.speedKSave)
                    {
                        this.speedK = this.speedKSave;
                    }
                }
            }
            else if (this.this_pt.y == this.roadMap[this.movePhase].y)
            {
                if (this.this_pt.x >= this.roadMap[this.movePhase].x)
                {
                    this.x = this.x - this.speedK;
                    if (this.x <= this.roadMap[this.movePhase].x)
                    {
                        this.tempObject = this.x;
                        this.x = this.roadMap[this.movePhase].x;
                        this.bifurcation();
                        var _loc_1:* = this;
                        var _loc_2:* = this.movePhase + 1;
                        _loc_1.movePhase = _loc_2;
                        if (this.movePhase < this.roadMap.length)
                        {
                            if (this.tempObject < this.roadMap[this.movePhase].x)
                            {
                                this.speedK = this.roadMap[this.movePhase].x - this.tempObject;
                                this.moveHandler();
                            }
                        }
                        else
                        {
                            this.kill();
                        }
                    }
                    else if (this.speedK != this.speedKSave)
                    {
                        this.speedK = this.speedKSave;
                    }
                }
                else
                {
                    this.x = this.x + this.speedK;
                    if (this.x >= this.roadMap[this.movePhase].x)
                    {
                        this.tempObject = this.x;
                        this.x = this.roadMap[this.movePhase].x;
                        this.bifurcation();
                        var _loc_1:* = this;
                        var _loc_2:* = this.movePhase + 1;
                        _loc_1.movePhase = _loc_2;
                        if (this.movePhase < this.roadMap.length)
                        {
                            if (this.tempObject > this.roadMap[this.movePhase].x)
                            {
                                this.speedK = this.roadMap[this.movePhase].x - this.tempObject;
                                this.moveHandler();
                            }
                        }
                        else
                        {
                            this.kill();
                        }
                    }
                    else if (this.speedK != this.speedKSave)
                    {
                        this.speedK = this.speedKSave;
                    }
                }
            }
            this.directionManage();
            this.this_pt = new Point(this.x, this.y);
            if (this.movePhase < this.roadMap.length)
            {
                if (this.roadMap[this.movePhase].x == this.roadMap[(this.movePhase - 1)].x)
                {
                    if (this.roadMap[this.movePhase].y > this.roadMap[(this.movePhase - 1)].y)
                    {
                        this.tempObject = this.roadMap[(this.movePhase - 1)].y + (this.roadMap[this.movePhase].y - this.roadMap[(this.movePhase - 1)].y) * 0.75;
                        if (this.this_pt.y > this.tempObject)
                        {
                            this.scanNextTurn();
                        }
                    }
                    else if (this.roadMap[this.movePhase].y < this.roadMap[(this.movePhase - 1)].y)
                    {
                        this.tempObject = this.roadMap[this.movePhase].y + (this.roadMap[(this.movePhase - 1)].y - this.roadMap[this.movePhase].y) * 0.75;
                        if (this.this_pt.y < this.tempObject)
                        {
                            this.scanNextTurn();
                        }
                    }
                }
            }
            return;
        }// end function

        public function directionManage() : void
        {
            if (this.x > this.this_pt.x)
            {
                if (this.direction != "right")
                {
                    this.direction = "right";
                    if (this.container.scaleX < 0)
                    {
                        this.container.scaleX = this.container.scaleX * -1;
                    }
                    if (this.container.currentFrame > 50)
                    {
                        this.container.gotoAndStop(this.container.currentFrame - 50);
                    }
                }
            }
            else if (this.x < this.this_pt.x)
            {
                if (this.direction != "left")
                {
                    this.direction = "left";
                    if (this.container.scaleX > 0)
                    {
                        this.container.scaleX = this.container.scaleX * -1;
                    }
                    if (this.container.currentFrame > 50)
                    {
                        if (this.container.currentFrame < 101)
                        {
                            this.container.gotoAndStop(this.container.currentFrame - 50);
                        }
                        else if (this.container.currentFrame > 100)
                        {
                            this.container.gotoAndStop(this.container.currentFrame - 100);
                        }
                    }
                }
            }
            if (this.y > this.this_pt.y)
            {
                if (this.direction != "down")
                {
                    this.direction = "down";
                    if (this.container.currentFrame < 51)
                    {
                        this.container.gotoAndStop(this.container.currentFrame + 50);
                    }
                    else if (this.container.currentFrame > 100)
                    {
                        this.container.gotoAndStop(this.container.currentFrame - 50);
                    }
                }
            }
            else if (this.y < this.this_pt.y)
            {
                if (this.direction != "up")
                {
                    this.direction = "up";
                    if (this.container.currentFrame < 51)
                    {
                        this.container.gotoAndStop(this.container.currentFrame + 100);
                    }
                    else if (this.container.currentFrame < 101)
                    {
                        this.container.gotoAndStop(this.container.currentFrame + 50);
                    }
                    if (this.container.scaleX < 0)
                    {
                        if (this.container.x != 4)
                        {
                            this.container.x = 4;
                        }
                    }
                }
            }
            return;
        }// end function

        public function scanNextTurn() : void
        {
            if (this.movePhase < (this.roadMap.length - 1))
            {
                if (this.movePhase < this.roadMap.length)
                {
                    if (this.roadMap[this.movePhase].x > this.roadMap[(this.movePhase + 1)].x)
                    {
                        if (this.container.scaleX > 0)
                        {
                            this.container.scaleX = this.container.scaleX * -1;
                            if (this.container.x != 4)
                            {
                                this.container.x = 4;
                            }
                        }
                    }
                    else if (this.roadMap[this.movePhase].x < this.roadMap[(this.movePhase + 1)].x)
                    {
                        if (this.container.scaleX < 0)
                        {
                            this.container.scaleX = this.container.scaleX * -1;
                            if (this.container.x != 0)
                            {
                                this.container.x = 0;
                            }
                        }
                    }
                    else if (this.movePhase < this.roadMap.length - 2)
                    {
                        if (this.roadMap[this.movePhase].x > this.roadMap[this.movePhase + 2].x)
                        {
                            if (this.container.scaleX > 0)
                            {
                                this.container.scaleX = this.container.scaleX * -1;
                                if (this.container.x != 4)
                                {
                                    this.container.x = 4;
                                }
                            }
                        }
                        else if (this.roadMap[this.movePhase].x < this.roadMap[this.movePhase + 2].x)
                        {
                            if (this.container.scaleX < 0)
                            {
                                this.container.scaleX = this.container.scaleX * -1;
                                if (this.container.x != 0)
                                {
                                    this.container.x = 0;
                                }
                            }
                        }
                    }
                }
            }
            return;
        }// end function

        public function attack() : void
        {
            this.i = this.world.listOfUnits.length - 1;
            while (this.i >= 0)
            {
                
                if (this.world.listOfUnits[this.i].readyDamage && this.world.listOfUnits[this.i].atStage && !this.world.listOfUnits[this.i].icemanFlag && !this.world.listOfUnits[this.i].teleportFlag && (this.world.listOfUnits[this.i].icemanResist > 0 || this.world.listOfUnits[this.i].typeUnit == 24))
                {
                    if (Point.distance(this.world.listOfUnits[this.i].shoot_pt, this.this_pt) < this.radius)
                    {
                        this.world.listOfUnits[this.i].icemanFlag = true;
                        if (this.world.listOfUnits[this.i].typeUnit != 24)
                        {
                            this.world.listOfUnits[this.i].icemanCounter = Math.round(Main.mainClass.readXMLClass.castIcemanFreezTimerXML * this.world.listOfUnits[this.i].icemanResist);
                        }
                        else
                        {
                            this.world.listOfUnits[this.i].icemanCounter = Main.mainClass.readXMLClass.castIcemanFreezTimerXML;
                        }
                        Sounds.instance.playSoundWithVol("snd_iceman_freezes", 0.5);
                        (this.world.icemanSlowdownEnemiesCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_icemanSlowdownEnemiesCounter + 1);
                        if (this.world.icemanSlowdownEnemiesCounter == 75)
                        {
                            this.world.achieveManage("icemanSlowdown_75_enemies");
                        }
                        if (this.world.saveBox.gameSave.data.addit_icemanSlowdownEnemiesCounter == 500)
                        {
                            this.world.achieveManage("icemanSlowdown_500_enemies");
                        }
                    }
                }
                var _loc_1:* = this;
                var _loc_2:* = this.i - 1;
                _loc_1.i = _loc_2;
            }
            return;
        }// end function

        public function bifurcation() : void
        {
            if (this.movePhase < (this.roadMap.length - 1))
            {
                this.tempObject1 = null;
                this.i = 1;
                while (this.i <= Main.mainClass.readXMLClass.strategies)
                {
                    
                    if (this.i != this.road)
                    {
                        if (this.i == 1)
                        {
                            this.j = this.world.map.road1.length - 2;
                            while (this.j >= 0)
                            {
                                
                                if (this.world.map.road1[this.j].x == this.roadMap[this.movePhase].x && this.world.map.road1[this.j].y == this.roadMap[this.movePhase].y && (this.world.map.road1[(this.j + 1)].x != this.roadMap[(this.movePhase + 1)].x || this.world.map.road1[(this.j + 1)].y != this.roadMap[(this.movePhase + 1)].y))
                                {
                                    this.tempObject1 = new Iceman(this.roadMap[this.movePhase], this.i, (this.j + 1), false);
                                    this.brother = this.tempObject1;
                                    this.tempObject1.brother = this;
                                    this.world.addChild(this.tempObject1);
                                    this.tempObject1.container.scaleX = this.container.scaleX;
                                    this.tempObject1.container.x = this.container.x;
                                    this.tempObject1.container.gotoAndStop(this.container.currentFrame);
                                    this.tempObject1.liveCounter = this.liveCounter;
                                    this.tempObject1.voiceCounter = 0;
                                    this.world.worldInterface.barInfoView();
                                    break;
                                }
                                var _loc_1:* = this;
                                var _loc_2:* = this.j - 1;
                                _loc_1.j = _loc_2;
                            }
                        }
                        else if (this.i == 2)
                        {
                            this.j = this.world.map.road2.length - 2;
                            while (this.j >= 0)
                            {
                                
                                if (this.world.map.road2[this.j].x == this.roadMap[this.movePhase].x && this.world.map.road2[this.j].y == this.roadMap[this.movePhase].y && (this.world.map.road2[(this.j + 1)].x != this.roadMap[(this.movePhase + 1)].x || this.world.map.road2[(this.j + 1)].y != this.roadMap[(this.movePhase + 1)].y))
                                {
                                    this.tempObject1 = new Iceman(this.roadMap[this.movePhase], this.i, (this.j + 1), false);
                                    this.brother = this.tempObject1;
                                    this.tempObject1.brother = this;
                                    this.world.addChild(this.tempObject1);
                                    this.tempObject1.container.scaleX = this.container.scaleX;
                                    this.tempObject1.container.x = this.container.x;
                                    this.tempObject1.container.gotoAndStop(this.container.currentFrame);
                                    this.tempObject1.liveCounter = this.liveCounter;
                                    this.tempObject1.voiceCounter = 0;
                                    this.world.worldInterface.barInfoView();
                                    break;
                                }
                                var _loc_1:* = this;
                                var _loc_2:* = this.j - 1;
                                _loc_1.j = _loc_2;
                            }
                        }
                        if (this.tempObject1)
                        {
                            break;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            return;
        }// end function

        public function soundTimerManageMove(param1:Boolean) : void
        {
            if (param1)
            {
                if (!this.soundTimerMove && Sounds.instance.soundOn && !this.world.menuObject)
                {
                    this.soundTimerMove = new Timer(Sounds.instance.playSoundWithVol("snd_iceman_move", 0.28), 99999);
                    this.soundChannelMove = Sounds.instance.soundChanel;
                    this.soundTimerMove.addEventListener(TimerEvent.TIMER, this.soundTimerMoveFunk);
                    this.soundTimerMove.start();
                }
            }
            else if (this.soundTimerMove)
            {
                this.world.listOfSoundChannels.push(this.soundChannelMove);
                this.soundTimerMove.removeEventListener(TimerEvent.TIMER, this.soundTimerMoveFunk);
                this.soundTimerMove.stop();
                this.soundTimerMove = null;
            }
            return;
        }// end function

        public function soundTimerMoveFunk(event:TimerEvent) : void
        {
            if (this.dead && Main.mainClass.worldClass)
            {
                if (!Main.mainClass.worldClass.menuObject)
                {
                    Sounds.instance.playSoundWithVol("snd_iceman_move", 0.28);
                    this.soundChannelMove = Sounds.instance.soundChanel;
                }
                else
                {
                    this.soundTimerManageMove(false);
                }
            }
            else
            {
                this.soundTimerManageMove(false);
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.soundTimerManageMove(false);
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
                if (this.world.selectObject == this)
                {
                    this.world.worldInterface.barInfoManage();
                }
            }
            return;
        }// end function

    }
}
