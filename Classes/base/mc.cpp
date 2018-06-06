#include "BaseHeaders.h"
#include "engine/World.h"

namespace engine
{
	MC::MC() :currentFrame(0), totalFrames(0)
	{
	}

	int MC::getTotalFrames(string aniName)
	{
		if(aniName == "")aniName = defAniName;
		AnimationData *aniData = this->getArmature()->_armatureData->animations[aniName];
		if(aniData)
			return aniData->frameCount + 1;
		return 0;
	};
	void MC::gotoAndStop(int cf, string aniName)
	{
		if(this->getArmature() == NULL || this->getAnimation() == NULL)return;
		if(cf == 0)cf = 1;
		if(aniName == "")aniName = defAniName;
		if(this->getAnimation()->getLastAnimationName() != aniName)
			this->getAnimation()->play(aniName, 1);
		this->currentFrame = (cf - 1) % totalFrames + 1;
		this->getAnimation()->gotoAndStopByFrame(aniName, currentFrame - 1);
	};
	void MC::nextFram()
	{
		if(this->getArmature() == NULL || this->getAnimation() == NULL)return;
		this->currentFrame++;
		gotoAndStop(this->currentFrame);
	};
	void MC::update()
	{
		nextFram();
	};
	void MC::stop(string aniName)
	{
		if(this->getArmature() == NULL || this->getAnimation() == NULL)return;
		if(aniName == "")aniName = defAniName;
		this->getAnimation()->stop(aniName);
	}
	void MC::play(int times)
	{
		if(this->getArmature() == NULL || this->getAnimation() == NULL)return;
		this->getAnimation()->play(defAniName, times);
	}
	void MC::play(string aniName, int times)
	{
		if(this->getArmature() == NULL || this->getAnimation() == NULL)return;
		if(aniName == "")aniName = defAniName;
		this->getAnimation()->play(aniName, times);
	}
	MovieClip * MC::getMc(MC * mc)
	{
		MovieClip * mvc = dynamic_cast<MovieClip*>(mc);
		while(mvc == NULL && mc != NULL)
		{
			MovieClipSub * mcvs = dynamic_cast<MovieClipSub*>(mc);
			mc = mcvs->mc;
			if(!mc)return NULL;
			mvc = dynamic_cast<MovieClip*>(mc);
		}
		return mvc;
	}
	void MC::addMcs(MC * mc, MovieClipSub * mcs)
	{
		mc->submc.push(mcs);
		MovieClip * mvc = getMc(mc);
		if(mvc && mc != mvc)
			mvc->addMcs(mcs);
	};
    void MC::addMCbs(MovieClipSubBase * mcs){
		this->mcbs.push(mcs);
        //if (ISTYPE(MCText, mcs)){
        //    this->mct.push((MCText*)mcs);
        //}
        //else if (ISTYPE(MCCase, mcs)){
        //    this->mcase.push((MCCase*)mcs);
        //}
    };
	bool MC::remove(MovieClipSub * mcs) {
		for(int i = 0; i < this->submc.size(); i++)
		{
			if(mcs == this->submc[i])
			{
				this->submc.remove(i);
				return true;
			}
		}
		return false;
	};

    bool MC::remove(MovieClipSubBase * mcs){
		for(int i = 0; i < this->mcbs.size(); i++)
		{
			if(mcs == this->mcbs[i])
			{
				this->mcbs.remove(i);
				return true;
			}
		}
		return false;

        //if (ISTYPE(MCText, mcs)){
        //    for (int i = 0; i < this->mct.size(); i++)
        //    {
        //        if (mcs == this->mct[i])
        //        {
        //            this->mct.remove(i);
        //            break;
        //        }
        //    }
        //}
        //else if (ISTYPE(MCCase, mcs)){
        //    for (int i = 0; i < this->mcase.size(); i++)
        //    {
        //        if (mcs == this->mcase[i])
        //        {
        //            this->mcase.remove(i);
        //            break;
        //        }
        //    }
        //}
    };
    MCText * MC::createText(string slotName){
		return new MCText(this, slotName);
    };
	 
    MovieClipSub * MC::createMovieClipSub(string slotName)
    {
		return  new MovieClipSub(this, slotName);
    }
	MovieClip * MC::createMovieClip(string slot, string rootPath, string armName, string dbName, string defAniName)
	{
		return  new MovieClip(this, slot,rootPath, armName, dbName, defAniName);
	};

    MCCase * MC::createCase(string slotName, bool draw)
	{
		return  new MCCase(this, slotName, draw);
    };
	MCSprite * MC::createSprite(string slotName, string file)
	{ 
		return new MCSprite(this, slotName, file);
	};
	MCSprite * MC::createSprite(string slotName, Sprite* file)
	{ 
		if(file)
			return new MCSprite(this, slotName, file);
		else
			return new MCSprite(this, slotName);
	};
	MCMask *  MC::createMask(string slotName)
	{
		return new MCMask(this, slotName);
	};

	//void MovieClipSubBase::addMCbs(MC * mc, MovieClipSubBase * mbs)
 //   { 
 //       mc->addMCbs(mbs);
 //   };
	 bool MovieClipSubBase::reinit() 
	 {
		 if(!this->slot)
		 {
			 if(mc->getArmature())
				 this->slot = mc->getArmature()->getSlot(slotName);
			 else
				 return false;
		 }
		 if(!this->slot) return false;
		 if(this->display == this->slot->getDisplay())
			 return false;
		 Node* thsi = ISTYPE(Node, this);
 		 Node * dis = (Node *) this->slot->getDisplay();
		 if(dis &&  ISTYPE(cocos2d::Sprite, dis))
		 {
			 isReady = true;
			 if(this->display )
			 {
				 thsi->retain();
				 this->display->removeChild(thsi);
				 this->display = (Node*)this->slot->getDisplay();
				 display->addChild(thsi);
				 if(!ISTYPE(MovieClip, this))
					display->setName(slotName);
				 else if(this->slot->_displayData)
					 display->setName(this->slot->_displayData->name);
				 thsi->release();
				 return true;
			  }
			  else
			  {
				  this->display = dis;
				  display->addChild(thsi);
				  if(!ISTYPE(MovieClip, this))
					  display->setName(slotName);
				  else if(this->slot->_displayData)
					  display->setName(this->slot->_displayData->name);
				  return true;
			  }
		 }
		 isReady = false;
		 return false;
	 };
	MCText::MCText(MC * mc, string slotName) :ui::Text()
	{
		init();
		this->autorelease();
		this->mc = mc; 
		this->slotName = slotName;
		this->setName(slotName);
        reinit();
		mc->addMCbs(this);
	};
    bool MCText::reinit()
    {
		return MovieClipSubBase::reinit();
   //     if (this->display == this->slot->getDisplay())
			//return false;
   //     Node * dis = (Node *) this->slot->getDisplay();
   //     if (!this->display)
   //     {
   //         this->display = dis;
   //         display->addChild(this);
   //         display->setName(slotName);
   //     }
   //     else if (this->display && dis)
   //     {
   //         this->retain();
   //         this->display->removeChild(this);
   //         this->display = (Node*)this->slot->getDisplay();
   //         display->addChild(this);
   //         display->setName(slotName);
   //         this->release();
   //     }
    };
    MCCase::MCCase(MC * mc, string slotName, bool draw) :BaseNode(), _draw(draw)
    {
		BaseNode::init();
        this->mc = mc;
        this->slotName = slotName;
        this->setName(slotName);
        reinit();
		mc->addMCbs(this);
    };
    bool MCCase::reinit()
    {
		if(MovieClipSubBase::reinit())
		{
			Size size = display->getContentSize();
			const dragonBones::Transform * origin = slot->getOrigin(); 
			this->setContentSize(Size(origin->scaleX*size.width, origin->scaleY*size.height));
			enableMouseHandler();
			if (_draw)drawRange();
			this->setPosition(origin->x, origin->y);
			return true;
		}
		return false;
	};

	MCSprite::MCSprite(MC * mc, string slotName, string file) :BaseSprite(file), initSprite(false)
	{ 
		this->mc = mc;
		this->slotName = slotName;
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
	};
	MCSprite::MCSprite(MC * mc, string slotName, cocos2d::Sprite * sprite) : BaseSprite(sprite) , initSprite(false)
	{
		this->mc = mc;
		this->slotName = slotName;
		this->setName(slotName); 
		reinit();
		mc->addMCbs(this);
	};
	MCSprite::MCSprite(MC * mc, string slotName) :initSprite(true)
	{
		this->mc = mc; 
		this->slotName = slotName;
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
	};
	bool MCSprite::reinit()
	{
		if(MovieClipSubBase::reinit())
		{
			if(initSprite && ISTYPE(cocos2d::Sprite, this->display))
			{
				cocos2d::Sprite * sprite = (Sprite*)this->display;
				this->initWithTexture(sprite->getTexture());
			}
			return true;
		}
		return false;
	};

	MCMask::MCMask(MC * mc, string slotName) 
	{
		this->mc = mc;
		this->slotName = slotName;
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
	};
	bool MCMask::reinit() 
	{
		MovieClipSubBase::reinit();
		if(this->display)
			this->mask = ISTYPE(Sprite,this->display);
		return this->mask != NULL;
	};

	void MovieClip::addMcs(MovieClipSub * mcs)
	{
		this->mcs.push(mcs);
	};
	void MovieClip::destroy()
	{
		int l = this->mcs.size();
		for(int i = l - 1; i >= 0; i--)
		{
			delete this->mcs[i];
			this->mcs[i] = NULL;
		}
	}
	void MovieClip::destroy(MovieClipSub * & ms)
	{ 
 		MC * par = NULL;
		for(int i = 0; i < this->mcs.size(); i++)
		{
			if(ms == this->mcs[i])
			{
				this->mcs.remove(i);
				par=ms->mc;
				par->remove(ms);
                delete ms;
                ms = NULL; 
                break;
			}
		}
	};
	bool MovieClip::remove(MovieClipSub * ms)
    {
		MC * par = NULL;
        for (int i = 0; i < this->mcs.size(); i++)
        {
            if (ms == this->mcs[i])
            {
                this->mcs.remove(i);
				par = ms->mc;
				if(par)
					par->remove(ms);
				else
					MC::remove(ms);
				return true;
            }
        }
		return false;
    };
   
    //void MovieClip::destroy(MCText * & mcs){
    //    for (int i = 0; i < this->mcs.size(); i++)
    //    {
    //        if (mcs == this->mct[i])
    //        {
    //            this->mct.remove(i);
    //            delete mcs;
    //            mcs = NULL;
    //            break;
    //        }
    //    }
    //};
    //void MovieClip::destroy(MCCase * & mcs){
    //    for (int i = 0; i < this->mcase.size(); i++)
    //    {
    //        if (mcs == this->mcase[i])
    //        {
    //            this->mcase.remove(i);
    //            delete mcs;
    //            mcs = NULL;
    //            break;
    //        }
    //    }
    //};

    void MovieClip::gotoAndStop(int cf, string aniName){
        MC::gotoAndStop(cf, aniName);
		int l = this->submc.size();
        for (int i = 0; i < l; i++)
			this->submc[i]->reinit();
        l = this->mcbs.size();
        for (int i = 0; i < l; i++)
			this->mcbs[i]->reinit();
        //l = this->mcase.size();
        //for (int i = 0; i < l; i++)
        //    this->mcase[i]->reinit();
    };
	MovieClip::MovieClip(dragonBones::CCArmatureDisplay * cont, string defAniName) :isOnce(false) 
	{
		std::map<std::string, dragonBones::AnimationData*> & animations = cont->getArmature()->_armatureData->animations;
		for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
		{
			std::string aniName = it.first;
			int totalFrames = it.second->frameCount;//+1;
			float duration = it.second->duration;
			CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
		}
		this->defAniName = defAniName;
		if(defAniName == "")
			this->defAniName = defAniName = cont->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = cont->getArmature()->_armatureData->animations[defAniName]->frameCount;// +1;
		float duration = cont->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		this->display = this->cont = cont;
		this->armName = cont->getArmature()->getName(); 
		BaseNode::init();
		addChild(display);
		//this->autorelease(); in BaseNode::init();
		this->setName(cont->getName());
		this->isReady = true;
	};
	MovieClip::MovieClip(string rootPath, string armName, string dbName, string defAniName) :isOnce(false) , cont(0)
	{
		this->rootPath = rootPath;
		this->armName = armName;
		this->dbName = dbName; 
		init(rootPath, armName, dbName, defAniName);
	};
	bool MovieClip::init(string rootPath, string armName, string dbName, string defAniName) 
	{ 
		if (isReady && this->getName()==armName){
			return true;
		}
		if(this->mc) 
			this->cont = this->loadArmature(rootPath, armName, dbName);
		else 
			this->display = this->cont = this->loadArmature(rootPath, armName, dbName);
		this->defAniName = defAniName;
		if(defAniName == "")
			this->defAniName = defAniName = this->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = this->getArmature()->_armatureData->animations[defAniName]->frameCount;//+ 1;
		float duration = this->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		BaseNode::init();
		addChild(cont);
		//this->autorelease(); in BaseNode::init();
		this->setName(armName);
		this->isReady = true;
	};
	MovieClip::MovieClip(string armName, string dbName, BaseNode *node) :cont(0)
	{ 
		this->armName = armName;
		this->dbName = dbName;
		this->display=this->cont = this->loadArmature(armName, dbName);
		if(defAniName == "")
			this->defAniName = defAniName = this->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = this->getArmature()->_armatureData->animations[defAniName]->frameCount;//+ 1;
		float duration = this->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		BaseNode::init();
		addChild(display);
		//this->autorelease(); in BaseNode::init();
		this->setName(armName); 
		if(node)node->addChild(this);
		this->isReady = true;
	};
	MovieClip::MovieClip(World * world, string rootPath, string armName, string dbName, string defAniName)
	{
		MovieClip(rootPath, armName, dbName, defAniName);
		if(world)setOnceMove(world);
	};

	MovieClip::MovieClip(MC *mc, dragonBones::Slot * slot, string rootPath, string armName, string dbName, string defAniName )
	{
		MovieClip(rootPath, armName, dbName, defAniName);
		this->mc = mc;
		this->slotName = slot->getName();
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
	};
	MovieClip::MovieClip(MC *mc, string slotName, string rootPath, string armName, string dbName, string defAniName)
	{
		MovieClip(rootPath, armName, dbName, defAniName);
		this->mc = mc;
		this->rootPath = rootPath;
		this->armName = armName;
		this->dbName = dbName;
		this->slotName = slotName;
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
	};
	MovieClip::MovieClip(MC *mc, string slotName, string rootPath, string dbName, string defAniName) :cont(0)
	{ 
 		this->mc = mc;
		this->slotName = slotName;
		this->setName(slotName);
		this->rootPath = rootPath; 
		this->dbName = dbName;
		this->defAniName = defAniName;
		reinit();
		mc->addMCbs(this);
	};
	bool MovieClip::reinit()
	{
		if(this->mc && MovieClipSubBase::reinit())
		{ 
			string _armName = armName;
			if(_armName.empty()) 
			//{
			//	if(ISTYPE(dragonBones::CCArmatureDisplay, this->display))
			//	{
			//		//dragonBones::CCArmatureDisplay * dis = ISTYPE(dragonBones::CCArmatureDisplay, this->display);
			//		Slot * _slot=this->getArmature()->getSlot(slotName);
			//		if(_slot)
			//		{
			//			Node * n = (Node *)_slot->getDisplay();
			//			if(_slot->_displayData)
			//			n->setName(this->slot->_displayData->name);
			//			_armName = n->getName();
			//		}
			//	}
			//	else if(ISTYPE(Sprite, this->display))
			//	{
			//		_armName = this->display->getName();
			//	}
			//	logInfo("_displayData->name", _armName);
			//} 
			_armName = this->display->getName();
			init(rootPath, _armName, dbName, defAniName);//display=_armName
		}
		return this->isReady;
	};


	bool MovieClip::setOnceMove(World * _world)
	{
		this->world = _world;
		if(world)
		{
			this->isOnce = true;
			this->world->addChild(this);
		}
		else
		{
			this->isOnce = false;
		}
		return isOnce;
	}
	bool MovieClip::init()
	{
		return BaseNode::init();
	}
	dragonBones::Animation *MovieClip::getAnimation()
	{
 		if(cont)
			return cont->getAnimation();
		else 
			return NULL;
	};
	dragonBones::Armature *MovieClip::getArmature()
	{
 		if(cont)
			return cont->getArmature();
		else
			return NULL; 
	};

	void MovieClip::setName(string name)
	{
		BaseNode::setName(name);
		if(this->mc && this->cont)
				this->cont->setName(name);
		else if(!this->mc && this->display)
			this->display->setName(name);
	};
	void MovieClip::onEnter()
	{
 		if(world && isOnce && cont)
		{
			cont->getEventDispatcher()->setEnabled(true);
			//container->getEventDispatcher()->addCustomEventListener(EventObject::FRAME_EVENT, std::bind(&MovieClip::onceMovieHandler, this, std::placeholders::_1));
			cont->getEventDispatcher()->addCustomEventListener(EventObject::COMPLETE, std::bind(&MovieClip::onceMovieHandler, this, std::placeholders::_1));
		}
		BaseNode::onEnter();
	};
	void MovieClip::onExit()
	{
		destroy();
		BaseNode::onExit();
	};

	void MovieClip::onceMovieHandler(cocos2d::EventCustom *event)
	{
		Node * target = event->getCurrentTarget();
		EventObject *eventObject = (EventObject*)(event->getUserData());
		string eventName = event->getEventName();//eventObject->type
		//eventObject->animationState->name aniName
		if(eventObject->type == dragonBones::EventObject::COMPLETE)
		{
			this->world->removeChild(this);
			//}
			//else if(eventName == EventObject::FRAME_EVENT)
			//{
			//	if(eventObject->name == "ending")
			//	{
			//	}
		}
		//case EventData::EventType::LOOP_COMPLETE:
		//	break;
	};
	MovieClipSub::MovieClipSub(MC *_mc, dragonBones::Slot * _slot, string defAniName) :arm(0)
	{
        this->mc=_mc;
        this->slot = _slot;
        this->slotName = slot->getName();
        this->display = NULL;
        this->arm = NULL;
		reinit();
		addMcs(mc, this);
	};
	MovieClipSub::MovieClipSub(MC *mc, string slotName, string defAniName) :arm(0)
	{
        this->mc = mc;
        this->slotName = slotName;
        this->display = NULL;
		this->slot = NULL; //mc->getArmature()->getSlot(slotName);
		reinit();
		addMcs(mc, this);
	}; 
	bool MovieClipSub::reinit()
    {
		if(!this->slot)
		{
			if(mc->getArmature())
				this->slot = mc->getArmature()->getSlot(slotName);
			else
				return false;
		}
		if(!this->slot) return false;
		if(this->arm == this->slot->getChildArmature())return false;
		this->arm = this->slot->getChildArmature();
        if (arm){
			this->display=(Node *)this->slot->getDisplay();
			if(this->display)this->display->setName(slot->getName());
			this->container = NULL;
			if(ISTYPE(CCArmatureDisplay, display))
				this->container = ISTYPE(CCArmatureDisplay, display);
			isReady = true;
            std::map<std::string, dragonBones::AnimationData*> & animations = this->arm->_armatureData->animations;
            for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
            {
                std::string aniName = it.first;
                int totalFrames = it.second->frameCount;//+ 1;
                float duration = it.second->duration;
                CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
            }
			/*string defAniName = this->defAniName;
            if (defAniName == "")*/
                defAniName = this->arm->_armatureData->defaultAnimation->name;
            totalFrames = this->arm->_armatureData->animations[defAniName]->frameCount;//+ 1;
            float duration = this->arm->_armatureData->animations[defAniName]->duration;
            CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
            this->gotoAndStop(1);
			return true;
		}
		else
		{
			isReady = false;
		}
		return false;
	}
	void MovieClipSub::setVisible(bool v) 
	{
		slot->setVisible(v);
		const std::vector<Bone*>& bones=arm->getBones();
		for each (Bone * bone in bones)
		{
			bone->setVisible(v);
		}
	};
	bool MovieClipSub::isVisible() 
	{
		return slot->getVisible();
	};

	cocos2d::Point MovieClipSub::getPosition()
	{
		Node * sp = (Node *)this->slot->getDisplay();
		return sp->getPosition();
	};
	float MovieClipSub::getPositionX()
	{
		Node * sp = (Node *)this->slot->getDisplay();
		return sp->getPositionX();
	};
	float MovieClipSub::getPositionY()
	{
		Node * sp = (Node *)this->slot->getDisplay();
		return sp->getPositionY();
	};
	void MovieClipSub::setPosition(cocos2d::Point pos) {
		Node * sp = (Node *)this->slot->getDisplay();
		sp->setPosition(pos);
	};
	void MovieClipSub::setPosition(float x, float y)
	{
		Node * sp = (Node *)this->slot->getDisplay();
		sp->setPosition(x,y);
	};
	void MovieClipSub::setPositionX(float x)
	{
		Node * sp = (Node *)this->slot->getDisplay();
		sp->setPositionX(x);
	};
	void MovieClipSub::setPositionY(float y)
	{
		Node * sp = (Node *)this->slot->getDisplay();
		sp->setPositionY(y);
	};
	Size MovieClipSub::getContentSize() {
		Node * sp = (Node *)this->slot->getDisplay();
		return sp->getContentSize();
	};
	Node* MovieClipSub::getDisplayNode()
	{ 
		return (Node *)this->slot->getDisplay();
	};

	dragonBones::Armature *MovieClipSub::getArmature()
	{
		return this->arm;
	};
	dragonBones::Animation *MovieClipSub::getAnimation()
	{
		return arm->getAnimation();
	};
	void MovieClipSub::gotoAndStop(int cf, string aniName)
	{
		MC::gotoAndStop(cf, aniName);
		int l = this->submc.size();
		for(int i = 0; i < l; i++)
			this->submc[i]->reinit();
		l = this->mcbs.size();
		for(int i = 0; i < l; i++)
			this->mcbs[i]->reinit();
		//l = this->mcase.size();
		//for (int i = 0; i < l; i++)
		//    this->mcase[i]->reinit();
	};

	ImageMovieClip::ImageMovieClip(string rootPath, string fileNamePre, int numFormat, int imgSize)
	{
		currentFrame = 0;
		totalFrames = imgSize - 1;
		if(!rootPath.empty() && rootPath.at(rootPath.length() - 1) != '/')
		{
			rootPath += "/";
		}
		filePre = rootPath + fileNamePre;
		char tmp[8];
		sprintf(tmp, "%04d", 1);
		cont = new BaseSprite(filePre + tmp + ".png");
		addChild(cont);
		playing = 0;
	};

	void ImageMovieClip::onEnter()
	{
		this->schedule(schedule_selector(ImageMovieClip::scheduleUpdate), 0.0f);
	}
	void ImageMovieClip::scheduleUpdate(float dt)
	{
		if(playing != -1)return;
		nextFram();
	};

	int ImageMovieClip::getTotalFrames(string aniName)
	{
		return totalFrames;
	};
	void ImageMovieClip::gotoAndStop(int cf, string aniName)
	{
		this->currentFrame = (cf) % (totalFrames + 1);
		char tmp[8];
		sprintf(tmp, "%04d", currentFrame);
		cont->setTexture(filePre + tmp + ".png");// = new BaseSprite(filePre + tmp + ".png");
		playing = true;
	};
	void ImageMovieClip::nextFram()
	{
		this->currentFrame++;
		gotoAndStop(this->currentFrame);
	};
	void ImageMovieClip::update()
	{
		nextFram();
	}
	void ImageMovieClip::play(string aniName)
	{
		playing = 1;
	}
	;
	void ImageMovieClip::stop(string aniName)
	{
		playing = 0;
	};

	SpriteClip::SpriteClip(BaseSprite * cont)
	{
		this->container = cont;
	};


}
