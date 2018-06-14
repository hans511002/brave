#ifndef ENGINE_TOWERS_TOWER6_H
#define ENGINE_TOWERS_TOWER6_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 

namespace engine
{
    namespace towers
    {
		struct Tower6_mc : public TowerBase_mc
        { 
            MovieClipSub * shotAnima;
			Tower6_mc();
		};
		class Tower6 : public Tower
		{
		public:
			int upgr1_intervalCounter, upgr1_intervalTimer;
			int soundCounter;
			int soundTimer;

			Tower6();

			bool init();

			virtual void update(float dt = 0);

			void scan();

			void addScan();

			void attack();

		};
    }
}
#endif
