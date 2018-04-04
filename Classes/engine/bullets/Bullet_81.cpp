#ifndef ENGINE_BULLET_81_H
#define ENGINE_BULLET_81_H
#include "Bullet_81.h" 
#include "engine/World.h" 

namespace engine
{
    namespace bullets
    { 
        Bullet_81::Bullet_81()
        {
            return;
        }// end function

        bool Bullet_81::init()
        {
            bulletType = 81;
            this->setPosition(this_pt);
            //this->x = this_pt.x;
            //this->y = this_pt.y;
            container = new BulletTower81_mc();
            container->stop();
            container->myWidth = container->width;
            container->myHeight = container->height;
            this->addChild(container);
            enemyTarget->bulletTower6Effect = true;
            Bullet::init();
            //Sounds.instance.playSound("snd_tower_shootUltraAdd4");
            return true;
        }// end function

        void Bullet_81::update() 
        {
            Bullet::update();
            if (this->getPositionX() != this_pt.x && this->getPositionY() != this_pt.y)
            {
                this_pt = this->getPosition();// cocos2d::Point(this->x, this->y);
            }
            if (container->currentFrame < container->totalFrames && enemyTarget->readyDamage)
            {
                container->gotoAndStop((container->currentFrame + 1));
                this->cathetus1 = enemyTarget->shoot_pt.x - this_pt.x;
                this->cathetus2 = enemyTarget->shoot_pt.y - this_pt.y;
                this->hypotenuse = this_pt.distance(enemyTarget->shoot_pt);
                this->angleAlpha = std::atan2(this->cathetus2, this->cathetus1) * (180 / std::PI) - 90;
                //this->rotation = this->angleAlpha;
                float tempObject = this->hypotenuse / container->myHeight;
                tempObject = (this->hypotenuse + 35 * tempObject) / container->myHeight;
                container->setScale(tempObject); 
                if (container->currentFrame == 4)
                {
                    if (enemyTarget->atStage() && enemyTarget->readyDamage)
                    {
                        if (enemyTarget->typeUnit != 23)
                        {
                            enemyTarget->getHit(damage / 2, "fire", 2, true, bulletType, whoShoot);
                        }
                        else
                        {
                            enemyTarget->getHit(damage / 2, "fire", 2, false, bulletType, whoShoot);
                        }
                        if (!enemyTarget->dead && enemyTarget->readyDamage)
                        {
                            enemyTarget->getHit(damage / 2, "levin", 2, false, bulletType, whoShoot);
                        }
                        if (enemyTarget->dead)
                        {
                            enemyTarget->fireLevinKillFlag = true;
                        }
                    }
                }
            }
            else
            {
                enemyTarget->bulletTower6Effect = false;
                kill();
            }
            return;
        }// end function
    }
}
#endif
