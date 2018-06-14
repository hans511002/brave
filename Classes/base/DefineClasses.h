#ifndef DEFINECLASSES_H
#define DEFINECLASSES_H
 
namespace engine
{
	class WorldInterface;
	class Waves;
	class Feature;
	class World;
	class Level;
	class BuildTowerPlace;
	class LevelPointer;
	class GetSphere;
	struct Hint_mc;
	class ShootBase;
	struct CastMask_mc;
	struct MouseStatusMC;



	namespace  towers
	{
		class Tower;
		class TowerMenu;
		class BuildTowerMenu;
		class UltraTowerMenu;
		class TowerRadius_mc;
		class Exchange;
	};
	namespace units
	{
		class Unit;
		struct RoadsignFire_mc;
		struct RoadsignIce_mc;
		struct RoadsignStone_mc;
		struct RoadsignLevin_mc;
		struct Unit_34;
	};
	namespace  casts
	{
		class Cast;
	};
	namespace  decoration
	{
		class Decoration;
	};
	namespace  bullets
	{
		class Bullet;

	}
};
namespace screens
{
	class LevelsMenu;
	class MiddleScreen;
};
namespace sys
{
	class SaveBox;
	class BezierBox;
};



using namespace engine;
using namespace engine::towers;
using namespace engine::units;
using namespace engine::casts;
using namespace engine::bullets;
using namespace screens;
using namespace sys;
using namespace engine;
#endif //  
 