#include "Unit_mc.h" 
#include "Unit.h"

namespace engine
{
	namespace units
	{
		Unit_mc::Unit_mc(Unit* unit, string contName, int typeUnit) : unit(unit), typeUnit(typeUnit), giveHealth1(NULL), giveHealth2(NULL), giveHealth3(NULL), signal(0),
			contName(contName), MovieClip("unit/", contName, contName)
		{
			iceDeathFlag = 0;
			stoneDeathFlag = 0;
			levinDeathFlag = 0;
			healthBarCounter = 0;

			levinDeath = this->createMovieClip("levinDeath", "unit/", "levinDeath", "UnitBase_mc");
			stoneDeath = this->createMovieClip("stoneDeath", "unit/", "stoneDeath", "UnitBase_mc");
			iceDeath = this->createMovieClip("iceDeath", "unit/", "iceDeath", "UnitBase_mc");
			buffHP = this->createMovieClip("buffHP", "unit/", "buffHP", "UnitBase_mc");
			airShock = this->createMovieClip("airShock", "unit/", "airShock", "UnitBase_mc");
			buffSpeed = this->createMovieClip("buffSpeed", "unit/", "buffSpeed", "UnitBase_mc");
			dust1 = this->createMovieClip("dust1", "unit/", "dust1", "UnitBase_mc");
			dust2 = this->createMovieClip("dust2", "unit/", "dust2", "UnitBase_mc");
			dust3 = this->createMovieClip("dust3", "unit/", "dust3", "UnitBase_mc");
			fireAttack = this->createMovieClip("fireAttack", "unit/", "fireAttack", "UnitBase_mc");
			iceAttack = this->createMovieClip("iceAttack", "unit/", "iceAttack", "UnitBase_mc");
			levinAttack = this->createMovieClip("levinAttack", "unit/", "levinAttack", "UnitBase_mc");
			iceFreez = this->createMovieClip("iceFreez", "unit/", "iceFreez", "UnitBase_mc");
			fireEffect = this->createMovieClip("fireEffect", "unit/", "fireEffect", "UnitBase_mc");
			iceEffect = this->createMovieClip("iceEffect", "unit/", "iceEffect", "UnitBase_mc");
			armor = this->createMovieClip("armor", "unit/", "armor", "UnitBase_mc");
			healthBar = this->createMovieClip("healthBar", "unit/", "healthBar", "UnitBase_mc");
			shadow = this->createMovieClip("shadow", "unit/", "shadow", "UnitBase_mc");
			selectUnit = this->createMovieClip("selectUnit", "unit/", "selectUnit", "UnitBase_mc");
			dust4 = this->createMovieClip("dust4", "unit/", "dust4", "UnitBase_mc");
			cont = this->createMovieClipSub("cont");
			unitCase = this->createCase("unitCase");

			healthBarGetDamage = (Sprite*)healthBar->getArmature()->getSlot("getDamage")->getDisplay();
			healthBarCont = (Sprite*)healthBar->getArmature()->getSlot("cont")->getDisplay();


			this->setPosition(0, 0);


			if (typeUnit == 28){
				this->giveHealth1 = this->createMovieClipSub("giveHealth1");// DBCCFactory::getInstance()->buildArmatureNode("giveHealth1");
				this->giveHealth2 = this->createMovieClipSub("giveHealth2");// DBCCFactory::getInstance()->buildArmatureNode("giveHealth2");
				this->giveHealth3 = this->createMovieClipSub("giveHealth3");// DBCCFactory::getInstance()->buildArmatureNode("giveHealth3");
			}
			else if (this->typeUnit == 29 || this->typeUnit == 30){
				this->dustAnima = this->createMovieClipSub("dustAnima");// DBCCFactory::getInstance()->buildArmatureNode("dustAnima");
			}
			////this->fireEffect->getEventDispatcher()->addCustomEventListener(EventObject::COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			////this->fireEffect->getCCEventDispatcher()->addCustomEventListener(EventData::LOOP_COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			////this->fireEffect->getCCEventDispatcher()->addCustomEventListener(EventData::FRAME_EVENT, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->iceFreez->getEventDispatcher()->addCustomEventListener(EventObject::COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			////this->iceFreez->getCCEventDispatcher()->addCustomEventListener(EventData::LOOP_COMPLETE, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			////this->iceFreez->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));
			//this->iceDeath->getEventDispatcher()->addCustomEventListener(EventObject::FRAME_EVENT, std::bind(&Unit_mc::mcHandler, this, std::placeholders::_1));


		};
		void Unit_mc::mcHandler(cocos2d::EventCustom *event)
		{
			EventObject *eventObject = (EventObject*)(event->getUserData());
			string eventName = event->getEventName();//eventObject->type
			string nodeName = eventObject->animationState->name;
			if (eventName == dragonBones::EventObject::COMPLETE)
			{
				if (nodeName == "iceeffect")
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
				else if (nodeName == "icefreeze")
				{
					//string aniName = eventObject->animationState->name;
					//if("icemandead" == aniName)
					//{
					//	unit->icemanFlag = false;
					//	this->iceFreez->getAnimation()->stop("");
					//	this->iceFreez->setVisible(false);
					//}
				}
				else if (nodeName == "fireeffect")
				{
					//this->fireEffect->getAnimation()->play("continue");
				}
				else if (nodeName == "icedeath")
				{

				}
			}
			else if (eventName == EventObject::FRAME_EVENT)
			{
				if (nodeName == "icedeath" && eventObject->name == "aa")
				{
					this->cont->setVisible(false);
				}
			}


		};

		bool Unit_mc::init(){
			MovieClip::init();
			this->levinDeath->setVisible(false);
			this->stoneDeath->setVisible(false);
			this->iceDeath->setVisible(false);
			this->buffHP->setVisible(false);
			this->airShock->setVisible(false);
			this->buffSpeed->setVisible(false);
			this->dust1->setVisible(false);
			this->dust2->setVisible(false);
			this->dust3->setVisible(false);
			this->fireAttack->setVisible(false);
			this->iceAttack->setVisible(false);
			this->levinAttack->setVisible(false);
			this->iceFreez->setVisible(false);
			this->fireEffect->setVisible(false);
			this->iceEffect->setVisible(false);
			this->armor->setVisible(false);
			this->healthBar->setVisible(false);
			this->shadow->setVisible(false);
			this->selectUnit->setVisible(false);
			this->dust4->setVisible(false);

			this->healthBarGetDamage->setVisible(false);



			if (this->signal)this->signal->setVisible(true);
			if (this->giveHealth1)this->giveHealth1->setVisible(true);
			if (this->giveHealth2)this->giveHealth2->setVisible(true);

			cont->setVisible(true);

			return true;
		};
		void Unit_mc::stop(){
			MovieClip::stop();
			//this->cont->stop();  
			//this->buffHP->stop();
			//this->airShock->stop();
			//this->buffSpeed->stop();
			//this->dust1->stop();
			//this->dust2->stop();
			//this->dust3->stop();
			//this->dust4->stop();
			//this->fireAttack->stop();
			//this->iceAttack->stop();
			//this->levinAttack->stop();
			//this->iceFreez->stop();
			//this->fireEffect->stop();
			//this->iceEffect->stop(); 
			//if (this->iceDeath)
			//{
			//	this->iceDeath->stop();
			//	this->stoneDeath->stop();
			//	this->levinDeath->stop();
			//}
			//if (this->unitCase)this->armor->stop();
			//if (this->armor)this->armor->stop();
			////if (this->shadow)this->shadow->stop(); 
			//if (this->signal)this->signal->stop();
			//if (this->giveHealth1)this->giveHealth1->stop();
			//if (this->giveHealth2)this->giveHealth2->stop();
			//if (this->giveHealth3)this->giveHealth3->stop();
		};



	}
}