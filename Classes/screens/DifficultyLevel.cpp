 
#include "MainClass.h"
#include "LevelsMenu.h"
#include "DifficultyLevel.h"   

namespace screens
{    
	DeifficultyLevel_mc::DeifficultyLevel_mc():MovieClip("screen/","DeifficultyLevel_mc","DeifficultyLevel_mc")
    {
        first=this->createMovieClipSub("first");
        firstEasy=first->createMovieClipSub("easy",true);
        firstNormal=first->createMovieClipSub("normal", true);
        firstHard=first->createMovieClipSub("hard", true);
        firstEasyComplexityCase=firstEasy->createCase("complexityCase");
        firstNormalComplexityCase=firstNormal->createCase("complexityCase");
        firstHardComplexityCase=firstHard->createCase("complexityCase");
        //shadow=this->createMovieClipSub("shadow");
    };
     
    DifficultyLevel::DifficultyLevel():openFlag(true),closeFlag(false),container(0)
    {
		init();
        return;
    }// end function

    bool DifficultyLevel::init()
    {
		this->enableMouseHandler(true);
		this->enableFrameHandler(true);
        Main::mainClass->levelsMenuClass->manageListeners("off");
        this->container = new DeifficultyLevel_mc(); 
		cocos2d::Size size = this->container->getSprite("bg")->getContentSize();
		float sy = Main::SCREEN_HEIGHT / size.height;
		float sx = (size.width - Main::SCREEN_WIDTH) / 2;
		this->container->setPosition(0, 525);
		this->container->setScaleY(sy);
        this->container->stop();
        this->container->first->stop();
        this->container->firstEasy->stop();
        this->container->firstNormal->stop();
        this->container->firstHard->stop(); 
        this->addChild(this->container);
        AudioUtil::playSound("Snd_menu_pageScrolling.mp3");
		this->manageListeners("on");
		return true;
    }// end function

    void DifficultyLevel::enterFrameHandler(float dt) 
    {
        if (this->frameCounter < 30)
            this->frameCounter++;
        else
            this->frameCounter = 1;
        if (this->openFlag)
        {
            if (this->container->currentFrame < this->container->totalFrames)
                this->container->gotoAndStop((this->container->currentFrame + 1));
            if (this->container->first->currentFrame < this->container->first->totalFrames)
            {
                this->container->first->gotoAndStop((this->container->first->currentFrame + 1));
                this->container->firstEasy->gotoAndStop(1);
                this->container->firstNormal->gotoAndStop(1);
                this->container->firstHard->gotoAndStop(1);
                this->container->firstEasyComplexityCase->stop();
                this->container->firstNormalComplexityCase->stop();
                this->container->firstHardComplexityCase->stop();
                this->container->firstEasyComplexityCase->setMouseEnabled(false);
                this->container->firstNormalComplexityCase->setMouseEnabled(false);
                this->container->firstHardComplexityCase->setMouseEnabled(false);
            }
            if (this->container->currentFrame == this->container->totalFrames && this->container->first->currentFrame == this->container->first->totalFrames)
            {
                this->openFlag = false;
                this->container->firstEasyComplexityCase->setMouseEnabled(true);
                this->container->firstNormalComplexityCase->setMouseEnabled(true);
                this->container->firstHardComplexityCase->setMouseEnabled(true);
            }
			if (this->openFlag && dt > 0)this->enableFrameHandler(0);
        }
        else if (this->closeFlag)
        {
            if (this->container->currentFrame > 1)
            {
                this->container->gotoAndStop((this->container->currentFrame - 1));
            }
            if (this->container->first->currentFrame > 1)
            {
                this->container->first->gotoAndStop((this->container->first->currentFrame - 1));
                this->container->firstEasy->gotoAndStop(1);
                this->container->firstNormal->gotoAndStop(1);
                this->container->firstHard->gotoAndStop(1);
                this->container->firstEasyComplexityCase->stop();
                this->container->firstNormalComplexityCase->stop();
                this->container->firstHardComplexityCase->stop();
                this->container->firstEasyComplexityCase->setMouseEnabled(false);
                this->container->firstNormalComplexityCase->setMouseEnabled(false);
                this->container->firstHardComplexityCase->setMouseEnabled(false);
            }
            if (this->container->currentFrame == 1 && this->container->first->currentFrame == 1)
            {
                Main::mainClass->levelsMenuClass->removeChild(this);
                Main::mainClass->levelsMenuClass->difficultyLevel = NULL;
                Main::mainClass->levelsMenuClass->manageListeners("on"); 
                Main::mainClass->levelsMenuClass->container->setMouseChildren(true);
                Main::mainClass->levelsMenuClass->container->setMouseEnabled(true);
            }else if (dt != 0)
				this->enterFrameHandler(0); 
        }
        return;
    }// end function

 	void DifficultyLevel::mouseMoveHandler(cocos2d::EventMouse * e)
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
		//if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_MOVE))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		//return;
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			Node * parent = event->target->getParent()->getParent();
			string parentName = parent->getName();

			if (parentName == "easy")
			{
				if (this->container->firstEasy->currentFrame == 1)
				{
					this->container->firstEasy->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->firstEasy->currentFrame == 2)
			{
				this->container->firstEasy->gotoAndStop(1);
			}
			if (parentName == "normal")
			{
				if (this->container->firstNormal->currentFrame == 1)
				{
					this->container->firstNormal->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->firstNormal->currentFrame == 2)
			{
				this->container->firstNormal->gotoAndStop(1);
			}
			if (parentName == "hard")
			{
				if (this->container->firstHard->currentFrame == 1)
				{
					this->container->firstHard->gotoAndStop(2);
					AudioUtil::playSoundWithVol("Snd_menu_mouseMove.mp3", 0.95f);
				}
			}
			else if (this->container->firstHard->currentFrame == 2)
			{
				this->container->firstHard->gotoAndStop(1);
			}
		}
        return;
    }// end function

    void DifficultyLevel::mouseDownHandler(cocos2d::EventMouse *e)
    {
		if (!globalNode)EventNode::mouseDownHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		//if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_DOWN))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			EventNode::beginTouchNode = event->target;// event->currentTargets.at(0);
			EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);

			Node * parent = event->target->getParent()->getParent();
			string parentName = parent->getName();

			if (parentName == "easy")
			{
				if (this->container->firstEasy->currentFrame == 2)
				{
					this->container->firstEasy->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (parentName == "normal")
			{
				if (this->container->firstNormal->currentFrame == 2)
				{
					this->container->firstNormal->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
			else if (parentName == "hard")
			{
				if (this->container->firstHard->currentFrame == 2)
				{
					this->container->firstHard->gotoAndStop(3);
					AudioUtil::playSoundWithVol("Snd_menu_mouseDown.mp3", 0.9f);
				}
			}
		}
        return;
    }// end function

    void DifficultyLevel::mouseUpHandler(cocos2d::EventMouse * e)
    {
		if (!globalNode)EventNode::mouseUpHandler(e);
		cocos2d::EventMouse::MouseButton mouseButton = e->getMouseButton();
		if (mouseButton == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)return;
		std::MouseEvent me(e);
		if (!useNodeEvent) {
			me = std::buildMouseEvent(e);
		}
		std::MouseEvent * event = &me;
		//if (preCheckEventTarget(event, EventMouse::MouseEventType::MOUSE_UP))return;
		if (!event->currentTargets.size())
			event->currentTargets.push(this);
		Main::mouseX = e->getCursorX();
		Main::mouseY = e->getCursorY();
		while (event->hasNext())
		{
			string targetName = event->target->getName();
			EventNode::beginTouchNode = event->target;// event->currentTargets.at(0);
			EventNode::beginTouchPos = Vec2(Main::mouseX, Main::mouseY);

			Node * parent = event->target->getParent()->getParent();
			string parentName = parent->getName();
			if (parentName == "easy")
			{
				if (this->container->firstEasy->currentFrame == 3)
				{
					this->container->firstEasy->gotoAndStop(2);
					this->closeFlag = true;
					Main::mainClass->saveBoxClass->setValue("difficultyLevel", true);
					Main::mainClass->saveBoxClass->setValue("complexityLevel", 1);
					AudioUtil::playSound("Snd_menu_pageScrolling.mp3");
				}
			}
			else if (this->container->firstEasy->currentFrame == 3)
			{
				this->container->firstEasy->gotoAndStop(1);
			}
			if (parentName == "normal")
			{
				if (this->container->firstNormal->currentFrame == 3)
				{
					this->container->firstNormal->gotoAndStop(2);
					this->closeFlag = true;
					Main::mainClass->saveBoxClass->setValue("difficultyLevel", true);
					Main::mainClass->saveBoxClass->setValue("complexityLevel", 2);
					AudioUtil::playSound("Snd_menu_pageScrolling.mp3");
				}
			}
			else if (this->container->firstNormal->currentFrame == 3)
			{
				this->container->firstNormal->gotoAndStop(1);
			}
			if (parentName == "hard")
			{
				if (this->container->firstHard->currentFrame == 3)
				{
					this->container->firstHard->gotoAndStop(2);
					this->closeFlag = true;
					Main::mainClass->saveBoxClass->setValue("difficultyLevel", true);
					Main::mainClass->saveBoxClass->setValue("complexityLevel", 3);
					AudioUtil::playSound("Snd_menu_pageScrolling.mp3");
				}
			}
			else if (this->container->firstHard->currentFrame == 3)
			{
				this->container->firstHard->gotoAndStop(1);
			}
		}
        return;
    }// end function

    void DifficultyLevel::autoguidersButtons()
    {
        //this->autoguidesMouse_pt = cocos2d::Point(Main::mouseX, Main::mouseY);
        //this->autoguidesObject = NULL;
        //this->autoguidesObject_pt = this->container->firstEasy->localToGlobal(this->container->firstEasyComplexityCase->getPosition());
        //this->autoguidesObjectWidth = this->container->firstEasyComplexityCase->width / 2;
        //this->autoguidesObjectHeight = this->container->firstEasyComplexityCase->height / 2;
        //if (this->container->firstEasyComplexityCase->hitText(autoguidesMouse_pt))
        //{
        //    this->autoguidesObject = this->container->firstEasyComplexityCase;
        //}
        //if (!this->autoguidesObject)
        //{
        //    this->autoguidesObject_pt = this->container->first->easy.localToGlobal(this->container->firstNormalComplexityCase->getPosition());
        //    this->autoguidesObjectWidth = this->container->firstNormalComplexityCase->width / 2;
        //    this->autoguidesObjectHeight = this->container->firstNormalComplexityCase->height / 2;
        //    if (this->container->firstNormalComplexityCase->hitText(autoguidesMouse_pt))
        //    {
        //        this->autoguidesObject = this->container->firstNormalComplexityCase;
        //    }
        //}
        //if (!this->autoguidesObject)
        //{
        //    this->autoguidesObject_pt = this->container->first->easy.localToGlobal(this->container->firstHardComplexityCase->getPosition());
        //    this->autoguidesObjectWidth = this->container->firstHardComplexityCase->width / 2;
        //    this->autoguidesObjectHeight = this->container->firstHardComplexityCase->height / 2;
        //    if (this->container->firstHardComplexityCase->hitText(autoguidesMouse_pt))
        //    {
        //        this->autoguidesObject = this->container->firstHardComplexityCase;
        //    }
        //}
        //if (this->autoguidesObject)
        //{
        //    //模拟事件
        //    this->tempObject = new Object();
        //    this->tempObject->target = this->autoguidesObject;
        //    this->mouseMoveHandler(this->tempObject);
        //}
        //return;
    }// end function

    //public function reInit(event:Event) : void
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDwonHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    return;
    //}// end function
}
