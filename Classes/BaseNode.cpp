#include "BaseNode.h"
#include "MainClass.h"

using namespace cocos2d;
namespace std
{
	void setAnchorPoint(Node* node,bool subset)
	{
		node->setAnchorPoint(Vec2(0, 0));
		if(subset)
		{
			cocos2d::Vector<Node * > chlds = node->getChildren();
			for(size_t i = 0; i < chlds.size(); i++)
			{
                std::setAnchorPoint(chlds.at(i), subset);
			}
		}
	};
    void setAnchorPoint(cocos2d::Node* node, float x, float y){
        node->setAnchorPoint(Vec2(0, 0));
        node->setPosition(Vec2(x, y));
    };
    void setAnchorPoint(cocos2d::Node* node, const cocos2d::Vec2 & pos){
        node->setAnchorPoint(Vec2(0, 0));
        node->setPosition(pos);
    };
    dragonBones::CCArmatureDisplay * loadArmature(string rootPath, string armatureName, const string& dragonBonesName){
        //dragonBones::DBCCFactory::getInstance()->loadDragonBonesData(rootPath + aniName + "/skeleton.xml", aniName);
        //dragonBones::DBCCFactory::getInstance()->loadTextureAtlas(rootPath + aniName + "/texture.xml", aniName);
        //return dragonBones::DBCCFactory::getInstance()->buildArmatureNode(aniName);
		if(!rootPath.empty() && rootPath.at(rootPath.length() - 1) != '/')
		{
			rootPath += "/";
		}
		string dbName = dragonBonesName == "" ? armatureName : dragonBonesName;
        const auto factory = dragonBones::CCFactory::getFactory();
		factory->loadDragonBonesData(rootPath + dbName + "/" + dbName + "_ske.json");
        //factory->loadDragonBonesData(rootPath + armatureName + "/" + armatureName + "_ske.dbbin");
		factory->loadTextureAtlasData(rootPath + dbName + "/" + dbName + "_tex.json");
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
}
bool BaseNode::init() {
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
BaseSprite::BaseSprite(string file){
    this->initWithFile(file);
    init();
}

bool BaseNode::hitTest(const Vec2 &pt){
    return BaseNode::hitTest(this, pt);
};
cocos2d::Point BaseNode::localToGlobal(cocos2d::Point pt)
{
	return this->convertToWorldSpace(pt);
};

void BaseNode::onEnter()
{
    if(schdt){
        this->schedule(schedule_selector(BaseNode::scheduleUpdate),Main::AnimationInterval);
    }
};
void BaseNode::onExit()
{
    cleanup();
};
void BaseNode::cleanup()
{
    if(schdt){
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

void BaseNode::touchAction(cocos2d::Ref *ref, cocos2d::ui::TouchEventType type){
    Node * node = (Node *)ref;
    string target = node->getName();
    CCLOG("touchAction %s type=%i", target.c_str(),type);
};

void BaseNode::mouseDownHandler(cocos2d::Event *event)//(event:MouseEvent) : void
{
    Node * node = event->getCurrentTarget();
    Event::Type tp = event->getType();
    string target = node->getName();
    CCLOG("BaseNode::mouseDownHandler %s", target.c_str());
}
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
	if(!LayerColor::initWithColor(cocos2d::Color4B(105, 105, 105, 255)))
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
  dragonBones::CCArmatureDisplay * BaseFuns::loadArmature(string rootPath, string armatureName, const string& dragonBonesName){
      return std::loadArmature(rootPath, armatureName, dragonBonesName);
  };

  bool BaseNode::hitTest(Node * node, const Vec2 &pt)
  {
	  Vec2 nsp = node->convertToNodeSpace(pt);//convertToNodeSpace convertToNodeSpaceAR
      Rect bb;
      bb.size = node->getContentSize();
	  if(bb.size.height == 0 || bb.size.width == 0)
	  {
		  if(node->getChildrenCount())
		  {
			  cocos2d::Vector<Node*> cld = node->getChildren();
			  for each (Node *n in cld)
			  {
				  Size t = (n->getContentSize() - bb.size);
				  if(t.width>0 || t.height>0)
				  {
					bb.size = n->getContentSize();
				  }
			  }
		  }
	  }
      if (bb.containsPoint(nsp))
      {
          return true;
      }
      return false;
  }
  bool BaseNode::hitTest(cocos2d::Node * node, cocos2d::EventMouse* e){
      return hitTest(node, e->getLocationInView());
  };


  bool BaseSprite::atStage()
  {
    const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
    Vec2 p = this->getPosition();
    return p.x < 0 || p.y<0 || p.x > stageSize.width || p.y > stageSize.height;
}
  bool BaseNode::atStage()
  {
    const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
    Vec2 p = this->getPosition();
    return p.x < 0 || p.y<0 || p.x > stageSize.width || p.y > stageSize.height;
}


void BaseNode::setOpacity(float op)
{
    int ops=op*255;
    if(ops>255)ops=255;
    Node::setOpacity(ops);
};
float BaseNode::getOpacity(){
    int ops=Node::getOpacity();
    return (double)ops/255;
};
