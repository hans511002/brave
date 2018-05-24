#ifndef ENGINE_CALLDELAY_H
#define ENGINE_CALLDELAY_H
#include "BaseHeaders.h" 
#include "engine/mc/mc.h"
#include "engine/unit/Unit.h"

namespace engine
{
	class World;
	
    class CallDelay :public Object
    {
    public:
        int i;
        //public var tempObject:Object;
        string type;
        int type1;
        int counter;
        bool dead;
        World* world;

        CallDelay(string param1,int param2);

        void update();

        void kill();
    };
}
#endif
 