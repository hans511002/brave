#include "engine/World.h"  
#include "Bullet_51.h"
#include "engine/units/Unit.h"


namespace engine{
    namespace bullets
    {
		Bullet_51::Bullet_51() {};

        bool Bullet_51::init() 
        {
            bulletType = 51;
            liveCounter = 0;
            distanceX = -40;
            distanceY = -40;
            this->setPosition(this_pt);
            //this->x = this_pt.x;
            //this->y = this_pt.y;
            i = 0;
            while (i < 7)
            {
                distanceX = -40;
                distanceY = distanceY + 10;
                j = 0;
                while (j < 7) 
                { 
                    distanceX = distanceX + 10;
					BulletBase_mc * tempObject = NULL;
                    if (this->turnFlag)
                    {
                        this->turnFlag = false;
						 tempObject  = new BulletTower51_1_mc();
                        if (this_pt.x < whoShoot->this_pt.x)
                        {
                            tempObject->setPositionX(44);
                        }
                        else
                        {
                            tempObject->setScaleX(tempObject->getScaleX() * -1);
                            tempObject->setPositionX(-44);
                        }
                        tempObject->setPositionY(-624);//.y = -624;
                    }
                    else
                    {
                        this->turnFlag = true;
						 tempObject = new BulletTower51_2_mc();
                        tempObject->setPositionX(0);//tempObject.x = 0;
                        tempObject->setPositionY(-624);//tempObject.y = -624;
                    }
					tempObject->stop();
					tempObject->setPositionX(tempObject->getPositionX() + distanceX);
					tempObject->setPositionY(tempObject->getPositionY() + distanceY);
					tempObject->setVisible(false);

                    tempObject->counter = 40;
                    tempObject->distX = (distanceX - tempObject->getPositionX()) / tempObject->counter;
                    tempObject->distY = (distanceY - tempObject->getPositionY()) / tempObject->counter;
                   
                    this->addChild(tempObject);
                    this->listOfAnimation.push(tempObject);
                    j++;
                }
                i++;
            }
            Bullet::init();
            //Sounds.instance.playSound("snd_tower_shootUltraAdd1");
            return true;
        }// end function

        void Bullet_51::update(float dt) 
        {
            Bullet::update();
            liveCounter++;
            i = this->listOfAnimation.size() - 1;
            while (i >= 0)
            {
                if (!this->listOfAnimation[i]->isVisible())
                {
                    if (std::random() < 0.05)
                    {
                        this->listOfAnimation[i]->setVisible(true);
                    }
                }
                else if (this->listOfAnimation[i]->counter > 0)
                {
                    this->listOfAnimation[i]->counter--;
                    this->listOfAnimation[i]->setPosition(this->listOfAnimation[i]->getPositionX() + this->listOfAnimation[i]->distX ,
                        this->listOfAnimation[i]->getPositionY() + this->listOfAnimation[i]->distY );
                    //this->listOfAnimation[i].x = this->listOfAnimation[i].x + this->listOfAnimation[i].distX;
                    //this->listOfAnimation[i].y = this->listOfAnimation[i].y + this->listOfAnimation[i].distY;
                }
                else if (this->listOfAnimation[i]->currentFrame < this->listOfAnimation[i]->totalFrames)
                {
                    this->listOfAnimation[i]->gotoAndStop((this->listOfAnimation[i]->currentFrame + 1));
                }
                else
                {
                    j = world->listOfUnits.size()- 1;
                    while (j >= 0)
                    {
			            Vec2 tempObject = this->convertToWorldSpace(this->listOfAnimation[i]->getPosition());
                        //tempObject = this->localToGlobal(new Point(this->listOfAnimation[i].x, this->listOfAnimation[i].y));
                        if (world->listOfUnits[j]->atStage() && world->listOfUnits[j]->readyDamage)
                        {
                            if (world->listOfUnits[j]->shoot_pt.distance(tempObject) < Main::mainClass->readXMLClass.ultraAddFireStoneRadiusXML)
                            {
                                Unit * tempObject = world->listOfUnits[j];
                                if (tempObject->typeUnit != 23)
                                {
                                    tempObject->getHit(damage, "fire", 2, true, bulletType, whoShoot);
                                }
                                else
                                {
                                    tempObject->getHit(damage, "fire", 2, false, bulletType, whoShoot);
                                }
                            }
                        }
                        j--;
                    }
                    this->removeChild(this->listOfAnimation[i]);
                    this->listOfAnimation.splice(i, 1);
                }
                i--;
            }
            if (liveCounter == 160)
            {
                i = this->listOfAnimation.size() - 1;
                while (i >= 0)
                {   
                    if (this->listOfAnimation[i]->currentFrame == 1)
                    {
                        this->removeChild(this->listOfAnimation[i]);
                        this->listOfAnimation.splice(i, 1);
                    }
                    i--;
                }
            }
            else if (this->listOfAnimation.size() == 0)
            {
                kill();
            }
            return;
        }// end function

    }
} 
