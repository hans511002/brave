
#include "Unit.h"

namespace engine
{
	namespace units
	{
		Unit_13::Unit_13()
		{
			return;
		}// end function
 
		bool Unit_13::init()
		{
			typeUnit = 13;
			container = new Unit_mc(this, "unit13", typeUnit); //new Unit13_mc(); 
			container->setScale(0.85);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_13::animationHandler()
		{
			if(!container->stoneDeath->isVisible() && !icemanFlag)
			{
				if(direction != "up")
				{
					if(container->contMcs->currentFrame < 11)
					{
						if(container->contMcs->currentFrame < 10)
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
						container->contMcs->gotoAndStop(container->contMcs->currentFrame - 10);
					}
				}
				else if(container->contMcs->currentFrame > 10)
				{
					if(container->contMcs->currentFrame < container->contMcs->totalFrames)
					{
						container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
					}
					else
					{
						container->contMcs->gotoAndStop(11);
					}
				}
				else
				{
					container->contMcs->gotoAndStop(container->contMcs->currentFrame + 10);
				}
				if(moveFlag && !airFlag && !airShockFlag || container->cont->currentFrame != 1)
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
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
