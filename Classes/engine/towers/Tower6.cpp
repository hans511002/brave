
#include "MainClass.h"
#include "engine/World.h"
#include "TowerMenu.h"
#include "Tower6.h" 

namespace engine
{
	namespace towers
	{

		Tower6::Tower6() :soundCounter(0), soundTimer(5)
		{
			return;
		}// end function

		bool Tower6::init()
		{
			towerType = 6;
			//slotsStack = [0, 0, 1, 1];
			slotsStack[0] = 0;
			slotsStack[1] = 0;
			slotsStack[2] = 1;
			slotsStack[3] = 1;

			correctYGrPos = -35;
			radius = Main::mainClass->readXMLClass.ultraIceLevinRadiusXML;
			damage = Main::mainClass->readXMLClass.ultraIceLevinDamageXML;
			intervalTimer = Main::mainClass->readXMLClass.ultraIceLevinIntervalXML;
			intervalCounter = Main::mainClass->readXMLClass.ultraIceLevinIntervalXML;
			this->upgr1_damage = Main::mainClass->readXMLClass.ultraAddIceLevinDamageXML;
			this->upgr1_intervalTimer = Main::mainClass->readXMLClass.ultraAddIceLevinIntervalXML;
			this->upgr1_intervalCounter = Main::mainClass->readXMLClass.ultraAddIceLevinIntervalXML;
			Tower6_mc * container = new Tower6_mc();
			this->container = container;
			container->stop();
			container->towerCase->stop();
			container->blockTower->stop();
			container->boneBlock->stop();
			container->shotAnima->stop();
			container->towerCase->buttonMode = true;
			container->blockTower->setVisible(false);
			container->boneBlock->setVisible(false);
			container->shotAnima->setVisible(false);
			this->addChild(container);
			Tower::init();
			container->setVisible(false);
			container->setScale(0.9f);
			return true;
		}// end function

		void Tower6::update(float dt)
		{
			if (this->soundCounter != -1)
			{
				if (this->soundCounter < this->soundTimer)
				{
					this->soundCounter++;
				}
				else
				{
					this->soundCounter = -1;
					container->setVisible(true);
					if (!autoBuild)
					{
						//Sounds.instance.playSoundWithVol("snd_tower_buildUltra", 0.8);
					}
				}
			}
			else
			{
				Tower::update();
				if (world->frameCounter % 2)
				{
					if (container->currentFrame < container->totalFrames)
					{
						container->gotoAndStop((container->currentFrame + 1));
					}
					else
					{
						container->gotoAndStop(1);
					}
				}
			}
			return;
		}// end function

		void Tower6::scan()
		{
			if (!container->blockTower->isVisible())
			{
				if (intervalCounter < intervalTimer)
				{
					intervalCounter++;
				}
				else if (world->frameCounter % 2)
				{
					scanBlock();
					if (enemyTarget)
					{
						intervalCounter = 0;
					}
				}
				if (upgradeTypeAdd == 1)
				{
					bool tempObject = false;
					i = 0;
					while (i < world->listOfTowers.size())
					{

						if (ISTYPE(Tower6,world->listOfTowers[i]) && world->listOfTowers[i] != this)
						{
							Tower6 * tower = ISTYPE(Tower6, world->listOfTowers[i]);
							if (world->listOfTowers[i]->enemyTarget && tower->upgr1_intervalCounter == 0)
							{
								tempObject = true;
								break;
							}
						}
						i++;
					}
					if (!tempObject)
					{
						if (this->upgr1_intervalCounter < this->upgr1_intervalTimer)
						{
							this->upgr1_intervalCounter++;
						}
						else if (world->frameCounter % 2)
						{
							this->addScan();
						}
					}
				}
			}
			else
			{
				blockTowerFunk();
			}
			return;
		}// end function

		void Tower6::addScan()
		{
			if (!enemyTarget)
			{
				float tempObject1 = 0;
				Unit *tempObject2 = NULL;
				i = 0;
				while (i < world->listOfUnits.size())
				{

					if (world->listOfUnits[i]->atStage() && world->listOfUnits[i]->readyDamage)
					{
						float tempObject = world->listOfUnits[i]->path / world->listOfUnits[i]->finishPath;
						if (tempObject > tempObject1)
						{
							tempObject1 = tempObject;
							tempObject2 = world->listOfUnits[i];
						}
					}
					i++;
				}
				if (tempObject1 > 0)
				{
					enemyTarget = tempObject2;
					this->upgr1_intervalCounter = 0;
				}
			}
			return;
		}// end function

		void Tower6::attack()
		{
			Tower6_mc * container = ISTYPE(Tower6_mc, this->container);
			if (intervalCounter == 0)
			{
				Bullet * tempObject = world->addBullet(6, shoot_pt, this, enemyTarget, damage);
				intervalCounter = 1;
				enemyTarget = NULL;
				if (this->upgr1_intervalCounter == 0)
				{
					this->scan();
				}
			}
			else if (this->upgr1_intervalCounter == 0)
			{
				if (!container->shotAnima->isVisible())
				{
					container->shotAnima->setVisible(true);
				}
				else if (container->shotAnima->currentFrame < container->shotAnima->totalFrames)
				{
					container->shotAnima->gotoAndStop((container->shotAnima->currentFrame + 1));
					if (container->shotAnima->currentFrame == 32)
					{
						//Sounds.instance.playSoundWithVol("snd_tower_firstShootUltraAdd1", 0.85);
					}
				}
				else
				{
					container->shotAnima->gotoAndStop(1);
					container->shotAnima->setVisible(false);
					this->upgr1_intervalCounter = 1;
					enemyTarget = NULL;
					this->addScan();
					if (enemyTarget)
					{
						enemy_pt = world->bezierClass->getPathPoint(enemyTarget->path + enemyTarget->speedK * 4, enemyTarget->road, enemyTarget->way);
						//enemy_pt = new Point(tempObject.x, tempObject.y);
						Bullet * tempObject = world->addBullet(61, enemy_pt, this, enemyTarget, this->upgr1_damage);
					}
					else
					{
						this->upgr1_intervalCounter = this->upgr1_intervalTimer;
					}
					enemyTarget = NULL;
				}
			}
			return;
		}// end function

	}
}
 