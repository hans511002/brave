#ifndef ENGINE_BULLET_7_H
#define ENGINE_BULLET_7_H
#include "Bullet.h" 

namespace engine
{
    namespace bullets
    {
        
		class Bullet_7 :public Bullet
		{
		public:
			bool rotationFlag;
			cocos2d::Point enemyStartPoint;
			int enemyRoad;
			int enemyWay;
			float enemyPath;
			float enemySpeed;
			UnitShadow_mc * shadow;
			int correct;

			Bullet_7();

			virtual bool init();

			virtual void update(float dt = 0);

			virtual void kill();

		};
    }
}
#endif
