package engine.bullets
{
    import flash.events.*;
    import flash.geom.*;

    public class Bullet_7 extends Bullet
    {
        public var rotationFlag:Boolean;
        public var enemyStartPoint:Point;
        public var enemyRoad:int;
        public var enemyWay:int;
        public var enemyPath:Number;
        public var enemySpeed:Number;
        public var shadow:UnitShadow_mc;

        public function Bullet_7()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 7;
            var _loc_2:* = 30;
            liveTimer = 30;
            liveCounter = _loc_2;
            this.x = this_pt.x;
            this.y = this_pt.y;
            correct = int(liveTimer / 6);
            container = new BulletTower7_mc();
            container.stop();
            container.ball.stop();
            container.smoke.stop();
            container.smoke.cont1.stop();
            container.smoke.cont2.stop();
            container.rotation = 180;
            this.addChild(container);
            testTower = whoShoot;
            radius = whoShoot.radius;
            super.init(event);
            this.enemyStartPoint = enemyTarget.this_pt;
            this.enemyRoad = enemyTarget.road;
            this.enemyWay = enemyTarget.way;
            this.enemyPath = enemyTarget.path;
            if (enemyTarget.speedK > 0 || enemyTarget.typeUnit == 34)
            {
                if (enemyTarget.typeUnit != 3 && enemyTarget.typeUnit != 8 && enemyTarget.typeUnit != 13)
                {
                    this.enemySpeed = enemyTarget.speedK * 0.95;
                }
                else
                {
                    this.enemySpeed = enemyTarget.speedK;
                }
            }
            else
            {
                this.enemySpeed = 0.1;
            }
            tempObject = world.bezierClass.getPathPoint(this.enemyPath + this.enemySpeed * liveTimer, this.enemyRoad, this.enemyWay);
            if (this.x > tempObject.x)
            {
                this.rotationFlag = false;
            }
            else
            {
                this.rotationFlag = true;
            }
            this.shadow = new UnitShadow_mc();
            this.shadow.stop();
            var _loc_2:* = false;
            this.shadow.mouseChildren = false;
            this.shadow.mouseEnabled = _loc_2;
            this.shadow.x = this_pt.x;
            this.shadow.y = whoShoot.y;
            var _loc_2:* = 0.5;
            this.shadow.scaleY = 0.5;
            this.shadow.scaleX = _loc_2;
            world.addChildAt(this.shadow, 2);
            world.listOfIndexes2.push(this.shadow);
            Sounds.instance.playSound("snd_tower_shootUltra1_1");
            return;
        }// end function

        override public function update() : void
        {
            super.update();
            if (container.smoke)
            {
                if (container.smoke.visible)
                {
                    if (container.smoke.cont1.currentFrame < container.smoke.cont1.totalFrames)
                    {
                        container.smoke.cont1.gotoAndStop((container.smoke.cont1.currentFrame + 1));
                    }
                    else
                    {
                        container.smoke.cont1.gotoAndStop(1);
                    }
                    if (container.smoke.cont2.currentFrame < container.smoke.cont2.totalFrames)
                    {
                        container.smoke.cont2.gotoAndStop((container.smoke.cont2.currentFrame + 1));
                    }
                    else
                    {
                        container.smoke.cont2.gotoAndStop(1);
                    }
                    if (world.frameCounter % 2)
                    {
                        tempObject1 = container.smoke.localToGlobal(new Point(container.smoke.cont2.x, container.smoke.cont2.y));
                        tempObject = new Indexes(new BulletTower7_smoke_mc(), 2, 0);
                        tempObject.x = tempObject1.x;
                        tempObject.y = tempObject1.y;
                        tempObject.container.rotation = container.rotation;
                    }
                }
            }
            if (container.currentFrame > 1)
            {
                if (container.currentFrame < container.totalFrames)
                {
                    container.gotoAndStop((container.currentFrame + 1));
                }
            }
            if (liveCounter > 0)
            {
                distanceX = this.enemyStartPoint.x - this_pt.x;
                distanceY = this.enemyStartPoint.y - this_pt.y;
                testTarget = this.enemyStartPoint;
                scanAtRadius();
                if (greenFlag)
                {
                    this.enemyPath = this.enemyPath + this.enemySpeed;
                }
                tempObject = world.bezierClass.getPathPoint(this.enemyPath, this.enemyRoad, this.enemyWay);
                this.enemyStartPoint = new Point(tempObject.x, tempObject.y);
                if (liveCounter > correct)
                {
                    this.x = this.x + distanceX / (liveCounter - correct);
                    this.y = this.y + (distanceY / (liveCounter - correct) - 8);
                    this.shadow.x = this.shadow.x + (this.enemyStartPoint.x - this.shadow.x) / (liveCounter - correct);
                    this.shadow.y = this.shadow.y + (this.enemyStartPoint.y - this.shadow.y) / (liveCounter - correct);
                    if (!this.rotationFlag)
                    {
                        container.rotation = container.rotation - 6;
                    }
                    else
                    {
                        container.rotation = container.rotation + 6;
                    }
                    this_pt = new Point(this.x, this.y);
                }
                else
                {
                    this.x = this.x + distanceX / (liveCounter * 10);
                    this.y = this.y + distanceY / (liveCounter * 10);
                    this.shadow.x = this.shadow.x + (this.enemyStartPoint.x - this.shadow.x) / (liveCounter * 10);
                    this.shadow.y = this.shadow.y + (this.enemyStartPoint.y - this.shadow.y) / (liveCounter * 10);
                    if (liveCounter == 4)
                    {
                        Sounds.instance.playSound("snd_tower_shootUltra3");
                        container.gotoAndStop(2);
                        this.shadow.visible = false;
                        i = world.listOfUnits.length - 1;
                        while (i >= 0)
                        {
                            
                            if (world.listOfUnits[i].atStage && world.listOfUnits[i].readyDamage)
                            {
                                if (Point.distance(this_pt, world.listOfUnits[i].shoot_pt) < Main.mainClass.readXMLClass.ultraIceStoneDamageRadiusXML)
                                {
                                    tempObject = world.listOfUnits[i];
                                    if (tempObject.typeUnit != 24)
                                    {
                                        tempObject.getHit(damage / 2, "ice", 2, true, bulletType, whoShoot);
                                    }
                                    else
                                    {
                                        tempObject.getHit(damage / 2, "ice", 2, false, bulletType, whoShoot);
                                    }
                                    if (!tempObject.dead && tempObject.readyDamage)
                                    {
                                        if (!enemyTarget.icemanFlag)
                                        {
                                            enemyTarget.iceEffectSlowdown = enemyTarget.speedKSave * Main.mainClass.readXMLClass.ultraIceStoneSlowdownPowerXML;
                                            enemyTarget.iceEffectCounter = Main.mainClass.readXMLClass.ultraIceStoneSlowdownTimerXML;
                                        }
                                        if (tempObject.typeUnit != 25)
                                        {
                                            tempObject.getHit(damage / 2, "stone", 2, true, bulletType, whoShoot);
                                        }
                                        else
                                        {
                                            tempObject.getHit(damage / 2, "stone", 2, false, bulletType, whoShoot);
                                        }
                                    }
                                }
                            }
                            var _loc_2:* = i - 1;
                            i = _loc_2;
                        }
                    }
                }
                (liveCounter - 1);
            }
            else if (container.currentFrame == container.totalFrames)
            {
                this.kill();
            }
            return;
        }// end function

        override public function kill() : void
        {
            if (this.shadow)
            {
                world.removeChild(this.shadow);
                i = 0;
                while (i < world.listOfIndexes2.length)
                {
                    
                    if (world.listOfIndexes2[i] == this.shadow)
                    {
                        world.listOfIndexes2.splice(i, 1);
                        break;
                    }
                    var _loc_2:* = i + 1;
                    i = _loc_2;
                }
                this.shadow = null;
            }
            super.kill();
            return;
        }// end function

    }
}
