#include "BuildTowerMenu.h"
#include "MainClass.h"
#include "engine/World.h"
namespace engine{
    namespace towers
    {

        BuildTowerMenu_mc::BuildTowerMenu_mc():MovieClip("tower","BuildTowerMenu_mc","BuildTowerMenu_mc")
        {
        }

        BuildTowerMenu_mc::~BuildTowerMenu_mc()
        {
        }
        bool BuildTowerMenu_mc::init(){
            Common::String placeName = "place";
            this->place = Sprite::create("public/BuildTowerMenu_mc.png");
            this->price = ui::Text::create();
            return true;
        };


        void BuildTowerMenu_mc::setPrice(int pr){
            char tmp[8];
            this->price->setText(itoa(pr, tmp, 10));
        };
        BuildTowerMenu::BuildTowerMenu(Sprite *  param1)
        {
            //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            this->myPlace = param1;
            return;
        }// end function

        bool BuildTowerMenu::init()
        {
            //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
            this->world = Main::mainClass->worldClass;
            std::setAnchorPoint(this, this->myPlace->getPosition());
            this->setPosition(this->myPlace->getPositionX() + this->myPlace->buildPoint->getPositionX()
                ,this->myPlace->getPositionY() + this->myPlace->buildPoint->getPositionY());
            //this->x = this->myPlace->x + this->myPlace->buildPoint->x;
            //this->y = this->myPlace->y + this->myPlace->buildPoint->y;
            this->myPlace->gotoAndStop(2);
            this->container = BuildTowerMenu_mc::create();
            this->container->setPrice(Main::mainClass->readXMLClass.costTowerXML);
            this->container->stop();
            this->container->cont->stop();
            std::setText(this->container->cont->costTXT, Main::mainClass->readXMLClass.costTowerXML);
            //this->container->cont->costTXT.text = Main::mainClass->readXMLClass.costTowerXML;
            this->container->contBuildTowerMenuCase->buttonMode = true;
            this->addChild(this->container);
            //this->world->listOfClasses.push(this);

            EventListenerMouse *mouseListener = cocos2d::EventListenerMouse::create();
            mouseListener->onMouseDown = CC_CALLBACK_1(BuildTowerMenu::mouseDownHandler, this);
            mouseListener->onMouseUp = CC_CALLBACK_1(BuildTowerMenu::mouseUpHandler, this);
            mouseListener->onMouseMove = CC_CALLBACK_1(BuildTowerMenu::mouseMoveHandler, this);
            this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
            this->monitor();
            return true;
        }// end function

        void BuildTowerMenu::update()
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
                    this->myPlace->buildPoint->stop();
                    this->myPlace->placeForBuildCase->buttonMode = true;
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
                    this->myPlace->buildPoint->stop();
                    this->myPlace->placeForBuildCase->buttonMode = true;
                    this->kill();
                }
            }
            return;
        }// end function
        void BuildTowerMenu::mouseMoveHandler(cocos2d::Event * event)
        {
            if (!this->closeFlag)
            {
                cocos2d::EventMouse*e = (cocos2d::EventMouse*)event;
                Node * node = event->getCurrentTarget();
                Event::Type tp = event->getType();
                string target = node->getName();
                CCLOG("BuildTowerMenu::mouseMoveHandler %s", target.c_str());

                cocos2d::Point pt = e->getLocationInView();
                CCLOG("mouse InView point %f,%f", pt.x, pt.y);

                if (BaseNode::hitTest(this->container->place, pt) || BaseNode::hitTest(this->myPlace, pt)){
                    //if (param1.target.name != "placeForBuildCase" && param1.target.name != "buildTowerMenuCase" 
                    //    && param1.target != this->myPlace && param1.target.parent != this)
                    //{
                    this->closeMenu();
                    //}
                }
            }
            return;
        }// end function
        void BuildTowerMenu::mouseDownHandler(cocos2d::Event * event)
        {
            if (!this->closeFlag)
            {
                cocos2d::EventMouse*e = (cocos2d::EventMouse*)event;
                Node * node = event->getCurrentTarget();
                Event::Type tp = event->getType();
                string target = node->getName();
                CCLOG("BuildTowerMenu::mouseMoveHandler %s", target.c_str());

                cocos2d::Point pt = e->getLocationInView();
                CCLOG("mouse InView point %f,%f", pt.x, pt.y);
                if (BaseNode::hitTest(this->container->place, pt) || BaseNode::hitTest(this->myPlace, pt)){
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
        void BuildTowerMenu::mouseUpHandler(cocos2d::Event * event)
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
                this->container->contBuildTowerMenuCase->buttonMode = true;
                this->myPlace->placeForBuildCase->buttonMode = true;
            }
            else
            {
                if (this->container->currentFrame < 8)
                {
                    this->container->gotoAndStop(this->container->currentFrame + 7);
                    this->container->cont->stop();
                }
                this->container->contBuildTowerMenuCase->buttonMode = false;
                this->myPlace->placeForBuildCase->buttonMode = false;
            }
            this->container->setPrice(Main::mainClass->readXMLClass.costTowerXML);
            std::setText(this->container->cont->costTXT, Main::mainClass->readXMLClass.costTowerXML);
            //this->container->cont->costTXT.text = Main::mainClass->readXMLClass.costTowerXML;
            return;
        }// end function
        void BuildTowerMenu::closeMenu()
        {
            this->closeFlag = true;
            this->mouseChildren = false;
            this->mouseEnabled = false;
            this->world->buildTowerMenu = NULL;
            return;
        }// end function

        void BuildTowerMenu::kill()
        {
            if (!this->dead)
            {
                this->dead = true;
                this->world->removeChild(this);
                this->i = 0;
                //while (this->i < this->world->listOfClasses.length)
                //{
                //    if (this->world->listOfClasses[this->i] == this)
                //    {
                //        this->world->listOfClasses.splice(this->i, 1);
                //        break;
                //    }
                //    i++;
                //}
            }
            return;
        }// end function

 }
}

