﻿#ifndef ENGINE_TOWERS_BUILDTOWERMENU_H
#define ENGINE_TOWERS_BUILDTOWERMENU_H
#include "BaseHeaders.h"
#include "Tower.h"
#include "engine/level/Level.h"
 

namespace engine
{
 
    namespace towers
    { 
		class BuildTowerMenu_mc : public MovieClip
		{
		public:
			BuildTowerMenu_mc();
			MovieClipSub * cont;
			MCCase * contBuildTowerMenuCase;
			MCText * contCostTXT;

		};

		class BuildTowerMenu :public BaseNode
		{
		public:
			int i;
			Tower * tempObject; //public var tempObject : Object;
			BuildTowerMenu_mc * container;// public var container : BuildTowerMenu_mc;
			bool dead;// : Boolean;
			bool closeFlag;// : Boolean;
			BuildTowerPlace *  myPlace;// : MovieClip;
			World *world;// : World;

			BuildTowerMenu(BuildTowerPlace *  param1);


			virtual bool init();

			virtual void update(float dt = 0);

			virtual void mouseMoveHandler(cocos2d::EventMouse * event);

			virtual void mouseDownHandler(cocos2d::EventMouse * event);

			virtual void mouseUpHandler(cocos2d::EventMouse * event);

			virtual void monitor();

			virtual void closeMenu();

			virtual void kill();
		};
    }
}
#endif

