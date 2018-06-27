#ifndef ENGINE_TOWERS_TOWER8_H
#define ENGINE_TOWERS_TOWER8_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h"  

namespace engine
{
    namespace towers
    {
		struct Tower8_mc : public TowerBase_mc
        { 
			MovieClipSub * cont1;
			MovieClipSub * cont2;
			MovieClipSub * cont3;
			MovieClipSub * cont4;
			MovieClipSub * cont5;
			MovieClipSub * cont6;
			MovieClipSub * fireLight1;
			Tower8_mc();
        };

		class Tower8 : public Tower
		{
		public:
			bool shootFlag;
			int upgr1_intervalCounter;//:int = 1;
			int upgr1_intervalTimer;
			int soundCounter;//:int = 0;
			int soundTimer;//:int = 5;

			Tower8();

			virtual bool init();

			virtual void update(float dt = 0);

			virtual void scan();

			virtual void attack();

		};
    }
}
#endif
