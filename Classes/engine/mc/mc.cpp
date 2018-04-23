#include "BaseHeaders.h"
#include "engine/World.h"

namespace engine
{
	MovieClip::MovieClip(World * world, dragonBones::CCArmatureDisplay * cont, int total) :currentFrame(1)
    {
		std::string defAniName ="";
		std::map<std::string, dragonBones::AnimationData*> & animations = cont->getArmature()->_armatureData->animations;
		for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
		{
			std::string aniName = it.first;
			if(defAniName == "")defAniName = aniName;
			int totalFrames = it.second->frameCount;
			float duration = it.second->duration;
			CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
		}
		totalFrames = cont->getArmature()->_armatureData->animations[defAniName]->frameCount;
		float duration = cont->getArmature()->_armatureData->animations[defAniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", defAniName.c_str(), totalFrames, duration);
		this->container = cont;
    };
    MovieClip:: MovieClip(World * world,string rootPath, string aniName,int total):currentFrame(1)
    {
        this->container=this->loadArmature(rootPath,aniName);
		totalFrames = cont->getArmature()->_armatureData->animations[aniName]->frameCount;
		float duration = cont->getArmature()->_armatureData->animations[aniName]->duration;
		CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
	};
    void MovieClip::gotoAndStop(int cf)
    {
       this->currentFrame=(cf) % totalFrames+1;
    };
    void MovieClip::nextFram()
    {
       this->currentFrame=(this->currentFrame+1) % totalFrames+1;
    };
    void MovieClip::update()
    {
        nextFram();
    };
    void MovieClip::stop()
    {
        container->getAnimation()->stop("");
    }
    void MovieClip::play()
    {
        container->getAnimation()->play();
    }
	SpriteClip::SpriteClip(BaseSprite * cont)
    {
		this->container = cont;
    };
    
	OnceMovieClip::OnceMovieClip(World * world, dragonBones::CCArmatureDisplay * cont, int total) :MovieClip(world, cont, total)
	{
		//container->getAnimation()->getAnimationConfig()->duration
		//container->getArmature()
		container->getEventDispatcher()->addCustomEventListener(EventObject::FRAME_EVENT, std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
		container->getEventDispatcher()->addCustomEventListener(EventObject::COMPLETE, std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
    }
	OnceMovieClip::OnceMovieClip(World * world, string rootPath, string aniName, int totalFrames) : MovieClip(world, rootPath, aniName, totalFrames)
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
 