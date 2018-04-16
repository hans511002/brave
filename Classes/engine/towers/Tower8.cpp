 
#include "Tower8.h"
#include "engine/World.h"

namespace engine
{
    namespace towers
    { 
        Tower8::Tower8():upgr1_intervalCounter(1),soundCounter(0),soundTimer(5)
        {
            return;
        }// end function

        bool Tower8::init()
        {
            towerType = 8;
            //slotsStack = [0, 0, 1, 1];
            slotsStack[0]=0;
            slotsStack[1]=0;
            slotsStack[2]=1;
            slotsStack[3]=1;
            correctYGrPos = -15;
            radius = Main::mainClass->readXMLClass.ultraFireLevinRadiusXML;
            damage = Main::mainClass->readXMLClass.ultraFireLevinDamageXML; 
            intervalTimer = Main::mainClass->readXMLClass.ultraFireLevinIntervalXML;
            intervalCounter = Main::mainClass->readXMLClass.ultraFireLevinIntervalXML;
            this->upgr1_damage = Main::mainClass->readXMLClass.ultraAddFireLevinDamageXML; 
            this->upgr1_intervalTimer = Main::mainClass->readXMLClass.ultraAddFireLevinIntervalXML;
            this->upgr1_intervalCounter = Main::mainClass->readXMLClass.ultraAddFireLevinIntervalXML;
            container = new Tower8_mc();
            container->stop();
            container->towerCase.stop();
            container->cont1->stop();
            container->cont2->stop();
            container->cont3->stop();
            container->cont4->stop();
            container->cont5->stop();
            container->cont6->stop();
            container->fireLight1->stop();
            container->blockTower->stop();
            container->boneBlock->stop();
            container->towerCase->buttonMode = true;
            container->cont4->setVisible(false);
            container->cont5->setVisible(false);
            container->cont6->setVisible(false);
            container->fireLight1->setVisible(false);
            container->blockTower->setVisible(false);
            container->boneBlock->setVisible(false);
            this->addChild(container);
            Tower::init();
            container->visible = false; 
            container->setScale(0.9); 
            return;
        }// end function

        void Tower8::update() 
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
                    container->visible = true;
                    if (!autoBuild)
                    {
                        //Sounds.instance.playSoundWithVol("snd_tower_buildUltra", 0.8);
                    }
                }
            }
            else
            {
                Tower::update();
                if (world->frameCounter % 2)
                {
                    if (container->cont1->currentFrame < container->cont1->totalFrames)
                    {
                        container->cont1->gotoAndStop((container->cont1->currentFrame + 1));
                    }
                    else
                    {
                        container->cont1->gotoAndStop(1);
                    }
                    if (container->cont2->currentFrame < container->cont2->totalFrames)
                    {
                        container->cont2->gotoAndStop((container->cont2->currentFrame + 1));
                    }
                    else
                    {
                        container->cont2->gotoAndStop(1);
                    }
                    if (container->cont3->currentFrame < container->cont3->totalFrames)
                    {
                        container->cont3->gotoAndStop((container->cont3->currentFrame + 1));
                    }
                    else
                    {
                        container->cont3->gotoAndStop(1);
                    }
                }
                container->cont2->rotation = container->cont2->rotation + 3;
            }
            return;
        }// end function

        void Tower8::scan()
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
                        this->upgr1_intervalCounter++;
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

        void Tower8::attack()
        {
            if (intervalCounter == 0)
            {
                if (!this->shootFlag)
                {
                    this->shootFlag = true;
                    container->cont4->setVisible(true);
                    container->cont5->setVisible(true);
                    container->cont6->setVisible(true);
                }
                else
                {
                    if (container->cont4->isVisible())
                    {
                        if (container->cont4->currentFrame < container->cont4->totalFrames)
                        {
                            container->cont4->gotoAndStop((container->cont4->currentFrame + 1));
                        }
                        else
                        {
                            container->cont4->gotoAndStop(1);
                            container->cont4->setVisible(false);
                        }
                    }
                    if (container->cont5->isVisible())
                    {
                        if (container->cont5->currentFrame < container->cont5->totalFrames)
                        {
                            container->cont5->gotoAndStop((container->cont5->currentFrame + 1));
                        }
                        else
                        {
                            container->cont5->gotoAndStop(1);
                            container->cont5->setVisible(false);
                        }
                    }
                    if (container->cont6->isVisible())
                    {
                        if (container->cont6->currentFrame < container->cont6->totalFrames)
                        {
                            container->cont6->gotoAndStop((container->cont6->currentFrame + 1));
                            if (container->cont6->currentFrame == 21)
                            {
                                //Sounds.instance.playSound("snd_tower_firstShootUltraAdd1");
                            }
                        }
                        else
                        {
                            container->cont6->gotoAndStop(1);
                            container->cont6->setVisible(false);
                        }
                    }
                    if (!container->cont4->isVisible() && !container->cont5->isVisible() && !container->cont6->isVisible())
                    {
                        this->shootFlag = false;
                        enemy_pt = world->bezierClass->getPathPoint(enemyTarget->path + enemyTarget->speedK * 30, enemyTarget->road, enemyTarget->way);
                        //enemy_pt =tempObject;// new Point(tempObject.x, tempObject.y);
                        Bullet* tempObject = world->addBullet(8, enemy_pt, this, enemy_pt, damage);
                        intervalCounter = 1;
                        enemyTarget = NULL;
                        if (this->upgr1_intervalCounter == 0)
                        {
                            this->scan();
                        }
                    }
                }
            }
            else if (this->upgr1_intervalCounter == 0)
            {
                if (!container->fireLight1->isVisible())
                {
                    container->fireLight1->setVisible(true);
                    container->fireLight1->gotoAndStop(1);
                }
                else if (container->fireLight1->currentFrame < container->fireLight1->totalFrames)
                {
                    container->fireLight1->gotoAndStop((container->fireLight1->currentFrame + 1));
                    if (container->fireLight1->currentFrame == 17)
                    {
                        if (!enemyTarget.dead)
                        {
                            tempObject = world->addBullet(81, shoot_pt, this, enemyTarget, this->upgr1_damage);
                        }
                    }
                    else if (container->fireLight1->currentFrame == 16)
                    {
                        if (enemyTarget.dead)
                        {
                            enemyTarget = NULL;
                            scanBlock();
                            if (!enemyTarget)
                            {
                                container->fireLight1->setVisible(false);
                                this->upgr1_intervalCounter = 1;
                            }
                        }
                    }
                }
                else
                {
                    container->fireLight1->setVisible(false);
                    this->upgr1_intervalCounter = 1;
                    enemyTarget = NULL;
                }
            }
            return;
        }// end function
 
    }
}
