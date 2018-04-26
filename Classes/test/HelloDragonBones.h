#include "BaseDemo.h"
/**
 * How to use
 * 1. Load data.
 *    factory.loadDragonBonesData();
 *    factory.loadTextureAtlasData();
 *
 * 2. Build armature.
 *    armatureDisplay = factory.buildArmatureDisplay("armatureName");
 *
 * 3. Play animation.
 *    armatureDisplay->getAnimation()->play("animationName");
 *
 * 4. Add armature to stage.
 *    addChild(armatureDisplay);
 */
class HelloDragonBones : BaseDemo
{
public:
    CREATE_FUNC(HelloDragonBones);

    static cocos2d::Scene* createScene()
    {
        auto scene = cocos2d::Scene::create();
        auto layer = HelloDragonBones::create();

        scene->addChild(layer);
        return scene;
    }
	dragonBones::CCArmatureDisplay* armatureDisplay;
protected:
    virtual void _onStart()
    {
        const auto factory = dragonBones::CCFactory::getFactory();
        //factory->loadDragonBonesData("mecha_1002_101d_show/mecha_1002_101d_show_ske.dbbin");
        //factory->loadDragonBonesData("mecha_1002_101d_show/mecha_1002_101d_show_ske.json");
        //factory->loadTextureAtlasData("mecha_1002_101d_show/mecha_1002_101d_show_tex.json");
        //const auto armatureDisplay = factory->buildArmatureDisplay("mecha_1002_101d", "mecha_1002_101d_show");
        //armatureDisplay->getAnimation()->play("idle");
		//factory->loadDragonBonesData("Cyborg/skeleton.json");
		//factory->loadTextureAtlasData("Cyborg/texture.json");
		//const auto armatureDisplay = factory->buildArmatureDisplay("Cyborg", "Cyborg");
		//armatureDisplay->getAnimation()->play("Cyborg");


		factory->loadDragonBonesData("levindeath/levindeath_ske.json");
		factory->loadTextureAtlasData("levindeath/levindeath_tex.json");
		armatureDisplay = factory->buildArmatureDisplay("levindeath");
		armatureDisplay->getAnimation()->play("levindeath",1);
        armatureDisplay->setPosition(0.0f, -200.0f);
	 
		//this->schedule(schedule_selector(HelloDragonBones::scheduleUpdate), 0.0f);


		std::map<std::string, dragonBones::AnimationData*> & animations = armatureDisplay->getArmature()->_armatureData->animations;
		for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
		{
			std::string aniName = it.first;
			int totalFrames = it.second->frameCount;
			float duration = it.second->duration;
			CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
		}
		totalFrames=armatureDisplay->getArmature()->_armatureData->animations["levindeath"]->frameCount;
		armatureDisplay->getEventDispatcher()->setEnabled(true);
		armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::START, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::LOOP_COMPLETE, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::COMPLETE, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FADE_IN, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FADE_IN_COMPLETE, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FADE_OUT, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FADE_OUT_COMPLETE, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FRAME_EVENT, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		armatureDisplay->getAnimation()->play("levindeath",10);
		currentFrame = 0;
		dir = true;
        addChild(armatureDisplay);

    }
	int currentFrame;
	bool dir;
	int totalFrames;
	void _animationEventHandler(cocos2d::EventCustom* event) const
	{
		const auto eventObject = (dragonBones::EventObject*)event->getUserData();
		cocos2d::log("%s %s %s", eventObject->animationState->name.c_str(), eventObject->type.c_str(), eventObject->name.c_str());
	}

 
	void  scheduleUpdate(float dt)
	{
		if(dir && currentFrame == totalFrames)
		{
			dir = false;
			currentFrame++;
		}
		else if(!dir && currentFrame == 0)
		{
			dir = true;
			currentFrame--;
		}
		if(dir)
		{
		currentFrame++;

		}
		else
		{
			currentFrame--;
		} 
		float curTime=armatureDisplay->getAnimation()->getLastAnimationState()->getCurrentTime();
		CCLOG("dt =%f ,  curTime =%f ,currentFrame=%i", dt, curTime, currentFrame);
		armatureDisplay->getAnimation()->gotoAndStopByFrame("levindeath", currentFrame);
	}
};