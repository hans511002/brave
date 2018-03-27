#include "WorldInterface.h"
#include "MainClass.h"
#include "World.h"
namespace engine
{
	WorldInterface::WorldInterface() :fireCount(0), iceCount(0), stoneCount(0), levinCount(0), getAllCount(0), 
		fireBuyHistory(0), iceBuyHistory(0), stoneBuyHistory(0), levinBuyHistory(0), fasterFlag(0),
		castGolemCounter(0), castIcemanCounter(0), castAirCounter(0)
	{
		//this->sphereCostHistory = [[], [], [], []];
		//this->listOfNewEnemies = [];
		//this->listOfGetAhieve = [];
		//this->listOfAnimation = [];
		//this->addEventListener(Event.ADDED_TO_STAGE, this->init);
	}// end function

	bool WorldInterface::init()// (event:Event) : void
	{
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		this->world = Main::mainClass->worldClass;

		BaseNode *point = this->world->pointer1;// Sprite::create("public/point.png");
		//point->setPosition(400, 250);
		EventListenerMouse *mouseListener= cocos2d::EventListenerMouse::create();
        mouseListener->onMouseDown = CC_CALLBACK_1(WorldInterface::mouseDownHandler, this);
        mouseListener->onMouseUp = CC_CALLBACK_1(WorldInterface::mouseUpHandler, this);
        mouseListener->onMouseMove = CC_CALLBACK_1(WorldInterface::mouseMoveHandler, this); 
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
       
        
 		//this->addChild(point);

		
		point->setVisible(true);
		this->setVisible(true);

		//this->mouseChildren = false;
		//this->mouseEnabled = false;
		//this->alpha = 0;
		this->container = new WorldInterface_mc();
        this->addChild(this->container);
        this->container->init();
        this->container->setPosition(0, 0);
 
		//this->container->stop();
		//this->container->fireBack.stop();
		//this->container->iceBack.stop();
		//this->container->stoneBack.stop();
		//this->container->levinBack.stop();
		//this->container->backComponents.stop();
		//this->container->fireSphere.stop();
		//this->container->iceSphere.stop();
		//this->container->stoneSphere.stop();
		//this->container->levinSphere.stop();
		//this->container->getAll.stop();
		//this->container->buyFire.stop();
		//this->container->buyIce.stop();
		//this->container->buyStone.stop();
		//this->container->buyLevin.stop();
		//this->container->buyGetAll.stop();
		//this->container->buyFire.coin.stop();
		//this->container->buyIce.coin.stop();
		//this->container->buyStone.coin.stop();
		//this->container->buyLevin.coin.stop();
		//this->container->buyGetAll.coin.stop();
		//this->container->buyFire.lightUp.stop();
		//this->container->buyIce.lightUp.stop();
		//this->container->buyStone.lightUp.stop();
		//this->container->buyLevin.lightUp.stop();
		//this->container->buyGetAll.lightUp.stop();
		//this->container->sell.stop();
		//this->container->book.stop();
		//this->container->pause.stop();
		//this->container->startWaves.stop();
		//this->container->butCastGolem.stop();
		//this->container->butCastIceman.stop();
		//this->container->butCastAir.stop();
		//this->container->barInfo.stop();
		//this->container->慢.stop();
		//this->container->快.stop();
		//this->container->traceBezier.stop();
		//this->container->barInfo.y = 585;
		//this->container->book.bookCase.buttonMode = true;
		//this->container->pause.pauseCase.buttonMode = true;
		//this->container->startWaves.startWavesCase.buttonMode = true;
		//this->container->butCastGolem.castGolemCase.buttonMode = true;
		//this->container->butCastIceman.castIcemanCase.buttonMode = true;
		//this->container->butCastAir.castAirCase.buttonMode = true;
		//this->container->慢.buttonMode = true;
		//this->container->traceBezier.buttonMode = true;
		//this->container->fireNumTXT.mouseEnabled = false;
		//this->container->iceNumTXT.mouseEnabled = false;
		//this->container->stoneNumTXT.mouseEnabled = false;
		//this->container->levinNumTXT.mouseEnabled = false; 
		//this->container->barInfo.mouseChildren = false;
		//this->container->barInfo.mouseEnabled = false;
		//this->container->lastTime.mouseEnabled = false;
		//this->container->butCastGolem.alpha = 0;
		//this->container->butCastIceman.alpha = 0;
		//this->container->butCastAir.alpha = 0;

		this->container->butCastGolem->setVisible( false);
		this->container->butCastIceman->setVisible( false);
		this->container->butCastAir->setVisible( false);
		//this->container->barInfo->setVisible( false);
		//this->container->lastTime->setVisible( false);
		this->container->buyFire->setVisible( false);
		this->container->buyIce->setVisible( false);
		this->container->buyStone->setVisible( false);
		this->container->buyLevin->setVisible( false);
		//this->container->backComponents.cacheAsBitmap = true;
		//this->addChild(this->container);
		//this->container->fireSphere.myPoint = this->container->fireSphere.localToGlobal(new Point(this->container->fireSphere.sphereCase.x, this->container->fireSphere.sphereCase.y));
		//this->container->iceSphere.myPoint = this->container->iceSphere.localToGlobal(new Point(this->container->iceSphere.sphereCase.x, this->container->iceSphere.sphereCase.y));
		//this->container->stoneSphere.myPoint = this->container->stoneSphere.localToGlobal(new Point(this->container->stoneSphere.sphereCase.x, this->container->stoneSphere.sphereCase.y));
		//this->container->levinSphere.myPoint = this->container->levinSphere.localToGlobal(new Point(this->container->levinSphere.sphereCase.x, this->container->levinSphere.sphereCase.y));
		//this->container->getAll.myPoint = this->container->getAll.localToGlobal(new Point(this->container->getAll.sphereCase.x, this->container->getAll.sphereCase.y));
		this->castGolemTimer = Main::mainClass->readXMLClass.intervalTimerGolemXML;
		this->castIcemanTimer = Main::mainClass->readXMLClass.intervalTimerIcemanXML;
		this->castAirTimer = Main::mainClass->readXMLClass.intervalTimerAirXML;
		//this->container->fireBacklight.turnFlag = true;
		//this->container->iceBacklight.turnFlag = true;
		//this->container->stoneBacklight.turnFlag = true;
		//this->container->levinBacklight.turnFlag = true;
		//this->container->fireBacklight.stop();
		//this->container->iceBacklight.stop();
		//this->container->stoneBacklight.stop();
		//this->container->levinBacklight.stop();
		this->container->fireBacklight->setVisible( false);
		this->container->iceBacklight->setVisible( false);
		this->container->stoneBacklight->setVisible( false);
		this->container->levinBacklight->setVisible( false);
		this->container->buyGetAll->setVisible( false);
		//this->container->testRestart.stop();
		//this->container->testRestartBoard.stop();
		//this->container->testRestart.buttonMode = true;
		//if (Main::mainClass->readXMLClass.bezierBuildXML)
		//{
		//	this->world->bezierClass->tracePoints = this->container->traceBezier;
		//	this->world->bezierClass.tracePoints.addEventListener(MouseEvent.CLICK, this->world->bezierClass.tracePointsArr);
		//}
		//else
		//{
		//	this->container->traceBezier->setVisible( false);
		//}
		//this->lastTime = this->container->lastTime;
		//this->container->removeChild(this->lastTime);
		//this->world->addChild(this->lastTime);
		//if (this->world->saveBox.gameSave.data.complexityLevel == 4)
		//{
		//	this->world->listOfIndexes3.push(this->lastTime);
		//}
		//this->container->testRestart->setVisible( false);
		//this->container->testRestartBoard->setVisible( false);
		//this->container->慢->setVisible( false);

       


        this->container->startWaves->addClickEventListener(CC_CALLBACK_1(WorldInterface::clickHandler, this));
        this->container->fastbtn->addClickEventListener(CC_CALLBACK_1(WorldInterface::clickHandler, this));

        EventListenerTouchOneByOne *touchListener = EventListenerTouchOneByOne::create();
        touchListener->onTouchBegan = [this](Touch *touch, Event *event){
            return this->onTouchBegan(touch, event);
        };
        touchListener->onTouchEnded = [this](Touch *touch, Event *event){
            return this->onTouchEnded(touch, event);
        };
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, point);

		//this->castMask = new CastMask_mc();
		//this->castMask.stop();
		//this->castMask.fireCase.stop();
		//this->castMask.iceCase.stop();
		//this->castMask.stoneCase.stop();
		//this->castMask.levinCase.stop();
		//this->castMask.getAllCase.stop();
		//this->castMask.archiveCase.stop();
		//this->castMask.interfaceUpCase.stop();
		//this->castMask.sellCase.stop();
		//this->castMask->setVisible( false);
		//this->addChild(this->castMask);
		this->world->forseIndexFl = true;
		this->blockCastGolem = true;
		this->blockCastIceman = true;
		this->blockCastAir = true;
		this->spheresBlockManage();
		return true;
	};
    void WorldInterface::clickHandler(Ref* ref){
        ui::Button * node = (ui::Button *)ref;
        string target = node->getName();
        CCLOG("startWavesCallback %s", target.c_str());
        if (target == "startWaves")
        {

        }
        else  if (target == "fastbtn")
        {

        }
    };

    bool WorldInterface::onTouchBegan(Touch* touch, Event* event)
    {
        Node * node = event->getCurrentTarget();
        Event::Type tp = event->getType();
        string target = node->getName();

        return true;
    }
    void WorldInterface::onTouchEnded(Touch* touch, Event* event)
    {
        Node * node = event->getCurrentTarget();
        Event::Type tp = event->getType();
        string target = node->getName();
        CCLOG("WorldInterface::onTouchEnded %s", target.c_str());
        return;
    }
	void WorldInterface::update(){
		////public function update() : void
		//{
		//	if (this->mouseEnabled)
		//	{
		//		if (this->container->快.cont)
		//		{
		//			if (this->world->frameCounter % 2)
		//			{
		//				if (this->container->快.cont.currentFrame < this->container->快.cont.totalFrames)
		//				{
		//					this->container->快.cont.gotoAndStop((this->container->快.cont.currentFrame + 1));
		//				}
		//				else
		//				{
		//					this->container->快.cont.gotoAndStop(1);
		//				}
		//			}
		//		}
		//		if (this->container->pause.openFlag)
		//		{
		//			if (this->container->pause.currentFrame < (this->container->pause.totalFrames - 1))
		//			{
		//				this->container->pause.gotoAndStop((this->container->pause.currentFrame + 1));
		//			}
		//			else
		//			{
		//				this->container->pause.openFlag = false;
		//			}
		//		}
		//		else if (this->container->pause.closeFlag)
		//		{
		//			if (this->container->pause.currentFrame > 1 && this->container->pause.currentFrame < this->container->pause.totalFrames)
		//			{
		//				this->container->pause.gotoAndStop((this->container->pause.currentFrame - 1));
		//			}
		//			else
		//			{
		//				this->container->pause.closeFlag = false;
		//			}
		//		}
		//		if (this->container->book.openFlag)
		//		{
		//			if (this->container->book.currentFrame < (this->container->book.totalFrames - 1))
		//			{
		//				this->container->book.gotoAndStop((this->container->book.currentFrame + 1));
		//			}
		//			else
		//			{
		//				this->container->book.openFlag = false;
		//			}
		//		}
		//		else if (this->container->book.closeFlag)
		//		{
		//			if (this->container->book.currentFrame > 1 && this->container->book.currentFrame < this->container->book.totalFrames)
		//			{
		//				this->container->book.gotoAndStop((this->container->book.currentFrame - 1));
		//			}
		//			else
		//			{
		//				this->container->book.closeFlag = false;
		//			}
		//		}
		//		if (this->fireCount > 0)
		//		{
		//			if (this->container->fireSphere.currentFrame < this->container->fireSphere.totalFrames)
		//			{
		//				this->container->fireSphere.gotoAndStop((this->container->fireSphere.currentFrame + 1));
		//			}
		//			else
		//			{
		//				this->container->fireSphere.gotoAndStop(1);
		//			}
		//		}
		//		if (this->iceCount > 0)
		//		{
		//			if (this->container->iceSphere.currentFrame < this->container->iceSphere.totalFrames)
		//			{
		//				this->container->iceSphere.gotoAndStop((this->container->iceSphere.currentFrame + 1));
		//			}
		//			else
		//			{
		//				this->container->iceSphere.gotoAndStop(1);
		//			}
		//		}
		//		if (this->stoneCount > 0)
		//		{
		//			if (this->container->stoneSphere.currentFrame < this->container->stoneSphere.totalFrames)
		//			{
		//				this->container->stoneSphere.gotoAndStop((this->container->stoneSphere.currentFrame + 1));
		//			}
		//			else
		//			{
		//				this->container->stoneSphere.gotoAndStop(1);
		//			}
		//		}
		//		if (this->levinCount > 0)
		//		{
		//			if (this->container->levinSphere.currentFrame < this->container->levinSphere.totalFrames)
		//			{
		//				this->container->levinSphere.gotoAndStop((this->container->levinSphere.currentFrame + 1));
		//			}
		//			else
		//			{
		//				this->container->levinSphere.gotoAndStop(1);
		//			}
		//		}
		//		if (this->getAllCount > 0)
		//		{
		//			if (this->container->getAll.fire)
		//			{
		//				if (this->container->getAll.fire.currentFrame < this->container->getAll.fire.totalFrames)
		//				{
		//					this->container->getAll.fire.gotoAndStop((this->container->getAll.fire.currentFrame + 1));
		//				}
		//				else
		//				{
		//					this->container->getAll.fire.gotoAndStop(1);
		//				}
		//				if (this->container->getAll.ice.currentFrame < this->container->getAll.ice.totalFrames)
		//				{
		//					this->container->getAll.ice.gotoAndStop((this->container->getAll.ice.currentFrame + 1));
		//				}
		//				else
		//				{
		//					this->container->getAll.ice.gotoAndStop(1);
		//				}
		//				if (this->container->getAll.stone.currentFrame < this->container->getAll.stone.totalFrames)
		//				{
		//					this->container->getAll.stone.gotoAndStop((this->container->getAll.stone.currentFrame + 1));
		//				}
		//				else
		//				{
		//					this->container->getAll.stone.gotoAndStop(1);
		//				}
		//				if (this->container->getAll.levin.currentFrame < this->container->getAll.levin.totalFrames)
		//				{
		//					this->container->getAll.levin.gotoAndStop((this->container->getAll.levin.currentFrame + 1));
		//				}
		//				else
		//				{
		//					this->container->getAll.levin.gotoAndStop(1);
		//				}
		//			}
		//		}
		//		if (this->container->startWaves.currentFrame <= 10)
		//		{
		//			if (this->container->startWaves.currentFrame < 10)
		//			{
		//				this->container->startWaves.gotoAndStop((this->container->startWaves.currentFrame + 1));
		//			}
		//			else
		//			{
		//				this->container->startWaves.gotoAndStop(1);
		//			}
		//		}
		//		else if (this->container->startWaves.currentFrame <= 20)
		//		{
		//			if (this->container->startWaves.currentFrame < 20)
		//			{
		//				this->container->startWaves.gotoAndStop((this->container->startWaves.currentFrame + 1));
		//			}
		//			else
		//			{
		//				this->container->startWaves.gotoAndStop(11);
		//			}
		//		}
		//		if (!this->blockCastGolem)
		//		{
		//			if (this->container->butCastGolem->isVisible())
		//			{
		//				if (this->container->butCastGolem.alpha < 1)
		//				{
		//					this->container->butCastGolem.alpha = this->container->butCastGolem.alpha + 0.2;
		//				}
		//				else
		//				{
		//					this->blockCastGolem = true;
		//					this->container->butCastGolem.alpha = 1;
		//					this->autoguidersButtons();
		//				}
		//			}
		//			else
		//			{
		//				this->container->butCastGolem->setVisible(true);
		//			}
		//		}
		//		if (!this->blockCastIceman)
		//		{
		//			if (this->container->butCastIceman->isVisible())
		//			{
		//				if (this->container->butCastIceman.alpha < 1)
		//				{
		//					this->container->butCastIceman.alpha = this->container->butCastIceman.alpha + 0.2;
		//				}
		//				else
		//				{
		//					this->blockCastIceman = true;
		//					this->container->butCastIceman.alpha = 1;
		//					this->autoguidersButtons();
		//				}
		//			}
		//			else
		//			{
		//				this->container->butCastIceman->setVisible(true);
		//			}
		//		}
		//		if (!this->blockCastAir)
		//		{
		//			if (this->container->butCastAir->isVisible())
		//			{
		//				if (this->container->butCastAir.alpha < 1)
		//				{
		//					this->container->butCastAir.alpha = this->container->butCastAir.alpha + 0.2;
		//				}
		//				else
		//				{
		//					this->blockCastAir = true;
		//					this->container->butCastAir.alpha = 1;
		//					this->autoguidersButtons();
		//				}
		//			}
		//			else
		//			{
		//				this->container->butCastAir->setVisible(true);
		//			}
		//		}
		//		if (this->container->fireSphere->isVisible())
		//		{
		//			if (!this->container->fireSphere.opened)
		//			{
		//				if (this->container->fireSphere.alpha < 1)
		//				{
		//					if (this->container->fireBack.currentFrame != 1)
		//					{
		//						this->container->fireBack.gotoAndStop(1);
		//					}
		//					this->container->fireSphere.alpha = this->container->fireSphere.alpha + 0.2;
		//					this->container->fireNumTXT.alpha = this->container->fireNumTXT.alpha + 0.2;
		//					this->container->buyFire.alpha = this->container->buyFire.alpha + 0.2;
		//				}
		//				else if (this->container->fireSphere.scaleX < 1)
		//				{
		//					this->container->fireSphere.scaleX = this->container->fireSphere.scaleX + 0.25;
		//					this->container->fireSphere.scaleY = this->container->fireSphere.scaleY + 0.25;
		//				}
		//				else
		//				{
		//					this->container->fireSphere.opened = true;
		//					this->spheresBlockManage("unblockFire");
		//				}
		//			}
		//		}
		//		if (this->container->iceSphere->isVisible())
		//		{
		//			if (!this->container->iceSphere.opened)
		//			{
		//				if (this->container->iceSphere.alpha < 1)
		//				{
		//					if (this->container->iceBack.currentFrame != 1)
		//					{
		//						this->container->iceBack.gotoAndStop(1);
		//					}
		//					this->container->iceSphere.alpha = this->container->iceSphere.alpha + 0.2;
		//					this->container->iceNumTXT.alpha = this->container->iceNumTXT.alpha + 0.2;
		//					this->container->buyIce.alpha = this->container->buyIce.alpha + 0.2;
		//				}
		//				else if (this->container->iceSphere.scaleX < 1)
		//				{
		//					this->container->iceSphere.scaleX = this->container->iceSphere.scaleX + 0.25;
		//					this->container->iceSphere.scaleY = this->container->iceSphere.scaleY + 0.25;
		//				}
		//				else
		//				{
		//					this->container->iceSphere.opened = true;
		//					this->spheresBlockManage("unblockIce");
		//				}
		//			}
		//		}
		//		if (this->container->stoneSphere->isVisible())
		//		{
		//			if (!this->container->stoneSphere.opened)
		//			{
		//				if (this->container->stoneSphere.alpha < 1)
		//				{
		//					if (this->container->stoneBack.currentFrame != 1)
		//					{
		//						this->container->stoneBack.gotoAndStop(1);
		//					}
		//					this->container->stoneSphere.alpha = this->container->stoneSphere.alpha + 0.2;
		//					this->container->stoneNumTXT.alpha = this->container->stoneNumTXT.alpha + 0.2;
		//					this->container->buyStone.alpha = this->container->buyStone.alpha + 0.2;
		//				}
		//				else if (this->container->stoneSphere.scaleX < 1)
		//				{
		//					this->container->stoneSphere.scaleX = this->container->stoneSphere.scaleX + 0.25;
		//					this->container->stoneSphere.scaleY = this->container->stoneSphere.scaleY + 0.25;
		//				}
		//				else
		//				{
		//					this->container->stoneSphere.opened = true;
		//					this->spheresBlockManage("unblockStone");
		//				}
		//			}
		//		}
		//		if (this->container->levinSphere->isVisible())
		//		{
		//			if (!this->container->levinSphere.opened)
		//			{
		//				if (this->container->levinSphere.alpha < 1)
		//				{
		//					if (this->container->levinBack.currentFrame != 1)
		//					{
		//						this->container->levinBack.gotoAndStop(1);
		//					}
		//					this->container->levinSphere.alpha = this->container->levinSphere.alpha + 0.2;
		//					this->container->levinNumTXT.alpha = this->container->levinNumTXT.alpha + 0.2;
		//					this->container->buyLevin.alpha = this->container->buyLevin.alpha + 0.2;
		//				}
		//				else if (this->container->levinSphere.scaleX < 1)
		//				{
		//					this->container->levinSphere.scaleX = this->container->levinSphere.scaleX + 0.25;
		//					this->container->levinSphere.scaleY = this->container->levinSphere.scaleY + 0.25;
		//				}
		//				else
		//				{
		//					this->container->levinSphere.opened = true;
		//					this->spheresBlockManage("unblockLevin");
		//				}
		//			}
		//		}
		//		if (!this->container->getAll.opened)
		//		{
		//			if (this->container->fireSphere.visible && this->container->iceSphere.visible && this->container->stoneSphere.visible && this->container->levinSphere->isVisible())
		//			{
		//				if (Main::mainClass->saveBoxClass.gameSave.data.saveNo > 3)
		//				{
		//					if (Main::mainClass->readXMLClass.towerSlotBlock == 0)
		//					{
		//						if (this->container->getAll.alpha < 1)
		//						{
		//							this->container->getAll.alpha = this->container->getAll.alpha + 0.2;
		//							this->container->getAll.alpha = this->container->getAll.alpha + 0.2;
		//							this->container->buyGetAll.alpha = this->container->buyGetAll.alpha + 0.2;
		//						}
		//						else if (this->container->getAll.scaleX < 1)
		//						{
		//							this->container->getAll.scaleX = this->container->getAll.scaleX + 0.25;
		//							this->container->getAll.scaleY = this->container->getAll.scaleY + 0.25;
		//						}
		//						else
		//						{
		//							this->container->getAll.opened = true;
		//							this->spheresBlockManage("unblockGetAll");
		//						}
		//					}
		//				}
		//				else
		//				{
		//					this->container->getAll.opened = true;
		//				}
		//			}
		//		}
		//		this->downloadCast();
		//		if (this->world->selectObject)
		//		{
		//			if (!this->container->barInfo->isVisible())
		//			{
		//				this->container->barInfo->setVisible(true);
		//			}
		//			this->barInfoView();
		//		}
		//		else if (this->container->barInfo->isVisible())
		//		{
		//			this->container->barInfo->setVisible( false);
		//		}
		//		this->newEnemyUpdate();
		//		if (this->container->fireBacklight->isVisible())
		//		{
		//			if (this->container->fireBacklight.currentFrame > 1)
		//			{
		//				if (this->container->fireBacklight.currentFrame < this->container->fireBacklight.totalFrames)
		//				{
		//					this->container->fireBacklight.gotoAndStop((this->container->fireBacklight.currentFrame + 1));
		//				}
		//				else if (!this->container->fireBacklight.turnFlag)
		//				{
		//					this->container->fireBacklight.turnFlag = true;
		//					this->container->fireBacklight.gotoAndStop(2);
		//				}
		//			}
		//		}
		//		if (this->container->iceBacklight->isVisible())
		//		{
		//			if (this->container->iceBacklight.currentFrame > 1)
		//			{
		//				if (this->container->iceBacklight.currentFrame < this->container->iceBacklight.totalFrames)
		//				{
		//					this->container->iceBacklight.gotoAndStop((this->container->iceBacklight.currentFrame + 1));
		//				}
		//				else if (!this->container->iceBacklight.turnFlag)
		//				{
		//					this->container->iceBacklight.turnFlag = true;
		//					this->container->iceBacklight.gotoAndStop(2);
		//				}
		//			}
		//		}
		//		if (this->container->stoneBacklight->isVisible())
		//		{
		//			if (this->container->stoneBacklight.currentFrame > 1)
		//			{
		//				if (this->container->stoneBacklight.currentFrame < this->container->stoneBacklight.totalFrames)
		//				{
		//					this->container->stoneBacklight.gotoAndStop((this->container->stoneBacklight.currentFrame + 1));
		//				}
		//				else if (!this->container->stoneBacklight.turnFlag)
		//				{
		//					this->container->stoneBacklight.turnFlag = true;
		//					this->container->stoneBacklight.gotoAndStop(2);
		//				}
		//			}
		//		}
		//		if (this->container->levinSphere->isVisible())
		//		{
		//			if (this->container->levinBacklight.currentFrame > 1)
		//			{
		//				if (this->container->levinBacklight.currentFrame < this->container->levinBacklight.totalFrames)
		//				{
		//					this->container->levinBacklight.gotoAndStop((this->container->levinBacklight.currentFrame + 1));
		//				}
		//				else if (!this->container->levinBacklight.turnFlag)
		//				{
		//					this->container->levinBacklight.turnFlag = true;
		//					this->container->levinBacklight.gotoAndStop(2);
		//				}
		//			}
		//		}
		//		this->hintUpdate();
		//		if (this->container->fireBack.currentFrame == 2)
		//		{
		//			if (this->container->fireBack.cont.currentFrame < this->container->fireBack.cont.totalFrames)
		//			{
		//				this->container->fireBack.cont.gotoAndStop(this->container->fireBack.cont.currentFrame + 2);
		//			}
		//			else
		//			{
		//				this->container->fireBack.cont.gotoAndStop(1);
		//			}
		//		}
		//		else if (this->container->iceBack.currentFrame == 2)
		//		{
		//			if (this->container->iceBack.cont.currentFrame < this->container->iceBack.cont.totalFrames)
		//			{
		//				this->container->iceBack.cont.gotoAndStop(this->container->iceBack.cont.currentFrame + 2);
		//			}
		//			else
		//			{
		//				this->container->iceBack.cont.gotoAndStop(1);
		//			}
		//		}
		//		else if (this->container->stoneBack.currentFrame == 2)
		//		{
		//			if (this->container->stoneBack.cont.currentFrame < this->container->stoneBack.cont.totalFrames)
		//			{
		//				this->container->stoneBack.cont.gotoAndStop(this->container->stoneBack.cont.currentFrame + 2);
		//			}
		//			else
		//			{
		//				this->container->stoneBack.cont.gotoAndStop(1);
		//			}
		//		}
		//		else if (this->container->levinBack.currentFrame == 2)
		//		{
		//			if (this->container->levinBack.cont.currentFrame < this->container->levinBack.cont.totalFrames)
		//			{
		//				this->container->levinBack.cont.gotoAndStop(this->container->levinBack.cont.currentFrame + 2);
		//			}
		//			else
		//			{
		//				this->container->levinBack.cont.gotoAndStop(1);
		//			}
		//		}
		//		if (this->listOfGetAhieve.length > 0)
		//		{
		//			this->i = this->listOfGetAhieve.length - 1;
		//			while (this->i >= 0)
		//			{ 
		//				if (!this->listOfGetAhieve[this->i].closeFlag)
		//				{
		//					if (this->listOfGetAhieve[this->i].currentFrame < this->listOfGetAhieve[this->i].totalFrames)
		//					{
		//						this->listOfGetAhieve[this->i].gotoAndStop((this->listOfGetAhieve[this->i].currentFrame + 1));
		//						this->listOfGetAhieve[this->i].board.noteTXT.text = this->listOfGetAhieve[this->i].myText;
		//					}
		//					else if (this->listOfGetAhieve[this->i].counter > 0)
		//					{
		//						(this->listOfGetAhieve[this->i].counter - 1);
		//					}
		//					else
		//					{
		//						this->listOfGetAhieve[this->i].closeFlag = true;
		//					}
		//					this->listOfGetAhieve[this->i].y = this->container->barInfo.y - 42;
		//				}
		//				else if (this->listOfGetAhieve[this->i].currentFrame > 1)
		//				{
		//					this->listOfGetAhieve[this->i].gotoAndStop((this->listOfGetAhieve[this->i].currentFrame - 1));
		//					this->listOfGetAhieve[this->i].board.noteTXT.text = this->listOfGetAhieve[this->i].myText;
		//				}
		//				else
		//				{
		//					this->removeChild(this->listOfGetAhieve[this->i]);
		//					this->listOfGetAhieve.splice(this->i, 1);
		//				}
		//				i++;
		//			}
		//		}
		//		if (this->listOfAnimation.length > 0)
		//		{
		//			this->i = this->listOfAnimation.length - 1;
		//			while (this->i >= 0)
		//			{
		//				if (this->listOfAnimation[this->i].currentFrame < this->listOfAnimation[this->i].totalFrames)
		//				{
		//					this->listOfAnimation[this->i].gotoAndStop((this->listOfAnimation[this->i].currentFrame + 1));
		//				}
		//				else
		//				{
		//					this->removeChild(this->listOfAnimation[this->i]);
		//					this->listOfAnimation.splice(this->i, 1);
		//				}
		//				i++;
		//			}
		//		}
		//	}
		//	else if (this->alpha < 1)
		//	{
		//		this->alpha = this->alpha + 0.2;
		//	}
		//	else
		//	{
		//		var _loc_1 : *= true;
		//		this->mouseChildren = true;
		//		this->mouseEnabled = _loc_1;
		//		this->alpha = 1;
		//	}
		//	return;
	};
	void WorldInterface::updateInfo()
	{
        char tmp[32];
        this->container->moneyTXT->setText(itoa(this->world->money, tmp, 10));
        this->container->liveTXT->setText(itoa(this->world->live, tmp, 10));
        sprintf(tmp, "%i/%i", this->world->wavesClass->nowWave ,this->world->wavesClass->maxWaves);
        this->container->waveTXT->setText(tmp);
        this->container->fireNumTXT->setText(itoa(this->fireCount, tmp, 10));

 		if (this->fireCount > 0)
		{
		    if (!this->container->fireNumTXT->isVisible())
		    {
		        this->container->fireNumTXT->setVisible(true);
		    }
		}
		else if (this->container->fireNumTXT->isVisible())
		{
		    this->container->fireNumTXT->setVisible( false);
		}
        this->container->iceNumTXT->setText(itoa(this->iceCount, tmp, 10));
		if (this->iceCount > 0)
		{
		    if (!this->container->iceNumTXT->isVisible())
		    {
		        this->container->iceNumTXT->setVisible(true);
		    }
		}
		else if (this->container->iceNumTXT->isVisible())
		{
		    this->container->iceNumTXT->setVisible( false);
		}
        this->container->stoneNumTXT->setText(itoa(this->stoneCount, tmp, 10));
		if (this->stoneCount > 0)
		{
		    if (!this->container->stoneNumTXT->isVisible())
		    {
		        this->container->stoneNumTXT->setVisible(true);
		    }
		}
		else if (this->container->stoneNumTXT->isVisible())
		{
		    this->container->stoneNumTXT->setVisible( false);
		}
        this->container->levinNumTXT->setText(itoa(this->levinCount, tmp, 10));
		if (this->levinCount > 0)
		{
		    if (!this->container->levinNumTXT->isVisible())
		    {
		        this->container->levinNumTXT->setVisible(true);
		    }
		}
		else if (this->container->levinNumTXT->isVisible())
		{
		    this->container->levinNumTXT->setVisible( false);
		}
        this->container->getAllNumTXT->setText(itoa(this->getAllCount, tmp, 10));
 		if (this->getAllCount > 0)
		{
		    if (!this->container->getAllNumTXT->isVisible())
		    {
		        this->container->getAllNumTXT->setVisible(true);
		    }
		}
		else if (this->container->getAllNumTXT->isVisible())
		{
		    this->container->getAllNumTXT->setVisible( false);
		}
        //
        int firePrice = Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory];
        this->container->firePrice->setText(itoa(firePrice, tmp, 10));
        int icePrice = Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory];
        this->container->icePrice->setText(itoa(icePrice, tmp, 10));
        int stonePrice = Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory];
        this->container->stonePrice->setText(itoa(stonePrice, tmp, 10));
        int levinPrice = Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
        this->container->levinPrice->setText(itoa(levinPrice, tmp, 10));
         
        int allPrice = Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory] + Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory] + Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory] + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
        this->container->getAllPrice->setText(itoa(allPrice, tmp, 10));
        cocos2d::Point bp= this->container->buyFire->getPosition();
        if (firePrice < 10)
            this->container->firePrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
		else
             this->container->firePrice->setPosition(Vec2(bp.x + 18, bp.y + 9));

        bp = this->container->buyIce->getPosition();
        if (icePrice < 10)
            this->container->icePrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
		else
            this->container->icePrice->setPosition(Vec2(bp.x + 18, bp.y + 9));
        bp = this->container->buyStone->getPosition();
        if (stonePrice < 10)
            this->container->stonePrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
        else
            this->container->stonePrice->setPosition(Vec2(bp.x + 18, bp.y + 9));
        bp = this->container->buyLevin->getPosition();
        if (levinPrice < 10)
            this->container->levinPrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
        else
            this->container->levinPrice->setPosition(Vec2(bp.x + 18, bp.y + 9));
        bp = this->container->buyGetAll->getPosition();
        if (allPrice < 10)
            this->container->getAllPrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
        else if (allPrice < 100)
            this->container->getAllPrice->setPosition(Vec2(bp.x + 18, bp.y + 9));
        else
            this->container->getAllPrice->setPosition(Vec2(bp.x + 16, bp.y + 9));

        if (this->container->fireSphere->isVisible() && (this->fireCount > 0 || this->world->money >= firePrice ))
		{
		    //if (!this->container->fireSphere.sphereCase.buttonMode)
		    //{
		    //    this->container->fireSphere.sphereCase.buttonMode = true;
		    //    this->container->fireSphere.alpha = 1;
		    //}
            if (this->world->money >= firePrice)
		    {
		        //if (this->container->buyFire.currentFrame == 2)
		        //{
		        //    this->container->buyFire.myCost = int(this->container->buyFire.buyTXT.text);
		        //    this->container->buyFire.coin.myPoint = new Point(this->container->buyFire.coin.x, this->container->buyFire.coin.y);
		        //    this->container->buyFire.gotoAndStop(1);
		        //    this->container->buyFire.buyTXT.text = this->container->buyFire.myCost;
		        //    this->container->buyFire.coin.gotoAndStop(1);
		        //    this->container->buyFire.coin.x = this->container->buyFire.coin.myPoint.x;
		        //    this->container->buyFire.coin.y = this->container->buyFire.coin.myPoint.y;
		        //}
		    }
		    //else if (this->container->buyFire.currentFrame == 1)
		    //{
		    //    this->container->buyFire.myCost = int(this->container->buyFire.buyTXT.text);
		    //    this->container->buyFire.coin.myPoint = new Point(this->container->buyFire.coin.x, this->container->buyFire.coin.y);
		    //    this->container->buyFire.gotoAndStop(2);
		    //    this->container->buyFire.buyTXT.text = this->container->buyFire.myCost;
		    //    this->container->buyFire.coin.gotoAndStop(2);
		    //    this->container->buyFire.coin.x = this->container->buyFire.coin.myPoint.x;
		    //    this->container->buyFire.coin.y = this->container->buyFire.coin.myPoint.y;
		    //   
		    //    this->container->buyFire.coin.scaleY = 0.8;
		    //    this->container->buyFire.coin.scaleX = 0.8;
		    //}

		//    if (this->container->fireSphere.sphereCase.buttonMode)
		//    {
		//        if (!this->world->getSphere)
		//        {
		//            if (this->world->towerMenu)
		//            {
		//                if (this->world->towerMenu.myTower.spheresManage("scan") > 0)
		//                {
		//                    if (!this->container->buyFire.lightUp->isVisible())
		//                    {
		//                        this->container->buyFire.lightUp->setVisible(true);
		//                    }
		//                }
		//                else if (this->container->buyFire.lightUp->isVisible())
		//                {
		//                    this->container->buyFire.lightUp->setVisible( false);
		//                }
		//            }
		//            else if (this->world->ultraTowerMenu)
		//            {
		//                if (this->world->ultraTowerMenu.myTower.towerType == 5 && Main::mainClass->readXMLClass.ultraTower1UpgrBlock == 0)
		//                {
		//                    if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[0])
		//                    {
		//                        if (!this->container->buyFire.lightUp->isVisible())
		//                        {
		//                            this->container->buyFire.lightUp->setVisible(true);
		//                        }
		//                    }
		//                    else if (this->container->buyFire.lightUp->isVisible())
		//                    {
		//                        this->container->buyFire.lightUp->setVisible( false);
		//                    }
		//                }
		//                else if (this->world->ultraTowerMenu.myTower.towerType == 8 && Main::mainClass->readXMLClass.ultraTower4UpgrBlock == 0)
		//                {
		//                    if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[0])
		//                    {
		//                        if (!this->container->buyFire.lightUp->isVisible())
		//                        {
		//                            this->container->buyFire.lightUp->setVisible(true);
		//                        }
		//                    }
		//                    else if (this->container->buyFire.lightUp->isVisible())
		//                    {
		//                        this->container->buyFire.lightUp->setVisible( false);
		//                    }
		//                }
		//            }
		//            else if (this->container->buyFire.lightUp->isVisible())
		//            {
		//                this->container->buyFire.lightUp->setVisible( false);
		//            }
		//        }
		//        else if (this->container->buyFire.lightUp->isVisible())
		//        {
		//            this->container->buyFire.lightUp->setVisible( false);
		//        }
		//    }
		}
		//else
		//{
		//    if (this->container->fireSphere.sphereCase.buttonMode)
		//    {
		//        this->container->fireSphere.sphereCase.buttonMode = false;
		//        this->container->fireBack.gotoAndStop(1);
		//        if (this->container->buyFire.lightUp->isVisible())
		//        {
		//            this->container->buyFire.lightUp->setVisible( false);
		//        }
		//    }
		//    if (this->container->buyFire.currentFrame == 1)
		//    {
		//        this->container->buyFire.myCost = int(this->container->buyFire.buyTXT.text);
		//        this->container->buyFire.coin.myPoint = new Point(this->container->buyFire.coin.x, this->container->buyFire.coin.y);
		//        this->container->buyFire.gotoAndStop(2);
		//        this->container->buyFire.buyTXT.text = this->container->buyFire.myCost;
		//        this->container->buyFire.coin.gotoAndStop(2);
		//        this->container->buyFire.coin.x = this->container->buyFire.coin.myPoint.x;
		//        this->container->buyFire.coin.y = this->container->buyFire.coin.myPoint.y;
		//        var _loc_1:* = 0.8;
		//        this->container->buyFire.coin.scaleY = 0.8;
		//        this->container->buyFire.coin.scaleX = _loc_1;
		//    }
		//    if (this->container->fireSphere.alpha != 0.5)
		//    {
		//        this->container->fireSphere.alpha = 0.5;
		//    }
		//}

		//if (this->container->iceSphere.visible && (this->iceCount > 0 || this->world->money >= int(this->container->buyIce.buyTXT.text)))
		//{
		//    if (!this->container->iceSphere.sphereCase.buttonMode)
		//    {
		//        this->container->iceSphere.sphereCase.buttonMode = true;
		//        this->container->iceSphere.alpha = 1;
		//    }
		//    if (this->world->money >= int(this->container->buyIce.buyTXT.text))
		//    {
		//        if (this->container->buyIce.currentFrame == 2)
		//        {
		//            this->container->buyIce.myCost = int(this->container->buyIce.buyTXT.text);
		//            this->container->buyIce.coin.myPoint = new Point(this->container->buyIce.coin.x, this->container->buyIce.coin.y);
		//            this->container->buyIce.gotoAndStop(1);
		//            this->container->buyIce.buyTXT.text = this->container->buyIce.myCost;
		//            this->container->buyIce.coin.gotoAndStop(1);
		//            this->container->buyIce.coin.x = this->container->buyIce.coin.myPoint.x;
		//            this->container->buyIce.coin.y = this->container->buyIce.coin.myPoint.y;
		//            var _loc_1:* = 1;
		//            this->container->buyIce.coin.scaleY = 1;
		//            this->container->buyIce.coin.scaleX = _loc_1;
		//        }
		//    }
		//    else if (this->container->buyIce.currentFrame == 1)
		//    {
		//        this->container->buyIce.myCost = int(this->container->buyIce.buyTXT.text);
		//        this->container->buyIce.coin.myPoint = new Point(this->container->buyIce.coin.x, this->container->buyIce.coin.y);
		//        this->container->buyIce.gotoAndStop(2);
		//        this->container->buyIce.buyTXT.text = this->container->buyIce.myCost;
		//        this->container->buyIce.coin.gotoAndStop(2);
		//        this->container->buyIce.coin.x = this->container->buyIce.coin.myPoint.x;
		//        this->container->buyIce.coin.y = this->container->buyIce.coin.myPoint.y;
		//        var _loc_1:* = 0.8;
		//        this->container->buyIce.coin.scaleY = 0.8;
		//        this->container->buyIce.coin.scaleX = _loc_1;
		//    }
		//    if (this->container->iceSphere.sphereCase.buttonMode)
		//    {
		//        if (!this->world->getSphere)
		//        {
		//            if (this->world->towerMenu)
		//            {
		//                if (this->world->towerMenu.myTower.spheresManage("scan") > 0)
		//                {
		//                    if (!this->container->buyIce.lightUp->isVisible())
		//                    {
		//                        this->container->buyIce.lightUp->setVisible(true);
		//                    }
		//                }
		//                else if (this->container->buyIce.lightUp->isVisible())
		//                {
		//                    this->container->buyIce.lightUp->setVisible( false);
		//                }
		//            }
		//            else if (this->world->ultraTowerMenu)
		//            {
		//                if (this->world->ultraTowerMenu.myTower.towerType == 6 && Main::mainClass->readXMLClass.ultraTower2UpgrBlock == 0)
		//                {
		//                    if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[1])
		//                    {
		//                        if (!this->container->buyIce.lightUp->isVisible())
		//                        {
		//                            this->container->buyIce.lightUp->setVisible(true);
		//                        }
		//                    }
		//                    else if (this->container->buyIce.lightUp->isVisible())
		//                    {
		//                        this->container->buyIce.lightUp->setVisible( false);
		//                    }
		//                }
		//                else if (this->world->ultraTowerMenu.myTower.towerType == 7 && Main::mainClass->readXMLClass.ultraTower3UpgrBlock == 0)
		//                {
		//                    if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[1])
		//                    {
		//                        if (!this->container->buyIce.lightUp->isVisible())
		//                        {
		//                            this->container->buyIce.lightUp->setVisible(true);
		//                        }
		//                    }
		//                    else if (this->container->buyIce.lightUp->isVisible())
		//                    {
		//                        this->container->buyIce.lightUp->setVisible( false);
		//                    }
		//                }
		//            }
		//            else if (this->container->buyIce.lightUp->isVisible())
		//            {
		//                this->container->buyIce.lightUp->setVisible( false);
		//            }
		//        }
		//        else if (this->container->buyIce.lightUp->isVisible())
		//        {
		//            this->container->buyIce.lightUp->setVisible( false);
		//        }
		//    }
		//}
		//else
		//{
		//    if (this->container->iceSphere.sphereCase.buttonMode)
		//    {
		//        this->container->iceSphere.sphereCase.buttonMode = false;
		//        this->container->iceBack.gotoAndStop(1);
		//        if (this->container->buyIce.lightUp->isVisible())
		//        {
		//            this->container->buyIce.lightUp->setVisible( false);
		//        }
		//    }
		//    if (this->container->buyIce.currentFrame == 1)
		//    {
		//        this->container->buyIce.myCost = int(this->container->buyIce.buyTXT.text);
		//        this->container->buyIce.coin.myPoint = new Point(this->container->buyIce.coin.x, this->container->buyIce.coin.y);
		//        this->container->buyIce.gotoAndStop(2);
		//        this->container->buyIce.buyTXT.text = this->container->buyIce.myCost;
		//        this->container->buyIce.coin.gotoAndStop(2);
		//        this->container->buyIce.coin.x = this->container->buyIce.coin.myPoint.x;
		//        this->container->buyIce.coin.y = this->container->buyIce.coin.myPoint.y;
		//        var _loc_1:* = 0.8;
		//        this->container->buyIce.coin.scaleY = 0.8;
		//        this->container->buyIce.coin.scaleX = _loc_1;
		//    }
		//    if (this->container->iceSphere.alpha != 0.5)
		//    {
		//        this->container->iceSphere.alpha = 0.5;
		//    }
		//}

		//if (this->container->stoneSphere.visible && (this->stoneCount > 0 || this->world->money >= int(this->container->buyStone.buyTXT.text)))
		//{
		//    if (!this->container->stoneSphere.sphereCase.buttonMode)
		//    {
		//        this->container->stoneSphere.sphereCase.buttonMode = true;
		//        this->container->stoneSphere.alpha = 1;
		//    }
		//    if (this->world->money >= int(this->container->buyStone.buyTXT.text))
		//    {
		//        if (this->container->buyStone.currentFrame == 2)
		//        {
		//            this->container->buyStone.myCost = int(this->container->buyStone.buyTXT.text);
		//            this->container->buyStone.coin.myPoint = new Point(this->container->buyStone.coin.x, this->container->buyStone.coin.y);
		//            this->container->buyStone.gotoAndStop(1);
		//            this->container->buyStone.buyTXT.text = this->container->buyStone.myCost;
		//            this->container->buyStone.coin.gotoAndStop(1);
		//            this->container->buyStone.coin.x = this->container->buyStone.coin.myPoint.x;
		//            this->container->buyStone.coin.y = this->container->buyStone.coin.myPoint.y;
		//            var _loc_1:* = 1;
		//            this->container->buyStone.coin.scaleY = 1;
		//            this->container->buyStone.coin.scaleX = _loc_1;
		//        }
		//    }
		//    else if (this->container->buyStone.currentFrame == 1)
		//    {
		//        this->container->buyStone.myCost = int(this->container->buyStone.buyTXT.text);
		//        this->container->buyStone.coin.myPoint = new Point(this->container->buyStone.coin.x, this->container->buyStone.coin.y);
		//        this->container->buyStone.gotoAndStop(2);
		//        this->container->buyStone.buyTXT.text = this->container->buyStone.myCost;
		//        this->container->buyStone.coin.gotoAndStop(2);
		//        this->container->buyStone.coin.x = this->container->buyStone.coin.myPoint.x;
		//        this->container->buyStone.coin.y = this->container->buyStone.coin.myPoint.y;
		//        var _loc_1:* = 0.8;
		//        this->container->buyStone.coin.scaleY = 0.8;
		//        this->container->buyStone.coin.scaleX = _loc_1;
		//    }
		//    if (this->container->stoneSphere.sphereCase.buttonMode)
		//    {
		//        if (!this->world->getSphere)
		//        {
		//            if (this->world->towerMenu)
		//            {
		//                if (this->world->towerMenu.myTower.spheresManage("scan") > 0)
		//                {
		//                    if (!this->container->buyStone.lightUp->isVisible())
		//                    {
		//                        this->container->buyStone.lightUp->setVisible(true);
		//                    }
		//                }
		//                else if (this->container->buyStone.lightUp->isVisible())
		//                {
		//                    this->container->buyStone.lightUp->setVisible( false);
		//                }
		//            }
		//            else if (this->world->ultraTowerMenu)
		//            {
		//                if (this->world->ultraTowerMenu.myTower.towerType == 5 && Main::mainClass->readXMLClass.ultraTower1UpgrBlock == 0)
		//                {
		//                    if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[2])
		//                    {
		//                        if (!this->container->buyStone.lightUp->isVisible())
		//                        {
		//                            this->container->buyStone.lightUp->setVisible(true);
		//                        }
		//                    }
		//                    else if (this->container->buyStone.lightUp->isVisible())
		//                    {
		//                        this->container->buyStone.lightUp->setVisible( false);
		//                    }
		//                }
		//                else if (this->world->ultraTowerMenu.myTower.towerType == 7 && Main::mainClass->readXMLClass.ultraTower3UpgrBlock == 0)
		//                {
		//                    if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[2])
		//                    {
		//                        if (!this->container->buyStone.lightUp->isVisible())
		//                        {
		//                            this->container->buyStone.lightUp->setVisible(true);
		//                        }
		//                    }
		//                    else if (this->container->buyStone.lightUp->isVisible())
		//                    {
		//                        this->container->buyStone.lightUp->setVisible( false);
		//                    }
		//                }
		//            }
		//            else if (this->container->buyStone.lightUp->isVisible())
		//            {
		//                this->container->buyStone.lightUp->setVisible( false);
		//            }
		//        }
		//        else if (this->container->buyStone.lightUp->isVisible())
		//        {
		//            this->container->buyStone.lightUp->setVisible( false);
		//        }
		//    }
		//}
		//else
		//{
		//    if (this->container->stoneSphere.sphereCase.buttonMode)
		//    {
		//        this->container->stoneSphere.sphereCase.buttonMode = false;
		//        this->container->stoneBack.gotoAndStop(1);
		//        if (this->container->buyStone.lightUp->isVisible())
		//        {
		//            this->container->buyStone.lightUp->setVisible( false);
		//        }
		//    }
		//    if (this->container->buyStone.currentFrame == 1)
		//    {
		//        this->container->buyStone.myCost = int(this->container->buyStone.buyTXT.text);
		//        this->container->buyStone.coin.myPoint = new Point(this->container->buyStone.coin.x, this->container->buyStone.coin.y);
		//        this->container->buyStone.gotoAndStop(2);
		//        this->container->buyStone.buyTXT.text = this->container->buyStone.myCost;
		//        this->container->buyStone.coin.gotoAndStop(2);
		//        this->container->buyStone.coin.x = this->container->buyStone.coin.myPoint.x;
		//        this->container->buyStone.coin.y = this->container->buyStone.coin.myPoint.y;
		//        var _loc_1:* = 0.8;
		//        this->container->buyStone.coin.scaleY = 0.8;
		//        this->container->buyStone.coin.scaleX = _loc_1;
		//    }
		//    if (this->container->stoneSphere.alpha != 0.5)
		//    {
		//        this->container->stoneSphere.alpha = 0.5;
		//    }
		//}

		//if (this->container->levinSphere.visible && (this->levinCount > 0 || this->world->money >= int(this->container->buyLevin.buyTXT.text)))
		//{
		//    if (!this->container->levinSphere.sphereCase.buttonMode)
		//    {
		//        this->container->levinSphere.sphereCase.buttonMode = true;
		//        this->container->levinSphere.alpha = 1;
		//    }
		//    if (this->world->money >= int(this->container->buyLevin.buyTXT.text))
		//    {
		//        if (this->container->buyLevin.currentFrame == 2)
		//        {
		//            this->container->buyLevin.myCost = int(this->container->buyLevin.buyTXT.text);
		//            this->container->buyLevin.coin.myPoint = new Point(this->container->buyLevin.coin.x, this->container->buyLevin.coin.y);
		//            this->container->buyLevin.gotoAndStop(1);
		//            this->container->buyLevin.buyTXT.text = this->container->buyLevin.myCost;
		//            this->container->buyLevin.coin.gotoAndStop(1);
		//            this->container->buyLevin.coin.x = this->container->buyLevin.coin.myPoint.x;
		//            this->container->buyLevin.coin.y = this->container->buyLevin.coin.myPoint.y;
		//            var _loc_1:* = 1;
		//            this->container->buyLevin.coin.scaleY = 1;
		//            this->container->buyLevin.coin.scaleX = _loc_1;
		//        }
		//    }
		//    else if (this->container->buyLevin.currentFrame == 1)
		//    {
		//        this->container->buyLevin.myCost = int(this->container->buyLevin.buyTXT.text);
		//        this->container->buyLevin.coin.myPoint = new Point(this->container->buyLevin.coin.x, this->container->buyLevin.coin.y);
		//        this->container->buyLevin.gotoAndStop(2);
		//        this->container->buyLevin.buyTXT.text = this->container->buyLevin.myCost;
		//        this->container->buyLevin.coin.gotoAndStop(2);
		//        this->container->buyLevin.coin.x = this->container->buyLevin.coin.myPoint.x;
		//        this->container->buyLevin.coin.y = this->container->buyLevin.coin.myPoint.y;
		//        var _loc_1:* = 0.8;
		//        this->container->buyLevin.coin.scaleY = 0.8;
		//        this->container->buyLevin.coin.scaleX = _loc_1;
		//    }
		//    if (this->container->levinSphere.sphereCase.buttonMode)
		//    {
		//        if (!this->world->getSphere)
		//        {
		//            if (this->world->towerMenu)
		//            {
		//                if (this->world->towerMenu.myTower.spheresManage("scan") > 0)
		//                {
		//                    if (!this->container->buyLevin.lightUp->isVisible())
		//                    {
		//                        this->container->buyLevin.lightUp->setVisible(true);
		//                    }
		//                }
		//                else if (this->container->buyLevin.lightUp->isVisible())
		//                {
		//                    this->container->buyLevin.lightUp->setVisible( false);
		//                }
		//            }
		//            else if (this->world->ultraTowerMenu)
		//            {
		//                if (this->world->ultraTowerMenu.myTower.towerType == 6 && Main::mainClass->readXMLClass.ultraTower2UpgrBlock == 0)
		//                {
		//                    if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[3])
		//                    {
		//                        if (!this->container->buyLevin.lightUp->isVisible())
		//                        {
		//                            this->container->buyLevin.lightUp->setVisible(true);
		//                        }
		//                    }
		//                    else if (this->container->buyLevin.lightUp->isVisible())
		//                    {
		//                        this->container->buyLevin.lightUp->setVisible( false);
		//                    }
		//                }
		//                else if (this->world->ultraTowerMenu.myTower.towerType == 8 && Main::mainClass->readXMLClass.ultraTower4UpgrBlock == 0)
		//                {
		//                    if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[3])
		//                    {
		//                        if (!this->container->buyLevin.lightUp->isVisible())
		//                        {
		//                            this->container->buyLevin.lightUp->setVisible(true);
		//                        }
		//                    }
		//                    else if (this->container->buyLevin.lightUp->isVisible())
		//                    {
		//                        this->container->buyLevin.lightUp->setVisible( false);
		//                    }
		//                }
		//            }
		//            else if (this->container->buyLevin.lightUp->isVisible())
		//            {
		//                this->container->buyLevin.lightUp->setVisible( false);
		//            }
		//        }
		//        else if (this->container->buyLevin.lightUp->isVisible())
		//        {
		//            this->container->buyLevin.lightUp->setVisible( false);
		//        }
		//    }
		//}
		//else
		//{
		//    if (this->container->levinSphere.sphereCase.buttonMode)
		//    {
		//        this->container->levinSphere.sphereCase.buttonMode = false;
		//        this->container->levinBack.gotoAndStop(1);
		//        if (this->container->buyLevin.lightUp->isVisible())
		//        {
		//            this->container->buyLevin.lightUp->setVisible( false);
		//        }
		//    }
		//    if (this->container->buyLevin.currentFrame == 1)
		//    {
		//        this->container->buyLevin.myCost = int(this->container->buyLevin.buyTXT.text);
		//        this->container->buyLevin.coin.myPoint = new Point(this->container->buyLevin.coin.x, this->container->buyLevin.coin.y);
		//        this->container->buyLevin.gotoAndStop(2);
		//        this->container->buyLevin.buyTXT.text = this->container->buyLevin.myCost;
		//        this->container->buyLevin.coin.gotoAndStop(2);
		//        this->container->buyLevin.coin.x = this->container->buyLevin.coin.myPoint.x;
		//        this->container->buyLevin.coin.y = this->container->buyLevin.coin.myPoint.y;
		//        var _loc_1:* = 0.8;
		//        this->container->buyLevin.coin.scaleY = 0.8;
		//        this->container->buyLevin.coin.scaleX = _loc_1;
		//    }
		//    if (this->container->levinSphere.alpha != 0.5)
		//    {
		//        this->container->levinSphere.alpha = 0.5;
		//    }
		//}

		//if (this->container->getAll.currentFrame < 3)
		//{
		//    if (this->container->getAll.visible && (this->getAllCount > 0 || this->world->money >= int(this->container->buyGetAll.buyTXT.text)))
		//    {
		//        if (!this->container->getAll.sphereCase.buttonMode)
		//        {
		//            this->container->getAll.sphereCase.buttonMode = true;
		//            this->container->getAll.alpha = 1;
		//        }
		//        if (this->world->money >= int(this->container->buyGetAll.buyTXT.text))
		//        {
		//            if (this->container->buyGetAll.currentFrame == 2)
		//            {
		//                this->container->buyGetAll.myCost = int(this->container->buyGetAll.buyTXT.text);
		//                this->container->buyGetAll.coin.myPoint = new Point(this->container->buyGetAll.coin.x, this->container->buyGetAll.coin.y);
		//                this->container->buyGetAll.gotoAndStop(1);
		//                this->container->buyGetAll.buyTXT.text = this->container->buyGetAll.myCost;
		//                this->container->buyGetAll.coin.gotoAndStop(1);
		//                this->container->buyGetAll.coin.x = this->container->buyGetAll.coin.myPoint.x;
		//                this->container->buyGetAll.coin.y = this->container->buyGetAll.coin.myPoint.y;
		//                var _loc_1:* = 1;
		//                this->container->buyGetAll.coin.scaleY = 1;
		//                this->container->buyGetAll.coin.scaleX = _loc_1;
		//            }
		//        }
		//        else if (this->container->buyGetAll.currentFrame == 1)
		//        {
		//            this->container->buyGetAll.myCost = int(this->container->buyGetAll.buyTXT.text);
		//            this->container->buyGetAll.coin.myPoint = new Point(this->container->buyGetAll.coin.x, this->container->buyGetAll.coin.y);
		//            this->container->buyGetAll.gotoAndStop(2);
		//            this->container->buyGetAll.buyTXT.text = this->container->buyGetAll.myCost;
		//            this->container->buyGetAll.coin.gotoAndStop(2);
		//            this->container->buyGetAll.coin.x = this->container->buyGetAll.coin.myPoint.x;
		//            this->container->buyGetAll.coin.y = this->container->buyGetAll.coin.myPoint.y;
		//            var _loc_1:* = 0.8;
		//            this->container->buyGetAll.coin.scaleY = 0.8;
		//            this->container->buyGetAll.coin.scaleX = _loc_1;
		//        }
		//        if (this->container->getAll.sphereCase.buttonMode)
		//        {
		//            if (!this->world->getSphere)
		//            {
		//                if (this->world->towerMenu)
		//                {
		//                    if (this->world->towerMenu.myTower.spheresManage("scan") == 4)
		//                    {
		//                        if (!this->container->buyGetAll.lightUp->isVisible())
		//                        {
		//                            this->container->buyGetAll.lightUp->setVisible(true);
		//                        }
		//                    }
		//                    else if (this->container->buyGetAll.lightUp->isVisible())
		//                    {
		//                        this->container->buyGetAll.lightUp->setVisible( false);
		//                    }
		//                }
		//                else if (this->container->buyGetAll.lightUp->isVisible())
		//                {
		//                    this->container->buyGetAll.lightUp->setVisible( false);
		//                }
		//            }
		//            else if (this->container->buyGetAll.lightUp->isVisible())
		//            {
		//                this->container->buyGetAll.lightUp->setVisible( false);
		//            }
		//        }
		//    }
		//    else
		//    {
		//        if (this->container->getAll.sphereCase.buttonMode)
		//        {
		//            this->container->getAll.sphereCase.buttonMode = false;
		//            this->container->getAll.gotoAndStop(1);
		//            if (this->container->buyGetAll.lightUp->isVisible())
		//            {
		//                this->container->buyGetAll.lightUp->setVisible( false);
		//            }
		//        }
		//        if (this->container->buyGetAll.currentFrame == 1)
		//        {
		//            this->container->buyGetAll.myCost = int(this->container->buyGetAll.buyTXT.text);
		//            this->container->buyGetAll.coin.myPoint = new Point(this->container->buyGetAll.coin.x, this->container->buyGetAll.coin.y);
		//            this->container->buyGetAll.gotoAndStop(2);
		//            this->container->buyGetAll.buyTXT.text = this->container->buyGetAll.myCost;
		//            this->container->buyGetAll.coin.gotoAndStop(2);
		//            this->container->buyGetAll.coin.x = this->container->buyGetAll.coin.myPoint.x;
		//            this->container->buyGetAll.coin.y = this->container->buyGetAll.coin.myPoint.y;
		//            var _loc_1:* = 0.8;
		//            this->container->buyGetAll.coin.scaleY = 0.8;
		//            this->container->buyGetAll.coin.scaleX = _loc_1;
		//        }
		//        if (this->container->getAll.alpha != 0.5)
		//        {
		//            this->container->getAll.alpha = 0.5;
		//        }
		//    }
		//}

		//if (this->world->getSphere)
		//{
		//    this->world->getSphere.monitor();
		//}
		//if (this->world->towerMenu)
		//{
		//    this->world->towerMenu.monitor();
		//}
		//else if (this->world->ultraTowerMenu)
		//{
		//    this->world->ultraTowerMenu.monitor();
		//}
		//if (this->world->buildTowerMenu)
		//{
		//    this->world->buildTowerMenu.monitor();
		//}
		//this->autoguidersButtons();
		//return;
	}// end function
	void WorldInterface::mouseDownHandler(cocos2d::Event *event)//(event:MouseEvent) : void
	{
        cocos2d::EventMouse*e = (cocos2d::EventMouse*)event;
        Node * node=event->getCurrentTarget();
        Event::Type tp=event->getType();
        string target = node->getName();
        CCLOG("WorldInterface::mouseDownHandler %s", target.c_str());
         

       cocos2d::Point pt = e->getLocationInView();
        CCLOG("mouse InView point %f,%f", pt.x, pt.y);
        nsp = node->convertToNodeSpaceAR(pt);
        CCLOG("mouse ToNodeSpaceAR point %f,%f", nsp.x, nsp.y);
        nsp = node->convertToNodeSpace(pt);
        CCLOG("mouse ToNodeSpace point %f,%f", nsp.x, nsp.y);

        nsp = this->world->pointer1->convertToNodeSpaceAR(pt);
        CCLOG("pointer1 ToNodeSpace point %f,%f", nsp.x, nsp.y);

        Rect bb;
        bb.size = this->world->pointer1->point->getContentSize();
        if (bb.containsPoint(nsp))
        {
            CCLOG("WorldInterface::containsPoint %s", target.c_str());
        }
		this->world->wavesClass->startWaves();

		//if (!this->world->getSphere && !this->world->cast)
		//{
		//	if (event.target.name == "慢")
		//	{
		//		if (this->container->慢.currentFrame == 2)
		//		{
		//			this->container->慢.gotoAndStop(3);
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//		}
		//	}
		//	else if (event.target.name == "fastCase")
		//	{
		//		if (event.target.buttonMode)
		//		{
		//			if (this->container->快.currentFrame == 2 || this->container->快.currentFrame == 5)
		//			{
		//				this->container->快.gotoAndStop((this->container->快.currentFrame + 1));
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//			}
		//		}
		//	}
		//	else if (event.target.name == "traceBezier")
		//	{
		//		if (this->container->traceBezier.currentFrame == 2)
		//		{
		//			this->container->traceBezier.gotoAndStop(3);
		//		}
		//	}
		//	else if (event.target.name == "pauseCase")
		//	{
		//		if (this->container->pause.currentFrame != this->container->pause.totalFrames)
		//		{
		//			this->container->pause.gotoAndStop(this->container->pause.totalFrames);
		//			this->container->pause.openFlag = false;
		//			this->container->pause.closeFlag = false;
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//		}
		//	}
		//	else if (event.target.name == "bookCase")
		//	{
		//		if (this->container->book.currentFrame != this->container->book.totalFrames)
		//		{
		//			this->container->book.gotoAndStop(this->container->book.totalFrames);
		//			this->container->book.openFlag = false;
		//			this->container->book.closeFlag = false;
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//		}
		//	}
		//	else if (event.target.name == "sphereCase")
		//	{
		//		if (event.target.buttonMode)
		//		{
		//			this->i = 0;
		//			while (this->i < this->world->listOfMoveSpheres.length)
		//			{

		//				if (this->world->listOfMoveSpheres[this->i].speedFrame > 0)
		//				{
		//					this->world->listOfMoveSpheres[this->i].speedFrame = 0;
		//				}
		//				var _loc_2 : *= this;
		//				var _loc_3 : *= this->i + 1;
		//				_loc_2.i = _loc_3;
		//			}
		//			this->world->feature.listOfMoveSpheres();
		//			if (event.target.parent.name == "fireSphere")
		//			{
		//				if (this->fireCount == 0)
		//				{
		//					this->archiveManage("buy", "fire");
		//				}
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//				this->archiveManage("get", "fire");
		//			}
		//			else if (event.target.parent.name == "iceSphere")
		//			{
		//				if (this->iceCount == 0)
		//				{
		//					this->archiveManage("buy", "ice");
		//				}
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//				this->archiveManage("get", "ice");
		//			}
		//			else if (event.target.parent.name == "stoneSphere")
		//			{
		//				if (this->stoneCount == 0)
		//				{
		//					this->archiveManage("buy", "stone");
		//				}
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//				this->archiveManage("get", "stone");
		//			}
		//			else if (event.target.parent.name == "levinSphere")
		//			{
		//				if (this->levinCount == 0)
		//				{
		//					this->archiveManage("buy", "levin");
		//				}
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//				this->archiveManage("get", "levin");
		//			}
		//			else if (event.target.parent.name == "getAll")
		//			{
		//				if (this->getAllCount == 0)
		//				{
		//					this->archiveManage("buy", "getAll");
		//				}
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//				this->archiveManage("get", "getAll");
		//			}
		//			if (this->world->getSphere)
		//			{
		//				if (this->world->getSphere.getAllCount == 0)
		//				{
		//					if (this->world->towerMenu)
		//					{
		//						if (this->world->towerMenu.myTower.spheresManage("scan") > 0)
		//						{
		//							this->world->getSphere.getSphereFromArchiveToTower();
		//						}
		//					}
		//					else if (this->world->ultraTowerMenu)
		//					{
		//						if (this->world->ultraTowerMenu.myTower.spheresManage("scan") > 0)
		//						{
		//							if (this->world->ultraTowerMenu.myTower.towerType == 5)
		//							{
		//								if (this->world->getSphere.fireCount > 0 && this->world->getSphere.iceCount == 0 && this->world->getSphere.stoneCount == 0 && this->world->getSphere.levinCount == 0)
		//								{
		//									if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[0])
		//									{
		//										this->world->getSphere.getSphereFromArchiveToTower();
		//									}
		//								}
		//								else if (this->world->getSphere.fireCount == 0 && this->world->getSphere.iceCount == 0 && this->world->getSphere.stoneCount > 0 && this->world->getSphere.levinCount == 0)
		//								{
		//									if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[2])
		//									{
		//										this->world->getSphere.getSphereFromArchiveToTower();
		//									}
		//								}
		//							}
		//							else if (this->world->ultraTowerMenu.myTower.towerType == 6)
		//							{
		//								if (this->world->getSphere.fireCount == 0 && this->world->getSphere.iceCount > 0 && this->world->getSphere.stoneCount == 0 && this->world->getSphere.levinCount == 0)
		//								{
		//									if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[1])
		//									{
		//										this->world->getSphere.getSphereFromArchiveToTower();
		//									}
		//								}
		//								else if (this->world->getSphere.fireCount == 0 && this->world->getSphere.iceCount == 0 && this->world->getSphere.stoneCount == 0 && this->world->getSphere.levinCount > 0)
		//								{
		//									if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[3])
		//									{
		//										this->world->getSphere.getSphereFromArchiveToTower();
		//									}
		//								}
		//							}
		//							else if (this->world->ultraTowerMenu.myTower.towerType == 7)
		//							{
		//								if (this->world->getSphere.fireCount == 0 && this->world->getSphere.iceCount > 0 && this->world->getSphere.stoneCount == 0 && this->world->getSphere.levinCount == 0)
		//								{
		//									if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[1])
		//									{
		//										this->world->getSphere.getSphereFromArchiveToTower();
		//									}
		//								}
		//								else if (this->world->getSphere.fireCount == 0 && this->world->getSphere.iceCount == 0 && this->world->getSphere.stoneCount > 0 && this->world->getSphere.levinCount == 0)
		//								{
		//									if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[2])
		//									{
		//										this->world->getSphere.getSphereFromArchiveToTower();
		//									}
		//								}
		//							}
		//							else if (this->world->ultraTowerMenu.myTower.towerType == 8)
		//							{
		//								if (this->world->getSphere.fireCount > 0 && this->world->getSphere.iceCount == 0 && this->world->getSphere.stoneCount == 0 && this->world->getSphere.levinCount == 0)
		//								{
		//									if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[0])
		//									{
		//										this->world->getSphere.getSphereFromArchiveToTower();
		//									}
		//								}
		//								else if (this->world->getSphere.fireCount == 0 && this->world->getSphere.iceCount == 0 && this->world->getSphere.stoneCount == 0 && this->world->getSphere.levinCount > 0)
		//								{
		//									if (!this->world->ultraTowerMenu.myTower.shootingTurnStack[3])
		//									{
		//										this->world->getSphere.getSphereFromArchiveToTower();
		//									}
		//								}
		//							}
		//						}
		//					}
		//				}
		//				else if (this->world->towerMenu)
		//				{
		//					if (this->world->towerMenu.myTower.spheresManage("scan") == 4)
		//					{
		//						this->world->getSphere.getSphereFromArchiveToTower();
		//					}
		//				}
		//			}
		//		}
		//	}
		//	else if (event.target.name == "startWavesCase")
		//	{
		//		if (this->container->startWaves.startWavesCase.buttonMode)
		//		{
		//			this->world->wavesClass.startWaves();
		//		}
		//	}
		//	else if (event.target.name == "castGolemCase")
		//	{
		//		if (this->container->butCastGolem.currentFrame == 2)
		//		{
		//			this->container->butCastGolem.gotoAndStop(3);
		//			this->castGolem();
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//		}
		//	}
		//	else if (event.target.name == "castIcemanCase")
		//	{
		//		if (this->container->butCastIceman.currentFrame == 2)
		//		{
		//			this->container->butCastIceman.gotoAndStop(3);
		//			this->castIceman();
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//		}
		//	}
		//	else if (event.target.name == "castAirCase")
		//	{
		//		if (this->container->butCastAir.currentFrame == 2)
		//		{
		//			this->container->butCastAir.gotoAndStop(3);
		//			this->castAir();
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//		}
		//	}
		//	else if (event.target.name == "pointerCase")
		//	{
		//		this->world->wavesClass.startWaves();
		//	}
		//	else if (event.target.name == "newEnemyCase" || event.target.name == "newElementCase")
		//	{
		//		this->tempObject = event.target.parent;
		//		this->tempObject.mouseStatus = 3;
		//		var _loc_2 : *= false;
		//		this->tempObject.mouseChildren = false;
		//		this->tempObject.mouseEnabled = _loc_2;
		//		Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
		//	}
		//	else if (event.target.name == "testRestart")
		//	{
		//		if (this->container->testRestart.currentFrame == 2)
		//		{
		//			this->container->testRestart.gotoAndStop(3);
		//		}
		//	}
		//}
	}
    void WorldInterface::mouseMoveHandler(cocos2d::Event *param1)//MouseEvent
	{
		//if (!this->world->getSphere && !this->world->cast && !this->world->exchange)
		//{
		//	if (param1.target.name == "sphereCase")
		//	{
		//		if (param1.target.parent.name == "fireSphere")
		//		{
		//			if (param1.target.buttonMode && this->container->fireBack.currentFrame == 1)
		//			{
		//				if (this->container->iceBack.currentFrame == 2)
		//				{
		//					this->container->iceBack.gotoAndStop(1);
		//				}
		//				if (this->container->stoneBack.currentFrame == 2)
		//				{
		//					this->container->stoneBack.gotoAndStop(1);
		//				}
		//				if (this->container->levinBack.currentFrame == 2)
		//				{
		//					this->container->levinBack.gotoAndStop(1);
		//				}
		//				if (this->container->getAll.currentFrame == 2)
		//				{
		//					this->container->getAll.gotoAndStop(1);
		//				}
		//				this->container->fireBack.gotoAndStop(2);
		//				this->container->fireBack.cont.stop();
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//			}
		//		}
		//		else if (param1.target.parent.name == "iceSphere")
		//		{
		//			if (param1.target.buttonMode && this->container->iceBack.currentFrame == 1)
		//			{
		//				if (this->container->fireBack.currentFrame == 2)
		//				{
		//					this->container->fireBack.gotoAndStop(1);
		//				}
		//				if (this->container->stoneBack.currentFrame == 2)
		//				{
		//					this->container->stoneBack.gotoAndStop(1);
		//				}
		//				if (this->container->levinBack.currentFrame == 2)
		//				{
		//					this->container->levinBack.gotoAndStop(1);
		//				}
		//				if (this->container->getAll.currentFrame == 2)
		//				{
		//					this->container->getAll.gotoAndStop(1);
		//				}
		//				this->container->iceBack.gotoAndStop(2);
		//				this->container->iceBack.cont.stop();
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//			}
		//		}
		//		else if (param1.target.parent.name == "stoneSphere")
		//		{
		//			if (param1.target.buttonMode && this->container->stoneBack.currentFrame == 1)
		//			{
		//				if (this->container->fireBack.currentFrame == 2)
		//				{
		//					this->container->fireBack.gotoAndStop(1);
		//				}
		//				if (this->container->iceBack.currentFrame == 2)
		//				{
		//					this->container->iceBack.gotoAndStop(1);
		//				}
		//				if (this->container->levinBack.currentFrame == 2)
		//				{
		//					this->container->levinBack.gotoAndStop(1);
		//				}
		//				if (this->container->getAll.currentFrame == 2)
		//				{
		//					this->container->getAll.gotoAndStop(1);
		//				}
		//				this->container->stoneBack.gotoAndStop(2);
		//				this->container->stoneBack.cont.stop();
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//			}
		//		}
		//		else if (param1.target.parent.name == "levinSphere")
		//		{
		//			if (param1.target.buttonMode && this->container->levinBack.currentFrame == 1)
		//			{
		//				if (this->container->fireBack.currentFrame == 2)
		//				{
		//					this->container->fireBack.gotoAndStop(1);
		//				}
		//				if (this->container->iceBack.currentFrame == 2)
		//				{
		//					this->container->iceBack.gotoAndStop(1);
		//				}
		//				if (this->container->stoneBack.currentFrame == 2)
		//				{
		//					this->container->stoneBack.gotoAndStop(1);
		//				}
		//				if (this->container->getAll.currentFrame == 2)
		//				{
		//					this->container->getAll.gotoAndStop(1);
		//				}
		//				this->container->levinBack.gotoAndStop(2);
		//				this->container->levinBack.cont.stop();
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//			}
		//		}
		//		else if (param1.target.parent.name == "getAll")
		//		{
		//			if (param1.target.buttonMode && this->container->getAll.currentFrame == 1)
		//			{
		//				if (this->container->fireBack.currentFrame == 2)
		//				{
		//					this->container->fireBack.gotoAndStop(1);
		//				}
		//				if (this->container->iceBack.currentFrame == 2)
		//				{
		//					this->container->iceBack.gotoAndStop(1);
		//				}
		//				if (this->container->stoneBack.currentFrame == 2)
		//				{
		//					this->container->stoneBack.gotoAndStop(1);
		//				}
		//				if (this->container->levinBack.currentFrame == 2)
		//				{
		//					this->container->levinBack.gotoAndStop(1);
		//				}
		//				this->container->getAll.gotoAndStop(2);
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//			}
		//			else if (this->container->getAll.currentFrame == 3)
		//			{
		//				if (this->container->levinSphere.visible && Main::mainClass->saveBoxClass.gameSave.data.saveNo <= 3)
		//				{
		//					if (!this->getAllHint)
		//					{
		//						this->getAllHint = new Hint_mc();
		//						this->getAllHint.gotoAndStop(15);
		//						this->getAllHint.x = 540;
		//						this->getAllHint.y = 45;
		//						var _loc_2 : *= false;
		//						this->getAllHint.mouseChildren = false;
		//						this->getAllHint.mouseEnabled = _loc_2;
		//						this->addChildAt(this->getAllHint, 1);
		//					}
		//				}
		//			}
		//		}
		//	}
		//	else
		//	{
		//		if (this->container->fireBack.currentFrame == 2)
		//		{
		//			this->container->fireBack.gotoAndStop(1);
		//		}
		//		if (this->container->iceBack.currentFrame == 2)
		//		{
		//			this->container->iceBack.gotoAndStop(1);
		//		}
		//		if (this->container->stoneBack.currentFrame == 2)
		//		{
		//			this->container->stoneBack.gotoAndStop(1);
		//		}
		//		if (this->container->levinBack.currentFrame == 2)
		//		{
		//			this->container->levinBack.gotoAndStop(1);
		//		}
		//		if (this->container->getAll.currentFrame == 2)
		//		{
		//			this->container->getAll.gotoAndStop(1);
		//		}
		//		if (this->getAllHint)
		//		{
		//			this->removeChild(this->getAllHint);
		//			this->getAllHint = null;
		//		}
		//	}
		//	if (param1.target.name == "慢")
		//	{
		//		if (this->container->慢.currentFrame == 1)
		//		{
		//			this->container->慢.gotoAndStop(2);
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//		}
		//	}
		//	else if (this->container->慢.currentFrame == 2)
		//	{
		//		this->container->慢.gotoAndStop(1);
		//	}
		//	if (param1.target.name == "fastCase")
		//	{
		//		if (param1.target.buttonMode)
		//		{
		//			if (this->container->快.currentFrame == 1 || this->container->快.currentFrame == 4)
		//			{
		//				if (this->container->快.currentFrame == 4)
		//				{
		//					this->tempObject = this->container->快.cont.currentFrame;
		//				}
		//				this->container->快.gotoAndStop((this->container->快.currentFrame + 1));
		//				if (this->container->快.currentFrame == 5)
		//				{
		//					this->container->快.cont.gotoAndStop(this->tempObject);
		//				}
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//			}
		//		}
		//	}
		//	else if (this->container->快.currentFrame == 2 || this->container->快.currentFrame == 5)
		//	{
		//		if (this->container->快.currentFrame == 5)
		//		{
		//			this->tempObject = this->container->快.cont.currentFrame;
		//		}
		//		this->container->快.gotoAndStop((this->container->快.currentFrame - 1));
		//		if (this->container->快.currentFrame == 4)
		//		{
		//			this->container->快.cont.gotoAndStop(this->tempObject);
		//		}
		//	}
		//	if (param1.target.name == "traceBezier")
		//	{
		//		if (this->container->traceBezier.currentFrame == 1)
		//		{
		//			this->container->traceBezier.gotoAndStop(2);
		//		}
		//	}
		//	else if (this->container->traceBezier.currentFrame == 2)
		//	{
		//		this->container->traceBezier.gotoAndStop(1);
		//	}
		//	if (param1.target.name == "pauseCase")
		//	{
		//		if (this->container->pause.currentFrame == 1)
		//		{
		//			this->container->pause.gotoAndStop(2);
		//			this->container->pause.openFlag = true;
		//			this->container->pause.closeFlag = false;
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//		}
		//	}
		//	else if (this->container->pause.currentFrame > 1)
		//	{
		//		if (this->container->pause.currentFrame == this->container->pause.totalFrames)
		//		{
		//			this->container->pause.gotoAndStop(this->container->pause.totalFrames);
		//		}
		//		if (this->container->pause.openFlag)
		//		{
		//			this->container->pause.openFlag = false;
		//		}
		//		if (!this->container->pause.closeFlag)
		//		{
		//			this->container->pause.closeFlag = true;
		//		}
		//	}
		//	if (param1.target.name == "bookCase")
		//	{
		//		if (this->container->book.currentFrame == 1)
		//		{
		//			this->container->book.gotoAndStop(2);
		//			this->container->book.openFlag = true;
		//			this->container->book.closeFlag = false;
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//		}
		//	}
		//	else if (this->container->book.currentFrame > 1)
		//	{
		//		if (this->container->book.currentFrame == this->container->book.totalFrames)
		//		{
		//			this->container->book.gotoAndStop(this->container->book.totalFrames);
		//		}
		//		if (this->container->book.openFlag)
		//		{
		//			this->container->book.openFlag = false;
		//		}
		//		if (!this->container->book.closeFlag)
		//		{
		//			this->container->book.closeFlag = true;
		//		}
		//	}
		//	if (param1.target.name == "startWavesCase")
		//	{
		//		if (this->container->startWaves.startWavesCase.buttonMode)
		//		{
		//			if (this->container->startWaves.currentFrame <= 10)
		//			{
		//				this->container->startWaves.gotoAndStop(this->container->startWaves.currentFrame + 10);
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//			}
		//		}
		//	}
		//	else if (this->container->startWaves.startWavesCase.buttonMode)
		//	{
		//		if (this->container->startWaves.currentFrame > 10)
		//		{
		//			this->container->startWaves.gotoAndStop(this->container->startWaves.currentFrame - 10);
		//		}
		//	}
		//	if (param1.target.name == "castGolemCase")
		//	{
		//		if (param1.target.parent->isVisible())
		//		{
		//			if (this->container->butCastGolem.currentFrame == 1)
		//			{
		//				this->container->butCastGolem.gotoAndStop(2);
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//				if (!this->world->hint->isVisible())
		//				{
		//					this->world->hint->setVisible(true);
		//				}
		//				if (this->world->hint.currentFrame != 1)
		//				{
		//					this->world->hint.gotoAndStop(1);
		//				}
		//				if (this->world->hint.nameTXT.text != "击碎者就绪!")
		//				{
		//					this->world->hint.nameTXT.text = "击碎者就绪!";
		//					this->world->hint.noteTXT.text = "一路碾压所有敌人";
		//					this->world->hint.nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
		//					this->world->hint.timeTXT.text = int(this->castGolemTimer / 30);
		//					this->world->hint.timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
		//					this->hintUpdate();
		//				}
		//			}
		//			else if (this->container->butCastGolem.currentFrame == 4)
		//			{
		//				if (!this->world->hint->isVisible())
		//				{
		//					this->world->hint->setVisible(true);
		//				}
		//				if (this->world->hint.currentFrame != 1)
		//				{
		//					this->world->hint.gotoAndStop(1);
		//				}
		//				if (this->world->hint.nameTXT.text != "击碎者重置")
		//				{
		//					this->world->hint.nameTXT.text = "击碎者重置";
		//					this->world->hint.noteTXT.text = "一路碾压所有敌人";
		//					this->world->hint.nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
		//					this->hintUpdate();
		//				}
		//			}
		//		}
		//	}
		//	else
		//	{
		//		if (this->container->butCastGolem.currentFrame == 2)
		//		{
		//			this->container->butCastGolem.gotoAndStop(1);
		//		}
		//		if (this->world->hint->isVisible())
		//		{
		//			if (this->world->hint.nameTXT.text == "击碎者重置" || this->world->hint.nameTXT.text == "击碎者就绪!")
		//			{
		//				this->world->hint->setVisible( false);
		//			}
		//		}
		//	}
		//	if (param1.target.name == "castIcemanCase")
		//	{
		//		if (param1.target.parent->isVisible())
		//		{
		//			if (this->container->butCastIceman.currentFrame == 1)
		//			{
		//				this->container->butCastIceman.gotoAndStop(2);
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//				if (!this->world->hint->isVisible())
		//				{
		//					this->world->hint->setVisible(true);
		//				}
		//				if (this->world->hint.currentFrame != 1)
		//				{
		//					this->world->hint.gotoAndStop(1);
		//				}
		//				if (this->world->hint.nameTXT.text != "冰冻者就绪!")
		//				{
		//					this->world->hint.nameTXT.text = "冰冻者就绪!";
		//					this->world->hint.noteTXT.text = "一路冻结所有敌人";
		//					this->world->hint.nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
		//					this->world->hint.timeTXT.text = int(this->castIcemanTimer / 30);
		//					this->world->hint.timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
		//					this->hintUpdate();
		//				}
		//			}
		//			else if (this->container->butCastIceman.currentFrame == 4)
		//			{
		//				if (!this->world->hint->isVisible())
		//				{
		//					this->world->hint->setVisible(true);
		//				}
		//				if (this->world->hint.currentFrame != 1)
		//				{
		//					this->world->hint.gotoAndStop(1);
		//				}
		//				if (this->world->hint.nameTXT.text != "冰冻者重置")
		//				{
		//					this->world->hint.nameTXT.text = "冰冻者重置";
		//					this->world->hint.noteTXT.text = "一路冻结所有敌人";
		//					this->world->hint.nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
		//					this->hintUpdate();
		//				}
		//			}
		//		}
		//	}
		//	else
		//	{
		//		if (this->container->butCastIceman.currentFrame == 2)
		//		{
		//			this->container->butCastIceman.gotoAndStop(1);
		//		}
		//		if (this->world->hint->isVisible())
		//		{
		//			if (this->world->hint.nameTXT.text == "冰冻者重置" || this->world->hint.nameTXT.text == "冰冻者就绪!")
		//			{
		//				this->world->hint->setVisible( false);
		//			}
		//		}
		//	}
		//	if (param1.target.name == "castAirCase")
		//	{
		//		if (param1.target.parent->isVisible())
		//		{
		//			if (this->container->butCastAir.currentFrame == 1)
		//			{
		//				this->container->butCastAir.gotoAndStop(2);
		//				Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//				if (!this->world->hint->isVisible())
		//				{
		//					this->world->hint->setVisible(true);
		//				}
		//				if (this->world->hint.currentFrame != 1)
		//				{
		//					this->world->hint.gotoAndStop(1);
		//				}
		//				if (this->world->hint.nameTXT.text != "复活岛巨像就绪!")
		//				{
		//					this->world->hint.nameTXT.text = "复活岛巨像就绪!";
		//					this->world->hint.noteTXT.text = "将敌人吹飞到后面";
		//					this->world->hint.nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
		//					this->world->hint.timeTXT.text = int(this->castAirTimer / 30);
		//					this->world->hint.timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
		//					this->hintUpdate();
		//				}
		//			}
		//			else if (this->container->butCastAir.currentFrame == 4)
		//			{
		//				if (!this->world->hint->isVisible())
		//				{
		//					this->world->hint->setVisible(true);
		//				}
		//				if (this->world->hint.currentFrame != 1)
		//				{
		//					this->world->hint.gotoAndStop(1);
		//				}
		//				if (this->world->hint.nameTXT.text != "复活岛巨像重置")
		//				{
		//					this->world->hint.nameTXT.text = "复活岛巨像重置";
		//					this->world->hint.noteTXT.text = "将敌人吹飞到后面";
		//					this->world->hint.nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
		//					this->hintUpdate();
		//				}
		//			}
		//		}
		//	}
		//	else
		//	{
		//		if (this->container->butCastAir.currentFrame == 2)
		//		{
		//			this->container->butCastAir.gotoAndStop(1);
		//		}
		//		if (this->world->hint->isVisible())
		//		{
		//			if (this->world->hint.nameTXT.text == "复活岛巨像重置" || this->world->hint.nameTXT.text == "复活岛巨像就绪!")
		//			{
		//				this->world->hint->setVisible( false);
		//			}
		//		}
		//	}
		//	if (param1.target.name == "pointerCase")
		//	{
		//		if (!param1.target.parent.mouseFlag)
		//		{
		//			this->world->pointer1.mouseFlag = true;
		//			if (this->world->pointer2)
		//			{
		//				this->world->pointer2.mouseFlag = true;
		//			}
		//			if (this->world->pointer3)
		//			{
		//				this->world->pointer3.mouseFlag = true;
		//			}
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//		}
		//	}
		//	else
		//	{
		//		if (this->world->pointer1.mouseFlag)
		//		{
		//			this->world->pointer1.mouseFlag = false;
		//		}
		//		if (this->world->pointer2)
		//		{
		//			if (this->world->pointer2.mouseFlag)
		//			{
		//				this->world->pointer2.mouseFlag = false;
		//			}
		//		}
		//		if (this->world->pointer3)
		//		{
		//			if (this->world->pointer3.mouseFlag)
		//			{
		//				this->world->pointer3.mouseFlag = false;
		//			}
		//		}
		//	}
		//	if (param1.target.name == "newEnemyCase" || param1.target.name == "newElementCase")
		//	{
		//		this->tempObject = param1.target.parent;
		//		if (this->tempObject.mouseStatus == 1)
		//		{
		//			this->tempObject.mouseStatus = 2;
		//			var _loc_2 : *= 1.1;
		//			this->tempObject.scaleY = 1.1;
		//			this->tempObject.scaleX = _loc_2;
		//			Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
		//		}
		//	}
		//	else if (this->listOfNewEnemies.length > 0)
		//	{
		//		this->i = 0;
		//		while (this->i < this->listOfNewEnemies.length)
		//		{
		//			if (this->listOfNewEnemies[this->i].mouseStatus == 2)
		//			{
		//				this->listOfNewEnemies[this->i].mouseStatus = 1;
		//				var _loc_2 : *= 1;
		//				this->listOfNewEnemies[this->i].scaleY = 1;
		//				this->listOfNewEnemies[this->i].scaleX = _loc_2;
		//			}
		//			var _loc_2 : *= this;
		//			var _loc_3 : *= this->i + 1;
		//			_loc_2.i = _loc_3;
		//		}
		//	}
		//	if (param1.target.name == "testRestart")
		//	{
		//		if (this->container->testRestart.currentFrame == 1)
		//		{
		//			this->container->testRestart.gotoAndStop(2);
		//		}
		//	}
		//	else if (this->container->testRestart.currentFrame == 2)
		//	{
		//		this->container->testRestart.gotoAndStop(1);
		//	}
		//	if (param1.target.name == "sellCase")
		//	{
		//		if (!this->sellHint)
		//		{
		//			this->sellHint = new Hint_mc();
		//			this->sellHint.gotoAndStop(14);
		//			this->sellHint.x = 645;
		//			this->sellHint.y = 50;
		//			var _loc_2 : *= 0.7;
		//			this->sellHint.scaleY = 0.7;
		//			this->sellHint.scaleX = _loc_2;
		//			var _loc_2 : *= false;
		//			this->sellHint.mouseChildren = false;
		//			this->sellHint.mouseEnabled = _loc_2;
		//			this->addChild(this->sellHint);
		//		}
		//	}
		//	else if (this->sellHint)
		//	{
		//		this->removeChild(this->sellHint);
		//		this->sellHint = null;
		//	}
		//}
	}
    void WorldInterface::mouseUpHandler(cocos2d::Event *event)//(event:MouseEvent) : void
	{
		//if (!this->world->getSphere && !this->world->cast)
		//{
		//	if (event.target.name == "慢")
		//	{
		//		if (this->container->慢.currentFrame == 3)
		//		{
		//			if (this->fasterFlag != 1)
		//			{
		//				this->fastPlayControl(1);
		//				if (this->container->快.currentFrame != 1)
		//				{
		//					this->container->快.gotoAndStop(1);
		//				}
		//			}
		//			else
		//			{
		//				this->fastPlayControl(0);
		//				this->container->慢.gotoAndStop(2);
		//			}
		//		}
		//	}
		//	else if (this->container->慢.currentFrame == 3)
		//	{
		//		if (this->fasterFlag != 1)
		//		{
		//			this->container->慢.gotoAndStop(1);
		//		}
		//	}
		//	if (event.target.name == "fastCase")
		//	{
		//		if (event.target.buttonMode)
		//		{
		//			if (this->container->快.currentFrame == 3 || this->container->快.currentFrame == 6)
		//			{
		//				this->fasterManage(true);
		//			}
		//		}
		//	}
		//	else if (this->container->快.currentFrame == 3 || this->container->快.currentFrame == 6)
		//	{
		//		this->container->快.gotoAndStop(this->container->快.currentFrame - 2);
		//		if (this->container->快.currentFrame == 4)
		//		{
		//			this->container->快.cont.stop();
		//		}
		//	}
		//	if (event.target.name == "traceBezier")
		//	{
		//		if (this->container->traceBezier.currentFrame == 3)
		//		{
		//			this->container->traceBezier.gotoAndStop(2);
		//		}
		//	}
		//	else if (this->container->traceBezier.currentFrame == 3)
		//	{
		//		this->container->traceBezier.gotoAndStop(1);
		//	}
		//	if (event.target.name == "pauseCase")
		//	{
		//		if (this->container->pause.currentFrame == this->container->pause.totalFrames)
		//		{
		//			this->addPause();
		//		}
		//	}
		//	else if (this->container->pause.currentFrame > 1)
		//	{
		//		if (this->container->pause.currentFrame == this->container->pause.totalFrames)
		//		{
		//			this->container->pause.gotoAndStop((this->container->pause.totalFrames - 1));
		//		}
		//		if (this->container->pause.opneFlag)
		//		{
		//			this->container->pause.opneFlag = false;
		//		}
		//		if (!this->container->pause.closeFlag)
		//		{
		//			this->container->pause.closeFlag = true;
		//		}
		//	}
		//	if (event.target.name == "bookCase")
		//	{
		//		if (this->container->book.currentFrame == this->container->book.totalFrames)
		//		{
		//			this->addEncyclopedia();
		//		}
		//	}
		//	else if (this->container->book.currentFrame > 1)
		//	{
		//		if (this->container->book.currentFrame == this->container->book.totalFrames)
		//		{
		//			this->container->book.gotoAndStop((this->container->book.totalFrames - 1));
		//		}
		//		if (this->container->book.opneFlag)
		//		{
		//			this->container->book.opneFlag = false;
		//		}
		//		if (!this->container->book.closeFlag)
		//		{
		//			this->container->book.closeFlag = true;
		//		}
		//	}
		//	if (event.target.name == "testRestart")
		//	{
		//		if (this->container->testRestart.currentFrame == 3)
		//		{
		//			this->container->testRestart.gotoAndStop(2);
		//			if (this->container->testRestartBoard.waveTXT.text == "")
		//			{
		//				Main::mainClass->testingClass.loadWave = Main::mainClass->worldClass.wavesClass.nowWave;
		//			}
		//			else if (int(this->container->testRestartBoard.waveTXT.text) < Main::mainClass->testingClass.listOfStory.length)
		//			{
		//				Main::mainClass->testingClass.loadWave = int(this->container->testRestartBoard.waveTXT.text);
		//			}
		//			else
		//			{
		//				Main::mainClass->testingClass.loadWave = 0;
		//			}
		//			Main::mainClass->addNewScreen("World");
		//		}
		//	}
		//	else if (this->container->testRestart.currentFrame == 3)
		//	{
		//		this->container->testRestart.gotoAndStop(1);
		//	}
		//}
	}// end function
    void WorldInterface::spheresBlockManage(string param1)
    {
        if (param1 == "")
        {
            //this->container->fireSphere.alpha = 0;
            //this->container->fireNumTXT.alpha = 0;
            //this->container->buyFire.alpha = 0;
            //this->container->fireSphere.mouseChildren = false;
            //this->container->fireSphere.mouseEnabled = false;
            //this->container->fireNumTXT.mouseEnabled = false;
            //this->container->buyFire.mouseChildren = false;
            //this->container->buyFire.mouseEnabled = false;
            //this->container->fireSphere.visible = false;
            //this->container->iceSphere.alpha = 0;
            //this->container->iceNumTXT.alpha = 0;
            //this->container->buyIce.alpha = 0;
            //this->container->iceSphere.mouseChildren = false;
            //this->container->iceSphere.mouseEnabled = false;
            //this->container->iceNumTXT.mouseEnabled = false;
            //this->container->buyIce.mouseChildren = false;
            //this->container->buyIce.mouseEnabled = false;
            //this->container->iceSphere.visible = false;
            //this->container->stoneSphere.alpha = 0;
            //this->container->stoneNumTXT.alpha = 0;
            //this->container->buyStone.alpha = 0;
            //this->container->stoneSphere.mouseChildren = false;
            //this->container->stoneSphere.mouseEnabled = false;
            //this->container->stoneNumTXT.mouseEnabled = false;
            //this->container->buyStone.mouseChildren = false;
            //this->container->buyStone.mouseEnabled = false;
            //this->container->stoneSphere.visible = false;
            //this->container->levinSphere.alpha = 0;
            //this->container->levinNumTXT.alpha = 0;
            //this->container->buyLevin.alpha = 0;
            //this->container->levinSphere.mouseChildren = false;
            //this->container->levinSphere.mouseEnabled = false;
            //this->container->levinNumTXT.mouseEnabled = false;
            //this->container->buyLevin.mouseChildren = false;
            //this->container->buyLevin.mouseEnabled = false;
            //this->container->levinSphere.visible = false;
            //this->container->getAll.gotoAndStop(3);
            //this->container->buyGetAll.alpha = 0;
            //this->container->getAllNumTXT.alpha = 0;
            //this->container->getAllNumTXT.mouseEnabled = false;
            //this->container->buyGetAll.mouseChildren = false;
            //this->container->buyGetAll.mouseEnabled = false;
            //this->container->fireBack.gotoAndStop(3);
            //this->container->iceBack.gotoAndStop(3);
            //this->container->stoneBack.gotoAndStop(3);
            //this->container->levinBack.gotoAndStop(3);
            if (Main::mainClass->readXMLClass.archiveSphereBlock == 3)
            {
                this->container->fireSphere->setVisible( true);
                //this->container->fireBack.gotoAndStop(1);
            }
            else if (Main::mainClass->readXMLClass.archiveSphereBlock == 2)
            {
                this->container->fireSphere->setVisible(true);
                this->container->iceSphere->setVisible(true);
                //this->container->fireBack.gotoAndStop(1);
                //this->container->iceBack.gotoAndStop(1);
            }
            else if (Main::mainClass->readXMLClass.archiveSphereBlock == 1)
            {
                this->container->fireSphere->setVisible(true);
                this->container->iceSphere->setVisible(true);
                this->container->stoneSphere->setVisible(true);
                //this->container->fireBack.gotoAndStop(1);
                //this->container->iceBack.gotoAndStop(1);
                //this->container->stoneBack.gotoAndStop(1);
            }
            else if (Main::mainClass->readXMLClass.archiveSphereBlock == 0)
            {
                this->container->fireSphere->setVisible(true);
                this->container->iceSphere->setVisible(true);
                this->container->stoneSphere->setVisible(true);
                this->container->levinSphere->setVisible(true);
                //this->container->fireBack.gotoAndStop(1);
                //this->container->iceBack.gotoAndStop(1);
                //this->container->stoneBack.gotoAndStop(1);
                //this->container->levinBack.gotoAndStop(1);
            }
            if (this->world->saveBox->getIntValue("complexityLevel") == 4)
            {
                if (this->world->nowLevel == 4)
                {
                    this->container->stoneSphere->setVisible(true);
                    this->container->levinSphere->setVisible(true);
                    //this->container->stoneBack.gotoAndStop(1);
                    //this->container->levinBack.gotoAndStop(1);
                }
                else if (this->world->nowLevel == 5)
                {
                    this->container->iceSphere->setVisible(true);
                    this->container->levinSphere->setVisible(true);
                    //this->container->iceBack.gotoAndStop(1);
                    //this->container->levinBack.gotoAndStop(1);
                }
                else if (this->world->nowLevel == 8)
                {
                    this->container->fireSphere->setVisible(true);
                    this->container->iceSphere->setVisible(true);
                    this->container->levinSphere->setVisible(true);
                    //this->container->fireBack.gotoAndStop(1);
                    //this->container->iceBack.gotoAndStop(1);
                    //this->container->levinBack.gotoAndStop(1);
                }
                else if (this->world->nowLevel == 13)
                {
                    this->container->iceSphere->setVisible(true);
                    this->container->levinSphere->setVisible(true);
                    //this->container->iceBack.gotoAndStop(1);
                    //this->container->levinBack.gotoAndStop(1);
                }
                else if (this->world->nowLevel == 15)
                {
                    this->container->fireSphere->setVisible(true);
                    this->container->iceSphere->setVisible(true);
                    this->container->levinSphere->setVisible(true);
                    //this->container->fireBack.gotoAndStop(1);
                    //this->container->iceBack.gotoAndStop(1);
                    //this->container->levinBack.gotoAndStop(1);
                }
            }
        }
        else if (param1 == "unblockFire")
        { 
            //this->container->fireSphere.scaleY = 1;
            //this->container->fireSphere.scaleX = 1;
            //this->container->fireSphere.alpha = 1;
            //this->container->fireNumTXT.alpha = 1;
            //this->container->buyFire.alpha = 1;
            //this->container->fireSphere.mouseChildren = true;
            //this->container->fireSphere.mouseEnabled = true;
            //this->container->fireNumTXT.mouseEnabled = false;
            //this->container->buyFire.mouseChildren = true;
            //this->container->buyFire.mouseEnabled = true;
            //this->container->fireBack.gotoAndStop(1);
        }
        else if (param1 == "unblockIce")
        {
            //this->container->iceSphere.scaleY = 1;
            //this->container->iceSphere.scaleX = 1;
            //this->container->iceSphere.alpha = 1;
            //this->container->iceNumTXT.alpha = 1;
            //this->container->buyIce.alpha = 1;
            //this->container->iceSphere.mouseChildren = true;
            //this->container->iceSphere.mouseEnabled = true;
            //this->container->iceNumTXT.mouseEnabled = false;
            //this->container->buyIce.mouseChildren = true;
            //this->container->buyIce.mouseEnabled = true;
            //this->container->iceBack.gotoAndStop(1);
        }
        else if (param1 == "unblockStone")
        {
            //this->container->stoneSphere.scaleY = 1;
            //this->container->stoneSphere.scaleX = 1;
            //this->container->stoneSphere.alpha = 1;
            //this->container->stoneNumTXT.alpha = 1;
            //this->container->buyStone.alpha = 1;
            //this->container->stoneSphere.mouseChildren = true;
            //this->container->stoneSphere.mouseEnabled = true;
            //this->container->stoneNumTXT.mouseEnabled = false;
            //this->container->buyStone.mouseChildren = true;
            //this->container->buyStone.mouseEnabled = true;
            //this->container->stoneBack.gotoAndStop(1);
        }
        else if (param1 == "unblockLevin")
        { 
            //this->container->levinSphere.scaleY = 1;
            //this->container->levinSphere.scaleX = 1;
            //this->container->levinSphere.alpha = 1;
            //this->container->levinNumTXT.alpha = 1;
            //this->container->buyLevin.alpha = 1;
            //this->container->levinSphere.mouseChildren = true;
            //this->container->levinSphere.mouseEnabled = true;
            //this->container->levinNumTXT.mouseEnabled = false;
            //this->container->buyLevin.mouseChildren = true;
            //this->container->buyLevin.mouseEnabled = true;
            //this->container->levinBack.gotoAndStop(1);
        }
        else if (param1 == "unblockGetAll")
        {
            //this->container->getAll.scaleY = 1;
            //this->container->getAll.scaleX = 1;
            //this->container->getAll.gotoAndStop(1);
            //this->container->getAll.fire.stop();
            //this->container->getAll.ice.stop();
            //this->container->getAll.stone.stop();
            //this->container->getAll.levin.stop();
            //this->container->buyGetAll.alpha = 1;
            //this->container->getAllNumTXT.alpha = 1;
            //this->container->getAllNumTXT.mouseEnabled = false;
            //this->container->buyGetAll.mouseChildren = true;
            //this->container->buyGetAll.mouseEnabled = true;
        }
        this->updateInfo();
        return;
    }// end function
}