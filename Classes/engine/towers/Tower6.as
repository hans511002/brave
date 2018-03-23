package engine.towers
{
    import flash.events.*;

    public class Tower6 extends Tower
    {
        public var upgr1_intervalCounter:int;
        public var upgr1_intervalTimer:int;
        public var upgr1_damage:Number;
        public var soundCounter:int = 0;
        public var soundTimer:int = 5;

        public function Tower6()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            towerType = 6;
            slotsStack = [0, 0, 1, 1];
            correctYGrPos = -35;
            radius = Main.mainClass.readXMLClass.ultraIceLevinRadiusXML;
            damage = Main.mainClass.readXMLClass.ultraIceLevinDamageXML;
            var _loc_2:* = Main.mainClass.readXMLClass.ultraIceLevinIntervalXML;
            intervalTimer = Main.mainClass.readXMLClass.ultraIceLevinIntervalXML;
            intervalCounter = _loc_2;
            this.upgr1_damage = Main.mainClass.readXMLClass.ultraAddIceLevinDamageXML;
            var _loc_2:* = Main.mainClass.readXMLClass.ultraAddIceLevinIntervalXML;
            this.upgr1_intervalTimer = Main.mainClass.readXMLClass.ultraAddIceLevinIntervalXML;
            this.upgr1_intervalCounter = _loc_2;
            container = new Tower6_mc();
            container.stop();
            container.towerCase.stop();
            container.blockTower.stop();
            container.boneBlock.stop();
            container.shotAnima.stop();
            container.towerCase.buttonMode = true;
            container.blockTower.visible = false;
            container.boneBlock.visible = false;
            container.shotAnima.visible = false;
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
                if (world.frameCounter % 2)
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
                    tempObject = false;
                    i = 0;
                    while (i < world.listOfTowers.length)
                    {
                        
                        if (world.listOfTowers[i] is Tower6 && world.listOfTowers[i] != this)
                        {
                            if (world.listOfTowers[i].enemyTarget && world.listOfTowers[i].upgr1_intervalCounter == 0)
                            {
                                tempObject = true;
                                break;
                            }
                        }
                        var _loc_2:* = i + 1;
                        i = _loc_2;
                    }
                    if (!tempObject)
                    {
                        if (this.upgr1_intervalCounter < this.upgr1_intervalTimer)
                        {
                            (this.upgr1_intervalCounter + 1);
                        }
                        else if (world.frameCounter % 2)
                        {
                            this.addScan();
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

        public function addScan() : void
        {
            if (!enemyTarget)
            {
                tempObject1 = 0;
                tempObject2 = null;
                i = 0;
                while (i < world.listOfUnits.length)
                {
                    
                    if (world.listOfUnits[i].atStage && world.listOfUnits[i].readyDamage)
                    {
                        tempObject = world.listOfUnits[i].path / world.listOfUnits[i].finishPath;
                        if (tempObject > tempObject1)
                        {
                            tempObject1 = tempObject;
                            tempObject2 = world.listOfUnits[i];
                        }
                    }
                    var _loc_2:* = i + 1;
                    i = _loc_2;
                }
                if (tempObject1 > 0)
                {
                    enemyTarget = tempObject2;
                    this.upgr1_intervalCounter = 0;
                }
            }
            return;
        }// end function

        override public function attack() : void
        {
            if (intervalCounter == 0)
            {
                tempObject = world.addBullet(6, shoot_pt, this, enemyTarget, damage);
                intervalCounter = 1;
                enemyTarget = null;
                if (this.upgr1_intervalCounter == 0)
                {
                    this.scan();
                }
            }
            else if (this.upgr1_intervalCounter == 0)
            {
                if (!container.shotAnima.visible)
                {
                    container.shotAnima.visible = true;
                }
                else if (container.shotAnima.currentFrame < container.shotAnima.totalFrames)
                {
                    container.shotAnima.gotoAndStop((container.shotAnima.currentFrame + 1));
                    if (container.shotAnima.currentFrame == 32)
                    {
                        Sounds.instance.playSoundWithVol("snd_tower_firstShootUltraAdd1", 0.85);
                    }
                }
                else
                {
                    container.shotAnima.gotoAndStop(1);
                    container.shotAnima.visible = false;
                    this.upgr1_intervalCounter = 1;
                    enemyTarget = null;
                    this.addScan();
                    if (enemyTarget)
                    {
                        tempObject = world.bezierClass.getPathPoint(enemyTarget.path + enemyTarget.speedK * 4, enemyTarget.road, enemyTarget.way);
                        enemy_pt = new Point(tempObject.x, tempObject.y);
                        tempObject = world.addBullet(61, enemy_pt, this, enemy_pt, this.upgr1_damage);
                    }
                    else
                    {
                        this.upgr1_intervalCounter = this.upgr1_intervalTimer;
                    }
                    enemyTarget = null;
                }
            }
            return;
        }// end function

    }
}
