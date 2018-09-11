#include "Bullet_8.h" 
#include "engine/World.h" 
#include "engine/units/Unit.h"

namespace engine
{
    namespace bullets
    {
        Bullet_8::Bullet_8()
        {
			SET_NODETYPENAME();
			return;
        }// end function

        bool Bullet_8::init()
        {
            bulletType = 8;
            this->setPosition(enemyTarget->getPosition());
            //this->x = enemyTarget.x;
            //this->y = enemyTarget.y;
            container = new BulletTower8_1_mc();
            container->stop();
            this->addChild(container);
			BulletTower8_2_mc * tempObject = new BulletTower8_2_mc();//new Indexes(new BulletTower8_2_mc(), 0, 0);
            tempObject->setPosition(enemyTarget->getPosition());
			tempObject->setOnceMove(this->world);
            //tempObject.x = enemyTarget.x;
            //tempObject.y = enemyTarget.y;
            tempObject->gotoAndStop(2);
            Bullet::init( ); 
            return true;
        }// end function

        void Bullet_8::update(float dt)
        {
            Bullet::update();
            if (container->currentFrame < container->totalFrames)
            {
                container->tryPlay();
			    //container->gotoAndStop((container->currentFrame + 1));
                if (container->currentFrame == 2 || container->currentFrame == 16 || container->currentFrame == 25)
                {
                    if (container->currentFrame == 2)
                    {
                        AudioUtil::playSound("Snd_tower_shootUltra4_1.mp3");
                    }
                    else if (container->currentFrame == 16)
                    {
                        AudioUtil::playSound("Snd_tower_shootUltra4_2.mp3");
                    }
                    else if (container->currentFrame == 25)
                    {
                        AudioUtil::playSound("Snd_tower_shootUltra4_3.mp3");
                    }
                    i = world->listOfUnits.size() - 1;
                    while (i >= 0)
                    { 
                        if (world->listOfUnits[i]->atStaged && world->listOfUnits[i]->readyDamage)
                        {
                            if (this_pt.distance(world->listOfUnits[i]->shoot_pt) < Main::mainClass->readXMLClass.ultraFireLevinDamageRadiusXML)
                            {
                                Unit * tempObject = world->listOfUnits[i];
                                if (tempObject->typeUnit != 23)
                                {
                                    tempObject->getHit(damage / 2, "fire", 2, true, bulletType, whoShoot);
                                }
                                else
                                {
                                    tempObject->getHit(damage / 2, "fire", 2, false, bulletType, whoShoot);
                                }
                                if (!tempObject->dead && tempObject->readyDamage)
                                {
                                    tempObject->getHit(damage / 2, "levin", 2, false, bulletType, whoShoot);
                                }
                            }
                        }
                        i--;
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
