#ifndef ENGINE_TOWERS_TOWER3_H
#define ENGINE_TOWERS_TOWER3_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
 
namespace engine
{
    namespace towers
    {
		class Tower3_mc :public TowerBase
		{
		public:
			//MovieClip * blockTower;
			//MovieClip * boneBlock;
			//MovieClipSub * selectTower;
			//MCCase * towerCase;
			//MovieClipSub * sphere1;
			//MovieClip * sphere1Bullet;
			//MovieClipSub * sphere1BulletCont;
			MovieClipSub * sphere2_1;
			MovieClip * sphere2_1Bullet;
			MovieClipSub * sphere2_1BulletCont;
			MovieClipSub * sphere2_2;
			MovieClip * sphere2_2Bullet;
			MovieClipSub * sphere2_2BulletCont;
			MovieClipSub * sphere3_1;
			MovieClip * sphere3_1Bullet;
			MovieClipSub * sphere3_1BulletCont;
			MovieClipSub * sphere3_2;
			MovieClip * sphere3_2Bullet;
			MovieClipSub * sphere3_2BulletCont;
			MovieClipSub * sphere3_3;
			MovieClip * sphere3_3Bullet;
			MovieClipSub * sphere3_3BulletCont;


			Tower3_mc();
		};
        class Tower3 :public  Tower
        {
        public:
            Tower3();

            bool init();

            void update();
        };
    }
}
#endif
