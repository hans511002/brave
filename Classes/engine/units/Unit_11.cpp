﻿
#include "Unit.h"

namespace engine
{
	namespace units
	{ 
 
		bool Unit_11::init()
		{
			typeUnit = 11;
			container = new Unit_mc(this, "Unit11_mc", typeUnit); //new Unit11_mc(); 
			container->setScale(0.82f);
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
					if(container->cont->currentFrame < 21)
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
					}
					else
					{
						container->cont->gotoAndStop(container->cont->currentFrame - 20);
					}
				}
				else if(container->cont->currentFrame > 20)
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
				}
				else
				{
					container->cont->gotoAndStop(container->cont->currentFrame + 20);
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
