#include "Training_2.h"   
#include "engine/World.h"   

using namespace engine;

namespace training
{  
    Training_2_mc::Training_2_mc() :MovieClip("training", "Training_2_mc", "Training_2_mc")
     {

     };
    Training_2::Training_2()
    {
        //this.addEventListener(Event.ADDED_TO_STAGE, this.init);
        return;
    }// end function

    bool Training_2_mc::init()  
    {
        //this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
        //this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
        //this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
        //this.addEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
        //this.addEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
        //this.addEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
        //this.world = Main.mainClass.worldClass;
        //this.container = new Training_2_mc();
        //this.container.x = Main.SCREEN_WIDTH_HALF;
        //this.container.y = Main.SCREEN_HEIGHT_HALF;
        //this.contStops();
        //this.addChild(this.container);
        //Sounds.instance.playSound("snd_menu_pageScrolling");
        return true;
    }// end function

        void Training_2_mc::enterFrameHandler(float dt)  
        {
            if (this.frameCounter < 30)
            {
                (this.frameCounter + 1);
            }
            else
            {
                this.frameCounter = 1;
            }
            if (this.openFlag)
            {
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                if (this.container.cont.currentFrame < this.container.cont.totalFrames)
                {
                    this.container.cont.gotoAndStop((this.container.cont.currentFrame + 1));
                    this.contStops();
                }
                if (this.container.currentFrame == this.container.totalFrames && this.container.cont.currentFrame == this.container.cont.totalFrames)
                {
                    this.openFlag = false;
                    var _loc_2:* = true;
                    this.container.cont.mouseChildren = true;
                    this.container.cont.mouseEnabled = _loc_2;
                    this.autoguidersButtons();
                }
            }
            else if (this.closeFlag)
            {
                if (this.container.currentFrame > 1)
                {
                    this.container.gotoAndStop((this.container.currentFrame - 1));
                }
                if (this.container.cont.currentFrame > 1)
                {
                    this.container.cont.gotoAndStop((this.container.cont.currentFrame - 1));
                    this.contStops();
                }
                if (this.container.currentFrame == 1 && this.container.cont.currentFrame == 1)
                {
                    this.closeFlag = false;
                    this.kill();
                }
            }
            return;
        }// end function

        void Training_2_mc::mouseMoveHandler(cocos2d::EventMouse * e) 
        {
            if (param1.target.name == "okCase")
            {
                if (this.container.cont.btnOk.currentFrame == 1)
                {
                    this.container.cont.btnOk.gotoAndStop(2);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseMove", 0.95);
                }
            }
            else if (this.container.cont.btnOk.currentFrame == 2)
            {
                this.container.cont.btnOk.gotoAndStop(1);
            }
            return;
        }// end function

        void Training_2_mc::mouseDownHandler(cocos2d::EventMouse * e)  
        {
            if (event.target.name == "okCase")
            {
                if (this.container.cont.btnOk.currentFrame == 2)
                {
                    this.container.cont.btnOk.gotoAndStop(3);
                    Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
                }
            }
            return;
        }// end function

        void Training_2_mc::mouseUpHandler(cocos2d::EventMouse * e)  
        {
            if (event.target.name == "okCase")
            {
                if (this.container.cont.btnOk.currentFrame == 3)
                {
                    this.container.cont.btnOk.gotoAndStop(1);
                    this.close();
                }
            }
            else if (this.container.cont.btnOk.currentFrame == 3)
            {
                this.container.cont.btnOk.gotoAndStop(1);
            }
            return;
        }// end function

        void Training_2_mc::contStops()  
        {
            this.container.stop();
            this.container.cont.stop();
            this.container.cont.btnOk.stop();
            this.container.cont.btnOk.okCase.stop();
            this.container.cont.btnOk.okCase.buttonMode = true;
            var _loc_1:* = false;
            this.container.cont.mouseChildren = false;
            this.container.cont.mouseEnabled = _loc_1;
            return;
        }// end function
 

        void Training_2_mc::close() 
        {
            if (!this.closeFlag)
            {
                this.closeFlag = true;
                var _loc_1:* = false;
                this.container.cont.mouseChildren = false;
                this.container.cont.mouseEnabled = _loc_1;
                Sounds.instance.playSound("snd_menu_pageScrolling");
            }
            return;
        }// end function

        void Training_2_mc::kill()  
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.removeChild(this);
                this.world.menuObject = null;
                this.world.menuObject = new Training_3();
                this.world.addChild(this.world.menuObject);
            }
            return;
        }// end function
 

    }
}
