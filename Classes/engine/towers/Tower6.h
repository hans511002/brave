﻿#ifndef ENGINE_TOWERS_TOWER6_H
#define ENGINE_TOWERS_TOWER6_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 

namespace engine
{
    namespace towers
    {
		struct Tower6_mc : public TowerBase_mc
        { 
            MovieClip * shotAnima;
		};
        class Tower6 : public Tower
        {
        public:
            int upgr1_intervalCounter, upgr1_intervalTimer;
             int soundCounter;
            int soundTimer;

            Tower6();

            bool init();

            void update() ;

            void scan() ;

            void addScan();

            void attack();

        };
    }
}
#endif
