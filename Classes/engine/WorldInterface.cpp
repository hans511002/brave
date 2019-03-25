
#include "MainClass.h"
#include "World.h" 

#include "MoneyAdd.h"
#include "CastSphere.h"
#include "GetSphere.h"
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
#include "engine/towers/TowerMenu_mc.h"

#include "engine/casts/Map.h"
#include "engine/casts/Cast.h"

#include "screens/MiddleScreen.h"
#include "screens/PauseMenu.h"
#include "screens/FastPause.h"
#include "WorldInterface.h"

namespace engine
{
    WorldInterface::WorldInterface() :container(NULL), fasterFlag(0), world(NULL), castMask(NULL), lastTime(NULL), sellHint(NULL), getAllHint(NULL), fireCount(0), iceCount(0), stoneCount(0), levinCount(0), getAllCount(0), fireBuyHistory(0), iceBuyHistory(0), stoneBuyHistory(0), levinBuyHistory(0), blockCastGolem(false), blockCastIceman(false), blockCastAir(false), castGolemCounter(0), castIcemanCounter(0), castAirCounter(0), castGolemTimer(0), castIcemanTimer(0), castAirTimer(0)
	{
		//this->sphereCostHistory = [[], [], [], []];
		this->sphereCostHistory[0].clear();
		this->sphereCostHistory[1].clear();
		this->sphereCostHistory[2].clear();
		this->sphereCostHistory[3].clear();
		//this->listOfNewEnemies = [];
		//this->listOfGetAhieve = [];
		//this->listOfAnimation = [];
		//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
	}// end function

	bool WorldInterface::init()// (event:Event) : void
	{
		BaseNode::init();
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		this->world = Main::mainClass->worldClass;
		//////////////////////////begin////////////////////////////////
		this->setPosition(Vec2(0,0)-this->world->getPosition());
		this->setMouseChildren(false);
		this->setMouseEnabled(false);
		//this->setAlpha(0);
		this->container = new WorldInterface_mc();
		this->addChild(this->container);
		this->container->init();
		//printChildNodes();
		 
		//this->container->stop();

		this->container->fireBack->stop();
		this->container->iceBack->stop();
		this->container->stoneBack->stop();
		this->container->levinBack->stop();
		//this->container->backComponents->stop();
		this->container->fireSphere->stop();
		this->container->iceSphere->stop();
		this->container->stoneSphere->stop();
		this->container->levinSphere->stop();
		this->container->getAll->stop();
		this->container->buyFire->stop();
		printNodePos(this->container->buyFireBuyTXT);

		this->container->buyIce->stop();
		this->container->buyStone->stop();
		this->container->buyLevin->stop();
		this->container->buyGetAll->stop();
		this->container->buyFireCoin->stop();
		this->container->buyIceCoin->stop();
		this->container->buyStoneCoin->stop();
		this->container->buyLevinCoin->stop();
		this->container->buyGetAllCoin->stop(); 
		this->container->sell->stop();
		this->container->book->stop();
		this->container->pause->stop();
		this->container->startWaves->stop();
		this->container->butCastGolem->stop();
		this->container->butCastIceman->stop();
		this->container->butCastAir->stop();
		//this->container->barInfo->stop();
		//this->container->slow->stop();
		this->container->fast->stop();
		//this->container->traceBezier->stop();
		//this->container->barInfo->setPositionY(15);//Main:: - 585
		this->container->bookBookCase->setMouseEnabled(true);
		this->container->pausePauseCase->setMouseEnabled(true);
		this->container->startWavesStartWavesCase->setMouseEnabled(true);
		this->container->butCastGolemCastGolemCase->setMouseEnabled(true);
		this->container->butCastIcemanCastIcemanCase->setMouseEnabled(true);
		this->container->butCastAirCastAirCase->setMouseEnabled(true);
		//this->container->slow->setMouseEnabled(true);
		//if (this->container->traceBezier)this->container->traceBezier->setMouseEnabled(true);
		//this->container->fireNumTXT->setMouseEnabled(false);
		//this->container->iceNumTXT->setMouseEnabled(false);
		//this->container->stoneNumTXT->setMouseEnabled(false);
		//this->container->levinNumTXT->setMouseEnabled(false);
		//this->container->barInfo->setMouseChildren(false);
		//this->container->barInfo->setMouseEnabled(false);
		//this->container->lastTime->setMouseEnabled(false);

		this->container->butCastGolem->setAlpha(0);
		this->container->butCastIceman->setAlpha(0);
		this->container->butCastAir->setAlpha(0);

		this->container->butCastGolem->setVisible(false);
		this->container->butCastIceman->setVisible(false);
		this->container->butCastAir->setVisible(false);
		//this->container->barInfo->setVisible(false);

		this->container->lastTime->setVisible(false);
		//this->container->buyFireLightUp->setVisible(false);
		//this->container->buyIceLightUp->setVisible(false);
		//this->container->buyStoneLightUp->setVisible(false);
		//this->container->buyLevinLightUp->setVisible(false);
		//this->container->buyGetAllLightUp->setVisible(false);


		//		this->container->backComponents.cacheAsBitmap = true;
		this->container->fireSphereMyPoint = CONVERT_TO_WORLD_POS(this->container->fireSphere->localToGlobal(this->container->fireSphereSphereCase->getPosition()));
		this->container->iceSphereMyPoint = CONVERT_TO_WORLD_POS(this->container->iceSphere->localToGlobal(this->container->iceSphereSphereCase->getPosition()));
		this->container->stoneSphereMyPoint = CONVERT_TO_WORLD_POS(this->container->stoneSphere->localToGlobal(this->container->stoneSphereSphereCase->getPosition()));
		this->container->levinSphereMyPoint = CONVERT_TO_WORLD_POS(this->container->levinSphere->localToGlobal(this->container->levinSphereSphereCase->getPosition()));
		this->container->getAllMyPoint = CONVERT_TO_WORLD_POS(this->container->getAll->localToGlobal(this->container->getAllSphereCase->getPosition()));
		this->castGolemTimer = Main::mainClass->readXMLClass.intervalTimerGolemXML;
		this->castIcemanTimer = Main::mainClass->readXMLClass.intervalTimerIcemanXML;
		this->castAirTimer = Main::mainClass->readXMLClass.intervalTimerAirXML;
		this->container->fireBacklightTurnFlag = true;
		this->container->iceBacklightTurnFlag = true;
		this->container->stoneBacklightTurnFlag = true;
		this->container->levinBacklightTurnFlag = true;
		this->container->fireBacklight->stop();
		this->container->iceBacklight->stop();
		this->container->stoneBacklight->stop();
		this->container->levinBacklight->stop();
		this->container->fireBacklight->setVisible(false);
		this->container->iceBacklight->setVisible(false);
		this->container->stoneBacklight->setVisible(false);
		this->container->levinBacklight->setVisible(false);
		this->container->buyGetAll->setVisible(false);
		//this->container->testRestart->stop();
		//this->container->testRestartBoard->stop();
		//this->container->testRestart->setMouseEnabled(true);
		//if (Main::mainClass->readXMLClass.bezierBuildXML)
		//{
		//	this->world->bezierClass->tracePoints = this->container->traceBezier;
		//	this->world->bezierClass->tracePoints.addEventListener(MouseEvent.CLICK, this->world->bezierClass->tracePointsArr);
		//}
		//else
		//{
		//	this->container->traceBezier->setVisible( false);
		//}
		this->lastTime = this->container->lastTime;
		
		if (!this->world)
		{
			return true;
		}
		
		//this->container->removeChild(this->lastTime);
		//this->world->addChild(this->lastTime);

		int complexityLevel = this->world->saveBox->getIntValue("complexityLevel");
		if (complexityLevel == 4)
		{
			this->world->addIndexes(this->lastTime,3);
		}
		//this->container->testRestart->setVisible(false);
		//this->container->testRestartBoard->setVisible(false);
		//this->container->slow->setVisible(false);




		//this->container->startWaves->addClickEventListener(CC_CALLBACK_1(WorldInterface::clickHandler, this);
		//this->container->fastbtn->addClickEventListener(CC_CALLBACK_1(WorldInterface::clickHandler, this);
		//EventListenerTouchOneByOne *touchListener = EventListenerTouchOneByOne::create();
		//touchListener->onTouchBegan = [this->(Touch *touch, Event *event){
		//    return this->onTouchBegan(touch, event);
		//};
		//touchListener->onTouchEnded = [this->(Touch *touch, Event *event){
		//    return this->onTouchEnded(touch, event);
		//};
		//Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, point);

		this->castMask = new CastMask_mc();
		this->castMask->stop();
		this->castMask->fireCase->stop();
		this->castMask->iceCase->stop();
		this->castMask->stoneCase->stop();
		this->castMask->levinCase->stop();
		this->castMask->getAllCase->stop();
		this->castMask->archiveCase->stop();
		this->castMask->interfaceUpCase->stop();
		this->castMask->sellCase->stop();
		this->castMask->setVisible(false);

		this->addChild(this->castMask,1);
		this->world->forseIndexFl = true;
		//测试cast
		//this->blockCastGolem = true;
		//this->blockCastIceman = true;
		//this->blockCastAir = true;
		return true;
	};

	void WorldInterface::onEnter(){
		this->spheresBlockManage();
		BaseNode::onEnter();

	};


	//void WorldInterface::clickHandler(Ref* ref)
	//{
	//    ui::Button * node = (ui::Button *)ref;
	//    string target = node->getName();
	//    CCLOG("startWavesCallback %s", target.c_str());
	//    if (target == "startWaves")
	//    {
	//
	//    }
	//    else  if (target == "fastbtn")
	//    {
	//
	//    }
	//};

	//bool WorldInterface::onTouchBegan(Touch* touch, Event* event)
	//{
	//    Node * node = event->getCurrentTarget();
	//    Event::Type tp = event->getType();
	//    string target = node->getName();
	//
	//    return true;
	//}
	//void WorldInterface::onTouchEnded(Touch* touch, Event* event)
	//{
	//    Node * node = event->getCurrentTarget();
	//    Event::Type tp = event->getType();
	//    string target = node->getName();
	//    CCLOG("WorldInterface::onTouchEnded %s", target.c_str());
	//    return;
	//}

	void WorldInterface::update(float dt){
		if (this->mouseEnabled)
		{
			if (this->container->fastCont->isReady)
			{
				if (this->world->frameCounter % 2)
				{
					if (this->container->fastCont->currentFrame < this->container->fastCont->totalFrames)
					{
						this->container->fastCont->tryPlay();
					    //this->container->fastCont->gotoAndStop((this->container->fastCont->currentFrame + 1));
					}
					else
					{
						this->container->fastCont->gotoAndStop(1);
					}
				}
			}
			if (this->container->pauseOpenFlag)
			{
				if (this->container->pause->currentFrame < (this->container->pause->totalFrames - 1))
				{
					this->container->pause->tryPlay();
					//this->container->pause->gotoAndStop((this->container->pause->currentFrame + 1));
				}
				else
				{
					this->container->pauseOpenFlag = false;
				}
			}
			else if (this->container->pauseCloseFlag)
			{
				if (this->container->pause->currentFrame > 1 && this->container->pause->currentFrame < this->container->pause->totalFrames)
				{
					this->container->pause->gotoAndStop((this->container->pause->currentFrame - 1));
				}
				else
				{
					this->container->pauseCloseFlag = false;
				}
			}
			if (this->container->bookOpenFlag)
			{
				if (this->container->book->currentFrame < (this->container->book->totalFrames - 1))
				{
					this->container->book->tryPlay();
					//this->container->book->gotoAndStop((this->container->book->currentFrame + 1));
				}
				else
				{
					this->container->bookOpenFlag = false;
				}
			}
			else if (this->container->bookCloseFlag)
			{
				if (this->container->book->currentFrame > 1 && this->container->book->currentFrame < this->container->book->totalFrames)
				{
					//this->container->book->tryPlay();
					this->container->book->gotoAndStop((this->container->book->currentFrame - 1));
				}
				else
				{
					this->container->bookCloseFlag = false;
				}
			}
			if (this->fireCount > 0)
			{
				if (this->container->fireSphere->currentFrame < this->container->fireSphere->totalFrames)
				{
					this->container->fireSphere->tryPlay();
					//this->container->fireSphere->gotoAndStop((this->container->fireSphere->currentFrame + 1));
				}
				else
				{
					this->container->fireSphere->gotoAndStop(1);
				}
			}
			if (this->iceCount > 0)
			{
				if (this->container->iceSphere->currentFrame < this->container->iceSphere->totalFrames)
				{
					this->container->iceSphere->tryPlay();
					//this->container->iceSphere->gotoAndStop((this->container->iceSphere->currentFrame + 1));
				}
				else
				{
					this->container->iceSphere->gotoAndStop(1);
				}
			}
			if (this->stoneCount > 0)
			{
				if (this->container->stoneSphere->currentFrame < this->container->stoneSphere->totalFrames)
				{
					this->container->stoneSphere->tryPlay();
					//this->container->stoneSphere->gotoAndStop((this->container->stoneSphere->currentFrame + 1));
				}
				else
				{
					this->container->stoneSphere->gotoAndStop(1);
				}
			}
			if (this->levinCount > 0)
			{
				if (this->container->levinSphere->currentFrame < this->container->levinSphere->totalFrames)
				{
					this->container->levinSphere->tryPlay();
					//this->container->levinSphere->gotoAndStop((this->container->levinSphere->currentFrame + 1));
				}
				else
				{
					this->container->levinSphere->gotoAndStop(1);
				}
			}
			if (this->getAllCount > 0)
			{
				if (this->container->getAllFire->isReady)
				{
					if (this->container->getAllFire->currentFrame < this->container->getAllFire->totalFrames)
					{
						this->container->getAllFire->tryPlay();
					    //this->container->getAllFire->gotoAndStop((this->container->getAllFire->currentFrame + 1));
					}
					else
					{
						this->container->getAllFire->gotoAndStop(1);
					}
					if (this->container->getAllIce->currentFrame < this->container->getAllIce->totalFrames)
					{
						this->container->getAllIce->tryPlay();
					    //this->container->getAllIce->gotoAndStop((this->container->getAllIce->currentFrame + 1));
					}
					else
					{
						this->container->getAllIce->gotoAndStop(1);
					}
					if (this->container->getAllStone->currentFrame < this->container->getAllStone->totalFrames)
					{
						this->container->getAllStone->tryPlay();
					    //this->container->getAllStone->gotoAndStop((this->container->getAllStone->currentFrame + 1));
					}
					else
					{
						this->container->getAllStone->gotoAndStop(1);
					}
					if (this->container->getAllLevin->currentFrame < this->container->getAllLevin->totalFrames)
					{
						this->container->getAllLevin->tryPlay();
					    //this->container->getAllLevin->gotoAndStop((this->container->getAllLevin->currentFrame + 1));
					}
					else
					{
						this->container->getAllLevin->gotoAndStop(1);
					}
				}
			}
			if (this->container->startWaves->currentFrame <= 10)
			{
				if (this->container->startWaves->currentFrame < 10)
				{
					this->container->startWaves->tryPlay();
					//this->container->startWaves->gotoAndStop((this->container->startWaves->currentFrame + 1));
				}
				else
				{
					this->container->startWaves->gotoAndStop(1);
				}
			}
			else if (this->container->startWaves->currentFrame <= 20)
			{
				if (this->container->startWaves->currentFrame < 20)
				{
					this->container->startWaves->tryPlay();
					//this->container->startWaves->gotoAndStop((this->container->startWaves->currentFrame + 1));
				}
				else
				{
					this->container->startWaves->gotoAndStop(11);
				}
			}
			if (!this->blockCastGolem)
			{
				if (this->container->butCastGolem->isVisible())
				{
					if (this->container->butCastGolem->getAlpha() < 1)
					{
						this->container->butCastGolem->setAlpha(this->container->butCastGolem->getAlpha() + 0.2);
					}
					else
					{
						this->blockCastGolem = true;
						this->container->butCastGolem->setAlpha(1);
						this->autoguidersButtons();
					}
				}
				else
				{
					this->container->butCastGolem->setVisible(true);
				}
			}
			if (!this->blockCastIceman)
			{
				if (this->container->butCastIceman->isVisible())
				{
					if (this->container->butCastIceman->getAlpha() < 1)
					{
						this->container->butCastIceman->setAlpha(this->container->butCastIceman->getAlpha() + 0.2);
					}
					else
					{
						this->blockCastIceman = true;
						this->container->butCastIceman->setAlpha(1);
						this->autoguidersButtons();
					}
				}
				else
				{
					this->container->butCastIceman->setVisible(true);
				}
			}
			if (!this->blockCastAir)
			{
				if (this->container->butCastAir->isVisible())
				{
					if (this->container->butCastAir->getAlpha() < 1)
					{
						this->container->butCastAir->setAlpha(this->container->butCastAir->getAlpha() + 0.2);
					}
					else
					{
						this->blockCastAir = true;
						this->container->butCastAir->setAlpha(1);
						this->autoguidersButtons();
					}
				}
				else
				{
					this->container->butCastAir->setVisible(true);
				}
			}
			if (this->container->fireSphere->isVisible())
			{
				if (!this->container->fireSphereOpened)
				{
					if (this->container->fireSphere->getAlpha() < 1)
					{
						if (this->container->fireBack->currentFrame != 1)
						{
							this->container->fireBack->gotoAndStop(1);
						}
						this->container->fireSphere->setAlpha(this->container->fireSphere->getAlpha() + 0.2);
						this->container->fireNumTXT->setAlpha(this->container->fireNumTXT->getAlpha() + 0.2);
						this->container->buyFire->setAlpha(this->container->buyFire->getAlpha() + 0.2);
					}
					else if (this->container->fireSphere->getScaleX() < 1)
					{
						this->container->fireSphere->setScaleX(this->container->fireSphere->getScaleX() + 0.25);
						this->container->fireSphere->setScaleY(this->container->fireSphere->getScaleY() + 0.25);
					}
					else
					{
						this->container->fireSphereOpened = true;
						this->spheresBlockManage("unblockFire");
					}
				}
			}
			if (this->container->iceSphere->isVisible())
			{
				if (!this->container->iceSphereOpened)
				{
					if (this->container->iceSphere->getAlpha() < 1)
					{
						if (this->container->iceBack->currentFrame != 1)
						{
							this->container->iceBack->gotoAndStop(1);
						}
						this->container->iceSphere->setAlpha(this->container->iceSphere->getAlpha() + 0.2);
						this->container->iceNumTXT->setAlpha(this->container->iceNumTXT->getAlpha() + 0.2);
						this->container->buyIce->setAlpha(this->container->buyIce->getAlpha() + 0.2);
					}
					else if (this->container->iceSphere->getScaleX() < 1)
					{
						this->container->iceSphere->setScaleX(this->container->iceSphere->getScaleX() + 0.25);
						this->container->iceSphere->setScaleY(this->container->iceSphere->getScaleY() + 0.25);
					}
					else
					{
						this->container->iceSphereOpened = true;
						this->spheresBlockManage("unblockIce");
					}
				}
			}
			if (this->container->stoneSphere->isVisible())
			{
				if (!this->container->stoneSphereOpened)
				{
					if (this->container->stoneSphere->getAlpha() < 1)
					{
						if (this->container->stoneBack->currentFrame != 1)
						{
							this->container->stoneBack->gotoAndStop(1);
						}
						this->container->stoneSphere->setAlpha(this->container->stoneSphere->getAlpha() + 0.2);
						this->container->stoneNumTXT->setAlpha(this->container->stoneNumTXT->getAlpha() + 0.2);
						this->container->buyStone->setAlpha(this->container->buyStone->getAlpha() + 0.2);
					}
					else if (this->container->stoneSphere->getScaleX() < 1)
					{
						this->container->stoneSphere->setScaleX(this->container->stoneSphere->getScaleX() + 0.25);
						this->container->stoneSphere->setScaleY(this->container->stoneSphere->getScaleY() + 0.25);
					}
					else
					{
						this->container->stoneSphereOpened = true;
						this->spheresBlockManage("unblockStone");
					}
				}
			}
			if (this->container->levinSphere->isVisible())
			{
				if (!this->container->levinSphereOpened)
				{
					if (this->container->levinSphere->getAlpha() < 1)
					{
						if (this->container->levinBack->currentFrame != 1)
						{
							this->container->levinBack->gotoAndStop(1);
						}
						this->container->levinSphere->setAlpha(this->container->levinSphere->getAlpha() + 0.2);
						this->container->levinNumTXT->setAlpha(this->container->levinNumTXT->getAlpha() + 0.2);
						this->container->buyLevin->setAlpha(this->container->buyLevin->getAlpha() + 0.2);
					}
					else if (this->container->levinSphere->getScaleX() < 1)
					{
						this->container->levinSphere->setScaleX(this->container->levinSphere->getScaleX() + 0.25);
						this->container->levinSphere->setScaleY(this->container->levinSphere->getScaleY() + 0.25);
					}
					else
					{
						this->container->levinSphereOpened = true;
						this->spheresBlockManage("unblockLevin");
					}
				}
			}
			if (!this->container->getAllOpened)
			{
				if (this->container->fireSphere->isVisible() && this->container->iceSphere->isVisible() && this->container->stoneSphere->isVisible() && this->container->levinSphere->isVisible())
				{
					if (Main::mainClass->saveBoxClass->getIntValue("saveNo") > 3)
					{
						if (Main::mainClass->readXMLClass.towerSlotBlock == 0)
						{
							if (this->container->getAll->getAlpha() < 1)
							{
								this->container->getAll->setAlpha(this->container->getAll->getAlpha() + 0.2);
								this->container->getAll->setAlpha(this->container->getAll->getAlpha() + 0.2);
								this->container->buyGetAll->setAlpha(this->container->buyGetAll->getAlpha() + 0.2);
							}
							else if (this->container->getAll->getScaleX() < 1)
							{
								this->container->getAll->setScaleX(this->container->getAll->getScaleX() + 0.25);
								this->container->getAll->setScaleY(this->container->getAll->getScaleY() + 0.25);
							}
							else
							{
								this->container->getAllOpened = true;
								this->spheresBlockManage("unblockGetAll");
							}
						}
					}
					else
					{
						this->container->getAllOpened = true;
					}
				}
			}
			this->downloadCast();
			//if (this->world->selectObject)
			//{
			//	//if (!this->container->barInfo->isVisible())
			//	//{
			//	//	this->container->barInfo->setVisible(true);
			//	//}
			//	//this->barInfoView();
			//}
			//else if (this->container->barInfo->isVisible())
			//{
			//	this->container->barInfo->setVisible(false);
			//}
			this->newEnemyUpdate();
			if (this->container->fireBacklight->isVisible())
			{
				if (this->container->fireBacklight->currentFrame > 1)
				{
					if (this->container->fireBacklight->currentFrame < this->container->fireBacklight->totalFrames)
					{
						this->container->fireBacklight->tryPlay();
						//this->container->fireBacklight->gotoAndStop((this->container->fireBacklight->currentFrame + 1));
					}
					else if (!this->container->fireBacklightTurnFlag)
					{
						this->container->fireBacklightTurnFlag = true;
						this->container->fireBacklight->gotoAndStop(2);
					}
				}
			}
			if (this->container->iceBacklight->isVisible())
			{
				if (this->container->iceBacklight->currentFrame > 1)
				{
					if (this->container->iceBacklight->currentFrame < this->container->iceBacklight->totalFrames)
					{
						this->container->iceBacklight->tryPlay();
						//this->container->iceBacklight->gotoAndStop((this->container->iceBacklight->currentFrame + 1));
					}
					else if (!this->container->iceBacklightTurnFlag)
					{
						this->container->iceBacklightTurnFlag = true;
						this->container->iceBacklight->gotoAndStop(2);
					}
				}
			}
			if (this->container->stoneBacklight->isVisible())
			{
				if (this->container->stoneBacklight->currentFrame > 1)
				{
					if (this->container->stoneBacklight->currentFrame < this->container->stoneBacklight->totalFrames)
					{
						this->container->stoneBacklight->tryPlay();
						//this->container->stoneBacklight->gotoAndStop((this->container->stoneBacklight->currentFrame + 1));
					}
					else if (!this->container->stoneBacklightTurnFlag)
					{
						this->container->stoneBacklightTurnFlag = true;
						this->container->stoneBacklight->gotoAndStop(2);
					}
				}
			}
			if (this->container->levinSphere->isVisible())
			{
				if (this->container->levinBacklight->currentFrame > 1)
				{
					if (this->container->levinBacklight->currentFrame < this->container->levinBacklight->totalFrames)
					{
					    this->container->levinBacklight->tryPlay();
						//this->container->levinBacklight->gotoAndStop((this->container->levinBacklight->currentFrame + 1));
					}
					else if (!this->container->levinBacklightTurnFlag)
					{
						this->container->levinBacklightTurnFlag = true;
						this->container->levinBacklight->gotoAndStop(2);
					}
				}
			}
			this->hintUpdate();
			if (this->container->fireBack->currentFrame == 2)
			{
				if (this->container->fireBackCont->currentFrame < this->container->fireBackCont->totalFrames)
				{
					this->container->fireBackCont->gotoAndStop(this->container->fireBackCont->currentFrame + 2);
				}
				else
				{
					this->container->fireBackCont->gotoAndStop(1);
				}
			}
			else if (this->container->iceBack->currentFrame == 2)
			{
				if (this->container->iceBackCont->currentFrame < this->container->iceBackCont->totalFrames)
				{
					this->container->iceBackCont->gotoAndStop(this->container->iceBackCont->currentFrame + 2);
				}
				else
				{
					this->container->iceBackCont->gotoAndStop(1);
				}
			}
			else if (this->container->stoneBack->currentFrame == 2)
			{
				if (this->container->stoneBackCont->currentFrame < this->container->stoneBackCont->totalFrames)
				{
					this->container->stoneBackCont->gotoAndStop(this->container->stoneBackCont->currentFrame + 2);
				}
				else
				{
					this->container->stoneBackCont->gotoAndStop(1);
				}
			}
			else if (this->container->levinBack->currentFrame == 2)
			{
				if (this->container->levinBackCont->currentFrame < this->container->levinBackCont->totalFrames)
				{
					this->container->levinBackCont->gotoAndStop(this->container->levinBackCont->currentFrame + 2);
				}
				else
				{
					this->container->levinBackCont->gotoAndStop(1);
				}
			}
			if (this->listOfGetAhieve.size() > 0)
			{
				this->i = this->listOfGetAhieve.size() - 1;
				while (this->i >= 0)
				{
					if (!this->listOfGetAhieve[this->i]->closeFlag)
					{
						if (this->listOfGetAhieve[this->i]->currentFrame < this->listOfGetAhieve[this->i]->totalFrames)
						{
						    this->listOfGetAhieve[this->i]->tryPlay();
							//this->listOfGetAhieve[this->i]->gotoAndStop((this->listOfGetAhieve[this->i]->currentFrame + 1));
							std::setText(this->listOfGetAhieve[this->i]->boardNoteTXT, this->listOfGetAhieve[this->i]->myText);
						}
						else if (this->listOfGetAhieve[this->i]->counter > 0)
						{
							this->listOfGetAhieve[this->i]->counter--;
						}
						else
						{
							this->listOfGetAhieve[this->i]->closeFlag = true;
						}
						this->listOfGetAhieve[this->i]->setPositionY(20 +42);// - 42
						//this->listOfGetAhieve[this->i]->setPositionY(this->container->barInfo->getPositionY() + 42);// - 42
					}
					else if (this->listOfGetAhieve[this->i]->currentFrame > 1)
					{
						this->listOfGetAhieve[this->i]->gotoAndStop((this->listOfGetAhieve[this->i]->currentFrame - 1));
						std::setText(this->listOfGetAhieve[this->i]->boardNoteTXT, this->listOfGetAhieve[this->i]->myText);
					}
					else
					{
						this->removeChild(this->listOfGetAhieve[this->i]);
						this->listOfGetAhieve.splice(this->i, 1);
					}
					i--;
				}
			}
			if (this->listOfAnimation.size() > 0)
			{
				this->i = this->listOfAnimation.size() - 1;
				while (this->i >= 0)
				{
					if (this->listOfAnimation[this->i]->currentFrame < this->listOfAnimation[this->i]->totalFrames)
					{
						this->listOfAnimation[this->i]->tryPlay();
						//this->listOfAnimation[this->i]->gotoAndStop((this->listOfAnimation[this->i]->currentFrame + 1));
					}
					else
					{
						this->removeChild(this->listOfAnimation[this->i]);
						this->listOfAnimation.splice(this->i, 1);
					}
					i--;
				}
			}
		}
		else if (this->getAlpha() < 1)
		{
			this->setAlpha(this->getAlpha() + 0.2);
		}
		else
		{
			this->setMouseChildren(true);
			this->setMouseEnabled(true);
			this->setAlpha(1);
		}
		return;
	};

	void WorldInterface::mouseDownHandler(cocos2d::EventMouse *e)//(event:MouseEvent) : void
	{
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
        string targetName=event->target->getName();
		logInfo("mouseMoveHandler.target", getNamePath(event->target));
		if (!this->world->getSphere && !this->world->cast)
		{ 
			if(targetName == "fastCase")
			{
                event->processed = true;
                if(ISTYPE(EventNode, event->target)->mouseEnabled)
				{
					if (this->container->fast->currentFrame == 2 || this->container->fast->currentFrame == 5)
					{
						this->container->fast->gotoAndStop((this->container->fast->currentFrame + 1));
						AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
					}
				}
            }
            else if(targetName == "pauseCase")
			{
                event->processed = true;
                if(this->container->pause->currentFrame != this->container->pause->totalFrames)
				{
					this->container->pause->gotoAndStop(this->container->pause->totalFrames);
					this->container->pauseOpenFlag = false;
					this->container->pauseCloseFlag = false;
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
            }
            else if(targetName == "bookCase")
			{
                event->processed = true;
                if(this->container->book->currentFrame != this->container->book->totalFrames)
				{
					this->container->book->gotoAndStop(this->container->book->totalFrames);
					this->container->bookOpenFlag = false;
					this->container->bookCloseFlag = false;
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
            }
            else if(targetName == "sphereCase")
			{
                event->processed = true;
                if(ISTYPE(EventNode, event->target)->mouseEnabled)
				{
					this->i = 0;
					while (this->i < this->world->listOfMoveSpheres.size())
					{
						if (this->world->listOfMoveSpheres[this->i]->speedFrame > 0)
						{
							this->world->listOfMoveSpheres[this->i]->speedFrame = 0;
						}
						i++;
					}
					this->world->feature->listOfMoveSpheres();
                    Node * parent = event->target->getParent()->getParent();//display -> dbdisplay
                    string parName = parent->getName();
                    if(parName == "fireSphere")
					{
						if (this->fireCount == 0)
						{
							this->archiveManage("buy", "fire");
						}
						AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
						this->archiveManage("get", "fire");
					}
                    else if(parName == "iceSphere")
					{
						if (this->iceCount == 0)
						{
							this->archiveManage("buy", "ice");
						}
						AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
						this->archiveManage("get", "ice");
					}
                    else if(parName == "stoneSphere")
					{
						if (this->stoneCount == 0)
						{
							this->archiveManage("buy", "stone");
						}
						AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
						this->archiveManage("get", "stone");
					}
                    else if(parName == "levinSphere")
					{
						if (this->levinCount == 0)
						{
							this->archiveManage("buy", "levin");
						}
						AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
						this->archiveManage("get", "levin");
					}
                    else if(parName == "getAll")
					{
						if (this->getAllCount == 0)
						{
							this->archiveManage("buy", "getAll");
						}
						AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
						this->archiveManage("get", "getAll");
					}
					if (this->world->getSphere)
					{
						if (this->world->getSphere->getAllCount == 0)
						{
							if (this->world->towerMenu)
							{
								if (this->world->towerMenu->myTower->spheresManage("scan") > 0)
								{
									this->world->getSphere->getSphereFromArchiveToTower();
								}
							}
							else if (this->world->ultraTowerMenu)
							{
								if (this->world->ultraTowerMenu->myTower->spheresManage("scan") > 0)
								{
									if (this->world->ultraTowerMenu->myTower->towerType == 5)
									{
										if (this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
										{
											if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[0])
											{
												this->world->getSphere->getSphereFromArchiveToTower();
											}
										}
										else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount == 0)
										{
											if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[2])
											{
												this->world->getSphere->getSphereFromArchiveToTower();
											}
										}
									}
									else if (this->world->ultraTowerMenu->myTower->towerType == 6)
									{
										if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
										{
											if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[1])
											{
												this->world->getSphere->getSphereFromArchiveToTower();
											}
										}
										else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount > 0)
										{
											if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[3])
											{
												this->world->getSphere->getSphereFromArchiveToTower();
											}
										}
									}
									else if (this->world->ultraTowerMenu->myTower->towerType == 7)
									{
										if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
										{
											if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[1])
											{
												this->world->getSphere->getSphereFromArchiveToTower();
											}
										}
										else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount == 0)
										{
											if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[2])
											{
												this->world->getSphere->getSphereFromArchiveToTower();
											}
										}
									}
									else if (this->world->ultraTowerMenu->myTower->towerType == 8)
									{
										if (this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
										{
											if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[0])
											{
												this->world->getSphere->getSphereFromArchiveToTower();
											}
										}
										else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount > 0)
										{
											if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[3])
											{
												this->world->getSphere->getSphereFromArchiveToTower();
											}
										}
									}
								}
							}
						}
						else if (this->world->towerMenu)
						{
							if (this->world->towerMenu->myTower->spheresManage("scan") == 4)
							{
								this->world->getSphere->getSphereFromArchiveToTower();
							}
						}
					}
				}
			}
			else if (targetName == "startWavesCase")
			{
                event->processed = true;
                if(this->container->startWavesStartWavesCase->mouseEnabled)
				{
					this->world->wavesClass->startWaves();
				}
			}
			else if (targetName == "castGolemCase")
			{
                event->processed = true;
                if(this->container->butCastGolem->currentFrame == 2)
				{
					this->container->butCastGolem->gotoAndStop(3);
					this->castGolem();
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "castIcemanCase")
			{
                event->processed = true;
                if(this->container->butCastIceman->currentFrame == 2)
				{
					this->container->butCastIceman->gotoAndStop(3);
					this->castIceman();
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "castAirCase")
			{
                event->processed = true;
                if(this->container->butCastAir->currentFrame == 2)
				{
					this->container->butCastAir->gotoAndStop(3);
					this->castAir();
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (targetName == "pointerCase")
			{
                event->processed = true;
                this->world->wavesClass->startWaves();
			}
			else if (targetName == "newEnemyCase" || targetName == "newElementCase")
			{
                event->processed = true;
                Node * parent = event->target->getParent()->getParent()->getParent();
                MouseStatusMC * tempObject = ISTYPE(MouseStatusMC, parent);
				if (tempObject){
					tempObject->mouseStatus = 3;
					tempObject->setMouseChildren(false);
					tempObject->setMouseEnabled(false);
				} 
				AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
			}
			//else if (targetName == "testRestart")
			//{
   //             event->processed = true;
   //             if(this->container->testRestart->currentFrame == 2)
			//	{
			//		this->container->testRestart->gotoAndStop(3);
			//	}
			//}
		}
	}
	void WorldInterface::mouseUpHandler(cocos2d::EventMouse *e)//(event:MouseEvent) : void
	{
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
        string targetName = event->target->getName();
        if(!this->world->getSphere && !this->world->cast)
		{ 
			if (targetName == "fastCase")
			{
                event->processed = true;
                if(ISTYPE(EventNode, event->target)->mouseEnabled)
				{
					if (this->container->fast->currentFrame == 3 || this->container->fast->currentFrame == 6)
						this->fasterManage(true);
				}
			}
			else if (this->container->fast->currentFrame == 3 || this->container->fast->currentFrame == 6)
			{
				this->container->fast->gotoAndStop(this->container->fast->currentFrame - 2);
				if (this->container->fast->currentFrame == 4)
				{
					this->container->fastCont->stop();
				}
			} 
			if (targetName == "pauseCase")
			{
                event->processed = true;
                if(this->container->pause->currentFrame == this->container->pause->totalFrames)
				{
					this->addPause();
				}
			}
			else if (this->container->pause->currentFrame > 1)
			{
				if (this->container->pause->currentFrame == this->container->pause->totalFrames)
				{
					this->container->pause->gotoAndStop((this->container->pause->totalFrames - 1));
				}
				if (this->container->pauseOpenFlag)
				{
					this->container->pauseOpenFlag = false;
				}
				if (!this->container->pauseCloseFlag)
				{
					this->container->pauseCloseFlag = true;
				}
			}
			if (targetName == "bookCase")
			{
                event->processed = true;
                if(this->container->book->currentFrame == this->container->book->totalFrames)
				{
					this->addEncyclopedia();
				}
			}
			else if (this->container->book->currentFrame > 1)
			{
				if (this->container->book->currentFrame == this->container->book->totalFrames)
				{
					this->container->book->gotoAndStop((this->container->book->totalFrames - 1));
				}
				if (this->container->bookOpenFlag)
				{
					this->container->bookOpenFlag = false;
				}
				if (!this->container->bookCloseFlag)
				{
					this->container->bookCloseFlag = true;
				}
			}
		}
	}// end function
	void WorldInterface::mouseMoveHandler(cocos2d::EventMouse *e)//MouseEvent
	{
		std::MouseEvent * event = ISTYPE(std::MouseEvent, e);
		if (!event)
			return;
        string targetName = event->target->getName();
        if(!this->world->getSphere && !this->world->cast && !this->world->exchange)
		{
            if(targetName == "sphereCase")
			{
                event->processed = true;
                Node * parent = event->target->getParent()->getParent();//display -> dbdisplay
                string parName = parent->getName();
                if(parName == "fireSphere")
				{
					if (ISTYPE(EventNode, event->target)->mouseEnabled && this->container->fireBack->currentFrame == 1)
					{
						if (this->container->iceBack->currentFrame == 2)
						{
							this->container->iceBack->gotoAndStop(1);
						}
						if (this->container->stoneBack->currentFrame == 2)
						{
							this->container->stoneBack->gotoAndStop(1);
						}
						if (this->container->levinBack->currentFrame == 2)
						{
							this->container->levinBack->gotoAndStop(1);
						}
						if (this->container->getAll->currentFrame == 2)
						{
							this->container->getAll->gotoAndStop(1);
						}
						this->container->fireBack->gotoAndStop(2);
						this->container->fireBackCont->stop();
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					}
				}
                else if(parName == "iceSphere")
				{
					if (ISTYPE(EventNode, event->target)->mouseEnabled && this->container->iceBack->currentFrame == 1)
					{
						if (this->container->fireBack->currentFrame == 2)
						{
							this->container->fireBack->gotoAndStop(1);
						}
						if (this->container->stoneBack->currentFrame == 2)
						{
							this->container->stoneBack->gotoAndStop(1);
						}
						if (this->container->levinBack->currentFrame == 2)
						{
							this->container->levinBack->gotoAndStop(1);
						}
						if (this->container->getAll->currentFrame == 2)
						{
							this->container->getAll->gotoAndStop(1);
						}
						this->container->iceBack->gotoAndStop(2);
						this->container->iceBackCont->stop();
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					}
				}
                else if(parName == "stoneSphere")
				{
					if (ISTYPE(EventNode, event->target)->mouseEnabled && this->container->stoneBack->currentFrame == 1)
					{
						if (this->container->fireBack->currentFrame == 2)
						{
							this->container->fireBack->gotoAndStop(1);
						}
						if (this->container->iceBack->currentFrame == 2)
						{
							this->container->iceBack->gotoAndStop(1);
						}
						if (this->container->levinBack->currentFrame == 2)
						{
							this->container->levinBack->gotoAndStop(1);
						}
						if (this->container->getAll->currentFrame == 2)
						{
							this->container->getAll->gotoAndStop(1);
						}
						this->container->stoneBack->gotoAndStop(2);
						this->container->stoneBackCont->stop();
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					}
				}
                else if(parName == "levinSphere")
				{
					if (ISTYPE(EventNode, event->target)->mouseEnabled && this->container->levinBack->currentFrame == 1)
					{
						if (this->container->fireBack->currentFrame == 2)
						{
							this->container->fireBack->gotoAndStop(1);
						}
						if (this->container->iceBack->currentFrame == 2)
						{
							this->container->iceBack->gotoAndStop(1);
						}
						if (this->container->stoneBack->currentFrame == 2)
						{
							this->container->stoneBack->gotoAndStop(1);
						}
						if (this->container->getAll->currentFrame == 2)
						{
							this->container->getAll->gotoAndStop(1);
						}
						this->container->levinBack->gotoAndStop(2);
						this->container->levinBackCont->stop();
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					}
				}
                else if(parName == "getAll")
				{
					if (ISTYPE(EventNode, event->target)->mouseEnabled && this->container->getAll->currentFrame == 1)
					{
						if (this->container->fireBack->currentFrame == 2)
						{
							this->container->fireBack->gotoAndStop(1);
						}
						if (this->container->iceBack->currentFrame == 2)
						{
							this->container->iceBack->gotoAndStop(1);
						}
						if (this->container->stoneBack->currentFrame == 2)
						{
							this->container->stoneBack->gotoAndStop(1);
						}
						if (this->container->levinBack->currentFrame == 2)
						{
							this->container->levinBack->gotoAndStop(1);
						}
						this->container->getAll->gotoAndStop(2);
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					}
					else if (this->container->getAll->currentFrame == 3)
					{
						if (this->container->levinSphere->isVisible() && Main::mainClass->saveBoxClass->getIntValue("saveNo") <= 3)
						{
							if (!this->getAllHint)
							{
								this->getAllHint = new Hint_mc();
								this->getAllHint->gotoAndStop(15);
								this->getAllHint->setPosition(540, 45); //Main::SCREEN_HEGIHT-45;
								this->getAllHint->setMouseChildren(false);
								this->getAllHint->setMouseEnabled(false);
								this->addChild(this->getAllHint, 1);
							}
						}
					}
				}
			}
			else
			{
				if (this->container->fireBack->currentFrame == 2)
				{
					this->container->fireBack->gotoAndStop(1);
				}
				if (this->container->iceBack->currentFrame == 2)
				{
					this->container->iceBack->gotoAndStop(1);
				}
				if (this->container->stoneBack->currentFrame == 2)
				{
					this->container->stoneBack->gotoAndStop(1);
				}
				if (this->container->levinBack->currentFrame == 2)
				{
					this->container->levinBack->gotoAndStop(1);
				}
				if (this->container->getAll->currentFrame == 2)
				{
					this->container->getAll->gotoAndStop(1);
				}
				if (this->getAllHint)
				{
					this->removeChild(this->getAllHint);
					this->getAllHint = NULL;
				}
			} 
            if(targetName == "fastCase")
			{
                event->processed = true;
                if(ISTYPE(EventNode, event->target)->mouseEnabled)
				{
					if (this->container->fast->currentFrame == 1 || this->container->fast->currentFrame == 4)
					{
						int tempObject = 0;
						if (this->container->fast->currentFrame == 4) 
							tempObject = this->container->fastCont->currentFrame; 
						this->container->fast->gotoAndStop((this->container->fast->currentFrame + 1));
						if (this->container->fast->currentFrame == 5) 
							this->container->fastCont->gotoAndStop(tempObject); 
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					}
				}
			}
			else if (this->container->fast->currentFrame == 2 || this->container->fast->currentFrame == 5)
			{
				int tempObject = 0;
				if (this->container->fast->currentFrame == 5)
					tempObject = this->container->fastCont->currentFrame;
				this->container->fast->gotoAndStop((this->container->fast->currentFrame - 1));
				if (this->container->fast->currentFrame == 4)
					this->container->fastCont->gotoAndStop(tempObject);
			}
			//if (targetName == "traceBezier")
			//{
			//	if (this->container->traceBezier->currentFrame == 1)
			//	{
			//		this->container->traceBezier->gotoAndStop(2);
			//	}
			//}
			//else if (this->container->traceBezier->currentFrame == 2)
			//{
			//	this->container->traceBezier->gotoAndStop(1);
			//}
            if(targetName == "pauseCase")
			{
                event->processed = true;
                if(this->container->pause->currentFrame == 1)
				{
					this->container->pause->gotoAndStop(2);
					this->container->pauseOpenFlag = true;
					this->container->pauseCloseFlag = false;
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->pause->currentFrame > 1)
			{
				if (this->container->pause->currentFrame == this->container->pause->totalFrames)
				{
					this->container->pause->gotoAndStop(this->container->pause->totalFrames-1);
				}
				if (this->container->pauseOpenFlag)
				{
					this->container->pauseOpenFlag = false;
				}
				if (!this->container->pauseCloseFlag)
				{
					this->container->pauseCloseFlag = true;
				}
			}
            if(targetName == "bookCase")
			{
                event->processed = true;
                if(this->container->book->currentFrame == 1)
				{
					this->container->book->gotoAndStop(2);
					this->container->bookOpenFlag = true;
					this->container->bookCloseFlag = false;
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->book->currentFrame > 1)
			{
				if (this->container->book->currentFrame == this->container->book->totalFrames)
				{
					this->container->book->gotoAndStop(this->container->book->totalFrames-1);
				}
				if (this->container->bookOpenFlag)
				{
					this->container->bookOpenFlag = false;
				}
				if (!this->container->bookCloseFlag)
				{
					this->container->bookCloseFlag = true;
				}
			}
            if(targetName == "startWavesCase")
			{
                event->processed = true;
                if(this->container->startWavesStartWavesCase->mouseEnabled)
				{
					if (this->container->startWaves->currentFrame <= 10)
					{
						this->container->startWaves->gotoAndStop(this->container->startWaves->currentFrame + 10);
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					}
				}
			}
			else if (this->container->startWavesStartWavesCase->mouseEnabled)
			{
				if (this->container->startWaves->currentFrame > 10)
				{
					this->container->startWaves->gotoAndStop(this->container->startWaves->currentFrame - 10);
				}
			}
            if(targetName == "castGolemCase")
			{
                event->processed = true;
                if(event->target->getParent()->isVisible())
				{
					if (this->container->butCastGolem->currentFrame == 1)
					{
						this->container->butCastGolem->gotoAndStop(2);
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
						if (!this->world->hint->isVisible())
						{
							this->world->hint->setVisible(true);
						}
						if (this->world->hint->currentFrame != 1)
						{
							this->world->hint->gotoAndStop(1);
						}
						string cnVal=I18N_VALUE(I18N_CODE::U001);
						if (std::getText(this->world->hint->nameTXT) != cnVal)
						{
							std::setText(this->world->hint->nameTXT, cnVal);
							std::setText(this->world->hint->noteTXT, I18N_VALUE(I18N_CODE::U002));
							//this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
							std::setText(this->world->hint->timeTXT, int(this->castGolemTimer / 30));
							//this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
							this->hintUpdate();
						}
					}
					else if (this->container->butCastGolem->currentFrame == 4)
					{
						if (!this->world->hint->isVisible())
						{
							this->world->hint->setVisible(true);
						}
						if (this->world->hint->currentFrame != 1)
						{
							this->world->hint->gotoAndStop(1);
						}
						if (std::getText(this->world->hint->nameTXT) != I18N_VALUE(I18N_CODE::U003))
						{
							std::setText(this->world->hint->nameTXT, I18N_VALUE(I18N_CODE::U003));
							std::setText(this->world->hint->noteTXT, I18N_VALUE(I18N_CODE::U002));
							//this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
							this->hintUpdate();
						}
					}
				}
			}
			else
			{
				if (this->container->butCastGolem->currentFrame == 2)
				{
					this->container->butCastGolem->gotoAndStop(1);
				}
				if (this->world->hint->isVisible())
				{
					if (std::getText(this->world->hint->nameTXT) == I18N_VALUE(I18N_CODE::U003) || std::getText(this->world->hint->nameTXT) == I18N_VALUE(I18N_CODE::U001))
					{
						this->world->hint->setVisible(false);
					}
				}
			}
            if(targetName == "castIcemanCase")
			{
                event->processed = true;
                if(event->target->getParent()->getParent()->isVisible())
				{
					if (this->container->butCastIceman->currentFrame == 1)
					{
						this->container->butCastIceman->gotoAndStop(2);
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
						if (!this->world->hint->isVisible())
						{
							this->world->hint->setVisible(true);
							this->world->hint->setLocalZOrder(3);
						}
						if (this->world->hint->currentFrame != 1)
						{
							this->world->hint->gotoAndStop(1);
						}
						if (std::getText(this->world->hint->nameTXT) != I18N_VALUE(I18N_CODE::U004))
						{
							std::setText(this->world->hint->nameTXT, I18N_VALUE(I18N_CODE::U004));
							std::setText(this->world->hint->noteTXT, I18N_VALUE(I18N_CODE::U006));
							//this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
							std::setText(this->world->hint->timeTXT, int(this->castIcemanTimer / 30));
							//this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
							this->hintUpdate();
						}
					}
					else if (this->container->butCastIceman->currentFrame == 4)
					{
						if (!this->world->hint->isVisible())
						{
							this->world->hint->setVisible(true);
						}
						if (this->world->hint->currentFrame != 1)
						{
							this->world->hint->gotoAndStop(1);
						}
						if (std::getText(this->world->hint->nameTXT) != I18N_VALUE(I18N_CODE::U005))
						{
							std::setText(this->world->hint->nameTXT, I18N_VALUE(I18N_CODE::U005));
							std::setText(this->world->hint->noteTXT, I18N_VALUE(I18N_CODE::U006));
							//this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
							this->hintUpdate();
						}
					}
				}
			}
			else
			{
				if (this->container->butCastIceman->currentFrame == 2)
				{
					this->container->butCastIceman->gotoAndStop(1);
				}
				if (this->world->hint->isVisible())
				{
					if (std::getText(this->world->hint->nameTXT) == I18N_VALUE(I18N_CODE::U005) || std::getText(this->world->hint->nameTXT) == I18N_VALUE(I18N_CODE::U004))
					{
						this->world->hint->setVisible(false);
					}
				}
			}
            if(targetName == "castAirCase")
			{
                event->processed = true;
                if(event->target->getParent()->getParent()->isVisible())
				{
					if (this->container->butCastAir->currentFrame == 1)
					{
						this->container->butCastAir->gotoAndStop(2);
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
						if (!this->world->hint->isVisible())
						{
							this->world->hint->setVisible(true);
						}
						if (this->world->hint->currentFrame != 1)
						{
							this->world->hint->gotoAndStop(1);
						}
						if (std::getText(this->world->hint->nameTXT) != I18N_VALUE(I18N_CODE::U007))
						{
							std::setText(this->world->hint->nameTXT, I18N_VALUE(I18N_CODE::U007));
							std::setText(this->world->hint->noteTXT, I18N_VALUE(I18N_CODE::U009));
							//this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
							std::setText(this->world->hint->timeTXT, int(this->castAirTimer / 30));
							//this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
							this->hintUpdate();
						}
					}
					else if (this->container->butCastAir->currentFrame == 4)
					{
						if (!this->world->hint->isVisible())
						{
							this->world->hint->setVisible(true);
						}
						if (this->world->hint->currentFrame != 1)
						{
							this->world->hint->gotoAndStop(1);
						}
						if (std::getText(this->world->hint->nameTXT) != I18N_VALUE(I18N_CODE::U008))
						{
							std::setText(this->world->hint->nameTXT, I18N_VALUE(I18N_CODE::U008));
							std::setText(this->world->hint->noteTXT, I18N_VALUE(I18N_CODE::U009));
							//this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
							this->hintUpdate();
						}
					}
				}
			}
			else
			{
				if (this->container->butCastAir->currentFrame == 2)
				{
					this->container->butCastAir->gotoAndStop(1);
				}
				if (this->world->hint->isVisible())
				{
					if (std::getText(this->world->hint->nameTXT) == I18N_VALUE(I18N_CODE::U008) || std::getText(this->world->hint->nameTXT) == I18N_VALUE(I18N_CODE::U007))
					{
						this->world->hint->setVisible(false);
					}
				}
			}
			if (targetName == "pointerCase")
			{
                event->processed = true;
                Node * parent = event->target->getParent()->getParent()->getParent();
				LevelPointer * pointer = ISTYPE(LevelPointer, parent);
				if (!pointer->mouseMoveFlag)
				{
					this->world->pointer1->setMouseMoveFlag(true);
					if (this->world->pointer2)
					{
						this->world->pointer2->setMouseMoveFlag(true);
					}
					if (this->world->pointer3)
					{
						this->world->pointer3->setMouseMoveFlag(true);
					}
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else
			{
				if (this->world->pointer1->mouseMoveFlag)
				{
					this->world->pointer1->setMouseMoveFlag(false);
				}
				if (this->world->pointer2)
				{
					if (this->world->pointer2->mouseMoveFlag)
					{
						this->world->pointer2->setMouseMoveFlag(false);
					}
				}
				if (this->world->pointer3)
				{
					if (this->world->pointer3->mouseMoveFlag)
					{
						this->world->pointer3->setMouseMoveFlag(false);
					}
				}
			}
            if(targetName == "newEnemyCase" || targetName == "newElementCase")
			{
                event->processed = true;
                MouseStatusMC * tempObject = ISTYPE(MouseStatusMC, event->target->getParent()->getParent()->getParent());
				if (tempObject){
					if (tempObject->mouseStatus == 1)
					{
						tempObject->mouseStatus = 2;
						tempObject->setScaleY(1.1f);
						tempObject->setScaleX(1.1f);
						AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
					}
				}  
			}
			else if (this->listOfNewEnemies.size() > 0)
			{
				this->i = 0;
				while (this->i < this->listOfNewEnemies.size())
				{
					if (this->listOfNewEnemies[this->i]->mouseStatus == 2)
					{
						this->listOfNewEnemies[this->i]->mouseStatus = 1;
						this->listOfNewEnemies[this->i]->setScaleY(1);
						this->listOfNewEnemies[this->i]->setScaleX(1);
					}
					i++;
				}
			}
   //         if(targetName == "testRestart")
			//{
   //             event->processed = true;
   //             if(this->container->testRestart->currentFrame == 1)
			//	{
			//		this->container->testRestart->gotoAndStop(2);
			//	}
			//}
			//else if (this->container->testRestart->currentFrame == 2)
			//{
			//	this->container->testRestart->gotoAndStop(1);
			//}
			if (targetName == "sellCase")
			{
                event->processed = true;
                if(!this->sellHint)
				{
					this->sellHint = new Hint_mc();
					this->sellHint->gotoAndStop(14);
					this->sellHint->setPosition(645, Main::SCREEN_HEIGHT - 50);
					this->sellHint->setScaleY(0.7f);
					this->sellHint->setScaleX(0.7f);
					this->sellHint->setMouseChildren(false);
					this->sellHint->setMouseEnabled(false);
					this->addChild(this->sellHint);
				}
			}
			else if (this->sellHint)
			{
				this->removeChild(this->sellHint);
				this->sellHint = NULL;
			}
		}
	}


	void WorldInterface::addCast(string param1)
	{
		if (param1 == "golem")
		{
			this->world->cast = new casts::Cast_1();
		}
		else if (param1 == "iceman")
		{
			this->world->cast = new casts::Cast_2();
		}
		else if (param1 == "air")
		{
			this->world->cast = new casts::Cast_3();
		}
		this->world->addChild(this->world->cast,5);
		this->world->addClasses(this->world->cast);
	}// end function

	void WorldInterface::updateInfo()
	{
		char tmp[32];
		sprintf(tmp, "%d", this->world->money);
		this->container->moneyTXT->setString(tmp);
		sprintf(tmp, "%d", this->world->live);
		this->container->liveTXT->setString(tmp);
		sprintf(tmp, "%i/%i", this->world->wavesClass->nowWave, this->world->wavesClass->maxWaves);
		this->container->waveTXT->setString(tmp);
		sprintf(tmp, "%d", this->fireCount);
		this->container->fireNumTXT->setString(tmp);
		printNodePos(this->container->buyFireBuyTXT);

		if (this->fireCount > 0)
		{
			if (!this->container->fireNumTXT->isVisible())
			{
				this->container->fireNumTXT->setVisible(true);
			}
		}
		else if (this->container->fireNumTXT->isVisible())
		{
			this->container->fireNumTXT->setVisible(false);
		}
		sprintf(tmp, "%d", this->fireCount);
		this->container->iceNumTXT->setString(  tmp );
		if (this->iceCount > 0)
		{
			if (!this->container->iceNumTXT->isVisible())
			{
				this->container->iceNumTXT->setVisible(true);
			}
		}
		else if (this->container->iceNumTXT->isVisible())
		{
			this->container->iceNumTXT->setVisible(false);
		}
		sprintf(tmp, "%d", this->stoneCount);
		this->container->stoneNumTXT->setString(tmp);
		if (this->stoneCount > 0)
		{
			if (!this->container->stoneNumTXT->isVisible())
			{
				this->container->stoneNumTXT->setVisible(true);
			}
		}
		else if (this->container->stoneNumTXT->isVisible())
		{
			this->container->stoneNumTXT->setVisible(false);
		}
		sprintf(tmp, "%d", this->levinCount);
		this->container->levinNumTXT->setString(tmp);
		if (this->levinCount > 0)
		{
			if (!this->container->levinNumTXT->isVisible())
			{
				this->container->levinNumTXT->setVisible(true);
			}
		}
		else if (this->container->levinNumTXT->isVisible())
		{
			this->container->levinNumTXT->setVisible(false);
		}
		sprintf(tmp, "%d", this->getAllCount);
		this->container->getAllNumTXT->setString(tmp);
		if (this->getAllCount > 0)
		{
			if (!this->container->getAllNumTXT->isVisible())
			{
				this->container->getAllNumTXT->setVisible(true);
			}
		}
		else if (this->container->getAllNumTXT->isVisible())
		{
			this->container->getAllNumTXT->setVisible(false);
		}

		std::setText(this->container->buyFireBuyTXT, Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory]);
		std::setText(this->container->buyIceBuyTXT, Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory]);
		std::setText(this->container->buyStoneBuyTXT, Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory]);
		std::setText(this->container->buyLevinBuyTXT, Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory]);
		std::setText(this->container->buyGetAllBuyTXT, Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory]
			+ Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory] + Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory]
			+ Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory]);
		//if (std::getInt(this->container->buyFireBuyTXT) < 10)
		//{
		//	this->container->buyFireCoin->setPositionX(-5.75f);
		//	this->container->buyFireCoin->setPositionY(13.15f);
		//}
		//else
		//{
		//	this->container->buyFireCoin->setPositionX(-9.25f);
		//	this->container->buyFireCoin->setPositionY(13.15f);
		//}
		//if (std::getInt(this->container->buyIceBuyTXT) < 10)
		//{
		//	this->container->buyIceCoin->setPositionX(-5.75f);
		//	this->container->buyIceCoin->setPositionY(13.15f);
		//}
		//else
		//{
		//	this->container->buyIceCoin->setPositionX(-9.25f);
		//	this->container->buyIceCoin->setPositionY(13.15f);
		//}
		//if (std::getInt(this->container->buyStoneBuyTXT) < 10)
		//{
		//	this->container->buyStoneCoin->setPositionX(-5.75f);
		//	this->container->buyStoneCoin->setPositionY(13.15f);
		//}
		//else
		//{
		//	this->container->buyStoneCoin->setPositionX(-9.25f);
		//	this->container->buyStoneCoin->setPositionY(13.15f);
		//}
		//if (std::getInt(this->container->buyLevinBuyTXT) < 10)
		//{
		//	this->container->buyLevinCoin->setPositionX(-5.75f);
		//	this->container->buyLevinCoin->setPositionY(13.15f);
		//}
		//else
		//{
		//	this->container->buyLevinCoin->setPositionX(-9.25f);
		//	this->container->buyLevinCoin->setPositionY(13.15f);
		//}
		//if (std::getInt(this->container->buyGetAllBuyTXT) < 10)
		//{
		//	this->container->buyGetAllCoin->setPositionX(-8.6f);
		//	this->container->buyGetAllCoin->setPositionY(13.15f);
		//}
		//else if (std::getInt(this->container->buyGetAllBuyTXT) < 100)
		//{
		//	this->container->buyGetAllCoin->setPositionX(-11);
		//	this->container->buyGetAllCoin->setPositionY(13.15f);
		//}
		//else
		//{
		//	this->container->buyGetAllCoin->setPositionX(-14.2f);
		//	this->container->buyGetAllCoin->setPositionY(13.15f);
		//}
		printNodePos(this->container->fireSphere); 

		int firePrice = std::getInt(this->container->buyFireBuyTXT);
		if (this->container->fireSphere->isVisible() && (this->fireCount > 0 || this->world->money >= firePrice))
		{
			if (!this->container->fireSphereSphereCase->mouseEnabled)
			{
				this->container->fireSphereSphereCase->setMouseEnabled(true);
				this->container->fireSphere->setAlpha(1);
			}
			if (this->world->money >= firePrice)
			{
				if (this->container->buyFire->currentFrame == 2)
				{
					if (this->container->buyFireMyCost = firePrice)
					{
						this->container->buyFireMyCost = firePrice;
						std::setText(this->container->buyFireBuyTXT, this->container->buyFireMyCost);
					}
					this->container->buyFireCoinMyPoint = this->container->buyFireCoin->getPosition();
					this->container->buyFire->gotoAndStop(1);
					this->container->buyFireCoin->gotoAndStop(1);
					//this->container->buyFireCoin->setPosition(this->container->buyFireCoinMyPoint);
				}
			}
			else if (this->container->buyFire->currentFrame == 1)
			{
				if (this->container->buyFireMyCost = firePrice)
				{
					this->container->buyFireMyCost = firePrice;
					std::setText(this->container->buyFireBuyTXT, this->container->buyFireMyCost);
				} 
				this->container->buyFireCoinMyPoint = this->container->buyFireCoin->getPosition();
				this->container->buyFire->gotoAndStop(2);
				this->container->buyFireCoin->gotoAndStop(2);
				//this->container->buyFireCoin->setPosition(this->container->buyFireCoinMyPoint);
				this->container->buyFireCoin->setScaleY(0.8f);
				this->container->buyFireCoin->setScaleX(0.8f);
			}
			//this->container->buyFireMyCost = firePrice;
			//this->container->buyFireCoinMyPoint = this->container->buyFireCoin->getPosition();
			////std::setText(this->container->buyFireBuyTXT, this->container->buyFireMyCost);
			//if (this->world->money >= firePrice)
			//{
			//	if (this->container->buyFire->currentFrame != 1)
			//	{
			//		this->container->buyFire->gotoAndStop(1);
			//		this->container->buyFireCoin->gotoAndStop(1);
			//	}
			//}
			//else if (this->container->buyFire->currentFrame != 2)
			//{ 
 		//	  this->container->buyFire->gotoAndStop(2);
			//	this->container->buyFireCoin->gotoAndStop(2);
			//	this->container->buyFireCoin->setScaleY(0.8f);
			//	this->container->buyFireCoin->setScaleX(0.8f);
			//}

			if (this->container->fireSphereSphereCase->mouseEnabled)
			{
				if (!this->world->getSphere)
				{
					if (this->world->towerMenu)
					{
						if (this->world->towerMenu->myTower->spheresManage("scan") > 0)
						{
							if (!this->container->buyFireLightUp->isVisible())
							{
								this->container->buyFireLightUp->setVisible(true);
							}
						}
						else if (this->container->buyFireLightUp->isVisible())
						{
							this->container->buyFireLightUp->setVisible(false);
						}
					}
					else if (this->world->ultraTowerMenu)
					{
						if (this->world->ultraTowerMenu->myTower->towerType == 5 && Main::mainClass->readXMLClass.ultraTower1UpgrBlock == 0)
						{
							if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[0])
							{
								if (!this->container->buyFireLightUp->isVisible())
								{
									this->container->buyFireLightUp->setVisible(true);
								}
							}
							else if (this->container->buyFireLightUp->isVisible())
							{
								this->container->buyFireLightUp->setVisible(false);
							}
						}
						else if (this->world->ultraTowerMenu->myTower->towerType == 8 && Main::mainClass->readXMLClass.ultraTower4UpgrBlock == 0)
						{
							if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[0])
							{
								if (!this->container->buyFireLightUp->isVisible())
								{
									this->container->buyFireLightUp->setVisible(true);
								}
							}
							else if (this->container->buyFireLightUp->isVisible())
							{
								this->container->buyFireLightUp->setVisible(false);
							}
						}
					}
					else if (this->container->buyFireLightUp->isVisible())
					{
						this->container->buyFireLightUp->setVisible(false);
					}
				}
				else if (this->container->buyFireLightUp->isVisible())
				{
					this->container->buyFireLightUp->setVisible(false);
				}
			}
		}
		else
		{
			if (this->container->fireSphereSphereCase->mouseEnabled)
			{
				this->container->fireSphereSphereCase->setMouseEnabled(false);
				this->container->fireBack->gotoAndStop(1);
				if (this->container->buyFireLightUp->isVisible())
				{
					this->container->buyFireLightUp->setVisible(false);
				}
			}
			if (this->container->buyFire->currentFrame == 1)
			{
				this->container->buyFireMyCost = std::getInt(this->container->buyFireBuyTXT);
				this->container->buyFireCoinMyPoint = this->container->buyFireCoin->getPosition();
				this->container->buyFire->gotoAndStop(2);
				std::setText(this->container->buyFireBuyTXT, this->container->buyFireMyCost);
				this->container->buyFireCoin->gotoAndStop(2);
				//this->container->buyFireCoin->setPosition(this->container->buyFireCoinMyPoint);
				this->container->buyFireCoin->setScaleY(0.8f);
				this->container->buyFireCoin->setScaleX(0.8f);
			}
			//this->container->buyFireMyCost = std::getInt(this->container->buyFireBuyTXT);
			//this->container->buyFireCoinMyPoint = this->container->buyFireCoin->getPosition();
			//std::setText(this->container->buyFireBuyTXT, this->container->buyFireMyCost);
			//if (this->container->buyFire->currentFrame != 2)
			//{
			//	this->container->buyFire->gotoAndStop(2);
			//	this->container->buyFireCoin->gotoAndStop(2);
			//	this->container->buyFireCoin->setScaleY(0.8f);
			//	this->container->buyFireCoin->setScaleX(0.8f);
			//}
			if (this->container->fireSphere->getAlpha() != 0.5)
			{
				this->container->fireSphere->setAlpha(0.5);
			}
		}

		if (this->container->iceSphere->isVisible() && (this->iceCount > 0 || this->world->money >= std::getInt(this->container->buyIceBuyTXT)))
		{
			if (!this->container->iceSphereSphereCase->mouseEnabled)
			{
				this->container->iceSphereSphereCase->setMouseEnabled(true);
				this->container->iceSphere->setAlpha(1);
			}
			if (this->world->money >= std::getInt(this->container->buyIceBuyTXT))
			{
				if (this->container->buyIce->currentFrame == 2)
				{
					this->container->buyIceMyCost = std::getInt(this->container->buyIceBuyTXT);
					this->container->buyIceCoinMyPoint = this->container->buyIceCoin->getPosition();
					this->container->buyIce->gotoAndStop(1);
					std::setText(this->container->buyIceBuyTXT, this->container->buyIceMyCost);
					this->container->buyIceCoin->gotoAndStop(1);
					this->container->buyIceCoin->setPosition(this->container->buyIceCoinMyPoint);
					this->container->buyIceCoin->setScaleY(1);
					this->container->buyIceCoin->setScaleX(1);
				}
			}
			else if (this->container->buyIce->currentFrame == 1)
			{
				this->container->buyIceMyCost = std::getInt(this->container->buyIceBuyTXT);
				this->container->buyIceCoinMyPoint = this->container->buyIceCoin->getPosition();
				this->container->buyIce->gotoAndStop(2);
				std::setText(this->container->buyIceBuyTXT, this->container->buyIceMyCost);
				this->container->buyIceCoin->gotoAndStop(2);
				this->container->buyIceCoin->setPosition(this->container->buyIceCoinMyPoint);
				this->container->buyIceCoin->setScaleY(0.8f);
				this->container->buyIceCoin->setScaleX(0.8f);
			}
			if (this->container->iceSphereSphereCase->mouseEnabled)
			{
				if (!this->world->getSphere)
				{
					if (this->world->towerMenu)
					{
						if (this->world->towerMenu->myTower->spheresManage("scan") > 0)
						{
							if (!this->container->buyIceLightUp->isVisible())
							{
								this->container->buyIceLightUp->setVisible(true);
							}
						}
						else if (this->container->buyIceLightUp->isVisible())
						{
							this->container->buyIceLightUp->setVisible(false);
						}
					}
					else if (this->world->ultraTowerMenu)
					{
						if (this->world->ultraTowerMenu->myTower->towerType == 6 && Main::mainClass->readXMLClass.ultraTower2UpgrBlock == 0)
						{
							if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[1])
							{
								if (!this->container->buyIceLightUp->isVisible())
								{
									this->container->buyIceLightUp->setVisible(true);
								}
							}
							else if (this->container->buyIceLightUp->isVisible())
							{
								this->container->buyIceLightUp->setVisible(false);
							}
						}
						else if (this->world->ultraTowerMenu->myTower->towerType == 7 && Main::mainClass->readXMLClass.ultraTower3UpgrBlock == 0)
						{
							if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[1])
							{
								if (!this->container->buyIceLightUp->isVisible())
								{
									this->container->buyIceLightUp->setVisible(true);
								}
							}
							else if (this->container->buyIceLightUp->isVisible())
							{
								this->container->buyIceLightUp->setVisible(false);
							}
						}
					}
					else if (this->container->buyIceLightUp->isVisible())
					{
						this->container->buyIceLightUp->setVisible(false);
					}
				}
				else if (this->container->buyIceLightUp->isVisible())
				{
					this->container->buyIceLightUp->setVisible(false);
				}
			}
		}
		else
		{
			if (this->container->iceSphereSphereCase->mouseEnabled)
			{
				this->container->iceSphereSphereCase->setMouseEnabled(false);
				this->container->iceBack->gotoAndStop(1);
				if (this->container->buyIceLightUp->isVisible())
				{
					this->container->buyIceLightUp->setVisible(false);
				}
			}
			if (this->container->buyIce->currentFrame == 1)
			{
				this->container->buyIceMyCost = std::getInt(this->container->buyIceBuyTXT);
				this->container->buyIceCoinMyPoint = this->container->buyIceCoin->getPosition();
				this->container->buyIce->gotoAndStop(2);
				std::setText(this->container->buyIceBuyTXT, this->container->buyIceMyCost);
				this->container->buyIceCoin->gotoAndStop(2);
				this->container->buyIceCoin->setPosition(this->container->buyIceCoinMyPoint);
				this->container->buyIceCoin->setScaleY(0.8f);
				this->container->buyIceCoin->setScaleX(0.8f);
			}
			if (this->container->iceSphere->getAlpha() != 0.5)
			{
				this->container->iceSphere->setAlpha(0.5);
			}
		}

		if (this->container->stoneSphere->isVisible() && (this->stoneCount > 0 || this->world->money >= std::getInt(this->container->buyStoneBuyTXT)))
		{
			if (!this->container->stoneSphereSphereCase->mouseEnabled)
			{
				this->container->stoneSphereSphereCase->setMouseEnabled(true);
				this->container->stoneSphere->setAlpha(1);
			}
			if (this->world->money >= std::getInt(this->container->buyStoneBuyTXT))
			{
				if (this->container->buyStone->currentFrame == 2)
				{
					this->container->buyStoneMyCost = std::getInt(this->container->buyStoneBuyTXT);
					this->container->buyStoneCoinMyPoint = this->container->buyStoneCoin->getPosition();
					this->container->buyStone->gotoAndStop(1);
					std::setText(this->container->buyStoneBuyTXT, this->container->buyStoneMyCost);
					this->container->buyStoneCoin->gotoAndStop(1);
					this->container->buyStoneCoin->setPosition(this->container->buyStoneCoinMyPoint);
					this->container->buyStoneCoin->setScaleY(1);
					this->container->buyStoneCoin->setScaleX(1);
				}
			}
			else if (this->container->buyStone->currentFrame == 1)
			{
				this->container->buyStoneMyCost = std::getInt(this->container->buyStoneBuyTXT);
				this->container->buyStoneCoinMyPoint = this->container->buyStoneCoin->getPosition();
				this->container->buyStone->gotoAndStop(2);
				std::setText(this->container->buyStoneBuyTXT, this->container->buyStoneMyCost);
				this->container->buyStoneCoin->gotoAndStop(2);
				this->container->buyStoneCoin->setPosition(this->container->buyStoneCoinMyPoint);
				this->container->buyStoneCoin->setScaleY(0.8f);
				this->container->buyStoneCoin->setScaleX(0.8f);
			}
			if (this->container->stoneSphereSphereCase->mouseEnabled)
			{
				if (!this->world->getSphere)
				{
					if (this->world->towerMenu)
					{
						if (this->world->towerMenu->myTower->spheresManage("scan") > 0)
						{
							if (!this->container->buyStoneLightUp->isVisible())
							{
								this->container->buyStoneLightUp->setVisible(true);
							}
						}
						else if (this->container->buyStoneLightUp->isVisible())
						{
							this->container->buyStoneLightUp->setVisible(false);
						}
					}
					else if (this->world->ultraTowerMenu)
					{
						if (this->world->ultraTowerMenu->myTower->towerType == 5 && Main::mainClass->readXMLClass.ultraTower1UpgrBlock == 0)
						{
							if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[2])
							{
								if (!this->container->buyStoneLightUp->isVisible())
								{
									this->container->buyStoneLightUp->setVisible(true);
								}
							}
							else if (this->container->buyStoneLightUp->isVisible())
							{
								this->container->buyStoneLightUp->setVisible(false);
							}
						}
						else if (this->world->ultraTowerMenu->myTower->towerType == 7 && Main::mainClass->readXMLClass.ultraTower3UpgrBlock == 0)
						{
							if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[2])
							{
								if (!this->container->buyStoneLightUp->isVisible())
								{
									this->container->buyStoneLightUp->setVisible(true);
								}
							}
							else if (this->container->buyStoneLightUp->isVisible())
							{
								this->container->buyStoneLightUp->setVisible(false);
							}
						}
					}
					else if (this->container->buyStoneLightUp->isVisible())
					{
						this->container->buyStoneLightUp->setVisible(false);
					}
				}
				else if (this->container->buyStoneLightUp->isVisible())
				{
					this->container->buyStoneLightUp->setVisible(false);
				}
			}
		}
		else
		{
			if (this->container->stoneSphereSphereCase->mouseEnabled)
			{
				this->container->stoneSphereSphereCase->setMouseEnabled(false);
				this->container->stoneBack->gotoAndStop(1);
				if (this->container->buyStoneLightUp->isVisible())
				{
					this->container->buyStoneLightUp->setVisible(false);
				}
			}
			if (this->container->buyStone->currentFrame == 1)
			{
				this->container->buyStoneMyCost = std::getInt(this->container->buyStoneBuyTXT);
				this->container->buyStoneCoinMyPoint = this->container->buyStoneCoin->getPosition();
				this->container->buyStone->gotoAndStop(2);
				std::setText(this->container->buyStoneBuyTXT, this->container->buyStoneMyCost);
				this->container->buyStoneCoin->gotoAndStop(2);
				this->container->buyStoneCoin->setPosition(this->container->buyStoneCoinMyPoint);
				this->container->buyStoneCoin->setScaleY(0.8f);
				this->container->buyStoneCoin->setScaleX(0.8f);
			}
			if (this->container->stoneSphere->getAlpha() != 0.5)
			{
				this->container->stoneSphere->setAlpha(0.5);
			}
		}

		if (this->container->levinSphere->isVisible() && (this->levinCount > 0 || this->world->money >= std::getInt(this->container->buyLevinBuyTXT)))
		{
			if (!this->container->levinSphereSphereCase->mouseEnabled)
			{
				this->container->levinSphereSphereCase->setMouseEnabled(true);
				this->container->levinSphere->setAlpha(1);
			}
			if (this->world->money >= std::getInt(this->container->buyLevinBuyTXT))
			{
				if (this->container->buyLevin->currentFrame == 2)
				{
					this->container->buyLevinMyCost = std::getInt(this->container->buyLevinBuyTXT);
					this->container->buyLevinCoinMyPoint = this->container->buyLevinCoin->getPosition();
					this->container->buyLevin->gotoAndStop(1);
					std::setText(this->container->buyLevinBuyTXT, this->container->buyLevinMyCost);
					this->container->buyLevinCoin->gotoAndStop(1);
					this->container->buyLevinCoin->setPosition(this->container->buyLevinCoinMyPoint);
					this->container->buyLevinCoin->setScaleY(1);
					this->container->buyLevinCoin->setScaleX(1);
				}
			}
			else if (this->container->buyLevin->currentFrame == 1)
			{
				this->container->buyLevinMyCost = std::getInt(this->container->buyLevinBuyTXT);
				this->container->buyLevinCoinMyPoint = this->container->buyLevinCoin->getPosition();
				this->container->buyLevin->gotoAndStop(2);
				std::setText(this->container->buyLevinBuyTXT, this->container->buyLevinMyCost);
				this->container->buyLevinCoin->gotoAndStop(2);
				this->container->buyLevinCoin->setPosition(this->container->buyLevinCoinMyPoint);
				this->container->buyLevinCoin->setScaleY(0.8f);
				this->container->buyLevinCoin->setScaleX(0.8f);
			}
			if (this->container->levinSphereSphereCase->mouseEnabled)
			{
				if (!this->world->getSphere)
				{
					if (this->world->towerMenu)
					{
						if (this->world->towerMenu->myTower->spheresManage("scan") > 0)
						{
							if (!this->container->buyLevinLightUp->isVisible())
							{
								this->container->buyLevinLightUp->setVisible(true);
							}
						}
						else if (this->container->buyLevinLightUp->isVisible())
						{
							this->container->buyLevinLightUp->setVisible(false);
						}
					}
					else if (this->world->ultraTowerMenu)
					{
						if (this->world->ultraTowerMenu->myTower->towerType == 6 && Main::mainClass->readXMLClass.ultraTower2UpgrBlock == 0)
						{
							if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[3])
							{
								if (!this->container->buyLevinLightUp->isVisible())
								{
									this->container->buyLevinLightUp->setVisible(true);
								}
							}
							else if (this->container->buyLevinLightUp->isVisible())
							{
								this->container->buyLevinLightUp->setVisible(false);
							}
						}
						else if (this->world->ultraTowerMenu->myTower->towerType == 8 && Main::mainClass->readXMLClass.ultraTower4UpgrBlock == 0)
						{
							if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[3])
							{
								if (!this->container->buyLevinLightUp->isVisible())
								{
									this->container->buyLevinLightUp->setVisible(true);
								}
							}
							else if (this->container->buyLevinLightUp->isVisible())
							{
								this->container->buyLevinLightUp->setVisible(false);
							}
						}
					}
					else if (this->container->buyLevinLightUp->isVisible())
					{
						this->container->buyLevinLightUp->setVisible(false);
					}
				}
				else if (this->container->buyLevinLightUp->isVisible())
				{
					this->container->buyLevinLightUp->setVisible(false);
				}
			}
		}
		else
		{
			if (this->container->levinSphereSphereCase->mouseEnabled)
			{
				this->container->levinSphereSphereCase->setMouseEnabled(false);
				this->container->levinBack->gotoAndStop(1);
				if (this->container->buyLevinLightUp->isVisible())
				{
					this->container->buyLevinLightUp->setVisible(false);
				}
			}
			if (this->container->buyLevin->currentFrame == 1)
			{
				this->container->buyLevinMyCost = std::getInt(this->container->buyLevinBuyTXT);
				this->container->buyLevinCoinMyPoint = this->container->buyLevinCoin->getPosition();
				this->container->buyLevin->gotoAndStop(2);
				std::setText(this->container->buyLevinBuyTXT, this->container->buyLevinMyCost);
				this->container->buyLevinCoin->gotoAndStop(2);
				this->container->buyLevinCoin->setPosition(this->container->buyLevinCoinMyPoint);
				this->container->buyLevinCoin->setScaleY(0.8f);
				this->container->buyLevinCoin->setScaleX(0.8f);
			}
			if (this->container->levinSphere->getAlpha() != 0.5)
			{
				this->container->levinSphere->setAlpha(0.5);
			}
		}

		if (this->container->getAll->currentFrame < 3)
		{
			if (this->container->getAll->isVisible() && (this->getAllCount > 0 || this->world->money >= std::getInt(this->container->buyGetAllBuyTXT)))
			{
				if (!this->container->getAllSphereCase->mouseEnabled)
				{
					this->container->getAllSphereCase->setMouseEnabled(true);
					this->container->getAll->setAlpha(1);
				}
				if (this->world->money >= std::getInt(this->container->buyGetAllBuyTXT))
				{
					if (this->container->buyGetAll->currentFrame == 2)
					{
						this->container->buyGetAllMyCost = std::getInt(this->container->buyGetAllBuyTXT);
						this->container->buyGetAllCoinMyPoint = this->container->buyGetAllCoin->getPosition();
						this->container->buyGetAll->gotoAndStop(1);
						std::setText(this->container->buyGetAllBuyTXT, this->container->buyGetAllMyCost);
						this->container->buyGetAllCoin->gotoAndStop(1);
						this->container->buyGetAllCoin->setPosition(this->container->buyGetAllCoinMyPoint);
						this->container->buyGetAllCoin->setScaleY(1);
						this->container->buyGetAllCoin->setScaleX(1);
					}
				}
				else if (this->container->buyGetAll->currentFrame == 1)
				{
					this->container->buyGetAllMyCost = std::getInt(this->container->buyGetAllBuyTXT);
					this->container->buyGetAllCoinMyPoint = this->container->buyGetAllCoin->getPosition();
					this->container->buyGetAll->gotoAndStop(2);
					std::setText(this->container->buyGetAllBuyTXT, this->container->buyGetAllMyCost);
					this->container->buyGetAllCoin->gotoAndStop(2);
					this->container->buyGetAllCoin->setPosition(this->container->buyGetAllCoinMyPoint);
					this->container->buyGetAllCoin->setScaleY(0.8f);
					this->container->buyGetAllCoin->setScaleX(0.8f);
				}
				if (this->container->getAllSphereCase->mouseEnabled)
				{
					if (!this->world->getSphere)
					{
						if (this->world->towerMenu)
						{
							if (this->world->towerMenu->myTower->spheresManage("scan") == 4)
							{
								if (!this->container->buyGetAllLightUp->isVisible())
								{
									this->container->buyGetAllLightUp->setVisible(true);
								}
							}
							else if (this->container->buyGetAllLightUp->isVisible())
							{
								this->container->buyGetAllLightUp->setVisible(false);
							}
						}
						else if (this->container->buyGetAllLightUp->isVisible())
						{
							this->container->buyGetAllLightUp->setVisible(false);
						}
					}
					else if (this->container->buyGetAllLightUp->isVisible())
					{
						this->container->buyGetAllLightUp->setVisible(false);
					}
				}
			}
			else
			{
				if (this->container->getAllSphereCase->mouseEnabled)
				{
					this->container->getAllSphereCase->setMouseEnabled(false);
					this->container->getAll->gotoAndStop(1);
					if (this->container->buyGetAllLightUp->isVisible())
					{
						this->container->buyGetAllLightUp->setVisible(false);
					}
				}
				if (this->container->buyGetAll->currentFrame == 1)
				{
					this->container->buyGetAllMyCost = std::getInt(this->container->buyGetAllBuyTXT);
					this->container->buyGetAllCoinMyPoint = this->container->buyGetAllCoin->getPosition();
					this->container->buyGetAll->gotoAndStop(2);
					std::setText(this->container->buyGetAllBuyTXT, this->container->buyGetAllMyCost);
					this->container->buyGetAllCoin->gotoAndStop(2);
					this->container->buyGetAllCoin->setPosition(this->container->buyGetAllCoinMyPoint);
					this->container->buyGetAllCoin->setScaleY(0.8f);
					this->container->buyGetAllCoin->setScaleX(0.8f);
				}
				if (this->container->getAll->getAlpha() != 0.5)
				{
					this->container->getAll->setAlpha(0.5);
				}
			}
		}

		if (this->world->getSphere)
		{
			this->world->getSphere->monitor();
		}
		if (this->world->towerMenu)
		{
			this->world->towerMenu->monitor();
		}
		else if (this->world->ultraTowerMenu)
		{
			this->world->ultraTowerMenu->monitor();
		}
		if (this->world->buildTowerMenu)
		{
			this->world->buildTowerMenu->monitor();
		}
		this->autoguidersButtons();
		return;
	}// end function

	void WorldInterface::archiveManage(string param1, string param2)
	{
		if (param1 == "buy")
		{
			if (param2 == "fire")
			{
				if (this->world->money >= Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory])
				{
					this->fireCount++;
					if(Main::moneyDebug)
						this->world->money = this->world->money + Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory];
					else
						this->world->money = this->world->money - Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory];
					this->sphereCostHistory[0].push(Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory]);
					if (this->fireBuyHistory < (Main::mainClass->readXMLClass.listOfFirePriceXML.size() - 1))
					{
						this->fireBuyHistory++;
					}
				}
			}
			else if (param2 == "ice")
			{
				if (this->world->money >= Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory])
				{
					this->iceCount++;
					if (Main::moneyDebug)
						this->world->money = this->world->money + Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory];
					else
						this->world->money = this->world->money - Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory];
					this->sphereCostHistory[1].push(Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory]);
					if (this->iceBuyHistory < (Main::mainClass->readXMLClass.listOfIcePriceXML.size() - 1))
					{
						this->iceBuyHistory++;
					}
				}
			}
			else if (param2 == "stone")
			{
				if (this->world->money >= Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory])
				{
					this->stoneCount++;
					if (Main::moneyDebug)
						this->world->money = this->world->money + Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory];
					else
						this->world->money = this->world->money - Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory];
					this->sphereCostHistory[2].push(Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory]);
					if (this->stoneBuyHistory < (Main::mainClass->readXMLClass.listOfStonePriceXML.size() - 1))
					{
						this->stoneBuyHistory++;
					}
				}
			}
			else if (param2 == "levin")
			{
				if (this->world->money >= Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory])
				{
					this->levinCount++;
					if (Main::moneyDebug)
						this->world->money = this->world->money + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
					else
						this->world->money = this->world->money - Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
					this->sphereCostHistory[3].push(Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory]);
					if (this->levinBuyHistory < (Main::mainClass->readXMLClass.listOfLevinPriceXML.size() - 1))
					{
						this->levinBuyHistory++;
					}
				}
			}
			else if (param2 == "getAll")
			{
				if (this->world->money >= Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory] + Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory] + Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory] + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory])
				{
					this->getAllCount++;
					int tempObject = Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory] + Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory] + Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory] + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
					if (Main::moneyDebug)
						this->world->money = this->world->money + tempObject;
					else
						this->world->money = this->world->money - tempObject;
					if (this->fireBuyHistory < (Main::mainClass->readXMLClass.listOfFirePriceXML.size() - 1))
					{
						this->fireBuyHistory++;
					}
					if (this->iceBuyHistory < (Main::mainClass->readXMLClass.listOfIcePriceXML.size() - 1))
					{
						this->iceBuyHistory++;
					}
					if (this->stoneBuyHistory < (Main::mainClass->readXMLClass.listOfStonePriceXML.size() - 1))
					{
						this->stoneBuyHistory++;
					}
					if (this->levinBuyHistory < (Main::mainClass->readXMLClass.listOfLevinPriceXML.size() - 1))
					{
						this->levinBuyHistory++;
					}
				}
			}
		}
		else if (param1 == "get")
		{
			if (param2 == "fire")
			{
				if (this->fireCount > 0)
				{
					if (!this->world->getSphere)
					{
						this->fireCount--;
						this->world->getSphere = new GetSphere();
						this->world->getSphere->owner = this->container->fireSphere;
						this->world->getSphere->ownerType = "archive";
						this->world->getSphere->ownerPoint = this->container->fireSphereMyPoint;
						this->world->addChild(this->world->getSphere,6);
						this->world->getSphere->manage("add", "fire");
					}
					else if (this->world->getSphere->listOfStack.size() < 4)
					{
						this->fireCount--;
						this->world->getSphere->manage("add", "fire");
					}
				}
			}
			else if (param2 == "ice")
			{
				if (this->iceCount > 0)
				{
					if (!this->world->getSphere)
					{
						this->iceCount--;
						this->world->getSphere = new GetSphere();
						this->world->getSphere->owner = this->container->iceSphere;
						this->world->getSphere->ownerType = "archive";
						this->world->getSphere->ownerPoint = this->container->iceSphereMyPoint;
						this->world->addChild(this->world->getSphere,6);
						this->world->getSphere->manage("add", "ice");
					}
					else if (this->world->getSphere->listOfStack.size() < 4)
					{
						this->iceCount--;
						this->world->getSphere->manage("add", "ice");
					}
				}
			}
			else if (param2 == "stone")
			{
				if (this->stoneCount > 0)
				{
					if (!this->world->getSphere)
					{
						this->stoneCount--;
						this->world->getSphere = new GetSphere();
						this->world->getSphere->owner = this->container->stoneSphere;
						this->world->getSphere->ownerType = "archive";
						this->world->getSphere->ownerPoint = this->container->stoneSphereMyPoint;
						this->world->addChild(this->world->getSphere,6);
						this->world->getSphere->manage("add", "stone");
					}
					else if (this->world->getSphere->listOfStack.size() < 4)
					{
						this->stoneCount--;
						this->world->getSphere->manage("add", "stone");
					}
				}
			}
			else if (param2 == "levin")
			{
				if (this->levinCount > 0)
				{
					if (!this->world->getSphere)
					{
						this->levinCount--;
						this->world->getSphere = new GetSphere();
						this->world->getSphere->owner = this->container->levinSphere;
						this->world->getSphere->ownerType = "archive";
						this->world->getSphere->ownerPoint = this->container->levinSphereMyPoint;
						this->world->addChild(this->world->getSphere,6);
						this->world->getSphere->manage("add", "levin");
					}
					else if (this->world->getSphere->listOfStack.size() < 4)
					{
						this->levinCount--;
						this->world->getSphere->manage("add", "levin");
					}
				}
			}
			else if (param2 == "getAll")
			{
				if (this->getAllCount > 0)
				{
					if (!this->world->getSphere)
					{
						this->getAllCount--;
						this->world->getSphere = new GetSphere("getAll");
						this->world->getSphere->owner = this->container->getAll;
						this->world->getSphere->ownerType = "archive";
						this->world->getSphere->ownerPoint = this->container->getAllMyPoint;
						this->world->addChild(this->world->getSphere,6);
						this->world->getSphere->manage("add", "getAll");
					}
					else
					{
						this->getAllCount--;
						this->world->getSphere->manage("add", "getAll");
					}
				}
			}
		}
		else if (param1 == "push")
		{
			if (param2 == "fire")
			{
				this->fireCount++;
			}
			else if (param2 == "ice")
			{
				this->iceCount++;
			}
			else if (param2 == "stone")
			{
				this->stoneCount++;
			}
			else if (param2 == "levin")
			{
				this->levinCount++;
			}
			else if (param2 == "getAll")
			{
				if (this->container->getAll->currentFrame < 3)
				{
					this->getAllCount++;
				}
				else
				{
					this->archiveManage("push", "fire");
					this->archiveManage("push", "ice");
					this->archiveManage("push", "stone");
					this->archiveManage("push", "levin");
				}
			}
		}
		this->updateInfo();
	}// end function

	void WorldInterface::castGolem()// : void
	{
		this->container->butCastGolem->gotoAndStop(6);
		AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
		this->castRegime("on");
		//if (this->world->road)this->world->road->setVisible(false);
		this->addCast("golem");
	}// end function

	void WorldInterface::castIceman()
	{
		this->container->butCastIceman->gotoAndStop(6);
		AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
		this->castRegime("on");
		if (this->world->road) this->world->road->setVisible(false);
		this->addCast("iceman");
	}// end function

	void WorldInterface::castAir()
	{
		this->container->butCastAir->gotoAndStop(6);
		AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
		this->castRegime("on");
		if (this->world->road)this->world->road->setVisible(false);
		this->addCast("air");
	}// end function

	void WorldInterface::addPause()
	{
		this->container->pause->gotoAndStop((this->container->pause->totalFrames - 1));
		this->container->pauseOpenFlag = false;
		this->container->pauseCloseFlag = true;
		this->world->menuObject = new PauseMenu();
		this->world->addChild(this->world->menuObject,10);
	}// end function

	void WorldInterface::addFastPause()
	{
		this->world->menuObject = new FastPause();
		this->world->addChild(this->world->menuObject,10);
	}// end function

	void WorldInterface::addEncyclopedia()
	{
		//this->world->menuObject = new Encyclopedia();
		//this->world->addChild(this->world->menuObject,10);
		//this->container->book->gotoAndStop((this->container->book->totalFrames - 1));
		//this->container->book.openFlag = false;
		//this->container->book.closeFlag = true;
	}// end function

	void WorldInterface::downloadCast()
	{
		if (this->castGolemCounter > 0)
		{
			if (this->castGolemCounter < this->castGolemTimer)
			{
				this->castGolemCounter++;
				this->container->butCastGolemContContMask->setScaleY(this->castGolemCounter / this->castGolemTimer);
			}
			else
			{
				this->castGolemCounter = 0;
				this->container->butCastGolemContContMask->setScaleY(1);
				this->container->butCastGolem->gotoAndStop(1);
				this->container->butCastGolemCastGolemCase->setMouseEnabled(true);
				this->autoguidersButtons();
				AudioUtil::playSound("Snd_cast_ready.mp3");
			}
		}
		if (this->castIcemanCounter > 0)
		{
			if (this->castIcemanCounter < this->castIcemanTimer)
			{
				this->castIcemanCounter++;
				this->container->butCastIcemanContContMask->setScaleY(this->castIcemanCounter / this->castIcemanTimer);
			}
			else
			{
				this->castIcemanCounter = 0;
				this->container->butCastIcemanContContMask->setScaleY(1);
				this->container->butCastIceman->gotoAndStop(1);
				this->container->butCastIcemanCastIcemanCase->setMouseEnabled(true);
				this->autoguidersButtons();
				AudioUtil::playSound("Snd_cast_ready.mp3");
			}
		}
		if (this->castAirCounter > 0)
		{
			if (this->castAirCounter < this->castAirTimer)
			{
				this->castAirCounter++;
				this->container->butCastAirContContMask->setScaleY(this->castAirCounter / this->castAirTimer);
			}
			else
			{
				this->castAirCounter = 0;
				this->container->butCastAirContContMask->setScaleY(1);
				this->container->butCastAir->gotoAndStop(1);
				this->container->butCastAirCastAirCase->setMouseEnabled(true);
				this->autoguidersButtons();
				AudioUtil::playSound("Snd_cast_ready.mp3");
			}
		}
	}// end function

	void WorldInterface::castRegime(string param1)
	{
		if (param1 == "on")
		{
			this->castMask->setVisible(true);
			this->world->manageMouse("hide");
			this->container->setMouseChildren(false);
			this->container->setMouseEnabled(false);
			this->i = 0;
			while (this->i < this->world->listOfPlaces.size())
			{
				this->world->listOfPlaces[this->i]->setMouseChildren(false);
				this->world->listOfPlaces[this->i]->setMouseEnabled(false);
				i++;
			}
			if (this->world->road)this->world->road->setVisible(true);
		}
		else if (param1 == "off")
		{
			this->castMask->setVisible(false);
			this->world->manageMouse("show");
			this->container->setMouseChildren(true);
			this->container->setMouseEnabled(true);
			this->i = 0;
			while (this->i < this->world->listOfPlaces.size())
			{
				this->world->listOfPlaces[this->i]->setMouseChildren(true);
				this->world->listOfPlaces[this->i]->setMouseEnabled(true);
				i++;
			}
			if (this->world->road)this->world->road->setVisible(false);
			if (this->world->pointer1)
			{
				this->world->pointer1->setAlpha(1);
			}
			if (this->world->pointer2)
			{
				this->world->pointer2->setAlpha(1);
			}
			if (this->world->pointer3)
			{
				this->world->pointer3->setAlpha(1);
			}
		}
	}// end function

	void WorldInterface::fastPlayControl(int param1)
	{
		if (param1 == 2)
		{
			const auto factory = dragonBones::CCFactory::getFactory();
			factory->getClock()->timeScale = 2;
			this->fasterFlag = 2;
		}else
		{
			const auto factory = dragonBones::CCFactory::getFactory();
			factory->getClock()->timeScale = 1;
			this->fasterFlag = 1;
		} 
	}// end function

	void  WorldInterface::barInfoView()
	{
		//if (dynamic_cast<GetSphere *>(this->world->selectObject) && this->world->getSphere)
		//{
		//	if (this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U010)) + ::round(this->world->getSphere->myRadius) + I18N_VALUE(I18N_CODE::U011) + ::round(this->world->getSphere->myDamage));
		//	}
		//	else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U010)) + ::round(this->world->getSphere->myRadius) + I18N_VALUE(I18N_CODE::U012) + ::round(this->world->getSphere->myDamage));
		//	}
		//	else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount == 0)
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U010)) + ::round(this->world->getSphere->myRadius) + I18N_VALUE(I18N_CODE::U013) + ::round(this->world->getSphere->myDamage));
		//	}
		//	else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount > 0)
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U010)) + ::round(this->world->getSphere->myRadius) + I18N_VALUE(I18N_CODE::U014) + ::round(this->world->getSphere->myDamage));
		//	}
		//	else if (this->world->getSphere->getAllCount > 0)
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U010)) + ::round(this->world->getSphere->myRadius) + I18N_VALUE(I18N_CODE::U015) + ::round(this->world->getSphere->myDamage));
		//	}
		//	else if ((this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount == 0)
		//		|| (this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount > 0)
		//		|| (this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount > 0)
		//		|| (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount > 0))
		//	{
		//		if (this->world->getSphere->fireCount > 1 || this->world->getSphere->iceCount > 1 || this->world->getSphere->stoneCount > 1 || this->world->getSphere->levinCount > 1)
		//		{
		//			std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U010)) + ::round(this->world->getSphere->myRadius) + I18N_VALUE(I18N_CODE::U015) + ::round(this->world->getSphere->myDamage * Main::mainClass->readXMLClass.getAllLittleDoubleMultiply));
		//		}
		//		else
		//		{
		//			std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U010)) + ::round(this->world->getSphere->myRadius) + I18N_VALUE(I18N_CODE::U015) + ::round(this->world->getSphere->myDamage * Main::mainClass->readXMLClass.getAllLittleMultiply));
		//		}
		//	}
		//	else
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U010)) + ::round(this->world->getSphere->myRadius) + I18N_VALUE(I18N_CODE::U015) + ::round(this->world->getSphere->myDamage));
		//	}
		//}
		//else if (dynamic_cast<casts::Cast *>(this->world->selectObject) && this->world->cast)
		//{
		//	if (dynamic_cast<casts::Cast_1 *>(this->world->cast))
		//	{
		//		std::setText(this->container->barInfoHealthTXT, ::round(Main::mainClass->readXMLClass.castGolemHealthXML));
		//	}
		//	else if (dynamic_cast<casts::Cast_2 *>(this->world->cast))
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(::round(Main::mainClass->readXMLClass.castIcemanLifeTimerXML / 30)) + I18N_VALUE(I18N_CODE::U016));
		//	}
		//	else if (dynamic_cast<casts::Cast_3 *>(this->world->cast))
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(::round(Main::mainClass->readXMLClass.airLifeSecXML / 30) ) + I18N_VALUE(I18N_CODE::U016));
		//	}
		//}
		//else if (dynamic_cast<Unit *>(this->world->selectObject))
		//{
		//	Unit * unit = dynamic_cast<Unit *>(this->world->selectObject);
		//	std::setText(this->container->barInfoHealthTXT, ::round(unit->health) + Common::String("/") + ::round(unit->healthMax));
		//	if (this->container->barInfoMyTarget != this->world->selectObject)
		//	{
		//		this->container->barInfoMyTarget = this->world->selectObject;
		//		//Common::Array<string> tempObject = Encyclopedia::enemyInfo(this->world->selectObject->typeUnit); 
		//		//std::setText(this->container->barInfoSpeedTXT , tempObject[2] );
		//		//std::setText(this->container->barInfoPenaltyTXT , tempObject[3] ); 
		//		//std::setText(this->container->barInfoFireTXT , tempObject[4] );
		//		//std::setText(this->container->barInfoIceTXT , tempObject[5] );
		//		//std::setText(this->container->barInfoStoneTXT , tempObject[6] );
		//		//std::setText(this->container->barInfoLevinTXT , tempObject[7] );
		//	}
		//}
		//else if (dynamic_cast<Golem *>(this->world->selectObject))
		//{
		//	Golem * golem = dynamic_cast<Golem *>(this->world->selectObject);
		//	if (!golem->brother)
		//	{
		//		std::setText(this->container->barInfoHealthTXT, ::round(golem->health));
		//	}
		//	else
		//	{
		//		float tempObject = 0;
		//		if (!golem->dead && !golem->brother->dead)
		//		{
		//			tempObject = ::round(golem->health) + ::round(golem->brother->health);
		//		}
		//		else if (!golem->dead)
		//		{
		//			tempObject = ::round(golem->health);
		//		}
		//		else if (!golem->brother->dead)
		//		{
		//			tempObject = ::round(golem->brother->health);
		//		}
		//		std::setText(this->container->barInfoHealthTXT, ::round(tempObject));
		//	}
		//}
		//else if (dynamic_cast<Iceman *>(this->world->selectObject))
		//{
		//	Iceman * iceman = dynamic_cast<Iceman *>(this->world->selectObject);
		//	int tempObject = (int)(iceman->liveCounter / 30 + 0.99);
		//	if (tempObject > 0)
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(tempObject) + I18N_VALUE(I18N_CODE::U016));
		//	}
		//	else
		//	{
		//		this->barInfoManage();
		//	}
		//}
		//else if (dynamic_cast<Air *>(this->world->selectObject))
		//{
		//	Air * air = dynamic_cast<Air *>(this->world->selectObject);
		//	int tempObject = (int)(air->liveCounter / 30 + 0.99);
		//	if (tempObject > 0)
		//	{
		//		std::setText(this->container->barInfoNoteTXT, Common::String(tempObject) + I18N_VALUE(I18N_CODE::U016));
		//	}
		//	else
		//	{
		//		this->barInfoManage();
		//	}
		//}
		//else if (dynamic_cast<TowerMenu *>(this->world->selectObject) || dynamic_cast<UltraTowerMenu *>(this->world->selectObject))
		//{
		//	TowerMenu * towerMenu = dynamic_cast<TowerMenu *>(this->world->selectObject);
		//	if (towerMenu->myTower->towerType < 5)
		//	{
		//		std::setText(this->container->barInfoNoteTXT, "");
		//		if (towerMenu->myTower->shootingTurnStack[0])
		//		{
		//			std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U017)) +
		//				::round(Main::mainClass->readXMLClass.listOfFireTowerDamageXML[(towerMenu->myTower->shootingTurnStack[0][3] - 1)]) + I18N_VALUE(I18N_CODE::U018));
		//		}
		//		if (towerMenu->myTower->shootingTurnStack[1])
		//		{
		//			std::setText(this->container->barInfoNoteTXT, Common::String(std::getText(this->container->barInfoNoteTXT))
		//				+ Common::String(I18N_VALUE(I18N_CODE::U019)) + Common::String(::round(Main::mainClass->readXMLClass.listOfIceTowerDamageXML[(towerMenu->myTower->shootingTurnStack[1][3] - 1)])) + Common::String(I18N_VALUE(I18N_CODE::U018)));
		//		}
		//		if (towerMenu->myTower->shootingTurnStack[2])
		//		{
		//			std::setText(this->container->barInfoNoteTXT, std::getText(this->container->barInfoNoteTXT) + Common::String(I18N_VALUE(I18N_CODE::U020)) + Common::String(::round(Main::mainClass->readXMLClass.listOfStoneTowerDamageXML[(towerMenu->myTower->shootingTurnStack[2][3] - 1)])) + I18N_VALUE(I18N_CODE::U018));
		//		}
		//		if (towerMenu->myTower->shootingTurnStack[3])
		//		{
		//			std::setText(this->container->barInfoNoteTXT, std::getText(this->container->barInfoNoteTXT) + Common::String(I18N_VALUE(I18N_CODE::U021)) + Common::String(::round(Main::mainClass->readXMLClass.listOfLevinTowerDamageXML[(towerMenu->myTower->shootingTurnStack[3][3] - 1)])) + I18N_VALUE(I18N_CODE::U018));
		//		}
		//		if (std::getText(this->container->barInfoNoteTXT) == "")
		//		{
		//			std::setText(this->container->barInfoNoteTXT, I18N_VALUE(I18N_CODE::U022));
		//		}
		//		else
		//		{
		//			string noteText = std::getText(this->container->barInfoNoteTXT);
		//			std::setText(this->container->barInfoNoteTXT, noteText.substr(0, noteText.size() - 2));
		//		}
		//	}
		//	else
		//	{
		//		if (towerMenu->myTower->towerType == 8)
		//		{
		//			std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U023)) + ::round(towerMenu->myTower->damage * 3));
		//		}
		//		else
		//		{
		//			std::setText(this->container->barInfoNoteTXT, Common::String(I18N_VALUE(I18N_CODE::U023)) + ::round(towerMenu->myTower->damage));
		//		}
		//		if (towerMenu->myTower->upgradeTypeAdd == 1)
		//		{
		//			if (towerMenu->myTower->towerType == 5)
		//			{
		//				std::setText(this->container->barInfoNoteTXT, std::getText(this->container->barInfoNoteTXT) + Common::String(I18N_VALUE(I18N_CODE::U024))
		//					+ Common::String(::round(towerMenu->myTower->upgr1_damage * 49)));
		//			}
		//			else
		//			{
		//				std::setText(this->container->barInfoNoteTXT, std::getText(this->container->barInfoNoteTXT) + Common::String(I18N_VALUE(I18N_CODE::U024))
		//					+ Common::String(::round(towerMenu->myTower->upgr1_damage)));
		//			}
		//		}
		//	}
		//}
		//else if (this->world->selectObject)
		//{
		//	if (!this->world->towerMenu)
		//	{
		//		this->barInfoManage();
		//	}
		//	else
		//	{
		//		this->barInfoManage(this->world->towerMenu);
		//	}
		//}
		//return;
	}// end function

	void WorldInterface::barInfoManage(BaseNode * param1)
	{
		//if (this->world->selectObject)
		//{
		//	if (dynamic_cast<Unit *>(this->world->selectObject))
		//	{
		//		Unit * unit = dynamic_cast<Unit *>(this->world->selectObject);
		//		unit->container->selectUnit->setVisible(false);
		//	}
		//}
		//if (!param1)
		//{
		//	this->world->selectObject = NULL;
		//	this->world->worldInterface->container->barInfo->gotoAndStop(1);
		//	this->i = this->world->listOfClasses.size() - 1;
		//	while (this->i >= 0)
		//	{
		//		if (dynamic_cast<Golem *>(this->world->listOfClasses[this->i]) || dynamic_cast<Iceman *>(this->world->listOfClasses[this->i])
		//			|| dynamic_cast<Air *>(this->world->listOfClasses[this->i]))
		//		{
		//			this->world->selectObject = this->world->listOfClasses[this->i];
		//			if (dynamic_cast<Golem *>(this->world->listOfClasses[this->i]))
		//			{
		//				this->world->worldInterface->container->barInfo->gotoAndStop(4);
		//			}
		//			else if (dynamic_cast<Iceman *>(this->world->listOfClasses[this->i]) || dynamic_cast<Air *>(this->world->listOfClasses[this->i]))
		//			{
		//				this->world->worldInterface->container->barInfo->gotoAndStop(5);
		//			}
		//			else
		//			{
		//				this->world->worldInterface->container->barInfo->gotoAndStop(2);
		//			}
		//			break;
		//		}
		//		i--;
		//	}
		//}
		//else
		//{
		//	this->world->selectObject = param1;
		//	if (dynamic_cast<Unit *>(this->world->selectObject))
		//	{
		//		Unit * unit = dynamic_cast<Unit *>(this->world->selectObject);
		//		unit->container->selectUnit->setVisible(true);
		//		this->world->worldInterface->container->barInfo->gotoAndStop(3);
		//		this->container->barInfoMyTarget = NULL;
		//	}
		//	else if (dynamic_cast<Golem *>(this->world->selectObject) || dynamic_cast<Cast_1 *>(this->world->selectObject))
		//	{
		//		this->world->worldInterface->container->barInfo->gotoAndStop(4);
		//	}
		//	else if (dynamic_cast<Iceman *>(this->world->selectObject) || dynamic_cast<Cast_2 *>(this->world->selectObject)
		//		|| dynamic_cast<Air *>(this->world->selectObject) || dynamic_cast<Cast_3 *>(this->world->selectObject))
		//	{
		//		this->world->worldInterface->container->barInfo->gotoAndStop(5);
		//	}
		//	else
		//	{
		//		this->world->worldInterface->container->barInfo->gotoAndStop(2);
		//	}
		//	this->barInfoView();
		//}
	}// end function

	void WorldInterface::breaking()
	{
		if (this->world->getSphere)
		{
			this->castRegime("off");
			this->world->getSphere->retrieveGetSphereToArchive();
		}
		else if (this->world->cast)
		{
			if (dynamic_cast<Cast_1 *>(this->world->cast))
			{
				this->container->butCastGolem->gotoAndStop(1);
			}
			else if (dynamic_cast<Cast_2 *>(this->world->cast))
			{
				this->container->butCastIceman->gotoAndStop(1);
			}
			else if (dynamic_cast<Cast_3 *>(this->world->cast))
			{
				this->container->butCastAir->gotoAndStop(1);
			}
			this->world->cast->kill();
		}
		else if (this->world->exchange)
		{
			this->world->exchange->kill();
		}
		return;
	}// end function

	void WorldInterface::hintUpdate()
	{
		if (this->world->hint->isVisible())
		{
			this->world->hint->setPosition(CONVERT_TO_WORLD_POS(Vec2(Main::mouseX, Main::mouseY)));
			if (this->world->hint->currentFrame == 1)
			{
				if (std::getText(this->world->hint->nameTXT) == I18N_VALUE(I18N_CODE::U003))
				{
					if (this->container->butCastGolem->currentFrame == 4)
					{
						std::setText(this->world->hint->timeTXT, (int)((this->castGolemTimer - this->castGolemCounter) / 30) + 1);
						//this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
					}
					else
					{
						this->world->hint->setVisible(false);
					}
				}
				else if (std::getText(this->world->hint->nameTXT) == I18N_VALUE(I18N_CODE::U005))
				{
					if (this->container->butCastIceman->currentFrame == 4)
					{
						std::setText(this->world->hint->timeTXT, (int)((this->castIcemanTimer - this->castIcemanCounter) / 30) + 1);
						//this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
					}
					else
					{
						this->world->hint->setVisible(false);
					}
				}
				else if (std::getText(this->world->hint->nameTXT) == I18N_VALUE(I18N_CODE::U008))
				{
					if (this->container->butCastAir->currentFrame == 4)
					{
						std::setText(this->world->hint->timeTXT, (int)((this->castAirTimer - this->castAirCounter) / 30) + 1);
						//this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
					}
					else
					{
						this->world->hint->setVisible(false);
					}
				}
			}
		}
	}// end function

	void WorldInterface::autoguidersButtons()
	{
		//this->autoguidesMouse_pt = CONVERT_TO_WORLD_POS(cocos2d::Point(Main::mouseX, Main::mouseY));
		//this->autoguidesObject = NULL;
		//this->autoguidesObject_pt = CONVERT_TO_WORLD_POS(this->container->butCastGolem->localToGlobal(this->container->butCastGolemCastGolemCase->getPosition()));
		//this->autoguidesObjectWidth = this->container->butCastGolemCastGolemCase->getWidth() / 2;
		//this->autoguidesObjectHeight = this->container->butCastGolemCastGolemCase->getHeight() / 2;
		//if (this->container->butCastGolemCastGolemCase->hitTest(autoguidesMouse_pt))
		//{
		//	this->autoguidesObject = this->container->butCastGolemCastGolemCase;
		//}
		//if (!this->autoguidesObject)
		//{
		//	this->autoguidesObject_pt =CONVERT_TO_WORLD_POS( this->container->butCastIceman->localToGlobal(this->container->butCastIcemanCastIcemanCase->getPosition()));
		//	this->autoguidesObjectWidth = this->container->butCastIcemanCastIcemanCase->getWidth() / 2;
		//	this->autoguidesObjectHeight = this->container->butCastIcemanCastIcemanCase->getHeight() / 2;
		//	if (this->container->butCastIcemanCastIcemanCase->hitTest(autoguidesMouse_pt))
		//	{
		//		this->autoguidesObject = this->container->butCastIcemanCastIcemanCase;
		//	}
		//}
		//if (!this->autoguidesObject)
		//{
		//	this->autoguidesObject_pt =CONVERT_TO_WORLD_POS( this->container->butCastAir->localToGlobal(this->container->butCastAirCastAirCase->getPosition()));
		//	this->autoguidesObjectWidth = this->container->butCastAirCastAirCase->getWidth() / 2;
		//	this->autoguidesObjectHeight = this->container->butCastAirCastAirCase->getHeight() / 2;
		//	if (this->container->butCastAirCastAirCase->hitTest(autoguidesMouse_pt))
		//	{
		//		this->autoguidesObject = this->container->butCastAirCastAirCase;
		//	}
		//}
		//if (!this->autoguidesObject)
		//{
		//	this->autoguidesObject_pt = CONVERT_TO_WORLD_POS(this->container->fast->localToGlobal(this->container->fastFastCase->getPosition()));
		//	this->autoguidesObjectWidth = this->container->fastFastCase->getWidth() / 2;
		//	this->autoguidesObjectHeight = this->container->fastFastCase->getHeight() / 2;
		//	if (this->container->fastFastCase->hitTest(autoguidesMouse_pt))
		//	{
		//		this->autoguidesObject = this->container->fastFastCase;
		//	}
		//}
		//if (!this->autoguidesObject)
		//{
		//	this->autoguidesObject_pt =CONVERT_TO_WORLD_POS( this->container->fireSphere->localToGlobal(this->container->fireSphereSphereCase->getPosition()));
		//	this->autoguidesObjectWidth = this->container->fireSphereSphereCase->getWidth() / 2;
		//	this->autoguidesObjectHeight = this->container->fireSphereSphereCase->getHeight() / 2;
		//	if (this->container->fireSphereSphereCase->hitTest(autoguidesMouse_pt))
		//	{
		//		this->autoguidesObject = this->container->fireSphereSphereCase;
		//	}
		//}
		//if (!this->autoguidesObject)
		//{
		//	this->autoguidesObject_pt = CONVERT_TO_WORLD_POS(this->container->iceSphere->localToGlobal(this->container->iceSphereSphereCase->getPosition()));
		//	this->autoguidesObjectWidth = this->container->iceSphereSphereCase->getWidth() / 2;
		//	this->autoguidesObjectHeight = this->container->iceSphereSphereCase->getHeight() / 2;
		//	if (this->container->iceSphereSphereCase->hitTest(autoguidesMouse_pt))
		//	{
		//		this->autoguidesObject = this->container->iceSphereSphereCase;
		//	}
		//}
		//if (!this->autoguidesObject)
		//{
		//	this->autoguidesObject_pt = CONVERT_TO_WORLD_POS(this->container->stoneSphere->localToGlobal(this->container->stoneSphereSphereCase->getPosition()));
		//	this->autoguidesObjectWidth = this->container->stoneSphereSphereCase->getWidth() / 2;
		//	this->autoguidesObjectHeight = this->container->stoneSphereSphereCase->getHeight() / 2;
		//	if (this->container->stoneSphereSphereCase->hitTest(autoguidesMouse_pt))
		//	{
		//		this->autoguidesObject = this->container->stoneSphereSphereCase;
		//	}
		//}
		//if (!this->autoguidesObject)
		//{
		//	this->autoguidesObject_pt = CONVERT_TO_WORLD_POS(this->container->levinSphere->localToGlobal(this->container->levinSphereSphereCase->getPosition()));
		//	this->autoguidesObjectWidth = this->container->levinSphereSphereCase->getWidth() / 2;
		//	this->autoguidesObjectHeight = this->container->levinSphereSphereCase->getHeight() / 2;
		//	if (this->container->levinSphereSphereCase->hitTest(autoguidesMouse_pt))
		//	{
		//		this->autoguidesObject = this->container->levinSphereSphereCase;
		//	}
		//}
		//if (!this->autoguidesObject)
		//{
		//	this->autoguidesObject_pt = CONVERT_TO_WORLD_POS(this->container->getAll->localToGlobal(this->container->getAllSphereCase->getPosition()));
		//	this->autoguidesObjectWidth = this->container->getAllSphereCase->getWidth() / 2;
		//	this->autoguidesObjectHeight = this->container->getAllSphereCase->getHeight() / 2;
		//	if (this->container->getAllSphereCase->hitTest(autoguidesMouse_pt))
		//	{
		//		this->autoguidesObject = this->container->getAllSphereCase;
		//	}
		//}
		//if (this->autoguidesObject)
		//{ //模拟event
		//	MouseEvent me = buildMouseEvent(this->autoguidesObject);
		//	this->mouseMoveHandler(&me);
		//}
	}// end function

	void WorldInterface::spheresBlockManage(string param1)
	{
		if (param1 == "")
		{
			this->container->fireSphere->setAlpha(0);
			this->container->fireNumTXT->setAlpha(0);
			this->container->buyFire->setAlpha(0);
			//this->container->fireSphere->setMouseChildren(false);
			//this->container->fireSphere->setMouseEnabled(false);
			//this->container->fireNumTXT->setMouseEnabled(false); 
			//this->container->buyFire->setMouseChildren(false);
			//this->container->buyFire->setMouseEnabled(false);
			this->container->fireSphere->setVisible(false);
 
			this->container->buyFire->gotoAndStop(2);
			this->container->buyIce->gotoAndStop(2);
			this->container->buyStone->gotoAndStop(2);
			this->container->buyLevin->gotoAndStop(2);
			this->container->buyGetAll->gotoAndStop(2);

			this->container->iceSphere->setAlpha(0);
			this->container->iceNumTXT->setAlpha(0);
			this->container->buyIce->setAlpha(0);
			this->container->iceSphere->setMouseChildren(false);
			this->container->iceSphere->setMouseEnabled(false);
			this->container->iceNumTXT->setMouseEnabled(false);
			this->container->buyIce->setMouseChildren(false);
			this->container->buyIce->setMouseEnabled(false);
			this->container->iceSphere->setVisible(false);

			this->container->stoneSphere->setAlpha(0);
			this->container->stoneNumTXT->setAlpha(0);
			this->container->buyStone->setAlpha(0);
			//this->container->stoneSphere->setMouseChildren(false);
			//this->container->stoneSphere->setMouseEnabled(false);
			//this->container->stoneNumTXT->setMouseEnabled(false);
			//this->container->buyStone->setMouseChildren(false);
			//this->container->buyStone->setMouseEnabled(false);
			this->container->stoneSphere->setVisible(false);

			this->container->levinSphere->setAlpha(0);
			this->container->levinNumTXT->setAlpha(0);
			this->container->buyLevin->setAlpha(0);
			//this->container->levinSphere->setMouseChildren(false);
			//this->container->levinSphere->setMouseEnabled(false);
			//this->container->levinNumTXT->setMouseEnabled(false);
			//this->container->buyLevin->setMouseChildren(false);
			//this->container->buyLevin->setMouseEnabled(false);
			this->container->levinSphere->setVisible(false);

			this->container->buyGetAll->setAlpha(0);
			this->container->getAllNumTXT->setAlpha(0);
			//this->container->getAllNumTXT->setMouseEnabled(false);
			//this->container->buyGetAll->setMouseChildren(false);
			//this->container->buyGetAll->setMouseEnabled(false); 

			this->container->getAll->gotoAndStop(3);
			this->container->fireBack->gotoAndStop(3);
			this->container->iceBack->gotoAndStop(3);
			this->container->stoneBack->gotoAndStop(3);
			this->container->levinBack->gotoAndStop(3);
 
			if (Main::mainClass->readXMLClass.archiveSphereBlock == 3)
			{
				this->container->fireSphere->setVisible(true);
				this->container->fireBack->gotoAndStop(1);
				//printNodePos(this->container->fireSphere);
			}
			else if (Main::mainClass->readXMLClass.archiveSphereBlock == 2)
			{
				this->container->fireSphere->setVisible(true);
				this->container->iceSphere->setVisible(true);
				this->container->fireBack->gotoAndStop(1);
				this->container->iceBack->gotoAndStop(1);
			}
			else if (Main::mainClass->readXMLClass.archiveSphereBlock == 1)
			{
				this->container->fireSphere->setVisible(true);
				this->container->iceSphere->setVisible(true);
				this->container->stoneSphere->setVisible(true);
				this->container->fireBack->gotoAndStop(1);
				this->container->iceBack->gotoAndStop(1);
				this->container->stoneBack->gotoAndStop(1);
			}
			else if (Main::mainClass->readXMLClass.archiveSphereBlock == 0)
			{
				this->container->fireSphere->setVisible(true);
				this->container->iceSphere->setVisible(true);
				this->container->stoneSphere->setVisible(true);
				this->container->levinSphere->setVisible(true);
				this->container->fireBack->gotoAndStop(1);
				this->container->iceBack->gotoAndStop(1);
				this->container->stoneBack->gotoAndStop(1);
				this->container->levinBack->gotoAndStop(1);
			}
			if (this->world->saveBox->getIntValue("complexityLevel") == 4)
			{
				if (this->world->nowLevel == 4)
				{
					this->container->stoneSphere->setVisible(true);
					this->container->levinSphere->setVisible(true);
					this->container->stoneBack->gotoAndStop(1);
					this->container->levinBack->gotoAndStop(1);
				}
				else if (this->world->nowLevel == 5)
				{
					this->container->iceSphere->setVisible(true);
					this->container->levinSphere->setVisible(true);
					this->container->iceBack->gotoAndStop(1);
					this->container->levinBack->gotoAndStop(1);
				}
				else if (this->world->nowLevel == 8)
				{
					this->container->fireSphere->setVisible(true);
					this->container->iceSphere->setVisible(true);
					this->container->levinSphere->setVisible(true);
					this->container->fireBack->gotoAndStop(1);
					this->container->iceBack->gotoAndStop(1);
					this->container->levinBack->gotoAndStop(1);
				}
				else if (this->world->nowLevel == 13)
				{
					this->container->iceSphere->setVisible(true);
					this->container->levinSphere->setVisible(true);
					this->container->iceBack->gotoAndStop(1);
					this->container->levinBack->gotoAndStop(1);
				}
				else if (this->world->nowLevel == 15)
				{
					this->container->fireSphere->setVisible(true);
					this->container->iceSphere->setVisible(true);
					this->container->levinSphere->setVisible(true);
					this->container->fireBack->gotoAndStop(1);
					this->container->iceBack->gotoAndStop(1);
					this->container->levinBack->gotoAndStop(1);
				}
			}
		}
		else if (param1 == "unblockFire")
		{
			this->container->fireSphere->setScaleY(1);
			this->container->fireSphere->setScaleX(1);
			this->container->fireSphere->setAlpha(1);
			this->container->fireNumTXT->setAlpha(1);
			this->container->buyFire->setAlpha(1);
			this->container->fireSphere->setMouseChildren(true);
			this->container->fireSphere->setMouseEnabled(true);
			this->container->fireNumTXT->setMouseEnabled(false);
			this->container->buyFire->setMouseChildren(true);
			this->container->buyFire->setMouseEnabled(true);
			this->container->fireBack->gotoAndStop(1);
		}
		else if (param1 == "unblockIce")
		{
			this->container->iceSphere->setScaleY(1);
			this->container->iceSphere->setScaleX(1);
			this->container->iceSphere->setAlpha(1);
			this->container->iceNumTXT->setAlpha(1);
			this->container->buyIce->setAlpha(1);
			this->container->iceSphere->setMouseChildren(true);
			this->container->iceSphere->setMouseEnabled(true);
			this->container->iceNumTXT->setMouseEnabled(false);
			this->container->buyIce->setMouseChildren(true);
			this->container->buyIce->setMouseEnabled(true);
			this->container->iceBack->gotoAndStop(1);
		}
		else if (param1 == "unblockStone")
		{
			this->container->stoneSphere->setScaleY(1);
			this->container->stoneSphere->setScaleX(1);
			this->container->stoneSphere->setAlpha(1);
			this->container->stoneNumTXT->setAlpha(1);
			this->container->buyStone->setAlpha(1);
			this->container->stoneSphere->setMouseChildren(true);
			this->container->stoneSphere->setMouseEnabled(true);
			this->container->stoneNumTXT->setMouseEnabled(false);
			this->container->buyStone->setMouseChildren(true);
			this->container->buyStone->setMouseEnabled(true);
			this->container->stoneBack->gotoAndStop(1);
		}
		else if (param1 == "unblockLevin")
		{
			this->container->levinSphere->setScaleY(1);
			this->container->levinSphere->setScaleX(1);
			this->container->levinSphere->setAlpha(1);
			this->container->levinNumTXT->setAlpha(1);
			this->container->buyLevin->setAlpha(1);
			this->container->levinSphere->setMouseChildren(true);
			this->container->levinSphere->setMouseEnabled(true);
			this->container->levinNumTXT->setMouseEnabled(false);
			this->container->buyLevin->setMouseChildren(true);
			this->container->buyLevin->setMouseEnabled(true);
			this->container->levinBack->gotoAndStop(1);
		}
		else if (param1 == "unblockGetAll")
		{
			this->container->getAll->setScaleY(1);
			this->container->getAll->setScaleX(1);
			this->container->getAll->gotoAndStop(1);
			this->container->getAllFire->stop();
			this->container->getAllIce->stop();
			this->container->getAllStone->stop();
			this->container->getAllLevin->stop();
			this->container->buyGetAll->setAlpha(1);
			this->container->getAllNumTXT->setAlpha(1);
			this->container->getAllNumTXT->setMouseEnabled(false);
			this->container->buyGetAll->setMouseChildren(true);
			this->container->buyGetAll->setMouseEnabled(true);
		}
		this->updateInfo();
		return;
	}// end function 

	void WorldInterface::archiveSphereBacklightManage(string param1)
	{
		BaseTowerMenu *tempObject = NULL;
		if (this->world->towerMenu)
		{
			tempObject = this->world->towerMenu;
		}
		else if (this->world->ultraTowerMenu)
		{
			tempObject = this->world->ultraTowerMenu;
		}
		if (param1 == "fire")
		{
			if (!this->container->fireBacklight->isVisible())
			{
				this->container->fireBacklight->setVisible(true);
			}
			if (!tempObject->myTower->shootingTurnStack[0])
			{
				if (this->container->fireBacklight->currentFrame == 1)
				{
					this->container->fireBacklight->gotoAndStop(this->container->fireBacklight->totalFrames);
				}
			}
			else if (this->container->fireBacklight->currentFrame != 1)
			{
				this->container->fireBacklight->gotoAndStop(1);
			}
		}
		else if (param1 == "ice")
		{
			if (!this->container->iceBacklight->isVisible())
			{
				this->container->iceBacklight->setVisible(true);
			}
			if (!tempObject->myTower->shootingTurnStack[1])
			{
				if (this->container->iceBacklight->currentFrame == 1)
				{
					this->container->iceBacklight->gotoAndStop(this->container->iceBacklight->totalFrames);
				}
			}
			else if (this->container->iceBacklight->currentFrame != 1)
			{
				this->container->iceBacklight->gotoAndStop(1);
			}
		}
		else if (param1 == "stone")
		{
			if (!this->container->stoneBacklight->isVisible())
			{
				this->container->stoneBacklight->setVisible(true);
			}
			if (!tempObject->myTower->shootingTurnStack[2])
			{
				if (this->container->stoneBacklight->currentFrame == 1)
				{
					this->container->stoneBacklight->gotoAndStop(this->container->stoneBacklight->totalFrames);
				}
			}
			else if (this->container->stoneBacklight->currentFrame != 1)
			{
				this->container->stoneBacklight->gotoAndStop(1);
			}
		}
		else if (param1 == "levin")
		{
			if (!this->container->levinBacklight->isVisible())
			{
				this->container->levinBacklight->setVisible(true);
			}
			if (!tempObject->myTower->shootingTurnStack[3])
			{
				if (this->container->levinBacklight->currentFrame == 1)
				{
					this->container->levinBacklight->gotoAndStop(this->container->levinBacklight->totalFrames);
				}
			}
			else if (this->container->levinBacklight->currentFrame != 1)
			{
				this->container->levinBacklight->gotoAndStop(1);
			}
		}
		else
		{
			if (this->container->fireBacklight->currentFrame != 1)
			{
				this->container->fireBacklight->gotoAndStop(1);
			}
			if (this->container->iceBacklight->currentFrame != 1)
			{
				this->container->iceBacklight->gotoAndStop(1);
			}
			if (this->container->stoneBacklight->currentFrame != 1)
			{
				this->container->stoneBacklight->gotoAndStop(1);
			}
			if (this->container->levinBacklight->currentFrame != 1)
			{
				this->container->levinBacklight->gotoAndStop(1);
			}
			if (!this->container->fireBacklightTurnFlag)
			{
				this->container->fireBacklightTurnFlag = true;
			}
			if (!this->container->iceBacklightTurnFlag)
			{
				this->container->iceBacklightTurnFlag = true;
			}
			if (!this->container->stoneBacklightTurnFlag)
			{
				this->container->stoneBacklightTurnFlag = true;
			}
			if (!this->container->levinBacklightTurnFlag)
			{
				this->container->levinBacklightTurnFlag = true;
			}
			if (this->container->fireBacklight->isVisible())
			{
				this->container->fireBacklight->setVisible(false);
			}
			if (this->container->iceBacklight->isVisible())
			{
				this->container->iceBacklight->setVisible(false);
			}
			if (this->container->stoneBacklight->isVisible())
			{
				this->container->stoneBacklight->setVisible(false);
			}
			if (this->container->levinBacklight->isVisible())
			{
				this->container->levinBacklight->setVisible(false);
			}
		}
	}// end function

	void WorldInterface::fasterManage(bool param1)
	{
		if (this->fasterFlag != 2)
		{
			if (param1)
				this->container->fast->gotoAndStop(5);
			else
				this->container->fast->gotoAndStop(4);
			this->container->fastCont->stop();
			this->fastPlayControl(2);
		}
		else
		{
			if (param1)
				this->container->fast->gotoAndStop(2);
			else
				this->container->fast->gotoAndStop(1);
			this->fastPlayControl(1);
		}
	}// end function

	void WorldInterface::sellSphere(string param1)
	{
		int tempObject = 0;
		if (param1 == "fire")
		{
			if (this->sphereCostHistory[0].size() > 0)
			{
				tempObject = this->sphereCostHistory[0].pop();
			}
			else
			{
				tempObject = Main::mainClass->readXMLClass.listOfFirePriceXML[0];
			}
			this->world->money = this->world->money + ::round(tempObject * Main::mainClass->readXMLClass.fireSellTax);
			this->world->sellFireCounter++;
			int addit_sellFireCounter = this->world->saveBox->getIntValue("addit_sellFireCounter") + 1;
			this->world->saveBox->setValue("addit_sellFireCounter", addit_sellFireCounter);//.gameSave.data.addit_sellFireCounter + 1);
			if (addit_sellFireCounter == 10)
			{
				this->world->achieveManage("sellFire_10_times");
			}
		}
		else if (param1 == "ice")
		{
			if (this->sphereCostHistory[1].size() > 0)
			{
				tempObject = this->sphereCostHistory[1].pop();
			}
			else
			{
				tempObject = Main::mainClass->readXMLClass.listOfIcePriceXML[0];
			}
			this->world->money = this->world->money + ::round(tempObject * Main::mainClass->readXMLClass.iceSellTax);
			this->world->sellIceCounter++;
			int addit_sellIceCounter = this->world->saveBox->getIntValue("addit_sellIceCounter") + 1;
			this->world->saveBox->setValue("addit_sellIceCounter", addit_sellIceCounter);
			if (addit_sellIceCounter == 10)
			{
				this->world->achieveManage("sellIce_10_times");
			}
		}
		else if (param1 == "stone")
		{
			if (this->sphereCostHistory[2].size() > 0)
			{
				tempObject = this->sphereCostHistory[2].pop();
			}
			else
			{
				tempObject = Main::mainClass->readXMLClass.listOfStonePriceXML[0];
			}
			this->world->money = this->world->money + ::round(tempObject * Main::mainClass->readXMLClass.stoneSellTax);
			this->world->sellStoneCounter++;
			int addit_sellStoneCounter = this->world->saveBox->getIntValue("addit_sellStoneCounter") + 1;
			this->world->saveBox->setValue("addit_sellStoneCounter", addit_sellStoneCounter);
			if (addit_sellStoneCounter == 10)
			{
				this->world->achieveManage("sellStone_10_times");
			}
		}
		else if (param1 == "levin")
		{
			if (this->sphereCostHistory[3].size() > 0)
			{
				tempObject = this->sphereCostHistory[3].pop();
			}
			else
			{
				tempObject = Main::mainClass->readXMLClass.listOfLevinPriceXML[0];
			}
			this->world->money = this->world->money + ::round(tempObject * Main::mainClass->readXMLClass.levinSellTax);
			this->world->sellLevinCounter++;
			int addit_sellLevinCounter = this->world->saveBox->getIntValue("addit_sellLevinCounter") + 1;
			this->world->saveBox->setValue("addit_sellLevinCounter", addit_sellLevinCounter);
			if (addit_sellLevinCounter == 10)
			{
				this->world->achieveManage("sellLevin_10_times");
			}
		}
		else if (param1 == "getAll")
		{
			this->sellSphere("fire");
			this->sellSphere("ice");
			this->sellSphere("stone");
			this->sellSphere("levin");
			this->world->sellGetAllCounter++;
			this->world->achieveManage("sellFireIceStoneLevin");
		}
		this->updateInfo();
	}// end function

	void WorldInterface::addGetAchieve(string param1)
	{
		GetAchieve_mc * tempObject = new GetAchieve_mc();
		tempObject->stop();
		tempObject->icon->stop();
		tempObject->board->stop();
		tempObject->setPositionX(435);
		tempObject->setPositionY(20 + 42);
		//tempObject->setPositionY(this->container->barInfo->getPositionY() + 42);
		tempObject->closeFlag = false;
		tempObject->counter = 30;
		tempObject->setMouseChildren(false);
		tempObject->setMouseEnabled(false);
		this->addChild(tempObject);
		this->listOfGetAhieve.push(tempObject);
		if (param1 == "firstKill")
		{
			tempObject->icon->gotoAndStop(1);
			tempObject->myText = I18N_VALUE(I18N_CODE::U025);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U025));
		}
		else if (param1 == "kill_100_enemies")
		{
			tempObject->icon->gotoAndStop(2);
			tempObject->myText = I18N_VALUE(I18N_CODE::U026);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U026));
		}
		else if (param1 == "kill_2500_enemies")
		{
			tempObject->icon->gotoAndStop(3);
			tempObject->myText = I18N_VALUE(I18N_CODE::U027);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U027));
		}
		else if (param1 == "call_100_earlyWaves")
		{
			tempObject->icon->gotoAndStop(4);
			tempObject->myText = I18N_VALUE(I18N_CODE::U028);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U028));
		}
		else if (param1 == "build_100_towers")
		{
			tempObject->icon->gotoAndStop(5);
			tempObject->myText = I18N_VALUE(I18N_CODE::U029);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U029));
		}
		else if (param1 == "createGolem_5_times")
		{
			tempObject->icon->gotoAndStop(6);
			tempObject->myText = I18N_VALUE(I18N_CODE::U030);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U030));
		}
		else if (param1 == "createIceman_15_times")
		{
			tempObject->icon->gotoAndStop(7);
			tempObject->myText = I18N_VALUE(I18N_CODE::U031);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U031));
		}
		else if (param1 == "createAir_7_times")
		{
			tempObject->icon->gotoAndStop(8);
			tempObject->myText = I18N_VALUE(I18N_CODE::U032);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U032));
		}
		else if (param1 == "callAllWavesInLevel")
		{
			tempObject->icon->gotoAndStop(9);
			tempObject->myText = I18N_VALUE(I18N_CODE::U033);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U033));
		}
		else if (param1 == "sellFireIceStoneLevin")
		{
			tempObject->icon->gotoAndStop(10);
			tempObject->myText = I18N_VALUE(I18N_CODE::U034);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U034));
		}
		else if (param1 == "sellFire_10_times")
		{
			tempObject->icon->gotoAndStop(11);
			tempObject->myText = I18N_VALUE(I18N_CODE::U035);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U035));
		}
		else if (param1 == "sellIce_10_times")
		{
			tempObject->icon->gotoAndStop(12);
			tempObject->myText = I18N_VALUE(I18N_CODE::U036);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U036));
		}
		else if (param1 == "sellStone_10_times")
		{
			tempObject->icon->gotoAndStop(13);
			tempObject->myText = I18N_VALUE(I18N_CODE::U037);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U037));
		}
		else if (param1 == "sellLevin_10_times")
		{
			tempObject->icon->gotoAndStop(14);
			tempObject->myText = I18N_VALUE(I18N_CODE::U038);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U038));
		}
		else if (param1 == "golemKill_250_enemies")
		{
			tempObject->icon->gotoAndStop(15);
			tempObject->myText = I18N_VALUE(I18N_CODE::U039);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U039));
		}
		else if (param1 == "icemanSlowdown_75_enemies")
		{
			tempObject->icon->gotoAndStop(16);
			tempObject->myText = I18N_VALUE(I18N_CODE::U040);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U040));
		}
		else if (param1 == "icemanSlowdown_500_enemies")
		{
			tempObject->icon->gotoAndStop(17);
			tempObject->myText = I18N_VALUE(I18N_CODE::U041);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U041));
		}
		else if (param1 == "buildUltraTower")
		{
			tempObject->icon->gotoAndStop(18);
			tempObject->myText = I18N_VALUE(I18N_CODE::U042);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U042));
		}
		else if (param1 == "buildUltraTower_50_times")
		{
			tempObject->icon->gotoAndStop(19);
			tempObject->myText = I18N_VALUE(I18N_CODE::U043);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U043));
		}
		else if (param1 == "buildAllUltraTowers")
		{
			tempObject->icon->gotoAndStop(20);
			tempObject->myText = I18N_VALUE(I18N_CODE::U044);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U044));
		}
		else if (param1 == "notCast")
		{
			tempObject->icon->gotoAndStop(21);
			tempObject->myText = I18N_VALUE(I18N_CODE::U045);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U045));
		}
		else if (param1 == "castFire_150_times")
		{
			tempObject->icon->gotoAndStop(22);
			tempObject->myText = I18N_VALUE(I18N_CODE::U046);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U046));
		}
		else if (param1 == "castIce_150_times")
		{
			tempObject->icon->gotoAndStop(23);
			tempObject->myText = I18N_VALUE(I18N_CODE::U047);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U047));
		}
		else if (param1 == "castStone_150_times")
		{
			tempObject->icon->gotoAndStop(24);
			tempObject->myText = I18N_VALUE(I18N_CODE::U048);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U048));
		}
		else if (param1 == "castLevin_150_times")
		{
			tempObject->icon->gotoAndStop(25);
			tempObject->myText = I18N_VALUE(I18N_CODE::U049);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U049));
		}
		else if (param1 == "castGetAll_10_times")
		{
			tempObject->icon->gotoAndStop(26);
			tempObject->myText = I18N_VALUE(I18N_CODE::U050);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U050));
		}
		else if (param1 == "castGetAll_100_times")
		{
			tempObject->icon->gotoAndStop(27);
			tempObject->myText = I18N_VALUE(I18N_CODE::U051);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U051));
		}
		else if (param1 == "castKill_1_enemy")
		{
			tempObject->icon->gotoAndStop(28);
			tempObject->myText = I18N_VALUE(I18N_CODE::U052);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U052));
		}
		else if (param1 == "castKill_100_enemy")
		{
			tempObject->icon->gotoAndStop(29);
			tempObject->myText = I18N_VALUE(I18N_CODE::U053);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U053));
		}
		else if (param1 == "complete_10_hardLevels")
		{
			tempObject->icon->gotoAndStop(30);
			tempObject->myText = I18N_VALUE(I18N_CODE::U054);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U054));
		}
		else if (param1 == "complete_10_survivalLevels")
		{
			tempObject->icon->gotoAndStop(31);
			tempObject->myText = I18N_VALUE(I18N_CODE::U055);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U055));
		}
		else if (param1 == "complete_10_withAllLives")
		{
			tempObject->icon->gotoAndStop(32);
			tempObject->myText = I18N_VALUE(I18N_CODE::U056);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U056));
		}
		else if (param1 == "achieve_dude_01")
		{
			tempObject->icon->gotoAndStop(33);
			tempObject->myText = I18N_VALUE(I18N_CODE::U057);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U057));
		}
		else if (param1 == "achieve_dude_02")
		{
			tempObject->icon->gotoAndStop(34);
			tempObject->myText = I18N_VALUE(I18N_CODE::U058);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U058));
		}
		else if (param1 == "achieve_dude_03")
		{
			tempObject->icon->gotoAndStop(35);
			tempObject->myText = I18N_VALUE(I18N_CODE::U059);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U059));
		}
		else if (param1 == "achieve_dude_04")
		{
			tempObject->icon->gotoAndStop(36);
			tempObject->myText = I18N_VALUE(I18N_CODE::U060);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U060));
		}
		else if (param1 == "achieve_dude_05")
		{
			tempObject->icon->gotoAndStop(37);
			tempObject->myText = I18N_VALUE(I18N_CODE::U061);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U061));
		}
		else if (param1 == "achieve_dude_06")
		{
			tempObject->icon->gotoAndStop(38);
			tempObject->myText = I18N_VALUE(I18N_CODE::U062);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U062));
		}
		else if (param1 == "achieve_dude_07")
		{
			tempObject->icon->gotoAndStop(39);
			tempObject->myText = I18N_VALUE(I18N_CODE::U063);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U063));
		}
		else if (param1 == "achieve_dude_08")
		{
			tempObject->icon->gotoAndStop(40);
			tempObject->myText = I18N_VALUE(I18N_CODE::U064);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U064));
		}
		else if (param1 == "achieve_dude_09")
		{
			tempObject->icon->gotoAndStop(41);
			tempObject->myText = I18N_VALUE(I18N_CODE::U065);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U065));
		}
		else if (param1 == "achieve_dude_10")
		{
			tempObject->icon->gotoAndStop(42);
			tempObject->myText = I18N_VALUE(I18N_CODE::U066);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U066));
		}
		else if (param1 == "achieve_dude_11")
		{
			tempObject->icon->gotoAndStop(43);
			tempObject->myText = I18N_VALUE(I18N_CODE::U067);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U067));
		}
		else if (param1 == "achieve_dude_12")
		{
			tempObject->icon->gotoAndStop(44);
			tempObject->myText = I18N_VALUE(I18N_CODE::U068);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U068));
		}
		else if (param1 == "achieve_dude_13")
		{
			tempObject->icon->gotoAndStop(45);
			tempObject->myText = I18N_VALUE(I18N_CODE::U069);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U069));
		}
		else if (param1 == "achieve_dude_14")
		{
			tempObject->icon->gotoAndStop(46);
			tempObject->myText = I18N_VALUE(I18N_CODE::U070);
			std::setText(tempObject->boardNoteTXT, I18N_VALUE(I18N_CODE::U070));
		}

	}// end function

	void WorldInterface::newEnemyUpdate()
	{
		this->i = this->listOfNewEnemies.size() - 1;
		while (this->i >= 0)
		{
			MouseStatusMC * tempObject = this->listOfNewEnemies[this->i];
			tempObject->tryPlay();
			//if (tempObject->currentFrame < tempObject->totalFrames)
			//{
			//	tempObject->gotoAndStop((tempObject->currentFrame + 1));
			//}
			//else
			//{
			//	tempObject->gotoAndStop(1);
			//}
			if (this->world->getSphere || this->world->cast)
			{
				if (tempObject->isVisible())
				{
					tempObject->setVisible(false);
				}
			}
			else if (!tempObject->isVisible())
			{
				tempObject->setVisible(true);
			}
			if (tempObject->getPositionX() == 0)
			{
				tempObject->setPositionX(Main::SCREEN_WIDTH - 40);				 
				if (dynamic_cast<NewEnemy_mc *>(tempObject))
				{
					NewEnemy_mc * enmc = dynamic_cast<NewEnemy_mc *>(tempObject);
					enmc->newEnemyCase->setMouseEnabled(true);
				}
				else if (dynamic_cast<NewElement_mc *>(tempObject))
				{
					NewElement_mc * enmc = dynamic_cast<NewElement_mc *>(tempObject);
					enmc->newElementCase->setMouseEnabled(true);
				}
				tempObject->mouseStatus = 1;
				tempObject->setScaleY(0);
				tempObject->setScaleX(0);
				if (this->listOfNewEnemies.size() > 3)
				{
					this->listOfNewEnemies[0]->mouseStatus = 4;
					this->listOfNewEnemies[0]->setMouseEnabled(false);
					this->listOfNewEnemies[0]->setMouseChildren(false);
				}
				if (this->listOfNewEnemies.size() > 4)
				{
					this->listOfNewEnemies[1]->mouseStatus = 4;
					this->listOfNewEnemies[1]->setMouseEnabled(false);
					this->listOfNewEnemies[1]->setMouseChildren(false);
				}
				if (this->listOfNewEnemies.size() > 5)
				{
					this->listOfNewEnemies[2]->mouseStatus = 4;
					this->listOfNewEnemies[2]->setMouseEnabled(false);
					this->listOfNewEnemies[2]->setMouseChildren(false);
				}
				if (this->listOfNewEnemies.size() > 6)
				{
					this->listOfNewEnemies[3]->mouseStatus = 4;
					this->listOfNewEnemies[3]->setMouseEnabled(false);
					this->listOfNewEnemies[3]->setMouseChildren(false);
				}
			}
			if (tempObject->mouseStatus != 3 && tempObject->mouseStatus != 4)
			{
				if (this->world->nowLevel != 12)
				{
					if (tempObject->getPositionY() == 0)
					{
						if (this->listOfNewEnemies.size() == 1)
						{
							tempObject->setPositionY(100);
						}
						else
						{
							if (this->listOfNewEnemies.size() > 0)
							{
								if (this->listOfNewEnemies[0]->getPositionY() == 0)
								{
									this->listOfNewEnemies[0]->setPositionY(100);
								}
							}
							if (this->listOfNewEnemies.size() > 1)
							{
								if (this->listOfNewEnemies[1]->getPositionY() == 0)
								{
									this->listOfNewEnemies[1]->setPositionY(this->listOfNewEnemies[0]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 2)
							{
								if (this->listOfNewEnemies[2]->getPositionY() == 0)
								{
									this->listOfNewEnemies[2]->setPositionY(this->listOfNewEnemies[1]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 3)
							{
								if (this->listOfNewEnemies[3]->getPositionY() == 0)
								{
									this->listOfNewEnemies[3]->setPositionY(this->listOfNewEnemies[2]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 4)
							{
								if (this->listOfNewEnemies[4]->getPositionY() == 0)
								{
									this->listOfNewEnemies[4]->setPositionY(this->listOfNewEnemies[3]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 5)
							{
								if (this->listOfNewEnemies[5]->getPositionY() == 0)
								{
									this->listOfNewEnemies[5]->setPositionY(this->listOfNewEnemies[4]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 6)
							{
								if (this->listOfNewEnemies[6]->getPositionY() == 0)
								{
									this->listOfNewEnemies[6]->setPositionY(this->listOfNewEnemies[5]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 7)
							{
								if (this->listOfNewEnemies[7]->getPositionY() == 0)
								{
									this->listOfNewEnemies[7]->setPositionY(this->listOfNewEnemies[6]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 8)
							{
								if (this->listOfNewEnemies[8]->getPositionY() == 0)
								{
									this->listOfNewEnemies[8]->setPositionY(this->listOfNewEnemies[8]->getPositionY() + 50);
								}
							}
						}
					}
					else if (tempObject->getPositionY() > 100)
					{
						if (this->i == 0)
						{
							if (tempObject->getPositionY() > 100)
							{
								tempObject->setPositionY(tempObject->getPositionY() - 10);
							}
						}
						else if (this->i == 1)
						{
							if (tempObject->getPositionY() > 150)
							{
								tempObject->setPositionY(tempObject->getPositionY() - 10);
							}
						}
						else if (this->i == 2)
						{
							if (tempObject->getPositionY() > 200)
							{
								tempObject->setPositionY(tempObject->getPositionY() - 10);
							}
						}
					}
					if (tempObject->getScaleX() < 1)
					{
						tempObject->setScaleX(tempObject->getScaleX() + 0.25);
						tempObject->setScaleY(tempObject->getScaleY() + 0.25);
						if (tempObject->getScaleX() > 1)
						{
							tempObject->setScaleY(1);
							tempObject->setScaleX(1);
						}
					}
				}
				else
				{
					if (tempObject->getPositionY() == 0)
					{
						if (this->listOfNewEnemies.size() == 1)
						{
							tempObject->setPositionY(200);
						}
						else
						{
							if (this->listOfNewEnemies.size() > 0)
							{
								if (this->listOfNewEnemies[0]->getPositionY() == 0)
								{
									this->listOfNewEnemies[0]->setPositionY(200);
								}
							}
							if (this->listOfNewEnemies.size() > 1)
							{
								if (this->listOfNewEnemies[1]->getPositionY() == 0)
								{
									this->listOfNewEnemies[1]->setPositionY(this->listOfNewEnemies[0]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 2)
							{
								if (this->listOfNewEnemies[2]->getPositionY() == 0)
								{
									this->listOfNewEnemies[2]->setPositionY(this->listOfNewEnemies[1]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 3)
							{
								if (this->listOfNewEnemies[3]->getPositionY() == 0)
								{
									this->listOfNewEnemies[3]->setPositionY(this->listOfNewEnemies[2]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 4)
							{
								if (this->listOfNewEnemies[4]->getPositionY() == 0)
								{
									this->listOfNewEnemies[4]->setPositionY(this->listOfNewEnemies[3]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 5)
							{
								if (this->listOfNewEnemies[5]->getPositionY() == 0)
								{
									this->listOfNewEnemies[5]->setPositionY(this->listOfNewEnemies[4]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 6)
							{
								if (this->listOfNewEnemies[6]->getPositionY() == 0)
								{
									this->listOfNewEnemies[6]->setPositionY(this->listOfNewEnemies[5]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 7)
							{
								if (this->listOfNewEnemies[7]->getPositionY() == 0)
								{
									this->listOfNewEnemies[7]->setPositionY(this->listOfNewEnemies[6]->getPositionY() + 50);
								}
							}
							if (this->listOfNewEnemies.size() > 8)
							{
								if (this->listOfNewEnemies[8]->getPositionY() == 0)
								{
									this->listOfNewEnemies[8]->setPositionY(this->listOfNewEnemies[8]->getPositionY() + 50);
								}
							}
						}
					}
					else if (tempObject->getPositionY() > 200)
					{
						if (this->i == 0)
						{
							if (tempObject->getPositionY() > 200)
							{
								tempObject->setPositionY(tempObject->getPositionY() - 10);
							}
						}
						else if (this->i == 1)
						{
							if (tempObject->getPositionY() > 250)
							{
								tempObject->setPositionY(tempObject->getPositionY() - 10);
							}
						}
						else if (this->i == 2)
						{
							if (tempObject->getPositionY() > 300)
							{
								tempObject->setPositionY(tempObject->getPositionY() - 10);
							}
						}
					}
					if (tempObject->getScaleX() < 1)
					{
						tempObject->setScaleX(tempObject->getScaleX() + 0.25);
						tempObject->setScaleY(tempObject->getScaleY() + 0.25);
						if (tempObject->getScaleX() > 1)
						{
							tempObject->setScaleY(1);
							tempObject->setScaleX(1);
						}
					}
				}
			}
			else if (tempObject->mouseStatus == 3)
			{
				if (tempObject->getScaleX() > 0)
				{
					tempObject->setScaleX(tempObject->getScaleX() - 0.25);
					tempObject->setScaleY(tempObject->getScaleY() - 0.25);
					if (tempObject->getScaleX() < 0)
					{
						tempObject->setScaleY(0);
						tempObject->setScaleX(0);
					}
				}
				else if (dynamic_cast<NewEnemy_mc *>(tempObject))
				{
					//this->world->menuObject = new Education("newEnemy", tempObject->typeUnit);
					//this->world->addChild(this->world->menuObject,5);
					this->removeChild(tempObject);
					this->listOfNewEnemies.splice(this->i, 1);
				}
				else if (dynamic_cast<NewElement_mc *>(tempObject))
				{
					if (!this->world->menuObject)
					{
						//this->world->menuObject = new Training_5(tempObject->type);
						//this->world->addChild(this->world->menuObject,5);
					}
					this->removeChild(tempObject);
					this->listOfNewEnemies.splice(this->i, 1);
				}
			}
			else if (tempObject->mouseStatus == 4)
			{
				if (tempObject->getScaleX() > 0)
				{
					tempObject->setScaleX(tempObject->getScaleX() - 0.25);
					tempObject->setScaleY(tempObject->getScaleY() - 0.25);
					if (tempObject->getScaleX() < 0)
					{
						tempObject->setScaleY(0);
						tempObject->setScaleX(0);
					}
				}
				else
				{
					this->removeChild(tempObject);
					this->listOfNewEnemies.splice(this->i, 1);
				}
			}
			i--;
		}
	}// end function
}
