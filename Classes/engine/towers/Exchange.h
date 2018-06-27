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
			MCCase * exchangeCase;
			 
			inline Exchange_mc() :MovieClip("tower/", "Exchange_mc", "Exchange_mc")
			{
				SET_NODETYPENAME();
				exchangeCase = this->createCase("exchangeCase");
			};
			inline Exchange_mc(string root, string arm, string db, string ani = "") :MovieClip(root, arm, db, ani){};
		};
		struct Exchange1_mc : public Exchange_mc
		{
 			MovieClipSub * cross;
			inline Exchange1_mc() :Exchange_mc("tower/", "Exchange1_mc", "Exchange1_mc")
			{
				SET_NODETYPENAME();
				exchangeCase = this->createCase("exchangeCase");
				cross = this->createMovieClipSub("cross");
			};
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

			virtual bool init();

			virtual void update(float dt = 0);

			virtual void mouseMoveHandler(cocos2d::EventMouse * param1);

			virtual void mouseDownHandler(cocos2d::EventMouse * param1);

			virtual void mouseUpHandler(cocos2d::EventMouse * param1);

			virtual void rightMouseDownHandler(cocos2d::EventMouse * param1);

			virtual void rightMouseUpHandler(cocos2d::EventMouse * param1);

			void kill();
		};
	}
}
#endif
