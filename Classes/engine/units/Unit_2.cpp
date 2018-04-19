
#include "Unit_2.h"

namespace engine
{
	namespace units
	{ 
        Unit_2::Unit_2()
        {
            return;
        }// end function

        bool Unit_2::init()
        {
            typeUnit = 2;
            container = new Unit_mc(this,"unit2", typeUnit); //new Unit2_mc(); 
            container->setScale(0.9);
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
                    if (container->currentFrame < container->totalFrames)
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
            return;
        }// end function

    }
}
