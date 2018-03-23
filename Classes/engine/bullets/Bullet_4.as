package engine.bullets
{
    import flash.events.*;

    public class Bullet_4 extends Bullet
    {
        public var deviation:Number = 6;
        public var effectFlag:Boolean = true;

        public function Bullet_4()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 4;
            var _loc_2:* = 10;
            liveTimer = 10;
            liveCounter = _loc_2;
            this.x = this_pt.x;
            this.y = this_pt.y;
            container = new BulletLevinTower_mc();
            container.stop();
            this.addChild(container);
            if (whoShoot is Tower)
            {
                (whoShoot.levinBulletCounter + 1);
                Sounds.instance.playSound("snd_tower_shootLevin");
            }
            super.init(event);
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
                    }
                    else
                    {
                        kill();
                    }
                }
                distanceX = enemyTarget.x - this_pt.x;
                distanceY = enemyTarget.y - this_pt.y;
                this.x = this.x + distanceX / (liveCounter - 3);
                this.y = this.y + distanceY / (liveCounter - 3);
                if (distanceY > 0)
                {
                    this.x = this.x + this.deviation;
                }
                else if (distanceY < 0)
                {
                    this.x = this.x - this.deviation;
                }
                this_pt = new Point(this.x, this.y);
                (liveCounter - 1);
            }
            else
            {
                if (enemyTarget.atStage && enemyTarget.readyDamage)
                {
                    if (this.effectFlag)
                    {
                        if (whoShoot.levinBulletCounter >= Main.mainClass.readXMLClass.listOfLevinProbability[(spherePower - 1)])
                        {
                            whoShoot.levinBulletCounter = 0;
                            enemyTarget.getHit(damage, "levin", spherePower, true, bulletType);
                        }
                        else
                        {
                            enemyTarget.getHit(damage, "levin", spherePower, false, bulletType);
                        }
                    }
                    else
                    {
                        enemyTarget.getHit(damage, "levin", spherePower, false, bulletType);
                    }
                }
                kill();
            }
            return;
        }// end function

    }
}
