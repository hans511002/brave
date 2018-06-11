#ifndef UNITS_UNIT4_H
#define UNITS_UNIT4_H
#include "Unit.h"

namespace engine
{
 
	namespace units
	{
		class Unit_4 :public Unit
		{ 
		public:
			Unit_4();

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif
 