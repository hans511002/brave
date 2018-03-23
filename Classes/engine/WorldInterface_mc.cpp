#include "WorldInterface_mc.h"  
using namespace cocos2d::ui;

namespace engine
{
	WorldInterface_mc::WorldInterface_mc():barinfoback(NULL),healthbar(NULL),moneybar(NULL),butCastAir(NULL),butCastGolem(NULL),
	    butCastIceman(NULL),fastbtn(NULL),faster(NULL),buyFire(NULL),buyIce(NULL),buyLevin(NULL),buyStone(NULL),buyGetAll(NULL),getAll(NULL),
	    pause(NULL),startWaves(NULL),stoneBacklight(NULL),levinBacklight(NULL),iceBacklight(NULL),fireBacklight(NULL),iceBack(NULL),fireBack(NULL),
	    levinBack(NULL),stoneBack(NULL),iceSphere(NULL),fireSphere(NULL),levinSphere(NULL),stoneSphere(NULL),lastTime(NULL),waveTXT(NULL),
	    liveTXT(NULL),moneyTXT(NULL),levinNumTXT(NULL),iceNumTXT(NULL),fireNumTXT(NULL),stoneNumTXT(NULL),getAllNumTXT(NULL)
	{

	}
    bool WorldInterface_mc::init()
    {
        BaseNode::init();
        string basePath = "worldinterface/";
        //左上
        barinfoback = Sprite::create(basePath + "barinfo/barinfoback.png");
        std::setAnchorPoint(barinfoback, 50, 500);
        healthbar = Sprite::create(basePath + "barinfo/healthbar.png");
        std::setAnchorPoint(healthbar, 70, 500);
        moneybar = Sprite::create(basePath + "barinfo/moneybar.png");
        std::setAnchorPoint(moneybar, 90, 500);

        //左下
        btncastback = Sprite::create(basePath + "btncastback/btncastback.png");
        std::setAnchorPoint(btncastback, 50, 50);
        butCastAir = Sprite::create(basePath + "btncastback/butCastAir.png");
        std::setAnchorPoint(butCastAir, 100, 50);
        butCastGolem = Sprite::create(basePath + "btncastback/butCastGolem.png");
        std::setAnchorPoint(butCastGolem, 150, 50);
        butCastIceman = Sprite::create(basePath + "btncastback/butCastIceman.png");
        std::setAnchorPoint(butCastIceman, 200, 50);

        //技能背景
        sphereback = Sprite::create(basePath + "sphere/backsphere.png");
        std::setAnchorPoint(sphereback, 250, 550);
        iceBack = Sprite::create(basePath + "sphere/iceBack.png");
        std::setAnchorPoint(iceBack, 250, 550);
        fireBack = Sprite::create(basePath + "sphere/fireBack.png");
        std::setAnchorPoint(fireBack, 300, 550);
        levinBack = Sprite::create(basePath + "sphere/levinBack.png");
        std::setAnchorPoint(levinBack, 350, 550);
        stoneBack = Sprite::create(basePath + "sphere/stoneBack.png");
        std::setAnchorPoint(stoneBack, 400, 550);
        getAll = Sprite::create(basePath + "sphere/allsphere.png");
        std::setAnchorPoint(getAll, 450, 550);

        //购买价格背景
        buyFire = Sprite::create(basePath + "sphere/buypricebar.png");
        std::setAnchorPoint(buyFire, 250, 500);
        buyIce = Sprite::create(basePath + "sphere/buypricebar.png");
        std::setAnchorPoint(buyIce, 300, 500);
        buyLevin = Sprite::create(basePath + "sphere/buypricebar.png");
        std::setAnchorPoint(buyLevin, 350, 500);
        buyStone = Sprite::create(basePath + "sphere/buypricebar.png");
        std::setAnchorPoint(buyStone, 400, 500);
        buyGetAll = Sprite::create(basePath + "sphere/buypricebar.png");
        std::setAnchorPoint(buyGetAll, 450, 500);

        //图片代替动画
        iceSphere = Sprite::create(basePath + "sphere/iceSphere.png");
        std::setAnchorPoint(iceSphere, 250, 560);;
        fireSphere = Sprite::create(basePath + "sphere/fireSphere.png");
        std::setAnchorPoint(fireSphere, 300, 560);
        levinSphere = Sprite::create(basePath + "sphere/levinSphere.png");
        std::setAnchorPoint(levinSphere, 350, 560);
        stoneSphere = Sprite::create(basePath + "sphere/stoneSphere.png");
        std::setAnchorPoint(stoneSphere, 400, 560);

        //鼠标移上的过度动画
        DBCCFactory::getInstance()->loadDragonBonesData(basePath + "spherelight/skeleton.xml", "spherelight");
        DBCCFactory::getInstance()->loadTextureAtlas(basePath + "spherelight/texture.xml", "spherelight");
        this->stoneBacklight = DBCCFactory::getInstance()->buildArmatureNode("spherelight");
        this->levinBacklight = DBCCFactory::getInstance()->buildArmatureNode("spherelight");
        this->iceBacklight = DBCCFactory::getInstance()->buildArmatureNode("spherelight");
        this->fireBacklight = DBCCFactory::getInstance()->buildArmatureNode("spherelight");

        DBCCFactory::getInstance()->loadDragonBonesData(basePath + "stoneBacked/skeleton.xml", "stonebacked");
        DBCCFactory::getInstance()->loadTextureAtlas(basePath + "stoneBacked/texture.xml", "stonebacked");
        this->stoneBacked = DBCCFactory::getInstance()->buildArmatureNode("stonebacked");
        DBCCFactory::getInstance()->loadDragonBonesData(basePath + "levinBacked/skeleton.xml", "levinbacked");
        DBCCFactory::getInstance()->loadTextureAtlas(basePath + "levinBacked/texture.xml", "levinbacked");
        this->levinBacked = DBCCFactory::getInstance()->buildArmatureNode("levinbacked");
        DBCCFactory::getInstance()->loadDragonBonesData(basePath + "iceBacked/skeleton.xml", "icebacked");
        DBCCFactory::getInstance()->loadTextureAtlas(basePath + "iceBacked/texture.xml", "icebacked");
        this->iceBacked = DBCCFactory::getInstance()->buildArmatureNode("icebacked");
        DBCCFactory::getInstance()->loadDragonBonesData(basePath + "fireBacked/skeleton.xml", "firebacked");
        DBCCFactory::getInstance()->loadTextureAtlas(basePath + "fireBacked/texture.xml", "firebacked");
        this->fireBacked = DBCCFactory::getInstance()->buildArmatureNode("firebacked");

        pause = Button::create(basePath + "startbtn/pause.png", basePath + "startbtn/paused.png");
        startbtnback = Sprite::create(basePath + "startbtn/startbtnback.png");
        std::setAnchorPoint(startbtnback, 500, 0);
        this->addChild(startbtnback); 
        DBCCFactory::getInstance()->loadDragonBonesData(basePath + "startbtn/fasterbtn/skeleton.xml", "faster");
        DBCCFactory::getInstance()->loadTextureAtlas(basePath + "startbtn/fasterbtn/texture.xml", "faster");
        this->faster = DBCCFactory::getInstance()->buildArmatureNode("faster");
        this->fastbtn = Button::create(basePath + "startbtn/fasterbtn.png", basePath + "startbtn/fastbtned.png");
        this->fastbtn->setPosition(Vec2(10, 0));
        startWaves = Button::create(basePath + "startbtn/startWavesoff.png", basePath + "startbtn/startWaveson.png");
        startbtnback->addChild(fastbtn);
        startbtnback->addChild(startWaves);
        std::setAnchorPoint(startWaves, 100, 10);
        std::setAnchorPoint(startWaves, 160, 10);


        startWaves->setPressedActionEnabled(true);
        //startWaves->addTouchEventListener(this, toucheventselector(PlayState::btnPlayAction));
        //addChild(startWaves, 10000);
        this->autorelease();
        return true;
    }
}
