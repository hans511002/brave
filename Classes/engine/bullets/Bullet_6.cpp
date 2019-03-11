
#include "Bullet_6.h" 
#include "engine/World.h" 
#include "engine/units/Unit.h"
#include "engine/towers/Tower.h"

namespace engine
{
    namespace bullets
    {  
        Bullet_6::Bullet_6():length(0),unitsCout(1)
        { 
			SET_NODETYPENAME();
			return;
        }// end function

		bool Bullet_6::init()
        {
            bulletType = 6;
            this->setPosition(this_pt);
			if (ISTYPE(Tower,whoShoot))
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
            AudioUtil::playSoundWithVol("Snd_tower_shootUltra2.mp3", 0.85f);
            return true;
        }// end function

        void Bullet_6::update(float dt) 
        {
            if(this->dead){
                this->remove();
                return;
            }
            Bullet::update();
            if (this->getPositionX() != this_pt.x && this->getPositionY() != this_pt.y)
            {
                this_pt =this->getPosition();// cocos2d::Point(this->x, this->y);
            }
            if (enemyTarget && container->currentFrame < container->totalFrames)
            {
                container->tryPlay();
			    //container->gotoAndStop((container->currentFrame + 1));
                this->cathetus1 = enemyTarget->shoot_pt.x - this_pt.x;
                this->cathetus2 = enemyTarget->shoot_pt.y - this_pt.y;
                this->hypotenuse = this_pt.distance(enemyTarget->shoot_pt);
                this->angleAlpha = std::atan2(this->cathetus2, this->cathetus1) * (180 / std::PI) - 90;
                //container->rotation = this->angleAlpha;
                if (container->getWidth() > container->getHeight())
                {
					//container->width = this->hypotenuse;
					//container->setContentSize(Size(this->hypotenuse, container->getHeight()));
					container->setScaleX(container->getWidth() / this->hypotenuse);
                    container->setScaleY(container->getScaleX());
                }
                else
                {
                    //container->height = this->hypotenuse;
					container->setScaleY(container->getHeight() / this->hypotenuse);
					container->setScaleX(container->getScaleY());
                }
                if (!this->chainTarget)
                {
                    Unit * tempObject2=NULL;
                    float tempObject = 1000;
                    i = world->listOfUnits.size()- 1;
                    while (i >= 0)
                    { 
                        if (!world->listOfUnits[i]->bulletTower6Effect && world->listOfUnits[i]->readyDamage && world->listOfUnits[i]->atStaged)
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
							Bullet_6 * tempObject = (Bullet_6*)world->addBullet(6, enemyTarget->shoot_pt, enemyTarget, tempObject2, damage);
                            tempObject->length = tempObject->length + this->length;
                            tempObject->unitsCout = this->unitsCout + 1;
                        }
                    }
                }
                if (enemyTarget->airFlag)
                {
                    this->close();
                }
                else if (ISTYPE(Unit,whoShoot ))
                {
					Unit * unit = ISTYPE(Unit, whoShoot);
					if (unit->airFlag)
                    {
                        this->close();
						return;
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

		void Bullet_6::attack()
        {
            if (enemyTarget && enemyTarget->atStaged && enemyTarget->readyDamage)
            {
				//if (enemyTarget->getHit != 24)
				if (enemyTarget->typeUnit != 24)
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

		void Bullet_6::close()
        {
            if(enemyTarget)enemyTarget->bulletTower6Effect = false;
            if (this->chainTarget)
            {
                this->chainTarget->bulletTower6Effect = false;
            }
            kill();
            return;
        }// end function

    
    }
}
