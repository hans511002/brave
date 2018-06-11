﻿#ifndef ENGINE_CALLDELAY_H
#define ENGINE_CALLDELAY_H
#include "BaseHeaders.h" 
#include "engine/mc/mc.h"
#include "engine/unit/Unit.h"

namespace engine
{
 
	
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

       virtual  void update(float dt=0);

        void kill();
    };
}
#endif
 