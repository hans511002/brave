#include "Unit.h"
#include "engine/WorldInterface.h"

//#include "Unit_1.h"

namespace engine
{
	namespace units
	{ 
		bool Unit_1::init()
		{
			typeUnit = 1;
			float tempObject = cocos2d::rand_0_1();
			if(tempObject < 0.35)
			{
			    container = new Unit_mc(this, "Unit1_1_mc", typeUnit);
			}
			else if(tempObject < 0.7)
			{
				container = new Unit_mc(this, "Unit1_2_mc", typeUnit);
			}
			else
			{
				container = new Unit_mc(this, "Unit1_3_mc", typeUnit);
			}
			container->setPosition(0, 0);
			container->setScaleX(0.9f);
			container->setScaleY(0.9f);
			container->init();
			Unit::init(); 
			//this->setPosition(50, 50);
			// this->autorelease();
			return true;
		}// end function

		void Unit_1::animationHandler()
		{
			if(!dead && !icemanFlag)
			{
				//换肤
				if(direction != "up")
				{
					if(container->cont->currentFrame != 1)
					{
						container->cont->gotoAndStop(1);
					}
				}
				else if (container->cont->currentFrame != 2)
				{
					container->cont->gotoAndStop(2);
				}
				if(!airFlag && !airShockFlag)
				{ 
                    container->tryPlay();
                    //if(container->currentFrame < container->totalFrames)
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
