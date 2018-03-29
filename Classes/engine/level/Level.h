#ifndef ENGINE_LEVEL_H
#define ENGINE_LEVEL_H
#include "BaseHeaders.h"
#include "PointTimer.h"

namespace engine{
   
	class Level : public BaseNode{
		public:
			Common::Array<dragonBones::DBCCArmatureNode * > decorations;
			Common::Array<dragonBones::DBCCArmatureNode * > flags;
			Common::Array<dragonBones::DBCCArmatureNode * > places;
            Common::Array<Sprite * > placeBases;
            //Common::Array<TowerPlace * > towerPlace;
			Common::Array<dragonBones::DBCCArmatureNode * > additionallys;
			Common::Array<PointTimer * > pointers;
			void flagHandler(cocos2d::EventCustom *event);
			Level()
			{ 
			};
		};
 
}
#endif

