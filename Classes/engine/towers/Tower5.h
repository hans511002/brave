#ifndef ENGINE_TOWERS_TOWER5_H
#define ENGINE_TOWERS_TOWER5_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "engine/mc/mc.h" 

namespace engine
{
    namespace towers
    { 
        struct Tower5_mc: public MovieClip
        { 
            MovieClip * blockTower ;
            MovieClip * boneBlock; 
            MovieClip * bot;
            MovieClip * towerCase;
            MovieClip * upgr1; 
        };
        class Tower5 : public Tower
        {
            public:
            int upgr1_intervalCounter;//:int;
            int upgr1_intervalTimer;//:int;
            float upgr1_damage;//:Number;
            int soundCounter;//:int = 0;
            int soundTimer;//:int = 5;

            Tower5();

            bool init() ;

            void update();

            void scan();

            void attack() ;

        };
    }
}
#endif

