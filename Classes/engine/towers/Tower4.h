#ifndef ENGINE_TOWERS_TOWER4_H
#define ENGINE_TOWERS_TOWER4_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "engine/mc/mc.h" 

namespace engine
{
    namespace towers
    {
        struct Tower4_mc: public MovieClip
        {
            MovieClip * blockTower ;
            MovieClip * boneBlock;
            MovieClip * selectTower;
            MovieClip * sphere1;
            MovieClip * sphere2_1;
            MovieClip * sphere2_2;
            MovieClip * sphere3_1;
            MovieClip * sphere3_2;
            MovieClip * sphere3_3;
            MovieClip * sphere4_1;
            MovieClip * sphere4_2;
            MovieClip * sphere4_3;
            MovieClip * sphere4_4;
            MovieClip * towerCase;
        };
        class Tower4 : public Tower
        {
            Tower4();

            bool init();

            void update();

        };
    }
}
#endif
