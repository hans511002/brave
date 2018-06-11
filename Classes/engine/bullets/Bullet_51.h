#ifndef ENGINE_BULLET_51_H
#define ENGINE_BULLET_51_H
#include "Bullet.h" 

namespace engine{
	namespace bullets{

		class Bullet_51 : public Bullet
		{
		public:
			bool turnFlag;//:Boolean;
			Common::Array<BulletBase_mc*> listOfAnimation;

			Bullet_51();

			bool init();

virtual 			void update(float dt=0);
		};
	}
}
#endif

