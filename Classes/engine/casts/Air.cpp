﻿
#include "Air.h"
#include "engine/World.h"
#include "MainClass.h"
#include "engine/WorldInterface.h"
#include "engine/units/Unit.h"

namespace engine
{

	namespace casts
	{

		Air_mc::Air_mc() : MovieClip("cast/", "Air_mc", "Air_mc"), cont(0), dust1(0), dust2(0), contBlowing(0)
		{
			SET_NODETYPENAME();
 			cont = this->createMovieClipSub("cont",true);
			contBlowing = cont->createMovieClipSub("blowing", true);
			dust1 = this->createMovieClipSub("dust1");
			dust2 = this->createMovieClipSub("dust2");
		};

		//virtual void Air_mc::gotoAndStop(int cur)
		//{
		//	MovieClip::gotoAndStop(cur);
		//	this->clear();
		//	this->cont = new MovieClipSub(this,this->getArmature()->getSlot("cont")->getChildArmature());
		//	this->dust1 = new MovieClipSub(this, this->getArmature()->getSlot("dust1")->getChildArmature());
		//	this->dust2 = new MovieClipSub(this, "dust2" );
		//	dragonBones::Armature * arm = cont->getArmature()->getSlot("blowing")->getChildArmature();
		//	this->contBlowing = new MovieClipSub(cont, arm);
		//	this->cont->gotoAndStop(48);
		//	this->dust1->stop();
		//	this->dust2->stop();
		//	this->dust1->arm->getBone("dust1")->setVisible(false);
		//	this->dust2->arm->getBone("dust2")->setVisible(false);
		//	this->cont->play(0);
		//};
		MoveAir_mc::MoveAir_mc() :MovieClip("cast/", "MoveAir_mc", "MoveAir_mc")
		{
			SET_NODETYPENAME();
		 
			//down = new MovieClip("updown","MoveAir_m");
			//left = new MovieClip("left","MoveAir_m");
			//right = new MovieClip("right","MoveAir_m");
			//up = new MovieClip("updown","MoveAir_m");  
			//up->setScaleX(-1);
			//left->setScaleX(-1);
			down = this->createMovieClipSub("down");
			left = this->createMovieClipSub("left");
			right = this->createMovieClipSub("right");
			up = this->createMovieClipSub("up");

		};
		Air::Air(cocos2d::Point param1, string param2) :container(NULL)
			, world(NULL)
			, direction("none")
			, radius(0)
			, dead(false)
			, openFlag(true)
			, openCounter(0)
			, workFlag(false)
			, liveCounter(0)
			, voiceCounter(10)
			, cameraJitterTimer(5)
			, cameraJitterCounter(0)
			, cameraXOffset(0)
			, cameraYOffset(0)
		{
			this->cameraJitterCounter = this->cameraJitterTimer;
			//	this->addEventListener(Event.ADDED_TO_STAGE, this->init);
			this->this_pt = param1;
			this->direction = param2;
			init();
			return;
		} // end function

		bool Air::init()
		{
			BaseNode::init();
			//      this->removeEventListener (Event.ADDED_TO_STAGE, this->init);
			this->world = Main::mainClass->worldClass;
			this->container = new Air_mc();
			if (this->direction == "left")
			{
				this->container->gotoAndStop(1);
			}
			else if (this->direction == "right")
			{
				this->container->gotoAndStop(2);
			}
			else if (this->direction == "up")
			{
				this->container->gotoAndStop(3);
			}
			else if (this->direction == "down")
			{
				this->container->gotoAndStop(4);
			}
			this->container->cont->gotoAndStop(48);
			this->container->dust1->stop();
			this->container->dust2->stop();
			this->container->dust1->setVisible(false);
			this->container->dust2->setVisible(false);
			this->addChild(this->container);
			this->radius = 125;
			this->liveCounter = Main::mainClass->readXMLClass.airLifeSecXML;
			this->setPosition(this->this_pt);
			//      this->x = this->this_pt.x;
			//      this->y = this->this_pt.y;
			this->container->setAlpha(0.01f);
			this->setPositionY(this->getPositionY() + 200);
			//      this->y = this->y - 200;
			this->setMouseChildren(false);
			this->setMouseEnabled(false);
			this->world->addClasses(this);
			// this->world->addIndexes(this,1); 
			this->world->worldInterface->barInfoManage(this);
			this->world->createAirCounter++;
			if (this->world->createAirCounter == 7)
			{
				this->world->achieveManage("createAir_7_times");
			}
			return true;
		} // end function

		void Air::update(float dt)
		{ 
			if(this->dead){
				this->remove();
				return;
			}
			if (!this->openFlag)
			{
				if (this->voiceCounter > 0)
				{
					this->voiceCounter--;
					if (this->voiceCounter == 0)
					{
						if (this->world->airVoiceTurn == 1)
						{
							this->world->airVoiceTurn = 2;
							AudioUtil::playSoundWithVol ("Snd_air_voice1.mp3", 0.9f);
						}
						else if (this->world->airVoiceTurn == 2)
						{
							this->world->airVoiceTurn = 3;
							AudioUtil::playSoundWithVol ("Snd_air_voice2.mp3", 0.9f);
						}
						else if (this->world->airVoiceTurn == 3)
						{
							this->world->airVoiceTurn = 4;
							AudioUtil::playSoundWithVol ("Snd_air_voice4.mp3", 0.9f);
						}
						else if (this->world->airVoiceTurn == 4)
						{
							this->world->airVoiceTurn = 1;
							AudioUtil::playSoundWithVol ("Snd_air_voice5.mp3", 0.9f);
						}
					}
				}
				if (this->liveCounter > 0)
				{
					this->liveCounter--;
				}
				if (this->liveCounter == 0 && !this->workFlag)
				{
					MovieClip *tempObject = NULL;
					if (this->direction == "left" || this->direction == "right")
					{
						tempObject = new MovieClip(this->world,"cast/","DeathAit1_mc","DeathAit_mc");
						//this->tempObject = new Indexes(new DeathAit1_mc(), 1);
					}
					else if (this->direction == "up")
					{
						tempObject = new MovieClip(this->world, "cast/", "DeathAit2_mc", "DeathAit_mc");
						//this->tempObject = new Indexes(new DeathAit2_mc(), 1);
					}
					else if (this->direction == "down")
					{
						tempObject = new MovieClip(this->world, "cast/", "DeathAit3_mc", "DeathAit_mc");
						//this->tempObject = new Indexes(new DeathAit3_mc(), 1);
					}
					tempObject->container->setScaleX(this->container->getScaleX());
					//tempObject.type = "airDeath";
					tempObject->setPosition( this->this_pt) ;
					AudioUtil::playSound("Snd_air_goodBye.mp3");
					this->kill();
				}
				else if (!this->workFlag)
				{
					this->scan();
				}
				else
				{
					this->attack();
				}
			}
			else
			{
				this->openCounter++;
				if (this->openCounter == 5)
				{
					AudioUtil::playSound("Snd_air_addToWorld.mp3");
				}
				if (this->container->getAlpha() < 1)
				{
					this->container->setAlpha(this->container->getAlpha() + 0.2);
					this->setPositionY(this->getPositionY() - 40);
					//this->y = this->y + 40;
				}
				else
				{
					if (!this->container->dust1->isVisible() && !this->container->dust2->isVisible())
					{
						this->container->dust1->setVisible(true);
						this->container->dust2->setVisible(true);
						this->setPositionY(this->this_pt.y);
						//this->y = this->this_pt.y;
						this->container->setAlpha(1);
					}
					if (this->cameraJitterCounter <= 0)
					{
						if (this->cameraJitterCounter == 0)
						{
							this->cameraJitterCounter = -1; 
							this->world->repairPos(  -movePos.x,-movePos.y); 
							this->movePos = Vec2(0, 0);
							this->openFlag = false;
							//this->world->decoration->earthquakeFlag = true;
							this->shoot_pt = CONVERT_TO_WORLD_POS(this->container->cont->convertToWorldSpace(this->container->cont->getPosition()));
							//this->shoot_pt = this->container->localToGlobal(new Point(this->container->cont.x,this->container->cont.y));
						}
					}
					else
					{
						this->cameraJitterCounter--;
						this->cameraXOffset = cocos2d::rand_0_1() * 2;
						if (cocos2d::rand_0_1() < 0.5)
							this->cameraXOffset = -this->cameraXOffset;
						this->cameraYOffset = cocos2d::rand_0_1() * 2;
						if (cocos2d::rand_0_1() < 0.5)
							this->cameraYOffset = -this->cameraYOffset;
						this->world->repairPos(this->cameraXOffset, this->cameraYOffset);
						this->movePos += Vec2(this->cameraXOffset, this->cameraYOffset);
						//this->world->hint.x = this->world->hint.x + this->tempObject.x;
						//this->world->hint.y = this->world->hint.y + this->tempObject.y;
					}
					if (this->container->cont->currentFrame == 48)
					{
						this->container->cont->gotoAndStop(49);
					}
					else if (this->container->cont->currentFrame == 49)
					{
						//this->container->cont->currentFrame = 1;
						this->container->cont->gotoAndStop(1);
						this->container->contBlowing->stop(); // 						this->container->contBlowing->stop();
						this->container->contBlowing->setVisible(false); // 						this->container->contBlowing->setVisible(false);
					}
				}
			}
			if (!this->dead)
			{
				if (this->container->dust1->isVisible())
				{
					this->container->dust1->tryPlay();
					if(this->container->dust1->currentFrame== this->container->dust1->totalFrames)
					{
							this->container->dust1->gotoAndStop(1);
							this->container->dust1->setVisible(false);
					}
					//this->container->dust1->currentFrame++;
					//if (!this->container->dust1->isPlay() && this->container->dust1->currentFrame < 5)
					//{
					//	this->container->dust1->play(1);
					//}
					//else {
					//	this->container->dust1->gotoAndStop(1);
					//	this->container->dust1->setVisible(false);
					//}

					//if (this->container->dust1->currentFrame < 47)
					//{
					//	this->container->dust1->gotoAndStop(this->container->dust1->currentFrame++);
					//}
					//else
					//{
					//	this->container->dust1->gotoAndStop(1);
					//	this->container->dust1->setVisible(false);
					//}
				}
				if (this->container->dust2->isVisible())
				{
					this->container->dust2->tryPlay();
					if (this->container->dust2->currentFrame == this->container->dust2->totalFrames)
					{
						this->container->dust2->gotoAndStop(1);
						this->container->dust2->setVisible(false);
					}
					//this->container->dust2->currentFrame++;
					//if (!this->container->dust2->isPlay() && this->container->dust2->currentFrame < 5)
					//{
					//	this->container->dust2->play(1);
					//}
					//else {
					//	this->container->dust2->gotoAndStop(1);
					//	this->container->dust2->setVisible(false);
					//}

					//if (this->container->dust2->currentFrame < 47)
					//{
					//	this->container->dust2->gotoAndStop(this->container->dust2->currentFrame++);
					//}
					//else
					//{
					//	//this->container->dust2->currentFrame = 1;
					//	this->container->dust2->gotoAndStop(1);
					//	this->container->dust2->setVisible(false);
					//}
				}
			}
			return;
		} // end function

		void Air::scan()
		{
			this->i = 0;
			while (this->i < this->world->listOfUnits.size())
			{
				if (this->world->listOfUnits[this->i]->readyDamage && this->world->listOfUnits[this->i]->atStaged && !this->world->listOfUnits[this->i]->airFlag)
				{
					float tempObject = this->world->listOfUnits[this->i]->shoot_pt.distance(this->shoot_pt);
					if (tempObject < this->radius)
					{
						if (this->direction == "left" || this->direction == "right")
						{
							if (this->world->listOfUnits[this->i]->shoot_pt.y > this->shoot_pt.y - 30
								&& this->world->listOfUnits[this->i]->shoot_pt.y < this->shoot_pt.y + 30)
							{
								if (this->direction == "left")
								{
									if (this->world->listOfUnits[this->i]->shoot_pt.x < this->shoot_pt.x)
									{
										this->workFlag = true;
										break;
									}
								}
								else if (this->direction == "right")
								{
									if (this->world->listOfUnits[this->i]->shoot_pt.x > this->shoot_pt.x)
									{
										this->workFlag = true;
										break;
									}
								}
							}
						}
						else if (this->direction == "up" || this->direction == "down")
						{
							if (this->world->listOfUnits[this->i]->shoot_pt.x > this->shoot_pt.x - 30
								&& this->world->listOfUnits[this->i]->shoot_pt.x < this->shoot_pt.x + 30)
							{
								if (this->direction == "up")
								{
									if (this->world->listOfUnits[this->i]->shoot_pt.y < this->shoot_pt.y)
									{
										this->workFlag = true;
										break;
									}
								}
								else if (this->direction == "down")
								{
									if (this->world->listOfUnits[this->i]->shoot_pt.y > this->shoot_pt.y)
									{
										this->workFlag = true;
										break;
									}
								}
							}
						}
					}
				}
				i++;
			}
			return;
		} // end function

		void Air::attack()
		{
			if (!this->container->contBlowing->isVisible()) // 			if(!this->container->contBlowing->isVisible())
			{
				this->container->contBlowing->setVisible(true); // 				this->container->contBlowing->setVisible(true);
			}
			else if (this->container->cont->currentFrame < 47)
			{
				
				this->container->cont->tryPlay();
				//this->container->cont->gotoAndStop(this->container->cont->currentFrame);

				this->container->contBlowing->tryPlay();
				//this->container->contBlowing->currentFrame++; // 				this->container->contBlowing->currentFrame++;
				//if (!this->container->contBlowing->isPlay()) {
				//	this->container->contBlowing->play(1);
				//}
				//this->container->contBlowing->gotoAndStop(this->container->contBlowing->currentFrame); // 				this->container->contBlowing->gotoAndStop(this->container->contBlowing->currentFrame);
				if (this->container->cont->currentFrame == 2)
				{
					AudioUtil::playSoundWithVol("Snd_air_blow.mp3", 0.65f);
				}
				else if (this->container->cont->currentFrame > 20)
				{
					this->i = 0;
					while (this->i < this->world->listOfUnits.size())
					{
						if (this->world->listOfUnits[this->i]->atStaged && this->world->listOfUnits[this->i]->readyDamage
							&& !this->world->listOfUnits[this->i]->airFlag && !this->world->listOfUnits[this->i]->teleportFlag)
						{
							float tempObject = this->world->listOfUnits[this->i]->shoot_pt.distance(this->shoot_pt);
							if (tempObject < this->radius)
							{
								if (this->direction == "left" || this->direction == "right")
								{
									if (this->world->listOfUnits[this->i]->shoot_pt.y > this->shoot_pt.y - 30
										&& this->world->listOfUnits[this->i]->shoot_pt.y < this->shoot_pt.y + 30)
									{
										if (this->direction == "left")
										{
											if (this->world->listOfUnits[this->i]->shoot_pt.x < this->shoot_pt.x)
											{
												this->world->listOfUnits[this->i]->setAirSettings("air");
											}
										}
										else if (this->direction == "right")
										{
											if (this->world->listOfUnits[this->i]->shoot_pt.x > this->shoot_pt.x)
											{
												this->world->listOfUnits[this->i]->setAirSettings("air");
											}
										}
									}
								}
								else if (this->direction == "up" || this->direction == "down")
								{
									if (this->world->listOfUnits[this->i]->shoot_pt.x > this->shoot_pt.x - 30
										&& this->world->listOfUnits[this->i]->shoot_pt.x < this->shoot_pt.x + 30)
									{
										if (this->direction == "up")
										{
											if (this->world->listOfUnits[this->i]->shoot_pt.y < this->shoot_pt.y)
											{
												this->world->listOfUnits[this->i]->setAirSettings("air");
											}
										}
										else if (this->direction == "down")
										{
											if (this->world->listOfUnits[this->i]->shoot_pt.y > this->shoot_pt.y)
											{
												this->world->listOfUnits[this->i]->setAirSettings("air");
											}
										}
									}
								}
							}
						}
						i++;
					}
				}
			}
			else
			{
				this->container->cont->gotoAndStop(1);
				this->container->contBlowing->gotoAndStop(1); // 				this->container->contBlowing->gotoAndStop (1);
				this->container->contBlowing->setVisible(false); // 				this->container->contBlowing->setVisible(false);
				this->workFlag = false;
			}
			return;
		} // end function
		void Air::remove() {
			this->world->removeClasses(this);
			this->world->repairPos(-movePos.x, -movePos.y);
			this->movePos = Vec2(0, 0);
			if (this->world->selectObject == this) {
				this->world->selectObject = NULL;
			}
			this->world->removeChild(this);
		}

		void Air::kill()
		{
			if (!this->dead)
			{
				this->dead = true;
			}
			return;
		} // end function

	}
}
