#ifndef ENGINE_LEVEL_H
#define ENGINE_LEVEL_H
#include "BaseHeaders.h"
#include "RoadLevels_mc.h"

namespace engine{
	class BuildTowerPlace :public MovieClip
	{
	public:
 
		MCCase * placeForBuildCase;
		MCCase * buildPoint;

		BuildTowerPlace(string arm);
	};

	class LevelPointer :public MovieClip
	{
	public:
		MCCase * pointerCase;
		MovieClipSub * fireAnima;
		MovieClipSub * eyesAnima;
		Sprite * mask1;
		Sprite * mask2;
		Sprite * arrow;
		LevelPointer();
		float counter;
		int timer;
		Vec2 myPoint;
		int statusAnima;
	};

	struct Level : public MovieClip{
			World *world;
			Common::Array<MovieClipSub * > decorations;
			Common::Array<MovieClip * > flags;
			Common::Array<BuildTowerPlace * > places;
			Common::Array<LevelPointer * > pointers;
            //Common::Array<TowerPlace * > towerPlace;
			Common::Array<MovieClipSub * > additionallys;
			Level(World *world, string rootPath, string armName, string dbName)  ;
		};
 
} 
#endif

