
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		bool Unit_29::init()
		{
			phase = (1);
			typeUnit = 29;
			readyDamage = false;
			moveFlag = false;
			this->returnHealth = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][33];
			this->stealthTimer = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
			this->stealthCounter = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
			container = new Unit_mc(this, "Unit29_mc", typeUnit);
			container->setScale(0.85);
			container->init();
			Unit::init();
			this->autorelease();
			container->cont->gotoAndStop(68);
			this->setAlpha(0);
			this->setMouseChildren(false);
			this->setMouseEnabled(false);
			i = 0;
			while (i < world->listOfUnits.size())
			{
				if (world->listOfUnits[i] == this)
				{
					world->listOfUnits.splice(i, 1);
					break;
				}
				i++;
			}
			world->addClasses(this);
			//world->listOfIndexes0.push(this);
			return true;
		}// end function

		void Unit_29::animationHandler()
		{
			if (!dead)
			{
				if (readyDamage)
				{
					if (!icemanFlag && !airFlag && !airShockFlag)
					{
						if (direction != "up")
						{
							if (container->cont->currentFrame == 101)
							{
								container->cont->gotoAndStop(33);
							}
							else if (container->cont->currentFrame == 102)
							{
								container->cont->gotoAndStop(34);
							}
						}
						else if (container->cont->currentFrame == 33)
						{
							container->cont->gotoAndStop(101);
						}
						else if (container->cont->currentFrame == 34)
						{
							container->cont->gotoAndStop(102);
						}
						if (direction == "left" || direction == "right")
						{
							if (container->currentFrame > 24)
							{
								container->tryPlay();
								//container->gotoAndStop((container->currentFrame + 1));
								Vec2 pos = container->getPosition();
								if (pos.x >= -1 && pos.x <= 1 && pos.y >= -1 && pos.y <= 1)
								{
									container->gotoAndStop(1);
								}
								if (container->currentFrame < 33)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < 37)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
								else if (container->currentFrame < 44)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < container->totalFrames)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
							}
							else
							{
								if (container->currentFrame < 24)
								{
									container->tryPlay();
									//container->gotoAndStop((container->currentFrame + 1));
								}
								else
								{
									container->gotoAndStop(1);
								}
								if (container->currentFrame < 9)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < 13)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
								else if (container->currentFrame < 20)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < 24)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
							}
						}
						else if (direction == "up")
						{
							if (container->cont->currentFrame < 10)
							{
								container->cont->gotoAndStop(10);
							}
							if (container->currentFrame < 25)
							{
								container->tryPlay();
								//container->gotoAndStop((container->currentFrame + 1));
								Vec2 pos = container->getPosition();
								if (pos.x >= -1 && pos.x <= 1 && pos.y >= -1 && pos.y <= 1)
								{
									container->gotoAndStop(25);
								}
								if (container->currentFrame < 9)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < 13)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
								else if (container->currentFrame < 20)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < 24)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
							}
							else
							{
								if (container->currentFrame < container->totalFrames)
								{
									container->tryPlay();
									//container->gotoAndStop((container->currentFrame + 1));
								}
								else
								{
									container->gotoAndStop(25);
								}
								if (container->currentFrame < 33)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < 37)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
								else if (container->currentFrame < 44)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < container->totalFrames)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
							}
						}
						else if (direction == "down")
						{
							if (container->currentFrame < 25)
							{
								container->tryPlay();
								//container->gotoAndStop((container->currentFrame + 1));
								Vec2 pos = container->getPosition();
								if (pos.x >= -1 && pos.x <= 1 && pos.y >= -1 && pos.y <= 1)
								{
									container->gotoAndStop(25);
								}
								if (container->currentFrame < 9)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < 13)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
								else if (container->currentFrame < 20)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < 24)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
							}
							else
							{
								if (container->currentFrame < container->totalFrames)
								{
									container->tryPlay();
									//container->gotoAndStop((container->currentFrame + 1));
								}
								else
								{
									container->gotoAndStop(25);
								}
								if (container->currentFrame < 33)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < 37)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
								else if (container->currentFrame < 44)
								{
									if (!moveFlag)
									{
										moveFlag = true;
									}
								}
								else if (container->currentFrame < container->totalFrames)
								{
									if (moveFlag)
									{
										moveFlag = false;
									}
								}
							}
						}
					}
				}
				else if (!teleportFlag)
				{
					if (this->phase == 1)
					{
						if (container->cont->currentFrame >= 34 && container->cont->currentFrame <= 68)
						{
							if (this->getAlpha() < 1)
							{
								this->setAlpha(this->getAlpha() + 0.1);
							}
							else if (this->getAlpha() != 1)
							{
								this->setAlpha(1);
							}
							if (this->stealthCounter > 0)
							{
								this->stealthCounter--;
								if (this->stealthCounter <= 5)
								{
									if (container->dustAnima->getAlpha() > 0)
									{
										container->dustAnima->setAlpha(container->dustAnima->getAlpha() - 0.2);
									}
								}
							}
							else
							{
								if (container->dustAnima->isVisible())
								{
									container->dustAnima->setVisible(false);
									container->dustAnima->setAlpha(0);
									i = 0;
									while (i < world->listOfIndexes0.size())
									{
										if (world->listOfIndexes0[i] == this)
										{
											world->listOfIndexes0.splice(i, 1);
											break;
										}
										i++;
									}
									world->listOfIndexes1.push(this);
								}
								if (container->cont->currentFrame > 34)
								{
									container->cont->gotoAndStop((container->cont->currentFrame - 1));
								}
								else
								{
									i = 0;
									while (i < world->listOfClasses.size())
									{
										if (world->listOfClasses[i] == this)
										{
											world->listOfClasses.splice(i, 1);
											break;
										}
										i++;
									}
									i = 0;
									while (i < world->listOfIndexes1.size())
									{
										if (world->listOfIndexes1[i] == this)
										{
											world->listOfIndexes1.splice(i, 1);
											break;
										}
										i++;
									}
									world->listOfUnits.push(this);
									readyDamage = true;
									moveFlag = true;
									this->setMouseChildren(true);
									this->setMouseEnabled(true);
									this->stealthCounter = this->stealthTimer;
									this->phase = 2;
								}
							}
						}
					}
					else if (this->phase == 2)
					{
						if (container->cont->currentFrame >= 34 && container->cont->currentFrame <= 68)
						{
							if (container->cont->currentFrame < 68)
							{
								container->cont->tryPlay();
								//container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else if (!container->dustAnima->isVisible())
							{
								container->dustAnima->setVisible(true);
								container->cont->gotoAndStop(1);
							}
						}
						else if (container->cont->currentFrame >= 102 && container->cont->currentFrame <= 136)
						{
							if (container->cont->currentFrame < 136)
							{
								container->cont->tryPlay();
								//container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else if (!container->dustAnima->isVisible())
							{
								container->dustAnima->setVisible(true);
								container->cont->gotoAndStop(69);
							}
						}
						if (container->cont->currentFrame == 1 || container->cont->currentFrame == 69)
						{
							container->dustAnima->setAlpha(container->dustAnima->getAlpha() + 0.2);
							if (container->dustAnima->getAlpha() > 1)
							{
								container->dustAnima->setAlpha(1);
								i = 0;
								while (i < world->listOfIndexes1.size())
								{

									if (world->listOfIndexes1[i] == this)
									{
										world->listOfIndexes1.splice(i, 1);
										break;
									}
									i++;
								}
								world->listOfIndexes0.push(this);
								this->phase = 3;
							}
						}
					}
					else if (this->phase == 3)
					{
						if (container->cont->currentFrame == 1 || container->cont->currentFrame == 69)
						{
							if (this->stealthCounter > 0)
							{
								this->stealthCounter--;
								if (this->stealthCounter <= 5)
								{
									if (container->dustAnima->getAlpha() > 0)
									{
										container->dustAnima->setAlpha(container->dustAnima->getAlpha() - 0.2);
									}
								}
							}
							else if (container->dustAnima->isVisible())
							{
								container->dustAnima->setVisible(false);
								container->dustAnima->setAlpha(0);
								i = 0;
								while (i < world->listOfIndexes0.size())
								{
									if (world->listOfIndexes0[i] == this)
									{
										world->listOfIndexes0.splice(i, 1);
										break;
									}
									i++;
								}
								world->listOfIndexes1.push(this);
								this->phase = 4;
							}
						}
					}
					else if (this->phase == 4)
					{
						if (container->cont->currentFrame >= 1 && container->cont->currentFrame <= 33)
						{
							if (container->cont->currentFrame < 33)
							{
								container->cont->tryPlay();
								//container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
						}
						else if (container->cont->currentFrame >= 69 && container->cont->currentFrame <= 101)
						{
							if (container->cont->currentFrame < 101)
							{
								container->cont->tryPlay();
								//container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
						}
						if (container->cont->currentFrame == 33 || container->cont->currentFrame == 101)
						{
							i = 0;
							while (i < world->listOfClasses.size())
							{
								if (world->listOfClasses[i] == this)
								{
									world->listOfClasses.splice(i, 1);
									break;
								}
								i++;
							}
							i = 0;
							while (i < world->listOfIndexes1.size())
							{
								if (world->listOfIndexes1[i] == this)
								{
									world->listOfIndexes1.splice(i, 1);
									break;
								}
								i++;
							}
							world->listOfUnits.push(this);
							health = healthMax * this->returnHealth;
							container->healthBar->setVisible(true);
							container->healthBarCont->setScaleX(health / healthMax);
							readyDamage = true;
							moveFlag = true;
							this->setMouseChildren(true);
							this->setMouseEnabled(true);
							this->phase = 5;
						}
					}
					if (container->dustAnima->isVisible())
					{
						if (container->dustAnima->currentFrame < container->dustAnima->totalFrames)
						{
							container->dustAnima->tryPlay();
							//container->dustAnima->gotoAndStop((container->dustAnima->currentFrame + 1));
						}
						else
						{
							container->dustAnima->gotoAndStop(1);
						}
					}
				}
			}
			Unit::animationHandler();
			return;
		}// end function

		void Unit_29::kill()
		{
			if (!dead)
			{
			    this->world->removeClasses(this);
				//i = 0;
				//while (i < world->listOfClasses.size())
				//{
				//	if (world->listOfClasses[i] == this)
				//	{
				//		world->listOfClasses.splice(i, 1);
				//		break;
				//	}
				//	i++;
				//}
				//i = 0;
				//while (i < world->listOfIndexes0.size())
				//{
				//    
				//    if (world->listOfIndexes0[i] == this)
				//    {
				//        world->listOfIndexes0.splice(i, 1);
				//        break;
				//    }
				//    i++;
				//}
				//i = 0;
				//while (i < world->listOfIndexes1.size())
				//{
				//    if (world->listOfIndexes1[i] == this)
				//    {
				//        world->listOfIndexes1.splice(i, 1);
				//        break;
				//    }
				//    i++;
				//}
			}
			Unit::kill();
			return;
		}// end function

	}
}
