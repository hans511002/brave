#include "MainClass.h"
#include "engine/World.h"
#include "engine/towers/Exchange.h"
#include "engine/WorldInterface.h"
#include "engine/GetSphere.h"
#include "engine/towers/UltraTowerMenu.h"
#include "engine/towers/TowerMenu.h"

namespace engine
{
    namespace towers
    { 
        Exchange::Exchange(Tower * param1)
        {
			SET_NODETYPENAME();
			//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            this->myTower = param1; 
            this->myTower->setMouseChildren(false);
            this->myTower->setMouseEnabled(false);
            return;
        }// end function

        bool Exchange::init() 
        {
            //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
            //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
            this->world = Main::mainClass->worldClass;
            this->graphicAtMyTower = new Exchange_mc();
            this->graphicAtMyTower->stop();
            this->graphicAtMyTower->setPosition(this->myTower->getPosition()); 
            this->graphicAtMyTower->setMouseChildren(false);
            this->graphicAtMyTower->setMouseEnabled(false);
            this->world->addChild(this->graphicAtMyTower,4);
            this->container = new Exchange1_mc();
            this->container->stop();
            this->container->cross->stop();
            this->addChild(this->container);
            this->setPosition(this->world->mouseX,this->world->mouseY); 
            this->setMouseChildren(false);
            this->setMouseEnabled(false);
            if (this->world->towerMenu)
            {
                this->world->towerMenu->closeMenu();
            }
            else if (this->world->ultraTowerMenu)
            {
                this->world->ultraTowerMenu->closeMenu();
            }
            this->i = 0;
            while (this->i < this->world->listOfTowers.size())
            {
                if (this->world->listOfTowers[this->i]->towerType < 5)
                {
                    if (this->world->listOfTowers[this->i] != this->myTower && !this->world->listOfTowers[this->i]->blockTowerFlag)
                    {
                        if (this->myTower->spheresStack.size() > 0 || this->world->listOfTowers[this->i]->spheresStack.size() > 0)
                        {
                            this->world->listOfTowers[this->i]->exchangeFlag = true;
                            this->world->listOfTowers[this->i]->container->selectTower->setVisible(true);
                        }
                    }
                    else
                    {
                        this->myTower->container->selectTower->setVisible(false);
                    }
                }
                i++;
            }
            this->world->manageMouse("hide");
            return true;
        }// end function

        void Exchange::update(float dt) 
        {
            this->setPosition(this->world->mouseX,this->world->mouseY); 
            if (this->atTower)
            {
                if (this->container->currentFrame < this->container->totalFrames)
                {
                    this->container->tryPlay();
                    //this->container->gotoAndStop((this->container->currentFrame + 1));
                }
                else
                {
                    this->container->gotoAndStop(1);
                }
            }
            return;
        }// end function

        void Exchange::mouseMoveHandler(cocos2d::EventMouse * e) 
        {
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if(!event)
				return;
            string targetName = event->target->getName();
			if(targetName == "towerCase" && ISTYPE(EventNode, event->target)->mouseEnabled)
			//if (!std::hitTest(this->container->contBuildTowerMenuCase, pt) && !std::hitTest(this->myPlace->placeForBuildCase, pt))
			{
				Node * parent = event->target->getParent()->getParent()->getParent()->getParent();
				Tower * tower = ISTYPE(Tower, parent);
				if(tower->towerType < 5)
                {
					if(tower->container->selectTower->isVisible())
                    {
                        if (!this->atTower)
                        {
                            this->atTower = true;
                            this->container->cross->setVisible(false);
                        }
                    }
                    else if (this->atTower)
                    {
                        this->atTower = false;
                        this->container->cross->setVisible(true);
                    }
                }
                else if (this->atTower)
                {
                    this->atTower = false;
                    this->container->cross->setVisible(true);
                }
            }
            else if (this->atTower)
            {
                this->atTower = false;
                this->container->cross->setVisible(true);
            }
            return;
        }// end function

        void Exchange::mouseDownHandler(cocos2d::EventMouse * param1) 
        {
            this->kill();
            return;
        }// end function

        void Exchange::mouseUpHandler(cocos2d::EventMouse * param1) 
        {
            return;
        }// end function

        void Exchange::rightMouseDownHandler(cocos2d::EventMouse * e) 
        {
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if(!event)
				return;
            string targetName = event->target->getName();
            if(targetName == "towerCase" && ISTYPE(EventNode, event->target)->mouseEnabled)
            {
				Node * parent = event->target->getParent()->getParent()->getParent()->getParent();
				Tower * tower = ISTYPE(Tower, parent);
				if(tower->towerType < 5)
                {
                    this->i = 0;
                    while (this->i < this->world->listOfMoveSpheres.size())
                    {
                        if (this->world->listOfMoveSpheres[this->i]->speedFrame >= 0)
                        {
                            this->world->listOfMoveSpheres[this->i]->speedFrame = 0;
                        }
                        i++;
                    }
                    this->world->feature->listOfMoveSpheres();
                    if (this->myTower->spheresStack.size() > 0)
                    {
                        while (this->myTower->spheresStack.size() > 0)
                        {
                            if (this->myTower->spheresStack[0] == "fire")
                            {
                                this->myTower->towerGetSphereManage("get", "fire");
                                continue;
                            }
                            if (this->myTower->spheresStack[0] == "ice")
                            {
                                this->myTower->towerGetSphereManage("get", "ice");
                                continue;
                            }
                            if (this->myTower->spheresStack[0] == "stone")
                            {
                                this->myTower->towerGetSphereManage("get", "stone");
                                continue;
                            }
                            if (this->myTower->spheresStack[0] == "levin")
                            {
                                this->myTower->towerGetSphereManage("get", "levin");
                            }
                        }
                        this->world->getSphere->setPosition(this->myTower->this_pt);
                        //this->world->getSphere.x = this->myTower->this_pt.x;
                        //this->world->getSphere.y = this->myTower->this_pt.y;
                        this->world->getSphere->owner = tower;
                        this->world->getSphere->ownerType = "tower";
                        this->world->getSphere->ownerPoint = tower->this_pt;
                        this->world->getSphere->retrieveGetSphere();
                    }
                    if (tower->spheresStack.size() > 0)
                    {
                        while (tower->spheresStack.size()> 0)
                        {
                            if (tower->spheresStack[0] == "fire")
                            {
                                tower->towerGetSphereManage("get", "fire");
                                continue;
                            }
                            if (tower->spheresStack[0] == "ice")
                            {
                                tower->towerGetSphereManage("get", "ice");
                                continue;
                            }
                            if (tower->spheresStack[0] == "stone")
                            {
                                tower->towerGetSphereManage("get", "stone");
                                continue;
                            }
                            if (tower->spheresStack[0] == "levin")
                            {
                                tower->towerGetSphereManage("get", "levin");
                            }
                        }
                        this->world->getSphere->setPosition(tower->this_pt);
                        //this->world->getSphere.x = tower->this_pt.x;
                        //this->world->getSphere.y = tower->this_pt.y;
                        this->world->getSphere->owner = this->myTower;
                        this->world->getSphere->ownerType = "tower";
                        this->world->getSphere->ownerPoint = this->myTower->this_pt;
                        this->world->getSphere->retrieveGetSphere();
                    }
                }
            }
            this->kill();
            this->world->mouseMoveHandler(event);
            return;
        }// end function

        void Exchange::rightMouseUpHandler(cocos2d::EventMouse * param1) 
        {
            return;
        }// end function

        void Exchange::kill()  
        {
            if (!this->dead)
            {
                this->dead = true; 
                this->myTower->setMouseChildren(true);
                this->myTower->setMouseEnabled(true);
                this->i = 0;
                while (this->i < this->world->listOfTowers.size())
                { 
                    if (this->world->listOfTowers[this->i]->towerType < 5)
                    {
                        if (this->world->listOfTowers[this->i] != this->myTower)
                        {
                            this->world->listOfTowers[this->i]->exchangeFlag = false;
                            this->world->listOfTowers[this->i]->container->selectTower->setVisible(false);
                        }
                    }
                    i++;
                }
                this->world->removeChild(this->graphicAtMyTower);
                this->graphicAtMyTower = NULL;
                this->world->removeChild(this->world->exchange);
                this->world->exchange = NULL;
                this->world->manageMouse("show");
            }
            return;
        }// end function
    }
}
 
