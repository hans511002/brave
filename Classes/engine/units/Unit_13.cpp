﻿
#include "Unit.h"

namespace engine
{
	namespace units
	{

		bool Unit_13::init()
		{
			typeUnit = 13;
			container = new Unit_mc(this, "Unit13_mc", typeUnit); //new Unit13_mc(); 
			container->setScale(0.85);
			container->init();
			Unit::init();
			//this->autorelease();
			return true;
		}// end function

		void Unit_13::animationHandler()
		{
			if (!container->stoneDeath->isVisible() && !icemanFlag)
			{
				if (direction != "up")
				{
					if (container->cont->currentFrame < 11)
					{
						if (container->cont->currentFrame < 10)
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
						container->cont->gotoAndStop(container->cont->currentFrame - 10);
					}
				}
				else if (container->cont->currentFrame > 10)
				{
					if (container->cont->currentFrame < container->cont->totalFrames)
					{
						container->cont->tryPlay();
						//container->cont->gotoAndStop((container->cont->currentFrame + 1));
					}
					else
					{
						container->cont->gotoAndStop(11);
					}
				}
				else
				{
					container->cont->gotoAndStop(container->cont->currentFrame + 10);
				}
				if (moveFlag && !airFlag && !airShockFlag || container->currentFrame != 1)
				{
					if (container->currentFrame < container->totalFrames)
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
			Unit::animationHandler();
			return;
		}// end function

	}
}
