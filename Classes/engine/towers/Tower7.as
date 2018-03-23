package engine.towers
{
    import flash.display.*;
    import flash.events.*;

    public class Tower7 extends Tower
    {
        public var ballAnima:BulletTower7_mc;
        public var visCounter:int = 0;
        public var upgr1_intervalCounter:int;
        public var upgr1_intervalTimer:int;
        public var upgr1_damage:Number;
        public var upgr1_anima:MovieClip;
        public var roundCounter:int = 0;
        public var soundCounter:int = 0;
        public var soundTimer:int = 5;

        public function Tower7()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            towerType = 7;
            slotsStack = [0, 0, 1, 1];
            correctYGrPos = -15;
            radius = Main.mainClass.readXMLClass.ultraIceStoneRadiusXML;
            damage = Main.mainClass.readXMLClass.ultraIceStoneDamageXML;
            var _loc_2:* = Main.mainClass.readXMLClass.ultraIceStoneIntervalXML;
            intervalTimer = Main.mainClass.readXMLClass.ultraIceStoneIntervalXML;
            intervalCounter = _loc_2;
            this.upgr1_damage = Main.mainClass.readXMLClass.ultraAddIceStoneDamageXML;
            var _loc_2:* = Main.mainClass.readXMLClass.ultraAddIceStoneIntervalXML;
            this.upgr1_intervalTimer = Main.mainClass.readXMLClass.ultraAddIceStoneIntervalXML;
            this.upgr1_intervalCounter = _loc_2;
            container = new Tower7_mc();
            container.stop();
            container.towerCase.stop();
            container.cont1.stop();
            container.cont2.stop();
            container.cont3.stop();
            container.upgr1_1.stop();
            container.upgr1_2.stop();
            container.upgr1_3.stop();
            container.upgr1_4.stop();
            container.upgr1_5.stop();
            container.upgr1_6.stop();
            container.upgr1_7.stop();
            container.upgr1_8.stop();
            container.round1.stop();
            container.round2.stop();
            container.round3.stop();
            container.round4.stop();
            container.blockTower.stop();
            container.boneBlock.stop();
            container.towerCase.buttonMode = true;
            container.upgr1_1.visible = false;
            container.upgr1_2.visible = false;
            container.upgr1_3.visible = false;
            container.upgr1_4.visible = false;
            container.upgr1_5.visible = false;
            container.upgr1_6.visible = false;
            container.upgr1_7.visible = false;
            container.upgr1_8.visible = false;
            container.round1.visible = false;
            container.round2.visible = false;
            container.round3.visible = false;
            container.round4.visible = false;
            container.blockTower.visible = false;
            container.boneBlock.visible = false;
            this.addChild(container);
            super.init(event);
            container.visible = false;
            var _loc_2:* = 0.9;
            container.scaleY = 0.9;
            container.scaleX = _loc_2;
            return;
        }// end function

        override public function update() : void
        {
            if (this.soundCounter != -1)
            {
                if (this.soundCounter < this.soundTimer)
                {
                    (this.soundCounter + 1);
                }
                else
                {
                    this.soundCounter = -1;
                    container.visible = true;
                    if (!autoBuild)
                    {
                        Sounds.instance.playSoundWithVol("snd_tower_buildUltra", 0.8);
                    }
                }
            }
            else
            {
                super.update();
                if (container.cont1.currentFrame < container.cont1.totalFrames)
                {
                    container.cont1.gotoAndStop((container.cont1.currentFrame + 1));
                }
                else
                {
                    container.cont1.gotoAndStop(1);
                }
                if (container.cont2.currentFrame < container.cont2.totalFrames)
                {
                    container.cont2.gotoAndStop((container.cont2.currentFrame + 1));
                }
                else
                {
                    container.cont2.gotoAndStop(1);
                }
                if (container.cont3.currentFrame < container.cont3.totalFrames)
                {
                    container.cont3.gotoAndStop((container.cont3.currentFrame + 1));
                }
                else
                {
                    container.cont3.gotoAndStop(1);
                }
            }
            return;
        }// end function

        override public function scan() : void
        {
            if (!container.blockTower.visible)
            {
                if (intervalCounter < intervalTimer)
                {
                    (intervalCounter + 1);
                }
                else if (world.frameCounter % 2)
                {
                    scanBlock();
                    if (enemyTarget)
                    {
                        intervalCounter = 0;
                    }
                }
                if (upgradeTypeAdd == 1)
                {
                    if (this.upgr1_intervalCounter < this.upgr1_intervalTimer)
                    {
                        (this.upgr1_intervalCounter + 1);
                    }
                    else if (world.frameCounter % 2)
                    {
                        listOfTargets = [];
                        i = 0;
                        while (i < world.listOfUnits.length)
                        {
                            
                            if (world.listOfUnits[i].readyDamage && world.listOfUnits[i].atStage && !world.listOfUnits[i].airFlag)
                            {
                                tempObject2 = world.bezierClass.getPathPoint(world.listOfUnits[i].path + world.listOfUnits[i].speedK * 16, world.listOfUnits[i].road, world.listOfUnits[i].way);
                                testTarget = new Point(tempObject2.x, tempObject2.y);
                                scanAtRadius();
                                if (greenFlag)
                                {
                                    tempObject1 = world.bezierClass.getPathPoint(world.listOfUnits[i].path + world.listOfUnits[i].speedK * 15, world.listOfUnits[i].road, world.listOfUnits[i].way);
                                    if (this_pt.y > tempObject2.y)
                                    {
                                        if (this_pt.x > tempObject1.x)
                                        {
                                            if (tempObject2.x > tempObject1.x && tempObject2.x - tempObject1.x >= world.listOfUnits[i].speedK * 0.5)
                                            {
                                                world.listOfUnits[i].tempObject1 = container.upgr1_4;
                                                listOfTargets.push(world.listOfUnits[i]);
                                            }
                                            else if (tempObject2.y > tempObject1.y && tempObject2.y - tempObject1.y >= world.listOfUnits[i].speedK * 0.5)
                                            {
                                                world.listOfUnits[i].tempObject1 = container.upgr1_6;
                                                listOfTargets.push(world.listOfUnits[i]);
                                            }
                                        }
                                        else if (tempObject2.x < tempObject1.x && tempObject1.x - tempObject2.x >= world.listOfUnits[i].speedK * 0.5)
                                        {
                                            world.listOfUnits[i].tempObject1 = container.upgr1_3;
                                            listOfTargets.push(world.listOfUnits[i]);
                                        }
                                        else if (tempObject2.y > tempObject1.y && tempObject2.y - tempObject1.y >= world.listOfUnits[i].speedK * 0.5)
                                        {
                                            world.listOfUnits[i].tempObject1 = container.upgr1_8;
                                            listOfTargets.push(world.listOfUnits[i]);
                                        }
                                    }
                                    else if (this_pt.x > tempObject2.x)
                                    {
                                        if (tempObject2.x > tempObject1.x && tempObject2.x - tempObject1.x >= world.listOfUnits[i].speedK * 0.5)
                                        {
                                            world.listOfUnits[i].tempObject1 = container.upgr1_1;
                                            listOfTargets.push(world.listOfUnits[i]);
                                        }
                                        else if (tempObject2.y < tempObject1.y && tempObject1.y - tempObject2.y >= world.listOfUnits[i].speedK * 0.5)
                                        {
                                            world.listOfUnits[i].tempObject1 = container.upgr1_5;
                                            listOfTargets.push(world.listOfUnits[i]);
                                        }
                                    }
                                    else if (tempObject2.x < tempObject1.x && tempObject1.x - tempObject2.x >= world.listOfUnits[i].speedK * 0.5)
                                    {
                                        world.listOfUnits[i].tempObject1 = container.upgr1_2;
                                        listOfTargets.push(world.listOfUnits[i]);
                                    }
                                    else if (tempObject2.y < tempObject1.y && tempObject1.y - tempObject2.y >= world.listOfUnits[i].speedK * 0.5)
                                    {
                                        world.listOfUnits[i].tempObject1 = container.upgr1_7;
                                        listOfTargets.push(world.listOfUnits[i]);
                                    }
                                }
                            }
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                        i = 0;
                        while (i < listOfTargets.length)
                        {
                            
                            listOfTargets[i].tempObject = listOfTargets[i].path / listOfTargets[i].finishPath;
                            if (enemyTarget)
                            {
                                if (listOfTargets[i].tempObject > enemyTarget.tempObject)
                                {
                                    this.upgr1_anima = listOfTargets[i].tempObject1;
                                    enemyTarget = listOfTargets[i];
                                }
                            }
                            else
                            {
                                this.upgr1_anima = listOfTargets[i].tempObject1;
                                enemyTarget = listOfTargets[i];
                                this.upgr1_intervalCounter = 0;
                            }
                            var _loc_2:* = i + 1;
                            i = _loc_2;
                        }
                    }
                }
            }
            else
            {
                blockTowerFunk();
            }
            return;
        }// end function

        override public function attack() : void
        {
            if (intervalCounter == 0)
            {
                if (!this.ballAnima)
                {
                    this.ballAnima = new BulletTower7_mc();
                    this.ballAnima.stop();
                    this.ballAnima.ball.stop();
                    this.ballAnima.smoke.stop();
                    this.ballAnima.smoke.cont1.stop();
                    this.ballAnima.smoke.cont2.stop();
                    this.ballAnima.x = 0;
                    this.ballAnima.y = -20;
                    this.ballAnima.rotation = 180;
                    this.ballAnima.alpha = 0;
                    this.ballAnima.smoke.visible = false;
                    container.addChildAt(this.ballAnima, (container.getChildIndex(container.cont2) + 1));
                }
                else if (this.ballAnima.alpha < 1)
                {
                    this.ballAnima.alpha = this.ballAnima.alpha + 0.1;
                    container.cont2.alpha = container.cont2.alpha - 0.1;
                }
                else if (container.cont2.visible)
                {
                    this.ballAnima.alpha = 1;
                    container.cont2.alpha = 1;
                    container.cont2.visible = false;
                }
                else if (this.ballAnima.y > -40)
                {
                    this.ballAnima.y = this.ballAnima.y - 7;
                }
                else if (this.visCounter < 30)
                {
                    (this.visCounter + 1);
                    if (this.visCounter == 1)
                    {
                        this.ballAnima.visible = false;
                        shoot_pt = container.localToGlobal(new Point(this.ballAnima.x, this.ballAnima.y));
                        world.addBullet(7, shoot_pt, this, enemyTarget, damage);
                    }
                }
                else
                {
                    container.removeChild(this.ballAnima);
                    this.ballAnima = null;
                    this.visCounter = 0;
                    container.cont2.visible = true;
                    intervalCounter = 1;
                    enemyTarget = null;
                    if (this.upgr1_intervalCounter == 0)
                    {
                        this.scan();
                    }
                }
            }
            if (this.upgr1_intervalCounter == 0)
            {
                if (this.roundCounter < 2)
                {
                    if (container.currentFrame < container.totalFrames)
                    {
                        if (this.upgr1_anima.name == "upgr1_1" || this.upgr1_anima.name == "upgr1_3" || this.upgr1_anima.name == "upgr1_6" || this.upgr1_anima.name == "upgr1_7")
                        {
                            if (container.currentFrame <= 8)
                            {
                                if (!container.round1.visible)
                                {
                                    container.round1.visible = true;
                                }
                                else if (container.round1.currentFrame < container.round1.totalFrames)
                                {
                                    container.round1.gotoAndStop((container.round1.currentFrame + 1));
                                    if (this.roundCounter == 0)
                                    {
                                        if (container.round1.currentFrame == 2)
                                        {
                                            Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                                        }
                                    }
                                }
                                else
                                {
                                    container.round1.gotoAndStop(1);
                                }
                                if (container.round2.visible)
                                {
                                    container.round2.visible = false;
                                }
                            }
                            else
                            {
                                if (container.round1.visible)
                                {
                                    container.round1.visible = false;
                                }
                                if (!container.round2.visible)
                                {
                                    container.round2.visible = true;
                                }
                                else if (container.round2.currentFrame < container.round2.totalFrames)
                                {
                                    container.round2.gotoAndStop((container.round2.currentFrame + 1));
                                    if (this.roundCounter == 0)
                                    {
                                        if (container.round2.currentFrame == 2)
                                        {
                                            Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                                        }
                                    }
                                }
                                else
                                {
                                    container.round2.gotoAndStop(1);
                                }
                            }
                        }
                        else if (this.upgr1_anima.name == "upgr1_2" || this.upgr1_anima.name == "upgr1_4" || this.upgr1_anima.name == "upgr1_5" || this.upgr1_anima.name == "upgr1_8")
                        {
                            if (container.currentFrame <= 8)
                            {
                                if (!container.round3.visible)
                                {
                                    container.round3.visible = true;
                                }
                                else if (container.round3.currentFrame < container.round3.totalFrames)
                                {
                                    container.round3.gotoAndStop((container.round3.currentFrame + 1));
                                    if (this.roundCounter == 0)
                                    {
                                        if (container.round3.currentFrame == 2)
                                        {
                                            Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                                        }
                                    }
                                }
                                else
                                {
                                    container.round3.gotoAndStop(1);
                                }
                                if (container.round4.visible)
                                {
                                    container.round2.visible = false;
                                }
                            }
                            else
                            {
                                if (container.round3.visible)
                                {
                                    container.round3.visible = false;
                                }
                                if (!container.round4.visible)
                                {
                                    container.round4.visible = true;
                                }
                                else if (container.round4.currentFrame < container.round4.totalFrames)
                                {
                                    container.round4.gotoAndStop((container.round4.currentFrame + 1));
                                    if (this.roundCounter == 0)
                                    {
                                        if (container.round4.currentFrame == 2)
                                        {
                                            Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                                        }
                                    }
                                }
                                else
                                {
                                    container.round4.gotoAndStop(1);
                                }
                            }
                        }
                        if (this.roundCounter == 1)
                        {
                            if (this.upgr1_anima.name == "upgr1_1")
                            {
                                if (container.currentFrame == 2)
                                {
                                    this.roundCounter = 2;
                                    tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    tempObject.rotation = 15;
                                    tempObject.scaleX = 1;
                                    tempObject.scaleY = 1;
                                    tempObject1 = container.localToGlobal(new Point(this.upgr1_anima.x, this.upgr1_anima.y));
                                    tempObject.x = tempObject1.x;
                                    tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this.upgr1_anima.name == "upgr1_2")
                            {
                                if (container.currentFrame == 2)
                                {
                                    this.roundCounter = 2;
                                    tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    tempObject.rotation = 15;
                                    tempObject.scaleX = -1;
                                    tempObject.scaleY = 1;
                                    tempObject1 = container.localToGlobal(new Point(this.upgr1_anima.x, this.upgr1_anima.y));
                                    tempObject.x = tempObject1.x;
                                    tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this.upgr1_anima.name == "upgr1_3")
                            {
                                if (container.currentFrame == 10)
                                {
                                    this.roundCounter = 2;
                                    tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    tempObject.rotation = -175;
                                    tempObject.scaleX = 1;
                                    tempObject.scaleY = 1;
                                    tempObject1 = container.localToGlobal(new Point(this.upgr1_anima.x, this.upgr1_anima.y));
                                    tempObject.x = tempObject1.x;
                                    tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this.upgr1_anima.name == "upgr1_4")
                            {
                                if (container.currentFrame == 10)
                                {
                                    this.roundCounter = 2;
                                    tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    tempObject.rotation = 175;
                                    tempObject.scaleX = -1;
                                    tempObject.scaleY = 1;
                                    tempObject1 = container.localToGlobal(new Point(this.upgr1_anima.x, this.upgr1_anima.y));
                                    tempObject.x = tempObject1.x;
                                    tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this.upgr1_anima.name == "upgr1_5")
                            {
                                if (container.currentFrame == 15)
                                {
                                    this.roundCounter = 2;
                                    tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    tempObject.rotation = -105;
                                    tempObject.scaleX = 1;
                                    tempObject.scaleY = -1;
                                    tempObject1 = container.localToGlobal(new Point(this.upgr1_anima.x, this.upgr1_anima.y));
                                    tempObject.x = tempObject1.x;
                                    tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this.upgr1_anima.name == "upgr1_6")
                            {
                                if (container.currentFrame == 8)
                                {
                                    this.roundCounter = 2;
                                    tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    tempObject.rotation = 105;
                                    tempObject.scaleX = 1;
                                    tempObject.scaleY = 1;
                                    tempObject1 = container.localToGlobal(new Point(this.upgr1_anima.x, this.upgr1_anima.y));
                                    tempObject.x = tempObject1.x;
                                    tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this.upgr1_anima.name == "upgr1_7")
                            {
                                if (container.currentFrame == 15)
                                {
                                    this.roundCounter = 2;
                                    tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    tempObject.rotation = -75;
                                    tempObject.scaleX = 1;
                                    tempObject.scaleY = 1;
                                    tempObject1 = container.localToGlobal(new Point(this.upgr1_anima.x, this.upgr1_anima.y));
                                    tempObject.x = tempObject1.x;
                                    tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this.upgr1_anima.name == "upgr1_8")
                            {
                                if (container.currentFrame == 8)
                                {
                                    this.roundCounter = 2;
                                    tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    tempObject.rotation = 75;
                                    tempObject.scaleX = 1;
                                    tempObject.scaleY = -1;
                                    tempObject1 = container.localToGlobal(new Point(this.upgr1_anima.x, this.upgr1_anima.y));
                                    tempObject.x = tempObject1.x;
                                    tempObject.y = tempObject1.y;
                                }
                            }
                        }
                        if (this.roundCounter == 2)
                        {
                            container.gotoAndStop(1);
                            container.round1.gotoAndStop(1);
                            container.round2.gotoAndStop(1);
                            container.round3.gotoAndStop(1);
                            container.round4.gotoAndStop(1);
                            container.round1.visible = false;
                            container.round2.visible = false;
                            container.round3.visible = false;
                            container.round4.visible = false;
                        }
                        else
                        {
                            container.gotoAndStop((container.currentFrame + 1));
                        }
                    }
                    else
                    {
                        container.gotoAndStop(1);
                        this.roundCounter = 1;
                    }
                }
                else if (this.upgr1_anima.currentFrame < this.upgr1_anima.totalFrames)
                {
                    this.upgr1_anima.gotoAndStop((this.upgr1_anima.currentFrame + 1));
                    if (this.upgr1_anima.currentFrame == 4)
                    {
                        Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                        i = world.listOfUnits.length - 1;
                        while (i >= 0)
                        {
                            
                            if (world.listOfUnits[i].readyDamage && world.listOfUnits[i].atStage && !world.listOfUnits[i].airFlag && !world.listOfUnits[i].teleportFlag)
                            {
                                if (Point.distance(enemyTarget.shoot_pt, world.listOfUnits[i].shoot_pt) < Main.mainClass.readXMLClass.ultraAddIceStoneRadiusXML)
                                {
                                    if (this.upgr1_anima.name == "upgr1_1")
                                    {
                                        if (this_pt.x + 30 >= world.listOfUnits[i].shoot_pt.x && this_pt.y - 30 <= world.listOfUnits[i].shoot_pt.y && this_pt.y + 150 >= world.listOfUnits[i].shoot_pt.y)
                                        {
                                            world.listOfUnits[i].setAirSettings("tower71");
                                            world.listOfUnits[i].getHit(this.upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this.upgr1_anima.name == "upgr1_2")
                                    {
                                        if (this_pt.x - 30 <= world.listOfUnits[i].shoot_pt.x && this_pt.y - 30 <= world.listOfUnits[i].shoot_pt.y && this_pt.y + 150 >= world.listOfUnits[i].shoot_pt.y)
                                        {
                                            world.listOfUnits[i].setAirSettings("tower71");
                                            world.listOfUnits[i].getHit(this.upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this.upgr1_anima.name == "upgr1_3")
                                    {
                                        if (this_pt.x - 30 <= world.listOfUnits[i].shoot_pt.x && this_pt.y + 30 >= world.listOfUnits[i].shoot_pt.y && this_pt.y - 150 <= world.listOfUnits[i].shoot_pt.y)
                                        {
                                            world.listOfUnits[i].setAirSettings("tower71");
                                            world.listOfUnits[i].getHit(this.upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this.upgr1_anima.name == "upgr1_4")
                                    {
                                        if (this_pt.x + 30 >= world.listOfUnits[i].shoot_pt.x && this_pt.y + 30 >= world.listOfUnits[i].shoot_pt.y && this_pt.y - 150 <= world.listOfUnits[i].shoot_pt.y)
                                        {
                                            world.listOfUnits[i].setAirSettings("tower71");
                                            world.listOfUnits[i].getHit(this.upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this.upgr1_anima.name == "upgr1_5")
                                    {
                                        if (this_pt.x + 30 >= world.listOfUnits[i].shoot_pt.x && this_pt.x - 150 <= world.listOfUnits[i].shoot_pt.x && this_pt.y - 30 <= world.listOfUnits[i].shoot_pt.y)
                                        {
                                            world.listOfUnits[i].setAirSettings("tower71");
                                            world.listOfUnits[i].getHit(this.upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this.upgr1_anima.name == "upgr1_6")
                                    {
                                        if (this_pt.x + 30 >= world.listOfUnits[i].shoot_pt.x && this_pt.x - 150 <= world.listOfUnits[i].shoot_pt.x && this_pt.y + 30 >= world.listOfUnits[i].shoot_pt.y)
                                        {
                                            world.listOfUnits[i].setAirSettings("tower71");
                                            world.listOfUnits[i].getHit(this.upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this.upgr1_anima.name == "upgr1_7")
                                    {
                                        if (this_pt.x - 30 <= world.listOfUnits[i].shoot_pt.x && this_pt.x + 150 >= world.listOfUnits[i].shoot_pt.x && this_pt.y - 30 <= world.listOfUnits[i].shoot_pt.y)
                                        {
                                            world.listOfUnits[i].setAirSettings("tower71");
                                            world.listOfUnits[i].getHit(this.upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this.upgr1_anima.name == "upgr1_8")
                                    {
                                        if (this_pt.x - 30 <= world.listOfUnits[i].shoot_pt.x && this_pt.x + 150 >= world.listOfUnits[i].shoot_pt.x && this_pt.y + 30 >= world.listOfUnits[i].shoot_pt.y)
                                        {
                                            world.listOfUnits[i].setAirSettings("tower71");
                                            world.listOfUnits[i].getHit(this.upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                }
                            }
                            var _loc_2:* = i - 1;
                            i = _loc_2;
                        }
                    }
                }
                else
                {
                    this.roundCounter = 0;
                    this.upgr1_anima.gotoAndStop(1);
                    this.upgr1_anima.visible = false;
                    this.upgr1_intervalCounter = 1;
                    enemyTarget = null;
                }
            }
            return;
        }// end function

    }
}
