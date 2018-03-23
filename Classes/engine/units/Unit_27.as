package engine.units
{
    import flash.events.*;

    public class Unit_27 extends Unit
    {
        public var teleportPhase:int = 0;
        public var teleportTimer:int;
        public var teleportCounter:int;
        public var teleportStealthTimer:int;
        public var teleportStealthCounter:int;
        public var teleportDistance:Number;
        public var teleportRadius:Number;
        public var listOfTeleportUnits:Array;
        public var soundCounter:int = 0;
        public var soundTimer:int = 5;
        public var soundTimer1:int = 4;
        public var teleportUnitsMax:int = 5;
        public var teleportUnitsCounter:int = 0;

        public function Unit_27()
        {
            this.listOfTeleportUnits = [];
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 27;
            var _loc_2:* = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            this.teleportCounter = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
            this.teleportTimer = _loc_2;
            var _loc_2:* = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            this.teleportStealthCounter = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
            this.teleportStealthTimer = _loc_2;
            this.teleportDistance = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][32];
            this.teleportRadius = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][33];
            this.teleportUnitsMax = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
            container = new Unit27_mc();
            var _loc_2:* = 0.9;
            container.scaleY = 0.9;
            container.scaleX = _loc_2;
            super.init(event);
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!dead && !icemanFlag && !airFlag && !airShockFlag)
            {
                if (!teleportFlag)
                {
                    if (this.teleportCounter > 0)
                    {
                        (this.teleportCounter - 1);
                    }
                    else if (this.soundCounter < this.soundTimer)
                    {
                        (this.soundCounter + 1);
                        if (this.soundCounter == 1)
                        {
                            Sounds.instance.playSoundWithVol("snd_unit_teleport", 0.85);
                        }
                    }
                    else
                    {
                        this.soundCounter = 0;
                        teleportFlag = true;
                        readyDamage = false;
                        mainMoveFlag = false;
                        this.teleportCounter = this.teleportTimer;
                        i = 0;
                        while (i < world.listOfUnits.length)
                        {
                            
                            if (world.listOfUnits[i].road == road)
                            {
                                if (!world.listOfUnits[i].dead && world.listOfUnits[i].readyDamage && world.listOfUnits[i].atStage && !world.listOfUnits[i].teleportAnima)
                                {
                                    if (world.listOfUnits[i].typeUnit != 27 && world.listOfUnits[i].typeUnit != 34)
                                    {
                                        if (Point.distance(this_pt, world.listOfUnits[i].this_pt) < this.teleportRadius)
                                        {
                                            if (this.teleportUnitsCounter < this.teleportUnitsMax)
                                            {
                                                (this.teleportUnitsCounter + 1);
                                                world.listOfUnits[i].teleportFlag = this;
                                                world.listOfUnits[i].readyDamage = false;
                                                world.listOfUnits[i].mainMoveFlag = false;
                                                this.listOfTeleportUnits.push(world.listOfUnits[i]);
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                        if (this.teleportUnitsCounter < this.teleportUnitsMax)
                        {
                            i = 0;
                            while (i < world.listOfUnits.length)
                            {
                                
                                if (world.listOfUnits[i].road != road)
                                {
                                    if (!world.listOfUnits[i].dead && world.listOfUnits[i].readyDamage && world.listOfUnits[i].atStage && !world.listOfUnits[i].teleportAnima)
                                    {
                                        if (world.listOfUnits[i].typeUnit != 27 && world.listOfUnits[i].typeUnit != 34)
                                        {
                                            if (Point.distance(this_pt, world.listOfUnits[i].this_pt) < this.teleportRadius)
                                            {
                                                if (this.teleportUnitsCounter < this.teleportUnitsMax)
                                                {
                                                    (this.teleportUnitsCounter + 1);
                                                    world.listOfUnits[i].teleportFlag = this;
                                                    world.listOfUnits[i].readyDamage = false;
                                                    world.listOfUnits[i].mainMoveFlag = false;
                                                    this.listOfTeleportUnits.push(world.listOfUnits[i]);
                                                }
                                                else
                                                {
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                                var _loc_2:* = i + 1;
                                i = _loc_2;
                            }
                        }
                        this.teleportUnitsCounter = 0;
                    }
                }
                else if (this.teleportPhase == 0)
                {
                    if (!teleportAnima)
                    {
                        teleportAnima = new UnitTeleportOut_mc();
                        teleportAnima.stop();
                        teleportAnima.x = container.unitCase.x;
                        teleportAnima.y = container.unitCase.y;
                        var _loc_1:* = false;
                        teleportAnima.mouseChildren = false;
                        teleportAnima.mouseEnabled = _loc_1;
                        this.addChild(teleportAnima);
                        i = 0;
                        while (i < this.listOfTeleportUnits.length)
                        {
                            
                            this.listOfTeleportUnits[i].teleportAnima = new UnitTeleportOut_mc();
                            this.listOfTeleportUnits[i].teleportAnima.stop();
                            this.listOfTeleportUnits[i].teleportAnima.x = this.listOfTeleportUnits[i].container.unitCase.x;
                            this.listOfTeleportUnits[i].teleportAnima.y = this.listOfTeleportUnits[i].container.unitCase.y;
                            var _loc_1:* = false;
                            this.listOfTeleportUnits[i].teleportAnima.mouseChildren = false;
                            this.listOfTeleportUnits[i].teleportAnima.mouseEnabled = _loc_1;
                            this.listOfTeleportUnits[i].addChild(this.listOfTeleportUnits[i].teleportAnima);
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                    }
                    else if (teleportAnima.currentFrame < teleportAnima.totalFrames)
                    {
                        teleportAnima.gotoAndStop((teleportAnima.currentFrame + 1));
                        container.alpha = container.alpha - 0.1;
                        i = 0;
                        while (i < this.listOfTeleportUnits.length)
                        {
                            
                            this.listOfTeleportUnits[i].teleportAnima.gotoAndStop((this.listOfTeleportUnits[i].teleportAnima.currentFrame + 1));
                            this.listOfTeleportUnits[i].container.alpha = this.listOfTeleportUnits[i].container.alpha - 0.1;
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                    }
                    else
                    {
                        this.teleportPhase = 1;
                        container.alpha = 0;
                        container.visible = false;
                        this.removeChild(teleportAnima);
                        teleportAnima = null;
                        i = 0;
                        while (i < this.listOfTeleportUnits.length)
                        {
                            
                            if (this.listOfTeleportUnits[i].teleportAnima)
                            {
                                this.listOfTeleportUnits[i].container.alpha = 0;
                                this.listOfTeleportUnits[i].visible = false;
                                this.listOfTeleportUnits[i].removeChild(this.listOfTeleportUnits[i].teleportAnima);
                                this.listOfTeleportUnits[i].teleportAnima = null;
                            }
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                        j = 0;
                        i = 0;
                        while (i < this.listOfTeleportUnits.length)
                        {
                            
                            if (this.listOfTeleportUnits[i].road != road)
                            {
                                j = j + 5;
                                this.listOfTeleportUnits[i].road = road;
                                this.listOfTeleportUnits[i].path = path + j;
                                this.listOfTeleportUnits[i].finishPath = finishPath;
                            }
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                    }
                }
                else if (this.teleportPhase == 1)
                {
                    if (this.teleportStealthCounter > 0)
                    {
                        (this.teleportStealthCounter - 1);
                    }
                    else if (this.soundCounter < this.soundTimer1)
                    {
                        (this.soundCounter + 1);
                        if (this.soundCounter == 1)
                        {
                            Sounds.instance.playSoundWithVol("snd_unit_teleport", 0.85);
                        }
                    }
                    else
                    {
                        this.soundCounter = 0;
                        this.teleportPhase = 2;
                        container.visible = true;
                        path = path + this.teleportDistance;
                        this.teleportStealthCounter = this.teleportStealthTimer;
                        tempObject = world.bezierClass.getPathPoint(path, road, way);
                        this.x = tempObject.x;
                        this.y = tempObject.y;
                        this_pt = new Point(this.x, this.y);
                        shoot_pt = container.localToGlobal(new Point(container.cont.x, container.cont.y));
                        teleportAnima = new UnitTeleportIn_mc();
                        teleportAnima.stop();
                        teleportAnima.x = container.unitCase.x;
                        teleportAnima.y = container.unitCase.y;
                        var _loc_1:* = false;
                        teleportAnima.mouseChildren = false;
                        teleportAnima.mouseEnabled = _loc_1;
                        this.addChild(teleportAnima);
                        i = 0;
                        while (i < this.listOfTeleportUnits.length)
                        {
                            
                            this.listOfTeleportUnits[i].visible = true;
                            this.listOfTeleportUnits[i].path = this.listOfTeleportUnits[i].path + this.teleportDistance;
                            tempObject = world.bezierClass.getPathPoint(this.listOfTeleportUnits[i].path, this.listOfTeleportUnits[i].road, this.listOfTeleportUnits[i].way);
                            this.listOfTeleportUnits[i].x = tempObject.x;
                            this.listOfTeleportUnits[i].y = tempObject.y;
                            this.listOfTeleportUnits[i].this_pt = new Point(this.listOfTeleportUnits[i].x, this.listOfTeleportUnits[i].y);
                            this.listOfTeleportUnits[i].shoot_pt = this.listOfTeleportUnits[i].container.localToGlobal(new Point(this.listOfTeleportUnits[i].container.cont.x, this.listOfTeleportUnits[i].container.cont.y));
                            this.listOfTeleportUnits[i].teleportAnima = new UnitTeleportIn_mc();
                            this.listOfTeleportUnits[i].teleportAnima.stop();
                            this.listOfTeleportUnits[i].teleportAnima.x = this.listOfTeleportUnits[i].container.unitCase.x;
                            this.listOfTeleportUnits[i].teleportAnima.y = this.listOfTeleportUnits[i].container.unitCase.y;
                            var _loc_1:* = false;
                            this.listOfTeleportUnits[i].teleportAnima.mouseChildren = false;
                            this.listOfTeleportUnits[i].teleportAnima.mouseEnabled = _loc_1;
                            this.listOfTeleportUnits[i].addChild(this.listOfTeleportUnits[i].teleportAnima);
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                    }
                }
                else if (this.teleportPhase == 2)
                {
                    if (teleportAnima.currentFrame < teleportAnima.totalFrames)
                    {
                        teleportAnima.gotoAndStop((teleportAnima.currentFrame + 1));
                        container.alpha = container.alpha + 0.1;
                        i = 0;
                        while (i < this.listOfTeleportUnits.length)
                        {
                            
                            this.listOfTeleportUnits[i].teleportAnima.gotoAndStop((this.listOfTeleportUnits[i].teleportAnima.currentFrame + 1));
                            this.listOfTeleportUnits[i].container.alpha = this.listOfTeleportUnits[i].container.alpha + 0.1;
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                    }
                    else
                    {
                        this.teleportPhase = 0;
                        container.alpha = 1;
                        teleportFlag = false;
                        readyDamage = true;
                        mainMoveFlag = true;
                        this.removeChild(teleportAnima);
                        teleportAnima = null;
                        directionFlag = true;
                        moveHandler();
                        i = 0;
                        while (i < this.listOfTeleportUnits.length)
                        {
                            
                            if (this.listOfTeleportUnits[i].teleportFlag == this)
                            {
                                this.listOfTeleportUnits[i].container.alpha = 1;
                                this.listOfTeleportUnits[i].teleportFlag = false;
                                this.listOfTeleportUnits[i].readyDamage = true;
                                this.listOfTeleportUnits[i].mainMoveFlag = true;
                                this.listOfTeleportUnits[i].removeChild(this.listOfTeleportUnits[i].teleportAnima);
                                this.listOfTeleportUnits[i].teleportAnima = null;
                                this.listOfTeleportUnits[i].directionFlag = true;
                                this.listOfTeleportUnits[i].moveHandler();
                            }
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                        this.listOfTeleportUnits.length = [];
                    }
                }
                if (direction != "up")
                {
                    if (container.cont.currentFrame < 9)
                    {
                        if (container.cont.currentFrame < 8)
                        {
                            container.cont.gotoAndStop((container.cont.currentFrame + 1));
                        }
                        else
                        {
                            container.cont.gotoAndStop(1);
                        }
                    }
                    else
                    {
                        container.cont.gotoAndStop(container.cont.currentFrame - 8);
                    }
                }
                else if (container.cont.currentFrame > 8)
                {
                    if (container.cont.currentFrame < container.cont.totalFrames)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                    }
                    else
                    {
                        container.cont.gotoAndStop(9);
                    }
                }
                else
                {
                    container.cont.gotoAndStop(container.cont.currentFrame + 8);
                }
                if (direction == "left" || direction == "right")
                {
                    if (!airFlag && !airShockFlag || container.currentFrame != 1)
                    {
                        if (container.currentFrame > 16)
                        {
                            if (container.currentFrame < container.totalFrames)
                            {
                                container.gotoAndStop((container.currentFrame + 1));
                            }
                            else
                            {
                                container.gotoAndStop(1);
                            }
                        }
                        else if (container.currentFrame < 16)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container.currentFrame != 17)
                {
                    if (container.currentFrame > 16)
                    {
                        if (container.currentFrame < container.totalFrames)
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                        else
                        {
                            container.gotoAndStop(17);
                        }
                    }
                    else if (container.currentFrame < 16)
                    {
                        container.gotoAndStop((container.currentFrame + 1));
                    }
                    else
                    {
                        container.gotoAndStop(17);
                    }
                }
            }
            super.animationHandler();
            return;
        }// end function

        override public function kill() : void
        {
            if (teleportFlag)
            {
                while (teleportFlag)
                {
                    
                    this.animationHandler();
                }
            }
            super.kill();
            return;
        }// end function

    }
}
