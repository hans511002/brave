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
            dragonBones::DBCCArmatureNode * blockTower;// : MovieClip;
            dragonBones::DBCCArmatureNode * boneBlock;// : MovieClip;
            dragonBones::DBCCArmatureNode * selectTower;// : MovieClip;
            dragonBones::DBCCArmatureNode * sphere1;// : MovieClip;
            dragonBones::DBCCArmatureNode * towerCase;// : MovieClip;

            Tower1_mc()
            {
                return;
            }// end function
            bool init();
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
