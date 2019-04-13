#include "BaseDemo.h"
#include "BaseHeaders.h"
#include "BaseNode.h"
#include "MaskTest.h" 

namespace engine
{
	class LevelPointerTest :public MovieClip
	{
	public:
		MCCase * pointerCase;
		MovieClipSub * fireAnima;
		MovieClipSub * eyesAnima;
		Sprite * mask1;
		Sprite * mask2;
		Sprite * firel;//2
		Sprite * firer;//1 2 
		Sprite * arrow;

		LevelPointerTest();
		float counter;
		int timer;
		Vec2 myPoint;
		int statusAnima;

		void resetMask() {
			mask1 = this->getSprite("mask1");
			mask2 = this->getSprite("mask2");
			firel = this->getSprite("firel");
			firer = this->getSprite("firer");
			if (this->currentFrame == 1) {
				if (mask1) {
					mask1->setLocalZOrder(1);
					mask1->setAnchorPoint(Vec2(0, 0.5));
					mask1->setRotation(0);
				}
				firer->setLocalZOrder(0);

				mask2->setLocalZOrder(3);
				mask2->setAnchorPoint(Vec2(1, 0.5));
				mask2->setRotation(0);
				firel->setLocalZOrder(2);
			}
			else {
				if (mask1) {
					mask1->setLocalZOrder(1);
					mask1->setAnchorPoint(Vec2(0, 0.5));
					mask1->setRotation(0);
				}
				firer->setLocalZOrder(4);
				mask2->setLocalZOrder(3);
				mask2->setAnchorPoint(Vec2(1, 0.5));
				mask2->setRotation(0);
				firel->setLocalZOrder(2);
			}
		};
	};
	LevelPointerTest::LevelPointerTest() :MovieClip("", "pointer", "LevelBase"), statusAnima(0), timer(0), counter(0)
	{
		SET_NODETYPENAME();
		pointerCase = this->createCase("pointerCase");
		fireAnima = this->createMovieClipSub("fireAnima", false);
		eyesAnima = this->createMovieClipSub("eyesAnima");
		mask1 = this->getSprite("mask1");
		mask2 = this->getSprite("mask2");
		firel = this->getSprite("firel");
		firer = this->getSprite("firer"); 
		arrow = (Sprite*)this->getArmature()->getSlot("arrow")->getDisplay();
	};
}
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
	LevelPointerTest * pointer=NULL;
	Tower1_mc * tower = NULL;
	void onEnter()
	{
		BaseDemo::onEnter();
	}
	virtual void _onStart()
	{
		currentFrame = frameCounter = 0;
		this->setName("layer");
		this->schedule(static_cast<cocos2d::SEL_SCHEDULE>(&DBComTest::scheduleUpdate));

		//addPointer();
		//addTest();
		//addWorldInterface();
		addPointer();
		return;
	}
	int currentFrame;
	bool dir;
	int totalFrames, frameCounter;
	string direction;
	MovieClip *mc;
	ui::Text *text = NULL; 

	void round() {
		if (pointer->currentFrame == 1) {
			float r= pointer->mask1->getRotation();
			pointer->mask1->setRotation(r + 1);
			if (r == 180) {
				pointer->gotoAndStop(2);
				pointer->resetMask();
			}
		}
		else {
			float r = pointer->mask2->getRotation();
			pointer->mask2->setRotation(r + 1);
			if (r == 180) {
				pointer->gotoAndStop(1);
				pointer->resetMask();
			}
		}
		pointer->fireAnima->setRotation(pointer->fireAnima->getRotation()+1);
	}
	virtual void  scheduleUpdate(float dt)
	{
		if (this->frameCounter < 30)
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
		//std::changeAnchorPoint(pointer->mask1, Vec2(0, 0.5));
		currentFrame++;
		//if (currentFrame<=255) {
		//	//pointer->mask5 ->setOpacity(256-currentFrame);
		//	pointer->mask2 ->mask->setOpacity(256-currentFrame);
		//}
		//else {
		//	//pointer->mask5->setOpacity(currentFrame%256);
		//	pointer->mask2->mask->setOpacity(currentFrame % 256);
		//}
		
		round();


		//pointer->fireAnima->setRotation(currentFrame);
		//logInfo("pointer->mask1->getPosition ", pointer->mask1->mask->getPosition(), &pointer->mask1->mask->getAnchorPointInPoints());
		//logInfo("pointer->mask2->getPosition ", pointer->mask2->mask->getPosition(), &pointer->mask2->mask->getAnchorPointInPoints());

		//if (currentFrame > 30) {
		//	//text->setText(I18N_VALUE(I18N_CODE::U102));
		//	if (text)
		//		std::setText(text, I18N_VALUE(I18N_CODE::U102));
			//if (pointer) {
			//	pointer->fireAnima->setVisible(true);
			//	Vec2 pt = pointer->fireAnima->container->getPosition();
			//	Vec2 wpt = pointer->fireAnima->container->convertToWorldSpace(pt);
			//	logInfo(getNamePath(pointer->fireAnima->container), pt, &wpt, &pointer->fireAnima->container->convertToNodeSpace(wpt));

			//	pt = pointer->tcase1->getPosition();
			//	wpt = pointer->tcase1->convertToWorldSpace(pt);
			//	logInfo(getNamePath(pointer->tcase1), pt, &wpt, &pointer->tcase1->convertToNodeSpace(wpt));
			//	pt = pointer->tcase2->getPosition();
			//	wpt = pointer->tcase2->convertToWorldSpace(pt);
			//	logInfo(getNamePath(pointer->tcase2), pt, &wpt, &pointer->tcase2->convertToNodeSpace(wpt));
			//}
		//	if (container) {
		//		printSphereCase();
		//		if (currentFrame < 40) {
		//			spheresBlockManage("unblockFire");
		//		}else if (currentFrame < 50) {
		//			spheresBlockManage("unblockIce");
		//		}
		//		else if (currentFrame < 60) {
		//			spheresBlockManage("unblockStone");
		//		}
		//		else if (currentFrame < 70) {
		//			spheresBlockManage("unblockLevin");
		//		} 
		//		printSphereCase();
		//	}
		//}

 

	}
 
	void printNodePos(Node *node) {
		Vec2 pt = node->getPosition();
		Vec2 wpt = node->convertToWorldSpace(pt);
		Vec2 wnpt = node->convertToNodeSpace(wpt);
		logInfo(getNamePath(node), pt, &wpt, &wnpt);
	}
	void addTest() {
		string str1 = I18N_VALUE(I18N_CODE::U001);
		auto * label1 = Label::create(str1, "Arial", 36);
		label1->setPosition(320, 270);
		addChild(label1);

		string str2 = I18N_VALUE(I18N_CODE::U002);
		auto* label2 = Label::create(str2, "Arial", 36);
		label2->setPosition(320, 230);
		addChild(label2);

		string str3 = I18N_VALUE(I18N_CODE::U003);
		text = ui::Text::create();
		text->setPosition(Vec2(320, 190));
		text->setText(str3);
		addChild(text);

		auto* label4 = cocos2d::TextFieldTTF::create(str3, "Arial", 36);
		label4->setPosition(Vec2(320, 150));
		addChild(label4);

		auto start_button = ui::Button::create();
		start_button->setContentSize(Size(100, 30));
		start_button->setTitleText(str1);
		start_button->setTitleFontName("微软雅黑");
		start_button->setTitleFontSize(16);
		start_button->setPosition(Vec2(100, 100));
		this->addChild(start_button);
	}
	void addPointer() {
	pointer = new LevelPointerTest();

		//pointer->mask1->setVisible(false);
		//pointer->mask2->setVisible(false);
		//pointer->arrow->setVisible(false);
		//pointer->mask3->setVisible(false);
		//pointer->mask4->setVisible(false);
		//pointer->mask5->setVisible(false);

		pointer->eyesAnima->play(0);
		pointer->fireAnima->play(0);
		pointer->setPosition(200, 200);
		this->addChild(pointer);
		pointer->statusAnima = 1;
		pointer->myPoint = cocos2d::Point(pointer->getPosition());
 		pointer->resetMask();
		//pointer->mask2->stop();
		//pointer->arrow->stop();
		//pointer->fireAnima->setVisible(false);
		//pointer->eyesAnima->setVisible(false);
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
		//float tempObject = pointer->getRotation();
		//pointer->setRotation(0);
		//pointer->arrow->setRotation(tempObject);

		////std::setAnchorPoint(pointer->mask1, Vec2(1, 0.5));
		//std::changeAnchorPoint(pointer->mask1->mask, Vec2(0, 0.5));
		//std::changeAnchorPoint(pointer->mask2->mask, Vec2(1, 0.5));
		////pointer->mask1->setRotation(-180);

		//pointer->mask2->mask->setOpacityModifyRGB(true);
		//pointer->mask5->setOpacityModifyRGB(true);
		//glEnable(GL_BLEND);
		////glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		////glBlendFunc(GL_ONE, GL_ONE);GL_DST_ALPHA

		//ccBlendFunc blendFunc;
		//blendFunc.src = GL_SRC_ALPHA;
		//blendFunc.dst = GL_DST_ALPHA;
		////pointer->mask1->setBlendFunc(blendFunc);
		////pointer->mask2->mask->setBlendFunc(blendFunc);
		////blendFunc.src = GL_ONE;
		////blendFunc.dst = GL_ZERO; 
		////blendFunc.src = GL_DST_ALPHA;            // mask图片的当前alpha值是多少，如果是0（完全透明），那么就显示mask的。如果是1（完全不透明）
		////blendFunc.dst = GL_ZERO;                // maskSprite不可见

		//pointer->mask2->mask->setPosition(pointer->mask2->mask->getPosition() + Vec2(50, 50));
		//blendFunc.src = GL_DST_ALPHA;            // mask图片的当前alpha值是多少，如果是0（完全透明），那么就显示mask的。如果是1（完全不透明）
		//blendFunc.dst = GL_ZERO;                // maskSprite不可见

		//pointer->mask5->visit();
		//pointer->mask2->mask->visit();

		////pointer->mask1->setVisible(false); 
		////pointer->mask2->setVisible(false);
		////if(pointer->mask3->mask)pointer->mask3->mask->setBlendFunc(blendFunc);
		////if (pointer->mask4->mask)pointer->mask4->mask->setBlendFunc(blendFunc);
		//pointer->mask5->setPosition(pointer->mask5->getPosition() + Vec2(50, 50));
		////pointer->mask5->setBlendFunc(blendFunc);
		////pointer->mask5 ->setOpacity(0);
		////pointer->mask2 ->mask->setOpacity(0);




		////pointer->mask5->setVisible(false);
		//pointer->mask3->setVisible(false);
		//pointer->mask4->setVisible(false);
		//pointer->arrow->setVisible(false);
		////pointer->mask1->setRotation(-180);
		//Sprite *mask6 = (Sprite*)pointer->getArmature()->getSlot("Layer 3")->getDisplay();
		//mask6->setVisible(false);
		//mask6 = (Sprite*)pointer->getArmature()->getSlot("Layer 14")->getDisplay();
		//mask6->setVisible(false);
		//logInfo("pointer->mask1->getPosition ", pointer->mask1->mask->getPosition(), &pointer->mask1->mask->getAnchorPointInPoints());

	}
  
}

;