#include "Feature.h"
#include "MainClass.h"
#include "World.h"
#include "engine/level/RoadLevel1.h"
#include "engine/level/Level1.h"
#include "engine/decoration/Decoration.h"
#include "engine/decoration/DecorationLevel1.h"
#include "bezier/Bezier.h"
#include "bezier/PathPoint.h"
#include "bezier/PathPoint.h"
#include "bezier/PathPoint.h"


namespace engine
{
	Feature::Feature() :autoAddTowerCounter(30)
	{
		this->world = Main::mainClass->worldClass;
		this->world->nowLevel = Main::mainClass->saveBoxClass->playLevel;
		this->world->saveBox = Main::mainClass->saveBoxClass;
		if (this->world->nowLevel == 1)
		{
			this->world->level = level::Level1::create();
			//this->world->road = new level::RoadLevel1();
			//this->world->decoration = new decoration::DecorationLevel1();
			this->world->levelType = "grass";
			if (!Main::mainClass->saveBoxClass->getBoolValue("firstViewTowers",0))
			{
				Main::mainClass->saveBoxClass->setValue("firstViewTowers", 0, true);
			}
		}
		//else if (this->world->nowLevel == 2)
		//{
		//	this->world->level = new Level2_mc();
		//	this->world->road = new RoadLevel2_mc();
		//	this->world->decoration = new DecorationLevel2();
		//	this->world->levelType = "grass";
		//	if (!Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[1])
		//	{
		//		Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[1] = true;
		//	}
		//}
		//else if (this->world->nowLevel == 3)
		//{
		//	this->world->level = new Level3_mc();
		//	this->world->road = new RoadLevel3_mc();
		//	this->world->decoration = new DecorationLevel3();
		//	this->world->levelType = "grass";
		//	if (!Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[2])
		//	{
		//		Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[2] = true;
		//	}
		//}
		//else if (this->world->nowLevel == 4)
		//{
		//	this->world->level = new Level4_mc();
		//	this->world->road = new RoadLevel4_mc();
		//	this->world->decoration = new DecorationLevel4();
		//	this->world->levelType = "grass";
		//	if (!Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[3])
		//	{
		//		Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[3] = true;
		//	}
		//}
		//else if (this->world->nowLevel == 5)
		//{
		//	this->world->level = new Level5_mc();
		//	this->world->road = new RoadLevel5_mc();
		//	this->world->decoration = new DecorationLevel5();
		//	this->world->levelType = "grass";
		//}
		//else if (this->world->nowLevel == 6)
		//{
		//	this->world->level = new Level6_mc();
		//	this->world->road = new RoadLevel6_mc();
		//	this->world->decoration = new DecorationLevel6();
		//	this->world->levelType = "grass";
		//	if (!Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[4])
		//	{
		//		Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[4] = true;
		//	}
		//}
		//else if (this->world->nowLevel == 7)
		//{
		//	this->world->level = new Level7_mc();
		//	this->world->road = new RoadLevel7_mc();
		//	this->world->decoration = new DecorationLevel7();
		//	this->world->levelType = "grass";
		//	if (!Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[5])
		//	{
		//		Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[5] = true;
		//	}
		//}
		//else if (this->world->nowLevel == 8)
		//{
		//	this->world->level = new Level8_mc();
		//	this->world->road = new RoadLevel8_mc();
		//	this->world->decoration = new DecorationLevel8();
		//	this->world->levelType = "dust";
		//}
		//else if (this->world->nowLevel == 9)
		//{
		//	this->world->level = new Level9_mc();
		//	this->world->road = new RoadLevel9_mc();
		//	this->world->decoration = new DecorationLevel9();
		//	this->world->levelType = "grass";
		//	if (!Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[6])
		//	{
		//		Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[6] = true;
		//	}
		//}
		//else if (this->world->nowLevel == 10)
		//{
		//	this->world->level = new Level10_mc();
		//	this->world->road = new RoadLevel10_mc();
		//	this->world->decoration = new DecorationLevel10();
		//	this->world->levelType = "dust";
		//}
		//else if (this->world->nowLevel == 11)
		//{
		//	this->world->level = new Level11_mc();
		//	this->world->road = new RoadLevel11_mc();
		//	this->world->decoration = new DecorationLevel11();
		//	this->world->levelType = "dust";
		//	if (!Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[7])
		//	{
		//		Main::mainClass->saveBoxClass.gameSave.data.firstViewTowers[7] = true;
		//	}
		//}
		//else if (this->world->nowLevel == 12)
		//{
		//	this->world->level = new Level12_mc();
		//	this->world->road = new RoadLevel12_mc();
		//	this->world->decoration = new DecorationLevel12();
		//	this->world->levelType = "dust";
		//}
		//else if (this->world->nowLevel == 13)
		//{
		//	this->world->level = new Level13_mc();
		//	this->world->road = new RoadLevel13_mc();
		//	this->world->decoration = new DecorationLevel13();
		//	this->world->levelType = "dust";
		//}
		//else if (this->world->nowLevel == 14)
		//{
		//	this->world->level = new Level14_mc();
		//	this->world->road = new RoadLevel14_mc();
		//	this->world->decoration = new DecorationLevel14();
		//	this->world->levelType = "dust";
		//}
		//else if (this->world->nowLevel == 15)
		//{
		//	this->world->level = new Level15_mc();
		//	this->world->road = new RoadLevel15_mc();
		//	this->world->decoration = new DecorationLevel15();
		//	this->world->levelType = "dust";
		//}
		this->world->addChild(this->world->level);
		for (size_t i = 0; i < this->world->level->flags.size(); i++)
		{
			dragonBones::DBCCArmatureNode * arma=this->world->level->flags.at(i);
			//this->world->addChild(arma); 
			//arma->setPosition( Main::SCREEN_WIDTH_HALF, Main::SCREEN_HEIGHT_HALF);

			//arma->getAnimation()->play();
			//arma->setVisible(true);
		}
		for (size_t i = 0; i < this->world->level->additionallys.size(); i++)
		{
			dragonBones::DBCCArmatureNode * arma = this->world->level->additionallys.at(i);
			this->world->addChild(arma);
		}
		for (size_t i = 0; i < this->world->level->places.size(); i++)
		{
			dragonBones::DBCCArmatureNode * arma = this->world->level->places.at(i);
			this->world->addChild(arma);
		}
		//this->world->level.stop();
		//this->i = this->world->level->getChildrenCount- 1;
		//while (this->i >= 0)
		//{
		//	this->tempObject = this->world->level.getChildAt(this->i);
		//	if (this->tempObject.name == "flag1" || this->tempObject.name == "flag2" || this->tempObject.name == "flag3" || this->tempObject.name == "flag4")
		//	{
		//		this->world->level.removeChild(this->tempObject);
		//		this->world->addChild(this->tempObject);
		//		this->tempObject.gotoAndStop((Math.round(Math.random() * (this->tempObject.totalFrames - 1)) + 1));
		//		var _loc_1 : *= false;
		//		this->tempObject.mouseChildren = false;
		//		this->tempObject.mouseEnabled = _loc_1;
		//		this->world->listOfFlags.push(this->tempObject);
		//	}
		//	else if (this->tempObject.name == "additionally")
		//	{
		//		this->world->levelAdditionally = this->tempObject;
		//		this->world->levelAdditionally.stop();
		//		var _loc_1 : *= false;
		//		this->world->levelAdditionally.mouseChildren = false;
		//		this->world->levelAdditionally.mouseEnabled = _loc_1;
		//		this->world->level.removeChild(this->world->levelAdditionally);
		//		this->world->addChild(this->world->levelAdditionally);
		//		this->world->listOfIndexes1.push(this->world->levelAdditionally);
		//	}
		//	else if (this->tempObject.name == "additionally1")
		//	{
		//		this->world->levelAdditionally1 = this->tempObject;
		//		this->world->levelAdditionally1.stop();
		//		var _loc_1 : *= false;
		//		this->world->levelAdditionally1.mouseChildren = false;
		//		this->world->levelAdditionally1.mouseEnabled = _loc_1;
		//		this->world->level.removeChild(this->world->levelAdditionally1);
		//		this->world->addChild(this->world->levelAdditionally1);
		//	}
		//	else if (this->tempObject.name == "additionally2")
		//	{
		//		this->world->levelAdditionally2 = this->tempObject;
		//		this->world->levelAdditionally2.stop();
		//		var _loc_1 : *= false;
		//		this->world->levelAdditionally2.mouseChildren = false;
		//		this->world->levelAdditionally2.mouseEnabled = _loc_1;
		//		this->world->level.removeChild(this->world->levelAdditionally2);
		//		this->world->addChild(this->world->levelAdditionally2);
		//	}
		//	else if (this->tempObject.name == "additionally3")
		//	{
		//		this->world->levelAdditionally3 = this->tempObject;
		//		this->world->levelAdditionally3.stop();
		//		var _loc_1 : *= false;
		//		this->world->levelAdditionally3.mouseChildren = false;
		//		this->world->levelAdditionally3.mouseEnabled = _loc_1;
		//		this->world->level.removeChild(this->world->levelAdditionally3);
		//		this->world->addChild(this->world->levelAdditionally3);
		//	}
		//	else if (this->tempObject.name == "place1" || this->tempObject.name == "place2" || this->tempObject.name == "place3" || this->tempObject.name == "place4" || this->tempObject.name == "place5" || this->tempObject.name == "place6" || this->tempObject.name == "place7" || this->tempObject.name == "place8" || this->tempObject.name == "place9" || this->tempObject.name == "place10" || this->tempObject.name == "place11" || this->tempObject.name == "place12" || this->tempObject.name == "place13" || this->tempObject.name == "place14" || this->tempObject.name == "place15" || this->tempObject.name == "place16" || this->tempObject.name == "place17" || this->tempObject.name == "place18" || this->tempObject.name == "place19" || this->tempObject.name == "place20")
		//	{
		//		this->tempObject.stop();
		//		this->tempObject.buildPoint.stop();
		//		this->tempObject.placeForBuildCase.buttonMode = true;
		//		this->world->level.removeChild(this->tempObject);
		//		this->world->addChild(this->tempObject);
		//		this->world->listOfPlaces.push(this->tempObject);
		//	}
		//	i++;
		//}

		
		//this->world->road->armature->getAnimation()->stop(); 
		//this->world->road->armature->setName("road");
		//this->world->road.alpha = 0;
		//this->world->road->setVisible(false);// visible = false;
		//this->world->addChild(this->world->road);

		//this->world->map = new Map();
		//this->world->towerRadius = new TowerRadius_mc();
		//this->world->towerRadius.stop(); 
		//this->world->towerRadius.mouseChildren = false;
		//this->world->towerRadius.mouseEnabled = false;
		//this->world->towerRadius.visible = false;
		//this->world->addChild(this->world->towerRadius);
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
		int levelPointerSize=this->world->level->pointers.size();
		if (levelPointerSize>0 && this->world->level->pointers[0])
		{
			this->world->pointer1 = this->world->level->pointers[0];// pointer1;
			//this->world->pointer1.statusAnima = 1;
			//this->world->pointer1.myPoint = new Point(this->world->pointer1.x, this->world->pointer1.y);
			//this->world->pointer1.gotoAndStop(2);
			//this->world->pointer1.mask2.stop();
			//this->world->pointer1.arrow.stop();
			//this->world->pointer1.fireAnima.gotoAndStop(1);
			//this->world->pointer1.eyesAnima.gotoAndStop(1);
			//this->world->pointer1.mask2.rotation = 180;
			//this->world->pointer1.pointerCase.buttonMode = true;
			//this->world->level.removeChild(this->world->pointer1);
			this->world->addChild(this->world->pointer1);
			//this->world->listOfIndexes3.push(this->world->pointer1); 
			//this->world->pointer1.scaleY = 0.9;
			//this->world->pointer1.scaleX = 0.9;
			//this->world->pointer1.visible = false;
			//this->tempObject = this->world->pointer1.rotation;
			//this->world->pointer1.rotation = 0;
			//this->world->pointer1.arrow.rotation = this->tempObject;
		}
		if (levelPointerSize>1 && this->world->level->pointers[1])//this->world->level.pointer2)
		{
		//	this->world->pointer2 = this->world->level.pointer2;
		//	this->world->pointer2.statusAnima = 1;
		//	this->world->pointer2.myPoint = new Point(this->world->pointer2.x, this->world->pointer2.y);
		//	this->world->pointer2.gotoAndStop(2);
		//	this->world->pointer2.mask2.stop();
		//	this->world->pointer2.arrow.stop();
		//	this->world->pointer2.fireAnima.gotoAndStop(1);
		//	this->world->pointer2.eyesAnima.gotoAndStop(1);
		//	this->world->pointer2.mask2.rotation = 180;
		//	this->world->pointer2.pointerCase.buttonMode = true;
		//	this->world->level.removeChild(this->world->pointer2);
		//	this->world->addChild(this->world->pointer2);
		//	this->world->listOfIndexes3.push(this->world->pointer2);
		//	var _loc_1 : *= 0.9;
		//	this->world->pointer2.scaleY = 0.9;
		//	this->world->pointer2.scaleX = _loc_1;
		//	this->world->pointer2.visible = false;
		//	this->tempObject = this->world->pointer2.rotation;
		//	this->world->pointer2.rotation = 0;
		//	this->world->pointer2.arrow.rotation = this->tempObject;
		}
		if (levelPointerSize>2 && this->world->level->pointers[2])//this->world->level.pointer3)
		{
		//	this->world->pointer3 = this->world->level.pointer3;
		//	this->world->pointer3.statusAnima = 1;
		//	this->world->pointer3.myPoint = new Point(this->world->pointer3.x, this->world->pointer3.y);
		//	this->world->pointer3.gotoAndStop(2);
		//	this->world->pointer3.mask2.stop();
		//	this->world->pointer3.arrow.stop();
		//	this->world->pointer3.fireAnima.gotoAndStop(1);
		//	this->world->pointer3.eyesAnima.gotoAndStop(1);
		//	this->world->pointer3.mask2.rotation = 180;
		//	this->world->pointer3.pointerCase.buttonMode = true;
		//	this->world->level.removeChild(this->world->pointer3);
		//	this->world->addChild(this->world->pointer3);
		//	this->world->listOfIndexes3.push(this->world->pointer3);
		//	var _loc_1 : *= 0.9;
		//	this->world->pointer3.scaleY = 0.9;
		//	this->world->pointer3.scaleX = _loc_1;
		//	this->world->pointer3.visible = false;
		//	this->tempObject = this->world->pointer3.rotation;
		//	this->world->pointer3.rotation = 0;
		//	this->world->pointer3.arrow.rotation = this->tempObject;
		}

		int complexityLevel= this->world->saveBox->getIntValue("complexityLevel");
		Common::String levelXmlFile="xml/";
		if (complexityLevel< 4)
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


		//this->world->hint = new Hint();
		//this->world->hint.stop(); 
		//this->world->hint.mouseChildren = false;
		//this->world->hint.mouseEnabled = false;
		//this->world->hint.visible = false;
		//this->world->addChild(this->world->hint);
		this->afterLoadXML();
 
	}// end function

	void   Feature::update()
	{
		//if (this->world->getSphere)
		//{
		//	this->world->getSphere.update();
		//}

		//this->listOfMoveSpheres();
		//this->i = 1;
		//while (this->i <= 3)
		//{
		//	if (this->i == 1)
		//	{
		//		this->tempObject = this->world->pointer1;
		//	}
		//	else if (this->i == 2)
		//	{
		//		if (this->world->pointer2)
		//		{
		//			this->tempObject = this->world->pointer2;
		//		}
		//		else
		//		{
		//			break;
		//		}
		//	}
		//	else if (this->i == 3)
		//	{
		//		if (this->world->pointer3)
		//		{
		//			this->tempObject = this->world->pointer3;
		//		}
		//		else
		//		{
		//			break;
		//		}
		//	}
		//	if (this->tempObject.visible)
		//	{
		//		if (this->tempObject.fireAnima.currentFrame < this->tempObject.fireAnima.totalFrames)
		//		{
		//			this->tempObject.fireAnima.gotoAndStop((this->tempObject.fireAnima.currentFrame + 1));
		//		}
		//		else
		//		{
		//			this->tempObject.fireAnima.gotoAndStop(1);
		//		}
		//		if (this->tempObject.eyesAnima.currentFrame < this->tempObject.eyesAnima.totalFrames)
		//		{
		//			this->tempObject.eyesAnima.gotoAndStop((this->tempObject.eyesAnima.currentFrame + 1));
		//		}
		//		else
		//		{
		//			this->tempObject.eyesAnima.gotoAndStop(1);
		//		}
		//		if (!this->tempObject.mouseEnabled)
		//		{
		//			if (this->tempObject.scaleX > 0)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX - 0.2;
		//				this->tempObject.scaleY = this->tempObject.scaleY - 0.2;
		//			}
		//			if (this->tempObject.scaleX <= 0)
		//			{
		//				this->world->pointer1.gotoAndStop(1);
		//				this->world->pointer1.mask1.rotation = -180;
		//				this->world->pointer1.mask2.rotation = 0;
		//				var _loc_1 : *= 0;
		//				this->world->pointer1.scaleY = 0;
		//				this->world->pointer1.scaleX = _loc_1;
		//				var _loc_1 : *= true;
		//				this->world->pointer1.mouseChildren = true;
		//				this->world->pointer1.mouseEnabled = _loc_1;
		//				this->world->pointer1.visible = false;
		//				this->world->pointer1.mouseFlag = false;
		//				this->world->pointer1.statusAnima = 1;
		//				if (this->world->pointer2)
		//				{
		//					this->world->pointer2.gotoAndStop(1);
		//					this->world->pointer2.mask1.rotation = -180;
		//					this->world->pointer2.mask2.rotation = 0;
		//					var _loc_1 : *= 0;
		//					this->world->pointer2.scaleY = 0;
		//					this->world->pointer2.scaleX = _loc_1;
		//					var _loc_1 : *= true;
		//					this->world->pointer2.mouseChildren = true;
		//					this->world->pointer2.mouseEnabled = _loc_1;
		//					this->world->pointer2.visible = false;
		//					this->world->pointer2.mouseFlag = false;
		//					this->world->pointer2.statusAnima = 1;
		//				}
		//				if (this->world->pointer3)
		//				{
		//					this->world->pointer3.gotoAndStop(1);
		//					this->world->pointer3.mask1.rotation = -180;
		//					this->world->pointer3.mask2.rotation = 0;
		//					var _loc_1 : *= 0;
		//					this->world->pointer3.scaleY = 0;
		//					this->world->pointer3.scaleX = _loc_1;
		//					var _loc_1 : *= true;
		//					this->world->pointer3.mouseChildren = true;
		//					this->world->pointer3.mouseEnabled = _loc_1;
		//					this->world->pointer3.visible = false;
		//					this->world->pointer3.mouseFlag = false;
		//					this->world->pointer3.statusAnima = 1;
		//				}
		//			}
		//		}
		//		else if (this->tempObject.statusAnima == 1)
		//		{
		//			if (this->tempObject.scaleX + 0.2 < 1.1)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX + 0.2;
		//				this->tempObject.scaleY = this->tempObject.scaleY + 0.2;
		//			}
		//			else
		//			{
		//				this->tempObject.statusAnima = 2;
		//			}
		//		}
		//		else if (this->tempObject.statusAnima == 2)
		//		{
		//			if (this->tempObject.scaleX - 0.2 > 0.9)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX - 0.2;
		//				this->tempObject.scaleY = this->tempObject.scaleY - 0.2;
		//			}
		//			else
		//			{
		//				this->tempObject.statusAnima = 0;
		//				var _loc_1 : *= 1;
		//				this->tempObject.scaleY = 1;
		//				this->tempObject.scaleX = _loc_1;
		//				if (this->world->wavesClass.nowWave == 1)
		//				{
		//					if (this->world->nowLevel == 1)
		//					{
		//						if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//						{
		//							if (!this->world->trainingClass)
		//							{
		//								this->world->trainingClass = new Training_6();
		//								this->world->addChild(this->world->trainingClass);
		//							}
		//						}
		//					}
		//				}
		//			}
		//		}
		//		else if (this->tempObject.mouseFlag)
		//		{
		//			if (this->tempObject.scaleX < 1)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX + 0.05;
		//				this->tempObject.scaleY = this->tempObject.scaleY + 0.05;
		//			}
		//		}
		//		else if (this->tempObject.scaleX > 0.9)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX - 0.05;
		//			this->tempObject.scaleY = this->tempObject.scaleY - 0.05;
		//			if (this->tempObject.scaleX < 0.9)
		//			{
		//				var _loc_1 : *= 0.9;
		//				this->tempObject.scaleY = 0.9;
		//				this->tempObject.scaleX = _loc_1;
		//			}
		//		}
		//	}
		//	i++;
		//}

		if (this->autoAddTowerCounter > 0)
		{
			this->autoAddTowerCounter--;
			if (this->autoAddTowerCounter == 0)
			{
				int complexityLevel = this->world->saveBox->getIntValue("complexityLevel");
				if (complexityLevel == 4)
				{
					if (this->world->nowLevel == 3)
					{
						//Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
						this->i = 0;
						while (this->i < this->world->listOfPlaces.size())
						{
							//if (this->world->listOfPlaces[this->i].name == "place1" || this->world->listOfPlaces[this->i].name == "place2" || this->world->listOfPlaces[this->i].name == "place4" || this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place8")
							//{
							//	this->world->listOfPlaces[this->i].gotoAndStop(2);
							//	this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
							//	this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
							//	this->tempObject.container.towerCase.buttonMode = false;
							//	this->tempObject.container.boneBlock.visible = true;
							//}
							//else if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place6" || this->world->listOfPlaces[this->i].name == "place7")
							//{
							//	this->world->listOfPlaces[this->i].gotoAndStop(2);
							//	this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
							//	this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
							//}
							i++;
						}
					}
					else if (this->world->nowLevel == 5)
					{
						//Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.length)
						//{
						//	if (this->world->listOfPlaces[this->i].name == "place4")
						//	{
						//		this->world->listOfPlaces[this->i].gotoAndStop(2);
						//		this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//		this->tempObject = this->world->addTower("tower5", this->world->listOfPlaces[this->i], true);
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 7)
					{
						//Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.length)
						//{
						//	if (this->world->listOfPlaces[this->i].name == "place1" || this->world->listOfPlaces[this->i].name == "place2" || this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place6" || this->world->listOfPlaces[this->i].name == "place8")
						//	{
						//		this->world->listOfPlaces[this->i].gotoAndStop(2);
						//		this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//		this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//		this->tempObject.container.towerCase.buttonMode = false;
						//		this->tempObject.container.boneBlock.visible = true;
						//	}
						//	else if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place7")
						//	{
						//		this->world->listOfPlaces[this->i].gotoAndStop(2);
						//		this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//		this->tempObject = this->world->addTower("tower5", this->world->listOfPlaces[this->i], true);
						//	}
						//	else if (this->world->listOfPlaces[this->i].name == "place4" || this->world->listOfPlaces[this->i].name == "place9")
						//	{
						//		this->world->listOfPlaces[this->i].gotoAndStop(2);
						//		this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//		this->tempObject = this->world->addTower("tower6", this->world->listOfPlaces[this->i], true);
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 9)
					{
						//Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.length)
						//{
						//	if (this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place10")
						//	{
						//		this->world->listOfPlaces[this->i].gotoAndStop(2);
						//		this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//		this->tempObject = this->world->addTower("tower7", this->world->listOfPlaces[this->i], true);
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 10)
					{
						//Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.length)
						//{
						//	if (this->world->listOfPlaces[this->i].name == "place1" || this->world->listOfPlaces[this->i].name == "place2" || this->world->listOfPlaces[this->i].name == "place8" || this->world->listOfPlaces[this->i].name == "place10")
						//	{
						//		this->world->listOfPlaces[this->i].gotoAndStop(2);
						//		this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//		this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//		this->tempObject.container.towerCase.buttonMode = false;
						//		this->tempObject.container.boneBlock.visible = true;
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 11)
					{
						//Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.length)
						//{
						//	if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place4" || this->world->listOfPlaces[this->i].name == "place8" || this->world->listOfPlaces[this->i].name == "place10")
						//	{
						//		this->world->listOfPlaces[this->i].gotoAndStop(2);
						//		this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//		this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//		this->tempObject.container.towerCase.buttonMode = false;
						//		this->tempObject.container.boneBlock.visible = true;
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 14)
					{
						//Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
						//this->i = 0;
						//while (this->i < this->world->listOfPlaces.length)
						//{
						//	if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place8" || this->world->listOfPlaces[this->i].name == "place10")
						//	{
						//		this->world->listOfPlaces[this->i].gotoAndStop(2);
						//		this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//		this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//		this->tempObject.container.towerCase.buttonMode = false;
						//		this->tempObject.container.boneBlock.visible = true;
						//	}
						//	i++;
						//}
					}
					else if (this->world->nowLevel == 15)
					{
						//	Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
						//	this->i = 0;
						//	while (this->i < this->world->listOfPlaces.length)
						//	{
						//		if (this->world->listOfPlaces[this->i].name == "place1" || this->world->listOfPlaces[this->i].name == "place6" || this->world->listOfPlaces[this->i].name == "place10" || this->world->listOfPlaces[this->i].name == "place15")
						//		{
						//			this->world->listOfPlaces[this->i].gotoAndStop(2);
						//			this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//			this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			this->tempObject.container.towerCase.buttonMode = false;
						//			this->tempObject.container.boneBlock.visible = true;
						//		}
						//		else if (this->world->listOfPlaces[this->i].name == "place2" || this->world->listOfPlaces[this->i].name == "place14")
						//		{
						//			this->world->listOfPlaces[this->i].gotoAndStop(2);
						//			this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//			this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			this->tempObject.spheresManage("push", "fire", 4);
						//		}
						//		else if (this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place11")
						//		{
						//			this->world->listOfPlaces[this->i].gotoAndStop(2);
						//			this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//			this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			this->tempObject.spheresManage("push", "ice", 4);
						//		}
						//		else if (this->world->listOfPlaces[this->i].name == "place4" || this->world->listOfPlaces[this->i].name == "place13")
						//		{
						//			this->world->listOfPlaces[this->i].gotoAndStop(2);
						//			this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//			this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			this->tempObject.spheresManage("push", "stone", 4);
						//		}
						//		else if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place12")
						//		{
						//			this->world->listOfPlaces[this->i].gotoAndStop(2);
						//			this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//			this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
						//			this->tempObject.spheresManage("push", "levin", 4);
						//		}
						//		else if (this->world->listOfPlaces[this->i].name == "place7" || this->world->listOfPlaces[this->i].name == "place8" || this->world->listOfPlaces[this->i].name == "place9")
						//		{
						//			this->world->listOfPlaces[this->i].gotoAndStop(2);
						//			this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
						//			this->tempObject = this->world->addTower("tower4", this->world->listOfPlaces[this->i], true);
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
		//this->i = this->world->listOfMoveSpheres.length - 1;
		//while (this->i >= 0)
		//{
		//	if (this->world->listOfMoveSpheres[this->i].speedFrame > 0)
		//	{
		//		(this->world->listOfMoveSpheres[this->i].speedFrame - 1);
		//		this->world->listOfMoveSpheres[this->i].alpha = this->world->listOfMoveSpheres[this->i].alpha - 0.1;
		//		this->world->listOfMoveSpheres[this->i].x = this->world->listOfMoveSpheres[this->i].x + this->world->listOfMoveSpheres[this->i].speedX;
		//		this->world->listOfMoveSpheres[this->i].y = this->world->listOfMoveSpheres[this->i].y + this->world->listOfMoveSpheres[this->i].speedY;
		//		this->world->listOfMoveSpheres[this->i].update();
		//	}
		//	else
		//	{
		//		if (this->world->listOfMoveSpheres[this->i].ownerType == "archive")
		//		{
		//			if (this->world->listOfMoveSpheres[this->i].fireCount > 0 && this->world->listOfMoveSpheres[this->i].iceCount == 0 && this->world->listOfMoveSpheres[this->i].stoneCount == 0 && this->world->listOfMoveSpheres[this->i].levinCount == 0)
		//			{
		//				while (this->world->listOfMoveSpheres[this->i].fireCount > 0)
		//				{
		//					(this->world->listOfMoveSpheres[this->i].fireCount - 1);
		//					this->world->worldInterface.archiveManage("push", "fire");
		//				}
		//			}
		//			else if (this->world->listOfMoveSpheres[this->i].fireCount == 0 && this->world->listOfMoveSpheres[this->i].iceCount > 0 && this->world->listOfMoveSpheres[this->i].stoneCount == 0 && this->world->listOfMoveSpheres[this->i].levinCount == 0)
		//			{
		//				while (this->world->listOfMoveSpheres[this->i].iceCount > 0)
		//				{
		//					(this->world->listOfMoveSpheres[this->i].iceCount - 1);
		//					this->world->worldInterface.archiveManage("push", "ice");
		//				}
		//			}
		//			else if (this->world->listOfMoveSpheres[this->i].fireCount == 0 && this->world->listOfMoveSpheres[this->i].iceCount == 0 && this->world->listOfMoveSpheres[this->i].stoneCount > 0 && this->world->listOfMoveSpheres[this->i].levinCount == 0)
		//			{
		//				while (this->world->listOfMoveSpheres[this->i].stoneCount > 0)
		//				{
		//					(this->world->listOfMoveSpheres[this->i].stoneCount - 1);
		//					this->world->worldInterface.archiveManage("push", "stone");
		//				}
		//			}
		//			else if (this->world->listOfMoveSpheres[this->i].fireCount == 0 && this->world->listOfMoveSpheres[this->i].iceCount == 0 && this->world->listOfMoveSpheres[this->i].stoneCount == 0 && this->world->listOfMoveSpheres[this->i].levinCount > 0)
		//			{
		//				while (this->world->listOfMoveSpheres[this->i].levinCount > 0)
		//				{
		//					(this->world->listOfMoveSpheres[this->i].levinCount - 1);
		//					this->world->worldInterface.archiveManage("push", "levin");
		//				}
		//			}
		//			else if (this->world->listOfMoveSpheres[this->i].getAllCount == 0)
		//			{
		//				while (this->world->listOfMoveSpheres[this->i].fireCount > 0 || this->world->listOfMoveSpheres[this->i].iceCount > 0 || this->world->listOfMoveSpheres[this->i].stoneCount > 0 || this->world->listOfMoveSpheres[this->i].levinCount > 0)
		//				{
		//					if (this->world->listOfMoveSpheres[this->i].fireCount > 0)
		//					{
		//						(this->world->listOfMoveSpheres[this->i].fireCount - 1);
		//						this->world->worldInterface.archiveManage("push", "fire");
		//					}
		//					if (this->world->listOfMoveSpheres[this->i].iceCount > 0)
		//					{
		//						(this->world->listOfMoveSpheres[this->i].iceCount - 1);
		//						this->world->worldInterface.archiveManage("push", "ice");
		//					}
		//					if (this->world->listOfMoveSpheres[this->i].stoneCount > 0)
		//					{
		//						(this->world->listOfMoveSpheres[this->i].stoneCount - 1);
		//						this->world->worldInterface.archiveManage("push", "stone");
		//					}
		//					if (this->world->listOfMoveSpheres[this->i].levinCount > 0)
		//					{
		//						(this->world->listOfMoveSpheres[this->i].levinCount - 1);
		//						this->world->worldInterface.archiveManage("push", "levin");
		//					}
		//				}
		//			}
		//			else
		//			{
		//				while (this->world->listOfMoveSpheres[this->i].getAllCount > 0)
		//				{
		//					(this->world->listOfMoveSpheres[this->i].getAllCount - 1);
		//					this->world->worldInterface.archiveManage("push", "getAll");
		//				}
		//			}
		//		}
		//		else if (this->world->listOfMoveSpheres[this->i].ownerType == "tower")
		//		{
		//			if (this->world->listOfMoveSpheres[this->i].fireCount > 0 && this->world->listOfMoveSpheres[this->i].iceCount == 0 && this->world->listOfMoveSpheres[this->i].stoneCount == 0 && this->world->listOfMoveSpheres[this->i].levinCount == 0)
		//			{
		//				this->tempObject = this->world->listOfMoveSpheres[this->i].owner.spheresManage("push", "fire", this->world->listOfMoveSpheres[this->i].fireCount);
		//				if (this->tempObject > 0)
		//				{
		//					this->returnGetSphereToArchive("fire", this->tempObject);
		//				}
		//			}
		//			else if (this->world->listOfMoveSpheres[this->i].fireCount == 0 && this->world->listOfMoveSpheres[this->i].iceCount > 0 && this->world->listOfMoveSpheres[this->i].stoneCount == 0 && this->world->listOfMoveSpheres[this->i].levinCount == 0)
		//			{
		//				this->tempObject = this->world->listOfMoveSpheres[this->i].owner.spheresManage("push", "ice", this->world->listOfMoveSpheres[this->i].iceCount);
		//				if (this->tempObject > 0)
		//				{
		//					this->returnGetSphereToArchive("ice", this->tempObject);
		//				}
		//			}
		//			else if (this->world->listOfMoveSpheres[this->i].fireCount == 0 && this->world->listOfMoveSpheres[this->i].iceCount == 0 && this->world->listOfMoveSpheres[this->i].stoneCount > 0 && this->world->listOfMoveSpheres[this->i].levinCount == 0)
		//			{
		//				this->tempObject = this->world->listOfMoveSpheres[this->i].owner.spheresManage("push", "stone", this->world->listOfMoveSpheres[this->i].stoneCount);
		//				if (this->tempObject > 0)
		//				{
		//					this->returnGetSphereToArchive("stone", this->tempObject);
		//				}
		//			}
		//			else if (this->world->listOfMoveSpheres[this->i].fireCount == 0 && this->world->listOfMoveSpheres[this->i].iceCount == 0 && this->world->listOfMoveSpheres[this->i].stoneCount == 0 && this->world->listOfMoveSpheres[this->i].levinCount > 0)
		//			{
		//				this->tempObject = this->world->listOfMoveSpheres[this->i].owner.spheresManage("push", "levin", this->world->listOfMoveSpheres[this->i].levinCount);
		//				if (this->tempObject > 0)
		//				{
		//					this->returnGetSphereToArchive("levin", this->tempObject);
		//				}
		//			}
		//			else if (this->world->listOfMoveSpheres[this->i].type == "holder")
		//			{
		//				this->j = 0;
		//				while (this->j < this->world->listOfMoveSpheres[this->i].listOfStack.length)
		//				{
		//					if (this->world->listOfMoveSpheres[this->i].listOfStack[this->j] == "fire")
		//					{
		//						this->tempObject = this->world->listOfMoveSpheres[this->i].owner.spheresManage("push", "fire", 1);
		//						(this->world->listOfMoveSpheres[this->i].fireCount - 1);
		//						if (this->tempObject > 0)
		//						{
		//							this->returnGetSphereToArchive("fire", this->tempObject);
		//						}
		//					}
		//					else if (this->world->listOfMoveSpheres[this->i].listOfStack[this->j] == "ice")
		//					{
		//						this->tempObject = this->world->listOfMoveSpheres[this->i].owner.spheresManage("push", "ice", 1);
		//						(this->world->listOfMoveSpheres[this->i].iceCount - 1);
		//						if (this->tempObject > 0)
		//						{
		//							this->returnGetSphereToArchive("ice", this->tempObject);
		//						}
		//					}
		//					else if (this->world->listOfMoveSpheres[this->i].listOfStack[this->j] == "stone")
		//					{
		//						this->tempObject = this->world->listOfMoveSpheres[this->i].owner.spheresManage("push", "stone", 1);
		//						(this->world->listOfMoveSpheres[this->i].stoneCount - 1);
		//						if (this->tempObject > 0)
		//						{
		//							this->returnGetSphereToArchive("stone", this->tempObject);
		//						}
		//					}
		//					else if (this->world->listOfMoveSpheres[this->i].listOfStack[this->j] == "levin")
		//					{
		//						this->tempObject = this->world->listOfMoveSpheres[this->i].owner.spheresManage("push", "levin", 1);
		//						(this->world->listOfMoveSpheres[this->i].levinCount - 1);
		//						if (this->tempObject > 0)
		//						{
		//							this->returnGetSphereToArchive("levin", this->tempObject);
		//						}
		//					}
		//					var _loc_1 : *= this;
		//					var _loc_2 : *= this->j + 1;
		//					_loc_1.j = _loc_2;
		//				}
		//			}
		//			else if (this->world->listOfMoveSpheres[this->i].type == "getAll")
		//			{
		//				if (this->world->listOfMoveSpheres[this->i].getAllCount > 0)
		//				{
		//					this->tempObject = this->world->listOfMoveSpheres[this->i].owner.spheresManage("push", "getAll", 1);
		//					(this->world->listOfMoveSpheres[this->i].getAllCount - 1);
		//					if (this->world->listOfMoveSpheres[this->i].getAllCount > 0)
		//					{
		//						this->returnGetSphereToArchive("getAll", this->world->listOfMoveSpheres[this->i].getAllCount);
		//					}
		//				}
		//			}
		//			if (this->world->towerMenu)
		//			{
		//				this->world->worldInterface.barInfoManage(this->world->towerMenu);
		//			}
		//		}
		//		if (this->world->towerMenu)
		//		{
		//			if (this->world->listOfMoveSpheres[this->i].owner == this->world->towerMenu.myTower)
		//			{
		//				this->world->towerMenu.spheresMonitor();
		//			}
		//		}
		//		this->world->worldInterface.updateInfo();
		//		if (this->world->listOfMoveSpheres[this->i].speedFrame == 0)
		//		{
		//			this->world->removeChild(this->world->listOfMoveSpheres[this->i]);
		//			this->world->listOfMoveSpheres.splice(this->i, 1);
		//		}
		//		this->world->worldInterface.container.fireSphere.sphereCase.visible = false;
		//		this->world->worldInterface.container.fireSphere.sphereCase.visible = true;
		//		this->world->worldInterface.container.iceSphere.sphereCase.visible = false;
		//		this->world->worldInterface.container.iceSphere.sphereCase.visible = true;
		//		this->world->worldInterface.container.stoneSphere.sphereCase.visible = false;
		//		this->world->worldInterface.container.stoneSphere.sphereCase.visible = true;
		//		this->world->worldInterface.container.levinSphere.sphereCase.visible = false;
		//		this->world->worldInterface.container.levinSphere.sphereCase.visible = true;
		//		this->world->worldInterface.container.getAll.sphereCase.visible = false;
		//		this->world->worldInterface.container.getAll.sphereCase.visible = true;
		//	}
		//	i++;
		//}
 
	}// end function
	void  Feature::getSphereBeat(string param1, int param2)
	{
		//if (param1 != "getAll")
		//{
		//	this->world->getSphere = new GetSphere();
		//	this->world->addChild(this->world->getSphere);
		//	this->world->getSphere.ownerType = "archive";
		//	if (param1 == "fire")
		//	{
		//		this->world->getSphere.owner = this->world->worldInterface.container.fireSphere;
		//		this->world->getSphere.ownerPoint = this->world->worldInterface.container.fireSphere.myPoint;
		//		while (param2 > 0)
		//		{

		//			param2 = param2 - 1;
		//			this->world->getSphere.manage("add", "fire");
		//		}
		//	}
		//	else if (param1 == "ice")
		//	{
		//		this->world->getSphere.owner = this->world->worldInterface.container.iceSphere;
		//		this->world->getSphere.ownerPoint = this->world->worldInterface.container.iceSphere.myPoint;
		//		while (param2 > 0)
		//		{

		//			param2 = param2 - 1;
		//			this->world->getSphere.manage("add", "ice");
		//		}
		//	}
		//	else if (param1 == "stone")
		//	{
		//		this->world->getSphere.owner = this->world->worldInterface.container.stoneSphere;
		//		this->world->getSphere.ownerPoint = this->world->worldInterface.container.stoneSphere.myPoint;
		//		while (param2 > 0)
		//		{

		//			param2 = param2 - 1;
		//			this->world->getSphere.manage("add", "stone");
		//		}
		//	}
		//	else if (param1 == "levin")
		//	{
		//		this->world->getSphere.owner = this->world->worldInterface.container.levinSphere;
		//		this->world->getSphere.ownerPoint = this->world->worldInterface.container.levinSphere.myPoint;
		//		while (param2 > 0)
		//		{

		//			param2 = param2 - 1;
		//			this->world->getSphere.manage("add", "levin");
		//		}
		//	}
		//}
		//else
		//{
		//	this->world->getSphere = new GetSphere("getAll");
		//	this->world->addChild(this->world->getSphere);
		//	this->world->getSphere.ownerType = "archive";
		//	this->world->getSphere.owner = this->world->worldInterface.container.getAll;
		//	this->world->getSphere.ownerPoint = this->world->worldInterface.container.getAll.myPoint;
		//	while (param2 > 0)
		//	{

		//		param2 = param2 - 1;
		//		this->world->getSphere.manage("add", "getAll");
		//	}
		//}
		//return;
	}// end function

	void Feature::afterLoadXML()
	{
		this->world->saveBox->bezierBoxClass.bezierPoints();
		this->world->bezierClass = bezier::Bezier::create();
		this->world->addChild(this->world->bezierClass,9999);
		this->i = 0;
		int listOfFirePortalsLen = Main::mainClass->readXMLClass.listOfFirePortals.size();
		while (this->i < listOfFirePortalsLen)
		{
			if (Main::mainClass->readXMLClass.listOfFirePortals[this->i][0] > 0 && Main::mainClass->readXMLClass.listOfFirePortals[this->i][1] > 0 && Main::mainClass->readXMLClass.listOfFirePortals[this->i][2] > 0)
			{
				//this->tempObject = new RoadsignFire_mc();
				//this->tempObject.stop();
				//this->tempObject.myStack = [];
				//this->tempObject.myPath = Main::mainClass->readXMLClass.listOfFirePortals[this->i][0];
				//this->tempObject.myRoad = Main::mainClass->readXMLClass.listOfFirePortals[this->i][1];
				//this->tempObject.myWay = Main::mainClass->readXMLClass.listOfFirePortals[this->i][2];
				//this->tempObject1 = this->world->bezierClass->getPathPoint(this->tempObject.myPath, this->tempObject.myRoad, this->tempObject.myWay);
				//bezier::PathPoint ppoint = this->world->bezierClass->getPathPoint(this->tempObject.myPath, this->tempObject.myRoad, this->tempObject.myWay);			
				//	this->tempObject.myPoint = new Point(this->tempObject1.x, this->tempObject1.y);
				//	this->tempObject.x = this->tempObject.myPoint.x + Main::mainClass->readXMLClass.listOfFirePortals[this->i][3];
				//	this->tempObject.y = this->tempObject.myPoint.y + Main::mainClass->readXMLClass.listOfFirePortals[this->i][4];
				//	var _loc_1 : *= false;
				//	this->tempObject.mouseChildren = false;
				//	this->tempObject.mouseEnabled = _loc_1;
				//	this->tempObject.repeatFlag = false;
				//	this->tempObject.repeatCounter = 0;
				//	this->world->addChild(this->tempObject);
				//	this->world->listOfFirePortals.push(this->tempObject);
				//	if (this->world->saveBox->gameSave.data.complexityLevel < 4)
				//	{
				//		if (this->world->nowLevel == 6)
				//		{
				//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
				//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
				//		}
				//		else if (this->world->nowLevel == 7)
				//		{
				//			this->tempObject.scaleX = this->tempObject.scaleX * 0.75;
				//			this->tempObject.scaleY = this->tempObject.scaleY * 0.75;
				//		}
				//		else if (this->world->nowLevel == 10)
				//		{
				//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
				//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
				//		}
				//		else if (this->world->nowLevel == 13)
				//		{
				//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
				//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
				//		}
				//		else if (this->world->nowLevel == 15)
				//		{
				//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
				//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
				//		}
				//	}
				//	else if (this->world->nowLevel == 6)
				//	{
				//		this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
				//		this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
				//	}
				//	else if (this->world->nowLevel == 7)
				//	{
				//		this->tempObject.scaleX = this->tempObject.scaleX * 0.75;
				//		this->tempObject.scaleY = this->tempObject.scaleY * 0.75;
				//	}
				//	else if (this->world->nowLevel == 10)
				//	{
				//		this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
				//		this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
				//	}
				//	else if (this->world->nowLevel == 13)
				//	{
				//		this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
				//		this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
				//	}
				//	else if (this->world->nowLevel == 15)
				//	{
				//		this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
				//		this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
				//	}
			}
			i++;
		}
		//this->i = 0;
		//while (this->i < Main::mainClass->readXMLClass.listOfIcePortals.length)
		//{ 
		//	if (Main::mainClass->readXMLClass.listOfIcePortals[this->i][0] > 0 && Main::mainClass->readXMLClass.listOfIcePortals[this->i][1] > 0 && Main::mainClass->readXMLClass.listOfIcePortals[this->i][2] > 0)
		//	{
		//		this->tempObject = new RoadsignIce_mc();
		//		this->tempObject.stop();
		//		this->tempObject.myStack = [];
		//		this->tempObject.myPath = Main::mainClass->readXMLClass.listOfIcePortals[this->i][0];
		//		this->tempObject.myRoad = Main::mainClass->readXMLClass.listOfIcePortals[this->i][1];
		//		this->tempObject.myWay = Main::mainClass->readXMLClass.listOfIcePortals[this->i][2];
		//		this->tempObject1 = this->world->bezierClass.getPathPoint(this->tempObject.myPath, this->tempObject.myRoad, this->tempObject.myWay);
		//		this->tempObject.myPoint = new Point(this->tempObject1.x, this->tempObject1.y);
		//		this->tempObject.x = this->tempObject.myPoint.x + Main::mainClass->readXMLClass.listOfIcePortals[this->i][3];
		//		this->tempObject.y = this->tempObject.myPoint.y + Main::mainClass->readXMLClass.listOfIcePortals[this->i][4];
		//		var _loc_1 : *= false;
		//		this->tempObject.mouseChildren = false;
		//		this->tempObject.mouseEnabled = _loc_1;
		//		this->tempObject.repeatFlag = false;
		//		this->tempObject.repeatCounter = 0;
		//		this->world->addChild(this->tempObject);
		//		this->world->listOfIcePortals.push(this->tempObject);
		//		if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//		{
		//			if (this->world->nowLevel == 6)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//			else if (this->world->nowLevel == 7)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.75;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.75;
		//			}
		//			else if (this->world->nowLevel == 10)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//			else if (this->world->nowLevel == 13)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//			else if (this->world->nowLevel == 15)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//		}
		//		else if (this->world->nowLevel == 6)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//		else if (this->world->nowLevel == 7)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.75;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.75;
		//		}
		//		else if (this->world->nowLevel == 10)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//		else if (this->world->nowLevel == 13)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//		else if (this->world->nowLevel == 15)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//	}
		//	var _loc_1 : *= this;
		//	var _loc_2 : *= this->i + 1;
		//	_loc_1.i = _loc_2;
		//}
		//this->i = 0;
		//while (this->i < Main::mainClass->readXMLClass.listOfStonePortals.length)
		//{
		//	if (Main::mainClass->readXMLClass.listOfStonePortals[this->i][0] > 0 && Main::mainClass->readXMLClass.listOfStonePortals[this->i][1] > 0 && Main::mainClass->readXMLClass.listOfStonePortals[this->i][2] > 0)
		//	{
		//		this->tempObject = new RoadsignStone_mc();
		//		this->tempObject.stop();
		//		this->tempObject.myStack = [];
		//		this->tempObject.myPath = Main::mainClass->readXMLClass.listOfStonePortals[this->i][0];
		//		this->tempObject.myRoad = Main::mainClass->readXMLClass.listOfStonePortals[this->i][1];
		//		this->tempObject.myWay = Main::mainClass->readXMLClass.listOfStonePortals[this->i][2];
		//		this->tempObject1 = this->world->bezierClass.getPathPoint(this->tempObject.myPath, this->tempObject.myRoad, this->tempObject.myWay);
		//		this->tempObject.myPoint = new Point(this->tempObject1.x, this->tempObject1.y);
		//		this->tempObject.x = this->tempObject.myPoint.x + Main::mainClass->readXMLClass.listOfStonePortals[this->i][3];
		//		this->tempObject.y = this->tempObject.myPoint.y + Main::mainClass->readXMLClass.listOfStonePortals[this->i][4];
		//		var _loc_1 : *= false;
		//		this->tempObject.mouseChildren = false;
		//		this->tempObject.mouseEnabled = _loc_1;
		//		this->tempObject.repeatFlag = false;
		//		this->tempObject.repeatCounter = 0;
		//		this->world->addChild(this->tempObject);
		//		this->world->listOfStonePortals.push(this->tempObject);
		//		if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//		{
		//			if (this->world->nowLevel == 6)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//			else if (this->world->nowLevel == 7)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.75;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.75;
		//			}
		//			else if (this->world->nowLevel == 10)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//			else if (this->world->nowLevel == 13)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//			else if (this->world->nowLevel == 15)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//		}
		//		else if (this->world->nowLevel == 6)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//		else if (this->world->nowLevel == 7)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.75;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.75;
		//		}
		//		else if (this->world->nowLevel == 10)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//		else if (this->world->nowLevel == 13)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//		else if (this->world->nowLevel == 15)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//	}
		//	i++;
		//}
		//this->i = 0;
		//while (this->i < Main::mainClass->readXMLClass.listOfLevinPortals.length)
		//{
		//	if (Main::mainClass->readXMLClass.listOfLevinPortals[this->i][0] > 0 && Main::mainClass->readXMLClass.listOfLevinPortals[this->i][1] > 0 && Main::mainClass->readXMLClass.listOfLevinPortals[this->i][2] > 0)
		//	{
		//		this->tempObject = new RoadsignLevin_mc();
		//		this->tempObject.stop();
		//		this->tempObject.myStack = [];
		//		this->tempObject.myPath = Main::mainClass->readXMLClass.listOfLevinPortals[this->i][0];
		//		this->tempObject.myRoad = Main::mainClass->readXMLClass.listOfLevinPortals[this->i][1];
		//		this->tempObject.myWay = Main::mainClass->readXMLClass.listOfLevinPortals[this->i][2];
		//		this->tempObject1 = this->world->bezierClass.getPathPoint(this->tempObject.myPath, this->tempObject.myRoad, this->tempObject.myWay);
		//		this->tempObject.myPoint = new Point(this->tempObject1.x, this->tempObject1.y);
		//		this->tempObject.x = this->tempObject.myPoint.x + Main::mainClass->readXMLClass.listOfLevinPortals[this->i][3];
		//		this->tempObject.y = this->tempObject.myPoint.y + Main::mainClass->readXMLClass.listOfLevinPortals[this->i][4];
		//		var _loc_1 : *= false;
		//		this->tempObject.mouseChildren = false;
		//		this->tempObject.mouseEnabled = _loc_1;
		//		this->tempObject.repeatFlag = false;
		//		this->tempObject.repeatCounter = 0;
		//		this->world->addChild(this->tempObject);
		//		this->world->listOfLevinPortals.push(this->tempObject);
		//		if (this->world->saveBox->gameSave.data.complexityLevel < 4)
		//		{
		//			if (this->world->nowLevel == 6)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//			else if (this->world->nowLevel == 7)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.75;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.75;
		//			}
		//			else if (this->world->nowLevel == 10)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//			else if (this->world->nowLevel == 13)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//			else if (this->world->nowLevel == 15)
		//			{
		//				this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//				this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//			}
		//		}
		//		else if (this->world->nowLevel == 6)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//		else if (this->world->nowLevel == 7)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.75;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.75;
		//		}
		//		else if (this->world->nowLevel == 10)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//		else if (this->world->nowLevel == 13)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//		else if (this->world->nowLevel == 15)
		//		{
		//			this->tempObject.scaleX = this->tempObject.scaleX * 0.8;
		//			this->tempObject.scaleY = this->tempObject.scaleY * 0.8;
		//		}
		//	}
		//	i++;
		//}

		this->world->worldInterface =  WorldInterface::create();
		this->world->addChild(this->world->worldInterface);

		//if (this->world->saveBox->gameSave.data.complexityLevel == 4)
		//{
		//	if (this->world->pointer1)
		//	{
		//		this->world->pointer1.visible = false;
		//	}
		//	if (this->world->pointer2)
		//	{
		//		this->world->pointer2.visible = false;
		//	}
		//	if (this->world->pointer3)
		//	{
		//		this->world->pointer3.visible = false;
		//	}

		//	this->world->worldInterface.container.lastTime.visible = true;
		 
		//	this->world->liveMax = 1;
		//	this->world->live = 1;
		//	if (this->world->nowLevel == 3)
		//	{
		//		this->i = 0;
		//		while (this->i < this->world->listOfPlaces.length)
		//		{
		//			if (this->world->listOfPlaces[this->i].name == "place1" || this->world->listOfPlaces[this->i].name == "place2" || this->world->listOfPlaces[this->i].name == "place4" || this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place8")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			else if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place6" || this->world->listOfPlaces[this->i].name == "place7")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			i++;
		//		}
		//		this->world->money = 10000000;
		//		this->i = 1;
		//		while (this->i <= 3)
		//		{
		//			this->world->worldInterface.archiveManage("buy", "fire");
		//			this->world->worldInterface.archiveManage("buy", "ice");
		//			this->world->worldInterface.archiveManage("buy", "stone");
		//			this->world->worldInterface.archiveManage("buy", "levin");
		//			i++;
		//		}
		//		this->world->money = 0;
		//	}
		//	else if (this->world->nowLevel == 5)
		//	{
		//		this->i = 0;
		//		while (this->i < this->world->listOfPlaces.length)
		//		{
		//			if (this->world->listOfPlaces[this->i].name == "place4")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			i++;
		//		}
		//	}
		//	else if (this->world->nowLevel == 7)
		//	{
		//		this->i = 0;
		//		while (this->i < this->world->listOfPlaces.length)
		//		{
		//			if (this->world->listOfPlaces[this->i].name == "place1" || this->world->listOfPlaces[this->i].name == "place2" || this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place6" || this->world->listOfPlaces[this->i].name == "place8")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			else if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place7")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			else if (this->world->listOfPlaces[this->i].name == "place4" || this->world->listOfPlaces[this->i].name == "place9")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			i++;
		//		}
		//	}
		//	else if (this->world->nowLevel == 9)
		//	{
		//		this->i = 0;
		//		while (this->i < this->world->listOfPlaces.length)
		//		{
		//			if (this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place10")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			i++;
		//		}
		//	}
		//	else if (this->world->nowLevel == 10)
		//	{
		//		this->i = 0;
		//		while (this->i < this->world->listOfPlaces.length)
		//		{
		//			if (this->world->listOfPlaces[this->i].name == "place1" || this->world->listOfPlaces[this->i].name == "place2" || this->world->listOfPlaces[this->i].name == "place8" || this->world->listOfPlaces[this->i].name == "place10")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			i++;
		//		}
		//	}
		//	else if (this->world->nowLevel == 11)
		//	{
		//		this->i = 0;
		//		while (this->i < this->world->listOfPlaces.length)
		//		{
		//			if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place4" || this->world->listOfPlaces[this->i].name == "place8" || this->world->listOfPlaces[this->i].name == "place10")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			i++;
		//		}
		//	}
		//	else if (this->world->nowLevel == 14)
		//	{
		//		this->i = 0;
		//		while (this->i < this->world->listOfPlaces.length)
		//		{ 
		//			if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place8" || this->world->listOfPlaces[this->i].name == "place10")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			i++;
		//		}
		//	}
		//	else if (this->world->nowLevel == 15)
		//	{
		//		this->i = 0;
		//		while (this->i < this->world->listOfPlaces.length)
		//		{

		//			if (this->world->listOfPlaces[this->i].name == "place1" || this->world->listOfPlaces[this->i].name == "place6" || this->world->listOfPlaces[this->i].name == "place10" || this->world->listOfPlaces[this->i].name == "place15")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			else if (this->world->listOfPlaces[this->i].name == "place4" || this->world->listOfPlaces[this->i].name == "place12")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			else if (this->world->listOfPlaces[this->i].name == "place5" || this->world->listOfPlaces[this->i].name == "place14")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			else if (this->world->listOfPlaces[this->i].name == "place2" || this->world->listOfPlaces[this->i].name == "place13")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			else if (this->world->listOfPlaces[this->i].name == "place3" || this->world->listOfPlaces[this->i].name == "place11")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			else if (this->world->listOfPlaces[this->i].name == "place7" || this->world->listOfPlaces[this->i].name == "place8" || this->world->listOfPlaces[this->i].name == "place9")
		//			{
		//				this->world->listOfPlaces[this->i].placeForBuildCase.buttonMode = false;
		//			}
		//			i++;
		//		}
		//	}
		//}

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
		//this->tempObject = new Point(this->world->mouseX, this->world->mouseY);
		//if (Point.distance(this->tempObject, this->world->pointer1.myPoint) < 30)
		//{
		//	if (this->world->pointer1.alpha == 1)
		//	{
		//		this->world->pointer1.alpha = 0;
		//	}
		//}
		//else if (this->world->pointer1.alpha == 0)
		//{
		//	this->world->pointer1.alpha = 1;
		//}
		//if (this->world->pointer2)
		//{
		//	if (Point.distance(this->tempObject, this->world->pointer2.myPoint) < 50)
		//	{
		//		if (this->world->pointer2.alpha == 1)
		//		{
		//			this->world->pointer2.alpha = 0;
		//		}
		//	}
		//	else if (this->world->pointer2.alpha == 0)
		//	{
		//		this->world->pointer2.alpha = 1;
		//	}
		//}
		//if (this->world->pointer3)
		//{
		//	if (Point.distance(this->tempObject, this->world->pointer3.myPoint) < 50)
		//	{
		//		if (this->world->pointer3.alpha == 1)
		//		{
		//			this->world->pointer3.alpha = 0;
		//		}
		//	}
		//	else if (this->world->pointer3.alpha == 0)
		//	{
		//		this->world->pointer3.alpha = 1;
		//	}
		//}
		//return;
	}// end function
	
}