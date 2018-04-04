﻿#ifndef ENGINE_BULLET_5_H
#define ENGINE_BULLET_5_H
#include "Bullet.h" 

namespace engine{
    namespace bullets{ 
        struct UnitShadow_mc
        {
        };
        struct BulletTower5_1_mc
        {
        };
        struct BulletStoneTower_mc
        {
        };
        struct BulletTower5_1Bang_mc
        {
        };
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
            UnitShadow_mc *shadow;
            float deviation;
            bool effectFlag;

            Bullet_5():deviation(0){};

            bool init( ) ;

            void update() ;
            void kill();
        };
    }
}
#endif
