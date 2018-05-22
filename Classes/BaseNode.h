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
	void setAnchorPoint(cocos2d::Node* node, float x, float y, bool subset = false);
	void setAnchorPoint(cocos2d::Node* node, const cocos2d::Vec2 & pos, bool subset = false);
    dragonBones::CCArmatureDisplay * loadArmature(string rootPath, string armatureName, const string& dragonBonesName = "");
    dragonBones::CCArmatureDisplay * buildArmature(string armatureName, const string& dragonBonesName);
    string setText(ui::Text * tui,string val); 
    int setText(ui::Text * tui,int val); 
    float setText(ui::Text * tui,float val); 
    int getInt(ui::Text * tui);
    string getText(ui::Text * tui);
}

class BaseFuns
{
	public:
	cocos2d::Label* createText(const std::string& string);
	float getStageWidth() const;
	float getStageHeight() const;
    dragonBones::CCArmatureDisplay * loadArmature(string rootPath, string armatureName, const string& dragonBonesName = "");
    dragonBones::CCArmatureDisplay * buildArmature(string armatureName, const string& dragonBonesName);
    inline string setText(ui::Text * tui,string val){return std::setText(tui,val);}; 
    inline int setText(ui::Text * tui,int val){return std::setText(tui,val);}; 
    inline float setText(ui::Text * tui,float val){return std::setText(tui,val);}; 
};


class BaseNode :public   cocos2d::Node, public   BaseFuns
{
    bool schdt;
public:
    static const double AnimationInterval;

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
	
	virtual void setOpacity(float);
	virtual float getOpacity();
	
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

class CaseNode : public BaseNode{
public:
    CaseNode(float w, float h);
};
#endif

