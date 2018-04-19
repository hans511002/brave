#ifndef UNITS_UNIT8_H
#define UNITS_UNIT8_H
#include "Unit.h"

namespace engine
{
	class World;
	
	namespace units
	{
		class Unit_8 :public Unit
		{ 
		public:
			Unit_8();

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif
