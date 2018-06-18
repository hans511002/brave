#ifndef SCREENS_DIFFICULTYLEVEL_H
#define SCREENS_DIFFICULTYLEVEL_H
#include "Screen.h"   
 
namespace screens
{   
    struct DeifficultyLevel_mc  : public MovieClip
    {
        MovieClipSub* first;
        MovieClipSub* firstEasy;
        MovieClipSub* firstNormal;
        MovieClipSub* firstHard;
        MCCase *  firstEasyComplexityCase;
        MCCase *  firstNormalComplexityCase;
        MCCase *  firstHardComplexityCase;
        MovieClipSub* shadow;
        DeifficultyLevel_mc();

    };
     class DifficultyLevel :public Screen
    {
    public: 
        //public var tempObject:Object;
        DeifficultyLevel_mc * container;
        bool openFlag ;
        bool closeFlag;
 

        DifficultyLevel():openFlag(true),closeFlag(false),container(0)
        {
            //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            return;
        }// end function

        bool init()
        {
            //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
            //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
            //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
            //this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
            //this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDwonHandler);
            //this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
            Main::mainClass->levelsMenuClass->manageListeners("off");
            this->container = new DeifficultyLevel_mc();
            this->container->stop();
            this->container->first->stop();
            this->container->firstEasy->stop();
            this->container->firstNormal->stop();
            this->container->firstHard->stop();
            this->container->firstEasyComplexityCase->stop();
            this->container->firstNormalComplexityCase->stop();
            this->container->firstHardComplexityCase->stop();
            this->container->firstEasyComplexityCase->setMouseEnabled(false);
            this->container->firstNormalComplexityCase->setMouseEnabled(false);
            this->container->firstHardComplexityCase->setMouseEnabled(false);
            this->addChild(this->container);
            this->setPosition(Main::SCREEN_WIDTH_HALF, Main::SCREEN_HEIGHT_HALF);
            //Sounds.instance.playSound("snd_menu_pageScrolling");
            return true;
        }// end function

        void enterFrameHandler(float dt)
        {
            if (this->frameCounter < 30)
            {
                this->frameCounter++;
            }
            else
            {
                this->frameCounter = 1;
            }
            if (this->openFlag)
            {
                if (this->container->currentFrame < this->container->totalFrames)
                {
                    this->container->gotoAndStop((this->container->currentFrame + 1));
                }
                if (this->container->first->currentFrame < this->container->first->totalFrames)
                {
                    this->container->first->gotoAndStop((this->container->first->currentFrame + 1));
                    this->container->firstEasy->gotoAndStop(1);
                    this->container->firstNormal->gotoAndStop(1);
                    this->container->firstHard->gotoAndStop(1);
                    this->container->firstEasyComplexityCase->stop();
                    this->container->firstNormalComplexityCase->stop();
                    this->container->firstHardComplexityCase->stop();
                    this->container->firstEasyComplexityCase->setMouseEnabled(false);
                    this->container->firstNormalComplexityCase->setMouseEnabled(false);
                    this->container->firstHardComplexityCase->setMouseEnabled(false);
                }
                if (this->container->currentFrame == this->container->totalFrames && this->container->first->currentFrame == this->container->first->totalFrames)
                {
                    this->openFlag = false;
                    this->container->firstEasyComplexityCase->setMouseEnabled(true);
                    this->container->firstNormalComplexityCase->setMouseEnabled(true);
                    this->container->firstHardComplexityCase->setMouseEnabled(true);
                }
            }
            else if (this->closeFlag)
            {
                if (this->container->currentFrame > 1)
                {
                    this->container->gotoAndStop((this->container->currentFrame - 1));
                }
                if (this->container->first->currentFrame > 1)
                {
                    this->container->first->gotoAndStop((this->container->first->currentFrame - 1));
                    this->container->firstEasy->gotoAndStop(1);
                    this->container->firstNormal->gotoAndStop(1);
                    this->container->firstHard->gotoAndStop(1);
                    this->container->firstEasyComplexityCase->stop();
                    this->container->firstNormalComplexityCase->stop();
                    this->container->firstHardComplexityCase->stop();
                    this->container->firstEasyComplexityCase->setMouseEnabled(false);
                    this->container->firstNormalComplexityCase->setMouseEnabled(false);
                    this->container->firstHardComplexityCase->setMouseEnabled(false);
                }
                if (this->container->currentFrame == 1 && this->container->first->currentFrame == 1)
                {
                    Main::mainClass->levelsMenuClass->removeChild(this);
                    Main::mainClass->levelsMenuClass->difficultyLevel = null;
                    Main::mainClass->levelsMenuClass->manageListeners("on"); 
                    Main::mainClass->levelsMenuClass->container->setMouseChildren(true);
                    Main::mainClass->levelsMenuClass->container->setMouseEnabled(true);
                }
            }
            return;
        }// end function

        void mouseMoveHandler(cocos2d::EventMouse * param1)
        {
            if (param1.target.parent.name == "easy")
            {
                if (param1.target->mouseEnabled)
                {
                    if (this->container->firstEasy->currentFrame == 1)
                    {
                        this->container->firstEasy->gotoAndStop(2);
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
            }
            else if (this->container->firstEasy->currentFrame == 2)
            {
                this->container->firstEasy->gotoAndStop(1);
            }
            if (param1.target.parent.name == "normal")
            {
                if (param1.target->mouseEnabled)
                {
                    if (this->container->firstNormal->currentFrame == 1)
                    {
                        this->container->firstNormal->gotoAndStop(2);
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
            }
            else if (this->container->firstNormal->currentFrame == 2)
            {
                this->container->firstNormal->gotoAndStop(1);
            }
            if (param1.target.parent.name == "hard")
            {
                if (param1.target->mouseEnabled)
                {
                    if (this->container->firstHard->currentFrame == 1)
                    {
                        this->container->firstHard->gotoAndStop(2);
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                    }
                }
            }
            else if (this->container->firstHard->currentFrame == 2)
            {
                this->container->firstHard->gotoAndStop(1);
            }
            return;
        }// end function

        void mouseDwonHandler(cocos2d::EventMouse *event) 
        {
            if (event.target.parent.name == "easy")
            {
                if (event.target->mouseEnabled)
                {
                    if (this->container->firstEasy->currentFrame == 2)
                    {
                        this->container->firstEasy->gotoAndStop(3);
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            else if (event.target.parent.name == "normal")
            {
                if (event.target->mouseEnabled)
                {
                    if (this->container->firstNormal->currentFrame == 2)
                    {
                        this->container->firstNormal->gotoAndStop(3);
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            else if (event.target.parent.name == "hard")
            {
                if (event.target->mouseEnabled)
                {
                    if (this->container->firstHard->currentFrame == 2)
                    {
                        this->container->firstHard->gotoAndStop(3);
                        //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                    }
                }
            }
            return;
        }// end function

        void mouseUpHandler(cocos2d::EventMouse * event)
        {
            if (event.target.parent.name == "easy")
            {
                if (event.target->mouseEnabled)
                {
                    if (this->container->firstEasy->currentFrame == 3)
                    {
                        this->container->firstEasy->gotoAndStop(2);
                        this->closeFlag = true;
                        Main::mainClass->saveBoxClass->setValue("difficultyLevel", true);
                        Main::mainClass->saveBoxClass->setValue("complexityLevel", 1);
                        //Sounds.instance.playSound("snd_menu_pageScrolling");
                    }
                }
            }
            else if (this->container->firstEasy->currentFrame == 3)
            {
                this->container->firstEasy->gotoAndStop(1);
            }
            if (event.target.parent.name == "normal")
            {
                if (event.target->mouseEnabled)
                {
                    if (this->container->firstNormal->currentFrame == 3)
                    {
                        this->container->firstNormal->gotoAndStop(2);
                        this->closeFlag = true;
                        Main::mainClass->saveBoxClass->setValue("difficultyLevel", true);
                        Main::mainClass->saveBoxClass->setValue("complexityLevel", 2); 
                        //Sounds.instance.playSound("snd_menu_pageScrolling");
                    }
                }
            }
            else if (this->container->firstNormal->currentFrame == 3)
            {
                this->container->firstNormal->gotoAndStop(1);
            }
            if (event.target.parent.name == "hard")
            {
                if (event.target->mouseEnabled)
                {
                    if (this->container->firstHard->currentFrame == 3)
                    {
                        this->container->firstHard->gotoAndStop(2);
                        this->closeFlag = true;
                        Main::mainClass->saveBoxClass->setValue("difficultyLevel", true);
                        Main::mainClass->saveBoxClass->setValue("complexityLevel", 3); 
                        //Sounds.instance.playSound("snd_menu_pageScrolling");
                    }
                }
            }
            else if (this->container->firstHard->currentFrame == 3)
            {
                this->container->firstHard->gotoAndStop(1);
            }
            return;
        }// end function

        void autoguidersButtons()
        {
            this->autoguidesMouse_pt = cocos2d::Point(Main::mainClass->worldClass->mouseX, Main::mainClass->worldClass->mouseY);
            this->autoguidesObject = NULL;
            this->autoguidesObject_pt = this->container->firstEasy->localToGlobal(this->container->firstEasyComplexityCase->getPosition());
            this->autoguidesObjectWidth = this->container->firstEasyComplexityCase->width / 2;
            this->autoguidesObjectHeight = this->container->firstEasyComplexityCase->height / 2;
            if (this->container->firstEasyComplexityCase->hitText(autoguidesMouse_pt))
            {
                this->autoguidesObject = this->container->firstEasyComplexityCase;
            }
            if (!this->autoguidesObject)
            {
                this->autoguidesObject_pt = this->container->first->easy.localToGlobal(this->container->firstNormalComplexityCase->getPosition());
                this->autoguidesObjectWidth = this->container->firstNormalComplexityCase->width / 2;
                this->autoguidesObjectHeight = this->container->firstNormalComplexityCase->height / 2;
                if (this->container->firstNormalComplexityCase->hitText(autoguidesMouse_pt))
                {
                    this->autoguidesObject = this->container->firstNormalComplexityCase;
                }
            }
            if (!this->autoguidesObject)
            {
                this->autoguidesObject_pt = this->container->first->easy.localToGlobal(this->container->firstHardComplexityCase->getPosition());
                this->autoguidesObjectWidth = this->container->firstHardComplexityCase->width / 2;
                this->autoguidesObjectHeight = this->container->firstHardComplexityCase->height / 2;
                if (this->container->firstHardComplexityCase->hitText(autoguidesMouse_pt))
                {
                    this->autoguidesObject = this->container->firstHardComplexityCase;
                }
            }
            if (this->autoguidesObject)
            {
                //模拟事件
                this->tempObject = new Object();
                this->tempObject->target = this->autoguidesObject;
                this->mouseMoveHandler(this->tempObject);
            }
            return;
        }// end function

        //public function reInit(event:Event) : void
        //{
        //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDwonHandler);
        //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        //    return;
        //}// end function

    }
}
