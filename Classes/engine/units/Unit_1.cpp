#include "Unit.h"

//#include "Unit_1.h"

namespace engine
{
	namespace units
	{
		bool Unit_1::init()
		{
			typeUnit = 1;
			tempObject = cocos2d::rand_0_1();
			if (tempObject < 0.35)
			{
				container = new Unit_mc(this,"unit1_1", typeUnit);
			}
			else if (tempObject < 0.7)
			{
				container = new Unit_mc(this, "unit1_2", typeUnit);
			}
			else
			{
				container = new Unit_mc(this, "unit1_3", typeUnit);
			} 
			container->setPosition(0, 0);
			container->setScaleX( 0.9f);
			container->setScaleY(0.9f);
			container->init();
			Unit::init(); 
			//this->addChild(container);
			//this->setPosition(50, 50);
			this->autorelease();
			return true;
		}// end function

		void Unit_1::animationHandler()
		{
			if (!dead && !icemanFlag)
			{
                    //换肤
				//if (direction != "up")
				//{ 
				//	//if (container->cont->currentFrame == 2)
				//	//{
				//	//	container->cont->gotoAndStop(1);
				//	//}
				//}
				//else if (container->cont->currentFrame == 1)
				//{
				//	container.cont.gotoAndStop(2);
				//}
				if (!airFlag && !airShockFlag)
				{
					//if (container->currentFrame < container->totalFrames)
					//{
					//	container->gotoAndStop((container.currentFrame + 1));
					//}
					//else
					//{
					//	container->gotoAndStop(1);
					//}
				}
			}
			Unit::animationHandler();
			return;
		}// end function
	}
}
