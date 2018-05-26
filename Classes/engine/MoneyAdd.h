#ifndef ENGINE_MONEYADD_H
#define ENGINE_MONEYADD_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"
#include "MainClass.h"
#include "World.h"
#include "JsonUtil.h"
 
namespace engine
{
	struct MoneyAdd_mc:public MovieClip
	{
		ui::Text	* noteTXT	;
		inline MoneyAdd_mc():MovieClip("worldinterface/","MoneyAdd_mc","MoneyAdd_mc")
		{
		noteTXT=this->createText("noteTXT");
		}
	} ;
	class MoneyAdd : public BaseNode
    {
        int i;
        int tempObject;
        //public var container:MoneyAdd_mc;
		dragonBones::DBCCArmatureNode * container;// MoneyAdd_mc;
        int money;
        bool dead;
        World *world;
        cocos2d::Label *noteTXT;
        

        bool init();
        void remove(){
			this->world->removeChild(this, true);
        };
        void update();

        void kill(); 

	};
}
#endif
