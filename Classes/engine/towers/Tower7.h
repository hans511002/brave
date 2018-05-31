#ifndef ENGINE_TOWERS_TOWER7_H
#define ENGINE_TOWERS_TOWER7_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "engine/mc/mc.h" 
#include "engine/bullets/Bullet_7.h" 

namespace engine
{
    namespace towers
    {

        struct Tower7_mc : public MovieClip
        {
            MovieClip * blockTower;
            MovieClip * boneBlock;
            MovieClip * cont1;
            MovieClip * cont2;
            MovieClip * cont3;
            MovieClip * round1;
            MovieClip * round2;
            MovieClip * round3;
            MovieClip * round4;
            MovieClip * towerCase;
            BulletTower71_mc * upgr1_1;
            BulletTower71_mc * upgr1_2;
            BulletTower71_mc * upgr1_3;
            BulletTower71_mc * upgr1_4;
            BulletTower71_mc * upgr1_5;
            BulletTower71_mc * upgr1_6;
            BulletTower71_mc * upgr1_7;
            BulletTower71_mc * upgr1_8;
        };
        class Tower7 :public Tower
        {
        public:
            BulletTower7_mc* ballAnima;
            int visCounter;// = 0;
            int upgr1_intervalCounter;
            int upgr1_intervalTimer;
            float upgr1_damage;
            Bullet * upgr1_anima;
            int roundCounter;
            int soundCounter;
            int soundTimer;

            Tower7();

            bool init() ;
            void update();

            void scan();

            void attack();

        };
    }
}
#endif
