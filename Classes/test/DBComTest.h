#include "BaseDemo.h"
#include "BaseHeaders.h"
#include "BaseNode.h"
#include "MaskTest.h"
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
	LevelPointer * pointer;
	 
	void onEnter()
	{
		BaseDemo::onEnter();
	}
	virtual void _onStart()
	{
		currentFrame = frameCounter = 0;
        this->setName("layer");
		  
		pointer = new LevelPointer();
		pointer->eyesAnima->play(0);
		pointer->fireAnima->play(0);
		pointer->setPosition(200, 200);
		this->addChild(pointer);
		//this->schedule(schedule_selector(DBComTest::scheduleUpdate), (float)1 / 30.0f);
		this->schedule(static_cast<cocos2d::SEL_SCHEDULE>(&DBComTest::scheduleUpdate) );
		pointer->statusAnima = 1;
		pointer->myPoint = cocos2d::Point(pointer->getPosition());
		pointer->gotoAndStop(2);
		//pointer->mask2->stop();
		//pointer->arrow->stop();
		//pointer->fireAnima->gotoAndStop(1);
		//pointer->eyesAnima->gotoAndStop(1);
		//std::changeAnchorPoint(pointer->mask2,Vec2(1,0.5));
		//pointer->getArmature()->getBone("mask2")->offset.rotation=180;
		//pointer->mask2->setRotation(180);
		pointer->mask2->setScaleX(-1);
		pointer->pointerCase->setMouseEnabled(true);
		//this->world->level.removeChild(this->world->pointer1);
		//this->world->addChild(this->world->pointer1);
		//this->world->listOfIndexes3.push(this->world->pointer1); 
		pointer->setScaleY(1.9f);
		pointer->setScaleX(1.9f);
		//pointer->setVisible(false);
		float tempObject = pointer->getRotation();
		pointer->setRotation(0);
		pointer->arrow->setRotation(tempObject);

		ccBlendFunc blendFunc;
		blendFunc.src = GL_ONE;
		blendFunc.dst = GL_ZERO;
		//pointer->mask1->setBlendFunc(blendFunc);
		//pointer->mask2->setBlendFunc(blendFunc);

		blendFunc.src = GL_DST_ALPHA;            // mask图片的当前alpha值是多少，如果是0（完全透明），那么就显示mask的。如果是1（完全不透明）
		blendFunc.dst = GL_ZERO;                // maskSprite不可见

		pointer->mask1->setVisible(false); 
		//pointer->mask2->setVisible(false);

		//if(pointer->mask3->mask)pointer->mask3->mask->setBlendFunc(blendFunc);
		//if (pointer->mask4->mask)pointer->mask4->mask->setBlendFunc(blendFunc);
		//pointer->mask5->setBlendFunc(blendFunc);

		logInfo("pointer->mask1->getPosition ", pointer->mask1->getPosition(), &pointer->mask1->getAnchorPointInPoints() );

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
			//pointer->mask1->setVisible(false);
			//pointer->mask2->setVisible(false);
			this->frameCounter = 1;
		}
		std::setAnchorPoint(pointer->mask1, Vec2(0, 0.5));
		std::setAnchorPoint(pointer->mask2, Vec2(1, 0.5));
		//std::changeAnchorPoint(pointer->mask1, Vec2(0, 0.5));
		currentFrame++;
		pointer->mask1->setRotation(currentFrame);
		pointer->mask2->setRotation(currentFrame);
		logInfo("pointer->mask1->getPosition ", pointer->mask1->getPosition(), &pointer->mask1->getAnchorPointInPoints());
		logInfo("pointer->mask2->getPosition ", pointer->mask2->getPosition(), &pointer->mask2->getAnchorPointInPoints());

	    
	}
};