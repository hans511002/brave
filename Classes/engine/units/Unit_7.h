#ifndef UNITS_UNIT7_H
#define UNITS_UNIT7_H
#include "Unit.h"

namespace engine
{
	class World; 
	
	namespace units
	{
		class Unit_7 :public Unit
		{ 
		public:
			Unit_7();

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif
