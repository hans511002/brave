#include "Scredits.h"   
 
namespace screens
{    
    Credits_mc::Credits_mc()
    {
        return;
    }// end function

     
    Credits::Credits()
    {
        //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
        return;
    }// end function

    bool Credits::init()
    {
        //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
        //this->addEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
        //this->addEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
        //this->addEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
        //this->addEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
        //this->addEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
        this->container = new Credits_mc();
        this->stopManage(); 
        this->container->cont->mouseChildren  = false;
        this->container->cont->setMouseEnabled(false);
        this->addChild(this->container);
        return true;
    }// end function

    void Credits::stopManage()
    {
        this->container->stop();
        this->container->cont->stop();
        this->container->cont->logoCont->stop();
        this->container->cont->noteCont->stop();
        this->container->cont->noteCont->stop();
        this->container->cont->facebook->stop();
        this->container->cont->facebook->stop();
        this->container->cont->btnOk->stop();
        this->container->cont->logoCont->logoContCase->stop();
        this->container->cont->noteCont->noteContCase->stop();
        this->container->cont->facebook->facebookCase->stop();
        this->container->cont->twitter->twitterCase->stop();
        this->container->cont->btnOk->okCase->stop();
        this->container->cont->logoCont->logoContCase->setMouseEnabled(true);
        this->container->cont->noteCont->noteContCase->setMouseEnabled(true);
        this->container->cont->facebook->facebookCase->setMouseEnabled(true);
        this->container->cont->twitter->twitterCase->setMouseEnabled(true);
        this->container->cont->btnOk->okCase->setMouseEnabled(true);
        return;
    }// end function

    void Credits::enterFrameHandler(float dt) 
    {
        if (this->frameCounter < 30)
        {
            this->frameCounter++;
        }
        else
        {
            this->frameCounter = 1;
        }
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
            this->stopManage();
            if (this->container->currentFrame == this->container->totalFrames && this->container->cont->currentFrame == this->container->cont->totalFrames)
            {
                this->openFlag = false; 
                this->container->cont->mouseChildren  = true;
                this->container->cont->setMouseEnabled(true);
                this->autoguidersButtons();
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
            this->stopManage();
            if (this->container->currentFrame == 1 && this->container->cont->currentFrame == 1)
            {
                this->closeFlag = false;
                this->kill();
            }
        }
        return;
    }// end function

    void Credits::mouseMoveHandler(cocos2d::EventMouse * param1) 
    {
        if (param1->target->name == "logoContCase")
        {
            if (this->container->cont->logoCont->currentFrame == 1)
            {
                this->container->cont->logoCont->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->logoCont->currentFrame == 2)
        {
            this->container->cont->logoCont->gotoAndStop(1);
        }
        if (param1->target->name == "noteContCase")
        {
            if (this->container->cont->noteCont->currentFrame == 1)
            {
                this->container->cont->noteCont->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->noteCont->currentFrame == 2)
        {
            this->container->cont->noteCont->gotoAndStop(1);
        }
        if (param1->target->name == "facebookCase")
        {
            if (this->container->cont->facebook->currentFrame == 1)
            {
                this->container->cont->facebook->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->facebook->currentFrame == 2)
        {
            this->container->cont->facebook->gotoAndStop(1);
        }
        if (param1->target->name == "twitterCase")
        {
            if (this->container->cont->twitter->currentFrame == 1)
            {
                this->container->cont->twitter->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->twitter->currentFrame == 2)
        {
            this->container->cont->twitter->gotoAndStop(1);
        }
        if (param1->target->name == "okCase")
        {
            if (this->container->cont->btnOk->currentFrame == 1)
            {
                this->container->cont->btnOk->gotoAndStop(2);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
            }
        }
        else if (this->container->cont->btnOk->currentFrame == 2)
        {
            this->container->cont->btnOk->gotoAndStop(1);
        }
        return;
    }// end function

    void Credits::mouseDownHandler(cocos2d::EventMouse * event) 
    {
        if (event->target->name == "logoContCase")
        {
            if (this->container->cont->logoCont->currentFrame == 2)
            {
                this->container->cont->logoCont->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event->target->name == "noteContCase")
        {
            if (this->container->cont->noteCont->currentFrame == 2)
            {
                this->container->cont->noteCont->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event->target->name == "facebookCase")
        {
            if (this->container->cont->facebook->currentFrame == 2)
            {
                this->container->cont->facebook->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event->target->name == "twitterCase")
        {
            if (this->container->cont->twitter->currentFrame == 2)
            {
                this->container->cont->twitter->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event->target->name == "okCase")
        {
            if (this->container->cont->btnOk->currentFrame == 2)
            {
                this->container->cont->btnOk->gotoAndStop(3);
                //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            }
        }
        else if (event->target->name == "shadow")
        {
            if (!this->openFlag && !this->closeFlag)
            {
                this->close();
            }
        }
        return;
    }// end function

    void Credits::mouseUpHandler(cocos2d::EventMouse *event)
    {
        if (event->target->name == "logoContCase")
        {
            if (this->container->cont->logoCont->currentFrame == 3)
            {
                this->container->cont->logoCont->gotoAndStop(2);
                //navigateToURL(new URLRequest("http://www.hammersongames.com"));
            }
        }
        else if (this->container->cont->logoCont->currentFrame == 3)
        {
            this->container->cont->logoCont->gotoAndStop(1);
        }
        if (event->target->name == "noteContCase")
        {
            if (this->container->cont->noteCont->currentFrame == 3)
            {
                this->container->cont->noteCont->gotoAndStop(2);
                //navigateToURL(new URLRequest("http://www.hammersongames.com"));
            }
        }
        else if (this->container->cont->noteCont->currentFrame == 3)
        {
            this->container->cont->noteCont->gotoAndStop(1);
        }
        if (event->target->name == "facebookCase")
        {
            if (this->container->cont->facebook->currentFrame == 3)
            {
                this->container->cont->facebook->gotoAndStop(2);
                //navigateToURL(new URLRequest("http://www.facebook->com/HammersonGames"));
            }
        }
        else if (this->container->cont->facebook->currentFrame == 3)
        {
            this->container->cont->facebook->gotoAndStop(1);
        }
        if (event->target->name == "twitterCase")
        {
            if (this->container->cont->twitter->currentFrame == 3)
            {
                this->container->cont->twitter->gotoAndStop(2);
                //navigateToURL(new URLRequest("http://twitter->com/hammersongames"));
            }
        }
        else if (this->container->cont->twitter->currentFrame == 3)
        {
            this->container->cont->twitter->gotoAndStop(1);
        }
        if (event->target->name == "okCase")
        {
            if (this->container->cont->btnOk->currentFrame == 3)
            {
                this->container->cont->btnOk->gotoAndStop(2);
                this->close();
            }
        }
        else if (this->container->cont->btnOk->currentFrame == 3)
        {
            this->container->cont->btnOk->gotoAndStop(1);
        }
        return;
    }// end function

    void Credits::autoguidersButtons()
    {
        this->autoguidesMouse_pt = cocos2d::Point(this->mouseX, this->mouseY);
        this->autoguidesObject = NULL;
        this->autoguidesObject_pt = this->container->cont->logoCont->localToGlobal(this->container->cont->logoCont->logoContCase->getPosition());
        this->autoguidesObjectWidth = this->container->cont->logoCont->logoContCase.width / 2;
        this->autoguidesObjectHeight = this->container->cont->logoCont->logoContCase.height / 2;
        if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
        && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
        && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
        && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
        {
            this->autoguidesObject = this->container->cont->logoCont->logoContCase;
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->cont->noteCont->localToGlobal( this->container->cont->noteCont->noteContCase->getPosition());
            this->autoguidesObjectWidth = this->container->cont->noteCont->noteContCase.width / 2;
            this->autoguidesObjectHeight = this->container->cont->noteCont->noteContCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->cont->noteCont->noteContCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->cont->facebook->localToGlobal( this->container->cont->facebook->facebookCase->getPosition());
            this->autoguidesObjectWidth = this->container->cont->facebook->facebookCase.width / 2;
            this->autoguidesObjectHeight = this->container->cont->facebook->facebookCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->cont->facebook->facebookCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->cont->twitter->localToGlobal( this->container->cont->twitter->twitterCase->getPosition());
            this->autoguidesObjectWidth = this->container->cont->twitter->twitterCase.width / 2;
            this->autoguidesObjectHeight = this->container->cont->twitter->twitterCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->cont->twitter->twitterCase;
            }
        }
        if (!this->autoguidesObject)
        {
            this->autoguidesObject_pt = this->container->cont->btnOk->localToGlobal( this->container->cont->btnOk->okCase->getPosition());
            this->autoguidesObjectWidth = this->container->cont->btnOk->okCase.width / 2;
            this->autoguidesObjectHeight = this->container->cont->btnOk->okCase.height / 2;
            if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth 
            && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight 
            && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            {
                this->autoguidesObject = this->container->cont->btnOk->okCase;
            }
        }
        if (this->autoguidesObject)
        {
            //事件模拟
            this->tempObject = new Object();
            this->tempObject->target = this->autoguidesObject;
            this->mouseMoveHandler(this->tempObject);
        }
        return;
    }// end function

    void Credits::close()
    {
        this->closeFlag = true; 
        this->container->cont->mouseChildren  = false;
        this->container->cont->setMouseEnabled(false);
        return;
    }// end function

    void Credits::kill()
    {
        if (!this->dead)
        {
            this->dead = true;
            Main::mainClass->startMenuClass->removeChild(this->;
            Main::mainClass->startMenuClass->creditsClass = NULL;
        }
        return;
    }// end function

    //public function reInit(event:Event) : void
    //{
    //    this->removeEventListener(Event.REMOVED_FROM_STAGE, this->reInit);
    //    this->removeEventListener(Event.ENTER_FRAME, this->enterFrameHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_MOVE, this->mouseMoveHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_DOWN, this->mouseDownHandler);
    //    this->removeEventListener(MouseEvent.MOUSE_UP, this->mouseUpHandler);
    //    return;
    //}// end function
 
} 
