#ifndef ENGINE_LEVEL_H
#define ENGINE_LEVEL_H
#include "BaseHeaders.h"

namespace engine{
	class BuildTowerPlace :public MovieClip
	{
	public:
		MCCase * placeForBuildCase;
		Sprite * buildPoint;
		BuildTowerPlace(string arm);
	};

	class LevelPointer :public MovieClip
	{
	public:
		MCCase * pointerCase;
		MovieClipSub * fireAnima;
		MovieClipSub * eyesAnima;
		MCCase * mask1;
		MCCase * mask2;
		LevelPointer();
		int counter;
		int timer;
		Vec2 myPoint;
		int statusAnima;
	};

	class Level : public MovieClip{
		public:
			World *world;
			Common::Array<MovieClipSub * > decorations;
			Common::Array<MovieClip * > flags;
			Common::Array<BuildTowerPlace * > places;
			Common::Array<LevelPointer * > pointers;
            //Common::Array<TowerPlace * > towerPlace;
			Common::Array<MovieClipSub * > additionallys;
			inline Level(World *world, string rootPath, string armName, string dbName) :MovieClip(rootPath, armName, dbName), world(world) {};
		};
 
} 
#endif

