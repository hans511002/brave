 
#include "Bullet_5.h" 
#include "engine/mc/mc.h" 
#include "engine/World.h" 

namespace engine{
    namespace bullets{ 
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
            testTower = whoShoot;
            radius = whoShoot.radius;
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
                this->enemySpeed = 0.1;
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
            this->shadow = new UnitShadow_mc();
            this->shadow->stop(); 
            this->shadow->mouseChildren = false;
            this->shadow->mouseEnabled = false;
            this->shadow->setPosition(this_pt.x,whoShoot.y);
            //this->shadow->x = this_pt.x;
            //this->shadow->y = whoShoot.y;
            this->shadow->setScale(0.5,0.5);
            world->addChildAt(this->shadow, 2);
            //world->listOfIndexes2.push(this->shadow);
            //Sounds.instance.playSound("snd_tower_shootUltra1_1");
            return;
        }// end function  
        void Bullet_5::update()
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
                    //this->x = this->x + distanceX / (liveCounter - this->correct);
                    this->setPositionX(this->getPositionX() + distanceX / (liveCounter - this->correct));
                    //this->y = this->y + (distanceY / (liveCounter - this->correct) - 8);
                    this->setPositionY(this->getPositionY() + (distanceY / (liveCounter - this->correct) - 8));
                    
                    this->shadow->setPositionX(this->shadow->getPositionX()+(this->enemyStartPoint.x - this->shadow->getPositionX()) / (liveCounter - this->correct));
                    //this->shadow.x = this->shadow.x + (this->enemyStartPoint.x - this->shadow.x) / (liveCounter - this->correct);
                    this->shadow->setPositionY(this->shadow->getPositionY()+(this->enemyStartPoint.y - this->shadow->getPositionY()) / (liveCounter - this->correct));
                    //this->shadow.y = this->shadow.y + (this->enemyStartPoint.y - this->shadow.y) / (liveCounter - this->correct);
                    if (!this->rotationFlag)
                    {
                        //container->rotation = container->rotation - 7;
                        //if (container->ball)
                        //{
                        //    container->ball->rotation = container->ball->rotation - 7;
                        //}
                    }
                    else
                    {
                        //container->rotation = container->rotation + 7;
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
                        BulletTower5_1Bang_mc * tempObject =  new BulletTower5_1Bang_mc() ;
                        //Sounds.instance.playSound("snd_tower_shootUltra1_2");
                        tempObject->setPosition(this_pt);
                        //tempObject.x = this_pt.x;
                        //tempObject.y = this_pt.y;
                        i = world->listOfUnits.size() - 1;
                        while (i >= 0)
                        {
                            if (world->listOfUnits[i]->atStage() && world->listOfUnits[i]->readyDamage)
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
                tempObject =new BulletTower5_1Smoke1_mc();// new Indexes(new BulletTower5_1Smoke1_mc(), 3, 0.18);
                //tempObject.container->rotation = container->rotation;
                tempObject->setPosition(this_pt);
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
        
        void Bullet_5::kill()
        {
            if (this->shadow)
            {
                world->removeChild(this->shadow);
                //i = 0;
                //while (i < world->listOfIndexes2.length)
                //{
                //    if (world->listOfIndexes2[i] == this->shadow)
                //    {
                //        world->listOfIndexes2.splice(i, 1);
                //        break;
                //    }
                //    i++;
                //}
                this->shadow = NULL;
            }
            Bullet_5::kill();
            return;
        }// end function

    }
}
 
  
         