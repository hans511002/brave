#ifndef BASE_HEADER_H
#define BASE_HEADER_H
#include "cocos2d.h"
#include "JsonUtil.h"
#include "dragonBones/cocos2dx/CCDragonBonesHeaders.h"
#include "dragonbones/DragonBonesHeaders.h"
#include "tinyxml2/tinyxml2.h"
#include "ui/CocosGUI.h"
#include "common/Common.h" 
#include "BaseNode.h"
#include "cocos-ext.h"
#include "engine/mc/mc.h"
USING_NS_CC;
using namespace dragonBones;
using namespace tinyxml2;

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

