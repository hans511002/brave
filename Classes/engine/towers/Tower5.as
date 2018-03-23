package engine.towers
{
    import flash.events.*;

    public class Tower5 extends Tower
    {
        public var upgr1_intervalCounter:int;
        public var upgr1_intervalTimer:int;
        public var upgr1_damage:Number;
        public var soundCounter:int = 0;
        public var soundTimer:int = 5;

        public function Tower5()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            towerType = 5;
            slotsStack = [0, 0, 1, 1];
            correctYGrPos = -30;
            radius = Main.mainClass.readXMLClass.ultraFireStoneRadiusXML;
            damage = Main.mainClass.readXMLClass.ultraFireStoneDamageXML;
            var _loc_2:* = Main.mainClass.readXMLClass.ultraFireStoneIntervalXML;
            intervalTimer = Main.mainClass.readXMLClass.ultraFireStoneIntervalXML;
            intervalCounter = _loc_2;
            this.upgr1_damage = Main.mainClass.readXMLClass.ultraAddFireStoneDamageXML;
            var _loc_2:* = Main.mainClass.readXMLClass.ultraAddFireStoneIntervalXML;
            this.upgr1_intervalTimer = Main.mainClass.readXMLClass.ultraAddFireStoneIntervalXML;
            this.upgr1_intervalCounter = _loc_2;
            container = new Tower5_mc();
            container.stop();
            container.towerCase.stop();
            container.upgr1.stop();
            container.blockTower.stop();
            container.boneBlock.stop();
            container.towerCase.buttonMode = true;
            container.upgr1.visible = false;
            container.blockTower.visible = false;
            container.boneBlock.visible = false;
            this.addChild(container);
            super.init(event);
            if (world.levelType == "grass")
            {
                if (world.nowLevel == 7)
                {
                    if (myPlace.name == "place8")
                    {
                        container.bot.gotoAndStop(2);
                    }
                    else if (myPlace.name == "place9")
                    {
                        container.bot.gotoAndStop(2);
                    }
                    else if (myPlace.name == "place10")
                    {
                        container.bot.gotoAndStop(2);
                    }
                    else
                    {
                        container.bot.gotoAndStop(1);
                    }
                }
                else
                {
                    container.bot.gotoAndStop(1);
                }
            }
            else if (world.levelType == "dust")
            {
                container.bot.gotoAndStop(2);
            }
            if (!autoBuild)
            {
                container.visible = false;
            }
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
                    Sounds.instance.playSoundWithVol("snd_tower_buildUltra", 0.8);
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
                    if (this.upgr1_intervalCounter < this.upgr1_intervalTimer)
                    {
                        (this.upgr1_intervalCounter + 1);
                    }
                    else if (world.frameCounter % 2)
                    {
                        if (!enemyTarget)
                        {
                            scanBlock();
                            if (enemyTarget)
                            {
                                this.upgr1_intervalCounter = 0;
                            }
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
                tempObject = world.addBullet(5, shoot_pt, this, enemyTarget, damage);
                intervalCounter = 1;
                enemyTarget = null;
                if (this.upgr1_intervalCounter == 0)
                {
                    this.scan();
                }
            }
            else if (this.upgr1_intervalCounter == 0)
            {
                if (!container.upgr1.visible)
                {
                    container.upgr1.visible = true;
                    Sounds.instance.playSound("snd_tower_firstShootUltraAdd1");
                }
                else if (container.upgr1.currentFrame < container.upgr1.totalFrames)
                {
                    container.upgr1.gotoAndStop((container.upgr1.currentFrame + 1));
                    if (container.upgr1.currentFrame == 4)
                    {
                        tempObject = new Indexes(new ShotTower51_2_mc(), 3);
                        tempObject.x = this.x - 8;
                        tempObject.y = this.y - 255;
                    }
                }
                else
                {
                    container.upgr1.gotoAndStop(1);
                    container.upgr1.visible = false;
                    tempObject = world.bezierClass.getPathPoint(enemyTarget.path + enemyTarget.speedK * 30, enemyTarget.road, enemyTarget.way);
                    enemy_pt = new Point(tempObject.x, tempObject.y);
                    tempObject = world.addBullet(51, enemy_pt, this, enemy_pt, this.upgr1_damage);
                    this.upgr1_intervalCounter = 1;
                    enemyTarget = null;
                }
            }
            return;
        }// end function

    }
}
