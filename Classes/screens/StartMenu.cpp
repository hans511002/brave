#include "engine/World.h" 
#include "StartMenu.h"   
#include "MainClass.h"

namespace screens
{  
	bool StartMenu::firstMusicPlay = false;
    StartMenu_mc::StartMenu_mc():MovieClip("screen","StartMenu_mc","StartMenu_mc")
    { 
		start = this->createMovieClipSub("start",true);
		startStartCase = this->start->createCase("startCase", true);
		credits = this->createMovieClipSub("credits", true);
		creditsCreditsCase = this->credits->createCase("creditsCase", true);
		btnMusic = this->createMovieClipSub("btnMusic");
		btnMusicMusicCase = btnMusic->createCase("musicCase");
		btnSound = this->createMovieClipSub("btnSound");
		btnSoundSoundCase = btnSound->createCase("soundCase");
		back = this->createMovieClipSub("back");
		backBackCase = this->back->createCase("backCase");
		glitter = this->createMovieClipSub("glitter",true);
		saveType = this->createMovieClipSub("saveType", true);
		saveTypeLocalSave = saveType->createMovieClipSub("localSave", true);
		saveTypeLocalSaveLocalSaveCase = saveTypeLocalSave->createCase("localSaveCase", true);
		saveTypeOnlineSave = saveType->createMovieClipSub("onlineSave", true);
		saveTypeOnlineSaveOnlineSaveCase = saveTypeOnlineSave->createCase("onlineSaveCase", true);
		saveTypeOnlineSaveNickTXT = saveTypeOnlineSave->createText("nickTXT", true);
		saveTypeOnlineSaveWelcomeTXT = saveTypeOnlineSave->createText("welcomeTXT", true);
		//saveTypeOnlineSaveLogo = saveTypeOnlineSave->createSprite("logo");
		question = this->createMovieClipSub("question", true);
		questionNoteTXT = question->createText("noteTXT", true);
		questionBtnYes = question->createMovieClipSub("btnYes", true);
		questionBtnYesYesCase = questionBtnYes->createCase("yesCase", true);
		questionBtnNo = question->createMovieClipSub("btnNo", true);
		questionBtnNoNoCase = questionBtnNo->createCase("noCase", true);
		comlogo = this->createCase("comlogo");
		copyright = this->createText("copyright");
		tips = this->createText("tips");

		game1 = this->createMovieClipSub("game1", true);
		game1Game1Case = game1->createCase("game1Case", true);
		game1NewGame1Case = game1->createCase("newGame1Case",true);
		game1SyncSlot = game1->createMovieClipSub("syncSlot", true);
		game1SyncSlotSyncSlotCase = game1SyncSlot->createCase("syncSlotCase", true);
		game1DeleteSlot = game1->createMovieClipSub("deleteSlot");
		game1DeleteSlotDeleteSlotCase = game1DeleteSlot->createCase("deleteSlotCase", true);
		game1NumTXT = game1->createText("numTXT", true);
		game2 = this->createMovieClipSub("game2", true);
		game2Game2Case = game2->createCase("game2Case", true,true);
		game2NewGame2Case = game2->createCase("newGame2Case", true, true);
		game2SyncSlot = game2->createMovieClipSub("syncSlot", true);
		game2SyncSlotSyncSlotCase = game2SyncSlot->createCase("syncSlotCase", true, true);
		game2DeleteSlot = game2->createMovieClipSub("deleteSlot", true);
		game2DeleteSlotDeleteSlotCase = game2DeleteSlot->createCase("deleteSlotCase");
		game2NumTXT = game2->createText("numTXT", true);
		game3 = this->createMovieClipSub("game3", true);
		game3Game3Case = game3->createCase("game3Case", true, true);
		game3NewGame3Case = game3->createCase("newGame3Case", true, true);
		game3SyncSlot = game3->createMovieClipSub("syncSlot", true);
		game3SyncSlotSyncSlotCase = game3SyncSlot->createCase("syncSlotCase");
		game3DeleteSlot = game3->createMovieClipSub("deleteSlot", true);
		game3DeleteSlotDeleteSlotCase = game3DeleteSlot->createCase("deleteSlotCase", true);
		game3NumTXT = game3->createText("numTXT", true);
        return;
    }// end function

    StartMenu::StartMenu():page(1),question(0),loginFlag1(0),waitCounter(0),syncLoginCounter(0), syncHint(NULL)
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool StartMenu::init() 
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        this->container = new StartMenu_mc();
		//this->printNodePos(this->container);
		cocos2d::Size size = this->container->getSprite("bg")->getContentSize();
		float sy = Main::SCREEN_HEIGHT / size.height;
		float sx = (size.width - Main::SCREEN_WIDTH) / 2;
 		this->container->setPosition(-sx, Main::SCREEN_HEIGHT);
		this->container->setScaleY(sy);
		this->container->stop();
        this->container->start->stop();
        this->container->credits->stop();
        this->container->btnMusic->stop();
        this->container->btnSound->stop();
        this->container->back->stop();
        this->container->btnMusicMusicCase->setMouseEnabled(true);
        this->container->btnSoundSoundCase->setMouseEnabled(true);
        this->container->backBackCase->setMouseEnabled(true);
        this->container->back->setVisible(false);
		
        this->addChild(this->container);
        if (AudioUtil::musicOn)
            this->container->btnMusic->gotoAndStop(1);
        else
            this->container->btnMusic->gotoAndStop(4);
        if (AudioUtil::soundOn)
            this->container->btnSound->gotoAndStop(1);
        else
            this->container->btnSound->gotoAndStop(4);
        if (!Main::mainClass->middleScreenClass)
        {
            this->firstPlay = true;
			this->container->setAlpha(0);
            //Main::mainClass->bmp = new Bitmap(Main::mainClass->getBitmapData(this));
            //Main::mainClass->bmp.alpha = 0;
            //this->addChild(Main::mainClass->bmp);
            //this->container->setVisible(false);
            this->manageListeners("on");
        }
        if (!StartMenu::firstMusicPlay)
        {
            StartMenu::firstMusicPlay = true;
			AudioUtil::playMusic("Music_menu_main.mp3");
        }
        if (Main::mainClass->lastClass == "LevelsMenu")
        {
            this->container->gotoAndStop(53);
            if (Main::mainClass->saveBoxClass->getStringValue("type") == "site")
            {
                this->page = 4;
                this->waitCounter = 0;
				Main::mainClass->saveBoxClass->setValue(4, "haveSave", false);
				Main::mainClass->saveBoxClass->setValue(5, "haveSave", false);
				Main::mainClass->saveBoxClass->setValue(6,"haveSave",false);
                //Main::mainClass->IDIClass.getData(4);
                //Main::mainClass->IDIClass.getData(5);
                //Main::mainClass->IDIClass.getData(6);
            }
            else
            {
                this->page = 3;
            }
            this->container->back->setVisible(true);
        } 
        this->container->setMouseChildren(false);
        this->container->setMouseEnabled(false);
        return true;
    }// end function

    void StartMenu::enterFrameHandler(float dt)
    {
        if (this->frameCounter < 30)
            this->frameCounter++;
        else
            this->frameCounter = 1;
        if (this->container->glitter)
			this->container->glitter->tryPlay(); 
        if (this->firstPlay)
        {
            if (container->getAlpha()< 1)
            {
				container->setAlpha(container->getAlpha() + 0.2);
            }
            else
            {
                this->firstPlay = false;
                //this->container->setVisible(true);
                //this->removeChild(Main::mainClass->bmp);
                //Main::mainClass->bmp = NULL;
            }
        }
        else
        {
            if (this->page == 1)
            {
                if (this->container->currentFrame < 28)
                {
                    this->container->gotoAndStop((this->container->currentFrame + 1));
                    if (this->container->currentFrame == 9)
                    {
                        this->container->glitter->stop();
                    }
                    else if (this->container->currentFrame == 28)
                    {
                        this->container->startStartCase->setMouseEnabled(true);
                        this->container->creditsCreditsCase->setMouseEnabled(true); 
                        this->container->setMouseChildren(true);
                        this->container->setMouseEnabled(true);
                        this->container->back->setVisible(false);
                        this->autoguidersButtons();
                    }
                }
                else if (this->container->currentFrame > 28)
                {
                    this->container->gotoAndStop((this->container->currentFrame - 1));
                    if (this->container->currentFrame == 33)
                    {
                        this->container->start->stop();
                        this->container->credits->stop();
                    }
                    else if (this->container->currentFrame == 28)
                    {
                        this->container->startStartCase->setMouseEnabled(true);
                        this->container->creditsCreditsCase->setMouseEnabled(true); 
                        this->container->setMouseChildren(true);
                        this->container->setMouseEnabled(true);
                        this->container->back->setVisible(false);
                        this->autoguidersButtons();
                    }
                }
            }
            else if (this->page == 2)
            {
                if (this->container->currentFrame < 44)
                {
                    this->container->gotoAndStop((this->container->currentFrame + 1));
                    if (this->container->currentFrame == 35)
                    {
                        this->container->saveType->stop();
                        this->container->saveTypeLocalSave->stop();
                        this->container->saveTypeOnlineSave->stop();
                        this->container->saveTypeLocalSaveLocalSaveCase->stop();
                        this->container->saveTypeOnlineSaveOnlineSaveCase->stop();
                        if (this->container->saveTypeOnlineSave->isReady)
                        {
                            if (!Main::mainClass->currentUser.empty())
                            {
                                std::setText(this->container->saveTypeOnlineSaveWelcomeTXT,I18N_VALUE(I18N_CODE::U119));
                                std::setText(this->container->saveTypeOnlineSaveNickTXT,Main::mainClass->currentUser + I18N_VALUE(I18N_CODE::U120));
                            }
                            else
                            {
                                std::setText(this->container->saveTypeOnlineSaveWelcomeTXT,I18N_VALUE(I18N_CODE::U118));
                                std::setText(this->container->saveTypeOnlineSaveNickTXT,"");
                            }
                            this->welcomeText = this->container->saveTypeOnlineSaveWelcomeTXT->getString();
                            this->nickText = this->container->saveTypeOnlineSaveNickTXT->getString();
                        }
                        this->container->saveTypeLocalSaveLocalSaveCase->setMouseEnabled(true);
                        this->container->saveTypeOnlineSaveOnlineSaveCase->setMouseEnabled(true);
                        this->container->back->setVisible(true);
                    }
                    else if (this->container->currentFrame == 44)
                    { 
                        this->container->setMouseChildren(true);
                        this->container->setMouseEnabled(true);
                        this->autoguidersButtons();
                    }
                }
                else if (this->container->currentFrame > 44)
                {
                    this->container->gotoAndStop((this->container->currentFrame - 1));
                    if (this->container->currentFrame == 53)
                    {
                        this->container->gotoAndStop(34);
                    }
                }
            }
            else if (this->page == 3 || this->page == 4)
            {
                if (this->page == 3 || this->waitCounter == 3)
                {
                    if (this->container->currentFrame < 79)
                    {
                        this->container->gotoAndStop((this->container->currentFrame + 1));
                        if (this->container->currentFrame == 55)
                        {
                            if (this->page == 3)
                            {
                                if (!Main::mainClass->saveBoxClass->getBoolValue("haveSave", Main::mainClass->saveBoxClass->getDoc(1)))
                                {
                                    this->container->game1->gotoAndStop(4);
                                    this->container->game1NewGame1Case->stop();
                                    this->container->game1NewGame1Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game1->gotoAndStop(1);
                                    this->container->game1Game1Case->stop();
                                    this->container->game1Game1Case->setMouseEnabled(true);
                                    this->container->game1SyncSlot->stop();
                                    this->container->game1SyncSlotSyncSlotCase->stop();
                                    this->container->game1SyncSlotSyncSlotCase->setMouseEnabled(true);
                                    //if (Main::mainClass->IDIClass.idnet)
                                    //{
                                    //    if (!Main::mainClass->IDIClass.idnet.userData)
                                    //    {
                                    //        this->container->game1SyncSlot->gotoAndStop(1);
                                    //    }
                                    //    else
                                    //    {
                                    //        this->container->game1SyncSlot->gotoAndStop(4);
                                    //    }
                                    //}
                                    //else
                                    //{
                                        this->container->game1SyncSlot->setVisible(false);
                                    //}
                                    this->container->game1DeleteSlot->stop();
                                    this->container->game1DeleteSlotDeleteSlotCase->stop();
                                    this->container->game1DeleteSlotDeleteSlotCase->setMouseEnabled(true);
                                    int tempObject = 0;
									rapidjson::Value * a = JsonUtil::getValue(Main::mainClass->saveBoxClass->gameSave1, "starsOfLevels");
									if (a && a->IsArray()) {
										JsonUtil::Value::Array arr = a->GetArray();
										this->i = 0;
										while (this->i < arr.Size())
										{
											tempObject = tempObject + JsonUtil::getInt(&arr[i]);
											i++;
										} 
									}
									this->container->game1NumTXT->setPosition(this->container->game1NumTXT->getPosition()+Vec2(20,15));
                                    std::setText(this->container->game1NumTXT,Common::String(tempObject) + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    //this->container->game1NumTXT.setTextFormat(Main::mainClass->boldTextFormat);
                                }
								if (!Main::mainClass->saveBoxClass->getBoolValue("haveSave", Main::mainClass->saveBoxClass->getDoc(2)))
									//if (!Main::mainClass->saveBoxClass->gameSave2.data.haveSave)
                                {
                                    this->container->game2->gotoAndStop(4);
                                    this->container->game2NewGame2Case->stop();
                                    this->container->game2NewGame2Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game2->gotoAndStop(1);
                                    this->container->game2Game2Case->stop();
                                    this->container->game2Game2Case->setMouseEnabled(true);
                                    this->container->game2SyncSlot->stop();
                                    this->container->game2SyncSlotSyncSlotCase->stop();
                                    this->container->game2SyncSlotSyncSlotCase->setMouseEnabled(true);
                                    //if (Main::mainClass->IDIClass.idnet)
                                    //{
                                    //    if (!Main::mainClass->IDIClass.idnet.userData)
                                    //    {
                                    //        this->container->game2SyncSlot->gotoAndStop(1);
                                    //    }
                                    //    else
                                    //    {
                                    //        this->container->game2SyncSlot->gotoAndStop(4);
                                    //    }
                                    //}
                                    //else
                                    //{
                                        this->container->game2SyncSlot->setVisible(false);
                                    //}
                                    this->container->game2DeleteSlot->stop();
                                    this->container->game2DeleteSlotDeleteSlotCase->stop();
                                    this->container->game2DeleteSlotDeleteSlotCase->setMouseEnabled(true);
                                    int tempObject = 0;
									rapidjson::Value * a = JsonUtil::getValue(Main::mainClass->saveBoxClass->gameSave2, "starsOfLevels");
									if (a && a->IsArray()) {
										JsonUtil::Value::Array arr = a->GetArray();
										this->i = 0;
										while (this->i < arr.Size())
										{
											tempObject = tempObject + JsonUtil::getInt(&arr[i]);
											i++;
										}
									} 
									this->container->game2NumTXT->setPosition(this->container->game2NumTXT->getPosition() + Vec2(20, 15));
									std::setText(this->container->game2NumTXT, Common::String(tempObject) + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    //this->container->game2NumTXT.setTextFormat(Main::mainClass->boldTextFormat);
                                }
								if (!Main::mainClass->saveBoxClass->getBoolValue("haveSave", Main::mainClass->saveBoxClass->getDoc(3)))
									//if (!Main::mainClass->saveBoxClass->gameSave3.data.haveSave)
                                {
                                    this->container->game3->gotoAndStop(4);
                                    this->container->game3NewGame3Case->stop();
                                    this->container->game3NewGame3Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game3->gotoAndStop(1);
                                    this->container->game3Game3Case->stop();
                                    this->container->game3Game3Case->setMouseEnabled(true);
                                    this->container->game3SyncSlot->stop();
                                    this->container->game3SyncSlotSyncSlotCase->stop();
                                    this->container->game3SyncSlotSyncSlotCase->setMouseEnabled(true);
                                    //if (Main::mainClass->IDIClass.idnet)
                                    //{
                                    //    if (!Main::mainClass->IDIClass.idnet.userData)
                                    //    {
                                    //        this->container->game3SyncSlot->gotoAndStop(1);
                                    //    }
                                    //    else
                                    //    {
                                    //        this->container->game3SyncSlot->gotoAndStop(4);
                                    //    }
                                    //}
                                    //else
                                    //{
                                        this->container->game3SyncSlot->setVisible(false);
                                    //}
                                    this->container->game3DeleteSlot->stop();
                                    this->container->game3DeleteSlotDeleteSlotCase->stop();
                                    this->container->game3DeleteSlotDeleteSlotCase->setMouseEnabled(true);
									int tempObject = 0;
									rapidjson::Value * a = JsonUtil::getValue(Main::mainClass->saveBoxClass->gameSave3, "starsOfLevels");
									if (a && a->IsArray()) {
										JsonUtil::Value::Array arr = a->GetArray();
										this->i = 0;
										while (this->i < arr.Size())
										{
											tempObject = tempObject + JsonUtil::getInt(&arr[i]);
											i++;
										}
									}
									this->container->game3NumTXT->setPosition(this->container->game3NumTXT->getPosition() + Vec2(20, 15));
									std::setText(this->container->game1NumTXT, Common::String(tempObject) + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    //this->container->game3->numTXT.setTextFormat(Main::mainClass->boldTextFormat);
                                }
                            }
                            else if (this->page == 4)
                            {
                                if (!Main::mainClass->saveBoxClass->getBoolValue("haveSave", Main::mainClass->saveBoxClass->getDoc(4)))
                                {
                                    this->container->game1->gotoAndStop(4);
                                    this->container->game1NewGame1Case->stop();
                                    this->container->game1NewGame1Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game1->gotoAndStop(1);
                                    this->container->game1Game1Case->stop();
                                    this->container->game1Game1Case->setMouseEnabled(true);
                                    this->container->game1SyncSlot->stop();
                                    this->container->game1SyncSlotSyncSlotCase->stop();
                                    this->container->game1SyncSlotSyncSlotCase->setMouseEnabled(true);
                                    this->container->game1SyncSlot->setVisible(false);
                                    this->container->game1DeleteSlot->stop();
                                    this->container->game1DeleteSlotDeleteSlotCase->stop();
                                    this->container->game1DeleteSlotDeleteSlotCase->setMouseEnabled(true);
                                    int tempObject = 0;
                                    this->i = 0;
									int len = Main::mainClass->saveBoxClass->getLength("starsOfLevels",4);
                                    while (this->i < len)
                                    {
                                        tempObject = tempObject + Main::mainClass->saveBoxClass->getIntValue("starsOfLevels",this->i,4);
                                        i++;
                                    }
                                    tempObject =  tempObject + 3;
                                    std::setText(this->container->game1NumTXT, Common::String(tempObject) + "/" + Main::mainClass->saveBoxClass->maxStars);
                                    this->container->game1NumTXT->setFontName("bold");
                                }
								if (!Main::mainClass->saveBoxClass->getBoolValue("haveSave", Main::mainClass->saveBoxClass->getDoc(5)))
                                {
                                    this->container->game2->gotoAndStop(4);
                                    this->container->game2NewGame2Case->stop();
                                    this->container->game2NewGame2Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game2->gotoAndStop(1);
                                    this->container->game2Game2Case->stop();
                                    this->container->game2Game2Case->setMouseEnabled(true);
                                    this->container->game2SyncSlot->stop();
                                    this->container->game2SyncSlotSyncSlotCase->stop();
                                    this->container->game2SyncSlotSyncSlotCase->setMouseEnabled(true);
                                    this->container->game2SyncSlot->setVisible(false);
                                    this->container->game2DeleteSlot->stop();
                                    this->container->game2DeleteSlotDeleteSlotCase->stop();
                                    this->container->game2DeleteSlotDeleteSlotCase->setMouseEnabled(true);
                                    int tempObject = 0;
                                    this->i = 0;
									int len = Main::mainClass->saveBoxClass->getLength("starsOfLevels", 5);
									while (this->i < len)
                                    { 
										tempObject = tempObject + Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", this->i, 5);
                                        i++;
                                    }
                                    tempObject = tempObject + 3;
                                    std::setText(this->container->game2NumTXT, Common::String(tempObject) + "/" + Main::mainClass->saveBoxClass->maxStars);
									this->container->game2NumTXT->setFontName("bold");
                                }
								if (!Main::mainClass->saveBoxClass->getBoolValue("haveSave", Main::mainClass->saveBoxClass->getDoc(6)))
                                {
                                    this->container->game3->gotoAndStop(4);
                                    this->container->game3NewGame3Case->stop();
                                    this->container->game3NewGame3Case->setMouseEnabled(true);
                                }
                                else
                                {
                                    this->container->game3->gotoAndStop(1);
                                    this->container->game3Game3Case->stop();
                                    this->container->game3Game3Case->setMouseEnabled(true);
                                    this->container->game3SyncSlot->stop();
                                    this->container->game3SyncSlotSyncSlotCase->stop();
                                    this->container->game3SyncSlotSyncSlotCase->setMouseEnabled(true);
                                    this->container->game3SyncSlot->setVisible(false);
                                    this->container->game3DeleteSlot->stop();
                                    this->container->game3DeleteSlotDeleteSlotCase->stop();
                                    this->container->game3DeleteSlotDeleteSlotCase->setMouseEnabled(true);
                                    int tempObject = 0;
									int len = Main::mainClass->saveBoxClass->getLength("starsOfLevels", 6);
									this->i = 0;
                                    while (this->i < len)
                                    {
										tempObject = tempObject + Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", this->i, 6);
                                        i++;
                                    }
                                    tempObject = tempObject + 3;
									std::setText(this->container->game3NumTXT, Common::String(tempObject) + "/" + Main::mainClass->saveBoxClass->maxStars);
									this->container->game3NumTXT->setFontName("bold");
                                }
                            }
                            this->container->back->setVisible(true);
                        }
                        else if (this->container->currentFrame == 79)
                        { 
                            this->container->setMouseChildren(true);
                            this->container->setMouseEnabled(true);
                            this->autoguidersButtons();
                        }
                    }
                    if (this->question > 0)
                    {
                        if (this->container->currentFrame < 87)
                        {
                            this->container->gotoAndStop((this->container->currentFrame + 1));
                            if (this->container->currentFrame == 80)
                            {
                                this->container->question->stop();
                                this->container->questionBtnYes->stop();
                                this->container->questionBtnYesYesCase->stop();
                                this->container->questionBtnNo->stop();
                                this->container->questionBtnNoNoCase->stop();
                                this->container->questionBtnYesYesCase->setMouseEnabled(true);
                                this->container->questionBtnNoNoCase->setMouseEnabled(true); 
                                this->container->question->setMouseChildren(false);
                                this->container->question->setMouseEnabled(false);
                                if (this->question < 11)
                                    std::setText(this->container->questionNoteTXT,I18N_VALUE(I18N_CODE::U121));
                                else
                                    std::setText(this->container->questionNoteTXT,I18N_VALUE(I18N_CODE::U122));
                            }
                        }
                        else if (this->container->question->currentFrame < this->container->question->totalFrames)
                        {
                            this->container->question->gotoAndStop((this->container->question->currentFrame + 1));
                            if (this->container->question->currentFrame == this->container->question->totalFrames)
                            { 
                                this->container->question->setMouseChildren(true);
                                this->container->question->setMouseEnabled(true);
                            }
                        }
                    }
                    else if (this->question == -1)
                    {
                        bool tempObject = false;
                        if (this->container->question)
                        {
                            if (this->container->question->currentFrame > 1)
                            {
                                this->container->question->gotoAndStop((this->container->question->currentFrame - 1));
                                tempObject = true;
                            }
                        }
                        if (!tempObject)
                        {
                            if (this->container->currentFrame > 79)
                            {
                                this->container->gotoAndStop((this->container->currentFrame - 1));
                            }
                            else
                            {
                                this->question = 0; 
                                this->container->game1->setMouseChildren(true);
                                this->container->game1->setMouseEnabled(true); 
                                this->container->game2->setMouseChildren(true);
                                this->container->game2->setMouseEnabled(true); 
                                this->container->game3->setMouseChildren(true);
                                this->container->game3->setMouseEnabled(true);
								this->container->game1->setAlpha(1);
								this->container->game2->setAlpha(1);
								this->container->game3->setAlpha(1);
                                this->container->setMouseChildren(true);
                                this->container->setMouseEnabled(true);
                                this->autoguidersButtons();
                            }
                        }
                    }
                }
            }
            if (this->loginFlag)
            {
                //if (Main::mainClass->IDIClass.idnet)
                //{
                //    if (Main::mainClass->IDIClass.idnet.userData)
                //    {
                //        this->loginFlag = false;
                //        this->page = 4; 
                //        this->container->setMouseChildren(false);
                //        this->container->setMouseEnabled(false);
                //        this->waitCounter = 0;
                //        Main::mainClass->saveBoxClass->gameSave4.data.haveSave = false;
                //        Main::mainClass->saveBoxClass->gameSave5.data.haveSave = false;
                //        Main::mainClass->saveBoxClass->gameSave6.data.haveSave = false;
                //        Main::mainClass->IDIClass.getData(4);
                //        Main::mainClass->IDIClass.getData(5);
                //        Main::mainClass->IDIClass.getData(6);
                //    }
                //}
            }
            else if (this->loginFlag1 > 0)
            {
                if (this->question > 0 || this->page != 3)
                {
                    this->loginFlag1 = 0;
                }
                else if (!Main::mainClass->currentUser.empty())
                {
                    if (!Main::mainClass->currentUser.empty())
                    {
                        this->question = this->loginFlag1;
                        if (this->container->game1SyncSlot)
                            this->container->game1SyncSlot->gotoAndStop(4);
                        if (this->container->game2SyncSlot->isReady)
                            this->container->game2SyncSlot->gotoAndStop(4);
                        if (this->container->game3SyncSlot->isReady)
                            this->container->game3SyncSlot->gotoAndStop(4);
                        this->container->game1->setMouseChildren(false);
                        this->container->game1->setMouseEnabled(false); 
                        this->container->game2->setMouseChildren(false);
                        this->container->game2->setMouseEnabled(false); 
                        this->container->game3->setMouseChildren(false);
                        this->container->game3->setMouseEnabled(false);
						this->container->game1->setAlpha(0.5);
						this->container->game2->setAlpha(0.5);
						this->container->game3->setAlpha(0.5);
                        this->loginFlag1 = 0;
                    }
                }
            }
        }
        return;
    }// end function
	bool StartMenu::preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType)
	{
		removeEventTarget(event, this);
		Vec2 pos = event->getLocationInView();
		switch (_mouseEventType)
		{
		case cocos2d::EventMouse::MouseEventType::MOUSE_NONE:
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_DOWN:
			if (event->currentTargets.size() > 1) {
				//removeEventTarget(event, "shadow");
				//removeEventTarget(event, "sphereCase", "fireCase");
			}
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_UP:
			if (event->currentTargets.size() > 1) {
 			}
			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_MOVE:
 			break;
		case cocos2d::EventMouse::MouseEventType::MOUSE_SCROLL:
			break;
		default:
			break;
		}
		event->reset();
		return false;
	};
    void StartMenu::mouseMoveHandler(cocos2d::EventMouse * e)  
    {
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		if (!globalNode)EventNode::mouseMoveHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_MOVE))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		//return;
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			EventNode::beginTouchNode = event->target;
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
			if (targetName == "musicCase")
			{
				if (this->container->btnMusic->currentFrame == 1 || this->container->btnMusic->currentFrame == 4)
				{
					this->container->btnMusic->gotoAndStop((this->container->btnMusic->currentFrame + 1));
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->btnMusic->currentFrame == 2 || this->container->btnMusic->currentFrame == 5)
			{
				this->container->btnMusic->gotoAndStop((this->container->btnMusic->currentFrame - 1));
			}
			if (targetName == "soundCase")
			{
				if (this->container->btnSound->currentFrame == 1 || this->container->btnSound->currentFrame == 4)
				{
					this->container->btnSound->gotoAndStop((this->container->btnSound->currentFrame + 1));
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->btnSound->currentFrame == 2 || this->container->btnSound->currentFrame == 5)
			{
				this->container->btnSound->gotoAndStop((this->container->btnSound->currentFrame - 1));
			}

			if (this->container->start && this->container->start->isReady)
			{
				if (this->container->startStartCase->mouseEnabled)
				{
					if (targetName == "startCase")
					{
						if (this->container->start->currentFrame == 1)
						{
							this->container->start->gotoAndStop(2);
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
					else if (this->container->start->currentFrame == 2)
					{
						this->container->start->gotoAndStop(1);
					}
					if (targetName == "creditsCase")
					{
						if (this->container->credits->currentFrame == 1)
						{
							this->container->credits->gotoAndStop(2);
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
					else if (this->container->credits->currentFrame == 2)
					{
						this->container->credits->gotoAndStop(1);
					}
				}
			}
			else if (this->container->saveType && this->container->saveType->isReady)
			{
				if (targetName == "localSaveCase")
				{
					if (this->container->saveTypeLocalSave->currentFrame == 1)
					{
						this->container->saveTypeLocalSave->gotoAndStop(2);
						//this->container->saveType->setChildIndex(this->container->saveTypeLocalSave, (this->container->saveType->numChildren - 1));
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->saveTypeLocalSave->currentFrame == 2)
				{
					this->container->saveTypeLocalSave->gotoAndStop(1);
				}
				if (targetName == "onlineSaveCase")
				{
					if (this->container->saveTypeOnlineSave->currentFrame == 1)
					{
						this->container->saveTypeOnlineSave->gotoAndStop(2);
						if (!this->welcomeText.empty())
						{
							std::setText(this->container->saveTypeOnlineSaveWelcomeTXT, this->welcomeText);
							std::setText(this->container->saveTypeOnlineSaveNickTXT, this->nickText);
							//this->container->saveTypeOnlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
						}
						//this->container->saveType->setChildIndex(this->container->saveTypeOnlineSave, (this->container->saveType->numChildren - 1));
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->saveTypeOnlineSave->currentFrame == 2)
				{
					this->container->saveTypeOnlineSave->gotoAndStop(1);
					if (!this->welcomeText.empty())
					{
						std::setText(this->container->saveTypeOnlineSaveWelcomeTXT, this->welcomeText);
						std::setText(this->container->saveTypeOnlineSaveNickTXT, this->nickText);
						//this->container->saveTypeOnlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
					}
				}
			}
			else if (this->container->game1 && this->container->game1->isReady)
			{
				if (targetName == "game1Case")
				{
					if (this->container->game1->currentFrame == 1)
					{
						this->container->game1->gotoAndStop(2);
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->game1->currentFrame == 2)
				{
					this->container->game1->gotoAndStop(1);
				}
				if (targetName == "game2Case")
				{
					if (this->container->game2->currentFrame == 1)
					{
						this->container->game2->gotoAndStop(2);
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->game2->currentFrame == 2)
				{
					this->container->game2->gotoAndStop(1);
				}
				if (targetName == "game3Case")
				{
					if (this->container->game3->currentFrame == 1)
					{
						this->container->game3->gotoAndStop(2);
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->game3->currentFrame == 2)
				{
					this->container->game3->gotoAndStop(1);
				}
				if (targetName == "newGame1Case")
				{
					if (this->container->game1->currentFrame == 4)
					{
						this->container->game1->gotoAndStop(5);
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->game1->currentFrame == 5)
				{
					this->container->game1->gotoAndStop(4);
				}
				if (targetName == "newGame2Case")
				{
					if (this->container->game2->currentFrame == 4)
					{
						this->container->game2->gotoAndStop(5);
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->game2->currentFrame == 5)
				{
					this->container->game2->gotoAndStop(4);
				}
				if (targetName == "newGame3Case")
				{
					if (this->container->game3->currentFrame == 4)
					{
						this->container->game3->gotoAndStop(5);
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->game3->currentFrame == 5)
				{
					this->container->game3->gotoAndStop(4);
				}
				if (targetName == "syncSlotCase")
				{
					//displayNode
					MCCase * scase = ISTYPE(MCCase, event->target);
					MovieClipSub  * syncSlot = scase->getParentMC<MovieClipSub>();
					MovieClipSub * game = syncSlot->getParentMC<MovieClipSub>();
					if (game->currentFrame < 4)
					{
						if (!this->syncHint)
						{
							this->syncHint = new Hint_mc();
							this->syncHint->gotoAndStop(16);
							if (game->getName() == "game1")
							{
								this->syncHint->setPositionX(this->container->game1->getPositionX() + this->container->game1SyncSlot->getPositionX() + this->container->game1SyncSlotSyncSlotCase->getPositionX() + 10);
								this->syncHint->setPositionY(this->container->game1->getPositionY() + this->container->game1SyncSlot->getPositionY() + this->container->game1SyncSlotSyncSlotCase->getPositionY() + 5);
							}
							else if (game->getName() == "game2")
							{
								this->syncHint->setPositionX(this->container->game2->getPositionX() + this->container->game2SyncSlot->getPositionX() + this->container->game2SyncSlotSyncSlotCase->getPositionX() + 10);
								this->syncHint->setPositionY(this->container->game2->getPositionY() + this->container->game2SyncSlot->getPositionY() + this->container->game2SyncSlotSyncSlotCase->getPositionY() + 5);
							}
							else if (game->getName() == "game3")
							{
								this->syncHint->setPositionX(this->container->game3->getPositionX() + this->container->game3SyncSlot->getPositionX() + this->container->game3SyncSlotSyncSlotCase->getPositionX() + 10);
								this->syncHint->setPositionY(this->container->game3->getPositionY() + this->container->game3SyncSlot->getPositionY() + this->container->game3SyncSlotSyncSlotCase->getPositionY() + 5);
							}
							this->syncHint->setMouseChildren(false);
							this->syncHint->mouseEnabled = false;
							this->addChild(this->syncHint);
						}
					}
					if (game->getName() == "game1")
					{
						if (this->container->game1SyncSlot->currentFrame == 1 || this->container->game1SyncSlot->currentFrame == 4)
						{
							this->container->game1SyncSlot->gotoAndStop((this->container->game1SyncSlot->currentFrame + 1));
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
					else if (game->getName() == "game2")
					{
						if (this->container->game2SyncSlot->currentFrame == 1 || this->container->game2SyncSlot->currentFrame == 4)
						{
							this->container->game2SyncSlot->gotoAndStop((this->container->game2SyncSlot->currentFrame + 1));
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
					else if (game->getName() == "game3")
					{
						if (this->container->game3SyncSlot->currentFrame == 1 || this->container->game3SyncSlot->currentFrame == 4)
						{
							this->container->game3SyncSlot->gotoAndStop((this->container->game3SyncSlot->currentFrame + 1));
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
				}
				else
				{
					if (this->syncHint)
					{
						this->removeChild(this->syncHint);
						this->syncHint = NULL;
					}
					if (this->container->game1->currentFrame < 4)
					{
						if (this->container->game1SyncSlot->currentFrame == 2 || this->container->game1SyncSlot->currentFrame == 5)
						{
							this->container->game1SyncSlot->gotoAndStop((this->container->game1SyncSlot->currentFrame - 1));
						}
					}
					if (this->container->game2->currentFrame < 4)
					{
						if (this->container->game2SyncSlot->currentFrame == 2 || this->container->game2SyncSlot->currentFrame == 5)
						{
							this->container->game2SyncSlot->gotoAndStop((this->container->game2SyncSlot->currentFrame - 1));
						}
					}
					if (this->container->game3->currentFrame < 4)
					{
						if (this->container->game3SyncSlot->currentFrame == 2 || this->container->game3SyncSlot->currentFrame == 5)
						{
							this->container->game3SyncSlot->gotoAndStop((this->container->game3SyncSlot->currentFrame - 1));
						}
					}
				}
				if (targetName == "deleteSlotCase")
				{
					MCCase * scase = ISTYPE(MCCase, event->target);
					MovieClipSub  * syncSlot = scase->getParentMC<MovieClipSub>();
					MovieClipSub * game = syncSlot->getParentMC<MovieClipSub>();
					if (game->getName() == "game1") {
						if (this->container->game1DeleteSlot->currentFrame == 1)
						{
							this->container->game1DeleteSlot->gotoAndStop(2);
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
					else if (this->container->game1->currentFrame < 4)
					{
						if (this->container->game1DeleteSlot->currentFrame == 2)
						{
							this->container->game1DeleteSlot->gotoAndStop(1);
						}
					}
					if (game->getName() == "game2")
					{
						if (this->container->game2DeleteSlot->currentFrame == 1)
						{
							this->container->game2DeleteSlot->gotoAndStop(2);
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
					else if (this->container->game2->currentFrame < 4)
					{
						if (this->container->game2DeleteSlot->currentFrame == 2)
						{
							this->container->game2DeleteSlot->gotoAndStop(1);
						}
					}
					if (game->getName() == "game3")
					{
						if (this->container->game3DeleteSlot->currentFrame == 1)
						{
							this->container->game3DeleteSlot->gotoAndStop(2);
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
					else if (this->container->game3->currentFrame < 4)
					{
						if (this->container->game3DeleteSlot->currentFrame == 2)
						{
							this->container->game3DeleteSlot->gotoAndStop(1);
						}
					}
				}
				if (this->container->question->isReady)
				{
					if (targetName == "yesCase")
					{
						MCCase * scase = ISTYPE(MCCase, event->target);
						MovieClipSub  * btnYes = scase->getParentMC<MovieClipSub>();
						if (btnYes->currentFrame == 1)
						{
							btnYes->gotoAndStop(2);
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
					else if (this->container->questionBtnYes->currentFrame == 2)
					{
						this->container->questionBtnYes->gotoAndStop(1);
					}
					if (targetName == "noCase")
					{
						MCCase * scase = ISTYPE(MCCase, event->target);
						MovieClipSub  * btnNo = scase->getParentMC<MovieClipSub>();
						if (btnNo->currentFrame == 1)
						{
							btnNo->gotoAndStop(2);
							AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
						}
					}
					else if (this->container->questionBtnNo->currentFrame == 2)
					{
						this->container->questionBtnNo->gotoAndStop(1);
					}
				}
			}
		}
    }// end function

    void StartMenu::mouseDownHandler(cocos2d::EventMouse * e)  
    {
		if (!globalNode)EventNode::mouseDownHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_DOWN))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		//Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			EventNode::beginTouchNode = event->target;
			if (targetName == "backCase")
			{
				if (this->container->back->currentFrame == 2)
				{
					this->container->back->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "musicCase")
			{
				if (this->container->btnMusic->currentFrame == 2 || this->container->btnMusic->currentFrame == 5)
				{
					this->container->btnMusic->gotoAndStop((this->container->btnMusic->currentFrame + 1));
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "soundCase")
			{
				if (this->container->btnSound->currentFrame == 2 || this->container->btnSound->currentFrame == 5)
				{
					this->container->btnSound->gotoAndStop((this->container->btnSound->currentFrame + 1));
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}

			else if (targetName == "logOut")
			{

			}
			if (this->container->start  && this->container->start->isReady)
			{
				if (targetName == "startCase")
				{
					if (this->container->start->currentFrame == 2)
					{
						this->container->start->gotoAndStop(3);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				else if (targetName == "creditsCase")
				{
					if (this->container->credits->currentFrame == 2)
					{
						this->container->credits->gotoAndStop(3);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
			}
			else if (this->container->saveType && this->container->saveType->isReady)
			{
				if (targetName == "localSaveCase")
				{
					if (this->container->saveTypeLocalSave->currentFrame == 2)
					{
						this->container->saveTypeLocalSave->gotoAndStop(3);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				else if (targetName == "onlineSaveCase")
				{
					if (this->container->saveTypeOnlineSave->currentFrame == 2)
					{
						this->container->saveTypeOnlineSave->gotoAndStop(3);
						if (!this->welcomeText.empty())
						{
							std::setText(this->container->saveTypeOnlineSaveWelcomeTXT, this->welcomeText);
							std::setText(this->container->saveTypeOnlineSaveNickTXT, this->nickText);
							//this->container->saveTypeOnlineSaveNickTXT.setTextFormat(Main::mainClass->boldTextFormat);
						}
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
			}
			else if (this->container->game1 && this->container->game1->isReady)
			{
				if (targetName == "game1Case")
				{
					if (this->container->game1->currentFrame == 2)
					{
						this->container->game1->gotoAndStop(3);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				else if (targetName == "game2Case")
				{
					if (this->container->game2->currentFrame == 2)
					{
						this->container->game2->gotoAndStop(3);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				else if (targetName == "game3Case")
				{
					if (this->container->game3->currentFrame == 2)
					{
						this->container->game3->gotoAndStop(3);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				else if (targetName == "newGame1Case")
				{
					if (this->container->game1->currentFrame == 5)
					{
						this->container->game1->gotoAndStop(6);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				else if (targetName == "newGame2Case")
				{
					if (this->container->game2->currentFrame == 5)
					{
						this->container->game2->gotoAndStop(6);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				else if (targetName == "newGame3Case")
				{
					if (this->container->game3->currentFrame == 5)
					{
						this->container->game3->gotoAndStop(6);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				else if (targetName == "syncSlotCase")
				{
					MCCase * scase = ISTYPE(MCCase, event->target);
					MovieClipSub  * parent = scase->getParentMC<MovieClipSub>();
					if (parent->currentFrame == 2 || parent->currentFrame == 5)
					{
						parent->gotoAndStop((parent->currentFrame + 1));
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				else if (targetName == "deleteSlotCase")
				{
					MCCase * scase = ISTYPE(MCCase, event->target);
					MovieClipSub  * parent = scase->getParentMC<MovieClipSub>();
					if (parent->currentFrame == 2)
					{
						parent->gotoAndStop(3);
						AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
					}
				}
				if (this->container->question)
				{
					if (targetName == "yesCase")
					{
						MCCase * scase = ISTYPE(MCCase, event->target);
						MovieClipSub  * parent = scase->getParentMC<MovieClipSub>();
						if (parent->currentFrame == 2)
						{
							parent->gotoAndStop(3);
							AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
						}
					}
					else if (targetName == "noCase")
					{
						MCCase * scase = ISTYPE(MCCase, event->target);
						MovieClipSub  * parent = scase->getParentMC<MovieClipSub>();
						if (parent->currentFrame == 2)
						{
							parent->gotoAndStop(3);
							AudioUtil::playSound("Snd_menu_stoneMouseDown.mp3");
						}
					}
				}
			}
		}
    }// end function

    void StartMenu::mouseUpHandler(cocos2d::EventMouse * e) 
    {
		if (!globalNode)EventNode::mouseUpHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_UP))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			if (targetName == "backCase")
			{
				if (this->container->back->currentFrame == 3)
				{
					this->container->back->gotoAndStop(1);
					if (this->question != 0)
					{
						this->question = -1;
					}
					else if (this->page == 2)
					{
						this->page = 1;
					}
					else if (this->page == 3 || this->page == 4)
					{
						this->page = 2;
					}
					this->container->setMouseChildren(false);
					this->container->setMouseEnabled(false);
				}
			}
			else if (this->container->back->currentFrame == 3)
			{
				this->container->back->gotoAndStop(1);
			}
			if (targetName == "musicCase")
			{
				if (this->container->btnMusic->currentFrame == 3 || this->container->btnMusic->currentFrame == 6)
				{
					if (this->container->btnMusic->currentFrame == 3)
					{
						this->container->btnMusic->gotoAndStop(5);
						AudioUtil::musicManage("off");
					}
					else if (this->container->btnMusic->currentFrame == 6)
					{
						this->container->btnMusic->gotoAndStop(2);
						AudioUtil::musicManage("on");
						//"music_menu_main", "music_world_beforeBattle", "music_world_battle"
						AudioUtil::playMusic("Music_menu_main.mp3");
					}
				}
			}
			else if (this->container->btnMusic->currentFrame == 3 || this->container->btnMusic->currentFrame == 6)
			{
				this->container->btnMusic->gotoAndStop(this->container->btnMusic->currentFrame - 2);
			}
			if (targetName == "soundCase")
			{
				if (this->container->btnSound->currentFrame == 3 || this->container->btnSound->currentFrame == 6)
				{
					if (this->container->btnSound->currentFrame == 3)
					{
						this->container->btnSound->gotoAndStop(5);
						//AudioUtil::soundManage("off");
					}
					else if (this->container->btnSound->currentFrame == 6)
					{
						this->container->btnSound->gotoAndStop(2);
						//AudioUtil::soundManage("on");
					}
				}
			}
			else if (this->container->btnSound->currentFrame == 3 || this->container->btnSound->currentFrame == 6)
			{
				this->container->btnSound->gotoAndStop(this->container->btnSound->currentFrame - 2);
			}
			if (this->container->start && this->container->start->isReady)
			{
				if (targetName == "startCase")
				{
					if (this->container->start->currentFrame == 3)
					{
						this->page = 2;
						this->container->setMouseChildren(false);
						this->container->mouseEnabled = false;
					}
				}
				else if (this->container->start->currentFrame == 3)
				{
					this->container->start->gotoAndStop(1);
				}
				if (targetName == "creditsCase")
				{
					if (this->container->credits->currentFrame == 3)
					{
						this->container->credits->gotoAndStop(2);
						//this->creditsClass = new Credits();
						//this->addChild(this->creditsClass);
					}
				}
				else if (this->container->credits->currentFrame == 3)
				{
					this->container->credits->gotoAndStop(1);
				}
			}
			else if (this->container->saveType && this->container->saveType->isReady)
			{
				if (targetName == "localSaveCase")
				{
					if (this->container->saveTypeLocalSave->currentFrame == 3)
					{
						this->container->saveTypeLocalSave->gotoAndStop(2);
						this->page = 3;
						this->container->setMouseChildren(false);
						this->container->mouseEnabled = false;
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->saveTypeLocalSave->currentFrame == 3)
				{
					this->container->saveTypeLocalSave->gotoAndStop(1);
				}
				if (targetName == "onlineSaveCase")
				{
					if (this->container->saveTypeOnlineSave->currentFrame == 3)
					{
						this->container->saveTypeOnlineSave->gotoAndStop(2);
						if (!this->welcomeText.empty())
						{
							std::setText(this->container->saveTypeOnlineSaveWelcomeTXT, this->welcomeText);
							std::setText(this->container->saveTypeOnlineSaveNickTXT, this->nickText);
							//this->container->saveTypeOnlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
						}
						//if (Main::mainClass->IDIClass.idnet)
						//{
						//    if (!Main::mainClass->IDIClass.idnet.userData)
						//    {
						//        this->loginFlag = true;
						//        Main::mainClass->IDIClass.idnet.toggleInterface();
						//    }
						//    else
						//    {
						//        this->page = 4; 
						//        this->container->setMouseChildren(false);
						//        this->container->mouseEnabled = false;
						//        this->waitCounter = 0;
						//        Main::mainClass->saveBoxClass->gameSave4.data.haveSave = false;
						//        Main::mainClass->saveBoxClass->gameSave5.data.haveSave = false;
						//        Main::mainClass->saveBoxClass->gameSave6.data.haveSave = false;
						//        Main::mainClass->IDIClass.getData(4);
						//        Main::mainClass->IDIClass.getData(5);
						//        Main::mainClass->IDIClass.getData(6);
						//    }
						//}
						AudioUtil::playSound("Snd_menu_stoneMouseMove.mp3");
					}
				}
				else if (this->container->saveTypeOnlineSave->currentFrame == 3)
				{
					this->container->saveTypeOnlineSave->gotoAndStop(1);
					if (!this->welcomeText.empty())
					{
						std::setText(this->container->saveTypeOnlineSaveWelcomeTXT, this->welcomeText);
						std::setText(this->container->saveTypeOnlineSaveNickTXT, this->nickText);
						//this->container->saveTypeOnlineSave->nickTXT.setTextFormat(Main::mainClass->boldTextFormat);
					}
				}
			}
			else if (this->container->game1 && this->container->game1->isReady)
			{
				if (targetName == "game1Case")
				{
					if (this->container->game1->currentFrame == 3)
					{
						if (this->page == 3)
						{
							Main::mainClass->saveBoxClass->checkSaves(1);
						}
						else if (this->page == 4)
						{
							Main::mainClass->saveBoxClass->checkSaves(4);
						}
						Main::mainClass->addNewScreen("LevelsMenu");
					}
				}
				else if (this->container->game1->currentFrame == 3)
				{
					this->container->game1->gotoAndStop(1);
				}
				if (targetName == "game2Case")
				{
					if (this->container->game2->currentFrame == 3)
					{
						if (this->page == 3)
						{
							Main::mainClass->saveBoxClass->checkSaves(2);
						}
						else if (this->page == 4)
						{
							Main::mainClass->saveBoxClass->checkSaves(5);
						}
						Main::mainClass->addNewScreen("LevelsMenu");
					}
				}
				else if (this->container->game2->currentFrame == 3)
				{
					this->container->game2->gotoAndStop(1);
				}
				if (targetName == "game3Case")
				{
					if (this->container->game3->currentFrame == 3)
					{
						if (this->page == 3)
						{
							Main::mainClass->saveBoxClass->checkSaves(3);
						}
						else if (this->page == 4)
						{
							Main::mainClass->saveBoxClass->checkSaves(6);
						}
						Main::mainClass->addNewScreen("LevelsMenu");
					}
				}
				else if (this->container->game3->currentFrame == 3)
				{
					this->container->game3->gotoAndStop(1);
				}
				if (targetName == "newGame1Case")
				{
					if (this->container->game1->currentFrame == 6)
					{
						if (this->page == 3)
						{
							Main::mainClass->saveBoxClass->checkSaves(1);
						}
						else if (this->page == 4)
						{
							Main::mainClass->saveBoxClass->checkSaves(4);
						}
						Main::mainClass->addNewScreen("LevelsMenu");
					}
				}
				else if (this->container->game1->currentFrame == 6)
				{
					this->container->game1->gotoAndStop(4);
				}
				if (targetName == "newGame2Case")
				{
					if (this->container->game2->currentFrame == 6)
					{
						if (this->page == 3)
						{
							Main::mainClass->saveBoxClass->checkSaves(2);
						}
						else if (this->page == 4)
						{
							Main::mainClass->saveBoxClass->checkSaves(5);
						}
						Main::mainClass->addNewScreen("LevelsMenu");
					}
				}
				else if (this->container->game2->currentFrame == 6)
				{
					this->container->game2->gotoAndStop(4);
				}
				if (targetName == "newGame3Case")
				{
					if (this->container->game3->currentFrame == 6)
					{
						if (this->page == 3)
						{
							Main::mainClass->saveBoxClass->checkSaves(3);
						}
						else if (this->page == 4)
						{
							Main::mainClass->saveBoxClass->checkSaves(6);
						}
						Main::mainClass->addNewScreen("LevelsMenu");
					}
				}
				else if (this->container->game3->currentFrame == 6)
				{
					this->container->game3->gotoAndStop(4);
				}
				if (targetName == "syncSlotCase")
				{
					MCCase * scase = ISTYPE(MCCase, event->target);
					MovieClipSub  * parent = scase->getParentMC<MovieClipSub>();
					parent = parent->getParentMC<MovieClipSub>();
					if (parent->getName() == "game1") {
						if (this->container->game1SyncSlot->currentFrame == 3 || this->container->game1SyncSlot->currentFrame == 6)
						{
							this->container->game1SyncSlot->gotoAndStop((this->container->game1SyncSlot->currentFrame - 1));
							//if (Main::mainClass->IDIClass.idnet)
							//{
							//    if (Main::mainClass->IDIClass.idnet.userData)
							//    {
							//        this->question = 11; 
							//        this->container->game1->setMouseChildren(false);
							//        this->container->game1->setMouseEnabled(false); 
							//        this->container->game2->setMouseChildren(false);
							//        this->container->game2->setMouseEnabled(false); 
							//        this->container->game3->setMouseChildren(false);
							//        this->container->game3->setMouseEnabled(false);
							//        this->container->game1->alpha = 0.5;
							//        this->container->game2->alpha = 0.5;
							//        this->container->game3->alpha = 0.5;
							//    }
							//    else
							//    {
							//        Main::mainClass->IDIClass.idnet.toggleInterface();
							//        this->loginFlag1 = 11;
							//    }
							//    if (this->syncHint)
							//    {
							//        this->removeChild(this->syncHint);
							//        this->syncHint = NULL;
							//    }
							//}
						}
					}
					else if (this->container->game1->currentFrame < 4)
					{
						if (this->container->game1SyncSlot->currentFrame == 3 || this->container->game1SyncSlot->currentFrame == 6)
						{
							this->container->game1SyncSlot->gotoAndStop(this->container->game1SyncSlot->currentFrame - 2);
						}
					}
					if (parent->getName() == "game2")
					{
						if (this->container->game2SyncSlot->currentFrame == 3 || this->container->game2SyncSlot->currentFrame == 6)
						{
							this->container->game2SyncSlot->gotoAndStop((this->container->game2SyncSlot->currentFrame - 1));
							//if (Main::mainClass->IDIClass.idnet)
							//{
							//    if (Main::mainClass->IDIClass.idnet.userData)
							//    {
							//        this->question = 12; 
							//        this->container->game1->setMouseChildren(false);
							//        this->container->game1->setMouseEnabled(false); 
							//        this->container->game2->setMouseChildren(false);
							//        this->container->game2->setMouseEnabled(false); 
							//        this->container->game3->setMouseChildren(false);
							//        this->container->game3->setMouseEnabled(false);
							//        this->container->game1->alpha = 0.5;
							//        this->container->game2->alpha = 0.5;
							//        this->container->game3->alpha = 0.5;
							//    }
							//    else
							//    {
							//        Main::mainClass->IDIClass.idnet.toggleInterface();
							//        this->loginFlag1 = 12;
							//    }
							//    if (this->syncHint)
							//    {
							//        this->removeChild(this->syncHint);
							//        this->syncHint = NULL;
							//    }
							//}
						}
					}
					else if (this->container->game2->currentFrame < 4)
					{
						if (this->container->game2SyncSlot->currentFrame == 3 || this->container->game2SyncSlot->currentFrame == 6)
						{
							this->container->game2SyncSlot->gotoAndStop(this->container->game2SyncSlot->currentFrame - 2);
						}
					}
					if (parent->getName() == "game3")
					{
						if (this->container->game3SyncSlot->currentFrame == 3 || this->container->game3SyncSlot->currentFrame == 6)
						{
							this->container->game3SyncSlot->gotoAndStop((this->container->game3SyncSlot->currentFrame - 1));
							//if (Main::mainClass->IDIClass.idnet)
							//{
							//    if (Main::mainClass->IDIClass.idnet.userData)
							//    {
							//        this->question = 13; 
							//        this->container->game1->setMouseChildren(false);
							//        this->container->game1->setMouseEnabled(false); 
							//        this->container->game2->setMouseChildren(false);
							//        this->container->game2->setMouseEnabled(false); 
							//        this->container->game3->setMouseChildren(false);
							//        this->container->game3->setMouseEnabled(false);
							//        this->container->game1->alpha = 0.5;
							//        this->container->game2->alpha = 0.5;
							//        this->container->game3->alpha = 0.5;
							//    }
							//    else
							//    {
							//        Main::mainClass->IDIClass.idnet.toggleInterface();
							//        this->loginFlag1 = 13;
							//    }
							//    if (this->syncHint)
							//    {
							//        this->removeChild(this->syncHint);
							//        this->syncHint = NULL;
							//    }
							//}
						}
					}
					else if (this->container->game3->currentFrame < 4)
					{
						if (this->container->game3SyncSlot->currentFrame == 3 || this->container->game3SyncSlot->currentFrame == 6)
						{
							this->container->game3SyncSlot->gotoAndStop(this->container->game3SyncSlot->currentFrame - 2);
						}
					}

				}

				if (targetName == "deleteSlotCase") {
					MCCase * scase = ISTYPE(MCCase, event->target);
					MovieClipSub  * parent = scase->getParentMC<MovieClipSub>();
					parent = parent->getParentMC<MovieClipSub>();
					if (parent->getName() == "game1")
					{
						if (this->container->game1DeleteSlot->currentFrame == 3)
						{
							this->container->game1DeleteSlot->gotoAndStop(2);
							if (this->page == 3)
							{
								this->question = 1;
							}
							else if (this->page == 4)
							{
								this->question = 4;
							}
							this->container->game1->setMouseChildren(false);
							this->container->game1->setMouseEnabled(false);
							this->container->game2->setMouseChildren(false);
							this->container->game2->setMouseEnabled(false);
							this->container->game3->setMouseChildren(false);
							this->container->game3->setMouseEnabled(false);
							this->container->game1->setAlpha(0.5);
							this->container->game2->setAlpha(0.5);
							this->container->game3->setAlpha(0.5);
						}
					}
					else if (this->container->game1->currentFrame < 4)
					{
						if (this->container->game1DeleteSlot->currentFrame == 3)
						{
							this->container->game1DeleteSlot->gotoAndStop(1);
						}
					}
					if (parent->getName() == "game2")
					{
						if (this->container->game2DeleteSlot->currentFrame == 3)
						{
							this->container->game2DeleteSlot->gotoAndStop(2);
							if (this->page == 3)
							{
								this->question = 2;
							}
							else if (this->page == 4)
							{
								this->question = 5;
							}
							this->container->game1->setMouseChildren(false);
							this->container->game1->setMouseEnabled(false);
							this->container->game2->setMouseChildren(false);
							this->container->game2->setMouseEnabled(false);
							this->container->game3->setMouseChildren(false);
							this->container->game3->setMouseEnabled(false);
							this->container->game1->setAlpha(0.5);
							this->container->game2->setAlpha(0.5);
							this->container->game3->setAlpha(0.5);
						}
					}
					else if (this->container->game2->currentFrame < 4)
					{
						if (this->container->game2DeleteSlot->currentFrame == 3)
						{
							this->container->game2DeleteSlot->gotoAndStop(1);
						}
					}
					if (parent->getName() == "game3")
					{
						if (this->container->game3DeleteSlot->currentFrame == 3)
						{
							this->container->game3DeleteSlot->gotoAndStop(2);
							if (this->page == 3)
							{
								this->question = 3;
							}
							else if (this->page == 4)
							{
								this->question = 6;
							}
							this->container->game1->setMouseChildren(false);
							this->container->game1->setMouseEnabled(false);
							this->container->game2->setMouseChildren(false);
							this->container->game2->setMouseEnabled(false);
							this->container->game3->setMouseChildren(false);
							this->container->game3->setMouseEnabled(false);
							this->container->game1->setAlpha(0.5);
							this->container->game2->setAlpha(0.5);
							this->container->game3->setAlpha(0.5);
						}
					}
					else if (this->container->game3->currentFrame < 4)
					{
						if (this->container->game3DeleteSlot->currentFrame == 3)
						{
							this->container->game3DeleteSlot->gotoAndStop(1);
						}
					}
				}
				if (this->container->question)
				{
					if (targetName == "yesCase")
					{
						MCCase * scase = ISTYPE(MCCase, event->target);
						MovieClipSub  * parent = scase->getParentMC<MovieClipSub>();
						if (parent->currentFrame == 3)
						{
							parent->gotoAndStop(2);
							if (this->question == 1 || this->question == 4)
							{
								this->container->game1->gotoAndStop(4);
								this->container->game1NewGame1Case->stop();
								this->container->game1NewGame1Case->setMouseEnabled(true);
								if (this->question == 1)
								{
									Main::mainClass->saveBoxClass->setValue(1, "haveSave", false);
								}
								else if (this->question == 4)
								{
									Main::mainClass->saveBoxClass->setValue(4, "haveSave", false);
									//Main::mainClass->IDIClass.removeData(4);
								}
							}
							else if (this->question == 2 || this->question == 5)
							{
								this->container->game2->gotoAndStop(4);
								this->container->game2NewGame2Case->stop();
								this->container->game2NewGame2Case->setMouseEnabled(true);
								if (this->question == 2)
								{
									Main::mainClass->saveBoxClass->setValue(2, "haveSave", false);
								}
								else if (this->question == 5)
								{
									Main::mainClass->saveBoxClass->setValue(5, "haveSave", false);
									// Main::mainClass->IDIClass.removeData(5);
								}
							}
							else if (this->question == 3 || this->question == 6)
							{
								this->container->game3->gotoAndStop(4);
								this->container->game3NewGame3Case->stop();
								this->container->game3NewGame3Case->setMouseEnabled(true);
								if (this->question == 3)
								{
									Main::mainClass->saveBoxClass->setValue(3, "haveSave", false);
								}
								else if (this->question == 6)
								{
									Main::mainClass->saveBoxClass->setValue(6, "haveSave", false);
									//Main::mainClass->IDIClass.removeData(6);
								}
							}
							else if (this->question == 11 || this->question == 12 || this->question == 13)
							{
								if (this->question == 11)
								{
									Main::mainClass->saveBoxClass->synchronizationLocalToSite(1);
									this->container->game1SyncSlot->gotoAndStop(7);
								}
								else if (this->question == 12)
								{
									Main::mainClass->saveBoxClass->synchronizationLocalToSite(2);
									this->container->game2SyncSlot->gotoAndStop(7);
								}
								else if (this->question == 13)
								{
									Main::mainClass->saveBoxClass->synchronizationLocalToSite(3);
									this->container->game3SyncSlot->gotoAndStop(7);
								}
							}
							this->question = -1;
						}
					}
					else if (this->container->questionBtnYes->currentFrame == 3)
					{
						this->container->questionBtnYes->gotoAndStop(2);
					}
					if (targetName == "noCase")
					{
						MCCase * scase = ISTYPE(MCCase, event->target);
						MovieClipSub  * parent = scase->getParentMC<MovieClipSub>();
						if (parent->currentFrame == 3)
						{
							parent->gotoAndStop(2);
							this->question = -1;
						}
					}
					else if (this->container->questionBtnNo->currentFrame == 3)
					{
						this->container->questionBtnNo->gotoAndStop(2);
					}
				}
			}
		}
    }// end function

    void StartMenu::autoguidersButtons()  
    {
        //this->autoguidesMouse_pt = cocos2d::Point(this->mouseX, this->mouseY);
        //this->autoguidesObject = NULL;
        //if (this->page == 1)
        //{
        //    this->autoguidesObject_pt = this->container->start->localToGlobal(this->container->startStartCase->getPosition());
        //    this->autoguidesObjectWidth = this->container->startStartCase->getWidth() / 2;
        //    this->autoguidesObjectHeight = this->container->startStartCase->getHeight() / 2;
        //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //    {
        //        this->autoguidesObject = this->container->startStartCase;
        //    }
        //    if (!this->autoguidesObject)
        //    {
        //        this->autoguidesObject_pt = this->container->credits->localToGlobal( this->container->creditsCreditsCase->getPosition());
        //        this->autoguidesObjectWidth = this->container->creditsCreditsCase->getWidth() / 2;
        //        this->autoguidesObjectHeight = this->container->creditsCreditsCase.height / 2;
        //        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //        {
        //            this->autoguidesObject = this->container->creditsCreditsCase;
        //        }
        //    }
        //}
        //else if (this->page == 2)
        //{
        //    this->autoguidesObject_pt = this->container->saveTypeLocalSave->localToGlobal( this->container->saveTypeLocalSaveLocalSaveCase->getPosition());
        //    this->autoguidesObjectWidth = this->container->saveTypeLocalSaveLocalSaveCase->getWidth() / 2;
        //    this->autoguidesObjectHeight = this->container->saveTypeLocalSaveLocalSaveCase.height / 2;
        //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //    {
        //        this->autoguidesObject = this->container->saveTypeLocalSaveLocalSaveCase;
        //    }
        //    if (!this->autoguidesObject)
        //    {
        //        this->autoguidesObject_pt = this->container->saveTypeOnlineSave->localToGlobal( this->container->saveTypeOnlineSaveOnlineSaveCase->getPosition());
        //        this->autoguidesObjectWidth = this->container->saveTypeOnlineSaveOnlineSaveCase->getWidth() / 2;
        //        this->autoguidesObjectHeight = this->container->saveTypeOnlineSaveOnlineSaveCase.height / 2;
        //        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //        {
        //            this->autoguidesObject = this->container->saveTypeOnlineSaveOnlineSaveCase;
        //        }
        //    }
        //}
        //else if (this->page == 3)
        //{
        //    if (this->container->game1->currentFrame < 4)
        //    {
        //        this->autoguidesObject_pt = this->container->game1->localToGlobal( this->container->game1Game1Case->getPosition());
        //        this->autoguidesObjectWidth = this->container->game1->game1Case->getWidth() / 2;
        //        this->autoguidesObjectHeight = this->container->game1->game1Case.height / 2;
        //        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //        {
        //            this->autoguidesObject = this->container->game1->game1Case;
        //        }
        //        if (!this->autoguidesObject)
        //        {
        //            this->autoguidesObject_pt = this->container->game1DeleteSlot->localToGlobal( this->container->game1DeleteSlotDeleteSlotCase->getPosition());
        //            this->autoguidesObjectWidth = this->container->game1DeleteSlotDeleteSlotCase->getWidth() / 2;
        //            this->autoguidesObjectHeight = this->container->game1DeleteSlotDeleteSlotCase.height / 2;
        //            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //            {
        //                this->autoguidesObject = this->container->game1DeleteSlotDeleteSlotCase;
        //            }
        //        }
        //    }
        //    else
        //    {
        //        this->autoguidesObject_pt = this->container->game1->localToGlobal(this->container->game1NewGame1Case->getPosition());
        //        this->autoguidesObjectWidth = this->container->game1->newGame1Case->getWidth() / 2;
        //        this->autoguidesObjectHeight = this->container->game1->newGame1Case.height / 2;
        //        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //        {
        //            this->autoguidesObject = this->container->game1->newGame1Case;
        //        }
        //    }
        //    if (this->container->game2->currentFrame < 4)
        //    {
        //        if (!this->autoguidesObject)
        //        {
        //            this->autoguidesObject_pt = this->container->game2->localToGlobal(this->container->game2Game2Case->getPosition());
        //            this->autoguidesObjectWidth = this->container->game2->game2Case->getWidth() / 2;
        //            this->autoguidesObjectHeight = this->container->game2->game2Case.height / 2;
        //            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //            {
        //                this->autoguidesObject = this->container->game2->game2Case;
        //            }
        //        }
        //        if (!this->autoguidesObject)
        //        {
        //            this->autoguidesObject_pt = this->container->game2DeleteSlot->localToGlobal(this->container->game2DeleteSlotDeleteSlotCase->getPosition());
        //            this->autoguidesObjectWidth = this->container->game2DeleteSlot->deleteSlotCase->getWidth() / 2;
        //            this->autoguidesObjectHeight = this->container->game2DeleteSlot->deleteSlotCase.height / 2;
        //            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //            {
        //                this->autoguidesObject = this->container->game2DeleteSlot->deleteSlotCase;
        //            }
        //        }
        //    }
        //    else if (!this->autoguidesObject)
        //    {
        //        this->autoguidesObject_pt = this->container->game2->localToGlobal(this->container->game2NewGame2Case->getPosition());
        //        this->autoguidesObjectWidth = this->container->game2NewGame2Case->getWidth() / 2;
        //        this->autoguidesObjectHeight = this->container->game2NewGame2Case.height / 2;
        //        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //        {
        //            this->autoguidesObject = this->container->game2NewGame2Case;
        //        }
        //    }
        //    if (this->container->game3->currentFrame < 4)
        //    {
        //        if (!this->autoguidesObject)
        //        {
        //            this->autoguidesObject_pt = this->container->game3->localToGlobal(this->container->game3Game3Case->getPosition());
        //            this->autoguidesObjectWidth = this->container->game3->game3Case->getWidth() / 2;
        //            this->autoguidesObjectHeight = this->container->game3->game3Case.height / 2;
        //            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //            {
        //                this->autoguidesObject = this->container->game3->game3Case;
        //            }
        //        }
        //        if (!this->autoguidesObject)
        //        {
        //            this->autoguidesObject_pt = this->container->game3DeleteSlot->localToGlobal(this->container->game3DeleteSlotDeleteSlotCase->getPosition());
        //            this->autoguidesObjectWidth = this->container->game3DeleteSlot->deleteSlotCase->getWidth() / 2;
        //            this->autoguidesObjectHeight = this->container->game3DeleteSlot->deleteSlotCase.height / 2;
        //            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //            {
        //                this->autoguidesObject = this->container->game3DeleteSlot->deleteSlotCase;
        //            }
        //        }
        //    }
        //    else if (!this->autoguidesObject)
        //    {
        //        this->autoguidesObject_pt = this->container->game3->localToGlobal(this->container->game3NewGame3Case->getPosition());
        //        this->autoguidesObjectWidth = this->container->game3->newGame3Case->getWidth() / 2;
        //        this->autoguidesObjectHeight = this->container->game3->newGame3Case.height / 2;
        //        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //        {
        //            this->autoguidesObject = this->container->game3->newGame3Case;
        //        }
        //    }
        //    if (this->container->question)
        //    {
        //        if (!this->autoguidesObject)
        //        {
        //            this->autoguidesObject_pt = this->container->questionBtnYes->localToGlobal(this->container->questionBtnYesYesCase->getPosition());
        //            this->autoguidesObjectWidth = this->container->questionBtnYes->yesCase->getWidth() / 2;
        //            this->autoguidesObjectHeight = this->container->questionBtnYes->yesCase.height / 2;
        //            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //            {
        //                this->autoguidesObject = this->container->questionBtnYes->yesCase;
        //            }
        //        }
        //        if (!this->autoguidesObject)
        //        {
        //            this->autoguidesObject_pt = this->container->questionBtnNo->localToGlobal(this->container->questionBtnNoNoCase->getPosition());
        //            this->autoguidesObjectWidth = this->container->questionBtnNo->noCase->getWidth() / 2;
        //            this->autoguidesObjectHeight = this->container->questionBtnNo->noCase.height / 2;
        //            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //            {
        //                this->autoguidesObject = this->container->questionBtnNo->noCase;
        //            }
        //        }
        //    }
        //}
        //if (!this->autoguidesObject)
        //{
        //    if (this->container->back->visible)
        //    {
        //        this->autoguidesObject_pt = this->container->back->localToGlobal(this->container->back->backCase.x, this->container->back->backCase.y));
        //        this->autoguidesObjectWidth = this->container->backBackCase->getWidth() / 2;
        //        this->autoguidesObjectHeight = this->container->backBackCase.height / 2;
        //        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        //            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        //            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //        {
        //            this->autoguidesObject = this->container->back->backCase;
        //        }
        //    }
        //}
        //if (this->autoguidesObject)
        //{
        //    tempObject = new Object();
        //    tempObject.target = this->autoguidesObject;
        //    this->mouseMoveHandler(tempObject);
        //}
        return;
    }// end function
	 

    //void StartMenu::reInit(event:Event)  
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    return;
    //}// end function

}
 
