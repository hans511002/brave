#include "engine/world.h"
#include "engine/decoration/Decoration.h"
#include "engine/decoration/DecorationLevel1.h"
#include "engine/level/level.h"
#include "engine/level/level1_mc.h"
namespace engine{
	namespace  decoration
	{
 
		Decoration::Decoration()
		{
			this->world = Main::mainClass->worldClass;
			this->world->listOfClasses.push(this);

		}// end function

		DecorationLevel1::DecorationLevel1()
		{
			 Level1_mc * level1 = ( Level1_mc *)world->level;
			//container = level1->decorations.at(0);
			//this->container1 = level1->decorations.at(1);
			//this->decorationCase = level1->decorations.at(2);

			//container.stop();
			//this.container1.stop();
			//this.decorationCase.stop();
			//this.decorationCase.setMouseEnabled(true);
			//this.container1.visible = false;
		}// end function
	}

}
