#ifndef ENGINE_LEVEL_H
#define ENGINE_LEVEL_H
#include "BaseHeaders.h"

namespace engine{
   
	class Level : public MovieClip{
		public:
			Common::Array<MovieClipSub * > decorations;
			Common::Array<MovieClip * > flags;
			Common::Array<MovieClip * > places; 
			Common::Array<MovieClip * > pointers;
            //Common::Array<TowerPlace * > towerPlace;
			Common::Array<MovieClipSub * > additionallys;
			inline Level(string rootPath, string armName, string dbName) :MovieClip(rootPath, armName, dbName) {};
		};
 
} 
#endif

