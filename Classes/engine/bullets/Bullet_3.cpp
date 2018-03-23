
#include "Bullet_3.h"

 namespace engine{
	 namespace bullets{ 
	       void init() 
        {
            bulletType = 3;
            liveTimer = 24;
            liveCounter = 24;
            this->correct = liveCounter / 12; 
            this->setPostition(this_pt.x,his_pt.y);
            //this->x = this_pt.x;
            //this->y = this_pt.y;
            container = new BulletStoneTower_mc();
            //container.stop();
            this->addChild(container);
            testTower = whoShoot;
            radius = whoShoot->radius;
            Bullet::init();
            this->enemyStartPoint = enemyTarget->this_pt;
            this->enemyRoad = enemyTarget->road;
            this->enemyWay = enemyTarget->way;
            this->enemyPath = enemyTarget->path;
            if (enemyTarget->speedK > 0 || enemyTarget->typeUnit == 34)
            {
                if (enemyTarget->typeUnit != 3 && enemyTarget->typeUnit != 8 && enemyTarget->typeUnit != 13)
                {
                    this->enemySpeed = enemyTarget->speedK * 0.5;
                }
                else
                {
                    this->enemySpeed = enemyTarget->speedK;
                }
            }
            else
            {
                this->enemySpeed = 0.1;
            }
            //this->shadow = new UnitShadow_mc();
            //this->shadow.stop();
            //this->shadow.mouseChildren = false;
            //this->shadow.mouseEnabled = false;
            //this->shadow.x = this_pt.x;
            //this->shadow.y = whoShoot->y;
            //this->shadow->setScale(0.5,0.5);
            //world->addChildAt(this->shadow, 2);
            //world->listOfIndexes2.push(this->shadow);
            return;
        }// end function

        void update() 
        {
            Bullet::update();
            if (mainCounter == 11)
            {
                //Sounds.instance.playSoundWithVol("snd_tower_shootStone", 0.8);
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
                distanceX = this->enemyStartPoint.x - this_pt.x;
                distanceY = this->enemyStartPoint.y - this_pt.y;
                testTarget = this->enemyStartPoint;
                scanAtRadius();
                if (greenFlag)
                {
                    this->enemyPath = this->enemyPath + this->enemySpeed;
                }
                bezier::PathPoint tempObject = world->bezierClass->getPathPoint(this->enemyPath, this->enemyRoad, this->enemyWay);
                this->enemyStartPoint = tempObject;//new Point(tempObject.x, tempObject.y);
                if (liveCounter > this->correct)
                {
                    this->setPostition(this->getPostition().x + distanceX /  (liveCounter - this->correct),
                             this->getPostition().y + (distanceY /  (liveCounter - this->correct)-12));
                    //this->x = this->x + distanceX / (liveCounter - this->correct);
                    //this->y = this->y + (distanceY / (liveCounter - this->correct) - 12);               
                    //this->shadow.x = this->shadow.x + (this->enemyStartPoint.x - this->shadow.x) / (liveCounter - this->correct);
                    //this->shadow.y = this->shadow.y + (this->enemyStartPoint.y - this->shadow.y) / (liveCounter - this->correct);
                }
                else
                {
                    this->setPostition(this->getPostition().x + distanceX /liveCounter,this->getPostition().y +  distanceY / liveCounter );
                    //this->x = this->x + distanceX / liveCounter;
                    //this->y = this->y + distanceY / liveCounter;
                    //this->shadow.x = this->shadow.x + (this->enemyStartPoint.x - this->shadow.x) / liveCounter;
                    //this->shadow.y = this->shadow.y + (this->enemyStartPoint.y - this->shadow.y) / liveCounter;
                }
                this_pt =this->getPostition();// new Point(this->x, this->y);
                liveCounter--;//(liveCounter - 1);
            }
            else
            {
                Node* tempObject = CastStone_mc::create(this);
                this->addChild(tempObject); 
                tempObject->container->setScale(0.5,0.5);
                tempObject->setPostition(this_pt);
                //tempObject.x = this_pt.x;
                //tempObject.y = this_pt.y;
                i = world->listOfUnits.size() - 1;
                while (i >= 0)
                {
                    if (world->listOfUnits[i]->atStage() && world->listOfUnits[i]->readyDamage)
                    {
                        //if (Point.distance(this_pt, world->listOfUnits[i]->shoot_pt) < Main::mainClass->readXMLClass.stoneEffectRadiusXML)
                        if(this_pt->distance(world->listOfUnits[i]->shoot_pt) < Main::mainClass->readXMLClass.stoneEffectRadiusXML)
                        {
                            tempObject = world->listOfUnits[i];
                            tempObject->getHit(damage, "stone", spherePower, true, bulletType);
                        }
                    }
                    i--;
                }
                this->kill();
            }
            return;
        }// end function

        void kill() 
        {
            //if (this->shadow)
            //{
            //    world->removeChild(this->shadow);
            //    i = 0;
            //    while (i < world->listOfIndexes2.length)
            //    {
            //        
            //        if (world->listOfIndexes2[i] == this->shadow)
            //        {
            //            world->listOfIndexes2.splice(i, 1);
            //            break;
            //        }
            //        var _loc_2:* = i + 1;
            //        i = _loc_2;
            //    }
            //    this->shadow = null;
            //}
            Bullet::kill();
            return;
        }// end function
}
}