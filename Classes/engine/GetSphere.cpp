
#include "GetSphere.h"
#include "engine/World.h"

namespace engine
{
	GetSphere_mc::GetSphere_mc() :MovieClip("worldinterface/", "GetSphere_mc", "GetSphere_mc")
	{
		cont = this->createMovieClipSub("cont");
		sphere1 = this->createMovieClipSub("sphere1");
		sphere1Cont = sphere1->createMovieClipSub("cont");
		sphere2 = this->createMovieClipSub("sphere2");
		sphere2Cont = sphere2->createMovieClipSub("cont");
		sphere3 = this->createMovieClipSub("sphere3");
		sphere3Cont = sphere3->createMovieClipSub("cont");
		sphere4 = this->createMovieClipSub("sphere4");
		sphere4Cont = sphere4->createMovieClipSub("cont");
	};
	GetSphere::GetSphere(string param1) :counter(0), myRadius(0), myDamage(0), fireCount(0), iceCount(0), stoneCount(0), levinCount(0), towerArrow(0)
	{
		//this->listOfStack = [];
		//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
		this->type = param1;
		return;
	}// end function
	bool GetSphere::init()
	{
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
		this->world = Main::mainClass->worldClass;
		if (this->type == "holder")
		{
			GetSphere_mc * container = new GetSphere_mc();
			this->container = container;
			container->stop();
			container->cont->stop();
			container->sphere1->stop();
			container->sphere2->stop();
			container->sphere3->stop();
			container->sphere4->stop();
			container->sphere1Cont->stop();
			container->sphere2Cont->stop();
			container->sphere3Cont->stop();
			container->sphere4Cont->stop();

			container->sphere1->setVisible(false);
			container->sphere2->setVisible(false);
			container->sphere3->setVisible(false);
			container->sphere4->setVisible(false);
		}
		else if (this->type == "getAll")
		{
			GetAll_mc * container = new GetAll_mc();
			this->container = container;
			container->stop();
			//container->cross->stop();
			container->cross->setVisible(false);
		}
		this->addChild(this->container);
		this->world->worldInterface->castRegime("on");
		this->arrow = new Arrow_mc();
		this->arrow->stop();
		this->arrow->setScaleY(-1);
		this->arrow->setPositionY(this->arrow->getPositionY() - 30);
		this->arrow->setVisible(false);
		this->addChild(this->arrow);
		if (this->world->towerMenu)
		{
			if (this->world->towerMenu->container->btnUpgradeMenu)
			{
				if (this->world->towerMenu->container->btnUpgradeMenuBtnUpgradeMenuCase->isReady)
				{
					if (this->world->towerMenu->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode)
					{
						this->world->towerMenu->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = false;
					}
				}
			}
			else
			{
				if (this->world->towerMenu->container->btnTowerUpgr1)
				{
					this->world->towerMenu->container->btnTowerUpgr1BtnTowerUpgrCase->buttonMode = false;
				}
				if (this->world->towerMenu->container->btnTowerUpgr2)
				{
					this->world->towerMenu->container->btnTowerUpgr2BtnTowerUpgrCase->buttonMode = false;
				}
				if (this->world->towerMenu->container->btnTowerUpgr3)
				{
					this->world->towerMenu->container->btnTowerUpgr3BtnTowerUpgrCase->buttonMode = false;
				}
				if (this->world->towerMenu->container->btnTowerUpgr4)
				{
					this->world->towerMenu->container->btnTowerUpgr4BtnTowerUpgrCase->buttonMode = false;
				}
			}
		}
		else if (this->world->ultraTowerMenu)
		{
			if (this->world->ultraTowerMenu->container->btnUpgradeMenu)
			{
				if (this->world->ultraTowerMenu->container->btnUpgradeMenuBtnUpgradeMenuCase->isReady)
				{
					if (this->world->ultraTowerMenu->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode)
					{
						this->world->ultraTowerMenu->container->btnUpgradeMenuBtnUpgradeMenuCase->buttonMode = false;
					}
				}
			}
		}
		this->setPosition(this->world->mouseX, this->world->mouseY);
		this->mouseChildren = false;
		this->mouseEnabled = false;
		return true;
	}// end function
	void  GetSphere::update(float dt)
	{
		if (this->type == "holder")
		{
			if (dynamic_cast<GetSphere_mc*>(this->container))
			{
				GetSphere_mc* container = (GetSphere_mc*)this->container;
				if (container->sphere1->isVisible())
				{
					if (container->sphere1->currentFrame < container->sphere1->totalFrames)
					{
						container->sphere1->gotoAndStop((container->sphere1->currentFrame + 1));
					}
					else
					{
						container->sphere1->gotoAndStop(1);
					}
				}
				if (container->sphere2->isVisible())
				{
					if (container->sphere2->currentFrame < container->sphere2->totalFrames)
					{
						container->sphere2->gotoAndStop((container->sphere2->currentFrame + 1));
					}
					else
					{
						container->sphere2->gotoAndStop(1);
					}
				}
				if (container->sphere3->isVisible())
				{
					if (container->sphere3->currentFrame < container->sphere3->totalFrames)
					{
						container->sphere3->gotoAndStop((container->sphere3->currentFrame + 1));
					}
					else
					{
						container->sphere3->gotoAndStop(1);
					}
				}
				if (container->sphere4->isVisible())
				{
					if (container->sphere4->currentFrame < container->sphere4->totalFrames)
					{
						container->sphere4->gotoAndStop((container->sphere4->currentFrame + 1));
					}
					else
					{
						container->sphere4->gotoAndStop(1);
					}
				}
				if (container->cont->currentFrame < container->cont->totalFrames)
				{
					container->cont->gotoAndStop((container->cont->currentFrame + 1));
				}
				else
				{
					container->cont->gotoAndStop(1);
				}
			}
		}
		else if (this->type == "getAll")
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
		if (this->arrow->isVisible())
		{
			if (this->arrow->currentFrame < this->arrow->totalFrames)
			{
				this->arrow->gotoAndStop((this->arrow->currentFrame + 1));
			}
			else
			{
				this->arrow->gotoAndStop(1);
			}
		}
		if (this->towerArrow)
		{
			if (this->towerArrow->currentFrame < this->towerArrow->totalFrames)
			{
				this->towerArrow->gotoAndStop((this->towerArrow->currentFrame + 1));
			}
			else
			{
				this->towerArrow->gotoAndStop(1);
			}
		}
		if (this->containerChange)
		{
			if (this->containerChange->getOpacity() > 0)
			{
				this->containerChange->setOpacity(this->containerChange->getOpacity() - 0.1);
				container->setOpacity(container->getOpacity() *(1 + 0.1));
			}
			else
			{
				this->removeChild(this->containerChange);
				this->containerChange = NULL;
				container->setOpacity(255);
			}
		}
		if (this->world->getSphere == this)
		{
			this->world->feature->scanPointersAtCast();
			this->setPosition(this->world->mouseX, this->world->mouseY);
			if (this->radius->isVisible())
			{
				if (this->radius->currentFrame == 1)
				{
					this->radius->setRotation(this->radius->getRotation() + 1);
				}
				if (this->radius->cont->currentFrame < this->radius->cont->totalFrames)
				{
					this->radius->cont->gotoAndStop((this->radius->cont->currentFrame + 1));
				}
				else
				{
					this->radius->cont->gotoAndStop(1);
				}
			}
		}
		return;
	}// end function
	void  GetSphere::mouseMoveHandler(cocos2d::Event* e)
	{
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
		if (event->target->getName() == "fireCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode && this->world->worldInterface->container->fireBack->currentFrame == 1)
			{
				if (this->world->worldInterface->container->iceBack->currentFrame == 2)
				{
					this->world->worldInterface->container->iceBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->stoneBack->currentFrame == 2)
				{
					this->world->worldInterface->container->stoneBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->levinBack->currentFrame == 2)
				{
					this->world->worldInterface->container->levinBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->getAll->currentFrame == 2)
				{
					this->world->worldInterface->container->getAll->gotoAndStop(1);
				}
				this->world->worldInterface->container->fireBack->gotoAndStop(2);
				this->world->worldInterface->container->fireBackCont->stop();
				//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
			}
		}
		else if (this->world->worldInterface->container->fireBack->currentFrame == 2)
		{
			this->world->worldInterface->container->fireBack->gotoAndStop(1);
		}
		if (event->target->getName() == "iceCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode && this->world->worldInterface->container->iceBack->currentFrame == 1)
			{
				if (this->world->worldInterface->container->fireBack->currentFrame == 2)
				{
					this->world->worldInterface->container->fireBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->stoneBack->currentFrame == 2)
				{
					this->world->worldInterface->container->stoneBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->levinBack->currentFrame == 2)
				{
					this->world->worldInterface->container->levinBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->getAll->currentFrame == 2)
				{
					this->world->worldInterface->container->getAll->gotoAndStop(1);
				}
				this->world->worldInterface->container->iceBack->gotoAndStop(2);
				this->world->worldInterface->container->iceBackCont->stop();
				//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
			}
		}
		else if (this->world->worldInterface->container->iceBack->currentFrame == 2)
		{
			this->world->worldInterface->container->iceBack->gotoAndStop(1);
		}
		if (event->target->getName() == "stoneCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode && this->world->worldInterface->container->stoneBack->currentFrame == 1)
			{
				if (this->world->worldInterface->container->fireBack->currentFrame == 2)
				{
					this->world->worldInterface->container->fireBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->iceBack->currentFrame == 2)
				{
					this->world->worldInterface->container->iceBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->levinBack->currentFrame == 2)
				{
					this->world->worldInterface->container->levinBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->getAll->currentFrame == 2)
				{
					this->world->worldInterface->container->getAll->gotoAndStop(1);
				}
				this->world->worldInterface->container->stoneBack->gotoAndStop(2);
				this->world->worldInterface->container->stoneBackCont->stop();
				//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
			}
		}
		else if (this->world->worldInterface->container->stoneBack->currentFrame == 2)
		{
			this->world->worldInterface->container->stoneBack->gotoAndStop(1);
		}
		if (event->target->getName() == "levinCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode && this->world->worldInterface->container->levinBack->currentFrame == 1)
			{
				if (this->world->worldInterface->container->fireBack->currentFrame == 2)
				{
					this->world->worldInterface->container->fireBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->iceBack->currentFrame == 2)
				{
					this->world->worldInterface->container->iceBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->stoneBack->currentFrame == 2)
				{
					this->world->worldInterface->container->stoneBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->getAll->currentFrame == 2)
				{
					this->world->worldInterface->container->getAll->gotoAndStop(1);
				}
				this->world->worldInterface->container->levinBack->gotoAndStop(2);
				this->world->worldInterface->container->levinBackCont->stop();
				//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
			}
		}
		else if (this->world->worldInterface->container->levinBack->currentFrame == 2)
		{
			this->world->worldInterface->container->levinBack->gotoAndStop(1);
		}
		if (event->target->getName() == "getAllCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode && this->world->worldInterface->container->getAll->currentFrame == 1)
			{
				if (this->world->worldInterface->container->fireBack->currentFrame == 2)
				{
					this->world->worldInterface->container->fireBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->iceBack->currentFrame == 2)
				{
					this->world->worldInterface->container->iceBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->stoneBack->currentFrame == 2)
				{
					this->world->worldInterface->container->stoneBack->gotoAndStop(1);
				}
				if (this->world->worldInterface->container->levinBack->currentFrame == 2)
				{
					this->world->worldInterface->container->levinBack->gotoAndStop(1);
				}
				this->world->worldInterface->container->getAll->gotoAndStop(2);
				//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
			}
		}
		else if (this->world->worldInterface->container->getAll->currentFrame == 2)
		{
			this->world->worldInterface->container->getAll->gotoAndStop(1);
		}
		if (event->target->getName() == "fireCase" || event->target->getName() == "iceCase" || event->target->getName() == "stoneCase"
			|| event->target->getName() == "levinCase" || event->target->getName() == "getAllCase" || event->target->getName() == "archiveCase"
			|| event->target->getName() == "interfaceUpCase" || event->target->getName() == "sellCase" || event->target->getName() == "towerCase")
		{
			if (this->radius->isVisible())
			{
				this->radius->setVisible(false);
				this->arrow->setVisible(false);
			}
			if (event->target->getName() == "towerCase")
			{
				Node * parent = event->target->getParent()->getParent();
				Tower * tower = ISTYPE(Tower, parent);
				if (this->type == "holder")
				{
					if (ISTYPE(EventNode, event->target)->buttonMode && tower->spheresManage("scan") > 0)
					{
						if (!this->towerArrow)
						{
							this->towerArrow = new Arrow_mc();
							this->towerArrow->stop();
							this->towerArrow->myTower = tower;
							this->towerArrow->mouseChildren = false;
							this->towerArrow->mouseEnabled = false;
							this->towerArrow->myTower->addChild(this->towerArrow);
						}
						if (container->currentFrame == 2)
						{
							container->gotoAndStop(1);
						}
					}
					else
					{
						if (this->towerArrow)
						{
							this->towerArrow->myTower->removeChild(this->towerArrow);
							this->towerArrow = NULL;
						}
						if (container->currentFrame == 1)
						{
							container->gotoAndStop(2);
						}
					}
				}
				else if (this->type == "getAll")
				{
					GetAll_mc * container = ISTYPE(GetAll_mc, this->container);
					if (ISTYPE(EventNode, event->target)->buttonMode && tower->spheresManage("scan") == 4)
					{
						if (!this->towerArrow)
						{
							this->towerArrow = new Arrow_mc();
							this->towerArrow->stop();
							this->towerArrow->myTower = tower;
							this->towerArrow->mouseChildren = false;
							this->towerArrow->mouseEnabled = false;
							this->towerArrow->myTower->addChild(this->towerArrow);
						}
						if (container->cross->isVisible())
						{
							container->cross->setVisible(false);
						}
					}
					else
					{
						if (this->towerArrow)
						{
							this->towerArrow->myTower->removeChild(this->towerArrow);
							this->towerArrow = NULL;
						}
						if (container->cross->isVisible())
						{
							container->cross->setVisible(true);
						}
					}
				}
			}
		}
		else
		{
			if (this->towerArrow)
			{
				this->towerArrow->myTower->removeChild(this->towerArrow);
				this->towerArrow = NULL;
			}
			if (this->type == "holder")
			{
				if (container->currentFrame == 2)
				{
					container->gotoAndStop(1);
				}
			}
			else if (this->type == "getAll")
			{
				GetAll_mc * container = ISTYPE(GetAll_mc, this->container);
				if (container->cross->isVisible())
				{
					container->cross->setVisible(false);
				}
			}
			if (!this->world->towerMenu && !this->world->ultraTowerMenu)
			{
				if (!this->radius->isVisible())
				{
					this->radius->setVisible(true);
					this->arrow->setVisible(true);
				}
			}
			else
			{
				BaseTowerMenu *tempObject = NULL;
				if (this->world->towerMenu)
				{
					tempObject = this->world->towerMenu;
				}
				else if (this->world->ultraTowerMenu)
				{
					tempObject = this->world->ultraTowerMenu;
				}
				if (!this->radius->isVisible() && tempObject->myTower->this_pt.distance(cocos2d::Point(this->world->mouseX, this->world->mouseY)) > 86)
				{
					this->radius->setVisible(true);
					this->arrow->setVisible(true);
					tempObject->closeMenu();
				}
			}
			if (event->target->getName() == "road")
			{
				if (this->radius->currentFrame == 2)
				{
					this->radius->gotoAndStop(1);
					this->arrow->setAlpha(0);
					this->radius->cont->stop();
					if (this->radius->cont1)
					{
						if (this->type == "holder")
						{
							this->radius->cont1->stop();
							this->radius->cont2->stop();
							this->radius->cont3->stop();
							this->radius->cont1->setVisible(false);
							this->radius->cont2->setVisible(false);
							this->radius->cont3->setVisible(false);
						}
						else
						{
							this->radius->cont1->stop();
							this->radius->cont2->stop();
							this->radius->cont3->stop();
							if (this->getAllCount > 0)
							{
								this->radius->cont1->setVisible(true);
							}
							else
							{
								this->radius->cont1->setVisible(false);
							}
							if (this->getAllCount > 1)
							{
								this->radius->cont2->setVisible(true);
							}
							else
							{
								this->radius->cont2->setVisible(false);
							}
							if (this->getAllCount > 2)
							{
								this->radius->cont3->setVisible(true);
							}
							else
							{
								this->radius->cont3->setVisible(false);
							}
						}
					}
				}
			}
			else if (this->radius->currentFrame == 1)
			{
				this->radius->gotoAndStop(2);
				this->arrow->setOpacity(255);
				this->radius->stop();
				if (this->radius->cont1)
				{
					if (this->type == "holder")
					{
						this->radius->cont1->stop();
						this->radius->cont2->stop();
						this->radius->cont3->stop();
						this->radius->cont1->setVisible(false);
						this->radius->cont2->setVisible(false);
						this->radius->cont3->setVisible(false);
					}
					else
					{
						this->radius->cont1->stop();
						this->radius->cont2->stop();
						this->radius->cont3->stop();
						if (this->getAllCount > 0)
						{
							this->radius->cont1->setVisible(true);
						}
						else
						{
							this->radius->cont1->setVisible(false);
						}
						if (this->getAllCount > 1)
						{
							this->radius->cont2->setVisible(true);
						}
						else
						{
							this->radius->cont2->setVisible(false);
						}
						if (this->getAllCount > 2)
						{
							this->radius->cont3->setVisible(true);
						}
						else
						{
							this->radius->cont3->setVisible(false);
						}
					}
				}
			}
		}
		if (event->target->getName() == "sphereSlotCase")
		{
			if (this->world->towerMenu)
			{
				this->world->towerMenu->mouseMoveHandler(event);
			}
			else if (this->world->ultraTowerMenu)
			{
				this->world->ultraTowerMenu->mouseMoveHandler(event);
			}
		}
		else if (this->world->towerMenu)
		{
			if (this->world->towerMenu->container->sphereSlot1->currentFrame == 2)
			{
				this->world->towerMenu->container->sphereSlot1->gotoAndStop(1);
			}
			if (this->world->towerMenu->container->sphereSlot2->currentFrame == 2)
			{
				this->world->towerMenu->container->sphereSlot2->gotoAndStop(1);
			}
			if (this->world->towerMenu->container->sphereSlot3->currentFrame == 2)
			{
				this->world->towerMenu->container->sphereSlot3->gotoAndStop(1);
			}
			if (this->world->towerMenu->container->sphereSlot4->currentFrame == 2)
			{
				this->world->towerMenu->container->sphereSlot4->gotoAndStop(1);
			}
		}
		else if (this->world->ultraTowerMenu)
		{
			if (this->world->ultraTowerMenu->container->sphereSlot1->currentFrame == 2)
			{
				this->world->ultraTowerMenu->container->sphereSlot1->gotoAndStop(1);
			}
			if (this->world->ultraTowerMenu->container->sphereSlot2->currentFrame == 2)
			{
				this->world->ultraTowerMenu->container->sphereSlot2->gotoAndStop(1);
			}
		}
		if (event->target->getName() == "sellCase")
		{
			if (this->world->worldInterface->container->sell->currentFrame == 1)
			{
				this->world->worldInterface->container->sell->gotoAndStop(2);
				//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
			}
		}
		else if (this->world->worldInterface->container->sell->currentFrame == 2)
		{
			this->world->worldInterface->container->sell->gotoAndStop(1);
		}
		return;
	}// end function

	void GetSphere::mouseDownHandler(cocos2d::Event* e)
	{
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
		if (event->target->getName() == "sellCase")
		{
			this->world->worldInterface->container->sell->gotoAndStop(1);
			while (this->fireCount > 0)
			{
				this->fireCount--;
				this->world->worldInterface->sellSphere("fire");
			}
			while (this->iceCount > 0)
			{
				this->iceCount--;
				this->world->worldInterface->sellSphere("ice");
			}
			while (this->stoneCount > 0)
			{

				this->stoneCount--;
				this->world->worldInterface->sellSphere("stone");
			}
			while (this->levinCount > 0)
			{

				this->levinCount--;
				this->world->worldInterface->sellSphere("levin");
			}
			while (this->getAllCount > 0)
			{

				this->getAllCount--;
				this->world->worldInterface->sellSphere("getAll");
			}
			this->kill();
			//Sounds.instance.playSound("snd_world_sell");
		}
		else if (event->target->getName() == "towerCase" && ISTYPE(EventNode, event->target)->buttonMode)
		{
			Node * parent = event->target->getParent()->getParent();
			Tower * tempObject = ISTYPE(Tower, parent);
			int tempObject1 = 0;
			if (this->type == "holder")
			{
				GetSphere_mc * container = ISTYPE(GetSphere_mc, this->container);
				container->sphere1->setVisible(false);
				container->sphere2->setVisible(false);
				container->sphere3->setVisible(false);
				container->sphere4->setVisible(false);
				this->i = 0;
				while (this->i < this->listOfStack.size())
				{
					if (this->listOfStack[this->i] == "fire")
					{
						tempObject1 = tempObject->spheresManage("push", "fire", 1);
						if (tempObject1 == 0)
						{
							this->fireCount--;
							this->listOfStack[this->i] = "none";
						}
					}
					else if (this->listOfStack[this->i] == "ice")
					{
						tempObject1 = tempObject->spheresManage("push", "ice", 1);
						if (tempObject1 == 0)
						{
							this->iceCount--;
							this->listOfStack[this->i] = "none";
						}
					}
					else if (this->listOfStack[this->i] == "stone")
					{
						tempObject1 = tempObject->spheresManage("push", "stone", 1);
						if (tempObject1 == 0)
						{
							this->stoneCount--;
							this->listOfStack[this->i] = "none";
						}
					}
					else if (this->listOfStack[this->i] == "levin")
					{
						tempObject1 = tempObject->spheresManage("push", "levin", 1);
						if (tempObject1 == 0)
						{
							this->levinCount--;
							this->listOfStack[this->i] = "none";
						}
					}
					i++;
				}
				this->i = this->listOfStack.size() - 1;
				while (this->i >= 0)
				{
					if (this->listOfStack[this->i] == "none")
					{
						this->listOfStack.splice(this->i, 1);
					}
					i--;
				}
				if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount == 0)
				{
					this->kill();
				}
				else
				{
					this->retrieveGetSphere();
				}
			}
			else if (this->type == "getAll")
			{
				this->getAllCount--;
				tempObject1 = tempObject->spheresManage("push", "getAll", 1);
				this->getAllCount = this->getAllCount + tempObject1;
				if (this->getAllCount == 0)
				{
					this->kill();
				}
				else
				{
					this->retrieveGetSphere();
				}
			}
		}
		else if (event->target->getName() == "fireCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode)
			{
				if (this->listOfStack.size() < 4)
				{
					if (this->world->worldInterface->fireCount == 0)
					{
						this->world->worldInterface->archiveManage("buy", "fire");
					}
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
					this->world->worldInterface->archiveManage("get", "fire");
				}
			}
		}
		else if (event->target->getName() == "iceCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode)
			{
				if (this->listOfStack.size() < 4)
				{
					if (this->world->worldInterface->iceCount == 0)
					{
						this->world->worldInterface->archiveManage("buy", "ice");
					}
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
					this->world->worldInterface->archiveManage("get", "ice");
				}
			}
		}
		else if (event->target->getName() == "stoneCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode)
			{
				if (this->listOfStack.size() < 4)
				{
					if (this->world->worldInterface->stoneCount == 0)
					{
						this->world->worldInterface->archiveManage("buy", "stone");
					}
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
					this->world->worldInterface->archiveManage("get", "stone");
				}
			}
		}
		else if (event->target->getName() == "levinCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode)
			{
				if (this->listOfStack.size() < 4)
				{
					if (this->world->worldInterface->levinCount == 0)
					{
						this->world->worldInterface->archiveManage("buy", "levin");
					}
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
					this->world->worldInterface->archiveManage("get", "levin");
				}
			}
		}
		else if (event->target->getName() == "getAllCase")
		{
			if (ISTYPE(EventNode, event->target)->buttonMode)
			{
				if (this->getAllCount < 3)
				{
					if (this->world->worldInterface->getAllCount == 0)
					{
						this->world->worldInterface->archiveManage("buy", "getAll");
					}
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
					this->world->worldInterface->archiveManage("get", "getAll");
				}
			}
		}
		else if (event->target->getName() == "sphereSlotCase")
		{
			Node * parent = event->target->getParent()->getParent()->getParent();
			TowerMenu_mc * towerMenuMc = ISTYPE(TowerMenu_mc, parent);
			MCCase * scase = ISTYPE(MCCase, event->target);
			//TowerMenu_mc  event->target->getParent()->getParent()->getParent()
			MovieClipSub *	sphereAnima = towerMenuMc->getSphereAnima(scase);
			MovieClipSub  * sphereSlot = towerMenuMc->getSphereSlot(scase);//ISTYPE(MovieClipSub, event->target->getParent());
			if (sphereSlot->currentFrame == 2)
			{
				BaseTowerMenu *tempObject = NULL;
				if (this->listOfStack.size() < 4)
				{
					if (this->world->towerMenu)
					{
						tempObject = this->world->towerMenu;
					}
					else if (this->world->ultraTowerMenu)
					{
						tempObject = this->world->ultraTowerMenu;
					}
					if (sphereAnima->isVisible())
					{
						if (sphereAnima->isVisible())
						{
							if (sphereAnima->currentFrame == 1)
							{
								tempObject->myTower->towerGetSphereManage("get", "fire");
								if (!this->world->ultraTowerMenu)
								{
									ISTYPE(TowerMenu, tempObject)->spheresMonitor();
								}
							}
							else if (sphereAnima->currentFrame == 2)
							{
								tempObject->myTower->towerGetSphereManage("get", "ice");
								if (!this->world->ultraTowerMenu)
								{
									ISTYPE(TowerMenu, tempObject)->spheresMonitor();
								}
							}
							else if (sphereAnima->currentFrame == 3)
							{
								tempObject->myTower->towerGetSphereManage("get", "stone");
								if (!this->world->ultraTowerMenu)
								{
									ISTYPE(TowerMenu, tempObject)->spheresMonitor();
								}
							}
							else if (sphereAnima->currentFrame == 4)
							{
								tempObject->myTower->towerGetSphereManage("get", "levin");
								if (!this->world->ultraTowerMenu)
								{
									ISTYPE(TowerMenu, tempObject)->spheresMonitor();
								}
							}
						}
					}
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
				}
			}
			else if (sphereSlot->currentFrame == 1)
			{
				this->getSphereFromArchiveToTower();
				this->speedFrame = 0;
			}
		}
		else if (event->target->getName() != "archiveCase" && event->target->getName() != "getAllCase")
		{
			if (this->radius->currentFrame == 1)
			{
				CastSphere * tempObject = new CastSphere();
				this->world->addChild(tempObject);
				this->kill();
			}
			else if (ISTYPE(TowerMenu_mc, event->target) || ISTYPE(TowerMenu_mc, event->target->getParent()) || ISTYPE(TowerMenu_mc, event->target->getParent()->getParent())
				|| ISTYPE(UltraTowerMenu_mc, event->target) || ISTYPE(UltraTowerMenu_mc, event->target->getParent()) || ISTYPE(UltraTowerMenu_mc, event->target->getParent()->getParent()))
			{
				if (this->world->towerMenu || this->world->ultraTowerMenu)
				{
					this->getSphereFromArchiveToTower();
					this->speedFrame = 0;
				}
			}
			else
			{
				this->retrieveGetSphereToArchive();
			}
		}
		return;
	}// end function
	void GetSphere::mouseUpHandler(cocos2d::Event* e)
	{
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
		return;
	}// end function

	void GetSphere::retrieveGetSphereToArchive()
	{
		this->ownerType = "archive";
		if (this->fireCount > 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount == 0)
		{
			this->owner = this->world->worldInterface->container->fireSphere;
			this->ownerPoint = this->world->worldInterface->container->fireSphereMyPoint;
		}
		else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount == 0)
		{
			this->owner = this->world->worldInterface->container->iceSphere;
			this->ownerPoint = this->world->worldInterface->container->iceSphereMyPoint;
		}
		else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount == 0)
		{
			this->owner = this->world->worldInterface->container->stoneSphere;
			this->ownerPoint = this->world->worldInterface->container->stoneSphereMyPoint;
		}
		else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount > 0)
		{
			this->owner = this->world->worldInterface->container->levinSphere;
			this->ownerPoint = this->world->worldInterface->container->levinSphereMyPoint;
		}
		else
		{
			this->owner = this->world->worldInterface->container->getAll;
			this->ownerPoint = this->world->worldInterface->container->getAllMyPoint;
		}
		this->retrieveGetSphere();
		return;
	}// end function
	void GetSphere::manage(string param1, string param2)
	{
		if (param1 == "add")
		{
			if (this->type == "holder")
			{
				GetSphere_mc *container = ISTYPE(GetSphere_mc, this->container);
				if (this->listOfStack.size() < 4)
				{
					this->listOfStack.push(param2);
					if (param2 == "fire")
					{
						if (this->listOfStack.size() == 1)
						{
							container->sphere1->gotoAndStop(1);
							container->sphere1Cont->stop();
							container->sphere1->setVisible(true);
						}
						else if (this->listOfStack.size() == 2)
						{
							container->sphere2->gotoAndStop(1);
							container->sphere2Cont->stop();
							container->sphere2->setVisible(true);
						}
						else if (this->listOfStack.size() == 3)
						{
							container->sphere3->gotoAndStop(1);
							container->sphere3Cont->stop();
							container->sphere3->setVisible(true);
						}
						else if (this->listOfStack.size() == 4)
						{
							container->sphere4->gotoAndStop(1);
							container->sphere4Cont->stop();
							container->sphere4->setVisible(true);
						}
						(this->fireCount + 1);
					}
					else if (param2 == "ice")
					{
						if (this->listOfStack.size() == 1)
						{
							container->sphere1->gotoAndStop(2);
							container->sphere1Cont->stop();
							container->sphere1->setVisible(true);
						}
						else if (this->listOfStack.size() == 2)
						{
							container->sphere2->gotoAndStop(2);
							container->sphere2Cont->stop();
							container->sphere2->setVisible(true);
						}
						else if (this->listOfStack.size() == 3)
						{
							container->sphere3->gotoAndStop(2);
							container->sphere3Cont->stop();
							container->sphere3->setVisible(true);
						}
						else if (this->listOfStack.size() == 4)
						{
							container->sphere4->gotoAndStop(2);
							container->sphere4Cont->stop();
							container->sphere4->setVisible(true);
						}
						(this->iceCount + 1);
					}
					else if (param2 == "stone")
					{
						if (this->listOfStack.size() == 1)
						{
							container->sphere1->gotoAndStop(3);
							container->sphere1Cont->stop();
							container->sphere1->setVisible(true);
						}
						else if (this->listOfStack.size() == 2)
						{
							container->sphere2->gotoAndStop(3);
							container->sphere2Cont->stop();
							container->sphere2->setVisible(true);
						}
						else if (this->listOfStack.size() == 3)
						{
							container->sphere3->gotoAndStop(3);
							container->sphere3Cont->stop();
							container->sphere3->setVisible(true);
						}
						else if (this->listOfStack.size() == 4)
						{
							container->sphere4->gotoAndStop(3);
							container->sphere4Cont->stop();
							container->sphere4->setVisible(true);
						}
						(this->stoneCount + 1);
					}
					else if (param2 == "levin")
					{
						if (this->listOfStack.size() == 1)
						{
							container->sphere1->gotoAndStop(4);
							container->sphere1Cont->stop();
							container->sphere1->setVisible(true);
						}
						else if (this->listOfStack.size() == 2)
						{
							container->sphere2->gotoAndStop(4);
							container->sphere2Cont->stop();
							container->sphere2->setVisible(true);
						}
						else if (this->listOfStack.size() == 3)
						{
							container->sphere3->gotoAndStop(4);
							container->sphere3Cont->stop();
							container->sphere3->setVisible(true);
						}
						else if (this->listOfStack.size() == 4)
						{
							container->sphere4->gotoAndStop(4);
							container->sphere4Cont->stop();
							container->sphere4->setVisible(true);
						}
						(this->levinCount + 1);
					}
					if (this->fireCount == 1 && this->iceCount == 1 && this->stoneCount == 1 && this->levinCount == 1)
					{
						this->fireCount = 0;
						this->iceCount = 0;
						this->stoneCount = 0;
						this->levinCount = 0;
						this->getAllCount = 1;
						this->type = "getAll";
						this->containerChange = this->container;
						this->listOfStack.clear();// = [];
						this->container = new GetAll_mc();
						GetAll_mc *container = ISTYPE(GetAll_mc, this->container);
						container->stop();
						//container->cross->stop();
						std::setText(container->numTXT, this->getAllCount);
						//container->numTXT.text = this->getAllCount;
						container->cross->setVisible(false);
						container->setAlpha(0);
						this->addChild(this->container);
					}
				}
			}
			else if (this->type == "getAll")
			{
				if (this->getAllCount < 3)
				{
					GetAll_mc *container = ISTYPE(GetAll_mc, this->container);
					this->getAllCount++;
					std::setText(container->numTXT, this->getAllCount);
				}
			}
			if (this->fireCount > 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount == 0)
			{
				if (this->radius && !ISTYPE(RadiusFire_mc, this->radius))
				{
					this->removeChild(this->radius);
					this->radius = NULL;
				}
				if (!this->radius)
				{
					this->radius = new RadiusFire_mc();
					this->radius->gotoAndStop(2);
					this->arrow->setAlpha(1);
					this->radius->cont->stop();
					this->radius->setHeight(Main::mainClass->readXMLClass.listOfMoveFireXML[0] * 2);
					this->radius->setWidth(Main::mainClass->readXMLClass.listOfMoveFireXML[0] * 2);
					this->radius->setVisible(false);
					this->arrow->setVisible(false);
					this->addChild(this->radius, 0);
				}
				this->myRadius = Main::mainClass->readXMLClass.listOfMoveFireXML[0];
				this->myDamage = Main::mainClass->readXMLClass.listOfMoveFireXML[this->fireCount];
			}
			else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount == 0)
			{
				if (this->radius && !(ISTYPE(RadiusIce_mc, this->radius)))
				{
					this->removeChild(this->radius);
					this->radius = NULL;
				}
				if (!this->radius)
				{
					this->radius = new RadiusIce_mc();
					this->radius->gotoAndStop(2);
					this->arrow->setAlpha(1);
					this->radius->cont->stop();
					this->radius->setHeight(Main::mainClass->readXMLClass.listOfMoveIceXML[0] * 2);
					this->radius->setWidth(Main::mainClass->readXMLClass.listOfMoveIceXML[0] * 2);
					this->radius->setVisible(false);
					this->arrow->setVisible(false);
					this->addChild(this->radius, 0);
				}
				this->myRadius = Main::mainClass->readXMLClass.listOfMoveIceXML[0];
				this->myDamage = Main::mainClass->readXMLClass.listOfMoveIceXML[this->iceCount];
			}
			else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount == 0)
			{
				if (this->radius && !ISTYPE(RadiusStone_mc, this->radius))
				{
					this->removeChild(this->radius);
					this->radius = NULL;
				}
				if (!this->radius)
				{
					this->radius = new RadiusStone_mc();
					this->radius->gotoAndStop(2);
					this->arrow->setAlpha(1);
					this->radius->cont->stop();
					this->radius->setHeight(Main::mainClass->readXMLClass.listOfMoveStoneXML[0] * 2);
					this->radius->setWidth(Main::mainClass->readXMLClass.listOfMoveStoneXML[0] * 2);
					this->radius->setVisible(false);
					this->arrow->setVisible(false);
					this->addChild(this->radius, 0);
				}
				this->myRadius = Main::mainClass->readXMLClass.listOfMoveStoneXML[0];
				this->myDamage = Main::mainClass->readXMLClass.listOfMoveStoneXML[this->stoneCount];
			}
			else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount > 0)
			{
				if (this->radius && !ISTYPE(RadiusLevin_mc, this->radius))
				{
					this->removeChild(this->radius);
					this->radius = NULL;
				}
				if (!this->radius)
				{
					this->radius = new RadiusLevin_mc();
					this->radius->gotoAndStop(2);
					this->arrow->setAlpha(1);
					this->radius->cont->stop();
					this->radius->setHeight(Main::mainClass->readXMLClass.listOfMoveLevinXML[0] * 2);
					this->radius->setWidth(Main::mainClass->readXMLClass.listOfMoveLevinXML[0] * 2);
					this->radius->setVisible(false);
					this->arrow->setVisible(false);
					this->addChild(this->radius, 0);
				}
				this->myRadius = Main::mainClass->readXMLClass.listOfMoveLevinXML[0];
				this->myDamage = Main::mainClass->readXMLClass.listOfMoveLevinXML[this->levinCount];
			}
			else
			{
				if (this->radius)
				{
					this->removeChild(this->radius);
					this->radius = NULL;
				}
				if (!this->radius)
				{
					this->radius = new RadiusGetAll_mc();
					this->radius->gotoAndStop(2);
					this->arrow->setAlpha(1);
					this->radius->cont->stop();
					if (this->radius->cont1)
					{
						if (this->type == "holder")
						{
							this->radius->cont1->stop();
							this->radius->cont2->stop();
							this->radius->cont3->stop();
							this->radius->cont1->setVisible(false);
							this->radius->cont2->setVisible(false);
							this->radius->cont3->setVisible(false);
						}
						else
						{
							this->radius->cont1->stop();
							this->radius->cont2->stop();
							this->radius->cont3->stop();
							this->radius->cont1->setVisible(true);
							if (this->getAllCount > 1)
							{
								this->radius->cont2->setVisible(true);
							}
							else
							{
								this->radius->cont2->setVisible(false);
							}
							if (this->getAllCount > 2)
							{
								this->radius->cont3->setVisible(true);
							}
							else
							{
								this->radius->cont3->setVisible(false);
							}
						}
					}
				}
				this->myRadius = 0;
				this->myDamage = 0;
				if (this->type == "holder")
				{
					if (this->fireCount > 0)
					{
						if (this->myRadius < Main::mainClass->readXMLClass.listOfMoveFireXML[0])
						{
							this->myRadius = Main::mainClass->readXMLClass.listOfMoveFireXML[0];
						}
						this->myDamage = this->myDamage + Main::mainClass->readXMLClass.listOfMoveFireXML[this->fireCount];
					}
					if (this->iceCount > 0)
					{
						if (this->myRadius < Main::mainClass->readXMLClass.listOfMoveIceXML[0])
						{
							this->myRadius = Main::mainClass->readXMLClass.listOfMoveIceXML[0];
						}
						this->myDamage = this->myDamage + Main::mainClass->readXMLClass.listOfMoveIceXML[this->iceCount];
					}
					if (this->stoneCount > 0)
					{
						if (this->myRadius < Main::mainClass->readXMLClass.listOfMoveStoneXML[0])
						{
							this->myRadius = Main::mainClass->readXMLClass.listOfMoveStoneXML[0];
						}
						this->myDamage = this->myDamage + Main::mainClass->readXMLClass.listOfMoveStoneXML[this->stoneCount];
					}
					if (this->levinCount > 0)
					{
						if (this->myRadius < Main::mainClass->readXMLClass.listOfMoveLevinXML[0])
						{
							this->myRadius = Main::mainClass->readXMLClass.listOfMoveLevinXML[0];
						}
						this->myDamage = this->myDamage + Main::mainClass->readXMLClass.listOfMoveLevinXML[this->levinCount];
					}
				}
				else if (this->type == "getAll")
				{
					if (this->myRadius < Main::mainClass->readXMLClass.listOfMoveFireXML[0])
					{
						this->myRadius = Main::mainClass->readXMLClass.listOfMoveFireXML[0];
					}
					if (this->myRadius < Main::mainClass->readXMLClass.listOfMoveIceXML[0])
					{
						this->myRadius = Main::mainClass->readXMLClass.listOfMoveIceXML[0];
					}
					if (this->myRadius < Main::mainClass->readXMLClass.listOfMoveStoneXML[0])
					{
						this->myRadius = Main::mainClass->readXMLClass.listOfMoveStoneXML[0];
					}
					if (this->myRadius < Main::mainClass->readXMLClass.listOfMoveLevinXML[0])
					{
						this->myRadius = Main::mainClass->readXMLClass.listOfMoveLevinXML[0];
					}
					if (this->getAllCount == 1)
					{
						this->myDamage = Main::mainClass->readXMLClass.getAllMultiply;
					}
					else if (this->getAllCount == 2)
					{
						this->myDamage = Main::mainClass->readXMLClass.getAllMultiply1;
					}
					else if (this->getAllCount == 3)
					{
						this->myDamage = Main::mainClass->readXMLClass.getAllMultiply2;
					}
				}
				this->radius->setHeight(this->myRadius * 2);
				this->radius->setWidth(this->myRadius * 2);
				this->radius->setVisible(false);
				this->arrow->setVisible(false);
				this->addChild(this->radius, 0);
			}
		}
		return;
	}// end function

	void GetSphere::retrieveGetSphere()
	{
		if (this->world->getSphere == this)
		{
			this->world->worldInterface->castRegime("off");
		}
		if (this->getAllCount == 0)
		{
			if (this->fireCount > 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount == 0)
			{
				this->removeChild(this->container);
				MoveFire_mc *container = new MoveFire_mc();
				this->container = container;
				container->stop();
				container->cont->stop();
				std::setText(container->numTXT, this->fireCount);
				//container->numTXT.text = this->fireCount;
				if (this->fireCount == 1)
				{
					container->numTXT->setVisible(false);
				}
				container->setScale(0.6f);
				this->addChild(this->container);
			}
			else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount == 0)
			{
				this->removeChild(this->container);
				MoveIce_mc *container = new MoveIce_mc();
				this->container = container;
				container->stop();
				container->cont->stop();
				std::setText(container->numTXT, this->iceCount);
				//container->numTXT.text = this->iceCount;
				if (this->iceCount == 1)
				{
					container->numTXT->setVisible(false);
				}
				container->setScale(0.6f);
				this->addChild(this->container);
			}
			else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount == 0)
			{
				this->removeChild(this->container);
				MoveStone_mc *container = new MoveStone_mc();
				this->container = container;
				container->stop();
				container->cont->stop();
				std::setText(container->numTXT, this->stoneCount);
				//container->numTXT.text = this->stoneCount;
				if (this->stoneCount == 1)
				{
					container->numTXT->setVisible(false);
				}
				container->setScale(0.6f);
				this->addChild(this->container);
			}
			else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount > 0)
			{
				this->removeChild(this->container);
				MoveLevin_mc *container = new MoveLevin_mc();
				this->container = container;
				container->stop();
				container->cont->stop();
				std::setText(container->numTXT, this->levinCount);
				//container->numTXT.text = this->levinCount;
				if (this->levinCount == 1)
				{
					container->numTXT->setVisible(false);
				}
				container->setScale(0.6f);
				this->addChild(this->container);
			}
			else if (this->ownerType == "archive")
			{
				if (this->fireCount > 0)
				{
					this->world->feature->getSphereBeat("fire", this->fireCount);
					this->world->getSphere->setPosition(this->getPosition());
					this->world->getSphere->retrieveGetSphere();
					this->fireCount = 0;
				}
				if (this->iceCount > 0)
				{
					this->world->feature->getSphereBeat("ice", this->iceCount);
					this->world->getSphere->setPosition(this->getPosition());
					this->world->getSphere->retrieveGetSphere();
					this->iceCount = 0;
				}
				if (this->stoneCount > 0)
				{
					this->world->feature->getSphereBeat("stone", this->stoneCount);
					this->world->getSphere->setPosition(this->getPosition());
					this->world->getSphere->retrieveGetSphere();
					this->stoneCount = 0;
				}
				if (this->stoneCount > 0)
				{
					this->world->feature->getSphereBeat("stone", this->stoneCount);
					this->world->getSphere->setPosition(this->getPosition());
					this->world->getSphere->retrieveGetSphere();
					this->stoneCount = 0;
				}
			}
		}
		this->speedFrame = 5;
		this->speedX = (this->ownerPoint.x - this->getPositionX()) / this->speedFrame;
		this->speedY = (this->ownerPoint.y - this->getPositionY()) / this->speedFrame;
		this->radius->setVisible(false);
		this->arrow->setVisible(false);
		this->world->getSphere = NULL;
		if (this->towerArrow)
		{
			this->towerArrow->myTower->removeChild(this->towerArrow);
			this->towerArrow = NULL;
		}
		if (this->ownerType == "archive")
		{
			//Sounds.instance.playSoundWithVol("snd_world_sphereGoToArchive", 0.9);
		}
		else
		{
			//Sounds.instance.playSound("snd_world_sphereMoveBack");
		}
		if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount == 0 && this->getAllCount == 0)
		{
			this->world->removeChild(this);
		}
		else
		{
			this->world->listOfMoveSpheres.push(this);
		}
		this->world->worldInterface->autoguidersButtons();
		return;
	}// end function

	void GetSphere::getSphereFromArchiveToTower()
	{
		if (this->world->towerMenu)
		{
			this->owner = this->world->towerMenu->myTower;
			this->ownerPoint = cocos2d::Point(this->world->towerMenu->myTower->getPositionX(), this->world->towerMenu->myTower->getPositionY() + this->world->towerMenu->myTower->correctYGrPos);
		}
		else if (this->world->ultraTowerMenu)
		{
			this->owner = this->world->ultraTowerMenu->myTower;
			this->ownerPoint = cocos2d::Point(this->world->ultraTowerMenu->myTower->getPositionX(), this->world->ultraTowerMenu->myTower->getPositionY() + this->world->ultraTowerMenu->myTower->correctYGrPos);
		}
		this->ownerType = "tower";
		if (this->fireCount > 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount == 0)
		{
			this->setPosition(this->world->worldInterface->container->fireSphere->getPositionX(), this->world->worldInterface->container->fireSphere->getPositionY());
		}
		else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount == 0)
		{
			this->setPosition(this->world->worldInterface->container->iceSphere->getPositionX(), this->world->worldInterface->container->iceSphere->getPositionY());
		}
		else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount == 0)
		{
			this->setPosition(this->world->worldInterface->container->stoneSphere->getPositionX(), this->world->worldInterface->container->stoneSphere->getPositionY());
		}
		else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount > 0)
		{
			this->setPosition(this->world->worldInterface->container->levinSphere->getPositionX(), this->world->worldInterface->container->levinSphere->getPositionY());
		}
		else
		{
			this->setPosition(this->world->worldInterface->container->getAll->getPositionX(), this->world->worldInterface->container->getAll->getPositionY());
		}
		this->retrieveGetSphere();
		this->world->worldInterface->updateInfo();
		return;
	}// end function
	void GetSphere::monitor()
	{
		if (this->listOfStack.size() < 4 && this->getAllCount == 0)
		{
			if (this->world->worldInterface->fireCount > 0 || this->world->money >= std::getInt(this->world->worldInterface->container->buyFireBuyTXT) && this->world->worldInterface->container->fireSphere->isVisible())
			{
				if (!this->world->worldInterface->castMask->fireCase->buttonMode)
				{
					this->world->worldInterface->castMask->fireCase->buttonMode = true;
				}
			}
			else if (this->world->worldInterface->castMask->fireCase->buttonMode)
			{
				this->world->worldInterface->castMask->fireCase->buttonMode = false;
			}
			if (this->world->worldInterface->iceCount > 0 || this->world->money >= std::getInt(this->world->worldInterface->container->buyIceBuyTXT) && this->world->worldInterface->container->iceSphere->isVisible())
			{
				if (!this->world->worldInterface->castMask->iceCase->buttonMode)
				{
					this->world->worldInterface->castMask->iceCase->buttonMode = true;
				}
			}
			else if (this->world->worldInterface->castMask->iceCase->buttonMode)
			{
				this->world->worldInterface->castMask->iceCase->buttonMode = false;
			}
			if (this->world->worldInterface->stoneCount > 0 || this->world->money >= std::getInt(this->world->worldInterface->container->buyStoneBuyTXT) && this->world->worldInterface->container->stoneSphere->isVisible())
			{
				if (!this->world->worldInterface->castMask->stoneCase->buttonMode)
				{
					this->world->worldInterface->castMask->stoneCase->buttonMode = true;
				}
			}
			else if (this->world->worldInterface->castMask->stoneCase->buttonMode)
			{
				this->world->worldInterface->castMask->stoneCase->buttonMode = false;
			}
			if (this->world->worldInterface->levinCount > 0 || this->world->money >= std::getInt(this->world->worldInterface->container->buyLevinBuyTXT) && this->world->worldInterface->container->levinSphere->isVisible())
			{
				if (!this->world->worldInterface->castMask->levinCase->buttonMode)
				{
					this->world->worldInterface->castMask->levinCase->buttonMode = true;
				}
			}
			else if (this->world->worldInterface->castMask->levinCase->buttonMode)
			{
				this->world->worldInterface->castMask->levinCase->buttonMode = false;
			}
		}
		else
		{
			if (this->world->worldInterface->castMask->fireCase->buttonMode)
			{
				this->world->worldInterface->castMask->fireCase->buttonMode = false;
			}
			if (this->world->worldInterface->castMask->iceCase->buttonMode)
			{
				this->world->worldInterface->castMask->iceCase->buttonMode = false;
			}
			if (this->world->worldInterface->castMask->stoneCase->buttonMode)
			{
				this->world->worldInterface->castMask->stoneCase->buttonMode = false;
			}
			if (this->world->worldInterface->castMask->levinCase->buttonMode)
			{
				this->world->worldInterface->castMask->levinCase->buttonMode = false;
			}
		}
		if (this->listOfStack.size() == 0)
		{
			if (this->getAllCount < 3)
			{
				if (!this->world->worldInterface->castMask->getAllCase->buttonMode)
				{
					this->world->worldInterface->castMask->getAllCase->buttonMode = true;
				}
			}
			else if (this->world->worldInterface->castMask->getAllCase->buttonMode)
			{
				this->world->worldInterface->castMask->getAllCase->buttonMode = false;
			}
		}
		else if (this->world->worldInterface->castMask->getAllCase->buttonMode)
		{
			this->world->worldInterface->castMask->getAllCase->buttonMode = false;
		}
		return;
	}// end function
	void GetSphere::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			this->world->worldInterface->castRegime("off");
			this->world->removeChild(this);
			this->world->getSphere = NULL;
			if (this->towerArrow)
			{
				this->towerArrow->myTower->removeChild(this->towerArrow);
				this->towerArrow = NULL;
			}
			this->world->worldInterface->castMask->fireCase->buttonMode = false;
			this->world->worldInterface->castMask->iceCase->buttonMode = false;
			this->world->worldInterface->castMask->stoneCase->buttonMode = false;
			this->world->worldInterface->castMask->levinCase->buttonMode = false;
			this->world->worldInterface->castMask->getAllCase->buttonMode = false;
			this->world->worldInterface->updateInfo();
		}
		return;
	}// end function
}

