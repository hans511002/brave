#ifndef ENGINE_SAVEDCASTTIME_H
#define ENGINE_SAVEDCASTTIME_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"
#include "MainClass.h"
#include "World.h"
#include "JsonUtil.h"
 
namespace engine
{ 
    struct SavedCastTime_mc : public MovieClip
    {
        MovieClipSub * cont;
        ui::Text * contNoteTXT;

        SavedCastTime_mc() ;
    };
    class SavedCastTime :public BaseNode
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

        SavedCastTime_mc * container;

        SavedCastTime(string param1, int param2);

		bool init();

		void update();

		void kill();

	};
}
#endif

