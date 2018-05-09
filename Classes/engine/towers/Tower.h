﻿#ifndef ENGINE_TOWERS_H
#define ENGINE_TOWERS_H
#include "BaseHeaders.h"
#include "engine/units/Unit.h" 

namespace engine
{
    class World;
    namespace towers
    {
        
        class Tower :public BaseNode
        {
        public:
            int i, j;
            //public var tempObject:Object;
            //public var tempObject1:Object;
            //public var tempObject2:Object;
            //public var tempObject3:Object;
            //public var tempObject4:Object;
            MovieClip *container;// public var container : MovieClip;
            Sprite * myPlace;// :MovieClip;
            MovieClip * buildAnima; //public var buildAnima:MovieClip;
            Common::Array<string>  spheresStack; //public var spheresStack:Array;
            Common::Array<int>  slotsStack; //public var slotsStack:Array;
            float damage; //public var damage:Number;
            float radius; //public var radius:Number;
            int  intervalCounter; //public var intervalCounter:int = 0;
            int  intervalTimer; //public var intervalTimer:int;
            bool  dead; //public var dead:Boolean;
            World * world;//public var world:World;
            int  towerType; //public var towerType:int = 0;
            int  correctYGrPos; //public var correctYGrPos:int;
            Common::Array<Common::Array<int> >  shootingTurnStack; //public var shootingTurnStack:Array;
            string shootingSphere;//public var shootingSphere:String;
            Common::Array<>  shootinAttackStack; //public var shootinAttackStack:Array;
            Common::Array<units::Unit *>  listOfTargets; //public var listOfTargets:Array;
            cocos2d::Vec2  this_pt; //public var this_pt:Point;
            cocos2d::Vec2  enemy_pt; //public var enemy_pt:Point;
            cocos2d::Vec2  shoot_pt; //public var shoot_pt:Point;
            units::Unit * enemyTarget;//public var enemyTarget:Object;
            units::Unit * testTarget;// public var testTarget:Object;
            bool  greenFlag; //public var greenFlag:Boolean;
            BulletSphereTower_mc * sphereBullet1; //public var sphereBullet1:MovieClip;
            BulletSphereTower_mc * sphereBullet2; //public var sphereBullet2:MovieClip;
            BulletSphereTower_mc * sphereBullet3; //public var sphereBullet3:MovieClip;
            BulletSphereTower_mc * sphereBullet4; //public var sphereBullet4:MovieClip;
            int  upgradeTypeAdd; //public var upgradeTypeAdd:int = 0;
            bool  blockTowerFlag; //public var blockTowerFlag:Boolean;
            int  sphereVisibleTimer; //public var sphereVisibleTimer:int = 18;
            int  fireBulletCounter; //public var fireBulletCounter:int = 0;
            int  iceBulletCounter; //public var iceBulletCounter:int = 0;
            int  levinBulletCounter; //public var levinBulletCounter:int = 0;
            bool  exchangeFlag; //public var exchangeFlag:Boolean;
            bool  autoBuild; //public var autoBuild:Boolean;

            Tower()
            {
                //this->spheresStack = [];
                //this->shootingTurnStack = [null, null, null, null];
                //this->shootinAttackStack = [];
                //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
                return;
            }// end function

            bool init();
            void update();

            void scan();

            void attack();

            void scanAtRadius();

            int spheresManage(string param1, string param2 = "", int param3=0);  
            
            void shootingStackManage(string param1,string param2);
            
            void prepareSpheresGraphic();
            
            void prepareSpheresGraphicAid(int param1) ;
            
            void addBuildAnima() ;
            
            void blockTowerFunk() ;
            
            void scanBlock() ;
            
            void scanAndPush() ;
            
            void towerGetSphereManage(string param1,string param2);
            
            void kill();

        };

    }
}
#endif
