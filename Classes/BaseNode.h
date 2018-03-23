#ifndef BASE_NODE_SPRITE_H
#define BASE_NODE_SPRITE_H
#include "cocos2d.h"
#include "dragonbones/cocos2d/DBCCRenderHeaders.h"
#include "common/Common.h"
#include "JsonUtil.h"

namespace std {
void setAnchorPoint(cocos2d::Node* node,bool subset=false); 
}

class BaseFuns
{
	public:
	cocos2d::Label* createText(const std::string& string);
	float getStageWidth() const;
	float getStageHeight() const;
};


class BaseNode :public cocos2d::Node, public BaseFuns
{
public:
	bool init();
	
private:

};
class BaseSprite :public cocos2d::Sprite, public BaseFuns
{
public:
	bool init();

private:

};
class BaseLayer : public cocos2d::LayerColor, public BaseFuns
{
protected:
	cocos2d::Sprite* _background;
	virtual void _onStart() = 0;

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

