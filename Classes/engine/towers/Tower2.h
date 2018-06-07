#ifndef ENGINE_TOWERS_TOWER2_H
#define ENGINE_TOWERS_TOWER2_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "engine/mc/mc.h" 

namespace engine
{
    namespace towers
    {
        class Tower2_mc :public BaseNode
        {
        public:  
            MovieClipSub * blockTower;
            MovieClipSub * boneBlock;
            MovieClipSub * selectTower;
            MCCase * towerCase;
            MovieClipSub * sphere1;
            MovieClipSub * sphere1Bullet;
            MovieClipSub * sphere1BulletCont;
            MovieClipSub * sphere2_1;
            MovieClipSub * sphere2_1Bullet;
            MovieClipSub * sphere2_1BulletCont;
            MovieClipSub * sphere2_2;
            MovieClipSub * sphere2_2Bullet;
            MovieClipSub * sphere2_2BulletCont;

            Tower2_mc(); 
        };
        class Tower2 : public Tower
        {
            Tower2();

            bool init();

            void update() ;

        };
    }
}
#endif
