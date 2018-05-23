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

	extern Common::Log gLog;//全局日志记录对象
	 void writeLog(string msg, int type)  ;

}

class BaseFuns
{
	public:
	static bool debug;
	cocos2d::Label* createText(const std::string& string);
	float getStageWidth() const;
	float getStageHeight() const;
    dragonBones::CCArmatureDisplay * loadArmature(string rootPath, string armatureName, const string& dragonBonesName = "");
    dragonBones::CCArmatureDisplay * buildArmature(string armatureName, const string& dragonBonesName);
    inline string setText(ui::Text * tui,string val){return std::setText(tui,val);}; 
    inline int setText(ui::Text * tui,int val){return std::setText(tui,val);}; 
    inline float setText(ui::Text * tui,float val){return std::setText(tui,val);}; 
	inline void logInfo(string label,cocos2d::Point pos)
	{
		if(!BaseFuns::debug)return;
		CCLOG("%s x=%f y=%f", label.c_str(), pos.x, pos.y);
		writeLog(label+" x="+Common::String(pos.x)+" y="+Common::String(pos.y), 1);
	};
	inline void logInfo(string label, cocos2d::Size pos )
	{
		if(!BaseFuns::debug)return;
		CCLOG("%s w=%f h=%f", label.c_str(), pos.width, pos.height);
		writeLog(label + " w=" + Common::String(pos.width) + " h=" + Common::String(pos.height), 1);
	};
	inline void logInfo(string label ,float x, float y = 0)
	{
		if(!BaseFuns::debug)return;
		CCLOG("%s x=%f y=%f", label.c_str(), x, y);
		writeLog(label + " x=" + Common::String(x) + " y=" + Common::String(y), 1);
	};
	inline void logInfo(string label, int x)
	{
		if(!BaseFuns::debug)return;
		CCLOG("%s=%d ", label.c_str(), x);
		writeLog(label + "=" + Common::String(x)  , 1);
	};
	inline void logInfo(string label, int x, int y )
	{
		if(!BaseFuns::debug)return;
		CCLOG("%s[%d , %d]", label.c_str(), x, y);
		writeLog(label + " x=" + Common::String(x) + " y=" + Common::String(y), 1);
	};
	inline void logInfo(string label1 , string label2 = "", string label3 = "", string label4 = "", string label5 = "", string label6 = "")
	{
		if(!BaseFuns::debug)return;
		string msg = label1;
		if(!label2.empty())
			msg += "=" + label2;
		if(!label3.empty() && !label4.empty())
			msg += label3+"=" + label4;
		if(!label5.empty() && !label6.empty())
			msg += label5 + "=" + label6;
		CCLOG(msg.c_str());
		writeLog(msg , 1);
	};
	#define LOGINFO(format, ...)      cocos2d::log(format, ##__VA_ARGS__)
	void loginfo(string mouseType, cocos2d::EventMouse* event);
};

class BaseNode :public   cocos2d::Node, public   BaseFuns
{
    bool schdt;
public:
    static const double AnimationInterval;

	BaseNode() :schdt(false), mouseEnabled(false), mouseChildren(false) {};
	bool init();
	bool atStage();
 	void touchAction(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
	virtual bool hitTest(const Vec2 &pt);
	virtual bool hitTest(cocos2d::EventMouse* event);
	bool mouseChildren;
	bool mouseEnabled;
	cocos2d::Point localToGlobal(cocos2d::Point pt);

    virtual void onEnter();
    virtual void onExit();
    virtual void cleanup();
	virtual void scheduleUpdate(float dt);
	//帧频事件
	virtual void enterFrameHandler(float dt);
	
	virtual void setOpacity(float);
	virtual float getOpacity();
	
	BaseNode(float w, float h, bool draw = false);
	virtual void setSize(float w, float h, bool draw = false);
	virtual void drawRange();
	void enableMouseHandler();
	void enableKeyHandler();
	//鼠标键盘事件
	virtual void keyBoardPressedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void mouseDownHandler(cocos2d::EventMouse* event);
	virtual void mouseUpHandler(cocos2d::EventMouse* event);
	virtual void mouseMovedHandler(cocos2d::EventMouse* event);
	virtual void mouseScrollHandler(cocos2d::EventMouse* event);
	virtual void rightMouseDownHandler(cocos2d::EventMouse* event);
	virtual void rightMouseUpHandler(cocos2d::EventMouse* event);
	 
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

//class CaseNode : public BaseNode{
//public:
//    CaseNode(float w, float h);
//	void enableKeyHandler();
// 	virtual void keyBoardPressedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
//	virtual void keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
//	virtual void mouseDownHandler(cocos2d::EventMouse* event);
//	virtual void mouseUpHandler(cocos2d::EventMouse* event);
//	virtual void mouseMovedHandler(cocos2d::EventMouse* event);
//	virtual void mouseScrollHandler(cocos2d::EventMouse* event);
//	virtual void rightMouseDownHandler(cocos2d::EventMouse* event);
//	virtual void rightMouseUpHandler(cocos2d::EventMouse* event);
// 
//};
#endif

