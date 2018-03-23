﻿package engine.bullets
{
    import flash.events.*;
    import flash.geom.*;

    public class Bullet_3 extends Bullet
    {
        public var correct:Number;
        public var enemyStartPoint:Point;
        public var enemyRoad:int;
        public var enemyWay:int;
        public var enemyPath:Number;
        public var enemySpeed:Number;
        public var shadow:UnitShadow_mc;

        public function Bullet_3()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 3;
            var _loc_2:* = 24;
            liveTimer = 24;
            liveCounter = _loc_2;
            this.correct = liveCounter / 12;
            this.x = this_pt.x;
            this.y = this_pt.y;
            container = new BulletStoneTower_mc();
            container.stop();
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
                    this.enemySpeed = enemyTarget.speedK * 0.5;
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
            return;
        }// end function

        override public function update() : void
        {
            super.update();
            if (mainCounter == 11)
            {
                Sounds.instance.playSoundWithVol("snd_tower_shootStone", 0.8);
            }
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
                    this.y = this.y + (distanceY / (liveCounter - this.correct) - 12);
                    this.shadow.x = this.shadow.x + (this.enemyStartPoint.x - this.shadow.x) / (liveCounter - this.correct);
                    this.shadow.y = this.shadow.y + (this.enemyStartPoint.y - this.shadow.y) / (liveCounter - this.correct);
                }
                else
                {
                    this.x = this.x + distanceX / liveCounter;
                    this.y = this.y + distanceY / liveCounter;
                    this.shadow.x = this.shadow.x + (this.enemyStartPoint.x - this.shadow.x) / liveCounter;
                    this.shadow.y = this.shadow.y + (this.enemyStartPoint.y - this.shadow.y) / liveCounter;
                }
                this_pt = new Point(this.x, this.y);
                (liveCounter - 1);
            }
            else
            {
                tempObject = new Indexes(new CastStone_mc(), 2);
                var _loc_1:* = 0.5;
                tempObject.container.scaleY = 0.5;
                tempObject.container.scaleX = _loc_1;
                tempObject.x = this_pt.x;
                tempObject.y = this_pt.y;
                i = world.listOfUnits.length - 1;
                while (i >= 0)
                {
                    
                    if (world.listOfUnits[i].atStage && world.listOfUnits[i].readyDamage)
                    {
                        if (Point.distance(this_pt, world.listOfUnits[i].shoot_pt) < Main.mainClass.readXMLClass.stoneEffectRadiusXML)
                        {
                            tempObject = world.listOfUnits[i];
                            tempObject.getHit(damage, "stone", spherePower, true, bulletType);
                        }
                    }
                    var _loc_2:* = i - 1;
                    i = _loc_2;
                }
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
