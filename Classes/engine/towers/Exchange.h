#ifndef ENGINE_TOWERS_EXCHANGE_H
#define ENGINE_TOWERS_EXCHANGE_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
#include "engine/mc/mc.h" 

namespace engine
{
    namespace towers
    {
        struct Exchange_mc : public MovieClip
        {
           MovieClip* exchangeCase;
        };
        struct Exchange1_mc : public Exchange_mc
        {
            MovieClip* cross;
        };
        class Exchange : public BaseNode
        {
            int i, j;
            //public var tempObject:Object;
            //public var tempObject1:Object;
            MovieClip* container;
            MovieClip* graphicAtMyTower;
            bool dead;
            World* world;
            Tower* myTower;
            bool atTower;

            Exchange(Tower * param1);

            bool init() ;

            void update() ;

            void mouseMoveHandler(cocos2d::Event * param1) ;

            void mouseDownHandler(cocos2d::Event * param1) ;

            void mouseUpHandler(cocos2d::Event * param1) ;

            void rightMouseDownHandler(cocos2d::Event * param1);

            void rightMouseUpHandler(cocos2d::Event * param1);

            void kill()  ;
        };
    }
}
#endif
