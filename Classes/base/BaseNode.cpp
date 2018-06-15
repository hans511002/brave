#include "BaseNode.h"
#include "MainClass.h"

using namespace cocos2d;
const double BaseNode::AnimationInterval = 1.0f / (double)Main::FrameRate;

namespace std
{
	Common::Log * gLog = new Common::Log("brave");
	//Common::Log * gLog = NULL;
	Common::Array<EventNode *> EventNodes;
	void addEventNode(EventNode *node)
	{
		if(!node)return;
		for each (EventNode * _node in EventNodes)
			if(_node == node)return;
		EventNodes.push(node);
	};
	void removeEventNode(EventNode *node) {
		int l = EventNodes.size();
		for(int i = 0;	i < l; i++)
		{
			if(EventNodes.at(i) == node)
			{
				EventNodes.remove(i);
				return;
			}
		}
	};


	void writeLog(string msg, int type)
	{
		if(gLog)Common::writeLog(msg, gLog, EventNode::debug, type);
	};
	void setAnchorPoint(Node* node, bool subset)
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
	void setAnchorPoint(cocos2d::Node* node, float x, float y, bool subset)
	{
		node->setAnchorPoint(Vec2(x, y));
		if(subset)
		{
			cocos2d::Vector<Node * > chlds = node->getChildren();
			for(size_t i = 0; i < chlds.size(); i++)
			{
				std::setAnchorPoint(chlds.at(i), x, y, subset);
			}
		}
	};
	void setAnchorPoint(cocos2d::Node* node, const cocos2d::Vec2 & pos, bool subset)
	{
		node->setAnchorPoint(pos);
		if(subset)
		{
			cocos2d::Vector<Node * > chlds = node->getChildren();
			for(size_t i = 0; i < chlds.size(); i++)
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
		if(!rootPath.empty() && rootPath.at(rootPath.length() - 1) != '/')
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
	bool BaseNode::init()
	{
		cocos2d::Node::init();
		std::setAnchorPoint(this);
		this->autorelease();
		return true;
	};
	void BaseNode::autorelease()
	{
		if(autoDel && !isAutoDel)
		{
			Node::autorelease();
			isAutoDel = true;
		}
	};

	bool BaseSprite::init()
	{
		this->autorelease();
		std::setAnchorPoint(this);
		return true;
	};
	BaseSprite::BaseSprite(string file)
	{
		setNodeType("BaseSprite");
		this->initWithFile(file);
		init();
	}
	BaseSprite::BaseSprite(cocos2d::Sprite* sprite)
	{
		setNodeType("BaseSprite");
		this->initWithTexture(sprite->getTexture());
		BaseSprite::init();
	};

	bool BaseNode::hitTest(const Vec2 &pt)
	{
		if(!mouseEnabled)return false;
		if(!this->isVisible())return false;
		return std::hitTest(this, pt);
	};
	bool BaseNode::hitTest(cocos2d::EventMouse* event)
	{
		if(!mouseEnabled)return false;
		if(!this->isVisible())return false;
		return std::hitTest(this, event);
	};

	cocos2d::Point BaseNode::localToGlobal(cocos2d::Point pt)
	{
		return this->convertToWorldSpace(pt);
	};

	void BaseNode::onEnter()
	{
		if(this->mouseEnabled || this->buttonMode)
			addEventNode(this);
		Node::onEnter();
		if(schdt==1)
			this->schedule(schedule_selector(BaseNode::scheduleUpdate), AnimationInterval);
	};
	void BaseNode::onExit()
	{
		removeEventNode(this);
		Node::onExit();
	};
 
	void BaseNode::scheduleUpdate(float dt)
	{
		enterFrameHandler(dt);
	};
	void BaseNode::enterFrameHandler(float dt)
	{
	};
	void BaseNode::enableFrameHandler(bool init){
		schdt = 2;
		if (init)
			this->schedule(schedule_selector(BaseNode::scheduleUpdate), AnimationInterval);
		else
			schdt = 1;
	};
	void BaseNode::disableFrameHandler(){
		if (schdt){
			schdt = 0;
			this->unschedule(schedule_selector(BaseNode::scheduleUpdate));
		}
	};

	bool BaseLayer::init()
	{
		if(!LayerColor::initWithColor(cocos2d::Color4B(105, 105, 105, 255)))
		{
			return false;
		}
		const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
		setPosition(0, 0);
		//setPosition(stageSize.width * 0.5f, stageSize.height * 0.5f);
		_background = cocos2d::Sprite::create("background.png");
		addChild(_background, 0);
		_onStart();
		return true;
	}
	void BaseLayer::onEnter()
	{
		if (this->mouseEnabled || this->buttonMode)
			addEventNode(this);
		LayerColor::onEnter();
	};
	void BaseLayer::onExit()
	{
		removeEventNode(this);
		LayerColor::onExit();
	};
	cocos2d::Label* EventNode::createLabel(const std::string& string)
	{
		const auto text = cocos2d::Label::create();
		text->setPosition(0.0f, -(getStageHeight() * 0.5f - 100.f));
		text->setString(string);
		text->setAlignment(cocos2d::TextHAlignment::CENTER);
		//addChild(text);
		return text;
	}

	float  EventNode::getStageWidth() const
	{
		const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
		return stageSize.width;
	}

	float  EventNode::getStageHeight() const
	{
		const auto& stageSize = cocos2d::Director::getInstance()->getVisibleSize();
		return stageSize.height;
	}
	dragonBones::CCArmatureDisplay * EventNode::loadArmature(string rootPath, string armatureName, const string& dragonBonesName)
	{
		return std::loadArmature(rootPath, armatureName, dragonBonesName);
	};
	dragonBones::CCArmatureDisplay * EventNode::buildArmature(string armatureName, const string& dragonBonesName)
	{
		return std::buildArmature(armatureName, dragonBonesName);
	};

	bool  hitTest(cocos2d::Node * node, cocos2d::EventMouse* e)
	{
		return hitTest(node, e->getLocationInView());
	};
	bool  hitTest(Node * node, const Vec2 &pt)
	{
		if(!node->isVisible())return false;
		if(node->getOpacity() < 2)return false;
		if (ISTYPE(EventNode, node)){
			EventNode* enode=ISTYPE(EventNode, node);
			if (!enode->mouseEnabled &&!enode->buttonMode)return false;
		} 
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
					if(t.width > 0 && t.height > 0)
						bb.size = n->getContentSize();
				}
			}
		}
		if(bb.containsPoint(nsp))
		{
			return true;
		}
		return false;
	}

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

	void BaseNode::setAlpha(float op)
	{
		setAlpha(this, op);
	};
	float BaseNode::getAlpha()
	{
		return getAlpha(this);
	};
	void BaseNode::setAlpha(cocos2d::Node * node, float op)
	{
		op = op<0 ? 0 : op>1?1:op;
		int ops = op * 255; 
		node->setOpacity(ops);
	};
	float BaseNode::getAlpha(cocos2d::Node * node)
	{
		int ops = node->getOpacity();
		return (double)ops / 255;
	};

	BaseNode::BaseNode(float w, float h, bool draw) :autoDel(true), listener(0)
	{
		setNodeType( "BaseNode");
		this->setContentSize(Size(w, h));
		enableMouseHandler();
		if(draw)drawRange();
	};
	void BaseNode::setSize(float w, float h, bool draw)
	{
		this->setContentSize(Size(w, h));
		if(draw)drawRange();
	}
	float BaseNode::getWidth()
	{
	    return this->getContentSize().width;
    };
    float BaseNode::getHeight()
	{
	    return this->getContentSize().height;
    };
	void BaseNode::setWidth(float w){
		Size size=this->getContentSize();
		size.width = w;
		this->setContentSize(size);
	};
	void BaseNode::setHeight(float h){
		Size size = this->getContentSize();
		size.height= h;
		this->setContentSize(size);
	};

	float BaseSprite::getWidth()
	{
		return this->getContentSize().width;
	};
	float BaseSprite::getHeight()
	{
		return this->getContentSize().height;
	};
	void BaseSprite::setWidth(float w){
		Size size = this->getContentSize();
		size.width = w;
		this->setContentSize(size);
	};
	void BaseSprite::setHeight(float h){
		Size size = this->getContentSize();
		size.height = h;
		this->setContentSize(size);
	};
	void BaseSprite::onEnter()
	{
		if(this->mouseEnabled || this->buttonMode)
			addEventNode(this);
		Sprite::onEnter();
	};	
	void BaseSprite::onExit()
	{
		removeEventNode(this);
		Sprite::onExit();
	};

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

	MouseEvent::MouseEvent(MouseEventType mouseEventCode) : cocos2d::EventMouse(mouseEventCode), idx(0), target(NULL)
	{
	};
	MouseEvent::MouseEvent(cocos2d::EventMouse * e, bool incSub) :EventMouse(*e), idx(0), target(NULL)
	{
		Node * node = e->getCurrentTarget();
		hitTest(node, incSub);
	};
	void  MouseEvent::hitTest(Node *node, bool incSub)
	{
		if(ISTYPE(EventNode, node))
		{
			EventNode *n = ISTYPE(EventNode, node);
			if(n->hitTest(this))
				currentTargets.push(node);
		} 
		if(incSub && node->isVisible() && node->getChildrenCount())
		{
			int len = node->getChildrenCount();
			Vector<Node*>& nodes = node->getChildren();
			for(int i = 0; i < len; i++)
			{
				node = nodes.at(i);
				hitTest(node, incSub);
			}
		}
	};
	void  MouseEvent::hitTest(Node *node, int level)
	{
		if (ISTYPE(EventNode, node))
		{
			EventNode *n = ISTYPE(EventNode, node);
			if(n->hitTest(this))
				currentTargets.push(node);
			if (n->mouseChildren && node->isVisible() && node->getChildrenCount())
			{
				int len = node->getChildrenCount();
				Vector<Node*>& nodes = node->getChildren();
				for(int i = 0; i < len; i++)
				{
					node = nodes.at(i);
					hitTest(node, level + 1);
				}
			}
		}
		else
		{
			if(!node->getName().empty() && std::hitTest(node, this))
				currentTargets.push(node);
			if(node->isVisible() && node->getChildrenCount())
			{
				int len = node->getChildrenCount();
				Vector<Node*>& nodes = node->getChildren();
				for(int i = 0; i < len; i++)
				{
					node = nodes.at(i);
					hitTest(node, level + 1);
				}
			}
		}
	};
	void std::MouseEvent::setCurrentTarget(Node* target)
	{
		cocos2d::EventMouse::setCurrentTarget(target);
		this->target = target;
	};
	bool MouseEvent::hasNext(){
		if (currentTargets.size() > idx){
			setCurrentTarget(currentTargets.at(idx));
			idx++;
            return true;
        }
		return false;
	};

	std::MouseEvent buildMouseEvent(EventMouse * e)
	{
		std::MouseEvent  me(e);
		Node * n=	e->getCurrentTarget();
		int l = EventNodes.size();
		for (int i = 0; i < l; i++)
		{
			EventNode * _node = EventNodes.at(i);
			Node *node = ISTYPE(Node, _node);
			if (n == node)continue;
			if (!node)continue;
			if (std::hitTest(node,e))
				me.currentTargets.push(node);
		}
		return me;
	};

	std::MouseEvent BaseNode::buildMouseEvent(Node * node, int mouseButton, cocos2d::EventMouse::MouseEventType mouseEventType)
	{
		std::MouseEvent e(mouseEventType);
		e.setMouseButton(mouseButton);
		if (node)
		{
			e.setCurrentTarget(node);
			Vec2 pos = node->convertToWorldSpace(node->getPosition());
			e.setCursorPosition(pos.x + 0.1, pos.y + 0.1);
		}
		else
		{
			e.setCurrentTarget(this);
			Vec2 pos = this->convertToWorldSpace(this->getPosition());
			e.setCursorPosition(pos.x + 0.1, pos.y + 0.1);
		}
		return e;
	}
	void BaseNode::enableMouseHandler()
	{
		if(!this->mouseEnabled)
		{
			this->mouseEnabled = true;
			this->buttonMode = true;
		}
		if(listener == NULL)
		{
			listener = cocos2d::EventListenerMouse::create();
			listener->onMouseDown = CC_CALLBACK_1(BaseNode::mouseDownHandler, this);
			listener->onMouseUp = CC_CALLBACK_1(BaseNode::mouseUpHandler, this);
			listener->onMouseMove = CC_CALLBACK_1(BaseNode::mouseMoveHandler, this);
			listener->onMouseScroll = CC_CALLBACK_1(BaseNode::mouseScrollHandler, this);
			getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
		}
	};
	void BaseNode::disableMouseHandler(){
		if (listener){
			getEventDispatcher()->removeEventListener(listener);
			delete listener;
			listener = NULL;
		}
	}

	void BaseNode::enableKeyHandler()
	{
		const auto keyboardListener = cocos2d::EventListenerKeyboard::create();
		keyboardListener->onKeyPressed = CC_CALLBACK_2(BaseNode::keyBoardPressedHandler, this);
		keyboardListener->onKeyReleased = CC_CALLBACK_2(BaseNode::keyBoardReleasedHandler, this);
		getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	}
	void EventNode::keyBoardPressedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		logInfo("keyBoardPressed keyCode", (int)keyCode);
		switch(keyCode)
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
	void EventNode::keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		logInfo("keyBoardReleased keyCode", (int)keyCode);
		switch(keyCode)
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
	void EventNode::mouseDownHandler(cocos2d::EventMouse* event)
	{
		//loginfo("mouseDown",event); 
		if(!std::hitTest(event->getCurrentTarget(),event))return;
		logInfo("hitTest true : mouse in ", event->getCurrentTarget()->getName());
		Node * node = event->getCurrentTarget();
		Event::Type tp = event->getType();
		logInfo("event targetNamePath", getNamePath(node));
		int mouseButton = event->getMouseButton();
		if(mouseButton == 1)
			rightMouseDownHandler(event);
	};
	void EventNode::mouseUpHandler(cocos2d::EventMouse* event)
	{
		if(!std::hitTest(event->getCurrentTarget(), event))return;
		int mouseButton = event->getMouseButton();
		//loginfo("mouseUp", event);
		if(mouseButton == 1)rightMouseUpHandler(event);
	};

	void EventNode::mouseMoveHandler(cocos2d::EventMouse* event)
	{
		if(!this->hitTest(event))return;
		//logInfo("mouseMoved", event->getCursorX(), event->getCursorY());
	};
	void EventNode::mouseScrollHandler(cocos2d::EventMouse* event)
	{
		if(!this->hitTest(event))return;
	};
	void EventNode::rightMouseDownHandler(cocos2d::EventMouse* event)
	{
	};
	void EventNode::rightMouseUpHandler(cocos2d::EventMouse* event)
	{
	};
	void EventNode::touchActionHandler(cocos2d::Ref *ref, cocos2d::ui::TouchEventType type)
	{
		Node * node = (Node *)ref;
		string target = node->getName();
		CCLOG("touchAction %s type=%i", target.c_str(), type);
	};

	string EventNode::getNamePath(Node *node)
	{
		if(!node)
		{
			if(ISTYPE(Node, this))
				return getNamePath(ISTYPE(Node, this));
			return "";
		}
		string name = node->getName();
		while(node->getParent())
		{
			node = node->getParent();
			name = node->getName() + "." + name;
		}
		return name;
	};

	void EventNode::loginfo(string mouseType, cocos2d::EventMouse* event)
	{
		if(!debug)return;
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
		if(bb.containsPoint(nsp))
		{
			logInfo("         nsp in bb", bb.size);

		}
	};
	bool EventNode::debug = true;
	void EventNode::logInfo(string label, cocos2d::Point pos)
	{
		if(!debug)return;
		CCLOG("%s x=%f y=%f", label.c_str(), pos.x, pos.y);
		if(gLog)writeLog(label + " x=" + Common::String(pos.x) + " y=" + Common::String(pos.y), 1);
	};
	void EventNode::logInfo(string label, cocos2d::Size pos)
	{
		if(!debug)return;
		CCLOG("%s w=%f h=%f", label.c_str(), pos.width, pos.height);
		if(gLog)writeLog(label + " w=" + Common::String(pos.width) + " h=" + Common::String(pos.height), 1);
	};
	void EventNode::logInfo(string label, float x, float y)
	{
		if(!debug)return;
		CCLOG("%s x=%f y=%f", label.c_str(), x, y);
		if(gLog)writeLog(label + " x=" + Common::String(x) + " y=" + Common::String(y), 1);
	};
	void EventNode::logInfo(string label, int x)
	{
		if(!debug)return;
		CCLOG("%s=%d ", label.c_str(), x);
		if(gLog)writeLog(label + "=" + Common::String(x), 1);
	};
	void EventNode::logInfo(string label, int x, int y)
	{
		if(!debug)return;
		CCLOG("%s[%d , %d]", label.c_str(), x, y);
		if(gLog)writeLog(label + " x=" + Common::String(x) + " y=" + Common::String(y), 1);
	};
	void EventNode::logInfo(string label1, string label2, string label3, string label4, string label5, string label6)
	{
		if(!debug)return;
		string msg = label1;
		if(!label2.empty())
			msg += "=" + label2;
		if(!label3.empty() && !label4.empty())
			msg += label3 + "=" + label4;
		if(!label5.empty() && !label6.empty())
			msg += label5 + "=" + label6;
		CCLOG(msg.c_str());
		if(gLog)writeLog(msg, 1);
	};

}
