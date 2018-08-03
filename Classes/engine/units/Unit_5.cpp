
#include "Unit.h"

namespace engine
{
	namespace units
	{
		Unit_5::Unit_5()
		{
			return;
		}// end function

		bool Unit_5::init()
		{
			typeUnit = 5;
			container = new Unit_mc(this, "unit5", typeUnit); //new Unit5_mc(); 
			container->setScale(0.8);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_5::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				if(!airFlag && !airShockFlag)
				{
					if(direction == "left" || direction == "right")
					{
						if(container->contMcs->currentFrame != 1)
						{
							container->contMcs->gotoAndStop(1);
						}
						if(container->cont->currentFrame > 20)
						{
							if(container->cont->currentFrame >= 29 && container->cont->currentFrame < container->cont->totalFrames)
							{
							    container->cont->tryPlay();
				                //container->cont->gotoAndStop((container->cont->currentFrame + 1));
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 29)
							{
								container->cont->gotoAndStop(container->cont->currentFrame - 20);
							}
							else
							{
								container->cont->gotoAndStop(1);
							}
						}
						else
						{
							if(container->cont->currentFrame < 20)
							{
								container->cont->tryPlay();
				                //container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else
							{
								container->cont->gotoAndStop(1);
							}
							if(container->cont->currentFrame < 9)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(!moveFlag)
							{
								moveFlag = true;
							}
						}
					}
					else if(direction == "up")
					{
						if(container->contMcs->currentFrame != 2)
						{
							container->contMcs->gotoAndStop(2);
						}
						if(container->cont->currentFrame < 21)
						{
							if(container->cont->currentFrame >= 9 && container->cont->currentFrame < 20)
							{
								container->cont->tryPlay();
				                //container->cont->gotoAndStop((container->cont->currentFrame + 1));
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 9)
							{
								container->cont->gotoAndStop(container->cont->currentFrame + 20);
							}
							else
							{
								container->cont->gotoAndStop(21);
							}
						}
						else
						{
							if(container->cont->currentFrame < container->cont->totalFrames)
							{
								container->cont->tryPlay();
				                //container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else
							{
								container->cont->gotoAndStop(21);
							}
							if(container->cont->currentFrame < 29)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(!moveFlag)
							{
								moveFlag = true;
							}
						}
					}
					else if(direction == "down")
					{
						if(container->contMcs->currentFrame != 1)
						{
							container->contMcs->gotoAndStop(1);
						}
						if(container->cont->currentFrame < 21)
						{
							if(container->cont->currentFrame >= 9 && container->cont->currentFrame < 20)
							{
								container->cont->tryPlay();
				                //container->cont->gotoAndStop((container->cont->currentFrame + 1));
								if(!moveFlag)
								{
									moveFlag = true;
								}
							}
							else if(container->cont->currentFrame < 9)
							{
								container->cont->gotoAndStop(container->cont->currentFrame + 20);
							}
							else
							{
								container->cont->gotoAndStop(21);
							}
						}
						else
						{
							if(container->cont->currentFrame < container->cont->totalFrames)
							{
								container->cont->tryPlay();
				                //container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else
							{
								container->cont->gotoAndStop(21);
							}
							if(container->cont->currentFrame < 29)
							{
								if(moveFlag)
								{
									moveFlag = false;
								}
							}
							else if(!moveFlag)
							{
								moveFlag = true;
							}
						}
					}
				}
				else if(direction == "left" || direction == "right")
				{
					if(container->contMcs->currentFrame != 1)
					{
						container->contMcs->gotoAndStop(1);
					}
					if(container->cont->currentFrame > 20)
					{
						if(container->cont->currentFrame >= 29 && container->cont->currentFrame < container->cont->totalFrames)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 29)
						{
							container->cont->gotoAndStop(container->cont->currentFrame - 20);
						}
						else
						{
							container->cont->gotoAndStop(1);
						}
					}
					else
					{
						if(container->cont->currentFrame != 1 && container->cont->currentFrame < 20)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else if(container->cont->currentFrame != 1)
						{
							container->cont->gotoAndStop(1);
						}
						if(container->cont->currentFrame < 9)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(!moveFlag)
						{
							moveFlag = true;
						}
					}
				}
				else if(direction == "up")
				{
					if(container->contMcs->currentFrame != 2)
					{
						container->contMcs->gotoAndStop(2);
					}
					if(container->cont->currentFrame < 21)
					{
						if(container->cont->currentFrame >= 9 && container->cont->currentFrame < 20)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 9)
						{
							container->cont->gotoAndStop(container->cont->currentFrame + 20);
						}
						else
						{
							container->cont->gotoAndStop(21);
						}
					}
					else
					{
						if(container->cont->currentFrame != 21 && container->cont->currentFrame < container->cont->totalFrames)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else if(container->cont->currentFrame != 21)
						{
							container->cont->gotoAndStop(21);
						}
						if(container->cont->currentFrame < 29)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(!moveFlag)
						{
							moveFlag = true;
						}
					}
				}
				else if(direction == "down")
				{
					if(container->contMcs->currentFrame != 1)
					{
						container->contMcs->gotoAndStop(1);
					}
					if(container->cont->currentFrame < 21)
					{
						if(container->cont->currentFrame >= 9 && container->cont->currentFrame < 20)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
							if(!moveFlag)
							{
								moveFlag = true;
							}
						}
						else if(container->cont->currentFrame < 9)
						{
							container->cont->gotoAndStop(container->cont->currentFrame + 20);
						}
						else
						{
							container->cont->gotoAndStop(21);
						}
					}
					else
					{
						if(container->cont->currentFrame != 21 && container->cont->currentFrame < container->cont->totalFrames)
						{
						    container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else if(container->cont->currentFrame != 21)
						{
							container->cont->gotoAndStop(21);
						}
						if(container->cont->currentFrame < 29)
						{
							if(moveFlag)
							{
								moveFlag = false;
							}
						}
						else if(!moveFlag)
						{
							moveFlag = true;
						}
					}
				}
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
