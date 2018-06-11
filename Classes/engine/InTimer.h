#ifndef ENGINE_INTIMER_H
#define ENGINE_INTIMER_H
#include "BaseHeaders.h" 
#include "engine/mc/mc.h"

namespace engine
{
 

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

       virtual  void update(float dt=0);

        void kill() ;

    };
}
#endif
