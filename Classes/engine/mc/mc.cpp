#include "BaseHeaders.h"
#include "engine/World.h"

namespace engine
{
    MovieClip:: MovieClip(World * world,dragonBones::DBCCArmatureNode * cont,int total):currentFrame(1),totalFrames(total)
    {
        this->container=cont;
    };
    MovieClip:: MovieClip(World * world,string rootPath, string aniName,int total):currentFrame(1),totalFrames(total)
    {
        this->container=this->loadAni(rootPath,aniName);
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
        container->getAnimation()->stop();
    }
    void MovieClip::play()
    {
        container->getAnimation()->play();
    }
	SpriteClip::SpriteClip(BaseSprite * cont)
    {
		this->container = cont;
    };
    
    OnceMovieClip::OnceMovieClip(World * world,dragonBones::DBCCArmatureNode * cont,int total):MovieClip(world,cont,total)
    { 
        container->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT,std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
        container->getCCEventDispatcher()->addCustomEventListener(EventData::COMPLETE,std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
    }
	OnceMovieClip::OnceMovieClip(World * world, string rootPath, string aniName, int totalFrames) : MovieClip(world, rootPath, aniName, totalFrames)
	{
		container->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT, std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
		container->getCCEventDispatcher()->addCustomEventListener(EventData::COMPLETE, std::bind(&OnceMovieClip::onceMovieHandler, this, std::placeholders::_1));
	};

	void OnceMovieClip::onceMovieHandler(cocos2d::EventCustom *event)
	{
		EventData *eventData = (EventData*)(event->getUserData());
		switch(eventData->getType())
		{
		case EventData::EventType::COMPLETE:
			this->world->removeChild(this);
			break;
			//case EventData::EventType::LOOP_COMPLETE:
			//	break;
		case EventData::EventType::ANIMATION_FRAME_EVENT:
			if(eventData->frameLabel == "ending")
			{
				//
				//pass->removeFromParentAndCleanup(true);
			}
			break;
		}
	};
}
 