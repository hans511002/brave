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
		Sprite * firel;//2
		Sprite * firer;//1 2 
		Sprite * arrow;

		LevelPointer();
		float counter;
		int timer;
		Vec2 myPoint;
		int statusAnima;
		void resetMask();
		void round(float r=0);
		void gotoAndStop(int c);
	};

	struct Level : public MovieClip{
		float offsetY ;
			World *world;
			Common::Array<MovieClipSub * > decorations;
			Common::Array<MovieClip * > flags;
			Common::Array<BuildTowerPlace * > places;
			Common::Array<LevelPointer * > pointers;
            //Common::Array<TowerPlace * > towerPlace;
			Common::Array<MovieClipSub * > additionallys;
			Level(World *world, string rootPath, string armName, string dbName)  ;
			virtual void setPos();

		};
 
} 
#endif

