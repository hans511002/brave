#ifndef ENGINE_MONEYADD_H
#define ENGINE_MONEYADD_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"
#include "MainClass.h"
#include "World.h"
#include "JsonUtil.h"

namespace engine
{
	class MoneyAdd : public BaseSprite
    {
        int i;
        int tempObject;
        //public var container:MoneyAdd_mc;
		dragonBones::DBCCArmatureNode * container;// MoneyAdd_mc;
        int money;
        bool dead;
        World *world;
        cocos2d::Label *noteTXT;
        MoneyAdd(int param1):container(NULL),money(0),dead(false),i(0)
        {
            this->world = Main::mainClass->worldClass;
            //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            this->money = param1;
        }// end function

        bool init();
        void remove(){
			this->world->removeChild(this, true);
        };
        //public function update() : void
        //{
        //    if (this->container.currentFrame < this->container.totalFrames)
        //    {
        //        this->container.gotoAndStop((this->container.currentFrame + 1));
        //    }
        //    else
        //    {
        //        this->kill();
        //    }
        //    return;
        //}// end function

        //public function kill() : void
        //{
        //    if (!this->dead)
        //    {
        //        this->dead = true;
        //        this->i = 0;
        //        while (this->i < this->world.listOfIndexes3.length)
        //        {
        //            
        //            if (this->world.listOfIndexes3[this->i] == this)
        //            {
        //                this->world.listOfIndexes3.splice(this->i, 1);
        //                break;
        //            }
        //            var _loc_1:* = this;
        //            var _loc_2:* = this->i + 1;
        //            _loc_1.i = _loc_2;
        //        }
        //        this->i = 0;
        //        while (this->i < this->world.listOfClasses.length)
        //        {
        //            
        //            if (this->world.listOfClasses[this->i] == this)
        //            {
        //                this->world.listOfClasses.splice(this->i, 1);
        //                break;
        //            }
        //            var _loc_1:* = this;
        //            var _loc_2:* = this->i + 1;
        //            _loc_1.i = _loc_2;
        //        }
        //        this->world.removeChild(this);
        //    }
        //    return;
        //}// end function

	};
}
#endif
