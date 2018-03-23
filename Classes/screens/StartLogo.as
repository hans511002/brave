package screens
{
    import flash.display.*;
    import flash.events.*;
    import flash.media.*;

    public class StartLogo extends Sprite
    {
        public var frameCounter:int = 0;
        public var container:MovieClip;
        public var nowSound:Sound;
        public var nowSoundTransform:SoundTransform;

        public function StartLogo()
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.addEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
            this.addEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            this.addEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            this.container = new StartLogo_mc();
            this.container.stop();
            this.addChild(this.container);
            this.nowSoundTransform = new SoundTransform(1, 0);
            this.nowSound = new Snd_menu_logo_mp3();
            this.nowSound.play(0, 1, this.nowSoundTransform);
            return;
        }// end function

        public function enterFrameHandler(event:Event) : void
        {
            if (this.frameCounter < 30)
            {
                var _loc_2:* = this;
                var _loc_3:* = this.frameCounter + 1;
                _loc_2.frameCounter = _loc_3;
            }
            else
            {
                this.frameCounter = 1;
            }
            if (this.container.currentFrame < this.container.totalFrames)
            {
                this.container.gotoAndStop((this.container.currentFrame + 1));
                if (this.container.currentFrame == this.container.totalFrames)
                {
                    Main.mainClass.bmp = new Bitmap(Main.mainClass.getBitmapData(this));
                    Main.mainClass.bmp.alpha = 0;
                    this.addChild(Main.mainClass.bmp);
                    this.container.visible = false;
                }
            }
            else if (Main.mainClass.bmp.alpha > 0)
            {
                Main.mainClass.bmp.alpha = Main.mainClass.bmp.alpha - 0.2;
            }
            else
            {
                this.removeChild(Main.mainClass.bmp);
                Main.mainClass.bmp = null;
                Main.mainClass.removeChild(Main.mainClass.startLogoClass);
                Main.mainClass.startLogoClass = null;
                var _loc_2:* = new StartMenu();
                Main.mainClass.container = new StartMenu();
                Main.mainClass.startMenuClass = _loc_2;
                Main.mainClass.addChild(Main.mainClass.startMenuClass);
            }
            return;
        }// end function

        public function mouseMoveHandler(event:MouseEvent) : void
        {
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            return;
        }// end function

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.removeEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
            this.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            this.removeEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            return;
        }// end function

    }
}
