package engine.towers
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;

    public class BuildTowerMenu extends Sprite
    {
        public var i:int;
        public var tempObject:Object;
        public var container:BuildTowerMenu_mc;
        public var dead:Boolean;
        public var closeFlag:Boolean;
        public var myPlace:MovieClip;
        public var world:World;

        public function BuildTowerMenu(param1:MovieClip)
        {
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            this.myPlace = param1;
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.world = Main.mainClass.worldClass;
            this.x = this.myPlace.x + this.myPlace.buildPoint.x;
            this.y = this.myPlace.y + this.myPlace.buildPoint.y;
            this.myPlace.gotoAndStop(2);
            this.container = new BuildTowerMenu_mc();
            this.container.stop();
            this.container.cont.stop();
            this.container.cont.costTXT.text = Main.mainClass.readXMLClass.costTowerXML;
            this.container.cont.buildTowerMenuCase.buttonMode = true;
            this.addChild(this.container);
            this.world.listOfClasses.push(this);
            this.monitor();
            return;
        }// end function

        public function update() : void
        {
            if (!this.closeFlag)
            {
                if (this.container.currentFrame < 8)
                {
                    if (this.container.currentFrame < 7)
                    {
                        this.container.gotoAndStop((this.container.currentFrame + 1));
                    }
                }
                else if (this.container.currentFrame > 7)
                {
                    if (this.container.currentFrame < this.container.totalFrames)
                    {
                        this.container.gotoAndStop((this.container.currentFrame + 1));
                    }
                }
            }
            else if (this.container.currentFrame < 8)
            {
                if (this.container.currentFrame > 1)
                {
                    this.container.gotoAndStop((this.container.currentFrame - 1));
                }
                else
                {
                    this.myPlace.gotoAndStop(1);
                    this.myPlace.buildPoint.stop();
                    this.myPlace.placeForBuildCase.buttonMode = true;
                    this.kill();
                }
            }
            else if (this.container.currentFrame > 7)
            {
                if (this.container.currentFrame > 8)
                {
                    this.container.gotoAndStop((this.container.currentFrame - 1));
                }
                else
                {
                    this.myPlace.gotoAndStop(1);
                    this.myPlace.buildPoint.stop();
                    this.myPlace.placeForBuildCase.buttonMode = true;
                    this.kill();
                }
            }
            return;
        }// end function

        public function mouseMoveHandler(param1) : void
        {
            if (!this.closeFlag)
            {
                if (param1.target.name != "placeForBuildCase" && param1.target.name != "buildTowerMenuCase" && param1.target != this.myPlace && param1.target.parent != this)
                {
                    this.closeMenu();
                }
            }
            return;
        }// end function

        public function mouseDownHandler(event:MouseEvent) : void
        {
            if (!this.closeFlag)
            {
                if (event.target.name == "placeForBuildCase" || event.target.name == "buildTowerMenuCase")
                {
                    if (this.container.cont.buildTowerMenuCase.buttonMode)
                    {
                        this.world.money = this.world.money - Main.mainClass.readXMLClass.costTowerXML;
                        this.world.worldInterface.updateInfo();
                        Main.mainClass.readXMLClass.costTowerXML = Main.mainClass.readXMLClass.costTowerXML + Main.mainClass.readXMLClass.costTowerPlusXML;
                        this.tempObject = this.world.addTower("tower1", this.myPlace);
                        this.kill();
                        this.world.buildTowerMenu = null;
                    }
                }
            }
            return;
        }// end function

        public function mouseUpHandler(event:MouseEvent) : void
        {
            return;
        }// end function

        public function monitor() : void
        {
            if (this.world.money >= Main.mainClass.readXMLClass.costTowerXML)
            {
                if (this.container.currentFrame > 7)
                {
                    this.container.gotoAndStop(this.container.currentFrame - 7);
                    this.container.cont.stop();
                }
                this.container.cont.buildTowerMenuCase.buttonMode = true;
                this.myPlace.placeForBuildCase.buttonMode = true;
            }
            else
            {
                if (this.container.currentFrame < 8)
                {
                    this.container.gotoAndStop(this.container.currentFrame + 7);
                    this.container.cont.stop();
                }
                this.container.cont.buildTowerMenuCase.buttonMode = false;
                this.myPlace.placeForBuildCase.buttonMode = false;
            }
            this.container.cont.costTXT.text = Main.mainClass.readXMLClass.costTowerXML;
            return;
        }// end function

        public function closeMenu() : void
        {
            this.closeFlag = true;
            var _loc_1:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_1;
            this.world.buildTowerMenu = null;
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.world.removeChild(this);
                this.i = 0;
                while (this.i < this.world.listOfClasses.length)
                {
                    
                    if (this.world.listOfClasses[this.i] == this)
                    {
                        this.world.listOfClasses.splice(this.i, 1);
                        break;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            return;
        }// end function

    }
}
