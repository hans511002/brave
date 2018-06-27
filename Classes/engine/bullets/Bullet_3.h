#ifndef ENGINE_BULLET_3_H
#define ENGINE_BULLET_3_H
#include "Bullet.h" 

namespace engine{
    namespace bullets{
		
		class Bullet_3 :public Bullet
		{
		public:
			float correct;
			Vec2 enemyStartPoint;
			int enemyRoad;
			int enemyWay;
			float enemyPath;
			float enemySpeed;
			UnitShadow_mc *shadow;//public var shadow:UnitShadow_mc;

			inline    Bullet_3() {
				SET_NODETYPENAME();
			};

			virtual bool init();

			virtual void update(float dt = 0);
			virtual void kill();
		};
    }
}
#endif
    
        