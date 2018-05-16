#include "World.h"
#include "MainClass.h"
#include "engine/units/Unit_1.h"
using namespace engine;
using namespace engine::units;
namespace engine
{ 
    World::World() :towerRadius(NULL),frameCounter(0), liveMax(20), unitInputBezieCounter(0), winDefCounter(-1), viewBoss(0), viewRockCrash(0), portalViewCounter(30)
		, startMusicVolume(0), bonusMoneyFlag(true), eduOpenUpgrArrowFlag(true), killEnemiesCounter(0), createGolemCounter(0)
		, createIcemanCounter(0), createAirCounter(0), earlyWaveCounter(0), sellFireCounter(0), sellIceCounter(0)
		, sellStoneCounter(0), sellLevinCounter(0), sellGetAllCounter(0), icemanSlowdownEnemiesCounter(0), castFireCounter(0), castIceCounter(0)
		, castStoneCounter(0), castLevinCounter(0), castGetAllCounter(0), golemVoiceTurn(1), icemanVoiceTurn(1), airVoiceTurn(1)
		,firstMusicPlay(false),trainingClass(0)
	{
        menuObject = NULL;
		pointer1 = NULL;
		pointer2 = NULL;
		pointer3 = NULL;
		//Main::mainClass->worldClass = this;
		//this->listOfFlags = [];
		//this->listOfPlaces = [];
		//this->listOfFirePortals = [];
		//this->listOfIcePortals = [];
		//this->listOfStonePortals = [];
		//this->listOfLevinPortals = [];
		//this->live = this->liveMax;
		//this->listOfMoveSpheres = [];
		//this->listOfClasses = [];
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
	bool World::init()
	{
		this->wavesClass = new Waves();
		this->feature = new Feature();
		BaseNode::init();
	    return true;
	};
	void World::onEnter()
	{
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		//this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
		//this->schedule(schedule_selector(World::scheduleUpdate));
		this->schedule(schedule_selector(World::scheduleUpdate), 0.0f);
		int complexityLevel=this->saveBox->getIntValue("complexityLevel");
		if (complexityLevel < 4)
		{
			if (this->nowLevel < 12 || this->nowLevel == 13)
			{
				this->mouseChildren = false;
				this->mouseEnabled = false;
			}
		}
		//Main::mainClass->tracker.trackPageview("openLevel_" + this->nowLevel);
 	}// end function

	//void  World::enterFrameHandler()  // event : Event
	void  World::enterFrameHandler( float dt)
	{
	    //dragonBones::CCFactory::getFactory()->getClock()->timeScale=2;
 		if (this->frameCounter < 30)
		{
			this->frameCounter++;
		}
		else
		{
			this->frameCounter = 1;
		}
		if (!this->firstMusicPlay)
		{
		    int complexityLevel=this->saveBox->getIntValue("complexityLevel");
			if (this->frameCounter == 10)
			{
				this->firstMusicPlay = true;
				//Sounds.instance.playMusic(1);
				if (complexityLevel < 4)
				{
					if (this->nowLevel == 1)
					{
						//this->menuObject = new Training_2();
						//this->addChild(this->menuObject); 
						//this->mouseChildren = true;
						//this->mouseEnabled = true;
					}
					else if (this->nowLevel >= 2 && this->nowLevel <= 11)
					{
						//this->menuObject = new Training_92(this->nowLevel - 1);
						//this->addChild(this->menuObject); 
						//this->mouseChildren = true;
						//this->mouseEnabled = true;
					}
					else if (this->nowLevel == 13)
					{
						//this->menuObject = new Training_92(11);
						//this->addChild(this->menuObject); 
						//this->mouseChildren = true;
						//this->mouseEnabled = true;
					}
				}
				else if (this->nowLevel == 1)
				{
					//this->menuObject = new Training_92(13);
					//this->addChild(this->menuObject); 
					//this->mouseChildren = true;
					//this->mouseEnabled = true;
				}
				else if (this->nowLevel == 2)
				{
					//this->menuObject = new Training_5(3);
					//this->addChild(this->menuObject); 
					//this->mouseChildren = true;
					//this->mouseEnabled = true;
				}
			}
		}
		else if (this->secondMusicPlay)
		{
			if (this->secondMusicCounter > 0)
			{
				this->secondMusicCounter--;
			}
			else
			{
				this->secondMusicPlay = false;
				//Sounds.instance.playMusic(2);
			}
		}
		if (this->bonusMoneyFlag)
		{
			if (this->frameCounter == 30 && !this->menuObject)
			{
				this->bonusMoneyFlag = false;
				if (this->saveBox->getIntValue("complexityLevel") < 4 && this->saveBox->getString("type") == "site")
				{
					this->tempObject = new BonusMoney();
					this->addChild(this->tempObject);
				}
			}
		}
		this->wavesClass->wavesHandler();
		int i = 0;
		while (i < this->listOfFlags.size())
		{
			if (this->listOfFlags[this->i]->currentFrame < this->listOfFlags[this->i]->totalFrames)
			{
				this->listOfFlags[this->i]->gotoAndStop((this->listOfFlags[this->i]->currentFrame + 1));
			}
			else
			{
				this->listOfFlags[this->i]->gotoAndStop(1);
			}
			i++;
		}

		if (this->worldInterface)
		{
			this->worldInterface->update();
		}

		this->feature->update();
		//子类播放
		this->i = this->listOfClasses.size() - 1;
		while (this->i >= 0)
		{
			this->listOfClasses[this->i]->update();
			i++;
		}
		this->i = this->listOfTowers.size() - 1;
		while (this->i >= 0)
		{
			this->listOfTowers[this->i]->update();
			i++;
		}

		//怪播放
		this->i = this->listOfUnits.size() - 1;
		while (this->i >= 0)
		{
			this->listOfUnits[this->i]->update();
			i++;
		}
		this->i = this->listOfBullets.size() - 1;
		while (this->i >= 0)
		{ 
			this->listOfBullets[this->i]->update();
			i++;
		}
		//this->i = this->listOfSoundChannels.size() - 1;
		//while (this->i >= 0)
		//{ 
		//	if (this->listOfSoundChannels[this->i]->soundTransform->volume - 0.0186667 > 0)
		//	{
		//		this->listOfSoundChannels[this->i]->soundTransform = new SoundTransform(this->listOfSoundChannels[this->i].soundTransform.volume - 0.0186667, 0);
		//	}
		//	else
		//	{
		//		this->listOfSoundChannels[this->i]->soundTransform = new SoundTransform(0, 0);
		//		this->listOfSoundChannels.splice(this->i, 1);
		//	}
		//	i++;
		//}
		if (this->winDefCounter > -1)
		{
			if (this->winDefCounter > 0)
			{
				winDefCounter--;
			}
			else if (!this->menuObject)
			{
				this->winDefCounter = -1;
				if (this->live <= 0)
				{
					//this->menuObject = new Defeat();
					//this->addChild(this->menuObject);
				}
				else if (this->nowLevel == 15 && this->saveBox->getIntValue("complexityLevel") < 4)
				{
					//this->menuObject = new PreVictory();
					//this->addChild(this->menuObject);
				}
				else
				{
					//this->menuObject = new Victory();
					//this->addChild(this->menuObject);
				}
			}
		}

		if (this->nowLevel == 15)
		{
			if (this->viewBoss == 1)
			{
				//if (Sounds.instance.musicChanel)
				//{
				//	if (this->startMusicVolume == 0)
				//	{
				//		this->startMusicVolume = Sounds.instance.musicChanel.soundTransform.volume;
				//	}
				//	if (Sounds.instance.musicChanel.soundTransform.volume > this->startMusicVolume * 0.35)
				//	{
				//		Sounds.instance.musicChanel.soundTransform = new SoundTransform(Sounds.instance.musicChanel.soundTransform.volume - this->startMusicVolume * 0.035, 0);
				//	}
				//}
				if (this->levelAdditionally->currentFrame < this->levelAdditionally->totalFrames)
				{
					this->levelAdditionally->gotoAndStop((this->levelAdditionally->currentFrame + 1));
				}
				if (this->levelAdditionally->currentFrame == 182)
				{
					this->viewBoss = 2;
					this->boss->setVisible(true);
				}
			}
			if (this->viewRockCrash == 1)
			{
				if (this->levelAdditionally1->currentFrame < this->levelAdditionally1->totalFrames)
				{
					this->levelAdditionally1->gotoAndStop((this->levelAdditionally1->currentFrame + 1));
					if (this->levelAdditionally1->currentFrame == 90)
					{
						//Sounds.instance.playSound("snd_world_openRoad");
					}
				}
				else
				{
					this->viewRockCrash = 2;
				}
			}
		}

		if (this->exchange)
		{
			this->exchange->update();
		}

		if (this->portalViewCounter > -1)
		{
			if (this->portalViewCounter > 0)
			{
				this->portalViewCounter--;
			}
			else
			{
				this->portalViewCounter = -1;
				int i = 0;
				while (i < this->listOfFirePortals.size())
				{ 
					//this->tempObject = new Indexes(new RoadsignFire_mc(), 0);
					//this->tempObject.x = this->listOfFirePortals[this->i].x;
					//this->tempObject.y = this->listOfFirePortals[this->i].y;
					//this->tempObject.scaleX = this->listOfFirePortals[this->i].scaleX;
					//this->tempObject.scaleY = this->listOfFirePortals[this->i].scaleY;
					i++;
				}
				i = 0;
				while (i < this->listOfIcePortals.size())
				{ 
					//this->tempObject = new Indexes(new RoadsignIce_mc(), 0);
					//this->tempObject.x = this->listOfIcePortals[this->i].x;
					//this->tempObject.y = this->listOfIcePortals[this->i].y;
					//this->tempObject.scaleX = this->listOfIcePortals[this->i].scaleX;
					//this->tempObject.scaleY = this->listOfIcePortals[this->i].scaleY;
					i++;
				}
				i = 0;
				while (i < this->listOfStonePortals.size())
				{ 
					//this->tempObject = new Indexes(new RoadsignStone_mc(), 0);
					//this->tempObject.x = this->listOfStonePortals[this->i].x;
					//this->tempObject.y = this->listOfStonePortals[this->i].y;
					//this->tempObject.scaleX = this->listOfStonePortals[this->i].scaleX;
					//this->tempObject.scaleY = this->listOfStonePortals[this->i].scaleY;
					i++;
				}
				i = 0;
				while (i < this->listOfLevinPortals.size())
				{
					//this->tempObject = new Indexes(new RoadsignLevin_mc(), 0);
					//this->tempObject.x = this->listOfLevinPortals[this->i].x;
					//this->tempObject.y = this->listOfLevinPortals[this->i].y;
					//this->tempObject.scaleX = this->listOfLevinPortals[this->i].scaleX;
					//this->tempObject.scaleY = this->listOfLevinPortals[this->i].scaleY;
					i++;
				}
			}
		}
		this->manageIndexes();

		if (this->worldInterface->fasterFlag == 2)
		{
			if (this->frameCounter % 2)
			{
				this->enterFrameHandler(event);
			}
		}
		return;
	}// end function

    //cocos2d::EventMouse* event
	void World::mouseMoveHandler(cocos2d::EventMouse* param1)
    {
 		if (this->getSphere)
		{
			this->getSphere->mouseMoveHandler(param1);
		}
		else
		{
			if (this->cast)
			{
				this->cast->mouseMoveHandler(param1);
				return;
			}
			if (this->towerMenu)
			{
				this->towerMenu->mouseMoveHandler(param1);
			}
			else if (this->ultraTowerMenu)
			{
				this->ultraTowerMenu->mouseMoveHandler(param1);
			}
			else if (this->exchange)
			{
				this->exchange->mouseMoveHandler(param1);
				if (param1->target->name == "towerCase")
				{
					if (!this->towerRadius->isVisible() || param1->target->parent->parent != this->towerRadius->myTower)
					{
						this->towerRadius->myTower = param1->target->parent->parent;
						this->towerRadius->width = this->towerRadius->myTower->radius * 2;
						this->towerRadius->height = this->towerRadius->myTower->radius * 2 * this->scaleRadius;
						this->towerRadius->setPosition(this->towerRadius->myTower->this_pt);
						//this->towerRadius->x = this->towerRadius->myTower->this_pt.x;
						//this->towerRadius->y = this->towerRadius->myTower->this_pt.y;
						this->towerRadius->setVisible(true);
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
				}
				else if (this->towerRadius->isVisible())
				{
					this->towerRadius->setVisible(false);
				}
				return;
			}
		}
		if (this->buildTowerMenu)
		{
			this->buildTowerMenu->mouseMoveHandler(param1);
		}
		this->decoration->mouseMoveHandler(param1);
		if (!this->cast && param1->target->name == "towerCase" && param1->target->buttonMode)
		{
			this->tempObject = false;
			if (this->towerMenu || this->ultraTowerMenu)
			{
				if (this->towerMenu)
				{
					if (this->towerMenu->myTower != param1->target->parent->parent)
					{
						this->tempObject = true;
					}
				}
				else if (this->ultraTowerMenu)
				{
					if (this->ultraTowerMenu->myTower != param1->target->parent->parent)
					{
						this->tempObject = true;
					}
				}
			}
			else
			{
				this->tempObject = true;
			}
			if (this->tempObject)
			{
				if (!this->towerRadius->isVisible() || param1->target->parent->parent != this->towerRadius->myTower)
				{
					if (this->towerRadius->myTower)
					{
						if (this->towerRadius->myTower->towerType < 5)
						{
							if (this->towerRadius->myTower->container->selectTower->isVisible())
							{
								this->towerRadius->myTower->container->selectTower->setVisible(false);
							}
						}
					}
					this->towerRadius->myTower = param1->target->parent->parent;
					this->towerRadius->width = this->towerRadius->myTower->radius * 2;
					this->towerRadius->height = this->towerRadius->myTower->radius * 2 * this->scaleRadius;
					this->towerRadius->setPosition(this->towerRadius->myTower->this_pt);
					//this->towerRadius->x = this->towerRadius->myTower->this_pt.x;
					//this->towerRadius->y = this->towerRadius->myTower->this_pt.y;
					if (this->towerRadius->myTower->towerType < 5)
					{
						if (!this->towerRadius->myTower->container->selectTower->isVisible())
						{
							this->towerRadius->myTower->container->selectTower->setVisible(true);
						}
					}
					this->towerRadius->setVisible(true);
					//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
				}
			}
			else if (this->towerRadius->isVisible())
			{
				this->towerRadius->setVisible(false);
				if (this->towerRadius->myTower->towerType < 5)
				{
					if (this->towerRadius->myTower->container->selectTower->isVisible())
					{
						this->towerRadius->myTower->container->selectTower->setVisible(false);
					}
				}
			}
		}
		else if (this->towerRadius->isVisible())
		{
			this->towerRadius->setVisible(false);
			if (this->towerRadius->myTower->towerType < 5)
			{
				if (this->towerRadius->myTower->container->selectTower->isVisible())
				{
					this->towerRadius->myTower->container->selectTower->setVisible(false);
				}
			}
		}
		if (!this->getSphere && !this->cast)
		{
			if (param1->target->name == "placeForBuildCase" && param1->target->buttonMode)
			{
				if (param1->target->parent->currentFrame == 1)
				{
					if (!this->buildTowerMenu)
					{
						this->buildTowerMenu = new BuildTowerMenu(param1->target->parent);
						this->addChild(this->buildTowerMenu);
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
					else if (this->buildTowerMenu.myPlace != param1->target->parent)
					{
						this->buildTowerMenu->closeMenu();
						this->buildTowerMenu = new BuildTowerMenu(param1->target->parent);
						this->addChild(this->buildTowerMenu);
						//Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
					}
				}
			}
		}
		if (this->worldInterface)
		{
			this->worldInterface->mouseMoveHandler(param1);
		}
		return;
 	}
	void World::mouseDownHandler(cocos2d::EventMouse* event)
    { 
		if (this->getSphere)
		{
			this->getSphere->mouseDownHandler(event);
			if (!this->getSphere)
			{
				return;
			}
		}
		else
		{
			if (this->cast)
			{
				this->cast->mouseDownHandler(event);
				return;
			}
			if (this->towerMenu)
			{
				this->towerMenu->mouseDownHandler(event);
			}
			else if (this->ultraTowerMenu)
			{
				this->ultraTowerMenu->mouseDownHandler(event);
			}
			else if (this->exchange)
			{
				this->exchange->mouseDownHandler(event);
				return;
			}
		}
		if (this->buildTowerMenu) 
			this->buildTowerMenu.mouseDownHandler(event); 
		if(this->decoration)
		    this->decoration->mouseDownHandler(event);
		if (!this->cast && event->target->name == "towerCase" && event->target->buttonMode)
		{
			if (event->target->parent->parent->towerType <= 4)
			{
				this->towerMenu = new TowerMenu(event->target->parent->parent);
				this->addChild(this->towerMenu);
			}
			else
			{
				this->ultraTowerMenu = new UltraTowerMenu(event->target->parent->parent);
				this->addChild(this->ultraTowerMenu);
			}
			//Sounds.instance.playSound("snd_tower_openMenu");
		}
		if (this->worldInterface)
		{
			this->worldInterface->mouseDownHandler(event);
		}
		if (!this->getSphere && !this->cast)
		{
			if (event->target->name == "unitCase")
			{
				if (event->target->name == "unitCase")
				{
					this->worldInterface->barInfoManage(event->target->parent->parent);
				}
			}
			else if (this->selectObject)
			{
				if (this->selectObject is Unit)
				{
					this->worldInterface->barInfoManage();
				}
				else if (this->selectObject is TowerMenu || this->selectObject is UltraTowerMenu)
				{
					if (!this->towerMenu && !this->ultraTowerMenu)
					{
						this->worldInterface->barInfoManage();
					}
				}
			}
		}
		else
		{
			if (this->selectObject)
			{
				if (this->selectObject != this->getSphere && this->selectObject != this->cast)
				{
					if (this->selectObject is Unit)
					{
						this->worldInterface->barInfoManage();
					}
				}
			}
			else
			{
				this->worldInterface->barInfoManage();
			}
			if (this->getSphere)
			{
				if (this->selectObject != this->getSphere)
				{
					this->worldInterface->barInfoManage(this->getSphere);
				}
			}
			else if (this->cast)
			{
				if (this->selectObject != this->cast)
				{
					this->worldInterface->barInfoManage(this->cast);
				}
			}
		}
		return;
	}

	void World::mouseUpHandler(cocos2d::EventMouse* event)
    {
		if (this->getSphere)
		{
			this->getSphere->mouseUpHandler(event);
		}
		else
		{
			if (this->cast)
			{
				this->cast->mouseUpHandler(event);
				return;
			}
			if (this->towerMenu)
			{
				this->towerMenu->mouseUpHandler(event);
			}
			else if (this->ultraTowerMenu)
			{
				this->ultraTowerMenu->mouseUpHandler(event);
			}
			else if (this->exchange)
			{
				this->exchange->mouseUpHandler(event);
				return;
			}
		}
		if (this->buildTowerMenu) 
			this->buildTowerMenu->mouseUpHandler(event); 
		if(this->decoration)
		    this->decoration->mouseUpHandler(event);
		if (this->worldInterface) 
			this->worldInterface->mouseUpHandler(event); 
		return;
	}// end function


	void World::rightMouseDownHandler(cocos2d::EventMouse* event)
    {
		if (event->target->name == "towerCase")
		{
			if (!this->exchange)
			{
				if (event->target->parent->parent->towerType < 5 && !event->target->parent->parent->blockTowerFlag)
				{
					this->i = 0;
					while (this->i < this->listOfTowers.size())
					{
						if (this->listOfTowers[this->i] != event->target->parent->parent && this->listOfTowers[this->i]->towerType < 5)
						{
							this->mouseMoveHandler(event);
							this->exchange = new Exchange(event->target->parent->parent);
							this->addChild(this->exchange);
							break;
						}
						i++;
					}
				}
			}
			else
			{
				this->exchange->rightMouseDownHandler(event);
			}
		}
		else if (this->exchange)
		{
			this->exchange->rightMouseDownHandler(event);
		}
		else if (this->nowLevel != 1 && !this->getSphere && !this->cast && !this->menuObject)
		{
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstRC"))
			{
				Main::mainClass->saveBoxClass->setValue("firstRC",true);
				//this->menuObject = new Training_10();
				//this->addChild(this->menuObject);
			}
		}
		if (this->getSphere || this->cast)
		{
			this->worldInterface->breaking();
		}
		return;
		// end function
	}

	void World::rightMouseUpHandler(cocos2d::EventMouse* event)
	{
		if (this->exchange)
		{
			this->exchange->rightMouseUpHandler(event);
		}
		return;
	}

	towers::Tower * World::addTower(std::string param1, Sprite *  param2, bool param3)
	{
        towers::Tower * tempObject = NULL;
		if (param1 == "tower1")
		{
			tempObject = new Tower1();
		}
		else if (param1 == "tower2")
		{
			this->tempObject = new Tower2();
		}
		else if (param1 == "tower3")
		{
			this->tempObject = new Tower3();
		}
		else if (param1 == "tower4")
		{
			this->tempObject = new Tower4();
		}
		else if (param1 == "tower5")
		{
			this->tempObject = new Tower5();
		}
		else if (param1 == "tower6")
		{
			this->tempObject = new Tower6();
		}
		else if (param1 == "tower7")
		{
			this->tempObject = new Tower7();
		}
		else if (param1 == "tower8")
		{
			this->tempObject = new Tower8();
		}
		tempObject->myPlace = param2;
		tempObject->autoBuild = param3;
		this->addChild(tempObject);
		this->listOfTowers.push(tempObject);
		//this->listOfTowers.sortOn("y", Array.NUMERIC);
		return tempObject;
	}// end function

	units::Unit * World::addUnit(int param1, int param2, int param3 , float param4 , int param5 , int param6 )
    {
		Unit *tempObject = NULL;
		if (param1 == 1)
		{
			tempObject = new Unit_1();// Unit_1::create();// new Unit_1();
		}
		else if (param1 == 2)
		{
			tempObject = new Unit_2();
		}
		else if (param1 == 3)
		{
			tempObject = new Unit_3();
		}
		else if (param1 == 4)
		{
			tempObject = new Unit_4();
		}
		else if (param1 == 5)
		{
			this->tempObject = new Unit_5();
		}
		else if (param1 == 6)
		{
			this->tempObject = new Unit_6();
		}
		else if (param1 == 7)
		{
			this->tempObject = new Unit_7();
		}
		else if (param1 == 8)
		{
			this->tempObject = new Unit_8();
		}
		else if (param1 == 9)
		{
			this->tempObject = new Unit_9();
		}
		//else if (param1 == 10)
		//{
		//	this->tempObject = new Unit_10();
		//}
		//else if (param1 == 11)
		//{
		//	this->tempObject = new Unit_11();
		//}
		//else if (param1 == 12)
		//{
		//	this->tempObject = new Unit_12();
		//}
		//else if (param1 == 13)
		//{
		//	this->tempObject = new Unit_13();
		//}
		//else if (param1 == 14)
		//{
		//	this->tempObject = new Unit_14();
		//}
		//else if (param1 == 15)
		//{
		//	this->tempObject = new Unit_15();
		//}
		//else if (param1 == 16)
		//{
		//	this->tempObject = new Unit_16();
		//}
		//else if (param1 == 17)
		//{
		//	this->tempObject = new Unit_17();
		//}
		//else if (param1 == 18)
		//{
		//	this->tempObject = new Unit_18();
		//}
		//else if (param1 == 19)
		//{
		//	this->tempObject = new Unit_19();
		//}
		//else if (param1 == 20)
		//{
		//	this->tempObject = new Unit_20();
		//}
		//else if (param1 == 21)
		//{
		//	this->tempObject = new Unit_21();
		//}
		//else if (param1 == 22)
		//{
		//	this->tempObject = new Unit_22();
		//}
		//else if (param1 == 23)
		//{
		//	this->tempObject = new Unit_23();
		//}
		//else if (param1 == 24)
		//{
		//	this->tempObject = new Unit_24();
		//}
		//else if (param1 == 25)
		//{
		//	this->tempObject = new Unit_25();
		//}
		//else if (param1 == 26)
		//{
		//	this->tempObject = new Unit_26();
		//}
		//else if (param1 == 27)
		//{
		//	this->tempObject = new Unit_27();
		//}
		//else if (param1 == 28)
		//{
		//	this->tempObject = new Unit_28();
		//}
		//else if (param1 == 29)
		//{
		//	this->tempObject = new Unit_29();
		//}
		//else if (param1 == 30)
		//{
		//	this->tempObject = new Unit_30();
		//}
		//else if (param1 == 31)
		//{
		//	this->tempObject = new Unit_31();
		//}
		//else if (param1 == 32)
		//{
		//	this->tempObject = new Unit_32();
		//}
		//else if (param1 == 33)
		//{
		//	this->tempObject = new Unit_33();
		//}
		//else if (param1 == 34)
		//{
		//	this->tempObject = new Unit_34();
		//}

		 tempObject->road = param2;
		if (param3 == 0)
		{
			tempObject->way = this->unitInputBezieArr[this->unitInputBezieCounter];
			if (this->unitInputBezieCounter < (this->unitInputBezieArr.size() - 1))
			{
				this->unitInputBezieCounter++;
			}
			else
			{
				this->unitInputBezieCounter = 0;
			}
		}
		else
		{
			tempObject->way = param3;
		}
		tempObject->replacementFlag = param5;
		tempObject->gate = param6;
		tempObject->path = param4;
		this->addChild(tempObject, 2);
		tempObject->init();
		tempObject->setPosition(50, 420);
		return tempObject;
	}

	Bullet * World::addBullet(int param1, Point param2, Object param3, Object param4, float param5 , int param6  )
	{
	    Bullet * tempObject1=NULL;
		if (param1 == 1)
		{
			tempObject1 = new Bullet_1();
		}
		else if (param1 == 2)
		{
			tempObject1 = new Bullet_2();
		}
		else if (param1 == 3)
		{
			tempObject1 = new Bullet_3();
		}
		else if (param1 == 4)
		{
			tempObject1 = new Bullet_4();
		}
		else if (param1 == 5)
		{
			tempObject1 = new Bullet_5();
		}
		else if (param1 == 6)
		{
			tempObject1 = new Bullet_6();
		}
		else if (param1 == 61)
		{
			tempObject1 = new Bullet_61();
		}
		else if (param1 == 7)
		{
			tempObject1 = new Bullet_7();
		}
		else if (param1 == 8)
		{
			tempObject1 = new Bullet_8();
		}
		else if (param1 == 51)
		{
			tempObject1 = new Bullet_51();
		}
		else if (param1 == 81)
		{
			tempObject1 = new Bullet_81();
		}
		tempObject1->spherePower = param6;
		tempObject1->this_pt = param2;
		tempObject1->whoShoot = param3;
		tempObject1->enemyTarget = param4;
		tempObject1->damage = param5;
		this->addChild(tempObject1);
		return tempObject1;
	}// end function

	void World::manageIndexes()
	{
		if (this->frameCounter == 10 || this->frameCounter == 20 || this->frameCounter == 30 || this->forseIndexFl)
		{
			if (this->forseIndexFl)
			{
				this->forseIndexFl = false;
			}
			if (this->listOfIndexes0.size() > 0)
			{
				//this->listOfIndexes0.sortOn(["y", "x"], [Array.NUMERIC, Array.NUMERIC]);
				//this->m = 0;
				//while (this->m < this->listOfIndexes0.size())
				//{ 
				//	this->setChildIndex(this->listOfIndexes0[this->m], (this->numChildren - 1));
				//	m++;
				//}
			}
			this->sortIndex.clear();// = [];
			this->sortIndex = this->sortIndex.concat(this->listOfIndexes1);
			this->sortIndex = this->sortIndex.concat(this->listOfIndexes2);
			this->sortIndex = this->sortIndex.concat(this->listOfTowers);
			this->sortIndex = this->sortIndex.concat(this->listOfUnits);
			this->sortIndex = this->sortIndex.concat(this->listOfFlags);
			if (this->buildTowerMenu)
			{
				this->sortIndex.push(this->buildTowerMenu);
			}
			//this->sortIndex.sortOn(["y", "x"], [Array.NUMERIC, Array.NUMERIC]);
			//this->m = 0;
			//while (this->m < this->sortIndex.size())
			//{ 
			//	this->setChildIndex(this->sortIndex[this->m], (this->numChildren - 1));
			//	m++;
			//}
			if (this->listOfIndexes2.size() > 0)
			{
				this->sortIndex.clear();// = [];
				this->sortIndex = this->sortIndex.concat(this->listOfTowers);
				this->sortIndex = this->sortIndex.concat(this->listOfIndexes2);
				//this->sortIndex.sortOn(["y", "x"], [Array.NUMERIC, Array.NUMERIC]);
				this->indexesTemp1 = NULL;
				this->m = 0;
				while (this->m < this->sortIndex.size())
				{
					if (!(this->sortIndex[this->m] is Tower))
					{
						bool indexesTemp3 = false;
						if (this->sortIndex[this->m] is Bullet)
						{
						    Bullet * bullet=(Bullet*)this->sortIndex[this->m];
							this->n = 0;
							while (this->n < this->listOfTowers.size())
							{
								if (this->listOfTowers[this->n]->getPositionY() > bullet->enemyTarget->getPositionY())
								{
								    indexesTemp3 = true;
									this->setChildIndex(bullet, (this->getChildIndex(this->listOfTowers[this->n]) - 1));
									break;
								}
								n++;
							}
							if (!indexesTemp3)
							{
								this->setChildIndex(bullet, (this->numChildren - 1));
							}
						}
						else
						{
							if (this->sortIndex[this->m] is CastSphere)
							{
							    CastSphere * castSphere=(CastSphere*)this->sortIndex[this->m];
								if (this->sortIndex[this->m]->sphereType == "getAll" && this->sortIndex[this->m]->container->haze1)
								{
									indexesTemp3 = true;
									tempObject4 = false;
									this->n = 0;
									while (this->n < this->listOfTowers.size())
									{ 
										int tempObject5 = 0;
										if (castSphere->container->haze1->isVisible() && this->listOfTowers[this->n]->getPositionY() > this->sortIndex[this->m]->container->haze1->myPoint.y + 30)
										{
											tempObject5++;
										}
										if (castSphere->container->haze2->isVisible() && this->listOfTowers[this->n]->getPositionY() > this->sortIndex[this->m]->container->haze2->myPoint.y + 30)
										{
											tempObject5++;
										}
										if (castSphere->container->haze3->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze3->myPoint.y + 30)
										{
											tempObject5++;
										}
										if (castSphere->container->haze4->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze4->myPoint.y + 30)
										{
											tempObject5++;
										}
										if (castSphere->container->haze5->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze5->myPoint.y + 30)
										{
											tempObject5++;
										}
										if (castSphere->container->haze6->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze6->myPoint.y + 30)
										{
											tempObject5++;
										}
										if (castSphere->container->haze7->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze7->myPoint.y + 30)
										{
											tempObject5++;
										}
										if (castSphere->container->haze8->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze8->myPoint.y + 30)
										{
											tempObject5++;
										}
										if (castSphere->container->haze9->isVisible() && this->listOfTowers[this->n]->getPositionY() > castSphere->container->haze9->myPoint.y + 30)
										{
											tempObject5++;
										}
										if (tempObject5 >= 3)
										{
											thistempObject4 = true;
											this->setChildIndex(castSphere, (this->getChildIndex(this->listOfTowers[this->n]) - 1));
											break;
										}
										n++;
									}
									if (!tempObject4)
									{
										this->setChildIndex(castSphere, (this->numChildren - 1));
									}
								}
							}
							if (!indexesTemp3)
							{
								this->n = 0;
								while (this->n < this->listOfTowers.size())
								{
									if (this->listOfTowers[this->n]->getPositionY() > this->sortIndex[this->m]->y)
									{
										indexesTemp3 = true;
										this->setChildIndex(this->sortIndex[this->m], (this->getChildIndex(this->listOfTowers[this->n]) - 1));
										break;
									}
									n++;
								}
								if (!this->indexesTemp3)
								{
									this->setChildIndex(this->sortIndex[this->m], (this->numChildren - 1));
								}
							}
						}
					}
					m++;
				}
			}
		}
		if (this->nowLevel == 15)
		{
			if (this->levelAdditionally1->currentFrame != this->levelAdditionally1->totalFrames)
			{
				this->setChildIndex(this->levelAdditionally1, (this->numChildren - 1));
			}
			this->setChildIndex(this->levelAdditionally3, (this->numChildren - 1));
		}
		if (this->towerRadius->isVisible())
		{
			this->setChildIndex(this->towerRadius, (this->numChildren - 1));
		}
		if (this->listOfIndexes3.size() > 0)
		{
			this->m = 0;
			while (this->m < this->listOfIndexes3.size())
			{
				this->setChildIndex(this->listOfIndexes3[this->m], (this->numChildren - 1));
				m++;
			}
		}
		this->setChildIndex(this->pointer1, (this->numChildren - 1));
		if (this->pointer2)
		{
			this->setChildIndex(this->pointer2, (this->numChildren - 1));
		}
		if (this->pointer3)
		{
			this->setChildIndex(this->pointer3, (this->numChildren - 1));
		}
		this->setChildIndex(this->worldInterface, (this->numChildren - 1));
		if (this->road->isVisible())
		{
			this->setChildIndex(this->road, (this->numChildren - 1));
		}
		if (this->towerMenu)
		{
			this->setChildIndex(this->towerMenu->towerRadius, (this->numChildren - 1));
			this->setChildIndex(this->towerMenu->towerRadius1, (this->numChildren - 1));
			this->setChildIndex(this->towerMenu, (this->numChildren - 1));
			this->setChildIndex(this->towerMenu->hint, (this->numChildren - 1));
		}
		else if (this->ultraTowerMenu)
		{
			this->setChildIndex(this->ultraTowerMenu, (this->numChildren - 1));
			this->setChildIndex(this->ultraTowerMenu->hint, (this->numChildren - 1));
		}
		this->m = 0;
		while (this->m < this->listOfMoveSpheres.size())
		{
			this->setChildIndex(this->listOfMoveSpheres[this->m], (this->numChildren - 1));
			m++;
		}
		if (this->getSphere)
		{
			this->setChildIndex(this->getSphere, (this->numChildren - 1));
		}
		if (this->cast)
		{
			this->setChildIndex(this->cast, (this->numChildren - 1));
		}
		if (this->exchange)
		{
			this->setChildIndex(this->exchange->graphicAtMyTower, (this->numChildren - 1));
			this->setChildIndex(this->exchange, (this->numChildren - 1));
		}
		if (this->bezierClass)
		{
			if (this->bezierClass->isVisible())
			{
				this->setChildIndex(this->bezierClass, (this->numChildren - 1));
				this->bezierClass.updateLine();
			}
		}
		if (this->trainingClass)
		{
			this->setChildIndex(this->trainingClass, (this->numChildren - 1));
		}
		this->setChildIndex(this->hint, (this->numChildren - 1));
		if (this->menuObject)
		{
			this->setChildIndex(this->menuObject, (this->numChildren - 1));
		}
		return;
	}// end function 
	
	void manageMouse(string param1)
	{
		if (param1 == "hide")
		{
			//Mouse.hide();
		}
		else if (param1 == "show")
		{
			//Mouse.show();
		}
		return;
	}// end function


	void World::manageListeners(string param1)
	{
		if (param1 == "on")
		{
			//this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
			//this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
			//this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
			//this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
			//this->addEventListener(MouseEvent.RIGHT_MOUSE_DOWN, this->rightMouseDownHandler);
			//this->addEventListener(MouseEvent.RIGHT_MOUSE_UP, this->rightMouseUpHandler);
			//if (this->saveBox.gameSave.data.autoPause)
			//{
			//	this->addEventListener(Event.DEACTIVATE, this->deactivateHandler);
			//}
		}
		else if (param1 == "off")
		{
			//this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
			//this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
			//this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
			//this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
			//this->removeEventListener(MouseEvent.RIGHT_MOUSE_DOWN, this->rightMouseDownHandler);
			//this->removeEventListener(MouseEvent.RIGHT_MOUSE_UP, this->rightMouseUpHandler);
			//this->removeEventListener(Event.DEACTIVATE, this->deactivateHandler);
		}
		return;
	}// end function
	void deactivateHandler(cocos2d::EventMouse* event)
	{
		if (this->saveBox->getIntValue("complexityLevel") < 4)
		{
			if (this->wavesClass->nowWave > 0 && !this->menuObject)
			{
				this->worldInterface->addFastPause();
			}
		}
		else if (!this->menuObject)
		{
			this->worldInterface->addFastPause();
		}
		//return;
	}// end function

	void World::achieveManage(string param1)
	{
	    string key="achieve_"+param1;
	    bool value=this->saveBox->getBoolValue(key);
	    if(value)return; 
        if (!this->saveBox->getBoolValue(key))
		{
			this->saveBox->setValue(key,true);
			this->worldInterface->addGetAchieve(param1);
		} 
	    return;
	    
		if (param1 == "firstKill")
		{ 
			//if (Main::mainClass->IDIClass.idnet)
			//{
			//	if (Main::mainClass->IDIClass.idnet.userData)
			//	{
			//		Main::mainClass->IDIClass.idnet.achievementsSave("第一滴血", "83409581c3f54d89fab5", String(Main::mainClass->IDIClass.currentUser));
			//	}
			//} 
		}
		else if (param1 == "kill_100_enemies")
		{ 
			//if (Main::mainClass->IDIClass.idnet)
			//{
			//	if (Main::mainClass->IDIClass.idnet.userData)
			//	{
			//		Main::mainClass->IDIClass.idnet.achievementsSave("热烈无比", "ccff354b538ba9d981c6", String(Main::mainClass->IDIClass.currentUser));
			//	}
			//} 
		}
		else if (param1 == "kill_2500_enemies")
		{ 
			//if (Main::mainClass->IDIClass.idnet)
			//{
			//	if (Main::mainClass->IDIClass.idnet.userData)
			//	{
			//		Main::mainClass->IDIClass.idnet.achievementsSave("杀手", "11963b14f22a7bce56b1", String(Main::mainClass->IDIClass.currentUser));
			//	}
			//} 
		}
		else if (param1 == "call_100_earlyWaves")
		{ 
			//if (Main::mainClass->IDIClass.idnet)
			//{
			//	if (Main::mainClass->IDIClass.idnet.userData)
			//	{
			//		Main::mainClass->IDIClass.idnet.achievementsSave("毫无畏惧", "9505fe07aec600010632", String(Main::mainClass->IDIClass.currentUser));
			//	}
			//} 
		}
		else if (param1 == "build_100_towers")
		{ 
			//if (Main::mainClass->IDIClass.idnet)
			//{
			//	if (Main::mainClass->IDIClass.idnet.userData)
			//	{
			//		Main::mainClass->IDIClass.idnet.achievementsSave("建造者", "45b808416d58aa9ec362", String(Main::mainClass->IDIClass.currentUser));
			//	}
			//} 
		}
		else if (param1 == "createGolem_5_times")
		{ 
			//if (Main::mainClass->IDIClass.idnet)
			//{
			//	if (Main::mainClass->IDIClass.idnet.userData)
			//	{
			//		Main::mainClass->IDIClass.idnet.achievementsSave("巨型支援", "4933337d00fe765e2d76", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("缓和", "7cb9e2506e2cff60188e", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("远古支援", "eae07af8c3fbf6969aaa", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("大胆", "29337500f9599ccc64dc", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("破坏者", "ae6966c4ffcbf75ff494", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("火焰破坏者", "de7be8dc61d39246d6d0", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("寒冰破坏者", "1f24299530577258bbf6", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("巨石破坏者", "3c5c886f47920ec924d1", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("闪电破坏者", "6b63e564bf6e744f8e78", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("粉碎者", "052b407c061f43d90593", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("有点冷", "cd3fd0815ded9b849e6d", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("霜冻力量", "1c64fdbcbc270a0aa41c", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("进阶建造者", "955bdd689299e80fb0ae", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("专家建造者", "9a578115947a76ccdc7a", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("策略建造者", "225f541c6876ebd07590", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("上手", "81cb72a77902ea9d9e8a", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("火焰大师", "d622abbd1bed287c5680", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("寒冰大师", "7484bbb391fe85f8bfd2", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("岩石大师", "7658bfe01730e286ab12", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("闪电大师", "57af93676b7cc1bd8d7a", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("策略爆破者", "0400fd8ee26fc4e6111e", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("爆破者", "252127936ed8d209e5d8", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("施法者", "06235f228a30f51541a2", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("法术杀手", "28108715890214c48efe", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("勇猛战士", "7e8c5c8fda54a7f755a5", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("幸存者", "5252af2b31911dfec2ca", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("活力四射", "be199456485a296baa27", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("伐木工", "e52e865a96cad6434c71", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("忙忙碌碌", "fbe8c2abc522477828ab", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("南瓜节", "de48d1b211ea73656394", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("修理工", "5e33b77fe8788d480d4d", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("勇士", "0b08fac999ba500f9e56", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("睡眼阑珊", "28324f0179eb9d4a0c29", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("超级女声", "8ec85ce03c6475fbcc58", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("老烟枪", "aee2716c8d18fa744acd", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("渔夫", "59cb9735aadd73823c6b", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("决斗", "26fa27c7ac79a9ff0dbb", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("萨满", "25188a8e66ef59bf2504", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("疯狂射手", "b79f6ade296b72ea2d3c", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("勇猛大头", "1d2c8f2227466dde4a7b", String(Main::mainClass->IDIClass.currentUser));
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
		//				Main::mainClass->IDIClass.idnet.achievementsSave("寻路无门", "1529e481b9b5e124cba2", String(Main::mainClass->IDIClass.currentUser));
		//			}
		//		}
		//	}
		//}
		//return;
	}// end function

	void World::reInit(cocos2d::EventMouse*event)//event:Event
	{
		//this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
		//this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
		//this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
		//this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
		//this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
		//this->removeEventListener(Event.DEACTIVATE, this->deactivateHandler);
		//return;
	}// end function

}

