#ifndef ENGINE_BULLET_2_H
#define ENGINE_BULLET_2_H
#include "Bullet.h" 

namespace engine{
    namespace bullets{
        class Bullet_2 :public Bullet
        {
        public:

            Bullet_2(){};

            bool init();

            void update();

        };
    }
}
#endif
   