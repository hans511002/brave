﻿#ifndef ENGINE_TOWERS_TOWER4_H
#define ENGINE_TOWERS_TOWER4_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 

namespace engine
{
    namespace towers
    {
		struct Tower4_mc : public Tower3_mc
        {
			MovieClipSub * sphere4_1;
			BulletSphereTower_mc * sphere4_1Bullet;
			MovieClipSub * sphere4_1BulletCont;
			MovieClipSub * sphere4_2;
			BulletSphereTower_mc * sphere4_2Bullet;
			MovieClipSub * sphere4_2BulletCont;
			MovieClipSub * sphere4_3;
			BulletSphereTower_mc * sphere4_3Bullet;
			MovieClipSub * sphere4_3BulletCont;
			MovieClipSub * sphere4_4;
			BulletSphereTower_mc * sphere4_4Bullet;
			MovieClipSub * sphere4_4BulletCont;
			inline Tower4_mc(string rootPath, string armName, string dbName, string defAniName = "") : Tower3_mc(rootPath, armName, dbName, defAniName){};
			Tower4_mc();
        };
        class Tower4 : public Tower
        {
            Tower4();

            bool init();

virtual             void update(float dt=0);

        };
    }
}
#endif
