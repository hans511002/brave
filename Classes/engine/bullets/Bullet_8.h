#ifndef ENGINE_BULLET_8_H
#define ENGINE_BULLET_8_H
#include "Bullet.h" 

namespace engine
{
    namespace bullets
    {
        
        class Bullet_8 : public Bullet
        {
        public:
			    Bullet_8();

            bool init();

virtual             void update(float dt=0);

        };
    }
}
#endif
