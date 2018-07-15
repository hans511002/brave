#include "BaseNode.h"
#include "MainClass.h"
#include "base/mc.h"

using namespace cocos2d;
const double BaseNode::AnimationInterval = 1.0f / (double)Main::FrameRate;

namespace std
{
	bool useNodeEvent = true;

	cocos2d::CCSprite* maskedSpriteWithSprite(cocos2d::CCSprite* textureSprite, cocos2d::CCSprite* maskSprite)
	{
		// 1
		int w = maskSprite->getContentSize().width * maskSprite->getScaleX();
		int h = maskSprite->getContentSize().height * maskSprite->getScaleY();
		RenderTexture* rt = RenderTexture::create(w, h);

		// 2
		maskSprite->setPosition(ccp(maskSprite->getContentSize().width *  maskSprite->getScaleX() / 2,
			maskSprite->getContentSize().height * maskSprite->getScaleY() / 2));
		textureSprite->setPosition(ccp(textureSprite->getContentSize().width *  textureSprite->getScaleX() / 2,
			textureSprite->getContentSize().height * textureSprite->getScaleY() / 2));

		// 3
		ccBlendFunc blendFunc;
		blendFunc.src = GL_ONE;
		blendFunc.dst = GL_ZERO;
		maskSprite->setBlendFunc(blendFunc);

		blendFunc.src = GL_DST_ALPHA;            // mask图片的当前alpha值是多少，如果是0（完全透明），那么就显示mask的。如果是1（完全不透明）
		blendFunc.dst = GL_ZERO;                // maskSprite不可见
		textureSprite->setBlendFunc(blendFunc);

		// 4
		rt->begin();
		maskSprite->visit();
		textureSprite->visit();
		rt->end();

		// 5
		Sprite* retval = Sprite::createWithTexture(rt->getSprite()->getTexture());
		retval->setFlipY(true);
		return retval;
	};
	cocos2d::CCClippingNode* maskedWithClippingNode(cocos2d::Sprite* textureSprite, cocos2d::Sprite* maskSprite)
	{
		auto clip = CCClippingNode::create();
		clip->setStencil(maskSprite);
		clip->setInverted(false);
		clip->setAlphaThreshold(0);
		clip->addChild(textureSprite);
		return clip;
	};

	EventNode::EventNode() :mouseChildren(false), mouseEnabled(false), mouseFlag(false)
	{
	};
	BaseNode::BaseNode() :schdt(0), autoDel(true), listener(0), linkParent(NULL)
	{
		//setName(getTypeName());
	};

	BaseNode::BaseNode(float w, float h, bool draw) :autoDel(true), listener(0), linkParent(NULL)
	{
		setNodeType("BaseNode");
		this->setContentSize(Size(w, h));
		enableMouseHandler();
		if (draw)drawRange();
	};
	string EventNode::getTypeName(){
		Common::String clzName = typeid(*this).name();
		Common::Array<Common::String> names = clzName.Split(" ");
		clzName = names.at(names.size() - 1);
		names = clzName.Split("::");
		clzName = names.at(names.size() - 1);
		return clzName;
	};
	//   string BaseNode::getTypeName(){
	//       return EventNode::getTypeName();
	//};
	Common::Log * gLog = new Common::Log("brave");
	//Common::Log * gLog = NULL;
	Common::Array<EventNode *> EventNodes;
	void addEventNode(EventNode *node)
	{
		if (useNodeEvent)return;
		if (!node)return;
		for each (EventNode * _node in EventNodes)
		if (_node == node)return;
		EventNodes.push(node);
	};
	void removeEventNode(EventNode *node) {
		int l = EventNodes.size();
		for (int i = 0; i < l; i++)
		{
			if (EventNodes.at(i) == node)
			{
				EventNodes.remove(i);
				return;
			}
		}
	};


	void writeLog(string msg, int type)
	{
		if (gLog)Common::writeLog(msg, gLog, EventNode::debug, type);
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
	dragonBones::CCArmatureDisplay * loadArmature(const string & _rootPath, const string & armatureName, const string& dragonBonesName)
	{
		Common::DateTime dt;
		//dragonBones::DBCCFactory::getInstance()->loadDragonBonesData(rootPath + aniName + "/skeleton.xml", aniName);
		//dragonBones::DBCCFactory::getInstance()->loadTextureAtlas(rootPath + aniName + "/texture.xml", aniName);
		//return dragonBones::DBCCFactory::getInstance()->buildArmatureNode(aniName);
		string rootPath = _rootPath;
		if (!rootPath.empty() && rootPath.at(rootPath.length() - 1) != '/')
		{
			rootPath += "/";
		}
		string dbName = dragonBonesName == "" ? armatureName : dragonBonesName;
		const auto factory = dragonBones::CCFactory::getFactory();
		string fileSke = rootPath + dbName + "/" + dbName + "_ske.json";
		string fileTex = rootPath + dbName + "/" + dbName + "_tex.json";
		if (!factory->getDragonBonesData(dbName))
		{
			factory->loadDragonBonesData(fileSke, dbName);
			//factory->loadDragonBonesData(rootPath + armatureName + "/" + armatureName + "_ske.dbbin");
			factory->loadTextureAtlasData(fileTex, dbName);
		}
		//const std::string& armatureName, const std::string& dragonBonesName = "", const std::string& skinName = "", const std::string& textureAtlasName = ""
		const auto armatureDisplay = factory->buildArmatureDisplay(armatureName, dbName);
		//scene->addChild(armatureDisplay);
		////std::string name = armatureDisplay->getArmature()->getSlot("handL")->getName();
		//armatureDisplay->getAnimation()->play("icemandead", 999999);
		//armatureDisplay->setAnchorPoint(cocos2d::Vec2(0, 0));
		////std::setAnchorPoint(armatureDisplay,0,0);
		//armatureDisplay->setPosition(200.0f, 200.0f);
		//armatureDisplay->setVisible(true);
		int time = (Common::DateTime().GetTicks() - dt.GetTicks());
		CCLOG("%s.%s load time:%i", dragonBonesName.c_str(), armatureName.c_str(), time);
		return armatureDisplay;// factory->buildArmatureDisplay(armatureName, dragonBonesName);
	};
	dragonBones::CCArmatureDisplay * buildArmature(const string & armatureName, const string& dragonBonesName)
	{
		const auto factory = dragonBones::CCFactory::getFactory();
		const auto armatureDisplay = factory->buildArmatureDisplay(armatureName, dragonBonesName, "", dragonBonesName);
		return armatureDisplay;

	};
	string setText(ui::Text * tui, const string & val)
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
	void drawRange(Node * node, Color4F c)
	{
		Node * draw = node->getChildByName("drawNode");
		if (!draw){
			DrawNode* drawNode = DrawNode::create();
			drawNode->setName("drawNode");
			std::setAnchorPoint(drawNode, node->getAnchorPoint());
			node->addChild(drawNode);
			Size size = node->getContentSize();
			drawNode->setContentSize(size);
			Vec2 arpos = node->getAnchorPointInPoints();
			//Vec2 pos = node->convertToNodeSpace(node->getPosition());
			//Vec2 dest(pos.x + size.width, pos.y + size.height);
			drawNode->drawRect(Vec2(0, 0) - arpos, (Vec2)size - arpos, c);
			//drawNode->setScaleX(this->getScaleX());
			//drawNode->setScaleY(this->getScaleY());
		}
	};

	bool BaseNode::init()
	{
		cocos2d::Node::init();
		if (!ISTYPE(MovieClip, this)){
		}
		//logInfo("node:getAnchorPoint", this->getAnchorPoint());
		//logInfo("node:getAnchorPoint", this->getAnchorPointInPoints());
		//std::setAnchorPoint(this);
		this->autorelease();
		string name = getTypeName();
		setName(name);
		setNodeType(name);
		return true;
	};
	void BaseNode::autorelease()
	{
		if (autoDel && !isAutoDel)
		{
			Node::autorelease();
			isAutoDel = true;
		}
	};

	bool BaseSprite::init()
	{
		this->autorelease();
		//std::setAnchorPoint(this);
		string name = getTypeName();
		setName(name);
		setNodeType(name);
		return true;
	};
	BaseSprite::BaseSprite(const string & file)
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
		if (!mouseEnabled)return false;
		if (!this->isVisible())return false;
		return std::hitTest(this, pt);
	};
	bool BaseNode::hitTest(cocos2d::EventMouse* event)
	{
		if (!mouseEnabled)return false;
		if (!this->isVisible())return false;
		return std::hitTest(this, event);
	};

	void BaseNode::onEnter()
	{
		if (!useNodeEvent && this->mouseEnabled)
			addEventNode(this);
		Node::onEnter();
		if (schdt == 1)
			this->schedule(schedule_selector(BaseNode::scheduleUpdate), (float)AnimationInterval);
	};
	void BaseNode::onExit()
	{
		removeEventNode(this);
		this->linkNodes.clear();
		if (this->linkParent)this->linkParent->removeLinkNode(this);
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
			this->schedule(schedule_selector(BaseNode::scheduleUpdate), (float)AnimationInterval);
		else
			schdt = 1;
	};
	void BaseNode::disableFrameHandler(){
		if (schdt){
			schdt = 0;
			this->unschedule(schedule_selector(BaseNode::scheduleUpdate));
		}
	};
	BaseLayer::BaseLayer() :_background(nullptr), listener(NULL)
	{
		setNodeType("BaseLayer");
		std::setAnchorPoint((Node*)this);
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
		_background = cocos2d::Sprite::create("background.png");
		addChild(_background, 0);
		_onStart();
		SET_NODETYPENAME();
		return true;
	}
	void BaseLayer::onEnter()
	{
		if (this->mouseEnabled || this->mouseEnabled)
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
	dragonBones::CCArmatureDisplay * EventNode::loadArmature(const string & rootPath, const string & armatureName, const string& dragonBonesName)
	{
		return std::loadArmature(rootPath, armatureName, dragonBonesName);
	};
	dragonBones::CCArmatureDisplay * EventNode::buildArmature(const string & armatureName, const string& dragonBonesName)
	{
		return std::buildArmature(armatureName, dragonBonesName);
	};

	bool  hitTest(cocos2d::Node * node, cocos2d::EventMouse* e)
	{
		return hitTest(node, e->getLocationInView());
	};
	bool getNodeVisible(Node * node)
	{
		if (!node)return false;
		if (!node->isVisible())return false;
		Node * par = node->getParent();
		while (par){
			if (!par->isVisible())return false;
			par = par->getParent();
		}
		return true;
	}

	bool  hitTest(Node * node, const Vec2 &pt, bool mouseEvent /*= true*/)
	{
		if (!getNodeVisible(node))return false;
		if (node->getOpacity() < 2)return false;
		if (mouseEvent && ISTYPE(EventNode, node)){
			EventNode* enode = ISTYPE(EventNode, node);
			if (!enode->mouseEnabled)return false;
		}
		MovieClipSubBase * mcbs = ISTYPE(MovieClipSubBase, node);
		if (mcbs && !mcbs->isReady)
			return false;
		Vec2 nsp = node->convertToNodeSpace(pt);//convertToNodeSpace convertToNodeSpaceAR
		Rect bb;
		bb.size = node->getContentSize(); //node->convertToWorldSpace(node->getPosition())
		if (bb.size.height == 0 || bb.size.width == 0)
		{
			return false;
			//if (node->getChildrenCount())
			//{
			//	cocos2d::Vector<Node*> cld = node->getChildren();
			//	for each (Node *n in cld)
			//	{
			//		Size t = (n->getContentSize() - bb.size);
			//		if (t.width > 0 && t.height > 0)
			//			bb.size = n->getContentSize();
			//	}
			//}
		}
		if (bb.containsPoint(nsp))
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
		p = this->getParent()->convertToWorldSpace(p);
		// p = this->convertToNodeSpace(p);
		return !(p.x < 0 || p.y<0 || p.x > stageSize.width || p.y > stageSize.height);
	}
	float BaseNode::getAlpha()
	{
		return getAlpha(this);
	};
	void BaseNode::setAlpha(cocos2d::Node * node, float op)
	{
		if (!node)return;
		op = op<0 ? 0 : op>1 ? 1 : op;
		int ops = op * 255;
		node->setOpacity(ops);
		if (ISTYPE(MovieClip, node)){
			ISTYPE(MovieClip, node)->container->setOpacity(ops);
		}
	};
	float BaseNode::getAlpha(cocos2d::Node * node)
	{
		if (!node)return 0;
		int ops = node->getOpacity();
		float alpha = (double)ops / 255 * 10;
		alpha = std::floor(alpha + 0.5) / 10;
		return alpha;
	};

	void BaseNode::setSize(float w, float h, bool draw)
	{
		this->setContentSize(Size(w, h));
		if (draw)drawRange();
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
		Size size = this->getContentSize();
		size.width = w;
		this->setContentSize(size);
	};
	void BaseNode::setHeight(float h){
		Size size = this->getContentSize();
		size.height = h;
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
		this->setScaleX((w / size.width));
		//size.width = w;
		//this->setContentSize(size);
	};
	void BaseSprite::setHeight(float h){
		Size size = this->getContentSize();
		this->setScaleY((h / size.height));
		//size.height = h;
		//this->setContentSize(size);
	};
	void BaseSprite::onEnter()
	{
		if (this->mouseEnabled || this->mouseEnabled)
			addEventNode(this);
		Sprite::onEnter();
	};
	void BaseSprite::onExit()
	{
		removeEventNode(this);
		Sprite::onExit();
	};
	void BaseNode::addChild(Node *child){
		Node::addChild(child);
		if (basePoint.x && basePoint.y)
			child->setPosition(basePoint);
	};
	void BaseNode::addChild(Node * child, int localZOrder){
		Node::addChild(child, localZOrder);
		if (basePoint.x && basePoint.y)
			child->setPosition(basePoint);
	};
	void BaseNode::addChild(Node* child, int localZOrder, int tag){
		Node::addChild(child, localZOrder, tag);
		if (basePoint.x && basePoint.y)
			child->setPosition(basePoint);
	};
	void BaseNode::addChild(Node* child, int localZOrder, const std::string &name){
		Node::addChild(child, localZOrder, name);
		if (basePoint.x && basePoint.y)
			child->setPosition(basePoint);
	};
	void changeAnchorPoint(Node * node, float xy){
		changeAnchorPoint(node, Vec2(xy, xy));
	}
	void changeAnchorPoint(Node * node, const Vec2& xy){
		Vec2 absPos1 = node->getAnchorPointInPoints();
		node->setAnchorPoint(xy);
		Vec2 absPos2 = node->getAnchorPointInPoints();
		Vec2 dif = absPos2 - absPos1;
		dif = Vec2(node->getScaleX()*dif.x, node->getScaleY()*dif.y);
		node->setPosition(node->getPosition() + dif);

		//this->getAnchorPoint();
		//if (xy == 0.5){
		//Vec2 orgpos = this->getPosition();
		//Vec2 pos = this->convertToWorldSpace(Vec2(0, 0));
		//this->setAnchorPoint(Vec2(xy, xy));
		//Vec2 pos1 = this->convertToNodeSpace(pos);
		//this->setPosition(orgpos+pos1);
		//}
		//else{
		//}
	};
	void BaseNode::changeAnchorPoint(float xy){
		std::changeAnchorPoint(this, xy);
	};
	void BaseNode::drawRange()
	{
		std::drawRange(this, Color4F::GREEN);
		//DrawNode* drawNode = DrawNode::create();
		//this->addChild(drawNode);
		//Vec2 pos = this->getPosition();
		//Size size = this->getContentSize();
		//Vec2 dest(pos.x + size.width, pos.y + size.height);
		//drawNode->drawRect(Vec2(0, 0), size, Color4F::GREEN);
		//logInfo(getNamePath(this), this->getPosition(), &this->convertToWorldSpace(this->getPosition()), &(Vec2)this->getContentSize());
		////drawNode->setScaleX(this->getScaleX());
		////drawNode->setScaleY(this->getScaleY());
	};
	void BaseSprite::drawRange()
	{
		std::drawRange(this, Color4F::YELLOW);
		//DrawNode* drawNode = DrawNode::create();
		//this->addChild(drawNode);
		//Vec2 pos = this->getPosition();
		//Size size = this->getContentSize();
		//Vec2 dest(pos.x + size.width, pos.y + size.height);
		//drawNode->drawRect(Vec2(0, 0), size, Color4F::YELLOW);
		////drawNode->setScaleX(this->getScaleX());
		////drawNode->setScaleY(this->getScaleY());
		//logInfo(getNamePath(this), this->getPosition(), &this->convertToWorldSpace(this->getPosition()),&(Vec2)this->getContentSize());
	};
	void BaseLayer::drawRange()
	{
		std::drawRange(this, Color4F::YELLOW);
		//DrawNode* drawNode = DrawNode::create();
		//this->addChild(drawNode);
		//Vec2 pos = this->getPosition();
		//Size size = this->getContentSize();
		//Vec2 dest(pos.x + size.width, pos.y + size.height);
		//drawNode->drawRect(Vec2(0, 0), size, Color4F::YELLOW);
		//logInfo(getNamePath(this), this->getPosition(), &this->convertToWorldSpace(this->getPosition()), &(Vec2)this->getContentSize());
		////drawNode->setScaleX(this->getScaleX());
		////drawNode->setScaleY(this->getScaleY());
	};
	MouseEvent::MouseEvent(MouseEventType mouseEventCode) : cocos2d::EventMouse(mouseEventCode), idx(0), target(NULL), processed(false), enode(NULL)
	{
	};
	MouseEvent::MouseEvent(cocos2d::EventMouse * e, bool incSub) :EventMouse(*e), idx(0), target(NULL), processed(false), enode(NULL)
	{
		Node * node = e->getCurrentTarget();
		hitTest(node, incSub);
	};
	MouseEvent::MouseEvent(cocos2d::EventMouse * e) :EventMouse(*e), idx(0), target(NULL), processed(false), enode(NULL)
	{
		hitTest(e->getCurrentTarget(), false);
	};

	void  MouseEvent::hitTest(Node *node, bool incSub)
	{
		if (ISTYPE(EventNode, node))
		{
			EventNode *n = ISTYPE(EventNode, node);
			if (n->hitTest(this))
				currentTargets.push(node);
		}
		if (incSub && node->isVisible() && node->getChildrenCount())
		{
			int len = node->getChildrenCount();
			Vector<Node*>& nodes = node->getChildren();
			for (int i = 0; i < len; i++)
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
			if (n->hitTest(this))
				currentTargets.push(node);
			if (n->mouseChildren && node->isVisible() && node->getChildrenCount())
			{
				int len = node->getChildrenCount();
				Vector<Node*>& nodes = node->getChildren();
				for (int i = 0; i < len; i++)
				{
					node = nodes.at(i);
					hitTest(node, level + 1);
				}
			}
		}
		else
		{
			if (!node->getName().empty() && std::hitTest(node, this))
				currentTargets.push(node);
			if (node->isVisible() && node->getChildrenCount())
			{
				int len = node->getChildrenCount();
				Vector<Node*>& nodes = node->getChildren();
				for (int i = 0; i < len; i++)
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
		enode = ISTYPE(EventNode, this->target);
	};
	bool MouseEvent::hasNext(){
		if (currentTargets.size() > idx){
			setCurrentTarget(currentTargets.at(idx));
			processed = false;
			idx++;
			return true;
		}
		return false;
	};
	int MouseEvent::getIndex(const string & name)
	{
		int len = currentTargets.size();
		for (int i = 0; i < len; i++)
		{
			if (currentTargets.at(i)->getName() == name)
				return i;
		}
		return -1;
	};
	void MouseEvent::remove(int i){
		if (currentTargets.size() > i)
			currentTargets.remove(i);
	};


	std::MouseEvent buildMouseEvent(EventMouse * e)
	{
		std::MouseEvent  me(e);
		//Node * n = e->getCurrentTarget();
		int l = EventNodes.size();
		Vec2 ep = e->getLocationInView();
		for (int i = l - 1; i >= 0; i--)
		{
			EventNode * _node = EventNodes.at(i);
			Node *node = ISTYPE(Node, _node);
			//if (n == node)continue;
			if (!node)continue;
			if (!node->isVisible()) continue;
			if (std::hitTest(node, ep))
				me.currentTargets.push(node);
		}
		return me;
	};

	std::MouseEvent BaseNode::buildMouseEvent(Node * node, cocos2d::EventMouse::MouseButton mouseButton, cocos2d::EventMouse::MouseEventType mouseEventType)
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
	void BaseNode::enableMouseHandler(bool listen)
	{
		if (!this->mouseEnabled)
		{
			this->setMouseEnabled(true);
		}
		if (listen && listener == NULL)
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
	void BaseLayer::enableMouseHandler()
	{
		if (!this->mouseEnabled)
		{
			this->setMouseEnabled(true);
			this->setMouseEnabled(true);
		}
		if (listener == NULL)
		{
			listener = cocos2d::EventListenerMouse::create();
			listener->onMouseDown = CC_CALLBACK_1(BaseNode::mouseDownHandler, this);
			listener->onMouseUp = CC_CALLBACK_1(BaseNode::mouseUpHandler, this);
			listener->onMouseMove = CC_CALLBACK_1(BaseNode::mouseMoveHandler, this);
			listener->onMouseScroll = CC_CALLBACK_1(BaseNode::mouseScrollHandler, this);
			getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
		}
	};
	void BaseLayer::disableMouseHandler(){
		if (listener){
			getEventDispatcher()->removeEventListener(listener);
			delete listener;
			listener = NULL;
		}
	}

	void BaseLayer::enableKeyHandler()
	{
		const auto keyboardListener = cocos2d::EventListenerKeyboard::create();
		keyboardListener->onKeyPressed = CC_CALLBACK_2(BaseNode::keyBoardPressedHandler, this);
		keyboardListener->onKeyReleased = CC_CALLBACK_2(BaseNode::keyBoardReleasedHandler, this);
		getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	}
	bool BaseNode::isVisible(){
		return getNodeVisible(this);
	};
	bool BaseSprite::isVisible(){
		return getNodeVisible(this);
	};
	bool BaseLayer::isVisible(){
		return getNodeVisible(this);
	};

	bool EventNode::isMouseChildren(){
		if (!this->mouseChildren)return false;
		Node *node = ISTYPE(Node, this);
		while (node){
			EventNode *enode = ISTYPE(EventNode, node);
			if (!enode->mouseChildren)return false;
			node = ISTYPE(Node, node->getParent());
		}
		return true;
	};
	bool EventNode::isMouseEnabled(){
		if (!this->mouseEnabled)return false;
		Node *node = ISTYPE(Node, this);
		while (node){
			EventNode *enode = ISTYPE(EventNode, node);
			if (!enode->mouseEnabled)return false;
			node = ISTYPE(Node, node->getParent());
		}
		return true;
	};
	bool EventNode::isMouseFlag(){
		if (!this->mouseFlag)return false;
		Node *node = ISTYPE(Node, this);
		while (node){
			EventNode *enode = ISTYPE(EventNode, node);
			if (!enode->mouseFlag)return false;
			node = ISTYPE(Node, node->getParent());
		}
		return true;
	};

	void EventNode::setNodeMouse(Node * n, int type, bool v, bool setSub){
		if (!n)
			return;
		EventNode *en = ISTYPE(EventNode, n);
		if (en){
			if (type == 1)en->mouseChildren = v;
			else if (type == 2)en->mouseEnabled = v;
			else if (type == 3)en->mouseFlag = v;
		}
		else if (!setSub){
			return;
		}
		Vector<Node*>& chlds = n->getChildren();
		int len = chlds.size();
		for (int i = 0; i < len; i++)
			setNodeMouse(ISTYPE(Node, chlds.at(i)), type, v, setSub);
	};

	void EventNode::setMouseChildren(bool v, bool setSub){
		setNodeMouse(ISTYPE(Node, this), 1, v, setSub);
	}

	void EventNode::setMouseEnabled(bool v, bool setSub){
		setNodeMouse(ISTYPE(Node, this), 2, v, setSub);
	};
	void EventNode::setMouseFlag(bool v, bool setSub){
		setNodeMouse(ISTYPE(Node, this), 3, v, setSub);
	};

	void EventNode::keyBoardPressedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
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
	void EventNode::keyBoardReleasedHandler(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
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
	void EventNode::mouseDownHandler(cocos2d::EventMouse* event)
	{
		//loginfo("mouseDown",event); 
		if (!std::hitTest(event->getCurrentTarget(), event))return;
		logInfo("hitTest true : mouse in ", event->getCurrentTarget()->getName());
		Node * node = event->getCurrentTarget();
		Event::Type tp = event->getType();
		logInfo("event targetNamePath", getNamePath(node));
		cocos2d::EventMouse::MouseButton mouseButton = event->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)
			rightMouseDownHandler(event);
	};
	void EventNode::mouseUpHandler(cocos2d::EventMouse* event)
	{
		if (!std::hitTest(event->getCurrentTarget(), event))return;
		cocos2d::EventMouse::MouseButton mouseButton = event->getMouseButton();
		//loginfo("mouseUp", event);
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)rightMouseUpHandler(event);
	};

	void EventNode::mouseMoveHandler(cocos2d::EventMouse* event)
	{
		if (!this->hitTest(event))return;
		//logInfo("mouseMoved", event->getCursorX(), event->getCursorY());
	};
	void EventNode::mouseScrollHandler(cocos2d::EventMouse* event)
	{
		if (!this->hitTest(event))return;
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
	string getNamePath(Node *node){
		if (!node)return "";
		string name = node->getName();
		while (node->getParent())
		{
			node = node->getParent();
			name = node->getName() + "." + name;
		}
		return name;
	};
	void  getChildNodes(Common::Array<Node*> & res, Node *node){
		if (!node)return;
		Vector<Node*>& chds = node->getChildren();
		string nam = getNamePath(node);
		int len = node->getChildrenCount();
		for (int i = 0; i < len; i++)
			res.push(chds.at(i));
		for (int i = 0; i < len; i++)
		{
			Node *snode = chds.at(i);
			if (snode->getChildrenCount())
				getChildNodes(res, snode);
		}
	};
	Common::Array<Node*>  getChildNodes(Node *node){
		Common::Array<Node*> res;
		getChildNodes(res, node);
		return res;
	};

	void EventNode::printNodePos(Node *node){
		logInfo(node->getName() + ".isVisible", node->isVisible());
		logInfo(node->getName() + ".position", node->getPosition());
		logInfo(node->getName() + ".worldPos", node->convertToWorldSpace(node->getPosition()));
		if (ISTYPE(EventNode, node)){
			EventNode *en = ISTYPE(EventNode, node);
			logInfo(node->getName() + ".mouseEnabled", en->mouseEnabled);
		}
		if (ISTYPE(BaseNode, node)){
			BaseNode *en = ISTYPE(BaseNode, node);
			logInfo(node->getName() + ".alpha", en->getAlpha());
		}
	}
	void EventNode::printNodePos(MovieClipSub *node){
		logInfo(node->getName() + ".isVisible", node->isVisible());
		logInfo(node->getName() + ".position", node->getPosition());
		logInfo(node->getName() + ".worldPos", node->convertToWorldSpace(node->getPosition()));
		if (ISTYPE(EventNode, node)){
			EventNode *en = ISTYPE(EventNode, node);
			logInfo(node->getName() + ".mouseEnabled", en->mouseEnabled);
		}
		logInfo(node->getName() + ".alpha", node->getAlpha());
	}

	void EventNode::printChildNodes(Node *node){
		if (!node){
			node = ISTYPE(Node, this);
		};
		if (!node)return;
		Vector<Node*>& chds = node->getChildren();
		string nam = getNamePath(node);
		for (int i = 0; i < node->getChildrenCount(); i++)
		{
			Node *snode = chds.at(i);
			logInfo(nam + "[" + Common::String(i) + "] ", getNamePath(snode));
			logInfo(nam + "[" + Common::String(i) + "].pos ", node->convertToWorldSpace(node->getPosition()));
			if (snode->getChildrenCount())
				printChildNodes(snode);
		}
	};
	string EventNode::getNamePath(Node *node)
	{
		return std::getNamePath(node ? node : ISTYPE(Node, this));
	};

	void EventNode::logInfo(string mouseType, cocos2d::EventMouse* event)
	{
		if (!debug)return;
		cocos2d::EventMouse::MouseButton mouseButton = event->getMouseButton();
		logInfo(mouseType, event->getCursorX(), event->getCursorY());
		logInfo("         mouseButton", (int)mouseButton);

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
	bool EventNode::debug = true;
	void EventNode::logInfo(const string & label, const cocos2d::Point & pos, const cocos2d::Point* pos2, const cocos2d::Point* pos3, const cocos2d::Point* pos4)
	{
		if (!debug)return;
		if (pos4)
			CCLOG("%s x=%f y=%f [%f,%f] [%f,%f] [%f,%f]", label.c_str(), pos.x, pos.y, pos2->x, pos2->y, pos3->x, pos3->y, pos4->x, pos4->y);
		else if (pos3)
			CCLOG("%s x=%f y=%f [%f,%f] [%f,%f]", label.c_str(), pos.x, pos.y, pos2->x, pos2->y, pos3->x, pos3->y);
		else if (pos2)
			CCLOG("%s x=%f y=%f [%f,%f]", label.c_str(), pos.x, pos.y, pos2->x, pos2->y);
		else
			CCLOG("%s x=%f y=%f", label.c_str(), pos.x, pos.y);
		if (gLog)writeLog(label + " x=" + Common::String(pos.x) + " y=" + Common::String(pos.y), 1);
	};
	void EventNode::logInfo(const string & label, const cocos2d::Size &pos)
	{
		if (!debug)return;
		CCLOG("%s w=%f h=%f", label.c_str(), pos.width, pos.height);
		if (gLog)writeLog(label + " w=" + Common::String(pos.width) + " h=" + Common::String(pos.height), 1);
	};
	void EventNode::logInfo(const string & label, float x, float y)
	{
		if (!debug)return;
		CCLOG("%s x=%f y=%f", label.c_str(), x, y);
		if (gLog)writeLog(label + " x=" + Common::String(x) + " y=" + Common::String(y), 1);
	};
	void EventNode::logInfo(const string & label, int x)
	{
		if (!debug)return;
		CCLOG("%s=%d ", label.c_str(), x);
		if (gLog)writeLog(label + "=" + Common::String(x), 1);
	};
	void EventNode::logInfo(const string & label, int x, int y)
	{
		if (!debug)return;
		CCLOG("%s[%d , %d]", label.c_str(), x, y);
		if (gLog)writeLog(label + " x=" + Common::String(x) + " y=" + Common::String(y), 1);
	};
	void EventNode::logInfo(const string & label, int i, Vec2 p)
	{
		if (!debug)return;
		CCLOG("%s[%i] x=%f , y=%f", label.c_str(), i, p.x, p.y);
		if (gLog)writeLog(label + " x=" + Common::String(p.x) + " y=" + Common::String(p.y), 1);
	};
	void EventNode::logInfo(const string & label1, const string & label2, const string & label3, const string & label4, const string & label5, const string & label6)
	{
		if (!debug)return;
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

	void EventNode::logInfo(const string & label, dragonBones::Transform const * t)
	{
		if (!debug)return;
		CCLOG("%s[%f , %f]  [sx=%f sy=%f r=%f]", label.c_str(), t->x, t->y, t->scaleX, t->scaleX, t->rotation);
	};
	void EventNode::logInfo(const string & label, dragonBones::Transform * t)
	{
		logInfo(label, (dragonBones::Transform const *)(t));
	};
	void EventNode::logInfo(const string & label, dragonBones::Transform t)
	{
		logInfo(label, (dragonBones::Transform const *)(&t));
	};
	////////////////////////////////////////////////////
	void BaseNode::setLocalZOrder(int localZOrder)
	{
		Node::setLocalZOrder(localZOrder);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkZOrder)
				it->first->setLocalZOrder(localZOrder);
		}
	};
	void BaseNode::setGlobalZOrder(float globalZOrder)
	{
		Node::setGlobalZOrder(globalZOrder);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkZOrder)
				it->first->setGlobalZOrder(globalZOrder);
		}
	};
	void BaseNode::setScaleX(float scaleX)
	{
		Node::setScaleX(scaleX);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkScale)
				it->first->setScaleX(scaleX);
		}
	};
	void BaseNode::setScaleY(float scaleY)
	{
		Node::setScaleY(scaleY);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkScale)
				it->first->setScaleY(scaleY);
		}
	};
	void BaseNode::setScaleZ(float scaleZ)
	{
		Node::setScaleZ(scaleZ);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkScale)
				it->first->setScaleZ(scaleZ);
		}
	};
	void BaseNode::setScale(float scale)
	{
		Node::setScale(scale);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkScale)
				it->first->setScale(scale);
		}
	};
	void BaseNode::setScale(float scaleX, float scaleY)
	{
		Node::setScale(scaleX, scaleY);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkScale)
				it->first->setScale(scaleX, scaleY);
		}
	};
	void BaseNode::setPosition(const Vec2 &position)
	{
		Node::setPosition(position);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkPos)
				it->first->setPosition(position);
		}
	};
	void BaseNode::setNormalizedPosition(const Vec2 &position)
	{
		Node::setNormalizedPosition(position);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkPos)
				it->first->setNormalizedPosition(position);
		}
	};
	void BaseNode::setPosition(float x, float y)
	{
		Node::setPosition(x, y);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkPos)
				it->first->setPosition(x, y);
		}
	};
	void BaseNode::setPositionX(float x)
	{
		Node::setPositionX(x);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkPos)
				it->first->setPositionX(x);
		}
	};
	void BaseNode::setPositionY(float y)
	{
		Node::setPositionY(y);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkPos)
				it->first->setPositionY(y);
		}
	};
	void BaseNode::setPosition3D(const Vec3& position)
	{
		Node::setPosition3D(position);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkPos)
				it->first->setPosition3D(position);
		}
	};
	void BaseNode::setPositionZ(float positionZ)
	{
		Node::setPositionZ(positionZ);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkPos)
				it->first->setPositionZ(positionZ);
		}
	};
	void BaseNode::setSkewX(float skewX)
	{
		Node::setSkewX(skewX);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkSekw)
				it->first->setSkewX(skewX);
		}
	};
	void BaseNode::setSkewY(float skewY)
	{
		Node::setSkewY(skewY);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkSekw)
				it->first->setSkewY(skewY);
		}
	};
	void BaseNode::setAnchorPoint(const Vec2& anchorPoint)
	{
		Node::setAnchorPoint(anchorPoint);
		//Vec2 absPos1 = Node::getAnchorPointInPoints();
		//Node::setAnchorPoint(anchorPoint);
		//Vec2 absPos2 = Node::getAnchorPointInPoints();
		//Node::setPosition(Node::getPosition() + absPos2 - absPos1);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkAnchorPoint)
				it->first->setAnchorPoint(anchorPoint);
		}
	};
	void BaseNode::setContentSize(const Size& contentSize)
	{
		Node::setContentSize(contentSize);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkSize)
				it->first->setContentSize(contentSize);
		}
	};
	void BaseNode::setVisible(bool visible)
	{
		Node::setVisible(visible);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkSize)
				it->first->setVisible(visible);
		}
	};
	void BaseNode::setRotation(float rotation)
	{
		Node::setRotation(rotation);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkRotation)
				it->first->setRotation(rotation);
		}
	};
	void BaseNode::setRotation3D(const Vec3& rotation)
	{
		Node::setRotation3D(rotation);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkRotation)
				it->first->setRotation3D(rotation);
		}
	};
	void BaseNode::setRotationQuat(const Quaternion& quat)
	{
		Node::setRotationQuat(quat);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkRotation)
				it->first->setRotationQuat(quat);
		}
	};
	void BaseNode::setRotationSkewX(float rotationX)
	{
		Node::setRotationSkewX(rotationX);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkRotation)
				it->first->setRotationSkewX(rotationX);
		}
	};
	void BaseNode::setRotationSkewY(float rotationY)
	{
		Node::setRotationSkewY(rotationY);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkRotation)
				it->first->setRotationSkewY(rotationY);
		}
	};
	void BaseNode::setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
	{
		Node::setCascadeOpacityEnabled(cascadeOpacityEnabled);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkAlpha)
				it->first->setCascadeOpacityEnabled(cascadeOpacityEnabled);
		}
	};

	void BaseNode::setOpacityModifyRGB(bool value)
	{
		Node::setOpacityModifyRGB(value);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkAlpha)
				it->first->setOpacityModifyRGB(value);
		}
	};
	void BaseNode::setOpacity(GLubyte opacity)
	{
		Node::setOpacity(opacity);
		for (LinkRuleMap::iterator it = linkNodes.begin(); it != linkNodes.end(); it++)
		{
			if (it->second & LinkNodeType::LinkAlpha)
				it->first->setOpacity(opacity);
		}
	};
	void BaseNode::setAlpha(float op)
	{
		setAlpha(this, op);
	};
	void BaseNode::addLinkNode(BaseNode * node, int linkFlag)
	{
		//Node * _node = node; 
		addLinkNodeFlag(node, linkFlag);
	};
	void BaseNode::addLinkNodeFlag(BaseNode * node, int linkFlag)
	{
		LinkRuleMap::iterator it = linkNodes.find(node);
		if (it == linkNodes.end())
		{
			linkNodes.insert(LinkRuleMap::value_type(node, linkFlag));
			node->linkParent = this;
		}
		else
			linkNodes[node] = it->second | linkFlag;
		//it = linkBaseNodes.find(this);
		//if (it == linkBaseNodes.end()){
		//	linkBaseNodes.insert(LinkRuleMap::value_type(this, 1));
		//}
	};
	void BaseNode::removeLinkNode(BaseNode * node)
	{
		LinkRuleMap::iterator it = linkNodes.find(node);
		if (it != linkNodes.end())
		{
			linkNodes.erase(node);
			node->setUserObject(NULL);
		}
	};
	void BaseNode::removeLinkNodeFlag(BaseNode * node, int linkFlag)
	{
		LinkRuleMap::iterator it = linkNodes.find(node);
		if (it != linkNodes.end())
		{
			if (it->second & linkFlag)
			{
				int flag = it->second - linkFlag;
				if (flag == 0){
					linkNodes.erase(node);
					node->setUserObject(NULL);
				}
				else{
					linkNodes[node] = it->second - linkFlag;
				}
			}
		}
	};


}
