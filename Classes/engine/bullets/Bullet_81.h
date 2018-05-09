#ifndef ENGINE_BULLET_81_H
#define ENGINE_BULLET_81_H
#include "Bullet.h" 

namespace engine
{
    namespace bullets
    {
        
        class Bullet_81 : public Bullet
        {
        public:
            float hypotenuse;
            float cathetus1;
            float cathetus2;
            float angleAlpha;
            BaseNode *chainTarget;//:Object;

            Bullet_81();

            bool init();

            void update() ;
        };
    }
}
#endif
