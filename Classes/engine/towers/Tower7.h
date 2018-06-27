#ifndef ENGINE_TOWERS_TOWER7_H
#define ENGINE_TOWERS_TOWER7_H
#include "BaseHeaders.h"
#include "engine/towers/Tower.h"  
#include "engine/bullets/Bullet_7.h" 

namespace engine
{
	namespace towers
	{

		struct Tower7_mc : public TowerBase_mc
		{
			MovieClipSub * cont1;
			MovieClipSub * cont2;
			MovieClipSub * cont3;
			MovieClipSub * round1;
			MovieClipSub * round2;
			MovieClipSub * round3;
			MovieClipSub * round4;

			BulletTower71_mc * upgr1_1;
			BulletTower71_mc * upgr1_2;
			BulletTower71_mc * upgr1_3;
			BulletTower71_mc * upgr1_4;
			BulletTower71_mc * upgr1_5;
			BulletTower71_mc * upgr1_6;
			BulletTower71_mc * upgr1_7;
			BulletTower71_mc * upgr1_8;
			Tower7_mc();
		};
		class Tower7 :public Tower
		{
		public:
			BulletTower7_mc* ballAnima;
			int visCounter;// = 0;
			int upgr1_intervalCounter;
			int upgr1_intervalTimer;
			BulletTower71_mc * upgr1_anima;
			int roundCounter;
			int soundCounter;
			int soundTimer;

			Tower7();

			virtual bool init();
			virtual void update(float dt = 0);

			virtual void scan();

			virtual void attack();

		};
	}
}
#endif
