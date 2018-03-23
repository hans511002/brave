package engine.bullets
{
    import flash.events.*;

    public class Bullet_6 extends Bullet
    {
        public var damageLittle:Number;
        public var hypotenuse:Number;
        public var cathetus1:Number;
        public var cathetus2:Number;
        public var angleAlpha:Number;
        public var chainTarget:Object;
        public var long:int = 0;
        public var unitsCout:int = 1;

        public function Bullet_6()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 6;
            this.x = this_pt.x;
            this.y = this_pt.y;
            if (whoShoot is Tower)
            {
                container = new BulletTower6_1_mc();
            }
            else
            {
                container = new BulletTower6_2_mc();
            }
            container.stop();
            this.addChild(container);
            enemyTarget.bulletTower6Effect = true;
            this.long = Point.distance(this_pt, enemyTarget.shoot_pt);
            this.damageLittle = damage / container.totalFrames;
            super.init(event);
            this.attack();
            Sounds.instance.playSoundWithVol("snd_tower_shootUltra2", 0.85);
            return;
        }// end function

        override public function update() : void
        {
            super.update();
            if (this.x != this_pt.x && this.y != this_pt.y)
            {
                this_pt = new Point(this.x, this.y);
            }
            if (container.currentFrame < container.totalFrames)
            {
                container.gotoAndStop((container.currentFrame + 1));
                this.cathetus1 = enemyTarget.shoot_pt.x - this_pt.x;
                this.cathetus2 = enemyTarget.shoot_pt.y - this_pt.y;
                this.hypotenuse = Point.distance(this_pt, enemyTarget.shoot_pt);
                this.angleAlpha = Math.atan2(this.cathetus2, this.cathetus1) * (180 / Math.PI) - 90;
                container.rotation = this.angleAlpha;
                if (container.width > container.height)
                {
                    container.width = this.hypotenuse;
                    container.scaleY = container.scaleX;
                }
                else
                {
                    container.height = this.hypotenuse;
                    container.scaleX = container.scaleY;
                }
                if (!this.chainTarget)
                {
                    tempObject = 1000;
                    i = world.listOfUnits.length - 1;
                    while (i >= 0)
                    {
                        
                        if (!world.listOfUnits[i].bulletTower6Effect && world.listOfUnits[i].readyDamage && world.listOfUnits[i].atStage)
                        {
                            tempObject1 = Point.distance(world.listOfUnits[i].shoot_pt, enemyTarget.shoot_pt);
                            if (tempObject > tempObject1)
                            {
                                tempObject = tempObject1;
                                tempObject2 = world.listOfUnits[i];
                            }
                        }
                        var _loc_2:* = i - 1;
                        i = _loc_2;
                    }
                    if (tempObject < 1000 && this.unitsCout < Main.mainClass.readXMLClass.ultraIceLevinMaxUnitsXML)
                    {
                        this.chainTarget = tempObject2;
                        if (this.long + tempObject < Main.mainClass.readXMLClass.ultraIceLevinLongXML)
                        {
                            tempObject2.bulletTower6Effect = true;
                            tempObject = world.addBullet(6, enemyTarget.shoot_pt, enemyTarget, tempObject2, damage);
                            tempObject.long = tempObject.long + this.long;
                            tempObject.unitsCout = this.unitsCout + 1;
                        }
                    }
                }
                if (enemyTarget.airFlag)
                {
                    this.close();
                }
                else if (whoShoot is Unit)
                {
                    if (whoShoot.airFlag)
                    {
                        this.close();
                    }
                }
                this.attack();
            }
            else
            {
                this.close();
            }
            return;
        }// end function

        public function attack() : void
        {
            if (enemyTarget.atStage && enemyTarget.readyDamage)
            {
                if (enemyTarget.getHit != 24)
                {
                    enemyTarget.getHit(this.damageLittle / 2, "ice", 2, true, bulletType, whoShoot);
                }
                else
                {
                    enemyTarget.getHit(this.damageLittle / 2, "ice", 2, false, bulletType, whoShoot);
                }
                if (!enemyTarget.dead && enemyTarget.readyDamage)
                {
                    if (!enemyTarget.icemanFlag)
                    {
                        enemyTarget.iceEffectSlowdown = enemyTarget.speedKSave * Main.mainClass.readXMLClass.ultraIceLevinSlowdownPowerXML;
                        enemyTarget.iceEffectCounter = Main.mainClass.readXMLClass.ultraIceLevinSlowdownTimerXML;
                    }
                    enemyTarget.getHit(this.damageLittle / 2, "levin", 2, false, bulletType, whoShoot);
                }
            }
            return;
        }// end function

        public function close() : void
        {
            enemyTarget.bulletTower6Effect = false;
            if (this.chainTarget)
            {
                this.chainTarget.bulletTower6Effect = false;
            }
            kill();
            return;
        }// end function

    }
}
