#ifndef UNITS_UNIT10_H
#define UNITS_UNIT10_H
#include "Unit.h"

namespace engine
{
	class World;
	
	namespace units
	{
		class Unit_10 :public Unit
		{  
		public:
			Unit_10();

			bool init(); 
			void animationHandler();
			// implement the "static create()" method manually
			//CREATE_FUNC(Unit_1);
		};
	}
}
#endif
