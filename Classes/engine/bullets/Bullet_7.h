#ifndef ENGINE_BULLET_7_H
#define ENGINE_BULLET_7_H
#include "Bullet.h" 

namespace engine
{
    namespace bullets
    {
        struct BulletTower7_mc :public MovieClip
        {
            
        };
        
        struct BulletTower7_smoke_mc :public MovieClip
        {
            
        };
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

            Bullet_7();

            bool init();

            void update();

            void kill() ;

        };
    }
}
#endif
