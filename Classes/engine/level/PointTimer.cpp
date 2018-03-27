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
		//this->initWithFile("public/point.png");
		point = Sprite::create("public/point.png");
        point->setName("point");
        std::setAnchorPoint(point, 0, 0);
		this->addChild(point);
		this->schedule(schedule_selector(PointTimer::scheduleUpdate), 1.0f);

        //EventListenerMouse *mouseListener = cocos2d::EventListenerMouse::create();
        //mouseListener->onMouseDown = CC_CALLBACK_1(PointTimer::mouseDownHandler, this);
        //this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);

		return true;
	}
    void PointTimer::mouseDownHandler(cocos2d::Event *event)//(event:MouseEvent) : void
    {
        cocos2d::EventMouse*e = (cocos2d::EventMouse*)event;
        Node * node = event->getCurrentTarget();
        Event::Type tp = event->getType();
        string target = node->getName();
        CCLOG("WorldInterface::mouseDownHandler %s", target.c_str());

        cocos2d::Point pt = e->getLocation();
        CCLOG("mouse point %f,%f", pt.x, pt.y);
        Vec2 nsp = node->convertToNodeSpaceAR(pt);
        CCLOG("mouse ToNodeSpaceAR point %f,%f", nsp.x, nsp.y);
        nsp = node->convertToNodeSpace(pt);
        CCLOG("mouse ToNodeSpace point %f,%f", nsp.x, nsp.y);
        nsp = this->convertToNodeSpaceAR(pt);
        CCLOG("pointer1 ToNodeSpace point %f,%f", nsp.x, nsp.y);

        pt = e->getLocationInView();
        CCLOG("mouse InView point %f,%f", pt.x, pt.y);
        nsp = node->convertToNodeSpaceAR(pt);
        CCLOG("mouse ToNodeSpaceAR point %f,%f", nsp.x, nsp.y);
        nsp = node->convertToNodeSpace(pt);
        CCLOG("mouse ToNodeSpace point %f,%f", nsp.x, nsp.y);

        nsp = this->convertToNodeSpaceAR(pt);
        CCLOG("pointer1 ToNodeSpace point %f,%f", nsp.x, nsp.y);

        Rect bb;
        bb.size = this->point->getContentSize();
        if (bb.containsPoint(nsp))
        {
            CCLOG("WorldInterface::containsPoint %s", target.c_str());
        }
    }
}
