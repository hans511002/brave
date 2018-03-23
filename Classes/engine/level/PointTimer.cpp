#include "PointTimer.h"
#include "engine/WorldInterface.h"


namespace engine{
	PointTimer::PointTimer() :timer(0),counter(0),currentFrame(0)
	{
	};
	PointTimer::~PointTimer(){
	};
	void PointTimer::scheduleUpdate(float dt){
		currentFrame++;

	};

 	bool PointTimer::init(){
		this->initWithFile("public/point.png");
		//point = Sprite::create("public/point.png");
		this->setPosition(50, 250);
		//this->addChild(point);

		this->schedule(schedule_selector(PointTimer::scheduleUpdate), 1.0f);
		return true;
	}
}
