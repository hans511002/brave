
#include "Bullet_4.h" 

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
            //container.stop();
            this->addChild(container);
            if (whoShoot is Tower)
            {
                whoShoot->levinBulletCounter++;
                //Sounds.instance.playSound("snd_tower_shootLevin");
            }
            Bullet::init( );
            return true;
        }// end function

        void Bullet_4::update()
        {
            Bullet::update();
            //if (container.currentFrame < container.totalFrames)
            //{
            //    container.gotoAndStop((container.currentFrame + 1));
            //}
            //else
            //{
            //    container.gotoAndStop(1);
            //}
            if (liveCounter > 0)
            {
                if (enemyTarget->dead)
                {
                    Unit * tempObject1 = null;
                    i = 0;
                    while (i < world->listOfUnits.size())
                    {
                        float tempObject = this_pt->distance(world->listOfUnits[i]->shoot_pt);
                        if (tempObject < 50)
                        {
                            if (!tempObject1)
                            {
                                tempObject1 = world->listOfUnits[i];
                            }
                            else if (this_pt->distance(tempObject1->shoot_pt) > tempObject)
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
                distanceX = enemyTarget->x - this_pt.x;
                distanceY = enemyTarget->y - this_pt.y;
                setPostition(this->getPOstition().x + distanceX / (liveCounter - 3), this->getPOstition().y + distanceY / (liveCounter - 3));
                // this->x = this->x + distanceX / (liveCounter - 3);
                // this->y = this->y + distanceY / (liveCounter - 3);
                if (distanceY > 0)
                {
                    setPostitionX(this->getPOstition().x + this->deviation);
                    //this->x = this->x + this->deviation;
                }
                else if (distanceY < 0)
                {
                    setPostitionX(this->getPOstition().x + this->deviation);
                    //this->x = this->x - this->deviation;
                }
                this_pt = new Point(this->x, this->y);
                (liveCounter - 1);
            }
            else
            {
                if (enemyTarget->atStage && enemyTarget->readyDamage)
                {
                    if (this->effectFlag)
                    {
                        if (whoShoot->levinBulletCounter >= Main.mainClass.readXMLClass.listOfLevinProbability[(spherePower - 1)])
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