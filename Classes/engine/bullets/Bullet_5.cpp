 
#include "Bullet_5.h" 
#include "engine/World.h"
#include "engine/units/Unit.h"
#include "engine/towers/Tower.h"

namespace engine{
    namespace bullets{ 
		Bullet_5::Bullet_5() :deviation(0) {
			SET_NODETYPENAME();
		};

        bool Bullet_5::init()  
        {
            bulletType = 5;
            liveTimer = 30;
            liveCounter = 30;
            this->setPosition(this_pt); 
            this->correct = int(liveTimer / 6);
            container = new BulletTower5_1_mc();
            container->stop();
            //container->rotation = 180;
            this->addChild(container);
			testTower = ISTYPE(Tower, whoShoot);
            radius = whoShoot->radius;
            Bullet::init();
            this->enemyStartPoint = enemyTarget->this_pt;
            this->enemyRoad = enemyTarget->road;
            this->enemyWay =  enemyTarget->way;
            this->enemyPath = enemyTarget->path;
            if (enemyTarget->speedK > 0 || enemyTarget->typeUnit == 34)
            {
                this->enemySpeed = enemyTarget->speedK;
            }
            else
            {
                this->enemySpeed = 0.1f;
            }
            bezier::PathPoint tempObject = world->bezierClass->getPathPoint(this->enemyPath + this->enemySpeed * liveTimer, this->enemyRoad, this->enemyWay);
            if (this->getPositionX() > tempObject.x)
            {
                this->rotationFlag = false;
            }
            else
            {
                this->rotationFlag = true;
            }
			this->shadow = new UnitShadow_mc();// new MovieClip("sphere","UnitShadow_mc","UnitShadow_mc");// new UnitShadow_mc();
          
            this->shadow->setPosition(this_pt.x,whoShoot->getPositionY());
            //this->shadow->x = this_pt.x;
            //this->shadow->y = whoShoot.y;
            this->shadow->setScale(0.5,0.5);
            world->addChild(this->shadow, 2); 
            AudioUtil::playSound("Snd_tower_shootUltra1_1.mp3");
            return true;
        }// end function  
        void Bullet_5::update(float dt)
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
                distanceX  = this->enemyStartPoint.x - this_pt.x;
                distanceY  = this->enemyStartPoint.y - this_pt.y;
                testTarget = this->enemyStartPoint;
                scanAtRadius();
                if (greenFlag)
                {
                    this->enemyPath = this->enemyPath + this->enemySpeed;
                }
                bezier::PathPoint tempObject = world->bezierClass->getPathPoint(this->enemyPath, this->enemyRoad, this->enemyWay);
                this->enemyStartPoint = cocos2d::Point(tempObject.x, tempObject.y);
                if (liveCounter > this->correct)
                { 
					this->setPosition(this->getPositionX() + distanceX / (liveCounter - this->correct),
						this->getPositionY() + (distanceY / (liveCounter - this->correct) + 8));
					Vec2 shpos = this->shadow->getPosition();
					this->shadow->setPosition(shpos.x + (this->enemyStartPoint.x - shpos.x) / (liveCounter - this->correct), shpos.y + (this->enemyStartPoint.y - shpos.y) / (liveCounter - this->correct));

                    if (!this->rotationFlag)
                    {
						container->setRotation(container->getRotation() - 7);
                        //if (container->ball)
                        //{
                        //    container->ball->rotation = container->ball->rotation - 7;
                        //}
                    }
                    else
                    {
						container->setRotation(container->getRotation() + 7);
                        //if (container->ball)
                        //{
                        //    container->ball.rotation = container->ball->rotation + 7;
                        //}
                    }
                    this_pt = this->getPosition();// cocos2d::Point(this->x, this->y);
                }
                else
                {
                    this->setPositionX(this->getPositionX() + distanceX / (liveCounter * 10));
                    //this->x = this->x + distanceX / (liveCounter * 10);
                    this->setPositionY(this->getPositionY() + distanceY / (liveCounter * 10));
                    //this->y = this->y + distanceY / (liveCounter * 10);
                    
                    this->shadow->setPositionX(this->shadow->getPositionX()+(this->enemyStartPoint.x - this->shadow->getPositionX()) / (liveCounter * 10));
                    this->shadow->setPositionY(this->shadow->getPositionY()+(this->enemyStartPoint.y - this->shadow->getPositionY()) / (liveCounter * 10));
                    //this->shadow.x = this->shadow.x + (this->enemyStartPoint.x - this->shadow.x) / (liveCounter * 10);
                    //this->shadow.y = this->shadow.y + (this->enemyStartPoint.y - this->shadow.y) / (liveCounter * 10);

                    if (liveCounter == 4)
                    {
                        BulletTower5_1Bang_mc * tempObject =  new BulletTower5_1Bang_mc(this->world) ;
                        AudioUtil::playSound("Snd_tower_shootUltra1_2.mp3");
                        tempObject->setPosition(this_pt);
                        //tempObject.x = this_pt.x;
                        //tempObject.y = this_pt.y;
                        i = world->listOfUnits.size() - 1;
                        while (i >= 0)
                        {
                            if (world->listOfUnits[i]->atStaged && world->listOfUnits[i]->readyDamage)
                            {
                                if (this_pt.distance(world->listOfUnits[i]->shoot_pt) < Main::mainClass->readXMLClass.ultraFireStoneDamageRadiusXML)
                                {
                                    Unit * tempObject = world->listOfUnits[i];
                                    if (tempObject->typeUnit != 23)
                                    {
                                        tempObject->getHit(damage / 2, "fire", 2, true, bulletType, whoShoot);
                                    }
                                    else
                                    {
                                        tempObject->getHit(damage, "fire", 2, false, bulletType, whoShoot);
                                    }
                                    if (!tempObject->dead && tempObject->readyDamage)
                                    {
                                        if (tempObject->typeUnit != 25)
                                        {
                                            tempObject->getHit(damage / 2, "stone", 2, true, bulletType, whoShoot);
                                        }
                                        else
                                        {
                                            tempObject->getHit(damage, "stone", 2, false, bulletType, whoShoot);
                                        }
                                    }
                                }
                            }
                            i--;
                        }
                        this->kill();
						return;
					}
                }
                if (liveCounter > 15)
                {
                    container->setScaleX(container->getScaleX() + 0.01);
                    container->setScaleY(container->getScaleY() + 0.01);
                }
                else
                {
                    container->setScaleX(container->getScaleX() - 0.0105);
                    container->setScaleY(container->getScaleY() - 0.0105);
                }
				BulletTower5_1Smoke1_mc * tempObject1 = new BulletTower5_1Smoke1_mc(world );// new Indexes(new BulletTower5_1Smoke1_mc(), 3, 0.18);
                //tempObject.container->rotation = container->rotation;
				tempObject1->setPosition(this_pt);
                //tempObject.x = this_pt.x;
                //tempObject.y = this_pt.y;
                liveCounter--;
            }
            else
            {
                this->kill();
            }
            return;
        }// end function
        
        void Bullet_5::remove()
        {
            if (this->shadow)
            {
                this->world->removeIndexes(this,2); 
                this->world->removeChild(this->shadow);
                this->shadow = NULL;
            }
            Bullet::remove();
            return;
        }// end function

    }
}
 
  
         