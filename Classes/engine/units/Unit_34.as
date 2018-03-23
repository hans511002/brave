package engine.units
{
    import engine.*;
    import flash.events.*;

    public class Unit_34 extends Unit
    {
        public var phase:int = 0;
        public var teleportStatus:int = 0;
        public var eyesFlag:Boolean;
        public var eyesCounter:int = 0;
        public var eyesCounter1:int = 0;
        public var eyesCounter2:int = 0;
        public var readXML:ReadXML;
        public var phaseRoad1:int = 0;
        public var phaseRoad2:int = 0;
        public var giveArmorFlag:Boolean;
        public var takeAwayCastsFlag:Boolean;
        public var changeRoad:String;
        public var speakFlag:Boolean;
        public var notAtRoad:int = 0;
        public var musicVolumeManageCounter:int = 0;
        public var greenFlag:Boolean;
        public var arrayTurn:Array;
        public var callUnitsCounter:int = 0;
        public var roadFlag:Boolean;

        public function Unit_34()
        {
            this.readXML = Main.mainClass.readXMLClass;
            this.arrayTurn = [];
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 34;
            container = new Unit34_mc();
            container.walkIn.stop();
            container.walkOut.stop();
            container.speak.stop();
            var _loc_2:* = 0.85;
            container.scaleY = 0.85;
            container.scaleX = _loc_2;
            container.walkIn.visible = false;
            container.walkOut.visible = false;
            container.speak.visible = false;
            super.init(event);
            world.boss = this;
            readyDamage = false;
            moveFlag = false;
            mainMoveFlag = false;
            this.visible = false;
            if (Math.random() < 0.5)
            {
                road = 1;
            }
            else
            {
                road = 2;
            }
            way = 3;
            if (road == 1)
            {
                path = this.readXML.bossArrayPhasePath[0][this.phaseRoad1];
            }
            else if (road == 2)
            {
                path = this.readXML.bossArrayPhasePath[1][this.phaseRoad2];
            }
            this.x = 398;
            this.y = 158;
            this_pt = new Point(this.x, this.y);
            shoot_pt = container.localToGlobal(new Point(container.cont.x, container.cont.y));
            this.speakFlag = true;
            if (world.worldInterface.fasterFlag == 2)
            {
                world.worldInterface.fasterManage(false);
            }
            world.worldInterface.container.快.fastCase.buttonMode = false;
            Sounds.instance.playSound("snd_boss_start");
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!dead && this.visible && !icemanFlag)
            {
                if (!airFlag && this.teleportStatus == 0 && !this.eyesFlag && !this.giveArmorFlag && !this.takeAwayCastsFlag && !this.speakFlag)
                {
                    if (this.readXML.bossArrayOfView.length > 0)
                    {
                        if (this.readXML.bossArrayOfView[0][0] > 0)
                        {
                            (this.readXML.bossArrayOfView[0][0] - 1);
                        }
                        else
                        {
                            this.changeRoad = this.readXML.bossArrayOfView[0][1];
                            this.readXML.bossArrayOfView.splice(0, 1);
                            (this.phase + 1);
                            this.teleportStatus = 1;
                            readyDamage = false;
                            if (armorFlag)
                            {
                                stopAllEffects("armor");
                            }
                        }
                    }
                    if (this.readXML.bossArrayOfEnemies.length > 0)
                    {
                        if (this.readXML.bossArrayOfEnemies[0].length > 0)
                        {
                            if (this.readXML.bossArrayOfEnemies[0][0] > 0)
                            {
                                if (world.frameCounter == 30 && this.phase > 0)
                                {
                                    this.greenFlag = false;
                                    i = 0;
                                    while (i < world.listOfUnits.length)
                                    {
                                        
                                        if (world.listOfUnits[i].myParent == this)
                                        {
                                            this.greenFlag = true;
                                            break;
                                        }
                                        var _loc_2:* = i + 1;
                                        i = _loc_2;
                                    }
                                    if (!this.greenFlag)
                                    {
                                        this.readXML.bossArrayOfEnemies[0][0] = 1;
                                    }
                                }
                                (this.readXML.bossArrayOfEnemies[0][0] - 1);
                            }
                            else
                            {
                                (this.callUnitsCounter + 1);
                                if (this.callUnitsCounter == 1)
                                {
                                    this.eyesFlag = true;
                                }
                                tempObject = [];
                                tempObject = tempObject.concat(this.readXML.bossArrayOfEnemies[0]);
                                this.arrayTurn.push(tempObject);
                                this.readXML.bossArrayOfEnemies.splice(0, 1);
                            }
                        }
                    }
                    if (this.readXML.bossArrayOfArmor.length > 0)
                    {
                        if (this.readXML.bossArrayOfArmor[0] > 0)
                        {
                            (this.readXML.bossArrayOfArmor[0] - 1);
                        }
                        else
                        {
                            this.readXML.bossArrayOfArmor.splice(0, 1);
                            this.giveArmorFlag = true;
                            Sounds.instance.playSound("snd_boss_eyes");
                        }
                    }
                    if (this.readXML.bossArrayOfCasts.length > 0)
                    {
                        if (this.readXML.bossArrayOfCasts[0] > 0)
                        {
                            (this.readXML.bossArrayOfCasts[0] - 1);
                        }
                        else
                        {
                            this.readXML.bossArrayOfCasts.splice(0, 1);
                            this.takeAwayCastsFlag = true;
                            Sounds.instance.playSound("snd_boss_eyes");
                        }
                    }
                }
                else if (this.teleportStatus > 0)
                {
                    if (icemanFlag)
                    {
                        if (icemanCounter != 0)
                        {
                            icemanCounter = 0;
                        }
                    }
                    else if (this.teleportStatus == 1)
                    {
                        if (!container.walkIn.visible)
                        {
                            container.walkIn.visible = true;
                            stopAllEffects();
                            if (health < healthMax)
                            {
                                container.healthBar.visible = true;
                            }
                            var _loc_1:* = false;
                            this.mouseChildren = false;
                            this.mouseEnabled = _loc_1;
                            Sounds.instance.playSound("snd_boss_appearDisappear");
                        }
                        else if (container.walkIn.currentFrame < container.walkIn.totalFrames)
                        {
                            container.walkIn.gotoAndStop((container.walkIn.currentFrame + 1));
                            if (container.cont.alpha > 0)
                            {
                                container.cont.alpha = container.cont.alpha - 0.2;
                            }
                        }
                        else
                        {
                            container.walkIn.gotoAndStop(1);
                            container.walkIn.visible = false;
                            container.cont.alpha = 0;
                            container.cont.gotoAndStop(1);
                            this.teleportStatus = 2;
                            direction = "无";
                            if ((!this.roadFlag || this.changeRoad == "true") && health > 0)
                            {
                                this.roadFlag = true;
                                if (road == 1)
                                {
                                    if (this.phaseRoad1 < this.readXML.bossArrayPhasePath[0].length)
                                    {
                                        (this.phaseRoad1 + 1);
                                    }
                                    road = 2;
                                    path = this.readXML.bossArrayPhasePath[1][this.phaseRoad2];
                                    tempObject = world.bezierClass.getPathPoint(path, road, way);
                                }
                                else
                                {
                                    if (this.phaseRoad2 < this.readXML.bossArrayPhasePath[1].length)
                                    {
                                        (this.phaseRoad2 + 1);
                                    }
                                    road = 1;
                                    path = this.readXML.bossArrayPhasePath[0][this.phaseRoad1];
                                    tempObject = world.bezierClass.getPathPoint(path, road, way);
                                }
                                var _loc_1:* = 0.67;
                                container.scaleY = 0.67;
                                container.scaleX = _loc_1;
                                this.x = tempObject.x;
                                this.y = tempObject.y;
                                this_pt = new Point(this.x, this.y);
                                shoot_pt = container.localToGlobal(new Point(container.cont.x, container.cont.y));
                            }
                            else
                            {
                                this.roadFlag = false;
                                var _loc_1:* = 0.85;
                                container.scaleY = 0.85;
                                container.scaleX = _loc_1;
                                this.x = 398;
                                this.y = 158;
                                this_pt = new Point(this.x, this.y);
                                shoot_pt = container.localToGlobal(new Point(container.cont.x, container.cont.y));
                                var _loc_1:* = this;
                                var _loc_2:* = this.notAtRoad + 1;
                                _loc_1.notAtRoad = _loc_2;
                                if (health > 0)
                                {
                                    if (this.notAtRoad % 2)
                                    {
                                        this.speakFlag = true;
                                    }
                                }
                                else
                                {
                                    this.kill();
                                    return;
                                }
                            }
                        }
                    }
                    else if (this.teleportStatus == 2)
                    {
                        if (!container.walkOut.visible)
                        {
                            container.walkOut.visible = true;
                            Sounds.instance.playSound("snd_boss_appearDisappear");
                        }
                        else if (container.walkOut.currentFrame < container.walkOut.totalFrames)
                        {
                            container.walkOut.gotoAndStop((container.walkOut.currentFrame + 1));
                            if (container.cont.alpha < 1)
                            {
                                container.cont.alpha = container.cont.alpha + 0.2;
                            }
                        }
                        else
                        {
                            container.walkOut.gotoAndStop(1);
                            container.walkOut.visible = false;
                            container.cont.alpha = 1;
                            this.teleportStatus = 0;
                            if (this.roadFlag)
                            {
                                readyDamage = true;
                            }
                            var _loc_1:* = true;
                            this.mouseChildren = true;
                            this.mouseEnabled = _loc_1;
                        }
                    }
                }
                else if (this.eyesFlag)
                {
                    if (container.cont.currentFrame < 18)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                        if (container.cont.currentFrame == 2)
                        {
                            Sounds.instance.playSound("snd_boss_eyes");
                        }
                    }
                    else if (this.eyesCounter == 0)
                    {
                        (this.eyesCounter + 1);
                        container.cont.gotoAndStop(1);
                    }
                    else
                    {
                        this.eyesFlag = false;
                        this.eyesCounter = 0;
                        container.cont.gotoAndStop(1);
                    }
                }
                else if (this.giveArmorFlag)
                {
                    if (container.cont.currentFrame < 19)
                    {
                        container.cont.gotoAndStop(19);
                    }
                    else if (container.cont.currentFrame < 36)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                    }
                    else if (this.eyesCounter1 == 0)
                    {
                        (this.eyesCounter1 + 1);
                        container.cont.gotoAndStop(19);
                    }
                    else if (this.eyesCounter1 == 1)
                    {
                        this.giveArmorFlag = false;
                        this.eyesCounter1 = 0;
                        container.cont.gotoAndStop(1);
                        i = 0;
                        while (i < world.listOfUnits.length)
                        {
                            
                            if (world.listOfUnits[i].atStage && world.listOfUnits[i].readyDamage && !world.listOfUnits[i].armorFlag && world.listOfUnits[i] != this)
                            {
                                world.listOfUnits[i].armorPower = 90;
                                world.listOfUnits[i].armorCounter = 80;
                            }
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                    }
                }
                else if (this.takeAwayCastsFlag)
                {
                    if (container.cont.currentFrame < 37)
                    {
                        container.cont.gotoAndStop(37);
                    }
                    else if (container.cont.currentFrame < 54)
                    {
                        container.cont.gotoAndStop((container.cont.currentFrame + 1));
                    }
                    else if (this.eyesCounter2 == 0)
                    {
                        (this.eyesCounter2 + 1);
                        container.cont.gotoAndStop(37);
                    }
                    else if (this.eyesCounter2 == 1)
                    {
                        this.takeAwayCastsFlag = false;
                        this.eyesCounter2 = 0;
                        tempObject = new AnimUpgrade_mc();
                        tempObject.stop();
                        tempObject.x = world.worldInterface.container.butCastGolem.x + world.worldInterface.container.butCastGolem.castGolemCase.x;
                        tempObject.y = world.worldInterface.container.butCastGolem.y + world.worldInterface.container.butCastGolem.castGolemCase.y;
                        var _loc_1:* = false;
                        tempObject.mouseChildren = false;
                        tempObject.mouseEnabled = _loc_1;
                        world.worldInterface.addChild(tempObject);
                        world.worldInterface.listOfAnimation.push(tempObject);
                        tempObject = new AnimUpgrade_mc();
                        tempObject.stop();
                        tempObject.x = world.worldInterface.container.butCastIceman.x + world.worldInterface.container.butCastIceman.castIcemanCase.x;
                        tempObject.y = world.worldInterface.container.butCastIceman.y + world.worldInterface.container.butCastIceman.castIcemanCase.y;
                        var _loc_1:* = false;
                        tempObject.mouseChildren = false;
                        tempObject.mouseEnabled = _loc_1;
                        world.worldInterface.addChild(tempObject);
                        world.worldInterface.listOfAnimation.push(tempObject);
                        tempObject = new AnimUpgrade_mc();
                        tempObject.stop();
                        tempObject.x = world.worldInterface.container.butCastAir.x + world.worldInterface.container.butCastAir.castAirCase.x;
                        tempObject.y = world.worldInterface.container.butCastAir.y + world.worldInterface.container.butCastAir.castAirCase.y;
                        var _loc_1:* = false;
                        tempObject.mouseChildren = false;
                        tempObject.mouseEnabled = _loc_1;
                        world.worldInterface.addChild(tempObject);
                        world.worldInterface.listOfAnimation.push(tempObject);
                        if (world.cast)
                        {
                            world.cast.kill();
                        }
                        world.worldInterface.castGolemCounter = 1;
                        world.worldInterface.container.butCastGolem.gotoAndStop(4);
                        world.worldInterface.container.butCastGolem.castGolemCase.buttonMode = false;
                        world.worldInterface.container.butCastGolem.cont.contMask.scaleY = 0;
                        world.worldInterface.castIcemanCounter = 1;
                        world.worldInterface.container.butCastIceman.gotoAndStop(4);
                        world.worldInterface.container.butCastIceman.castIcemanCase.buttonMode = false;
                        world.worldInterface.container.butCastIceman.cont.contMask.scaleY = 0;
                        world.worldInterface.castAirCounter = 1;
                        world.worldInterface.container.butCastAir.gotoAndStop(4);
                        world.worldInterface.container.butCastAir.castAirCase.buttonMode = false;
                        world.worldInterface.container.butCastAir.cont.contMask.scaleY = 0;
                        Sounds.instance.playSound("snd_boss_castReset");
                    }
                }
                else if (this.speakFlag)
                {
                    if (!container.speak.visible)
                    {
                        container.speak.visible = true;
                        Sounds.instance.playSound("snd_boss_speak");
                    }
                    else if (container.speak.currentFrame < container.speak.totalFrames)
                    {
                        container.speak.gotoAndStop((container.speak.currentFrame + 1));
                    }
                    else if (!container.speak.flag)
                    {
                        container.speak.flag = true;
                        container.speak.gotoAndStop(1);
                        if (this.musicVolumeManageCounter == 0)
                        {
                            this.musicVolumeManageCounter = 1;
                        }
                    }
                    else
                    {
                        container.speak.flag = false;
                        this.speakFlag = false;
                        container.speak.gotoAndStop(1);
                        container.speak.visible = false;
                        if (!world.worldInterface.container.快.fastCase.buttonMode)
                        {
                            world.worldInterface.container.快.fastCase.buttonMode = true;
                        }
                    }
                }
            }
            if (this.arrayTurn.length > 0)
            {
                if (this.arrayTurn[0][1].length > 0)
                {
                    if (!this.arrayTurn[0][2])
                    {
                        if (this.arrayTurn[0][1][0][1] > 0)
                        {
                            this.arrayTurn[0][2] = this.arrayTurn[0][1][0][2];
                            tempObject = world.addUnit(this.arrayTurn[0][1][0][0], this.arrayTurn[0][1][0][7], this.arrayTurn[0][1][0][3], this.arrayTurn[0][1][0][4], this.arrayTurn[0][1][0][5], this.arrayTurn[0][1][0][6]);
                            tempObject.myParent = this;
                            (this.arrayTurn[0][1][0][1] - 1);
                        }
                        else
                        {
                            this.arrayTurn[0][1].splice(0, 1);
                        }
                    }
                    else if (this.arrayTurn[0][2] > 0)
                    {
                        (this.arrayTurn[0][2] - 1);
                    }
                    else if (this.arrayTurn[0][1][0][1] > 0)
                    {
                        this.arrayTurn[0][2] = this.arrayTurn[0][1][0][2];
                        tempObject = world.addUnit(this.arrayTurn[0][1][0][0], this.arrayTurn[0][1][0][7], this.arrayTurn[0][1][0][3], this.arrayTurn[0][1][0][4], this.arrayTurn[0][1][0][5], this.arrayTurn[0][1][0][6]);
                        tempObject.myParent = this;
                        (this.arrayTurn[0][1][0][1] - 1);
                    }
                    else
                    {
                        this.arrayTurn[0][1].splice(0, 1);
                    }
                }
                else
                {
                    this.arrayTurn.splice(0, 1);
                }
            }
            if (this.musicVolumeManageCounter == 1)
            {
                if (Sounds.instance.musicChanel)
                {
                    if (Sounds.instance.musicChanel.soundTransform.volume < world.startMusicVolume)
                    {
                        Sounds.instance.musicChanel.soundTransform = new SoundTransform(Sounds.instance.musicChanel.soundTransform.volume + world.startMusicVolume * 0.035, 0);
                    }
                    else
                    {
                        world.startMusicVolume = 0;
                        this.musicVolumeManageCounter = 2;
                    }
                }
                else
                {
                    world.startMusicVolume = 0;
                    this.musicVolumeManageCounter = 2;
                }
            }
            if (this.musicVolumeManageCounter == 3)
            {
                if (Sounds.instance.musicChanel)
                {
                    if (world.startMusicVolume == 0)
                    {
                        world.startMusicVolume = Sounds.instance.musicChanel.soundTransform.volume;
                    }
                    if (Sounds.instance.musicChanel.soundTransform.volume > world.startMusicVolume * 0.35)
                    {
                        Sounds.instance.musicChanel.soundTransform = new SoundTransform(Sounds.instance.musicChanel.soundTransform.volume - world.startMusicVolume * 0.035, 0);
                    }
                    else
                    {
                        this.musicVolumeManageCounter = 4;
                    }
                }
                else
                {
                    this.musicVolumeManageCounter = 4;
                }
            }
            super.animationHandler();
            return;
        }// end function

        override public function kill() : void
        {
            if (this.roadFlag)
            {
                if (icemanFlag)
                {
                    if (icemanCounter != 0)
                    {
                        icemanCounter = 0;
                    }
                }
                this.teleportStatus = 1;
                readyDamage = false;
                if (world.worldInterface.fasterFlag == 2)
                {
                    world.worldInterface.fasterManage(false);
                }
                world.worldInterface.container.快.fastCase.buttonMode = false;
                this.musicVolumeManageCounter = 3;
                return;
            }
            if (!dead && health <= 0)
            {
                tempObject = new Indexes(new Unit34Death_mc(), 3);
                tempObject.x = shoot_pt.x;
                tempObject.y = shoot_pt.y - 44.5;
                new InTimer("bossDeath");
                new InTimer("bossSpeakInDeath");
                world.wavesClass.listOfWaves[0] = [];
                world.wavesClass.listOfWaves[1] = [];
                world.wavesClass.listOfWaves[2] = [];
                world.wavesClass.wavesHandler();
                i = world.listOfUnits.length - 1;
                while (i >= 0)
                {
                    
                    if (world.listOfUnits[i] != this)
                    {
                        world.listOfUnits[i].health = 0;
                        world.listOfUnits[i].kill();
                    }
                    var _loc_2:* = i - 1;
                    i = _loc_2;
                }
                i = world.listOfUnits.length - 1;
                while (i >= 0)
                {
                    
                    if (world.listOfUnits[i] != this)
                    {
                        world.listOfUnits[i].health = 0;
                        world.listOfUnits[i].kill();
                    }
                    var _loc_2:* = i - 1;
                    i = _loc_2;
                }
            }
            super.kill();
            return;
        }// end function

    }
}
