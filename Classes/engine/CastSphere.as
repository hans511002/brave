package engine
{
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class CastSphere extends Sprite
    {
        public var i:int;
        public var j:int;
        public var n:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var container:MovieClip;
        public var sphereType:String;
        public var fireCount:int = 0;
        public var iceCount:int = 0;
        public var stoneCount:int = 0;
        public var levinCount:int = 0;
        public var getAllCount:int = 0;
        public var this_pt:Point;
        public var world:World;
        public var radius:Number;
        public var additAnamation:MovieClip;
        public var getAllForm:Array;
        public var dead:Boolean;
        public var liveCounter:int;
        public var leftSmoke_pt:Point;
        public var rightSmoke_pt:Point;
        public var upSmoke_pt:Point;
        public var downSmoke_pt:Point;

        public function CastSphere()
        {
            this.getAllForm = [false, false, false, false];
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.world = Main.mainClass.worldClass;
            this.radius = this.world.getSphere.myRadius;
            this.x = Main.mainClass.mouseX;
            this.y = Main.mainClass.mouseY;
            if (this.world.getSphere.type == "holder")
            {
                if (this.world.getSphere.fireCount > 0 && this.world.getSphere.iceCount == 0 && this.world.getSphere.stoneCount == 0 && this.world.getSphere.levinCount == 0)
                {
                    this.sphereType = "fire";
                    this.fireCount = this.world.getSphere.fireCount;
                    Sounds.instance.playSoundWithVol("snd_cast_fire", 0.7);
                    (this.world.castFireCounter + 1);
                    (this.world.saveBox.gameSave.data.addit_castFireCounter + 1);
                }
                else if (this.world.getSphere.fireCount == 0 && this.world.getSphere.iceCount > 0 && this.world.getSphere.stoneCount == 0 && this.world.getSphere.levinCount == 0)
                {
                    this.sphereType = "ice";
                    this.iceCount = this.world.getSphere.iceCount;
                    Sounds.instance.playSoundWithVol("snd_cast_ice", 0.7);
                    (this.world.castIceCounter + 1);
                    (this.world.saveBox.gameSave.data.addit_castIceCounter + 1);
                }
                else if (this.world.getSphere.fireCount == 0 && this.world.getSphere.iceCount == 0 && this.world.getSphere.stoneCount > 0 && this.world.getSphere.levinCount == 0)
                {
                    this.sphereType = "stone";
                    this.stoneCount = this.world.getSphere.stoneCount;
                    Sounds.instance.playSound("snd_cast_stone");
                    (this.world.castStoneCounter + 1);
                    (this.world.saveBox.gameSave.data.addit_castStoneCounter + 1);
                }
                else if (this.world.getSphere.fireCount == 0 && this.world.getSphere.iceCount == 0 && this.world.getSphere.stoneCount == 0 && this.world.getSphere.levinCount > 0)
                {
                    this.sphereType = "levin";
                    this.levinCount = this.world.getSphere.levinCount;
                    Sounds.instance.playSoundWithVol("snd_cast_levin", 0.8);
                    (this.world.castLevinCounter + 1);
                    (this.world.saveBox.gameSave.data.addit_castLevinCounter + 1);
                }
                else
                {
                    this.fireCount = this.world.getSphere.fireCount;
                    this.iceCount = this.world.getSphere.iceCount;
                    this.stoneCount = this.world.getSphere.stoneCount;
                    this.levinCount = this.world.getSphere.levinCount;
                    if (this.fireCount > 0 && this.iceCount > 0 && this.stoneCount == 0 && this.levinCount == 0)
                    {
                        this.sphereType = "fireIce";
                        Sounds.instance.playSoundWithVol("snd_cast_fireIce", 0.9);
                        (this.world.castFireCounter + 1);
                        (this.world.castIceCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castFireCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castIceCounter + 1);
                    }
                    else if (this.fireCount > 0 && this.iceCount == 0 && this.stoneCount > 0 && this.levinCount == 0)
                    {
                        this.sphereType = "fireStone";
                        Sounds.instance.playSound("snd_cast_fireStone");
                        (this.world.castFireCounter + 1);
                        (this.world.castStoneCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castFireCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castStoneCounter + 1);
                    }
                    else if (this.fireCount > 0 && this.iceCount == 0 && this.stoneCount == 0 && this.levinCount > 0)
                    {
                        this.sphereType = "fireLevin";
                        Sounds.instance.playSoundWithVol("snd_cast_fireLevin", 0.7);
                        (this.world.castFireCounter + 1);
                        (this.world.castLevinCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castFireCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castLevinCounter + 1);
                    }
                    else if (this.fireCount == 0 && this.iceCount > 0 && this.stoneCount > 0 && this.levinCount == 0)
                    {
                        this.sphereType = "iceStone";
                        Sounds.instance.playSound("snd_cast_iceStone");
                        (this.world.castIceCounter + 1);
                        (this.world.castStoneCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castIceCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castStoneCounter + 1);
                    }
                    else if (this.fireCount == 0 && this.iceCount > 0 && this.stoneCount == 0 && this.levinCount > 0)
                    {
                        this.sphereType = "iceLevin";
                        Sounds.instance.playSoundWithVol("snd_cast_iceLevin", 0.9);
                        (this.world.castIceCounter + 1);
                        (this.world.castLevinCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castIceCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castLevinCounter + 1);
                    }
                    else if (this.fireCount == 0 && this.iceCount == 0 && this.stoneCount > 0 && this.levinCount > 0)
                    {
                        this.sphereType = "stoneLevin";
                        Sounds.instance.playSoundWithVol("snd_cast_stoneLevin", 0.9);
                        (this.world.castStoneCounter + 1);
                        (this.world.castLevinCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castStoneCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castLevinCounter + 1);
                    }
                    else
                    {
                        this.sphereType = "getAllLittle";
                        Sounds.instance.playSoundWithVol("snd_cast_getAllLittle", 0.9);
                        (this.world.castGetAllCounter + 1);
                        (this.world.saveBox.gameSave.data.addit_castGetAllCounter + 1);
                    }
                }
            }
            else if (this.world.getSphere.type == "getAll")
            {
                this.sphereType = "getAll";
                this.getAllCount = this.world.getSphere.getAllCount;
                Sounds.instance.playSoundWithVol("snd_cast_getAll", 0.95);
            }
            if (this.world.saveBox.gameSave.data.addit_castFireCounter == 150)
            {
                this.world.achieveManage("castFire_150_times");
            }
            if (this.world.saveBox.gameSave.data.addit_castIceCounter == 150)
            {
                this.world.achieveManage("castIce_150_times");
            }
            if (this.world.saveBox.gameSave.data.addit_castStoneCounter == 150)
            {
                this.world.achieveManage("castStone_150_times");
            }
            if (this.world.saveBox.gameSave.data.addit_castLevinCounter == 150)
            {
                this.world.achieveManage("castLevin_150_times");
            }
            if (this.world.castGetAllCounter == 10)
            {
                this.world.achieveManage("castGetAll_10_times");
            }
            if (this.world.saveBox.gameSave.data.addit_castGetAllCounter == 100)
            {
                this.world.achieveManage("castGetAll_100_times");
            }
            this.this_pt = new Point(this.x, this.y);
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            if (this.sphereType == "fire")
            {
                this.container = new CastFire_mc();
            }
            else if (this.sphereType == "ice")
            {
                this.container = new CastIce_mc();
            }
            else if (this.sphereType == "stone")
            {
                this.container = new CastStone_mc();
                this.container.visible = false;
                this.container.myCounter = 3;
            }
            else if (this.sphereType == "levin")
            {
                this.container = new CastLevin_mc();
            }
            else if (this.sphereType == "fireIce")
            {
                this.container = new CastFireIce_mc();
            }
            else if (this.sphereType == "fireStone")
            {
                this.container = new CastFireStone_mc();
            }
            else if (this.sphereType == "fireLevin")
            {
                this.container = new CastFireLevin_mc();
            }
            else if (this.sphereType == "iceStone")
            {
                this.container = new CastIceStone_mc();
            }
            else if (this.sphereType == "iceLevin")
            {
                this.container = new CastIceLevin_mc();
            }
            else if (this.sphereType == "stoneLevin")
            {
                this.container = new CastStoneLevin_mc();
            }
            else if (this.sphereType == "getAllLittle")
            {
                this.container = new CastGetAllLittle_mc();
                var _loc_2:* = 0.8;
                this.container.scaleY = 0.8;
                this.container.scaleX = _loc_2;
            }
            else if (this.sphereType == "getAll")
            {
                this.liveCounter = Main.mainClass.readXMLClass.getAllLiveTimer;
                if (this.getAllCount < 3)
                {
                    this.container = new CastGetAllLittle_mc();
                }
                else
                {
                    this.container = new CastGetAll_mc();
                    if (this.getAllCount == 3)
                    {
                        this.additAnamation = new CastGetAllSwamp_mc();
                        this.additAnamation.stop();
                        this.additAnamation.x = this.x;
                        this.additAnamation.y = this.y;
                        var _loc_2:* = false;
                        this.additAnamation.mouseChildren = false;
                        this.additAnamation.mouseEnabled = _loc_2;
                        this.world.addChildAt(this.additAnamation, 2);
                        this.world.listOfIndexes0.push(this.additAnamation);
                        this.tempObject = 1000;
                        if (this.world.map.road1)
                        {
                            this.i = 0;
                            while (this.i < this.world.map.allPointsRoad1.length)
                            {
                                
                                this.tempObject1 = Point.distance(this.this_pt, this.world.map.allPointsRoad1[this.i]);
                                if (this.tempObject1 < this.tempObject)
                                {
                                    this.tempObject = this.tempObject1;
                                    this.x = this.world.map.allPointsRoad1[this.i].x;
                                    this.y = this.world.map.allPointsRoad1[this.i].y;
                                }
                                var _loc_2:* = this;
                                var _loc_3:* = this.i + 1;
                                _loc_2.i = _loc_3;
                            }
                        }
                        if (this.world.map.road2)
                        {
                            this.i = 0;
                            while (this.i < this.world.map.allPointsRoad2.length)
                            {
                                
                                this.tempObject1 = Point.distance(this.this_pt, this.world.map.allPointsRoad2[this.i]);
                                if (this.tempObject1 < this.tempObject)
                                {
                                    this.tempObject = this.tempObject1;
                                    this.x = this.world.map.allPointsRoad2[this.i].x;
                                    this.y = this.world.map.allPointsRoad2[this.i].y;
                                }
                                var _loc_2:* = this;
                                var _loc_3:* = this.i + 1;
                                _loc_2.i = _loc_3;
                            }
                        }
                        if (this.world.map.road3)
                        {
                            this.i = 0;
                            while (this.i < this.world.map.allPointsRoad3.length)
                            {
                                
                                this.tempObject1 = Point.distance(this.this_pt, this.world.map.allPointsRoad3[this.i]);
                                if (this.tempObject1 < this.tempObject)
                                {
                                    this.tempObject = this.tempObject1;
                                    this.x = this.world.map.allPointsRoad3[this.i].x;
                                    this.y = this.world.map.allPointsRoad3[this.i].y;
                                }
                                var _loc_2:* = this;
                                var _loc_3:* = this.i + 1;
                                _loc_2.i = _loc_3;
                            }
                        }
                        this.this_pt = new Point(this.x, this.y);
                        this.i = 0;
                        while (this.i < this.world.map.allPointsRoad1.length)
                        {
                            
                            if (!this.getAllForm[0])
                            {
                                if (this.this_pt.x - this.world.map.allPointsRoad1[this.i].x >= 22 && this.this_pt.x - this.world.map.allPointsRoad1[this.i].x <= 45 && (this.this_pt.y >= this.world.map.allPointsRoad1[this.i].y - 22 && this.this_pt.y <= this.world.map.allPointsRoad1[this.i].y + 22))
                                {
                                    this.getAllForm[0] = true;
                                    ;
                                }
                            }
                            if (!this.getAllForm[1])
                            {
                                if (this.world.map.allPointsRoad1[this.i].x - this.this_pt.x >= 22 && this.world.map.allPointsRoad1[this.i].x - this.this_pt.x <= 45 && (this.this_pt.y >= this.world.map.allPointsRoad1[this.i].y - 22 && this.this_pt.y <= this.world.map.allPointsRoad1[this.i].y + 22))
                                {
                                    this.getAllForm[1] = true;
                                    ;
                                }
                            }
                            if (!this.getAllForm[3])
                            {
                                if (this.world.map.allPointsRoad1[this.i].y - this.this_pt.y >= 22 && this.world.map.allPointsRoad1[this.i].y - this.this_pt.y <= 45 && (this.this_pt.x >= this.world.map.allPointsRoad1[this.i].x - 22 && this.this_pt.x <= this.world.map.allPointsRoad1[this.i].x + 22))
                                {
                                    this.getAllForm[3] = true;
                                    ;
                                }
                            }
                            if (!this.getAllForm[2])
                            {
                                if (this.this_pt.y - this.world.map.allPointsRoad1[this.i].y >= 22 && this.this_pt.y - this.world.map.allPointsRoad1[this.i].y <= 45 && (this.this_pt.x >= this.world.map.allPointsRoad1[this.i].x - 22 && this.this_pt.x <= this.world.map.allPointsRoad1[this.i].x + 22))
                                {
                                    this.getAllForm[2] = true;
                                    ;
                                }
                            }
                            var _loc_2:* = this;
                            var _loc_3:* = this.i + 1;
                            _loc_2.i = _loc_3;
                        }
                        this.i = 0;
                        while (this.i < this.world.map.allPointsRoad2.length)
                        {
                            
                            if (!this.getAllForm[0])
                            {
                                if (this.this_pt.x - this.world.map.allPointsRoad2[this.i].x >= 22 && this.this_pt.x - this.world.map.allPointsRoad2[this.i].x <= 45 && (this.this_pt.y >= this.world.map.allPointsRoad2[this.i].y - 22 && this.this_pt.y <= this.world.map.allPointsRoad2[this.i].y + 22))
                                {
                                    this.getAllForm[0] = true;
                                    ;
                                }
                            }
                            if (!this.getAllForm[1])
                            {
                                if (this.world.map.allPointsRoad2[this.i].x - this.this_pt.x >= 22 && this.world.map.allPointsRoad2[this.i].x - this.this_pt.x <= 45 && (this.this_pt.y >= this.world.map.allPointsRoad2[this.i].y - 22 && this.this_pt.y <= this.world.map.allPointsRoad2[this.i].y + 22))
                                {
                                    this.getAllForm[1] = true;
                                    ;
                                }
                            }
                            if (!this.getAllForm[3])
                            {
                                if (this.world.map.allPointsRoad2[this.i].y - this.this_pt.y >= 22 && this.world.map.allPointsRoad2[this.i].y - this.this_pt.y <= 45 && (this.this_pt.x >= this.world.map.allPointsRoad2[this.i].x - 22 && this.this_pt.x <= this.world.map.allPointsRoad2[this.i].x + 22))
                                {
                                    this.getAllForm[3] = true;
                                    ;
                                }
                            }
                            if (!this.getAllForm[2])
                            {
                                if (this.this_pt.y - this.world.map.allPointsRoad2[this.i].y >= 22 && this.this_pt.y - this.world.map.allPointsRoad2[this.i].y <= 45 && (this.this_pt.x >= this.world.map.allPointsRoad2[this.i].x - 22 && this.this_pt.x <= this.world.map.allPointsRoad2[this.i].x + 22))
                                {
                                    this.getAllForm[2] = true;
                                    ;
                                }
                            }
                            var _loc_2:* = this;
                            var _loc_3:* = this.i + 1;
                            _loc_2.i = _loc_3;
                        }
                        this.i = 0;
                        while (this.i < this.world.map.allPointsRoad3.length)
                        {
                            
                            if (!this.getAllForm[0])
                            {
                                if (this.this_pt.x - this.world.map.allPointsRoad3[this.i].x >= 22 && this.this_pt.x - this.world.map.allPointsRoad3[this.i].x <= 45 && (this.this_pt.y >= this.world.map.allPointsRoad3[this.i].y - 22 && this.this_pt.y <= this.world.map.allPointsRoad3[this.i].y + 22))
                                {
                                    this.getAllForm[0] = true;
                                    ;
                                }
                            }
                            if (!this.getAllForm[1])
                            {
                                if (this.world.map.allPointsRoad3[this.i].x - this.this_pt.x >= 22 && this.world.map.allPointsRoad3[this.i].x - this.this_pt.x <= 45 && (this.this_pt.y >= this.world.map.allPointsRoad3[this.i].y - 22 && this.this_pt.y <= this.world.map.allPointsRoad3[this.i].y + 22))
                                {
                                    this.getAllForm[1] = true;
                                    ;
                                }
                            }
                            if (!this.getAllForm[3])
                            {
                                if (this.world.map.allPointsRoad3[this.i].y - this.this_pt.y >= 22 && this.world.map.allPointsRoad3[this.i].y - this.this_pt.y <= 45 && (this.this_pt.x >= this.world.map.allPointsRoad3[this.i].x - 22 && this.this_pt.x <= this.world.map.allPointsRoad3[this.i].x + 22))
                                {
                                    this.getAllForm[3] = true;
                                    ;
                                }
                            }
                            if (!this.getAllForm[2])
                            {
                                if (this.this_pt.y - this.world.map.allPointsRoad3[this.i].y >= 22 && this.this_pt.y - this.world.map.allPointsRoad3[this.i].y <= 45 && (this.this_pt.x >= this.world.map.allPointsRoad3[this.i].x - 22 && this.this_pt.x <= this.world.map.allPointsRoad3[this.i].x + 22))
                                {
                                    this.getAllForm[2] = true;
                                    ;
                                }
                            }
                            var _loc_2:* = this;
                            var _loc_3:* = this.i + 1;
                            _loc_2.i = _loc_3;
                        }
                    }
                }
            }
            this.container.stop();
            this.addChild(this.container);
            this.world.listOfClasses.push(this);
            this.world.listOfIndexes2.push(this);
            this.world.forseIndexFl = true;
            return;
        }// end function

        public function update() : void
        {
            if (this.container is CastGetAll_mc && this.additAnamation)
            {
                if (this.liveCounter > 0)
                {
                    (this.liveCounter - 1);
                }
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                if (this.container.currentFrame > 3 && this.container.currentFrame < 6)
                {
                    this.container.haze1.myFrame = this.container.haze1.currentFrame;
                    this.container.haze2.myFrame = this.container.haze2.currentFrame;
                    this.container.haze3.myFrame = this.container.haze3.currentFrame;
                    this.container.haze4.myFrame = this.container.haze4.currentFrame;
                    this.container.haze5.myFrame = this.container.haze5.currentFrame;
                    this.container.haze6.myFrame = this.container.haze6.currentFrame;
                    this.container.haze7.myFrame = this.container.haze7.currentFrame;
                    this.container.haze8.myFrame = this.container.haze8.currentFrame;
                    this.container.haze9.myFrame = this.container.haze9.currentFrame;
                }
                if (this.container.currentFrame == 4 || this.container.currentFrame == 5 || this.container.currentFrame == 6)
                {
                    if (this.container.currentFrame == 4)
                    {
                        if (!this.getAllForm[0])
                        {
                            this.container.haze5.visible = false;
                            this.container.haze1.visible = false;
                            this.container.haze3.visible = false;
                        }
                        if (!this.getAllForm[1])
                        {
                            this.container.haze7.visible = false;
                            this.container.haze2.visible = false;
                            this.container.haze4.visible = false;
                        }
                        if (!this.getAllForm[2])
                        {
                            this.container.haze6.visible = false;
                            this.container.haze1.visible = false;
                            this.container.haze2.visible = false;
                        }
                        if (!this.getAllForm[3])
                        {
                            this.container.haze8.visible = false;
                            this.container.haze3.visible = false;
                            this.container.haze4.visible = false;
                        }
                        this.container.haze1.myPoint = this.container.localToGlobal(new Point(this.container.haze1.x, this.container.haze1.y));
                        this.container.haze2.myPoint = this.container.localToGlobal(new Point(this.container.haze2.x, this.container.haze2.y));
                        this.container.haze3.myPoint = this.container.localToGlobal(new Point(this.container.haze3.x, this.container.haze3.y));
                        this.container.haze4.myPoint = this.container.localToGlobal(new Point(this.container.haze4.x, this.container.haze4.y));
                        this.container.haze5.myPoint = this.container.localToGlobal(new Point(this.container.haze5.x, this.container.haze5.y));
                        this.container.haze6.myPoint = this.container.localToGlobal(new Point(this.container.haze6.x, this.container.haze6.y));
                        this.container.haze7.myPoint = this.container.localToGlobal(new Point(this.container.haze7.x, this.container.haze7.y));
                        this.container.haze8.myPoint = this.container.localToGlobal(new Point(this.container.haze8.x, this.container.haze8.y));
                        this.container.haze9.myPoint = this.container.localToGlobal(new Point(this.container.haze9.x, this.container.haze9.y));
                        this.leftSmoke_pt = this.container.localToGlobal(new Point(this.container.haze5.x, this.container.haze5.y));
                        this.rightSmoke_pt = this.container.localToGlobal(new Point(this.container.haze7.x, this.container.haze7.y));
                        this.upSmoke_pt = this.container.localToGlobal(new Point(this.container.haze6.x, this.container.haze6.y));
                        this.downSmoke_pt = this.container.localToGlobal(new Point(this.container.haze8.x, this.container.haze8.y));
                    }
                    if (this.container.haze1.myFrame < 60)
                    {
                        this.container.haze1.gotoAndStop((this.container.haze1.myFrame + 1));
                    }
                    else
                    {
                        this.container.haze1.gotoAndStop(1);
                    }
                    if (this.container.haze2.myFrame < 60)
                    {
                        this.container.haze2.gotoAndStop((this.container.haze2.myFrame + 1));
                    }
                    else
                    {
                        this.container.haze2.gotoAndStop(1);
                    }
                    if (this.container.haze3.myFrame < 60)
                    {
                        this.container.haze3.gotoAndStop((this.container.haze3.myFrame + 1));
                    }
                    else
                    {
                        this.container.haze3.gotoAndStop(1);
                    }
                    if (this.container.haze4.myFrame < 60)
                    {
                        this.container.haze4.gotoAndStop((this.container.haze4.myFrame + 1));
                    }
                    else
                    {
                        this.container.haze4.gotoAndStop(1);
                    }
                    if (this.container.haze5.myFrame < 60)
                    {
                        this.container.haze5.gotoAndStop((this.container.haze5.myFrame + 1));
                    }
                    else
                    {
                        this.container.haze5.gotoAndStop(1);
                    }
                    if (this.container.haze6.myFrame < 60)
                    {
                        this.container.haze6.gotoAndStop((this.container.haze6.myFrame + 1));
                    }
                    else
                    {
                        this.container.haze6.gotoAndStop(1);
                    }
                    if (this.container.haze7.myFrame < 60)
                    {
                        this.container.haze7.gotoAndStop((this.container.haze7.myFrame + 1));
                    }
                    else
                    {
                        this.container.haze7.gotoAndStop(1);
                    }
                    if (this.container.haze8.myFrame < 60)
                    {
                        this.container.haze8.gotoAndStop((this.container.haze8.myFrame + 1));
                    }
                    else
                    {
                        this.container.haze8.gotoAndStop(1);
                    }
                    if (this.container.haze9.myFrame < 60)
                    {
                        this.container.haze9.gotoAndStop((this.container.haze9.myFrame + 1));
                    }
                    else
                    {
                        this.container.haze9.gotoAndStop(1);
                    }
                }
                else if (this.container.currentFrame > 3)
                {
                    if (this.liveCounter > 0)
                    {
                        if (this.container.haze1.currentFrame < 60)
                        {
                            this.container.haze1.gotoAndStop((this.container.haze1.currentFrame + 1));
                        }
                        else
                        {
                            this.container.haze1.gotoAndStop(1);
                        }
                        if (this.container.haze2.currentFrame < 60)
                        {
                            this.container.haze2.gotoAndStop((this.container.haze2.currentFrame + 1));
                        }
                        else
                        {
                            this.container.haze2.gotoAndStop(1);
                        }
                        if (this.container.haze3.currentFrame < 60)
                        {
                            this.container.haze3.gotoAndStop((this.container.haze3.currentFrame + 1));
                        }
                        else
                        {
                            this.container.haze3.gotoAndStop(1);
                        }
                        if (this.container.haze4.currentFrame < 60)
                        {
                            this.container.haze4.gotoAndStop((this.container.haze4.currentFrame + 1));
                        }
                        else
                        {
                            this.container.haze4.gotoAndStop(1);
                        }
                        if (this.container.haze5.currentFrame < 60)
                        {
                            this.container.haze5.gotoAndStop((this.container.haze5.currentFrame + 1));
                        }
                        else
                        {
                            this.container.haze5.gotoAndStop(1);
                        }
                        if (this.container.haze6.currentFrame < 60)
                        {
                            this.container.haze6.gotoAndStop((this.container.haze6.currentFrame + 1));
                        }
                        else
                        {
                            this.container.haze6.gotoAndStop(1);
                        }
                        if (this.container.haze7.currentFrame < 60)
                        {
                            this.container.haze7.gotoAndStop((this.container.haze7.currentFrame + 1));
                        }
                        else
                        {
                            this.container.haze7.gotoAndStop(1);
                        }
                        if (this.container.haze8.currentFrame < 60)
                        {
                            this.container.haze8.gotoAndStop((this.container.haze8.currentFrame + 1));
                        }
                        else
                        {
                            this.container.haze8.gotoAndStop(1);
                        }
                        if (this.container.haze9.currentFrame < 60)
                        {
                            this.container.haze9.gotoAndStop((this.container.haze9.currentFrame + 1));
                        }
                        else
                        {
                            this.container.haze9.gotoAndStop(1);
                        }
                    }
                    else
                    {
                        if (this.container.haze1.currentFrame < this.container.haze1.totalFrames)
                        {
                            this.container.haze1.gotoAndStop((this.container.haze1.currentFrame + 1));
                        }
                        if (this.container.haze2.currentFrame < this.container.haze2.totalFrames)
                        {
                            this.container.haze2.gotoAndStop((this.container.haze2.currentFrame + 1));
                        }
                        if (this.container.haze3.currentFrame < this.container.haze3.totalFrames)
                        {
                            this.container.haze3.gotoAndStop((this.container.haze3.currentFrame + 1));
                        }
                        if (this.container.haze4.currentFrame < this.container.haze4.totalFrames)
                        {
                            this.container.haze4.gotoAndStop((this.container.haze4.currentFrame + 1));
                        }
                        if (this.container.haze5.currentFrame < this.container.haze5.totalFrames)
                        {
                            this.container.haze5.gotoAndStop((this.container.haze5.currentFrame + 1));
                        }
                        if (this.container.haze6.currentFrame < this.container.haze6.totalFrames)
                        {
                            this.container.haze6.gotoAndStop((this.container.haze6.currentFrame + 1));
                        }
                        if (this.container.haze7.currentFrame < this.container.haze7.totalFrames)
                        {
                            this.container.haze7.gotoAndStop((this.container.haze7.currentFrame + 1));
                        }
                        if (this.container.haze8.currentFrame < this.container.haze8.totalFrames)
                        {
                            this.container.haze8.gotoAndStop((this.container.haze8.currentFrame + 1));
                        }
                        if (this.container.haze9.currentFrame < this.container.haze9.totalFrames)
                        {
                            this.container.haze9.gotoAndStop((this.container.haze9.currentFrame + 1));
                        }
                    }
                    this.i = this.world.listOfUnits.length - 1;
                    while (this.i >= 0)
                    {
                        
                        if (this.world.listOfUnits[this.i].atStage && this.world.listOfUnits[this.i].readyDamage)
                        {
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.container.haze9.visible)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.container.haze9.width)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.getAllDamagePerSec);
                                }
                            }
                            if (this.container.haze5.visible)
                            {
                                if (Point.distance(this.leftSmoke_pt, this.tempObject.shoot_pt) < this.container.haze5.width)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.getAllDamagePerSec);
                                }
                            }
                            if (this.container.haze7.visible)
                            {
                                if (Point.distance(this.rightSmoke_pt, this.tempObject.shoot_pt) < this.container.haze7.width)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.getAllDamagePerSec);
                                }
                            }
                            if (this.container.haze6.visible)
                            {
                                if (Point.distance(this.upSmoke_pt, this.tempObject.shoot_pt) < this.container.haze6.width)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.getAllDamagePerSec);
                                }
                            }
                            if (this.container.haze8.visible)
                            {
                                if (Point.distance(this.downSmoke_pt, this.tempObject.shoot_pt) < this.container.haze8.width)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.getAllDamagePerSec);
                                }
                            }
                            if (this.tempObject.dead)
                            {
                                (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                            }
                        }
                        var _loc_1:* = this;
                        var _loc_2:* = this.i - 1;
                        _loc_1.i = _loc_2;
                    }
                }
                if (this.additAnamation.currentFrame > 3 && this.additAnamation.currentFrame < 6)
                {
                    this.additAnamation.swamp1.myFrame = this.additAnamation.swamp1.currentFrame;
                    this.additAnamation.swamp2.myFrame = this.additAnamation.swamp2.currentFrame;
                    this.additAnamation.swamp3.myFrame = this.additAnamation.swamp3.currentFrame;
                    this.additAnamation.swamp4.myFrame = this.additAnamation.swamp4.currentFrame;
                    this.additAnamation.swamp5.myFrame = this.additAnamation.swamp5.currentFrame;
                }
                if (this.additAnamation.currentFrame < this.additAnamation.totalFrames)
                {
                    this.additAnamation.gotoAndStop((this.additAnamation.currentFrame + 1));
                }
                if (this.additAnamation.currentFrame == 4 || this.additAnamation.currentFrame == 5 || this.additAnamation.currentFrame == 6)
                {
                    if (this.additAnamation.currentFrame == 4)
                    {
                        if (!this.getAllForm[0])
                        {
                            this.additAnamation.swamp1.visible = false;
                        }
                        if (!this.getAllForm[1])
                        {
                            this.additAnamation.swamp3.visible = false;
                        }
                        if (!this.getAllForm[2])
                        {
                            this.additAnamation.swamp2.visible = false;
                        }
                        if (!this.getAllForm[3])
                        {
                            this.additAnamation.swamp4.visible = false;
                        }
                    }
                    if (this.additAnamation.swamp1.myFrame < 62)
                    {
                        this.additAnamation.swamp1.gotoAndStop((this.additAnamation.swamp1.currentFrame + 1));
                    }
                    else
                    {
                        this.additAnamation.swamp1.gotoAndStop(1);
                    }
                    if (this.additAnamation.swamp2.myFrame < 62)
                    {
                        this.additAnamation.swamp2.gotoAndStop((this.additAnamation.swamp2.currentFrame + 1));
                    }
                    else
                    {
                        this.additAnamation.swamp2.gotoAndStop(1);
                    }
                    if (this.additAnamation.swamp3.myFrame < 62)
                    {
                        this.additAnamation.swamp3.gotoAndStop((this.additAnamation.swamp3.currentFrame + 1));
                    }
                    else
                    {
                        this.additAnamation.swamp3.gotoAndStop(1);
                    }
                    if (this.additAnamation.swamp4.myFrame < 62)
                    {
                        this.additAnamation.swamp4.gotoAndStop((this.additAnamation.swamp4.currentFrame + 1));
                    }
                    else
                    {
                        this.additAnamation.swamp4.gotoAndStop(1);
                    }
                    if (this.additAnamation.swamp5.myFrame < 62)
                    {
                        this.additAnamation.swamp5.gotoAndStop((this.additAnamation.swamp5.currentFrame + 1));
                    }
                    else
                    {
                        this.additAnamation.swamp5.gotoAndStop(1);
                    }
                }
                else if (this.additAnamation.currentFrame > 3)
                {
                    if (this.liveCounter > 0)
                    {
                        if (this.additAnamation.swamp1.currentFrame < 62)
                        {
                            this.additAnamation.swamp1.gotoAndStop((this.additAnamation.swamp1.currentFrame + 1));
                        }
                        else
                        {
                            this.additAnamation.swamp1.gotoAndStop(1);
                        }
                        if (this.additAnamation.swamp2.currentFrame < 62)
                        {
                            this.additAnamation.swamp2.gotoAndStop((this.additAnamation.swamp2.currentFrame + 1));
                        }
                        else
                        {
                            this.additAnamation.swamp2.gotoAndStop(1);
                        }
                        if (this.additAnamation.swamp3.currentFrame < 62)
                        {
                            this.additAnamation.swamp3.gotoAndStop((this.additAnamation.swamp3.currentFrame + 1));
                        }
                        else
                        {
                            this.additAnamation.swamp3.gotoAndStop(1);
                        }
                        if (this.additAnamation.swamp4.currentFrame < 62)
                        {
                            this.additAnamation.swamp4.gotoAndStop((this.additAnamation.swamp4.currentFrame + 1));
                        }
                        else
                        {
                            this.additAnamation.swamp4.gotoAndStop(1);
                        }
                        if (this.additAnamation.swamp5.currentFrame < 62)
                        {
                            this.additAnamation.swamp5.gotoAndStop((this.additAnamation.swamp5.currentFrame + 1));
                        }
                        else
                        {
                            this.additAnamation.swamp5.gotoAndStop(1);
                        }
                    }
                    else
                    {
                        if (this.additAnamation.swamp1.currentFrame < this.additAnamation.swamp1.totalFrames)
                        {
                            this.additAnamation.swamp1.gotoAndStop((this.additAnamation.swamp1.currentFrame + 1));
                        }
                        if (this.additAnamation.swamp2.currentFrame < this.additAnamation.swamp2.totalFrames)
                        {
                            this.additAnamation.swamp2.gotoAndStop((this.additAnamation.swamp2.currentFrame + 1));
                        }
                        if (this.additAnamation.swamp3.currentFrame < this.additAnamation.swamp3.totalFrames)
                        {
                            this.additAnamation.swamp3.gotoAndStop((this.additAnamation.swamp3.currentFrame + 1));
                        }
                        if (this.additAnamation.swamp4.currentFrame < this.additAnamation.swamp4.totalFrames)
                        {
                            this.additAnamation.swamp4.gotoAndStop((this.additAnamation.swamp4.currentFrame + 1));
                        }
                        if (this.additAnamation.swamp5.currentFrame < this.additAnamation.swamp5.totalFrames)
                        {
                            this.additAnamation.swamp5.gotoAndStop((this.additAnamation.swamp5.currentFrame + 1));
                        }
                    }
                }
                if (this.container.currentFrame == 4)
                {
                    if (this.getAllCount > 0)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            if (this.world.listOfUnits[this.i].atStage && this.world.listOfUnits[this.i].readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.world.listOfUnits[this.i].shoot_pt) < this.radius)
                                {
                                    this.tempObject = this.world.listOfUnits[this.i];
                                    this.tempObject1 = Main.mainClass.readXMLClass.getAllMultiply2;
                                    this.tempObject.getHit(this.tempObject1, "getAll");
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                if (this.liveCounter == 0)
                {
                    if (this.container.haze1.currentFrame == this.container.haze1.totalFrames && this.additAnamation.swamp1.currentFrame == this.additAnamation.swamp1.totalFrames)
                    {
                        this.kill();
                        this.i = 0;
                        while (this.i < this.world.listOfIndexes0.length)
                        {
                            
                            if (this.world.listOfIndexes0[this.i] == this.additAnamation)
                            {
                                this.world.removeChild(this.additAnamation);
                                this.world.listOfIndexes0.splice(this.i, 1);
                                break;
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
            }
            else if (this.container.currentFrame < this.container.totalFrames)
            {
                if (this.sphereType == "fire")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 2)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveFireXML[this.fireCount], this.sphereType, this.fireCount, true);
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "ice")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 2)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveIceXML[this.iceCount], this.sphereType, this.iceCount, true);
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "stone")
                {
                    if (this.container.myCounter > 0)
                    {
                        (this.container.myCounter - 1);
                        if (this.container.myCounter == 0)
                        {
                            this.container.visible = true;
                        }
                    }
                    else
                    {
                        this.container.gotoAndStop((this.container.currentFrame + 1));
                        if (this.container.currentFrame == 2)
                        {
                            this.i = this.world.listOfUnits.length - 1;
                            while (this.i >= 0)
                            {
                                
                                this.tempObject = this.world.listOfUnits[this.i];
                                if (this.tempObject.atStage && this.tempObject.readyDamage)
                                {
                                    if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                    {
                                        this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveStoneXML[this.stoneCount], this.sphereType, this.stoneCount, true);
                                        if (this.tempObject.dead)
                                        {
                                            (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                        }
                                    }
                                }
                                var _loc_1:* = this;
                                var _loc_2:* = this.i - 1;
                                _loc_1.i = _loc_2;
                            }
                        }
                    }
                }
                else if (this.sphereType == "levin")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 2)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveLevinXML[this.levinCount], this.sphereType, this.levinCount, true);
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "fireIce")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 2)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveFireXML[this.fireCount], "fire", this.fireCount, true);
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveIceXML[this.iceCount], "ice", this.iceCount, true);
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "fireStone")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 2)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveFireXML[this.fireCount], "fire", this.fireCount, true);
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveStoneXML[this.stoneCount], "stone", this.stoneCount, true);
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "fireLevin")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 2)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveFireXML[this.fireCount], "fire", this.fireCount, true);
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveLevinXML[this.levinCount], "levin", this.levinCount, true);
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "iceStone")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 2)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveIceXML[this.iceCount], "ice", this.iceCount, true);
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveStoneXML[this.stoneCount], "stone", this.stoneCount, true);
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "iceLevin")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 2)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveIceXML[this.iceCount], "ice", this.iceCount, true);
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveLevinXML[this.levinCount], "levin", this.levinCount, true);
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "stoneLevin")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 2)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveStoneXML[this.stoneCount], "stone", this.stoneCount, true);
                                    this.tempObject.getHit(Main.mainClass.readXMLClass.listOfMoveLevinXML[this.levinCount], "levin", this.levinCount, true);
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "getAllLittle")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 4)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject1 = 0;
                                    if (this.fireCount > 0)
                                    {
                                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfMoveFireXML[this.fireCount];
                                    }
                                    if (this.iceCount > 0)
                                    {
                                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfMoveIceXML[this.iceCount];
                                    }
                                    if (this.stoneCount > 0)
                                    {
                                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfMoveStoneXML[this.stoneCount];
                                    }
                                    if (this.levinCount > 0)
                                    {
                                        this.tempObject1 = this.tempObject1 + Main.mainClass.readXMLClass.listOfMoveLevinXML[this.levinCount];
                                    }
                                    if (this.fireCount > 1 || this.iceCount > 1 || this.stoneCount > 1 || this.levinCount > 1)
                                    {
                                        this.tempObject1 = this.tempObject1 * Main.mainClass.readXMLClass.getAllLittleDoubleMultiply;
                                    }
                                    else
                                    {
                                        this.tempObject1 = this.tempObject1 * Main.mainClass.readXMLClass.getAllLittleMultiply;
                                    }
                                    this.tempObject.getHit(this.tempObject1, "getAllLittle");
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
                else if (this.sphereType == "getAll")
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 4)
                    {
                        this.i = this.world.listOfUnits.length - 1;
                        while (this.i >= 0)
                        {
                            
                            this.tempObject = this.world.listOfUnits[this.i];
                            if (this.tempObject.atStage && this.tempObject.readyDamage)
                            {
                                if (Point.distance(this.this_pt, this.tempObject.shoot_pt) < this.radius)
                                {
                                    this.tempObject1 = 0;
                                    if (this.getAllCount == 1)
                                    {
                                        this.tempObject1 = Main.mainClass.readXMLClass.getAllMultiply;
                                    }
                                    else if (this.getAllCount == 2)
                                    {
                                        this.tempObject1 = Main.mainClass.readXMLClass.getAllMultiply1;
                                    }
                                    this.tempObject.getHit(this.tempObject1, "getAll");
                                    if (this.tempObject.dead)
                                    {
                                        (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i - 1;
                            _loc_1.i = _loc_2;
                        }
                    }
                }
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
                this.i = 0;
                while (this.i < this.world.listOfClasses.length)
                {
                    
                    if (this.world.listOfClasses[this.i] == this)
                    {
                        this.world.removeChild(this.world.listOfClasses[this.i]);
                        this.world.listOfClasses.splice(this.i, 1);
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
                if (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter > 0)
                {
                    this.world.achieveManage("castKill_1_enemy");
                }
                else if (this.world.saveBox.gameSave.data.addit_castKillEnemiesCounter >= 100)
                {
                    this.world.achieveManage("castKill_100_enemy");
                }
            }
            return;
        }// end function

    }
}
