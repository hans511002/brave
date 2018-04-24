#ifndef ENGINE_CASTS_CAST_H
#define ENGINE_CASTS_CAST_H
#include "BaseHeaders.h"
#include "engine/mc/mc.h"
namespace engine{
    class World;
    namespace    casts
    {
        struct  MoveCast_mc :public BaseNode
        {
            BaseSprite * sprite;
            int type;
            int currentFrame;
            MoveCast_mc(int _type) :sprite(NULL), type(_type)
            {
                BaseNode::init();
                this->autorelease();
                gotoAndStop(1);
            }
            void gotoAndStop(int idx){
                this->currentFrame = idx;
                char path[64];
                if (type == 1){
                sprintf(path, "cast/MoveCast_mc/MoveGolem_mc%2d.png", idx);
                }
                else if (type == 2){
                    sprintf(path, "cast/MoveCast_mc/MoveIceman_mc%2d.png", idx);
                }
                else if (type == 3){
                    sprintf(path, "cast/MoveCast_mc/MoveAir_mc%2d.png", idx);
                }
                if (sprite == NULL)
                {
                    sprite = new BaseSprite(path);
                }
                else
                {
                    sprite->setTexture(path);
                }
            }
        };
        class Cast : public BaseNode
        {
        public:
            int i, j, n;
            //        public var tempObject:Object;
            //        public var tempObject1:Object;
            //        public var tempObject2:Object;
            cocos2d::Point tempObject;
            cocos2d::Point tempObject3;
            MoveCast_mc * container;// : MovieClip;
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
