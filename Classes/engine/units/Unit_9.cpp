
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
                    if (container->contMcs->currentFrame < 31)
                    {
                        if (container->contMcs->currentFrame < 30)
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
                        container->contMcs->gotoAndStop(container->contMcs->currentFrame - 30);
                    }
                }
                else if (container->contMcs->currentFrame > 30)
                {
                    if (container->contMcs->currentFrame < container->contMcs->totalFrames)
                    {
                        container->contMcs->gotoAndStop((container->contMcs->currentFrame + 1));
                    }
                    else
                    {
                        container->contMcs->gotoAndStop(31);
                    }
                }
                else
                {
                    container->contMcs->gotoAndStop(container->contMcs->currentFrame + 30);
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
