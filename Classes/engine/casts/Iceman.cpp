
#include "BaseHeaders.h"
#include "MainClass.h"
#include "engine/World.h"
#include "Cast.h"
#include "engine/WorldInterface.h"
#include "engine/units/Unit.h"

namespace engine{
	namespace    casts
	{
		Iceman_mc::Iceman_mc() :MovieClip("cast/", "Iceman_mc", "Iceman_mc")
		{
			SET_NODETYPENAME();

		};
		BlowIce_mc::BlowIce_mc() :MovieClip("cast/", "BlowIce_mc", "BlowIce_mc")
		{
			SET_NODETYPENAME();

		};

		Iceman::Iceman(cocos2d::Point param1, int param2, int param3, bool param4) :container(NULL), world(NULL), direction("none"), speedK(0), speedKSave(0), radius(0)
			, roadMap(0), dead(false), blow(0), liveCounter(0), voiceCounter(10), rotationTimer(4), brother(NULL), roadAnimaTimer(7), roadAnimaCounter(0)
		{
			//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
			this->this_pt = param1;
			this->road = param2;
			this->movePhase = param3;
			this->openFlag = param4;
			init();
			return;
		}// end function

		bool  Iceman::init()
		{
			BaseNode::init();
			//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
			this->world = Main::mainClass->worldClass;
			this->container = new Iceman_mc();//MovieClip("cast/","Iceman_mc","Iceman_mc");// new Iceman_mc();
			this->container->stop();
			this->addChild(this->container);
			this->speedKSave = Main::mainClass->readXMLClass.castIcemanSpeedXML;
			this->speedK = Main::mainClass->readXMLClass.castIcemanSpeedXML;
			this->radius = 30;
			this->liveCounter = Main::mainClass->readXMLClass.castIcemanLifeTimerXML;
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
					this->container->setScaleX(this->container->getScaleX() * -1);
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
				this->container->setAlpha(0);
				this->blow = new BlowIce_mc();//MovieClip("cast/","BlowIce_mc","BlowIce_mc");// new BlowIce_mc();
				this->blow->stop();
				this->addChild(this->blow);
				this->setPosition(Vec2(this->getPositionX() + 84, this->getPositionY() + 238));
				//this->x = this->x + 84;
				//this->y = this->y + 238;
			}
			this->setMouseChildren(false);
			this->setMouseEnabled(false);
			this->world->addClasses(this);
			//this->world->listOfIndexes1.push(this);
			if (!this->world->selectObject)
			{
				this->world->worldInterface->barInfoManage(this);
			}
			if (!this->brother)
			{
				this->world->createIcemanCounter++;
				if (this->world->createIcemanCounter == 15)
				{
					this->world->achieveManage("createIceman_15_times");
				}
			}
			return true;
		}// end function

		void  Iceman::update(float dt)
		{
			MovieClip * tempObject = NULL;
			if (!this->openFlag)
			{
				this->soundTimerManageMove(true);
				if (this->liveCounter > 0)
				{
					this->liveCounter--;
				}
				if (this->liveCounter == 0)
				{ 
					if (this->direction == "left")
					{
						tempObject = new MovieClip(this->world, "cast/", "IcemanHorisontDeath_mc", "IcemanHorisontDeath_mc");
						//this->tempObject = new Indexes(new IcemanHorisontDeath_mc(), 2);
						tempObject->speedX = this->speedK * -1;
					}
					else if (this->direction == "right")
					{
						tempObject = new MovieClip(this->world, "cast/", "IcemanHorisontDeath_mc", "IcemanHorisontDeath_mc");
						//tempObject = new Indexes(new IcemanHorisontDeath_mc(), 2);
						tempObject->speedX = this->speedK;
					}
					else if (this->direction == "up")
					{
						tempObject = new MovieClip(this->world, "cast/", "IcemanVerticalDeath_mc", "IcemanVerticalDeath_mc");
						//tempObject = new Indexes(new IcemanVerticalDeath_mc(), 2);
						tempObject->speedY = this->speedK * -1;
					}
					else if (this->direction == "down")
					{
						tempObject = new MovieClip(this->world, "cast/", "IcemanHorisontDeath_mc", "IcemanHorisontDeath_mc");
						//this->tempObject = new Indexes(new IcemanHorisontDeath_mc(), 2);
						tempObject->speedY = this->speedK;
					}
					else
					{
						tempObject = new MovieClip(this->world, "cast/", "IcemanHorisontDeath_mc", "IcemanHorisontDeath_mc");
						//this->tempObject = new Indexes(new IcemanHorisontDeath_mc(), 2);
					}
					//tempObject->type = "icemanDeath";
					tempObject->setScaleX(this->container->getScaleX());
					tempObject->setPositionX(this->container->getPositionX());
					//tempObject->container.x = this->container->x;
					tempObject->setPosition(this->this_pt);
					//tempObject->x = this->this_pt.x;
					//tempObject->y = this->this_pt.y;
					this->kill();
					return;
				}
				else
				{
					if (this->voiceCounter > 0)
					{
						this->voiceCounter--;
						if (this->voiceCounter == 0)
						{
							if (this->world->icemanVoiceTurn == 1)
							{
								this->world->icemanVoiceTurn = 2;
								//Sounds.instance.playSoundWithVol("snd_iceman_voice2", 0.5);
							}
							else if (this->world->icemanVoiceTurn == 2)
							{
								this->world->icemanVoiceTurn = 3;
								//Sounds.instance.playSoundWithVol("snd_iceman_voice3", 0.5);
							}
							else if (this->world->icemanVoiceTurn == 3)
							{
								this->world->icemanVoiceTurn = 4;
								//Sounds.instance.playSoundWithVol("snd_iceman_voice4", 0.5);
							}
							else if (this->world->icemanVoiceTurn == 4)
							{
								this->world->icemanVoiceTurn = 1;
								//Sounds.instance.playSoundWithVol("snd_iceman_voice5", 0.5);
							}
						}
					}
					if (this->roadAnimaCounter < this->roadAnimaTimer)
					{
						this->roadAnimaCounter++;
					}
					else
					{
						this->roadAnimaCounter = 0;
						tempObject = new MovieClip(this->world, "cast/", "IceRoad_mc", "IceRoad_mc");
						//tempObject = new Indexes(new IceRoad_mc(), 1);
						tempObject->setPosition(this->this_pt);
						//tempObject.x = this->this_pt.x;
						//tempObject.y = this->this_pt.y;
						//this->world->setChildIndex(tempObject, (this->world->getChildIndex(this) - 1));
						//tempObject->setZOrder(tempObject->getZOrder()-1);
						if (this->direction == "left")
						{
						}
						else if (this->direction == "right")
						{
							tempObject->setScaleX(tempObject->getScaleX() * -1);
						}
						else if (this->direction == "up")
						{
							//tempObject->runAction(RotateBy::create(0, 90));
							tempObject->setRotation(tempObject->getRotation() + 90);
							//this->tempObject->container.rotation = this->tempObject.container.rotation + 90;
						}
						else if (this->direction == "down")
						{
							tempObject->setRotation(tempObject->getRotation() + 270);
							//this->tempObject.container.rotation = this->tempObject.container.rotation + 270;
							tempObject->setPositionX(tempObject->getPositionX() - 10);
						}
					}
					this->moveHandler();
					this->attack();
					if (this->direction == "left" || this->direction == "right")
					{
						if (this->container->currentFrame < 50)
						{
							this->container->tryPlay();
                            //this->container->gotoAndStop((this->container->currentFrame + 1));
						}
						else
						{
							this->container->gotoAndStop(1);
						}
					}
					else if (this->direction == "up")
					{
						if (this->container->currentFrame < this->container->totalFrames)
						{
							this->container->tryPlay();
                            //this->container->gotoAndStop((this->container->currentFrame + 1));
						}
						else
						{
							this->container->gotoAndStop(101);
						}
					}
					else if (this->direction == "down")
					{
						if (this->container->currentFrame < 100)
						{
							this->container->tryPlay();
                            //this->container->gotoAndStop((this->container->currentFrame + 1));
						}
						else
						{
							this->container->gotoAndStop(51);
						}
					}
				}
				if (this->blow)
				{
					if (this->blow->currentFrame < this->blow->totalFrames)
					{
						this->blow->tryPlay();
                        //this->blow->gotoAndStop((this->blow->currentFrame + 1));
						this->container->setAlpha(this->container->getAlpha() + (float)1 / this->blow->totalFrames);
					}
					else
					{
						this->container->setAlpha(1);
						this->removeChild(this->blow);
						this->blow = NULL;
					}
				}
			}
			else if (abs(this->getPositionX() - this->this_pt.x) > 1 || std::abs(this->getPositionY() - this->this_pt.y) > 1)
			{
				this->setPosition(Vec2(this->getPositionX() - 8.4, this->getPositionY() - 23.8));
				//this->x = this->x - 8.4;
				//this->y = this->y - 23.8;
			}
			else
			{
				this->openFlag = false;
				if (this->getPositionX() != this->this_pt.x)
				{
					this->setPositionX(this->this_pt.x);
				}
				if (this->getPositionY() != this->this_pt.y)
				{
					this->setPositionY(this->this_pt.y);
				}
				this->moveHandler();
			}
			return;
		}// end function

		bool  Iceman::moveHandler()
		{
			Common::Array<cocos2d::Point> &roadMap = *this->roadMap;
			if (this->this_pt.x == roadMap[this->movePhase].x)
			{
				if (this->this_pt.y >= roadMap[this->movePhase].y)
				{
					this->setPositionY(this->getPositionY() - this->speedK);
					if (this->getPositionY() <= roadMap[this->movePhase].y)
					{
						float tempObject = this->getPositionY();
						this->setPositionY(roadMap[this->movePhase].y);
						this->bifurcation();
						this->movePhase++;
						if (this->movePhase < roadMap.size())
						{
							if (tempObject < roadMap[this->movePhase].y)
							{
								this->speedK = roadMap[this->movePhase].y - tempObject;
								return this->moveHandler();
							}
						}
						else
						{
							this->kill();
							return true;
						}
					}
					else if (this->speedK != this->speedKSave)
					{
						this->speedK = this->speedKSave;
					}
				}
				else
				{
					this->setPositionY(this->getPositionY() + this->speedK);
					//this->y = this->y + this->speedK;
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
								return this->moveHandler();
							}
						}
						else
						{
							this->kill();
							return true;
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
					if (this->getPositionX() <= roadMap[this->movePhase].x)
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
								return this->moveHandler();
							}
						}
						else
						{
							this->kill();
							return true;
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
							if (tempObject > roadMap[this->movePhase].x)
							{
								this->speedK = roadMap[this->movePhase].x - tempObject;
								return this->moveHandler();
							}
						}
						else
						{
							this->kill();
							return true;
						}
					}
					else if (this->speedK != this->speedKSave)
					{
						this->speedK = this->speedKSave;
					}
				}
			}
			this->directionManage();
			this->this_pt = this->getPosition();// cocos2d::Point(this->x, this->y);
			if (this->movePhase <  roadMap.size())
			{
				if (roadMap[this->movePhase].x == roadMap[(this->movePhase - 1)].x)
				{
					if (roadMap[this->movePhase].y > roadMap[(this->movePhase - 1)].y)
					{
						float tempObject = roadMap[(this->movePhase - 1)].y + (roadMap[this->movePhase].y - roadMap[(this->movePhase - 1)].y) * 0.75;
						if (this->this_pt.y > tempObject)
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
			return false;
		}// end function

		void  Iceman::directionManage()
		{
			if (this->getPositionX() > this->this_pt.x)
			{
				if (this->direction != "right")
				{
					this->direction = "right";
					if (this->container->getScaleX() < 0)
					{
						this->container->setScaleX(this->container->getScaleX() * -1);
					}
					if (this->container->currentFrame > 50)
					{
						this->container->gotoAndStop(this->container->currentFrame - 50);
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
					}
					if (this->container->currentFrame > 50)
					{
						if (this->container->currentFrame < 101)
						{
							this->container->gotoAndStop(this->container->currentFrame - 50);
						}
						else if (this->container->currentFrame > 100)
						{
							this->container->gotoAndStop(this->container->currentFrame - 100);
						}
					}
				}
			}
			if (this->getPositionY() > this->this_pt.y)
			{
				if (this->direction != "down")
				{
					this->direction = "down";
					if (this->container->currentFrame < 51)
					{
						this->container->gotoAndStop(this->container->currentFrame + 50);
					}
					else if (this->container->currentFrame > 100)
					{
						this->container->gotoAndStop(this->container->currentFrame - 50);
					}
				}
			}
			else if (this->getPositionY() < this->this_pt.y)
			{
				if (this->direction != "up")
				{
					this->direction = "up";
					if (this->container->currentFrame < 51)
					{
						this->container->gotoAndStop(this->container->currentFrame + 100);
					}
					else if (this->container->currentFrame < 101)
					{
						this->container->gotoAndStop(this->container->currentFrame + 50);
					}
					if (this->container->getScaleX() < 0)
					{
						if (this->container->getPositionX() != 4)
						{
							this->container->setPositionX(4);
						}
					}
				}
			}
			return;
		}// end function

		void  Iceman::scanNextTurn()
		{
			Common::Array<cocos2d::Point> &roadMap = *this->roadMap;
			if (this->movePhase < (roadMap.size() - 1))
			{
				if (this->movePhase < roadMap.size())
				{
					if (roadMap[this->movePhase].x > roadMap[(this->movePhase + 1)].x)
					{
						if (this->container->getScaleX() > 0)
						{
							this->container->setScaleX(this->container->getScaleX() * -1);
							if (this->container->getPositionX() != 4)
							{
								this->container->setPositionX(4);
							}
						}
					}
					else if (roadMap[this->movePhase].x < roadMap[(this->movePhase + 1)].x)
					{
						if (this->container->getScaleX() < 0)
						{
							this->container->setScaleX(this->container->getScaleX() * -1);
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
								this->container->setScaleX(this->container->getScaleX()* -1);
								if (this->container->getPositionX() != 4)
								{
									this->container->setPositionX(4);
								}
							}
						}
						else if (roadMap[this->movePhase].x < roadMap[this->movePhase + 2].x)
						{
							if (this->container->getScaleX() < 0)
							{
								this->container->setScaleX(this->container->getScaleX() * -1);
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

		void  Iceman::attack()
		{
			this->i = this->world->listOfUnits.size() - 1;
			while (this->i >= 0)
			{
				if (this->world->listOfUnits[this->i]->readyDamage && this->world->listOfUnits[this->i]->atStage()
					&& !this->world->listOfUnits[this->i]->icemanFlag && !this->world->listOfUnits[this->i]->teleportFlag
					&& (this->world->listOfUnits[this->i]->icemanResist > 0 || this->world->listOfUnits[this->i]->typeUnit == 24))
				{
					if (this->world->listOfUnits[this->i]->shoot_pt.distance(this->this_pt) < this->radius)
					{
						this->world->listOfUnits[this->i]->icemanFlag = true;
						if (this->world->listOfUnits[this->i]->typeUnit != 24)
						{
							this->world->listOfUnits[this->i]->icemanCounter = ::round(Main::mainClass->readXMLClass.castIcemanFreezTimerXML * this->world->listOfUnits[this->i]->icemanResist);
						}
						else
						{
							this->world->listOfUnits[this->i]->icemanCounter = Main::mainClass->readXMLClass.castIcemanFreezTimerXML;
						}
						//Sounds.instance.playSoundWithVol("snd_iceman_freezes", 0.5);
						this->world->icemanSlowdownEnemiesCounter++;
						int addit_icemanSlowdownEnemiesCounter = this->world->saveBox->getIntValue("addit_icemanSlowdownEnemiesCounter") + 1;
						this->world->saveBox->setValue("addit_icemanSlowdownEnemiesCounter", addit_icemanSlowdownEnemiesCounter);
						if (this->world->icemanSlowdownEnemiesCounter == 75)
						{
							this->world->achieveManage("icemanSlowdown_75_enemies");
						}
						if (addit_icemanSlowdownEnemiesCounter == 500)
						{
							this->world->achieveManage("icemanSlowdown_500_enemies");
						}
					}
				}
				i--;
			}
			return;
		}// end function

		void  Iceman::bifurcation()
		{
			if (this->movePhase < (roadMap->size() - 1))
			{
				Common::Array<cocos2d::Point> & roadMap = *this->roadMap;
				Iceman *tempObject1 = NULL;
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
									tempObject1 = new Iceman(roadMap[this->movePhase], this->i, (this->j + 1), false);
									this->brother = tempObject1;
									tempObject1->brother = this;
									this->world->addChild(tempObject1);
									tempObject1->container->setScaleX(this->container->getScaleX());
									tempObject1->container->setPositionX(this->container->getPositionX());
									tempObject1->container->gotoAndStop(this->container->currentFrame);
									tempObject1->liveCounter = this->liveCounter;
									tempObject1->voiceCounter = 0;
									this->world->worldInterface->barInfoView();
									break;
								}
								j--;
							}
						}
						else if (this->i == 2)
						{
							this->j = this->world->map.road2.size() - 2;
							while (this->j >= 0)
							{
								if (this->world->map.road2[this->j].x == roadMap[this->movePhase].x && this->world->map.road2[this->j].y == roadMap[this->movePhase].y
									&& (this->world->map.road2[(this->j + 1)].x != roadMap[(this->movePhase + 1)].x
									|| this->world->map.road2[(this->j + 1)].y != roadMap[(this->movePhase + 1)].y))
								{
									tempObject1 = new Iceman(roadMap[this->movePhase], this->i, (this->j + 1), false);
									this->brother = tempObject1;
									tempObject1->brother = this;
									this->world->addChild(tempObject1);
									tempObject1->container->setScaleX(this->container->getScaleX());
									tempObject1->container->setPositionX(this->container->getPositionX());
									tempObject1->container->gotoAndStop(this->container->currentFrame);
									tempObject1->liveCounter = this->liveCounter;
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

		void  Iceman::soundTimerManageMove(bool param1)
		{
			//if (param1)
			//{
			//    if (!this->soundTimerMove && !this->world->menuObject)// && Sounds.instance.soundOn
			//    {
			//        //this->soundTimerMove = new Timer(Sounds.instance.playSoundWithVol("snd_iceman_move", 0.28), 99999);
			//        //this->soundChannelMove = Sounds.instance.soundChanel;
			//        //this->soundTimerMove.addEventListener(TimerEvent.TIMER, this->soundTimerMoveFunk);
			//        //this->soundTimerMove.start();
			//    }
			//}
			//else if (this->soundTimerMove)
			//{
			//    //this->world->listOfSoundChannels.push(this->soundChannelMove);
			//    //this->soundTimerMove.removeEventListener(TimerEvent.TIMER, this->soundTimerMoveFunk);
			//    //this->soundTimerMove.stop();
			//    //this->soundTimerMove = null;
			//}
			return;
		}// end function

		void  Iceman::soundTimerMoveFunk()//(event:TimerEvent) 
		{
			if (this->dead && Main::mainClass->worldClass)
			{
				if (!Main::mainClass->worldClass->menuObject)
				{
					//Sounds.instance.playSoundWithVol("snd_iceman_move", 0.28);
					//this->soundChannelMove = Sounds.instance.soundChanel;
				}
				else
				{
					this->soundTimerManageMove(false);
				}
			}
			else
			{
				this->soundTimerManageMove(false);
			}
			return;
		}// end function

		void  Iceman::kill()
		{
			if (!this->dead)
			{
				this->dead = true;
				this->soundTimerManageMove(false);
				//this->i = 0;
				//while (this->i < this->world->listOfIndexes1.length)
				//{ 
				//    if (this->world->listOfIndexes1[this->i] == this)
				//    {
				//        this->world->listOfIndexes1.splice(this->i, 1);
				//        break;
				//    }
				//    i++;
				//}
				if (this->world->selectObject == this) {
					this->world->selectObject = NULL;
				}
				this->world->removeClasses(this);
				this->world->removeChild(this);
			}
			return;
		}// end function

	}
}

