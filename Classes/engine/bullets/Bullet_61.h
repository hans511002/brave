#ifndef ENGINE_BULLET_61_H
#define ENGINE_BULLET_61_H
#include "Bullet.h" 

namespace engine
{
    namespace bullets
    {
        
        class Bullet_61 : public Bullet
        {
        public:
            Bullet_61();

            bool init() ;

virtual             void update(float dt=0) ;

        };
    }
}
#endif
