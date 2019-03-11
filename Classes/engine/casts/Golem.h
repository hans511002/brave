#ifndef ENGINE_CASTS_GOLEM_H
#define ENGINE_CASTS_GOLEM_H
#include "BaseHeaders.h"
#include "Cast.h"

namespace engine{
 
    namespace    casts
    {
        struct Golem_mc :public MovieClip
        {
            Golem_mc(string path, string arm, string db);
            MovieClipSub * dust1;//:MovieClip;
            MovieClipSub * dust2;//:MovieClip;
        };
        struct Golem1_mc :public Golem_mc
        {
            Golem1_mc();
        };
        struct Golem2_mc :public Golem_mc
        {
            Golem2_mc();
        };
        struct Golem3_mc :public Golem_mc
        {
            Golem3_mc();
        };
        class Golem :public BaseNode
        {
        public:
            int i, j, n;// : int;
            //public var tempObject : Object;
            //public var tempObject1 : Object;
            Golem_mc *container;// : MovieClip;
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

			Vec2 movePos;

            Golem(cocos2d::Point param1, int param2, int param3, bool param4 = true);

			virtual bool init();

			virtual void  update(float dt = 0);

			virtual bool  moveHandler();

			virtual void  directionManage();

			virtual void  scanNextTurn();

			virtual void  attack();

			virtual void  bifurcation();

			virtual void  closeGolem();

			virtual void  kill();
            virtual void remove();

        };
    }
}
#endif

