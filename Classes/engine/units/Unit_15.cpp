
#include "Unit.h"
 
namespace engine
{
	namespace units
	{ 

		bool Unit_15::init()
		{
			typeUnit = 15;
			moveFlag = false;
			container = new Unit_mc(this, "Unit15_mc", typeUnit); //new Unit15_mc(); 
			container->setScale(0.85);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_15::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				if(!airFlag && !airShockFlag)
				{
					if(direction == "left" || direction == "right")
					{
						if(container->cont->currentFrame != 1)
						{
							container->cont->gotoAndStop(1);
						}
						if(container->currentFrame > 18)
						{
							container->gotoAndStop(container->currentFrame - 18);
						}
						else if(container->currentFrame < 18)
						{
							container->gotoAndStop((container->currentFrame + 1));
						}
						else
						{
							container->gotoAndStop(1);
						}
						if(container->currentFrame < 9)
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
					else if(direction == "up")
					{
						if(container->cont->currentFrame != 2)
						{
							container->cont->gotoAndStop(2);
						}
						if(container->currentFrame < 19)
						{
							container->gotoAndStop(container->currentFrame + 18);
						}
						else if(container->currentFrame < container->totalFrames)
						{
							container->gotoAndStop((container->currentFrame + 1));
						}
						else
						{
							container->gotoAndStop(19);
						}
						if(container->currentFrame < 27)
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
					else if(direction == "down")
					{
						if(container->cont->currentFrame != 1)
						{
							container->cont->gotoAndStop(1);
						}
						if(container->currentFrame < 19)
						{
							container->gotoAndStop(container->currentFrame + 18);
						}
						else if(container->currentFrame < container->totalFrames)
						{
							container->gotoAndStop((container->currentFrame + 1));
						}
						else
						{
							container->gotoAndStop(19);
						}
						if(container->currentFrame < 27)
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
				else if(direction == "left" || direction == "right")
				{
					if(container->cont->currentFrame != 1)
					{
						container->cont->gotoAndStop(1);
					}
					if(container->currentFrame > 18)
					{
						container->gotoAndStop(container->currentFrame - 18);
					}
					else if(container->currentFrame != 1 && container->currentFrame < 18)
					{
						container->gotoAndStop((container->currentFrame + 1));
					}
					else if(container->currentFrame != 1)
					{
						container->gotoAndStop(1);
					}
					if(container->currentFrame < 9)
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
				else if(direction == "up")
				{
					if(container->cont->currentFrame != 2)
					{
						container->cont->gotoAndStop(2);
					}
					if(container->currentFrame < 19)
					{
						container->gotoAndStop(container->currentFrame + 18);
					}
					else if(container->currentFrame != 19 && container->currentFrame < container->totalFrames)
					{
						container->gotoAndStop((container->currentFrame + 1));
					}
					else if(container->currentFrame != 19)
					{
						container->gotoAndStop(19);
					}
					if(container->currentFrame < 27)
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
				else if(direction == "down")
				{
					if(container->cont->currentFrame != 1)
					{
						container->cont->gotoAndStop(1);
					}
					if(container->currentFrame < 19)
					{
						container->gotoAndStop(container->currentFrame + 18);
					}
					else if(container->currentFrame != 19 && container->currentFrame < container->totalFrames)
					{
						container->gotoAndStop((container->currentFrame + 1));
					}
					else if(container->currentFrame != 19)
					{
						container->gotoAndStop(19);
					}
					if(container->currentFrame < 27)
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
			Unit::animationHandler();
			return;
		}// end function

	}
}
