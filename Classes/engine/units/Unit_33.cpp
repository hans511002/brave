
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		Unit_32::Unit_33():distanceX(0),distanceY(0),counter(-1),firstView(false)
		{
			return;
		}// end function
    
        bool Unit_33::init()
        {  
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
                        this->distanceX = (this_pt.x - this->x) / this->counter;
                        this->distanceY = (this_pt.y - this->y) / this->counter;
                    }
                    else if (this->counter > 0)
                    {
                        (this->counter - 1);
                        this->x = this->x + this->distanceX;
                        this->y = this->y + this->distanceY;
                        if (this->alpha < 1)
                        {
                            this->alpha = this->alpha + 0.3;
                        }
                    }
                    else
                    {
                        this->firstView = true;
                        this->x = this_pt.x;
                        this->y = this_pt.y;
                        this->alpha = 1;
                        readyDamage = true;
                        moveFlag = true;
                        this->moveHandler();
                    }
                }
                else if (!icemanFlag)
                {
                    if (container->contMcs->currentFrame < container->contMcs->totalFrames)
                    {
                        container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                    }
                    else
                    {
                        container->contMcs->gotoAndStop(1);
                    }
                }
            }
            Unit::animationHandler();
            return;
        }// end function

    }
}
