#ifndef ENGINE_BULLET_2_H
#define ENGINE_BULLET_2_H
#include "Bullet.h" 

namespace engine{
    namespace bullets{
		
		class Bullet_2 :public Bullet
		{
		public:

			inline Bullet_2(){
				SET_NODETYPENAME();
			};

			virtual bool init();

			virtual void update(float dt = 0);

		};
    }
}
#endif
   