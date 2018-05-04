
#include "Unit.h"

namespace engine
{
	namespace units
	{  
        Unit_10::Unit_10()
        {
            return;
        }// end function

        bool Unit_10::init(event:Event) : void
        {
            typeUnit = 10;
            moveFlag = false;
            container = new Unit_mc(this,"unit10", typeUnit); //new Unit10_mc(); 
            container->setScale(0.87);
            container->init();
            Unit::init();
            this->autorelease();  
            return true;
              
        }// end function

        void Unit_10::animationHandler()
        {
            if (!dead && !icemanFlag)
            {
                if (!airFlag && !airShockFlag)
                {
                    if (direction == "left" || direction == "right")
                    {
                        if (container->contMcs->currentFrame != 1)
                        {
                            container->contMcs->gotoAndStop(1);
                        }
                        if (container->cont->currentFrame > 18)
                        {
                            container->cont->gotoAndStop(container->cont->currentFrame - 18);
                        }
                        else if (container->cont->currentFrame < 18)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(1);
                        }
                        if (container->cont->currentFrame < 9)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (!moveFlag)
                        {
                            moveFlag = true;
                        }
                    }
                    else if (direction == "up")
                    {
                        if (container->contMcs->currentFrame != 2)
                        {
                            container->contMcs->gotoAndStop(2);
                        }
                        if (container->cont->currentFrame < 19)
                        {
                            container->cont->gotoAndStop(container->cont->currentFrame + 18);
                        }
                        else if (container->cont->currentFrame < container->cont->totalFrames)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(19);
                        }
                        if (container->cont->currentFrame < 27)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (!moveFlag)
                        {
                            moveFlag = true;
                        }
                    }
                    else if (direction == "down")
                    {
                        if (container->contMcs->currentFrame != 1)
                        {
                            container->contMcs->gotoAndStop(1);
                        }
                        if (container->cont->currentFrame < 19)
                        {
                            container->cont->gotoAndStop(container->cont->currentFrame + 18);
                        }
                        else if (container->cont->currentFrame < container->cont->totalFrames)
                        {
                            container->cont->gotoAndStop((container->cont->currentFrame + 1));
                        }
                        else
                        {
                            container->cont->gotoAndStop(19);
                        }
                        if (container->cont->currentFrame < 27)
                        {
                            if (moveFlag)
                            {
                                moveFlag = false;
                            }
                        }
                        else if (!moveFlag)
                        {
                            moveFlag = true;
                        }
                    }
                }
                else if (direction == "left" || direction == "right")
                {
                    if (container->contMcs->currentFrame != 1)
                    {
                        container->contMcs->gotoAndStop(1);
                    }
                    if (container->cont->currentFrame > 18)
                    {
                        container->cont->gotoAndStop(container->cont->currentFrame - 18);
                    }
                    else if (container->cont->currentFrame != 1 && container->cont->currentFrame < 18)
                    {
                        container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else if (container->cont->currentFrame != 1)
                    {
                        container->cont->gotoAndStop(1);
                    }
                    if (container->cont->currentFrame < 9)
                    {
                        if (moveFlag)
                        {
                            moveFlag = false;
                        }
                    }
                    else if (!moveFlag)
                    {
                        moveFlag = true;
                    }
                }
                else if (direction == "up")
                {
                    if (container->contMcs->currentFrame != 2)
                    {
                        container->contMcs->gotoAndStop(2);
                    }
                    if (container->cont->currentFrame < 19)
                    {
                        container->cont->gotoAndStop(container->cont->currentFrame + 18);
                    }
                    else if (container->cont->currentFrame != 19 && container->cont->currentFrame < container->cont->totalFrames)
                    {
                        container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else if (container->cont->currentFrame != 19)
                    {
                        container->cont->gotoAndStop(19);
                    }
                    if (container->cont->currentFrame < 27)
                    {
                        if (moveFlag)
                        {
                            moveFlag = false;
                        }
                    }
                    else if (!moveFlag)
                    {
                        moveFlag = true;
                    }
                }
                else if (direction == "down")
                {
                    if (container->contMcs->currentFrame != 1)
                    {
                        container->contMcs->gotoAndStop(1);
                    }
                    if (container->cont->currentFrame < 19)
                    {
                        container->cont->gotoAndStop(container->cont->currentFrame + 18);
                    }
                    else if (container->cont->currentFrame != 19 && container->cont->currentFrame < container->cont->totalFrames)
                    {
                        container->cont->gotoAndStop((container->cont->currentFrame + 1));
                    }
                    else if (container->cont->currentFrame != 19)
                    {
                        container->cont->gotoAndStop(19);
                    }
                    if (container->cont->currentFrame < 27)
                    {
                        if (moveFlag)
                        {
                            moveFlag = false;
                        }
                    }
                    else if (!moveFlag)
                    {
                        moveFlag = true;
                    }
                }
            }
            Unit::animationHandler();
            return;
        }// end function

    }
}
