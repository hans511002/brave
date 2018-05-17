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
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		this->world = Main::mainClass->worldClass;

		BaseNode *point = this->world->pointer1;// Sprite::create("public/point.png");
		//point->setPosition(400, 250);
		EventListenerMouse *mouseListener= cocos2d::EventListenerMouse::create();
        mouseListener->onMouseDown = CC_CALLBACK_1(WorldInterface::mouseDownHandler, this->;
        mouseListener->onMouseUp = CC_CALLBACK_1(WorldInterface::mouseUpHandler, this->;
        mouseListener->onMouseMove = CC_CALLBACK_1(WorldInterface::mouseMoveHandler, this->; 
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this->;
       	point->setVisible(true); 
        
 		//this->addChild(point);

		
	
//////////////////////////begin////////////////////////////////
		this->mouseChildren = false;
		this->mouseEnabled = false;
		this->alpha = 0;
		this->container = new WorldInterface_mc();
        this->addChild(this->container);
        this->container->init();
        this->container->setPosition(0, 0);
 
		this->container->stop();
		this->container->fireBack->stop();
		this->container->iceBack->stop();
		this->container->stoneBack->stop();
		this->container->levinBack->stop();
		this->container->backComponents->stop();
		this->container->fireSphere->stop();
		this->container->iceSphere->stop();
		this->container->stoneSphere->stop();
		this->container->levinSphere->stop();
		this->container->getAll->stop();
		this->container->buyFire->stop();
		this->container->buyIce->stop();
		this->container->buyStone->stop();
		this->container->buyLevin->stop();
		this->container->buygetAll->stop();
		this->container->buyFire->coin->stop();
		this->container->buyIce->coin->stop();
		this->container->buyStone->coin->stop();
		this->container->buyLevin->coin->stop();
		this->container->buygetAll->coin->stop();
		this->container->buyFire->lightUp->stop();
		this->container->buyIce->lightUp->stop();
		this->container->buyStone->lightUp->stop();
		this->container->buyLevin->lightUp->stop();
		this->container->buygetAll->lightUp->stop();
		this->container->sell->stop();
		this->container->book->stop();
		this->container->pause->stop();
		this->container->startWaves->stop();
		this->container->butCastGolem->stop();
		this->container->butCastIceman->stop();
		this->container->butCastAir->stop();
		this->container->barInfo->stop();
		this->container->slow->stop();
		this->container->fast->stop();
		this->container->traceBezier->stop();
		this->container->barInfo->y = 585;
		this->container->book->bookCase->buttonMode = true;
		this->container->pause->pauseCase->buttonMode = true;
		this->container->startWaves->startWavesCase->buttonMode = true;
		this->container->butCastGolem->castGolemCase->buttonMode = true;
		this->container->butCastIceman->castIcemanCase->buttonMode = true;
		this->container->butCastAir->castAirCase->buttonMode = true;
		this->container->slow->buttonMode = true;
		this->container->traceBezier->buttonMode = true;
		this->container->fireNumTXT->mouseEnabled = false;
		this->container->iceNumTXT->mouseEnabled = false;
		this->container->stoneNumTXT->mouseEnabled = false;
		this->container->levinNumTXT->mouseEnabled = false; 
		this->container->barInfo->mouseChildren = false;
		this->container->barInfo->mouseEnabled = false;
		this->container->lastTime->mouseEnabled = false;
		this->container->butCastGolem->alpha = 0;
		this->container->butCastIceman->alpha = 0;
		this->container->butCastAir->alpha = 0;

		this->container->butCastGolem->setVisible( false);
		this->container->butCastIceman->setVisible( false);
		this->container->butCastAir->setVisible( false);
		this->container->barInfo->setVisible( false);
		this->container->lastTime->setVisible( false);
		this->container->buyFire->setVisible( false);
		this->container->buyIce->setVisible( false);
		this->container->buyStone->setVisible( false);
		this->container->buyLevin->setVisible( false);
		this->container->backComponents.cacheAsBitmap = true;
		this->addChild(this->container);
		this->container->fireSphere->myPoint = this->container->fireSphere->localToGlobal(this->container->fireSphere->sphereCase->getPosition());
		this->container->iceSphere->myPoint = this->container->iceSphere->localToGlobal(this->container->iceSphere->sphereCase->getPosition());
		this->container->stoneSphere->myPoint = this->container->stoneSphere->localToGlobal(this->container->stoneSphere->sphereCase->getPosition());
		this->container->levinSphere->myPoint = this->container->levinSphere->localToGlobal(this->container->levinSphere->sphereCase->getPosition());
		this->container->getAll->myPoint = this->container->getAll->localToGlobal(this->container->getAll->sphereCase->getPosition());
		this->castGolemTimer = Main::mainClass->readXMLClass.intervalTimerGolemXML;
		this->castIcemanTimer = Main::mainClass->readXMLClass.intervalTimerIcemanXML;
		this->castAirTimer = Main::mainClass->readXMLClass.intervalTimerAirXML;
		this->container->fireBacklight->turnFlag = true;
		this->container->iceBacklight->turnFlag = true;
		this->container->stoneBacklight->turnFlag = true;
		this->container->levinBacklight->turnFlag = true;
		this->container->fireBacklight->stop();
		this->container->iceBacklight->stop();
		this->container->stoneBacklight->stop();
		this->container->levinBacklight->stop();
		this->container->fireBacklight->setVisible( false);
		this->container->iceBacklight->setVisible( false);
		this->container->stoneBacklight->setVisible( false);
		this->container->levinBacklight->setVisible( false);
		this->container->buyGetAll->setVisible( false);
		this->container->testRestart->stop();
		this->container->testRestartBoard->stop();
		this->container->testRestart->buttonMode = true;
		if (Main::mainClass->readXMLClass.bezierBuildXML)
		{
			this->world->bezierClass->tracePoints = this->container->traceBezier;
			this->world->bezierClass->tracePoints.addEventListener(MouseEvent.CLICK, this->world->bezierClass->tracePointsArr);
		}
		else
		{
			this->container->traceBezier->setVisible( false);
		}
		this->lastTime = this->container->lastTime;
		this->container->removeChild(this->lastTime);
		this->world->addChild(this->lastTime);
		if (this->world->saveBox.gameSave.data.complexityLevel == 4)
		{
			this->world->listOfIndexes3.push(this->lastTime);
		}
		this->container->testRestart->setVisible( false);
		this->container->testRestartBoard->setVisible( false);
		this->container->slow->setVisible( false);

       


        //this->container->startWaves->addClickEventListener(CC_CALLBACK_1(WorldInterface::clickHandler, this->);
        //this->container->fastbtn->addClickEventListener(CC_CALLBACK_1(WorldInterface::clickHandler, this->);
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
		this->castMask->setVisible( false);
		this->addChild(this->castMask);
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
		if (this->mouseEnabled)
		{
			if (this->container->fast->cont)
			{
				if (this->world->frameCounter % 2)
				{
					if (this->container->fast->cont->currentFrame < this->container->fast->cont->totalFrames)
					{
						this->container->fast->cont->gotoAndStop((this->container->fast->cont->currentFrame + 1));
					}
					else
					{
						this->container->fast->cont->gotoAndStop(1);
					}
				}
			}
			if (this->container->pause->openFlag)
			{
				if (this->container->pause->currentFrame < (this->container->pause->totalFrames - 1))
				{
					this->container->pause->gotoAndStop((this->container->pause->currentFrame + 1));
				}
				else
				{
					this->container->pause->openFlag = false;
				}
			}
			else if (this->container->pause->closeFlag)
			{
				if (this->container->pause->currentFrame > 1 && this->container->pause->currentFrame < this->container->pause->totalFrames)
				{
					this->container->pause->gotoAndStop((this->container->pause->currentFrame - 1));
				}
				else
				{
					this->container->pause->closeFlag = false;
				}
			}
			if (this->container->book->openFlag)
			{
				if (this->container->book->currentFrame < (this->container->book->totalFrames - 1))
				{
					this->container->book->gotoAndStop((this->container->book->currentFrame + 1));
				}
				else
				{
					this->container->book->openFlag = false;
				}
			}
			else if (this->container->book->closeFlag)
			{
				if (this->container->book->currentFrame > 1 && this->container->book->currentFrame < this->container->book->totalFrames)
				{
					this->container->book->gotoAndStop((this->container->book->currentFrame - 1));
				}
				else
				{
					this->container->book->closeFlag = false;
				}
			}
			if (this->fireCount > 0)
			{
				if (this->container->fireSphere->currentFrame < this->container->fireSphere->totalFrames)
				{
					this->container->fireSphere->gotoAndStop((this->container->fireSphere->currentFrame + 1));
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
					this->container->iceSphere->gotoAndStop((this->container->iceSphere->currentFrame + 1));
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
					this->container->stoneSphere->gotoAndStop((this->container->stoneSphere->currentFrame + 1));
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
					this->container->levinSphere->gotoAndStop((this->container->levinSphere->currentFrame + 1));
				}
				else
				{
					this->container->levinSphere->gotoAndStop(1);
				}
			}
			if (this->getAllCount > 0)
			{
				if (this->container->getAll->fire)
				{
					if (this->container->getAll->fire->currentFrame < this->container->getAll->fire->totalFrames)
					{
						this->container->getAll->fire->gotoAndStop((this->container->getAll->fire->currentFrame + 1));
					}
					else
					{
						this->container->getAll->fire->gotoAndStop(1);
					}
					if (this->container->getAll->ice->currentFrame < this->container->getAll->ice->totalFrames)
					{
						this->container->getAll->ice->gotoAndStop((this->container->getAll->ice->currentFrame + 1));
					}
					else
					{
						this->container->getAll->ice->gotoAndStop(1);
					}
					if (this->container->getAll->stone->currentFrame < this->container->getAll->stone->totalFrames)
					{
						this->container->getAll->stone->gotoAndStop((this->container->getAll->stone->currentFrame + 1));
					}
					else
					{
						this->container->getAll->stone->gotoAndStop(1);
					}
					if (this->container->getAll->levin->currentFrame < this->container->getAll->levin->totalFrames)
					{
						this->container->getAll->levin->gotoAndStop((this->container->getAll->levin->currentFrame + 1));
					}
					else
					{
						this->container->getAll->levin->gotoAndStop(1);
					}
				}
			}
			if (this->container->startWaves->currentFrame <= 10)
			{
				if (this->container->startWaves->currentFrame < 10)
				{
					this->container->startWaves->gotoAndStop((this->container->startWaves->currentFrame + 1));
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
					this->container->startWaves->gotoAndStop((this->container->startWaves->currentFrame + 1));
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
					if (this->container->butCastGolem->alpha < 1)
					{
						this->container->butCastGolem->alpha = this->container->butCastGolem->alpha + 0.2;
					}
					else
					{
						this->blockCastGolem = true;
						this->container->butCastGolem->alpha = 1;
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
					if (this->container->butCastIceman->alpha < 1)
					{
						this->container->butCastIceman->alpha = this->container->butCastIceman->alpha + 0.2;
					}
					else
					{
						this->blockCastIceman = true;
						this->container->butCastIceman->alpha = 1;
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
					if (this->container->butCastAir->alpha < 1)
					{
						this->container->butCastAir->alpha = this->container->butCastAir->alpha + 0.2;
					}
					else
					{
						this->blockCastAir = true;
						this->container->butCastAir->alpha = 1;
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
				if (!this->container->fireSphere->opened)
				{
					if (this->container->fireSphere->alpha < 1)
					{
						if (this->container->fireBack->currentFrame != 1)
						{
							this->container->fireBack->gotoAndStop(1);
						}
						this->container->fireSphere->alpha = this->container->fireSphere->alpha + 0.2;
						this->container->fireNumTXT->alpha = this->container->fireNumTXT->alpha + 0.2;
						this->container->buyFire->alpha = this->container->buyFire->alpha + 0.2;
					}
					else if (this->container->fireSphere->getScaleX() < 1)
					{
						this->container->fireSphere->setScaleX( this->container->fireSphere->getScaleX() + 0.25);
						this->container->fireSphere->setScaleY( this->container->fireSphere->getScaleY() + 0.25);
					}
					else
					{
						this->container->fireSphere->opened = true;
						this->spheresBlockManage("unblockFire");
					}
				}
			}
			if (this->container->iceSphere->isVisible())
			{
				if (!this->container->iceSphere->opened)
				{
					if (this->container->iceSphere->alpha < 1)
					{
						if (this->container->iceBack->currentFrame != 1)
						{
							this->container->iceBack->gotoAndStop(1);
						}
						this->container->iceSphere->alpha = this->container->iceSphere->alpha + 0.2;
						this->container->iceNumTXT->alpha = this->container->iceNumTXT->alpha + 0.2;
						this->container->buyIce->alpha = this->container->buyIce->alpha + 0.2;
					}
					else if (this->container->iceSphere->scaleX < 1)
					{
						this->container->iceSphere->scaleX = this->container->iceSphere->scaleX + 0.25;
						this->container->iceSphere->scaleY = this->container->iceSphere->scaleY + 0.25;
					}
					else
					{
						this->container->iceSphere->opened = true;
						this->spheresBlockManage("unblockIce");
					}
				}
			}
			if (this->container->stoneSphere->isVisible())
			{
				if (!this->container->stoneSphere->opened)
				{
					if (this->container->stoneSphere->alpha < 1)
					{
						if (this->container->stoneBack->currentFrame != 1)
						{
							this->container->stoneBack->gotoAndStop(1);
						}
						this->container->stoneSphere->alpha = this->container->stoneSphere->alpha + 0.2;
						this->container->stoneNumTXT->alpha = this->container->stoneNumTXT->alpha + 0.2;
						this->container->buyStone->alpha = this->container->buyStone->alpha + 0.2;
					}
					else if (this->container->stoneSphere->scaleX < 1)
					{
						this->container->stoneSphere->scaleX = this->container->stoneSphere->scaleX + 0.25;
						this->container->stoneSphere->scaleY = this->container->stoneSphere->scaleY + 0.25;
					}
					else
					{
						this->container->stoneSphere->opened = true;
						this->spheresBlockManage("unblockStone");
					}
				}
			}
			if (this->container->levinSphere->isVisible())
			{
				if (!this->container->levinSphere->opened)
				{
					if (this->container->levinSphere->alpha < 1)
					{
						if (this->container->levinBack->currentFrame != 1)
						{
							this->container->levinBack->gotoAndStop(1);
						}
						this->container->levinSphere->alpha = this->container->levinSphere->alpha + 0.2;
						this->container->levinNumTXT->alpha = this->container->levinNumTXT->alpha + 0.2;
						this->container->buyLevin->alpha = this->container->buyLevin->alpha + 0.2;
					}
					else if (this->container->levinSphere->scaleX < 1)
					{
						this->container->levinSphere->scaleX = this->container->levinSphere->scaleX + 0.25;
						this->container->levinSphere->scaleY = this->container->levinSphere->scaleY + 0.25;
					}
					else
					{
						this->container->levinSphere->opened = true;
						this->spheresBlockManage("unblockLevin");
					}
				}
			}
			if (!this->container->getAll->opened)
			{
				if (this->container->fireSphere->isVisible() && this->container->iceSphere->isVisible() && this->container->stoneSphere->isVisible() && this->container->levinSphere->isVisible())
				{
					if (Main::mainClass->saveBoxClass->getIntValue("saveNo") > 3)
					{
						if (Main::mainClass->readXMLClass.towerSlotBlock == 0)
						{
							if (this->container->getAll->alpha < 1)
							{
								this->container->getAll->alpha = this->container->getAll->alpha + 0.2;
								this->container->getAll->alpha = this->container->getAll->alpha + 0.2;
								this->container->buygetAll->alpha = this->container->buygetAll->alpha + 0.2;
							}
							else if (this->container->getAll->scaleX < 1)
							{
								this->container->getAll->scaleX = this->container->getAll->scaleX + 0.25;
								this->container->getAll->scaleY = this->container->getAll->scaleY + 0.25;
							}
							else
							{
								this->container->getAll->opened = true;
								this->spheresBlockManage("unblockGetAll");
							}
						}
					}
					else
					{
						this->container->getAll->opened = true;
					}
				}
			}
			this->downloadCast();
			if (this->world->selectObject)
			{
				if (!this->container->barInfo->isVisible())
				{
					this->container->barInfo->setVisible(true);
				}
				this->barInfoView();
			}
			else if (this->container->barInfo->isVisible())
			{
				this->container->barInfo->setVisible( false);
			}
			this->newEnemyUpdate();
			if (this->container->fireBacklight->isVisible())
			{
				if (this->container->fireBacklight->currentFrame > 1)
				{
					if (this->container->fireBacklight->currentFrame < this->container->fireBacklight->totalFrames)
					{
						this->container->fireBacklight->gotoAndStop((this->container->fireBacklight->currentFrame + 1));
					}
					else if (!this->container->fireBacklight->turnFlag)
					{
						this->container->fireBacklight->turnFlag = true;
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
						this->container->iceBacklight->gotoAndStop((this->container->iceBacklight->currentFrame + 1));
					}
					else if (!this->container->iceBacklight->turnFlag)
					{
						this->container->iceBacklight->turnFlag = true;
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
						this->container->stoneBacklight->gotoAndStop((this->container->stoneBacklight->currentFrame + 1));
					}
					else if (!this->container->stoneBacklight->turnFlag)
					{
						this->container->stoneBacklight->turnFlag = true;
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
						this->container->levinBacklight->gotoAndStop((this->container->levinBacklight->currentFrame + 1));
					}
					else if (!this->container->levinBacklight->turnFlag)
					{
						this->container->levinBacklight->turnFlag = true;
						this->container->levinBacklight->gotoAndStop(2);
					}
				}
			}
			this->hintUpdate();
			if (this->container->fireBack->currentFrame == 2)
			{
				if (this->container->fireBack->cont->currentFrame < this->container->fireBack->cont->totalFrames)
				{
					this->container->fireBack->cont->gotoAndStop(this->container->fireBack->cont->currentFrame + 2);
				}
				else
				{
					this->container->fireBack->cont->gotoAndStop(1);
				}
			}
			else if (this->container->iceBack->currentFrame == 2)
			{
				if (this->container->iceBack->cont->currentFrame < this->container->iceBack->cont->totalFrames)
				{
					this->container->iceBack->cont->gotoAndStop(this->container->iceBack->cont->currentFrame + 2);
				}
				else
				{
					this->container->iceBack->cont->gotoAndStop(1);
				}
			}
			else if (this->container->stoneBack->currentFrame == 2)
			{
				if (this->container->stoneBack->cont->currentFrame < this->container->stoneBack->cont->totalFrames)
				{
					this->container->stoneBack->cont->gotoAndStop(this->container->stoneBack->cont->currentFrame + 2);
				}
				else
				{
					this->container->stoneBack->cont->gotoAndStop(1);
				}
			}
			else if (this->container->levinBack->currentFrame == 2)
			{
				if (this->container->levinBack->cont->currentFrame < this->container->levinBack->cont->totalFrames)
				{
					this->container->levinBack->cont->gotoAndStop(this->container->levinBack->cont->currentFrame + 2);
				}
				else
				{
					this->container->levinBack->cont->gotoAndStop(1);
				}
			}
			if (this->listOfGetAhieve.size() > 0)
			{
				this->i = this->listOfGetAhieve.size() - 1;
				while (this->i >= 0)
				{ 
					if (!this->listOfGetAhieve[this->i].closeFlag)
					{
						if (this->listOfGetAhieve[this->i]->currentFrame < this->listOfGetAhieve[this->i]->totalFrames)
						{
							this->listOfGetAhieve[this->i]->gotoAndStop((this->listOfGetAhieve[this->i]->currentFrame + 1));
							std::setText(this->listOfGetAhieve[this->i].board->noteTXT , this->listOfGetAhieve[this->i].myText );
						}
						else if (this->listOfGetAhieve[this->i].counter > 0)
						{
							(this->listOfGetAhieve[this->i].counter - 1);
						}
						else
						{
							this->listOfGetAhieve[this->i].closeFlag = true;
						}
						this->listOfGetAhieve[this->i].y = this->container->barInfo->y - 42;
					}
					else if (this->listOfGetAhieve[this->i]->currentFrame > 1)
					{
						this->listOfGetAhieve[this->i]->gotoAndStop((this->listOfGetAhieve[this->i]->currentFrame - 1));
						std::setText(this->listOfGetAhieve[this->i].board->noteTXT , this->listOfGetAhieve[this->i].myText );
					}
					else
					{
						this->removeChild(this->listOfGetAhieve[this->i]);
						this->listOfGetAhieve.splice(this->i, 1);
					}
					i++;
				}
			}
			if (this->listOfAnimation.size() > 0)
			{
				this->i = this->listOfAnimation.size() - 1;
				while (this->i >= 0)
				{
					if (this->listOfAnimation[this->i]->currentFrame < this->listOfAnimation[this->i]->totalFrames)
					{
						this->listOfAnimation[this->i]->gotoAndStop((this->listOfAnimation[this->i]->currentFrame + 1));
					}
					else
					{
						this->removeChild(this->listOfAnimation[this->i]);
						this->listOfAnimation.splice(this->i, 1);
					}
					i++;
				}
			}
		}
		else if (this->alpha < 1)
		{
			this->alpha = this->alpha + 0.2;
		}
		else
		{
			var _loc_1 : *= true;
			this->mouseChildren = true;
			this->mouseEnabled = _loc_1;
			this->alpha = 1;
		}
		return;
	};

    void WorldInterface::mouseMoveHandler(cocos2d::Event *param1)//MouseEvent
	{
		if (!this->world->getSphere && !this->world->cast && !this->world->exchange)
		{
			if (param1->target->name == "sphereCase")
			{
				if (param1->target->parent->name == "fireSphere")
				{
					if (param1->target->buttonMode && this->container->fireBack->currentFrame == 1)
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
						this->container->fireBack->cont->stop();
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
				}
				else if (param1->target->parent->name == "iceSphere")
				{
					if (param1->target->buttonMode && this->container->iceBack->currentFrame == 1)
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
						this->container->iceBack->cont->stop();
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
				}
				else if (param1->target->parent->name == "stoneSphere")
				{
					if (param1->target->buttonMode && this->container->stoneBack->currentFrame == 1)
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
						this->container->stoneBack->cont->stop();
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
				}
				else if (param1->target->parent->name == "levinSphere")
				{
					if (param1->target->buttonMode && this->container->levinBack->currentFrame == 1)
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
						this->container->levinBack->cont->stop();
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
				}
				else if (param1->target->parent->name == "getAll")
				{
					if (param1->target->buttonMode && this->container->getAll->currentFrame == 1)
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
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
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
								this->getAllHint->mouseChildren = false;
								this->getAllHint->mouseEnabled = false;
								this->addChildAt(this->getAllHint, 1);
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
			if (param1->target->name == "slow")
			{
				if (this->container->slow->currentFrame == 1)
				{
					this->container->slow->gotoAndStop(2);
					//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
				}
			}
			else if (this->container->slow->currentFrame == 2)
			{
				this->container->slow->gotoAndStop(1);
			}
			if (param1->target->name == "fastCase")
			{
				if (param1->target->buttonMode)
				{
					if (this->container->fast->currentFrame == 1 || this->container->fast->currentFrame == 4)
					{
						if (this->container->fast->currentFrame == 4)
						{
							tempObject = this->container->fast->cont->currentFrame;
						}
						this->container->fast->gotoAndStop((this->container->fast->currentFrame + 1));
						if (this->container->fast->currentFrame == 5)
						{
							this->container->fast->cont->gotoAndStop(tempObject);
						}
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
				}
			}
			else if (this->container->fast->currentFrame == 2 || this->container->fast->currentFrame == 5)
			{
				if (this->container->fast->currentFrame == 5)
				{
					tempObject = this->container->fast->cont->currentFrame;
				}
				this->container->fast->gotoAndStop((this->container->fast->currentFrame - 1));
				if (this->container->fast->currentFrame == 4)
				{
					this->container->fast->cont->gotoAndStop(tempObject);
				}
			}
			if (param1->target->name == "traceBezier")
			{
				if (this->container->traceBezier->currentFrame == 1)
				{
					this->container->traceBezier->gotoAndStop(2);
				}
			}
			else if (this->container->traceBezier->currentFrame == 2)
			{
				this->container->traceBezier->gotoAndStop(1);
			}
			if (param1->target->name == "pauseCase")
			{
				if (this->container->pause->currentFrame == 1)
				{
					this->container->pause->gotoAndStop(2);
					this->container->pause->openFlag = true;
					this->container->pause->closeFlag = false;
					//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
				}
			}
			else if (this->container->pause->currentFrame > 1)
			{
				if (this->container->pause->currentFrame == this->container->pause->totalFrames)
				{
					this->container->pause->gotoAndStop(this->container->pause->totalFrames);
				}
				if (this->container->pause->openFlag)
				{
					this->container->pause->openFlag = false;
				}
				if (!this->container->pause->closeFlag)
				{
					this->container->pause->closeFlag = true;
				}
			}
			if (param1->target->name == "bookCase")
			{
				if (this->container->book->currentFrame == 1)
				{
					this->container->book->gotoAndStop(2);
					this->container->book->openFlag = true;
					this->container->book->closeFlag = false;
					//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
				}
			}
			else if (this->container->book->currentFrame > 1)
			{
				if (this->container->book->currentFrame == this->container->book->totalFrames)
				{
					this->container->book->gotoAndStop(this->container->book->totalFrames);
				}
				if (this->container->book->openFlag)
				{
					this->container->book->openFlag = false;
				}
				if (!this->container->book->closeFlag)
				{
					this->container->book->closeFlag = true;
				}
			}
			if (param1->target->name == "startWavesCase")
			{
				if (this->container->startWaves->startWavesCase->buttonMode)
				{
					if (this->container->startWaves->currentFrame <= 10)
					{
						this->container->startWaves->gotoAndStop(this->container->startWaves->currentFrame + 10);
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
				}
			}
			else if (this->container->startWaves->startWavesCase->buttonMode)
			{
				if (this->container->startWaves->currentFrame > 10)
				{
					this->container->startWaves->gotoAndStop(this->container->startWaves->currentFrame - 10);
				}
			}
			if (param1->target->name == "castGolemCase")
			{
				if (param1->target->parent->isVisible())
				{
					if (this->container->butCastGolem->currentFrame == 1)
					{
						this->container->butCastGolem->gotoAndStop(2);
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
						if (!this->world->hint->isVisible())
						{
							this->world->hint->setVisible(true);
						}
						if (this->world->hint->currentFrame != 1)
						{
							this->world->hint->gotoAndStop(1);
						}
						if (std::getText(this->world->hint->nameTXT) != "击碎者就绪!")
						{
							std::setText(this->world->hint->nameTXT,"击碎者就绪!") ;
							std::setText(this->world->hint->noteTXT , "一路碾压所有敌人" );
							this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
							std::setText(this->world->hint->timeTXT , int(this->castGolemTimer / 30) );
							this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
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
						if (std::getText(this->world->hint->nameTXT) != "击碎者重置")
						{
							std::setText(this->world->hint->nameTXT, "击碎者重置") ;
							std::setText(this->world->hint->noteTXT , "一路碾压所有敌人" );
							this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
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
					if (std::getText(this->world->hint->nameTXT) == "击碎者重置" || std::getText(this->world->hint->nameTXT) == "击碎者就绪!")
					{
						this->world->hint->setVisible( false);
					}
				}
			}
			if (param1->target->name == "castIcemanCase")
			{
				if (param1->target->parent->isVisible())
				{
					if (this->container->butCastIceman->currentFrame == 1)
					{
						this->container->butCastIceman->gotoAndStop(2);
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
						if (!this->world->hint->isVisible())
						{
							this->world->hint->setVisible(true);
						}
						if (this->world->hint->currentFrame != 1)
						{
							this->world->hint->gotoAndStop(1);
						}
						if (std::getText(this->world->hint->nameTXT) != "冰冻者就绪!")
						{
							std::setText(this->world->hint->nameTXT,"冰冻者就绪!");
							std::setText(this->world->hint->noteTXT , "一路冻结所有敌人" );
							this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
							std::setText(this->world->hint->timeTXT , int(this->castIcemanTimer / 30) );
							this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
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
						if (std::getText(this->world->hint->nameTXT) != "冰冻者重置")
						{
							std::setText(this->world->hint->nameTXT , "冰冻者重置" );
							std::setText(this->world->hint->noteTXT , "一路冻结所有敌人" );
							this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
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
					if (std::getText(this->world->hint->nameTXT) == "冰冻者重置" || std::getText(this->world->hint->nameTXT) == "冰冻者就绪!")
					{
						this->world->hint->setVisible( false);
					}
				}
			}
			if (param1->target->name == "castAirCase")
			{
				if (param1->target->parent->isVisible())
				{
					if (this->container->butCastAir->currentFrame == 1)
					{
						this->container->butCastAir->gotoAndStop(2);
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
						if (!this->world->hint->isVisible())
						{
							this->world->hint->setVisible(true);
						}
						if (this->world->hint->currentFrame != 1)
						{
							this->world->hint->gotoAndStop(1);
						}
						if (std::getText(this->world->hint->nameTXT) != "复活岛巨像就绪!")
						{
							std::setText(this->world->hint->nameTXT , "复活岛巨像就绪!" );
							std::setText(this->world->hint->noteTXT , "将敌人吹飞到后面" );
							this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
							std::setText(this->world->hint->timeTXT , int(this->castAirTimer / 30) );
							this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
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
						if (std::getText(this->world->hint->nameTXT) != "复活岛巨像重置")
						{
							std::setText(this->world->hint->nameTXT , "复活岛巨像重置" );
							std::setText(this->world->hint->noteTXT , "将敌人吹飞到后面" );
							this->world->hint->nameTXT.setTextFormat(Main::mainClass->boldTextFormat);
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
					if (std::getText(this->world->hint->nameTXT) == "复活岛巨像重置" || std::getText(this->world->hint->nameTXT) == "复活岛巨像就绪!")
					{
						this->world->hint->setVisible( false);
					}
				}
			}
			if (param1->target->name == "pointerCase")
			{
				if (!param1->target->parent.mouseFlag)
				{
					this->world->pointer1.mouseFlag = true;
					if (this->world->pointer2)
					{
						this->world->pointer2.mouseFlag = true;
					}
					if (this->world->pointer3)
					{
						this->world->pointer3.mouseFlag = true;
					}
					//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
				}
			}
			else
			{
				if (this->world->pointer1.mouseFlag)
				{
					this->world->pointer1.mouseFlag = false;
				}
				if (this->world->pointer2)
				{
					if (this->world->pointer2.mouseFlag)
					{
						this->world->pointer2.mouseFlag = false;
					}
				}
				if (this->world->pointer3)
				{
					if (this->world->pointer3.mouseFlag)
					{
						this->world->pointer3.mouseFlag = false;
					}
				}
			}
			if (param1->target->name == "newEnemyCase" || param1->target->name == "newElementCase")
			{
				tempObject = param1->target->parent;
				if (tempObject->mouseStatus == 1)
				{
					tempObject->mouseStatus = 2;
					var _loc_2 : *= 1.1;
					tempObject->setScaleY( 1.1);
					tempObject->setScaleX( _loc_2);
					//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
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
						this->listOfNewEnemies[this->i]->setScaleY( 1);
						this->listOfNewEnemies[this->i]->setScaleX( 1);
					}
					i++;
				}
			}
			if (param1->target->name == "testRestart")
			{
				if (this->container->testRestart->currentFrame == 1)
				{
					this->container->testRestart->gotoAndStop(2);
				}
			}
			else if (this->container->testRestart->currentFrame == 2)
			{
				this->container->testRestart->gotoAndStop(1);
			}
			if (param1->target->name == "sellCase")
			{
				if (!this->sellHint)
				{
					this->sellHint = new Hint_mc();
					this->sellHint->gotoAndStop(14);
					this->sellHint.x = 645;
					this->sellHint.y = 50;
					var _loc_2 : *= 0.7;
					this->sellHint->setScaleY( 0.7);
					this->sellHint->setScaleX( _loc_2);
					var _loc_2 : *= false;
					this->sellHint->mouseChildren = false;
					this->sellHint->mouseEnabled = _loc_2;
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
	
	void WorldInterface::mouseDownHandler(cocos2d::Event *event)//(event:MouseEvent) : void
	{
        cocos2d::EventMouse*e = (cocos2d::EventMouse*)event;
        Node * node=event->getCurrentTarget();
        Event::Type tp=event->getType();
        string target = node->getName();
        CCLOG("WorldInterface::mouseDownHandler %s", target.c_str());
         

       cocos2d::Point pt = e->getLocationInView();
        CCLOG("mouse InView point %f,%f", pt.x, pt.y);
        cocos2d::Point  nsp = node->convertToNodeSpaceAR(pt);
        CCLOG("mouse ToNodeSpaceAR point %f,%f", nsp.x, nsp.y);
        nsp = node->convertToNodeSpace(pt);
        CCLOG("mouse ToNodeSpace point %f,%f", nsp.x, nsp.y);

        nsp = this->world->pointer1->convertToNodeSpaceAR(pt);
        CCLOG("pointer1 ToNodeSpace point %f,%f", nsp.x, nsp.y);

        Rect bb;
        bb.size = this->world->pointer1->point->getContentSize();
        if (bb->containsPoint(nsp))
        {
            CCLOG("WorldInterface::containsPoint %s", target.c_str());
        }
		this->world->wavesClass->startWaves();

		if (!this->world->getSphere && !this->world->cast)
		{
			if (event->target->name == "slow")
			{
				if (this->container->slow->currentFrame == 2)
				{
					this->container->slow->gotoAndStop(3);
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
				}
			}
			else if (event->target->name == "fastCase")
			{
				if (event->target->buttonMode)
				{
					if (this->container->fast->currentFrame == 2 || this->container->fast->currentFrame == 5)
					{
						this->container->fast->gotoAndStop((this->container->fast->currentFrame + 1));
						//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
					}
				}
			}
			else if (event->target->name == "traceBezier")
			{
				if (this->container->traceBezier->currentFrame == 2)
				{
					this->container->traceBezier->gotoAndStop(3);
				}
			}
			else if (event->target->name == "pauseCase")
			{
				if (this->container->pause->currentFrame != this->container->pause->totalFrames)
				{
					this->container->pause->gotoAndStop(this->container->pause->totalFrames);
					this->container->pause->openFlag = false;
					this->container->pause->closeFlag = false;
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
				}
			}
			else if (event->target->name == "bookCase")
			{
				if (this->container->book->currentFrame != this->container->book->totalFrames)
				{
					this->container->book->gotoAndStop(this->container->book->totalFrames);
					this->container->book->openFlag = false;
					this->container->book->closeFlag = false;
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
				}
			}
			else if (event->target->name == "sphereCase")
			{
				if (event->target->buttonMode)
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
					if (event->target->parent->name == "fireSphere")
					{
						if (this->fireCount == 0)
						{
							this->archiveManage("buy", "fire");
						}
						//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
						this->archiveManage("get", "fire");
					}
					else if (event->target->parent->name == "iceSphere")
					{
						if (this->iceCount == 0)
						{
							this->archiveManage("buy", "ice");
						}
						//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
						this->archiveManage("get", "ice");
					}
					else if (event->target->parent->name == "stoneSphere")
					{
						if (this->stoneCount == 0)
						{
							this->archiveManage("buy", "stone");
						}
						//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
						this->archiveManage("get", "stone");
					}
					else if (event->target->parent->name == "levinSphere")
					{
						if (this->levinCount == 0)
						{
							this->archiveManage("buy", "levin");
						}
						//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
						this->archiveManage("get", "levin");
					}
					else if (event->target->parent->name == "getAll")
					{
						if (this->getAllCount == 0)
						{
							this->archiveManage("buy", "getAll");
						}
						//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
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
			else if (event->target->name == "startWavesCase")
			{
				if (this->container->startWaves->startWavesCase->buttonMode)
				{
					this->world->wavesClass->startWaves();
				}
			}
			else if (event->target->name == "castGolemCase")
			{
				if (this->container->butCastGolem->currentFrame == 2)
				{
					this->container->butCastGolem->gotoAndStop(3);
					this->castGolem();
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
				}
			}
			else if (event->target->name == "castIcemanCase")
			{
				if (this->container->butCastIceman->currentFrame == 2)
				{
					this->container->butCastIceman->gotoAndStop(3);
					this->castIceman();
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
				}
			}
			else if (event->target->name == "castAirCase")
			{
				if (this->container->butCastAir->currentFrame == 2)
				{
					this->container->butCastAir->gotoAndStop(3);
					this->castAir();
					//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
				}
			}
			else if (event->target->name == "pointerCase")
			{
				this->world->wavesClass->startWaves();
			}
			else if (event->target->name == "newEnemyCase" || event->target->name == "newElementCase")
			{
				tempObject = event->target->parent;
				tempObject->mouseStatus = 3; 
				tempObject->mouseChildren = false;
				tempObject->mouseEnabled = false;
				//Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
			}
			else if (event->target->name == "testRestart")
			{
				if (this->container->testRestart->currentFrame == 2)
				{
					this->container->testRestart->gotoAndStop(3);
				}
			}
		}
	}

    void WorldInterface::mouseUpHandler(cocos2d::Event *event)//(event:MouseEvent) : void
	{
		if (!this->world->getSphere && !this->world->cast)
		{
			if (event->target->name == "slow")
			{
				if (this->container->slow->currentFrame == 3)
				{
					if (this->fasterFlag != 1)
					{
						this->fastPlayControl(1);
						if (this->container->fast->currentFrame != 1)
						{
							this->container->fast->gotoAndStop(1);
						}
					}
					else
					{
						this->fastPlayControl(0);
						this->container->slow->gotoAndStop(2);
					}
				}
			}
			else if (this->container->slow->currentFrame == 3)
			{
				if (this->fasterFlag != 1)
				{
					this->container->slow->gotoAndStop(1);
				}
			}
			if (event->target->name == "fastCase")
			{
				if (event->target->buttonMode)
				{
					if (this->container->fast->currentFrame == 3 || this->container->fast->currentFrame == 6)
					{
						this->fasterManage(true);
					}
				}
			}
			else if (this->container->fast->currentFrame == 3 || this->container->fast->currentFrame == 6)
			{
				this->container->fast->gotoAndStop(this->container->fast->currentFrame - 2);
				if (this->container->fast->currentFrame == 4)
				{
					this->container->fast->cont->stop();
				}
			}
			if (event->target->name == "traceBezier")
			{
				if (this->container->traceBezier->currentFrame == 3)
				{
					this->container->traceBezier->gotoAndStop(2);
				}
			}
			else if (this->container->traceBezier->currentFrame == 3)
			{
				this->container->traceBezier->gotoAndStop(1);
			}
			if (event->target->name == "pauseCase")
			{
				if (this->container->pause->currentFrame == this->container->pause->totalFrames)
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
				if (this->container->pause->opneFlag)
				{
					this->container->pause->opneFlag = false;
				}
				if (!this->container->pause->closeFlag)
				{
					this->container->pause->closeFlag = true;
				}
			}
			if (event->target->name == "bookCase")
			{
				if (this->container->book->currentFrame == this->container->book->totalFrames)
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
				if (this->container->book->opneFlag)
				{
					this->container->book->opneFlag = false;
				}
				if (!this->container->book->closeFlag)
				{
					this->container->book->closeFlag = true;
				}
			}
			if (event->target->name == "testRestart")
			{
				if (this->container->testRestart->currentFrame == 3)
				{
					this->container->testRestart->gotoAndStop(2);
					if (std::getText(this->container->testRestartBoard->waveTXT) == "")
					{
						Main::mainClass->testingClass->loadWave = Main::mainClass->worldClass->wavesClass.nowWave;
					}
					else if (std::getInt(this->container->testRestartBoard->waveTXT) < Main::mainClass->testingClass->listOfStory.size())
					{
						Main::mainClass->testingClass->loadWave = std::getInt(this->container->testRestartBoard->waveTXT);
					}
					else
					{
						Main::mainClass->testingClass->loadWave = 0;
					}
					Main::mainClass->addNewScreen("World");
				}
			}
			else if (this->container->testRestart->currentFrame == 3)
			{
				this->container->testRestart->gotoAndStop(1);
			}
		}
	}// end function
	
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
		this->world->addChild(this->world->cast);
		//this->world->listOfClasses.push(this->world->cast);
	}// end function

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
        ////
        //int firePrice = Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory];
        //this->container->firePrice->setText(itoa(firePrice, tmp, 10));
        //int icePrice = Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory];
        //this->container->icePrice->setText(itoa(icePrice, tmp, 10));
        //int stonePrice = Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory];
        //this->container->stonePrice->setText(itoa(stonePrice, tmp, 10));
        //int levinPrice = Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
        //this->container->levinPrice->setText(itoa(levinPrice, tmp, 10));
        // 
        //int allPrice = Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory] + Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory] + Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory] + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
        //this->container->getAllPrice->setText(itoa(allPrice, tmp, 10));
        //cocos2d::Point bp= this->container->buyFire->getPosition();
        //if (firePrice < 10)
        //    this->container->firePrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
		//else
        //     this->container->firePrice->setPosition(Vec2(bp.x + 18, bp.y + 9));
        //
        //bp = this->container->buyIce->getPosition();
        //if (icePrice < 10)
        //    this->container->icePrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
		//else
        //    this->container->icePrice->setPosition(Vec2(bp.x + 18, bp.y + 9));
        //bp = this->container->buyStone->getPosition();
        //if (stonePrice < 10)
        //    this->container->stonePrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
        //else
        //    this->container->stonePrice->setPosition(Vec2(bp.x + 18, bp.y + 9));
        //bp = this->container->buyLevin->getPosition();
        //if (levinPrice < 10)
        //    this->container->levinPrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
        //else
        //    this->container->levinPrice->setPosition(Vec2(bp.x + 18, bp.y + 9));
        //bp = this->container->buyGetAll->getPosition();
        //if (allPrice < 10)
        //    this->container->getAllPrice->setPosition(Vec2(bp.x + 21, bp.y + 9));
        //else if (allPrice < 100)
        //    this->container->getAllPrice->setPosition(Vec2(bp.x + 18, bp.y + 9));
        //else
        //    this->container->getAllPrice->setPosition(Vec2(bp.x + 16, bp.y + 9));
			
		this->container->buyFire->buyTXT.text = Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory];
        this->container->buyIce->buyTXT.text = Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory];
        this->container->buyStone->buyTXT.text = Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory];
        this->container->buyLevin->buyTXT.text = Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
        this->container->buyGetAll->buyTXT.text = Main::mainClass->readXMLClass.listOfFirePriceXML[this->fireBuyHistory] + Main::mainClass->readXMLClass.listOfIcePriceXML[this->iceBuyHistory] + Main::mainClass->readXMLClass.listOfStonePriceXML[this->stoneBuyHistory] + Main::mainClass->readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
		if (std::getInt(this->container->buyFire->buyTXT) < 10)
        {
            this->container->buyFire->coin->setPositionX(-5.75);
            this->container->buyFire->coin->setPositionY(13.15);
        }
        else
        {
            this->container->buyFire->coin->setPositionX(-9.25);
            this->container->buyFire->coin->setPositionY(13.15);
        }
        if (std::getInt(this->container->buyIce->buyTXT) < 10)
        {
            this->container->buyIce->coin->setPositionX(-5.75);
            this->container->buyIce->coin->setPositionY(13.15);
        }
        else
        {
            this->container->buyIce->coin->setPositionX(-9.25);
            this->container->buyIce->coin->setPositionY(13.15);
        }
        if (std::getInt(this->container->buyStone->buyTXT) < 10)
        {
            this->container->buyStone->coin->setPositionX(-5.75);
            this->container->buyStone->coin->setPositionY(13.15);
        }
        else
        {
            this->container->buyStone->coin->setPositionX(-9.25);
            this->container->buyStone->coin->setPositionY(13.15);
        }
        if (std::getInt(this->container->buyLevin->buyTXT) < 10)
        {
            this->container->buyLevin->coin->setPositionX(-5.75);
            this->container->buyLevin->coin->setPositionY(13.15);
        }
        else
        {
            this->container->buyLevin->coin->setPositionX(-9.25);
            this->container->buyLevin->coin->setPositionY(13.15);
        }
        if (std::getInt(this->container->buyGetAll->buyTXT) < 10)
        {
            this->container->buyGetAll->coin->setPositionX(-8.6);
            this->container->buyGetAll->coin->setPositionY(13.15);
        }
        else if (std::getInt(this->container->buyGetAll->buyTXT) < 100)
        {
            this->container->buyGetAll->coin->setPositionX(-11);
            this->container->buyGetAll->coin->setPositionY(13.15);
        }
        else
        {
            this->container->buyGetAll->coin->setPositionX(-14.2);
            this->container->buyGetAll->coin->setPositionY(13.15);
        }

        if (this->container->fireSphere->isVisible() && (this->fireCount > 0 || this->world->money >= firePrice ))
		{
		    if (!this->container->fireSphere->sphereCase->buttonMode)
		    {
		        this->container->fireSphere->sphereCase->buttonMode = true;
		        this->container->fireSphere->alpha = 1;
		    }
            if (this->world->money >= firePrice)
		    {
		        if (this->container->buyFire->currentFrame == 2)
		        {
		            this->container->buyFire->myCost = std::getInt(this->container->buyFire->buyTXT);
		            this->container->buyFire->coin->myPoint = new Point(this->container->buyFire->coin->x, this->container->buyFire->coin->y);
		            this->container->buyFire->gotoAndStop(1);
		            std::setText(this->container->buyFire->buyTXT , this->container->buyFire->myCost );
		            this->container->buyFire->coin->gotoAndStop(1);
		            this->container->buyFire->coin->setPosition(this->container->buyFire->coin->myPoint);
		        }
		    }
		    else if (this->container->buyFire->currentFrame == 1)
		    {
		        this->container->buyFire->myCost = std::getInt(this->container->buyFire->buyTXT);
		        this->container->buyFire->coin->myPoint = new Point(this->container->buyFire->coin->x, this->container->buyFire->coin->y);
		        this->container->buyFire->gotoAndStop(2);
		        std::setText(this->container->buyFire->buyTXT , this->container->buyFire->myCost );
		        this->container->buyFire->coin->gotoAndStop(2);
		        this->container->buyFire->coin->setPosition(this->container->buyFire->coin->myPoint); 
		        this->container->buyFire->coin->setScaleY(0.8);
		        this->container->buyFire->coin->setScaleX(0.8);
		    }

		    if (this->container->fireSphere->sphereCase->buttonMode)
		    {
		        if (!this->world->getSphere)
		        {
		            if (this->world->towerMenu)
		            {
		                if (this->world->towerMenu->myTower->spheresManage("scan") > 0)
		                {
		                    if (!this->container->buyFire->lightUp->isVisible())
		                    {
		                        this->container->buyFire->lightUp->setVisible(true);
		                    }
		                }
		                else if (this->container->buyFire->lightUp->isVisible())
		                {
		                    this->container->buyFire->lightUp->setVisible( false);
		                }
		            }
		            else if (this->world->ultraTowerMenu)
		            {
		                if (this->world->ultraTowerMenu->myTower->towerType == 5 && Main::mainClass->readXMLClass.ultraTower1UpgrBlock == 0)
		                {
		                    if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[0])
		                    {
		                        if (!this->container->buyFire->lightUp->isVisible())
		                        {
		                            this->container->buyFire->lightUp->setVisible(true);
		                        }
		                    }
		                    else if (this->container->buyFire->lightUp->isVisible())
		                    {
		                        this->container->buyFire->lightUp->setVisible( false);
		                    }
		                }
		                else if (this->world->ultraTowerMenu->myTower->towerType == 8 && Main::mainClass->readXMLClass.ultraTower4UpgrBlock == 0)
		                {
		                    if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[0])
		                    {
		                        if (!this->container->buyFire->lightUp->isVisible())
		                        {
		                            this->container->buyFire->lightUp->setVisible(true);
		                        }
		                    }
		                    else if (this->container->buyFire->lightUp->isVisible())
		                    {
		                        this->container->buyFire->lightUp->setVisible( false);
		                    }
		                }
		            }
		            else if (this->container->buyFire->lightUp->isVisible())
		            {
		                this->container->buyFire->lightUp->setVisible( false);
		            }
		        }
		        else if (this->container->buyFire->lightUp->isVisible())
		        {
		            this->container->buyFire->lightUp->setVisible( false);
		        }
		    }
		}
		else
		{
		    if (this->container->fireSphere->sphereCase->buttonMode)
		    {
		        this->container->fireSphere->sphereCase->buttonMode = false;
		        this->container->fireBack->gotoAndStop(1);
		        if (this->container->buyFire->lightUp->isVisible())
		        {
		            this->container->buyFire->lightUp->setVisible( false);
		        }
		    }
		    if (this->container->buyFire->currentFrame == 1)
		    {
		        this->container->buyFire->myCost = std::getInt(this->container->buyFire->buyTXT);
		        this->container->buyFire->coin->myPoint = new Point(this->container->buyFire->coin->x, this->container->buyFire->coin->y);
		        this->container->buyFire->gotoAndStop(2);
		        std::setText(this->container->buyFire->buyTXT , this->container->buyFire->myCost );
		        this->container->buyFire->coin->gotoAndStop(2);
		        this->container->buyFire->coin->setPosition(this->container->buyFire->coin->myPoint);
		        this->container->buyFire->coin->setScaleY(0.8);
		        this->container->buyFire->coin->setScaleX(0.8);
		    }
		    if (this->container->fireSphere->alpha != 0.5)
		    {
		        this->container->fireSphere->alpha = 0.5;
		    }
		}

		if (this->container->iceSphere->isVisible() && (this->iceCount > 0 || this->world->money >= std::getInt(this->container->buyIce->buyTXT)))
		{
		    if (!this->container->iceSphere->sphereCase->buttonMode)
		    {
		        this->container->iceSphere->sphereCase->buttonMode = true;
		        this->container->iceSphere->alpha = 1;
		    }
		    if (this->world->money >= std::getInt(this->container->buyIce->buyTXT))
		    {
		        if (this->container->buyIce->currentFrame == 2)
		        {
		            this->container->buyIce->myCost = std::getInt(this->container->buyIce->buyTXT);
		            this->container->buyIce->coin->myPoint = new Point(this->container->buyIce->coin->x, this->container->buyIce->coin->y);
		            this->container->buyIce->gotoAndStop(1);
		            std::setText(this->container->buyIce->buyTXT , this->container->buyIce->myCost );
		            this->container->buyIce->coin->gotoAndStop(1);
		            this->container->buyIce->coin->setPosition(this->container->buyIce->coin->myPoint);
		            this->container->buyIce->coin->setScaleY(1);
		            this->container->buyIce->coin->setScaleX(1);
		        }
		    }
		    else if (this->container->buyIce->currentFrame == 1)
		    {
		        this->container->buyIce->myCost = std::getInt(this->container->buyIce->buyTXT);
		        this->container->buyIce->coin->myPoint = new Point(this->container->buyIce->coin->x, this->container->buyIce->coin->y);
		        this->container->buyIce->gotoAndStop(2);
		        std::setText(this->container->buyIce->buyTXT , this->container->buyIce->myCost );
		        this->container->buyIce->coin->gotoAndStop(2);
		        this->container->buyIce->coin->setPosition(this->container->buyIce->coin->myPoint); 
		        this->container->buyIce->coin->setScaleY(0.8);
		        this->container->buyIce->coin->setScaleX(0.8);
		    }
		    if (this->container->iceSphere->sphereCase->buttonMode)
		    {
		        if (!this->world->getSphere)
		        {
		            if (this->world->towerMenu)
		            {
		                if (this->world->towerMenu->myTower->spheresManage("scan") > 0)
		                {
		                    if (!this->container->buyIce->lightUp->isVisible())
		                    {
		                        this->container->buyIce->lightUp->setVisible(true);
		                    }
		                }
		                else if (this->container->buyIce->lightUp->isVisible())
		                {
		                    this->container->buyIce->lightUp->setVisible( false);
		                }
		            }
		            else if (this->world->ultraTowerMenu)
		            {
		                if (this->world->ultraTowerMenu->myTower->towerType == 6 && Main::mainClass->readXMLClass.ultraTower2UpgrBlock == 0)
		                {
		                    if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[1])
		                    {
		                        if (!this->container->buyIce->lightUp->isVisible())
		                        {
		                            this->container->buyIce->lightUp->setVisible(true);
		                        }
		                    }
		                    else if (this->container->buyIce->lightUp->isVisible())
		                    {
		                        this->container->buyIce->lightUp->setVisible( false);
		                    }
		                }
		                else if (this->world->ultraTowerMenu->myTower->towerType == 7 && Main::mainClass->readXMLClass.ultraTower3UpgrBlock == 0)
		                {
		                    if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[1])
		                    {
		                        if (!this->container->buyIce->lightUp->isVisible())
		                        {
		                            this->container->buyIce->lightUp->setVisible(true);
		                        }
		                    }
		                    else if (this->container->buyIce->lightUp->isVisible())
		                    {
		                        this->container->buyIce->lightUp->setVisible( false);
		                    }
		                }
		            }
		            else if (this->container->buyIce->lightUp->isVisible())
		            {
		                this->container->buyIce->lightUp->setVisible( false);
		            }
		        }
		        else if (this->container->buyIce->lightUp->isVisible())
		        {
		            this->container->buyIce->lightUp->setVisible( false);
		        }
		    }
		}
		else
		{
		    if (this->container->iceSphere->sphereCase->buttonMode)
		    {
		        this->container->iceSphere->sphereCase->buttonMode = false;
		        this->container->iceBack->gotoAndStop(1);
		        if (this->container->buyIce->lightUp->isVisible())
		        {
		            this->container->buyIce->lightUp->setVisible( false);
		        }
		    }
		    if (this->container->buyIce->currentFrame == 1)
		    {
		        this->container->buyIce->myCost = std::getInt(this->container->buyIce->buyTXT);
		        this->container->buyIce->coin->myPoint = new Point(this->container->buyIce->coin->x, this->container->buyIce->coin->y);
		        this->container->buyIce->gotoAndStop(2);
		        std::setText(this->container->buyIce->buyTXT , this->container->buyIce->myCost );
		        this->container->buyIce->coin->gotoAndStop(2);
		        this->container->buyIce->coin->setPosition(this->container->buyIce->coin->myPoint); 
		        this->container->buyIce->coin->setScaleY(0.8);
		        this->container->buyIce->coin->setScaleX(0.8);
		    }
		    if (this->container->iceSphere->alpha != 0.5)
		    {
		        this->container->iceSphere->alpha = 0.5;
		    }
		}

		if (this->container->stoneSphere->isVisible() && (this->stoneCount > 0 || this->world->money >= std::getInt(this->container->buyStone->buyTXT)))
		{
		    if (!this->container->stoneSphere->sphereCase->buttonMode)
		    {
		        this->container->stoneSphere->sphereCase->buttonMode = true;
		        this->container->stoneSphere->alpha = 1;
		    }
		    if (this->world->money >= std::getInt(this->container->buyStone->buyTXT))
		    {
		        if (this->container->buyStone->currentFrame == 2)
		        {
		            this->container->buyStone->myCost = std::getInt(this->container->buyStone->buyTXT);
		            this->container->buyStone->coin->myPoint = new Point(this->container->buyStone->coin->x, this->container->buyStone->coin->y);
		            this->container->buyStone->gotoAndStop(1);
		            std::setText(this->container->buyStone->buyTXT , this->container->buyStone->myCost );
		            this->container->buyStone->coin->gotoAndStop(1);
		            this->container->buyStone->coin->setPosition(this->container->buyStone->coin->myPoint);
		            this->container->buyStone->coin->setScaleY(1);
		            this->container->buyStone->coin->setScaleX(1);
		        }
		    }
		    else if (this->container->buyStone->currentFrame == 1)
		    {
		        this->container->buyStone->myCost = std::getInt(this->container->buyStone->buyTXT);
		        this->container->buyStone->coin->myPoint = new Point(this->container->buyStone->coin->x, this->container->buyStone->coin->y);
		        this->container->buyStone->gotoAndStop(2);
		        std::setText(this->container->buyStone->buyTXT , this->container->buyStone->myCost );
		        this->container->buyStone->coin->gotoAndStop(2);
		        this->container->buyStone->coin->setPosition(this->container->buyStone->coin->myPoint);
		        this->container->buyStone->coin->setScaleY(0.8);
		        this->container->buyStone->coin->setScaleX(0.8);
		    }
		    if (this->container->stoneSphere->sphereCase->buttonMode)
		    {
		        if (!this->world->getSphere)
		        {
		            if (this->world->towerMenu)
		            {
		                if (this->world->towerMenu->myTower->spheresManage("scan") > 0)
		                {
		                    if (!this->container->buyStone->lightUp->isVisible())
		                    {
		                        this->container->buyStone->lightUp->setVisible(true);
		                    }
		                }
		                else if (this->container->buyStone->lightUp->isVisible())
		                {
		                    this->container->buyStone->lightUp->setVisible( false);
		                }
		            }
		            else if (this->world->ultraTowerMenu)
		            {
		                if (this->world->ultraTowerMenu->myTower->towerType == 5 && Main::mainClass->readXMLClass.ultraTower1UpgrBlock == 0)
		                {
		                    if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[2])
		                    {
		                        if (!this->container->buyStone->lightUp->isVisible())
		                        {
		                            this->container->buyStone->lightUp->setVisible(true);
		                        }
		                    }
		                    else if (this->container->buyStone->lightUp->isVisible())
		                    {
		                        this->container->buyStone->lightUp->setVisible( false);
		                    }
		                }
		                else if (this->world->ultraTowerMenu->myTower->towerType == 7 && Main::mainClass->readXMLClass.ultraTower3UpgrBlock == 0)
		                {
		                    if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[2])
		                    {
		                        if (!this->container->buyStone->lightUp->isVisible())
		                        {
		                            this->container->buyStone->lightUp->setVisible(true);
		                        }
		                    }
		                    else if (this->container->buyStone->lightUp->isVisible())
		                    {
		                        this->container->buyStone->lightUp->setVisible( false);
		                    }
		                }
		            }
		            else if (this->container->buyStone->lightUp->isVisible())
		            {
		                this->container->buyStone->lightUp->setVisible( false);
		            }
		        }
		        else if (this->container->buyStone->lightUp->isVisible())
		        {
		            this->container->buyStone->lightUp->setVisible( false);
		        }
		    }
		}
		else
		{
		    if (this->container->stoneSphere->sphereCase->buttonMode)
		    {
		        this->container->stoneSphere->sphereCase->buttonMode = false;
		        this->container->stoneBack->gotoAndStop(1);
		        if (this->container->buyStone->lightUp->isVisible())
		        {
		            this->container->buyStone->lightUp->setVisible( false);
		        }
		    }
		    if (this->container->buyStone->currentFrame == 1)
		    {
		        this->container->buyStone->myCost = std::getInt(this->container->buyStone->buyTXT);
		        this->container->buyStone->coin->myPoint = new Point(this->container->buyStone->coin->x, this->container->buyStone->coin->y);
		        this->container->buyStone->gotoAndStop(2);
		        std::setText(this->container->buyStone->buyTXT , this->container->buyStone->myCost );
		        this->container->buyStone->coin->gotoAndStop(2);
		        this->container->buyStone->coin->setPosition(this->container->buyStone->coin->myPoint);
		        this->container->buyStone->coin->setScaleY(0.8);
		        this->container->buyStone->coin->setScaleX(0.8);
		    }
		    if (this->container->stoneSphere->alpha != 0.5)
		    {
		        this->container->stoneSphere->alpha = 0.5;
		    }
		}

		if (this->container->levinSphere->isVisible() && (this->levinCount > 0 || this->world->money >= std::getInt(this->container->buyLevin->buyTXT)))
		{
		    if (!this->container->levinSphere->sphereCase->buttonMode)
		    {
		        this->container->levinSphere->sphereCase->buttonMode = true;
		        this->container->levinSphere->alpha = 1;
		    }
		    if (this->world->money >= std::getInt(this->container->buyLevin->buyTXT))
		    {
		        if (this->container->buyLevin->currentFrame == 2)
		        {
		            this->container->buyLevin->myCost = std::getInt(this->container->buyLevin->buyTXT);
		            this->container->buyLevin->coin->myPoint = new Point(this->container->buyLevin->coin->x, this->container->buyLevin->coin->y);
		            this->container->buyLevin->gotoAndStop(1);
		            std::setText(this->container->buyLevin->buyTXT , this->container->buyLevin->myCost );
		            this->container->buyLevin->coin->gotoAndStop(1);
		            this->container->buyLevin->coin->setPosition(this->container->buyLevin->coin->myPoint);
		            this->container->buyLevin->coin->setScaleY(1);
		            this->container->buyLevin->coin->setScaleX(1);
		        }
		    }
		    else if (this->container->buyLevin->currentFrame == 1)
		    {
		        this->container->buyLevin->myCost = std::getInt(this->container->buyLevin->buyTXT);
		        this->container->buyLevin->coin->myPoint = new Point(this->container->buyLevin->coin->x, this->container->buyLevin->coin->y);
		        this->container->buyLevin->gotoAndStop(2);
		        std::setText(this->container->buyLevin->buyTXT , this->container->buyLevin->myCost );
		        this->container->buyLevin->coin->gotoAndStop(2);
		        this->container->buyLevin->coin->setPosition(this->container->buyLevin->coin->myPoint);
    	        this->container->buyLevin->coin->setScaleY(0.8);
		        this->container->buyLevin->coin->setScaleX(0.8);
		    }
		    if (this->container->levinSphere->sphereCase->buttonMode)
		    {
		        if (!this->world->getSphere)
		        {
		            if (this->world->towerMenu)
		            {
		                if (this->world->towerMenu->myTower->spheresManage("scan") > 0)
		                {
		                    if (!this->container->buyLevin->lightUp->isVisible())
		                    {
		                        this->container->buyLevin->lightUp->setVisible(true);
		                    }
		                }
		                else if (this->container->buyLevin->lightUp->isVisible())
		                {
		                    this->container->buyLevin->lightUp->setVisible( false);
		                }
		            }
		            else if (this->world->ultraTowerMenu)
		            {
		                if (this->world->ultraTowerMenu->myTower->towerType == 6 && Main::mainClass->readXMLClass.ultraTower2UpgrBlock == 0)
		                {
		                    if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[3])
		                    {
		                        if (!this->container->buyLevin->lightUp->isVisible())
		                        {
		                            this->container->buyLevin->lightUp->setVisible(true);
		                        }
		                    }
		                    else if (this->container->buyLevin->lightUp->isVisible())
		                    {
		                        this->container->buyLevin->lightUp->setVisible( false);
		                    }
		                }
		                else if (this->world->ultraTowerMenu->myTower->towerType == 8 && Main::mainClass->readXMLClass.ultraTower4UpgrBlock == 0)
		                {
		                    if (!this->world->ultraTowerMenu->myTower->shootingTurnStack[3])
		                    {
		                        if (!this->container->buyLevin->lightUp->isVisible())
		                        {
		                            this->container->buyLevin->lightUp->setVisible(true);
		                        }
		                    }
		                    else if (this->container->buyLevin->lightUp->isVisible())
		                    {
		                        this->container->buyLevin->lightUp->setVisible( false);
		                    }
		                }
		            }
		            else if (this->container->buyLevin->lightUp->isVisible())
		            {
		                this->container->buyLevin->lightUp->setVisible( false);
		            }
		        }
		        else if (this->container->buyLevin->lightUp->isVisible())
		        {
		            this->container->buyLevin->lightUp->setVisible( false);
		        }
		    }
		}
		else
		{
		    if (this->container->levinSphere->sphereCase->buttonMode)
		    {
		        this->container->levinSphere->sphereCase->buttonMode = false;
		        this->container->levinBack->gotoAndStop(1);
		        if (this->container->buyLevin->lightUp->isVisible())
		        {
		            this->container->buyLevin->lightUp->setVisible( false);
		        }
		    }
		    if (this->container->buyLevin->currentFrame == 1)
		    {
		        this->container->buyLevin->myCost = std::getInt(this->container->buyLevin->buyTXT);
		        this->container->buyLevin->coin->myPoint = new Point(this->container->buyLevin->coin->x, this->container->buyLevin->coin->y);
		        this->container->buyLevin->gotoAndStop(2);
		        std::setText(this->container->buyLevin->buyTXT , this->container->buyLevin->myCost );
		        this->container->buyLevin->coin->gotoAndStop(2);
		        this->container->buyLevin->coin->setPosition(this->container->buyLevin->coin->myPoint);
		        this->container->buyLevin->coin->setScaleY(0.8);
		        this->container->buyLevin->coin->setScaleX(0.8);
		    }
		    if (this->container->levinSphere->alpha != 0.5)
		    {
		        this->container->levinSphere->alpha = 0.5;
		    }
		}

		if (this->container->getAll->currentFrame < 3)
		{
		    if (this->container->getAll->isVisible() && (this->getAllCount > 0 || this->world->money >= std::getInt(this->container->buygetAll->buyTXT)))
		    {
		        if (!this->container->getAll->sphereCase->buttonMode)
		        {
		            this->container->getAll->sphereCase->buttonMode = true;
		            this->container->getAll->alpha = 1;
		        }
		        if (this->world->money >= std::getInt(this->container->buygetAll->buyTXT))
		        {
		            if (this->container->buygetAll->currentFrame == 2)
		            {
		                this->container->buygetAll->myCost = std::getInt(this->container->buygetAll->buyTXT);
		                this->container->buygetAll->coin->myPoint = new Point(this->container->buygetAll->coin->x, this->container->buygetAll->coin->y);
		                this->container->buygetAll->gotoAndStop(1);
		                std::setText(this->container->buygetAll->buyTXT , this->container->buygetAll->myCost );
		                this->container->buygetAll->coin->gotoAndStop(1);
		                this->container->buygetAll->coin->setPosition(this->container->buygetAll->coin->myPoint);
		                this->container->buygetAll->coin->setScaleY(1);
		                this->container->buygetAll->coin->setScaleX(1);
		            }
		        }
		        else if (this->container->buygetAll->currentFrame == 1)
		        {
		            this->container->buygetAll->myCost = std::getInt(this->container->buygetAll->buyTXT);
		            this->container->buygetAll->coin->myPoint = new Point(this->container->buygetAll->coin->x, this->container->buygetAll->coin->y);
		            this->container->buygetAll->gotoAndStop(2);
		            std::setText(this->container->buygetAll->buyTXT , this->container->buygetAll->myCost );
		            this->container->buygetAll->coin->gotoAndStop(2);
		            this->container->buygetAll->coin->setPosition(this->container->buygetAll->coin->myPoint);
		            this->container->buygetAll->coin->setScaleY(0.8);
		            this->container->buygetAll->coin->setScaleX(0.8);
		        }
		        if (this->container->getAll->sphereCase->buttonMode)
		        {
		            if (!this->world->getSphere)
		            {
		                if (this->world->towerMenu)
		                {
		                    if (this->world->towerMenu->myTower->spheresManage("scan") == 4)
		                    {
		                        if (!this->container->buygetAll->lightUp->isVisible())
		                        {
		                            this->container->buygetAll->lightUp->setVisible(true);
		                        }
		                    }
		                    else if (this->container->buygetAll->lightUp->isVisible())
		                    {
		                        this->container->buygetAll->lightUp->setVisible( false);
		                    }
		                }
		                else if (this->container->buygetAll->lightUp->isVisible())
		                {
		                    this->container->buygetAll->lightUp->setVisible( false);
		                }
		            }
		            else if (this->container->buygetAll->lightUp->isVisible())
		            {
		                this->container->buygetAll->lightUp->setVisible( false);
		            }
		        }
		    }
		    else
		    {
		        if (this->container->getAll->sphereCase->buttonMode)
		        {
		            this->container->getAll->sphereCase->buttonMode = false;
		            this->container->getAll->gotoAndStop(1);
		            if (this->container->buygetAll->lightUp->isVisible())
		            {
		                this->container->buygetAll->lightUp->setVisible( false);
		            }
		        }
		        if (this->container->buygetAll->currentFrame == 1)
		        {
		            this->container->buygetAll->myCost = std::getInt(this->container->buygetAll->buyTXT);
		            this->container->buygetAll->coin->myPoint = this->container->buygetAll->coin->getPosition();
		            this->container->buygetAll->gotoAndStop(2);
		            std::setText(this->container->buygetAll->buyTXT , this->container->buygetAll->myCost );
		            this->container->buygetAll->coin->gotoAndStop(2);
		            this->container->buygetAll->coin->setPosition(this->container->buygetAll->coin->myPoint);
		            this->container->buygetAll->coin->setScaleY(0.8);
		            this->container->buygetAll->coin->setScaleX(0.8);
		        }
		        if (this->container->getAll->alpha != 0.5)
		        {
		            this->container->getAll->alpha = 0.5;
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
                    this->fireCount++
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
                        this->world->getSphere->ownerPoint = this->container->fireSphere->myPoint;
                        this->world->addChild(this->world->getSphere);
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
                        this->world->getSphere->ownerPoint = this->container->iceSphere->myPoint;
                        this->world->addChild(this->world->getSphere);
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
                        this->world->getSphere->ownerPoint = this->container->stoneSphere->myPoint;
                        this->world->addChild(this->world->getSphere);
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
                        this->world->getSphere->ownerPoint = this->container->levinSphere->myPoint;
                        this->world->addChild(this->world->getSphere);
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
                        this->world->getSphere->ownerPoint = this->container->getAll->myPoint;
                        this->world->addChild(this->world->getSphere);
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
        //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
        this->castRegime("on");
        this->world->road->setVisible(false);
        this->addCast("golem");
    }// end function

    void WorldInterface::castIceman() 
    {
        this->container->butCastIceman->gotoAndStop(6);
        //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
        this->castRegime("on");
        this->world->road->setVisible(false);
        this->addCast("iceman");
    }// end function

    void WorldInterface::castAir() 
    {
        this->container->butCastAir->gotoAndStop(6);
        //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
        this->castRegime("on");
        this->world->road->setVisible(false);
        this->addCast("air");
    }// end function

    void WorldInterface::addPause() 
    {
        this->container->pause->gotoAndStop((this->container->pause->totalFrames - 1));
        this->container->pause->openFlag = false;
        this->container->pause->closeFlag = true;
        this->world->menuObject = new PauseMenu();
        this->world->addChild(this->world->menuObject);
    }// end function

    void WorldInterface::addFastPause()
    {
        //this->world->menuObject = new FastPause();
        //this->world->addChild(this->world->menuObject);
    }// end function

    void WorldInterface::addEncyclopedia() 
    {
        //this->world->menuObject = new Encyclopedia();
        //this->world->addChild(this->world->menuObject);
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
                this->container->butCastGolem->cont->contMask->setScaleY( this->castGolemCounter / this->castGolemTimer);
            }
            else
            {
                this->castGolemCounter = 0;
                this->container->butCastGolem->cont->contMask->setScaleY( 1);
                this->container->butCastGolem->gotoAndStop(1);
                this->container->butCastGolem->castGolemCase->buttonMode = true;
                this->autoguidersButtons();
                //Sounds.instance.playSound("snd_cast_ready");
            }
        }
        if (this->castIcemanCounter > 0)
        {
            if (this->castIcemanCounter < this->castIcemanTimer)
            {
                this->castIcemanCounter++;
                this->container->butCastIceman->cont->contMask->setScaleY( this->castIcemanCounter / this->castIcemanTimer);
            }
            else
            {
                this->castIcemanCounter = 0;
                this->container->butCastIceman->cont->contMask->setScaleY( 1);
                this->container->butCastIceman->gotoAndStop(1);
                this->container->butCastIceman->castIcemanCase->buttonMode = true;
                this->autoguidersButtons();
                //Sounds.instance.playSound("snd_cast_ready");
            }
        }
        if (this->castAirCounter > 0)
        {
            if (this->castAirCounter < this->castAirTimer)
            {
                this->castAirCounter++;
                this->container->butCastAir->cont->contMask->setScaleY( this->castAirCounter / this->castAirTimer);
            }
            else
            {
                this->castAirCounter = 0;
                this->container->butCastAir->cont->contMask->setScaleY( 1);
                this->container->butCastAir->gotoAndStop(1);
                this->container->butCastAir->castAirCase->buttonMode = true;
                this->autoguidersButtons();
                //Sounds.instance.playSound("snd_cast_ready");
            }
        } 
    }// end function

    void WorldInterface::castRegime(string param1) 
    {
        if (param1 == "on")
        {
            this->castMask->setVsible(true);
            this->world->manageMouse("hide"); 
            this->container->mouseChildren = false;
            this->container->mouseEnabled = false;
            this->i = 0;
            while (this->i < this->world->listOfPlaces.size())
            { 
                this->world->listOfPlaces[this->i]->mouseChildren = false;
                this->world->listOfPlaces[this->i]->mouseEnabled = false;
                i++;
            }
            this->world->road->setVisible(true);
        }
        else if (param1 == "off")
        {
            this->castMask->setVisible(false);
            this->world->manageMouse("show");
            var _loc_2:* = true;
            this->container->mouseChildren = true;
            this->container->mouseEnabled = _loc_2;
            this->i = 0;
            while (this->i < this->world->listOfPlaces.size())
            { 
                this->world->listOfPlaces[this->i]->mouseChildren = true;
                this->world->listOfPlaces[this->i]->mouseEnabled = true;
                i++;
            }
            this->world->road->setVisible(false);
            if (this->world->pointer1)
            {
                this->world->pointer1->alpha = 1;
            }
            if (this->world->pointer2)
            {
                this->world->pointer2->alpha = 1;
            }
            if (this->world->pointer3)
            {
                this->world->pointer3->alpha = 1;
            }
        }
    }// end function

    void WorldInterface::fastPlayControl(int param1)
    {
        if (param1 == 0)
        {
            this->fasterFlag = 0;
            //Main::mainClass->stage.frameRate = 30;
        }
        else if (param1 == 1)
        {
            this->fasterFlag = 1;
            //Main::mainClass->stage.frameRate = 1;
        }
        else if (param1 == 2)
        {
            this->fasterFlag = 2;
            //Main::mainClass->stage.frameRate = 30;
        } 
    }// end function

	 void  WorldInterface::barInfoView()
    {
        if (dynamic_cast<GetSphere *>(this->world->selectObject) && this->world->getSphere)
        {
            if (this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
            {
                std::setText(this->container->barInfo->noteTXT , string("范围: ") + std::round(this->world->getSphere->myRadius) + " ; 火焰伤害: " + std::round(this->world->getSphere->myDamage));
            }
            else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount == 0)
            {
                std::setText(this->container->barInfo->noteTXT , string("范围: ") + std::round(this->world->getSphere->myRadius) + " ; 寒冰伤害: " + std::round(this->world->getSphere->myDamage));
            }
            else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount == 0)
            {
                std::setText(this->container->barInfo->noteTXT , string("范围: ") + std::round(this->world->getSphere->myRadius) + " ; 岩石伤害: " + std::round(this->world->getSphere->myDamage));
            }
            else if (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount > 0)
            {
                std::setText(this->container->barInfo->noteTXT , string("范围: ") + std::round(this->world->getSphere->myRadius) + " ; 闪电伤害: " + std::round(this->world->getSphere->myDamage));
            }
            else if (this->world->getSphere->getAllCount > 0)
            {
                std::setText(this->container->barInfo->noteTXT , string("范围: ") + std::round(this->world->getSphere->myRadius) + " ; 伤害: " + std::round(this->world->getSphere->myDamage));
            }
            else if ((this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount == 0 )
                || (this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount == 0 && this->world->getSphere->levinCount > 0 )
                || (this->world->getSphere->fireCount > 0 && this->world->getSphere->iceCount == 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount > 0 )
                || (this->world->getSphere->fireCount == 0 && this->world->getSphere->iceCount > 0 && this->world->getSphere->stoneCount > 0 && this->world->getSphere->levinCount > 0))
            {
                if (this->world->getSphere->fireCount > 1 || this->world->getSphere->iceCount > 1 || this->world->getSphere->stoneCount > 1 || this->world->getSphere->levinCount > 1)
                {
                    std::setText(this->container->barInfo->noteTXT , string("范围: ") + std::round(this->world->getSphere->myRadius) + " ; 伤害: " + std::round(this->world->getSphere->myDamage * Main::mainClass->readXMLClass.getAllLittleDoubleMultiply));
                }
                else
                {
                    std::setText(this->container->barInfo->noteTXT , string("范围: ") + std::round(this->world->getSphere->myRadius) + " ; 伤害: " + std::round(this->world->getSphere->myDamage * Main::mainClass->readXMLClass.getAllLittleMultiply));
                }
            }
            else
            {
                std::setText(this->container->barInfo->noteTXT , string("范围: ") + std::round(this->world->getSphere->myRadius) + " ; 伤害: " + std::round(this->world->getSphere->myDamage));
            }
        }
        else if (dynamic_cast<Cast *>(this->world->selectObject) && this->world->cast)
        {
            if (dynamic_cast<Cast_1 *>(this->world->cast))
            {
                std::setText(this->container->barInfo->healthTXT , std::round(Main::mainClass->readXMLClass.castGolemHealthXML) );
            }
            else if (dynamic_cast<Cast_2 *>(this->world->cast))
            {
                std::setText(this->container->barInfo->noteTXT , std::round(Main::mainClass->readXMLClass.castIcemanLifeTimerXML / 30) + " 秒" );
            }
            else if (dynamic_cast<Cast_3 *>(this->world->cast))
            {
                std::setText(this->container->barInfo->noteTXT , std::round(Main::mainClass->readXMLClass.airLifeSecXML / 30) + " 秒" );
            }
        }
        else if (dynamic_cast<Unit *>(this->world->selectObject))
        {
            std::setText(this->container->barInfo->healthTXT , std::round(this->world->selectObject->health) + "/" + std::round(this->world->selectObject->healthMax) );
            if (this->container->barInfo->myTarget != this->world->selectObject)
            {
                this->container->barInfo->myTarget = this->world->selectObject;
                Common::Array<string> tempObject = Encyclopedia::enemyInfo(this->world->selectObject->typeUnit); 
                std::setText(this->container->barInfo->speedTXT , tempObject[2] );
                std::setText(this->container->barInfo->penaltyTXT , tempObject[3] ); 
                std::setText(this->container->barInfo->fireTXT , tempObject[4] );
                std::setText(this->container->barInfo->iceTXT , tempObject[5] );
                std::setText(this->container->barInfo->stoneTXT , tempObject[6] );
                std::setText(this->container->barInfo->levinTXT , tempObject[7] );
            }
        }
        else if (dynamic_cast<Golem *>(this->world->selectObject))
        {
            if (!this->world->selectObject->brother)
            {
                std::setText(this->container->barInfo->healthTXT , std::round(this->world->selectObject->health) );
            }
            else
            {
                if (!this->world->selectObject->dead && !this->world->selectObject->brother->dead)
                {
                    tempObject = std::round(this->world->selectObject->health) + std::round(this->world->selectObject->brother.health);
                }
                else if (!this->world->selectObject->dead)
                {
                    tempObject = std::round(this->world->selectObject->health);
                }
                else if (!this->world->selectObject->brother->dead)
                {
                    tempObject = std::round(this->world->selectObject->brother.health);
                }
                std::setText(this->container->barInfo->healthTXT , std::round(tempObject) );
            }
        }
        else if (dynamic_cast<Iceman *>(this->world->selectObject))
        {
            int tempObject = (int)(this->world->selectObject->liveCounter / 30 + 0.99);
            if (tempObject > 0)
            {
                std::setText(this->container->barInfo->noteTXT , tempObject + " 秒" );
            }
            else
            {
                this->barInfoManage();
            }
        }
        else if (dynamic_cast<Air *>(this->world->selectObject))
        {
            int tempObject = (int)(this->world->selectObject->liveCounter / 30 + 0.99);
            if (tempObject > 0)
            {
                std::setText(this->container->barInfo->noteTXT , tempObject + " 秒" );
            }
            else
            {
                this->barInfoManage();
            }
        }
        else if (dynamic_cast<TowerMenu *>(this->world->selectObject) || dynamic_cast<UltraTowerMenu *>(this->world->selectObject))
        {
            if (this->world->selectObject->myTower->towerType < 5)
            {
                std::setText(this->container->barInfo->noteTXT , "" );
                if (this->world->selectObject->myTower->shootingTurnStack[0])
                {
                    std::setText(this->container->barInfo->noteTXT , "火焰: " + std::round(Main::mainClass->readXMLClass.listOfFireTowerDamageXML[(this->world->selectObject->myTower->shootingTurnStack[0][3] - 1)]) + " ; ");
                }
                if (this->world->selectObject->myTower->shootingTurnStack[1])
                {
                    std::setText(this->container->barInfo->noteTXT , std::getText(this->container->barInfo->noteTXT) + "寒冰: " + std::round(Main::mainClass->readXMLClass.listOfIceTowerDamageXML[(this->world->selectObject->myTower->shootingTurnStack[1][3] - 1)]) + " ; ");
                }
                if (this->world->selectObject->myTower->shootingTurnStack[2])
                {
                    std::setText(this->container->barInfo->noteTXT , std::getText(this->container->barInfo->noteTXT) + "岩石: " + std::round(Main::mainClass->readXMLClass.listOfStoneTowerDamageXML[(this->world->selectObject->myTower->shootingTurnStack[2][3] - 1)]) + " ; ");
                }
                if (this->world->selectObject->myTower->shootingTurnStack[3])
                {
                    std::setText(this->container->barInfo->noteTXT , std::getText(this->container->barInfo->noteTXT) + "闪电: " + std::round(Main::mainClass->readXMLClass.listOfLevinTowerDamageXML[(this->world->selectObject->myTower->shootingTurnStack[3][3] - 1)]) + " ; ");
                }
                if (std::getText(this->container->barInfo->noteTXT) == "")
                {
                    std::setText(this->container->barInfo->noteTXT , "无元素" );
                }
                else
                {
                    string noteText=std::getText(this->container->barInfo->noteTXT);
                    std::setText(this->container->barInfo->noteTXT , noteText.subStr(0, noteText.size() - 2) );
                }
            }
            else
            {
                if (this->world->selectObject->myTower->towerType == 8)
                {
                    std::setText(this->container->barInfo->noteTXT , "伤害: " + std::round(this->world->selectObject->myTower->damage * 3) );
                }
                else
                {
                    std::setText(this->container->barInfo->noteTXT , "伤害: " + std::round(this->world->selectObject->myTower->damage) );
                }
                if (this->world->selectObject->myTower->upgradeTypeAdd == 1)
                {
                    if (this->world->selectObject->myTower->towerType == 5)
                    {
                        std::setText(this->container->barInfo->noteTXT , std::getText(this->container->barInfo->noteTXT) + " ; 额外伤害: " + std::round(this->world->selectObject->myTower->upgr1_damage * 49));
                    }
                    else
                    {
                        std::setText(this->container->barInfo->noteTXT , std::getText(this->container->barInfo->noteTXT) + " ; 额外伤害: " + std::round(this->world->selectObject->myTower->upgr1_damage));
                    }
                }
            }
        }
        else if (this->world->selectObject)
        {
            if (!this->world->towerMenu)
            {
                this->barInfoManage();
            }
            else
            {
                this->barInfoManage(this->world->towerMenu);
            }
        }
        return;
    }// end function

	void WorldInterface::barInfoManage(BaseNode * param1) 
    {
        if (this->world->selectObject)
        {
            if (dynamic_cast<Unit *>(this->world->selectObject))
            {
                this->world->selectObject->container->selectUnit->setVisible(false);
            }
        }
        if (!param1)
        {
            this->world->selectObject = NULL;
            this->world->worldInterface->container->barInfo->gotoAndStop(1);
            this->i = this->world->listOfClasses.size() - 1;
            while (this->i >= 0)
            {
                
                if (dynamic_cast<Golem *>(this->world->listOfClasses[this->i]) || dynamic_cast<Iceman *>(this->world->listOfClasses[this->i]) 
                    || dynamic_cast<Air *>(this->world->listOfClasses[this->i]))
                {
                    this->world->selectObject = this->world->listOfClasses[this->i];
                    if (dynamic_cast<Golem *>(this->world->listOfClasses[this->i]))
                    {
                        this->world->worldInterface->container->barInfo->gotoAndStop(4);
                    }
                    else if (dynamic_cast<Iceman *>(this->world->listOfClasses[this->i]) || dynamic_cast<Air *>(this->world->listOfClasses[this->i]))
                    {
                        this->world->worldInterface->container->barInfo->gotoAndStop(5);
                    }
                    else
                    {
                        this->world->worldInterface->container->barInfo->gotoAndStop(2);
                    }
                    break;
                i--;
                }
            }
        }
        else
        {
            this->world->selectObject = param1;
            if (dynamic_cast<Unit *>(this->world->selectObject)  )
            {
                this->world->selectObject->container->selectUnit->setVisible(true);
                this->world->worldInterface->container->barInfo->gotoAndStop(3);
                this->container->barInfo->myTarget = NULL;
            }
            else if (dynamic_cast<Golem *>(this->world->selectObject)   || dynamic_cast<Cast_1 *>(this->world->selectObject) )
            {
                this->world->worldInterface->container->barInfo->gotoAndStop(4);
            }
            else if (dynamic_cast<Iceman *>(this->world->selectObject) || dynamic_cast<Cast_2 *>(this->world->selectObject) 
                || dynamic_cast<Air *>(this->world->selectObject) || dynamic_cast<Cast_3 *>(this->world->selectObject))
            {
                this->world->worldInterface->container->barInfo->gotoAndStop(5);
            }
            else
            {
                this->world->worldInterface->container->barInfo->gotoAndStop(2);
            }
            this->barInfoView();
        }
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
            if (dynamic_cast<Cast_1 *>(this->world->cast)  )
            {
                this->container->butCastGolem->gotoAndStop(1);
            }
            else if (dynamic_cast<Cast_2 *>(this->world->cast) )
            {
                this->container->butCastIceman->gotoAndStop(1);
            }
            else if (dynamic_cast<Cast_3 *>(this->world->cast) )
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
            this->world->hint->setPosition(this->mouseX, this->mouseY);
            if (this->world->hint->currentFrame == 1)
            {
                if (std::getText(this->world->hint->nameTXT) == "击碎者重置")
                {
                    if (this->container->butCastGolem->currentFrame == 4)
                    {
                        std::setText(this->world->hint->timeTXT,(int)((this->castGolemTimer - this->castGolemCounter) / 30) + 1);
                        //this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
                    }
                    else
                    {
                        this->world->hint->setVisible(false);
                    }
                }
                else if (std::getText(this->world->hint->nameTXT) == "冰冻者重置")
                {
                    if (this->container->butCastIceman->currentFrame == 4)
                    {
                        std::setText(this->world->hint->timeTXT , (int)((this->castIcemanTimer - this->castIcemanCounter) / 30) + 1 );
                        //this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
                    }
                    else
                    {
                        this->world->hint->setVisible(false);
                    }
                }
                else if (std::getText(this->world->hint->nameTXT) == "复活岛巨像重置")
                {
                    if (this->container->butCastAir->currentFrame == 4)
                    {
                        std::setText(this->world->hint->timeTXT , (int)((this->castAirTimer - this->castAirCounter) / 30) + 1 );
                        this->world->hint->timeTXT.setTextFormat(Main::mainClass->boldTextFormat);
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
        this->autoguidesMouse_pt = cocos2d::Point(Main::mainClass->worldClass->mouseX, Main::mainClass->worldClass->mouseY);
        this->autoguidesObject = NULL;
        this->autoguidesObject_pt = this->container->butCastGolem->localToGlobal(this->container->butCastGolem->castGolemCase->getPosition());
        this->autoguidesObjectWidth = this->container->butCastGolem->castGolemCase.width / 2;
        this->autoguidesObjectHeight = this->container->butCastGolem->castGolemCase.height / 2;
        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        {
            this->autoguidesObject = this->container->butCastGolem->castGolemCase;
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->butCastIceman->localToGlobal(this->container->butCastIceman->castIcemanCase->getPosition());
            this->autoguidesObjectWidth = this->container->butCastIceman->castIcemanCase.width / 2;
            this->autoguidesObjectHeight = this->container->butCastIceman->castIcemanCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->butCastIceman->castIcemanCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->butCastAir->localToGlobal(this->container->butCastAir->castAirCase->getPosition());
            this->autoguidesObjectWidth = this->container->butCastAir->castAirCase.width / 2;
            this->autoguidesObjectHeight = this->container->butCastAir->castAirCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->butCastAir->castAirCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->fast->localToGlobal(this->container->fast->fastCase->getPosition());
            this->autoguidesObjectWidth = this->container->fast->fastCase.width / 2;
            this->autoguidesObjectHeight = this->container->fast->fastCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->fast->fastCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->fireSphere->localToGlobal(this->container->fireSphere->sphereCase->getPosition());
            this->autoguidesObjectWidth = this->container->fireSphere->sphereCase.width / 2;
            this->autoguidesObjectHeight = this->container->fireSphere->sphereCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->fireSphere->sphereCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->iceSphere->localToGlobal(this->container->iceSphere->sphereCase->getPosition());
            this->autoguidesObjectWidth = this->container->iceSphere->sphereCase.width / 2;
            this->autoguidesObjectHeight = this->container->iceSphere->sphereCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->iceSphere->sphereCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->stoneSphere->localToGlobal(this->container->stoneSphere->sphereCase->getPosition());
            this->autoguidesObjectWidth = this->container->stoneSphere->sphereCase.width / 2;
            this->autoguidesObjectHeight = this->container->stoneSphere->sphereCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->stoneSphere->sphereCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->levinSphere->localToGlobal(this->container->levinSphere->sphereCase->getPosition());
            this->autoguidesObjectWidth = this->container->levinSphere->sphereCase.width / 2;
            this->autoguidesObjectHeight = this->container->levinSphere->sphereCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->levinSphere->sphereCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->getAll->localToGlobal(this->container->getAll->sphereCase->getPosition());
            this->autoguidesObjectWidth = this->container->getAll->sphereCase.width / 2;
            this->autoguidesObjectHeight = this->container->getAll->sphereCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
                && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
                && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->getAll->sphereCase;
            }
        }
        if (this->autoguidesObject)
        { //模拟event
            tempObject = new Object();
            tempObject->target = this->autoguidesObject;
            this->mouseMoveHandler(tempObject);
        }
    }// end function
    
    void WorldInterface::spheresBlockManage(string param1)
    {
        if (param1 == "")
        {
            this->container->fireSphere->alpha = 0;
            this->container->fireNumTXT->alpha = 0;
            this->container->buyFire->alpha = 0;
            this->container->fireSphere->mouseChildren = false;
            this->container->fireSphere->mouseEnabled = false;
            this->container->fireNumTXT->mouseEnabled = false;
            this->container->buyFire->mouseChildren = false;
            this->container->buyFire->mouseEnabled = false;
            this->container->fireSphere->setVisible(false);
            this->container->iceSphere->alpha = 0;
            this->container->iceNumTXT->alpha = 0;
            this->container->buyIce->alpha = 0;
            this->container->iceSphere->mouseChildren = false;
            this->container->iceSphere->mouseEnabled = false;
            this->container->iceNumTXT->mouseEnabled = false;
            this->container->buyIce->mouseChildren = false;
            this->container->buyIce->mouseEnabled = false;
            this->container->iceSphere->setVisible(false);
            this->container->stoneSphere->alpha = 0;
            this->container->stoneNumTXT->alpha = 0;
            this->container->buyStone->alpha = 0;
            this->container->stoneSphere->mouseChildren = false;
            this->container->stoneSphere->mouseEnabled = false;
            this->container->stoneNumTXT->mouseEnabled = false;
            this->container->buyStone->mouseChildren = false;
            this->container->buyStone->mouseEnabled = false;
            this->container->stoneSphere->setVisible(false);
            this->container->levinSphere->alpha = 0;
            this->container->levinNumTXT->alpha = 0;
            this->container->buyLevin->alpha = 0;
            this->container->levinSphere->mouseChildren = false;
            this->container->levinSphere->mouseEnabled = false;
            this->container->levinNumTXT->mouseEnabled = false;
            this->container->buyLevin->mouseChildren = false;
            this->container->buyLevin->mouseEnabled = false;
            this->container->levinSphere->setVisible(false);
            this->container->getAll->gotoAndStop(3);
            this->container->buygetAll->alpha = 0;
            this->container->getAllNumTXT->alpha = 0;
            this->container->getAllNumTXT->mouseEnabled = false;
            this->container->buygetAll->mouseChildren = false;
            this->container->buygetAll->mouseEnabled = false;
            this->container->fireBack->gotoAndStop(3);
            this->container->iceBack->gotoAndStop(3);
            this->container->stoneBack->gotoAndStop(3);
            this->container->levinBack->gotoAndStop(3);
            if (Main::mainClass->readXMLClass.archiveSphereBlock == 3)
            {
                this->container->fireSphere->setVisible( true);
                this->container->fireBack->gotoAndStop(1);
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
            this->container->fireSphere->setScaleY( 1);
            this->container->fireSphere->setScaleX( 1);
            this->container->fireSphere->alpha = 1;
            this->container->fireNumTXT->alpha = 1;
            this->container->buyFire->alpha = 1;
            this->container->fireSphere->mouseChildren = true;
            this->container->fireSphere->mouseEnabled = true;
            this->container->fireNumTXT->mouseEnabled = false;
            this->container->buyFire->mouseChildren = true;
            this->container->buyFire->mouseEnabled = true;
            this->container->fireBack->gotoAndStop(1);
        }
        else if (param1 == "unblockIce")
        {
            this->container->iceSphere->setScaleY(1);
            this->container->iceSphere->setScaleX(1);
            this->container->iceSphere->alpha = 1;
            this->container->iceNumTXT->alpha = 1;
            this->container->buyIce->alpha = 1;
            this->container->iceSphere->mouseChildren = true;
            this->container->iceSphere->mouseEnabled = true;
            this->container->iceNumTXT->mouseEnabled = false;
            this->container->buyIce->mouseChildren = true;
            this->container->buyIce->mouseEnabled = true;
            this->container->iceBack->gotoAndStop(1);
        }
        else if (param1 == "unblockStone")
        {
            this->container->stoneSphere->setScaleY(1);
            this->container->stoneSphere->setScaleX(1);
            this->container->stoneSphere->alpha = 1;
            this->container->stoneNumTXT->alpha = 1;
            this->container->buyStone->alpha = 1;
            this->container->stoneSphere->mouseChildren = true;
            this->container->stoneSphere->mouseEnabled = true;
            this->container->stoneNumTXT->mouseEnabled = false;
            this->container->buyStone->mouseChildren = true;
            this->container->buyStone->mouseEnabled = true;
            this->container->stoneBack->gotoAndStop(1);
        }
        else if (param1 == "unblockLevin")
        { 
            this->container->levinSphere->setScaleY(1);
            this->container->levinSphere->setScaleX(1);
            this->container->levinSphere->alpha = 1;
            this->container->levinNumTXT->alpha = 1;
            this->container->buyLevin->alpha = 1;
            this->container->levinSphere->mouseChildren = true;
            this->container->levinSphere->mouseEnabled = true;
            this->container->levinNumTXT->mouseEnabled = false;
            this->container->buyLevin->mouseChildren = true;
            this->container->buyLevin->mouseEnabled = true;
            this->container->levinBack->gotoAndStop(1);
        }
        else if (param1 == "unblockGetAll")
        {
            this->container->getAll->setScaleY(1);
            this->container->getAll->setScaleX(1);
            this->container->getAll->gotoAndStop(1);
            this->container->getAll->fire->stop();
            this->container->getAll->ice->stop();
            this->container->getAll->stone->stop();
            this->container->getAll->levin->stop();
            this->container->buygetAll->alpha = 1;
            this->container->getAllNumTXT->alpha = 1;
            this->container->getAllNumTXT->mouseEnabled = false;
            this->container->buygetAll->mouseChildren = true;
            this->container->buygetAll->mouseEnabled = true;
        }
        this->updateInfo();
        return;
    }// end function 
    
	void WorldInterface::archiveSphereBacklightManage(string param1)
    {
        BaseTowerMenu *tempObject=NULL;
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
            if (!this->container->fireBacklight->turnFlag)
            {
                this->container->fireBacklight->turnFlag = true;
            }
            if (!this->container->iceBacklight->turnFlag)
            {
                this->container->iceBacklight->turnFlag = true;
            }
            if (!this->container->stoneBacklight->turnFlag)
            {
                this->container->stoneBacklight->turnFlag = true;
            }
            if (!this->container->levinBacklight->turnFlag)
            {
                this->container->levinBacklight->turnFlag = true;
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
            {
                this->container->fast->gotoAndStop(5);
            }
            else
            {
                this->container->fast->gotoAndStop(4);
            }
            this->container->fast->cont->stop();
            this->fastPlayControl(2);
            if (this->container->slow->currentFrame != 1)
            {
                this->container->slow->gotoAndStop(1);
            }
        }
        else
        {
            if (param1)
            {
                this->container->fast->gotoAndStop(2);
            }
            else
            {
                this->container->fast->gotoAndStop(1);
            }
            this->fastPlayControl(0);
        }
    }// end function

	void WorldInterface::sellSphere(string param1)
    {
        int tempObject=0;
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
            this->world->money = this->world->money + std::round(tempObject * Main::mainClass->readXMLClass.fireSellTax);
            this->world->sellFireCounter++;
            int addit_sellFireCounter=this->world->saveBox->getIntValue("addit_sellFireCounter")+1;
            this->world->saveBox->setValue("addit_sellFireCounter",addit_sellFireCounter);//.gameSave.data.addit_sellFireCounter + 1);
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
            this->world->money = this->world->money + std::round(tempObject * Main::mainClass->readXMLClass.iceSellTax);
            this->world->sellIceCounter++;
            int addit_sellIceCounter=this->world->saveBox->getIntValue("addit_sellIceCounter")+1;
            this->world->saveBox->setValue("addit_sellIceCounter",addit_sellIceCounter); 
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
            this->world->money = this->world->money + std::round(tempObject * Main::mainClass->readXMLClass.stoneSellTax);
            this->world->sellStoneCounter++;
            int addit_sellStoneCounter=this->world->saveBox->getIntValue("addit_sellStoneCounter")+1;
            this->world->saveBox->setValue("addit_sellStoneCounter",addit_sellStoneCounter); 
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
            this->world->money = this->world->money + std::round(tempObject * Main::mainClass->readXMLClass.levinSellTax);
            this->world->sellLevinCounter++;
            int addit_sellLevinCounter=this->world->saveBox->getIntValue("addit_sellLevinCounter")+1;
            this->world->saveBox->setValue("addit_sellLevinCounter",addit_sellLevinCounter);  
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
        tempObject->setPositionY(this->container->barInfo->getPositionY() - 42);
        tempObject->closeFlag = false;
        tempObject->counter = 30; 
        tempObject->mouseChildren = false;
        tempObject->mouseEnabled = false;
        this->addChild(tempObject);
        this->listOfGetAhieve.push(tempObject);
        if (param1 == "firstKill")
        {
            tempObject->icon->gotoAndStop(1); 
            tempObject->myText = "第一滴血";
            std::setText(tempObject->board->noteTXT , "第一滴血" );
        }
        else if (param1 == "kill_100_enemies")
        {
            tempObject->icon->gotoAndStop(2); 
            tempObject->myText = "热烈无比";
            std::setText(tempObject->board->noteTXT , "热烈无比" );
        }
        else if (param1 == "kill_2500_enemies")
        {
            tempObject->icon->gotoAndStop(3); 
            tempObject->myText = "杀手";
            std::setText(tempObject->board->noteTXT , "杀手" );
        }
        else if (param1 == "call_100_earlyWaves")
        {
            tempObject->icon->gotoAndStop(4); 
            tempObject->myText = "毫无畏惧";
            std::setText(tempObject->board->noteTXT , "毫无畏惧" );
        }
        else if (param1 == "build_100_towers")
        {
            tempObject->icon->gotoAndStop(5); 
            tempObject->myText = "建造者";
            std::setText(tempObject->board->noteTXT , "建造者" );
        }
        else if (param1 == "createGolem_5_times")
        {
            tempObject->icon->gotoAndStop(6); 
            tempObject->myText = "巨型支援";
            std::setText(tempObject->board->noteTXT , "巨型支援" );
        }
        else if (param1 == "createIceman_15_times")
        {
            tempObject->icon->gotoAndStop(7); 
            tempObject->myText = "缓和";
            std::setText(tempObject->board->noteTXT , "缓和" );
        }
        else if (param1 == "createAir_7_times")
        {
            tempObject->icon->gotoAndStop(8); 
            tempObject->myText = "远古支援";
            std::setText(tempObject->board->noteTXT , "远古支援" );
        }
        else if (param1 == "callAllWavesInLevel")
        {
            tempObject->icon->gotoAndStop(9); 
            tempObject->myText = "大胆";
            std::setText(tempObject->board->noteTXT , "大胆" );
        }
        else if (param1 == "sellFireIceStoneLevin")
        {
            tempObject->icon->gotoAndStop(10); 
            tempObject->myText = "破坏者";
            std::setText(tempObject->board->noteTXT , "破坏者" );
        }
        else if (param1 == "sellFire_10_times")
        {
            tempObject->icon->gotoAndStop(11); 
            tempObject->myText = "火焰破坏者";
            std::setText(tempObject->board->noteTXT , "火焰破坏者" );
        }
        else if (param1 == "sellIce_10_times")
        {
            tempObject->icon->gotoAndStop(12); 
            tempObject->myText = "寒冰破坏者";
            std::setText(tempObject->board->noteTXT , "寒冰破坏者" );
        }
        else if (param1 == "sellStone_10_times")
        {
            tempObject->icon->gotoAndStop(13); 
            tempObject->myText = "巨石破坏者";
            std::setText(tempObject->board->noteTXT , "巨石破坏者" );
        }
        else if (param1 == "sellLevin_10_times")
        {
            tempObject->icon->gotoAndStop(14); 
            tempObject->myText = "闪电破坏者";
            std::setText(tempObject->board->noteTXT , "闪电破坏者" );
        }
        else if (param1 == "golemKill_250_enemies")
        {
            tempObject->icon->gotoAndStop(15); 
            tempObject->myText = "粉碎者";
            std::setText(tempObject->board->noteTXT , "粉碎者" );
        }
        else if (param1 == "icemanSlowdown_75_enemies")
        {
            tempObject->icon->gotoAndStop(16); 
            tempObject->myText = "有点冷";
            std::setText(tempObject->board->noteTXT , "有点冷" );
        }
        else if (param1 == "icemanSlowdown_500_enemies")
        {
            tempObject->icon->gotoAndStop(17); 
            tempObject->myText = "霜冻力量";
            std::setText(tempObject->board->noteTXT , "霜冻力量" );
        }
        else if (param1 == "buildUltraTower")
        {
            tempObject->icon->gotoAndStop(18); 
            tempObject->myText = "进阶建造者";
            std::setText(tempObject->board->noteTXT , "进阶建造者" );
        }
        else if (param1 == "buildUltraTower_50_times")
        {
            tempObject->icon->gotoAndStop(19); 
            tempObject->myText = "专家建造者";
            std::setText(tempObject->board->noteTXT, "专家建造者");
        }
        else if (param1 == "buildAllUltraTowers")
        {
            tempObject->icon->gotoAndStop(20); 
            tempObject->myText = "策略建造者";
            std::setText(tempObject->board->noteTXT , "策略建造者" );
        }
        else if (param1 == "notCast")
        {
            tempObject->icon->gotoAndStop(21); 
            tempObject->myText = "上手";
            std::setText(tempObject->board->noteTXT , "上手" );
        }
        else if (param1 == "castFire_150_times")
        {
            tempObject->icon->gotoAndStop(22); 
            tempObject->myText = "火焰大师";
            std::setText(tempObject->board->noteTXT , "火焰大师" );
        }
        else if (param1 == "castIce_150_times")
        {
            tempObject->icon->gotoAndStop(23); 
            tempObject->myText = "寒冰大师";
            std::setText(tempObject->board->noteTXT , "寒冰大师" );
        }
        else if (param1 == "castStone_150_times")
        {
            tempObject->icon->gotoAndStop(24); 
            tempObject->myText = "岩石大师";
            std::setText(tempObject->board->noteTXT , "岩石大师" );
        }
        else if (param1 == "castLevin_150_times")
        {
            tempObject->icon->gotoAndStop(25); 
            tempObject->myText = "闪电大师";
            std::setText(tempObject->board->noteTXT , "闪电大师" );
        }
        else if (param1 == "castGetAll_10_times")
        {
            tempObject->icon->gotoAndStop(26); 
            tempObject->myText = "策略爆破者";
            std::setText(tempObject->board->noteTXT , "策略爆破者" );
        }
        else if (param1 == "castGetAll_100_times")
        {
            tempObject->icon->gotoAndStop(27); 
            tempObject->myText = "爆破者";
            std::setText(tempObject->board->noteTXT , "爆破者" );
        }
        else if (param1 == "castKill_1_enemy")
        {
            tempObject->icon->gotoAndStop(28); 
            tempObject->myText = "施法者";
            std::setText(tempObject->board->noteTXT , "施法者" );
        }
        else if (param1 == "castKill_100_enemy")
        {
            tempObject->icon->gotoAndStop(29); 
            tempObject->myText = "法术杀手";
            std::setText(tempObject->board->noteTXT , "法术杀手" );
        }
        else if (param1 == "complete_10_hardLevels")
        {
            tempObject->icon->gotoAndStop(30); 
            tempObject->myText = "勇猛战士";
            std::setText(tempObject->board->noteTXT , "勇猛战士" );
        }
        else if (param1 == "complete_10_survivalLevels")
        {
            tempObject->icon->gotoAndStop(31); 
            tempObject->myText = "幸存者";
            std::setText(tempObject->board->noteTXT , "幸存者" );
        }
        else if (param1 == "complete_10_withAllLives")
        {
            tempObject->icon->gotoAndStop(32); 
            tempObject->myText = "活力四射";
            std::setText(tempObject->board->noteTXT , "活力四射" );
        }
        else if (param1 == "achieve_dude_01")
        {
            tempObject->icon->gotoAndStop(33); 
            tempObject->myText = "伐木工";
            std::setText(tempObject->board->noteTXT , "伐木工" );
        }
        else if (param1 == "achieve_dude_02")
        {
            tempObject->icon->gotoAndStop(34); 
            tempObject->myText = "忙忙碌碌";
            std::setText(tempObject->board->noteTXT , "忙忙碌碌" );
        }
        else if (param1 == "achieve_dude_03")
        {
            tempObject->icon->gotoAndStop(35); 
            tempObject->myText = "南瓜节";
            std::setText(tempObject->board->noteTXT , "南瓜节" );
        }
        else if (param1 == "achieve_dude_04")
        {
            tempObject->icon->gotoAndStop(36); 
            tempObject->myText = "修理工";
            std::setText(tempObject->board->noteTXT , "修理工" );
        }
        else if (param1 == "achieve_dude_05")
        {
            tempObject->icon->gotoAndStop(37); 
            tempObject->myText = "勇士";
            std::setText(tempObject->board->noteTXT , "勇士" );
        }
        else if (param1 == "achieve_dude_06")
        {
            tempObject->icon->gotoAndStop(38); 
            tempObject->myText = "睡眼阑珊";
            std::setText(tempObject->board->noteTXT , "睡眼阑珊" );
        }
        else if (param1 == "achieve_dude_07")
        {
            tempObject->icon->gotoAndStop(39); 
            tempObject->myText = "超级女声";
            std::setText(tempObject->board->noteTXT , "超级女声" );
        }
        else if (param1 == "achieve_dude_08")
        {
            tempObject->icon->gotoAndStop(40); 
            tempObject->myText = "老烟枪";
            std::setText(tempObject->board->noteTXT , "老烟枪" );
        }
        else if (param1 == "achieve_dude_09")
        {
            tempObject->icon->gotoAndStop(41); 
            tempObject->myText = "渔夫";
            std::setText(tempObject->board->noteTXT , "渔夫" );
        }
        else if (param1 == "achieve_dude_10")
        {
            tempObject->icon->gotoAndStop(42);  
            tempObject->myText = "决斗" ;
            std::setText(tempObject->board->noteTXT , "决斗" );
        }
        else if (param1 == "achieve_dude_11")
        {
            tempObject->icon->gotoAndStop(43); 
            tempObject->myText = "萨满";
            std::setText(tempObject->board->noteTXT , "萨满" );
        }
        else if (param1 == "achieve_dude_12")
        {
            tempObject->icon->gotoAndStop(44); 
            tempObject->myText = "疯狂射手";
            std::setText(tempObject->board->noteTXT , "疯狂射手" );
        }
        else if (param1 == "achieve_dude_13")
        {
            tempObject->icon->gotoAndStop(45); 
            tempObject->myText = "勇猛大头";
            std::setText(tempObject->board->noteTXT , "勇猛大头" ); 
        }
        else if (param1 == "achieve_dude_14")
        {
            tempObject->icon->gotoAndStop(46); 
            tempObject->myText = "寻路无门";
            std::setText(tempObject->board->noteTXT , "寻路无门" );
        }

    }// end function

	void WorldInterface::newEnemyUpdate()
    {
        this->i = this->listOfNewEnemies.size() - 1;
        while (this->i >= 0)
        { 
            MovieClip * tempObject = this->listOfNewEnemies[this->i];
            if (tempObject->currentFrame < tempObject->totalFrames)
            {
                tempObject->gotoAndStop((tempObject->currentFrame + 1));
            }
            else
            {
                tempObject->gotoAndStop(1);
            }
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
            if (tempObject->getPositionX()== 0)
            {
                tempObject->setPositionX(Main::SCREEN_WIDTH - 40);
                if (dynamic_cast<NewEnemy_mc *>(tempObject)) 
                {
                    NewEnemy_mc * enmc=dynamic_cast<NewEnemy_mc *>(tempObject));
                    enmc->newEnemyCase->buttonMode = true;
                }
                else if (dynamic_cast<NewElement_mc *>(tempObject))
                {
                    NewElement_mc * enmc=dynamic_cast<NewElement_mc *>(tempObject));
                    enmc->newElementCase->buttonMode = true;
                }
                tempObject->mouseStatus = 1;
                tempObject->setScaleY( 0);
                tempObject->setScaleX( 0);
                if (this->listOfNewEnemies.size() > 3)
                {
                    this->listOfNewEnemies[0]->mouseStatus = 4;
                    this->listOfNewEnemies[0]->mouseEnabled = false;
                    this->listOfNewEnemies[0]->mouseChildren = false;
                }
                if (this->listOfNewEnemies.size() > 4)
                {
                    this->listOfNewEnemies[1]->mouseStatus = 4;
                    this->listOfNewEnemies[1]->mouseEnabled = false;
                    this->listOfNewEnemies[1]->mouseChildren = false;
                }
                if (this->listOfNewEnemies.size() > 5)
                {
                    this->listOfNewEnemies[2]->mouseStatus = 4;
                    this->listOfNewEnemies[2]->mouseEnabled = false;
                    this->listOfNewEnemies[2]->mouseChildren = false;
                }
                if (this->listOfNewEnemies.size() > 6)
                {
                    this->listOfNewEnemies[3]->mouseStatus = 4;
                    this->listOfNewEnemies[3]->mouseEnabled = false;
                    this->listOfNewEnemies[3]->mouseChildren = false;
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
                        tempObject->setScaleX( tempObject->getScaleX() + 0.25);
                        tempObject->setScaleY( tempObject->getScaleY() + 0.25);
                        if (tempObject->getScaleX() > 1)
                        { 
                            tempObject->setScaleY( 1);
                            tempObject->setScaleX( 1);
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
                        tempObject->setScaleX( tempObject->getScaleX() + 0.25);
                        tempObject->setScaleY( tempObject->getScaleY() + 0.25);
                        if (tempObject->getScaleX() > 1)
                        {
                            tempObject->setScaleY( 1);
                            tempObject->setScaleX( 1);
                        }
                    }
                }
            }
            else if (tempObject->mouseStatus == 3)
            {
                if (tempObject->getScaleX() > 0)
                {
                    tempObject->setScaleX( tempObject->getScaleX() - 0.25);
                    tempObject->setScaleY( tempObject->getScaleY() - 0.25);
                    if (tempObject->getScaleX() < 0)
                    {
                        tempObject->setScaleY( 0);
                        tempObject->setScaleX( 0);
                    }
                }
                else if (dynamic_cast<NewEnemy_mc *>(tempObject))
                {
                    this->world->menuObject = new Education("newEnemy", tempObject->typeUnit);
                    this->world->addChild(this->world->menuObject);
                    this->removeChild(tempObject);
                    this->listOfNewEnemies.splice(this->i, 1);
                }
                else if (dynamic_cast<NewElement_mc *>(tempObject)   )
                {
                    if (!this->world->menuObject)
                    {
                        //this->world->menuObject = new Training_5(tempObject->type);
                        //this->world->addChild(this->world->menuObject);
                    }
                    this->removeChild(tempObject);
                    this->listOfNewEnemies.splice(this->i, 1);
                }
            }
            else if (tempObject->mouseStatus == 4)
            {
                if (tempObject->getScaleX() > 0)
                {
                    tempObject->setScaleX( tempObject->getScaleX() - 0.25);
                    tempObject->setScaleY( tempObject->getScaleY() - 0.25);
                    if (tempObject->getScaleX() < 0)
                    { 
                        tempObject->setScaleY( 0);
                        tempObject->setScaleX( 0);
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