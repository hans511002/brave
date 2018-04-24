﻿#ifndef ENGINE_TOWERS_TOWER2_H
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
            Tower2_mc()
            {
                return;
            }// end function
            bool init();
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