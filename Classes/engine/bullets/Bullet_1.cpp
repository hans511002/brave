
#include "Bullet_1.h"


 namespace engine{
	 namespace bullets{ 
        bool Bullet_1::init( ) 
        {
            bulletType = 1;
            liveTimer = 18;
            liveCounter = 18;
            this.setPostition(this_pt.x,his_pt.y);
            //this->x = this_pt.x;
            //this->y = this_pt.y;
            this->shiftX = 1;
            this->shiftY = 1;
            this->phase1 = 4;
            this->phase2 = 10;
            container = new BulletFireTower_mc();
            //container.stop();
            this->addChild(container);
            this->whoShoot->fireBulletCounter++;
            super.init(event);
            changeIndex = 16;
            return;
        }// end function
        
        void Bullet_1::update() 
        {
            Bullet::update();
            if (mainCounter == 7)
            {
                //Sounds.instance.playSound("snd_tower_shootFire");
            }
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
                    Unit * tempObject1 = NULL;
                    i = 0;
                    while (i < world->listOfUnits.length)
                    {
                        
                        float  tempObject = this_pt.distance(world->listOfUnits[i]->shoot_pt);
                        if (tempObject < 50)
                        {
                            if (!tempObject1)
                            {
                                tempObject1 = world->listOfUnits[i];
                            }
                            else if (this_pt.distance(tempObject1->shoot_pt) > tempObject)
                            {
                                tempObject1 = world->listOfUnits[i];
                            }
                        }
                        i++;
                    }
                    if (tempObject1)
                    {
                        enemyTarget = tempObject1;
                        this->phase1 = 0;
                        this->phase2 = 0;
                    }
                    else
                    {
                        kill();
                    }
                }
                distanceX = enemyTarget->shoot_pt.x - this_pt.x;
                distanceY = enemyTarget->shoot_pt.y - this_pt.y;
                if (this->phase1 > 0)
                {
                    this->phase1--;
                    this->setPostitionX(this->getPostition().x - distanceX / 20);
                    this->setPostitionY( this->getPostition().y - distanceY / 20);
                }
                else if (this->phase2 > 0)
                {
                    (this->phase2 - 1);
                    if (distanceX > 0)
                    {
                        this->setPostitionX(this->getPostition().x +this->shiftX);//this->x = this->x + this->shiftX;
                    }
                    else
                    {
                        this->setPostitionX(this->getPostition().x - this->shiftX);//this->x = this->x - this->shiftX;
                    }
                    if (distanceY > 0)//取反
                    {
                        this->setPostitionY(this->getPostition().y + this->shiftY);// this->y = this->y - this->shiftY;
                    }
                    else
                    {
                        this->setPostitionY(this->getPostition().y - this->shiftY);//  this->y = this->y + this->shiftY;
                    }
                    if (liveCounter < (int)(liveTimer / 2))
                    {
                        this->shiftX = this->shiftX - 0.08;
                        this->shiftY = this->shiftY - 0.08;//this->shiftY = this->shiftY + 0.08;
                    }
                    else
                    {
                        this->shiftX = this->shiftX + 0.08;
                        this->shiftY = this->shiftY + 0.08;//this->shiftY = this->shiftY - 0.08;
                    }
                }
                else
                {
                    this->setPostition(this->getPostition().x + distanceX / liveCounter, this->getPostition().y + distanceY / liveCounter);
                    //this->x = this->x + distanceX / liveCounter;
                    //this->y = this->y + distanceY / liveCounter;
                }
                this_pt =this->getPostition();// cocos2d::Point(this->x, this->y);
                liveCounter--;
            }
            else
            {
                if (enemyTarget->Atstage() && enemyTarget->readyDamage)
                {
                    if (whoShoot->fireBulletCounter >= Main::mainClass->readXMLClass.listOfFireProbability[(spherePower - 1)])
                    {
                        whoShoot->fireBulletCounter = 0;
                        enemyTarget->getHit(damage, "fire", spherePower, true, bulletType);
                    }
                    else
                    {
                        enemyTarget->getHit(damage, "fire", spherePower, false, bulletType);
                    }
                }
                kill();
            }
            return;
        }// end function

    }
}
