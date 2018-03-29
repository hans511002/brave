#ifndef ENGINE_TOWERS_TOWERRADIUS_MC_H
#define ENGINE_TOWERS_TOWERRADIUS_MC_H
#include "BaseHeaders.h"
#include "Tower.h"

namespace engine
{
    namespace towers
    {
        class TowerRadius_mc :public BaseSprite{
        public:
            Tower * myTower;
            TowerRadius_mc();
        };
    }
}
#endif
