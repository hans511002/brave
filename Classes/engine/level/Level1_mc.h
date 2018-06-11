#ifndef ENGINE_LVEL_LEVEL1_H
#define ENGINE_LVEL_LEVEL1_H
#include "BaseHeaders.h"

#include "Level.h"
namespace engine{
	
	class Level1_mc : public Level{
	public:
		MovieClipSub * decoration;
        MovieClipSub * decoration1;
        BaseNode * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		LevelPointer * pointer1;
		Level1_mc(World *world);
		
	};
 
}
#endif

