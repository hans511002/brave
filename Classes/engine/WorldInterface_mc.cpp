#include "WorldInterface_mc.h"  
using namespace cocos2d::ui;
#include "cocostudio/DictionaryHelper.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetReader/WidgetReader.h"
using namespace cocostudio;

namespace engine
{
    WorldInterface_mc::WorldInterface_mc() :barinfoback(NULL), healthbar(NULL), moneybar(NULL), butCastAir(NULL), butCastGolem(NULL), allSphereBack(NULL),
        butCastIceman(NULL), fastbtn(NULL), faster(NULL), buyFire(NULL), buyIce(NULL), buyLevin(NULL), buyStone(NULL), buyGetAll(NULL), allSphere(NULL),
        pause(NULL), startWaves(NULL), stoneBacklight(NULL), levinBacklight(NULL), iceBacklight(NULL), fireBacklight(NULL), iceBack(NULL), fireBack(NULL),
        levinBack(NULL), stoneBack(NULL), iceSphere(NULL), fireSphere(NULL), levinSphere(NULL), stoneSphere(NULL), lastTime(NULL), waveTXT(NULL),
        liveTXT(NULL), moneyTXT(NULL), levinNumTXT(NULL), iceNumTXT(NULL), fireNumTXT(NULL), stoneNumTXT(NULL), getAllNumTXT(NULL)
    {

    }
    bool WorldInterface_mc::init()
    {
        BaseNode::init();
        string basePath = "res/worldinterface/";
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
        DBCCFactory::getInstance()->loadDragonBonesData(basePath + "startbtn/fasterbtn/skeleton.xml", "faster");
        DBCCFactory::getInstance()->loadTextureAtlas(basePath + "startbtn/fasterbtn/texture.xml", "faster");
        this->faster = DBCCFactory::getInstance()->buildArmatureNode("faster");



        Node * node = CSLoader::createNode("worldinterface.csb");
        //CSLoader cs;
        //node = cs.createNodeFromJson("D:\\work\\gm\\brave\\proj.win32\\Debug.win32\\worldinterface.json");
        this->addChild(node);
        this->autorelease();
        //左上
        barinfoback = (Sprite *)node->getChildByName("barinfoback"); 
        healthbar = (Sprite *)node->getChildByName("healthbar");  
        moneybar = (Sprite *)node->getChildByName("moneybar");  
        //左下
        btncastback = (Sprite *)node->getChildByName("btncastback");  
        butCastAir = (Sprite *)node->getChildByName("butCastAir");   
        butCastGolem = (Sprite *)node->getChildByName("butCastGolem");   
        butCastIceman = (Sprite *)node->getChildByName("butCastIceman"); 


        //技能背景
        sphereback = (Sprite *)node->getChildByName("sphereback"); 
        iceBack = (Sprite *)node->getChildByName("iceBack");  
        fireBack = (Sprite *)node->getChildByName("fireBack");  
        stoneBack = (Sprite *)node->getChildByName("stoneBack");  
        levinBack = (Sprite *)node->getChildByName("levinBack");  
        allSphereBack = (Sprite *)node->getChildByName("allsphereback");

        this->fireBacklight->setPosition(this->fireBack->getPosition());
        this->iceBacklight->setPosition(this->iceBack->getPosition());
        this->stoneBacklight->setPosition(this->stoneBack->getPosition());
        this->levinBacklight->setPosition(this->levinBack->getPosition());

        this->stoneBacked->setPosition(this->levinBack->getPosition());
        this->levinBacked->setPosition(this->levinBack->getPosition());
        this->iceBacked->setPosition(this->levinBack->getPosition());
        this->fireBacked->setPosition(this->levinBack->getPosition());
        
         

        //购买价格背景
        buyFire = (Sprite *)node->getChildByName("buyFire");  
        buyIce = (Sprite *)node->getChildByName("buyIce");  
        buyLevin = (Sprite *)node->getChildByName("buyLevin"); 
        buyStone = (Sprite *)node->getChildByName("buyStone"); 
        buyGetAll = (Sprite *)node->getChildByName("buyGetAll");  
        
        //图片代替动画
        iceSphere = (Sprite *)node->getChildByName("iceSphere");   
        fireSphere = (Sprite *)node->getChildByName("fireSphere");  
        levinSphere = (Sprite *)node->getChildByName("levinSphere");  
        stoneSphere = (Sprite *)node->getChildByName("stoneSphere");
        allSphere = (Sprite *)node->getChildByName("allSphere");
        

        //startbtnback
        startbtnback = (Sprite *)node->getChildByName("startbtnback");
        startWaves = (ui::Button *)node->getChildByName("startWaves");
        fastbtn = (ui::Button *)node->getChildByName("fastbtn");
        pause = (ui::Button *)node->getChildByName("pause");
        startWaves->setVisible(true);
        fastbtn->setVisible(true);
        this->faster->setPosition(this->fastbtn->getPosition());
         
          
        //lastTime=(ui::Text *)node->getChildByName("lastTime"); 
        waveTXT = (ui::Text *)node->getChildByName("waveTXT"); 
        liveTXT = (ui::Text *)node->getChildByName("liveTXT");;// : TextField;
        moneyTXT = (ui::Text *)node->getChildByName("moneyTXT");;//: TextField;

        fireNumTXT = (ui::Text *)node->getChildByName("fireNumTXT");;// : TextField;
        iceNumTXT = (ui::Text *)node->getChildByName("iceNumTXT");;//: TextField;
        stoneNumTXT = (ui::Text *)node->getChildByName("stoneNumTXT");;//public var stoneNumTXT : TextField;
        levinNumTXT = (ui::Text *)node->getChildByName("levinNumTXT");;// : TextField;
        getAllNumTXT = (ui::Text *)node->getChildByName("getAllNumTXT");; // public var getAllNumTXT : TextField;

        firePrice = (ui::Text *)node->getChildByName("firePrice");;// : TextField;
        icePrice = (ui::Text *)node->getChildByName("icePrice");;//: TextField;
        stonePrice = (ui::Text *)node->getChildByName("stonePrice");;//public var stoneNumTXT : TextField;
        levinPrice = (ui::Text *)node->getChildByName("levinPrice");;// : TextField;
        getAllPrice = (ui::Text *)node->getChildByName("getAllPrice");; // public var getAllNumTXT : TextField;
         
        
        liveTXT->setText("50");
 
        //startWaves->addClickEventListener(CC_CALLBACK_1(WorldInterface_mc::startWavesCallback, this));
        //fastbtn->addClickEventListener(CC_CALLBACK_1(WorldInterface_mc::startWavesCallback, this));
        

        this->setName("workdIntface_mc");
         
        //fastbtn->addTouchEventListener(fastbtn, toucheventselector(BaseNode::touchAction));
        //startWaves->addTouchEventListener(startWaves, toucheventselector(BaseNode::touchAction));
         
        //EventListenerTouchOneByOne *touchListener = EventListenerTouchOneByOne::create();
        //touchListener->setSwallowTouches(true);
        //touchListener->onTouchBegan = [this](Touch *touch, Event *event){
        //    Node * node = event->getCurrentTarget();
        //    Event::Type tp = event->getType();
        //    string target = node->getName();
        //    bool hit = BaseNode::hitTest(node, touch->getLocation());
        //    if (hit) CCLOG("WorldInterface_mc::onTouchBegan %s", target.c_str());
        //    return hit;
        //};
        //touchListener->onTouchEnded = [this](Touch *touch, Event *event){
        //    Node * node = event->getCurrentTarget();
        //    Event::Type tp = event->getType();
        //    string target = node->getName();
        //    CCLOG("WorldInterface_mc::onTouchEnded %s", target.c_str());
        //};

        ////EventListenerTouchOneByOne *_touchListener = EventListenerTouchOneByOne::create();
        ////CC_SAFE_RETAIN(_touchListener);
        ////_touchListener->setSwallowTouches(true);
        ////_touchListener->onTouchBegan = CC_CALLBACK_2(WorldInterface_mc::onTouchBegan, this);
        ////_touchListener->onTouchMoved = CC_CALLBACK_2(WorldInterface_mc::onTouchMoved, this);
        ////_touchListener->onTouchEnded = CC_CALLBACK_2(WorldInterface_mc::onTouchEnded, this);
        ////_touchListener->onTouchCancelled = CC_CALLBACK_2(WorldInterface_mc::onTouchCancelled, this);
        ////_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);


        //iceSphere->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, iceSphere);
        //fireSphere->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener->clone(), fireSphere);
        //stoneSphere->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener->clone(), stoneSphere);

         
        return true;


        ////左上
        //barinfoback = Sprite::create(basePath + "barinfo/barinfoback.png");
        //std::setAnchorPoint(barinfoback, 50, 500);
        //healthbar = Sprite::create(basePath + "barinfo/healthbar.png");
        //std::setAnchorPoint(healthbar, 70, 500);
        //moneybar = Sprite::create(basePath + "barinfo/moneybar.png");
        //std::setAnchorPoint(moneybar, 90, 500);

        ////左下
        //btncastback = Sprite::create(basePath + "btncastback/btncastback.png");
        //std::setAnchorPoint(btncastback, 50, 50);
        //butCastAir = Sprite::create(basePath + "btncastback/butCastAir.png");
        //std::setAnchorPoint(butCastAir, 100, 50);
        //butCastGolem = Sprite::create(basePath + "btncastback/butCastGolem.png");
        //std::setAnchorPoint(butCastGolem, 150, 50);
        //butCastIceman = Sprite::create(basePath + "btncastback/butCastIceman.png");
        //std::setAnchorPoint(butCastIceman, 200, 50);

        ////技能背景
        //sphereback = Sprite::create(basePath + "sphere/backsphere.png");
        //std::setAnchorPoint(sphereback, 250, 550);
        //iceBack = Sprite::create(basePath + "sphere/iceBack.png");
        //std::setAnchorPoint(iceBack, 250, 550);
        //fireBack = Sprite::create(basePath + "sphere/fireBack.png");
        //std::setAnchorPoint(fireBack, 300, 550);
        //levinBack = Sprite::create(basePath + "sphere/levinBack.png");
        //std::setAnchorPoint(levinBack, 350, 550);
        //stoneBack = Sprite::create(basePath + "sphere/stoneBack.png");
        //std::setAnchorPoint(stoneBack, 400, 550);
        //allSphere = Sprite::create(basePath + "sphere/allsphereback.png");
        //std::setAnchorPoint(allSphere, 450, 550);

        ////购买价格背景
        //buyFire = Sprite::create(basePath + "sphere/buypricebar.png");
        //std::setAnchorPoint(buyFire, 250, 500);
        //buyIce = Sprite::create(basePath + "sphere/buypricebar.png");
        //std::setAnchorPoint(buyIce, 300, 500);
        //buyLevin = Sprite::create(basePath + "sphere/buypricebar.png");
        //std::setAnchorPoint(buyLevin, 350, 500);
        //buyStone = Sprite::create(basePath + "sphere/buypricebar.png");
        //std::setAnchorPoint(buyStone, 400, 500);
        //buyGetAll = Sprite::create(basePath + "sphere/buypricebar.png");
        //std::setAnchorPoint(buyGetAll, 450, 500);

        ////图片代替动画
        //iceSphere = Sprite::create(basePath + "sphere/iceSphere.png");
        //std::setAnchorPoint(iceSphere, 250, 560);;
        //fireSphere = Sprite::create(basePath + "sphere/fireSphere.png");
        //std::setAnchorPoint(fireSphere, 300, 560);
        //levinSphere = Sprite::create(basePath + "sphere/levinSphere.png");
        //std::setAnchorPoint(levinSphere, 350, 560);
        //stoneSphere = Sprite::create(basePath + "sphere/stoneSphere.png");
        //std::setAnchorPoint(stoneSphere, 400, 560);


        //pause = Button::create(basePath + "startbtn/pause.png", basePath + "startbtn/paused.png");
        //startbtnback = Sprite::create(basePath + "startbtn/startbtnback.png");
        //std::setAnchorPoint(startbtnback, 510, 0);
        //this->addChild(startbtnback); 
        //this->fastbtn = Button::create(basePath + "startbtn/fasterbtn.png", basePath + "startbtn/fastbtned.png");
        //startWaves = Button::create(basePath + "startbtn/startWavesoff.png", basePath + "startbtn/startWaveson.png");
        //startbtnback->addChild(fastbtn);
        //startbtnback->addChild(startWaves);
        //std::setAnchorPoint(fastbtn, 96, 22); 
        //std::setAnchorPoint(startWaves, 145, 15);


        //startWaves->setPressedActionEnabled(true);
        ////startWaves->addTouchEventListener(this, toucheventselector(PlayState::btnPlayAction));
        ////addChild(startWaves, 10000);
        //this->autorelease();
        //return true;
    }
        
    void WorldInterface_mc::startWavesCallback(Ref* ref){
        ui::Button * node = (ui::Button *)ref;
        string target = node->getName();
        CCLOG("startWavesCallback %s", target.c_str());
        int a = 0;
    }
}
