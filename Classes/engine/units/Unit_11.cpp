
#include "Unit.h"

namespace engine
{
	namespace units
	{
		Unit_11::Unit_11()
		{
			return;
		}// end function
 
		bool Unit_11::init()
		{
			typeUnit = 11;
			container = new Unit_mc(this, "unit11", typeUnit); //new Unit11_mc(); 
			container->setScale(0.82);
			container->init();
			Unit::init();
			//this->autorelease();
			return true;
		}// end function

		void Unit_11::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				if(direction != "up")
				{
					if(container->contMcs->currentFrame < 21)
					{
						if(container->contMcs->currentFrame < 20)
						{
							container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
						}
						else
						{
							container->contMcs->gotoAndStop(1);
						}
					}
					else
					{
						container->contMcs->gotoAndStop(container->contMcs->currentFrame - 20);
					}
				}
				else if(container->contMcs->currentFrame > 20)
				{
					if(container->contMcs->currentFrame < container->contMcs->totalFrames)
					{
						container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
					}
					else
					{
						container->contMcs->gotoAndStop(21);
					}
				}
				else
				{
					container->contMcs->gotoAndStop(container->contMcs->currentFrame + 20);
				}
				if(direction == "left" || direction == "right")
				{
					if(!airFlag && !airShockFlag || container->cont->currentFrame != 1)
					{
						if(container->cont->currentFrame > 20)
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
						else if(container->cont->currentFrame < 20)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else
						{
							container->cont->gotoAndStop(1);
						}
					}
				}
				else if(!airFlag && !airShockFlag || container->cont->currentFrame != 21)
				{
					if(container->cont->currentFrame < 21)
					{
						if(container->cont->currentFrame < 20)
						{
							container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else
						{
							container->cont->gotoAndStop(21);
						}
					}
					else if(container->cont->currentFrame < container->cont->totalFrames)
					{
						container->cont->gotoAndStop((container->cont->currentFrame + 1));
					}
					else
					{
						container->cont->gotoAndStop(21);
					}
				}
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
