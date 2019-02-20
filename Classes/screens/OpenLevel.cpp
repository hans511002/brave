 
#include "engine/World.h"
#include "engine/xml/ReadXML.h"
#include "MainClass.h"
#include "LevelsMenu.h"
#include "OpenLevel.h"  

namespace screens
{  
	OpenLevel_mc::OpenLevel_mc() :MovieClip("screen/", "OpenLevel_mc", "OpenLevel_mc")
	{
		this->board = this->createMovieClipSub("board");
		this->shadow = this->createCase("shadow");
		this->boardInfoAdd = this->board->createMovieClipSub("infoAdd");
		this->boardInfoAddLevinSphere = this->boardInfoAdd->createMovieClipSub("levinSphere ");
		this->boardInfoAddStoneSphere = this->boardInfoAdd->createMovieClipSub("stoneSphere ");
		this->boardInfoAddIceSphere = this->boardInfoAdd->createMovieClipSub("iceSphere ");
		this->boardInfoAddFireSphere =this->boardInfoAdd->createMovieClipSub("fireSphere ");
		this->boardInfoAddGetSphere = this->boardInfoAdd->createMovieClipSub("getSphere ");
		this->boardInfoAddLevinSphereSphereCase = this->boardInfoAddLevinSphere->createCase("sphereCase");
		this->boardInfoAddStoneSphereSphereCase = this->boardInfoAddStoneSphere->createCase("sphereCase");
		this->boardInfoAddIceSphereSphereCase = this->boardInfoAddIceSphere->createCase("sphereCase");
		this->boardInfoAddFireSphereSphereCase = this->boardInfoAddFireSphere->createCase("sphereCase");

		this->boardCurrentComplexity = this->board->createMovieClipSub("currentComplexity");
		this->boardCurrentComplexityComplexityCase = this->boardCurrentComplexity->createCase("complexityCase");
		this->boardCurrentComplexityFire = this->boardCurrentComplexity->createMovieClipSub("fire");

		this->boardStatus = this->board->createMovieClipSub("status");
		this->boardHeaderTXT = this->board->createText("headerTXT");
		this->boardStar1 = this->board->createMovieClipSub("star1");
		this->boardStar2 = this->board->createMovieClipSub("star2");
		this->boardStar3 = this->board->createMovieClipSub("star3");
		this->boardWreath = this->board->createMovieClipSub("wreath");
		this->boardMainMode = this->board->createMovieClipSub("mainMode");
		this->boardMainModeMainModeCase = this->boardMainMode->createCase("mainModeCase");
		this->boardSurvivalMode = this->board->createMovieClipSub("survivalMode");
		this->boardSurvivalModeSurvivalModeCase = this->boardSurvivalMode->createCase("survivalModeCase");
		this->boardSurvivalModeEyes = this->boardSurvivalMode->createMovieClipSub("eyes");

		this->boardMap = this->board->createMovieClipSub("map");
		this->boardStart = this->board->createMovieClipSub("start");
		this->boardStartStartCase = this->boardStart->createCase("startCase");
		this->boardDescription = this->board->createMovieClipSub("description");
		 
		
		//this->back;
	}
	HintSurvival_mc::HintSurvival_mc() :MovieClip("screen/", "HintSurvival_mc", "HintSurvival_mc")
	{ 
	}
    OpenLevel::OpenLevel(int param1): eyes1Counter(0)
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
        //this->container->back->backCase->stop();
        this->container->back->backCase->setMouseEnabled(true);
        this->container->board->stop();
        this->container->boardDescription->stop();
        this->container->boardInfoAdd->stop();
        this->container->boardInfoAddGetSphere->stop();
        this->container->boardInfoAddFireSphere->stop();
        this->container->boardInfoAddIceSphere->stop();
        this->container->boardInfoAddStoneSphere->stop();
        this->container->boardInfoAddLevinSphere->stop();
        this->container->boardStatus->stop();
        this->container->boardMap->stop();
        this->container->boardStar1->stop();
        this->container->boardStar2->stop();
        this->container->boardStar3->stop();
        this->container->boardWreath->stop();
        this->container->boardMainMode->gotoAndStop(4);
        this->container->boardSurvivalMode->stop();
        this->container->boardCurrentComplexity->stop();
        this->container->boardCurrentComplexityFire->gotoAndStop(std::round(std::random() * (this->container->boardCurrentComplexityFire->totalFrames - 1) + 1));
        this->container->boardStart->gotoAndStop(1);
        this->container->boardCurrentComplexityComplexityCase->setMouseEnabled(true);
        this->container->board->setMouseChildren(false);
        this->container->board->setMouseEnabled(false);
        this->container->boardInfoAdd->setVisible(false);
        this->addChild(this->container);
		this->container->back = new Back_mc();
		this->addChild(this->container->back);
		this->container->back->setPosition(0, Main::SCREEN_HEIGHT-100);

        this->container->board->gotoAndStop(this->playLevel);
        if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels",this->playLevel - 1) < 3)
        {
            this->container->boardSurvivalMode->gotoAndStop(5);
        }
        else
        {
            this->container->boardSurvivalModeEyes->stop();
			this->container->boardSurvivalModeEyes->setAlpha(0);
            this->container->boardSurvivalModeSurvivalModeCase->setMouseEnabled(true);
            if (!Main::mainClass->saveBoxClass->getBoolValue("eduSurvHint"))
            {
                //this->openSurvEdu = new Training_91_mc();
                //this->openSurvEdu->stop();
                //this->openSurvEdu->x = 367;
                //this->openSurvEdu->y = 372;
                //this->openSurvEdu->setVisible(false); 
                //this->openSurvEdu->setMouseChildren(false);
                //this->openSurvEdu->setMouseEnabled(false);
                //this->addChild(this->openSurvEdu);
            }
        }
        this->container->boardStartStartCase->setMouseEnabled(true);
        this->statusManage();
		int starsOfLevel = Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", (this->playLevel - 1));
		if(starsOfLevel >= 1)
        {
            this->container->boardStar1->gotoAndStop(1);
        }
        else
        {
            this->container->boardStar1->gotoAndStop(2);
        }
		if(starsOfLevel >= 2)
        {
			this->container->boardStar2->gotoAndStop(1);
        }
        else
        {
			this->container->boardStar2->gotoAndStop(2);
        }
		if(starsOfLevel >= 3)
        {
			this->container->boardStar3->gotoAndStop(1);
        }
        else
        {
			this->container->boardStar3->gotoAndStop(3);
        }
		if(starsOfLevel >= 4)
        {
			this->container->boardWreath->gotoAndStop(1);
        }
        else
        {
			this->container->boardWreath->gotoAndStop(2);
        }
		int complexityLevel = Main::mainClass->saveBoxClass->getIntValue("complexityLevel");
        if (complexityLevel < 4)
        {
        }
		char tmp[32];
		sprintf(tmp, "%s %i", I18N_VALUE(I18N_CODE::U200), this->playLevel);
		this->container->boardHeaderTXT->setText(tmp);
		this->container->boardHeaderTXT->setFontName("bold");
        //this->container->boardHeaderTXT->setTextFormat(Main::mainClass->boldTextFormat);
        this->container->boardMap->gotoAndStop(this->playLevel);
		if(complexityLevel >= 1 && complexityLevel<=3)
        {
            this->complexityManage(complexityLevel);
        } 
        else if (complexityLevel == 4)
        {
			int oldComplexityLevel = Main::mainClass->saveBoxClass->getIntValue("oldComplexityLevel");
			this->complexityManage(oldComplexityLevel);
        }
        AudioUtil::playSound("Snd_menu_openBoard.mp3");
        return true;
    }// end function

    void OpenLevel::enterFrameHandler(cocos2d::EventMouse * event) 
    {
        if (this->frameCounter < 30)
        {
            this->frameCounter ++;
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
                this->container->board->setMouseChildren(true);
                this->container->board->setMouseEnabled(true);
                //this->stage.frameRate = 30;
                //if (this->openSurvEdu)
                //{
                //    this->openSurvEdu->setVisible(true);
                //}
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
        //    if (this->openSurvEdu->isVisible())
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
        //                if (this->openSurvEdu->currentFrame < this->openSurvEdu->totalFrames)
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
        if (this->container->boardCurrentComplexityFire->currentFrame < this->container->boardCurrentComplexityFire->totalFrames)
        {
            this->container->boardCurrentComplexityFire->gotoAndStop((this->container->boardCurrentComplexityFire->currentFrame + 1));
        }
        else
        {
            this->container->boardCurrentComplexityFire->gotoAndStop(1);
        }
        if (this->container->boardSurvivalMode->currentFrame == 4)
        {
            if (this->container->boardSurvivalModeEyes->currentFrame < this->container->boardSurvivalModeEyes->totalFrames)
            {
                this->container->boardSurvivalModeEyes->gotoAndStop((this->container->boardSurvivalModeEyes->currentFrame + 1));
            }
            else
            {
                this->container->boardSurvivalModeEyes->gotoAndStop(1);
            }
        }
        if (this->container->boardInfoAdd->isVisible())
        {
            if (this->container->boardInfoAddGetSphere->currentFrame < this->container->boardInfoAddGetSphere->totalFrames)
            {
                this->container->boardInfoAddGetSphere->gotoAndStop((this->container->boardInfoAddGetSphere->currentFrame + 1));
            }
            else
            {
                this->container->boardInfoAddGetSphere->gotoAndStop(1);
            }
            if (this->container->boardInfoAddFireSphere->isVisible())
            {
                if (this->container->boardInfoAddFireSphere->currentFrame < this->container->boardInfoAddFireSphere->totalFrames)
                {
                    this->container->boardInfoAddFireSphere->gotoAndStop((this->container->boardInfoAddFireSphere->currentFrame + 1));
                }
                else
                {
                    this->container->boardInfoAddFireSphere->gotoAndStop(1);
                }
            }
            if (this->container->boardInfoAddIceSphere->isVisible())
            {
                if (this->container->boardInfoAddIceSphere->currentFrame < this->container->boardInfoAddIceSphere->totalFrames)
                {
                    this->container->boardInfoAddIceSphere->gotoAndStop((this->container->boardInfoAddIceSphere->currentFrame + 1));
                }
                else
                {
                    this->container->boardInfoAddIceSphere->gotoAndStop(1);
                }
            }
            if (this->container->boardInfoAddStoneSphere->isVisible())
            {
                if (this->container->boardInfoAddStoneSphere->currentFrame < this->container->boardInfoAddStoneSphere->totalFrames)
                {
                    this->container->boardInfoAddStoneSphere->gotoAndStop((this->container->boardInfoAddStoneSphere->currentFrame + 1));
                }
                else
                {
                    this->container->boardInfoAddStoneSphere->gotoAndStop(1);
                }
            }
            if (this->container->boardInfoAddLevinSphere->isVisible())
            {
                if (this->container->boardInfoAddLevinSphere->currentFrame < this->container->boardInfoAddLevinSphere->totalFrames)
                {
                    this->container->boardInfoAddLevinSphere->gotoAndStop((this->container->boardInfoAddLevinSphere->currentFrame + 1));
                }
                else
                {
                    this->container->boardInfoAddLevinSphere->gotoAndStop(1);
                }
            }
        }
        if (this->hintSurvival)
        {
            this->hintSurvival->setPosition(Main::mouseX, Main::mouseY);
        }
        if (this->container->boardSurvivalMode->currentFrame < 4)
        {
            if (this->eyes1Counter < 60)
            {
                this->eyes1Counter ++;
            }
            else
            {
                this->eyes1Counter = 1;
            }
            if (this->eyes1Counter >= 11 && this->eyes1Counter <= 21)
            {
                this->container->boardSurvivalModeEyes->setAlpha(this->container->boardSurvivalModeEyes->getAlpha() + 0.1);
                if (this->eyes1Counter == 21)
                    this->container->boardSurvivalModeEyes->setAlpha(1);
            }
            else if (this->eyes1Counter >= 21 && this->eyes1Counter <= 31)
            {
				this->container->boardSurvivalModeEyes->setAlpha(this->container->boardSurvivalModeEyes->getAlpha() - 0.1);
                if (this->eyes1Counter == 31)
					this->container->boardSurvivalModeEyes->setAlpha(0);
            }
            else if (this->eyes1Counter >= 31 && this->eyes1Counter <= 41)
            {
				this->container->boardSurvivalModeEyes->setAlpha(this->container->boardSurvivalModeEyes->getAlpha() + 0.1);
                if (this->eyes1Counter == 41)
					this->container->boardSurvivalModeEyes->setAlpha(1);
            }
            else if (this->eyes1Counter >= 41 && this->eyes1Counter <= 51)
            {
				this->container->boardSurvivalModeEyes->setAlpha(this->container->boardSurvivalModeEyes->getAlpha() - 0.1);
                if (this->eyes1Counter == 51)
					this->container->boardSurvivalModeEyes->setAlpha(0);
            }
            if (this->container->boardSurvivalModeEyes->currentFrame < this->container->boardSurvivalModeEyes->totalFrames)
            {
                this->container->boardSurvivalModeEyes->gotoAndStop((this->container->boardSurvivalModeEyes->currentFrame + 1));
            }
            else
            {
                this->container->boardSurvivalModeEyes->gotoAndStop(1);
            }
        }
        return;
    }// end function

    void OpenLevel::mouseMoveHandler(cocos2d::EventMouse * e) 
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if(!event)
			return;
        string targetName = event->target->getName();
        if (targetName == "backCase")
        {
            if (this->container->back->currentFrame == 1)
            {
                this->container->back->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->back->currentFrame == 2)
        {
            this->container->back->gotoAndStop(1);
        }
        if (targetName == "complexityCase")
        {
            if (this->container->boardCurrentComplexity->currentFrame == 1 || this->container->boardCurrentComplexity->currentFrame == 4 
                || this->container->boardCurrentComplexity->currentFrame == 7)
            {
                this->container->boardCurrentComplexity->gotoAndStop((this->container->boardCurrentComplexity->currentFrame + 1));
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->boardCurrentComplexity->currentFrame == 2 || this->container->boardCurrentComplexity->currentFrame == 5 || this->container->boardCurrentComplexity->currentFrame == 8)
        {
            this->container->boardCurrentComplexity->gotoAndStop((this->container->boardCurrentComplexity->currentFrame - 1));
        }
        if (targetName == "survivalModeCase")
        {
            if (this->container->boardSurvivalMode->currentFrame == 1)
            {
                this->container->boardSurvivalMode->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
            if (this->container->boardSurvivalMode->currentFrame == 5)
            {
                if (!this->hintSurvival)
                {
                    this->hintSurvival = new HintSurvival_mc();
                    this->hintSurvival->stop();
                    this->hintSurvival->setPosition(Main::mouseX,Main::mouseY); 
                    this->hintSurvival->setMouseChildren(false);
                    this->hintSurvival->setMouseEnabled(false);
                    this->addChild(this->hintSurvival);
                }
            }
        }
        else
        {
            if (this->container->boardSurvivalMode->currentFrame == 2)
            {
                this->container->boardSurvivalMode->gotoAndStop(1);
            }
            if (this->hintSurvival)
            {
                this->removeChild(this->hintSurvival);
                this->hintSurvival = NULL;
            }
        }
        if (targetName == "mainModeCase")
        {
            if (this->container->boardMainMode->currentFrame == 1)
            {
                this->container->boardMainMode->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->boardMainMode->currentFrame == 2)
        {
            this->container->boardMainMode->gotoAndStop(1);
        }
        if (targetName == "startCase")
        {
            if (this->container->boardStart->currentFrame == 1)
            {
                this->container->boardStart->gotoAndStop(2);
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
        }
        else if (this->container->boardStart->currentFrame == 2)
        {
            this->container->boardStart->gotoAndStop(1);
        }
        return;
    }// end function

    void OpenLevel::mouseDownHandler(cocos2d::EventMouse * e) 
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if(!event)
			return;
        string targetName = event->target->getName();
        if (!this->openFlag)
        {
            if (targetName == "backCase")
            {
                if (this->container->back->currentFrame == 2)
                {
                    this->container->back->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "complexityCase")
            {
                if (this->container->boardCurrentComplexity->currentFrame == 2 || this->container->boardCurrentComplexity->currentFrame == 5 || this->container->boardCurrentComplexity->currentFrame == 8)
                {
                    this->container->boardCurrentComplexity->gotoAndStop((this->container->boardCurrentComplexity->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "survivalModeCase")
            {
                if (this->container->boardSurvivalMode->currentFrame == 2)
                {
                    this->container->boardSurvivalMode->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "mainModeCase")
            {
                if (this->container->boardMainMode->currentFrame == 2)
                {
                    this->container->boardMainMode->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "startCase")
            {
                if (this->container->boardStart->currentFrame == 2)
                {
                    this->container->boardStart->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
            else if (targetName == "shadow")
            {
                this->close();
            }
        }
        return;
    }// end function

    void OpenLevel::mouseUpHandler(cocos2d::EventMouse * e) 
    {
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
        string targetName = event->target->getName();
        if (targetName == "backCase")
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
        if (targetName == "complexityCase")
        {
            if (this->container->boardCurrentComplexity->currentFrame == 3 || this->container->boardCurrentComplexity->currentFrame == 6 || this->container->boardCurrentComplexity->currentFrame == 9)
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
                this->container->boardCurrentComplexity->gotoAndStop((this->container->boardCurrentComplexity->currentFrame + 1));
            }
        }
        else if (this->container->boardCurrentComplexity->currentFrame == 3 || this->container->boardCurrentComplexity->currentFrame == 6 || this->container->boardCurrentComplexity->currentFrame == 9)
        {
            this->container->boardCurrentComplexity->gotoAndStop(this->container->boardCurrentComplexity->currentFrame - 2);
        }
        if (targetName == "survivalModeCase")
        {
            if (this->container->boardSurvivalMode->currentFrame == 3)
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
        else if (this->container->boardSurvivalMode->currentFrame == 3)
        {
            this->container->boardSurvivalMode->gotoAndStop(1);
        }
        if (targetName == "mainModeCase")
        {
            if (this->container->boardMainMode->currentFrame == 3)
            {
                this->container->boardMainMode->gotoAndStop(4);
                this->container->boardSurvivalMode->gotoAndStop(1);
                this->container->boardSurvivalModeEyes->stop();
                this->container->boardSurvivalModeEyes->setAlpha(0);
                this->container->boardMainModeMainModeCase->setMouseEnabled(false);
                this->container->boardSurvivalModeSurvivalModeCase->setMouseEnabled(true); 
                this->container->boardCurrentComplexity->setMouseChildren(true);
                this->container->boardCurrentComplexity->setMouseEnabled(true);
                if (this->oldComplexity == 1)
                {
                    this->complexityManage(1);
                    this->container->boardCurrentComplexity->gotoAndStop(1);
                }
                else if (this->oldComplexity == 2 || this->oldComplexity == 4)
                {
                    this->complexityManage(2);
                    this->container->boardCurrentComplexity->gotoAndStop(4);
                }
                else if (this->oldComplexity == 3)
                {
                    this->complexityManage(3);
                    this->container->boardCurrentComplexity->gotoAndStop(7);
                }
            }
        }
        else if (this->container->boardMainMode->currentFrame == 3)
        {
            this->container->boardMainMode->gotoAndStop(1);
        }
        if (targetName == "startCase")
        {
            if (this->container->boardStart->currentFrame == 3)
            {
                this->container->boardStart->gotoAndStop(2);
                Main::mainClass->addNewScreen("World");
            }
        }
        else if (this->container->boardStart->currentFrame == 3)
        {
            this->container->boardStart->gotoAndStop(1);
        }
        return;
    }// end function

    void OpenLevel::complexityManage(int param1) 
    { 
        if (param1 < 4)
        {
			char tmp[32];
			sprintf(tmp, "%s %i", I18N_VALUE(I18N_CODE::U200), this->playLevel);
			std::setText(this->container->boardHeaderTXT, tmp);
                this->container->boardDescription->gotoAndStop(this->playLevel);
            
            if (param1 == 1)
            {
                this->container->boardCurrentComplexity->gotoAndStop(1);
                Main::mainClass->saveBoxClass->setValue("oldComplexityLevel",1);
                Main::mainClass->saveBoxClass->setValue("complexityLevel",1);
                if (this->container->boardInfoAdd->isVisible())
                {
                    this->container->boardInfoAdd->setVisible(false);
                }
            }
            else if (param1 == 2)
            {
                this->container->boardCurrentComplexity->gotoAndStop(4); 
                Main::mainClass->saveBoxClass->setValue("oldComplexityLevel",2);
                Main::mainClass->saveBoxClass->setValue("complexityLevel",2);
                if (this->container->boardInfoAdd->isVisible())
                {
                    this->container->boardInfoAdd->setVisible(false);
                }
            }
            else if (param1 == 3)
            {
                this->container->boardCurrentComplexity->gotoAndStop(7); 
                Main::mainClass->saveBoxClass->setValue("oldComplexityLevel",3);
                Main::mainClass->saveBoxClass->setValue("complexityLevel",3);
                if (this->container->boardInfoAdd->isVisible())
                {
                    this->container->boardInfoAdd->setVisible(false);
                }
            }
            this->statusManage();
        }
        else if (param1 == 4)
        {
            this->container->boardDescription->gotoAndStop(16);
            this->container->boardMainMode->gotoAndStop(1);
            this->container->boardSurvivalMode->gotoAndStop(4);
            this->container->boardCurrentComplexity->gotoAndStop(10);
            this->container->boardMainModeMainModeCase->setMouseEnabled(true);
            this->container->boardSurvivalModeSurvivalModeCase->setMouseEnabled(false); 
            this->container->boardCurrentComplexity->setMouseChildren(false);
            this->container->boardCurrentComplexity->setMouseEnabled(false);
            this->oldComplexity = Main::mainClass->saveBoxClass->getIntValue("complexityLevel");
            Main::mainClass->saveBoxClass->setValue("complexityLevel", 4);
            if (!this->container->boardInfoAdd->isVisible())
            {
                this->container->boardInfoAdd->setVisible(true);
                if (this->playLevel == 1)
                {
                    this->container->boardInfoAdd->gotoAndStop(1);
                    this->container->boardInfoAddIceSphere->setVisible(false);
                    this->container->boardInfoAddStoneSphere->setVisible(false);
                    this->container->boardInfoAddLevinSphere->setVisible(false);
                }
                else if (this->playLevel == 2)
                {
                    this->container->boardInfoAdd->gotoAndStop(3);
                    this->container->boardInfoAddLevinSphere->setVisible(false);
                }
                else if (this->playLevel == 3)
                {
                    this->container->boardInfoAdd->gotoAndStop(6);
                }
                else if (this->playLevel == 4)
                {
                    this->container->boardInfoAdd->gotoAndStop(6);
                    this->container->boardInfoAddFireSphere->setVisible(false);
                    this->container->boardInfoAddIceSphere->setVisible(false);
                }
                else if (this->playLevel == 5)
                {
                    this->container->boardInfoAdd->gotoAndStop(6);
                    this->container->boardInfoAddFireSphere->setVisible(false);
                    this->container->boardInfoAddStoneSphere->setVisible(false);
                }
                else if (this->playLevel == 6)
                {
                    this->container->boardInfoAdd->gotoAndStop(6);
                    this->container->boardInfoAddLevinSphere->setVisible(false);
                }
                else if (this->playLevel == 7)
                {
                    this->container->boardInfoAdd->gotoAndStop(6);
                }
                else if (this->playLevel == 8)
                {
                    this->container->boardInfoAdd->gotoAndStop(7);
                    this->container->boardInfoAddStoneSphere->setVisible(false);
                }
                else if (this->playLevel == 9)
                {
                    this->container->boardInfoAdd->gotoAndStop(1);
                }
                else if (this->playLevel == 10)
                {
                    this->container->boardInfoAdd->gotoAndStop(6);
                    this->container->boardInfoAddLevinSphere->setVisible(false);
                }
                else if (this->playLevel == 11)
                {
                    this->container->boardInfoAdd->gotoAndStop(8);
                }
                else if (this->playLevel == 12)
                {
                    this->container->boardInfoAdd->gotoAndStop(1);
                }
                else if (this->playLevel == 13)
                {
                    this->container->boardInfoAdd->gotoAndStop(7);
                    this->container->boardInfoAddFireSphere->setVisible(false);
                    this->container->boardInfoAddStoneSphere->setVisible(false);
                }
                else if (this->playLevel == 14)
                {
                    this->container->boardInfoAdd->gotoAndStop(8);
                }
                else if (this->playLevel == 15)
                {
                    this->container->boardInfoAdd->gotoAndStop(1);
                    this->container->boardInfoAddStoneSphere->setVisible(false);
                }
                this->container->boardInfoAddGetSphere->stop();
                this->container->boardInfoAddFireSphere->stop();
                this->container->boardInfoAddIceSphere->stop();
                this->container->boardInfoAddStoneSphere->stop();
                this->container->boardInfoAddLevinSphere->stop();
                //if (this->openSurvEdu)
                //{
                //    this->openSurvEdu->closeFlag = true;
                //    Main::mainClass->saveBoxClass->setValue("eduSurvHint" , true);
                //}
            }
            this->statusManage(true);
        }
        return;
    }// end function

    void OpenLevel::statusManage(bool param1) 
    {
        if (!param1)
        {
            if (Main::mainClass->saveBoxClass->getIntValue("levelsFinish",(this->playLevel - 1)) == 0)
            {
                this->container->boardStatus->gotoAndStop(1);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("levelsFinish",(this->playLevel - 1)) == 1)
            {
                this->container->boardStatus->gotoAndStop(2);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("levelsFinish",(this->playLevel - 1)) == 2)
            {
                this->container->boardStatus->gotoAndStop(3);
            }
            else if (Main::mainClass->saveBoxClass->getIntValue("levelsFinish",(this->playLevel - 1)) == 3)
            {
                this->container->boardStatus->gotoAndStop(4);
            }
        }
        else if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels",Main::mainClass->saveBoxClass->playLevel - 1) == 4)
        {
            this->container->boardStatus->gotoAndStop(5);
        }
        else
        {
            this->container->boardStatus->gotoAndStop(1);
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
        //this->autoguidesMouse_pt = cocos2d::Point(Main::mouseX, Main::mouseY);
        //this->autoguidesObject = NULL;
        //this->autoguidesObject_pt = this->container->back->localToGlobal(  cocos2d::Point(this->container->back->backCase->x, this->container->back->backCase->y));
        //this->autoguidesObjectWidth = this->container->back->backCase->width / 2;
        //this->autoguidesObjectHeight = this->container->back->backCase->height / 2;
        //if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //    && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //    && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //    && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //{
        //    this->autoguidesObject = this->container->back->backCase;
        //}
        //if (this->autoguidesObject)
        //{
        //    this->tempObject = new Object();
        //    this->tempObject.target = this->autoguidesObject;
        //    this->mouseMoveHandler(this->tempObject);
        //}
        return;
    }// end function

    void OpenLevel::close()
    {
        if (!this->closeFlag)
        {
            this->closeFlag = true; 
            this->container->board->setMouseChildren(false);
            this->container->board->setMouseEnabled(false);
            //this->stage.frameRate = 60;
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
