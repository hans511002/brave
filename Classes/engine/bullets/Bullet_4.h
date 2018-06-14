#ifndef ENGINE_BULLET_4_H
#define ENGINE_BULLET_4_H
#include "Bullet.h" 

namespace engine{
	namespace bullets
	{

		class Bullet_4 :public Bullet
		{
		public:
			float deviation;
			bool effectFlag;

			inline  Bullet_4() :deviation(6) {};

			bool init();

			virtual void update(float dt = 0);
			//void kill();
		};
	}
}
#endif
      
      
      