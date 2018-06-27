#ifndef ENGINE_BULLET_6_H
#define ENGINE_BULLET_6_H
#include "Bullet.h" 

namespace engine
{
    namespace bullets
    {
        
		class Bullet_6 : public Bullet
		{
		public:
			float damageLittle;
			float hypotenuse;
			float cathetus1;
			float cathetus2;
			float angleAlpha;
			units::Unit * chainTarget;//public var chainTarget:Object;
			int length;
			int unitsCout;

			Bullet_6();

			virtual bool init();

			virtual void update(float dt = 0);

			virtual void attack();

			virtual void close();

		};
    }
}
#endif
