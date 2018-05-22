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
class DBComTest : BaseDemo
{
public:
	CREATE_FUNC(DBComTest);

	static cocos2d::Scene* createScene()
	{
		auto scene = cocos2d::Scene::create();
		auto layer = DBComTest::create();

		scene->addChild(layer);
		return scene;
	}
	dragonBones::CCArmatureDisplay* armatureDisplay;
protected: 

	class Air_mc :public MovieClip
	{
	public:
		string direction;
		MovieClipSub* cont;//public var cont:MovieClip;
		MovieClipSub* contBlowing;
		MovieClipSub* dust1;//public var dust1:MovieClip;
		MovieClipSub* dust2;
		Air_mc(string dir) :direction(dir), MovieClip("cast/", "Air_mc", "Air_mc"), cont(0), dust1(0), dust2(0), contBlowing(0)
		{
			//dust1 = new MovieClipSub(this->getArmature()->getSlot("dust1")->getChildArmature());
			//dust2 = new MovieClipSub(this->getArmature()->getSlot("dust2")->getChildArmature());
			//this->getArmature()->getBone("dust1")->setVisible(false);
			 
		/*};
		void onEnter()
		{*/
			if(this->direction == "left")
			{
				this->gotoAndStop(1);
			}
			else if(this->direction == "right")
			{
				this->gotoAndStop(2);
			}
			else if(this->direction == "up")
			{
				this->gotoAndStop(3);
			}
			else if(this->direction == "down")
			{
				this->gotoAndStop(4);
			}
			
		};
		void clear()
		{
			destroy(cont);
			MovieClip::destroy(dust1);
			MovieClip::destroy(dust2);
			MovieClip::destroy(contBlowing);
			//if(this->cont)delete this->cont;
			//if(this->dust1)delete this->dust1;
			//if(this->dust2)delete this->dust2;
			//if(this->contBlowing)delete this->contBlowing;
		};
		virtual void gotoAndStop(int cur)
		{
			MovieClip::gotoAndStop(cur);
			this->clear();
			this->cont = new MovieClipSub(this,this->getArmature()->getSlot("cont") );
			this->dust1 = new MovieClipSub(this, this->getArmature()->getSlot("dust1") );
			this->dust2 = new MovieClipSub(this, "dust2" );
			dragonBones::Armature * arm = cont->getArmature()->getSlot("blowing")->getChildArmature();
			//while(arm == NULL)
			//{
			//	CCLOG("blowing arm = NULL this->cont->getName=%s  ", this->cont->getArmature()->getName().c_str());
			//	arm=cont->getArmature()->getSlot("blowing")->getChildArmature();
			//}
			this->contBlowing = new MovieClipSub(cont, cont->getArmature()->getSlot("blowing"));
			
			this->cont->gotoAndStop(48);
			this->dust1->stop();
			this->dust2->stop();
			this->dust1->arm->getBone("dust1")->setVisible(false);
			this->dust2->arm->getBone("dust2")->setVisible(false);
			this->cont->play(0);
		};
	};
	Air_mc * air;
 
	void onEnter()
	{
		BaseDemo::onEnter();
	}
	virtual void _onStart()
	{
		currentFrame = frameCounter = 0;
        this->setName("layer");
		air = new Air_mc("up");
		this->addChild(air);
		//this->schedule(schedule_selector(DBComTest::scheduleUpdate), (float)1 / 30.0f);
		this->schedule(static_cast<cocos2d::SEL_SCHEDULE>(&DBComTest::scheduleUpdate) );

		return;
	}
	int currentFrame;
	bool dir;
	int totalFrames, frameCounter;
	string direction;
	MovieClip *mc;

	virtual void  scheduleUpdate(float dt)
	{
		if(this->frameCounter < 30)
		{
			this->frameCounter++;
		}
		else
		{
			this->frameCounter = 1;
		}
		currentFrame++;
		if(air)
		{
			int cur=(this->currentFrame / 100) %air->totalFrames +1;
			if(cur != air->currentFrame)
				air->gotoAndStop(cur);
		}
		if(this->currentFrame > 500)
		{
			this->removeChild(air);
            air = NULL;
		}
		return;

		CCLOG("%s getVisible=%i ", mc->getArmature()->getSlot("shadow")->getName().c_str(), mc->getArmature()->getSlot("shadow")->getVisible());
		if(this->currentFrame > 100 && this->currentFrame<200)
		{
			cocos2d::Sprite * img = (cocos2d::Sprite *)mc->getArmature()->getSlot("shadow")->getDisplay();
			//img->setVisible(false);
			//setVisible(true);//
			mc->getArmature()->getSlot("shadow")->setDisplayIndex(-1);
			//mc->getArmature()->getSlot("shadow")->setVisible(false); //visible = true;
			//mc->getArmature()->getSlot("shadow")->setDisplay(NULL,DisplayType::Image);
		}
		else if(this->currentFrame>500)
		{
			//mc->getArmature()->getSlot("shadow")->setVisible(true);
			//mc->getArmature()->getSlot("shadow")->setDisplayIndex(-1);
			mc->getArmature()->getSlot("shadow")->setDisplayIndex(0);
			//mc->getArmature()->getBone("shadow")->setVisible(true);
		}
		return;


		MovieClipSub * mcs = (MovieClipSub*)mc->getUserData();
		if(currentFrame > 100)
			direction = "up";
		const auto factory = dragonBones::CCFactory::getFactory();
		factory->getClock()->timeScale = 1;
		if((currentFrame > 50 && currentFrame<100) || currentFrame>150)
		{
			//factory->getClock()->advanceTime(1 / 60.0f);
			factory->getClock()->timeScale = 2;
		}
		CCLOG("time=%f  getClock->timeScale=%f ", factory->getClock()->time, factory->getClock()->timeScale);

		float curTime = mcs->arm->getAnimation()->getLastAnimationState()->getCurrentTime();
		int mcsidx = mcs->arm->getSlot("contSlot")->getDisplayIndex();
		CCLOG("dt=%f curTime=%f slot->getDisplayIndex=%i   mcs->currentFrame=%i ", dt, curTime, mcsidx, mcs->currentFrame);
		if(direction != "up")
		{
			if(mcs->currentFrame < 9)
			{
				if(mcs->currentFrame < 8)
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
				mcs->gotoAndStop(mcs->currentFrame - 8);
			}
		}
		else if(mcs->currentFrame > 8)
		{
			if(mcs->currentFrame < mcs->totalFrames)
			{
				mcs->gotoAndStop((mcs->currentFrame + 1));
			}
			else
			{
				mcs->gotoAndStop(9);
			}
		}
		else
		{
			mcs->gotoAndStop(mcs->currentFrame + 8);
		}
		if(direction == "left" || direction == "right")
		{
			if(mc->currentFrame != 1)
			{
				if(mc->currentFrame > 16)
				{
					if(mc->currentFrame < mc->totalFrames)
					{
						mc->gotoAndStop((mc->currentFrame + 1));
					}
					else
					{
						mc->gotoAndStop(1);
					}
				}
				else if(mc->currentFrame < 16)
				{
					mc->gotoAndStop((mc->currentFrame + 1));
				}
				else
				{
					mc->gotoAndStop(1);
				}
			}
		}
		else if(mc->currentFrame != 17)
		{
			if(mc->currentFrame > 16)
			{
				if(mc->currentFrame < mc->totalFrames)
				{
					mc->gotoAndStop((mc->currentFrame + 1));
				}
				else
				{
					mc->gotoAndStop(17);
				}
			}
			else if(mc->currentFrame < 16)
			{
				mc->gotoAndStop((mc->currentFrame + 1));
			}
			else
			{
				mc->gotoAndStop(17);
			}
		}
		if(this->frameCounter % 2)
		{
			this->scheduleUpdate(0);
		}
		return;


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
		CCLOG("dt=%f  slot->getDisplayIndex=%i   cs->currentFrame=%i ", dt, edidx, mcs->currentFrame);
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
		curTime = armatureDisplay->getAnimation()->getLastAnimationState()->getCurrentTime();
		CCLOG("dt =%f ,  curTime =%f ,currentFrame=%i", dt, curTime, currentFrame);
		armatureDisplay->getAnimation()->gotoAndStopByFrame("levindeath", currentFrame);
	}
};