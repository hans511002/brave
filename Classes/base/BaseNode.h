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
#include "MYPThread.h"
#include "sys/I18n.h"

#define ISTYPE(CLZTYPE,POINTER)  dynamic_cast<CLZTYPE *>(POINTER)
namespace engine{
	struct MovieClipSub;
}
using namespace sys;
namespace std
{
	class BaseNode;
    class EventNode;
	extern bool useNodeEvent;
    extern sys::I18n i18n;
	extern EventNode *globalNode;

#define I18N_VALUE(code) i18n[code]
	typedef void (EventNode::*NODE_MOUSEHANDLER)(cocos2d::EventMouse* event);
#define NODE_MOUSEHANDLER_SELECTOR(_SELECTOR) static_cast<std::NODE_MOUSEHANDLER>(&_SELECTOR)
	struct WORLD_NODE_MOUSEHANDLER {
		EventNode*  node;
		NODE_MOUSEHANDLER mouseDownHandler;
		NODE_MOUSEHANDLER mouseUpHandler;
		NODE_MOUSEHANDLER mouseMoveHandler;
	};

	void setAnchorPoint(cocos2d::Node* node, bool subset = false);
	void setAnchorPoint(cocos2d::Node* node, float x, float y, bool subset = false);
	void setAnchorPoint(cocos2d::Node* node, const cocos2d::Vec2 & pos, bool subset = false);
    dragonBones::CCArmatureDisplay * loadArmature(const string & rootPath, const string &  armatureName, const string& dragonBonesName = "");
    dragonBones::CCArmatureDisplay * buildArmature(const string &  armatureName, const string& dragonBonesName);
    string setText(ui::Text * tui, const string &  val);
	int setText(ui::Text * tui, int val);
	float setText(ui::Text * tui, float val);
	inline float setText(ui::Text * tui, double val){setText(tui,(float)val);};
	int getInt(ui::Text * tui);
	string getText(ui::Text * tui); 
	bool hitTest(cocos2d::Node * node, const Vec2 &pt,bool mouseEvent=true);
	bool hitTest(cocos2d::Node * node, cocos2d::EventMouse* e);
	void drawRange(cocos2d::Node * node, Color4F c = Color4F::RED);
	void changeAnchorPoint(Node * node, float xy);
	void changeAnchorPoint(Node * node, const Vec2& xy); 
	cocos2d::Sprite* maskedSpriteWithSprite(cocos2d::Sprite* textureSprite, cocos2d::Sprite* maskSprite);
	//cocos2d::ClippingNode* maskedWithClippingNode(cocos2d::Sprite* textureSprite, cocos2d::Sprite* maskSprite);

	string getNamePath(Node *node);
	Common::Array<Node*>  getChildNodes(Node *node);
	bool getNodeVisible(Node * node);

	extern Common::Log * gLog;

	void writeLog(string msg, int type);

	class EventNode
	{
	public:
		EventNode();
		static bool debug;
		cocos2d::Label* createLabel(const std::string& string);

		string nodeType;
		virtual string getTypeName();
		inline void setNodeType(string nt) { nodeType = nt; };
		inline virtual bool hitTest(const Vec2 &pt) { return mouseEnabled ; };
		inline virtual bool hitTest(cocos2d::EventMouse* event) { return   mouseEnabled; };
		bool mouseChildren;
		bool mouseEnabled;
		bool mouseFlag;
		virtual void setMouseChildren(bool v,bool setSub=true);
		virtual void setMouseEnabled(bool v, bool setSub = true);
		virtual void setMouseFlag(bool v, bool setSub = true);
		static void setNodeMouse(Node * en, int type, bool v, bool setSub = true);

		virtual bool isMouseChildren();
		virtual bool isMouseEnabled();
		virtual bool isMouseFlag();

		float getStageWidth() const;
		float getStageHeight() const;
        dragonBones::CCArmatureDisplay * loadArmature(const string &  rootPath, const string & armatureName, const string& dragonBonesName = "");
        dragonBones::CCArmatureDisplay * buildArmature(const string &  armatureName, const string& dragonBonesName);
		//inline string setText(ui::Text * tui, string val) { return std::setText(tui, val); };
		//inline int setText(ui::Text * tui, int val) { return std::setText(tui, val); };
		//inline float setText(ui::Text * tui, float val) { return std::setText(tui, val); };
        void logInfo(const string &  label, const cocos2d::Point & pos, const cocos2d::Point* pos2 = NULL, const  cocos2d::Point* pos3 = NULL, const  cocos2d::Point* pos4 = NULL);
        void logInfo(const string &  label, const cocos2d::Size & pos);
        void logInfo(const string &  label, float x, float y = 0);
        void logInfo(const string &  label, int x);
        void logInfo(const string &  label, int x, int y);
        void logInfo(const string &  label, int i, Vec2 p);
        void logInfo(const string &  label1, const string & label2 = "", const string & label3 = "", const string & label4 = "", const string & label5 = "", const string & label6 = "");
        void logInfo(const string &  label, dragonBones::Transform t);
        void logInfo(const string &  label, dragonBones::Transform*t);
        void logInfo(const string &  label, dragonBones::Transform const*t);
		 

#define LOGINFO(format, ...)      cocos2d::log(format, ##__VA_ARGS__)
		void logInfo(string mouseType, cocos2d::EventMouse* event);
		virtual string getNamePath(Node *node= NULL);
		void printChildNodes(Node *node=NULL);
		void printNodePos(Node *node);
		void printNodePos(MovieClipSub *node);

		virtual void keyBoardPressedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
		virtual void keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
		virtual void mouseDownHandler(cocos2d::EventMouse* event);
		virtual void mouseUpHandler(cocos2d::EventMouse* event);
		virtual void mouseMoveHandler(cocos2d::EventMouse* event);
		virtual void mouseScrollHandler(cocos2d::EventMouse* event);
		virtual void rightMouseDownHandler(cocos2d::EventMouse* event);
		virtual void rightMouseUpHandler(cocos2d::EventMouse* event);
		//ui touch
		virtual void touchActionHandler(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);

		virtual bool onTouchBegan(Touch *touch, Event *unused_event);
		virtual void onTouchEnded(Touch *touch, Event *unused_event);
		virtual void onTouchCancelled(Touch *touch, Event *unused_event);
		virtual void onTouchMoved(Touch *touch, Event *unused_event);
	};
	extern Common::Array<EventNode *> EventNodes;
	void addEventNode(EventNode *node);
	void removeEventNode(EventNode *node);
	class MouseEvent : public cocos2d::EventMouse
	{
		int idx;
	public:
        bool processed;
		 
		Common::Array<Node *> currentTargets;
		MouseEvent(MouseEventType mouseEventCode);
		void setCurrentTarget(Node* target);
        MouseEvent(EventMouse * e, bool incSub);
        MouseEvent(EventMouse * e);
		void hitTest(Node *node, int level);
		void hitTest(Node *node, bool incSub = false);
		bool hasNext(); 
		inline void reset(){ idx =0; };
        int getIndex(const string & name);
		void remove(int i);
		Node * target; 
        EventNode * enode;
	};	
    std::MouseEvent buildMouseEvent(EventMouse * e);
    enum LinkNodeType{
        LinkRuleNone=0,
        LinkPos=1,
        LinkVisible=2,
        LinkScale=4,
		LinkAlpha = 8,
		LinkSize = 16,
		LinkRotation = 32,
		LinkSekw = 64,
		LinkZOrder = 128,
        LinkAnchorPoint=256
    };
    static const int defaultLinkFlag=255;
	typedef std::map<BaseNode *, int> LinkRuleMap;
#define SET_NODETYPENAME() string name=getTypeName();setName(name);setNodeType(name)

	class BaseNode :public cocos2d::Node, public EventNode
	{

    protected:
		int schdt;
		LinkRuleMap linkNodes;
		//static LinkRuleMap linkBaseNodes;
		BaseNode * linkParent;
	public:
		Vec2 basePoint;
		static const double AnimationInterval;
		cocos2d::EventListenerMouse * listener;
		cocos2d::EventListenerTouchOneByOne * touchOnelistener;

		BaseNode();
		BaseNode(float w, float h, bool draw = true);
		//virtual string getTypeName();
        virtual bool init();
        virtual bool atStage();
		virtual bool hitTest(const Vec2 &pt);
		virtual bool hitTest(cocos2d::EventMouse* event);
        inline Vec2 localToGlobal(const Vec2 &  pos) { return this->convertToWorldSpace(pos); };
        inline Vec2 globalToLocal(const Vec2 &  pos) { return this->convertToNodeSpaceAR(pos); };

		virtual void onEnter();
		virtual void onExit();
		virtual void scheduleUpdate(float dt);
		inline virtual void update(float dt = 0) {};
		virtual void addChild(Node *child);
		virtual void addChild(Node * child, int localZOrder);
		virtual void addChild(Node* child, int localZOrder, int tag);
		virtual void addChild(Node* child, int localZOrder, const std::string &name);

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
		virtual void enableMouseHandler(bool listen=false);
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

		virtual std::MouseEvent buildMouseEvent(Node * node = NULL, cocos2d::EventMouse::MouseButton mouseButton = cocos2d::EventMouse::MouseButton::BUTTON_LEFT, cocos2d::EventMouse::MouseEventType mouseEventType = cocos2d::EventMouse::MouseEventType::MOUSE_DOWN);

		virtual float getWidth();
		virtual float getHeight();
		virtual void setWidth(float w);
		virtual void setHeight(float h);
		virtual void  changeAnchorPoint(float xy);

		static void setAlpha(cocos2d::Node * node, float);
		static float getAlpha(cocos2d::Node * node);
		virtual bool isVisible();
		//////////////////////////////////////////////////
		virtual void setLocalZOrder(int localZOrder);
        virtual void setGlobalZOrder(float globalZOrder);
        virtual void setScaleX(float scaleX); 
        virtual void setScaleY(float scaleY); 
        virtual void setScaleZ(float scaleZ); 
        virtual void setScale(float scale); 
        virtual void setScale(float scaleX, float scaleY); 
        virtual void setPosition(const Vec2 &position);
        virtual void setNormalizedPosition(const Vec2 &position);
        virtual void setPosition(float x, float y); 
        virtual void setPositionX(float x); 
        virtual void setPositionY(float y); 
        virtual void setPosition3D(const Vec3& position); 
        virtual void setPositionZ(float positionZ);
        virtual void setSkewX(float skewX); 
        virtual void setSkewY(float skewY);
        virtual void setAnchorPoint(const Vec2& anchorPoint);
        virtual void setContentSize(const Size& contentSize);
        virtual void setVisible(bool visible);
        virtual void setRotation(float rotation); 
        virtual void setRotation3D(const Vec3& rotation); 
        virtual void setRotationQuat(const Quaternion& quat); 
        virtual void setRotationSkewX(float rotationX); 
        virtual void setRotationSkewY(float rotationY); 
        virtual void setOpacity(GLubyte opacity);
        virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);
        virtual void setOpacityModifyRGB(bool value);
        
        ///////////////////
		virtual void addLinkNode(BaseNode * node, int linkFlag = defaultLinkFlag);
		virtual void addLinkNodeFlag(BaseNode * node, int linkFlag);
		virtual void removeLinkNode(BaseNode * node);
		virtual void removeLinkNodeFlag(BaseNode * node, int linkFlag);
	};
	class BaseSprite :public   cocos2d::Sprite, public EventNode
	{
	protected:
		inline BaseSprite() {};
	public:
		bool init();
		bool atStage();
		//void mouseDownHandler(cocos2d::EventMouse *event);
		BaseSprite(const string &file);
		BaseSprite(cocos2d::Sprite* sprite);
		virtual float getWidth();
		virtual float getHeight();
		virtual void setWidth(float w);
		virtual void setHeight(float h);
		inline virtual bool hitTest(const Vec2 &pt) { return std::hitTest(this, pt); };
		inline virtual bool hitTest(cocos2d::EventMouse* event) { return std::hitTest(this, event); };
		virtual void onEnter();
		virtual void onExit();
		virtual void drawRange();

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
		cocos2d::EventListenerTouchOneByOne * touchOnelistener;
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
		virtual void drawRange();

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

