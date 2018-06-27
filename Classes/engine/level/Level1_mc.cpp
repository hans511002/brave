#include "Level1_mc.h"
#include "engine/xml/ReadXML.h"
#include "MainClass.h"
#include "engine/World.h"
#include "JsonUtil.h"
#include "cocostudio/DictionaryHelper.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetReader/WidgetReader.h"
using namespace cocostudio;

namespace engine{

	LevelPointer::LevelPointer() :MovieClip("worldinterface/", "pointer", "LevelBase")
	{
		SET_NODETYPENAME();
		pointerCase = this->createCase("pointerCase");
		fireAnima = this->createMovieClipSub("fireAnima");
		eyesAnima = this->createMovieClipSub("eyesAnima");
		mask1 = this->createMask("mask1");
		mask2 = this->createMask("mask2");
		arrow = (Sprite*)this->getArmature()->getSlot("arrow")->getDisplay();
	}

	BuildTowerPlace::BuildTowerPlace(string arm) :MovieClip("worldinterface/", arm, "LevelBase")
	{
		SET_NODETYPENAME();
	 
		placeForBuildCase = this->createCase("placeForBuildCase");
		buildPoint = this->createCase("buildPoint");
        buildPoint->setMouseEnabled(false);
	};

	Level1_mc::Level1_mc(World *world) :Level(world, "worldinterface/", "Level1_mc", "Level1_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decoration1 = this->createMovieClipSub("decoration1");
		decorationCase = this->createCase("decorationCase");

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		flags.push(flag1);
		flags.push(flag2);
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		pointers.push(pointer1);

		//CCActionInterval * actionBy1 = CCScaleBy::create(2.f, 2.f, 1.f);
		//neru_pSprite->runAction(actionBy1); /
		//miku_pSprite->runAction(CCSequence::create(actionBy1, actionBy1->reverse(), NULL));

		//this->initWithFile("level/level1.png");
		//auto _background = cocos2d::Sprite::create("level/level1.png");
		//this->addChild(_background);
		//this->setScale(1.05f);
		//this->setPosition(Main::SCREEN_WIDTH_HALF, Main::SCREEN_HEIGHT_HALF);

		//BaseSprite::init();
		//cocos2d::Size lsize=this->getContentSize();
		//this->setPosition((Main::SCREEN_WIDTH - lsize.width*this->getScaleX()) / 2, (Main::SCREEN_HEIGHT - lsize.height*this->getScaleY()) / 2);

		//      Node * node = CSLoader::createNode("level1.csb");
		//      //CSLoader cs;
		//      //node = cs.createNodeFromJson("D:\\work\\gm\\brave\\proj.win32\\Debug.win32\\worldinterface.json");
		//      this->addChild(node);

		////this->setPosition(Main::SCREEN_WIDTH_HALF, Main::SCREEN_HEIGHT_HALF);
		////DBCCFactory::getInstance()->loadDragonBonesData("public/flag/skeleton.xml", "flag");
		////DBCCFactory::getInstance()->loadTextureAtlas("public/flag/texture.xml", "flag");
		//      auto flag1 = this->loadArmature("worldinterface/level/", "flag");// DBCCFactory::getInstance()->buildArmatureNode("flag");
		//      auto flag2 = this->loadArmature("worldinterface/level/", "flag");//DBCCFactory::getInstance()->buildArmatureNode("flag");
		//flags.push_back(flag1);
		//flags.push_back(flag2);
		//this->addChild(flag1);
		//this->addChild(flag2);
		//      flag1->getAnimation()->play("flag", 0);
		//      flag2->getAnimation()->play("flag", 0); 
		//flag1->setPosition(760 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 255);
		//flag2->setPosition(760 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
		////flag1->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT,std::bind(&Level1::flagHandler, this, std::placeholders::_1));
		////flag1->getCCEventDispatcher()->addCustomEventListener(EventData::COMPLETE,std::bind(&Level1::flagHandler, this, std::placeholders::_1));
		////flag1->getCCEventDispatcher()->addCustomEventListener(EventData::LOOP_COMPLETE,std::bind(&Level1::flagHandler, this, std::placeholders::_1));

		////flag2->setPosition(-100,-100);

		//for (int i = 0; i < 5; i++)
		//{
		//          Common::String placeName = "place";
		//          placeBases[i] = (Sprite *)node->getChildByName(placeName + i);
		//          //towerPlace[i] = TowerPlace::create();
		//          //placeBases[i]->addChild(towerPlace[i]);
		//          //std::setAnchorPoint(towerPlace[i], 35, 10);
		//	//placeBases[i] = Sprite::create("public/place_off.png");
		//	//this->addChild(placeBases[i]);
		//}
		////placeBases[0]->setPosition(100 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 230);
		////placeBases[1]->setPosition(220 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
		////placeBases[2]->setPosition(320 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
		////placeBases[3]->setPosition(420 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
		////placeBases[4]->setPosition(520 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
		//// 
		//      Sprite * point = (Sprite *)node->getChildByName("point");
		//      pointers[0] =  PointTimer::create();
		//      pointers[0] ->setPosition(point->getPosition());
		//      pointers[0]->setName("point1");
		//      node->removeChild(point);
		////pointers[1] = PointTimer::create();

	}

}
