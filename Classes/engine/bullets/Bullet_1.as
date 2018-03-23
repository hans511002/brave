package engine.bullets
{
    import flash.events.*;

    public class Bullet_1 extends Bullet
    {
        public var shiftX:Number;
        public var shiftY:Number;
        public var phase1:int;
        public var phase2:int;

        public function Bullet_1()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 1;
            var _loc_2:* = 18;
            liveTimer = 18;
            liveCounter = _loc_2;
            this.x = this_pt.x;
            this.y = this_pt.y;
            this.shiftX = 1;
            this.shiftY = 1;
            this.phase1 = 4;
            this.phase2 = 10;
            container = new BulletFireTower_mc();
            container.stop();
            this.addChild(container);
            (whoShoot.fireBulletCounter + 1);
            super.init(event);
            changeIndex = 16;
            return;
        }// end function

        override public function update() : void
        {
            super.update();
            if (mainCounter == 7)
            {
                Sounds.instance.playSound("snd_tower_shootFire");
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
                if (enemyTarget.dead)
                {
                    tempObject1 = null;
                    i = 0;
                    while (i < world.listOfUnits.length)
                    {
                        
                        tempObject = Point.distance(this_pt, world.listOfUnits[i].shoot_pt);
                        if (tempObject < 50)
                        {
                            if (!tempObject1)
                            {
                                tempObject1 = world.listOfUnits[i];
                            }
                            else if (Point.distance(this_pt, tempObject1.shoot_pt) > tempObject)
                            {
                                tempObject1 = world.listOfUnits[i];
                            }
                        }
                        var _loc_2:* = i + 1;
                        i = _loc_2;
                    }
                    if (tempObject1)
                    {
                        enemyTarget = tempObject1;
                        this.phase1 = 0;
                        this.phase2 = 0;
                    }
                    else
                    {
                        kill();
                    }
                }
                distanceX = enemyTarget.shoot_pt.x - this_pt.x;
                distanceY = enemyTarget.shoot_pt.y - this_pt.y;
                if (this.phase1 > 0)
                {
                    (this.phase1 - 1);
                    this.x = this.x - distanceX / 20;
                    this.y = this.y - distanceY / 20;
                }
                else if (this.phase2 > 0)
                {
                    (this.phase2 - 1);
                    if (distanceX > 0)
                    {
                        this.x = this.x + this.shiftX;
                    }
                    else
                    {
                        this.x = this.x - this.shiftX;
                    }
                    if (distanceY > 0)
                    {
                        this.y = this.y - this.shiftY;
                    }
                    else
                    {
                        this.y = this.y + this.shiftY;
                    }
                    if (liveCounter < int(liveTimer / 2))
                    {
                        this.shiftX = this.shiftX - 0.08;
                        this.shiftY = this.shiftY + 0.08;
                    }
                    else
                    {
                        this.shiftX = this.shiftX + 0.08;
                        this.shiftY = this.shiftY - 0.08;
                    }
                }
                else
                {
                    this.x = this.x + distanceX / liveCounter;
                    this.y = this.y + distanceY / liveCounter;
                }
                this_pt = new Point(this.x, this.y);
                (liveCounter - 1);
            }
            else
            {
                if (enemyTarget.atStage && enemyTarget.readyDamage)
                {
                    if (whoShoot.fireBulletCounter >= Main.mainClass.readXMLClass.listOfFireProbability[(spherePower - 1)])
                    {
                        whoShoot.fireBulletCounter = 0;
                        enemyTarget.getHit(damage, "fire", spherePower, true, bulletType);
                    }
                    else
                    {
                        enemyTarget.getHit(damage, "fire", spherePower, false, bulletType);
                    }
                }
                kill();
            }
            return;
        }// end function

    }
}
