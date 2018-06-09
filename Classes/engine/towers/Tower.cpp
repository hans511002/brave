#include "engine/World.h"
#include "Tower.h"
#include "engine/bullets/Bullet.h" 

namespace engine{
    namespace towers{
 
        bool Tower::init( ) 
        {
            ////this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
            this->world = Main::mainClass->worldClass;
            this->setPosition(this->myPlace->getPosition());
            //this->x = this->myPlace.x;
            //this->y = this->myPlace.y;
            //this->myPlace->placeForBuildCase->buttonMode = false;
            this->this_pt = cocos2d::Point(this->getPositionX() + this->container->getPositionX() + this->container->towerCase->getPositionX()
                , this->getPositionY() + this->container->getPositionY() + this->container->towerCase->getPositionY());
            this->shoot_pt = cocos2d::Point(this->getPositionX(), this->getPositionY() + this->correctYGrPos);
            this->addBuildAnima();
            if (this->towerType < 5)
            {
                this->prepareSpheresGraphic();
            }
            if (Main::mainClass->saveBoxClass->getIntValue("firstViewTowers",this->towerType - 1) == 0)
            {
                Main::mainClass->saveBoxClass->setValue("firstViewTowers",this->towerType - 1, 1) ;
            }
            if (!this->autoBuild)
            {
                if (this->towerType < 5)
                {
                    int addit_buildTowerCounter=this->world->saveBox->getIntValue("addit_buildTowerCounter")+1;
                    this->world->saveBox->setValue("addit_buildTowerCounter",addit_buildTowerCounter);
                        //(this->world->saveBox.gameSave.data.addit_buildTowerCounter + 1);
                    if (addit_buildTowerCounter == 100)
                    {
                        this->world->achieveManage("build_100_towers");
                    }
                }
                else
                {
                    int addit_buildUltraTowersCounter=this->world->saveBox->getIntValue("addit_buildUltraTowersCounter")+1;
                    this->world->saveBox->setValue("addit_buildUltraTowersCounter",addit_buildUltraTowersCounter);
                    if (addit_buildUltraTowersCounter == 1)
                    {
                        this->world->achieveManage("buildUltraTower");
                    }
                    else if (addit_buildUltraTowersCounter == 50)
                    {
                        this->world->achieveManage("buildUltraTower_50_times");
                    }
                    int tempObject1 = 0;
                    int tempObject2 = 0;
                    int tempObject3 = 0;
                    int tempObject4 = 0;
                    this->i = 0;
                    while (this->i < this->world->listOfTowers.size())
                    {
                        if (this->world->listOfTowers[this->i]->towerType == 5)
                        {
                            tempObject1 ++;
                        }
                        else if (this->world->listOfTowers[this->i]->towerType == 6)
                        {
                            tempObject2 ++;
                        }
                        else if (this->world->listOfTowers[this->i]->towerType == 7)
                        {
                            tempObject3 ++;
                        }
                        else if (this->world->listOfTowers[this->i]->towerType == 8)
                        {
                            tempObject4 ++;
                        }
                        i++;
                    }
                    if (tempObject1 > 0 && tempObject2 > 0 && tempObject3 > 0 && tempObject4 > 0)
                    {
                        this->world->achieveManage("buildAllUltraTowers");
                    }
                }
            }
            return true;
        }// end function
        
        void Tower::update() 
        {
            if (!this->buildAnima)
            {
                if (this->towerType < 5)
                {
                    if (this->sphereBullet1)
                    {
                        if (this->sphereBullet1->counter > 0)
                        {
                            this->sphereBullet1->counter --;
                        }
                        else
                        {
                            this->sphereBullet1->setVisible(true);
                            this->sphereBullet1 = NULL;
                        }
                    }
                    if (this->sphereBullet2)
                    {
                        if (this->sphereBullet2->counter > 0)
                        {
                            this->sphereBullet2->counter--;
                        }
                        else
                        {
                            this->sphereBullet2->setVisible(true);
                            this->sphereBullet2 = NULL;
                        }
                    }
                    if (this->sphereBullet3)
                    {
                        if (this->sphereBullet3->counter > 0)
                        {
                            this->sphereBullet3->counter --;
                        }
                        else
                        {
                            this->sphereBullet3->setVisible(true);
                            this->sphereBullet3 = NULL;
                        }
                    }
                    if (this->sphereBullet4)
                    {
                        if (this->sphereBullet4->counter > 0)
                        {
                            this->sphereBullet4->counter--;
                        }
                        else
                        {
                            this->sphereBullet4->setVisible(true);
                            this->sphereBullet4 = NULL;
                        }
                    }
                }
                if (!this->enemyTarget)
                {
                    this->scan();
                }
                else
                {
                    this->attack();
                }
            }
            else if (this->buildAnima->currentFrame < this->buildAnima->totalFrames)
            {
                this->buildAnima->gotoAndStop((this->buildAnima->currentFrame + 1));
            }
            else
            {
                this->removeChild(this->buildAnima);
                this->buildAnima = NULL;
            }
            return;
        }// end function
		void Tower::scan()  
        {
            if (!this->container->blockTower->isVisible() && !this->container->boneBlock->isVisible())
            {
                cocos2d::Point tempObject;
                BulletSphereTower_mc * tempObject2=NULL;
                BulletSphereTower_mc * tempObject1=NULL;
                if (this->shootingTurnStack[0] || this->shootingTurnStack[1] || this->shootingTurnStack[2] || this->shootingTurnStack[3])
                {
                    this->greenFlag = false;
                    this->i = 0;
                    while (this->i < this->shootingTurnStack.size())
                    {
                        if (this->shootingTurnStack[this->i])
                        {
                            if (this->shootingTurnStack[this->i][1] < this->shootingTurnStack[this->i][2])
                            {
                                this->shootingTurnStack[this->i][1] ++;
                            }
                            else
                            {
                                this->greenFlag = true;
                                this->shootingSphere = this->shootingTurnStack[this->i][0];
                                break;
                            }
                        }
                        i++;
                    }
                    if (this->greenFlag && this->world->frameCounter % 2)
                    {
                        this->scanBlock();
                        if (this->enemyTarget)
                        {
                            this->i = 0;
                            while (this->i < this->shootingTurnStack.size())
                            { 
                                if (this->shootingTurnStack[this->i])
                                {
                                    if (this->shootingTurnStack[this->i][1] >= this->shootingTurnStack[this->i][2])
                                    {
                                        this->shootingTurnStack[this->i][1] = 0;
                                        break;
                                    }
                                }
                                i++;
                            }
                            if (this->spheresStack.size() > 1)
                            {
                                if (this->spheresStack.size() == 2)
                                {
                                    this->i = 0;
                                    while (this->i < this->spheresStack.size())
                                    { 
                                        if (this->spheresStack[this->i] == this->shootingSphere)
                                        {
                                            if (this->i == 0)
                                            {
                                                tempObject = this->container->sphere2_1->localToGlobal(this->container->sphere2_1->bullet->getPosition());
                                                if (this->sphereBullet1)
                                                {
                                                    this->sphereBullet1->setVisible(true);
                                                }
                                                this->sphereBullet1 = this->container->sphere2_1->bullet;
                                                tempObject2 = this->container->sphere2_1->bullet;
                                                if (this->shootingSphere == "fire")
                                                {
                                                    tempObject1 = new BulletFireTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "ice")
                                                {
                                                    tempObject1= new BulletIceTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "stone")
                                                {
                                                    tempObject1= new BulletStoneTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "levin")
                                                {
                                                    tempObject1= new BulletLevinTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                            }
                                            else if (this->i == 1)
                                            {
                                                tempObject = this->container->sphere2_2->localToGlobal(this->container->sphere2_2->bullet->getPosition());
                                                if (this->sphereBullet2)
                                                {
                                                    this->sphereBullet2->setVisible(true);
                                                }
                                                this->sphereBullet2 = this->container->sphere2_2->bullet;
                                                tempObject2 = this->container->sphere2_2->bullet;
                                                if (this->shootingSphere == "fire")
                                                {
                                                    tempObject1= new BulletFireTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "ice")
                                                {
                                                    tempObject1= new BulletIceTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "stone")
                                                {
                                                    tempObject1= new BulletStoneTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "levin")
                                                {
                                                    tempObject1= new BulletLevinTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                            }
                                            this->tempObject2->counter = this->sphereVisibleTimer;
                                            this->tempObject2->setVisible(false);
                                            tempObject = this->container->globalToLocal(tempObject);
                                            tempObject1->setPosition(tempObject);
                                            //tempObject1->x = this->tempObject.x;
                                            //tempObject1->y = this->tempObject.y;
                                            tempObject1->counter = 3;
                                            tempObject1->distX = -tempObject->getPositionX() / tempObject1->counter;
                                            tempObject1->distY = (-70 - tempObject->getPositionY()) / tempObject1->counter;
                                            this->container->addChild(tempObject1);
                                            this->shootinAttackStack.push(tempObject1);
                                        }
                                        i++;
                                    }
                                }
                                else if (this->spheresStack.size() == 3)
                                {
                                    this->i = 0;
                                    while (this->i < this->spheresStack.size())
                                    { 
                                        if (this->spheresStack[this->i] == this->shootingSphere)
                                        {
                                            if (this->i == 0)
                                            {
                                                tempObject = this->container->sphere3_1->localToGlobal(this->container->sphere3_1->bullet->getPosition());
                                                if (this->sphereBullet1)
                                                {
                                                    this->sphereBullet1->setVisible(true);
                                                }
                                                this->sphereBullet1 = this->container->sphere3_1->bullet;
                                                tempObject2 = this->container->sphere3_1->bullet;
                                                if (this->shootingSphere == "fire")
                                                {
                                                    tempObject1= new BulletFireTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "ice")
                                                {
                                                    tempObject1= new BulletIceTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "stone")
                                                {
                                                    tempObject1= new BulletStoneTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "levin")
                                                {
                                                    tempObject1= new BulletLevinTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                            }
                                            else if (this->i == 1)
                                            {
                                                tempObject = this->container->sphere3_2.localToGlobal(this->container->sphere3_2->bullet->getPosition());
                                                if (this->sphereBullet2)
                                                {
                                                    this->sphereBullet2->setVisible(true);
                                                } 
                                                this->sphereBullet2 = this->container->sphere3_2->bullet;
                                                tempObject2 = this->container->sphere3_2->bullet;
                                                if (this->shootingSphere == "fire")
                                                {
                                                    tempObject1= new BulletFireTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "ice")
                                                {
                                                    tempObject1= new BulletIceTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "stone")
                                                {
                                                    tempObject1= new BulletStoneTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "levin")
                                                {
                                                    tempObject1= new BulletLevinTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                            }
                                            else if (this->i == 2)
                                            {
                                                tempObject = this->container->sphere3_3.localToGlobal(this->container->sphere3_3->bullet->getPosition() );
                                                if (this->sphereBullet3)
                                                {
                                                    this->sphereBullet3->setVisible(true);
                                                } 
                                                this->sphereBullet3 = this->container->sphere3_3->bullet;
                                                tempObject2 = this->container->sphere3_3->bullet;
                                                if (this->shootingSphere == "fire")
                                                {
                                                    tempObject1= new BulletFireTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "ice")
                                                {
                                                    tempObject1= new BulletIceTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "stone")
                                                {
                                                    tempObject1= new BulletStoneTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "levin")
                                                {
                                                    tempObject1= new BulletLevinTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                            }
                                            this->tempObject2->counter = this->sphereVisibleTimer;
                                            this->tempObject2->setVisible(false);
                                            tempObject = this->container->globalToLocal( tempObject);
                                            tempObject1->setPosition(tempObject);
                                            tempObject1->counter = 3;
                                            tempObject1->distX = -tempObject.x / tempObject1->counter;
                                            tempObject1->distY = (-70 - tempObject.y) / tempObject1->counter;
                                            this->container->addChild(tempObject1);
                                            this->shootinAttackStack.push(tempObject1);
                                        }
                                        i++;
                                    }
                                }
                                else if (this->spheresStack.size() == 4)
                                {
                                    this->i = 0;
                                    while (this->i < this->spheresStack.size())
                                    { 
                                        if (this->spheresStack[this->i] == this->shootingSphere)
                                        {
                                            if (this->i == 0)
                                            {
                                                tempObject = this->container->sphere4_1->localToGlobal(this->container->sphere4_1->bullet->getPosition());
                                                if (this->sphereBullet1)
                                                {
                                                    this->sphereBullet1->setVisible(true);
                                                } 
                                                this->sphereBullet1 = this->container->sphere4_1->bullet;
                                                tempObject2 = this->container->sphere4_1->bullet;
                                                if (this->shootingSphere == "fire")
                                                {
                                                    tempObject1= new BulletFireTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "ice")
                                                {
                                                    tempObject1= new BulletIceTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "stone")
                                                {
                                                    tempObject1= new BulletStoneTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "levin")
                                                {
                                                    tempObject1= new BulletLevinTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                            }
                                            else if (this->i == 1)
                                            {
                                                tempObject = this->container->sphere4_2->localToGlobal( this->container->sphere4_2->bullet->getPosition());
                                                if (this->sphereBullet2)
                                                {
                                                    this->sphereBullet2->setVisible(true);
                                                } 
                                                this->sphereBullet2 = this->container->sphere4_2->bullet;
                                                tempObject2 = this->container->sphere4_2->bullet;
                                                if (this->shootingSphere == "fire")
                                                {
                                                    tempObject1= new BulletFireTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "ice")
                                                {
                                                    tempObject1= new BulletIceTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "stone")
                                                {
                                                    tempObject1= new BulletStoneTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "levin")
                                                {
                                                    tempObject1= new BulletLevinTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                            }
                                            else if (this->i == 2)
                                            {
                                                tempObject = this->container->sphere4_3->localToGlobal(this->container->sphere4_3->bullet->getPosition());
                                                if (this->sphereBullet3)
                                                {
                                                    this->sphereBullet3->setVisible(true);
                                                } 
                                                this->sphereBullet3 = this->container->sphere4_3->bullet;
                                                tempObject2 =  this->container->sphere4_3->bullet;
                                                if (this->shootingSphere == "fire")
                                                {
                                                    tempObject1= new BulletFireTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "ice")
                                                {
                                                    tempObject1= new BulletIceTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "stone")
                                                {
                                                    tempObject1= new BulletStoneTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "levin")
                                                {
                                                    tempObject1= new BulletLevinTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                            }
                                            else if (this->i == 3)
                                            {
                                                tempObject = this->container->sphere4_4->localToGlobal(this->container->sphere4_4->bullet->getPosition());
                                                if (this->sphereBullet4)
                                                {
                                                    this->sphereBullet4->setVisible(true);
                                                } 
                                                this->sphereBullet4 = this->container->sphere4_4->bullet;
                                                tempObject2 = this->container->sphere4_4->bullet;
                                                if (this->shootingSphere == "fire")
                                                {
                                                    tempObject1= new BulletFireTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "ice")
                                                {
                                                    tempObject1= new BulletIceTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "stone")
                                                {
                                                    tempObject1= new BulletStoneTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                                else if (this->shootingSphere == "levin")
                                                {
                                                    tempObject1= new BulletLevinTower_mc();
                                                    tempObject1->gotoAndStop(tempObject2->cont->currentFrame);
                                                }
                                            }
                                            tempObject2->counter = this->sphereVisibleTimer;
                                            tempObject2->setVisible(false);
                                            tempObject = this->container->globalToLocal(tempObject);
                                            tempObject1->setPosition(tempObject);
                                            tempObject1->counter = 3;
                                            tempObject1->distX = -tempObject.x / tempObject1->counter;
                                            tempObject1->distY = (-70 - tempObject.y) / tempObject1->counter;
                                            this->container->addChild(tempObject1);
                                            this->shootinAttackStack.push(tempObject1);
                                        }
                                        i++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                this->blockTowerFunk();
            }
            return;
        }// end function
        void Tower::attack() 
        {
            if (this->shootinAttackStack.size() == 0)
            {
                cocos2d::Point tempPos= this->container->sphere1->localToGlobal(this->container->sphere1->bullet->getPosition());
                if (this->shootingSphere == "fire")
                {
                    Bullet * tempObject = this->world->addBullet(1, tempPos, this, this->enemyTarget, Main::mainClass->readXMLClass.listOfFireTowerDamageXML[0], 1);
                    if (this->container->sphere1->bullet->cont)
                    {
                        tempObject->container->gotoAndStop(this->container->sphere1->bullet->cont->currentFrame);
                    }
                }
                else if (this->shootingSphere == "ice")
                {
                    Bullet * tempObject = this->world->addBullet(2, tempPos, this, this->enemyTarget, Main::mainClass->readXMLClass.listOfIceTowerDamageXML[0], 1);
                    if (this->container->sphere1->bullet->cont)
                    {
                        tempObject->container->gotoAndStop(this->container->sphere1->bullet->cont->currentFrame);
                    }
                }
                else if (this->shootingSphere == "stone")
                {
                    Bullet * tempObject = this->world->addBullet(3, tempPos, this, this->enemyTarget, Main::mainClass->readXMLClass.listOfStoneTowerDamageXML[0], 1);
                    if (this->container->sphere1->bullet->cont)
                    {
                        tempObject->container->gotoAndStop(this->container->sphere1->bullet->cont->currentFrame);
                    }
                }
                else if (this->shootingSphere == "levin")
                {
                    Bullet * tempObject = this->world->addBullet(4, tempPos, this, this->enemyTarget, Main::mainClass->readXMLClass.listOfLevinTowerDamageXML[0], 1);
                    if (this->container->sphere1->bullet->cont)
                    {
                        tempObject->container->gotoAndStop(this->container->sphere1->bullet->cont->currentFrame);
                    }
                }
                if (this->sphereBullet1)
                {
                    this->sphereBullet1->setVisible(true);
                } 
                this->sphereBullet1 = this->container->sphere1->bullet;
                this->tempObject2 = this->container->sphere1->bullet;
                this->tempObject2->counter = this->sphereVisibleTimer;
                this->tempObject2->setVisible(false);
                this->shootingSphere = NULL;
                this->enemyTarget = NULL;
            }
            else
            {
                this->i = 0;
                while (this->i < this->shootinAttackStack.size())
                { 
                    if (this->shootinAttackStack[this->i]->currentFrame < this->shootinAttackStack[this->i]->totalFrames)
                    {
                        this->shootinAttackStack[this->i]->gotoAndStop((this->shootinAttackStack[this->i]->currentFrame + 1));
                    }
                    else
                    {
                        this->shootinAttackStack[this->i]->gotoAndStop(1);
                    }
                    if (this->shootinAttackStack[this->i]->counter > 0)
                    {
                        this->shootinAttackStack[this->i]->counter --;
                        
                        this->shootinAttackStack[this->i]->setPositionX(this->shootinAttackStack[this->i]->getPositionX() + this->shootinAttackStack[this->i]->distX);
                        this->shootinAttackStack[this->i]->setPositionY(this->shootinAttackStack[this->i]->getPositionY() + this->shootinAttackStack[this->i]->distY);
                    }
                    else
                    {
                        Bullet * tempObject =NULL;
                        cocos2d::Point tempPos = this->container->localToGlobal( this->shootinAttackStack[0]->getPosition());
                        if (this->shootingSphere == "fire")
                        {
                            if (this->shootingTurnStack[0])
                            {
                                 tempObject = this->world->addBullet(1, tempPos, this, this->enemyTarget, Main::mainClass->readXMLClass.listOfFireTowerDamageXML[(this->shootingTurnStack[0][3] - 1)], this->shootingTurnStack[0][3]);
                            }
                            else
                            {
                                //this->tempObject = null;
                            }
                        }
                        else if (this->shootingSphere == "ice")
                        {
                            if (this->shootingTurnStack[1])
                            {
                                 tempObject = this->world->addBullet(2,tempPos, this, this->enemyTarget, Main::mainClass->readXMLClass.listOfIceTowerDamageXML[(this->shootingTurnStack[1][3] - 1)], this->shootingTurnStack[1][3]);
                            }
                            else
                            {
                                //this->tempObject = null;
                            }
                        }
                        else if (this->shootingSphere == "stone")
                        {
                            if (this->shootingTurnStack[2])
                            {
                                 tempObject = this->world->addBullet(3, tempPos, this, this->enemyTarget, Main::mainClass->readXMLClass.listOfStoneTowerDamageXML[(this->shootingTurnStack[2][3] - 1)], this->shootingTurnStack[2][3]);
                            }
                            else
                            {
                                //this->tempObject = null;
                            }
                        }
                        else if (this->shootingSphere == "levin")
                        {
                            if (this->shootingTurnStack[3])
                            {
                              tempObject = this->world->addBullet(4,tempPos, this, this->enemyTarget, Main::mainClass->readXMLClass.listOfLevinTowerDamageXML[(this->shootingTurnStack[3][3] - 1)], this->shootingTurnStack[3][3]);
                            }
                            else
                            {
                                //this->tempObject = null;
                            }
                        }
                        if ( tempObject)
                        {
                            tempObject->container->gotoAndStop(this->shootinAttackStack[0]->currentFrame);
                        }
                        this->shootingSphere = NULL;
                        this->enemyTarget = NULL;
                        this->j = this->shootinAttackStack.size() - 1;
                        while (this->j >= 0)
                        {
                            this->container->removeChild(this->shootinAttackStack[this->j]);
                            this->shootinAttackStack.splice(this->j, 1);
                            j--;
                        }
                        break;
                    }
                    i++;
                }
            }
            return;
        }// end function
        void Tower::scanAtRadius() 
        {
            this->greenFlag = false;
            float tempObject = this->radius - this->radius * (1 - this->world->scaleRadius);
            if ((this->testTarget->getPositionX() - this->this_pt.x) * (this->testTarget->getPositionX() - this->this_pt.x) / (this->radius * this->radius) 
                + (this->testTarget->getPositionY() - this->this_pt.y) * (this->testTarget->getPositionY() - this->this_pt.y) / (tempObject * tempObject) <= 1)
            {
                this->greenFlag = true;
            }
            return;
        }// end functio
        
        int spheresManage(string param1, string param2, int param3) 
        {
            if (this->towerType < 5)
            {
                if (param1 == "scan")
                {
                    if (this->slotsStack.size() > 0)
                    {
                        if (this->slotsStack[3] == 0)
                        {
                            int tempObject = 4 - this->spheresStack.size();
                            return tempObject;
                        }
                        if (this->slotsStack[2] == 0)
                        {
                            int tempObject = 3 - this->spheresStack.size();
                            return tempObject;
                        }
                        if (this->slotsStack[1] == 0)
                        {
                            int tempObject = 2 - this->spheresStack.size();
                            return tempObject;
                        }
                        if (this->slotsStack[0] == 0)
                        {
                            int tempObject = 1 - this->spheresStack.size();
                            return tempObject;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (param1 == "push")
                {
                    if (this->world->towerMenu)
                    {
                        if (this->world->towerMenu->myTower == this && this->world->nowLevel > 1 && this->world->nowLevel < 5)
                        {
                            if (!this->world->towerMenu->training_12)
                            {
                                if (!Main::mainClass->saveBoxClass->getBoolValue("firstClickKeepAll"))
                                {
                                    this->world->towerMenu->training_12 = new Training_12();
                                    this->world->towerMenu->addChild(this->world->towerMenu->training_12);
                                }
                            }
                        }
                    }
                    tempObject1= this->spheresManage("scan");
                    if (param2 != "getAll")
                    {
                        if (tempObject1 >= param3)
                        {
                            while (param3 > 0)
                            { 
                                param3 = param3 - 1;
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                            }
                            this->prepareSpheresGraphic();
                            return 0;
                        }
                        else
                        {
                            this->i = 1;
                            while (this->i <= tempObject1)
                            { 
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                                i++;
                            }
                            this->tempObject = param3 - tempObject1;
                            if (this->tempObject != param3)
                            {
                                this->prepareSpheresGraphic();
                            }
                            return this->tempObject;
                        }
                    }
                    else
                    {
                        if (tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            this->i = 1;
                            while (this->i <= tempObject1)
                            { 
                                if (this->i == 1)
                                {
                                    this->spheresStack.push("fire");
                                    this->shootingStackManage("add", "fire");
                                }
                                else if (this->i == 2)
                                {
                                    this->spheresStack.push("ice");
                                    this->shootingStackManage("add", "ice");
                                }
                                else if (this->i == 3)
                                {
                                    this->spheresStack.push("stone");
                                    this->shootingStackManage("add", "stone");
                                }
                                else if (this->i == 4)
                                {
                                    this->spheresStack.push("levin");
                                    this->shootingStackManage("add", "levin");
                                }
                                this->prepareSpheresGraphic();
                                i++;
                            }
                            if (tempObject1 < 4)
                            {
                                if (tempObject1 < 4)
                                {
                                    this->world->feature->getSphereBeat("levin", 1);
                                    this->world->getSphere->setPosition(this->this_pt);
                                    this->world->getSphere->retrieveGetSphere();
                                }
                                if (tempObject1 < 3)
                                {
                                    this->world->feature->getSphereBeat("stone", 1);
                                    this->world->getSphere->setPosition(this->this_pt); 
                                    this->world->getSphere->retrieveGetSphere();
                                }
                                if (tempObject1 < 2)
                                {
                                    this->world->feature->getSphereBeat("ice", 1);
                                    this->world->getSphere->setPosition(this->this_pt);
                                    this->world->getSphere->retrieveGetSphere();
                                }
                            }
                        }
                        return param3;
                    }
                }
                else if (param1 == "get")
                {
                    int tempObject = 0;
                    this->i = this->spheresStack.size() - 1;
                    while (this->i >= 0)
                    { 
                        if (this->spheresStack[this->i] == param2)
                        {
                            if (this->tempObject < param3)
                            {
                                this->spheresStack.splice(this->i, 1);
                                this->shootingStackManage("remove", param2);
                                this->tempObject++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        i--;
                    }
                    if (this->tempObject > 0)
                    {
                        this->prepareSpheresGraphic();
                    }
                    return tempObject;
                }
            }
            else if (param1 == "scan")
            {
                int tempObject = 0;
                if (this->towerType == 5)
                {
                    if (Main::mainClass->readXMLClass.ultraTower1UpgrBlock > 0)
                    {
                        return 0;
                    }
                    if (!this->shootingTurnStack[0])
                    {
                         tempObject++;
                    }
                    if (!this->shootingTurnStack[2])
                    {
                         tempObject++;
                    }
                    return tempObject;
                }
                else if (this->towerType == 6)
                {
                    if (Main::mainClass->readXMLClass.ultraTower2UpgrBlock > 0)
                    {
                        return 0;
                    }
                    tempObject = 0;
                    if (!this->shootingTurnStack[1])
                    {
                        tempObject++;
                    }
                    if (!this->shootingTurnStack[3])
                    {
                        tempObject++;
                    }
                    return tempObject;
                }
                else if (this->towerType == 7)
                {
                    if (Main::mainClass->readXMLClass.ultraTower3UpgrBlock > 0)
                    {
                        return 0;
                    }
                    tempObject = 0;
                    if (!this->shootingTurnStack[1])
                    {
                        tempObject++;
                    }
                    if (!this->shootingTurnStack[2])
                    {
                        tempObject++;
                    }
                    return  tempObject;
                }
                else if (this->towerType == 8)
                {
                    if (Main::mainClass->readXMLClass.ultraTower4UpgrBlock > 0)
                    {
                        return 0;
                    }
                    tempObject = 0;
                    if (!this->shootingTurnStack[0])
                    {
                        tempObject++;
                    }
                    if (!this->shootingTurnStack[3])
                    {
                        tempObject++;
                    }
                    return  tempObject;
                }
            }
            else if (param1 == "push")
            {
                if (this->towerType == 5)
                {
                    if (Main::mainClass->readXMLClass.ultraTower1UpgrBlock > 0)
                    {
                        return param3;
                    }
                    if (param2 == "fire")
                    {
                        if (param3 > 0)
                        {
                            if (!this->shootingTurnStack[0])
                            {
                                param3 = param3 - 1;
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "stone")
                    {
                        if (param3 > 0)
                        {
                            if (!this->shootingTurnStack[2])
                            {
                                param3 = param3 - 1;
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "getAll")
                    {
                        tempObject1 = this->spheresManage("scan");
                        if (tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            if (!this->shootingTurnStack[0])
                            {
                                this->spheresStack.push("fire");
                                this->shootingStackManage("add", "fire");
                            }
                            else
                            {
                                this->world->feature->getSphereBeat("fire", 1);
                                this->world->getSphere->setPosition(this->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                            if (!this->shootingTurnStack[2])
                            {
                                this->spheresStack.push("stone");
                                this->shootingStackManage("add", "stone");
                            }
                            else
                            {
                                this->world->feature->getSphereBeat("stone", 1);
                                this->world->getSphere->setPosition(this->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                            this->world->feature->getSphereBeat("ice", 1);
                            this->world->getSphere->setPosition(this->this_pt);
                            this->world->getSphere->retrieveGetSphere();
                            this->world->feature->getSphereBeat("levin", 1);
                            this->world->getSphere->setPosition(this->this_pt);
                            this->world->getSphere->retrieveGetSphere();
                        }
                        return param3;
                    }
                    else
                    {
                        return param3;
                    }
                }
                else if (this->towerType == 6)
                {
                    if (Main::mainClass->readXMLClass.ultraTower2UpgrBlock > 0)
                    {
                        return param3;
                    }
                    if (param2 == "ice")
                    {
                        if (param3 > 0)
                        {
                            if (!this->shootingTurnStack[1])
                            {
                                param3 = param3 - 1;
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "levin")
                    {
                        if (param3 > 0)
                        {
                            if (!this->shootingTurnStack[3])
                            {
                                param3 = param3 - 1;
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "getAll")
                    {
                        tempObject1 = this->spheresManage("scan");
                        if (tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            if (!this->shootingTurnStack[1])
                            {
                                this->spheresStack.push("ice");
                                this->shootingStackManage("add", "ice");
                            }
                            else
                            {
                                this->world->feature->getSphereBeat("ice", 1);
                                this->world->getSphere->setPosition(this->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                            if (!this->shootingTurnStack[3])
                            {
                                this->spheresStack.push("levin");
                                this->shootingStackManage("add", "levin");
                            }
                            else
                            {
                                this->world->feature->getSphereBeat("levin", 1); 
                                this->world->getSphere->setPosition(this->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                            this->world->feature->getSphereBeat("fire", 1);
                            this->world->getSphere->setPosition(this->this_pt);
                            this->world->getSphere->retrieveGetSphere();
                            this->world->feature->getSphereBeat("stone", 1);
                            this->world->getSphere->setPosition(this->this_pt);
                            this->world->getSphere->retrieveGetSphere();
                        }
                        return param3;
                    }
                    else
                    {
                        return param3;
                    }
                }
                else if (this->towerType == 7)
                {
                    if (Main::mainClass->readXMLClass.ultraTower3UpgrBlock > 0)
                    {
                        return param3;
                    }
                    if (param2 == "ice")
                    {
                        if (param3 > 0)
                        {
                            if (!this->shootingTurnStack[1])
                            {
                                param3 = param3 - 1;
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "stone")
                    {
                        if (param3 > 0)
                        {
                            if (!this->shootingTurnStack[2])
                            {
                                param3 = param3 - 1;
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "getAll")
                    {
                        tempObject1 = this->spheresManage("scan");
                        if (tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            if (!this->shootingTurnStack[1])
                            {
                                this->spheresStack.push("ice");
                                this->shootingStackManage("add", "ice");
                            }
                            else
                            {
                                this->world->feature->getSphereBeat("ice", 1);
                                this->world->getSphere->setPosition(this->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                            if (!this->shootingTurnStack[3])
                            {
                                this->spheresStack.push("stone");
                                this->shootingStackManage("add", "stone");
                            }
                            else
                            {
                                this->world->feature->getSphereBeat("stone", 1);
                                this->world->getSphere->setPosition(this->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                            this->world->feature->getSphereBeat("fire", 1);
                            this->world->getSphere->setPosition(this->this_pt);
                            this->world->getSphere->retrieveGetSphere();
                            this->world->feature->getSphereBeat("levin", 1);
                            this->world->getSphere->setPosition(this->this_pt);
                            this->world->getSphere->retrieveGetSphere();
                        }
                        return param3;
                    }
                    else
                    {
                        return param3;
                    }
                }
                else if (this->towerType == 8)
                {
                    if (Main::mainClass->readXMLClass.ultraTower4UpgrBlock > 0)
                    {
                        return param3;
                    }
                    if (param2 == "fire")
                    {
                        if (param3 > 0)
                        {
                            if (!this->shootingTurnStack[0])
                            {
                                param3 = param3 - 1;
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "levin")
                    {
                        if (param3 > 0)
                        {
                            if (!this->shootingTurnStack[3])
                            {
                                param3 = param3 - 1;
                                this->spheresStack.push(param2);
                                this->shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "getAll")
                    {
                        tempObject1 = this->spheresManage("scan");
                        if (tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            if (!this->shootingTurnStack[1])
                            {
                                this->spheresStack.push("fire");
                                this->shootingStackManage("add", "fire");
                            }
                            else
                            {
                                this->world->feature->getSphereBeat("fire", 1);
                                this->world->getSphere->setPosition(this->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                            if (!this->shootingTurnStack[3])
                            {
                                this->spheresStack.push("levin");
                                this->shootingStackManage("add", "levin");
                            }
                            else
                            {
                                this->world->feature->getSphereBeat("levin", 1);
                                this->world->getSphere->setPosition(this->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                            this->world->feature->getSphereBeat("ice", 1);
                            this->world->getSphere->setPosition(this->this_pt);
                            this->world->getSphere->retrieveGetSphere();
                            this->world->feature->getSphereBeat("stone", 1);
                            this->world->getSphere->setPosition(this->this_pt);
                            this->world->getSphere->retrieveGetSphere();
                        }
                        return param3;
                    }
                    else
                    {
                        return param3;
                    }
                }
            }
            else if (param1 == "get")
            {
                if (param2 == "fire")
                {
                    if (this->shootingTurnStack[0])
                    {
                        this->i = 0;
                        while (this->i < param3)
                        { 
                            if (this->shootingTurnStack[0])
                            {
                                this->i++;
                                this->shootingStackManage("remove", param2);
                                continue;
                            }
                            return this->i;
                        }
                        return this->i;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (param2 == "ice")
                {
                    if (this->shootingTurnStack[1])
                    {
                        this->i = 0;
                        while (this->i < param3)
                        { 
                            if (this->shootingTurnStack[1])
                            {
                                this->i++;
                                this->shootingStackManage("remove", param2);
                                continue;
                            }
                            return this->i;
                        }
                        return this->i;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (param2 == "stone")
                {
                    if (this->shootingTurnStack[2])
                    {
                        this->i = 0;
                        while (this->i < param3)
                        { 
                            if (this->shootingTurnStack[2])
                            {
                                this->i++;
                                this->shootingStackManage("remove", param2);
                                continue;
                            }
                            return this->i;
                        }
                        return this->i;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (param2 == "levin")
                {
                    if (this->shootingTurnStack[3])
                    {
                        this->i = 0;
                        while (this->i < param3)
                        { 
                            if (this->shootingTurnStack[3])
                            {
                                this->i++;
                                this->shootingStackManage("remove", param2);
                                continue;
                            }
                            return this->i;
                        }
                        return this->i;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            return;
        }// end function

        void shootingStackManage(string param1,string param2)
        {
            if (param1 == "add")
            {
                if (param2 == "fire")
                {
                    if (!this->shootingTurnStack[0])
                    {
                        this->shootingTurnStack[0][0] =param2;
                        this->shootingTurnStack[0][1] =Main::mainClass->readXMLClass.fireTowerIntervalXML;
                        this->shootingTurnStack[0][2] =Main::mainClass->readXMLClass.fireTowerIntervalXML;
                        this->shootingTurnStack[0][3] =1;
                      // [param2, Main::mainClass->readXMLClass.fireTowerIntervalXML, Main::mainClass->readXMLClass.fireTowerIntervalXML, 1];
                    }
                    else
                    {
                        this->shootingTurnStack[0][3]++;
                    }
                    this->shootingTurnStack[0][1] = Main::mainClass->readXMLClass.fireTowerIntervalXML - 10;
                }
                else if (param2 == "ice")
                {
                    if (!this->shootingTurnStack[1])
                    {
                        this->shootingTurnStack[1][0] =param2;
                        this->shootingTurnStack[1][1] =Main::mainClass->readXMLClass.iceTowerIntervalXML;
                        this->shootingTurnStack[1][2] =Main::mainClass->readXMLClass.iceTowerIntervalXML;
                        this->shootingTurnStack[1][3] =1;
                        //this->shootingTurnStack[1] = [param2, Main::mainClass->readXMLClass.iceTowerIntervalXML, Main::mainClass->readXMLClass.iceTowerIntervalXML, 1];
                    }
                    else
                    {
                        this->shootingTurnStack[1][3]++;
                    }
                    this->shootingTurnStack[1][1] = Main::mainClass->readXMLClass.iceTowerIntervalXML - 10;
                }
                else if (param2 == "stone")
                {
                if (!this->shootingTurnStack[2])
                {
                    this->shootingTurnStack[2][0] =param2;
                    this->shootingTurnStack[2][1] =Main::mainClass->readXMLClass.stoneTowerIntervalXML;
                    this->shootingTurnStack[2][2] =Main::mainClass->readXMLClass.stoneTowerIntervalXML;
                    this->shootingTurnStack[2][3] =1;
                    //this->shootingTurnStack[2] = [param2, Main::mainClass->readXMLClass.stoneTowerIntervalXML, Main::mainClass->readXMLClass.stoneTowerIntervalXML, 1];
                }
                else
                {
                  this->shootingTurnStack[2][3] ++;
                }
                this->shootingTurnStack[2][1] = Main::mainClass->readXMLClass.stoneTowerIntervalXML - 10;
                }
                else if (param2 == "levin")
                {
                    if (!this->shootingTurnStack[3])
                    {
                        this->shootingTurnStack[3][0] =param2;
                        this->shootingTurnStack[3][1] =Main::mainClass->readXMLClass.levinTowerIntervalXML;
                        this->shootingTurnStack[3][2] =Main::mainClass->readXMLClass.levinTowerIntervalXML;
                        this->shootingTurnStack[3][3] =1;
                      //this->shootingTurnStack[3] = [param2, Main::mainClass->readXMLClass.levinTowerIntervalXML, Main::mainClass->readXMLClass.levinTowerIntervalXML, 1];
                    }
                    else
                    {
                      this->shootingTurnStack[3][3]++;
                    }
                    this->shootingTurnStack[3][1] = Main::mainClass->readXMLClass.levinTowerIntervalXML - 10;
                }
                if (this->shootingTurnStack[0] && this->shootingTurnStack[1] && this->shootingTurnStack[2] && this->shootingTurnStack[3])
                {
                    this->shootingTurnStack[0][1] = std::round(this->shootingTurnStack[0][1] * 0.85);
                    this->shootingTurnStack[1][1] = std::round(this->shootingTurnStack[1][1] * 0.85);
                    this->shootingTurnStack[2][1] = std::round(this->shootingTurnStack[2][1] * 0.85);
                    this->shootingTurnStack[3][1] = std::round(this->shootingTurnStack[3][1] * 0.85);
                }
                else if (!this->shootingTurnStack[0] && this->shootingTurnStack[1] && this->shootingTurnStack[2] && this->shootingTurnStack[3] || this->shootingTurnStack[0] && !this->shootingTurnStack[1] && this->shootingTurnStack[2] && this->shootingTurnStack[3] || this->shootingTurnStack[0] && this->shootingTurnStack[1] && !this->shootingTurnStack[2] && this->shootingTurnStack[3] || this->shootingTurnStack[0] && this->shootingTurnStack[1] && this->shootingTurnStack[2] && !this->shootingTurnStack[3])
                {
                    if (this->shootingTurnStack[0])
                    {
                        this->shootingTurnStack[0][1] = std::round(this->shootingTurnStack[0][1] * 0.9);
                    }
                    if (this->shootingTurnStack[1])
                    {
                        this->shootingTurnStack[1][1] = std::round(this->shootingTurnStack[1][1] * 0.9);
                    }
                    if (this->shootingTurnStack[2])
                    {
                        this->shootingTurnStack[2][1] = std::round(this->shootingTurnStack[2][1] * 0.9);
                    }
                    if (this->shootingTurnStack[3])
                    {
                        this->shootingTurnStack[3][1] = std::round(this->shootingTurnStack[3][1] * 0.9);
                    }
                }
                else if (this->shootingTurnStack[0] && this->shootingTurnStack[1] && !this->shootingTurnStack[2] && !this->shootingTurnStack[3] || !this->shootingTurnStack[0] && this->shootingTurnStack[1] && this->shootingTurnStack[2] && !this->shootingTurnStack[3] || !this->shootingTurnStack[0] && !this->shootingTurnStack[1] && this->shootingTurnStack[2] && this->shootingTurnStack[3] || !this->shootingTurnStack[0] && this->shootingTurnStack[1] && !this->shootingTurnStack[2] && this->shootingTurnStack[3] || this->shootingTurnStack[0] && !this->shootingTurnStack[1] && this->shootingTurnStack[2] && !this->shootingTurnStack[3] || this->shootingTurnStack[0] && !this->shootingTurnStack[1] && !this->shootingTurnStack[2] && this->shootingTurnStack[3])
                {
                    if (this->shootingTurnStack[0])
                    {
                        this->shootingTurnStack[0][1] = std::round(this->shootingTurnStack[0][1] * 0.95);
                    }
                    if (this->shootingTurnStack[1])
                    {
                        this->shootingTurnStack[1][1] = std::round(this->shootingTurnStack[1][1] * 0.95);
                    }
                    if (this->shootingTurnStack[2])
                    {
                        this->shootingTurnStack[2][1] = std::round(this->shootingTurnStack[2][1] * 0.95);
                    }
                    if (this->shootingTurnStack[3])
                    {
                        this->shootingTurnStack[3][1] = std::round(this->shootingTurnStack[3][1] * 0.95);
                    }
                }
            }
            else if (param1 == "remove")
            {
                this->j = 0;
                while (this->j < this->shootingTurnStack.size())
                {
                    if (this->shootingTurnStack[this->j])
                    {
                        if (this->shootingTurnStack[this->j][0] == param2)
                        {
                            if (this->shootingTurnStack[this->j][3] > 1)
                            {
                                (this->shootingTurnStack[this->j][3] - 1);
                            }
                            else
                            {
                                this->shootingTurnStack[this->j] = NULL;
                            }
                            break;
                        }
                    }
                    j++;
                }
            }
            return;
        }// end function

        void prepareSpheresGraphic()
        {
          if (this->towerType >= 1)
          {
              this->container->sphere1->gotoAndStop(1);
              this->container->sphere1->bullet->gotoAndStop(1);
              this->container->sphere1->bullet->cont->gotoAndStop(1);
              this->container->sphere1->setVisible(false);
          }
          if (this->towerType >= 2)
          {
              this->container->sphere2_1->gotoAndStop(1);
              this->container->sphere2_2->gotoAndStop(24);
              this->container->sphere2_1->bullet->gotoAndStop(1);
              this->container->sphere2_2->bullet->gotoAndStop(1);
              this->container->sphere2_1->bullet->cont->gotoAndStop(1);
              this->container->sphere2_2->bullet->cont->gotoAndStop(1);
              this->container->sphere2_1->setVisible(false);
              this->container->sphere2_2->setVisible(false);
          }
          if (this->towerType >= 3)
          {
              this->container->sphere3_1->gotoAndStop(1);
              this->container->sphere3_2->gotoAndStop(18);
              this->container->sphere3_3->gotoAndStop(35);
              this->container->sphere3_1->bullet->gotoAndStop(1);
              this->container->sphere3_2->bullet->gotoAndStop(1);
              this->container->sphere3_3->bullet->gotoAndStop(1);
              this->container->sphere3_1->bullet->cont->gotoAndStop(1);
              this->container->sphere3_2->bullet->cont->gotoAndStop(1);
              this->container->sphere3_3->bullet->cont->gotoAndStop(1);
              this->container->sphere3_1->setVisible(false);
              this->container->sphere3_2->setVisible(false);
              this->container->sphere3_3->setVisible(false);
          }
          if (this->towerType == 4)
          {
              this->container->sphere4_1->gotoAndStop(1);
              this->container->sphere4_2->gotoAndStop(15);
              this->container->sphere4_3->gotoAndStop(29);
              this->container->sphere4_4->gotoAndStop(43);
              this->container->sphere4_1->bullet->gotoAndStop(1);
              this->container->sphere4_2->bullet->gotoAndStop(1);
              this->container->sphere4_3->bullet->gotoAndStop(1);
              this->container->sphere4_4->bullet->gotoAndStop(1);
              this->container->sphere4_1->bullet->cont->gotoAndStop(1);
              this->container->sphere4_2->bullet->cont->gotoAndStop(1);
              this->container->sphere4_3->bullet->cont->gotoAndStop(1);
              this->container->sphere4_4->bullet->cont->gotoAndStop(1);
              this->container->sphere4_1->setVisible(false);
              this->container->sphere4_2->setVisible(false);
              this->container->sphere4_3->setVisible(false);
              this->container->sphere4_4->setVisible(false);
          }
          if (this->towerType == 1)
          {
              if (this->spheresStack.size() == 1)
              {
                  this->prepareSpheresGraphicAid(1);
              }
          }
          else if (this->towerType == 2)
          {
              if (this->spheresStack.size() == 1)
              {
                  this->prepareSpheresGraphicAid(1);
              }
              else if (this->spheresStack.size() == 2)
              {
                  this->prepareSpheresGraphicAid(2);
              }
          }
          else if (this->towerType == 3)
          {
              if (this->spheresStack.size() == 1)
              {
                  this->prepareSpheresGraphicAid(1);
              }
              else if (this->spheresStack.size() == 2)
              {
                  this->prepareSpheresGraphicAid(2);
              }
              else if (this->spheresStack.size() == 3)
              {
                  this->prepareSpheresGraphicAid(3);
              }
          }
          else if (this->towerType == 4)
          {
              if (this->spheresStack.size() == 1)
              {
                  this->prepareSpheresGraphicAid(1);
              }
              else if (this->spheresStack.size() == 2)
              {
                  this->prepareSpheresGraphicAid(2);
              }
              else if (this->spheresStack.size() == 3)
              {
                  this->prepareSpheresGraphicAid(3);
              }
              else if (this->spheresStack.size() == 4)
              {
                  this->prepareSpheresGraphicAid(4);
              }
          }
          return;
        }// end function

        void prepareSpheresGraphicAid(int param1) 
        {
          if (param1 == 1)
          {
              this->container->sphere1->gotoAndStop(1);
              this->container->sphere1->setVisible(true);
              if (this->spheresStack[0] == "fire")
              {
                  this->container->sphere1->bullet->gotoAndStop(1);
                  this->container->sphere1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "ice")
              {
                  this->container->sphere1->bullet->gotoAndStop(2);
                  this->container->sphere1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "stone")
              {
                  this->container->sphere1->bullet->gotoAndStop(3);
                  this->container->sphere1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "levin")
              {
                  this->container->sphere1->bullet->gotoAndStop(4);
                  this->container->sphere1->bullet->cont->gotoAndStop(1);
              }
          }
          else if (param1 == 2)
          {
              this->container->sphere2_1->gotoAndStop(1);
              this->container->sphere2_1->setVisible(true);
              if (this->spheresStack[0] == "fire")
              {
                  this->container->sphere2_1->bullet->gotoAndStop(1);
                  this->container->sphere2_1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "ice")
              {
                  this->container->sphere2_1->bullet->gotoAndStop(2);
                  this->container->sphere2_1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "stone")
              {
                  this->container->sphere2_1->bullet->gotoAndStop(3);
                  this->container->sphere2_1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "levin")
              {
                  this->container->sphere2_1->bullet->gotoAndStop(4);
                  this->container->sphere2_1->bullet->cont->gotoAndStop(1);
              }
              this->container->sphere2_2->gotoAndStop(23);
              this->container->sphere2_2->setVisible(true);
              if (this->spheresStack[1] == "fire")
              {
                  this->container->sphere2_2->bullet->gotoAndStop(1);
                  this->container->sphere2_2->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[1] == "ice")
              {
                  this->container->sphere2_2->bullet->gotoAndStop(2);
                  this->container->sphere2_2->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[1] == "stone")
              {
                  this->container->sphere2_2->bullet->gotoAndStop(3);
                  this->container->sphere2_2->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[1] == "levin")
              {
                  this->container->sphere2_2->bullet->gotoAndStop(4);
                  this->container->sphere2_2->bullet->cont->gotoAndStop(1);
              }
          }
          else if (param1 == 3)
          {
              this->container->sphere3_1->gotoAndStop(1);
              this->container->sphere3_1->setVisible(true);
              if (this->spheresStack[0] == "fire")
              {
                  this->container->sphere3_1->bullet->gotoAndStop(1);
                  this->container->sphere3_1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "ice")
              {
                  this->container->sphere3_1->bullet->gotoAndStop(2);
                  this->container->sphere3_1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "stone")
              {
                  this->container->sphere3_1->bullet->gotoAndStop(3);
                  this->container->sphere3_1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "levin")
              {
                  this->container->sphere3_1->bullet->gotoAndStop(4);
                  this->container->sphere3_1->bullet->cont->gotoAndStop(1);
              }
              this->container->sphere3_2->gotoAndStop(17);
              this->container->sphere3_2->setVisible(true);
              if (this->spheresStack[1] == "fire")
              {
                  this->container->sphere3_2->bullet->gotoAndStop(1);
                  this->container->sphere3_2->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[1] == "ice")
              {
                  this->container->sphere3_2->bullet->gotoAndStop(2);
                  this->container->sphere3_2->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[1] == "stone")
              {
                  this->container->sphere3_2->bullet->gotoAndStop(3);
                  this->container->sphere3_2->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[1] == "levin")
              {
                  this->container->sphere3_2->bullet->gotoAndStop(4);
                  this->container->sphere3_2->bullet->cont->gotoAndStop(1);
              }
              this->container->sphere3_3->gotoAndStop(34);
              this->container->sphere3_3->setVisible(true);
              if (this->spheresStack[2] == "fire")
              {
                  this->container->sphere3_3->bullet->gotoAndStop(1);
                  this->container->sphere3_3->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[2] == "ice")
              {
                  this->container->sphere3_3->bullet->gotoAndStop(2);
                  this->container->sphere3_3->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[2] == "stone")
              {
                  this->container->sphere3_3->bullet->gotoAndStop(3);
                  this->container->sphere3_3->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[2] == "levin")
              {
                  this->container->sphere3_3->bullet->gotoAndStop(4);
                  this->container->sphere3_3->bullet->cont->gotoAndStop(1);
              }
          }
          else if (param1 == 4)
          {
              this->container->sphere4_1->gotoAndStop(1);
              this->container->sphere4_1->setVisible(true);
              if (this->spheresStack[0] == "fire")
              {
                  this->container->sphere4_1->bullet->gotoAndStop(1);
                  this->container->sphere4_1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "ice")
              {
                  this->container->sphere4_1->bullet->gotoAndStop(2);
                  this->container->sphere4_1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "stone")
              {
                  this->container->sphere4_1->bullet->gotoAndStop(3);
                  this->container->sphere4_1->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[0] == "levin")
              {
                  this->container->sphere4_1->bullet->gotoAndStop(4);
                  this->container->sphere4_1->bullet->cont->gotoAndStop(1);
              }
              this->container->sphere4_2->gotoAndStop(14);
              this->container->sphere4_2->setVisible(true);
              if (this->spheresStack[1] == "fire")
              {
                  this->container->sphere4_2->bullet->gotoAndStop(1);
                  this->container->sphere4_2->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[1] == "ice")
              {
                  this->container->sphere4_2->bullet->gotoAndStop(2);
                  this->container->sphere4_2->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[1] == "stone")
              {
                  this->container->sphere4_2->bullet->gotoAndStop(3);
                  this->container->sphere4_2->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[1] == "levin")
              {
                  this->container->sphere4_2->bullet->gotoAndStop(4);
                  this->container->sphere4_2->bullet->cont->gotoAndStop(1);
              }
              this->container->sphere4_3->gotoAndStop(28);
              this->container->sphere4_3->setVisible(true);
              if (this->spheresStack[2] == "fire")
              {
                  this->container->sphere4_3->bullet->gotoAndStop(1);
                  this->container->sphere4_3->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[2] == "ice")
              {
                  this->container->sphere4_3->bullet->gotoAndStop(2);
                  this->container->sphere4_3->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[2] == "stone")
              {
                  this->container->sphere4_3->bullet->gotoAndStop(3);
                  this->container->sphere4_3->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[2] == "levin")
              {
                  this->container->sphere4_3->bullet->gotoAndStop(4);
                  this->container->sphere4_3->bullet->cont->gotoAndStop(1);
              }
              this->container->sphere4_4->gotoAndStop(42);
              this->container->sphere4_4->setVisible(true);
              if (this->spheresStack[3] == "fire")
              {
                  this->container->sphere4_4->bullet->gotoAndStop(1);
                  this->container->sphere4_4->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[3] == "ice")
              {
                  this->container->sphere4_4->bullet->gotoAndStop(2);
                  this->container->sphere4_4->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[3] == "stone")
              {
                  this->container->sphere4_4->bullet->gotoAndStop(3);
                  this->container->sphere4_4->bullet->cont->gotoAndStop(1);
              }
              else if (this->spheresStack[3] == "levin")
              {
                  this->container->sphere4_4->bullet->gotoAndStop(4);
                  this->container->sphere4_4->bullet->cont->gotoAndStop(1);
              }
          }
          return;
        }// end function

        void addBuildAnima() 
        {
          if (!this->buildAnima)
          {
              this->buildAnima = new MovieClip("tower/","BuildTowerSmoke_mc","BuildTowerSmoke_mc");// BuildTowerSmoke_mc();
              this->buildAnima->stop();
              this->buildAnima->setPositionY(5); 
              this->buildAnima->mouseChildren = false;
              this->buildAnima->mouseEnabled = false;
              this->addChild(this->buildAnima);
          }
          else
          {
              this->buildAnima->gotoAndStop(1);
          }
          return;
        }// end function

        void blockTowerFunk() 
        {
          if (this->container->boneBlock->isVisible())
          {
              if (this->blockTowerFlag)
              {
              }
              else if (this->container->boneBlock->currentFrame < 11)
              {
                  this->container->boneBlock->gotoAndStop((this->container->boneBlock->currentFrame + 1));
              }
              else
              {
                  this->blockTowerFlag = true;
              }
          }
          else if (this->container->blockTower->isVisible())
          {
              if (this->blockTowerFlag)
              {
                  if (this->world->frameCounter == 10 || this->world->frameCounter == 20 || this->world->frameCounter == 30)
                  {
                      bool tempObject = false;
                      this->i = 0;
                      while (this->i < this->world->listOfUnits.size())
                      { 
                          if (this->world->listOfUnits[this->i]->typeUnit == 22)
                          {
                              if (this->world->listOfUnits[this->i]->readyDamage && this->world->listOfUnits[this->i]->atStage && !this->world->listOfUnits[this->i]->icemanFlag && !this->world->listOfUnits[this->i]->airShockFlag)
                              {
                                  if (Point.distance(this->this_pt, this->world->listOfUnits[this->i]->this_pt) < this->world->listOfUnits[this->i]->blockTowerRadius)
                                  {
                                      tempObject = true;
                                      break;
                                  }
                              }
                          }
                          i++;
                      }
                      if (!this->tempObject)
                      {
                          blockTowerFlag = false;
                      }
                  }
                  if (this->container->blockTower->currentFrame < this->container->blockTower->totalFrames)
                  {
                      this->container->blockTower->gotoAndStop((this->container->blockTower->currentFrame + 1));
                  }
                  else
                  {
                      this->container->blockTower->gotoAndStop(21);
                  }
              }
              else if (this->container->blockTower->currentFrame > 20)
              {
                  if (this->container->blockTower->currentFrame < this->container->blockTower->totalFrames)
                  {
                      this->container->blockTower->gotoAndStop((this->container->blockTower->currentFrame + 1));
                  }
                  else
                  {
                      this->container->blockTower->gotoAndStop(20);
                  }
              }
              else if (this->container->blockTower->currentFrame > 1)
              {
                  this->container->blockTower->gotoAndStop((this->container->blockTower->currentFrame - 1));
              }
              else
              {
                  this->container->blockTower->setVisible(false); 
                  this->mouseChildren = true;
                  this->mouseEnabled = true;
              }
          }
          return;
        }// end function

        void scanBlock() 
        {
          this->listOfTargets.clear();// = [];
          this->scanAndPush();
          this->enemyTarget = NULL;
          Unit * tempObject =NULL;
          float tempObject1 = 0;
          if (this->world->nowLevel == 3)
          {
              this->i = 0;
              while (this->i < this->listOfTargets.size())
              { 
                  tempObject = this->listOfTargets[this->i];
                  tempObject->resLen1 = false;
                  if (tempObject->road == 1)
                  {
                      if ( tempObject->way == 1)
                      {
                          if ( tempObject->path > 855)
                          {
                              tempObject1 = 855;
                          }
                      }
                      else if ( tempObject->way == 2)
                      {
                          if ( tempObject->path > 827)
                          {
                              tempObject1 = 827;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 844)
                          {
                              tempObject1 = 844;
                          }
                      }
                  }
                  else if (tempObject->road == 2)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 515)
                          {
                              tempObject1 = 515;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 474)
                          {
                              tempObject1 = 474;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 501)
                          {
                              tempObject1 = 501;
                          }
                      }
                  }
                  if (tempObject1 > 0)
                  {
                      tempObject->resFlag = true;
                      tempObject->resLen = (tempObject->path - tempObject1)  / (tempObject->finishPath - tempObject1);
                      if (this->enemyTarget)
                      {
                          if (this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                          else
                          {
                              this->enemyTarget = tempObject;
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  else
                  {
                      tempObject->resLen = tempObject->path / tempObject->finishPath;
                      if (this->enemyTarget)
                      {
                          if (!this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  i++;
              }
          }
          else if (this->world->nowLevel == 5)
          {
              this->i = 0;
              while (this->i < this->listOfTargets.size())
              { 
                  tempObject = this->listOfTargets[this->i];
                  tempObject->resLen1 = false;
                  tempObject1 = 0;
                  if (tempObject->road == 1)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 1006)
                          {
                              tempObject1 = 1006;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 990)
                          {
                              tempObject1 = 990;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 1016)
                          {
                              tempObject1 = 1016;
                          }
                      }
                  }
                  else if (tempObject->road == 2)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 969)
                          {
                              tempObject1 = 969;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 882)
                          {
                              tempObject1 = 882;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 922)
                          {
                              tempObject1 = 922;
                          }
                      }
                  }
                  if (tempObject1 > 0)
                  {
                      tempObject->resLen1 = true;
                      tempObject->resLen = (tempObject->path - tempObject1)  / (tempObject->finishPath - tempObject1);
                      if (this->enemyTarget)
                      {
                          if (this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                          else
                          {
                              this->enemyTarget = tempObject;
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  else
                  {
                      tempObject->resLen = tempObject->path / tempObject->finishPath;
                      if (this->enemyTarget)
                      {
                          if (!this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  i++;
              }
          }
          else if (this->world->nowLevel == 6)
          {
              this->i = 0;
              while (this->i < this->listOfTargets.size())
              { 
                  tempObject = this->listOfTargets[this->i];
                  tempObject->resLen1 = false;
                  tempObject1 = 0;
                  if (tempObject->road == 1)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 696)
                          {
                              tempObject1 = 696;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 691)
                          {
                              tempObject1 = 691;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 689)
                          {
                              tempObject1 = 689;
                          }
                      }
                  }
                  else if (tempObject->road == 2)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 686)
                          {
                              tempObject1 = 686;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 770)
                          {
                              tempObject1 = 770;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 733)
                          {
                              tempObject1 = 733;
                          }
                      }
                  }
                  if (tempObject1 > 0)
                  {
                      tempObject->resLen1 = true;
                      tempObject->resLen = (tempObject->path - tempObject1) / (tempObject->finishPath - tempObject1);
                      if (this->enemyTarget)
                      {
                          if (this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                          else
                          {
                              this->enemyTarget = tempObject;
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  else
                  {
                      tempObject->resLen = tempObject->path / tempObject->finishPath;
                      if (this->enemyTarget)
                      {
                          if (!this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  i++;
              }
          }
          else if (this->world->nowLevel == 8)
          {
              this->i = 0;
              while (this->i < this->listOfTargets.size())
              { 
                  tempObject = this->listOfTargets[this->i];
                  tempObject->resLen1 = false;
                  tempObject1 = 0;
                  if (tempObject->road == 1)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 393)
                          {
                              tempObject1 = 393;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 427)
                          {
                              tempObject1 = 427;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 414)
                          {
                              tempObject1 = 414;
                          }
                      }
                  }
                  else if (tempObject->road == 2)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 1053)
                          {
                              tempObject1 = 1053;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 1048)
                          {
                              tempObject1 = 1048;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 1056)
                          {
                              tempObject1 = 1056;
                          }
                      }
                  }
                  if (tempObject1 > 0)
                  {
                      tempObject->resLen1 = true;
                      tempObject->resLen = (tempObject->path - tempObject1 ) / (tempObject->finishPath - tempObject1) ;
                      if (this->enemyTarget)
                      {
                          if (this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                          else
                          {
                              this->enemyTarget = tempObject;
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  else
                  {
                      tempObject->resLen = tempObject->path / tempObject->finishPath;
                      if (this->enemyTarget)
                      {
                          if (!this->enemyTarget->resFlag-)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  i++;
              }
          }
          else if (this->world->nowLevel == 11)
          {
              this->i = 0;
              while (this->i < this->listOfTargets.size())
              { 
                  tempObject = this->listOfTargets[this->i];
                  tempObject->resLen1 = false;
                  tempObject1 = 0;
                  if (tempObject->road == 1)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 849)
                          {
                              tempObject1 = 849;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 851)
                          {
                              tempObject1 = 851;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 847)
                          {
                              tempObject1 = 847;
                          }
                      }
                  }
                  else if (tempObject->road == 2)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 636)
                          {
                              tempObject1 = 636;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 696)
                          {
                              tempObject1 = 696;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 662)
                          {
                              tempObject1 = 662;
                          }
                      }
                  }
                  if (tempObject1 > 0)
                  {
                      tempObject->resLen1 = true;
                      tempObject->resLen = (tempObject->path - tempObject1 ) / (tempObject->finishPath - tempObject1 );
                      if (this->enemyTarget)
                      {
                          if (this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                          else
                          {
                              this->enemyTarget = tempObject;
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  else
                  {
                      tempObject->resLen = tempObject->path / tempObject->finishPath;
                      if (this->enemyTarget)
                      {
                          if (!this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  i++;
              }
          }
          else if (this->world->nowLevel == 12)
          {
              this->i = 0;
              while (this->i < this->listOfTargets.size())
              { 
                  tempObject = this->listOfTargets[this->i];
                  tempObject->resLen1 = false;
                  tempObject1 = 0;
                  if (tempObject->road == 1)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 756)
                          {
                              tempObject1 = 756;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 756)
                          {
                              tempObject1 = 756;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 741)
                          {
                              tempObject1 = 741;
                          }
                      }
                  }
                  else if (tempObject->road == 2)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 1855)
                          {
                              tempObject1 = 1855;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 1828)
                          {
                              tempObject1 = 1828;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 1817)
                          {
                              tempObject1 = 1817;
                          }
                      }
                  }
                  if (tempObject1 > 0)
                  {
                      tempObject->resLen1 = true;
                      tempObject->resLen = (tempObject->path - tempObject1 ) / (tempObject->finishPath - tempObject1 );
                      if (this->enemyTarget)
                      {
                          if (this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                          else
                          {
                              this->enemyTarget = tempObject;
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  else
                  {
                      tempObject->resLen = tempObject->path / tempObject->finishPath;
                      if (this->enemyTarget)
                      {
                          if (!this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  i++;
              }
          }
          else if (this->world->nowLevel == 13)
          {
              this->i = 0;
              while (this->i < this->listOfTargets.size())
              { 
                  tempObject = this->listOfTargets[this->i];
                  tempObject->resLen1 = false;
                  tempObject1 = 0;
                  if (tempObject->road == 1)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 1617)
                          {
                              tempObject1 = 1617;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 1582)
                          {
                              tempObject1 = 1582;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 1589)
                          {
                              tempObject1 = 1589;
                          }
                      }
                  }
                  else if (tempObject->road == 2)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 235)
                          {
                              tempObject1 = 235;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 193)
                          {
                              tempObject1 = 193;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 208)
                          {
                              tempObject1 = 208;
                          }
                      }
                  }
                  if (tempObject1 > 0)
                  {
                      tempObject->resLen1 = true;
                      tempObject->resLen = (tempObject->path - tempObject1)  / (tempObject->finishPath - tempObject1 );
                      if (this->enemyTarget)
                      {
                          if (this->enemyTarget->resFlag 
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                          else
                          {
                              this->enemyTarget = tempObject;
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  else
                  {
                      tempObject->resLen = tempObject->path / tempObject->finishPath;
                      if (this->enemyTarget)
                      {
                          if (!this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  i++;
              }
          }
          else if (this->world->nowLevel == 14)
          {
              this->i = 0;
              while (this->i < this->listOfTargets.size())
              { 
                  tempObject = this->listOfTargets[this->i];
                  tempObject->resLen1 = false;
                  tempObject1 = 0;
                  if (tempObject->road == 1)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 1413)
                          {
                              tempObject1 = 1413;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 1340)
                          {
                              tempObject1 = 1340;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 1365)
                          {
                              tempObject1 = 1365;
                          }
                      }
                  }
                  else if (tempObject->road == 2)
                  {
                      if (tempObject->way == 1)
                      {
                          if (tempObject->path > 380)
                          {
                              tempObject1 = 380;
                          }
                      }
                      else if (tempObject->way == 2)
                      {
                          if (tempObject->path > 397)
                          {
                              tempObject1 = 397;
                          }
                      }
                      else if (tempObject->way == 3)
                      {
                          if (tempObject->path > 380)
                          {
                              tempObject1 = 380;
                          }
                      }
                  }
                  if (tempObject1 > 0)
                  {
                      tempObject->resLen1 = true;
                      tempObject->resLen = (tempObject->path - tempObject1)  / (tempObject->finishPath - tempObject1) ;
                      if (this->enemyTarget)
                      {
                          if (this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                          else
                          {
                              this->enemyTarget = tempObject;
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  else
                  {
                      tempObject->resLen = tempObject->path / tempObject->finishPath;
                      if (this->enemyTarget)
                      {
                          if (!this->enemyTarget->resFlag)
                          {
                              if (tempObject->resLen > this->enemyTarget->resLen)
                              {
                                  this->enemyTarget = tempObject;
                              }
                          }
                      }
                      else
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  i++;
              }
          }
          else
          {
              this->i = 0;
              while (this->i < this->listOfTargets.size())
              { 
                  tempObject = this->listOfTargets[this->i];
                  tempObject->resLen = tempObject->path / tempObject->finishPath;
                  if (this->enemyTarget)
                  {
                      if (tempObject->resLen > this->enemyTarget->resLen)
                      {
                          this->enemyTarget = tempObject;
                      }
                  }
                  else
                  {
                      this->enemyTarget = tempObject;
                  }
                  i++;
              }
          }
          tempObject = NULL;
          this->i = 0;
          while (this->i < this->listOfTargets.size())
          { 
              if (this->listOfTargets[this->i]->road == this->enemyTarget->road && this->listOfTargets[this->i]->direction == this->enemyTarget->direction)
              {
                  if (this->listOfTargets[this->i] != this->enemyTarget)
                  {
                      if (this->enemyTarget->direction == "left")
                      {
                          if (!tempObject)
                          {
                              if (this->enemyTarget->getPositionX() > this->listOfTargets[this->i]->getPositionX())
                              {
                                  tempObject = this->listOfTargets[this->i];
                              }
                          }
                          else if (tempObject->getPositionX() > this->listOfTargets[this->i]->getPositionX())
                          {
                              tempObject = this->listOfTargets[this->i];
                          }
                      }
                      else if (this->enemyTarget->direction == "right")
                      {
                          if (!tempObject)
                          {
                              if (this->enemyTarget->getPositionX() < this->listOfTargets[this->i]->getPositionX())
                              {
                                  tempObject = this->listOfTargets[this->i];
                              }
                          }
                          else if (tempObject->getPositionX() < this->listOfTargets[this->i]->getPositionX())
                          {
                              tempObject = this->listOfTargets[this->i];
                          }
                      }
                      else if (this->enemyTarget->direction == "up")
                      {
                          if (!tempObject)
                          {
                              if (this->enemyTarget->getPositionY() > this->listOfTargets[this->i]->getPositionY())
                              {
                                  tempObject = this->listOfTargets[this->i];
                              }
                          }
                          else if (tempObject->getPositionY() > this->listOfTargets[this->i]->getPositionY())
                          {
                              tempObject = this->listOfTargets[this->i];
                          }
                      }
                      else if (this->enemyTarget->direction == "down")
                      {
                          if (!tempObject)
                          {
                              if (this->enemyTarget->getPositionY() < this->listOfTargets[this->i]->getPositionY())
                              {
                                  tempObject = this->listOfTargets[this->i];
                              }
                          }
                          else if (tempObject->getPositionY() < this->listOfTargets[this->i]->getPositionY())
                          {
                              tempObject = this->listOfTargets[this->i];
                          }
                      }
                  }
              }
              i++;
          }
          if (tempObject)
          {
              this->enemyTarget = tempObject;
          }
          return;
        }// end function

        void scanAndPush() 
        {
          this->i = 0;
          while (this->i < this->world->listOfUnits.size())
          { 
              if (this->world->listOfUnits[this->i]->atStaged && this->world->listOfUnits[this->i]->readyDamage && !this->world->listOfUnits[this->i]->airFlag)
              {
                  this->testTarget = this->world->listOfUnits[this->i]->shoot_pt;
                  this->scanAtRadius();
                  if (this->greenFlag)
                  {
                      this->listOfTargets.push(this->world->listOfUnits[this->i]);
                  }
              }
              i++;
          }
          return;
        }// end function

        void towerGetSphereManage(string param1,string param2)
        {
          if (param1 == "get")
          {
              if (param2 == "fire")
              {
                  if (this->shootingTurnStack[0])
                  {
                      if (!this->world->getSphere)
                      {
                          this->spheresManage("get", "fire", 1);
                          this->world->getSphere = new GetSphere();
                          this->world->getSphere->ownerType = "archive";
                          this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
                          this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphere->myPoint;
                          this->world->addChild(this->world->getSphere);
                          this->world->getSphere->manage("add", "fire");
                      }
                      else if (this->world->getSphere->listOfStack.size() < 4)
                      {
                          this->spheresManage("get", "fire", 1);
                          this->world->getSphere->manage("add", "fire");
                      }
                  }
              }
              else if (param2 == "ice")
              {
                  if (this->shootingTurnStack[1])
                  {
                      if (!this->world->getSphere)
                      {
                          this->spheresManage("get", "ice", 1);
                          this->world->getSphere = new GetSphere();
                          this->world->getSphere->ownerType = "archive";
                          this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
                          this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphere->myPoint;
                          this->world->addChild(this->world->getSphere);
                          this->world->getSphere->manage("add", "ice");
                      }
                      else if (this->world->getSphere->listOfStack.size() < 4)
                      {
                          this->spheresManage("get", "ice", 1);
                          this->world->getSphere->manage("add", "ice");
                      }
                  }
              }
              else if (param2 == "stone")
              {
                  if (this->shootingTurnStack[2])
                  {
                      if (!this->world->getSphere)
                      {
                          this->spheresManage("get", "stone", 1);
                          this->world->getSphere = new GetSphere();
                          this->world->getSphere->ownerType = "archive";
                          this->world->getSphere->owner = this->world->worldInterface->container->stoneSphere;
                          this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphere->myPoint;
                          this->world->addChild(this->world->getSphere);
                          this->world->getSphere->manage("add", "stone");
                      }
                      else if (this->world->getSphere->listOfStack.size() < 4)
                      {
                          this->spheresManage("get", "stone", 1);
                          this->world->getSphere->manage("add", "stone");
                      }
                  }
              }
              else if (param2 == "levin")
              {
                  if (this->shootingTurnStack[3])
                  {
                      if (!this->world->getSphere)
                      {
                          this->spheresManage("get", "levin", 1);
                          this->world->getSphere = new GetSphere();
                          this->world->getSphere->ownerType = "archive";
                          this->world->getSphere->owner = this->world->worldInterface->container->levinSphere;
                          this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphere->myPoint;
                          this->world->addChild(this->world->getSphere);
                          this->world->getSphere->manage("add", "levin");
                      }
                      else if (this->world->getSphere->listOfStack.size() < 4)
                      {
                          this->spheresManage("get", "levin", 1);
                          this->world->getSphere->manage("add", "levin");
                      }
                  }
              }
              else if (param2 == "getAll")
              {
                  if (this->spheresStack.size() > 0)
                  {
                      if (!this->world->getSphere)
                      {
                          this->world->getSphere = new GetSphere();
                          this->world->getSphere->ownerType = "archive";
                          this->world->getSphere->owner = this->world->worldInterface->container->getAll;
                          this->world->getSphere->ownerPoint = this->world->worldInterface->container->getAll->myPoint;
                          this->world->addChild(this->world->getSphere);
                          while (this->spheresStack.size() > 0)
                          {
                              
                              if (this->spheresStack[0] == "fire")
                              {
                                  this->spheresManage("get", "fire", 1);
                                  this->world->getSphere->manage("add", "fire");
                                  continue;
                              }
                              if (this->spheresStack[0] == "ice")
                              {
                                  this->spheresManage("get", "ice", 1);
                                  this->world->getSphere->manage("add", "ice");
                                  continue;
                              }
                              if (this->spheresStack[0] == "stone")
                              {
                                  this->spheresManage("get", "stone", 1);
                                  this->world->getSphere->manage("add", "stone");
                                  continue;
                              }
                              if (this->spheresStack[0] == "levin")
                              {
                                  this->spheresManage("get", "levin", 1);
                                  this->world->getSphere->manage("add", "levin");
                              }
                          }
                      }
                  }
              }
              this->world->worldInterface->updateInfo();
          }
          return;
        }// end function

        void kill() 
        {
          if (!this->dead)
          {
              this->dead = true;
              this->i = 0;
              while (this->i < this->world->listOfTowers.size())
              { 
                  if (this->world->listOfTowers[this->i] == this)
                  {
                      this->world->removeChild(this);
                      this->world->listOfTowers.splice(this->i, 1);
                      break;
                  }
                  i++;
              }
          }
          return;
        }// end function
   	}
}