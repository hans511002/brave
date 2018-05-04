
#include "Unit.h"

namespace engine
{
	namespace units
	{
		Unit_4::Unit_4()
		{
			return;
		}// end function

		bool Unit_4::init()
		{
			typeUnit = 4;
			container = new Unit_mc(this, "unit4", typeUnit); //new Unit4_mc(); 
			container->setScale(0.9);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_4::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				if(direction != "up")
				{
					if(container->contMcs->currentFrame == 2)
					{
						container->contMcs->gotoAndStop(1);
					}
				}
				else if(container->contMcs->currentFrame == 1)
				{
					container->contMcs->gotoAndStop(2);
				}
				if(!airFlag && !airShockFlag)
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
		}// end function

	}
}
