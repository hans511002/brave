
#include "Unit.h"

namespace engine
{
	namespace units
	{
		Unit_6::Unit_6()
		{
			return;
		}// end function

		bool Unit_6::init()
		{
			typeUnit = 6;
			container = new Unit_mc(this, "unit6", typeUnit); //new Unit6_mc(); 
			container->setScale(0.85);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_6::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				if(direction != "up")
				{
					if(container->contMcs->currentFrame < 21)
					{
						if(container->contMcs->currentFrame < 20)
						{
							container->contMcs->tryPlay();
				            //container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
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
						container->contMcs->tryPlay();
				        //container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
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
						if(container->cont->currentFrame > 17)
						{
							if(container->cont->currentFrame < container->cont->totalFrames)
							{
								container->cont->tryPlay();
				                //container->cont->gotoAndStop((container->cont->currentFrame + 1));
							}
							else
							{
								container->cont->gotoAndStop(1);
							}
						}
						else if(container->cont->currentFrame < 17)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else
						{
							container->cont->gotoAndStop(1);
						}
					}
				}
				else if(!airFlag && !airShockFlag || container->cont->currentFrame != 18)
				{
					if(container->cont->currentFrame < 18)
					{
						if(container->cont->currentFrame < 17)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else
						{
							container->cont->gotoAndStop(18);
						}
					}
					else if(container->cont->currentFrame < container->cont->totalFrames)
					{
						container->cont->tryPlay();
				        //container->cont->gotoAndStop((container->cont->currentFrame + 1));
					}
					else
					{
						container->cont->gotoAndStop(18);
					}
				}
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
