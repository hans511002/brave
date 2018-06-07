#ifndef ENGINE_TOWERS_TOWER1_H
#define ENGINE_TOWERS_TOWER1_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 

namespace engine
{
    namespace towers
    {
        class Tower1_mc :public MovieClip
        {
        public: 
MovieClip * blockTower;
MovieClip * boneBlock;
MovieClipSub * selectTower;
MCCase * towerCase;
MovieClipSub * sphere1;
MovieClip * sphere1Bullet;
MovieClipSub * sphere1BulletCont;

            Tower1_mc(); 
        };
        class Tower1 :public Tower
        {
        public:
            int firstTowerMenuCounter;// = 8;

            Tower1() :firstTowerMenuCounter(8)
            {
            }// end function

            bool init();

            void update();

        };
    }
}
#endif
