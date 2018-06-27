#ifndef ENGINE_TOWERS_TOWER1_H
#define ENGINE_TOWERS_TOWER1_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 

namespace engine
{
	namespace towers
	{
		struct Tower1_mc :public TowerBase_mc
		{
		public:
			MovieClipSub * sphere1;
			BulletSphereTower_mc * sphere1Bullet;
			MovieClipSub * sphere1BulletCont;
			inline Tower1_mc(string rootPath, string armName, string dbName, string defAniName = "") : TowerBase_mc(rootPath, armName, dbName, defAniName) {};
			Tower1_mc();
		};
		class Tower1 :public Tower
		{
		public:
			int firstTowerMenuCounter;// = 8;

            Tower1();

			virtual bool init();

			virtual void update(float dt = 0);

		};
	}
}
#endif
