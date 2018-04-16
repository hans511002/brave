#ifndef ENGINE_BONUSMONEY_H
#define ENGINE_BONUSMONEY_H
#include "BaseHeaders.h" 
#include "engine/mc/mc.h"

namespace engine
{
	class World;
	struct BonusMoney_mc:public MovieClip
	{
	    MovieClip* cont;
	    ui::Text * noteTXT;
	};

    class BonusMoney :public BaseNode
    {
    public:
        int i;
        bool dead;
        World * world;
        BonusMoney_mc* container;
        int counter;

        BonusMoney();

        bool init();

        void update();

        void kill();

    };
}
#endif
