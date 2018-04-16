
#include "Bullet_6.h" 
#include "engine/World.h" 
#include "engine/units/Unit.h"

namespace engine
{
    namespace bullets
    {  
        Bullet_6::Bullet_6():length(0),unitsCout(1)
        {
            return;
        }// end function

        bool init()
        {
            bulletType = 6;
            this->setPosition(this_pt);
            if (whoShoot is Tower)
            {
                container = new BulletTower6_1_mc();
            }
            else
            {
                container = new BulletTower6_2_mc();
            }
            container->stop();
            this->addChild(container);
            enemyTarget->bulletTower6Effect = true;
            this->length = this_pt.distance(enemyTarget->shoot_pt);
            this->damageLittle = damage / container->totalFrames;
            Bullet::init();
            this->attack();
            //Sounds.instance.playSoundWithVol("snd_tower_shootUltra2", 0.85);
            return;
        }// end function

        void Bullet_6::update() 
        {
            Bullet::update();
            if (this->getPositionX() != this_pt.x && this->getPositionY() != this_pt.y)
            {
                this_pt =this->getPosition();// cocos2d::Point(this->x, this->y);
            }
            if (container->currentFrame < container->totalFrames)
            {
                container->gotoAndStop((container->currentFrame + 1));
                this->cathetus1 = enemyTarget->shoot_pt.x - this_pt.x;
                this->cathetus2 = enemyTarget->shoot_pt.y - this_pt.y;
                this->hypotenuse = this_pt.distance(enemyTarget->shoot_pt);
                this->angleAlpha = std::atan2(this->cathetus2, this->cathetus1) * (180 / std::PI) - 90;
                //container->rotation = this->angleAlpha;
                if (container->width > container->height)
                {
                    container->width = this->hypotenuse;
                    container->setScaleY(container->getScaleX());
                }
                else
                {
                    container->height = this->hypotenuse;
                    container->setScaleX(container->getScaleY());
                }
                if (!this->chainTarget)
                {
                    Unit * tempObject2=NULL;
                    float tempObject = 1000;
                    i = world->listOfUnits.size()- 1;
                    while (i >= 0)
                    { 
                        if (!world->listOfUnits[i]->bulletTower6Effect && world->listOfUnits[i]->readyDamage && world->listOfUnits[i]->atStage())
                        {
                            float tempObject1 = world->listOfUnits[i]->shoot_pt.distance(enemyTarget->shoot_pt);
                            if (tempObject > tempObject1)
                            {
                                tempObject = tempObject1;
                                tempObject2 = world->listOfUnits[i];
                            }
                        }
                        i--;
                    }
                    if (tempObject < 1000 && this->unitsCout < Main::mainClass->readXMLClass.ultraIceLevinMaxUnitsXML)
                    {
                        this->chainTarget = tempObject2;
                        if (this->length + tempObject < Main::mainClass->readXMLClass.ultraIceLevinLongXML)
                        {
                            tempObject2->bulletTower6Effect = true;
                            Bullet * tempObject = world->addBullet(6, enemyTarget->shoot_pt, enemyTarget, tempObject2, damage);
                            tempObject->length = tempObject->length + this->length;
                            tempObject->unitsCout = this->unitsCout + 1;
                        }
                    }
                }
                if (enemyTarget->airFlag)
                {
                    this->close();
                }
                else if (whoShoot is Unit)
                {
                    if (whoShoot->airFlag)
                    {
                        this->close();
                    }
                }
                this->attack();
            }
            else
            {
                this->close();
            }
            return;
        }// end function

        void attack() 
        {
            if (enemyTarget->atStage() && enemyTarget->readyDamage)
            {
                if (enemyTarget->getHit != 24)
                {
                    enemyTarget->getHit(this->damageLittle / 2, "ice", 2, true, bulletType, whoShoot);
                }
                else
                {
                    enemyTarget->getHit(this->damageLittle / 2, "ice", 2, false, bulletType, whoShoot);
                }
                if (!enemyTarget->dead && enemyTarget->readyDamage)
                {
                    if (!enemyTarget->icemanFlag)
                    {
                        enemyTarget->iceEffectSlowdown = enemyTarget->speedKSave * Main::mainClass->readXMLClass.ultraIceLevinSlowdownPowerXML;
                        enemyTarget->iceEffectCounter = Main::mainClass->readXMLClass.ultraIceLevinSlowdownTimerXML;
                    }
                    enemyTarget->getHit(this->damageLittle / 2, "levin", 2, false, bulletType, whoShoot);
                }
            }
            return;
        }// end function

        void close() 
        {
            enemyTarget->bulletTower6Effect = false;
            if (this->chainTarget)
            {
                this->chainTarget->bulletTower6Effect = false;
            }
            kill();
            return;
        }// end function

    
    }
}
