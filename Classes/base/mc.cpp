#include "BaseHeaders.h"
#include "engine/World.h"

namespace engine
{
	MC::MC() :currentFrame(0), totalFrames(0)
	{
	}

    int MC::getTotalFrames(const string &  _aniName)
	{
        string aniName = _aniName;
		if(aniName == "")aniName = defAniName;
		AnimationData *aniData = this->getArmature()->_armatureData->animations[aniName];
		if(aniData)
			return aniData->frameCount + 1;
		return 0;
	};
    void MC::gotoAndStop(int cf, const string & _aniName)
	{
		if(this->getArmature() == NULL || this->getAnimation() == NULL)return;
		if(cf == 0)cf = 1;
        string aniName = _aniName;
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
    void MC::stop(const string &  _aniName)
	{
		if(this->getArmature() == NULL || this->getAnimation() == NULL)return;
        string aniName = _aniName;
        if(aniName == "")aniName = defAniName;
		this->getAnimation()->stop(aniName);
	}
	void MC::play(int times)
	{
		if(this->getArmature() == NULL || this->getAnimation() == NULL)return;
		this->getAnimation()->play(defAniName, times);
	}
    void MC::play(const string &  _aniName, int times)
	{
		if(this->getArmature() == NULL || this->getAnimation() == NULL)return;
        string aniName = _aniName;
        if(aniName == "")aniName = defAniName;
		this->getAnimation()->play(aniName, times);
	}
	MovieClip * MC::getRootMc(MC * mc)
	{
		while (mc != NULL)
		{
			if (ISTYPE(MovieClip, mc))
				return ISTYPE(MovieClip, mc); 
			else if (ISTYPE(MovieClipSub, mc)){
				MovieClipSub * mcvs = ISTYPE(MovieClipSub, mc);// dynamic_cast<MovieClipSub*>(mc);
				mc = mcvs->mc;
				if (!mc)return NULL;
			}
		}
		return NULL;
	}
	void MC::addMcs(MC * mc, MovieClipSub * mcs)
	{
		mc->submc.push(mcs);
		MovieClip * mvc = getRootMc(mc);
		if(mvc)// && mc != mvc
			mvc->addMcs(mcs);
	};
    MovieClipSub*  MC::getMemSubMC(const string &  slotName)
	{
		for(int i = 0; i < this->submc.size(); i++)
		{
			if(slotName == this->submc[i]->getName())
			{ 
				return this->submc[i];
			}
		}
		return NULL;
	};
    Node *  MC::getMemNode(const string &  slotName)
	 {
		for (int i = 0; i < this->submcbs.size(); i++)
		 {
			MovieClipSubBase *_node = ISTYPE(MovieClipSubBase, this->submcbs[i]);
			if (_node && slotName == _node->slotName)
			 { 
				return ISTYPE(Node, this->submcbs[i]);
			 }
		 }
		 return NULL;
	};
 
    void MC::addMCbs(MovieClipSubBase * mcs){
		this->submcbs.push(mcs);
		if (ISTYPE(Node, mcs)){
			ISTYPE(Node, mcs)->retain();
		}
		MovieClip * mvc = getRootMc(this);
		if (mvc)
			mvc->mcbs.push(mcs);
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
		for (int i = 0; i < this->submcbs.size(); i++)
		{
			if (mcs == this->submcbs[i])
			{
				this->submcbs.remove(i);
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
    MCText * MC::createText(const string &  slotName)
    {
		return new MCText(this, slotName);
    };
	 
    MovieClipSub * MC::createMovieClipSub(const string &  slotName)
    {
		return  new MovieClipSub(this, slotName);
    }
    MovieClip * MC::createMovieClip(const string &  slot, const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName)
	{
		return  new MovieClip(this, slot,rootPath, armName, dbName, defAniName);
	};
    MovieClip * MC::createMovieClip(const string &  slot, const string &  rootPath, const string &  dbName)
	{
		return  new MovieClip(this, slot,rootPath,  dbName);
	};
    MovieClip * MC::createMovieClip(const string &  slot, MovieClip * mc)
	{
		mc->mc=this;
		mc->display=NULL;
		mc->slotName=slot;
		mc->reinit();
		this->addMCbs(mc);
		return mc;
	};
	
	MCCase * MC::createCase(const string &  slotName, bool mouseEnabled, bool draw)
	{
		return  new MCCase(this, slotName, mouseEnabled, draw);
    };
    MCSprite * MC::createSprite(const string &  slotName, const string &  file)
	{ 
		return new MCSprite(this, slotName, file);
	};
    MCSprite * MC::createSprite(const string &  slotName, Sprite* file)
	{ 
		return new MCSprite(this, slotName, file);
	};
    MCMask *  MC::createMask(const string &  slotName)
	{
		return new MCMask(this, slotName);
	};
    Sprite * MC::getSprite(const string &  slotName)
    {
		return (Sprite*)this->getArmature()->getSlot(slotName)->getDisplay();
	};

	//void MovieClipSubBase::addMCbs(MC * mc, MovieClipSubBase * mbs)
 //   { 
 //       mc->addMCbs(mbs);
 //   };
	void MovieClipSubBase::setVisible(bool v){ 
		this->visible = v;
		//if (this->display)this->display->setVisible(v);
	};
	Vec2 MovieClipSubBase::getDisPosition(){
		float x = bone->getOrigin()->x;
		float y = bone->getOrigin()->y;
		float x1 = slot->getOrigin()->x;
		float y1 = slot->getOrigin()->y;
		x += x1;
		y += y1;
		Node * dis = (Node *) this->slot->getDisplay();
		if (root){
			const dragonBones::Transform*  orgin = root->getOrigin();
			y = -(orgin->y + y);
		}
		else{
			y = -(y);
		}
		//Size mcSize = dis->getContentSize();
		//dragonBones::Transform*  global = root->getGlobal();
		//Node * disPar = dis->getParent();
		//dragonBones::Transform*  offset = root->getOffset();
		//const dragonBones::Rectangle & aabb = mc->getArmature()->getArmatureData()->aabb;
		//if (ISTYPE(dragonBones::CCArmatureDisplay, disPar)){
		//	dragonBones::CCArmatureDisplay * aniDis = ISTYPE(dragonBones::CCArmatureDisplay, disPar);
		//	const dragonBones::Rectangle & aabb = aniDis->getArmature()->getArmatureData()->aabb;
		//	y = y;
		//}
		disPos.x = x;
		disPos.y= y;// = disPar->convertToNodeSpaceAR(Vec2(x, y));
		return disPos;
	};
	Vec2 MovieClipSubBase::getDisArPos(){
 		Vec2 thisPos;
		//return  thisPos;
		if (!ISTYPE(MCCase, this) && !ISTYPE(MCText, this) )//&& !ISTYPE(MovieClip, this)
		{ 
			Node * dis = (Node *) this->slot->getDisplay();
			std::setAnchorPoint(dis, Vec2(0.5, 0.5));
			thisPos = dis->convertToNodeSpace(dis->getPosition());
		}
		//if (ISTYPE(MovieClipSub, this->mc) && ISTYPE(MCCase, this)){
		//	MovieClipSub * mcs = ISTYPE(MovieClipSub, this->mc);
		//	Size mcSize = mcs->container->getContentSize();
		//	const dragonBones::Rectangle & aabb = mcs->container->getArmature()->getArmatureData()->aabb;
		//	thisPos.x = -aabb.width / 2;
		//	thisPos.y = -aabb.height / 2;
		// }  
		return  thisPos;
	};
	void MovieClipSubBase::setDisScale(){
		if (!ISTYPE(MCText, this)){
			float scx = slot->getOrigin()->scaleX * bone->getOrigin()->scaleX;
			if (root) scx *= root->getOrigin()->scaleX;
			display->setScaleX(scx);
			float scy = slot->getOrigin()->scaleY * bone->getOrigin()->scaleY;
			if (root) scy *= root->getOrigin()->scaleY;
			display->setScaleY(scy);
		}
		else{
			display->setContentSize(Size(40, 25));
			display->setScaleX(1);
			display->setScaleY(1);
			MCText * text=ISTYPE(MCText, this);
			std::setText(text,"TEST");
		}
	}
	 bool MovieClipSubBase::reinit() 
	 {
		 if(!this->slot)
		 {
			 if (mc->getArmature())
			 {
				 this->slot = mc->getArmature()->getSlot(slotName);
				 this->bone = mc->getArmature()->getBone(slotName);
				 this->root = mc->getArmature()->getBone("root");
			 }
			 else
				 return false;
		 }
		 if(!this->slot) return false;
		 if(this->display == this->slot->getDisplay())
			 return false;
		 Node* thsi = ISTYPE(Node, this);
 		 Node * dis = (Node *) this->slot->getDisplay();
		 if (dis &&  ISTYPE(cocos2d::Sprite, dis))
		 {
			isReady = true;
			Vec2 disPos=getDisPosition();
			bool expCase = !ISTYPE(MCCase, this) && !ISTYPE(MCText, this);// && !ISTYPE(MovieClip, this);
			 if(this->display )
			 {
				 thsi->retain();
				 this->display->removeChild(thsi);
				 this->display = dis;
				 if (expCase)std::setAnchorPoint(display);
				 else std::setAnchorPoint(display, Vec2(0.5, 0.5));
				 display->addChild(thsi);
				 dis->setPosition(disPos);
				 setDisScale();
				 if (expCase){
					Vec2 thisPos = getDisArPos();
					thsi->setPosition(thisPos);
				 }

				 //std::setAnchorPoint(display, Vec2(0.5, 0.5));
				 if (!ISTYPE(MovieClip, this))
					display->setName(slotName);
				 else if(this->slot->_displayData)
					 display->setName(this->slot->_displayData->name);
				 thsi->release();
				 display->setVisible(visible);
				 return true;
			  }
			  else
			  {
				  this->display = dis;
				  if (expCase) std::setAnchorPoint(display);
				  else std::setAnchorPoint(display, Vec2(0.5, 0.5));
				  display->addChild(thsi);
				  dis->setPosition(disPos);
				  setDisScale();
				  if (expCase){
					  Vec2 thisPos = getDisArPos();
					  thsi->setPosition(thisPos);
				  }
				  //std::setAnchorPoint(display, Vec2(0.5, 0.5));

				  if(!ISTYPE(MovieClip, this))
					  display->setName(slotName);
				  else if(this->slot->_displayData)
					  display->setName(this->slot->_displayData->name);
				  display->setVisible(visible);
				  return true;
			  }
		 }
		 isReady = false;
		 return false;
	 };
     MCText::MCText(MC * mc, const string &  slotName) :ui::Text()
    { 
		init();
        this->setFontName("Arial");//Arial
        //this->setFontName("宋体");//Arial
        this->setFontSize(12);
		//setNodeType("MCText");
        this->setColor(Color3B::YELLOW);
		this->autorelease();
		this->mc = mc; 
		this->slotName = slotName;
		this->setName(slotName);
        reinit();
		mc->addMCbs(this);
	};
	void MCText::setVisible(bool v){
		ui::Text::setVisible(v);
		MovieClipSubBase::setVisible(v);
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
	MCCase::MCCase(MC * mc, const string &  slotName, bool mouseEnabled, bool draw) :BaseNode(), _draw(draw)
    {
		setNodeType("MCCase");
		BaseNode::init();
        this->mc = mc;
		this->mouseEnabled=mouseEnabled;
        this->slotName = slotName;
        this->setName(slotName);
        reinit();
		mc->addMCbs(this);
		addEventNode(this);
    };
	void MCCase::setVisible(bool v){
		MovieClipSubBase::setVisible(v);
		BaseNode::setVisible(v);
	};
    bool MCCase::reinit()
    {
		if(MovieClipSubBase::reinit())
		{
			//Size size = display->getContentSize();
			const dragonBones::Transform * origin = slot->getOrigin(); 
			//this->setContentSize(Size(origin->scaleX*size.width, origin->scaleY*size.height));
			////enableMouseHandler(); //涓嶄娇鐢ㄥ崟鐙簨浠?
			////this->setMouseEnabled(true);
			//if (_draw)drawRange();
			//this->setPosition(origin->x, origin->y);
			//return true;

			Size size = display->getContentSize();
			//size=Size(this->display->getScaleX()*size.width, this->display->getScaleY()*size.height);
			this->setContentSize(size);
			//enableMouseHandler(); //涓嶄娇鐢ㄥ崟鐙簨浠?
			//this->setMouseEnabled(true);
			if (_draw)drawRange();
			this->setPosition(origin->x, origin->y);
			return true;

		}
		return false;
	};

    MCSprite::MCSprite(MC * mc, const string &  slotName, const string &  file) :BaseSprite(file), initSprite(false)
	{ 
		setNodeType("MCSprite");
		this->mc = mc;
		this->slotName = slotName;
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
		addEventNode(this);

	};
    MCSprite::MCSprite(MC * mc, const string &  slotName, cocos2d::Sprite * sprite) : BaseSprite(sprite), initSprite(false)
	{
		setNodeType("MCSprite");
		this->mc = mc;
		this->slotName = slotName;
		this->setName(slotName); 
		reinit();
		mc->addMCbs(this);
	};
    MCSprite::MCSprite(MC * mc, const string &  slotName) :initSprite(true)
	{
		setNodeType("MCSprite");
		this->mc = mc;
		this->slotName = slotName;
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
	};
	void MCSprite::setVisible(bool v){
		MovieClipSubBase::setVisible(v);
		BaseSprite::setVisible(v);
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

    MCMask::MCMask(MC * mc, const string &  slotName) :mask(0)
	{
		setNodeType("MCMask");
		this->mc = mc;
		this->slotName = slotName;
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
	};
	void MCMask::setVisible(bool v){
		BaseNode::setVisible(v);
		MovieClipSubBase::setVisible(v);
        if(this->mask)
            mask->setVisible(v);
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
		for (int i = l - 1; i >= 0; i--)
		{
			delete this->mcs[i];
			this->mcs[i] = NULL;
		}
		this->mcs.clear();
		l = this->mcbs.size();
		for (int i = l - 1; i >= 0; i--)
		{
			if (ISTYPE(Node, this->mcbs[i]))
				ISTYPE(Node, this->mcbs[i])->release();
			else
				delete this->mcbs[i];
			this->mcbs[i] = NULL;
		}
		this->mcbs.clear();
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

    void MovieClip::gotoAndStop(int cf, const string &  aniName)
    {
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
    MovieClip::MovieClip(dragonBones::CCArmatureDisplay * container, const string &  _defAniName) :isOnce(false), container(0), world(0), myFrame(0), speedX(0), speedY(0)
	{
		setNodeType("MovieClip");
		//std::map<std::string, dragonBones::AnimationData*> & animations = container->getArmature()->_armatureData->animations;
		//for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
		//{
		//	std::string aniName = it.first;
		//	int totalFrames = it.second->frameCount+1;//;
		//	float duration = it.second->duration;
		//	CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
		//}
        string defAniName = _defAniName;
        this->defAniName = defAniName;
		if(defAniName == "")
			this->defAniName = defAniName = container->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = container->getArmature()->_armatureData->animations[defAniName]->frameCount+1;// ;
		float duration = container->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		this->display = this->container = container;
		this->armName = container->getArmature()->getName(); 
		BaseNode::init();
		addChild(display);
		this->setName(container->getName());
        this->gotoAndStop(1);
		//std::setAnchorPoint(display, true);
        //this->autorelease(); in BaseNode::init();
		this->isReady = true;
	};
    MovieClip::MovieClip(const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName) :isOnce(false), container(0), world(0), myFrame(0), speedX(0), speedY(0)
	{
		setNodeType("MovieClip");
		this->rootPath = rootPath;
		this->armName = armName;
		this->dbName = dbName; 
		init(rootPath, armName, dbName, defAniName);
	};
    bool MovieClip::init(const string &  rootPath, const string &  armName, const string &  dbName, const string &  _defAniName)
	{ 
        if(isReady && this->container && this->getName() == armName)
        {
			return true;
		}
		if(this->mc) 
			this->container = this->loadArmature(rootPath, armName, dbName);
		else 
			this->display = this->container = this->loadArmature(rootPath, armName, dbName);
        string defAniName = _defAniName;
        this->defAniName = defAniName;
		if(defAniName == "")
			this->defAniName = defAniName = this->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = this->getArmature()->_armatureData->animations[defAniName]->frameCount+ 1;//;
		float duration = this->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		addChild(container);
        this->gotoAndStop(1);
		//std::setAnchorPoint(display, true);

		//this->autorelease(); in BaseNode::init();
		this->setName(armName);
		this->isReady = true;
		init();
	
		return true;
	};
	MovieClip::MovieClip(const string &  armName, const string &  dbName, BaseNode *node) :isOnce(false), container(0), world(0), myFrame(0), speedX(0), speedY(0)
	{ 
		setNodeType("MovieClip");
		this->armName = armName;
		this->dbName = dbName;
		this->display=this->container = this->loadArmature(armName, dbName);
		if(defAniName == "")
			this->defAniName = defAniName = this->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = this->getArmature()->_armatureData->animations[defAniName]->frameCount+ 1;//;
		float duration = this->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		BaseNode::init();
		addChild(display);
		//this->autorelease(); in BaseNode::init();
		this->setName(armName); 
        this->gotoAndStop(1);
		//std::setAnchorPoint(display,true);
		if (node)node->addChild(this);
		this->isReady = true;
	};
    MovieClip::MovieClip(World * world, const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName) :MovieClip(rootPath, armName, dbName, defAniName)
	{ 
		if(world)setOnceMove(world);
	};

	MovieClip::MovieClip(MC *mc, dragonBones::Slot * slot, const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName) :isOnce(false), container(0), world(0), myFrame(0), speedX(0), speedY(0)
	{ 
		this->mc = mc;
		this->slotName = slot->getName();
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
	};
	MovieClip::MovieClip(MC *mc, const string &  slotName, const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName) :isOnce(false), container(0), world(0), myFrame(0), speedX(0), speedY(0)
	{
		
		this->mc = mc;
		this->rootPath = rootPath;
		this->armName = armName;
		this->dbName = dbName;
		this->slotName = slotName;
		this->setName(slotName);
		reinit();
		mc->addMCbs(this);
	};
	MovieClip::MovieClip(MC *mc, const string &  slotName, const string &  rootPath, const string &  dbName) :isOnce(false), container(0), world(0), myFrame(0), speedX(0), speedY(0)
	{
		setNodeType("MovieClip");
		this->mc = mc;
		this->slotName = slotName;
		this->setName(slotName);
		this->rootPath = rootPath; 
		this->dbName = dbName;
		this->defAniName = "";
		reinit();
		mc->addMCbs(this);
	};
	void MovieClip::setVisible(bool v){
		BaseNode::setVisible(v);
		MovieClipSubBase::setVisible(v);
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

    void MovieClip::update(float dt)
    {
        nextFram();
    };	
    void MovieClipSub::update(float dt)
    {
        nextFram();
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
		  BaseNode::init();
		  Size size = this->container->getContentSize();
		  const dragonBones::Rectangle & aabb = this->getArmature()->getArmatureData()->aabb;
		  if (size.width = 0 || size.height == 0){
			  this->setContentSize(Size(aabb.width, aabb.height));
  		  }
		  //this->container->setPosition(Vec2(aabb.x, aabb.y));
		  return true;
	}
	void MovieClip::drawRange(){
		const dragonBones::Rectangle & aabb = this->getArmature()->getArmatureData()->aabb;
		DrawNode* drawNode = DrawNode::create();
		this->addChild(drawNode);
		Vec2 ap = this->getAnchorPoint();
		//Vec2 st = this->convertToWorldSpace(Vec2(aabb.x, aabb.y));
		//st = this->convertToNodeSpaceAR(st);
		//Vec2 et = this->convertToWorldSpace(Vec2(aabb.x + aabb.width, aabb.y + aabb.height));
		//et = this->convertToNodeSpaceAR(et);
		//drawNode->drawRect(st, et, Color4F::RED);
		Vec2 st = Vec2(0 - aabb.width / 2, 0 - aabb.height / 2);
		Vec2 et = Vec2(aabb.width / 2, aabb.height / 2);
		drawNode->drawRect(st, et, Color4F::RED);
		//if (ap.x > 0 && ap.y>0){
		//}else
		//drawNode->drawRect(Vec2(aabb.x, aabb.y), Vec2(aabb.x + aabb.width, aabb.y + aabb.height), Color4F::RED);


	};
	const dragonBones::Rectangle & MovieClip::getRectangle(){
		return this->getArmature()->getArmatureData()->aabb;
	};
	dragonBones::Animation *MovieClip::getAnimation()
	{
 		if(container)
			return container->getAnimation();
		else 
			return NULL;
	};
	dragonBones::Armature *MovieClip::getArmature()
	{
 		if(container)
			return container->getArmature();
		else
			return NULL; 
	};

    void MovieClip::setName(const string &  name)
	{
		BaseNode::setName(name);
		if(this->mc && this->container)
				this->container->setName(name);
		else if(!this->mc && this->display)
			this->display->setName(name);
	};
	void MovieClip::onEnter()
	{
 		if(world && isOnce && container)
		{
			container->getEventDispatcher()->setEnabled(true);
			//container->getEventDispatcher()->addCustomEventListener(EventObject::FRAME_EVENT, std::bind(&MovieClip::onceMovieHandler, this, std::placeholders::_1));
			container->getEventDispatcher()->addCustomEventListener(EventObject::COMPLETE, std::bind(&MovieClip::onceMovieHandler, this, std::placeholders::_1));
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
	float MovieClip::getWidth(){
		Size size = this->container->getContentSize();
		return	size.width*this->getScaleX();
	};
	float MovieClip::getHeight(){
		Size size = this->container->getContentSize();
		return	size.width*this->getScaleY();
	};
	 void MovieClip::setWidth(float w)
	{
		BaseNode::setWidth(w);
		Size size = this->container->getContentSize();
		if (size.width > 0){
			float r = w / (size.width*this->getScaleX());
			this->setScaleX(this->getScaleX()*r);
		}
	};
	 void MovieClip::setHeight(float h){
		BaseNode::setHeight(h);	Size size = this->container->getContentSize();
		if (size.width > 0){
			float r = h / (size.width*this->getScaleY());
			this->setScaleY(this->getScaleY()*r);
		}
	};


	 MovieClipSub::MovieClipSub(MC *_mc, dragonBones::Slot * _slot, const string &  defAniName) :arm(0), userData(0), setTrans(0)
	{
		setNodeType("MovieClipSub");
		this->mc = _mc;
        this->slot = _slot;
        this->slotName = slot->getName();
		this->display = container = NULL;
		this->slot = NULL;
		this->bone = NULL;
		reinit();
		addMcs(mc, this);
	};
	 MovieClipSub::MovieClipSub(MC *mc, const string &  slotName, const string &  defAniName) :arm(0), userData(0), setTrans(0)
	{
		setNodeType("MovieClipSub");
		this->mc = mc;
        this->slotName = slotName;
		this->display = container = NULL;
		this->slot = NULL; //mc->getArmature()->getSlot(slotName);
		this->bone = NULL;
		reinit();
		addMcs(mc, this);
	}; 
	bool MovieClipSub::reinit()
    {
		if(!this->slot)
		{
			if (mc->getArmature())
			{
				this->slot = mc->getArmature()->getSlot(slotName);
				this->bone = mc->getArmature()->getBone(slotName);
				this->root = mc->getArmature()->getBone("root");
			}
			else
				return false;
		}
		if(!this->slot) return false;
		if(this->arm == this->slot->getChildArmature())return false;
		this->arm = this->slot->getChildArmature();
        if (arm){
			this->display=(Node *)this->slot->getDisplay();
			if (this->display)
			{
				this->display->setName(slot->getName());
				this->display->setVisible(this->visible);
				this->container = NULL;
				if (ISTYPE(CCArmatureDisplay, display))
				{
					this->container = ISTYPE(CCArmatureDisplay, display);
					this->transform=this->container->getNodeToWorldTransform();
				}
				isReady = true;
				//disPos = getDisPosition();
				//disPos=this->display->getParent()->convertToNodeSpaceAR(disPos);
				//this->display->setPosition(disPos);
				//std::setAnchorPoint(display);
				std::map<std::string, dragonBones::AnimationData*> & animations = this->arm->_armatureData->animations;
				//for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
				//{
				//    std::string aniName = it.first;
				//    int totalFrames = it.second->frameCount+ 1;//;
				//    float duration = it.second->duration;
				//    CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
				//}
				//if (Common::String(slotName).EndsWith("Sphere")){
				//	this->setPosition(100, 100);
				//}
				/*string defAniName = this->defAniName;
				if (defAniName == "")*/
				defAniName = this->arm->_armatureData->defaultAnimation->name;
				totalFrames = this->arm->_armatureData->animations[defAniName]->frameCount+ 1;//;
				float duration = this->arm->_armatureData->animations[defAniName]->duration;
				CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
				this->gotoAndStop(1);
				return true;
			}
		}
		else
		{
			isReady = false;
		}
		return false;
	}
	void MovieClipSub::setVisible(bool v)
	{
		if(this->visible!=v)
			MovieClipSubBase::setVisible(v);
		if (this->container && this->container->isVisible() != v)
		{
			cocos2d::Mat4 _transform = this->container->getNodeToWorldTransform();
			if (!this->container->isRunning()){
				this->container->setVisible(v);
				this->container->setNodeToParentTransform(_transform);
			}
			else{
 				this->container->setVisible(v);
				if (v && !setTrans){// && _transform.m[12] != transform.m[12] && _transform.m[13] != transform.m[13]
					//_transform.m[12] += transform.m[12];
					//_transform.m[13] += transform.m[13];
					this->container->setNodeToParentTransform(transform);
					setTrans = true;
				}
			}
		}
	};
	bool MovieClipSub::isVisible() 
	{
		return this->visible &&  getNodeVisible(display);
	};

	cocos2d::Point MovieClipSub::getPosition()
	{
		Node * sp = (Node *)this->slot->getDisplay();
		return sp->getPosition();
		Node * parent = sp->getParent();
		Vec2 p = sp->getPosition();
		p = parent->convertToWorldSpace(sp->getPosition());
		//return parent->convertToNodeSpaceAR(parent->convertToWorldSpace(sp->getPosition()));
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
	float MovieClipSub::getWidth(){
		Size size = this->getDisplayNode()->getContentSize();
		return	size.width*this->getScaleX();
	};
	float MovieClipSub::getHeight(){
		Size size = this->getDisplayNode()->getContentSize();
		return	size.width*this->getScaleY();
	};
	void MovieClipSub::setWidth(float w)
	{ 
		Size size = this->getDisplayNode()->getContentSize();
		if (size.width > 0){
			float r = w / (size.width*this->getScaleX());
			this->setScaleX(this->getScaleX()*r);
		}
	};
	void MovieClipSub::setHeight(float h){
		 Size size = this->getDisplayNode()->getContentSize();
		if (size.width > 0){
			float r = h / (size.width*this->getScaleY());
			this->setScaleY(this->getScaleY()*r);
		}
	};



	dragonBones::Armature *MovieClipSub::getArmature()
	{
		return this->arm;
	};
	dragonBones::Animation *MovieClipSub::getAnimation()
	{
		return arm->getAnimation();
	};
    void MovieClipSub::gotoAndStop(int cf, const string &  aniName)
	{
		MC::gotoAndStop(cf, aniName);
		int l = this->submc.size();
		for(int i = 0; i < l; i++)
			this->submc[i]->reinit();
		l = this->submcbs.size();
		for(int i = 0; i < l; i++)
			this->submcbs[i]->reinit();
		//l = this->mcase.size();
		//for (int i = 0; i < l; i++)
		//    this->mcase[i]->reinit();
	};

    ImageMovieClip::ImageMovieClip(const string &  _rootPath, const string &  fileNamePre, int numFormat, int imgSize)
	{
		setNodeType("ImageMovieClip");
		currentFrame = 0;
		totalFrames = imgSize ;
        string rootPath = _rootPath;
        if(!rootPath.empty() && rootPath.at(rootPath.length() - 1) != '/')
		{
			rootPath += "/";
		}
		filePre = rootPath + fileNamePre;
		char tmp[8];
		sprintf(tmp, "%04d", 1);
		container = new BaseSprite(filePre + tmp + ".png");
		addChild(container);
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

    int ImageMovieClip::getTotalFrames(const string &  aniName)
	{
		return totalFrames;
	};
    void ImageMovieClip::gotoAndStop(int cf, const string &  aniName)
	{
		this->currentFrame = cf % totalFrames + 1;
		char tmp[8];
		sprintf(tmp, "%04d", currentFrame);
		container->setTexture(filePre + tmp + ".png");// = new BaseSprite(filePre + tmp + ".png");
		playing = true;
	};
	void ImageMovieClip::nextFram()
	{
		this->currentFrame++;
		gotoAndStop(this->currentFrame);
	};
	void ImageMovieClip::update(float dt)
	{
		nextFram();
	}
    void ImageMovieClip::play(const string &  aniName)
	{
		playing = 1;
	}
	;
    void ImageMovieClip::stop(const string &  aniName)
	{
		playing = 0;
	};

	SpriteClip::SpriteClip(BaseSprite * container)
	{
		setNodeType("SpriteClip");
		this->container = container;
	};


}
