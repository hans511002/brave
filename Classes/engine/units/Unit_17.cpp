
#include "Unit.h"

namespace engine
{
	namespace units
	{  
        Unit_17::Unit_17()
        {
            return;
        }// end function

        bool Unit_17::init() 
        {
            typeUnit = 17;
            container = new Unit_mc(this,"unit17", typeUnit); //new Unit17_mc(); 
            container->setScale(0.85);
            container->init();
            Unit::init();
            this->autorelease();  
            return true;  
             
        }// end function

        void Unit_17::animationHandler() : void
        {
            if (!dead && !icemanFlag)
            {
                if (direction != "up")
                {
                    if (container->contMcs->currentFrame < 36)
                    {
                        if (container->contMcs->currentFrame < 35)
                        {
                            container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                        }
                        else
                        {
                            container->contMcs->gotoAndStop(1);
                        }
                    }
                    else
                    {
                        container->contMcs->gotoAndStop(container->contMcs->currentFrame - 35);
                    }
                }
                else if (container->contMcs->currentFrame > 35)
                {
                    if (container->contMcs->currentFrame < container->contMcs->totalFrames)
                    {
                        container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                    }
                    else
                    {
                        container->contMcs->gotoAndStop(36);
                    }
                }
                else
                {
                    container->contMcs->gotoAndStop(container->contMcs->currentFrame + 35);
                }
                if (direction == "left" || direction == "right")
                {
                    if (!airFlag && !airShockFlag || container->cont->currentFrame != 1)
                    {
                        if (container->cont->currentFrame > 20)
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
                        else if (container->cont->currentFrame < 20)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container->cont->currentFrame != 21)
                {
                    if (container->cont->currentFrame < 21)
                    {
                        if (container->cont->currentFrame < 20)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(21);
                        }
                    }
                    else if (container->cont->currentFrame < container->cont->totalFrames)
                    {
                        container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else
                    {
                        container->cont->gotoAndStop(21);
                    }
                }
            }
            Unit::animationHandler();
            return;
        }// end function

    }
}
