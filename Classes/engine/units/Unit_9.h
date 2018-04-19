#ifndef UNITS_UNIT9_H
#define UNITS_UNIT9_H
#include "Unit.h"

namespace engine
{
	class World;
	
	namespace units
	{
		class Unit_9 :public Unit
		{ 
		public:
			Unit_9();

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif
