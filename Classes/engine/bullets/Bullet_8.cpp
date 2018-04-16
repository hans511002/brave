#include "Bullet_8.h" 
#include "engine/World.h" 
#include "engine/units/Unit.h"

namespace engine
{
    namespace bullets
    {
        Bullet_8::Bullet_8()
        {
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
            tempObject = new BulletTower8_2_mc();//new Indexes(new BulletTower8_2_mc(), 0, 0);
            tempObject->setPosition(enemyTarget->getPosition());
            //tempObject.x = enemyTarget.x;
            //tempObject.y = enemyTarget.y;
            tempObject->container->gotoAndStop(2);
            Bullet::init(event);
            return true;
        }// end function

        void Bullet_8::update()
        {
            Bullet::update();
            if (container->currentFrame < container->totalFrames)
            {
                container->gotoAndStop((container->currentFrame + 1));
                if (container->currentFrame == 2 || container->currentFrame == 16 || container->currentFrame == 25)
                {
                    if (container->currentFrame == 2)
                    {
                        //Sounds.instance.playSound("snd_tower_shootUltra4_1");
                    }
                    else if (container->currentFrame == 16)
                    {
                        //Sounds.instance.playSound("snd_tower_shootUltra4_2");
                    }
                    else if (container->currentFrame == 25)
                    {
                        //Sounds.instance.playSound("snd_tower_shootUltra4_3");
                    }
                    i = world->listOfUnits.size() - 1;
                    while (i >= 0)
                    { 
                        if (world->listOfUnits[i]->atStage() && world->listOfUnits[i]->readyDamage)
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
