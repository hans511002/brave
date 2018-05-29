#include "BaseDemo.h"
#include "BaseHeaders.h"
#include "BaseNode.h"
#include "engine/WorldInterface_mc.h"
using namespace engine;
class WorldInterface : BaseDemo
{
public:
	CREATE_FUNC(WorldInterface);

	static cocos2d::Scene* createScene()
	{
		auto scene = cocos2d::Scene::create();
		auto layer = WorldInterface::create();
		scene->addChild(layer);
		layer->setName("WorldInterface");
		scene->setName("scene");
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
			this->cont = new MovieClipSub(this, this->getArmature()->getSlot("cont"));
			this->dust1 = new MovieClipSub(this, this->getArmature()->getSlot("dust1"));
			this->dust2 = new MovieClipSub(this, "dust2");
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

	struct BuySphere :public MovieClip
	{
		ui::Text * buyTXT;
		MovieClipSub * coin;
		MovieClipSub *lightUp;
		BaseNode *buySphereCase;
		BuySphere() :MovieClip("worldinterface/", "buySphere", "buySphere")
		{
			//this->gotoAndStop(2);
			buySphereCase = createCase("buySphereCase",true);
			buyTXT = createText("buyTXT");
			this->coin = createMovieClipSub("coin");
			std::setText(buyTXT, 4);
		};
		void logPos(cocos2d::Point pos)
		{
			CCLOG("x=%f y=%f", pos.x, pos.y);
		};
		void logPos(cocos2d::Size pos)
		{
			CCLOG("w=%f h=%f", pos.width, pos.height);
		};
		void logPos(float x, float y)
		{
			CCLOG("x=%f y=%f", x, y);
		};
		void print()
		{
			Node * sp = (Node *)this->getArmature()->getSlot("buyTXT")->getDisplay();
			//CCLOG("coin.x=%f y=%f", sp->getContentSize().width, sp->getContentSize().height);
			//logPos(this->convertToNodeSpace(sp->getPosition()));
			//logPos(this->convertToWorldSpace(sp->getPosition()));
			//logPos(this->convertToNodeSpace(this->getPosition()));
			//logPos(this->convertToWorldSpace(this->getPosition()));
			//CCLOG("coin.x=%f y=%f", coin->getPosition().x, coin->getPosition().y);
			////buySphereCase
			const dragonBones::Transform * origin = this->getArmature()->getBone("buySphereCase")->getOrigin();
			const dragonBones::Transform * offset = this->getArmature()->getBone("buySphereCase")->getOffset();
			CCLOG(" origin.x=%f y=%f", origin->x, origin->y);
			CCLOG(" offset.x=%f y=%f", offset->x, offset->y);
			CCLOG("buySphereCase.x=%f y=%f", this->getArmature()->getBone("buySphereCase")->getOffset()->x, this->getArmature()->getBone("buySphereCase")->getOffset()->y);
		}
	};
	
	struct CaseTest :public BaseNode
	{
		CaseTest()
		{
			BaseNode::init();
		}
		virtual void mouseDownHandler(cocos2d::EventMouse* event) {
			if(!this->hitTest(event))return;
			BaseNode::mouseDownHandler(event);
			loginfo("mouseDown", event);
		};
		virtual void mouseUpHandler(cocos2d::EventMouse* event) {
			if(!this->hitTest(event))return;
			loginfo("mouseUp", event);
			BaseNode::mouseUpHandler(event);
		};

	};

	void onEnter()
	{
		BaseDemo::onEnter();
	}
	virtual void _onStart()
	{
		air = NULL;
		currentFrame = frameCounter = 0;
		//BuySphere * sphere = new BuySphere();
		//sphere->setName("sphere");
		//this->addChild(sphere);

		//BuySphere * sphere1 = new BuySphere( );
		//sphere1->setName("sphere1");
		//this->addChild(sphere1);
		//sphere1->enableMouseHandler();
		//sphere1->setSize(40, 30);
		//sphere1->setPosition(-100, -100);
		////sphere->print();
		////this->addChild(sphere->buySphereCase);
		//sphere1->buySphereCase->setPosition(-100, -100);
		////sphere->buySphereCase->setPosition(100, 100);

		//CaseTest *Case = new CaseTest();
		//this->addChild(Case);
		//Case->setSize(50, 50);
		//Case->drawRange();
		//Case->setPosition(-150, -100);
		//Case->enableMouseHandler();
		//Case->setName("Case");

  //      GetAchieve_mc * gac = new GetAchieve_mc();
  //      this->addChild(gac);
  //      //gac->drawRange();
  //      gac->setPosition(-250, -100);
		//gac->boardNoteTXT->setText("中国联盟");

		 worldInterface = new WorldInterface_mc();
		worldInterface->setName("WorldInterface_mc");
		this->addChild(worldInterface);

		//Sprite * sprite=Sprite::create("background1.png");
		//sprite->setContentSize(sphere->buySphereCase->getContentSize());
		//sphere->buySphereCase->addChild(sprite);

		//Node * node = sphere->buySphereCase;
		//while(node)
		//{
		//	CCLOG("%s getScaleX.x=%f y=%f",node->getName().c_str(), node->getScaleX(), node->getScaleY());
		//	node = node->getParent();
		//}
	 
		//this->schedule(schedule_selector(DBComTest::scheduleUpdate), (float)1 / 30.0f);
		this->schedule(static_cast<cocos2d::SEL_SCHEDULE>(&WorldInterface::scheduleUpdate));
		return;
	}
	int currentFrame;
	bool dir;
	int totalFrames, frameCounter;
	string direction;
	MovieClip *mc;
	WorldInterface_mc * worldInterface;
	virtual void  scheduleUpdate(float dt)
	{
		//logInfo("fireSphere pos", worldInterface->fireSphere->getPosition());
		//logInfo("fireSphere worldpos", worldInterface->fireSphere->convertToWorldSpace(worldInterface->fireSphere->getPosition()));
		//logInfo("fireSphereSphereCase pos", worldInterface->fireSphereSphereCase->getPosition() );
		//logInfo("fireSphereSphereCase worldpos", worldInterface->fireSphereSphereCase->convertToWorldSpace(worldInterface->fireSphereSphereCase->getPosition()));
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
			int cur = (this->currentFrame / 100) % air->totalFrames + 1;
			if(cur != air->currentFrame)
				air->gotoAndStop(cur);
		}
		if(this->currentFrame > 500)
		{
			this->removeChild(air);
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