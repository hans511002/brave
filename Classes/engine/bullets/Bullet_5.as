package engine.bullets
{
    import flash.events.*;
    import flash.geom.*;

    public class Bullet_5 extends Bullet
    {
        public var correct:Number;
        public var rotationFlag:Boolean;
        public var enemyStartPoint:Point;
        public var enemyRoad:int;
        public var enemyWay:int;
        public var enemyPath:Number;
        public var enemySpeed:Number;
        public var shadow:UnitShadow_mc;

        public function Bullet_5()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 5;
            var _loc_2:* = 30;
            liveTimer = 30;
            liveCounter = _loc_2;
            this.x = this_pt.x;
            this.y = this_pt.y;
            this.correct = int(liveTimer / 6);
            container = new BulletTower5_1_mc();
            container.stop();
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
                this.enemySpeed = enemyTarget.speedK;
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
            if (container.currentFrame < container.totalFrames)
            {
                container.gotoAndStop((container.currentFrame + 1));
            }
            else
            {
                container.gotoAndStop(1);
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
                if (liveCounter > this.correct)
                {
                    this.x = this.x + distanceX / (liveCounter - this.correct);
                    this.y = this.y + (distanceY / (liveCounter - this.correct) - 8);
                    this.shadow.x = this.shadow.x + (this.enemyStartPoint.x - this.shadow.x) / (liveCounter - this.correct);
                    this.shadow.y = this.shadow.y + (this.enemyStartPoint.y - this.shadow.y) / (liveCounter - this.correct);
                    if (!this.rotationFlag)
                    {
                        container.rotation = container.rotation - 7;
                        if (container.ball)
                        {
                            container.ball.rotation = container.ball.rotation - 7;
                        }
                    }
                    else
                    {
                        container.rotation = container.rotation + 7;
                        if (container.ball)
                        {
                            container.ball.rotation = container.ball.rotation + 7;
                        }
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
                        tempObject = new Indexes(new BulletTower5_1Bang_mc(), 2);
                        Sounds.instance.playSound("snd_tower_shootUltra1_2");
                        tempObject.x = this_pt.x;
                        tempObject.y = this_pt.y;
                        i = world.listOfUnits.length - 1;
                        while (i >= 0)
                        {
                            
                            if (world.listOfUnits[i].atStage && world.listOfUnits[i].readyDamage)
                            {
                                if (Point.distance(this_pt, world.listOfUnits[i].shoot_pt) < Main.mainClass.readXMLClass.ultraFireStoneDamageRadiusXML)
                                {
                                    tempObject = world.listOfUnits[i];
                                    if (tempObject.typeUnit != 23)
                                    {
                                        tempObject.getHit(damage / 2, "fire", 2, true, bulletType, whoShoot);
                                    }
                                    else
                                    {
                                        tempObject.getHit(damage, "fire", 2, false, bulletType, whoShoot);
                                    }
                                    if (!tempObject.dead && tempObject.readyDamage)
                                    {
                                        if (tempObject.typeUnit != 25)
                                        {
                                            tempObject.getHit(damage / 2, "stone", 2, true, bulletType, whoShoot);
                                        }
                                        else
                                        {
                                            tempObject.getHit(damage, "stone", 2, false, bulletType, whoShoot);
                                        }
                                    }
                                }
                            }
                            var _loc_2:* = i - 1;
                            i = _loc_2;
                        }
                        this.kill();
                    }
                }
                if (liveCounter > 15)
                {
                    container.scaleX = container.scaleX + 0.01;
                    container.scaleY = container.scaleY + 0.01;
                }
                else
                {
                    container.scaleX = container.scaleX - 0.0105;
                    container.scaleY = container.scaleY - 0.0105;
                }
                tempObject = new Indexes(new BulletTower5_1Smoke1_mc(), 3, 0.18);
                tempObject.container.rotation = container.rotation;
                tempObject.x = this_pt.x;
                tempObject.y = this_pt.y;
                (liveCounter - 1);
            }
            else
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
