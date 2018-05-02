#ifndef BASE_NODE_SPRITE_H
#define BASE_NODE_SPRITE_H
#include "cocos2d.h"
#include "dragonBones/cocos2dx/CCDragonBonesHeaders.h"
#include "common/Common.h"
#include "JsonUtil.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;

namespace std {
    void setAnchorPoint(cocos2d::Node* node, bool subset = false);
    void setAnchorPoint(cocos2d::Node* node, float x, float y);
    void setAnchorPoint(cocos2d::Node* node,const cocos2d::Vec2 & pos);
    dragonBones::CCArmatureDisplay * loadArmature(string rootPath, string armatureName, const string& dragonBonesName = "");
}

class BaseFuns
{
	public:
	cocos2d::Label* createText(const std::string& string);
	float getStageWidth() const;
	float getStageHeight() const;
    dragonBones::CCArmatureDisplay * loadArmature(string rootPath, string armatureName, const string& dragonBonesName = "");
};


class BaseNode :public   cocos2d::Node, public   BaseFuns
{
    bool schdt;
public:
    BaseNode():schdt(false){};
	bool init();
	bool atStage();
	void mouseDownHandler(cocos2d::Event *event);
	void touchAction(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
	bool hitTest(const Vec2 &pt);
	bool mouseChildren;
	bool mouseEnabled;
	cocos2d::Point localToGlobal(cocos2d::Point pt);

    virtual void onEnter();
    virtual void onExit();
    virtual void cleanup();
	virtual void scheduleUpdate(float dt);
	virtual void enterFrameHandler(float dt);
	
	static bool hitTest(cocos2d::Node * node, const Vec2 &pt);
	static bool hitTest(cocos2d::Node * node, cocos2d::EventMouse* e);
protected:
    
};
class BaseSprite :public   cocos2d::Sprite, public   BaseFuns
{
public:
	bool init();
	bool atStage();
    void mouseDownHandler(cocos2d::Event *event);
    BaseSprite(string file);
//    BaseSprite(){};
    static Sprite* create();
private:

};
class BaseLayer : public   cocos2d::LayerColor, public   BaseFuns
{
protected:
	cocos2d::Sprite* _background;
	virtual void _onStart() = 0;
    void mouseDownHandler(cocos2d::Event *event);
public:
	BaseLayer() :_background(nullptr)
	{
		std::setAnchorPoint((Node*)this);
	}

	virtual bool init();

	//cocos2d::Label* createText(const std::string& string);

	//float getStageWidth() const;
	//float getStageHeight() const;
};

#endif

