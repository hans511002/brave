
#include "Unit.h"
#include "MainClass.h"
#include "engine/World.h"

namespace engine
{
	namespace units
	{
		Unit_31::Unit_31():distanceX(0),distanceY(0),counter(-1),firstView(false)
		{
			return;
		}// end function
    
        bool Unit_31::init()
        { 
            typeUnit = 31; 
            container = new Unit_mc(this, "unit31", typeUnit);  
			container->setScale(0.81);
			container->init();
			Unit::init();
			this->autorelease();  
            return true;
        }// end function

        void Unit_31::moveHandler()
        {
            if (readyDamage)
            {
                Unit::moveHandler();
            }
            return;
        }// end function

        void Unit_31::animationHandler()
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
                        this->counter--;
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
                    if (direction != "up")
                    {
                        if (container->contMcs->currentFrame == 2)
                        {
                            container->contMcs->gotoAndStop(1);
                        }
                    }
                    else if (container->contMcs->currentFrame == 1)
                    {
                        container->contMcs->gotoAndStop(2);
                    }
                    if (!airFlag && !airShockFlag || container->cont->currentFrame != 1)
                    {
                        if (container->cont->currentFrame < container->cont->totalFrames)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(1);
                        }
                    }
                }
            }
            Unit::animationHandler();
            return;
        }// end function

    }
}
