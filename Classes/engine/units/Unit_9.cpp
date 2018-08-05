
#include "Unit.h"

namespace engine
{
	namespace units
	{ 

		bool Unit_9::init()
		{
			typeUnit = 9;
			container = new Unit_mc(this, "Unit9_mc", typeUnit); //new Unit9_mc(); 
			container->setScale(0.85f);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_9::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				if(direction != "up")
				{
					if(container->cont->currentFrame < 31)
					{
						if(container->cont->currentFrame < 30)
						{
							container->cont->tryPlay();
				            //container->cont->gotoAndStop((container->cont->currentFrame + 1));
						}
						else
						{
							container->cont->gotoAndStop(1);
						}
					}
					else
					{
						container->cont->gotoAndStop(container->cont->currentFrame - 30);
					}
				}
				else if(container->cont->currentFrame > 30)
				{
					if(container->cont->currentFrame < container->cont->totalFrames)
					{
						container->cont->tryPlay();
				        //container->cont->gotoAndStop((container->cont->currentFrame + 1));
					}
					else
					{
						container->cont->gotoAndStop(31);
					}
				}
				else
				{
					container->cont->gotoAndStop(container->cont->currentFrame + 30);
				}
				if(direction == "left" || direction == "right")
				{
					if(!airFlag && !airShockFlag || container->currentFrame != 1)
					{
						if(container->currentFrame > 20)
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
						else if(container->currentFrame < 20)
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
				else if(!airFlag && !airShockFlag || container->currentFrame != 21)
				{
					if(container->currentFrame < 21)
					{
						if(container->currentFrame < 20)
						{
							container->tryPlay();
				            //container->gotoAndStop((container->currentFrame + 1));
						}
						else
						{
							container->gotoAndStop(21);
						}
					}
					else if(container->currentFrame < container->totalFrames)
					{
						container->tryPlay();
				        //container->gotoAndStop((container->currentFrame + 1));
					}
					else
					{
						container->gotoAndStop(21);
					}
				}
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
