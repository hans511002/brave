#ifndef BASE_NODE_SPRITE_H
#define BASE_NODE_SPRITE_H
#pragma warning(disable:4819 4003)

#include "cocos2d.h"
#include "dragonBones/cocos2dx/CCDragonBonesHeaders.h"
#include "common/Common.h"
#include "JsonUtil.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
#include "DefineClasses.h"

#define ISTYPE(CLZTYPE,POINTER)  dynamic_cast<CLZTYPE *>(POINTER)
namespace engine{
	struct MovieClipSub;
}

namespace std
{
	class BaseNode;
	void setAnchorPoint(cocos2d::Node* node, bool subset = false);
	void setAnchorPoint(cocos2d::Node* node, float x, float y, bool subset = false);
	void setAnchorPoint(cocos2d::Node* node, const cocos2d::Vec2 & pos, bool subset = false);
	dragonBones::CCArmatureDisplay * loadArmature(string rootPath, string armatureName, const string& dragonBonesName = "");
	dragonBones::CCArmatureDisplay * buildArmature(string armatureName, const string& dragonBonesName);
	string setText(ui::Text * tui, string val);
	int setText(ui::Text * tui, int val);
	float setText(ui::Text * tui, float val);
	int getInt(ui::Text * tui);
	string getText(ui::Text * tui);
	bool hitTest(cocos2d::Node * node, const Vec2 &pt);
	bool hitTest(cocos2d::Node * node, cocos2d::EventMouse* e);
	string getNamePath(Node *node);
	Common::Array<Node*>  getChildNodes(Node *node);
	bool getNodeVisible(Node * node);


	extern Common::Log * gLog;

	void writeLog(string msg, int type);
	class MouseEvent : public cocos2d::EventMouse
	{
		int idx;
	public:
		Common::Array<Node *> currentTargets;
		MouseEvent(MouseEventType mouseEventCode);
		void setCurrentTarget(Node* target);
		MouseEvent(EventMouse * e, bool incSub = false);
		void hitTest(Node *node, int level);
		void hitTest(Node *node, bool incSub = false);
		bool hasNext(); 
		inline void reset(){ idx =0; };

		Node * target; 
	};

	class EventNode
	{
	public:
		inline EventNode() :mouseChildren(false), mouseEnabled(false),  mouseFlag(false){ nodeType = getTypeName(); };
		static bool debug;
		cocos2d::Label* createLabel(const std::string& string);

		string nodeType;
		string getTypeName();
		inline void setNodeType(string nt) { nodeType = typeid(*this).name(); };
		inline virtual bool hitTest(const Vec2 &pt) { return mouseEnabled ; };
		inline virtual bool hitTest(cocos2d::EventMouse* event) { return   mouseEnabled; };
		bool mouseChildren;
		bool mouseEnabled;
		bool mouseFlag;
		virtual void setMouseChildren(bool v);
		virtual void setMouseEnabled(bool v);
		virtual void setMouseFlag(bool v);
		static void setNodeMouse(EventNode * en,int type,bool v);

		virtual bool isMouseChildren();
		virtual bool isMouseEnabled();
		virtual bool isMouseFlag();

		float getStageWidth() const;
		float getStageHeight() const;
		dragonBones::CCArmatureDisplay * loadArmature(string rootPath, string armatureName, const string& dragonBonesName = "");
		dragonBones::CCArmatureDisplay * buildArmature(string armatureName, const string& dragonBonesName);
		//inline string setText(ui::Text * tui, string val) { return std::setText(tui, val); };
		//inline int setText(ui::Text * tui, int val) { return std::setText(tui, val); };
		//inline float setText(ui::Text * tui, float val) { return std::setText(tui, val); };
		void logInfo(string label, cocos2d::Point pos, const cocos2d::Point* pos2 = NULL, const  cocos2d::Point* pos3 = NULL, const  cocos2d::Point* pos4 = NULL);
		void logInfo(string label, cocos2d::Size pos);
		void logInfo(string label, float x, float y = 0);
		void logInfo(string label, int x);
		void logInfo(string label, int x, int y);
		void logInfo(string label, int i, Vec2 p);
		void logInfo(string label1, string label2 = "", string label3 = "", string label4 = "", string label5 = "", string label6 = "");
		void logInfo(string label, dragonBones::Transform t);
		void logInfo(string label, dragonBones::Transform*t);
		void logInfo(string label, dragonBones::Transform const*t);
		 

#define LOGINFO(format, ...)      cocos2d::log(format, ##__VA_ARGS__)
		void logInfo(string mouseType, cocos2d::EventMouse* event);
		virtual string getNamePath(Node *node= NULL);
		void printChildNodes(Node *node=NULL);
		void printNodePos(Node *node);
		void printNodePos(MovieClipSub *node);


		virtual   void keyBoardPressedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
		virtual   void keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
		virtual   void mouseDownHandler(cocos2d::EventMouse* event);
		virtual   void mouseUpHandler(cocos2d::EventMouse* event);
		virtual   void mouseMoveHandler(cocos2d::EventMouse* event);
		virtual   void mouseScrollHandler(cocos2d::EventMouse* event);
		virtual   void rightMouseDownHandler(cocos2d::EventMouse* event);
		virtual   void rightMouseUpHandler(cocos2d::EventMouse* event);
		virtual void touchActionHandler(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
	};
	extern Common::Array<EventNode *> EventNodes;
	void addEventNode(EventNode *node);
	void removeEventNode(EventNode *node);
	std::MouseEvent buildMouseEvent(EventMouse * e);

	class BaseNode :public cocos2d::Node, public EventNode
	{
		int schdt;
	public:
		static const double AnimationInterval;
		cocos2d::EventListenerMouse * listener;
		inline BaseNode() :schdt(0), autoDel(true), listener(0) { setName(getTypeName()); };//mouseEnabled(false), mouseChildren(false), 
		BaseNode(float w, float h, bool draw = true);
        virtual bool init();
        virtual bool atStage();
		virtual bool hitTest(const Vec2 &pt);
		virtual bool hitTest(cocos2d::EventMouse* event);
		cocos2d::Point localToGlobal(cocos2d::Point pt);

		virtual void onEnter();
		virtual void onExit();
		virtual void scheduleUpdate(float dt);
		inline virtual void update(float dt = 0) {};

		//帧频事件
		virtual void enterFrameHandler(float dt);
		virtual void enableFrameHandler(bool init = true);
		virtual void disableFrameHandler();

		virtual void setAlpha(float);
		virtual float getAlpha();

		bool autoDel;
		bool isAutoDel;
		virtual void autorelease();
		virtual void setSize(float w, float h, bool draw = true);
		virtual void drawRange();
		virtual void enableMouseHandler();
		virtual void enableKeyHandler();
		virtual void disableMouseHandler();

		////鼠标键盘事件
		//virtual void touchActionHandler(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
		//virtual void keyBoardPressedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
		//virtual void keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
		//virtual void mouseDownHandler(cocos2d::EventMouse* event);
		//virtual void mouseUpHandler(cocos2d::EventMouse* event);
		//virtual void mouseMoveHandler(cocos2d::EventMouse* event);
		//virtual void mouseScrollHandler(cocos2d::EventMouse* event);
		//virtual void rightMouseDownHandler(cocos2d::EventMouse* event);
		//virtual void rightMouseUpHandler(cocos2d::EventMouse* event);

		virtual std::MouseEvent buildMouseEvent(Node * node = NULL, int mouseButton=0, cocos2d::EventMouse::MouseEventType mouseEventType = cocos2d::EventMouse::MouseEventType::MOUSE_DOWN);

		virtual float getWidth();
		virtual float getHeight();
		virtual void setWidth(float w);
		virtual void setHeight(float h);

		static void setAlpha(cocos2d::Node * node, float);
		static float getAlpha(cocos2d::Node * node);
		virtual bool isVisible();
	protected:

	};
	class BaseSprite :public   cocos2d::Sprite, public EventNode
	{
	protected:
		inline BaseSprite() {};
	public:
		bool init();
		bool atStage();
		//void mouseDownHandler(cocos2d::EventMouse *event);
		BaseSprite(string file);
		BaseSprite(cocos2d::Sprite* sprite);
		virtual float getWidth();
		virtual float getHeight();
		virtual void setWidth(float w);
		virtual void setHeight(float h);
		inline virtual bool hitTest(const Vec2 &pt) { return std::hitTest(this, pt); };
		inline virtual bool hitTest(cocos2d::EventMouse* event) { return std::hitTest(this, event); };
		virtual void onEnter();
		virtual void onExit();

		virtual bool isVisible();

	private:

	};
	class BaseLayer : public   cocos2d::LayerColor, public EventNode
	{
	protected:
		cocos2d::Sprite* _background;
		virtual void _onStart() = 0;
 	public:
		cocos2d::EventListenerMouse * listener;
		BaseLayer();
		inline virtual bool hitTest(const Vec2 &pt) { return std::hitTest(this, pt); };
		inline virtual bool hitTest(cocos2d::EventMouse* event) { return std::hitTest(this, event); };

		virtual bool init();
		virtual void onEnter();
		virtual void onExit();
		virtual void enableMouseHandler();
		virtual void enableKeyHandler();
		virtual void disableMouseHandler();
		//cocos2d::Label* createText(const std::string& string);
		virtual bool isVisible();

		//float getStageWidth() const;
		//float getStageHeight() const;
	};
	class ListenInterface : public BaseNode
	{
	public:
		virtual inline void manageListeners(string param1){};
	}; 
}

#endif

