#include "BaseDemo.h"
#include "BaseHeaders.h"
#include "BaseNode.h"
#include "MaskTest.h"
#include "engine/WorldInterface_mc.h"
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
	LevelPointer * pointer=NULL;
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
		addTower();
		return;
	}
	int currentFrame;
	bool dir;
	int totalFrames, frameCounter;
	string direction;
	MovieClip *mc;
	ui::Text *text = NULL;
	WorldInterface_mc *container = NULL;

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
		//pointer->mask1->setRotation(pointer->mask1->getRotation()+1);
		//pointer->mask2->setRotation(pointer->mask2->getRotation()+1);
		//pointer->fireAnima->setRotation(currentFrame);
		//logInfo("pointer->mask1->getPosition ", pointer->mask1->mask->getPosition(), &pointer->mask1->mask->getAnchorPointInPoints());
		//logInfo("pointer->mask2->getPosition ", pointer->mask2->mask->getPosition(), &pointer->mask2->mask->getAnchorPointInPoints());

		//if (currentFrame > 30) {
		//	//text->setText(I18N_VALUE(I18N_CODE::U102));
		//	if (text)
		//		std::setText(text, I18N_VALUE(I18N_CODE::U102));
		//	if (pointer) {
		//		pointer->fireAnima->setVisible(true);
		//		Vec2 pt = pointer->fireAnima->container->getPosition();
		//		Vec2 wpt = pointer->fireAnima->container->convertToWorldSpace(pt);
		//		logInfo(getNamePath(pointer->fireAnima->container), pt, &wpt, &pointer->fireAnima->container->convertToNodeSpace(wpt));

		//		pt = pointer->tcase1->getPosition();
		//		wpt = pointer->tcase1->convertToWorldSpace(pt);
		//		logInfo(getNamePath(pointer->tcase1), pt, &wpt, &pointer->tcase1->convertToNodeSpace(wpt));
		//		pt = pointer->tcase2->getPosition();
		//		wpt = pointer->tcase2->convertToWorldSpace(pt);
		//		logInfo(getNamePath(pointer->tcase2), pt, &wpt, &pointer->tcase2->convertToNodeSpace(wpt));
		//	}
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

		if (currentFrame > 100) {
			tower->sphere1->setVisible(true);
			if(!tower->sphere1->isPlay())
				tower->sphere1->play(0);
			if (((currentFrame / 100 ) %4+1) != tower->sphere1Bullet->currentFrame) {
				tower->sphere1Bullet->gotoAndStop((currentFrame / 100) % 4 + 1);
				//if (!tower->sphere1BulletCont->isPlay())
				//	tower->sphere1BulletCont->play(1); 
			}
		}

	}
	void printSphereCase() {
		printNodePos(container->fireSphereSphereCase);
		printNodePos(container->iceSphereSphereCase);
		printNodePos(container->stoneSphereSphereCase);
		printNodePos(container->levinSphereSphereCase);

	}
	void printNodePos(Node *node) {
		Vec2 pt = node->getPosition();
		Vec2 wpt = node->convertToWorldSpace(pt);
		logInfo(getNamePath(node), pt, &wpt, &node->convertToNodeSpace(wpt));
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
		pointer = new LevelPointer();

		pointer->mask1->setVisible(false);
		pointer->mask2->setVisible(false);
		pointer->arrow->setVisible(false);
		pointer->mask3->setVisible(false);
		pointer->mask4->setVisible(false);
		pointer->mask5->setVisible(false);


		pointer->eyesAnima->play(0);
		pointer->fireAnima->play(0);
		pointer->setPosition(200, 200);
		this->addChild(pointer);
		pointer->statusAnima = 1;
		pointer->myPoint = cocos2d::Point(pointer->getPosition());
		pointer->gotoAndStop(1);
		//pointer->mask2->stop();
		//pointer->arrow->stop();
		pointer->fireAnima->setVisible(false);
		pointer->eyesAnima->setVisible(false);
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

		pointer->mask2->mask->setPosition(pointer->mask2->mask->getPosition() + Vec2(50, 50));
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
		logInfo("pointer->mask1->getPosition ", pointer->mask1->mask->getPosition(), &pointer->mask1->mask->getAnchorPointInPoints());

	}
	void addWorldInterface() {
		container = new WorldInterface_mc();
		this->addChild(container);


		this->container->stop();

		this->container->fireBack->stop();
		this->container->iceBack->stop();
		this->container->stoneBack->stop();
		this->container->levinBack->stop();
		//this->container->backComponents->stop();
		this->container->fireSphere->stop();
		this->container->iceSphere->stop();
		this->container->stoneSphere->stop();
		this->container->levinSphere->stop();
		this->container->getAll->stop();
		this->container->buyFire->stop();
		this->container->buyIce->stop();
		this->container->buyStone->stop();
		this->container->buyLevin->stop();
		this->container->buyGetAll->stop();
		this->container->buyFireCoin->stop();
		this->container->buyIceCoin->stop();
		this->container->buyStoneCoin->stop();
		this->container->buyLevinCoin->stop();
		this->container->buyGetAllCoin->stop();
		this->container->sell->stop();
		this->container->book->stop();
		this->container->pause->stop();
		this->container->startWaves->stop();
		this->container->butCastGolem->stop();
		this->container->butCastIceman->stop();
		this->container->butCastAir->stop();
		this->container->barInfo->stop();
		this->container->slow->stop();
		this->container->fast->stop();
		//this->container->traceBezier->stop();
		this->container->barInfo->setPositionY(15);//Main:: - 585
		this->container->bookBookCase->setMouseEnabled(true);
		this->container->pausePauseCase->setMouseEnabled(true);
		this->container->startWavesStartWavesCase->setMouseEnabled(true);
		this->container->butCastGolemCastGolemCase->setMouseEnabled(true);
		this->container->butCastIcemanCastIcemanCase->setMouseEnabled(true);
		this->container->butCastAirCastAirCase->setMouseEnabled(true);
		//this->container->slow->setMouseEnabled(true);
		if (this->container->traceBezier)this->container->traceBezier->setMouseEnabled(true);
		//this->container->fireNumTXT->setMouseEnabled(false);
		//this->container->iceNumTXT->setMouseEnabled(false);
		//this->container->stoneNumTXT->setMouseEnabled(false);
		//this->container->levinNumTXT->setMouseEnabled(false);
		//this->container->barInfo->setMouseChildren(false);
		//this->container->barInfo->setMouseEnabled(false);
		//this->container->lastTime->setMouseEnabled(false);

		this->container->butCastGolem->setAlpha(0);
		this->container->butCastIceman->setAlpha(0);
		this->container->butCastAir->setAlpha(0);

		this->container->butCastGolem->setVisible(false);
		this->container->butCastIceman->setVisible(false);
		this->container->butCastAir->setVisible(false);
		this->container->barInfo->setVisible(false);

		this->container->lastTime->setVisible(false);
		//this->container->buyFireLightUp->setVisible(false);
		//this->container->buyIceLightUp->setVisible(false);
		//this->container->buyStoneLightUp->setVisible(false);
		//this->container->buyLevinLightUp->setVisible(false);
		//this->container->buyGetAllLightUp->setVisible(false);

		//		this->container->backComponents.cacheAsBitmap = true;
		this->container->fireSphereMyPoint = this->container->fireSphere->localToGlobal(this->container->fireSphereSphereCase->getPosition());
		this->container->iceSphereMyPoint = this->container->iceSphere->localToGlobal(this->container->iceSphereSphereCase->getPosition());
		this->container->stoneSphereMyPoint = this->container->stoneSphere->localToGlobal(this->container->stoneSphereSphereCase->getPosition());
		this->container->levinSphereMyPoint = this->container->levinSphere->localToGlobal(this->container->levinSphereSphereCase->getPosition());
		this->container->getAllMyPoint = this->container->getAll->localToGlobal(this->container->getAllSphereCase->getPosition());
		this->container->fireBacklightTurnFlag = true;
		this->container->iceBacklightTurnFlag = true;
		this->container->stoneBacklightTurnFlag = true;
		this->container->levinBacklightTurnFlag = true;
		this->container->fireBacklight->stop();
		this->container->iceBacklight->stop();
		this->container->stoneBacklight->stop();
		this->container->levinBacklight->stop();
		this->container->fireBacklight->setVisible(false);
		this->container->iceBacklight->setVisible(false);
		this->container->stoneBacklight->setVisible(false);
		this->container->levinBacklight->setVisible(false);
		this->container->buyGetAll->setVisible(false);
		this->container->testRestart->stop();
		this->container->testRestartBoard->stop();
		this->container->testRestart->setMouseEnabled(true);
		spheresBlockManage();
	};
	void spheresBlockManage(string param1="")
	{
		if (param1 == "")
		{
			//this->container->fireSphere->setAlpha(0);
			//this->container->fireNumTXT->setAlpha(0);
			//this->container->buyFire->setAlpha(0);
			this->container->fireSphere->setMouseChildren(false);
			this->container->fireSphere->setMouseEnabled(false);
			this->container->fireNumTXT->setMouseEnabled(false);
			this->container->buyFire->setMouseChildren(false);
			this->container->buyFire->setMouseEnabled(false);
			this->container->fireSphere->setVisible(false);

			this->container->buyFire->gotoAndStop(2);
			this->container->buyIce->gotoAndStop(2);
			this->container->buyStone->gotoAndStop(2);
			this->container->buyLevin->gotoAndStop(2);
			this->container->buyGetAll->gotoAndStop(2);

			//this->container->iceSphere->setAlpha(0);
			//this->container->iceNumTXT->setAlpha(0);
			//this->container->buyIce->setAlpha(0);
			this->container->iceSphere->setMouseChildren(false);
			this->container->iceSphere->setMouseEnabled(false);
			this->container->iceNumTXT->setMouseEnabled(false);
			this->container->buyIce->setMouseChildren(false);
			this->container->buyIce->setMouseEnabled(false);
			this->container->iceSphere->setVisible(false);

			//this->container->stoneSphere->setAlpha(0);
			//this->container->stoneNumTXT->setAlpha(0);
			//this->container->buyStone->setAlpha(0);
			this->container->stoneSphere->setMouseChildren(false);
			this->container->stoneSphere->setMouseEnabled(false);
			this->container->stoneNumTXT->setMouseEnabled(false);
			this->container->buyStone->setMouseChildren(false);
			this->container->buyStone->setMouseEnabled(false);
			this->container->stoneSphere->setVisible(false);

			//this->container->levinSphere->setAlpha(0);
			//this->container->levinNumTXT->setAlpha(0);
			//this->container->buyLevin->setAlpha(0);
			this->container->levinSphere->setMouseChildren(false);
			this->container->levinSphere->setMouseEnabled(false);
			this->container->levinNumTXT->setMouseEnabled(false);
			this->container->buyLevin->setMouseChildren(false);
			this->container->buyLevin->setMouseEnabled(false);
			this->container->levinSphere->setVisible(false);

			//this->container->buyGetAll->setAlpha(0);
			//this->container->getAllNumTXT->setAlpha(0);
			this->container->getAllNumTXT->setMouseEnabled(false);
			this->container->buyGetAll->setMouseChildren(false);
			this->container->buyGetAll->setMouseEnabled(false);
			this->container->getAll->setVisible(false);

			this->container->getAll->gotoAndStop(3);
			this->container->fireBack->gotoAndStop(3);
			this->container->iceBack->gotoAndStop(3);
			this->container->stoneBack->gotoAndStop(3);
			this->container->levinBack->gotoAndStop(3);
		}
		else if (param1 == "unblockFire")
		{
			this->container->fireSphere->setScaleY(1);
			this->container->fireSphere->setScaleX(1);
			this->container->fireSphere->setAlpha(1);
			this->container->fireNumTXT->setAlpha(1);
			this->container->buyFire->setAlpha(1);
			this->container->fireSphere->setMouseChildren(true);
			this->container->fireSphere->setMouseEnabled(true);
			this->container->fireNumTXT->setMouseEnabled(false);
			this->container->buyFire->setMouseChildren(true);
			this->container->buyFire->setMouseEnabled(true);
			this->container->fireBack->gotoAndStop(1);
			this->container->fireSphere->setVisible(true);
		}
		else if (param1 == "unblockIce")
		{
			this->container->iceSphere->setScaleY(1);
			this->container->iceSphere->setScaleX(1);
			this->container->iceSphere->setAlpha(1);
			this->container->iceNumTXT->setAlpha(1);
			this->container->buyIce->setAlpha(1);
			this->container->iceSphere->setMouseChildren(true);
			this->container->iceSphere->setMouseEnabled(true);
			this->container->iceNumTXT->setMouseEnabled(false);
			this->container->buyIce->setMouseChildren(true);
			this->container->buyIce->setMouseEnabled(true);
			this->container->iceBack->gotoAndStop(1);
			this->container->iceSphere->setVisible(true);
		}
		else if (param1 == "unblockStone")
		{
			this->container->stoneSphere->setScaleY(1);
			this->container->stoneSphere->setScaleX(1);
			this->container->stoneSphere->setAlpha(1);
			this->container->stoneNumTXT->setAlpha(1);
			this->container->buyStone->setAlpha(1);
			this->container->stoneSphere->setMouseChildren(true);
			this->container->stoneSphere->setMouseEnabled(true);
			this->container->stoneNumTXT->setMouseEnabled(false);
			this->container->buyStone->setMouseChildren(true);
			this->container->buyStone->setMouseEnabled(true);
			this->container->stoneBack->gotoAndStop(1);
			this->container->stoneSphere->setVisible(true);
		}
		else if (param1 == "unblockLevin")
		{
			this->container->levinSphere->setScaleY(1);
			this->container->levinSphere->setScaleX(1);
			this->container->levinSphere->setAlpha(1);
			this->container->levinNumTXT->setAlpha(1);
			this->container->buyLevin->setAlpha(1);
			this->container->levinSphere->setMouseChildren(true);
			this->container->levinSphere->setMouseEnabled(true);
			this->container->levinNumTXT->setMouseEnabled(false);
			this->container->buyLevin->setMouseChildren(true);
			this->container->buyLevin->setMouseEnabled(true);
			this->container->levinBack->gotoAndStop(1);
			this->container->levinSphere->setVisible(true);
		}
		else if (param1 == "unblockGetAll")
		{
			this->container->getAll->setScaleY(1);
			this->container->getAll->setScaleX(1);
			this->container->getAll->gotoAndStop(1);
			this->container->getAllFire->stop();
			this->container->getAllIce->stop();
			this->container->getAllStone->stop();
			this->container->getAllLevin->stop();
			this->container->buyGetAll->setAlpha(1);
			this->container->getAllNumTXT->setAlpha(1);
			this->container->getAllNumTXT->setMouseEnabled(false);
			this->container->buyGetAll->setMouseChildren(true);
			this->container->buyGetAll->setMouseEnabled(true);
			this->container->getAll->setVisible(true);
		}
 		return;
	}
	void addTower() {
		tower = new Tower1_mc();
		this->addChild(tower);
		tower->setPosition(200, 200);
		tower->sphere1->setVisible(false);
	}
}

;