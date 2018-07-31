﻿#ifndef ENGINE_TOWERS_TOWER2_H
#define ENGINE_TOWERS_TOWER2_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "Tower1.h"


namespace engine
{
    namespace towers
    {
		class Tower2_mc :public Tower1_mc
        {
        public:  
			//MovieClip * blockTower;
			//MovieClip * boneBlock;
   //         MovieClipSub * selectTower;
   //         MCCase * towerCase;
   //         MovieClipSub * sphere1;
			//MovieClip * sphere1Bullet;
   //         MovieClipSub * sphere1BulletCont;
            MovieClipSub * sphere2_1;
            BulletSphereTower_mc  * sphere2_1Bullet;
            MovieClipSub * sphere2_1BulletCont;
            MovieClipSub * sphere2_2;
			BulletSphereTower_mc * sphere2_2Bullet;
            MovieClipSub * sphere2_2BulletCont;

			inline Tower2_mc(const string & rootPath, const string &  armName, const string &  dbName, const string &  defAniName = "")
				: Tower1_mc(rootPath, armName, dbName, defAniName){
				init();
			};
			Tower2_mc();
			virtual bool init();
		};
		class Tower2 : public Tower
		{
		public:
			Tower2();

			virtual bool init();

			virtual void update(float dt = 0);

		};
    }
}
#endif
