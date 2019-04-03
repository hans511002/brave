#include "engine/World.h"
#include "MainClass.h"

#include "engine/Waves.h"
#include "sys/saveBox.h"
#include "engine/WorldInterface.h"
#include "Feature.h"

#include "engine/MoneyAdd.h"
#include "engine/CastSphere.h"
#include "engine/GetSphere.h"
#include "BonusMoney.h"

#include "engine/level/Level.h"
#include "engine/decoration/Decoration.h"

#include "engine/units/Unit.h"
#include "engine/GetSphere.h"
#include "engine/bullets/Bullet.h"

#include "engine/towers/Tower.h"
#include "engine/towers/BuildTowerMenu.h"
#include "engine/towers/UltraTowerMenu.h"
#include "engine/towers/TowerMenu.h"

#include "engine/casts/Map.h"
#include "engine/casts/Cast.h"

#include "screens/MiddleScreen.h"
#include "screens/PauseMenu.h"
#include "screens/FastPause.h"
#include "screens/PauseMenu.h"
#include "screens/Defeat.h"
#include "screens/Victory.h"
#include "screens/PreVictory.h"


using namespace engine;
using namespace engine::units;
using namespace engine::bullets;
namespace engine {
    World::World() : frameCounter(0), feature(NULL), bezierClass(NULL), wavesClass(NULL),
                     numRoads(0), level(NULL), road(NULL), levelAdditionally(NULL),
                     levelAdditionally1(NULL), levelAdditionally2(NULL), levelAdditionally3(NULL),
                     worldInterface(NULL), money(0), bonusMoney(0), liveMax(20), live(0),
                     forseIndexFl(false), getSphere(NULL), buildTowerMenu(NULL), towerMenu(NULL),
                     ultraTowerMenu(NULL), scaleRadius(0.85f), towerRadius(NULL),
                     unitInputBezieCounter(0), cast(NULL), menuObject(NULL), pointer1(NULL),
                     pointer2(NULL), pointer3(NULL), selectObject(NULL), firstMusicPlay(false),
                     secondMusicPlay(false), secondMusicCounter(0), winDefCounter(-1), viewBoss(0),
                     viewRockCrash(0), boss(NULL), decoration(NULL), nowLevel(0), saveBox(NULL),
                     exchange(NULL), portalViewCounter(30), trainingClass(NULL), hint(NULL),
                     startMusicVolume(0), bonusMoneyFlag(true), eduOpenUpgrArrowFlag(true),
                     killEnemiesCounter(0), createGolemCounter(0), createIcemanCounter(0),
                     createAirCounter(0), earlyWaveCounter(0), sellFireCounter(0),
                     sellIceCounter(0), sellStoneCounter(0), sellLevinCounter(0),
                     sellGetAllCounter(0), icemanSlowdownEnemiesCounter(0), castFireCounter(0),
                     castIceCounter(0), castStoneCounter(0), castLevinCounter(0),
                     castGetAllCounter(0), golemVoiceTurn(1), icemanVoiceTurn(1), airVoiceTurn(1),
                     fixedRoot(NULL) {
        if (useNodeEvent)
            std::globalNode = this;
        //MCCase::worldMouseHandler.node = this;
        //MCCase::worldMouseHandler.mouseDownHandler = NODE_MOUSEHANDLER_SELECTOR(World::mouseDownHandler);
        //MCCase::worldMouseHandler.mouseMoveHandler =   NODE_MOUSEHANDLER_SELECTOR (World::mouseMoveHandler);
        //MCCase::worldMouseHandler.mouseUpHandler = NODE_MOUSEHANDLER_SELECTOR(World::mouseUpHandler);
        menuObject = NULL;
        pointer1 = NULL;
        pointer2 = NULL;
        pointer3 = NULL;
        this->setContentSize(Size(Main::LEVEL_MAP_WIDTH, Main::LEVEL_MAP_HEIGHT));
        //Main::mainClass->worldClass = this;
        //this->listOfFlags = [];
        //this->listOfPlaces = [];
        //this->listOfFirePortals = [];
        //this->listOfIcePortals = [];
        //this->listOfStonePortals = [];
        //this->listOfLevinPortals = [];
        this->live = this->liveMax;
        ////////////level end////////
        //live = 0; winDefCounter = (1);
        ///////////////////////
        //this->listOfMoveSpheres = [];
        this->listOfClasses.clear();
        //this->listOfTowers = [];
        //this->listOfUnits = [];
        //this->listOfBullets = [];
        this->unitInputBezieArr.push_back(3);//[3, 1, 2, 1, 3, 2];
        this->unitInputBezieArr.push_back(1);//[3, 1, 2, 1, 3, 2];
        this->unitInputBezieArr.push_back(2);//[3, 1, 2, 1, 3, 2];
        this->unitInputBezieArr.push_back(1);//[3, 1, 2, 1, 3, 2];
        this->unitInputBezieArr.push_back(3);//[3, 1, 2, 1, 3, 2];
        this->unitInputBezieArr.push_back(2);//[3, 1, 2, 1, 3, 2];
        //this->listOfIndexes0 = [];
        //this->listOfIndexes1 = [];
        //this->listOfIndexes2 = [];
        //this->listOfIndexes3 = [];
        //this->sortIndex = [];
        //this->listOfSoundChannels = [];
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        //return;
    }// end function
    bool World::init() {
        BaseNode::init();
        fixedRoot = Node::create();
        fixedRoot->setContentSize(Size(Main::LEVEL_MAP_WIDTH, Main::LEVEL_MAP_HEIGHT));
        if (this->getParent())
            this->getParent()->addChild(fixedRoot);
        this->wavesClass = new Waves();
        this->feature = new Feature();
        map = new casts::Map();
        ////test bezier getPathPoint
        //int r=1,w=1;
        //float finishPath = this->bezierClass->getPathLength(r, w);
        //Common::DateTime dt;
        //float path=0;
        //for (int i = 0; i < 100000; ++i) {
        //	path=std::random()*finishPath;
        //	bezier::PathPoint ppo = this->bezierClass->getPathPoint(path, r,w);
        //}
        //long ts=Common::DateTime().GetTicks() -dt.GetTicks();
        int complexityLevel = this->saveBox->getIntValue("complexityLevel");
        if (complexityLevel < 4) {
            if (this->nowLevel < 12 || this->nowLevel == 13) {
                //this->setMouseChildren(false);
                //this->setMouseEnabled(false);
            }
        }
        if (Main::SCREEN_WIDTH != Main::LEVEL_MAP_WIDTH ||
            Main::LEVEL_MAP_HEIGHT != Main::SCREEN_HEIGHT) {
            this->setMouseDrag(true);
            float h = Main::LEVEL_MAP_HEIGHT - Main::SCREEN_HEIGHT;
            float w = Main::LEVEL_MAP_WIDTH - Main::SCREEN_WIDTH;
            this->minDragPos = Vec2(-w, -h);
            this->maxDragPos = Vec2(0, 0);
        }
        //savePos=this->getPosition();
        return true;
    };

    void World::onEnter() {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        BaseNode::onEnter();
        if (fixedRoot && !fixedRoot->getParent())
            this->getParent()->addChild(fixedRoot);
        //this->schedule(schedule_selector(World::enterFrameHandler), 0.033f);
        //Main::mainClass->tracker.trackPageview("openLevel_" + this->nowLevel);
    }// end function
    void World::focusChanged(cocos2d::EventFocus *e) {

    };

    void World::onExit() {
        delete this->map;
        this->map = NULL;
        delete this->wavesClass;
        this->wavesClass = NULL;
        delete this->feature;
        this->feature = NULL;
        BaseNode::onExit();
    };

    //void  World::enterFrameHandler()  // event : Event
    void World::enterFrameHandler(float dt) {
        bool printTime = false;
        if (this->frameCounter < 30)
            this->frameCounter++;
        else
            this->frameCounter = 1;
        Common::DateTime stime, gstime;
        int ts = 0;
        if (!this->firstMusicPlay) {
            int complexityLevel = this->saveBox->getIntValue("complexityLevel");
            if (this->frameCounter == 10) {
                this->firstMusicPlay = true;
                AudioUtil::playMusic("Music_world_beforeBattle.mp3");// (1f);
                if (complexityLevel < 4) {
                    if (this->nowLevel == 1) {
                        //this->menuObject = new Training_2();
                        //this->addChild(this->menuObject);
                        //this->setMouseChildren(true);
                        //this->setMouseEnabled(true);
                    } else if (this->nowLevel >= 2 && this->nowLevel <= 11) {
                        //this->menuObject = new Training_92(this->nowLevel - 1);
                        //this->addChild(this->menuObject);
                        //this->setMouseChildren(true);
                        //this->setMouseEnabled(true);
                    } else if (this->nowLevel == 13) {
                        //this->menuObject = new Training_92(11);
                        //this->addChild(this->menuObject);
                        //this->setMouseChildren(true);
                        //this->setMouseEnabled(true);
                    }
                } else if (this->nowLevel == 1) {
                    //this->menuObject = new Training_92(13);
                    //this->addChild(this->menuObject);
                    //this->setMouseChildren(true);
                    //this->setMouseEnabled(true);
                } else if (this->nowLevel == 2) {
                    //this->menuObject = new Training_5(3);
                    //this->addChild(this->menuObject);
                    //this->setMouseChildren(true);
                    //this->setMouseEnabled(true);
                }
            }
        } else if (this->secondMusicPlay) {
            if (this->secondMusicCounter > 0) {
                this->secondMusicCounter--;
            } else {
                this->secondMusicPlay = false;
                AudioUtil::playMusic("Music_world_battle.mp3");// (2f);
            }
        }
        if (this->bonusMoneyFlag) {
            if (this->frameCounter == 30 && !this->menuObject) {
                this->bonusMoneyFlag = false;
                if (this->saveBox->getIntValue("complexityLevel") < 4 &&
                    this->saveBox->getStringValue("type") == "site") {
                    BonusMoney *tempObject = new BonusMoney();
                    this->addChild(tempObject, 3);
                }
            }
        }
        if (printTime) {
            ts = Common::DateTime().GetTicks() - stime.GetTicks();
            stime = Common::DateTime();
            logInfo("begin", ts);
        }
        this->wavesClass->wavesHandler();
        if (printTime) {
            ts = Common::DateTime().GetTicks() - stime.GetTicks();
            stime = Common::DateTime();
            logInfo("wavesHandler", ts);
        }
        if (this->worldInterface)
            this->worldInterface->update();
        if (printTime) {
            ts = Common::DateTime().GetTicks() - stime.GetTicks();
            stime = Common::DateTime();
            logInfo("worldInterface", ts);
        }
        this->feature->update();
        if (printTime) {
            ts = Common::DateTime().GetTicks() - stime.GetTicks();
            stime = Common::DateTime();
            logInfo("feature", ts);
        }
        int i = 0;
        //子类播放
        i = this->listOfClasses.size() - 1;
        while (i >= 0) {
            this->listOfClasses[i]->update();
            i--;
        }
        if (printTime) {
            ts = Common::DateTime().GetTicks() - stime.GetTicks();
            stime = Common::DateTime();
            logInfo("listOfClasses", ts);
        }
        i = this->listOfTowers.size() - 1;
        while (i >= 0) {
            this->listOfTowers[i]->update();
            i--;
        }
        if (printTime) {
            ts = Common::DateTime().GetTicks() - stime.GetTicks();
            stime = Common::DateTime();
            logInfo("listOfTowers", ts);
        }
        i = this->listOfBullets.size() - 1;
        while (i >= 0) {
            this->listOfBullets[i]->update();
            i--;
        }
        if (printTime) {
            ts = Common::DateTime().GetTicks() - stime.GetTicks();
            stime = Common::DateTime();
            logInfo("listOfBullets", ts);
        }
        //怪播放
        i = this->listOfUnits.size() - 1;
        while (i >= 0) {
            engine::units::Unit *unit = this->listOfUnits[i];
            unit->update();
            i--;
        }
        if (printTime) {
            ts = Common::DateTime().GetTicks() - stime.GetTicks();
            stime = Common::DateTime();
            logInfo("listOfUnits", ts);
        }
        i = this->listOfDeads.size() - 1;
        while (i >= 0) {
             this->listOfDeads[i]->update();
            i--;
        }
        if (this->winDefCounter > -1) {
            if (this->winDefCounter > 0) {
                winDefCounter--;
            } else if (!this->menuObject) {
                this->winDefCounter = -1;
                if (this->live <= 0) {
                    this->menuObject = new Defeat();
                    this->addChild(this->menuObject, 9999);
                } else if (this->nowLevel == 15 &&
                           this->saveBox->getIntValue("complexityLevel") < 4) {
                    this->menuObject = new PreVictory();
                    this->addChild(this->menuObject, 9999);
                } else {
                    this->menuObject = new Victory();
                    this->addChild(this->menuObject, 9999);
                }
            }
        }

        if (this->nowLevel == 15) {
            if (this->viewBoss == 1) {
                if (AudioUtil::musicOn) {
                    if (this->startMusicVolume == 0)
                        this->startMusicVolume = AudioUtil::getMusicVolume();
                    if (AudioUtil::getMusicVolume() > this->startMusicVolume * 0.35)
                        AudioUtil::setMusicVolume(
                                AudioUtil::getMusicVolume() - this->startMusicVolume * 0.035f);
                }
                if (this->levelAdditionally->currentFrame < this->levelAdditionally->totalFrames) {
                    this->levelAdditionally1->tryPlay();
                    //this->levelAdditionally->gotoAndStop((this->levelAdditionally->currentFrame + 1));
                }
                if (this->levelAdditionally->currentFrame == 182) {
                    this->viewBoss = 2;
                    this->boss->setVisible(true);
                }
            }
            if (this->viewRockCrash == 1) {
                if (this->levelAdditionally1->currentFrame <
                    this->levelAdditionally1->totalFrames) {
                    this->levelAdditionally1->tryPlay();
                    //this->levelAdditionally1->gotoAndStop((this->levelAdditionally1->currentFrame + 1));
                    if (this->levelAdditionally1->currentFrame == 90) {
                        AudioUtil::playSound("Snd_world_openRoad.mp3");
                    }
                } else {
                    this->viewRockCrash = 2;
                }
            }
        }

        if (this->exchange)
            this->exchange->update();
        if (this->portalViewCounter > -1) {
            if (this->portalViewCounter > 0) {
                this->portalViewCounter--;
            } else {
                this->portalViewCounter = -1;
                int i = 0;
                while (i < this->listOfFirePortals.size()) {
                    Indexes *tempObject = new Indexes(new RoadsignFire_mc(), 0);
                    tempObject->setPosition(this->listOfFirePortals[i]->getPosition());
                    tempObject->setScaleX(this->listOfFirePortals[i]->getScaleX());
                    tempObject->setScaleY(this->listOfFirePortals[i]->getScaleY());
                    i++;
                }
                i = 0;
                while (i < this->listOfIcePortals.size()) {
                    Indexes *tempObject = new Indexes(new RoadsignIce_mc(), 0);
                    tempObject->setPosition(this->listOfIcePortals[i]->getPosition());
                    tempObject->setScaleX(this->listOfIcePortals[i]->getScaleX());
                    tempObject->setScaleY(this->listOfIcePortals[i]->getScaleY());
                    i++;
                }
                i = 0;
                while (i < this->listOfStonePortals.size()) {
                    Indexes *tempObject = new Indexes(new RoadsignStone_mc(), 0);
                    tempObject->setPosition(this->listOfStonePortals[i]->getPosition());
                    tempObject->setScaleX(this->listOfStonePortals[i]->getScaleX());
                    tempObject->setScaleY(this->listOfStonePortals[i]->getScaleY());
                    i++;
                }
                i = 0;
                while (i < this->listOfLevinPortals.size()) {
                    Indexes *tempObject = new Indexes(new RoadsignLevin_mc(), 0);
                    tempObject->setPosition(this->listOfLevinPortals[i]->getPosition());
                    tempObject->setScaleX(this->listOfLevinPortals[i]->getScaleX());
                    tempObject->setScaleY(this->listOfLevinPortals[i]->getScaleY());
                    i++;
                }
            }
        }
        this->manageIndexes();
        if (printTime) {
            ts = Common::DateTime().GetTicks() - stime.GetTicks();
            stime = Common::DateTime();
            logInfo("end", ts);
            ts = Common::DateTime().GetTicks() - gstime.GetTicks();
            logInfo("all", ts);
        }
        if (this->worldInterface->fasterFlag == 2) {
            if (this->frameCounter % 2) {
                this->enterFrameHandler(0);
            }
        }

        return;
    }// end function
    void World::removeEventTarget(std::MouseEvent *event, BaseNode *node, string caseName) {
        if (!node)return;
        int ri = event->getIndex(caseName);
        if (ri >= 0) {
            Vec2 pos = event->getLocationInView();
            if (std::hitTest(node, pos, false)) {
                event->remove(ri);
            }
        }
    }

    void World::removeEventTarget(std::MouseEvent *event, string case1, string caseName) {
        int ri = event->getIndex(case1);
        if (ri >= 0) {
            ri = event->getIndex(caseName);
            if (ri >= 0)
                event->remove(ri);
        }
    }

    bool World::preCheckEventTarget(std::MouseEvent *event, EventMouse::MouseEventType _mouseEventType) {
        if(useNodeEvent)return false;
        //this->castMask->fireCase->stop();
        //this->castMask->iceCase->stop();
        //this->castMask->stoneCase->stop();
        //this->castMask->levinCase->stop();
        //this->castMask->getAllCase->stop();
        //this->castMask->archiveCase->stop();
        //this->castMask->interfaceUpCase->stop();
        //this->castMask->sellCase->stop();
        removeEventTarget(event, "fireCase", "interfaceUpCase");
        removeEventTarget(event, "iceCase", "interfaceUpCase");
        removeEventTarget(event, "stoneCase", "interfaceUpCase");
        removeEventTarget(event, "levinCase", "interfaceUpCase");
        removeEventTarget(event, "getAllCase", "interfaceUpCase");
        removeEventTarget(event, "fireCase", "archiveCase");
        removeEventTarget(event, "iceCase", "archiveCase");
        removeEventTarget(event, "stoneCase", "archiveCase");
        removeEventTarget(event, "levinCase", "archiveCase");
        removeEventTarget(event, "getAllCase", "archiveCase");
        removeEventTarget(event, "archiveCase", "interfaceUpCase");
        removeEventTarget(event, "sellCase", "interfaceUpCase");
        Vec2 pos = event->getLocationInView();
        switch (_mouseEventType) {
            case cocos2d::EventMouse::MouseEventType::MOUSE_NONE:
                break;
            case cocos2d::EventMouse::MouseEventType::MOUSE_DOWN:
                if (this->towerMenu) {
                    removeEventTarget(event, this->towerMenu, "road");
                    removeEventTarget(event, this->towerMenu, "towerCase");
                }
                if (this->getSphere) {
                    removeEventTarget(event, this->getSphere, "sphereCase");
                    removeEventTarget(event, "fireCase", "sphereCase");
                    removeEventTarget(event, "iceCase", "sphereCase");
                    removeEventTarget(event, "stoneCase", "sphereCase");
                    removeEventTarget(event, "levinCase", "sphereCase");
                    removeEventTarget(event, "getAllCase", "sphereCase");
                } else {
                    removeEventTarget(event, "sphereCase", "archiveCase");
                    removeEventTarget(event, "sphereCase", "fireCase");
                }
                break;
            case cocos2d::EventMouse::MouseEventType::MOUSE_UP:
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

    //cocos2d::EventMouse* event
    void World::mouseDownHandler(cocos2d::EventMouse *e) {
		logInfo("check mouse down: ", getNamePath(e->getCurrentTarget()));
		if (!globalNode)EventNode::mouseDownHandler(e);
        cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
        if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
        std::MouseEvent me(e);
        if (!useNodeEvent) {
            me = std::buildMouseEvent(e);
        }else if(globalNode && globalNode==this){
            if (!std::hitTest(e->getCurrentTarget(), e,true,true))return;
			e->stopPropagation(); 
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
            {
                logInfo("mouseDownHandler.target", getNamePath(event->target));
                Vec2 gpos = CONVERT_TO_WORLD_POS(event->target->getParent()->convertToWorldSpace(
                        event->target->getPosition()));
                logInfo("mouseDownHandler.target.pos", event->getLocation(),
                        &event->target->getPosition(), &gpos);
                logInfo("mouseDownHandler.target.zindex", event->target->getLocalZOrder(), 0);
            }
            if (this->getSphere) {
                this->getSphere->mouseDownHandler(event);
                if (!this->getSphere)
                    return;
            } else {
                if (this->cast) {
                    this->cast->mouseDownHandler(event);
                    if (!this->cast)
                        return;
                }
                if (this->towerMenu) {
                    this->towerMenu->mouseDownHandler(event);
                    if (event->processed)
                        continue;
                } else if (this->ultraTowerMenu) {
                    this->ultraTowerMenu->mouseDownHandler(event);
                    if (event->processed)
                        continue;
                } else if (this->exchange) {
                    this->exchange->mouseDownHandler(event);
                    if (event->processed)
                        continue;    //return;
                }
            }
            if (this->buildTowerMenu) {
                this->buildTowerMenu->mouseDownHandler(event);
                if (event->processed)
                    continue;
            }
            if (this->decoration) {
                this->decoration->mouseDownHandler(event);
                if (event->processed)
                    continue;
            }
            if (!this->cast && targetName == "towerCase")// && event->target->mouseEnabled
            {
                Node *parent = event->target->getParent()->getParent()->getParent()->getParent();
                Tower *tower = ISTYPE(Tower, parent);
                if (tower->towerType <= 4) {
                    this->towerMenu = new TowerMenu(tower);
                    this->addChild(this->towerMenu, 3);
                    this->towerMenu->init();
                } else {
                    this->ultraTowerMenu = new UltraTowerMenu(tower);
                    this->addChild(this->ultraTowerMenu, 3);
                    this->ultraTowerMenu->init();
                }
                AudioUtil::playSound("Snd_tower_openMenu.mp3");
            }
            if (this->worldInterface) {
                this->worldInterface->mouseDownHandler(event);
                //if(event->processed)
                //    continue;
            }
            if (!this->getSphere && !this->cast) {
                if (targetName == "unitCase") {
                    Node *parent = event->target->getParent()->getParent()->getParent()->getParent();
                    Unit *unit = ISTYPE(Unit, parent);
                    this->worldInterface->barInfoManage(unit);
                } else if (this->selectObject) {
                    if (ISTYPE(Unit, this->selectObject)) {
                        this->worldInterface->barInfoManage();
                    } else if (ISTYPE(TowerMenu, this->selectObject) ||
                               ISTYPE(UltraTowerMenu, this->selectObject)) {
                        if (!this->towerMenu && !this->ultraTowerMenu) {
                            this->worldInterface->barInfoManage();
                        }
                    }
                }
            } else {
                if (this->selectObject) {
                    if (this->selectObject != this->getSphere && this->selectObject != this->cast) {
                        if (ISTYPE(TowerMenu, this->selectObject)) {
                            this->worldInterface->barInfoManage();
                        }
                    }
                } else {
                    this->worldInterface->barInfoManage();
                }
                if (this->getSphere) {
                    if (this->selectObject != this->getSphere) {
                        this->worldInterface->barInfoManage(this->getSphere);
                    }
                } else if (this->cast) {
                    if (this->selectObject != this->cast) {
                        this->worldInterface->barInfoManage(this->cast);
                    }
                }
            }
        }
    }

    void World::mouseUpHandler(cocos2d::EventMouse *e) {
		logInfo("check mouse up: ", getNamePath(e->getCurrentTarget()));
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
            logInfo("mouseUpHandler.target", getNamePath(event->target));
            if (this->getSphere) {
                this->getSphere->mouseUpHandler(event);
                if (event->processed)
                    continue;
            } else {
                if (this->cast) {
                    this->cast->mouseUpHandler(event);
                    if (event->processed)
                        continue; //return;
                }
                if (this->towerMenu) {
                    this->towerMenu->mouseUpHandler(event);
                } else if (this->ultraTowerMenu) {
                    this->ultraTowerMenu->mouseUpHandler(event);
                } else if (this->exchange) {
                    this->exchange->mouseUpHandler(event);
                    if (event->processed)
                        continue;  //return;
                }
            }
            if (this->buildTowerMenu) {
                this->buildTowerMenu->mouseUpHandler(event);
                if (event->processed)
                    continue;
            }
            if (this->decoration) {
                this->decoration->mouseUpHandler(event);
                if (event->processed)
                    continue;
            }
            if (this->worldInterface) {
                this->worldInterface->mouseUpHandler(event);
                if (event->processed)
                    continue;
            }
        }
        EventNode::beginTouchNode = NULL;
    }// end function
    void World::repairPos(Vec2 endPos) {
        if (endPos.x < this->minDragPos.x) {
            endPos.x = this->minDragPos.x;
        } else if (endPos.x > this->maxDragPos.x) {
            endPos.x = this->maxDragPos.x;
        }
        if (endPos.y < this->minDragPos.y) {
            endPos.y = this->minDragPos.y;
        } else if (endPos.y > this->maxDragPos.y) {
            endPos.y = this->maxDragPos.y;
        }
        savePos = this->getPosition();
        Vec2 moveOffset = endPos - savePos;
        this->setPosition(endPos);
        this->worldInterface->setPosition(this->worldInterface->getPosition() - moveOffset);
        this->worldInterface->savePos = this->worldInterface->getPosition();
        savePos = this->getPosition();
    }

    Vec2 World::getMousePos() {
        return CONVERT_TO_WORLD_POS(cocos2d::Point(Main::mouseX, Main::mouseY));
    };

    void World::repairPos(float ofx, float ofy) {
        Vec2 moveOffset(ofx, ofy);
        savePos = this->getPosition();
        Vec2 endPos = savePos + moveOffset;
        if (endPos.x < this->minDragPos.x) {
            endPos.x = this->minDragPos.x;
        } else if (endPos.x > this->maxDragPos.x) {
            endPos.x = this->maxDragPos.x;
        }
        if (endPos.y < this->minDragPos.y) {
            endPos.y = this->minDragPos.y;
        } else if (endPos.y > this->maxDragPos.y) {
            endPos.y = this->maxDragPos.y;
        }
        this->setPosition(endPos);
        moveOffset = endPos - savePos;
        this->worldInterface->setPosition(this->worldInterface->getPosition() - moveOffset);
        this->worldInterface->savePos = this->worldInterface->getPosition();
        savePos = this->getPosition();
    }

    void World::mouseMoveHandler(cocos2d::EventMouse *e) {
//		logInfo("check mouse umoved: ", getNamePath(e->getCurrentTarget()));
		if (Main::mouseX == e->getCursorX() && Main::mouseY == e->getCursorY())
            return;
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
            if (event->target == EventNode::beginTouchNode) {
                EventNode *en = ISTYPE(EventNode, event->target);
                if (en && en->isMouseDrag()) {
                    Vec2 stpos = event->target->getPosition();
                    Vec2 endPos =
                            stpos + Vec2(Main::mouseX, Main::mouseY) - EventNode::beginTouchPos;
                    EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
                    if (endPos.x < en->minDragPos.x) {
                        endPos.x = en->minDragPos.x;
                    } else if (endPos.x > en->maxDragPos.x) {
                        endPos.x = en->maxDragPos.x;
                    }
                    if (endPos.y < en->minDragPos.y) {
                        endPos.y = en->minDragPos.y;
                    } else if (endPos.y > en->maxDragPos.y) {
                        endPos.y = en->maxDragPos.y;
                    }
                    World *thiz = ISTYPE(World, event->target);
                    if (thiz) {
                        Vec2 moveOffset = endPos - stpos;
                        this->repairPos(moveOffset.x, moveOffset.y);
                    } else {
                        event->target->setPosition(endPos);
                    }
                }
            }

            if (this->getSphere) {
                this->getSphere->mouseMoveHandler(event);
            } else {
                if (this->cast) {
                    this->cast->mouseMoveHandler(event);
                    return;
                }
                if (this->towerMenu) {
                    this->towerMenu->mouseMoveHandler(event);
                } else if (this->ultraTowerMenu) {
                    this->ultraTowerMenu->mouseMoveHandler(event);
                } else if (this->exchange) {
                    this->exchange->mouseMoveHandler(event);
                    if (targetName == "towerCase") {
                        if (!this->towerRadius->isVisible() ||
                            event->target->getParent()->getParent() != this->towerRadius->myTower) {
                            Node *parent = event->target->getParent()->getParent()->getParent()->getParent();
                            Tower *tower = ISTYPE(Tower, parent);
                            this->towerRadius->myTower = tower;
                            this->towerRadius->setWidth(this->towerRadius->myTower->radius * 2);
                            this->towerRadius->setHeight(
                                    this->towerRadius->myTower->radius * 2 * this->scaleRadius);
                            this->towerRadius->setPosition(this->towerRadius->myTower->this_pt);
                            //std::setAnchorPoint(this->towerRadius, 0.5, 0.5);
                            //this->towerRadius->x = this->towerRadius->myTower->this_pt.x;
                            //this->towerRadius->y = this->towerRadius->myTower->this_pt.y;
                            this->towerRadius->setVisible(true);
                            AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
                        }
                    } else if (this->towerRadius->isVisible()) {
                        this->towerRadius->setVisible(false);
                    }
                    return;
                }
            }
            if (this->buildTowerMenu)
                this->buildTowerMenu->mouseMoveHandler(event);
            if (this->decoration)
                this->decoration->mouseMoveHandler(event);
            if (!this->cast && targetName == "towerCase")// && event->target->mouseEnabled
            {
                bool tempObject = false;
                Node *parent = event->target->getParent()->getParent()->getParent()->getParent();
                if (this->towerMenu || this->ultraTowerMenu) {
                    if (this->towerMenu) {
                        if (this->towerMenu->myTower != parent) {
                            tempObject = true;
                        }
                    } else if (this->ultraTowerMenu) {
                        if (this->ultraTowerMenu->myTower != parent) {
                            tempObject = true;
                        }
                    }
                } else {
                    tempObject = true;
                }
                if (tempObject) {
                    if (!this->towerRadius->isVisible() || parent != this->towerRadius->myTower) {
                        if (this->towerRadius->myTower) {
                            if (this->towerRadius->myTower->towerType < 5) {
                                if (this->towerRadius->myTower->container->selectTower->isVisible()) {
                                    this->towerRadius->myTower->container->selectTower->setVisible(
                                            false);
                                }
                            }
                        }
                        Tower *tower = ISTYPE(Tower, parent);
                        this->towerRadius->setVisible(true);
                        this->towerRadius->myTower = tower;
                        this->towerRadius->setWidth(this->towerRadius->myTower->radius * 2);
                        this->towerRadius->setHeight(
                                this->towerRadius->myTower->radius * 2 * this->scaleRadius);
                        this->towerRadius->setPosition(this->towerRadius->myTower->this_pt);

                        //std::setAnchorPoint(this->towerRadius, tower->getAnchorPoint());
                        //this->towerRadius->x = this->towerRadius->myTower->this_pt.x;
                        //this->towerRadius->y = this->towerRadius->myTower->this_pt.y;

                        if (this->towerRadius->myTower->towerType < 5) {
                            if (!this->towerRadius->myTower->container->selectTower->isVisible()) {
                                this->towerRadius->myTower->container->selectTower->setVisible(
                                        true);
                            }
                        }

                        logInfo("towerRadius", this->towerRadius->getAnchorPoint(),
                                &this->towerRadius->getPosition());
                        AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
                    }
                } else if (this->towerRadius->isVisible()) {
                    this->towerRadius->setVisible(false);
                    if (this->towerRadius->myTower->towerType < 5) {
                        if (this->towerRadius->myTower->container->selectTower->isVisible()) {
                            this->towerRadius->myTower->container->selectTower->setVisible(false);
                        }
                    }
                }
            } else if (this->towerRadius->isVisible()) {
                this->towerRadius->setVisible(false);
                if (this->towerRadius->myTower->towerType < 5) {
                    if (this->towerRadius->myTower->container->selectTower->isVisible()) {
                        this->towerRadius->myTower->container->selectTower->setVisible(false);
                    }
                }
            }
            if (!this->getSphere && !this->cast) {
                if (targetName == "placeForBuildCase")//&& event->target->mouseEnabled
                {
                    Node *parent = event->target->getParent()->getParent()->getParent();
                    BuildTowerPlace *place = ISTYPE(BuildTowerPlace, parent);
                    if (place->currentFrame == 1)// (event->target->getParent()->currentFrame == 1)
                    {
                        if (!this->buildTowerMenu) {
                            this->buildTowerMenu = new BuildTowerMenu(place);
                            this->addChild(this->buildTowerMenu, 3);
                            AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
                        } else if (this->buildTowerMenu->myPlace != place) {
                            this->buildTowerMenu->closeMenu();
                            this->buildTowerMenu = new BuildTowerMenu(place);
                            this->addChild(this->buildTowerMenu, 3);
                            AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
                        }
                    }
                }
            }
            if (this->worldInterface) {
                this->worldInterface->mouseMoveHandler(event);
            }
        }
    }

    void World::rightMouseDownHandler(cocos2d::EventMouse *e) {
        if (!globalNode)EventNode::mouseDownHandler(e);
        cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
        if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
        std::MouseEvent me = std::buildMouseEvent(e);
        std::MouseEvent *event = &me;
        if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_DOWN))return;
        if (!event->currentTargets.size())
            event->currentTargets.push(this);
        while (event->hasNext()) {
            string targetName = event->target->getName();
            if (targetName == "towerCase") {
                if (!this->exchange) {
                    Node *parent = event->target->getParent()->getParent();
                    Tower *tower = ISTYPE(Tower, parent);
                    if (tower->towerType < 5 && !tower->blockTowerFlag) {
                        int i = 0;
                        while (i < this->listOfTowers.size()) {
                            if (this->listOfTowers[i] != tower &&
                                this->listOfTowers[i]->towerType < 5) {
                                this->mouseMoveHandler(event);
                                this->exchange = new Exchange(tower);
                                this->addChild(this->exchange, 3);
                                break;
                            }
                            i++;
                        }
                    }
                } else {
                    this->exchange->rightMouseDownHandler(event);
                }
            } else if (this->exchange) {
                this->exchange->rightMouseDownHandler(event);
            } else if (this->nowLevel != 1 && !this->getSphere && !this->cast &&
                       !this->menuObject) {
                if (!Main::mainClass->saveBoxClass->getBoolValue("firstRC")) {
                    Main::mainClass->saveBoxClass->setValue("firstRC", true);
                    //this->menuObject = new Training_10();
                    //this->addChild(this->menuObject);
                }
            }
            if (this->getSphere || this->cast) {
                this->worldInterface->breaking();
            }
        }
    }

    void World::rightMouseUpHandler(cocos2d::EventMouse *e) {
        if (!globalNode)EventNode::mouseDownHandler(e);
        cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
        if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
        std::MouseEvent me = std::buildMouseEvent(e);
        std::MouseEvent *event = &me;
        if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_DOWN))return;
        if (!event->currentTargets.size())
            event->currentTargets.push(this);
        while (event->hasNext()) {
            if (this->exchange) {
                this->exchange->rightMouseUpHandler(event);
            }
        }
        return;
    }

    //bool World::onTouchBegan(Touch *touch, cocos2d::Event *event) {
    //	Node * node = event->getCurrentTarget();
    //		Vec2 tpos = touch->getLocationInView();
    //	tpos.y = Main::SCREEN_HEIGHT - tpos.y;
    //	if (!std::hitTest(node, tpos))return false;
    //	if (!globalNode)EventNode::onTouchBegan(touch,event);
    //
    //	Event::Type tp = event->getType();
    //	event->stopPropagation();

    //	MouseEvent mevent(cocos2d::EventMouse::MouseEventType::MOUSE_DOWN);
    //	mevent.setMouseButton(cocos2d::EventMouse::MouseButton::BUTTON_LEFT);
    //	mevent.setCursorPosition(tpos.x, tpos.y);
    //	mevent.setCurrentTarget(node);
    //	EventNode::beginTouchNode = node;
    //	EventNode::beginTouchPos = tpos;
    //	if (globalNode) {
    //		globalNode->mouseMoveHandler(&mevent);
    //		globalNode->mouseDownHandler(&mevent);
    //	}
    //	else {
    //		mouseMoveHandler(&mevent);
    //		mouseDownHandler(&mevent);
    //	}
    //	return true;
    //};
    //void World::onTouchEnded(Touch *touch, Event *event) {
    //	Node * node = event->getCurrentTarget();
    //	Vec2 tpos = touch->getLocationInView();
    //	tpos.y = Main::SCREEN_HEIGHT - tpos.y;
    //	if (!std::hitTest(node, tpos))return;
    //	if (!globalNode)EventNode::onTouchEnded(touch, event);
    //	Event::Type tp = event->getType();
    //	//logInfo("event targetNamePath", getNamePath(node));
    //	event->stopPropagation();

    //	if (EventNode::beginTouchNode && EventNode::beginTouchNode != node) {
    //		if (tpos.distance(EventNode::beginTouchPos) > 20) {
    //			MouseEvent mevent(cocos2d::EventMouse::MouseEventType::MOUSE_MOVE);
    //			mevent.setMouseButton(cocos2d::EventMouse::MouseButton::BUTTON_LEFT);
    //			mevent.setCursorPosition(tpos.x, tpos.y);
    //			mevent.setCurrentTarget(node);
    //			if (globalNode)
    //				globalNode->mouseMoveHandler(&mevent);
    //			//				else
    //			//					mouseMoveHandler(&mevent);
    //		}
    //	}
    //	EventNode::beginTouchNode = NULL;
    //	MouseEvent mevent(cocos2d::EventMouse::MouseEventType::MOUSE_UP);
    //	mevent.setMouseButton(cocos2d::EventMouse::MouseButton::BUTTON_LEFT);
    //	mevent.setCursorPosition(tpos.x, tpos.y);
    //	mevent.setCurrentTarget(node);
    //	if (globalNode)
    //		globalNode->mouseUpHandler(&mevent);
    //	//		else
    //	//			mouseUpHandler(&mevent);
    //};
    //void World::onTouchCancelled(Touch *touch, Event *unused_event) {

    //};
    //void World::onTouchMoved(Touch *touch, Event *event) {
    //	Vec2 tpos = touch->getLocationInView();
    //	tpos.y = Main::SCREEN_HEIGHT - tpos.y;
    //	Node * node = event->getCurrentTarget();
    //	if (!std::hitTest(node, tpos))return;
    //	if (!globalNode)EventNode::onTouchMoved(touch, event);
    //	Event::Type tp = event->getType();
    //	event->stopPropagation();
    //	MouseEvent mevent(cocos2d::EventMouse::MouseEventType::MOUSE_MOVE);
    //	mevent.setMouseButton(cocos2d::EventMouse::MouseButton::BUTTON_LEFT);
    //	mevent.setCursorPosition(tpos.x, tpos.y);
    //	mevent.setCurrentTarget(node);
    //	//node->setUserData((void*)1);
    //	if (globalNode)
    //		globalNode->mouseMoveHandler(&mevent);
    //	//		else
    //	//			mouseMoveHandler(&mevent);
    //};





    towers::Tower *World::addTower(std::string param1, BuildTowerPlace *param2, bool param3) {
        towers::Tower *tempObject = NULL;
        if (param1 == "tower1") {
            tempObject = new Tower1();
        } else if (param1 == "tower2") {
            tempObject = new Tower2();
        } else if (param1 == "tower3") {
            tempObject = new Tower3();
        } else if (param1 == "tower4") {
            tempObject = new Tower4();
        } else if (param1 == "tower5") {
            tempObject = new Tower5();
        } else if (param1 == "tower6") {
            tempObject = new Tower6();
        } else if (param1 == "tower7") {
            tempObject = new Tower7();
        } else if (param1 == "tower8") {
            tempObject = new Tower8();
        }
        tempObject->myPlace = param2;
        tempObject->autoBuild = param3;
        this->addChild(tempObject, 2);
        tempObject->init();
        this->listOfTowers.push(tempObject);
        //this->listOfTowers.sortOn("y", Array.NUMERIC);
        return tempObject;
    }// end function

    units::Unit *
    World::addUnit(int param1, int param2, int param3, float param4, int param5, int param6) {
        Unit *tempObject = NULL;
        if (param1 == 1) {
            tempObject = new Unit_1();// Unit_1::create();// new Unit_1();
        } else if (param1 == 2) {
            tempObject = new Unit_2();
        } else if (param1 == 3) {
            tempObject = new Unit_3();
        } else if (param1 == 4) {
            tempObject = new Unit_4();
        } else if (param1 == 5) {
            tempObject = new Unit_5();
        } else if (param1 == 6) {
            tempObject = new Unit_6();
        } else if (param1 == 7) {
            tempObject = new Unit_7();
        } else if (param1 == 8) {
            tempObject = new Unit_8();
        } else if (param1 == 9) {
            tempObject = new Unit_9();
        } else if (param1 == 10) {
            tempObject = new Unit_10();
        } else if (param1 == 11) {
            tempObject = new Unit_11();
        } else if (param1 == 12) {
            tempObject = new Unit_12();
        } else if (param1 == 13) {
            tempObject = new Unit_13();
        } else if (param1 == 14) {
            tempObject = new Unit_14();
        } else if (param1 == 15) {
            tempObject = new Unit_15();
        } else if (param1 == 16) {
            tempObject = new Unit_16();
        } else if (param1 == 17) {
            tempObject = new Unit_17();
        } else if (param1 == 18) {
            tempObject = new Unit_18();
        } else if (param1 == 19) {
            tempObject = new Unit_19();
        } else if (param1 == 20) {
            tempObject = new Unit_20();
        } else if (param1 == 21) {
            tempObject = new Unit_21();
        } else if (param1 == 22) {
            tempObject = new Unit_22();
        } else if (param1 == 23) {
            tempObject = new Unit_23();
        } else if (param1 == 24) {
            tempObject = new Unit_24();
        } else if (param1 == 25) {
            tempObject = new Unit_25();
        } else if (param1 == 26) {
            tempObject = new Unit_26();
        } else if (param1 == 27) {
            tempObject = new Unit_27();
        } else if (param1 == 28) {
            tempObject = new Unit_28();
        } else if (param1 == 29) {
            tempObject = new Unit_29();
        } else if (param1 == 30) {
            tempObject = new Unit_30();
        } else if (param1 == 31) {
            tempObject = new Unit_31();
        } else if (param1 == 32) {
            tempObject = new Unit_32();
        } else if (param1 == 33) {
            tempObject = new Unit_33();
        } else if (param1 == 34) {
            tempObject = new Unit_34();
        }

        tempObject->road = param2;
        if (param3 == 0) {
            tempObject->way = this->unitInputBezieArr[this->unitInputBezieCounter];
            if (this->unitInputBezieCounter < (this->unitInputBezieArr.size() - 1)) {
                this->unitInputBezieCounter++;
            } else {
                this->unitInputBezieCounter = 0;
            }
        } else {
            tempObject->way = param3;
        }
        tempObject->replacementFlag = param5;
        tempObject->gate = param6;
        tempObject->path = param4;
        this->addChild(tempObject, 2);
        tempObject->init();
        //tempObject->setPosition(50, 420);
        return tempObject;
    }

    Bullet *
    World::addBullet(int param1, cocos2d::Point param2, ShootBase *param3, units::Unit *param4,
                     float param5, int param6) {
        Bullet *tempObject1 = NULL;
        if (param1 == 1) {
            tempObject1 = new Bullet_1();
        } else if (param1 == 2) {
            tempObject1 = new Bullet_2();
        } else if (param1 == 3) {
            tempObject1 = new Bullet_3();
        } else if (param1 == 4) {
            tempObject1 = new Bullet_4();
        } else if (param1 == 5) {
            tempObject1 = new Bullet_5();
        } else if (param1 == 6) {
            tempObject1 = new Bullet_6();
        } else if (param1 == 61) {
            tempObject1 = new Bullet_61();
        } else if (param1 == 7) {
            tempObject1 = new Bullet_7();
        } else if (param1 == 8) {
            tempObject1 = new Bullet_8();
        } else if (param1 == 51) {
            tempObject1 = new Bullet_51();
        } else if (param1 == 81) {
            tempObject1 = new Bullet_81();
        }
        tempObject1->spherePower = param6;
        tempObject1->this_pt = param2;
        tempObject1->whoShoot = param3;
        tempObject1->enemyTarget = param4;
        tempObject1->damage = param5;
        this->addChild(tempObject1, 3);
        tempObject1->init();
        return tempObject1;
    }// end function

    void World::manageIndexes() {
        //if (this->frameCounter == 10 || this->frameCounter == 20 || this->frameCounter == 30 || this->forseIndexFl)
        //{
        //	if (this->forseIndexFl)
        //	{
        //		this->forseIndexFl = false;
        //	}
        //	//if (this->listOfIndexes0.size() > 0)
        //	//{
        //	//	//this->listOfIndexes0.sortOn(["y", "x"], [Array.NUMERIC, Array.NUMERIC]);
        //	//	//this->m = 0;
        //	//	//while (this->m < this->listOfIndexes0.size())
        //	//	//{
        //	//	//	this->setChildIndex(this->listOfIndexes0[this->m], (this->numChildren - 1));
        //	//	//	m++;
        //	//	//}
        //	//}
        //	this->sortIndex.clear();// = [];
        //	this->sortIndex = this->sortIndex.concat(this->listOfIndexes1);
        //	this->sortIndex = this->sortIndex.concat(this->listOfIndexes2);
        //	this->sortIndex = this->sortIndex.concat(this->listOfTowers);
        //	this->sortIndex = this->sortIndex.concat(this->listOfUnits);
        //	this->sortIndex = this->sortIndex.concat(this->listOfFlags);
        //	if (this->buildTowerMenu)
        //	{
        //		this->sortIndex.push(this->buildTowerMenu);
        //	}
        //	//this->sortIndex.sortOn(["y", "x"], [Array.NUMERIC, Array.NUMERIC]);
        //	//this->m = 0;
        //	//while (this->m < this->sortIndex.size())
        //	//{
        //	//	this->setChildIndex(this->sortIndex[this->m], (this->numChildren - 1));
        //	//	m++;
        //	//}
        //	if (this->listOfIndexes2.size() > 0)
        //	{
        //		this->sortIndex.clear();// = [];
        //		this->sortIndex = this->sortIndex.concat(this->listOfTowers);
        //		this->sortIndex = this->sortIndex.concat(this->listOfIndexes2);
        //		//this->sortIndex.sortOn(["y", "x"], [Array.NUMERIC, Array.NUMERIC]);
        //		this->indexesTemp1 = NULL;
        //		this->m = 0;
        //		while (this->m < this->sortIndex.size())
        //		{
        //			if (!(this->sortIndex[this->m] is Tower))
        //			{
        //				bool indexesTemp3 = false;
        //				if (this->sortIndex[this->m] is Bullet)
        //				{
        //					Bullet * bullet = (Bullet*)this->sortIndex[this->m];
        //					this->n = 0;
        //					while (this->n < this->listOfTowers.size())
        //					{
        //						if (this->listOfTowers[this->n]->getPositionY() > bullet->enemyTarget->getPositionY())
        //						{
        //							indexesTemp3 = true;
        //							this->setChildIndex(bullet, (this->getChildIndex(this->listOfTowers[this->n]) - 1));
        //							break;
        //						}
        //						n++;
        //					}
        //					if (!indexesTemp3)
        //					{
        //						this->setChildIndex(bullet, (this->numChildren - 1));
        //					}
        //				}
        //				else
        //				{
        //					if (this->sortIndex[this->m] is CastSphere)
        //					{
        //						CastSphere * castSphere = (CastSphere*)this->sortIndex[this->m];
        //						if (this->sortIndex[this->m]->sphereType == "getAll" && this->sortIndex[this->m]->container->haze1)
        //						{
        //							indexesTemp3 = true;
        //							tempObject4 = false;
        //							this->n = 0;
        //							while (this->n < this->listOfTowers.size())
        //							{
        //								int tempObject5 = 0;
        //								if (castSphere->container->haze1->isVisible() && this->listOfTowers[this->n]->getPositionY() > this->sortIndex[this->m]->container->haze1->myPoint.y + 30)
        //								{
        //									tempObject5++;
        //								}
        //								if (castSphere->container->haze2->isVisible() && this->listOfTowers[this->n]->getPositionY() > this->sortIndex[this->m]->container->haze2->myPoint.y + 30)
        //								{
        //									tempObject5++;
        //								}
        //								if (castSphere->container->haze3->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze3->myPoint.y + 30)
        //								{
        //									tempObject5++;
        //								}
        //								if (castSphere->container->haze4->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze4->myPoint.y + 30)
        //								{
        //									tempObject5++;
        //								}
        //								if (castSphere->container->haze5->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze5->myPoint.y + 30)
        //								{
        //									tempObject5++;
        //								}
        //								if (castSphere->container->haze6->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze6->myPoint.y + 30)
        //								{
        //									tempObject5++;
        //								}
        //								if (castSphere->container->haze7->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze7->myPoint.y + 30)
        //								{
        //									tempObject5++;
        //								}
        //								if (castSphere->container->haze8->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze8->myPoint.y + 30)
        //								{
        //									tempObject5++;
        //								}
        //								if (castSphere->container->haze9->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze9->myPoint.y + 30)
        //								{
        //									tempObject5++;
        //								}
        //								if (tempObject5 >= 3)
        //								{
        //									thistempObject4 = true;
        //									this->setChildIndex(castSphere, (this->getChildIndex(this->listOfTowers[this->n]) - 1));
        //									break;
        //								}
        //								n++;
        //							}
        //							if (!tempObject4)
        //							{
        //								this->setChildIndex(castSphere, (this->numChildren - 1));
        //							}
        //						}
        //					}
        //					if (!indexesTemp3)
        //					{
        //						this->n = 0;
        //						while (this->n < this->listOfTowers.size())
        //						{
        //							if (this->listOfTowers[this->n]->getPositionY() > this->sortIndex[this->m]->y)
        //							{
        //								indexesTemp3 = true;
        //								this->setChildIndex(this->sortIndex[this->m], (this->getChildIndex(this->listOfTowers[this->n]) - 1));
        //								break;
        //							}
        //							n++;
        //						}
        //						if (!this->indexesTemp3)
        //						{
        //							this->setChildIndex(this->sortIndex[this->m], (this->numChildren - 1));
        //						}
        //					}
        //				}
        //			}
        //			m++;
        //		}
        //	}
        //}
        //if (this->nowLevel == 15)
        //{
        //	if (this->levelAdditionally1->currentFrame != this->levelAdditionally1->totalFrames)
        //	{
        //		this->setChildIndex(this->levelAdditionally1, (this->numChildren - 1));
        //	}
        //	this->setChildIndex(this->levelAdditionally3, (this->numChildren - 1));
        //}
        //if (this->towerRadius->isVisible())
        //{
        //	this->setChildIndex(this->towerRadius, (this->numChildren - 1));
        //}
        //if (this->listOfIndexes3.size() > 0)
        //{
        //	this->m = 0;
        //	while (this->m < this->listOfIndexes3.size())
        //	{
        //		this->setChildIndex(this->listOfIndexes3[this->m], (this->numChildren - 1));
        //		m++;
        //	}
        //}
        //this->setChildIndex(this->pointer1, (this->numChildren - 1));
        //if (this->pointer2)
        //{
        //	this->setChildIndex(this->pointer2, (this->numChildren - 1));
        //}
        //if (this->pointer3)
        //{
        //	this->setChildIndex(this->pointer3, (this->numChildren - 1));
        //}
        //this->setChildIndex(this->worldInterface, (this->numChildren - 1));
        //if (this->road->isVisible())
        //{
        //	this->setChildIndex(this->road, (this->numChildren - 1));
        //}
        //if (this->towerMenu)
        //{
        //	this->setChildIndex(this->towerMenu->towerRadius, (this->numChildren - 1));
        //	this->setChildIndex(this->towerMenu->towerRadius1, (this->numChildren - 1));
        //	this->setChildIndex(this->towerMenu, (this->numChildren - 1));
        //	this->setChildIndex(this->towerMenu->hint, (this->numChildren - 1));
        //}
        //else if (this->ultraTowerMenu)
        //{
        //	this->setChildIndex(this->ultraTowerMenu, (this->numChildren - 1));
        //	this->setChildIndex(this->ultraTowerMenu->hint, (this->numChildren - 1));
        //}
        //this->m = 0;
        //while (this->m < this->listOfMoveSpheres.size())
        //{
        //	this->setChildIndex(this->listOfMoveSpheres[this->m], (this->numChildren - 1));
        //	m++;
        //}
        //if (this->getSphere)
        //{
        //	this->setChildIndex(this->getSphere, (this->numChildren - 1));
        //}
        //if (this->cast)
        //{
        //	this->setChildIndex(this->cast, (this->numChildren - 1));
        //}
        //if (this->exchange)
        //{
        //	this->setChildIndex(this->exchange->graphicAtMyTower, (this->numChildren - 1));
        //	this->setChildIndex(this->exchange, (this->numChildren - 1));
        //}
        //if (this->bezierClass)
        //{
        //	if (this->bezierClass->isVisible())
        //	{
        //		this->setChildIndex(this->bezierClass, (this->numChildren - 1));
        //		this->bezierClass.updateLine();
        //	}
        //}
        //if (this->trainingClass)
        //{
        //	this->setChildIndex(this->trainingClass, (this->numChildren - 1));
        //}
        //this->setChildIndex(this->hint, (this->numChildren - 1));
        //if (this->menuObject)
        //{
        //	this->setChildIndex(this->menuObject, (this->numChildren - 1));
        //}
        //return;
    }// end function

    void World::manageMouse(string param1) {
        if (param1 == "hide") {
            //Mouse.hide();
        } else if (param1 == "show") {
            //Mouse.show();
        }
        return;
    }// end function


    void World::manageListeners(string param1) {
        if (param1 == "on") {
            if (std::useGlobalNode)
                std::globalNode = this;
            this->enableMouseHandler(true);
            this->enableFrameHandler(true);
        } else if (param1 == "off") {
            this->disableMouseHandler();
            this->disableFrameHandler();
        }
        return;
    }// end function
    void World::deactivateHandler(cocos2d::EventMouse *event) {
        if (this->saveBox->getIntValue("complexityLevel") < 4) {
            if (this->wavesClass->nowWave > 0 && !this->menuObject) {
                this->worldInterface->addFastPause();
            }
        } else if (!this->menuObject) {
            this->worldInterface->addFastPause();
        }
        //return;
    }// end function

    void World::achieveManage(string param1) {
        string key = "achieve_" + param1;
        bool value = this->saveBox->getBoolValue(key);
        if (value)return;
        if (!this->saveBox->getBoolValue(key)) {
            this->saveBox->setValue(key, true);
            this->worldInterface->addGetAchieve(param1);
        }
        //net save
        return;

        if (param1 == "firstKill") {
            //if (Main::mainClass->IDIClass.idnet)
            //{
            //	if (Main::mainClass->IDIClass.idnet.userData)
            //	{
            //		Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U025), "83409581c3f54d89fab5", String(Main::mainClass->IDIClass.currentUser));
            //	}
            //}
        } else if (param1 == "kill_100_enemies") {
            //if (Main::mainClass->IDIClass.idnet)
            //{
            //	if (Main::mainClass->IDIClass.idnet.userData)
            //	{
            //		Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U026), "ccff354b538ba9d981c6", String(Main::mainClass->IDIClass.currentUser));
            //	}
            //}
        } else if (param1 == "kill_2500_enemies") {
            //if (Main::mainClass->IDIClass.idnet)
            //{
            //	if (Main::mainClass->IDIClass.idnet.userData)
            //	{
            //		Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U027), "11963b14f22a7bce56b1", String(Main::mainClass->IDIClass.currentUser));
            //	}
            //}
        } else if (param1 == "call_100_earlyWaves") {
            //if (Main::mainClass->IDIClass.idnet)
            //{
            //	if (Main::mainClass->IDIClass.idnet.userData)
            //	{
            //		Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U028), "9505fe07aec600010632", String(Main::mainClass->IDIClass.currentUser));
            //	}
            //}
        } else if (param1 == "build_100_towers") {
            //if (Main::mainClass->IDIClass.idnet)
            //{
            //	if (Main::mainClass->IDIClass.idnet.userData)
            //	{
            //		Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U029), "45b808416d58aa9ec362", String(Main::mainClass->IDIClass.currentUser));
            //	}
            //}
        } else if (param1 == "createGolem_5_times") {
            //if (Main::mainClass->IDIClass.idnet)
            //{
            //	if (Main::mainClass->IDIClass.idnet.userData)
            //	{
            //		Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U030), "4933337d00fe765e2d76", String(Main::mainClass->IDIClass.currentUser));
            //	}
            //}
        }
        //else if (param1 == "createIceman_15_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_createIceman_15_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_createIceman_15_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U031), "7cb9e2506e2cff60188e", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "createAir_7_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_createAir_7_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_createAir_7_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U032), "eae07af8c3fbf6969aaa", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "callAllWavesInLevel")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_callAllWavesInLevel)
        //	{
        //		this->saveBox.gameSave.data.achieve_callAllWavesInLevel = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U033), "29337500f9599ccc64dc", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "sellFireIceStoneLevin")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_sellFireIceStoneLevin)
        //	{
        //		this->saveBox.gameSave.data.achieve_sellFireIceStoneLevin = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U034), "ae6966c4ffcbf75ff494", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "sellFire_10_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_sellFire_10_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_sellFire_10_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U035), "de7be8dc61d39246d6d0", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "sellIce_10_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_sellIce_10_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_sellIce_10_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U036), "1f24299530577258bbf6", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "sellStone_10_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_sellStone_10_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_sellStone_10_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U037), "3c5c886f47920ec924d1", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "sellLevin_10_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_sellLevin_10_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_sellLevin_10_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U038), "6b63e564bf6e744f8e78", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "golemKill_250_enemies")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_golemKill_250_enemies)
        //	{
        //		this->saveBox.gameSave.data.achieve_golemKill_250_enemies = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U039), "052b407c061f43d90593", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "icemanSlowdown_75_enemies")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_icemanSlowdown_75_enemies)
        //	{
        //		this->saveBox.gameSave.data.achieve_icemanSlowdown_75_enemies = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U040), "cd3fd0815ded9b849e6d", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "icemanSlowdown_500_enemies")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_icemanSlowdown_500_enemies)
        //	{
        //		this->saveBox.gameSave.data.achieve_icemanSlowdown_500_enemies = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U041), "1c64fdbcbc270a0aa41c", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "buildUltraTower")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_buildUltraTower)
        //	{
        //		this->saveBox.gameSave.data.achieve_buildUltraTower = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U042), "955bdd689299e80fb0ae", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "buildUltraTower_50_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_buildUltraTower_50_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_buildUltraTower_50_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U043), "9a578115947a76ccdc7a", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "buildAllUltraTowers")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_buildAllUltraTowers)
        //	{
        //		this->saveBox.gameSave.data.achieve_buildAllUltraTowers = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U044), "225f541c6876ebd07590", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "notCast")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_notCast)
        //	{
        //		this->saveBox.gameSave.data.achieve_notCast = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U045), "81cb72a77902ea9d9e8a", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "castFire_150_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_castFire_150_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_castFire_150_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U046), "d622abbd1bed287c5680", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "castIce_150_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_castIce_150_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_castIce_150_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U047), "7484bbb391fe85f8bfd2", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "castStone_150_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_castStone_150_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_castStone_150_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U048), "7658bfe01730e286ab12", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "castLevin_150_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_castLevin_150_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_castLevin_150_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U049), "57af93676b7cc1bd8d7a", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "castGetAll_10_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_castGetAll_10_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_castGetAll_10_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U050), "0400fd8ee26fc4e6111e", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "castGetAll_100_times")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_castGetAll_100_times)
        //	{
        //		this->saveBox.gameSave.data.achieve_castGetAll_100_times = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U051), "252127936ed8d209e5d8", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "castKill_1_enemy")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_castKill_1_enemy)
        //	{
        //		this->saveBox.gameSave.data.achieve_castKill_1_enemy = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U052), "06235f228a30f51541a2", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "castKill_100_enemy")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_castKill_100_enemy)
        //	{
        //		this->saveBox.gameSave.data.achieve_castKill_100_enemy = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U053), "28108715890214c48efe", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "complete_10_hardLevels")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_complete_10_hardLevels)
        //	{
        //		this->saveBox.gameSave.data.achieve_complete_10_hardLevels = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U054), "7e8c5c8fda54a7f755a5", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "complete_10_survivalLevels")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_complete_10_survivalLevels)
        //	{
        //		this->saveBox.gameSave.data.achieve_complete_10_survivalLevels = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U055), "5252af2b31911dfec2ca", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "complete_10_withAllLives")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_complete_10_withAllLives)
        //	{
        //		this->saveBox.gameSave.data.achieve_complete_10_withAllLives = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U056), "be199456485a296baa27", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_01")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_01)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_01 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U057), "e52e865a96cad6434c71", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_02")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_02)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_02 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U058), "fbe8c2abc522477828ab", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_03")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_03)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_03 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U059), "de48d1b211ea73656394", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_04")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_04)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_04 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U060), "5e33b77fe8788d480d4d", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_05")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_05)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_05 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U061), "0b08fac999ba500f9e56", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_06")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_06)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_06 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U062), "28324f0179eb9d4a0c29", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_07")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_07)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_07 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U063), "8ec85ce03c6475fbcc58", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_08")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_08)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_08 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U064), "aee2716c8d18fa744acd", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_09")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_09)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_09 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U065), "59cb9735aadd73823c6b", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_10")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_10)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_10 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U066), "26fa27c7ac79a9ff0dbb", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_11")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_11)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_11 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U067), "25188a8e66ef59bf2504", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_12")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_12)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_12 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U068), "b79f6ade296b72ea2d3c", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_13")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_13)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_13 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U069), "1d2c8f2227466dde4a7b", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //else if (param1 == "achieve_dude_14")
        //{
        //	if (!this->saveBox.gameSave.data.achieve_dude_14)
        //	{
        //		this->saveBox.gameSave.data.achieve_dude_14 = true;
        //		this->worldInterface->addGetAchieve(param1);
        //		if (Main::mainClass->IDIClass.idnet)
        //		{
        //			if (Main::mainClass->IDIClass.idnet.userData)
        //			{
        //				Main::mainClass->IDIClass.idnet.achievementsSave(I18N_VALUE(I18N_CODE::U070), "1529e481b9b5e124cba2", String(Main::mainClass->IDIClass.currentUser));
        //			}
        //		}
        //	}
        //}
        //return;
    }// end function

    void World::reInit(cocos2d::EventMouse *event)//event:Event
    {
        //this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        //this->removeEventListener(Event.DEACTIVATE, this->deactivateHandler);

        //return;
    }// end function
    void World::removeClasses(BaseNode *node) {
        int i = listOfClasses.size() - 1;
        while (i >= 0) {
            if (listOfClasses.at(i) == node) {
                listOfClasses.remove(i);
                break;
            }
            i--;
        }
    };
    void World::removeDead(BaseNode *node) {
        int i = listOfDeads.size() - 1;
        while (i >= 0) {
            if (listOfDeads.at(i) == node) {
                listOfDeads.remove(i);
            }
            i--;
        }
    };
    void World::addDead(BaseNode *node) {
        int i = listOfDeads.size() - 1;
        while (i >= 0) {
            if (listOfDeads.at(i) == node)
                return;
            i--;
        }
        listOfDeads.push(node);
    };
    void World::addClasses(BaseNode *node) {
        int i = listOfClasses.size() - 1;
        while (i >= 0) {
            if (listOfClasses.at(i) == node)
                return;
            i--;
        }
        listOfClasses.push(node);
    };

    bool World::existClasses(BaseNode *node) {
        int i = listOfClasses.size() - 1;
        while (i >= 0) {
            if (listOfClasses.at(i) == node)
                return true;
            i--;
        }
        return false;
    };

    void World::removeIndexes(Node *node, int indexType) {
        return;
        int i = 0, len = 0;
        if (indexType == -1 || indexType == 0) {
            len = listOfIndexes0.size();
            while (i < len) {
                if (listOfIndexes0[i] == node) {
                    listOfIndexes0.remove(i);
                    break;
                }
                i++;
            }
        }
        if (indexType == -1 || indexType == 1) {
            len = listOfIndexes1.size();
            while (i < len) {
                if (listOfIndexes1[i] == node) {
                    listOfIndexes1.remove(i);
                    break;
                }
                i++;
            }
        }
        if (indexType == -1 || indexType == 2) {
            i = 0;
            len = listOfIndexes2.size();
            while (i < len) {
                if (listOfIndexes2[i] == node) {
                    listOfIndexes2.remove(i);
                    break;
                }
                i++;
            }
        }
        if (indexType == -1 || indexType == 3) {
            i = 0;
            len = listOfIndexes3.size();
            while (i < len) {
                if (listOfIndexes3[i] == node) {
                    listOfIndexes3.remove(i);
                    break;
                }
                i++;
            }
        }
    };

    void World::addIndexes(Node *node, int indexParam) {
        return;
        if (indexParam == 0) {
            listOfIndexes0.push(this);
        } else if (indexParam == 1) {
            listOfIndexes1.push(this);
        } else if (indexParam == 2) {
            listOfIndexes2.push(this);
        } else if (indexParam == 3) {
            listOfIndexes3.push(this);
        }
    }

    void World::removeUnit(units::Unit *unit) {
        int i = this->listOfUnits.size()-1;
        while (i >=0) {
            if (this->listOfUnits[i] == unit) {
                this->listOfUnits.remove(i);
                break;
            }
            i--;
        }
        i = this->listOfBullets.size() - 1;
        while (i >= 0) {
            if (this->listOfBullets[i]->enemyTarget == unit) {
                this->listOfBullets[i]->enemyTarget = NULL;
            }
            i--;
        }
    };

    void World::removeBullet(Bullet *blt) {
        int i = this->listOfBullets.size() - 1;
        while (i >= 0) {
            if (this->listOfBullets[i] == blt) {
                this->listOfBullets.remove(i);
                break;
            };
            i--;
        }
    };

    void World::removeChild(Node *child, bool cleanup /* = true */) {
        if (ISTYPE(BaseNode, child)) {
            removeClasses(ISTYPE(BaseNode, child));
            removeIndexes(ISTYPE(BaseNode, child));
        }
        BaseNode::removeChild(child, cleanup);
    };

}

