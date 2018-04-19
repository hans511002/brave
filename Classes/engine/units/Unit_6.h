#ifndef UNITS_UNIT6_H
#define UNITS_UNIT6_H
#include "Unit.h"

namespace engine
{
	class World;
	
	namespace units
	{
		class Unit_6 :public Unit
		{ 
		public:
			Unit_6();

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif
