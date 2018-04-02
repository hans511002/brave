#ifndef ENGINE_CASTS_ICEMAN_H
#define ENGINE_CASTS_ICEMAN_H
#include "BaseHeaders.h"
#include "Cast.h"

namespace engine{
    class World;
    namespace    casts
    {
        struct Iceman_mc
        {
            MovieClip * container ;
            
        }
        class Iceman extends Sprite
        {
        public:
            int  i ;//public var i:int;
            int  j ;//public var j:int;
            //Object  tempObject ;//public var tempObject:Object;
            //Object  tempObject1 ;//public var tempObject1:Object;
            MovieClip * container ;//public var container:MovieClip;
            cocos2d::Point  this_pt ;//public var this_pt:Point;
            //cocos2d::Point  enemy_pt ;//public var enemy_pt:Point;
            World *world;
            string  direction ;//public var direction:String = "无";
            int  movePhase ;//public var movePhase:int = 1;
            float  speedK ;//public var speedK:Number;
            float  speedKSave ;//public var speedKSave:Number;
            float  radius ;//public var radius:Number;
            int  road ;//public var road:int;
            Common::Array<cocos2d::Point> * roadMap;
            bool  dead ;//public var dead:Boolean;
            bool  openFlag ;//public var openFlag:Boolean;
            MovieClip * blow ;//public var blow:MovieClip;
            int  liveCounter ;//public var liveCounter:int;
            //public var soundTimerMove:Timer;
            //public var soundChannelMove:SoundChannel;
            int  voiceCounter ;//public var voiceCounter:int = 10;
            int  rotationTimer ;//public var rotationTimer:int = 4;
            String  rotateFlag ;//public var rotateFlag:String;
            Iceman * brother;
            int  roadAnimaTimer ;//public var roadAnimaTimer:int = 7;
            int  roadAnimaCounter ;//public var roadAnimaCounter:int = 0;

        Iceman(cocos2d::Point param1,int param2,int param3,bool param4 = true);

        void  init() ;

        void  update() ;

        void  moveHandler() ;

        void  directionManage() ;

        void  scanNextTurn() ;

        void  attack() ;

        void  bifurcation() ;

        void  soundTimerManageMove(param1:Boolean) ;

        void  soundTimerMoveFunk(event:TimerEvent) ;

        void  kill() ;

    }
}
}
#endif
