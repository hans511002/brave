#include "level1.h"
#include "engine/xml/ReadXML.h"
#include "MainClass.h"
#include "engine/World.h"
#include "JsonUtil.h"
#include "cocostudio/DictionaryHelper.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetReader/WidgetReader.h"
using namespace cocostudio;

namespace engine{
	void Level::flagHandler(cocos2d::EventCustom *event){
		EventData *eventData = (EventData*)(event->getUserData());
		switch (eventData->getType())
		{
		case EventData::EventType::COMPLETE:
			for (size_t i = 0; i < flags.size(); i++)
			{
				flags[i]->getAnimation()->gotoAndPlay("flag");
			}
			break;
		case EventData::EventType::LOOP_COMPLETE:
			break;
		case EventData::EventType::ANIMATION_FRAME_EVENT:
			if (eventData->frameLabel == "ending")
			{
				//
				//pass->removeFromParentAndCleanup(true);
			}
			break;

		}
	};

	namespace level
	{
		bool Level1::init(){
			//this->initWithFile("level/level1.png");
			//auto _background = cocos2d::Sprite::create("level/level1.png");
			//this->addChild(_background);
			//this->setScale(1.05f);
			//this->setPosition(Main::SCREEN_WIDTH_HALF, Main::SCREEN_HEIGHT_HALF);
			
			//BaseSprite::init();
			//cocos2d::Size lsize=this->getContentSize();
			//this->setPosition((Main::SCREEN_WIDTH - lsize.width*this->getScaleX()) / 2, (Main::SCREEN_HEIGHT - lsize.height*this->getScaleY()) / 2);

            Node * node = CSLoader::createNode("level1.csb");
            //CSLoader cs;
            //node = cs.createNodeFromJson("D:\\work\\gm\\brave\\proj.win32\\Debug.win32\\worldinterface.json");
            this->addChild(node);

			//this->setPosition(Main::SCREEN_WIDTH_HALF, Main::SCREEN_HEIGHT_HALF);
			DBCCFactory::getInstance()->loadDragonBonesData("public/flag/skeleton.xml", "flag");
			DBCCFactory::getInstance()->loadTextureAtlas("public/flag/texture.xml", "flag");
			auto flag1 = DBCCFactory::getInstance()->buildArmatureNode("flag");
			auto flag2 = DBCCFactory::getInstance()->buildArmatureNode("flag");
			flags.push_back(flag1);
			flags.push_back(flag2);
			this->addChild(flag1);
			this->addChild(flag2);
			flag1->getAnimation()->gotoAndPlay("flag", -1.0, -1.0, 0x7FFFFFF);
			flag2->getAnimation()->gotoAndPlay("flag", -1.0, -1.0, 0x7FFFFFF);
			flag1->setPosition(760 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 255);
			flag2->setPosition(760 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
			//flag1->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT,std::bind(&Level1::flagHandler, this, std::placeholders::_1));
			//flag1->getCCEventDispatcher()->addCustomEventListener(EventData::COMPLETE,std::bind(&Level1::flagHandler, this, std::placeholders::_1));
			//flag1->getCCEventDispatcher()->addCustomEventListener(EventData::LOOP_COMPLETE,std::bind(&Level1::flagHandler, this, std::placeholders::_1));

			//flag2->setPosition(-100,-100);

			for (int i = 0; i < 5; i++)
			{
                Common::String placeName = "place";
                placeBases[i] = (Sprite *)node->getChildByName(placeName + i);
				//placeBases[i] = Sprite::create("public/place_off.png");
				//this->addChild(placeBases[i]);
			}
			//placeBases[0]->setPosition(100 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 230);
			//placeBases[1]->setPosition(220 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
			//placeBases[2]->setPosition(320 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
			//placeBases[3]->setPosition(420 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
			//placeBases[4]->setPosition(520 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
			// 
            Sprite * point = (Sprite *)node->getChildByName("point");
            pointers[0] =  PointTimer::create();
            pointers[0] ->setPosition(point->getPosition());
            pointers[0]->setName("point1");
            node->removeChild(point);
			//pointers[1] = PointTimer::create();
			return true;
		}
	}

}