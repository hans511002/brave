#include "Golem.h"
#include "engine/world.h"

namespace engine{
    namespace    casts
    {
        Golem::Golem(cocos2d::Point param1, int param2, int param3, bool param4 = true) :direction("none"), voiceCounter(10), cameraJitterTimer(3), movePhase(1)
        {
            this->cameraJitterCounter = this->cameraJitterTimer;
            this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            this->this_pt = param1;
            this->road = param2;
            this->movePhase = param3;
            this->openFlag = param4;
            return;
        }// end function

        bool Golem::init() 
        {
            //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
            this->world = Main::mainClass->worldClass;
            if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem4"))// gameSave.data.upgradeGolem4)
            {
                this->container = new Golem3_mc();
            }
            else if (Main::mainClass->saveBoxClass->getBoolValue("upgradeGolem2"))
                //(Main::mainClass->saveBoxClass.gameSave.data.upgradeGolem2)
            {
                this->container = new Golem2_mc();
            }
            else
            {
                this->container = new Golem1_mc();
            }
            //this->container->gotoAndStop(57);
            //this->container->dust1.stop();
            //this->container->dust2.stop();
            //this->container->dust1->setVisible(false);
            //this->container->dust2->setVisible(false);
            this->addChild(this->container);
            this->speedKSave = Main::mainClass->readXMLClass.castGolemSpeedXML;
            this->speedK = Main::mainClass->readXMLClass.castGolemSpeedXML;
            this->radius = 50; 
            this->healthSave = Main::mainClass->readXMLClass.castGolemHealthXML;
            this->health = Main::mainClass->readXMLClass.castGolemHealthXML;
            if (this->road == 1)
            {
                this->roadMap = &this->world->map.road1;
            }
            else if (this->road == 2)
            {
                this->roadMap = &this->world->map.road2;
            }
            else if (this->road == 3)
            {
                this->roadMap = &this->world->map.road3;
            }
            Common::Array<cocos2d::Point> &roadMap = *this->roadMap;

            if (roadMap[this->movePhase].x != roadMap[(this->movePhase - 1)].x)
            {
                if (roadMap[this->movePhase].x < roadMap[(this->movePhase - 1)].x)
                {
                    this->container->setScaleX(  this->container->getScaleX() * -1);
                }
            }
            else
            {
                this->scanNextTurn();
            }
            this->setPosition(this->this_pt);
            //this->x = this->this_pt.x;
            //this->y = this->this_pt.y;
            if (this->openFlag)
            {
                //this->container->alpha = 0.1;
                this->setPositionY( this->getPositionY() - 200);
            }
            this->mouseChildren = false;
            this->mouseEnabled = false;
            //this->world->listOfClasses.push(this);
            //this->world->listOfIndexes1.push(this);
            if (!this->world->selectObject)
            {
                this->world->worldInterface->barInfoManage(this);
            }
            if (!this->brother)
            {
                this->world->createGolemCounter++;
                if (this->world->createGolemCounter == 5)
                {
                    this->world->achieveManage("createGolem_5_times");
                }
            }
            return;
        }// end function

        void  Golem::update()
        {
            if (!this->openFlag)
            {
                if (this->voiceCounter > 0)
                {
                    (this->voiceCounter - 1);
                    if (this->voiceCounter == 0)
                    {
                        if (this->world->golemVoiceTurn == 1)
                        {
                            this->world->golemVoiceTurn = 2;
                            //Sounds.instance.playSound("snd_golem_voice1");
                        }
                        else if (this->world->golemVoiceTurn == 2)
                        {
                            this->world->golemVoiceTurn = 3;
                            //Sounds.instance.playSound("snd_golem_voice2");
                        }
                        else if (this->world->golemVoiceTurn == 3)
                        {
                            this->world->golemVoiceTurn = 4;
                            //Sounds.instance.playSound("snd_golem_voice3");
                        }
                        else if (this->world->golemVoiceTurn == 4)
                        {
                            this->world->golemVoiceTurn = 5;
                            //Sounds.instance.playSound("snd_golem_voice4");
                        }
                        else if (this->world->golemVoiceTurn == 5)
                        {
                            this->world->golemVoiceTurn = 6;
                            //Sounds.instance.playSound("snd_golem_voice5");
                        }
                        else if (this->world->golemVoiceTurn == 6)
                        {
                            this->world->golemVoiceTurn = 7;
                            //Sounds.instance.playSound("snd_golem_voice6");
                        }
                        else if (this->world->golemVoiceTurn == 7)
                        {
                            this->world->golemVoiceTurn = 1;
                            //Sounds.instance.playSound("snd_golem_voice8");
                        }
                    }
                }
                if (this->direction != "up")
                {
                    //if (this->container->currentFrame < 28)
                    //{
                    //    this->container->gotoAndStop((this->container->currentFrame + 1));
                    //}
                    //else
                    //{
                    //    this->container->gotoAndStop(1);
                    //}
                }
                //else if (this->container->currentFrame < 56)
                //{
                //    this->container->gotoAndStop((this->container->currentFrame + 1));
                //}
                //else
                //{
                //    this->container->gotoAndStop(29);
                //}
                //if (this->container->dust1->getVisible())
                //{
                //    if (this->container->dust1.currentFrame < this->container->dust1.totalFrames)
                //    {
                //        this->container->dust1.gotoAndStop((this->container->dust1.currentFrame + 1));
                //    }
                //    else
                //    {
                //        this->container->dust1.gotoAndStop(1);
                //        this->container->dust1->setVisible(false);
                //    }
                //}
                //if (this->container->dust2->getVisible())
                //{
                //    if (this->container->dust2.currentFrame < this->container->dust2.totalFrames)
                //    {
                //        this->container->dust2.gotoAndStop((this->container->dust2.currentFrame + 1));
                //    }
                //    else
                //    {
                //        this->container->dust2.gotoAndStop(1);
                //        this->container->dust2->setVisible(false);
                //    }
                //}
                //if (this->cameraJitterCounter <= 0)
                //{
                //    if (this->cameraJitterCounter == 0)
                //    {
                //        this->cameraJitterCounter = -1; 
                //        //this->world->y = 0;
                //        //this->world->x = 0; 
                //        //this->world->worldInterface.y = 0;
                //        //this->world->worldInterface.x = 0;
                //    }
                //    this->i = 0;
                //    while (this->i < this->world->listOfClasses.length)
                //    {
                //        if (this->world->listOfClasses[this->i] is Golem)
                //        {
                //            if (this->world->listOfClasses[this->i] == this)
                //            {
                //                if (this->container is Golem1_mc)
                //                {
                //                    if (this->container->currentFrame == 9 || this->container->currentFrame == 22 || this->container->currentFrame == 37 || this->container->currentFrame == 50)
                //                    {
                //                        this->cameraJitterCounter = this->cameraJitterTimer;
                //                        //Sounds.instance.playSoundWithVol("snd_golem_move", 0.5);
                //                    }
                //                }
                //                else if (this->container is Golem2_mc || this->container is Golem3_mc)
                //                {
                //                    if (this->container->currentFrame == 10 || this->container->currentFrame == 24 || this->container->currentFrame == 38 || this->container->currentFrame == 52)
                //                    {
                //                        this->cameraJitterCounter = this->cameraJitterTimer;
                //                        //Sounds.instance.playSoundWithVol("snd_golem_move", 0.5);
                //                    }
                //                }
                //                break;
                //            }
                //            else
                //            {
                //                break;
                //            }
                //        }
                //       i++;
                //    }
                //}
                //else
                //{
                //    (this->cameraJitterCounter - 1);
                //    this->cameraXOffset =cocos2d::rand_0_1() * 2;
                //    if (cocos2d::rand_0_1() < 0.5)
                //    {
                //        this->cameraXOffset = -this->cameraXOffset;
                //    }
                //    this->cameraYOffset = cocos2d::rand_0_1() * 2;
                //    if (cocos2d::rand_0_1() < 0.5)
                //    {
                //        this->cameraYOffset = -this->cameraYOffset;
                //    }
                //    this->world->x = this->world->x + this->cameraXOffset;
                //    this->world->y = this->world->y + this->cameraYOffset;
                //    this->tempObject = Main::mainClass->worldClass.globalToLocal(new Point(0, 0));
                //    this->world->worldInterface.x = this->tempObject.x;
                //    this->world->worldInterface.y = this->tempObject.y;
                //    this->world->hint.x = this->world->hint.x + this->tempObject.x;
                //    this->world->hint.y = this->world->hint.y + this->tempObject.y;
                //}
                //this->moveHandler();
                //this->attack();
            //}
            //else if (this->container->alpha < 1)
            //{
            //    this->container->alpha = this->container->alpha + 0.1;
            //    this->y = this->y + 20;
            //}
            //else
            //{
                //this->openFlag = false;
                //this->container->gotoAndStop(58);
                //this->container->alpha = 1;
                //this->container->dust1->getVisible() = true;
                //this->container->dust2->getVisible() = true;
                //this->world->decoration.earthquakeFlag = true;
                //Sounds.instance.playSound("snd_air_addToWorld");
            }
            return;
        }// end function

        void  Golem::moveHandler()
        {
            //if (this->this_pt.x == this->roadMap[this->movePhase].x)
            //{
            //    if (this->this_pt.y >= this->roadMap[this->movePhase].y)
            //    {
            //        this->y = this->y - this->speedK * 0.9;
            //        if (this->y <= this->roadMap[this->movePhase].y)
            //        {
            //            this->tempObject = this->y;
            //            this->y = this->roadMap[this->movePhase].y;
            //            this->bifurcation(); 
            //            this->movePhase++;
            //            if (this->movePhase < this->roadMap.length)
            //            {
            //                if (this->tempObject < this->roadMap[this->movePhase].y)
            //                {
            //                    this->speedK = this->roadMap[this->movePhase].y - this->tempObject;
            //                    this->moveHandler();
            //                }
            //            }
            //            else
            //            {
            //                this->kill();
            //            }
            //        }
            //        else if (this->speedK != this->speedKSave)
            //        {
            //            this->speedK = this->speedKSave;
            //        }
            //    }
            //    else
            //    {
            //        this->y = this->y + this->speedK;
            //        if (this->y >= this->roadMap[this->movePhase].y)
            //        {
            //            this->tempObject = this->y;
            //            this->y = this->roadMap[this->movePhase].y;
            //            this->bifurcation();
            //            var _loc_1 : *= this;
            //            var _loc_2 : *= this->movePhase + 1;
            //            _loc_1.movePhase = _loc_2;
            //            if (this->movePhase < this->roadMap.length)
            //            {
            //                if (this->tempObject > this->roadMap[this->movePhase].y)
            //                {
            //                    this->speedK = this->tempObject - this->roadMap[this->movePhase].y;
            //                    this->moveHandler();
            //                }
            //            }
            //            else
            //            {
            //                this->kill();
            //            }
            //        }
            //        else if (this->speedK != this->speedKSave)
            //        {
            //            this->speedK = this->speedKSave;
            //        }
            //    }
            //}
            //else if (this->this_pt.y == this->roadMap[this->movePhase].y)
            //{
            //    if (this->this_pt.x >= this->roadMap[this->movePhase].x)
            //    {
            //        this->x = this->x - this->speedK;
            //        if (this->x <= this->roadMap[this->movePhase].x)
            //        {
            //            this->tempObject = this->x;
            //            this->x = this->roadMap[this->movePhase].x;
            //            this->bifurcation();
            //            var _loc_1 : *= this;
            //            var _loc_2 : *= this->movePhase + 1;
            //            _loc_1.movePhase = _loc_2;
            //            if (this->movePhase < this->roadMap.length)
            //            {
            //                if (this->tempObject < this->roadMap[this->movePhase].x)
            //                {
            //                    this->speedK = this->roadMap[this->movePhase].x - this->tempObject;
            //                    this->moveHandler();
            //                }
            //            }
            //            else
            //            {
            //                this->kill();
            //            }
            //        }
            //        else if (this->speedK != this->speedKSave)
            //        {
            //            this->speedK = this->speedKSave;
            //        }
            //    }
            //    else
            //    {
            //        this->x = this->x + this->speedK;
            //        if (this->x >= this->roadMap[this->movePhase].x)
            //        {
            //            this->tempObject = this->x;
            //            this->x = this->roadMap[this->movePhase].x;
            //            this->bifurcation();
            //            var _loc_1 : *= this;
            //            var _loc_2 : *= this->movePhase + 1;
            //            _loc_1.movePhase = _loc_2;
            //            if (this->movePhase < this->roadMap.length)
            //            {
            //                if (this->tempObject > this->roadMap[this->movePhase].x)
            //                {
            //                    this->speedK = this->tempObject - this->roadMap[this->movePhase].x;
            //                    this->moveHandler();
            //                }
            //            }
            //            else
            //            {
            //                this->kill();
            //            }
            //        }
            //        else if (this->speedK != this->speedKSave)
            //        {
            //            this->speedK = this->speedKSave;
            //        }
            //    }
            //}
            //this->directionManage();
            //this->this_pt = new Point(this->x, this->y);
            //if (this->movePhase < this->roadMap.length)
            //{
            //    if (this->roadMap[this->movePhase].x == this->roadMap[(this->movePhase - 1)].x)
            //    {
            //        if (this->roadMap[this->movePhase].y > this->roadMap[(this->movePhase - 1)].y)
            //        {
            //            this->tempObject = this->roadMap[(this->movePhase - 1)].y + (this->roadMap[this->movePhase].y - this->roadMap[(this->movePhase - 1)].y) * 0.75;
            //            if (this->this_pt.y > this->tempObject)
            //            {
            //                this->scanNextTurn();
            //            }
            //        }
            //        else if (this->roadMap[this->movePhase].y < this->roadMap[(this->movePhase - 1)].y)
            //        {
            //            this->tempObject = this->roadMap[this->movePhase].y + (this->roadMap[(this->movePhase - 1)].y - this->roadMap[this->movePhase].y) * 0.75;
            //            if (this->this_pt.y < this->tempObject)
            //            {
            //                this->scanNextTurn();
            //            }
            //        }
            //    }
            //}
            return;
        }// end function

        void  Golem::directionManage()
        {
            //if (this->x > this->this_pt.x)
            //{
            //    if (this->direction != "right")
            //    {
            //        this->direction = "right";
            //        if (this->container->scaleX < 0)
            //        {
            //            this->container->scaleX = this->container->scaleX * -1;
            //            if (this->container->x != 0)
            //            {
            //                this->container->x = 0;
            //            }
            //        }
            //        if (this->container->currentFrame > 28)
            //        {
            //            this->container->gotoAndStop(this->container->currentFrame - 28);
            //        }
            //    }
            //}
            //else if (this->x < this->this_pt.x)
            //{
            //    if (this->direction != "left")
            //    {
            //        this->direction = "left";
            //        if (this->container->scaleX > 0)
            //        {
            //            this->container->scaleX = this->container->scaleX * -1;
            //            if (this->container->x != 0)
            //            {
            //                this->container->x = 0;
            //            }
            //        }
            //        if (this->container->currentFrame > 28)
            //        {
            //            this->container->gotoAndStop(this->container->currentFrame - 28);
            //        }
            //    }
            //}
            //if (this->y > this->this_pt.y)
            //{
            //    if (this->direction != "down")
            //    {
            //        this->direction = "down";
            //        if (this->container->currentFrame > 28)
            //        {
            //            this->container->gotoAndStop(this->container->currentFrame - 28);
            //        }
            //    }
            //}
            //else if (this->y < this->this_pt.y)
            //{
            //    if (this->direction != "up")
            //    {
            //        this->direction = "up";
            //        if (this->container->currentFrame < 29)
            //        {
            //            this->container->gotoAndStop(this->container->currentFrame + 28);
            //        }
            //    }
            //}
            return;
        }// end function

        void Golem::scanNextTurn()
        {
            //if (this->movePhase < (this->roadMap.length - 1))
            //{
            //    if (this->movePhase < this->roadMap.length)
            //    {
            //        if (this->roadMap[this->movePhase].x > this->roadMap[(this->movePhase + 1)].x)
            //        {
            //            if (this->container->scaleX > 0)
            //            {
            //                this->container->scaleX = this->container->scaleX * -1;
            //                if (this->container is Golem1_mc)
            //                {
            //                    if (this->container->x != -6)
            //                    {
            //                        this->container->x = -6;
            //                    }
            //                }
            //                else if (this->container is Golem2_mc)
            //                {
            //                    if (this->container->x != -5)
            //                    {
            //                        this->container->x = -5;
            //                    }
            //                }
            //                else if (this->container is Golem3_mc)
            //                {
            //                    if (this->container->x != -5)
            //                    {
            //                        this->container->x = -5;
            //                    }
            //                }
            //            }
            //        }
            //        else if (this->roadMap[this->movePhase].x < this->roadMap[(this->movePhase + 1)].x)
            //        {
            //            if (this->container->scaleX < 0)
            //            {
            //                this->container->scaleX = this->container->scaleX * -1;
            //                if (this->container->x != 0)
            //                {
            //                    this->container->x = 0;
            //                }
            //            }
            //        }
            //        else if (this->movePhase < this->roadMap.length - 2)
            //        {
            //            if (this->roadMap[this->movePhase].x > this->roadMap[this->movePhase + 2].x)
            //            {
            //                if (this->container->scaleX > 0)
            //                {
            //                    this->container->scaleX = this->container->scaleX * -1;
            //                    if (this->container is Golem1_mc)
            //                    {
            //                        if (this->container->x != -6)
            //                        {
            //                            this->container->x = -6;
            //                        }
            //                    }
            //                    else if (this->container is Golem2_mc)
            //                    {
            //                        if (this->container->x != -5)
            //                        {
            //                            this->container->x = -5;
            //                        }
            //                    }
            //                    else if (this->container is Golem3_mc)
            //                    {
            //                        if (this->container->x != -5)
            //                        {
            //                            this->container->x = -5;
            //                        }
            //                    }
            //                }
            //            }
            //            else if (this->roadMap[this->movePhase].x < this->roadMap[this->movePhase + 2].x)
            //            {
            //                if (this->container->scaleX < 0)
            //                {
            //                    this->container->scaleX = this->container->scaleX * -1;
            //                    if (this->container->x != 0)
            //                    {
            //                        this->container->x = 0;
            //                    }
            //                }
            //            }
            //        }
            //    }
            //}
            return;
        }// end function

        void Golem::attack()
        {
            //this->i = this->world->listOfUnits.length - 1;
            //while (this->i >= 0)
            //{
            //    if (this->world->listOfUnits[this->i].readyDamage && this->world->listOfUnits[this->i].atStage)
            //    {
            //        if (Point.distance(this->world->listOfUnits[this->i].shoot_pt, this->this_pt) < 30)
            //        {
            //            if (this->world->listOfUnits[this->i].health < this->health)
            //            {
            //                this->health = this->health - this->world->listOfUnits[this->i].health;
            //                this->world->listOfUnits[this->i].getHit(this->world->listOfUnits[this->i].health, "golem");
            //                (this->world->saveBox.gameSave.data.addit_golemKillEnemiesCounter + 1);
            //                if (this->world->saveBox.gameSave.data.addit_golemKillEnemiesCounter == 250)
            //                {
            //                    this->world->achieveManage("golemKill_250_enemies");
            //                }
            //            }
            //            else
            //            {
            //                this->world->listOfUnits[this->i].getHit(this->health, "golem");
            //                this->health = 0;
            //                this->closeGolem();
            //                break;
            //            }
            //        }
            //    }
            //    i--;
            //}
            return;
        }// end function

        void  Golem::bifurcation()
        {
            //if (this->movePhase < (this->roadMap.length - 1))
            //{
            //    this->tempObject1 = null;
            //    this->i = 1;
            //    while (this->i <= Main::mainClass->readXMLClass.strategies)
            //    {
            //        if (this->i != this->road)
            //        {
            //            if (this->i == 1)
            //            {
            //                this->j = this->world->map.road1.length - 2;
            //                while (this->j >= 0)
            //                {
            //                    if (this->world->map.road1[this->j].x == this->roadMap[this->movePhase].x && this->world->map.road1[this->j].y == this->roadMap[this->movePhase].y && (this->world->map.road1[(this->j + 1)].x != this->roadMap[(this->movePhase + 1)].x || this->world->map.road1[(this->j + 1)].y != this->roadMap[(this->movePhase + 1)].y))
            //                    {
            //                        this->tempObject1 = new Golem(this->roadMap[this->movePhase], this->i, (this->j + 1), false);
            //                        this->brother = this->tempObject1;
            //                        this->tempObject1.brother = this;
            //                        this->world->addChild(this->tempObject1);
            //                        this->tempObject1.container.scaleX = this->container->scaleX;
            //                        this->tempObject1.container.x = this->container->x;
            //                        this->tempObject1.container.gotoAndStop(this->container->currentFrame);
            //                        var _loc_1 : *= this->health / 2;
            //                        this->tempObject1.health = this->health / 2;
            //                        this->health = _loc_1;
            //                        this->tempObject1.voiceCounter = 0;
            //                        this->world->worldInterface.barInfoView();
            //                        break;
            //                    }
            //                    j--;
            //                }
            //            }
            //            else if (this->i == 2)
            //            {
            //                this->j = this->world->map.road2.length - 2;
            //                while (this->j >= 0)
            //                {
            //                    if (this->world->map.road2[this->j].x == this->roadMap[this->movePhase].x && this->world->map.road2[this->j].y == this->roadMap[this->movePhase].y && (this->world->map.road2[(this->j + 1)].x != this->roadMap[(this->movePhase + 1)].x || this->world->map.road2[(this->j + 1)].y != this->roadMap[(this->movePhase + 1)].y))
            //                    {
            //                        this->tempObject1 = new Golem(this->roadMap[this->movePhase], this->i, (this->j + 1), false);
            //                        this->brother = this->tempObject1;
            //                        this->tempObject1.brother = this;
            //                        this->world->addChild(this->tempObject1);
            //                        this->tempObject1.container.scaleX = this->container->scaleX;
            //                        this->tempObject1.container.x = this->container->x;
            //                        this->tempObject1.container.gotoAndStop(this->container->currentFrame);
            //                        var _loc_1 : *= this->health / 2;
            //                        this->tempObject1.health = this->health / 2;
            //                        this->health = _loc_1;
            //                        this->tempObject1.voiceCounter = 0;
            //                        this->world->worldInterface.barInfoView();
            //                        break;
            //                    }
            //                    j--;
            //                }
            //            }
            //            if (this->tempObject1)
            //            {
            //                break;
            //            }
            //        }
            //        i++;
            //    }
            //}
            return;
        }// end function

        void Golem::closeGolem()
        {
            //this->kill();
            //if (this->direction != "up")
            //{
            //    if (this->container is Golem1_mc)
            //    {
            //        this->tempObject = new Indexes(new Golem1HorisontDeath_mc(), 1);
            //        this->tempObject.container.gotoAndStop(12);
            //    }
            //    else if (this->container is Golem2_mc)
            //    {
            //        this->tempObject = new Indexes(new Golem2HorisontDeath_mc(), 1);
            //        this->tempObject.container.gotoAndStop(12);
            //    }
            //    else if (this->container is Golem3_mc)
            //    {
            //        this->tempObject = new Indexes(new Golem3HorisontDeath_mc(), 1);
            //        this->tempObject.container.gotoAndStop(12);
            //    }
            //}
            //else if (this->container is Golem1_mc)
            //{
            //    this->tempObject = new Indexes(new Golem1VerticalDeath_mc(), 1);
            //    this->tempObject.container.gotoAndStop(12);
            //}
            //else if (this->container is Golem2_mc)
            //{
            //    this->tempObject = new Indexes(new Golem2VerticalDeath_mc(), 1);
            //    this->tempObject.container.gotoAndStop(12);
            //}
            //else if (this->container is Golem3_mc)
            //{
            //    this->tempObject = new Indexes(new Golem3VerticalDeath_mc(), 1);
            //    this->tempObject.container.gotoAndStop(12);
            //}
            //this->tempObject.type = "golemDeath";
            //this->tempObject.container.scaleX = this->container->scaleX;
            //this->tempObject.container.x = this->container->x;
            //this->tempObject.x = this->this_pt.x;
            //this->tempObject.y = this->this_pt.y;
            //Sounds.instance.playSound("snd_golem_death");
            return;
        }// end function

        void Golem::kill()
        {
            if (!this->dead)
            {
                this->dead = true;
                this->world->removeChild(this);
                //this->i = 0;
                //while (this->i < this->world->listOfClasses.length)
                //{
                //    if (this->world->listOfClasses[this->i] == this)
                //    {
                //        this->world->listOfClasses.splice(this->i, 1);
                //        break;
                //    }
                //    i++;
                //}
                //this->i = 0;
                //while (this->i < this->world->listOfIndexes1.length)
                //{

                //    if (this->world->listOfIndexes1[this->i] == this)
                //    {
                //        this->world->listOfIndexes1.splice(this->i, 1);
                //        break;
                //    }
                //   i++;
                //}0
                //this->world->y = 0;
                //this->world->x = 0;0
                //this->world->worldInterface.y = 0;
                //this->world->worldInterface.x = 0;
                //this->world->hint.x = Math.round(this->world->hint.x);
                //this->world->hint.y = Math.round(this->world->hint.y);
                if (this->world->selectObject == this)
                {
                    this->world->worldInterface->barInfoManage();
                }
            }
            return;
        }// end function

    }
}
