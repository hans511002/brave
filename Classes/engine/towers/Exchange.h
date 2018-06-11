#ifndef ENGINE_TOWERS_EXCHANGE_H
#define ENGINE_TOWERS_EXCHANGE_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
 

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
		public:
            int i, j;
            //public var tempObject:Object;
            //public var tempObject1:Object;
			Exchange1_mc* container;
            MovieClip* graphicAtMyTower;
            bool dead;
            World* world;
            Tower* myTower;
            bool atTower;

            Exchange(Tower * param1);

            bool init() ;

virtual             void update(float dt=0) ;

            void mouseMoveHandler(cocos2d::EventMouse * param1) ;

            void mouseDownHandler(cocos2d::EventMouse * param1) ;

            void mouseUpHandler(cocos2d::EventMouse * param1) ;

            void rightMouseDownHandler(cocos2d::EventMouse * param1);

            void rightMouseUpHandler(cocos2d::EventMouse * param1);

            void kill()  ;
        };
    }
}
#endif
