package engine.bullets
{
    import flash.events.*;

    public class Bullet_2 extends Bullet
    {

        public function Bullet_2()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 2;
            var _loc_2:* = 6;
            liveTimer = 6;
            liveCounter = _loc_2;
            this.x = this_pt.x;
            this.y = this_pt.y;
            container = new BulletIceTower_mc();
            container.stop();
            this.addChild(container);
            (whoShoot.iceBulletCounter + 1);
            super.init(event);
            Sounds.instance.playSoundWithVol("snd_tower_shootIce", 0.83);
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
                this.x = this.x + distanceX / liveCounter;
                this.y = this.y + distanceY / liveCounter;
                this_pt = new Point(this.x, this.y);
                (liveCounter - 1);
            }
            else
            {
                if (enemyTarget.atStage && enemyTarget.readyDamage)
                {
                    if (whoShoot.iceBulletCounter >= Main.mainClass.readXMLClass.listOfIceProbability[(spherePower - 1)])
                    {
                        whoShoot.iceBulletCounter = 0;
                        enemyTarget.getHit(damage, "ice", spherePower, true, bulletType);
                    }
                    else
                    {
                        enemyTarget.getHit(damage, "ice", spherePower, false, bulletType);
                    }
                }
                kill();
            }
            return;
        }// end function

    }
}
