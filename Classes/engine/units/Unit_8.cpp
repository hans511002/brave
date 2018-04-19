
#include "Unit_8.h"

namespace engine
{
	namespace units
	{  
        Unit_8::Unit_8()
        {
            return;
        }// end function

        bool Unit_8::init() 
        {
            typeUnit = 8;
            container = new Unit_mc(this,"unit8", typeUnit); //new Unit8_mc(); 
            container->setScale(0.87);
            container->init();
            Unit::init();
            this->autorelease();  
            return true;
        }// end function

        void Unit_8::animationHandler() 
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
            Unit_8::animationHandler();
            return;
        }// end function

    }
}
