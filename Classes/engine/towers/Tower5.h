#ifndef ENGINE_TOWERS_TOWER5_H
#define ENGINE_TOWERS_TOWER5_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h" 
 
namespace engine
{
    namespace towers
    { 
		struct Tower5_mc : public TowerBase_mc
        {  
			MovieClipSub * bot; 
			MovieClipSub * upgr1;
			Tower5_mc();
        };
		class Tower5 : public Tower
		{
		public:
			int upgr1_intervalCounter;//:int;
			int upgr1_intervalTimer;//:int;
			int soundCounter;//:int = 0;
			int soundTimer;//:int = 5;

			Tower5();

			virtual bool init();

			virtual void update(float dt = 0);

			void scan();

			void attack();

		};
    }
}
#endif

