#ifndef BASE_HEADER_H
#define BASE_HEADER_H
#include "cocos2d.h"
#include "dragonbones/cocos2d/DBCCRenderHeaders.h"
#include "common/Common.h"
#include "engine/xml/XmlConfigParser.h"
#include "JsonUtil.h"

inline static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

#endif

