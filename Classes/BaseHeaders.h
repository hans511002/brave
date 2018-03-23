#ifndef BASE_HEADER_H
#define BASE_HEADER_H
#include "cocos2d.h"
#include "JsonUtil.h"
#include "dragonbones/cocos2d/DBCCRenderHeaders.h"
#include "dragonbones/DragonBonesHeaders.h"
#include "ui/CocosGUI.h"
#include "common/Common.h"
#include "animation/MovieClip.h" 
#include "BaseNode.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_DB;

inline static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

namespace std{
double const PI = 3.14159265;
inline float random(){ return cocos2d::rand_0_1(); }

}

#endif

