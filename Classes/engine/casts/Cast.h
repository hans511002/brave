#ifndef ENGINE_CASTS_CAST_H
#define ENGINE_CASTS_CAST_H
#include "BaseHeaders.h"
#include "base/mc.h"
namespace engine{
 
    struct CastMask_mc : public MovieClip
    {

        MCCase	* archiveCase;
		MCCase	* castAirCase;
		MCCase	* castGolemCase;
		MCCase	* castIcemanCase;
		MCCase	* fireCase;
		MCCase	* getAllCase;
		MCCase	* iceCase;
		MCCase	* interfaceUpCase;
		MCCase	* levinCase;
		MCCase	* sellCase;
		MCCase	* stoneCase;
        CastMask_mc();

    };
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
			int canselCounter;// = 0;
			int canselTimer;

			Cast() :canselCounter(0), map(NULL), dead(false), container(NULL), canselTimer(5), tempObject3(-1, -1) {   };

			virtual bool init();

			virtual void update(float dt = 0);

			virtual void mouseMoveHandler(cocos2d::EventMouse * param1) {};

			virtual void mouseDownHandler(cocos2d::EventMouse *event) {};

			virtual void mouseUpHandler(cocos2d::EventMouse * event) {};

			virtual bool scanWay();

			virtual void   kill();

		};
    }
}
#include "Air.h"
#include "Iceman.h"
#include "Golem.h"
#include "Cast_1.h"
#include "Cast_2.h"
#include "Cast_3.h"
#endif
