 
#include "RoadLevels_mc.h"

namespace engine{
	RoadLevels_mc::RoadLevels_mc(int level) :level(level)
	{
		if (level == 1)
		{
			sectors.push(Sector(0, 309 - 46, 247, 46));
			sectors.push(Sector(247 - 46, 309 - 205, 46, 162));
			sectors.push(Sector(247, 309 - 205, 204 - 46, 46));
			sectors.push(Sector(247 + 204 - 92, 0, 46, 150 - 46));
			sectors.push(Sector(247 + 204-46, 0, 416 - 46, 46));
			sectors.push(Sector(247 + 204 + 416 - 138, 46, 46, 203 - 46));
			sectors.push(Sector(247 + 204 + 416-92, 203-46, 218 - 46, 46));
		}
		else if (level == 2) {
		}
		else if (level == 3) {
		}
		else if (level == 4) {
		}
		else if (level == 5) {
		}
		else if (level == 6) {
		}
		else if (level == 7) {
		}
		else if (level == 8) {
		}
		else if (level == 9) {
		}
		else if (level == 10) {
		}
		else if (level == 11) {
		}
		else if (level == 12) {
		}
		else if (level == 13) {
		}
		else if (level == 14) {
		}
		else if (level == 15) {

		}
		init();
	};
    bool RoadLevels_mc::init()
    {
        BaseNode::init();
		int len = sectors.size();
		for (int i = 0; i < len; i++)
		{
			Sector & sec=sectors.at(i);
			BaseNode * node = new BaseNode(sec.w, sec.h, true);
			node->setPosition(sec.x,sec.y);
			node->mouseEnabled=true;
			this->addChild(node);
			node->setName("road");
			segments.push_back(node);
		} 
		if (this->level == 1){
			//this->setContentSize(Size(948,309));
			//this->drawRange();
			this->setPosition(Vec2(-76.4f, Main::SCREEN_HEIGHT - 144.9f - 309));
 		}
		return true;
    };
}
