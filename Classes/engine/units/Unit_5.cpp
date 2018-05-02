
#include "Unit_5.h"

namespace engine
{
	namespace units
	{  
        Unit_5::Unit_5()
        {
            return;
        }// end function

        bool Unit_5::init() 
        {
            typeUnit = 5;
            container = new Unit_mc(this,"unit5", typeUnit); //new Unit5_mc(); 
            container->setScale(0.8);
            container->init();
            Unit::init();
            this->autorelease(); 
            return true;
        }// end function

        void Unit_5::animationHandler()  
        {
            if (!dead && !icemanFlag)
            {
                if (!airFlag && !airShockFlag)
                {
                    if (direction == "left" || direction == "right")
                    {
                        if (container->contMcs->currentFrame == 2)
                        {
                            container->contMcs->gotoAndStop(1);
                        }
                        if (container->currentFrame > 20)
                        {
                            if (container->currentFrame >= 29 && container->currentFrame < container->totalFrames)
                            {
                                container->gotoAndStop((container->currentFrame + 1));
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container->currentFrame < 29)
                            {
                                container->gotoAndStop(container->currentFrame - 20);
                            }
                            else
                            {
                                container->gotoAndStop(1);
                            }
                        }
                        else
                        {
                            if (container->currentFrame < 20)
                            {
                                container->gotoAndStop((container->currentFrame + 1));
                            }
                            else
                            {
                                container->gotoAndStop(1);
                            }
                            if (container->currentFrame < 9)
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
                    else if (direction == "up")
                    {
                        if (container->cont->currentFrame == 1)
                        {
                            container->cont->gotoAndStop(2);
                        }
                        if (container->currentFrame < 21)
                        {
                            if (container->currentFrame >= 9 && container->currentFrame < 20)
                            {
                                container->gotoAndStop((container->currentFrame + 1));
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container->currentFrame < 9)
                            {
                                container->gotoAndStop(container->currentFrame + 20);
                            }
                            else
                            {
                                container->gotoAndStop(21);
                            }
                        }
                        else
                        {
                            if (container->currentFrame < container->totalFrames)
                            {
                                container->gotoAndStop((container->currentFrame + 1));
                            }
                            else
                            {
                                container->gotoAndStop(21);
                            }
                            if (container->currentFrame < 29)
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
                    else if (direction == "down")
                    {
                        if (container->cont->currentFrame == 2)
                        {
                            container->cont->gotoAndStop(1);
                        }
                        if (container->currentFrame < 21)
                        {
                            if (container->currentFrame >= 9 && container->currentFrame < 20)
                            {
                                container->gotoAndStop((container->currentFrame + 1));
                                if (!moveFlag)
                                {
                                    moveFlag = true;
                                }
                            }
                            else if (container->currentFrame < 9)
                            {
                                container->gotoAndStop(container->currentFrame + 20);
                            }
                            else
                            {
                                container->gotoAndStop(21);
                            }
                        }
                        else
                        {
                            if (container->currentFrame < container->totalFrames)
                            {
                                container->gotoAndStop((container->currentFrame + 1));
                            }
                            else
                            {
                                container->gotoAndStop(21);
                            }
                            if (container->currentFrame < 29)
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
                }
                else if (direction == "left" || direction == "right")
                {
                    if (container->cont->currentFrame == 2)
                    {
                        container->cont->gotoAndStop(1);
                    }
                    if (container->currentFrame > 20)
                    {
                        if (container->currentFrame >= 29 && container->currentFrame < container->totalFrames)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container->currentFrame < 29)
                        {
                            container->gotoAndStop(container->currentFrame - 20);
                        }
                        else
                        {
                            container->gotoAndStop(1);
                        }
                    }
                    else
                    {
                        if (container->currentFrame != 1 && container->currentFrame < 20)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                        else if (container->currentFrame != 1)
                        {
                            container->gotoAndStop(1);
                        }
                        if (container->currentFrame < 9)
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
                else if (direction == "up")
                {
                    if (container->cont->currentFrame == 1)
                    {
                        container->cont->gotoAndStop(2);
                    }
                    if (container->currentFrame < 21)
                    {
                        if (container->currentFrame >= 9 && container->currentFrame < 20)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container->currentFrame < 9)
                        {
                            container->gotoAndStop(container->currentFrame + 20);
                        }
                        else
                        {
                            container->gotoAndStop(21);
                        }
                    }
                    else
                    {
                        if (container->currentFrame != 21 && container->currentFrame < container->totalFrames)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                        else if (container->currentFrame != 21)
                        {
                            container->gotoAndStop(21);
                        }
                        if (container->currentFrame < 29)
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
                else if (direction == "down")
                {
                    if (container->cont->currentFrame == 2)
                    {
                        container->cont->gotoAndStop(1);
                    }
                    if (container->currentFrame < 21)
                    {
                        if (container->currentFrame >= 9 && container->currentFrame < 20)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                            if (!moveFlag)
                            {
                                moveFlag = true;
                            }
                        }
                        else if (container->currentFrame < 9)
                        {
                            container->gotoAndStop(container->currentFrame + 20);
                        }
                        else
                        {
                            container->gotoAndStop(21);
                        }
                    }
                    else
                    {
                        if (container->currentFrame != 21 && container->currentFrame < container->totalFrames)
                        {
                            container->gotoAndStop((container->currentFrame + 1));
                        }
                        else if (container->currentFrame != 21)
                        {
                            container->gotoAndStop(21);
                        }
                        if (container->currentFrame < 29)
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
            }
            Unit_6::animationHandler();
            return;
        }// end function

    }
}
