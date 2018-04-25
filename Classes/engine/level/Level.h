#ifndef ENGINE_LEVEL_H
#define ENGINE_LEVEL_H
#include "BaseHeaders.h"
#include "PointTimer.h"

namespace engine{
   
	class Level : public BaseNode{
		public:
			Common::Array<dragonBones::CCArmatureDisplay * > decorations;
			Common::Array<dragonBones::CCArmatureDisplay * > flags;
			Common::Array<dragonBones::CCArmatureDisplay * > places;
            Common::Array<Sprite * > placeBases;
            //Common::Array<TowerPlace * > towerPlace;
			Common::Array<dragonBones::CCArmatureDisplay * > additionallys;
			Common::Array<PointTimer * > pointers;
 			Level()
			{ 
			};
		};
 
}
#endif

