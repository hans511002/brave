#include "MainClass.h"
#include "engine/World.h"
#include "engine/WorldInterface.h"
#include "engine/towers/BuildTowerMenu.h"

namespace engine{
    namespace towers
    {

		BuildTowerMenu_mc::BuildTowerMenu_mc() :MovieClip("tower", "BuildTowerMenu_mc", "BuildTowerMenu_mc")
		{
			cont = this->createMovieClipSub("cont");
			contBuildTowerMenuCase = cont->createCase("buildTowerMenuCase");
			contCostTXT = cont->createText("costTXT");
		}
   
		BuildTowerMenu::BuildTowerMenu(BuildTowerPlace *  param1) :world(NULL), dead(false), closeFlag(false), tempObject(NULL), myPlace(NULL)
        {
            //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            this->myPlace = param1;
			init();
            return;
        }// end function

		bool BuildTowerMenu::init()
		{
			BaseNode::init();
			//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
			this->world = Main::mainClass->worldClass;
			std::setAnchorPoint(this);
			Vec2 pos = this->myPlace->getPosition();
			pos = this->myPlace->convertToWorldSpace(Vec2(0,0));
			pos = this->world->convertToNodeSpaceAR(pos);
			Vec2 bpos = this->myPlace->buildPoint->getPosition();
			this->setPosition(pos + bpos);
			//this->x = this->myPlace->x + this->myPlace->buildPoint->x;
			//this->y = this->myPlace->y + this->myPlace->buildPoint->y;
			this->myPlace->gotoAndStop(2);
			this->container = new BuildTowerMenu_mc();
			this->container->stop();
			this->container->cont->stop();
			std::setText(this->container->contCostTXT, Main::mainClass->readXMLClass.costTowerXML);
			//this->container->cont->costTXT.text = Main::mainClass->readXMLClass.costTowerXML;
			this->container->contBuildTowerMenuCase->setMouseEnabled(true);
			this->addChild(this->container);
			this->world->listOfClasses.push(this);

			//EventListenerMouse *mouseListener = cocos2d::EventListenerMouse::create();
			//mouseListener->onMouseDown = CC_CALLBACK_1(BuildTowerMenu::mouseDownHandler, this);
			//mouseListener->onMouseUp = CC_CALLBACK_1(BuildTowerMenu::mouseUpHandler, this);
			//mouseListener->onMouseMove = CC_CALLBACK_1(BuildTowerMenu::mouseMoveHandler, this);
			//this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
			this->monitor();
			return true;
		}

        void BuildTowerMenu::update(float dt)
        {
            if (!this->closeFlag)
            {
                if (this->container->currentFrame < 8)
                {
                    if (this->container->currentFrame < 7)
                    {
                        this->container->gotoAndStop((this->container->currentFrame + 1));
                    }
                }
                else if (this->container->currentFrame > 7)
                {
                    if (this->container->currentFrame < this->container->totalFrames)
                    {
                        this->container->gotoAndStop((this->container->currentFrame + 1));
                    }
                }
            }
            else if (this->container->currentFrame < 8)
            {
                if (this->container->currentFrame > 1)
                {
                    this->container->gotoAndStop((this->container->currentFrame - 1));
                }
                else
                {
                    this->myPlace->gotoAndStop(1);
                    //this->myPlace->buildPoint->stop();
                    this->myPlace->placeForBuildCase->setMouseEnabled(true);
                    this->kill();
                }
            }
            else if (this->container->currentFrame > 7)
            {
                if (this->container->currentFrame > 8)
                {
                    this->container->gotoAndStop((this->container->currentFrame - 1));
                }
                else
                {
                    this->myPlace->gotoAndStop(1);
                    //this->myPlace->buildPoint->stop();
                    this->myPlace->placeForBuildCase->setMouseEnabled(true);
                    this->kill();
                }
            }
            return;
        }// end function
		void BuildTowerMenu::mouseMoveHandler(cocos2d::EventMouse * e)
		{
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if (!event)
				return;
			if (!this->closeFlag)
			{
                string target = event->target->getName();
				Vec2 pt=e->getLocationInView();
				if (target != "placeForBuildCase" &&  target != "buildTowerMenuCase" &&  !std::hitTest(this->myPlace, pt))
                //logInfo(getNamePath( event->target) , event->getLocationInView());
				//if (!std::hitTest(this->container->contBuildTowerMenuCase, pt) && !std::hitTest(this->myPlace->placeForBuildCase, pt))
					this->closeMenu();
				//if (event->target->getName() != "placeForBuildCase" && event->target->getName() != "buildTowerMenuCase" && param1.target != this->myPlace && param1.target.parent != this)
				//{
				// this->closeMenu();
				//}
			}
			return;
		}
        void BuildTowerMenu::mouseDownHandler(cocos2d::EventMouse * e)
        {
			std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
			if (!event)
				return;
            if (!this->closeFlag)
            {
                string target = event->target->getName();
                cocos2d::Point pt = e->getLocationInView();
                 if(target == "placeForBuildCase" ||  target == "buildTowerMenuCase" ||  !std::hitTest(this->myPlace, pt))
				//if (event.target.name == "placeForBuildCase" || event.target.name == "buildTowerMenuCase")
				//if (target != "placeForBuildCase" ||  target != "buildTowerMenuCase" || std::hitTest(this->myPlace, pt))
				//if (std::hitTest(this->container->contBuildTowerMenuCase, pt) || std::hitTest(this->myPlace->placeForBuildCase, pt))
				{
                    this->world->money = this->world->money - Main::mainClass->readXMLClass.costTowerXML;
                    this->world->worldInterface->updateInfo();
                    Main::mainClass->readXMLClass.costTowerXML = Main::mainClass->readXMLClass.costTowerXML + Main::mainClass->readXMLClass.costTowerPlusXML;
                    this->tempObject = this->world->addTower("tower1", this->myPlace);
                    this->kill();
                    this->world->buildTowerMenu = NULL;
                }
            }
            return;
        }// end function
        void BuildTowerMenu::mouseUpHandler(cocos2d::EventMouse * event)
        {
            return;
        }// end function

        void BuildTowerMenu::monitor()
        {
            if (this->world->money >= Main::mainClass->readXMLClass.costTowerXML)
            {
                if (this->container->currentFrame > 7)
                {
                    this->container->gotoAndStop(this->container->currentFrame - 7);
                    this->container->cont->stop();
                }
                this->container->contBuildTowerMenuCase->setMouseEnabled(true);
                this->myPlace->placeForBuildCase->setMouseEnabled(true);
            }
            else
            {
                if (this->container->currentFrame < 8)
                {
                    this->container->gotoAndStop(this->container->currentFrame + 7);
                    this->container->cont->stop();
                }
                this->container->contBuildTowerMenuCase->setMouseEnabled(false);
                this->myPlace->placeForBuildCase->setMouseEnabled(false);
            }
            std::setText(this->container->contCostTXT, Main::mainClass->readXMLClass.costTowerXML);
            //this->container->cont->costTXT.text = Main::mainClass->readXMLClass.costTowerXML;
            return;
        }// end function
        void BuildTowerMenu::closeMenu()
        {
            this->closeFlag = true;
            this->setMouseChildren(false);
            this->setMouseEnabled(false);
            this->world->buildTowerMenu = NULL;
			//kill();
            return;
        }// end function

        void BuildTowerMenu::kill()
        {
            if (!this->dead)
            {
                this->dead = true;
                this->world->removeClasses(this);
                this->world->removeChild(this);
            }
            return;
        }// end function

 }
}

