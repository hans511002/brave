#ifndef ENGINE_BULLETS_H
#define ENGINE_BULLETS_H
#include "BaseHeaders.h"
//#include "engine/units/Unit.h"
//#include "engine/towers/Tower.h"
#include "base/mc.h"

namespace engine{
 
	namespace units{
	class Unit;
	};
	namespace towers{
		class Tower;
	} ;
    namespace bullets{
		struct BulletBase_mc :public MovieClip
        {
            float distX;
            float distY;
            int counter;
			inline BulletBase_mc(string rootPath, string armName, string dbName, string defAniName = "") :distX(0), distY(0), counter(0)
				,MovieClip(rootPath, armName, dbName, defAniName)
			{
			};
			inline BulletBase_mc(World * world, string rootPath, string armName, string dbName, string defAniName = "") :distX(0), distY(0), counter(0)
				, MovieClip(world, rootPath, armName, dbName, defAniName)
			{
			};

        };
        struct BulletSphereTower_mc : public MovieClip
        {
            MovieClip * cont;
			int counter;
            virtual void gotoAndStop(int cur);
			BulletSphereTower_mc();
        };
        struct BulletFireTower_mc :public BulletBase_mc 
        {
            BulletFireTower_mc();
        };
        struct BulletIceTower_mc :public BulletBase_mc 
		{
            BulletIceTower_mc();
		};
		struct BulletStoneTower_mc :public BulletBase_mc 
		{
            BulletStoneTower_mc();
		};
		struct BulletLevinTower_mc :public BulletBase_mc 
		{
            BulletLevinTower_mc();
		};
		struct BulletTower5_1_mc :public BulletBase_mc 
        {
            BulletTower5_1_mc();
        }; 
		struct BulletTower5_1Bang_mc :public MovieClip
        {
			BulletTower5_1Bang_mc(World * world);
        };
        struct BulletTower5_1Smoke1_mc :public MovieClip
        {
			BulletTower5_1Smoke1_mc(World * world);
        };
        struct BulletTower51_1_mc:public BulletBase_mc 
        {
            BulletTower51_1_mc();
        };
        struct BulletTower51_2_mc:public BulletBase_mc 
        {
            BulletTower51_2_mc();
        };
        struct BulletTower6_1_mc : public BulletBase_mc 
        {
            BulletTower6_1_mc();
        };
        struct BulletTower6_2_mc : public BulletBase_mc 
        {
            BulletTower6_2_mc();
        };
        struct BulletTower61_mc : public BulletBase_mc 
        {
            BulletTower61_mc();
        };
		struct BulletTower7_smoke_mc :public MovieClip
        {
			 BulletTower7_smoke_mc(World * world);
        };
        struct BulletTower71_mc: public BulletBase_mc 
        {
            BulletTower71_mc();
        };
        struct BulletTower7_mc :public BulletBase_mc 
        {
            MovieClipSub * ball;
            MovieClipSub * smoke;
            MovieClipSub * smokeCont1;
            MovieClip  * smokeCont2;

            BulletTower7_mc();
        };
        
       
        struct BulletTower8_1_mc : public BulletBase_mc 
        {
            BulletTower8_1_mc();
        };
        struct BulletTower8_2_mc : public BulletBase_mc 
        {
            BulletTower8_2_mc();
        };
        struct BulletTower81_mc : public BulletBase_mc 
        {
            BulletTower81_mc();
        };
        
        
        
		
        struct UnitShadow_mc:public BaseSprite
        {
            UnitShadow_mc();
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
			BulletBase_mc * container;//public var container:MovieClip;
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
            Vec2 testTarget;//public var testTarget:Object;
            towers::Tower * testTower;//public var testTower:Object;
            bool greenFlag;//public var greenFlag:Boolean;
			bool effectFlag;

            Bullet();

            bool init();

virtual             void update(float dt=0);

            void defaultIndex();

            void scanAtRadius();

            void kill();

        };
    }
}
using namespace engine::bullets;
#include "engine/bullets/Bullet_1.h"
#include "engine/bullets/Bullet_2.h"
#include "engine/bullets/Bullet_3.h"
#include "engine/bullets/Bullet_4.h"
#include "engine/bullets/Bullet_5.h"
#include "engine/bullets/Bullet_6.h"
#include "engine/bullets/Bullet_7.h"
#include "engine/bullets/Bullet_8.h"
#include "engine/bullets/Bullet_51.h"
#include "engine/bullets/Bullet_61.h"
#include "engine/bullets/Bullet_81.h"

#endif
