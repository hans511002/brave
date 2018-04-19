
#include "Unit_7.h"

namespace engine
{
	namespace units
	{  
        Unit_7::Unit_7()
        {
            return;
        }// end function

        bool Unit_7::init()
        {
            typeUnit = 7;
            container = new Unit_mc(this,"unit7", typeUnit); //new Unit7_mc(); 
            container->setScale(0.9);
            container->init();
            Unit::init();
            this->autorelease();  
            return true;
        }// end function

        void Unit_7::animationHandler() 
        {
            if (!dead && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container->cont->currentFrame < 31)
                    {
                        if (container->cont->currentFrame < 30)
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
                        container->cont->gotoAndStop(container->cont->currentFrame - 30);
                    }
                }
                else if (container->cont->currentFrame > 30)
                {
                    if (container->cont->currentFrame < container->cont->totalFrames)
                    {
                        container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else
                    {
                        container->cont->gotoAndStop(31);
                    }
                }
                else
                {
                    container->cont->gotoAndStop(container->cont->currentFrame + 30);
                }
                if (direction == "left" || direction == "right")
                {
                    if (!airFlag && !airShockFlag || container->currentFrame != 1)
                    {
                        if (container->currentFrame > 19)
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
                        else if (container->currentFrame < 19)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                        else
                        {
                            container->gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container->currentFrame != 20)
                {
                    if (container->currentFrame < 20)
                    {
                        if (container->currentFrame < 19)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                        else
                        {
                            container->gotoAndStop(20);
                        }
                    }
                    else if (container->currentFrame < container->totalFrames)
                    {
                        container->gotoAndStop((container->currentFrame + 1));
                    }
                    else
                    {
                        container->gotoAndStop(20);
                    }
                }
            }
            Unit_7::animationHandler();
            return;
        }// end function

    }
}
