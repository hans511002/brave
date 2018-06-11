#include "TowerMenu.h"
#include "engine/World.h"

namespace engine
{
	namespace towers
	{
		BaseTowerMenu::BaseTowerMenu() : myTower(NULL), world(NULL), dead(false), closeFlag(false), openFlag(true), towerRadius(NULL),
			openFastBuyUltraFlag(false), closeFastBuyUltraFlag(false), readyFastBuyUltraFlag(false), fastBuyBlockCost(false), fastBuyPrice(0)
		{
		};

		TowerMenu::TowerMenu(Tower * param1) :container(NULL), towerRadius1(NULL), exampleUltraTower(NULL), openUltraSection(false), hint(NULL),
			hint1(NULL), container1(NULL), starsAnima(NULL), training_12(NULL)
		{
			//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
			this->myTower = param1;
			return;
		}// end function

		bool TowerMenu::init()
		{
			//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
			this->world = Main::mainClass->worldClass;
			if (this->world->towerRadius->isVisible())
			{
				this->world->towerRadius->setVisible(false);
			}
			if (this->myTower->towerType < 5)
			{
				this->myTower->container->selectTower->setVisible(false);
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
			//this->towerRadius->x = this->x;
			//this->towerRadius->y = this->y;
			this->towerRadius->setPosition(this->getPosition());

			//this->towerRadius->mouseChildren = false;
			//this->towerRadius->mouseEnabled = false;
			this->world->addChild(this->towerRadius);
			this->towerRadius1 = new TowerRadius_mc();
			//this->towerRadius1->stop();
			this->towerRadius1->setContentSize(Size(this->myTower->radius * 2, this->myTower->radius * 2 * this->world->scaleRadius));
			//this->towerRadius1->width = this->myTower->radius * 2;
			//this->towerRadius1->height = this->myTower->radius * 2 * this->world->scaleRadius;
			this->towerRadius1->setPosition(this->getPosition());
			//this->towerRadius1->x = this->x;
			//this->towerRadius1->y = this->y; 
			//this->towerRadius1->mouseChildren = false;
			//this->towerRadius1->mouseEnabled = false;
			this->towerRadius1->setVisible(false);
			this->world->addChild(this->towerRadius1);
			this->container = new TowerMenu_mc();
			this->container->stop();
			this->container->btnUpgradeMenu->stop();
			this->container->btnGetAll->stop();
			this->container->sphereSlot1->stop();
			this->container->sphereSlot2->stop();
			this->container->sphereSlot3->stop();
			this->container->sphereSlot4->stop();
			this->container->sphereSlot1SphereAnima->stop();
			this->container->sphereSlot2SphereAnima->stop();
			this->container->sphereSlot3SphereAnima->stop();
			this->container->sphereSlot4SphereAnima->stop();
			this->container->sphereSlot1SphereAnimaCont->stop();
			this->container->sphereSlot2SphereAnimaCont->stop();
			this->container->sphereSlot3SphereAnimaCont->stop();
			this->container->sphereSlot4SphereAnimaCont->stop();
			this->container->cont1->stop();
			this->container->cont2->stop();
			this->addChild(this->container);
			//this->world->listOfClasses.push(this);
			if (this->myTower->spheresStack.size() > 0)
			{
				this->container->btnGetAllBtnGetAllCase->buttonMode = true;
			}
			if (this->myTower->towerType == 4)
			{
				this->container->gotoAndStop(this->container->totalFrames);
			}
			this->myTower->mouseChildren = false;
			this->myTower->mouseEnabled = false;
			this->world->worldInterface->barInfoManage(this);
			if (!this->hint)
			{
				this->hint = new TowerMenuHint_mc();
				this->hint->stop();
				this->hint->cont->stop();
				this->hint->contCont1->stop();
				this->hint->contCont1Sphere1->stop();
				this->hint->contCont1Sphere2->stop();
				this->hint->mouseChildren = false;
				this->hint->mouseEnabled = false;
				this->hint->setVisible(false);
				this->world->addChild(this->hint);
			}
			if (this->world->eduOpenUpgrArrowFlag)
			{
				if (this->world->nowLevel == 2 && this->world->saveBox->getIntValue("complexityLevel") < 4)
				{
					this->container->setVisible(false);
					this->container1 = new TowerMenu_mc();
					this->container1->stop();
					this->container1->btnUpgradeMenu->gotoAndStop(5);
					this->container1->btnGetAll->stop();
					this->container1->sphereSlot1->gotoAndStop(1);
					this->container1->sphereSlot2->gotoAndStop(4);
					this->container1->sphereSlot3->gotoAndStop(4);
					this->container1->sphereSlot4->gotoAndStop(4);
					this->container1->sphereSlot1SphereAnima->stop();
					this->container1->sphereSlot2SphereAnima->stop();
					this->container1->sphereSlot3SphereAnima->stop();
					this->container1->sphereSlot4SphereAnima->stop();
					this->container1->sphereSlot1SphereAnimaCont->stop();
					this->container1->sphereSlot2SphereAnimaCont->stop();
					this->container1->sphereSlot3SphereAnimaCont->stop();
					this->container1->sphereSlot4SphereAnimaCont->stop();
					this->container1->cont1->stop();
					this->container1->cont2->stop();
					this->container1->sphereSlot1SphereAnima->setVisible(false);
					this->container1->sphereSlot2SphereAnima->setVisible(false);
					this->container1->sphereSlot3SphereAnima->setVisible(false);
					this->container1->sphereSlot4SphereAnima->setVisible(false);
					this->container1->sphereSlot1->setVisible(false);
					this->container1->sphereSlot2->setVisible(false);
					this->container1->sphereSlot3->setVisible(false);
					this->container1->sphereSlot4->setVisible(false);

					this->container1->mouseChildren = false;
					this->container1->mouseEnabled = false;
					this->addChild(this->container1);
					this->starsAnima = new AnimUpgrade_mc();
					this->starsAnima->stop();
					this->starsAnima->setPosition(this->container->btnUpgradeMenu->getPosition());
					//this->starsAnima->x = this->container->btnUpgradeMenu->x;
					//this->starsAnima->y = this->container->btnUpgradeMenu->y;
					this->starsAnima->mouseChildren = false;
					this->starsAnima->mouseEnabled = false;
					this->addChild(this->starsAnima);
					//Sounds.instance.playSound("snd_menu_upgrIconMouseDown");
				}
				else
				{
					this->world->eduOpenUpgrArrowFlag = false;
				}
			}
			this->upgradeManage();
			this->spheresMonitor();
			this->world->worldInterface->updateInfo();
			return true;
		}// end function
		void TowerMenu::update(float dt)
		{
			if (!this->closeFlag)
			{
				if (this->openFlag)
				{
					if (this->container->getScaleX() < 1)
					{
						this->container->setScaleX(this->container->getScaleX() + 0.2);
						this->container->setScaleY(this->container->getScaleY() + 0.2);
						//this->container->scaleX = this->container->scaleX + 0.2;
						//this->container->scaleY = this->container->scaleY + 0.2;
					}
					else
					{
						this->openFlag = false;
						this->container->setScale(1);
						//this->container->scaleY = 1;
						//this->container->scaleX = 1;
						this->mouseChildren = true;
						this->mouseEnabled = true;
						this->autoguidersButtons();
						if (!this->training_12 && this->world->nowLevel > 1 && this->world->nowLevel < 5)
						{
							if (!Main::mainClass->saveBoxClass->getBoolValue("firstClickKeepAll"))
							{
								if (this->myTower->spheresStack.size()> 0)
								{
									//this->training_12 = new Training_12();
									//this->addChild(this->training_12);
								}
							}
						}
					}
				}
				else
				{
					if (this->world->eduOpenUpgrArrowFlag)
					{
						if (this->container1->btnGetAll->currentFrame < this->container1->btnGetAll->totalFrames)
						{
							this->container1->btnGetAll->gotoAndStop((this->container1->btnGetAll->currentFrame + 1));
						}
						else
						{
							this->container1->btnGetAll->gotoAndStop(1);
						}
						if (this->container1->cont1->currentFrame < this->container1->cont1->totalFrames)
						{
							this->container1->cont1->gotoAndStop((this->container1->cont1->currentFrame + 1));
						}
						else
						{
							this->container1->cont1->gotoAndStop(1);
						}
						if (this->container1->cont2->currentFrame < this->container1->cont2->totalFrames)
						{
							this->container1->cont2->gotoAndStop((this->container1->cont2->currentFrame + 1));
						}
						else
						{
							this->container1->cont2->gotoAndStop(1);
						}

						if (this->starsAnima->currentFrame < this->starsAnima->totalFrames)
						{
							this->starsAnima->gotoAndStop((this->starsAnima->currentFrame + 1));
							if (this->starsAnima->currentFrame == 12)
							{
								this->container1->btnUpgradeMenu->gotoAndStop(1);
								std::setText(this->container1->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costSlot2XML);
								//this->container1->btnUpgradeMenuCostTXT = Main::mainClass->readXMLClass.costSlot2XML;
								this->container1->sphereSlot2->gotoAndStop(3);
							}
						}
						else
						{
							this->container->setVisible(true);
							this->removeChild(this->starsAnima);
							this->starsAnima = NULL;
							this->removeChild(this->container1);
							this->container1 = NULL;
							this->world->eduOpenUpgrArrowFlag = false;
						}
					}
					if (this->container->btnGetAll->currentFrame < this->container->btnGetAll->totalFrames)
					{
						this->container->btnGetAll->gotoAndStop((this->container->btnGetAll->currentFrame + 1));
					}
					else
					{
						this->container->btnGetAll->gotoAndStop(1);
					}
					if (this->container->cont1->currentFrame < this->container->cont1->totalFrames)
					{
						this->container->cont1->gotoAndStop((this->container->cont1->currentFrame + 1));
					}
					else
					{
						this->container->cont1->gotoAndStop(1);
					}
					if (this->container->cont2->currentFrame < this->container->cont2->totalFrames)
					{
						this->container->cont2->gotoAndStop((this->container->cont2->currentFrame + 1));
					}
					else
					{
						this->container->cont2->gotoAndStop(1);
					}
					if (this->openUltraSection)
					{
						if (this->container->currentFrame < this->container->totalFrames)
						{
							this->container->gotoAndStop((this->container->currentFrame + 1));
							if (this->container->currentFrame == 4 || this->container->currentFrame == 6 || this->container->currentFrame == 9 || this->container->currentFrame == 11)
							{
								std::setText(this->container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costSlot4XML);
								//this->container->btnUpgradeMenuCostTXT = Main::mainClass->readXMLClass.costSlot4XML;
							}
							else if (this->container->currentFrame == 13 || this->container->currentFrame == 15 || this->container->currentFrame == 17 || this->container->currentFrame == 19 || this->container->currentFrame == 21 || this->container->currentFrame == 23 || this->container->currentFrame == 25)
							{
								this->upgradeManage();
							}
						}
						else
						{
							this->openUltraSection = false;
							this->mouseChildren = true;
							this->mouseEnabled = true;
							this->upgradeManage();
							this->autoguidersButtons();
						}
					}
					if (this->hint)
					{
						if (this->hint->isVisible())
						{
							if (this->hint->currentFrame < 5)
							{
								if (this->hint->contCont1Sphere1->currentFrame < this->hint->contCont1Sphere1->totalFrames)
								{
									this->hint->contCont1Sphere1->gotoAndStop((this->hint->contCont1Sphere1->currentFrame + 1));
								}
								else
								{
									this->hint->contCont1Sphere1->gotoAndStop(1);
								}
								if (this->hint->contCont1Sphere2->currentFrame < this->hint->contCont1Sphere2->totalFrames)
								{
									this->hint->contCont1Sphere2->gotoAndStop((this->hint->contCont1Sphere2->currentFrame + 1));
								}
								else
								{
									this->hint->contCont1Sphere2->gotoAndStop(1);
								}
							}
						}
					}
					if (this->exampleUltraTower)
					{
						if (ISTYPE(Tower5_mc, this->exampleUltraTower))
						{
							Tower5_mc * tower = ISTYPE(Tower5_mc, this->exampleUltraTower);
							if (this->world->frameCounter % 2)
							{
								if (tower->currentFrame < tower->totalFrames)
								{
									tower->gotoAndStop((tower->currentFrame + 1));
								}
								else
								{
									tower->gotoAndStop(1);
								}
							}
						}
						else if (ISTYPE(Tower6_mc, this->exampleUltraTower))
						{
							Tower6_mc * tower = ISTYPE(Tower6_mc, this->exampleUltraTower);
							if (this->world->frameCounter % 2)
							{
								if (tower->currentFrame < exampleUltraTower->totalFrames)
								{
									tower->gotoAndStop((tower->currentFrame + 1));
								}
								else
								{
									tower->gotoAndStop(1);
								}
							}
						}
						else if (ISTYPE(Tower7_mc, this->exampleUltraTower))
						{
							Tower7_mc * tower = ISTYPE(Tower7_mc, this->exampleUltraTower);
							if (tower->cont1->currentFrame < tower->cont1->totalFrames)
							{
								tower->cont1->gotoAndStop((tower->cont1->currentFrame + 1));
							}
							else
							{
								tower->cont1->gotoAndStop(1);
							}
							if (tower->cont2->currentFrame < tower->cont2->totalFrames)
							{
								tower->cont2->gotoAndStop((tower->cont2->currentFrame + 1));
							}
							else
							{
								tower->cont2->gotoAndStop(1);
							}
							if (tower->cont3->currentFrame < tower->cont3->totalFrames)
							{
								tower->cont3->gotoAndStop((tower->cont3->currentFrame + 1));
							}
							else
							{
								tower->cont3->gotoAndStop(1);
							}
						}
						else if (ISTYPE(Tower8_mc, this->exampleUltraTower))
						{
							Tower8_mc * tower = ISTYPE(Tower8_mc, this->exampleUltraTower);
							if (this->world->frameCounter % 2)
							{
								if (tower->cont1->currentFrame < tower->cont1->totalFrames)
								{
									tower->cont1->gotoAndStop((tower->cont1->currentFrame + 1));
								}
								else
								{
									tower->cont1->gotoAndStop(1);
								}
								if (tower->cont2->currentFrame < tower->cont2->totalFrames)
								{
									tower->cont2->gotoAndStop((tower->cont2->currentFrame + 1));
								}
								else
								{
									tower->cont2->gotoAndStop(1);
								}
								if (tower->cont3->currentFrame < tower->cont3->totalFrames)
								{
									tower->cont3->gotoAndStop((tower->cont3->currentFrame + 1));
								}
								else
								{
									tower->cont3->gotoAndStop(1);
								}
							}
							tower->cont2->setRotation( tower->cont2->getRotation() + 3);
						}
					}
					if (this->container->sphereSlot1->isVisible())
					{
						if (this->container->sphereSlot1->currentFrame == 1)
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
					if (this->container->sphereSlot2->isVisible())//(this->container->sphereSlot2SphereAnima->isVisible())
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
					if (this->container->sphereSlot3->isVisible())
					{
						if (this->container->sphereSlot3SphereAnima->currentFrame == 1)
						{
							if (this->container->sphereSlot3SphereAnimaCont->currentFrame < this->container->sphereSlot3SphereAnimaCont->totalFrames)
							{
								this->container->sphereSlot3SphereAnimaCont->gotoAndStop((this->container->sphereSlot3SphereAnimaCont->currentFrame + 1));
							}
							else
							{
								this->container->sphereSlot3SphereAnimaCont->gotoAndStop(1);
							}
						}
						else if (this->container->sphereSlot3SphereAnima->currentFrame == 2)
						{
							if (this->container->sphereSlot3SphereAnimaCont->currentFrame < this->container->sphereSlot3SphereAnimaCont->totalFrames)
							{
								this->container->sphereSlot3SphereAnimaCont->gotoAndStop((this->container->sphereSlot3SphereAnimaCont->currentFrame + 1));
							}
							else
							{
								this->container->sphereSlot3SphereAnimaCont->gotoAndStop(1);
							}
						}
						else if (this->container->sphereSlot3SphereAnima->currentFrame == 3)
						{
							if (this->container->sphereSlot3SphereAnimaCont->currentFrame < this->container->sphereSlot3SphereAnimaCont->totalFrames)
							{
								this->container->sphereSlot3SphereAnimaCont->gotoAndStop((this->container->sphereSlot3SphereAnimaCont->currentFrame + 1));
							}
							else
							{
								this->container->sphereSlot3SphereAnimaCont->gotoAndStop(1);
							}
						}
						else if (this->container->sphereSlot3SphereAnima->currentFrame == 4)
						{
							if (this->container->sphereSlot3SphereAnimaCont->currentFrame < this->container->sphereSlot3SphereAnimaCont->totalFrames)
							{
								this->container->sphereSlot3SphereAnimaCont->gotoAndStop((this->container->sphereSlot3SphereAnimaCont->currentFrame + 1));
							}
							else
							{
								this->container->sphereSlot3SphereAnimaCont->gotoAndStop(1);
							}
						}
					}
					if (this->container->sphereSlot4->isVisible())
					{
						if (this->container->sphereSlot4SphereAnima->currentFrame == 1)
						{
							if (this->container->sphereSlot4SphereAnimaCont->currentFrame < this->container->sphereSlot4SphereAnimaCont->totalFrames)
							{
								this->container->sphereSlot4SphereAnimaCont->gotoAndStop((this->container->sphereSlot4SphereAnimaCont->currentFrame + 1));
							}
							else
							{
								this->container->sphereSlot4SphereAnimaCont->gotoAndStop(1);
							}
						}
						else if (this->container->sphereSlot4SphereAnima->currentFrame == 2)
						{
							if (this->container->sphereSlot4SphereAnimaCont->currentFrame < this->container->sphereSlot4SphereAnimaCont->totalFrames)
							{
								this->container->sphereSlot4SphereAnimaCont->gotoAndStop((this->container->sphereSlot4SphereAnimaCont->currentFrame + 1));
							}
							else
							{
								this->container->sphereSlot4SphereAnimaCont->gotoAndStop(1);
							}
						}
						else if (this->container->sphereSlot4SphereAnima->currentFrame == 3)
						{
							if (this->container->sphereSlot4SphereAnimaCont->currentFrame < this->container->sphereSlot4SphereAnimaCont->totalFrames)
							{
								this->container->sphereSlot4SphereAnimaCont->gotoAndStop((this->container->sphereSlot4SphereAnimaCont->currentFrame + 1));
							}
							else
							{
								this->container->sphereSlot4SphereAnimaCont->gotoAndStop(1);
							}
						}
						else if (this->container->sphereSlot4SphereAnima->currentFrame == 4)
						{
							if (this->container->sphereSlot4SphereAnimaCont->currentFrame < this->container->sphereSlot4SphereAnimaCont->totalFrames)
							{
								this->container->sphereSlot4SphereAnimaCont->gotoAndStop((this->container->sphereSlot4SphereAnimaCont->currentFrame + 1));
							}
							else
							{
								this->container->sphereSlot4SphereAnimaCont->gotoAndStop(1);
							}
						}
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
					else if (this->fastBuyUltraFlag == "btnTowerUpgr1")
					{
						if (this->myTower->shootingTurnStack[0] && this->myTower->shootingTurnStack[2])
						{
							this->readyFastBuyUltraFlag = false;
							this->ultraUpgradeTower(this->fastBuyUltraFlag);
						}
					}
					else if (this->fastBuyUltraFlag == "btnTowerUpgr2")
					{
						if (this->myTower->shootingTurnStack.size() > 3);//(this->myTower->shootingTurnStack[1] && this->myTower->shootingTurnStack[3])
						{
							this->readyFastBuyUltraFlag = false;
							this->ultraUpgradeTower(this->fastBuyUltraFlag);
						}
					}
					else if (this->fastBuyUltraFlag == "btnTowerUpgr3")
					{
						if (this->myTower->shootingTurnStack[1] && this->myTower->shootingTurnStack[2])
						{
							this->readyFastBuyUltraFlag = false;
							this->ultraUpgradeTower(this->fastBuyUltraFlag);
						}
					}
					else if (this->fastBuyUltraFlag == "btnTowerUpgr4")
					{
						if (this->myTower->shootingTurnStack[0] && this->myTower->shootingTurnStack[3])
						{
							this->readyFastBuyUltraFlag = false;
							this->ultraUpgradeTower(this->fastBuyUltraFlag);
						}
					}
				}
			}
			else
			{
				this->kill();
			}
			return;
		}// end function
		void TowerMenu::mouseMoveHandler(cocos2d::Event * param1)
		{
			if (this->container->currentFrame == 1)
			{
				if (param1->target->name == "btnUpgradeMenuCase")
				{
					if (this->container->btnUpgradeMenu->currentFrame == 1)
					{
						this->container->btnUpgradeMenu->gotoAndStop(2);
						this->towerRadius1->setVisible(true);
						if (this->myTower->towerType == 1)
						{
							this->towerRadius1->width = Main::mainClass->readXMLClass.listOfSpheresRadius[1] * 2;
							this->towerRadius1->height = Main::mainClass->readXMLClass.listOfSpheresRadius[1] * 2 * this->world->scaleRadius;
						}
						else if (this->myTower->towerType == 2)
						{
							this->towerRadius1->width = Main::mainClass->readXMLClass.listOfSpheresRadius[2] * 2;
							this->towerRadius1->height = Main::mainClass->readXMLClass.listOfSpheresRadius[2] * 2 * this->world->scaleRadius;
						}
						else if (this->myTower->towerType == 3)
						{
							this->towerRadius1->width = Main::mainClass->readXMLClass.listOfSpheresRadius[3] * 2;
							this->towerRadius1->height = Main::mainClass->readXMLClass.listOfSpheresRadius[3] * 2 * this->world->scaleRadius;
						}
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
					if (this->myTower->towerType < 5)
					{
						if (!this->hint->isVisible() && !this->openFlag && !this->closeFlag)
						{
							this->hint->setVisible(true);
							this->hintPosition(5);
						}
					}
					else if (this->hint->isVisible())
					{
						this->hint->setVisible(false);
					}
				}
				else
				{
					if (this->container->btnUpgradeMenu->currentFrame == 2)
					{
						this->container->btnUpgradeMenu->gotoAndStop(1);
						this->towerRadius1->setVisible(false);
					}
					if (this->myTower->towerType < 5)
					{
						if (param1->target->name == "btnUpgradeMenuBLOCKCase")
						{
							if (!this->hint->isVisible() && !this->openFlag && !this->closeFlag)
							{
								this->hint->setVisible(true);
								this->hintPosition(5);
							}
						}
						else if (param1->target->name == "btnUpgradeMenuLOCKCase")
						{
							if (!this->hint->isVisible() && !this->openFlag && !this->closeFlag)
							{
								this->hint->setVisible(true);
								this->hintPosition(9);
							}
						}
						else if (this->hint->isVisible())
						{
							this->hint->setVisible(false);
						}
					}
					else if (this->hint->isVisible())
					{
						this->hint->setVisible(false);
					}
				}
			}
			else if (this->container->currentFrame == this->container->totalFrames)
			{
				if (param1->target->name == "btnTowerUpgrCase")
				{
					if (param1->target->parent != this->container->btnTowerUpgr1)
					{
						if (this->container->btnTowerUpgr1->currentFrame == 2)
						{
							if (this->fastBuyUltraFlag != "btnTowerUpgr1")
							{ 
								string tempObject = std::getText(this->container->btnTowerUpgr1CostTXT);
								this->container->btnTowerUpgr1->gotoAndStop(1);
								std::setText(this->container->btnTowerUpgr1CostTXT, tempObject);
								//this->container->btnTowerUpgr1CostTXT = this->tempObject;
							}
						}
					}
					if (param1->target->parent != this->container->btnTowerUpgr2)
					{
						if (this->container->btnTowerUpgr2->currentFrame == 2)
						{
							if (this->fastBuyUltraFlag != "btnTowerUpgr2")
							{
								string tempObject = std::getText(this->container->btnTowerUpgr2CostTXT); 
								this->container->btnTowerUpgr2->gotoAndStop(1);
								std::setText(this->container->btnTowerUpgr2CostTXT, tempObject);
								//this->container->btnTowerUpgr2CostTXT = this->tempObject;
							}
						}
					}
					if (param1->target->parent != this->container->btnTowerUpgr3)
					{
						if (this->container->btnTowerUpgr3->currentFrame == 2)
						{
							if (this->fastBuyUltraFlag != "btnTowerUpgr3")
							{ 
								string tempObject = std::getText(this->container->btnTowerUpgr3CostTXT);
								this->container->btnTowerUpgr3->gotoAndStop(1);
								std::setText(this->container->btnTowerUpgr3CostTXT, tempObject);
								//this->container->btnTowerUpgr3CostTXT = this->tempObject;
							}
						}
					}
					if (param1->target->parent != this->container->btnTowerUpgr4)
					{
						if (this->container->btnTowerUpgr4->currentFrame == 2)
						{
							if (this->fastBuyUltraFlag != "btnTowerUpgr4")
							{ 
								string tempObject = std::getText(this->container->btnTowerUpgr4CostTXT);
								this->container->btnTowerUpgr4->gotoAndStop(1);
								std::setText(this->container->btnTowerUpgr4CostTXT, tempObject);
								//this->container->btnTowerUpgr4CostTXT = this->tempObject;
							}
						}
					}
					if (param1->target->parent->currentFrame == 1)
					{
						if (param1->target->buttonMode)
						{
							string tempObject = param1->target->parentCostTXT;
							param1->target->parent->gotoAndStop(2);
							std::setText(param1->target->parent->costTXT, tempObject);
							//param1->target->parentCostTXT = this->tempObject;
							//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
						}
						else
						{
							if (this->container->btnTowerUpgr1->currentFrame == 2)
							{
								string tempObject = std::getText(this->container->btnTowerUpgr1CostTXT); 
								this->container->btnTowerUpgr1->gotoAndStop(1);
								std::setText(this->container->btnTowerUpgr1CostTXT, tempObject);
								//this->container->btnTowerUpgr1CostTXT = this->tempObject;
							}
							if (this->container->btnTowerUpgr2->currentFrame == 2)
							{
								string tempObject = std::getText(this->container->btnTowerUpgr2CostTXT); 
								this->container->btnTowerUpgr2->gotoAndStop(1);
								std::setText(this->container->btnTowerUpgr2CostTXT, tempObject);
								//this->container->btnTowerUpgr2CostTXT = this->tempObject;
							}
							if (this->container->btnTowerUpgr3->currentFrame == 2)
							{
								string tempObject = std::getText(this->container->btnTowerUpgr3CostTXT); 
								this->container->btnTowerUpgr3->gotoAndStop(1);
								std::setText(this->container->btnTowerUpgr3CostTXT, tempObject);
								//this->container->btnTowerUpgr3CostTXT = this->tempObject;
							}
							if (this->container->btnTowerUpgr4->currentFrame == 2)
							{ 
								string tempObject = std::getText(this->container->btnTowerUpgr4CostTXT);
								this->container->btnTowerUpgr4->gotoAndStop(1);
								std::setText(this->container->btnTowerUpgr4CostTXT, tempObject);
								//this->container->btnTowerUpgr4CostTXT = this->tempObject;
							}
						}
					}
					if (param1->target->parent->currentFrame < 5)
					{
						this->towerRadius1->setVisible(true);
						if (param1->target->parent->name == "btnTowerUpgr1")
						{
							this->towerRadius1->width = Main::mainClass->readXMLClass.ultraFireStoneRadiusXML * 2;
							this->towerRadius1->height = Main::mainClass->readXMLClass.ultraFireStoneRadiusXML * 2 * this->world->scaleRadius;
						}
						else if (param1->target->parent->name == "btnTowerUpgr2")
						{
							this->towerRadius1->width = Main::mainClass->readXMLClass.ultraIceLevinRadiusXML * 2;
							this->towerRadius1->height = Main::mainClass->readXMLClass.ultraIceLevinRadiusXML * 2 * this->world->scaleRadius;
						}
						else if (param1->target->parent->name == "btnTowerUpgr3")
						{
							this->towerRadius1->width = Main::mainClass->readXMLClass.ultraIceStoneRadiusXML * 2;
							this->towerRadius1->height = Main::mainClass->readXMLClass.ultraIceStoneRadiusXML * 2 * this->world->scaleRadius;
						}
						else if (param1->target->parent->name == "btnTowerUpgr4")
						{
							this->towerRadius1->width = Main::mainClass->readXMLClass.ultraFireLevinRadiusXML * 2;
							this->towerRadius1->height = Main::mainClass->readXMLClass.ultraFireLevinRadiusXML * 2 * this->world->scaleRadius;
						}
						if (this->hint->currentFrame > 4)
						{
							this->hintManage("ultraButtons", 1);
						}
						if (param1->target->parent->name == "btnTowerUpgr1")
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
							this->hintManage("ultraButtons", 1);
						}
						else if (param1->target->parent->name == "btnTowerUpgr2")
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
							this->hintManage("ultraButtons", 2);
						}
						else if (param1->target->parent->name == "btnTowerUpgr3")
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
							this->hintManage("ultraButtons", 3);
						}
						else if (param1->target->parent->name == "btnTowerUpgr4")
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
							this->hintManage("ultraButtons", 4);
						}
					}
					else
					{
						if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->iceBacklight->isVisible()
							|| this->world->worldInterface->container->stoneBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
						{
							this->world->worldInterface->archiveSphereBacklightManage("");
						}
						if (this->hint->currentFrame != 9 || !this->hint->isVisible())
						{
							this->hintManage("ultraButtons", 9, param1->target->parent);
							if (this->exampleUltraTower)
							{
								this->exampleUltraManage("remove");
							}
						}
					}
				}
				else
				{
					if (this->container->btnTowerUpgr1->currentFrame == 2)
					{
						if (this->fastBuyUltraFlag != "btnTowerUpgr1")
						{
							string tempObject = std::getText(this->container->btnTowerUpgr1CostTXT); 
							this->container->btnTowerUpgr1->gotoAndStop(1);
							std::setText(this->container->btnTowerUpgr1CostTXT, tempObject);
							//this->container->btnTowerUpgr1CostTXT = this->tempObject;
						}
					}
					if (this->container->btnTowerUpgr2->currentFrame == 2)
					{
						if (this->fastBuyUltraFlag != "btnTowerUpgr2")
						{
							string tempObject = std::getText(this->container->btnTowerUpgr2CostTXT);
 							this->container->btnTowerUpgr2->gotoAndStop(1);
							std::setText(this->container->btnTowerUpgr2CostTXT, tempObject);
							//this->container->btnTowerUpgr2CostTXT = this->tempObject;
						}
					}
					if (this->container->btnTowerUpgr3->currentFrame == 2)
					{
						if (this->fastBuyUltraFlag != "btnTowerUpgr3")
						{
							string tempObject = std::getText(this->container->btnTowerUpgr3CostTXT); 
							this->container->btnTowerUpgr3->gotoAndStop(1);
							std::setText(this->container->btnTowerUpgr3CostTXT, tempObject);
							//this->container->btnTowerUpgr3CostTXT = this->tempObject;
						}
					}
					if (this->container->btnTowerUpgr4->currentFrame == 2)
					{
						if (this->fastBuyUltraFlag != "btnTowerUpgr4")
						{
							string tempObject = std::getText(this->container->btnTowerUpgr4CostTXT);
							this->container->btnTowerUpgr4->gotoAndStop(1);
							std::setText(this->container->btnTowerUpgr4CostTXT, tempObject);
							//this->container->btnTowerUpgr4CostTXT = this->tempObject;
						}
					}
					if (this->towerRadius1->isVisible())
					{
						this->towerRadius1->setVisible(false);
					}
					if (param1->target->name != "fastBuyUltraCase" || !this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode)
					{
						if (this->world->worldInterface->container->fireBacklight->isVisible() || this->world->worldInterface->container->iceBacklight->isVisible()
							|| this->world->worldInterface->container->stoneBacklight->isVisible() || this->world->worldInterface->container->levinBacklight->isVisible())
						{
							this->world->worldInterface->archiveSphereBacklightManage("");
						}
						if (param1->target->name != "fastBuyUltraCase")
						{
							if (this->hint->isVisible())
							{
								this->hint->setVisible(false);
							}
							if (this->exampleUltraTower)
							{
								this->exampleUltraManage("remove");
							}
						}
					}
				}
				if (!this->openFastBuyUltraFlag && !this->closeFastBuyUltraFlag)
				{
					if (param1->target->name == "fastBuyUltraCase" && this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode)
					{
						if (this->container->fastBuyUltraContBtnFastBuyUltra->currentFrame == 1)
						{
							this->container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(2);
							std::setText(this->container->fastBuyUltraContBtnFastBuyUltra->costTXT, fastBuyPrice);
							//this->container->fastBuyUltraContBtnFastBuyUltraCostTXT = this->fastBuyPrice;
							if (this->hint->currentFrame > 4)
							{
								this->hintManage("ultraButtons", 1);
							}
							if (this->fastBuyUltraFlag == "btnTowerUpgr1")
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
								if (this->hint->cont->currentFrame != 1 || !this->hint->isVisible())
								{
									this->hintManage("ultraButtons", 1);
								}
							}
							else if (this->fastBuyUltraFlag == "btnTowerUpgr2")
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
								if (this->hint->cont->currentFrame != 2 || !this->hint->isVisible())
								{
									this->hintManage("ultraButtons", 2);
								}
							}
							else if (this->fastBuyUltraFlag == "btnTowerUpgr3")
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
								if (this->hint->cont->currentFrame != 3 || !this->hint->isVisible())
								{
									this->hintManage("ultraButtons", 3);
								}
							}
							else if (this->fastBuyUltraFlag == "btnTowerUpgr4")
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
								if (this->hint->cont->currentFrame != 4 || !this->hint->isVisible())
								{
									this->hintManage("ultraButtons", 4);
								}
							}
							this->hint->setPositionX(this->getPositionX() + this->container->getPositionX() + this->container->fastBuyUltraCont->getPositionX() + this->container->fastBuyUltraContBtnFastBuyUltra->getPositionX());
							this->hint->setPositionY(this->getPositionY() + this->container->getPositionY() + this->container->fastBuyUltraCont->getPositionY() + this->container->fastBuyUltraContBtnFastBuyUltra->getPositionY() - 15);
							//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
						}
					}
					else if (this->container->fastBuyUltraContBtnFastBuyUltra->currentFrame == 2)
					{
						this->container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(1);
						std::setText(this->container->fastBuyUltraContBtnFastBuyUltra->costTXT, fastBuyPrice);
						//this->container->fastBuyUltraContBtnFastBuyUltraCostTXT = this->fastBuyPrice;
					}
				}
			}
			if (param1->target->name == "sphereSlotCase")
			{
				this->tempObject = param1->target->parent;
				if (this->tempObject->sphereAnima->isVisible())
				{
					if (this->tempObject != this->container->sphereSlot1 && this->container->sphereSlot1->currentFrame == 2)
					{
						this->container->sphereSlot1->gotoAndStop(1);
					}
					if (this->tempObject != this->container->sphereSlot2 && this->container->sphereSlot2->currentFrame == 2)
					{
						this->container->sphereSlot2->gotoAndStop(1);
					}
					if (this->tempObject != this->container->sphereSlot3 && this->container->sphereSlot3->currentFrame == 2)
					{
						this->container->sphereSlot3->gotoAndStop(1);
					}
					if (this->tempObject != this->container->sphereSlot4 && this->container->sphereSlot4->currentFrame == 2)
					{
						this->container->sphereSlot4->gotoAndStop(1);
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
				if (this->container->sphereSlot3->currentFrame == 2)
				{
					this->container->sphereSlot3->gotoAndStop(1);
				}
				if (this->container->sphereSlot4->currentFrame == 2)
				{
					this->container->sphereSlot4->gotoAndStop(1);
				}
			}
			return;
		}// end function
		void TowerMenu::mouseDownHandler(cocos2d::Event * event)
		{
			if (event->target->name == "btnUpgradeMenuCase")
			{
				if (this->container->btnUpgradeMenu->currentFrame == 2)
				{
					this->container->btnUpgradeMenu->gotoAndStop(3);
				}
			}
			else if (event->target->name == "btnTowerUpgrCase")
			{
				if (event->target->parent->currentFrame == 2)
				{
					string tempObject = event->target->parentCostTXT;
					event->target->parent->gotoAndStop(3);
					setText(event->target->parent->costTXT, tempObject);
					//event->target->parentCostTXT = this->tempObject;
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
				}
				if (this->world->worldInterface->container->fireBacklight->isVisible())
				{
					if (this->world->worldInterface->container->fireBacklight->currentFrame == this->world->worldInterface->container->fireBacklight->totalFrames)
					{
						this->world->worldInterface->container->fireBacklight->gotoAndStop(2);
						this->world->worldInterface->container->fireBacklightTurnFlag = false;
					}
				}
				if (this->world->worldInterface->container->iceBacklight->isVisible())
				{
					if (this->world->worldInterface->container->iceBacklight->currentFrame == this->world->worldInterface->container->iceBacklight->totalFrames)
					{
						this->world->worldInterface->container->iceBacklight->gotoAndStop(2);
						this->world->worldInterface->container->iceBacklightTurnFlag = false;
					}
				}
				if (this->world->worldInterface->container->stoneBacklight->isVisible())
				{
					if (this->world->worldInterface->container->stoneBacklight->currentFrame == this->world->worldInterface->container->stoneBacklight->totalFrames)
					{
						this->world->worldInterface->container->stoneBacklight->gotoAndStop(2);
						this->world->worldInterface->container->stoneBacklightTurnFlag = false;
					}
				}
				if (this->world->worldInterface->container->levinBacklight->isVisible())
				{
					if (this->world->worldInterface->container->levinBacklight->currentFrame == this->world->worldInterface->container->levinBacklight->totalFrames)
					{
						this->world->worldInterface->container->levinBacklight->gotoAndStop(2);
						this->world->worldInterface->container->levinBacklightTurnFlag = false;
					}
				}
			}
			else if (event->target->name == "sphereSlotCase")
			{
				if (event->target->parent->sphereAnima->isVisible())
				{
					this->tempObject = event->target->parent;
					if (this->tempObject->sphereAnima->currentFrame == 1)
					{
						this->myTower->towerGetSphereManage("get", "fire");
						this->spheresMonitor();
					}
					else if (this->tempObject->sphereAnima->currentFrame == 2)
					{
						this->myTower->towerGetSphereManage("get", "ice");
						this->spheresMonitor();
					}
					else if (this->tempObject->sphereAnima->currentFrame == 3)
					{
						this->myTower->towerGetSphereManage("get", "stone");
						this->spheresMonitor();
					}
					else if (this->tempObject->sphereAnima->currentFrame == 4)
					{
						this->myTower->towerGetSphereManage("get", "levin");
						this->spheresMonitor();
					}
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
				}
				else
				{
					if (this->world->worldInterface->container->fireSphere.alpha == 1 && this->world->worldInterface->container->fireSphere->isVisible())
					{
						this->world->worldInterface->container->fireBacklightTurnFlag = false;
						this->world->worldInterface->container->fireBacklight->gotoAndStop(2);
						this->world->worldInterface->container->fireBacklight->setVisible(true);
					}
					if (this->world->worldInterface->container->iceSphere.alpha == 1 && this->world->worldInterface->container->iceSphere->isVisible())
					{
						this->world->worldInterface->container->iceBacklightTurnFlag = false;
						this->world->worldInterface->container->iceBacklight->gotoAndStop(2);
						this->world->worldInterface->container->iceBacklight->setVisible(true);
					}
					if (this->world->worldInterface->container->stoneSphere.alpha == 1 && this->world->worldInterface->container->stoneSphere->isVisible())
					{
						this->world->worldInterface->container->stoneBacklightTurnFlag = false;
						this->world->worldInterface->container->stoneBacklight->gotoAndStop(2);
						this->world->worldInterface->container->stoneBacklight->setVisible(true);
					}
					if (this->world->worldInterface->container->levinSphere.alpha == 1 && this->world->worldInterface->container->levinSphere->isVisible())
					{
						this->world->worldInterface->container->levinBacklightTurnFlag = false;
						this->world->worldInterface->container->levinBacklight->gotoAndStop(2);
						this->world->worldInterface->container->levinBacklight->setVisible(true);
					}
				}
			}
			else if (event->target->name == "btnGetAllCase")
			{
				if (event->target->parent->btnGetAllCase->buttonMode)
				{
					this->i = 0;
					while (this->i < this->world->listOfMoveSpheres.size())
					{
						if (this->world->listOfMoveSpheres[this->i]->owner == this->myTower)
						{
							if (this->world->listOfMoveSpheres[this->i]->speedFrame >= 0)
							{
								this->world->listOfMoveSpheres[this->i]->speedFrame = 0;
							}
						}
						i++;
					}
					this->world->feature->listOfMoveSpheres();
					this->i = 0;
					while (this->i < 4)
					{
						this->myTower->towerGetSphereManage("get", "fire");
						this->spheresMonitor();
						i++;
					}
					this->i = 0;
					while (this->i < 4)
					{
						this->myTower->towerGetSphereManage("get", "ice");
						this->spheresMonitor();
						i++;
					}
					this->i = 0;
					while (this->i < 4)
					{
						this->myTower->towerGetSphereManage("get", "stone");
						this->spheresMonitor();
						i++;
					}
					this->i = 0;
					while (this->i < 4)
					{
						this->myTower->towerGetSphereManage("get", "levin");
						this->spheresMonitor();
						i++;
					}
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
						std::setText(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT, this->fastBuyPrice);
						//this->container->fastBuyUltraContBtnFastBuyUltraCostTXT = this->fastBuyPrice;
						this->fastBuyBlockCost = true;
						this->fastBuyUltraManage();
						this->ultraUpgradeTower(this->fastBuyUltraFlag, true);
						this->myTower->mouseChildren = false;
						this->myTower->mouseEnabled = false;
						this->readyFastBuyUltraFlag = true;
						if (this->fastBuyUltraFlag == "btnTowerUpgr1")
						{
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
						else if (this->fastBuyUltraFlag == "btnTowerUpgr2")
						{
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
						else if (this->fastBuyUltraFlag == "btnTowerUpgr3")
						{
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
						else if (this->fastBuyUltraFlag == "btnTowerUpgr4")
						{
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
						//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
					}
				}
			}
			else if (event->target->name != "buySphereCase" && event->target->name != "sphereCase"
				&& event->target->name != "btnUpgradeMenuBLOCKCase" && event->target->name != "fastBuyUltraCase"
				&& event->target->parent != this->container && event->target->parent->parent != this->container)
			{
				this->lastE = event;
				this->closeMenu();
			}
			return;
		}// end function

		void TowerMenu::mouseUpHandler(cocos2d::Event * event)
		{
			if (this->container->currentFrame == 1)
			{
				if (event->target->name == "btnUpgradeMenuCase")
				{
					if (this->container->btnUpgradeMenu->currentFrame == 3)
					{
						if (this->myTower->towerType == 1)
						{
							this->tempObject = this->myTower->myPlace;
							Common::Array<> tempObject1;
							Common::Array<> tempObject3;
							tempObject1 = tempObject1.concat(this->myTower->spheresStack);
							int tempObject2 = this->myTower->container->sphere1->currentFrame;
							tempObject3 = tempObject3.concat(this->myTower->shootingTurnStack);
							this->myTower->kill();
							this->myTower = this->world->addTower("tower2", this->tempObject);
							this->myTower->spheresStack = this->myTower->spheresStack.concat(this->tempObject1);
							this->myTower->shootingTurnStack = [];
							this->myTower->shootingTurnStack = this->myTower->shootingTurnStack.concat(this->tempObject3);
							this->myTower->prepareSpheresGraphic();
							if (this->myTower->container->sphere2_1->currentFrame + this->tempObject2 > this->myTower->container->sphere2_1->totalFrames)
							{
								this->tempObject = this->tempObject2 + this->myTower->container->sphere2_1->currentFrame - this->myTower->container->sphere2_1->totalFrames;
								this->myTower->container->sphere2_1->gotoAndStop(this->tempObject);
							}
							else
							{
								this->myTower->container->sphere2_1->gotoAndStop(this->myTower->container->sphere2_1->currentFrame + this->tempObject2);
							}
							if (this->myTower->container->sphere2_2->currentFrame + this->tempObject2 > this->myTower->container->sphere2_2->totalFrames)
							{
								this->tempObject = this->tempObject2 + this->myTower->container->sphere2_2->currentFrame - this->myTower->container->sphere2_2->totalFrames;
								this->myTower->container->sphere2_2->gotoAndStop(this->tempObject);
							}
							else
							{
								this->myTower->container->sphere2_2->gotoAndStop(this->myTower->container->sphere2_2->currentFrame + this->tempObject2);
							}
							this->world->setChildIndex(this->myTower, (this->world->getChildIndex(this) - 1));
							this->container->btnUpgradeMenu->gotoAndStop(1);
							this->world->money = this->world->money - Main::mainClass->readXMLClass.costSlot2XML;
						}
						else if (this->myTower->towerType == 2)
						{
							this->tempObject = this->myTower->myPlace;
							this->tempObject1 = [];
							this->tempObject3 = [];
							this->tempObject1 = this->tempObject1.concat(this->myTower->spheresStack);
							this->tempObject2 = this->myTower->container->sphere2_1->currentFrame;
							this->tempObject3 = this->tempObject3.concat(this->myTower->shootingTurnStack);
							this->myTower->kill();
							this->myTower = this->world->addTower("tower3", this->tempObject);
							this->myTower->spheresStack = this->myTower->spheresStack.concat(this->tempObject1);
							this->myTower->shootingTurnStack = [];
							this->myTower->shootingTurnStack = this->myTower->shootingTurnStack.concat(this->tempObject3);
							this->myTower->prepareSpheresGraphic();
							if (this->myTower->container->sphere3_1->currentFrame + this->tempObject2 > this->myTower->container->sphere3_1->totalFrames)
							{
								this->tempObject = this->tempObject2 + this->myTower->container->sphere3_1->currentFrame - this->myTower->container->sphere3_1->totalFrames;
								this->myTower->container->sphere3_1->gotoAndStop(this->tempObject);
							}
							else
							{
								this->myTower->container->sphere3_1->gotoAndStop(this->myTower->container->sphere3_1->currentFrame + this->tempObject2);
							}
							if (this->myTower->container->sphere3_2->currentFrame + this->tempObject2 > this->myTower->container->sphere3_2->totalFrames)
							{
								this->tempObject = this->tempObject2 + this->myTower->container->sphere3_2->currentFrame - this->myTower->container->sphere3_2->totalFrames;
								this->myTower->container->sphere3_2->gotoAndStop(this->tempObject);
							}
							else
							{
								this->myTower->container->sphere3_2->gotoAndStop(this->myTower->container->sphere3_2->currentFrame + this->tempObject2);
							}
							if (this->myTower->container->sphere3_3->currentFrame + this->tempObject2 > this->myTower->container->sphere3_3->totalFrames)
							{
								this->tempObject = this->tempObject2 + this->myTower->container->sphere3_3->currentFrame - this->myTower->container->sphere3_3->totalFrames;
								this->myTower->container->sphere3_3->gotoAndStop(this->tempObject);
							}
							else
							{
								this->myTower->container->sphere3_3->gotoAndStop(this->myTower->container->sphere3_3->currentFrame + this->tempObject2);
							}
							this->world->setChildIndex(this->myTower, (this->world->getChildIndex(this) - 1));
							this->container->btnUpgradeMenu->gotoAndStop(1);
							this->world->money = this->world->money - Main::mainClass->readXMLClass.costSlot3XML;
						}
						else if (this->myTower->towerType == 3)
						{
							this->tempObject = this->myTower->myPlace;
							this->tempObject1 = [];
							this->tempObject3 = [];
							this->tempObject1 = this->tempObject1.concat(this->myTower->spheresStack);
							this->tempObject2 = this->myTower->container->sphere3_1->currentFrame;
							this->tempObject3 = this->tempObject3.concat(this->myTower->shootingTurnStack);
							this->myTower->kill();
							this->myTower = this->world->addTower("tower4", this->tempObject);
							this->myTower->spheresStack = this->myTower->spheresStack.concat(this->tempObject1);
							this->myTower->shootingTurnStack = [];
							this->myTower->shootingTurnStack = this->myTower->shootingTurnStack.concat(this->tempObject3);
							this->myTower->prepareSpheresGraphic();
							if (this->myTower->container->sphere4_1->currentFrame + this->tempObject2 > this->myTower->container->sphere4_1->totalFrames)
							{
								this->tempObject = this->tempObject2 + this->myTower->container->sphere4_1->currentFrame - this->myTower->container->sphere4_1->totalFrames;
								this->myTower->container->sphere4_1->gotoAndStop(this->tempObject);
							}
							else
							{
								this->myTower->container->sphere4_1->gotoAndStop(this->myTower->container->sphere4_1->currentFrame + this->tempObject2);
							}
							if (this->myTower->container->sphere4_2->currentFrame + this->tempObject2 > this->myTower->container->sphere4_2->totalFrames)
							{
								this->tempObject = this->tempObject2 + this->myTower->container->sphere4_2->currentFrame - this->myTower->container->sphere4_2->totalFrames;
								this->myTower->container->sphere4_2->gotoAndStop(this->tempObject);
							}
							else
							{
								this->myTower->container->sphere4_2->gotoAndStop(this->myTower->container->sphere4_2->currentFrame + this->tempObject2);
							}
							if (this->myTower->container->sphere4_3->currentFrame + this->tempObject2 > this->myTower->container->sphere4_3->totalFrames)
							{
								this->tempObject = this->tempObject2 + this->myTower->container->sphere4_3->currentFrame - this->myTower->container->sphere4_3->totalFrames;
								this->myTower->container->sphere4_3->gotoAndStop(this->tempObject);
							}
							else
							{
								this->myTower->container->sphere4_3->gotoAndStop(this->myTower->container->sphere4_3->currentFrame + this->tempObject2);
							}
							if (this->myTower->container->sphere4_4->currentFrame + this->tempObject2 > this->myTower->container->sphere4_4->totalFrames)
							{
								this->tempObject = this->tempObject2 + this->myTower->container->sphere4_4->currentFrame - this->myTower->container->sphere4_4->totalFrames;
								this->myTower->container->sphere4_4->gotoAndStop(this->tempObject);
							}
							else
							{
								this->myTower->container->sphere4_4->gotoAndStop(this->myTower->container->sphere4_4->currentFrame + this->tempObject2);
							}
							this->world->setChildIndex(this->myTower, (this->world->getChildIndex(this) - 1));
							this->container->btnUpgradeMenu->gotoAndStop(1);
							this->world->money = this->world->money - Main::mainClass->readXMLClass.costSlot4XML;
						}
						else if (this->myTower->towerType == 4)
						{
							this->upgradeManage();
						}
						this->towerRadius->width = this->myTower->radius * 2;
						this->towerRadius->height = this->myTower->radius * 2 * this->world->scaleRadius;
						this->world->worldInterface->updateInfo();
						//事件模拟
						this->tempObject = new Object();
						this->tempObject->target = new Object();
						this->tempObject->target.name = "btnUpgradeMenuCase";
						this->mouseMoveHandler(this->tempObject);
						if (this->myTower->towerType == 4)
						{
							this->towerRadius1->setVisible(false);
							this->hint->gotoAndStop(1);
							this->hint->cont->stop();
							this->hint->contCont1->stop();
							this->hint->contCont1Sphere1->stop();
							this->hint->contCont1Sphere2->stop();
							this->hint->setVisible(false);
						}
					}
				}
				else if (this->container->btnUpgradeMenu->currentFrame == 3)
				{
					this->container->btnUpgradeMenu->gotoAndStop(1);
				}
			}
			else if (this->container->currentFrame == this->container->totalFrames)
			{
				if (event->target->name == "btnTowerUpgrCase")
				{
					if (event->target->parent != this->container->btnTowerUpgr1)
					{
						if (this->container->btnTowerUpgr1->currentFrame == 3)
						{
							this->tempObject = this->container->btnTowerUpgr1CostTXT;
							this->container->btnTowerUpgr1->gotoAndStop(1);
							this->container->btnTowerUpgr1CostTXT = this->tempObject;
						}
					}
					if (event->target->parent != this->container->btnTowerUpgr2)
					{
						if (this->container->btnTowerUpgr2->currentFrame == 3)
						{
							this->tempObject = this->container->btnTowerUpgr2CostTXT;
							this->container->btnTowerUpgr2->gotoAndStop(1);
							this->container->btnTowerUpgr2CostTXT = this->tempObject;
						}
					}
					if (event->target->parent != this->container->btnTowerUpgr3)
					{
						if (this->container->btnTowerUpgr3->currentFrame == 3)
						{
							this->tempObject = this->container->btnTowerUpgr3CostTXT;
							this->container->btnTowerUpgr3->gotoAndStop(1);
							this->container->btnTowerUpgr3CostTXT = this->tempObject;
						}
					}
					if (event->target->parent != this->container->btnTowerUpgr4)
					{
						if (this->container->btnTowerUpgr4->currentFrame == 3)
						{
							this->tempObject = this->container->btnTowerUpgr4CostTXT;
							this->container->btnTowerUpgr4->gotoAndStop(1);
							this->container->btnTowerUpgr4CostTXT = this->tempObject;
						}
					}
					if (event->target->parent->currentFrame == 3)
					{
						this->tempObject = event->target->parent;
						tempObject1 = this->tempObject->costTXT;
						tempObject->gotoAndStop(2);
						std::setText(tempObject->costTXT , tempObject1);
						if (!this->fastBuyUltraFlag)
						{
							this->fastBuyUltraFlag = event->target->parent->name;
							this->openFastBuyUltraFlag = true;
							this->fastBuyUltraManage();
						}
						else if (event->target->parent->name == this->fastBuyUltraFlag)
						{
							this->fastBuyUltraFlag = "";
							this->closeFastBuyUltraFlag = true;
							this->mouseMoveHandler(event);
						}
						else
						{
							this->fastBuyUltraFlag = "";
							if (this->exampleUltraTower)
							{
								this->exampleUltraManage("remove");
							}
							this->closeFastBuyUltraFlag = true;
							this->mouseMoveHandler(event);
							this->fastBuyUltraFlag = event->target->parent->name;
							this->openFastBuyUltraFlag = true;
							this->closeFastBuyUltraFlag = false;
							this->fastBuyUltraManage();
							this->exampleUltraManage(event->target->parent->name);
						}
					}
				}
				else
				{
					if (this->container->btnTowerUpgr1->currentFrame == 3)
					{
						string tempObject = std::getText(this->container->btnTowerUpgr1CostTXT);
						this->container->btnTowerUpgr1->gotoAndStop(1);
						std::setText(this->container->btnTowerUpgr1CostTXT , tempObject);
					}
					if (this->container->btnTowerUpgr2->currentFrame == 3)
					{
						string tempObject = std::getText(this->container->btnTowerUpgr2CostTXT);
						this->container->btnTowerUpgr2->gotoAndStop(1);
						std::setText(this->container->btnTowerUpgr2CostTXT,  tempObject);
					}
					if (this->container->btnTowerUpgr3->currentFrame == 3)
					{
						string tempObject = std::getText(this->container->btnTowerUpgr3CostTXT);
						this->container->btnTowerUpgr3->gotoAndStop(1);
						std::setText(this->container->btnTowerUpgr3CostTXT, tempObject);
					}
					if (this->container->btnTowerUpgr4->currentFrame == 3)
					{
						string tempObject = std::getText(this->container->btnTowerUpgr4CostTXT);
						this->container->btnTowerUpgr4->gotoAndStop(1);
						std::setText(this->container->btnTowerUpgr4CostTXT, tempObject);
					}
				}
			}
			return;
		}// end function

		void TowerMenu::upgradeManage()
		{
			if (this->myTower->towerType == 4)
			{
				if (this->container->currentFrame == 1)
				{
					this->openUltraSection = true;
					this->mouseChildren = false;
					this->mouseEnabled = false;
				}
				else
				{
					this->fastBuyUltraManage();
					if (this->container->btnTowerUpgr1)
					{
						if (Main::mainClass->readXMLClass.ultraTower1Block == 0)
						{
							if (this->world->money >= Main::mainClass->readXMLClass.costUltraFireStone && this->world->worldInterface->container->fireSphere->isVisible() && this->world->worldInterface->container->stoneSphere->isVisible())
							{
								if (this->container->btnTowerUpgr1->currentFrame > 3)
								{
									this->container->btnTowerUpgr1->gotoAndStop(1);
								}
								else
								{
									this->container->btnTowerUpgr1->stop();
								}
								this->container->btnTowerUpgr1BtnTowerUpgrCase->buttonMode = true;
							}
							else
							{
								this->container->btnTowerUpgr1->gotoAndStop(4);
								this->container->btnTowerUpgr1BtnTowerUpgrCase->buttonMode = false;
							}
							std::setText(this->container->btnTowerUpgr1CostTXT,Main::mainClass->readXMLClass.costUltraFireStone);
						}
						else
						{
							this->container->btnTowerUpgr1->gotoAndStop(5);
						}
					}
					if (this->container->btnTowerUpgr2)
					{
						if (Main::mainClass->readXMLClass.ultraTower2Block == 0)
						{
							if (this->world->money >= Main::mainClass->readXMLClass.costUltraIceLevin && this->world->worldInterface->container->iceSphere->isVisible()&& this->world->worldInterface->container->levinSphere->isVisible())
							{
								if (this->container->btnTowerUpgr2->currentFrame > 3)
								{
									this->container->btnTowerUpgr2->gotoAndStop(1);
								}
								else
								{
									this->container->btnTowerUpgr2->stop();
								}
								this->container->btnTowerUpgr2BtnTowerUpgrCase->buttonMode = true;
							}
							else
							{
								this->container->btnTowerUpgr2->gotoAndStop(4);
								this->container->btnTowerUpgr2BtnTowerUpgrCase->buttonMode = false;
							}
							std::setText(this->container->btnTowerUpgr2CostTXT, Main::mainClass->readXMLClass.costUltraIceLevin);
						}
						else
						{
							this->container->btnTowerUpgr2->gotoAndStop(5);
						}
					}
					if (this->container->btnTowerUpgr3)
					{
						if (Main::mainClass->readXMLClass.ultraTower3Block == 0)
						{
							if (this->world->money >= Main::mainClass->readXMLClass.costUltraIceStone && this->world->worldInterface->container->iceSphere->isVisible()&& this->world->worldInterface->container->stoneSphere->isVisible())
							{
								if (this->container->btnTowerUpgr3->currentFrame > 3)
								{
									this->container->btnTowerUpgr3->gotoAndStop(1);
								}
								else
								{
									this->container->btnTowerUpgr3->stop();
								}
								this->container->btnTowerUpgr3BtnTowerUpgrCase->buttonMode = true;
							}
							else
							{
								this->container->btnTowerUpgr3->gotoAndStop(4);
								this->container->btnTowerUpgr3BtnTowerUpgrCase->buttonMode = false;
							}
							std::setText(this->container->btnTowerUpgr3CostTXT, Main::mainClass->readXMLClass.costUltraIceStone);
						}
						else
						{
							this->container->btnTowerUpgr3->gotoAndStop(5);
						}
					}
					if (this->container->btnTowerUpgr4)
					{
						if (Main::mainClass->readXMLClass.ultraTower4Block == 0)
						{
							if (this->world->money >= Main::mainClass->readXMLClass.costUltraFireLevin && this->world->worldInterface->container->fireSphere->isVisible()&& this->world->worldInterface->container->levinSphere->isVisible())
							{
								if (this->container->btnTowerUpgr4->currentFrame > 3)
								{
									this->container->btnTowerUpgr4->gotoAndStop(1);
								}
								else
								{
									this->container->btnTowerUpgr4->stop();
								}
								this->container->btnTowerUpgr4BtnTowerUpgrCase->buttonMode = true;
							}
							else
							{
								this->container->btnTowerUpgr4->gotoAndStop(4);
								this->container->btnTowerUpgr4BtnTowerUpgrCase->buttonMode = false;
							}
							std::setText(this->container->btnTowerUpgr4CostTXT, Main::mainClass->readXMLClass.costUltraFireLevin);
						}
						else
						{
							this->container->btnTowerUpgr4->gotoAndStop(5);
						}
					}
					this->fastBuyUltraManage();
				}
			}
			return;
		}// end function

		void TowerMenu::monitor()
		{
			if (this->myTower->towerType == 1)
			{
				this->container->sphereSlot1->gotoAndStop(1);
				if (Main::mainClass->readXMLClass.towerSlotBlock < 3)
				{
					if (this->world->money >= Main::mainClass->readXMLClass.costSlot2XML)
					{
						this->container->sphereSlot2->gotoAndStop(3);
						if (this->container->btnUpgradeMenu->currentFrame > 2)
						{
							this->container->btnUpgradeMenu->gotoAndStop(1);
						}
						this->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
					}
					else
					{
						this->container->sphereSlot2->gotoAndStop(4);
						this->container->btnUpgradeMenu->gotoAndStop(4);
					}
					std::setText(this->container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costSlot2XML);
				}
				else
				{
					this->container->sphereSlot2->gotoAndStop(4);
					if (this->container->btnUpgradeMenu->currentFrame != 5)
					{
						this->container->btnUpgradeMenu->gotoAndStop(5);
						if (!this->openFlag && !this->closeFlag)
						{
							this->hint->setVisible(true);
							this->hintPosition(9);
						}
					}
				}
				this->container->sphereSlot3->gotoAndStop(4);
				this->container->sphereSlot4->gotoAndStop(4);
			}
			else if (this->myTower->towerType == 2)
			{
				this->container->sphereSlot1->gotoAndStop(1);
				this->container->sphereSlot2->gotoAndStop(1);
				if (Main::mainClass->readXMLClass.towerSlotBlock < 2)
				{
					if (this->world->money >= Main::mainClass->readXMLClass.costSlot3XML)
					{
						this->container->sphereSlot3->gotoAndStop(3);
						if (this->container->btnUpgradeMenu->currentFrame > 2)
						{
							this->container->btnUpgradeMenu->gotoAndStop(1);
						}
						this->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
					}
					else
					{
						this->container->sphereSlot3->gotoAndStop(4);
						this->container->btnUpgradeMenu->gotoAndStop(4);
					}
					std::setText(this->container->btnUpgradeMenuCostTXT,Main::mainClass->readXMLClass.costSlot3XML);
				}
				else
				{
					this->container->sphereSlot3->gotoAndStop(4);
					if (this->container->btnUpgradeMenu->currentFrame != 5)
					{
						this->container->btnUpgradeMenu->gotoAndStop(5);
						if (!this->openFlag && !this->closeFlag)
						{
							this->hint->setVisible(true);
							this->hintPosition(9);
						}
					}
				}
				this->container->sphereSlot4->gotoAndStop(4);
			}
			else if (this->myTower->towerType == 3)
			{
				this->container->sphereSlot1->gotoAndStop(1);
				this->container->sphereSlot2->gotoAndStop(1);
				this->container->sphereSlot3->gotoAndStop(1);
				if (Main::mainClass->readXMLClass.towerSlotBlock < 1)
				{
					if (this->world->money >= Main::mainClass->readXMLClass.costSlot4XML)
					{
						this->container->sphereSlot4->gotoAndStop(3);
						if (this->container->btnUpgradeMenu->currentFrame > 2)
						{
							this->container->btnUpgradeMenu->gotoAndStop(1);
						}
						this->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = true;
					}
					else
					{
						this->container->sphereSlot4->gotoAndStop(4);
						this->container->btnUpgradeMenu->gotoAndStop(4);
					}
					std::setText(this->container->btnUpgradeMenuCostTXT, Main::mainClass->readXMLClass.costSlot4XML);
				}
				else
				{
					this->container->sphereSlot4->gotoAndStop(4);
					if (this->container->btnUpgradeMenu->currentFrame != 5)
					{
						this->container->btnUpgradeMenu->gotoAndStop(5);
						if (!this->openFlag && !this->closeFlag)
						{
							this->hint->setVisible(true);
							this->hintPosition(9);
						}
					}
				}
			}
			else if (this->myTower->towerType == 4)
			{
				this->container->sphereSlot1->gotoAndStop(1);
				this->container->sphereSlot2->gotoAndStop(1);
				this->container->sphereSlot3->gotoAndStop(1);
				this->container->sphereSlot4->gotoAndStop(1);
				this->upgradeManage();
			}
			if (!this->openFlag)
			{
				this->world->worldInterface->archiveSphereBacklightManage("");
				this->autoguidersButtons();
			}
			return;
		}// end function

		void TowerMenu::spheresMonitor()
		{
			this->container->sphereSlot1SphereSlotCase->buttonMode = false;
			this->container->sphereSlot2SphereSlotCase->buttonMode = false;
			this->container->sphereSlot3SphereSlotCase->buttonMode = false;
			this->container->sphereSlot4SphereSlotCase->buttonMode = false;
			this->container->btnGetAllBtnGetAllCase->buttonMode = false;
			this->container->sphereSlot1SphereAnima->setVisible(false);
			this->container->sphereSlot2SphereAnima->setVisible(false);
			this->container->sphereSlot3SphereAnima->setVisible(false);
			this->container->sphereSlot4SphereAnima->setVisible(false);
			if (this->myTower->spheresStack.size() == 0)
			{
				if (this->container->sphereSlot1->currentFrame == 2)
				{
					this->container->sphereSlot1->gotoAndStop(1);
				}
			}
			else if (this->myTower->spheresStack.size() == 1)
			{
				if (this->container->sphereSlot2->currentFrame == 2)
				{
					this->container->sphereSlot2->gotoAndStop(1);
				}
			}
			else if (this->myTower->spheresStack.size() == 2)
			{
				if (this->container->sphereSlot3->currentFrame == 2)
				{
					this->container->sphereSlot3->gotoAndStop(1);
				}
			}
			else if (this->myTower->spheresStack.size() == 3)
			{
				if (this->container->sphereSlot4->currentFrame == 2)
				{
					this->container->sphereSlot4->gotoAndStop(1);
				}
			}
			else if (this->myTower->spheresStack.size() == 4)
			{
			}
			if (this->myTower->spheresStack.size() >= 1)
			{
				this->container->btnGetAllBtnGetAllCase->buttonMode = true;
				if (this->container->sphereSlot1->currentFrame == 5)
				{
					this->container->sphereSlot1->gotoAndStop(1);
				}
				this->container->sphereSlot1SphereSlotCase->buttonMode = true;
				this->container->sphereSlot1SphereAnima->setVisible(true);
				if (this->myTower->spheresStack[0] == "fire")
				{
					this->container->sphereSlot1SphereAnima->gotoAndStop(1);
					if (this->container->sphereSlot1SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot1SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[0] == "ice")
				{
					this->container->sphereSlot1SphereAnima->gotoAndStop(2);
					if (this->container->sphereSlot1SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot1SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[0] == "stone")
				{
					this->container->sphereSlot1SphereAnima->gotoAndStop(3);
					if (this->container->sphereSlot1SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot1SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[0] == "levin")
				{
					this->container->sphereSlot1SphereAnima->gotoAndStop(4);
					if (this->container->sphereSlot1SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot1SphereAnimaCont->stop();
					}
				}
			}
			if (this->myTower->spheresStack.size() >= 2)
			{
				if (this->container->sphereSlot2->currentFrame == 5)
				{
					this->container->sphereSlot2->gotoAndStop(1);
				}
				this->container->sphereSlot2SphereSlotCase->buttonMode = true;
				this->container->sphereSlot2SphereAnima->setVisible(true);
				if (this->myTower->spheresStack[1] == "fire")
				{
					this->container->sphereSlot2SphereAnima->gotoAndStop(1);
					if (this->container->sphereSlot2SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot2SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[1] == "ice")
				{
					this->container->sphereSlot2SphereAnima->gotoAndStop(2);
					if (this->container->sphereSlot2SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot2SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[1] == "stone")
				{
					this->container->sphereSlot2SphereAnima->gotoAndStop(3);
					if (this->container->sphereSlot2SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot2SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[1] == "levin")
				{
					this->container->sphereSlot2SphereAnima->gotoAndStop(4);
					if (this->container->sphereSlot2SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot2SphereAnimaCont->stop();
					}
				}
			}
			if (this->myTower->spheresStack.size() >= 3)
			{
				if (this->container->sphereSlot3->currentFrame == 5)
				{
					//this->container->sphereSlot3->gotoAndStop(1);
				}
				this->container->sphereSlot3SphereSlotCase->buttonMode = true;
				this->container->sphereSlot3SphereAnima->setVisible(true);
				if (this->myTower->spheresStack[2] == "fire")
				{
					this->container->sphereSlot3SphereAnima->gotoAndStop(1);
					if (this->container->sphereSlot3SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot3SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[2] == "ice")
				{
					this->container->sphereSlot3SphereAnima->gotoAndStop(2);
					if (this->container->sphereSlot3SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot3SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[2] == "stone")
				{
					this->container->sphereSlot3SphereAnima->gotoAndStop(3);
					if (this->container->sphereSlot3SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot3SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[2] == "levin")
				{
					this->container->sphereSlot3SphereAnima->gotoAndStop(4);
					if (this->container->sphereSlot3SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot3SphereAnimaCont->stop();
					}
				}
			}
			if (this->myTower->spheresStack.size() >= 4)
			{
				if (this->container->sphereSlot4->currentFrame == 5)
				{
					this->container->sphereSlot4->gotoAndStop(1);
				}
				this->container->sphereSlot4SphereSlotCase->buttonMode = true;
				this->container->sphereSlot4SphereAnima->setVisible(true);
				if (this->myTower->spheresStack[3] == "fire")
				{
					this->container->sphereSlot4SphereAnima->gotoAndStop(1);
					if (this->container->sphereSlot4SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot4SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[3] == "ice")
				{
					this->container->sphereSlot4SphereAnima->gotoAndStop(2);
					if (this->container->sphereSlot4SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot4SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[3] == "stone")
				{
					this->container->sphereSlot4SphereAnima->gotoAndStop(3);
					if (this->container->sphereSlot4SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot4SphereAnimaCont->stop();
					}
				}
				else if (this->myTower->spheresStack[3] == "levin")
				{
					this->container->sphereSlot4SphereAnima->gotoAndStop(4);
					if (this->container->sphereSlot4SphereAnimaCont->currentFrame == 1)
					{
						this->container->sphereSlot4SphereAnimaCont->stop();
					}
				}
			}
			return;
		}// end function

		void TowerMenu::exampleUltraManage(string param1)
		{
			if (param1 == "btnTowerUpgr1" || param1 == "btnTowerUpgr2" || param1 == "btnTowerUpgr3" || param1 == "btnTowerUpgr4")
			{
				if (param1 == "btnTowerUpgr1")
				{
					if (this->exampleUltraTower)
					{
						this->myTower->removeChild(this->exampleUltraTower);
					}
					Tower5_mc *exampleUltraTower = new Tower5_mc();
					this->exampleUltraTower = exampleUltraTower;
					exampleUltraTower->myParent = this->myTower;
					exampleUltraTower->stop();
					exampleUltraTower->upgr1->stop();
					exampleUltraTower->blockTower->stop();
					exampleUltraTower->boneBlock->stop();
					exampleUltraTower->bot->stop();
					exampleUltraTower->setPosition(this->myTower->container->getPosition());
					//exampleUltraTower->x = this->myTower->container->x;
					//exampleUltraTower->y = this->myTower->container->y;
					exampleUltraTower->upgr1->setVisible(false);
					exampleUltraTower->blockTower->setVisible(false);
					exampleUltraTower->boneBlock->setVisible(false);
					this->myTower->addChild(this->exampleUltraTower);
				}
				else if (param1 == "btnTowerUpgr2")
				{
					if (this->exampleUltraTower)
					{
						this->myTower->removeChild(this->exampleUltraTower);
					}
					Tower6_mc *exampleUltraTower = new Tower6_mc();
					this->exampleUltraTower = exampleUltraTower;
 					exampleUltraTower->myParent = this->myTower;
					exampleUltraTower->stop();
					exampleUltraTower->shotAnima->stop();
					exampleUltraTower->blockTower->stop();
					exampleUltraTower->boneBlock->stop();
					exampleUltraTower->setPosition(this->myTower->container->getPosition());
					//exampleUltraTower->x = this->myTower->container->x;
					//exampleUltraTower->y = this->myTower->container->y;
					exampleUltraTower->shotAnima->setVisible(false);
					exampleUltraTower->blockTower->setVisible(false);
					exampleUltraTower->boneBlock->setVisible(false);
					this->myTower->addChild(this->exampleUltraTower);
				}
				else if (param1 == "btnTowerUpgr3")
				{
					if (this->exampleUltraTower)
					{
						this->myTower->removeChild(this->exampleUltraTower);
					}
					Tower7_mc *exampleUltraTower = new Tower7_mc();
					this->exampleUltraTower = exampleUltraTower;

					exampleUltraTower->myParent = this->myTower;
					exampleUltraTower->stop();
					exampleUltraTower->cont1->stop();
					exampleUltraTower->cont2->stop();
					exampleUltraTower->cont3->stop();
					exampleUltraTower->upgr1_1->stop();
					exampleUltraTower->upgr1_2->stop();
					exampleUltraTower->upgr1_3->stop();
					exampleUltraTower->upgr1_4->stop();
					exampleUltraTower->upgr1_5->stop();
					exampleUltraTower->upgr1_6->stop();
					exampleUltraTower->upgr1_7->stop();
					exampleUltraTower->upgr1_8->stop();
					exampleUltraTower->round1->stop();
					exampleUltraTower->round2->stop();
					exampleUltraTower->round3->stop();
					exampleUltraTower->round4->stop();
					exampleUltraTower->blockTower->stop();
					exampleUltraTower->boneBlock->stop();
					exampleUltraTower->setPosition(this->myTower->container->getPosition());
					//exampleUltraTower->x = this->myTower->container->x;
					//exampleUltraTower->y = this->myTower->container->y; 
					exampleUltraTower->upgr1_1->setVisible(false);
					exampleUltraTower->upgr1_2->setVisible(false);
					exampleUltraTower->upgr1_3->setVisible(false);
					exampleUltraTower->upgr1_4->setVisible(false);
					exampleUltraTower->upgr1_5->setVisible(false);
					exampleUltraTower->upgr1_6->setVisible(false);
					exampleUltraTower->upgr1_7->setVisible(false);
					exampleUltraTower->upgr1_8->setVisible(false);
					exampleUltraTower->round1->setVisible(false);
					exampleUltraTower->round2->setVisible(false);
					exampleUltraTower->round3->setVisible(false);
					exampleUltraTower->round4->setVisible(false);
					exampleUltraTower->blockTower->setVisible(false);
					exampleUltraTower->boneBlock->setVisible(false);
					this->myTower->addChild(this->exampleUltraTower);
				}
				else if (param1 == "btnTowerUpgr4")
				{
					if (this->exampleUltraTower)
					{
						this->myTower->removeChild(this->exampleUltraTower);
					}
					Tower8_mc *exampleUltraTower = new Tower8_mc();
					this->exampleUltraTower = exampleUltraTower;
					exampleUltraTower->myParent = this->myTower;
					exampleUltraTower->stop();
					exampleUltraTower->cont1->stop();
					exampleUltraTower->cont2->stop();
					exampleUltraTower->cont3->stop();
					exampleUltraTower->cont4->stop();
					exampleUltraTower->cont5->stop();
					exampleUltraTower->cont6->stop();
					exampleUltraTower->fireLight1->stop();
					exampleUltraTower->blockTower->stop();
					exampleUltraTower->boneBlock->stop();
					exampleUltraTower->setPosition(this->myTower->container->getPosition());
					//exampleUltraTower->x = this->myTower->container->x;
					//exampleUltraTower->y = this->myTower->container->y;
					exampleUltraTower->cont4->setVisible(false);
					exampleUltraTower->cont5->setVisible(false);
					exampleUltraTower->cont6->setVisible(false);
					exampleUltraTower->fireLight1->setVisible(false);
					exampleUltraTower->blockTower->setVisible(false);
					exampleUltraTower->boneBlock->setVisible(false);
					this->myTower->addChild(this->exampleUltraTower);
				}
				this->container->btnGetAll->setVisible(false);
				this->container->cont2->setVisible(false);
				this->myTower->container->setVisible(false);
			}
			else if (param1 == "remove")
			{
				this->container->btnGetAll->setVisible(true);
				this->container->cont2->setVisible(true);
				exampleUltraTower->myParent->container->setVisible(true);
				exampleUltraTower->myParent->removeChild(this->exampleUltraTower);
				this->exampleUltraTower = NULL;
			}
			return;
		}// end function

		void TowerMenu::autoguidersButtons()
		{
			this->autoguidesMouse_pt = cocos2d::Point(Main::mainClass->worldClass->mouseX, Main::mainClass->worldClass->mouseY);
			this->autoguidesObject = NULL;
			if (this->container->currentFrame == 1)
			{
				if (this->container->btnUpgradeMenuBtnUpgradeMenuCase->isReady)
				{
					this->autoguidesObject_pt = this->container->btnUpgradeMenuBtnUpgradeMenuCase->localToGlobal(this->container->btnUpgradeMenuBtnUpgradeMenuCase->getPosition());
					this->autoguidesObjectWidth = this->container->btnUpgradeMenuBtnUpgradeMenuCase->getWidth() / 2;
					this->autoguidesObjectHeight = this->container->btnUpgradeMenuBtnUpgradeMenuCase->getHeight() / 2;
					if (this->container->btnUpgradeMenuBtnUpgradeMenuCase->hitTest(this->autoguidesMouse_pt))
						//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
					{
						this->autoguidesObject = this->container->btnUpgradeMenuBtnUpgradeMenuCase;
					}
				}
			}
			else if (this->container->currentFrame == this->container->totalFrames)
			{
				this->autoguidesObject_pt = this->container->btnTowerUpgr1BtnTowerUpgrCase->localToGlobal(this->container->btnTowerUpgr1BtnTowerUpgrCase->getPosition());
				this->autoguidesObjectWidth = this->container->btnTowerUpgr1BtnTowerUpgrCase->getWidth() / 2;
				this->autoguidesObjectHeight = this->container->btnTowerUpgr1BtnTowerUpgrCase->getHeight() / 2;
				if (this->container->btnTowerUpgr1BtnTowerUpgrCase->hitTest(this->autoguidesMouse_pt))
					//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
				{
					this->autoguidesObject = this->container->btnTowerUpgr1BtnTowerUpgrCase;
				}
				if (!this->autoguidesObject)
				{
					this->autoguidesObject_pt = this->container->btnTowerUpgr2BtnTowerUpgrCase->localToGlobal(this->container->btnTowerUpgr2BtnTowerUpgrCase->getPosition());
					this->autoguidesObjectWidth = this->container->btnTowerUpgr2BtnTowerUpgrCase->getWidth() / 2;
					this->autoguidesObjectHeight = this->container->btnTowerUpgr2BtnTowerUpgrCase->getHeight() / 2;
					if (this->container->btnTowerUpgr2BtnTowerUpgrCase->hitTest(this->autoguidesMouse_pt))
						//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
					{
						this->autoguidesObject = this->container->btnTowerUpgr2BtnTowerUpgrCase;
					}
				}
				if (!this->autoguidesObject)
				{
					this->autoguidesObject_pt = this->container->btnTowerUpgr3BtnTowerUpgrCase->localToGlobal(this->container->btnTowerUpgr3BtnTowerUpgrCase->getPosition());
					this->autoguidesObjectWidth = this->container->btnTowerUpgr3BtnTowerUpgrCase->getWidth() / 2;
					this->autoguidesObjectHeight = this->container->btnTowerUpgr3BtnTowerUpgrCase->getHeight() / 2;
					if (this->container->btnTowerUpgr3BtnTowerUpgrCase->hitTest(this->autoguidesMouse_pt))
						//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
					{
						this->autoguidesObject = this->container->btnTowerUpgr3BtnTowerUpgrCase;
					}
				}
				if (!this->autoguidesObject)
				{
					this->autoguidesObject_pt = this->container->btnTowerUpgr4BtnTowerUpgrCase->localToGlobal(this->container->btnTowerUpgr4BtnTowerUpgrCase->getPosition());
					this->autoguidesObjectWidth = this->container->btnTowerUpgr4BtnTowerUpgrCase->getWidth() / 2;
					this->autoguidesObjectHeight = this->container->btnTowerUpgr4BtnTowerUpgrCase->getHeight() / 2;
					if (this->container->btnTowerUpgr4BtnTowerUpgrCase->hitTest(this->autoguidesMouse_pt))
						//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
					{
						this->autoguidesObject = this->container->btnTowerUpgr4BtnTowerUpgrCase;
					}
				}
				if (!this->autoguidesObject && this->fastBuyUltraFlag)
				{
					this->autoguidesObject_pt = this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->localToGlobal(this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->getPosition());
					this->autoguidesObjectWidth = this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->getWidth() / 2;
					this->autoguidesObjectHeight = this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->getHeight() / 2;
					if (this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->hitTest(this->autoguidesMouse_pt))
						//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
					{
						this->autoguidesObject = this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase;
					}
				}
			}
			if (!this->autoguidesObject)
			{
				this->autoguidesObject_pt = this->container->sphereSlot1SphereSlotCase->localToGlobal(this->container->sphereSlot1SphereSlotCase->getPosition());
				this->autoguidesObjectWidth = this->container->sphereSlot1SphereSlotCase->getWidth() / 2;
				this->autoguidesObjectHeight = this->container->sphereSlot1SphereSlotCase->getHeight() / 2;
				if (this->container->sphereSlot1SphereSlotCase->hitTest(this->autoguidesMouse_pt))
					//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
				{
					this->autoguidesObject = this->container->sphereSlot1SphereSlotCase;
				}
				if (!this->autoguidesObject)
				{
					this->autoguidesObject_pt = this->container->sphereSlot2SphereSlotCase->localToGlobal(this->container->sphereSlot2SphereSlotCase->getPosition());
					this->autoguidesObjectWidth = this->container->sphereSlot2SphereSlotCase->getWidth() / 2;
					this->autoguidesObjectHeight = this->container->sphereSlot2SphereSlotCase->getHeight() / 2;
					if (this->container->sphereSlot2SphereSlotCase->hitTest(this->autoguidesMouse_pt))
						//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
					{
						this->autoguidesObject = this->container->sphereSlot2SphereSlotCase;
					}
				}
				if (!this->autoguidesObject)
				{
					this->autoguidesObject_pt = this->container->sphereSlot3SphereSlotCase->localToGlobal(this->container->sphereSlot3SphereSlotCase->getPosition());
					this->autoguidesObjectWidth = this->container->sphereSlot3SphereSlotCase->getWidth() / 2;
					this->autoguidesObjectHeight = this->container->sphereSlot3SphereSlotCase->getHeight() / 2;
					if (this->container->sphereSlot3SphereSlotCase->hitTest(this->autoguidesMouse_pt))
						//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
					{
						this->autoguidesObject = this->container->sphereSlot3SphereSlotCase;
					}
				}
				if (!this->autoguidesObject)
				{
					this->autoguidesObject_pt = this->container->sphereSlot4SphereSlotCase->localToGlobal(this->container->sphereSlot4SphereSlotCase->getPosition());
					this->autoguidesObjectWidth = this->container->sphereSlot4SphereSlotCase->getWidth() / 2;
					this->autoguidesObjectHeight = this->container->sphereSlot4SphereSlotCase->getHeight() / 2;
					if (this->container->sphereSlot4SphereSlotCase->hitTest(this->autoguidesMouse_pt))
						//if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
					{
						this->autoguidesObject = this->container->sphereSlot4SphereSlotCase;
					}
				}
			}
			if (this->autoguidesObject)
			{
				//事件
				//this->tempObject = new Object();
				//this->tempObject->target = this->autoguidesObject;
				//this->mouseMoveHandler(this->tempObject);
			}
			return;
		}// end function

		void TowerMenu::hintManage(string param1, int param2, Node * param3)
		{
			if (param1 == "ultraButtons")
			{
				if (!param3)
				{
					if (!this->exampleUltraTower)
					{
						if (param2 == 1)
						{
							this->exampleUltraManage("btnTowerUpgr1");
						}
						else if (param2 == 2)
						{
							this->exampleUltraManage("btnTowerUpgr2");
						}
						else if (param2 == 3)
						{
							this->exampleUltraManage("btnTowerUpgr3");
						}
						else if (param2 == 4)
						{
							this->exampleUltraManage("btnTowerUpgr4");
						}
					}
					else if (param2 == 1)
					{
						if (!(ISTYPE(Tower5_mc,this->exampleUltraTower)))
						{
							this->exampleUltraManage("remove");
							this->exampleUltraManage("btnTowerUpgr1");
						}
					}
					else if (param2 == 2)
					{
						if (!(ISTYPE(Tower6_mc, this->exampleUltraTower)))
						{
							this->exampleUltraManage("remove");
							this->exampleUltraManage("btnTowerUpgr2");
						}
					}
					else if (param2 == 3)
					{
						if (!(ISTYPE(Tower7_mc, this->exampleUltraTower)))
						{
							this->exampleUltraManage("remove");
							this->exampleUltraManage("btnTowerUpgr3");
						}
					}
					else if (param2 == 4)
					{
						if (!(ISTYPE(Tower8_mc, this->exampleUltraTower)))
						{
							this->exampleUltraManage("remove");
							this->exampleUltraManage("btnTowerUpgr4");
						}
					}
					this->hintPosition(param2, param3);
					this->hint->cont->gotoAndStop(param2);
					this->hint->contCont1Sphere1->stop();
					this->hint->contCont1Sphere2->stop();
					this->hint->setVisible(true);
				}
				else
				{
					this->hintPosition(param2, param3);
					this->hint->setVisible(true);
				}
			}
			return;
		}// end function

		void TowerMenu::hintPosition(int param1, Node* param2)
		{
			//if (param1 == 1)
			//{
			//    this->tempObject = this->container->btnTowerUpgr1->localToGlobal(new Point(this->container->btnTowerUpgr1->btnTowerUpgrCase.x, this->container->btnTowerUpgr1->btnTowerUpgrCase.y));
			//}
			//else if (param1 == 2)
			//{
			//    this->tempObject = this->container->btnTowerUpgr2->localToGlobal(new Point(this->container->btnTowerUpgr2->btnTowerUpgrCase.x, this->container->btnTowerUpgr2->btnTowerUpgrCase.y));
			//}
			//else if (param1 == 3)
			//{
			//    this->tempObject = this->container->btnTowerUpgr3->localToGlobal(new Point(this->container->btnTowerUpgr3->btnTowerUpgrCase.x, this->container->btnTowerUpgr3->btnTowerUpgrCase.y));
			//}
			//else if (param1 == 4)
			//{
			//    this->tempObject = this->container->btnTowerUpgr4->localToGlobal(new Point(this->container->btnTowerUpgr4->btnTowerUpgrCase.x, this->container->btnTowerUpgr4->btnTowerUpgrCase.y));
			//}
			//else if (param1 == 5)
			//{
			//    this->tempObject = this->container->localToGlobal(new Point(this->container->btnUpgradeMenu->x, this->container->btnUpgradeMenu->y));
			//    this->hint->gotoAndStop((param1 - 1));
			//}
			//else if (param1 == 9)
			//{
			//    if (!param2)
			//    {
			//        this->tempObject = this->container->localToGlobal(new Point(this->container->btnUpgradeMenu->x, this->container->btnUpgradeMenu->y));
			//    }
			//    else
			//    {
			//        this->tempObject = param2.parent.localToGlobal(new Point(param2.x, param2.y));
			//    }
			//    this->hint->gotoAndStop((param1 - 1));
			//}
			//if (param1 < 5)
			//{
			//    if (this->tempObject->x < 120)
			//    {
			//        if (this->tempObject->y < 120)
			//        {
			//            this->hint->gotoAndStop(4);
			//            this->hint->y = this->tempObject->y + 12;
			//        }
			//        else if (this->tempObject->y > Main.SCREEN_HEIGHT - 120)
			//        {
			//            this->hint->gotoAndStop(2);
			//            this->hint->y = this->tempObject->y - 12;
			//        }
			//        else
			//        {
			//            this->hint->gotoAndStop(2);
			//            this->hint->y = this->tempObject->y - 12;
			//        }
			//        this->hint->x = this->tempObject->x + 12;
			//    }
			//    else if (this->tempObject->x > Main.SCREEN_WIDTH - 120)
			//    {
			//        if (this->tempObject->y < 120)
			//        {
			//            this->hint->gotoAndStop(3);
			//            this->hint->y = this->tempObject->y + 12;
			//        }
			//        else if (this->tempObject->y > Main.SCREEN_HEIGHT - 120)
			//        {
			//            this->hint->gotoAndStop(1);
			//            this->hint->y = this->tempObject->y - 12;
			//        }
			//        else
			//        {
			//            this->hint->gotoAndStop(1);
			//            this->hint->y = this->tempObject->y + 12;
			//        }
			//        this->hint->x = this->tempObject->x - 12;
			//    }
			//    else if (this->tempObject->y < 120)
			//    {
			//        if (this->tempObject->x < 120)
			//        {
			//            this->hint->gotoAndStop(4);
			//            this->hint->x = this->tempObject->x + 12;
			//            this->hint->y = this->tempObject->y + 12;
			//        }
			//        else if (this->tempObject->x > Main.SCREEN_WIDTH - 120)
			//        {
			//            this->hint->gotoAndStop(3);
			//            this->hint->x = this->tempObject->x - 12;
			//            this->hint->y = this->tempObject->y + 12;
			//        }
			//        else
			//        {
			//            this->hint->gotoAndStop(4);
			//            this->hint->x = this->tempObject->x;
			//            this->hint->y = this->tempObject->y + 12;
			//        }
			//    }
			//    else if (this->tempObject->y > Main.SCREEN_HEIGHT - 120)
			//    {
			//        if (this->tempObject->x < 120)
			//        {
			//            this->hint->gotoAndStop(2);
			//            this->hint->x = this->tempObject->x + 12;
			//            this->hint->y = this->tempObject->y - 12;
			//        }
			//        else if (this->tempObject->x > Main.SCREEN_WIDTH - 120)
			//        {
			//            this->hint->gotoAndStop(1);
			//            this->hint->x = this->tempObject->x - 12;
			//            this->hint->y = this->tempObject->y - 12;
			//        }
			//        else
			//        {
			//            this->hint->gotoAndStop(2);
			//            this->hint->x = this->tempObject->x;
			//            this->hint->y = this->tempObject->y - 12;
			//        }
			//    }
			//    else
			//    {
			//        this->hint->gotoAndStop(2);
			//        this->hint->x = this->tempObject->x;
			//        this->hint->y = this->tempObject->y - 12;
			//    }
			//}
			//else if (this->tempObject->x < 120)
			//{
			//    if (this->tempObject->y < 120)
			//    {
			//        this->hint->gotoAndStop(this->hint->currentFrame + 4);
			//        this->hint->y = this->tempObject->y + 12;
			//    }
			//    else if (this->tempObject->y > Main.SCREEN_HEIGHT - 120)
			//    {
			//        this->hint->gotoAndStop(this->hint->currentFrame + 2);
			//        this->hint->y = this->tempObject->y - 12;
			//    }
			//    else
			//    {
			//        this->hint->gotoAndStop(this->hint->currentFrame + 2);
			//        this->hint->y = this->tempObject->y - 12;
			//    }
			//    this->hint->x = this->tempObject->x + 12;
			//}
			//else if (this->tempObject->x > Main.SCREEN_WIDTH - 120)
			//{
			//    if (this->tempObject->y < 120)
			//    {
			//        this->hint->gotoAndStop(this->hint->currentFrame + 3);
			//        this->hint->y = this->tempObject->y + 12;
			//    }
			//    else if (this->tempObject->y > Main.SCREEN_HEIGHT - 120)
			//    {
			//        this->hint->gotoAndStop((this->hint->currentFrame + 1));
			//        this->hint->y = this->tempObject->y - 12;
			//    }
			//    else
			//    {
			//        this->hint->gotoAndStop((this->hint->currentFrame + 1));
			//        this->hint->y = this->tempObject->y + 12;
			//    }
			//    this->hint->x = this->tempObject->x - 12;
			//}
			//else if (this->tempObject->y < 120)
			//{
			//    if (this->tempObject->x < 120)
			//    {
			//        this->hint->gotoAndStop(this->hint->currentFrame + 4);
			//        this->hint->x = this->tempObject->x + 12;
			//        this->hint->y = this->tempObject->y + 12;
			//    }
			//    else if (this->tempObject->x > Main.SCREEN_WIDTH - 120)
			//    {
			//        this->hint->gotoAndStop(this->hint->currentFrame + 3);
			//        this->hint->x = this->tempObject->x - 12;
			//        this->hint->y = this->tempObject->y + 12;
			//    }
			//    else
			//    {
			//        this->hint->gotoAndStop(this->hint->currentFrame + 4);
			//        this->hint->x = this->tempObject->x;
			//        this->hint->y = this->tempObject->y + 12;
			//    }
			//}
			//else if (this->tempObject->y > Main.SCREEN_HEIGHT - 120)
			//{
			//    if (this->tempObject->x < 120)
			//    {
			//        this->hint->gotoAndStop(this->hint->currentFrame + 2);
			//        this->hint->x = this->tempObject->x + 12;
			//        this->hint->y = this->tempObject->y - 12;
			//    }
			//    else if (this->tempObject->x > Main.SCREEN_WIDTH - 120)
			//    {
			//        this->hint->gotoAndStop((this->hint->currentFrame + 1));
			//        this->hint->x = this->tempObject->x - 12;
			//        this->hint->y = this->tempObject->y - 12;
			//    }
			//    else
			//    {
			//        this->hint->gotoAndStop(this->hint->currentFrame + 2);
			//        this->hint->x = this->tempObject->x;
			//        this->hint->y = this->tempObject->y - 12;
			//    }
			//}
			//else
			//{
			//    this->hint->gotoAndStop(this->hint->currentFrame + 2);
			//    this->hint->x = this->tempObject->x;
			//    this->hint->y = this->tempObject->y - 12;
			//}
			//this->tempObject = NULL;
			return;
		}// end function

		void TowerMenu::ultraUpgradeTower(string param1, bool param2)
		{
			if (param1 == "btnTowerUpgr1")
			{
				//if (this->myTower->shootingTurnStack.size()>0)
				//{
				//    if (this->myTower->shootingTurnStack[0][3] > 1)
				//    {
				//        this->world->getSphere = new GetSphere();
				//        this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
				//        this->world->getSphere->ownerType = "archive";
				//        this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphere.myPoint;
				//        this->world->addChild(this->world->getSphere);
				//        this->i = 0;
				//        while (this->i < (this->myTower->shootingTurnStack[0][3] - 1))
				//        { 
				//            (this->i + 1);
				//            this->world->getSphere->manage("add", "fire");
				//        }
				//        this->myTower->spheresManage("get", "fire", (this->myTower->shootingTurnStack[0][3] - 1));
				//        this->world->getSphere->x = this->myTower->this_pt.x;
				//        this->world->getSphere->y = this->myTower->this_pt.y;
				//        this->world->getSphere->retrieveGetSphere();
				//    }
				//}
				//if (this->myTower->shootingTurnStack[1])
				//{
				//    this->world->getSphere = new GetSphere();
				//    this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
				//    this->world->getSphere->ownerType = "archive";
				//    this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphere.myPoint;
				//    this->world->addChild(this->world->getSphere);
				//    this->i = 0;
				//    while (this->i < this->myTower->shootingTurnStack[1][3])
				//    {
				//        (this->i + 1);
				//        this->world->getSphere->manage("add", "ice");
				//    }
				//    this->myTower->spheresManage("get", "ice", this->myTower->shootingTurnStack[1][3]);
				//    this->world->getSphere->x = this->myTower->this_pt.x;
				//    this->world->getSphere->y = this->myTower->this_pt.y;
				//    this->world->getSphere->retrieveGetSphere();
				//}
				//if (this->myTower->shootingTurnStack[2])
				//{
				//    if (this->myTower->shootingTurnStack[2][3] > 1)
				//    {
				//        this->world->getSphere = new GetSphere();
				//        this->world->getSphere->owner = this->world->worldInterface->container->stoneSphere;
				//        this->world->getSphere->ownerType = "archive";
				//        this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphere.myPoint;
				//        this->world->addChild(this->world->getSphere);
				//        this->i = 0;
				//        while (this->i < (this->myTower->shootingTurnStack[2][3] - 1))
				//        {
				//            (this->i + 1);
				//            this->world->getSphere->manage("add", "stone");
				//        }
				//        this->myTower->spheresManage("get", "stone", (this->myTower->shootingTurnStack[2][3] - 1));
				//        this->world->getSphere->x = this->myTower->this_pt.x;
				//        this->world->getSphere->y = this->myTower->this_pt.y;
				//        this->world->getSphere->retrieveGetSphere();
				//    }
				//}
				//if (this->myTower->shootingTurnStack[3])
				//{
				//    this->world->getSphere = new GetSphere();
				//    this->world->getSphere->owner = this->world->worldInterface->container->levinSphere;
				//    this->world->getSphere->ownerType = "archive";
				//    this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphere.myPoint;
				//    this->world->addChild(this->world->getSphere);
				//    this->i = 0;
				//    while (this->i < this->myTower->shootingTurnStack[3][3])
				//    {
				//        (this->i + 1);
				//        this->world->getSphere->manage("add", "levin");
				//    }
				//    this->myTower->spheresManage("get", "levin", this->myTower->shootingTurnStack[3][3]);
				//    this->world->getSphere->x = this->myTower->this_pt.x;
				//    this->world->getSphere->y = this->myTower->this_pt.y;
				//    this->world->getSphere->retrieveGetSphere();
				//}
				//if (!param2)
				//{
				//    this->tempObject = this->myTower->myPlace;
				//    this->myTower->kill();
				//    this->myTower = this->world->addTower("tower5", this->tempObject);
				//    this->world->setChildIndex(this->myTower, (this->world->getChildIndex(this) - 1));
				//    this->world->money = this->world->money - Main::mainClass->readXMLClass.costUltraFireStone;
				//    this->closeMenu();
				//}
			}
			else if (param1 == "btnTowerUpgr2")
			{
				//if (this->myTower->shootingTurnStack[0])
				//{
				//    this->world->getSphere = new GetSphere();
				//    this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
				//    this->world->getSphere->ownerType = "archive";
				//    this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphere.myPoint;
				//    this->world->addChild(this->world->getSphere);
				//    this->i = 0;
				//    while (this->i < this->myTower->shootingTurnStack[0][3])
				//    {
				//        (this->i + 1);
				//        this->world->getSphere->manage("add", "fire");
				//    }
				//    this->myTower->spheresManage("get", "fire", this->myTower->shootingTurnStack[0][3]);
				//    this->world->getSphere->x = this->myTower->this_pt.x;
				//    this->world->getSphere->y = this->myTower->this_pt.y;
				//    this->world->getSphere->retrieveGetSphere();
				//}
				//if (this->myTower->shootingTurnStack[1])
				//{
				//    if (this->myTower->shootingTurnStack[1][3] > 1)
				//    {
				//        this->world->getSphere = new GetSphere();
				//        this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
				//        this->world->getSphere->ownerType = "archive";
				//        this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphere.myPoint;
				//        this->world->addChild(this->world->getSphere);
				//        this->i = 0;
				//        while (this->i < (this->myTower->shootingTurnStack[1][3] - 1))
				//        {
				//            (this->i + 1);
				//            this->world->getSphere->manage("add", "ice");
				//        }
				//        this->myTower->spheresManage("get", "ice", (this->myTower->shootingTurnStack[1][3] - 1));
				//        this->world->getSphere->x = this->myTower->this_pt.x;
				//        this->world->getSphere->y = this->myTower->this_pt.y;
				//        this->world->getSphere->retrieveGetSphere();
				//    }
				//}
				//if (this->myTower->shootingTurnStack[2])
				//{
				//    this->world->getSphere = new GetSphere();
				//    this->world->getSphere->owner = this->world->worldInterface->container->stoneSphere;
				//    this->world->getSphere->ownerType = "archive";
				//    this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphere.myPoint;
				//    this->world->addChild(this->world->getSphere);
				//    this->i = 0;
				//    while (this->i < this->myTower->shootingTurnStack[2][3])
				//    {
				//        (this->i + 1);
				//        this->world->getSphere->manage("add", "stone");
				//    }
				//    this->myTower->spheresManage("get", "stone", this->myTower->shootingTurnStack[2][3]);
				//    this->world->getSphere->x = this->myTower->this_pt.x;
				//    this->world->getSphere->y = this->myTower->this_pt.y;
				//    this->world->getSphere->retrieveGetSphere();
				//}
				//if (this->myTower->shootingTurnStack[3])
				//{
				//    if (this->myTower->shootingTurnStack[3][3] > 1)
				//    {
				//        this->world->getSphere = new GetSphere();
				//        this->world->getSphere->owner = this->world->worldInterface->container->levinSphere;
				//        this->world->getSphere->ownerType = "archive";
				//        this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphere.myPoint;
				//        this->world->addChild(this->world->getSphere);
				//        this->i = 0;
				//        while (this->i < (this->myTower->shootingTurnStack[3][3] - 1))
				//        {
				//            (this->i + 1);
				//            this->world->getSphere->manage("add", "levin");
				//        }
				//        this->myTower->spheresManage("get", "levin", (this->myTower->shootingTurnStack[3][3] - 1));
				//        this->world->getSphere->x = this->myTower->this_pt.x;
				//        this->world->getSphere->y = this->myTower->this_pt.y;
				//        this->world->getSphere->retrieveGetSphere();
				//    }
				//}
				//if (!param2)
				//{
				//    this->tempObject = this->myTower->myPlace;
				//    this->myTower->kill();
				//    this->myTower = this->world->addTower("tower6", this->tempObject);
				//    this->world->setChildIndex(this->myTower, (this->world->getChildIndex(this) - 1));
				//    this->world->money = this->world->money - Main::mainClass->readXMLClass.costUltraIceLevin;
				//    this->closeMenu();
				//}
			}
			else if (param1 == "btnTowerUpgr3")
			{
				//if (this->myTower->shootingTurnStack[0])
				//{
				//    this->world->getSphere = new GetSphere();
				//    this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
				//    this->world->getSphere->ownerType = "archive";
				//    this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphere.myPoint;
				//    this->world->addChild(this->world->getSphere);
				//    this->i = 0;
				//    while (this->i < this->myTower->shootingTurnStack[0][3])
				//    {
				//        (this->i + 1);
				//        this->world->getSphere->manage("add", "fire");
				//    }
				//    this->myTower->spheresManage("get", "fire", this->myTower->shootingTurnStack[0][3]);
				//    this->world->getSphere->x = this->myTower->this_pt.x;
				//    this->world->getSphere->y = this->myTower->this_pt.y;
				//    this->world->getSphere->retrieveGetSphere();
				//}
				//if (this->myTower->shootingTurnStack[1])
				//{
				//    if (this->myTower->shootingTurnStack[1][3] > 1)
				//    {
				//        this->world->getSphere = new GetSphere();
				//        this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
				//        this->world->getSphere->ownerType = "archive";
				//        this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphere.myPoint;
				//        this->world->addChild(this->world->getSphere);
				//        this->i = 0;
				//        while (this->i < (this->myTower->shootingTurnStack[1][3] - 1))
				//        {
				//            (this->i + 1);
				//            this->world->getSphere->manage("add", "ice");
				//        }
				//        this->myTower->spheresManage("get", "ice", (this->myTower->shootingTurnStack[1][3] - 1));
				//        this->world->getSphere->x = this->myTower->this_pt.x;
				//        this->world->getSphere->y = this->myTower->this_pt.y;
				//        this->world->getSphere->retrieveGetSphere();
				//    }
				//}
				//if (this->myTower->shootingTurnStack[2])
				//{
				//    if (this->myTower->shootingTurnStack[2][3] > 1)
				//    {
				//        this->world->getSphere = new GetSphere();
				//        this->world->getSphere->owner = this->world->worldInterface->container->stoneSphere;
				//        this->world->getSphere->ownerType = "archive";
				//        this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphere.myPoint;
				//        this->world->addChild(this->world->getSphere);
				//        this->i = 0;
				//        while (this->i < (this->myTower->shootingTurnStack[2][3] - 1))
				//        {
				//            (this->i + 1);
				//            this->world->getSphere->manage("add", "stone");
				//        }
				//        this->myTower->spheresManage("get", "stone", (this->myTower->shootingTurnStack[2][3] - 1));
				//        this->world->getSphere->x = this->myTower->this_pt.x;
				//        this->world->getSphere->y = this->myTower->this_pt.y;
				//        this->world->getSphere->retrieveGetSphere();
				//    }
				//}
				//if (this->myTower->shootingTurnStack[3])
				//{
				//    this->world->getSphere = new GetSphere();
				//    this->world->getSphere->owner = this->world->worldInterface->container->levinSphere;
				//    this->world->getSphere->ownerType = "archive";
				//    this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphere.myPoint;
				//    this->world->addChild(this->world->getSphere);
				//    this->i = 0;
				//    while (this->i < this->myTower->shootingTurnStack[3][3])
				//    {
				//        (this->i + 1);
				//        this->world->getSphere->manage("add", "levin");
				//    }
				//    this->myTower->spheresManage("get", "levin", this->myTower->shootingTurnStack[3][3]);
				//    this->world->getSphere->x = this->myTower->this_pt.x;
				//    this->world->getSphere->y = this->myTower->this_pt.y;
				//    this->world->getSphere->retrieveGetSphere();
				//}
				//if (!param2)
				//{
				//    this->tempObject = this->myTower->myPlace;
				//    this->myTower->kill();
				//    this->myTower = this->world->addTower("tower7", this->tempObject);
				//    this->world->setChildIndex(this->myTower, (this->world->getChildIndex(this) - 1));
				//    this->world->money = this->world->money - Main::mainClass->readXMLClass.costUltraIceStone;
				//    this->closeMenu();
				//}
			}
			else if (param1 == "btnTowerUpgr4")
			{
				//if (this->myTower->shootingTurnStack[0])
				//{
				//    if (this->myTower->shootingTurnStack[0][3] > 1)
				//    {
				//        this->world->getSphere = new GetSphere();
				//        this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
				//        this->world->getSphere->ownerType = "archive";
				//        this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphere.myPoint;
				//        this->world->addChild(this->world->getSphere);
				//        this->i = 0;
				//        while (this->i < (this->myTower->shootingTurnStack[0][3] - 1))
				//        {
				//            (this->i + 1);
				//            this->world->getSphere->manage("add", "fire");
				//        }
				//        this->myTower->spheresManage("get", "fire", (this->myTower->shootingTurnStack[0][3] - 1));
				//        this->world->getSphere->x = this->myTower->this_pt.x;
				//        this->world->getSphere->y = this->myTower->this_pt.y;
				//        this->world->getSphere->retrieveGetSphere();
				//    }
				//}
				//if (this->myTower->shootingTurnStack[1])
				//{
				//    this->world->getSphere = new GetSphere();
				//    this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
				//    this->world->getSphere->ownerType = "archive";
				//    this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphere.myPoint;
				//    this->world->addChild(this->world->getSphere);
				//    this->i = 0;
				//    while (this->i < this->myTower->shootingTurnStack[1][3])
				//    {
				//        (this->i + 1);
				//        this->world->getSphere->manage("add", "ice");
				//    }
				//    this->myTower->spheresManage("get", "ice", this->myTower->shootingTurnStack[1][3]);
				//    this->world->getSphere->x = this->myTower->this_pt.x;
				//    this->world->getSphere->y = this->myTower->this_pt.y;
				//    this->world->getSphere->retrieveGetSphere();
				//}
				//if (this->myTower->shootingTurnStack[2])
				//{
				//    this->world->getSphere = new GetSphere();
				//    this->world->getSphere->owner = this->world->worldInterface->container->stoneSphere;
				//    this->world->getSphere->ownerType = "archive";
				//    this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphere.myPoint;
				//    this->world->addChild(this->world->getSphere);
				//    this->i = 0;
				//    while (this->i < this->myTower->shootingTurnStack[2][3])
				//    {
				//        (this->i + 1);
				//        this->world->getSphere->manage("add", "stone");
				//    }
				//    this->myTower->spheresManage("get", "stone", this->myTower->shootingTurnStack[2][3]);
				//    this->world->getSphere->x = this->myTower->this_pt.x;
				//    this->world->getSphere->y = this->myTower->this_pt.y;
				//    this->world->getSphere->retrieveGetSphere();
				//}
				//if (this->myTower->shootingTurnStack[3])
				//{
				//    if (this->myTower->shootingTurnStack[3][3] > 1)
				//    {
				//        this->world->getSphere = new GetSphere();
				//        this->world->getSphere->owner = this->world->worldInterface->container->levinSphere;
				//        this->world->getSphere->ownerType = "archive";
				//        this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphere.myPoint;
				//        this->world->addChild(this->world->getSphere);
				//        this->i = 0;
				//        while (this->i < (this->myTower->shootingTurnStack[3][3] - 1))
				//        {
				//            (this->i + 1);
				//            this->world->getSphere->manage("add", "levin");
				//        }
				//        this->myTower->spheresManage("get", "levin", (this->myTower->shootingTurnStack[3][3] - 1));
				//        this->world->getSphere->x = this->myTower->this_pt.x;
				//        this->world->getSphere->y = this->myTower->this_pt.y;
				//        this->world->getSphere->retrieveGetSphere();
				//    }
				//}
				//if (!param2)
				//{
				//    this->tempObject = this->myTower->myPlace;
				//    this->myTower->kill();
				//    this->myTower = this->world->addTower("tower8", this->tempObject);
				//    this->world->setChildIndex(this->myTower, (this->world->getChildIndex(this) - 1));
				//    this->world->money = this->world->money - Main::mainClass->readXMLClass.costUltraFireLevin;
				//    this->closeMenu();
				//}
			}
			this->world->worldInterface->updateInfo();
			return;
		}// end function

		void TowerMenu::fastBuyUltraManage()
		{
			if (this->container->fastBuyUltraCont->isReady)
			{
				this->container->fastBuyUltraCont->stop();
				this->container->fastBuyUltraContBtnFastBuyUltra->stop();
				//this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->stop();
				this->container->fastBuyUltraContIndicator1->stop();
				this->container->fastBuyUltraContIndicator2->stop();
				this->container->fastBuyUltraContIndicator3->stop();
				this->container->fastBuyUltraContIndicator4->stop();
				if (this->fastBuyUltraFlag.empty() && !this->openFastBuyUltraFlag && !this->closeFastBuyUltraFlag)
				{
					this->container->fastBuyUltraCont->setVisible(false);
				}
				if (!this->fastBuyUltraFlag.empty())
				{
					this->container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(1);
					this->container->fastBuyUltraContIndicator1->gotoAndStop(2);
					this->container->fastBuyUltraContIndicator2->gotoAndStop(2);
					this->container->fastBuyUltraContIndicator3->gotoAndStop(2);
					this->container->fastBuyUltraContIndicator4->gotoAndStop(2);
					this->container->fastBuyUltraContIndicator1->setVisible(true);
					this->container->fastBuyUltraContIndicator2->setVisible(true);
					this->container->fastBuyUltraContIndicator3->setVisible(true);
					this->container->fastBuyUltraContIndicator4->setVisible(true);
					if (!this->fastBuyBlockCost)
					{
						std::setText(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT, this->fastBuyUltraScan(this->fastBuyUltraFlag));
					}
					else
					{
						std::setText(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT, this->fastBuyPrice);
					}
					if (this->fastBuyUltraFlag == "btnTowerUpgr1")
					{
						this->j = 0;
						this->i = 0;
						while (this->i < this->myTower->spheresStack.size())
						{
							if (this->myTower->spheresStack[this->i] == "fire")
							{
								if (this->i == 0)
								{
									this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
								}
								else if (this->i == 1)
								{
									this->container->fastBuyUltraContIndicator2->gotoAndStop(1);
								}
								else if (this->i == 2)
								{
									this->container->fastBuyUltraContIndicator3->gotoAndStop(1);
								}
								else if (this->i == 3)
								{
									this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
								}
								this->j++;
								break;
							}
							i++;
						}
						this->i = 0;
						while (this->i < this->myTower->spheresStack.size())
						{
							if (this->myTower->spheresStack[this->i] == "stone")
							{
								if (this->i == 0)
								{
									this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
								}
								else if (this->i == 1)
								{
									this->container->fastBuyUltraContIndicator2->gotoAndStop(1);
								}
								else if (this->i == 2)
								{
									this->container->fastBuyUltraContIndicator3->gotoAndStop(1);
								}
								else if (this->i == 3)
								{
									this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
								}
								this->j ++;
								break;
							}
							i++;
						}
						if (this->j < 2 && this->world->money >= std::getInt(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT))
						{
							this->i = 0;
							while (this->i < this->myTower->spheresStack.size())
							{
								if (this->myTower->spheresStack[this->i] != "fire" && this->myTower->spheresStack[this->i] != "stone")
								{
									this->j --;
									if (this->i == 0)
									{
										this->container->fastBuyUltraContIndicator1->gotoAndStop(3);
									}
									else if (this->i == 1)
									{
										this->container->fastBuyUltraContIndicator2->gotoAndStop(3);
									}
									else if (this->i == 2)
									{
										this->container->fastBuyUltraContIndicator3->gotoAndStop(3);
									}
									else if (this->i == 3)
									{
										this->container->fastBuyUltraContIndicator4->gotoAndStop(3);
									}
									if (this->j == 0)
									{
										break;
									}
								}
								i++;
							}
						}
					}
					else if (this->fastBuyUltraFlag == "btnTowerUpgr2")
					{
						this->j = 0;
						this->i = 0;
						while (this->i < this->myTower->spheresStack.size())
						{
							if (this->myTower->spheresStack[this->i] == "ice")
							{
								if (this->i == 0)
								{
									this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
								}
								else if (this->i == 1)
								{
									this->container->fastBuyUltraContIndicator2->gotoAndStop(1);
								}
								else if (this->i == 2)
								{
									this->container->fastBuyUltraContIndicator3->gotoAndStop(1);
								}
								else if (this->i == 3)
								{
									this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
								}
								this->j++;
								break;
							}
							i++;
						}
						this->i = 0;
						while (this->i < this->myTower->spheresStack.size())
						{
							if (this->myTower->spheresStack[this->i] == "levin")
							{
								if (this->i == 0)
								{
									this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
								}
								else if (this->i == 1)
								{
									this->container->fastBuyUltraContIndicator2->gotoAndStop(1);
								}
								else if (this->i == 2)
								{
									this->container->fastBuyUltraContIndicator3->gotoAndStop(1);
								}
								else if (this->i == 3)
								{
									this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
								}
								this->j ++;
								break;
							}
							i++;
						}
						if (this->j < 2 && this->world->money >= std::getInt(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT))
						{
							this->i = 0;
							while (this->i < this->myTower->spheresStack.size())
							{
								if (this->myTower->spheresStack[this->i] != "ice" && this->myTower->spheresStack[this->i] != "levin")
								{
									(this->j - 1);
									if (this->i == 0)
									{
										this->container->fastBuyUltraContIndicator1->gotoAndStop(3);
									}
									else if (this->i == 1)
									{
										this->container->fastBuyUltraContIndicator2->gotoAndStop(3);
									}
									else if (this->i == 2)
									{
										this->container->fastBuyUltraContIndicator3->gotoAndStop(3);
									}
									else if (this->i == 3)
									{
										this->container->fastBuyUltraContIndicator4->gotoAndStop(3);
									}
									if (this->j == 0)
									{
										break;
									}
								}
								i++;
							}
						}
					}
					else if (this->fastBuyUltraFlag == "btnTowerUpgr3")
					{
						this->j = 0;
						this->i = 0;
						while (this->i < this->myTower->spheresStack.size())
						{
							if (this->myTower->spheresStack[this->i] == "ice")
							{
								if (this->i == 0)
								{
									this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
								}
								else if (this->i == 1)
								{
									this->container->fastBuyUltraContIndicator2->gotoAndStop(1);
								}
								else if (this->i == 2)
								{
									this->container->fastBuyUltraContIndicator3->gotoAndStop(1);
								}
								else if (this->i == 3)
								{
									this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
								}
								(this->j + 1);
								break;
							}
							i++;
						}
						this->i = 0;
						while (this->i < this->myTower->spheresStack.size())
						{
							if (this->myTower->spheresStack[this->i] == "stone")
							{
								if (this->i == 0)
								{
									this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
								}
								else if (this->i == 1)
								{
									this->container->fastBuyUltraContIndicator2->gotoAndStop(1);
								}
								else if (this->i == 2)
								{
									this->container->fastBuyUltraContIndicator3->gotoAndStop(1);
								}
								else if (this->i == 3)
								{
									this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
								}
								(this->j + 1);
								break;
							}
							i++;
						}
						if (this->j < 2 && this->world->money >= std::getInt(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT))
						{
							this->i = 0;
							while (this->i < this->myTower->spheresStack.size())
							{
								if (this->myTower->spheresStack[this->i] != "ice" && this->myTower->spheresStack[this->i] != "stone")
								{
									(this->j - 1);
									if (this->i == 0)
									{
										this->container->fastBuyUltraContIndicator1->gotoAndStop(3);
									}
									else if (this->i == 1)
									{
										this->container->fastBuyUltraContIndicator2->gotoAndStop(3);
									}
									else if (this->i == 2)
									{
										this->container->fastBuyUltraContIndicator3->gotoAndStop(3);
									}
									else if (this->i == 3)
									{
										this->container->fastBuyUltraContIndicator4->gotoAndStop(3);
									}
									if (this->j == 0)
									{
										break;
									}
								}
								i++;
							}
						}
					}
					else if (this->fastBuyUltraFlag == "btnTowerUpgr4")
					{
						this->j = 0;
						this->i = 0;
						while (this->i < this->myTower->spheresStack.size())
						{
							if (this->myTower->spheresStack[this->i] == "fire")
							{
								if (this->i == 0)
								{
									this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
								}
								else if (this->i == 1)
								{
									this->container->fastBuyUltraContIndicator2->gotoAndStop(1);
								}
								else if (this->i == 2)
								{
									this->container->fastBuyUltraContIndicator3->gotoAndStop(1);
								}
								else if (this->i == 3)
								{
									this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
								}
								(this->j + 1);
								break;
							}
							i++;
						}
						this->i = 0;
						while (this->i < this->myTower->spheresStack.size())
						{
							if (this->myTower->spheresStack[this->i] == "levin")
							{
								if (this->i == 0)
								{
									this->container->fastBuyUltraContIndicator1->gotoAndStop(1);
								}
								else if (this->i == 1)
								{
									this->container->fastBuyUltraContIndicator2->gotoAndStop(1);
								}
								else if (this->i == 2)
								{
									this->container->fastBuyUltraContIndicator3->gotoAndStop(1);
								}
								else if (this->i == 3)
								{
									this->container->fastBuyUltraContIndicator4->gotoAndStop(1);
								}
								(this->j + 1);
								break;
							}
							i++;
						}
						if (this->j < 2 && this->world->money >= std::getInt(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT))
						{
							this->i = 0;
							while (this->i < this->myTower->spheresStack.size())
							{
								if (this->myTower->spheresStack[this->i] != "fire" && this->myTower->spheresStack[this->i] != "levin")
								{
									(this->j - 1);
									if (this->i == 0)
									{
										this->container->fastBuyUltraContIndicator1->gotoAndStop(3);
									}
									else if (this->i == 1)
									{
										this->container->fastBuyUltraContIndicator2->gotoAndStop(3);
									}
									else if (this->i == 2)
									{
										this->container->fastBuyUltraContIndicator3->gotoAndStop(3);
									}
									else if (this->i == 3)
									{
										this->container->fastBuyUltraContIndicator4->gotoAndStop(3);
									}
									if (this->j == 0)
									{
										break;
									}
								}
								i++;
							}
						}
					}
					this->fastBuyPrice = int(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT);
					if (this->world->money >= int(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT))
					{
						this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode = true;
					}
					else
					{
						this->container->fastBuyUltraContBtnFastBuyUltra->gotoAndStop(4);
						std::setText(this->container->fastBuyUltraContBtnFastBuyUltraCostTXT , this->fastBuyPrice);
						this->container->fastBuyUltraContBtnFastBuyUltraFastBuyUltraCase->buttonMode = false;
					}
				}
			}
			return;
		}// end function

		int TowerMenu::fastBuyUltraScan(string param1)
		{
			int tempObject1 = 0;
			if (param1 == "btnTowerUpgr1")
			{
				tempObject1 = Main::mainClass->readXMLClass.costUltraFireStone;
				if (this->myTower->shootingTurnStack.size() == 0)
				{
					if (this->world->worldInterface->fireCount == 0)
					{
						tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfFirePriceXML[this->world->worldInterface->fireBuyHistory];
					}
				}
				if (this->myTower->shootingTurnStack.size() == 2)
				{
					if (this->world->worldInterface->stoneCount == 0)
					{
						tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfStonePriceXML[this->world->worldInterface->stoneBuyHistory];
					}
				}
			}
			else if (param1 == "btnTowerUpgr2")
			{
				tempObject1 = Main::mainClass->readXMLClass.costUltraIceLevin;
				if (this->myTower->shootingTurnStack.size() == 1)//(!this->myTower->shootingTurnStack[1])
				{
					if (this->world->worldInterface->iceCount == 0)
					{
						tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfIcePriceXML[this->world->worldInterface->iceBuyHistory];
					}
				}
				if (this->myTower->shootingTurnStack.size() == 3)//(!this->myTower->shootingTurnStack[3])
				{
					if (this->world->worldInterface->levinCount == 0)
					{
						tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->world->worldInterface->levinBuyHistory];
					}
				}
			}
			else if (param1 == "btnTowerUpgr3")
			{
				tempObject1 = Main::mainClass->readXMLClass.costUltraIceStone;
				if (this->myTower->shootingTurnStack.size() == 1)// (!this->myTower->shootingTurnStack[1])
				{
					if (this->world->worldInterface->iceCount == 0)
					{
						tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfIcePriceXML[this->world->worldInterface->iceBuyHistory];
					}
				}
				if (this->myTower->shootingTurnStack.size() == 2)//(!this->myTower->shootingTurnStack[2])
				{
					if (this->world->worldInterface->stoneCount == 0)
					{
						tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfStonePriceXML[this->world->worldInterface->stoneBuyHistory];
					}
				}
			}
			else if (param1 == "btnTowerUpgr4")
			{
				tempObject1 = Main::mainClass->readXMLClass.costUltraFireLevin;
				if (this->myTower->shootingTurnStack.size() == 0)// (!this->myTower->shootingTurnStack[0])
				{
					if (this->world->worldInterface->fireCount == 0)
					{
						tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfFirePriceXML[this->world->worldInterface->fireBuyHistory];
					}
				}
				if (this->myTower->shootingTurnStack.size() == 3)//(!this->myTower->shootingTurnStack[3])
				{
					if (this->world->worldInterface->levinCount == 0)
					{
						tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->world->worldInterface->levinBuyHistory];
					}
				}
			}
			return  tempObject1;
		}// end function

		void  TowerMenu::closeMenu(bool param1)
		{
			if (!this->readyFastBuyUltraFlag)
			{
				if (this->exampleUltraTower)
				{
					this->exampleUltraManage("remove");
				}
				this->mouseChildren = false;
				this->mouseEnabled = false;
				this->closeFlag = true;
				this->towerRadius->setVisible(false);
				if (this->myTower->towerType < 5)
				{
					//this->myTower->container->selectTower->setVisible(false);
				}
				this->world->towerMenu = NULL;
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
			}
			return;
		}// end function

		void TowerMenu::kill()
		{
			if (!this->dead)
			{
				this->dead = true;
				this->world->worldInterface->updateInfo();
				this->world->removeChild(this->towerRadius);
				this->towerRadius = NULL;
				this->world->removeChild(this->towerRadius1);
				this->towerRadius1 = NULL;
				this->world->removeChild(this);
				//this->i = 0;
				//while (this->i < this->world->listOfClasses.size())
				//{
				//    if (this->world->listOfClasses[this->i] == this)
				//    {
				//        this->world->listOfClasses.splice(this->i, 1);
				//        break;
				//    }
				//    i++;
				//}
				//this->i = 0;
				//while (this->i < this->world->listOfIndexes3.size())
				//{
				//    if (this->world->listOfIndexes3[this->i] == this)
				//    {
				//        this->world->listOfIndexes3.splice(this->i, 1);
				//        break;
				//    }
				//    i++;
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
