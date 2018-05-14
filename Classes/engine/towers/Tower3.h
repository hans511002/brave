#ifndef ENGINE_TOWERS_TOWER3_H
#define ENGINE_TOWERS_TOWER3_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "engine/mc/mc.h" 

namespace engine
{
    namespace towers
    {
        class Tower3_mc :public MovieClip
        {
        public: 
             MovieClip * blockTower;
             MovieClip * boneBlock;
             MovieClip * selectTower;
             MovieClip * sphere1;
             MovieClip * sphere2_1;
             MovieClip * sphere2_2;
             MovieClip * sphere3_1;
             MovieClip * sphere3_2;
             MovieClip * sphere3_3;
             MovieClip * towerCase;
            
            Tower2_mc()
            {
                return;
            }// end function
            bool init();
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
