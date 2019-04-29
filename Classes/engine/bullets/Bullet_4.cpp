
#include "Bullet_4.h" 
#include "engine/World.h"
#include "engine/units/Unit.h"
#include "engine/towers/Tower.h"

namespace engine{
    namespace bullets{
        bool Bullet_4::init()
        {
            bulletType = 4;
            liveTimer = 10;
            liveCounter = 10;
            this->setPosition(this_pt);
            //this->x = this_pt.x;
            //this->y = this_pt.y;
            container = new BulletLevinTower_mc();
            //container->stop();
            this->addChild(container);
			if (ISTYPE(Tower , whoShoot ))
            {
                whoShoot->levinBulletCounter++;
                AudioUtil::playSound("Snd_tower_shootLevin.mp3");
            }
            Bullet::init( );
            return true;
        }// end function

        void Bullet_4::update(float dt)
        {
             if(this->dead){
                this->remove();
                return;
            }
           Bullet::update();
            if (container->currentFrame < container->totalFrames)
            {
                container->tryPlay();
				//container->gotoAndStop((container->currentFrame + 1));
            }
            else
            {
                container->gotoAndStop(1);
            }
            if (liveCounter > 0)
            {
                if (!enemyTarget || enemyTarget->dead)
                {
                    Unit * tempObject1 = NULL;
                    i = world->listOfUnits.size()-1;
                    while (i >=0)
                    {
                        Unit * unit= world->listOfUnits[i];
                        if(!unit->dead){
                            float tempObject = this_pt.distance(unit->shoot_pt);
                            if (tempObject < 50)
                            {
                                if (!tempObject1)
                                    tempObject1 = unit;
                                else if (this_pt.distance(tempObject1->shoot_pt) > tempObject)
                                    tempObject1 = unit;
                            }
                        }
                        i--;
                    }
                    if (tempObject1)
                    {
                        enemyTarget = tempObject1;
                    }
                    else
                    {
                        kill();
						return;
					}
                }
                distanceX = enemyTarget->getPositionX() - this_pt.x;
                distanceY = enemyTarget->getPositionY() - this_pt.y;
                setPosition(this->getPosition().x + distanceX / (liveCounter - 3), this->getPosition().y + distanceY / (liveCounter - 3));
                // this->x = this->x + distanceX / (liveCounter - 3);
                // this->y = this->y + distanceY / (liveCounter - 3);
                if (distanceY > 0)
                {
                    setPositionX(this->getPosition().x + this->deviation);
                    //this->x = this->x + this->deviation;
                }
                else if (distanceY < 0)
                {
                    setPositionX(this->getPosition().x + this->deviation);
                    //this->x = this->x - this->deviation;
                }
                this_pt = cocos2d::Point(this->getPositionX(), this->getPositionY());
                liveCounter--;
            }
            else
            {
                if (enemyTarget && enemyTarget->atStaged && enemyTarget->readyDamage)
                {
                    if (this->effectFlag)
                    {
                        if (whoShoot->levinBulletCounter >= Main::mainClass->readXMLClass.listOfLevinProbability[(spherePower - 1)])
                        {
                            whoShoot->levinBulletCounter = 0;
                            enemyTarget->getHit(damage, "levin", spherePower, true, bulletType);
                        }
                        else
                        {
                            enemyTarget->getHit(damage, "levin", spherePower, false, bulletType);
                        }
                    }
                    else
                    {
                        enemyTarget->getHit(damage, "levin", spherePower, false, bulletType);
                    }
                }
                kill();
            }
            return;
        }// end function
    }
}