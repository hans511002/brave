package engine.bullets
{
    import flash.events.*;

    public class Bullet_81 extends Bullet
    {
        public var hypotenuse:Number;
        public var cathetus1:Number;
        public var cathetus2:Number;
        public var angleAlpha:Number;
        public var chainTarget:Object;

        public function Bullet_81()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            bulletType = 81;
            this.x = this_pt.x;
            this.y = this_pt.y;
            container = new BulletTower81_mc();
            container.stop();
            container.myWidth = container.width;
            container.myHeight = container.height;
            this.addChild(container);
            enemyTarget.bulletTower6Effect = true;
            super.init(event);
            Sounds.instance.playSound("snd_tower_shootUltraAdd4");
            return;
        }// end function

        override public function update() : void
        {
            super.update();
            if (this.x != this_pt.x && this.y != this_pt.y)
            {
                this_pt = new Point(this.x, this.y);
            }
            if (container.currentFrame < container.totalFrames && enemyTarget.readyDamage)
            {
                container.gotoAndStop((container.currentFrame + 1));
                this.cathetus1 = enemyTarget.shoot_pt.x - this_pt.x;
                this.cathetus2 = enemyTarget.shoot_pt.y - this_pt.y;
                this.hypotenuse = Point.distance(this_pt, enemyTarget.shoot_pt);
                this.angleAlpha = Math.atan2(this.cathetus2, this.cathetus1) * (180 / Math.PI) - 90;
                this.rotation = this.angleAlpha;
                tempObject = this.hypotenuse / container.myHeight;
                tempObject = (this.hypotenuse + 35 * tempObject) / container.myHeight;
                var _loc_1:* = tempObject;
                container.scaleY = tempObject;
                container.scaleX = _loc_1;
                if (container.currentFrame == 4)
                {
                    if (enemyTarget.atStage && enemyTarget.readyDamage)
                    {
                        if (enemyTarget.typeUnit != 23)
                        {
                            enemyTarget.getHit(damage / 2, "fire", 2, true, bulletType, whoShoot);
                        }
                        else
                        {
                            enemyTarget.getHit(damage / 2, "fire", 2, false, bulletType, whoShoot);
                        }
                        if (!enemyTarget.dead && enemyTarget.readyDamage)
                        {
                            enemyTarget.getHit(damage / 2, "levin", 2, false, bulletType, whoShoot);
                        }
                        if (enemyTarget.dead)
                        {
                            enemyTarget.fireLevinKillFlag = true;
                        }
                    }
                }
            }
            else
            {
                enemyTarget.bulletTower6Effect = false;
                kill();
            }
            return;
        }// end function

    }
}
