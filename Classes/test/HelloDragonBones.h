#include "BaseDemo.h"
#include "BaseHeaders.h"
#include "BaseNode.h"
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
	MovieClip * mc;
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
		
       ////子动画中有多个动画
       // armatureDisplay =std::loadArmature("unit/",  "Unit3_mc");
       // armatureDisplay->setPosition(0.0f, -100.0f);
       // addChild(armatureDisplay);
       // Armature * arm = armatureDisplay->getArmature()->getSlot("Layer 7")->getChildArmature();
       // arm->getAnimation()->play("top", 0);
       // armatureDisplay->getAnimation()->play("Unit3_mc", 0);

		//
		currentFrame = 0;
		dir = true;
		mc = new MovieClip("unit/", "unit1_1");
		mc->setPosition(0.0f, 100.0f);
		addChild(mc);
		mc->getAnimation()->play("unit1_1");
		Armature * arm = mc->getArmature()->getSlot("contSlot")->getChildArmature();
		mc->setUserData(new MovieClipSub(arm));
		arm->getAnimation()->play();
		
		   
	 
		this->schedule(schedule_selector(HelloDragonBones::scheduleUpdate), 0.0f);

		//////动画事件		
		//factory->loadDragonBonesData("levindeath/levindeath_ske.json");
		//factory->loadTextureAtlasData("levindeath/levindeath_tex.json");
		//armatureDisplay = factory->buildArmatureDisplay("levindeath");
		//armatureDisplay->getAnimation()->play("levindeath",1);
		//armatureDisplay->setPosition(0.0f, -200.0f);
		//addChild(armatureDisplay);
		//armatureDisplay->getAnimation()->play("levindeath",10);
		//std::map<std::string, dragonBones::AnimationData*> & animations = armatureDisplay->getArmature()->_armatureData->animations;
		//for each (std::pair<std::string, dragonBones::AnimationData*> it in animations)
		//{
		//	std::string aniName = it.first;
		//	int totalFrames = it.second->frameCount;
		//	float duration = it.second->duration;
		//	CCLOG("load %s totalFrames=%i duration=%f", aniName.c_str(), totalFrames, duration);
		//}
		//totalFrames=armatureDisplay->getArmature()->_armatureData->animations["levindeath"]->frameCount;
		//armatureDisplay->getEventDispatcher()->setEnabled(true);
		//armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::START, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		//armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::LOOP_COMPLETE, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		//armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::COMPLETE, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		//armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FADE_IN, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		//armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FADE_IN_COMPLETE, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		//armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FADE_OUT, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		//armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FADE_OUT_COMPLETE, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));
		//armatureDisplay->getEventDispatcher()->addCustomEventListener(dragonBones::EventObject::FRAME_EVENT, std::bind(&HelloDragonBones::_animationEventHandler, this, std::placeholders::_1));



    }
	int currentFrame;
	bool dir;
	int totalFrames;
	string direction;
	void _animationEventHandler(cocos2d::EventCustom* event) const
	{
        Node * target = event->getCurrentTarget();
        string eventName = event->getEventName();
		const auto eventObject = (dragonBones::EventObject*)event->getUserData();
		cocos2d::log("%s %s %s", eventObject->animationState->name.c_str(), eventObject->type.c_str(), eventObject->name.c_str());
        double curFrames = (double)eventObject->animationState->getCurrentTime() / eventObject->animationState->_duration
            * eventObject->armature->_armatureData->frameRate;
        int currFrame = curFrames;
        CCLOG("eventData->armature->_armatureData->frameRate=%i", eventObject->armature->_armatureData->frameRate);
        CCLOG("eventData->animationState->getCurrentTime()=%f", eventObject->animationState->getCurrentTime());
        CCLOG("curFrames=%f  %i", curFrames, currFrame);

    }

	
	void  scheduleUpdate(float dt)
	{
		currentFrame++;
		MovieClipSub * mcs = (MovieClipSub*)mc->getUserData();
		if(currentFrame > 100)
		{
			direction = "up";
		}
		if(mc->currentFrame < mc->totalFrames)
		{
			mc->gotoAndStop((mc->currentFrame + 1));
		}
		else
		{
			mc->gotoAndStop(1);
		}
		//int didx = mcs->arm->getSlot("contSlot")->getDisplayIndex();
		//int bcf = mcs->currentFrame;
 	//	mcs->gotoAndStop((mcs->currentFrame + 1));
		//int edidx = mcs->arm->getSlot("contSlot")->getDisplayIndex();
		//CCLOG("dt=%f  slot->getDisplayIndex=%i %i  cs->currentFrame=%i %i", dt, didx, edidx, bcf, mcs->currentFrame);
		//return;
		int edidx = mcs->arm->getSlot("contSlot")->getDisplayIndex();
		CCLOG("dt=%f  slot->getDisplayIndex=%i   cs->currentFrame=%i ", dt,   edidx,  mcs->currentFrame);
		//if(mcs->currentFrame < mcs->totalFrames)
		//{
		//	mcs->gotoAndStop((mcs->currentFrame + 1));
		//}
		//else
		//{
		//	mcs->gotoAndStop(1);
		//}
		if(direction != "up")
		{
			if(mcs->currentFrame != 1)
			{
				mcs->gotoAndStop(1);
			} 
		}
		else if(mcs->currentFrame != 2)
		{
			mcs->gotoAndStop(2);
		}
		return;

		if(direction != "up")
		{
			if(mcs->currentFrame < 11)
			{
				if(mcs->currentFrame < 10)
				{
					mcs->gotoAndStop((mcs->currentFrame + 1));
				}
				else
				{
					mcs->gotoAndStop(1);
				}
			}
			else
			{
				mcs->gotoAndStop(mcs->currentFrame - 10);
			}
		}
		else if(mcs->currentFrame > 10)
		{
			if(mcs->currentFrame < mcs->totalFrames)
			{
				//mcs->gotoAndStop(11);
				mcs->gotoAndStop((mcs->currentFrame + 1));
			}
			else
			{
				mcs->gotoAndStop(11);
			}
		}
		else
		{
			mcs->gotoAndStop(mcs->currentFrame + 10);
		}
		return;
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