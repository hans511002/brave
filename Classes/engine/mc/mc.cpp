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
		if(cf == 0)cf = 1;
		if(aniName == "")aniName = defAniName;
		if(this->getAnimation()->getLastAnimationName() != aniName)
			this->getAnimation()->play(aniName, 1);
		this->currentFrame = (cf - 1) % totalFrames + 1;
		this->getAnimation()->gotoAndStopByFrame(aniName, currentFrame - 1);
	};
	void MC::nextFram()
	{
		this->currentFrame++;
		gotoAndStop(this->currentFrame);
	};
	void MC::update()
	{
		nextFram();
	};
	void MC::stop(string aniName)
	{
		if(aniName == "")aniName = defAniName;
		this->getAnimation()->stop(aniName);
	}
	void MC::play(int times)
	{
		this->getAnimation()->play(defAniName, times);
	}
	void MC::play(string aniName, int times)
	{
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
		MovieClip * mvc = getMc(mc);
		if(mvc)
		{
			mvc->addMcs(mcs);
		}
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
		this->mcs.clear();
	}
	void MovieClip::destroy(MovieClipSub * & ms)
	{ 
		for(int i = 0; i < this->mcs.size(); i++)
		{
			if(ms == this->mcs[i])
			{
				this->mcs.remove(i);
				delete ms;
				ms = NULL;
				break;
			}
		}
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
		if(defAniName == "")
			this->defAniName = defAniName = cont->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = cont->getArmature()->_armatureData->animations[defAniName]->frameCount;// +1;
		float duration = cont->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		this->container = cont;
		BaseNode::init();
		addChild(container);
		this->autorelease();
	};
	MovieClip::MovieClip(string rootPath, string armName, string dbName, string defAniName) :isOnce(false)
	{
		this->container = this->loadArmature(rootPath, armName, dbName);
		if(defAniName == "")
			this->defAniName = defAniName = container->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = container->getArmature()->_armatureData->animations[defAniName]->frameCount;//+ 1;
		float duration = container->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		BaseNode::init();
		addChild(container);
		this->autorelease();
	};
	MovieClip::MovieClip(string armName, string dbName, BaseNode *node)
	{
		MovieClip(armName, dbName);
		if(node)node->addChild(this);
	};
	MovieClip::MovieClip(World * world, string rootPath, string armName, string dbName, string defAniName)
	{
		MovieClip(rootPath, armName, dbName, defAniName);
		if(world)setOnceMove(world);
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
		return container->getAnimation();
	};
	dragonBones::Armature *MovieClip::getArmature()
	{
		return container->getArmature();
	};

	void MovieClip::onEnter()
	{
		if(world && isOnce)
		{
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
	MovieClipSub::MovieClipSub(MC *_mc, dragonBones::Armature * arm, string defAniName) :mc(_mc)
	{
		this->arm = arm;
		std::map<std::string, dragonBones::AnimationData*> & animations = this->getArmature()->_armatureData->animations;
		for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
		{
			std::string aniName = it.first;
			int totalFrames = it.second->frameCount;//+ 1;
			float duration = it.second->duration;
			CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
		}
		if(defAniName == "")
			this->defAniName = defAniName = this->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = this->getArmature()->_armatureData->animations[defAniName]->frameCount;//+ 1;
		float duration = this->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		this->gotoAndStop(1);
		addMcs(mc, this);
	};
	MovieClipSub::MovieClipSub(MC *mc, string solt, string defAniName) :mc(mc)
	{
		this->arm = mc->getArmature()->getSlot(solt)->getChildArmature();
		std::map<std::string, dragonBones::AnimationData*> & animations = this->getArmature()->_armatureData->animations;
		for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
		{
			std::string aniName = it.first;
			int totalFrames = it.second->frameCount;//+ 1;
			float duration = it.second->duration;
			CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
		}
		if(defAniName == "")
			this->defAniName = defAniName = this->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = this->getArmature()->_armatureData->animations[defAniName]->frameCount;//+ 1;
		float duration = this->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		this->gotoAndStop(1);
		addMcs(mc, this);
	};

	dragonBones::Armature *MovieClipSub::getArmature()
	{
		return this->arm;
	};
	dragonBones::Animation *MovieClipSub::getAnimation()
	{
		return arm->getAnimation();
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
