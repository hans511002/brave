#ifndef ENGINE_TOWERS_TOWER3_H
#define ENGINE_TOWERS_TOWER3_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "Tower2.h"

namespace engine
{
    namespace towers
    {
		class Tower3_mc :public Tower2_mc
		{
		public:
			//MovieClip * blockTower;
			//MovieClip * boneBlock;
			//MovieClipSub * selectTower;
			//MCCase * towerCase;
			//MovieClipSub * sphere1;
			//MovieClip * sphere1Bullet;
			//MovieClipSub * sphere1BulletCont;

			//MovieClipSub * sphere2_1;
			//BulletSphereTower_mc * sphere2_1Bullet;
			//MovieClipSub * sphere2_1BulletCont;
			//MovieClipSub * sphere2_2;
			//BulletSphereTower_mc * sphere2_2Bullet;
			//MovieClipSub * sphere2_2BulletCont;

			MovieClipSub * sphere3_1;
			BulletSphereTower_mc * sphere3_1Bullet;
			MovieClipSub * sphere3_1BulletCont;
			MovieClipSub * sphere3_2;
			BulletSphereTower_mc * sphere3_2Bullet;
			MovieClipSub * sphere3_2BulletCont;
			MovieClipSub * sphere3_3;
			BulletSphereTower_mc * sphere3_3Bullet;
			MovieClipSub * sphere3_3BulletCont;


			inline Tower3_mc(string rootPath, string armName, string dbName, string defAniName = "") : Tower2_mc(rootPath, armName, dbName, defAniName){};
			Tower3_mc();
		};
		class Tower3 :public  Tower
		{
		public:
			Tower3();

			virtual bool init();

			virtual void update(float dt = 0);
		};
    }
}
#endif
