
#include "Unit_9.h"

namespace engine
{
	namespace units
	{  
        Unit_9::Unit_9()
        {
            return;
        }// end function

        bool Unit_9::init() 
        {
            typeUnit = 9;
            container = new Unit_mc(this,"unit9", typeUnit); //new Unit9_mc(); 
            container->setScale(0.85);
            container->init();
            Unit::init();
            this->autorelease();  
            return true;
        }// end function

        void Unit::animationHandler()
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
                        if (container->currentFrame > 20)
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
                        else if (container->currentFrame < 20)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                        else
                        {
                            container->gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container->currentFrame != 21)
                {
                    if (container->currentFrame < 21)
                    {
                        if (container->currentFrame < 20)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                        else
                        {
                            container->gotoAndStop(21);
                        }
                    }
                    else if (container->currentFrame < container->totalFrames)
                    {
                        container->gotoAndStop((container->currentFrame + 1));
                    }
                    else
                    {
                        container->gotoAndStop(21);
                    }
                }
            }
            Unit::animationHandler();
            return;
        }// end function

    }
}
