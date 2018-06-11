#ifndef UNITS_UNIT3_H
#define UNITS_UNIT3_H
#include "Unit.h"

namespace engine
{
 
	
	namespace units
	{
		class Unit_3 :public Unit
		{ 
		public:
			Unit_3();

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif
 