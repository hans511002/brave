#include "BaseNode.h"
#include "MainClass.h"

using namespace cocos2d;
const double BaseNode::AnimationInterval = 1.0f / (double)Main::FrameRate;

namespace std
{
    Common::Log * gLog = new Common::Log("brave");
    //Common::Log * gLog = NULL;

    void writeLog(string msg, int type)
    {
        if (gLog)Common::writeLog(msg, gLog, BaseFuns::debug, type);
    };
    void setAnchorPoint(Node* node, bool subset)
    {
        node->setAnchorPoint(Vec2(0, 0));
        if (subset)
        {
            cocos2d::Vector<Node * > chlds = node->getChildren();
            for (size_t i = 0; i < chlds.size(); i++)
            {
                std::setAnchorPoint(chlds.at(i), subset);
            }
        }
    };
    void setAnchorPoint(cocos2d::Node* node, float x, float y, bool subset)
    {
        node->setAnchorPoint(Vec2(x, y));
        if (subset)
        {
            cocos2d::Vector<Node * > chlds = node->getChildren();
            for (size_t i = 0; i < chlds.size(); i++)
            {
                std::setAnchorPoint(chlds.at(i), x, y, subset);
            }
        }
    };
    void setAnchorPoint(cocos2d::Node* node, const cocos2d::Vec2 & pos, bool subset)
    {
        node->setAnchorPoint(pos);
        if (subset)
        {
            cocos2d::Vector<Node * > chlds = node->getChildren();
            for (size_t i = 0; i < chlds.size(); i++)
            {
                std::setAnchorPoint(chlds.at(i), pos, subset);
            }
        }
    };
    dragonBones::CCArmatureDisplay * loadArmature(string rootPath, string armatureName, const string& dragonBonesName)
    {
        //dragonBones::DBCCFactory::getInstance()->loadDragonBonesData(rootPath + aniName + "/skeleton.xml", aniName);
        //dragonBones::DBCCFactory::getInstance()->loadTextureAtlas(rootPath + aniName + "/texture.xml", aniName);
        //return dragonBones::DBCCFactory::getInstance()->buildArmatureNode(aniName);
        if (!rootPath.empty() && rootPath.at(rootPath.length() - 1) != '/')
        {
            rootPath += "/";
        }
        string dbName = dragonBonesName == "" ? armatureName : dragonBonesName;
        const auto factory = dragonBones::CCFactory::getFactory();
        factory->loadDragonBonesData(rootPath + dbName + "/" + dbName + "_ske.json", dbName);
        //factory->loadDragonBonesData(rootPath + armatureName + "/" + armatureName + "_ske.dbbin");
        factory->loadTextureAtlasData(rootPath + dbName + "/" + dbName + "_tex.json", dbName);
        //const std::string& armatureName, const std::string& dragonBonesName = "", const std::string& skinName = "", const std::string& textureAtlasName = ""
        const auto armatureDisplay = factory->buildArmatureDisplay(armatureName, dbName);
        //scene->addChild(armatureDisplay);
        ////std::string name = armatureDisplay->getArmature()->getSlot("handL")->getName();
        //armatureDisplay->getAnimation()->play("icemandead", 999999);
        //armatureDisplay->setAnchorPoint(cocos2d::Vec2(0, 0));
        ////std::setAnchorPoint(armatureDisplay,0,0);
        //armatureDisplay->setPosition(200.0f, 200.0f);
        //armatureDisplay->setVisible(true);
        return armatureDisplay;
    };
    dragonBones::CCArmatureDisplay * buildArmature(string armatureName, const string& dragonBonesName)
    {
        const auto factory = dragonBones::CCFactory::getFactory();
        return   factory->buildArmatureDisplay(armatureName, dragonBonesName);
    };
    string setText(ui::Text * tui, string val)
    {
        string old = tui->getString();
        tui->setString(val);
        return old;
    };
    int setText(ui::Text * tui, int val)
    {
        string old = tui->getString();
        char tmp[12];
        sprintf(tmp, "%d", val);
        tui->setText(tmp);
        return atoi(old.c_str());
    };
    float setText(ui::Text * tui, float val)
    {
        string old = tui->getString();
        char tmp[15];
        sprintf(tmp, "%0.2f", val);
        tui->setText(tmp);
        return atof(old.c_str());
    };
    int getInt(ui::Text * tui)
    {
        string old = tui->getString();
        return atoi(old.c_str());
    };
    string getText(ui::Text * tui)
    {
        return tui->getString();
    };
}
bool BaseNode::init()
{
    cocos2d::Node::init();
    std::setAnchorPoint(this);
    return true;
};
bool BaseSprite::init()
{
    this->autorelease();
    std::setAnchorPoint(this);
    return true;
};
BaseSprite::BaseSprite(string file)
{
    this->initWithFile(file);
    init();
}

bool BaseNode::hitTest(const Vec2 &pt)
{
    if (!mouseEnabled)return false;
    return BaseNode::hitTest(this, pt);
};
bool BaseNode::hitTest(cocos2d::EventMouse* event)
{
    if (!mouseEnabled)return false;
    return BaseNode::hitTest(this, event);
};

cocos2d::Point BaseNode::localToGlobal(cocos2d::Point pt)
{
    return this->convertToWorldSpace(pt);
};

void BaseNode::onEnter()
{
    Node::onEnter();
    if (schdt)
    {
        this->schedule(schedule_selector(BaseNode::scheduleUpdate), AnimationInterval);
    }
};
void BaseNode::onExit()
{
    cleanup();
    Node::onExit();
};
void BaseNode::cleanup()
{
    if (schdt)
    {
        this->unschedule(schedule_selector(BaseNode::scheduleUpdate));
    }
    Node::cleanup();
};
void BaseNode::scheduleUpdate(float dt)
{
    enterFrameHandler(dt);
};
void BaseNode::enterFrameHandler(float dt)
{
};


void BaseSprite::mouseDownHandler(cocos2d::Event *event)//(event:MouseEvent) : void
{
    Node * node = event->getCurrentTarget();
    Event::Type tp = event->getType();
    string target = node->getName();
    CCLOG("BaseSprite::mouseDownHandler %s", target.c_str());
}
void BaseLayer::mouseDownHandler(cocos2d::Event *event)//(event:MouseEvent) : void
{
    Node * node = event->getCurrentTarget();
    Event::Type tp = event->getType();
    string target = node->getName();
    CCLOG("BaseLayer::mouseDownHandler %s", target.c_str());
}

bool BaseLayer::init()
{
    if (!LayerColor::initWithColor(cocos2d::Color4B(105, 105, 105, 255)))
    {
        return false;
    }
    const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
    setPosition(0, 0);
    //setPosition(stageSize.width * 0.5f, stageSize.height * 0.5f);
    //_background = cocos2d::Sprite::create("background.png");
    //addChild(_background);
    _onStart();
    return true;
}

cocos2d::Label* BaseFuns::createText(const std::string& string)
{
    const auto text = cocos2d::Label::create();
    text->setPosition(0.0f, -(getStageHeight() * 0.5f - 100.f));
    text->setString(string);
    text->setAlignment(cocos2d::TextHAlignment::CENTER);
    //addChild(text);
    return text;
}

float  BaseFuns::getStageWidth() const
{
    const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
    return stageSize.width;
}

float  BaseFuns::getStageHeight() const
{
    const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
    return stageSize.height;
}
dragonBones::CCArmatureDisplay * BaseFuns::loadArmature(string rootPath, string armatureName, const string& dragonBonesName)
{
    return std::loadArmature(rootPath, armatureName, dragonBonesName);
};
dragonBones::CCArmatureDisplay * BaseFuns::buildArmature(string armatureName, const string& dragonBonesName)
{
    return std::buildArmature(armatureName, dragonBonesName);
};

bool BaseNode::hitTest(Node * node, const Vec2 &pt)
{
    Vec2 nsp = node->convertToNodeSpace(pt);//convertToNodeSpace convertToNodeSpaceAR
    Rect bb;
    bb.size = node->getContentSize();
    if (bb.size.height == 0 || bb.size.width == 0)
    {
        if (node->getChildrenCount())
        {
            cocos2d::Vector<Node*> cld = node->getChildren();
            for each (Node *n in cld)
            {
                Size t = (n->getContentSize() - bb.size);
                if (t.width > 0 && t.height > 0)
                    bb.size = n->getContentSize();
            }
        }
    }
    if (bb.containsPoint(nsp))
    {
        return true;
    }
    return false;
}
bool BaseNode::hitTest(cocos2d::Node * node, cocos2d::EventMouse* e)
{
    return hitTest(node, e->getLocationInView());
};


bool BaseSprite::atStage()
{
    const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
    Vec2 p = this->getPosition();
    p = this->convertToWorldSpace(p);
    return !(p.x < 0 || p.y<0 || p.x > stageSize.width || p.y > stageSize.height);
}
bool BaseNode::atStage()
{
    const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
    Vec2 p = this->getPosition();
    p = this->convertToWorldSpace(p);
    // p = this->convertToNodeSpace(p);
    return !(p.x < 0 || p.y<0 || p.x > stageSize.width || p.y > stageSize.height);
}

void BaseNode::setOpacity(float op)
{
    int ops = op * 255;
    if (ops > 255)ops = 255;
    Node::setOpacity(ops);
};
float BaseNode::getOpacity()
{
    int ops = Node::getOpacity();
    return (double)ops / 255;
};

BaseNode::BaseNode(float w, float h, bool draw)
{
    this->setContentSize(Size(w, h));
    enableMouseHandler();
    if (draw)drawRange();
};
void BaseNode::setSize(float w, float h, bool draw)
{
    this->setContentSize(Size(w, h));
    if (draw)drawRange();
}
void BaseNode::drawRange()
{
    DrawNode* drawNode = DrawNode::create();
    this->addChild(drawNode);
    Vec2 pos = this->getPosition();
    Size size = this->getContentSize();
    Vec2 dest(pos.x + size.width, pos.y + size.height);
    drawNode->drawRect(pos, dest, Color4F::GREEN);
    drawNode->setScaleX(this->getScaleX());
    drawNode->setScaleY(this->getScaleY());
};

std::MouseEvent::MouseEvent(MouseEventType mouseEventCode) : cocos2d::EventMouse(mouseEventCode)
{
};
inline void std::MouseEvent::setCurrentTarget(Node* target)
{
    cocos2d::EventMouse::setCurrentTarget(target);
};
std::MouseEvent* BaseNode::buildMousrEvent(Node * node, int mouseButton)
{
    std::MouseEvent* e = new std::MouseEvent(cocos2d::EventMouse::MouseEventType::MOUSE_DOWN);
    e->setMouseButton(mouseButton);
    e->getCurrentTarget();
    //setCurrentTarget
    if (node)
    {
        Vec2 pos = node->convertToWorldSpace(node->getPosition());
        e->setCursorPosition(pos.x, pos.y);
    }
    else
    {
        Vec2 pos = this->convertToWorldSpace(this->getPosition());
        e->setCursorPosition(pos.x, pos.y);
    }
    return e;
}
void BaseNode::enableMouseHandler()
{
    if (!this->mouseEnabled)this->mouseEnabled = true;
    const auto listener = cocos2d::EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(BaseNode::mouseDownHandler, this);
    listener->onMouseUp = CC_CALLBACK_1(BaseNode::mouseUpHandler, this);
    listener->onMouseMove = CC_CALLBACK_1(BaseNode::mouseMovedHandler, this);
    listener->onMouseScroll = CC_CALLBACK_1(BaseNode::mouseScrollHandler, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
};
void BaseNode::enableKeyHandler()
{
    const auto keyboardListener = cocos2d::EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(BaseNode::keyBoardPressedHandler, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(BaseNode::keyBoardReleasedHandler, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}
void BaseNode::keyBoardPressedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    logInfo("keyBoardPressed keyCode", (int)keyCode);
    switch (keyCode)
    {
    case cocos2d::EventKeyboard::KeyCode::KEY_A:
    case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        //_left = true;
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_D:
    case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        //_right = true;
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_W:
    case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
        //->jump();
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_S:
    case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        //->squat(true);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_Q:
        //->switchWeaponR();
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_E:
        //->switchWeaponL();
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
        //->switchSkin();
        break;
    }

};
void BaseNode::keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    logInfo("keyBoardReleased keyCode", (int)keyCode);
    switch (keyCode)
    {
    case cocos2d::EventKeyboard::KeyCode::KEY_A:
    case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        //_left = false;		 
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_D:
    case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        //_right = false; 
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_W:
    case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_S:
    case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        //_player->squat(false);
        break;
    }
};
void BaseNode::mouseDownHandler(cocos2d::EventMouse* event)
{

    //loginfo("mouseDown",event); 
    if (!this->hitTest(event))return;
    logInfo("hitTest true : mouse in ", this->getName());
    Node * node = event->getCurrentTarget();
    string name = node->getName();
    while (node->getParent())
    {
        node = node->getParent();
        name = node->getName() + "." + name;
    }
    logInfo("event targetNamePath", name);

    int mouseButton = event->getMouseButton();
    if (mouseButton == 1)
        rightMouseDownHandler(event);
};
void BaseNode::mouseUpHandler(cocos2d::EventMouse* event)
{
    if (!this->hitTest(event))return;
    int mouseButton = event->getMouseButton();
    //loginfo("mouseUp", event);
    if (mouseButton == 1)rightMouseUpHandler(event);
};
void BaseNode::mouseMovedHandler(cocos2d::EventMouse* event)
{
    if (!this->hitTest(event))return;
    //logInfo("mouseMoved", event->getCursorX(), event->getCursorY());
};
void BaseNode::mouseScrollHandler(cocos2d::EventMouse* event)
{
    if (!this->hitTest(event))return;
};
void BaseNode::rightMouseDownHandler(cocos2d::EventMouse* event)
{
};
void BaseNode::rightMouseUpHandler(cocos2d::EventMouse* event)
{
};
void BaseNode::touchAction(cocos2d::Ref *ref, cocos2d::ui::TouchEventType type)
{
    Node * node = (Node *)ref;
    string target = node->getName();
    CCLOG("touchAction %s type=%i", target.c_str(), type);
};

void BaseFuns::loginfo(string mouseType, cocos2d::EventMouse* event)
{
    if (!BaseFuns::debug)return;
    int mouseButton = event->getMouseButton();
    logInfo(mouseType, event->getCursorX(), event->getCursorY());
    logInfo("         mouseButton", mouseButton);

    Node * node = event->getCurrentTarget();
    Event::Type tp = event->getType();
    string target = node->getName();
    logInfo("         node->getPosition()", node->getPosition());
    logInfo("         target", target);


    cocos2d::Point pt = event->getLocationInView();
    logInfo("         event getLocation", event->getLocation());
    logInfo("         event getLocationInView", pt);
    cocos2d::Point  nsp = node->convertToNodeSpaceAR(pt);
    logInfo("         event convertToNodeSpaceAR", nsp);
    nsp = node->convertToNodeSpace(pt);
    logInfo("         event convertToNodeSpace", nsp);

    Rect bb;
    bb.size = node->getContentSize();
    logInfo("         getContentSize", bb.size);
    if (bb.containsPoint(nsp))
    {
        logInfo("         nsp in bb", bb.size);

    }
};
bool BaseFuns::debug = true;
void BaseFuns::logInfo(string label, cocos2d::Point pos)
{
    if (!BaseFuns::debug)return;
    CCLOG("%s x=%f y=%f", label.c_str(), pos.x, pos.y);
    if (gLog)writeLog(label + " x=" + Common::String(pos.x) + " y=" + Common::String(pos.y), 1);
};
void BaseFuns::logInfo(string label, cocos2d::Size pos)
{
    if (!BaseFuns::debug)return;
    CCLOG("%s w=%f h=%f", label.c_str(), pos.width, pos.height);
    if (gLog)writeLog(label + " w=" + Common::String(pos.width) + " h=" + Common::String(pos.height), 1);
};
void BaseFuns::logInfo(string label, float x, float y)
{
    if (!BaseFuns::debug)return;
    CCLOG("%s x=%f y=%f", label.c_str(), x, y);
    if (gLog)writeLog(label + " x=" + Common::String(x) + " y=" + Common::String(y), 1);
};
void BaseFuns::logInfo(string label, int x)
{
    if (!BaseFuns::debug)return;
    CCLOG("%s=%d ", label.c_str(), x);
    if (gLog)writeLog(label + "=" + Common::String(x), 1);
};
void BaseFuns::logInfo(string label, int x, int y)
{
    if (!BaseFuns::debug)return;
    CCLOG("%s[%d , %d]", label.c_str(), x, y);
    if (gLog)writeLog(label + " x=" + Common::String(x) + " y=" + Common::String(y), 1);
};
void BaseFuns::logInfo(string label1, string label2, string label3, string label4, string label5, string label6)
{
    if (!BaseFuns::debug)return;
    string msg = label1;
    if (!label2.empty())
        msg += "=" + label2;
    if (!label3.empty() && !label4.empty())
        msg += label3 + "=" + label4;
    if (!label5.empty() && !label6.empty())
        msg += label5 + "=" + label6;
    CCLOG(msg.c_str());
    if (gLog)writeLog(msg, 1);
};

