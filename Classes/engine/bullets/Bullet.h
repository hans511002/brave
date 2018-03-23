#ifndef ENGINE_BULLETS_H
#define ENGINE_BULLETS_H
#include "BaseHeaders.h"
#include "engine/World.h"
#include "MainClass.h"
#include "engine/units/Unit.h"
#include "engine/towers/Tower.h"


namespace engine{
    namespace bullets{ 
  
        class Bullet :public BaseNode
        {
        public:
            int i,j;
            //public var tempObject:Object;
            //public var tempObject1:Object;
            //public var tempObject2:Object;
            bool dead;//public var dead:Boolean;
            World * world;//public var world:World;
            MovieClip * container;//public var container:MovieClip;
            Unit* enemyTarget;//public var enemyTarget:Object;
            float damage;//public var damage:Number;
            int bulletType;//public var bulletType:int;
            Tower * whoShoot;//public var whoShoot:Object;
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
            Unit * testTarget;//public var testTarget:Object;
            Tower * testTower;//public var testTower:Object;
            bool greenFlag;//public var greenFlag:Boolean;

            Bullet();

            bool init( );

            void update();

            void defaultIndex() ; 

            void scanAtRadius() ; 

            void kill()  ;

    }
}
}
#endif
