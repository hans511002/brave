
#include "Bullet_2.h"


 namespace engine{
	 namespace bullets{ 
        bool Bullet_2::init( ) 
        {  
            bulletType = 2; 
            liveTimer = 6;
            liveCounter = 6;
            this->setPosition(this_pt.x,his_pt.y);
            //this->x = this_pt.x;
            //this->y = this_pt.y;
            container = new BulletIceTower_mc();
            //container->stop();
            this->addChild(container);
            whoShoot->iceBulletCounter++; 
            Bullet::init();
            //Sounds.instance.playSoundWithVol("snd_tower_shootIce", 0.83);
            return true;
        }// end function

        void Bullet_2::update()  
        {
            Bullet::update();
            if (container->currentFrame < container->totalFrames)
            {
                container->gotoAndStop((container->currentFrame + 1));
            }
            else
            {
                container->gotoAndStop(1);
            }
            if (liveCounter > 0)
            {
                if (enemyTarget->dead)
                {
                    Unit* tempObject1 = NULL;
                    i = 0;
                    while (i < world->listOfUnits.length)
                    {
                        
                        float tempObject =this_pt.distance( world->listOfUnits[i]->shoot_pt);// Point.distance(this_pt, world->listOfUnits[i]->shoot_pt);
                        if (tempObject < 50)
                        {
                            if (!tempObject1)
                            {
                                tempObject1 = world->listOfUnits[i];
                            }
                            else if (this_pt.distance( tempObject1->shoot_pt) > tempObject)
                            {
                                tempObject1 = world->listOfUnits[i];
                            }
                        }
                        i++;
                    }
                    if (tempObject1)
                    {
                        enemyTarget = tempObject1;
                    }
                    else
                    {
                        kill();
                    }
                }
                distanceX = enemyTarget->getPosition().x - this_pt.x;
                distanceY = enemyTarget->getPosition().y - this_pt.y; 
                this->setPosition(this->getPosition().x + distanceX / liveCounter, this->getPosition().y + distanceY / liveCounter);
                //this->x = this->x + distanceX / liveCounter;
                //this->y = this->y + distanceY / liveCounter;
                this_pt =this->getPosition();// new Point(this->x, this->y);
                liveCounter--;
            }
            else
            {
                if (enemyTarget->atStage() && enemyTarget->readyDamage)
                {
                    if (whoShoot->iceBulletCounter >= Main::mainClass->readXMLClass.listOfIceProbability[(spherePower - 1)])
                    {
                        whoShoot->iceBulletCounter = 0;
                        enemyTarget->getHit(damage, "ice", spherePower, true, bulletType);
                    }
                    else
                    {
                        enemyTarget->getHit(damage, "ice", spherePower, false, bulletType);
                    }
                }
                kill();
            }
            return;
        }// end function

    }
}
