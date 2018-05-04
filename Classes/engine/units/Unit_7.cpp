﻿
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
                        if (container->cont->currentFrame > 19)
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
                        else if (container->cont->currentFrame < 19)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(1);
                        }
                    }
                }
                else if (!airFlag && !airShockFlag || container->cont->currentFrame != 20)
                {
                    if (container->cont->currentFrame < 20)
                    {
                        if (container->cont->currentFrame < 19)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(20);
                        }
                    }
                    else if (container->cont->currentFrame < container->cont->totalFrames)
                    {
                        container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else
                    {
                        container->cont->gotoAndStop(20);
                    }
                }
            }
            Unit_7::animationHandler();
            return;
        }// end function

    }
}
