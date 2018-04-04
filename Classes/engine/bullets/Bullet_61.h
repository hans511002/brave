#ifndef ENGINE_BULLET_61_H
#define ENGINE_BULLET_61_H
#include "Bullet.h" 

namespace engine
{
    namespace bullets
    {
        struct BulletTower61_mc : public MovieClip
        {
            
        };
        class Bullet_61 : public Bullet
        {
        public:
            Bullet_61();

            bool init() ;

            void update() ;

        };
    }
}
#endif
