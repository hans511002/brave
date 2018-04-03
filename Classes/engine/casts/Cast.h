#ifndef ENGINE_CASTS_CAST_H
#define ENGINE_CASTS_CAST_H
#include "BaseHeaders.h"
#include "engine/mc/mc.h"
namespace engine{
    class World;
    namespace    casts
    {

        class Cast : public BaseNode
        {
        public:
            int i, j, n;
            //        public var tempObject:Object;
            //        public var tempObject1:Object;
            //        public var tempObject2:Object;
            cocos2d::Point tempObject;
            cocos2d::Point tempObject3;
            MovieClip * container;// : MovieClip;
            World *world;
            bool dead;
            Common::Array<cocos2d::Point> *  map;
            int canselCounter = 0;
            int canselTimer;

            Cast() :canselCounter(0), canselTimer(5),tempObject3(-1,-1){};

            bool init();

            void   update();

            virtual  void   mouseMoveHandler(cocos2d::Event * param1);

            virtual  void   mouseDownHandler(cocos2d::Event *event);

            virtual void   mouseUpHandler(cocos2d::Event  event);

            bool scanWay();

            void   kill();

        };
    }
}
#endif
