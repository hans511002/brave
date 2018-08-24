#include "MainClass.h"
#include "World.h"
#include "MoneyAdd.h"

namespace engine
{ 
	MoneyAdd::MoneyAdd(int param1) :container(NULL), money(0), dead(false), i(0)
    {
        this->world = Main::mainClass->worldClass;
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        this->money = param1;
		init();
    }// end function
	bool MoneyAdd::init()//(event:Event) : void
	{
		BaseNode::init();
		////this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
		this->container = new MoneyAdd_mc();
		this->container->stop();
		std::setText(this->container->noteTXT, this->money);
		this->addChild(this->container);
		this->setMouseChildren(false);
		this->setMouseEnabled(false);
		this->world->addClasses(this);
		this->world->addIndexes(this,3);
		 
		return true;
	};
    void MoneyAdd::update(float dt) 
    {
        if (this->container->currentFrame < this->container->totalFrames)
        {
            this->container->tryPlay();
            //this->container->gotoAndStop((this->container->currentFrame + 1));
        }
        else
        {
            this->kill();
        }
        return;
    }// end function
	void MoneyAdd::remove(){
		this->world->removeChild(this, true);
	};
    void MoneyAdd::kill()  
    {
        if (!this->dead)
        {
            this->dead = true;
            //this->world->removeClasses(this);
            //this->world->removeIndexes(this,3); 
            this->world->removeChild(this);
        }
        return;
    }// end function
}

