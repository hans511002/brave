
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		bool Unit_33::init()
		{
			distanceX = (0), distanceY = (0), counter = (-1), firstView = (false);
			typeUnit = 33;
			container = new Unit_mc(this, "unit33", typeUnit);
			container->setScale(0.9);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_33::moveHandler()
		{
			if (readyDamage)
			{
				Unit::moveHandler();
			}
			return;
		}// end function

		void Unit_33::animationHandler()
		{
			if (!dead)
			{
				if (!readyDamage && !this->firstView)
				{
					if (this->counter == -1)
					{
						this->counter = 5;
						this->distanceX = (this_pt.x - this->getPositionX()) / this->counter;
						this->distanceY = (this_pt.y - this->getPositionY()) / this->counter;
					}
					else if (this->counter > 0)
					{
						this->counter--;
						this->setPosition(this->getPositionX() + this->distanceX, this->getPositionY() + this->distanceY);
						if (this->getAlpha() < 1)
						{
							this->setAlpha(this->getAlpha() + 0.3);
						}
					}
					else
					{
						this->firstView = true;
						this->setPosition(this->this_pt);
						this->setAlpha(1);
						readyDamage = true;
						moveFlag = true;
						this->moveHandler();
					}
				}
				else if (!icemanFlag)
				{
					if (container->cont->currentFrame < container->cont->totalFrames)
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
			Unit::animationHandler();
			return;
		}// end function

	}
}
