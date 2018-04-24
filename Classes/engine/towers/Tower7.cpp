#ifndef ENGINE_TOWERS_TOWER7_H
#define ENGINE_TOWERS_TOWER7_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "engine/mc/mc.h" 
#include "engine/bullets/Bullet_7.h" 
#include "engine/World.h" 

namespace engine
{
    namespace towers
    { 
        Tower7::Tower7():roundCounter(0),soundCounter(0),soundTimer(5)
        {
            return;
        }// end function

        bool Tower7::init() 
        {
            towerType = 7;
            //slotsStack = [0, 0, 1, 1];
            slotsStack[0]=0;
            slotsStack[1]=0;
            slotsStack[2]=1;
            slotsStack[3]=1;
            correctYGrPos = -15;
            radius = Main::mainClass->readXMLClass.ultraIceStoneRadiusXML;
            damage = Main::mainClass->readXMLClass.ultraIceStoneDamageXML;
            intervalTimer = Main::mainClass->readXMLClass.ultraIceStoneIntervalXML;
            intervalCounter = Main::mainClass->readXMLClass.ultraIceStoneIntervalXML;
            this->upgr1_damage = Main::mainClass->readXMLClass.ultraAddIceStoneDamageXML;
            this->upgr1_intervalTimer = Main::mainClass->readXMLClass.ultraAddIceStoneIntervalXML;
            this->upgr1_intervalCounter = Main::mainClass->readXMLClass.ultraAddIceStoneIntervalXML;
            container = new Tower7_mc();
            container->stop();
            container->towerCase->stop();
            container->cont1->stop();
            container->cont2->stop();
            container->cont3->stop();
            container->upgr1_1->stop();
            container->upgr1_2->stop();
            container->upgr1_3->stop();
            container->upgr1_4->stop();
            container->upgr1_5->stop();
            container->upgr1_6->stop();
            container->upgr1_7->stop();
            container->upgr1_8->stop();
            container->round1->stop();
            container->round2->stop();
            container->round3->stop();
            container->round4->stop();
            container->blockTower->stop();
            container->boneBlock->stop();
            container->towerCase->buttonMode = true;
            container->upgr1_1->setVisible(false);
            container->upgr1_2->setVisible(false);
            container->upgr1_3->setVisible(false);
            container->upgr1_4->setVisible(false);
            container->upgr1_5->setVisible(false);
            container->upgr1_6->setVisible(false);
            container->upgr1_7->setVisible(false);
            container->upgr1_8->setVisible(false);
            container->round1->setVisible(false);
            container->round2->setVisible(false);
            container->round3->setVisible(false);
            container->round4->setVisible(false);
            container->blockTower->setVisible(false);
            container->boneBlock->setVisible(false);
            this->addChild(container);
            Tower::init();
            container->setVisible(false);
            container->setScale(0.9);
            return true;
        }// end function

        void Tower7::update()
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
                    if (!autoBuild)
                    {
                        //Sounds.instance.playSoundWithVol("snd_tower_buildUltra", 0.8);
                    }
                }
            }
            else
            {
                Tower::update();
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
            return;
        }// end function

        void Tower7::scan()
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
                        listOfTargets.clear();// = [];
                        i = 0;
                        while (i < world->listOfUnits.size())
                        { 
                            if (world->listOfUnits[i]->readyDamage && world->listOfUnits[i]->atStage() && !world->listOfUnits[i]->airFlag)
                            {
                                cocos2d::Point tempObject2 = world->bezierClass->getPathPoint(world->listOfUnits[i]->path + world->listOfUnits[i]->speedK * 16, world->listOfUnits[i]->road, world->listOfUnits[i]->way);
                                cocos2d::Point testTarget = cocos2d::Point(tempObject2.x, tempObject2.y);
                                scanAtRadius();
                                if (greenFlag)
                                {
                                    cocos2d::Point tempObject1 = world->bezierClass->getPathPoint(world->listOfUnits[i]->path + world->listOfUnits[i]->speedK * 15, world->listOfUnits[i]->road, world->listOfUnits[i]->way);
                                    if (this_pt.y > tempObject2.y)
                                    {
                                        if (this_pt.x > tempObject1.x)
                                        {
                                            if (tempObject2.x > tempObject1.x && tempObject2.x - tempObject1.x >= world->listOfUnits[i]->speedK * 0.5)
                                            {
                                                world->listOfUnits[i]->tempObject1 = container->upgr1_4;
                                                listOfTargets.push(world->listOfUnits[i]);
                                            }
                                            else if (tempObject2.y > tempObject1.y && tempObject2.y - tempObject1.y >= world->listOfUnits[i]->speedK * 0.5)
                                            {
                                                world->listOfUnits[i]->tempObject1 = container->upgr1_6;
                                                listOfTargets.push(world->listOfUnits[i]);
                                            }
                                        }
                                        else if (tempObject2.x < tempObject1.x && tempObject1.x - tempObject2.x >= world->listOfUnits[i]->speedK * 0.5)
                                        {
                                            world->listOfUnits[i]->tempObject1 = container->upgr1_3;
                                            listOfTargets.push(world->listOfUnits[i]);
                                        }
                                        else if (tempObject2.y > tempObject1.y && tempObject2.y - tempObject1.y >= world->listOfUnits[i]->speedK * 0.5)
                                        {
                                            world->listOfUnits[i]->tempObject1 = container->upgr1_8;
                                            listOfTargets.push(world->listOfUnits[i]);
                                        }
                                    }
                                    else if (this_pt.x > tempObject2.x)
                                    {
                                        if (tempObject2.x > tempObject1.x && tempObject2.x - tempObject1.x >= world->listOfUnits[i]->speedK * 0.5)
                                        {
                                            world->listOfUnits[i]->tempObject1 = container->upgr1_1;
                                            listOfTargets.push(world->listOfUnits[i]);
                                        }
                                        else if (tempObject2.y < tempObject1.y && tempObject1.y - tempObject2.y >= world->listOfUnits[i]->speedK * 0.5)
                                        {
                                            world->listOfUnits[i]->tempObject1 = container->upgr1_5;
                                            listOfTargets.push(world->listOfUnits[i]);
                                        }
                                    }
                                    else if (tempObject2.x < tempObject1.x && tempObject1.x - tempObject2.x >= world->listOfUnits[i]->speedK * 0.5)
                                    {
                                        world->listOfUnits[i]->tempObject1 = container->upgr1_2;
                                        listOfTargets.push(world->listOfUnits[i]);
                                    }
                                    else if (tempObject2.y < tempObject1.y && tempObject1.y - tempObject2.y >= world->listOfUnits[i]->speedK * 0.5)
                                    {
                                        world->listOfUnits[i]->tempObject1 = container->upgr1_7;
                                        listOfTargets.push(world->listOfUnits[i]);
                                    }
                                }
                            }
                            i++;
                        }
                        i = 0;
                        while (i < listOfTargets.size())
                        {
                            if (enemyTarget)
                            {
                                float tempObject = listOfTargets[i]->path / listOfTargets[i]->finishPath;
                                if (tempObject > enemyTarget->tempObject)
                                {
                                    this->upgr1_anima = listOfTargets[i]->tempObject1;
                                    enemyTarget = listOfTargets[i];
                                }
                            }
                            else
                            {
                                this->upgr1_anima = listOfTargets[i]->tempObject1;
                                enemyTarget = listOfTargets[i];
                                this->upgr1_intervalCounter = 0;
                            }
                            i++;
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

        void Tower7::attack()
        {
            if (intervalCounter == 0)
            {
                if (!this->ballAnima)
                {
                    this->ballAnima = new BulletTower7_mc();
                    this->ballAnima->stop();
                    this->ballAnima->ball->stop();
                    this->ballAnima->smoke->stop();
                    this->ballAnima->smoke->cont1->stop();
                    this->ballAnima->smoke->cont2->stop();
                    this->setPosition(0,-20);
                    //this->ballAnima->x = 0;
                    //this->ballAnima->y = -20;
                    //this->ballAnima->rotation = 180;
                    //this->ballAnima->alpha = 0;
                    this->ballAnima->smoke->setVisible(false);
                    container->addChildAt(this->ballAnima, (container->getChildIndex(container->cont2) + 1));
                }
                else if (this->ballAnima->getOpacity() < 1)
                {
                    this->ballAnima->setOpacity(this->ballAnima->getOpacity() + 0.1);
                    container->cont2->setOpacity(container->cont2->getOpacity() - 0.1;
                }
                else if (container->cont2->isVisible())
                {
                    this->ballAnima->setOpacity(1);
                    container->cont2->setOpacity(1);
                    container->cont2->setVisible(false);
                }
                else if (this->ballAnima->getPositionY() > -40)
                {
                    this->ballAnima->setPositionY(this->ballAnima->getPositionY() - 7);
                }
                else if (this->visCounter < 30)
                {
                    this->visCounter++;
                    if (this->visCounter == 1)
                    {
                        this->ballAnima->setVisible(false);
                        shoot_pt = container->localToGlobal(this->ballAnima->getPosition());
                        world->addBullet(7, shoot_pt, this, enemyTarget, damage);
                    }
                }
                else
                {
                    container->removeChild(this->ballAnima);
                    this->ballAnima = NULL;
                    this->visCounter = 0;
                    container->cont2->setVisible(true);
                    intervalCounter = 1;
                    enemyTarget = NULL;
                    if (this->upgr1_intervalCounter == 0)
                    {
                        this->scan();
                    }
                }
            }
            if (this->upgr1_intervalCounter == 0)
            {
                if (this->roundCounter < 2)
                {
                    if (container->currentFrame < container->totalFrames)
                    {
                        if (this->upgr1_anima->name == "upgr1_1" || this->upgr1_anima->name == "upgr1_3" || this->upgr1_anima->name == "upgr1_6" || this->upgr1_anima->name == "upgr1_7")
                        {
                            if (container->currentFrame <= 8)
                            {
                                if (!container->round1->isVisible())
                                {
                                    container->round1->setVisible(true);
                                }
                                else if (container->round1->currentFrame < container->round1->totalFrames)
                                {
                                    container->round1->gotoAndStop((container->round1->currentFrame + 1));
                                    if (this->roundCounter == 0)
                                    {
                                        if (container->round1->currentFrame == 2)
                                        {
                                            //Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                                        }
                                    }
                                }
                                else
                                {
                                    container->round1->gotoAndStop(1);
                                }
                                if (container->round2->isVisible())
                                {
                                    container->round2->setVisible(false);
                                }
                            }
                            else
                            {
                                if (container->round1->isVisible())
                                {
                                    container->round1->setVisible(false);
                                }
                                if (!container->round2->isVisible())
                                {
                                    container->round2->setVisible(true);
                                }
                                else if (container->round2->currentFrame < container->round2->totalFrames)
                                {
                                    container->round2->gotoAndStop((container->round2->currentFrame + 1));
                                    if (this->roundCounter == 0)
                                    {
                                        if (container->round2->currentFrame == 2)
                                        {
                                            //Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                                        }
                                    }
                                }
                                else
                                {
                                    container->round2->gotoAndStop(1);
                                }
                            }
                        }
                        else if (this->upgr1_anima->name == "upgr1_2" || this->upgr1_anima->name == "upgr1_4" || this->upgr1_anima->name == "upgr1_5" || this->upgr1_anima->name == "upgr1_8")
                        {
                            if (container->currentFrame <= 8)
                            {
                                if (!container->round3->isVisible())
                                {
                                    container->round3->setVisible(true);
                                }
                                else if (container->round3->currentFrame < container->round3->totalFrames)
                                {
                                    container->round3->gotoAndStop((container->round3->currentFrame + 1));
                                    if (this->roundCounter == 0)
                                    {
                                        if (container->round3->currentFrame == 2)
                                        {
                                            //Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                                        }
                                    }
                                }
                                else
                                {
                                    container->round3->gotoAndStop(1);
                                }
                                if (container->round4->isVisible())
                                {
                                    container->round2->setVisible(false);
                                }
                            }
                            else
                            {
                                if (container->round3->isVisible())
                                {
                                    container->round3->setVisible(false);
                                }
                                if (!container->round4->isVisible())
                                {
                                    container->round4.visible = true;
                                }
                                else if (container->round4->currentFrame < container->round4->totalFrames)
                                {
                                    container->round4->gotoAndStop((container->round4->currentFrame + 1));
                                    if (this->roundCounter == 0)
                                    {
                                        if (container->round4->currentFrame == 2)
                                        {
                                            //Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                                        }
                                    }
                                }
                                else
                                {
                                    container->round4->gotoAndStop(1);
                                }
                            }
                        }
                        if (this->roundCounter == 1)
                        {
                            if (this->upgr1_anima->name == "upgr1_1")
                            {
                                if (container->currentFrame == 2)
                                {
                                    this->roundCounter = 2;
                                    BulletTower71_mc * tempObject = new BulletTower71_mc();//new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject->rotation = 15;
                                    tempObject->setScale(1);
                                    cocos2d::Point tempObject1 = container->localToGlobal(this->upgr1_anima->getPosition());
                                    tempObject->setPosition(tempObject1); 
                                }
                            }
                            else if (this->upgr1_anima->name == "upgr1_2")
                            {
                                if (container->currentFrame == 2)
                                {
                                    this->roundCounter = 2;
                                    BulletTower71_mc * tempObject = new BulletTower71_mc();//new Indexes(new BulletTower71_mc(), 3, 0);
                                    tempObject->rotation = 15;
                                    tempObject->setScale(1);
                                    cocos2d::Point tempObject1 = container->localToGlobal(this->upgr1_anima->getPosition());
                                    tempObject->setPosition(tempObject1);
                                    //tempObject.x = tempObject1.x;
                                    //tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this->upgr1_anima->name == "upgr1_3")
                            {
                                if (container->currentFrame == 10)
                                {
                                    this->roundCounter = 2;
                                    BulletTower71_mc * tempObject = new BulletTower71_mc();//new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject->rotation = -175;
                                    tempObject->setScale(1);
                                    cocos2d::Point tempObject1 = container->localToGlobal(this->upgr1_anima->getPosition());
                                    tempObject->setPosition(tempObject1);
                                }
                            }
                            else if (this->upgr1_anima->name == "upgr1_4")
                            {
                                if (container->currentFrame == 10)
                                {
                                    this->roundCounter = 2;
                                    BulletTower71_mc * tempObject = new BulletTower71_mc();//new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject->rotation = 175;
                                    tempObject->setScaleX(-1);
                                    tempObject->setScaleY(1); 
                                    cocos2d::Point tempObject1 = container->localToGlobal(this->upgr1_anima->getPosition());
                                    tempObject->setPosition(tempObject1);
                                }
                            }
                            else if (this->upgr1_anima->name == "upgr1_5")
                            {
                                if (container->currentFrame == 15)
                                {
                                    this->roundCounter = 2;
                                    BulletTower71_mc * tempObject = new BulletTower71_mc();//new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject->rotation = -105;
                                    tempObject->setScaleX(1);
                                    tempObject->setScaleY(-1); 
                                    cocos2d::Point tempObject1 = container->localToGlobal(this->upgr1_anima->getPosition());
                                    //tempObject1 = container->localToGlobal(new Point(this->upgr1_anima->x, this->upgr1_anima->y));
                                    tempObject->setPosition(tempObject1);
                                    //tempObject.x = tempObject1.x;
                                    //tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this->upgr1_anima->name == "upgr1_6")
                            {
                                if (container->currentFrame == 8)
                                {
                                    this->roundCounter = 2;
                                    BulletTower71_mc * tempObject = new BulletTower71_mc();//new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject->rotation = 105;
                                    tempObject->setScale(1); 
                                    cocos2d::Point tempObject1 = container->localToGlobal(this->upgr1_anima->getPosition());
                                    //cocos2d::Point tempObject1 = container->localToGlobal(new Point(this->upgr1_anima->x, this->upgr1_anima->y));
                                    tempObject->setPosition(tempObject1);
                                    //tempObject.x = tempObject1.x;
                                    //tempObject.y = tempObject1.y;
                                }
                            }
                            else if (this->upgr1_anima->name == "upgr1_7")
                            {
                                if (container->currentFrame == 15)
                                {
                                    this->roundCounter = 2;
                                    BulletTower71_mc * tempObject = new BulletTower71_mc();//new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject->rotation = -75;
                                    tempObject->setScale(1); 
                                    cocos2d::Point tempObject1 = container->localToGlobal(this->upgr1_anima->getPosition());
                                    tempObject->setPosition(tempObject1); 
                                }
                            }
                            else if (this->upgr1_anima->name == "upgr1_8")
                            {
                                if (container->currentFrame == 8)
                                {
                                    this->roundCounter = 2;
                                    BulletTower71_mc * tempObject = new BulletTower71_mc();//new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject = new Indexes(new BulletTower71_mc(), 3, 0);
                                    //tempObject->rotation = 75;
                                    tempObject->setScaleX(1); 
                                    tempObject->setScaleY(-1); 
                                    cocos2d::Point tempObject1 = container->localToGlobal(this->upgr1_anima->getPosition());
                                    tempObject->setPosition(tempObject1); 
                                }
                            }
                        }
                        if (this->roundCounter == 2)
                        {
                            container->gotoAndStop(1);
                            container->round1->gotoAndStop(1);
                            container->round2->gotoAndStop(1);
                            container->round3->gotoAndStop(1);
                            container->round4->gotoAndStop(1);
                            container->round1->setVisible(false);
                            container->round2->setVisible(false);
                            container->round3->setVisible(false);
                            container->round4->setVisible(false);
                        }
                        else
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                    }
                    else
                    {
                        container->gotoAndStop(1);
                        this->roundCounter = 1;
                    }
                }
                else if (this->upgr1_anima->currentFrame < this->upgr1_anima->totalFrames)
                {
                    this->upgr1_anima->gotoAndStop((this->upgr1_anima->currentFrame + 1));
                    if (this->upgr1_anima->currentFrame == 4)
                    {
                        //Sounds.instance.playSoundWithVol("snd_tower_shootUltraAdd3", 0.95);
                        i = world->listOfUnits.size() - 1;
                        while (i >= 0)
                        {
                            if (world->listOfUnits[i]->readyDamage && world->listOfUnits[i]->atStage() && !world->listOfUnits[i]->airFlag && !world->listOfUnits[i]->teleportFlag)
                            {
                                if (enemyTarget->shoot_pt.distance( world->listOfUnits[i]->shoot_pt) < Main::mainClass->readXMLClass.ultraAddIceStoneRadiusXML)
                                {
                                    if (this->upgr1_anima->name == "upgr1_1")
                                    {
                                        if (this_pt.x + 30 >= world->listOfUnits[i]->shoot_pt.x && this_pt.y - 30 <= world->listOfUnits[i]->shoot_pt.y && this_pt.y + 150 >= world->listOfUnits[i]->shoot_pt.y)
                                        {
                                            world->listOfUnits[i]->setAirSettings("tower71");
                                            world->listOfUnits[i]->getHit(this->upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this->upgr1_anima->name == "upgr1_2")
                                    {
                                        if (this_pt.x - 30 <= world->listOfUnits[i]->shoot_pt.x && this_pt.y - 30 <= world->listOfUnits[i]->shoot_pt.y && this_pt.y + 150 >= world->listOfUnits[i]->shoot_pt.y)
                                        {
                                            world->listOfUnits[i]->setAirSettings("tower71");
                                            world->listOfUnits[i]->getHit(this->upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this->upgr1_anima->name == "upgr1_3")
                                    {
                                        if (this_pt.x - 30 <= world->listOfUnits[i]->shoot_pt.x && this_pt.y + 30 >= world->listOfUnits[i]->shoot_pt.y && this_pt.y - 150 <= world->listOfUnits[i]->shoot_pt.y)
                                        {
                                            world->listOfUnits[i]->setAirSettings("tower71");
                                            world->listOfUnits[i]->getHit(this->upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this->upgr1_anima->name == "upgr1_4")
                                    {
                                        if (this_pt.x + 30 >= world->listOfUnits[i]->shoot_pt.x && this_pt.y + 30 >= world->listOfUnits[i]->shoot_pt.y && this_pt.y - 150 <= world->listOfUnits[i]->shoot_pt.y)
                                        {
                                            world->listOfUnits[i]->setAirSettings("tower71");
                                            world->listOfUnits[i]->getHit(this->upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this->upgr1_anima->name == "upgr1_5")
                                    {
                                        if (this_pt.x + 30 >= world->listOfUnits[i]->shoot_pt.x && this_pt.x - 150 <= world->listOfUnits[i]->shoot_pt.x && this_pt.y - 30 <= world->listOfUnits[i]->shoot_pt.y)
                                        {
                                            world->listOfUnits[i]->setAirSettings("tower71");
                                            world->listOfUnits[i]->getHit(this->upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this->upgr1_anima->name == "upgr1_6")
                                    {
                                        if (this_pt.x + 30 >= world->listOfUnits[i]->shoot_pt.x && this_pt.x - 150 <= world->listOfUnits[i]->shoot_pt.x && this_pt.y + 30 >= world->listOfUnits[i]->shoot_pt.y)
                                        {
                                            world->listOfUnits[i]->setAirSettings("tower71");
                                            world->listOfUnits[i]->getHit(this->upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this->upgr1_anima->name == "upgr1_7")
                                    {
                                        if (this_pt.x - 30 <= world->listOfUnits[i]->shoot_pt.x && this_pt.x + 150 >= world->listOfUnits[i]->shoot_pt.x && this_pt.y - 30 <= world->listOfUnits[i]->shoot_pt.y)
                                        {
                                            world->listOfUnits[i]->setAirSettings("tower71");
                                            world->listOfUnits[i]->getHit(this->upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                    else if (this->upgr1_anima->name == "upgr1_8")
                                    {
                                        if (this_pt.x - 30 <= world->listOfUnits[i]->shoot_pt.x && this_pt.x + 150 >= world->listOfUnits[i]->shoot_pt.x && this_pt.y + 30 >= world->listOfUnits[i]->shoot_pt.y)
                                        {
                                            world->listOfUnits[i]->setAirSettings("tower71");
                                            world->listOfUnits[i]->getHit(this->upgr1_damage, "ice", 2, false, 71, this);
                                        }
                                    }
                                }
                            }
                            i--;
                        }
                    }
                }
                else
                {
                    this->roundCounter = 0;
                    this->upgr1_anima->gotoAndStop(1);
                    this->upgr1_anima->setVisible(false);
                    this->upgr1_intervalCounter = 1;
                    enemyTarget = NULL;
                }
            }
            return;
        }// end function

    }
}
#endif