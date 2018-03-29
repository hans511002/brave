#include "engine/World.h"
#include "Tower.h"

namespace engine{
    namespace towers{
 
         bool Tower::init( ) 
        {
            ////this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
            //this->world = Main::mainClass->worldClass;
            //this->setPosition(this->myPlace->getPostition());
            ////this->x = this->myPlace.x;
            ////this->y = this->myPlace.y;
            ////this->myPlace.placeForBuildCase.buttonMode = false;
            //this->this_pt = new Point(this->x + this->container.x + this->container.towerCase.x, this->y + this->container.y + this->container.towerCase.y);
            //this->shoot_pt = new Point(this->x, this->y + this->correctYGrPos);
            //this->addBuildAnima();
            //if (this->towerType < 5)
            //{
            //    this->prepareSpheresGraphic();
            //}
            //if (Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[(this->towerType - 1)] == 0)
            //{
            //    Main.mainClass.saveBoxClass.gameSave.data.firstViewTowers[(this->towerType - 1)] = 1;
            //}
            //if (!this->autoBuild)
            //{
            //    if (this->towerType < 5)
            //    {
            //        (this->world.saveBox.gameSave.data.addit_buildTowerCounter + 1);
            //        if (this->world.saveBox.gameSave.data.addit_buildTowerCounter == 100)
            //        {
            //            this->world.achieveManage("build_100_towers");
            //        }
            //    }
            //    else
            //    {
            //        (this->world.saveBox.gameSave.data.addit_buildUltraTowersCounter + 1);
            //        if (this->world.saveBox.gameSave.data.addit_buildUltraTowersCounter == 1)
            //        {
            //            this->world.achieveManage("buildUltraTower");
            //        }
            //        else if (this->world.saveBox.gameSave.data.addit_buildUltraTowersCounter == 50)
            //        {
            //            this->world.achieveManage("buildUltraTower_50_times");
            //        }
            //        this->tempObject1 = 0;
            //        this->tempObject2 = 0;
            //        this->tempObject3 = 0;
            //        this->tempObject4 = 0;
            //        this->i = 0;
            //        while (this->i < this->world.listOfTowers.length)
            //        {
            //            
            //            if (this->world.listOfTowers[this->i].towerType == 5)
            //            {
            //                (this->tempObject1 + 1);
            //            }
            //            else if (this->world.listOfTowers[this->i].towerType == 6)
            //            {
            //                (this->tempObject2 + 1);
            //            }
            //            else if (this->world.listOfTowers[this->i].towerType == 7)
            //            {
            //                (this->tempObject3 + 1);
            //            }
            //            else if (this->world.listOfTowers[this->i].towerType == 8)
            //            {
            //                (this->tempObject4 + 1);
            //            }
            //            var _loc_2:* = this;
            //            var _loc_3:* = this->i + 1;
            //            _loc_2.i = _loc_3;
            //        }
            //        if (this->tempObject1 > 0 && this->tempObject2 > 0 && this->tempObject3 > 0 && this->tempObject4 > 0)
            //        {
            //            this->world.achieveManage("buildAllUltraTowers");
            //        }
            //    }
            //}
            return true;
        }// end function
        void Tower::update() 
        {
            //if (!this->buildAnima)
            //{
            //    if (this->towerType < 5)
            //    {
            //        if (this->sphereBullet1)
            //        {
            //            if (this->sphereBullet1.counter > 0)
            //            {
            //                (this->sphereBullet1.counter - 1);
            //            }
            //            else
            //            {
            //                this->sphereBullet1.visible = true;
            //                this->sphereBullet1 = null;
            //            }
            //        }
            //        if (this->sphereBullet2)
            //        {
            //            if (this->sphereBullet2.counter > 0)
            //            {
            //                (this->sphereBullet2.counter - 1);
            //            }
            //            else
            //            {
            //                this->sphereBullet2.visible = true;
            //                this->sphereBullet2 = null;
            //            }
            //        }
            //        if (this->sphereBullet3)
            //        {
            //            if (this->sphereBullet3.counter > 0)
            //            {
            //                (this->sphereBullet3.counter - 1);
            //            }
            //            else
            //            {
            //                this->sphereBullet3.visible = true;
            //                this->sphereBullet3 = null;
            //            }
            //        }
            //        if (this->sphereBullet4)
            //        {
            //            if (this->sphereBullet4.counter > 0)
            //            {
            //                (this->sphereBullet4.counter - 1);
            //            }
            //            else
            //            {
            //                this->sphereBullet4.visible = true;
            //                this->sphereBullet4 = null;
            //            }
            //        }
            //    }
            //    if (!this->enemyTarget)
            //    {
            //        this->scan();
            //    }
            //    else
            //    {
            //        this->attack();
            //    }
            //}
            //else if (this->buildAnima.currentFrame < this->buildAnima.totalFrames)
            //{
            //    this->buildAnima.gotoAndStop((this->buildAnima.currentFrame + 1));
            //}
            //else
            //{
            //    this->removeChild(this->buildAnima);
            //    this->buildAnima = null;
            //}
            return;
        }// end function
				void Tower::scan()  
        {
        //    if (!this->container.blockTower.visible && !this->container.boneBlock.visible)
        //    {
        //        if (this->shootingTurnStack[0] || this->shootingTurnStack[1] || this->shootingTurnStack[2] || this->shootingTurnStack[3])
        //        {
        //            this->greenFlag = false;
        //            this->i = 0;
        //            while (this->i < this->shootingTurnStack.length)
        //            {
        //                
        //                if (this->shootingTurnStack[this->i])
        //                {
        //                    if (this->shootingTurnStack[this->i][1] < this->shootingTurnStack[this->i][2])
        //                    {
        //                        (this->shootingTurnStack[this->i][1] + 1);
        //                    }
        //                    else
        //                    {
        //                        this->greenFlag = true;
        //                        this->shootingSphere = this->shootingTurnStack[this->i][0];
        //                        break;
        //                    }
        //                }
        //                var _loc_1:* = this;
        //                var _loc_2:* = this->i + 1;
        //                _loc_1.i = _loc_2;
        //            }
        //            if (this->greenFlag && this->world.frameCounter % 2)
        //            {
        //                this->scanBlock();
        //                if (this->enemyTarget)
        //                {
        //                    this->i = 0;
        //                    while (this->i < this->shootingTurnStack.length)
        //                    {
        //                        
        //                        if (this->shootingTurnStack[this->i])
        //                        {
        //                            if (this->shootingTurnStack[this->i][1] >= this->shootingTurnStack[this->i][2])
        //                            {
        //                                this->shootingTurnStack[this->i][1] = 0;
        //                                break;
        //                            }
        //                        }
        //                        var _loc_1:* = this;
        //                        var _loc_2:* = this->i + 1;
        //                        _loc_1.i = _loc_2;
        //                    }
        //                    if (this->spheresStack.length > 1)
        //                    {
        //                        if (this->spheresStack.length == 2)
        //                        {
        //                            this->i = 0;
        //                            while (this->i < this->spheresStack.length)
        //                            {
        //                                
        //                                if (this->spheresStack[this->i] == this->shootingSphere)
        //                                {
        //                                    if (this->i == 0)
        //                                    {
        //                                        this->tempObject = this->container.sphere2_1.localToGlobal(new Point(this->container.sphere2_1.bullet.x, this->container.sphere2_1.bullet.y));
        //                                        if (this->sphereBullet1)
        //                                        {
        //                                            this->sphereBullet1.visible = true;
        //                                        }
        //                                        var _loc_1:* = this->container.sphere2_1.bullet;
        //                                        this->sphereBullet1 = this->container.sphere2_1.bullet;
        //                                        this->tempObject2 = _loc_1;
        //                                        if (this->shootingSphere == "fire")
        //                                        {
        //                                            this->tempObject1 = new BulletFireTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "ice")
        //                                        {
        //                                            this->tempObject1 = new BulletIceTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "stone")
        //                                        {
        //                                            this->tempObject1 = new BulletStoneTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "levin")
        //                                        {
        //                                            this->tempObject1 = new BulletLevinTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                    }
        //                                    else if (this->i == 1)
        //                                    {
        //                                        this->tempObject = this->container.sphere2_2.localToGlobal(new Point(this->container.sphere2_2.bullet.x, this->container.sphere2_2.bullet.y));
        //                                        if (this->sphereBullet2)
        //                                        {
        //                                            this->sphereBullet2.visible = true;
        //                                        }
        //                                        var _loc_1:* = this->container.sphere2_2.bullet;
        //                                        this->sphereBullet2 = this->container.sphere2_2.bullet;
        //                                        this->tempObject2 = _loc_1;
        //                                        if (this->shootingSphere == "fire")
        //                                        {
        //                                            this->tempObject1 = new BulletFireTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "ice")
        //                                        {
        //                                            this->tempObject1 = new BulletIceTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "stone")
        //                                        {
        //                                            this->tempObject1 = new BulletStoneTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "levin")
        //                                        {
        //                                            this->tempObject1 = new BulletLevinTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                    }
        //                                    this->tempObject2.counter = this->sphereVisibleTimer;
        //                                    this->tempObject2.visible = false;
        //                                    this->tempObject = this->container.globalToLocal(this->tempObject);
        //                                    this->tempObject1.x = this->tempObject.x;
        //                                    this->tempObject1.y = this->tempObject.y;
        //                                    this->tempObject1.counter = 3;
        //                                    this->tempObject1.distX = -this->tempObject.x / this->tempObject1.counter;
        //                                    this->tempObject1.distY = (-70 - this->tempObject.y) / this->tempObject1.counter;
        //                                    this->container.addChild(this->tempObject1);
        //                                    this->shootinAttackStack.push(this->tempObject1);
        //                                }
        //                                var _loc_1:* = this;
        //                                var _loc_2:* = this->i + 1;
        //                                _loc_1.i = _loc_2;
        //                            }
        //                        }
        //                        else if (this->spheresStack.length == 3)
        //                        {
        //                            this->i = 0;
        //                            while (this->i < this->spheresStack.length)
        //                            {
        //                                
        //                                if (this->spheresStack[this->i] == this->shootingSphere)
        //                                {
        //                                    if (this->i == 0)
        //                                    {
        //                                        this->tempObject = this->container.sphere3_1.localToGlobal(new Point(this->container.sphere3_1.bullet.x, this->container.sphere3_1.bullet.y));
        //                                        if (this->sphereBullet1)
        //                                        {
        //                                            this->sphereBullet1.visible = true;
        //                                        }
        //                                        var _loc_1:* = this->container.sphere3_1.bullet;
        //                                        this->sphereBullet1 = this->container.sphere3_1.bullet;
        //                                        this->tempObject2 = _loc_1;
        //                                        if (this->shootingSphere == "fire")
        //                                        {
        //                                            this->tempObject1 = new BulletFireTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "ice")
        //                                        {
        //                                            this->tempObject1 = new BulletIceTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "stone")
        //                                        {
        //                                            this->tempObject1 = new BulletStoneTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "levin")
        //                                        {
        //                                            this->tempObject1 = new BulletLevinTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                    }
        //                                    else if (this->i == 1)
        //                                    {
        //                                        this->tempObject = this->container.sphere3_2.localToGlobal(new Point(this->container.sphere3_2.bullet.x, this->container.sphere3_2.bullet.y));
        //                                        if (this->sphereBullet2)
        //                                        {
        //                                            this->sphereBullet2.visible = true;
        //                                        }
        //                                        var _loc_1:* = this->container.sphere3_2.bullet;
        //                                        this->sphereBullet2 = this->container.sphere3_2.bullet;
        //                                        this->tempObject2 = _loc_1;
        //                                        if (this->shootingSphere == "fire")
        //                                        {
        //                                            this->tempObject1 = new BulletFireTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "ice")
        //                                        {
        //                                            this->tempObject1 = new BulletIceTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "stone")
        //                                        {
        //                                            this->tempObject1 = new BulletStoneTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "levin")
        //                                        {
        //                                            this->tempObject1 = new BulletLevinTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                    }
        //                                    else if (this->i == 2)
        //                                    {
        //                                        this->tempObject = this->container.sphere3_3.localToGlobal(new Point(this->container.sphere3_3.bullet.x, this->container.sphere3_3.bullet.y));
        //                                        if (this->sphereBullet3)
        //                                        {
        //                                            this->sphereBullet3.visible = true;
        //                                        }
        //                                        var _loc_1:* = this->container.sphere3_3.bullet;
        //                                        this->sphereBullet3 = this->container.sphere3_3.bullet;
        //                                        this->tempObject2 = _loc_1;
        //                                        if (this->shootingSphere == "fire")
        //                                        {
        //                                            this->tempObject1 = new BulletFireTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "ice")
        //                                        {
        //                                            this->tempObject1 = new BulletIceTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "stone")
        //                                        {
        //                                            this->tempObject1 = new BulletStoneTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "levin")
        //                                        {
        //                                            this->tempObject1 = new BulletLevinTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                    }
        //                                    this->tempObject2.counter = this->sphereVisibleTimer;
        //                                    this->tempObject2.visible = false;
        //                                    this->tempObject = this->container.globalToLocal(this->tempObject);
        //                                    this->tempObject1.x = this->tempObject.x;
        //                                    this->tempObject1.y = this->tempObject.y;
        //                                    this->tempObject1.counter = 3;
        //                                    this->tempObject1.distX = -this->tempObject.x / this->tempObject1.counter;
        //                                    this->tempObject1.distY = (-70 - this->tempObject.y) / this->tempObject1.counter;
        //                                    this->container.addChild(this->tempObject1);
        //                                    this->shootinAttackStack.push(this->tempObject1);
        //                                }
        //                                var _loc_1:* = this;
        //                                var _loc_2:* = this->i + 1;
        //                                _loc_1.i = _loc_2;
        //                            }
        //                        }
        //                        else if (this->spheresStack.length == 4)
        //                        {
        //                            this->i = 0;
        //                            while (this->i < this->spheresStack.length)
        //                            {
        //                                
        //                                if (this->spheresStack[this->i] == this->shootingSphere)
        //                                {
        //                                    if (this->i == 0)
        //                                    {
        //                                        this->tempObject = this->container.sphere4_1.localToGlobal(new Point(this->container.sphere4_1.bullet.x, this->container.sphere4_1.bullet.y));
        //                                        if (this->sphereBullet1)
        //                                        {
        //                                            this->sphereBullet1.visible = true;
        //                                        }
        //                                        var _loc_1:* = this->container.sphere4_1.bullet;
        //                                        this->sphereBullet1 = this->container.sphere4_1.bullet;
        //                                        this->tempObject2 = _loc_1;
        //                                        if (this->shootingSphere == "fire")
        //                                        {
        //                                            this->tempObject1 = new BulletFireTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "ice")
        //                                        {
        //                                            this->tempObject1 = new BulletIceTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "stone")
        //                                        {
        //                                            this->tempObject1 = new BulletStoneTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "levin")
        //                                        {
        //                                            this->tempObject1 = new BulletLevinTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                    }
        //                                    else if (this->i == 1)
        //                                    {
        //                                        this->tempObject = this->container.sphere4_2.localToGlobal(new Point(this->container.sphere4_2.bullet.x, this->container.sphere4_2.bullet.y));
        //                                        if (this->sphereBullet2)
        //                                        {
        //                                            this->sphereBullet2.visible = true;
        //                                        }
        //                                        var _loc_1:* = this->container.sphere4_2.bullet;
        //                                        this->sphereBullet2 = this->container.sphere4_2.bullet;
        //                                        this->tempObject2 = _loc_1;
        //                                        if (this->shootingSphere == "fire")
        //                                        {
        //                                            this->tempObject1 = new BulletFireTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "ice")
        //                                        {
        //                                            this->tempObject1 = new BulletIceTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "stone")
        //                                        {
        //                                            this->tempObject1 = new BulletStoneTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "levin")
        //                                        {
        //                                            this->tempObject1 = new BulletLevinTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                    }
        //                                    else if (this->i == 2)
        //                                    {
        //                                        this->tempObject = this->container.sphere4_3.localToGlobal(new Point(this->container.sphere4_3.bullet.x, this->container.sphere4_3.bullet.y));
        //                                        if (this->sphereBullet3)
        //                                        {
        //                                            this->sphereBullet3.visible = true;
        //                                        }
        //                                        var _loc_1:* = this->container.sphere4_3.bullet;
        //                                        this->sphereBullet3 = this->container.sphere4_3.bullet;
        //                                        this->tempObject2 = _loc_1;
        //                                        if (this->shootingSphere == "fire")
        //                                        {
        //                                            this->tempObject1 = new BulletFireTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "ice")
        //                                        {
        //                                            this->tempObject1 = new BulletIceTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "stone")
        //                                        {
        //                                            this->tempObject1 = new BulletStoneTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "levin")
        //                                        {
        //                                            this->tempObject1 = new BulletLevinTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                    }
        //                                    else if (this->i == 3)
        //                                    {
        //                                        this->tempObject = this->container.sphere4_4.localToGlobal(new Point(this->container.sphere4_4.bullet.x, this->container.sphere4_4.bullet.y));
        //                                        if (this->sphereBullet4)
        //                                        {
        //                                            this->sphereBullet4.visible = true;
        //                                        }
        //                                        var _loc_1:* = this->container.sphere4_4.bullet;
        //                                        this->sphereBullet4 = this->container.sphere4_4.bullet;
        //                                        this->tempObject2 = _loc_1;
        //                                        if (this->shootingSphere == "fire")
        //                                        {
        //                                            this->tempObject1 = new BulletFireTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "ice")
        //                                        {
        //                                            this->tempObject1 = new BulletIceTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "stone")
        //                                        {
        //                                            this->tempObject1 = new BulletStoneTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                        else if (this->shootingSphere == "levin")
        //                                        {
        //                                            this->tempObject1 = new BulletLevinTower_mc();
        //                                            this->tempObject1.gotoAndStop(_loc_1.cont.currentFrame);
        //                                        }
        //                                    }
        //                                    this->tempObject2.counter = this->sphereVisibleTimer;
        //                                    this->tempObject2.visible = false;
        //                                    this->tempObject = this->container.globalToLocal(this->tempObject);
        //                                    this->tempObject1.x = this->tempObject.x;
        //                                    this->tempObject1.y = this->tempObject.y;
        //                                    this->tempObject1.counter = 3;
        //                                    this->tempObject1.distX = -this->tempObject.x / this->tempObject1.counter;
        //                                    this->tempObject1.distY = (-70 - this->tempObject.y) / this->tempObject1.counter;
        //                                    this->container.addChild(this->tempObject1);
        //                                    this->shootinAttackStack.push(this->tempObject1);
        //                                }
        //                                var _loc_1:* = this;
        //                                var _loc_2:* = this->i + 1;
        //                                _loc_1.i = _loc_2;
        //                            }
        //                        }
        //                    }
        //                }
        //            }
        //        }
        //    }
        //    else
        //    {
        //        this->blockTowerFunk();
        //    }
        //    return;
        }// end function
void Tower::attack() 
        {
            //if (this->shootinAttackStack.length == 0)
            //{
            //    this->tempObject = this->container.sphere1.localToGlobal(new Point(this->container.sphere1.bullet.x, this->container.sphere1.bullet.y));
            //    if (this->shootingSphere == "fire")
            //    {
            //        this->tempObject = this->world.addBullet(1, this->tempObject, this, this->enemyTarget, Main.mainClass.readXMLClass.listOfFireTowerDamageXML[0], 1);
            //        if (this->container.sphere1.bullet.cont)
            //        {
            //            this->tempObject.container.gotoAndStop(this->container.sphere1.bullet.cont.currentFrame);
            //        }
            //    }
            //    else if (this->shootingSphere == "ice")
            //    {
            //        this->tempObject = this->world.addBullet(2, this->tempObject, this, this->enemyTarget, Main.mainClass.readXMLClass.listOfIceTowerDamageXML[0], 1);
            //        if (this->container.sphere1.bullet.cont)
            //        {
            //            this->tempObject.container.gotoAndStop(this->container.sphere1.bullet.cont.currentFrame);
            //        }
            //    }
            //    else if (this->shootingSphere == "stone")
            //    {
            //        this->tempObject = this->world.addBullet(3, this->tempObject, this, this->enemyTarget, Main.mainClass.readXMLClass.listOfStoneTowerDamageXML[0], 1);
            //        if (this->container.sphere1.bullet.cont)
            //        {
            //            this->tempObject.container.gotoAndStop(this->container.sphere1.bullet.cont.currentFrame);
            //        }
            //    }
            //    else if (this->shootingSphere == "levin")
            //    {
            //        this->tempObject = this->world.addBullet(4, this->tempObject, this, this->enemyTarget, Main.mainClass.readXMLClass.listOfLevinTowerDamageXML[0], 1);
            //        if (this->container.sphere1.bullet.cont)
            //        {
            //            this->tempObject.container.gotoAndStop(this->container.sphere1.bullet.cont.currentFrame);
            //        }
            //    }
            //    if (this->sphereBullet1)
            //    {
            //        this->sphereBullet1.visible = true;
            //    }
            //    var _loc_1:* = this->container.sphere1.bullet;
            //    this->sphereBullet1 = this->container.sphere1.bullet;
            //    this->tempObject2 = _loc_1;
            //    this->tempObject2.counter = this->sphereVisibleTimer;
            //    this->tempObject2.visible = false;
            //    this->shootingSphere = null;
            //    this->enemyTarget = null;
            //}
            //else
            //{
            //    this->i = 0;
            //    while (this->i < this->shootinAttackStack.length)
            //    {
            //        
            //        if (this->shootinAttackStack[this->i].currentFrame < this->shootinAttackStack[this->i].totalFrames)
            //        {
            //            this->shootinAttackStack[this->i].gotoAndStop((this->shootinAttackStack[this->i].currentFrame + 1));
            //        }
            //        else
            //        {
            //            this->shootinAttackStack[this->i].gotoAndStop(1);
            //        }
            //        if (this->shootinAttackStack[this->i].counter > 0)
            //        {
            //            (this->shootinAttackStack[this->i].counter - 1);
            //            this->shootinAttackStack[this->i].x = this->shootinAttackStack[this->i].x + this->shootinAttackStack[this->i].distX;
            //            this->shootinAttackStack[this->i].y = this->shootinAttackStack[this->i].y + this->shootinAttackStack[this->i].distY;
            //        }
            //        else
            //        {
            //            this->tempObject = this->container.localToGlobal(new Point(this->shootinAttackStack[0].x, this->shootinAttackStack[0].y));
            //            if (this->shootingSphere == "fire")
            //            {
            //                if (this->shootingTurnStack[0])
            //                {
            //                    this->tempObject = this->world.addBullet(1, this->tempObject, this, this->enemyTarget, Main.mainClass.readXMLClass.listOfFireTowerDamageXML[(this->shootingTurnStack[0][3] - 1)], this->shootingTurnStack[0][3]);
            //                }
            //                else
            //                {
            //                    this->tempObject = null;
            //                }
            //            }
            //            else if (this->shootingSphere == "ice")
            //            {
            //                if (this->shootingTurnStack[1])
            //                {
            //                    this->tempObject = this->world.addBullet(2, this->tempObject, this, this->enemyTarget, Main.mainClass.readXMLClass.listOfIceTowerDamageXML[(this->shootingTurnStack[1][3] - 1)], this->shootingTurnStack[1][3]);
            //                }
            //                else
            //                {
            //                    this->tempObject = null;
            //                }
            //            }
            //            else if (this->shootingSphere == "stone")
            //            {
            //                if (this->shootingTurnStack[2])
            //                {
            //                    this->tempObject = this->world.addBullet(3, this->tempObject, this, this->enemyTarget, Main.mainClass.readXMLClass.listOfStoneTowerDamageXML[(this->shootingTurnStack[2][3] - 1)], this->shootingTurnStack[2][3]);
            //                }
            //                else
            //                {
            //                    this->tempObject = null;
            //                }
            //            }
            //            else if (this->shootingSphere == "levin")
            //            {
            //                if (this->shootingTurnStack[3])
            //                {
            //                    this->tempObject = this->world.addBullet(4, this->tempObject, this, this->enemyTarget, Main.mainClass.readXMLClass.listOfLevinTowerDamageXML[(this->shootingTurnStack[3][3] - 1)], this->shootingTurnStack[3][3]);
            //                }
            //                else
            //                {
            //                    this->tempObject = null;
            //                }
            //            }
            //            if (this->tempObject)
            //            {
            //                this->tempObject.container.gotoAndStop(this->shootinAttackStack[0].currentFrame);
            //            }
            //            this->shootingSphere = null;
            //            this->enemyTarget = null;
            //            this->j = this->shootinAttackStack.length - 1;
            //            while (this->j >= 0)
            //            {
            //                
            //                this->container.removeChild(this->shootinAttackStack[this->j]);
            //                this->shootinAttackStack.splice(this->j, 1);
            //                var _loc_1:* = this;
            //                var _loc_2:* = this->j - 1;
            //                _loc_1.j = _loc_2;
            //            }
            //            break;
            //        }
            //        var _loc_1:* = this;
            //        var _loc_2:* = this->i + 1;
            //        _loc_1.i = _loc_2;
            //    }
            //}
            return;
        }// end function
void Tower::scanAtRadius() 
        {
            //this->greenFlag = false;
            //this->tempObject = this->radius - this->radius * (1 - this->world.scaleRadius);
            //if ((this->testTarget.x - this->this_pt.x) * (this->testTarget.x - this->this_pt.x) / (this->radius * this->radius) + (this->testTarget.y - this->this_pt.y) * (this->testTarget.y - this->this_pt.y) / (this->tempObject * this->tempObject) <= 1)
            //{
            //    this->greenFlag = true;
            //}
            return;
        }// end functio
   	}
}