package engine.units
{
    import flash.events.*;

    public class Unit_29 extends Unit
    {
        public var returnHealth:Number;
        public var stealthCounter:int;
        public var stealthTimer:int;
        public var phase:int = 1;

        public function Unit_29()
        {
            return;
        }// end function

        override public function init(event:Event) : void
        {
            typeUnit = 29;
            readyDamage = false;
            moveFlag = false;
            this.returnHealth = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][33];
            var _loc_2:* = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
            this.stealthTimer = Main.mainClass.readXMLClass.listOfEnemiesXML[(typeUnit - 1)][34];
            this.stealthCounter = _loc_2;
            container = new Unit29_mc();
            var _loc_2:* = 0.85;
            container.scaleY = 0.85;
            container.scaleX = _loc_2;
            super.init(event);
            container.cont.gotoAndStop(68);
            this.alpha = 0;
            var _loc_2:* = false;
            this.mouseChildren = false;
            this.mouseEnabled = _loc_2;
            i = 0;
            while (i < world.listOfUnits.length)
            {
                
                if (world.listOfUnits[i] == this)
                {
                    world.listOfUnits.splice(i, 1);
                    break;
                }
                var _loc_3:* = i + 1;
                i = _loc_3;
            }
            world.listOfClasses.push(this);
            world.listOfIndexes0.push(this);
            return;
        }// end function

        override public function animationHandler() : void
        {
            if (!dead)
            {
                if (readyDamage)
                {
                    if (!icemanFlag && !airFlag && !airShockFlag)
                    {
                        if (direction != "up")
                        {
                            if (container.cont.currentFrame == 101)
                            {
                                container.cont.gotoAndStop(33);
                            }
                            else if (container.cont.currentFrame == 102)
                            {
                                container.cont.gotoAndStop(34);
                            }
                        }
                        else if (container.cont.currentFrame == 33)
                        {
                            container.cont.gotoAndStop(101);
                        }
                        else if (container.cont.currentFrame == 34)
                        {
                            container.cont.gotoAndStop(102);
                        }
                        if (direction == "left" || direction == "right")
                        {
                            if (container.currentFrame > 24)
                            {
                                container.gotoAndStop((container.currentFrame + 1));
                                if (container.cont.x >= -1 && container.cont.x <= 1 && container.cont.y >= -1 && container.cont.y <= 1)
                                {
                                    container.gotoAndStop(1);
                                }
                                if (container.currentFrame < 33)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < 37)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container.currentFrame < 44)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < container.totalFrames)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                            else
                            {
                                if (container.currentFrame < 24)
                                {
                                    container.gotoAndStop((container.currentFrame + 1));
                                }
                                else
                                {
                                    container.gotoAndStop(1);
                                }
                                if (container.currentFrame < 9)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < 13)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container.currentFrame < 20)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < 24)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                        }
                        else if (direction == "up")
                        {
                            if (container.cont.currentFrame < 10)
                            {
                                container.cont.gotoAndStop(10);
                            }
                            if (container.currentFrame < 25)
                            {
                                container.gotoAndStop((container.currentFrame + 1));
                                if (container.cont.x >= -1 && container.cont.x <= 1 && container.cont.y >= -1 && container.cont.y <= 1)
                                {
                                    container.gotoAndStop(25);
                                }
                                if (container.currentFrame < 9)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < 13)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container.currentFrame < 20)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < 24)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                            else
                            {
                                if (container.currentFrame < container.totalFrames)
                                {
                                    container.gotoAndStop((container.currentFrame + 1));
                                }
                                else
                                {
                                    container.gotoAndStop(25);
                                }
                                if (container.currentFrame < 33)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < 37)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container.currentFrame < 44)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < container.totalFrames)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                        }
                        else if (direction == "down")
                        {
                            if (container.currentFrame < 25)
                            {
                                container.gotoAndStop((container.currentFrame + 1));
                                if (container.cont.x >= -1 && container.cont.x <= 1 && container.cont.y >= -1 && container.cont.y <= 1)
                                {
                                    container.gotoAndStop(25);
                                }
                                if (container.currentFrame < 9)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < 13)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container.currentFrame < 20)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < 24)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                            else
                            {
                                if (container.currentFrame < container.totalFrames)
                                {
                                    container.gotoAndStop((container.currentFrame + 1));
                                }
                                else
                                {
                                    container.gotoAndStop(25);
                                }
                                if (container.currentFrame < 33)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < 37)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                                else if (container.currentFrame < 44)
                                {
                                    if (!moveFlag)
                                    {
                                        moveFlag = true;
                                    }
                                }
                                else if (container.currentFrame < container.totalFrames)
                                {
                                    if (moveFlag)
                                    {
                                        moveFlag = false;
                                    }
                                }
                            }
                        }
                    }
                }
                else if (!teleportFlag)
                {
                    if (this.phase == 1)
                    {
                        if (container.cont.currentFrame >= 34 && container.cont.currentFrame <= 68)
                        {
                            if (this.alpha < 1)
                            {
                                this.alpha = this.alpha + 0.1;
                            }
                            else if (this.alpha != 1)
                            {
                                this.alpha = 1;
                            }
                            if (this.stealthCounter > 0)
                            {
                                (this.stealthCounter - 1);
                                if (this.stealthCounter <= 5)
                                {
                                    if (container.dustAnima.alpha > 0)
                                    {
                                        container.dustAnima.alpha = container.dustAnima.alpha - 0.2;
                                    }
                                }
                            }
                            else
                            {
                                if (container.dustAnima.visible)
                                {
                                    container.dustAnima.visible = false;
                                    container.dustAnima.alpha = 0;
                                    i = 0;
                                    while (i < world.listOfIndexes0.length)
                                    {
                                        
                                        if (world.listOfIndexes0[i] == this)
                                        {
                                            world.listOfIndexes0.splice(i, 1);
                                            break;
                                        }
                                        var _loc_2:* = i + 1;
                                        i = _loc_2;
                                    }
                                    world.listOfIndexes1.push(this);
                                }
                                if (container.cont.currentFrame > 34)
                                {
                                    container.cont.gotoAndStop((container.cont.currentFrame - 1));
                                }
                                else
                                {
                                    i = 0;
                                    while (i < world.listOfClasses.length)
                                    {
                                        
                                        if (world.listOfClasses[i] == this)
                                        {
                                            world.listOfClasses.splice(i, 1);
                                            break;
                                        }
                                        var _loc_2:* = i + 1;
                                        i = _loc_2;
                                    }
                                    i = 0;
                                    while (i < world.listOfIndexes1.length)
                                    {
                                        
                                        if (world.listOfIndexes1[i] == this)
                                        {
                                            world.listOfIndexes1.splice(i, 1);
                                            break;
                                        }
                                        var _loc_2:* = i + 1;
                                        i = _loc_2;
                                    }
                                    world.listOfUnits.push(this);
                                    readyDamage = true;
                                    moveFlag = true;
                                    var _loc_1:* = true;
                                    this.mouseChildren = true;
                                    this.mouseEnabled = _loc_1;
                                    this.stealthCounter = this.stealthTimer;
                                    this.phase = 2;
                                }
                            }
                        }
                    }
                    else if (this.phase == 2)
                    {
                        if (container.cont.currentFrame >= 34 && container.cont.currentFrame <= 68)
                        {
                            if (container.cont.currentFrame < 68)
                            {
                                container.cont.gotoAndStop((container.cont.currentFrame + 1));
                            }
                            else if (!container.dustAnima.visible)
                            {
                                container.dustAnima.visible = true;
                                container.cont.gotoAndStop(1);
                            }
                        }
                        else if (container.cont.currentFrame >= 102 && container.cont.currentFrame <= 136)
                        {
                            if (container.cont.currentFrame < 136)
                            {
                                container.cont.gotoAndStop((container.cont.currentFrame + 1));
                            }
                            else if (!container.dustAnima.visible)
                            {
                                container.dustAnima.visible = true;
                                container.cont.gotoAndStop(69);
                            }
                        }
                        if (container.cont.currentFrame == 1 || container.cont.currentFrame == 69)
                        {
                            container.dustAnima.alpha = container.dustAnima.alpha + 0.2;
                            if (container.dustAnima.alpha > 1)
                            {
                                container.dustAnima.alpha = 1;
                                i = 0;
                                while (i < world.listOfIndexes1.length)
                                {
                                    
                                    if (world.listOfIndexes1[i] == this)
                                    {
                                        world.listOfIndexes1.splice(i, 1);
                                        break;
                                    }
                                    var _loc_2:* = i + 1;
                                    i = _loc_2;
                                }
                                world.listOfIndexes0.push(this);
                                this.phase = 3;
                            }
                        }
                    }
                    else if (this.phase == 3)
                    {
                        if (container.cont.currentFrame == 1 || container.cont.currentFrame == 69)
                        {
                            if (this.stealthCounter > 0)
                            {
                                (this.stealthCounter - 1);
                                if (this.stealthCounter <= 5)
                                {
                                    if (container.dustAnima.alpha > 0)
                                    {
                                        container.dustAnima.alpha = container.dustAnima.alpha - 0.2;
                                    }
                                }
                            }
                            else if (container.dustAnima.visible)
                            {
                                container.dustAnima.visible = false;
                                container.dustAnima.alpha = 0;
                                i = 0;
                                while (i < world.listOfIndexes0.length)
                                {
                                    
                                    if (world.listOfIndexes0[i] == this)
                                    {
                                        world.listOfIndexes0.splice(i, 1);
                                        break;
                                    }
                                    var _loc_2:* = i + 1;
                                    i = _loc_2;
                                }
                                world.listOfIndexes1.push(this);
                                this.phase = 4;
                            }
                        }
                    }
                    else if (this.phase == 4)
                    {
                        if (container.cont.currentFrame >= 1 && container.cont.currentFrame <= 33)
                        {
                            if (container.cont.currentFrame < 33)
                            {
                                container.cont.gotoAndStop((container.cont.currentFrame + 1));
                            }
                        }
                        else if (container.cont.currentFrame >= 69 && container.cont.currentFrame <= 101)
                        {
                            if (container.cont.currentFrame < 101)
                            {
                                container.cont.gotoAndStop((container.cont.currentFrame + 1));
                            }
                        }
                        if (container.cont.currentFrame == 33 || container.cont.currentFrame == 101)
                        {
                            i = 0;
                            while (i < world.listOfClasses.length)
                            {
                                
                                if (world.listOfClasses[i] == this)
                                {
                                    world.listOfClasses.splice(i, 1);
                                    break;
                                }
                                var _loc_2:* = i + 1;
                                i = _loc_2;
                            }
                            i = 0;
                            while (i < world.listOfIndexes1.length)
                            {
                                
                                if (world.listOfIndexes1[i] == this)
                                {
                                    world.listOfIndexes1.splice(i, 1);
                                    break;
                                }
                                var _loc_2:* = i + 1;
                                i = _loc_2;
                            }
                            world.listOfUnits.push(this);
                            health = healthMax * this.returnHealth;
                            container.healthBar.visible = true;
                            container.healthBar.cont.scaleX = health / healthMax;
                            readyDamage = true;
                            moveFlag = true;
                            var _loc_1:* = true;
                            this.mouseChildren = true;
                            this.mouseEnabled = _loc_1;
                            this.phase = 5;
                        }
                    }
                    if (container.dustAnima.visible)
                    {
                        if (container.dustAnima.currentFrame < container.dustAnima.totalFrames)
                        {
                            container.dustAnima.gotoAndStop((container.dustAnima.currentFrame + 1));
                        }
                        else
                        {
                            container.dustAnima.gotoAndStop(1);
                        }
                    }
                }
            }
            super.animationHandler();
            return;
        }// end function

        override public function kill() : void
        {
            if (!dead)
            {
                i = 0;
                while (i < world.listOfClasses.length)
                {
                    
                    if (world.listOfClasses[i] == this)
                    {
                        world.listOfClasses.splice(i, 1);
                        break;
                    }
                    var _loc_2:* = i + 1;
                    i = _loc_2;
                }
                i = 0;
                while (i < world.listOfIndexes0.length)
                {
                    
                    if (world.listOfIndexes0[i] == this)
                    {
                        world.listOfIndexes0.splice(i, 1);
                        break;
                    }
                    var _loc_2:* = i + 1;
                    i = _loc_2;
                }
                i = 0;
                while (i < world.listOfIndexes1.length)
                {
                    
                    if (world.listOfIndexes1[i] == this)
                    {
                        world.listOfIndexes1.splice(i, 1);
                        break;
                    }
                    var _loc_2:* = i + 1;
                    i = _loc_2;
                }
            }
            super.kill();
            return;
        }// end function

    }
}
