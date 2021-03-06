﻿#include "MainClass.h"
#include "World.h"
#include "Waves.h"
#include "bezier/Bezier.h"
#include "bezier/PathPoint.h"
//#include "bezier/Bezier.h"
#include "SavedCastTime.h"
#include "engine/WorldInterface.h"
#include "MoneyAdd.h"
#include "engine/level/Level.h"
#include "engine/units/Unit.h"
#include "InTimer.h"
#include "CallDelay.h"
#include "training/Training_5.h"
#include "training/Training_8.h"
#include "training/Training_92.h"

using namespace engine::units;
using namespace bezier ;

namespace engine 
{
	Waves::Waves() :nowWave(0), maxWaves(0), waveWork(false), waveWorkSt1(false), waveWorkSt2(false), waveWorkSt3(false), world(NULL)
	{
		i = j = n = 0; 
		this->world = Main::mainClass->worldClass;
		//this->listOfWaves = [];
		//this->additArr = [[], [], []];
		//this->listOfReplacement = [];
	}
	void Waves::startWaves()
	{
		int complexityLevel = this->world->saveBox->getIntValue("complexityLevel");
		if (this->nowWave > 0)
		{
			float tempObject = (float)this->listOfWaves[0][0][0] / this->world->pointer1->timer;
			//this->tempObject = this->listOfWaves[0][0][0] / this->world->pointer1->timer;
            if (tempObject > 0)
            {
				SavedCastTime * tempObject1 = NULL;
                this->j = ::round(tempObject * Main::mainClass->readXMLClass.savingOfTimeCast);
                if (this->world->worldInterface->castGolemCounter > 0 && this->world->worldInterface->castGolemCounter < this->world->worldInterface->castGolemTimer)
                {
                    if (this->j > this->world->worldInterface->castGolemTimer - this->world->worldInterface->castGolemCounter)
                    {
                        tempObject1 = new SavedCastTime("golem", this->world->worldInterface->castGolemTimer - this->world->worldInterface->castGolemCounter);
                    }
                    else
                    {
                        tempObject1 = new SavedCastTime("golem", this->j);
                    }
                    this->world->worldInterface->addChild(tempObject1);
                    //this->world->addClasses(tempObject1);
                }
                if (this->world->worldInterface->castIcemanCounter > 0 && this->world->worldInterface->castIcemanCounter < this->world->worldInterface->castIcemanTimer)
                {
                    if (this->j > this->world->worldInterface->castIcemanTimer - this->world->worldInterface->castIcemanCounter)
                    {
                        tempObject1 = new SavedCastTime("iceman", this->world->worldInterface->castIcemanTimer - this->world->worldInterface->castIcemanCounter);
                    }
                    else
                    {
                        tempObject1 = new SavedCastTime("iceman", this->j);
                    }
                    this->world->worldInterface->addChild(tempObject1);
                    //this->world->addClasses(tempObject1);
                }
                if (this->world->worldInterface->castAirCounter > 0 && this->world->worldInterface->castAirCounter < this->world->worldInterface->castAirTimer)
                {
                    if (this->j > this->world->worldInterface->castAirTimer - this->world->worldInterface->castAirCounter)
                    {
                        tempObject1 = new SavedCastTime("air", this->world->worldInterface->castAirTimer - this->world->worldInterface->castAirCounter);
                    }
                    else
                    {
                        tempObject1 = new SavedCastTime("air", this->j);
                    }
                    this->world->worldInterface->addChild(tempObject1);
                    //this->world->addClasses(tempObject1);
                }
				if (this->world->worldInterface->castGolemCounter > 0 || this->world->worldInterface->castIcemanCounter ||
					this->world->worldInterface->castAirCounter) {
					this->i = 0;
					while (this->i < this->j)
					{
						this->world->worldInterface->downloadCast();
    					i++;
					}
				}
                tempObject = ::round(tempObject * 20);
                if (tempObject > 0)
                {
                    this->world->money = this->world->money + tempObject;
                    if (this->world->pointer1)
                    {
                        if (this->world->pointer1->isVisible())
                        {
                            MoneyAdd *tempObject1 = new MoneyAdd(tempObject);
                            tempObject1->setPosition(this->world->pointer1->getPosition());
                            this->world->addChild( tempObject1,3);
                        }
                    }
                    if (this->world->pointer2)
                    {
                        if (this->world->pointer2->isVisible())
                        {
                            MoneyAdd * tempObject1 = new MoneyAdd(tempObject);
                            tempObject1->setPosition(this->world->pointer2->getPosition());
                            this->world->addChild( tempObject1,3);
                        }
                    }
                    if (this->world->pointer3)
                    {
                        if (this->world->pointer3->isVisible())
                        {
                            MoneyAdd * tempObject1 = new MoneyAdd(tempObject);
                            tempObject1->setPosition(this->world->pointer3->getPosition());
                            //tempObject1.x = this->world->pointer3.x;
                            //tempObject1.y = this->world->pointer3.y;
                            this->world->addChild(tempObject1,3);
                        }
                    }
                    AudioUtil::playSoundWithVol("Snd_menu_monetki.mp3", 0.95f);
                }
                //(this->world->saveBox.gameSave.data.addit_earlyWavesCounter + 1);
                int addit_earlyWavesCounter=this->world->saveBox->getIntValue("addit_earlyWavesCounter")+1;
                this->world->earlyWaveCounter=addit_earlyWavesCounter;
                this->world->saveBox->setValue("addit_earlyWavesCounter",addit_earlyWavesCounter);
                if (addit_earlyWavesCounter == 100)
                {
                    this->world->achieveManage("call_100_earlyWaves");
                }
                if (this->world->earlyWaveCounter == (this->maxWaves - 1))
                {
                    this->world->achieveManage("callAllWavesInLevel");
                }
            }
		}
		else
		{
			if (!this->world->worldInterface->container->fastFastCase->mouseEnabled)
			{
				this->world->worldInterface->container->fastFastCase->setMouseEnabled(true);
			}
			if (complexityLevel < 4)
			{
				if (this->world->nowLevel == 1)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = true;
					this->world->worldInterface->blockCastAir = true;
				}
				else if (this->world->nowLevel == 2)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = false;
					this->world->worldInterface->blockCastAir = true;
				}
				else if (this->world->nowLevel == 3)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = false;
					this->world->worldInterface->blockCastAir = false;
				}
				else
				{
					this->world->worldInterface->blockCastGolem = false;
					this->world->worldInterface->blockCastIceman = false;
					this->world->worldInterface->blockCastAir = false;
				}
			}
			else
			{
				if (this->world->nowLevel == 1)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = true;
					this->world->worldInterface->blockCastAir = true;
				}
				else if (this->world->nowLevel == 2)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = false;
					this->world->worldInterface->blockCastAir = true;
				}
				else if (this->world->nowLevel == 8)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = false;
					this->world->worldInterface->blockCastAir = false;
				}
				else if (this->world->nowLevel == 9)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = true;
					this->world->worldInterface->blockCastAir = true;
				}
				else if (this->world->nowLevel == 10)
				{
					this->world->worldInterface->blockCastGolem = false;
					this->world->worldInterface->blockCastIceman = false;
					this->world->worldInterface->blockCastAir = false;
				}
				else if (this->world->nowLevel == 11)
				{
					this->world->worldInterface->blockCastGolem = false;
					this->world->worldInterface->blockCastIceman = true;
					this->world->worldInterface->blockCastAir = false;
				}
				else if (this->world->nowLevel == 12)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = true;
					this->world->worldInterface->blockCastAir = true;
				}
				else if (this->world->nowLevel == 13)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = false;
					this->world->worldInterface->blockCastAir = false;
				}
				else if (this->world->nowLevel == 14)
				{
					this->world->worldInterface->blockCastGolem = false;
					this->world->worldInterface->blockCastIceman = true;
					this->world->worldInterface->blockCastAir = false;
				}
				else if (this->world->nowLevel == 15)
				{
					this->world->worldInterface->blockCastGolem = true;
					this->world->worldInterface->blockCastIceman = true;
					this->world->worldInterface->blockCastAir = true;
				}
				else
				{
					this->world->worldInterface->blockCastGolem = false;
					this->world->worldInterface->blockCastIceman = false;
					this->world->worldInterface->blockCastAir = false;
				}
				//this->world->worldInterface->container->lastTime->alpha = 1;
				//this->world->worldInterface->container->lastTime->setVisible(false);
			}
		}
		this->world->worldInterface->container->startWaves->gotoAndStop(21);
		this->world->worldInterface->container->startWavesStartWavesCase->setMouseEnabled(false);
		if (this->world->pointer1->isVisible())
		{ 
		    this->world->pointer1->setMouseChildren(false);
		    this->world->pointer1->setMouseEnabled(false);
		}
		if (this->world->pointer2)
		{
		    if (this->world->pointer2->isVisible())
		    { 
		        this->world->pointer2->setMouseChildren(false);
		        this->world->pointer2->setMouseEnabled(false);
		    }
		}
		if (this->world->pointer3)
		{
		    if (this->world->pointer3->isVisible())
		    { 
		        this->world->pointer3->setMouseChildren(false);
		        this->world->pointer3->setMouseEnabled(false);
		    }
		}
		this->nowWave++;
		this->waveWork = true;
		if (this->world->numRoads > 0)
		{
			this->waveWorkSt1 = true;
		}
		if (this->world->numRoads > 1)
		{
			this->waveWorkSt2 = true;
		}
		if (this->world->numRoads > 2)
		{
			this->waveWorkSt3 = true;
		}
		//Main::mainClass->testingClass->newWave();
		if (complexityLevel < 4)
		{
			if (this->nowWave == 1)
			{
				this->world->secondMusicPlay = true;
				this->world->secondMusicCounter = 15;
				//if (Sounds.instance.musicChanel)
				//{
				//    Sounds.instance.musicChanel.soundTransform = new SoundTransform(0, 0);
				//}
				if (this->world->nowLevel == 1)
					if (Main::fullTraining)new CallDelay("newElement", 1);
			}
			else if (this->nowWave == 2)
			{
				if (this->world->nowLevel == 1)
				{
					new InTimer("openIce");
					if(Main::fullTraining)new CallDelay("newElement", 2);
				}
				else if (this->world->nowLevel == 2)
				{
					if (!this->world->menuObject)
					{
						if (Main::fullTraining && !Main::mainClass->saveBoxClass->getBoolValue("Training_92", 12))
						{ 
							this->world->menuObject = new training::Training_92(12);
							this->world->addChild(this->world->menuObject, 99);
							Main::mainClass->saveBoxClass->setValue("Training_92", 12, true);
						}
					}
				}
				else if (this->world->nowLevel == 3)
				{
					new InTimer("openLevin");
					if (Main::fullTraining)new CallDelay("newElement", 4);
				}
			}
			else if (this->nowWave == 3)
			{
				if (this->world->nowLevel == 3)
				{
					//if (!this->world->menuObject)
					//{
					//    this->world->menuObject = new Training_10();
					//    this->world->addChild(this->world->menuObject,99);
					//}
				}
			}
			else if (this->nowWave == 4)
			{
				if (this->world->nowLevel == 1)
				{
					this->world->worldInterface->blockCastIceman = false;
					if (!this->world->menuObject)
					{
						if (!Main::mainClass->saveBoxClass->getBoolValue("Training_5", 6))
						{
							this->world->menuObject = new training::Training_5(6);
							this->world->addChild(this->world->menuObject,99);
							Main::mainClass->saveBoxClass->setValue("Training_5", 6, true);
						}
					}
				}
			}
			else if (this->nowWave == 5)
			{
				if (this->world->nowLevel == 1)
				{
					if (!this->world->menuObject)
					{
						if (!Main::mainClass->saveBoxClass->getBoolValue("Training_8", 1))
						{
							this->world->menuObject = new training::Training_8(1);
							this->world->addChild(this->world->menuObject, 99); 
							Main::mainClass->saveBoxClass->setValue("Training_8",1, true);
						}
					}
				}
				else if (this->world->nowLevel == 2)
				{
					this->world->worldInterface->blockCastAir = false;
					if (!this->world->menuObject)
					{
						if (Main::fullTraining && !Main::mainClass->saveBoxClass->getBoolValue("Training_5", 7))
						{ 
							this->world->menuObject = new training::Training_5(7);
							this->world->addChild(this->world->menuObject, 99);
							Main::mainClass->saveBoxClass->setValue("Training_5", 7, true);
						}
					}
				}
				else if (this->world->nowLevel == 3)
				{
					this->world->worldInterface->blockCastGolem = false;
					if (!this->world->menuObject)
					{
						if (Main::fullTraining && !Main::mainClass->saveBoxClass->getBoolValue("Training_5", 5))
						{ 
							this->world->menuObject = new training::Training_5(5);
							this->world->addChild(this->world->menuObject, 99);
							Main::mainClass->saveBoxClass->setValue("Training_5", 5, true);
						}
					}
				}
			}
		}
		else if (this->nowWave == 1)
		{
			this->world->secondMusicPlay = true;
			this->world->secondMusicCounter = 15;
			//if (Sounds.instance.musicChanel)
			//{
			//    Sounds.instance.musicChanel.soundTransform = new SoundTransform(0, 0);
			//}
		}
		this->world->worldInterface->updateInfo();
		AudioUtil::playSoundWithVol("Snd_world_startWave.mp3", 0.9f);
	}// end function
    void Waves::wavesHandler()
    {
        if (this->listOfReplacement.size() > 0)
        {
			this->i = this->listOfReplacement.size() - 1;
            while (this->i >= 0)
            {
                if (this->listOfReplacement[this->i][0] > 0)
                {
                    this->listOfReplacement[this->i][0]--;
                }
                else
                {
                    if (this->listOfReplacement[this->i][1] != 29 && this->listOfReplacement[this->i][1] != 30)
                    {
						Unit * unit1 = this->world->addUnit(this->listOfReplacement[this->i][1], this->listOfReplacement[this->i][2]);
                        //this->tempObject.replaced = true;
                    }
                    else
                    {
                        int tempObject = this->listOfReplacement[this->i][4];
                        if (this->listOfReplacement[this->i][1] == 29)
                        {
							//Math.random()
                            tempObject = tempObject - ::round(cocos2d::rand_0_1() * Main::mainClass->readXMLClass.listOfEnemiesXML[28][30]);
                            if (tempObject < Main::mainClass->readXMLClass.listOfEnemiesXML[28][31] + 100)
                            {
								tempObject = ::round(cocos2d::rand_0_1() * Main::mainClass->readXMLClass.listOfEnemiesXML[28][31]) + 100;
                            }
                            else if (tempObject > this->world->bezierClass->getPathLength(this->listOfReplacement[this->i][2], 
								this->listOfReplacement[this->i][3]) - Main::mainClass->readXMLClass.listOfEnemiesXML[28][32] - 80)
                            {
                                tempObject = this->world->bezierClass->getPathLength(this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3]) -
									::round(cocos2d::rand_0_1() * Main::mainClass->readXMLClass.listOfEnemiesXML[28][32]) - 80;
                            }
                        }
                        else if (this->listOfReplacement[this->i][1] == 30)
                        {
                            tempObject = tempObject - ::round(std::random() * Main::mainClass->readXMLClass.listOfEnemiesXML[29][30]);
                            if (tempObject < Main::mainClass->readXMLClass.listOfEnemiesXML[29][31] + 100)
                            {
								tempObject = ::round(std::random() * Main::mainClass->readXMLClass.listOfEnemiesXML[29][31]) + 100;
                            }
                            else if (tempObject > this->world->bezierClass->getPathLength(this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3]) - Main::mainClass->readXMLClass.listOfEnemiesXML[29][32] - 80)
                            {
                                tempObject = this->world->bezierClass->getPathLength(this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3]) -
									::round(std::random() * Main::mainClass->readXMLClass.listOfEnemiesXML[29][32]) - 80;
                            }
                        }
						PathPoint tempObject1 = this->world->bezierClass->getPathPoint(tempObject, this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3]);
                        cocos2d::Vec2 point(tempObject1.x, tempObject1.y);
                        this->n = tempObject;
                        while (this->n > Main::mainClass->readXMLClass.listOfEnemiesXML[28][31])
                        {
                            this->j = 0;
                            while (this->j < this->world->listOfUnits.size())
                            {
                                if (this->world->listOfUnits[this->j]->typeUnit == 29 || this->world->listOfUnits[this->j]->typeUnit == 30)
                                {
                                    //if (Point.distance(this->world->listOfUnits[this->j].this_pt, this->tempObject1) < 80)
									if (this->world->listOfUnits[this->j]->this_pt.distance(point)<80)
                                    {
                                        this->n = this->n - 80;
                                        break;
                                    }
                                }
                                j++;
                            }
                            if (this->n == tempObject)
                            {
                                break;
                                //continue;
                            }
                            tempObject = this->n;
                            tempObject1 = this->world->bezierClass->getPathPoint(tempObject, this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3]);
							point = cocos2d::Point(tempObject1.x, tempObject1.y);
                        }
						Unit * unit1 = this->world->addUnit(this->listOfReplacement[this->i][1], this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3], tempObject);
						//this->tempObject = this->world->addUnit(this->listOfReplacement[this->i][1], this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3], this->tempObject);
						unit1->replaced = true;
                    }
                    this->listOfReplacement.remove(this->i);
                }
                i--;
            }
        }

        if (this->world->nowLevel == 15)
        {
            if (this->world->saveBox->getIntValue("complexityLevel") < 4)
            {
                if (this->nowWave == this->maxWaves)
                {
                    if (this->world->viewBoss == 0)
                    {
                        if (this->world->listOfUnits.size() == 0)
                        {
                            this->world->viewBoss = 1;
                            this->world->addUnit(34, 0);
                        }
                        else
                        {
                            return;
                        }
                    }
                    else if (this->world->viewBoss == 1)
                    {
                        return;
                    }
                }
            }
        }

        if (this->waveWork)
        {
            if (this->waveWorkSt1)
            {
                if (this->listOfWaves.size()> 0)
                {
                    if (this->listOfWaves[0].size()> 0)
                    {
						if (this->listOfWaves[0][0].size() > 0)
                        {
							if (this->listOfWaves[0][0][1].size() > 0)
                            {
								if (this->listOfWaves[0][0][1][1].size() > 0)
                                {
                                    if (this->listOfWaves[0][0][1][0].value > 0)
                                    {
										this->listOfWaves[0][0][1][0].value--;
                                    }
									else if (this->listOfWaves[0][0][1][1][0].size() > 0)
                                    {
                                        if (!this->additArr[0][0])
                                        {
                                            this->additArr[0][0] = this->listOfWaves[0][0][1][1][0][2].value;
											Unit * unit1  = this->world->addUnit(this->listOfWaves[0][0][1][1][0][0], 1, this->listOfWaves[0][0][1][1][0][3], this->listOfWaves[0][0][1][1][0][4], this->listOfWaves[0][0][1][1][0][5], this->listOfWaves[0][0][1][1][0][6]);
                                            this->listOfWaves[0][0][1][1][0][1]--;
                                        }
                                        else if (this->additArr[0][0] > 0)
                                        {
                                            this->additArr[0][0]--;
                                        }
                                        else
                                        {
                                            this->additArr[0][0] = this->listOfWaves[0][0][1][1][0][2];
											Unit * unit1 = this->world->addUnit(this->listOfWaves[0][0][1][1][0][0], 1, this->listOfWaves[0][0][1][1][0][3], this->listOfWaves[0][0][1][1][0][4], this->listOfWaves[0][0][1][1][0][5], this->listOfWaves[0][0][1][1][0][6]);
                                            this->listOfWaves[0][0][1][1][0][1]--;
                                        }
                                        if (this->listOfWaves[0][0][1][1][0][1] == 0)
                                        {
                                            this->listOfWaves[0][0][1][1].splice(0, 1);
                                        }
                                    }
                                    else
                                    {
                                        this->waveWorkSt1 = false;
                                        this->additArr[0].clear();
                                        this->listOfWaves[0].splice(0, 1);
                                    }
                                }
                                else
                                {
                                    this->waveWorkSt1 = false;
									this->additArr[0].clear();
                                    this->listOfWaves[0].splice(0, 1);
                                }
                            }
                            else
                            {
                                this->waveWorkSt1 = false;
								this->additArr[0].clear();
                                this->listOfWaves[0].splice(0, 1);
                            }
                        }
                        else
                        {
                            this->waveWorkSt1 = false;
							this->additArr[0].clear();
                            this->listOfWaves[0].splice(0, 1);
                        }
                    }
                    else
                    {
                        this->waveWorkSt1 = false;
						this->additArr[0].clear();
                    }
                }
                else
                {
                    this->waveWorkSt1 = false;
					this->additArr[0].clear();
                }
            }
            if (this->waveWorkSt2)
            {
                if (this->listOfWaves.size() > 1)
                {
					if (this->listOfWaves[1].size() > 0)
                    {
						if (this->listOfWaves[1][0].size() > 0)
                        {
							if (this->listOfWaves[1][0][1].size() > 0)
                            {
								if (this->listOfWaves[1][0][1][1].size() > 0)
                                {
                                    if (this->listOfWaves[1][0][1][0] > 0)
                                    {
                                        this->listOfWaves[1][0][1][0]--;
                                    }
									else if (this->listOfWaves[1][0][1][1][0].size() > 0)
                                    {
                                        if (!this->additArr[1][0])
                                        {
                                            this->additArr[1][0] = this->listOfWaves[1][0][1][1][0][2];
											Unit * unit1 = this->world->addUnit(this->listOfWaves[1][0][1][1][0][0], 2, this->listOfWaves[1][0][1][1][0][3], this->listOfWaves[1][0][1][1][0][4], this->listOfWaves[1][0][1][1][0][5], this->listOfWaves[1][0][1][1][0][6]);
                                             this->listOfWaves[1][0][1][1][0][1]--;
                                        }
                                        else if (this->additArr[1][0] > 0)
                                        {
                                            this->additArr[1][0]--;
                                        }
                                        else
                                        {
                                            this->additArr[1][0] = this->listOfWaves[1][0][1][1][0][2];
											Unit * unit1 = this->world->addUnit(this->listOfWaves[1][0][1][1][0][0], 2, this->listOfWaves[1][0][1][1][0][3], this->listOfWaves[1][0][1][1][0][4], this->listOfWaves[1][0][1][1][0][5], this->listOfWaves[1][0][1][1][0][6]);
                                            this->listOfWaves[1][0][1][1][0][1]--;
                                        }
                                        if (this->listOfWaves[1][0][1][1][0][1] == 0)
                                        {
                                            this->listOfWaves[1][0][1][1].splice(0, 1);
                                        }
                                    }
                                    else
                                    {
                                        this->waveWorkSt2 = false;
                                        this->additArr[1].clear();
                                        this->listOfWaves[1].splice(0, 1);
                                    }
                                }
                                else
                                {
                                    this->waveWorkSt2 = false;
									this->additArr[1].clear();
                                    this->listOfWaves[1].splice(0, 1);
                                }
                            }
                            else
                            {
                                this->waveWorkSt2 = false;
								this->additArr[1].clear();
                                this->listOfWaves[1].splice(0, 1);
                            }
                        }
                        else
                        {
                            this->waveWorkSt2 = false;
							this->additArr[1].clear();
                            this->listOfWaves[1].splice(0, 1);
                        }
                    }
                    else
                    {
                        this->waveWorkSt2 = false;
						this->additArr[1].clear();
                    }
                }
                else
                {
                    this->waveWorkSt2 = false;
					this->additArr[1].clear();
                }
            }
            if (this->waveWorkSt3)
            {
                if (this->listOfWaves.size() > 2)
                {
					if (this->listOfWaves[2].size() > 0)
                    {
						if (this->listOfWaves[2][0].size() > 0)
                        {
							if (this->listOfWaves[2][0][1].size() > 0)
                            {
								if (this->listOfWaves[2][0][1][1].size() > 0)
                                {
                                    if (this->listOfWaves[2][0][1][0] > 0)
                                    {
                                        this->listOfWaves[2][0][1][0]--;
                                        if (this->listOfWaves[2][0][1][0] < 91)
                                        {
                                            if (this->world->viewRockCrash == 0)
                                            {
                                                this->world->viewRockCrash = 1;
                                            }
                                        }
                                    }
									else if (this->listOfWaves[2][0][1][1][0].size() > 0)
                                    {
                                        if (!this->additArr[2][0])
                                        {
                                            this->additArr[2][0] = this->listOfWaves[2][0][1][1][0][2];
											Unit * unit1 = this->world->addUnit(this->listOfWaves[2][0][1][1][0][0], 3, this->listOfWaves[2][0][1][1][0][3], this->listOfWaves[2][0][1][1][0][4], this->listOfWaves[2][0][1][1][0][5], this->listOfWaves[2][0][1][1][0][6]);
                                            this->listOfWaves[2][0][1][1][0][1]--;
                                        }
                                        else if (this->additArr[2][0] > 0)
                                        {
                                            this->additArr[2][0]--;
                                        }
                                        else
                                        {
                                            this->additArr[2][0] = this->listOfWaves[2][0][1][1][0][2];
											Unit * unit1 = this->world->addUnit(this->listOfWaves[2][0][1][1][0][0], 3, this->listOfWaves[2][0][1][1][0][3], this->listOfWaves[2][0][1][1][0][4], this->listOfWaves[2][0][1][1][0][5], this->listOfWaves[2][0][1][1][0][6]);
                                            this->listOfWaves[2][0][1][1][0][1]--;
                                        }
                                        if (this->listOfWaves[2][0][1][1][0][1] == 0)
                                        {
                                            this->listOfWaves[2][0][1][1].splice(0, 1);
                                        }
                                    }
                                    else
                                    {
                                        this->waveWorkSt3 = false;
                                        this->additArr[2].clear();
                                        this->listOfWaves[2].splice(0, 1);
                                    }
                                }
                                else
                                {
                                    this->waveWorkSt3 = false;
									this->additArr[2].clear();
                                    this->listOfWaves[2].splice(0, 1);
                                }
                            }
                            else
                            {
                                this->waveWorkSt3 = false;
								this->additArr[2].clear();
                                this->listOfWaves[2].splice(0, 1);
                            }
                        }
                        else
                        {
                            this->waveWorkSt3 = false;
							this->additArr[2].clear();
                            this->listOfWaves[2].splice(0, 1);
                        }
                    }
                    else
                    {
                        this->waveWorkSt3 = false;
						this->additArr[2].clear();
                    }
                }
                else
                {
                    this->waveWorkSt3 = false;
					this->additArr[2].clear();
                }
            }
            if (!this->waveWorkSt1 && !this->waveWorkSt2 && !this->waveWorkSt3)
            {
                this->waveWork = false;
                if (this->nowWave < this->maxWaves)
                {
                    this->world->worldInterface->container->startWaves->gotoAndStop(1);
                    this->world->worldInterface->container->startWavesStartWavesCase->setMouseEnabled(true);
                    this->world->pointer1->timer = this->listOfWaves[0][0][0];
                    this->world->pointer1->counter = (double)360 / this->listOfWaves[0][0][0];
					this->world->pointer1->fireAnima->setRotation(0);
                    if (this->world->pointer2)
                    {
						this->world->pointer2->fireAnima->setRotation(0);
						this->world->pointer2->counter= this->world->pointer1->counter;
                    }
                    if (this->world->pointer3)
                    {
						this->world->pointer3->fireAnima->setRotation(0);
						this->world->pointer3->counter = this->world->pointer1->counter;
					}
                    if (this->listOfWaves.size() > 0)
                    {
						if (this->listOfWaves[0].size() > 0)
                        {
							if (this->listOfWaves[0][0].size() > 0)
                            {
								if (this->listOfWaves[0][0][1].size() > 0)
                                {
									if (this->listOfWaves[0][0][1][1].size() > 0)
                                    {
                                        if (!this->world->pointer1->isVisible())
                                        {
                                            this->world->pointer1->setVisible(true);
                                            AudioUtil::playSoundWithVol("Snd_world_openMarker.mp3", 0.55f);
                                        }
                                    }
                                }
                            }
                        }
                    }
					if (this->listOfWaves.size() > 1)
                    {
						if (this->listOfWaves[1].size() > 0)
                        {
							if (this->listOfWaves[1][0].size() > 0)
                            {
								if (this->listOfWaves[1][0][1].size() > 0)
                                {
									if (this->listOfWaves[1][0][1][1].size() > 0)
                                    {
                                        if (!this->world->pointer2->isVisible())
                                        {
											this->world->pointer2->setVisible(true);
                                            if (!this->world->pointer1->isVisible())
                                            {
                                                AudioUtil::playSoundWithVol("Snd_world_openMarker.mp3", 0.55f);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
					if (this->listOfWaves.size() > 2)
                    {
						if (this->listOfWaves[2].size() > 0)
                        {
							if (this->listOfWaves[2][0].size() > 0)
                            {
								if (this->listOfWaves[2][0][1].size() > 0)
                                {
									if (this->listOfWaves[2][0][1][1].size() > 0)
                                    {
                                        if (!this->world->pointer3->isVisible() && this->world->viewRockCrash > 0)
                                        {
                                            this->world->pointer3->setVisible(true);
                                            if (!this->world->pointer1->isVisible() && !this->world->pointer2->isVisible())
                                            {
                                                AudioUtil::playSoundWithVol("Snd_world_openMarker.mp3", 0.55f);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (this->nowWave > 0)
        {
            if (this->listOfWaves.size() > 0)
            {
				if (this->listOfWaves[0].size() > 0)
                {
                    if (this->listOfWaves[0][0][0] > 0)
                    {
                        this->listOfWaves[0][0][0]--;
                        if (this->world->pointer1)
                        {
                            if (this->world->pointer1->isVisible())
								this->world->pointer1->round();
                        }
                        if (this->world->pointer2)
                        {
                            if (this->world->pointer2->isVisible())
								this->world->pointer2->round(); 
                        }
                        if (this->world->pointer3)
                        {
                            if (this->world->pointer3->isVisible())
								this->world->pointer3->round(); 
                        }
                    }
                    else
                    {
                        this->startWaves();
                    }
                }
            }
        }
        else if (this->world->worldInterface->lastTime->isVisible())
        {
            if (this->world->worldInterface->getAlpha() == 1)
            {
                if (Main::mainClass->readXMLClass.autoStartCounter > 0)
                {
                    Main::mainClass->readXMLClass.autoStartCounter--;
                    std::setText(this->world->worldInterface->lastTime, int(Main::mainClass->readXMLClass.autoStartCounter / 30) + 1);
                    //this->world->worldInterface->lastTime.setTextFormat(Main::mainClass->boldTextFormat);
                }
				else if (this->world->worldInterface->lastTime->getAlpha()  > 0)
                {
					this->world->worldInterface->lastTime->setAlpha(this->world->worldInterface->lastTime->getAlpha() - 0.2);
                }
                else
                {
					this->world->worldInterface->lastTime->setAlpha(1);
                    this->world->worldInterface->lastTime->setVisible(false); 
                    this->world->removeIndexes(this->world->worldInterface->lastTime,3);
                    this->startWaves();
                }
            }
        }
        return;
    }// end function

}
