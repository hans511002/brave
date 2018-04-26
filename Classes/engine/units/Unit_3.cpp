
#include "Unit.h"
//#include "Unit_3.h"

namespace engine
{
	namespace units
	{  
        Unit_3::Unit_3()
        {
            return;
        }// end function

        bool Unit_3::init()
        {
            typeUnit = 3;
            container = new Unit_mc(this,"unit3", typeUnit); //new Unit3_mc(); 
            container->setScale(0.9);
            container->init();
            Unit::init();
            this->autorelease();
            return true;
        }// end function

        void Unit_3::animationHandler() 
        {
            if (!container->stoneDeath->isVisible() && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container->cont->currentFrame < 11)
                    {
                        if (container->cont->currentFrame < 10)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(1);
                        }
                    }
                    else
                    {
                        container->cont->gotoAndStop(container->cont->currentFrame - 10);
                    }
                }
                else if (container->cont->currentFrame > 10)
                {
                    if (container->cont->currentFrame < container->cont->totalFrames)
                    {
                        container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else
                    {
                        container->cont->gotoAndStop(11);
                    }
                }
                else
                {
                    container->cont->gotoAndStop(container->cont->currentFrame + 10);
                }
                if (moveFlag && !airFlag && !airShockFlag || container->currentFrame != 1)
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
