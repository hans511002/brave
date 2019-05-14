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
			float myWidth;
			float myHeight;

			 Bullet_81();

			virtual bool init();

			virtual void update(float dt = 0);
		};
    }
}
#endif
