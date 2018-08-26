
#include "MainClass.h"
#include "engine/World.h"
#include "TowerMenu.h"
#include "Tower5.h" 

namespace engine
{
    namespace towers
    {
		Tower5_mc::Tower5_mc() :TowerBase_mc("tower/", "Tower5_mc", "Tower5_mc")
		{
			SET_NODETYPENAME();
			bot = this->createMovieClipSub("bot");
			upgr1 = this->createMovieClipSub("upgr1");
		};

        Tower5::Tower5():soundTimer(5),soundCounter(0),upgr1_intervalTimer(0),upgr1_intervalCounter(0)
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
			Tower5_mc * container = new Tower5_mc();
			this->container = container;
            container->stop();
            container->towerCase->stop();
            container->upgr1->stop();
            container->blockTower->stop();
            container->boneBlock->stop();
            container->towerCase->setMouseEnabled(true);
            container->upgr1->setVisible(false);
            container->blockTower->setVisible(false); 
            container->boneBlock->setVisible(false);
            this->addChild(container);
            Tower::init();
            if (world->levelType == "grass")
            {
                if (world->nowLevel == 7)
                {
                    if (myPlace->getName() == "place8")
                    {
                        container->bot->gotoAndStop(2);
                    }
					else if (myPlace->getName() == "place9")
                    {
                        container->bot->gotoAndStop(2);
                    }
					else if (myPlace->getName() == "place10")
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
            container->setScale(0.9f);
            return true;
        }// end function

        void Tower5::update(float dt)
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
                    AudioUtil::playSoundWithVol("Snd_tower_buildUltra.mp3", 0.8f);
                }
            }
            else
            {
                Tower::update();
                if (world->frameCounter % 2)
                {
                    if (container->currentFrame < container->totalFrames)
                    {
                        container->tryPlay();
                        //container->gotoAndStop((container->currentFrame + 1));
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
            if (!container->blockTower->isVisible())
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
			Tower5_mc * container = ISTYPE(Tower5_mc, this->container);
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
                if (!container->upgr1->isVisible())
                {
                    container->upgr1->setVisible(true);
                    AudioUtil::playSound("Snd_tower_firstShootUltraAdd1.mp3");
                }
                else if (container->upgr1->currentFrame < container->upgr1->totalFrames)
                {
                    container->upgr1->tryPlay();
                    //container->upgr1->gotoAndStop((container->upgr1->currentFrame + 1));
                    if (container->upgr1->currentFrame == 4)
                    {
                        MovieClip * tempObject = new MovieClip(world,"tower","ShotTower51_2_mc","ShotTower51_2_mc");//new Indexes(new ShotTower51_2_mc(), 3);
                        tempObject->setPosition(this->getPositionX() - 8 , this->getPositionY() - 255);
                        //tempObject.x = this->x - 8;
                        //tempObject.y = this->y - 255;
                    }
                }
                else
                {
                    container->upgr1->gotoAndStop(1);
                    container->upgr1->setVisible(false);
                    Vec2 tempObject = world->bezierClass->getPathPoint(enemyTarget->path + enemyTarget->speedK * 30, enemyTarget->road, enemyTarget->way);
                    enemy_pt = tempObject;//cocos2d::Point(tempObject.x, tempObject.y);
					Bullet * bullet = world->addBullet(51, enemy_pt, this, enemyTarget, this->upgr1_damage);
                    this->upgr1_intervalCounter = 1;
                    enemyTarget = NULL;
                }
            }
            return;
        }// end function
    }
}
 

