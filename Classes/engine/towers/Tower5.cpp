#include "Tower5.h" 

namespace engine
{
    namespace towers
    {
        Tower5::Tower5():soundTimer(5),soundCounter(0),upgr1_damage(0),upgr1_intervalTimer(0),upgr1_intervalCounter(0)
        {
            return;
        }// end function

        bool Tower5::init() 
        {
            towerType = 5;
            //slotsStack = [0, 0, 1, 1];
            slotsStack[0]=0;
            slotsStack[1]=0;
            slotsStack[2]=1;
            slotsStack[3]=1;
            correctYGrPos = -30;
            radius = Main::mainClass->readXMLClass.ultraFireStoneRadiusXML;
            damage = Main::mainClass->readXMLClass.ultraFireStoneDamageXML;
            intervalTimer = Main::mainClass->readXMLClass.ultraFireStoneIntervalXML;
            intervalCounter = Main::mainClass->readXMLClass.ultraFireStoneIntervalXML;
            this->upgr1_damage = Main::mainClass->readXMLClass.ultraAddFireStoneDamageXML;
            this->upgr1_intervalTimer = Main::mainClass->readXMLClass.ultraAddFireStoneIntervalXML;
            this->upgr1_intervalCounter = Main::mainClass->readXMLClass.ultraAddFireStoneIntervalXML;
            container = new Tower5_mc();
            container->stop();
            container->towerCase->stop();
            container->upgr1->stop();
            container->blockTower->stop();
            container->boneBlock->stop();
            container->towerCase->buttonMode = true;
            container->upgr1->setVisible(false);
            container->blockTower->setVisible(false);
            container->boneBlock->setVisible(false);
            this->addChild(container);
            Tower::init();
            if (world->levelType == "grass")
            {
                if (world->nowLevel == 7)
                {
                    if (myPlace->name == "place8")
                    {
                        container->bot->gotoAndStop(2);
                    }
                    else if (myPlace->name == "place9")
                    {
                        container->bot->gotoAndStop(2);
                    }
                    else if (myPlace->name == "place10")
                    {
                        container->bot->gotoAndStop(2);
                    }
                    else
                    {
                        container->bot->gotoAndStop(1);
                    }
                }
                else
                {
                    container->bot->gotoAndStop(1);
                }
            }
            else if (world->levelType == "dust")
            {
                container->bot->gotoAndStop(2);
            }
            if (!autoBuild)
            {
                container->setVisible(false);
            } 
            container->setScale(0.9);
            return;
        }// end function

        void Tower5::update()
        {
            if (this->soundCounter != -1)
            {
                if (this->soundCounter < this->soundTimer)
                {
                    this->soundCounter++;
                }
                else
                {
                    this->soundCounter = -1;
                    container->setVisible(true);
                    //Sounds.instance.playSoundWithVol("snd_tower_buildUltra", 0.8);
                }
            }
            else
            {
                Tower::update();
                if (world->frameCounter % 2)
                {
                    if (container->currentFrame < container->totalFrames)
                    {
                        container->gotoAndStop((container->currentFrame + 1));
                    }
                    else
                    {
                        container->gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

        void Tower5::scan()
        {
            if (!container->blockTower.visible)
            {
                if (intervalCounter < intervalTimer)
                {
                    intervalCounter++;
                }
                else if (world->frameCounter % 2)
                {
                    scanBlock();
                    if (enemyTarget)
                    {
                        intervalCounter = 0;
                    }
                }
                if (upgradeTypeAdd == 1)
                {
                    if (this->upgr1_intervalCounter < this->upgr1_intervalTimer)
                    {
                        this->upgr1_intervalCounter ++;
                    }
                    else if (world->frameCounter % 2)
                    {
                        if (!enemyTarget)
                        {
                            scanBlock();
                            if (enemyTarget)
                            {
                                this->upgr1_intervalCounter = 0;
                            }
                        }
                    }
                }
            }
            else
            {
                blockTowerFunk();
            }
            return;
        }// end function

        void Tower5::attack() 
        {
            if (intervalCounter == 0)
            {
                Bullet * tempObject = world->addBullet(5, shoot_pt, this, enemyTarget, damage);
                intervalCounter = 1;
                enemyTarget = NULL;
                if (this->upgr1_intervalCounter == 0)
                {
                    this->scan();
                }
            }
            else if (this->upgr1_intervalCounter == 0)
            {
                if (!container->upgr1->getVisible())
                {
                    container->upgr1->setVisible(true);
                    //Sounds.instance.playSound("snd_tower_firstShootUltraAdd1");
                }
                else if (container->upgr1->currentFrame < container->upgr1->totalFrames)
                {
                    container->upgr1->gotoAndStop((container->upgr1->currentFrame + 1));
                    if (container->upgr1->currentFrame == 4)
                    {
                        OnceMovieClip * tempObject = new OnceMovieClip();//new Indexes(new ShotTower51_2_mc(), 3);
                        tempObject->setPosition(this->getPositionX() - 8 , this->getPositionY() - 255);
                        //tempObject.x = this->x - 8;
                        //tempObject.y = this->y - 255;
                    }
                }
                else
                {
                    container->upgr1->gotoAndStop(1);
                    container->upgr1->setVisible(false);
                    Point tempObject = world->bezierClass.getPathPoint(enemyTarget.path + enemyTarget.speedK * 30, enemyTarget.road, enemyTarget.way);
                    enemy_pt = tempObject;//cocos2d::Point(tempObject.x, tempObject.y);
                    Bullet * tempObject = world->addBullet(51, enemy_pt, this, enemy_pt, this->upgr1_damage);
                    this->upgr1_intervalCounter = 1;
                    enemyTarget = NULL;
                }
            }
            return;
        }// end function
    }
}
 

