#ifndef UNITS_UNIT5_H
#define UNITS_UNIT5_H
#include "Unit.h"

namespace engine
{
	class World;
	
	namespace units
	{
		class Unit_5 :public Unit
		{ 
		public:
			Unit_5();

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif 
