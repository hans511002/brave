#include "GetSphere.h"
#include "CastSphere.h"
#include "engine/World.h" 
#include "MainClass.h"

namespace engine{


	CastSphere::CastSphere() :container(NULL), fireCount(0), iceCount(0), stoneCount(0), levinCount(0), getAllCount(0), world(NULL), radius(0), additAnamation(NULL), dead(0), liveCounter(0)
	{
		//this->getAllForm = [false, false, false, false];
		this->getAllForm[0] = false;
		this->getAllForm[1] = false;
		this->getAllForm[2] = false;
		this->getAllForm[3] = false;
		//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
		init();
		return;
	}// end function

	bool CastSphere::init()
	{
		BaseNode::init();
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		this->world = Main::mainClass->worldClass;
		this->radius = this->world->getSphere->myRadius;
		this->setPosition(this->world->mouseX, this->world->mouseY);
		if (this->world->getSphere->type == "holder")
		{
			if (this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
			{
				this->sphereType = "fire";
				this->fireCount = this->world->getSphere->fireCount;
				//Sounds.instance.playSoundWithVol("snd_cast_fire", 0.7);
				this->world->castFireCounter++;
				int addit_castFireCounter = this->world->saveBox->getIntValue("addit_castFireCounter");
				this->world->saveBox->setValue("addit_castFireCounter", addit_castFireCounter + 1);
			}
			else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
			{
				this->sphereType = "ice";
				this->iceCount = this->world->getSphere->iceCount;
				//Sounds.instance.playSoundWithVol("snd_cast_ice", 0.7);
				this->world->castIceCounter++;
				this->world->saveBox->setValue("addit_castStoneCounter", this->world->castIceCounter);
			}
			else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount == 0)
			{
				this->sphereType = "stone";
				this->stoneCount = this->world->getSphere->stoneCount;
				//Sounds.instance.playSound("snd_cast_stone");
				this->world->castStoneCounter++;
				this->world->saveBox->setValue("addit_castStoneCounter", this->world->castStoneCounter);
			}
			else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount > 0)
			{
				this->sphereType = "levin";
				this->levinCount = this->world->getSphere->levinCount;
				//Sounds.instance.playSoundWithVol("snd_cast_levin", 0.8);
				this->world->castLevinCounter++;
				this->world->saveBox->setValue("addit_castLevinCounter", this->world->castLevinCounter);
			}
			else
			{
				this->fireCount = this->world->getSphere->fireCount;
				this->iceCount = this->world->getSphere->iceCount;
				this->stoneCount = this->world->getSphere->stoneCount;
				this->levinCount = this->world->getSphere->levinCount;
				if (this->fireCount > 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount == 0)
				{
					this->sphereType = "fireIce";
					//Sounds.instance.playSoundWithVol("snd_cast_fireIce", 0.9);
					this->world->castFireCounter++;
					this->world->castIceCounter++;
					this->world->saveBox->setValue("addit_castFireCounter", this->world->castFireCounter);
					this->world->saveBox->setValue("addit_castIceCounter", this->world->castIceCounter);
				}
				else if (this->fireCount > 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount == 0)
				{
					this->sphereType = "fireStone";
					//Sounds.instance.playSound("snd_cast_fireStone");
					this->world->castFireCounter++;
					this->world->castStoneCounter++;
					this->world->saveBox->setValue("addit_castFireCounter", this->world->castFireCounter);
					this->world->saveBox->setValue("addit_castStoneCounter", this->world->castStoneCounter);
				}
				else if (this->fireCount > 0 && this->iceCount == 0 && this->stoneCount == 0 && this->levinCount > 0)
				{
					this->sphereType = "fireLevin";
					//Sounds.instance.playSoundWithVol("snd_cast_fireLevin", 0.7);
					this->world->castFireCounter++;
					this->world->castLevinCounter++;
					this->world->saveBox->setValue("addit_castFireCounter", this->world->castFireCounter);
					this->world->saveBox->setValue("addit_castLevinCounter", this->world->castLevinCounter);
				}
				else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount > 0 && this->levinCount == 0)
				{
					this->sphereType = "iceStone";
					//Sounds.instance.playSound("snd_cast_iceStone");
					this->world->castIceCounter++;
					this->world->castStoneCounter++;
					this->world->saveBox->setValue("addit_castIceCounter", this->world->castIceCounter);
					this->world->saveBox->setValue("addit_castStoneCounter", this->world->castStoneCounter);
				}
				else if (this->fireCount == 0 && this->iceCount > 0 && this->stoneCount == 0 && this->levinCount > 0)
				{
					this->sphereType = "iceLevin";
					//Sounds.instance.playSoundWithVol("snd_cast_iceLevin", 0.9);
					this->world->castIceCounter++;
					this->world->castLevinCounter++;
					this->world->saveBox->setValue("addit_castIceCounter", this->world->castIceCounter);
					this->world->saveBox->setValue("addit_castLevinCounter", this->world->castLevinCounter);
				}
				else if (this->fireCount == 0 && this->iceCount == 0 && this->stoneCount > 0 && this->levinCount > 0)
				{
					this->sphereType = "stoneLevin";
					//Sounds.instance.playSoundWithVol("snd_cast_stoneLevin", 0.9);
					this->world->castStoneCounter++;
					this->world->castLevinCounter++;
					this->world->saveBox->setValue("addit_castStoneCounter", this->world->castStoneCounter);
					this->world->saveBox->setValue("addit_castLevinCounter", this->world->castLevinCounter);
				}
				else
				{
					this->sphereType = "getAllLittle";
					//Sounds.instance.playSoundWithVol("snd_cast_getAllLittle", 0.9);
					this->world->castGetAllCounter++;
					this->world->saveBox->setValue("addit_castGetAllCounter", this->world->castGetAllCounter);
				}
			}
		}
		else if (this->world->getSphere->type == "getAll")
		{
			this->sphereType = "getAll";
			this->getAllCount = this->world->getSphere->getAllCount;
			//Sounds.instance.playSoundWithVol("snd_cast_getAll", 0.95);
		}
		if (this->world->saveBox->getIntValue("addit_castFireCounter") == 150)
		{
			this->world->achieveManage("castFire_150_times");
		}
		if (this->world->saveBox->getIntValue("addit_castIceCounter") == 150)
		{
			this->world->achieveManage("castIce_150_times");
		}
		if (this->world->saveBox->getIntValue("addit_castStoneCounter") == 150)
		{
			this->world->achieveManage("castStone_150_times");
		}
		if (this->world->saveBox->getIntValue("addit_castLevinCounter") == 150)
		{
			this->world->achieveManage("castLevin_150_times");
		}
		if (this->world->castGetAllCounter == 10)
		{
			this->world->achieveManage("castGetAll_10_times");
		}
		if (this->world->saveBox->getIntValue("addit_castGetAllCounter") == 100)
		{
			this->world->achieveManage("castGetAll_100_times");
		}
		this->this_pt = this->getPosition();// new Point(this->x, this->y); 
		this->setMouseChildren(false);
		this->setMouseEnabled(false);
		if (this->sphereType == "fire")
		{
			this->container = new CastFire_mc();
		}
		else if (this->sphereType == "ice")
		{
			this->container = new CastIce_mc();
		}
		else if (this->sphereType == "stone")
		{
			this->container = new CastStone_mc();
			this->container->setVisible(false);
			this->container->myCounter = 3;
		}
		else if (this->sphereType == "levin")
		{
			this->container = new CastLevin_mc();
		}
		else if (this->sphereType == "fireIce")
		{
			this->container = new CastFireIce_mc();
		}
		else if (this->sphereType == "fireStone")
		{
			this->container = new CastFireStone_mc();
		}
		else if (this->sphereType == "fireLevin")
		{
			this->container = new CastFireLevin_mc();
		}
		else if (this->sphereType == "iceStone")
		{
			this->container = new CastIceStone_mc();
		}
		else if (this->sphereType == "iceLevin")
		{
			this->container = new CastIceLevin_mc();
		}
		else if (this->sphereType == "stoneLevin")
		{
			this->container = new CastStoneLevin_mc();
		}
		else if (this->sphereType == "getAllLittle")
		{
			this->container = new CastGetAllLittle_mc();
			this->container->setScale(0.8f);
		}
		else if (this->sphereType == "getAll")
		{
			this->liveCounter = Main::mainClass->readXMLClass.getAllLiveTimer;
			if (this->getAllCount < 3)
			{
				this->container = new CastGetAllLittle_mc();
			}
			else
			{
				this->container = new CastGetAll_mc();
				if (this->getAllCount == 3)
				{
					this->additAnamation = new CastGetAllSwamp_mc();
					this->additAnamation->stop();
					this->additAnamation->setPosition(this->getPosition());
					this->additAnamation->setMouseChildren(false);
					this->additAnamation->setMouseEnabled(false);
					this->world->addChild(this->additAnamation, 2);
					//this->world->listOfIndexes0.push(this->additAnamation);
					float tempObject = 1000;
					if (this->world->map.road1.size())
					{
						this->i = 0;
						while (this->i < this->world->map.allPointsRoad1.size())
						{
							float tempObject1 = this->this_pt.distance(this->world->map.allPointsRoad1[this->i]);
							if (tempObject1 < tempObject)
							{
								tempObject = tempObject1;
								this->setPosition(this->world->map.allPointsRoad1[this->i]);
								//this->x = this->world->map.allPointsRoad1[this->i].x;
								//this->y = this->world->map.allPointsRoad1[this->i].y;
							}
							i++;
						}
					}
					if (this->world->map.road2.size())
					{
						this->i = 0;
						while (this->i < this->world->map.allPointsRoad2.size())
						{
							float tempObject1 = this->this_pt.distance(this->world->map.allPointsRoad2[this->i]);
							if (tempObject1 < tempObject)
							{
								tempObject = tempObject1;
								this->setPosition(this->world->map.allPointsRoad2[this->i]);
								//this->x = this->world->map.allPointsRoad2[this->i].x;
								//this->y = this->world->map.allPointsRoad2[this->i].y;
							}
							i++;
						}
					}
					if (this->world->map.road3.size())
					{
						this->i = 0;
						while (this->i < this->world->map.allPointsRoad3.size())
						{
							float tempObject1 = this->this_pt.distance(this->world->map.allPointsRoad3[this->i]);
							if (tempObject1 < tempObject)
							{
								tempObject = tempObject1;
								this->setPosition(this->world->map.allPointsRoad3[this->i]);
								//this->x = this->world->map.allPointsRoad3[this->i].x;
								//this->y = this->world->map.allPointsRoad3[this->i].y;
							}
							i++;
						}
					}
					this->this_pt = this->getPosition();// new Point(this->x, this->y);
					this->i = 0;
					while (this->i < this->world->map.allPointsRoad1.size())
					{
						if (!this->getAllForm[0])
						{
							if (this->this_pt.x - this->world->map.allPointsRoad1[this->i].x >= 22 && this->this_pt.x - this->world->map.allPointsRoad1[this->i].x <= 45 && (this->this_pt.y >= this->world->map.allPointsRoad1[this->i].y - 22 && this->this_pt.y <= this->world->map.allPointsRoad1[this->i].y + 22))
							{
								this->getAllForm[0] = true;
							}
						}
						if (!this->getAllForm[1])
						{
							if (this->world->map.allPointsRoad1[this->i].x - this->this_pt.x >= 22 && this->world->map.allPointsRoad1[this->i].x - this->this_pt.x <= 45 && (this->this_pt.y >= this->world->map.allPointsRoad1[this->i].y - 22 && this->this_pt.y <= this->world->map.allPointsRoad1[this->i].y + 22))
							{
								this->getAllForm[1] = true;
							}
						}
						if (!this->getAllForm[3])
						{
							if (this->world->map.allPointsRoad1[this->i].y - this->this_pt.y >= 22 && this->world->map.allPointsRoad1[this->i].y - this->this_pt.y <= 45 && (this->this_pt.x >= this->world->map.allPointsRoad1[this->i].x - 22 && this->this_pt.x <= this->world->map.allPointsRoad1[this->i].x + 22))
							{
								this->getAllForm[3] = true;
							}
						}
						if (!this->getAllForm[2])
						{
							if (this->this_pt.y - this->world->map.allPointsRoad1[this->i].y >= 22 && this->this_pt.y - this->world->map.allPointsRoad1[this->i].y <= 45 && (this->this_pt.x >= this->world->map.allPointsRoad1[this->i].x - 22 && this->this_pt.x <= this->world->map.allPointsRoad1[this->i].x + 22))
							{
								this->getAllForm[2] = true;
							}
						}
						i++;
					}
					this->i = 0;
					while (this->i < this->world->map.allPointsRoad2.size())
					{
						if (!this->getAllForm[0])
						{
							if (this->this_pt.x - this->world->map.allPointsRoad2[this->i].x >= 22 && this->this_pt.x - this->world->map.allPointsRoad2[this->i].x <= 45 && (this->this_pt.y >= this->world->map.allPointsRoad2[this->i].y - 22 && this->this_pt.y <= this->world->map.allPointsRoad2[this->i].y + 22))
							{
								this->getAllForm[0] = true;
							}
						}
						if (!this->getAllForm[1])
						{
							if (this->world->map.allPointsRoad2[this->i].x - this->this_pt.x >= 22 && this->world->map.allPointsRoad2[this->i].x - this->this_pt.x <= 45 && (this->this_pt.y >= this->world->map.allPointsRoad2[this->i].y - 22 && this->this_pt.y <= this->world->map.allPointsRoad2[this->i].y + 22))
							{
								this->getAllForm[1] = true;
							}
						}
						if (!this->getAllForm[3])
						{
							if (this->world->map.allPointsRoad2[this->i].y - this->this_pt.y >= 22 && this->world->map.allPointsRoad2[this->i].y - this->this_pt.y <= 45 && (this->this_pt.x >= this->world->map.allPointsRoad2[this->i].x - 22 && this->this_pt.x <= this->world->map.allPointsRoad2[this->i].x + 22))
							{
								this->getAllForm[3] = true;
							}
						}
						if (!this->getAllForm[2])
						{
							if (this->this_pt.y - this->world->map.allPointsRoad2[this->i].y >= 22 && this->this_pt.y - this->world->map.allPointsRoad2[this->i].y <= 45 && (this->this_pt.x >= this->world->map.allPointsRoad2[this->i].x - 22 && this->this_pt.x <= this->world->map.allPointsRoad2[this->i].x + 22))
							{
								this->getAllForm[2] = true;
							}
						}
						i++;
					}
					this->i = 0;
					while (this->i < this->world->map.allPointsRoad3.size())
					{
						if (!this->getAllForm[0])
						{
							if (this->this_pt.x - this->world->map.allPointsRoad3[this->i].x >= 22 && this->this_pt.x - this->world->map.allPointsRoad3[this->i].x <= 45 && (this->this_pt.y >= this->world->map.allPointsRoad3[this->i].y - 22 && this->this_pt.y <= this->world->map.allPointsRoad3[this->i].y + 22))
							{
								this->getAllForm[0] = true;
							}
						}
						if (!this->getAllForm[1])
						{
							if (this->world->map.allPointsRoad3[this->i].x - this->this_pt.x >= 22 && this->world->map.allPointsRoad3[this->i].x - this->this_pt.x <= 45 && (this->this_pt.y >= this->world->map.allPointsRoad3[this->i].y - 22 && this->this_pt.y <= this->world->map.allPointsRoad3[this->i].y + 22))
							{
								this->getAllForm[1] = true;
							}
						}
						if (!this->getAllForm[3])
						{
							if (this->world->map.allPointsRoad3[this->i].y - this->this_pt.y >= 22 && this->world->map.allPointsRoad3[this->i].y - this->this_pt.y <= 45 && (this->this_pt.x >= this->world->map.allPointsRoad3[this->i].x - 22 && this->this_pt.x <= this->world->map.allPointsRoad3[this->i].x + 22))
							{
								this->getAllForm[3] = true;
							}
						}
						if (!this->getAllForm[2])
						{
							if (this->this_pt.y - this->world->map.allPointsRoad3[this->i].y >= 22 && this->this_pt.y - this->world->map.allPointsRoad3[this->i].y <= 45 && (this->this_pt.x >= this->world->map.allPointsRoad3[this->i].x - 22 && this->this_pt.x <= this->world->map.allPointsRoad3[this->i].x + 22))
							{
								this->getAllForm[2] = true;
							}
						}
						i++;
					}
				}
			}
		}
		this->container->stop();
		this->addChild(this->container);
		this->world->listOfClasses.push(this);
		//this->world->listOfIndexes2.push(this);
		this->world->forseIndexFl = true;
		return true;
	}// end function

	void CastSphere::update(float dt)
	{
		if (dynamic_cast<CastGetAll_mc*>(this->container) && this->additAnamation)
		{
			CastGetAll_mc * container = (CastGetAll_mc*)this->container;
			if (this->liveCounter > 0)
			{
				this->liveCounter--;
			}
			if (this->container->currentFrame < this->container->totalFrames)
			{
			    this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
			}
			if (this->container->currentFrame > 3 && this->container->currentFrame < 6)
			{
				container->haze1->myFrame = container->haze1->currentFrame;
				container->haze2->myFrame = container->haze2->currentFrame;
				container->haze3->myFrame = container->haze3->currentFrame;
				container->haze4->myFrame = container->haze4->currentFrame;
				container->haze5->myFrame = container->haze5->currentFrame;
				container->haze6->myFrame = container->haze6->currentFrame;
				container->haze7->myFrame = container->haze7->currentFrame;
				container->haze8->myFrame = container->haze8->currentFrame;
				container->haze9->myFrame = container->haze9->currentFrame;
			}
			if (this->container->currentFrame == 4 || this->container->currentFrame == 5 || this->container->currentFrame == 6)
			{
				if (this->container->currentFrame == 4)
				{
					if (!this->getAllForm[0])
					{
						container->haze5->setVisible(false);
						container->haze1->setVisible(false);
						container->haze3->setVisible(false);
					}
					if (!this->getAllForm[1])
					{
						container->haze7->setVisible(false);
						container->haze2->setVisible(false);
						container->haze4->setVisible(false);
					}
					if (!this->getAllForm[2])
					{
						container->haze6->setVisible(false);
						container->haze1->setVisible(false);
						container->haze2->setVisible(false);
					}
					if (!this->getAllForm[3])
					{
						container->haze8->setVisible(false);
						container->haze3->setVisible(false);
						container->haze4->setVisible(false);
					}
					container->haze1->myPoint = this->container->convertToWorldSpace(container->haze1->getPosition());
					container->haze2->myPoint = this->container->convertToWorldSpace(container->haze2->getPosition());
					container->haze3->myPoint = this->container->convertToWorldSpace(container->haze3->getPosition());
					container->haze4->myPoint = this->container->convertToWorldSpace(container->haze4->getPosition());
					container->haze5->myPoint = this->container->convertToWorldSpace(container->haze5->getPosition());
					container->haze6->myPoint = this->container->convertToWorldSpace(container->haze6->getPosition());
					container->haze7->myPoint = this->container->convertToWorldSpace(container->haze7->getPosition());
					container->haze8->myPoint = this->container->convertToWorldSpace(container->haze8->getPosition());
					container->haze9->myPoint = this->container->convertToWorldSpace(container->haze9->getPosition());
					this->leftSmoke_pt = this->container->convertToWorldSpace(container->haze5->getPosition());
					this->rightSmoke_pt = this->container->convertToWorldSpace(container->haze7->getPosition());
					this->upSmoke_pt = this->container->convertToWorldSpace(container->haze6->getPosition());
					this->downSmoke_pt = this->container->convertToWorldSpace(container->haze8->getPosition());
				}
				if (container->haze1->myFrame < 60)
				{
				    container->haze1->tryPlay();
					//container->haze1->gotoAndStop((container->haze1->myFrame + 1));
				}
				else
				{
					container->haze1->gotoAndStop(1);
				}
				if (container->haze2->myFrame < 60)
				{
					container->haze2->tryPlay();
					//container->haze2->gotoAndStop((container->haze2->myFrame + 1));
				}
				else
				{
					container->haze2->gotoAndStop(1);
				}
				if (container->haze3->myFrame < 60)
				{
					container->haze3->tryPlay();
					//container->haze3->gotoAndStop((container->haze3->myFrame + 1));
				}
				else
				{
					container->haze3->gotoAndStop(1);
				}
				if (container->haze4->myFrame < 60)
				{
					container->haze4->tryPlay();
					//container->haze4->gotoAndStop((container->haze4->myFrame + 1));
				}
				else
				{
					container->haze4->gotoAndStop(1);
				}
				if (container->haze5->myFrame < 60)
				{
					container->haze5->tryPlay();
					//container->haze5->gotoAndStop((container->haze5->myFrame + 1));
				}
				else
				{
					container->haze5->gotoAndStop(1);
				}
				if (container->haze6->myFrame < 60)
				{
					container->haze6->tryPlay();
					//container->haze6->gotoAndStop((container->haze6->myFrame + 1));
				}
				else
				{
					container->haze6->gotoAndStop(1);
				}
				if (container->haze7->myFrame < 60)
				{
					container->haze7->tryPlay();
					//container->haze7->gotoAndStop((container->haze7->myFrame + 1));
				}
				else
				{
					container->haze7->gotoAndStop(1);
				}
				if (container->haze8->myFrame < 60)
				{
					container->haze8->tryPlay();
					//container->haze8->gotoAndStop((container->haze8->myFrame + 1));
				}
				else
				{
					container->haze8->gotoAndStop(1);
				}
				if (container->haze9->myFrame < 60)
				{
					container->haze9->tryPlay();
					//container->haze9->gotoAndStop((container->haze9->myFrame + 1));
				}
				else
				{
					container->haze9->gotoAndStop(1);
				}
			}
			else if (this->container->currentFrame > 3)
			{
				if (this->liveCounter > 0)
				{
					if (container->haze1->currentFrame < 60)
					{
						container->haze1->tryPlay();
					    //container->haze1->gotoAndStop((container->haze1->currentFrame + 1));
					}
					else
					{
						container->haze1->gotoAndStop(1);
					}
					if (container->haze2->currentFrame < 60)
					{
						container->haze2->tryPlay();
					    //container->haze2->gotoAndStop((container->haze2->currentFrame + 1));
					}
					else
					{
						container->haze2->gotoAndStop(1);
					}
					if (container->haze3->currentFrame < 60)
					{
						container->haze3->tryPlay();
					    //container->haze3->gotoAndStop((container->haze3->currentFrame + 1));
					}
					else
					{
						container->haze3->gotoAndStop(1);
					}
					if (container->haze4->currentFrame < 60)
					{
						container->haze4->tryPlay();
					    //container->haze4->gotoAndStop((container->haze4->currentFrame + 1));
					}
					else
					{
						container->haze4->gotoAndStop(1);
					}
					if (container->haze5->currentFrame < 60)
					{
						container->haze5->tryPlay();
					    //container->haze5->gotoAndStop((container->haze5->currentFrame + 1));
					}
					else
					{
						container->haze5->gotoAndStop(1);
					}
					if (container->haze6->currentFrame < 60)
					{
						container->haze6->tryPlay();
					    //container->haze6->gotoAndStop((container->haze6->currentFrame + 1));
					}
					else
					{
						container->haze6->gotoAndStop(1);
					}
					if (container->haze7->currentFrame < 60)
					{
						container->haze7->tryPlay();
					    //container->haze7->gotoAndStop((container->haze7->currentFrame + 1));
					}
					else
					{
						container->haze7->gotoAndStop(1);
					}
					if (container->haze8->currentFrame < 60)
					{
						container->haze8->tryPlay();
					    //container->haze8->gotoAndStop((container->haze8->currentFrame + 1));
					}
					else
					{
						container->haze8->gotoAndStop(1);
					}
					if (container->haze9->currentFrame < 60)
					{
						container->haze9->tryPlay();
					    //container->haze9->gotoAndStop((container->haze9->currentFrame + 1));
					}
					else
					{
						container->haze9->gotoAndStop(1);
					}
				}
				else
				{
					if (container->haze1->currentFrame < container->haze1->totalFrames)
					{
						container->haze1->tryPlay();
					    //container->haze1->gotoAndStop((container->haze1->currentFrame + 1));
					}
					if (container->haze2->currentFrame < container->haze2->totalFrames)
					{
						container->haze2->tryPlay();
					    //container->haze2->gotoAndStop((container->haze2->currentFrame + 1));
					}
					if (container->haze3->currentFrame < container->haze3->totalFrames)
					{
						container->haze3->tryPlay();
					    //container->haze3->gotoAndStop((container->haze3->currentFrame + 1));
					}
					if (container->haze4->currentFrame < container->haze4->totalFrames)
					{
						container->haze4->tryPlay();
					    //container->haze4->gotoAndStop((container->haze4->currentFrame + 1));
					}
					if (container->haze5->currentFrame < container->haze5->totalFrames)
					{
						container->haze5->tryPlay();
					    //container->haze5->gotoAndStop((container->haze5->currentFrame + 1));
					}
					if (container->haze6->currentFrame < container->haze6->totalFrames)
					{
						container->haze6->tryPlay();
					    //container->haze6->gotoAndStop((container->haze6->currentFrame + 1));
					}
					if (container->haze7->currentFrame < container->haze7->totalFrames)
					{
						container->haze7->tryPlay();
					    //container->haze7->gotoAndStop((container->haze7->currentFrame + 1));
					}
					if (container->haze8->currentFrame < container->haze8->totalFrames)
					{
						container->haze8->tryPlay();
					    //container->haze8->gotoAndStop((container->haze8->currentFrame + 1));
					}
					if (container->haze9->currentFrame < container->haze9->totalFrames)
					{
						container->haze9->tryPlay();
					    //container->haze9->gotoAndStop((container->haze9->currentFrame + 1));
					}
				}
				this->i = this->world->listOfUnits.size() - 1;
				while (this->i >= 0)
				{
					if (this->world->listOfUnits[this->i]->atStage() && this->world->listOfUnits[this->i]->readyDamage)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (container->haze9->isVisible())
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < container->haze9->getWidth())
							{
								tempObject->getHit(Main::mainClass->readXMLClass.getAllDamagePerSec);
							}
						}
						if (container->haze5->isVisible())
						{
							if (this->leftSmoke_pt.distance(tempObject->shoot_pt) < container->haze5->getWidth())
							{
								tempObject->getHit(Main::mainClass->readXMLClass.getAllDamagePerSec);
							}
						}
						if (container->haze7->isVisible())
						{
							if (this->rightSmoke_pt.distance(tempObject->shoot_pt) < container->haze7->getWidth())
							{
								tempObject->getHit(Main::mainClass->readXMLClass.getAllDamagePerSec);
							}
						}
						if (container->haze6->isVisible())
						{
							if (this->upSmoke_pt.distance(tempObject->shoot_pt) < container->haze6->getWidth())
							{
								tempObject->getHit(Main::mainClass->readXMLClass.getAllDamagePerSec);
							}
						}
						if (container->haze8->isVisible())
						{
							if (this->downSmoke_pt.distance(tempObject->shoot_pt) < container->haze8->getWidth())
							{
								tempObject->getHit(Main::mainClass->readXMLClass.getAllDamagePerSec);
							}
						}
						if (tempObject->dead)
						{
							int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
							//(this->world->saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
						}
					}
					i--;
				}
			}
			if (this->additAnamation->currentFrame > 3 && this->additAnamation->currentFrame < 6)
			{
				this->additAnamation->swamp1->myFrame = this->additAnamation->swamp1->currentFrame;
				this->additAnamation->swamp2->myFrame = this->additAnamation->swamp2->currentFrame;
				this->additAnamation->swamp3->myFrame = this->additAnamation->swamp3->currentFrame;
				this->additAnamation->swamp4->myFrame = this->additAnamation->swamp4->currentFrame;
				this->additAnamation->swamp5->myFrame = this->additAnamation->swamp5->currentFrame;
			}
			if (this->additAnamation->currentFrame < this->additAnamation->totalFrames)
			{
				this->additAnamation->tryPlay();
				//this->additAnamation->gotoAndStop((this->additAnamation->currentFrame + 1));
			}
			if (this->additAnamation->currentFrame == 4 || this->additAnamation->currentFrame == 5 || this->additAnamation->currentFrame == 6)
			{
				if (this->additAnamation->currentFrame == 4)
				{
					if (!this->getAllForm[0])
					{
						this->additAnamation->swamp1->setVisible(false);
					}
					if (!this->getAllForm[1])
					{
						this->additAnamation->swamp3->setVisible(false);
					}
					if (!this->getAllForm[2])
					{
						this->additAnamation->swamp2->setVisible(false);
					}
					if (!this->getAllForm[3])
					{
						this->additAnamation->swamp4->setVisible(false);
					}
				}
				if (this->additAnamation->swamp1->myFrame < 62)
				{
					this->additAnamation->swamp1->tryPlay();
					//this->additAnamation->swamp1->gotoAndStop((this->additAnamation->swamp1->currentFrame + 1));
				}
				else
				{
					this->additAnamation->swamp1->gotoAndStop(1);
				}
				if (this->additAnamation->swamp2->myFrame < 62)
				{
					this->additAnamation->swamp2->tryPlay();
					//this->additAnamation->swamp2->gotoAndStop((this->additAnamation->swamp2->currentFrame + 1));
				}
				else
				{
					this->additAnamation->swamp2->gotoAndStop(1);
				}
				if (this->additAnamation->swamp3->myFrame < 62)
				{
					this->additAnamation->swamp3->tryPlay();
					//this->additAnamation->swamp3->gotoAndStop((this->additAnamation->swamp3->currentFrame + 1));
				}
				else
				{
					this->additAnamation->swamp3->gotoAndStop(1);
				}
				if (this->additAnamation->swamp4->myFrame < 62)
				{
					this->additAnamation->swamp4->tryPlay();
					//this->additAnamation->swamp4->gotoAndStop((this->additAnamation->swamp4->currentFrame + 1));
				}
				else
				{
					this->additAnamation->swamp4->gotoAndStop(1);
				}
				if (this->additAnamation->swamp5->myFrame < 62)
				{
					this->additAnamation->swamp5->tryPlay();
					//this->additAnamation->swamp5->gotoAndStop((this->additAnamation->swamp5->currentFrame + 1));
				}
				else
				{
					this->additAnamation->swamp5->gotoAndStop(1);
				}
			}
			else if (this->additAnamation->currentFrame > 3)
			{
				if (this->liveCounter > 0)
				{
					if (this->additAnamation->swamp1->currentFrame < 62)
					{
						this->additAnamation->swamp1->tryPlay();
					    //this->additAnamation->swamp1->gotoAndStop((this->additAnamation->swamp1->currentFrame + 1));
					}
					else
					{
						this->additAnamation->swamp1->gotoAndStop(1);
					}
					if (this->additAnamation->swamp2->currentFrame < 62)
					{
						this->additAnamation->swamp2->tryPlay();
					    //this->additAnamation->swamp2->gotoAndStop((this->additAnamation->swamp2->currentFrame + 1));
					}
					else
					{
						this->additAnamation->swamp2->gotoAndStop(1);
					}
					if (this->additAnamation->swamp3->currentFrame < 62)
					{
						this->additAnamation->swamp3->tryPlay();
					    //this->additAnamation->swamp3->gotoAndStop((this->additAnamation->swamp3->currentFrame + 1));
					}
					else
					{
						this->additAnamation->swamp3->gotoAndStop(1);
					}
					if (this->additAnamation->swamp4->currentFrame < 62)
					{
						this->additAnamation->swamp4->tryPlay();
					    //this->additAnamation->swamp4->gotoAndStop((this->additAnamation->swamp4->currentFrame + 1));
					}
					else
					{
						this->additAnamation->swamp4->gotoAndStop(1);
					}
					if (this->additAnamation->swamp5->currentFrame < 62)
					{
						this->additAnamation->swamp5->tryPlay();
					    //this->additAnamation->swamp5->gotoAndStop((this->additAnamation->swamp5->currentFrame + 1));
					}
					else
					{
						this->additAnamation->swamp5->gotoAndStop(1);
					}
				}
				else
				{
					if (this->additAnamation->swamp1->currentFrame < this->additAnamation->swamp1->totalFrames)
					{
						this->additAnamation->swamp1->tryPlay();
					    //this->additAnamation->swamp1->gotoAndStop((this->additAnamation->swamp1->currentFrame + 1));
					}
					if (this->additAnamation->swamp2->currentFrame < this->additAnamation->swamp2->totalFrames)
					{
						this->additAnamation->swamp2->tryPlay();
					    //this->additAnamation->swamp2->gotoAndStop((this->additAnamation->swamp2->currentFrame + 1));
					}
					if (this->additAnamation->swamp3->currentFrame < this->additAnamation->swamp3->totalFrames)
					{
						this->additAnamation->swamp3->tryPlay();
					    //this->additAnamation->swamp3->gotoAndStop((this->additAnamation->swamp3->currentFrame + 1));
					}
					if (this->additAnamation->swamp4->currentFrame < this->additAnamation->swamp4->totalFrames)
					{
						this->additAnamation->swamp4->tryPlay();
					    //this->additAnamation->swamp4->gotoAndStop((this->additAnamation->swamp4->currentFrame + 1));
					}
					if (this->additAnamation->swamp5->currentFrame < this->additAnamation->swamp5->totalFrames)
					{
						this->additAnamation->swamp5->tryPlay();
					    //this->additAnamation->swamp5->gotoAndStop((this->additAnamation->swamp5->currentFrame + 1));
					}
				}
			}
			if (this->container->currentFrame == 4)
			{
				if (this->getAllCount > 0)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						if (this->world->listOfUnits[this->i]->atStage() && this->world->listOfUnits[this->i]->readyDamage)
						{
							if (this->this_pt.distance(this->world->listOfUnits[this->i]->shoot_pt) < this->radius)
							{
								units::Unit * tempObject = this->world->listOfUnits[this->i];
								float tempObject1 = Main::mainClass->readXMLClass.getAllMultiply2;
								tempObject->getHit(tempObject1, "getAll");
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			if (this->liveCounter == 0)
			{
				if (container->haze1->currentFrame == container->haze1->totalFrames && this->additAnamation->swamp1->currentFrame == this->additAnamation->swamp1->totalFrames)
				{
					this->kill();
					//this->i = 0;
					//while (this->i < this->world->listOfIndexes0.length)
					//{ 
					//    if (this->world->listOfIndexes0[this->i] == this->additAnamation)
					//    {
					//        this->world->removeChild(this->additAnamation);
					//        this->world->listOfIndexes0.splice(this->i, 1);
					//        break;
					//    }
					//    i++;
					//}
				}
			}
		}
		else if (this->container->currentFrame < this->container->totalFrames)
		{
			if (this->sphereType == "fire")
			{
			    this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 2)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveFireXML[this->fireCount], this->sphereType, this->fireCount, true);
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "ice")
			{
			    this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 2)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveIceXML[this->iceCount], this->sphereType, this->iceCount, true);
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "stone")
			{
				if (this->container->myCounter > 0)
				{
					this->container->myCounter--;
					if (this->container->myCounter == 0)
					{
						this->container->setVisible(true);
					}
				}
				else
				{
					this->container->tryPlay();
					//this->container->gotoAndStop((this->container->currentFrame + 1));
					if (this->container->currentFrame == 2)
					{
						this->i = this->world->listOfUnits.size() - 1;
						while (this->i >= 0)
						{
							units::Unit * tempObject = this->world->listOfUnits[this->i];
							if (tempObject->atStage() && tempObject->readyDamage)
							{
								if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
								{
									tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveStoneXML[this->stoneCount], this->sphereType, this->stoneCount, true);
									if (tempObject->dead)
									{
										int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
										this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
									}
								}
							}
							i--;
						}
					}
				}
			}
			else if (this->sphereType == "levin")
			{
				this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 2)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveLevinXML[this->levinCount], this->sphereType, this->levinCount, true);
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "fireIce")
			{
				this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 2)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveFireXML[this->fireCount], "fire", this->fireCount, true);
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveIceXML[this->iceCount], "ice", this->iceCount, true);
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "fireStone")
			{
				this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 2)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveFireXML[this->fireCount], "fire", this->fireCount, true);
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveStoneXML[this->stoneCount], "stone", this->stoneCount, true);
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
									//(this->world->saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "fireLevin")
			{
				this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 2)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveFireXML[this->fireCount], "fire", this->fireCount, true);
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveLevinXML[this->levinCount], "levin", this->levinCount, true);
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
									//(this->world->saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "iceStone")
			{
				this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 2)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveIceXML[this->iceCount], "ice", this->iceCount, true);
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveStoneXML[this->stoneCount], "stone", this->stoneCount, true);
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
									//(this->world->saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "iceLevin")
			{
				this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 2)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveIceXML[this->iceCount], "ice", this->iceCount, true);
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveLevinXML[this->levinCount], "levin", this->levinCount, true);
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
									//(this->world->saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "stoneLevin")
			{
				this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 2)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveStoneXML[this->stoneCount], "stone", this->stoneCount, true);
								tempObject->getHit(Main::mainClass->readXMLClass.listOfMoveLevinXML[this->levinCount], "levin", this->levinCount, true);
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
									//(this->world->saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "getAllLittle")
			{
				this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 4)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								float tempObject1 = 0;
								if (this->fireCount > 0)
								{
									tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfMoveFireXML[this->fireCount];
								}
								if (this->iceCount > 0)
								{
									tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfMoveIceXML[this->iceCount];
								}
								if (this->stoneCount > 0)
								{
									tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfMoveStoneXML[this->stoneCount];
								}
								if (this->levinCount > 0)
								{
									tempObject1 = tempObject1 + Main::mainClass->readXMLClass.listOfMoveLevinXML[this->levinCount];
								}
								if (this->fireCount > 1 || this->iceCount > 1 || this->stoneCount > 1 || this->levinCount > 1)
								{
									tempObject1 = tempObject1 * Main::mainClass->readXMLClass.getAllLittleDoubleMultiply;
								}
								else
								{
									tempObject1 = tempObject1 * Main::mainClass->readXMLClass.getAllLittleMultiply;
								}
								tempObject->getHit(tempObject1, "getAllLittle");
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
									//(this->world->saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
			else if (this->sphereType == "getAll")
			{
				this->container->tryPlay();
				//this->container->gotoAndStop((this->container->currentFrame + 1));
				if (this->container->currentFrame == 4)
				{
					this->i = this->world->listOfUnits.size() - 1;
					while (this->i >= 0)
					{
						units::Unit * tempObject = this->world->listOfUnits[this->i];
						if (tempObject->atStage() && tempObject->readyDamage)
						{
							if (this->this_pt.distance(tempObject->shoot_pt) < this->radius)
							{
								float tempObject1 = 0;
								if (this->getAllCount == 1)
								{
									tempObject1 = Main::mainClass->readXMLClass.getAllMultiply;
								}
								else if (this->getAllCount == 2)
								{
									tempObject1 = Main::mainClass->readXMLClass.getAllMultiply1;
								}
								tempObject->getHit(tempObject1, "getAll");
								if (tempObject->dead)
								{
									int addit_castKillEnemiesCounter = this->world->saveBox->getIntValue("addit_castKillEnemiesCounter");
									this->world->saveBox->setValue("addit_castKillEnemiesCounter", addit_castKillEnemiesCounter + 1);
									//(this->world->saveBox.gameSave.data.addit_castKillEnemiesCounter + 1);
								}
							}
						}
						i--;
					}
				}
			}
		}
		else
		{
			this->kill();
		}
		return;
	}// end function

	void CastSphere::kill()
	{
		if (!this->dead)
		{
			this->dead = true;
			this->world->removeChild(this);
			//this->i = 0;
			//while (this->i < this->world->listOfClasses.size())
			//{ 
			//    if (this->world->listOfClasses[this->i] == this)
			//    {
			//        this->world->removeChild(this->world->listOfClasses[this->i]);
 			//			break;
			//    }
			//    i++;
			//}
			//this->i = 0;
			//while (this->i < this->world->listOfIndexes2.length)
			//{
			//    
			//    if (this->world->listOfIndexes2[this->i] == this)
			//    {
			//        this->world->listOfIndexes2.splice(this->i, 1);
			//        break;
			//    }
			//    i++;
			//}
			if (this->world->saveBox->getIntValue("addit_castKillEnemiesCounter") > 0)
			{
				this->world->achieveManage("castKill_1_enemy");
			}
			else if (this->world->saveBox->getIntValue("addit_castKillEnemiesCounter") >= 100)
			{
				this->world->achieveManage("castKill_100_enemy");
			}
		}
		return;
	}// end function


}
