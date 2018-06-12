
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h" 

namespace engine
{
	NewEnemy_mc::NewEnemy_mc() :MouseStatusMC("unit/", "NewEnemy_mc", "NewEnemy_mc") 
		{
			newEnemyCase = this->createCase("newEnemyCase");
		};

	NewElement_mc::NewElement_mc() :MouseStatusMC("unit/", "NewElement_mc", "NewElement_mc")
		{
			newElementCase = this->createCase("newElementCase");
		};
	namespace units
	{


		bool Unit::init() //public function init(event:Event) : void event:Event
		{
			//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
			this->container->stop();
			BaseNode::init();
			//this->container->unitCase.buttonMode = true;
			//this->container->healthBar->setVisible(false) ;
			//this->container->healthBar->getDamage->setVisible(false);

			this->addChild(this->container);
			this->container->coordOrigin = this->container->getPosition();
			//this->container->unitCase.coordOrigin = new Point(this->container->unitCase.x, this->container->unitCase.y);
			//this->container->buffHP.coordOrigin = new Point(this->container->buffHP.x, this->container->buffHP.y);
			//this->container->airShock.coordOrigin = new Point(this->container->airShock.x, this->container->airShock.y);
			//this->container->buffSpeed.coordOrigin = new Point(this->container->buffSpeed.x, this->container->buffSpeed.y);
			//this->container->dust1.coordOrigin = new Point(this->container->dust1.x, this->container->dust1.y);
			//this->container->dust2.coordOrigin = new Point(this->container->dust2.x, this->container->dust2.y);
			//this->container->dust3.coordOrigin = new Point(this->container->dust3.x, this->container->dust3.y);
			//this->container->fireAttack.coordOrigin = new Point(this->container->fireAttack.x, this->container->fireAttack.y);
			//this->container->iceAttack.coordOrigin = new Point(this->container->iceAttack.x, this->container->iceAttack.y);
			//this->container->levinAttack.coordOrigin = new Point(this->container->levinAttack.x, this->container->levinAttack.y);
			//this->container->iceFreez.coordOrigin = new Point(this->container->iceFreez.x, this->container->iceFreez.y);
			//this->container->fireEffect.coordOrigin = new Point(this->container->fireEffect.x, this->container->fireEffect.y);
			//this->container->iceEffect.coordOrigin = new Point(this->container->iceEffect.x, this->container->iceEffect.y);
			//this->container->armor.coordOrigin = new Point(this->container->armor.x, this->container->armor.y);
			//this->container->healthBar->coordOrigin = new Point(this->container->healthBar->x, this->container->healthBar->y);
			//this->container->dust4.coordOrigin = new Point(this->container->dust4.x, this->container->dust4.y);
			//this->container->selectUnit.coordOrigin = new Point(this->container->selectUnit.x, this->container->selectUnit.y);
			//if (this->container->iceDeath)
			//{
			//	this->container->iceDeath.coordOrigin = new Point(this->container->iceDeath.x, this->container->iceDeath.y);
			//	this->container->stoneDeath.coordOrigin = new Point(this->container->stoneDeath.x, this->container->stoneDeath.y);
			//	this->container->levinDeath.coordOrigin = new Point(this->container->levinDeath.x, this->container->levinDeath.y);
			//}
			//if (this->container->signal)
			//{
			//	this->container->signal.coordOrigin = new Point(this->container->signal.x, this->container->signal.y);
			//}
			//if (this->typeUnit == 28)
			//{
			//	this->container->giveHealth1.coordOrigin = new Point(this->container->giveHealth1.x, this->container->giveHealth1.y);
			//	this->container->giveHealth2.coordOrigin = new Point(this->container->giveHealth2.x, this->container->giveHealth2.y);
			//	this->container->giveHealth3.coordOrigin = new Point(this->container->giveHealth3.x, this->container->giveHealth3.y);
			//}
			//else if (this->typeUnit == 29 || this->typeUnit == 30)
			//{
			//	this->container->dustAnima.coordOrigin = new Point(this->container->dustAnima.x, this->container->dustAnima.y);
			//}
			this->world = Main::mainClass->worldClass;
			this->world->listOfUnits.push(this);
			this->speedKSave = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][1];
			this->speedK = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][1];

			this->health = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][2];
			this->healthMax = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][2];

			this->gold = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][3];
			this->fireDamageK = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][4];
			this->iceDamageK = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][5];
			this->stoneDamageK = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][6];
			this->levinDamageK = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][7];
			this->penalty = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][8];
			this->airResist = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][9];
			this->icemanResist = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][10];
			this->replacementCount = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][11];
			this->airSpacing = Main::mainClass->readXMLClass.airSpacingXML * this->airResist;
			this->airPower = Main::mainClass->readXMLClass.airPowerXML * this->airResist;
			this->airWaitTimer = Main::mainClass->readXMLClass.airWaitTimerXML;
			this->finishPath = this->world->bezierClass->getPathLength(this->road, this->way);
			this->setPosition(this->world->bezierClass->getPathPoint(this->path, this->road, this->way));


			this->this_pt = this->getPosition();// cocos2d::Vec2();
			//this->this_pt = new Point(this->x, this->y);
			this->shoot_pt = this->container->cont->convertToWorldSpace(this->container->cont->getPosition());
			//this->shoot_pt = this->container->localToGlobal(new Point(this->container->cont.x, this->container->cont.y));
 
			bezier::PathPoint tempObject = this->world->bezierClass->getPathPoint(this->path + 10, this->road, this->way);
			if (this->this_pt.x < tempObject.x - 5)
			{
				this->direction = "right";
			}
			else if (this->this_pt.x > tempObject.x + 5)
			{
				this->direction = "left";
			}
			else if (this->this_pt.y > tempObject.y + 5)
			{
				this->direction = "up";
			}
			else if (this->this_pt.y < tempObject.y - 5)
			{
				this->direction = "down";
			}
			if (this->direction == "up" || this->direction == "down")
			{
				this->scanNextTurn();
				this->setVerticalTurn();
			}
			this->world->forseIndexFl = true;
			if (this->typeUnit < 33)
			{
				if (Main::mainClass->saveBoxClass->getIntValue("firstViewEnemies", (this->typeUnit - 1)) == 0)
				{
					Main::mainClass->saveBoxClass->setValue("firstViewEnemies", (this->typeUnit - 1), 1);
					NewEnemy_mc * tempObject = new NewEnemy_mc();
 					tempObject->stop();
					//tempObject->newEnemyCase->stop();
					tempObject->typeUnit = this->typeUnit;
					//this->tempObject.newEnemyCase.buttonMode = true;
					this->world->worldInterface->addChild(tempObject);
					this->world->worldInterface->listOfNewEnemies.push(tempObject);
					//Sounds.instance.playSoundWithVol("snd_world_newEnemy", 0.9);
				}
			}
			this->schedule(schedule_selector(Unit::update), 0.0f);
			return true;
		}// end function
		void Unit::update(float dt) //public function update() : void
		{
			this->moveHandler();
			if (this->path >= this->finishPath)
			{
				this->kill();
				return;
			}
			this->animationHandler();
			//return;
		}// end function
		void Unit::moveHandler() //public function moveHandler() : void
		{
			if (!this->airFlag && !this->airShockFlag && !this->icemanFlag && !this->iceEffectFlag && !this->speedPlusFlag)
			{
				if (this->moveFlag)
				{
					if (this->speedK != this->speedKSave)
					{
						this->speedK = this->speedKSave;
						this->directionFlag = true;
					}
				}
				else if (this->speedK != 0)
				{
					this->speedK = 0;
				}
			}
			else if (this->airFlag)
			{
				float tempObject = this->airPower - this->dampingAir;
				if (this->traversedPath < this->airSpacing &&  tempObject > 0)
				{
					this->dampingAir = this->dampingAir + 0.4;
					this->speedK =  tempObject * -1;
					if (this->path - this->speedK < 0)
					{
						this->speedK = 0;
					}
					this->traversedPath = this->traversedPath + this->speedK;
				}
				else
				{
					this->airFlag = false;
					if (this->typeUnit != 34)
					{
						this->airShockFlag = true;
						this->airShockCounter = Main::mainClass->readXMLClass.airWaitTimerXML;
					}
				}
			}
			else if (this->airShockFlag)
			{
				if (this->speedK != 0)
				{
					this->speedK = 0;
				}
			}
			else if (this->icemanFlag)
			{
				if (this->speedK != 0)
				{
					this->speedK = 0;
				}
			}
			else if (this->iceEffectFlag)
			{
				if (this->moveFlag)
				{
					this->speedK = this->iceEffectSlowdown;
				}
				else if (this->speedK != 0)
				{
					this->speedK = 0;
				}
			}
			else if (this->speedPlusFlag)
			{
				if (this->moveFlag)
				{
					this->speedK = this->speedPlusValue;
				}
				else if (this->speedK != 0)
				{
					this->speedK = 0;
				}
			}
			if (this->mainMoveFlag && this->speedK != 0)
			{
				this->path = this->path + this->speedK;
				bezier::PathPoint ppo = this->world->bezierClass->getPathPoint(this->path, this->road, this->way);
				this->setPosition(ppo);
				this->directionManage();
				this->this_pt = this->getPosition();
				this->shoot_pt = this->container->cont->convertToWorldSpace(this->container->cont->getPosition());
				//this->shoot_pt = this->container->localToGlobal(new Point(this->container->cont.x, this->container->cont.y));
				if (this->direction == "up" || this->direction == "down")
				{
					if (this->path > this->nextTurnMidPath)
					{
						this->setVerticalTurn();
					}
				}
			}
			this->atStageManage();
			//return;
		}// end function

		void Unit::directionManage() //public function directionManage() : void
		{
			if (this->directionFlag || this->world->frameCounter == 10 || this->world->frameCounter == 20 || this->world->frameCounter == 30)
			{
				if (this->directionFlag)
				{
					this->directionFlag = false;
				}
				if (this->speedK != 0)
				{
					if (this->getPosition().x > this->this_pt.x && this->getPosition().x - this->this_pt.x >= this->speedK * 0.5)
					{
						if (this->speedK > 0)
						{
							if (this->direction != "right")
							{
								this->direction = "right";
								if (this->nextTurnFlag)
								{
									this->nextTurnFlag = false;
								}
							}
						}
						if (this->container->getScaleX() < 0)
						{
							this->setTurn("right");
						}
						if (this->airFlag)
						{
							if (this->airGo != 1)
							{
								this->airGo = 1;
							}
						}
					}
					else if (this->getPosition().x < this->this_pt.x && this->this_pt.x - this->getPosition().x >= this->speedK * 0.5)
					{
						if (this->speedK > 0)
						{
							if (this->direction != "left")
							{
								this->direction = "left";
								if (this->nextTurnFlag)
								{
									this->nextTurnFlag = false;
								}
							}
						}
						if (this->container->getScaleX() > 0)
						{
							this->setTurn("left");
						}
						if (this->airFlag)
						{
							if (this->airGo != 1)
							{
								this->airGo = 1;
							}
						}
					}
					else if (this->getPosition().y > this->this_pt.y && this->getPosition().y - this->this_pt.y >= this->speedK * 0.5)
					{
						if (this->speedK > 0)
						{
							if (this->direction != "down")
							{
								this->direction = "down";
								this->scanNextTurn();
							}
						}
						if (this->airFlag)
						{
							if (this->airGo != 3)
							{
								this->airGo = 3;
							}
						}
					}
					else if (this->getPosition().y < this->this_pt.y && this->this_pt.y - this->getPosition().y >= this->speedK * 0.5)
					{
						if (this->speedK > 0)
						{
							if (this->direction != "up")
							{
								this->direction = "up";
								this->scanNextTurn();
							}
						}
						if (this->airFlag)
						{
							if (this->airGo != 2)
							{
								this->airGo = 2;
							}
						}
					}
				}
			}
		}// end function
		void Unit::scanNextTurn() //public function scanNextTurn() : void
		{
			if (!this->nextTurnFlag)
			{
				this->nextTurnFlag = true;
				bezier::PathPoint ppo = this->world->bezierClass->getPathPoint(this->path, this->road, this->way);
				this->j = 10;
				this->n = 20;
				this->i = this->path;
				bezier::PathPoint po(0, 0);
				while (this->i < this->finishPath)
				{
					po = this->world->bezierClass->getPathPoint(this->i, this->road, this->way);
					if (po.x < ppo.x - this->n)
					{
						break;
					}
					else if (po.x > ppo.x + this->n)
					{
						break;
					}
					this->i = this->i + this->j;
				}
				this->nextTurnPoint = po;// new cocos2d::Point(po.x, po.y);
				this->nextTurnPath = this->i;
				this->nextTurnMidPath = this->path + (this->nextTurnPath - this->path) * 0.25;
			}
			//return;
		}// end function
		void Unit::setVerticalTurn() //public function setVerticalTurn() : void
		{
			if (this->this_pt.x > this->nextTurnPoint.x)
			{
				if (this->container->getScaleX() > 0)
				{
					this->setTurn("left");
				}
			}
			else if (this->this_pt.x < this->nextTurnPoint.x)
			{
				if (this->container->getScaleX() < 0)
				{
					this->setTurn("right");
				}
			}
			//return;
		}// end function
		void Unit::setTurn(string param1) //public function setTurn(param1:String) : void
		{
			if (param1 == "left")
			{
				if (this->container->getScaleX() > 0)
				{
					this->container->setScaleX(this->container->getScaleX() * -1);
					this->container->healthBar->setScaleX(this->container->healthBar->getScaleX() * -1);
					this->container->healthBar->setPositionX(this->container->healthBar->getPositionX() * -1);
				}
			}
			else if (param1 == "right")
			{
				if (this->container->getScaleX() < 0)
				{
					this->container->setScaleX(this->container->getScaleX() * -1);
					this->container->healthBar->setScaleX(this->container->healthBar->getScaleX() * -1);
					this->container->healthBar->setPositionX(this->container->healthBar->getPositionX() * -1);
				}
			}
			//return;
		}// end function
		void Unit::atStageManage() //public function atStageManage() : void
		{
			if (!this->atStaged)
			{
				if (this->world->nowLevel == 6)
				{
					if (this->road == 2)
					{
						if (this->path > 129)
						{
							this->atStaged = true;
						}
						return;
					}
				}
				else if (this->world->nowLevel == 11)
				{
					if (this->road == 2)
					{
						if (this->path > 79)
						{
							this->atStaged = true;
						}
						return;
					}
				}
				else if (this->world->nowLevel == 13)
				{
					if (this->road == 2)
					{
						if (this->path > 50)
						{
							this->atStaged = true;
						}
						return;
					}
				}
				else if (this->world->nowLevel == 14)
				{
					if (this->road == 2)
					{
						if (this->path > 100)
						{
							this->atStaged = true;
						}
						return;
					}
				}
				if (this->this_pt.x > 0 && this->this_pt.y > 0 && this->this_pt.x < Main::SCREEN_WIDTH && this->this_pt.y < Main::SCREEN_HEIGHT)
				{
					this->atStaged = true;
				}
			}
			//return;
		}// end function
		void Unit::animationHandler() //public function animationHandler() : void
		{
			if (this->container->healthBarCont->isVisible())
			{
				if (this->container->healthBarCounter < 2)
				{
					this->container->healthBarCounter++;
				}
				else
				{
					this->container->healthBarCont->setVisible(false);
				}
			}
			//播放火击中效果
			if (this->container->fireAttack->isVisible())
			{
				if (this->container->fireAttack->currentFrame < this->container->fireAttack->totalFrames)
				{
					this->container->fireAttack->gotoAndStop((this->container->fireAttack->currentFrame + 1));
				}
				else
				{
					this->container->fireAttack->setVisible(false);
				}
			}
			if (this->container->iceAttack->isVisible())
			{
				if (this->container->iceAttack->currentFrame < this->container->iceAttack->totalFrames)
				{
					this->container->iceAttack->gotoAndStop((this->container->iceAttack->currentFrame + 1));
				}
				else
				{
					this->container->iceAttack->setVisible(false);
				}
			}
			if (this->container->levinAttack->isVisible())
			{
				if (this->container->levinAttack->currentFrame < this->container->levinAttack->totalFrames)
				{
					this->container->levinAttack->gotoAndStop((this->container->levinAttack->currentFrame + 1));
				}
				else
				{
					this->container->levinAttack->setVisible(false);
				}
			}
			if (this->fireEffectFlag)
			{
				if (!this->container->fireEffect->isVisible())
				{
					this->container->fireEffect->setVisible(true);
					this->container->fireEffect->gotoAndStop(1);
					if (this->icemanFlag)
					{
						this->stopAllEffects("fireEffect");
					}
				}
				else if (this->fireEffectCounter > 0)
				{
					this->fireEffectCounter--;
					if (this->atStaged && this->readyDamage)
					{
						this->getHit(this->fireEffectDamage, "fire", 1, false);
					}
					if (this->dead)
					{
						return;
					}
					if (this->container->fireEffect->currentFrame < this->container->fireEffect->totalFrames)
					{
						this->container->fireEffect->gotoAndStop((this->container->fireEffect->currentFrame + 1));
					}
					else
					{
						this->container->fireEffect->gotoAndStop(20);
					}
				}
				else
				{
					this->fireEffectFlag = false;
					this->container->fireEffect->stop();
					this->container->fireEffect->setVisible(false);
				}
			}
			if (this->iceEffectFlag)
			{
				if (!this->container->iceEffect->isVisible())
				{
					this->container->iceEffect->setVisible(true);
					this->container->iceEffect->gotoAndStop(1);
					if (this->icemanFlag)
					{
						this->stopAllEffects("iceEffect");
					}
				}
				else if (this->iceEffectCounter > 0)
				{
					this->iceEffectCounter--;
					if (this->container->iceEffect->currentFrame < this->container->iceEffect->totalFrames)
					{
						this->container->iceEffect->gotoAndStop((this->container->iceEffect->currentFrame + 1));
					}
					else
					{
						this->container->iceEffect->gotoAndStop(16);
					}
				}
				else if (this->container->iceEffect->currentFrame > 16)
				{
					if (this->container->iceEffect->currentFrame < this->container->iceEffect->totalFrames)
					{
						this->container->iceEffect->gotoAndStop((this->container->iceEffect->currentFrame + 1));
					}
					else
					{
						this->container->iceEffect->gotoAndStop(16);
					}
				}
				else if (this->container->iceEffect->currentFrame > 1)
				{
					this->container->iceEffect->gotoAndStop((this->container->iceEffect->currentFrame - 1));
				}
				else
				{
					this->iceEffectFlag = false;
					this->container->iceEffect->stop();
					this->container->iceEffect->setVisible(false);
				}
			}
			if (this->healthPlusFlag)
			{
				if (!this->container->buffHP->isVisible())
				{
					this->container->buffHP->setVisible(true);
					this->container->buffHP->gotoAndStop(1);
				}
				else if (this->container->buffHP->currentFrame < this->container->buffHP->totalFrames)
				{
					this->container->buffHP->gotoAndStop((this->container->buffHP->currentFrame + 1));
					if (this->health + this->healthPlusValue < this->healthMax)
					{
						this->health = this->health + this->healthPlusValue;
						this->container->healthBar->cont->setScaleX(this->health / this->healthMax);
					}
					else if (this->container->healthBar->isVisible())
					{
						this->container->healthBar->setVisible(false);
						this->container->healthBar->cont->setScaleX(1);
						this->health = this->healthMax;
					}
				}
				else
				{
					this->healthPlusFlag = false;
					this->container->buffHP->setVisible(false);
				}
			}
			if (this->armorFlag)
			{
				if (this->armorCounter > 0 && this->armorPower > 0)
				{
					(this->armorCounter - 1);
					if (!this->container->armor->isVisible())
					{
						this->container->armor->setVisible(true);
						this->container->armor->gotoAndStop(1);
					}
					else if (this->container->armor->currentFrame < this->container->armor->totalFrames)
					{
						this->container->armor->gotoAndStop((this->container->armor->currentFrame + 1));
					}
					else
					{
						this->container->armor->gotoAndStop(16);
					}
				}
				else
				{
					this->armorFlag = false;
					this->container->armor->setVisible(false);
				}
			}
			else if (this->armorCounter > 0)
			{
				this->armorFlag = true;
			}
			if (this->airShockFlag)
			{
				if (!this->container->airShock->isVisible())
				{
					this->container->airShock->setVisible(true);
					this->container->airShock->gotoAndStop(1);
					if (this->icemanFlag)
					{
						this->stopAllEffects("airShock");
					}
				}
				else if (this->airShockCounter > 0)
				{
					this->airShockCounter--;
					//if (this->container->airShock->currentFrame < this->container->airShock->totalFrames)
					//{
					//	this->container->airShock->gotoAndStop((this->container->airShock->currentFrame + 1));
					//}
					//else
					//{
					//	this->container->airShock->gotoAndStop(1);
					//}
				}
				else
				{
					this->airShockFlag = false;
					this->container->airShock->setVisible(false);
				}
			}
			if (this->speedPlusFlag)
			{
				if (!this->container->buffSpeed->isVisible())
				{
					this->container->buffSpeed->setVisible(true);
					this->container->buffSpeed->gotoAndStop(1);
				}
				else if (this->speedPlusCounter > 0)
				{
					this->speedPlusCounter--;
					if (this->container->buffSpeed->currentFrame < this->container->buffSpeed->totalFrames)
					{
						this->container->buffSpeed->gotoAndStop((this->container->buffSpeed->currentFrame + 1));
					}
					else
					{
						this->container->buffSpeed->gotoAndStop(1);
					}
				}
				else
				{
					this->speedPlusFlag = false;
					this->container->buffSpeed->stop();
					this->container->buffSpeed->setVisible(false);
				}
			}
			if (this->airGo > 0)
			{
				if (this->airFlag)
				{
					if (this->airGo == 1)
					{
						if (this->container->dust2->isVisible())
						{
							this->container->dust2->setVisible(false);
						}
						if (this->container->dust3->isVisible())
						{
							this->container->dust3->setVisible(false);
						}
						if (this->container->dust4->isVisible())
						{
							this->container->dust4->setVisible(false);
						}
						if (!this->container->dust1->isVisible())
						{
							this->container->dust1->setVisible(true);
							this->container->dust1->gotoAndStop(1);
						}
						else if (this->container->dust1->currentFrame < this->container->dust1->totalFrames)
						{
							this->container->dust1->gotoAndStop((this->container->dust1->currentFrame + 1));
						}
						else
						{
							this->container->dust1->gotoAndStop(1);
						}
					}
					else if (this->airGo == 2)
					{
						if (this->container->dust1->isVisible())
						{
							this->container->dust2->setVisible(false);
						}
						if (this->container->dust4->isVisible())
						{
							this->container->dust3->setVisible(false);
						}
						if (!this->container->dust2->isVisible() || !this->container->dust4->isVisible())
						{
							this->container->dust2->setVisible(true);
							this->container->dust3->setVisible(true);
							this->container->dust2->gotoAndStop(1);
							this->container->dust3->gotoAndStop(1);
						}
						else
						{
							if (this->container->dust2->currentFrame < this->container->dust2->totalFrames)
							{
								this->container->dust2->gotoAndStop((this->container->dust2->currentFrame + 1));
							}
							else
							{
								this->container->dust2->gotoAndStop(1);
							}
							if (this->container->dust3->currentFrame < this->container->dust3->totalFrames)
							{
								this->container->dust3->gotoAndStop((this->container->dust3->currentFrame + 1));
							}
							else
							{
								this->container->dust3->gotoAndStop(1);
							}
						}
					}
					else if (this->airGo == 3)
					{
						if (this->container->dust1->isVisible())
						{
							this->container->dust2->setVisible(false);
						}
						if (this->container->dust2->isVisible())
						{
							this->container->dust3->setVisible(false);
						}
						if (this->container->dust3->isVisible())
						{
							this->container->dust4->setVisible(false);
						}
						if (!this->container->dust4->isVisible())
						{
							this->container->dust4->setVisible(true);
							this->container->dust4->gotoAndStop(1);
						}
						else if (this->container->dust4->currentFrame < this->container->dust4->totalFrames)
						{
							this->container->dust4->gotoAndStop((this->container->dust4->currentFrame + 1));
						}
						else
						{
							this->container->dust4->gotoAndStop(1);
						}
					}
				}
				else
				{
					this->airGo = 0;
					if (this->container->dust1->isVisible())
					{
						this->container->dust1->setVisible(false);
					}
					if (this->container->dust2->isVisible())
					{
						this->container->dust2->setVisible(false);
					}
					if (this->container->dust3->isVisible())
					{
						this->container->dust3->setVisible(false);
					}
					if (this->container->dust4->isVisible())
					{
						this->container->dust4->setVisible(false);
					}
				}
			}
			if (this->icemanFlag)
			{
				if (!this->container->iceFreez->isVisible())
				{
					this->container->iceFreez->setVisible(true);
					this->container->iceFreez->gotoAndStop(1);
					this->stopAllEffects("fireEffect");
					this->stopAllEffects("iceEffect");
					this->stopAllEffects("airShock");
					this->stopAllEffects("armor");
				}
				else if (this->icemanCounter > 0)
				{
					this->icemanCounter--;
					if (this->container->iceFreez->currentFrame < 45)
					{
						this->container->iceFreez->gotoAndStop((this->container->iceFreez->currentFrame + 1));
					}
					else
					{
						this->container->iceFreez->gotoAndStop(1);
					}
					if (this->icemanCounter % 30 == 0)
					{
						this->getHit(Main::mainClass->readXMLClass.castIcemanDamageXML, "ice", 1, false, 0);
					}
				}
				else
				{
					if (this->container->iceFreez->currentFrame < 46)
					{
						this->container->iceFreez->gotoAndStop(46);
					}
					if (this->container->iceFreez->currentFrame < this->container->iceFreez->totalFrames)
					{
						this->container->iceFreez->gotoAndStop((this->container->iceFreez->currentFrame + 1));
						if (this->container->iceFreez->currentFrame == 46)
						{
							//Sounds.instance.playSound("snd_unit_floeCrash");
						}
					}
					else
					{
						this->container->iceFreez->stop();
						this->icemanFlag = false;
						this->container->iceFreez->setVisible(false);
						//Sounds.instance.playSound("snd_unit_floeShards");
					}
				}
			}
			if (this->dead && this->container->iceDeath)
			{
				if (this->container->iceDeath->isVisible())
				{
					if (this->container->iceDeath->currentFrame < this->container->iceDeath->totalFrames)
					{
						this->container->iceDeath->gotoAndStop((this->container->iceDeath->currentFrame + 1));
						if (this->container->iceDeath->currentFrame == 9)
						{
							this->container->cont->setVisible(false);
						}
					}
					else if (this->container->getOpacity() > 0)
						this->container->setOpacity(this->container->getOpacity() - 0.25 * this->container->getOpacity());
					else
						this->removeUnitAfterDeathAnima();
				}
				else if (this->container->stoneDeath->isVisible())
				{
					if (this->container->stoneDeath->currentFrame < this->container->stoneDeath->totalFrames)
					{
						this->container->stoneDeath->gotoAndStop((this->container->stoneDeath->currentFrame + 1));
						if (this->container->stoneDeath->currentFrame == 9)
						{
							this->container->cont->setVisible(false);
						}
					}
					if (this->container->stoneDeath->currentFrame < this->container->stoneDeath->totalFrames)
					{
						this->container->stoneDeath->gotoAndStop((this->container->stoneDeath->currentFrame + 1));
						if (this->container->stoneDeath->currentFrame == 3)
						{
							this->container->cont->setVisible(false);
						}
					}
					else
					{
						this->removeUnitAfterDeathAnima();
					}
				}
				else if (this->container->levinDeath->isVisible())
				{
					if (this->container->levinDeath->currentFrame < this->container->levinDeath->totalFrames)
					{
						this->container->levinDeath->gotoAndStop((this->container->levinDeath->currentFrame + 1));
						if (this->container->levinDeath->currentFrame == 6)
						{
							this->container->cont->setVisible(false);
						}
					}
					else if (this->container->getOpacity() > 0)
						this->container->setOpacity(this->container->getOpacity() - 0.25 * this->container->getOpacity());
					else
						this->removeUnitAfterDeathAnima();
				}
			}
			//this->container->unitCase.x = this->container->unitCase.coordOrigin.x + this->container->cont.x;
			//this->container->unitCase.y = this->container->unitCase.coordOrigin.y + this->container->cont.y;
			//this->container->buffHP.x = this->container->buffHP.coordOrigin.x + this->container->cont.x;
			//this->container->buffHP.y = this->container->buffHP.coordOrigin.y + this->container->cont.y;
			//this->container->airShock.x = this->container->airShock.coordOrigin.x + this->container->cont.x;
			//this->container->airShock.y = this->container->airShock.coordOrigin.y + this->container->cont.y;
			//this->container->buffSpeed.x = this->container->buffSpeed.coordOrigin.x + this->container->cont.x;
			//this->container->buffSpeed.y = this->container->buffSpeed.coordOrigin.y + this->container->cont.y;
			//this->container->dust1.x = this->container->dust1.coordOrigin.x + this->container->cont.x;
			//this->container->dust1.y = this->container->dust1.coordOrigin.y + this->container->cont.y;
			//this->container->dust2.x = this->container->dust2.coordOrigin.x + this->container->cont.x;
			//this->container->dust2.y = this->container->dust2.coordOrigin.y + this->container->cont.y;
			//this->container->dust3.x = this->container->dust3.coordOrigin.x + this->container->cont.x;
			//this->container->dust3.y = this->container->dust3.coordOrigin.y + this->container->cont.y;
			//this->container->fireAttack.x = this->container->fireAttack.coordOrigin.x + this->container->cont.x;
			//this->container->fireAttack.y = this->container->fireAttack.coordOrigin.y + this->container->cont.y;
			//this->container->iceAttack.x = this->container->iceAttack.coordOrigin.x + this->container->cont.x;
			//this->container->iceAttack.y = this->container->iceAttack.coordOrigin.y + this->container->cont.y;
			//this->container->levinAttack.x = this->container->levinAttack.coordOrigin.x + this->container->cont.x;
			//this->container->levinAttack.y = this->container->levinAttack.coordOrigin.y + this->container->cont.y;
			//this->container->iceFreez.x = this->container->iceFreez.coordOrigin.x + this->container->cont.x;
			//this->container->iceFreez.y = this->container->iceFreez.coordOrigin.y + this->container->cont.y;
			//this->container->fireEffect.x = this->container->fireEffect.coordOrigin.x + this->container->cont.x;
			//this->container->fireEffect.y = this->container->fireEffect.coordOrigin.y + this->container->cont.y;
			//this->container->iceEffect.x = this->container->iceEffect.coordOrigin.x + this->container->cont.x;
			//this->container->iceEffect.y = this->container->iceEffect.coordOrigin.y + this->container->cont.y;
			//this->container->armor.x = this->container->armor.coordOrigin.x + this->container->cont.x;
			//this->container->armor.y = this->container->armor.coordOrigin.y + this->container->cont.y;
			//this->container->healthBar->x = this->container->healthBar->coordOrigin.x + this->container->cont.x;
			//this->container->healthBar->y = this->container->healthBar->coordOrigin.y + this->container->cont.y;
			//this->container->dust4.x = this->container->dust4.coordOrigin.x + this->container->cont.x;
			//this->container->dust4.y = this->container->dust4.coordOrigin.y + this->container->cont.y;
			//if (this->typeUnit != 3 && this->typeUnit != 8 && this->typeUnit != 13)
			//{
			//	this->container->selectUnit.x = this->container->selectUnit.coordOrigin.x + this->container->cont.x;
			//	this->container->selectUnit.y = this->container->selectUnit.coordOrigin.y + this->container->cont.y;
			//}
			//if (this->container->iceDeath)
			//{
			//	this->container->iceDeath.x = this->container->iceDeath.coordOrigin.x + this->container->cont.x;
			//	this->container->iceDeath.y = this->container->iceDeath.coordOrigin.y + this->container->cont.y;
			//	this->container->stoneDeath.x = this->container->stoneDeath.coordOrigin.x + this->container->cont.x;
			//	this->container->stoneDeath.y = this->container->stoneDeath.coordOrigin.y + this->container->cont.y;
			//	this->container->levinDeath.x = this->container->levinDeath.coordOrigin.x + this->container->cont.x;
			//	this->container->levinDeath.y = this->container->levinDeath.coordOrigin.y + this->container->cont.y;
			//}
			//if (this->container->signal)
			//{
			//	this->container->signal.x = this->container->signal.coordOrigin.x + this->container->cont.x;
			//	this->container->signal.y = this->container->signal.coordOrigin.y + this->container->cont.y;
			//}
			//if (this->typeUnit == 28)
			//{
			//	this->container->giveHealth1.x = this->container->giveHealth1.coordOrigin.x + this->container->cont.x;
			//	this->container->giveHealth1.y = this->container->giveHealth1.coordOrigin.y + this->container->cont.y;
			//	this->container->giveHealth2.x = this->container->giveHealth2.coordOrigin.x + this->container->cont.x;
			//	this->container->giveHealth2.y = this->container->giveHealth2.coordOrigin.y + this->container->cont.y;
			//	this->container->giveHealth3.x = this->container->giveHealth3.coordOrigin.x + this->container->cont.x;
			//	this->container->giveHealth3.y = this->container->giveHealth3.coordOrigin.y + this->container->cont.y;
			//}
			//else if (this->typeUnit == 29 || this->typeUnit == 30)
			//{
			//	this->container->dustAnima.x = this->container->dustAnima.coordOrigin.x + this->container->cont.x;
			//	this->container->dustAnima.y = this->container->dustAnima.coordOrigin.y + this->container->cont.y;
			//}
			//return;
		}// end function

		////public function getHit(param1:Number, param2:String = "无", param3:int = 0, param4:Boolean = false, param5:int = 0, param6:Object = null) : void
		void Unit::getHit(float param1, string param2, int  param3, bool param4, int param5, ShootBase * param6)
		{
			if (!this->readyDamage)return; 
			if (param1 > 0)
			{
				this->container->healthBarCounter = 0;
				this->container->healthBar->setVisible(true);
			}
			float tempObject = param1;
			if (param2 != "none")
			{
				this->lastAttackType = param2;
			}
			if (param2 == "fire")
			{
				if (param5)
				{
					 tempObject = param1 * this->fireDamageK;
					if (!this->container->fireAttack->isVisible() && this->typeUnit != 34)
					{
						this->container->fireAttack->setVisible(true);
						this->container->fireAttack->play("fireattack");
					}
					if (this->typeUnit != 23)
					{
						if (param4 && this->fireDamageK > 0)
						{
							this->fireEffectFlag = true;
							this->fireEffectCounter = 30;
							this->fireEffectDamage =  tempObject * Main::mainClass->readXMLClass.towerFireEffectDamageXML / this->fireEffectCounter;
						}
					}
					else if (param5 == 0 || param5 == 1)
					{
						this->healthPlusFlag = true;
						this->healthPlusValue = param1 * Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
						this->healthPlusValue = this->healthPlusValue / 25;// this->container->buffHP->totalFrames;
					}
				}
				else if (this->typeUnit != 23)
				{
					if (param4 && this->fireDamageK > 0)
					{
						this->fireEffectFlag = true;
						this->fireEffectCounter = 30;
						this->fireEffectDamage =  tempObject * Main::mainClass->readXMLClass.fireEffectDamageXML / this->fireEffectCounter;
					}
				}
				else if (param5 == 0 || param5 == 1)
				{
					 tempObject = 0;
					this->healthPlusFlag = true;
					this->healthPlusValue = param1 * Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
					this->healthPlusValue = this->healthPlusValue / 25;//  this->container->buffHP->totalFrames;
				}
			}
			else if (param2 == "ice")
			{
				if (param5)
				{
				     tempObject = param1 * this->iceDamageK;
					if (!this->container->iceAttack->isVisible() && this->typeUnit != 34)
					{
						this->container->iceAttack->setVisible(true);
						this->container->iceAttack->play("iceattack");
					}
					if (this->typeUnit != 24 && this->typeUnit != 34)
					{
						if (param4 && this->iceDamageK > 0 && this->icemanCounter == 0)
						{
							if (param3 == 1)
							{
								if (Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[0] < 1)
								{
									if (!this->iceEffectFlag)
									{
										this->iceEffectFlag = true;
										this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[0];
										this->iceEffectCounter = Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[4];
									}
									else if (this->iceEffectSlowdown >= this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[0])
									{
										this->iceEffectSlowdown = this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[0];
										this->iceEffectCounter = Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[4];
									}
								}
							}
							else if (param3 == 2)
							{
								if (Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[1] < 1)
								{
									if (!this->iceEffectFlag)
									{
										this->iceEffectFlag = true;
										this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[1];
										this->iceEffectCounter = Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[5];
									}
									else if (this->iceEffectSlowdown >= this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[1])
									{
										this->iceEffectSlowdown = this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[1];
										this->iceEffectCounter = Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[5];
									}
								}
							}
							else if (param3 == 3)
							{
								if (Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[2] < 1)
								{
									if (!this->iceEffectFlag)
									{
										this->iceEffectFlag = true;
										this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[2];
										this->iceEffectCounter = Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[6];
									}
									else if (this->iceEffectSlowdown >= this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[2])
									{
										this->iceEffectSlowdown = this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[2];
										this->iceEffectCounter = Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[6];
									}
								}
							}
							else if (param3 == 4)
							{
								if (Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[3] < 1)
								{
									if (!this->iceEffectFlag)
									{
										this->iceEffectFlag = true;
										this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[3];
										this->iceEffectCounter = Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[7];
									}
									else if (this->iceEffectSlowdown >= this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[3])
									{
										this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[3];
										this->iceEffectCounter = Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[7];
									}
								}
							}
						}
					}
					else if (this->typeUnit == 24)
					{
						if ((param5 == 0 || param5 == 2) && !this->icemanFlag)
						{
							if (param3 == 1)
							{
								if (Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[0] < 1)
								{
									if (!this->speedPlusFlag)
									{
										this->speedPlusFlag = true;
										this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[0]) * this->speedKRun;
										this->speedPlusCounter = this->speedRunTimerIce1;
									}
									else if (this->speedPlusValue <= this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[0]) * this->speedKRun)
									{
										this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[0]) * this->speedKRun;
										this->speedPlusCounter = this->speedRunTimerIce1;
									}
								}
							}
							else if (param3 == 2)
							{
								if (Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[1] < 1)
								{
									if (!this->speedPlusFlag)
									{
										this->speedPlusFlag = true;
										this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[1]) * this->speedKRun;
										this->speedPlusCounter = this->speedRunTimerIce2;
									}
									else if (this->speedPlusValue <= this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[1]) * this->speedKRun)
									{
										this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[1]) * this->speedKRun;
										this->speedPlusCounter = this->speedRunTimerIce2;
									}
								}
							}
							else if (param3 == 3)
							{
								if (Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[2] < 1)
								{
									if (!this->speedPlusFlag)
									{
										this->speedPlusFlag = true;
										this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[2]) * this->speedKRun;
										this->speedPlusCounter = this->speedRunTimerIce3;
									}
									else if (this->speedPlusValue <= this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[2]) * this->speedKRun)
									{
										this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[2]) * this->speedKRun;
										this->speedPlusCounter = this->speedRunTimerIce3;
									}
								}
							}
							else if (param3 == 4)
							{
								if (Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[3] < 1)
								{
									if (!this->speedPlusFlag)
									{
										this->speedPlusFlag = true;
										this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[3]) * this->speedKRun;
										this->speedPlusCounter = this->speedRunTimerIce4;
									}
									else if (this->speedPlusValue <= this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[3]) * this->speedKRun)
									{
										this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.towerIceEffectSlowdownXML[3]) * this->speedKRun;
										this->speedPlusCounter = this->speedRunTimerIce4;
									}
								}
							}
						}
					}
				}
				else if (this->typeUnit != 24 && this->typeUnit != 34)
				{
					if (param4 && this->iceDamageK > 0 && this->icemanCounter == 0)
					{
						if (param3 == 1)
						{
							if (!this->iceEffectFlag)
							{
								this->iceEffectFlag = true;
								this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown1XML;
								this->iceEffectCounter = Main::mainClass->readXMLClass.iceEffectSlowdown1TimerXML;
							}
							else if (this->iceEffectSlowdown >= this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown1XML)
							{
								this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown1XML;
								this->iceEffectCounter = Main::mainClass->readXMLClass.iceEffectSlowdown1TimerXML;
							}
						}
						else if (param3 == 2)
						{
							if (!this->iceEffectFlag)
							{
								this->iceEffectFlag = true;
								this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown2XML;
								this->iceEffectCounter = Main::mainClass->readXMLClass.iceEffectSlowdown2TimerXML;
							}
							else if (this->iceEffectSlowdown >= this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown2XML)
							{
								this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown2XML;
								this->iceEffectCounter = Main::mainClass->readXMLClass.iceEffectSlowdown2TimerXML;
							}
						}
						else if (param3 == 3)
						{
							if (!this->iceEffectFlag)
							{
								this->iceEffectFlag = true;
								this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown3XML;
								this->iceEffectCounter = Main::mainClass->readXMLClass.iceEffectSlowdown3TimerXML;
							}
							else if (this->iceEffectSlowdown >= this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown3XML)
							{
								this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown3XML;
								this->iceEffectCounter = Main::mainClass->readXMLClass.iceEffectSlowdown3TimerXML;
							}
						}
						else if (param3 == 4)
						{
							if (!this->iceEffectFlag)
							{
								this->iceEffectFlag = true;
								this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown4XML;
								this->iceEffectCounter = Main::mainClass->readXMLClass.iceEffectSlowdown4TimerXML;
							}
							else if (this->iceEffectSlowdown >= this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown4XML)
							{
								this->iceEffectSlowdown = this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown4XML;
								this->iceEffectCounter = Main::mainClass->readXMLClass.iceEffectSlowdown4TimerXML;
							}
						}
					}
				}
				else if (this->typeUnit == 24)
				{
					if ((param5 == 0 || param5 == 2) && !this->icemanFlag)
					{
						 tempObject = 0;
						if (param3 == 1)
						{
							if (!this->speedPlusFlag)
							{
								this->speedPlusFlag = true;
								this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown1XML) * this->speedKRun;
								this->speedPlusCounter = this->speedRunTimerIce1;
							}
							else if (this->speedPlusValue <= this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown1XML) * this->speedKRun)
							{
								this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown1XML) * this->speedKRun;
								this->speedPlusCounter = this->speedRunTimerIce1;
							}
						}
						else if (param3 == 2)
						{
							if (!this->speedPlusFlag)
							{
								this->speedPlusFlag = true;
								this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown2XML) * this->speedKRun;
								this->speedPlusCounter = this->speedRunTimerIce2;
							}
							else if (this->speedPlusValue <= this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown2XML) * this->speedKRun)
							{
								this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown2XML) * this->speedKRun;
								this->speedPlusCounter = this->speedRunTimerIce2;
							}
						}
						else if (param3 == 3)
						{
							if (!this->speedPlusFlag)
							{
								this->speedPlusFlag = true;
								this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown3XML) * this->speedKRun;
								this->speedPlusCounter = this->speedRunTimerIce3;
							}
							else if (this->speedPlusValue <= this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown3XML) * this->speedKRun)
							{
								this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown3XML) * this->speedKRun;
								this->speedPlusCounter = this->speedRunTimerIce3;
							}
						}
						else if (param3 == 4)
						{
							if (!this->speedPlusFlag)
							{
								this->speedPlusFlag = true;
								this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown4XML) * this->speedKRun;
								this->speedPlusCounter = this->speedRunTimerIce4;
							}
							else if (this->speedPlusValue <= this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown4XML) * this->speedKRun)
							{
								this->speedPlusValue = this->speedKSave + (this->speedKSave - this->speedKSave * Main::mainClass->readXMLClass.iceEffectSlowdown4XML) * this->speedKRun;
								this->speedPlusCounter = this->speedRunTimerIce4;
							}
						}
					}
				}
			}
			else if (param2 == "stone")
			{
				if (param5)
				{
					 tempObject = param1 * this->stoneDamageK;
					if (this->typeUnit != 25)
					{
						if (param4)
						{
						}
					}
					else if (param5 == 0 || param5 == 3)
					{
						this->i = 0;
						while (this->i < this->world->listOfUnits.size())
						{
							if (this->world->listOfUnits[this->i] != this)
							{
								if (this->this_pt.distance(this->world->listOfUnits[this->i]->this_pt) < Main::mainClass->readXMLClass.towerStoneEffectRadiusXML)
								{
									if (param3 == 1)
									{
										this->world->listOfUnits[this->i]->armorPower = param1;
										this->world->listOfUnits[this->i]->armorCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
									}
									else if (param3 == 2)
									{
										this->world->listOfUnits[this->i]->armorPower = param1;
										this->world->listOfUnits[this->i]->armorCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
									}
									else if (param3 == 3)
									{
										this->world->listOfUnits[this->i]->armorPower = param1;
										this->world->listOfUnits[this->i]->armorCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
									}
									else if (param3 == 4)
									{
										this->world->listOfUnits[this->i]->armorPower = param1;
										this->world->listOfUnits[this->i]->armorCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
									}
								}
							}
							i++;
						}
					}
				}
				else if (this->typeUnit != 25)
				{
					if (param4)
					{
					}
				}
				else if (param5 == 0 || param5 == 3)
				{
					 tempObject = 0;
					this->i = 0;
					while (this->i < this->world->listOfUnits.size())
					{
						if (this->world->listOfUnits[this->i] != this)
						{
							if (this->this_pt.distance(this->world->listOfUnits[this->i]->this_pt) < Main::mainClass->readXMLClass.towerStoneEffectRadiusXML)
								//if(Point.distance(this->this_pt, this->world->listOfUnits[this->i].this_pt) < Main::mainClass->readXMLClass.stoneEffectRadiusXML)
							{
								if (param3 == 1)
								{
									this->world->listOfUnits[this->i]->armorPower = param1;
									this->world->listOfUnits[this->i]->armorCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
								}
								else if (param3 == 2)
								{
									this->world->listOfUnits[this->i]->armorPower = param1;
									this->world->listOfUnits[this->i]->armorCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
								}
								else if (param3 == 3)
								{
									this->world->listOfUnits[this->i]->armorPower = param1;
									this->world->listOfUnits[this->i]->armorCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
								}
								else if (param3 == 4)
								{
									this->world->listOfUnits[this->i]->armorPower = param1;
									this->world->listOfUnits[this->i]->armorCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(this->typeUnit - 1)][30];
								}
							}
						}
						i++;
					}
				}
			}
			else if (param2 == "levin")
			{
				if (param5)
				{
					 tempObject = param1 * this->levinDamageK;
					param3 = param3 + Main::mainClass->readXMLClass.levinCountPlus;
					if (!this->container->levinAttack->isVisible())
					{
						this->container->levinAttack->setVisible(true);
						this->container->levinAttack->play("levinattack");
					}
					if (this->typeUnit != 26)
					{
						if (param4)
						{
							this->i = 0;
							while (this->i < this->world->listOfUnits.size())
							{
								if (this->world->listOfUnits[this->i]->atStaged && this->world->listOfUnits[this->i]->readyDamage && this->world->listOfUnits[this->i] != this && this->typeUnit != 33)
								{
									if (this->world->listOfUnits[this->i]->this_pt.distance(this->this_pt) < Main::mainClass->readXMLClass.towerLevinEffectRadiusXML)
										//if(Point.distance(this->world->listOfUnits[this->i].this_pt, this->this_pt) < Main::mainClass->readXMLClass.towerLevinEffectRadiusXML)
									{
										Bullet * tempObject1 = this->world->addBullet(4, this->shoot_pt, this, this->world->listOfUnits[this->i], param1 * Main::mainClass->readXMLClass.towerLevinEffectDamageXML, 1);
										tempObject1->effectFlag = false;
										param3 = param3 - 1;
										if (param3 <= 0)
										{
											break;
										}
									}
								}
								i++;
							}
						}
					}
					else if (param5 == 0 || param5 == 4)
					{
						this->i = param3;
						while (this->i > 0)
						{
							this->listOfTornado.push(33);
							i++;
						}
					}
				}
				else if (this->typeUnit != 26)
				{
					if (param4)
					{
						this->i = 0;
						while (this->i < this->world->listOfUnits.size())
						{
							if (this->world->listOfUnits[this->i]->atStaged && this->world->listOfUnits[this->i]->readyDamage && this->world->listOfUnits[this->i] != this && this->typeUnit != 33)
							{
								if (this->world->listOfUnits[this->i]->this_pt.distance(this->this_pt) < Main::mainClass->readXMLClass.levinEffectRadiusXML)
									//if(Point.distance(this->world->listOfUnits[this->i].this_pt, this->this_pt) < Main::mainClass->readXMLClass.levinEffectRadiusXML)
								{
									Bullet * tempObject1 = this->world->addBullet(4, this->shoot_pt, this, this->world->listOfUnits[this->i], param1 * Main::mainClass->readXMLClass.towerLevinEffectDamageXML, 1);
									tempObject1->effectFlag = false;
									tempObject1->setVisible(false);
									param3 = param3 - 1;
									if (param3 <= 0)
									{
										break;
									}
								}
							}
							i++;
						}
					}
				}
				else if (param5 == 0 || param5 == 4)
				{
					tempObject = 0;
					if (param4)
					{
						this->i = param3;
						while (this->i > 0)
						{
							this->listOfTornado.push(33);
							i++;
						}
					}
				}
			}
			if (!this->armorFlag)
			{
				this->health = this->health - tempObject;
			}
			else
			{
				this->armorPower = this->armorPower - tempObject;
				if (this->armorPower < 0)
				{
					this->health = this->health + this->armorPower;
				}
			}
			if (this->health < this->healthMax)
			{
				if (this->health > 0)
				{
					if (!this->container->healthBar->isVisible())
					{
						this->container->healthBar->setVisible(true);
					}
					this->container->healthBar->cont->setScaleX(this->health / this->healthMax);
				}
				else
				{
					this->kill();
				}
			}
			else
			{
				this->health = this->healthMax;
				if (this->container->healthBar->isVisible())
				{
					this->container->healthBar->setVisible(false);
				}
			}
		 
			//return;
		}// end function

		void Unit::setAirSettings(string param1) //public function setAirSettings(param1:String) : void
		{
			this->airFlag = true;
			this->traversedPath = 0;
			this->dampingAir = 0;
			if (param1 == "air")
			{
				this->airSpacing = Main::mainClass->readXMLClass.airSpacingXML * this->airResist;
				this->airPower = Main::mainClass->readXMLClass.airPowerXML * this->airResist;
				this->airShockCounter = Main::mainClass->readXMLClass.airWaitTimerXML;
			}
			else if (param1 == "tower71")
			{
				this->airSpacing = Main::mainClass->readXMLClass.ultraAddIceStoneSpacingXML * this->airResist;
				this->airPower = Main::mainClass->readXMLClass.ultraAddIceStonePowerXML * this->airResist;
				this->airShockCounter = Main::mainClass->readXMLClass.ultraAddIceStoneSlowdownTimerXML;
			}
			//return;
		}// end function
		void Unit::stopAllEffects(string param1) //public function stopAllEffects(param1:String = "") : void
		{
			if (param1 == "" || param1 == "healthBar")
			{
				if (this->container->healthBar->isVisible())
				{
					this->container->healthBar->setVisible(false);
					//this->container->healthBar->getDamage->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "shadow")
			{
				if (this->container->shadow)
				{
					if (this->container->shadow->isVisible())
					{
						this->container->shadow->setVisible(false);
					}
				}
			}
			if (param1 == "" || param1 == "selectUnit")
			{
				if (this->container->selectUnit->isVisible())
				{
					this->container->selectUnit->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "buffHP")
			{
				if (this->healthPlusFlag)
				{
					this->healthPlusFlag = false;
					this->healthPlusValue = 0;
					this->container->buffHP->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "armor")
			{
				if (this->armorCounter > 0)
				{
					this->armorFlag = false;
					this->armorCounter = 0;
					this->container->armor->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "dust")
			{
				if (this->airFlag)
				{
					this->airFlag = false;
					this->airGo = 0;
					if (this->container->dust1->isVisible())
					{
						this->container->dust1->setVisible(false);
					}
					if (this->container->dust2->isVisible())
					{
						this->container->dust2->setVisible(false);
					}
					if (this->container->dust3->isVisible())
					{
						this->container->dust3->setVisible(false);
					}
					if (this->container->dust4->isVisible())
					{
						this->container->dust4->setVisible(false);
					}
				}
			}
			if (param1 == "" || param1 == "airShock")
			{
				if (this->airShockFlag)
				{
					this->airShockFlag = false;
					this->airShockCounter = 0;
					this->container->airShock->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "buffSpeed")
			{
				if (this->speedPlusFlag)
				{
					this->speedPlusFlag = false;
					this->speedPlusCounter = 0;
					this->container->buffSpeed->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "iceFreez")
			{
				if (this->icemanFlag)
				{
					this->icemanFlag = false;
					this->icemanCounter = 0;
					this->container->iceFreez->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "fireEffect")
			{
				if (this->fireEffectFlag)
				{
					this->fireEffectFlag = false;
					this->fireEffectCounter = 0;
					this->container->fireEffect->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "iceEffect")
			{
				if (this->iceEffectFlag)
				{
					this->iceEffectFlag = false;
					this->iceEffectCounter = 0;
					this->container->iceEffect->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "fireAttack")
			{
				if (this->container->fireAttack->isVisible())
				{
					this->container->fireAttack->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "iceAttack")
			{
				if (this->container->iceAttack->isVisible())
				{
					this->container->iceAttack->setVisible(false);
				}
			}
			if (param1 == "" || param1 == "levinAttack")
			{
				if (this->container->levinAttack->isVisible())
				{
					this->container->levinAttack->setVisible(false);
				}
			}
			if (this->container->signal)
			{
				if (this->container->signal->isVisible())
				{
					this->container->signal->gotoAndStop(1);
					this->container->signal->setVisible(false);
				}
			}
			return;
		}// end function
		void Unit::removeUnitAfterDeathAnima() //public function removeUnitAfterDeathAnima() : void
		{
			//if (this->parent)
			//{
			this->world->removeChild(this, true);
			//this->i = 0;
			//while (this->i < this->world->listOfClasses.length)
			//{
			//	if (this->world->listOfClasses[this->i] == this)
			//	{
			//		this->world->listOfClasses.splice(this->i, 1);
			//		break;
			//	}
			//	i++;
			//}
			//this->i = 0;
			//while (this->i < this->world->listOfIndexes1.length)
			//{
			//	if (this->world->listOfIndexes1[this->i] == this)
			//	{
			//		this->world->listOfIndexes1.splice(this->i, 1);
			//		break;
			//	}
			//	i++;
			//}
			//}
			//return;
		}// end function
		void Unit::kill() //public function kill() : void
		{
			if (!this->dead)return;
			{
				this->dead = true;
				this->readyDamage = false;
				this->moveFlag = false;
				this->stopAllEffects();
				if (this->health <= 0)
				{
					if ((this->lastAttackType == "ice" || this->lastAttackType == "stone" || this->lastAttackType == "levin") && this->container->iceDeath)
					{
						if (this->lastAttackType == "ice")
						{
							this->container->iceDeath->setVisible(true);
							//Sounds.instance.playSoundWithVol("snd_unit_iceDeath", 0.75);
						}
						else if (this->lastAttackType == "stone")
						{
							this->container->stoneDeath->setVisible(true);
						}
						else if (this->lastAttackType == "levin")
						{
							this->container->levinDeath->setVisible(true);
							//Sounds.instance.playSound("snd_unit_levinDeath");
						}
						//this->mouseChildren = false;
						//this->mouseEnabled = false;
						//this->world->listOfClasses.push(this);
						//this->world->listOfIndexes1.push(this);
					}
					else
					{
						if (this->typeUnit != 20 && this->typeUnit != 21 && (this->typeUnit < 23 || this->typeUnit > 26) && this->typeUnit != 34)
						{
							//this->tempObject = new DeathEffect(this, NULL, 6, 0.2, 1);
							if (this->lastAttackType != "golem")
							{
								//Sounds.instance.playSound("snd_unit_fireDeath");
							}
						}
						this->world->removeChild(this);
					}
					this->world->money = this->world->money + this->gold;
					if (this->replacementFlag > 0)
					{
						this->i = 0;
						while (this->i < this->replacementCount)
						{
							if (this->world->wavesClass->listOfReplacement.size() == 0)
							{
								this->world->wavesClass->listOfReplacement[0][0] = 60;
								this->world->wavesClass->listOfReplacement[0][1] = this->replacementFlag == 1 ? 29 : 30;
								this->world->wavesClass->listOfReplacement[0][2] = this->road;
								this->world->wavesClass->listOfReplacement[0][3] = this->way;
								this->world->wavesClass->listOfReplacement[0][4] = this->path;
								//this->world->wavesClass->listOfReplacement.push([60, 29, this->road, this->way, this->path]);
							}
							else
							{
								int c = this->world->wavesClass->listOfReplacement.size();
								this->world->wavesClass->listOfReplacement[c][0] = this->world->wavesClass->listOfReplacement[(c - 1)][0] + 60;
								this->world->wavesClass->listOfReplacement[c][1] = 29;
								this->world->wavesClass->listOfReplacement[c][2] = this->road;
								this->world->wavesClass->listOfReplacement[c][3] = this->way;
								this->world->wavesClass->listOfReplacement[c][4] = this->path;
								//this->world->wavesClass->listOfReplacement.push([this->world->wavesClass->listOfReplacement[(c- 1)][0] + 60, 29, this->road, this->way, this->path]);
							}
							i++;
						}
						if (this->replacementFlag == 1)
						{
							this->i = 0;
							while (this->i < this->replacementCount)
							{
								if (this->world->wavesClass->listOfReplacement.size() == 0)
								{
									this->world->wavesClass->listOfReplacement[0][0] = 60;
									this->world->wavesClass->listOfReplacement[0][1] = 29;
									this->world->wavesClass->listOfReplacement[0][2] = this->road;
									this->world->wavesClass->listOfReplacement[0][3] = this->way;
									this->world->wavesClass->listOfReplacement[0][4] = this->path;
									//this->world->wavesClass->listOfReplacement.push([60, 29, this->road, this->way, this->path]);
								}
								else
								{
									int c = this->world->wavesClass->listOfReplacement.size();
									this->world->wavesClass->listOfReplacement[c][0] = this->world->wavesClass->listOfReplacement[(c - 1)][0] + 60;
									this->world->wavesClass->listOfReplacement[c][1] = 29;
									this->world->wavesClass->listOfReplacement[c][2] = this->road;
									this->world->wavesClass->listOfReplacement[c][3] = this->way;
									this->world->wavesClass->listOfReplacement[c][4] = this->path;
									//this->world->wavesClass->listOfReplacement.push([this->world->wavesClass->listOfReplacement[(c- 1)][0] + 60, 29, this->road, this->way, this->path]);
								}
								i++;
							}
						}
						else if (this->replacementFlag == 2)
						{
							this->i = 0;
							while (this->i < this->replacementCount)
							{
								if (this->world->wavesClass->listOfReplacement.size() == 0)
								{
									//this->world->wavesClass->listOfReplacement.push({ 60, 30, this->road, this->way, this->path });
									this->world->wavesClass->listOfReplacement[0][0] = 60;
									this->world->wavesClass->listOfReplacement[0][1] = 30;
									this->world->wavesClass->listOfReplacement[0][2] = this->road;
									this->world->wavesClass->listOfReplacement[0][3] = this->way;
									this->world->wavesClass->listOfReplacement[0][4] = this->path;
								}
								else
								{
									//this->world->wavesClass->listOfReplacement.push([this->world->wavesClass->listOfReplacement[(this->world->wavesClass->listOfReplacement.length - 1)][0] + 60, 30, this->road, this->way, this->path]);
									int c = this->world->wavesClass->listOfReplacement.size();
									this->world->wavesClass->listOfReplacement[c][0] = this->world->wavesClass->listOfReplacement[(c - 1)][0] + 60;
									this->world->wavesClass->listOfReplacement[c][1] = 30;
									this->world->wavesClass->listOfReplacement[c][2] = this->road;
									this->world->wavesClass->listOfReplacement[c][3] = this->way;
									this->world->wavesClass->listOfReplacement[c][4] = this->path;
								}
								i++;
							}
						}
					}
					int addit_killEnemiesCounter = this->world->saveBox->getIntValue("addit_killEnemiesCounter") + 1;
					this->world->saveBox->setValue("addit_killEnemiesCounter", addit_killEnemiesCounter);
					//(this->world->saveBox.gameSave.data.addit_killEnemiesCounter + 1);
					this->world->killEnemiesCounter++;
					if (addit_killEnemiesCounter == 1)
					{
						this->world->achieveManage("firstKill");
					}
					else if (addit_killEnemiesCounter == 2500)
					{
						this->world->achieveManage("kill_2500_enemies");
					}
					if (this->world->killEnemiesCounter == 100)
					{
						this->world->achieveManage("kill_100_enemies");
					}
				}
				else
				{
					if (this->world->live > 0)
					{
						//Sounds.instance.playSoundWithVol("snd_unit_finish", 0.9);
					}
					this->world->live = this->world->live - this->penalty;
					this->world->removeChild(this);
					if (this->world->live <= 0)
					{
						this->world->live = 0;
						if (this->world->saveBox->getIntValue("complexityLevel") < 4)
						{
							this->world->winDefCounter = 15;
						}
						else
						{
							this->world->winDefCounter = 1;
						}
					}
				}
				this->world->worldInterface->updateInfo();
				this->i = 0;
				while (this->i < this->world->listOfUnits.size())
				{
					if (this->world->listOfUnits[this->i] == this)
					{
						this->world->listOfUnits.remove(this->i);
						break;
					}
					i++;
				}
				if (this->world->selectObject == this)
				{
					this->world->worldInterface->barInfoManage();
				}
				if (this->world->live > 0 && this->world->wavesClass->nowWave == this->world->wavesClass->maxWaves && !this->world->wavesClass->waveWork)
				{
					int tempObject = 0;
					this->i = 0;
					while (this->i < this->world->listOfUnits.size())
					{
						if (!this->world->listOfUnits[this->i]->replaced)
						{
							 tempObject++;
						}
						i++;
					}
					if ( tempObject <= 3)
					{
						if (this->world->wavesClass->listOfReplacement.size() > 0)
						{
							this->world->wavesClass->listOfReplacement.clear();
						}
						this->i = 0;
						while (this->i < this->world->listOfUnits.size())
						{
							if (this->world->listOfUnits[this->i]->replacementFlag)
							{
								this->world->listOfUnits[this->i]->replacementFlag = false;
							}
							if (this->world->listOfUnits.size() <= 2)
							{
								if (this->world->listOfUnits[this->i]->typeUnit == 29 || this->world->listOfUnits[this->i]->typeUnit == 30)
								{
									this->world->listOfUnits[this->i]->stealthCounter = 0;
								}
							}
							i++;
						}
					}
					if (this->world->listOfUnits.size() == 0 && this->world->wavesClass->listOfReplacement.size() == 0)
					{
						bool tempObject = false;
						if (this->world->wavesClass->listOfWaves.size() > 0)
						{
							if (this->world->wavesClass->listOfWaves[0].size() > 0)
							{
								 tempObject = true;
							}
						}
						if (! tempObject)
						{
							if (this->world->wavesClass->listOfWaves.size() > 1)
							{
								if (this->world->wavesClass->listOfWaves[1].size() > 0)
								{
									 tempObject = true;
								}
							}
						}
						if (! tempObject)
						{
							if (this->world->wavesClass->listOfWaves.size() > 2)
							{
								if (this->world->wavesClass->listOfWaves[2].size() > 0)
								{
									 tempObject = true;
								}
							}
						}
						//if (!this->tempObject)
						//{
						//	this->i = 0;
						//	while(this->i < this->world->listOfClasses.size())
						//	{
						//		if (this->world->listOfClasses[this->i] is Unit)
						//		{
						//			if (!this->world->listOfClasses[this->i].dead)
						//			{
						//				this->tempObject = true;
						//				break;
						//			}
						//		}
						//		i++;
						//	}
						//}
						if (! tempObject)
						{
							if (this->typeUnit != 34)
							{
								this->world->winDefCounter = 60;
							}
							else
							{
								this->world->winDefCounter = 250;
							}
						}
					}
				}
			}
			//return;
		}// end function

	}
}
