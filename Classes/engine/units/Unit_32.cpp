
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		bool Unit_32::init()
		{
			distanceX = (0), distanceY = (0), counter = (-1), firstView = (false);
			typeUnit = 32;
			container = new Unit_mc(this, "unit32", typeUnit);
			container->setScale(0.81f);
			container->init();
			Unit::init();
			this->autorelease();
			return true;
		}// end function

		void Unit_32::moveHandler()
		{
			if (readyDamage)
			{
				Unit::moveHandler();
			}
			return;
		}// end function

		void Unit_32::animationHandler()
		{
			if (!dead)
			{
				if (!readyDamage && !this->firstView)
				{
					if (this->counter == -1)
					{
						this->counter = 3;
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
						this->setPosition(this_pt);
						this->setAlpha(1);
						readyDamage = true;
						moveFlag = true;
						this->moveHandler();
					}
				}
				else if (!icemanFlag)
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
					if (!airFlag && !airShockFlag || container->currentFrame != 1)
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
			}
			Unit::animationHandler();
			return;
		}// end function

	}
}
