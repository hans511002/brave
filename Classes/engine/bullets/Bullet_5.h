#ifndef ENGINE_BULLET_5_H
#define ENGINE_BULLET_5_H
#include "Bullet.h" 

namespace engine{
    namespace bullets{

		
		class Bullet_5 :public Bullet
		{
		public:

			float correct;//:Number;
			bool rotationFlag;//:Boolean;
			cocos2d::Point enemyStartPoint;//:Point;
			int enemyRoad;//:int;
			int enemyWay;
			float enemyPath;//:Number;
			float enemySpeed;//:Number;
			MovieClip *shadow;
			float deviation;
			bool effectFlag;

			Bullet_5();

			virtual bool init();

			virtual void update(float dt = 0);
			virtual void remove();
		};
    }
}
#endif
