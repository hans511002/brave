#ifndef ENGINE_TOWERS_TOWER6_H
#define ENGINE_TOWERS_TOWER6_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "engine/mc/mc.h" 

namespace engine
{
    namespace towers
    {
        struct Tower6_mc: public MovieClip
        {
            MovieClip * blockTower;
            MovieClip * boneBlock;
            MovieClip * shotAnima;
            MovieClip * towerCase;
        };
        class Tower6 : public Tower
        {
        public:
            int upgr1_intervalCounter, upgr1_intervalTimer;
            float upgr1_damage;
            int soundCounter;
            int soundTimer;

            Tower6();

            void init();

            void update() ;

            void scan() ;

            void addScan();

            void attack();

        };
    }
}
#endif
