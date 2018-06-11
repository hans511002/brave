 
#include "OpenLevel.h"  
#include "engine/World.h"
#include "engine/xml/ReadXML.h"
#include "engine/mc/mc.h"

namespace screens
{  
    OpenLevel::OpenLevel(int param1):frameCounter(0),openFlag(true),eyes1Counter(0)
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        this->playLevel = param1;
        Main::mainClass->saveBoxClass->playLevel = param1;
        return;
    }// end function

    bool OpenLevel::init()
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        this->manageListeners("on");
        Main::mainClass->levelsMenuClass->manageListeners("off");
        //this->stage.frameRate = 60;
        this->container = new OpenLevel_mc();
        this->container->stop();
        this->container->back->stop();
        this->container->back->backCase->stop();
        this->container->back->backCase->buttonMode = true;
        this->container->board->stop();
        this->container->board->description->stop();
        this->container->board->infoAdd->stop();
        this->container->board->infoAdd->getSphere->stop();
        this->container->board->infoAdd->fireSphere->stop();
        this->container->board->infoAdd->iceSphere->stop();
        this->container->board->infoAdd->stoneSphere->stop();
        this->container->board->infoAdd->levinSphere->stop();
        this->container->board->status->stop();
        this->container->board->map->stop();
        this->container->board->star1->stop();
        this->container->board->star2->stop();
        this->container->board->star3->stop();
        this->container->board->wreath->stop();
        this->container->board->mainMode->gotoAndStop(4);
        this->container->board->survivalMode->stop();
        this->container->board->currentComplexity->stop();
        this->container->board->currentComplexity->fire->gotoAndStop(std::round(std::random() * (this->container->board->currentComplexity->fire->totalFrames - 1) + 1));
        this->container->board->start->gotoAndStop(1);
        this->container->board->currentComplexity->complexityCase->buttonMode = true;
        this->container->board->mouseChildren = false;
        this->container->board->mouseEnabled = false;
        this->container->board->infoAdd->setVisible(false);
        this->addChild(this->container);
        this->container->board->gotoAndStop(this->playLevel);
        if (Main::mainClass->saveBoxClass.gameSave.data.starsOfLevels[(this->playLevel - 1)] < 3)
        {
            this->container->board->survivalMode->gotoAndStop(5);
        }
        else
        {
            this->container->board->survivalMode->eyes1->stop();
            this->container->board->survivalMode->eyes1.alpha = 0;
            this->container->board->survivalMode->survivalModeCase->buttonMode = true;
            if (!Main::mainClass->saveBoxClass.gameSave.data.eduSurvHint)
            {
                //this->openSurvEdu = new Training_91_mc();
                //this->openSurvEdu->stop();
                //this->openSurvEdu->x = 367;
                //this->openSurvEdu->y = 372;
                //this->openSurvEdu->setVisible(false); 
                //this->openSurvEdu->mouseChildren = false;
                //this->openSurvEdu->mouseEnabled = false;
                //this->addChild(this->openSurvEdu);
            }
        }
        this->container->board->start->startCase->buttonMode = true;
        this->statusManage();
		int starsOfLevel = Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", (this->playLevel - 1));
		if(starsOfLevel >= 1)
        {
            this->container->board->star1->gotoAndStop(1);
        }
        else
        {
            this->container->board->star1->gotoAndStop(2);
        }
		if(starsOfLevel >= 2)
        {
			this->container->board->star2->gotoAndStop(1);
        }
        else
        {
			this->container->board->star2->gotoAndStop(2);
        }
		if(starsOfLevel >= 3)
        {
			this->container->board->star3->gotoAndStop(1);
        }
        else
        {
			this->container->board->star3->gotoAndStop(3);
        }
		if(starsOfLevel >= 4)
        {
			this->container->board->wreath->gotoAndStop(1);
        }
        else
        {
			this->container->board->wreath->gotoAndStop(2);
        }
		int complexityLevel = Main::mainClass->saveBoxClass->getIntValue("complexityLevel");
        if (complexityLevel < 4)
        {
        }
		char tmp[32];
		sprintf(tmp, "关卡 %i", this->playLevel);
		this->container->board->headerTXT->setText(tmp);
        
        this->container->board->headerTXT->setTextFormat(Main::mainClass->boldTextFormat);
        this->container->board->map->gotoAndStop(this->playLevel);
		if(complexityLevel == 1)
        {
            this->complexityManage(1);
        }
		else if(complexityLevel == 2)
        {
            this->complexityManage(2);
        }
		else if(complexityLevel == 3)
        {
            this->complexityManage(3);
        }
        else if (complexityLevel == 4)
        {
			int oldComplexityLevel = Main::mainClass->saveBoxClass->getIntValue("oldComplexityLevel");
			this->complexityManage(oldComplexityLevel);
        }
        //Sounds.instance.playSound("snd_menu_openBoard");
        return;
    }// end function

    void OpenLevel::enterFrameHandler(cocos2d::EventMouse * event) 
    {
        if (this->frameCounter < 30)
        {
            (this->frameCounter + 1);
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
            else
            {
                this->openFlag = false; 
                this->container->board->mouseChildren = true;
                this->container->board->mouseEnabled = true;
                this->stage.frameRate = 30;
                if (this->openSurvEdu)
                {
                    this->openSurvEdu->setVisible(true);
                }
            }
        }
        else if (this->closeFlag)
        {
            if (this->container->currentFrame > 1)
            {
                this->container->gotoAndStop((this->container->currentFrame - 1));
            }
            else
            {
                this->closeFlag = false;
                this->kill();
            }
        }
		//public var openSurvEdu:Training_91_mc;
        //if (this->openSurvEdu)
        //{
        //    if (this->openSurvEdu.visible)
        //    {
        //        if (!this->closeFlag)
        //        {
        //            if (!this->openSurvEdu.closeFlag)
        //            {
        //                if (this->openSurvEdu->currentFrame < 23)
        //                {
        //                    this->openSurvEdu->gotoAndStop((this->openSurvEdu->currentFrame + 1));
        //                }
        //                else
        //                {
        //                    this->openSurvEdu->gotoAndStop(13);
        //                }
        //            }
        //            else
        //            {
        //                if (this->openSurvEdu->currentFrame < 23)
        //                {
        //                    this->openSurvEdu->gotoAndStop(23);
        //                }
        //                if (this->openSurvEdu->currentFrame < this->openSurvEdu.totalFrames)
        //                {
        //                    this->openSurvEdu->gotoAndStop((this->openSurvEdu->currentFrame + 1));
        //                }
        //                else
        //                {
        //                    this->removeChild(this->openSurvEdu);
        //                    this->openSurvEdu = null;
        //                }
        //            }
        //        }
        //        else
        //        {
        //            this->removeChild(this->openSurvEdu);
        //            this->openSurvEdu = null;
        //        }
        //    }
        //}
        if (this->container->board->currentComplexity.fire->currentFrame < this->container->board->currentComplexity.fire.totalFrames)
        {
            this->container->board->currentComplexity.fire->gotoAndStop((this->container->board->currentComplexity.fire->currentFrame + 1));
        }
        else
        {
            this->container->board->currentComplexity.fire->gotoAndStop(1);
        }
        if (this->container->board->survivalMode->currentFrame == 4)
        {
            if (this->container->board->survivalMode->eyes->currentFrame < this->container->board->survivalMode->eyes.totalFrames)
            {
                this->container->board->survivalMode->eyes->gotoAndStop((this->container->board->survivalMode->eyes->currentFrame + 1));
            }
            else
            {
                this->container->board->survivalMode->eyes->gotoAndStop(1);
            }
        }
        if (this->container->board->infoAdd->isVisible())
        {
            if (this->container->board->infoAdd->getSphere->currentFrame < this->container->board->infoAdd->getSphere.totalFrames)
            {
                this->container->board->infoAdd->getSphere->gotoAndStop((this->container->board->infoAdd->getSphere->currentFrame + 1));
            }
            else
            {
                this->container->board->infoAdd->getSphere->gotoAndStop(1);
            }
            if (this->container->board->infoAdd->fireSphere.visible)
            {
                if (this->container->board->infoAdd->fireSphere->currentFrame < this->container->board->infoAdd->fireSphere.totalFrames)
                {
                    this->container->board->infoAdd->fireSphere->gotoAndStop((this->container->board->infoAdd->fireSphere->currentFrame + 1));
                }
                else
                {
                    this->container->board->infoAdd->fireSphere->gotoAndStop(1);
                }
            }
            if (this->container->board->infoAdd->iceSphere.visible)
            {
                if (this->container->board->infoAdd->iceSphere->currentFrame < this->container->board->infoAdd->iceSphere.totalFrames)
                {
                    this->container->board->infoAdd->iceSphere->gotoAndStop((this->container->board->infoAdd->iceSphere->currentFrame + 1));
                }
                else
                {
                    this->container->board->infoAdd->iceSphere->gotoAndStop(1);
                }
            }
            if (this->container->board->infoAdd->stoneSphere.visible)
            {
                if (this->container->board->infoAdd->stoneSphere->currentFrame < this->container->board->infoAdd->stoneSphere.totalFrames)
                {
                    this->container->board->infoAdd->stoneSphere->gotoAndStop((this->container->board->infoAdd->stoneSphere->currentFrame + 1));
                }
                else
                {
                    this->container->board->infoAdd->stoneSphere->gotoAndStop(1);
                }
            }
            if (this->container->board->infoAdd->levinSphere.visible)
            {
                if (this->container->board->infoAdd->levinSphere->currentFrame < this->container->board->infoAdd->levinSphere.totalFrames)
                {
                    this->container->board->infoAdd->levinSphere->gotoAndStop((this->container->board->infoAdd->levinSphere->currentFrame + 1));
                }
                else
                {
                    this->container->board->infoAdd->levinSphere->gotoAndStop(1);
                }
            }
        }
        if (this->hintSurvival)
        {
            this->hintSurvival.x = this->mouseX;
            this->hintSurvival.y = this->mouseY;
        }
        if (this->container->board->survivalMode->currentFrame < 4)
        {
            if (this->eyes1Counter < 60)
            {
                (this->eyes1Counter + 1);
            }
            else
            {
                this->eyes1Counter = 1;
            }
            if (this->eyes1Counter >= 11 && this->eyes1Counter <= 21)
            {
                this->container->board->survivalMode->eyes1.alpha = this->container->board->survivalMode->eyes1.alpha + 0.1;
                if (this->eyes1Counter == 21)
                {
                    this->container->board->survivalMode->eyes1.alpha = 1;
                }
            }
            else if (this->eyes1Counter >= 21 && this->eyes1Counter <= 31)
            {
                this->container->board->survivalMode->eyes1.alpha = this->container->board->survivalMode->eyes1.alpha - 0.1;
                if (this->eyes1Counter == 31)
                {
                    this->container->board->survivalMode->eyes1.alpha = 0;
                }
            }
            else if (this->eyes1Counter >= 31 && this->eyes1Counter <= 41)
            {
                this->container->board->survivalMode->eyes1.alpha = this->container->board->survivalMode->eyes1.alpha + 0.1;
                if (this->eyes1Counter == 41)
                {
                    this->container->board->survivalMode->eyes1.alpha = 1;
                }
            }
            else if (this->eyes1Counter >= 41 && this->eyes1Counter <= 51)
            {
                this->container->board->survivalMode->eyes1.alpha = this->container->board->survivalMode->eyes1.alpha - 0.1;
                if (this->eyes1Counter == 51)
                {
                    this->container->board->survivalMode->eyes1.alpha = 0;
                }
            }
            if (this->container->board->survivalMode->eyes1->currentFrame < this->container->board->survivalMode->eyes1.totalFrames)
            {
                this->container->board->survivalMode->eyes1->gotoAndStop((this->container->board->survivalMode->eyes1->currentFrame + 1));
            }
            else
            {
                this->container->board->survivalMode->eyes1->gotoAndStop(1);
            }
        }
        return;
    }// end function

    void OpenLevel::mouseMoveHandler(cocos2d::EventMouse * param1) 
    {
        if (param1->target->name == "backCase")
        {
            if (this->container->back->currentFrame == 1)
            {
                this->container->back->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->back->currentFrame == 2)
        {
            this->container->back->gotoAndStop(1);
        }
        if (param1->target->name == "complexityCase")
        {
            if (this->container->board->currentComplexity->currentFrame == 1 || this->container->board->currentComplexity->currentFrame == 4 
                || this->container->board->currentComplexity->currentFrame == 7)
            {
                this->container->board->currentComplexity->gotoAndStop((this->container->board->currentComplexity->currentFrame + 1));
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->board->currentComplexity->currentFrame == 2 || this->container->board->currentComplexity->currentFrame == 5 || this->container->board->currentComplexity->currentFrame == 8)
        {
            this->container->board->currentComplexity->gotoAndStop((this->container->board->currentComplexity->currentFrame - 1));
        }
        if (param1->target->name == "survivalModeCase")
        {
            if (this->container->board->survivalMode->currentFrame == 1)
            {
                this->container->board->survivalMode->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
            if (this->container->board->survivalMode->currentFrame == 5)
            {
                if (!this->hintSurvival)
                {
                    this->hintSurvival = new HintSurvival_mc();
                    this->hintSurvival->stop();
                    this->hintSurvival->setPosition(this->mouseX,this->mouseY); 
                    this->hintSurvival->mouseChildren = false;
                    this->hintSurvival->mouseEnabled = false;
                    this->addChild(this->hintSurvival);
                }
            }
        }
        else
        {
            if (this->container->board->survivalMode->currentFrame == 2)
            {
                this->container->board->survivalMode->gotoAndStop(1);
            }
            if (this->hintSurvival)
            {
                this->removeChild(this->hintSurvival);
                this->hintSurvival = NULL;
            }
        }
        if (param1->target->name == "mainModeCase")
        {
            if (this->container->board->mainMode->currentFrame == 1)
            {
                this->container->board->mainMode->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->board->mainMode->currentFrame == 2)
        {
            this->container->board->mainMode->gotoAndStop(1);
        }
        if (param1->target->name == "startCase")
        {
            if (this->container->board->start->currentFrame == 1)
            {
                this->container->board->start->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->board->start->currentFrame == 2)
        {
            this->container->board->start->gotoAndStop(1);
        }
        return;
    }// end function

    void OpenLevel::mouseDownHandler(cocos2d::EventMouse * event) 
    {
        if (!this->openFlag)
        {
            if (event->target->name == "backCase")
            {
                if (this->container->back->currentFrame == 2)
                {
                    this->container->back->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "complexityCase")
            {
                if (this->container->board->currentComplexity->currentFrame == 2 || this->container->board->currentComplexity->currentFrame == 5 || this->container->board->currentComplexity->currentFrame == 8)
                {
                    this->container->board->currentComplexity->gotoAndStop((this->container->board->currentComplexity->currentFrame + 1));
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "survivalModeCase")
            {
                if (this->container->board->survivalMode->currentFrame == 2)
                {
                    this->container->board->survivalMode->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "mainModeCase")
            {
                if (this->container->board->mainMode->currentFrame == 2)
                {
                    this->container->board->mainMode->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "startCase")
            {
                if (this->container->board->start->currentFrame == 2)
                {
                    this->container->board->start->gotoAndStop(3);
                    //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            else if (event->target->name == "shadow")
            {
                this->close();
            }
        }
        return;
    }// end function

    void OpenLevel::mouseUpHandler(cocos2d::EventMouse * event) 
    {
        if (event->target->name == "backCase")
        {
            if (this->container->back->currentFrame == 3)
            {
                this->container->back->gotoAndStop(2);
                this->close();
            }
        }
        else if (this->container->back->currentFrame == 3)
        {
            this->container->back->gotoAndStop(1);
        }
        if (event->target->name == "complexityCase")
        {
            if (this->container->board->currentComplexity->currentFrame == 3 || this->container->board->currentComplexity->currentFrame == 6 || this->container->board->currentComplexity->currentFrame == 9)
            {
                int complexityLevel=Main::mainClass->saveBoxClass->getIntValue("complexityLevel");
                if ( complexityLevel == 1)
                {
                    this->complexityManage(2);
                }
                else if ( complexityLevel == 2)
                {
                    this->complexityManage(3);
                }
                else if ( complexityLevel == 3)
                {
                    this->complexityManage(1);
                }
                this->container->board->currentComplexity->gotoAndStop((this->container->board->currentComplexity->currentFrame + 1));
            }
        }
        else if (this->container->board->currentComplexity->currentFrame == 3 || this->container->board->currentComplexity->currentFrame == 6 || this->container->board->currentComplexity->currentFrame == 9)
        {
            this->container->board->currentComplexity->gotoAndStop(this->container->board->currentComplexity->currentFrame - 2);
        }
        if (event->target->name == "survivalModeCase")
        {
            if (this->container->board->survivalMode->currentFrame == 3)
            {
                if (Main::mainClass->saveBoxClass->getIntValue("saveNo") < 4)
                {
                    //this->loginOrRegisterClass = new LoginOrRegister();
                    //this->addChild(this->loginOrRegisterClass);
                }
                else
                {
                    this->complexityManage(4);
                }
            }
        }
        else if (this->container->board->survivalMode->currentFrame == 3)
        {
            this->container->board->survivalMode->gotoAndStop(1);
        }
        if (event->target->name == "mainModeCase")
        {
            if (this->container->board->mainMode->currentFrame == 3)
            {
                this->container->board->mainMode->gotoAndStop(4);
                this->container->board->survivalMode->gotoAndStop(1);
                this->container->board->survivalMode->eyes1->stop();
                this->container->board->survivalMode->eyes1->alpha = 0;
                this->container->board->mainMode->mainModeCase->buttonMode = false;
                this->container->board->survivalMode->survivalModeCase->buttonMode = true; 
                this->container->board->currentComplexity->mouseChildren = true;
                this->container->board->currentComplexity->mouseEnabled = true;
                if (this->oldComplexity == 1)
                {
                    this->complexityManage(1);
                    this->container->board->currentComplexity->gotoAndStop(1);
                }
                else if (this->oldComplexity == 2 || this->oldComplexity == 4)
                {
                    this->complexityManage(2);
                    this->container->board->currentComplexity->gotoAndStop(4);
                }
                else if (this->oldComplexity == 3)
                {
                    this->complexityManage(3);
                    this->container->board->currentComplexity->gotoAndStop(7);
                }
            }
        }
        else if (this->container->board->mainMode->currentFrame == 3)
        {
            this->container->board->mainMode->gotoAndStop(1);
        }
        if (event->target->name == "startCase")
        {
            if (this->container->board->start->currentFrame == 3)
            {
                this->container->board->start->gotoAndStop(2);
                Main::mainClass->addNewScreen("World");
            }
        }
        else if (this->container->board->start->currentFrame == 3)
        {
            this->container->board->start->gotoAndStop(1);
        }
        return;
    }// end function

    void OpenLevel::complexityManage(int param1) 
    {
        if (param1 < 4)
        {
            if (this->playLevel == 1)
            {
                this->container->board->headerTXT.text = "关卡 1";
                this->container->board->description->gotoAndStop(1);
            }
            else if (this->playLevel == 2)
            {
                this->container->board->headerTXT.text = "关卡 2";
                this->container->board->description->gotoAndStop(2);
            }
            else if (this->playLevel == 3)
            {
                this->container->board->headerTXT.text = "关卡 3";
                this->container->board->description->gotoAndStop(3);
            }
            else if (this->playLevel == 4)
            {
                this->container->board->headerTXT.text = "关卡 4";
                this->container->board->description->gotoAndStop(4);
            }
            else if (this->playLevel == 5)
            {
                this->container->board->headerTXT.text = "关卡 5";
                this->container->board->description->gotoAndStop(5);
            }
            else if (this->playLevel == 6)
            {
                this->container->board->headerTXT.text = "关卡 6";
                this->container->board->description->gotoAndStop(6);
            }
            else if (this->playLevel == 7)
            {
                this->container->board->headerTXT.text = "关卡 7";
                this->container->board->description->gotoAndStop(7);
            }
            else if (this->playLevel == 8)
            {
                this->container->board->headerTXT.text = "关卡 8";
                this->container->board->description->gotoAndStop(8);
            }
            else if (this->playLevel == 9)
            {
                this->container->board->headerTXT.text = "关卡 9";
                this->container->board->description->gotoAndStop(9);
            }
            else if (this->playLevel == 10)
            {
                this->container->board->headerTXT.text = "关卡 10";
                this->container->board->description->gotoAndStop(10);
            }
            else if (this->playLevel == 11)
            {
                this->container->board->headerTXT.text = "关卡 11";
                this->container->board->description->gotoAndStop(11);
            }
            else if (this->playLevel == 12)
            {
                this->container->board->headerTXT.text = "关卡 12";
                this->container->board->description->gotoAndStop(12);
            }
            else if (this->playLevel == 13)
            {
                this->container->board->headerTXT.text = "关卡 13";
                this->container->board->description->gotoAndStop(13);
            }
            else if (this->playLevel == 14)
            {
                this->container->board->headerTXT.text = "关卡 14";
                this->container->board->description->gotoAndStop(14);
            }
            else if (this->playLevel == 15)
            {
                this->container->board->headerTXT.text = "关卡 15";
                this->container->board->description->gotoAndStop(15);
            }
            if (param1 == 1)
            {
                this->container->board->currentComplexity->gotoAndStop(1);
                Main::mainClass->saveBoxClass->setValue("oldComplexityLevel",1);
                Main::mainClass->saveBoxClass->setValue("complexityLevel",1);
                if (this->container->board->infoAdd->isVisible())
                {
                    this->container->board->infoAdd->setVisible(false);
                }
            }
            else if (param1 == 2)
            {
                this->container->board->currentComplexity->gotoAndStop(4); 
                Main::mainClass->saveBoxClass->setValue("oldComplexityLevel",2);
                Main::mainClass->saveBoxClass->setValue("complexityLevel",2);
                if (this->container->board->infoAdd->isVisible())
                {
                    this->container->board->infoAdd->setVisible(false);
                }
            }
            else if (param1 == 3)
            {
                this->container->board->currentComplexity->gotoAndStop(7); 
                Main::mainClass->saveBoxClass->setValue("oldComplexityLevel",3);
                Main::mainClass->saveBoxClass->setValue("complexityLevel",3);
                if (this->container->board->infoAdd->isVisible())
                {
                    this->container->board->infoAdd->setVisible(false);
                }
            }
            this->statusManage();
        }
        else if (param1 == 4)
        {
            this->container->board->description->gotoAndStop(16);
            this->container->board->mainMode->gotoAndStop(1);
            this->container->board->survivalMode->gotoAndStop(4);
            this->container->board->currentComplexity->gotoAndStop(10);
            this->container->board->mainMode->mainModeCase->buttonMode = true;
            this->container->board->survivalMode->survivalModeCase->buttonMode = false; 
            this->container->board->currentComplexity->mouseChildren = false;
            this->container->board->currentComplexity->mouseEnabled = false;
            this->oldComplexity = Main::mainClass->saveBoxClass->getIntValue("complexityLevel");
            Main::mainClass->saveBoxClass->setValue("complexityLevel", 4);
            if (!this->container->board->infoAdd->isVisible())
            {
                this->container->board->infoAdd->setVisible(true);
                if (this->playLevel == 1)
                {
                    this->container->board->infoAdd->gotoAndStop(1);
                    this->container->board->infoAdd->iceSphere->setVisible(false);
                    this->container->board->infoAdd->stoneSphere->setVisible(false);
                    this->container->board->infoAdd->levinSphere->setVisible(false);
                }
                else if (this->playLevel == 2)
                {
                    this->container->board->infoAdd->gotoAndStop(3);
                    this->container->board->infoAdd->levinSphere->setVisible(false);
                }
                else if (this->playLevel == 3)
                {
                    this->container->board->infoAdd->gotoAndStop(6);
                }
                else if (this->playLevel == 4)
                {
                    this->container->board->infoAdd->gotoAndStop(6);
                    this->container->board->infoAdd->fireSphere->setVisible(false);
                    this->container->board->infoAdd->iceSphere->setVisible(false);
                }
                else if (this->playLevel == 5)
                {
                    this->container->board->infoAdd->gotoAndStop(6);
                    this->container->board->infoAdd->fireSphere->setVisible(false);
                    this->container->board->infoAdd->stoneSphere->setVisible(false);
                }
                else if (this->playLevel == 6)
                {
                    this->container->board->infoAdd->gotoAndStop(6);
                    this->container->board->infoAdd->levinSphere->setVisible(false);
                }
                else if (this->playLevel == 7)
                {
                    this->container->board->infoAdd->gotoAndStop(6);
                }
                else if (this->playLevel == 8)
                {
                    this->container->board->infoAdd->gotoAndStop(7);
                    this->container->board->infoAdd->stoneSphere->setVisible(false);
                }
                else if (this->playLevel == 9)
                {
                    this->container->board->infoAdd->gotoAndStop(1);
                }
                else if (this->playLevel == 10)
                {
                    this->container->board->infoAdd->gotoAndStop(6);
                    this->container->board->infoAdd->levinSphere->setVisible(false);
                }
                else if (this->playLevel == 11)
                {
                    this->container->board->infoAdd->gotoAndStop(8);
                }
                else if (this->playLevel == 12)
                {
                    this->container->board->infoAdd->gotoAndStop(1);
                }
                else if (this->playLevel == 13)
                {
                    this->container->board->infoAdd->gotoAndStop(7);
                    this->container->board->infoAdd->fireSphere->setVisible(false);
                    this->container->board->infoAdd->stoneSphere->setVisible(false);
                }
                else if (this->playLevel == 14)
                {
                    this->container->board->infoAdd->gotoAndStop(8);
                }
                else if (this->playLevel == 15)
                {
                    this->container->board->infoAdd->gotoAndStop(1);
                    this->container->board->infoAdd->stoneSphere->setVisible(false);
                }
                this->container->board->infoAdd->getSphere->stop();
                this->container->board->infoAdd->fireSphere->stop();
                this->container->board->infoAdd->iceSphere->stop();
                this->container->board->infoAdd->stoneSphere->stop();
                this->container->board->infoAdd->levinSphere->stop();
                if (this->openSurvEdu)
                {
                    this->openSurvEdu->closeFlag = true;
                    Main::mainClass->saveBoxClass->setValue("eduSurvHint" , true);
                }
            }
            this->statusManage(true);
        }
        return;
    }// end function

    void OpenLevel::statusManage(bool param1) 
    {
        if (!param1)
        {
            if (Main::mainClass->saveBoxClass->getIntValue(("levelsFinish",(this->playLevel - 1)) == 0)
            {
                this->container->board->status->gotoAndStop(1);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue(("levelsFinish",(this->playLevel - 1)) == 1)
            {
                this->container->board->status->gotoAndStop(2);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue(("levelsFinish",(this->playLevel - 1)) == 2)
            {
                this->container->board->status->gotoAndStop(3);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("levelsFinish",(this->playLevel - 1)) == 3)
            {
                this->container->board->status->gotoAndStop(4);
            }
        }
        else if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels",(Main::mainClass->saveBoxClass.playLevel - 1) == 4)
        {
            this->container->board->status->gotoAndStop(5);
        }
        else
        {
            this->container->board->status->gotoAndStop(1);
        }
        return;
    }// end function

    void OpenLevel::manageListeners(string param1) 
    {
        if (param1 == "on")
        {
            //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
            //this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
            //this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
            //this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        }
        else if (param1 == "off")
        {
            //this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
            //this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
            //this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
            //this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        }
        return;
    }// end function

    void OpenLevel::autoguidersButtons()
    {
        this->autoguidesMouse_pt = cocos2d::Point(this->mouseX, this->mouseY);
        this->autoguidesObject = NULL;
        this->autoguidesObject_pt = this->container->back->localToGlobal(new Point(this->container->back->backCase->x, this->container->back->backCase->y));
        this->autoguidesObjectWidth = this->container->back->backCase->width / 2;
        this->autoguidesObjectHeight = this->container->back->backCase->height / 2;
        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        {
            this->autoguidesObject = this->container->back->backCase;
        }
        if (this->autoguidesObject)
        {
            this->tempObject = new Object();
            this->tempObject.target = this->autoguidesObject;
            this->mouseMoveHandler(this->tempObject);
        }
        return;
    }// end function

    void OpenLevel::close()
    {
        if (!this->closeFlag)
        {
            this->closeFlag = true; 
            this->container->board->mouseChildren = false;
            this->container->board->mouseEnabled = false;
            this->stage.frameRate = 60;
            if (Main::mainClass->saveBoxClass->getIntValue("complexityLevel") == 4)
            {
                Main::mainClass->saveBoxClass->setValue("complexityLevel",this->oldComplexity);
            }
            Main::mainClass->levelsMenuClass->autoguidersButtons();
        }
        return;
    }// end function

    void OpenLevel::kill()
    {
        if (!this->dead)
        {
            this->dead = true;
            Main::mainClass->levelsMenuClass->manageListeners("on");
            Main::mainClass->levelsMenuClass->removeChild(Main::mainClass->levelsMenuClass->openLevel);
            Main::mainClass->levelsMenuClass->openLevel = NULL;
        }
        return;
    }// end function

    //public function reInit(event:Event) : void
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    this->stage.frameRate = 30;
    //    return;
    //}// end function


}
#endif
