#include "UltraTowerMenu.h"
#include "engine/World.h"
#include "engine/WorldInterface.h"
#include "engine/GetSphere.h"

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
            container = new UltraTowerMenu_mc();
            container->stop();
            container->btnUpgradeMenu->stop();
            container->sphereSlot1->stop();
            container->sphereSlot2->stop();
            container->sphereSlot1SphereAnima->stop();
            container->sphereSlot2SphereAnima->stop();
            container->sphereSlot1SphereAnimaCont->stop();
            container->sphereSlot2SphereAnimaCont->stop();
            container->sellUltraTower->stop();
            container->sellUltraTowerSellUltraTowerCase->stop();
            container->sellUltraTowerSellUltraTowerCase->buttonMode = true;
            this->addChild(container);
            this->world->listOfClasses.push(this);
            if (this->myTower->upgradeTypeAdd == 1)
            {
                container->sphereSlot1->setVisible(false);
                container->sphereSlot2->setVisible(false);
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
                if (container->getScaleX() < 1)
                {
					container->setScaleX(container->getScaleX() + 0.2);//scaleX = container->scaleX + 0.2;
					container->setScaleY(container->getScaleY() + 0.2);//scaleY = container->scaleY + 0.2;
                }
                else
                {
                    this->openFlag = false; 
                    container->setScaleY(1);//scaleY = 1;
                    container->setScaleX(1);//scaleX = 1; 
                    this->mouseChildren = true;
                    this->mouseEnabled = true;
                    this->autoguidersButtons();
                }
            }
            else
            {
                if (container->sphereSlot1SphereAnima->isVisible())
                {
                    if (container->sphereSlot1SphereAnima->currentFrame == 1)
                    {
                        if (container->sphereSlot1SphereAnimaCont->currentFrame < container->sphereSlot1SphereAnimaCont->totalFrames)
                        {
                            container->sphereSlot1SphereAnimaCont->gotoAndStop((container->sphereSlot1SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            container->sphereSlot1SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (container->sphereSlot1SphereAnima->currentFrame == 2)
                    {
                        if (container->sphereSlot1SphereAnimaCont->currentFrame < container->sphereSlot1SphereAnimaCont->totalFrames)
                        {
                            container->sphereSlot1SphereAnimaCont->gotoAndStop((container->sphereSlot1SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            container->sphereSlot1SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (container->sphereSlot1SphereAnima->currentFrame == 3)
                    {
                        if (container->sphereSlot1SphereAnimaCont->currentFrame < container->sphereSlot1SphereAnimaCont->totalFrames)
                        {
                            container->sphereSlot1SphereAnimaCont->gotoAndStop((container->sphereSlot1SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            container->sphereSlot1SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (container->sphereSlot1SphereAnima->currentFrame == 4)
                    {
                        if (container->sphereSlot1SphereAnimaCont->currentFrame < container->sphereSlot1SphereAnimaCont->totalFrames)
                        {
                            container->sphereSlot1SphereAnimaCont->gotoAndStop((container->sphereSlot1SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            container->sphereSlot1SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                }
                if (container->sphereSlot2SphereAnima->isVisible())
                {
                    if (container->sphereSlot2SphereAnima->currentFrame == 1)
                    {
                        if (container->sphereSlot2SphereAnimaCont->currentFrame < container->sphereSlot2SphereAnimaCont->totalFrames)
                        {
                            container->sphereSlot2SphereAnimaCont->gotoAndStop((container->sphereSlot2SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            container->sphereSlot2SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (container->sphereSlot2SphereAnima->currentFrame == 2)
                    {
                        if (container->sphereSlot2SphereAnimaCont->currentFrame < container->sphereSlot2SphereAnimaCont->totalFrames)
                        {
                            container->sphereSlot2SphereAnimaCont->gotoAndStop((container->sphereSlot2SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            container->sphereSlot2SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (container->sphereSlot2SphereAnima->currentFrame == 3)
                    {
                        if (container->sphereSlot2SphereAnimaCont->currentFrame < container->sphereSlot2SphereAnimaCont->totalFrames)
                        {
                            container->sphereSlot2SphereAnimaCont->gotoAndStop((container->sphereSlot2SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            container->sphereSlot2SphereAnimaCont->gotoAndStop(1);
                        }
                    }
                    else if (container->sphereSlot2SphereAnima->currentFrame == 4)
                    {
                        if (container->sphereSlot2SphereAnimaCont->currentFrame < container->sphereSlot2SphereAnimaCont->totalFrames)
                        {
                            container->sphereSlot2SphereAnimaCont->gotoAndStop((container->sphereSlot2SphereAnimaCont->currentFrame + 1));
                        }
                        else
                        {
                            container->sphereSlot2SphereAnimaCont->gotoAndStop(1);
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
                    if (container->fastBuyUltraCont->currentFrame > 1)
                    {
                        container->fastBuyUltraCont->gotoAndStop((container->fastBuyUltraCont->currentFrame - 1));
                    }
                    else
                    {
                        this->closeFastBuyUltraFlag = false;
                        this->openFastBuyUltraFlag = false;
                        container->fastBuyUltraCont->setVisible(false);
                    }
                }
                else if (this->openFastBuyUltraFlag)
                {
                    if (!container->fastBuyUltraCont->isVisible())
                    {
                        container->fastBuyUltraCont->setVisible(true);
                    }
                    else if (container->fastBuyUltraCont->currentFrame < container->fastBuyUltraCont->totalFrames)
                    {
                        container->fastBuyUltraCont->gotoAndStop((container->fastBuyUltraCont->currentFrame + 1));
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
                    container->btnUpgradeMenuCostTXT->setVisible(false);
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
        
        void UltraTowerMenu::mouseMoveHandler(cocos2d::EventMouse *e)
        {
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if(!event)
				return;
            if (event->target->getName() == "btnUpgradeMenuCase")
            {
                if (container->btnUpgradeMenu->currentFrame == 1)
                {
                    container->btnUpgradeMenu->gotoAndStop(2);
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
                if (container->btnUpgradeMenu->currentFrame == 2)
                {
                    container->btnUpgradeMenu->gotoAndStop(1);
                }
                if (event->target->getName() == "btnUpgradeMenuBLOCKCase")
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
                else if (event->target->getName() == "btnUpgradeMenuLOCKCase")
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
            if (event->target->getName() == "btnUpgradeMenuCase" || event->target->getName() == "btnUpgradeMenuBLOCKCase" || event->target->getName() == "fastBuyUltraCase")
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
            else if (event->target->getName() != "sphereSlotCase")
            {
                if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->iceBacklight->isVisible() 
                    || this->world->worldInterface->container->stoneBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
                {
                    this->world->worldInterface->archiveSphereBacklightManage("");
                }
            }
			if(event->target->getName() == "sphereSlotCase")
			{
				Node * parent = event->target->getParent()->getParent()->getParent();
				UltraTowerMenu_mc * towerMenuMc = ISTYPE(UltraTowerMenu_mc, parent);
				MCCase * scase = ISTYPE(MCCase, event->target);
				//UltraTowerMenu_mc  event->target->getParent()->getParent()->getParent()
				MovieClipSub  * sphereSlot = scase->getParentMC<MovieClipSub>();// towerMenuMc->getSphereSlot(scase);//ISTYPE(MovieClipSub, event->target->getParent());
				MovieClip *	sphereAnima = sphereSlot->getMem<MovieClip>("sphereAnima");
				if(sphereAnima->isVisible())
				{
					if(event->target->getParent()->getName() == "sphereSlot1")
					{
						if(container->sphereSlot2->currentFrame == 2)
						{
							container->sphereSlot2->gotoAndStop(1);
						}
					}
					else if(event->target->getParent()->getName() == "sphereSlot2")
					{
						if(container->sphereSlot1->currentFrame == 2)
						{
							container->sphereSlot1->gotoAndStop(1);
						}
					}
					if(sphereSlot->currentFrame == 1)
					{
						sphereSlot->gotoAndStop(2);
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
				}
				else if(sphereSlot->currentFrame == 2)
				{
					sphereSlot->gotoAndStop(1);
				}
			}
            else
            {
                if (container->sphereSlot1->currentFrame == 2)
                {
                    container->sphereSlot1->gotoAndStop(1);
                }
                if (container->sphereSlot2->currentFrame == 2)
                {
                    container->sphereSlot2->gotoAndStop(1);
                }
            }
            if (event->target->getName() == "sellUltraTowerCase")
            {
                if (container->sellUltraTower->currentFrame == 1)
                {
                    container->sellUltraTower->gotoAndStop(2);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (container->sellUltraTower->currentFrame == 2)
            {
                container->sellUltraTower->gotoAndStop(1);
            }
            if (!this->openFastBuyUltraFlag && !this->closeFastBuyUltraFlag)
            {
                if (event->target->getName() == "fastBuyUltraCase" && container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode)
                {
                    if (container->fastBuyUltraContBtnFastBuyUltra->currentFrame == 1)
                    {
                        container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(2);
                        std::setText(container->fastBuyUltraContBtnFastBuyUltraCostTXT, this->fastBuyPrice);
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
                else if (container->fastBuyUltraContBtnFastBuyUltra->currentFrame == 2)
                {
                    container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(1);
                    std::setText(container->fastBuyUltraContBtnFastBuyUltraCostTXT, this->fastBuyPrice);
                    //container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyPrice;
                    if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->iceBacklight->isVisible() || this->world->worldInterface->container->stoneBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
                    {
                        this->world->worldInterface->archiveSphereBacklightManage("");
                    }
                }
            }
            return;
        }// end function

        void UltraTowerMenu::mouseDownHandler(cocos2d::EventMouse *e)
        {
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if(!event)
				return;
            if (event->target->getName() == "btnUpgradeMenuCase")
            {
                if (container->btnUpgradeMenu->currentFrame == 2)
                {
                    container->btnUpgradeMenu->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->getName() == "sphereSlotCase")
            {
				Node * parent = event->target->getParent()->getParent()->getParent();
				UltraTowerMenu_mc * towerMenuMc = ISTYPE(UltraTowerMenu_mc, parent);
				MCCase * scase = ISTYPE(MCCase, event->target);
				//UltraTowerMenu_mc  event->target->getParent()->getParent()->getParent()
				MovieClipSub  * sphereSlot = scase->getParentMC<MovieClipSub>();// towerMenuMc->getSphereSlot(scase);//ISTYPE(MovieClipSub, event->target->getParent());
				MovieClip *	sphereAnima = sphereSlot->getMem<MovieClip>("sphereAnima");
                if (sphereSlot->currentFrame < 4)
                {
                    if (sphereAnima->currentFrame == 1)
                    {
                        this->myTower->towerGetSphereManage("get", "fire");
                    }
                    else if (sphereAnima->currentFrame == 2)
                    {
                        this->myTower->towerGetSphereManage("get", "ice");
                    }
                    else if (sphereAnima->currentFrame == 3)
                    {
                        this->myTower->towerGetSphereManage("get", "stone");
                    }
                    else if (sphereAnima->currentFrame == 4)
                    {
                        this->myTower->towerGetSphereManage("get", "levin");
                    }
                    if (!this->world->getSphere)
                    {
                        if (sphereSlot->getName() == "sphereSlot1")
                        {
                            if (this->myTower->towerType == 5)
                            {
                                if (this->world->worldInterface->container->fireSphere->getAlpha() == 1 && this->world->worldInterface->container->fireSphere->isVisible())
                                {
                                    this->world->worldInterface->container->fireBacklightTurnFlag = false;
                                    this->world->worldInterface->container->fireBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->fireBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 6)
                            {
								if(this->world->worldInterface->container->iceSphere->getAlpha() == 1 && this->world->worldInterface->container->iceSphere->isVisible())
                                {
                                    this->world->worldInterface->container->iceBacklightTurnFlag = false;
                                    this->world->worldInterface->container->iceBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->iceBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 7)
                            {
								if(this->world->worldInterface->container->iceSphere->getAlpha() == 1 && this->world->worldInterface->container->iceSphere->isVisible())
                                {
                                    this->world->worldInterface->container->iceBacklightTurnFlag = false;
                                    this->world->worldInterface->container->iceBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->iceBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 8)
                            {
								if(this->world->worldInterface->container->fireSphere->getAlpha() == 1 && this->world->worldInterface->container->fireSphere->isVisible())
                                {
                                    this->world->worldInterface->container->fireBacklightTurnFlag = false;
                                    this->world->worldInterface->container->fireBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->fireBacklight->setVisible(true);
                                }
                            }
                        }
                        else if (sphereSlot->getName() == "sphereSlot2")
                        {
                            if (this->myTower->towerType == 5)
                            {
                                if (this->world->worldInterface->container->stoneSphere->getAlpha() == 1 && this->world->worldInterface->container->stoneSphere->isVisible())
                                {
                                    this->world->worldInterface->container->stoneBacklightTurnFlag = false;
                                    this->world->worldInterface->container->stoneBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->stoneBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 6)
                            {
                                if (this->world->worldInterface->container->levinSphere->getAlpha() == 1 && this->world->worldInterface->container->levinSphere->isVisible())
                                {
                                    this->world->worldInterface->container->levinBacklightTurnFlag = false;
                                    this->world->worldInterface->container->levinBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->levinBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 7)
                            {
                                if (this->world->worldInterface->container->stoneSphere->getAlpha() == 1 && this->world->worldInterface->container->stoneSphere->isVisible())
                                {
                                    this->world->worldInterface->container->stoneBacklightTurnFlag = false;
                                    this->world->worldInterface->container->stoneBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->stoneBacklight->setVisible(true);
                                }
                            }
                            else if (this->myTower->towerType == 8)
                            {
                                if (this->world->worldInterface->container->levinSphere->getAlpha() == 1 && this->world->worldInterface->container->levinSphere->isVisible())
                                {
                                    this->world->worldInterface->container->levinBacklightTurnFlag = false;
                                    this->world->worldInterface->container->levinBacklight->gotoAndStop(2);
                                    this->world->worldInterface->container->levinBacklight->setVisible(true);
                                }
                            }
                        }
                    }
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->getName() == "sellUltraTowerCase")
            {
                if (container->sellUltraTower->currentFrame == 2)
                {
                    container->sellUltraTower->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->getName() == "fastBuyUltraCase")
            {
                if (!this->openFastBuyUltraFlag && !this->closeFastBuyUltraFlag)
                {
                    if (container->fastBuyUltraContBtnFastBuyUltra->currentFrame == 2 && container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode)
                    {
                        container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(1);
                        std::setText(container->fastBuyUltraContBtnFastBuyUltraCostTXT, this->fastBuyPrice);
                        //container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyPrice;
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
            else if (event->target->getName() != "buySphereCase" && event->target->getName() != "sphereCase" && event->target->getName() != "btnUpgradeMenuBLOCKCase"
                 && event->target->getParent() != container && event->target->getParent()->getParent() != container)
            {
                this->lastE = event;
                this->closeMenu();
            }
            return;
        }// end function

        void UltraTowerMenu::mouseUpHandler(cocos2d::EventMouse *e)
        {
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if(!event)
				return;
            if (event->target->getName() == "btnUpgradeMenuCase")
            {
                if (container->btnUpgradeMenu->currentFrame == 3)
                {
                    container->btnUpgradeMenu->gotoAndStop(4);
                    if (this->myTower->towerType == 5)
                    {
                        std::setText(container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costUltraAddFireStone);
                        //container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddFireStone;
                    }
                    else if (this->myTower->towerType == 6)
                    {
                        std::setText(container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costUltraAddIceLevin);
                        //container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddIceLevin;
                    }
                    else if (this->myTower->towerType == 7)
                    {
                        std::setText(container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costUltraAddIceStone);
                        //container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddIceStone;
                    }
                    else if (this->myTower->towerType == 8)
                    {
                        std::setText(container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costUltraAddFireLevin);
                        //container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddFireLevin;
                    }
                    if (!this->fastBuyUltraFlag.empty())
                    {
                        this->fastBuyUltraFlag = "upgrade";
                        this->openFastBuyUltraFlag = true;
                        this->fastBuyUltraManage();
                    }
                    else if (event->target->getParent()->getName() == this->fastBuyUltraFlag)
                    {
                        this->fastBuyUltraFlag = "";
                        this->closeFastBuyUltraFlag = true;
                        this->mouseMoveHandler(event);
                    }
                }
            }
            else if (container->btnUpgradeMenu->currentFrame == 3)
            {
                container->btnUpgradeMenu->gotoAndStop(1);
            }
            if (event->target->getName() == "sellUltraTowerCase")
            {
                if (container->sellUltraTower->currentFrame == 3)
                {
					float tempObject = 0;
                    container->sellUltraTower->gotoAndStop(2);
                    if (this->myTower->towerType == 5)
                    {
                          tempObject = std::round(Main::mainClass->readXMLClass.costUltraFireStone - Main::mainClass->readXMLClass.costUltraFireStone * this->sellTax);
                        if (this->myTower->upgradeTypeAdd == 0)
                        {
                            if (this->myTower->shootingTurnStack[0])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphereMyPoint;
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
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphereMyPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "stone", 1);
                                this->world->getSphere->manage("add", "stone");
                                this->world->getSphere->setPosition(this->myTower->this_pt); 
                                this->world->getSphere->retrieveGetSphere();
                            }
                        }
                        else if (this->myTower->upgradeTypeAdd == 1)
                        {
                            tempObject = tempObject + std::round(Main::mainClass->readXMLClass.costUltraAddFireStone - Main::mainClass->readXMLClass.costUltraAddFireStone * this->sellTax);
                            this->world->worldInterface->sellSphere("fire");
                            this->world->worldInterface->sellSphere("stone");
                        }
                    }
                    else if (this->myTower->towerType == 6)
                    {
                          tempObject = std::round(Main::mainClass->readXMLClass.costUltraIceLevin - Main::mainClass->readXMLClass.costUltraIceLevin * this->sellTax);
                        if (this->myTower->upgradeTypeAdd == 0)
                        {
                            if (this->myTower->shootingTurnStack[1])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphereMyPoint;
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
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphereMyPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "levin", 1);
                                this->world->getSphere->manage("add", "levin");
                                this->world->getSphere->setPosition(this->myTower->this_pt); 
                                this->world->getSphere->retrieveGetSphere();
                            }
                        }
                        else if (this->myTower->upgradeTypeAdd == 1)
                        {
                            tempObject = tempObject + std::round(Main::mainClass->readXMLClass.costUltraAddIceLevin - Main::mainClass->readXMLClass.costUltraAddIceLevin * this->sellTax);
                            this->world->worldInterface->sellSphere("ice");
                            this->world->worldInterface->sellSphere("levin");
                        }
                    }
                    else if (this->myTower->towerType == 7)
                    {
                          tempObject = std::round(Main::mainClass->readXMLClass.costUltraIceStone - Main::mainClass->readXMLClass.costUltraIceStone * this->sellTax);
                        if (this->myTower->upgradeTypeAdd == 0)
                        {
                            if (this->myTower->shootingTurnStack[1])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphereMyPoint;
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
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphereMyPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "stone", 1);
                                this->world->getSphere->manage("add", "stone");
                                this->world->getSphere->setPosition(this->myTower->this_pt); 
                                this->world->getSphere->retrieveGetSphere();
                            }
                        }
                        else if (this->myTower->upgradeTypeAdd == 1)
                        {
                            tempObject = tempObject + std::round(Main::mainClass->readXMLClass.costUltraAddIceStone - Main::mainClass->readXMLClass.costUltraAddIceStone * this->sellTax);
                            this->world->worldInterface->sellSphere("ice");
                            this->world->worldInterface->sellSphere("stone");
                        }
                    }
                    else if (this->myTower->towerType == 8)
                    {
                        tempObject = std::round(Main::mainClass->readXMLClass.costUltraFireLevin - Main::mainClass->readXMLClass.costUltraFireLevin * this->sellTax);
                        if (this->myTower->upgradeTypeAdd == 0)
                        {
                            if (this->myTower->shootingTurnStack[0])
                            {
                                this->world->getSphere = new GetSphere();
                                this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
                                this->world->getSphere->ownerType = "archive";
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphereMyPoint;
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
                                this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphereMyPoint;
                                this->world->addChild(this->world->getSphere);
                                this->myTower->spheresManage("get", "levin", 1);
                                this->world->getSphere->manage("add", "levin");
                                this->world->getSphere->setPosition(this->myTower->this_pt);
                                this->world->getSphere->retrieveGetSphere();
                            }
                        }
                        else if (this->myTower->upgradeTypeAdd == 1)
                        {
                            tempObject = tempObject + std::round(Main::mainClass->readXMLClass.costUltraAddFireLevin - Main::mainClass->readXMLClass.costUltraAddFireLevin * this->sellTax);
                            this->world->worldInterface->sellSphere("fire");
                            this->world->worldInterface->sellSphere("levin");
                        }
                    }
                    this->world->money = this->world->money + tempObject;
                    this->world->worldInterface->updateInfo();
                    this->closeMenu();
                    this->myTower->myPlace->gotoAndStop(1);
                    //this->myTower->myPlace->buildPoint->stop();
                    this->myTower->myPlace->placeForBuildCase->buttonMode = true;
                    this->myTower->kill();
                    //Sounds.instance.playSound("snd_tower_sell");
                }
            }
            else if (container->sellUltraTower->currentFrame == 3)
            {
                container->sellUltraTower->gotoAndStop(1);
            }
            return;
        }// end function
        void UltraTowerMenu::monitor()
        {
            if (this->myTower->towerType == 5)
            {
                if (Main::mainClass->readXMLClass.ultraTower1UpgrBlock == 0)
                {
                    container->sphereSlot1->gotoAndStop(1);
                    container->sphereSlot2->gotoAndStop(1);
                    container->sphereSlot1SphereAnima->gotoAndStop(1);
                    container->sphereSlot1SphereAnimaCont->stop();
                    container->sphereSlot2SphereAnima->gotoAndStop(3);
                    container->sphereSlot2SphereAnimaCont->stop();
                    if (!this->myTower->shootingTurnStack[0])
                    {
                        container->sphereSlot1SphereAnima->setVisible(false);
                        container->sphereSlot1SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        container->sphereSlot1SphereAnima->setVisible(true);
                        container->sphereSlot1SphereSlotCase->buttonMode = true;
                    }
                    if (!this->myTower->shootingTurnStack[2])
                    {
                        container->sphereSlot2SphereAnima->setVisible(false);
                        container->sphereSlot2SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        container->sphereSlot2SphereAnima->setVisible(true);
                        container->sphereSlot2SphereSlotCase->buttonMode = true;
                    }
                    if (this->myTower->upgradeTypeAdd == 1)
                    {
                        container->btnUpgradeMenu->setVisible(false);
                    }
                    else if (this->world->money >= Main::mainClass->readXMLClass.costUltraAddFireStone && !this->fastBuyUltraFlag.empty())
                    {
                        container->btnUpgradeMenu->gotoAndStop(1);
                        container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
                    }
                    else
                    {
                        container->btnUpgradeMenu->gotoAndStop(4);
                    }
					if (!this->fastBuyUltraFlag.empty())
                    {
                        std::setText(container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costUltraAddFireStone);
                        //container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddFireStone;
                    }
                }
                else
                {
                    container->btnUpgradeMenu->gotoAndStop(5);
                    container->sphereSlot1->gotoAndStop(4);
                    container->sphereSlot2->gotoAndStop(4);
                    container->sphereSlot1SphereAnima->gotoAndStop(1);
                    container->sphereSlot1SphereAnimaCont->stop();
                    container->sphereSlot2SphereAnima->gotoAndStop(3);
                    container->sphereSlot2SphereAnimaCont->stop();
                    container->sphereSlot1SphereAnima->setVisible(false);
                    container->sphereSlot1SphereSlotCase->buttonMode = false;
                    container->sphereSlot2SphereAnima->setVisible(false);
                    container->sphereSlot2SphereSlotCase->buttonMode = false;
                }
            }
            else if (this->myTower->towerType == 6)
            {
                if (Main::mainClass->readXMLClass.ultraTower2UpgrBlock == 0)
                {
                    container->sphereSlot1->gotoAndStop(1);
                    container->sphereSlot2->gotoAndStop(1);
                    container->sphereSlot1SphereAnima->gotoAndStop(2);
                    container->sphereSlot1SphereAnimaCont->stop();
                    container->sphereSlot2SphereAnima->gotoAndStop(4);
                    container->sphereSlot2SphereAnimaCont->stop();
                    if (!this->myTower->shootingTurnStack[1])
                    {
                        container->sphereSlot1SphereAnima->setVisible(false);
                        container->sphereSlot1SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        container->sphereSlot1SphereAnima->setVisible(true);
                        container->sphereSlot1SphereSlotCase->buttonMode = true;
                    }
                    if (!this->myTower->shootingTurnStack[3])
                    {
                        container->sphereSlot2SphereAnima->setVisible(false);
                        container->sphereSlot2SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        container->sphereSlot2SphereAnima->setVisible(true);
                        container->sphereSlot2SphereSlotCase->buttonMode = true;
                    }
                    if (this->myTower->upgradeTypeAdd == 1)
                    {
                        container->btnUpgradeMenu->setVisible(false);
                    }
					else if (this->world->money >= Main::mainClass->readXMLClass.costUltraAddIceLevin && !this->fastBuyUltraFlag.empty())
                    {
                        container->btnUpgradeMenu->gotoAndStop(1);
                        container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
                    }
                    else
                    {
                        container->btnUpgradeMenu->gotoAndStop(4);
                    }
					if (!this->fastBuyUltraFlag.empty())
                    {
                        std::setText(container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costUltraAddIceLevin);
                        //container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddIceLevin;
                    }
                }
                else
                {
                    container->btnUpgradeMenu->gotoAndStop(5);
                    container->sphereSlot1->gotoAndStop(4);
                    container->sphereSlot2->gotoAndStop(4);
                    container->sphereSlot1SphereAnima->gotoAndStop(2);
                    container->sphereSlot1SphereAnimaCont->stop();
                    container->sphereSlot2SphereAnima->gotoAndStop(4);
                    container->sphereSlot2SphereAnimaCont->stop();
                    container->sphereSlot1SphereAnima->setVisible(false);
                    container->sphereSlot1SphereSlotCase->buttonMode = false;
                    container->sphereSlot2SphereAnima->setVisible(false);
                    container->sphereSlot2SphereSlotCase->buttonMode = false;
                }
            }
            else if (this->myTower->towerType == 7)
            {
                if (Main::mainClass->readXMLClass.ultraTower3UpgrBlock == 0)
                {
                    container->sphereSlot1->gotoAndStop(1);
                    container->sphereSlot2->gotoAndStop(1);
                    container->sphereSlot1SphereAnima->gotoAndStop(2);
                    container->sphereSlot1SphereAnimaCont->stop();
                    container->sphereSlot2SphereAnima->gotoAndStop(3);
                    container->sphereSlot2SphereAnimaCont->stop();
                    if (!this->myTower->shootingTurnStack[1])
                    {
                        container->sphereSlot1SphereAnima->setVisible(false);
                        container->sphereSlot1SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        container->sphereSlot1SphereAnima->setVisible(true);
                        container->sphereSlot1SphereSlotCase->buttonMode = true;
                    }
                    if (!this->myTower->shootingTurnStack[2])
                    {
                        container->sphereSlot2SphereAnima->setVisible(false);
                        container->sphereSlot2SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        container->sphereSlot2SphereAnima->setVisible(true);
                        container->sphereSlot2SphereSlotCase->buttonMode = true;
                    }
                    if (this->myTower->upgradeTypeAdd == 1)
                    {
                        container->btnUpgradeMenu->setVisible(false);
                    }
					else if (this->world->money >= Main::mainClass->readXMLClass.costUltraAddIceStone && !this->fastBuyUltraFlag.empty())
                    {
                        container->btnUpgradeMenu->gotoAndStop(1);
                        container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
                    }
                    else
                    {
                        container->btnUpgradeMenu->gotoAndStop(4);
                    }
					if (!this->fastBuyUltraFlag.empty())
                    {
                        std::setText(container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costUltraAddIceStone);
                        //container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddIceStone;
                    }
                }
                else
                {
                    container->btnUpgradeMenu->gotoAndStop(5);
                    container->sphereSlot1->gotoAndStop(4);
                    container->sphereSlot2->gotoAndStop(4);
                    container->sphereSlot1SphereAnima->gotoAndStop(2);
                    container->sphereSlot1SphereAnimaCont->stop();
                    container->sphereSlot2SphereAnima->gotoAndStop(3);
                    container->sphereSlot2SphereAnimaCont->stop();
                    container->sphereSlot1SphereAnima->setVisible(false);
                    container->sphereSlot1SphereSlotCase->buttonMode = false;
                    container->sphereSlot2SphereAnima->setVisible(false);
                    container->sphereSlot2SphereSlotCase->buttonMode = false;
                }
            }
            else if (this->myTower->towerType == 8)
            {
                if (Main::mainClass->readXMLClass.ultraTower4UpgrBlock == 0)
                {
                    container->sphereSlot1->gotoAndStop(1);
                    container->sphereSlot2->gotoAndStop(1);
                    container->sphereSlot1SphereAnima->gotoAndStop(1);
                    container->sphereSlot1SphereAnimaCont->stop();
                    container->sphereSlot2SphereAnima->gotoAndStop(4);
                    container->sphereSlot2SphereAnimaCont->stop();
                    if (!this->myTower->shootingTurnStack[0])
                    {
                        container->sphereSlot1SphereAnima->setVisible(false);
                        container->sphereSlot1SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        container->sphereSlot1SphereAnima->setVisible(true);
                        container->sphereSlot1SphereSlotCase->buttonMode = true;
                    }
                    if (!this->myTower->shootingTurnStack[3])
                    {
                        container->sphereSlot2SphereAnima->setVisible(false);
                        container->sphereSlot2SphereSlotCase->buttonMode = false;
                    }
                    else
                    {
                        container->sphereSlot2SphereAnima->setVisible(true);
                        container->sphereSlot2SphereSlotCase->buttonMode = true;
                    }
                    if (this->myTower->upgradeTypeAdd == 1)
                    {
                        container->btnUpgradeMenu->setVisible(false);
                    }
					else if (this->world->money >= Main::mainClass->readXMLClass.costUltraAddFireLevin && !this->fastBuyUltraFlag.empty())
                    {
                        container->btnUpgradeMenu->gotoAndStop(1);
                        container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
                    }
                    else
                    {
                        container->btnUpgradeMenu->gotoAndStop(4);
                    }
					if (!this->fastBuyUltraFlag.empty())
                    {
                        std::setText(container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costUltraAddFireLevin);
                        //container->btnUpgradeMenu->costTXT.text = Main::mainClass->readXMLClass.costUltraAddFireLevin;
                    }
                }
                else
                {
                    container->btnUpgradeMenu->gotoAndStop(5);
                    container->sphereSlot1->gotoAndStop(4);
                    container->sphereSlot2->gotoAndStop(4);
                    container->sphereSlot1SphereAnima->gotoAndStop(1);
                    container->sphereSlot1SphereAnimaCont->stop();
                    container->sphereSlot2SphereAnima->gotoAndStop(4);
                    container->sphereSlot2SphereAnimaCont->stop();
                    container->sphereSlot1SphereAnima->setVisible(false);
                    container->sphereSlot1SphereSlotCase->buttonMode = false;
                    container->sphereSlot2SphereAnima->setVisible(false);
                    container->sphereSlot2SphereSlotCase->buttonMode = false;
                }
            }
            if (!this->fastBuyUltraFlag.empty())
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
			this->autoguidesObject_pt = container->sphereSlot1SphereSlotCase->localToGlobal(container->sphereSlot1SphereSlotCase->getPosition());
            this->autoguidesObjectWidth = container->sphereSlot1SphereSlotCase->getWidth() / 2;
            this->autoguidesObjectHeight = container->sphereSlot1SphereSlotCase->getHeight() / 2;
            //if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            //    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            //    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            //    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
			if (container->sphereSlot1SphereSlotCase->hitTest(autoguidesMouse_pt))
            {
                this->autoguidesObject = container->sphereSlot1SphereSlotCase;
            }
            if (!this->autoguidesObject)
            {
				this->autoguidesObject_pt = container->sphereSlot2SphereSlotCase->localToGlobal(container->sphereSlot2SphereSlotCase->getPosition());
				this->autoguidesObjectWidth = container->sphereSlot2SphereSlotCase->getWidth() / 2;
				this->autoguidesObjectHeight = container->sphereSlot2SphereSlotCase->getHeight() / 2;
                //if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                //    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                //    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                //    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
				if (container->sphereSlot2SphereSlotCase->hitTest(autoguidesMouse_pt))
				{
                    this->autoguidesObject = container->sphereSlot2SphereSlotCase;
                }
            }
            if (!this->autoguidesObject && container->btnUpgradeMenu->isVisible() && container->btnUpgradeMenuBtnUpgradeMenuCase)
            {
				this->autoguidesObject_pt = container->btnUpgradeMenuBtnUpgradeMenuCase->localToGlobal(container->btnUpgradeMenuBtnUpgradeMenuCase->getPosition());
				this->autoguidesObjectWidth = container->btnUpgradeMenuBtnUpgradeMenuCase->getWidth() / 2;
				this->autoguidesObjectHeight = container->btnUpgradeMenuBtnUpgradeMenuCase->getHeight() / 2;
                //if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                //    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                //    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                //    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
				if (container->btnUpgradeMenuBtnUpgradeMenuCase->hitTest(autoguidesMouse_pt))
				{
                    this->autoguidesObject = container->btnUpgradeMenuBtnUpgradeMenuCase;
                }
            }
            if (!this->autoguidesObject && !this->fastBuyUltraFlag.empty())
            {
				this->autoguidesObject_pt = container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->localToGlobal(container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->getPosition());
				this->autoguidesObjectWidth = container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->getWidth() / 2;
				this->autoguidesObjectHeight = container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->getHeight() / 2;
                //if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                //    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                //    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                //    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
				if (container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->hitTest(autoguidesMouse_pt))
				{
                    this->autoguidesObject = container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase;
                }
            }
            if (this->autoguidesObject)
            {
                //构造事件对象
				std::MouseEvent  me = this->buildMouseEvent(this->autoguidesObject);
                this->mouseMoveHandler(&me);
            }
            return;
        }// end function

        void UltraTowerMenu::fastBuyUltraManage()
        {
			UltraTowerMenu_mc * container = ISTYPE(UltraTowerMenu_mc, this->container);
            if (container->fastBuyUltraCont)
            {
                container->fastBuyUltraCont->stop();
                container->fastBuyUltraContBtnFastBuyUltra->stop();
                container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->stop();
                container->fastBuyUltraContIndicator1->stop();
                container->fastBuyUltraContIndicator2->stop();
                container->fastBuyUltraContIndicator3->stop();
                container->fastBuyUltraContIndicator4->stop();
                container->fastBuyUltraContIndicator2->setVisible(false);
                container->fastBuyUltraContIndicator3->setVisible(false);
                if (!this->fastBuyUltraFlag.empty() && !this->openFastBuyUltraFlag && !this->closeFastBuyUltraFlag)
                {
                    container->fastBuyUltraCont->setVisible(false);
                }
                if (!this->fastBuyUltraFlag.empty())
                {
                    container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(1);
                    container->fastBuyUltraContIndicator1->gotoAndStop(2);
                    container->fastBuyUltraContIndicator4->gotoAndStop(2);
                    container->fastBuyUltraContIndicator1->setVisible(true);
                    container->fastBuyUltraContIndicator4->setVisible(true);
                    if (!this->fastBuyBlockCost)
                    {
                        std::setText(container->fastBuyUltraContBtnFastBuyUltraCostTXT, this->fastBuyUltraScan());
                        //container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyUltraScan();
                    }
                    else
                    {
                        std::setText(container->fastBuyUltraContBtnFastBuyUltraCostTXT, this->fastBuyPrice);
                        //container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyPrice;
                    }
                    if (this->myTower->towerType == 5)
                    {
                        if (this->myTower->shootingTurnStack[0])
                        {
                            container->fastBuyUltraContIndicator1->gotoAndStop(1);
                        }
                        if (this->myTower->shootingTurnStack[2])
                        {
                            container->fastBuyUltraContIndicator4->gotoAndStop(1);
                        }
                    }
                    else if (this->myTower->towerType == 6)
                    {
                        if (this->myTower->shootingTurnStack[1])
                        {
                            container->fastBuyUltraContIndicator1->gotoAndStop(1);
                        }
                        if (this->myTower->shootingTurnStack[3])
                        {
                            container->fastBuyUltraContIndicator4->gotoAndStop(1);
                        }
                    }
                    else if (this->myTower->towerType == 7)
                    {
                        if (this->myTower->shootingTurnStack[1])
                        {
                            container->fastBuyUltraContIndicator1->gotoAndStop(1);
                        }
                        if (this->myTower->shootingTurnStack[2])
                        {
                            container->fastBuyUltraContIndicator4->gotoAndStop(1);
                        }
                    }
                    else if (this->myTower->towerType == 8)
                    {
                        if (this->myTower->shootingTurnStack[0])
                        {
                            container->fastBuyUltraContIndicator1->gotoAndStop(1);
                        }
                        if (this->myTower->shootingTurnStack[3])
                        {
                            container->fastBuyUltraContIndicator4->gotoAndStop(1);
                        }
                    }
                    this->fastBuyPrice = std::getInt(container->fastBuyUltraContBtnFastBuyUltraCostTXT);
					if (this->world->money >= this->fastBuyPrice)
                    {
                        container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode = true;
                    }
                    else
                    {
                        container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(4);
                        std::setText(container->fastBuyUltraContBtnFastBuyUltraCostTXT, this->fastBuyPrice);
                        //container->fastBuyUltraContBtnFastBuyUltra->costTXT.text = this->fastBuyPrice;
                        container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode = false;
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
                        tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfFirePriceXML[this->world->worldInterface->fireBuyHistory];
                    }
                }
                if (!this->myTower->shootingTurnStack[2])
                {
                    if (this->world->worldInterface->stoneCount == 0)
                    {
                        tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfStonePriceXML[this->world->worldInterface->stoneBuyHistory];
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
                        tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfIcePriceXML[this->world->worldInterface->iceBuyHistory];
                    }
                }
                if (!this->myTower->shootingTurnStack[3])
                {
                    if (this->world->worldInterface->levinCount == 0)
                    {
                        tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->world->worldInterface->levinBuyHistory];
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
                        tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfIcePriceXML[this->world->worldInterface->iceBuyHistory];
                    }
                }
                if (!this->myTower->shootingTurnStack[2])
                {
                    if (this->world->worldInterface->stoneCount == 0)
                    {
                        tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfStonePriceXML[this->world->worldInterface->stoneBuyHistory];
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
                        tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfFirePriceXML[this->world->worldInterface->fireBuyHistory];
                    }
                }
                if (!this->myTower->shootingTurnStack[3])
                {
                    if (this->world->worldInterface->levinCount == 0)
                    {
                        tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->world->worldInterface->levinBuyHistory];
                    }
                }
            }
            return tempObject1;
        }// end function

        void UltraTowerMenu::hintPosition(int param1 )
        {
            //tempObject = container->localToGlobal(new Point(container->btnUpgradeMenu->x, container->btnUpgradeMenu->y));
            cocos2d::Point tempObject = container->localToGlobal(container->btnUpgradeMenu->getPosition());
            param1 = param1 - 1;
            if (tempObject.x < 120)
            {
                if (tempObject.y < 120)
                {
                    this->hint->gotoAndStop(param1 + 4);
                    this->hint->setPositionY(tempObject.y + 12);
                }
                else if (tempObject.y > Main::SCREEN_HEIGHT - 120)
                {
                    this->hint->gotoAndStop(param1 + 2);
					this->hint->setPositionY(tempObject.y - 12);
                }
                else
                {
                    this->hint->gotoAndStop(param1 + 2);
                    this->hint->setPositionY(tempObject.y - 12);
                }
                this->hint->setPositionX(tempObject.x + 12);
            }
            else if (tempObject.x > Main::SCREEN_WIDTH - 120)
            {
                if (tempObject.y < 120)
                {
                    this->hint->gotoAndStop(param1 + 3);
                    this->hint->setPositionY(tempObject.y + 12);
                }
                else if (tempObject.y > Main::SCREEN_HEIGHT - 120)
                {
                    this->hint->gotoAndStop((param1 + 1));
					this->hint->setPositionY( tempObject.y - 12);
                    this->hint->setPositionY(tempObject.y - 12);
                }
                else
                {
                    this->hint->gotoAndStop((param1 + 1));
                    this->hint->setPositionY(tempObject.y + 12);
                }
                this->hint->setPositionX(tempObject.x - 12);
            }
            else if (tempObject.y < 120)
            {
                if (tempObject.x < 120)
                {
                    this->hint->gotoAndStop(param1 + 4);
                    this->hint->setPositionX(tempObject.x + 12);
                    this->hint->setPositionY(tempObject.y + 12);
                }
                else if (tempObject.x > Main::SCREEN_WIDTH - 120)
                {
                    this->hint->gotoAndStop(param1 + 3); 
                    this->hint->setPositionX(tempObject.x - 12);
                    this->hint->setPositionY(tempObject.y + 12);
                }
                else
                {
                    this->hint->gotoAndStop(param1 + 4);
                    this->hint->setPositionX(tempObject.x);
                    this->hint->setPositionY(tempObject.y + 12); 
                }
            }
            else if (tempObject.y > Main::SCREEN_HEIGHT - 120)
            {
                if (tempObject.x < 120)
                {
                    this->hint->gotoAndStop(param1 + 2);
                    this->hint->setPositionX(tempObject.x + 12);
                    this->hint->setPositionY(tempObject.y - 12);
                }
                else if (tempObject.x > Main::SCREEN_WIDTH - 120)
                {
                    this->hint->gotoAndStop((param1 + 1)); 
                    this->hint->setPositionX(tempObject.x - 12);
                    this->hint->setPositionY(tempObject.y - 12);
                }
                else
                {
                    this->hint->gotoAndStop(param1 + 2);
                    this->hint->setPosition( tempObject.x ,tempObject.y - 12); 
                }
            }
            else
            {
                this->hint->gotoAndStop(param1 + 2); 
                this->hint->setPositionX(tempObject.x);
                this->hint->setPositionY(tempObject.y - 12);
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
