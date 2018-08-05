
#include "Unit.h"

namespace engine
{
	namespace units
	{ 

		bool Unit_12::init()
		{ 
			typeUnit = 12;
			container = new Unit_mc(this, "Unit12_mc", typeUnit); //new Unit12_mc(); 
			container->setScale(0.82);
			container->init();
			Unit::init();
			//this->autorelease();
			return true;
		}// end function

		void Unit_12::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				if(direction != "up")
				{
					if(container->cont->currentFrame != 1)
					{
						container->cont->gotoAndStop(1);
					}
				}
				else if(container->cont->currentFrame != 2)
				{
					container->cont->gotoAndStop(2);
				}
				if(direction == "left" || direction == "right")
				{
					if(!airFlag && !airShockFlag || container->currentFrame != 1)
					{
						if(container->currentFrame > 26)
						{
							if(container->currentFrame < container->totalFrames)
							{
								container->tryPlay();
					            //container->gotoAndStop((container->currentFrame + 1));
							}
							else
							{
								container->gotoAndStop(1);
							}
						}
						else if(container->currentFrame < 26)
						{
							container->tryPlay();
					    //container->gotoAndStop((container->currentFrame + 1));
						}
						else
						{
							container->gotoAndStop(1);
						}
					}
				}
				else if(!airFlag && !airShockFlag || container->currentFrame != 27)
				{
					if(container->currentFrame < 27)
					{
						if(container->currentFrame < 26)
						{
							container->tryPlay();
					    //container->gotoAndStop((container->currentFrame + 1));
						}
						else
						{
							container->gotoAndStop(27);
						}
					}
					else if(container->currentFrame < container->totalFrames)
					{
						container->tryPlay();
					    //container->gotoAndStop((container->currentFrame + 1));
					}
					else
					{
						container->gotoAndStop(27);
					}
				}
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
