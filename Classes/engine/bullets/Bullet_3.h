#ifndef ENGINE_BULLET_3_H
#define ENGINE_BULLET_3_H
#include "Bullet.h" 

namespace engine{
    namespace bullets{
		struct BulletStoneTower_mc :public MovieClip
		{

		};
        class Bullet_3 :public Bullet
        {
        public:
            float correct;
            Vec2 enemyStartPoint;
            int enemyRoad;
            int enemyWay;
            float enemyPath;
            float enemySpeed;
            //public var shadow:UnitShadow_mc;

            Bullet_3(){};

            bool init();

            void update();
            void kill();
        };
    }
}
#endif
    
        