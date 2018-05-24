#include "MainClass.h"
#include "World.h"
#include "Waves.h"
#include "engine/units/Unit_1.h"
using namespace engine::units;
#include "bezier/Bezier.h"
#include "bezier/PathPoint.h"
//#include "bezier/Bezier.h"
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
			int tempObject = this->listOfWaves[0][0][0] / this->world->pointer1->timer;
			//this->tempObject = this->listOfWaves[0][0][0] / this->world->pointer1->timer;
            if (tempObject > 0)
            {
                this->j = std::round(this->tempObject * Main::mainClass->readXMLClass.savingOfTimeCast);
                if (this->world->worldInterface->castGolemCounter > 0 && this->world->worldInterface->castGolemCounter < this->world->worldInterface->castGolemTimer)
                {
                    if (this->j > this->world->worldInterface->castGolemTimer - this->world->worldInterface->castGolemCounter)
                    {
                        this->tempObject1 = new SavedCastTime("golem", this->world->worldInterface->castGolemTimer - this->world->worldInterface->castGolemCounter);
                    }
                    else
                    {
                        this->tempObject1 = new SavedCastTime("golem", this->j);
                    }
                    this->world->worldInterface->addChild(this->tempObject1);
                    this->world->listOfClasses.push(this->tempObject1);
                }
                if (this->world->worldInterface->castIcemanCounter > 0 && this->world->worldInterface->castIcemanCounter < this->world->worldInterface->castIcemanTimer)
                {
                    if (this->j > this->world->worldInterface->castIcemanTimer - this->world->worldInterface->castIcemanCounter)
                    {
                        this->tempObject1 = new SavedCastTime("iceman", this->world->worldInterface->castIcemanTimer - this->world->worldInterface->castIcemanCounter);
                    }
                    else
                    {
                        this->tempObject1 = new SavedCastTime("iceman", this->j);
                    }
                    this->world->worldInterface->addChild(this->tempObject1);
                    this->world->listOfClasses.push(this->tempObject1);
                }
                if (this->world->worldInterface->castAirCounter > 0 && this->world->worldInterface->castAirCounter < this->world->worldInterface->castAirTimer)
                {
                    if (this->j > this->world->worldInterface->castAirTimer - this->world->worldInterface->castAirCounter)
                    {
                        this->tempObject1 = new SavedCastTime("air", this->world->worldInterface->castAirTimer - this->world->worldInterface->castAirCounter);
                    }
                    else
                    {
                        this->tempObject1 = new SavedCastTime("air", this->j);
                    }
                    this->world->worldInterface->addChild(this->tempObject1);
                    this->world->listOfClasses.push(this->tempObject1);
                }
                this->i = 0;
                while (this->i < this->j)
                {
                    this->world->worldInterface->downloadCast();
    		        i++;
                }
                this->tempObject = Math.round(this->tempObject * 20);
                if (this->tempObject > 0)
                {
                    this->world->money = this->world->money + this->tempObject;
                    if (this->world->pointer1)
                    {
                        if (this->world->pointer1->isVisible())
                        {
                            MoneyAdd *tempObject1 = new Moneyadd(this->tempObject);
                            tempObject1->setPosition(this->world->pointer1->getPosition());
                            this->world->addChild( tempObject1);
                        }
                    }
                    if (this->world->pointer2)
                    {
                        if (this->world->pointer2->isVisible())
                        {
                            MoneyAdd * tempObject1 = new MoneyAdd(this->tempObject);
                            tempObject1->setPosition(this->world->pointer2->getPosition());
                            this->world->addChild( tempObject1);
                        }
                    }
                    if (this->world->pointer3)
                    {
                        if (this->world->pointer3->isVisible())
                        {
                            MoneyAdd * tempObject1 = new MoneyAdd(this->tempObject);
                            tempObject1->setPosition(this->world->pointer3->getPosition());
                            //tempObject1.x = this->world->pointer3.x;
                            //tempObject1.y = this->world->pointer3.y;
                            this->world->addChild(tempObject1);
                        }
                    }
                    //Sounds.instance.playSoundWithVol("snd_menu_monetki", 0.95);
                }
                //(this->world->saveBox.gameSave.data.addit_earlyWavesCounter + 1);
                int addit_earlyWavesCounter=this->world->saveBox->setIntValue("addit_earlyWavesCounter")+1;
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
			if (!this->world->worldInterface->container->快->fastCase->buttonMode)
			{
			    this->world->worldInterface->container->快->fastCase->buttonMode = true;
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
		this->world->worldInterface->container->startWaves->startWavesCase.buttonMode = false;
		if (this->world->pointer1->isVisible())
		{ 
		    this->world->pointer1->mouseChildren = false;
		    this->world->pointer1->mouseEnabled = false;
		}
		if (this->world->pointer2)
		{
		    if (this->world->pointer2->isVisible())
		    { 
		        this->world->pointer2->mouseChildren = false;
		        this->world->pointer2->mouseEnabled = false;
		    }
		}
		if (this->world->pointer3)
		{
		    if (this->world->pointer3->isVisible())
		    { 
		        this->world->pointer3->mouseChildren = false;
		        this->world->pointer3->mouseEnabled = false;
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
				//if (this->world->nowLevel == 1)
				//{
				//    new CallDelay("newElement", 1);
				//}
			}
			else if (this->nowWave == 2)
			{
				if (this->world->nowLevel == 1)
				{
					//new InTimer("openIce");
					//new CallDelay("newElement", 2);
				}
				else if (this->world->nowLevel == 2)
				{
					//if (!this->world->menuObject)
					//{
					//    this->world->menuObject = new Training_92(12);
					//    this->world->addChild(this->world->menuObject);
					//}
				}
				else if (this->world->nowLevel == 3)
				{
					//new InTimer("openLevin");
					//new CallDelay("newElement", 4);
				}
			}
			else if (this->nowWave == 3)
			{
				if (this->world->nowLevel == 3)
				{
					//if (!this->world->menuObject)
					//{
					//    this->world->menuObject = new Training_10();
					//    this->world->addChild(this->world->menuObject);
					//}
				}
			}
			else if (this->nowWave == 4)
			{
				if (this->world->nowLevel == 1)
				{
					this->world->worldInterface->blockCastIceman = false;
					//if (!this->world->menuObject)
					//{
					//    this->world->menuObject = new Training_5(6);
					//    this->world->addChild(this->world->menuObject);
					//}
				}
			}
			else if (this->nowWave == 5)
			{
				if (this->world->nowLevel == 1)
				{
					//if (!this->world->menuObject)
					//{
					//    this->world->menuObject = new Training_8(1);
					//    this->world->addChild(this->world->menuObject);
					//}
				}
				else if (this->world->nowLevel == 2)
				{
					//this->world->worldInterface->blockCastAir = false;
					//if (!this->world->menuObject)
					//{
					//    this->world->menuObject = new Training_5(7);
					//    this->world->addChild(this->world->menuObject);
					//}
				}
				else if (this->world->nowLevel == 3)
				{
					//this->world->worldInterface->blockCastGolem = false;
					//if (!this->world->menuObject)
					//{
					//    this->world->menuObject = new Training_5(5);
					//    this->world->addChild(this->world->menuObject);
					//}
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
		//     Sounds.instance.playSoundWithVol("snd_world_startWave", 0.9);
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
                            tempObject = tempObject - std::round(cocos2d::rand_0_1() * Main::mainClass->readXMLClass.listOfEnemiesXML[28][30]);
                            if (tempObject < Main::mainClass->readXMLClass.listOfEnemiesXML[28][31] + 100)
                            {
								tempObject = std::round(cocos2d::rand_0_1() * Main::mainClass->readXMLClass.listOfEnemiesXML[28][31]) + 100;
                            }
                            else if (tempObject > this->world->bezierClass->getPathLength(this->listOfReplacement[this->i][2], 
								this->listOfReplacement[this->i][3]) - Main::mainClass->readXMLClass.listOfEnemiesXML[28][32] - 80)
                            {
                                tempObject = this->world->bezierClass->getPathLength(this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3]) -
									std::round(cocos2d::rand_0_1() * Main::mainClass->readXMLClass.listOfEnemiesXML[28][32]) - 80;
                            }
                        }
                        else if (this->listOfReplacement[this->i][1] == 30)
                        {
                            tempObject = tempObject - std::round(std::random() * Main::mainClass->readXMLClass.listOfEnemiesXML[29][30]);
                            if (tempObject < Main::mainClass->readXMLClass.listOfEnemiesXML[29][31] + 100)
                            {
								tempObject = std::round(std::random() * Main::mainClass->readXMLClass.listOfEnemiesXML[29][31]) + 100;
                            }
                            else if (tempObject > this->world->bezierClass->getPathLength(this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3]) - Main::mainClass->readXMLClass.listOfEnemiesXML[29][32] - 80)
                            {
                                tempObject = this->world->bezierClass->getPathLength(this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3]) -
									std::round(std::random() * Main::mainClass->readXMLClass.listOfEnemiesXML[29][32]) - 80;
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
                                continue;
                            }
                            tempObject = this->n;
                            tempObject1 = this->world->bezierClass->getPathPoint(tempObject, this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3]);
							point = cocos2d::Point(tempObject1.x, tempObject1.y);
                        }
						Unit * unit1 = this->world->addUnit(this->listOfReplacement[this->i][1], this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3], tempObject);
						//this->tempObject = this->world->addUnit(this->listOfReplacement[this->i][1], this->listOfReplacement[this->i][2], this->listOfReplacement[this->i][3], this->tempObject);
                        //this->tempObject.replaced = true;
                    }
                    this->listOfReplacement.remove(this->i);
                }
                i++;
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
                                            (this->listOfWaves[0][0][1][1][0][1] - 1);
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
                                        (this->listOfWaves[1][0][1][0] - 1);
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
                                            (this->additArr[1][0] - 1);
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
                                        (this->listOfWaves[2][0][1][0] - 1);
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
                                            (this->additArr[2][0] - 1);
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
                    this->world->worldInterface->container->startWaves->startWavesCase.buttonMode = true;
                    this->world->pointer1->timer = this->listOfWaves[0][0][0];
                    this->world->pointer1->counter = 360 / this->listOfWaves[0][0][0];
					this->world->pointer1->fireAnima->rotation = 0;
                    if (this->world->pointer2)
                    {
                        this->world->pointer2->fireAnima->rotation = 0;
                    }
                    if (this->world->pointer3)
                    {
                        this->world->pointer3->fireAnima->rotation = 0;
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
                                            //Sounds.instance.playSoundWithVol("snd_world_openMarker", 0.55);
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
                                                //Sounds.instance.playSoundWithVol("snd_world_openMarker", 0.55);
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
                                                //Sounds.instance.playSoundWithVol("snd_world_openMarker", 0.55);
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
                        (this->listOfWaves[0][0][0] - 1);
                        if (this->world->pointer1)
                        {
                            if (this->world->pointer1->isVisible())
                            {
                                if (this->world->pointer1->currentFrame == 1)
                                {
                                    if (this->world->pointer1->mask1->rotation + this->world->pointer1->counter < 0)
                                    {
                                        this->world->pointer1->mask1->rotation = this->world->pointer1->mask1->rotation + this->world->pointer1->counter;
                                        this->world->pointer1->fireAnima->rotation = this->world->pointer1->fireAnima->rotation + this->world->pointer1->counter;
                                    }
                                    else
                                    {
                                        this->tempObject = this->world->pointer1->mask1->rotation + this->world->pointer1->counter;
                                        this->world->pointer1->gotoAndStop(2);
                                        this->world->pointer1->mask2->rotation = this->tempObject;
                                    }
                                }
                                else
                                {
                                    this->world->pointer1->mask2->rotation = this->world->pointer1->mask2->rotation + this->world->pointer1->counter;
                                    this->world->pointer1->fireAnima->rotation = this->world->pointer1->fireAnima->rotation + this->world->pointer1->counter;
                                }
                            }
                        }
                        if (this->world->pointer2)
                        {
                            if (this->world->pointer2->isVisible())
                            {
                                if (this->world->pointer2->currentFrame == 1)
                                {
                                    if (this->world->pointer2->mask1->rotation + this->world->pointer1->counter < 0)
                                    {
                                        this->world->pointer2->mask1->rotation = this->world->pointer2->mask1->rotation + this->world->pointer1->counter;
                                        this->world->pointer2->fireAnima->rotation = this->world->pointer2->fireAnima->rotation + this->world->pointer1->counter;
                                    }
                                    else
                                    {
                                        this->tempObject = this->world->pointer2->mask1->rotation + this->world->pointer1->counter;
                                        this->world->pointer2->gotoAndStop(2);
                                        this->world->pointer2->mask2->rotation = this->tempObject;
                                    }
                                }
                                else
                                {
                                    this->world->pointer2->mask2->rotation = this->world->pointer2->mask2->rotation + this->world->pointer1->counter;
                                    this->world->pointer2->fireAnima->rotation = this->world->pointer2->fireAnima->rotation + this->world->pointer1->counter;
                                }
                            }
                        }
                        if (this->world->pointer3)
                        {
                            if (this->world->pointer3->isVisible())
                            {
                                if (this->world->pointer3->currentFrame == 1)
                                {
                                    if (this->world->pointer3->mask1->rotation + this->world->pointer1->counter < 0)
                                    {
                                        this->world->pointer3->mask1->rotation = this->world->pointer3->mask1->rotation + this->world->pointer1->counter;
                                        this->world->pointer3->fireAnima->rotation = this->world->pointer3->fireAnima->rotation + this->world->pointer1->counter;
                                    }
                                    else
                                    {
                                        this->tempObject = this->world->pointer3->mask1->rotation + this->world->pointer1->counter;
                                        this->world->pointer3->gotoAndStop(2);
                                        this->world->pointer3->mask2->rotation = this->tempObject;
                                    }
                                }
                                else
                                {
                                    this->world->pointer3->mask2->rotation = this->world->pointer3->mask2->rotation + this->world->pointer1->counter;
                                    this->world->pointer3->fireAnima->rotation = this->world->pointer3->fireAnima->rotation + this->world->pointer1->counter;
                                }
                            }
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
            if (this->world->worldInterface->alpha == 1)
            {
                if (Main::mainClass->readXMLClass.autoStartCounter > 0)
                {
                    Main::mainClass->readXMLClass.autoStartCounter--;
                    this->world->worldInterface->lastTime.text = int(Main::mainClass->readXMLClass.autoStartCounter / 30) + 1;
                    this->world->worldInterface->lastTime.setTextFormat(Main::mainClass->boldTextFormat);
                }
                else if (this->world->worldInterface->lastTime->alpha > 0)
                {
                    this->world->worldInterface->lastTime->alpha = this->world->worldInterface->lastTime->alpha - 0.2;
                }
                else
                {
                    this->world->worldInterface->lastTime->alpha = 1;
                    this->world->worldInterface->lastTime->setVisible(false);
                    //this->i = 0;
                    //while (this->i < this->world->listOfIndexes3.size())
                    //{
                    //    
                    //    if (this->world->listOfIndexes3[this->i] == this->world->worldInterface->lastTime)
                    //    {
                    //        this->world->listOfIndexes3.splice(this->i, 1);
                    //        break;
                    //    }
                    //    i++;
                    //}
                    this->startWaves();
                }
            }
        }
        return;
    }// end function

}
