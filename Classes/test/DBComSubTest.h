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
class DBComSubTest : BaseDemo
{
public:
	CREATE_FUNC(DBComSubTest);

	static cocos2d::Scene* createScene()
	{
		auto scene = cocos2d::Scene::create();
		auto layer = DBComSubTest::create();

		scene->addChild(layer);
		return scene;
	}
	dragonBones::CCArmatureDisplay* armatureDisplay;
protected: 
	struct BulletSphereTower_mc : public MovieClip
	{
		MovieClip * cont;
		BulletSphereTower_mc() :MovieClip("sphere/", "BulletSphereTower_mc", "BulletSphereTower_mc"), cont(0)
		{
		};
		void  gotoAndStop(int cur)
		{
			int oldIdx = this->currentFrame;
			MovieClip::gotoAndStop(cur);
			if(oldIdx == this->currentFrame)return;
			if(cont)display->removeChild(cont);
			cont = NULL;
			if(this->currentFrame == 1)
			{
				cont = new MovieClip("sphere/", "BulletFireTower_mc", "BulletFireTower_mc");
			}
			else if(this->currentFrame == 2)
			{
				cont = new MovieClip("sphere/", "BulletIceTower_mc", "BulletIceTower_mc");
			}
			else if(this->currentFrame == 3)
			{
				cont = new MovieClip("sphere/", "BulletStoneTower_mc", "BulletStoneTower_mc");
			}
			else if(this->currentFrame == 4)
			{
				cont = new MovieClip("sphere/", "BulletLevinTower_mc", "BulletLevinTower_mc");
			}
			if(cont)display->addChild(cont);

		};
	};
	class TowerMenuHint_mc :public MovieClip
	{
	public:
		MovieClipSub * cont;
		MovieClipSub * contCont1;
		MovieClip * contCont1Sphere1;
		MovieClip * contCont1Sphere2;
		//ui::Text     * nameTXT             ;
		TowerMenuHint_mc() :MovieClip("tower/", "TowerMenuHint_mc", "TowerMenuHint_mc")
		{
			cont = this->createMovieClipSub("cont");
			contCont1 = cont->createMovieClipSub("cont1");
			contCont1Sphere1 = new MovieClip(contCont1, "sphere1", "worldinterface", "GetSphere_mc");
			contCont1Sphere2 = new MovieClip(contCont1, "sphere2", "worldinterface", "GetSphere_mc");
		};
	};

	
	//BulletSphereTower_mc * cont;
	TowerMenuHint_mc * cont;
	void onEnter()
	{
		BaseDemo::onEnter();
	}
	virtual void _onStart()
	{
		currentFrame = frameCounter = 0;
        this->setName("layer");
		//cont = new BulletSphereTower_mc();
		cont = new TowerMenuHint_mc();
		cont->setPosition(100, 100);
 		this->addChild(cont);
		//this->schedule(schedule_selector(DBComSubTest::scheduleUpdate), (float)1 / 30.0f);
		this->schedule(static_cast<cocos2d::SEL_SCHEDULE>(&DBComSubTest::scheduleUpdate) ,0.3333333);
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
		cont->gotoAndStop(this->currentFrame / 30 + 1);
		cont->cont->nextFram();
		cont->contCont1->nextFram();
		cont->contCont1Sphere1->nextFram();
		cont->contCont1Sphere2->nextFram();
		return;

		 
	}
};