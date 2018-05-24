#ifndef UNITS_UNIT1_H
#define UNITS_UNIT1_H
#include "Unit.h"

namespace engine
{
	class World;
	namespace units
	{ 
		class Unit_1 :public Unit
		{ 
		public:
			Unit_1()
			{
				 ;
			}// end function

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif
