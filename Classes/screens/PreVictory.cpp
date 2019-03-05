#include "PreVictory.h"   
#include "engine/World.h"   

using namespace engine;

namespace screens
{ 
    PreVictory_mc::PreVictory_mc():MoviceClip("screen","PreVictory_mc","PreVictory_mc")
    {
        this->cont=this->createMoviceClipSub("cont");
        this->contBtnOk=this->cont->createMoviceClipSub("btnOk");
        this->contBtnOkOkCase=this->contBtnOk->createCase("okCase");
     };
        
        
    PreVictory::PreVictory()
    {
        this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool PreVictory::init()
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        Main->mainClass->worldClass->manageListeners("off");
        Main->mainClass->worldClass->worldInterface.breaking();
        this->container = new PreVictory_mc();
        this->stopAll();
        this->container->setPosition(Main::SCREEN_WIDTH_HALF, Main::SCREEN_HEIGHT_HALF);
        this->addChild(this->container); 
        this->container->cont->setMouseChildren(false);
        this->container->cont->mouseEnabled = false;
        return true;
    }// end function

    void enterFrameHandler(float dt)
    {
        if (this->openFlag)
        {
            if (this->container->currentFrame < this->container->totalFrames)
            {
                this->container->gotoAndStop((this->container->currentFrame + 1));
            }
            if (this->container->cont->currentFrame < this->container->cont->totalFrames)
            {
                this->container->cont->gotoAndStop((this->container->cont->currentFrame + 1));
            }
            this->stopAll();
            if (this->container->currentFrame == this->container->totalFrames && this->container->cont->currentFrame == this->container->cont->totalFrames)
            {
                this->openFlag = false; 
                this->container->cont->setMouseChildren(true);
                this->container->cont->mouseEnabled = true;
            }
        }
        else if (this->closeFlag)
        {
            if (this->container->currentFrame > 1)
            {
                this->container->gotoAndStop((this->container->currentFrame - 1));
            }
            if (this->container->cont->currentFrame > 1)
            {
                this->container->cont->gotoAndStop((this->container->cont->currentFrame - 1));
            }
            this->stopAll();
            if (this->container->currentFrame == 1 && this->container->cont->currentFrame == 1)
            {
                this->closeFlag = false;
                this->kill();
            }
        }
        return;
    }// end function

    void mouseMoveHandler(cocos2d::EventMouse * e)  
    {
        Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		if (!globalNode)EventNode::mouseMoveHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_MOVE))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			EventNode::beginTouchNode = event->target;
            if (targetName == "okCase")
            {
                if (this->container->contBtnOk->currentFrame == 1)
                {
                    this->container->contBtnOk->gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95);
                }
            }
            else if (this->container->contBtnOk->currentFrame == 2)
            {
                this->container->contBtnOk->gotoAndStop(1);
            }
        }
    }// end function

    void mouseDownHandler(cocos2d::EventMouse * e)  
    {
        if (!globalNode)EventNode::mouseDownHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_DOWN))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		//Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			EventNode::beginTouchNode = event->target;
            if (!this->openFlag && !this->closeFlag)
            {
                if (event.target.name == "okCase")
                {
                    if (this->container->contBtnOk->currentFrame == 2)
                    {
                        this->container->contBtnOk->gotoAndStop(3);
                        Sounds.instance.playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9);
                    }
                }
            }
        }
    }// end function

    void mouseUpHandler(cocos2d::EventMouse * e) 
    {
        if (!globalNode)EventNode::mouseUpHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_UP))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);
		while (event->hasNext())
		{
			string targetName = event->target->getName();
            if (event.target.name == "okCase")
            {
                if (this->container->contBtnOk->currentFrame == 3)
                {
                    this->container->contBtnOk->gotoAndStop(2);
                    this->close();
                }
            }
            else if (this->container->contBtnOk->currentFrame == 3)
            {
                this->container->contBtnOk->gotoAndStop(1);
            }
        }
    }// end function

        void stopAll() 
        {
            this->container->stop();
            this->container->cont->stop();
            this->container->contBtnOk->stop();
            this->container->contBtnOk->okCase->stop();
            this->container->contBtnOk->okCase->setMouseEnabled(true);
            return;
        }// end function

      
        void close() 
        {
            if (!this->closeFlag)
            {
                this->closeFlag = true;
                this->container->cont->setMouseChildren(false);
                this->container->cont->mouseEnabled = false;
            }
            return;
        }// end function

        void kill() 
        {
            if (!this->dead)
            {
                this->dead = true;
                Main->mainClass->worldClass->removeChild(this);
                Main->mainClass->worldClass->menuObject = NULL;
                Main->mainClass->worldClass->menuObject = new Victory();
                Main->mainClass->worldClass->addChild(Main->mainClass->worldClass->menuObject);
            }
            return;
        }// end function
 
     
}
