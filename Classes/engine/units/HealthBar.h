#ifndef UNITS_HEALTHBAR_H
#define UNITS_HEALTHBAR_H
#include "BaseHeaders.h"
namespace engine
{ 
	namespace units
	{
		class HealthBar:public cocos2d::Sprite
		{
		public:
			int counter;
			Sprite*cont;
			HealthBar() :counter(0){ //healthbar/getdamage.png
			};
			CREATE_FUNC(HealthBar);
			bool init();

		};
	}
}
#endif 
