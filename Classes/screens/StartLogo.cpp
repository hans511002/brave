#include "StartLogo.h"   
#include "engine/World.h"   

using namespace engine;

namespace screens
{ 
    StartLogo::StartLogo()
    {
        init() ;
        //this.addEventListener(Event.ADDED_TO_STAGE, this.init);
        return;
    }// end function

    bool init() 
    {
       //this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
       //this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
       //this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
       //this.addEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
       //this.addEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
       //this.addEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
        this.container = new StartLogo_mc();
        this.container->stop();
        this.addChild(this.container);
        this.nowSoundTransform = new SoundTransform(1, 0);
        //this.nowSound = new Snd_menu_logo_mp3();
        //this.nowSound.play(0, 1, this.nowSoundTransform);
        this->manageListeners("off");
        return;
    }// end function

    void enterFrameHandler(float dt) 
    {
        if (this.frameCounter < 30)
             this.frameCounter++;  
        else 
            this.frameCounter = 1; 
        if (this.container->currentFrame < this.container->totalFrames)
        {
            this.container->gotoAndStop((this.container->currentFrame + 1));
            if (this.container->currentFrame == this.container->totalFrames)
            {
                //Main::mainClass->bmp = new Bitmap(Main::mainClass->getBitmapData(this));
                //Main::mainClass->bmp.alpha = 0;
                this.addChild(Main::mainClass->bmp);
                this.container->visible = false;
            }
        }
        else if (Main::mainClass->bmp.alpha > 0)
        {
            Main::mainClass->bmp.alpha = Main::mainClass->bmp.alpha - 0.2;
        }
        else
        {
            this.removeChild(Main::mainClass->bmp);
            Main::mainClass->bmp = NULL;
            Main::mainClass->removeChild(Main::mainClass->startLogoClass);
            Main::mainClass->startLogoClass = null;
            Main::mainClass->startMenuClass = new StartMenu();
            Main::mainClass->container = Main::mainClass->startMenuClass
            Main::mainClass->addChild(Main::mainClass->startMenuClass);
        }
        return;
    }// end function
 
 
}
