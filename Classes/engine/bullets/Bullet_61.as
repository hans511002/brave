package engine.bullets
{
    import flash.events.*;

    public class Bullet_61 extends Bullet
    {

        public function Bullet_61()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 61;
            this.x = enemyTarget.x;
            this.y = enemyTarget.y;
            container = new BulletTower61_mc();
            container.stop();
            this.addChild(container);
            super.init(event);
            Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd2", 0.9);
            return;
        }// end function

        override public function update() : void
        {
            super.update();
            if (container.currentFrame < container.totalFrames)
            {
                container.gotoAndStop((container.currentFrame + 1));
                if (container.currentFrame == 4)
                {
                    i = world.listOfUnits.length - 1;
                    while (i >= 0)
                    {
                        
                        if (world.listOfUnits[i].atStage && world.listOfUnits[i].readyDamage && !world.listOfUnits[i].icemanFlag && !world.listOfUnits[i].teleportFlag)
                        {
                            if (Point.distance(this_pt, world.listOfUnits[i].shoot_pt) < Main.mainClass.readXMLClass.ultraAddIceLevinDamageRadiusXML)
                            {
                                tempObject = world.listOfUnits[i];
                                tempObject.getHit(damage / 2, "ice", 2, false, bulletType, whoShoot);
                                if (!tempObject.dead && tempObject.readyDamage)
                                {
                                    tempObject.getHit(damage / 2, "levin", 2, false, bulletType, whoShoot);
                                    if (tempObject.health > 0)
                                    {
                                        tempObject.icemanFlag = true;
                                    }
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
