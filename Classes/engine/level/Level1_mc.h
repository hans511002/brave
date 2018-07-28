#ifndef ENGINE_LVEL_LEVEL1_H
#define ENGINE_LVEL_LEVEL1_H
#include "BaseHeaders.h"

#include "Level.h"
namespace engine {

	struct Level1_mc : public Level {
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
	struct Level2_mc : public Level {
	public:
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		LevelPointer * pointer1;
		Level2_mc(World *world);

	};

	struct Level3_mc : public Level {
	public:
		MovieClipSub * decoration;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		MCCase * pumpkin1Case;
		MCCase * pumpkin2Case;
		MCCase * pumpkin3Case;
		Level3_mc(World *world);
	};

	struct Level4_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		MovieClip * flag3;
		MovieClip * flag4;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		Level4_mc(World *world);
	};

	struct Level5_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		Level5_mc(World *world);
	};
	struct Level6_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		MovieClipSub * additionally;

		Level6_mc(World *world);
	};
	struct Level7_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		BuildTowerPlace * place10;
		LevelPointer * pointer1;

		Level7_mc(World *world);
	};
	struct Level8_mc : public Level {
		MovieClipSub * decoration;
		MovieClipSub * decoration1;
		MovieClipSub * decoration2;
		MovieClipSub * decoration3;
		MCCase * decorationCase;
		MCCase * decoration1Case;
		MCCase * decoration2Case;
		MCCase * decoration3Case;
		MCCase * decoration4Case;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		BuildTowerPlace * place10;
		BuildTowerPlace * place11;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		Level8_mc(World *world);
	};
	struct Level9_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		MovieClip * flag3;
		MovieClip * flag4;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		BuildTowerPlace * place10;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		Level9_mc(World *world);
	};
	struct Level10_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		MovieClip * flag3;
		MovieClip * flag4;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		BuildTowerPlace * place10;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		Level10_mc(World *world);
	};
	struct Level11_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		BuildTowerPlace * place10;
		BuildTowerPlace * place11;
		LevelPointer * pointer1;
		LevelPointer * pointer2;
		MovieClipSub * additionally;

		Level11_mc(World *world);
	};
	struct Level12_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		BuildTowerPlace * place10;
		BuildTowerPlace * place11;
		BuildTowerPlace * place12;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		Level12_mc(World *world);
	};
	struct Level13_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		BuildTowerPlace * place10;
		BuildTowerPlace * place11;
		BuildTowerPlace * place12;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		MovieClipSub * additionally;
		Level13_mc(World *world);
	};
	struct Level14_mc : public Level {
		MovieClipSub * decoration;
		MCCase * decorationCase;
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		BuildTowerPlace * place10;
		BuildTowerPlace * place11;
		LevelPointer * pointer1;
		LevelPointer * pointer2;

		MovieClipSub * additionally;
		Level14_mc(World *world);
	};
	struct Level15_mc : public Level {
		MovieClip * flag1;
		MovieClip * flag2;
		BuildTowerPlace * place1;
		BuildTowerPlace * place2;
		BuildTowerPlace * place3;
		BuildTowerPlace * place4;
		BuildTowerPlace * place5;
		BuildTowerPlace * place6;
		BuildTowerPlace * place7;
		BuildTowerPlace * place8;
		BuildTowerPlace * place9;
		BuildTowerPlace * place10;
		BuildTowerPlace * place11;
		BuildTowerPlace * place12;
		BuildTowerPlace * place13;
		BuildTowerPlace * place14;
		BuildTowerPlace * place15;
		LevelPointer * pointer1;
		LevelPointer * pointer2;
		LevelPointer * pointer3;

		MovieClipSub * additionally;
		MovieClipSub * additionally1;
		MovieClipSub * additionally3;

		MovieClipSub * portal;
		Level15_mc(World *world);
	};
}
#endif

