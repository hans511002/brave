#ifndef ENGINE_SAVEDCASTTIME_H
#define ENGINE_SAVEDCASTTIME_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"
#include "MainClass.h"
#include "World.h"
#include "JsonUtil.h"

namespace engine
{ 
    class SavedCastTime :public cocos2d::Sprite
    {
	public:
		int i, j;
        //public var tempObject:Object;
        //public var container:SavedCastTime_mc;
		bool dead;
        string type;
        int savedFrames;
		World *world;
		int *counter ;
		int timer = 90;

        SavedCastTime(string param1, int param2)
        {
           //this->addEventListener(Event.ADDED_TO_STAGE,this->init);
           this->type = param1;
           this->savedFrames = param2;
        }// end function

		bool init();

		void update();

		void kill();

	};
}
#endif

