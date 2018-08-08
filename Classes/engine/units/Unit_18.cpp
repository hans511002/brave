
#include "Unit.h"
#include "MainClass.h"

namespace engine
{ 
	namespace units
	{ 

		bool Unit_18::init()
		{
			typeUnit = 18;
			this->hiddenFlag = true;
			this->setAlpha( 0.5);// = 0.5;
			readyDamage = false;
			this->invisibleTimer = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][30];
			this->visibleTimer = Main::mainClass->readXMLClass.listOfEnemiesXML[(typeUnit - 1)][31];
			container = new Unit_mc(this, "Unit18_mc", typeUnit); //new Unit18_mc(); 
			container->setScale(0.84f);
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
							if(container->cont->currentFrame > 9)
							{
								container->cont->gotoAndStop(1);
							}
							else if(container->cont->currentFrame > 1)
							{
								container->cont->gotoAndStop((container->cont->currentFrame - 1));
							}
						}
						else if(container->cont->currentFrame > 9)
						{
							container->cont->gotoAndStop(9);
						}
						else if(container->cont->currentFrame < 9)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						if(container->currentFrame > 24)
						{
							container->tryPlay();
				            //container->gotoAndStop((container->currentFrame + 1));
							if(container->getPositionX() >= -1 && container->getPositionX() <= 1
							   && container->getPositionY() >= -1 && container->getPositionY() <= 1)
							{
								container->gotoAndStop(1);
							}
							if(container->currentFrame < 33)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < 37)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->currentFrame < 44)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < container->totalFrames)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
						}
						else
						{
							if(container->currentFrame < 24)
							{
								container->tryPlay();
				                //container->gotoAndStop((container->currentFrame + 1));
							}
							else
							{
								container->gotoAndStop(1);
							}
							if(container->currentFrame < 9)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < 13)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->currentFrame < 20)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < 24)
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
						if(container->cont->currentFrame < 10)
						{
							container->cont->gotoAndStop(10);
						}
						if(container->currentFrame < 25)
						{
							container->tryPlay();
				            //container->gotoAndStop((container->currentFrame + 1));
							if(container->getPositionX() >= -1 && container->getPositionX() <= 1 && container->getPositionY() >= -1 && container->getPositionY() <= 1)
							{
								container->gotoAndStop(25);
							}
							if(container->currentFrame < 9)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < 13)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->currentFrame < 20)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < 24)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
						}
						else
						{
							if(container->currentFrame < container->totalFrames)
							{
								container->tryPlay();
				            //container->gotoAndStop((container->currentFrame + 1));
							}
							else
							{
								container->gotoAndStop(25);
							}
							if(container->currentFrame < 33)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < 37)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->currentFrame < 44)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < container->totalFrames)
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
							if(container->cont->currentFrame > 9)
							{
								container->cont->gotoAndStop(1);
							}
							else if(container->cont->currentFrame > 1)
							{
								container->cont->gotoAndStop((container->cont->currentFrame - 1));
							}
						}
						else if(container->cont->currentFrame > 9)
						{
							container->cont->gotoAndStop(9);
						}
						else if(container->cont->currentFrame < 9)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						if(container->currentFrame < 25)
						{
							container->tryPlay();
				            //container->gotoAndStop((container->currentFrame + 1));
							if(container->getPositionX() >= -1 && container->getPositionX() <= 1
							   && container->getPositionY() >= -1 && container->getPositionY() <= 1)
							{
								container->gotoAndStop(25);
							}
							if(container->currentFrame < 9)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < 13)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->currentFrame < 20)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < 24)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
						}
						else
						{
							if(container->currentFrame < container->totalFrames)
							{
								container->tryPlay();
				                //container->gotoAndStop((container->currentFrame + 1));
							}
							else
							{
								container->gotoAndStop(25);
							}
							if(container->currentFrame < 33)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < 37)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(container->currentFrame < 44)
							{
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->currentFrame < container->totalFrames)
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
						if(container->cont->currentFrame > 9)
						{
							container->cont->gotoAndStop(1);
						}
						else if(container->cont->currentFrame > 1)
						{
							container->cont->gotoAndStop((container->cont->currentFrame - 1));
						}
					}
					else if(container->cont->currentFrame > 9)
					{
						container->cont->gotoAndStop(9);
					}
					else if(container->cont->currentFrame < 9)
					{
						container->cont->tryPlay();
				        //container->cont->gotoAndStop((container->cont->currentFrame + 1));
					}
					if(container->currentFrame > 24)
					{
						container->tryPlay();
				        //container->gotoAndStop((container->currentFrame + 1));
						if(container->getPositionX() >= -1 && container->getPositionX() <= 1
						   && container->getPositionY() >= -1 && container->getPositionY() <= 1)
						{
							container->gotoAndStop(1);
						}
						if(container->currentFrame < 33)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < 37)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->currentFrame < 44)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < container->totalFrames)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
					}
					else
					{
						if(container->currentFrame != 1 && container->currentFrame < 24)
						{
							container->tryPlay();
				            //container->gotoAndStop((container->currentFrame + 1));
						}
						else if(container->currentFrame != 1)
						{
							container->gotoAndStop(1);
						}
						if(container->currentFrame < 9)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < 13)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->currentFrame < 20)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < 24)
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
					if(container->cont->currentFrame < 10)
					{
						container->cont->gotoAndStop(10);
					}
					if(container->currentFrame < 25)
					{
						container->tryPlay();
				        //container->gotoAndStop((container->currentFrame + 1));
						if(container->getPositionX() >= -1 && container->getPositionX() <= 1
						   && container->getPositionY() >= -1 && container->getPositionY() <= 1)
						{
							container->gotoAndStop(25);
						}
						if(container->currentFrame < 9)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < 13)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->currentFrame < 20)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < 24)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
					}
					else
					{
						if(container->currentFrame != 25 && container->currentFrame < container->totalFrames)
						{
							container->tryPlay();
				            //container->gotoAndStop((container->currentFrame + 1));
						}
						else if(container->currentFrame != 25)
						{
							container->gotoAndStop(25);
						}
						if(container->currentFrame < 33)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < 37)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->currentFrame < 44)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < container->totalFrames)
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
						if(container->cont->currentFrame > 9)
						{
							container->cont->gotoAndStop(1);
						}
						else if(container->cont->currentFrame > 1)
						{
							container->cont->gotoAndStop((container->cont->currentFrame - 1));
						}
					}
					else if(container->cont->currentFrame > 9)
					{
						container->cont->gotoAndStop(9);
					}
					else if(container->cont->currentFrame < 9)
					{
						container->cont->tryPlay();
				        //container->cont->gotoAndStop((container->cont->currentFrame + 1));
					}
					if(container->currentFrame < 25)
					{
						container->tryPlay();
				        //container->gotoAndStop((container->currentFrame + 1));
						if(container->getPositionX() >= -1 && container->getPositionX() <= 1
						   && container->getPositionY() >= -1 && container->getPositionY() <= 1)
						{
							container->gotoAndStop(25);
						}
						if(container->currentFrame < 9)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < 13)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->currentFrame < 20)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < 24)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
					}
					else
					{
						if(container->currentFrame != 25 && container->currentFrame < container->totalFrames)
						{
							container->tryPlay();
				            //container->gotoAndStop((container->currentFrame + 1));
						}
						else if(container->currentFrame != 25)
						{
							container->gotoAndStop(25);
						}
						if(container->currentFrame < 33)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < 37)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(container->currentFrame < 44)
						{
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->currentFrame < container->totalFrames)
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
					container->signal->tryPlay();
				    //container->signal->gotoAndStop((container->signal->currentFrame + 1));
				}
				else
				{
					container->signal->gotoAndStop(1);
					container->signal->setVisible(false);
					this->invisibleCounter = 0;
					this->hiddenFlag = false;
					this->setAlpha(1);// alpha = 1;
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
					container->signal->tryPlay();
				    //container->signal->gotoAndStop((container->signal->currentFrame + 1));
				}
				else
				{
					container->signal->gotoAndStop(1);
					container->signal->setVisible(false);
					this->visibleCounter = 0;
					this->hiddenFlag = true;
					this->setAlpha( 0.5);
				}
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
