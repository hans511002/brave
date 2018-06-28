#ifndef ENGINE_TOWERS_H
#define ENGINE_TOWERS_H
#include "BaseHeaders.h" 
#include "engine/units/Unit.h" 
#include "engine/units/Unit_mc.h"
#include "engine/level/Level.h"

namespace engine
{

    namespace bullets
    {
        struct BulletSphereTower_mc;
    };

    namespace towers
    {
        struct TowerBase_mc :public MovieClip
        {
            MovieClip * blockTower;
            MovieClip * boneBlock;
            MCCase * towerCase;
            Tower * myParent;
            MCMask * selectTower;
            TowerBase_mc(string rootPath, string armName, string dbName, string defAniName = "");
        };
        struct ShootingTurnStack
        {
            int value;
            string name;
            Common::Array<ShootingTurnStack> d;
            inline ShootingTurnStack() :value(0) {}
            inline ShootingTurnStack & operator[](int i)
            {
                return d[i];
            };
            int size()
            {
                return d.size();
            }
            inline int operator=(int i)
            {
                return value = i;
            };
            inline  operator int()
            {
                if(value)return value;
				if (!name.empty())return name.size();
				return d.size();
            };
            inline string operator=(string i)
            {
                return name = i;
            };
            inline  operator string()
            {
                return name;
            };

            // prefix
            inline int operator++() { return ++value; }
            inline int operator--() { return --value; }

            // suffix
            inline int operator++(int) { int old = value; value++; return (old); }
            inline int operator--(int) { int old = value; value--; return  (old); }

            inline int operator==(std::string s) { return name == s; }
            inline int operator==(int s) { return value == s; }

            inline ShootingTurnStack &splice(int s, int n = 1)
            {
                while(n)
                {
                    d.remove(s);
                    n--;
                }
                return *this;
            }
        };

        class Tower :public engine::ShootBase
        {
        public:
            int i, j;
            BulletSphereTower_mc * tempObject2 ;
            //public var tempObject:Object;
            //public var tempObject1:Object;
            //public var tempObject2:Object;
            //public var tempObject3:Object;
            //public var tempObject4:Object;
            TowerBase_mc *container;// public var container : MovieClip;
            BuildTowerPlace * myPlace;// :MovieClip;
            MovieClip * buildAnima; //public var buildAnima:MovieClip;
            Common::Array<string>  spheresStack; //public var spheresStack:Array;
            Common::Array<int>  slotsStack; //public var slotsStack:Array;
            float damage; //public var damage:Number;
            int  intervalCounter; //public var intervalCounter:int = 0;
            int  intervalTimer; //public var intervalTimer:int;
            bool  dead; //public var dead:Boolean;
            World * world;//public var world:World;
            int  towerType; //public var towerType:int = 0;
            int  correctYGrPos; //public var correctYGrPos:int;
            Common::Array<ShootingTurnStack >  shootingTurnStack; //public var shootingTurnStack:Array;
            string shootingSphere;//public var shootingSphere:String;
            Common::Array<BulletBase_mc *>  shootinAttackStack; //public var shootinAttackStack:Array;
            Common::Array<units::Unit *>  listOfTargets; //public var listOfTargets:Array;
            //cocos2d::Vec2  this_pt; //public var this_pt:Point;
            cocos2d::Vec2  enemy_pt; //public var enemy_pt:Point;
            cocos2d::Vec2  shoot_pt; //public var shoot_pt:Point;
            units::Unit * enemyTarget;//public var enemyTarget:Object;
            cocos2d::Vec2 testTarget;// public var testTarget:Object;
            bool  greenFlag; //public var greenFlag:Boolean;
            bullets::BulletSphereTower_mc * sphereBullet1; //public var sphereBullet1:MovieClip;
            bullets::BulletSphereTower_mc * sphereBullet2; //public var sphereBullet2:MovieClip;
            bullets::BulletSphereTower_mc * sphereBullet3; //public var sphereBullet3:MovieClip;
            bullets::BulletSphereTower_mc * sphereBullet4; //public var sphereBullet4:MovieClip;
            int  upgradeTypeAdd; //public var upgradeTypeAdd:int = 0;
            bool  blockTowerFlag; //public var blockTowerFlag:Boolean;
            int  sphereVisibleTimer; //public var sphereVisibleTimer:int = 18;
            bool  exchangeFlag; //public var exchangeFlag:Boolean;
            bool  autoBuild; //public var autoBuild:Boolean;

            float upgr1_damage;// 5 6 7 8

            Tower();

			virtual bool init();
            virtual void update(float dt = 0);

			virtual void scan();

			virtual void attack();

			virtual void scanAtRadius();

			virtual int spheresManage(string param1, string param2 = "", int param3 = 0);

			virtual void shootingStackManage(string param1, string param2);

			virtual void prepareSpheresGraphic();

			virtual void prepareSpheresGraphicAid(int param1);

			virtual void addBuildAnima();

			virtual void blockTowerFunk();

			virtual void scanBlock();

			virtual void scanAndPush();

			virtual void towerGetSphereManage(string param1, string param2);

			virtual void kill();

        };

    }
}
#include "Tower1.h" 
#include "Tower2.h" 
#include "Tower3.h" 
#include "Tower4.h" 
#include "Tower5.h" 
#include "Tower6.h" 
#include "Tower7.h" 
#include "Tower8.h" 
#include "Exchange.h" 


#endif
