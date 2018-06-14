
#include "Bullet_7.h" 
#include "engine/World.h" 
#include "engine/units/Unit.h"
#include "engine/towers/Tower.h"

namespace engine
{
	namespace bullets
	{

		Bullet_7::Bullet_7()
		{
			return;
		}// end function

		bool Bullet_7::init()
		{
			bulletType = 7;
			liveTimer = 30;
			liveCounter = 30;
			this->setPosition(this_pt);
			//this->x = this_pt.x;
			//this->y = this_pt.y;
			correct = (int)(liveTimer / 6);
			BulletTower7_mc *cont = new BulletTower7_mc();
			container = cont;
			container->stop();
			cont->ball->stop();
			cont->smoke->stop();
			cont->smokeCont1->stop();
			cont->smokeCont2->stop();
			cont->setRotation(180);
			this->addChild(container);
			testTower = ISTYPE(Tower, whoShoot);
			radius = whoShoot->radius;
			Bullet::init();
			this->enemyStartPoint = enemyTarget->this_pt;
			this->enemyRoad = enemyTarget->road;
			this->enemyWay = enemyTarget->way;
			this->enemyPath = enemyTarget->path;
			if (enemyTarget->speedK > 0 || enemyTarget->typeUnit == 34)
			{
				if (enemyTarget->typeUnit != 3 && enemyTarget->typeUnit != 8 && enemyTarget->typeUnit != 13)
				{
					this->enemySpeed = enemyTarget->speedK * 0.95;
				}
				else
				{
					this->enemySpeed = enemyTarget->speedK;
				}
			}
			else
			{
				this->enemySpeed = 0.1f;
			}
			bezier::PathPoint  tempObject = world->bezierClass->getPathPoint(this->enemyPath + this->enemySpeed * liveTimer, this->enemyRoad, this->enemyWay);
			if (this->getPositionX() > tempObject.x)
			{
				this->rotationFlag = false;
			}
			else
			{
				this->rotationFlag = true;
			}
			this->shadow = new UnitShadow_mc();// new UnitShadow_mc();
			//this->shadow->stop(); 
			this->shadow->mouseChildren = false;
			this->shadow->mouseEnabled = false;
			this->shadow->setPosition(this_pt.x, whoShoot->getPositionY());
			//this->shadow.x = this_pt.x;
			//this->shadow.y = whoShoot.y;
			this->shadow->setScale(0.5);
			//this->shadow.scaleY = 0.5;
			//this->shadow.scaleX = 0.5;
			world->addChild(this->shadow, 2);
			//world->listOfIndexes2.push(this->shadow);
			//Sounds.instance.playSound("snd_tower_shootUltra1_1");
			return true;
		}// end function

		void Bullet_7::update(float dt)
		{
			Bullet::update();

			BulletTower7_mc *container = (BulletTower7_mc *)this->container;
			if (container->smoke)
			{
				if (container->smoke->isVisible())
				{
					if (container->smokeCont1->currentFrame < container->smokeCont1->totalFrames)
					{
						container->smokeCont1->gotoAndStop((container->smokeCont1->currentFrame + 1));
					}
					else
					{
						container->smokeCont1->gotoAndStop(1);
					}
					if (container->smokeCont2->currentFrame < container->smokeCont2->totalFrames)
					{
						container->smokeCont2->gotoAndStop((container->smokeCont2->currentFrame + 1));
					}
					else
					{
						container->smokeCont2->gotoAndStop(1);
					}
					if (world->frameCounter % 2)
					{
						cocos2d::Point tempObject1 = container->smokeCont2->localToGlobal(container->smokeCont2->getPosition());
						BulletTower7_smoke_mc * tempObject = new BulletTower7_smoke_mc(this->world);//new Indexes(new BulletTower7_smoke_mc(), 2, 0);
						tempObject->setPosition(tempObject1);
						//tempObject.x = tempObject1.x;
						//tempObject.y = tempObject1.y;
						tempObject->setRotation(container->getRotation());
					}
				}
			}
			if (container->currentFrame > 1)
			{
				if (container->currentFrame < container->totalFrames)
				{
					container->gotoAndStop((container->currentFrame + 1));
				}
			}
			if (liveCounter > 0)
			{
				distanceX = this->enemyStartPoint.x - this_pt.x;
				distanceY = this->enemyStartPoint.y - this_pt.y;
				testTarget = this->enemyStartPoint;
				scanAtRadius();
				if (greenFlag)
				{
					this->enemyPath = this->enemyPath + this->enemySpeed;
				}
				bezier::PathPoint tempObject = world->bezierClass->getPathPoint(this->enemyPath, this->enemyRoad, this->enemyWay);
				this->enemyStartPoint = tempObject;// new Point(tempObject.x, tempObject.y);
				if (liveCounter > correct)
				{
					this->setPosition(this->getPositionX() + distanceX / (liveCounter - correct), this->getPositionY() + distanceY / (liveCounter - correct));
					//this->x = this->x + distanceX / (liveCounter - correct);
					//this->y = this->y + (distanceY / (liveCounter - correct) - 8);
					this->shadow->setPositionX(this->shadow->getPositionX() + (this->enemyStartPoint.x - this->shadow->getPositionX()) / (liveCounter - correct));
					this->shadow->setPositionY(this->shadow->getPositionY() + (this->enemyStartPoint.y - this->shadow->getPositionY()) / (liveCounter - correct));
					//this->shadow.x = this->shadow.x + (this->enemyStartPoint.x - this->shadow.x) / (liveCounter - correct);
					//this->shadow.y = this->shadow.y + (this->enemyStartPoint.y - this->shadow.y) / (liveCounter - correct);
					if (!this->rotationFlag)
						container->setRotation( container->getRotation() - 6);
					else
						container->setRotation(container->getRotation() + 6);
					this_pt = this->getPosition();// new Point(this->x, this->y);
				}
				else
				{
					this->setPosition(this->getPositionX() + distanceX / (liveCounter * 10), this->getPositionY() + distanceY / (liveCounter * 10));
					//this->x = this->x + distanceX / (liveCounter * 10);
					//this->y = this->y + distanceY / (liveCounter * 10);
					this->shadow->setPositionX(this->shadow->getPositionX() + (this->enemyStartPoint.x - this->shadow->getPositionX()) / (liveCounter * 10));
					this->shadow->setPositionY(this->shadow->getPositionY() + (this->enemyStartPoint.y - this->shadow->getPositionY()) / (liveCounter * 10));
					//this->shadow.x = this->shadow.x + (this->enemyStartPoint.x - this->shadow.x) / (liveCounter * 10);
					//this->shadow.y = this->shadow.y + (this->enemyStartPoint.y - this->shadow.y) / (liveCounter * 10);
					if (liveCounter == 4)
					{
						//Sounds.instance.playSound("snd_tower_shootUltra3");
						container->gotoAndStop(2);
						this->shadow->setVisible(false);
						i = world->listOfUnits.size() - 1;
						while (i >= 0)
						{
							if (world->listOfUnits[i]->atStage() && world->listOfUnits[i]->readyDamage)
							{
								if (this_pt.distance(world->listOfUnits[i]->shoot_pt) < Main::mainClass->readXMLClass.ultraIceStoneDamageRadiusXML)
								{
									Unit* tempObject = world->listOfUnits[i];
									if (tempObject->typeUnit != 24)
									{
										tempObject->getHit(damage / 2, "ice", 2, true, bulletType, whoShoot);
									}
									else
									{
										tempObject->getHit(damage / 2, "ice", 2, false, bulletType, whoShoot);
									}
									if (!tempObject->dead && tempObject->readyDamage)
									{
										if (!enemyTarget->icemanFlag)
										{
											enemyTarget->iceEffectSlowdown = enemyTarget->speedKSave * Main::mainClass->readXMLClass.ultraIceStoneSlowdownPowerXML;
											enemyTarget->iceEffectCounter = Main::mainClass->readXMLClass.ultraIceStoneSlowdownTimerXML;
										}
										if (tempObject->typeUnit != 25)
										{
											tempObject->getHit(damage / 2, "stone", 2, true, bulletType, whoShoot);
										}
										else
										{
											tempObject->getHit(damage / 2, "stone", 2, false, bulletType, whoShoot);
										}
									}
								}
							}
							i--;
						}
					}
				}
				liveCounter--;
			}
			else if (container->currentFrame == container->totalFrames)
			{
				this->kill();
			}
			return;
		}// end function

		void Bullet_7::kill()
		{
			if (this->shadow)
			{
				world->removeChild(this->shadow);
				//i = 0;
				//while (i < world->listOfIndexes2.size())
				//{
				//    
				//    if (world->listOfIndexes2[i] == this->shadow)
				//    {
				//        world->listOfIndexes2.splice(i, 1);
				//        break;
				//    }
				//    i++;
				//}
				this->shadow = NULL;
			}
			Bullet::kill();
			return;
		}// end function
	}
}
