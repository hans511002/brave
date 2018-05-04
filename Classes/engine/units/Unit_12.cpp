
#include "Unit.h"

namespace engine
{
	namespace units
	{
		Unit_12::Unit_12()
		{
			return;
		}// end function

		bool Unit_12::init()
		{
			typeUnit = 12;
			container = new Unit_mc(this, "unit12", typeUnit); //new Unit12_mc(); 
			container->setScale(0.82);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_12::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				if(direction != "up")
				{
					if(container->contMcs->currentFrame != 1)
					{
						container->contMcs->gotoAndStop(1);
					}
				}
				else if(container->contMcs->currentFrame != 2)
				{
					container->contMcs->gotoAndStop(2);
				}
				if(direction == "left" || direction == "right")
				{
					if(!airFlag && !airShockFlag || container->cont->currentFrame != 1)
					{
						if(container->cont->currentFrame > 26)
						{
							if(container->cont->currentFrame < container->cont->totalFrames)
							{
								container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else
							{
								container->cont->gotoAndStop(1);
							}
						}
						else if(container->cont->currentFrame < 26)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else
						{
							container->cont->gotoAndStop(1);
						}
					}
				}
				else if(!airFlag && !airShockFlag || container->cont->currentFrame != 27)
				{
					if(container->cont->currentFrame < 27)
					{
						if(container->cont->currentFrame < 26)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else
						{
							container->cont->gotoAndStop(27);
						}
					}
					else if(container->cont->currentFrame < container->cont->totalFrames)
					{
						container->cont->gotoAndStop((container->cont->currentFrame + 1));
					}
					else
					{
						container->cont->gotoAndStop(27);
					}
				}
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
