#include "Golem.h"
#include "engine/world.h"

namespace engine{
    namespace    casts
    {
        Golem1_mc:Golem1_mc()
        {
            dust1=new MovieClip("cast/","dust1","Golem1_mc");
            dust2=new MovieClip("cast/","dust2","Golem1_mc");
        }
        Golem2_mc:Golem1_mc()
        {
            dust1=new MovieClip("cast/","dust1","Golem2_mc");
            dust2=new MovieClip("cast/","dust2","Golem2_mc");
        }
        Golem3_mc:Golem1_mc()
        {
            dust1=new MovieClip("cast/","dust1","Golem3_mc");
            dust2=new MovieClip("cast/","dust2","Golem3_mc");
        }
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
                    if (this->container->currentFrame < 28)
                    {
                        this->container->currentFrame++;
                        //this->container->gotoAndStop((this->container->currentFrame + 1));
                    }
                    else
                    {
                        this->container->currentFrame=1;
                        //this->container->gotoAndStop(1);
                    }
                }
                else if (this->container->currentFrame < 56)
                {
                    this->container->currentFrame++;
                    //this->container->gotoAndStop((this->container->currentFrame + 1));
                }
                else
                {
                    this->container->currentFrame=1;
                    //this->container->gotoAndStop(29);
                }
                if (this->container->dust1->getVisible())
                {
                    if (this->container->dust1->currentFrame < this->container->dust1->totalFrames)
                    {
                        this->container->dust1->currentFrame++;
                        //this->container->dust1.gotoAndStop((this->container->dust1.currentFrame + 1));
                    }
                    else
                    {
                        this->container->dust1->currentFrame=1;
                        //this->container->dust1.gotoAndStop(1);
                        this->container->dust1->setVisible(false);
                    }
                }
                if (this->container->dust2->getVisible())
                {
                    if (this->container->dust2->currentFrame < this->container->dust2->totalFrames)
                    {
                        this->container->dust2.currentFrame++;
                        //this->container->dust2->gotoAndStop(this->container->dust2.currentFrame);
                    }
                    else
                    {
                        this->container->dust2.currentFrame=1;
                        //this->container->dust2->gotoAndStop(1);
                        this->container->dust2->setVisible(false);
                    }
                }
                if (this->cameraJitterCounter <= 0)
                {
                    if (this->cameraJitterCounter == 0)
                    {
                        this->cameraJitterCounter = -1; 
                        this->world->setPosition(Vec2(0,0));
                        //this->world->y = 0;
                        //this->world->x = 0; 
                        this->world->worldInterface->setPosition(Vec2(0,0));
                        //this->world->worldInterface.y = 0;
                        //this->world->worldInterface.x = 0;
                    }
                    this->i = 0;
                    while (this->i < this->world->listOfClasses.length)
                    {
                        if (this->world->listOfClasses[this->i] is Golem)
                        {
                            if (this->world->listOfClasses[this->i] == this)
                            {
                                if (dynamic_cast<Golem1_mc*>(this->container))
                                {
                                    if (this->container->currentFrame == 9 || this->container->currentFrame == 22 || this->container->currentFrame == 37 || this->container->currentFrame == 50)
                                    {
                                        this->cameraJitterCounter = this->cameraJitterTimer;
                                        //Sounds.instance.playSoundWithVol("snd_golem_move", 0.5);
                                    }
                                }
                                else if (dynamic_cast<Golem2_mc*>(this->container)   ||dynamic_cast<Golem3_mc*>(this->container)  )
                                {
                                    if (this->container->currentFrame == 10 || this->container->currentFrame == 24 || this->container->currentFrame == 38 || this->container->currentFrame == 52)
                                    {
                                        this->cameraJitterCounter = this->cameraJitterTimer;
                                        //Sounds.instance.playSoundWithVol("snd_golem_move", 0.5);
                                    }
                                }
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                       i++;
                    }
                }
                else
                {
                    (this->cameraJitterCounter - 1);
                    this->cameraXOffset =cocos2d::rand_0_1() * 2;
                    if (cocos2d::rand_0_1() < 0.5)
                    {
                        this->cameraXOffset = -this->cameraXOffset;
                    }
                    this->cameraYOffset = cocos2d::rand_0_1() * 2;
                    if (cocos2d::rand_0_1() < 0.5)
                    {
                        this->cameraYOffset = -this->cameraYOffset;
                    }
                    this->world->setPosition(Vec2(this->world->getPositionX()+this->cameraXOffset,this->world->getPositionY()+this->cameraYOffset));
    				//this->world->x = this->world->x + this->cameraXOffset;
    				//this->world->y = this->world->y + this->cameraYOffset;
			        cocos2d::Point tempObject = this->world->convertToWorldSpace(cocos2d::Point(0, 0));
				    //this->tempObject = Main::mainClass->worldClass->globalToLocal(new Point(0, 0));
			        this->world->worldInterface->setPosition(tempObject);
				    //this->world->worldInterface.x = this->tempObject.x;
				    //this->world->worldInterface.y = this->tempObject.y;

                    //this->world->hint.x = this->world->hint.x + this->tempObject.x;
                    //this->world->hint.y = this->world->hint.y + this->tempObject.y;
                }
                this->moveHandler();
                this->attack();
            }
            else if (this->container->getOpacity() < 1) {
    			this->container->setOpacity(this->container->getOpacity() + 0.1);
    			this->setPositionY(this->getPositionY() + 20);
			    //this->y = this->y + 20;
		    }
            else
            {
                this->openFlag = false;
                //this->container->gotoAndStop(58);
                this->container->setOpacity(1);
                this->container->dust1->setVisible(true);
                this->container->dust2->setVisible(true) ;
                //this->world->decoration->earthquakeFlag = true;
                //Sounds.instance.playSound("snd_air_addToWorld");
            }
            return;
        }// end function

        void  Golem::moveHandler()
        {
            Common::Array<cocos2d::Point> &roadMap=*this->roadMap;
            if (this->this_pt.x == roadMap[this->movePhase].x)
            {
                if (this->this_pt.y >= roadMap[this->movePhase].y)
                {
                    this->setPositionY(this->getPositionY() - this->speedK * 0.9);
                    //this->y = this->y - this->speedK * 0.9;
                    if (this->getPositionY() <= roadMap[this->movePhase].y)
                    {
                        float tempObject =this->getPositionY();// this->y;
                        this->setPositionY(roadMap[this->movePhase].y);
                        this->bifurcation(); 
                        this->movePhase++;
                        if (this->movePhase < roadMap.size())
                        {
                            if (tempObject < roadMap[this->movePhase].y)
                            {
                                this->speedK = roadMap[this->movePhase].y - tempObject;
                                this->moveHandler();
                            }
                        }
                        else
                        {
                            this->kill();
                        }
                    }
                    else if (this->speedK != this->speedKSave)
                    {
                        this->speedK = this->speedKSave;
                    }
                }
                else
                {
                    this->setPositionY(this->getPositionY() + this->speedK);//this->y = this->y + this->speedK;
                    if (this->getPositionY() >= roadMap[this->movePhase].y)
                    {
                        float tempObject = this->getPositionY();
                        this->setPositionY(roadMap[this->movePhase].y);
                        this->bifurcation();
                        this->movePhase++;
                        if (this->movePhase < roadMap.size())
                        {
                            if (tempObject > roadMap[this->movePhase].y)
                            {
                                this->speedK = tempObject - roadMap[this->movePhase].y;
                                this->moveHandler();
                            }
                        }
                        else
                        {
                            this->kill();
                        }
                    }
                    else if (this->speedK != this->speedKSave)
                    {
                        this->speedK = this->speedKSave;
                    }
                }
            }
            else if (this->this_pt.y == roadMap[this->movePhase].y)
            {
                if (this->this_pt.x >= roadMap[this->movePhase].x)
                {
                    this->setPositionX(this->getPositionX() - this->speedK);
                    //this->x = this->x - this->speedK;
                    if (this->xgetPositionX() <= roadMap[this->movePhase].x)
                    {
                        float tempObject = this->getPositionX();
                        this->setPositionX(roadMap[this->movePhase].x);
                        this->bifurcation();
                        this->movePhase++;
                        if (this->movePhase < roadMap.size())
                        {
                            if (tempObject < roadMap[this->movePhase].x)
                            {
                                this->speedK = roadMap[this->movePhase].x - tempObject;
                                this->moveHandler();
                            }
                        }
                        else
                        {
                            this->kill();
                        }
                    }
                    else if (this->speedK != this->speedKSave)
                    {
                        this->speedK = this->speedKSave;
                    }
                }
                else
                {
                    this->setPositionX(this->getPositionX() + this->speedK);
                    //this->x = this->x + this->speedK;
                    if (this->getPositionX() >= roadMap[this->movePhase].x)
                    {
                        float tempObject = this->getPositionX();
                        this->setPositionX(roadMap[this->movePhase].x);
                        this->bifurcation();
                        this->movePhase++;
                        if (this->movePhase < roadMap.size())
                        {
                            if ( tempObject > roadMap[this->movePhase].x)
                            {
                                this->speedK =  tempObject - roadMap[this->movePhase].x;
                                this->moveHandler();
                            }
                        }
                        else
                        {
                            this->kill();
                        }
                    }
                    else if (this->speedK != this->speedKSave)
                    {
                        this->speedK = this->speedKSave;
                    }
                }
            }
            this->directionManage();
            this->this_pt =this->getPosition();// cocos2d::Point(this->x, this->y);
            if (this->movePhase < roadMap.size())
            {
                if (roadMap[this->movePhase].x == roadMap[(this->movePhase - 1)].x)
                {
                    if (roadMap[this->movePhase].y > roadMap[(this->movePhase - 1)].y)
                    {
                        float tempObject = roadMap[(this->movePhase - 1)].y + (roadMap[this->movePhase].y - roadMap[(this->movePhase - 1)].y) * 0.75;
                        if (this->this_pt.y >  tempObject)
                        {
                            this->scanNextTurn();
                        }
                    }
                    else if (roadMap[this->movePhase].y < roadMap[(this->movePhase - 1)].y)
                    {
                        float tempObject = roadMap[this->movePhase].y + (roadMap[(this->movePhase - 1)].y - roadMap[this->movePhase].y) * 0.75;
                        if (this->this_pt.y < tempObject)
                        {
                            this->scanNextTurn();
                        }
                    }
                }
            }
            return;
        }// end function

        void  Golem::directionManage()
        {
            if (this->getPositionX() > this->this_pt.x)
            {
                if (this->direction != "right")
                {
                    this->direction = "right";
                    if (this->container->getScaleX() < 0)
                    {
                        this->container->setScaleX(this->container->getScaleX() * -1);
                        if (this->container->getPositionX() != 0)
                        {
                            this->container->setPositionX(0);
                        }
                    }
                    if (this->container->currentFrame > 28)
                    {
                        this->container->gotoAndStop(this->container->currentFrame - 28);
                    }
                }
            }
            else if (this->getPositionX() < this->this_pt.x)
            {
                if (this->direction != "left")
                {
                    this->direction = "left";
                    if (this->container->getScaleX() > 0)
                    {
                        this->container->setScaleX(this->container->getScaleX() * -1);
                        if (this->container->getPositionX() != 0)
                        {
                            this->container->setPositionX(0);
                        }
                    }
                    if (this->container->currentFrame > 28)
                    {
                        this->container->gotoAndStop(this->container->currentFrame - 28);
                    }
                }
            }
            if (this->getPositionY() > this->this_pt.y)
            {
                if (this->direction != "down")
                {
                    this->direction = "down";
                    if (this->container->currentFrame > 28)
                    {
                        this->container->gotoAndStop(this->container->currentFrame - 28);
                    }
                }
            }
            else if (this->getPositionY() < this->this_pt.y)
            {
                if (this->direction != "up")
                {
                    this->direction = "up";
                    if (this->container->currentFrame < 29)
                    {
                        this->container->gotoAndStop(this->container->currentFrame + 28);
                    }
                }
            }
            return;
        }// end function

        void Golem::scanNextTurn()
        {
            Common::Array<cocos2d::Point> &roadMap=*this->roadMap;
            if (this->movePhase < (roadMap.size() - 1))
            {
                if (this->movePhase < roadMap.size())
                {
                    if (roadMap[this->movePhase].x > roadMap[(this->movePhase + 1)].x)
                    {
                        if (this->container->getScaleX() > 0)
                        {
                            this->container->setScaleX(this->container->getScaleX() * -1);
                            if (dynamic_cast<Golem1_mc*>(this->container))
                            {
                                if (this->container->getPositionX() != -6)
                                {
                                    this->container->setPositionX(-6);
                                }
                            }
                            else if (dynamic_cast<Golem2_mc*>(this->container) || dynamic_cast<Golem3_mc*>(this->container) )//(this->container is Golem2_mc)
                            {
                                if (this->container->getPositionX() != -5)
                                {
                                    this->container->setPositionX(-5);
                                } 
                            }
                        }
                    }
                    else if (roadMap[this->movePhase].x < roadMap[(this->movePhase + 1)].x)
                    {
                        if (this->container->getScaleX() < 0)
                        {
                            this->container->setScaleX(this->container->getScaleX() * -1);
                            //this->container->scaleX = this->container->scaleX * -1;
                            if (this->container->getPositionX() != 0)
                            {
                                this->container->setPositionX(0);
                            }
                        }
                    }
                    else if (this->movePhase < roadMap.size() - 2)
                    {
                        if (roadMap[this->movePhase].x > roadMap[this->movePhase + 2].x)
                        {
                            if (this->container->getScaleX() > 0)
                            {
                                this->container->setScaleX(this->container->getScaleX() * -1);
                                //this->container->scaleX = this->container->getScaleX() * -1;
                                if (dynamic_cast<Golem1_mc*>(this->container))
                                {
                                    if (this->container->getPositionX() != -6)
                                    {
                                        this->container->setPositionX(-6);
                                    }
                                }
                                else if (dynamic_cast<Golem2_mc*>(this->container) || dynamic_cast<Golem3_mc*>(this->container) )//(this->container is Golem2_mc)
                                {
                                    if (this->container->getPositionX() != -5)
                                    {
                                        this->container->setPositionX(-5);
                                    } 
                                }
                            }
                        }
                        else if (roadMap[this->movePhase].x < roadMap[this->movePhase + 2].x)
                        {
                            if (this->container->getScaleX() < 0)
                            {
                                this->container->setScaleX(this->container->getScaleX() * -1);
                                //this->container->scaleX = this->container->getScaleX() * -1;
                                if (this->container->getPositionX() != 0)
                                {
                                    this->container->setPositionX(0);
                                }
                            }
                        }
                    }
                }
            }
            return;
        }// end function

        void Golem::attack()
        {
            int i = this->world->listOfUnits.size() - 1;
            while (this->i >= 0)
            {
                if (this->world->listOfUnits[i]->readyDamage && this->world->listOfUnits[i]->atStage())
                {
                    if (this->world->listOfUnits[i]->shoot_pt.distance(this->this_pt) < 30)
                    {
                        if (this->world->listOfUnits[i]->health < this->health)
                        {
                            this->health = this->health - this->world->listOfUnits[i]->health;
                            this->world->listOfUnits[i]->getHit(this->world->listOfUnits[i]->health, "golem");
                            int addit_golemKillEnemiesCounter=this->world->saveBox->getIntValue("addit_golemKillEnemiesCounter")+1;
                            //this->world->saveBox.gameSave.data.addit_golemKillEnemiesCounter++;
                            this->world->saveBox->setIntValue("addit_golemKillEnemiesCounter", addit_golemKillEnemiesCounter)  ;
                            if (addit_golemKillEnemiesCounter == 250)
                            {
                                this->world->achieveManage("golemKill_250_enemies");
                            }
                        }
                        else
                        {
                            this->world->listOfUnits[i]->getHit(this->health, "golem");
                            this->health = 0;
                            this->closeGolem();
                            break;
                        }
                    }
                }
                i--;
            }
            return;
        }// end function

        void  Golem::bifurcation()
        {
            Common::Array<cocos2d::Point> &roadMap=*this->roadMap;
            if (this->movePhase < (roadMap.size() - 1))
            {
                Golem * tempObject1 = NULL;
                this->i = 1;
                while (this->i <= Main::mainClass->readXMLClass.strategies)
                {
                    if (this->i != this->road)
                    {
                        if (this->i == 1)
                        {
                            this->j = this->world->map.road1.size() - 2;
                            while (this->j >= 0)
                            {
                                if (this->world->map.road1[this->j].x == roadMap[this->movePhase].x && this->world->map.road1[this->j].y == roadMap[this->movePhase].y 
                                    && (this->world->map.road1[(this->j + 1)].x != roadMap[(this->movePhase + 1)].x || this->world->map.road1[(this->j + 1)].y != roadMap[(this->movePhase + 1)].y))
                                {
                                    tempObject1 = new Golem(roadMap[this->movePhase], this->i, (this->j + 1), false);
                                    this->brother = tempObject1;
                                    this->tempObject1->brother = this;
                                    this->world->addChild(tempObject1);
                                    tempObject1->container->setScaleX(this->container->getScaleX());
                                    tempObject1->container->setPositionX(this->container->getPositionX());
                                    tempObject1->container->gotoAndStop(this->container->currentFrame);
                                    tempObject1->health = this->health / 2;
                                    this->health = this->health / 2;
                                    this->tempObject1->voiceCounter = 0;
                                    this->world->worldInterface->barInfoView();
                                    break;
                                }
                                j--;
                            }
                        }
                        else if (this->i == 2)
                        {
                            this->j = this->world->map.road2.length - 2;
                            while (this->j >= 0)
                            {
                                if (this->world->map.road2[this->j].x == roadMap[this->movePhase].x && this->world->map.road2[this->j].y == roadMap[this->movePhase].y && (this->world->map.road2[(this->j + 1)].x != roadMap[(this->movePhase + 1)].x || this->world->map.road2[(this->j + 1)].y != roadMap[(this->movePhase + 1)].y))
                                {
                                    tempObject1 = new Golem(roadMap[this->movePhase], this->i, (this->j + 1), false);
                                    this->brother = tempObject1;
                                    tempObject1->brother = this;
                                    this->world->addChild( tempObject1);
                                    tempObject1->container->setScaleX(this->container->getScaleX());
                                    tempObject1->container->setPositionX(this->container->getPositionX());
                                    tempObject1->container->gotoAndStop(this->container->currentFrame);
                                    tempObject1->health = this->health / 2;
                                    this->health = this->health / 2;
                                    tempObject1->voiceCounter = 0;
                                    this->world->worldInterface->barInfoView();
                                    break;
                                }
                                j--;
                            }
                        }
                        if (tempObject1)
                        {
                            break;
                        }
                    }
                    i++;
                }
            }
            return;
        }// end function

        void Golem::closeGolem()
        {
            Common::Array<cocos2d::Point> &roadMap=*this->roadMap;
            this->kill();
            OnceMovieClip * tempObject =NULL;
            if (this->direction != "up")
            {
                if (dynamic_cast<Golem1_mc*>(this->container))
                {
                    tempObject = new OnceMovieClip(this->world,"cast/","Golem1HorisontDeath_mc","Golem1HorisontDeath_mc");
                    tempObject->container->gotoAndStop(12);
                }
                else if (dynamic_cast<Golem2_mc*>(this->container) )
                {
                    tempObject = new OnceMovieClip(this->world,"cast/","Golem2HorisontDeath_mc","Golem2HorisontDeath_mc");
                    tempObject->container->gotoAndStop(12);
                }
                else if (dynamic_cast<Golem3_mc*>(this->container))
                {
                    tempObject = new OnceMovieClip(this->world,"cast/","Golem3HorisontDeath_mc","Golem3HorisontDeath_mc");
                    //tempObject = new Indexes(new Golem3HorisontDeath_mc(), 1);
                    tempObject->container->gotoAndStop(12);
                }
            }
            else if (dynamic_cast<Golem1_mc*>(this->container))
            {
                tempObject = new OnceMovieClip(this->world,"cast/","Golem1VerticalDeath_mc","Golem1VerticalDeath_mc");
                //tempObject = new Indexes(new Golem1VerticalDeath_mc(), 1);
                tempObject->container->gotoAndStop(12);
            }
            else if (dynamic_cast<Golem2_mc*>(this->container))
            {
                //tempObject = new Indexes(new Golem2VerticalDeath_mc(), 1);
                tempObject = new OnceMovieClip(this->world,"cast/","Golem2VerticalDeath_mc","Golem2VerticalDeath_mc");
                tempObject->container->gotoAndStop(12);
            }
            else if (dynamic_cast<Golem3_mc*>(this->container))
            {
                //tempObject = new Indexes(new Golem3VerticalDeath_mc(), 1);
                tempObject = new OnceMovieClip(this->world,"cast/","Golem3VerticalDeath_mc","Golem3VerticalDeath_mc");
                tempObject->container->gotoAndStop(12);
            }
            tempObject->type = "golemDeath";
            tempObject->container->setScaleX(this->container->getScaleX());
            tempObject->container->setPositionX(this->container->getPositionX());
            tempObject->setPosition(this->this_pt);
            //tempObject->x = this->this_pt.x;
            //tempObject->y = this->this_pt.y;
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
