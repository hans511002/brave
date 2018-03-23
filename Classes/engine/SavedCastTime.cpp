#include "SavedCastTime.h"
namespace engine
{
	bool SavedCastTime::init()
	{
		//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		//this->world = Main.mainClass.worldClass;
		//this->container = new SavedCastTime_mc();
		//this->container.stop();
		//this->tempObject = Math.round(this.savedFrames / 30);
		//if (this.tempObject >= 10)
		//{
		//	this->container.cont.gotoAndStop(1);
		//}
		//else
		//{
		//	this->container.cont.gotoAndStop(2);
		//}
		//this->container.cont.noteTXT.text = "-" + this->tempObject;
		//this->addChild(this.container);
		//this->world.listOfClasses.push(this);
		//if (this.type == "golem")
		//{
		//	this->x = this->world.worldInterface.container.butCastGolem.x;
		//	this->y = this->world.worldInterface.container.butCastGolem.y;
		//}
		//else if (this.type == "iceman")
		//{
		//	this->x = this->world.worldInterface.container.butCastIceman.x;
		//	this->y = this->world.worldInterface.container.butCastIceman.y;
		//}
		//else if (this.type == "air")
		//{
		//	this->x = this->world.worldInterface.container.butCastAir.x;
		//	this->y = this->world.worldInterface.container.butCastAir.y;
		//}
		//this->x = this->x + 8;
		//var _loc_2 : *= false;
		//this->mouseChildren = false;
		//this->mouseEnabled = _loc_2;
		return true;
	}// end function

	void SavedCastTime::update()
	{
		//if (this->container.currentFrame <this->container.totalFrames)
		//{
		//	this->container.gotoAndStop((this->container.currentFrame + 1));
		//}
		//else
		//{
		//	this->kill();
		//}
	}// end function
	void SavedCastTime::kill()
	{
		//if (!this->dead)
		//{
		//	this->dead = true;
		//	this->world->worldInterface.removeChild(this);
		//	this->i = 0;
		//	while (this->i <this->world.listOfClasses.length)
		//	{
		//		if (this->world.listOfClasses[this->i] == this)
		//		{
		//			this->world.listOfClasses.splice(this->i, 1);
		//			break;
		//		}
		//		i++;
		//	}
		//}
	}// end function
}
