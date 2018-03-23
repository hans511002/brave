package engine.bullets
{
    import flash.events.*;

    public class Bullet_8 extends Bullet
    {

        public function Bullet_8()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 8;
            this.x = enemyTarget.x;
            this.y = enemyTarget.y;
            container = new BulletTower8_1_mc();
            container.stop();
            this.addChild(container);
            tempObject = new Indexes(new BulletTower8_2_mc(), 0, 0);
            tempObject.x = enemyTarget.x;
            tempObject.y = enemyTarget.y;
            tempObject.container.gotoAndStop(2);
            super.init(event);
            return;
        }// end function

        override public function update() : void
        {
            super.update();
            if (container.currentFrame < container.totalFrames)
            {
                container.gotoAndStop((container.currentFrame + 1));
                if (container.currentFrame == 2 || container.currentFrame == 16 || container.currentFrame == 25)
                {
                    if (container.currentFrame == 2)
                    {
                        Sounds.instance.playSound("snd_tower_shootUltra4_1");
                    }
                    else if (container.currentFrame == 16)
                    {
                        Sounds.instance.playSound("snd_tower_shootUltra4_2");
                    }
                    else if (container.currentFrame == 25)
                    {
                        Sounds.instance.playSound("snd_tower_shootUltra4_3");
                    }
                    i = world.listOfUnits.length - 1;
                    while (i >= 0)
                    {
                        
                        if (world.listOfUnits[i].atStage && world.listOfUnits[i].readyDamage)
                        {
                            if (Point.distance(this_pt, world.listOfUnits[i].shoot_pt) < Main.mainClass.readXMLClass.ultraFireLevinDamageRadiusXML)
                            {
                                tempObject = world.listOfUnits[i];
                                if (tempObject.typeUnit != 23)
                                {
                                    tempObject.getHit(damage / 2, "fire", 2, true, bulletType, whoShoot);
                                }
                                else
                                {
                                    tempObject.getHit(damage / 2, "fire", 2, false, bulletType, whoShoot);
                                }
                                if (!tempObject.dead && tempObject.readyDamage)
                                {
                                    tempObject.getHit(damage / 2, "levin", 2, false, bulletType, whoShoot);
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
                kill();
            }
            return;
        }// end function

    }
}
