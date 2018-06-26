#ifndef ENGINE_INDEXES_H
#define ENGINE_INDEXES_H
#include "BaseHeaders.h"

namespace engine
{
    class Indexes :public BaseNode
    {
    public:
        int i;
        World *world;
        MovieClip * container;
        int indexParam;
        float alphaParam;
        string type;//:String = "default";
        float speedX;//:Number = 0;
        float speedY;//:Number = 0;

        Indexes(MovieClip *param1, int param2=0, float param3 = 0);

        virtual void update(float dt = 0);

    };
}
#endif
