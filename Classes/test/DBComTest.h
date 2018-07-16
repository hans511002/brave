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
		pointer->gotoAndStop(1);
		//pointer->mask2->stop();
		//pointer->arrow->stop();
		//pointer->fireAnima->gotoAndStop(1);
		//pointer->eyesAnima->gotoAndStop(1);
		//std::changeAnchorPoint(pointer->mask2,Vec2(1,0.5));
		//pointer->getArmature()->getBone("mask2")->offset.rotation=180;
		//pointer->mask2->setScaleX(-1);
		pointer->pointerCase->setMouseEnabled(true);
		//this->world->level.removeChild(this->world->pointer1);
		//this->world->addChild(this->world->pointer1);
		//this->world->listOfIndexes3.push(this->world->pointer1); 
		pointer->setScaleY(0.9f);
		pointer->setScaleX(0.9f);
		//pointer->setVisible(false);
		float tempObject = pointer->getRotation();
		pointer->setRotation(0);
		pointer->arrow->setRotation(tempObject);

		//std::setAnchorPoint(pointer->mask1, Vec2(1, 0.5));
		std::changeAnchorPoint(pointer->mask1->mask, Vec2(0, 0.5));
		std::changeAnchorPoint(pointer->mask2->mask, Vec2(1, 0.5));
		//pointer->mask1->setRotation(-180);

		pointer->mask2->mask->setOpacityModifyRGB(true);
		pointer->mask5->setOpacityModifyRGB(true);
		glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glBlendFunc(GL_ONE, GL_ONE);GL_DST_ALPHA

		ccBlendFunc blendFunc;
		blendFunc.src = GL_SRC_ALPHA;
		blendFunc.dst = GL_DST_ALPHA;
		//pointer->mask1->setBlendFunc(blendFunc);
		//pointer->mask2->mask->setBlendFunc(blendFunc);
		//blendFunc.src = GL_ONE;
		//blendFunc.dst = GL_ZERO; 
		//blendFunc.src = GL_DST_ALPHA;            // mask图片的当前alpha值是多少，如果是0（完全透明），那么就显示mask的。如果是1（完全不透明）
		//blendFunc.dst = GL_ZERO;                // maskSprite不可见

		pointer->mask2->mask->setPosition(pointer->mask2->mask->getPosition()+Vec2(50, 50));
		blendFunc.src = GL_DST_ALPHA;            // mask图片的当前alpha值是多少，如果是0（完全透明），那么就显示mask的。如果是1（完全不透明）
		blendFunc.dst = GL_ZERO;                // maskSprite不可见

		pointer->mask5->visit();
		pointer->mask2->mask->visit();

		//pointer->mask1->setVisible(false); 
		//pointer->mask2->setVisible(false);
		//if(pointer->mask3->mask)pointer->mask3->mask->setBlendFunc(blendFunc);
		//if (pointer->mask4->mask)pointer->mask4->mask->setBlendFunc(blendFunc);
		pointer->mask5->setPosition(pointer->mask5->getPosition() + Vec2(50, 50));
		//pointer->mask5->setBlendFunc(blendFunc);
		//pointer->mask5 ->setOpacity(0);
		//pointer->mask2 ->mask->setOpacity(0);

 


		//pointer->mask5->setVisible(false);
		pointer->mask3->setVisible(false);
		pointer->mask4->setVisible(false);  
			pointer->arrow->setVisible(false);
		//pointer->mask1->setRotation(-180);
		Sprite *mask6 = (Sprite*)pointer->getArmature()->getSlot("Layer 3")->getDisplay();
		mask6->setVisible(false);
		mask6 = (Sprite*)pointer->getArmature()->getSlot("Layer 14")->getDisplay();
		mask6->setVisible(false);

		logInfo("pointer->mask1->getPosition ", pointer->mask1->mask->getPosition(), &pointer->mask1->mask->getAnchorPointInPoints() );

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
			//pointer->mask1->setRotation(-180);
			//pointer->mask1->setScaleX(180);
			//std::changeAnchorPoint(pointer->mask1, Vec2(0, 0.5));
		}
		else
		{
			//pointer->mask1->setVisible(false);
			//pointer->mask2->setVisible(false);
			this->frameCounter = 1;
		}
		if (currentFrame<=255) {
			//pointer->mask5 ->setOpacity(256-currentFrame);
			pointer->mask2 ->mask->setOpacity(256-currentFrame);
		}
		else {
			//pointer->mask5->setOpacity(currentFrame%256);
			pointer->mask2->mask->setOpacity(currentFrame % 256);

		}
		//std::changeAnchorPoint(pointer->mask1, Vec2(0, 0.5));
		currentFrame++;
		//pointer->mask1->setRotation(pointer->mask1->getRotation()+1);
		pointer->mask2->setRotation(pointer->mask2->getRotation()+1);
		pointer->fireAnima->setRotation(currentFrame);
		logInfo("pointer->mask1->getPosition ", pointer->mask1->mask->getPosition(), &pointer->mask1->mask->getAnchorPointInPoints());
		logInfo("pointer->mask2->getPosition ", pointer->mask2->mask->getPosition(), &pointer->mask2->mask->getAnchorPointInPoints());

	    
	}
};