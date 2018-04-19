
#include "Unit_6.h"

namespace engine
{
	namespace units
	{  
        Unit_6::Unit_6()
        {
            return;
        }// end function

        bool init() 
        {
            typeUnit = 6;
            container = new Unit_mc(this,"unit6", typeUnit); //new Unit6_mc(); 
            container->setScale(0.85);
            container->init();
            Unit::init();
            this->autorelease();  
            return true;
        }// end function

        void Unit_6::animationHandler() 
        {
            if (!dead && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container->cont->currentFrame < 21)
                    {
                        if (container->cont->currentFrame < 20)
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
                        container->cont->gotoAndStop(container->cont->currentFrame - 20);
                    }
                }
                else if (container->cont->currentFrame > 20)
                {
                    if (container->cont->currentFrame < container->cont->totalFrames)
                    {
                        container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else
                    {
                        container->cont->gotoAndStop(21);
                    }
                }
                else
                {
                    container->cont->gotoAndStop(container->cont->currentFrame + 20);
                }
                if (direction == "left" || direction == "right")
                {
                    if (!airFlag && !airShockFlag || container->currentFrame != 1)
                    {
                        if (container->currentFrame > 17)
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
                        else if (container->currentFrame < 17)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                        else
                        {
                            container->gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container->currentFrame != 18)
                {
                    if (container->currentFrame < 18)
                    {
                        if (container->currentFrame < 17)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                        else
                        {
                            container->gotoAndStop(18);
                        }
                    }
                    else if (container->currentFrame < container->totalFrames)
                    {
                        container->gotoAndStop((container->currentFrame + 1));
                    }
                    else
                    {
                        container->gotoAndStop(18);
                    }
                }
            }
            Unit_6::animationHandler();
            return;
        }// end function

    }
}
