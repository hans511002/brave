#ifndef ENGINE_INTIMER_H
#define ENGINE_INTIMER_H
#include "BaseHeaders.h" 
#include "engine/mc/mc.h"

namespace engine
{
	class World;
	struct AnimUpgrade_mc :public MovieClip
    { 
        AnimUpgrade_mc()
        {
            return;
        }// end function
    }
    class InTimer :public MovieClip
    {
    public:
        int i;
        //public var tempObject:Object;
        int counter;//public var counter:int = 0;
        string type;
        bool dead;
        World* world;

        InTimer(string param1);

        void update();

        void kill() ;

    };
}
#endif
