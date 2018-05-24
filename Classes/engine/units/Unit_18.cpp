
#include "Unit.h"
#include "MainClass.h"

namespace engine
{ 
	namespace units
	{
		Unit_18::Unit_18()
		{
			return;
		}// end function

		bool Unit_18::init()
		{
			typeUnit = 18;
			this->hiddenFlag = true;
			this->setOpacity(255 * 0.5);// = 0.5;
			readyDamage = false;
			this->invisibleTimer = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
			this->visibleTimer = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
			container = new Unit_mc(this, "unit18", typeUnit); //new Unit18_mc(); 
			container->setScale(0.84);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_18::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				if(!airFlag && !airShockFlag)
				{
					if(this->hiddenFlag)
					{
						if(this->invisibleCounter < this->invisibleTimer)
						{
							this->invisibleCounter++;
						}
					}
					else if(this->visibleCounter < this->visibleTimer)
					{
						this->visibleCounter++;
					}
					if(direction == "left" || direction == "right")
					{
						if(this->hiddenFlag)
						{
							if(container->contMcs->currentFrame > 9)
							{
								container->contMcs->gotoAndStop(1);
							}
							else if(container->contMcs->currentFrame > 1)
							{
								container->contMcs->gotoAndStop((container->contMcs->currentFrame - 1));
							}
						}
						else if(container->contMcs->currentFrame > 9)
						{
							container->contMcs->gotoAndStop(9);
						}
						else if(container->contMcs->currentFrame < 9)
						{
							container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
						}
						if(container->cont->currentFrame > 24)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
							if(container->cont->getPositionX() >= -1 && container->cont->getPositionX() <= 1
							   && container->cont->getPositionY() >= -1 && container->cont->getPositionY() <= 1)
							{
								container->cont->gotoAndStop(1);
							}
							if(container->cont->currentFrame < 33)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 37)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->cont->currentFrame < 44)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < container->cont->totalFrames)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
						}
						else
						{
							if(container->cont->currentFrame < 24)
							{
								container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else
							{
								container->cont->gotoAndStop(1);
							}
							if(container->cont->currentFrame < 9)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 13)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->cont->currentFrame < 20)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 24)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
						}
					}
					else if(direction == "up")
					{
						if(container->contMcs->currentFrame < 10)
						{
							container->contMcs->gotoAndStop(10);
						}
						if(container->cont->currentFrame < 25)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
							if(container->cont->getPositionX() >= -1 && container->cont->getPositionX() <= 1 && container->cont->getPositionY() >= -1 && container->cont->getPositionY() <= 1)
							{
								container->cont->gotoAndStop(25);
							}
							if(container->cont->currentFrame < 9)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 13)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->cont->currentFrame < 20)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 24)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
						}
						else
						{
							if(container->cont->currentFrame < container->cont->totalFrames)
							{
								container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else
							{
								container->cont->gotoAndStop(25);
							}
							if(container->cont->currentFrame < 33)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 37)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->cont->currentFrame < 44)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < container->cont->totalFrames)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
						}
					}
					else if(direction == "down")
					{
						if(this->hiddenFlag)
						{
							if(container->contMcs->currentFrame > 9)
							{
								container->contMcs->gotoAndStop(1);
							}
							else if(container->contMcs->currentFrame > 1)
							{
								container->contMcs->gotoAndStop((container->contMcs->currentFrame - 1));
							}
						}
						else if(container->contMcs->currentFrame > 9)
						{
							container->contMcs->gotoAndStop(9);
						}
						else if(container->contMcs->currentFrame < 9)
						{
							container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
						}
						if(container->cont->currentFrame < 25)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
							if(container->cont->getPositionX() >= -1 && container->cont->getPositionX() <= 1
							   && container->cont->getPositionY() >= -1 && container->cont->getPositionY() <= 1)
							{
								container->cont->gotoAndStop(25);
							}
							if(container->cont->currentFrame < 9)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 13)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->cont->currentFrame < 20)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 24)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
						}
						else
						{
							if(container->cont->currentFrame < container->cont->totalFrames)
							{
								container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else
							{
								container->cont->gotoAndStop(25);
							}
							if(container->cont->currentFrame < 33)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 37)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->cont->currentFrame < 44)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < container->cont->totalFrames)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
						}
					}
				}
				else if(direction == "left" || direction == "right")
				{
					if(this->hiddenFlag)
					{
						if(container->contMcs->currentFrame > 9)
						{
							container->contMcs->gotoAndStop(1);
						}
						else if(container->contMcs->currentFrame > 1)
						{
							container->contMcs->gotoAndStop((container->contMcs->currentFrame - 1));
						}
					}
					else if(container->contMcs->currentFrame > 9)
					{
						container->contMcs->gotoAndStop(9);
					}
					else if(container->contMcs->currentFrame < 9)
					{
						container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
					}
					if(container->cont->currentFrame > 24)
					{
						container->cont->gotoAndStop((container->cont->currentFrame + 1));
						if(container->cont->getPositionX() >= -1 && container->cont->getPositionX() <= 1
						   && container->cont->getPositionY() >= -1 && container->cont->getPositionY() <= 1)
						{
							container->cont->gotoAndStop(1);
						}
						if(container->cont->currentFrame < 33)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 37)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->cont->currentFrame < 44)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < container->cont->totalFrames)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
					}
					else
					{
						if(container->cont->currentFrame != 1 && container->cont->currentFrame < 24)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else if(container->cont->currentFrame != 1)
						{
							container->cont->gotoAndStop(1);
						}
						if(container->cont->currentFrame < 9)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 13)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->cont->currentFrame < 20)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 24)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
					}
				}
				else if(direction == "up")
				{
					if(container->contMcs->currentFrame < 10)
					{
						container->contMcs->gotoAndStop(10);
					}
					if(container->cont->currentFrame < 25)
					{
						container->cont->gotoAndStop((container->cont->currentFrame + 1));
						if(container->cont->getPositionX() >= -1 && container->cont->getPositionX() <= 1
						   && container->cont->getPositionY() >= -1 && container->cont->getPositionY() <= 1)
						{
							container->cont->gotoAndStop(25);
						}
						if(container->cont->currentFrame < 9)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 13)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->cont->currentFrame < 20)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 24)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
					}
					else
					{
						if(container->cont->currentFrame != 25 && container->cont->currentFrame < container->cont->totalFrames)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else if(container->cont->currentFrame != 25)
						{
							container->cont->gotoAndStop(25);
						}
						if(container->cont->currentFrame < 33)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 37)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->cont->currentFrame < 44)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < container->cont->totalFrames)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
					}
				}
				else if(direction == "down")
				{
					if(this->hiddenFlag)
					{
						if(container->contMcs->currentFrame > 9)
						{
							container->contMcs->gotoAndStop(1);
						}
						else if(container->contMcs->currentFrame > 1)
						{
							container->contMcs->gotoAndStop((container->contMcs->currentFrame - 1));
						}
					}
					else if(container->contMcs->currentFrame > 9)
					{
						container->contMcs->gotoAndStop(9);
					}
					else if(container->contMcs->currentFrame < 9)
					{
						container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
					}
					if(container->cont->currentFrame < 25)
					{
						container->cont->gotoAndStop((container->cont->currentFrame + 1));
						if(container->cont->getPositionX() >= -1 && container->cont->getPositionX() <= 1
						   && container->cont->getPositionY() >= -1 && container->cont->getPositionY() <= 1)
						{
							container->cont->gotoAndStop(25);
						}
						if(container->cont->currentFrame < 9)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 13)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->cont->currentFrame < 20)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 24)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
					}
					else
					{
						if(container->cont->currentFrame != 25 && container->cont->currentFrame < container->cont->totalFrames)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else if(container->cont->currentFrame != 25)
						{
							container->cont->gotoAndStop(25);
						}
						if(container->cont->currentFrame < 33)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 37)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->cont->currentFrame < 44)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < container->cont->totalFrames)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
					}
				}
			}
			if(this->invisibleCounter == this->invisibleTimer)
			{
				if(!container->signal->isVisible())
				{
					container->signal->setVisible(true);
				}
				else if(container->signal->currentFrame < container->signal->totalFrames)
				{
					container->signal->gotoAndStop((container->signal->currentFrame + 1));
				}
				else
				{
					container->signal->gotoAndStop(1);
					container->signal->setVisible(false);
					this->invisibleCounter = 0;
					this->hiddenFlag = false;
					this->setOpacity(255);// alpha = 1;
					readyDamage = true;
				}
			}
			else if(this->visibleCounter == this->visibleTimer)
			{
				if(!container->signal->isVisible())
				{
					container->signal->setVisible(true);
					readyDamage = false;
				}
				else if(container->signal->currentFrame < container->signal->totalFrames)
				{
					container->signal->gotoAndStop((container->signal->currentFrame + 1));
				}
				else
				{
					container->signal->gotoAndStop(1);
					container->signal->setVisible(false);
					this->visibleCounter = 0;
					this->hiddenFlag = true;
					this->setOpacity(255 * 0.5);
				}
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
