#ifndef ENGINE_BULLET_4_H
#define ENGINE_BULLET_4_H
#include "Bullet.h" 

namespace engine{
    namespace bullets{ 
		
        class Bullet_4 :public Bullet
        {
        public:
            float deviation;
            bool effectFlag;

            Bullet_4():deviation(6){};

            bool init( ) ;

            void update() ;
            void kill();
        };
    }
}
#endif
      
      
      