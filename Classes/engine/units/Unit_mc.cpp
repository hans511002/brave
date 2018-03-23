#include "Unit_mc.h" 
#include "Unit.h"

namespace engine
{ 
	namespace units
	{
		bool HealthBar::init(){
			initWithFile("healthbar/bg.png");
			this->cont = cocos2d::Sprite::create("healthbar/hg.png");//healthbar/getdamage.png
			this->addChild(cont); 
			std::setAnchorPoint(cont);
			cont->setPosition(2.5, 3);
			return true;
		};

		Unit_mc::Unit_mc(Unit* unit, string contName, int typeUnit) :unit(unit), typeUnit(typeUnit), giveHealth1(NULL), giveHealth2(NULL), giveHealth3(NULL)
		{
			iceDeathFlag = 0;
			stoneDeathFlag = 0;
			levinDeathFlag = 0;

			this->unitCase = NULL;
			this->shadow = NULL;
			this->armor = NULL;
			this->signal = NULL;
			this->setPosition(0, 0);
			this->contName = contName;
			DBCCFactory::getInstance()->loadDragonBonesData(contName + "/skeleton.xml", contName);
			DBCCFactory::getInstance()->loadTextureAtlas(contName + "/texture.xml", contName);
			cont = DBCCFactory::getInstance()->buildArmatureNode(contName);

			std::string amnis[16] = { "levindeath", "stonedeath", "icedeath", "buffhp", "airshock",
				"buffspeed", "dust1", "dust2", "dust3", "dust4", "fireattack", "levinattack", "iceattack", "icefreeze",
				"fireeffect","iceeffect"};
			for (int i = 0; i< 16; i++)
			{
				DBCCFactory::getInstance()->loadDragonBonesData(amnis[i] + "/skeleton.xml", amnis[i]);
				DBCCFactory::getInstance()->loadTextureAtlas( amnis[i] + "/texture.xml", amnis[i]);
			}

			this->levinDeath = DBCCFactory::getInstance()->buildArmatureNode("levindeath");
			this->stoneDeath = DBCCFactory::getInstance()->buildArmatureNode("stonedeath");
			this->iceDeath = DBCCFactory::getInstance()->buildArmatureNode("icedeath");
			this->buffHP = DBCCFactory::getInstance()->buildArmatureNode("buffhp");
			this->airShock = DBCCFactory::getInstance()->buildArmatureNode("airshock");
			this->buffSpeed = DBCCFactory::getInstance()->buildArmatureNode("buffspeed");
			this->dust1 = DBCCFactory::getInstance()->buildArmatureNode("dust1");
			this->dust2 = DBCCFactory::getInstance()->buildArmatureNode("dust2");
			this->dust3 = DBCCFactory::getInstance()->buildArmatureNode("dust3");
			this->dust4 = DBCCFactory::getInstance()->buildArmatureNode("dust4");
			this->fireAttack = DBCCFactory::getInstance()->buildArmatureNode("fireattack");
			this->levinAttack = DBCCFactory::getInstance()->buildArmatureNode("levinattack");
			this->iceAttack = DBCCFactory::getInstance()->buildArmatureNode("iceattack");
			this->iceFreez = DBCCFactory::getInstance()->buildArmatureNode("icefreeze");
			this->fireEffect = DBCCFactory::getInstance()->buildArmatureNode("fireeffect");
			this->iceEffect = DBCCFactory::getInstance()->buildArmatureNode("iceeffect");
			this->selectUnit = cocos2d::Sprite::create("selectunit.png");
		 
			if (typeUnit == 28){
				DBCCFactory::getInstance()->loadDragonBonesData("giveHealth1/skeleton.xml", "giveHealth1");
				DBCCFactory::getInstance()->loadTextureAtlas("giveHealth1/texture.xml", "giveHealth1");
				this->giveHealth1 = DBCCFactory::getInstance()->buildArmatureNode("giveHealth1");
				DBCCFactory::getInstance()->loadDragonBonesData("giveHealth2/skeleton.xml", "giveHealth2");
				DBCCFactory::getInstance()->loadTextureAtlas("giveHealth2/texture.xml", "giveHealth2");
				this->giveHealth1 = DBCCFactory::getInstance()->buildArmatureNode("giveHealth2");
				DBCCFactory::getInstance()->loadDragonBonesData("giveHealth3/skeleton.xml", "giveHealth3");
				DBCCFactory::getInstance()->loadTextureAtlas("giveHealth3/texture.xml", "giveHealth3");
				this->giveHealth1 = DBCCFactory::getInstance()->buildArmatureNode("giveHealth3");
			}
			else if (this->typeUnit == 29 || this->typeUnit == 30){
				DBCCFactory::getInstance()->loadDragonBonesData("dustAnima/skeleton.xml","dustAnima");
				DBCCFactory::getInstance()->loadTextureAtlas("dustAnima/texture.xml", "dustAnima");
				this->dustAnima = DBCCFactory::getInstance()->buildArmatureNode("dustAnima");
			}
			healthBar = HealthBar::create();

			this->fireEffect->getCCEventDispatcher()->addCustomEventListener(EventData::COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->fireEffect->getCCEventDispatcher()->addCustomEventListener(EventData::LOOP_COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->fireEffect->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));

			this->iceFreez->getCCEventDispatcher()->addCustomEventListener(EventData::COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->iceFreez->getCCEventDispatcher()->addCustomEventListener(EventData::LOOP_COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->iceFreez->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			
			this->iceDeath->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));

			 
		}; 
		void Unit_mc::mcHandler(cocos2d::EventCustom *event)
		{
 			EventData *eventData = (EventData*)(event->getUserData());
			string nodeName = eventData->armature->name;
			switch(eventData->getType())
			{
			case EventData::EventType::COMPLETE:
				if(nodeName == "iceeffect")
				{
					string aniName = eventData->animationState->name;
					if(aniName == "begine")
					{
						this->iceEffect->getAnimation()->gotoAndPlay("continue", -1, -1, 0xFFFFFF);
					}
					else if(aniName == "end")
					{
						unit->iceEffectFlag = false;
						this->iceEffect->getAnimation()->stop();
						this->iceEffect->setVisible(false);
					}
				}
				else if(nodeName == "icefreeze")
				{
					string aniName = eventData->animationState->name;
					if("icemandead" == aniName)
					{
						unit->icemanFlag = false;
						this->iceFreez->getAnimation()->stop();
						this->iceFreez->setVisible(false);
					}
				}
				else if(nodeName == "fireeffect")
				{
					this->fireEffect->getAnimation()->gotoAndPlay("continue", -1, -1, 0xFFFFFF);
				}
				else if(nodeName == "icedeath")
				{

				}
				break;
			case EventData::EventType::LOOP_COMPLETE:
				break;
			case EventData::EventType::ANIMATION_FRAME_EVENT:
				if(nodeName == "icedeath" && eventData->frameLabel == "aa")
				{
					this->cont->setVisible(false);
				}
				break;
			}

			//switch(eventData->getType())
			//{
			//case EventData::EventType::COMPLETE:

			//	break;
			//case EventData::EventType::LOOP_COMPLETE:
			//	break;
			//case EventData::EventType::ANIMATION_FRAME_EVENT:
			//	if(eventData->frameLabel == "ending")
			//	{
			//		//
			//		//pass->removeFromParentAndCleanup(true);
			//	}
			//	break;
			//	 
			//}

		};

		bool Unit_mc::init(){
			BaseNode::init();
			addChild(cont); 
			//this->setPosition(50, 50);
			//cont->setPosition(50, 50); 
			addChild(this->levinDeath);
			addChild(this->stoneDeath);
			addChild(this->iceDeath);
			addChild(this->buffHP);
			addChild(this->airShock);
			addChild(this->buffSpeed);
			addChild(this->dust1);
			addChild(this->dust2);
			addChild(this->dust3);
			addChild(this->dust4);
			addChild(this->fireAttack);
			addChild(this->levinAttack);
			addChild(this->iceAttack);
			addChild(this->iceFreez);
			addChild(this->fireEffect);
			addChild(this->iceEffect);
			addChild(this->healthBar);
			addChild(this->selectUnit);
			if(this->giveHealth3)addChild(this->giveHealth3);
			if(this->unitCase)addChild(this->unitCase);
			if(this->armor)addChild(this->armor);
			if(this->shadow)addChild(this->shadow);
			if(this->signal)addChild(this->signal);
			if(this->giveHealth1)addChild(this->giveHealth1);
			if(this->giveHealth2)addChild(this->giveHealth2);
			if(this->giveHealth3)addChild(this->giveHealth3);

			this->levinDeath->setVisible(false);
			this->stoneDeath->setVisible(false);
			this->iceDeath->setVisible(false);
			this->buffHP->setVisible(false);
			this->airShock->setVisible(false);
			this->buffSpeed->setVisible(false);
			this->dust1->setVisible(false);
			this->dust2->setVisible(false);
			this->dust3->setVisible(false);
			this->dust4->setVisible(false);
			this->fireAttack->setVisible(false);
			this->levinAttack->setVisible(false);
			this->iceAttack->setVisible(false);
			this->iceFreez->setVisible(false);
			this->fireEffect->setVisible(false);
			this->iceEffect->setVisible(false);
			this->selectUnit->setVisible(false);
	 
			this->healthBar->setVisible(true); 
			this->healthBar->setPosition(-15, 30);

			if(this->unitCase)this->armor->setVisible(true);
			if(this->armor)this->armor->setVisible(true);
			if(this->shadow)this->shadow->setVisible(true);
			if(this->signal)this->signal->setVisible(true);
			if(this->giveHealth1)this->giveHealth1->setVisible(true);
			if(this->giveHealth2)this->giveHealth2->setVisible(true);
			std::setAnchorPoint(this,true);
			cont->setVisible(true);
 

			this->autorelease();
			return true;
		};
		void Unit_mc::stop(){
			//this->;
			this->cont->getAnimation()->stop();  
			this->buffHP->getAnimation()->stop();
			this->airShock->getAnimation()->stop();
			this->buffSpeed->getAnimation()->stop();
			this->dust1->getAnimation()->stop();
			this->dust2->getAnimation()->stop();
			this->dust3->getAnimation()->stop();
			this->dust4->getAnimation()->stop();
			this->fireAttack->getAnimation()->stop();
			this->iceAttack->getAnimation()->stop();
			this->levinAttack->getAnimation()->stop();
			this->iceFreez->getAnimation()->stop();
			this->fireEffect->getAnimation()->stop();
			this->iceEffect->getAnimation()->stop(); 
			if (this->iceDeath)
			{
				this->iceDeath->getAnimation()->stop();
				this->stoneDeath->getAnimation()->stop();
				this->levinDeath->getAnimation()->stop();
			}
			if (this->unitCase)this->armor->getAnimation()->stop();
			if (this->armor)this->armor->getAnimation()->stop();
			if (this->shadow)this->shadow->getAnimation()->stop(); 
			if (this->signal)this->signal->getAnimation()->stop();
			if (this->giveHealth1)this->giveHealth1->getAnimation()->stop();
			if (this->giveHealth2)this->giveHealth2->getAnimation()->stop();
			if (this->giveHealth3)this->giveHealth3->getAnimation()->stop();
		};
	}
}