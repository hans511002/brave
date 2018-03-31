﻿#ifndef ENGINE_CASTS_GOLEM_H
#define ENGINE_CASTS_GOLEM_H
#include "BaseHeaders.h"
#include "Cast.h"

namespace engine{
    class World;
    namespace    casts
    {
        struct Golem1_mc :public BaseNode
        {

        };
        struct Golem2_mc :public BaseNode
        {

        };        
        struct Golem3_mc :public BaseNode
        {

        };
        class Golem :public BaseNode
        {
        public:
            int i, j, n;// : int;
            //public var tempObject : Object;
            //public var tempObject1 : Object;
            BaseNode *container;// : MovieClip;
            cocos2d::Point this_pt;// : Point;
            cocos2d::Point enemy_pt;// : Point;
            World * world;
            string direction;// : String = "无";
            int movePhase;// : int = 1;
            float speedK;// : Number;
            float speedKSave;// : Number;
            float radius;// : Number;
            int road;// : int;
            Common::Array<cocos2d::Point> *roadMap;
            bool dead;// : Boolean;
            float health;// : Number;
            float healthSave;// : Number;
            bool openFlag;// : Boolean;
            int voiceCounter;// : int = 10;
            Golem * brother;
            int cameraJitterTimer;// : int = 3;
            int cameraJitterCounter;// : int;
            float cameraXOffset;// : Number;
            float cameraYOffset;// : Number;

            Golem(cocos2d::Point param1, int param2, int param3, bool param4 = true);

            bool init();

            void  update();

            void  moveHandler();

            void  directionManage();

            void  scanNextTurn();

            void  attack();

            void  bifurcation();

            void  closeGolem();

            void  kill();

        };
    }
}
#endif
