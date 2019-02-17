#include "Feature.h"
#include "bezier/Bezier.h"
#include "bezier/PathPoint.h"  
#include "engine/Waves.h"
#include "sys/saveBox.h"

#include "MainClass.h"
#include "World.h"
#include "engine/WorldInterface.h"

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
#include "engine/level/Level.h"
#include "engine/level/Level1_mc.h"


namespace engine
{
	Feature::Feature() :autoAddTowerCounter(30)
	{
		this->world = Main::mainClass->worldClass;
		this->world->nowLevel = Main::mainClass->saveBoxClass->playLevel;
		this->world->saveBox = Main::mainClass->saveBoxClass;
		if (this->world->nowLevel == 1)
		{
			this->world->level = new  Level1_mc(this->world);
			//this->world->decoration = new decoration::DecorationLevel1();
			this->world->levelType = "grass";
			int firstViewTowerIdx = 0;
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstViewTowers", firstViewTowerIdx))
				Main::mainClass->saveBoxClass->setValue("firstViewTowers", firstViewTowerIdx, true);
		}
		else if (this->world->nowLevel == 2)
		{
			this->world->level = new  Level2_mc(this->world);
 			//this->world->decoration = new DecorationLevel2();
			this->world->levelType = "grass";
			int firstViewTowerIdx = 1;
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstViewTowers", firstViewTowerIdx))
				Main::mainClass->saveBoxClass->setValue("firstViewTowers", firstViewTowerIdx, true);
		}
		else if (this->world->nowLevel == 3)
		{
			this->world->level = new  Level3_mc(this->world); 
			//this->world->road = new RoadLevel3_mc();
			//this->world->decoration = new DecorationLevel3();
			this->world->levelType = "grass";
			int firstViewTowerIdx = 2;
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstViewTowers", firstViewTowerIdx))
				Main::mainClass->saveBoxClass->setValue("firstViewTowers", firstViewTowerIdx, true);
		}
		else if (this->world->nowLevel == 4)
		{
			this->world->level = new  Level4_mc(this->world);
			//this->world->decoration = new DecorationLevel4();
			this->world->levelType = "grass";
			int firstViewTowerIdx = 3;
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstViewTowers", firstViewTowerIdx))
				Main::mainClass->saveBoxClass->setValue("firstViewTowers", firstViewTowerIdx, true);
		}
		else if (this->world->nowLevel == 5)
		{
			this->world->level = new  Level5_mc(this->world);
			//this->world->decoration = new DecorationLevel5();
			this->world->levelType = "grass";
		}
		else if (this->world->nowLevel == 6)
		{
			this->world->level = new  Level6_mc(this->world);
			//this->world->road = new RoadLevel6_mc();
			//this->world->decoration = new DecorationLevel6();
			this->world->levelType = "grass";
			int firstViewTowerIdx = 4;
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstViewTowers", firstViewTowerIdx))
				Main::mainClass->saveBoxClass->setValue("firstViewTowers", firstViewTowerIdx, true);
		}
		else if (this->world->nowLevel == 7)
		{ 
			this->world->level = new  Level7_mc(this->world);
			//this->world->road = new RoadLevel7_mc();
			//this->world->decoration = new DecorationLevel7();
			this->world->levelType = "grass";
			int firstViewTowerIdx = 5;
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstViewTowers", firstViewTowerIdx))
				Main::mainClass->saveBoxClass->setValue("firstViewTowers", firstViewTowerIdx, true);
		}
		else if (this->world->nowLevel == 8)
		{
			this->world->level = new  Level8_mc(this->world); 
			//this->world->road = new RoadLevel8_mc();
			//this->world->decoration = new DecorationLevel8();
			this->world->levelType = "dust";
		}
		else if (this->world->nowLevel == 9)
		{
			this->world->level = new  Level9_mc(this->world);
			//this->world->road = new RoadLevel9_mc();
			//this->world->decoration = new DecorationLevel9();
			this->world->levelType = "grass";
			int firstViewTowerIdx = 6;
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstViewTowers", firstViewTowerIdx))
				Main::mainClass->saveBoxClass->setValue("firstViewTowers", firstViewTowerIdx, true);
 		}
		else if (this->world->nowLevel == 10)
		{
			this->world->level = new  Level10_mc(this->world);
			//this->world->road = new RoadLevel10_mc();
			//this->world->decoration = new DecorationLevel10();
			this->world->levelType = "dust";
		}
		else if (this->world->nowLevel == 11)
		{
			this->world->level = new  Level11_mc(this->world);
 			//this->world->decoration = new DecorationLevel11();
			this->world->levelType = "dust";
			int firstViewTowerIdx = 7;
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstViewTowers", firstViewTowerIdx))
				Main::mainClass->saveBoxClass->setValue("firstViewTowers", firstViewTowerIdx, true);
		}
		else if (this->world->nowLevel == 12)
		{
			this->world->level = new Level12_mc(this->world);
			//this->world->road = new RoadLevel12_mc();
			//this->world->decoration = new DecorationLevel12();
			this->world->levelType = "dust";
		}
		else if (this->world->nowLevel == 13)
		{
			this->world->level = new Level13_mc(this->world);
			//this->world->road = new RoadLevel13_mc();
			//this->world->decoration = new DecorationLevel13();
			this->world->levelType = "dust";
		}
		else if (this->world->nowLevel == 14)
		{
			this->world->level = new Level14_mc(this->world);
			//this->world->road = new RoadLevel14_mc();
			//this->world->decoration = new DecorationLevel14();
			this->world->levelType = "dust";
		}
		else if (this->world->nowLevel == 15)
		{
			this->world->level = new Level15_mc(this->world);
			//this->world->road = new RoadLevel15_mc();
			//this->world->decoration = new DecorationLevel15();
			this->world->levelType = "dust";
		}
		this->world->addChild(this->world->level);
		this->world->level->setPos();
		//for (size_t i = 0; i < this->world->level->flags.size(); i++)
		//{
		//	MovieClip * arma=this->world->level->flags.at(i);
		//	//this->world->addChild(arma); 
		//	arma->play(0);// getAnimation()->play();
		//	arma->setVisible(true);
		//}
		//for (size_t i = 0; i < this->world->level->additionallys.size(); i++)
		//{
		//	//MovieClipSub * arma = this->world->level->additionallys.at(i);
		//	//this->world->addChild(arma);
		//}
		//for (size_t i = 0; i < this->world->level->places.size(); i++)
		//{
		//	//dragonBones::DBCCArmatureNode * arma = this->world->level->places.at(i);
		//	//this->world->addChild(arma);
		//}

		//this->world->level->stop();
		for (int i = 0; i < world->level->flags.size(); i++)
		{
			MovieClip *flag = world->level->flags.at(i);
			flag->gotoAndStop((::round(std::random() * (flag->totalFrames - 1)) + 1));
			flag->play("", 0);
			//world->listOfFlags.push_back(world->level->flags.at(i));
		}
		for (int i = 0; i < world->level->additionallys.size(); i++)
		{
			MovieClipSub *place = world->level->additionallys.at(i);
			if (i == 0)
				this->world->levelAdditionally = world->level->additionallys.at(i);
			else if (i == 1)
				this->world->levelAdditionally1 = world->level->additionallys.at(i);
			else if (i == 2)
				this->world->levelAdditionally2 = world->level->additionallys.at(i);
			else if (i == 3)
				this->world->levelAdditionally3 = world->level->additionallys.at(i);
		}
		for (int i = 0; i < world->level->places.size(); i++)
		{
			BuildTowerPlace *place = world->level->places.at(i);
			place->placeForBuildCase->setMouseEnabled(true);
			world->listOfPlaces.push_back(world->level->places.at(i));
		}

		//this->world->map = new Map();
		this->world->towerRadius = new TowerRadius_mc();
		//this->world->towerRadius->stop(); 
		this->world->towerRadius->setMouseChildren(false);
		this->world->towerRadius->mouseEnabled = false;
		this->world->towerRadius->setVisible(false);
		this->world->addChild(this->world->towerRadius,4);
		//std::setAnchorPoint(this->world->towerRadius, 0.5, 0.5);

		//this->world->quality = this->world->saveBox->getStringValue("quality");
		//if (quality == "low")
		//{
		//	this->world->quality = "low";
		//}
		//else if (this->world->saveBox->gameSave.data.quality == "medium")
		//{
		//	this->world->quality = "medium";
		//}
		//else if (this->world->saveBox->gameSave.data.quality == "high")
		//{
		//	this->world->quality = "high";
		//}
		int levelPointerSize = this->world->level->pointers.size();
		for (int i = 0; i < levelPointerSize; i++)
		{
			LevelPointer * pointer = this->world->level->pointers[i];
			pointer->retain();
			pointer->statusAnima = 1;
			pointer->myPoint = cocos2d::Point(pointer->getPosition());
			pointer->gotoAndStop(2);
			//pointer->mask2->stop();
			//pointer->arrow->stop();
			pointer->fireAnima->gotoAndStop(1);
			pointer->eyesAnima->gotoAndStop(1);
			//std::changeAnchorPoint(pointer->mask2,Vec2(1,0.5));
			//pointer->getArmature()->getBone("mask2")->offset.rotation=180;
			//pointer->mask2->setRotation(180);
			pointer->pointerCase->setMouseEnabled(true);
			Vec2 pos = CONVERT_TO_WORLD_POS(pointer->display->convertToWorldSpace(pointer->getPosition()));
			pointer->display->removeChild(pointer,false);
			//this->world->level->removeChild(pointer);
			this->world->addChild(pointer,5);
			pointer->setPosition(pos);
			//pointer->pointerCase->enableMouseHandler(useNodeEvent);
			//this->world->adIndexes(this->world->pointer1,3); 
			pointer->setScaleY(0.9f);
			pointer->setScaleX(0.9f);
			pointer->setVisible(false);
			float tempObject = pointer->getRotation();
			pointer->setRotation(0);
			pointer->arrow->setRotation(tempObject);

			pointer->release();
		}

		if (levelPointerSize > 0 && this->world->level->pointers[0])
		{
			this->world->pointer1 = this->world->level->pointers[0];// pointer1; 
		}
		if (levelPointerSize > 1 && this->world->level->pointers[1])//this->world->level.pointer2)
		{
			this->world->pointer2 = this->world->level->pointers[1];// pointer2; 
		}
		if (levelPointerSize > 2 && this->world->level->pointers[2])//this->world->level.pointer3)
		{
			this->world->pointer3 = this->world->level->pointers[2];// pointer3; 
		}



		int complexityLevel = this->world->saveBox->getIntValue("complexityLevel");
		Common::String levelXmlFile = "xml/";
		if (complexityLevel < 4)
			levelXmlFile += "levels";
		else
			levelXmlFile = "levelsSurvival";
		levelXmlFile += "/level";
		levelXmlFile += this->world->nowLevel;
		levelXmlFile += ".xml";
		Main::mainClass->readXMLClass.loadXMLLevels(levelXmlFile);

		//if (this->world->nowLevel == 1)
		//{
		//	if (complexityLevel< 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level1.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level1.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 2)
		//{
		//	if (complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level2.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level2.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 3)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level3.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level3.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 4)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level4.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level4.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 5)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level5.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level5.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 6)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level6.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level6.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 7)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level7.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level7.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 8)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level8.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level8.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 9)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level9.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level9.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 10)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level10.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level10.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 11)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level11.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level11.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 12)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level12.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level12.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 13)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level13.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level13.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 14)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level14.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level14.xml");
		//	}
		//}
		//else if (this->world->nowLevel == 15)
		//{
		//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levels/level15.xml");
		//	}
		//	else
		//	{
		//		Main::mainClass->readXMLClass.loadXMLLevels("levelsSurvival/level15.xml");
		//	}
		//}


		this->world->hint = new Hint_mc();
		this->world->hint->stop();
		this->world->hint->setMouseChildren(false);
		this->world->hint->mouseEnabled = false;
		this->world->hint->setVisible(false);
		this->world->addChild(this->world->hint,3);
		this->afterLoadXML();
		
		//this->world->road->armature->getAnimation()->stop(); 
		//this->world->road->armature->setName("road");
		//this->world->road->setAlpha(0);
		//this->world->road->setVisible(false);// visible = false;
		
        this->world->road = new  RoadLevels_mc(this->world->nowLevel);
		this->world->addChild(this->world->road,4); 
		this->world->road->init();
		//this->world->road->setPosition(this->world->road->initPos);
		//this->world->logInfo("this->world->road->getPosition",this->world->road->getPosition());


	}// end function

	void   Feature::update(float dt)
	{
		if (this->world->getSphere)
		{
			this->world->getSphere->update();
		}
		int complexityLevel = this->world->saveBox->getIntValue("complexityLevel");
		this->listOfMoveSpheres();
		this->i = 1;
		while (this->i <= 3)
		{
			LevelPointer * tempObject = NULL;
			if (this->i == 1)
			{
				tempObject = this->world->pointer1;
			}
			else if (this->i == 2)
			{
				if (this->world->pointer2)
				{
					tempObject = this->world->pointer2;
				}
				else
				{
					break;
				}
			}
			else if (this->i == 3)
			{
				if (this->world->pointer3)
				{
					tempObject = this->world->pointer3;
				}
				else
				{
					break;
				}
			}
			if (tempObject->isVisible())
			{
 				tempObject->fireAnima->tryPlay(); 
				//if (tempObject->fireAnima->currentFrame < tempObject->fireAnima->totalFrames)
				//	tempObject->fireAnima->gotoAndStop((tempObject->fireAnima->currentFrame + 1));
				//else
				//	tempObject->fireAnima->gotoAndStop(1); 
				tempObject->eyesAnima->tryPlay();
				//if (tempObject->eyesAnima->currentFrame < tempObject->eyesAnima->totalFrames)
				//	tempObject->eyesAnima->gotoAndStop((tempObject->eyesAnima->currentFrame + 1));
				//else
				//	tempObject->eyesAnima->gotoAndStop(1);
				if (!tempObject->mouseEnabled)
				{
					if (tempObject->getScaleX() > 0)
					{
						tempObject->setScaleX(tempObject->getScaleX() - 0.2);
						tempObject->setScaleY(tempObject->getScaleY() - 0.2);
					}
					if (tempObject->getScaleX() <= 0)
					{
						this->world->pointer1->gotoAndStop(1);
						this->world->pointer1->mask1->setRotation(-180);
						this->world->pointer1->mask2->setRotation(0);
						this->world->pointer1->setScaleY(0);
						this->world->pointer1->setScaleX(0);
						this->world->pointer1->setMouseChildren(true);
						this->world->pointer1->setMouseEnabled(true);
						this->world->pointer1->setVisible(false);
						this->world->pointer1->mouseMoveFlag = false;
						this->world->pointer1->statusAnima = 1;
						if (this->world->pointer2)
						{
							this->world->pointer2->gotoAndStop(1);
							this->world->pointer2->mask1->setRotation(-180);
							this->world->pointer2->mask2->setRotation(0);
							this->world->pointer2->setScaleY(0);
							this->world->pointer2->setScaleX(0);
							this->world->pointer2->setMouseChildren(true);
							this->world->pointer2->setMouseEnabled(true);
							this->world->pointer2->setVisible(false);
							this->world->pointer2->mouseMoveFlag = false;
							this->world->pointer2->statusAnima = 1;
						}
						if (this->world->pointer3)
						{
							this->world->pointer3->gotoAndStop(1);
							this->world->pointer3->mask1->setRotation(-180);
							this->world->pointer3->mask2->setRotation(0);
							this->world->pointer3->setScaleY(0);
							this->world->pointer3->setScaleX(0);
							this->world->pointer3->setMouseChildren(true);
							this->world->pointer3->setMouseEnabled(true);
							this->world->pointer3->setVisible(false);
							this->world->pointer3->mouseMoveFlag = false;
							this->world->pointer3->statusAnima = 1;
						}
					}
				}
				else if (tempObject->statusAnima == 1)
				{
					if (tempObject->getScaleX() + 0.2 < 1.1)
					{
						tempObject->setScaleX(tempObject->getScaleX() + 0.2);
						tempObject->setScaleY(tempObject->getScaleY() + 0.2);
					}
					else
					{
						tempObject->statusAnima = 2;
					}
				}
				else if (tempObject->statusAnima == 2)
				{
					if (tempObject->getScaleX() - 0.2 > 0.9)
					{
						tempObject->setScaleX(tempObject->getScaleX() - 0.2);
						tempObject->setScaleY(tempObject->getScaleY() - 0.2);
					}
					else
					{
						tempObject->statusAnima = 0;
						tempObject->setScaleY(1);
						tempObject->setScaleX(1);
						if (this->world->wavesClass->nowWave == 1)
						{
							if (this->world->nowLevel == 1)
							{
								if (complexityLevel < 4)
								{
									//if (!this->world->trainingClass)
									//{
									//	this->world->trainingClass = new Training_6();
									//	this->world->addChild(this->world->trainingClass);
									//}
								}
							}
						}
					}
				}
				else if (tempObject->mouseMoveFlag)
				{
					if (tempObject->getScaleX() < 1)
					{
						tempObject->setScaleX(tempObject->getScaleX() + 0.05);
						tempObject->setScaleY(tempObject->getScaleY() + 0.05);
					}
				}
				else if (tempObject->getScaleX() > 0.9)
				{
					tempObject->setScaleX(tempObject->getScaleX() - 0.05);
					tempObject->setScaleY(tempObject->getScaleY() - 0.05);
					if (tempObject->getScaleX() < 0.9)
					{
						tempObject->setScaleY(0.9f);
						tempObject->setScaleX(0.9f);
					}
				}
			}
			i++;
		}

		if (this->autoAddTowerCounter > 0)
		{
			this->autoAddTowerCounter--;
			if (this->autoAddTowerCounter == 0)
			{
				if (complexityLevel == 4)
				{
					if (this->world->nowLevel == 3)
					{
						AudioUtil::playSoundWithVol("Snd_tower_build.mp3", 0.95f);
						this->i = 0;
						while (this->i < this->world->listOfPlaces.size())
						{
							//if (this->world->listOfPlaces[this->i]->getName() == "place1" || this->world->listOfPlaces[this->i]->getName() == "place2" || this->world->listOfPlaces[this->i]->getName() == "place4" || this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place8")
							//{
							//	this->world->listOfPlaces[this->i]->gotoAndStop(2);
							//	this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
							//	tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
							//	tempObject->container->towerCase->mouseEnabled = false;
							//	tempObject->container->boneBlock->setVisible(true);
							//}
							//else if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place6" || this->world->listOfPlaces[this->i]->getName() == "place7")
							//{
							//	this->world->listOfPlaces[this->i]->gotoAndStop(2);
							//	this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
							//	tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
							//}
							i++;
						}
					}
					else if (this->world->nowLevel == 5)
					{
						AudioUtil::playSoundWithVol("Snd_tower_build.mp3", 0.95f);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.size())
						//{
						//	if (this->world->listOfPlaces[this->i]->getName() == "place4")
						//	{
						//		this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//		this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//		tempObject = this->world->addTower("tower5", this->world->listOfPlaces[this->i], true);
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 7)
					{
						AudioUtil::playSoundWithVol("Snd_tower_build.mp3", 0.95f);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.size())
						//{
						//	if (this->world->listOfPlaces[this->i]->getName() == "place1" || this->world->listOfPlaces[this->i]->getName() == "place2" || this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place6" || this->world->listOfPlaces[this->i]->getName() == "place8")
						//	{
						//		this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//		this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//		tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//		tempObject->container->towerCase->mouseEnabled = false;
						//		tempObject->container->boneBlock->setVisible(true);
						//	}
						//	else if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place7")
						//	{
						//		this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//		this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//		tempObject = this->world->addTower("tower5", this->world->listOfPlaces[this->i], true);
						//	}
						//	else if (this->world->listOfPlaces[this->i]->getName() == "place4" || this->world->listOfPlaces[this->i]->getName() == "place9")
						//	{
						//		this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//		this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//		tempObject = this->world->addTower("tower6", this->world->listOfPlaces[this->i], true);
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 9)
					{
						AudioUtil::playSoundWithVol("Snd_tower_build.mp3", 0.95f);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.size())
						//{
						//	if (this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place10")
						//	{
						//		this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//		this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//		tempObject = this->world->addTower("tower7", this->world->listOfPlaces[this->i], true);
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 10)
					{
						AudioUtil::playSoundWithVol("Snd_tower_build.mp3", 0.95f);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.size())
						//{
						//	if (this->world->listOfPlaces[this->i]->getName() == "place1" || this->world->listOfPlaces[this->i]->getName() == "place2" || this->world->listOfPlaces[this->i]->getName() == "place8" || this->world->listOfPlaces[this->i]->getName() == "place10")
						//	{
						//		this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//		this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//		tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//		tempObject->container->towerCase->mouseEnabled = false;
						//		tempObject->container->boneBlock->setVisible(true);
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 11)
					{
						AudioUtil::playSoundWithVol("Snd_tower_build.mp3", 0.95f);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.size())
						//{
						//	if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place4" || this->world->listOfPlaces[this->i]->getName() == "place8" || this->world->listOfPlaces[this->i]->getName() == "place10")
						//	{
						//		this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//		this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//		tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//		tempObject->container->towerCase->mouseEnabled = false;
						//		tempObject->container->boneBlock->setVisible(true);
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 14)
					{
						AudioUtil::playSoundWithVol("Snd_tower_build.mp3", 0.95f);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.size())
						//{
						//	if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place8" || this->world->listOfPlaces[this->i]->getName() == "place10")
						//	{
						//		this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//		this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//		tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//		tempObject->container->towerCase->mouseEnabled = false;
						//		tempObject->container->boneBlock->setVisible(true);
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 15)
					{
						AudioUtil::playSoundWithVol("Snd_tower_build.mp3", 0.95f);
						//	this->i = 0;
						//	while (this->i < this->world->listOfPlaces.size())
						//	{
						//		if (this->world->listOfPlaces[this->i]->getName() == "place1" || this->world->listOfPlaces[this->i]->getName() == "place6" || this->world->listOfPlaces[this->i]->getName() == "place10" || this->world->listOfPlaces[this->i]->getName() == "place15")
						//		{
						//			this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//			this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//			tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			tempObject->container->towerCase->mouseEnabled = false;
						//			tempObject->container->boneBlock->setVisible(true);
						//		}
						//		else if (this->world->listOfPlaces[this->i]->getName() == "place2" || this->world->listOfPlaces[this->i]->getName() == "place14")
						//		{
						//			this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//			this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//			tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			tempObject->spheresManage("push", "fire", 4);
						//		}
						//		else if (this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place11")
						//		{
						//			this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//			this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//			tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			tempObject->spheresManage("push", "ice", 4);
						//		}
						//		else if (this->world->listOfPlaces[this->i]->getName() == "place4" || this->world->listOfPlaces[this->i]->getName() == "place13")
						//		{
						//			this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//			this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//			tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			tempObject->spheresManage("push", "stone", 4);
						//		}
						//		else if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place12")
						//		{
						//			this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//			this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//			tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			tempObject->spheresManage("push", "levin", 4);
						//		}
						//		else if (this->world->listOfPlaces[this->i]->getName() == "place7" || this->world->listOfPlaces[this->i]->getName() == "place8" || this->world->listOfPlaces[this->i]->getName() == "place9")
						//		{
						//			this->world->listOfPlaces[this->i]->gotoAndStop(2);
						//			this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
						//			tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//		}
						//		i++;
						//	}
					}
				}
			}
		}
	}// end function


	void Feature::listOfMoveSpheres()
	{
		this->i = this->world->listOfMoveSpheres.size() - 1;
		while (this->i >= 0)
		{
			if (this->world->listOfMoveSpheres[this->i]->speedFrame > 0)
			{
				this->world->listOfMoveSpheres[this->i]->speedFrame--;
				this->world->listOfMoveSpheres[this->i]->setAlpha(this->world->listOfMoveSpheres[this->i]->getAlpha() - 0.1);
				this->world->listOfMoveSpheres[this->i]->setPositionX(this->world->listOfMoveSpheres[this->i]->getPositionX() + this->world->listOfMoveSpheres[this->i]->speedX);
				this->world->listOfMoveSpheres[this->i]->setPositionY(this->world->listOfMoveSpheres[this->i]->getPositionY() + this->world->listOfMoveSpheres[this->i]->speedY);
				this->world->listOfMoveSpheres[this->i]->update();
			}
			else
			{
				if (this->world->listOfMoveSpheres[this->i]->ownerType == "archive")
				{
					if (this->world->listOfMoveSpheres[this->i]->fireCount > 0 && this->world->listOfMoveSpheres[this->i]->iceCount == 0 && this->world->listOfMoveSpheres[this->i]->stoneCount == 0 && this->world->listOfMoveSpheres[this->i]->levinCount == 0)
					{
						while (this->world->listOfMoveSpheres[this->i]->fireCount > 0)
						{
							this->world->listOfMoveSpheres[this->i]->fireCount--;
							this->world->worldInterface->archiveManage("push", "fire");
						}
					}
					else if (this->world->listOfMoveSpheres[this->i]->fireCount == 0 && this->world->listOfMoveSpheres[this->i]->iceCount > 0 && this->world->listOfMoveSpheres[this->i]->stoneCount == 0 && this->world->listOfMoveSpheres[this->i]->levinCount == 0)
					{
						while (this->world->listOfMoveSpheres[this->i]->iceCount > 0)
						{
							this->world->listOfMoveSpheres[this->i]->iceCount--;
							this->world->worldInterface->archiveManage("push", "ice");
						}
					}
					else if (this->world->listOfMoveSpheres[this->i]->fireCount == 0 && this->world->listOfMoveSpheres[this->i]->iceCount == 0 && this->world->listOfMoveSpheres[this->i]->stoneCount > 0 && this->world->listOfMoveSpheres[this->i]->levinCount == 0)
					{
						while (this->world->listOfMoveSpheres[this->i]->stoneCount > 0)
						{
							this->world->listOfMoveSpheres[this->i]->stoneCount--;
							this->world->worldInterface->archiveManage("push", "stone");
						}
					}
					else if (this->world->listOfMoveSpheres[this->i]->fireCount == 0 && this->world->listOfMoveSpheres[this->i]->iceCount == 0 && this->world->listOfMoveSpheres[this->i]->stoneCount == 0 && this->world->listOfMoveSpheres[this->i]->levinCount > 0)
					{
						while (this->world->listOfMoveSpheres[this->i]->levinCount > 0)
						{
							this->world->listOfMoveSpheres[this->i]->levinCount--;
							this->world->worldInterface->archiveManage("push", "levin");
						}
					}
					else if (this->world->listOfMoveSpheres[this->i]->getAllCount == 0)
					{
						while (this->world->listOfMoveSpheres[this->i]->fireCount > 0 || this->world->listOfMoveSpheres[this->i]->iceCount > 0 || this->world->listOfMoveSpheres[this->i]->stoneCount > 0 || this->world->listOfMoveSpheres[this->i]->levinCount > 0)
						{
							if (this->world->listOfMoveSpheres[this->i]->fireCount > 0)
							{
								this->world->listOfMoveSpheres[this->i]->fireCount--;
								this->world->worldInterface->archiveManage("push", "fire");
							}
							if (this->world->listOfMoveSpheres[this->i]->iceCount > 0)
							{
								this->world->listOfMoveSpheres[this->i]->iceCount--;
								this->world->worldInterface->archiveManage("push", "ice");
							}
							if (this->world->listOfMoveSpheres[this->i]->stoneCount > 0)
							{
								this->world->listOfMoveSpheres[this->i]->stoneCount--;
								this->world->worldInterface->archiveManage("push", "stone");
							}
							if (this->world->listOfMoveSpheres[this->i]->levinCount > 0)
							{
								this->world->listOfMoveSpheres[this->i]->levinCount--;
								this->world->worldInterface->archiveManage("push", "levin");
							}
						}
					}
					else
					{
						while (this->world->listOfMoveSpheres[this->i]->getAllCount > 0)
						{
							this->world->listOfMoveSpheres[this->i]->getAllCount--;
							this->world->worldInterface->archiveManage("push", "getAll");
						}
					}
				}
				else if (this->world->listOfMoveSpheres[this->i]->ownerType == "tower")
				{
					Tower * tower = ISTYPE(Tower, (Node*)this->world->listOfMoveSpheres[this->i]->owner);
					int tempObject = 0;
					if (this->world->listOfMoveSpheres[this->i]->fireCount > 0 && this->world->listOfMoveSpheres[this->i]->iceCount == 0 && this->world->listOfMoveSpheres[this->i]->stoneCount == 0 && this->world->listOfMoveSpheres[this->i]->levinCount == 0)
					{
						tempObject = tower->spheresManage("push", "fire", this->world->listOfMoveSpheres[this->i]->fireCount);
						if (tempObject > 0)
						{
							this->returnGetSphereToArchive("fire", tempObject);
						}
					}
					else if (this->world->listOfMoveSpheres[this->i]->fireCount == 0 && this->world->listOfMoveSpheres[this->i]->iceCount > 0 && this->world->listOfMoveSpheres[this->i]->stoneCount == 0 && this->world->listOfMoveSpheres[this->i]->levinCount == 0)
					{
						tempObject = tower->spheresManage("push", "ice", this->world->listOfMoveSpheres[this->i]->iceCount);
						if (tempObject > 0)
						{
							this->returnGetSphereToArchive("ice", tempObject);
						}
					}
					else if (this->world->listOfMoveSpheres[this->i]->fireCount == 0 && this->world->listOfMoveSpheres[this->i]->iceCount == 0 && this->world->listOfMoveSpheres[this->i]->stoneCount > 0 && this->world->listOfMoveSpheres[this->i]->levinCount == 0)
					{
						tempObject = tower->spheresManage("push", "stone", this->world->listOfMoveSpheres[this->i]->stoneCount);
						if (tempObject > 0)
						{
							this->returnGetSphereToArchive("stone", tempObject);
						}
					}
					else if (this->world->listOfMoveSpheres[this->i]->fireCount == 0 && this->world->listOfMoveSpheres[this->i]->iceCount == 0 && this->world->listOfMoveSpheres[this->i]->stoneCount == 0 && this->world->listOfMoveSpheres[this->i]->levinCount > 0)
					{
						tempObject = tower->spheresManage("push", "levin", this->world->listOfMoveSpheres[this->i]->levinCount);
						if (tempObject > 0)
						{
							this->returnGetSphereToArchive("levin", tempObject);
						}
					}
					else if (this->world->listOfMoveSpheres[this->i]->type == "holder")
					{
						this->j = 0;
						while (this->j < this->world->listOfMoveSpheres[this->i]->listOfStack.size())
						{
							if (this->world->listOfMoveSpheres[this->i]->listOfStack[this->j] == "fire")
							{
								tempObject = tower->spheresManage("push", "fire", 1);
								this->world->listOfMoveSpheres[this->i]->fireCount--;
								if (tempObject > 0)
								{
									this->returnGetSphereToArchive("fire", tempObject);
								}
							}
							else if (this->world->listOfMoveSpheres[this->i]->listOfStack[this->j] == "ice")
							{
								tempObject = tower->spheresManage("push", "ice", 1);
								this->world->listOfMoveSpheres[this->i]->iceCount--;
								if (tempObject > 0)
								{
									this->returnGetSphereToArchive("ice", tempObject);
								}
							}
							else if (this->world->listOfMoveSpheres[this->i]->listOfStack[this->j] == "stone")
							{
								tempObject = tower->spheresManage("push", "stone", 1);
								this->world->listOfMoveSpheres[this->i]->stoneCount--;
								if (tempObject > 0)
								{
									this->returnGetSphereToArchive("stone", tempObject);
								}
							}
							else if (this->world->listOfMoveSpheres[this->i]->listOfStack[this->j] == "levin")
							{
								tempObject = tower->spheresManage("push", "levin", 1);
								this->world->listOfMoveSpheres[this->i]->levinCount--;
								if (tempObject > 0)
								{
									this->returnGetSphereToArchive("levin", tempObject);
								}
							}
							j++;
						}
					}
					else if (this->world->listOfMoveSpheres[this->i]->type == "getAll")
					{
						if (this->world->listOfMoveSpheres[this->i]->getAllCount > 0)
						{
							tempObject = tower->spheresManage("push", "getAll", 1);
							this->world->listOfMoveSpheres[this->i]->getAllCount--;
							if (this->world->listOfMoveSpheres[this->i]->getAllCount > 0)
							{
								this->returnGetSphereToArchive("getAll", this->world->listOfMoveSpheres[this->i]->getAllCount);
							}
						}
					}
					if (this->world->towerMenu)
					{
						this->world->worldInterface->barInfoManage(this->world->towerMenu);
					}
				}
				if (this->world->towerMenu)
				{
					if (this->world->listOfMoveSpheres[this->i]->owner == this->world->towerMenu->myTower)
					{
						this->world->towerMenu->spheresMonitor();
					}
				}
				this->world->worldInterface->updateInfo();
				if (this->world->listOfMoveSpheres[this->i]->speedFrame == 0)
				{
					this->world->removeChild(this->world->listOfMoveSpheres[this->i]);
					this->world->listOfMoveSpheres.splice(this->i, 1);
				}
				this->world->worldInterface->container->fireSphereSphereCase->setVisible(false);
				this->world->worldInterface->container->fireSphereSphereCase->setVisible(true);
				this->world->worldInterface->container->iceSphereSphereCase->setVisible(false);
				this->world->worldInterface->container->iceSphereSphereCase->setVisible(true);
				this->world->worldInterface->container->stoneSphereSphereCase->setVisible(false);
				this->world->worldInterface->container->stoneSphereSphereCase->setVisible(true);
				this->world->worldInterface->container->levinSphereSphereCase->setVisible(false);
				this->world->worldInterface->container->levinSphereSphereCase->setVisible(true);
				this->world->worldInterface->container->getAllSphereCase->setVisible(false);
				this->world->worldInterface->container->getAllSphereCase->setVisible(true);
			}
			i--;
		}

	}// end function
	void  Feature::getSphereBeat(string param1, int param2)
	{
		if (param1 != "getAll")
		{
			this->world->getSphere = new GetSphere();
			this->world->addChild(this->world->getSphere,6);
			this->world->getSphere->ownerType = "archive";
			if (param1 == "fire")
			{
				this->world->getSphere->owner = this->world->worldInterface->container->fireSphere;
				this->world->getSphere->ownerPoint = this->world->worldInterface->container->fireSphereMyPoint;
				while (param2 > 0)
				{
					param2 = param2 - 1;
					this->world->getSphere->manage("add", "fire");
				}
			}
			else if (param1 == "ice")
			{
				this->world->getSphere->owner = this->world->worldInterface->container->iceSphere;
				this->world->getSphere->ownerPoint = this->world->worldInterface->container->iceSphereMyPoint;
				while (param2 > 0)
				{
					param2 = param2 - 1;
					this->world->getSphere->manage("add", "ice");
				}
			}
			else if (param1 == "stone")
			{
				this->world->getSphere->owner = this->world->worldInterface->container->stoneSphere;
				this->world->getSphere->ownerPoint = this->world->worldInterface->container->stoneSphereMyPoint;
				while (param2 > 0)
				{
					param2 = param2 - 1;
					this->world->getSphere->manage("add", "stone");
				}
			}
			else if (param1 == "levin")
			{
				this->world->getSphere->owner = this->world->worldInterface->container->levinSphere;
				this->world->getSphere->ownerPoint = this->world->worldInterface->container->levinSphereMyPoint;
				while (param2 > 0)
				{
					param2 = param2 - 1;
					this->world->getSphere->manage("add", "levin");
				}
			}
		}
		else
		{
			this->world->getSphere = new GetSphere("getAll");
			this->world->addChild(this->world->getSphere,6);
			this->world->getSphere->ownerType = "archive";
			this->world->getSphere->owner = this->world->worldInterface->container->getAll;
			this->world->getSphere->ownerPoint = this->world->worldInterface->container->getAllMyPoint;
			while (param2 > 0)
			{
				param2 = param2 - 1;
				this->world->getSphere->manage("add", "getAll");
			}
		}
		return;
	}// end function
	void Feature::returnGetSphereToArchive(string param1, int param2)
	{
		if (!this->world->getSphere)
		{
			this->getSphereBeat(param1, param2);
			Vec2 pos = this->world->listOfMoveSpheres[this->i]->getPosition();
			this->world->getSphere->setPosition(pos);
			//this->world->getSphere->setPosition(this->world->listOfMoveSpheres[this->i]->getPosition());
			//this->world->getSphere->x = this->world->listOfMoveSpheres[this->i]->x;
			//this->world->getSphere->y = this->world->listOfMoveSpheres[this->i]->y;
			this->world->getSphere->retrieveGetSphere();
		}

	}// end function
	void Feature::afterLoadXML()
	{
		this->world->saveBox->bezierBoxClass.bezierPoints();
		this->world->bezierClass = bezier::Bezier::create();
		this->world->addChild(this->world->bezierClass, 9999);
		int complexityLevel = this->world->saveBox->getIntValue("complexityLevel");
		this->i = 0;
		int listOfFirePortalsLen = Main::mainClass->readXMLClass.listOfFirePortals.size();
		while (this->i < listOfFirePortalsLen)
		{
			if (Main::mainClass->readXMLClass.listOfFirePortals[this->i][0] > 0 && Main::mainClass->readXMLClass.listOfFirePortals[this->i][1] > 0 && Main::mainClass->readXMLClass.listOfFirePortals[this->i][2] > 0)
			{
				RoadsignFire_mc * tempObject = new RoadsignFire_mc();
				tempObject->stop();
				tempObject->myStack.clear();// = [];
				tempObject->myPath = Main::mainClass->readXMLClass.listOfFirePortals[this->i][0];
				tempObject->myRoad = Main::mainClass->readXMLClass.listOfFirePortals[this->i][1];
				tempObject->myWay = Main::mainClass->readXMLClass.listOfFirePortals[this->i][2];
				tempObject->myPoint = this->world->bezierClass->getPathPoint(tempObject->myPath, tempObject->myRoad, tempObject->myWay);
				tempObject->setPositionX(tempObject->myPoint.x + Main::mainClass->readXMLClass.listOfFirePortals[this->i][3]);
				tempObject->setPositionY(tempObject->myPoint.y + Main::mainClass->readXMLClass.listOfFirePortals[this->i][4]);
				tempObject->setMouseChildren(false);
				tempObject->mouseEnabled = false;
				tempObject->repeatFlag = false;
				tempObject->repeatCounter = 0;
				this->world->addChild(tempObject,4);
				this->world->listOfFirePortals.push(tempObject);
				if (complexityLevel < 4)
				{
					if (this->world->nowLevel == 6)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 7)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.75);
						tempObject->setScaleY(tempObject->getScaleY() * 0.75);
					}
					else if (this->world->nowLevel == 10)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 13)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 15)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
				}
				else if (this->world->nowLevel == 6)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 7)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.75);
					tempObject->setScaleY(tempObject->getScaleY() * 0.75);
				}
				else if (this->world->nowLevel == 10)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 13)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 15)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
			}
			i++;
		}
		this->i = 0;
		int listOfIcePortalsLen = Main::mainClass->readXMLClass.listOfIcePortals.size();
		while (this->i < listOfIcePortalsLen)
		{
			if (Main::mainClass->readXMLClass.listOfIcePortals[this->i][0] > 0 && Main::mainClass->readXMLClass.listOfIcePortals[this->i][1] > 0 && Main::mainClass->readXMLClass.listOfIcePortals[this->i][2] > 0)
			{
				RoadsignIce_mc * tempObject = new RoadsignIce_mc();
				tempObject->stop();
				tempObject->myStack.clear();// = [];
				tempObject->myPath = Main::mainClass->readXMLClass.listOfIcePortals[this->i][0];
				tempObject->myRoad = Main::mainClass->readXMLClass.listOfIcePortals[this->i][1];
				tempObject->myWay = Main::mainClass->readXMLClass.listOfIcePortals[this->i][2];
				tempObject->myPoint = this->world->bezierClass->getPathPoint(tempObject->myPath, tempObject->myRoad, tempObject->myWay);
				tempObject->setPositionX(tempObject->myPoint.x + Main::mainClass->readXMLClass.listOfIcePortals[this->i][3]);
				tempObject->setPositionY(tempObject->myPoint.y + Main::mainClass->readXMLClass.listOfIcePortals[this->i][4]);
				tempObject->setMouseChildren(false);
				tempObject->mouseEnabled = false;
				tempObject->repeatFlag = false;
				tempObject->repeatCounter = 0;
				world->addChild(tempObject,4);
				world->listOfIcePortals.push(tempObject);
				if (complexityLevel < 4)
				{
					if (this->world->nowLevel == 6)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 7)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.75);
						tempObject->setScaleY(tempObject->getScaleY() * 0.75);
					}
					else if (this->world->nowLevel == 10)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 13)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 15)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
				}
				else if (this->world->nowLevel == 6)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 7)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.75);
					tempObject->setScaleY(tempObject->getScaleY() * 0.75);
				}
				else if (this->world->nowLevel == 10)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 13)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 15)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
			}
			i++;
		}
		int listOfStonePortalsLen = Main::mainClass->readXMLClass.listOfStonePortals.size();
		this->i = 0;
		while (this->i < listOfStonePortalsLen)
		{
			if (Main::mainClass->readXMLClass.listOfStonePortals[this->i][0] > 0 && Main::mainClass->readXMLClass.listOfStonePortals[this->i][1] > 0 && Main::mainClass->readXMLClass.listOfStonePortals[this->i][2] > 0)
			{
				RoadsignStone_mc * tempObject = new RoadsignStone_mc();
				tempObject->stop();
				tempObject->myStack.clear();// = [];
				tempObject->myPath = Main::mainClass->readXMLClass.listOfStonePortals[this->i][0];
				tempObject->myRoad = Main::mainClass->readXMLClass.listOfStonePortals[this->i][1];
				tempObject->myWay = Main::mainClass->readXMLClass.listOfStonePortals[this->i][2];
				tempObject->myPoint = this->world->bezierClass->getPathPoint(tempObject->myPath, tempObject->myRoad, tempObject->myWay);
				tempObject->setPositionX(tempObject->myPoint.x + Main::mainClass->readXMLClass.listOfStonePortals[this->i][3]);
				tempObject->setPositionY(tempObject->myPoint.y + Main::mainClass->readXMLClass.listOfStonePortals[this->i][4]);
				tempObject->setMouseChildren(false);
				tempObject->mouseEnabled = false;
				tempObject->repeatFlag = false;
				tempObject->repeatCounter = 0;
				this->world->addChild(tempObject,4);
				this->world->listOfStonePortals.push(tempObject);
				if (complexityLevel < 4)
				{
					if (this->world->nowLevel == 6)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 7)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.75);
						tempObject->setScaleY(tempObject->getScaleY() * 0.75);
					}
					else if (this->world->nowLevel == 10)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 13)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 15)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
				}
				else if (this->world->nowLevel == 6)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 7)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.75);
					tempObject->setScaleY(tempObject->getScaleY() * 0.75);
				}
				else if (this->world->nowLevel == 10)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 13)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 15)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
			}
			i++;
		}
		int listOfLevinPortalsLen = Main::mainClass->readXMLClass.listOfLevinPortals.size();
		this->i = 0;
		while (this->i < listOfLevinPortalsLen)
		{
			if (Main::mainClass->readXMLClass.listOfLevinPortals[this->i][0] > 0 && Main::mainClass->readXMLClass.listOfLevinPortals[this->i][1] > 0 && Main::mainClass->readXMLClass.listOfLevinPortals[this->i][2] > 0)
			{
				RoadsignLevin_mc * tempObject = new RoadsignLevin_mc();
				tempObject->stop();
				tempObject->myStack.clear();// = [];
				tempObject->myPath = Main::mainClass->readXMLClass.listOfLevinPortals[this->i][0];
				tempObject->myRoad = Main::mainClass->readXMLClass.listOfLevinPortals[this->i][1];
				tempObject->myWay = Main::mainClass->readXMLClass.listOfLevinPortals[this->i][2];
				tempObject->myPoint = this->world->bezierClass->getPathPoint(tempObject->myPath, tempObject->myRoad, tempObject->myWay);
				tempObject->setPositionX(tempObject->myPoint.x + Main::mainClass->readXMLClass.listOfLevinPortals[this->i][3]);
				tempObject->setPositionY(tempObject->myPoint.y + Main::mainClass->readXMLClass.listOfLevinPortals[this->i][4]);
				tempObject->setMouseChildren(false);
				tempObject->mouseEnabled = false;
				tempObject->repeatFlag = false;
				tempObject->repeatCounter = 0;
				this->world->addChild(tempObject,4);
				this->world->listOfLevinPortals.push(tempObject);
				if (complexityLevel < 4)
				{
					if (this->world->nowLevel == 6)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 7)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.75);
						tempObject->setScaleY(tempObject->getScaleY() * 0.75);
					}
					else if (this->world->nowLevel == 10)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 13)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
					else if (this->world->nowLevel == 15)
					{
						tempObject->setScaleX(tempObject->getScaleX() * 0.8);
						tempObject->setScaleY(tempObject->getScaleY() * 0.8);
					}
				}
				else if (this->world->nowLevel == 6)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 7)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.75);
					tempObject->setScaleY(tempObject->getScaleY() * 0.75);
				}
				else if (this->world->nowLevel == 10)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 13)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
				else if (this->world->nowLevel == 15)
				{
					tempObject->setScaleX(tempObject->getScaleX() * 0.8);
					tempObject->setScaleY(tempObject->getScaleY() * 0.8);
				}
			}
			i++;
		}

		this->world->worldInterface = new WorldInterface();
		this->world->worldInterface->init();
		this->world->addChild(this->world->worldInterface,5);
		//world->logInfo("buyFireBuyTXT", world->worldInterface->container->buyFireBuyTXT->getPosition());
		//world->logInfo("buyFireBuyTXT", world->worldInterface->container->buyFireBuyTXT->getNamePath());
		//world->logInfo("buyFireBuyTXT", CONVERT_TO_WORLD_POS(world->worldInterface->container->buyFire->convertToWorldSpace(world->worldInterface->container->buyFireBuyTXT->getPosition())));

		if (complexityLevel == 4)
		{
			if (this->world->pointer1)
			{
				this->world->pointer1->setVisible(false);
			}
			if (this->world->pointer2)
			{
				this->world->pointer2->setVisible(false);
			}
			if (this->world->pointer3)
			{
				this->world->pointer3->setVisible(false);
			}
			this->world->worldInterface->container->lastTime->setVisible(true);
			this->world->liveMax = 1;
			this->world->live = 1;
			if (this->world->nowLevel == 3)
			{
				this->i = 0;
				while (this->i < this->world->listOfPlaces.size())
				{
					this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					//if (this->world->listOfPlaces[this->i]->getName() == "place1" || this->world->listOfPlaces[this->i]->getName() == "place2" || this->world->listOfPlaces[this->i]->getName() == "place4" || this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place8")
					//{
					//	this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					//}
					//else if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place6" || this->world->listOfPlaces[this->i]->getName() == "place7")
					//{
					//	this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					//}
					i++;
				}
				this->world->money = 10000000;
				this->i = 1;
				while (this->i <= 3)
				{
					this->world->worldInterface->archiveManage("buy", "fire");
					this->world->worldInterface->archiveManage("buy", "ice");
					this->world->worldInterface->archiveManage("buy", "stone");
					this->world->worldInterface->archiveManage("buy", "levin");
					i++;
				}
				this->world->money = 0;
			}
			else if (this->world->nowLevel == 5)
			{
				this->i = 0;
				while (this->i < this->world->listOfPlaces.size())
				{
					if (this->world->listOfPlaces[this->i]->getName() == "place4")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					i++;
				}
			}
			else if (this->world->nowLevel == 7)
			{
				this->i = 0;
				while (this->i < this->world->listOfPlaces.size())
				{
					if (this->world->listOfPlaces[this->i]->getName() == "place1" || this->world->listOfPlaces[this->i]->getName() == "place2" || this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place6" || this->world->listOfPlaces[this->i]->getName() == "place8")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					else if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place7")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					else if (this->world->listOfPlaces[this->i]->getName() == "place4" || this->world->listOfPlaces[this->i]->getName() == "place9")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					i++;
				}
			}
			else if (this->world->nowLevel == 9)
			{
				this->i = 0;
				while (this->i < this->world->listOfPlaces.size())
				{
					if (this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place10")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					i++;
				}
			}
			else if (this->world->nowLevel == 10)
			{
				this->i = 0;
				while (this->i < this->world->listOfPlaces.size())
				{
					if (this->world->listOfPlaces[this->i]->getName() == "place1" || this->world->listOfPlaces[this->i]->getName() == "place2" || this->world->listOfPlaces[this->i]->getName() == "place8" || this->world->listOfPlaces[this->i]->getName() == "place10")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					i++;
				}
			}
			else if (this->world->nowLevel == 11)
			{
				this->i = 0;
				while (this->i < this->world->listOfPlaces.size())
				{
					if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place4" || this->world->listOfPlaces[this->i]->getName() == "place8" || this->world->listOfPlaces[this->i]->getName() == "place10")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					i++;
				}
			}
			else if (this->world->nowLevel == 14)
			{
				this->i = 0;
				while (this->i < this->world->listOfPlaces.size())
				{
					if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place8" || this->world->listOfPlaces[this->i]->getName() == "place10")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					i++;
				}
			}
			else if (this->world->nowLevel == 15)
			{
				this->i = 0;
				while (this->i < this->world->listOfPlaces.size())
				{

					if (this->world->listOfPlaces[this->i]->getName() == "place1" || this->world->listOfPlaces[this->i]->getName() == "place6" || this->world->listOfPlaces[this->i]->getName() == "place10" || this->world->listOfPlaces[this->i]->getName() == "place15")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					else if (this->world->listOfPlaces[this->i]->getName() == "place4" || this->world->listOfPlaces[this->i]->getName() == "place12")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					else if (this->world->listOfPlaces[this->i]->getName() == "place5" || this->world->listOfPlaces[this->i]->getName() == "place14")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					else if (this->world->listOfPlaces[this->i]->getName() == "place2" || this->world->listOfPlaces[this->i]->getName() == "place13")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					else if (this->world->listOfPlaces[this->i]->getName() == "place3" || this->world->listOfPlaces[this->i]->getName() == "place11")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					else if (this->world->listOfPlaces[this->i]->getName() == "place7" || this->world->listOfPlaces[this->i]->getName() == "place8" || this->world->listOfPlaces[this->i]->getName() == "place9")
					{
						this->world->listOfPlaces[this->i]->placeForBuildCase->mouseEnabled = false;
					}
					i++;
				}
			}
		}

		Main::mainClass->readXMLClass.costTowerXML = Main::mainClass->readXMLClass.costTowerXML + Main::mainClass->readXMLClass.costTowerPlusXML * Main::mainClass->readXMLClass.testTowerStep;
		if (Main::mainClass->readXMLClass.testFireStep < Main::mainClass->readXMLClass.listOfFirePriceXML.size())
		{
			this->world->worldInterface->fireBuyHistory = Main::mainClass->readXMLClass.testFireStep;
		}
		if (Main::mainClass->readXMLClass.testIceStep < Main::mainClass->readXMLClass.listOfIcePriceXML.size())
		{
			this->world->worldInterface->iceBuyHistory = Main::mainClass->readXMLClass.testIceStep;
		}
		if (Main::mainClass->readXMLClass.testStoneStep < Main::mainClass->readXMLClass.listOfStonePriceXML.size())
		{
			this->world->worldInterface->stoneBuyHistory = Main::mainClass->readXMLClass.testStoneStep;
		}
		if (Main::mainClass->readXMLClass.testLevinStep < Main::mainClass->readXMLClass.listOfLevinPriceXML.size())
		{
			this->world->worldInterface->levinBuyHistory = Main::mainClass->readXMLClass.testLevinStep;
		}
		this->world->worldInterface->updateInfo();
		//if (!Main::mainClass->testingClass)
		//{
		//	Main::mainClass->testingClass = new Testing();
		//	Main::mainClass->testingClass.newWave();
		//}
		//else
		//{
		//	Main::mainClass->testingClass.load();
		//}
		//return;
	}// end function

	void Feature::scanPointersAtCast()
	{
		cocos2d::Point tempObject=CONVERT_TO_WORLD_POS(Vec2(Main::mouseX, Main::mouseY));
		if (tempObject.distance(this->world->pointer1->myPoint) < 30)
		{
			if (this->world->pointer1->getAlpha() == 1)
			{
				this->world->pointer1->setAlpha(0);
			}
		}
		else if (this->world->pointer1->getAlpha() == 0)
		{
			this->world->pointer1->setAlpha(1);
		}
		if (this->world->pointer2)
		{
			if (tempObject.distance(this->world->pointer2->myPoint) < 50)
			{
				if (this->world->pointer2->getAlpha() == 1)
				{
					this->world->pointer2->setAlpha(0);
				}
			}
			else if (this->world->pointer2->getAlpha() == 0)
			{
				this->world->pointer2->setAlpha(1);
			}
		}
		if (this->world->pointer3)
		{
			if (tempObject.distance(this->world->pointer3->myPoint) < 50)
			{
				if (this->world->pointer3->getAlpha() == 1)
				{
					this->world->pointer3->setAlpha(0);
				}
			}
			else if (this->world->pointer3->getAlpha() == 0)
			{
				this->world->pointer3->setAlpha(1);
			}
		}
		return;
	}// end function

}