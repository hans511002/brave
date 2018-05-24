#ifndef UNITS_UNIT2_H
#define UNITS_UNIT2_H
#include "Unit.h"
 
namespace engine
{
	class World;
	
	namespace units
	{
		class Unit_2 :public Unit
		{ 
		public:
			Unit_2();

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif
