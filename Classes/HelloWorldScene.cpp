#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
//cocos2dx
#include "dragonbones/cocos2d/DBCCRenderHeaders.h"
USING_NS_CC;
USING_NS_DB;

using namespace cocos2d::ui;
using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	auto sprite = Sprite::create("level1.png");
	sprite->setPositionX(400);
	sprite->setPositionY(300);
	cocos2d::TextFieldTTF txt;
	txt.setPositionX(400);
	txt.setPositionY(400);
	txt.setString("name");
	addChild(sprite, 0);
	addChild(&txt, 1, "name");
	DBCCFactory::getInstance()->loadDragonBonesData("icefreeze/skeleton.xml", "icefreeze");
	DBCCFactory::getInstance()->loadTextureAtlas("icefreeze/texture.xml", "icefreeze");
	auto hero = DBCCFactory::getInstance()->buildArmatureNode("icefreeze");
	addChild(hero,1);
	hero->setPositionX(400);
	hero->setPositionY(300);
	hero->getAnimation()->gotoAndPlay("icemandead");
	//cocos2d::Sprite *uiButton;
	//cocos2d::Touch t; cocos2d::Event e; e.getType();

	cocos2d::ui::Button* btnPlay = cocos2d::ui::Button::create("fight/controler/hit.png", "fight/controler/hit.png");
	btnPlay->setPosition(Vec2(100, 90));
	btnPlay->setPressedActionEnabled(true); 
	btnPlay->addTouchEventListener(this, toucheventselector(HelloWorld::touchButton));
	addChild(btnPlay, 10000);

	

	//hero->getAnimation()->gotoAndPlay("icemanlive");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	//����Ļ����ʾָ���Ű�
	Sprite *mouse = Sprite::create("mouse.png");
	mouse->setScale(0.3f);
	this->addChild(mouse);

	auto myKeyListener = EventListenerKeyboard::create(); //�����¼����������������¼�
	//���̰�������ʱ����Ӧ
	myKeyListener->onKeyPressed = [](EventKeyboard::KeyCode keycode, cocos2d::Event *event)
	{
		CCLOG("key is pressed, keycode is %d", keycode);
	};

	//���̰�������ʱ����Ӧ
	myKeyListener->onKeyReleased = [](EventKeyboard::KeyCode keycode, cocos2d::Event *event)
	{
		CCLOG("key is released, keycode is %d", keycode);
	};
	auto myMouseListener = EventListenerMouse::create();//�����¼�����������¼�
	//����ƶ�
	myMouseListener->onMouseMove = [=](Event *event)
	{
		EventMouse* e = (EventMouse*)event;
	    mouse->setPosition(e->getCursorX(), e->getCursorY() + visibleSize.height);
	};
	//��걻����
	myMouseListener->onMouseDown = [=](Event *event)
	{
		 mouse->setScale(0.2f); //��갴�����£���Ļ�ϵġ���ͷ���ߴ���С
	};
	//��갴������
	myMouseListener->onMouseUp = [=](Event *event)
	{
		 mouse->setScale(0.3f); //��갴��̧����Ļ�ϵġ���ͷ���ߴ�Ŵ�
	};

	//���¼��������볡����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);

    return true;
}
using namespace cocos2d::ui;
void HelloWorld::touchButton(cocos2d::Ref * object,cocos2d::ui::TouchEventType type)
{
	LabelTTF* label;
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		label = static_cast<LabelTTF*>(getChildByTag(11));
		label->setString("���°�ť");
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		label = static_cast<LabelTTF*>(getChildByTag(11));
		label->setString("���°�ť�ƶ�");
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		label = static_cast<LabelTTF*>(getChildByTag(11));
		label->setString("�ſ���ť");
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		label = static_cast<LabelTTF*>(getChildByTag(11));
		label->setString("ȡ�����");
		break;
	default:
		break;
	}
}