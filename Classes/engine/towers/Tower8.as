package engine.towers
{
    import flash.events.*;

    public class Tower8 extends Tower
    {
        public var shootFlag:Boolean;
        public var upgr1_intervalCounter:int = 1;
        public var upgr1_intervalTimer:int;
        public var upgr1_damage:Number;
        public var soundCounter:int = 0;
        public var soundTimer:int = 5;

        public function Tower8()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            towerType = 8;
            slotsStack = [0, 0, 1, 1];
            correctYGrPos = -15;
            radius = Main.mainClass.readXMLClass.ultraFireLevinRadiusXML;
            damage = Main.mainClass.readXMLClass.ultraFireLevinDamageXML;
            var _loc_2:* = Main.mainClass.readXMLClass.ultraFireLevinIntervalXML;
            intervalTimer = Main.mainClass.readXMLClass.ultraFireLevinIntervalXML;
            intervalCounter = _loc_2;
            this.upgr1_damage = Main.mainClass.readXMLClass.ultraAddFireLevinDamageXML;
            var _loc_2:* = Main.mainClass.readXMLClass.ultraAddFireLevinIntervalXML;
            this.upgr1_intervalTimer = Main.mainClass.readXMLClass.ultraAddFireLevinIntervalXML;
            this.upgr1_intervalCounter = _loc_2;
            container = new Tower8_mc();
            container.stop();
            container.towerCase.stop();
            container.cont1.stop();
            container.cont2.stop();
            container.cont3.stop();
            container.cont4.stop();
            container.cont5.stop();
            container.cont6.stop();
            container.fireLight1.stop();
            container.blockTower.stop();
            container.boneBlock.stop();
            container.towerCase.buttonMode = true;
            container.cont4.visible = false;
            container.cont5.visible = false;
            container.cont6.visible = false;
            container.fireLight1.visible = false;
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
                if (world.frameCounter % 2)
                {
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
                container.cont2.rotation = container.cont2.rotation + 3;
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
                if (!this.shootFlag)
                {
                    this.shootFlag = true;
                    container.cont4.visible = true;
                    container.cont5.visible = true;
                    container.cont6.visible = true;
                }
                else
                {
                    if (container.cont4.visible)
                    {
                        if (container.cont4.currentFrame < container.cont4.totalFrames)
                        {
                            container.cont4.gotoAndStop((container.cont4.currentFrame + 1));
                        }
                        else
                        {
                            container.cont4.gotoAndStop(1);
                            container.cont4.visible = false;
                        }
                    }
                    if (container.cont5.visible)
                    {
                        if (container.cont5.currentFrame < container.cont5.totalFrames)
                        {
                            container.cont5.gotoAndStop((container.cont5.currentFrame + 1));
                        }
                        else
                        {
                            container.cont5.gotoAndStop(1);
                            container.cont5.visible = false;
                        }
                    }
                    if (container.cont6.visible)
                    {
                        if (container.cont6.currentFrame < container.cont6.totalFrames)
                        {
                            container.cont6.gotoAndStop((container.cont6.currentFrame + 1));
                            if (container.cont6.currentFrame == 21)
                            {
                                Sounds.instance.playSound("snd_tower_firstShootUltraAdd1");
                            }
                        }
                        else
                        {
                            container.cont6.gotoAndStop(1);
                            container.cont6.visible = false;
                        }
                    }
                    if (!container.cont4.visible && !container.cont5.visible && !container.cont6.visible)
                    {
                        this.shootFlag = false;
                        tempObject = world.bezierClass.getPathPoint(enemyTarget.path + enemyTarget.speedK * 30, enemyTarget.road, enemyTarget.way);
                        enemy_pt = new Point(tempObject.x, tempObject.y);
                        tempObject = world.addBullet(8, enemy_pt, this, enemy_pt, damage);
                        intervalCounter = 1;
                        enemyTarget = null;
                        if (this.upgr1_intervalCounter == 0)
                        {
                            this.scan();
                        }
                    }
                }
            }
            else if (this.upgr1_intervalCounter == 0)
            {
                if (!container.fireLight1.visible)
                {
                    container.fireLight1.visible = true;
                    container.fireLight1.gotoAndStop(1);
                }
                else if (container.fireLight1.currentFrame < container.fireLight1.totalFrames)
                {
                    container.fireLight1.gotoAndStop((container.fireLight1.currentFrame + 1));
                    if (container.fireLight1.currentFrame == 17)
                    {
                        if (!enemyTarget.dead)
                        {
                            tempObject = world.addBullet(81, shoot_pt, this, enemyTarget, this.upgr1_damage);
                        }
                    }
                    else if (container.fireLight1.currentFrame == 16)
                    {
                        if (enemyTarget.dead)
                        {
                            enemyTarget = null;
                            scanBlock();
                            if (!enemyTarget)
                            {
                                container.fireLight1.visible = false;
                                this.upgr1_intervalCounter = 1;
                            }
                        }
                    }
                }
                else
                {
                    container.fireLight1.visible = false;
                    this.upgr1_intervalCounter = 1;
                    enemyTarget = null;
                }
            }
            return;
        }// end function

    }
}
