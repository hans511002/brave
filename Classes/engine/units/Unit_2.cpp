
#include "Unit.h"
//#include "Unit_2.h" 
#include "engine/World.h" 
#include "engine/bullets/Bullet.h" 

namespace engine
{
	namespace units
	{

		bool Unit_2::init()
		{
			typeUnit = 2;
			container = new Unit_mc(this, "Unit2_mc", typeUnit); //new Unit2_mc(); 
			container->setScale(0.9f);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_2::animationHandler()
		{
			if (!dead && !icemanFlag)
			{
				if (direction != "up")
				{
					if (container->cont->currentFrame != 1)
					{
						container->cont->gotoAndStop(1);
					}
				}
				else if (container->cont->currentFrame != 2)
				{
					container->cont->gotoAndStop(2);
				}
				if (!airFlag && !airShockFlag)
				{ 
                    container->->tryPlay();
				    //
                    //if (container->currentFrame < container->totalFrames)
					//{
					//	container->gotoAndStop((container->currentFrame + 1));
					//}
					//else
					//{
					//	container->gotoAndStop(1);
					//}
                }
                else
                {
                    container->stop();
                }
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
