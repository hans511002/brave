 
#include "GetSphere.h"
#include "engine/World.h"

namespace engine
{
	GetSphere_mc::GetSphere_mc()
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
    GetSphere::GetSphere(string param1 ) :counter(0), myRadius(0), myDamage(0), fireCount(0), iceCount(0), stoneCount(0), levinCount(0)
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
		if(this->type == "holder")
		{
			this->container = new GetSphere_mc();
			this->container->stop();
			this->container->cont->stop();
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
		else if(this->type == "getAll")
		{
			GetAll_mc * container = new GetAll_mc();
			this->container = container;
			this->container->stop();
			this->container->cross->stop();
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
		if(this->world->towerMenu)
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
    			if(this->world->towerMenu->container->btnTowerUpgr3)
    		    {
    				this->world->towerMenu->container->btnTowerUpgr3BtnTowerUpgrCase->buttonMode = false;
    		    }
    			if(this->world->towerMenu->container->btnTowerUpgr4)
    			{
				this->world->towerMenu->container->btnTowerUpgr4BtnTowerUpgrCase->buttonMode = false;
	            }
	        }
		}
		else if(this->world->ultraTowerMenu)
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
		return;
	}// end function
    void  GetSphere::update() 
    {
        if (this->type == "holder")
        {
			if(dynamic_cast<GetSphere_mc*>(this->container))
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
					if(container->sphere2->currentFrame < container->sphere2->totalFrames)
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
					if(container->sphere3->currentFrame < container->sphere3->totalFrames)
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
					if(container->sphere4->currentFrame < container->sphere4->totalFrames)
                    {
						container->sphere4->gotoAndStop((container->sphere4->currentFrame + 1));
                    }
                    else
                    {
						container->sphere4->gotoAndStop(1);
                    }
                }
            }
            else if (container->cont->currentFrame < this->container->cont.totalFrames)
            {
                this->container->cont->gotoAndStop((this->container->cont->currentFrame + 1));
            }
            else
            {
                this->container->cont->gotoAndStop(1);
            }
        }
        else if (this->type == "getAll")
        {
            if (this->container->currentFrame < this->container->totalFrames)
            {
                this->container->gotoAndStop((this->container->currentFrame + 1));
            }
            else
            {
                this->container->gotoAndStop(1);
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
				this->container->setOpacity(this->container->getOpacity() *(1+ 0.1) );
            }
            else
            {
                this->removeChild(this->containerChange);
                this->containerChange = NULL;
                this->container->setOpacity(255);
            }
        }
        if (this->world->getSphere == this)
        {
            this->world->feature->scanPointersAtCast();
            this->setPosition(this->world->mouseX,this->world->mouseY);
            if (this->radius->isVisible())
            {
                if (this->radius->currentFrame == 1)
                {
                    //this->radius->rotation++;
                }
				if(this->radius->container->currentFrame < this->radius->cont.totalFrames)
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
    void  GetSphere::mouseMoveHandler(cocos2d::Event* param1)
    {
        if (param1->target->name == "fireCase")
        {
            if (param1->target->buttonMode && this->world->worldInterface->container->fireBack->currentFrame == 1)
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
        if (param1->target->name == "iceCase")
        {
            if (param1->target->buttonMode && this->world->worldInterface->container->iceBack->currentFrame == 1)
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
        if (param1->target->name == "stoneCase")
        {
            if (param1->target->buttonMode && this->world->worldInterface->container->stoneBack->currentFrame == 1)
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
        if (param1->target->name == "levinCase")
        {
            if (param1->target->buttonMode && this->world->worldInterface->container->levinBack->currentFrame == 1)
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
        if (param1->target->name == "getAllCase")
        {
            if (param1->target->buttonMode && this->world->worldInterface->container->getAll->currentFrame == 1)
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
        if (param1->target->name == "fireCase" || param1->target->name == "iceCase" || param1->target->name == "stoneCase"
             || param1->target->name == "levinCase" || param1->target->name == "getAllCase" || param1->target->name == "archiveCase" 
             || param1->target->name == "interfaceUpCase" || param1->target->name == "sellCase" || param1->target->name == "towerCase")
        {
            if (this->radius->isVisible())
            {
                this->radius->setVisible(false);
                this->arrow->setVisible(false);
            }
            if (param1->target->name == "towerCase")
            {
                if (this->type == "holder")
                {
                    if (param1->target->buttonMode && param1->target->parent->parent->spheresManage("scan") > 0)
                    {
                        if (!this->towerArrow)
                        {
                            this->towerArrow = new Arrow_mc();
                            this->towerArrow->stop();
                            this->towerArrow->myTower = param1->target->parent->parent;
                            this->towerArrow->mouseChildren = false;
                            this->towerArrow->mouseEnabled = false;
                            this->towerArrow->myTower->addChild(this->towerArrow);
                        }
                        if (this->container->currentFrame == 2)
                        {
                            this->container->gotoAndStop(1);
                        }
                    }
                    else
                    {
                        if (this->towerArrow)
                        {
                            this->towerArrow->myTower->removeChild(this->towerArrow);
                            this->towerArrow = NULL;
                        }
                        if (this->container->currentFrame == 1)
                        {
                            this->container->gotoAndStop(2);
                        }
                    }
                }
                else if (this->type == "getAll")
                {
                    if (param1->target->buttonMode && param1->target->parent->parent->spheresManage("scan") == 4)
                    {
                        if (!this->towerArrow)
                        {
                            this->towerArrow = new Arrow_mc();
                            this->towerArrow->stop();
                            this->towerArrow->myTower = param1->target->parent->parent; 
                            this->towerArrow->mouseChildren = false;
                            this->towerArrow->mouseEnabled = false;
                            this->towerArrow->myTower->addChild(this->towerArrow);
                        }
                        if (this->container->cross->isVisible())
                        {
                            this->container->cross->setVisible(false);
                        }
                    }
                    else
                    {
                        if (this->towerArrow)
                        {
                            this->towerArrow->myTower->removeChild(this->towerArrow);
                            this->towerArrow = NULL;
                        }
                        if (this->container->cross->isVisible())
                        {
                            this->container->cross->setVisible(true);
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
                if (this->container->currentFrame == 2)
                {
                    this->container->gotoAndStop(1);
                }
            }
            else if (this->type == "getAll")
            {
                if (this->container->cross->isVisible())
                {
                    this->container->cross->setVisible(false);
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
                if (this->world->towerMenu)
                {
                    this->tempObject = this->world->towerMenu;
                }
                else if (this->world->ultraTowerMenu)
                {
                    this->tempObject = this->world->ultraTowerMenu;
                }
                if (!this->radius->isVisible() && tempObject->myTower->this_pt.distance(cocos2d::Point(this->world->mouseX, this->world->mouseY)) > 86)
                {
                    this->radius->setVisible(true);
                    this->arrow->setVisible(true);
                    this->tempObject->closeMenu();
                }
            }
            if (param1->target->name == "road")
            {
                if (this->radius->currentFrame == 2)
                {
                    this->radius->gotoAndStop(1);
                    this->arrow->alpha = 0;
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
			else if(this->radius->currentFrame == 1)
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
        if (param1->target->name == "sphereSlotCase")
        {
            if (this->world->towerMenu)
            {
                this->world->towerMenu->mouseMoveHandler(param1);
            }
            else if (this->world->ultraTowerMenu)
            {
                this->world->ultraTowerMenu->mouseMoveHandler(param1);
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
			if(this->world->ultraTowerMenu->container->sphereSlot1->currentFrame == 2)
            {
				this->world->ultraTowerMenu->container->sphereSlot1->gotoAndStop(1);
            }
			if(this->world->ultraTowerMenu->container->sphereSlot2->currentFrame == 2)
            {
				this->world->ultraTowerMenu->container->sphereSlot2->gotoAndStop(1);
            }
        }
        if (param1->target->name == "sellCase")
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

    void GetSphere::mouseDownHandler(cocos2d::Event* param1)
    {
        if (param1->target->name == "sellCase")
        {
            this->world->worldInterface->container->sell->gotoAndStop(1);
            while (this->fireCount > 0)
            { 
                this->fireCount --;
                this->world->worldInterface->sellSphere("fire");
            }
            while (this->iceCount > 0)
            { 
                this->iceCount --;
                this->world->worldInterface->sellSphere("ice");
            }
            while (this->stoneCount > 0)
            {
                
                this->stoneCount --;
                this->world->worldInterface->sellSphere("stone");
            }
            while (this->levinCount > 0)
            {
                
                this->levinCount --;
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
        else if (param1->target->name == "towerCase" && param1->target->buttonMode)
        {
            this->tempObject = param1->target->parent->parent;
            if (this->type == "holder")
            {
                container->sphere1->setVisible(false);
                container->sphere2->setVisible(false);
                container->sphere3->setVisible(false);
                container->sphere4->setVisible(false);
                this->i = 0;
                while (this->i < this->listOfStack.size())
                {
                    if (this->listOfStack[this->i] == "fire")
                    {
                        this->tempObject1 = this->tempObject->spheresManage("push", "fire", 1);
                        if (this->tempObject1 == 0)
                        {
                            this->fireCount--;
                            this->listOfStack[this->i] = "none";
                        }
                    }
                    else if (this->listOfStack[this->i] == "ice")
                    {
                        this->tempObject1 = this->tempObject->spheresManage("push", "ice", 1);
                        if (this->tempObject1 == 0)
                        {
                            this->iceCount--;
                            this->listOfStack[this->i] = "none";
                        }
                    }
                    else if (this->listOfStack[this->i] == "stone")
                    {
                        this->tempObject1 = this->tempObject->spheresManage("push", "stone", 1);
                        if (this->tempObject1 == 0)
                        {
                            this->stoneCount--;
                            this->listOfStack[this->i] = "none";
                        }
                    }
                    else if (this->listOfStack[this->i] == "levin")
                    {
                        this->tempObject1 = this->tempObject->spheresManage("push", "levin", 1);
                        if (this->tempObject1 == 0)
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
                this->getAllCount --;
                this->tempObject1 = this->tempObject->spheresManage("push", "getAll", 1);
                this->getAllCount = this->getAllCount + this->tempObject1;
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
        else if (param1->target->name == "fireCase")
        {
            if (param1->target->buttonMode)
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
        else if (param1->target->name == "iceCase")
        {
            if (param1->target->buttonMode)
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
        else if (param1->target->name == "stoneCase")
        {
            if (param1->target->buttonMode)
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
        else if (param1->target->name == "levinCase")
        {
            if (param1->target->buttonMode)
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
        else if (param1->target->name == "getAllCase")
        {
            if (param1->target->buttonMode)
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
        else if (param1->target->name == "sphereSlotCase")
        {
            if (param1->target->parent->currentFrame == 2)
            {
                if (this->listOfStack.size() < 4)
                {
                    if (this->world->towerMenu)
                    {
                        this->tempObject = this->world->towerMenu;
                    }
                    else if (this->world->ultraTowerMenu)
                    {
                        this->tempObject = this->world->ultraTowerMenu;
                    }
                    if (param1->target->parent->sphereAnima->isVisible())
                    {
                        if (param1->target->parent->sphereAnima->isVisible())
                        {
                            if (param1->target->parent->sphereAnima->currentFrame == 1)
                            {
                                this->tempObject->myTower->towerGetSphereManage("get", "fire");
                                if (!this->world->ultraTowerMenu)
                                {
                                    this->tempObject->spheresMonitor();
                                }
                            }
                            else if (param1->target->parent->sphereAnima->currentFrame == 2)
                            {
                                this->tempObject->myTower->towerGetSphereManage("get", "ice");
                                if (!this->world->ultraTowerMenu)
                                {
                                    this->tempObject->spheresMonitor();
                                }
                            }
                            else if (param1->target->parent->sphereAnima->currentFrame == 3)
                            {
                                this->tempObject->myTower->towerGetSphereManage("get", "stone");
                                if (!this->world->ultraTowerMenu)
                                {
                                    this->tempObject->spheresMonitor();
                                }
                            }
                            else if (param1->target->parent->sphereAnima->currentFrame == 4)
                            {
                                this->tempObject->myTower->towerGetSphereManage("get", "levin");
                                if (!this->world->ultraTowerMenu)
                                {
                                    this->tempObject->spheresMonitor();
                                }
                            }
                        }
                    }
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (param1->target->parent->currentFrame == 1)
            {
                this->getSphereFromArchiveToTower();
                this->speedFrame = 0;
            }
        }
        else if (param1->target->name != "archiveCase" && param1->target->name != "getAllCase")
        {
            if (this->radius->currentFrame == 1)
            {
                this->tempObject = new CastSphere();
                this->world->addChild(this->tempObject);
                this->kill();
            }
            else if (param1->target is TowerMenu_mc || param1->target->parent is TowerMenu_mc || param1->target->parent.parent is TowerMenu_mc 
                || param1->target is UltraTowerMenu_mc || param1->target->parent is UltraTowerMenu_mc 
                || param1->target->parent.parent is UltraTowerMenu_mc)
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
    void GetSphere::mouseUpHandler(cocos2d::Event* param1)
    {
        return;
    }// end function
    
    void GetSphere::retrieveGetSphereToArchive() 
    {
        this->ownerType = "archive";
        if (this->fireCount > 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount == 0)
        {
            this->owner = this->world->worldInterface->container->fireSphere;
            this->ownerPoint = this->world->worldInterface->container->fireSphere->myPoint;
        }
        else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount == 0)
        {
            this->owner = this->world->worldInterface->container->iceSphere;
            this->ownerPoint = this->world->worldInterface->container->iceSphere->myPoint;
        }
        else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount == 0)
        {
            this->owner = this->world->worldInterface->container->stoneSphere;
			this->ownerPoint = this->world->worldInterface->container->stoneSphere->myPoint;
        }
        else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount > 0)
        {
            this->owner = this->world->worldInterface->container->levinSphere;
			this->ownerPoint = this->world->worldInterface->container->levinSphere->myPoint;
        }
        else
        {
            this->owner = this->world->worldInterface->container->getAll;
			this->ownerPoint = this->world->worldInterface->container->getAll->myPoint;
        }
        this->retrieveGetSphere();
        return;
    }// end function
     void GetSphere::manage(string param1, string param2  ) 
    {
        if (param1 == "add")
        {
            if (this->type == "holder")
            {
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
                        this->container->stop();
                        this->container->cross->stop();
                        std::setText(this->container->numTXT , this->getAllCount);
                        //this->container->numTXT.text = this->getAllCount;
                        this->container->cross->setVisible(false);
                        this->container->alpha = 0;
                        this->addChild(this->container);
                    }
                }
            }
            else if (this->type == "getAll")
            {
                if (this->getAllCount < 3)
                {
                    (this->getAllCount + 1);
                    this->container->numTXT.text = this->getAllCount;
                }
            }
            if (this->fireCount > 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount == 0)
            {
                if (this->radius && !(this->radius is RadiusFire_mc))
                {
                    this->removeChild(this->radius);
                    this->radius = NULL;
                }
                if (!this->radius)
                {
                    this->radius = new RadiusFire_mc();
                    this->radius->gotoAndStop(2);
                    this->arrow->alpha = 1;
                    this->radius->cont->stop(); 
                    this->radius->height = Main::mainClass->readXMLClass.listOfMoveFireXML[0] * 2;
                    this->radius->width = Main::mainClass->readXMLClass.listOfMoveFireXML[0] * 2;
                    this->radius->setVisible(false);
                    this->arrow->setVisible(false);
                    this->addChildAt(this->radius, 0);
                }
                this->myRadius = Main::mainClass->readXMLClass.listOfMoveFireXML[0];
                this->myDamage = Main::mainClass->readXMLClass.listOfMoveFireXML[this->fireCount];
            }
            else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount == 0)
            {
                if (this->radius && !(this->radius is RadiusIce_mc))
                {
                    this->removeChild(this->radius);
                    this->radius = NULL;
                }
                if (!this->radius)
                {
                    this->radius = new RadiusIce_mc();
                    this->radius->gotoAndStop(2);
                    this->arrow->alpha = 1;
                    this->radius->cont->stop(); 
                    this->radius->height = Main::mainClass->readXMLClass.listOfMoveIceXML[0] * 2;
                    this->radius->width = Main::mainClass->readXMLClass.listOfMoveIceXML[0] * 2;
                    this->radius->setVisible(false);
                    this->arrow->setVisible(false);
                    this->addChildAt(this->radius, 0);
                }
                this->myRadius = Main::mainClass->readXMLClass.listOfMoveIceXML[0];
                this->myDamage = Main::mainClass->readXMLClass.listOfMoveIceXML[this->iceCount];
            }
            else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount == 0)
            {
                if (this->radius && !(this->radius is RadiusStone_mc))
                {
                    this->removeChild(this->radius);
                    this->radius = null;
                }
                if (!this->radius)
                {
                    this->radius = new RadiusStone_mc();
                    this->radius->gotoAndStop(2);
                    this->arrow->alpha = 1;
                    this->radius->cont->stop(); 
                    this->radius->height = Main::mainClass->readXMLClass.listOfMoveStoneXML[0] * 2;
                    this->radius->width = Main::mainClass->readXMLClass.listOfMoveStoneXML[0] * 2;
                    this->radius->setVisible(false);
                    this->arrow->setVisible(false);
                    this->addChildAt(this->radius, 0);
                }
                this->myRadius = Main::mainClass->readXMLClass.listOfMoveStoneXML[0];
                this->myDamage = Main::mainClass->readXMLClass.listOfMoveStoneXML[this->stoneCount];
            }
            else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount > 0)
            {
                if (this->radius && !(this->radius is RadiusLevin_mc))
                {
                    this->removeChild(this->radius);
                    this->radius = null;
                }
                if (!this->radius)
                {
                    this->radius = new RadiusLevin_mc();
                    this->radius->gotoAndStop(2);
                    this->arrow->alpha = 1;
                    this->radius->cont->stop(); 
                    this->radius->height = Main::mainClass->readXMLClass.listOfMoveLevinXML[0] * 2;
                    this->radius->width = Main::mainClass->readXMLClass.listOfMoveLevinXML[0] * 2;
                    this->radius->setVisible(false);
                    this->arrow->setVisible(false);
                    this->addChildAt(this->radius, 0);
                }
                this->myRadius = Main::mainClass->readXMLClass.listOfMoveLevinXML[0];
                this->myDamage = Main::mainClass->readXMLClass.listOfMoveLevinXML[this->levinCount];
            }
            else
            {
                if (this->radius)
                {
                    this->removeChild(this->radius);
                    this->radius = null;
                }
                if (!this->radius)
                {
                    this->radius = new RadiusGetAll_mc();
                    this->radius->gotoAndStop(2);
                    this->arrow->alpha = 1;
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
                this->radius->height = this->myRadius * 2;
                this->radius->width = this->myRadius * 2;
                this->radius->setVisible(false);
                this->arrow->setVisible(false);
                this->addChildAt(this->radius, 0);
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
                this->container = new MoveFire_mc();
                this->container->stop();
                this->container->cont->stop();
                std::setText(this->container->numTXT, this->fireCount);
                //this->container->numTXT.text = this->fireCount;
                if (this->fireCount == 1)
                {
                    this->container->numTXT->setVisible(false);
                }
                this->container->setScale(0.6);
                this->addChild(this->container);
            }
            else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount == 0)
            {
                this->removeChild(this->container);
                this->container = new MoveIce_mc();
                this->container->stop();
                this->container->cont->stop();
                std::setText(this->container->numTXT, this->iceCount);
                //this->container->numTXT.text = this->iceCount;
                if (this->iceCount == 1)
                {
                    this->container->numTXT->setVisible(false);
                }
                this->container->setScale(0.6);
                this->addChild(this->container);
            }
            else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount == 0)
            {
                this->removeChild(this->container);
                this->container = new MoveStone_mc();
                this->container->stop();
                this->container->cont->stop();
                std::setText(this->container->numTXT, this->stoneCount);
                //this->container->numTXT.text = this->stoneCount;
                if (this->stoneCount == 1)
                {
                    this->container->numTXT->setVisible(false);
                }
                this->container->setScale(0.6);
                this->addChild(this->container);
            }
            else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount > 0)
            {
                this->removeChild(this->container);
                this->container = new MoveLevin_mc();
                this->container->stop();
                this->container->cont->stop();
                std::setText(this->container->numTXT, this->levinCount);
                //this->container->numTXT.text = this->levinCount;
                if (this->levinCount == 1)
                {
                    this->container->numTXT->setVisible(false);
                }
                this->container->setScale(0.6);
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
            this->ownerPoint = new Point(this->world->towerMenu->myTower->getPositionX(), this->world->towerMenu->myTower->getPositionY() + this->world->towerMenu->myTower->correctYGrPos);
        }
        else if (this->world->ultraTowerMenu)
        {
            this->owner = this->world->ultraTowerMenu->myTower;
            this->ownerPoint = new Point(this->world->ultraTowerMenu->myTower->getPositionX(), this->world->ultraTowerMenu->myTower->getPositionY() + this->world->ultraTowerMenu->myTower->correctYGrPos);
        }
        this->ownerType = "tower";
        if (this->fireCount > 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount == 0)
        {
            this->setPosition(this->world->worldInterface->container->fireSphere->getPositionX(),this->world->worldInterface->container->fireSphere->getPositionY());
        }
        else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount == 0)
        {
            this->setPosition(this->world->worldInterface->container->iceSphere->getPositionX(),this->world->worldInterface->container->iceSphere->getPositionY());
        }
        else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount == 0)
        {
            this->setPosition(this->world->worldInterface->container->stoneSphere->getPositionX(),this->world->worldInterface->container->stoneSphere->getPositionY());
        }
        else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount > 0)
        {
            this->setPosition(this->world->worldInterface->container->levinSphere->getPositionX(),this->world->worldInterface->container->levinSphere->getPositionY());
        }
        else
        {
            this->setPosition(this->world->worldInterface->container->getAll->getPositionX(),this->world->worldInterface->container->getAll->getPositionY());
        }
        this->retrieveGetSphere();
        this->world->worldInterface->updateInfo();
        return;
    }// end function
    void GetSphere::monitor()
    {
        if (this->listOfStack.size() < 4 && this->getAllCount == 0)
        {
            if (this->world->worldInterface->fireCount > 0 || this->world->money >= std::getInt(this->world->worldInterface->container->buyFire->buyTXT) && this->world->worldInterface->container->fireSphere->isVisible())
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
            if (this->world->worldInterface->iceCount > 0 || this->world->money >= std::getInt(this->world->worldInterface->container->buyIce->buyTXT) && this->world->worldInterface->container->iceSphere->isVisible())
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
            if (this->world->worldInterface->stoneCount > 0 || this->world->money >= std::getInt(this->world->worldInterface->container->buyStone->buyTXT) && this->world->worldInterface->container->stoneSphere->isVisible())
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
            if (this->world->worldInterface->levinCount > 0 || this->world->money >= std::getInt(this->world->worldInterface->container->buyLevin->buyTXT) && this->world->worldInterface->container->levinSphere->isVisible())
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

