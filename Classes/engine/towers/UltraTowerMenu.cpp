﻿#include "UltraTowerMenu.h"
#include "engine/World.h"

namespace engine
{
    namespace towers
    { 
    	UltraTowerMenu::UltraTowerMenu(Tower *param1)
        {
            //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            this->myTower = param1;
            return;
        }// end function
        bool UltraTowerMenu::init()
        {
            //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
            this->world = Main::mainClass->worldClass;
            if (this->world->towerRadius->isVisible())
            {
                this->world->towerRadius->setVisible(false);
            }
            this->mouseChildren = false;
            this->mouseEnabled = false;
            this->setPosition(this->myTower->this_pt);
            //this->x = this->myTower->this_pt.x;
            //this->y = this->myTower->this_pt.y;
            this->towerRadius = new TowerRadius_mc();
            //this->towerRadius->stop();
            this->towerRadius->setContentSize(Size(this->myTower->radius * 2, this->myTower->radius * 2 * this->world->scaleRadius));
            //this->towerRadius->width = this->myTower->radius * 2;
            //this->towerRadius->height = this->myTower->radius * 2 * this->world->scaleRadius;
            this->towerRadius->mouseChildren = false;
            this->towerRadius->mouseEnabled = false;
            this->addChild(this->towerRadius);
            this->container = new UltraTowerMenu_mc();
            this->container->stop();
            this->container->btnUpgradeMenu->stop();
            this->container->sphereSlot1->stop();
            this->container->sphereSlot2->stop();
            this->container->sphereSlot1SphereAnima->stop();
            this->container->sphereSlot2SphereAnima->stop();
            this->container->sphereSlot1SphereAnimaCont->stop();
            this->container->sphereSlot2SphereAnimaCont->stop();
            this->container->sellUltraTower->stop();
            this->container->sellUltraTowerSellUltraTowerCase->stop();
            this->container->sellUltraTowerSellUltraTowerCase->buttonMode = true;
            this->addChild(this->container);
            this->world->listOfClasses.push(this);
            if (this->myTower->upgradeTypeAdd == 1)
            {
                this->container->sphereSlot1->setVisible(false);
                this->container->sphereSlot2->setVisible(false);
            }
            this->fastBuyUltraManage(); 
            this->myTower->mouseChildren = false;
            this->myTower->mouseEnabled = false;
            this->world->worldInterface->barInfoManage(this);
            if (!this->hint)
            {
                this->hint = new UltraTowerMenuHint_mc();
                this->hint->stop(); 
                this->hint->mouseChildren = false;
                this->hint->mouseEnabled = false;
                this->hint->setVisible(false);
                this->world->addChild(this->hint);
            }
            this->world->worldInterface->updateInfo();
            return true;
        }// end function
        void UltraTowerMenu::update(float dt)
        {
            if (this->closeFlag)
            {
                this->kill();
            }
            else if (this->openFlag)
            {
                if (this->container->getScaleX() < 1)
                {
					this->container->setScaleX(this->container->getScaleX() + 0.2);//scaleX = this->container->scaleX + 0.2;
					this->container->setScaleY(this->container->getScaleY() + 0.2);//scaleY = this->container->scaleY + 0.2;
                }
                else
                {
                    this->openFlag = false; 
                    this->container->setScaleY(1);//scaleY = 1;
                    this->container->setScaleX(1);//scaleX = 1; 
                    this->mouseChildren = true;
                    this->mouseEnabled = true;
                    this->autoguidersButtons();
                }
            }
            else
            {
                if (this->container->sphereSlot1SphereAnima->isVisible())
                {
                    if (this->container->sphereSlot1SphereAnima->currentFrame == 1)
                    {
                        if (this->container->sphereSlot1SphereAnimaCont->currentFrame < this->container->sphereSlot1SphereAnimaCont->totalFrames)
                        {
                            this->container->sphereSlot1SphereAnimaCont->gotoAndStop((this->container->sphereSlot1SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            this->container->sphereSlot1SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (this->container->sphereSlot1SphereAnima->currentFrame == 2)
                    {
                        if (this->container->sphereSlot1SphereAnimaCont->currentFrame < this->container->sphereSlot1SphereAnimaCont->totalFrames)
                        {
                            this->container->sphereSlot1SphereAnimaCont->gotoAndStop((this->container->sphereSlot1SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            this->container->sphereSlot1SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (this->container->sphereSlot1SphereAnima->currentFrame == 3)
                    {
                        if (this->container->sphereSlot1SphereAnimaCont->currentFrame < this->container->sphereSlot1SphereAnimaCont->totalFrames)
                        {
                            this->container->sphereSlot1SphereAnimaCont->gotoAndStop((this->container->sphereSlot1SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            this->container->sphereSlot1SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (this->container->sphereSlot1SphereAnima->currentFrame == 4)
                    {
                        if (this->container->sphereSlot1SphereAnimaCont->currentFrame < this->container->sphereSlot1SphereAnimaCont->totalFrames)
                        {
                            this->container->sphereSlot1SphereAnimaCont->gotoAndStop((this->container->sphereSlot1SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            this->container->sphereSlot1SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                }
                if (this->container->sphereSlot2SphereAnima->isVisible())
                {
                    if (this->container->sphereSlot2SphereAnima->currentFrame == 1)
                    {
                        if (this->container->sphereSlot2SphereAnimaCont->currentFrame < this->container->sphereSlot2SphereAnimaCont->totalFrames)
                        {
                            this->container->sphereSlot2SphereAnimaCont->gotoAndStop((this->container->sphereSlot2SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            this->container->sphereSlot2SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (this->container->sphereSlot2SphereAnima->currentFrame == 2)
                    {
                        if (this->container->sphereSlot2SphereAnimaCont->currentFrame < this->container->sphereSlot2SphereAnimaCont->totalFrames)
                        {
                            this->container->sphereSlot2SphereAnimaCont->gotoAndStop((this->container->sphereSlot2SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            this->container->sphereSlot2SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (this->container->sphereSlot2SphereAnima->currentFrame == 3)
                    {
                        if (this->container->sphereSlot2SphereAnimaCont->currentFrame < this->container->sphereSlot2SphereAnimaCont->totalFrames)
                        {
                            this->container->sphereSlot2SphereAnimaCont->gotoAndStop((this->container->sphereSlot2SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            this->container->sphereSlot2SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (this->container->sphereSlot2SphereAnima->currentFrame == 4)
                    {
                        if (this->container->sphereSlot2SphereAnimaCont->currentFrame < this->container->sphereSlot2SphereAnimaCont->totalFrames)
                        {
                            this->container->sphereSlot2SphereAnimaCont->gotoAndStop((this->container->sphereSlot2SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            this->container->sphereSlot2SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                }
                if (this->myTower->this_pt.distance(cocos2d::Point(this->world->mouseX, this->world->mouseY)) > 75)
                {
                    if (this->mouseEnabled)
                    { 
                        this->mouseChildren = false;
                        this->mouseEnabled = false;
                    }
                }
                else if (!this->mouseEnabled)
                { 
                    this->mouseChildren = true;
                    this->mouseEnabled = true;
                }
                if (this->closeFastBuyUltraFlag)
                {
                    if (this->container->fastBuyUltraCont->currentFrame > 1)
                    {
                        this->container->fastBuyUltraCont->gotoAndStop((this->container->fastBuyUltraCont->currentFrame - 1));
                    }
                    else
                    {
                        this->closeFastBuyUltraFlag = false;
                        this->openFastBuyUltraFlag = false;
                        this->container->fastBuyUltraCont->setVisible(false);
                    }
                }
                else if (this->openFastBuyUltraFlag)
                {
                    if (!this->container->fastBuyUltraCont->isVisible())
                    {
                        this->container->fastBuyUltraCont->setVisible(true);
                    }
                    else if (this->container->fastBuyUltraCont->currentFrame < this->container->fastBuyUltraCont->totalFrames)
                    {
                        this->container->fastBuyUltraCont->gotoAndStop((this->container->fastBuyUltraCont->currentFrame + 1));
                    }
                    else
                    {
                        this->openFastBuyUltraFlag = false;
                        this->closeFastBuyUltraFlag = false;
                        this->fastBuyUltraManage();
                    }
                }
                if (!this->readyFastBuyUltraFlag)
                {
                    if (this->myTower->this_pt.distance(cocos2d::Point(this->world->mouseX, this->world->mouseY)) > 86)
                    {
                        if (this->mouseEnabled)
                        { 
                            this->mouseChildren = false;
                            this->mouseEnabled = false;
                        }
                    }
                    else if (!this->mouseEnabled)
                    { 
                        this->mouseChildren = true;
                        this->mouseEnabled = true;
                    }
                }
                else if (this->fastBuyUltraFlag == "upgrade")
                {
                    //Sounds.instance.playSoundWithVol("snd_tower_build1", 0.9);
                    this->container->btnUpgradeMenuCostTXT->setVisible(false);
                    this->myTower->upgradeTypeAdd ++;
                    if (!this->myTower->enemyTarget)
                    {
                        this->myTower->addBuildAnima();
                    }
                    this->closeMenu();
                }
            }
            return;
        }// end function
        
        void UltraTowerMenu::mouseMoveHandler(cocos2d::EventMouse *param1)
        {
            if (param1->target->name == "btnUpgradeMenuCase")
            {
                if (this->container->btnUpgradeMenu->currentFrame == 1)
                {
                    this->container->btnUpgradeMenu->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
                if (!this->hint->isVisible() && !this->openFlag && !this->closeFlag)
                {
                    this->hint->setVisible(true);
                    if (this->myTower->towerType == 5)
                    {
                        this->hintPosition(1);
                    }
                    else if (this->myTower->towerType == 6)
                    {
                        this->hintPosition(5);
                    }
                    else if (this->myTower->towerType == 7)
                    {
                        this->hintPosition(9);
                    }
                    else if (this->myTower->towerType == 8)
                    {
                        this->hintPosition(13);
                    }
                }
            }
            else
            {
                if (this->container->btnUpgradeMenu->currentFrame == 2)
                {
                    this->container->btnUpgradeMenu->gotoAndStop(1);
                }
                if (param1->target->name == "btnUpgradeMenuBLOCKCase")
                {
                    if (!this->hint->isVisible() && !this->openFlag && !this->closeFlag)
                    {
                        this->hint->setVisible(true);
                        if (this->myTower->towerType == 5)
                        {
                            this->hintPosition(1);
                        }
                        else if (this->myTower->towerType == 6)
                        {
                            this->hintPosition(5);
                        }
                        else if (this->myTower->towerType == 7)
                        {
                            this->hintPosition(9);
                        }
                        else if (this->myTower->towerType == 8)
                        {
                            this->hintPosition(13);
                        }
                    }
                }
                else if (param1->target->name == "btnUpgradeMenuLOCKCase")
                {
                    if (!this->hint->isVisible() && !this->openFlag && !this->closeFlag)
                    {
                        this->hint->setVisible(true);
                        this->hintPosition(21);
                    }
                }
                else if (this->hint->isVisible())
                {
                    this->hint->setVisible(false);
                }
            }
            if (param1->target->name == "btnUpgradeMenuCase" || param1->target->name == "btnUpgradeMenuBLOCKCase" || param1->target->name == "fastBuyUltraCase")
            {
                if (this->myTower->towerType == 5)
                {
                    if (this->world->worldInterface->container->iceBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("");
                    }
                    if (!this->world->worldInterface->container->fireBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("fire");
                    }
                    if (!this->world->worldInterface->container->stoneBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("stone");
                    }
                }
                else if (this->myTower->towerType == 6)
                {
                    if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->stoneBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("");
                    }
                    if (!this->world->worldInterface->container->iceBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("ice");
                    }
                    if (!this->world->worldInterface->container->levinBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("levin");
                    }
                }
                else if (this->myTower->towerType == 7)
                {
                    if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("");
                    }
                    if (!this->world->worldInterface->container->iceBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("ice");
                    }
                    if (!this->world->worldInterface->container->stoneBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("stone");
                    }
                }
                else if (this->myTower->towerType == 8)
                {
                    if (this->world->worldInterface->container->iceBacklight->isVisible() || this->world->worldInterface->container->stoneBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("");
                    }
                    if (!this->world->worldInterface->container->fireBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("fire");
                    }
                    if (!this->world->worldInterface->container->levinBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("levin");
                    }
                }
            }
            else if (param1->target->name != "sphereSlotCase")
            {
                if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->iceBacklight->isVisible() 
                    || this->world->worldInterface->container->stoneBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
                {
                    this->world->worldInterface->archiveSphereBacklightManage("");
                }
            }
            if (param1->target->name == "sphereSlotCase")
            {
                this->tempObject = param1.target.parent;
                if (this->tempObject->sphereAnima->isVisible())
                {
                    if (param1->target->parent->name == "sphereSlot1")
                    {
                        if (this->container->sphereSlot2->currentFrame == 2)
                        {
                            this->container->sphereSlot2->gotoAndStop(1);
                        }
                    }
                    else if (param1->target->parent->name == "sphereSlot2")
                    {
                        if (this->container->sphereSlot1->currentFrame == 2)
                        {
                            this->container->sphereSlot1->gotoAndStop(1);
                        }
                    }
                    if (this->tempObject->currentFrame == 1)
                    {
                        this->tempObject->gotoAndStop(2);
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this->tempObject->currentFrame == 2)
                {
                    this->tempObject->gotoAndStop(1);
                }
            }
            else
            {
                if (this->container->sphereSlot1->currentFrame == 2)
                {
                    this->container->sphereSlot1->gotoAndStop(1);
                }
                if (this->container->sphereSlot2->currentFrame == 2)
                {
                    this->container->sphereSlot2->gotoAndStop(1);
                }
            }
            if (param1->target->name == "sellUltraTowerCase")
            {
                if (this->container->sellUltraTower->currentFrame == 1)
                {
                    this->container->sellUltraTower->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this->container->sellUltraTower->currentFrame == 2)
            {
                this->container->sellUltraTower->gotoAndStop(1);
            }
            if (!this->openFastBuyUltraFlag && !this->closeFastBuyUltraFlag)
            {
                if (param1->target->name == "fastBuyUltraCase" && this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase.buttonMode)
                {
                    if (this->container->fastBuyUltraContBtnFastBuyUltra->currentFrame == 1)
                    {
                        this->container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(2);
                        this->container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyPrice;
                        if (this->fastBuyUltraFlag == "upgrade")
                        {
                            if (this->myTower->towerType == 5)
                            {
                                if (this->world->worldInterface->container->iceBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("");
                                }
                                if (!this->world->worldInterface->container->fireBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("fire");
                                }
                                if (!this->world->worldInterface->container->stoneBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("stone");
                                }
                            }
                            else if (this->myTower->towerType == 6)
                            {
                                if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->stoneBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("");
                                }
                                if (!this->world->worldInterface->container->iceBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("ice");
                                }
                                if (!this->world->worldInterface->container->levinBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("levin");
                                }
                            }
                            else if (this->myTower->towerType == 7)
                            {
                                if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("");
                                }
                                if (!this->world->worldInterface->container->iceBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("ice");
                                }
                                if (!this->world->worldInterface->container->stoneBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("stone");
                                }
                            }
                            else if (this->myTower->towerType == 8)
                            {
                                if (this->world->worldInterface->container->iceBacklight->isVisible() || this->world->worldInterface->container->stoneBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("");
                                }
                                if (!this->world->worldInterface->container->fireBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("fire");
                                }
                                if (!this->world->worldInterface->container->levinBacklight->isVisible())
                                {
                                    this->world->worldInterface->archiveSphereBacklightManage("levin");
                                }
                            }
                        }
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
                else if (this->container->fastBuyUltraContBtnFastBuyUltra->currentFrame == 2)
                {
                    this->container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(1);
                    std::setText(this->container->fastBuyUltraContBtnFastBuyUltra->costTXT, this->fastBuyPrice);
                    //this->container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyPrice;
                    if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->iceBacklight->isVisible() || this->world->worldInterface->container->stoneBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("");
                    }
                }
            }
            return;
        }// end function

        void UltraTowerMenu::mouseDownHandler(cocos2d::EventMouse *event)
        {
            if (event->target->name == "btnUpgradeMenuCase")
            {
                if (this->container->btnUpgradeMenu->currentFrame == 2)
                {
                    this->container->btnUpgradeMenu->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "sphereSlotCase")
            {
                this->tempObject = event->target->parent;
                if (this->tempObject->currentFrame < 4)
                {
                    if (this->tempObject->sphereAnima->currentFrame == 1)
                    {
                        this->myTower->towerGetSphereManage("get", "fire");
                    }
                    else if (this->tempObject->sphereAnima->currentFrame == 2)
                    {
                        this->myTower->towerGetSphereManage("get", "ice");
                    }
                    else if (this->tempObject->sphereAnima->currentFrame == 3)
                    {
                        this->myTower->towerGetSphereManage("get", "stone");
                    }
                    else if (this->tempObject->sphereAnima->currentFrame == 4)
                    {
                        this->myTower->towerGetSphereManage("get", "levin");
                    }
                    if (!this->world->getSphere)
                    {
                        if (this->tempObject.name == "sphereSlot1")
                        {
                            if (this->myTower->towerType == 5)
                            {
                                if (this->world->worldInterface->container->fireSphere->alpha == 1 && this->world->worldInterface->container->fireSphere->isVisible())
                                {
                                    this->world->worldInterface->container->fireBacklight->turnFlag = false;
                                    this->world->worldInterface->container->fireBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->fireBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 6)
                            {
                                if (this->world->worldInterface->container->iceSphere->alpha == 1 && this->world->worldInterface->container->iceSphere->isVisible())
                                {
                                    this->world->worldInterface->container->iceBacklight->turnFlag = false;
                                    this->world->worldInterface->container->iceBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->iceBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 7)
                            {
                                if (this->world->worldInterface->container->iceSphere->alpha == 1 && this->world->worldInterface->container->iceSphere->isVisible())
                                {
                                    this->world->worldInterface->container->iceBacklight->turnFlag = false;
                                    this->world->worldInterface->container->iceBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->iceBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 8)
                            {
                                if (this->world->worldInterface->container->fireSphere->alpha == 1 && this->world->worldInterface->container->fireSphere->isVisible())
                                {
                                    this->world->worldInterface->container->fireBacklight->turnFlag = false;
                                    this->world->worldInterface->container->fireBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->fireBacklight->setVisible(true);
                                }
                            }
                        }
                        else if (this->tempObject.name == "sphereSlot2")
                        {
                            if (this->myTower->towerType == 5)
                            {
                                if (this->world->worldInterface->container->stoneSphere->alpha == 1 && this->world->worldInterface->container->stoneSphere->isVisible())
                                {
                                    this->world->worldInterface->container->stoneBacklight->turnFlag = false;
                                    this->world->worldInterface->container->stoneBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->stoneBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 6)
                            {
                                if (this->world->worldInterface->container->levinSphere->alpha == 1 && this->world->worldInterface->container->levinSphere->isVisible())
                                {
                                    this->world->worldInterface->container->levinBacklight->turnFlag = false;
                                    this->world->worldInterface->container->levinBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->levinBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 7)
                            {
                                if (this->world->worldInterface->container->stoneSphere->alpha == 1 && this->world->worldInterface->container->stoneSphere->isVisible())
                                {
                                    this->world->worldInterface->container->stoneBacklight->turnFlag = false;
                                    this->world->worldInterface->container->stoneBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->stoneBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 8)
                            {
                                if (this->world->worldInterface->container->levinSphere->alpha == 1 && this->world->worldInterface->container->levinSphere->isVisible())
                                {
                                    this->world->worldInterface->container->levinBacklight->turnFlag = false;
                                    this->world->worldInterface->container->levinBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->levinBacklight->setVisible(true);
                                }
                            }
                        }
                    }
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "sellUltraTowerCase")
            {
                if (this->container->sellUltraTower->currentFrame == 2)
                {
                    this->container->sellUltraTower->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "fastBuyUltraCase")
            {
                if (!this->openFastBuyUltraFlag && !this->closeFastBuyUltraFlag)
                {
                    if (this->container->fastBuyUltraContBtnFastBuyUltra->currentFrame == 2 && this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode)
                    {
                        this->container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(1);
                        std::setText(this->container->fastBuyUltraContBtnFastBuyUltra->costTXT, this->fastBuyPrice);
                        //this->container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyPrice;
                        this->fastBuyBlockCost = true;
                        this->fastBuyUltraManage(); 
                        this->myTower->mouseChildren = false;
                        this->myTower->mouseEnabled = false;
                        this->readyFastBuyUltraFlag = true;
                        if (this->myTower->towerType == 5)
                        {
                            this->world->money = this->world->money - Main::mainClass->readXMLClass.costUltraAddFireStone;
                            if (!this->myTower->shootingTurnStack[0])
                            {
                                if (this->world->worldInterface->fireCount == 0)
                                {
                                    this->world->worldInterface->archiveManage("buy", "fire");
                                }
                                if (this->world->worldInterface->fireCount > 0)
                                {
                                    this->world->worldInterface->archiveManage("get", "fire");
                                    this->world->getSphere->getSphereFromArchiveToTower();
                                }
                            }
                            if (!this->myTower->shootingTurnStack[2])
                            {
                                if (this->world->worldInterface->stoneCount == 0)
                                {
                                    this->world->worldInterface->archiveManage("buy", "stone");
                                }
                                if (this->world->worldInterface->stoneCount > 0)
                                {
                                    this->world->worldInterface->archiveManage("get", "stone");
                                    this->world->getSphere->getSphereFromArchiveToTower();
                                }
                            }
                        }
                        else if (this->myTower->towerType == 6)
                        {
                            this->world->money = this->world->money - Main::mainClass->readXMLClass.costUltraAddIceLevin;
                            if (!this->myTower->shootingTurnStack[1])
                            {
                                if (this->world->worldInterface->iceCount == 0)
                                {
                                    this->world->worldInterface->archiveManage("buy", "ice");
                                }
                                if (this->world->worldInterface->iceCount > 0)
                                {
                                    this->world->worldInterface->archiveManage("get", "ice");
                                    this->world->getSphere->getSphereFromArchiveToTower();
                                }
                            }
                            if (!this->myTower->shootingTurnStack[3])
                            {
                                if (this->world->worldInterface->levinCount == 0)
                                {
                                    this->world->worldInterface->archiveManage("buy", "levin");
                                }
                                if (this->world->worldInterface->levinCount > 0)
                                {
                                    this->world->worldInterface->archiveManage("get", "levin");
                                    this->world->getSphere->getSphereFromArchiveToTower();
                                }
                            }
                        }
                        else if (this->myTower->towerType == 7)
                        {
                            this->world->money = this->world->money - Main::mainClass->readXMLClass.costUltraAddIceStone;
                            if (!this->myTower->shootingTurnStack[1])
                            {
                                if (this->world->worldInterface->iceCount == 0)
                                {
                                    this->world->worldInterface->archiveManage("buy", "ice");
                                }
                                if (this->world->worldInterface->iceCount > 0)
                                {
                                    this->world->worldInterface->archiveManage("get", "ice");
                                    this->world->getSphere->getSphereFromArchiveToTower();
                                }
                            }
                            if (!this->myTower->shootingTurnStack[2])
                            {
                                if (this->world->worldInterface->stoneCount == 0)
                                {
                                    this->world->worldInterface->archiveManage("buy", "stone");
                                }
                                if (this->world->worldInterface->stoneCount > 0)
                                {
                                    this->world->worldInterface->archiveManage("get", "stone");
                                    this->world->getSphere->getSphereFromArchiveToTower();
                                }
                            }
                        }
                        else if (this->myTower->towerType == 8)
                        {
                            this->world->money = this->world->money - Main::mainClass->readXMLClass.costUltraAddFireLevin;
                            if (!this->myTower->shootingTurnStack[0])
                            {
                                if (this->world->worldInterface->fireCount == 0)
                                {
                                    this->world->worldInterface->archiveManage("buy", "fire");
                                }
                                if (this->world->worldInterface->fireCount > 0)
                                {
                                    this->world->worldInterface->archiveManage("get", "fire");
                                    this->world->getSphere->getSphereFromArchiveToTower();
                                }
                            }
                            if (!this->myTower->shootingTurnStack[3])
                            {
                                if (this->world->worldInterface->levinCount == 0)
                                {
                                    this->world->worldInterface->archiveManage("buy", "levin");
                                }
                                if (this->world->worldInterface->levinCount > 0)
                                {
                                    this->world->worldInterface->archiveManage("get", "levin");
                                    this->world->getSphere->getSphereFromArchiveToTower();
                                }
                            }
                        }
                        this->world->worldInterface->updateInfo();
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            else if (event->target->name != "buySphereCase" && event->target->name != "sphereCase" && event->target->name != "btnUpgradeMenuBLOCKCase"
                 && event->target->parent != this->container && event->target->parent.parent != this->container)
            {
                this->lastE = event;
                this->closeMenu();
            }
            return;
        }// end function

        void UltraTowerMenu::mouseUpHandler(cocos2d::EventMouse *event)
        {
            if (event->target->name == "btnUpgradeMenuCase")
            {
                if (this->container->btnUpgradeMenu->currentFrame == 3)
                {
                    this->container->btnUpgradeMenu->gotoAndStop(4);
                    if (this->myTower->towerType == 5)
                    {
                        std:;setText(this->container->btnUpgradeMenu->costTXT, Main::mainClass->readXMLClass.costUltraAddFireStone);
                        //this->container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddFireStone;
                    }
                    else if (this->myTower->towerType == 6)
                    {
                        std:;setText(this->container->btnUpgradeMenu->costTXT, Main::mainClass->readXMLClass.costUltraAddIceLevin);
                        //this->container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddIceLevin;
                    }
                    else if (this->myTower->towerType == 7)
                    {
                        std:;setText(this->container->btnUpgradeMenu->costTXT, Main::mainClass->readXMLClass.costUltraAddIceStone);
                        //this->container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddIceStone;
                    }
                    else if (this->myTower->towerType == 8)
                    {
                        std:;setText(this->container->btnUpgradeMenu->costTXT, Main::mainClass->readXMLClass.costUltraAddFireLevin);
                        //this->container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddFireLevin;
                    }
                    if (!this->fastBuyUltraFlag)
                    {
                        this->fastBuyUltraFlag = "upgrade";
                        this->openFastBuyUltraFlag = true;
                        this->fastBuyUltraManage();
                    }
                    else if (event->target->parent.name == this->fastBuyUltraFlag)
                    {
                        this->fastBuyUltraFlag = null;
                        this->closeFastBuyUltraFlag = true;
                        this->mouseMoveHandler(event);
                    }
                }
            }
            else if (this->container->btnUpgradeMenu->currentFrame == 3)
            {
                this->container->btnUpgradeMenu->gotoAndStop(1);
            }
            if (event->target->name == "sellUltraTowerCase")
            {
                if (this->container->sellUltraTower->currentFrame == 3)
                {
                    this->container->sellUltraTower->gotoAndStop(2);
                    if (this->myTower->towerType == 5)
                    {
                        this->tempObject = std::round(Main::mainClass->readXMLClass.costUltraFireStone - Main::mainClass->readXMLClass.costUltraFireStone * this->sellTax);
                        if (this->myTower->upgradeTypeAdd == 0)
                        {
                            if (this->myTower->shootingTurnStack[0])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphere->myPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "fire", 1);
                                this->world->getSphere->manage("add", "fire");
                                this->world->getSphere->setPosition(this->myTower->this_pt);
                                //this->world->getSphere->x = this->myTower->this_pt.x;
                                //this->world->getSphere->y = this->myTower->this_pt.y;
                                this->world->getSphere->retrieveGetSphere();
                            }
                            if (this->myTower->shootingTurnStack[2])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->stoneSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphere.myPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "stone", 1);
                                this->world->getSphere->manage("add", "stone");
                                this->world->getSphere->setPosition(this->myTower->this_pt); 
                                this->world->getSphere->retrieveGetSphere();
                            }
                        }
                        else if (this->myTower->upgradeTypeAdd == 1)
                        {
                            this->tempObject = this->tempObject + std::round(Main::mainClass->readXMLClass.costUltraAddFireStone - Main::mainClass->readXMLClass.costUltraAddFireStone * this->sellTax);
                            this->world->worldInterface->sellSphere("fire");
                            this->world->worldInterface->sellSphere("stone");
                        }
                    }
                    else if (this->myTower->towerType == 6)
                    {
                        this->tempObject = std::round(Main::mainClass->readXMLClass.costUltraIceLevin - Main::mainClass->readXMLClass.costUltraIceLevin * this->sellTax);
                        if (this->myTower->upgradeTypeAdd == 0)
                        {
                            if (this->myTower->shootingTurnStack[1])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphere.myPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "ice", 1);
                                this->world->getSphere->manage("add", "ice");
                                this->world->getSphere->setPosition(this->myTower->this_pt); 
                                this->world->getSphere->retrieveGetSphere();
                            }
                            if (this->myTower->shootingTurnStack[3])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->levinSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphere.myPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "levin", 1);
                                this->world->getSphere->manage("add", "levin");
                                this->world->getSphere->setPosition(this->myTower->this_pt); 
                                this->world->getSphere->retrieveGetSphere();
                            }
                        }
                        else if (this->myTower->upgradeTypeAdd == 1)
                        {
                            this->tempObject = this->tempObject + std::round(Main::mainClass->readXMLClass.costUltraAddIceLevin - Main::mainClass->readXMLClass.costUltraAddIceLevin * this->sellTax);
                            this->world->worldInterface->sellSphere("ice");
                            this->world->worldInterface->sellSphere("levin");
                        }
                    }
                    else if (this->myTower->towerType == 7)
                    {
                        this->tempObject = std::round(Main::mainClass->readXMLClass.costUltraIceStone - Main::mainClass->readXMLClass.costUltraIceStone * this->sellTax);
                        if (this->myTower->upgradeTypeAdd == 0)
                        {
                            if (this->myTower->shootingTurnStack[1])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphere.myPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "ice", 1);
                                this->world->getSphere->manage("add", "ice");
                                this->world->getSphere->setPosition(this->myTower->this_pt); 
                                this->world->getSphere->retrieveGetSphere();
                            }
                            if (this->myTower->shootingTurnStack[2])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->stoneSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphere.myPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "stone", 1);
                                this->world->getSphere->manage("add", "stone");
                                this->world->getSphere->setPosition(this->myTower->this_pt); 
                                this->world->getSphere->retrieveGetSphere();
                            }
                        }
                        else if (this->myTower->upgradeTypeAdd == 1)
                        {
                            this->tempObject = this->tempObject + std::round(Main::mainClass->readXMLClass.costUltraAddIceStone - Main::mainClass->readXMLClass.costUltraAddIceStone * this->sellTax);
                            this->world->worldInterface->sellSphere("ice");
                            this->world->worldInterface->sellSphere("stone");
                        }
                    }
                    else if (this->myTower->towerType == 8)
                    {
                        this->tempObject = std::round(Main::mainClass->readXMLClass.costUltraFireLevin - Main::mainClass->readXMLClass.costUltraFireLevin * this->sellTax);
                        if (this->myTower->upgradeTypeAdd == 0)
                        {
                            if (this->myTower->shootingTurnStack[0])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphere->myPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "fire", 1);
                                this->world->getSphere->manage("add", "fire");
                                this->world->getSphere->setPosition(this->myTower->this_pt); 
                                this->world->getSphere->retrieveGetSphere();
                            }
                            if (this->myTower->shootingTurnStack[3])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->levinSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphere.myPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "levin", 1);
                                this->world->getSphere->manage("add", "levin");
                                this->world->getSphere->setPosition(this->myTower->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                        }
                        else if (this->myTower->upgradeTypeAdd == 1)
                        {
                            this->tempObject = this->tempObject + std::round(Main::mainClass->readXMLClass.costUltraAddFireLevin - Main::mainClass->readXMLClass.costUltraAddFireLevin * this->sellTax);
                            this->world->worldInterface->sellSphere("fire");
                            this->world->worldInterface->sellSphere("levin");
                        }
                    }
                    this->world->money = this->world->money + this->tempObject;
                    this->world->worldInterface->updateInfo();
                    this->closeMenu();
                    this->myTower->myPlace->gotoAndStop(1);
                    this->myTower->myPlace->buildPoint->stop();
                    this->myTower->myPlace->placeForBuildCase->buttonMode = true;
                    this->myTower->kill();
                    //Sounds.instance.playSound("snd_tower_sell");
                }
            }
            else if (this->container->sellUltraTower->currentFrame == 3)
            {
                this->container->sellUltraTower->gotoAndStop(1);
            }
            return;
        }// end function
        void UltraTowerMenu::monitor()
        {
            if (this->myTower->towerType == 5)
            {
                if (Main::mainClass->readXMLClass.ultraTower1UpgrBlock == 0)
                {
                    this->container->sphereSlot1->gotoAndStop(1);
                    this->container->sphereSlot2->gotoAndStop(1);
                    this->container->sphereSlot1SphereAnima->gotoAndStop(1);
                    this->container->sphereSlot1SphereAnimaCont->stop();
                    this->container->sphereSlot2SphereAnima->gotoAndStop(3);
                    this->container->sphereSlot2SphereAnimaCont->stop();
                    if (!this->myTower->shootingTurnStack[0])
                    {
                        this->container->sphereSlot1SphereAnima->setVisible(false);
                        this->container->sphereSlot1SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        this->container->sphereSlot1SphereAnima->setVisible(true);
                        this->container->sphereSlot1SphereSlotCase->buttonMode = true;
                    }
                    if (!this->myTower->shootingTurnStack[2])
                    {
                        this->container->sphereSlot2SphereAnima->setVisible(false);
                        this->container->sphereSlot2SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        this->container->sphereSlot2SphereAnima->setVisible(true);
                        this->container->sphereSlot2SphereSlotCase->buttonMode = true;
                    }
                    if (this->myTower->upgradeTypeAdd == 1)
                    {
                        this->container->btnUpgradeMenu->setVisible(false);
                    }
                    else if (this->world->money >= Main::mainClass->readXMLClass.costUltraAddFireStone && !this->fastBuyUltraFlag)
                    {
                        this->container->btnUpgradeMenu->gotoAndStop(1);
                        this->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
                    }
                    else
                    {
                        this->container->btnUpgradeMenu->gotoAndStop(4);
                    }
                    if (!this->fastBuyUltraFlag)
                    {
                        std::setText(this->container->btnUpgradeMenu->costTXT, Main::mainClass->readXMLClass.costUltraAddFireStone);
                        //this->container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddFireStone;
                    }
                }
                else
                {
                    this->container->btnUpgradeMenu->gotoAndStop(5);
                    this->container->sphereSlot1->gotoAndStop(4);
                    this->container->sphereSlot2->gotoAndStop(4);
                    this->container->sphereSlot1SphereAnima->gotoAndStop(1);
                    this->container->sphereSlot1SphereAnimaCont->stop();
                    this->container->sphereSlot2SphereAnima->gotoAndStop(3);
                    this->container->sphereSlot2SphereAnimaCont->stop();
                    this->container->sphereSlot1SphereAnima->setVisible(false);
                    this->container->sphereSlot1SphereSlotCase->buttonMode = false;
                    this->container->sphereSlot2SphereAnima->setVisible(false);
                    this->container->sphereSlot2SphereSlotCase->buttonMode = false;
                }
            }
            else if (this->myTower->towerType == 6)
            {
                if (Main::mainClass->readXMLClass.ultraTower2UpgrBlock == 0)
                {
                    this->container->sphereSlot1->gotoAndStop(1);
                    this->container->sphereSlot2->gotoAndStop(1);
                    this->container->sphereSlot1SphereAnima->gotoAndStop(2);
                    this->container->sphereSlot1SphereAnimaCont->stop();
                    this->container->sphereSlot2SphereAnima->gotoAndStop(4);
                    this->container->sphereSlot2SphereAnimaCont->stop();
                    if (!this->myTower->shootingTurnStack[1])
                    {
                        this->container->sphereSlot1SphereAnima->setVisible(false);
                        this->container->sphereSlot1SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        this->container->sphereSlot1SphereAnima->setVisible(true);
                        this->container->sphereSlot1SphereSlotCase->buttonMode = true;
                    }
                    if (!this->myTower->shootingTurnStack[3])
                    {
                        this->container->sphereSlot2SphereAnima->setVisible(false);
                        this->container->sphereSlot2SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        this->container->sphereSlot2SphereAnima->setVisible(true);
                        this->container->sphereSlot2SphereSlotCase->buttonMode = true;
                    }
                    if (this->myTower->upgradeTypeAdd == 1)
                    {
                        this->container->btnUpgradeMenu->setVisible(false);
                    }
                    else if (this->world->money >= Main::mainClass->readXMLClass.costUltraAddIceLevin && !this->fastBuyUltraFlag)
                    {
                        this->container->btnUpgradeMenu->gotoAndStop(1);
                        this->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
                    }
                    else
                    {
                        this->container->btnUpgradeMenu->gotoAndStop(4);
                    }
                    if (!this->fastBuyUltraFlag)
                    {
                        std::setText(this->container->btnUpgradeMenu->costTXT, Main::mainClass->readXMLClass.costUltraAddIceLevin);
                        //this->container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddIceLevin;
                    }
                }
                else
                {
                    this->container->btnUpgradeMenu->gotoAndStop(5);
                    this->container->sphereSlot1->gotoAndStop(4);
                    this->container->sphereSlot2->gotoAndStop(4);
                    this->container->sphereSlot1SphereAnima->gotoAndStop(2);
                    this->container->sphereSlot1SphereAnimaCont->stop();
                    this->container->sphereSlot2SphereAnima->gotoAndStop(4);
                    this->container->sphereSlot2SphereAnimaCont->stop();
                    this->container->sphereSlot1SphereAnima->setVisible(false);
                    this->container->sphereSlot1SphereSlotCase->buttonMode = false;
                    this->container->sphereSlot2SphereAnima->setVisible(false);
                    this->container->sphereSlot2SphereSlotCase->buttonMode = false;
                }
            }
            else if (this->myTower->towerType == 7)
            {
                if (Main::mainClass->readXMLClass.ultraTower3UpgrBlock == 0)
                {
                    this->container->sphereSlot1->gotoAndStop(1);
                    this->container->sphereSlot2->gotoAndStop(1);
                    this->container->sphereSlot1SphereAnima->gotoAndStop(2);
                    this->container->sphereSlot1SphereAnimaCont->stop();
                    this->container->sphereSlot2SphereAnima->gotoAndStop(3);
                    this->container->sphereSlot2SphereAnimaCont->stop();
                    if (!this->myTower->shootingTurnStack[1])
                    {
                        this->container->sphereSlot1SphereAnima->setVisible(false);
                        this->container->sphereSlot1SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        this->container->sphereSlot1SphereAnima->setVisible(true);
                        this->container->sphereSlot1SphereSlotCase->buttonMode = true;
                    }
                    if (!this->myTower->shootingTurnStack[2])
                    {
                        this->container->sphereSlot2SphereAnima->setVisible(false);
                        this->container->sphereSlot2SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        this->container->sphereSlot2SphereAnima->setVisible(true);
                        this->container->sphereSlot2SphereSlotCase->buttonMode = true;
                    }
                    if (this->myTower->upgradeTypeAdd == 1)
                    {
                        this->container->btnUpgradeMenu->setVisible(false);
                    }
                    else if (this->world->money >= Main::mainClass->readXMLClass.costUltraAddIceStone && !this->fastBuyUltraFlag)
                    {
                        this->container->btnUpgradeMenu->gotoAndStop(1);
                        this->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
                    }
                    else
                    {
                        this->container->btnUpgradeMenu->gotoAndStop(4);
                    }
                    if (!this->fastBuyUltraFlag)
                    {
                        std::setText(this->container->btnUpgradeMenu->costTXT, Main::mainClass->readXMLClass.costUltraAddIceStone);
                        //this->container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddIceStone;
                    }
                }
                else
                {
                    this->container->btnUpgradeMenu->gotoAndStop(5);
                    this->container->sphereSlot1->gotoAndStop(4);
                    this->container->sphereSlot2->gotoAndStop(4);
                    this->container->sphereSlot1SphereAnima->gotoAndStop(2);
                    this->container->sphereSlot1SphereAnimaCont->stop();
                    this->container->sphereSlot2SphereAnima->gotoAndStop(3);
                    this->container->sphereSlot2SphereAnimaCont->stop();
                    this->container->sphereSlot1SphereAnima->setVisible(false);
                    this->container->sphereSlot1SphereSlotCase->buttonMode = false;
                    this->container->sphereSlot2SphereAnima->setVisible(false);
                    this->container->sphereSlot2SphereSlotCase->buttonMode = false;
                }
            }
            else if (this->myTower->towerType == 8)
            {
                if (Main::mainClass->readXMLClass.ultraTower4UpgrBlock == 0)
                {
                    this->container->sphereSlot1->gotoAndStop(1);
                    this->container->sphereSlot2->gotoAndStop(1);
                    this->container->sphereSlot1SphereAnima->gotoAndStop(1);
                    this->container->sphereSlot1SphereAnimaCont->stop();
                    this->container->sphereSlot2SphereAnima->gotoAndStop(4);
                    this->container->sphereSlot2SphereAnimaCont->stop();
                    if (!this->myTower->shootingTurnStack[0])
                    {
                        this->container->sphereSlot1SphereAnima->setVisible(false);
                        this->container->sphereSlot1SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        this->container->sphereSlot1SphereAnima->setVisible(true);
                        this->container->sphereSlot1SphereSlotCase->buttonMode = true;
                    }
                    if (!this->myTower->shootingTurnStack[3])
                    {
                        this->container->sphereSlot2SphereAnima->setVisible(false);
                        this->container->sphereSlot2SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        this->container->sphereSlot2SphereAnima->setVisible(true);
                        this->container->sphereSlot2SphereSlotCase->buttonMode = true;
                    }
                    if (this->myTower->upgradeTypeAdd == 1)
                    {
                        this->container->btnUpgradeMenu->setVisible(false);
                    }
                    else if (this->world->money >= Main::mainClass->readXMLClass.costUltraAddFireLevin && !this->fastBuyUltraFlag)
                    {
                        this->container->btnUpgradeMenu->gotoAndStop(1);
                        this->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
                    }
                    else
                    {
                        this->container->btnUpgradeMenu->gotoAndStop(4);
                    }
                    if (!this->fastBuyUltraFlag)
                    {
                        std::setText(this->container->btnUpgradeMenu->costTXT, Main::mainClass->readXMLClass.costUltraAddFireLevin);
                        //this->container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddFireLevin;
                    }
                }
                else
                {
                    this->container->btnUpgradeMenu->gotoAndStop(5);
                    this->container->sphereSlot1->gotoAndStop(4);
                    this->container->sphereSlot2->gotoAndStop(4);
                    this->container->sphereSlot1SphereAnima->gotoAndStop(1);
                    this->container->sphereSlot1SphereAnimaCont->stop();
                    this->container->sphereSlot2SphereAnima->gotoAndStop(4);
                    this->container->sphereSlot2SphereAnimaCont->stop();
                    this->container->sphereSlot1SphereAnima->setVisible(false);
                    this->container->sphereSlot1SphereSlotCase->buttonMode = false;
                    this->container->sphereSlot2SphereAnima->setVisible(false);
                    this->container->sphereSlot2SphereSlotCase->buttonMode = false;
                }
            }
            if (this->fastBuyUltraFlag)
            {
                this->fastBuyUltraManage();
            }
            if (!this->openFlag)
            {
                this->world->worldInterface->archiveSphereBacklightManage("");
                this->autoguidersButtons();
            }
            return;
        }// end function

        void UltraTowerMenu::autoguidersButtons()
        {
            this->autoguidesMouse_pt = cocos2d::Point(Main::mainClass->worldClass->mouseX, Main::mainClass->worldClass->mouseY);
            this->autoguidesObject = NULL;
            this->autoguidesObject_pt = this->container->sphereSlot1->localToGlobal(this->container->sphereSlot1SphereSlotCase->getPosition());
            this->autoguidesObjectWidth = this->container->sphereSlot1SphereSlotCase->width / 2;
            this->autoguidesObjectHeight = this->container->sphereSlot1SphereSlotCase->height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->sphereSlot1SphereSlotCase;
            }
            if (!this->autoguidesObject)
            {
                this->autoguidesObject_pt = this->container->sphereSlot2->localToGlobal(this->container->sphereSlot2SphereSlotCase->getPosition());
                this->autoguidesObjectWidth = this->container->sphereSlot2SphereSlotCase->width / 2;
                this->autoguidesObjectHeight = this->container->sphereSlot2SphereSlotCase->height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->sphereSlot2SphereSlotCase;
                }
            }
            if (!this->autoguidesObject && this->container->btnUpgradeMenu->isVisible() && this->container->btnUpgradeMenuBtnUpgradeMenuCase)
            {
                this->autoguidesObject_pt = this->container->btnUpgradeMenu->localToGlobal(this->container->btnUpgradeMenuBtnUpgradeMenuCase->getPosition());
                this->autoguidesObjectWidth = this->container->btnUpgradeMenuBtnUpgradeMenuCase.width / 2;
                this->autoguidesObjectHeight = this->container->btnUpgradeMenuBtnUpgradeMenuCase.height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->btnUpgradeMenuBtnUpgradeMenuCase;
                }
            }
            if (!this->autoguidesObject && this->fastBuyUltraFlag)
            {
                this->autoguidesObject_pt = this->container->fastBuyUltraContBtnFastBuyUltra->localToGlobal(this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->getPosition());
                this->autoguidesObjectWidth = this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->width / 2;
                this->autoguidesObjectHeight = this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->height / 2;
                if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
                {
                    this->autoguidesObject = this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase;
                }
            }
            if (this->autoguidesObject)
            {
                //构造事件对象
                this->tempObject =new Event();// new Object();
                this->tempObject.target = this->autoguidesObject;
                this->mouseMoveHandler(this->tempObject);
            }
            return;
        }// end function

        void UltraTowerMenu::fastBuyUltraManage()
        {
            if (this->container->fastBuyUltraCont)
            {
                this->container->fastBuyUltraCont->stop();
                this->container->fastBuyUltraContBtnFastBuyUltra->stop();
                this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->stop();
                this->container->fastBuyUltraContIndicator1->stop();
                this->container->fastBuyUltraContIndicator2->stop();
                this->container->fastBuyUltraContIndicator3->stop();
                this->container->fastBuyUltraContIndicator4->stop();
                this->container->fastBuyUltraContIndicator2->setVisible(false);
                this->container->fastBuyUltraContIndicator3->setVisible(false);
                if (!this->fastBuyUltraFlag && !this->openFastBuyUltraFlag && !this->closeFastBuyUltraFlag)
                {
                    this->container->fastBuyUltraCont->setVisible(false);
                }
                if (this->fastBuyUltraFlag)
                {
                    this->container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(1);
                    this->container->fastBuyUltraContIndicator1->gotoAndStop(2);
                    this->container->fastBuyUltraContIndicator4->gotoAndStop(2);
                    this->container->fastBuyUltraContIndicator1->setVisible(true);
                    this->container->fastBuyUltraContIndicator4->setVisible(true);
                    if (!this->fastBuyBlockCost)
                    {
                        std::setText(this->container->fastBuyUltraContBtnFastBuyUltra->costTXT, this->fastBuyUltraScan());
                        //this->container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyUltraScan();
                    }
                    else
                    {
                        std::setText(this->container->fastBuyUltraContBtnFastBuyUltra->costTXT, this->fastBuyPrice);
                        //this->container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyPrice;
                    }
                    if (this->myTower->towerType == 5)
                    {
                        if (this->myTower->shootingTurnStack[0])
                        {
                            this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
                        }
                        if (this->myTower->shootingTurnStack[2])
                        {
                            this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
                        }
                    }
                    else if (this->myTower->towerType == 6)
                    {
                        if (this->myTower->shootingTurnStack[1])
                        {
                            this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
                        }
                        if (this->myTower->shootingTurnStack[3])
                        {
                            this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
                        }
                    }
                    else if (this->myTower->towerType == 7)
                    {
                        if (this->myTower->shootingTurnStack[1])
                        {
                            this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
                        }
                        if (this->myTower->shootingTurnStack[2])
                        {
                            this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
                        }
                    }
                    else if (this->myTower->towerType == 8)
                    {
                        if (this->myTower->shootingTurnStack[0])
                        {
                            this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
                        }
                        if (this->myTower->shootingTurnStack[3])
                        {
                            this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
                        }
                    }
                    this->fastBuyPrice = int(this->container->fastBuyUltraContBtnFastBuyUltra->costTXT.text);
                    if (this->world->money >= int(this->container->fastBuyUltraContBtnFastBuyUltra->costTXT.text))
                    {
                        this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode = true;
                    }
                    else
                    {
                        this->container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(4);
                        std::setText(this->container->fastBuyUltraContBtnFastBuyUltra->costTXT, this->fastBuyPrice);
                        //this->container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyPrice;
                        this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode = false;
                    }
                }
            }
            return;
        }// end function

        int UltraTowerMenu::fastBuyUltraScan()
        {
            int tempObject1 =0;
            if (this->myTower->towerType == 5)
            {
                tempObject1 = Main::mainClass->readXMLClass.costUltraAddFireStone;
                if (!this->myTower->shootingTurnStack[0])
                {
                    if (this->world->worldInterface->fireCount == 0)
                    {
                        tempObject1 = this->tempObject1 + Main::mainClass->readXMLClass.listOfFirePriceXML[this->world->worldInterface->fireBuyHistory];
                    }
                }
                if (!this->myTower->shootingTurnStack[2])
                {
                    if (this->world->worldInterface->stoneCount == 0)
                    {
                        tempObject1 = this->tempObject1 + Main::mainClass->readXMLClass.listOfStonePriceXML[this->world->worldInterface->stoneBuyHistory];
                    }
                }
            }
            else if (this->myTower->towerType == 6)
            {
                tempObject1 = Main::mainClass->readXMLClass.costUltraAddIceLevin;
                if (!this->myTower->shootingTurnStack[1])
                {
                    if (this->world->worldInterface->iceCount == 0)
                    {
                        tempObject1 = this->tempObject1 + Main::mainClass->readXMLClass.listOfIcePriceXML[this->world->worldInterface->iceBuyHistory];
                    }
                }
                if (!this->myTower->shootingTurnStack[3])
                {
                    if (this->world->worldInterface->levinCount == 0)
                    {
                        tempObject1 = this->tempObject1 + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->world->worldInterface->levinBuyHistory];
                    }
                }
            }
            else if (this->myTower->towerType == 7)
            {
                tempObject1 = Main::mainClass->readXMLClass.costUltraAddIceStone;
                if (!this->myTower->shootingTurnStack[1])
                {
                    if (this->world->worldInterface->iceCount == 0)
                    {
                        tempObject1 = this->tempObject1 + Main::mainClass->readXMLClass.listOfIcePriceXML[this->world->worldInterface->iceBuyHistory];
                    }
                }
                if (!this->myTower->shootingTurnStack[2])
                {
                    if (this->world->worldInterface->stoneCount == 0)
                    {
                        tempObject1 = this->tempObject1 + Main::mainClass->readXMLClass.listOfStonePriceXML[this->world->worldInterface->stoneBuyHistory];
                    }
                }
            }
            else if (this->myTower->towerType == 8)
            {
                tempObject1 = Main::mainClass->readXMLClass.costUltraAddFireLevin;
                if (!this->myTower->shootingTurnStack[0])
                {
                    if (this->world->worldInterface->fireCount == 0)
                    {
                        tempObject1 = this->tempObject1 + Main::mainClass->readXMLClass.listOfFirePriceXML[this->world->worldInterface->fireBuyHistory];
                    }
                }
                if (!this->myTower->shootingTurnStack[3])
                {
                    if (this->world->worldInterface->levinCount == 0)
                    {
                        tempObject1 = this->tempObject1 + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->world->worldInterface->levinBuyHistory];
                    }
                }
            }
            return tempObject1;
        }// end function

        void UltraTowerMenu::hintPosition(int param1 )
        {
            //this->tempObject = this->container->localToGlobal(new Point(this->container->btnUpgradeMenu->x, this->container->btnUpgradeMenu->y));
            cocos2d::Point tempObject = this->container->localToGlobal(this->container->btnUpgradeMenu->getPosition());
            param1 = param1 - 1;
            if (this->tempObject.x < 120)
            {
                if (this->tempObject.y < 120)
                {
                    this->hint->gotoAndStop(param1 + 4);
                    this->hint->setPositionY(this->tempObject->getPositionY() + 12);
                }
                else if (this->tempObject.y > Main::SCREEN_HEIGHT - 120)
                {
                    this->hint->gotoAndStop(param1 + 2);
                    this->hint->setPositionY(this->tempObject->getPositionY() - 12);
                }
                else
                {
                    this->hint->gotoAndStop(param1 + 2);
                    this->hint->y = this->tempObject.y - 12;
                }
                this->hint->setPositionX(this->tempObject->getPositionX() + 12);
            }
            else if (this->tempObject.x > Main::SCREEN_WIDTH - 120)
            {
                if (this->tempObject.y < 120)
                {
                    this->hint->gotoAndStop(param1 + 3);
                    this->hint->setPositionY(this->tempObject->getPositionY() + 12);
                }
                else if (this->tempObject.y > Main::SCREEN_HEIGHT - 120)
                {
                    this->hint->gotoAndStop((param1 + 1));
                    this->hint->y = this->tempObject.y - 12;
                    this->hint->setPositionY(this->tempObject->getPositionY() - 12);
                }
                else
                {
                    this->hint->gotoAndStop((param1 + 1));
                    this->hint->setPositionY(this->tempObject->getPositionY() + 12);
                }
                this->hint->setPositionX(this->tempObject->getPositionX() - 12);
            }
            else if (this->tempObject.y < 120)
            {
                if (this->tempObject.x < 120)
                {
                    this->hint->gotoAndStop(param1 + 4);
                    this->hint->setPositionX(this->tempObject->getPositionX() + 12);
                    this->hint->setPositionY(this->tempObject->getPositionY() + 12);
                }
                else if (this->tempObject.x > Main::SCREEN_WIDTH - 120)
                {
                    this->hint->gotoAndStop(param1 + 3); 
                    this->hint->setPositionX(this->tempObject->getPositionX() - 12);
                    this->hint->setPositionY(this->tempObject->getPositionY() + 12);
                }
                else
                {
                    this->hint->gotoAndStop(param1 + 4);
                    this->hint->setPositionX(this->tempObject->getPositionX());
                    this->hint->setPositionY(this->tempObject->getPositionY() + 12); 
                }
            }
            else if (this->tempObject.y > Main::SCREEN_HEIGHT - 120)
            {
                if (this->tempObject.x < 120)
                {
                    this->hint->gotoAndStop(param1 + 2);
                    this->hint->setPositionX(this->tempObject->getPositionX() + 12);
                    this->hint->setPositionY(this->tempObject->getPositionY() - 12);
                }
                else if (this->tempObject.x > Main::SCREEN_WIDTH - 120)
                {
                    this->hint->gotoAndStop((param1 + 1)); 
                    this->hint->setPositionX(this->tempObject->getPositionX() - 12);
                    this->hint->setPositionY(this->tempObject->getPositionY() - 12);
                }
                else
                {
                    this->hint->gotoAndStop(param1 + 2);
                    this->hint->x = this->tempObject.x;
                    this->hint->y = this->tempObject.y - 12;
                    this->hint->setPositionX(this->tempObject->getPositionX());
                    this->hint->setPositionY(this->tempObject->getPositionY() - 12);
                }
            }
            else
            {
                this->hint->gotoAndStop(param1 + 2); 
                this->hint->setPositionX(this->tempObject->getPositionX());
                this->hint->setPositionY(this->tempObject->getPositionY() - 12);
            }
            return;
        }// end function

        void UltraTowerMenu::closeMenu(bool param1 )
        {
            this->mouseChildren = false;
            this->mouseEnabled = false;
            this->closeFlag = true;
            this->towerRadius->setVisible(false);
            this->world->ultraTowerMenu = NULL;
            if (!this->myTower->blockTowerFlag)
            {
                this->myTower->mouseChildren = true;
                this->myTower->mouseEnabled = true;
            }
            this->world->worldInterface->archiveSphereBacklightManage("");
            if (this->hint)
            {
                this->world->removeChild(this->hint);
            }
            this->world->worldInterface->updateInfo();
            if (!this->world->getSphere && !this->world->cast)
            {
                this->world->worldInterface->barInfoManage();
            }
            if (!param1)
            {
                //this->world->listOfIndexes3.push(this);
            }
            else
            {
                this->kill();
            }
            return;
        }// end function

        void UltraTowerMenu::kill()
        {
            if (!this->dead)
            {
                this->dead = true;
                this->world->worldInterface->updateInfo();
                this->world->removeChild(this);
                //this->i = 0;
                //while (this->i < this->world->listOfClasses.length)
                //{
                //    
                //    if (this->world->listOfClasses[this->i] == this)
                //    {
                //        this->world->listOfClasses.splice(this->i, 1);
                //        break;
                //    }
                //    i++;
                //}
                //this->i = 0;
                //while (this->i < this->world->listOfIndexes3.length)
                //{
                //    
                //    if (this->world->listOfIndexes3[this->i] == this)
                //    {
                //        this->world->listOfIndexes3.splice(this->i, 1);
                //        break;
                //    }
                //   i++;
                //}
                if (this->lastE)
                {
                    this->world->mouseMoveHandler(this->lastE);
                }
            }
            return;
        }// end function
    }
}
