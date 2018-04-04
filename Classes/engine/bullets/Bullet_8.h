#ifndef ENGINE_BULLET_8_H
#define ENGINE_BULLET_8_H
#include "Bullet.h" 

namespace engine
{
    namespace bullets
    {
        struct BulletTower8_1_mc : public MovieClip
        {
            
        };
        
        struct BulletTower8_2_mc : public MovieClip
        {
            
        };
        class Bullet_8 : public Bullet
        {
        public:
             Bullet_8();

            bool init();

            void update();

        };
    }
}
#endif
