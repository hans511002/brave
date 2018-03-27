#include "BaseNode.h"

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
				std::setAnchorPoint(chlds.at(i));
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
    }
}
bool BaseNode::init() {
    cocos2d::Node::init();
	std::setAnchorPoint(this);
	return true;
}; 
bool BaseSprite::init()
{
    cocos2d::Sprite::init();
	std::setAnchorPoint(this);
	return true;
};
bool BaseNode::hitTest(const Vec2 &pt){
    return BaseNode::hitTest(this, pt);
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
  dragonBones::DBCCArmatureNode * BaseFuns::loadAni(string rootPath,string aniName){
      dragonBones::DBCCFactory::getInstance()->loadDragonBonesData(rootPath + aniName + "/skeleton.xml", aniName);
      dragonBones::DBCCFactory::getInstance()->loadTextureAtlas(rootPath + aniName + "/texture.xml", aniName);
      return dragonBones::DBCCFactory::getInstance()->buildArmatureNode(aniName);
  };

  bool BaseNode::hitTest(Node * node, const Vec2 &pt)
  {
      Vec2 nsp = node->convertToNodeSpaceAR(pt);//convertToNodeSpace
      Rect bb;
      bb.size = node->getContentSize();
      if (bb.containsPoint(nsp))
      {
          return true;
      }
      return false;
  }


bool BaseSprite::Atstage(){
    const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
    Vec2 p = this->getPosition();
    return p.x < 0 || p.y<0 || p.x > stageSize.width || p.y > stageSize.height;
}
bool BaseNode::Atstage(){
    const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
    Vec2 p = this->getPosition();
    return p.x < 0 || p.y<0 || p.x > stageSize.width || p.y > stageSize.height;
}

