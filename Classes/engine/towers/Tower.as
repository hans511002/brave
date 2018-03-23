package engine.towers
{
    import engine.*;
    import flash.display.*;
    import flash.events.*;
    import flash.geom.*;

    public class Tower extends Sprite
    {
        public var i:int;
        public var j:int;
        public var tempObject:Object;
        public var tempObject1:Object;
        public var tempObject2:Object;
        public var tempObject3:Object;
        public var tempObject4:Object;
        public var container:MovieClip;
        public var myPlace:MovieClip;
        public var buildAnima:MovieClip;
        public var spheresStack:Array;
        public var slotsStack:Array;
        public var damage:Number;
        public var radius:Number;
        public var intervalCounter:int = 0;
        public var intervalTimer:int;
        public var dead:Boolean;
        public var world:World;
        public var towerType:int = 0;
        public var correctYGrPos:int;
        public var shootingTurnStack:Array;
        public var shootingSphere:String;
        public var shootinAttackStack:Array;
        public var listOfTargets:Array;
        public var this_pt:Point;
        public var enemy_pt:Point;
        public var shoot_pt:Point;
        public var enemyTarget:Object;
        public var testTarget:Object;
        public var greenFlag:Boolean;
        public var sphereBullet1:MovieClip;
        public var sphereBullet2:MovieClip;
        public var sphereBullet3:MovieClip;
        public var sphereBullet4:MovieClip;
        public var upgradeTypeAdd:int = 0;
        public var blockTowerFlag:Boolean;
        public var sphereVisibleTimer:int = 18;
        public var fireBulletCounter:int = 0;
        public var iceBulletCounter:int = 0;
        public var levinBulletCounter:int = 0;
        public var exchangeFlag:Boolean;
        public var autoBuild:Boolean;

        public function Tower()
        {
            this.spheresStack = [];
            this.shootingTurnStack = [null, null, null, null];
            this.shootinAttackStack = [];
            this.addEventListener(Event.ADDED_TO_STAGE, this.init);
            return;
        }// end function

        public function init(event:Event) : void
        {
            this.removeEventListener(Event.ADDED_TO_STAGE, this.init);
            this.world = Main.mainClass.worldClass;
            this.x = this.myPlace.x;
            this.y = this.myPlace.y;
            this.myPlace.placeForBuildCase.buttonMode = false;
            this.this_pt = new Point(this.x + this.container.x + this.container.towerCase.x, this.y + this.container.y + this.container.towerCase.y);
            this.shoot_pt = new Point(this.x, this.y + this.correctYGrPos);
            this.addBuildAnima();
            if (this.towerType < 5)
            {
                this.prepareSpheresGraphic();
            }
            if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[(this.towerType - 1)] == 0)
            {
                Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[(this.towerType - 1)] = 1;
            }
            if (!this.autoBuild)
            {
                if (this.towerType < 5)
                {
                    (this.world.saveBox.gameSave.data.addit_buildTowerCounter + 1);
                    if (this.world.saveBox.gameSave.data.addit_buildTowerCounter == 100)
                    {
                        this.world.achieveManage("build_100_towers");
                    }
                }
                else
                {
                    (this.world.saveBox.gameSave.data.addit_buildUltraTowersCounter + 1);
                    if (this.world.saveBox.gameSave.data.addit_buildUltraTowersCounter == 1)
                    {
                        this.world.achieveManage("buildUltraTower");
                    }
                    else if (this.world.saveBox.gameSave.data.addit_buildUltraTowersCounter == 50)
                    {
                        this.world.achieveManage("buildUltraTower_50_times");
                    }
                    this.tempObject1 = 0;
                    this.tempObject2 = 0;
                    this.tempObject3 = 0;
                    this.tempObject4 = 0;
                    this.i = 0;
                    while (this.i < this.world.listOfTowers.length)
                    {
                        
                        if (this.world.listOfTowers[this.i].towerType == 5)
                        {
                            (this.tempObject1 + 1);
                        }
                        else if (this.world.listOfTowers[this.i].towerType == 6)
                        {
                            (this.tempObject2 + 1);
                        }
                        else if (this.world.listOfTowers[this.i].towerType == 7)
                        {
                            (this.tempObject3 + 1);
                        }
                        else if (this.world.listOfTowers[this.i].towerType == 8)
                        {
                            (this.tempObject4 + 1);
                        }
                        var _loc_2:* = this;
                        var _loc_3:* = this.i + 1;
                        _loc_2.i = _loc_3;
                    }
                    if (this.tempObject1 > 0 && this.tempObject2 > 0 && this.tempObject3 > 0 && this.tempObject4 > 0)
                    {
                        this.world.achieveManage("buildAllUltraTowers");
                    }
                }
            }
            return;
        }// end function

        public function update() : void
        {
            if (!this.buildAnima)
            {
                if (this.towerType < 5)
                {
                    if (this.sphereBullet1)
                    {
                        if (this.sphereBullet1.counter > 0)
                        {
                            (this.sphereBullet1.counter - 1);
                        }
                        else
                        {
                            this.sphereBullet1.visible = true;
                            this.sphereBullet1 = null;
                        }
                    }
                    if (this.sphereBullet2)
                    {
                        if (this.sphereBullet2.counter > 0)
                        {
                            (this.sphereBullet2.counter - 1);
                        }
                        else
                        {
                            this.sphereBullet2.visible = true;
                            this.sphereBullet2 = null;
                        }
                    }
                    if (this.sphereBullet3)
                    {
                        if (this.sphereBullet3.counter > 0)
                        {
                            (this.sphereBullet3.counter - 1);
                        }
                        else
                        {
                            this.sphereBullet3.visible = true;
                            this.sphereBullet3 = null;
                        }
                    }
                    if (this.sphereBullet4)
                    {
                        if (this.sphereBullet4.counter > 0)
                        {
                            (this.sphereBullet4.counter - 1);
                        }
                        else
                        {
                            this.sphereBullet4.visible = true;
                            this.sphereBullet4 = null;
                        }
                    }
                }
                if (!this.enemyTarget)
                {
                    this.scan();
                }
                else
                {
                    this.attack();
                }
            }
            else if (this.buildAnima.currentFrame < this.buildAnima.totalFrames)
            {
                this.buildAnima.gotoAndStop((this.buildAnima.currentFrame + 1));
            }
            else
            {
                this.removeChild(this.buildAnima);
                this.buildAnima = null;
            }
            return;
        }// end function

        public function scan() : void
        {
            if (!this.container.blockTower.visible && !this.container.boneBlock.visible)
            {
                if (this.shootingTurnStack[0] || this.shootingTurnStack[1] || this.shootingTurnStack[2] || this.shootingTurnStack[3])
                {
                    this.greenFlag = false;
                    this.i = 0;
                    while (this.i < this.shootingTurnStack.length)
                    {
                        
                        if (this.shootingTurnStack[this.i])
                        {
                            if (this.shootingTurnStack[this.i][1] < this.shootingTurnStack[this.i][2])
                            {
                                (this.shootingTurnStack[this.i][1] + 1);
                            }
                            else
                            {
                                this.greenFlag = true;
                                this.shootingSphere = this.shootingTurnStack[this.i][0];
                                break;
                            }
                        }
                        var _loc_1:* = this;
                        var _loc_2:* = this.i + 1;
                        _loc_1.i = _loc_2;
                    }
                    if (this.greenFlag && this.world.frameCounter % 2)
                    {
                        this.scanBlock();
                        if (this.enemyTarget)
                        {
                            this.i = 0;
                            while (this.i < this.shootingTurnStack.length)
                            {
                                
                                if (this.shootingTurnStack[this.i])
                                {
                                    if (this.shootingTurnStack[this.i][1] >= this.shootingTurnStack[this.i][2])
                                    {
                                        this.shootingTurnStack[this.i][1] = 0;
                                        break;
                                    }
                                }
                                var _loc_1:* = this;
                                var _loc_2:* = this.i + 1;
                                _loc_1.i = _loc_2;
                            }
                            if (this.spheresStack.length > 1)
                            {
                                if (this.spheresStack.length == 2)
                                {
                                    this.i = 0;
                                    while (this.i < this.spheresStack.length)
                                    {
                                        
                                        if (this.spheresStack[this.i] == this.shootingSphere)
                                        {
                                            if (this.i == 0)
                                            {
                                                this.tempObject = this.container.sphere2_1.localToGlobal(new Point(this.container.sphere2_1.bullet.x, this.container.sphere2_1.bullet.y));
                                                if (this.sphereBullet1)
                                                {
                                                    this.sphereBullet1.visible = true;
                                                }
                                                var _loc_1:* = this.container.sphere2_1.bullet;
                                                this.sphereBullet1 = this.container.sphere2_1.bullet;
                                                this.tempObject2 = _loc_1;
                                                if (this.shootingSphere == "fire")
                                                {
                                                    this.tempObject1 = new BulletFireTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "ice")
                                                {
                                                    this.tempObject1 = new BulletIceTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "stone")
                                                {
                                                    this.tempObject1 = new BulletStoneTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "levin")
                                                {
                                                    this.tempObject1 = new BulletLevinTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                            }
                                            else if (this.i == 1)
                                            {
                                                this.tempObject = this.container.sphere2_2.localToGlobal(new Point(this.container.sphere2_2.bullet.x, this.container.sphere2_2.bullet.y));
                                                if (this.sphereBullet2)
                                                {
                                                    this.sphereBullet2.visible = true;
                                                }
                                                var _loc_1:* = this.container.sphere2_2.bullet;
                                                this.sphereBullet2 = this.container.sphere2_2.bullet;
                                                this.tempObject2 = _loc_1;
                                                if (this.shootingSphere == "fire")
                                                {
                                                    this.tempObject1 = new BulletFireTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "ice")
                                                {
                                                    this.tempObject1 = new BulletIceTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "stone")
                                                {
                                                    this.tempObject1 = new BulletStoneTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "levin")
                                                {
                                                    this.tempObject1 = new BulletLevinTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                            }
                                            this.tempObject2.counter = this.sphereVisibleTimer;
                                            this.tempObject2.visible = false;
                                            this.tempObject = this.container.globalToLocal(this.tempObject);
                                            this.tempObject1.x = this.tempObject.x;
                                            this.tempObject1.y = this.tempObject.y;
                                            this.tempObject1.counter = 3;
                                            this.tempObject1.distX = -this.tempObject.x / this.tempObject1.counter;
                                            this.tempObject1.distY = (-70 - this.tempObject.y) / this.tempObject1.counter;
                                            this.container.addChild(this.tempObject1);
                                            this.shootinAttackStack.push(this.tempObject1);
                                        }
                                        var _loc_1:* = this;
                                        var _loc_2:* = this.i + 1;
                                        _loc_1.i = _loc_2;
                                    }
                                }
                                else if (this.spheresStack.length == 3)
                                {
                                    this.i = 0;
                                    while (this.i < this.spheresStack.length)
                                    {
                                        
                                        if (this.spheresStack[this.i] == this.shootingSphere)
                                        {
                                            if (this.i == 0)
                                            {
                                                this.tempObject = this.container.sphere3_1.localToGlobal(new Point(this.container.sphere3_1.bullet.x, this.container.sphere3_1.bullet.y));
                                                if (this.sphereBullet1)
                                                {
                                                    this.sphereBullet1.visible = true;
                                                }
                                                var _loc_1:* = this.container.sphere3_1.bullet;
                                                this.sphereBullet1 = this.container.sphere3_1.bullet;
                                                this.tempObject2 = _loc_1;
                                                if (this.shootingSphere == "fire")
                                                {
                                                    this.tempObject1 = new BulletFireTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "ice")
                                                {
                                                    this.tempObject1 = new BulletIceTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "stone")
                                                {
                                                    this.tempObject1 = new BulletStoneTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "levin")
                                                {
                                                    this.tempObject1 = new BulletLevinTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                            }
                                            else if (this.i == 1)
                                            {
                                                this.tempObject = this.container.sphere3_2.localToGlobal(new Point(this.container.sphere3_2.bullet.x, this.container.sphere3_2.bullet.y));
                                                if (this.sphereBullet2)
                                                {
                                                    this.sphereBullet2.visible = true;
                                                }
                                                var _loc_1:* = this.container.sphere3_2.bullet;
                                                this.sphereBullet2 = this.container.sphere3_2.bullet;
                                                this.tempObject2 = _loc_1;
                                                if (this.shootingSphere == "fire")
                                                {
                                                    this.tempObject1 = new BulletFireTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "ice")
                                                {
                                                    this.tempObject1 = new BulletIceTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "stone")
                                                {
                                                    this.tempObject1 = new BulletStoneTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "levin")
                                                {
                                                    this.tempObject1 = new BulletLevinTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                            }
                                            else if (this.i == 2)
                                            {
                                                this.tempObject = this.container.sphere3_3.localToGlobal(new Point(this.container.sphere3_3.bullet.x, this.container.sphere3_3.bullet.y));
                                                if (this.sphereBullet3)
                                                {
                                                    this.sphereBullet3.visible = true;
                                                }
                                                var _loc_1:* = this.container.sphere3_3.bullet;
                                                this.sphereBullet3 = this.container.sphere3_3.bullet;
                                                this.tempObject2 = _loc_1;
                                                if (this.shootingSphere == "fire")
                                                {
                                                    this.tempObject1 = new BulletFireTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "ice")
                                                {
                                                    this.tempObject1 = new BulletIceTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "stone")
                                                {
                                                    this.tempObject1 = new BulletStoneTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "levin")
                                                {
                                                    this.tempObject1 = new BulletLevinTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                            }
                                            this.tempObject2.counter = this.sphereVisibleTimer;
                                            this.tempObject2.visible = false;
                                            this.tempObject = this.container.globalToLocal(this.tempObject);
                                            this.tempObject1.x = this.tempObject.x;
                                            this.tempObject1.y = this.tempObject.y;
                                            this.tempObject1.counter = 3;
                                            this.tempObject1.distX = -this.tempObject.x / this.tempObject1.counter;
                                            this.tempObject1.distY = (-70 - this.tempObject.y) / this.tempObject1.counter;
                                            this.container.addChild(this.tempObject1);
                                            this.shootinAttackStack.push(this.tempObject1);
                                        }
                                        var _loc_1:* = this;
                                        var _loc_2:* = this.i + 1;
                                        _loc_1.i = _loc_2;
                                    }
                                }
                                else if (this.spheresStack.length == 4)
                                {
                                    this.i = 0;
                                    while (this.i < this.spheresStack.length)
                                    {
                                        
                                        if (this.spheresStack[this.i] == this.shootingSphere)
                                        {
                                            if (this.i == 0)
                                            {
                                                this.tempObject = this.container.sphere4_1.localToGlobal(new Point(this.container.sphere4_1.bullet.x, this.container.sphere4_1.bullet.y));
                                                if (this.sphereBullet1)
                                                {
                                                    this.sphereBullet1.visible = true;
                                                }
                                                var _loc_1:* = this.container.sphere4_1.bullet;
                                                this.sphereBullet1 = this.container.sphere4_1.bullet;
                                                this.tempObject2 = _loc_1;
                                                if (this.shootingSphere == "fire")
                                                {
                                                    this.tempObject1 = new BulletFireTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "ice")
                                                {
                                                    this.tempObject1 = new BulletIceTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "stone")
                                                {
                                                    this.tempObject1 = new BulletStoneTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "levin")
                                                {
                                                    this.tempObject1 = new BulletLevinTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                            }
                                            else if (this.i == 1)
                                            {
                                                this.tempObject = this.container.sphere4_2.localToGlobal(new Point(this.container.sphere4_2.bullet.x, this.container.sphere4_2.bullet.y));
                                                if (this.sphereBullet2)
                                                {
                                                    this.sphereBullet2.visible = true;
                                                }
                                                var _loc_1:* = this.container.sphere4_2.bullet;
                                                this.sphereBullet2 = this.container.sphere4_2.bullet;
                                                this.tempObject2 = _loc_1;
                                                if (this.shootingSphere == "fire")
                                                {
                                                    this.tempObject1 = new BulletFireTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "ice")
                                                {
                                                    this.tempObject1 = new BulletIceTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "stone")
                                                {
                                                    this.tempObject1 = new BulletStoneTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "levin")
                                                {
                                                    this.tempObject1 = new BulletLevinTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                            }
                                            else if (this.i == 2)
                                            {
                                                this.tempObject = this.container.sphere4_3.localToGlobal(new Point(this.container.sphere4_3.bullet.x, this.container.sphere4_3.bullet.y));
                                                if (this.sphereBullet3)
                                                {
                                                    this.sphereBullet3.visible = true;
                                                }
                                                var _loc_1:* = this.container.sphere4_3.bullet;
                                                this.sphereBullet3 = this.container.sphere4_3.bullet;
                                                this.tempObject2 = _loc_1;
                                                if (this.shootingSphere == "fire")
                                                {
                                                    this.tempObject1 = new BulletFireTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "ice")
                                                {
                                                    this.tempObject1 = new BulletIceTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "stone")
                                                {
                                                    this.tempObject1 = new BulletStoneTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "levin")
                                                {
                                                    this.tempObject1 = new BulletLevinTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                            }
                                            else if (this.i == 3)
                                            {
                                                this.tempObject = this.container.sphere4_4.localToGlobal(new Point(this.container.sphere4_4.bullet.x, this.container.sphere4_4.bullet.y));
                                                if (this.sphereBullet4)
                                                {
                                                    this.sphereBullet4.visible = true;
                                                }
                                                var _loc_1:* = this.container.sphere4_4.bullet;
                                                this.sphereBullet4 = this.container.sphere4_4.bullet;
                                                this.tempObject2 = _loc_1;
                                                if (this.shootingSphere == "fire")
                                                {
                                                    this.tempObject1 = new BulletFireTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "ice")
                                                {
                                                    this.tempObject1 = new BulletIceTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "stone")
                                                {
                                                    this.tempObject1 = new BulletStoneTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                                else if (this.shootingSphere == "levin")
                                                {
                                                    this.tempObject1 = new BulletLevinTower_mc();
                                                    this.tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
                                                }
                                            }
                                            this.tempObject2.counter = this.sphereVisibleTimer;
                                            this.tempObject2.visible = false;
                                            this.tempObject = this.container.globalToLocal(this.tempObject);
                                            this.tempObject1.x = this.tempObject.x;
                                            this.tempObject1.y = this.tempObject.y;
                                            this.tempObject1.counter = 3;
                                            this.tempObject1.distX = -this.tempObject.x / this.tempObject1.counter;
                                            this.tempObject1.distY = (-70 - this.tempObject.y) / this.tempObject1.counter;
                                            this.container.addChild(this.tempObject1);
                                            this.shootinAttackStack.push(this.tempObject1);
                                        }
                                        var _loc_1:* = this;
                                        var _loc_2:* = this.i + 1;
                                        _loc_1.i = _loc_2;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                this.blockTowerFunk();
            }
            return;
        }// end function

        public function attack() : void
        {
            if (this.shootinAttackStack.length == 0)
            {
                this.tempObject = this.container.sphere1.localToGlobal(new Point(this.container.sphere1.bullet.x, this.container.sphere1.bullet.y));
                if (this.shootingSphere == "fire")
                {
                    this.tempObject = this.world.addBullet(1, this.tempObject, this, this.enemyTarget, Main.mainClass.readXMLClass.listOfFireTowerDamageXML[0], 1);
                    if (this.container.sphere1.bullet.cont)
                    {
                        this.tempObject.container.gotoAndStop(this.container.sphere1.bullet.cont.currentFrame);
                    }
                }
                else if (this.shootingSphere == "ice")
                {
                    this.tempObject = this.world.addBullet(2, this.tempObject, this, this.enemyTarget, Main.mainClass.readXMLClass.listOfIceTowerDamageXML[0], 1);
                    if (this.container.sphere1.bullet.cont)
                    {
                        this.tempObject.container.gotoAndStop(this.container.sphere1.bullet.cont.currentFrame);
                    }
                }
                else if (this.shootingSphere == "stone")
                {
                    this.tempObject = this.world.addBullet(3, this.tempObject, this, this.enemyTarget, Main.mainClass.readXMLClass.listOfStoneTowerDamageXML[0], 1);
                    if (this.container.sphere1.bullet.cont)
                    {
                        this.tempObject.container.gotoAndStop(this.container.sphere1.bullet.cont.currentFrame);
                    }
                }
                else if (this.shootingSphere == "levin")
                {
                    this.tempObject = this.world.addBullet(4, this.tempObject, this, this.enemyTarget, Main.mainClass.readXMLClass.listOfLevinTowerDamageXML[0], 1);
                    if (this.container.sphere1.bullet.cont)
                    {
                        this.tempObject.container.gotoAndStop(this.container.sphere1.bullet.cont.currentFrame);
                    }
                }
                if (this.sphereBullet1)
                {
                    this.sphereBullet1.visible = true;
                }
                var _loc_1:* = this.container.sphere1.bullet;
                this.sphereBullet1 = this.container.sphere1.bullet;
                this.tempObject2 = _loc_1;
                this.tempObject2.counter = this.sphereVisibleTimer;
                this.tempObject2.visible = false;
                this.shootingSphere = null;
                this.enemyTarget = null;
            }
            else
            {
                this.i = 0;
                while (this.i < this.shootinAttackStack.length)
                {
                    
                    if (this.shootinAttackStack[this.i].currentFrame < this.shootinAttackStack[this.i].totalFrames)
                    {
                        this.shootinAttackStack[this.i].gotoAndStop((this.shootinAttackStack[this.i].currentFrame + 1));
                    }
                    else
                    {
                        this.shootinAttackStack[this.i].gotoAndStop(1);
                    }
                    if (this.shootinAttackStack[this.i].counter > 0)
                    {
                        (this.shootinAttackStack[this.i].counter - 1);
                        this.shootinAttackStack[this.i].x = this.shootinAttackStack[this.i].x + this.shootinAttackStack[this.i].distX;
                        this.shootinAttackStack[this.i].y = this.shootinAttackStack[this.i].y + this.shootinAttackStack[this.i].distY;
                    }
                    else
                    {
                        this.tempObject = this.container.localToGlobal(new Point(this.shootinAttackStack[0].x, this.shootinAttackStack[0].y));
                        if (this.shootingSphere == "fire")
                        {
                            if (this.shootingTurnStack[0])
                            {
                                this.tempObject = this.world.addBullet(1, this.tempObject, this, this.enemyTarget, Main.mainClass.readXMLClass.listOfFireTowerDamageXML[(this.shootingTurnStack[0][3] - 1)], this.shootingTurnStack[0][3]);
                            }
                            else
                            {
                                this.tempObject = null;
                            }
                        }
                        else if (this.shootingSphere == "ice")
                        {
                            if (this.shootingTurnStack[1])
                            {
                                this.tempObject = this.world.addBullet(2, this.tempObject, this, this.enemyTarget, Main.mainClass.readXMLClass.listOfIceTowerDamageXML[(this.shootingTurnStack[1][3] - 1)], this.shootingTurnStack[1][3]);
                            }
                            else
                            {
                                this.tempObject = null;
                            }
                        }
                        else if (this.shootingSphere == "stone")
                        {
                            if (this.shootingTurnStack[2])
                            {
                                this.tempObject = this.world.addBullet(3, this.tempObject, this, this.enemyTarget, Main.mainClass.readXMLClass.listOfStoneTowerDamageXML[(this.shootingTurnStack[2][3] - 1)], this.shootingTurnStack[2][3]);
                            }
                            else
                            {
                                this.tempObject = null;
                            }
                        }
                        else if (this.shootingSphere == "levin")
                        {
                            if (this.shootingTurnStack[3])
                            {
                                this.tempObject = this.world.addBullet(4, this.tempObject, this, this.enemyTarget, Main.mainClass.readXMLClass.listOfLevinTowerDamageXML[(this.shootingTurnStack[3][3] - 1)], this.shootingTurnStack[3][3]);
                            }
                            else
                            {
                                this.tempObject = null;
                            }
                        }
                        if (this.tempObject)
                        {
                            this.tempObject.container.gotoAndStop(this.shootinAttackStack[0].currentFrame);
                        }
                        this.shootingSphere = null;
                        this.enemyTarget = null;
                        this.j = this.shootinAttackStack.length - 1;
                        while (this.j >= 0)
                        {
                            
                            this.container.removeChild(this.shootinAttackStack[this.j]);
                            this.shootinAttackStack.splice(this.j, 1);
                            var _loc_1:* = this;
                            var _loc_2:* = this.j - 1;
                            _loc_1.j = _loc_2;
                        }
                        break;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            return;
        }// end function

        public function scanAtRadius() : void
        {
            this.greenFlag = false;
            this.tempObject = this.radius - this.radius * (1 - this.world.scaleRadius);
            if ((this.testTarget.x - this.this_pt.x) * (this.testTarget.x - this.this_pt.x) / (this.radius * this.radius) + (this.testTarget.y - this.this_pt.y) * (this.testTarget.y - this.this_pt.y) / (this.tempObject * this.tempObject) <= 1)
            {
                this.greenFlag = true;
            }
            return;
        }// end function

        public function spheresManage(param1:String, param2:String = null, param3:int = 0) : Object
        {
            if (this.towerType < 5)
            {
                if (param1 == "scan")
                {
                    if (this.slotsStack.length > 0)
                    {
                        if (this.slotsStack[3] == 0)
                        {
                            this.tempObject = 4 - this.spheresStack.length;
                            return this.tempObject;
                        }
                        if (this.slotsStack[2] == 0)
                        {
                            this.tempObject = 3 - this.spheresStack.length;
                            return this.tempObject;
                        }
                        if (this.slotsStack[1] == 0)
                        {
                            this.tempObject = 2 - this.spheresStack.length;
                            return this.tempObject;
                        }
                        if (this.slotsStack[0] == 0)
                        {
                            this.tempObject = 1 - this.spheresStack.length;
                            return this.tempObject;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (param1 == "push")
                {
                    if (this.world.towerMenu)
                    {
                        if (this.world.towerMenu.myTower == this && this.world.nowLevel > 1 && this.world.nowLevel < 5)
                        {
                            if (!this.world.towerMenu.training_12)
                            {
                                if (!Main.mainClass.saveBoxClass.gameSave.data.firstClickKeepAll)
                                {
                                    this.world.towerMenu.training_12 = new Training_12();
                                    this.world.towerMenu.addChild(this.world.towerMenu.training_12);
                                }
                            }
                        }
                    }
                    this.tempObject1 = this.spheresManage("scan");
                    if (param2 != "getAll")
                    {
                        if (this.tempObject1 >= param3)
                        {
                            while (param3 > 0)
                            {
                                
                                param3 = param3 - 1;
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                            }
                            this.prepareSpheresGraphic();
                            return 0;
                        }
                        else
                        {
                            this.i = 1;
                            while (this.i <= this.tempObject1)
                            {
                                
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                                var _loc_4:* = this;
                                var _loc_5:* = this.i + 1;
                                _loc_4.i = _loc_5;
                            }
                            this.tempObject = param3 - this.tempObject1;
                            if (this.tempObject != param3)
                            {
                                this.prepareSpheresGraphic();
                            }
                            return this.tempObject;
                        }
                    }
                    else
                    {
                        if (this.tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            this.i = 1;
                            while (this.i <= this.tempObject1)
                            {
                                
                                if (this.i == 1)
                                {
                                    this.spheresStack.push("fire");
                                    this.shootingStackManage("add", "fire");
                                }
                                else if (this.i == 2)
                                {
                                    this.spheresStack.push("ice");
                                    this.shootingStackManage("add", "ice");
                                }
                                else if (this.i == 3)
                                {
                                    this.spheresStack.push("stone");
                                    this.shootingStackManage("add", "stone");
                                }
                                else if (this.i == 4)
                                {
                                    this.spheresStack.push("levin");
                                    this.shootingStackManage("add", "levin");
                                }
                                this.prepareSpheresGraphic();
                                var _loc_4:* = this;
                                var _loc_5:* = this.i + 1;
                                _loc_4.i = _loc_5;
                            }
                            if (this.tempObject1 < 4)
                            {
                                if (this.tempObject1 < 4)
                                {
                                    this.world.feature.getSphereBeat("levin", 1);
                                    this.world.getSphere.x = this.this_pt.x;
                                    this.world.getSphere.y = this.this_pt.y;
                                    this.world.getSphere.retrieveGetSphere();
                                }
                                if (this.tempObject1 < 3)
                                {
                                    this.world.feature.getSphereBeat("stone", 1);
                                    this.world.getSphere.x = this.this_pt.x;
                                    this.world.getSphere.y = this.this_pt.y;
                                    this.world.getSphere.retrieveGetSphere();
                                }
                                if (this.tempObject1 < 2)
                                {
                                    this.world.feature.getSphereBeat("ice", 1);
                                    this.world.getSphere.x = this.this_pt.x;
                                    this.world.getSphere.y = this.this_pt.y;
                                    this.world.getSphere.retrieveGetSphere();
                                }
                            }
                        }
                        return param3;
                    }
                }
                else if (param1 == "get")
                {
                    this.tempObject = 0;
                    this.i = this.spheresStack.length - 1;
                    while (this.i >= 0)
                    {
                        
                        if (this.spheresStack[this.i] == param2)
                        {
                            if (this.tempObject < param3)
                            {
                                this.spheresStack.splice(this.i, 1);
                                this.shootingStackManage("remove", param2);
                                (this.tempObject + 1);
                            }
                            else
                            {
                                break;
                            }
                        }
                        var _loc_4:* = this;
                        var _loc_5:* = this.i - 1;
                        _loc_4.i = _loc_5;
                    }
                    if (this.tempObject > 0)
                    {
                        this.prepareSpheresGraphic();
                    }
                    return this.tempObject;
                }
            }
            else if (param1 == "scan")
            {
                if (this.towerType == 5)
                {
                    if (Main.mainClass.readXMLClass.ultraTower1UpgrBlock > 0)
                    {
                        return 0;
                    }
                    this.tempObject = 0;
                    if (!this.shootingTurnStack[0])
                    {
                        (this.tempObject + 1);
                    }
                    if (!this.shootingTurnStack[2])
                    {
                        (this.tempObject + 1);
                    }
                    return this.tempObject;
                }
                else if (this.towerType == 6)
                {
                    if (Main.mainClass.readXMLClass.ultraTower2UpgrBlock > 0)
                    {
                        return 0;
                    }
                    this.tempObject = 0;
                    if (!this.shootingTurnStack[1])
                    {
                        (this.tempObject + 1);
                    }
                    if (!this.shootingTurnStack[3])
                    {
                        (this.tempObject + 1);
                    }
                    return this.tempObject;
                }
                else if (this.towerType == 7)
                {
                    if (Main.mainClass.readXMLClass.ultraTower3UpgrBlock > 0)
                    {
                        return 0;
                    }
                    this.tempObject = 0;
                    if (!this.shootingTurnStack[1])
                    {
                        (this.tempObject + 1);
                    }
                    if (!this.shootingTurnStack[2])
                    {
                        (this.tempObject + 1);
                    }
                    return this.tempObject;
                }
                else if (this.towerType == 8)
                {
                    if (Main.mainClass.readXMLClass.ultraTower4UpgrBlock > 0)
                    {
                        return 0;
                    }
                    this.tempObject = 0;
                    if (!this.shootingTurnStack[0])
                    {
                        (this.tempObject + 1);
                    }
                    if (!this.shootingTurnStack[3])
                    {
                        (this.tempObject + 1);
                    }
                    return this.tempObject;
                }
            }
            else if (param1 == "push")
            {
                if (this.towerType == 5)
                {
                    if (Main.mainClass.readXMLClass.ultraTower1UpgrBlock > 0)
                    {
                        return param3;
                    }
                    if (param2 == "fire")
                    {
                        if (param3 > 0)
                        {
                            if (!this.shootingTurnStack[0])
                            {
                                param3 = param3 - 1;
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "stone")
                    {
                        if (param3 > 0)
                        {
                            if (!this.shootingTurnStack[2])
                            {
                                param3 = param3 - 1;
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "getAll")
                    {
                        this.tempObject1 = this.spheresManage("scan");
                        if (this.tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            if (!this.shootingTurnStack[0])
                            {
                                this.spheresStack.push("fire");
                                this.shootingStackManage("add", "fire");
                            }
                            else
                            {
                                this.world.feature.getSphereBeat("fire", 1);
                                this.world.getSphere.x = this.this_pt.x;
                                this.world.getSphere.y = this.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            if (!this.shootingTurnStack[2])
                            {
                                this.spheresStack.push("stone");
                                this.shootingStackManage("add", "stone");
                            }
                            else
                            {
                                this.world.feature.getSphereBeat("stone", 1);
                                this.world.getSphere.x = this.this_pt.x;
                                this.world.getSphere.y = this.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            this.world.feature.getSphereBeat("ice", 1);
                            this.world.getSphere.x = this.this_pt.x;
                            this.world.getSphere.y = this.this_pt.y;
                            this.world.getSphere.retrieveGetSphere();
                            this.world.feature.getSphereBeat("levin", 1);
                            this.world.getSphere.x = this.this_pt.x;
                            this.world.getSphere.y = this.this_pt.y;
                            this.world.getSphere.retrieveGetSphere();
                        }
                        return param3;
                    }
                    else
                    {
                        return param3;
                    }
                }
                else if (this.towerType == 6)
                {
                    if (Main.mainClass.readXMLClass.ultraTower2UpgrBlock > 0)
                    {
                        return param3;
                    }
                    if (param2 == "ice")
                    {
                        if (param3 > 0)
                        {
                            if (!this.shootingTurnStack[1])
                            {
                                param3 = param3 - 1;
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "levin")
                    {
                        if (param3 > 0)
                        {
                            if (!this.shootingTurnStack[3])
                            {
                                param3 = param3 - 1;
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "getAll")
                    {
                        this.tempObject1 = this.spheresManage("scan");
                        if (this.tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            if (!this.shootingTurnStack[1])
                            {
                                this.spheresStack.push("ice");
                                this.shootingStackManage("add", "ice");
                            }
                            else
                            {
                                this.world.feature.getSphereBeat("ice", 1);
                                this.world.getSphere.x = this.this_pt.x;
                                this.world.getSphere.y = this.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            if (!this.shootingTurnStack[3])
                            {
                                this.spheresStack.push("levin");
                                this.shootingStackManage("add", "levin");
                            }
                            else
                            {
                                this.world.feature.getSphereBeat("levin", 1);
                                this.world.getSphere.x = this.this_pt.x;
                                this.world.getSphere.y = this.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            this.world.feature.getSphereBeat("fire", 1);
                            this.world.getSphere.x = this.this_pt.x;
                            this.world.getSphere.y = this.this_pt.y;
                            this.world.getSphere.retrieveGetSphere();
                            this.world.feature.getSphereBeat("stone", 1);
                            this.world.getSphere.x = this.this_pt.x;
                            this.world.getSphere.y = this.this_pt.y;
                            this.world.getSphere.retrieveGetSphere();
                        }
                        return param3;
                    }
                    else
                    {
                        return param3;
                    }
                }
                else if (this.towerType == 7)
                {
                    if (Main.mainClass.readXMLClass.ultraTower3UpgrBlock > 0)
                    {
                        return param3;
                    }
                    if (param2 == "ice")
                    {
                        if (param3 > 0)
                        {
                            if (!this.shootingTurnStack[1])
                            {
                                param3 = param3 - 1;
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "stone")
                    {
                        if (param3 > 0)
                        {
                            if (!this.shootingTurnStack[2])
                            {
                                param3 = param3 - 1;
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "getAll")
                    {
                        this.tempObject1 = this.spheresManage("scan");
                        if (this.tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            if (!this.shootingTurnStack[1])
                            {
                                this.spheresStack.push("ice");
                                this.shootingStackManage("add", "ice");
                            }
                            else
                            {
                                this.world.feature.getSphereBeat("ice", 1);
                                this.world.getSphere.x = this.this_pt.x;
                                this.world.getSphere.y = this.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            if (!this.shootingTurnStack[3])
                            {
                                this.spheresStack.push("stone");
                                this.shootingStackManage("add", "stone");
                            }
                            else
                            {
                                this.world.feature.getSphereBeat("stone", 1);
                                this.world.getSphere.x = this.this_pt.x;
                                this.world.getSphere.y = this.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            this.world.feature.getSphereBeat("fire", 1);
                            this.world.getSphere.x = this.this_pt.x;
                            this.world.getSphere.y = this.this_pt.y;
                            this.world.getSphere.retrieveGetSphere();
                            this.world.feature.getSphereBeat("levin", 1);
                            this.world.getSphere.x = this.this_pt.x;
                            this.world.getSphere.y = this.this_pt.y;
                            this.world.getSphere.retrieveGetSphere();
                        }
                        return param3;
                    }
                    else
                    {
                        return param3;
                    }
                }
                else if (this.towerType == 8)
                {
                    if (Main.mainClass.readXMLClass.ultraTower4UpgrBlock > 0)
                    {
                        return param3;
                    }
                    if (param2 == "fire")
                    {
                        if (param3 > 0)
                        {
                            if (!this.shootingTurnStack[0])
                            {
                                param3 = param3 - 1;
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "levin")
                    {
                        if (param3 > 0)
                        {
                            if (!this.shootingTurnStack[3])
                            {
                                param3 = param3 - 1;
                                this.spheresStack.push(param2);
                                this.shootingStackManage("add", param2);
                                return param3;
                            }
                            return param3;
                        }
                        else
                        {
                            return param3;
                        }
                    }
                    else if (param2 == "getAll")
                    {
                        this.tempObject1 = this.spheresManage("scan");
                        if (this.tempObject1 > 0)
                        {
                            param3 = param3 - 1;
                            if (!this.shootingTurnStack[1])
                            {
                                this.spheresStack.push("fire");
                                this.shootingStackManage("add", "fire");
                            }
                            else
                            {
                                this.world.feature.getSphereBeat("fire", 1);
                                this.world.getSphere.x = this.this_pt.x;
                                this.world.getSphere.y = this.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            if (!this.shootingTurnStack[3])
                            {
                                this.spheresStack.push("levin");
                                this.shootingStackManage("add", "levin");
                            }
                            else
                            {
                                this.world.feature.getSphereBeat("levin", 1);
                                this.world.getSphere.x = this.this_pt.x;
                                this.world.getSphere.y = this.this_pt.y;
                                this.world.getSphere.retrieveGetSphere();
                            }
                            this.world.feature.getSphereBeat("ice", 1);
                            this.world.getSphere.x = this.this_pt.x;
                            this.world.getSphere.y = this.this_pt.y;
                            this.world.getSphere.retrieveGetSphere();
                            this.world.feature.getSphereBeat("stone", 1);
                            this.world.getSphere.x = this.this_pt.x;
                            this.world.getSphere.y = this.this_pt.y;
                            this.world.getSphere.retrieveGetSphere();
                        }
                        return param3;
                    }
                    else
                    {
                        return param3;
                    }
                }
            }
            else if (param1 == "get")
            {
                if (param2 == "fire")
                {
                    if (this.shootingTurnStack[0])
                    {
                        this.i = 0;
                        while (this.i < param3)
                        {
                            
                            if (this.shootingTurnStack[0])
                            {
                                (this.i + 1);
                                this.shootingStackManage("remove", param2);
                                continue;
                            }
                            return this.i;
                        }
                        return this.i;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (param2 == "ice")
                {
                    if (this.shootingTurnStack[1])
                    {
                        this.i = 0;
                        while (this.i < param3)
                        {
                            
                            if (this.shootingTurnStack[1])
                            {
                                (this.i + 1);
                                this.shootingStackManage("remove", param2);
                                continue;
                            }
                            return this.i;
                        }
                        return this.i;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (param2 == "stone")
                {
                    if (this.shootingTurnStack[2])
                    {
                        this.i = 0;
                        while (this.i < param3)
                        {
                            
                            if (this.shootingTurnStack[2])
                            {
                                (this.i + 1);
                                this.shootingStackManage("remove", param2);
                                continue;
                            }
                            return this.i;
                        }
                        return this.i;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (param2 == "levin")
                {
                    if (this.shootingTurnStack[3])
                    {
                        this.i = 0;
                        while (this.i < param3)
                        {
                            
                            if (this.shootingTurnStack[3])
                            {
                                (this.i + 1);
                                this.shootingStackManage("remove", param2);
                                continue;
                            }
                            return this.i;
                        }
                        return this.i;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            return;
        }// end function

        public function shootingStackManage(param1:String, param2:String) : void
        {
            if (param1 == "add")
            {
                if (param2 == "fire")
                {
                    if (!this.shootingTurnStack[0])
                    {
                        this.shootingTurnStack[0] = [param2, Main.mainClass.readXMLClass.fireTowerIntervalXML, Main.mainClass.readXMLClass.fireTowerIntervalXML, 1];
                    }
                    else
                    {
                        (this.shootingTurnStack[0][3] + 1);
                    }
                    this.shootingTurnStack[0][1] = Main.mainClass.readXMLClass.fireTowerIntervalXML - 10;
                }
                else if (param2 == "ice")
                {
                    if (!this.shootingTurnStack[1])
                    {
                        this.shootingTurnStack[1] = [param2, Main.mainClass.readXMLClass.iceTowerIntervalXML, Main.mainClass.readXMLClass.iceTowerIntervalXML, 1];
                    }
                    else
                    {
                        (this.shootingTurnStack[1][3] + 1);
                    }
                    this.shootingTurnStack[1][1] = Main.mainClass.readXMLClass.iceTowerIntervalXML - 10;
                }
                else if (param2 == "stone")
                {
                    if (!this.shootingTurnStack[2])
                    {
                        this.shootingTurnStack[2] = [param2, Main.mainClass.readXMLClass.stoneTowerIntervalXML, Main.mainClass.readXMLClass.stoneTowerIntervalXML, 1];
                    }
                    else
                    {
                        (this.shootingTurnStack[2][3] + 1);
                    }
                    this.shootingTurnStack[2][1] = Main.mainClass.readXMLClass.stoneTowerIntervalXML - 10;
                }
                else if (param2 == "levin")
                {
                    if (!this.shootingTurnStack[3])
                    {
                        this.shootingTurnStack[3] = [param2, Main.mainClass.readXMLClass.levinTowerIntervalXML, Main.mainClass.readXMLClass.levinTowerIntervalXML, 1];
                    }
                    else
                    {
                        (this.shootingTurnStack[3][3] + 1);
                    }
                    this.shootingTurnStack[3][1] = Main.mainClass.readXMLClass.levinTowerIntervalXML - 10;
                }
                if (this.shootingTurnStack[0] && this.shootingTurnStack[1] && this.shootingTurnStack[2] && this.shootingTurnStack[3])
                {
                    this.shootingTurnStack[0][1] = Math.round(this.shootingTurnStack[0][1] * 0.85);
                    this.shootingTurnStack[1][1] = Math.round(this.shootingTurnStack[1][1] * 0.85);
                    this.shootingTurnStack[2][1] = Math.round(this.shootingTurnStack[2][1] * 0.85);
                    this.shootingTurnStack[3][1] = Math.round(this.shootingTurnStack[3][1] * 0.85);
                }
                else if (!this.shootingTurnStack[0] && this.shootingTurnStack[1] && this.shootingTurnStack[2] && this.shootingTurnStack[3] || this.shootingTurnStack[0] && !this.shootingTurnStack[1] && this.shootingTurnStack[2] && this.shootingTurnStack[3] || this.shootingTurnStack[0] && this.shootingTurnStack[1] && !this.shootingTurnStack[2] && this.shootingTurnStack[3] || this.shootingTurnStack[0] && this.shootingTurnStack[1] && this.shootingTurnStack[2] && !this.shootingTurnStack[3])
                {
                    if (this.shootingTurnStack[0])
                    {
                        this.shootingTurnStack[0][1] = Math.round(this.shootingTurnStack[0][1] * 0.9);
                    }
                    if (this.shootingTurnStack[1])
                    {
                        this.shootingTurnStack[1][1] = Math.round(this.shootingTurnStack[1][1] * 0.9);
                    }
                    if (this.shootingTurnStack[2])
                    {
                        this.shootingTurnStack[2][1] = Math.round(this.shootingTurnStack[2][1] * 0.9);
                    }
                    if (this.shootingTurnStack[3])
                    {
                        this.shootingTurnStack[3][1] = Math.round(this.shootingTurnStack[3][1] * 0.9);
                    }
                }
                else if (this.shootingTurnStack[0] && this.shootingTurnStack[1] && !this.shootingTurnStack[2] && !this.shootingTurnStack[3] || !this.shootingTurnStack[0] && this.shootingTurnStack[1] && this.shootingTurnStack[2] && !this.shootingTurnStack[3] || !this.shootingTurnStack[0] && !this.shootingTurnStack[1] && this.shootingTurnStack[2] && this.shootingTurnStack[3] || !this.shootingTurnStack[0] && this.shootingTurnStack[1] && !this.shootingTurnStack[2] && this.shootingTurnStack[3] || this.shootingTurnStack[0] && !this.shootingTurnStack[1] && this.shootingTurnStack[2] && !this.shootingTurnStack[3] || this.shootingTurnStack[0] && !this.shootingTurnStack[1] && !this.shootingTurnStack[2] && this.shootingTurnStack[3])
                {
                    if (this.shootingTurnStack[0])
                    {
                        this.shootingTurnStack[0][1] = Math.round(this.shootingTurnStack[0][1] * 0.95);
                    }
                    if (this.shootingTurnStack[1])
                    {
                        this.shootingTurnStack[1][1] = Math.round(this.shootingTurnStack[1][1] * 0.95);
                    }
                    if (this.shootingTurnStack[2])
                    {
                        this.shootingTurnStack[2][1] = Math.round(this.shootingTurnStack[2][1] * 0.95);
                    }
                    if (this.shootingTurnStack[3])
                    {
                        this.shootingTurnStack[3][1] = Math.round(this.shootingTurnStack[3][1] * 0.95);
                    }
                }
            }
            else if (param1 == "remove")
            {
                this.j = 0;
                while (this.j < this.shootingTurnStack.length)
                {
                    
                    if (this.shootingTurnStack[this.j])
                    {
                        if (this.shootingTurnStack[this.j][0] == param2)
                        {
                            if (this.shootingTurnStack[this.j][3] > 1)
                            {
                                (this.shootingTurnStack[this.j][3] - 1);
                            }
                            else
                            {
                                this.shootingTurnStack[this.j] = null;
                            }
                            break;
                        }
                    }
                    var _loc_3:* = this;
                    var _loc_4:* = this.j + 1;
                    _loc_3.j = _loc_4;
                }
            }
            return;
        }// end function

        public function prepareSpheresGraphic() : void
        {
            if (this.towerType >= 1)
            {
                this.container.sphere1.gotoAndStop(1);
                this.container.sphere1.bullet.gotoAndStop(1);
                this.container.sphere1.bullet.cont.gotoAndStop(1);
                this.container.sphere1.visible = false;
            }
            if (this.towerType >= 2)
            {
                this.container.sphere2_1.gotoAndStop(1);
                this.container.sphere2_2.gotoAndStop(24);
                this.container.sphere2_1.bullet.gotoAndStop(1);
                this.container.sphere2_2.bullet.gotoAndStop(1);
                this.container.sphere2_1.bullet.cont.gotoAndStop(1);
                this.container.sphere2_2.bullet.cont.gotoAndStop(1);
                this.container.sphere2_1.visible = false;
                this.container.sphere2_2.visible = false;
            }
            if (this.towerType >= 3)
            {
                this.container.sphere3_1.gotoAndStop(1);
                this.container.sphere3_2.gotoAndStop(18);
                this.container.sphere3_3.gotoAndStop(35);
                this.container.sphere3_1.bullet.gotoAndStop(1);
                this.container.sphere3_2.bullet.gotoAndStop(1);
                this.container.sphere3_3.bullet.gotoAndStop(1);
                this.container.sphere3_1.bullet.cont.gotoAndStop(1);
                this.container.sphere3_2.bullet.cont.gotoAndStop(1);
                this.container.sphere3_3.bullet.cont.gotoAndStop(1);
                this.container.sphere3_1.visible = false;
                this.container.sphere3_2.visible = false;
                this.container.sphere3_3.visible = false;
            }
            if (this.towerType == 4)
            {
                this.container.sphere4_1.gotoAndStop(1);
                this.container.sphere4_2.gotoAndStop(15);
                this.container.sphere4_3.gotoAndStop(29);
                this.container.sphere4_4.gotoAndStop(43);
                this.container.sphere4_1.bullet.gotoAndStop(1);
                this.container.sphere4_2.bullet.gotoAndStop(1);
                this.container.sphere4_3.bullet.gotoAndStop(1);
                this.container.sphere4_4.bullet.gotoAndStop(1);
                this.container.sphere4_1.bullet.cont.gotoAndStop(1);
                this.container.sphere4_2.bullet.cont.gotoAndStop(1);
                this.container.sphere4_3.bullet.cont.gotoAndStop(1);
                this.container.sphere4_4.bullet.cont.gotoAndStop(1);
                this.container.sphere4_1.visible = false;
                this.container.sphere4_2.visible = false;
                this.container.sphere4_3.visible = false;
                this.container.sphere4_4.visible = false;
            }
            if (this.towerType == 1)
            {
                if (this.spheresStack.length == 1)
                {
                    this.prepareSpheresGraphicAid(1);
                }
            }
            else if (this.towerType == 2)
            {
                if (this.spheresStack.length == 1)
                {
                    this.prepareSpheresGraphicAid(1);
                }
                else if (this.spheresStack.length == 2)
                {
                    this.prepareSpheresGraphicAid(2);
                }
            }
            else if (this.towerType == 3)
            {
                if (this.spheresStack.length == 1)
                {
                    this.prepareSpheresGraphicAid(1);
                }
                else if (this.spheresStack.length == 2)
                {
                    this.prepareSpheresGraphicAid(2);
                }
                else if (this.spheresStack.length == 3)
                {
                    this.prepareSpheresGraphicAid(3);
                }
            }
            else if (this.towerType == 4)
            {
                if (this.spheresStack.length == 1)
                {
                    this.prepareSpheresGraphicAid(1);
                }
                else if (this.spheresStack.length == 2)
                {
                    this.prepareSpheresGraphicAid(2);
                }
                else if (this.spheresStack.length == 3)
                {
                    this.prepareSpheresGraphicAid(3);
                }
                else if (this.spheresStack.length == 4)
                {
                    this.prepareSpheresGraphicAid(4);
                }
            }
            return;
        }// end function

        public function prepareSpheresGraphicAid(param1:int) : void
        {
            if (param1 == 1)
            {
                this.container.sphere1.gotoAndStop(1);
                this.container.sphere1.visible = true;
                if (this.spheresStack[0] == "fire")
                {
                    this.container.sphere1.bullet.gotoAndStop(1);
                    this.container.sphere1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "ice")
                {
                    this.container.sphere1.bullet.gotoAndStop(2);
                    this.container.sphere1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "stone")
                {
                    this.container.sphere1.bullet.gotoAndStop(3);
                    this.container.sphere1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "levin")
                {
                    this.container.sphere1.bullet.gotoAndStop(4);
                    this.container.sphere1.bullet.cont.gotoAndStop(1);
                }
            }
            else if (param1 == 2)
            {
                this.container.sphere2_1.gotoAndStop(1);
                this.container.sphere2_1.visible = true;
                if (this.spheresStack[0] == "fire")
                {
                    this.container.sphere2_1.bullet.gotoAndStop(1);
                    this.container.sphere2_1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "ice")
                {
                    this.container.sphere2_1.bullet.gotoAndStop(2);
                    this.container.sphere2_1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "stone")
                {
                    this.container.sphere2_1.bullet.gotoAndStop(3);
                    this.container.sphere2_1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "levin")
                {
                    this.container.sphere2_1.bullet.gotoAndStop(4);
                    this.container.sphere2_1.bullet.cont.gotoAndStop(1);
                }
                this.container.sphere2_2.gotoAndStop(23);
                this.container.sphere2_2.visible = true;
                if (this.spheresStack[1] == "fire")
                {
                    this.container.sphere2_2.bullet.gotoAndStop(1);
                    this.container.sphere2_2.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[1] == "ice")
                {
                    this.container.sphere2_2.bullet.gotoAndStop(2);
                    this.container.sphere2_2.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[1] == "stone")
                {
                    this.container.sphere2_2.bullet.gotoAndStop(3);
                    this.container.sphere2_2.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[1] == "levin")
                {
                    this.container.sphere2_2.bullet.gotoAndStop(4);
                    this.container.sphere2_2.bullet.cont.gotoAndStop(1);
                }
            }
            else if (param1 == 3)
            {
                this.container.sphere3_1.gotoAndStop(1);
                this.container.sphere3_1.visible = true;
                if (this.spheresStack[0] == "fire")
                {
                    this.container.sphere3_1.bullet.gotoAndStop(1);
                    this.container.sphere3_1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "ice")
                {
                    this.container.sphere3_1.bullet.gotoAndStop(2);
                    this.container.sphere3_1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "stone")
                {
                    this.container.sphere3_1.bullet.gotoAndStop(3);
                    this.container.sphere3_1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "levin")
                {
                    this.container.sphere3_1.bullet.gotoAndStop(4);
                    this.container.sphere3_1.bullet.cont.gotoAndStop(1);
                }
                this.container.sphere3_2.gotoAndStop(17);
                this.container.sphere3_2.visible = true;
                if (this.spheresStack[1] == "fire")
                {
                    this.container.sphere3_2.bullet.gotoAndStop(1);
                    this.container.sphere3_2.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[1] == "ice")
                {
                    this.container.sphere3_2.bullet.gotoAndStop(2);
                    this.container.sphere3_2.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[1] == "stone")
                {
                    this.container.sphere3_2.bullet.gotoAndStop(3);
                    this.container.sphere3_2.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[1] == "levin")
                {
                    this.container.sphere3_2.bullet.gotoAndStop(4);
                    this.container.sphere3_2.bullet.cont.gotoAndStop(1);
                }
                this.container.sphere3_3.gotoAndStop(34);
                this.container.sphere3_3.visible = true;
                if (this.spheresStack[2] == "fire")
                {
                    this.container.sphere3_3.bullet.gotoAndStop(1);
                    this.container.sphere3_3.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[2] == "ice")
                {
                    this.container.sphere3_3.bullet.gotoAndStop(2);
                    this.container.sphere3_3.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[2] == "stone")
                {
                    this.container.sphere3_3.bullet.gotoAndStop(3);
                    this.container.sphere3_3.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[2] == "levin")
                {
                    this.container.sphere3_3.bullet.gotoAndStop(4);
                    this.container.sphere3_3.bullet.cont.gotoAndStop(1);
                }
            }
            else if (param1 == 4)
            {
                this.container.sphere4_1.gotoAndStop(1);
                this.container.sphere4_1.visible = true;
                if (this.spheresStack[0] == "fire")
                {
                    this.container.sphere4_1.bullet.gotoAndStop(1);
                    this.container.sphere4_1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "ice")
                {
                    this.container.sphere4_1.bullet.gotoAndStop(2);
                    this.container.sphere4_1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "stone")
                {
                    this.container.sphere4_1.bullet.gotoAndStop(3);
                    this.container.sphere4_1.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[0] == "levin")
                {
                    this.container.sphere4_1.bullet.gotoAndStop(4);
                    this.container.sphere4_1.bullet.cont.gotoAndStop(1);
                }
                this.container.sphere4_2.gotoAndStop(14);
                this.container.sphere4_2.visible = true;
                if (this.spheresStack[1] == "fire")
                {
                    this.container.sphere4_2.bullet.gotoAndStop(1);
                    this.container.sphere4_2.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[1] == "ice")
                {
                    this.container.sphere4_2.bullet.gotoAndStop(2);
                    this.container.sphere4_2.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[1] == "stone")
                {
                    this.container.sphere4_2.bullet.gotoAndStop(3);
                    this.container.sphere4_2.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[1] == "levin")
                {
                    this.container.sphere4_2.bullet.gotoAndStop(4);
                    this.container.sphere4_2.bullet.cont.gotoAndStop(1);
                }
                this.container.sphere4_3.gotoAndStop(28);
                this.container.sphere4_3.visible = true;
                if (this.spheresStack[2] == "fire")
                {
                    this.container.sphere4_3.bullet.gotoAndStop(1);
                    this.container.sphere4_3.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[2] == "ice")
                {
                    this.container.sphere4_3.bullet.gotoAndStop(2);
                    this.container.sphere4_3.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[2] == "stone")
                {
                    this.container.sphere4_3.bullet.gotoAndStop(3);
                    this.container.sphere4_3.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[2] == "levin")
                {
                    this.container.sphere4_3.bullet.gotoAndStop(4);
                    this.container.sphere4_3.bullet.cont.gotoAndStop(1);
                }
                this.container.sphere4_4.gotoAndStop(42);
                this.container.sphere4_4.visible = true;
                if (this.spheresStack[3] == "fire")
                {
                    this.container.sphere4_4.bullet.gotoAndStop(1);
                    this.container.sphere4_4.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[3] == "ice")
                {
                    this.container.sphere4_4.bullet.gotoAndStop(2);
                    this.container.sphere4_4.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[3] == "stone")
                {
                    this.container.sphere4_4.bullet.gotoAndStop(3);
                    this.container.sphere4_4.bullet.cont.gotoAndStop(1);
                }
                else if (this.spheresStack[3] == "levin")
                {
                    this.container.sphere4_4.bullet.gotoAndStop(4);
                    this.container.sphere4_4.bullet.cont.gotoAndStop(1);
                }
            }
            return;
        }// end function

        public function addBuildAnima() : void
        {
            if (!this.buildAnima)
            {
                this.buildAnima = new BuildTowerSmoke_mc();
                this.buildAnima.stop();
                this.buildAnima.y = 5;
                var _loc_1:* = false;
                this.buildAnima.mouseChildren = false;
                this.buildAnima.mouseEnabled = _loc_1;
                this.addChild(this.buildAnima);
            }
            else
            {
                this.buildAnima.gotoAndStop(1);
            }
            return;
        }// end function

        public function blockTowerFunk() : void
        {
            if (this.container.boneBlock.visible)
            {
                if (this.blockTowerFlag)
                {
                }
                else if (this.container.boneBlock.currentFrame < 11)
                {
                    this.container.boneBlock.gotoAndStop((this.container.boneBlock.currentFrame + 1));
                }
                else
                {
                    this.blockTowerFlag = true;
                }
            }
            else if (this.container.blockTower.visible)
            {
                if (this.blockTowerFlag)
                {
                    if (this.world.frameCounter == 10 || this.world.frameCounter == 20 || this.world.frameCounter == 30)
                    {
                        this.tempObject = null;
                        this.i = 0;
                        while (this.i < this.world.listOfUnits.length)
                        {
                            
                            if (this.world.listOfUnits[this.i].typeUnit == 22)
                            {
                                if (this.world.listOfUnits[this.i].readyDamage && this.world.listOfUnits[this.i].atStage && !this.world.listOfUnits[this.i].icemanFlag && !this.world.listOfUnits[this.i].airShockFlag)
                                {
                                    if (Point.distance(this.this_pt, this.world.listOfUnits[this.i].this_pt) < this.world.listOfUnits[this.i].blockTowerRadius)
                                    {
                                        this.tempObject = true;
                                        break;
                                    }
                                }
                            }
                            var _loc_1:* = this;
                            var _loc_2:* = this.i + 1;
                            _loc_1.i = _loc_2;
                        }
                        if (!this.tempObject)
                        {
                            this.blockTowerFlag = false;
                        }
                    }
                    if (this.container.blockTower.currentFrame < this.container.blockTower.totalFrames)
                    {
                        this.container.blockTower.gotoAndStop((this.container.blockTower.currentFrame + 1));
                    }
                    else
                    {
                        this.container.blockTower.gotoAndStop(21);
                    }
                }
                else if (this.container.blockTower.currentFrame > 20)
                {
                    if (this.container.blockTower.currentFrame < this.container.blockTower.totalFrames)
                    {
                        this.container.blockTower.gotoAndStop((this.container.blockTower.currentFrame + 1));
                    }
                    else
                    {
                        this.container.blockTower.gotoAndStop(20);
                    }
                }
                else if (this.container.blockTower.currentFrame > 1)
                {
                    this.container.blockTower.gotoAndStop((this.container.blockTower.currentFrame - 1));
                }
                else
                {
                    this.container.blockTower.visible = false;
                    var _loc_1:* = true;
                    this.mouseChildren = true;
                    this.mouseEnabled = _loc_1;
                }
            }
            return;
        }// end function

        public function scanBlock() : void
        {
            this.listOfTargets = [];
            this.scanAndPush();
            this.enemyTarget = null;
            if (this.world.nowLevel == 3)
            {
                this.i = 0;
                while (this.i < this.listOfTargets.length)
                {
                    
                    this.tempObject = this.listOfTargets[this.i];
                    this.tempObject.tempObject1 = false;
                    this.tempObject1 = 0;
                    if (this.tempObject.road == 1)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 855)
                            {
                                this.tempObject1 = 855;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 827)
                            {
                                this.tempObject1 = 827;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 844)
                            {
                                this.tempObject1 = 844;
                            }
                        }
                    }
                    else if (this.tempObject.road == 2)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 515)
                            {
                                this.tempObject1 = 515;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 474)
                            {
                                this.tempObject1 = 474;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 501)
                            {
                                this.tempObject1 = 501;
                            }
                        }
                    }
                    if (this.tempObject1 > 0)
                    {
                        this.tempObject.tempObject1 = true;
                        this.tempObject.tempObject = (this.tempObject.path - this.tempObject1) / (this.tempObject.finishPath - this.tempObject1);
                        if (this.enemyTarget)
                        {
                            if (this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                            else
                            {
                                this.enemyTarget = this.tempObject;
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    else
                    {
                        this.tempObject.tempObject = this.tempObject.path / this.tempObject.finishPath;
                        if (this.enemyTarget)
                        {
                            if (!this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            else if (this.world.nowLevel == 5)
            {
                this.i = 0;
                while (this.i < this.listOfTargets.length)
                {
                    
                    this.tempObject = this.listOfTargets[this.i];
                    this.tempObject.tempObject1 = false;
                    this.tempObject1 = 0;
                    if (this.tempObject.road == 1)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 1006)
                            {
                                this.tempObject1 = 1006;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 990)
                            {
                                this.tempObject1 = 990;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 1016)
                            {
                                this.tempObject1 = 1016;
                            }
                        }
                    }
                    else if (this.tempObject.road == 2)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 969)
                            {
                                this.tempObject1 = 969;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 882)
                            {
                                this.tempObject1 = 882;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 922)
                            {
                                this.tempObject1 = 922;
                            }
                        }
                    }
                    if (this.tempObject1 > 0)
                    {
                        this.tempObject.tempObject1 = true;
                        this.tempObject.tempObject = (this.tempObject.path - this.tempObject1) / (this.tempObject.finishPath - this.tempObject1);
                        if (this.enemyTarget)
                        {
                            if (this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                            else
                            {
                                this.enemyTarget = this.tempObject;
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    else
                    {
                        this.tempObject.tempObject = this.tempObject.path / this.tempObject.finishPath;
                        if (this.enemyTarget)
                        {
                            if (!this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            else if (this.world.nowLevel == 6)
            {
                this.i = 0;
                while (this.i < this.listOfTargets.length)
                {
                    
                    this.tempObject = this.listOfTargets[this.i];
                    this.tempObject.tempObject1 = false;
                    this.tempObject1 = 0;
                    if (this.tempObject.road == 1)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 696)
                            {
                                this.tempObject1 = 696;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 691)
                            {
                                this.tempObject1 = 691;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 689)
                            {
                                this.tempObject1 = 689;
                            }
                        }
                    }
                    else if (this.tempObject.road == 2)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 686)
                            {
                                this.tempObject1 = 686;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 770)
                            {
                                this.tempObject1 = 770;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 733)
                            {
                                this.tempObject1 = 733;
                            }
                        }
                    }
                    if (this.tempObject1 > 0)
                    {
                        this.tempObject.tempObject1 = true;
                        this.tempObject.tempObject = (this.tempObject.path - this.tempObject1) / (this.tempObject.finishPath - this.tempObject1);
                        if (this.enemyTarget)
                        {
                            if (this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                            else
                            {
                                this.enemyTarget = this.tempObject;
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    else
                    {
                        this.tempObject.tempObject = this.tempObject.path / this.tempObject.finishPath;
                        if (this.enemyTarget)
                        {
                            if (!this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            else if (this.world.nowLevel == 8)
            {
                this.i = 0;
                while (this.i < this.listOfTargets.length)
                {
                    
                    this.tempObject = this.listOfTargets[this.i];
                    this.tempObject.tempObject1 = false;
                    this.tempObject1 = 0;
                    if (this.tempObject.road == 1)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 393)
                            {
                                this.tempObject1 = 393;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 427)
                            {
                                this.tempObject1 = 427;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 414)
                            {
                                this.tempObject1 = 414;
                            }
                        }
                    }
                    else if (this.tempObject.road == 2)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 1053)
                            {
                                this.tempObject1 = 1053;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 1048)
                            {
                                this.tempObject1 = 1048;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 1056)
                            {
                                this.tempObject1 = 1056;
                            }
                        }
                    }
                    if (this.tempObject1 > 0)
                    {
                        this.tempObject.tempObject1 = true;
                        this.tempObject.tempObject = (this.tempObject.path - this.tempObject1) / (this.tempObject.finishPath - this.tempObject1);
                        if (this.enemyTarget)
                        {
                            if (this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                            else
                            {
                                this.enemyTarget = this.tempObject;
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    else
                    {
                        this.tempObject.tempObject = this.tempObject.path / this.tempObject.finishPath;
                        if (this.enemyTarget)
                        {
                            if (!this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            else if (this.world.nowLevel == 11)
            {
                this.i = 0;
                while (this.i < this.listOfTargets.length)
                {
                    
                    this.tempObject = this.listOfTargets[this.i];
                    this.tempObject.tempObject1 = false;
                    this.tempObject1 = 0;
                    if (this.tempObject.road == 1)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 849)
                            {
                                this.tempObject1 = 849;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 851)
                            {
                                this.tempObject1 = 851;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 847)
                            {
                                this.tempObject1 = 847;
                            }
                        }
                    }
                    else if (this.tempObject.road == 2)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 636)
                            {
                                this.tempObject1 = 636;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 696)
                            {
                                this.tempObject1 = 696;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 662)
                            {
                                this.tempObject1 = 662;
                            }
                        }
                    }
                    if (this.tempObject1 > 0)
                    {
                        this.tempObject.tempObject1 = true;
                        this.tempObject.tempObject = (this.tempObject.path - this.tempObject1) / (this.tempObject.finishPath - this.tempObject1);
                        if (this.enemyTarget)
                        {
                            if (this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                            else
                            {
                                this.enemyTarget = this.tempObject;
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    else
                    {
                        this.tempObject.tempObject = this.tempObject.path / this.tempObject.finishPath;
                        if (this.enemyTarget)
                        {
                            if (!this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            else if (this.world.nowLevel == 12)
            {
                this.i = 0;
                while (this.i < this.listOfTargets.length)
                {
                    
                    this.tempObject = this.listOfTargets[this.i];
                    this.tempObject.tempObject1 = false;
                    this.tempObject1 = 0;
                    if (this.tempObject.road == 1)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 756)
                            {
                                this.tempObject1 = 756;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 756)
                            {
                                this.tempObject1 = 756;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 741)
                            {
                                this.tempObject1 = 741;
                            }
                        }
                    }
                    else if (this.tempObject.road == 2)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 1855)
                            {
                                this.tempObject1 = 1855;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 1828)
                            {
                                this.tempObject1 = 1828;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 1817)
                            {
                                this.tempObject1 = 1817;
                            }
                        }
                    }
                    if (this.tempObject1 > 0)
                    {
                        this.tempObject.tempObject1 = true;
                        this.tempObject.tempObject = (this.tempObject.path - this.tempObject1) / (this.tempObject.finishPath - this.tempObject1);
                        if (this.enemyTarget)
                        {
                            if (this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                            else
                            {
                                this.enemyTarget = this.tempObject;
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    else
                    {
                        this.tempObject.tempObject = this.tempObject.path / this.tempObject.finishPath;
                        if (this.enemyTarget)
                        {
                            if (!this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            else if (this.world.nowLevel == 13)
            {
                this.i = 0;
                while (this.i < this.listOfTargets.length)
                {
                    
                    this.tempObject = this.listOfTargets[this.i];
                    this.tempObject.tempObject1 = false;
                    this.tempObject1 = 0;
                    if (this.tempObject.road == 1)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 1617)
                            {
                                this.tempObject1 = 1617;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 1582)
                            {
                                this.tempObject1 = 1582;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 1589)
                            {
                                this.tempObject1 = 1589;
                            }
                        }
                    }
                    else if (this.tempObject.road == 2)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 235)
                            {
                                this.tempObject1 = 235;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 193)
                            {
                                this.tempObject1 = 193;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 208)
                            {
                                this.tempObject1 = 208;
                            }
                        }
                    }
                    if (this.tempObject1 > 0)
                    {
                        this.tempObject.tempObject1 = true;
                        this.tempObject.tempObject = (this.tempObject.path - this.tempObject1) / (this.tempObject.finishPath - this.tempObject1);
                        if (this.enemyTarget)
                        {
                            if (this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                            else
                            {
                                this.enemyTarget = this.tempObject;
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    else
                    {
                        this.tempObject.tempObject = this.tempObject.path / this.tempObject.finishPath;
                        if (this.enemyTarget)
                        {
                            if (!this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            else if (this.world.nowLevel == 14)
            {
                this.i = 0;
                while (this.i < this.listOfTargets.length)
                {
                    
                    this.tempObject = this.listOfTargets[this.i];
                    this.tempObject.tempObject1 = false;
                    this.tempObject1 = 0;
                    if (this.tempObject.road == 1)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 1413)
                            {
                                this.tempObject1 = 1413;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 1340)
                            {
                                this.tempObject1 = 1340;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 1365)
                            {
                                this.tempObject1 = 1365;
                            }
                        }
                    }
                    else if (this.tempObject.road == 2)
                    {
                        if (this.tempObject.way == 1)
                        {
                            if (this.tempObject.path > 380)
                            {
                                this.tempObject1 = 380;
                            }
                        }
                        else if (this.tempObject.way == 2)
                        {
                            if (this.tempObject.path > 397)
                            {
                                this.tempObject1 = 397;
                            }
                        }
                        else if (this.tempObject.way == 3)
                        {
                            if (this.tempObject.path > 380)
                            {
                                this.tempObject1 = 380;
                            }
                        }
                    }
                    if (this.tempObject1 > 0)
                    {
                        this.tempObject.tempObject1 = true;
                        this.tempObject.tempObject = (this.tempObject.path - this.tempObject1) / (this.tempObject.finishPath - this.tempObject1);
                        if (this.enemyTarget)
                        {
                            if (this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                            else
                            {
                                this.enemyTarget = this.tempObject;
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    else
                    {
                        this.tempObject.tempObject = this.tempObject.path / this.tempObject.finishPath;
                        if (this.enemyTarget)
                        {
                            if (!this.enemyTarget.tempObject1)
                            {
                                if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                                {
                                    this.enemyTarget = this.tempObject;
                                }
                            }
                        }
                        else
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            else
            {
                this.i = 0;
                while (this.i < this.listOfTargets.length)
                {
                    
                    this.tempObject = this.listOfTargets[this.i];
                    this.tempObject.tempObject = this.tempObject.path / this.tempObject.finishPath;
                    if (this.enemyTarget)
                    {
                        if (this.tempObject.tempObject > this.enemyTarget.tempObject)
                        {
                            this.enemyTarget = this.tempObject;
                        }
                    }
                    else
                    {
                        this.enemyTarget = this.tempObject;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            this.tempObject = null;
            this.i = 0;
            while (this.i < this.listOfTargets.length)
            {
                
                if (this.listOfTargets[this.i].road == this.enemyTarget.road && this.listOfTargets[this.i].direction == this.enemyTarget.direction)
                {
                    if (this.listOfTargets[this.i] != this.enemyTarget)
                    {
                        if (this.enemyTarget.direction == "left")
                        {
                            if (!this.tempObject)
                            {
                                if (this.enemyTarget.x > this.listOfTargets[this.i].x)
                                {
                                    this.tempObject = this.listOfTargets[this.i];
                                }
                            }
                            else if (this.tempObject.x > this.listOfTargets[this.i].x)
                            {
                                this.tempObject = this.listOfTargets[this.i];
                            }
                        }
                        else if (this.enemyTarget.direction == "right")
                        {
                            if (!this.tempObject)
                            {
                                if (this.enemyTarget.x < this.listOfTargets[this.i].x)
                                {
                                    this.tempObject = this.listOfTargets[this.i];
                                }
                            }
                            else if (this.tempObject.x < this.listOfTargets[this.i].x)
                            {
                                this.tempObject = this.listOfTargets[this.i];
                            }
                        }
                        else if (this.enemyTarget.direction == "up")
                        {
                            if (!this.tempObject)
                            {
                                if (this.enemyTarget.y > this.listOfTargets[this.i].y)
                                {
                                    this.tempObject = this.listOfTargets[this.i];
                                }
                            }
                            else if (this.tempObject.y > this.listOfTargets[this.i].y)
                            {
                                this.tempObject = this.listOfTargets[this.i];
                            }
                        }
                        else if (this.enemyTarget.direction == "down")
                        {
                            if (!this.tempObject)
                            {
                                if (this.enemyTarget.y < this.listOfTargets[this.i].y)
                                {
                                    this.tempObject = this.listOfTargets[this.i];
                                }
                            }
                            else if (this.tempObject.y < this.listOfTargets[this.i].y)
                            {
                                this.tempObject = this.listOfTargets[this.i];
                            }
                        }
                    }
                }
                var _loc_1:* = this;
                var _loc_2:* = this.i + 1;
                _loc_1.i = _loc_2;
            }
            if (this.tempObject)
            {
                this.enemyTarget = this.tempObject;
            }
            return;
        }// end function

        public function scanAndPush() : void
        {
            this.i = 0;
            while (this.i < this.world.listOfUnits.length)
            {
                
                if (this.world.listOfUnits[this.i].atStage && this.world.listOfUnits[this.i].readyDamage && !this.world.listOfUnits[this.i].airFlag)
                {
                    this.testTarget = this.world.listOfUnits[this.i].shoot_pt;
                    this.scanAtRadius();
                    if (this.greenFlag)
                    {
                        this.listOfTargets.push(this.world.listOfUnits[this.i]);
                    }
                }
                var _loc_1:* = this;
                var _loc_2:* = this.i + 1;
                _loc_1.i = _loc_2;
            }
            return;
        }// end function

        public function towerGetSphereManage(param1:String, param2:String) : void
        {
            if (param1 == "get")
            {
                if (param2 == "fire")
                {
                    if (this.shootingTurnStack[0])
                    {
                        if (!this.world.getSphere)
                        {
                            this.spheresManage("get", "fire", 1);
                            this.world.getSphere = new GetSphere();
                            this.world.getSphere.ownerType = "archive";
                            this.world.getSphere.owner = this.world.worldInterface.container.fireSphere;
                            this.world.getSphere.ownerPoint = this.world.worldInterface.container.fireSphere.myPoint;
                            this.world.addChild(this.world.getSphere);
                            this.world.getSphere.manage("add", "fire");
                        }
                        else if (this.world.getSphere.listOfStack.length < 4)
                        {
                            this.spheresManage("get", "fire", 1);
                            this.world.getSphere.manage("add", "fire");
                        }
                    }
                }
                else if (param2 == "ice")
                {
                    if (this.shootingTurnStack[1])
                    {
                        if (!this.world.getSphere)
                        {
                            this.spheresManage("get", "ice", 1);
                            this.world.getSphere = new GetSphere();
                            this.world.getSphere.ownerType = "archive";
                            this.world.getSphere.owner = this.world.worldInterface.container.iceSphere;
                            this.world.getSphere.ownerPoint = this.world.worldInterface.container.iceSphere.myPoint;
                            this.world.addChild(this.world.getSphere);
                            this.world.getSphere.manage("add", "ice");
                        }
                        else if (this.world.getSphere.listOfStack.length < 4)
                        {
                            this.spheresManage("get", "ice", 1);
                            this.world.getSphere.manage("add", "ice");
                        }
                    }
                }
                else if (param2 == "stone")
                {
                    if (this.shootingTurnStack[2])
                    {
                        if (!this.world.getSphere)
                        {
                            this.spheresManage("get", "stone", 1);
                            this.world.getSphere = new GetSphere();
                            this.world.getSphere.ownerType = "archive";
                            this.world.getSphere.owner = this.world.worldInterface.container.stoneSphere;
                            this.world.getSphere.ownerPoint = this.world.worldInterface.container.stoneSphere.myPoint;
                            this.world.addChild(this.world.getSphere);
                            this.world.getSphere.manage("add", "stone");
                        }
                        else if (this.world.getSphere.listOfStack.length < 4)
                        {
                            this.spheresManage("get", "stone", 1);
                            this.world.getSphere.manage("add", "stone");
                        }
                    }
                }
                else if (param2 == "levin")
                {
                    if (this.shootingTurnStack[3])
                    {
                        if (!this.world.getSphere)
                        {
                            this.spheresManage("get", "levin", 1);
                            this.world.getSphere = new GetSphere();
                            this.world.getSphere.ownerType = "archive";
                            this.world.getSphere.owner = this.world.worldInterface.container.levinSphere;
                            this.world.getSphere.ownerPoint = this.world.worldInterface.container.levinSphere.myPoint;
                            this.world.addChild(this.world.getSphere);
                            this.world.getSphere.manage("add", "levin");
                        }
                        else if (this.world.getSphere.listOfStack.length < 4)
                        {
                            this.spheresManage("get", "levin", 1);
                            this.world.getSphere.manage("add", "levin");
                        }
                    }
                }
                else if (param2 == "getAll")
                {
                    if (this.spheresStack.length > 0)
                    {
                        if (!this.world.getSphere)
                        {
                            this.world.getSphere = new GetSphere();
                            this.world.getSphere.ownerType = "archive";
                            this.world.getSphere.owner = this.world.worldInterface.container.getAll;
                            this.world.getSphere.ownerPoint = this.world.worldInterface.container.getAll.myPoint;
                            this.world.addChild(this.world.getSphere);
                            while (this.spheresStack.length > 0)
                            {
                                
                                if (this.spheresStack[0] == "fire")
                                {
                                    this.spheresManage("get", "fire", 1);
                                    this.world.getSphere.manage("add", "fire");
                                    continue;
                                }
                                if (this.spheresStack[0] == "ice")
                                {
                                    this.spheresManage("get", "ice", 1);
                                    this.world.getSphere.manage("add", "ice");
                                    continue;
                                }
                                if (this.spheresStack[0] == "stone")
                                {
                                    this.spheresManage("get", "stone", 1);
                                    this.world.getSphere.manage("add", "stone");
                                    continue;
                                }
                                if (this.spheresStack[0] == "levin")
                                {
                                    this.spheresManage("get", "levin", 1);
                                    this.world.getSphere.manage("add", "levin");
                                }
                            }
                        }
                    }
                }
                this.world.worldInterface.updateInfo();
            }
            return;
        }// end function

        public function kill() : void
        {
            if (!this.dead)
            {
                this.dead = true;
                this.i = 0;
                while (this.i < this.world.listOfTowers.length)
                {
                    
                    if (this.world.listOfTowers[this.i] == this)
                    {
                        this.world.removeChild(this);
                        this.world.listOfTowers.splice(this.i, 1);
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
