package training
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;

    public class Training_3 extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var container:Training_3_mc;
        public var frameCounter:int = 0;
        public var dead:Boolean;
        public var world:World;
        public var openFlag:Boolean = true;
        public var closeFlag:Boolean;
        public var phase:int = 0;

        public function Training_3()
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.addEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.addEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            Main.mainClass.worldClass.addEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
            Main.mainClass.worldClass.addEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            Main.mainClass.worldClass.addEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            this.world = Main.mainClass.worldClass;
            this.world.removeEventListener(MouseEvent.MOUSE_MOVE, this.world.mouseMoveHandler);
            this.world.removeEventListener(MouseEvent.MOUSE_DOWN, this.world.mouseDownHandler);
            this.world.removeEventListener(MouseEvent.MOUSE_UP, this.world.mouseUpHandler);
            this.i = 0;
            while (this.i < this.world.listOfPlaces.length)
            {
                
                if (this.world.listOfPlaces[this.i].name != "place2")
                {
                    var _loc_2:* = false;
                    this.world.listOfPlaces[this.i].mouseChildren = false;
                    this.world.listOfPlaces[this.i].mouseEnabled = _loc_2;
                }
                var _loc_2:* = this;
                var _loc_3:* = this.i + 1;
                _loc_2.i = _loc_3;
            }
            var _loc_2:* = false;
            this.world.worldInterface.container.fireSphere.mouseChildren = false;
            this.world.worldInterface.container.fireSphere.mouseEnabled = _loc_2;
            this.world.worldInterface.container.book.bookCase.buttonMode = false;
            this.world.worldInterface.container.pause.pauseCase.buttonMode = false;
            this.world.worldInterface.container.startWaves.startWavesCase.buttonMode = false;
            this.world.pointer1.pointerCase.buttonMode = false;
            this.container = new Training_3_mc();
            this.container.stop();
            this.addChild(this.container);
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            return;
        }// end function

        public function enterFrameHandler(event:Event) : void
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
                if (this.container.currentFrame < 23)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                else
                {
                    this.openFlag = false;
                }
            }
            else if (this.closeFlag)
            {
                if (this.container.currentFrame < this.container.totalFrames)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                else
                {
                    this.closeFlag = false;
                    this.kill();
                }
            }
            else if (this.phase == 0)
            {
                if (this.container.currentFrame < 43)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                }
                else
                {
                    this.container.gotoAndStop(24);
                }
                if (this.world.towerMenu)
                {
                    this.phase = 1;
                    this.container.gotoAndStop(44);
                }
            }
            else if (this.phase == 1)
            {
                if (this.container.currentFrame < 94)
                {
                    this.container.gotoAndStop((this.container.currentFrame + 1));
                    if (this.container.currentFrame == 56)
                    {
                        var _loc_2:* = true;
                        this.world.worldInterface.container.fireSphere.mouseChildren = true;
                        this.world.worldInterface.container.fireSphere.mouseEnabled = _loc_2;
                        this.world.worldInterface.autoguidersButtons();
                    }
                }
                else
                {
                    this.container.gotoAndStop(75);
                }
                if (this.world.listOfMoveSpheres.length > 0)
                {
                    this.closeFlag = true;
                    this.container.gotoAndStop(95);
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(event:MouseEvent) : void
        {
            if (this.world.buildTowerMenu)
            {
                this.world.buildTowerMenu.mouseMoveHandler(event);
            }
            else if (event.target.name == "placeForBuildCase")
            {
                this.world.mouseMoveHandler(event);
            }
            else if (event.target.name == "towerCase")
            {
                this.world.mouseMoveHandler(event);
            }
            else if (event.target.name == "sphereCase" && this.world.towerMenu)
            {
                this.world.mouseMoveHandler(event);
            }
            else
            {
                this.tempObject = new Object();
                this.tempObject.target = new Object();
                this.tempObject.target.name = "无";
                this.world.mouseMoveHandler(this.tempObject);
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (this.world.buildTowerMenu)
            {
                this.world.buildTowerMenu.mouseDownHandler(event);
            }
            else if (event.target.name == "placeCase")
            {
                this.world.mouseDownHandler(event);
            }
            else if (event.target.name == "towerCase")
            {
                this.world.mouseDownHandler(event);
            }
            else if (event.target.name == "sphereCase" && this.world.towerMenu)
            {
                this.world.mouseDownHandler(event);
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            if (this.world.buildTowerMenu)
            {
                this.world.buildTowerMenu.mouseUpHandler(event);
            }
            else if (event.target.name == "placeCase")
            {
                this.world.mouseUpHandler(event);
            }
            else if (event.target.name == "towerCase")
            {
                this.world.mouseUpHandler(event);
            }
            else if (event.target.name == "sphereCase" && this.world.towerMenu)
            {
                this.world.mouseUpHandler(event);
            }
            return;
        }// end function

        public function close() : void
        {
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.addEventListener(MouseEvent.MOUSE_MOVE, this.world.mouseMoveHandler);
                this.world.addEventListener(MouseEvent.MOUSE_DOWN, this.world.mouseDownHandler);
                this.world.addEventListener(MouseEvent.MOUSE_UP, this.world.mouseUpHandler);
                this.i = 0;
                while (this.i < this.world.listOfPlaces.length)
                {
                    
                    var _loc_1:* = true;
                    this.world.listOfPlaces[this.i].mouseChildren = true;
                    this.world.listOfPlaces[this.i].mouseEnabled = _loc_1;
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
                this.world.worldInterface.container.book.bookCase.buttonMode = true;
                this.world.worldInterface.container.pause.pauseCase.buttonMode = true;
                this.world.worldInterface.container.startWaves.startWavesCase.buttonMode = true;
                this.world.pointer1.pointerCase.buttonMode = true;
                this.world.removeChild(this);
                this.world.menuObject = null;
                this.world.trainingClass = new Training_4();
                this.world.addChild(this.world.trainingClass);
            }
            return;
        }// end function

        public function reInit(event:Event) : void
        {
            this.removeEventListener(Event.REMOVED_FROM_STAGE, this.reInit);
            this.removeEventListener(Event.ENTER_FRAME, this.enterFrameHandler);
            this.world.removeEventListener(MouseEvent.MOUSE_MOVE, this.mouseMoveHandler);
            this.world.removeEventListener(MouseEvent.MOUSE_DOWN, this.mouseDownHandler);
            this.world.removeEventListener(MouseEvent.MOUSE_UP, this.mouseUpHandler);
            return;
        }// end function

    }
}
