#ifndef ENGINE_BULLETS_H
#define ENGINE_BULLETS_H
#include "BaseHeaders.h"
#include "engine/units/Unit.h"
#include "engine/towers/Tower.h"
#include "base/mc.h"

namespace engine{
    class World;
	class units::Unit;
    namespace bullets{

        struct BulletSphereTower_mc
        {
            float distX;
            float distY;
            int counter;
        };
        struct BulletFireTower_mc :public BulletSphereTower_mc  ,public MovieClip
        {
            BulletFireTower_mc();
        };
        struct BulletIceTower_mc :public BulletSphereTower_mc,public MovieClip
		{
            BulletIceTower_mc();
		};
		struct BulletStoneTower_mc :public BulletSphereTower_mc,public MovieClip
		{
            BulletStoneTower_mc();
		};
		struct BulletLevinTower_mc :public BulletSphereTower_mc,public MovieClip
		{
            BulletLevinTower_mc();
		};
		struct BulletTower5_1_mc :public BulletSphereTower_mc,public MovieClip
        {
            BulletTower5_1_mc();
        }; 
		struct BulletTower5_1Bang_mc :public BulletSphereTower_mc,public MovieClip
        {
            BulletTower5_1Bang_mc();
        };
        struct BulletTower5_1Smoke1_mc :public MovieClip
        {
            inline BulletTower5_1Smoke1_mc(World * world):MovieClip(world,"sphere/","BulletTower5_1Smoke1_mc","BulletTower5_1Smoke1_mc");
        };
        struct BulletTower51_1_mc:public BulletSphereTower_mc,public MovieClip
        {
            BulletTower51_1_mc();
        };
        struct BulletTower51_2_mc:public BulletSphereTower_mc,public MovieClip
        {
            BulletTower51_2_mc();
        };
        struct BulletTower6_1_mc : public BulletSphereTower_mc,public MovieClip
        {
            BulletTower6_1_mc();
        };
        struct BulletTower6_2_mc : public BulletSphereTower_mc,public MovieClip
        {
            BulletTower6_2_mc();
        };
        struct BulletTower61_mc : public BulletSphereTower_mc,public MovieClip
        {
            BulletTower61_mc();
        };
        struct BulletTower7_mc :public BulletSphereTower_mc,public MovieClip
        {
            // ball:MovieClip;
            // smoke:MovieClip;
            MovieClip * ball;
            MovieClip * smoke;
            MovieClip * smokeCont1;
            MovieClip * smokeCont2;
            BulletTower7_mc();
        };
        
        struct BulletTower7_smoke_mc :public BulletSphereTower_mc,public MovieClip
        {
            BulletTower7_smoke_mc();
        };
        struct BulletTower71_mc: public BulletSphereTower_mc,public MovieClip
        {
            BulletTower71_mc();
        };
        struct BulletTower8_1_mc : public BulletSphereTower_mc,public MovieClip
        {
            BulletTower8_1_mc();
        };
        struct BulletTower8_2_mc : public BulletSphereTower_mc,public MovieClip
        {
            BulletTower8_2_mc();
        };
        struct BulletTower81_mc : public BulletSphereTower_mc,public MovieClip
        {
            BulletTower81_mc();
        };
        
        
        
		
        struct UnitShadow_mc:public MovieClip
        {
            
        };
        class Bullet :public BaseNode
        {
        public:
            int i, j;
            //public var tempObject:Object;
            //public var tempObject1:Object;
            //public var tempObject2:Object;
            bool dead;//public var dead:Boolean;
            World * world;//public var world:World;
            MovieClip * container;//public var container:MovieClip;
            units::Unit* enemyTarget;//public var enemyTarget:Object;
            float damage;//public var damage:Number;
            int bulletType;//public var bulletType:int;
            towers::Tower * whoShoot;//public var whoShoot:Object;
            int liveCounter;//public var liveCounter:int;
            int liveTimer;//public var liveTimer:int;
            float distanceX;//public var distanceX:Number;
            float distanceY;//public var distanceY:Number;
            cocos2d::Point this_pt;//public var this_pt:Point;
            cocos2d::Point enemy_pt;//public var enemy_pt:Point;
            int spherePower;//public var spherePower:int;
            int  mainCounter;//public var mainCounter:int = 0;
            int changeIndex;//public var changeIndex:int;
            float radius;//public var radius:Number;
            units::Unit * testTarget;//public var testTarget:Object;
            towers::Tower * testTower;//public var testTower:Object;
            bool greenFlag;//public var greenFlag:Boolean;

            Bullet();

            bool init();

            void update();

            void defaultIndex();

            void scanAtRadius();

            void kill();

        };
    }
}
using namespace engine::bullets;
#endif
