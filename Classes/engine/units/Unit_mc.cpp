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

		Unit_mc::Unit_mc(Unit* unit, string contName, int typeUnit) :contMcs(NULL),unit(unit), typeUnit(typeUnit), giveHealth1(NULL), giveHealth2(NULL), giveHealth3(NULL)
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
			cont = new MovieClip("unit/", contName);
			if (typeUnit==3 || typeUnit==13) 
            {
                Armature * arm = cont->getArmature()->getSlot("contSlot")->getChildArmature();
        		contMcs=new MovieClipSub(arm);
        		arm->getAnimation()->play();
            }
    		
			//DBCCFactory::getInstance()->loadDragonBonesData(contName + "/skeleton.xml", contName);
			//DBCCFactory::getInstance()->loadTextureAtlas(contName + "/texture.xml", contName);
			//cont = DBCCFactory::getInstance()->buildArmatureNode(contName);

			std::string amnis[16] = { "levindeath", "stonedeath", "icedeath", "buffhp", "airshock",
				"buffspeed", "dust1", "dust2", "dust3", "dust4", "fireattack", "levinattack", "iceattack", "icefreeze",
				"fireeffect","iceeffect"};
			//for (int i = 0; i< 16; i++)
			//{
			//	DBCCFactory::getInstance()->loadDragonBonesData(amnis[i] + "/skeleton.xml", amnis[i]);
			//	DBCCFactory::getInstance()->loadTextureAtlas( amnis[i] + "/texture.xml", amnis[i]);
			//}

			this->levinDeath = new MovieClip("unit/", "levindeath");// DBCCFactory::getInstance()->buildArmatureNode("levindeath");
			this->stoneDeath = new MovieClip("unit/", "stonedeath");//DBCCFactory::getInstance()->buildArmatureNode("stonedeath");
			this->iceDeath = new MovieClip("unit/", "icedeath");// DBCCFactory::getInstance()->buildArmatureNode("icedeath");
			this->buffHP = new MovieClip("unit/", "buffhp");// DBCCFactory::getInstance()->buildArmatureNode("buffhp");
			this->airShock = new MovieClip("unit/", "airshock");// DBCCFactory::getInstance()->buildArmatureNode("airshock");
			this->buffSpeed = new MovieClip("unit/", "buffspeed");// DBCCFactory::getInstance()->buildArmatureNode("buffspeed");
			this->dust1 = new MovieClip("unit/", "dust1");// DBCCFactory::getInstance()->buildArmatureNode("dust1");
			this->dust2 = new MovieClip("unit/", "dust2");// DBCCFactory::getInstance()->buildArmatureNode("dust2");
			this->dust3 = new MovieClip("unit/", "dust3");// DBCCFactory::getInstance()->buildArmatureNode("dust3");
			this->dust4 = new MovieClip("unit/", "dust4");// DBCCFactory::getInstance()->buildArmatureNode("dust4");
			this->fireAttack = new MovieClip("unit/", "fireattack");// DBCCFactory::getInstance()->buildArmatureNode("fireattack");
			this->levinAttack = new MovieClip("unit/", "levinattack");// DBCCFactory::getInstance()->buildArmatureNode("levinattack");
			this->iceAttack = new MovieClip("unit/", "iceattack");// DBCCFactory::getInstance()->buildArmatureNode("iceattack");
			this->iceFreez = new MovieClip("unit/", "icefreeze");// DBCCFactory::getInstance()->buildArmatureNode("icefreeze");
			this->fireEffect = new MovieClip("unit/", "fireeffect");// DBCCFactory::getInstance()->buildArmatureNode("fireeffect");
			this->iceEffect = new MovieClip("unit/", "iceeffect");// DBCCFactory::getInstance()->buildArmatureNode("iceeffect");
			this->selectUnit = cocos2d::Sprite::create("selectunit.png");
		 
			if (typeUnit == 28){
				this->giveHealth1 = new MovieClip("unit/", "giveHealth1");// DBCCFactory::getInstance()->buildArmatureNode("giveHealth1");
				this->giveHealth1 = new MovieClip("unit/", "giveHealth2");// DBCCFactory::getInstance()->buildArmatureNode("giveHealth2");
				this->giveHealth1 = new MovieClip("unit/", "giveHealth3");// DBCCFactory::getInstance()->buildArmatureNode("giveHealth3");
			}
			else if (this->typeUnit == 29 || this->typeUnit == 30){
				this->dustAnima = new MovieClip("unit/", "dustAnima");// DBCCFactory::getInstance()->buildArmatureNode("dustAnima");
			}
			healthBar = HealthBar::create();

			//this->fireEffect->getEventDispatcher()->addCustomEventListener(EventObject::COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->fireEffect->getCCEventDispatcher()->addCustomEventListener(EventData::LOOP_COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->fireEffect->getCCEventDispatcher()->addCustomEventListener(EventData::FRAME_EVENT, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));

			this->iceFreez->getEventDispatcher()->addCustomEventListener(EventObject::COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->iceFreez->getCCEventDispatcher()->addCustomEventListener(EventData::LOOP_COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->iceFreez->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			
			this->iceDeath->getEventDispatcher()->addCustomEventListener(EventObject::FRAME_EVENT, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));

			 
		}; 
		void Unit_mc::mcHandler(cocos2d::EventCustom *event)
		{
			EventObject *eventObject = (EventObject*)(event->getUserData());
			string eventName = event->getEventName();//eventObject->type
			string nodeName = eventObject->animationState->name;
			if(eventName == dragonBones::EventObject::COMPLETE)
			{
				if(nodeName == "iceeffect")
				{
					//string aniName = eventObject->animationState->name;
					//if(aniName == "begin")
					//{
					//	this->iceEffect->getAnimation()->play("continue");
					//}
					//else if(aniName == "end")
					//{
					//	unit->iceEffectFlag = false;
					//	this->iceEffect->getAnimation()->stop("");
					//	this->iceEffect->setVisible(false);
					//}
				}
				else if(nodeName == "icefreeze")
				{
					//string aniName = eventObject->animationState->name;
					//if("icemandead" == aniName)
					//{
					//	unit->icemanFlag = false;
					//	this->iceFreez->getAnimation()->stop("");
					//	this->iceFreez->setVisible(false);
					//}
				}
				else if(nodeName == "fireeffect")
				{
					//this->fireEffect->getAnimation()->play("continue");
				}
				else if(nodeName == "icedeath")
				{

				}
			}
			else if(eventName == EventObject::FRAME_EVENT)
			{
				if(nodeName == "icedeath" && eventObject->name == "aa")
				{
					this->cont->setVisible(false);
				}
			}
			 

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
			this->cont->stop();  
			this->buffHP->stop();
			this->airShock->stop();
			this->buffSpeed->stop();
			this->dust1->stop();
			this->dust2->stop();
			this->dust3->stop();
			this->dust4->stop();
			this->fireAttack->stop();
			this->iceAttack->stop();
			this->levinAttack->stop();
			this->iceFreez->stop();
			this->fireEffect->stop();
			this->iceEffect->stop(); 
			if (this->iceDeath)
			{
				this->iceDeath->stop();
				this->stoneDeath->stop();
				this->levinDeath->stop();
			}
			if (this->unitCase)this->armor->stop();
			if (this->armor)this->armor->stop();
			if (this->shadow)this->shadow->stop(); 
			if (this->signal)this->signal->stop();
			if (this->giveHealth1)this->giveHealth1->stop();
			if (this->giveHealth2)this->giveHealth2->stop();
			if (this->giveHealth3)this->giveHealth3->stop();
		};
		
        void Unit_mc::onExit()
        {
            if(contMcs){
                delete contMcs;
            }
        };

    }
}