#include "BaseHeaders.h"
#include "engine/World.h"

namespace engine
{
	MovieClip::MovieClip(World * world, dragonBones::CCArmatureDisplay * cont, string defAniName ) :currentFrame(0)
    { 
		std::map<std::string, dragonBones::AnimationData*> & animations = cont->getArmature()->_armatureData->animations;
		for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
		{
			std::string aniName = it.first;
			int totalFrames = it.second->frameCount;
			float duration = it.second->duration;
			CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
		}

		if(defAniName == "")defAniName = cont->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = cont->getArmature()->_armatureData->animations[defAniName]->frameCount;
		float duration = cont->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		this->container = cont;
    };
	MovieClip::MovieClip(World * world, string rootPath, string armName,   string defAniName ) :currentFrame(0)
    {
		this->container = this->loadArmature(rootPath, armName);
		if(defAniName == "")defAniName = container->getArmature()->_armatureData->defaultAnimation->name;
		totalFrames = container->getArmature()->_armatureData->animations[defAniName]->frameCount;
		float duration = container->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
	};
	int MovieClip::getTotalFrames(string aniName)
	{
		if(!container)return 0;
		if(aniName == "")aniName = defAniName;
		AnimationData *aniData = container->getArmature()->_armatureData->animations[aniName];
		if(aniData) 
			return aniData->frameCount; 
		return 0;
	};

	void MovieClip::gotoAndStop(int cf, string aniName )
    {
		if(!container)return ;
		if(aniName == "")aniName = defAniName;
		if(this->currentFrame == 0) 
			container->getAnimation()->play(aniName, 1);
		this->currentFrame = (cf) % (totalFrames + 1);
		container->getAnimation()->gotoAndStopByFrame(aniName, currentFrame);
    };
    void MovieClip::nextFram()
    {
		if(!container)return;
		this->currentFrame++;
	   gotoAndStop(this->currentFrame);
    };
    void MovieClip::update()
    {
		if(!container)return;
		nextFram();
    };
	void MovieClip::stop(string aniName)
    {
		if(!container)return;
		if(aniName == "")aniName = defAniName;
		container->getAnimation()->stop(aniName);
    }
	void MovieClip::play(string aniName )
    {
		if(!container)return;
		if(aniName == "")aniName = defAniName;
		container->getAnimation()->play(aniName, 1);
    }
	SpriteClip::SpriteClip(BaseSprite * cont)
    {
		this->container = cont;
    };
    
	OnceMovieClip::OnceMovieClip(World * world, dragonBones::CCArmatureDisplay * cont, string defAniName) :MovieClip(world, cont, defAniName)
	{
		//container->getAnimation()->getAnimationConfig()->duration
		//container->getArmature()
		container->getEventDispatcher()->addCustomEventListener(EventObject::FRAME_EVENT, std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
		container->getEventDispatcher()->addCustomEventListener(EventObject::COMPLETE, std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
    }
	OnceMovieClip::OnceMovieClip(World * world, string rootPath, string aniName, string defAniName) : MovieClip(world, rootPath, aniName, defAniName)
	{
		container->getEventDispatcher()->addCustomEventListener(EventObject::FRAME_EVENT, std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
		container->getEventDispatcher()->addCustomEventListener(EventObject::COMPLETE, std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
	};

	void OnceMovieClip::onceMovieHandler(cocos2d::EventCustom *event)
	{
		Node * target = event->getCurrentTarget();
		string eventName = event->getEventName();
		EventObject *eventData = (EventObject*)(event->getUserData());
		if(eventName == EventObject::COMPLETE)
		{
			this->world->removeChild(this);
		}
		else if(eventName == EventObject::FRAME_EVENT)
		{
			if(eventData->getData()->getString(0)== "ending")
			{
				//
				//pass->removeFromParentAndCleanup(true);
			}
		}
		//case EventData::EventType::LOOP_COMPLETE:
		//	break;
	};
}
 