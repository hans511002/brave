
#include "Unit.h"
#include "engine/World.h" 
#include "engine/bullets/Bullet.h" 

namespace engine
{
	namespace units
	{

		bool Unit_4::init()
		{
			typeUnit = 4;
			container = new Unit_mc(this, "Unit4_mc", typeUnit); //new Unit4_mc(); 
			container->setScale(0.9f);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_4::animationHandler()
		{
			if (!dead && !icemanFlag)
			{
				if (direction != "up")
				{
					if (container->cont->currentFrame == 2)
					{
						container->cont->gotoAndStop(1);
					}
				}
				else if (container->cont->currentFrame == 1)
				{
					container->cont->gotoAndStop(2);
				}
				if (!airFlag && !airShockFlag)
				{
					if (container-> currentFrame < container->totalFrames)
					{
						container->gotoAndStop((container->currentFrame + 1));
					}
					else
					{
						container->gotoAndStop(1);
					}
				}
			}
			Unit::animationHandler();
		}// end function

	}
}
