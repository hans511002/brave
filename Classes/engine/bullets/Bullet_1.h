#ifndef ENGINE_BULLET_1_H
#define ENGINE_BULLET_1_H
#include "Bullet.h" 

namespace engine{
    namespace bullets{ 
        class Bullet_1 :public Bullet
        {
        public:
            float shiftX,shiftY;
            int phase1,phase2;

            Bullet_1(){};

            bool init( ) ;

            void update() ;

        }
    }
}
#endif

