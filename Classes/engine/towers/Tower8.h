#ifndef ENGINE_TOWERS_TOWER8_H
#define ENGINE_TOWERS_TOWER8_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "engine/mc/mc.h" 

namespace engine
{
    namespace towers
    {
        struct Tower8_mc: public MovieClip
        {
        MovieClip * blockTower;
        MovieClip *  boneBlock;
        MovieClip *  cont1;
        MovieClip *  cont2;
        MovieClip *  cont3;
        MovieClip *  cont4;
        MovieClip *  cont5;
        MovieClip *  cont6;
        MovieClip *  fireLight1;
        MovieClip *  towerCase;
        };

        class Tower8 : public Tower
        {
            bool shootFlag;
            int upgr1_intervalCounter;//:int = 1;
            int upgr1_intervalTimer;
            float upgr1_damage;
            int soundCounter;//:int = 0;
            int soundTimer;//:int = 5;

            Tower8();

            bool init();

            void update() ;

            void scan();

            void attack();

        };
    }
}
#endif
