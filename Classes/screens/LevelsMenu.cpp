
#include "MainClass.h"
#include "DifficultyLevel.h"
#include "Upgrades.h"
#include "Achievements.h"
#include "LevelsMenu.h"

namespace screens {
    NewLevel_mc::NewLevel_mc() : MovieClip("screen/", "NewLevel_mc", "NewLevel_mc") {
    }

    Level_mc::Level_mc() : MovieClip("screen/", "level", "level") {
        this->levelCase = this->createCase("levelCase", true);
        this->star1 = this->createMovieClipSub("star1", true);
        this->star2 = this->createMovieClipSub("star2", true);
        this->star3 = this->createMovieClipSub("star3", true);
        this->towerEffect = this->createMovieClipSub("towerEffect", true);
        this->wreath = this->createMovieClipSub("wreath", true);
    };

    LevelsMenu_mc::LevelsMenu_mc() : MovieClip("screen/", "LevelsMenu_mc", "LevelsMenu_mc") {
        SET_NODETYPENAME();
        this->level1 = (Level_mc *) this->createMovieClip("level1", new Level_mc());
        this->level2 = (Level_mc *) this->createMovieClip("level2", new Level_mc());
        this->level3 = (Level_mc *) this->createMovieClip("level3", new Level_mc());
        this->level4 = (Level_mc *) this->createMovieClip("level4", new Level_mc());
        this->level5 = (Level_mc *) this->createMovieClip("level5", new Level_mc());
        this->level6 = (Level_mc *) this->createMovieClip("level6", new Level_mc());
        this->level7 = (Level_mc *) this->createMovieClip("level7", new Level_mc());
        this->level8 = (Level_mc *) this->createMovieClip("level8", new Level_mc());
        this->level9 = (Level_mc *) this->createMovieClip("level9", new Level_mc());
        this->level10 = (Level_mc *) this->createMovieClip("level10", new Level_mc());
        this->level11 = (Level_mc *) this->createMovieClip("level11", new Level_mc());
        this->level12 = (Level_mc *) this->createMovieClip("level12", new Level_mc());
        this->level13 = (Level_mc *) this->createMovieClip("level13", new Level_mc());
        this->level14 = (Level_mc *) this->createMovieClip("level14", new Level_mc());
        this->level15 = (Level_mc *) this->createMovieClip("level15", new Level_mc());
        this->road = this->createMovieClipSub("road");

        return;
    }// end function

    LevelsMenu::LevelsMenu() :
            container(0), frameCounter(0), newLevel(0), newLevelGr(0), roadOff(false),
            newStarsForLevel(0), mouseMoveTarget(0), mouseDownTarget(0), openLevel(0),
            upgradesClass(0), achievementsClass(0), firstMusicPlay(0),
            difficultyLevel(0) //, encyclopediaClass(0),
    {
        //this->listOfLevels = [];
        //this->listOfAnimation = [];
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool LevelsMenu::init() {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        if (Main::mainClass->saveBoxClass->getIntValue("newLevel") > 0) {
            this->newLevel = Main::mainClass->saveBoxClass->getIntValue("newLevel");
            this->roadOff = false;
        }
        if (Main::mainClass->saveBoxClass->getIntValue("newStarsForLevel") > 0) {
            this->newStarsForLevel = Main::mainClass->saveBoxClass->getIntValue("newStarsForLevel");
        }
        this->container = new LevelsMenu_mc();
        this->addChild(this->container);
        //this->printNodePos(this->container);
        cocos2d::Size size = this->container->getSprite("Layer 1")->getContentSize();
        float sy = Main::SCREEN_HEIGHT / size.height;
//        this->container->setScaleY(sy);
//        this->container->setPosition(0, Main::SCREEN_HEIGHT);
        this->container->setMouseDrag(true);
        this->container->setMouseEnabled(true);
        this->container->enableMouseHandler(true);
        //this->container->setPosition(0, Main::LEVEL_MAP_HEIGHT);
        this->container->maxDragPos = Vec2(0, 0);
        this->container->minDragPos = Vec2(0, Main::SCREEN_HEIGHT-Main::LEVEL_MAP_HEIGHT);
		this->container->display->setPosition(0, Main::LEVEL_MAP_HEIGHT);
		this->container->setName("LevelsMenu_mc");
		//this->printNodePos(this->container);


		MovieClip * btnSM = new MovieClip("screen/", "sound_mc", "LevelsMenu_mc");
		this->addChild(btnSM);
		btnSM->setPosition(Vec2(0, Main::SCREEN_HEIGHT));
		this->container->btnMusic = btnSM->createMovieClipSub("btnMusic");
		this->container->btnMusicMusicCase = this->container->btnMusic->createCase("musicCase");
		this->container->btnSound = btnSM->createMovieClipSub("btnSound");
		this->container->btnSoundSoundCase = this->container->btnSound->createCase("soundCase");
		
		this->container->back = new MovieClip("screen/", "back", "back");// this->createMovieClipSub("back");
		this->addChild(this->container->back);
		this->container->backBackCase = this->container->back->createCase("backCase");
 		this->container->back->setPosition(26, Main::SCREEN_HEIGHT - 15);

		MovieClip * upbook = new MovieClip("screen/", "upgrades_mc", "LevelsMenu_mc");
		this->addChild(upbook);
		upbook->setPosition(Vec2(0, Main::LEVEL_MAP_HEIGHT));

		this->container->achieves = upbook->createMovieClipSub("achieves");
		this->container->achievesAchievesCase1 = this->container->achieves->createCase("achievesCase1");
		this->container->achievesAchievesCase2 = this->container->achieves->createCase("achievesCase2");
		this->container->book = upbook->createMovieClipSub("book");
		this->container->bookBookCase1 = this->container->book->createCase("bookCase1");
		this->container->bookBookCase2 = this->container->book->createCase("bookCase2");
		this->container->freeStars = upbook->createMovieClipSub("freeStars");
		this->container->freeStarsCont = this->container->freeStars->createMovieClipSub("cont");
		this->container->freeStarsContStarsTXT = this->container->freeStarsCont->createText("starsTXT");

		this->container->upgrades = upbook->createMovieClipSub("upgrades");
		this->container->upgradesUpgradesCase1 = this->container->upgrades->createCase("upgradesCase1");
		this->container->upgradesUpgradesCase2 = this->container->upgrades->createCase("upgradesCase2");
		this->container->upgradesFireCont = this->container->upgrades->createMovieClipSub("fireCont", true);
		this->container->wavesAnimation = this->container->createMovieClipSub("wavesAnimation");

        this->container->stop();
        this->container->back->stop();
        this->container->upgrades->stop();
        this->container->book->stop();
        this->container->achieves->stop();
        this->container->backBackCase->setMouseEnabled(true);
        this->container->upgradesUpgradesCase1->setMouseEnabled(true);
        this->container->upgradesUpgradesCase2->setMouseEnabled(true);
        this->container->bookBookCase1->setMouseEnabled(true);
        this->container->bookBookCase2->setMouseEnabled(true);
        this->container->achievesAchievesCase1->setMouseEnabled(true);
        this->container->achievesAchievesCase2->setMouseEnabled(true);
        this->container->wavesAnimation->stop();
        this->i = 0;
        const std::vector<Slot *> &slots = this->container->wavesAnimation->arm->getSlots();
        for (int i = 0; i < slots.size(); i++) {
            MovieClipSub *wave = this->container->wavesAnimation->createMovieClipSub(
                    slots.at(i)->getName());
            wave->gotoAndStop(((int) (std::random() * (wave->totalFrames - 1) + 0.5) + 1));
            this->listOfAnimation.push(wave);
        }
        this->listOfLevels.push(this->container->level1);
        this->listOfLevels.push(this->container->level2);
        this->listOfLevels.push(this->container->level3);
        this->listOfLevels.push(this->container->level4);
        this->listOfLevels.push(this->container->level5);
        this->listOfLevels.push(this->container->level6);
        this->listOfLevels.push(this->container->level7);
        this->listOfLevels.push(this->container->level8);
        this->listOfLevels.push(this->container->level9);
        this->listOfLevels.push(this->container->level10);
        this->listOfLevels.push(this->container->level11);
        this->listOfLevels.push(this->container->level12);
        this->listOfLevels.push(this->container->level13);
        this->listOfLevels.push(this->container->level14);
        this->listOfLevels.push(this->container->level15);
        this->preparationLevels();
        this->container->btnMusic->stop();
        this->container->btnSound->stop();
        this->container->btnMusicMusicCase->setMouseEnabled(true);
        this->container->btnSoundSoundCase->setMouseEnabled(true);
        this->container->freeStars->stop();
        this->container->freeStarsCont->stop();
        this->container->freeStars->setMouseChildren(false);
        this->container->freeStars->setMouseEnabled(false);
        if (Main::mainClass->saveBoxClass->getIntValue("stars") == 0) {
            this->container->freeStars->setVisible(false);
        }
        if (AudioUtil::musicOn)
            this->container->btnMusic->gotoAndStop(1);
        else
            this->container->btnMusic->gotoAndStop(4);

        if (AudioUtil::soundOn)
            this->container->btnSound->gotoAndStop(1);
        else
            this->container->btnSound->gotoAndStop(4);

        this->container->setMouseEnabled(true);
        if (!Main::mainClass->saveBoxClass->getBoolValue("difficultyLevel")) {
            this->container->setMouseChildren(false);
            this->container->setMouseEnabled(false);
        }
        //if (Main::mainClass->saveBoxClass.gameSave.data.training_9 == 1)
        //{
        //    Main::mainClass->saveBoxClass.gameSave.data.training_9 = 2;
        //    this->training_9 = new Training_9();
        //    this->addChild(this->training_9);
        //}
        //if (Main::mainClass->saveBoxClass.gameSave.data.training_91 > 0)
        //{
        //    training_91 = new Training_91(Main::mainClass->saveBoxClass.gameSave.data.training_91);
        //    this->addChild(training_91);
        //    Main::mainClass->saveBoxClass.gameSave.data.training_91 = -1;
        //}
        return true;
    }// end function

    void LevelsMenu::enterFrameHandler(float dt) {
        if (this->frameCounter < 30)
            this->frameCounter++;
        else
            this->frameCounter = 1;
        if (!this->firstMusicPlay) {
            if (this->frameCounter == 8) {
                if (!Main::mainClass->saveBoxClass->getBoolValue("difficultyLevel")) {
                    this->difficultyLevel = new DifficultyLevel();
                    this->addChild(this->difficultyLevel);
                    this->difficultyLevel->init();
                    this->difficultyLevel->setPosition(Vec2(0, 0));
                    this->printNodePos(this->difficultyLevel);
                } else {
                    this->firstMusicPlay = true;
                    if (AudioUtil::nowMusic != "Music_menu_main.mp3")
                        AudioUtil::playMusic("Music_menu_main.mp3");
                }
            }
        }
        if (this->container->freeStars->isVisible()) {
            if (this->container->freeStars->currentFrame <
                this->container->freeStars->totalFrames) {
                this->container->freeStars->tryPlay();//gotoAndStop((this->container->freeStars->currentFrame + 1));
            } else {
                this->container->freeStars->gotoAndStop(11);
            }
            if (this->container->freeStarsCont->currentFrame <
                this->container->freeStarsCont->totalFrames) {
                this->container->freeStarsCont->tryPlay();//gotoAndStop((this->container->freeStarsCont->currentFrame + 1));
            } else {
                this->container->freeStarsCont->gotoAndStop(1);
            }
            std::setText(this->container->freeStarsContStarsTXT,
                         Main::mainClass->saveBoxClass->getIntValue("stars"));
            //this->container->freeStarsCont->starsTXT.setTextFormat(Main::mainClass->boldTextFormat);
        }
        if (this->newLevel > 0 && this->container->mouseEnabled) {
            this->openNewLevel();
        }
        if (this->newStarsForLevel > 0) {
            this->openNewStarsForLevel();
        }
        if (this->container->upgrades->currentFrame != this->container->upgrades->totalFrames) {
            if (this->mouseMoveTarget == this->container->upgrades) {
                if (this->container->upgrades->currentFrame < 6) {
                    this->container->upgrades->gotoAndStop(
                            (this->container->upgrades->currentFrame + 1));
                }
            } else if (this->container->upgrades->currentFrame > 1) {
                if (this->container->upgrades->currentFrame > 6) {
                    this->container->upgrades->gotoAndStop(6);
                } else {
                    this->container->upgrades->gotoAndStop(
                            (this->container->upgrades->currentFrame - 1));
                }
            }
            if (this->container->upgradesFireCont->isReady) {
                if (this->container->upgradesFireCont->currentFrame <
                    this->container->upgradesFireCont->totalFrames) {
                    this->container->upgradesFireCont->gotoAndStop(
                            (this->container->upgradesFireCont->currentFrame + 1));
                } else {
                    this->container->upgradesFireCont->gotoAndStop(1);
                }
            }
        }
        if (this->container->book->currentFrame != this->container->book->totalFrames) {
            if (this->mouseMoveTarget == this->container->book) {
                if (this->container->book->currentFrame <
                    (this->container->book->totalFrames - 1)) {
                    this->container->book->gotoAndStop((this->container->book->currentFrame + 1));
                }
            } else if (this->container->book->currentFrame > 1) {
                this->container->book->gotoAndStop((this->container->book->currentFrame - 1));
            }
        }
        if (this->container->achieves->currentFrame != this->container->achieves->totalFrames) {
            if (this->mouseMoveTarget == this->container->achieves) {
                if (this->container->achieves->currentFrame <
                    (this->container->achieves->totalFrames - 1)) {
                    this->container->achieves->gotoAndStop(
                            (this->container->achieves->currentFrame + 1));
                }
            } else if (this->container->achieves->currentFrame > 1) {
                this->container->achieves->gotoAndStop(
                        (this->container->achieves->currentFrame - 1));
            }
        }
        if (this->frameCounter % 2)//(this->frameCounter / 2 is int)
        {
            this->i = 0;
            while (this->i < this->listOfAnimation.size()) {
                this->listOfAnimation[this->i]->tryPlay();
                //if (this->listOfAnimation[this->i]->currentFrame < this->listOfAnimation[this->i]->totalFrames)
                //            {
                //                this->listOfAnimation[this->i]->tryPlay();//gotoAndStop((this->listOfAnimation[this->i]->currentFrame + 1));
                //            }
                //            else
                //            {
                //                this->listOfAnimation[this->i]->gotoAndStop(1);
                //            }
                i++;
            }
        }
        return;
    }// end function
    bool LevelsMenu::preCheckEventTarget(std::MouseEvent *event,
                                         EventMouse::MouseEventType _mouseEventType) {
        if(useNodeEvent)return false;
        return false;
    }

    void LevelsMenu::mouseMoveHandler(cocos2d::EventMouse *e) {
        Main::mouseX = e->getCursorX();
        Main::mouseY = e->getCursorY();
        if (!globalNode)EventNode::mouseMoveHandler(e);
        cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
        if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
        std::MouseEvent me(e);
        if (!useNodeEvent) {
            me = std::buildMouseEvent(e);
        }else if(globalNode && globalNode==this){
            if (!std::hitTest(this, e))return;
        }
        std::MouseEvent *event = &me;
        if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_MOVE))return;
        if (!event->currentTargets.size())
            event->currentTargets.push(this);
        //return;
        while (event->hasNext()) {
            string targetName = event->target->getName();
            if (event->target == EventNode::beginTouchNode &&(EventNode::beginTouchPos.x!= Main::mouseX|| EventNode::beginTouchPos.y != Main::mouseY)) {
                EventNode *en = ISTYPE(EventNode, event->target);
				if (this->container->isMouseDrag()   ) {
					Vec2 stpos = this->container->getPosition();
					Vec2 endPos = stpos + Vec2(Main::mouseX, Main::mouseY) - EventNode::beginTouchPos;
					EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
					if (endPos.x < this->container->minDragPos.x) {
						endPos.x = this->container->minDragPos.x;
					}
					else if (endPos.x > this->container->maxDragPos.x) {
						endPos.x = this->container->maxDragPos.x;
					}
					if (endPos.y < this->container->minDragPos.y) {
						endPos.y = this->container->minDragPos.y;
					}
					else if (endPos.y > this->container->maxDragPos.y) {
						endPos.y = this->container->maxDragPos.y;
					}
					this->container->setPosition(endPos);
				}
            }
            if (this->mouseMoveTarget)
                this->mouseMoveTarget = NULL;
            if (targetName == "musicCase") {
                if (this->container->btnMusic->currentFrame == 1 ||
                    this->container->btnMusic->currentFrame == 4) {
                    this->container->btnMusic->gotoAndStop(
                            (this->container->btnMusic->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
                }
            } else if (this->container->btnMusic->currentFrame == 2 ||
                       this->container->btnMusic->currentFrame == 5) {
                this->container->btnMusic->gotoAndStop(
                        (this->container->btnMusic->currentFrame - 1));
            }
            if (targetName == "soundCase") {
                if (this->container->btnSound->currentFrame == 1 ||
                    this->container->btnSound->currentFrame == 4) {
                    this->container->btnSound->gotoAndStop(
                            (this->container->btnSound->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
                }
            } else if (this->container->btnSound->currentFrame == 2 ||
                       this->container->btnSound->currentFrame == 5) {
                this->container->btnSound->gotoAndStop(
                        (this->container->btnSound->currentFrame - 1));
            }
            if (targetName == "backCase") {
                this->mouseMoveTarget = this->container->back;// event->target->getParent()->getParent();
                if (this->container->back->currentFrame == 1) {
                    this->container->back->gotoAndStop(2);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
                }
            } else if (this->container->back->currentFrame == 2) {
                this->container->back->gotoAndStop(1);
            }
            if (targetName == "upgradesCase1" || targetName == "upgradesCase2") {
                this->mouseMoveTarget = this->container->upgrades;//  param1->target->parent;
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
            if (targetName == "bookCase1" || targetName == "bookCase2") {
                this->mouseMoveTarget = this->container->book;//  param1->target->parent;
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
            if (targetName == "achievesCase1" || targetName == "achievesCase2") {
                this->mouseMoveTarget = this->container->achieves;// param1->target->parent;
                AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
            }
            if (targetName == "levelCase") {
                Node *n = event->target->getParent()->getParent()->getParent();
                Level_mc *level = ISTYPE(Level_mc, n);
                if (level->currentFrame == 1 || level->currentFrame == 5 ||
                    level->currentFrame == 8) {
                    level->gotoAndStop((level->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
                }
            } else {
                if (this->container->level1->currentFrame == 2 ||
                    this->container->level1->currentFrame == 6 ||
                    this->container->level1->currentFrame == 9) {
                    this->container->level1->gotoAndStop(
                            (this->container->level1->currentFrame - 1));
                }
                if (this->container->level2->currentFrame == 2 ||
                    this->container->level2->currentFrame == 6 ||
                    this->container->level2->currentFrame == 9) {
                    this->container->level2->gotoAndStop(
                            (this->container->level2->currentFrame - 1));
                }
                if (this->container->level3->currentFrame == 2 ||
                    this->container->level3->currentFrame == 6 ||
                    this->container->level3->currentFrame == 9) {
                    this->container->level3->gotoAndStop(
                            (this->container->level3->currentFrame - 1));
                }
                if (this->container->level4->currentFrame == 2 ||
                    this->container->level4->currentFrame == 6 ||
                    this->container->level4->currentFrame == 9) {
                    this->container->level4->gotoAndStop(
                            (this->container->level4->currentFrame - 1));
                }
                if (this->container->level5->currentFrame == 2 ||
                    this->container->level5->currentFrame == 6 ||
                    this->container->level5->currentFrame == 9) {
                    this->container->level5->gotoAndStop(
                            (this->container->level5->currentFrame - 1));
                }
                if (this->container->level6->currentFrame == 2 ||
                    this->container->level6->currentFrame == 6 ||
                    this->container->level6->currentFrame == 9) {
                    this->container->level6->gotoAndStop(
                            (this->container->level6->currentFrame - 1));
                }
                if (this->container->level7->currentFrame == 2 ||
                    this->container->level7->currentFrame == 6 ||
                    this->container->level7->currentFrame == 9) {
                    this->container->level7->gotoAndStop(
                            (this->container->level7->currentFrame - 1));
                }
                if (this->container->level8->currentFrame == 2 ||
                    this->container->level8->currentFrame == 6 ||
                    this->container->level8->currentFrame == 9) {
                    this->container->level8->gotoAndStop(
                            (this->container->level8->currentFrame - 1));
                }
                if (this->container->level9->currentFrame == 2 ||
                    this->container->level9->currentFrame == 6 ||
                    this->container->level9->currentFrame == 9) {
                    this->container->level9->gotoAndStop(
                            (this->container->level9->currentFrame - 1));
                }
                if (this->container->level10->currentFrame == 2 ||
                    this->container->level10->currentFrame == 6 ||
                    this->container->level10->currentFrame == 9) {
                    this->container->level10->gotoAndStop(
                            (this->container->level10->currentFrame - 1));
                }
                if (this->container->level11->currentFrame == 2 ||
                    this->container->level11->currentFrame == 6 ||
                    this->container->level11->currentFrame == 9) {
                    this->container->level11->gotoAndStop(
                            (this->container->level11->currentFrame - 1));
                }
                if (this->container->level12->currentFrame == 2 ||
                    this->container->level12->currentFrame == 6 ||
                    this->container->level12->currentFrame == 9) {
                    this->container->level12->gotoAndStop(
                            (this->container->level12->currentFrame - 1));
                }
                if (this->container->level13->currentFrame == 2 ||
                    this->container->level13->currentFrame == 6 ||
                    this->container->level13->currentFrame == 9) {
                    this->container->level13->gotoAndStop(
                            (this->container->level13->currentFrame - 1));
                }
                if (this->container->level14->currentFrame == 2 ||
                    this->container->level14->currentFrame == 6 ||
                    this->container->level14->currentFrame == 9) {
                    this->container->level14->gotoAndStop(
                            (this->container->level14->currentFrame - 1));
                }
                if (this->container->level15->currentFrame == 2 ||
                    this->container->level15->currentFrame == 6 ||
                    this->container->level15->currentFrame == 9) {
                    this->container->level15->gotoAndStop(
                            (this->container->level15->currentFrame - 1));
                }
            }
        }
        return;
    }// end function

    void LevelsMenu::mouseDownHandler(cocos2d::EventMouse *e) {
        if (!globalNode)EventNode::mouseDownHandler(e);
        cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
        if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
        std::MouseEvent me(e);
        if (!useNodeEvent) {
            me = std::buildMouseEvent(e);
        }else if(globalNode && globalNode==this){
            if (!std::hitTest(this, e))return;
        }
        std::MouseEvent *event = &me;
        if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_DOWN))return;
        if (!event->currentTargets.size())
            event->currentTargets.push(this);
        Main::mouseX = e->getCursorX();
        Main::mouseY = e->getCursorY();
        EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
        while (event->hasNext()) {
            string targetName = event->target->getName();
            EventNode::beginTouchNode = event->target;// event->currentTargets.at(0);

            if (this->mouseDownTarget) {
                this->mouseDownTarget = NULL;
            }
            if (targetName == "musicCase") {
                if (this->container->btnMusic->currentFrame == 2 ||
                    this->container->btnMusic->currentFrame == 5) {
                    this->container->btnMusic->gotoAndStop(
                            (this->container->btnMusic->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            } else if (targetName == "soundCase") {
                if (this->container->btnSound->currentFrame == 2 ||
                    this->container->btnSound->currentFrame == 5) {
                    this->container->btnSound->gotoAndStop(
                            (this->container->btnSound->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            } else if (targetName == "backCase") {
                this->mouseDownTarget = event->target->getParent()->getParent();
                if (this->container->back->currentFrame == 2) {
                    this->container->back->gotoAndStop(3);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            } else if (targetName == "upgradesCase1" || targetName == "upgradesCase2") {
                this->mouseDownTarget = event->target->getParent();
                if (this->container->upgrades->currentFrame != 7) {
                    this->container->upgrades->gotoAndStop(7);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            } else if (targetName == "bookCase1" || targetName == "bookCase2") {
                this->mouseDownTarget = event->target->getParent();
                if (this->container->book->currentFrame != this->container->book->totalFrames) {
                    this->container->book->gotoAndStop(this->container->book->totalFrames);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            } else if (targetName == "achievesCase1" || targetName == "achievesCase2") {
                this->mouseDownTarget = event->target->getParent();
                if (this->container->achieves->currentFrame !=
                    this->container->achieves->totalFrames) {
                    this->container->achieves->gotoAndStop(this->container->achieves->totalFrames);
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            } else if (targetName == "levelCase") {
                this->mouseDownTarget = event->target->getParent();
                Node *n = event->target->getParent()->getParent()->getParent();
                Level_mc *level = ISTYPE(Level_mc, n);
                if (level->currentFrame == 2 || level->currentFrame == 6 ||
                    level->currentFrame == 9) {
                    level->gotoAndStop((level->currentFrame + 1));
                    AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
                }
            }
        }
        return;
    }// end function

    void LevelsMenu::mouseUpHandler(cocos2d::EventMouse *e) {
        if (!globalNode)EventNode::mouseUpHandler(e);
        cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
        if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
        std::MouseEvent me(e);
        if (!useNodeEvent) {
            me = std::buildMouseEvent(e);
        }else if(globalNode && globalNode==this){
            if (!std::hitTest(this, e))return;
        }
        std::MouseEvent *event = &me;
        if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_UP))return;
        if (!event->currentTargets.size())
            event->currentTargets.push(this);
        Main::mouseX = e->getCursorX();
        Main::mouseY = e->getCursorY();
        EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
        while (event->hasNext()) {
            string targetName = event->target->getName();
            EventNode::beginTouchNode = event->target;// event->currentTargets.at(0);
            if (this->mouseDownTarget) {
                this->mouseDownTarget = NULL;
            }
            if (targetName == "musicCase") {
                if (this->container->btnMusic->currentFrame == 3 ||
                    this->container->btnMusic->currentFrame == 6) {
                    if (this->container->btnMusic->currentFrame == 3) {
                        this->container->btnMusic->gotoAndStop(5);
                        AudioUtil::musicManage("off");
                    } else if (this->container->btnMusic->currentFrame == 6) {
                        this->container->btnMusic->gotoAndStop(2);
                        AudioUtil::musicManage("on");
                        AudioUtil::playMusic("Music_menu_main.mp3");
                    }
                }
            } else if (this->container->btnMusic->currentFrame == 3 ||
                       this->container->btnMusic->currentFrame == 6) {
                this->container->btnMusic->gotoAndStop(this->container->btnMusic->currentFrame - 2);
            }
            if (targetName == "soundCase") {
                if (this->container->btnSound->currentFrame == 3 ||
                    this->container->btnSound->currentFrame == 6) {
                    if (this->container->btnSound->currentFrame == 3) {
                        this->container->btnSound->gotoAndStop(5);
                        AudioUtil::soundManage("off");
                    } else if (this->container->btnSound->currentFrame == 6) {
                        this->container->btnSound->gotoAndStop(2);
                        AudioUtil::soundManage("on");
                    }
                }
            } else if (this->container->btnSound->currentFrame == 3 ||
                       this->container->btnSound->currentFrame == 6) {
                this->container->btnSound->gotoAndStop(this->container->btnSound->currentFrame - 2);
            }
            if (targetName == "backCase") {
                if (this->container->back->currentFrame == 3) {
                    this->container->back->gotoAndStop(2);
                    Main::mainClass->addNewScreen("StartMenu");
                }
            } else if (this->container->back->currentFrame == 3) {
                this->container->back->gotoAndStop(1);
            }
            if (targetName == "upgradesCase1" || targetName == "upgradesCase2") {
                this->mouseMoveTarget = NULL;
                this->mouseDownTarget = NULL;
                this->container->upgrades->gotoAndStop(7);
                this->upgradesClass = new Upgrades();
                this->addChild(this->upgradesClass);
            } else if (this->container->upgrades->currentFrame ==
                       this->container->upgrades->totalFrames) {
                this->container->upgrades->gotoAndStop(7);
            }
            if (targetName == "bookCase1" || targetName == "bookCase2") {
                this->mouseMoveTarget = NULL;
                this->mouseDownTarget = NULL;
                this->container->book->gotoAndStop(this->container->book->totalFrames);
                //this->container->book->mouseMoveFlag= false;
                //this->encyclopediaClass = new Encyclopedia();
                //this->addChild(this->encyclopediaClass);
            } else if (this->container->book->currentFrame == this->container->book->totalFrames) {
                this->container->book->gotoAndStop((this->container->book->totalFrames - 1));
            }
            if (targetName == "achievesCase1" || targetName == "achievesCase2") {
                this->mouseMoveTarget = NULL;
                this->mouseDownTarget = NULL;
                this->container->achieves->mouseMoveFlag = false;
                this->container->achieves->gotoAndStop(this->container->achieves->totalFrames);
                this->achievementsClass = new Achievements();
                this->addChild(this->achievementsClass);
            } else if (this->container->achieves->currentFrame ==
                       this->container->achieves->totalFrames) {
                this->container->achieves->gotoAndStop(
                        (this->container->achieves->totalFrames - 1));
            }
            if (targetName == "levelCase") {
                Level_mc *level = ISTYPE(Level_mc,
                                         event->target->getParent()->getParent()->getParent());
                if (level->currentFrame == 3 || level->currentFrame == 7 ||
                    level->currentFrame == 10) {
                    if (level->getName() == "level1")
                        this->openLevel = new OpenLevel(1);
                    else if (level->getName() == "level2")
                        this->openLevel = new OpenLevel(2);
                    else if (level->getName() == "level3")
                        this->openLevel = new OpenLevel(3);
                    else if (level->getName() == "level4")
                        this->openLevel = new OpenLevel(4);
                    else if (level->getName() == "level5")
                        this->openLevel = new OpenLevel(5);
                    else if (level->getName() == "level6")
                        this->openLevel = new OpenLevel(6);
                    else if (level->getName() == "level7")
                        this->openLevel = new OpenLevel(7);
                    else if (level->getName() == "level8")
                        this->openLevel = new OpenLevel(8);
                    else if (level->getName() == "level9")
                        this->openLevel = new OpenLevel(9);
                    else if (level->getName() == "level10")
                        this->openLevel = new OpenLevel(10);
                    else if (level->getName() == "level11")
                        this->openLevel = new OpenLevel(11);
                    else if (level->getName() == "level12")
                        this->openLevel = new OpenLevel(12);
                    else if (level->getName() == "level13")
                        this->openLevel = new OpenLevel(13);
                    else if (level->getName() == "level14")
                        this->openLevel = new OpenLevel(14);
                    else if (level->getName() == "level15")
                        this->openLevel = new OpenLevel(15);
                    this->openLevel->init();
                    this->addChild(this->openLevel);
                }
            }
            if (this->container->level1->currentFrame == 3 ||
                this->container->level1->currentFrame == 7 ||
                this->container->level1->currentFrame == 10) {
                this->container->level1->gotoAndStop(this->container->level1->currentFrame - 2);
            }
            if (this->container->level2->currentFrame == 3 ||
                this->container->level2->currentFrame == 7 ||
                this->container->level2->currentFrame == 10) {
                this->container->level2->gotoAndStop(this->container->level2->currentFrame - 2);
            }
            if (this->container->level3->currentFrame == 3 ||
                this->container->level3->currentFrame == 7 ||
                this->container->level3->currentFrame == 10) {
                this->container->level3->gotoAndStop(this->container->level3->currentFrame - 2);
            }
            if (this->container->level4->currentFrame == 3 ||
                this->container->level4->currentFrame == 7 ||
                this->container->level4->currentFrame == 10) {
                this->container->level4->gotoAndStop(this->container->level4->currentFrame - 2);
            }
            if (this->container->level5->currentFrame == 3 ||
                this->container->level5->currentFrame == 7 ||
                this->container->level5->currentFrame == 10) {
                this->container->level5->gotoAndStop(this->container->level5->currentFrame - 2);
            }
            if (this->container->level6->currentFrame == 3 ||
                this->container->level6->currentFrame == 7 ||
                this->container->level6->currentFrame == 10) {
                this->container->level6->gotoAndStop(this->container->level6->currentFrame - 2);
            }
            if (this->container->level7->currentFrame == 3 ||
                this->container->level7->currentFrame == 7 ||
                this->container->level7->currentFrame == 10) {
                this->container->level7->gotoAndStop(this->container->level7->currentFrame - 2);
            }
            if (this->container->level8->currentFrame == 3 ||
                this->container->level8->currentFrame == 7 ||
                this->container->level8->currentFrame == 10) {
                this->container->level8->gotoAndStop(this->container->level8->currentFrame - 2);
            }
            if (this->container->level9->currentFrame == 3 ||
                this->container->level9->currentFrame == 7 ||
                this->container->level9->currentFrame == 10) {
                this->container->level9->gotoAndStop(this->container->level9->currentFrame - 2);
            }
            if (this->container->level10->currentFrame == 3 ||
                this->container->level10->currentFrame == 7 ||
                this->container->level10->currentFrame == 10) {
                this->container->level10->gotoAndStop(this->container->level10->currentFrame - 2);
            }
            if (this->container->level11->currentFrame == 3 ||
                this->container->level11->currentFrame == 7 ||
                this->container->level11->currentFrame == 10) {
                this->container->level11->gotoAndStop(this->container->level11->currentFrame - 2);
            }
            if (this->container->level12->currentFrame == 3 ||
                this->container->level12->currentFrame == 7 ||
                this->container->level12->currentFrame == 10) {
                this->container->level12->gotoAndStop(this->container->level12->currentFrame - 2);
            }
            if (this->container->level13->currentFrame == 3 ||
                this->container->level13->currentFrame == 7 ||
                this->container->level13->currentFrame == 10) {
                this->container->level13->gotoAndStop(this->container->level13->currentFrame - 2);
            }
            if (this->container->level14->currentFrame == 3 ||
                this->container->level14->currentFrame == 7 ||
                this->container->level14->currentFrame == 10) {
                this->container->level14->gotoAndStop(this->container->level14->currentFrame - 2);
            }
            if (this->container->level15->currentFrame == 3 ||
                this->container->level15->currentFrame == 7 ||
                this->container->level15->currentFrame == 10) {
                this->container->level15->gotoAndStop(this->container->level15->currentFrame - 2);
            }
        }
        return;
    }// end function

    void LevelsMenu::preparationLevels() {
        this->container->road->stop();
        if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 14) == 1) {
            if (this->newLevel != 15) {
                this->container->road->gotoAndStop(179);
            }
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 13) == 1) {
            if (this->newLevel != 14) {
                this->container->road->gotoAndStop(164);
            }
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 12) == 1) {
            if (this->newLevel != 13) {
                this->container->road->gotoAndStop(153);
            }
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 11) == 1) {
            if (this->newLevel != 12) {
                this->container->road->gotoAndStop(144);
            }
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 10) == 1) {
            if (this->newLevel != 11) {
                this->container->road->gotoAndStop(136);
            }
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 9) == 1) {
            if (this->newLevel != 10) {
                this->container->road->gotoAndStop(127);
            }
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 8) == 1) {
            if (this->newLevel != 9) {
                this->container->road->gotoAndStop(115);
            }
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 7) == 1) {
            if (this->newLevel != 8) {
                this->container->road->gotoAndStop(104);
            }
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 6) == 1) {
            if (this->newLevel != 7) {
                this->container->road->gotoAndStop(92);
            }
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 5) == 1) {
            if (this->newLevel != 6) {
                this->container->road->gotoAndStop(80);
            }
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 4) == 1) {
            if (this->newLevel != 5) {
                this->container->road->gotoAndStop(66);
            }
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 3) == 1) {
            if (this->newLevel != 4) {
                this->container->road->gotoAndStop(55);
            }
            this->container->level5->setVisible(false);
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 2) == 1) {
            if (this->newLevel != 3) {
                this->container->road->gotoAndStop(41);
            }
            this->container->level4->setVisible(false);
            this->container->level5->setVisible(false);
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 1) == 1) {
            if (this->newLevel != 2) {
                this->container->road->gotoAndStop(26);
            }
            this->container->level3->setVisible(false);
            this->container->level4->setVisible(false);
            this->container->level5->setVisible(false);
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        } else if (Main::mainClass->saveBoxClass->getIntValue("openLevels", 0) == 1) {
            if (this->newLevel != 1) {
                this->container->road->gotoAndStop(12);
            }
            this->container->level2->setVisible(false);
            this->container->level3->setVisible(false);
            this->container->level4->setVisible(false);
            this->container->level5->setVisible(false);
            this->container->level6->setVisible(false);
            this->container->level7->setVisible(false);
            this->container->level8->setVisible(false);
            this->container->level9->setVisible(false);
            this->container->level10->setVisible(false);
            this->container->level11->setVisible(false);
            this->container->level12->setVisible(false);
            this->container->level13->setVisible(false);
            this->container->level14->setVisible(false);
            this->container->level15->setVisible(false);
        }
        this->i = 0;
        while (this->i < 15) {
            if (this->listOfLevels[this->i]->isVisible() && (this->i + 1) != this->newLevel &&
                (this->i + 1) != this->newStarsForLevel) {
                if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", this->i) > 0) {
                    this->listOfLevels[this->i]->gotoAndStop(5);
                    this->listOfLevels[this->i]->wreath->stop();
                    this->listOfLevels[this->i]->star1->stop();
                    this->listOfLevels[this->i]->star2->stop();
                    this->listOfLevels[this->i]->star3->stop();
                    this->listOfLevels[this->i]->wreath->setVisible(false);
                    this->listOfLevels[this->i]->star1->setVisible(false);
                    this->listOfLevels[this->i]->star2->setVisible(false);
                    this->listOfLevels[this->i]->star3->setVisible(false);
                    if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", this->i) >= 1) {
                        this->listOfLevels[this->i]->star1->setVisible(true);
                        this->listOfLevels[this->i]->star1->gotoAndStop(
                                this->listOfLevels[this->i]->star1->totalFrames);
                    }
                    if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", this->i) >= 2) {
                        this->listOfLevels[this->i]->star2->setVisible(true);
                        this->listOfLevels[this->i]->star2->gotoAndStop(
                                this->listOfLevels[this->i]->star2->totalFrames);
                    }
                    if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", this->i) >= 3) {
                        this->listOfLevels[this->i]->star3->setVisible(true);
                        this->listOfLevels[this->i]->star3->gotoAndStop(
                                this->listOfLevels[this->i]->star3->totalFrames);
                    }
                    if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", this->i) == 4) {
                        this->listOfLevels[this->i]->gotoAndStop(8);
                        this->listOfLevels[this->i]->levelCase->stop();
                        this->listOfLevels[this->i]->levelCase->setMouseEnabled(true);
                    }
                }
            } else if ((this->i + 1) == this->newLevel) {
                if (this->newLevel == 1) {
                    this->container->road->gotoAndStop(1);
                } else if (this->newLevel == 2) {
                    this->container->road->gotoAndStop(12);
                } else if (this->newLevel == 3) {
                    this->container->road->gotoAndStop(26);
                } else if (this->newLevel == 4) {
                    this->container->road->gotoAndStop(41);
                } else if (this->newLevel == 5) {
                    this->container->road->gotoAndStop(55);
                } else if (this->newLevel == 6) {
                    this->container->road->gotoAndStop(66);
                } else if (this->newLevel == 7) {
                    this->container->road->gotoAndStop(80);
                } else if (this->newLevel == 8) {
                    this->container->road->gotoAndStop(92);
                } else if (this->newLevel == 9) {
                    this->container->road->gotoAndStop(104);
                } else if (this->newLevel == 10) {
                    this->container->road->gotoAndStop(115);
                } else if (this->newLevel == 11) {
                    this->container->road->gotoAndStop(127);
                } else if (this->newLevel == 12) {
                    this->container->road->gotoAndStop(136);
                } else if (this->newLevel == 13) {
                    this->container->road->gotoAndStop(144);
                } else if (this->newLevel == 14) {
                    this->container->road->gotoAndStop(153);
                } else if (this->newLevel == 15) {
                    this->container->road->gotoAndStop(164);
                }
                this->listOfLevels[this->i]->setVisible(false);
            } else if ((this->i + 1) == this->newStarsForLevel) {
                if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels", this->i) < 4) {
                    this->listOfLevels[this->i]->gotoAndStop(4);
                    this->listOfLevels[this->i]->towerEffect->stop();
                    this->listOfLevels[this->i]->star1->stop();
                    this->listOfLevels[this->i]->star2->stop();
                    this->listOfLevels[this->i]->star3->stop();
                    this->listOfLevels[this->i]->star1->setVisible(false);
                    this->listOfLevels[this->i]->star2->setVisible(false);
                    this->listOfLevels[this->i]->star3->setVisible(false);
                } else {
                    this->listOfLevels[this->i]->gotoAndStop(5);
                    this->listOfLevels[this->i]->wreath->stop();
                    this->listOfLevels[this->i]->star1->stop();
                    this->listOfLevels[this->i]->star2->stop();
                    this->listOfLevels[this->i]->star3->stop();
                    this->listOfLevels[this->i]->wreath->setVisible(true);
                    this->listOfLevels[this->i]->star1->setVisible(true);
                    this->listOfLevels[this->i]->star2->setVisible(true);
                    this->listOfLevels[this->i]->star3->setVisible(true);
                    this->listOfLevels[this->i]->wreath->gotoAndStop(1);
                    this->listOfLevels[this->i]->star1->gotoAndStop(
                            this->listOfLevels[this->i]->star1->totalFrames);
                    this->listOfLevels[this->i]->star2->gotoAndStop(
                            this->listOfLevels[this->i]->star2->totalFrames);
                    this->listOfLevels[this->i]->star3->gotoAndStop(
                            this->listOfLevels[this->i]->star3->totalFrames);
                    this->listOfLevels[this->i]->stop();
                    this->listOfLevels[this->i]->levelCase->stop();
                }
            }
            this->listOfLevels[this->i]->stop();
            if (this->listOfLevels[this->i]->levelCase) {
                this->listOfLevels[this->i]->levelCase->stop();
                this->listOfLevels[this->i]->levelCase->setMouseEnabled(true);
            }
            i++;
        }
        return;
    }// end function

    void LevelsMenu::openNewLevel() {
        if (this->newLevel == 1) {
            if (this->container->road->currentFrame < 12) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 2) {
            if (this->container->road->currentFrame < 26) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 3) {
            if (this->container->road->currentFrame < 41) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 4) {
            if (this->container->road->currentFrame < 55) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 5) {
            if (this->container->road->currentFrame < 66) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 6) {
            if (this->container->road->currentFrame < 80) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 7) {
            if (this->container->road->currentFrame < 92) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 8) {
            if (this->container->road->currentFrame < 104) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 9) {
            if (this->container->road->currentFrame < 115) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 10) {
            if (this->container->road->currentFrame < 127) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 11) {
            if (this->container->road->currentFrame < 136) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 12) {
            if (this->container->road->currentFrame < 144) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 13) {
            if (this->container->road->currentFrame < 153) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 14) {
            if (this->container->road->currentFrame < 164) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        } else if (this->newLevel == 15) {
            if (this->container->road->currentFrame < 179) {
                this->container->road->gotoAndStop((this->container->road->currentFrame + 1));
            } else if (!this->roadOff) {
                this->roadOff = true;
            }
        }
        if (this->roadOff) {
            if (!this->newLevelGr) {
                this->newLevelGr = new NewLevel_mc();
                this->newLevelGr->stop();
                Vec2 pos = this->convertToNodeSpace(
                        this->listOfLevels[(this->newLevel - 1)]->convertToWorldSpace(Vec2(0, 0)));
                this->newLevelGr->setPositionX(pos.x + 0.65);
                this->newLevelGr->setPositionY(pos.y + 0.65);
                this->addChild(this->newLevelGr);
                this->listOfLevels[(this->newLevel - 1)]->setVisible(true);
                this->listOfLevels[(this->newLevel - 1)]->setAlpha(0);
            } else if (this->newLevelGr->currentFrame < this->newLevelGr->totalFrames) {
                this->newLevelGr->gotoAndStop((this->newLevelGr->currentFrame + 1));
                if (this->newLevelGr->currentFrame >= 8) {
                    this->newLevelGr->setAlpha(this->newLevelGr->getAlpha() - 0.2);
                    this->listOfLevels[(this->newLevel - 1)]->setAlpha(
                            this->listOfLevels[(this->newLevel - 1)]->getAlpha() + 0.2);
                }
            } else {
                if (this->newLevel == 1) {
                    //this->training_1 = new Training_1();
                    //this->addChild(this->training_1);
                }
                this->listOfLevels[(this->newLevel - 1)]->setAlpha(1);
                this->newLevel = 0;
                Main::mainClass->saveBoxClass->setValue("newLevel", 0);
                this->removeChild(this->newLevelGr);
                this->newLevelGr = NULL;
            }
        }
        return;
    }// end function

    void LevelsMenu::openNewStarsForLevel() {
        if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels",
                                                       (this->newStarsForLevel - 1)) < 4) {
            if (this->listOfLevels[(this->newStarsForLevel - 1)]->towerEffect->currentFrame <
                this->listOfLevels[(this->newStarsForLevel - 1)]->towerEffect->totalFrames) {
                this->listOfLevels[(this->newStarsForLevel - 1)]->towerEffect->gotoAndStop(
                        (this->listOfLevels[(this->newStarsForLevel -
                                             1)]->towerEffect->currentFrame + 1));
            } else if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels",
                                                                  (this->newStarsForLevel - 1)) ==
                       1) {
                if (!this->listOfLevels[(this->newStarsForLevel - 1)]->star1->isVisible()) {
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->setVisible(true);
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)]->star1->currentFrame <
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->totalFrames) {
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->gotoAndStop(
                            (this->listOfLevels[(this->newStarsForLevel - 1)]->star1->currentFrame +
                             1));
                } else {
                    this->newStarsForLevel = 0;
                    Main::mainClass->saveBoxClass->setValue("newStarsForLevel",
                                                            this->newStarsForLevel);
                    this->preparationLevels();
                }
            } else if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels",
                                                                  (this->newStarsForLevel - 1)) ==
                       2) {
                if (!this->listOfLevels[(this->newStarsForLevel - 1)]->star1->isVisible()) {
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->setVisible(true);
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star2->setVisible(true);
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)]->star1->currentFrame <
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->totalFrames) {
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->gotoAndStop(
                            (this->listOfLevels[(this->newStarsForLevel - 1)]->star1->currentFrame +
                             1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)]->star2->currentFrame <
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star2->totalFrames) {
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star2->gotoAndStop(
                            (this->listOfLevels[(this->newStarsForLevel - 1)]->star2->currentFrame +
                             1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)]->star1->currentFrame ==
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->totalFrames
                    && this->listOfLevels[(this->newStarsForLevel - 1)]->star2->currentFrame ==
                       this->listOfLevels[(this->newStarsForLevel - 1)]->star2->totalFrames) {
                    this->newStarsForLevel = 0;
                    Main::mainClass->saveBoxClass->setValue("newStarsForLevel", 0);
                    this->preparationLevels();
                }
            } else if (Main::mainClass->saveBoxClass->getIntValue("starsOfLevels",
                                                                  (this->newStarsForLevel - 1)) ==
                       3) {
                if (!this->listOfLevels[(this->newStarsForLevel - 1)]->star1->isVisible()) {
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->setVisible(true);
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star2->setVisible(true);
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star3->setVisible(true);
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)]->star1->currentFrame <
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->totalFrames) {
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->gotoAndStop(
                            (this->listOfLevels[(this->newStarsForLevel - 1)]->star1->currentFrame +
                             1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)]->star2->currentFrame <
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star2->totalFrames) {
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star2->gotoAndStop(
                            (this->listOfLevels[(this->newStarsForLevel - 1)]->star2->currentFrame +
                             1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)]->star3->currentFrame <
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star3->totalFrames) {
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star3->gotoAndStop(
                            (this->listOfLevels[(this->newStarsForLevel - 1)]->star3->currentFrame +
                             1));
                }
                if (this->listOfLevels[(this->newStarsForLevel - 1)]->star1->currentFrame ==
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star1->totalFrames &&
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star2->currentFrame ==
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star2->totalFrames &&
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star3->currentFrame ==
                    this->listOfLevels[(this->newStarsForLevel - 1)]->star3->totalFrames) {
                    this->newStarsForLevel = 0;
                    Main::mainClass->saveBoxClass->setValue("newStarsForLevel", 0);
                    this->preparationLevels();
                }
            }
        } else if (this->listOfLevels[(this->newStarsForLevel - 1)]->wreath->currentFrame <
                   this->listOfLevels[(this->newStarsForLevel - 1)]->wreath->totalFrames) {
            this->listOfLevels[(this->newStarsForLevel - 1)]->wreath->gotoAndStop(
                    (this->listOfLevels[(this->newStarsForLevel - 1)]->wreath->currentFrame + 1));
        } else {
            this->newStarsForLevel = 0;
            Main::mainClass->saveBoxClass->setValue("newStarsForLevel", 0);
            this->preparationLevels();
        }
        return;
    }// end function

    void LevelsMenu::autoguidersButtons() {
        //this->autoguidesMouse_pt = CONVERT_TO_WORLD_POS(cocos2d::Point(this->mouseX, this->mouseY));
        //this->autoguidesObject = NULL;
        //this->autoguidesObject_pt = CONVERT_TO_WORLD_POS(this->container->back->localToGlobal(this->container->backBackCase->getPosition()));
        //this->autoguidesObjectWidth = this->container->backBackCase->getWidth() / 2;
        //this->autoguidesObjectHeight = this->container->backBackCase->getHeight() / 2;
        //if (this->container->backBackCase->hitTest(autoguidesMouse_pt))
        //{
        //	this->autoguidesObject = this->container->backBackCase;
        //}
        //      if (!this->autoguidesObject)
        //      {
        //          this->autoguidesObject_pt = this->container->upgrades->localToGlobal( this->container->upgrades->upgradesCase1->getPosition());
        //          this->autoguidesObjectWidth = this->container->upgrades->upgradesCase1->width / 2;
        //          this->autoguidesObjectHeight = this->container->upgrades->upgradesCase1->height / 2;
        //          if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //              && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //          {
        //              this->autoguidesObject = this->container->upgrades->upgradesCase1;
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          this->autoguidesObject_pt = this->container->upgrades->localToGlobal(this->container->upgrades->upgradesCase2->getPosition());
        //          this->autoguidesObjectWidth = this->container->upgrades.upgradesCase2->width / 2;
        //          this->autoguidesObjectHeight = this->container->upgrades.upgradesCase2->height / 2;
        //          if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //              && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //          {
        //              this->autoguidesObject = this->container->upgrades->upgradesCase2;
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          this->autoguidesObject_pt = this->container->book->localToGlobal(this->container->book->bookCase1->getPosition());
        //          this->autoguidesObjectWidth = this->container->book->bookCase1->width / 2;
        //          this->autoguidesObjectHeight = this->container->book->bookCase1->height / 2;
        //          if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //              && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //          {
        //              this->autoguidesObject = this->container->book->bookCase1;
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          this->autoguidesObject_pt = this->container->book->localToGlobal(this->container->book->bookCase2->getPosition());
        //          this->autoguidesObjectWidth = this->container->book->bookCase2->width / 2;
        //          this->autoguidesObjectHeight = this->container->book->bookCase2->height / 2;
        //          if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //              && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //          {
        //              this->autoguidesObject = this->container->book->bookCase2;
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          this->autoguidesObject_pt = this->container->achieves->localToGlobal(this->container->achieves->achievesCase1->getPosition());
        //          this->autoguidesObjectWidth = this->container->achieves->achievesCase1->width / 2;
        //          this->autoguidesObjectHeight = this->container->achieves->achievesCase1->height / 2;
        //          if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //              && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //          {
        //              this->autoguidesObject = this->container->achieves->achievesCase1;
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          this->autoguidesObject_pt = this->container->achieves->localToGlobal(this->container->achieves->achievesCase2->getPosition());
        //          this->autoguidesObjectWidth = this->container->achieves->achievesCase2->width / 2;
        //          this->autoguidesObjectHeight = this->container->achieves->achievesCase2->height / 2;
        //          if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //              && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //              && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //          {
        //              this->autoguidesObject = this->container->achieves->achievesCase2;
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level1->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level1->localToGlobal(this->container->level1->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level1->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level1->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level1->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level2->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level2->localToGlobal(this->container->level2->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level2->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level2->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level2->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level3->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level3->localToGlobal(this->container->level3->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level3->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level3->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level3->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level4->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level4->localToGlobal(this->container->level4->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level4->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level4->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level4->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level5->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level5->localToGlobal(this->container->level5->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level5->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level5->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level5->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level6->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level6->localToGlobal(this->container->level6->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level6->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level6->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level6->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level7->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level7->localToGlobal(this->container->level7->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level7->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level7->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level7->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level8->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level8->localToGlobal(this->container->level8->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level8->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level8->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level8->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level9->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level9->localToGlobal(this->container->level9->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level9->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level9->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level9->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level10->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level10->localToGlobal(this->container->level10->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level10->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level10->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level10->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level11->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level11->localToGlobal(this->container->level11->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level11->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level11->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level11->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level12->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level12->localToGlobal(this->container->level12->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level12->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level12->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level12->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level13->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level13->localToGlobal(this->container->level13->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level13->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level13->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level13->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level14->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level14->localToGlobal(this->container->level14->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level14->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level14->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level14->levelCase;
        //              }
        //          }
        //      }
        //      if (!this->autoguidesObject)
        //      {
        //          if (this->container->level15->levelCase)
        //          {
        //              this->autoguidesObject_pt = this->container->level15->localToGlobal(this->container->level15->levelCase->getPosition());
        //              this->autoguidesObjectWidth = this->container->level15->levelCase->width / 2;
        //              this->autoguidesObjectHeight = this->container->level15->levelCase->height / 2;
        //              if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth
        //                  && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight
        //                  && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        //              {
        //                  this->autoguidesObject = this->container->level15->levelCase;
        //              }
        //          }
        //      }
        //      if (this->autoguidesObject)
        //      {
        //          this->tempObject = new Object();
        //          this->tempObject.target = this->autoguidesObject;
        //          this->mouseMoveHandler(this->tempObject);
        //      }
        return;
    }// end function

    //void reInit(event:Event) 
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    return;
    //}// end function

}

